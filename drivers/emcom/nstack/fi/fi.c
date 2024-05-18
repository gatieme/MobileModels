/*
 * Copyright (c) Honor Device Co., Ltd. 2019-2020. All rights reserved.
 * Description: This module is to collect IP package parameters
 * Author: songqiubin songqiubin.
 * Create: 2019-09-18
 */

#include "fi.h"
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/netdevice.h>
#include <linux/tcp.h>
#include <linux/timer.h>
#include <linux/udp.h>
#include <linux/version.h>
#include <linux/skbuff.h>
#include <net/net_namespace.h>
#include <net/sock.h>
#include <net/tcp.h>
#include <net/udp.h>

struct fi_ctx g_fi_ctx;
static struct fi_app_info_table g_fi_app_info;
static uint64_t g_fi_iface_bytes[FI_DEV_NUM];

void fi_qos_update(const struct sk_buff *skb, struct fi_flow_node *flow);
void fi_filesize_update(const struct sk_buff *skb, struct fi_flow_node *flow);
void fi_iface_report(void);

static unsigned int fi_ipv4_hook_out(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state);

static unsigned int fi_ipv4_hook_in(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state);

#if IS_ENABLED(CONFIG_IPV6)
static unsigned int fi_ipv6_hook_out(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state);

static unsigned int fi_ipv6_hook_in(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state);
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
	static const struct nf_hook_ops fi_nfhooks[] = {
#else
	static struct nf_hook_ops fi_nfhooks[] = {
#endif
	{
		.hook = fi_ipv4_hook_out,
		.pf = PF_INET,
		.hooknum = NF_INET_LOCAL_OUT,
		.priority = NF_IP_PRI_FILTER - 1,
	},
	{
		.hook = fi_ipv4_hook_in,
		.pf = PF_INET,
		.hooknum = NF_INET_LOCAL_IN,
		.priority = NF_IP_PRI_FILTER - 1,
	},
#if IS_ENABLED(CONFIG_IPV6)
	{
		.hook = fi_ipv6_hook_out,
		.pf = PF_INET6,
		.hooknum = NF_INET_LOCAL_OUT,
		.priority = NF_IP_PRI_FILTER - 1,
	},
	{
		.hook = fi_ipv6_hook_in,
		.pf = PF_INET6,
		.hooknum = NF_INET_LOCAL_IN,
		.priority = NF_IP_PRI_FILTER - 1,
	},
#endif
};

void fi_register_nfhook(void)
{
	int ret;
	int i;
	struct net_device *dev = NULL;
	char *iface = NULL;
	struct rtnl_link_stats64 stats;

	mutex_lock(&(g_fi_ctx.nf_mutex));
	if (g_fi_ctx.nf_exist) {
		mutex_unlock(&(g_fi_ctx.nf_mutex));
		return;
	}
	local_irq_disable();
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
	ret = nf_register_net_hooks(&init_net, fi_nfhooks, ARRAY_SIZE(fi_nfhooks));
#else
	ret = nf_register_hooks(fi_nfhooks, ARRAY_SIZE(fi_nfhooks));
#endif
	local_irq_enable();
	if (ret == 0) {
		g_fi_ctx.nf_exist = true;
		g_fi_ctx.tm.expires = jiffies + HZ / FI_TIMER_INTERVAL;
		if (!timer_pending(&(g_fi_ctx.tm)))
			add_timer(&(g_fi_ctx.tm));
		else
			fi_loge("timer_pending, not need to add again");
	}
	mutex_unlock(&(g_fi_ctx.nf_mutex));
	for (i = 0; i < FI_DEV_NUM; i++) {
		iface = emcom_xengine_get_network_iface_name(i);
		dev = dev_get_by_name(&init_net, iface);
		if (dev == NULL) {
			/* clear g_fi_iface_bytes if dev is off */
			g_fi_iface_bytes[i] = 0;
			fi_logi(" can't find dev %s", iface);
			continue;
		}
		read_lock(&dev_base_lock);
		dev_get_stats(dev, &stats);
		read_unlock(&dev_base_lock);
		dev_put(dev);
		g_fi_iface_bytes[i] = stats.rx_bytes;
		fi_logi("init ifname: %s, total_byes: %lu", iface, stats.rx_bytes);
	}
	spin_lock_bh(&(g_fi_ctx.app_stat_lock));
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		memset_s(&g_fi_ctx.app_net_info[i].app_stat_ctx, sizeof(struct fi_app_stat_ctx),
			0, sizeof(struct fi_app_stat_ctx));
		memset_s(&g_fi_ctx.app_net_info[i].app_stat_report.app_stat_msg, sizeof(struct fi_app_stat_msg),
			0, sizeof(struct fi_app_stat_msg));
	}
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		g_fi_ctx.app_net_info[i].app_stat_ctx.dns_ctx.timer_counter = FI_APP_INFO_DNS_TIMER_COUNTER_INVALID;
	}
	spin_unlock_bh(&(g_fi_ctx.app_stat_lock));
	if (ret == 0)
		fi_logi("FI register nf hooks successfully");
	else
		fi_loge("FI register nf hooks failed, ret:%d", ret);
}

void fi_unregister_nfhook(void)
{
	mutex_lock(&(g_fi_ctx.nf_mutex));
	if (!g_fi_ctx.nf_exist) {
		mutex_unlock(&(g_fi_ctx.nf_mutex));
		return;
	}

	local_irq_disable();
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 1)
	nf_unregister_net_hooks(&init_net, fi_nfhooks, ARRAY_SIZE(fi_nfhooks));
#else
	nf_unregister_hooks(fi_nfhooks, ARRAY_SIZE(fi_nfhooks));
#endif
	local_irq_enable();

	g_fi_ctx.nf_exist = false;
	del_timer_sync(&(g_fi_ctx.tm));
	fi_ipv4_flow_clear();
	fi_ipv4_flow_netinfo_clear();
#if IS_ENABLED(CONFIG_IPV6)
	fi_ipv6_flow_clear();
	fi_ipv6_flow_netinfo_clear();
#endif
	mutex_unlock(&(g_fi_ctx.nf_mutex));
	fi_logi("FI unregister nf hooks successfully");
}

void fi_dns_statistic()
{
	int i;
	uint64_t timestamp;

	struct fi_app_stat_msg *app_stat = NULL;
	struct fi_app_stat_ctx *app_ctx  = NULL;

	spin_lock_bh(&g_fi_ctx.app_stat_lock);
	app_stat = &g_fi_ctx.app_net_info[g_fi_ctx.index].app_stat_report.app_stat_msg;
	app_ctx = &g_fi_ctx.app_net_info[g_fi_ctx.index].app_stat_ctx;
	if (app_ctx->dns_ctx.timer_counter >= 0) {
		app_ctx->dns_ctx.timer_counter++;
		timestamp = jiffies_to_msecs(jiffies);
		if (app_ctx->dns_ctx.num > FI_APP_INFO_DNS_BUFFER_NUM)
			app_ctx->dns_ctx.num = 0;
		i = 0;
		while (i < app_ctx->dns_ctx.num) {
			if (timestamp - app_ctx->dns_ctx.req_timestamp[i] > FI_APP_INFO_DNS_TIME_OUT) {
				fi_loge("fi_dns_statitic dns fail tid:%u", app_ctx->dns_ctx.tid[i]);
				app_ctx->dns_ctx.req_timestamp[i] = app_ctx->dns_ctx.req_timestamp[app_ctx->dns_ctx.num - 1];
				app_ctx->dns_ctx.tid[i] = app_ctx->dns_ctx.tid[app_ctx->dns_ctx.num - 1];
				app_ctx->dns_ctx.num--;
				app_stat->dns_fail_count++;
			} else {
				i++;
			}
		}
		if (app_ctx->dns_ctx.timer_counter > FI_APP_INFO_DNS_TIMER_EXPIRE || app_ctx->dns_ctx.num == 0) {
			app_ctx->dns_ctx.timer_counter = FI_APP_INFO_DNS_TIMER_COUNTER_INVALID;
			app_ctx->dns_ctx.num = 0;
		}
	}
	if (app_stat->dns_succ_count)
		app_stat->dns_avg_delay = (uint32_t)(app_ctx->dns_ctx.total_delay / app_stat->dns_succ_count);
	spin_unlock_bh(&g_fi_ctx.app_stat_lock);
}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
void fi_timer(struct timer_list *arg)
#else
void fi_timer(unsigned long arg)
#endif
{
	fi_flow_periodic_report();
	fi_flow_qos_report();
	fi_iface_report();
	fi_app_netinfo_report();
	fi_ipv4_flow_netinfo_age();
	fi_ipv4_flow_age();
#if IS_ENABLED(CONFIG_IPV6)
	fi_ipv6_flow_netinfo_age();
	fi_ipv6_flow_age();
#endif
	mod_timer(&(g_fi_ctx.tm), jiffies + HZ / FI_TIMER_INTERVAL);
}

static inline bool fi_payloadlen_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static inline bool fi_tcpseq_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static inline bool fi_tcpack_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static inline bool fi_tcpflags_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static inline bool fi_tcpwindowsize_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static inline bool fi_tcpoptions_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static inline bool fi_payload_segment_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static inline bool fi_payload_seq_parse(struct fi_pkt_parse *pktinfo);
static inline bool fi_tcp_hole_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow);
static void fi_update_frags_and_loss(struct fi_flow_node *flow, struct fi_pkt_parse *pktinfo);

static struct fi_pkt_parse_f g_fi_pkt_parse_f[] = {
	{FI_PAYLOADLEN_PARSE,		fi_payloadlen_parse},
	{FI_PAYLOAD_SEGMENT_PARSE,	fi_payload_segment_parse},
	{FI_ECHO_DELAY,				NULL},
	{FI_TCPSEQ_PARSE,			fi_tcpseq_parse},
	{FI_TCPACK_PARSE,			fi_tcpack_parse},
	{FI_TCPFLAGS_PARSE,			fi_tcpflags_parse},
	{FI_TCPWINDOWSIZE_PARSE,	fi_tcpwindowsize_parse},
	{FI_TCPOPTIONS_PARSE,		fi_tcpoptions_parse},
	{FI_LOSS_CNT_PARSE,			NULL},
	{FI_TCP_HOLE_PARSE,			fi_tcp_hole_parse},
	{FI_END_PARSE,				NULL},
};

