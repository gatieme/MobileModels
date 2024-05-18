/*
 * sy7758.c
 *
 * adapt for backlight driver
 *
 * Copyright (c) 2018-2019 Honor Device Co., Ltd.
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

#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#endif
#ifdef MTK_LCD_KIT_LK2_SUPPORT
#include <libfdt.h>
#include <dev/timer/arm_generic.h>
#include <mt_i2c.h>
#include <platform.h>
#include <platform_mtk.h>
#else
#include <fdt_op.h>
#include <platform/mt_i2c.h>
#include <platform/mt_gpt.h>
#endif
#include "lcd_kit_utils.h"
#include "sy7758.h"
#include "lcd_kit_common.h"
#include "lcd_kit_bl.h"

#define OFFSET_DEF_VAL (-1)

#define CHECK_STATUS_FAIL 0
#define CHECK_STATUS_OK 1
#define SY7758_DEFAULT_CFG0_VAL 0xFF

static struct sy7758_backlight_information sy7758_bl_info = {0};
static bool sy7758_init_status = false;
static bool backlight_enable_status = false;
static bool sy7758_checked;
static bool check_status;
static bool is_dual_hw_en_gpio_same = false;

static char *sy7758_dts_string[SY7758_RW_REG_MAX] = {
	"sy7758_close_ctrl",
	"sy7758_eprom_cfg0",
	"sy7758_eprom_cfg1",
	"sy7758_eprom_cfg2",
	"sy7758_eprom_cfg3",
	"sy7758_eprom_cfg4",
	"sy7758_eprom_cfg5",
	"sy7758_eprom_cfg6",
	"sy7758_eprom_cfg7",
	"sy7758_eprom_cfg9",
	"sy7758_eprom_cfgA",
	"sy7758_eprom_cfgE",
	"sy7758_eprom_cfg9E",
	"sy7758_led_enable",
	"sy7758_eprom_cfg98",
	"sy7758_fualt_flag",
	"sy7758_eprom_cfg00",
	"sy7758_eprom_cfg03",
	"sy7758_eprom_cfg04",
	"sy7758_eprom_cfg05",
	"sy7758_eprom_cfg10",
	"sy7758_eprom_cfg11",
	"sy7758_device_control",
};

static u8 sy7758_reg_addr[SY7758_RW_REG_MAX] = {
	SY7758_DEVICE_CONTROL,
	SY7758_EPROM_CFG0,
	SY7758_EPROM_CFG1,
	SY7758_EPROM_CFG2,
	SY7758_EPROM_CFG3,
	SY7758_EPROM_CFG4,
	SY7758_EPROM_CFG5,
	SY7758_EPROM_CFG6,
	SY7758_EPROM_CFG7,
	SY7758_EPROM_CFG9,
	SY7758_EPROM_CFGA,
	SY7758_EPROM_CFGE,
	SY7758_EPROM_CFG9E,
	SY7758_LED_ENABLE,
	SY7758_EPROM_CFG98,
	SY7758_FUALT_FLAG,
	SY7758_EPROM_CFG00,
	SY7758_EPROM_CFG03,
	SY7758_EPROM_CFG04,
	SY7758_EPROM_CFG05,
	SY7758_EPROM_CFG10,
	SY7758_EPROM_CFG11,
	SY7758_DEVICE_CONTROL,
};

static int sy7758_2_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = SY7758_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c sy7758_i2c = {0};
#else
	struct mt_i2c_t sy7758_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	sy7758_i2c.id = sy7758_bl_info.sy7758_2_i2c_bus_id;
	sy7758_i2c.addr = chip_no;

#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(sy7758_i2c.id, sy7758_i2c.addr,
		data_buffer, len, len, NULL);
#else
	sy7758_i2c.mode = ST_MODE;
	sy7758_i2c.speed = SY7758_I2C_SPEED;
	ret = i2c_write_read(&sy7758_i2c, data_buffer, len, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
	return ret;
}

static int sy7758_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = SY7758_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c sy7758_i2c = {0};
#else
	struct mt_i2c_t sy7758_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	sy7758_i2c.id = sy7758_bl_info.sy7758_i2c_bus_id;
	sy7758_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(sy7758_i2c.id, sy7758_i2c.addr,
		data_buffer, len, len, NULL);
#else
	sy7758_i2c.mode = ST_MODE;
	sy7758_i2c.speed = SY7758_I2C_SPEED;
	ret = i2c_write_read(&sy7758_i2c, data_buffer, len, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
		return ret;
	}
	if (sy7758_bl_info.dual_ic) {
		ret = sy7758_2_i2c_read_u8(chip_no, data_buffer, addr);
		if (ret < 0) {
			LCD_KIT_ERR("sy7758_2_i2c_read_u8  failed! reg is 0x%xret: %d\n",
				addr, ret);
			return ret;
		}
	}
	return ret;
}

static int sy7758_2_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[SY7758_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = SY7758_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c sy7758_i2c = {0};
#else
	struct mt_i2c_t sy7758_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	sy7758_i2c.id = sy7758_bl_info.sy7758_2_i2c_bus_id;
	sy7758_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(sy7758_i2c.id, sy7758_i2c.addr, write_data, len, NULL);
#else
	sy7758_i2c.mode = ST_MODE;
	sy7758_i2c.speed = SY7758_I2C_SPEED;
	ret = i2c_write(&sy7758_i2c, write_data, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_write  failed! reg is  0x%x ret: %d\n",
			addr, ret);
	return ret;
}


static int sy7758_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[SY7758_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = SY7758_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c sy7758_i2c = {0};
#else
	struct mt_i2c_t sy7758_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	sy7758_i2c.id = sy7758_bl_info.sy7758_i2c_bus_id;
	sy7758_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(sy7758_i2c.id, sy7758_i2c.addr, write_data, len, NULL);
#else
	sy7758_i2c.mode = ST_MODE;
	sy7758_i2c.speed = SY7758_I2C_SPEED;
	ret = i2c_write(&sy7758_i2c, write_data, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("%s: i2c_write  failed! reg is  0x%x ret: %d\n",
			addr, ret);
		return ret;
	}
	if (sy7758_bl_info.dual_ic) {
		ret = sy7758_2_i2c_write_u8(chip_no, addr, value);
		if(ret < 0){
			LCD_KIT_ERR("sy7758_2_i2c_write_u8  failed! reg is  0x%x ret: %d\n",
				addr, ret);
			return ret;
		}
	}
	return ret;
}

static int sy7758_parse_dts()
{
	int ret;
	int i;

	LCD_KIT_INFO("sy7758_parse_dts +!\n");

	for (i = 0;i < SY7758_RW_REG_MAX;i++ ) {
		ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
			sy7758_bl_info.nodeoffset, sy7758_dts_string[i],
			&sy7758_bl_info.sy7758_reg[i], 0);
		if (ret < 0) {
			sy7758_bl_info.sy7758_reg[i] = 0xffff;
			LCD_KIT_ERR("can not find %s dts\n", sy7758_dts_string[i]);
		} else {
			LCD_KIT_INFO("get %s value = 0x%x\n",
				sy7758_dts_string[i], sy7758_bl_info.sy7758_reg[i]);
		}
	}

	return ret;
}

static int sy7758_config_register(void)
{
	int ret = 0;
	int i, temp;

	ret = sy7758_i2c_read_u8(SY7758_SLAV_ADDR, &temp, SY7758_EPROM_CFG0);
	if (ret < 0) {
		LCD_KIT_ERR("sy7758 read register:0x%x failed\n", SY7758_EPROM_CFG0);
		return ret;
	}
	if (temp != SY7758_DEFAULT_CFG0_VAL) {
		LCD_KIT_INFO("sy7758 already configured, return.\n");
		return 0;
	}

	for(i = 0; i < SY7758_INIT_CMD_NUM; i++) {
		/*judge reg is valid*/
		if (sy7758_bl_info.sy7758_reg[i] != 0xffff) {
			ret = sy7758_i2c_write_u8(SY7758_SLAV_ADDR,
				(u8)sy7758_reg_addr[i], (u8)sy7758_bl_info.sy7758_reg[i]);
			if (ret < 0) {
				LCD_KIT_ERR("write sy7758 backlight config register 0x%x failed\n",
					sy7758_reg_addr[i]);
				return ret;
			}
		}
	}
	return ret;
}

