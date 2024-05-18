/*
 * rt4539.c
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

#include "lcd_kit_utils.h"
#include "rt4539.h"
#include "lcd_kit_common.h"
#include "lcd_kit_bl.h"

#define OFFSET_DEF_VAL (-1)

#define CHECK_STATUS_FAIL 0
#define CHECK_STATUS_OK 1
#define RT4539_DEFAULT_BOOST_VAL 0x1A

static struct rt4539_backlight_information rt4539_bl_info = {0};
static bool rt4539_init_status = false;
static bool rt4539_checked;
static bool check_status;
static bool is_dual_hw_en_gpio_same = false;

static char *rt4539_dts_string[RT4539_RW_REG_MAX] = {
	"rt4539_eprom_cfg00",
	"rt4539_eprom_cfg01",
	"rt4539_eprom_cfg02",
	"rt4539_eprom_cfg03",
	"rt4539_eprom_cfg06",
	"rt4539_eprom_cfg07",
	"rt4539_eprom_cfg08",
	"rt4539_eprom_cfg09",
	"rt4539_eprom_cfg0A",
	"rt4539_eprom_cfg05",
	"rt4539_eprom_cfg04",
	"rt4539_bl_control",
};

static u8 rt4539_reg_addr[RT4539_RW_REG_MAX] = {
	RT4539_EPROM_CFG00,
	RT4539_EPROM_CFG01,
	RT4539_EPROM_CFG02,
	RT4539_EPROM_CFG03,
	RT4539_EPROM_CFG06,
	RT4539_EPROM_CFG07,
	RT4539_EPROM_CFG08,
	RT4539_EPROM_CFG09,
	RT4539_EPROM_CFG0A,
	RT4539_EPROM_CFG05,
	RT4539_EPROM_CFG04,
	RT4539_BL_CONTROL,
};

static int rt4539_2_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = RT4539_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c rt4539_i2c = {0};
#else
	struct mt_i2c_t rt4539_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	rt4539_i2c.id = rt4539_bl_info.rt4539_2_i2c_bus_id;
	rt4539_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(rt4539_i2c.id, rt4539_i2c.addr, data_buffer, len, len, NULL);
#else
	rt4539_i2c.mode = ST_MODE;
	rt4539_i2c.speed = RT4539_I2C_SPEED;
	ret = i2c_write_read(&rt4539_i2c, data_buffer, len, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
	return ret;
}

static int rt4539_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = RT4539_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c rt4539_i2c = {0};
#else
	struct mt_i2c_t rt4539_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	rt4539_i2c.id = rt4539_bl_info.rt4539_i2c_bus_id;
	rt4539_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(rt4539_i2c.id, rt4539_i2c.addr, data_buffer, len, len, NULL);
#else
	rt4539_i2c.mode = ST_MODE;
	rt4539_i2c.speed = RT4539_I2C_SPEED;
	ret = i2c_write_read(&rt4539_i2c, data_buffer, len, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
		return ret;
	}
	if (rt4539_bl_info.dual_ic) {
		ret = rt4539_2_i2c_read_u8(chip_no, data_buffer, addr);
		if (ret < 0) {
			LCD_KIT_ERR("rt4539_2_i2c_read_u8  failed! reg is 0x%xret: %d\n",
				addr, ret);
			return ret;
		}
	}
	return ret;
}

static int rt4539_2_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[RT4539_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = RT4539_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c rt4539_i2c = {0};
#else
	struct mt_i2c_t rt4539_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	rt4539_i2c.id = rt4539_bl_info.rt4539_2_i2c_bus_id;
	rt4539_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(rt4539_i2c.id, rt4539_i2c.addr, write_data, len, NULL);
#else
	rt4539_i2c.mode = ST_MODE;
	rt4539_i2c.speed = RT4539_I2C_SPEED;
	ret = i2c_write(&rt4539_i2c, write_data, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_write  failed! reg is  0x%x ret: %d\n", addr, ret);
	return ret;
}


static int rt4539_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[RT4539_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = RT4539_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c rt4539_i2c = {0};
#else
	struct mt_i2c_t rt4539_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	rt4539_i2c.id = rt4539_bl_info.rt4539_i2c_bus_id;
	rt4539_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(rt4539_i2c.id, rt4539_i2c.addr, write_data, len, NULL);
#else
	rt4539_i2c.mode = ST_MODE;
	rt4539_i2c.speed = RT4539_I2C_SPEED;
	ret = i2c_write(&rt4539_i2c, write_data, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("i2c_write  failed! reg is  0x%x ret: %d\n", addr, ret);
		return ret;
	}
	if (rt4539_bl_info.dual_ic) {
		ret = rt4539_2_i2c_write_u8(chip_no, addr, value);
		if(ret < 0){
			LCD_KIT_ERR("rt4539_2_i2c_write_u8  failed! reg is  0x%x ret: %d\n", addr, ret);
			return ret;
		}
	}
	return ret;
}

static int rt4539_parse_dts()
{
	int ret;
	int i;

	LCD_KIT_INFO("rt4539_parse_dts +!\n");

	for (i = 0;i < RT4539_RW_REG_MAX;i++ ) {
		ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
			rt4539_bl_info.nodeoffset, rt4539_dts_string[i],
			&rt4539_bl_info.rt4539_reg[i], 0);
		if (ret < 0) {
			rt4539_bl_info.rt4539_reg[i] = 0xffff;
			LCD_KIT_ERR("can not find %s dts\n", rt4539_dts_string[i]);
		} else {
			LCD_KIT_INFO("get %s value = 0x%x\n",
				rt4539_dts_string[i], rt4539_bl_info.rt4539_reg[i]);
		}
	}

	return ret;
}

static int rt4539_config_register(void)
{
	int ret = 0;
	int i;
	u8 temp;

	ret = rt4539_i2c_read_u8(RT4539_SLAV_ADDR, &temp, RT4539_EPROM_CFG0A);
	if (ret < 0) {
		LCD_KIT_ERR("rt4539 read 0x0A fail!\n");
		return ret;
	}
	if (temp != RT4539_DEFAULT_BOOST_VAL) {
		LCD_KIT_INFO("rt4539 already configured, return.\n");
		return ret;
	}

	/*Disable bl before writing the register*/
	ret = rt4539_i2c_write_u8(RT4539_SLAV_ADDR,
			RT4539_BL_CONTROL, BL_DISABLE_CTL);
	if (ret < 0) {
		LCD_KIT_ERR("rt4539 bl_disable reg set failed\n");
		return ret;
	}
	for(i = 0;i < RT4539_RW_REG_MAX;i++) {
		/*judge reg is valid*/
		if (rt4539_bl_info.rt4539_reg[i] != 0xffff) {
			ret = rt4539_i2c_write_u8(RT4539_SLAV_ADDR,
				(u8)rt4539_reg_addr[i], (u8)rt4539_bl_info.rt4539_reg[i]);
			if (ret < 0) {
				LCD_KIT_ERR("write rt4539 backlight config register 0x%x failed\n",
					rt4539_reg_addr[i]);
				return ret;
			}
		}
	}
	return ret;
}

