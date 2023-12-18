/*
 * rt8979.c
 *
 * driver file for rt8979 chip
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
#include <huawei_platform/usb/switch/switch_chip_common.h>
#include "rt8979.h"
#include "rt8979_reg.h"
#include "rt8979_bc12.h"
#include "rt8979_accp.h"
#include "rt8979_osc.h"
#include "usbswitch_rt8979.h"
#include "switch_chip_i2c.h"
#include "switch_interface.h"

#define HWLOG_TAG rt8979_chip
HWLOG_REGIST();

static struct rt8979_device_info *g_rt8979_dev;

static int g_switch_gpio = -1;

static bool rt8979_get_chip_init_status(void)
{
	return (g_rt8979_dev != NULL);
}

static struct switch_interface_info_ops rt8979_info_ops = {
	.chip_init_status = rt8979_get_chip_init_status,
};

struct rt8979_device_info *rt8979_get_dev_info(void)
{
	if (!g_rt8979_dev)
		hwlog_err("dev_info is null\n");

	return g_rt8979_dev;
}

static int rt8979_get_device_id(struct rt8979_device_info *di)
{
	int id;
	int vendor_id;
	int version_id;
	int device_id;

	id = switch_read_reg(di->client, RT8979_REG_DEVICE_ID);
	if (id < 0)
		return -1;

	vendor_id = (id & RT8979_REG_DEVICE_ID_VENDOR_ID_MASK) >>
		RT8979_REG_DEVICE_ID_VENDOR_ID_SHIFT;
	version_id = (id & RT8979_REG_DEVICE_ID_VERSION_ID_MASK) >>
		RT8979_REG_DEVICE_ID_VERSION_ID_SHIFT;

	hwlog_info("get_device_id [%x]=%x,%d,%d\n", RT8979_REG_DEVICE_ID,
		id, vendor_id, version_id);

	if (vendor_id == RT8979_VENDOR_ID) {
		if (version_id == RT8979_1_VERSION_ID) {
			hwlog_info("find rt8979 (first revision)\n");
			device_id = USBSWITCH_ID_RT8979;
		} else if (version_id == RT8979_2_VERSION_ID) {
			hwlog_info("find rt8979 (second revision)\n");
			device_id = USBSWITCH_ID_RT8979;
		} else {
			hwlog_err("use default id (rt8979)\n");
			device_id = USBSWITCH_ID_RT8979;
		}
	} else {
		hwlog_err("rt8979 not find\n");
		device_id = -EINVAL;
	}

	return device_id;
}

int rt8979_is_support_fcp(struct rt8979_device_info *di)
{
	if (!di->fcp_support)
		return -1;

	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id switch_rt8979_ids[] = {
	{ .compatible = "huawei,fairchild_fsa9685" },
	{ .compatible = "huawei,fairchild_fsa9683" },
	{ .compatible = "huawei,nxp_cbtl9689" },
	{ },
};
MODULE_DEVICE_TABLE(of, switch_rt8979_ids);
#endif /* CONFIG_OF */

static int rt8979_parse_dts(struct device_node* np, struct rt8979_device_info *di)
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

static int rt8979_register_init(struct rt8979_device_info *di)
{
	struct power_devices_info_data *power_dev_info = NULL;

	switch_interface_charger_ops_register(rt8979_get_accp_ops());
	switch_interface_bc12_ops_register(rt8979_get_bc12_ops());
	switch_interface_control_ops_register(usbswitch_rt8979_get_control_ops());
	switch_interface_info_ops_register(&rt8979_info_ops);

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

static int rt8979_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct rt8979_device_info *di = NULL;
	struct device_node *node = NULL;
	int ret = -ERR_NO_DEV;
	int reg_ctl;
	bool is_dcp = false;

	hwlog_info("rt8979 probe begin\n");

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
		hwlog_err("i2c_check failed\n");
		goto fail_i2c_check_functionality;
	}

	if (g_rt8979_dev) {
		hwlog_err("rt8979 chip is already detected\n");
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
	di->device_id = rt8979_get_device_id(di);
	if (di->device_id < 0)
		goto fail_i2c_check_functionality;

	rt8979_accp_enable(di, true);
	reg_ctl = switch_read_reg(di->client, RT8979_REG_DEVICE_TYPE_1);
	hwlog_info("DEV_TYPE1 = 0x%x\n", reg_ctl);
	is_dcp = (reg_ctl & RT8979_REG_DEVICE_TYPE_1_DCP_MASK) ? true : false;
	if (is_dcp) {
		hwlog_info("reset rt8979\n");
		switch_write_reg(di->client, RT8979_REG_RESET,
			RT8979_REG_RESET_ENTIRE_IC);
		usleep_range(1000, 1100); /* 1000: sleep 1ms */
		switch_write_reg_mask(di->client, RT8979_REG_CONTROL,
			0, RT8979_REG_CONTROL_SW_OPEN_MASK);
		rt8979_accp_enable(di, true);
	}
	switch_write_reg_mask(di->client, RT8979_REG_TIMING_SET_2,
		RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK,
		RT8979_REG_TIMING_SET_2_DCD_TIMEOUT_SET_MASK);
	rt8979_init_osc_params(di);
	ret = rt8979_init_early(di);
	if (ret < 0)
		goto fail_i2c_check_functionality;

	atomic_set(&di->chg_type_det, 0);
	ret = rt8979_parse_dts(node, di);
	if (ret) {
		hwlog_err("parse dts failed\n");
		goto fail_i2c_check_functionality;
	}
	/* init lock */
	mutex_init(&di->accp_detect_lock);
	mutex_init(&di->accp_adaptor_reg_lock);

	ret = rt8979_init_later(di);
	if (ret < 0)
		goto fail_free_int_gpio;

	rt8979_disable_accp_intr(di);
	/* clear INT MASK */
	reg_ctl = switch_read_reg(di->client, RT8979_REG_CONTROL);
	if (reg_ctl < 0) {
		hwlog_err("read FSA9685_REG_CONTROL error\n");
		ret = -EIO;
		goto fail_free_int_irq;
	}

	reg_ctl &= (~RT8979_REG_CONTROL_INT_MASK_MASK);
	ret = switch_write_reg(di->client, RT8979_REG_CONTROL, reg_ctl);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_CONTROL error\n");
		goto fail_free_int_irq;
	}

	ret = switch_write_reg(di->client, RT8979_REG_DCD,
		RT8979_REG_DCD_STATUS_INIT_VAL);
	if (ret < 0) {
		hwlog_err("write FSA9685_REG_DCD error\n");
		goto fail_free_int_irq;
	}

	ret = rt8979_register_init(di);
	if (ret < 0)
		goto fail_free_int_irq;

	g_rt8979_dev = di;

	hwlog_info("probe end\n");
	return 0;

