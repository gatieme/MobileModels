/*
 * cloud_network_param.c
 *
 * cloud network kernel module implementation
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

#include "cloud_network_param.h"
#include <linux/module.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/platform_device.h>
#include <linux/mm.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/sock_diag.h>
#include <linux/skbuff.h>
#include <linux/netlink.h>
#include <linux/moduleparam.h>
#include <net/sock.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <securec.h>
#include <linux/sort.h>
#include <linux/version.h>
#include <linux/io.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/gfp.h>
#include <net/xfrm.h>
#include <linux/jhash.h>
#include <linux/rtnetlink.h>
#include <net/netfilter/nf_conntrack.h>
#include <net/netfilter/nf_conntrack_core.h>
#include <net/netfilter/nf_conntrack_helper.h>
#include <net/netfilter/nf_conntrack_seqadj.h>
#include <net/netfilter/nf_conntrack_zones.h>
#include <net/netfilter/nf_nat.h>
#include <net/netfilter/nf_nat_helper.h>
#include <uapi/linux/netfilter/nf_nat.h>

#include "cloud_network_utils.h"
#include "cloud_network.h"
#include "cloud_network_device.h"
#include "cloud_network_rx.h"
#include "cloud_network_signature.h"
#include "cloud_network_detect.h"
#include "cloud_network_session.h"
#include "cloud_network_tx.h"
#include "cloud_network_packet_match.h"
#include "cloud_network_option.h"
#include "cloud_network_path_rtt.h"

#define COMPASS_NORMAL_IMS_NORMAL 0
#define COMPASS_NORMAL_IMS_ABNORMAL 1
#define COMPASS_ABNORMAL_IMS_NORMAL 2
#define COMPASS_ABNORMAL_IMS_ABNORMAL 3

#define COMPASS_CHANGING_MS 5000

#define EXCEPTION_NO 0
#define EXCEPTION_LEVEL_ONE_CLOUD 1
#define EXCEPTION_LEVEL_TWO_LINK 2

#define IMS_RECEIVE_SEND_NORMAL_CHECK_THRES 250

#define IPV6_MONITOR_UDP_SOCKET_NUM_THRES 2
#define IPV6_MONITOR_TCP_SOCKET_NUM_THRES 1

#define UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST_CHECK_TX_THRES 10
#define UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST_CHECK_TIMER 1000
#define SINGLE_PATH_UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST 120

struct ims_param {
	struct ims_monitor config;
	spinlock_t lock;
	bool status;
	int exception_level[DETECT_PATH_VAL_MAX];
	struct hrtimer upstream_exist_downstream_no_exist_check_timer;
	struct work_struct upstream_exist_downstream_no_exist_check_work;
};

struct compass_check {
	spinlock_t lock;
	struct compass_available_monitor config;
	bool front_app_compass_check_status;
	struct hrtimer front_app_compass_check_timer;
	struct work_struct front_app_compass_check_work;
	struct hrtimer unavailable_status_compass_check_timer;
	struct work_struct unavailable_status_compass_check_work;
	struct hrtimer data_flow_compass_check_timer;
	struct work_struct data_flow_compass_check_work;
	struct hrtimer detect_timer;
	struct work_struct detect_timeout_work;
	atomic_t detect_exception_level;
};

struct sock_node {
	struct list_head list;
	struct sock *sk;
};

struct ipv6_monitor_info {
	atomic_t uid;
	struct hrtimer ipv6_monitor_timer;
	struct work_struct ipv6_monitor_timeout_work;
};

static atomic_t compass_available;

enum {
	DETECT_TIMEOUT = 0,
	CHECK_TIMEOUT = 1,
	FAST_CHECK_TIMEOUT = 2,
};

struct ims_param ims_mgr;
static struct compass_check check_mgr;
static atomic_t compass_available; /* compass_check judgment */

static atomic_t compass_status; /* ims and compass_check Judge together */

static atomic_t inited = ATOMIC_INIT(0);
static struct config_param *cfg = NULL; /* cloud network config param */
static struct status_param *status = NULL; /* cloud network status */
struct ipv6_monitor_info ipv6_monitor_data;
static atomic_t is_screen_on; /* 1 ：on, 0 : off */
static atomic_t is_app_front; /* 1 : app is front, 0 ：app is backgrond */
static void detect_stop(void);
static void compass_status_judgment(s64 current_timestamp);
static struct app_node *app_collect_search(const u32 uid);
static int get_ims_exception_level(void);
static void try_to_start_data_flow_compass_check(void);
static void try_to_stop_data_flow_compass_check(void);
static void try_to_start_front_app_compass_check(void);
static void try_to_stop_front_app_compass_check(void);

bool cloud_network_inet6_block_handle(struct socket *sock)
{
	kuid_t uid;
	bool ret = false;
	struct app_node *entry = NULL;

	if (sock == NULL)
		return false;

	uid = SOCK_INODE(sock)->i_uid;

	log_info("uid %u", uid.val);
	if (uid.val == 0)
		return false;

	read_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(uid.val);
	if (entry)
		ret = true;
	read_unlock_bh(&(cfg->app_collect_lock));
	return ret;
}

void cloud_network_inet6_create_handle(struct sock *sk)
{
	struct app_node *entry = NULL;
	struct sock_node *node = NULL;

	if (sk == NULL || sk->sk_family != PF_INET6)
		return;

	if (!is_cloud_network_enable() || (atomic_read(&(ipv6_monitor_data.uid)) != sk->sk_uid.val))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(sk->sk_uid.val);
	if (entry) {
		node = kmalloc(sizeof(struct sock_node), GFP_ATOMIC);
		if (node) {
			node->sk = sk;
			if (sk->sk_type == SOCK_DGRAM) {
				list_add(&node->list, &(entry->ipv6_udp_sock));
				entry->ipv6_udp_sock_cnt++;
			} else if (sk->sk_type == SOCK_STREAM) {
				list_add(&node->list, &(entry->ipv6_tcp_sock));
				entry->ipv6_tcp_sock_cnt++;
			} else {
				kfree(node);
			}
			if (entry->ipv6_udp_sock_cnt > entry->ipv6_udp_sock_cnt_max)
				entry->ipv6_udp_sock_cnt_max = entry->ipv6_udp_sock_cnt;
			else if (entry->ipv6_tcp_sock_cnt > entry->ipv6_tcp_sock_cnt_max)
				entry->ipv6_tcp_sock_cnt_max = entry->ipv6_tcp_sock_cnt;
			log_info("uid %u ipv6_udp_sock_cnt %u ipv6_tcp_sock_cnt %u ipv6_udp_sock_cnt_max %u ipv6_tcp_sock_cnt_max %u",
				entry->app.uid, entry->ipv6_udp_sock_cnt, entry->ipv6_tcp_sock_cnt, entry->ipv6_udp_sock_cnt_max,
				entry->ipv6_tcp_sock_cnt_max);
		}
	}
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}

static void cloud_network_inet6_release(struct app_node *entry, struct sock *sk)
{
	struct sock_node *node = NULL;
	struct sock_node *tmp = NULL;

	if (entry == NULL || sk == NULL)
		return;

	if (sk->sk_type == SOCK_DGRAM) {
		list_for_each_entry_safe(node, tmp, &(entry->ipv6_udp_sock), list) {
			if (node->sk == sk) {
				list_del(&(node->list));
				kfree(node);
				entry->ipv6_udp_sock_cnt--;
			}
		}
	} else if (sk->sk_type == SOCK_STREAM) {
		list_for_each_entry_safe(node, tmp, &(entry->ipv6_tcp_sock), list) {
			if (node->sk == sk) {
				list_del(&(node->list));
				kfree(node);
				entry->ipv6_tcp_sock_cnt--;
			}
		}
	}
	return;
}

void cloud_network_inet6_release_handle(struct sock *sk)
{
	struct app_node *entry = NULL;
	struct sock_node *node = NULL;
	struct sock_node *tmp = NULL;

	if (sk == NULL || sk->sk_family != PF_INET6)
		return;

	if (!is_cloud_network_enable() || (atomic_read(&(ipv6_monitor_data.uid)) != sk->sk_uid.val))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(sk->sk_uid.val);
	if (entry) {
		cloud_network_inet6_release(entry, sk);
		log_info("uid %u ipv6_udp_sock_cnt %u ipv6_tcp_sock_cnt %u ipv6_udp_sock_cnt_max %u ipv6_tcp_sock_cnt_max %u",
			entry->app.uid, entry->ipv6_udp_sock_cnt, entry->ipv6_tcp_sock_cnt, entry->ipv6_udp_sock_cnt_max,
			entry->ipv6_tcp_sock_cnt_max);
	}
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}

static void cloud_network_inet6_sock_destroy(const u32 uid)
{
	struct app_node *entry = NULL;
	struct sock_node *node = NULL;
	struct sock_node *tmp = NULL;

	if (!is_cloud_network_enable())
		return;

	log_info("sk_uid %u", uid);
	write_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(uid);
	if (entry) {
		list_for_each_entry_safe(node, tmp, &(entry->ipv6_udp_sock), list) {
			if (!IS_ERR(node->sk)) {
				sock_diag_destroy(node->sk, ECONNABORTED);
				sock_put(node->sk);
				list_del(&(node->list));
				kfree(node);
				entry->ipv6_udp_sock_cnt--;
			}
		}
		list_for_each_entry_safe(node, tmp, &(entry->ipv6_tcp_sock), list) {
			if (!IS_ERR(node->sk)) {
				sock_diag_destroy(node->sk, ECONNABORTED);
				sock_put(node->sk);
				list_del(&(node->list));
				kfree(node);
				entry->ipv6_tcp_sock_cnt--;
			}
		}
		log_info("uid %u ipv6_udp_sock_cnt %u ipv6_tcp_sock_cnt %u ipv6_udp_sock_cnt_max %u ipv6_tcp_sock_cnt_max %u",
			entry->app.uid, entry->ipv6_udp_sock_cnt, entry->ipv6_tcp_sock_cnt, entry->ipv6_udp_sock_cnt_max,
			entry->ipv6_tcp_sock_cnt_max);
	}
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}

