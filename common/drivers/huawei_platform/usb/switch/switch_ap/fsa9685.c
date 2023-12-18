/*
 * fsa9685.c
 *
 * driver file for fsa9685 chip
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

#include <asm/irq.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <linux/param.h>
#include <linux/platform_device.h>
#include <linux/pm_wakeup.h>
#include <linux/power_supply.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/uaccess.h>
#include <linux/workqueue.h>
#ifdef CONFIG_HDMI_K3
#include <../video/k3/hdmi/k3_hdmi.h>
#endif
#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#endif
#include <huawei_platform/usb/hw_pd_dev.h>
#ifdef CONFIG_BOOST_5V
#include <chipset_common/hwpower/hardware_ic/boost_5v.h>
#endif
#include <hwmanufac/dev_detect/dev_detect.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/adapter/adapter_test.h>
#include <chipset_common/hwpower/common_module/power_devices_info.h>
#include <chipset_common/hwpower/common_module/power_gpio.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <chipset_common/hwusb/hw_usb_rwswitch.h>
#include <huawei_platform/power/direct_charger/direct_charger.h>
#include <huawei_platform/power/huawei_charger_adaptor.h>
#include <huawei_platform/power/huawei_charger_common.h>
#include <huawei_platform/usb/switch/fsa9685.h>
#include <huawei_platform/usb/switch/switch_chip_common.h>
#include "fsa9685_bc12.h"
#include "fsa9685_accp.h"
#include "usbswitch_fsa9685.h"
#include "fsa9685_reg.h"
#include "switch_chip_i2c.h"
#include "switch_interface.h"

#define HWLOG_TAG fsa9685_chip
HWLOG_REGIST();

static struct fsa9685_device_info *g_fsa9685_dev;

static int g_gpio = -1;
static int g_switch_gpio = -1;

static bool fsa9685_get_chip_init_status(void)
{
	return (g_fsa9685_dev != NULL);
}

static struct switch_interface_info_ops fsa9685_info_ops = {
	.chip_init_status = fsa9685_get_chip_init_status,
};

struct fsa9685_device_info *fsa9685_get_dev_info(void)
{
	if (!g_fsa9685_dev)
		hwlog_err("dev_info is null\n");

	return g_fsa9685_dev;
}

int fsa9685_get_gpio(void)
{
	return g_gpio;
}

void fsa9685_usb_switch_wake_lock(struct fsa9685_device_info *di)
{
	if (!di->usb_switch_lock.active) {
		__pm_stay_awake(&di->usb_switch_lock);
		hwlog_info("usb_switch_lock lock\n");
	}
}

void fsa9685_usb_switch_wake_unlock(struct fsa9685_device_info *di)
{
	if (di->usb_switch_lock.active) {
		__pm_relax(&di->usb_switch_lock);
		hwlog_info("usb_switch_lock unlock\n");
	}
}

static int fsa9685_get_device_id(struct fsa9685_device_info *di)
{
	int id;
	int vendor_id;
	int version_id;
	int device_id;

	id = switch_read_reg(di->client, FSA9685_REG_DEVICE_ID);
	if (id < 0)
		return -1;

	vendor_id = (id & FSA9685_REG_DEVICE_ID_VENDOR_ID_MASK) >>
		FSA9685_REG_DEVICE_ID_VENDOR_ID_SHIFT;
	version_id = (id & FSA9685_REG_DEVICE_ID_VERSION_ID_MASK) >>
		FSA9685_REG_DEVICE_ID_VERSION_ID_SHIFT;

	hwlog_info("get_device_id [%x]=%x,%d,%d\n", FSA9685_REG_DEVICE_ID,
		id, vendor_id, version_id);

	if (vendor_id == FSA9685_VENDOR_ID) {
		if (version_id == FSA9683_VERSION_ID) {
			hwlog_info("find fsa9683\n");
			device_id = USBSWITCH_ID_FSA9683;
		} else if (version_id == FSA9688_VERSION_ID) {
			hwlog_info("find fsa9688\n");
			device_id = USBSWITCH_ID_FSA9688;
		} else if (version_id == FSA9688C_VERSION_ID) {
			hwlog_info("find fsa9688c\n");
			device_id = USBSWITCH_ID_FSA9688C;
		} else {
			hwlog_err("use default id (fsa9685)\n");
			device_id = USBSWITCH_ID_FSA9685;
		}
	} else {
		hwlog_err("fsa9685 not find\n");
		device_id = -EINVAL;
	}

	return device_id;
}

int fsa9685_is_support_fcp(struct fsa9685_device_info *di)
{
	if (!di->fcp_support)
		return -1;

	return 0;
}

static void fsa9685_detach_work(struct work_struct *work)
{
	return usbswitch_fsa9685_detach_work();
}

static irqreturn_t fsa9685_irq_handler(int irq, void *dev_id)
{
	int gpio_value;
	struct fsa9685_device_info *di = fsa9685_get_dev_info();

	if (!di || !di->client)
		return IRQ_HANDLED;

	if (!di->pd_support)
		fsa9685_usb_switch_wake_lock(di);

	gpio_value = gpio_get_value(g_gpio);
	if (gpio_value == 1) /* 1:irq gpio is high */
		hwlog_err("%s: intb high when interrupt occured\n", __func__);

	schedule_work(&di->intb_work);

	hwlog_info("%s:end gpio_value=%d\n", __func__, gpio_value);
	return IRQ_HANDLED;
}

