/* SPDX-License-Identifier: GPL-2.0 */
/*
 * hw_pogopin.c
 *
 * pogopin driver
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
#include <linux/platform_device.h>
#include <linux/power_supply.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <linux/workqueue.h>
#include <linux/interrupt.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <huawei_platform/log/hw_log.h>
#include <huawei_platform/usb/hw_pogopin.h>
#include <huawei_platform/usb/hw_pd_dev.h>
#include <chipset_common/hwpower/common_module/power_pinctrl.h>
#if IS_ENABLED(CONFIG_QCOM_FSA4480_I2C)
#include <linux/soc/qcom/fsa4480-i2c.h>
#endif
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>

#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif

#define HWLOG_TAG hw_pogopin
HWLOG_REGIST();

static struct device *g_pogopin_dev;
static struct class *g_pogopin_class;
static struct pogopin_info *g_pogopin_di;
struct blocking_notifier_head g_pogopin_evt_nb;
BLOCKING_NOTIFIER_HEAD(g_pogopin_evt_nb);

static struct pogopin_info *pogopin_get_dev_info(void)
{
	if (!g_pogopin_di) {
		hwlog_info("g_pogopin_di is null\n");
		return NULL;
	}

	return g_pogopin_di;
}

struct pogopin_sysfs_info {
	struct device_attribute attr;
	u8 name;
};

void pogopin_set_buck_boost_gpio(int value)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di || !di->buck_boost_gpio)
		return;

	gpio_set_value(di->buck_boost_gpio, value);
}

#define POGOPIN_SYSFS_FIELD(_name, n, m, store) \
{ \
	.attr = __ATTR(_name, m, pogopin_sysfs_show, store), \
	.name = POGOPIN_SYSFS_##n, \
}

#define POGOPIN_SYSFS_FIELD_RO(_name, n) \
	POGOPIN_SYSFS_FIELD(_name, n, 0664, NULL)

static ssize_t pogopin_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);

static struct pogopin_sysfs_info pogopin_sysfs_tbl[] = {
	POGOPIN_SYSFS_FIELD_RO(interface_type, INTERFACE_TYPE),
};

static struct attribute *pogopin_sysfs_attrs[ARRAY_SIZE(pogopin_sysfs_tbl) + 1];

static const struct attribute_group pogopin_sysfs_attr_group = {
	.attrs = pogopin_sysfs_attrs,
};

static void pogopin_sysfs_init_attrs(void)
{
	int i;
	int limit = ARRAY_SIZE(pogopin_sysfs_tbl);

	for (i = 0; i < limit; i++)
		pogopin_sysfs_attrs[i] = &pogopin_sysfs_tbl[i].attr.attr;

	pogopin_sysfs_attrs[limit] = NULL;
}

static struct pogopin_sysfs_info *pogopin_sysfs_field_lookup(const char *name)
{
	int i;
	int limit = ARRAY_SIZE(pogopin_sysfs_tbl);
	int len;

	if (!name) {
		hwlog_err("name is null\n");
		return NULL;
	}

	len = strlen(name);

	for (i = 0; i < limit; i++) {
		if (!strncmp(name, pogopin_sysfs_tbl[i].attr.attr.name, len))
			break;
	}

	if (i >= limit)
		return NULL;

	return &pogopin_sysfs_tbl[i];
}

static ssize_t pogopin_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct pogopin_sysfs_info *info = NULL;
	int len = 0;
	int status = pogopin_get_interface_status();

	info = pogopin_sysfs_field_lookup(attr->attr.name);
	if (!info) {
		hwlog_err("info is null\n");
		return -EINVAL;
	}

	switch (info->name) {
	case POGOPIN_SYSFS_INTERFACE_TYPE:
		len = snprintf(buf, PAGE_SIZE, "%u\n", status);
		break;
	default:
		break;
	}

	return len;
}

static int pogopin_sysfs_create_group(struct pogopin_info *di)
{
	if (!di || !di->pdev) {
		hwlog_err("di or pdev is null\n");
		return -EINVAL;
	}

	pogopin_sysfs_init_attrs();
	return sysfs_create_group(&di->pdev->dev.kobj,
		&pogopin_sysfs_attr_group);
}

static inline void pogopin_sysfs_remove_group(struct pogopin_info *di)
{
	if (!di)
		return;

	sysfs_remove_group(&di->pdev->dev.kobj, &pogopin_sysfs_attr_group);
}

static int pogopin_init_sysfs_and_class(struct pogopin_info *di)
{
	int ret;

	if (!di)
		return -EINVAL;

	ret = pogopin_sysfs_create_group(di);
	if (ret) {
		hwlog_err("cannot create group\n");
		return ret;
	}

	g_pogopin_class = class_create(THIS_MODULE, "hw_pogopin");
	if (IS_ERR(g_pogopin_class)) {
		hwlog_err("cannot create class\n");
		return -EINVAL;
	}

	if (!g_pogopin_dev) {
		g_pogopin_dev = device_create(g_pogopin_class, NULL, 0,NULL, "pogopin");
		if (!g_pogopin_dev) {
			hwlog_err("sysfs device create failed\n");
			return -EINVAL ;
		}

		ret = sysfs_create_link(&g_pogopin_dev->kobj,
					&di->pdev->dev.kobj, "pogopin_data");
		if (ret) {
			hwlog_err("sysfs link create failed\n");
			return -EINVAL;
		}
	}

	return 0;
}

int pogopin_get_interface_status(void)
{
	int pogopin_int_value;
	int typec_int_value;
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return NO_INTERFACE;

	pogopin_int_value = gpio_get_value(di->pogopin_int_gpio);
	typec_int_value = gpio_get_value(di->typec_int_gpio);

	hwlog_info("pogopin_int=%d, typec_int=%d\n",
		pogopin_int_value, typec_int_value);

	if ((pogopin_int_value == HIGH) && (typec_int_value == HIGH))
		return NO_INTERFACE;
	else if ((pogopin_int_value == HIGH) && (typec_int_value == LOW))
		return TYPEC_INTERFACE;
	else if ((pogopin_int_value == LOW) && (typec_int_value == HIGH))
		return POGOPIN_INTERFACE;
	else if ((pogopin_int_value == LOW) && (typec_int_value == LOW))
		return POGOPIN_INTERFACE;

	return NO_INTERFACE;
}
EXPORT_SYMBOL_GPL(pogopin_get_interface_status);

void pogopin_event_notify(enum pogopin_event event)
{
	hwlog_info("%s event:%d\n", __func__, event);
	blocking_notifier_call_chain(&g_pogopin_evt_nb, event, NULL);
}

void pogopin_event_notify_with_data(enum pogopin_event event, u32 data)
{
	hwlog_info("%s event:%d\n", __func__, event);
	blocking_notifier_call_chain(&g_pogopin_evt_nb, event, &data);
}

int pogopin_event_notifier_register(struct notifier_block *nb)
{
	if (!nb)
		return -EINVAL;

	return blocking_notifier_chain_register(&g_pogopin_evt_nb, nb);
}

int pogopin_event_notifier_unregister(struct notifier_block *nb)
{
	if (!nb)
		return -EINVAL;

	return blocking_notifier_chain_unregister(&g_pogopin_evt_nb, nb);
}

/* plug_in: 1 notify mirco usb mode, 0 notify type-c usb mode */
void pogopin_set_usb_mode(int plug_in)
{
	u32 id = POWER_GLINK_PROP_ID_SET_USB_MODE;

	hwlog_info("%s plug:%d\n", __func__, plug_in);
	power_glink_interface_set_property_value(id, &plug_in, GLINK_DATA_ONE);
}

