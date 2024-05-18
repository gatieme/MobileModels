/*
* aw3750x.c
*
* Copyright (c) 2021-2022 AWINIC Technology CO., LTD
*
* Author: <shiqiang@awinic.com>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*/

#include <linux/init.h>
#include <linux/slab.h>
#include <linux/of_gpio.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <linux/leds.h>
#include <linux/string.h>
#include <linux/regulator/consumer.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>
#include <linux/regulator/of_regulator.h>

#include "aw3750x.h"
#include "lcd_kit_common.h"
#include "lcd_kit_core.h"
#include "lcd_kit_bias.h"

#define AW3750X_DRIVER_VERSION	"V0.3.0"

#define BIAS_TRUE 1
#define BIAS_FALSE 0

static const AW_VOUT aw37501_vout_map[] = {
	{4000000, -4000000, 0x00},
	{4100000, -4100000, 0x01},
	{4200000, -4200000, 0x02},
	{4300000, -4300000, 0x03},
	{4400000, -4400000, 0x04},
	{4500000, -4500000, 0x05},
	{4600000, -4600000, 0x06},
	{4700000, -4700000, 0x07},
	{4800000, -4800000, 0x08},
	{4900000, -4900000, 0x09},
	{5000000, -5000000, 0x0a},
	{5100000, -5100000, 0x0b},
	{5200000, -5200000, 0x0c},
	{5300000, -5300000, 0x0d},
	{5400000, -5400000, 0x0e},
	{5500000, -5500000, 0x0f},
	{5600000, -5600000, 0x10},
	{5700000, -5700000, 0x11},
	{5800000, -5800000, 0x12},
	{5900000, -5900000, 0x13},
	{6000000, -6000000, 0x14},
};
static const AW_VOUT aw37502_vout_map[] = {
	{4000000, -4000000, 0x00},
	{4100000, -4100000, 0x01},
	{4200000, -4200000, 0x02},
	{4300000, -4300000, 0x03},
	{4400000, -4400000, 0x04},
	{4500000, -4500000, 0x05},
	{4600000, -4600000, 0x06},
	{4700000, -4700000, 0x07},
	{4800000, -4800000, 0x08},
	{4900000, -4900000, 0x09},
	{5000000, -5000000, 0x0a},
	{5100000, -5100000, 0x0b},
	{5200000, -5200000, 0x0c},
	{5300000, -5300000, 0x0d},
	{5400000, -5400000, 0x0e},
	{5500000, -5500000, 0x0f},
	{5600000, -5600000, 0x10},
	{5700000, -5700000, 0x11},
	{5800000, -5800000, 0x12},
	{5900000, -5900000, 0x13},
	{6000000, -6000000, 0x14},
	{6100000, -6100000, 0x15},
	{6200000, -6200000, 0x16},
	{6300000, -6300000, 0x17},
	{6400000, -6400000, 0x18},
	{6500000, -6500000, 0x19},
};
static const AW_VOUT aw37503_vout_map[] = {
	{4000000, -4000000, 0x00},
	{4100000, -4100000, 0x01},
	{4200000, -4200000, 0x02},
	{4300000, -4300000, 0x03},
	{4400000, -4400000, 0x04},
	{4500000, -4500000, 0x05},
	{4600000, -4600000, 0x06},
	{4700000, -4700000, 0x07},
	{4800000, -4800000, 0x08},
	{4900000, -4900000, 0x09},
	{5000000, -5000000, 0x0a},
	{5100000, -5100000, 0x0b},
	{5200000, -5200000, 0x0c},
	{5300000, -5300000, 0x0d},
	{5400000, -5400000, 0x0e},
	{5500000, -5500000, 0x0f},
	{5600000, -5600000, 0x10},
	{5700000, -5700000, 0x11},
	{5800000, -5800000, 0x12},
	{5900000, -5900000, 0x13},
	{6000000, -6000000, 0x14},
};

static const AW_VOUT aw37505_vout_map[] = {
	{4000000, -4000000, 0x00},
	{4100000, -4100000, 0x01},
	{4200000, -4200000, 0x02},
	{4300000, -4300000, 0x03},
	{4400000, -4400000, 0x04},
	{4500000, -4500000, 0x05},
	{4600000, -4600000, 0x06},
	{4700000, -4700000, 0x07},
	{4800000, -4800000, 0x08},
	{4900000, -4900000, 0x09},
	{5000000, -5000000, 0x0a},
	{5100000, -5100000, 0x0b},
	{5200000, -5200000, 0x0c},
	{5300000, -5300000, 0x0d},
	{5400000, -5400000, 0x0e},
	{5500000, -5500000, 0x0f},
	{5600000, -5600000, 0x10},
	{5700000, -5700000, 0x11},
	{5800000, -5800000, 0x12},
	{5900000, -5900000, 0x13},
	{6000000, -6000000, 0x14},
	{6100000, -6100000, 0x15},
	{6200000, -6200000, 0x16},
	{6300000, -6300000, 0x17},
	{6400000, -6400000, 0x18},
	{6500000, -6500000, 0x19},
};

static struct aw3750x_voltage voltage_table[] = {
	{ LCD_BIAS_VOL_40, AW3750X_VOL_40 },
	{ LCD_BIAS_VOL_41, AW3750X_VOL_41 },
	{ LCD_BIAS_VOL_42, AW3750X_VOL_42 },
	{ LCD_BIAS_VOL_43, AW3750X_VOL_43 },
	{ LCD_BIAS_VOL_44, AW3750X_VOL_44 },
	{ LCD_BIAS_VOL_45, AW3750X_VOL_45 },
	{ LCD_BIAS_VOL_46, AW3750X_VOL_46 },
	{ LCD_BIAS_VOL_47, AW3750X_VOL_47 },
	{ LCD_BIAS_VOL_48, AW3750X_VOL_48 },
	{ LCD_BIAS_VOL_49, AW3750X_VOL_49 },
	{ LCD_BIAS_VOL_50, AW3750X_VOL_50 },
	{ LCD_BIAS_VOL_51, AW3750X_VOL_51 },
	{ LCD_BIAS_VOL_52, AW3750X_VOL_52 },
	{ LCD_BIAS_VOL_53, AW3750X_VOL_53 },
	{ LCD_BIAS_VOL_54, AW3750X_VOL_54 },
	{ LCD_BIAS_VOL_55, AW3750X_VOL_55 },
	{ LCD_BIAS_VOL_56, AW3750X_VOL_56 },
	{ LCD_BIAS_VOL_57, AW3750X_VOL_57 },
	{ LCD_BIAS_VOL_58, AW3750X_VOL_58 },
	{ LCD_BIAS_VOL_59, AW3750X_VOL_59 },
	{ LCD_BIAS_VOL_60, AW3750X_VOL_60 }
};

const unsigned char aw3750x_reg_access[AW3750X_REG_MAX] = {
	[AW3750X_REG_VOUTP] = REG_RD_ACCESS|REG_WR_ACCESS,
	[AW3750X_REG_VOUTN] = REG_RD_ACCESS|REG_WR_ACCESS,
	[AW3750X_REG_APPS]  = REG_RD_ACCESS|REG_WR_ACCESS,
	[AW3750X_REG_CTRL]  = REG_RD_ACCESS|REG_WR_ACCESS,
	[AW3750X_REG_VERSION]  = REG_RD_ACCESS|REG_WR_ACCESS,
};

struct aw3750x_power *g_aw3750x = NULL;

static int g_vol_mapped = BIAS_FALSE;
static unsigned char vpos_cmd;
static unsigned char vneg_cmd;

static void aw3750x_get_target_voltage(int vpos_target, int vneg_target)
{
	int i;
	int vol_size = ARRAY_SIZE(voltage_table);

	for (i = 0; i < vol_size; i++) {
		if (voltage_table[i].voltage == vpos_target) {
			LCD_KIT_INFO("aw3750x vsp voltage:0x%x\n", voltage_table[i].value);
			vpos_cmd = voltage_table[i].value;
			break;
		}
	}
	if (i >= vol_size) {
		LCD_KIT_ERR("not found vsp voltage, use default voltage\n");
		vpos_cmd = AW3750X_VOL_50;
	}
	for (i = 0; i < vol_size; i++) {
		if (voltage_table[i].voltage == vneg_target) {
			LCD_KIT_INFO("aw3750x vsn voltage:0x%x\n", voltage_table[i].value);
			vneg_cmd = voltage_table[i].value;
			break;
		}
	}
	if (i >= vol_size) {
		LCD_KIT_ERR("not found vsn voltage, use default voltage\n");
		vneg_cmd = AW3750X_VOL_50;
	}
	LCD_KIT_INFO("vpos = 0x%x, vneg = 0x%x\n", vpos_cmd, vneg_cmd);
}

static int aw3750x_i2c_write(struct aw3750x_power *aw3750x, u8 reg, u8 val)
{
	int ret = -1;
	unsigned char cnt = 0;

	while (cnt < AW_I2C_RETRIES) {
		ret =
		i2c_smbus_write_byte_data(aw3750x->client, reg, val);
		if (ret < 0) {
			pr_err("%s: i2c_write cnt=%d error=%d\n",
				__func__, cnt, ret);
		} else {
			break;
		}
		cnt++;
		usleep_range(2000, 3000);
	}

	return ret;
}

static int aw3750x_i2c_read(struct aw3750x_power *aw3750x, u8 reg, u8 *val)
{
	int ret = -1;
	unsigned char cnt = 0;

	while (cnt < AW_I2C_RETRIES) {
		ret = i2c_smbus_read_byte_data(aw3750x->client, reg);
		if (ret < 0) {
			pr_err("%s: i2c_read cnt=%d error=%d\n",
				__func__, cnt, ret);
		} else {
			*val = ret;
			break;
		}
		cnt++;
		usleep_range(2000, 3000);
	}
	return ret;
}

static int aw3750x_i2c_bit_write(struct aw3750x_power *aw3750x,
					u8 reg_addr,
					u16 mask,
					u8 reg_data)
{
	uint8_t reg_val = 0;
	uint8_t reg_mask = (uint8_t)mask;
	int ret = 0;

	ret = aw3750x_i2c_read(aw3750x, reg_addr, &reg_val);
	reg_val &= reg_mask;
	reg_val |= (reg_data & (~reg_mask));
	ret = aw3750x_i2c_write(aw3750x, reg_addr, reg_val);

	return ret;
}

