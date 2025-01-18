/*
 * cloud_network_detect.c
 *
 * cloud network detect compass function kernel module implementation
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include "cloud_network_detect.h"
#include <linux/spinlock.h>
#include <linux/sort.h>
#include <linux/time.h>
#include <securec.h>
#include "cloud_network_honhdr.h"
#include "cloud_network_option.h"
#include "cloud_network_utils.h"
#include "cloud_network_param.h"
#include "cloud_network_rx.h"
#include "cloud_network_device.h"
#include "cloud_network_tx.h"

#define COMPASS_DETECT_NORMAL_CHECK_NUM 2
#define COMPASS_DETECT_NORMAL_CHECK_TIMEOUT 1

struct detect_ctrl {
	struct list_queue work_queue;
	struct work_struct detect_handle_work;
};

atomic_t rtt_gain_show_counter;
static struct detect_ops detect_modules[DETECT_MODULE_ID_MAX];
static struct detect_path_info detect_paths[DETECT_PATH_NUM_MAX + 1];
struct hrtimer send_packet_hrtimer;
struct hrtimer rtt_resp_timeout_hrtimer;
static struct detect_ctrl detect_mgr;
static atomic_t link_dynamic_status;
static bool param_init_status;
struct dynamic_param_base dynamic_rtt_param;
atomic_t link_dynamic_rtt_quality;
atomic_t link_dynamic_interval_quality;
atomic_t link_dynamic_wifi_channel_qoe;
atomic_t link_dynamic_modem_channel_qoe;
atomic_t path_rtt_dynamic_state;

static void traffic_report(void)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_traffic *msg_rept = NULL;

	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_traffic), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return;
	}

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_traffic);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = TRAFFIC_REPORT;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_traffic);

	msg_rept = (struct rept_traffic *)(msg_header->data);
	msg_rept->traffic = get_secondary_traffic();
	log_info("traffic report %llu", msg_rept->traffic);
	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return;
}

static void rtt_gain_show_report(struct rept_rtt_gain_show *data)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_rtt_gain_show *msg_rept = NULL;

	if (unlikely(data == NULL)) {
		log_err("NULL pointer, error");
		return;
	}

	log_info("event report rtt gain show status %u combination %u primary_path %u second_path %u", data->status,
		data->combination_rtt_average, data->primary_path_rtt_average, data->second_path_rtt_average);

	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_rtt_gain_show), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return;
	}

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_rtt_gain_show);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = RTT_GAIN_SHOW;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_rtt_gain_show);

	msg_rept = (struct rept_rtt_gain_show *)(msg_header->data);
	msg_rept->status = data->status;
	msg_rept->primary_path_rtt_average = data->primary_path_rtt_average;
	msg_rept->second_path_rtt_average = data->second_path_rtt_average;
	msg_rept->combination_rtt_average = data->combination_rtt_average;

	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return;
}

static int get_rtt_value(u32 path, int *rtt, u32 rtt_size, u32 default_value)
{
	int iterator;

	if (path <= 0 || path >= DETECT_PATH_NUM_MAX || rtt_size > PATH_LIST_NUM || rtt == NULL) {
		log_err("param value is invalid, error");
		return ERROR;
	}

	spin_lock_bh(&(detect_paths[path].lock));
	for (int i = 0; i < rtt_size; i++) {
		iterator = (detect_paths[path].send_iterator - 1 - i + PATH_LIST_NUM) % PATH_LIST_NUM;
		if (detect_paths[path].rtt_list[iterator] > 0)
			rtt[i] = detect_paths[path].rtt_list[iterator];
		else
			rtt[i] = default_value;
	}
	spin_unlock_bh(&(detect_paths[path].lock));
	return SUCCESS;
}

static void rtt_gain_show_handle(void)
{
	struct link_info link_info_data;
	struct rept_rtt_gain_show rept_rtt_gain = {0};
	int  combination_rtt[PATH_LIST_NUM] = {0};
	int  primary_path_rtt[PATH_LIST_NUM] = {0};
	int  second_path_rtt[PATH_LIST_NUM] = {0};
	u32  primary_path = 0;
	u32  second_path = 0;

	if (!cloud_network_started() || (get_link_info(&link_info_data) != SUCCESS))
		return;

	atomic_inc(&rtt_gain_show_counter);
	if (atomic_read(&rtt_gain_show_counter) != link_info_data.rtt_gain_show_report_interval)
		return;
	traffic_report();
	log_info("rtt gain show handle, rtt_gain_show_counter %d", atomic_read(&rtt_gain_show_counter));

	atomic_set(&rtt_gain_show_counter, 0);
	if (link_info_data.scene == SCENE_MOEM_MODEM) {
		primary_path = get_default_fid();
		if (primary_path == DETECT_PATH_VAL_ERROR)
			return;
		second_path = primary_path == DETECT_PATH_VAL_MODEM_1 ? DETECT_PATH_VAL_MODEM_2 : DETECT_PATH_VAL_MODEM_1;
	} else if (link_info_data.scene == SCENE_WIFI_MODEM) {
		primary_path = DETECT_PATH_VAL_WIFI_1;
		second_path = DETECT_PATH_VAL_MODEM_1;
	} else {
		return;
	}

	if (get_rtt_value(primary_path, primary_path_rtt, link_info_data.rtt_gain_show_calc_num, 0) != SUCCESS)
		return;
	rept_rtt_gain.primary_path_rtt_average = mean(primary_path_rtt, link_info_data.rtt_gain_show_calc_num);
	rept_rtt_gain.second_path_rtt_average = 0;
	rept_rtt_gain.combination_rtt_average = 0;
	if (get_tx_rx_state() != TX_RX_STATE_1T1R) {
		if (get_redundant_status()) {
			rept_rtt_gain.status = 0;
			if (get_rtt_value(second_path, second_path_rtt, link_info_data.rtt_gain_show_calc_num, 0) != SUCCESS)
				return;
			rept_rtt_gain.second_path_rtt_average = mean(second_path_rtt, link_info_data.rtt_gain_show_calc_num);
			rept_rtt_gain.combination_rtt_average = combination_min_mean(primary_path_rtt, second_path_rtt,
				link_info_data.rtt_gain_show_calc_num);
		} else {
			rept_rtt_gain.status = 1;
		}
	} else {
		rept_rtt_gain.status = 2;
	}

	rtt_gain_show_report(&rept_rtt_gain);
	return;
}

static void rtt_gain_show_init(void)
{
	atomic_set(&rtt_gain_show_counter, 0);
	return;
}

void rtt_gain_show_counter_reset(void)
{
	atomic_set(&rtt_gain_show_counter, 0);
	return;
}

static int path_bit_to_val(int path_bit)
{
	switch (path_bit) {
	case DETECT_PATH_BIT_MODEM_1:
		return DETECT_PATH_VAL_MODEM_1;
	case DETECT_PATH_BIT_MODEM_2:
		return DETECT_PATH_VAL_MODEM_2;
	case DETECT_PATH_BIT_WIFI_1:
		return DETECT_PATH_VAL_WIFI_1;
	case DETECT_PATH_BIT_WIFI_2:
		return DETECT_PATH_VAL_WIFI_2;
	default:
		log_err("path_bit_to_val error");
		return DETECT_PATH_VAL_ERROR;
	}
}

static int path_val_to_bit(int path_val)
{
	switch (path_val) {
	case DETECT_PATH_VAL_MODEM_1:
		return DETECT_PATH_BIT_MODEM_1;
	case DETECT_PATH_VAL_MODEM_2:
		return DETECT_PATH_BIT_MODEM_2;
	case DETECT_PATH_VAL_WIFI_1:
		return DETECT_PATH_BIT_WIFI_1;
	case DETECT_PATH_VAL_WIFI_2:
		return DETECT_PATH_BIT_WIFI_2;
	default:
		log_err("path_val_to_bit error");
		return DETECT_PATH_BIT_ERROR;
	}
}

/* must be called with spin_lock_bh(&(detect_paths[path].lock)) held */
static bool compass_detect_normal_check_path(int path, u32 current_timestamp)
{
	bool ret = false;
	int iterator;

	if (path < 0 || path >= DETECT_PATH_NUM_MAX)
		return false;

	for (int i = 0; i < COMPASS_DETECT_NORMAL_CHECK_NUM; i++) {
		iterator = (detect_paths[path].send_iterator - 1 - i + PATH_LIST_NUM) % PATH_LIST_NUM;
		log_info("path %d iterator %u timestamp_list_rx %u timestamp_list %u rtt_list %u",
			path, iterator, detect_paths[path].timestamp_list_rx[iterator],
			detect_paths[path].timestamp_list[iterator],
			detect_paths[path].rtt_list[iterator]);
		if ((detect_paths[path].timestamp_list_rx[iterator] != 0) &&
			(current_timestamp * 1000 - detect_paths[path].timestamp_list_rx[iterator] <
			((i + 1 + COMPASS_DETECT_NORMAL_CHECK_TIMEOUT) * 1000 * 1000))) {
			log_info("find the RTT response, compass detect normal check true");
			ret = true;
			break;
		}
	}
	return ret;
}

