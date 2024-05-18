/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2022. All rights reserved.
 * Description: This module is flow table for FI
 * Author: yangjingqi
 * Create: 2022-01-29
 */

#include <linux/list.h>
#include <linux/string.h>
#include <linux/timer.h>
#include <linux/types.h>
#include <net/inet6_hashtables.h>
#include <net/inet_sock.h>
#include <net/ip.h>
#include <net/tcp.h>
#include "fi.h"
#include "fi_flow_netinfo.h"
#include "fi_utils.h"

static struct fi_netinfo_flow g_fi_ipv4_flow_netinfo;
#if IS_ENABLED(CONFIG_IPV6)
static struct fi_netinfo_flow g_fi_ipv6_flow_netinfo;
#endif

struct sk_buff *fi_get_netlink_skb(int type, int len, char **data);
void fi_enqueue_netlink_skb(struct sk_buff *pskb);

uint32_t fi_ipv4_flow_netinfo_node_num(void)
{
	return atomic_read(&g_fi_ipv4_flow_netinfo.node_num);
}

void fi_ipv4_flow_netinfo_lock(uint32_t index)
{
	spin_lock_bh(&(g_fi_ipv4_flow_netinfo.flow_lock[index & FI_FLOW_NET_INFO_TABLE_MASK]));
}

void fi_ipv4_flow_netinfo_unlock(uint32_t index)
{
	spin_unlock_bh(&(g_fi_ipv4_flow_netinfo.flow_lock[index & FI_FLOW_NET_INFO_TABLE_MASK]));
}

uint32_t fi_ipv4_flow_netinfo_hash(__be32 addr1, __u16 port1,
			__be32 addr2, __be16 port2, char *flow, int str_len, bool exchange)
{
	int ret;
	static u32 fi_ipv4_flow_secret __read_mostly;

	net_get_random_once(&fi_ipv4_flow_secret, sizeof(fi_ipv4_flow_secret));
	if (exchange) {
		if (flow != NULL) {
			ret = sprintf_s(flow, str_len, "%u%u%u%u", addr2, port2, addr1, port1);
			if (ret == -1) {
				fi_loge("sprintf_s flow err, ret %d", ret);
				flow = NULL;
			}
		}
		return __inet_ehashfn(addr2, port2, addr1, port1, fi_ipv4_flow_secret) & FI_FLOW_NET_INFO_TABLE_MASK;
	}
	if (flow != NULL) {
		ret = sprintf_s(flow, str_len, "%u%u%u%u", addr1, port1, addr2, port2);
		if (ret == -1) {
			fi_loge("sprintf_s flow err, ret %d", ret);
			flow = NULL;
		}
	}
	return __inet_ehashfn(addr1, port1, addr2, port2, fi_ipv4_flow_secret) & FI_FLOW_NET_INFO_TABLE_MASK;
}

inline struct fi_netinfo_flow_head *fi_ipv4_flow_netinfo_header(uint32_t index)
{
	return &(g_fi_ipv4_flow_netinfo.flow_table[index & FI_FLOW_NET_INFO_TABLE_MASK]);
}

bool fi_ipv4_flow_netinfo_same(struct fi_netinfo_flow_node *node, __be32 saddr, __u16 sport, __be32 daddr, __be16 dport)
{
	return (((node->ipv4_saddr == saddr)
			&& (node->ipv4_daddr == daddr)
			&& (node->sport == sport)
			&& (node->dport == dport))
			|| ((node->ipv4_saddr == daddr)
			&& (node->ipv4_daddr == saddr)
			&& (node->sport == dport)
			&& (node->dport == sport)));
}

struct fi_netinfo_flow_node *fi_ipv4_flow_netinfo_find(const struct fi_netinfo_flow_head *head,
			__be32 saddr, __u16 sport, __be32 daddr, __be16 dport)
{
	struct fi_netinfo_flow_node *node = NULL;

	if (head != NULL) {
		list_for_each_entry(node, &(head->list), list) {
			if (fi_ipv4_flow_netinfo_same(node, saddr, sport, daddr, dport)) {
				node->updatetime = jiffies_to_msecs(jiffies);
				return node;
			}
		}
	}
	return NULL;
}