static void fi_payload_parse(struct fi_flow_node *flow, struct sk_buff *skb, struct fi_pkt_parse *pktinfo)
{
	const skb_frag_t *frag = NULL;
	int transport_len = 0;
	int tmpNum = 1;
	struct sk_buff *frag_list = NULL;
	int i = 0;
	int j = 0;
	pktinfo->is_gso = false;

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_UDP)
		transport_len = sizeof(struct udphdr);
	else
		transport_len = tcp_hdrlen(skb);

	/* step1: Point to the linear region */
	if (skb_headlen(skb) > skb_transport_offset(skb) + transport_len) {
		pktinfo->payloadlen = skb_headlen(skb) -
			skb_transport_offset(skb) - transport_len;
		pktinfo->payload = skb_transport_header(skb) + transport_len;
		fi_update_frags_and_loss(flow, pktinfo);
	}
	/* step2: Point to the fragList region */
	if (skb_shinfo(skb)->frag_list != NULL) {
		frag_list = skb_shinfo(skb)->frag_list;
		pktinfo->is_gso = true;
		while (frag_list && pktinfo->raw_frag_num < FI_SKB_MAX_FRAG_LIST_NUM) {
			pktinfo->payloadlen = skb_headlen(frag_list);
			pktinfo->payload = frag_list->data;
			frag_list = frag_list->next;
			fi_update_frags_and_loss(flow, pktinfo);
		}
	}
	/* step3: Point to the frags */
	if (skb_shinfo(skb)->nr_frags) {
	/* Copy paged appendix. Decentralized aggregation IO model and UDP GSO adapt*/
		for (i = 0; i < skb_shinfo(skb)->nr_frags && i < MAX_SKB_FRAGS; i++) {
			frag = (const skb_frag_t *)(&skb_shinfo(skb)->frags[i]);
			if (!skb_is_gso(skb)) {
				pktinfo->payloadlen = skb_frag_size(frag);
				pktinfo->payload = skb_frag_address_safe(frag);
				fi_update_frags_and_loss(flow, pktinfo);
			} else if (skb_frag_size(frag) >= skb_shinfo(skb)->gso_size) {
				pktinfo->is_gso = true;
				tmpNum = skb_frag_size(frag) / skb_shinfo(skb)->gso_size;
				for (j = 0; j < tmpNum; j++) {
					pktinfo->payloadlen = skb_shinfo(skb)->gso_size;
					pktinfo->payload = skb_frag_address_safe(frag) + j * skb_shinfo(skb)->gso_size;
					fi_update_frags_and_loss(flow, pktinfo);
				}
				if (skb_frag_size(frag) % skb_shinfo(skb)->gso_size) {
					pktinfo->payloadlen = skb_frag_size(frag) % skb_shinfo(skb)->gso_size;
					pktinfo->payload = skb_frag_address_safe(frag) +
						(skb_frag_size(frag) / skb_shinfo(skb)->gso_size) * skb_shinfo(skb)->gso_size;
					if (pktinfo->payload - (char*)skb_frag_address_safe(frag) + pktinfo->payloadlen >
						skb_frag_size(frag)) {
						pktinfo->payloadlen = skb_frag_size(frag);
						pktinfo->payload = skb_frag_address_safe(frag);
					}
					fi_update_frags_and_loss(flow, pktinfo);
				}
			}
		}
	}
	if (pktinfo->is_gso
		&& pktinfo->filter_payload != NULL
		&& pktinfo->filter_payloadlen != 0) {
		pktinfo->payload = pktinfo->filter_payload;
		pktinfo->payloadlen = pktinfo->filter_payloadlen;
	}
}

static bool fi_payloadlen_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_UDP) {
		if (skb->len > skb_transport_offset(skb) + sizeof(struct udphdr))
			pktinfo->msg.payloadlen = skb->len -
				skb_transport_offset(skb) - sizeof(struct udphdr);
		else
			pktinfo->msg.payloadlen = 0;
	} else {
		if (skb->len > skb_transport_offset(skb) + tcp_hdrlen(skb))
			pktinfo->msg.payloadlen = skb->len - skb_transport_offset(skb) - tcp_hdrlen(skb);
		else
			pktinfo->msg.payloadlen = 0;
	}
	return true;
}

static bool fi_tcpseq_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	struct tcphdr *tcph = NULL;

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP) {
		tcph = tcp_hdr(skb);
		pktinfo->msg.tcp_seq = ntohl(tcph->seq);
		return true;
	}
	return true;
}

static bool fi_tcpack_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	struct tcphdr *tcph = NULL;

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP) {
		tcph = tcp_hdr(skb);
		pktinfo->msg.tcp_ack = ntohl(tcph->ack_seq);
		return true;
	}
	return true;
}

static bool fi_tcpflags_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	struct tcphdr *tcph = NULL;

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP) {
		tcph = tcp_hdr(skb);
		pktinfo->msg.tcp_flags |= tcph->fin;
		pktinfo->msg.tcp_flags |= tcph->syn << 1;
		pktinfo->msg.tcp_flags |= tcph->rst << 2;
		pktinfo->msg.tcp_flags |= tcph->psh << 3;
		pktinfo->msg.tcp_flags |= tcph->ack << 4;
		pktinfo->msg.tcp_flags |= tcph->urg << 5;
		pktinfo->msg.tcp_flags |= tcph->ece << 6;
		pktinfo->msg.tcp_flags |= tcph->cwr << 7;
		return true;
	}
	return true;
}

static bool fi_tcpwindowsize_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	struct tcphdr *tcph = NULL;

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP) {
		tcph = tcp_hdr(skb);
		pktinfo->msg.tcp_window = ntohs(tcph->window);
		return true;
	}
	return true;
}

static bool fi_tcpoptions_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	unsigned int optionslen;
	int ret;

	if (pktinfo->msg.flow_msg.l4proto != IPPROTO_TCP)
		return true;
	if (tcp_hdrlen(skb) <= sizeof(struct tcphdr))
		return true;
	optionslen = tcp_hdrlen(skb) - sizeof(struct tcphdr);
	if (optionslen > FI_TCP_OPTIONS_LEN)
		return false;
	ret = memcpy_s(pktinfo->msg.tcp_options, FI_TCP_OPTIONS_LEN,
		(char *)(skb_transport_header(skb) + sizeof(struct tcphdr)), optionslen);
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return false;
	}

	return true;
}

static int fi_tcp_seq_minus(u32 seq1, u32 seq2)
{
	return (s32)(seq1-seq2);
}

static bool fi_tcp_hole_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	u32 cur_last_byte_seq;
	if (pktinfo->dir != FI_DIR_DOWN) {
		return false;
	}

	if (!flow->flow_ctx.flow_tcp_init) {
		flow->flow_ctx.expect_tcp_seq = pktinfo->msg.tcp_seq;
		flow->flow_ctx.flow_tcp_init = true;
	}
	if (after(pktinfo->msg.tcp_seq, flow->flow_ctx.expect_tcp_seq)) {
		flow->flow_ctx.flow_stat.total_tcp_hole += fi_tcp_seq_minus(pktinfo->msg.tcp_seq, flow->flow_ctx.expect_tcp_seq);
	}

	if (!flow->flow_ctx.flow_tcp_period_init) {
		flow->flow_ctx.flow_stat.min_tcp_seq = flow->flow_ctx.expect_tcp_seq;
		flow->flow_ctx.flow_stat.max_tcp_seq = flow->flow_ctx.expect_tcp_seq;
		flow->flow_ctx.flow_tcp_period_init = true;
	}

	cur_last_byte_seq = pktinfo->msg.tcp_seq + pktinfo->msg.payloadlen; // tcp seq wrap around compatible
	if (pktinfo->msg.tcp_flags & (TCPHDR_SYN | TCPHDR_FIN)) {
		cur_last_byte_seq += 1;
	}
	if (after(pktinfo->msg.tcp_seq, flow->flow_ctx.expect_tcp_seq) || pktinfo->msg.tcp_seq == flow->flow_ctx.expect_tcp_seq) {
		flow->flow_ctx.expect_tcp_seq = cur_last_byte_seq;
	}

	if (after(cur_last_byte_seq, flow->flow_ctx.flow_stat.max_tcp_seq)) {
		flow->flow_ctx.flow_stat.max_tcp_seq = cur_last_byte_seq;
	}
	return true;
}

static bool fi_payload_segment_parse(struct sk_buff *skb, struct fi_pkt_parse *pktinfo, struct fi_flow_node *flow)
{
	int ret;
	__be16 payloadlen = 0;
	uint32_t offset;
	char *payload = NULL;
	fi_flow_identify_cfg *flow_cfg = pktinfo->flow_cb.flow_identify_cfg;

	payload = pktinfo->payload;
	payloadlen = pktinfo->payloadlen;

	if (payloadlen == 0 || payload == NULL)
		return true;
	if (flow_cfg->pkt[pktinfo->dir].seg_begin >= payloadlen)
		return true;
	offset = flow_cfg->pkt[pktinfo->dir].seg_end - flow_cfg->pkt[pktinfo->dir].seg_begin + 1;
	if (flow_cfg->pkt[pktinfo->dir].seg_end >= payloadlen)
		offset = payloadlen - flow_cfg->pkt[pktinfo->dir].seg_begin;
	ret = memcpy_s(pktinfo->msg.payload_seg, sizeof(pktinfo->msg.payload_seg),
		payload + flow_cfg->pkt[pktinfo->dir].seg_begin, offset);
	if (ret) {
		fi_loge("memcpy_s failed ret=%d, len=%u", ret, offset);
		return false;
	}
	fi_logd("get payload_seg len=%u, payloadlen=%d begin=%u end=%u", offset,
		payloadlen, flow_cfg->pkt[pktinfo->dir].seg_begin, flow_cfg->pkt[pktinfo->dir].seg_end);
	return true;
}

static uint16_t fi_dns_transaction_id_parse(struct sk_buff *skb)
{
	__be16 payloadlen = 0;
	char *payload = NULL;
	const skb_frag_t *frag = NULL;
	int transport_len = 0;
	struct sk_buff *frag_list = NULL;
	uint16_t tid = 0;

	transport_len = sizeof(struct udphdr);
	if (skb_headlen(skb) > skb_transport_offset(skb) + transport_len) {
		/* step1: Point to the linear region */
		payloadlen = skb_headlen(skb) - skb_transport_offset(skb) - transport_len;
		payload = skb_transport_header(skb) + transport_len;
	} else if (skb_shinfo(skb)->frag_list != NULL) {
		/* step2: Point to the fragList region */
		frag_list = skb_shinfo(skb)->frag_list;
		payloadlen = skb_headlen(frag_list);
		payload = frag_list->data;
	} else if (skb_shinfo(skb)->nr_frags) {
		/* step3: Point to the frags */
		frag = (const skb_frag_t *)(&skb_shinfo(skb)->frags[0]);
		payloadlen = skb_frag_size(frag);
		payload = skb_frag_address_safe(frag);
	}

	if (payload == NULL) {
		return INVALID_TID;
	}

	if (payloadlen > 2) {
		tid = payload[0]<<8 | payload[1];
	}
	return tid;
}

static inline bool fi_payload_seq_parse(struct fi_pkt_parse *pktinfo)
{
	__be16 payloadlen = 0;
	char *payload = NULL;
	fi_flow_identify_cfg *flow_cfg = pktinfo->flow_cb.flow_identify_cfg;

	payload = pktinfo->payload;
	payloadlen = pktinfo->payloadlen;
	if (payloadlen == 0)
		return false;

	if (flow_cfg->periodic[pktinfo->dir].spec_seq_high >= payloadlen)
		return false;
	if (flow_cfg->periodic[pktinfo->dir].spec_seq_low >= payloadlen)
		return false;

	pktinfo->msg.seq_curr = MAKE_SEQ_NUM(payload[flow_cfg->periodic[pktinfo->dir].spec_seq_high],
		payload[flow_cfg->periodic[pktinfo->dir].spec_seq_low]);

	return true;
}

