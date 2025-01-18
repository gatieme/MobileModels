/*
 * cloud_network_param.h
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

#ifndef _CLOUD_NETWORK_PARAM_H_
#define _CLOUD_NETWORK_PARAM_H_

#include <linux/types.h>
#include <linux/version.h>
#include <linux/spinlock.h>
#include <linux/rbtree.h>
#include <linux/netdevice.h>
#include "cloud_network.h"

#define CLOUD_NETWORK_DEINIED 0
#define CLOUD_NETWORK_INITED 1

#define CONFIG_DISABLE 0
#define CONFIG_ENABLE 1

#define STATUS_STOPED 0
#define STATUS_STARTED 1

#define DATA_LEN_MAX_FOR_SIGNED 1568
#define SHA256_SIGNED_DATA_LEN 32

#define COMPASS_DETECT_INTERVAL 1000 /* ms */
#define COMPASS_DETECT_TIMEOUT_LINK 40000 /* ms */
#define COMPASS_DETECT_TIMEOUT_CLOUD 10000 /* ms */
#define UNAVAILABLE_STATUS_COMPASS_CHECK_INTERVAL 10000 /* ms */
#define FRONT_APP_COMPASS_CHECK_INTERVAL 3000000 /* ms */
#define DATA_FLOW_COMPASS_CHECK_INTERVAL 1000 /* ms */

#define IMS_TX_PACKET_CNT_UPDATE 0
#define IMS_RX_PACKET_CNT_UPDATE 1

struct app_node {
	struct rb_node app_rb_node;
	struct app_info app;
	int state;
	struct list_head ipv6_udp_sock;
	struct list_head ipv6_tcp_sock;
	u32 ipv6_udp_sock_cnt;
	u32 ipv6_udp_sock_cnt_max;
	u32 ipv6_tcp_sock_cnt;
	u32 ipv6_tcp_sock_cnt_max;

	u32 tx_packet_cnt[DETECT_PATH_VAL_MAX];
	u32 rx_packet_cnt[DETECT_PATH_VAL_MAX];
	u32 upstream_exist_downstream_no_exist_cnt[DETECT_PATH_VAL_MAX];
};

struct dev_state {
	u8 pri_card;
	u8 sec_card;
	u8 wifi;
	u8 condition;
};

struct config_param {
	atomic_t enable;

	rwlock_t cfg_lock;
	struct compass_info compass;
	struct compass_info last_compass;
	struct key_info key;
	struct link_info link;
	struct dynamic_param dynamic;
	struct rb_root app_collect;
	rwlock_t app_collect_lock;
};

struct status_param {
	atomic_t started;
};

struct protocol_info {
	u8  app_id[APP_ID_LEN];
	u32 compass_ip;
	u16 compass_port;
	u8  client_id[CLINET_ID_LEN];
	u8  hmac_key[SIGN_KEY_LEN];
	u8  hmac_id;
};

void set_compass_available(void);
void set_compass_unavailable(void);
bool is_compass_available(void);
void set_data_flow_status_start(void);
void set_data_flow_status_stop(void);
bool get_data_flow_status(void);
int cloud_network_param_init(void);
void cloud_network_param_exit(void);
int netlink_cmd_init_param_handle(const struct netlink_msg_head *msg);
void netlink_cmd_deinit_param_handle(const struct netlink_msg_head *msg);
void netlink_cmd_tx_rx_ctl_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_param_all_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_param_key_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_param_compass_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_param_app_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_param_link_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_ims_monitor_start_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_ims_monitor_stop_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_compass_monitor_start_handle(const struct netlink_msg_head *msg);
void netlink_cmd_cloud_compass_monitor_stop_handle(const struct netlink_msg_head *msg);
int netlink_cmd_qos_get_handle(const struct netlink_msg_head *msg,
								struct rept_qos *msg_rept);
int netlink_cmd_startacc_param_handle(const struct netlink_msg_head *msg);
int netlink_cmd_stopacc_param_handle(const struct netlink_msg_head *msg);
void netlink_cmd_ipv6_monitor_param_handle(const struct netlink_msg_head *msg);
int netlink_cmd_screen_state_handle(const struct netlink_msg_head *msg);
int get_protocol_info(struct protocol_info *proto);
int get_link_info(struct link_info *link_info_data);
int get_dynamic_param(struct dynamic_param_base *dynamic_param_data, int scene);
bool protocol_info_match(u32 compass_ip, u16 compass_port);
bool is_cloud_network_enable(void);
int skb_uid_match(u32 uid);

bool get_ims_status(void);
int ims_check_init(void);
void ims_check_exit(void);
void ims_tx_rx_packet_cnt_updata(u32 uid, int dir, u32 fid);
void compass_check_once(void);
void front_app_compass_check_start(void);
void front_app_compass_check_stop(void);
void data_flow_compass_check_start(void);
void stop_all_compass_detect(void);
void start_compass_detect_on_demand(void);
int compass_check_init(void);
void compass_check_exit(void);
bool is_compass_changing(void);
int compass_status_report(int report_status);
int get_match_window_id(__be32 compass_ip, __be16 compass_port);
bool cloud_network_inet6_block_handle(struct socket *sock);
void cloud_network_inet6_create_handle(struct sock *sk);
void cloud_network_inet6_release_handle(struct sock *sk);
#endif /* _CLOUD_NETWORK_PARAM_H_ */
