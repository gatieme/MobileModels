/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_charge_scp_auth.h
 *
 * authenticate for reverse scp charge
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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

#ifndef _REVERSE_CHARGE_SCP_AUTH_H_
#define _REVERSE_CHARGE_SCP_AUTH_H_

#include <linux/errno.h>

#define RSCP_AUTH_HASH_LEN             16
#define RSCP_AUTH_RANDOM_LEN           17
#define RSCP_AUTH_WAIT_TIMEOUT         2000
#define RSCP_AUTH_GENL_OPS_NUM         1

#define RSCP_AUTH_RETRY_COUNT           150
#define RSCP_AUTH_RETRY_INTERVAL_CYCLE  10
#define RSCP_AUTH_RETRY_INTERVAL_BASE   30
#define RSCP_AUTH_RETRY_INTERVAL_INC    25

#ifdef CONFIG_REVERSE_CHARGE
bool rscp_auth_get_srv_state(void);
int rscp_auth_wait_completion(void);
void rscp_auth_clean_hash_data(void);
u8 *rscp_auth_get_hash_data_header(void);
unsigned int rscp_auth_get_hash_data_size(void);
#else
static inline bool rscp_auth_get_srv_state(void)
{
	return false;
}

static inline void rscp_auth_clean_hash_data(void)
{
}

static inline u8 *rscp_auth_get_hash_data_header(void)
{
	return NULL;
}

static inline unsigned int rscp_auth_get_hash_data_size(void)
{
	return 0;
}

static inline int rscp_auth_wait_completion(void)
{
	return -EPERM;
}
#endif /* CONFIG_REVERSE_CHARGE */

#endif /* _REVERSE_CHARGE_SCP_AUTH_H_ */
