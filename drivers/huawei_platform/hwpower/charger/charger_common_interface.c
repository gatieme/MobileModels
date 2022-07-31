// SPDX-License-Identifier: GPL-2.0
/*
 * charger_common_interface.c
 *
 * common interface for charger module
 *
 * Copyright (C) 2021-2021 Huawei Technologies Co., Ltd.
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

#include <linux/power/huawei_battery.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <huawei_platform/hwpower/common_module/power_glink.h>
#include <huawei_platform/power/huawei_charger.h>

#define HWLOG_TAG charger_common
HWLOG_REGIST();

#if !IS_ENABLED(CONFIG_QTI_PMIC_GLINK)
/* platform charge type to common charge type */
static struct convert_data g_charge_type_table[] = {
	{ POWER_SUPPLY_TYPE_UNKNOWN, CHARGER_REMOVED },
	{ POWER_SUPPLY_TYPE_BATTERY, CHARGER_TYPE_BATTERY },
	{ POWER_SUPPLY_TYPE_UPS, CHARGER_TYPE_UPS },
	{ POWER_SUPPLY_TYPE_MAINS, CHARGER_TYPE_MAINS },
	{ POWER_SUPPLY_TYPE_USB, CHARGER_TYPE_USB },
	{ POWER_SUPPLY_TYPE_USB_DCP, CHARGER_TYPE_STANDARD },
	{ POWER_SUPPLY_TYPE_USB_CDP, CHARGER_TYPE_BC_USB },
	{ POWER_SUPPLY_TYPE_USB_ACA, CHARGER_TYPE_ACA },
	{ POWER_SUPPLY_TYPE_USB_TYPE_C, CHARGER_TYPE_TYPEC },
	{ POWER_SUPPLY_TYPE_USB_PD, CHARGER_TYPE_PD },
	{ POWER_SUPPLY_TYPE_USB_PD_DRP, CHARGER_TYPE_PD_DRP },
	{ POWER_SUPPLY_TYPE_APPLE_BRICK_ID, CHARGER_TYPE_APPLE_BRICK_ID },
	{ POWER_SUPPLY_TYPE_USB_HVDCP, CHARGER_TYPE_HVDCP },
	{ POWER_SUPPLY_TYPE_USB_HVDCP_3, CHARGER_TYPE_HVDCP_3 },
	{ POWER_SUPPLY_TYPE_WIRELESS, CHARGER_TYPE_WIRELESS },
	{ POWER_SUPPLY_TYPE_USB_FLOAT, CHARGER_TYPE_NON_STANDARD },
	{ POWER_SUPPLY_TYPE_BMS, CHARGER_TYPE_BMS },
	{ POWER_SUPPLY_TYPE_PARALLEL, CHARGER_TYPE_PARALLEL },
	{ POWER_SUPPLY_TYPE_MAIN, CHARGER_TYPE_MAIN },
	{ POWER_SUPPLY_TYPE_UFP, CHARGER_TYPE_UFP },
	{ POWER_SUPPLY_TYPE_DFP, CHARGER_TYPE_DFP },
	{ POWER_SUPPLY_TYPE_CHARGE_PUMP, CHARGER_TYPE_CHARGE_PUMP },
#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
	{ POWER_SUPPLY_TYPE_FCP, CHARGER_TYPE_FCP },
	{ POWER_SUPPLY_TYPE_WIRELESS, CHARGER_TYPE_WIRELESS },
#endif
};
#endif /* IS_ENABLED(CONFIG_QTI_PMIC_GLINK) */

static struct charge_switch_ops *g_charge_switch_ops;
static unsigned int g_charge_charger_source = POWER_SUPPLY_TYPE_UNKNOWN;
static unsigned int g_charge_reset_adapter_source;
static bool g_charge_ignore_plug_event;

