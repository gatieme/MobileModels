/*
 * power_supply_interface.h
 *
 * power supply interface for power module
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

#ifndef _POWER_SUPPLY_INTERFACE_H_
#define _POWER_SUPPLY_INTERFACE_H_

#include <linux/power_supply.h>

void power_supply_sync_changed(const char *name);
int power_supply_get_property_value(const char *name,
	enum power_supply_property psp, union power_supply_propval *val);
int power_supply_set_property_value(const char *name,
	enum power_supply_property psp, const union power_supply_propval *val);
int power_supply_get_int_property_value(const char *name,
	enum power_supply_property psp, int *val);
int power_supply_set_int_property_value(const char *name,
	enum power_supply_property psp, int val);
int power_supply_get_charge_status(void);

#endif /* _POWER_SUPPLY_INTERFACE_H_ */