static bool inline fi_seq_circular_check(int seq_low, int seq_high)
{
	if ((seq_low <= FI_MAX_SEQ_NUM) &&
		(seq_low > FI_MAX_SEQ_NUM - FI_MAX_PKT_NUM_PER_PERIOD) &&
		(seq_high < FI_MAX_PKT_NUM_PER_PERIOD))
		return true;
	return false;
}

static int fi_get_max_seq(int seq1, int seq2)
{
	if (fi_seq_circular_check(seq1, seq2))
		return seq2;
	if (fi_seq_circular_check(seq2, seq1))
		return seq1;
	return fi_max(seq1, seq2);
}

static int fi_get_min_seq(int seq1, int seq2)
{
	if (fi_seq_circular_check(seq1, seq2))
		return seq1;
	if (fi_seq_circular_check(seq2, seq1))
		return seq2;
	return fi_min(seq1, seq2);
}

static bool fi_seq_is_increase(int last_seq, int curr_seq)
{
	if (curr_seq >= last_seq)
		return true;
	else {
		if ((last_seq <= FI_MAX_SEQ_NUM) &&
			(last_seq > FI_MAX_SEQ_NUM - FI_MAX_PKT_NUM_PER_PERIOD) &&
			(curr_seq < FI_MAX_PKT_NUM_PER_PERIOD))
			return true;
		else
			return false;
	}
}

static void fi_update_frags_and_loss(struct fi_flow_node *flow, struct fi_pkt_parse *pktinfo)
{
	struct fi_flow_stat *flow_stat = &flow->flow_ctx.flow_stat;
	struct fi_flow_ctx *flow_ctx = &flow->flow_ctx;
	fi_rpt_cfg *periodic_cfg = NULL;
	uint16_t loss_cnt = 0;

	pktinfo->raw_frag_num++;
	periodic_cfg = &pktinfo->flow_cb.flow_identify_cfg->periodic[pktinfo->dir];
	if (fi_payload_len_filter_check(pktinfo->msg.payloadlen,
		periodic_cfg->filter_pkt_size_start, periodic_cfg->filter_pkt_size_stop)
		&& fi_payload_str_filter_check(pktinfo, periodic_cfg)) {
		pktinfo->filter_frag_num++;
		pktinfo->filter_payloadlen = pktinfo->payloadlen;
		pktinfo->filter_payload = pktinfo->payload;

		if (pktinfo->dir != FI_DIR_DOWN)
			return;
		if (!periodic_cfg->opt_enable[FI_LOSS_CNT_PARSE])
			return;
		if (!fi_payload_seq_parse(pktinfo))
			return;

		if (flow_stat->down_seq_max == FI_INVALID_SEQ_NUM)
			flow_stat->down_seq_max = pktinfo->msg.seq_curr;
		else
			flow_stat->down_seq_max = fi_get_max_seq(flow_stat->down_seq_max,
				pktinfo->msg.seq_curr);

		if (flow_stat->down_seq_min == FI_INVALID_SEQ_NUM)
			flow_stat->down_seq_min = pktinfo->msg.seq_curr;
		else
			flow_stat->down_seq_min = fi_get_min_seq(flow_stat->down_seq_min,
				pktinfo->msg.seq_curr);

		if (flow_ctx->down_seq_expect == FI_INVALID_SEQ_NUM) {
			flow_ctx->down_seq_expect = (pktinfo->msg.seq_curr + 1) % (FI_MAX_SEQ_NUM + 1);
			return;
		}
		if (fi_seq_is_increase(flow_ctx->down_seq_expect, pktinfo->msg.seq_curr)) {
			loss_cnt = (pktinfo->msg.seq_curr + (FI_MAX_SEQ_NUM + 1) -
				flow_ctx->down_seq_expect) % (FI_MAX_SEQ_NUM + 1);
			flow_ctx->down_seq_expect = (pktinfo->msg.seq_curr + 1) % (FI_MAX_SEQ_NUM + 1);
		}

		flow_stat->down_loss_cnt += loss_cnt;
	}
}

static void fi_reset(void)
{
	int i;

	fi_logi("fi need reset when netlink pid change]free_cnt=%d", atomic_read(&(g_fi_app_info.free_cnt)));
	if (atomic_read(&(g_fi_app_info.free_cnt)) >= FI_LAUNCH_APP_MAX)
		return;
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		spin_lock_bh(&(g_fi_app_info.app[i].lock));
		if (g_fi_app_info.app[i].msg.status != FI_INVALID_APP_STATUS) {
			struct fi_app_info_node *app = &(g_fi_app_info.app[i]);

			app->rand_num = 0;
			app->msg.status = FI_INVALID_APP_STATUS;
		}
		spin_unlock_bh(&(g_fi_app_info.app[i].lock));
	}
	atomic_set(&(g_fi_app_info.free_cnt), FI_LAUNCH_APP_MAX);
	fi_unregister_nfhook();
}

static void fi_set_nl_pid(const struct fi_cfg_head *cfg)
{
	if (cfg->len < sizeof(struct fi_cfg_head) + sizeof(uint32_t)) {
		fi_loge(" received a message without enough FI app info, len %d, min_len %zu\n",
			cfg->len, sizeof(struct fi_cfg_head) + sizeof(uint32_t));
		return;
	}
	/* fi need reset when netlink pid change, in case of daemon process restart */
	fi_reset();
	 g_fi_ctx.nl_pid = *(uint32_t *)((char *)cfg +
		sizeof(struct fi_cfg_head));
	fi_logi("set netlink pid from frameworkJnI_pid %u", g_fi_ctx.nl_pid);
	return;
}

static void fi_iface_qos_rpt_update(void)
{
	int i;

	g_fi_ctx.iface_qos_rpt_enable = 0;
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		spin_lock_bh(&(g_fi_app_info.app[i].lock));
		if (g_fi_app_info.app[i].msg.uid != 0 &&
			g_fi_app_info.app[i].msg.status == FI_COLLECT_RUN &&
			g_fi_app_info.app[i].msg.qos_rpt_enable) {
			g_fi_ctx.iface_qos_rpt_enable = 1;
			spin_unlock_bh(&(g_fi_app_info.app[i].lock));
			break;
		}
		spin_unlock_bh(&(g_fi_app_info.app[i].lock));
	}
}

static void fi_app_netinfo_rpt_update(void)
{
	int i;

	fi_loge("fi_app_netinfo_rpt_update app_netinfo_rpt_enable 0");
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		g_fi_ctx.app_netinfo_rpt_enable[i] = 0;
		spin_lock_bh(&(g_fi_app_info.app[i].lock));
		if (g_fi_app_info.app[i].msg.uid != 0 &&
			g_fi_app_info.app[i].msg.status == FI_COLLECT_RUN &&
			g_fi_app_info.app[i].msg.app_netinfo_rpt) {
			g_fi_ctx.app_netinfo_rpt_enable[i] = 1;
			fi_loge("fi_app_netinfo_rpt_update app_netinfo_rpt_enable 1");
		}
		spin_unlock_bh(&(g_fi_app_info.app[i].lock));
	}
}

static bool fi_app_info_update_status_check_invalid(const enum fi_app_status status)
{
	if ((status <= FI_INVALID_APP_STATUS) || (status >= FI_MAX_APP_STATUS)) {
		fi_loge("received an app with illegal status %d", status);
		return true;
	} else {
		return false;
	}
}

static bool fi_app_info_update_same_app_check(struct fi_app_update_msg *update_msg,
	struct fi_app_info_node *app)
{
	if (app->msg.uid == update_msg->uid)
		return true;

	return false;
}

static int protocol_trans(int proto)
{
	switch (proto) {
	case FI_TCP:
		return IPPROTO_TCP;
	case FI_UDP:
		return IPPROTO_UDP;
	default:
		break;
	}
	return proto;
}

static void fi_app_info_update(const struct fi_cfg_head *cfg)
{
	struct fi_app_update_msg *update_msg = NULL;
	struct fi_app_info_node *app = NULL;
	struct fi_app_info_node *new_app = NULL;
	fi_rpt_cfg *periodic = NULL;
	fi_rpt_cfg *pkt = NULL;
	int i, ret;

	if (cfg->len != sizeof(struct fi_cfg_head) + sizeof(struct fi_app_update_msg)) {
		fi_loge("received message without enough FI app info, len %d, min_len %zu",
			cfg->len, sizeof(struct fi_cfg_head) + sizeof(struct fi_app_update_msg));
		return;
	}
	update_msg = (struct fi_app_update_msg *)((char *)cfg +
		sizeof(struct fi_cfg_head));
	if (fi_app_info_update_status_check_invalid(update_msg->status) ||
		(update_msg->status == FI_COLLECT_STOP)) {
		fi_loge("received an app with illegal status %d",
			update_msg->status);
		return;
	}

	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		spin_lock_bh(&(g_fi_app_info.app[i].lock));
		if (fi_app_info_update_same_app_check(update_msg, &g_fi_app_info.app[i]) &&
			g_fi_app_info.app[i].msg.status != FI_INVALID_APP_STATUS) {
			app = &(g_fi_app_info.app[i]);
			break;
		}
		if (new_app == NULL && g_fi_app_info.app[i].msg.status ==
			FI_INVALID_APP_STATUS) {
			new_app = &(g_fi_app_info.app[i]);
			continue;
		}
		spin_unlock_bh(&(g_fi_app_info.app[i].lock));
	}
	if (app == NULL && new_app == NULL) {
		fi_loge("reach max app launch size %d", FI_LAUNCH_APP_MAX);
		return;
	} else if (app == NULL) {
		app = new_app;
		atomic_dec(&(g_fi_app_info.free_cnt));
	} else if (new_app != NULL) {
		spin_unlock_bh(&(new_app->lock));
	}

	ret = memcpy_s(&(app->msg), sizeof(struct fi_app_update_msg),
		update_msg, sizeof(struct fi_app_update_msg));
	if (ret) {
		fi_loge("memcpy_s failed ret=%d", ret);
		spin_unlock_bh(&(app->lock));
		return;
	}

	for (i = 0; i < FI_FLOW_IDENTIFY_MAX; i++)
		app->msg.flow_identify_cfg[i].proto = protocol_trans(app->msg.flow_identify_cfg[i].proto);

	app->rand_num++;
	spin_unlock_bh(&(app->lock));
	for (i = 0; i < FI_DIR_BOTH; i++) {
		periodic = &(app->msg.flow_identify_cfg[0].periodic[i]);
		pkt = &(app->msg.flow_identify_cfg[0].pkt[i]);
		fi_logi("Config received.app %s[%d], appNetInfoReport[%d], status=%d,proto=%d,dport=%d,"
			"periodic[dir=%d roiType=%d roiStart=%d roiStop=%d],"
			"immediate[dir=%d roiType=%d roiStart=%d roiStop=%d] version:%s",
			app->msg.app_name, app->msg.app_netinfo_rpt, app->msg.uid, app->msg.status,
			app->msg.flow_identify_cfg[0].proto, app->msg.flow_identify_cfg[0].dport[0],
			i, periodic->report_type, periodic->roi_start, periodic->roi_stop,
			i, pkt->report_type, pkt->roi_start, pkt->roi_stop, FI_VER);
	}
	fi_register_nfhook();
	fi_iface_qos_rpt_update();
	fi_app_netinfo_rpt_update();
	return;
}

