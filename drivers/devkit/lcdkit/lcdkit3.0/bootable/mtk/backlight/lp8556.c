/*
 * lp8556.c
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
#include <platform_mtk.h>
#include <platform.h>
#include <dev/timer/arm_generic.h>
#include <mt_i2c.h>
#else
#include <fdt_op.h>
#include <platform/mt_i2c.h>
#include <platform/mt_gpt.h>
#endif
#include <securec.h>

#include "lcd_kit_utils.h"
#include "lp8556.h"
#include "lcd_kit_common.h"
#include "lcd_kit_bl.h"

#define OFFSET_DEF_VAL (-1)
#define REG_NODE_NAME_LEN 32
#define CHECK_STATUS_FAIL 0
#define CHECK_STATUS_OK 1

static struct lp8556_backlight_information lp8556_bl_info = {0};
static bool lp8556_init_status = false;
static bool lp8556_checked;
static bool check_status;
static bool is_dual_hw_en_gpio_same = false;

static char *lp8556_dts_string[LP8556_RW_REG_MAX] = {
	"lp8556_device_control",
	"lp8556_eprom_cfg0",
	"lp8556_eprom_cfg1",
	"lp8556_eprom_cfg2",
	"lp8556_eprom_cfg3",
	"lp8556_eprom_cfg4",
	"lp8556_eprom_cfg5",
	"lp8556_eprom_cfg6",
	"lp8556_eprom_cfg7",
	"lp8556_eprom_cfg8",
	"lp8556_eprom_cfg9",
	"lp8556_eprom_cfgA",
	"lp8556_eprom_cfgE",
	"lp8556_eprom_cfg9E",
	"lp8556_led_enable",
	"lp8556_eprom_cfg98",
	"lp8556_fualt_flag",
	"lp8556_eprom_cfg00",
	"lp8556_eprom_cfg03",
	"lp8556_eprom_cfg04",
	"lp8556_eprom_cfg05",
	"lp8556_eprom_cfg10",
	"lp8556_eprom_cfg11",
};

static u8 lp8556_reg_addr[LP8556_RW_REG_MAX] = {
	LP8556_DEVICE_CONTROL,
	LP8556_EPROM_CFG0,
	LP8556_EPROM_CFG1,
	LP8556_EPROM_CFG2,
	LP8556_EPROM_CFG3,
	LP8556_EPROM_CFG4,
	LP8556_EPROM_CFG5,
	LP8556_EPROM_CFG6,
	LP8556_EPROM_CFG7,
	LP8556_EPROM_CFG8,
	LP8556_EPROM_CFG9,
	LP8556_EPROM_CFGA,
	LP8556_EPROM_CFGE,
	LP8556_EPROM_CFG9E,
	LP8556_LED_ENABLE,
	LP8556_EPROM_CFG98,
	LP8556_FUALT_FLAG,
	LP8556_EPROM_CFG00,
	LP8556_EPROM_CFG03,
	LP8556_EPROM_CFG04,
	LP8556_EPROM_CFG05,
	LP8556_EPROM_CFG10,
	LP8556_EPROM_CFG11,
};

static int lp8556_2_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = LP8556_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c lp8556_i2c = {0};
#else
	struct mt_i2c_t lp8556_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	lp8556_i2c.id = lp8556_bl_info.lp8556_2_i2c_bus_id;
	lp8556_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(lp8556_i2c.id, lp8556_i2c.addr, data_buffer, len, len, NULL);
#else
	lp8556_i2c.mode = ST_MODE;
	lp8556_i2c.speed = LP8556_I2C_SPEED;
	ret = i2c_write_read(&lp8556_i2c, data_buffer, len, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
	return ret;
}

static int lp8556_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = LP8556_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c lp8556_i2c = {0};
#else
	struct mt_i2c_t lp8556_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	lp8556_i2c.id = lp8556_bl_info.lp8556_i2c_bus_id;
	lp8556_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(lp8556_i2c.id, lp8556_i2c.addr, data_buffer, len, len, NULL);
#else
	lp8556_i2c.mode = ST_MODE;
	lp8556_i2c.speed = LP8556_I2C_SPEED;
	ret = i2c_write_read(&lp8556_i2c, data_buffer, len, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
		return ret;
	}
	if (lp8556_bl_info.dual_ic) {
		ret = lp8556_2_i2c_read_u8(chip_no, data_buffer, addr);
		if (ret < 0) {
			LCD_KIT_ERR("lp8556_2_i2c_read_u8  failed! reg is 0x%xret: %d\n",
				addr, ret);
			return ret;
		}
	}
	return ret;
}

static int lp8556_2_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[LP8556_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = LP8556_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c lp8556_i2c = {0};
#else
	struct mt_i2c_t lp8556_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	lp8556_i2c.id = lp8556_bl_info.lp8556_2_i2c_bus_id;
	lp8556_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(lp8556_i2c.id, lp8556_i2c.addr, write_data, len, NULL);
#else
	lp8556_i2c.mode = ST_MODE;
	lp8556_i2c.speed = LP8556_I2C_SPEED;
	ret = i2c_write(&lp8556_i2c, write_data, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_write  failed! reg is  0x%x ret: %d\n",
			addr, ret);
	return ret;
}


static int lp8556_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[LP8556_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = LP8556_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c lp8556_i2c = {0};
#else
	struct mt_i2c_t lp8556_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	lp8556_i2c.id = lp8556_bl_info.lp8556_i2c_bus_id;
	lp8556_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(lp8556_i2c.id, lp8556_i2c.addr, write_data, len, NULL);
#else
	lp8556_i2c.mode = ST_MODE;
	lp8556_i2c.speed = LP8556_I2C_SPEED;
	ret = i2c_write(&lp8556_i2c, write_data, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("%s: i2c_write  failed! reg is  0x%x ret: %d\n",
			addr, ret);
		return ret;
	}
	if (lp8556_bl_info.dual_ic) {
		ret = lp8556_2_i2c_write_u8(chip_no, addr, value);
		if(ret < 0){
			LCD_KIT_ERR("lp8556_2_i2c_write_u8  failed! reg is  0x%x ret: %d\n",
				addr, ret);
			return ret;
		}
	}
	return ret;
}

static int lp8556_parse_reg_config()
{
	int ret;
	int i;
	u8 ic_sub_version;
	char reg_node_name[REG_NODE_NAME_LEN] = {0};

	LCD_KIT_ERR("lp8556_parse_reg_config +!\n");

	/* enable bl ic */
	if (lp8556_bl_info.lp8556_hw_en) {
		lcdkit_gpio_set_mode(lp8556_bl_info.lp8556_hw_en_gpio,
			LCDKIT_GPIO_MODE_00);
		lcdkit_gpio_set_dir(lp8556_bl_info.lp8556_hw_en_gpio,
			LCDKIT_GPIO_DIR_OUT);
		lcdkit_gpio_set_out(lp8556_bl_info.lp8556_hw_en_gpio,
			LCDKIT_GPIO_VAL_HIGH);
		if (lp8556_bl_info.dual_ic) {
			lcdkit_gpio_set_mode(lp8556_bl_info.lp8556_2_hw_en_gpio,
				LCDKIT_GPIO_MODE_00);
			lcdkit_gpio_set_dir(lp8556_bl_info.lp8556_2_hw_en_gpio,
				LCDKIT_GPIO_DIR_OUT);
			lcdkit_gpio_set_out(lp8556_bl_info.lp8556_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_HIGH);
		}
		if (lp8556_bl_info.bl_on_lk_mdelay)
			mdelay(lp8556_bl_info.bl_on_lk_mdelay);
	}

	/* read ic sub version */
	ret = lp8556_i2c_read_u8(LP8556_SLAV_ADDR, &ic_sub_version, LP8556_EPROM_CFGF);
	if (ret < 0) {
		LCD_KIT_ERR("get ic_sub_version failed\n");
		return ret;
	}
	LCD_KIT_ERR("get ic_sub_version = 0x%x\n", ic_sub_version);

	switch (ic_sub_version) {
	case LP8556_E11_CFGF_VAL:
	case LP8556_E03_E07_CFGF_VAL:
		strncpy_s(reg_node_name, sizeof(reg_node_name), DTS_COMP_LP8556_E11, strlen(DTS_COMP_LP8556_E11));
		break;
	default:
		LCD_KIT_ERR("failed to get reg node name\n");
		return ret;
	}
	LCD_KIT_ERR("get reg_node_name = %s\n", reg_node_name);

	/* read register by dts node */
	lp8556_bl_info.nodeoffset = fdt_node_offset_by_compatible(
		lp8556_bl_info.pfdt, OFFSET_DEF_VAL, reg_node_name);
	if (lp8556_bl_info.nodeoffset < 0) {
		LCD_KIT_ERR("can not find %s node\n", reg_node_name);
		return LCD_KIT_FAIL;
	}

	LCD_KIT_ERR("get nodeoffset = %d\n", lp8556_bl_info.nodeoffset);

	for (i = 0;i < LP8556_RW_REG_MAX;i++ ) {
		ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
			lp8556_bl_info.nodeoffset, lp8556_dts_string[i],
			&lp8556_bl_info.lp8556_reg[i], 0);
		if (ret < 0) {
			lp8556_bl_info.lp8556_reg[i] = 0xffff;
			LCD_KIT_ERR("can not find %s dts\n", lp8556_dts_string[i]);
		} else {
			LCD_KIT_ERR("get %s value = 0x%x\n",
				lp8556_dts_string[i], lp8556_bl_info.lp8556_reg[i]);
		}
	}

	return ret;
}