static int aw3750x_i2c_bit_clear(struct aw3750x_power *aw3750x, u8 reg_addr, u16 mask)
{
	uint8_t reg_val = 0;
	int ret = 0;

	ret = aw3750x_i2c_read(aw3750x, reg_addr, &reg_val);
	reg_val &= mask;
	ret = aw3750x_i2c_write(aw3750x, reg_addr, reg_val);

	return ret;
}

static int aw3750x_soft_reset(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS,
						AW_SOFT_RESET_MASK,
						AW3750X_SOFT_RESET);
	if (ret < 0) {
		pr_err("%s aw3750x_i2c_bit_write failed\n", __func__);
		return ret;
	}
	mdelay(5);
	return 0;
}
static int aw3750x_get_voltage_by_reg(struct aw3750x_power *aw3750x, int reg_val)
{
	int i = 0;

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
			(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID) |
			(aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID) |
			(aw3750x->aw3750x_version_id == AW37503_VERSION_ID) |
			(aw3750x->aw3750x_version_id == AW37504_VERSION_ID)) {
			for (i = 0; i < ARRAY_SIZE(aw37501_vout_map); i++) {
				if (reg_val == aw37501_vout_map[i].vout_reg) {
					aw3750x->select = i;
					return aw37501_vout_map[i].voutp;
				}
				if (reg_val > AW37501_MAX_VOLTAGE) {
					aw3750x->select = ARRAY_SIZE(aw37501_vout_map) - 1;
					return aw37501_vout_map[ARRAY_SIZE(aw37501_vout_map) - 1].voutp;
				}
			}
	} else if ((aw3750x->aw3750x_version_id == AW37502_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37505_VERSION_ID)) {
		for (i = 0; i < ARRAY_SIZE(aw37502_vout_map); i++) {
			if (reg_val == aw37502_vout_map[i].vout_reg) {
				aw3750x->select = i;
				return aw37502_vout_map[i].voutp;
			}
			if (reg_val > AW37502_MAX_VOLTAGE) {
				aw3750x->select = ARRAY_SIZE(aw37502_vout_map) - 1;
				return aw37502_vout_map[ARRAY_SIZE(aw37502_vout_map) - 1].voutp;
			}
		}
	}
	return 0;
}
static int aw3750x_get_reg_by_voltage(struct aw3750x_power *aw3750x, int vol)
{
	int i = 0;

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
			(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID) |
			(aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID) |
			(aw3750x->aw3750x_version_id == AW37503_VERSION_ID) |
			(aw3750x->aw3750x_version_id == AW37504_VERSION_ID)) {
			for (i = 0; i < ARRAY_SIZE(aw37501_vout_map); i++) {
				if (vol == aw37501_vout_map[i].voutp) {
					aw3750x->select = i;
					return aw37501_vout_map[i].vout_reg;
				}
				if (vol > aw37501_vout_map[ARRAY_SIZE(aw37501_vout_map) - 1].voutp) {
					aw3750x->select = ARRAY_SIZE(aw37501_vout_map) - 1;
					return aw37501_vout_map[ARRAY_SIZE(aw37501_vout_map) - 1].vout_reg;
				}
			}
	} else if ((aw3750x->aw3750x_version_id == AW37502_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37505_VERSION_ID)) {
		for (i = 0; i < ARRAY_SIZE(aw37502_vout_map); i++) {
			if (vol == aw37502_vout_map[i].voutp) {
				aw3750x->select = i;
				return aw37502_vout_map[i].vout_reg;
			}
			if (vol > aw37502_vout_map[ARRAY_SIZE(aw37502_vout_map) - 1].voutp) {
				aw3750x->select = ARRAY_SIZE(aw37502_vout_map) - 1;
				return aw37502_vout_map[ARRAY_SIZE(aw37502_vout_map) - 1].vout_reg;
			}
		}
	}
	return 0;
}

static int aw3750x_disn_enable(struct aw3750x_power *aw3750x)
{
	int ret;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS,
						AW3750X_DISN_MASK,
						AW3750X_DISN_ENABLE);
	if (ret < 0) {
		pr_err("%s aw3750x_i2c_bit_write failed\n", __func__);
		return ret;
	}

	return 0;
}

static int aw3750x_disn_disable(struct aw3750x_power *aw3750x)
{
	int ret;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_bit_clear(aw3750x, AW3750X_REG_APPS, AW3750X_DISN_MASK);
	if (ret < 0) {
		pr_err("%s aw3750x_i2c_bit_clear failed\n", __func__);
		return ret;
	}

	return 0;
}
static int aw3750x_disp_enable(struct aw3750x_power *aw3750x)
{
	int ret;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS,
						AW3750X_DISP_MASK,
						AW3750X_DISP_ENABLE);
	if (ret < 0) {
		pr_err("%s aw3750x_i2c_bit_write failed\n", __func__);
		return ret;
	}

	return 0;
}

static int aw3750x_disp_disable(struct aw3750x_power *aw3750x)
{
	int ret;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_bit_clear(aw3750x, AW3750X_REG_APPS, AW3750X_DISP_MASK);
	if (ret < 0) {
		pr_err("%s aw3750x_i2c_bit_clear failed\n", __func__);
		return ret;
	}

	return 0;
}

static int aw3750x_enn_enable(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	if (aw3750x->aw3750x_gpio_ctrl == 1) {
		ret = pinctrl_select_state(aw3750x->pinctrl.pinctrl,
					     aw3750x->pinctrl.aw_enn_high);
		if (ret < 0) {
			pr_err("%s pinctrl_select_state failed for aw_enn_high\n",
				__func__);
			return ret;
		}
	} else {
		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO, AW3750X_OPEN_CMD);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_write AW3750X_OPEN_CMD failed\n", __func__);
			return ret;
		}
		ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS,
							AW3750X_ENN_MASK,
							AW3750X_ENN_ENABLE);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_bit_write failed\n", __func__);
			return ret;
		}

		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO, AW3750X_CLOSE_CMD);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_write AW3750X_CLOSE_CMD failed\n", __func__);
			return ret;
		}
	}
	return 0;
}

static int aw3750x_enn_disable(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	if (aw3750x->aw3750x_gpio_ctrl == 1) {
		ret = pinctrl_select_state(aw3750x->pinctrl.pinctrl,
					     aw3750x->pinctrl.aw_enn_low);
		if (ret < 0) {
			pr_err("%s pinctrl_select_state failed for aw_enn_low\n",
				__func__);
			return ret;
		}
	} else {
		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO, AW3750X_OPEN_CMD);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_write AW3750X_OPEN_CMD failed\n", __func__);
			return ret;
		}
		ret = aw3750x_i2c_bit_clear(aw3750x, AW3750X_REG_APPS, AW3750X_ENN_MASK);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_bit_clear failed\n", __func__);
			return ret;
		}

		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO, AW3750X_CLOSE_CMD);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_write AW3750X_CLOSE_CMD failed\n", __func__);
			return ret;
		}
	}
	return 0;
}

static int aw3750x_enp_enable(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	if (aw3750x->aw3750x_gpio_ctrl == 1) {
		ret = pinctrl_select_state(aw3750x->pinctrl.pinctrl,
					     aw3750x->pinctrl.aw_enp_high);
		if (ret < 0) {
			pr_err("%s pinctrl_select_state failed for aw_enp_high\n",
				__func__);
			return ret;
		}
	} else {
		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO, AW3750X_OPEN_CMD);
		if (ret < 0)
			return ret;

		ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS,
							AW3750X_ENP_MASK,
							AW3750X_ENP_ENABLE);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_bit_write failed\n", __func__);
			return ret;
		}

		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO, AW3750X_CLOSE_CMD);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_write AW3750X_CLOSE_CMD failed\n", __func__);
			return ret;
		}
	}
	return 0;
}

static int aw3750x_enp_disable(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	if (aw3750x->aw3750x_gpio_ctrl == 1) {
		ret = pinctrl_select_state(aw3750x->pinctrl.pinctrl,
					     aw3750x->pinctrl.aw_enp_low);
		if (ret < 0) {
			pr_info("%s pinctrl_select_state failed for aw_enp_low\n",
				__func__);
			return ret;
		}
	} else {
		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO, AW3750X_OPEN_CMD);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_write AW3750X_OPEN_CMD failed\n", __func__);
			return ret;
		}

		ret = aw3750x_i2c_bit_clear(aw3750x, AW3750X_REG_APPS, AW3750X_ENP_MASK);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_bit_clear failed\n", __func__);
			return ret;
		}

		ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO,
				    AW3750X_CLOSE_CMD);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_write AW3750X_CLOSE_CMD failed\n", __func__);
			return ret;
		}
	}
	return 0;
}

static int aw3750x_voltage_outp_set(struct aw3750x_power *aw3750x)
{
	u8 reg_val = 0;
	int ret = 0;

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID) |
		(aw3750x->aw3750x_version_id == AW37503_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37504_VERSION_ID)) {
		if (aw3750x->outp_set > AW37501_MAX_VOLTAGE)
			aw3750x->outp_set = AW37501_MAX_VOLTAGE;
	} else if ((aw3750x->aw3750x_version_id == AW37502_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37505_VERSION_ID)) {
		if (aw3750x->outp_set > AW37502_MAX_VOLTAGE)
			aw3750x->outp_set = AW37502_MAX_VOLTAGE;
	}
	reg_val = reg_val | aw3750x->outp_set;
	ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_VOUTP, reg_val);
	if (ret < 0) {
		pr_err("%s aw3750x_i2c_write AW3750X_REG_VOUTP failed\n", __func__);
		return ret;
	}
	pr_info("%s out_val = %#x\n", __func__, aw3750x->outp_set);

	return 0;
}

