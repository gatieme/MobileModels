// SPDX-License-Identifier: GPL-2.0
/*
 * buck_charge_platform_interface.c
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

#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/power_supply.h>
#include <linux/kernel.h>
#include <huawei_platform/power/huawei_charger.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/log/hwlog_kernel.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/charger/charge_common_vote.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_platform_interface.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_sysfs.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_ic_manager.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>

#define HWLOG_TAG buck_charge_platform_interface
HWLOG_REGIST();

unsigned int buck_charge_get_charge_core_data(int info_name)
{
	unsigned int value = 0;

	switch (info_name) {
	case BUCK_CHARGE_CORE_VTERM_RT:
		value = BATTERY_VOLTAGE_4500_MV;
		break;
	case BUCK_CHARGE_CORE_IIN_MAX:
		value = BUCK_CHARGE_DEFAULT_IIN_THL;
		break;
	case BUCK_CHARGE_CORE_ICHG_MAX:
		value = BUCK_CHARGE_DEFAULT_IIN_THL;
		break;
	case BUCK_CHARGE_CORE_ITERM:
		break;
	case BUCK_CHARGE_CORE_VTERM:
		value = POWER_SUPPLY_DEFAULT_VOLTAGE_MAX;
		break;
	default:
		break;
	}

	return value;
}

int buck_charge_get_vsys(void)
{
	int vsys = 0;

	charge_get_vsys(&vsys);
	return vsys;
}

int buck_charge_get_hiz_mode(int hiz_mode)
{
	return hiz_mode;
}

int buck_charge_get_mains_online(void)
{
	int usb_online = 0;
	unsigned int type;

	(void)power_supply_get_int_property_value(POWER_PLATFORM_USB_PSY_NAME,
		POWER_SUPPLY_PROP_ONLINE, &usb_online);

	type = charge_get_charger_type();
	if (usb_online && ((type == CHARGER_TYPE_STANDARD) ||
		(type == CHARGER_TYPE_FCP) ||
		(type == CHARGER_TYPE_PD) ||
		(type == CHARGER_TYPE_TYPEC))) {
		hwlog_err("use standard adaptor\n");
		return 1; /* use standard adaptor */
	}

	hwlog_err("not use standard adaptor\n");
	return 0;
}

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
static void buck_charge_set_rt_current(int val, int *iin_rt_curr)
{
	#ifdef CONFIG_HLTHERM_RUNTEST
	int curr = BUCK_CHARGE_HLTHERM_CURRENT;
#else
	int curr = CHARGE_SYSFS_MIN_IIN_CURRENT;
#endif

	if (val == 0)
		*iin_rt_curr = BUCK_CHARGE_DCP_INPUT_CURRENT;
	else if ((val <= CHARGE_SYSFS_MIN_IIN_CURRENT) && (val > 0))
		*iin_rt_curr = curr;
	else
		*iin_rt_curr = val;

	chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_RT,
		true, iin_rt_curr);
	hwlog_info("set iin_rt_curr=%d\n", *iin_rt_curr);
}

int buck_charge_set_iin_thermal_limit(unsigned int value)
{
	int ret;
	int iin = (value > 0) ? value : BUCK_CHARGE_DCP_INPUT_CURRENT;

	ret = chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_THERMAL,
		true, iin);
	if (ret) {
		hwlog_err("set_iin_thermal_limit vote fail, disable voter\n", ret);
		chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_THERMAL, false, 0);
	}

	return ret;
}
#else
static void buck_charge_set_rt_current(int val, int *iin_rt_curr)
{
	struct power_supply *psy = NULL;

	if (!power_supply_check_psy_available("huawei_charge", &psy)) {
		hwlog_err("huawei_charge psy is not ready\n");
		return;
	}

	if (val == 0) {
		*iin_rt_curr = power_supply_return_int_property_value_with_psy(
			"huawei_charge", POWER_SUPPLY_PROP_INPUT_CURRENT_MAX);
		hwlog_info("rt_curr =%d\n", iin_rt_curr);
	} else if ((val <= CHARGE_SYSFS_MIN_IIN_CURRENT) && (val > 0)) {
#ifndef CONFIG_HLTHERM_RUNTEST
		*iin_rt_curr = CHARGE_SYSFS_MIN_IIN_CURRENT;
#else
		*iin_rt_curr = BUCK_CHARGE_HLTHERM_CURRENT;
#endif
	} else {
		*iin_rt_curr = val;
	}

	power_supply_set_int_property_value_with_psy(psy,
		POWER_SUPPLY_PROP_INPUT_CURRENT_MAX, *iin_rt_curr);

	hwlog_info("set iin_rt_curr %d\n", *iin_rt_curr);
}

