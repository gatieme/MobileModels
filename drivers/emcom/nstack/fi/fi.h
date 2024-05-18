/*
 * Copyright (c) Honor Device Co., Ltd. 2019-2020. All rights reserved.
 * Description: This module is to collect IP package parameters
 * Author: songqiubin songqiubin.
 * Create: 2019-09-18
 */

#ifndef _FI_H
#define _FI_H

#include <linux/if.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv6.h>
#include <linux/spinlock_types.h>
#include <linux/types.h>
#include "fi_flow.h"
#include "fi_flow_netinfo.h"
#include "fi_utils.h"
#include "emcom/emcom_xengine.h"

#define FI_LAUNCH_APP_MAX		8
#define FI_TIMER_INTERVAL		2 /* 500ms timer */
#define FI_NL_SKB_QUEUE_MAXLEN	128
#define FI_DEV_NUM			4
#define FI_DEV_INVALID		(-1)
#define FI_WLAN0_IFNAME	emcom_xengine_get_network_iface_name(EMCOM_XENGINE_NET_WLAN0)
#define FI_CELL0_IFNAME	emcom_xengine_get_network_iface_name(EMCOM_XENGINE_NET_CELL0)
#define FI_WLAN1_IFNAME	emcom_xengine_get_network_iface_name(EMCOM_XENGINE_NET_WLAN1)
#define FI_CELL1_IFNAME	emcom_xengine_get_network_iface_name(EMCOM_XENGINE_NET_CELL1)
#define FI_INVALID_SEQ_NUM -1
#define FI_MAX_SEQ_NUM 0xffff
#define FI_MAX_PKT_NUM_PER_PERIOD 0xff
#define FI_SKB_MAX_FRAG_LIST_NUM 20
#define FI_MIN_DELTA_US 5000u
#define FI_MIN_BURST_DURATION 2000u
#define FI_MIN_BURST_SIZE (10 * 1024)
#define FI_RTT_SHIFT 3
#define FI_VER "V3.00 20200920"

#define FI_APP_INFO_DNS_BUFFER_NUM 6
#define FI_APP_INFO_DNS_TIME_OUT 5000
#define FI_APP_INFO_DNS_PORT 53
#define FI_APP_INFO_DNS_TIMER_EXPIRE 10 // 10 * 500ms
#define FI_APP_INFO_DNS_TIMER_COUNTER_INVALID (-1) // DNS TIMER INVALID TAG
#define FI_TIME_BASE 1000
#define INVALID_TID 0xffff

#define MAKE_SEQ_NUM(high, low) ((((uint32_t)(high)) << 8) | ((uint32_t)(low)))
#define fi_min(a, b) (((a) <= (b)) ? (a) : (b))
#define fi_max(a, b) (((a) >= (b)) ? (a) : (b))

typedef enum {
	FI_DEV_WLAN,
	FI_DEV_CELL,
}fi_dev_type;

typedef enum {
	FI_SET_NL_PID_CMD,
	FI_COLLECT_START_CMD,
	FI_COLLECT_STATUS_UPDATE_CMD,
	FI_COLLECT_INFO_UPDATE_CMD,
	FI_COLLECT_FLOW_CTRL_MAP_UPDATE_CMD,
	CMD_NUM,
} fi_cfg_type;

typedef enum {
	FI_PKT_MSG_RPT,
	FI_PERIODIC_MSG_RPT,
	FI_QOS_MSG_RPT,
	FI_IFACE_MSG_RPT,
	FI_APP_MSG_RPT,
} fi_msg_type;

struct fi_app_info_table {
	struct fi_app_info_node	app[FI_LAUNCH_APP_MAX];
	atomic_t			free_cnt;
};

struct fi_dns_ctx {
	int32_t num;
	uint16_t tid[FI_APP_INFO_DNS_BUFFER_NUM];
	uint64_t req_timestamp[FI_APP_INFO_DNS_BUFFER_NUM];
	int32_t timer_counter;
	uint64_t total_delay;
};

struct fi_app_stat_ctx {
	struct fi_dns_ctx dns_ctx;
	uint32_t rtt_cnt;
};

struct fi_app_stat_msg {
	uint32_t uplink_pkt_num;
	uint32_t dlink_pkt_num;
	uint32_t uplink_len;
	uint32_t downlink_len;
	uint32_t avr_rtt;
	uint32_t dlink_tcp_num;
	uint32_t dlink_tcp_len;
	uint32_t uplink_tcp_num;
	uint32_t uplink_tcp_len;
	uint32_t dlink_udp_num;
	uint32_t dlink_udp_len;
	uint32_t uplink_udp_num;
	uint32_t uplink_udp_len;
	uint32_t dlink_retrans_num;
	uint32_t uplink_retrans_num;
	uint32_t syn_num;
	uint32_t socket_num;
	uint32_t dns_fail_count;
	uint32_t dns_succ_count;
	uint32_t dns_avg_delay;
	uint32_t http_get_count;
	uint32_t uplink_retrans_rate;
	uint32_t dlink_retrans_rate;
	uint32_t uplink_udp_max_pktlen;
	uint32_t dlink_udp_max_pktlen;
};

struct fi_app_stat_report {
	int32_t uid;
	int8_t pri_dev;
	struct fi_app_stat_msg app_stat_msg;
};

struct fi_app_netinfo {
	struct fi_app_stat_report app_stat_report;
	struct fi_app_stat_ctx app_stat_ctx;
};

static struct fi_app_info_table g_fi_app_info;

struct fi_ctx {
	struct mutex		nf_mutex;
	bool				nf_exist;
	struct timer_list	tm;
	bool				running;
	bool	iface_qos_rpt_enable;
	struct sock *nlfd;
	uint32_t nl_pid;
	struct sk_buff_head skb_queue;
	struct semaphore netlink_sync_sema;
	struct task_struct *netlink_task;
	bool	app_netinfo_rpt_enable[FI_LAUNCH_APP_MAX];
	spinlock_t app_stat_lock;
	uint8_t index;
	struct fi_app_netinfo app_net_info[FI_LAUNCH_APP_MAX];
};

struct fi_iface_msg {
	char dev[IFNAMSIZ];
	uint32_t rcv_bytes;
};


struct fi_cfg_head{
	unsigned short		type;
	unsigned short		len;
};

extern struct fi_ctx g_fi_ctx;
extern void fi_cfg_process(const struct fi_cfg_head *cfg);
extern void fi_init(struct sock *nlfd);
extern void fi_deinit(void);
void fi_bw_calc(struct fi_flow_node *flow);
void fi_rtt_update(struct fi_flow_node *flow);
extern void fi_dns_statistic(void);
extern int fi_get_primary_dev(void);
#endif /* _FI_H */