static void cloud_network_inet6_sock_clear(struct app_node *entry)
{
	struct sock_node *node = NULL;
	struct sock_node *tmp = NULL;

	if (entry) {
		list_for_each_entry_safe(node, tmp, &(entry->ipv6_udp_sock), list) {
			if (!IS_ERR(node->sk)) {
				list_del(&(node->list));
				kfree(node);
				entry->ipv6_udp_sock_cnt--;
			}
		}
		list_for_each_entry_safe(node, tmp, &(entry->ipv6_tcp_sock), list) {
			if (!IS_ERR(node->sk)) {
				list_del(&(node->list));
				kfree(node);
				entry->ipv6_tcp_sock_cnt--;
			}
		}
		log_info("uid %u ipv6_udp_sock_cnt %u ipv6_tcp_sock_cnt %u ipv6_udp_sock_cnt_max %u ipv6_tcp_sock_cnt_max %u",
			entry->app.uid, entry->ipv6_udp_sock_cnt, entry->ipv6_tcp_sock_cnt, entry->ipv6_udp_sock_cnt_max,
			entry->ipv6_tcp_sock_cnt_max);
		entry->ipv6_udp_sock_cnt = 0;
		entry->ipv6_udp_sock_cnt_max = 0;
		entry->ipv6_tcp_sock_cnt = 0;
		entry->ipv6_tcp_sock_cnt_max = 0;
	}
	return;
}

static void cloud_network_inet6_sock_clear_all(void)
{
	struct app_node *pos = NULL;
	struct app_node *n = NULL;

	if (unlikely(cfg == NULL))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	rbtree_postorder_for_each_entry_safe(pos, n, &(cfg->app_collect), app_rb_node) {
		log_info("inet6 sock clear app uid %u", pos->app.uid);
		cloud_network_inet6_sock_clear(pos);
	}
	write_unlock_bh(&(cfg->app_collect_lock));

	return;
}

static void ipv6_monitor_result_report(u32 data_report)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_ipv6_monitor_result *msg_rept = NULL;

	log_info("event report ipv6 monitor result %u", data_report);

	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ipv6_monitor_result), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return;
	}

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ipv6_monitor_result);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = IPV6_MONITOR_RESULT;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ipv6_monitor_result);

	msg_rept = (struct rept_ipv6_monitor_result *)(msg_header->data);
	msg_rept->result = data_report;
	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return;
}

static void ipv6_monitor_timeout_work_handle(struct work_struct *work)
{
	struct app_node *entry = NULL;
	u32 ipv6_status = 0;

	log_info("ipv6 monitor timer handle uid %d", atomic_read(&(ipv6_monitor_data.uid)));
	if (!is_cloud_network_enable())
		return;
	
	read_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(atomic_read(&(ipv6_monitor_data.uid)));
	log_info("uid %u ipv6_udp_sock_cnt %u ipv6_tcp_sock_cnt %u ipv6_udp_sock_cnt_max %u ipv6_tcp_sock_cnt_max %u",
		entry->app.uid, entry->ipv6_udp_sock_cnt, entry->ipv6_tcp_sock_cnt, entry->ipv6_udp_sock_cnt_max,
		entry->ipv6_tcp_sock_cnt_max);
	if (entry && (entry->ipv6_udp_sock_cnt_max >= IPV6_MONITOR_UDP_SOCKET_NUM_THRES) &&
		(entry->ipv6_tcp_sock_cnt_max >= IPV6_MONITOR_TCP_SOCKET_NUM_THRES))
		ipv6_status = 1;
	read_unlock_bh(&(cfg->app_collect_lock));
	atomic_set(&(ipv6_monitor_data.uid), 0);
	ipv6_monitor_result_report(ipv6_status);
	cloud_network_inet6_sock_clear_all();
	return;
}

static enum hrtimer_restart ipv6_monitor_timeout(struct hrtimer *timer)
{
	if (is_cloud_network_enable())
		schedule_work(&(ipv6_monitor_data.ipv6_monitor_timeout_work));
	return HRTIMER_NORESTART;
}