bool compass_detect_normal_check(int paths, u32 current_timestamp)
{
	bool ret = false;
	int iterator;

	for (int i = 0b1000; i != 0; i >>= 1) { /* search valid path */
		if (i & paths) {
			int path = path_bit_to_val(i);
			if (path < 0 || path >= DETECT_PATH_NUM_MAX)
				continue;

			spin_lock_bh(&(detect_paths[path].lock));
			if (detect_paths[path].send_iterator < 0 ||
				detect_paths[path].send_iterator >= PATH_LIST_NUM) {
				log_err("iter is invalid, error");
				spin_unlock_bh(&(detect_paths[path].lock));
				continue;
			}

			ret = compass_detect_normal_check_path(path, current_timestamp);
			spin_unlock_bh(&(detect_paths[path].lock));
			if (ret)
				break;
		}
	}

	return ret;
}

void change_detect_path(int module_id, int paths)
{
	if (module_id <= DETECT_MODULE_ID_ERROR || module_id >= DETECT_MODULE_ID_MAX) {
		log_err("module id is invalid");
		return;
	}
	detect_modules[module_id].paths = paths;
}

static int get_all_detect_paths(void)
{
	int paths = 0;
	for (int i = 0; i < DETECT_MODULE_ID_MAX; i++) {
		if (detect_modules[i].module_id != DETECT_MODULE_ID_ERROR)
			paths |= detect_modules[i].paths;
	}
	return paths;
}

static int get_min_detect_interval(void)
{
	int min_interval = INT_MAX;
	for (int i = 0; i < DETECT_MODULE_ID_MAX; i++) {
		if (detect_modules[i].module_id > -1 && detect_modules[i].time_interval < min_interval)
			min_interval = detect_modules[i].time_interval;
	}

	return min_interval;
}

static int dynamic_link_changed_report(bool redundant_status)
{
	struct link_info link_info_data;
	if (get_link_info(&link_info_data) != SUCCESS) {
		log_err("calc_rtt, get link info error");
		return ERROR;
	}

	int status = redundant_status ? 2 : 1;
	if (link_info_data.scene == SCENE_WIFI_MODEM || link_info_data.scene == SCENE_MOEM_MODEM) {
		log_info("event report dynamic link changed to %d, do not report", status);
		return ERROR;
	}
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_dynamic *msg_rept = NULL;

	log_info("event report dynamic link changed to %d", status);
	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_dynamic), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("dynamic link report kmalloc failed");
		return ERROR;
	}

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_dynamic);
	
	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = DYNAMIC_PATH_STATUS;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_dynamic);
	
	msg_rept = (struct rept_dynamic *)(msg_header->data);
	msg_rept->status = status;

	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return SUCCESS;
}