static void sy7758_enable(void)
{
	int ret;

	if (sy7758_bl_info.sy7758_hw_en) {
		lcdkit_gpio_set_mode(sy7758_bl_info.sy7758_hw_en_gpio,
			LCDKIT_GPIO_MODE_00);
		lcdkit_gpio_set_dir(sy7758_bl_info.sy7758_hw_en_gpio,
			LCDKIT_GPIO_DIR_OUT);
		lcdkit_gpio_set_out(sy7758_bl_info.sy7758_hw_en_gpio,
			LCDKIT_GPIO_VAL_HIGH);
		if (sy7758_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			lcdkit_gpio_set_mode(sy7758_bl_info.sy7758_2_hw_en_gpio,
				LCDKIT_GPIO_MODE_00);
			lcdkit_gpio_set_dir(sy7758_bl_info.sy7758_2_hw_en_gpio,
				LCDKIT_GPIO_DIR_OUT);
			lcdkit_gpio_set_out(sy7758_bl_info.sy7758_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_HIGH);
		}
		if (sy7758_bl_info.bl_on_lk_mdelay)
			mdelay(sy7758_bl_info.bl_on_lk_mdelay);
	}
	ret = sy7758_config_register();
	if (ret < 0) {
		LCD_KIT_ERR("sy7758 config register failed\n");
		return ;
	}
	sy7758_init_status = true;
}

