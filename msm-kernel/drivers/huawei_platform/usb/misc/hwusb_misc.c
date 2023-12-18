/*
 * hwusb_misc.c
 *
 * file for usb misc driver
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

#include <huawei_platform/usb/hwusb_misc.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <linux/audio_interface.h>
#include <chipset_common/hwpower/common_module/power_vote.h>
#include <huawei_platform/log/hw_log.h>

#define HWLOG_TAG usb_misc
HWLOG_REGIST();

#define CHARGER_REGN_ADC_VOTE_OBJECT "charger_regn_adc"

struct usb_misc_dev_info *g_usb_misc_di;

int charger_regn_adc_enable(bool enable, bool force, const char *client_name)
{
	struct usb_misc_dev_info *l_dev = g_usb_misc_di;

	if (!l_dev || !client_name || !l_dev->p_ops || !l_dev->p_ops->adc_enable ||
		!l_dev->p_ops->dev_data || !l_dev->p_ops->sc_regn_enable)
		return -EINVAL;

	if (force) {
		l_dev->p_ops->sc_regn_enable(enable, l_dev->p_ops->dev_data);
		l_dev->p_ops->adc_enable(enable, l_dev->p_ops->dev_data);
		return 0;
	}

	return power_vote_set(CHARGER_REGN_ADC_VOTE_OBJECT, client_name, enable, enable);
}
EXPORT_SYMBOL(charger_regn_adc_enable);

static int charger_regn_adc_vote_callback(struct power_vote_object *obj,
	void *data, int result, const char *client_str)
{
	struct usb_misc_dev_info *l_dev = (struct usb_misc_dev_info *)data;

	if (!l_dev || !client_str) {
		hwlog_err("l_dev or client_str is null\n");
		return -EINVAL;
	}

	hwlog_info("result=%d client_str=%s\n", result, client_str);

	g_usb_misc_di->p_ops->sc_regn_enable(result, g_usb_misc_di->p_ops->dev_data);
	g_usb_misc_di->p_ops->adc_enable(result, g_usb_misc_di->p_ops->dev_data);

	return 0;
}

int huawei_usb_misc_ops_register(struct huawei_usb_misc_ops *ops)
{
	if (!g_usb_misc_di || !ops) {
		hwlog_err("dev or ops is null\n");
		return -EINVAL;
	}

	g_usb_misc_di->p_ops = ops;
	hwlog_info("ops register ok\n");

	return 0;
}

static int usb_misc_probe(struct platform_device *pdev)
{
	struct usb_misc_dev_info *di = NULL;

	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_usb_misc_di = di;
	di->dev = &pdev->dev;
	platform_set_drvdata(pdev, di);

	power_vote_create_object(CHARGER_REGN_ADC_VOTE_OBJECT, POWER_VOTE_SET_ANY,
		charger_regn_adc_vote_callback, di);

	hwlog_info("probe end\n");
	return 0;
}

static int usb_misc_remove(struct platform_device *pdev)
{
	struct usb_misc_dev_info *di = platform_get_drvdata(pdev);

	if (!di)
		return 0;

	platform_set_drvdata(pdev, NULL);
	g_usb_misc_di = NULL;
	kfree(di);

	return 0;
}

static const struct of_device_id usb_misc_match_table[] = {
	{
		.compatible = "huawei,usb_misc",
		.data = NULL,
	},
	{},
};

static struct platform_driver usb_misc_driver = {
	.probe = usb_misc_probe,
	.remove = usb_misc_remove,
	.driver = {
		.name = "huawei,usb_misc",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(usb_misc_match_table),
	},
};

static int __init usb_misc_init(void)
{
	return platform_driver_register(&usb_misc_driver);
}

static void __exit usb_misc_exit(void)
{
	platform_driver_unregister(&usb_misc_driver);
}

module_init(usb_misc_init);
module_exit(usb_misc_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei usb misc driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