void change_wifi_channel_qoe_status(int status)
{
	log_info("change wifi channel qoe status to %d", status);
	bool pre_redundant_status = is_redundant_status();
	if (atomic_read(&link_dynamic_wifi_channel_qoe) != status)
		atomic_set(&(link_dynamic_wifi_channel_qoe), status);

	bool post_redundant_status = is_redundant_status();
	if (post_redundant_status != pre_redundant_status)
		dynamic_link_changed_report(post_redundant_status);

	return;
}

void change_modem_channel_qoe_status(int status)
{
	log_info("change modem channel qoe status to %d", status);
	bool pre_redundant_status = is_redundant_status();

	if (atomic_read(&link_dynamic_modem_channel_qoe) != status)
		atomic_set(&(link_dynamic_modem_channel_qoe), status);

	bool post_redundant_status = is_redundant_status();
	if (post_redundant_status != pre_redundant_status)
		dynamic_link_changed_report(post_redundant_status);

	return;
}

void set_path_rtt_dynamic_state(int state)
{
	bool pre_redundant_status = is_redundant_status();
	if (state < LINK_DYNAMIC_STATUS_MAX)
		atomic_set(&(path_rtt_dynamic_state), state);

	bool post_redundant_status = is_redundant_status();
	if (post_redundant_status != pre_redundant_status)
		dynamic_link_changed_report(post_redundant_status);

	return;
}

static int variance(int *values, int mean, int length)
{
	if (values == NULL || length < 0) {
		log_err("NULL pointer, error");
		return ERROR;
	}
	int var_result = 0;
	for (int i = 0; i < length; ++i)
		var_result += (values[i] - mean) * (values[i] - mean);

	return var_result;
}

static int covariance(int *x, int mean_x, int *y, int mean_y, int length)
{
	if ((x == NULL) || (y == NULL) || (length < 0)) {
		log_err("NULL pointer, error");
		return ERROR;
	}
	int cov = 0;
	for (int i = 0; i < length; i++)
		cov += (x[i] - mean_x) * (y[i] - mean_y);

	return cov;
}

static int coefficients(int **data, int length)
{
	if ((data == NULL) || (length <= 0)) {
		log_err("NULL pointer, error");
		return ERROR;
	}
	int *x = (int *) kmalloc(length * sizeof(int), GFP_ATOMIC);
	if (unlikely(!x))
		return ERROR;

	int *y = (int *) kmalloc(length * sizeof(int), GFP_ATOMIC);
	if (unlikely(!y)) {
		kfree(x);
		return ERROR;
	}

	int count_zero = 0;
	int i;
	for (i = 0; i < length; ++i) {
		x[i] = data[i][0];
		y[i] = data[i][1];
		if (y[i] == 0)
			count_zero += 1;
	}
	int x_mean = mean(x, length);
	int y_mean = mean(y, length - count_zero);
	int var_value = variance(x, x_mean, length);
	for (i = 0; i < length; ++i)
		y[i] = y[i] == 0 ? y_mean : y[i];
	int slope = var_value == 0 ? 0 : covariance(x, x_mean, y, y_mean, length) / var_value;
	kfree(x);
	kfree(y);
	for (i = 0; i < length; i++)
		kfree(data[i]);
	kfree(data);
	return slope;
}

static void calc_rtt_decision(int slope, int rtt_mean_calc, int loss_rate, int calc_length)
{
	if (calc_length <= 0) {
		log_err("calc length is less than 0");
		return;
	}
	rtt_mean_calc = rtt_mean_calc / calc_length;
	loss_rate = loss_rate * 100 / calc_length;
	log_info("rtt LR: gradient is %d, mean is %d, loss_rate is %d, slope_thresh is %d, "
			 "good_thresh is %d, bad thresh is %d", slope, rtt_mean_calc, loss_rate,
			dynamic_rtt_param.slope_thresh, dynamic_rtt_param.mean_good_thresh,
			dynamic_rtt_param.mean_bad_thresh);
	if ((slope > 0 &&
		slope >= dynamic_rtt_param.slope_thresh) ||
		(rtt_mean_calc > dynamic_rtt_param.mean_bad_thresh) || (loss_rate > 0))
		set_rtt_quality(LINK_DYNAMIC_SLOW);
	else if ((slope < 0 && rtt_mean_calc < dynamic_rtt_param.mean_bad_thresh) ||
			  rtt_mean_calc < dynamic_rtt_param.mean_good_thresh)
		set_rtt_quality(LINK_DYNAMIC_NORMAL);
	return;
}