static int fi_flow_ctx_init(struct fi_netinfo_flow_node *newnode, fi_flow_cb *flow_cb)
{
	int ret = memset_s(&newnode->flow_ctx, sizeof(struct fi_netinfo_flow_ctx), 0, sizeof(struct fi_netinfo_flow_ctx));
	if (ret) {
		fi_loge("memset_s failed]ret=%d", ret);
		return ret;
	}
	return ret;
}

struct fi_netinfo_flow_node *fi_ipv4_flow_netinfo_add(struct fi_netinfo_flow_head *head, int32_t uid,
			__be32 saddr, __u16 sport, __be32 daddr, __be16 dport, fi_flow_cb flow_cb, struct sock *sk)
{
	struct fi_netinfo_flow_node *newnode = NULL;
	int ret;
	if (head != NULL) {
		if (atomic_read(&g_fi_ipv4_flow_netinfo.node_num) > FI_FLOW_NET_INFO_NODE_LIMIT) {
			fi_loge("IPV4 flow node out of limited %d", FI_FLOW_NET_INFO_NODE_LIMIT);
			return NULL;
		}
		newnode = (struct fi_netinfo_flow_node *)kzalloc(sizeof(struct fi_netinfo_flow_node), GFP_ATOMIC);
		if (newnode == NULL) {
			fi_loge("failed to malloc new IPV4 node for uid:%d", uid);
			return NULL;
		}
		ret = memset_s(newnode, sizeof(struct fi_netinfo_flow_node), 0, sizeof(struct fi_netinfo_flow_node));
		if (ret) {
			kfree(newnode);
			fi_loge("memset_s failed ret=%d", ret);
			return NULL;
		}
		newnode->ipv4_saddr = saddr;
		newnode->ipv4_daddr = daddr;
		newnode->sport = sport;
		newnode->dport = dport;
		newnode->uid = uid;
		newnode->updatetime = jiffies_to_msecs(jiffies);
		newnode->flow_cb = flow_cb;
		if (fi_flow_ctx_init(newnode, &flow_cb)) {
			fi_loge("fi_flow_ctx_init failed");
			kfree(newnode);
			return NULL;
		}
		if (sk != NULL && (sk->sk_protocol == IPPROTO_TCP || sk->sk_protocol == IPPROTO_UDP)) {
			newnode->sk = sk;
			sock_hold(sk);
		}
		list_add(&(newnode->list), &(head->list));
		atomic_inc(&g_fi_ipv4_flow_netinfo.node_num);
		fi_logd("add a new IPV4 netinfo flow, uid:%d", uid);
	}
	return newnode;
}

struct fi_netinfo_flow_node *fi_ipv4_flow_netinfo_get(struct fi_netinfo_flow_head *head, int32_t uid,
			__be32 saddr, __u16 sport, __be32 daddr, __be16 dport,
			fi_flow_cb flow_cb, bool addflow, bool *newflow, struct sock *sk)
{
	struct fi_netinfo_flow_node *node = NULL;

	if (head != NULL && newflow != NULL) {
		node = fi_ipv4_flow_netinfo_find(head, saddr, sport, daddr, dport);
		if (node != NULL) {
			if (addflow && sk && ((node->flow_ctx.flow_msg.dev_if != sk->sk_bound_dev_if) ||
				(node->sk && sk != node->sk))) {
				fi_logi("dev_if change rebuild flow, uid:%d port[%hu -- %hu] dev_if[%d -- %d]",
					uid, sport, dport, node->flow_ctx.flow_msg.dev_if, sk->sk_bound_dev_if);
				fi_ipv4_flow_netinfo_clear_node(node);
			} else {
				return node;
			}
		}
		if (addflow) {
			if (sk && sk->sk_state >= TCP_FIN_WAIT1 && sk->sk_protocol == IPPROTO_TCP) {
				fi_logd("Ignore flow add:sk_state=%d", sk->sk_state);
				*newflow = false;
				return NULL;
			}
			*newflow = true;
			return fi_ipv4_flow_netinfo_add(head, uid, saddr, sport, daddr, dport, flow_cb, sk);
		}
		*newflow = false;
	}
	return NULL;
}