static void fi_app_status_update(const struct fi_cfg_head *cfg)
{
	struct fi_app_update_msg *update_msg = NULL;
	struct fi_app_info_node *app = NULL;
	int i;

	if (cfg->len < sizeof(struct fi_cfg_head) + sizeof(struct fi_app_update_msg)) {
		fi_loge("receive a message without enough FI app info, len %d, min_len %zu",
			cfg->len,
			sizeof(struct fi_cfg_head) + sizeof(struct fi_app_update_msg));
		return;
	}
	update_msg = (struct fi_app_update_msg *)((char *)cfg +
		sizeof(struct fi_cfg_head));
	if (fi_app_info_update_status_check_invalid(update_msg->status)) {
		return;
	}
	for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
		spin_lock_bh(&(g_fi_app_info.app[i].lock));
		if (g_fi_app_info.app[i].msg.uid == update_msg->uid &&
			g_fi_app_info.app[i].msg.status != FI_INVALID_APP_STATUS) {
			app = &(g_fi_app_info.app[i]);
			break;
		}
		spin_unlock_bh(&(g_fi_app_info.app[i].lock));
	}
	if (app == NULL) {
		fi_loge("app %s, uid %d not exist",
			update_msg->app_name, update_msg->uid);
		return;
	}
	if (update_msg->status == FI_COLLECT_STOP) {
		app->rand_num = 0;
		app->msg.status = FI_INVALID_APP_STATUS;
		spin_unlock_bh(&(app->lock));
		fi_ipv4_flow_clear_by_uid(update_msg->uid);
#if IS_ENABLED(CONFIG_IPV6)
		fi_ipv6_flow_clear_by_uid(update_msg->uid);
#endif
		atomic_inc(&(g_fi_app_info.free_cnt));
		fi_logd("app %s, uid %d stop",
			update_msg->app_name, update_msg->uid);
	} else {
		app->msg.status = update_msg->status;
		app->rand_num++;
		spin_unlock_bh(&(app->lock));
	}
	if (atomic_read(&(g_fi_app_info.free_cnt)) >= FI_LAUNCH_APP_MAX)
		fi_unregister_nfhook();

	fi_iface_qos_rpt_update();
	fi_app_netinfo_rpt_update();

	fi_logi("app %s status update, uid:%d, status:%d, rand_num:%lu, free_cnt:%d",
		app->msg.app_name, app->msg.uid, app->msg.status, app->rand_num, atomic_read(&(g_fi_app_info.free_cnt)));
	return;
}

void fi_cfg_process(const struct fi_cfg_head *cfg)
{
	if (!g_fi_ctx.running) {
		fi_loge("FI not initialized yet, cfg type:%d", cfg->type);
		return;
	}
	if (cfg == NULL || cfg->len == 0)
		return;

	switch (cfg->type) {
	case FI_SET_NL_PID_CMD:
		fi_set_nl_pid(cfg);
		break;
	case FI_COLLECT_START_CMD:
	case FI_COLLECT_INFO_UPDATE_CMD:
		fi_app_info_update(cfg);
		break;
	case FI_COLLECT_STATUS_UPDATE_CMD:
		fi_app_status_update(cfg);
		break;
	default:
		fi_loge("receive a not FI message, type:%d", cfg->type);
		break;
	}
	return;
}
EXPORT_SYMBOL(fi_cfg_process); /*lint !e580*/

static void fi_pkt_msg_report(const struct fi_pkt_parse *pktinfo, int type)
{
	uint32_t size;
	char *data = NULL;
	int ret;
	struct sk_buff *pskb = NULL;

	spin_lock_bh(&(pktinfo->flow_cb.app_info->lock));
	if (pktinfo->rand_num == pktinfo->flow_cb.app_info->rand_num) {
		spin_unlock_bh(&(pktinfo->flow_cb.app_info->lock));
		size = sizeof(struct fi_pkt_msg);
		pskb = fi_get_netlink_skb(type, size, &data);
		if (pskb == NULL) {
			fi_loge("failed to malloc memory for data");
			return;
		}
		ret = memcpy_s(data, size, &(pktinfo->msg), sizeof(struct fi_pkt_msg));
		if (ret) {
			fi_loge("memcpy_s failed ret=%d", ret);
			kfree_skb(pskb);
			return;
		}

		fi_enqueue_netlink_skb(pskb);
		fi_logd("finish to send a message to native, flow:%s", pktinfo->msg.flow_msg.flow);
	} else {
		spin_unlock_bh(&(pktinfo->flow_cb.app_info->lock));
	}
	return;
}

static bool fi_app_netinfo_cfg_get(struct fi_pkt_parse *pktinfo,
				int32_t uid, enum fi_app_status status)
{
	struct fi_app_info_node *app = NULL;
	int i;
	bool enable = false;
	int index = -1;
	if (pktinfo != NULL) {
		for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
			spin_lock_bh(&(g_fi_app_info.app[i].lock));
			if (g_fi_app_info.app[i].msg.uid == uid &&
				g_fi_app_info.app[i].msg.status == status) {
				app = &(g_fi_app_info.app[i]);
				index = i;
				break;
			}
			spin_unlock_bh(&(g_fi_app_info.app[i].lock));
		}
		if (app == NULL)
			return false;
		pktinfo->flow_cb.app_info = app;
		pktinfo->rand_num = pktinfo->flow_cb.app_info->rand_num;
		pktinfo->msg.flow_msg.uid = uid;
		enable = app->msg.app_netinfo_rpt;
		spin_unlock_bh(&(app->lock));
		if (!enable)
			return false;

		spin_lock_bh(&g_fi_ctx.app_stat_lock);
		g_fi_ctx.index = index;
		g_fi_ctx.app_net_info[index].app_stat_report.uid = uid;
		spin_unlock_bh(&g_fi_ctx.app_stat_lock);
		return true;
	}
	return false;
}

static bool fi_app_identify_cfg_get(struct fi_pkt_parse *pktinfo,
				int32_t uid, enum fi_app_status status)
{
	struct fi_app_info_node *app = NULL;
	int i, j;
	bool match = false;

	if (pktinfo != NULL) {
		for (i = 0; i < FI_LAUNCH_APP_MAX; i++) {
			spin_lock_bh(&(g_fi_app_info.app[i].lock));
			if (g_fi_app_info.app[i].msg.uid == uid &&
				g_fi_app_info.app[i].msg.status == status) {
				app = &(g_fi_app_info.app[i]);
				break;
			}
			spin_unlock_bh(&(g_fi_app_info.app[i].lock));
		}
		if (app == NULL)
			return false;
		pktinfo->flow_cb.app_info = app;
		pktinfo->rand_num = pktinfo->flow_cb.app_info->rand_num;
		pktinfo->msg.flow_msg.uid = uid;
		for (i = 0; i < FI_FLOW_IDENTIFY_MAX; i++) {
			int proto = app->msg.flow_identify_cfg[i].proto;
			if (proto ==  FI_PROTO_ANY || proto ==  pktinfo->msg.flow_msg.l4proto) {
				for (j = 0; j < FI_DPORT_MAX; j++) {
					if (app->msg.flow_identify_cfg[i].dport[j] == FI_PORT_ANY ||
						pktinfo->msg.flow_msg.dport == app->msg.flow_identify_cfg[i].dport[j]) {
						match = true;
						break;
					}
				}
				if (pktinfo->msg.flow_msg.dport >= app->msg.flow_identify_cfg[i].dport_range[FI_DPORT_LOW] &&
					pktinfo->msg.flow_msg.dport <= app->msg.flow_identify_cfg[i].dport_range[FI_DPORT_HIGH]) {
					match = true;
				}
			}
			if (match)
				break;
		}
		spin_unlock_bh(&(app->lock));
		if (!match)
			return false;
		pktinfo->flow_cb.flow_identify_cfg = &app->msg.flow_identify_cfg[i];
		return true;
	}
	return false;
}

static void fi_app_netinfo_update(struct sk_buff *skb, struct fi_netinfo_flow_node *flow,
	const struct fi_pkt_parse *pktinfo, enum fi_dir dir)
{
	struct tcphdr *tcph = NULL;
	struct tcp_sock *tp = NULL;
	int tcp_len = 0;

	struct fi_app_stat_msg *app_stat = NULL;
	struct fi_app_stat_ctx *app_ctx  = NULL;
	int payloadlen = 0;
	if (pktinfo->msg.flow_msg.l4proto != IPPROTO_TCP
		&& pktinfo->msg.flow_msg.l4proto != IPPROTO_UDP)
		return;

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_UDP) {
		if (skb->len > skb_transport_offset(skb) + sizeof(struct udphdr))
			payloadlen = skb->len -
				skb_transport_offset(skb) - sizeof(struct udphdr);
	} else {
		if (skb->len > skb_transport_offset(skb) + tcp_hdrlen(skb))
			payloadlen = skb->len - skb_transport_offset(skb) - tcp_hdrlen(skb);
	}

	spin_lock_bh(&g_fi_ctx.app_stat_lock);
	app_stat = &g_fi_ctx.app_net_info[g_fi_ctx.index].app_stat_report.app_stat_msg;
	app_ctx = &g_fi_ctx.app_net_info[g_fi_ctx.index].app_stat_ctx;
	if (dir == FI_DIR_UP) {
		app_stat->uplink_len += payloadlen;
	} else {
		app_stat->downlink_len += payloadlen;
	}
	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP) {
		fi_flow_rtt_update(flow);
		tp = (struct tcp_sock *)flow->sk;
		tcph = tcp_hdr(skb);
		if (dir == FI_DIR_DOWN) {
			app_stat->dlink_tcp_num++;
			flow->flow_ctx.flow_app_info.raw_down_tcp_pkt_num++;
			app_stat->dlink_tcp_len += payloadlen;
			tcp_len = payloadlen - tcph->doff * 4; // 32bits to byte
			if (before(ntohl(tcph->seq) + tcp_len - 1, tp->rcv_nxt) && tcp_len > 0)
				app_stat->dlink_retrans_num++;
			if (flow->flow_ctx.flow_app_info.raw_up_tcp_pkt_num
				&& flow->flow_ctx.flow_app_info.raw_down_tcp_pkt_num
				&& flow->flow_ctx.flow_app_info.rtt) {
					app_stat->avr_rtt += flow->flow_ctx.flow_app_info.rtt;
					app_ctx->rtt_cnt++;
			}
		}

		if (dir == FI_DIR_UP) {
			app_stat->uplink_tcp_num++;
			flow->flow_ctx.flow_app_info.raw_up_tcp_pkt_num++;
			app_stat->uplink_tcp_len += payloadlen;
			if (tp->snd_nxt != 0 && before(ntohl(tcph->seq), tp->snd_nxt) &&
			(flow->sk->sk_state == TCP_ESTABLISHED || flow->sk->sk_state == TCP_SYN_SENT))
				app_stat->uplink_retrans_num++;
			if (tcph->syn == 1)
				app_stat->syn_num++;
		}
	 }

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_UDP) {
		if (dir == FI_DIR_DOWN) {
			app_stat->dlink_udp_num++;
			app_stat->dlink_udp_len += payloadlen;
			if (app_stat->dlink_udp_max_pktlen < payloadlen) {
				app_stat->dlink_udp_max_pktlen = payloadlen;
			}
		}
		if (dir == FI_DIR_UP) {
			app_stat->uplink_udp_num++;
			app_stat->uplink_udp_len += payloadlen;
			if (app_stat->uplink_udp_max_pktlen < payloadlen) {
				app_stat->uplink_udp_max_pktlen = payloadlen;
			}
		}
	}
	spin_unlock_bh(&g_fi_ctx.app_stat_lock);
}