static void rt4539_enable(void)
{
	int ret;

	if (rt4539_bl_info.rt4539_hw_en) {
		lcdkit_gpio_set_mode(rt4539_bl_info.rt4539_hw_en_gpio,
			LCDKIT_GPIO_MODE_00);
		lcdkit_gpio_set_dir(rt4539_bl_info.rt4539_hw_en_gpio,
			LCDKIT_GPIO_DIR_OUT);
		lcdkit_gpio_set_out(rt4539_bl_info.rt4539_hw_en_gpio,
			LCDKIT_GPIO_VAL_HIGH);
		if (rt4539_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			lcdkit_gpio_set_mode(rt4539_bl_info.rt4539_2_hw_en_gpio,
				LCDKIT_GPIO_MODE_00);
			lcdkit_gpio_set_dir(rt4539_bl_info.rt4539_2_hw_en_gpio,
				LCDKIT_GPIO_DIR_OUT);
			lcdkit_gpio_set_out(rt4539_bl_info.rt4539_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_HIGH);
		}
		if (rt4539_bl_info.bl_on_lk_mdelay)
			mdelay(rt4539_bl_info.bl_on_lk_mdelay);
	}
	ret = rt4539_config_register();
	if (ret < 0) {
		LCD_KIT_ERR("rt4539 config register failed\n");
		return ;
	}
	rt4539_init_status = true;
}

static void rt4539_disable(void)
{
	if (rt4539_bl_info.rt4539_hw_en) {
		lcdkit_gpio_set_out(rt4539_bl_info.rt4539_hw_en_gpio,
			LCDKIT_GPIO_VAL_LOW);
		if (rt4539_bl_info.dual_ic && is_dual_hw_en_gpio_same == false)
			lcdkit_gpio_set_out(rt4539_bl_info.rt4539_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_LOW);
	}
	rt4539_init_status = false;
}

