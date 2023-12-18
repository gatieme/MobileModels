/* SPDX-License-Identifier: GPL-2.0 */
/*
 * hw_pogopin_otg_id.c
 *
 * pogopin id driver
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

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/mutex.h>
#include <linux/platform_device.h>
#include <linux/pm_wakeup.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/delay.h>
#include <linux/of_address.h>
#include <linux/regulator/consumer.h>
#include <linux/clk.h>
#include <linux/of_gpio.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <huawei_platform/usb/hw_pogopin.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/usb/hw_pogopin_otg_id.h>
#include <linux/gpio.h>
#include <linux/power_supply.h>
#include <chipset_common/hwpower/common_module/power_pinctrl.h>
#include <linux/extcon-provider.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#if IS_ENABLED(CONFIG_QCOM_FSA4480_I2C)
#include <linux/soc/qcom/fsa4480-i2c.h>
 #endif
#include <chipset_common/hwpower/common_module/power_wakeup.h>

/* include platform head-file */
#if defined(CONFIG_DEC_USB)
#include "dwc_otg_dec.h"
#include "dwc_otg_cil.h"
#endif

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG hw_pogopin_id
HWLOG_REGIST();

static struct pogopin_otg_id_dev *g_pogopin_otg_id_di;


static int pogopin_otg_id_adc_sampling(struct pogopin_otg_id_dev *di)
{
	int i;
	int avgvalue;
	int vol_value;
	int sum = ADC_SAMPLING_SUM_DEFAULT;
	int retry = ADC_SAMPLING_RETRY_TIMES;
	int sample_cnt = ADC_SAMPLE_COUNT_DEFAULT;

	if (!di->id_iio) {
		do {
			di->id_iio = iio_channel_get(&(di->pdev->dev), "pogo-id");
			if (IS_ERR(di->id_iio)) {
				hwlog_info("pogo-id channel not ready:%d\n", retry);
				di->id_iio = NULL;
				/* 100: wait for iio channel ready */
				msleep(100);
			} else {
				hwlog_info("pogo-id channel is ready\n");
				break;
			}
		} while (retry-- > 0);
	}

	if (!di->id_iio) {
		hwlog_err("pogo-id channel not exist\n");
		return GET_ADC_FAIL;
	}

	for (i = 0; i < VBATT_AVR_MAX_COUNT; i++) {
		(void)iio_read_channel_processed(di->id_iio, &vol_value);
		hwlog_info("%s, vol:%d\n", __func__, vol_value);
		udelay(SMAPLING_OPTIMIZE);

		/* 0: vol_value is negative */
		if (vol_value < 0) {
			hwlog_info("the value from adc is error\n");
			return GET_ADC_FAIL;
		}

		sum += vol_value;
		sample_cnt++;
	}

	avgvalue = sum / sample_cnt;
	hwlog_info("the average voltage of adc is %d\n", avgvalue);

	return avgvalue;
}

static void pogopin_otg_in_handle_work(struct pogopin_otg_id_dev *di)
{
	if (!di)
		return;

	hwlog_info("pogopin otg insert cutoff cc,wait data and power switch\n");

	/* open ocp when plug in pogo otg */
	if (di->ocp_control_support)
		gpio_set_value(di->ocp_en_gpio, HIGH);
	/* set usb mode to micro usb mode */
	pogopin_set_usb_mode(POGOPIN_MICROB_OTG_MODE);
	pogopin_5pin_set_pogo_status(POGO_OTG);
	pogopin_5pin_otg_in_switch_from_typec();
	(void)power_msleep(DT_MSLEEP_100MS, 0, NULL);
	pogopin_event_notify(POGOPIN_PLUG_IN_OTG);
}

static void pogopin_otg_out_handle_work(struct pogopin_otg_id_dev *di)
{
	if (!di)
		return;

	hwlog_info("pogopin otg out,switch to typec, wait\n");

	/* close ocp when plug out pogo otg */
	if (di->ocp_control_support)
		gpio_set_value(di->ocp_en_gpio, LOW);
	/* set usb mode to typec usb mode */
	pogopin_set_usb_mode(POGOPIN_TYPEC_MODE);
	pogopin_event_notify(POGOPIN_PLUG_OUT_OTG);
	pogopin_5pin_remove_switch_to_typec();
}