static void fsa9685_disable_fcp_interrupt(struct fsa9685_device_info *di)
{
	int ret = 0;

	if (!fsa9685_is_support_fcp(di) &&
		((switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK1) != FSA9685_REG_ALLMASK) ||
		(switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK2) != FSA9685_REG_ALLMASK))) {
		hwlog_info("disable fcp interrrupt again!!\n");
		ret |= switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2,
			FSA9685_ACCP_OSC_ENABLE, FSA9685_ACCP_OSC_ENABLE);
		ret |= switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2,
			di->dcd_timeout_force_enable, FSA9685_DCD_TIME_OUT_MASK);
		ret |= switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK1,
			FSA9685_REG_ALLMASK);
		ret |= switch_write_reg(di->client, FSA9685_REG_ACCP_INTERRUPT_MASK2,
			FSA9685_REG_ALLMASK);
		hwlog_info("%s: read ACCP interrupt,reg[0x59]=0x%x,reg[0x5A]=0x%x\n", __func__,
			switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT1),
			switch_read_reg(di->client, FSA9685_REG_ACCP_INTERRUPT2));
		if (ret < 0)
			hwlog_err("accp interrupt mask write failed\n");
	}
}

static void fsa9685_handle_attach_interrupt(struct fsa9685_device_info *di,
	int reg_intrpt, int *id_valid_status, int *pedestal_attach)
{
	int reg_dev_type1, reg_dev_type2, reg_dev_type3;

	if (!(reg_intrpt & FSA9685_ATTACH))
		return;

	hwlog_info("%s: FSA9685_ATTACH\n", __func__);
	reg_dev_type1 = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_1);
	reg_dev_type2 = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_2);
	reg_dev_type3 = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_3);
	hwlog_info("%s: reg_dev_type1=0x%X, reg_dev_type2=0x%X, reg_dev_type3= 0x%X\n",
		__func__, reg_dev_type1, reg_dev_type2, reg_dev_type3);
	if (reg_dev_type1 & FSA9685_FC_USB_DETECTED)
		hwlog_info("%s: FSA9685_FC_USB_DETECTED\n", __func__);
	if (reg_dev_type1 & FSA9685_USB_DETECTED) {
		hwlog_info("%s: FSA9685_USB_DETECTED\n", __func__);
		fsa9685_update_nstd_chg_type(CHARGER_TYPE_USB);
	}
	if (reg_dev_type1 & FSA9685_UART_DETECTED)
		hwlog_info("%s: FSA9685_UART_DETECTED\n", __func__);
	if (reg_dev_type1 & FSA9685_CDP_DETECTED) {
		hwlog_info("%s: FSA9685_CDP_DETECTED\n", __func__);
		fsa9685_update_nstd_chg_type(CHARGER_TYPE_BC_USB);
	}
	if (reg_dev_type1 & FSA9685_DCP_DETECTED) {
		hwlog_info("%s: FSA9685_DCP_DETECTED\n", __func__);
		fsa9685_update_nstd_chg_type(CHARGER_TYPE_STANDARD);
	}
	if (reg_dev_type1 & FSA9685_DEVICE_TYPE1_UNAVAILABLE) {
		*id_valid_status = ID_INVALID;
		hwlog_info("%s: FSA9685_DEVICE_TYPE1_UNAVAILABLE_DETECTED\n", __func__);
	}
	if (reg_dev_type2 & FSA9685_JIG_UART)
		hwlog_info("%s: FSA9685_JIG_UART\n", __func__);
	if (reg_dev_type2 & FSA9685_DEVICE_TYPE2_UNAVAILABLE) {
		*id_valid_status = ID_INVALID;
		hwlog_info("%s: FSA9685_DEVICE_TYPE2_UNAVAILABLE_DETECTED\n", __func__);
	}
	if (reg_dev_type3 & FSA9685_CUSTOMER_ACCESSORY7) {
		usbswitch_fsa9685_manual_switch(SWITCH_CHIP_USB1_ID_TO_IDBYPASS);
		hwlog_info("%s:Enter FSA9685_CUSTOMER_ACCESSORY7\n", __func__);
	}
	if (reg_dev_type3 & FSA9685_CUSTOMER_ACCESSORY5) {
		hwlog_info("%s: FSA9685_CUSTOMER_ACCESSORY5, 365K\n", __func__);
		*pedestal_attach = 1;
	}
	if (reg_dev_type3 & FSA9685_FM8_ACCESSORY) {
		hwlog_info("%s: FSA9685_FM8_DETECTED\n", __func__);
		usbswitch_fsa9685_manual_switch(SWITCH_CHIP_USB1_ID_TO_IDBYPASS);
	}
	if (reg_dev_type3 & FSA9685_DEVICE_TYPE3_UNAVAILABLE) {
		*id_valid_status = ID_INVALID;
		if (reg_intrpt & FSA9685_VBUS_CHANGE)
			usbswitch_fsa9685_manual_switch(SWITCH_CHIP_USB1_ID_TO_IDBYPASS);
		hwlog_info("%s: FSA9685_DEVICE_TYPE3_UNAVAILABLE_DETECTED\n", __func__);
	}
}

