/*
  * h sensors_sysfs_hinge.c
  *
  * code for bal_poweroff_charging_fold
  *
  * Copyright (c) 2021 Huawei Technologies Co., Ltd.
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

#include <chipset_common/hwpower/common_module/power_cmdline.h>
#include <linux/of.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/of_device.h>
#include <huawei_platform/ap_hall/ext_hall_event.h>
#include "sensors_sysfs_hinge.h"
#include <misc/app_info.h>

bool is_poweroff_charge_notify_available = false;   // init invalid value

int ext_fold_status_notifier_cb(struct notifier_block *nb,
	unsigned long foo, void *bar)
{
	bool poweroff_flag = false;
	(void)bar;
	if (is_poweroff_charge_notify_available)
		poweroff_flag = true;
	ext_fold_status_notifier_cb_check(nb, foo, poweroff_flag);
	return 0;
}

void get_poweroff_fold_notify_status_from_dts(void)
{
	struct device_node *hall_node = NULL;
	uint32_t is_support_poweroff_charge_fold_notify = 0;
	bool power_mode = false;

	hall_node = of_find_compatible_node(NULL, NULL, "huawei,sensor_info");
	if (!hall_node) {
		pr_err("%s, can't find node hall\n", __func__);
		return;
	}
	if (!of_property_read_u32(hall_node, "is_support_poweroff_charge_fold_notify",
		&is_support_poweroff_charge_fold_notify))
		pr_info("get charge mode %d\n", is_support_poweroff_charge_fold_notify);

	power_mode = power_cmdline_is_powerdown_charging_mode();
	pr_info("get charging_mode mode %d, charge_check = %u\n",
		power_mode, is_support_poweroff_charge_fold_notify);
	if ((power_mode) && (is_support_poweroff_charge_fold_notify == 1))
		is_poweroff_charge_notify_available = true; // suport power off get fold
}

static struct notifier_block ext_fold_notify_to_hinge = {
	.notifier_call = ext_fold_status_notifier_cb,
	.priority = -1,
};

static int __init hinge_init(void)
{
	get_poweroff_fold_notify_status_from_dts();
	ext_fold_register_notifier(&ext_fold_notify_to_hinge);
	pr_info("ext_fold_register_notifier\n");
	return 0;
}

static void __exit hinge_exit(void)
{
	return;
}

subsys_initcall(hinge_init);
module_exit(hinge_exit);

MODULE_LICENSE("GPL");