static void sy7758_disable(void)
{
	if (sy7758_bl_info.sy7758_hw_en) {
		lcdkit_gpio_set_out(sy7758_bl_info.sy7758_hw_en_gpio,
			LCDKIT_GPIO_VAL_LOW);
		if (sy7758_bl_info.dual_ic && is_dual_hw_en_gpio_same == false)
			lcdkit_gpio_set_out(sy7758_bl_info.sy7758_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_LOW);
	}
	sy7758_init_status = false;
	backlight_enable_status = false;
}

static void lcd_kit_backlight_ctrl_enable(void)
{
	int ret;

	ret = sy7758_i2c_write_u8(SY7758_SLAV_ADDR, sy7758_reg_addr[SY7758_RW_REG_MAX - 1], sy7758_bl_info.sy7758_reg[SY7758_RW_REG_MAX - 1]);
	if (ret < 0) {
		LCD_KIT_ERR("write sy7758 backlight ctrl enable failed\n");
	}
}

int sy7758_set_backlight(uint32_t bl_level)
{
	int bl_msb = 0;
	int bl_lsb = 0;
	int ret = 0;

	/*first set backlight, enable sy7758*/
	if (false == sy7758_init_status && bl_level > 0)
		sy7758_enable();

	bl_level = bl_level * sy7758_bl_info.bl_level / SY7758_BL_DEFAULT_LEVEL;

	if (bl_level > SY7758_BL_MAX)
		bl_level = SY7758_BL_MAX;

	/*set backlight level*/
	bl_msb = (bl_level >> 8) & 0x0F;
	bl_lsb = bl_level & 0xFF;

	LCD_KIT_ERR("write sy7758 backlight level lsb:0x%x msb:0x%x\n", bl_lsb,bl_msb);
	ret = sy7758_i2c_write_u8(SY7758_SLAV_ADDR, sy7758_bl_info.sy7758_level_lsb, bl_lsb);
	if (ret < 0)
		LCD_KIT_ERR("write sy7758 backlight level lsb:0x%x failed\n", bl_lsb);
	ret = sy7758_i2c_write_u8(SY7758_SLAV_ADDR, sy7758_bl_info.sy7758_level_msb, bl_msb);
	if (ret < 0)
		LCD_KIT_ERR("write sy7758 backlight level msb:0x%x failed\n", bl_msb);

	if (backlight_enable_status == false) {
		if (sy7758_bl_info.ctrl_enable) {
			lcd_kit_backlight_ctrl_enable();
		}
		backlight_enable_status = true;
	}
	/*if set backlight level 0, disable sy7758*/
	if (true == sy7758_init_status && 0 == bl_level)
		sy7758_disable();

	return ret;
}
int sy7758_en_backlight(uint32_t bl_level)
{
	int ret = 0;

	LCD_KIT_INFO("sy7758_en_backlight: bl_level=%d\n", bl_level);
	/*first set backlight, enable sy7758*/
	if (false == sy7758_init_status && bl_level > 0)
		sy7758_enable();

	/*if set backlight level 0, disable sy7758*/
	if (true == sy7758_init_status && 0 == bl_level)
		sy7758_disable();

	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = sy7758_set_backlight,
	.en_backlight = sy7758_en_backlight,
};