static void fi_ip_save_5tuple_info(struct fi_pkt_parse *pktinfo, uint16_t protocol,
	struct sk_buff *skb)
{
	struct udphdr *udph = NULL;
	struct tcphdr *tcph = NULL;
	if (protocol == IPPROTO_UDP) {
		udph = udp_hdr(skb);
		pktinfo->msg.flow_msg.l4proto = IPPROTO_UDP;
		pktinfo->msg.flow_msg.sport = ntohs(udph->source);
		pktinfo->msg.flow_msg.dport = ntohs(udph->dest);
	} else {
		tcph = tcp_hdr(skb);
		pktinfo->msg.flow_msg.l4proto = IPPROTO_TCP;
		pktinfo->msg.flow_msg.sport = ntohs(tcph->source);
		pktinfo->msg.flow_msg.dport = ntohs(tcph->dest);
	}
}

 /**
 * do_gettimeofday_ - Returns the time of day in a timeval
 * instead do_gettimeofday under kernel 5.4
 * @tv: pointer to the timeval to be set
 *
 * NOTE: Users should be converted to using getnstimeofday()
 */
void do_gettimeofday_fi(struct fi_timeval *tv)
{
    struct timespec64 now;
    ktime_get_real_ts64(&now);
    tv->tv_sec = now.tv_sec;
    tv->tv_usec = now.tv_nsec/FI_TIME_BASE;
}

static void fi_flow_get_dev(struct fi_flow_msg *flow_msg, const struct net_device *dev)
{
	int ret = memcpy_s(flow_msg->dev, IFNAMSIZ, dev->name, strlen(dev->name)+1);
	if (ret)
		fi_loge("memcpy_s failed ret=%d, dev %s", ret, dev->name);
	return;
}

static bool fi_dns_proc(struct fi_pkt_parse *pktinfo, enum fi_dir dir, struct sk_buff *skb)
{
	int i;
	uint64_t timestamp;
	uint16_t tid;
	struct fi_app_stat_msg *app_stat = NULL;
	struct fi_app_stat_ctx *app_ctx  = NULL;

	if (pktinfo->msg.flow_msg.l4proto != IPPROTO_UDP)
		return false;
	if (dir == FI_DIR_UP && pktinfo->msg.flow_msg.dport != FI_APP_INFO_DNS_PORT)
		return false;
	if (dir == FI_DIR_DOWN && pktinfo->msg.flow_msg.sport != FI_APP_INFO_DNS_PORT)
		return false;

	timestamp = jiffies_to_msecs(jiffies);
	tid = fi_dns_transaction_id_parse(skb);
	if (tid == INVALID_TID)
		return true;
	spin_lock_bh(&g_fi_ctx.app_stat_lock);

	app_stat = &g_fi_ctx.app_net_info[g_fi_ctx.index].app_stat_report.app_stat_msg;
	app_ctx = &g_fi_ctx.app_net_info[g_fi_ctx.index].app_stat_ctx;

	if (app_ctx->dns_ctx.num < 0
		|| app_ctx->dns_ctx.num > FI_APP_INFO_DNS_BUFFER_NUM) {
		fi_loge("num exceed limit");
		app_ctx->dns_ctx.num = 0;
	}

	if (dir == FI_DIR_UP) {
		if (app_ctx->dns_ctx.num == FI_APP_INFO_DNS_BUFFER_NUM) {
			fi_loge("num exceed limit");
  			spin_unlock_bh(&g_fi_ctx.app_stat_lock);
			return true;
		}
		for (i = 0; i < app_ctx->dns_ctx.num; i++) {
			if (app_ctx->dns_ctx.tid[i] == tid) {
				spin_unlock_bh(&g_fi_ctx.app_stat_lock);
				return true;
			}
		}
		app_ctx->dns_ctx.req_timestamp[app_ctx->dns_ctx.num] = timestamp;
		app_ctx->dns_ctx.tid[app_ctx->dns_ctx.num] = tid;
		app_ctx->dns_ctx.num++;
		app_ctx->dns_ctx.timer_counter = 0; // start timer count
		fi_loge("fi_dns_proc up tid:%u, app_ctx->dns_ctx.num:%d", tid, app_ctx->dns_ctx.num);
	} else {
		i = 0;
		while (i < app_ctx->dns_ctx.num) {
			if (app_ctx->dns_ctx.tid[i] == tid) {
				app_ctx->dns_ctx.total_delay += timestamp - app_ctx->dns_ctx.req_timestamp[i];
				app_stat->dns_succ_count++;
				app_ctx->dns_ctx.req_timestamp[i] = app_ctx->dns_ctx.req_timestamp[app_ctx->dns_ctx.num - 1];
				app_ctx->dns_ctx.tid[i] = app_ctx->dns_ctx.tid[app_ctx->dns_ctx.num - 1];
				app_ctx->dns_ctx.num--;
				fi_loge("fi_dns_proc down succ tid:%u, app_ctx->dns_ctx.num:%d, dns_delay:%u",
					tid, app_ctx->dns_ctx.num, (uint32_t)(timestamp - app_ctx->dns_ctx.req_timestamp[i]));
				break;
			}
			i++;
		}
	}
	spin_unlock_bh(&g_fi_ctx.app_stat_lock);
	return true;
}

static void fi_http_get_proc(struct fi_pkt_parse *pktinfo, enum fi_dir dir,
	struct sk_buff *skb, enum fi_app_status status)
{
	__be16 payloadlen = 0;
	char *payload = NULL;
	const skb_frag_t *frag = NULL;
	int transport_len = 0;
	struct sk_buff *frag_list = NULL;
	struct fi_app_stat_msg *app_stat = NULL;


	if (pktinfo->msg.flow_msg.l4proto != IPPROTO_TCP)
		return;
	if (dir != FI_DIR_UP)
		return;

	transport_len = tcp_hdrlen(skb);
	if (skb_headlen(skb) > skb_transport_offset(skb) + transport_len) {
		/* step1: Point to the linear region */
		payloadlen = skb_headlen(skb) - skb_transport_offset(skb) - transport_len;
		payload = skb_transport_header(skb) + transport_len;
	} else if (skb_shinfo(skb)->frag_list != NULL) {
		/* step2: Point to the fragList region */
		frag_list = skb_shinfo(skb)->frag_list;
		payloadlen = skb_headlen(frag_list);
		payload = frag_list->data;
	} else if (skb_shinfo(skb)->nr_frags) {
		/* step3: Point to the frags */
		frag = (const skb_frag_t *)(&skb_shinfo(skb)->frags[0]);
		payloadlen = skb_frag_size(frag);
		payload = skb_frag_address_safe(frag);
	}
	if (payload == NULL) {
		return;
	}
	if (payloadlen >= 3 && strncmp(payload, "GET", 3) == 0) {
		spin_lock_bh(&g_fi_ctx.app_stat_lock);
		app_stat = &g_fi_ctx.app_net_info[g_fi_ctx.index].app_stat_report.app_stat_msg;
		app_stat->http_get_count++;
		spin_unlock_bh(&g_fi_ctx.app_stat_lock);
	}
}

static void fi_ipv4_pkt_parse(struct fi_pkt_parse *pktinfo, struct sk_buff *skb, struct fi_flow_node *flow)
{
	int i;

	spin_lock_bh(&(pktinfo->flow_cb.app_info->lock));
	fi_payload_parse(flow, skb, pktinfo);
	for (i = 0; i < FI_END_PARSE; i++) {
		if ((pktinfo->flow_cb.flow_identify_cfg->pkt[pktinfo->dir].opt_enable[i] ||
			pktinfo->flow_cb.flow_identify_cfg->periodic[pktinfo->dir].opt_enable[i]) &&
			(g_fi_pkt_parse_f[i].opt_val_parse != NULL)) {
			fi_logd("parse %d function", i);
			(void)(g_fi_pkt_parse_f[i].opt_val_parse(skb, pktinfo, flow));
		}
	}
	spin_unlock_bh(&(pktinfo->flow_cb.app_info->lock));
	return;
}

static bool fi_ipv4_pkt_check(struct sk_buff *skb)
{
	struct iphdr *iph = ip_hdr(skb);
	if (iph == NULL)
		return false;
	if (ipv4_is_loopback(iph->saddr) || ipv4_is_loopback(iph->daddr))
		return false;
	if (iph->protocol == IPPROTO_UDP) {
		if (skb->len >= skb_transport_offset(skb) + sizeof(struct udphdr))
			return true;
	} else if (iph->protocol == IPPROTO_TCP) {
		if (skb->len >= skb_transport_offset(skb) + tcp_hdrlen(skb))
			return true;
	}
	return false;
}

static void fi_ipv4_5tuple_parse(struct fi_pkt_parse *pktinfo, struct sk_buff *skb,
				enum fi_dir dir)
{
	struct iphdr *iph = NULL;

	pktinfo->msg.flow_msg.l3proto = ntohs(skb->protocol);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
	do_gettimeofday_fi(&(pktinfo->msg.tstamp));
#else
	struct timeval now;
	do_gettimeofday(&now);
	pktinfo->msg.tstamp.tv_sec = now.tv_sec;
	pktinfo->msg.tstamp.tv_usec = now.tv_usec;
#endif
	pktinfo->msg.dir = dir;
	iph = ip_hdr(skb);
	pktinfo->msg.flow_msg.ipv4_sip = iph->saddr;
	pktinfo->msg.flow_msg.ipv4_dip = iph->daddr;
	fi_ip_save_5tuple_info(pktinfo, iph->protocol, skb);
	return;
}

static void fi_ipv4_app_netinfo_parse(struct fi_pkt_parse *pktinfo,
	const struct nf_hook_state *state, struct sk_buff *skb,
	enum fi_dir dir)
{
	struct sock *sk = NULL;
	kuid_t kuid = {0};
	uint32_t hash;
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *flow = NULL;