static int fsa9685_handle_detach_interrupt(struct fsa9685_device_info *di,
	int reg_intrpt, int *pedestal_attach)
{
	int ret, reg_ctl, reg_dev_type2;

	if (!(reg_intrpt & FSA9685_DETACH))
		return 0;

	hwlog_info("%s: FSA9685_DETACH\n", __func__);
	/* check control register, if manual switch, reset to auto switch */
	reg_ctl = switch_read_reg(di->client, FSA9685_REG_CONTROL);
	reg_dev_type2 = switch_read_reg(di->client, FSA9685_REG_DEVICE_TYPE_2);
	hwlog_info("%s: reg_ctl=0x%x\n", __func__, reg_ctl);
	if (reg_ctl < 0) {
		hwlog_err("%s: read FSA9685_REG_CONTROL error!!! reg_ctl=%d\n",
			__func__, reg_ctl);
		return reg_ctl;
	}
	if ((reg_ctl & FSA9685_MANUAL_SW) == 0) {
		reg_ctl |= FSA9685_MANUAL_SW;
		ret = switch_write_reg(di->client, FSA9685_REG_CONTROL, reg_ctl);
		if (ret < 0) {
			hwlog_err("%s: write FSA9685_REG_CONTROL error!!!\n", __func__);
			return ret;
		}
	}
	if (*pedestal_attach == 1) {
		hwlog_info("%s: FSA9685_CUSTOMER_ACCESSORY5_DETACH\n", __func__);
		*pedestal_attach = 0;
	}
	if (reg_dev_type2 & FSA9685_JIG_UART)
		hwlog_info("%s: FSA9685_JIG_UART\n", __func__);

	return 0;
}

static void fsa9685_handle_id_event(struct fsa9685_device_info *di,
	int id_valid_status, int *invalid_times, int reg_intrpt)
{
	if ((id_valid_status == ID_INVALID) &&
		(reg_intrpt & (FSA9685_ATTACH | FSA9685_RESERVED_ATTACH))) {
		*invalid_times++;
		hwlog_info("%s: invalid time:%d reset fsa9685 work\n", __func__, *invalid_times);

		if (*invalid_times < MAX_DETECTION_TIMES) {
			hwlog_info("%s: start schedule delayed work\n", __func__);
			schedule_delayed_work(&di->detach_delayed_work, msecs_to_jiffies(0));
		} else {
			*invalid_times = 0;
		}
	} else if ((id_valid_status == ID_INVALID) &&
		(reg_intrpt & (FSA9685_ATTACH | FSA9685_RESERVED_ATTACH))) {
		*invalid_times = 0;
	}
}

