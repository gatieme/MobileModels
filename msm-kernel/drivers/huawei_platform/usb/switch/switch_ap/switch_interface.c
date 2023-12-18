/*
 * switch_interface.c
 *
 * driver file for switch_interface
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

#include "switch_interface.h"
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <huawei_platform/power/huawei_charger_common.h>
#include <huawei_platform/usb/switch/usbswitch_common.h>

#define HWLOG_TAG switch_interface
HWLOG_REGIST();

static struct switch_interface_di *g_switch_interface_di;

bool switch_interface_get_chip_init_status(void)
{
	struct switch_interface_info_ops *ops = switch_interface_get_info_ops();

	if (!ops || !ops->chip_init_status)
		return false;

	return ops->chip_init_status();
}

unsigned int switch_interface_get_charger_type(void)
{
	struct switch_interface_bc12_ops *ops = switch_interface_get_bc12_ops();

	if (!ops || !ops->get_charger_type)
		return CHARGER_REMOVED;

	return ops->get_charger_type();
}

static int switch_interface_enable_bc12(bool en)
{
	struct switch_interface_bc12_ops *ops = switch_interface_get_bc12_ops();

	if (!ops || !ops->chg_type_det)
		return -EINVAL;

	return ops->chg_type_det(en);
}

static int switch_interface_dcd_timeout(bool enable_flag)
{
	struct switch_interface_bc12_ops *ops = switch_interface_get_bc12_ops();

	if (!ops || !ops->dcd_timeout)
		return -1;

	return ops->dcd_timeout(enable_flag);
}

static int switch_interface_dcd_timeout_status(void)
{
	struct switch_interface_bc12_ops *ops = switch_interface_get_bc12_ops();

	if (!ops || !ops->dcd_timeout_status)
		return -1;

	return ops->dcd_timeout_status();
}

struct switch_interface_di *switch_interface_get_device_info(void)
{
	if (!g_switch_interface_di)
		return NULL;

	return g_switch_interface_di;
}

struct switch_interface_charger_ops *switch_interface_get_charger_ops(void)
{
	if (!g_switch_interface_di || !g_switch_interface_di->chg_ops) {
		hwlog_err("g_switch_interface_di or si_ops is null\n");
		return NULL;
	}

	return g_switch_interface_di->chg_ops;
}

struct switch_interface_control_ops *switch_interface_get_control_ops(void)
{
	if (!g_switch_interface_di || !g_switch_interface_di->ctrl_ops) {
		hwlog_err("g_switch_interface_di or ctrl_ops is null\n");
		return NULL;
	}

	return g_switch_interface_di->ctrl_ops;
}

struct switch_interface_bc12_ops *switch_interface_get_bc12_ops(void)
{
	if (!g_switch_interface_di || !g_switch_interface_di->bc12_ops) {
		hwlog_err("g_switch_interface_di or bc12_ops is null\n");
		return NULL;
	}

	return g_switch_interface_di->bc12_ops;
}

struct switch_interface_info_ops *switch_interface_get_info_ops(void)
{
	if (!g_switch_interface_di || !g_switch_interface_di->info_ops) {
		hwlog_err("g_switch_interface_di or info_ops is null\n");
		return NULL;
	}

	return g_switch_interface_di->info_ops;
}

void switch_interface_charger_ops_register(struct switch_interface_charger_ops *ops)
{
	if (!g_switch_interface_di || !ops)
		return;

	hwlog_info("switch interface charger ops register ok\n");
	g_switch_interface_di->chg_ops = ops;
}

void switch_interface_control_ops_register(struct switch_interface_control_ops *ops)
{
	if (!g_switch_interface_di || !ops)
		return;

	hwlog_info("switch interface ctrl ops register ok\n");
	g_switch_interface_di->ctrl_ops = ops;
}

void switch_interface_bc12_ops_register(struct switch_interface_bc12_ops *ops)
{
	if (!g_switch_interface_di || !ops)
		return;

	hwlog_info("switch interface bc12 ops register ok\n");
	g_switch_interface_di->bc12_ops = ops;
}

void switch_interface_info_ops_register(struct switch_interface_info_ops *ops)
{
	if (!g_switch_interface_di || !ops)
		return;

	hwlog_info("switch interface info ops register ok\n");
	g_switch_interface_di->info_ops = ops;
}

struct charge_switch_ops switch_interface_chrg_ops = {
	.get_charger_type = switch_interface_get_charger_type,
};

static struct usbswitch_common_ops switch_interface_common_ops = {
	.manual_switch = switch_control_manual_switch,
	.dcd_timeout_enable = switch_interface_dcd_timeout,
	.dcd_timeout_status = switch_interface_dcd_timeout_status,
	.manual_detach = switch_control_manual_detach,
	.enable_chg_type_det = switch_interface_enable_bc12,
};

static void switch_interface_parse_dts(struct device_node *np,
	struct switch_interface_di *di)
{
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "fcp_support",
		&di->fcp_support, SWITCH_INTERFACE_FCP_SUPPORT_DEFAULT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "scp_support",
		&di->scp_support, SWITCH_INTERFACE_SCP_SUPPORT_DEFAULT);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "power_by_5v",
		&di->power_by_5v, SWITCH_INTERFACE_POWER_BY_5V_DEFAULT);
}

static int switch_interface_probe(struct platform_device *pdev)
{
	struct switch_interface_di *di = NULL;
	struct device_node *np = NULL;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_switch_interface_di = di;
	di->dev = &pdev->dev;
	np = di->dev->of_node;
	platform_set_drvdata(pdev, di);

	switch_interface_parse_dts(np, di);
	INIT_DELAYED_WORK(&di->detach_delayed_work, switch_control_manual_detach_work);
	switch_charger_protocol_register(di);
#ifdef CONFIG_HUAWEI_CHARGER
	if (charge_switch_ops_register(&switch_interface_chrg_ops) == 0)
		hwlog_info("charge switch ops register success\n");
#endif /* CONFIG_HUAWEI_CHARGER */
	usbswitch_common_ops_register(&switch_interface_common_ops);
	switch_control_sysfs_init(di);
	return 0;
}

static int switch_interface_remove(struct platform_device *pdev)
{
	struct switch_interface_di *di = platform_get_drvdata(pdev);

	if (!di)
		return 0;

	switch_control_sysfs_exit(di);
	platform_set_drvdata(pdev, NULL);
	kfree(di);
	g_switch_interface_di = NULL;
	return 0;
}

static const struct of_device_id switch_interface_match_table[] = {
	{
		.compatible = "huawei,switch_interface",
		.data = NULL,
	},
	{},
};

static struct platform_driver switch_interface_driver = {
	.probe = switch_interface_probe,
	.remove = switch_interface_remove,
	.driver = {
		.name = "huawei,switch_interface",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(switch_interface_match_table),
	},
};

static int __init switch_interface_init(void)
{
	return platform_driver_register(&switch_interface_driver);
}

static void __exit switch_interface_exit(void)
{
	platform_driver_unregister(&switch_interface_driver);
}

device_initcall(switch_interface_init);
module_exit(switch_interface_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("switch interface module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