void fi_ipv4_flow_netinfo_clear_node(struct fi_netinfo_flow_node *node)
{
	list_del(&(node->list));
	if (node->sk != NULL) {
		sock_put(node->sk);
		node->sk = NULL;
	}
	kfree(node);
	node = NULL;
	atomic_dec(&g_fi_ipv4_flow_netinfo.node_num);
}

void fi_ipv4_flow_netinfo_age(void)
{
	uint32_t curtime;
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *node = NULL;
	struct fi_netinfo_flow_node *tmp = NULL;
	int i;

	curtime = jiffies_to_msecs(jiffies);

	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		head = g_fi_ipv4_flow_netinfo.flow_table + i;
		if (list_empty(&(head->list))) {
			continue;
		}
		fi_ipv4_flow_netinfo_lock(i);
		list_for_each_entry_safe(node, tmp, &(head->list), list) {
			if (node->sk && ((node->sk->sk_protocol == IPPROTO_TCP && node->sk->sk_state >= TCP_FIN_WAIT1) ||
				node->flow_ctx.flow_msg.dev_if != node->sk->sk_bound_dev_if ||
				node->sk->sk_err == ECONNABORTED || sock_flag(node->sk, SOCK_DEAD))) {
				fi_logi("age free flow, node->uid=%d [%hu--%hu] uid=%d [%hu--%hu] protocol=%d sk_state=%d flag=%d",
					node->uid, node->sport, node->dport, node->flow_ctx.flow_msg.uid,
					node->flow_ctx.flow_msg.sport, node->flow_ctx.flow_msg.dport,
					node->sk->sk_protocol, node->sk->sk_state, sock_flag(node->sk, SOCK_DEAD));
				fi_ipv4_flow_netinfo_clear_node(node);
			} else if (curtime - node->updatetime > FI_FLOW_NET_INFO_AGING_TIME) {
				fi_ipv4_flow_netinfo_clear_node(node);
			}
		}
		fi_ipv4_flow_netinfo_unlock(i);
	}
	return;
}

void fi_ipv4_flow_netinfo_clear(void)
{
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *node = NULL;
	struct fi_netinfo_flow_node *tmp = NULL;
	int i;

	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		head = g_fi_ipv4_flow_netinfo.flow_table + i;
		if (list_empty(&(head->list))) {
			continue;
		}
		fi_ipv4_flow_netinfo_lock(i);
		list_for_each_entry_safe(node, tmp, &(head->list), list) {
			fi_ipv4_flow_netinfo_clear_node(node);
		}
		fi_ipv4_flow_netinfo_unlock(i);
	}
	return;
}

void fi_ipv4_flow_netinfo_clear_by_uid(int32_t uid)
{
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *node = NULL;
	struct fi_netinfo_flow_node *tmp = NULL;
	int i;

	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		head = g_fi_ipv4_flow_netinfo.flow_table + i;
		if (list_empty(&(head->list))) {
			continue;
		}
		fi_ipv4_flow_netinfo_lock(i);
		list_for_each_entry_safe(node, tmp, &(head->list), list) {
			if (node->uid == uid)
				fi_ipv4_flow_netinfo_clear_node(node);
		}
		fi_ipv4_flow_netinfo_unlock(i);
	}
	return;
}

void fi_ipv4_flow_netinfo_init(void)
{
	int i, ret;

	ret = memset_s(&g_fi_ipv4_flow_netinfo, sizeof(g_fi_ipv4_flow_netinfo), 0, sizeof(g_fi_ipv4_flow_netinfo));
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return;
	}
	atomic_set(&(g_fi_ipv4_flow_netinfo.node_num), 0);
	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		INIT_LIST_HEAD(&(g_fi_ipv4_flow_netinfo.flow_table[i].list));
		spin_lock_init(&(g_fi_ipv4_flow_netinfo.flow_lock[i]));
	}
	return;
}

#if IS_ENABLED(CONFIG_IPV6)
uint32_t fi_ipv6_flow_netinfo_node_num(void)
{
	return atomic_read(&g_fi_ipv6_flow_netinfo.node_num);
}