int buck_charge_set_iin_thermal_limit(unsigned int value)
{
	struct power_supply *psy = NULL;

	if (!power_supply_check_psy_available("huawei_charge", &psy)) {
		hwlog_err("huawei_charge psy is not ready\n");
		return -EINVAL;
	}

	return power_supply_set_int_property_value_with_psy(psy,
		POWER_SUPPLY_PROP_IIN_THERMAL, value);
}
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */

static void buck_charge_send_charging_event(int val)
{
	int usb_in = 0;
	int wls_in = 0;

	(void)power_supply_get_int_property_value(POWER_PLATFORM_USB_PSY_NAME, POWER_SUPPLY_PROP_ONLINE, &usb_in);
	(void)power_supply_get_int_property_value("Wireless", POWER_SUPPLY_PROP_ONLINE, &wls_in);

	pr_info("usb_in=%d, wls_in=%d enable=%d\n", usb_in, wls_in, val);
	if (usb_in || wls_in) {
		if (val)
			power_event_bnc_notify(POWER_BNT_CHARGING, POWER_NE_CHARGING_START, NULL);
		else
			power_event_bnc_notify(POWER_BNT_CHARGING, POWER_NE_CHARGING_SUSPEND, NULL);
	} else {
		power_event_bnc_notify(POWER_BNT_CHARGING, POWER_NE_CHARGING_STOP, NULL);
	}
}

int buck_charge_set_charge_en(unsigned int val, unsigned int charge_enable,
	unsigned int *charge_limit)
{
	u32 id = POWER_GLINK_PROP_ID_SET_CHARGE_ENABLE;

	if (power_glink_interface_set_property_value(id, &val, GLINK_DATA_ONE))
		return -EIO;

	buck_charge_send_charging_event(val);
	return 0;
}

int buck_charge_set_iin_limit(unsigned int val, unsigned int *inputcurrent)
{
	int iin = (val > 0) ? val : BUCK_CHARGE_DEFAULT_IIN_THL;

	hwlog_info("dcp set iin limit=%d\n", iin);
	return chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_POWER_IF,
		true, iin);
}

int buck_charge_set_ichg_limit(unsigned int val)
{
	int cur = (val > 0) ? val : BUCK_CHARGE_DCP_IBAT_CURRENT;

	return chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_FCC, VOTE_CLIENT_THERMAL, true, cur);
}

#ifndef CONFIG_HLTHERM_RUNTEST
int buck_charge_set_iin_limit_array(unsigned int val)
{
	buck_charge_set_iin_thermal_limit(val);
	hwlog_info("thermal set input current=%d\n", val);
	return 0;
}
#else
int buck_charge_set_iin_limit_array(unsigned int val)
{
	return 0;
}
#endif /* CONFIG_HLTHERM_RUNTEST */

int buck_charge_set_vterm_dec(unsigned int val)
{
	return power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_FV_FOR_BASP,
		&val, GLINK_DATA_ONE);
}