static int pogopin_otg_status_check_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct pogopin_otg_id_dev *di = g_pogopin_otg_id_di;

	if (!di) {
		hwlog_err("di is null\n");
		return NOTIFY_OK;
	}

	switch (event) {
	case POGOPIN_CHARGER_OUT_COMPLETE:
		if (gpio_get_value(di->gpio) == LOW) {
			power_wakeup_lock(di->wakelock, false);
			schedule_delayed_work(&di->otg_intb_work,
				POGOPIN_DELAYED_50MS);
		}
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static void pogopin_otg_id_intb_work(struct work_struct *work)
{
	int gpio_value;
	struct pogopin_otg_id_dev *di = g_pogopin_otg_id_di;
	static bool pogo_otg_trigger = false;
	int avgvalue;

	if (!work || !di || pogopin_is_charging()) {
		hwlog_err("work or di is null or pogopin is charging\n");
		goto exit;
	}

	gpio_value = gpio_get_value(di->gpio);
	hwlog_info("%s gpio_value = %d\n", __func__, gpio_value);

	if (di->pogo_otg_gpio_status == gpio_value)
		goto exit;

	di->pogo_otg_gpio_status = gpio_value;

	if (gpio_value == LOW) {
		avgvalue = pogopin_otg_id_adc_sampling(di);
		if ((avgvalue >= 0) && (avgvalue <= ADC_VOLTAGE_LIMIT)) {
			pogo_otg_trigger = true;
			pogopin_otg_in_handle_work(di);
		} else {
			hwlog_info("avgvalue is %d\n", avgvalue);
		}
	} else {
		/* ignore otg plug out event when undetect otg plug in event */
		if (!pogo_otg_trigger) {
			hwlog_err("%s:otg insert error, do nothing\n",
				__func__);
			goto exit;
		}
		pogo_otg_trigger = false;
		pogopin_otg_out_handle_work(di);
	}

exit:
	power_wakeup_unlock(di->wakelock, false);
}

static irqreturn_t pogopin_otg_id_irq_handle(int irq, void *dev_id)
{
	struct pogopin_otg_id_dev *di = g_pogopin_otg_id_di;

	if (!di) {
		hwlog_err("di is null\n");
		return IRQ_HANDLED;
	}

	disable_irq_wake(di->irq);
	power_wakeup_lock(di->wakelock, false);


	enable_irq_wake(di->irq);
	schedule_delayed_work(&di->otg_intb_work, POGOPIN_DELAYED_50MS);

	return IRQ_HANDLED;
}

static int pogopin_otg_id_parse_dts(struct pogopin_otg_id_dev *di,
	struct device_node *np)
{
	if (!di)
		return -EINVAL;

	di->gpio = of_get_named_gpio(np, "pogo_otg_int_gpio", 0);
	if (!gpio_is_valid(di->gpio)) {
		hwlog_err("gpio is not valid\n");
		return -EINVAL;
	}

	if (power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"otg_adc_channel", &di->otg_adc_channel, 0))
		return -EINVAL;
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"ocp_control_support", &di->ocp_control_support, 0);

	if (di->ocp_control_support) {
		di->ocp_en_gpio = of_get_named_gpio(np, "ocp_en_gpio", 0);
		hwlog_info("ocp_en_gpio=%d\n", di->ocp_en_gpio);
		if (!gpio_is_valid(di->ocp_en_gpio)) {
			hwlog_err("gpio is not valid\n");
			return -EINVAL;
		}

		di->ocp_int_gpio = of_get_named_gpio(np, "ocp_int_gpio", 0);
		hwlog_info("ocp_int_gpio=%d\n", di->ocp_int_gpio);
		if (!gpio_is_valid(di->ocp_int_gpio)) {
			hwlog_err("gpio is not valid\n");
			return -EINVAL;
		}
	}

	return 0;
}

static void pogopin_ocp_irq_work(struct work_struct *work)
{
	struct pogopin_otg_id_dev *di = g_pogopin_otg_id_di;

	pogopin_set_buck_boost_gpio(LOW);
	msleep(OCP_DELAY_2MS);
	gpio_set_value(di->ocp_en_gpio, LOW);
	power_wakeup_unlock(di->wakelock, false);
}