void fi_ipv6_flow_netinfo_lock(uint32_t index)
{
	spin_lock_bh(&(g_fi_ipv6_flow_netinfo.flow_lock[index & FI_FLOW_NET_INFO_TABLE_MASK]));
}

void fi_ipv6_flow_netinfo_unlock(uint32_t index)
{
	spin_unlock_bh(&(g_fi_ipv6_flow_netinfo.flow_lock[index & FI_FLOW_NET_INFO_TABLE_MASK]));
}

uint32_t fi_ipv6_flow_netinfo_hash(const struct in6_addr *addr1, __u16 port1,
			const struct in6_addr *addr2, __be16 port2, char *flow, int str_len, bool exchange)
{
	int ret;
	static u32 fi_ipv6_flow_secret __read_mostly;
	static u32 fi_ipv6_flow_d_secret __read_mostly;
	u32 hash1;
	u32 hash2;

	net_get_random_once(&fi_ipv6_flow_secret, sizeof(fi_ipv6_flow_secret));
	net_get_random_once(&fi_ipv6_flow_d_secret, sizeof(fi_ipv6_flow_d_secret));
	if (exchange) {
		hash2 = (__force u32)addr2->s6_addr32[3];
		hash1 = __ipv6_addr_jhash(addr1, fi_ipv6_flow_d_secret);
		if (flow != NULL) {
			ret = sprintf_s(flow, str_len, "%u%u%u%u", (__force u32)addr2->s6_addr32[3],
				port2, (__force u32)addr1->s6_addr32[3], port1);
			if (ret == -1) {
				fi_loge("sprintf_s flow err, ret %d", ret);
				flow = NULL;
			}
		}
		return __inet6_ehashfn(hash2, port2, hash1, port1, fi_ipv6_flow_secret) & FI_FLOW_NET_INFO_TABLE_MASK;
	}
	hash1 = (__force u32)addr1->s6_addr32[3];
	hash2 = __ipv6_addr_jhash(addr2, fi_ipv6_flow_d_secret);
	if (flow != NULL) {
		ret = sprintf_s(flow, str_len, "%u%u%u%u", (__force u32)addr1->s6_addr32[3],
			port1, (__force u32)addr2->s6_addr32[3], port2);
		if (ret == -1) {
			fi_loge("sprintf_s flow err, ret %d", ret);
			flow = NULL;
		}
	}
	return __inet6_ehashfn(hash1, port1, hash2, port2, fi_ipv6_flow_secret) & FI_FLOW_NET_INFO_TABLE_MASK;
}

inline struct fi_netinfo_flow_head *fi_ipv6_flow_netinfo_header(uint32_t index)
{
	return &(g_fi_ipv6_flow_netinfo.flow_table[index & FI_FLOW_NET_INFO_TABLE_MASK]);
}

bool fi_ipv6_flow_netinfo_same(struct fi_netinfo_flow_node *node,
						const struct in6_addr *saddr, __u16 sport,
						const struct in6_addr *daddr, __be16 dport)
{
	return ((ipv6_addr_equal((const struct in6_addr *)(&(node->ipv6_saddr)), saddr) &&
			ipv6_addr_equal((const struct in6_addr *)(&(node->ipv6_daddr)), daddr) &&
			node->sport == sport && node->dport == dport) ||
			(ipv6_addr_equal((const struct in6_addr *)(&(node->ipv6_saddr)), daddr) &&
			ipv6_addr_equal((const struct in6_addr *)(&(node->ipv6_daddr)), saddr) &&
			node->sport == dport && node->dport == sport));
}

struct fi_netinfo_flow_node *fi_ipv6_flow_netinfo_find(const struct fi_netinfo_flow_head *head,
			const struct in6_addr *saddr, __u16 sport,
			const struct in6_addr *daddr, __be16 dport)
{
	struct fi_netinfo_flow_node *node = NULL;

	if (saddr != NULL && daddr != NULL && head != NULL) {
		list_for_each_entry(node, &(head->list), list) {
			if (fi_ipv6_flow_netinfo_same(node, saddr, sport, daddr, dport)) {
				node->updatetime = jiffies_to_msecs(jiffies);
				return node;
			}
		}
	}
	return NULL;
}