int rt4539_set_backlight(uint32_t bl_level)
{
	int bl_msb = 0;
	int bl_lsb = 0;
	int ret = 0;

	/*first set backlight, enable rt4539*/
	if (false == rt4539_init_status && bl_level > 0)
		rt4539_enable();

	bl_level = bl_level * rt4539_bl_info.bl_level / RT4539_BL_DEFAULT_LEVEL;

	if (bl_level > RT4539_BL_MAX)
		bl_level = RT4539_BL_MAX;

	/*set backlight level*/
	bl_msb = (bl_level >> 8) & 0x0F;
	bl_lsb = bl_level & 0xFF;
	ret = rt4539_i2c_write_u8(RT4539_SLAV_ADDR, rt4539_bl_info.rt4539_level_msb, bl_msb);
	if (ret < 0)
		LCD_KIT_ERR("write rt4539 backlight level msb:0x%x failed\n", bl_msb);
	ret = rt4539_i2c_write_u8(RT4539_SLAV_ADDR, rt4539_bl_info.rt4539_level_lsb, bl_lsb);
	if (ret < 0)
		LCD_KIT_ERR("write rt4539 backlight level lsb:0x%x failed\n", bl_lsb);

	LCD_KIT_INFO("write rt4539 backlight level msb:0x%x lsb:0x%x \n", bl_msb,bl_lsb);
	
	/*if set backlight level 0, disable rt4539*/
	if (true == rt4539_init_status && 0 == bl_level)
		rt4539_disable();

	return ret;
}
int rt4539_en_backlight(uint32_t bl_level)
{
	int ret = 0;

	LCD_KIT_INFO("rt4539_en_backlight: bl_level=%d\n", bl_level);
	/*first set backlight, enable rt4539*/
	if (false == rt4539_init_status && bl_level > 0)
		rt4539_enable();

	/*if set backlight level 0, disable rt4539*/
	if (true == rt4539_init_status && 0 == bl_level)
		rt4539_disable();

	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = rt4539_set_backlight,
	.en_backlight = rt4539_en_backlight,
};

#ifdef MTK_LCD_KIT_LK2_SUPPORT
void rt4539_set_backlight_status(void *fdt)
#else
void rt4539_set_backlight_status(void)
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
	offset = fdt_node_offset_by_compatible(kernel_fdt, 0, DTS_COMP_RT4539);
	if (offset < 0) {
		LCD_KIT_ERR("Could not find rt4539 node, change dts failed\n");
		return;
	}

	if (check_status == CHECK_STATUS_OK)
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"okay");
	else
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"disabled");
	if (ret) {
		LCD_KIT_ERR("Cannot update rt4539 status errno=%d\n", ret);
		return;
	}

	LCD_KIT_INFO("rt4539_set_backlight_status OK!\n");
}

static int rt4539_backlight_ic_check(void)
{
	int ret = 0;

	if (rt4539_checked) {
		LCD_KIT_INFO("rt4539 already check, not again setting\n");
		return ret;
	}
	rt4539_parse_dts();
	rt4539_enable();
	ret = rt4539_i2c_read_u8(RT4539_SLAV_ADDR,
		(u8 *)&rt4539_bl_info.rt4539_reg[0], rt4539_reg_addr[0]);
	if (ret < 0) {
		LCD_KIT_ERR("rt4539 not used\n");
		return ret;
	}
	//rt4539_disable();
	lcd_kit_bl_register(&bl_ops);
	check_status = CHECK_STATUS_OK;
	LCD_KIT_INFO("rt4539 is right backlight ic\n");
	rt4539_checked = true;

	return ret;
}

