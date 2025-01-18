/*
 * cloud_network_path_rtt.c
 *
 * cloud network kernel module implementation
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "cloud_network_path_rtt.h"

#include <securec.h>

#include "cloud_network_option.h"
#include "cloud_network_device.h"
#include "cloud_network_honhdr.h"
#include "cloud_network_utils.h"
#include "cloud_network_utils.h"
#include "cloud_network_rx.h"
#include "cloud_network_tx.h"
#include "cloud_network.h"
#include "cloud_network_param.h"
#include "cloud_network_detect.h"

#define PATH_LIST_SIZE 128
#define STANDARD_CALCULATE_SIZE 16
#define SQUARE_DIFFERRENCE_STANDARD 200
#define BAD_PATH_RTT_THRESHOLD_US 10000000 /* 10000000us = 10s */
#define GOOD_PATH_RTT_THRESHOLD_US 800000 /* 800000us = 0.8s */

#define TIME_SYNC_SEND_REPEATE_COUNT 20
#define TIME_SYNC_SEND_INTERVAL_TIME_MS 100 /* 100ms */
#define OFFSET_UPDATE_INTERVAL_MS 300000 /* 300000ms = 5min */
#define TIME_SYNC_REQUEST_OPTION_LEN 6
#define MUTATION_TIME 1000 /* 1000ms */
#define MAX_INT 0x7ffffff

#define PATH_RTT_ON 1
#define PATH_RTT_OFF 0
#define PATH_RTT_SWITCH_OPT_LEN 3

struct path_rtt_list_struct {
	spinlock_t lock;
	int list[PATH_LIST_SIZE];
	int index;
	int size;
	u64 sum;
	u32 max;
	u32 min;
	atomic_t state;
	atomic_t count;
};

enum {
	RECV_PATH_RTT_OPT = 0,
	RECV_TIME_SYNC_RESPOND = 1
};

static atomic_t time_sync_state;

static int offset;
spinlock_t offset_lock;
static int min_delay;
spinlock_t min_delay_lock;
static atomic_t achieved_number;
static struct hrtimer time_sync_send_timer;
static struct hrtimer offset_update_timer;
struct path_rtt_list_struct path_rtt_list;
struct work_struct path_rtt_opt_work;
struct list_queue path_rtt_opt_work_queue;

static int rtt_average(void)
{
	s64 sum;
	int ret = ERROR;
	int i;
	int j = 0;
	sum = 0;
	spin_lock_bh(&(path_rtt_list.lock));
	if (path_rtt_list.size >= STANDARD_CALCULATE_SIZE) {
		for (i = path_rtt_list.index; j < STANDARD_CALCULATE_SIZE; j++) {
			sum += path_rtt_list.list[i];
			i = (i + PATH_LIST_SIZE - 1) % PATH_LIST_SIZE;
		}
		ret = (int)(sum >> 4);
	}
	spin_unlock_bh(&(path_rtt_list.lock));
	return ret;
}

static u32 rtt_standard(void)
{
	int avg;
	u64 sqrt_sum;
	int i;
	int j = 0;
	u32 ret = 0xFFFFFFFF;
	sqrt_sum = 0;
	avg = rtt_average();
	spin_lock_bh(&(path_rtt_list.lock));
	if (path_rtt_list.size >= STANDARD_CALCULATE_SIZE) {
		for (i = path_rtt_list.index; j < STANDARD_CALCULATE_SIZE; j++) {
			sqrt_sum += (path_rtt_list.list[i] - avg) * (path_rtt_list.list[i] - avg);
			i = (i + PATH_LIST_SIZE - 1) % PATH_LIST_SIZE;
		}
		ret = int_sqrt64(sqrt_sum >> 4);
	}
	spin_unlock_bh(&(path_rtt_list.lock));
	return ret;
}