	if (dir == FI_DIR_UP) {
		sk = skb->sk;
		if (sk == NULL)
			return;
		/* If sk state is SYN_RECV, sk is actually a request_sock, can not call sock_i_uid */
		if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
			(sk->sk_state == TCP_NEW_SYN_RECV || sk->sk_state == TCP_SYN_RECV)) {
			fi_logd("Ignore SYN_RECV sk, sk_state=%d l4proto=%d port[%hu--%hu]",
				sk->sk_state, pktinfo->msg.flow_msg.l4proto, pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
			return;
		}
		kuid = sock_i_uid(sk);
		if (!fi_app_netinfo_cfg_get(pktinfo, kuid.val, FI_COLLECT_RUN))
			return;
		pktinfo->msg.flow_msg.dev_if = sk->sk_bound_dev_if;
	}
	if (fi_dns_proc(pktinfo, dir, skb))
		return; // if it is a DNS req/rsp, return;
	hash = fi_ipv4_flow_netinfo_hash(pktinfo->msg.flow_msg.ipv4_sip,
		pktinfo->msg.flow_msg.sport,
		pktinfo->msg.flow_msg.ipv4_dip,
		pktinfo->msg.flow_msg.dport,
		pktinfo->msg.flow_msg.flow,
		FI_FLOW_LEN + 1,
		((dir == FI_DIR_DOWN) ? true : false));
	head = fi_ipv4_flow_netinfo_header(hash);
	fi_ipv4_flow_netinfo_lock(hash);

	flow = fi_ipv4_flow_netinfo_get(head, kuid.val,
		pktinfo->msg.flow_msg.ipv4_sip,
		pktinfo->msg.flow_msg.sport,
		pktinfo->msg.flow_msg.ipv4_dip,
		pktinfo->msg.flow_msg.dport,
		pktinfo->flow_cb, ((dir == FI_DIR_UP) ? true : false),
		&(pktinfo->msg.flow_msg.new_flow), sk);
	if (flow == NULL) {
		fi_ipv4_flow_netinfo_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
		flow->sk && flow->sk->sk_state >= TCP_FIN_WAIT1) {
		fi_logd("Ignore flow:l4proto=%d,sk=%pK, sk_state=%d port[%hu--%hu]",
			pktinfo->msg.flow_msg.l4proto, flow->sk, flow->sk->sk_state,
			pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
		fi_ipv4_flow_netinfo_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.new_flow == true) {
		if (state->out) {
			fi_flow_get_dev(&pktinfo->msg.flow_msg, state->out);
			fi_flow_get_dev(&flow->flow_ctx.flow_msg, state->out);
		} else {
			fi_logi("new flow dev is null");
		}
	}
	fi_http_get_proc(pktinfo, dir, skb, FI_COLLECT_RUN);
	fi_app_netinfo_update(skb, flow, pktinfo, dir);

	fi_ipv4_flow_netinfo_unlock(hash);
}

static void fi_ipv4_identify_report(struct fi_pkt_parse *pktinfo,
	const struct nf_hook_state *state, struct sk_buff *skb,
	enum fi_dir dir)
{
	struct sock *sk = NULL;
	kuid_t kuid = {0};
	uint32_t hash;
	bool enable = false;
	struct fi_flow_head *head = NULL;
	struct fi_flow_node *flow = NULL;

	if (dir == FI_DIR_UP) {
		sk = skb->sk;
		if (sk == NULL)
			return;
		/* If sk state is SYN_RECV, sk is actually a request_sock, can not call sock_i_uid */
		if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
			(sk->sk_state == TCP_NEW_SYN_RECV || sk->sk_state == TCP_SYN_RECV)) {
			fi_logd("Ignore SYN_RECV sk, sk_state=%d l4proto=%d port[%hu--%hu]",
				sk->sk_state, pktinfo->msg.flow_msg.l4proto, pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
			return;
		}
		kuid = sock_i_uid(sk);
		if (!fi_app_identify_cfg_get(pktinfo, kuid.val, FI_COLLECT_RUN))
			return;
		pktinfo->msg.flow_msg.dev_if = sk->sk_bound_dev_if;
	}
	hash = fi_ipv4_flow_hash(pktinfo->msg.flow_msg.ipv4_sip,
		pktinfo->msg.flow_msg.sport,
		pktinfo->msg.flow_msg.ipv4_dip,
		pktinfo->msg.flow_msg.dport,
		pktinfo->msg.flow_msg.flow,
		FI_FLOW_LEN + 1,
		((dir == FI_DIR_DOWN) ? true : false));
	head = fi_ipv4_flow_header(hash);
	fi_ipv4_flow_lock(hash);
	flow = fi_ipv4_flow_get(head, kuid.val,
		pktinfo->msg.flow_msg.ipv4_sip,
		pktinfo->msg.flow_msg.sport,
		pktinfo->msg.flow_msg.ipv4_dip,
		pktinfo->msg.flow_msg.dport,
		pktinfo->flow_cb, ((dir == FI_DIR_UP) ? true : false),
		&(pktinfo->msg.flow_msg.new_flow), sk);
	if (flow == NULL) {
		fi_ipv4_flow_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
		flow->sk && flow->sk->sk_state >= TCP_FIN_WAIT1) {
		fi_logd("Ignore flow:l4proto=%d,sk=%pK, sk_state=%d port[%hu--%hu]",
			pktinfo->msg.flow_msg.l4proto, flow->sk, flow->sk->sk_state,
			pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
		fi_ipv4_flow_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.new_flow == true) {
		if (state->out) {
			fi_flow_get_dev(&pktinfo->msg.flow_msg, state->out);
			fi_flow_get_dev(&flow->flow_ctx.flow_msg, state->out);
		} else {
			fi_logi("new flow dev is null");
		}
	}
	if (fi_flow_qos_rpt_enable(flow) && pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP) {
		if (dir == FI_DIR_UP) {
			fi_filesize_update(skb, flow);
		} else {
			fi_qos_update(skb, flow);
		}
	}
	/* if all stat report have stopped, bypass this packet */
	if ((flow->flow_ctx.stat_stop & FI_FLOW_ALL_REPORT_STOP) == FI_FLOW_ALL_REPORT_STOP
			&& !flow->flow_cb.flow_identify_cfg->basic_rpt_en) {
		fi_ipv4_flow_unlock(hash);
		return;
	}
	if (dir == FI_DIR_DOWN) {
		pktinfo->flow_cb = flow->flow_cb;
		pktinfo->rand_num = pktinfo->flow_cb.app_info->rand_num;
		pktinfo->msg.flow_msg.uid = flow->uid;
		pktinfo->msg.flow_msg.dev_if = flow->flow_ctx.flow_msg.dev_if;
	}
	pktinfo->dir = dir;
	fi_ipv4_pkt_parse(pktinfo, skb, flow);
	fi_flow_statistics(flow, pktinfo, dir);
	enable = fi_pkt_report_is_enable(flow, pktinfo, dir);
	if (enable) {
		int ret = strncpy_s(pktinfo->msg.flow_msg.dev, IFNAMSIZ, flow->flow_ctx.flow_msg.dev, IFNAMSIZ);
		if (ret)
			fi_loge("strcpy_s failed ret=%d, dev=%s", ret, flow->flow_ctx.flow_msg.dev);
	}
	fi_ipv4_flow_unlock(hash);

	if (enable)
		fi_pkt_msg_report(pktinfo, FI_PKT_MSG_RPT);
	return;
}

static void fi_ipv4_hook(struct sk_buff *skb, const struct nf_hook_state *state, enum fi_dir dir)
{
	struct fi_pkt_parse pktinfo;

	if (unlikely(skb == NULL))
		return;
	if (!fi_ipv4_pkt_check(skb))
		return;

	if (memset_s(&pktinfo, sizeof(pktinfo), 0, sizeof(struct fi_pkt_parse))) {
		fi_loge("ipv4 hook memset_s failed");
		return;
	}

	fi_ipv4_5tuple_parse(&pktinfo, skb, dir);

	/* netinfo parse, periodic report*/
	fi_ipv4_app_netinfo_parse(&pktinfo, state, skb, dir);
	/* fi flow identify parse, filter by ideintify cfg, periodic or immi report*/
	fi_ipv4_identify_report(&pktinfo, state, skb, dir);
}

static unsigned int fi_ipv4_hook_out(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state)
{
	fi_ipv4_hook(skb, state, FI_DIR_UP);
	return NF_ACCEPT;
}

static unsigned int fi_ipv4_hook_in(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state)
{
	fi_ipv4_hook(skb, state, FI_DIR_DOWN);
	return NF_ACCEPT;
}

#if IS_ENABLED(CONFIG_IPV6)
static void fi_ipv6_pkt_parse(struct fi_pkt_parse *pktinfo, struct sk_buff *skb, struct fi_flow_node *flow)
{
	int i;

	spin_lock_bh(&(pktinfo->flow_cb.app_info->lock));
	fi_payload_parse(flow, skb, pktinfo);
	for (i = 0; i < FI_END_PARSE; i++) {
		if ((pktinfo->flow_cb.flow_identify_cfg->pkt[pktinfo->dir].opt_enable[i] ||
			pktinfo->flow_cb.flow_identify_cfg->periodic[pktinfo->dir].opt_enable[i]) &&
			g_fi_pkt_parse_f[i].opt_val_parse != NULL) {
			fi_logd("parse %d", i);
			(void)(g_fi_pkt_parse_f[i].opt_val_parse(skb, pktinfo, flow));
		}
	}
	spin_unlock_bh(&(pktinfo->flow_cb.app_info->lock));
	return;
}

static bool fi_ipv6_pkt_check(struct sk_buff *skb)
{
	int thoff = 0;
	int tproto;
	struct ipv6hdr *iph = ipv6_hdr(skb);
	if (iph == NULL)
		return false;
	if (ipv6_addr_loopback(&(iph->saddr)) ||
		ipv6_addr_loopback(&(iph->daddr)))
		return false;
	tproto = ipv6_find_hdr(skb, &thoff, -1, NULL, NULL);
	if (tproto == IPPROTO_UDP) {
		if (skb->len >= skb_transport_offset(skb) + sizeof(struct udphdr))
			return true;
	} else if (tproto == IPPROTO_TCP) {
		if (skb->len >= skb_transport_offset(skb) + tcp_hdrlen(skb))
			return true;
	}
	return false;
}

static void fi_ipv6_5tuple_parse(struct fi_pkt_parse *pktinfo, struct sk_buff *skb,
				enum fi_dir dir)
{
	struct ipv6hdr *iph = NULL;
	int thoff = 0;
	int tproto;
	int ret;

	pktinfo->msg.flow_msg.l3proto = ntohs(skb->protocol);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
	do_gettimeofday_fi(&(pktinfo->msg.tstamp));
#else
	struct timeval now;
	do_gettimeofday(&now);
	pktinfo->msg.tstamp.tv_sec = now.tv_sec;
	pktinfo->msg.tstamp.tv_usec = now.tv_usec;
#endif
	pktinfo->msg.dir = dir;
	iph = ipv6_hdr(skb);
	ret = memcpy_s(&(pktinfo->msg.flow_msg.ipv6_sip), sizeof(pktinfo->msg.flow_msg.ipv6_sip),
		&(iph->saddr),
		sizeof(pktinfo->msg.flow_msg.ipv6_sip));
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return;
	}

	ret = memcpy_s(&(pktinfo->msg.flow_msg.ipv6_dip), sizeof(pktinfo->msg.flow_msg.ipv6_dip),
		&(iph->daddr),
		sizeof(pktinfo->msg.flow_msg.ipv6_dip));
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return;
	}
	tproto = ipv6_find_hdr(skb, &thoff, -1, NULL, NULL);
	fi_ip_save_5tuple_info(pktinfo, tproto, skb);
	return;
}