static int aw3750x_voltage_outn_set(struct aw3750x_power *aw3750x)
{
	u8 reg_val = 0;
	int ret = 0;

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID) |
		(aw3750x->aw3750x_version_id == AW37503_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37504_VERSION_ID)) {
		if (aw3750x->outn_set > AW37501_MAX_VOLTAGE)
			aw3750x->outn_set = AW37501_MAX_VOLTAGE;
	} else if ((aw3750x->aw3750x_version_id == AW37502_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37505_VERSION_ID)) {
		if (aw3750x->outn_set > AW37502_MAX_VOLTAGE)
			aw3750x->outn_set = AW37502_MAX_VOLTAGE;
	}
	reg_val = reg_val | aw3750x->outn_set;
	ret = aw3750x_i2c_write(aw3750x, AW3750X_REG_VOUTN, reg_val);
	if (ret < 0) {
		pr_err("%s aw3750x_i2c_write failed\n", __func__);
		return ret;
	}
	pr_info("%s out_val = %#x\n", __func__, aw3750x->outn_set);

	return 0;
}

static void aw3750x_set_current(void)
{
	int ret = 0;
	u8 val1 = 0, val2 = 0;
	ret = aw3750x_i2c_read(g_aw3750x, AW3750X_REG_APPS, &val1);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_read_u8 AW3750X_REG_APPS failed,ret = %d\n", ret);
		return;
	}
	val1 |= AW3750X_APPS_APPS_BIT;
	LCD_KIT_INFO("aw3750x_i2c_read_u8 REG_APPS, val1 = 0x%x\n", val1);
	ret = aw3750x_i2c_write(g_aw3750x, AW3750X_REG_APPS, val1);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_write_u8 AW3750X_REG_APPS failed,ret = %d\n", ret);
		return;
	}
	ret = aw3750x_i2c_read(g_aw3750x, AW3750X_REG_CTRL, &val2);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_read_u8 AW3750X_REG_CTRL failed,ret = %d\n", ret);
		return;
	}
	val2 |= AW3750X_CTRL_ILMTNCP_BIT;
	LCD_KIT_INFO("aw3750x_i2c_read_u8 REG_CTRL, val2 = 0x%x\n", val2);
	ret = aw3750x_i2c_write(g_aw3750x, AW3750X_REG_CTRL, val2);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_write_u8 AW3750X_REG_CTRL failed,ret = %d\n", ret);
		return;
	}
	return;
}

static int aw3750x_set_bias(int vpos, int vneg)
{
	int ret;

	if (g_aw3750x == NULL) {
		pr_err("%s, g_aw3750x is NULL\n", __func__);
		return -1;
	}

	if (g_vol_mapped == BIAS_FALSE) {
		aw3750x_get_target_voltage(vpos, vneg);
		g_vol_mapped = BIAS_TRUE;
	}
	g_aw3750x->outp = vpos_cmd;
	ret = aw3750x_voltage_outp_set(g_aw3750x);
	if (ret < 0) {
		pr_err("%s, aw3750x_voltage_outp_set error\n", __func__);
		return ret;
	}

	g_aw3750x->outn = vneg_cmd;
	ret = aw3750x_voltage_outn_set(g_aw3750x);
	if (ret < 0) {
		pr_err("%s, aw3750x_voltage_outn_set error\n", __func__);
		return ret;
	}

	return LCD_KIT_OK;
}

static struct lcd_kit_bias_ops bias_ops = {
	.set_bias_voltage = aw3750x_set_bias,
	.dbg_set_bias_voltage = NULL,
};

static int aw3750x_voltage_outp_get(struct aw3750x_power *aw3750x)
{
	u8 reg_val;
	int ret;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_VOUTP, &reg_val);
	if (ret < 0) {
		pr_err("%s, aw3750x_i2c_read error...\n", __func__);
		return ret;
	}
	aw3750x->read_outp = reg_val;

	return 0;
}

static int aw3750x_voltage_outn_get(struct aw3750x_power *aw3750x)
{
	u8 reg_val;
	int ret;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_VOUTN, &reg_val);
	if (ret < 0) {
		pr_err("%s, aw3750x_i2c_read error...\n", __func__);
		return ret;
	}
	aw3750x->read_outn = reg_val;
	return 0;
}

static int aw3750x_ldo_current_set(struct aw3750x_power *aw3750x)
{
	int ret;

	pr_info("%s\n", __func__);

	if (aw3750x->limit == MAX_LOO_CURRENT) {
		ret = aw3750x_i2c_bit_clear(aw3750x, AW3750X_REG_CTRL, LOO_CURRENT_MASK);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_bit_clear failed\n", __func__);
			return ret;
		}
	} else if (aw3750x->limit == MIN_LOD_CURRENT) {
		ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_CTRL,
							LOO_CURRENT_MASK,
							LOD_CURRENT_VAL);
		if (ret < 0) {
			pr_err("%s aw3750x_i2c_bit_write failed\n", __func__);
			return ret;
		}
	}
	return 0;
}

static int aw3750x_status_read(struct aw3750x_power *aw3750x, u8 *val)
{
	u8 reg_val;
	int ret;

	pr_info("%s\n", __func__);

	ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_APPS, &reg_val);
	if (ret < 0) {
		pr_err("%s, aw3750x_i2c_read error...\n", __func__);
		return ret;
	}
	*val = reg_val;

	return 0;
}

/* ************************* regulator driver ************************* */
static int aw3750x_list_voltage(struct regulator_dev *rdev, unsigned selector)
{
	if (selector >= rdev->desc->n_voltages)
			return -EINVAL;
	if (selector < rdev->desc->linear_min_sel)
			return 0;
	selector -= rdev->desc->linear_min_sel;

	return rdev->desc->min_uV + (rdev->desc->uV_step * selector);
}

static int
aw3750x_set_voltage(struct regulator_dev *rdev,
						    int vol_min, int vol_max,
						    unsigned *selector)
{
	int ret = 0;
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);

	pr_info("%s enter\n", __func__);

	if (strcmp(rdev->desc->name, "outp") == 0) {
		aw3750x->outp = vol_min;
		aw3750x->outp_set = aw3750x_get_reg_by_voltage(aw3750x, aw3750x->outp);
		ret = aw3750x_voltage_outp_set(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_voltage_outp_set error\n",
				__func__);
			return ret;
		}
	} else if (strcmp(rdev->desc->name, "outn") == 0) {
		aw3750x->outn = vol_min;
		aw3750x->outn_set = aw3750x_get_reg_by_voltage(aw3750x, aw3750x->outn);
		ret = aw3750x_voltage_outn_set(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_voltage_outn_set error\n",
				__func__);
			return ret;
		}
	} else {
		pr_err("%s, regulator outp/outn set failed\n", __func__);
		return -EINVAL;
	}

	return ret;
}

static int aw37501_get_voltage_sel(struct regulator_dev *rdev)
{
	int ret = 0;
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);

	pr_info("%s enter\n", __func__);

	if (strcmp(rdev->desc->name, "outp") == 0) {
		ret = aw3750x_voltage_outp_get(aw3750x);
		if (ret < 0) {
			return ret;
			pr_err("%s, aw3750x_voltage_outp_get error\n",
				__func__);
		}
		aw3750x->outp = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outp);
		return aw3750x->outp;
	} else if (strcmp(rdev->desc->name, "outn") == 0) {
		ret = aw3750x_voltage_outn_get(aw3750x);
		if (ret < 0) {
			return ret;
			pr_err("%s, aw3750x_voltage_outn_get error\n",
				__func__);
		}
		aw3750x->outn = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outn);
		return aw3750x->outn;
	} else {
		pr_err("%s, regulator dev error\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static int aw37502_get_voltage_sel(struct regulator_dev *rdev)
{
	int ret = 0;
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);

	pr_info("%s enter test\n", __func__);

	if (strcmp(rdev->desc->name, "outp") == 0) {
		ret = aw3750x_voltage_outp_get(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_voltage_outp_get error\n",
				__func__);
			return ret;
		}
		aw3750x->outp = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outp);
		return aw3750x->outp;
	} else if (strcmp(rdev->desc->name, "outn") == 0) {
		ret = aw3750x_voltage_outn_get(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_voltage_outn_get error\n",
				__func__);
			return ret;
		}
		aw3750x->outn = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outn);
		return aw3750x->outn;
	} else {
		pr_err("%s, regulator dev error\n", __func__);
		return -EINVAL;
	}

	return 0;
}
static int aw37503_get_voltage_sel(struct regulator_dev *rdev)
{
	int ret = 0;
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);

	pr_info("%s enter test\n", __func__);

	if (strcmp(rdev->desc->name, "outp") == 0) {
		ret = aw3750x_voltage_outp_get(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_voltage_outp_get error\n",
				__func__);
			return ret;
		}
		aw3750x->outp = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outp);
		return aw3750x->outp;
	} else if (strcmp(rdev->desc->name, "outn") == 0) {
		ret = aw3750x_voltage_outn_get(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_voltage_outn_get error\n",
				__func__);
			return ret;
		}
		aw3750x->outn = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outn);
		return aw3750x->outn;
	} else {
		pr_err("%s, regulator dev error\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static int aw37505_get_voltage_sel(struct regulator_dev *rdev)
{
	int ret = 0;
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);

	pr_info("%s enter test\n", __func__);

	if (strcmp(rdev->desc->name, "outp") == 0) {
		ret = aw3750x_voltage_outp_get(aw3750x);
		if (ret < 0) {
			return ret;
			pr_err("%s, aw3750x_voltage_outp_get error\n",
				__func__);
		}
		aw3750x->outp = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outp);
		return aw3750x->outp;
	} else if (strcmp(rdev->desc->name, "outn") == 0) {
		ret = aw3750x_voltage_outn_get(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_voltage_outn_get error\n",
				__func__);
			return ret;
		}
		aw3750x->outn = aw3750x_get_voltage_by_reg(aw3750x, aw3750x->read_outn);
		return aw3750x->outn;
	} else {
		pr_err("%s, regulator dev error\n", __func__);
		return -EINVAL;
	}

	return 0;
}