static void fsa9685_handle_change_event(struct fsa9685_device_info *di,
	int reg_intrpt)
{
	int reg_adc;

	if (reg_intrpt & FSA9685_VBUS_CHANGE)
		hwlog_info("%s: FSA9685_VBUS_CHANGE\n", __func__);

	if (reg_intrpt & FSA9685_ADC_CHANGE) {
		reg_adc = switch_read_reg(di->client, FSA9685_REG_ADC);
		hwlog_info("%s: FSA9685_ADC_CHANGE. reg_adc=%d\n", __func__, reg_adc);
		if (reg_adc < 0)
			hwlog_err("%s: read FSA9685_ADC_CHANGE error!!! reg_adc=%d\n",
				__func__, reg_adc);
	}
}

static void fsa9685_intb_work(struct work_struct *work)
{
	int reg_intrpt, vbus_status, ret;
	int id_valid_status = ID_VALID;
	static int invalid_times;
	static int pedestal_attach;
	struct fsa9685_device_info *di = container_of(work, struct fsa9685_device_info,
		intb_work);

	if (!di || !di->client)
		return;

	reg_intrpt = switch_read_reg(di->client, FSA9685_REG_INTERRUPT);
	vbus_status = switch_read_reg(di->client, FSA9685_REG_VBUS_STATUS);
	hwlog_info("%s: reg_intrpt=0x%x, vbus_status=0x%x\n", __func__, reg_intrpt,
		vbus_status);

	/* if support fcp ,disable fcp interrupt */
	fsa9685_disable_fcp_interrupt(di);
	if (unlikely(reg_intrpt < 0)) {
		hwlog_err("%s: read FSA9685_REG_INTERRUPT error!!!\n", __func__);
	} else if (unlikely(reg_intrpt == 0)) {
		hwlog_err("%s: read FSA9685_REG_INTERRUPT, and no intr!!!\n", __func__);
	} else {
		fsa9685_handle_attach_interrupt(di, reg_intrpt, &id_valid_status, &pedestal_attach);
		if (reg_intrpt & FSA9685_RESERVED_ATTACH) {
			hwlog_info("%s: FSA9685_RESERVED_ATTACH\n", __func__);
			id_valid_status = ID_INVALID;
			if (reg_intrpt & FSA9685_VBUS_CHANGE)
				usbswitch_fsa9685_manual_switch(SWITCH_CHIP_USB1_ID_TO_IDBYPASS);
		}

		ret = fsa9685_handle_detach_interrupt(di, reg_intrpt, &pedestal_attach);
		if (!ret)
			goto OUT;

		fsa9685_handle_change_event(di, reg_intrpt);
	}
	fsa9685_handle_id_event(di, id_valid_status, &invalid_times, reg_intrpt);

OUT:
	if (di->pd_support) {
	} else if (invalid_times == 0) {
		fsa9685_usb_switch_wake_unlock(di);
	}

	hwlog_info("%s: ------end.\n", __func__);
	return;
}

#ifdef CONFIG_OF
static const struct of_device_id switch_fsa9685_ids[] = {
	{ .compatible = "huawei,fairchild_fsa9685" },
	{ .compatible = "huawei,fairchild_fsa9683" },
	{ .compatible = "huawei,nxp_cbtl9689" },
	{ },
};
MODULE_DEVICE_TABLE(of, switch_fsa9685_ids);
#endif /* CONFIG_OF */

static int fsa9685_parse_dts(struct device_node* np, struct fsa9685_device_info *di)
{
	int ret;

	if (!power_gpio_config_output(np, "switch_gpio", "switch_gpio_init",
		&g_switch_gpio, 1)) {
		gpio_set_value(g_switch_gpio, 1);
		ret = gpio_get_value(g_switch_gpio);
		hwlog_info("g_switch_gpio get value = %d\n", ret);
	}

	ret = of_property_read_u32(np, "fcp_support", &di->fcp_support);
	if (ret) {
		di->fcp_support = 0;
		hwlog_err("error: fcp_support dts read failed!\n");
	}
	hwlog_info("fcp_support=%d\n", di->fcp_support);

	ret = of_property_read_u32(np, "scp_support", &di->scp_support);
	if (ret) {
		di->scp_support = 0;
		hwlog_err("error: scp_support dts read failed!\n");
	}
	hwlog_info("scp_support=%d\n", di->scp_support);

	ret = of_property_read_u32(np, "two-switch-flag", &di->two_switch_flag);
	if (ret) {
		di->two_switch_flag = 0;
		hwlog_err("error: two-switch-flag dts read failed!\n");
	}
	hwlog_info("two-switch-flag=%d\n", di->two_switch_flag);

	ret = of_property_read_u32(of_find_compatible_node(NULL, NULL, "huawei,charger"),
		"pd_support", &di->pd_support);
	if (ret) {
		di->pd_support = 0;
		hwlog_err("error: pd_support dts read failed!\n");
	}
	hwlog_info("pd_support=%d\n", di->pd_support);

	ret = of_property_read_u32(np, "dcd_timeout_force_enable", &di->dcd_timeout_force_enable);
	if (ret) {
		di->dcd_timeout_force_enable = 0;
		hwlog_err("error: dcd_timeout_force_enable dts read failed!\n");
	}
	hwlog_info("dcd_timeout_force_enable=%d\n", di->dcd_timeout_force_enable);

	ret = of_property_read_u32(np, "power_by_5v", &di->power_by_5v);
	if (ret)
		di->power_by_5v = 0;

	hwlog_info("power_by_5v=%d\n", di->power_by_5v);

	return 0;
}

