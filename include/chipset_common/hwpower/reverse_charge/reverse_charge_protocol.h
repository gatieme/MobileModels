/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_charge_protocol.h
 *
 * reverse charge protocol api
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

#ifndef _REVERSE_CHARGE_PROTOCOL_H_
#define _REVERSE_CHARGE_PROTOCOL_H_

#ifdef CONFIG_REVERSE_CHARGE
int rprot_ic_reset(void);
int rprot_get_rt_ibus(void);
int rprot_update_vbus(int vbus);
int rprot_update_drop_cur(int ibus);
int rprot_enable_rscp(int enable);
int rprot_enable_sleep(int enable);
int rprot_get_request_vbus(void);
int rprot_get_request_ibus(void);
int rprot_check_protocol_state(void);
int rprot_detect_device(void);
int rprot_get_dev_det_result(void);
int rprot_auth_process(void);
int rprot_get_random_value(u8 *data, int data_len);
int rprot_set_rscp_auth_result(u8 *auth_result, int len);
int rprot_set_power_curve(struct rchg_power_curve* power_curve);
#else
static inline int rprot_ic_reset(void)
{
	return 0;
}

static inline int rprot_get_rt_ibus(void)
{
	return 0;
}

static inline int rprot_update_vbus(int vbus)
{
	return 0;
}

static inline int rprot_update_drop_cur(int ibus)
{
	return 0;
}

static inline int rprot_enable_rscp(int enable)
{
	return 0;
}

static inline int rprot_enable_sleep(int enable)
{
	return 0;
}

static inline int rprot_get_request_vbus(void)
{
	return 0;
}

static inline int rprot_get_request_ibus(void)
{
	return 0;
}

static inline int rprot_check_protocol_state(void)
{
	return 0;
}

static inline int rprot_detect_device(void)
{
	return 0;
}

static inline int rprot_get_dev_det_result(void)
{
	return 0;
}
static inline int rprot_auth_process(void)
{
	return 0;
}
static inline int rprot_get_random_value(u8 *data, int data_len)
{
	return 0;
}
static inline int rprot_set_rscp_auth_result(u8 *cipherkey, int len)
{
	return 0;
}
static inline int rprot_set_power_curve(struct rchg_power_curve* power_curve)
{
	return 0;
}
#endif

#endif /* _REVERSE_CHARGE_PROTOCOL_H_ */