#ifdef MTK_LCD_KIT_LK2_SUPPORT
void sy7758_set_backlight_status(void *fdt)
#else
void sy7758_set_backlight_status(void)
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
	offset = fdt_node_offset_by_compatible(kernel_fdt, 0, DTS_COMP_SY7758);
	if (offset < 0) {
		LCD_KIT_ERR("Could not find sy7758 node, change dts failed\n");
		return;
	}

	if (check_status == CHECK_STATUS_OK)
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"okay");
	else
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"disabled");
	if (ret) {
		LCD_KIT_ERR("Cannot update sy7758 status errno=%d\n", ret);
		return;
	}

	LCD_KIT_INFO("sy7758_set_backlight_status OK!\n");
}

static int sy7758_backlight_ic_check(void)
{
	int ret = 0;
	int temp = 0;

	if (sy7758_checked) {
		LCD_KIT_INFO("sy7758 already check, not again setting\n");
		return ret;
	}
	sy7758_parse_dts();
	sy7758_enable();
	ret = sy7758_i2c_read_u8(SY7758_SLAV_ADDR, (u8 *)&temp, sy7758_reg_addr[0]);
	if (ret < 0) {
		LCD_KIT_ERR("sy7758 not used\n");
		return ret;
	}
	sy7758_disable();
	lcd_kit_bl_register(&bl_ops);
	check_status = CHECK_STATUS_OK;
	LCD_KIT_INFO("sy7758 is right backlight ic\n");
	sy7758_checked = true;
	return ret;
}