static int lp8556_parse_dts()
{
	int ret;
	int i;

	LCD_KIT_INFO("lp8556_parse_dts +!\n");

	for (i = 0;i < LP8556_RW_REG_MAX;i++ ) {
		ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
			lp8556_bl_info.nodeoffset, lp8556_dts_string[i],
			&lp8556_bl_info.lp8556_reg[i], 0);
		if (ret < 0) {
			lp8556_bl_info.lp8556_reg[i] = 0xffff;
			LCD_KIT_ERR("can not find %s dts\n", lp8556_dts_string[i]);
		} else {
			LCD_KIT_INFO("get %s value = 0x%x\n",
				lp8556_dts_string[i], lp8556_bl_info.lp8556_reg[i]);
		}
	}

	return ret;
}

static int lp8556_config_register(void)
{
	int ret = 0;
	int i;

	for(i = 0;i < LP8556_RW_REG_MAX;i++) {
		/*judge reg is valid*/
		if (lp8556_bl_info.lp8556_reg[i] != 0xffff) {
			ret = lp8556_i2c_write_u8(LP8556_SLAV_ADDR,
				(u8)lp8556_reg_addr[i], (u8)lp8556_bl_info.lp8556_reg[i]);
			if (ret < 0) {
				LCD_KIT_ERR("write lp8556 backlight config register 0x%x failed\n",
					lp8556_reg_addr[i]);
				return ret;
			}
		}
	}
	return ret;
}