static irqreturn_t pogopin_ocp_handler(int irq, void *dev_id)
{
	struct pogopin_otg_id_dev *di = dev_id;

	if (!di) {
		hwlog_err("di is null\n");
		return IRQ_HANDLED;
	}

	disable_irq_wake(di->ocp_irq);
	power_wakeup_lock(di->wakelock, false);
	enable_irq_wake(di->ocp_irq);
	schedule_work(&di->ocp_work);

	return IRQ_HANDLED;
}

int pogopin_request_ocp_irq(struct pogopin_otg_id_dev *di)
{
	int ret;

	if (!di) {
		hwlog_err("di is null\n");
		return -EINVAL;
	}

	di->ocp_irq = gpio_to_irq(di->ocp_int_gpio);
	if (di->ocp_irq < 0) {
		hwlog_err("gpio map to irq fail\n");
		return -EINVAL;
	}
	hwlog_info("ocp_irq=%d\n", di->ocp_irq);

	/* request ocp irq */
	ret = request_irq(di->ocp_irq, pogopin_ocp_handler,
			IRQF_TRIGGER_FALLING, "ocp_irq", di);
	if (ret) {
		hwlog_err("gpio irq request fail\n");
		di->ocp_irq = -1;
		return -EINVAL;
	}

	enable_irq_wake(di->ocp_irq);
	return 0;
}

int pogopin_set_ocp_gpio(struct pogopin_otg_id_dev *di)
{
	int ret;

	if (!di) {
		hwlog_err("di is null\n");
		return -EINVAL;
	}

	/* request ocp en gpio */
	ret = gpio_request(di->ocp_en_gpio, "ocp_en_gpio");
	if (ret) {
		hwlog_err("ocp en gpio request fail\n");
		goto fail_ocp_en_gpio;
	}

	/* set ocp en gpio direction */
	ret = gpio_direction_output(di->ocp_en_gpio, LOW);
	if (ret < 0) {
		hwlog_err("gpio set output fail\n");
		goto fail_ocp_en_gpio_dir;
	}

	/* request ocp int gpio */
	ret = gpio_request(di->ocp_int_gpio, "ocp_int_gpio");
	if (ret) {
		hwlog_err("gpio request fail\n");
		goto fail_ocp_en_gpio_dir;
	}

	/* set ocp int gpio direction */
	ret = gpio_direction_input(di->ocp_int_gpio);
	if (ret < 0) {
		hwlog_err("gpio set input fail\n");
		goto fail_ocp_int_gpio_dir;
	}
	msleep(5);   /* Wait the GPIO status stable.  */

	if (pogopin_request_ocp_irq(di) < 0)
		goto fail_ocp_int_gpio_dir;

	return 0;

fail_ocp_int_gpio_dir:
	gpio_free(di->ocp_int_gpio);
fail_ocp_en_gpio_dir:
	gpio_free(di->ocp_en_gpio);
fail_ocp_en_gpio:
	return -EINVAL;
}

static int pogopin_otg_id_irq_init(struct pogopin_otg_id_dev *di)
{
	int ret = -EINVAL;

	if (!di)
		return -EINVAL;

	di->irq = gpio_to_irq(di->gpio);
	if (di->irq < 0) {
		hwlog_err("gpio map to irq fail\n");
		return ret;
	}

	ret = request_irq(di->irq, pogopin_otg_id_irq_handle,
		IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_ONESHOT, "otg_gpio_irq", NULL);
	if (ret < 0) {
		hwlog_err("gpio irq request fail\n");
		return ret;
	} else {
		di->otg_irq_enabled = TRUE;
	}

	enable_irq_wake(di->irq);

	return ret;
}

