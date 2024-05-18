/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2022. All rights reserved.
 * Description: This module is flow table for FI
 * Author: yangjingqi
 * Create: 2022-01-29
 */

#ifndef _FI_FLOW_NET_INFO_H
#define _FI_FLOW_NET_INFO_H

#include <linux/spinlock_types.h>
#include <net/ipv6.h>


#define FI_FLOW_NET_INFO_TABLE_MASK	0xf
#define FI_FLOW_NET_INFO_TABLE_SIZE	0x10
#define FI_FLOW_NET_INFO_NODE_LIMIT	1024
#define FI_FLOW_NET_INFO_AGING_TIME	30000
#define FI_PERCENTAGE_100	100

struct fi_flow_app_info_stat {
	uint16_t	raw_up_tcp_pkt_num;
	uint16_t	raw_down_tcp_pkt_num;
	uint32_t	rtt;
};

struct fi_netinfo_flow_ctx {
	struct fi_flow_app_info_stat flow_app_info;
	struct fi_flow_msg flow_msg;
};

struct fi_netinfo_flow_node {
	struct list_head		list;
	union {
		struct {
			uint32_t		ipv4_saddr;
			uint32_t		ipv4_daddr;
		};
#if IS_ENABLED(CONFIG_IPV6)
		struct {
			struct in6_addr	ipv6_saddr;
			struct in6_addr	ipv6_daddr;
		};
#endif
	};
	__be16			sport;
	__be16			dport;
	uint32_t		updatetime;
	int32_t			uid;
	struct fi_netinfo_flow_ctx flow_ctx;
	fi_flow_cb			flow_cb;
	struct sock *sk;
};

struct fi_netinfo_flow_head {
	struct list_head		list;
};

struct fi_netinfo_flow {
	struct fi_netinfo_flow_head	flow_table[FI_FLOW_NET_INFO_TABLE_SIZE];
	spinlock_t		flow_lock[FI_FLOW_NET_INFO_TABLE_SIZE];
	atomic_t		node_num;
};

extern uint32_t fi_ipv4_flow_netinfo_node_num(void);

extern void fi_ipv4_flow_netinfo_lock(uint32_t index);

extern void fi_ipv4_flow_netinfo_unlock(uint32_t index);

extern uint32_t fi_ipv4_flow_netinfo_hash(__be32 addr1, __u16 port1,
			__be32 addr2, __be16 port2, char *flow, int str_len, bool exchange);

extern struct fi_netinfo_flow_head *fi_ipv4_flow_netinfo_header(uint32_t index);

extern struct fi_netinfo_flow_node *fi_ipv4_flow_netinfo_find(const struct fi_netinfo_flow_head *head,
			__be32 saddr, __u16 sport, __be32 daddr, __be16 dport);

extern struct fi_netinfo_flow_node *fi_ipv4_flow_netinfo_add(struct fi_netinfo_flow_head *head, int32_t uid,
			__be32 saddr, __u16 sport, __be32 daddr, __be16 dport, fi_flow_cb flow_cb,  struct sock *sk);

extern struct fi_netinfo_flow_node *fi_ipv4_flow_netinfo_get(struct fi_netinfo_flow_head *head, int32_t uid,
			__be32 saddr, __u16 sport, __be32 daddr, __be16 dport,
			fi_flow_cb flow_cb, bool addflow, bool *newflow, struct sock *sk);

extern void fi_ipv4_flow_netinfo_age(void);

extern void fi_ipv4_flow_netinfo_clear_node(struct fi_netinfo_flow_node *node);

extern void fi_ipv4_flow_netinfo_clear(void);

extern void fi_ipv4_flow_netinfo_clear_by_uid(int32_t uid);

extern void fi_ipv4_flow_netinfo_init(void);

#if IS_ENABLED(CONFIG_IPV6)
extern uint32_t fi_ipv6_flow_netinfo_node_num(void);

extern void fi_ipv6_flow_netinfo_lock(uint32_t index);

extern void fi_ipv6_flow_netinfo_unlock(uint32_t index);

extern uint32_t fi_ipv6_flow_netinfo_hash(const struct in6_addr *addr1, __u16 port1,
			const struct in6_addr *addr2, __be16 port2, char *flow, int str_len, bool exchange);

extern struct fi_netinfo_flow_head *fi_ipv6_flow_netinfo_header(uint32_t index);

extern struct fi_netinfo_flow_node *fi_ipv6_flow_netinfo_find(const struct fi_netinfo_flow_head *head,
			const struct in6_addr *saddr, __u16 sport,
			const struct in6_addr *daddr, __be16 dport);

extern struct fi_netinfo_flow_node *fi_ipv6_flow_netinfo_add(struct fi_netinfo_flow_head *head, int32_t uid,
			const struct in6_addr *saddr, __u16 sport,
			const struct in6_addr *daddr, __be16 dport, fi_flow_cb flow_cb, struct sock *sk);

extern struct fi_netinfo_flow_node *fi_ipv6_flow_netinfo_get(struct fi_netinfo_flow_head *head, int32_t uid,
			const struct in6_addr *saddr, __u16 sport,
			const struct in6_addr *daddr, __be16 dport,
			fi_flow_cb flow_cb, bool addflow, bool *newflow,  struct sock *sk);

extern void fi_ipv6_flow_netinfo_age(void);

extern void fi_ipv6_flow_netinfo_clear_node(struct fi_netinfo_flow_node *node);

extern void fi_ipv6_flow_netinfo_clear(void);

extern void fi_ipv6_flow_netinfo_clear_by_uid(int32_t uid);

extern void fi_ipv6_flow_netinfo_init(void);
#endif /* CONFIG_IPV6 */

void fi_flow_rtt_update(struct fi_netinfo_flow_node *flow);

void fi_app_netinfo_report(void);

static inline bool fi_flow_app_netinfo_rpt_enable(struct fi_netinfo_flow_node *flow)
{
	return flow->flow_cb.app_info->msg.app_netinfo_rpt;
}
#endif /* _FI_FLOW_NET_INFO_H */
