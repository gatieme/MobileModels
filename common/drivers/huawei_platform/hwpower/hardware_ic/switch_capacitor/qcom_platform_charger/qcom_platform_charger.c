// SPDX-License-Identifier: GPL-2.0
/*
 * qcom_platform_charger.c
 *
 * qcom_platform_charger driver
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

#include "qcom_platform_charger.h"
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/charger/charge_common_vote.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_device_id.h>
#include <huawei_platform/power/battery_voltage.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <securec.h>

#define HWLOG_TAG qcom_platform_charger
HWLOG_REGIST();

static int qplat_charger_sc_enable(int enable, void *dev_data)
{
	bool vote_enable = false;
	struct qplat_charger_device_info *di = dev_data;

	if (!di) {
		hwlog_err("di is null\n");
		return -EPERM;
	}

	if (enable)
		vote_enable = true;

	hwlog_info("sc_enable = %d\n", enable);
	if (charge_set_hiz_enable(!enable)) {
		hwlog_err("qplat charger sc enable failed!\n");
		return -EPERM;
	}

	chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_FCC, VOTE_CLIENT_DC,
		vote_enable, di->sc_max_charge_current);
	chg_vote_set(VOTE_OBJ_TYPE_BUCK, VOTE_OBJ_USB_ICL, VOTE_CLIENT_DC,
		vote_enable, di->sc_max_input_current);

	return 0;
}

static int qplat_charger_discharge(int enable, void *dev_data)
{
	return 0;
}

static int qplat_charger_is_device_close(void *dev_data)
{
	return 0;
}

static int qplat_charger_get_device_id(void *dev_data)
{
	struct qplat_charger_device_info *di = dev_data;

	if (!di)
		return -EPERM;

	return di->device_id;
}

static int qplat_charger_get_vbat_mv(void *dev_data)
{
	int bat_num;
	int vol = 0;
	struct qplat_charger_device_info *di = dev_data;
	if (!di)
		return -EPERM;

	bat_num = hw_battery_get_series_num();
	power_supply_get_int_prop(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &vol,
		POWER_SUPPLY_DEFAULT_VOLTAGE_NOW, POWER_UV_PER_MV);
	if (bat_num > 0)
		vol /= bat_num;

	return vol;
}

static int qplat_charger_get_ibat_ma(int *ibat, void *dev_data)
{
	struct qplat_charger_device_info *di = dev_data;

	if (!di || !ibat)
		return -EPERM;

	*ibat = -power_platform_get_battery_current();
	return 0;
}

static int qplat_charger_get_ibus_ma(int *ibus, void *dev_data)
{
	int cur = 0;
	struct qplat_charger_device_info *di = dev_data;

	if (!di || !ibus)
		return -EPERM;

	if (power_supply_get_int_property_value("usb",
		POWER_SUPPLY_PROP_CURRENT_NOW, &cur))
		return -EPERM;

	*ibus = cur / POWER_UA_PER_MA;
	return 0;
}

static int qplat_charger_get_vbus_mv(int *vbus, void *dev_data)
{
	int vol = 0;
	struct qplat_charger_device_info *di = dev_data;

	if (!di || !vbus)
		return -EPERM;

	if (power_supply_get_int_property_value("usb",
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &vol))
		return -EPERM;

	*vbus = vol / POWER_UV_PER_MV;
	return 0;
}

static int qplat_charger_get_device_temp(int *temp, void *dev_data)
{
	struct qplat_charger_device_info *di = dev_data;

	if (!temp || !di)
		return -EPERM;
	*temp = DEFAULT_FAKE_SC_TEMP;

	return 0;
}

static int qplat_charger_get_vout_mv(int *vout, void *dev_data)
{
	return 0;
}

static int qplat_charger_config_watchdog_ms(int time, void *dev_data)
{
	return 0;
}

static int qplat_charger_kick_watchdog_ms(void *dev_data)
{
	return 0;
}

static int qplat_charger_sc_init(void *dev_data)
{
	return 0;
}

static int qplat_charger_sc_charge_exit(void *dev_data)
{
	return 0;
}

static int qplat_charger_batinfo_exit(void *dev_data)
{
	return 0;
}

static int qplat_charger_batinfo_init(void *dev_data)
{
	return 0;
}

static void qplat_charger_parse_dts(struct device_node *np,
	struct qplat_charger_device_info *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"ic_role", &di->ic_role, 0);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sc_max_input_current", &di->sc_max_input_current, DEFAULT_SC_MAX_INPUT_CURRENT);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"sc_max_charge_current", &di->sc_max_charge_current, DEFAULT_SC_MAX_CHARGE_CURRENT);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"use_buck_as_sc", &di->use_buck_as_sc, 0);

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"use_buck_as_sc4", &di->use_buck_as_sc4, 0);
}

static struct dc_ic_ops qplat_charger_sysinfo_ops = {
	.dev_name = "qplat_charger",
	.ic_init = qplat_charger_sc_init,
	.ic_exit = qplat_charger_sc_charge_exit,
	.ic_enable = qplat_charger_sc_enable,
	.ic_discharge = qplat_charger_discharge,
	.is_ic_close = qplat_charger_is_device_close,
	.get_ic_id = qplat_charger_get_device_id,
	.config_ic_watchdog = qplat_charger_config_watchdog_ms,
	.kick_ic_watchdog = qplat_charger_kick_watchdog_ms,
};

static struct dc_batinfo_ops qplat_charger_batinfo_ops = {
	.init = qplat_charger_batinfo_init,
	.exit = qplat_charger_batinfo_exit,
	.get_bat_btb_voltage = qplat_charger_get_vbat_mv,
	.get_bat_package_voltage = qplat_charger_get_vbat_mv,
	.get_vbus_voltage = qplat_charger_get_vbus_mv,
	.get_bat_current = qplat_charger_get_ibat_ma,
	.get_ic_ibus = qplat_charger_get_ibus_ma,
	.get_ic_temp = qplat_charger_get_device_temp,
	.get_ic_vout = qplat_charger_get_vout_mv,
};

static void qplat_charger_init_ops_dev_data(struct qplat_charger_device_info *di)
{
	memcpy_s(&di->sc_ops, sizeof(struct dc_ic_ops),
		&qplat_charger_sysinfo_ops, sizeof(struct dc_ic_ops));
	di->sc_ops.dev_data = (void *)di;
	memcpy_s(&di->batinfo_ops, sizeof(struct dc_batinfo_ops),
		&qplat_charger_batinfo_ops, sizeof(struct dc_batinfo_ops));
	di->batinfo_ops.dev_data = (void *)di;

	if (!di->ic_role) {
		snprintf_s(di->name, CHIP_DEV_NAME_LEN, CHIP_DEV_NAME_LEN - 1, "qplat_charger");
	} else {
		snprintf_s(di->name, CHIP_DEV_NAME_LEN,
			CHIP_DEV_NAME_LEN - 1, "qplat_charger_%d", di->ic_role);
		di->sc_ops.dev_name = di->name;
	}
}

static int qplat_charger_ops_register(struct qplat_charger_device_info *di)
{
	int ret;

	qplat_charger_init_ops_dev_data(di);
	if (di->use_buck_as_sc)
		ret = dc_ic_ops_register(SC_MODE, di->ic_role, &di->sc_ops);
	if (di->use_buck_as_sc4)
		ret = dc_ic_ops_register(SC4_MODE, di->ic_role, &di->sc_ops);

	ret += dc_batinfo_ops_register(di->ic_role, &di->batinfo_ops, di->device_id);
	if (ret) {
		hwlog_err("sysinfo ops register fail\n");
		return -EPERM;
	}
	hwlog_info("qplat_charger_sc_ops register successful!\n");
	return 0;
}

static int qplat_charger_probe(struct platform_device *pdev)
{
	int ret;
	struct qplat_charger_device_info *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;
	np = di->dev->of_node;

	qplat_charger_parse_dts(np, di);
	di->device_id = BUCK_QPLAT_CHARGER;

	ret = qplat_charger_ops_register(di);
	if (ret)
		goto ops_register_fail;

	platform_set_drvdata(pdev, di);
	hwlog_info("qcom_platform_charger driver probe successful!\n");
	return 0;

ops_register_fail:
	devm_kfree(&pdev->dev, di);
	return ret;
}

static int qplat_charger_remove(struct platform_device *pdev)
{
	struct qplat_charger_device_info *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	platform_set_drvdata(pdev, NULL);
	kfree(di);
	return 0;
}

static const struct of_device_id qplat_charger_of_match[] = {
	{
		.compatible = "huawei,qplat_charger_sc",
		.data = NULL,
	},
	{},
};

static struct platform_driver qplat_charger_driver = {
	.probe = qplat_charger_probe,
	.remove = qplat_charger_remove,
	.driver = {
		.owner = THIS_MODULE,
		.name = "huawei,qplat_charger_sc",
		.of_match_table = of_match_ptr(qplat_charger_of_match),
	},
};

static int __init qplat_charger_init(void)
{
	return platform_driver_register(&qplat_charger_driver);
}

static void __exit qplat_charger_exit(void)
{
	platform_driver_unregister(&qplat_charger_driver);
}

device_initcall_sync(qplat_charger_init);
module_exit(qplat_charger_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("qplat_charger module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