static int aw3750x_get_voltage(struct regulator_dev *rdev)
{
	int ret = 0;
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID)) {
		ret = aw37501_get_voltage_sel(rdev);
	}
	else if (aw3750x->aw3750x_version_id == AW37502_VERSION_ID) {
		ret = aw37502_get_voltage_sel(rdev);
	}
	else if (aw3750x->aw3750x_version_id == AW37503_VERSION_ID ||
			aw3750x->aw3750x_version_id == AW37504_VERSION_ID) {
		ret = aw37503_get_voltage_sel(rdev);
	}
	else if (aw3750x->aw3750x_version_id == AW37505_VERSION_ID) {
		ret = aw37505_get_voltage_sel(rdev);
	}
	else {
		pr_err("%s, no device provide.\n", __func__);
	}
	return ret;
}
static int aw37501_set_current(struct aw3750x_power *aw3750x,
				      int min_uA,
				      int max_uA)
{
	int ret = 0;
	u8 reg_val = 0;

	pr_info("%s enter.\n", __func__);

	if (min_uA < AW_CURRENT_40MA) {
		aw3750x->power_mode = AW37501_CURRENT_40MA_VAL;
	}
	else if (min_uA < AW_CURRENT_80MA) {
		aw3750x->power_mode = AW37501_CURRENT_80MA_VAL;
	}
	else if (min_uA < AW_CURRENT_100MA) {
		aw3750x->power_mode = AW37501_CURRENT_100MA_VAL;
	}
	else {
		pr_err("%s aw3750x->power_mode failed\n", __func__);
		return -EINVAL;
	}
	reg_val = reg_val | aw3750x->power_mode;
	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS, AW37501_CURRENT_MASK, reg_val);
	if (ret < 0) {
		pr_err("%s,aw37501_set_current failed\n", __func__);
		return ret;
	}

	return 0;
}

static int aw37501b_set_current(struct aw3750x_power *aw3750x,
						int min_uA,
						int max_uA)
{
	int ret = 0;
	u8 reg_val = 0;

	pr_info("%s enter.\n", __func__);

	if (min_uA < AW_CURRENT_40MA) {
		aw3750x->power_mode = AW37501B_CURRENT_40MA_VAL;
	}
	else if (min_uA < AW_CURRENT_80MA) {
		aw3750x->power_mode = AW37501B_CURRENT_80MA_VAL;
	}
	else if (min_uA < AW_CURRENT_120MA) {
		aw3750x->power_mode = AW37501B_CURRENT_120MA_VAL;
	}
	else if (min_uA < AW_CURRENT_150MA) {
		aw3750x->power_mode = AW37501B_CURRENT_150MA_VAL;
	}
	else {
		pr_err("%s aw3750x->power_mode failed\n", __func__);
		return -EINVAL;
	}

	reg_val = reg_val | aw3750x->power_mode;
	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS, AW37501_CURRENT_MASK, reg_val);
	if (ret < 0) {
		pr_err("%s,aw37501b_set_current failed\n", __func__);
		return ret;
	}

	return 0;
}


static int aw37502_set_current(struct aw3750x_power *aw3750x,
				      int min_uA,
				      int max_uA)
{
	int ret = 0;
	u8 reg_val = 0;

	pr_info("%s enter.\n", __func__);

	if (min_uA < AW_CURRENT_40MA) {
		aw3750x->power_mode = AW37502_CURRENT_40MA_VAL;
	}
	else if (min_uA < AW_CURRENT_80MA) {
		aw3750x->power_mode = AW37502_CURRENT_80MA_VAL;
	}
	else if (min_uA < AW_CURRENT_100MA) {
		aw3750x->power_mode = AW37502_CURRENT_100MA_VAL;
	}
	else {
		pr_err("%s aw3750x->power_mode failed\n", __func__);
		return -EINVAL;
	}

	reg_val = reg_val | aw3750x->power_mode;
	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS, AW37502_CURRENT_MASK, reg_val);
	if (ret < 0) {
		pr_err("%s,aw37502_set_current failed\n", __func__);
		return ret;
	}

	return 0;
}
static int aw37503_set_current(struct aw3750x_power *aw3750x,
				      int min_uA,
				      int max_uA)
{
	int ret = 0;
	u8 reg_val = 0;

	pr_info("%s enter.\n", __func__);

	if (min_uA < AW_CURRENT_80MA) {
		aw3750x->power_mode = AW37503_CURRENT_80MA_VAL;
	}
	else if (min_uA < AW_CURRENT_150MA) {
		aw3750x->power_mode = AW37503_CURRENT_150MA_VAL;
	}
	else {
		pr_err("%s aw3750x->power_mode failed\n", __func__);
		return -EINVAL;
	}

	reg_val = reg_val | aw3750x->power_mode;
	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS, AW37503_CURRENT_MASK, reg_val);
	if (ret < 0) {
		pr_err("%s,aw37503_set_current failed\n", __func__);
		return ret;
	}

	return 0;
}
static int aw37504_set_current(struct aw3750x_power *aw3750x,
				      int min_uA,
				      int max_uA)
{
	int ret = 0;
	u8 reg_ctrl = 0;
	u8 reg_apps = 0;

	pr_info("%s enter.\n", __func__);

	if (min_uA < AW_CURRENT_80MA) {
		reg_ctrl = 0;
		reg_apps = 0;
		pr_info("%s,set_current AW_CURRENT_80MA\n", __func__);
	} else if (min_uA < AW_CURRENT_100MA) {
		reg_ctrl = AW37504_CURRENT_CTRL;
		reg_apps = 0;
		pr_info("%s,set_current AW_CURRENT_100MA\n", __func__);
	} else if (min_uA < AW_CURRENT_150MA) {
		reg_ctrl = 0;
		reg_apps = AW37504_CURRENT_APPS;
		pr_info("%s,set_current AW_CURRENT_150MA\n", __func__);
	} else if (min_uA < AW_CURRENT_220MA) {
		reg_ctrl = AW37504_CURRENT_CTRL;
		reg_apps = AW37504_CURRENT_APPS;
		pr_info("%s,set_current AW_CURRENT_220MA\n", __func__);
	} else {
		pr_err("%s,set_current error.\n", __func__);
		return -EINVAL;
	}

	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_CTRL, AW37504_CURRENT_CTRL_MASK, reg_ctrl);
	if (ret < 0) {
		pr_err("%s,aw37504 set current ctrl failed\n", __func__);
		return ret;
	}
	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS, AW37504_CURRENT_APPS_MASK, reg_apps);
	if (ret < 0) {
		pr_err("%s,aw37504 set current apps failed\n", __func__);
		return ret;
	}

	return 0;
}

static int aw37505_set_current(struct aw3750x_power *aw3750x,
									  int min_uA,
									  int max_uA)
{
	int ret = 0;
	u8 reg_val = 0;

	pr_info("%s enter.\n", __func__);

	if (min_uA < AW_CURRENT_80MA) {
		aw3750x->power_mode = AW37505_CURRENT_80MA_VAL;
	}
	else if (min_uA < AW_CURRENT_150MA) {
		aw3750x->power_mode = AW37505_CURRENT_150MA_VAL;
	}
	else {
		pr_err("%s,aw3750x->power_mode failed\n", __func__);
		return -EINVAL;
	}
	reg_val = reg_val | aw3750x->power_mode;
	ret = aw3750x_i2c_bit_write(aw3750x, AW3750X_REG_APPS, AW37505_CURRENT_MASK, reg_val);
	if (ret < 0) {
		pr_err("%s,aw37505_set_current failed\n", __func__);
		return ret;
	}

	return 0;
}

static int aw3750x_set_current_limit(struct regulator_dev *rdev,
					int min_uA, int max_uA)
{
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);
	int ret = 0;

	pr_info("%s enter,aw3750x_version_id = %#x, min = %d, max = %d\n",
			__func__, aw3750x->aw3750x_version_id, min_uA, max_uA);

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID)) {
		ret = aw37501_set_current(aw3750x, min_uA, max_uA);
	}
	else if (aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID) {
		ret = aw37501b_set_current(aw3750x, min_uA, max_uA);
	}
	else if (aw3750x->aw3750x_version_id == AW37502_VERSION_ID) {
		ret = aw37502_set_current(aw3750x, min_uA, max_uA);
	}
	else if (aw3750x->aw3750x_version_id == AW37503_VERSION_ID) {
		ret = aw37503_set_current(aw3750x, min_uA, max_uA);
	}
	else if (aw3750x->aw3750x_version_id == AW37504_VERSION_ID) {
		ret = aw37504_set_current(aw3750x, min_uA, max_uA);
	}
	else if (aw3750x->aw3750x_version_id == AW37505_VERSION_ID) {
		ret = aw37505_set_current(aw3750x, min_uA, max_uA);
	}
	else {
		pr_err("%s, no chip provide.\n", __func__);
		return ret;
	}

	if (ret < 0) {
		pr_err("%s,set current failed\n", __func__);
		return ret;
	}

	return ret;
}

static int aw37501_get_current(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	pr_info("%s enter.\n", __func__);

	if ((aw3750x->read_power_mode & AW37501_CURRENT_GET) ==
		AW37501_CURRENT_40MA_VAL) {
		ret = AW_CURRENT_40MA;
	}
	else if ((aw3750x->read_power_mode & AW37501_CURRENT_GET) ==
		AW37501_CURRENT_80MA_VAL) {
		ret = AW_CURRENT_80MA;
	}
	else if ((aw3750x->read_power_mode & AW37501_CURRENT_GET) ==
		AW37501_CURRENT_100MA_VAL) {
		ret = AW_CURRENT_100MA;
	}
	else {
		pr_err("%s, no matched data val\n", __func__);
		return ret;
	}
	return ret;
}

static int aw37501b_get_current(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	pr_info("%s enter.\n", __func__);

	if ((aw3750x->read_power_mode & AW37501_CURRENT_GET) ==
		AW37501B_CURRENT_40MA_VAL) {
		ret = AW_CURRENT_40MA;
	}
	else if ((aw3750x->read_power_mode & AW37501_CURRENT_GET) ==
		AW37501B_CURRENT_80MA_VAL) {
		ret = AW_CURRENT_80MA;
	}
	else if ((aw3750x->read_power_mode & AW37501_CURRENT_GET) ==
		AW37501B_CURRENT_120MA_VAL) {
		ret = AW_CURRENT_120MA;
	}
	else if ((aw3750x->read_power_mode & AW37501_CURRENT_GET) ==
		AW37501B_CURRENT_150MA_VAL) {
		ret = AW_CURRENT_150MA;
	}
	else {
		pr_err("%s, no matched data val\n", __func__);
		return ret;
	}
	return ret;
}

