// SPDX-License-Identifier: GPL-2.0
/*
 * power_gpio_misc.c
 *
 * misc gpio configuration for power module
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
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <chipset_common/hwpower/common_module/power_pinctrl.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG power_gpio_misc
HWLOG_REGIST();

#define GPIO_NAME_SIZE  16
#define PINCTRL_NUM     8
#define GPIO_GROUP_SIZE 8

enum {
	GPIO_NAME,
	GPIO_DIRECTION,
	GPIO_VALUE,
	GPIO_GROUP_PARA_TOTAL,
};

struct gpio_group_para {
	char gpio_name[GPIO_NAME_SIZE];
	int gpio_direction;
	int gpio_value;
	int gpio_num;
};

struct power_gpio_misc_dev {
	struct device *dev;
	struct gpio_group_para *para;
};

static struct power_gpio_misc_dev *g_power_gpio_misc_di;

static void power_gpio_misc_config_gpio(int size, struct device_node *np, struct power_gpio_misc_dev *di)
{
	int i;

	for (i = 0; i < size; i++) {
		if (di->para[i].gpio_direction)
			power_gpio_config_output(np, di->para[i].gpio_name, di->para[i].gpio_name,
				&di->para[i].gpio_num, di->para[i].gpio_value);
		else
			power_gpio_config_input(np, di->para[i].gpio_name, di->para[i].gpio_name,
				&di->para[i].gpio_num);
	}

	for (i = 0; i < size; i++)
		hwlog_info("gpio_group[%d] %s %d %d %d\n", i, di->para[i].gpio_name, di->para[i].gpio_direction,
			di->para[i].gpio_value, di->para[i].gpio_num);
}

static int power_gpio_misc_config_gpio_group(struct device_node *np, struct power_gpio_misc_dev *di)
{
	int i, row, col, size, array_len;
	const char *tmp_string = NULL;

	array_len = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), np, "gpio_group",
		GPIO_GROUP_SIZE, GPIO_GROUP_PARA_TOTAL);
	if (array_len < 0)
		return -EINVAL;

	size = array_len / GPIO_GROUP_PARA_TOTAL;
	di->para = kzalloc(sizeof(struct gpio_group_para) * size, GFP_KERNEL);
	if (!di->para)
		return -ENOMEM;

	for (i = 0; i < array_len; i++) {
		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG), np, "gpio_group", i, &tmp_string))
			goto err_out;

		row = i / GPIO_GROUP_PARA_TOTAL;
		col = i % GPIO_GROUP_PARA_TOTAL;
		switch (col) {
		case GPIO_NAME:
			strncpy(di->para[row].gpio_name, tmp_string, GPIO_NAME_SIZE - 1);
			break;
		case GPIO_DIRECTION:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &di->para[row].gpio_direction))
				goto err_out;
			break;
		case GPIO_VALUE:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &di->para[row].gpio_value))
				goto err_out;
			break;
		default:
			break;
		}
	}

	power_gpio_misc_config_gpio(size, np, di);
	return 0;

err_out:
	kfree(di->para);
	di->para = NULL;
	return -EINVAL;
}

static void power_gpio_misc_config(struct device_node *np, struct power_gpio_misc_dev *di)
{
	(void)power_pinctrl_config(di->dev, "pinctrl-names", PINCTRL_NUM);
	if (power_gpio_misc_config_gpio_group(np, di))
		hwlog_err("config gpio group failed\n");
}

static int power_gpio_misc_probe(struct platform_device *pdev)
{
	struct power_gpio_misc_dev *di = NULL;
	struct device_node *np = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;
	np = di->dev->of_node;

	power_gpio_misc_config(np, di);

	g_power_gpio_misc_di = di;
	platform_set_drvdata(pdev, di);
	return 0;
}

static int power_gpio_misc_remove(struct platform_device *pdev)
{
	struct power_gpio_misc_dev *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	platform_set_drvdata(pdev, NULL);
	if (di->para)
		kfree(di->para);
	kfree(di);
	g_power_gpio_misc_di = NULL;
	return 0;
}

static const struct of_device_id power_gpio_misc_match_table[] = {
	{
		.compatible = "huawei,power_gpio_misc",
		.data = NULL,
	},
	{},
};

static struct platform_driver power_gpio_misc_driver = {
	.probe = power_gpio_misc_probe,
	.remove = power_gpio_misc_remove,
	.driver = {
		.name = "huawei,power_gpio_misc",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(power_gpio_misc_match_table),
	},
};
module_platform_driver(power_gpio_misc_driver);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("power gpio misc driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