static void cloud_network_ipv6_init(void)
{
	atomic_set(&(ipv6_monitor_data.uid), 0);
	INIT_WORK(&(ipv6_monitor_data.ipv6_monitor_timeout_work), ipv6_monitor_timeout_work_handle);
	hrtimer_init(&ipv6_monitor_data.ipv6_monitor_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	ipv6_monitor_data.ipv6_monitor_timer.function = ipv6_monitor_timeout;
	return;
}

void set_compass_available(void)
{
	log_info("set compass ip is available");
	atomic_set(&compass_available, 1);
}

void set_compass_unavailable(void)
{
	log_info("set compass ip is unavailable");
	atomic_set(&compass_available, 0);
}

bool is_compass_available(void)
{
	return (atomic_read(&compass_available) != 0);
}

void set_data_flow_status_start(void)
{
	log_info("set data flow status started");
	atomic_set(&status->started, 1);
}

void set_data_flow_status_stop(void)
{
	log_info("set data flow status stoped");
	atomic_set(&status->started, 0);
}

bool get_data_flow_status(void)
{
	return (atomic_read(&status->started) != 0);
}

static bool is_compare_config_changed(void)
{
	bool ret;
	read_lock_bh(&(cfg->cfg_lock));
	ret = (cfg->compass.compass_ip != cfg->last_compass.compass_ip) ||
		(cfg->compass.compass_port != cfg->last_compass.compass_port);
	read_unlock_bh(&(cfg->cfg_lock));
	return ret;
}

static int backup_config_info(void)
{
	errno_t s_ret = EOK;

	if (unlikely(cfg == NULL))
		return ERROR;

	write_lock_bh(&(cfg->cfg_lock));
	log_info("set last ip");

	s_ret = memcpy_s(&(cfg->last_compass), sizeof(struct compass_info),
		&(cfg->compass), sizeof(struct compass_info));
	if (unlikely(s_ret != EOK))
		log_err("memcpy_s failed, error");
	write_unlock_bh(&(cfg->cfg_lock));

	return SUCCESS;
}

static int reset_last_config_info(void)
{
	if (unlikely(cfg == NULL))
		return ERROR;
	
	write_lock_bh(&(cfg->cfg_lock));
	(void)memset_s(&(cfg->last_compass), sizeof(struct compass_info), 0x00,
		sizeof(struct compass_info));
	write_unlock_bh(&(cfg->cfg_lock));

	return SUCCESS;
}

static int config_compass_infor(const struct compass_info *compass)
{
	errno_t s_ret = EOK;

	if (unlikely(cfg == NULL || compass == NULL))
		return ERROR;

	log_info("client id %02X %02X %02X %02X %02X %02X %02X %02X", compass->client_id[0],
		compass->client_id[1], compass->client_id[2], compass->client_id[3],
		compass->client_id[4], compass->client_id[5], compass->client_id[6], compass->client_id[7]);
	log_info("app id %02X %02X %02X", compass->app_id[0], compass->app_id[1],
		compass->app_id[2]);

	write_lock_bh(&(cfg->cfg_lock));

	s_ret = memcpy_s(&(cfg->compass), sizeof(struct compass_info), compass,
		sizeof(struct compass_info));

	write_unlock_bh(&(cfg->cfg_lock));
	if (unlikely(s_ret != EOK))
		return ERROR;

	if ((cfg->last_compass.compass_ip != 0) && is_compare_config_changed()) {
		all_session_next_window_reset();
		change_receive_window();
	}

	return SUCCESS;
}

static int config_key_infor(const struct key_info *key)
{
	errno_t s_ret = EOK;

	if (unlikely(cfg == NULL || key == NULL))
		return ERROR;

	log_info("hmac id %d", key->hmac_id);

	write_lock_bh(&(cfg->cfg_lock));
	s_ret = memcpy_s(&(cfg->key), sizeof(struct key_info), key,
		sizeof(struct key_info));
	write_unlock_bh(&(cfg->cfg_lock));
	if (unlikely(s_ret != EOK))
		return ERROR;

	return SUCCESS;
}

static int config_dynamic_param(const struct dynamic_param *dynamic)
{
	errno_t s_ret = EOK;

	if (unlikely(cfg == NULL || dynamic == NULL))
		return ERROR;

	log_info("dynamic link param have been configured");

	write_lock_bh(&(cfg->cfg_lock));
	s_ret = memcpy_s(&(cfg->dynamic), sizeof(struct dynamic_param), dynamic,
		sizeof(struct dynamic_param));
	write_unlock_bh(&(cfg->cfg_lock));
	if (unlikely(s_ret != EOK))
		return ERROR;

	return SUCCESS;
}

static int config_link_infor(const struct link_info *link)
{
	errno_t s_ret = EOK;

	if (unlikely(cfg == NULL || link == NULL))
		return ERROR;

	log_info("pri_modem %02X sec_modem %02X pri_wifi %02X scene %02X rtt_gain_show_report_interval %d "
		"rtt_gain_show_calc_num %d", link->pri_modem_permit, link->sec_modem_permit, link->pri_wifi_permit,
		link->scene, link->rtt_gain_show_report_interval, link->rtt_gain_show_calc_num);

	if (link->scene == SCENE_WIFI_MODEM)
		change_wifi_channel_qoe_status(link->wifi_status == 0 ?
										LINK_DYNAMIC_SLOW : LINK_DYNAMIC_NORMAL);
	else
		change_modem_channel_qoe_status(link->modem_status == 0 ?
										LINK_DYNAMIC_SLOW : LINK_DYNAMIC_NORMAL);

	write_lock_bh(&(cfg->cfg_lock));
	s_ret = memcpy_s(&(cfg->link), sizeof(struct link_info), link, sizeof(struct link_info));
	write_unlock_bh(&(cfg->cfg_lock));
	if (unlikely(s_ret != EOK))
		return ERROR;

	return SUCCESS;
}

static struct app_node *app_collect_search(const u32 uid)
{
	struct rb_node *node = NULL;

	if (unlikely(cfg == NULL))
		return NULL;

	node = cfg->app_collect.rb_node;
	while (node != NULL) {
		struct app_node *data = rb_entry(node, struct app_node,
			app_rb_node);
		if (uid < data->app.uid)
			node = node->rb_left;
		else if (uid > data->app.uid)
			node = node->rb_right;
		else
			return data;
	}
	return NULL;
}

static void set_app_collect_state(const u32 uid, int state)
{
	struct app_node *entry = NULL;

	if (unlikely(cfg == NULL))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(uid);
	if (entry != NULL) {
		log_info("uid %u state %d to %d", uid, entry->state, state);
		entry->state = state;
	} else {
		log_err("uid %u is not in list");
	}
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}

static void app_collect_delete(const u32 uid)
{
	struct app_node *entry = NULL;

	if (unlikely(cfg == NULL))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(uid);
	if (entry != NULL) {
		rb_erase(&entry->app_rb_node, &(cfg->app_collect));
		kfree(entry);
	}
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}

static void app_collect_insert(struct app_node *data)
{
	struct rb_node **insert = NULL;
	struct rb_node *parent = NULL;

	if (unlikely(data == NULL || cfg == NULL))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	insert = &(cfg->app_collect.rb_node);
	while (*insert != NULL) {
		struct app_node *this = rb_entry(*insert, struct app_node,
			app_rb_node);
		parent = *insert;
		if (data->app.uid < this->app.uid) {
			insert = &((*insert)->rb_left);
		} else if (data->app.uid > this->app.uid) {
			insert = &((*insert)->rb_right);
		} else {
			write_unlock_bh(&(cfg->app_collect_lock));
			log_err("uid %d has already inserted, error", data->app.uid);
			return;
		}
	}
	rb_link_node(&data->app_rb_node, parent, insert);
	log_info("app collect insert uid %d", data->app.uid);
	rb_insert_color(&data->app_rb_node, &(cfg->app_collect));
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}

static void app_collect_clear(void)
{
	struct rb_node *node = NULL;
	struct app_node *data = NULL;

	if (unlikely(cfg == NULL))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	while (node = rb_first(&(cfg->app_collect))) {
		data = rb_entry(node, struct app_node, app_rb_node);
		log_info("erase app uid %u", data->app.uid);
		cloud_network_inet6_sock_clear(data);
		rb_erase(&data->app_rb_node, &(cfg->app_collect));
		kfree(data);
	}
	cfg->app_collect = RB_ROOT;
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}

static int config_app_collect_infor(const struct app_collect *app)
{
	errno_t s_ret = EOK;
	u32 app_num = 0;
	struct app_info *app_entry = NULL;
	struct app_node *app_insert = NULL;

	if (unlikely(app == NULL || cfg == NULL))
		return ERROR;

	app_collect_clear();
	app_num = app->data_len / sizeof(struct app_info);
	if (app_num == 0)
		return SUCCESS;

	for (int i = 0; i < app_num; i++) {
		app_entry = (struct app_info *)(app->data + sizeof(struct app_info) * i);
		if (app_entry->uid < 0)
			continue;
		app_insert = kzalloc(sizeof(struct app_node), GFP_ATOMIC);
		if (app_insert == NULL) {
			log_err("alloc app_entry fail");
			return ERROR;
		}
		s_ret = memcpy_s(&(app_insert->app), sizeof(struct app_info), app_entry,
			sizeof(struct app_info));
		if (s_ret != EOK)
			return ERROR;
		app_insert->state = 1;
		INIT_LIST_HEAD(&(app_insert->ipv6_udp_sock));
		INIT_LIST_HEAD(&(app_insert->ipv6_tcp_sock));
		app_insert->ipv6_udp_sock_cnt = 0;
		app_insert->ipv6_udp_sock_cnt_max = 0;
		app_insert->ipv6_tcp_sock_cnt = 0;
		app_insert->ipv6_tcp_sock_cnt_max = 0;
		(void)memset_s(app_insert->tx_packet_cnt, sizeof(app_insert->tx_packet_cnt), 0x00,
			sizeof(app_insert->tx_packet_cnt));
		(void)memset_s(app_insert->rx_packet_cnt, sizeof(app_insert->rx_packet_cnt), 0x00,
			sizeof(app_insert->rx_packet_cnt));
		(void)memset_s(app_insert->upstream_exist_downstream_no_exist_cnt,
			sizeof(app_insert->upstream_exist_downstream_no_exist_cnt), 0x00,
			sizeof(app_insert->upstream_exist_downstream_no_exist_cnt));
		app_collect_insert(app_insert);
	}
	return SUCCESS;
}

int cloud_network_data_prosess_init(void)
{
	int ret = ERROR;
	struct hw_cloud_network_ops ops;

	ret = cloud_network_rx_init();
	ops.rx_handle = cloud_network_rx;
	ops.tx_handle = cloud_network_tx;
	ret += cloud_network_op_register(&ops);
	return ret;
}

void cloud_network_data_prosess_deinit(void)
{
	cloud_network_op_unregister();
	cloud_network_data_rx_exit();
	return;
}

void netlink_cmd_cloud_param_key_handle(const struct netlink_msg_head *msg)
{
	struct recv_cloud_param_key *data = NULL;

	if (unlikely(msg == NULL))
		return;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_cloud_param_key))
		|| msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	data = (struct recv_cloud_param_key *)(msg->data);
	if (config_key_infor(&(data->key)) != SUCCESS) {
		log_err("config key infor error");
		return;
	}
	cloud_network_set_key(cfg->key.hmac_key, SIGN_KEY_LEN, cfg->key.hmac_id);
	return;
}

void netlink_cmd_cloud_param_compass_handle(const struct netlink_msg_head *msg)
{
	struct recv_cloud_param_compass *data = NULL;

	if (unlikely(msg == NULL))
		return;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_cloud_param_compass))
		|| msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	data = (struct recv_cloud_param_compass *)(msg->data);
	if (backup_config_info() != SUCCESS)
		log_err("backup config compass infor error");

	if (config_compass_infor(&(data->compass)) != SUCCESS) {
		log_err("config compass infor error");
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		return;
	}
	set_compass_available();
	compass_check_once();
	return;
}

void netlink_cmd_cloud_param_app_handle(const struct netlink_msg_head *msg)
{
	struct recv_cloud_param_app *data = NULL;

	if (unlikely(msg == NULL))
		return;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_cloud_param_app))
		|| msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	data = (struct recv_cloud_param_app *)(msg->data);
	if (config_app_collect_infor(&(data->app)) != SUCCESS) {
		log_err("config app collect infor error");
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		return;
	}
	return;
}

void netlink_cmd_cloud_param_link_handle(const struct netlink_msg_head *msg)
{
	struct recv_cloud_param_link *data = NULL;

	if (unlikely(msg == NULL))
		return;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_cloud_param_link))
		|| msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	data = (struct recv_cloud_param_link *)(msg->data);
	if (config_link_infor(&(data->link)) != SUCCESS) {
		log_err("config link infor error");
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		return;
	}
	return;
}

void netlink_cmd_cloud_ims_monitor_start_handle(const struct netlink_msg_head *msg)
{
	struct recv_ims_monitor_start *data = NULL;

	if (unlikely(msg == NULL))
		return;

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has no inited, ignore this cmd");
		return;
	}

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_ims_monitor_start))
		|| msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	data = (struct recv_ims_monitor_start *)(msg->data);
	spin_lock_bh(&ims_mgr.lock);
	log_info("uid %d exception_timeout_link %d exception_timeout_cloud %d", data->ims_monitor_param.uid,
		data->ims_monitor_param.exception_timeout_link, data->ims_monitor_param.exception_timeout_cloud);
	ims_mgr.config.uid = data->ims_monitor_param.uid;
	ims_mgr.config.exception_timeout_link = data->ims_monitor_param.exception_timeout_link;
	ims_mgr.config.exception_timeout_cloud = data->ims_monitor_param.exception_timeout_cloud;

	(void)memset_s(ims_mgr.exception_level, sizeof(ims_mgr.exception_level), EXCEPTION_NO,
		sizeof(ims_mgr.exception_level));
	ims_mgr.status = true;
	spin_unlock_bh(&ims_mgr.lock);
	atomic_set(&compass_status, COMPASS_NORMAL_IMS_NORMAL);
	start_gain_detection();
	if (ims_mgr.status && !hrtimer_active(&ims_mgr.upstream_exist_downstream_no_exist_check_timer))
		hrtimer_start(&ims_mgr.upstream_exist_downstream_no_exist_check_timer,
			ms_to_ktime(UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST_CHECK_TIMER), HRTIMER_MODE_REL);
	try_to_start_data_flow_compass_check();
	return;
}