static void send_time_sync_option_packet(void)
{
	struct sk_buff *skb = NULL;
	struct link_info link_info_data;
	int path;
	if (get_link_info(&link_info_data) != SUCCESS)
		return;

	if (link_info_data.scene == SCENE_WIFI_MODEM)
		path = PATH_WIFI_1;
	else if	(link_info_data.scene == SCENE_MOEM_MODEM)
		path = PATH_MODEM_1;
	else
		return;

	skb = alloc_option_skb(TIME_SYNC_REQUEST_OPTION_LEN);
	if (unlikely(skb == NULL))
		return;

	u32 timestamp = option_timestamp_append(skb, 0);
	if (unlikely(timestamp == 0)) {
		log_err("timestamp is 0");
		dev_kfree_skb_any(skb);
		return;
	}
	u32 timestamp_us = htonl(get_rel_time_us());
	option_append(skb, HONOPT_TIME_SYNC_REQUEST, TIME_SYNC_REQUEST_OPTION_LEN,
				(char *)(&timestamp_us));
	struct iphdr *iph = ip_hdr(skb);
	struct udphdr *udph = udp_hdr(skb);
	iph->tot_len = htons(IP_SIZE + UDP_SIZE + HON_SIZE + get_options_len(skb) +
						HMAC_SIZE);
	udph->len = htons(UDP_SIZE + HON_SIZE + get_options_len(skb) + HMAC_SIZE);
	skb_put(skb, HMAC_SIZE);
	skb_send(skb, path);
	return;
}

bool get_time_sync_state(void)
{
	return atomic_read(&time_sync_state) == PATH_RTT_ON;
}

static int get_offset(void)
{
	int ret;
	spin_lock_bh(&offset_lock);
	ret = offset;
	spin_unlock_bh(&offset_lock);
	return ret;
}

static enum hrtimer_restart time_sync_send_func(struct hrtimer *timer)
{
	if (unlikely(!timer))
		return HRTIMER_NORESTART;

	send_time_sync_option_packet();
	hrtimer_forward_now(timer, ms_to_ktime(TIME_SYNC_SEND_INTERVAL_TIME_MS));

	return HRTIMER_RESTART;
}

static void path_rtt_stat(void)
{
	path_rtt_list.sum += path_rtt_list.list[path_rtt_list.index];

	if (path_rtt_list.list[path_rtt_list.index] > path_rtt_list.max)
		path_rtt_list.max = path_rtt_list.list[path_rtt_list.index];
	if (path_rtt_list.list[path_rtt_list.index] < path_rtt_list.min)
		path_rtt_list.min = path_rtt_list.list[path_rtt_list.index];

	if (path_rtt_list.index == PATH_LIST_SIZE - 1) {
		log_info("average %u max %u min %u", path_rtt_list.sum >> 8,
				path_rtt_list.max, path_rtt_list.min);

		path_rtt_list.max = 0;
		path_rtt_list.min = 0xFFFFFFFF;
		path_rtt_list.sum = 0;
	}
}

static void reset_path_rtt_list(void)
{
	spin_lock_bh(&(path_rtt_list.lock));
	memset_s(&(path_rtt_list.list), sizeof(path_rtt_list.list),
			0, sizeof(path_rtt_list.list));
	path_rtt_list.index = 0;
	path_rtt_list.size = 0;
	path_rtt_list.max = 0;
	path_rtt_list.min = 0xFFFFFFFF;
	path_rtt_list.sum = 0;
	spin_unlock_bh(&(path_rtt_list.lock));
	atomic_set(&(path_rtt_list.state), 0);
	atomic_set(&(path_rtt_list.count), 0);
	return;
}

static void path_rtt_list_insert(int path_rtt)
{
	spin_lock_bh(&(path_rtt_list.lock));
	path_rtt_list.index = (path_rtt_list.index + 1) % PATH_LIST_SIZE;
	path_rtt_list.size = (path_rtt_list.size + 1) > PATH_LIST_SIZE ?
						PATH_LIST_SIZE : path_rtt_list.size + 1;
	path_rtt_list.list[path_rtt_list.index] = path_rtt;
	path_rtt_stat();
	spin_unlock_bh(&(path_rtt_list.lock));
	if (atomic_read(&(path_rtt_list.state)) == 1)
		atomic_inc(&(path_rtt_list.count));
	return;
}

static void stop_time_sync(void)
{
	hrtimer_cancel(&time_sync_send_timer);
	hrtimer_cancel(&offset_update_timer);
	reset_path_rtt_list();
	spin_lock_bh(&min_delay_lock);
	min_delay = MAX_INT;
	spin_unlock_bh(&min_delay_lock);
	log_info("stop time sync");
	return;
}

static void send_rtt_switch_state_opt(u8 state)
{
	u8 switch_state = state;
	send_option_packet(HONOPT_PATH_RTT_SWITCH, PATH_RTT_SWITCH_OPT_LEN,
					(char *)(&switch_state));
	return;
}

static void start_time_sync(void)
{
	atomic_set(&achieved_number, 0);
	atomic_set(&time_sync_state, PATH_RTT_OFF);
	send_rtt_switch_state_opt(PATH_RTT_OFF);
	hrtimer_start(&time_sync_send_timer,
		ms_to_ktime(TIME_SYNC_SEND_INTERVAL_TIME_MS),
			HRTIMER_MODE_REL_SOFT);
	log_info("start time sync");
	return;
}