bool pogopin_is_charging(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return false;

	return ((di->current_int_status == POGOPIN_INTERFACE) ||
		(di->current_int_status == POGOPIN_AND_TYPEC)) ? true : false;
}

bool pogopin_is_support(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return false;

	return (di->pogo_support == POGOPIN_SUPPORT) ? true : false;
}

bool pogopin_extcon_is_needed(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return false;

	return (di->pogopin_extcon_needed == POGOPIN_EXTCON_NEEDED) ? true : false;
}

void pogopin_5pin_set_pogo_status(enum pogo_status status)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return;

	di->pogo_insert_status = status;
}

static inline void pogopin_vbus_channel_ctrl(int gpio_num, int value)
{
	gpio_set_value(gpio_num, value);
}

static inline void pogopin_dpdm_channel_ctrl(int gpio_num, int value)
{
	gpio_set_value(gpio_num, value);
}

static inline void pogopin_otg_buckboost_ctrl(int gpio_num, int value)
{
	gpio_set_value(gpio_num, value);
}

static void pogopin_5pin_vbus_in_switch_from_typec(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return;

	hwlog_info("pogopin vbus in,power and data switch to pogopin\n");
#if IS_ENABLED(CONFIG_QCOM_FSA4480_I2C)
	fsa4480_switch_event(di->aux_switch_node, FSA_POGO_IN);
#endif
	pogopin_vbus_channel_ctrl(di->pogo_path_switch_gpio, LOW);
	pogopin_otg_buckboost_ctrl(di->buck_boost_gpio, LOW);
	pogopin_dpdm_channel_ctrl(di->usb_switch_gpio, HIGH);
}