static void calc_rtt_gradient(int path)
{
	int front;
	int rear;
	int slope;
	int calc_length = dynamic_rtt_param.rtt_qoe_num;
	int rtt_list_value;
	int rtt_mean_calc = 0;
	int loss_num = 0;
	int **rtt_value;

	spin_lock_bh(&(detect_paths[path].lock));
	rear = detect_paths[path].send_iterator;
	front = (rear - calc_length + PATH_LIST_NUM) % PATH_LIST_NUM;
	if (detect_paths[path].rtt_list[front] == UINT_MAX) {
		log_info("length is less than defination, bypass calc");
		spin_unlock_bh(&(detect_paths[path].lock));
		return;
	}

	calc_length = (rear - front + PATH_LIST_NUM) % PATH_LIST_NUM;
	rtt_value = (int **) kmalloc(calc_length * sizeof(int *), GFP_ATOMIC);
	if (unlikely(!rtt_value)) {
		spin_unlock_bh(&(detect_paths[path].lock));
		return;
	}
	for (int i = 0; i < calc_length; i++) {
		rtt_value[i] = (int *) kmalloc(2 * sizeof(int), GFP_ATOMIC);
		if (unlikely(!rtt_value[i])) {
			for (int j = 0; j < i ; j++)
				kfree(rtt_value[j]);
			kfree(rtt_value);
			spin_unlock_bh(&(detect_paths[path].lock));
			return;
		}
		rtt_value[i][0] = i;
		rtt_list_value = detect_paths[path].rtt_list[(front + i) % PATH_LIST_NUM];
		if (rtt_list_value == 0) {
			rtt_mean_calc += get_rel_time_us() -
				detect_paths[path].timestamp_list[(front + i) % PATH_LIST_NUM];
			loss_num += 1;
		} else {
			rtt_mean_calc += rtt_list_value;
		}
		rtt_value[i][1] = rtt_list_value;
	}
	spin_unlock_bh(&(detect_paths[path].lock));
	slope = coefficients(rtt_value, calc_length);
	calc_rtt_decision(slope, rtt_mean_calc, loss_num, calc_length);
	return;
}

void set_rtt_quality(int quality)
{
	bool pre_redundant_status = is_redundant_status();
	if (quality < LINK_DYNAMIC_STATUS_MAX)
		atomic_set(&(link_dynamic_rtt_quality), quality);
	
	bool post_redundant_status = is_redundant_status();
	if (post_redundant_status != pre_redundant_status)
		dynamic_link_changed_report(post_redundant_status);
	
	return;
}

void set_interval_quality(int quality)
{
	bool pre_redundant_status = is_redundant_status();
	if (quality < LINK_DYNAMIC_STATUS_MAX)
		atomic_set(&(link_dynamic_interval_quality), quality);
	
	bool post_redundant_status = is_redundant_status();
	if (post_redundant_status != pre_redundant_status)
		dynamic_link_changed_report(post_redundant_status);
	
	return;
}

int get_rtt_quality(void)
{
	return atomic_read(&(link_dynamic_rtt_quality));
}

int get_interval_quality(void)
{
	return atomic_read(&(link_dynamic_interval_quality));
}

int get_wifi_quality(void)
{
	return atomic_read(&(link_dynamic_wifi_channel_qoe));
}

int get_modem_quality(void)
{
	return atomic_read(&(link_dynamic_modem_channel_qoe));
}

int get_path_rtt_dynamic_state(void)
{
	return atomic_read(&(path_rtt_dynamic_state));
}

int get_channel_quality(void)
{
	struct link_info link_info_data;
	if (get_link_info(&link_info_data) != SUCCESS)
		return LINK_DYNAMIC_SLOW;

	if (link_info_data.scene == SCENE_WIFI_MODEM)
		return get_wifi_quality();
	else
		return get_modem_quality();
}

bool get_redundant_status(void)
{
	return atomic_read(&(link_dynamic_status)) == LINK_DYNAMIC_REDUNDANT;
}

int get_dynamic_state_to_buffer(char *buffer, int buffer_len)
{
	int len = 0;
	int dynamic_state = 0;
	if (unlikely(!buffer || buffer_len < NUM_10))
		return ERROR;

	if (!cloud_network_started())
		dynamic_state = 0;
	else if (get_redundant_status())
		dynamic_state = 2;
	else
		dynamic_state = 1;

	len = snprintf_s(buffer, buffer_len, buffer_len - 1, "%d\r\n", dynamic_state);
	if (unlikely(len < 0))
		return ERROR;

	return len;
}

bool is_redundant_status(void)
{
	if ((get_rtt_quality() == LINK_DYNAMIC_SLOW ||
		get_interval_quality() == LINK_DYNAMIC_SLOW ||
		get_channel_quality() == LINK_DYNAMIC_SLOW ||
		get_path_rtt_dynamic_state() == LINK_DYNAMIC_SLOW) &&
		get_tx_rx_state() == TX_RX_STATE_2T2R) {
		atomic_set(&(link_dynamic_status), LINK_DYNAMIC_REDUNDANT);
		start_gain_detection();
	} else {
		atomic_set(&(link_dynamic_status), LINK_DYNAMIC_SINGLE);
		stop_gain_detection();
	}
	return atomic_read(&(link_dynamic_status)) == LINK_DYNAMIC_REDUNDANT;
}

static int get_main_path(void)
{
	int path_select = 0;
	struct link_info link_info_data;
	if (get_link_info(&link_info_data) != SUCCESS) {
		log_err("calc_rtt, get link info error");
		return ERROR;
	}

	int current_fid = get_default_fid();
	if (current_fid == ERROR && link_info_data.scene == SCENE_MOEM_MODEM) {
		log_info("get default fid error, return");
		return ERROR;
	}

	path_select = link_info_data.scene == SCENE_WIFI_MODEM ?
		DETECT_PATH_VAL_WIFI_1 : current_fid;
	return path_select;
}

void calc_rtt_gradient_process(int path)
{
	if (!is_cloud_network_enable()) {
		log_err("cloud network disabled, do not calculate");
		return;
	}

	if (path < 0 || path >= DETECT_PATH_NUM_MAX) {
		log_err("calc_rtt, path value is invalid");
		return;
	}

	int path_select = get_main_path();
	if (path_select == path)
		calc_rtt_gradient(path);
	return;
}

