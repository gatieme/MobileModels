/*
 * Copyright (c) Honor Device Co., Ltd 2021-2021. All rights reserved.
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

#include "vsim.h"
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv6.h>
#include "hnril_netlink.h"

#ifdef CONFIG_TZDRIVER
extern int TC_NS_RegisterServiceCallbackFunc(const char *uuid, void *func,
	const void *private_data);
#endif

struct teec_timer_property_stru {
	unsigned int time_type; /* Timer Type */
	unsigned int time_id;   /* Timer ID */
	unsigned int rev1;
	unsigned int rev2;
};

static unsigned int vsim_hook(void *priv,
	struct sk_buff *skb,
	const struct nf_hook_state *state);

#define NOTIFY_THRESH 1024 // 1KB
#define NOTIFY_INTERVAL HZ
#define IP_PKT_MAX_LEN 70000

static DEFINE_SPINLOCK(vsim_lock);
static char vsim_ifname[IFNAMSIZ] = {0};
static unsigned long rx_bytes;
static unsigned long tx_bytes;
static unsigned long total_bytes;
static unsigned long prev_bytes;
static unsigned long prev_jiffies;
static struct timer_list notify_timer;

static struct nf_hook_ops vsim_hooks[] = {
	{
		.hook = vsim_hook,
		.pf = PF_INET,
		.hooknum = NF_INET_PRE_ROUTING,
		.priority = NF_IP_PRI_RAW - 1,
	},
	{
		.hook = vsim_hook,
		.pf = PF_INET,
		.hooknum = NF_INET_POST_ROUTING,
		.priority = NF_IP_PRI_MANGLE + 1,
	},
	{
		.hook = vsim_hook,
		.pf = PF_INET6,
		.hooknum = NF_INET_PRE_ROUTING,
		.priority = NF_IP6_PRI_RAW - 1,
	},
	{
		.hook = vsim_hook,
		.pf = PF_INET6,
		.hooknum = NF_INET_POST_ROUTING,
		.priority = NF_IP6_PRI_MANGLE + 1,
	},
};

int vsim_set_ifname(struct sk_buff *skb, struct genl_info *info)
{
	char *ifname = NULL;

	if (!info || !info->attrs) {
		pr_info("vsim: null attr");
		return 0;
	}
	if (info->attrs[HNRIL_ATTR_VSIM_IFNAME])
		ifname = nla_data(info->attrs[HNRIL_ATTR_VSIM_IFNAME]);

	if (!ifname) {
		pr_info("vsim: null ifname");
		return 0;
	}
	spin_lock_bh(&vsim_lock);
	strlcpy(vsim_ifname, ifname, IFNAMSIZ);
	spin_unlock_bh(&vsim_lock);
	pr_info("vsim: set ifname %s", ifname);
	return 0;
}