static int aw37502_get_current(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	pr_info("%s enter.\n", __func__);

	if ((aw3750x->read_power_mode & AW37502_CURRENT_GET) ==
		AW37502_CURRENT_40MA_VAL) {
		ret = AW_CURRENT_40MA;
	}
	else if ((aw3750x->read_power_mode & AW37502_CURRENT_GET) ==
		AW37502_CURRENT_80MA_VAL) {
		ret = AW_CURRENT_80MA;
	}
	else if ((aw3750x->read_power_mode & AW37502_CURRENT_GET) ==
		AW37502_CURRENT_100MA_VAL) {
		ret = AW_CURRENT_100MA;
	}
	else {
		pr_err("%s, no matched data val\n", __func__);
		return ret;
	}
	return ret;
}
static int aw37503_get_current(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	pr_info("%s enter.\n", __func__);

	if ((aw3750x->read_power_mode & AW37503_CURRENT_GET) ==
		AW37503_CURRENT_80MA_VAL) {
		ret = AW_CURRENT_80MA;
	}
	else if ((aw3750x->read_power_mode & AW37503_CURRENT_GET) ==
		AW37503_CURRENT_150MA_VAL) {
		ret = AW_CURRENT_150MA;
	}
	else {
		pr_err("%s, no matched data val\n", __func__);
		return ret;
	}
	return ret;
}
static int aw37504_get_current(struct aw3750x_power *aw3750x)
{
	int ret = 0;
	u8 reg_val;

	pr_info("%s enter.\n", __func__);

	ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_CTRL, &reg_val);
	if (ret < 0) {
		pr_err("%s, aw3750x_i2c_read AW3750X_REG_CTRL\n", __func__);
		return ret;
	}
	if ((reg_val & AW37504_CURRENT_CTRL) == AW37504_CURRENT_CTRL) {
		if ((aw3750x->read_power_mode & AW37504_CURRENT_APPS) == AW37504_CURRENT_APPS) {
			ret = AW_CURRENT_220MA;
		}
		else {
			ret = AW_CURRENT_100MA;
		}
	} else {
		if ((aw3750x->read_power_mode & AW37504_CURRENT_APPS) == AW37504_CURRENT_APPS) {
			ret = AW_CURRENT_150MA;
		}
		else {
			ret = AW_CURRENT_80MA;
		}
	}
	pr_info("%s ret = %d.\n", __func__, ret);
	return ret;
}

static int aw37505_get_current(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	pr_info("%s enter.\n", __func__);

	if ((aw3750x->read_power_mode & AW37505_CURRENT_GET) ==
		AW37505_CURRENT_80MA_VAL) {
		ret = AW_CURRENT_80MA;
	}
	else if ((aw3750x->read_power_mode & AW37505_CURRENT_GET) ==
		AW37505_CURRENT_150MA_VAL) {
		ret = AW_CURRENT_150MA;
	}
	else {
		pr_err("%s, no matched data val\n", __func__);
		return ret;
	}
	return ret;
}

static int aw3750x_get_current_limit(struct regulator_dev *rdev)
{
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);
	int ret = 0;
	u8 reg_val = 0;

	pr_info("%s enter\n", __func__);

	ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_APPS, &reg_val);
	if (ret < 0) {
		pr_err("%s, aw3750x_i2c_read AW3750X_REG_APPS\n", __func__);
		return ret;
	}
	aw3750x->read_power_mode = reg_val;

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID)) {
		ret = aw37501_get_current(aw3750x);
	}
	else if (aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID) {
		ret = aw37501b_get_current(aw3750x);
	}
	else if (aw3750x->aw3750x_version_id == AW37502_VERSION_ID) {
		ret = aw37502_get_current(aw3750x);
	}
	else if (aw3750x->aw3750x_version_id == AW37503_VERSION_ID) {
		ret = aw37503_get_current(aw3750x);
	}
	else if (aw3750x->aw3750x_version_id == AW37504_VERSION_ID) {
		ret = aw37504_get_current(aw3750x);
	}
	else if (aw3750x->aw3750x_version_id == AW37505_VERSION_ID) {
		ret = aw37505_get_current(aw3750x);
	}
	pr_info("%s current mode = %d\n", __func__, ret);
	return ret;
}
static int aw3750x_is_enabled(struct regulator_dev *rdev)
{
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);
	u8 val = 0;
	int ret = -1;

	pr_info("%s enter\n", __func__);

	if (aw3750x->aw3750x_gpio_ctrl == 1) {
		if (strcmp(rdev->desc->name, "outp") == 0) {
			val = gpio_get_value(aw3750x->enp_gpio);
			return val;
		} else if (strcmp(rdev->desc->name, "outn") == 0) {
			val = gpio_get_value(aw3750x->enn_gpio);
			return val;
		} else {
			pr_err("%s regulator error.\n", __func__);
		}
	} else {
		ret = aw3750x_status_read(aw3750x, &val);
		if (ret < 0) {
			pr_err("%s, aw3750x_status_read failed\n", __func__);
			return ret;
		}
		if (strcmp(rdev->desc->name, "outp") == 0) {
			val = (val & (1 << 3)) >> 3;
			return val;
		} else if (strcmp(rdev->desc->name, "outn") == 0) {
			val = (val & (1 << 4)) >> 4;
			return val;
		}
	}
	return ret;
}
static int aw3750x_enable(struct regulator_dev *rdev)
{
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);
	int ret = 0;

	pr_info("%s enter\n", __func__);

	ret = aw3750x_is_enabled(rdev);
	if (ret == 1) {
		return 0;
	}

	if (strcmp(rdev->desc->name, "outp") == 0) {
		ret = aw3750x_enp_enable(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_enp_enable failed\n", __func__);
			return ret;
		}
	} else if (strcmp(rdev->desc->name, "outn") == 0) {
		ret = aw3750x_enn_enable(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_enn_enable failed\n", __func__);
			return ret;
		}

	} else {
		pr_err("%s, regulator enable error, rdev->desc->name = %s.\n", __func__, rdev->desc->name);
		return -EINVAL;
	}

	return 0;
}

static int aw3750x_disable(struct regulator_dev *rdev)
{
	struct aw3750x_power *aw3750x = rdev_get_drvdata(rdev);
	int ret = 0;

	pr_info("%s enter\n", __func__);

	ret = aw3750x_is_enabled(rdev);
	if (ret == 0) {
		return 0;
	}
	if (strcmp(rdev->desc->name, "outp") == 0) {
		ret = aw3750x_enp_disable(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_enp_disable failed\n", __func__);
			return ret;
		}
	} else if (strcmp(rdev->desc->name, "outn") == 0) {
		ret = aw3750x_enn_disable(aw3750x);
		if (ret < 0) {
			pr_err("%s, aw3750x_enn_disable failed\n", __func__);
			return ret;
		}
	} else {
		pr_err("%s, regulator disable error\n", __func__);
		return -EINVAL;
	}

	return 0;
}
int aw3750x_map_voltage(struct regulator_dev *rdev,
				 int min_uV, int max_uV)
{
	int i, ret;

	pr_info("%s enter\n", __func__);

	for (i = 0; i < rdev->desc->n_voltages; i++) {
		ret = rdev->desc->ops->list_voltage(rdev, i);
		if (ret < 0) {
			continue;
		}
		if (ret > max_uV) {
			break;
		}

		if (ret >= min_uV && ret <= max_uV) {
			return i;
		}
	}

	return -EINVAL;
}
static struct regulator_ops aw3750x_outp_ops = {
	.list_voltage = aw3750x_list_voltage,
	.set_voltage = aw3750x_set_voltage,
	.get_voltage = aw3750x_get_voltage,
	.set_current_limit = aw3750x_set_current_limit,
	.get_current_limit = aw3750x_get_current_limit,
	.map_voltage = aw3750x_map_voltage,
	.enable = aw3750x_enable,
	.disable = aw3750x_disable,
	.is_enabled = aw3750x_is_enabled,
};
static struct regulator_ops aw3750x_outn_ops = {
	.list_voltage = aw3750x_list_voltage,
	.set_voltage = aw3750x_set_voltage,
	.get_voltage = aw3750x_get_voltage,
	.set_current_limit = aw3750x_set_current_limit,
	.get_current_limit = aw3750x_get_current_limit,
	.map_voltage = aw3750x_map_voltage,
	.enable = aw3750x_enable,
	.disable = aw3750x_disable,
	.is_enabled = aw3750x_is_enabled,
};

static struct regulator_desc aw3750x_desc[] = {
	{
		.name = "outp",
		.id = 0,
		.n_voltages = N_VOLTAGE,
		.min_uV = MIN_VOLTAGE,
		.uV_step = UV_STEP,
		.linear_min_sel = 0,
		.ops = &aw3750x_outp_ops,
		.type = REGULATOR_VOLTAGE,
		.owner = THIS_MODULE,
	},
	{
		.name = "outn",
		.id = 1,
		.n_voltages = N_VOLTAGE,
		.min_uV = MIN_VOLTAGE,
		.uV_step = UV_STEP,
		.linear_min_sel = 0,
		.ops = &aw3750x_outn_ops,
		.type = REGULATOR_VOLTAGE,
		.owner = THIS_MODULE,
	},
};

