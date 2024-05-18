/*
* aw3750x.c
*
* Copyright (c) 2021-2022 AWINIC Technology CO., LTD
*
* Author: Alex <shiqiang@awinic.com>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*/
#include "aw3750x.h"
#include "lcd_kit_common.h"
#include "lcd_kit_bias.h"
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#endif

#ifdef MTK_LCD_KIT_LK2_SUPPORT
#include <libfdt.h>
#include <platform_mtk.h>
#include <platform.h>
#include <gpio_api.h>
#include <mt_i2c.h>
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array)	((sizeof(array)) / (sizeof(array[0])))
#endif
#else
#include <fdt_op.h>
#include <platform/mt_i2c.h>
#endif

#define AW3750X_DRIVER_VERSION	"V0.1.0"
#define BIAS_TRUE 1
#define BIAS_FALSE 0

#define AW3750X_SLAV_ADDR 0x3E
#define AW3750X_I2C_SPEED 100
#define AW3750X_CMD_LEN_ONE 1
#define AW3750X_CMD_LEN_TWO 2
#define CHECK_STATUS_FAIL 0
#define CHECK_STATUS_OK 1
#define OUTN 0
#define OUTP 1

static unsigned int i2c_bus_id;
static unsigned int check_status;
static unsigned char vpos_cmd;
static unsigned char vneg_cmd;
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

static int aw3750x_i2c_read_u8(unsigned char addr, unsigned char *databuffer)
{
	int ret;
	unsigned char len;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c aw3750x_i2c = {0};
#else
	struct mt_i2c_t aw3750x_i2c = {0};
#endif

	*databuffer = addr;
	aw3750x_i2c.id = i2c_bus_id;
	aw3750x_i2c.addr = AW3750X_SLAV_ADDR;
	len = AW3750X_CMD_LEN_ONE;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(aw3750x_i2c.id, aw3750x_i2c.addr, databuffer, len, len, NULL);
#else
	aw3750x_i2c.mode = ST_MODE;
	aw3750x_i2c.speed = AW3750X_I2C_SPEED;
	aw3750x_i2c.st_rs = I2C_TRANS_REPEATED_START;
	ret = i2c_write_read(&aw3750x_i2c, databuffer, len, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("%s: i2c_read  failed, reg is 0x%x ret: %d\n", __func__, addr, ret);
	}

	return ret;
}

static int aw3750x_i2c_write_u8(unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[AW3750X_CMD_LEN_TWO] = {0};
	unsigned char len;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c aw3750x_i2c = {0};
#else
	struct mt_i2c_t aw3750x_i2c = {0};
#endif

	write_data[0] = addr;
	write_data[1] = value;

	aw3750x_i2c.id = i2c_bus_id;
	aw3750x_i2c.addr = AW3750X_SLAV_ADDR;
	len = AW3750X_CMD_LEN_TWO;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(aw3750x_i2c.id, aw3750x_i2c.addr, write_data, len, NULL);
#else
	aw3750x_i2c.mode = ST_MODE;
	aw3750x_i2c.speed = aw3750x_I2C_SPEED;
	ret = i2c_write(&aw3750x_i2c, write_data, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("%s: i2c_write  failed, reg is  0x%x ret: %d\n", __func__, addr, ret);
	}

	return ret;
}

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

static int aw3750x_voltage_set(unsigned char is_outp, unsigned char reg_val)
{
	int ret = 0;

	if (is_outp) {
		ret = aw3750x_i2c_write_u8(AW3750X_REG_VOUTP, reg_val);
	} else {
		ret = aw3750x_i2c_write_u8(AW3750X_REG_VOUTN, reg_val);
	}

	return ret;
}

static int aw3750x_set_bias(int vpos, int vneg)
{
	int ret;

	aw3750x_get_target_voltage(vpos, vneg);

	LCD_KIT_INFO("set voltage outp:0x%x outn:0x%x\n", vpos_cmd, vneg_cmd);
	ret = aw3750x_voltage_set(OUTP, vpos_cmd);
	if (ret < 0) {
		LCD_KIT_ERR("%s, aw3750x voltage outp set error\n", __func__);
		return ret;
	}

	ret = aw3750x_voltage_set(OUTN, vneg_cmd);
	if (ret < 0) {
		LCD_KIT_ERR("%s, aw3750x voltage outn set error\n", __func__);
		return ret;
	}

	return LCD_KIT_OK;
}

static int aw3750x_soft_reset()
{
	int ret;
	u8 soft_val;
	ret = aw3750x_i2c_read_u8(AW3750X_REG_APPS, &soft_val);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_read_u8 failed,ret = %d\n", ret);
		return ret;
	}
	soft_val &= AW_SOFT_RESET_MASK;
	soft_val |= AW3750X_SOFT_RESET;
	LCD_KIT_INFO("aw3750x_i2c_read_u8, soft_val = 0x%x\n", soft_val);
	ret = aw3750x_i2c_write_u8(AW3750X_REG_APPS, soft_val);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_write_u8 failed,ret = %d\n", ret);
		return ret;
	}
	mdelay(10);
	return 0;
}