static void fi_ipv6_app_netinfo_parse(struct fi_pkt_parse *pktinfo,
	const struct nf_hook_state *state, struct sk_buff *skb,
	enum fi_dir dir)
{
	struct sock *sk = NULL;
	kuid_t kuid = {0};
	uint32_t hash;
	struct fi_netinfo_flow_head *head = NULL;
	struct fi_netinfo_flow_node *flow = NULL;

	if (dir == FI_DIR_UP) {
		sk = skb->sk;
		if (sk == NULL)
			return;
		/* If sk state is SYN_RECV, sk is actually a request_sock, can not call sock_i_uid */
		if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
			(sk->sk_state == TCP_NEW_SYN_RECV || sk->sk_state == TCP_SYN_RECV)) {
			fi_logd("Ignore SYN_RECV sk, sk_state=%d l4proto=%d port[%hu--%hu]",
				sk->sk_state, pktinfo->msg.flow_msg.l4proto, pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
			return;
		}
		kuid = sock_i_uid(sk);
		if (!fi_app_netinfo_cfg_get(pktinfo, kuid.val, FI_COLLECT_RUN))
			return;
		pktinfo->msg.flow_msg.dev_if = sk->sk_bound_dev_if;
	}
	if (fi_dns_proc(pktinfo, dir, skb))
		return; // if it is a DNS req/rsp, return;
	hash = fi_ipv6_flow_netinfo_hash(
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_sip),
		pktinfo->msg.flow_msg.sport,
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_dip),
		pktinfo->msg.flow_msg.dport,
		pktinfo->msg.flow_msg.flow,
		FI_FLOW_LEN + 1,
		((dir == FI_DIR_DOWN) ? true : false));
	head = fi_ipv6_flow_netinfo_header(hash);
	fi_ipv6_flow_netinfo_lock(hash);

	flow = fi_ipv6_flow_netinfo_get(head, kuid.val,
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_sip),
		pktinfo->msg.flow_msg.sport,
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_dip),
		pktinfo->msg.flow_msg.dport,
		pktinfo->flow_cb, ((dir == FI_DIR_UP) ? true : false),
		&(pktinfo->msg.flow_msg.new_flow), sk);
	if (flow == NULL) {
		fi_ipv6_flow_netinfo_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
		flow->sk && flow->sk->sk_state >= TCP_FIN_WAIT1) {
		fi_logd("Ignore flow:l4proto=%d,sk=%pK, sk_state=%d port[%hu--%hu]",
			pktinfo->msg.flow_msg.l4proto, flow->sk, flow->sk->sk_state,
			pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
		fi_ipv6_flow_netinfo_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.new_flow == true) {
		if (state->out) {
			fi_flow_get_dev(&pktinfo->msg.flow_msg, state->out);
			fi_flow_get_dev(&flow->flow_ctx.flow_msg, state->out);
		} else {
			fi_logi("new flow dev is null");
		}
	}
	fi_http_get_proc(pktinfo, dir, skb, FI_COLLECT_RUN);
	fi_app_netinfo_update(skb, flow, pktinfo, dir);

	fi_ipv6_flow_netinfo_unlock(hash);
}

static void fi_ipv6_identify_report(struct fi_pkt_parse *pktinfo,
	const struct nf_hook_state *state, struct sk_buff *skb,
	enum fi_dir dir)
{
	struct sock *sk = NULL;
	kuid_t kuid = {0};
	uint32_t hash;
	bool enable = false;
	struct fi_flow_head *head = NULL;
	struct fi_flow_node *flow = NULL;

	if (dir == FI_DIR_UP) {
		sk = skb->sk;
		if (sk == NULL)
			return;
		/* If sk state is SYN_RECV, sk is actually a request_sock, can not call sock_i_uid */
		if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
			(sk->sk_state == TCP_NEW_SYN_RECV || sk->sk_state == TCP_SYN_RECV)) {
			fi_logd("Ignore SYN_RECV sk, sk_state=%d l4proto=%d port[%hu--%hu]",
				sk->sk_state, pktinfo->msg.flow_msg.l4proto, pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
			return;
		}
		kuid = sock_i_uid(sk);
		if (!fi_app_identify_cfg_get(pktinfo, kuid.val, FI_COLLECT_RUN))
			return;
		pktinfo->msg.flow_msg.dev_if = sk->sk_bound_dev_if;
	}
	hash = fi_ipv6_flow_hash(
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_sip),
		pktinfo->msg.flow_msg.sport,
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_dip),
		pktinfo->msg.flow_msg.dport,
		pktinfo->msg.flow_msg.flow,
		FI_FLOW_LEN + 1,
		((dir == FI_DIR_DOWN) ? true : false));
	head = fi_ipv6_flow_header(hash);
	fi_ipv6_flow_lock(hash);
	flow = fi_ipv6_flow_get(head, kuid.val,
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_sip),
		pktinfo->msg.flow_msg.sport,
		(const struct in6_addr *)&(pktinfo->msg.flow_msg.ipv6_dip),
		pktinfo->msg.flow_msg.dport,
		pktinfo->flow_cb, ((dir == FI_DIR_UP) ? true : false),
		&(pktinfo->msg.flow_msg.new_flow), sk);
	if (flow == NULL) {
		fi_ipv6_flow_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP &&
		flow->sk && flow->sk->sk_state >= TCP_FIN_WAIT1) {
		fi_logd("Ignore flow:l4proto=%d,sk=%pK, sk_state=%d port[%hu--%hu]",
			pktinfo->msg.flow_msg.l4proto, flow->sk, flow->sk->sk_state,
			pktinfo->msg.flow_msg.sport, pktinfo->msg.flow_msg.dport);
		fi_ipv6_flow_unlock(hash);
		return;
	}

	if (pktinfo->msg.flow_msg.new_flow == true) {
		if (state->out) {
			fi_flow_get_dev(&pktinfo->msg.flow_msg, state->out);
			fi_flow_get_dev(&flow->flow_ctx.flow_msg, state->out);
		} else {
			fi_logi("new flow dev is null");
		}
	}
	if (fi_flow_qos_rpt_enable(flow) && pktinfo->msg.flow_msg.l4proto == IPPROTO_TCP) {
		if (dir == FI_DIR_UP) {
			fi_filesize_update(skb, flow);
		} else {
			fi_qos_update(skb, flow);
		}
	}
	/* if all stat report have stopped, bypass this packet */
	if ((flow->flow_ctx.stat_stop & FI_FLOW_ALL_REPORT_STOP) == FI_FLOW_ALL_REPORT_STOP
			&& !flow->flow_cb.flow_identify_cfg->basic_rpt_en) {
		fi_ipv6_flow_unlock(hash);
		return;
	}
	if (dir == FI_DIR_DOWN) {
		pktinfo->flow_cb = flow->flow_cb;
		pktinfo->rand_num = pktinfo->flow_cb.app_info->rand_num;
		pktinfo->msg.flow_msg.uid = flow->uid;
		pktinfo->msg.flow_msg.dev_if = flow->flow_ctx.flow_msg.dev_if;
	}
	pktinfo->dir = dir;
	fi_ipv6_pkt_parse(pktinfo, skb, flow);
	fi_flow_statistics(flow, pktinfo, dir);
	enable = fi_pkt_report_is_enable(flow, pktinfo, dir);
	if (enable) {
		int ret = strncpy_s(pktinfo->msg.flow_msg.dev, IFNAMSIZ, flow->flow_ctx.flow_msg.dev, IFNAMSIZ);
		if (ret)
			fi_loge("strcpy_s failed ret=%d, dev=%s", ret, flow->flow_ctx.flow_msg.dev);
	}
	fi_ipv6_flow_unlock(hash);

	if (enable)
		fi_pkt_msg_report(pktinfo, FI_PKT_MSG_RPT);
	return;
}

static void fi_ipv6_hook(struct sk_buff *skb, const struct nf_hook_state *state, enum fi_dir dir)
{
	struct fi_pkt_parse pktinfo;

	if (unlikely(skb == NULL))
		return;

	if (!fi_ipv6_pkt_check(skb))
		return;

	if (memset_s(&pktinfo, sizeof(pktinfo), 0, sizeof(struct fi_pkt_parse))) {
		fi_loge("ipv6 hook memset_s failed");
		return;
	}

	fi_ipv6_5tuple_parse(&pktinfo, skb, dir);

	/* netinfo parse, periodic report*/
	fi_ipv6_app_netinfo_parse(&pktinfo, state, skb, dir);
	/* fi flow identify parse, filter by ideintify cfg, periodic or immi report*/
	fi_ipv6_identify_report(&pktinfo, state, skb, dir);
}

static unsigned int fi_ipv6_hook_out(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state)
{
	fi_ipv6_hook(skb, state, FI_DIR_UP);
	return NF_ACCEPT;
}

static unsigned int fi_ipv6_hook_in(void *priv, struct sk_buff *skb,
				const struct nf_hook_state *state)
{
	fi_ipv6_hook(skb, state, FI_DIR_DOWN);
	return NF_ACCEPT;
}
#endif

void fi_init(struct sock *nlfd)
{
	int ret;
	int i;

	ret = memset_s(&g_fi_app_info, sizeof(g_fi_app_info), 0, sizeof(g_fi_app_info));
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return;
	}

	for (i = 0; i < FI_LAUNCH_APP_MAX; i++)
		spin_lock_init(&(g_fi_app_info.app[i].lock));
	atomic_set(&(g_fi_app_info.free_cnt), FI_LAUNCH_APP_MAX);
	fi_logd("app_info init success");

	fi_ipv4_flow_init();
	fi_ipv4_flow_netinfo_init();
	fi_logd("IPV4 flow table init success");
#if IS_ENABLED(CONFIG_IPV6)
	fi_ipv6_flow_init();
	fi_ipv6_flow_netinfo_init();
	fi_logd("IPV6 flow table init success");
#endif

	ret  = memset_s(&g_fi_ctx, sizeof(g_fi_ctx), 0, sizeof(g_fi_ctx));
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return;
	}

	mutex_init(&g_fi_ctx.nf_mutex);
	spin_lock_init(&g_fi_ctx.app_stat_lock);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
	timer_setup(&(g_fi_ctx.tm), fi_timer, 0);
#else
	init_timer(&(g_fi_ctx.tm));
	g_fi_ctx.tm.function = fi_timer;
#endif
	g_fi_ctx.nlfd = nlfd;
	g_fi_ctx.running = true;
	skb_queue_head_init(&g_fi_ctx.skb_queue);
	sema_init(&g_fi_ctx.netlink_sync_sema, 0);
	g_fi_ctx.netlink_task = kthread_run(fi_netlink_thread, NULL, "fi_netlink_thread");
	fi_logi("init success");
	return;
}
EXPORT_SYMBOL(fi_init); /*lint !e580*/