void netlink_cmd_cloud_ims_monitor_stop_handle(const struct netlink_msg_head *msg)
{
	if (unlikely(msg == NULL))
		return;

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has no inited, ignore this cmd");
		return;
	}
	cancel_work_sync(&(ims_mgr.upstream_exist_downstream_no_exist_check_work));
	hrtimer_cancel(&ims_mgr.upstream_exist_downstream_no_exist_check_timer);
	spin_lock_bh(&ims_mgr.lock);
	ims_mgr.status = false;
	(void)memset_s(ims_mgr.exception_level, sizeof(ims_mgr.exception_level), EXCEPTION_NO,
		sizeof(ims_mgr.exception_level));
	spin_unlock_bh(&ims_mgr.lock);
	atomic_set(&compass_status, COMPASS_NORMAL_IMS_NORMAL);
	stop_gain_detection();
	try_to_stop_data_flow_compass_check();
}

void netlink_cmd_cloud_compass_monitor_start_handle(const struct netlink_msg_head *msg)
{
	errno_t s_ret = EOK;
	struct recv_compass_available_monitor_start *data = NULL;

	if (unlikely(msg == NULL))
		return;

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has no inited, ignore this cmd");
		return;
	}

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_compass_available_monitor_start))
		|| msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	data = (struct recv_compass_available_monitor_start *)(msg->data);
	spin_lock_bh(&check_mgr.lock);
	s_ret = memcpy_s(&(check_mgr.config),
		sizeof(struct compass_available_monitor), data,
		sizeof(struct compass_available_monitor));
	if (s_ret != EOK) {
		log_err("memcpy_s failed");
		spin_unlock_bh(&check_mgr.lock);
		return;
	}
	atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_NO);
	log_info("comfig param %u %u %u %u %u %u %u", check_mgr.config.poll_timeout,
		check_mgr.config.detect_interval, check_mgr.config.exception_timeout_link,
		check_mgr.config.detect_interval, check_mgr.config.exception_timeout_cloud,
		check_mgr.config.exception_poll_timeout,
		check_mgr.config.data_poll_timeout);
	spin_unlock_bh(&check_mgr.lock);
	atomic_set(&compass_status, COMPASS_NORMAL_IMS_NORMAL);
	atomic_set(&is_app_front, 1);
	try_to_start_front_app_compass_check();
}

void netlink_cmd_cloud_compass_monitor_stop_handle(const struct netlink_msg_head *msg)
{
	if (unlikely(msg == NULL))
		return;

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has not inited, ignore this cmd");
		return;
	}
	atomic_set(&is_app_front, 0);
	try_to_stop_front_app_compass_check();
}

void netlink_cmd_deinit_param_handle(const struct netlink_msg_head *msg)
{
	if (unlikely(msg == NULL ||
		atomic_read(&inited) == CLOUD_NETWORK_DEINIED ||
		atomic_read(&(cfg->enable)) == CONFIG_DISABLE))
		return;

	atomic_set(&(cfg->enable), CONFIG_DISABLE);
	cloud_network_data_prosess_deinit();

	set_tx_rx_state(TX_RX_STATE_2T2R);
	front_app_compass_check_stop();
	cancel_work_sync(&(ims_mgr.upstream_exist_downstream_no_exist_check_work));
	hrtimer_cancel(&ims_mgr.upstream_exist_downstream_no_exist_check_timer);
	spin_lock_bh(&ims_mgr.lock);
	ims_mgr.status = false;
	(void)memset_s(ims_mgr.exception_level, sizeof(ims_mgr.exception_level), EXCEPTION_NO,
		sizeof(ims_mgr.exception_level));
	spin_unlock_bh(&ims_mgr.lock);

	write_lock_bh(&(cfg->cfg_lock));
	(void)memset_s(&(cfg->compass), sizeof(struct compass_info), 0x00,
		sizeof(struct compass_info));
	(void)memset_s(&(cfg->key), sizeof(struct key_info), 0x00,
		sizeof(struct key_info));
	(void)memset_s(&(cfg->link), sizeof(struct link_info), 0x00,
		sizeof(struct link_info));
	write_unlock_bh(&(cfg->cfg_lock));

	app_collect_clear();
	cloud_network_option_stop();
	cloud_network_session_reset();
	cloud_network_detect_reset();
	ims_check_exit();
	compass_check_exit();
	cloud_network_sign_deinit();
	stop_path_rtt_module();
	return;
}

int netlink_cmd_init_param_handle(const struct netlink_msg_head *msg)
{
	struct recv_init *init_data = NULL;
	int ret = ERROR;

	if (unlikely(msg == NULL || atomic_read(&inited) == CLOUD_NETWORK_DEINIED))
		return ERROR;

	if (likely(atomic_read(&(cfg->enable)) != CONFIG_DISABLE)) {
		log_err("cloud network has inited, ignore this init param");
		return SUCCESS;
	}

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_init)) || msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return ERROR;
	}

	init_data = (struct recv_init *)(msg->data);
	if (reset_last_config_info() != SUCCESS)
		log_err("reset config last compass infor error");

	if (config_compass_infor(&(init_data->compass)) != SUCCESS) {
		log_err("config compass infor error");
		return ERROR;
	}
	if (config_key_infor(&(init_data->key)) != SUCCESS) {
		log_err("config key infor error");
		return ERROR;
	}
	if (config_link_infor(&(init_data->link)) != SUCCESS) {
		log_err("config link infor error");
		return ERROR;
	}
	if (config_dynamic_param(&(init_data->dynamic)) != SUCCESS) {
		log_err("config dynamic param error");
		return ERROR;
	}
	if (config_app_collect_infor(&(init_data->app)) != SUCCESS) {
		log_err("config app collect infor error");
		return ERROR;
	}
	set_tx_rx_state(TX_RX_STATE_2T2R);

	ret = ims_check_init();
	ret += compass_check_init();
	send_reset_option();
	cloud_network_sign_init();
	cloud_network_set_key(cfg->key.hmac_key, SIGN_KEY_LEN, cfg->key.hmac_id);
	ret += cloud_network_data_prosess_init();
	atomic_set(&(cfg->enable), CONFIG_ENABLE);
	compass_check_once();
	start_path_rtt_module();
	return ret;
}

int netlink_cmd_startacc_param_handle(const struct netlink_msg_head *msg)
{
	struct recv_startacc *data = NULL;

	if (unlikely(msg == NULL))
		return ERROR;
	
	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_startacc)) ||
		msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return ERROR;
	}

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has no inited, ignore this cmd");
		return ERROR;
	}

	set_rtt_quality(LINK_DYNAMIC_SLOW);
	set_interval_quality(LINK_DYNAMIC_SLOW);

	data = (struct recv_startacc *)(msg->data);
	if (config_dynamic_param(&(data->param)) != SUCCESS) {
		log_err("config dynamic param error");
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		return ERROR;
	}
	return SUCCESS;
}

int netlink_cmd_stopacc_param_handle(const struct netlink_msg_head *msg)
{
	struct recv_stopacc *data = NULL;

	if (unlikely(msg == NULL))
		return ERROR;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_stopacc)) ||
		msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return ERROR;
	}

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has no inited, ignore this cmd");
		return ERROR;
	}

	return SUCCESS;
}

void netlink_cmd_ipv6_monitor_param_handle(const struct netlink_msg_head *msg)
{
	struct recv_ipv6_monitor *data = NULL;

	if (unlikely(msg == NULL))
		return;
	
	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_ipv6_monitor)) ||
		msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has no inited, ignore this cmd");
		return;
	}

	data = (struct recv_ipv6_monitor *)(msg->data);
	log_info("ipv6 monitor uid %u", data->uid);
	atomic_set(&(ipv6_monitor_data.uid), data->uid);
	if (!hrtimer_active(&(ipv6_monitor_data.ipv6_monitor_timer)))
		hrtimer_start(&(ipv6_monitor_data.ipv6_monitor_timer),
			ms_to_ktime(3000), HRTIMER_MODE_REL);

	return;
}

void netlink_cmd_tx_rx_ctl_handle(const struct netlink_msg_head *msg)
{
	struct recv_tx_rx_ctl *tx_rx_ctl = NULL;

	if (unlikely(msg == NULL))
		return;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_tx_rx_ctl)) ||
		msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	tx_rx_ctl = (struct recv_tx_rx_ctl *)(msg->data);
	log_info("TX_RX control state %d", tx_rx_ctl->tx_rx.state);
	if (tx_rx_ctl->tx_rx.state == TX_RX_STATE_2T2R)
		start_gain_detection();
	else
		stop_gain_detection();

	set_tx_rx_state(tx_rx_ctl->tx_rx.state);
	return;
}

void netlink_cmd_cloud_param_all_handle(const struct netlink_msg_head *msg)
{
	struct recv_cloud_param_all *data = NULL;

	if (unlikely(msg == NULL))
		return;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_cloud_param_all)) ||
		msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return;
	}

	data = (struct recv_cloud_param_all *)(msg->data);

	if (backup_config_info() != SUCCESS)
		log_err("backup config compass infor error");

	if (config_compass_infor(&(data->compass)) != SUCCESS) {
		log_err("config compass infor error");
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		return;
	}
	if (config_key_infor(&(data->key)) != SUCCESS) {
		log_err("config key infor error");
		return;
	}
	if (config_dynamic_param(&(data->dynamic)) != SUCCESS) {
		log_err("config dynamic info error");
		return;
	}
	if (config_app_collect_infor(&(data->app)) != SUCCESS) {
		log_err("config app collect infor error");
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		return;
	}

	set_compass_available();
	cloud_network_set_key(cfg->key.hmac_key, SIGN_KEY_LEN, cfg->key.hmac_id);
	compass_check_once();
	return;
}