static int fsa9685_register_init(struct fsa9685_device_info *di)
{
	struct power_devices_info_data *power_dev_info = NULL;

	switch_interface_charger_ops_register(fas9685_get_accp_ops());
	switch_interface_bc12_ops_register(fas9685_get_bc12_ops());
	switch_interface_control_ops_register(usbswitch_fsa9685_get_control_ops());
	switch_interface_info_ops_register(&fsa9685_info_ops);

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
	/* detect current device successful, set the flag as present */
	set_hw_dev_flag(DEV_I2C_USB_SWITCH);
#endif /* CONFIG_HUAWEI_HW_DEV_DCT */

	power_dev_info = power_devices_info_register();
	if (power_dev_info) {
		power_dev_info->dev_name = di->dev->driver->name;
		power_dev_info->dev_id = di->device_id;
		power_dev_info->ver_id = 0;
	}

	return 0;
}

static int fsa9685_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct fsa9685_device_info *di = NULL;
	struct device_node *node = NULL;
	int ret = -ERR_NO_DEV;
	int reg_ctl;
	int gpio_value;

	hwlog_info("fsa9685 probe begin\n");

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
		hwlog_err("i2c_check failed\n");
		goto fail_i2c_check_functionality;
	}

	if (g_fsa9685_dev) {
		hwlog_err("fsa9685 chip is already detected\n");
		return ret;
	}

	di = devm_kzalloc(&client->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &client->dev;
	node = di->dev->of_node;
	di->client = client;
	i2c_set_clientdata(client, di);

	/* device idendify */
	di->device_id = fsa9685_get_device_id(di);
	if (di->device_id < 0)
		goto fail_i2c_check_functionality;

	atomic_set(&di->chg_type_det, 0);
	ret = fsa9685_parse_dts(node, di);
	if (ret) {
		hwlog_err("parse dts failed\n");
		goto fail_i2c_check_functionality;
	}
	/* init lock */
	mutex_init(&di->accp_detect_lock);
	mutex_init(&di->accp_adaptor_reg_lock);
	wakeup_source_init(&di->usb_switch_lock, "usb_switch_wakelock");

	/* init work */
	INIT_DELAYED_WORK(&di->detach_delayed_work, fsa9685_detach_work);
	INIT_DELAYED_WORK(&di->update_type_work, fsa9685_update_type_work);
	INIT_DELAYED_WORK(&di->chg_det_work, fsa9685_chg_det_work);
	INIT_WORK(&di->intb_work, fsa9685_intb_work);

	g_gpio = of_get_named_gpio(node, "fairchild_fsa9685,gpio-intb", 0);
	if (g_gpio < 0) {
		hwlog_err("of_get_named_gpio error\n");
		ret = -EIO;
		goto fail_free_wakelock;
	}
	hwlog_info("get gpio-intb:%d\n", g_gpio);

	client->irq = gpio_to_irq(g_gpio);
	if (client->irq < 0) {
		hwlog_err("gpio_to_irq error\n");
		ret = -EIO;
		goto fail_free_wakelock;
	}

	ret = gpio_request(g_gpio, "fsa9685_int");
	if (ret < 0) {
		hwlog_err("gpio_request error\n");
		goto fail_free_wakelock;
	}

	ret = gpio_direction_input(g_gpio);
	if (ret < 0) {
		hwlog_err("gpio_direction_input error\n");
		goto fail_free_int_gpio;
	}

	ret |= switch_write_reg_mask(di->client, FSA9685_REG_CONTROL2, 0,
		FSA9685_DCD_TIME_OUT_MASK);
	if (ret < 0)
		hwlog_err("write FSA9685_REG_CONTROL2 error\n");
	ret |= switch_write_reg_mask(di->client, FSA9685_REG_INTERRUPT_MASK,
		FSA9685_DEVICE_CHANGE, FSA9685_DEVICE_CHANGE);
	if (ret < 0)
		hwlog_err("write FSA9685_REG_INTERRUPT_MASK error\n");

	/* interrupt register */
	ret = request_irq(client->irq, fsa9685_irq_handler,
		IRQF_NO_SUSPEND | IRQF_TRIGGER_FALLING, "fsa9685_int", client);
	if (ret < 0) {
		hwlog_err("request_irq error\n");
		goto fail_free_int_gpio;
	}

	fsa9685_disable_accp_intr(di);

	/* clear INT MASK */
	reg_ctl = switch_read_reg(di->client, FSA9685_REG_CONTROL);
	if (reg_ctl < 0) {
		hwlog_err("read FSA9685_REG_CONTROL error\n");
		ret = -EIO;
		goto fail_free_int_irq;
	}

	reg_ctl &= (~FSA9685_INT_MASK);
	ret = switch_write_reg(di->client, FSA9685_REG_CONTROL, reg_ctl);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_CONTROL error\n");
		goto fail_free_int_irq;
	}

	ret = switch_write_reg(di->client, FSA9685_REG_DCD,
		FSA9685_REG_DCD_STATUS_INIT_VAL);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_DCD error\n");
		goto fail_free_int_irq;
	}

	gpio_value = gpio_get_value(g_gpio);
	if (gpio_value == 0) {
		hwlog_info("get gpio value 0\n");
		schedule_work(&di->intb_work);
	}

	ret = fsa9685_register_init(di);
	if (ret < 0)
		goto fail_free_int_irq;

	g_fsa9685_dev = di;

	hwlog_info("probe end\n");
	return 0;