void add_path_timestamp_send(int paths, u32 timestamp_send)
{
	for (int i = 0b1000; i != 0; i >>= 1) { /* search valid path */
		if (i & paths) {
			int path = path_bit_to_val(i);
			calc_rtt_gradient_process(path);
			if (path < 0 || path >= DETECT_PATH_NUM_MAX)
				return;

			if (detect_paths[path].send_iterator < 0 ||
				detect_paths[path].send_iterator >= PATH_LIST_NUM) {
				log_info("iter is invalid, error");
				break;
			}

			spin_lock_bh(&(detect_paths[path].lock));
			if (detect_paths[path].rtt_list != NULL &&
				detect_paths[path].timestamp_list != NULL) {
				detect_paths[path].rtt_list[detect_paths[path].send_iterator] =
					0;
				detect_paths[path].timestamp_list[detect_paths[path].send_iterator] =
					timestamp_send;
				detect_paths[path].timestamp_list_rx[detect_paths[path].send_iterator] =
					0;
				detect_paths[path].send_iterator++;
				detect_paths[path].send_iterator %= PATH_LIST_NUM;
			}
			spin_unlock_bh(&(detect_paths[path].lock));
		}
	}
}

static bool update_path_data(int path, u32 timestamp_send, u32 timestamp_recv)
{
	u32 rtt = timestamp_recv - timestamp_send;
	int iter;
	bool ret = false;

	if (path < 0 || path >= DETECT_PATH_NUM_MAX)
		return ret;

	spin_lock_bh(&(detect_paths[path].lock));
	iter = detect_paths[path].send_iterator;
	do {
		if (detect_paths[path].timestamp_list == NULL) {
			log_info("timestamp list is NULL Pointer, error");
			continue;
		}
		if (detect_paths[path].rtt_list == NULL) {
			log_info("rtt list is NULL Pointer, error");
			continue;
		}
		if (iter < 0 || iter >= PATH_LIST_NUM) {
			log_info("iter is invalid, error");
			break;
		}
		iter = (iter - 1 + PATH_LIST_NUM) % PATH_LIST_NUM;
		if (detect_paths[path].timestamp_list[iter] == timestamp_send) {
			detect_paths[path].timestamp_list_rx[iter] = timestamp_recv;
			detect_paths[path].rtt_list[iter] = rtt;
			log_info("path %d rtt %u", path, rtt);
			ret = true;
			break;
		}
		if (detect_paths[path].timestamp_list[iter] < timestamp_send)
			break;
	} while (iter != detect_paths[path].send_iterator);
	spin_unlock_bh(&(detect_paths[path].lock));
	return ret;
}

static int rtt_compare(const void *a, const void *b)
{
	const int *r1 = NULL;
	const int *r2 = NULL;

	if ((a == NULL) || (b == NULL))
		return 0;

	r1 = a;
	r2 = b;
	if (*r1 < *r2)
		return -1;
	if (*r1 > *r2)
		return 1;
	return 0;
}

static u32 rtt_average(const int *array, int array_len)
{
	u64 sum;
	int i;
	if ((array == NULL) || (array_len <= 0)) {
		log_err("param is invalid, error");
		return 0;
	}

	sum = 0;
	for (i = 0; i < array_len; i++)
		sum += array[i];

	return (u32)(sum / array_len);
}

static u32 rtt_standard(const int *array, int array_len)
{
	u32 avg;
	u64 sqrt_sum;
	int i;

	if ((array == NULL) || (array_len <= 0)) {
		log_err("array is NULL, error");
		return 0;
	}

	avg = rtt_average(array, array_len);
	sqrt_sum = 0;
	for (i = 0; i < array_len; i++)
		sqrt_sum += (array[i] - avg) * (array[i] - avg);
	return int_sqrt64(sqrt_sum / array_len);
}

static int get_rtt_list(int path, int range, u32 timestamp_now_us, int *rtt_list)
{
	int iter;
	int count = 0;
	if (unlikely(path < 0 || path >= DETECT_PATH_NUM_MAX))
		return count;

	if (unlikely(rtt_list == NULL)) {
		log_err("null pointer, error");
		return count;
	}

	iter = (detect_paths[path].send_iterator - 1 + PATH_LIST_NUM) % PATH_LIST_NUM;
	while ((detect_paths[path].timestamp_list[iter] != 0) &&
			(((u32)(detect_paths[path].timestamp_list[iter]) +
			range * USEC_PER_SEC) > timestamp_now_us)) {
		rtt_list[count] = range * USEC_PER_SEC;
		if (detect_paths[path].rtt_list[iter] != 0)
			rtt_list[count] = detect_paths[path].rtt_list[iter];

		count++;
		if (count == PATH_LIST_NUM) {
			log_info("rtt_list list is no space");
			break;
		}
		iter = (iter - 1 + PATH_LIST_NUM) % PATH_LIST_NUM;
	}
	return count;
}

void calculate_rtt_qos(int path, int range, u32 *average, u32 *stand)
{
	int count = 0;
	u32 timestamp_us = get_rel_time_us();
	int rtt[PATH_LIST_NUM];

	if (unlikely(path < 0 || path >= DETECT_PATH_NUM_MAX))
		return;

	if (unlikely(average == NULL || stand == NULL)) {
		log_err("null pointer, error");
		return;
	}

	if (unlikely(range <= 0)) {
		log_err("range error");
		return;
	}

	memset_s(rtt, sizeof(int) * PATH_LIST_NUM,
			0, sizeof(int) * PATH_LIST_NUM);

	spin_lock_bh(&(detect_paths[path].lock));
	count = get_rtt_list(path, range, timestamp_us, rtt);
	spin_unlock_bh(&(detect_paths[path].lock));

	log_info("count %d", count);
	if (count == 0) {
		log_info("no rtt data in range");
		return;
	}

	sort(rtt, count, sizeof(int), rtt_compare, NULL);
	*average = rtt_average(rtt + count / 3, count / 3 + count % 3);
	*stand = rtt_standard(rtt + count / 3, count / 3 + count % 3);

	return;
}

