// SPDX-License-Identifier: GPL-2.0
/*
 * power_glink_handle_charge.c
 *
 * glink channel for handle charge
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

#include <linux/device.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_glink.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <huawei_platform/power/wireless/wireless_charger.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_pwr_ctrl.h>
#include <linux/power/huawei_battery.h>

#define HWLOG_TAG power_glink_handle_charge
HWLOG_REGIST();

static unsigned int g_final_chg_type;
static bool g_dcp_ever_detected;
static unsigned int g_qbg_event;

static void qbg_event_work_func(struct work_struct *work);
static DECLARE_WORK(g_qbg_event_work, qbg_event_work_func);

static void qbg_event_work_func(struct work_struct *work)
{
	switch (g_qbg_event) {
	case POWER_GLINK_NOTIFY_QBG_CHARGE_DONE:
		power_event_bnc_notify(POWER_BNT_CHG, POWER_NE_CHG_CHARGING_DONE, NULL);
		huawei_battery_handle_charge_done();
		break;
	case POWER_GLINK_NOTIFY_QBG_CHARGE_RECHARGE:
		power_event_bnc_notify(POWER_BNT_CHG, POWER_NE_CHG_CHARGING_RECHARGE, NULL);
		break;
	default:
		break;
	}
}

static void power_glink_handle_stop_charging(void)
{
	static bool first_in = true;

	if (first_in) {
		first_in = false;
		if (charge_get_charger_type() == CHARGER_TYPE_WIRELESS)
			return;
	}

	g_dcp_ever_detected = false;
	g_final_chg_type = CHARGER_REMOVED;
	power_supply_set_int_property_value("charger_detection",
		POWER_SUPPLY_PROP_CHG_PLUGIN, POWER_SUPPLY_STOP_SINK);

	charge_set_done_status(CHARGE_DONE_NON);
}

static void power_glink_handle_start_charging(void)
{
	power_supply_set_int_property_value("charger_detection",
		POWER_SUPPLY_PROP_CHG_PLUGIN, POWER_SUPPLY_START_SINK);
}

void power_glink_handle_dc_connect_message(u32 msg)
{
	static u32 charging_now = 0xFFFF;

	if (charging_now == msg) {
		pr_err("%s: charging msg %u repeats\n", __func__, charging_now);
		return;
	}
	charging_now = msg;

	switch (msg) {
	case POWER_GLINK_NOTIFY_VAL_STOP_CHARGING:
		power_glink_handle_stop_charging();
		break;
	case POWER_GLINK_NOTIFY_VAL_START_CHARGING:
		power_glink_handle_start_charging();
		break;
	default:
		break;
	}
}

void power_glink_handle_charge_type_message(u32 msg)
{
	unsigned int type = CHARGER_REMOVED;

	switch (msg) {
	case POWER_GLINK_NOTIFY_VAL_SDP_CHARGER:
		type = CHARGER_TYPE_USB;
		break;
	case POWER_GLINK_NOTIFY_VAL_CDP_CHARGER:
		type = CHARGER_TYPE_BC_USB;
		break;
	case POWER_GLINK_NOTIFY_VAL_DCP_CHARGER:
		type = CHARGER_TYPE_STANDARD;
		g_dcp_ever_detected = true;
		break;
	case POWER_GLINK_NOTIFY_VAL_NONSTANDARD_CHARGER:
		type = CHARGER_TYPE_NON_STANDARD;
		break;
	default:
		break;
	}

	/* Prevent the type from switching from dcp to other types , Because of the problem of bc1.2 detection */
	if (g_final_chg_type == CHARGER_TYPE_STANDARD)
		return;

	g_final_chg_type = type;

	charge_set_charger_type(type);
	power_supply_set_int_property_value("huawei_charge",
		POWER_SUPPLY_PROP_CHG_TYPE, type);
}

bool is_dcp_ever_detected(void)
{
	hwlog_info("%s g_dcp_ever_detected=%d\n", __func__, g_dcp_ever_detected);
	return g_dcp_ever_detected;
}

static void power_glink_handle_qbg_message(u32 msg)
{
	hwlog_info("%s msg=%u\n", __func__, msg);
	g_qbg_event = msg;
	switch (msg) {
	case POWER_GLINK_NOTIFY_QBG_CHARGE_DONE:
		charge_set_done_status(CHARGE_DONE);
		schedule_work(&g_qbg_event_work);
		hwlog_info("enter into buck charge done\n");
		break;
	case POWER_GLINK_NOTIFY_QBG_CHARGE_RECHARGE:
		charge_set_done_status(CHARGE_DONE_NON);
		schedule_work(&g_qbg_event_work);
		hwlog_info("enter into recharge\n");
		break;
	default:
		break;
	}
}

void power_glink_handle_charge_notify_message(u32 id, u32 msg)
{
	switch (id) {
	case POWER_GLINK_NOTIFY_ID_DC_CONNECT_EVENT:
		power_glink_handle_dc_connect_message(msg);
		break;
	case POWER_GLINK_NOTIFY_ID_APSD_EVENT:
		power_glink_handle_charge_type_message(msg);
		break;
	case POWER_GLINK_NOTIFY_ID_WLS2WIRED:
		wlrx_switch_to_wired_handler();
		break;
	case POWER_GLINK_NOTIFY_ID_WLSIN_VBUS:
		wireless_charger_pmic_vbus_handler(msg);
		break;
	case POWER_GLINK_NOTIFY_ID_QBG_EVENT:
		power_glink_handle_qbg_message(msg);
		break;
	default:
		break;
	}
}
