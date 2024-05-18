/*
 * sm5350.c
 *
 * sm5350 backlight driver
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#include "lcd_kit_utils.h"
#include "sm5350.h"
#include <libfdt.h>
#include "lcd_kit_common.h"
#include "lcd_kit_bl.h"
#include "i2c.h"

#define CHECK_STATUS_FAIL 0
#define CHECK_STATUS_OK 1

static struct sm5350_backlight_information sm5350_bl_info = {0};
static unsigned int check_status;
static bool sm5350_checked;

static char *sm5350_dts_string[SM5350_RW_REG_MAX] = {
	"sm5350_reg_hvled_current_output_cfg",
	"sm5350_reg_ctrl_a_bl_cfg",
	"sm5350_reg_ctrl_a_current_set",
	"sm5350_reg_boost_ctrl",
	"sm5350_reg_pwm_cfg",
	"sm5350_reg_led_fault_enable",
	"sm5350_reg_ctrl_a_lsb",
	"sm5350_reg_ctrl_a_msb",
	"sm5350_reg_ctrl_back_enable"
};

static unsigned int sm5350_reg_addr[SM5350_RW_REG_MAX] = {
	SM5350_REG_HVLED_CURRENT_SINK_OUT_CONFIG,
	SM5350_REG_BL_CONFIG,
	SM5350_REG_BL_CTRL_A_FULL_SCALE_CURRENT_SETTING,
	SM5350_REG_BOOST_CTRL,
	SM5350_REG_PWM_CONFIG,
	SM5350_REG_LED_FAULT_ENABLE,
	SM5350_REG_CTRL_A_BRIGHTNESS_LSB,
	SM5350_REG_CTRL_A_BRIGHTNESS_MSB,
	SM5350_REG_CTRL_BANK_ENABLE
};

static int sm5350_i2c_read_u8(unsigned char addr, unsigned char *data_buffer)
{
	int ret = LCD_KIT_FAIL;

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	i2c_set_bus_num(sm5350_bl_info.sm5350_i2c_bus_id);
	i2c_init(SM5350_I2C_SPEED, SM5350_SLAV_ADDR);
	ret = i2c_reg_read(SM5350_SLAV_ADDR, addr);
	if (ret < 0) {
		LCD_KIT_ERR("%s: i2c_read failed, reg is 0x%x ret: %d\n",
			__func__, addr, ret);
		return ret;
	}
	*data_buffer = ret;
	return ret;
}

static int sm5350_i2c_write_u8(unsigned char addr, unsigned char value)
{
	i2c_set_bus_num(sm5350_bl_info.sm5350_i2c_bus_id);
	i2c_init(SM5350_I2C_SPEED, SM5350_SLAV_ADDR);
	i2c_reg_write(SM5350_SLAV_ADDR, addr, value);

	return LCD_KIT_OK;
}

static void sm5350_parse_dts(void)
{
	int ret;
	int i;

	LCD_KIT_INFO("sm5350_parse_dts\n");
	for (i = 0; i < SM5350_RW_REG_MAX; i++) {
		ret = lcd_kit_parse_get_u32_default(DTS_COMP_SM5350,
			sm5350_dts_string[i],
			&sm5350_bl_info.sm5350_reg[i], 0);
		if (ret < 0) {
			sm5350_bl_info.sm5350_reg[i] = SM5350_INVALID_VAL;
			LCD_KIT_INFO("can not find %s dts\n", sm5350_dts_string[i]);
		} else {
			LCD_KIT_INFO("get %s value = 0x%x\n",
				sm5350_dts_string[i], sm5350_bl_info.sm5350_reg[i]);
		}
	}
}

static int sm5350_config_register(void)
{
	int ret = 0;
	int i;

	for (i = 0; i < SM5350_RW_REG_MAX; i++) {
		if (sm5350_bl_info.sm5350_reg[i] != SM5350_INVALID_VAL) {
			ret = sm5350_i2c_write_u8(sm5350_reg_addr[i],
				sm5350_bl_info.sm5350_reg[i]);
			if (ret < 0) {
				LCD_KIT_ERR("write sm5350 reg 0x%x failed\n",
					sm5350_reg_addr[i]);
				return ret;
			}
		}
	}

	return ret;
}

static int sm5350_set_backlight(unsigned int bl_level)
{
	int bl_msb;
	int bl_lsb;
	int ret;

	bl_level = bl_level * sm5350_bl_info.bl_level / SM5350_BL_DEFAULT_LEVEL;

	if (bl_level > SM5350_BL_MAX)
		bl_level = SM5350_BL_MAX;

	/* set backlight level */
	bl_msb = (bl_level >> SM5350_BL_LSB_LEN) & SM5350_BL_MSB_MASK;
	bl_lsb = bl_level & SM5350_BL_LSB_MASK;
	ret = sm5350_i2c_write_u8(SM5350_REG_CTRL_A_BRIGHTNESS_LSB, bl_lsb);
	if (ret < 0)
		LCD_KIT_ERR("write sm5350 backlight lsb:0x%x failed\n", bl_lsb);

	ret = sm5350_i2c_write_u8(SM5350_REG_CTRL_A_BRIGHTNESS_MSB, bl_msb);
	if (ret < 0)
		LCD_KIT_ERR("write sm5350 backlight msb:0x%x failed\n", bl_msb);

	LCD_KIT_INFO("write sm5350 backlight %u success\n", bl_level);
	return ret;
}