fail_free_int_irq:
	free_irq(client->irq, client);
fail_free_int_gpio:
fail_i2c_check_functionality:
	g_rt8979_dev = NULL;
	return ret;
}

static int rt8979_remove(struct i2c_client *client)
{
	struct rt8979_device_info *di = i2c_get_clientdata(client);

	free_irq(client->irq, client);
	if (!di)
		return 0;

	hwlog_info("%s\n", __func__);
	disable_irq(di->irq);
#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	cancel_delayed_work_sync(&di->psy_dwork);
	if (di->ac_psy)
		power_supply_put(di->ac_psy);

	kthread_stop(di->bc12_en_kthread);
	wakeup_source_unregister(di->bc12_en_ws);
	mutex_destroy(&di->bc12_lock);
	mutex_destroy(&di->bc12_en_lock);
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */
	mutex_destroy(&di->io_lock);
	mutex_destroy(&di->hidden_mode_lock);

	return 0;
}

static void rt8979_shutdown(struct i2c_client *client)
{
	struct rt8979_device_info *di = i2c_get_clientdata(client);
	int ret;

	if (!di)
		return;

#ifdef CONFIG_BOOST_5V
	if (di->power_by_5v) {
		boost_5v_enable(DISABLE, BOOST_CTRL_FCP);
		dc_set_bst_ctrl(DISABLE);
	}
#endif /* CONFIG_BOOST_5V */

	hwlog_info("%s\n", __func__);
	disable_irq(di->irq);
#ifdef CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT
	kthread_stop(di->bc12_en_kthread);
#endif /* CONFIG_MTK_EXTERNAL_CHARGER_TYPE_DETECT */
	ret = switch_read_reg(di->client, RT8979_REG_MUIC_CTRL_4);
	if (ret < 0)
		return;

	ret = switch_write_reg(di->client, RT8979_REG_MUIC_CTRL_4,
		ret & RT8979_REG_MUIC_CTRL_4_ENABLEID2_FUNCTION);
	if (ret < 0)
		hwlog_info("shutdown error\n");

	ret = rt8979_reset(di);
	if (ret < 0)
		hwlog_err("reset rt8979 failed\n");
}

static int rt8979_suspend(struct device *dev)
{
	struct rt8979_device_info *di = dev_get_drvdata(dev);

	if (!di)
		return -1;

	hwlog_info("%s enter\n", __func__);
	mutex_lock(&di->irq_lock);
	di->resume_completed = false;
	mutex_unlock(&di->irq_lock);
	return 0;
}

static int rt8979_suspend_noirq(struct device *dev)
{
	struct rt8979_device_info *di = dev_get_drvdata(dev);

	if (!di)
		return -1;

	hwlog_info("%s\n", __func__);
	if (di->irq_waiting) {
		hwlog_info("%s Aborting suspend\n", __func__);
		return -EBUSY;
	}

	return 0;
}

static int rt8979_resume(struct device *dev)
{
	struct rt8979_device_info *di = dev_get_drvdata(dev);

	if (!di)
		return -1;

	hwlog_info("%s enter\n", __func__);
	mutex_lock(&di->irq_lock);
	di->resume_completed = true;
	mutex_unlock(&di->irq_lock);
	if (di->irq_waiting) {
		rt8979_deal_resume_irq(di->irq, di);
		enable_irq(di->irq);
	}
	return 0;
}

static const struct dev_pm_ops rt8979_pm_ops = {
#ifdef CONFIG_PM_SLEEP
	.suspend = rt8979_suspend,
	.resume = rt8979_resume,
	.freeze = rt8979_suspend,
	.thaw = rt8979_resume,
	.poweroff = rt8979_suspend,
	.restore = rt8979_resume,
	.suspend_noirq = rt8979_suspend_noirq,
#endif
};

static const struct i2c_device_id rt8979_i2c_id[] = {
	{ "rt8979", 0 },
	{}
};

static struct i2c_driver rt8979_i2c_driver = {
	.probe = rt8979_probe,
	.remove = rt8979_remove,
	.shutdown = rt8979_shutdown,
	.id_table = rt8979_i2c_id,
	.driver = {
		.name = "rt8979",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(switch_rt8979_ids),
		.pm = &rt8979_pm_ops,
	},
};

static __init int rt8979_i2c_init(void)
{
	return i2c_add_driver(&rt8979_i2c_driver);
}

static __exit void rt8979_i2c_exit(void)
{
	i2c_del_driver(&rt8979_i2c_driver);
}

device_initcall_sync(rt8979_i2c_init);
module_exit(rt8979_i2c_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("huawei rt8979 chip driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
