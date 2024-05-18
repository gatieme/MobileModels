/*
 * direct_charge_adapter.h
 *
 * adapter operate for direct charge
 *
 * Copyright (c) 2022 Honor Technologies Co., Ltd.
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

#ifndef _DIRECT_CHARGE_ADAPTER_H_
#define _DIRECT_CHARGE_ADAPTER_H_

#ifdef CONFIG_DIRECT_CHARGER
int dc_init_adapter(void);
int dc_reset_operate(int type);
int dc_get_adapter_type(void);
int dc_get_adapter_support_mode(void);
int dc_get_adapter_port_leakage_current(void);
int dc_get_adapter_voltage(int *value);
int dc_get_adapter_max_voltage(int *value);
int dc_get_adapter_min_voltage(int *value);
int dc_get_adapter_current(int *value);
int dc_get_adapter_current_set(int *value);
int dc_get_power_drop_current(int *value);
void dc_reset_adapter_power_curve(void *p);
int dc_get_adapter_power_curve(void);
int dc_get_adapter_max_current(int value);
int dc_get_adapter_temp(int *value);
int dc_get_protocol_register_state(void);
int dc_set_adapter_voltage(int value);
int dc_set_adapter_current(int value);
int dc_set_adapter_output_enable(int enable);
void dc_set_adapter_usbpd_enable(int enable);
void dc_set_adapter_default_param(void);
int dc_set_adapter_default(void);
int dc_update_adapter_info(void);
unsigned int dc_update_adapter_support_mode(void);
int dc_check_adapter_support_mode(int *mode);
int dc_check_adapter_antifake(void);
bool dc_is_ignore_cable_check(void);
#else
static inline int dc_init_adapter(void)
{
	return -1;
}

static inline int dc_reset_operate(int type)
{
	return -1;
}

static inline int dc_get_adapter_type(void)
{
	return 0;
}

static inline int dc_get_adapter_support_mode(void)
{
	return 0;
}

static inline int dc_get_adapter_port_leakage_current(void)
{
	return -1;
}

static inline int dc_get_adapter_voltage(int *value)
{
	return -1;
}

static inline int dc_get_adapter_max_voltage(int *value)
{
	return -1;
}

static inline int dc_get_adapter_min_voltage(int *value)
{
	return -1;
}

static inline int dc_get_adapter_current(int *value)
{
	return -1;
}

static inline int dc_get_adapter_current_set(int *value)
{
	return -1;
}

static inline int dc_get_power_drop_current(int *value)
{
	return -1;
}

static inline void dc_reset_adapter_power_curve(void *p)
{
}

static inline int dc_get_adapter_power_curve(void)
{
	return -1;
}

static inline int dc_get_adapter_max_current(int value)
{
	return 0;
}

static inline int dc_get_adapter_temp(int *value)
{
	return -1;
}

static inline int dc_get_protocol_register_state(void)
{
	return -1;
}

static inline int dc_set_adapter_voltage(int value)
{
	return -1;
}

static inline int dc_set_adapter_current(int value)
{
	return -1;
}

static inline int dc_set_adapter_output_enable(int enable)
{
	return -1;
}

static inline void dc_set_adapter_usbpd_enable(int enable)
{
}

static inline void dc_set_adapter_default_param(void)
{
}

static inline int dc_set_adapter_default(void)
{
	return -1;
}

static inline int dc_update_adapter_info(void)
{
	return -1;
}

static inline unsigned int dc_update_adapter_support_mode(void)
{
	return 0;
}

static inline int dc_check_adapter_support_mode(int *mode)
{
	return -1;
}

static inline int dc_check_adapter_antifake(void)
{
	return -1;
}

static inline bool dc_is_ignore_cable_check(void)
{
	return false;
}

#endif /* CONFIG_DIRECT_CHARGER */

#endif /* _DIRECT_CHARGE_ADAPTER_H_ */