void pogopin_5pin_otg_in_switch_from_typec(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return;

	hwlog_info("pogopin otg in, power and data switch to pogopin\n");
#if IS_ENABLED(CONFIG_QCOM_FSA4480_I2C)
	fsa4480_switch_event(di->aux_switch_node, FSA_POGO_IN);
#endif
	pogopin_vbus_channel_ctrl(di->pogo_path_switch_gpio, HIGH);
	pogopin_otg_buckboost_ctrl(di->buck_boost_gpio, HIGH);
	pogopin_dpdm_channel_ctrl(di->usb_switch_gpio, HIGH);
}

void pogopin_5pin_remove_switch_to_typec(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return;

	hwlog_info("pogopin revome, power and data switch to typec\n");
#if IS_ENABLED(CONFIG_QCOM_FSA4480_I2C)
	fsa4480_switch_event(di->aux_switch_node, FSA_POGO_OUT);
#endif
	pogopin_vbus_channel_ctrl(di->pogo_path_switch_gpio, HIGH);
	pogopin_otg_buckboost_ctrl(di->buck_boost_gpio, LOW);
	pogopin_dpdm_channel_ctrl(di->usb_switch_gpio, LOW);
}

static void pogopin_5pin_pogo_vbus_in(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return;

	hwlog_info("%s\n", __func__);
	/* set usb mode to micro usb mode */
	pogopin_set_usb_mode(POGOPIN_MICROB_CHARGER_MODE);
	pogopin_5pin_set_pogo_status(POGO_CHARGER);
	pogopin_5pin_vbus_in_switch_from_typec();
}

static void pogopin_5pin_pogo_vbus_out(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return;

	hwlog_info("%s\n", __func__);
	/* set usb mode to typec usb mode */
	pogopin_set_usb_mode(POGOPIN_TYPEC_MODE);
	pogopin_5pin_remove_switch_to_typec();
	pogopin_5pin_set_pogo_status(POGO_NONE);
}

static int pogopin_5pin_is_usbswitch_at_typec(void)
{
	int usb_switch_value;
	int buck_boost_value;
	struct pogopin_info *di = pogopin_get_dev_info();

	if (!di)
		return FALSE;

	usb_switch_value = gpio_get_value(di->usb_switch_gpio);
	buck_boost_value = gpio_get_value(di->buck_boost_gpio);
	if ((usb_switch_value == LOW) && (buck_boost_value == LOW))
		return TRUE;

	return FALSE;
}