static int aw3750x_pinctrl_init(struct aw3750x_power *aw3750x)
{
	struct aw3750x_pinctrl *pinctrl = &aw3750x->pinctrl;

	pinctrl->pinctrl = devm_pinctrl_get(aw3750x->dev);
	if (IS_ERR_OR_NULL(pinctrl->pinctrl)) {
		pr_info("%s:No pinctrl found\n", __func__);
		pinctrl->pinctrl = NULL;
		return 0;
	}
	/* for enn */
	pinctrl->aw_enn_default = pinctrl_lookup_state(pinctrl->pinctrl,
						       "aw_enn_default");
	if (IS_ERR_OR_NULL(pinctrl->aw_enn_default)) {
		pr_info("%s: Failed get pinctrl state:enn default state\n",
			__func__);
		goto exit_pinctrl_init;
	}

	pinctrl->aw_enn_high = pinctrl_lookup_state(pinctrl->pinctrl,
						    "aw_enn_output_high");
	if (IS_ERR_OR_NULL(pinctrl->aw_enn_high)) {
		pr_info("%s: Failed get pinctrl state:enn_high\n", __func__);
		goto exit_pinctrl_init;
	}

	pinctrl->aw_enn_low = pinctrl_lookup_state(pinctrl->pinctrl,
						   "aw_enn_output_low");
	if (IS_ERR_OR_NULL(pinctrl->aw_enn_low)) {
		pr_info("%s: Failed get pinctrl state:enn_low\n", __func__);
		goto exit_pinctrl_init;
	}
	/* for enp */
	pinctrl->aw_enp_default = pinctrl_lookup_state(pinctrl->pinctrl,
						       "aw_enp_default");
	if (IS_ERR_OR_NULL(pinctrl->aw_enp_default)) {
		pr_info("%s: Failed get pinctrl state:enp default state\n",
			__func__);
		goto exit_pinctrl_init;
	}

	pinctrl->aw_enp_high = pinctrl_lookup_state(pinctrl->pinctrl,
						    "aw_enp_output_high");
	if (IS_ERR_OR_NULL(pinctrl->aw_enp_high)) {
		pr_info("%s: Failed get pinctrl state:enp_high\n", __func__);
		goto exit_pinctrl_init;
	}

	pinctrl->aw_enp_low = pinctrl_lookup_state(pinctrl->pinctrl,
						    "aw_enp_output_low");
	if (IS_ERR_OR_NULL(pinctrl->aw_enp_low)) {
		pr_info("%s: Failed get pinctrl state:enp_low\n", __func__);
		goto exit_pinctrl_init;
	}
	pr_info("%s: Success init pinctrl\n", __func__);
	return 0;
 exit_pinctrl_init:
	devm_pinctrl_put(pinctrl->pinctrl);
	return -EINVAL;
}

static void aw3750x_pinctrl_deinit(struct aw3750x_power *aw3750x)
{
	if (aw3750x->pinctrl.pinctrl)
		devm_pinctrl_put(aw3750x->pinctrl.pinctrl);
}

/***************************sys attribute*********************************/
static ssize_t aw3750x_reg_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);

	unsigned char i = 0, reg_val = 0;
	ssize_t len = 0;
	int ret = 0;

	pr_info("%s\n", __func__);

	for (i = 0; i < AW3750X_REG_MAX; i++) {
		if (!(aw3750x_reg_access[i] & REG_RD_ACCESS)) {
			continue;
		}
		ret = aw3750x_i2c_read(aw3750x, i, &reg_val);
		if (ret < 0) {
			pr_err("aw3750x_i2c_read failed,ret = %d\n", ret);
			break;
		}
		len += snprintf(buf+len, PAGE_SIZE-len, "reg:0x%02x=0x%02x\n",
				i, reg_val);
	}

	return len;
}

static ssize_t aw3750x_reg_store(struct device *dev,
			     struct device_attribute *attr,
			     const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);

	unsigned int databuf[2] = {0};

	pr_info("%s\n", __func__);

	if (sscanf(buf, "%x %x", &databuf[0], &databuf[1]) == 2) {
		aw3750x_i2c_write(aw3750x, (unsigned char)databuf[0],
				       (unsigned char)databuf[1]);
	}

	return len;
}

static ssize_t aw3750x_power_outp_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int ret = 0;
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);

	pr_info("%s\n", __func__);

	ret = aw3750x->regulators[0]
		     ->desc->ops->get_voltage(aw3750x->regulators[0]);
	if (ret < 0) {
		pr_err("get_voltage_sel failed,ret = %d\n", ret);
		return ret;
	}

	len += snprintf(buf + len, PAGE_SIZE - len, "outp : %d\n", ret);

	return len;
}

static ssize_t aw3750x_power_outp_store(struct device *dev,
					struct device_attribute *attr,
					const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	unsigned int databuf[1] = {0};

	pr_info("%s\n", __func__);

	if (sscanf(buf, "%x", &databuf[0]) == 1) {
		if (databuf[0] >= MIN_VOLTAGE_VAL && databuf[0] <= MAX_VOLTAGE_VAL) {
			aw3750x->outp = aw3750x_get_voltage_by_reg(aw3750x, databuf[0]);
			ret = aw3750x->regulators[0]->desc->ops->set_voltage(aw3750x->regulators[0],
			aw3750x->outp, aw3750x->outp, NULL);
			if (ret < 0) {
				dev_err(dev, "%s set_voltage_sel error\n", __func__);
				return ret;
			}
		}
	}

	pr_info("%s exit \n", __func__);

	return len;
}

static ssize_t aw3750x_power_outn_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int ret = 0;
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);

	pr_info("%s\n", __func__);

	ret = aw3750x->regulators[1]
		     ->desc->ops->get_voltage(aw3750x->regulators[1]);
	if (ret < 0 && ret > -MIN_VOLTAGE) {
		dev_err(dev, "%s get_voltage_sel failed\n", __func__);
		return ret;
	}
	len += snprintf(buf + len, PAGE_SIZE - len, "outn : %d\n", -ret);

	return len;
}

static ssize_t aw3750x_power_outn_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	unsigned int databuf[1] = {0};

	pr_info("%s\n", __func__);

	if (sscanf(buf, "%x", &databuf[0]) == 1) {
		if (databuf[0] >= MIN_VOLTAGE_VAL && databuf[0] <= MAX_VOLTAGE_VAL) {
			aw3750x->outn = aw3750x_get_voltage_by_reg(aw3750x, databuf[0]);
			ret = aw3750x->regulators[1]->desc->ops->set_voltage(aw3750x->regulators[1],
			aw3750x->outn, aw3750x->outn, NULL);
			if (ret < 0) {
				dev_err(dev, "%s set_voltage_sel error\n",
					__func__);
				return ret;
			}
		}
	}

	pr_info("%s exit \n", __func__);

	return len;
}

static ssize_t aw3750x_enn_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;

	pr_info("%s\n", __func__);

	ret = aw3750x->regulators[1]
		     ->desc->ops->is_enabled(aw3750x->regulators[1]);
	if (ret < 0) {
		dev_err(dev, "%s is_enabled error\n", __func__);
		return ret;
	}

	len += snprintf(buf + len, PAGE_SIZE - len, "outn status: %d\n", ret);

	return len;
}

static ssize_t aw3750x_enn_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int val = 0;

	pr_info("%s\n", __func__);

	ret = kstrtouint(buf, 0, &val);
	if (ret < 0) {
		dev_err(dev, "%s kstrtouint failed\n", __func__);
		return ret;
	}

	if (val == 1) {
		ret = aw3750x->regulators[1]
			     ->desc->ops->enable(aw3750x->regulators[1]);
		if (ret < 0) {
			dev_err(dev, "%s enable error\n", __func__);
			return ret;
		}
	} else if (val == 0) {
		ret = aw3750x->regulators[1]
			     ->desc->ops->disable(aw3750x->regulators[1]);
		if (ret < 0) {
			dev_err(dev, "%s disable error\n", __func__);
			return ret;
		}
	} else {
		dev_err(dev, "%s input val error\n", __func__);
		return -EINVAL;
	}

	return len;
}

static ssize_t aw3750x_enp_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{

	ssize_t len = 0;
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;

	pr_info("%s\n", __func__);

	ret = aw3750x->regulators[0]
		     ->desc->ops->is_enabled(aw3750x->regulators[0]);
	if (ret < 0) {
		dev_err(dev, "%s is_enabled error\n", __func__);
		return ret;
	}

	len += snprintf(buf + len, PAGE_SIZE - len, "outp status: %d\n", ret);

	return len;
}

static ssize_t aw3750x_enp_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int val = 0;

	pr_info("%s\n", __func__);

	ret = kstrtouint(buf, 10, &val);
	if (ret < 0) {
		dev_err(dev, "%s kstrtouint failed\n", __func__);
		return ret;
	}
	pr_info("%s val = %d\n", __func__, val);

	if (val == 1) {
		ret = aw3750x->regulators[0]
			     ->desc->ops->enable(aw3750x->regulators[0]);
		if (ret < 0) {
			dev_err(dev, "%s enable error\n", __func__);
			return ret;
		}
	} else if (val == 0) {
		ret = aw3750x->regulators[0]
			     ->desc->ops->disable(aw3750x->regulators[0]);
		if (ret < 0) {
			dev_err(dev, "%s disable error\n", __func__);
			return ret;
		}
	} else {
		dev_err(dev, "%s input val error\n", __func__);
		return -EINVAL;
	}

	return len;
}

static ssize_t aw3750x_current_mode_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int ret = 0;
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);

	pr_info("%s\n", __func__);

	ret = aw3750x->regulators[0]
		     ->desc->ops->get_current_limit(aw3750x->regulators[0]);
	if (ret < 0) {
		dev_err(dev, "%s get_current_limit error\n", __func__);
		return ret;
	}
	len += snprintf(buf + len, PAGE_SIZE - len, "modes: %d\n", ret);

	return len;
}

static ssize_t aw3750x_current_mode_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int databuf[2] = {0};

	pr_info("%s\n", __func__);

	if (sscanf(buf, "%d %d", &databuf[0], &databuf[1]) == 2) {
		ret = aw3750x->regulators[0]->desc->ops->
				set_current_limit(aw3750x->regulators[0],
						  databuf[0], databuf[1]);
		if (ret < 0) {
			dev_err(dev, "%s set_current_limit error\n", __func__);
			return ret;
		}
	}

	return len;
}

static ssize_t aw3750x_disn_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int val = 0;

	ret = kstrtouint(buf, 0, &val);
	if (ret < 0) {
		dev_err(dev, "%s kstrtouint failed\n", __func__);
		return ret;
	}
	if (val > 0) {
		ret = aw3750x_disn_enable(aw3750x);
		if (ret < 0) {
			dev_err(dev, "%s aw3750x_disn_enable error\n",
				__func__);
			return ret;
		}
	} else if (val == 0) {
		ret = aw3750x_disn_disable(aw3750x);
		if (ret < 0) {
			dev_err(dev, "%s aw3750x_disn_disable error\n",
				__func__);
			return ret;
		}
	} else {
		return -EINVAL;
	}
	return len;
}