int netlink_cmd_qos_get_handle(const struct netlink_msg_head *msg, struct rept_qos *msg_rept)
{
	struct recv_qos_get *data = NULL;

	if (unlikely(msg == NULL))
		return ERROR;
	
	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_qos_get)) ||
		msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return ERROR;
	}

	if (unlikely(atomic_read(&(cfg->enable)) == CONFIG_DISABLE)) {
		log_err("cloud network has no inited, ignore this cmd");
		return ERROR;
	}

	data = (struct recv_qos_get *)(msg->data);

	if (data->range <= 0)
		return ERROR;

	calculate_rtt_qos(DETECT_PATH_VAL_WIFI_1, data->range,
					&msg_rept->wifi_avg, &msg_rept->wifi_stand);
	calculate_rtt_qos(DETECT_PATH_VAL_MODEM_1, data->range,
					&msg_rept->pri_modemem_avg, &msg_rept->pri_modemem_stand);
	calculate_rtt_qos(DETECT_PATH_VAL_MODEM_2, data->range,
					&msg_rept->sec_modemem_avg, &msg_rept->sec_modemem_stand);
	return SUCCESS;
}

int netlink_cmd_screen_state_handle(const struct netlink_msg_head *msg)
{
	struct recv_screen_state *data = NULL;

	if (unlikely(msg == NULL))
		return ERROR;

	if (msg->data_len < (sizeof(struct netlink_msg_head)
		+ sizeof(struct recv_screen_state)) ||
		msg->data_len > NETLINK_DATA_MSG_LEN) {
		log_err("msg length error");
		return ERROR;
	}

	data = (struct recv_screen_state *)(msg->data);
	atomic_set(&is_screen_on, data->screen_state);
	if (atomic_read(&is_screen_on) == 1) {
		try_to_start_data_flow_compass_check();
		try_to_start_front_app_compass_check();
	} else if (atomic_read(&is_screen_on) == 0) {
		try_to_stop_data_flow_compass_check();
		try_to_stop_front_app_compass_check();
	}

	log_info("netlink cmd screen state %u", atomic_read(&is_screen_on));
	return SUCCESS;
}

int skb_uid_match(u32 uid)
{
	struct app_node *entry = NULL;
	bool ret = false;

	if (atomic_read(&inited) == CLOUD_NETWORK_DEINIED ||
		atomic_read(&(cfg->enable)) == CONFIG_DISABLE)
		return false;

	read_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(uid);
	if (entry)
		ret = entry->state;
	else
		ret = -1;
	read_unlock_bh(&(cfg->app_collect_lock));
	return ret;
}

bool is_cloud_network_enable(void)
{
	if (atomic_read(&inited) == CLOUD_NETWORK_DEINIED || atomic_read(&(cfg->enable)) == CONFIG_DISABLE)
		return false;

	return true;
}

int get_protocol_info(struct protocol_info *proto)
{
	errno_t err;

	if (atomic_read(&inited) == CLOUD_NETWORK_DEINIED ||
		atomic_read(&(cfg->enable)) == CONFIG_DISABLE || proto == NULL)
		return ERROR;

	read_lock_bh(&(cfg->cfg_lock));
	proto->compass_ip = cfg->compass.compass_ip;
	proto->compass_port = cfg->compass.compass_port;
	err = memcpy_s(proto->client_id, sizeof(proto->client_id),
		cfg->compass.client_id, sizeof(proto->client_id));
	if (err != EOK) {
		read_unlock_bh(&(cfg->cfg_lock));
		return ERROR;
	}

	err = memcpy_s(proto->app_id, sizeof(proto->app_id),
		cfg->compass.app_id, sizeof(proto->app_id));
	if (err != EOK) {
		read_unlock_bh(&(cfg->cfg_lock));
		return ERROR;
	}

	proto->hmac_id = cfg->key.hmac_id;
	read_unlock_bh(&(cfg->cfg_lock));
	return SUCCESS;
}

int get_link_info(struct link_info *link_info_data)
{
	if (atomic_read(&inited) == CLOUD_NETWORK_DEINIED ||
		atomic_read(&(cfg->enable)) == CONFIG_DISABLE)
		return ERROR;

	if (unlikely(link_info_data == NULL))
		return ERROR;

	read_lock_bh(&(cfg->cfg_lock));
	link_info_data->pri_modem_permit = cfg->link.pri_modem_permit;
	link_info_data->sec_modem_permit = cfg->link.sec_modem_permit;
	link_info_data->pri_wifi_permit = cfg->link.pri_wifi_permit;
	link_info_data->scene = cfg->link.scene;
	link_info_data->rtt_gain_show_report_interval = cfg->link.rtt_gain_show_report_interval;
	link_info_data->rtt_gain_show_calc_num = cfg->link.rtt_gain_show_calc_num;
	read_unlock_bh(&(cfg->cfg_lock));
	return SUCCESS;
}

int get_dynamic_param(struct dynamic_param_base *dynamic_param_data, int scene)
{
	if (atomic_read(&inited) == CLOUD_NETWORK_DEINIED)
		return ERROR;

	if (unlikely(dynamic_param_data == NULL))
		return ERROR;

	read_lock_bh(&(cfg->cfg_lock));
	struct dynamic_param_base scene_base = scene == SCENE_WIFI_MODEM ?
		cfg->dynamic.wifi_param : cfg->dynamic.modem_param;

	dynamic_param_data->rtt_qoe_num = scene_base.rtt_qoe_num;
	dynamic_param_data->slope_thresh = scene_base.slope_thresh;
	dynamic_param_data->mean_good_thresh = scene_base.mean_good_thresh;
	dynamic_param_data->mean_bad_thresh = scene_base.mean_bad_thresh;
	dynamic_param_data->single_to_redundant_interval_ms = scene_base.single_to_redundant_interval_ms;
	dynamic_param_data->redundant_to_single_interval_ms = scene_base.redundant_to_single_interval_ms;
	dynamic_param_data->redundant_to_single_hold_time = scene_base.redundant_to_single_hold_time;
	read_unlock_bh(&(cfg->cfg_lock));
	return SUCCESS;
}

bool protocol_info_match(__be32 compass_ip, __be16 compass_port)
{
	if (atomic_read(&inited) == CLOUD_NETWORK_DEINIED ||
		atomic_read(&(cfg->enable)) == CONFIG_DISABLE)
		return false;

	read_lock_bh(&(cfg->cfg_lock));
	if (((cfg->compass.compass_ip == compass_ip) &&
		(cfg->compass.compass_port == ntohs(compass_port))) ||
		((cfg->last_compass.compass_ip == compass_ip) &&
		(cfg->last_compass.compass_port == ntohs(compass_port)))) {
		read_unlock_bh(&(cfg->cfg_lock));
		return true;
	}
	read_unlock_bh(&(cfg->cfg_lock));
	return false;
}

int get_match_window_id(__be32 compass_ip, __be16 compass_port)
{
	int ret = ERROR;
	if (atomic_read(&inited) == CLOUD_NETWORK_DEINIED ||
		atomic_read(&(cfg->enable)) == CONFIG_DISABLE)
		return ret;

	read_lock_bh(&(cfg->cfg_lock));
	if ((cfg->compass.compass_ip == compass_ip) &&
		(cfg->compass.compass_port == ntohs(compass_port)))
		ret = get_rx_window_id();
	else if ((cfg->last_compass.compass_ip == compass_ip) &&
		(cfg->last_compass.compass_port == ntohs(compass_port)))
		ret = get_backup_window_id();
	else
		ret = ERROR;
	read_unlock_bh(&(cfg->cfg_lock));
	return ret;
}

int cloud_network_param_init(void)
{
	if (likely(cfg == NULL)) {
		log_info("cloud network config param malloc");
		cfg = (struct config_param *)kmalloc(sizeof(struct config_param), GFP_ATOMIC);
		if (unlikely(cfg == NULL)) {
			log_err("kmalloc failed");
			atomic_set(&inited, CLOUD_NETWORK_DEINIED);
			return ERROR;
		}
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		rwlock_init(&(cfg->cfg_lock));
		rwlock_init(&(cfg->app_collect_lock));
		write_lock_bh(&(cfg->app_collect_lock));
		cfg->app_collect = RB_ROOT;
		write_unlock_bh(&(cfg->app_collect_lock));
	} else {
		log_info("cloud network config param has malloc");
		atomic_set(&(cfg->enable), CONFIG_DISABLE);
		app_collect_clear();
	}

	write_lock_bh(&(cfg->cfg_lock));
	(void)memset_s(&(cfg->compass), sizeof(struct compass_info), 0x00,
		sizeof(struct compass_info));
	write_unlock_bh(&(cfg->cfg_lock));

	if (likely(status == NULL)) {
		log_info("cloud network status param init");
		status = (struct status_param *)kmalloc(sizeof(struct status_param), GFP_ATOMIC);
		if (unlikely(status == NULL)) {
			log_err("kmalloc failed");
			atomic_set(&inited, CLOUD_NETWORK_DEINIED);
			return ERROR;
		}
	}
	atomic_set(&(status->started), STATUS_STOPED);
	atomic_set(&inited, CLOUD_NETWORK_INITED);
	atomic_set(&is_screen_on, 1);
	atomic_set(&is_app_front, 0);
	cloud_network_ipv6_init();
	return SUCCESS;
}

void cloud_network_param_exit(void)
{
	atomic_set(&inited, CLOUD_NETWORK_DEINIED);
	if (likely(cfg != NULL)) {
		log_err("config param exit");
		app_collect_clear();
		kfree(cfg);
		cfg = NULL;
	}
	if (likely(status != NULL)) {
		log_err("status param exit");
		kfree(status);
		status = NULL;
	}
	return;
}