int charge_switch_ops_register(struct charge_switch_ops *ops)
{
	if (ops) {
		g_charge_switch_ops = ops;
		return 0;
	}

	hwlog_err("charge switch ops register fail\n");
	return -EINVAL;
}

int charge_switch_get_charger_type(void)
{
	if (!g_charge_switch_ops || !g_charge_switch_ops->get_charger_type) {
		hwlog_err("g_charge_switch_ops or get_charger_type is null\n");
		return -EINVAL;
	}

	return g_charge_switch_ops->get_charger_type();
}

#if !IS_ENABLED(CONFIG_QTI_PMIC_GLINK)
unsigned int charge_convert_charger_type(unsigned int type)
{
	unsigned int new_type = CHARGER_REMOVED;
	int len = ARRAY_SIZE(g_charge_type_table);

	power_convert_value(g_charge_type_table, len, type, &new_type);
	hwlog_info("convert_charger_type: len=%d type=%u new_type=%u\n", len, type, new_type);
	return new_type;
}

int charge_set_buck_iterm(unsigned int value)
{
	return 0;
}

int charge_set_buck_fv_delta(unsigned int value)
{
	return 0;
}

int charge_get_battery_current_avg(void)
{
	return battery_get_bat_avg_current();
}

int charge_set_jeita_ichg(unsigned int value)
{
	return 0;
}

int charge_set_jeita_vterm(unsigned int value)
{
	return 0;
}
#else
unsigned int charge_convert_charger_type(unsigned int type)
{
	return type;
}

int charge_set_buck_iterm(unsigned int value)
{
	/* 1:valid buff size */
	return power_glink_set_property_value(
		POWER_GLINK_PROP_ID_SET_FFC_ITERM, &value, 1);
}

int charge_set_buck_fv_delta(unsigned int value)
{
	/* 1:valid buff size */
	return power_glink_set_property_value(
		POWER_GLINK_PROP_ID_SET_FFC_FV_DELTA, &value, 1);
}

int charge_get_battery_current_avg(void)
{
	int curr_avg = 0;

	(void)power_supply_get_int_property_value("battery",
		POWER_SUPPLY_PROP_CURRENT_AVG, &curr_avg);

	return curr_avg;
}

int charge_set_jeita_ichg(unsigned int value)
{
	return huawei_charger_set_ichg_jeita_limit(value);
}

int charge_set_jeita_vterm(unsigned int value)
{
	return huawei_charger_set_vterm_jeita_limit(value);
}
#endif /* IS_ENABLED(CONFIG_QTI_PMIC_GLINK) */


#if IS_ENABLED(CONFIG_QTI_PMIC_GLINK)
int charge_set_batfet_disable(int val)
{
	u32 id = POWER_GLINK_PROP_ID_SET_SHIP_MODE;
	u32 value = 0;

	if (val == 0)
		return -EINVAL;

	(void)power_glink_set_property_value(id, &value, GLINK_DATA_ONE);
	hwlog_info("set_batfet_disable: val=%d\n", val);
	return 0;
}

void charge_set_usbpd_disable(bool flag)
{
	int usb_type = 0;
	u32 id = POWER_GLINK_PROP_ID_SET_PD_DISABLE_FLAG;
	u32 pd_disable = flag;

	power_supply_get_int_property_value("usb", POWER_SUPPLY_PROP_USB_TYPE,
		&usb_type);
	if ((usb_type == POWER_SUPPLY_USB_TYPE_PD) ||
		(usb_type == POWER_SUPPLY_USB_TYPE_PD_DRP) ||
		(usb_type == POWER_SUPPLY_USB_TYPE_PD_PPS)) {
		adapter_set_usbpd_enable(ADAPTER_PROTOCOL_SCP, !pd_disable);
		power_glink_set_property_value(id, &pd_disable, GLINK_DATA_ONE);
		hwlog_info("adapter support pd and scp, disable pd\n");
	}
}
#else
int charge_set_batfet_disable(int val)
{
	return -EINVAL;
}