static void pogopin_5pin_pogo_vbus_handle_work(void)
{
	struct pogopin_info *di = pogopin_get_dev_info();
	int pogopin_gpio_value;
	int buck_boost_gpio_value;
	int need_do_pogopin_switch = TRUE;
	int now_is_typec;

	if (!di)
		return;

	pogopin_gpio_value = gpio_get_value(di->pogopin_int_gpio);
	hwlog_info("pogopin_gpio_value:%d\n", pogopin_gpio_value);
	if (di->pogo_gpio_status == pogopin_gpio_value)
		return;
	di->pogo_gpio_status = pogopin_gpio_value;

	now_is_typec = pogopin_5pin_is_usbswitch_at_typec();

	buck_boost_gpio_value = gpio_get_value(di->buck_boost_gpio);
	if (buck_boost_gpio_value)
		need_do_pogopin_switch = FALSE;

	hwlog_info("buck_boost_gpio=%d\n", buck_boost_gpio_value);
	if (need_do_pogopin_switch == FALSE)
		return;

	if (pogopin_gpio_value == LOW) {
		di->current_int_status = pogopin_get_interface_status();
		pogopin_5pin_pogo_vbus_in();
	} else if ((pogopin_gpio_value == HIGH) && !now_is_typec) {
		pogopin_5pin_pogo_vbus_out();
		di->current_int_status = pogopin_get_interface_status();
		pogopin_event_notify(POGOPIN_CHARGER_OUT_COMPLETE);
	}
}

static irqreturn_t pogopin_int_handler(int irq, void *_di)
{
	struct pogopin_info *di = _di;

	if (!di) {
		hwlog_err("di is null\n");
		return IRQ_HANDLED;
	}

	disable_irq_wake(di->pogopin_int_irq);
	__pm_wakeup_event(di->wakelock, POGOPIN_DELAYED_5000MS);
	schedule_delayed_work(&di->work, POGOPIN_DELAYED_50MS);
	enable_irq_wake(di->pogopin_int_irq);
	return IRQ_HANDLED;
}

static void pogopin_vbus_in_work(struct work_struct *work)
{
	pogopin_5pin_pogo_vbus_handle_work();
}

static int pogopin_request_irq(struct pogopin_info *di)
{
	int ret;

	if (!di)
		return -EINVAL;

	di->pogopin_int_irq = gpio_to_irq(di->pogopin_int_gpio);
	if (di->pogopin_int_irq < 0) {
		hwlog_err("gpio map to irq fail\n");
		return -EINVAL;
	}
	ret = request_irq(di->pogopin_int_irq, pogopin_int_handler,
		IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING, "pogopin_int_irq", di);
	if (ret) {
		hwlog_err("gpio irq request fail\n");
		di->pogopin_int_irq = -1;
		return ret;
	}
	enable_irq_wake(di->pogopin_int_irq);
	return ret;
}

static int popogpin_set_gpio_direction_irq(struct pogopin_info *di)
{
	int ret;

	if (!di)
		return -EINVAL;

	ret = gpio_direction_output(di->pogo_path_switch_gpio, 1);
	if (ret < 0) {
		hwlog_err("gpio set output fail\n");
		return ret;
	}

	ret = gpio_direction_input(di->pogopin_int_gpio);
	if (ret < 0) {
		hwlog_err("gpio set input fail\n");
		return ret;
	}

	ret = gpio_direction_output(di->usb_switch_gpio, 0);
	if (ret < 0) {
		hwlog_err("gpio set output fail\n");
		return ret;
	}

	ret = gpio_direction_output(di->buck_boost_gpio, 0);
	if (ret < 0) {
		hwlog_err("gpio set output fail\n");
		return ret;
	}

	ret = gpio_direction_input(di->typec_int_gpio);
	if (ret < 0) {
		hwlog_err("gpio set input fail\n");
		return ret;
	}
	msleep(5); /* sleep 5 ms */
	return pogopin_request_irq(di);
}

static void pogopin_free_irqs(struct pogopin_info *di)
{
	if (!di)
		return;

	free_irq(di->pogopin_int_irq, di);
}

static int pogopin_parse_gpio_dts(struct pogopin_info *di,
	struct device_node *np)
{
	int ret = -EINVAL;

	if (!di)
		return -EINVAL;

	di->pogo_path_switch_gpio = of_get_named_gpio(np,
		"pogo_path_switch_gpio", 0);
	hwlog_info("pogo_path_switch_gpio=%d\n", di->pogo_path_switch_gpio);