struct fi_netinfo_flow_node *fi_ipv6_flow_netinfo_add(struct fi_netinfo_flow_head *head, int32_t uid,
			const struct in6_addr *saddr, __u16 sport,
			const struct in6_addr *daddr, __be16 dport, fi_flow_cb flow_cb,  struct sock *sk)
{
	struct fi_netinfo_flow_node *newnode = NULL;
	int ret;

	if (saddr != NULL && daddr != NULL && head != NULL) {
		if (atomic_read(&g_fi_ipv6_flow_netinfo.node_num) > FI_FLOW_NET_INFO_NODE_LIMIT) {
			fi_loge("IPV6 flow node out of limited %d", FI_FLOW_NET_INFO_NODE_LIMIT);
			return NULL;
		}
		newnode = (struct fi_netinfo_flow_node *)kzalloc(sizeof(struct fi_netinfo_flow_node), GFP_ATOMIC);
		if (newnode == NULL) {
			fi_loge("failed to malloc new IPV6 node for uid %d", uid);
			return NULL;
		}
		ret = memset_s(newnode, sizeof(struct fi_netinfo_flow_node), 0, sizeof(struct fi_netinfo_flow_node));
		if (ret) {
			kfree(newnode);
			fi_loge("memset_s failed ret=%d", ret);
			return NULL;
		}

		newnode->ipv6_saddr = *saddr;
		newnode->ipv6_daddr = *daddr;
		newnode->sport = sport;
		newnode->dport = dport;
		newnode->uid = uid;
		newnode->updatetime = jiffies_to_msecs(jiffies);
		newnode->flow_cb = flow_cb;
		if (fi_flow_ctx_init(newnode, &flow_cb)) {
			fi_loge("fi_flow_ctx_init failed");
			kfree(newnode);
			return NULL;
		}

		if (sk != NULL && (sk->sk_protocol == IPPROTO_TCP || sk->sk_protocol == IPPROTO_UDP)) {
			newnode->sk = sk;
			sock_hold(sk);
		}
		list_add(&(newnode->list), &(head->list));
		atomic_inc(&g_fi_ipv6_flow_netinfo.node_num);
	}
	return newnode;
}

struct fi_netinfo_flow_node *fi_ipv6_flow_netinfo_get(struct fi_netinfo_flow_head *head, int32_t uid,
			const struct in6_addr *saddr, __u16 sport,
			const struct in6_addr *daddr, __be16 dport,
			fi_flow_cb flow_cb, bool addflow, bool *newflow, struct sock *sk)
{
	struct fi_netinfo_flow_node *node = NULL;

	if (saddr != NULL && daddr != NULL && head != NULL && newflow != NULL) {
		node = fi_ipv6_flow_netinfo_find(head, saddr, sport, daddr, dport);
		if (node != NULL) {
			if (addflow && sk && ((node->flow_ctx.flow_msg.dev_if != sk->sk_bound_dev_if) ||
				(node->sk && sk != node->sk))) {
				fi_logi("dev_if change rebuild flow, uid:%d port[%hu -- %hu] dev_if[%d -- %d]",
					uid, sport, dport, node->flow_ctx.flow_msg.dev_if, sk->sk_bound_dev_if);
				fi_ipv6_flow_netinfo_clear_node(node);
			} else {
				return node;
			}
		}
		if (addflow) {
			if (sk && sk->sk_state >= TCP_FIN_WAIT1 && sk->sk_protocol == IPPROTO_TCP) {
				fi_logd("Ignore flow add:sk_state=%d", sk->sk_state);
				*newflow = false;
				return NULL;
			}
			*newflow = true;
			return fi_ipv6_flow_netinfo_add(head, uid, saddr, sport, daddr, dport, flow_cb, sk);
		}
		*newflow = false;
	}
	return NULL;
}

void fi_ipv6_flow_netinfo_clear_node(struct fi_netinfo_flow_node *node)
{
	list_del(&(node->list));
	if (node->sk != NULL) {
		sock_put(node->sk);
		node->sk = NULL;
	}
	kfree(node);
	node = NULL;
	atomic_dec(&g_fi_ipv6_flow_netinfo.node_num);
}