static void recv_path_rtt_handle(void *data)
{
	if (unlikely(!data))
		return;

	if (!get_time_sync_state())
		return;
	spin_lock_bh(&offset_lock);
	int path_rtt = ((struct path_rtt_opt_data *)data)->t6 -
					((struct path_rtt_opt_data *)data)->t5 + offset;
	spin_unlock_bh(&offset_lock);
	if (path_rtt <= 0) {
		stop_time_sync();
		return start_time_sync();
	}

	if (atomic_read(&(path_rtt_list.state)) == 0) {
		spin_lock_bh(&(path_rtt_list.lock));
			if (path_rtt_list.size > 0) {
				int last_index = (path_rtt_list.index + PATH_LIST_SIZE - 1) %
								PATH_LIST_SIZE;
				int last_path_rtt = path_rtt_list.list[last_index];
			if (abs(path_rtt - last_path_rtt) > MUTATION_TIME) {
				atomic_set(&(path_rtt_list.state), 1);
				atomic_set(&(path_rtt_list.count), 1);
			}
		}
		spin_unlock_bh(&(path_rtt_list.lock));
	}

	if (atomic_read(&(path_rtt_list.count)) == STANDARD_CALCULATE_SIZE) {
		u32 standard = rtt_standard();
		if (standard <= SQUARE_DIFFERRENCE_STANDARD) {
			stop_time_sync();
			return start_time_sync();
		}
		atomic_set(&(path_rtt_list.state), 0);
		atomic_set(&(path_rtt_list.count), 0);
	}

	path_rtt_list_insert(path_rtt);
	if (path_rtt >= BAD_PATH_RTT_THRESHOLD_US)
		set_path_rtt_dynamic_state(LINK_DYNAMIC_SLOW);
	else if (path_rtt <= GOOD_PATH_RTT_THRESHOLD_US)
		set_path_rtt_dynamic_state(LINK_DYNAMIC_NORMAL);

	return;
}

static void complete_update_offset(void)
{
	spin_lock_bh(&offset_lock);
	log_info("complete update offset %d", offset);
	spin_unlock_bh(&offset_lock);
	stop_time_sync();
	atomic_set(&time_sync_state, PATH_RTT_ON);
	send_rtt_switch_state_opt(PATH_RTT_ON);
	hrtimer_start(&offset_update_timer,
			ms_to_ktime(OFFSET_UPDATE_INTERVAL_MS),
				HRTIMER_MODE_REL_SOFT);
	return;
}

static enum hrtimer_restart update_offset_timer_func(struct hrtimer *timer)
{
	if (unlikely(!timer))
		return HRTIMER_NORESTART;
	start_time_sync();
	return HRTIMER_NORESTART;
}

static void recv_time_sync_respond_handle(void *data)
{
	if (unlikely(!data))
		return;

	s64 t1 = ((struct time_sync_respond_data *) data)->t1;
	s64 t2 = ((struct time_sync_respond_data *) data)->t2;
	s64 t3 = ((struct time_sync_respond_data *) data)->t3;
	s64 t4 = ((struct time_sync_respond_data *) data)->t4;
	int delay = t4 - t1;
	if (atomic_read(&achieved_number) >= TIME_SYNC_SEND_REPEATE_COUNT)
		return complete_update_offset();
	atomic_inc(&achieved_number);
	spin_lock_bh(&min_delay_lock);
	if (delay < min_delay) {
		min_delay = delay;
	} else {
		spin_unlock_bh(&min_delay_lock);
		return;
	}
	spin_unlock_bh(&min_delay_lock);
	int offset_tmp = ((t2 - t1) + (t3 - t4)) >> 1;
	if ((t2 - t1 - offset_tmp) <= 0 || (t4 - t3 + offset_tmp) <= 0)
		return;
	spin_lock_bh(&offset_lock);
	offset = offset_tmp;
	spin_unlock_bh(&offset_lock);
	return;
}