int rt4539_init(struct mtk_panel_info *pinfo)
{
	int ret;

	LCD_KIT_INFO("rt4539 init\n");
	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}
	if (pinfo->bias_bl_ic_checked != 0) {
		LCD_KIT_ERR("bias bl ic checked\n");
		return LCD_KIT_OK;
	}

	rt4539_bl_info.pfdt = get_lk_overlayed_dtb();
	if (rt4539_bl_info.pfdt == NULL) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return LCD_KIT_FAIL;
	}
	rt4539_bl_info.nodeoffset = fdt_node_offset_by_compatible(
		rt4539_bl_info.pfdt, OFFSET_DEF_VAL, DTS_COMP_RT4539);
	if (rt4539_bl_info.nodeoffset < 0) {
		LCD_KIT_INFO("can not find %s node\n", DTS_COMP_RT4539);
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
		rt4539_bl_info.nodeoffset, RT4539_SUPPORT,
		&rt4539_bl_info.rt4539_support, 0);
	if (ret < 0 || !rt4539_bl_info.rt4539_support) {
		LCD_KIT_ERR("get rt4539_support failed!\n");
		goto exit;
	}

	ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
		rt4539_bl_info.nodeoffset, RT4539_HW_DUAL_IC,
		&rt4539_bl_info.dual_ic, 0);
	if (ret < 0)
		LCD_KIT_ERR("parse dts dual_ic fail!\n");

	ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
		rt4539_bl_info.nodeoffset, RT4539_I2C_BUS_ID,
		&rt4539_bl_info.rt4539_i2c_bus_id, 0);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts rt4539_i2c_bus_id fail!\n");
		rt4539_bl_info.rt4539_i2c_bus_id = 0;
		goto exit;
	}
	if (rt4539_bl_info.dual_ic) {
		ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
			rt4539_bl_info.nodeoffset, RT4539_2_I2C_BUS_ID,
			&rt4539_bl_info.rt4539_2_i2c_bus_id, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts rt4539_2_i2c_bus_id fail!\n");
			rt4539_bl_info.rt4539_2_i2c_bus_id = 0;
			goto exit;
		}
	}
	ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
		rt4539_bl_info.nodeoffset, GPIO_RT4539_EN_NAME,
		&rt4539_bl_info.rt4539_hw_en, 0);
	if (ret < 0) {
		LCD_KIT_ERR(" parse dts rt4539_hw_enable fail!\n");
		rt4539_bl_info.rt4539_hw_en = 0;
		return LCD_KIT_FAIL;
	}

	if (rt4539_bl_info.rt4539_hw_en) {
		ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
			rt4539_bl_info.nodeoffset, RT4539_HW_EN_GPIO,
			&rt4539_bl_info.rt4539_hw_en_gpio, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts rt4539_hw_en_gpio fail!\n");
			rt4539_bl_info.rt4539_hw_en_gpio = 0;
			goto exit;
		}
		if (rt4539_bl_info.dual_ic) {
			ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
				rt4539_bl_info.nodeoffset, RT4539_2_HW_EN_GPIO,
				&rt4539_bl_info.rt4539_2_hw_en_gpio, 0);
			if (ret < 0) {
				LCD_KIT_ERR("parse dts rt4539_2_hw_en_gpio fail!\n");
				rt4539_bl_info.rt4539_2_hw_en_gpio = 0;
				goto exit;
			}
			if (rt4539_bl_info.rt4539_hw_en_gpio == rt4539_bl_info.rt4539_2_hw_en_gpio) {
				is_dual_hw_en_gpio_same = true;
			}
		}
		ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
			rt4539_bl_info.nodeoffset, RT4539_HW_EN_DELAY,
			&rt4539_bl_info.bl_on_lk_mdelay, 0);
		if (ret < 0)
			LCD_KIT_INFO("parse dts bl_on_lk_mdelay fail!\n");
	}

	ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
		rt4539_bl_info.nodeoffset, RT4539_BL_LEVEL,
		&rt4539_bl_info.bl_level, RT4539_BL_DEFAULT_LEVEL);
	if (ret < 0)
		LCD_KIT_ERR("parse dts rt4539_bl_level fail!\n");

	ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
		rt4539_bl_info.nodeoffset, "rt4539_level_lsb",
		&rt4539_bl_info.rt4539_level_lsb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get rt4539_level_lsb dts failed\n");
		goto exit;
	}
	ret = lcd_kit_get_dts_u32_default(rt4539_bl_info.pfdt,
			rt4539_bl_info.nodeoffset, "rt4539_level_msb",
		&rt4539_bl_info.rt4539_level_msb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get rt4539_level_msb dts failed\n");
		goto exit;
	}

	ret = rt4539_backlight_ic_check();
	if (ret == LCD_KIT_OK) {
		pinfo->bias_bl_ic_checked = 1;
		LCD_KIT_INFO("rt4539 is checked\n");
	}
	LCD_KIT_INFO("[%s]:rt4539 is support\n", __FUNCTION__);

exit:
	return ret;
}