void fi_ipv6_flow_netinfo_age(void)
{
	uint32_t curtime;
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *node = NULL;
	struct fi_netinfo_flow_node *tmp = NULL;
	int i;

	curtime = jiffies_to_msecs(jiffies);

	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		head = g_fi_ipv6_flow_netinfo.flow_table + i;
		if (list_empty(&(head->list))) {
			continue;
		}
		fi_ipv6_flow_netinfo_lock(i);
		list_for_each_entry_safe(node, tmp, &(head->list), list) {
			if (node->sk && ((node->sk->sk_protocol == IPPROTO_TCP && node->sk->sk_state >= TCP_FIN_WAIT1) ||
				node->flow_ctx.flow_msg.dev_if != node->sk->sk_bound_dev_if ||
				node->sk->sk_err == ECONNABORTED || sock_flag(node->sk, SOCK_DEAD))) {
				fi_logi("age free flow, node->uid=%d [%hu--%hu] uid=%d [%hu--%hu] protocol=%d sk_state=%d flag=%d",
					node->uid, node->sport, node->dport, node->flow_ctx.flow_msg.uid,
					node->flow_ctx.flow_msg.sport, node->flow_ctx.flow_msg.dport,
					node->sk->sk_protocol, node->sk->sk_state, sock_flag(node->sk, SOCK_DEAD));
				fi_ipv6_flow_netinfo_clear_node(node);
			} else if (curtime - node->updatetime > FI_FLOW_NET_INFO_AGING_TIME) {
				fi_ipv6_flow_netinfo_clear_node(node);
			}
		}
		fi_ipv6_flow_netinfo_unlock(i);
	}
	return;
}

void fi_ipv6_flow_netinfo_clear(void)
{
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *node = NULL;
	struct fi_netinfo_flow_node *tmp = NULL;
	int i;

	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		head = g_fi_ipv6_flow_netinfo.flow_table + i;
		if (list_empty(&(head->list))) {
			continue;
		}
		fi_ipv6_flow_netinfo_lock(i);
		list_for_each_entry_safe(node, tmp, &(head->list), list) {
			fi_ipv6_flow_netinfo_clear_node(node);
		}
		fi_ipv6_flow_netinfo_unlock(i);
	}
	return;
}

void fi_ipv6_flow_netinfo_clear_by_uid(int32_t uid)
{
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *node = NULL;
	struct fi_netinfo_flow_node *tmp = NULL;
	int i;

	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		head = g_fi_ipv6_flow_netinfo.flow_table + i;
		if (list_empty(&(head->list))) {
			continue;
		}
		fi_ipv6_flow_netinfo_lock(i);
		list_for_each_entry_safe(node, tmp, &(head->list), list) {
			if (node->uid == uid)
				fi_ipv6_flow_netinfo_clear_node(node);
		}
		fi_ipv6_flow_netinfo_unlock(i);
	}
	return;
}

void fi_ipv6_flow_netinfo_init(void)
{
	int i, ret;

	ret = memset_s(&g_fi_ipv6_flow_netinfo, sizeof(g_fi_ipv6_flow_netinfo), 0, sizeof(g_fi_ipv6_flow_netinfo));
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return;
	}

	atomic_set(&(g_fi_ipv6_flow_netinfo.node_num), 0);
	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		INIT_LIST_HEAD(&(g_fi_ipv6_flow_netinfo.flow_table[i].list));
		spin_lock_init(&(g_fi_ipv6_flow_netinfo.flow_lock[i]));
	}
	return;
}
#endif