static int aw3750x_set_current(void)
{
	/*set current limit threshold > 220ma*/
	int ret = 0;
	u8 val1 = 0, val2 = 0;
	ret = aw3750x_i2c_read_u8(AW3750X_REG_APPS, &val1);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_read_u8 AW3750X_REG_APPS failed,ret = %d\n", ret);
		return ret;
	}
	val1 |= AW3750X_APPS_APPS_BIT;
	LCD_KIT_INFO("aw3750x_i2c_read_u8 REG_APPS, val1 = 0x%x\n", val1);
	ret = aw3750x_i2c_write_u8(AW3750X_REG_APPS, val1);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_write_u8 AW3750X_REG_APPS failed,ret = %d\n", ret);
		return ret;
	}
	ret = aw3750x_i2c_read_u8(AW3750X_REG_CTRL, &val2);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_read_u8 AW3750X_REG_CTRL failed,ret = %d\n", ret);
		return ret;
	}
	val2 |= AW3750X_CTRL_ILMTNCP_BIT;
	LCD_KIT_INFO("aw3750x_i2c_read_u8 REG_CTRL, val2 = 0x%x\n", val2);
	ret = aw3750x_i2c_write_u8(AW3750X_REG_CTRL, val2);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_write_u8 AW3750X_REG_CTRL failed,ret = %d\n", ret);
		return ret;
	}
	return 0;
}

static int aw3750x_device_verify(void)
{
	int ret;
	u8 val;
	u8 reg_val;

	LCD_KIT_INFO("%s enter\n", __func__);

	ret = aw3750x_soft_reset();
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_soft_reset failed,ret = %d\n", ret);
		return ret;
	}

	ret = aw3750x_i2c_read_u8(AW3750X_REG_VERSION, &val);
	if (ret < 0) {
		LCD_KIT_ERR("aw3750x_i2c_read_u8 failed,ret = %d\n", ret);
		return ret;
	}

        LCD_KIT_INFO("aw3750x_i2c_read_u8 AW3750X_REG_VERSION, val = 0x%02x\n", val);

	if (val == AW37501_VERSION_ID) {
		LCD_KIT_INFO("%s,aw37501, chip version = 0x%02x\n", __func__, val);
	} else if (val == AW37502_VERSION_ID) {
		LCD_KIT_INFO("%s,aw37502, chip version = 0x%02x\n", __func__, val);
	} else if (val == AW37503_VERSION_ID) {
		ret = aw3750x_i2c_read_u8(AW3750X_REG_TRIM, &reg_val);
		if (ret < 0) {
			LCD_KIT_ERR("aw3750x_i2c_read_u8 failed,ret = %d\n", ret);
			return ret;
		}
		if ((reg_val & AW37504_VERSION_ID) == AW37504_VERSION_ID) {
			LCD_KIT_INFO("%s,aw37504, chip version = 0x%02x.\n", __func__, AW37504_VERSION_ID);
			aw3750x_set_current();
		} else {
			LCD_KIT_INFO("%s,aw37503, chip version = 0x%02x\n", __func__, val);
		}
	} else {
		LCD_KIT_ERR("%s, no chip provide,val = %x reg_val = %x.\n", __func__, val, reg_val);
		return -1;
	}

	return 0;
}

#ifdef MTK_LCD_KIT_LK2_SUPPORT
void aw3750x_set_bias_status(void *fdt)
#else
void aw3750x_set_bias_status(void)
#endif
{
	int ret;
	int offset;
	void *kernel_fdt = NULL;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	kernel_fdt = fdt;
#else
#ifdef DEVICE_TREE_SUPPORT
	kernel_fdt = get_kernel_fdt();
#endif
#endif
	if (kernel_fdt == NULL) {
		LCD_KIT_ERR("kernel_fdt is NULL\n");
		return;
	}

	offset = fdt_node_offset_by_compatible(kernel_fdt, 0, DTS_COMP_AW3750X);
	if (offset < 0) {
		LCD_KIT_ERR("can not find node, change status failed\n");
		return;
	}

	if (check_status == CHECK_STATUS_OK)
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status", "okay");
	else
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status", "disabled");

	if (ret) {
		LCD_KIT_ERR("can not update dts status errno=%d\n", ret);
		return;
	}

	LCD_KIT_INFO("rt4801h set bias status OK!\n");
}

static struct lcd_kit_bias_ops bias_ops = {
	.set_bias_voltage = aw3750x_set_bias,
};

int aw3750x_bias_recognize(void)
{
	int ret;

	ret = aw3750x_device_verify();
	if (ret < 0) {
		check_status = CHECK_STATUS_FAIL;
		LCD_KIT_ERR("aw3750x is not right bias\n");
		return ret;
	}

	lcd_kit_bias_register(&bias_ops);
	check_status = CHECK_STATUS_OK;

	LCD_KIT_INFO("aw3750x is right bias\n");

	return ret;
}

int aw3750x_init(void)
{
	int ret;
	unsigned int support = 0;

	ret = lcd_kit_parse_get_u32_default(DTS_COMP_AW3750X, AW3750X_SUPPORT, &support, 0);
	if ((ret < 0) || (!support)) {
		LCD_KIT_ERR("not support aw3750x\n");
		return LCD_KIT_OK;
	}

	/* register bias ops */
	lcd_kit_bias_recognize_register(aw3750x_bias_recognize);
	ret = lcd_kit_parse_get_u32_default(DTS_COMP_AW3750X, AW3750X_I2C_BUS_ID, &i2c_bus_id, 0);
	if (ret < 0) {
		i2c_bus_id = 0;
		return LCD_KIT_OK;
	}
	LCD_KIT_INFO("aw3750x is support\n");

	return LCD_KIT_OK;
}