static ssize_t aw3750x_disp_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int val = 0;

	ret = kstrtouint(buf, 0, &val);
	if (ret < 0) {
		dev_err(dev, "%s kstrtouint failed\n", __func__);
		return ret;
	}
	if (val > 0) {
		ret = aw3750x_disp_enable(aw3750x);
		if (ret < 0) {
			dev_err(dev, "%s aw3750x_disp_enable error\n",
				__func__);
			return ret;
		}
	} else if (val == 0) {
		ret = aw3750x_disp_disable(aw3750x);
		if (ret < 0) {
			dev_err(dev, "%s aw3750x_disp_disable error\n",
				__func__);
			return ret;
		}
	} else {
		return -EINVAL;
	}
	return len;
}

static ssize_t aw3750x_listoutp_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int val = 0;

	ret = kstrtouint(buf, 10, &val);
	if (ret < 0) {
		dev_err(dev, "%s kstrtouint failed\n", __func__);
		return ret;
	}
	if (val < 0 || val >= N_VOLTAGE) {
		dev_err(dev, "%s,error n_voltage = %d\n", __func__, val);
		return -EINVAL;
	}

	ret =
	aw3750x->regulators[0]->desc->ops->list_voltage(aw3750x->regulators[0],
							val);
	if (ret < 0) {
		dev_err(dev, "%s list_voltage error\n", __func__);
		return ret;
	}
	pr_info("%s, list_voltage result = %d\n", __func__, ret);
	return len;
}

static ssize_t aw3750x_listoutn_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int val = 0;

	pr_info("%s,enter\n", __func__);
	ret = kstrtouint(buf, 10, &val);
	if (ret < 0) {
		dev_err(dev, "%s kstrtouint failed\n", __func__);
		return ret;
	}
	if (val < 0 || val >= N_VOLTAGE)
		return -EINVAL;

	ret =
	aw3750x->regulators[1]->desc->ops->list_voltage(aw3750x->regulators[1],
							val);
	if (ret < 0) {
		dev_err(dev, "%s list_voltage error\n", __func__);
		return ret;
	}
	pr_info("%s, list_voltage result = %d\n", __func__, ret);
	return len;
}

static ssize_t aw3750x_reset_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t len)
{
	struct aw3750x_power *aw3750x = dev_get_drvdata(dev);
	int ret = 0;
	int val = 0;

	pr_info("%s,enter\n", __func__);
	ret = kstrtouint(buf, 0, &val);
	if (ret < 0) {
		dev_err(dev, "%s kstrtouint failed\n", __func__);
		return ret;
	}

	if (val == 1) {
		ret = aw3750x_soft_reset(aw3750x);
		if (ret < 0) {
			dev_err(dev, "%s aw3750x_soft_reset error\n", __func__);
			return ret;
		}
	} else {
		return -EINVAL;
	}
	return len;
}

static DEVICE_ATTR(reg, 0664, aw3750x_reg_show, aw3750x_reg_store);
static DEVICE_ATTR(outp, 0664, aw3750x_power_outp_show,
			       aw3750x_power_outp_store);
static DEVICE_ATTR(outn, 0664, aw3750x_power_outn_show,
			       aw3750x_power_outn_store);
static DEVICE_ATTR(enn, 0664, aw3750x_enn_show, aw3750x_enn_store);
static DEVICE_ATTR(enp, 0664, aw3750x_enp_show, aw3750x_enp_store);
static DEVICE_ATTR(current_mode, 0664, aw3750x_current_mode_show,
				       aw3750x_current_mode_store);
static DEVICE_ATTR(disn, 0664, NULL, aw3750x_disn_store);
static DEVICE_ATTR(disp, 0664, NULL, aw3750x_disp_store);
static DEVICE_ATTR(list_outp, 0664, NULL, aw3750x_listoutp_store);
static DEVICE_ATTR(list_outn, 0664, NULL, aw3750x_listoutn_store);
static DEVICE_ATTR(reset, 0664, NULL, aw3750x_reset_store);

static struct attribute *aw3750x_power_attributes[] = {
	&dev_attr_reg.attr,
	&dev_attr_outp.attr,
	&dev_attr_outn.attr,
	&dev_attr_enn.attr,
	&dev_attr_enp.attr,
	&dev_attr_current_mode.attr,
	&dev_attr_disn.attr,
	&dev_attr_disp.attr,
	&dev_attr_list_outp.attr,
	&dev_attr_list_outn.attr,
	&dev_attr_reset.attr,
	NULL,
};

static struct attribute_group aw3750x_power_attr_group = {
	.attrs = aw3750x_power_attributes
};

/* *********************************driver********************************* */
static int aw3750x_release_load_capability(struct aw3750x_power *aw3750x)
{
	u8 reg_val = 0;

	pr_info("%s\n", __func__);

	aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO2, AW3750X_OPEN_CMD2);

	if ((aw3750x->aw3750x_version_id == AW37501_VERSION_ID) |
		(aw3750x->aw3750x_version_id == AW37501A_VERSION_ID)) {
		reg_val = AW37501_LOAD_CAPABILITY;
	}
	else if (aw3750x->aw3750x_version_id == AW37501B_DEVICE_ID) {
		return 0;
	}
	else if (aw3750x->aw3750x_version_id == AW37502_VERSION_ID) {
		reg_val = AW37502_LOAD_CAPABILITY;
	}
	else if (aw3750x->aw3750x_version_id == AW37503_VERSION_ID) {
		reg_val = AW37503_LOAD_CAPABILITY;
	}
	else if (aw3750x->aw3750x_version_id == AW37504_VERSION_ID) {
		reg_val = AW37504_LOAD_CAPABILITY;
	}
	else if (aw3750x->aw3750x_version_id == AW37505_VERSION_ID) {
		return 0;
	}
	else {
		pr_err("%s, device not compatiable.\n", __func__);
		return -EINVAL;
	}
	aw3750x_i2c_write(aw3750x, AW3750X_REG_VERSION, reg_val);

	aw3750x_i2c_write(aw3750x, AW3750X_REG_PRO2, AW3750X_CLOSE_CMD);
	return 0;
}
static int aw3750x_power_init(struct aw3750x_power *aw3750x)
{
	int ret = 0;

	pr_info("%s\n", __func__);

	/* LDO output current limit value configure*/
	ret = aw3750x_ldo_current_set(aw3750x);
	if (ret < 0) {
		dev_err(aw3750x->dev, "%s aw3750x_ldo_current_set error\n",
			__func__);
		return ret;
	}

	/* Output voltage of LDO */
	ret = aw3750x_voltage_outp_set(aw3750x);
	if (ret < 0) {
		dev_err(aw3750x->dev, "%s aw3750x_voltage_outp_set error\n",
			__func__);
		return ret;
	}

	/* Output voltage of CHARGE PUMP */
	ret = aw3750x_voltage_outn_set(aw3750x);
	if (ret < 0) {
		dev_err(aw3750x->dev, "%s aw3750x_voltage_outn_set error\n",
			__func__);
		return ret;
	}
	/*Release on load starting capability*/
	ret = aw3750x_release_load_capability(aw3750x);
	if (ret < 0) {
		dev_err(aw3750x->dev, "%s aw3750x_release_load_capability error\n",
			__func__);
		return ret;
	}

	return 0;
}

static int
aw3750x_gpio_init(struct aw3750x_power *aw3750x, struct i2c_client *i2c)
{
	int ret;

	pr_info("%s enter\n", __func__);
	ret = aw3750x_pinctrl_init(aw3750x);
	if (ret < 0) {
		pr_err("%s: Failed get wanted pinctrl state\n", __func__);
		return ret;
	}
	ret = pinctrl_select_state(aw3750x->pinctrl.pinctrl,
					     aw3750x->pinctrl.aw_enn_high);
	if (ret < 0) {
		pr_err("%s: pinctrl_select_state failed for aw_enn_high\n",
			__func__);
		return ret;
	}
	ret = pinctrl_select_state(aw3750x->pinctrl.pinctrl,
					     aw3750x->pinctrl.aw_enp_high);
	if (ret < 0) {
		pr_err("%s: pinctrl_select_state failed for aw_enp_high\n",
			__func__);
		return ret;
	}
	return 0;
}

static int
aw3750x_parse_dt(struct i2c_client *i2c, struct aw3750x_power *aw3750x,
		 struct device_node *np)
{
	int rc = 0;
	struct device *dev = &i2c->dev;
	const char *label;
	struct device_node *temp;

	pr_info("%s enter\n", __func__);

	rc = of_property_read_u32(np, "aw3750x_gpio_ctrl",
					&aw3750x->aw3750x_gpio_ctrl);
	if (rc < 0) {
		dev_err(&aw3750x->client->dev,
			"Failure reading aaw3750x_gpio_ctrl, rc = %d\n", rc);
	}

	if (aw3750x->aw3750x_gpio_ctrl == 1) {
		aw3750x->enn_gpio = of_get_named_gpio(np, "enn-gpio", 0);
		if (gpio_is_valid(aw3750x->enn_gpio)) {
			dev_info(dev, "%s: enn gpio provided ok.\n", __func__);
		} else {
			dev_err(dev, "%s: no enn gpio provided.\n", __func__);
			return -EIO;
		}

		aw3750x->enp_gpio = of_get_named_gpio(np, "enp-gpio", 0);
		if (gpio_is_valid(aw3750x->enp_gpio)) {
			dev_info(dev, "%s: enp gpio provided ok.\n", __func__);
		} else {
			dev_err(dev, "%s: no enp gpio provided.\n", __func__);
			return -EIO;
		}

		rc = aw3750x_gpio_init(aw3750x, i2c);
		if (rc < 0) {
			dev_err(&aw3750x->client->dev,
				"aw3750x_gpio_init failed, rc = %d\n", rc);
			return rc;
		}
		pr_info("%s: ctrl by gpio\n", __func__);
	} else {
		pr_info("%s: ctrl by IIC\n", __func__);
	}

	rc = of_property_read_u32(np, "outp", &aw3750x->outp_set);
	if (rc < 0) {
		dev_err(&aw3750x->client->dev,
			"Failure reading outp, rc = %d\n", rc);
		goto read_err;
	} else {
		pr_info("%s,outp = %#x\n",  __func__, aw3750x->outp_set);
	}

