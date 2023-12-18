/* SPDX-License-Identifier: GPL-2.0 */
/*
 * pogopin_extcon.c
 *
 * pogopin extcon driver
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/extcon.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/delay.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/usb/hw_pd_dev.h>
#include <huawei_platform/usb/hw_pogopin.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG pogopin_extcon
HWLOG_REGIST();


struct pogopin_extcon_info {
	struct platform_device  *pdev;
	struct device           *dev;
	struct notifier_block   pogopin_status_check_nb;
	struct extcon_dev       *extcon;
};

static const unsigned int bcdev_pogopin_extcon_cable[] = {
	EXTCON_USB,
	EXTCON_USB_HOST,
	EXTCON_NONE,
};

static int pogopin_status_check_notifier_call(struct notifier_block *pogopin_status_check_nb,
	unsigned long event, void *data)
{
	struct pogopin_extcon_info *bcdev = NULL;
	u32 usb_prev_mode = 0;

	if (data != NULL)
		usb_prev_mode = *((u32 *)data);

	hwlog_info(" %s usb_prev_mode %d \n", __func__, usb_prev_mode);

	bcdev = container_of(pogopin_status_check_nb, struct pogopin_extcon_info, pogopin_status_check_nb);
	if (!bcdev) {
		hwlog_err("battery chg dev is null\n");
		return NOTIFY_OK;
	}

	switch (event) {
	case POGOPIN_PLUG_IN_OTG:
		/* Host mode connect notification */
		hwlog_info("%s : Host mode connect \n", __func__);
		extcon_set_state_sync(bcdev->extcon, EXTCON_USB_HOST, 1);
		break;

	case POGOPIN_PLUG_OUT_OTG:
		/* Host disconnect notification */
		hwlog_info("%s : Host mode disconnect\n", __func__);
		extcon_set_state_sync(bcdev->extcon, EXTCON_USB_HOST, 0);
		break;

	case POGOPIN_PLUG_IN_MICROUSB:
		/* Pogopin connect notification */
		hwlog_info("%s : Pogopin plug in notification\n", __func__);
		extcon_set_state_sync(bcdev->extcon, EXTCON_USB, 1);
		break;

	case POGOPIN_PLUG_OUT_MICROUSB:
		/* pogopin disconnect notification */
		hwlog_info("%s : Pogopin plug out notification\n", __func__);
		extcon_set_state_sync(bcdev->extcon, usb_prev_mode, 0);
		break;

	default:
		break;
	}

	return NOTIFY_OK;
}

static int register_pogopin_extcon_conn_type(struct pogopin_extcon_info *bcdev)
{
	int rc;

	bcdev->extcon = devm_extcon_dev_allocate(bcdev->dev,
						bcdev_pogopin_extcon_cable);
	if (IS_ERR(bcdev->extcon)) {
		rc = PTR_ERR(bcdev->extcon);
		hwlog_err("Failed to allocate extcon device rc=%d\n", rc);
		return rc;
	}

	rc = devm_extcon_dev_register(bcdev->dev, bcdev->extcon);
	if (rc < 0) {
		hwlog_err("Failed to register extcon device rc=%d\n", rc);
		goto error;
	}

	rc = extcon_set_property_capability(bcdev->extcon, EXTCON_USB,
					    EXTCON_PROP_USB_SS);
	rc |= extcon_set_property_capability(bcdev->extcon,
					     EXTCON_USB_HOST, EXTCON_PROP_USB_SS);
	if (rc < 0)
		hwlog_err("failed to configure extcon capabilities rc=%d\n", rc);
	else
		hwlog_info("Registered extcon success\n");

	return rc;

error:
	devm_extcon_dev_free(bcdev->dev, bcdev->extcon);
	return rc;
}

static int pogopin_extcon_probe(struct platform_device *pdev)
{
	int rc;
	struct pogopin_extcon_info *di  = NULL;
	struct device *dev = &pdev->dev;

	hwlog_info("[%s] enter\n", __func__);

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = dev;
	di->pdev = pdev;
	platform_set_drvdata(pdev, di);

	di->pogopin_status_check_nb.notifier_call = pogopin_status_check_notifier_call;
	rc = pogopin_event_notifier_register(&di->pogopin_status_check_nb);
	if (rc < 0) {
		hwlog_err("pogopin pogopin_status_check_nb register failed\n");
		goto fail_register_notify;
	}

	device_init_wakeup(di->dev, true);
	rc = register_pogopin_extcon_conn_type(di);
	if (rc < 0) {
		hwlog_err("Failed to register extcon rc=%d\n", rc);
		goto fail_register_extcon;
	}

	hwlog_info("[%s] end\n", __func__);
	return 0;

fail_register_extcon:
	pogopin_event_notifier_unregister(&di->pogopin_status_check_nb);
fail_register_notify:
	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, di);
	return rc;
}

static int pogopin_extcon_remove(struct platform_device *pdev)
{
	struct pogopin_extcon_info *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	device_init_wakeup(di->dev, false);
	pogopin_event_notifier_unregister(&di->pogopin_status_check_nb);
	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, di);
	return 0;
}

static const struct of_device_id pogopin_extcon_match_table[] = {
	{
		.compatible = "huawei,pogopin_extcon",
		.data = NULL,
	},
	{},
};

static struct platform_driver pogopin_extcon_driver = {
	.probe = pogopin_extcon_probe,
	.remove = pogopin_extcon_remove,
	.driver = {
		.name = "huawei,pogopin_extcon",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(pogopin_extcon_match_table),
	},
};

static int __init pogopin_extcon_init(void)
{
	return platform_driver_register(&pogopin_extcon_driver);
}

static void __exit pogopin_extcon_exit(void)
{
	platform_driver_unregister(&pogopin_extcon_driver);
}

module_init(pogopin_extcon_init);
module_exit(pogopin_extcon_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("pogopin extcon module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