void charge_set_usbpd_disable(bool flag)
{
}
#endif /* IS_ENABLED(CONFIG_QTI_PMIC_GLINK) */

int charge_get_charger_online(void)
{
	int online = -EINVAL;

	(void)power_supply_get_int_property_value("usb", POWER_SUPPLY_PROP_ONLINE, &online);
	return online;
}

void charge_set_charger_online(int online)
{
	(void)power_supply_set_int_property_value("usb", POWER_SUPPLY_PROP_ONLINE, online);
	hwlog_info("set_charger_online: online=%d\n", online);
}

#if (defined(CONFIG_QTI_PMIC_GLINK) || defined(CONFIG_HUAWEI_BUCK_CHARGER))
static unsigned int g_charge_charger_type = CHARGER_REMOVED;
unsigned int charge_get_charger_type(void)
{
	return g_charge_charger_type;
}

void charge_set_charger_type(unsigned int type)
{
	g_charge_charger_type = type;
	hwlog_info("set_charger_type: type=%u\n", type);
}
#else
unsigned int charge_get_charger_type(void)
{
	int ret;
	int type = POWER_SUPPLY_TYPE_UNKNOWN;

	ret = power_supply_get_int_property_value("usb", POWER_SUPPLY_PROP_REAL_TYPE, &type);
	if (ret)
		return CHARGER_REMOVED;

	return charge_convert_charger_type(type);
}

void charge_set_charger_type(unsigned int type)
{
	(void)power_supply_set_int_property_value("usb", POWER_SUPPLY_PROP_REAL_TYPE, type);
	hwlog_info("set_charger_type: type=%u\n", type);
}
#endif /* CONFIG_QTI_PMIC_GLINK || CONFIG_HUAWEI_BUCK_CHARGER */

unsigned int charge_get_charger_source(void)
{
	return g_charge_charger_source;
}

void charge_set_charger_source(unsigned int source)
{
	g_charge_charger_source = source;
	hwlog_info("set_charger_source: source=%u\n", source);
}

unsigned int charge_get_reset_adapter_source(void)
{
	return g_charge_reset_adapter_source;
}

void charge_set_reset_adapter_source(unsigned int mode, unsigned int value)
{
	switch (mode) {
	case RESET_ADAPTER_DIRECT_MODE:
		g_charge_reset_adapter_source = value;
		break;
	case RESET_ADAPTER_SET_MODE:
		if (value >= RESET_ADAPTER_SOURCE_END) {
			hwlog_err("invalid source=%u\n", value);
			return;
		}
		g_charge_reset_adapter_source |= (unsigned int)(1 << value);
		break;
	case RESET_ADAPTER_CLEAR_MODE:
		if (value >= RESET_ADAPTER_SOURCE_END) {
			hwlog_err("invalid source=%u\n", value);
			return;
		}
		g_charge_reset_adapter_source &= (unsigned int)(~(1 << value));
		break;
	default:
		hwlog_err("invalid mode=%u\n", mode);
		return;
	}

	hwlog_info("set_reset_adapter_source: mode=%u value=%u source=%u\n",
		mode, value, g_charge_reset_adapter_source);
}

bool charge_need_ignore_plug_event(void)
{
	if (g_charge_ignore_plug_event)
		hwlog_info("need ignore plug event\n");

	return g_charge_ignore_plug_event == true;
}

void charge_ignore_plug_event(bool state)
{
	g_charge_ignore_plug_event = state;
	hwlog_info("ignore_plug_event: %s plug event\n", (state == true) ? "ignore" : "restore");
}

void charge_update_charger_remove_type(void)
{
	hwlog_info("update charger_remove type\n");
	charge_set_charger_type(CHARGER_REMOVED);
	charge_set_charger_source(POWER_SUPPLY_TYPE_BATTERY);
}

void charge_update_buck_iin_thermal(void)
{
	huawei_charger_update_iin_thermal();
}
