/*
 * cloud_network_nat.h
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
#ifndef _CLOUD_NETWORK_NAT_H_
#define _CLOUD_NETWORK_NAT_H_

#include <linux/skbuff.h>

int cloud_network_nat_tx(struct sk_buff *skb);
int cloud_network_nat_rx(struct sk_buff *skb, struct session *ss);
#endif
