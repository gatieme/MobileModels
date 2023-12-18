/*
 * hw_klinkaware.h
 *
 * This file use to handle packet
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#ifndef HW_KLINKAWARE_H
#define HW_KLINKAWARE_H

#define IPV4_MAX_LEN 15

#include <net/sock.h>
#include <linux/skbuff.h>

int set_key_uid(const char *info);
void pg_hook_dl_stub(struct sock *sk, struct sk_buff *skb, unsigned int len);
void pg_hook_mc_add(struct sock *sk, __be32 addr);
void pg_hook_mc_del(struct sock *sk, __be32 addr);
int set_proxy_addr(const char *info);
char *pg_get_proxy_addr(void);

#endif
