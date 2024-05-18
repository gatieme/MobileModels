/*
 * honor_charger_sysfs.h
 *
 * honor charger sysfs driver
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
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

#ifndef _HONOR_CHARGER_SYSFS_
#define _HONOR_CHARGER_SYSFS_

#include <linux/version.h>
#include <linux/mutex.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/power_supply.h>
#include <hwpower/power_dts.h>
#include <hwpower/power_dsm.h>
#include <hwpower/power_event_ne.h>
#include <hwpower/power_ui_ne.h>
#include <hwpower/honor_charger_type.h>
#include <hwpower/charger_log_print.h>

#define DEFAULT_IIN_CURRENT       1000
#define MAX_CURRENT               2500
#define MIN_CURRENT               100
#define HLTHERM_CURRENT           2000
#define NO_CHG_TEMP_LOW           0
#define NO_CHG_TEMP_HIGH          500
#define BATT_EXIST_TEMP_LOW       (-400)
#define DEFAULT_IIN_THL           2300

#define MAX_SIZE                  1024
#define POWER_SUPPLY_USB_TYPE_FCP 10

/* adaptor test macro */
#define ADAPTER_0V                    (0)
#define ADAPTER_5V                    (5)
#define ADAPTER_7V                    (7)
#define ADAPTER_9V                    (9)
#define ADAPTER_12V                   (12)
#define ADAPTER_15V                   (15)

enum charge_sysfs_type {
	CHARGE_SYSFS_IIN_RT_CURRENT = 0,
	CHARGE_SYSFS_IBUS,
	CHARGE_SYSFS_VBUS,
	CHARGE_SYSFS_HIZ,
	CHARGE_SYSFS_CHARGE_TYPE,
	CHARGE_SYSFS_FCP_SUPPORT,
	CHARGE_SYSFS_UPDATE_VOLT_NOW,
	CHARGE_SYSFS_WATCHDOG_DISABLE,
	CHARGE_SYSFS_ADAPTOR_TEST,
	CHARGE_SYSFS_VOLTAGE_SYS,
	CHARGE_SYSFS_CHARGELOG_HEAD,
	CHARGE_SYSFS_CHARGELOG,
	CHARGE_SYSFS_END,
};

enum iin_thermal_charge_type {
	IIN_THERMAL_CHARGE_TYPE_BEGIN = 0,
	IIN_THERMAL_WCURRENT_5V = IIN_THERMAL_CHARGE_TYPE_BEGIN,
	IIN_THERMAL_WCURRENT_9V,
	IIN_THERMAL_WLCURRENT_5V,
	IIN_THERMAL_WLCURRENT_9V,
	IIN_THERMAL_CHARGE_TYPE_END,
};

struct charge_sysfs_data
{
	int iin_rt_curr;
	int hiz_mode;
	int ibus;
	int vbus;
	unsigned int iin_thl_array[IIN_THERMAL_CHARGE_TYPE_END];
	unsigned int charge_enable;
	unsigned int fcp_charge_enable;
	unsigned int pd_charge_enable;
	unsigned int wdt_disable;
};

struct charger_sysfs_ops {
	int (*get_property)(char *buf);
	int (*set_property)(const char *buf);
};

struct charge_device_info {
	struct device *dev;
	struct delayed_work sync_work;
	struct charge_sysfs_data sysfs_data;
	struct power_supply *batt_psy;
	struct power_supply *usb_psy;
	u32 startup_iin_limit;
	u32 hota_iin_limit;
	u32 adapt_vol_set;
	u32 phone_state;
	unsigned int charge_turbo_enable;
};

#endif /* _HONOR_CHARGER_SYSFS_ */