int compass_status_report(int report_status)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_compass_status *msg_rept = NULL;
	struct protocol_info info;
	int ims_exception_level = get_ims_exception_level();
	int detect_exception_level = atomic_read(&(check_mgr.detect_exception_level));
	int current_compass_status = atomic_read(&compass_status);

	get_protocol_info(&info);

	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_compass_status), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return ERROR;
	}

	log_info("ims_exception_level %d compass_detect_exception_level %d current_compass_status %d", ims_exception_level,
		detect_exception_level, current_compass_status);

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_compass_status);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);

	msg_header->type = COMPASS_ABNORMAL;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_compass_status);

	msg_rept = (struct rept_compass_status *)(msg_header->data);
	msg_rept->status = report_status;
	msg_rept->compass_ip = info.compass_ip;
	log_info("event report compass status %u", msg_rept->status);
	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return SUCCESS;
}

static bool is_front_app_compass_check_start(void)
{
	bool ret = false;
	spin_lock_bh(&check_mgr.lock);
	ret = check_mgr.front_app_compass_check_status;
	spin_unlock_bh(&check_mgr.lock);
	return ret;
}

static void compass_detect_callback(int path, u32 rtt, int average_rtt,
	int loss_rate)
{
	log_info("detect prob RTT %u", rtt);
	if (!is_cloud_network_enable())
		return;

	detect_stop();
	if (!is_compass_available())
		set_compass_available();

	spin_lock_bh(&check_mgr.lock);
	hrtimer_cancel(&check_mgr.detect_timer);
	hrtimer_cancel(&check_mgr.unavailable_status_compass_check_timer);
	if (check_mgr.front_app_compass_check_status && (atomic_read(&is_screen_on) == 1) &&
		(atomic_read(&is_app_front) == 1) &&
		!hrtimer_active(&check_mgr.front_app_compass_check_timer))
		hrtimer_start(&check_mgr.front_app_compass_check_timer,
			ms_to_ktime(check_mgr.config.poll_timeout), HRTIMER_MODE_REL);

	atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_NO);
	if (get_data_flow_status() && (get_ims_status() || (atomic_read(&is_screen_on) == 1)) &&
		!hrtimer_active(&check_mgr.data_flow_compass_check_timer))
		hrtimer_start(&check_mgr.data_flow_compass_check_timer,
			ms_to_ktime(check_mgr.config.data_poll_timeout), HRTIMER_MODE_REL);
	spin_unlock_bh(&check_mgr.lock);
}

static void detect_start(void)
{
	log_info("detect start");
	if (unlikely(!is_cloud_network_enable()))
		return;
	detect_module_start(COMPASS_CHECK_ID, check_mgr.config.detect_interval,
		DETECT_PATH_BIT_MODEM_1 | DETECT_PATH_BIT_MODEM_2 | DETECT_PATH_BIT_WIFI_1,
		compass_detect_callback);
	atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_NO);
	if (!hrtimer_active(&check_mgr.detect_timer))
		hrtimer_start(&check_mgr.detect_timer,
			ms_to_ktime(check_mgr.config.exception_timeout_cloud), HRTIMER_MODE_REL);
}

static void detect_stop(void)
{
	log_info("detect stop");
	detect_module_stop(COMPASS_CHECK_ID);
	return;
}

void compass_check_once(void)
{
	log_info("compass check once");
	spin_lock_bh(&check_mgr.lock);
	detect_start();
	spin_unlock_bh(&check_mgr.lock);
}

void front_app_compass_check_start(void)
{
	log_info("front app compass check start");
	rtt_gain_show_counter_reset();
	spin_lock_bh(&check_mgr.lock);
	check_mgr.front_app_compass_check_status = true;
	if (!hrtimer_active(&check_mgr.front_app_compass_check_timer))
		hrtimer_start(&check_mgr.front_app_compass_check_timer,
			ms_to_ktime(check_mgr.config.poll_timeout), HRTIMER_MODE_REL);

	detect_start();
	spin_unlock_bh(&check_mgr.lock);
}

void front_app_compass_check_stop(void)
{
	log_info("front app compass check stop");
	spin_lock_bh(&check_mgr.lock);
	check_mgr.front_app_compass_check_status = false;
	hrtimer_cancel(&check_mgr.front_app_compass_check_timer);
	spin_unlock_bh(&check_mgr.lock);
	atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_NO);
}

void data_flow_compass_check_start(void)
{
	log_info("data flow compass check start");
	spin_lock_bh(&check_mgr.lock);
	if (!hrtimer_active(&check_mgr.data_flow_compass_check_timer))
		hrtimer_start(&check_mgr.data_flow_compass_check_timer,
			ms_to_ktime(check_mgr.config.data_poll_timeout), HRTIMER_MODE_REL);
	spin_unlock_bh(&check_mgr.lock);
}

static void try_to_start_data_flow_compass_check(void)
{
	if (get_ims_status() ||
		((atomic_read(&is_screen_on) == 1) && get_data_flow_status()))
		data_flow_compass_check_start();
}

static void try_to_stop_data_flow_compass_check(void)
{
	if (!get_ims_status() &&
		((atomic_read(&is_screen_on) == 0) || !get_data_flow_status()))
		hrtimer_cancel(&check_mgr.data_flow_compass_check_timer);
}

static void try_to_start_front_app_compass_check(void)
{
	if (is_front_app_compass_check_start())
		return;

	if (((atomic_read(&is_screen_on) == 1) && (atomic_read(&is_app_front) == 1)))
		front_app_compass_check_start();
}

static void try_to_stop_front_app_compass_check(void)
{
	if (!is_front_app_compass_check_start())
		return;

	if (((atomic_read(&is_screen_on) == 0) || (atomic_read(&is_app_front) == 0)))
		front_app_compass_check_stop();
}

static enum hrtimer_restart front_app_compass_check_timeout(struct hrtimer *timer)
{
	if (is_cloud_network_enable())
		schedule_work(&check_mgr.front_app_compass_check_work);
	return HRTIMER_NORESTART;
}

static enum hrtimer_restart unavailable_status_compass_check_timeout(struct hrtimer *timer)
{
	if (is_cloud_network_enable())
		schedule_work(&check_mgr.unavailable_status_compass_check_work);
	return HRTIMER_NORESTART;
}

static enum hrtimer_restart data_flow_compass_check_timer_timeout(struct hrtimer *timer)
{
	if (is_cloud_network_enable())
		schedule_work(&check_mgr.data_flow_compass_check_work);
	return HRTIMER_NORESTART;
}

static enum hrtimer_restart compass_detect_timeout(struct hrtimer *timer)
{
	if (is_cloud_network_enable())
		schedule_work(&check_mgr.detect_timeout_work);
	return HRTIMER_NORESTART;
}

static void front_app_compass_check_handle(struct work_struct *work)
{
	log_info("front app compass check timer handle");
	if (!is_cloud_network_enable())
		return;
	spin_lock_bh(&check_mgr.lock);
	detect_start();
	spin_unlock_bh(&check_mgr.lock);
}

static void unavailable_status_compass_check_handle(struct work_struct *work)
{
	log_info("unavailable status compass check timer handle");
	if (!is_cloud_network_enable())
		return;
	spin_lock_bh(&check_mgr.lock);
	detect_start();
	spin_unlock_bh(&check_mgr.lock);
}

static void data_flow_compass_check_timer_handle(struct work_struct *work)
{
	log_info("data flow compass check timer handle");
	if (!is_cloud_network_enable())
		return;
	spin_lock_bh(&check_mgr.lock);
	detect_start();
	spin_unlock_bh(&check_mgr.lock);
}

static bool compass_unavailable_condition(void)
{
	struct link_info link_info_data;

	if (get_link_info(&link_info_data) != SUCCESS)
		return false;
	if ((link_info_data.scene == SCENE_MOEM_MODEM) && /* modem + modem scene */
		((get_link_path() & (PATH_MODEM_1 | PATH_MODEM_2)) == 0))
		return false;
	if ((link_info_data.scene == SCENE_WIFI_MODEM) && /* wifi + modem scene */
		((get_link_path() & (PATH_WIFI_1 | PATH_MODEM_1)) == 0))
		return false;
	return true;
}

static u32 get_compass_exception_timeout_link(void)
{
	u32 ret;
	spin_lock_bh(&check_mgr.lock);
	ret = check_mgr.config.exception_timeout_link;
	spin_unlock_bh(&check_mgr.lock);
	return ret;
}

static u32 get_compass_exception_timeout_cloud(void)
{
	u32 ret;
	spin_lock_bh(&check_mgr.lock);
	ret = check_mgr.config.exception_timeout_cloud;
	spin_unlock_bh(&check_mgr.lock);
	return ret;
}