void fi_flow_rtt_update(struct fi_netinfo_flow_node *flow)
{
	unsigned long now_jiffies = jiffies;
	u64 now_mstamp = tcp_clock_us();
	struct tcp_sock *tp = NULL;
	uint32_t srtt;
	unsigned long srtt_time;
	u64 rcv_rtt_time;
	u32 delta_us;

	if ((flow->sk == NULL) || (flow->sk->sk_protocol != IPPROTO_TCP)
		|| (flow->sk->sk_state != TCP_ESTABLISHED && flow->sk->sk_state != TCP_SYN_SENT))
		return;

	tp = tcp_sk(flow->sk);
	srtt = tp->srtt_us >> FI_RTT_SHIFT;
	srtt_time = tp->rcv_tstamp;
	rcv_rtt_time = tp->rcv_rtt_est.time;
	fi_logd("sport %u now %lu srtt_time %lu srtt %u now_mstamp %ju rcv_rtt_time %ju rcv_rtt %u",
			flow->sk->sk_num, now_jiffies, srtt_time, srtt, now_mstamp, rcv_rtt_time, tp->rcv_rtt_est.rtt_us);
	fi_logd("updatetime %u tcp_mstamp %ju mdev_max_us %u rttvar_us %u total_retrans %u retrans_stamp %u",
			flow->updatetime, tp->tcp_mstamp, tp->mdev_us, tp->rttvar_us, tp->total_retrans, tp->retrans_stamp);
	/* SYN TIMEOUT */
	if (flow->sk->sk_state == TCP_SYN_SENT && tp->total_retrans > 0) {
		if (!strncmp(FI_CELL0_IFNAME, flow->flow_ctx.flow_msg.dev, strlen(flow->flow_ctx.flow_msg.dev)) ||
			!strncmp(FI_CELL1_IFNAME, flow->flow_ctx.flow_msg.dev, strlen(flow->flow_ctx.flow_msg.dev)))
			flow->flow_ctx.flow_app_info.rtt = tp->total_retrans * USEC_PER_SEC;
		else
			flow->flow_ctx.flow_app_info.rtt = 0;
		fi_logi("syn time out, set rtt = %u", flow->flow_ctx.flow_app_info.rtt);
		return;
	}
	if (tp->rcv_rtt_est.rtt_us == 0) {
		flow->flow_ctx.flow_app_info.rtt = srtt;
		return;
	}
	delta_us = tcp_stamp_us_delta(now_mstamp, rcv_rtt_time);
	/*lint -e666*/
	if (time_before(now_jiffies, srtt_time + msecs_to_jiffies(MSEC_PER_SEC)) ||
			time_before(now_jiffies, srtt_time + usecs_to_jiffies(delta_us)) || srtt < tp->rcv_rtt_est.rtt_us)
		flow->flow_ctx.flow_app_info.rtt = srtt;
	else
		flow->flow_ctx.flow_app_info.rtt = tp->rcv_rtt_est.rtt_us;
	/*lint +e666*/
}

void fi_ip_app_netinfo_flow_stat_clear(const struct fi_flow *flow,
	void (*flow_lock)(uint32_t),
	void (*flow_unlock)(uint32_t))
{
	int i;
	struct fi_netinfo_flow_node *node = NULL;
	struct fi_netinfo_flow_node *tmp = NULL;
	// get average rtt
	for (i = 0; i < FI_FLOW_TABLE_SIZE; i++) {
		if (list_empty(&(flow->flow_table[i].list))) {
			continue;
		}
		(*flow_lock)(i);
		list_for_each_entry_safe(node, tmp, &(flow->flow_table[i].list), list) {
			memset_s(&node->flow_ctx.flow_app_info,
				sizeof(struct fi_flow_app_info_stat), 0, sizeof(struct fi_flow_app_info_stat));

		}
		(*flow_unlock)(i);
	}
	return;
}

