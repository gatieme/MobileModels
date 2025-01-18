/*
 * buck_boost_notifier.c
 *
 * buck_boost_notifier driver
 *
 * Copyright (c) 2024-2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
 
#include "buck_boost_notifier.h"
 
#include <huawei_platform/log/hw_log.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <securec.h>
#include <linux/of.h>
#include <buck_boost.h>
 
#define HWLOG_TAG buck_boost_notifier
#define MOD_NAME "buck_boost_notifier"

static unsigned int is_support_buck_boost_notifier = 0;

HWLOG_REGIST();
static long buck_boost_notifier(void __user *data)
{
	long ret = 0;
	unsigned int buck_boost_status = 0;

	if (!is_support_buck_boost_notifier || !data)
		return -1;
	ret = copy_from_user(&buck_boost_status, data, sizeof(buck_boost_status));
	if (ret) {
		hwlog_err("%s: get buck_boost_status fail\n", __func__);
		return -EFAULT;
	}
	if (buck_boost_status != BUCK_BOOST_PWM_ENABLE && buck_boost_status != BUCK_BOOST_PWM_DISABLE) {
		hwlog_err("%s: Invalid data: %u Expected 0 or 1\n", __func__, buck_boost_status);
		return -EINVAL;
	}
#ifdef CONFIG_BUCKBOOST
	ret = buck_boost_set_pwm_enable(buck_boost_status, BUCK_BOOST_INDEX);
	if (ret) {
		hwlog_err("%s: set buck_boost_status fail\n", __func__);
		return ret;
	}
#endif
	hwlog_info("%s: buck_boost_status = %u\n", __func__, buck_boost_status);
    return EOK;
}

static long buck_boost_notifier_ioctl(unsigned int command, unsigned long arg)
{
	long ret = 0;
	void __user *data = (void __user *)(uintptr_t)arg;

	if (command == BUCK_BOOST_NOTIFIER)
		ret = buck_boost_notifier(data);
	else 
		hwlog_err("%s: not support command = 0x%x\n", __func__, command);

	return ret;
}

static void buck_boost_notifier_init(struct device_node *np)
{
    unsigned int tmp = 0;

	struct device_node *np_child = of_get_child_by_name(np, "buck_boost_notifier");
	if (!of_property_read_u32(np_child, "support_buck_boost_notifier", &tmp))
		is_support_buck_boost_notifier = tmp;

	hwlog_info("is_support_buck_boost_notifier = %u\n", is_support_buck_boost_notifier);
}

static void buck_boost_notifier_remove(void *priv)
{
	(void)(priv);
}

static const struct audio_misc_module_ops buck_boost_notifiler_ops = {
	.ioctl = buck_boost_notifier_ioctl,
	.remove = buck_boost_notifier_remove,
};

int buck_boost_notifier_probe(struct device *dev, struct device_node *np)
{
	int ret;

	hwlog_info("%s: in\n", __func__);
	buck_boost_notifier_init(np);
	ret = audio_misc_module_constructor(MOD_NAME, NULL, BUCK_BOOST_IOCTL_TYPE, &buck_boost_notifiler_ops);
	if (ret) {
		hwlog_err("%s: constructor buck_boost_notifier fail \n", __func__);
		ret = -ENOMEM;
	}

	return ret;
}