int vsim_reset_ifname(struct sk_buff *skb, struct genl_info *info)
{
	pr_info("vsim: reset ifname");
	spin_lock_bh(&vsim_lock);
	vsim_ifname[0] = '\0';
	spin_unlock_bh(&vsim_lock);
	return 0;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
void vsim_flow_notify(unsigned long data)
#else
void vsim_flow_notify(struct timer_list *t)
#endif
{
	int err;

	spin_lock_bh(&vsim_lock);
	err = hnril_nl_vsim_flow_notify(tx_bytes, rx_bytes);
	pr_info("vsim: flow notify tx=%llu rx=%llu err=%d", tx_bytes, rx_bytes, err);
	prev_bytes = total_bytes;
	prev_jiffies = jiffies;
	spin_unlock_bh(&vsim_lock);
}

int vsim_get_flow(struct sk_buff *skb, struct genl_info *info)
{
	vsim_flow_notify(0);
	return 0;
}

bool vsim_match_ifname(const char *ifname)
{
	if (likely(vsim_ifname[0] == '\0'))
		return false;
	return !strncmp(vsim_ifname, ifname, IFNAMSIZ);
}

void vsim_maybe_notify(void)
{
	if (total_bytes - prev_bytes < NOTIFY_THRESH)
		return;
	if (timer_pending(&notify_timer))
		return;

	if (time_after(jiffies, prev_jiffies + NOTIFY_INTERVAL))
		mod_timer(&notify_timer, jiffies);
	else
		mod_timer(&notify_timer, prev_jiffies + NOTIFY_INTERVAL);
}

int vsim_reset_counter(struct sk_buff *skb, struct genl_info *info)
{
	pr_info("vsim: reset counter");
	spin_lock_bh(&vsim_lock);
	rx_bytes = 0;
	tx_bytes = 0;
	total_bytes = 0;
	prev_bytes = 0;
	spin_unlock_bh(&vsim_lock);
	return 0;
}

static unsigned int vsim_hook(void *priv,
	struct sk_buff *skb,
	const struct nf_hook_state *state)
{
	if (unlikely(skb == NULL || skb->dev == NULL || state == NULL))
		return NF_ACCEPT;

	if (unlikely(!spin_trylock_bh(&vsim_lock)))
		return NF_ACCEPT;
	if (likely(!vsim_match_ifname(skb->dev->name))) {
		spin_unlock_bh(&vsim_lock);
		return NF_ACCEPT;
	}
	if (state->in)
		rx_bytes += skb->len;
	else
		tx_bytes += skb->len;
	total_bytes += skb->len;
	vsim_maybe_notify();
	spin_unlock_bh(&vsim_lock);
	return NF_ACCEPT;
}

// Statistics of traffic shared by hotspots
void vsim_l2_check(struct sk_buff *skb, struct net_device *dev_output) {
	if (unlikely(skb == NULL || skb->dev == NULL))
		return;
	if (unlikely(!spin_trylock_bh(&vsim_lock)))
		return;
	if (likely(vsim_ifname[0] == '\0')) {
		spin_unlock_bh(&vsim_lock);
		return;
	}

	if (!strncmp(vsim_ifname, skb->dev->name, IFNAMSIZ)) {
		unsigned int ip_len = skb->len - skb->mac_len;
		if (likely(ip_len > 0 && ip_len < IP_PKT_MAX_LEN)) {
			rx_bytes += ip_len;
			total_bytes += ip_len;
			vsim_maybe_notify();
		}
	} else if (!strncmp(vsim_ifname, dev_output->name, IFNAMSIZ)) {
		unsigned int ip_len = skb->len - skb->mac_len;
		if (likely(ip_len > 0 && ip_len < IP_PKT_MAX_LEN)) {
			tx_bytes += ip_len;
			total_bytes += ip_len;
			vsim_maybe_notify();
		}
	}

	spin_unlock_bh(&vsim_lock);
	return;
}

void vsim_notify_tether_stats(const char *ifname, uint64_t tether_rx_bytes, uint64_t tether_tx_bytes)
{
	if (unlikely(!spin_trylock_bh(&vsim_lock))) {
		return;
	}
	if (likely(!vsim_match_ifname(ifname))) {
		spin_unlock_bh(&vsim_lock);
		return;
	}

	pr_info("%s: ifname:%s, rx_bytes:%lu, tx_bytes:%lu", __func__, ifname, tether_rx_bytes, tether_tx_bytes);
	rx_bytes += tether_rx_bytes;
	tx_bytes += tether_tx_bytes;
	total_bytes += (tether_rx_bytes + tether_tx_bytes);
	vsim_maybe_notify();
	spin_unlock_bh(&vsim_lock);
}
EXPORT_SYMBOL_GPL(vsim_notify_tether_stats);

void vsim_tee_timeout_callback(void *timer_data_callback)
{
	struct teec_timer_property_stru *timer_data = NULL;

	pr_info("%s enter", __func__);
	if (timer_data_callback == NULL) {
		pr_err("%s: para error!", __func__);
		return;
	}

	timer_data = (struct teec_timer_property_stru *)timer_data_callback;
	spin_lock_bh(&vsim_lock);
	hnril_nl_vsim_tee_notify(timer_data->time_type);
	spin_unlock_bh(&vsim_lock);
	pr_info("%s, time_type = %d", __func__, timer_data->time_type);
}

void regist_vsim_tcc_timeout(void)
{
#ifdef CONFIG_TZDRIVER
	// this uuid must same as skytone APK, used in tee OS to check validity
	const unsigned char uuid[] = {
		0x47, 0x91, 0xe8, 0xab, 0x61, 0xcd, 0x3f, 0xf4, 0x71, 0xc4,
			0x1a, 0x31, 0x7e, 0x40, 0x53, 0x12
	};
	pr_info("%s\n", __func__);

	if (TC_NS_RegisterServiceCallbackFunc((const char *)uuid, vsim_tee_timeout_callback, NULL) != 0) {
		pr_err("%s regist tee timeout cb Fail", __func__);
		return;
	}
#endif
	pr_info("%s regist tee timeout cb ok", __func__);
}

int vsim_init(void)
{
	int err;
	pr_info("vsim: init");
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
	init_timer(&notify_timer);
#else
	timer_setup(&notify_timer, NULL, 0);
#endif
	notify_timer.function = vsim_flow_notify;
	prev_jiffies = jiffies;
	err = nf_register_net_hooks(&init_net, vsim_hooks, ARRAY_SIZE(vsim_hooks));
	regist_vsim_tcc_timeout();
	return err;
}
