/*
 * drivers/aw37504.c
 *
 * aw37504 driver reffer to lcd
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Author: HUAWEI, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/param.h>
#include <linux/delay.h>
#include <linux/idr.h>
#include <linux/i2c.h>
#include <asm/unaligned.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/ctype.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/err.h>
#include <linux/regulator/consumer.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/workqueue.h>
#include <linux/of.h>
#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <huawei_platform/devdetect/hw_dev_dec.h>
#endif

#include "aw37504.h"
#include "../dpu_fb_def.h"

#if defined(CONFIG_LCD_KIT_DRIVER)
#include "lcd_kit_common.h"
#include "lcd_kit_core.h"
#include "lcd_kit_bias.h"
#endif

static struct aw37504_device_info *aw37504_client = NULL;
static bool is_aw37504_device = false;
static bool is_lyw6360_device = false;

static int aw37504_reg_init(struct i2c_client *client, u8 vpos, u8 vneg)
{
	int ret = 0;
	unsigned int app_dis;
	unsigned int ctl = 0;

	if (client == NULL) {
		pr_err("[%s,%d]: NULL point for client\n", __FUNCTION__, __LINE__);
		goto exit;
	}

	ret = i2c_smbus_read_byte_data(client, AW37504_REG_APP_DIS);
	if (ret < 0) {
		pr_err("%s read app_dis failed\n", __func__);
		goto exit;
	}
	app_dis = (unsigned int)ret;
	app_dis = app_dis | AW37504_DISP_BIT | AW37504_DISN_BIT | AW37504_APPS_BIT;

	ret = i2c_smbus_write_byte_data(client, AW37504_REG_VPOS, (u8)vpos);
	if (ret < 0) {
		pr_err("%s write vpos failed\n", __func__);
		goto exit;
	}
	ret = i2c_smbus_write_byte_data(client, AW37504_REG_VNEG, (u8)vneg);
	if (ret < 0) {
		pr_err("%s write vneg failed\n", __func__);
		goto exit;
	}
	ret = i2c_smbus_write_byte_data(client, AW37504_REG_APP_DIS, (u8)app_dis);
	if (ret < 0) {
		pr_err("%s write add_dis failed\n", __func__);
		goto exit;
	}

	if (is_aw37504_device) {
		ret = i2c_smbus_read_byte_data(client, AW37504_REG_CTRL);
		if (ret < 0) {
			pr_err("%s read ctl failed\n", __func__);
			goto exit;
		}
		ctl = (unsigned int)ret;
		ctl = ctl | AW37504_NCP_BIT;
		ret = i2c_smbus_write_byte_data(client, AW37504_REG_CTRL, (u8)ctl);
		if (ret < 0) {
			pr_err("%s write ctrl failed\n", __func__);
			goto exit;
		}
	}
	pr_info("%s set sus\n", __func__);

exit:
	return ret;
}

#ifdef CONFIG_LCD_KIT_DRIVER
static int aw37504_set_bias(int vpos, int vneg)
{
	unsigned int i = 0;

	for (i = 0; i < sizeof(vol_table) / sizeof(struct aw37504_voltage); i++) {
		if (vol_table[i].voltage == vpos) {
			pr_err("aw37504 vsp voltage:0x%x\n", vol_table[i].value);
			vpos = vol_table[i].value;
			break;
		}
	}
	if (i >= sizeof(vol_table) / sizeof(struct aw37504_voltage)) {
		pr_err("not found vsp voltage, use default voltage:AW37504_VOL_59\n");
		vpos = AW37504_VOL_59;
	}
	for (i = 0; i < sizeof(vol_table) / sizeof(struct aw37504_voltage); i++) {
		if (vol_table[i].voltage == vneg) {
			pr_err("aw37504 vsn voltage:0x%x\n", vol_table[i].value);
			vneg = vol_table[i].value;
			break;
		}
	}

	if (i >= sizeof(vol_table) / sizeof(struct aw37504_voltage)) {
		pr_err("not found vsn voltage, use default voltage:AW37504_VOL_59\n");
		vneg = AW37504_VOL_59;
	}
	pr_err("vpos = 0x%x, vneg = 0x%x\n", vpos, vneg);
	aw37504_reg_init(aw37504_client->client, vpos, vpos);
	return 0;
}

static struct lcd_kit_bias_ops bias_ops = {
	.set_bias_voltage = aw37504_set_bias,
};
#endif

static int aw37504_device_verify(struct i2c_client *client)
{
	int ret = IS_ERR_DEVICE;
	int ctrl = 0;
	int vendorid = 0;

	ctrl = i2c_smbus_read_byte_data(client, AW37504_REG_CTRL);
	if (ctrl == LYW6360_ENABLE_FLAG) {
		DPU_FB_INFO("lyw6360 verify ok, ctrl = 0x%x\n", ctrl);
		ret = IS_LYW6360_DEVICE;
		goto exit;
	} else {
		pr_err("not lyw6360 device, ctrl = 0x%x\n", ctrl);
	}

	vendorid = i2c_smbus_read_byte_data(client, AW3750X_REG_TRIM);
	if ((vendorid & AW37504_VERSION_ID) == AW37504_VERSION_ID) {
		DPU_FB_INFO("aw37504 verify ok, vendorid = 0x%x\n", vendorid);
		ret = IS_AW37504_DEVICE;
		goto exit;
	} else {
		pr_err("not aw37504 device, vendorid = 0x%x\n", vendorid);
	}

	pr_err("%s no bias device\n", __func__);

exit:
	return ret;
}

static int aw37504_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int retval = 0;
	int ret = 0;
	int vpos_target = AW37504_VOL_59;
	int vneg_target = AW37504_VOL_59;
	struct device_node *np = NULL;

	if (client == NULL) {
		pr_err("[%s,%d]: NULL point for client\n", __FUNCTION__, __LINE__);
		retval = -ENODEV;
		goto failed_1;
	}
	client->addr = AW37504_SLAV_ADDR;
	np = of_find_compatible_node(NULL, NULL, DTS_COMP_AW37504);
	if (!np) {
		pr_err("NOT FOUND device node %s!\n", DTS_COMP_AW37504);
		retval = -ENODEV;
		goto failed_1;
	}

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		pr_err("[%s,%d]: need I2C_FUNC_I2C\n", __FUNCTION__, __LINE__);
		retval = -ENODEV;
		goto failed_1;
	}

	aw37504_client = kzalloc(sizeof(*aw37504_client), GFP_KERNEL);
	if (!aw37504_client) {
		dev_err(&client->dev, "failed to allocate device info data\n");
		retval = -ENOMEM;
		goto failed_1;
	}

	i2c_set_clientdata(client, aw37504_client);
	aw37504_client->dev = &client->dev;
	aw37504_client->client = client;

	ret = aw37504_device_verify(aw37504_client->client);
	if (ret == IS_AW37504_DEVICE) {
		is_aw37504_device = true;
	} else if (ret == IS_LYW6360_DEVICE) {
		is_lyw6360_device = true;
	} else {
		is_aw37504_device = false;
		is_lyw6360_device = false;
		retval = -ENODEV;
		pr_err("aw37504_reg_verify failed\n");
		goto failed;
	}

	ret = aw37504_reg_init(aw37504_client->client, (u8)vpos_target, (u8)vneg_target);
	if (ret) {
		retval = -ENODEV;
		pr_err("aw37504_reg_init failed\n");
		goto failed;
	}
	pr_info("aw37504 inited succeed\n");

#ifdef CONFIG_LCD_KIT_DRIVER
	lcd_kit_bias_register(&bias_ops);
#endif

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
	/* detect current device successful, set the flag as present */
	set_hw_dev_flag(DEV_I2C_DC_DC);
#endif

failed_1:
	return retval;
failed:
	if (aw37504_client) {
		kfree(aw37504_client);
		aw37504_client = NULL;
	}
	return retval;
}

static const struct of_device_id aw37504_match_table[] = {
	{
		.compatible = DTS_COMP_AW37504,
		.data = NULL,
	},
	{},
};

static const struct i2c_device_id aw37504_i2c_id[] = {
	{ "aw37504", 0 },
	{ }
};

MODULE_DEVICE_TABLE(of, aw37504_match_table);

static struct i2c_driver aw37504_driver = {
	.id_table = aw37504_i2c_id,
	.probe = aw37504_probe,
	.driver = {
		.name = "aw37504",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(aw37504_match_table),
	},
};

static int __init aw37504_module_init(void)
{
	int ret;

	ret = i2c_add_driver(&aw37504_driver);

	if (ret)
		pr_err("Unable to register aw37504 driver\n");

	return ret;
}

static void __exit aw37504_exit(void)
{
	if (aw37504_client) {
		kfree(aw37504_client);
		aw37504_client = NULL;
	}
	i2c_del_driver(&aw37504_driver);
}

late_initcall(aw37504_module_init);
module_exit(aw37504_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("AW37504 driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
