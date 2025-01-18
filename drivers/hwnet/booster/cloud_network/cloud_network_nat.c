/*
 * cloud_network_nat.c
 *
 * cloud network path select methods module implementation
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

#include <linux/types.h>
#include <linux/spinlock.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/gfp.h>
#include <linux/version.h>
#include <linux/icmp.h>
#include <securec.h>
#include <net/checksum.h>
#include <net/udp.h>
#include <linux/if_arp.h>
#include <net/arp.h>

#include "cloud_network_session.h"
#include "cloud_network_tx.h"
#include "cloud_network_rx.h"
#include "cloud_network_utils.h"
#include "cloud_network_device.h"

int cloud_network_nat_process_udp(struct sk_buff *skb, __be32 addr, __be32 new_addr)
{
	int ihl;
	struct iphdr *iph = NULL;
	struct udphdr *udph = NULL;

	if (unlikely(!skb))
		return ERROR;
	iph = (struct iphdr *)(skb->data);
	ihl = iph->ihl * 4;

	if (!pskb_may_pull(skb, ihl + sizeof(*udph)))
		return ERROR;
	udph = (void *)(skb->data + ihl);
	if (udph->check || skb->ip_summed == CHECKSUM_PARTIAL) {
		inet_proto_csum_replace4(&udph->check, skb, addr,
					new_addr, true);
		if (!udph->check)
			udph->check = CSUM_MANGLED_0;
	}
	return SUCCESS;
}

int cloud_network_nat_process_tcp(struct sk_buff *skb, __be32 addr, __be32 new_addr)
{
	int ihl;
	struct iphdr *iph = NULL;
	struct tcphdr *tcph = NULL;
	if (unlikely(!skb))
		return ERROR;
	iph = (struct iphdr *)(skb->data);
	ihl = iph->ihl * 4;

	if (!pskb_may_pull(skb, ihl + sizeof(*tcph)))
		return ERROR;
	tcph = (void *)(skb->data + ihl);
	if (tcph->syn)
		tcp_mss_replace(skb, tcph);
	inet_proto_csum_replace4(&tcph->check, skb, addr, new_addr,
				true);

	return SUCCESS;
}

int cloud_network_nat_process_icmp_tx(struct sk_buff *skb, __be32 saddr, __be32 new_saddr)
{
	struct icmphdr *icmph = NULL;
	struct iphdr *iph = NULL;
	if (unlikely(!skb))
		return ERROR;

	iph = (struct iphdr *)(skb->data);
	int ihl = iph->ihl * 4;
	icmph = (void *)(skb->data + ihl);
	if (!icmp_is_err(icmph->type))
		return SUCCESS;

	iph = (void *)(icmph + 1);
	saddr = iph->saddr;
	/* XXX Fix up the inner checksums. */
	iph->saddr = new_saddr;
	inet_proto_csum_replace4(&icmph->checksum, skb, saddr, new_saddr,
					false);
	return SUCCESS;
}

int cloud_network_nat_process_icmp_rx(struct sk_buff *skb, __be32 daddr, __be32 new_daddr)
{
	struct icmphdr *icmph = NULL;
	struct iphdr *iph = NULL;
	if (unlikely(!skb))
		return ERROR;

	iph = (struct iphdr *)(skb->data);
	int ihl = iph->ihl * 4;
	if (!pskb_may_pull(skb, ihl + sizeof(*icmph)))
		return ERROR;

	icmph = (void *)(skb->data + ihl);
	if (!icmp_is_err(icmph->type))
		return SUCCESS;

	if (!pskb_may_pull(skb, ihl + sizeof(*icmph) + sizeof(*iph)))
		return ERROR;

	icmph = (void *)(skb->data + ihl);
	iph = (void *)(icmph + 1);
	daddr = iph->daddr;
	/* XXX Fix up the inner checksums. */
	iph->daddr = new_daddr;
	inet_proto_csum_replace4(&icmph->checksum, skb, daddr, new_daddr,
					false);
	return SUCCESS;
}

