/*
 * pc_backlight.c
 *
 * backlight for PC
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/regmap.h>
#include <linux/of_gpio.h>
#include "pc_backlight.h"

#define PC_BL_NAME "pc_blacklight"
#define MAX_READ_BL_CHIP_TIMES 3
#define BL_LP8556_I2C_ADDR 0x2c
#define BL_RT8555_I2C_ADDR 0x31
#define BL_SYH62758_I2C_ADDR 0x2e

enum pc_bl_chip_type {
	BL_DEFAULT = 0,
	TI_LP85556 = 1,
	RT_RT8555 = 2,
	SY_SYH62758 = 3,
};

unsigned int pcbl_msg_level = 7;

struct bl_chip_data {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
};

struct pc_bl_info {
	int bl_chip_type;
	int chip_addr;
	struct regmap *chip_regmap;
};

static struct pc_bl_info g_pc_bl_info;

static const struct regmap_config bl_regmap = {
	.reg_bits = 8,
	.val_bits = 8,
	.reg_stride = 1,
};

static int set_rt85555_ctrl_reg(void)
{
	bl_err("+");
	regmap_write(g_pc_bl_info.chip_regmap, 0x00, 0x4c);
	regmap_write(g_pc_bl_info.chip_regmap, 0x01, 0x76);
	regmap_write(g_pc_bl_info.chip_regmap, 0x02, 0x92);
	regmap_write(g_pc_bl_info.chip_regmap, 0x03, 0x00);
	regmap_write(g_pc_bl_info.chip_regmap, 0x08, 0x00);
	regmap_write(g_pc_bl_info.chip_regmap, 0x09, 0x1C);
	regmap_write(g_pc_bl_info.chip_regmap, 0x0A, 0x04);
	regmap_write(g_pc_bl_info.chip_regmap, 0x0B, 0x00);
	regmap_write(g_pc_bl_info.chip_regmap, 0x0D, 0x00);
	regmap_write(g_pc_bl_info.chip_regmap, 0x0E, 0x00);
	regmap_write(g_pc_bl_info.chip_regmap, 0x50, 0x00);
	bl_err("-");
	return 0;
}

static int set_syh62758_ctrl_reg(void)
{
	bl_info("+");
	regmap_write(g_pc_bl_info.chip_regmap, 0x01, 0x81);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA3, 0x72);
	bl_info("-");
	return 0;
}

static int set_lp8556_ctrl_reg(void)
{
	bl_err("+");
	regmap_write(g_pc_bl_info.chip_regmap, 0x01, 0x00);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA0, 0xFF);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA1, 0xCF);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA2, 0x2F);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA3, 0x02);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA4, 0x72);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA5, 0x04);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA6, 0x80);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA7, 0xF6);
	regmap_write(g_pc_bl_info.chip_regmap, 0xA9, 0xA0);
	regmap_write(g_pc_bl_info.chip_regmap, 0xAA, 0x0F);
	regmap_write(g_pc_bl_info.chip_regmap, 0xAE, 0x0F);
	regmap_write(g_pc_bl_info.chip_regmap, 0x9E, 0x22);
	regmap_write(g_pc_bl_info.chip_regmap, 0x16, 0x3F);
	regmap_write(g_pc_bl_info.chip_regmap, 0x98, 0xA5);
	bl_err("-");
	return 0;
}

int bl_chip_config(void)
{
	int ret = -1;
	bl_info("+");
	if(g_pc_bl_info.chip_regmap == NULL) {
		bl_err("the backlight is not on board, so no configuration!");
		return ret;  /* not return error */
	}

	if(g_pc_bl_info.bl_chip_type == TI_LP85556) {
		ret = set_lp8556_ctrl_reg();
	} else if (g_pc_bl_info.bl_chip_type == RT_RT8555) {
		ret = set_rt85555_ctrl_reg();
	} else if (g_pc_bl_info.bl_chip_type == SY_SYH62758) {
		ret = set_syh62758_ctrl_reg();
	} else {
		bl_err("bl chip type is not support");
	}

	bl_info("-");
	return ret;
}

static int probe_init(struct i2c_client *client, struct bl_chip_data **pdata)
{
	struct i2c_adapter *adapter = NULL;

	if (pdata == NULL) {
		bl_err("pdata is NULL pointer\n");
		return -1;
	}

	adapter = client->adapter;
	if (adapter == NULL) {
		bl_err("adapter is NULL pointer\n");
		return -1;
	}

	if (i2c_check_functionality(adapter, I2C_FUNC_I2C) == 0) {
		dev_err(&client->dev, "i2c functionality check fail.\n");
		return -EOPNOTSUPP;
	}

	*pdata = devm_kzalloc(&client->dev,
		sizeof(struct bl_chip_data), GFP_KERNEL);
	if (*pdata == NULL) {
		bl_err("failed to alloc memory");
		return -ENOMEM;
	}

	return 0;
}

