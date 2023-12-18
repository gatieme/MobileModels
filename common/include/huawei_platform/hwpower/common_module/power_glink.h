/* SPDX-License-Identifier: GPL-2.0 */
/*
 * power_glink.h
 *
 * glink channel for power module
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _POWER_GLINK_H_
#define _POWER_GLINK_H_

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK)
int power_glink_get_property_value(u32 prop_id, u32 *data_buffer, u32 data_size);
int power_glink_set_property_value(u32 prop_id, u32 *data_buffer, u32 data_size);
void power_glink_handle_charge_notify_message(u32 id, u32 msg);
void power_glink_handle_usb_notify_message(u32 id, u32 msg);
int power_glink_support_fcp_pd_icl(void);
bool is_dcp_ever_detected(void);
void power_glink_handle_dc_connect_message(u32 msg);
void power_glink_handle_charge_type_message(u32 msg);
#else
static inline int power_glink_get_property_value(u32 prop_id, u32 *data_buffer, u32 data_size)
{
	return 0;
}

static inline int power_glink_set_property_value(u32 prop_id, u32 *data_buffer, u32 data_size)
{
	return 0;
}

static inline void power_glink_handle_charge_notify_message(u32 id, u32 msg)
{
}

static inline void power_glink_handle_usb_notify_message(u32 id, u32 msg)
{
}

static inline int power_glink_support_fcp_pd_icl(void)
{
	return 0;
}

static inline bool is_dcp_ever_detected(void)
{
	return false;
}

static inline void power_glink_handle_dc_connect_message(u32 msg)
{
}

static inline void power_glink_handle_charge_type_message(u32 msg)
{
}
#endif /* CONFIG_HUAWEI_POWER_GLINK */

#endif /* _POWER_GLINK_H_ */
