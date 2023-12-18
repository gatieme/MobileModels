// SPDX-License-Identifier: GPL-2.0
/*
 * adsp_charger.c
 *
 * virtual buck charger ic driver for qcom platforms which have power glink
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

#include <chipset_common/hwpower/buck_charge/buck_charge_ic.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <chipset_common/hwpower/common_module/power_vote.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>

#define HWLOG_TAG adsp_charger
HWLOG_REGIST();

static int adsp_charger_set_hiz(int enable)
{
	int ret;
	u32 value;
	u32 id = POWER_GLINK_PROP_ID_SET_INPUT_SUSPEND;

	if (enable)
		value = 1; /* Hiz enable */
	else
		value = 0;

	hwlog_info("set_hiz: val=%d\n", value);
	ret = power_glink_interface_set_property_value(id, &value, GLINK_DATA_ONE);
	if (ret)
		hwlog_err("set_hiz failed\n");

	power_msleep(DT_MSLEEP_200MS, 0, NULL);
	return ret;
}

static int adsp_charger_set_batfet_disable(int enable)
{
	u32 id = POWER_GLINK_PROP_ID_SET_SHIP_MODE;
	u32 value = 0;

	if (enable == 0)
		return -EINVAL;

	(void)power_glink_interface_set_property_value(id, &value, GLINK_DATA_ONE);
	hwlog_info("set_batfet_disable: val=%d\n", enable);
	return 0;
}

static int adsp_charger_get_vbus(u32 *vbus)
{
	int vwls = 0;
	int temp_vbus = 0;

	power_supply_get_int_prop(POWER_PLATFORM_USB_PSY_NAME,
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &temp_vbus, 0, POWER_UV_PER_MV);
	(void)power_glink_interface_get_property_value(
		POWER_GLINK_PROP_ID_SET_WLSBST, (u32 *)&vwls, GLINK_DATA_ONE);

	*vbus = power_max_positive(temp_vbus, vwls);
	return 0;
}

static int adsp_charger_get_ibus(void)
{
	int ibus = 0;

	(void)charger_dev_get_ibus(&ibus);
	return (ibus / POWER_UA_PER_MA);
}

static int adsp_charger_get_vsys(int *vsys)
{
	int ret;

	if(!vsys)
		return -EINVAL;

	ret = power_glink_interface_get_property_value(POWER_GLINK_PROP_ID_GET_VOLTAGE_SYS,
		(unsigned int *)vsys, GLINK_DATA_ONE);
	if (ret) {
		*vsys = 0;
		return -EINVAL;
	}
	hwlog_info("get vsys val=%d\n", *vsys);
	return 0;
}

static int adsp_charge_get_charge_enable_status(void)
{
	int val = 0;

	power_glink_interface_get_property_value(POWER_GLINK_PROP_ID_SET_CHARGE_ENABLE, (u32 *)&val, GLINK_DATA_ONE);

	hwlog_info("get_charge_enable_status=%d\n", val);
	return val;
}

static int adsp_charge_vote_for_fcc(struct power_vote_object *obj, void *data, int fcc_ma, const char *client)
{
	u32 id = POWER_GLINK_PROP_ID_SET_IBAT;
	u32 glink_data[GLINK_DATA_TWO];

	if (fcc_ma < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		return 0;
	}

	glink_data[GLINK_DATA_ZERO] = AGGREGATOR_VOTE_ENABLE;
	glink_data[GLINK_DATA_ONE] = fcc_ma;

	return power_glink_interface_set_property_value(id, glink_data, GLINK_DATA_TWO);
}

static int adsp_charge_vote_for_usb_icl(struct power_vote_object *obj, void *data, int icl_ma, const char *client)
{
	u32 id = POWER_GLINK_PROP_ID_SET_USB_ICL;
	u32 glink_data[GLINK_DATA_TWO];

	if (icl_ma < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		return 0;
	}

	glink_data[GLINK_DATA_ZERO] = AGGREGATOR_VOTE_ENABLE;
	glink_data[GLINK_DATA_ONE] = icl_ma;

	return power_glink_interface_set_property_value(id, glink_data, GLINK_DATA_TWO);
}

static int adsp_charge_vote_for_vterm(struct power_vote_object *obj, void *data, int vterm_mv, const char *client)
{
	u32 id = POWER_GLINK_PROP_ID_SET_VTERM;
	u32 glink_data[GLINK_DATA_TWO];

	if (vterm_mv < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		return 0;
	}

	glink_data[GLINK_DATA_ZERO] = AGGREGATOR_VOTE_ENABLE;
	glink_data[GLINK_DATA_ONE] = vterm_mv;

	return power_glink_interface_set_property_value(id, glink_data, GLINK_DATA_TWO);
}

static int adsp_charge_vote_for_iterm(struct power_vote_object *obj, void *data, int iterm_ma, const char *client)
{
	if (iterm_ma < 0) {
		hwlog_err("%s invalid vote\n", __func__);
		return 0;
	}

	return power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_FFC_ITERM, &iterm_ma, GLINK_DATA_ONE);
}

static int adsp_charge_vote_for_dis_chg(struct power_vote_object *obj, void *data, int dis_chg, const char *client)
{
	return 0;
}

static struct charge_device_ops adsp_charger_ops = {
	.set_charger_hiz = adsp_charger_set_hiz,
	.set_batfet_disable = adsp_charger_set_batfet_disable,
	.get_vbus = adsp_charger_get_vbus,
	.get_vsys = adsp_charger_get_vsys,
	.get_ibus = adsp_charger_get_ibus,
	.get_charge_enable_status = adsp_charge_get_charge_enable_status,
	.vote_for_fcc = adsp_charge_vote_for_fcc,
	.vote_for_usb_icl = adsp_charge_vote_for_usb_icl,
	.vote_for_vterm = adsp_charge_vote_for_vterm,
	.vote_for_iterm = adsp_charge_vote_for_iterm,
	.vote_for_dis_chg = adsp_charge_vote_for_dis_chg,
};

static int __init adsp_charger_init(void)
{
	return charge_ops_register(&adsp_charger_ops, BUCK_IC_TYPE_PLATFORM);
}

static void __exit adsp_charger_exit(void)
{
	return;
}

module_init(adsp_charger_init);
module_exit(adsp_charger_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("adsp charger driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