static void detect_paths_init(void)
{
	for (int i = 0; i < DETECT_PATH_NUM_MAX; i++) {
		spin_lock_init(&detect_paths[i].lock);
		spin_lock_bh(&(detect_paths[i].lock));
		detect_paths[i].rtt_list =
			(int *)kmalloc(sizeof(int) * PATH_LIST_NUM, GFP_ATOMIC);
		if (detect_paths[i].rtt_list != NULL)
			memset_s(detect_paths[i].rtt_list, sizeof(int) * PATH_LIST_NUM,
				UINT_MAX, sizeof(int) * PATH_LIST_NUM);

		detect_paths[i].timestamp_list =
			(int *)kmalloc(sizeof(int) * PATH_LIST_NUM, GFP_ATOMIC);
		if (detect_paths[i].timestamp_list != NULL)
			memset_s(detect_paths[i].timestamp_list, sizeof(int) * PATH_LIST_NUM,
				0, sizeof(int) * PATH_LIST_NUM);

		detect_paths[i].timestamp_list_rx =
			(int *)kmalloc(sizeof(int) * PATH_LIST_NUM, GFP_ATOMIC);
		if (detect_paths[i].timestamp_list_rx != NULL)
			memset_s(detect_paths[i].timestamp_list_rx, sizeof(int) * PATH_LIST_NUM,
				0, sizeof(int) * PATH_LIST_NUM);
		detect_paths[i].send_iterator = 0;
		spin_unlock_bh(&(detect_paths[i].lock));
	}
	return;
}

static void detect_paths_deinit(void)
{
	for (int i = 0; i < DETECT_PATH_NUM_MAX; i++) {
		spin_lock_bh(&(detect_paths[i].lock));
		if (!detect_paths[i].rtt_list) {
			kfree(detect_paths[i].rtt_list);
			detect_paths[i].rtt_list = NULL;
		}

		if (!detect_paths[i].timestamp_list) {
			kfree(detect_paths[i].timestamp_list);
			detect_paths[i].timestamp_list = NULL;
		}

		if (!detect_paths[i].timestamp_list_rx) {
			kfree(detect_paths[i].timestamp_list_rx);
			detect_paths[i].timestamp_list_rx = NULL;
		}

		spin_unlock_bh(&(detect_paths[i].lock));
	}
}

static void detect_paths_reset(void)
{
	for (int i = 0; i < DETECT_PATH_NUM_MAX; i++) {
		spin_lock_bh(&(detect_paths[i].lock));
		if (detect_paths[i].rtt_list != NULL)
			memset_s(detect_paths[i].rtt_list, sizeof(int) * PATH_LIST_NUM,
				UINT_MAX, sizeof(int) * PATH_LIST_NUM);

		if (detect_paths[i].timestamp_list != NULL)
			memset_s(detect_paths[i].timestamp_list, sizeof(int) * PATH_LIST_NUM,
				0, sizeof(int) * PATH_LIST_NUM);

		if (detect_paths[i].timestamp_list_rx != NULL)
			memset_s(detect_paths[i].timestamp_list_rx, sizeof(int) * PATH_LIST_NUM,
				0, sizeof(int) * PATH_LIST_NUM);
		spin_unlock_bh(&(detect_paths[i].lock));
	}
	return;
}

static struct sk_buff *alloc_detect_skb(int timestamp)
{
	struct sk_buff *skb = NULL;

	skb = alloc_option_skb(sizeof(u8) + sizeof(u8) + sizeof(u32));
	if (unlikely(skb == NULL)) {
		log_err("NULL Pointer, error");
		return NULL;
	}

	option_timestamp_append(skb, timestamp);
	struct iphdr *iph = ip_hdr(skb);
	struct udphdr *udph = udp_hdr(skb);

	iph->tot_len = htons(IP_SIZE + UDP_SIZE + HON_SIZE + get_options_len(skb) + HMAC_SIZE);
	udph->len = htons(UDP_SIZE + HON_SIZE + get_options_len(skb) + HMAC_SIZE);
	skb_put(skb, HMAC_SIZE);
	return skb;
}

int detect_packet_recv(int path, struct hon_option_detect *detect)
{
	struct detect_work_rcv_packet detect_recv;

	if (!is_cloud_network_enable())
		return HON_OPT_HANDLE_FAILED;

	detect_recv.type = DETECT_WORK_RCV_PACKET;
	detect_recv.msg_len = sizeof(struct detect_work_rcv_packet);
	detect_recv.path = path;
	detect_recv.timestamp_send = ntohl(detect->timestamp);
	detect_recv.timestamp_recv = get_rel_time_us();
	struct list_node *node = list_node_alloc((void *)(&detect_recv), sizeof(struct detect_work_rcv_packet));
	if (node == NULL) {
		log_err("NULL Pointer, error");
		return HON_OPT_HANDLE_FAILED;
	}
	enqueue_list_queue(&(detect_mgr.work_queue), node);
	schedule_work(&(detect_mgr.detect_handle_work));
	return HON_OPT_HANDLE_SUCCESS;
}

static void send_detect_packet(void)
{
	struct detect_work_send_packet detect_send;

	if (!is_cloud_network_enable())
		return;

	detect_send.type = DETECT_WORK_SEND_PACKET;
	detect_send.msg_len = sizeof(struct detect_work_send_packet);
	detect_send.paths = get_all_detect_paths();
	struct list_node *node = list_node_alloc(&detect_send, sizeof(struct detect_work_send_packet));
	log_info("send detect path %d", detect_send.paths);

	rtt_gain_show_handle();

	enqueue_list_queue(&(detect_mgr.work_queue), node);
	schedule_work(&(detect_mgr.detect_handle_work));
	return;
}