static void compass_detect_timeout_handle(struct work_struct *work)
{
	u32 exception_timeout_link;
	u32 exception_timeout_cloud;

	log_info("compass detect timeout, compass unavailable handle");
	if (!is_cloud_network_enable())
		return;

	if (atomic_read(&(check_mgr.detect_exception_level)) == EXCEPTION_NO) {
		log_info("handle EXCEPTION_LEVEL_ONE_CLOUD level");
		atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_LEVEL_ONE_CLOUD);
		exception_timeout_link = get_compass_exception_timeout_link();
		exception_timeout_cloud = get_compass_exception_timeout_cloud();
		if (exception_timeout_link > exception_timeout_cloud) {
			log_info("start EXCEPTION_LEVEL_TWO_LINK level timer");
			if (!hrtimer_active(&check_mgr.detect_timer))
				hrtimer_start(&check_mgr.detect_timer,
					ms_to_ktime(exception_timeout_link - exception_timeout_cloud), HRTIMER_MODE_REL);
			compass_status_judgment(ktime_to_ms(ktime_get_real()));
			return;
		}
	}
	if (atomic_read(&(check_mgr.detect_exception_level)) == EXCEPTION_LEVEL_ONE_CLOUD) {
		log_info("handle EXCEPTION_LEVEL_TWO_LINK level");
		atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_LEVEL_TWO_LINK);
		compass_status_judgment(ktime_to_ms(ktime_get_real()));
		if (compass_unavailable_condition() && is_compass_available())
			set_compass_unavailable();

		spin_lock_bh(&check_mgr.lock);
		detect_stop();
		cancel_work_sync(&(check_mgr.front_app_compass_check_work));
		cancel_work_sync(&(check_mgr.unavailable_status_compass_check_work));
		cancel_work_sync(&(check_mgr.data_flow_compass_check_work));
		hrtimer_cancel(&check_mgr.front_app_compass_check_timer);
		hrtimer_cancel(&check_mgr.unavailable_status_compass_check_timer);
		hrtimer_cancel(&check_mgr.data_flow_compass_check_timer);
		hrtimer_cancel(&check_mgr.detect_timer);
		spin_unlock_bh(&check_mgr.lock);
	}
	return;
}

void stop_all_compass_detect(void)
{
	log_info("stop all compass deetect");
	cancel_work_sync(&(check_mgr.front_app_compass_check_work));
	cancel_work_sync(&(check_mgr.unavailable_status_compass_check_work));
	cancel_work_sync(&(check_mgr.data_flow_compass_check_work));
	cancel_work_sync(&(check_mgr.detect_timeout_work));
	hrtimer_cancel(&check_mgr.front_app_compass_check_timer);
	hrtimer_cancel(&check_mgr.unavailable_status_compass_check_timer);
	hrtimer_cancel(&check_mgr.data_flow_compass_check_timer);
	hrtimer_cancel(&check_mgr.detect_timer);
	atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_NO);
	return;
}

void start_compass_detect_on_demand(void)
{
	log_info("start compass detect on demand");
	if (check_mgr.front_app_compass_check_status &&
		!hrtimer_active(&check_mgr.front_app_compass_check_timer))
		hrtimer_start(&check_mgr.front_app_compass_check_timer,
			ms_to_ktime(check_mgr.config.poll_timeout), HRTIMER_MODE_REL);

	if (get_data_flow_status() &&
		!hrtimer_active(&check_mgr.data_flow_compass_check_timer))
		hrtimer_start(&check_mgr.data_flow_compass_check_timer,
			ms_to_ktime(check_mgr.config.data_poll_timeout), HRTIMER_MODE_REL);
	return;
}

