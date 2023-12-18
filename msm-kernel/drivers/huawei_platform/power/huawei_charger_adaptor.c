/*
 * huawei_charger_adaaptor.c
 *
 * huawei charger adaaptor for power module
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <linux/kernel.h>
#include <linux/power/huawei_charger.h>
#include <linux/power/huawei_battery.h>
#include <linux/power/charger-manager.h>
#include <linux/notifier.h>
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_icon.h>
#include <chipset_common/hwpower/common_module/power_ui_ne.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_adapter.h>
#include <chipset_common/hwpower/hardware_channel/vbus_channel.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <chipset_common/hwpower/charger/charge_common_vote.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>

#define HWLOG_TAG huawei_charger_adaptor
HWLOG_REGIST();

static int g_charge_done_status;

#define DEFAULT_CAP              50

void charge_set_adapter_voltage(int val, unsigned int type, unsigned int delay_time)
{
}

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
int charge_otg_mode_enable(int enable, unsigned int user)
{
	if (user == VBUS_CH_USER_WR_TX)
		return power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_WLSBST,
			(u32 *)&enable, GLINK_DATA_ONE);

	return 0;
}
#else
int charge_otg_mode_enable(int enable, unsigned int user)
{
	if (enable)
		vbus_ch_open(user, VBUS_CH_TYPE_CHARGER, false);
	else
		vbus_ch_close(user, VBUS_CH_TYPE_CHARGER, false, false);

	hwlog_info("charge_otg_mode_enable_ext = %d,user = %d\n", enable, user);
	return 0;
}
#endif

void charge_send_uevent(int input_events)
{
	int val = POWER_SUPPLY_DEFAULT_STATUS;

	(void)power_supply_get_int_property_value(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_STATUS, &val);

	if (input_events == VCHRG_NOT_CHARGING_EVENT ||
		input_events == VCHRG_POWER_SUPPLY_OVERVOLTAGE)
		power_event_bnc_notify(POWER_BNT_CHARGING, POWER_NE_CHARGING_SUSPEND, NULL);
	if (input_events == VCHRG_START_USB_CHARGING_EVENT &&
		val == POWER_SUPPLY_STATUS_NOT_CHARGING)
		power_event_bnc_notify(POWER_BNT_CHARGING, POWER_NE_CHARGING_START, NULL);
	hwlog_info("%s input_events = %d\n", __func__, input_events);
}

void charge_request_charge_monitor(void)
{
	struct power_supply *psy = NULL;

	if (charge_get_monitor_work_flag() == CHARGE_MONITOR_WORK_NEED_STOP)
		return;

	if (charge_get_charger_type() == CHARGER_REMOVED) {
		hwlog_info("charger already plugged out\n");
		return;
	}

	if (charge_get_charger_type() != CHARGER_TYPE_STANDARD)
		return;

	if (power_supply_check_psy_available("charge_manager", &psy))
		power_supply_set_int_property_value("charge_manager",
			POWER_SUPPLY_PROP_CHG_TYPE, CHARGER_TYPE_STANDARD);
	else
		power_supply_set_int_property_value("huawei_charge",
			POWER_SUPPLY_PROP_CHG_TYPE, CHARGER_TYPE_STANDARD);
}

int charger_manager_notifier(struct charger_manager *info, int event)
{
	return 0;
}

void wired_connect_send_icon_uevent(int icon_type)
{
	hwlog_info("%s enter,icon_type=%d\n", __func__, icon_type);

	power_icon_notify(icon_type);
}

void wired_disconnect_send_icon_uevent(void)
{
	power_icon_notify(ICON_TYPE_INVALID);
}

int charge_enable_force_sleep(bool enable)
{
	return 0;
}

int charge_set_wls_icl(int iin_ma)
{
	return chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_WLS,
		true, iin_ma);
}

int charge_set_hiz_enable(int hz_enable)
{
	return charger_set_hiz(hz_enable);
}

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
int charge_set_wlsin_hiz_enable(int hz_enable)
{
	int ret;
	u32 hiz_value;
	int icl_value;
	u32 id = POWER_GLINK_PROP_ID_SET_INPUT_SUSPEND_WLS;

	if (hz_enable) {
		icl_value = 0; /* limit input 0ma */
		hiz_value = 1; /* Hiz enable */
	} else {
		icl_value = 2000; /* limit input 2000ma */
		hiz_value = 0;
	}

	charge_set_wls_icl(icl_value);
	ret = power_glink_interface_set_property_value(id, &hiz_value, GLINK_DATA_ONE);
	msleep(DT_MSLEEP_200MS);
	return ret;
}

#else
int charge_set_wlsin_hiz_enable(int hz_enable)
{
	return 0;
}

#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */

int adaptor_cfg_for_wltx_vbus(int vol, int cur)
{
	hwlog_info("adaptor_cfg for wireless_tx: vol=%d, cur=%d\n", vol, cur);
	return dc_set_adapter_output_capability(vol, cur, 0);
}

void charge_set_done_status(int status)
{
	if ((status < CHARGE_DONE_NON) || (status > CHARGE_DONE))
		return;

	hwlog_info("set charge done status: %d\n", status);
	g_charge_done_status = status;
}
EXPORT_SYMBOL_GPL(charge_set_done_status);

#if IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE)
int charge_get_done_type(void)
{
	return g_charge_done_status;
}
EXPORT_SYMBOL_GPL(charge_get_done_type);
#else
int charge_get_done_type(void)
{
	int rc;
	union power_supply_propval val = {0, };
	struct charge_device_info *di = NULL;

	if (charge_support_thirdparty_buck())
		return get_charge_done_type();

	di = get_charger_device_info();
	if (!di) {
		hwlog_err("%s g_di is null\n", __func__);
		return CHARGE_DONE_NON;
	}

	rc = power_supply_get_property_value_with_psy(di->batt_psy,
		POWER_SUPPLY_PROP_CHARGE_DONE, &val);
	if (rc < 0) {
		hwlog_err("%s charge done fail\n", __func__);
		return CHARGE_DONE_NON;
	}
	return val.intval;
}
EXPORT_SYMBOL_GPL(charge_get_done_type);
#endif /* IS_ENABLED(CONFIG_HUAWEI_POWER_GLINK_INTERFACE) */

signed int battery_get_bat_current(void)
{
	int rc;
	union power_supply_propval val = {0, };
	struct charge_device_info *di = NULL;

	di = get_charger_device_info();
	if (!di) {
		hwlog_err("%s g_di is null\n", __func__);
		return 0;
	}

	rc = power_supply_get_property_value_with_psy(di->batt_psy,
		POWER_SUPPLY_PROP_CURRENT_NOW, &val);
	if (rc < 0) {
		hwlog_err("%s get vbus vol fail\n", __func__);
		return 0;
	}
	/* -val.intval is a negative number indicating charging */
	return -val.intval;
}
EXPORT_SYMBOL_GPL(battery_get_bat_current);

int charge_enable_eoc(bool eoc_enable)
{
	return 0;
}

void reset_cur_delay_eoc_count(void)
{
}

void charger_detect_init(void)
{
}

void charger_detect_release(void)
{
}
