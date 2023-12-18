/*
 * Copyright (C) 2022-2022 HUAWEI, Inc.
 * rf driver
 *
 * This program is used for RF drive
 *
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/slab.h>
#include <linux/of_platform.h>
#include <linux/of_gpio.h>
#include <linux/pm.h>
#include <linux/delay.h>
#include <securec.h>

#define TAG "RF_Driver: "

struct rf_device {
	struct device *dev;
};

static int rf_pinctol(struct device *dev)
{
	int ret = 1;
	struct pinctrl *pctrl = NULL;
	struct pinctrl_state *pctrl_state = NULL;

	pctrl = devm_pinctrl_get(dev);
	if (IS_ERR(pctrl)) {
		pr_err(TAG "failed to devm pinctrl get\n");
		return -EINVAL;
	}

	pctrl_state = pinctrl_lookup_state(pctrl, "rf_driver_default");
	if (IS_ERR(pctrl_state)) {
		pr_err(TAG "failed to pinctrl lookup state default\n");
		devm_pinctrl_put(pctrl);
		return -EINVAL;
	}

	ret = pinctrl_select_state(pctrl, pctrl_state);
	if (ret < 0) {
		pr_err(TAG "set iomux normal error, %d\n", ret);
		devm_pinctrl_put(pctrl);
		return ret;
	}

	pr_info(TAG "rf_pinctol pass!\n");

	ret = 0;
	return ret;
}

static int rf_driver_probe(struct platform_device *pdev)
{
	if (rf_pinctol(&pdev->dev) != 0)
		pr_info(TAG "set extended gpio fail!\n");

	pr_info(TAG "RF driver probe ok!\n");
	return 0;
}

/*
 * probe match table
*/
static struct of_device_id rf_driver_match[] = {
	{
		.compatible = "huawei,rf_driver",
		.data = NULL,
	},
	{},
};

/*
 * rf driver
 */
static struct platform_driver rf_driver = {
	.probe = rf_driver_probe,
	.driver = {
		.name = "huawei,rf_driver",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(rf_driver_match),
	},
};

/***************************************************************
 * Function: rf_driver_init
 * Description: rf driver initialization
 * Parameters:  Null
 * return value: 0-sucess or others-fail
 * **************************************************************/
static int __init rf_driver_init(void)
{
	return platform_driver_register(&rf_driver);
}

/*******************************************************************
 * Function:       rf_driver_exit
 * Description:    rf driver module exit
 * Parameters:   NULL
 * return value:  NULL
 * *********************************************************/
static void __exit rf_driver_exit(void)
{
	platform_driver_unregister(&rf_driver);
}

late_initcall(rf_driver_init);
module_exit(rf_driver_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("huawei rf driver");
MODULE_AUTHOR("HUAWEI Inc");