static void lp8556_enable(void)
{
	int ret;

	if (lp8556_bl_info.lp8556_hw_en) {
		lcdkit_gpio_set_mode(lp8556_bl_info.lp8556_hw_en_gpio,
			LCDKIT_GPIO_MODE_00);
		lcdkit_gpio_set_dir(lp8556_bl_info.lp8556_hw_en_gpio,
			LCDKIT_GPIO_DIR_OUT);
		lcdkit_gpio_set_out(lp8556_bl_info.lp8556_hw_en_gpio,
			LCDKIT_GPIO_VAL_HIGH);
		if (lp8556_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			lcdkit_gpio_set_mode(lp8556_bl_info.lp8556_2_hw_en_gpio,
				LCDKIT_GPIO_MODE_00);
			lcdkit_gpio_set_dir(lp8556_bl_info.lp8556_2_hw_en_gpio,
				LCDKIT_GPIO_DIR_OUT);
			lcdkit_gpio_set_out(lp8556_bl_info.lp8556_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_HIGH);
		}
		if (lp8556_bl_info.bl_on_lk_mdelay)
			mdelay(lp8556_bl_info.bl_on_lk_mdelay);
	}
	ret = lp8556_config_register();
	if (ret < 0) {
		LCD_KIT_ERR("lp8556 config register failed\n");
		return ;
	}
	lp8556_init_status = true;
}

static void lp8556_disable(void)
{
	if (lp8556_bl_info.lp8556_hw_en) {
		lcdkit_gpio_set_out(lp8556_bl_info.lp8556_hw_en_gpio,
			LCDKIT_GPIO_VAL_LOW);
		if (lp8556_bl_info.dual_ic && is_dual_hw_en_gpio_same == false)
			lcdkit_gpio_set_out(lp8556_bl_info.lp8556_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_LOW);
	}
	lp8556_init_status = false;
}

