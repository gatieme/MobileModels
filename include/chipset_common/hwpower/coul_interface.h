/*
 * coul_interface.h
 *
 * interface for coul driver
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

#ifndef _COUL_INTERFACE_H_
#define _COUL_INTERFACE_H_

#include <linux/power_supply.h>

#define COUL_DEFAULT_TECHNOLOGY       POWER_SUPPLY_TECHNOLOGY_LIPO
#define COUL_DEFAULT_CAPACITY_LEVEL   POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN
#define COUL_DEFAULT_BRAND            "error_brand"
#define COUL_DEFAULT_TEMP             (-99)
#define COUL_CAPACITY_TH              7

enum coul_interface_type {
	COUL_TYPE_BEGIN = 0,
	COUL_TYPE_MAIN = COUL_TYPE_BEGIN,
	COUL_TYPE_AUX,
	COUL_TYPE_AUX2,
	COUL_TYPE_END,
};

enum coull_fg_type {
	COUL_FG_TYPE_BEGIN = 0,
	COUL_FG_TYPE_CW2217,
	COUL_FG_TYPE_RT9426,
	COUL_FG_TYPE_RT9426A,
	COUL_FG_TYPE_BQ27Z561,
	COUL_FG_TYPE_END,
};

struct coul_interface_ops {
	const char *type_name;
	void *dev_data;
	int (*is_coul_ready)(void *);
	int (*is_battery_exist)(void *);
	int (*get_battery_capacity)(void *);
	int (*get_battery_voltage)(void *);
	int (*get_battery_current)(void *);
	int (*get_battery_avg_current)(void *);
	int (*get_battery_temperature)(void *);
	int (*get_battery_cycle)(void *);
	int (*get_battery_fcc)(void *);
	int (*set_vterm_dec)(int, void *);
	void (*notify_charge_done)(void *);
	int (*set_battery_low_voltage)(int, void *);
	int (*get_battery_uv_irq_status)(void *);
	int (*set_battery_last_capacity)(int, void *);
	int (*get_battery_last_capacity)(void *);
	int (*get_battery_rm)(void *);
	void (*update_batt_param)(int, const char *);
	int (*get_battery_moved)(void *);
	void (*clear_battery_moved)(void*);
	int (*get_fg_type)(void *);
	int (*get_battery_resistance)(void *);
};

struct coul_interface_dev {
	unsigned int total_ops;
	struct coul_interface_ops *p_ops[COUL_TYPE_END];
};

#if IS_ENABLED(CONFIG_HONOR_COUL)
int coul_interface_ops_register(struct coul_interface_ops *ops);
int coul_interface_is_coul_ready(int type);
int coul_interface_is_battery_exist(int type);
int coul_interface_get_battery_capacity(int type);
int coul_interface_get_battery_rm(int type);
int coul_interface_get_battery_last_capacity(int type);
int coul_interface_set_battery_last_capacity(int type, int capacity);
int coul_interface_get_battery_voltage(int type);
int coul_interface_get_battery_current(int type);
int coul_interface_get_battery_avg_current(int type);
int coul_interface_get_battery_temperature(int type);
int coul_interface_get_battery_cycle(int type);
int coul_interface_get_battery_fcc(int type);
int coul_interface_set_vterm_dec(int type, int vterm_dec);
void coul_interface_notify_charge_done(int type);
int coul_interface_set_battery_low_voltage(int type, int val);
int coul_interface_get_battery_uv_irq_status(int type);
int coul_interface_get_battery_moved(int type);
void coul_interface_clear_battery_moved(int type);
int coul_interface_get_fg_type(int type);
int coul_interface_get_rbatt(int type);

//#ifdef CONFIG_HONOR_POWER_EMBEDDED_ISOLATION
void coul_interface_update_batt_param(int type, const char *barnd);
#else
static inline int coul_interface_ops_register(struct coul_interface_ops *ops)
{
	return -1;
}

static inline int coul_interface_is_coul_ready(int type)
{
	return 0;
}

static inline int coul_interface_is_battery_exist(int type)
{
	return 0;
}

static inline int coul_interface_get_battery_capacity(int type)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_rm(int type)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_last_capacity(int type)
{
	return -EPERM;
}

static inline int coul_interface_set_battery_last_capacity(int type, int capacity)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_voltage(int type)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_current(int type)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_avg_current(int type)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_temperature(int type)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_cycle(int type)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_fcc(int type)
{
	return -EPERM;
}

static inline int coul_interface_set_vterm_dec(int type, int vterm_dec)
{
	return 0;
}

static inline void coul_interface_notify_charge_done(int type)
{
}

static inline int coul_interface_set_battery_low_voltage(int type, int val)
{
	return -EPERM;
}

static inline int coul_interface_get_battery_uv_irq_status(int type)
{
	return 0;
}

static inline int coul_interface_get_battery_moved(int type)
{
	return 0;
}

static inline void coul_interface_clear_battery_moved (int type)
{
}

static inline int coul_interface_get_fg_type(int type)
{
	return COUL_FG_TYPE_BEGIN;
}

static inline int coul_interface_get_rbatt(int type)
{
	return 0;
}

//#ifdef CONFIG_HONOR_POWER_EMBEDDED_ISOLATION
void coul_interface_update_batt_param(int type, const char *barnd)
{
}
#endif /* CONFIG_HONOR_COUL */

#endif /* _COUL_INTERFACE_H_ */