void sm5350_set_backlight_status(void *fdt)
{
	int ret;
	int offset;
	void *kernel_fdt = NULL;

	kernel_fdt = fdt;
	if (kernel_fdt == NULL) {
		LCD_KIT_ERR("kernel_fdt is NULL\n");
		return;
	}

	offset = fdt_node_offset_by_compatible(kernel_fdt, 0, DTS_COMP_SM5350);
	if (offset < 0) {
		LCD_KIT_ERR("Could not find sm5350 node, change dts failed\n");
		return;
	}

	if (check_status == CHECK_STATUS_OK)
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"okay");
	else
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"disabled");
	if (ret) {
		LCD_KIT_ERR("Cannot update sm5350 status errno=%d\n", ret);
		return;
	}

	LCD_KIT_INFO("sm5350_set_backlight_status OK!\n");
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = sm5350_set_backlight,
};

static int sm5350_device_verify(void)
{
	int ret;
	unsigned char chip_id = 1;

	if (sm5350_bl_info.sm5350_hw_en) {
		sprd_gpio_request(NULL, sm5350_bl_info.sm5350_hw_en_gpio);
		sprd_gpio_direction_output(NULL, sm5350_bl_info.sm5350_hw_en_gpio,
			GPIO_OUT_ONE);

		if (sm5350_bl_info.bl_on_lk_mdelay)
			mdelay(sm5350_bl_info.bl_on_lk_mdelay);
	}

	ret = sm5350_i2c_read_u8(SM5350_REG_REVISION, &chip_id);
	if (ret < 0) {
		LCD_KIT_ERR("read sm5350 revision failed\n");
		goto error_exit;
	}
	if((chip_id & SM5350_DEV_MASK) != SM5350_CHIP_ID) {
		LCD_KIT_ERR("sm5350 check vendor id failed\n");
		ret = LCD_KIT_FAIL;
		goto error_exit;
	}
	return LCD_KIT_OK;
error_exit:
	if (sm5350_bl_info.sm5350_hw_en)
		sprd_gpio_direction_output(NULL, sm5350_bl_info.sm5350_hw_en_gpio,
			GPIO_OUT_ZERO);


	return ret;
}

static int sm5350_backlight_ic_check(void)
{
	int ret = LCD_KIT_OK;

	if (sm5350_checked) {
		LCD_KIT_INFO("sm5350 already check, not again setting\n");
		return ret;
	}
	ret = sm5350_device_verify();
	if (ret < 0) {
		check_status = CHECK_STATUS_FAIL;
		LCD_KIT_ERR("sm5350 is not right backlight ic\n");
	} else {
		sm5350_parse_dts();
		ret = sm5350_config_register();
		if (ret < 0){
			LCD_KIT_ERR("sm5350 config register failed\n");
			return ret;
		}
		check_status = CHECK_STATUS_OK;
		lcd_kit_bl_register(&bl_ops);
		LCD_KIT_INFO("sm5350 is right backlight ic\n");
	}
	sm5350_checked = true;

	return ret;
}

int sm5350_init(struct sprd_panel_info *pinfo)
{
	int ret;

	LCD_KIT_INFO("sm5350 enter\n");
	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}

	if (pinfo->bias_bl_ic_checked != 0) {
		LCD_KIT_ERR("bl ic is checked\n");
		return LCD_KIT_OK;
	}

	if (check_status == CHECK_STATUS_OK) {
		LCD_KIT_ERR("bl ic is checked succ\n");
		return LCD_KIT_OK;
	}
	ret = lcd_kit_parse_get_u32_default(DTS_COMP_SM5350,
		SM5350_SUPPORT, &sm5350_bl_info.sm5350_support, 0);
	if (ret < 0 || !sm5350_bl_info.sm5350_support) {
		LCD_KIT_ERR("not support sm5350!\n");
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_parse_get_u32_default(DTS_COMP_SM5350,
		SM5350_I2C_BUS_ID, &sm5350_bl_info.sm5350_i2c_bus_id, 0);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts sm5350_i2c_bus_id fail!\n");
		return LCD_KIT_FAIL;
	}
	ret = lcd_kit_parse_get_u32_default(DTS_COMP_SM5350,
		SM5350_HW_ENABLE, &sm5350_bl_info.sm5350_hw_en, 0);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts sm5350_hw_enable fail!\n");
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_parse_get_u32_default(DTS_COMP_SM5350,
		SM5350_BL_LEVEL, &sm5350_bl_info.bl_level,
		SM5350_BL_DEFAULT_LEVEL);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts sm5350_bl_level fail!\n");
		return LCD_KIT_FAIL;
	}
	if (sm5350_bl_info.sm5350_hw_en) {
		ret = lcd_kit_parse_get_u32_default(DTS_COMP_SM5350,
			SM5350_HW_EN_GPIO,
			&sm5350_bl_info.sm5350_hw_en_gpio, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts sm5350_hw_en_gpio fail!\n");
			sm5350_bl_info.sm5350_hw_en_gpio = 0;
			return LCD_KIT_FAIL;
		}
		ret = lcd_kit_parse_get_u32_default(DTS_COMP_SM5350,
			SM5350_HW_EN_DELAY,
			&sm5350_bl_info.bl_on_lk_mdelay, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts bl_on_lk_mdelay fail!\n");
			sm5350_bl_info.bl_on_lk_mdelay = 0;
			return LCD_KIT_FAIL;
		}
	}
	ret = sm5350_backlight_ic_check();
	if (ret == LCD_KIT_OK) {
		pinfo->bias_bl_ic_checked = CHECK_STATUS_OK;
		LCD_KIT_INFO("sm5350 is checked succ\n");
	}
	LCD_KIT_INFO("sm5350 is support\n");

	return LCD_KIT_OK;
}