void buck_charge_set_iin_runningtest(unsigned int val, unsigned int iin_max, unsigned int *iin_rt)
{
	struct power_supply *psy = NULL;

	if (!power_supply_check_psy_available(POWER_PLATFORM_BAT_PSY_NAME, &psy)) {
		hwlog_err("battery psy is not ready\n");
		return;
	}

	power_supply_set_int_property_value_with_psy(psy,
		POWER_SUPPLY_PROP_CHARGING_ENABLED, !!val);
	*iin_rt = power_supply_return_int_property_value_with_psy(psy,
		POWER_SUPPLY_PROP_CHARGING_ENABLED);
	hwlog_info("iin_rt = %d\n", *iin_rt);
}

void buck_charge_set_iin_thermal(unsigned int val, unsigned int iin_max, unsigned int *iin_thl)
{
	struct power_supply *psy = NULL;

	if (power_supply_check_psy_available("huawei_charge", &psy)) {
		power_supply_set_int_property_value_with_psy(psy,
			POWER_SUPPLY_PROP_IIN_THERMAL, val);
		*iin_thl = val;
		hwlog_info("thermal set input current=%d\n", val);
	}
}

void buck_charge_set_iin_rt_current(unsigned int val, int *iin_rt_curr)
{
	buck_charge_set_rt_current(val, iin_rt_curr);
}

static void buck_charge_set_adaptor_change(int val)
{
	struct power_supply *psy = NULL;

	if (!power_supply_check_psy_available(POWER_PLATFORM_BAT_PSY_NAME, &psy)) {
		hwlog_err("battery psy is not ready\n");
		return;
	}

	power_supply_set_int_property_value_with_psy(psy,
		POWER_SUPPLY_PROP_ADAPTOR_VOLTAGE, val);
	hwlog_info("set adpator volt %d\n", val);
}

void buck_charge_set_adaptor_voltage(unsigned int val)
{
	if (val == ADAPTER_5V)
		charge_set_reset_adapter_source(RESET_ADAPTER_DIRECT_MODE, TRUE);
	else
		charge_set_reset_adapter_source(RESET_ADAPTER_DIRECT_MODE, FALSE);
	buck_charge_set_adaptor_change(charge_get_reset_adapter_source());
}

void buck_charge_set_chrg_config(unsigned int val, int *chrg_config)
{
	struct power_supply *psy = NULL;

	if (power_supply_check_psy_available(POWER_PLATFORM_BAT_PSY_NAME, &psy)) {
		power_supply_set_int_property_value_with_psy(psy,
			POWER_SUPPLY_PROP_CHARGING_ENABLED, !!val);
		*chrg_config = val;
	}
}

void buck_charge_set_factory_diag(unsigned int val)
{
	if (power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_CHARGE_ENABLE,
		(unsigned int *)&val, GLINK_DATA_ONE))
		return;
	buck_charge_send_charging_event(val);
}

int buck_charge_get_plugusb(char *buf)
{
	return 0;
}

void buck_charge_set_ichg_runningtest(unsigned int ichg_rt)
{
}

void buck_charge_set_sdp_iin_limit(unsigned int val)
{
}

void buck_charge_set_ichg_thermal(unsigned int  val, unsigned int ichg_thl)
{
}

void buck_charge_set_vterm_rt(unsigned int vterm_rt)
{
}

void buck_charge_set_batfet_disable(long val, unsigned int batfet_disable)
{
}

void buck_charge_set_inputcurrent(unsigned int inputcurrent)
{
}

void buck_charge_set_charger_cvcal(long val, unsigned int *charger_cvcal_value)
{
}

void buck_charge_set_charger_cvcal_clear(long val, unsigned int *charger_cvcal_clear)
{
}

void buck_charge_set_plugusb(const char *buf)
{
}

void buck_charge_set_vr_charge_type(void)
{
}

void buck_charge_set_charge_core_iin_usb(unsigned int val)
{
}

int buck_charge_init_charge_core_data(void)
{
	return 0;
}