void fi_deinit(void)
{
	int ret;

	fi_unregister_nfhook();

	ret = memset_s(&g_fi_app_info, sizeof(g_fi_app_info), 0, sizeof(g_fi_app_info));
	if (ret) {
		fi_loge("memset_s failed ret=%d", ret);
		return;
	}
	fi_logd("app_info deinit success");

	fi_ipv4_flow_clear();
	fi_ipv4_flow_netinfo_clear();
#if IS_ENABLED(CONFIG_IPV6)
	fi_ipv6_flow_clear();
	fi_ipv6_flow_netinfo_clear();
#endif
	fi_logd("flow table deinit success");

	g_fi_ctx.running = false;
	if (g_fi_ctx.netlink_task != NULL) {
		kthread_stop(g_fi_ctx.netlink_task);
		g_fi_ctx.netlink_task = NULL;
	}
	fi_empty_netlink_skb_queue();

	fi_logi("deinit success");
	return;
}
EXPORT_SYMBOL(fi_deinit); /*lint !e580*/
/**
 * fi_mstamp_get - get current timestamp
 * @cl: place to store timestamps
 */
static void fi_mstamp_get(struct fi_mstamp *cl)
{
	u64 val = local_clock();
	do_div(val, NSEC_PER_USEC);
	cl->stamp_us = (u32)val;
	cl->stamp_jiffies = (u32)jiffies;
}

/**
 * fi_mstamp_delta - compute the difference in usec between two fi_mstamp
 * @t1: pointer to newest sample
 * @t0: pointer to oldest sample
 */
static u32 fi_mstamp_us_delta(struct fi_mstamp *t1, struct fi_mstamp *t0)
{
	s32 delta_us = t1->stamp_us - t0->stamp_us;
	u32 delta_jiffies = t1->stamp_jiffies - t0->stamp_jiffies;

	/* If delta_us is negative, this might be because interval is too big,
	 * or local_clock() drift is too big : fallback using jiffies.
	 */
	if ((delta_us <= 0) || (delta_jiffies >= (INT_MAX / (USEC_PER_SEC / HZ))))
		delta_us = jiffies_to_usecs(delta_jiffies);

	return delta_us;
}

void fi_bw_calc(struct fi_flow_node *flow)
{
	uint32_t delta_us;

	if ((flow->rcv_bw.first_rcv_time.stamp_jiffies == 0) && (flow->rcv_bw.first_rcv_time.stamp_us == 0))
		return;
	delta_us = fi_mstamp_us_delta(&(flow->rcv_bw.last_rcv_time), &(flow->rcv_bw.first_rcv_time));
	if (flow->rcv_bw.total_bytes == 0) {
		if (flow->rcv_bw.burst_bytes < FI_MIN_BURST_SIZE || delta_us * FI_TIMER_INTERVAL < USEC_PER_SEC)
			return;
	}
	if (flow->rcv_bw.burst_bytes >= FI_MIN_BURST_SIZE) {
		flow->rcv_bw.total_bytes += flow->rcv_bw.burst_bytes;
		flow->rcv_bw.total_time += delta_us;
	}
	if (flow->rcv_bw.total_time < FI_MIN_BURST_DURATION)
		flow->qos.bw_est = (uint64_t)flow->rcv_bw.total_bytes * USEC_PER_SEC / FI_MIN_BURST_DURATION;
	else
		flow->qos.bw_est = (uint64_t)flow->rcv_bw.total_bytes * USEC_PER_SEC / flow->rcv_bw.total_time;
	flow->rcv_bw.total_bytes = 0;
	flow->rcv_bw.total_time = 0;
}

void fi_bw_update(struct fi_flow_node *flow)
{
	if (flow->rcv_bw.burst_bytes > FI_MIN_BURST_SIZE) {
		uint32_t delta_us = fi_mstamp_us_delta(&(flow->rcv_bw.last_rcv_time), &(flow->rcv_bw.first_rcv_time));
		fi_logd("burst: uid %u, sport: %u, burst_bytes: %u, delta_us: %u",
			flow->uid, flow->sport, flow->rcv_bw.burst_bytes, delta_us);
		delta_us = (delta_us > FI_MIN_BURST_DURATION) ? delta_us : FI_MIN_BURST_DURATION;
		flow->rcv_bw.total_bytes += flow->rcv_bw.burst_bytes;
		flow->rcv_bw.total_time += delta_us;
	}
}

void fi_rtt_update(struct fi_flow_node *flow)
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
			flow->qos.rtt = tp->total_retrans * USEC_PER_SEC;
		else
			flow->qos.rtt = 0;
		fi_logd("syn time out, set rtt = %u", flow->qos.rtt);
		return;
	}
	if (tp->rcv_rtt_est.rtt_us == 0) {
		flow->qos.rtt = srtt;
		return;
	}
	delta_us = tcp_stamp_us_delta(now_mstamp, rcv_rtt_time);
	/*lint -e666*/
	if (time_before(now_jiffies, srtt_time + msecs_to_jiffies(MSEC_PER_SEC)) ||
			time_before(now_jiffies, srtt_time + usecs_to_jiffies(delta_us)) || srtt < tp->rcv_rtt_est.rtt_us)
		flow->qos.rtt = srtt;
	else
		flow->qos.rtt = tp->rcv_rtt_est.rtt_us;
	/*lint +e666*/
}

void fi_qos_update(const struct sk_buff *skb, struct fi_flow_node *flow)
{
	uint32_t max_delta;
	uint32_t delta_time_last;
	uint32_t delta_time_first;
	struct fi_mstamp now;
	fi_mstamp_get(&now);
	if (unlikely(flow->qos.rtt == 0))
		fi_rtt_update(flow);
	if (flow->sk == NULL || flow->sk->sk_protocol != IPPROTO_TCP)
		return;
	max_delta = flow->qos.rtt >> 1;
	delta_time_last = fi_mstamp_us_delta(&now, &(flow->rcv_bw.last_rcv_time));
	delta_time_first = fi_mstamp_us_delta(&now, &(flow->rcv_bw.first_rcv_time));
	fi_logd(" dev %s, sport %u, jiffies %u us %u seq %u len %u", flow->flow_ctx.flow_msg.dev, flow->sk->sk_num,
		now.stamp_jiffies, now.stamp_us, TCP_SKB_CB(skb)->seq, skb->len);
	if (delta_time_last <= max_delta || delta_time_last <= FI_MIN_DELTA_US || delta_time_first <= flow->qos.rtt) {
		flow->rcv_bw.burst_bytes += skb->len;
	} else {
		fi_bw_update(flow);
		flow->rcv_bw.first_rcv_time = now;
		flow->rcv_bw.burst_bytes = 0;
	}
	flow->rcv_bw.last_rcv_time = now;
	flow->qos.rcv_bytes += skb->len;
}

void fi_filesize_update(const struct sk_buff *skb, struct fi_flow_node *flow)
{
	uint32_t download_bytes;
	flow->flow_ctx.up_pkt_num++;
	if (skb->len <= skb_transport_offset(skb) + tcp_hdrlen(skb) ||
		(flow->sk == NULL || flow->sk->sk_protocol != IPPROTO_TCP)) {
		return;
	} else {
		struct tcp_sock *tp = tcp_sk(flow->sk);
		if (unlikely(flow->file_size.last_rcv_bytes == 0)) {
			flow->file_size.last_rcv_bytes = tp->bytes_received;
			return;
		}

		if (tp->bytes_received < flow->file_size.last_rcv_bytes)
			return;

		download_bytes = tp->bytes_received - flow->file_size.last_rcv_bytes;
		flow->file_size.last_rcv_bytes = tp->bytes_received;
		if (download_bytes > flow->file_size.size) {
			flow->file_size.size = download_bytes;
			fi_logd("sport %u filesize %u", flow->sk->sk_num, flow->file_size.size);
		}
	}
}

int fi_iface_msg_by_index(char *data, int index, uint32_t size)
{
	struct fi_iface_msg iface_msg;
	struct net_device *dev = NULL;
	struct rtnl_link_stats64 stats;
	char *iface = NULL;
	int ret;
	iface = emcom_xengine_get_network_iface_name(index);
	ret = strncpy_s(iface_msg.dev, IFNAMSIZ, iface, strlen(iface));
	if (ret != EOK) {
		fi_loge("strncpy_s failed ret: %d, iface: %s", ret, iface);
		return -1;
	}

	dev = dev_get_by_name(&init_net, iface);
	if (dev) {
		read_lock(&dev_base_lock);
		dev_get_stats(dev, &stats);
		read_unlock(&dev_base_lock);
		dev_put(dev);
		if (stats.rx_bytes > g_fi_iface_bytes[index])
			iface_msg.rcv_bytes = stats.rx_bytes - g_fi_iface_bytes[index];
		else
			iface_msg.rcv_bytes = 0;
		g_fi_iface_bytes[index] = stats.rx_bytes;
	} else {
		iface_msg.rcv_bytes = 0;
		/* clear g_fi_iface_bytes if dev is off */
		g_fi_iface_bytes[index] = 0;
		iface_msg.dev[0] = '\0';
	}
	ret = memcpy_s(data + index * sizeof(struct fi_iface_msg), size - index * sizeof(struct fi_iface_msg),
		&iface_msg, sizeof(struct fi_iface_msg));
	if (ret != EOK) {
		fi_loge("memcpy_s failed ret: %d, size: %u", ret, size);
		return -1;
	}
	return 0;
}

int fi_get_primary_dev()
{
	int bitCnt = 0;
	uint32_t maxRate = 0;
	uint32_t secRate = 0;
	uint32_t i;
	int maxDev = FI_DEV_INVALID;
	int secDev = FI_DEV_INVALID;
	for (i = 0; i < FI_DEV_NUM; i++) {
		if (g_fi_iface_bytes[i]) {
			bitCnt++;
			if (maxDev == FI_DEV_INVALID) {
				maxDev = i;
				maxRate = g_fi_iface_bytes[i];
				continue;
			}
			if (g_fi_iface_bytes[i] > maxRate) {
				secDev = maxDev;
				secRate = maxRate;
				maxDev = i;
				maxRate = g_fi_iface_bytes[i];
			} else if (g_fi_iface_bytes[i] > secRate) {
				secDev = i;
				secRate = g_fi_iface_bytes[i];
			}
		}
	}
	fi_logd("dev info.bitCnt:%d, maxDev:%d, secDev:%d, maxRate:%u, secRate:%u",
		bitCnt, maxDev, secDev, maxRate, secRate);
	if (bitCnt > 1) {
		if (maxRate > (secRate << 1)) {
			return maxDev;
		}
	} else {
		return maxDev;
	}
	return FI_DEV_INVALID;
}

void fi_iface_report(void)
{
	int i;
	uint32_t size = sizeof(struct fi_iface_msg) * FI_DEV_NUM;
	char *data = NULL;
	struct sk_buff *pskb = NULL;
	if (!g_fi_ctx.iface_qos_rpt_enable) {
		return;
	}
	pskb = fi_get_netlink_skb(FI_IFACE_MSG_RPT, size, &data);
	if (pskb == NULL) {
		fi_loge("failed to malloc memory for data");
		return;
	}
	for (i = 0; i < FI_DEV_NUM; i++) {
		if (fi_iface_msg_by_index(data, i, size) != 0) {
			kfree_skb(pskb);
			return;
		}
	}
	fi_enqueue_netlink_skb(pskb);
	return;
}