static int bl_regmap_init(struct i2c_client *client,
	struct bl_chip_data *pdata)
{
	int ret = 0;
	pdata->regmap = devm_regmap_init_i2c(client, &bl_regmap);
	if(IS_ERR(pdata->regmap)) {
		dev_err(&client->dev, "fail : allocate register map: %d\n", ret);
		ret = -1;
	}

	return ret;
}

static int config_bl_chip_type(struct i2c_client *client,
	struct bl_chip_data *pdata)
{
	int ret = 0;
	int i;
	int reg = 0;

	for(i = 0; i < MAX_READ_BL_CHIP_TIMES; i++) {
		ret = regmap_read(pdata->regmap, 0x01, &reg);
		if(ret) {
			bl_err("fail numbers %d", i);
			continue;
		}

		if(client->addr == BL_LP8556_I2C_ADDR) {
			bl_info("ti lp8556 bl chip is on onboard!");
			g_pc_bl_info.bl_chip_type = TI_LP85556;
			g_pc_bl_info.chip_addr = BL_LP8556_I2C_ADDR;
			g_pc_bl_info.chip_regmap = pdata->regmap;
			return 0;
		}

		if(client->addr == BL_RT8555_I2C_ADDR) {
			bl_info("rt rt855 bl chip is on onboard!");
			g_pc_bl_info.bl_chip_type = RT_RT8555;
			g_pc_bl_info.chip_addr = BL_RT8555_I2C_ADDR;
			g_pc_bl_info.chip_regmap = pdata->regmap;
			return 0;
		}

		if(client->addr == BL_SYH62758_I2C_ADDR) {
			bl_info("syh syh62758 bl chip is on onboard!");
			g_pc_bl_info.bl_chip_type = SY_SYH62758;
			g_pc_bl_info.chip_addr = BL_SYH62758_I2C_ADDR;
			g_pc_bl_info.chip_regmap = pdata->regmap;
			return 0;
		}
	}

	bl_err("pc bl chip isn't onboard!\n");
	return ret;
}

static int pcbl_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	struct bl_chip_data *pdata = NULL;
	int ret;
	bl_info("+");

	if (client == NULL) {
		bl_err("client is NULL pointer\n");
		return -ENOMEM;
	}

	ret = probe_init(client, &pdata);
	if (ret) {
		bl_err("probe init error, ret is %d", ret);
		return ret;
	}

	ret = bl_regmap_init(client, pdata);
	if(ret) {
		bl_err("bl chip regmap init error, ret is %d", ret);
		goto err_out;
	}

	ret = config_bl_chip_type(client, pdata);
	if(ret) {
		bl_err("bl chip config error, ret is %d", ret);
		goto err_out;
	}

	bl_info("-");
	return ret;

err_out:
	devm_kfree(&client->dev, pdata);
	return ret;
}

static int pcbl_remove(struct i2c_client *client)
{
	bl_info("+");
	bl_info("-");
	return 0;
}

static const struct i2c_device_id pcbl_id[] = {
	{PC_BL_NAME, 0},
	{ },
};

static const struct of_device_id pcbl_of_id_tablele[] = {
	{.compatible = "ti,lp8556"},
	{.compatible = "rtk,rt8555"},
	{.compatible = "syh,syh62758"},
	{ },
};

MODULE_DEVICE_TABLE(i2c, pcbl_id);
static struct i2c_driver pc_backlight_i2c_driver = {
	.driver = {
		.name = "pc_backlight",
		.owner = THIS_MODULE,
		.of_match_table = pcbl_of_id_tablele,
	},
	.probe = pcbl_probe,
	.remove = pcbl_remove,
	.id_table = pcbl_id,
};

static int __init pc_bl_module_init(void)
{
	int ret;
	bl_info("+");
	ret = i2c_add_driver(&pc_backlight_i2c_driver);
	if(ret)
		bl_err("Unable to register lm36923 driver\n");
	bl_info("-");
	return ret;
}

#ifndef CONFIG_LCD_KIT_DRIVER
module_init(pc_bl_module_init);
#endif

static void __exit pc_bl_module_exit(void)
{
	bl_info("+");
	i2c_del_driver(&pc_backlight_i2c_driver);
	bl_info("-");
}

module_exit(pc_bl_module_exit);

MODULE_DESCRIPTION("PC Backlight driver");
MODULE_ALIAS("PC backlight driver module");
MODULE_LICENSE("GPL v2");

/*lint +e86 +e546 +e580 +e592*/