// SPDX-License-Identifier: GPL-2.0
/*
 * nonadsp_charger.c
 *
 * virtual buck charger ic driver for qcom platforms which have power supply
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include <linux/power_supply.h>
#include <linux/power/huawei_battery.h>
#include <chipset_common/hwpower/buck_charge/buck_charge_ic.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_vote.h>

#define HWLOG_TAG nonadsp_charger
HWLOG_REGIST();

static int nonadsp_charger_set_hiz(int enable)
{
	struct power_supply *psy = NULL;
	int ret;
	u32 value;

	if (enable)
		value = 1; /* Hiz enable */
	else
		value = 0;

	if (!power_supply_check_psy_available("battery", &psy)) {
		hwlog_err("battery psy is not ready\n");
		return -EINVAL;
	}

	hwlog_info("set_hiz: val=%d\n", value);
	ret = power_supply_set_int_property_value_with_psy(psy,
		POWER_SUPPLY_PROP_HIZ_MODE, value);
	if (ret)
		hwlog_err("set_hiz failed\n");

	power_msleep(DT_MSLEEP_250MS, 0, NULL);
	return ret;
}

static int nonadsp_charger_get_vbus(u32 *vbus)
{
	int val = 0;
	struct power_supply *psy = NULL;
	int ret;

	if (!power_supply_check_psy_available("usb", &psy)) {
		hwlog_err("usb psy is not ready\n");
		*vbus = 0;
		return -EINVAL;
	}

	ret = power_supply_get_int_property_value("usb",
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &val);
	if (ret) {
		hwlog_err("get vbus failed\n");
		*vbus = 0;
		return -EINVAL;
	}

	hwlog_info("vbus_now: value=%d\n", val);
	*vbus = val / POWER_UA_PER_MA;
	return 0;
}

static int nonadsp_charger_get_ibus(void)
{
	int ret;
	int val = 0;
	struct power_supply *psy = NULL;

	if (!power_supply_check_psy_available("usb", &psy)) {
		hwlog_err("usb psy is not ready\n");
		return -EINVAL;
	}

	ret = power_supply_get_int_property_value("usb",
		POWER_SUPPLY_PROP_INPUT_CURRENT_NOW, &val);
	if (ret) {
		hwlog_err("get ibus failed\n");
		return -EINVAL;
	}

	hwlog_info("ibus_now: value=%d\n", val);
	return val / POWER_UA_PER_MA;
}

static int nonadsp_charge_get_charge_enable_status(void)
{
	int val = 0;

	power_supply_get_int_property_value("battery", POWER_SUPPLY_PROP_CHARGING_ENABLED, &val);

	hwlog_info("get_charge_enable_status=%d\n", val);
	return val;
}

static int nonadsp_charge_vote_for_fcc(struct power_vote_object *obj, void *data, int fcc_ma, const char *client)
{
	if (fcc_ma < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		return 0;
	}

	return power_supply_set_int_property_value("bk_battery",
		POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX, fcc_ma * POWER_UV_PER_MV);
}

static int nonadsp_charge_vote_for_usb_icl(struct power_vote_object *obj, void *data, int icl_ma, const char *client)
{
	if (icl_ma < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		return 0;
	}

	if (huawei_battery_get_chg_usb_current() > icl_ma)
		icl_ma = huawei_battery_get_chg_usb_current();

	return power_supply_set_int_property_value("bk_battery", POWER_SUPPLY_PROP_INPUT_CURRENT_MAX, icl_ma);
}

static int nonadsp_charge_vote_for_vterm(struct power_vote_object *obj, void *data, int vterm_mv, const char *client)
{
	if (vterm_mv < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		return 0;
	}

	return power_supply_set_int_property_value("bk_battery",
		POWER_SUPPLY_PROP_VOLTAGE_MAX, vterm_mv * POWER_UV_PER_MV);
}

static int nonadsp_charge_vote_for_iterm(struct power_vote_object *obj, void *data, int iterm_ma, const char *client)
{
	return 0;
}

static int nonadsp_charge_vote_for_dis_chg(struct power_vote_object *obj, void *data, int dis_chg, const char *client)
{
	if (dis_chg < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		dis_chg = false;
	}

	return power_supply_set_int_property_value("bk_battery", POWER_SUPPLY_PROP_BATTERY_CHARGING_ENABLED, !dis_chg);
}

static struct charge_device_ops nonadsp_charger_ops = {
	.set_charger_hiz = nonadsp_charger_set_hiz,
	.get_vbus = nonadsp_charger_get_vbus,
	.get_ibus = nonadsp_charger_get_ibus,
	.get_charge_enable_status = nonadsp_charge_get_charge_enable_status,
	.vote_for_fcc = nonadsp_charge_vote_for_fcc,
	.vote_for_usb_icl = nonadsp_charge_vote_for_usb_icl,
	.vote_for_vterm = nonadsp_charge_vote_for_vterm,
	.vote_for_iterm = nonadsp_charge_vote_for_iterm,
	.vote_for_dis_chg = nonadsp_charge_vote_for_dis_chg,
};

static int __init nonadsp_charger_init(void)
{
	return charge_ops_register(&nonadsp_charger_ops, BUCK_IC_TYPE_PLATFORM);
}

static void __exit nonadsp_charger_exit(void)
{
	return;
}

module_init(nonadsp_charger_init);
module_exit(nonadsp_charger_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("nonadsp charger driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