	if (!gpio_is_valid(di->pogo_path_switch_gpio)) {
		hwlog_err("gpio is not valid\n");
		return ret;
	}

	di->pogopin_int_gpio = of_get_named_gpio(np, "pogopin_int_gpio", 0);
	hwlog_info("pogopin_int_gpio=%d\n", di->pogopin_int_gpio);
	if (!gpio_is_valid(di->pogopin_int_gpio)) {
		hwlog_err("gpio is not valid\n");
		return ret;
	}

	di->usb_switch_gpio = of_get_named_gpio(np,	"usb_switch_gpio", 0);
	hwlog_info("usb_switch_gpio=%d\n", di->usb_switch_gpio);
	if (!gpio_is_valid(di->usb_switch_gpio)) {
		hwlog_err("gpio is not valid\n");
		return ret;
	}

	di->buck_boost_gpio = of_get_named_gpio(np,"buck_boost_gpio", 0);
	hwlog_info("buck_boost_gpio=%d\n", di->buck_boost_gpio);
	if (!gpio_is_valid(di->buck_boost_gpio)) {
		hwlog_err("gpio is not valid\n");
		return ret;
	}

	di->typec_int_gpio = of_get_named_gpio(np, "typec_int_gpio", 0);
	hwlog_info("typec_int_gpio=%d\n", di->typec_int_gpio);
	if (!gpio_is_valid(di->typec_int_gpio)) {
		hwlog_err("gpio is not valid\n");
		return ret;
	}

	return 0;
}

static int pogopin_request_common_gpio(struct pogopin_info *di)
{
	int ret;

	if (!di)
		return -EINVAL;

	ret = gpio_request(di->pogo_path_switch_gpio, "pogo_path_switch");
	if (ret) {
		hwlog_err("gpio request fail\n");
		goto fail_pogo_path_switch_gpio;
	}

	ret = gpio_request(di->pogopin_int_gpio, "pogopin_int");
	if (ret) {
		hwlog_err("gpio request fail\n");
		goto fail_pogopin_int_gpio;
	}

	return 0;

fail_pogopin_int_gpio:
	gpio_free(di->pogo_path_switch_gpio);
fail_pogo_path_switch_gpio:
	return ret;
}

static void pogopin_free_common_gpio(struct pogopin_info *di)
{
	if (!di)
		return;

	gpio_free(di->pogopin_int_gpio);
	gpio_free(di->pogo_path_switch_gpio);
}

static int pogopin_request_cust_gpio(struct pogopin_info *di)
{
	int ret;

	if (!di)
		return -EINVAL;

	ret = gpio_request(di->typec_int_gpio, "typec_int");
	if (ret) {
		hwlog_err("gpio request fail\n");
		return ret;
	}

	ret = gpio_request(di->usb_switch_gpio, "usb_switch");
	if (ret) {
		hwlog_err("gpio request fail\n");
		goto fail_usb_switch_gpio;

		ret = gpio_request(di->buck_boost_gpio, "buck_boost");
		if (ret) {
			hwlog_err("gpio request fail\n");
			goto fail_buck_boost_gpio;
		}
	}

	return 0;

fail_buck_boost_gpio:
	gpio_free(di->usb_switch_gpio);
fail_usb_switch_gpio:
	gpio_free(di->typec_int_gpio);
	return ret;
}

static int pogopin_parse_and_request_gpios(struct pogopin_info *di,
	struct device_node *np)
{
	int ret;

	if (!di)
		return -EINVAL;

	ret = pogopin_parse_gpio_dts(di, np);
	if (ret != 0)
		return ret;

	ret = pogopin_request_common_gpio(di);
	if (ret != 0)
		return ret;

	ret = pogopin_request_cust_gpio(di);
	if (ret != 0)
		goto fail_request_gpio;

	return 0;

fail_request_gpio:
	pogopin_free_common_gpio(di);
	return ret;
}

