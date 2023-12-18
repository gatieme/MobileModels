// SPDX-License-Identifier: GPL-2.0
/*
 * power_glink_interface.c
 *
 * glink interface for power module
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>

#define HWLOG_TAG power_glink_interface
HWLOG_REGIST();

struct power_glink_interface_dev {
	struct device *dev;
	struct power_glink_interface_ops *ops;
};

static struct power_glink_interface_dev *g_power_glink_interface_dev;

int power_glink_interface_get_property_value(u32 prop_id, u32 *data_buffer, u32 data_size)
{
	struct power_glink_interface_ops *l_ops = NULL;

	if (!g_power_glink_interface_dev || !g_power_glink_interface_dev->ops)
		return -EPERM;

	l_ops = g_power_glink_interface_dev->ops;
	if (!l_ops->power_glink_get_property_value) {
		hwlog_err("power_glink_get_property_value is null\n");
		return -EPERM;
	}

	return l_ops->power_glink_get_property_value(prop_id, data_buffer, data_size);
}

int power_glink_interface_set_property_value(u32 prop_id, u32 *data_buffer, u32 data_size)
{
	struct power_glink_interface_ops *l_ops = NULL;

	if (!g_power_glink_interface_dev || !g_power_glink_interface_dev->ops)
		return -EPERM;

	l_ops = g_power_glink_interface_dev->ops;
	if (!l_ops->power_glink_set_property_value) {
		hwlog_err("power_glink_set_property_value is null\n");
		return -EPERM;
	}

	return l_ops->power_glink_set_property_value(prop_id, data_buffer, data_size);
}

int power_glink_interface_support_fcp_pd_icl(void)
{
	struct power_glink_interface_ops *l_ops = NULL;

	if (!g_power_glink_interface_dev || !g_power_glink_interface_dev->ops)
		return -EPERM;

	l_ops = g_power_glink_interface_dev->ops;
	if (!l_ops->power_glink_support_fcp_pd_icl) {
		hwlog_err("power_glink_support_fcp_pd_icl is null\n");
		return -EPERM;
	}

	return l_ops->power_glink_support_fcp_pd_icl();
}

bool power_glink_interface_is_dcp_ever_detected(void)
{
	struct power_glink_interface_ops *l_ops = NULL;

	if (!g_power_glink_interface_dev || !g_power_glink_interface_dev->ops)
		return false;

	l_ops = g_power_glink_interface_dev->ops;
	if (!l_ops->is_dcp_ever_detected) {
		hwlog_err("is_dcp_ever_detected is null\n");
		return false;
	}

	return l_ops->is_dcp_ever_detected();
}

void power_glink_interface_handle_dc_connect_message(u32 msg)
{
	struct power_glink_interface_ops *l_ops = NULL;

	if (!g_power_glink_interface_dev || !g_power_glink_interface_dev->ops)
		return;

	l_ops = g_power_glink_interface_dev->ops;
	if (!l_ops->power_glink_handle_dc_connect_message) {
		hwlog_err("power_glink_handle_dc_connect_message is null\n");
		return;
	}

	l_ops->power_glink_handle_dc_connect_message(msg);
}
EXPORT_SYMBOL_GPL(power_glink_interface_handle_dc_connect_message);

void power_glink_interface_handle_charge_type_message(u32 msg)
{
	struct power_glink_interface_ops *l_ops = NULL;

	if (!g_power_glink_interface_dev || !g_power_glink_interface_dev->ops)
		return;

	l_ops = g_power_glink_interface_dev->ops;
	if (!l_ops->power_glink_handle_charge_type_message) {
		hwlog_err("power_glink_handle_charge_type_message is null\n");
		return;
	}

	l_ops->power_glink_handle_charge_type_message(msg);
}
EXPORT_SYMBOL_GPL(power_glink_interface_handle_charge_type_message);

int power_glink_interface_haptics_enable_hboost_5v(int value)
{
	struct power_glink_interface_ops *l_ops = NULL;

	if (!g_power_glink_interface_dev || !g_power_glink_interface_dev->ops)
		return -EPERM;

	l_ops = g_power_glink_interface_dev->ops;
	if (!l_ops->haptics_enable_hboost_5v) {
		hwlog_err("haptics_enable_hboost_5v is null\n");
		return -EPERM;
	}

	return l_ops->haptics_enable_hboost_5v(value);
}

int power_glink_interface_ops_register(struct power_glink_interface_ops *ops)
{
	if (!g_power_glink_interface_dev || !ops) {
		hwlog_err("g_adapter_protocol_dev or ops is null\n");
		return -EPERM;
	}

	g_power_glink_interface_dev->ops = ops;
	hwlog_info("%s ok\n", __func__);
	return 0;
}
EXPORT_SYMBOL_GPL(power_glink_interface_ops_register);

static int __init power_glink_interface_init(void)
{
	struct power_glink_interface_dev *l_dev = NULL;

	l_dev = kzalloc(sizeof(*l_dev), GFP_KERNEL);
	if (!l_dev)
		return -ENOMEM;


	g_power_glink_interface_dev = l_dev;
	hwlog_info("%s ok\n", __func__);
	return 0;
}

static void __exit power_glink_interface_exit(void)
{
	if (!g_power_glink_interface_dev)
		return;

	kfree(g_power_glink_interface_dev);
	g_power_glink_interface_dev = NULL;
}

device_initcall(power_glink_interface_init);
module_exit(power_glink_interface_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("power glink interface driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