int fi_app_netinfo_msg(char *data, uint32_t size, int index)
{
	int ret;
	int i = 0;
	//int rtt_ipv4 = 0;
	int rtt_cnt = 0;
	struct fi_app_stat_report *app_report = (struct fi_app_stat_report *)data;
	struct fi_app_stat_msg *app_msg = &app_report->app_stat_msg;
	struct fi_app_netinfo *app_net_info = NULL;

	spin_lock_bh(&g_fi_ctx.app_stat_lock);
	app_net_info = &g_fi_ctx.app_net_info[index];
	app_net_info->app_stat_report.pri_dev = fi_get_primary_dev();
	rtt_cnt = app_net_info->app_stat_ctx.rtt_cnt;
	ret = memcpy_s(app_report, size, &app_net_info->app_stat_report, sizeof(struct fi_app_stat_report));
	if (ret) {
		spin_unlock_bh(&g_fi_ctx.app_stat_lock);
		fi_loge("memcpy_s failed ret=%d", ret);
		return -1;
	}
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		memset_s(&app_net_info->app_stat_ctx, sizeof(struct fi_app_stat_ctx),
			0, sizeof(struct fi_app_stat_ctx));
		memset_s(&app_net_info->app_stat_report.app_stat_msg, sizeof(struct fi_app_stat_msg),
			0, sizeof(struct fi_app_stat_msg));
	}
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		app_net_info->app_stat_ctx.dns_ctx.timer_counter = FI_APP_INFO_DNS_TIMER_COUNTER_INVALID;
	}
	spin_unlock_bh(&g_fi_ctx.app_stat_lock);

	app_msg->uplink_pkt_num = app_msg->uplink_tcp_num + app_msg->uplink_udp_num ;
	app_msg->dlink_pkt_num = app_msg->dlink_tcp_num + app_msg->dlink_udp_num;
	app_msg->socket_num = fi_ipv4_flow_netinfo_node_num();

	if (app_msg->dlink_tcp_num == 0)
		app_msg->dlink_retrans_rate = 0;
	else if (app_msg->dlink_tcp_num <= app_msg->dlink_retrans_num)
		app_msg->dlink_retrans_rate = FI_PERCENTAGE_100;
	else
		app_msg->dlink_retrans_rate = app_msg->dlink_retrans_num * FI_PERCENTAGE_100 / app_msg->dlink_tcp_num;

	if (app_msg->uplink_tcp_num == 0)
		app_msg->uplink_retrans_rate = 0;
	else if (app_msg->uplink_tcp_num <= app_msg->uplink_retrans_num)
		app_msg->uplink_retrans_rate = FI_PERCENTAGE_100;
	else
		app_msg->uplink_retrans_rate = app_msg->uplink_retrans_num * FI_PERCENTAGE_100 / app_msg->uplink_tcp_num;

	if (rtt_cnt)
		app_msg->avr_rtt = app_msg->avr_rtt / rtt_cnt;

#if IS_ENABLED(CONFIG_IPV6)
	app_msg->socket_num += fi_ipv6_flow_netinfo_node_num();
#endif

	fi_logi("HiHonorQoECollectData, dnsSuccCount:%u, dnsFailCount:%u, dnsAvgDelay:%u, httpGetCount:%u,"
		" uplinkPktNum:%u, dlinkPktNum:%u, rtt:%u, dlinkTcpPktNum:%u, dlinkTcpPktLen:%u, uplinkTcpPktNum:%u, uplinkTcpPktLen:%u,"
		" dlinkUdpPktNum:%u, dlinkUdpPktLen:%u, uplinkUdpPktNum:%u, uplinkUdpPktLen:%u, dlinkRetransNum:%u, uplinkRetransNum:%u, sockNum:%u, synNum:%u.",
		app_msg->dns_succ_count, app_msg->dns_fail_count, app_msg->dns_avg_delay, app_msg->http_get_count,
		app_msg->uplink_pkt_num, app_msg->dlink_pkt_num, app_msg->avr_rtt, app_msg->dlink_tcp_num,
		app_msg->dlink_tcp_len, app_msg->uplink_tcp_num, app_msg->uplink_tcp_len,
		app_msg->dlink_udp_num, app_msg->dlink_udp_len, app_msg->uplink_udp_num,
		app_msg->uplink_udp_len, app_msg->dlink_retrans_num, app_msg->uplink_retrans_num,
		app_msg->socket_num, app_msg->syn_num);

	return 0;
}

void fi_app_netinfo_report(void)
{
	uint32_t size;
	char *data = NULL;
	struct sk_buff *pskb = NULL;
	int i = 0;
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		if (!g_fi_ctx.app_netinfo_rpt_enable[i]) {
			continue;
		}
		fi_dns_statistic();
		size = sizeof(struct fi_app_stat_report);
		pskb = fi_get_netlink_skb(FI_APP_MSG_RPT, size, &data);
		if (pskb == NULL) {
			fi_loge("failed to malloc memory for data");
			continue;
		}
		if (fi_app_netinfo_msg(data, size, i) != 0) {
			kfree_skb(pskb);
			continue;
		}

		fi_enqueue_netlink_skb(pskb);
	}
	return;
}