int sy7758_init(struct mtk_panel_info *pinfo)
{
	int ret;

	LCD_KIT_INFO("sy7758 init\n");
	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}
	if (pinfo->bias_bl_ic_checked != 0) {
		LCD_KIT_ERR("bias bl ic checked\n");
		return LCD_KIT_OK;
	}

	sy7758_bl_info.pfdt = get_lk_overlayed_dtb();
	if (sy7758_bl_info.pfdt == NULL) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return LCD_KIT_FAIL;
	}
	sy7758_bl_info.nodeoffset = fdt_node_offset_by_compatible(
		sy7758_bl_info.pfdt, OFFSET_DEF_VAL, DTS_COMP_SY7758);
	if (sy7758_bl_info.nodeoffset < 0) {
		LCD_KIT_INFO("can not find %s node\n", DTS_COMP_SY7758);
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
		sy7758_bl_info.nodeoffset, SY7758_SUPPORT,
		&sy7758_bl_info.sy7758_support, 0);
	if (ret < 0 || !sy7758_bl_info.sy7758_support) {
		LCD_KIT_ERR("get sy7758_support failed!\n");
		goto exit;
	}

	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
		sy7758_bl_info.nodeoffset, SY7758_HW_DUAL_IC,
		&sy7758_bl_info.dual_ic, 0);
	if (ret < 0)
		LCD_KIT_ERR("parse dts dual_ic fail!\n");

	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
		sy7758_bl_info.nodeoffset, "bl_ctrl_enable", &sy7758_bl_info.ctrl_enable, 0);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts bl_ctrl_enable fail!\n");
	}

	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
		sy7758_bl_info.nodeoffset, SY7758_I2C_BUS_ID,
		&sy7758_bl_info.sy7758_i2c_bus_id, 0);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts sy7758_i2c_bus_id fail!\n");
		sy7758_bl_info.sy7758_i2c_bus_id = 0;
		goto exit;
	}
	if (sy7758_bl_info.dual_ic) {
		ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
			sy7758_bl_info.nodeoffset, SY7758_2_I2C_BUS_ID,
			&sy7758_bl_info.sy7758_2_i2c_bus_id, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts sy7758_2_i2c_bus_id fail!\n");
			sy7758_bl_info.sy7758_2_i2c_bus_id = 0;
			goto exit;
		}
	}
	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
		sy7758_bl_info.nodeoffset, GPIO_SY7758_EN_NAME,
		&sy7758_bl_info.sy7758_hw_en, 0);
	if (ret < 0) {
		LCD_KIT_ERR(" parse dts sy7758_hw_enable fail!\n");
		sy7758_bl_info.sy7758_hw_en = 0;
		return LCD_KIT_FAIL;
	}

	if (sy7758_bl_info.sy7758_hw_en) {
		ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
			sy7758_bl_info.nodeoffset, SY7758_HW_EN_GPIO,
			&sy7758_bl_info.sy7758_hw_en_gpio, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts sy7758_hw_en_gpio fail!\n");
			sy7758_bl_info.sy7758_hw_en_gpio = 0;
			goto exit;
		}
		if (sy7758_bl_info.dual_ic) {
			ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
				sy7758_bl_info.nodeoffset, SY7758_2_HW_EN_GPIO,
				&sy7758_bl_info.sy7758_2_hw_en_gpio, 0);
			if (ret < 0) {
				LCD_KIT_ERR("parse dts sy7758_2_hw_en_gpio fail!\n");
				sy7758_bl_info.sy7758_2_hw_en_gpio = 0;
				goto exit;
			}
			if (sy7758_bl_info.sy7758_hw_en_gpio == sy7758_bl_info.sy7758_2_hw_en_gpio) {
				is_dual_hw_en_gpio_same = true;
			}
		}
		ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
			sy7758_bl_info.nodeoffset, SY7758_HW_EN_DELAY,
			&sy7758_bl_info.bl_on_lk_mdelay, 0);
		if (ret < 0)
			LCD_KIT_INFO("parse dts bl_on_lk_mdelay fail!\n");
	}

	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
		sy7758_bl_info.nodeoffset, SY7758_BL_LEVEL,
		&sy7758_bl_info.bl_level, SY7758_BL_DEFAULT_LEVEL);
	if (ret < 0)
		LCD_KIT_ERR("parse dts sy7758_bl_level fail!\n");

	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
		sy7758_bl_info.nodeoffset, "sy7758_level_lsb",
		&sy7758_bl_info.sy7758_level_lsb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get sy7758_level_lsb dts failed\n");
		goto exit;
	}
	ret = lcd_kit_get_dts_u32_default(sy7758_bl_info.pfdt,
			sy7758_bl_info.nodeoffset, "sy7758_level_msb",
		&sy7758_bl_info.sy7758_level_msb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get sy7758_level_msb dts failed\n");
		goto exit;
	}

	ret = sy7758_backlight_ic_check();
	if (ret == LCD_KIT_OK) {
		pinfo->bias_bl_ic_checked = 1;
		LCD_KIT_INFO("sy7758 is checked\n");
	}
	LCD_KIT_INFO("[%s]:sy7758 is support\n", __FUNCTION__);

exit:
	return ret;
}