static enum hrtimer_restart add_send_packet_task(struct hrtimer *timer)
{
	if (!is_cloud_network_enable())
		return HRTIMER_NORESTART;

	if (unlikely(timer == NULL)) {
		log_err("NULL Pointer, error");
		return HRTIMER_NORESTART;
	}
	send_detect_packet();
	hrtimer_forward_now(timer, ms_to_ktime(get_min_detect_interval()));
	return HRTIMER_RESTART;
}

static enum hrtimer_restart rtt_resp_timeout_hrtimer_handler(struct hrtimer *timer)
{
	if (!is_cloud_network_enable())
		return HRTIMER_NORESTART;
	
	if (unlikely(timer == NULL)) {
		log_err("NULL Pointer, error");
		return HRTIMER_NORESTART;
	}
	
	log_info("rtt judge timeout, switch to redundant");
	set_rtt_quality(LINK_DYNAMIC_SLOW);
	return HRTIMER_NORESTART;
}

static void send_packet_hrtimer_start(void)
{
	if (!hrtimer_active(&send_packet_hrtimer))
		hrtimer_start(&send_packet_hrtimer, ms_to_ktime(get_min_detect_interval()), HRTIMER_MODE_REL);
	return;
}

static void rtt_resp_timeout_hrtimer_start(void)
{
	struct link_info link_info_data;
	if (get_link_info(&link_info_data) != SUCCESS) {
		log_err("calc_rtt, get link info error");
		return;
	}
	int timeout_thresh = link_info_data.scene == SCENE_WIFI_MODEM ?
		LINK_DYNAMIC_RTT_TIMEOUT_WIFI : LINK_DYNAMIC_RTT_TIMEOUT_MODEM;

	if (!hrtimer_active(&rtt_resp_timeout_hrtimer))
		hrtimer_start(&rtt_resp_timeout_hrtimer, ms_to_ktime(timeout_thresh),
			HRTIMER_MODE_REL);
	return;
}

void detect_work_send_packet_handle(struct detect_work_send_packet *detect_send)
{
	struct sk_buff *skb = NULL;
	int paths = 0;
	u32 timestamp_send;
	if (unlikely(detect_send == NULL)) {
		log_err("NULL Pointer, error");
		return;
	}
	timestamp_send = get_rel_time_us();
	skb = alloc_detect_skb(timestamp_send);
	if (unlikely(skb == NULL))
		return;
	paths = get_link_path();
	add_path_timestamp_send(paths, timestamp_send);
	skb_send(skb, paths);
	return;
}

void detect_work_rcv_packet_handle(struct detect_work_rcv_packet *detect_recv)
{
	int average_rtt = 0;
	int loss_rate = 0;
	int path_bit;
	bool is_found_rtt;

	if (unlikely(detect_recv == NULL)) {
		log_err("NULL Pointer, error");
		return;
	}
	if (get_compass_check_debug() == 1) {
		log_err("compass check debug set abnormal, trigger handle rtt error");
		return;
	}

	is_found_rtt = update_path_data(detect_recv->path, detect_recv->timestamp_send,
		detect_recv->timestamp_recv);
	if (is_found_rtt && get_main_path() == detect_recv->path) {
		log_info("recv rtt packet, cancel rtt resp timeout timer");
		hrtimer_cancel(&rtt_resp_timeout_hrtimer);
	}

	path_bit = path_val_to_bit(detect_recv->path);

	for (int i = 0; i < DETECT_MODULE_ID_MAX; i++) {
		if (detect_modules[i].module_id == -1)
			continue;

		if ((path_bit & detect_modules[i].paths) && detect_modules[i].detect_fn)
			detect_modules[i].detect_fn(detect_recv->path,
				detect_recv->timestamp_recv - detect_recv->timestamp_send,
				average_rtt, loss_rate);
	}
	return;
}

static void detect_module_start_handle(struct detect_work_start_info *detect_info)
{
	if (unlikely(detect_info == NULL))
		return;

	int module_id = detect_info->module_id;
	if (module_id <= DETECT_MODULE_ID_ERROR || module_id >= DETECT_MODULE_ID_MAX) {
		log_err("module id is invalid");
		return;
	}

	spin_lock_bh(&(detect_modules[module_id].lock));
	if (detect_modules[module_id].module_id == module_id) {
		log_info("this module id has started");
		spin_unlock_bh(&(detect_modules[module_id].lock));
		return;
	}
	detect_modules[module_id].module_id = detect_info->module_id;
	detect_modules[module_id].time_interval = detect_info->time_interval;
	detect_modules[module_id].paths = detect_info->paths;
	detect_modules[module_id].detect_fn = detect_info->detect_fn;
	send_packet_hrtimer_start();
	if (get_tx_rx_state() == TX_RX_STATE_2T2R && !is_redundant_status()) {
		log_info("state is 2T2R and remain single path, start rtt timeout check");
		rtt_resp_timeout_hrtimer_start();
	}
	spin_unlock_bh(&(detect_modules[module_id].lock));
	send_detect_packet();
	return;
}

static void detect_module_stop_handle(struct detect_work_stop_info *detect_info)
{
	if (unlikely(detect_info == NULL))
		return;

	int module_id = detect_info->module_id;
	if (module_id <= DETECT_MODULE_ID_ERROR || module_id >= DETECT_MODULE_ID_MAX) {
		log_err("module id is invalid");
		return;
	}

	spin_lock_bh(&(detect_modules[module_id].lock));
	detect_modules[module_id].module_id = DETECT_MODULE_ID_ERROR;
	detect_modules[module_id].time_interval = 0;
	detect_modules[module_id].paths = 0;
	detect_modules[module_id].detect_fn = NULL;
	if (get_all_detect_paths() == 0)
		hrtimer_cancel(&send_packet_hrtimer);
	spin_unlock_bh(&(detect_modules[module_id].lock));
	return;
}