static void pogopin_free_gpios(struct pogopin_info *di)
{
	if (!di)
		return;

	pogopin_free_common_gpio(di);
	gpio_free(di->buck_boost_gpio);
	gpio_free(di->usb_switch_gpio);
	gpio_free(di->typec_int_gpio);
}

static int pogopin_init_gpios(struct pogopin_info *di, struct device_node *np)
{
	int ret;

	if (!di)
		return -EINVAL;

	ret = pogopin_parse_and_request_gpios(di, np);
	if (ret)
		return ret;

	ret = popogpin_set_gpio_direction_irq(di);
	if (ret)
		goto fail_request_gpio;

	return 0;

fail_request_gpio:
	pogopin_free_gpios(di);
	return ret;
}

static int pogopin_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct device_node *np = NULL;
	struct device *dev = NULL;
	struct pogopin_info *di = NULL;
	const char *phandle = "qcom,dp-aux-switch";
	u32 value = 0;

	hwlog_info("[%s] enter\n", __func__);
	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	platform_set_drvdata(pdev, di);
	g_pogopin_di = di;
	di->pdev = pdev;
	dev = &pdev->dev;
	np = dev->of_node;

	di->pogo_gpio_status = -1;
	(void)power_pinctrl_config(&(pdev->dev), "pinctrl-names", 1);
	di->aux_switch_node = of_parse_phandle(di->pdev->dev.of_node,
		phandle, 0);
	if (!di->aux_switch_node) {
		hwlog_err("cannot parse %s handle\n", phandle);
		return -EINVAL;
	}

	di->wakelock = power_wakeup_source_register(&pdev->dev, "pogopin_charger_wakelock");
	if (!di->wakelock) {
		ret = -EINVAL;
		goto fail_register_wakeup_source;
	}

	INIT_DELAYED_WORK(&di->work, pogopin_vbus_in_work);

	ret = pogopin_init_gpios(di, np);
	if (ret)
		goto fail_init_gpio;

	di->current_int_status = pogopin_get_interface_status();
	pogopin_int_handler(di->pogopin_int_irq, di);

	ret = pogopin_init_sysfs_and_class(di);
	if (ret)
		goto fail_create_sysfs;

	ret = of_property_read_u32(np, "huawei,pogopin_support", &value);
	if ((!ret) && (value == 1))
		di->pogo_support  = POGOPIN_SUPPORT;
	 else
		di->pogo_support  = POGOPIN_NOT_SUPPORT;

	ret = of_property_read_u32(np, "huawei,pogopin_extcon", &value);
	if ((!ret) && (value == 1))
		di->pogopin_extcon_needed  = POGOPIN_EXTCON_NEEDED;
	else
		di->pogopin_extcon_needed  = POGOPIN_EXTCON_NOT_NEEDED;

	hwlog_info("[%s] end\n", __func__);
	return 0;

fail_create_sysfs:
	pogopin_free_irqs(di);
	pogopin_free_gpios(di);
	power_wakeup_source_unregister(di->wakelock);
fail_register_wakeup_source:
fail_init_gpio:
	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, di);
	g_pogopin_di = NULL;
	return ret;
}

static int pogopin_remove(struct platform_device *pdev)
{
	struct pogopin_info *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	pogopin_free_irqs(di);
	pogopin_free_gpios(di);
	platform_set_drvdata(pdev, NULL);
	devm_kfree(&pdev->dev, di);
	g_pogopin_di = NULL;
	return 0;
}

static const struct of_device_id pogopin_match_table[] = {
	{
		.compatible = "huawei,pogopin",
		.data = NULL,
	},
	{},
};

static struct platform_driver pogopin_driver = {
	.probe = pogopin_probe,
	.remove = pogopin_remove,
	.driver = {
		.name = "huawei,pogopin",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(pogopin_match_table),
	},
};

static int __init pogopin_init(void)
{
	return platform_driver_register(&pogopin_driver);
}

static void __exit pogopin_exit(void)
{
	platform_driver_unregister(&pogopin_driver);
}

late_initcall(pogopin_init);
module_exit(pogopin_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei pogopin module driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