int nat_tx_process_header(struct sk_buff *skb, int role_id)
{
	__be32 saddr;
	__be32 new_saddr;
	struct iphdr *iph = NULL;
	if (unlikely(!skb))
		return ERROR;

	iph = (struct iphdr *)(skb->data);
	saddr = iph->saddr;
	new_saddr = cloud_network_inet_select_addr(role_id);
	if (new_saddr == 0)
		return ERROR;
	iph->saddr = new_saddr;
	csum_replace4(&iph->check, saddr, new_saddr);
	switch (iph->frag_off & htons(IP_OFFSET) ? 0 : iph->protocol) {
	case IPPROTO_TCP:
		return cloud_network_nat_process_tcp(skb, saddr, new_saddr);
	case IPPROTO_UDP:
		return cloud_network_nat_process_udp(skb, saddr, new_saddr);
	case IPPROTO_ICMP:
		return cloud_network_nat_process_icmp_tx(skb, saddr, new_saddr);
	case 0:
		return SUCCESS;
	default:
		return ERROR;
	}
}

int nat_rx_process_header(struct sk_buff *skb, struct session *ss)
{
	if (!skb || !ss || !ss->before_ss)
		return ERROR;

	__be32 new_daddr = ss->before_ss->saddr;
	struct iphdr *iph = (struct iphdr *)(skb->data);
	__be32 daddr = iph->daddr;

	iph->daddr = new_daddr;

	csum_replace4(&iph->check, daddr, new_daddr);
	skb_reset_network_header(skb);
	skb_set_transport_header(skb, ip_hdr(skb)->ihl * 4);

	switch (iph->frag_off & htons(IP_OFFSET) ? 0 : iph->protocol) {
	case IPPROTO_TCP:
		return cloud_network_nat_process_tcp(skb, daddr, new_daddr);
	case IPPROTO_UDP:
		return cloud_network_nat_process_udp(skb, daddr, new_daddr);
	case IPPROTO_ICMP:
		return cloud_network_nat_process_icmp_rx(skb, daddr, new_daddr);
	case 0:
		return SUCCESS;
	default:
		return ERROR;
	}
}

int cloud_network_nat_tx(struct sk_buff *skb)
{
	struct session *ss = NULL;
	struct session *after_ss = NULL;
	struct iphdr *iph = NULL;
	int role_id;
	if (unlikely(skb == NULL))
		return ERROR;

	ss = session_manage(skb, NULL);
	if (ss == NULL)
		return ERROR;

	role_id = select_default_network_role_id();
	skb->dev = get_net_device(role_id);

	if (role_id == ERROR) {
		session_put(ss);
		return ERROR;
	}
	if (nat_tx_process_header(skb, role_id) == ERROR) {
		session_put(ss);
		return ERROR;
	}

	after_ss = session_manage(skb, ss);
	if (after_ss == NULL) {
		session_put(ss);
		return ERROR;
	}

	if (cloud_network_set_mac(skb, 0x1 << role_id) == ERROR) {
		session_put(after_ss);
		session_put(ss);
		return ERROR;
	}

	if (dev_queue_xmit(skb) != NET_XMIT_SUCCESS)
		log_err("send skb loss, dev_type = %d", 0x1 << role_id);

	session_put(after_ss);
	session_put(ss);
	return SUCCESS;
}

int cloud_network_nat_rx(struct sk_buff *skb, struct session *ss)
{
	struct net_device *dst_dev = NULL;
	if (unlikely(!skb || !ss))
		return ERROR;

	dst_dev = cloud_network_get_tun();
	if (dst_dev == NULL) {
		log_err("rx cannot find dst dev");
		return ERROR;
	}
	if (nat_rx_process_header(skb, ss) == ERROR)
		return ERROR;

	skb->dev = dst_dev;
	skb->skb_iif = dst_dev->ifindex;
	skb->mac_len = 0;
	netif_rx_any_context(skb);
	return SUCCESS;
}