int lp8556_set_backlight(uint32_t bl_level)
{
	int bl_msb = 0;
	int bl_lsb = 0;
	int ret = 0;

	/*first set backlight, enable lp8556*/
	if (false == lp8556_init_status && bl_level > 0)
		lp8556_enable();

	bl_level = bl_level * lp8556_bl_info.bl_level / LP8556_BL_DEFAULT_LEVEL;

	if(bl_level > LP8556_BL_MAX)
		bl_level = LP8556_BL_MAX;

	/*set backlight level*/
	bl_msb = (bl_level >> 8) & 0x0F;
	bl_lsb = bl_level & 0xFF;

		LCD_KIT_ERR("write lp8556 backlight level lsb:0x%x msb:0x%x success\n", bl_lsb,bl_msb);
	ret = lp8556_i2c_write_u8(LP8556_SLAV_ADDR, lp8556_bl_info.lp8556_level_lsb, bl_lsb);
	if (ret < 0)
		LCD_KIT_ERR("write lp8556 backlight level lsb:0x%x failed\n", bl_lsb);
	ret = lp8556_i2c_write_u8(LP8556_SLAV_ADDR, lp8556_bl_info.lp8556_level_msb, bl_msb);
	if (ret < 0)
		LCD_KIT_ERR("write lp8556 backlight level msb:0x%x failed\n", bl_msb);

	/*if set backlight level 0, disable lp8556*/
	if (true == lp8556_init_status && 0 == bl_level)
		lp8556_disable();

	return ret;
}
int lp8556_en_backlight(uint32_t bl_level)
{
	int ret = 0;

	LCD_KIT_INFO("lp8556_en_backlight: bl_level=%d\n", bl_level);
	/*first set backlight, enable lp8556*/
	if (false == lp8556_init_status && bl_level > 0)
		lp8556_enable();

	/*if set backlight level 0, disable lp8556*/
	if (true == lp8556_init_status && 0 == bl_level)
		lp8556_disable();

	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = lp8556_set_backlight,
	.en_backlight = lp8556_en_backlight,
};

#ifdef MTK_LCD_KIT_LK2_SUPPORT
void lp8556_set_backlight_status(void *fdt)
#else
void lp8556_set_backlight_status(void)
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
	offset = fdt_node_offset_by_compatible(kernel_fdt, 0, DTS_COMP_LP8556);
	if (offset < 0) {
		LCD_KIT_ERR("Could not find lp8556 node, change dts failed\n");
		return;
	}

	if (check_status == CHECK_STATUS_OK)
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"okay");
	else
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"disabled");
	if (ret) {
		LCD_KIT_ERR("Cannot update lp8556 status errno=%d\n", ret);
		return;
	}

	LCD_KIT_INFO("lp8556_set_backlight_status OK!\n");
}

static int lp8556_backlight_ic_check(void)
{
	int ret = 0;

	if (lp8556_checked) {
		LCD_KIT_INFO("lp8556 already check, not again setting\n");
		return ret;
	}
	lp8556_parse_dts();

	if (lp8556_bl_info.is_need_compatible) {
		lp8556_parse_reg_config();
	}

	lp8556_enable();
	ret = lp8556_i2c_read_u8(LP8556_SLAV_ADDR,
		(u8 *)&lp8556_bl_info.lp8556_reg[0], lp8556_reg_addr[0]);
	if (ret < 0) {
		LCD_KIT_ERR("lp8556 not used\n");
		return ret;
	}
	lp8556_disable();
	lcd_kit_bl_register(&bl_ops);
	check_status = CHECK_STATUS_OK;
	LCD_KIT_INFO("lp8556 is right backlight ic\n");
	lp8556_checked = true;
	return ret;
}