void recv_time_sync_respond(__u8 fid, void *opt_data)
{
	u32 timestamp = get_rel_time_us();
	struct link_info link_info_data;
	int main_path_fid;
	struct time_sync_respond_data data;

	if (unlikely(!opt_data))
		return;

	if (get_link_info(&link_info_data) != SUCCESS)
		return;

	if (link_info_data.scene == SCENE_WIFI_MODEM)
		main_path_fid = DETECT_PATH_VAL_WIFI_1;
	else if	(link_info_data.scene == SCENE_MOEM_MODEM)
		main_path_fid = DETECT_PATH_VAL_MODEM_1;
	else
		return;

	if (fid != main_path_fid)
		return;

	data.type = RECV_TIME_SYNC_RESPOND;
	data.t1 = ntohl(((struct time_sync_respond *) opt_data)->t1);
	data.t2 = ntohl(((struct time_sync_respond *) opt_data)->t2);
	data.t3 = ntohl(((struct time_sync_respond *) opt_data)->t3);
	data.t4 = timestamp;

	struct list_node *node = list_node_alloc((void *)(&data),
							sizeof(struct time_sync_respond_data));
	if (node == NULL) {
		log_err("NULL Pointer, error");
		return;
	}
	enqueue_list_queue(&path_rtt_opt_work_queue, node);
	schedule_work(&path_rtt_opt_work);
	return;
}

void recv_path_rtt(__u8 fid, void *opt_data)
{
	u32 timestamp = get_rel_time_us();
	struct link_info link_info_data;
	int main_path_fid;
	struct path_rtt_opt_data data;
	if (unlikely(!opt_data))
		return;

	if (get_link_info(&link_info_data) != SUCCESS)
		return;

	if (link_info_data.scene == SCENE_WIFI_MODEM)
		main_path_fid = DETECT_PATH_VAL_WIFI_1;
	else if	(link_info_data.scene == SCENE_MOEM_MODEM)
		main_path_fid = DETECT_PATH_VAL_MODEM_1;
	else
		return;

	if (fid != main_path_fid)
		return;

	data.type = RECV_PATH_RTT_OPT;
	data.t5 = ntohl(((struct path_rtt_opt *)opt_data)->t5);
	data.t6 = timestamp;
	struct list_node *node = list_node_alloc((void *)(&data),
							sizeof(struct path_rtt_opt_data));
	if (node == NULL) {
		log_err("NULL Pointer, error");
		return;
	}
	enqueue_list_queue(&path_rtt_opt_work_queue, node);
	schedule_work(&path_rtt_opt_work);
	return;
}

static void cloud_network_path_rtt_opt_work_handle(struct work_struct *work)
{
	struct list_node *node = NULL;

	if (unlikely(work == NULL)) {
		log_err("work is NULL, error");
		return;
	}

	while (list_queue_empty(&path_rtt_opt_work_queue) == 0) {
		node = dequeue_list_queue(&path_rtt_opt_work_queue);
		if (node == NULL) {
			log_err("dequeue a null node, error");
			break;
		}
		u32 type = *((u32 *)(node->data));
		switch (type) {
		case RECV_PATH_RTT_OPT:
			recv_path_rtt_handle(node->data);
			break;
		case RECV_TIME_SYNC_RESPOND:
			log_info("RECV_TIME_SYNC_RESPOND");
			recv_time_sync_respond_handle(node->data);
			break;
		default:
			log_err("type %u unknown, error", type);
		}
		list_node_free(node);
		node = NULL;
	}
	return;
}

void start_path_rtt_module(void)
{
	if (get_time_sync_state())
		return complete_update_offset();
	stop_time_sync();
	return start_time_sync();
}

void stop_path_rtt_module(void)
{
	return stop_time_sync();
}

void cloud_network_time_sync_init(void)
{
	atomic_set(&achieved_number, 0);
	atomic_set(&time_sync_state, PATH_RTT_OFF);
	spin_lock_init(&(path_rtt_list.lock));
	init_list_queue(&path_rtt_opt_work_queue);
	INIT_WORK(&path_rtt_opt_work, cloud_network_path_rtt_opt_work_handle);
	reset_path_rtt_list();
	spin_lock_init(&min_delay_lock);
	spin_lock_init(&offset_lock);
	spin_lock_bh(&min_delay_lock);
	min_delay = MAX_INT;
	spin_unlock_bh(&min_delay_lock);
	hrtimer_init(&time_sync_send_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL_SOFT);
	time_sync_send_timer.function = time_sync_send_func;
	hrtimer_init(&offset_update_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL_SOFT);
	offset_update_timer.function = update_offset_timer_func;
	set_path_rtt_dynamic_state(LINK_DYNAMIC_SLOW);
	return;
}

void cloud_network_time_sync_exit(void)
{
	stop_time_sync();
	cancel_work_sync(&path_rtt_opt_work);
	clean_list_queue(&path_rtt_opt_work_queue);
	return;
}