fail_free_int_irq:
	free_irq(client->irq, client);
fail_free_int_gpio:
	gpio_free(g_gpio);
fail_free_wakelock:
	wakeup_source_trash(&di->usb_switch_lock);
fail_i2c_check_functionality:
	g_fsa9685_dev = NULL;
	return ret;
}

static int fsa9685_remove(struct i2c_client *client)
{
	struct fsa9685_device_info *di = i2c_get_clientdata(client);

	free_irq(client->irq, client);
	gpio_free(g_gpio);
	if (di) {
		wakeup_source_trash(&di->usb_switch_lock);
		cancel_delayed_work_sync(&di->chg_det_work);
		cancel_delayed_work_sync(&di->update_type_work);
	}

	return 0;
}

static void fsa9685_shutdown(struct i2c_client *client)
{
#ifdef CONFIG_BOOST_5V
	struct fsa9685_device_info *di = i2c_get_clientdata(client);

	if (!di)
		return;

	if (di->power_by_5v) {
		boost_5v_enable(DISABLE, BOOST_CTRL_FCP);
		dc_set_bst_ctrl(DISABLE);
	}
#endif /* CONFIG_BOOST_5V */
}

static int fsa9685_suspend(struct device *dev)
{
	hwlog_info("%s enter\n", __func__);
	return 0;
}

static int fsa9685_resume(struct device *dev)
{
	hwlog_info("%s enter\n", __func__);
	return 0;
}

static SIMPLE_DEV_PM_OPS(fsa9685_pm_ops, fsa9685_suspend, fsa9685_resume);

static const struct i2c_device_id fsa9685_i2c_id[] = {
	{ "fsa9685", 0 },
	{}
};

static struct i2c_driver fsa9685_i2c_driver = {
	.probe = fsa9685_probe,
	.remove = fsa9685_remove,
	.shutdown = fsa9685_shutdown,
	.id_table = fsa9685_i2c_id,
	.driver = {
		.name = "fsa9685",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(switch_fsa9685_ids),
		.pm = &fsa9685_pm_ops,
	},
};

static __init int fsa9685_i2c_init(void)
{
	return i2c_add_driver(&fsa9685_i2c_driver);
}

static __exit void fsa9685_i2c_exit(void)
{
	i2c_del_driver(&fsa9685_i2c_driver);
}

device_initcall_sync(fsa9685_i2c_init);
module_exit(fsa9685_i2c_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei fsa9685 chip driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