static void detect_work_handle(struct work_struct *work)
{
	struct list_node *node = NULL;

	if (unlikely(work == NULL)) {
		log_err("work is NULL, error");
		return;
	}

	if (!is_cloud_network_enable())
		return;

	while (list_queue_empty(&(detect_mgr.work_queue)) == 0) {
		node = dequeue_list_queue(&(detect_mgr.work_queue));
		if (node == NULL) {
			log_err("dequeue a null node, error");
			break;
		}
		struct detect_tlv *tlv = (struct detect_tlv *)(node->data);
		switch (tlv->type) {
		case DETECT_WORK_SEND_PACKET:
			detect_work_send_packet_handle((struct detect_work_send_packet *)(node->data));
			break;
		case DETECT_WORK_RCV_PACKET:
			detect_work_rcv_packet_handle((struct detect_work_rcv_packet *)(node->data));
			break;
		case DETECT_WORK_START:
			detect_module_start_handle((struct detect_work_start_info *)(node->data));
			break;
		case DETECT_WORK_STOP:
			detect_module_stop_handle((struct detect_work_stop_info *)(node->data));
			break;
		default:
			log_err("type %u unknown, error", tlv->type);
		}
		list_node_free(node);
		node = NULL;
	}
	return;
}

/* module_id should be defined in cloud_network_detect.h */
void detect_module_start(int module_id, int time_interval, int paths, detect_callback *detect_fn)
{
	struct detect_work_start_info detect_info;

	log_info("module id %d start detect %d", module_id, time_interval);

	if (module_id <= DETECT_MODULE_ID_ERROR || module_id >= DETECT_MODULE_ID_MAX) {
		log_err("module id is invalid");
		return;
	}
	if (paths == 0 || paths > 0b1111) {
		log_err("paths is illegal");
		return;
	}
	struct link_info link_info_data;
	if (get_link_info(&link_info_data) != SUCCESS) {
		log_err("get link info error");
		return;
	}

	if (get_dynamic_param(&(dynamic_rtt_param), link_info_data.scene) != SUCCESS) {
		dynamic_rtt_param.rtt_qoe_num = LINK_DYNAMIC_RTT_CALC_NUM;
		dynamic_rtt_param.slope_thresh = LINK_DYNAMIC_RTT_SLOPE_THRESH;
		dynamic_rtt_param.mean_good_thresh = LINK_DYNAMIC_RTT_MEAN_GOOD_THRESH;
		dynamic_rtt_param.mean_bad_thresh = LINK_DYNAMIC_RTT_MEAN_BAD_THRESH;
	}

	detect_info.type = DETECT_WORK_START;
	detect_info.msg_len = sizeof(struct detect_work_start_info);
	detect_info.module_id = module_id;
	detect_info.time_interval = time_interval;
	detect_info.paths = paths;
	detect_info.detect_fn = detect_fn;
	struct list_node *node = list_node_alloc(&detect_info, sizeof(struct detect_work_start_info));

	enqueue_list_queue(&detect_mgr.work_queue, node);
	schedule_work(&(detect_mgr.detect_handle_work));
	return;
}

void detect_module_stop(int module_id)
{
	struct detect_work_stop_info detect_info;
	log_info("module id %d stop detect", module_id);

	if (module_id <= DETECT_MODULE_ID_ERROR || module_id >= DETECT_MODULE_ID_MAX) {
		log_err("module id is invalid");
		return;
	}

	detect_info.type = DETECT_WORK_STOP;
	detect_info.msg_len = sizeof(struct detect_work_stop_info);
	detect_info.module_id = module_id;
	struct list_node *node = list_node_alloc((void *)(&detect_info), sizeof(struct detect_work_stop_info));
	enqueue_list_queue(&detect_mgr.work_queue, node);
	schedule_work(&(detect_mgr.detect_handle_work));
	return;
}

void cloud_network_detect_reset(void)
{
	log_info("cloud network detect reset");

	cancel_work_sync(&(detect_mgr.detect_handle_work));
	clean_list_queue(&(detect_mgr.work_queue));
	hrtimer_cancel(&send_packet_hrtimer);
	detect_paths_reset();
	return;
}

void cloud_network_detect_exit(void)
{
	log_info("cloud network detect exit");

	cancel_work_sync(&(detect_mgr.detect_handle_work));
	clean_list_queue(&(detect_mgr.work_queue));
	hrtimer_cancel(&send_packet_hrtimer);
	detect_paths_deinit();
	return;
}

int cloud_network_detect_init(void)
{
	log_info("cloud network detect init");

	init_list_queue(&(detect_mgr.work_queue));
	INIT_WORK(&(detect_mgr.detect_handle_work), detect_work_handle);
	hrtimer_init(&send_packet_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	hrtimer_init(&rtt_resp_timeout_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	param_init_status = false;
	set_interval_quality(LINK_DYNAMIC_SLOW);
	set_rtt_quality(LINK_DYNAMIC_SLOW);
	send_packet_hrtimer.function = add_send_packet_task;
	rtt_resp_timeout_hrtimer.function = rtt_resp_timeout_hrtimer_handler;
	for (int i = 0; i < DETECT_MODULE_ID_MAX; i++) {
		detect_modules[i].module_id = DETECT_MODULE_ID_ERROR;
		detect_modules[i].paths = 0;
		detect_modules[i].time_interval = INT_MAX;
		detect_modules[i].detect_fn = NULL;
		spin_lock_init(&detect_modules[i].lock);
	}
	atomic_set(&link_dynamic_status, LINK_DYNAMIC_REDUNDANT);
	detect_paths_init();
	rtt_gain_show_init();
	return SUCCESS;
}