static int pogopin_otg_id_probe(struct platform_device *pdev)
{
	int ret;
	struct device_node *np = NULL;
	struct device *dev = NULL;
	struct pogopin_otg_id_dev *di = NULL;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	g_pogopin_otg_id_di = di;
	platform_set_drvdata(pdev, di);
	di->pdev = pdev;
	dev = &pdev->dev;
	np = dev->of_node;

	di->pogo_otg_gpio_status = -1;
	(void)power_pinctrl_config(&(pdev->dev), "pinctrl-names", 1);
	ret = pogopin_otg_id_parse_dts(di, np);
	if (ret != 0) {
		hwlog_err("fail to parse dts");
		goto fail_parse_dts;
	}

	di->pogopin_otg_status_check_nb.notifier_call =
		pogopin_otg_status_check_notifier_call;
	ret = pogopin_event_notifier_register(&di->pogopin_otg_status_check_nb);
	if (ret < 0) {
		hwlog_err("pogopin otg_notifier register failed\n");
		goto fail_parse_dts;
	}

	di->id_iio = iio_channel_get(&(pdev->dev), "pogo-id");
	if (IS_ERR(di->id_iio)) {
		hwlog_info("pogo-id channel not ready in probe\n");
		di->id_iio = NULL;
	} else {
		hwlog_info("pogo-id channel is ready in probe\n");
	}

	di->wakelock = power_wakeup_source_register(&pdev->dev, "pogopin_otg_wakelock");
	if (!di->wakelock) {
		hwlog_err("fail register wakeup_source\n");
		goto fail_register_wakeup_source;
	}
	ret = gpio_request(di->gpio, "otg_gpio_irq");
	if (ret < 0) {
		hwlog_err("gpio request fail\n");
		goto fail_request_gpio;
	}

	INIT_DELAYED_WORK(&di->otg_intb_work, pogopin_otg_id_intb_work);
	if (di->ocp_control_support)
		INIT_WORK(&di->ocp_work, pogopin_ocp_irq_work);

	if (di->ocp_control_support) {
		if (pogopin_set_ocp_gpio(di) < 0) {
			hwlog_err("ocp gpio set fail\n");
			goto fail_set_ocp_gpio;
		}
	}
	ret = gpio_direction_input(di->gpio);
	if (ret < 0) {
		hwlog_err("gpio set input fail\n");
		goto fail_set_gpio_direction;
	}
	msleep(5); /* sleep 5 ms */
	ret = pogopin_otg_id_irq_init(di);
	if (ret != 0) {
		hwlog_err("pogopin_otg_id_irq_init fail\n");
		goto fail_request_irq;
	}

	ret = gpio_get_value(di->gpio);
	if (ret == 0) {
		power_wakeup_lock(di->wakelock, false);
		schedule_delayed_work(&di->otg_intb_work, OTG_DELAYED_5000MS);
	}

	return 0;
fail_request_irq:
fail_set_gpio_direction:
	if (di->ocp_control_support) {
		gpio_free(di->ocp_en_gpio);
		free_irq(di->ocp_irq, pdev);
		gpio_free(di->ocp_int_gpio);
	}
fail_set_ocp_gpio:
	gpio_free(di->gpio);
	power_wakeup_source_unregister(di->wakelock);
fail_parse_dts:
fail_request_gpio:
fail_register_wakeup_source:
	pogopin_event_notifier_unregister(&di->pogopin_otg_status_check_nb);
	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, di);
	return ret;
}

static int pogopin_otg_id_remove(struct platform_device *pdev)
{
	struct pogopin_otg_id_dev *di = g_pogopin_otg_id_di;

	if (!di)
		return -ENODEV;

	free_irq(di->irq, pdev);
	if (di->ocp_control_support) {
		gpio_free(di->ocp_en_gpio);
		free_irq(di->ocp_irq, pdev);
		gpio_free(di->ocp_int_gpio);
	}
	gpio_free(di->gpio);
	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, di);
	g_pogopin_otg_id_di = NULL;

	return 0;
}

static const struct of_device_id pogopin_otg_id_of_match[] = {
	{
		.compatible = "huawei,pogopin-otg-by-id",
	},
	{},
};

static struct platform_driver pogopin_otg_id_drv = {
	.probe = pogopin_otg_id_probe,
	.remove = pogopin_otg_id_remove,
	.driver = {
		.owner = THIS_MODULE,
		.name = "pogo_otg_id",
		.of_match_table = pogopin_otg_id_of_match,
	},
};

static int __init pogopin_otg_id_init(void)
{
	return platform_driver_register(&pogopin_otg_id_drv);
}

static void __exit pogopin_otg_id_exit(void)
{
	platform_driver_unregister(&pogopin_otg_id_drv);
}

late_initcall(pogopin_otg_id_init);
module_exit(pogopin_otg_id_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("POGOPIN OTG connection/disconnection driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
