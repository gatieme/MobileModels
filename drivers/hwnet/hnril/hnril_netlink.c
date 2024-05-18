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

#include "hnril_netlink.h"
#include <linux/if.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <net/genetlink.h>
#include "vsim.h"

static const struct nla_policy hnril_policy[HNRIL_ATTR_MAX + 1] = {
	[HNRIL_ATTR_VSIM_IFNAME] = {
		.type = NLA_NUL_STRING,
		.len = IFNAMSIZ - 1 },
	[HNRIL_ATTR_VSIM_TX_BYTES] = { .type = NLA_U64 },
	[HNRIL_ATTR_VSIM_RX_BYTES] = { .type = NLA_U64 },
	[HNRIL_ATTR_VSIM_TEE_TASK] = { .type = NLA_U32 },
};

static struct genl_ops hnril_genl_ops[] = {
	{
		.cmd = HNRIL_CMD_VSIM_SET_IFNAME,
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
		.policy = hnril_policy,
#endif
		.doit = vsim_set_ifname
	},
	{
		.cmd = HNRIL_CMD_VSIM_RESET_IFNAME,
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
		.policy = hnril_policy,
#endif
		.doit = vsim_reset_ifname
	},
	{
		.cmd = HNRIL_CMD_VSIM_RESET_COUNTER,
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
		.policy = hnril_policy,
#endif
		.doit = vsim_reset_counter
	},
	{
		.cmd = HNRIL_CMD_VSIM_GET_FLOW,
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,19,0)
		.policy = hnril_policy,
#endif
		.doit = vsim_get_flow
	},
};

struct genl_multicast_group hnril_mcgrps[] = {
	{ .name = "events" },
};

static struct genl_family hnril_genl_family = {
	.hdrsize = 0,
	.name = HNRIL_GENL_FAMILY,
	.version = 1,
	.maxattr = HNRIL_ATTR_MAX,
	.ops = hnril_genl_ops,
	.n_ops = ARRAY_SIZE(hnril_genl_ops),
	.mcgrps = hnril_mcgrps,
	.n_mcgrps = ARRAY_SIZE(hnril_mcgrps),
};

int hnril_nl_vsim_flow_notify(u64 tx_bytes, u64 rx_bytes)
{
	struct sk_buff *skb = NULL;
	void *hdr = NULL;
	skb = genlmsg_new(GENLMSG_DEFAULT_SIZE, GFP_ATOMIC);
	if (!skb) {
		pr_info("%s: no mem", __func__);
		return -ENOMEM;
	}

	hdr = genlmsg_put(skb, 0, 0, &hnril_genl_family, 0, HNRIL_CMD_VSIM_NOTIFY);
	if (!hdr) {
		pr_info("%s: msg size error", __func__);
		nlmsg_free(skb);
		return -EMSGSIZE;
	}

	if (nla_put_u64_64bit(skb, HNRIL_ATTR_VSIM_TX_BYTES, tx_bytes, HNRIL_ATTR_PAD)) {
		pr_info("%s: msg size error", __func__);
		genlmsg_cancel(skb, hdr);
		nlmsg_free(skb);
		return -EMSGSIZE;
	}
	if (nla_put_u64_64bit(skb, HNRIL_ATTR_VSIM_RX_BYTES, rx_bytes, HNRIL_ATTR_PAD)) {
		pr_info("%s: msg size error", __func__);
		genlmsg_cancel(skb, hdr);
		nlmsg_free(skb);
		return -EMSGSIZE;
	}
	genlmsg_end(skb, hdr);
	return genlmsg_multicast(&hnril_genl_family, skb, 0, 0, GFP_ATOMIC);
}

int hnril_nl_vsim_tee_notify(u32 task_type)
{
	struct sk_buff *skb = NULL;
	void *hdr = NULL;

	skb = genlmsg_new(GENLMSG_DEFAULT_SIZE, GFP_ATOMIC);
	if (!skb) {
		pr_info("%s: no mem", __func__);
		return -ENOMEM;
	}

	hdr = genlmsg_put(skb, 0, 0, &hnril_genl_family, 0, HNRIL_CMD_VSIM_NOTIFY);
	if (!hdr) {
		pr_info("%s: msg size error", __func__);
		nlmsg_free(skb);
		return -EMSGSIZE;
	}

	if (nla_put_u32(skb, HNRIL_ATTR_VSIM_TEE_TASK, task_type)) {
		pr_info("%s: msg size error", __func__);
		genlmsg_cancel(skb, hdr);
		nlmsg_free(skb);
		return -EMSGSIZE;
	}
	genlmsg_end(skb, hdr);
	return genlmsg_multicast(&hnril_genl_family, skb, 0, 0, GFP_ATOMIC);
}

static int __init hnril_netlink_init(void)
{
	int err;

	pr_info("%s, netlink init", __func__);
	err = genl_register_family(&hnril_genl_family);
	if (err < 0) {
		pr_err("hnril: genl_register_family failed %d", err);
		return err;
	}

	/* init hnril module here */
	err = vsim_init();
	if (err < 0)
		pr_err("hnril: vsim_init failed %d", err);

	return 0;
}

static void __exit hnril_netlink_exit(void)
{
	int err;

	pr_info("hnril: exit");
	err = genl_unregister_family(&hnril_genl_family);
	if (err < 0)
		pr_err("hnril: genl_unregister_family failed %d", err);
}

module_init(hnril_netlink_init)
module_exit(hnril_netlink_exit)
