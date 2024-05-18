/*
 * buck_ic_manager.h
 *
 * buck ic manager drivers
 *
 * Copyright (c) 2022-2022 Honor Technologies Co., Ltd.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef _BUCK_IC_MANAGER
#define _BUCK_IC_MANAGER

#include <linux/version.h>
#include <linux/mutex.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <hwpower/buck_charger_interface.h>

typedef struct buck_ic_dirver_manager {
	int (*monitor_update)(int val);
	int (*charger_type_detect)(int val);
	int (*set_input_current)(int val);
	int (*get_input_current)(int *val);
	int (*set_charge_current)(int val);
	int (*get_charge_current)(int *val);
	int (*set_constant_voltage)(int val);
	int (*get_constant_voltage)(int *val);
	int (*set_charge_enable)(int val);
	int (*get_charge_enable)(int *val);
	int (*set_otg_enable)(int val);
	int (*set_terminate_current)(int val);
	int (*get_terminate_current)(int *val);
	int (*set_terminate_enable)(int val);
	int (*set_dpm_voltage)(int val);
	int (*get_dpm_voltage)(int *val);
	int (*set_hiz_mode)(int val);
	int (*get_hiz_mode)(int *val);
	int (*kick_charge_watchdog)(int val);
	int (*enable_watchdog)(int val);
	int (*get_charge_done)(int *val);
	int (*get_charge_state)(int *val);
	int (*enable_eoc)(int val);
	int (*get_vbus_vol)(int *val);
	int (*get_ibus_cur)(int *val);
	int (*set_ovp_enable)(int val);
} buck_ic_dirver_manager;

int buck_ic_driver_register(buck_charger_driver_type type,
	buck_ic_dirver_manager *ops);
void buck_ic_driver_unregister(buck_charger_driver_type type);
int buck_ic_monitor_update(buck_charger_driver_type type,
	int val);
int buck_ic_type_detect(buck_charger_driver_type type,
	int val);
int buck_ic_set_charge_current(buck_charger_driver_type type,
	int val);
int buck_ic_get_charge_current(buck_charger_driver_type type,
	int *val);
int buck_ic_set_input_current(buck_charger_driver_type type,
	int val);
int buck_ic_get_input_current(buck_charger_driver_type type,
	int *val);
int buck_ic_set_constant_voltage(buck_charger_driver_type type,
	int val);
int buck_ic_get_constant_voltage(buck_charger_driver_type type,
	int *val);
int buck_ic_set_charge_enable(buck_charger_driver_type type,
	int val);
int buck_ic_get_charge_enable(buck_charger_driver_type type,
	int *val);
int buck_ic_set_otg_enable(buck_charger_driver_type type,
	int val);
int buck_ic_set_terminate_current(buck_charger_driver_type type,
	int val);
int buck_ic_get_terminate_current(buck_charger_driver_type type,
	int *val);
int buck_ic_set_terminate_enable(buck_charger_driver_type type,
	int val);
int buck_ic_set_dpm_voltage(buck_charger_driver_type type,
	int val);
int buck_ic_get_dpm_voltage(buck_charger_driver_type type,
	int *val);
int buck_ic_set_hiz_mode(buck_charger_driver_type type,
	int val);
int buck_ic_get_hiz_mode(buck_charger_driver_type type,
	int *val);
int buck_ic_kick_charge_watchdog(buck_charger_driver_type type,
	int val);
int buck_ic_enable_watchdog(buck_charger_driver_type type,
	int val);
int buck_ic_get_charge_done(buck_charger_driver_type type,
	int *val);
int buck_ic_get_charge_state(buck_charger_driver_type type,
	int *val);
int buck_ic_get_vbus_vol(buck_charger_driver_type type,
	int *val);
int buck_ic_get_ibus_cur(buck_charger_driver_type type,
	int *val);
int buck_ic_set_ovp_enable(buck_charger_driver_type type,
	int val);
#endif /* _BUCK_IC_MANAGER */