	rc = of_property_read_u32(np, "outn", &aw3750x->outn_set);
	if (rc < 0) {
		dev_err(&aw3750x->client->dev,
			"Failure reading outn, rc = %d\n", rc);
		goto read_err;
	} else {
		pr_info("%s,outn = %#x\n", __func__, aw3750x->outn_set);
	}

	rc = of_property_read_u32(np, "limit", &aw3750x->limit);
	if (rc < 0) {
		dev_err(&aw3750x->client->dev,
			"Failure reading limit, rc = %d\n", rc);
		goto read_err;
	} else {
		pr_info("%s,power limit = %d\n", __func__, aw3750x->limit);
	}

	for_each_available_child_of_node(np, temp) {
		rc = of_property_read_string(temp, "label", &label);
		if (rc < 0) {
			pr_err("%s, Failed to read label rc=%d\n", __func__, rc);
			return rc;
		}
		if (strcmp(label, "outp") == 0) {
			aw3750x->aw_node[0] = temp;
			pr_info("%s,lable for ldo found.\n", __func__);
		} else if (strcmp(label, "outn") == 0) {
			aw3750x->aw_node[1] = temp;
			pr_info("%s,lable for ncp found.\n", __func__);
		} else {
			pr_err("%s, Failed to identify label %s\n", __func__, label);
			return -EINVAL;
		}
	}

	return 0;
read_err:
	if (aw3750x->aw3750x_gpio_ctrl == 1)
		aw3750x_pinctrl_deinit(aw3750x);
	return rc;
}
static int aw3750x_i2c_read_vendor_id(struct aw3750x_power *aw3750x)
{
	int ret;
	u8 val;

	ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_CTRL, &val);
	aw3750x->vendorID = val & AW3750x_VENDOR_ID_MASK;
	if (ret < 0) {
		pr_err("aw3750x_i2c_read failed,ret = %d\n", ret);
		return ret;
	}
	pr_info("aw3750x read vendor id = %#x\n", aw3750x->vendorID);
	if (aw3750x->vendorID != AW3750x_VENDOR_ID) {
		pr_err("%s read vendor ID error!\n", __func__);
		return -EINVAL;
	}
	return 0;
}
static int aw3750x_i2c_read_chipid(struct aw3750x_power *aw3750x)
{
	int ret;
	u8 val;
	u8 reg_val;

	ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_VERSION, &val);
	if (ret < 0) {
		pr_err("aw3750x_i2c_read failed,ret = %d\n", ret);
		return ret;
	}

	if (val == AW37501_VERSION_ID) {
		aw3750x->aw3750x_version_id = val;
		pr_info("%s,aw37501, chip version = 0x%02x\n", __func__, val);
	} else if (val == AW37502_VERSION_ID) {
		aw3750x->aw3750x_version_id = val;
		pr_info("%s,aw37502, chip version = 0x%02x\n", __func__, val);
	} else if (val == AW37503_VERSION_ID || val == AW37503_LOAD_CAPABILITY) {
		ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_TRIM, &reg_val);
		if (ret < 0) {
			pr_err("aw3750x_i2c_read failed,ret = %d\n", ret);
			return ret;
		}
		if ((reg_val & AW37504_VERSION_ID) == AW37504_VERSION_ID) {
			aw3750x->aw3750x_version_id = reg_val & AW37504_VERSION_ID;
			pr_info("%s,aw37504, chip version = 0x%02x.\n", __func__, aw3750x->aw3750x_version_id);
			aw3750x_set_current();
		} else {
			aw3750x->aw3750x_version_id = AW37503_VERSION_ID;
			pr_info("%s,aw37503, chip version = 0x%02x\n", __func__, val);
		}
	} else if (val == AW37501A_VERSION_ID) {
		aw3750x->aw3750x_version_id = val;
		pr_info("%s,aw37501a, chip version = 0x%02x.\n", __func__, aw3750x->aw3750x_version_id);
	} else if (val == AW37505_VERSION_ID) {
		aw3750x->aw3750x_version_id = val;
		pr_info("%s,aw37505, chip version = 0x%02x.\n", __func__, aw3750x->aw3750x_version_id);
	} else {
		ret = aw3750x_i2c_read(aw3750x, AW3750X_REG_DEVID, &val);
		if (ret < 0) {
			pr_err("aw3750x_i2c_read failed,ret = %d\n", ret);
			return ret;
		}
		if (val == AW37501B_DEVICE_ID) {
			aw3750x->aw3750x_version_id = val;
			pr_info("%s,aw37501b, chip version = 0x%02x.\n", __func__, aw3750x->aw3750x_version_id);
		} else {
			pr_info("%s, no chip provide,val = %#x.\n", __func__, val);
			return -EINVAL;
		}
	}

	return 0;
}

static int aw3750x_power_probe(struct i2c_client *i2c,
			   const struct i2c_device_id *id)
{
	int ret = 0;
	int i;
	struct aw3750x_power *aw3750x = NULL;
	struct device_node *node = i2c->dev.of_node;

	pr_info("%s\n", __func__);

	if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_I2C)) {
		dev_err(&i2c->dev, "check_functionality failed\n");
		return -EIO;
	}

	aw3750x = devm_kzalloc(&i2c->dev,
			(sizeof(struct aw3750x_power)), GFP_KERNEL);
	if (!aw3750x) {
		pr_err("%s devm_kzalloc failed\n", __func__);
		return -ENOMEM;
	}

	g_aw3750x = aw3750x;

	aw3750x->dev = &i2c->dev;
	aw3750x->client = i2c;

	if (node) {
		ret = aw3750x_parse_dt(i2c, aw3750x, node);
		if (ret < 0) {
			pr_err("%s aw3750x_parse_dt failed\n", __func__);
			goto chip_error;
		}
	} else {
		pr_err("%s, failed device node is null!\n", __func__);
		goto chip_error;
	}

	i2c_set_clientdata(i2c, aw3750x);

	ret = aw3750x_i2c_read_vendor_id(aw3750x);
	if (ret < 0) {
		pr_err("%s soft reset failed.\n", __func__);
		goto chip_error;
	}

	ret = aw3750x_i2c_read_chipid(aw3750x);
	if (ret < 0) {
		pr_err("%s, aw3750x_i2c_read_chipid failed!\n", __func__);
		goto chip_error;
	}
	for (i = 0; i < ARRAY_SIZE(aw3750x_desc); i++) {

		struct regulator_desc *desc = &aw3750x_desc[i];
		struct regulator_init_data *init = NULL;
		struct regulator_config config = { };

		if (&aw3750x->aw_node[i] == NULL) {
			dev_err(&i2c->dev, " %s aw3750x->aw_node[%d] is NULL.\n",
				__func__, i);
			break;
		}
		init = of_get_regulator_init_data(&i2c->dev, aw3750x->aw_node[i], &desc[i]);

		if (init == NULL) {
			dev_err(&i2c->dev, " %s Failed to get init_data %s\n",
				__func__, desc->name);
			of_node_put(node);
			goto regulator_error;
		}

		config.dev = &i2c->dev;
		config.init_data = init;
		config.driver_data = aw3750x;
		config.of_node = aw3750x->aw_node[i];

		aw3750x->regulators[i] = devm_regulator_register(&i2c->dev,
								 desc, &config);
		if (IS_ERR(aw3750x->regulators[i])) {
			ret = PTR_ERR(aw3750x->regulators[i]);
			dev_err(&i2c->dev, "failed to register regulator %s:%d\n",
				desc->name, ret);
			goto regulator_error;
		}
	}

	ret = sysfs_create_group(&aw3750x->dev->kobj,
				&aw3750x_power_attr_group);
	if (ret < 0) {
		dev_err(&aw3750x->client->dev, "power sysfs ret: %d\n", ret);
		goto regulator_error;
	}

	ret = aw3750x_power_init(aw3750x);
	if (ret < 0) {
		dev_err(&aw3750x->client->dev, "%s,aw3750x_power_init failed\n",
			__func__);
		goto init_error;
	}

	lcd_kit_bias_register(&bias_ops);

	pr_info("%s exit.\n", __func__);

	return 0;
init_error:
	sysfs_remove_group(&aw3750x->dev->kobj,
					&aw3750x_power_attr_group);
regulator_error:
	while (--i >= 0)
		regulator_unregister(aw3750x->regulators[i]);
chip_error:
	devm_kfree(&i2c->dev, aw3750x);
	aw3750x = NULL;
	return ret;
}

static int aw3750x_power_remove(struct i2c_client *i2c)
{
	struct aw3750x_power *aw3750x = i2c_get_clientdata(i2c);
	int i = 2;

	pr_info("%s\n", __func__);
	sysfs_remove_group(&aw3750x->dev->kobj, &aw3750x_power_attr_group);
	while (--i >= 0)
		devm_regulator_unregister(aw3750x->dev, aw3750x->regulators[i]);

	if (aw3750x->aw3750x_gpio_ctrl == 1)
		aw3750x_pinctrl_deinit(aw3750x);

	devm_kfree(&i2c->dev, aw3750x);
	aw3750x = NULL;
	return 0;
}

static const struct i2c_device_id aw3750x_power_id[] = {
	{"aw3750x_led", 0},
	{},
};

MODULE_DEVICE_TABLE(i2c, aw3750x_power_id);

static const struct of_device_id aw3750x_match_table[] = {
	{.compatible = "awinic,aw3750x_led",},
	{ },
};

static struct i2c_driver aw3750x_power_driver = {
	.driver = {
		.name = "aw3750x_led",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(aw3750x_match_table),
	},
	.probe = aw3750x_power_probe,
	.remove = aw3750x_power_remove,
	.id_table = aw3750x_power_id,
};

static int __init aw3750x_module_init(void)
{
	pr_info("%s: driver version: %s\n", __func__, AW3750X_DRIVER_VERSION);
	return i2c_add_driver(&aw3750x_power_driver);
}
module_init(aw3750x_module_init);

static void __exit aw3750x_module_exit(void)
{
	i2c_del_driver(&aw3750x_power_driver);
}
module_exit(aw3750x_module_exit);

MODULE_AUTHOR("<shiqiang@awinic.com>");
MODULE_DESCRIPTION("Awinic AW3750X Power driver");
MODULE_LICENSE("GPL v2");