int compass_check_init(void)
{
	check_mgr.config.poll_timeout = FRONT_APP_COMPASS_CHECK_INTERVAL;
	check_mgr.config.detect_interval = COMPASS_DETECT_INTERVAL;
	check_mgr.config.exception_timeout_link = COMPASS_DETECT_TIMEOUT_LINK;
	check_mgr.config.exception_timeout_cloud = COMPASS_DETECT_TIMEOUT_CLOUD;
	check_mgr.config.exception_poll_timeout =
		UNAVAILABLE_STATUS_COMPASS_CHECK_INTERVAL;
	check_mgr.config.data_poll_timeout = DATA_FLOW_COMPASS_CHECK_INTERVAL;
	atomic_set(&(check_mgr.detect_exception_level), EXCEPTION_NO);

	check_mgr.front_app_compass_check_status = false;
	set_data_flow_status_stop();
	set_compass_available();

	INIT_WORK(&(check_mgr.front_app_compass_check_work),
		front_app_compass_check_handle);
	INIT_WORK(&(check_mgr.unavailable_status_compass_check_work),
		unavailable_status_compass_check_handle);
	INIT_WORK(&(check_mgr.data_flow_compass_check_work),
		data_flow_compass_check_timer_handle);
	INIT_WORK(&(check_mgr.detect_timeout_work), compass_detect_timeout_handle);

	hrtimer_init(&check_mgr.front_app_compass_check_timer, CLOCK_MONOTONIC,
		HRTIMER_MODE_REL);
	check_mgr.front_app_compass_check_timer.function =
		front_app_compass_check_timeout;
	hrtimer_init(&check_mgr.unavailable_status_compass_check_timer,
		CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	check_mgr.unavailable_status_compass_check_timer.function =
		unavailable_status_compass_check_timeout;
	hrtimer_init(&check_mgr.data_flow_compass_check_timer,
		CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	check_mgr.data_flow_compass_check_timer.function =
		data_flow_compass_check_timer_timeout;
	hrtimer_init(&check_mgr.detect_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	check_mgr.detect_timer.function = compass_detect_timeout;
	spin_lock_init(&check_mgr.lock);
	atomic_set(&compass_status, COMPASS_NORMAL_IMS_NORMAL);
	return SUCCESS;
}

void compass_check_exit(void)
{
	spin_lock_bh(&check_mgr.lock);
	check_mgr.front_app_compass_check_status = false;
	spin_unlock_bh(&check_mgr.lock);
	set_data_flow_status_stop();
	cancel_work_sync(&(check_mgr.front_app_compass_check_work));
	cancel_work_sync(&(check_mgr.unavailable_status_compass_check_work));
	cancel_work_sync(&(check_mgr.data_flow_compass_check_work));
	cancel_work_sync(&(check_mgr.detect_timeout_work));
	hrtimer_cancel(&check_mgr.front_app_compass_check_timer);
	hrtimer_cancel(&check_mgr.unavailable_status_compass_check_timer);
	hrtimer_cancel(&check_mgr.data_flow_compass_check_timer);
	hrtimer_cancel(&check_mgr.detect_timer);
	return;
}

int ims_error_report(u32 uid)
{
	struct netlink_head *msg_rsp = NULL;
	struct netlink_msg_head *msg_header = NULL;
	struct rept_ims_app_abnormal *msg_rept = NULL;

	log_info("event report ims app abnormal");
	msg_rsp = (struct netlink_head *)kmalloc(sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ims_app_abnormal), GFP_ATOMIC);
	if (unlikely(msg_rsp == NULL)) {
		log_err("kmalloc failed");
		return ERROR;
	}

	msg_rsp->type = CLOUD_NETWORK_REPORT;
	msg_rsp->msg_len = sizeof(struct netlink_head) +
		sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ims_app_abnormal);

	msg_header = (struct netlink_msg_head *)(msg_rsp->data);
	msg_header->type = IMS_APP_ABNORMAL;
	msg_header->data_len = sizeof(struct netlink_msg_head) +
		sizeof(struct rept_ims_app_abnormal);

	msg_rept = (struct rept_ims_app_abnormal *)(msg_header->data);
	msg_rept->uid = uid;

	netlink_report(msg_rsp, WORK_EXEC);
	kfree(msg_rsp);
	return SUCCESS;
}

static void single_path_upstream_exist_downstream_no_exist_check(void)
{
	struct app_node *entry = NULL;
	bool result = false;
	u8 scene;
	u8 id_pri;
	u8 id_sec;

	read_lock_bh(&(cfg->cfg_lock));
	scene = cfg->link.scene;
	read_unlock_bh(&(cfg->cfg_lock));
	if (scene == SCENE_MOEM_MODEM) {
		id_pri = DETECT_PATH_VAL_MODEM_1;
		id_sec = DETECT_PATH_VAL_MODEM_2;
	} else if (scene == SCENE_WIFI_MODEM) {
		id_pri = DETECT_PATH_VAL_WIFI_1;
		id_sec = DETECT_PATH_VAL_MODEM_1;
	} else {
		return;
	}

	write_lock_bh(&(cfg->app_collect_lock));
	spin_lock_bh(&ims_mgr.lock);
	entry = app_collect_search(ims_mgr.config.uid);
	if (entry) {
		if ((entry->upstream_exist_downstream_no_exist_cnt[id_pri] > SINGLE_PATH_UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST) ||
			(entry->upstream_exist_downstream_no_exist_cnt[id_sec] > SINGLE_PATH_UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST))
			result = true;
	}
	spin_unlock_bh(&ims_mgr.lock);
	write_unlock_bh(&(cfg->app_collect_lock));

	if (result) {
		log_info("single path upstream exist downstream no exist");
		compass_status_report(COMPASS_NORMAL_IMS_ABNORMAL);
	}

	return;
}

static void upstream_exist_downstream_no_exist_check_work_handle(struct app_node *entry, int id)
{
	if (unlikely((entry == NULL) || (id < DETECT_PATH_VAL_MODEM_1) || (id > DETECT_PATH_VAL_WIFI_2)))
		return;

	if ((entry->tx_packet_cnt[id] > UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST_CHECK_TX_THRES) &&
		(entry->rx_packet_cnt[id] == 0)) {
		entry->upstream_exist_downstream_no_exist_cnt[id]++;
		if ((entry->upstream_exist_downstream_no_exist_cnt[id] * MSEC_PER_SEC) >
			(s64)ims_mgr.config.exception_timeout_link) {
			ims_mgr.exception_level[id] = EXCEPTION_LEVEL_TWO_LINK;
		} else if ((entry->upstream_exist_downstream_no_exist_cnt[id] * MSEC_PER_SEC) >
			(s64)ims_mgr.config.exception_timeout_cloud) {
			ims_mgr.exception_level[id] = EXCEPTION_LEVEL_ONE_CLOUD;
		} else {
			ims_mgr.exception_level[id] = 0;
		}
	} else {
		entry->upstream_exist_downstream_no_exist_cnt[id] = 0;
		ims_mgr.exception_level[id] = 0;
	}

	return;
}

static void upstream_exist_downstream_no_exist_check_work(struct work_struct *work)
{
	struct app_node *entry = NULL;

	if (!is_cloud_network_enable())
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	spin_lock_bh(&ims_mgr.lock);

	entry = app_collect_search(ims_mgr.config.uid);
	if (entry) {
		for (int i = DETECT_PATH_VAL_MODEM_1; i < DETECT_PATH_VAL_MAX; i++) {
			if (get_link_path() == 0) {
				log_info("no available network, reset upstream_exist_downstream_no_exist_check param");
				entry->tx_packet_cnt[i] = 0;
				entry->rx_packet_cnt[i] = 0;
				entry->upstream_exist_downstream_no_exist_cnt[i] = 0;
				ims_mgr.exception_level[i] = 0;
				continue;
			}
			upstream_exist_downstream_no_exist_check_work_handle(entry, i);
			log_info("i %d uid %u tx_packet %u rx_packet %u up_exist_down_no_exist_cnt %u exception_level %u",
				i, entry->app.uid, entry->tx_packet_cnt[i], entry->rx_packet_cnt[i],
				entry->upstream_exist_downstream_no_exist_cnt[i], ims_mgr.exception_level[i]);
			entry->tx_packet_cnt[i] = 0;
			entry->rx_packet_cnt[i] = 0;
		}
	}
	if (ims_mgr.status && !hrtimer_active(&ims_mgr.upstream_exist_downstream_no_exist_check_timer))
		hrtimer_start(&ims_mgr.upstream_exist_downstream_no_exist_check_timer,
			ms_to_ktime(UPSTREAM_EXIST_DOWNSTREAM_NO_EXIST_CHECK_TIMER), HRTIMER_MODE_REL);

	spin_unlock_bh(&ims_mgr.lock);
	write_unlock_bh(&(cfg->app_collect_lock));

	compass_status_judgment(ktime_to_ms(ktime_get_real()));
	single_path_upstream_exist_downstream_no_exist_check();

	return;
}

static enum hrtimer_restart upstream_exist_downstream_no_exist_check_timer(struct hrtimer *timer)
{
	if (is_cloud_network_enable())
		schedule_work(&(ims_mgr.upstream_exist_downstream_no_exist_check_work));
	return HRTIMER_NORESTART;
}

int ims_check_init(void)
{
	spin_lock_init(&ims_mgr.lock);
	(void)memset_s(ims_mgr.exception_level, sizeof(ims_mgr.exception_level), EXCEPTION_NO,
		sizeof(ims_mgr.exception_level));
	ims_mgr.config.exception_timeout_link = 0;
	ims_mgr.config.exception_timeout_cloud = 0;
	ims_mgr.config.uid = 0;
	ims_mgr.status = false;

	INIT_WORK(&(ims_mgr.upstream_exist_downstream_no_exist_check_work), upstream_exist_downstream_no_exist_check_work);
	hrtimer_init(&ims_mgr.upstream_exist_downstream_no_exist_check_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	ims_mgr.upstream_exist_downstream_no_exist_check_timer.function = upstream_exist_downstream_no_exist_check_timer;
	return SUCCESS;
}

void ims_check_exit(void)
{
	cancel_work_sync(&(ims_mgr.upstream_exist_downstream_no_exist_check_work));
	hrtimer_cancel(&ims_mgr.upstream_exist_downstream_no_exist_check_timer);
	spin_lock_bh(&ims_mgr.lock);
	(void)memset_s(ims_mgr.exception_level, sizeof(ims_mgr.exception_level), EXCEPTION_NO,
		sizeof(ims_mgr.exception_level));
	ims_mgr.config.exception_timeout_link = 0;
	ims_mgr.config.uid = 0;
	ims_mgr.status = false;
	spin_unlock_bh(&ims_mgr.lock);
}

bool get_ims_status(void)
{
	bool ret = false;
	spin_lock_bh(&ims_mgr.lock);
	ret = ims_mgr.status;
	spin_unlock_bh(&ims_mgr.lock);
	return ret;
}

bool is_ims_uid(u32 uid)
{
	spin_lock_bh(&ims_mgr.lock);
	if (ims_mgr.config.uid == uid) {
		spin_unlock_bh(&ims_mgr.lock);
		return true;
	}
	spin_unlock_bh(&ims_mgr.lock);
	return false;
}

static bool ims_exception_level_judgment(int exception_level_judg)
{
	bool ret = true;
	u8 scene;
	u8 id_pri;
	u8 id_sec;

	read_lock_bh(&(cfg->cfg_lock));
	scene = cfg->link.scene;
	read_unlock_bh(&(cfg->cfg_lock));
	if (scene == SCENE_MOEM_MODEM) {
		id_pri = DETECT_PATH_VAL_MODEM_1;
		id_sec = DETECT_PATH_VAL_MODEM_2;
	} else if (scene == SCENE_WIFI_MODEM) {
		id_pri = DETECT_PATH_VAL_WIFI_1;
		id_sec = DETECT_PATH_VAL_MODEM_1;
	} else {
		return false;
	}

	spin_lock_bh(&ims_mgr.lock);
	if ((ims_mgr.exception_level[id_pri] != exception_level_judg) ||
		(ims_mgr.exception_level[id_sec] != exception_level_judg))
		ret = false;
	spin_unlock_bh(&ims_mgr.lock);
	return ret;
}

static int get_ims_exception_level(void)
{
	if (ims_exception_level_judgment(EXCEPTION_NO))
		return EXCEPTION_NO;
	else if (ims_exception_level_judgment(EXCEPTION_LEVEL_ONE_CLOUD))
		return EXCEPTION_LEVEL_ONE_CLOUD;
	else if (ims_exception_level_judgment(EXCEPTION_LEVEL_TWO_LINK))
		return EXCEPTION_LEVEL_TWO_LINK;
	else
		return EXCEPTION_NO;
}

static bool ims_receive_send_normal_check()
{
	struct app_node *entry = NULL;
	bool ret = true;
	int i;

	write_lock_bh(&(cfg->app_collect_lock));
	spin_lock_bh(&ims_mgr.lock);

	entry = app_collect_search(ims_mgr.config.uid);
	if (entry) {
		for (i = DETECT_PATH_VAL_MODEM_1; i < DETECT_PATH_VAL_MAX; i++) {
			if (entry->upstream_exist_downstream_no_exist_cnt[i] <= 1) {
				log_info("i %d uid %u tx_packet %u rx_packet %u up_exist_down_no_exist_cnt %u exception_level %u",
					i, entry->app.uid, entry->tx_packet_cnt[i], entry->rx_packet_cnt[i],
					entry->upstream_exist_downstream_no_exist_cnt[i], ims_mgr.exception_level[i]);
				break;
			}
		}
		if (i == DETECT_PATH_VAL_MAX) {
			log_info("ims receive send normal check fasle");
			ret = false;
		}
	}
	spin_unlock_bh(&ims_mgr.lock);
	write_unlock_bh(&(cfg->app_collect_lock));
	return ret;
}

static void compass_status_judgment(s64 current_timestamp)
{
	int ims_exception_level = get_ims_exception_level();
	int detect_exception_level = atomic_read(&(check_mgr.detect_exception_level));
	int current_compass_status = atomic_read(&compass_status);
	struct link_info link_info_data;
	int paths;

	if (get_link_info(&link_info_data) != SUCCESS)
		return;

	if (link_info_data.scene == SCENE_WIFI_MODEM)
		paths = DETECT_PATH_BIT_MODEM_1 | DETECT_PATH_BIT_WIFI_1;
	else if	(link_info_data.scene == SCENE_MOEM_MODEM)
		paths = DETECT_PATH_BIT_MODEM_1 | DETECT_PATH_BIT_MODEM_2;
	else
		return;

	if (!get_ims_status())
		return;

	if (ims_exception_level > EXCEPTION_NO && compass_detect_normal_check(paths, current_timestamp))
		atomic_set(&compass_status, COMPASS_NORMAL_IMS_ABNORMAL);
	else if (detect_exception_level > EXCEPTION_NO && ims_receive_send_normal_check())
		atomic_set(&compass_status, COMPASS_ABNORMAL_IMS_NORMAL);
	else if (detect_exception_level == EXCEPTION_LEVEL_TWO_LINK && ims_exception_level == EXCEPTION_LEVEL_TWO_LINK)
		atomic_set(&compass_status, COMPASS_ABNORMAL_IMS_ABNORMAL);
	else if (detect_exception_level == EXCEPTION_NO && ims_exception_level == EXCEPTION_NO)
		atomic_set(&compass_status, COMPASS_NORMAL_IMS_NORMAL);

	if (atomic_read(&compass_status) != current_compass_status)
		compass_status_report(atomic_read(&compass_status));

	return;
}

void ims_tx_rx_packet_cnt_updata(u32 uid, int dir, u32 fid)
{
	struct app_node *entry = NULL;

	if (!is_cloud_network_enable() || !get_ims_status() || !is_ims_uid(uid) || (fid < DETECT_PATH_VAL_MODEM_1) ||
		(fid > DETECT_PATH_VAL_WIFI_2))
		return;

	write_lock_bh(&(cfg->app_collect_lock));
	entry = app_collect_search(uid);
	if (entry) {
		if (dir == IMS_TX_PACKET_CNT_UPDATE)
			entry->tx_packet_cnt[fid]++;
		else if (dir == IMS_RX_PACKET_CNT_UPDATE)
			entry->rx_packet_cnt[fid]++;
	}
	write_unlock_bh(&(cfg->app_collect_lock));
	return;
}