int lp8556_init(struct mtk_panel_info *pinfo)
{
	int ret;

	LCD_KIT_INFO("lp8556 init\n");
	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}
	if (pinfo->bias_bl_ic_checked != 0) {
		LCD_KIT_ERR("bias bl ic checked\n");
		return LCD_KIT_OK;
	}

	lp8556_bl_info.pfdt = get_lk_overlayed_dtb();
	if (lp8556_bl_info.pfdt == NULL) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return LCD_KIT_FAIL;
	}
	lp8556_bl_info.nodeoffset = fdt_node_offset_by_compatible(
		lp8556_bl_info.pfdt, OFFSET_DEF_VAL, DTS_COMP_LP8556);
	if (lp8556_bl_info.nodeoffset < 0) {
		LCD_KIT_INFO("can not find %s node\n", DTS_COMP_LP8556);
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
		lp8556_bl_info.nodeoffset, LP8556_SUPPORT,
		&lp8556_bl_info.lp8556_support, 0);
	if (ret < 0 || !lp8556_bl_info.lp8556_support) {
		LCD_KIT_ERR("get lp8556_support failed!\n");
		goto exit;
	}

	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
		lp8556_bl_info.nodeoffset, LP8556_HW_DUAL_IC,
		&lp8556_bl_info.dual_ic, 0);
	if (ret < 0)
		LCD_KIT_ERR("parse dts dual_ic fail!\n");

	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
		lp8556_bl_info.nodeoffset, LP8556_I2C_BUS_ID,
		&lp8556_bl_info.lp8556_i2c_bus_id, 0);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts lp8556_i2c_bus_id fail!\n");
		lp8556_bl_info.lp8556_i2c_bus_id = 0;
		goto exit;
	}
	if (lp8556_bl_info.dual_ic) {
		ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
			lp8556_bl_info.nodeoffset, LP8556_2_I2C_BUS_ID,
			&lp8556_bl_info.lp8556_2_i2c_bus_id, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts lp8556_2_i2c_bus_id fail!\n");
			lp8556_bl_info.lp8556_2_i2c_bus_id = 0;
			goto exit;
		}
	}
	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
		lp8556_bl_info.nodeoffset, GPIO_LP8556_EN_NAME,
		&lp8556_bl_info.lp8556_hw_en, 0);
	if (ret < 0) {
		LCD_KIT_ERR(" parse dts lp8556_hw_enable fail!\n");
		lp8556_bl_info.lp8556_hw_en = 0;
		return LCD_KIT_FAIL;
	}

	if (lp8556_bl_info.lp8556_hw_en) {
		ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
			lp8556_bl_info.nodeoffset, LP8556_HW_EN_GPIO,
			&lp8556_bl_info.lp8556_hw_en_gpio, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts lp8556_hw_en_gpio fail!\n");
			lp8556_bl_info.lp8556_hw_en_gpio = 0;
			goto exit;
		}
		if (lp8556_bl_info.dual_ic) {
			ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
				lp8556_bl_info.nodeoffset, LP8556_2_HW_EN_GPIO,
				&lp8556_bl_info.lp8556_2_hw_en_gpio, 0);
			if (ret < 0) {
				LCD_KIT_ERR("parse dts lp8556_2_hw_en_gpio fail!\n");
				lp8556_bl_info.lp8556_2_hw_en_gpio = 0;
				goto exit;
			}
			if (lp8556_bl_info.lp8556_hw_en_gpio == lp8556_bl_info.lp8556_2_hw_en_gpio) {
				is_dual_hw_en_gpio_same = true;
			}
		}
		ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
			lp8556_bl_info.nodeoffset, LP8556_HW_EN_DELAY,
			&lp8556_bl_info.bl_on_lk_mdelay, 0);
		if (ret < 0)
			LCD_KIT_INFO("parse dts bl_on_lk_mdelay fail!\n");
	}

	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
		lp8556_bl_info.nodeoffset, LP8556_BL_LEVEL,
		&lp8556_bl_info.bl_level, LP8556_BL_DEFAULT_LEVEL);
	if (ret < 0)
		LCD_KIT_ERR("parse dts lp8556_bl_level fail!\n");

	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
		lp8556_bl_info.nodeoffset, "need_compatible",
		&lp8556_bl_info.is_need_compatible, 0);
	if (ret < 0)
		LCD_KIT_ERR("parse dts is_need_compatible fail!\n");

	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
		lp8556_bl_info.nodeoffset, "lp8556_level_lsb",
		&lp8556_bl_info.lp8556_level_lsb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get lp8556_level_lsb dts failed\n");
		goto exit;
	}
	ret = lcd_kit_get_dts_u32_default(lp8556_bl_info.pfdt,
			lp8556_bl_info.nodeoffset, "lp8556_level_msb",
		&lp8556_bl_info.lp8556_level_msb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get lp8556_level_msb dts failed\n");
		goto exit;
	}

	ret = lp8556_backlight_ic_check();
	if (ret == LCD_KIT_OK) {
		pinfo->bias_bl_ic_checked = 1;
		LCD_KIT_INFO("lp8556 is checked\n");
	}
	LCD_KIT_INFO("[%s]:lp8556 is support\n", __FUNCTION__);

exit:
	return ret;
}

