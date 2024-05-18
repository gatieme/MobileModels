/*
 * vsim.h
 *
 * monitor vsim traffic
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef __HNRIL_VSIM_H
#define __HNRIL_VSIM_H
#include <net/genetlink.h>
#include <linux/version.h>

int vsim_set_ifname(struct sk_buff *skb, struct genl_info *info);
int vsim_reset_ifname(struct sk_buff *skb, struct genl_info *info);
int vsim_reset_counter(struct sk_buff *skb, struct genl_info *info);
int vsim_get_flow(struct sk_buff *skb, struct genl_info *info);
void vsim_l2_check(struct sk_buff *skb, struct net_device *dev_output);
void vsim_notify_tether_stats(const char *ifname, uint64_t tether_rx_bytes, uint64_t tether_tx_bytes);
int vsim_init(void);
#endif	/* __HNRIL_VSIM_H */
