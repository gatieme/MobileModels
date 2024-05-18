/*
 * mp3314.c
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
#include "mp3314.h"
#include "lcd_kit_common.h"
#include "lcd_kit_bl.h"

#define OFFSET_DEF_VAL (-1)

#define CHECK_STATUS_FAIL 0
#define CHECK_STATUS_OK 1

static struct mp3314_backlight_information mp3314_bl_info = {0};
static bool mp3314_init_status = false;
static bool mp3314_checked;
static bool check_status;
static bool is_dual_hw_en_gpio_same = false;

static char *mp3314_dts_string[MP3314_RW_REG_MAX] = {
	"mp3314_eprom_cfg05",
	"mp3314_eprom_cfg06",
	"mp3314_eprom_cfg07",
	"mp3314_eprom_cfg08",
	"mp3314_eprom_cfg09",
	"mp3314_eprom_cfg0A",
	"mp3314_eprom_cfg0C",
	"mp3314_eprom_cfg0D",
	"mp3314_eprom_cfg0F",
	"mp3314_eprom_cfg10",
	"mp3314_eprom_cfg03",
	"mp3314_eprom_cfg04",
	"mp3314_eprom_cfg00",
	"mp3314_eprom_cfg01",
	"mp3314_bl_en_ctl",
	"mp3314_eprom_cfg1F",
};

static u8 mp3314_reg_addr[MP3314_RW_REG_MAX] = {
	MP3314_EPROM_CFG05,
	MP3314_EPROM_CFG06,
	MP3314_EPROM_CFG07,
	MP3314_EPROM_CFG08,
	MP3314_EPROM_CFG09,
	MP3314_EPROM_CFG0A,
	MP3314_EPROM_CFG0C,
	MP3314_EPROM_CFG0D,
	MP3314_EPROM_CFG0F,
	MP3314_EPROM_CFG10,
	MP3314_EPROM_CFG03,
	MP3314_EPROM_CFG04,
	MP3314_EPROM_CFG00,
	MP3314_EPROM_CFG01,
	MP3314_BL_EN_CTL,
	MP3314_EPROM_CFG1F,
};

static int mp3314_2_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = MP3314_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c mp3314_i2c = {0};
#else
	struct mt_i2c_t mp3314_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	mp3314_i2c.id = mp3314_bl_info.mp3314_2_i2c_bus_id;
	mp3314_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(mp3314_i2c.id, mp3314_i2c.addr, data_buffer, len, len, NULL);
#else
	mp3314_i2c.mode = ST_MODE;
	mp3314_i2c.speed = MP3314_I2C_SPEED;
	ret = i2c_write_read(&mp3314_i2c, data_buffer, len, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
	return ret;
}

static int mp3314_i2c_read_u8(u8 chip_no, u8 *data_buffer, int addr)
{
	int ret = MP3314_FAIL;
	/* read date default length */
	unsigned char len = 1;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c mp3314_i2c = {0};
#else
	struct mt_i2c_t mp3314_i2c = {0};
#endif

	if (!data_buffer) {
		LCD_KIT_ERR("data buffer is NULL");
		return ret;
	}

	*data_buffer = addr;
	mp3314_i2c.id = mp3314_bl_info.mp3314_i2c_bus_id;
	mp3314_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write_read(mp3314_i2c.id, mp3314_i2c.addr, data_buffer, len, len, NULL);
#else
	mp3314_i2c.mode = ST_MODE;
	mp3314_i2c.speed = MP3314_I2C_SPEED;
	ret = i2c_write_read(&mp3314_i2c, data_buffer, len, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("i2c_read  failed! reg is 0x%x ret: %d\n",
			addr, ret);
		return ret;
	}
	if (mp3314_bl_info.dual_ic) {
		ret = mp3314_2_i2c_read_u8(chip_no, data_buffer, addr);
		if (ret < 0) {
			LCD_KIT_ERR("mp3314_2_i2c_read_u8  failed! reg is 0x%xret: %d\n",
				addr, ret);
			return ret;
		}
	}
	return ret;
}

static int mp3314_2_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[MP3314_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = MP3314_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c mp3314_i2c = {0};
#else
	struct mt_i2c_t mp3314_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	mp3314_i2c.id = mp3314_bl_info.mp3314_2_i2c_bus_id;
	mp3314_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(mp3314_i2c.id, mp3314_i2c.addr, write_data, len, NULL);
#else
	mp3314_i2c.mode = ST_MODE;
	mp3314_i2c.speed = MP3314_I2C_SPEED;
	ret = i2c_write(&mp3314_i2c, write_data, len);
#endif
	if (ret != 0)
		LCD_KIT_ERR("i2c_write  failed! reg is  0x%x ret: %d\n",
			addr, ret);
	return ret;
}


static int mp3314_i2c_write_u8(u8 chip_no, unsigned char addr, unsigned char value)
{
	int ret;
	unsigned char write_data[MP3314_WRITE_LEN] = {0};
	/* write date default length */
	unsigned char len = MP3314_WRITE_LEN;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	struct mt_i2c mp3314_i2c = {0};
#else
	struct mt_i2c_t mp3314_i2c = {0};
#endif

	/* data0: address, data1: write value */
	write_data[0] = addr;
	write_data[1] = value;

	mp3314_i2c.id = mp3314_bl_info.mp3314_i2c_bus_id;
	mp3314_i2c.addr = chip_no;
#ifdef MTK_LCD_KIT_LK2_SUPPORT
	ret = mtk_i2c_write(mp3314_i2c.id, mp3314_i2c.addr, write_data, len, NULL);
#else
	mp3314_i2c.mode = ST_MODE;
	mp3314_i2c.speed = MP3314_I2C_SPEED;
	ret = i2c_write(&mp3314_i2c, write_data, len);
#endif
	if (ret != 0) {
		LCD_KIT_ERR("i2c_write  failed! reg is  0x%x ret: %d\n", addr, ret);
		return ret;
	}
	if (mp3314_bl_info.dual_ic) {
		ret = mp3314_2_i2c_write_u8(chip_no, addr, value);
		if(ret < 0){
			LCD_KIT_ERR("mp3314_2_i2c_write_u8  failed! reg is  0x%x ret: %d\n", addr, ret);
			return ret;
		}
	}
	return ret;
}

static int mp3314_parse_dts()
{
	int ret;
	int i;

	LCD_KIT_INFO("mp3314_parse_dts +!\n");

	for (i = 0;i < MP3314_RW_REG_MAX;i++ ) {
		ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
			mp3314_bl_info.nodeoffset, mp3314_dts_string[i],
			&mp3314_bl_info.mp3314_reg[i], 0);
		if (ret < 0) {
			mp3314_bl_info.mp3314_reg[i] = 0xffff;
			LCD_KIT_ERR("can not find %s dts\n", mp3314_dts_string[i]);
		} else {
			LCD_KIT_INFO("get %s value = 0x%x\n",
				mp3314_dts_string[i], mp3314_bl_info.mp3314_reg[i]);
		}
	}

	return ret;
}

static int mp3314_config_register(void)
{
	int ret = 0;
	int i;
	u8 tmp1 = 0, reg = 0x06;

	ret = mp3314_i2c_read_u8(MP3314_SLAV_ADDR, &tmp1, reg);
	if (ret < 0) {
		LCD_KIT_ERR("mp3314 mp3314_i2c_read_u8 reg06 error\n");
		return ret;
	}
	LCD_KIT_INFO("mp3314 backlight ic reg: 0x%x\n", tmp1);
	if(tmp1 != 0xff){
		LCD_KIT_INFO("mp3314 backlight reg is not 0xff, mp3314 not need to config, return");
		return ret;
	}
	/*Disable bl before writing the register*/
	ret = mp3314_i2c_write_u8(MP3314_SLAV_ADDR,
			MP3314_BL_EN_CTL, BL_DISABLE_CTL);
	if (ret < 0) {
		LCD_KIT_ERR("mp3314 bl_disable reg set failed\n");
		return ret;
	}

	for(i = 0;i < MP3314_RW_REG_MAX;i++) {
		/*judge reg is valid*/
		if (mp3314_bl_info.mp3314_reg[i] != 0xffff) {
			ret = mp3314_i2c_write_u8(MP3314_SLAV_ADDR,
				(u8)mp3314_reg_addr[i], (u8)mp3314_bl_info.mp3314_reg[i]);
			if (ret < 0) {
				LCD_KIT_ERR("write mp3314 backlight config register 0x%x failed\n",
					mp3314_reg_addr[i]);
				return ret;
			}
		}
	}
	return ret;
}

static void mp3314_enable(void)
{
	int ret;

	LCD_KIT_INFO("mp3314_enable\n");
	if (mp3314_bl_info.mp3314_hw_en) {
		lcdkit_gpio_set_mode(mp3314_bl_info.mp3314_hw_en_gpio,
			LCDKIT_GPIO_MODE_00);
		lcdkit_gpio_set_dir(mp3314_bl_info.mp3314_hw_en_gpio,
			LCDKIT_GPIO_DIR_OUT);
		lcdkit_gpio_set_out(mp3314_bl_info.mp3314_hw_en_gpio,
			LCDKIT_GPIO_VAL_HIGH);
		if (mp3314_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			lcdkit_gpio_set_mode(mp3314_bl_info.mp3314_2_hw_en_gpio,
				LCDKIT_GPIO_MODE_00);
			lcdkit_gpio_set_dir(mp3314_bl_info.mp3314_2_hw_en_gpio,
				LCDKIT_GPIO_DIR_OUT);
			lcdkit_gpio_set_out(mp3314_bl_info.mp3314_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_HIGH);
		}
	}
	if (mp3314_bl_info.bl_on_lk_mdelay)
		mdelay(mp3314_bl_info.bl_on_lk_mdelay);
	ret = mp3314_config_register();
	if (ret < 0) {
		LCD_KIT_ERR("mp3314 config register failed\n");
		return ;
	}
	mp3314_init_status = true;
}

static void mp3314_disable(void)
{
	LCD_KIT_INFO("mp3314_disable\n");
	if (mp3314_bl_info.mp3314_hw_en) {
		lcdkit_gpio_set_out(mp3314_bl_info.mp3314_hw_en_gpio,
			LCDKIT_GPIO_VAL_LOW);
		if (mp3314_bl_info.dual_ic && is_dual_hw_en_gpio_same == false)
			lcdkit_gpio_set_out(mp3314_bl_info.mp3314_2_hw_en_gpio,
				LCDKIT_GPIO_VAL_LOW);
	}
	mp3314_init_status = false;
}

int mp3314_set_backlight(uint32_t bl_level)
{
	int bl_msb = 0;
	int bl_lsb = 0;
	int ret = 0;

	/*first set backlight, enable mp3314*/
	if (false == mp3314_init_status && bl_level > 0)
		mp3314_enable();

	bl_level = bl_level * mp3314_bl_info.bl_level / MP3314_BL_DEFAULT_LEVEL;

	if(bl_level > MP3314_BL_MAX)
		bl_level = MP3314_BL_MAX;

	/*set backlight level*/
	bl_msb = (bl_level >> 8) & 0xFF;
	bl_lsb = bl_level & 0xFF;
	LCD_KIT_INFO("write mp3314 backlight level lsb:0x%x msb:0x%x\n", bl_lsb, bl_msb);
	ret = mp3314_i2c_write_u8(MP3314_SLAV_ADDR, mp3314_bl_info.mp3314_level_msb, bl_msb);
	if (ret < 0){
		LCD_KIT_ERR("write mp3314 backlight level msb:0x%x failed\n", bl_msb);
	}else{
	        LCD_KIT_INFO("write mp3314 backlight level msb:0x%x success\n", bl_msb);
	}
	ret = mp3314_i2c_write_u8(MP3314_SLAV_ADDR, mp3314_bl_info.mp3314_level_lsb, bl_lsb);
	if (ret < 0) {
		LCD_KIT_ERR("write mp3314 backlight level lsb:0x%x failed\n", bl_lsb);
	} else {
		LCD_KIT_INFO("write mp3314 backlight level lsb:0x%x success\n", bl_lsb);
	}

	/*if set backlight level 0, disable mp3314*/
	if (true == mp3314_init_status && 0 == bl_level)
		mp3314_disable();

	return ret;
}
int mp3314_en_backlight(uint32_t bl_level)
{
	int ret = 0;

	LCD_KIT_INFO("mp3314_en_backlight: bl_level=%d\n", bl_level);
	/*first set backlight, enable mp3314*/
	if (false == mp3314_init_status && bl_level > 0)
		mp3314_enable();

	/*if set backlight level 0, disable mp3314*/
	if (true == mp3314_init_status && 0 == bl_level)
		mp3314_disable();

	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = mp3314_set_backlight,
	.en_backlight = mp3314_en_backlight,
};

#ifdef MTK_LCD_KIT_LK2_SUPPORT
void mp3314_set_backlight_status(void *fdt)
#else
void mp3314_set_backlight_status(void)
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
	offset = fdt_node_offset_by_compatible(kernel_fdt, 0, DTS_COMP_MP3314);
	if (offset < 0) {
		LCD_KIT_ERR("Could not find mp3314 node, change dts failed\n");
		return;
	}

	if (check_status == CHECK_STATUS_OK)
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"okay");
	else
		ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"status",
			"disabled");
	if (ret) {
		LCD_KIT_ERR("Cannot update mp3314 status errno=%d\n", ret);
		return;
	}

	LCD_KIT_INFO("mp3314_set_backlight_status OK!\n");
}

static int mp3314_backlight_ic_check(void)
{
	int ret = 0;

	if (mp3314_checked) {
		LCD_KIT_INFO("mp3314 already check, not again setting\n");
		return ret;
	}
	mp3314_parse_dts();
	mp3314_enable();
	ret = mp3314_i2c_read_u8(MP3314_SLAV_ADDR,
		(u8 *)&mp3314_bl_info.mp3314_reg[0], mp3314_reg_addr[0]);
	if (ret < 0) {
		LCD_KIT_ERR("mp3314 not used\n");
		return ret;
	}
	//mp3314_disable();
	lcd_kit_bl_register(&bl_ops);
	check_status = CHECK_STATUS_OK;
	LCD_KIT_INFO("mp3314 is right backlight ic\n");
	mp3314_checked = true;
	return ret;
}

int mp3314_init(struct mtk_panel_info *pinfo)
{
	int ret;

	LCD_KIT_INFO("mp3314 init\n");

	if (pinfo == NULL) {
		LCD_KIT_ERR("pinfo is null\n");
		return LCD_KIT_FAIL;
	}
	if (pinfo->bias_bl_ic_checked != 0) {
		LCD_KIT_ERR("bias bl ic checked\n");
		return LCD_KIT_OK;
	}

	mp3314_bl_info.pfdt = get_lk_overlayed_dtb();
	if (mp3314_bl_info.pfdt == NULL) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return LCD_KIT_FAIL;
	}
	mp3314_bl_info.nodeoffset = fdt_node_offset_by_compatible(
		mp3314_bl_info.pfdt, OFFSET_DEF_VAL, DTS_COMP_MP3314);
	if (mp3314_bl_info.nodeoffset < 0) {
		LCD_KIT_INFO("can not find %s node\n", DTS_COMP_MP3314);
		return LCD_KIT_FAIL;
	}

	ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
		mp3314_bl_info.nodeoffset, MP3314_SUPPORT,
		&mp3314_bl_info.mp3314_support, 0);
	if (ret < 0 || !mp3314_bl_info.mp3314_support) {
		LCD_KIT_ERR("get mp3314_support failed!\n");
		goto exit;
	}

	ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
		mp3314_bl_info.nodeoffset, MP3314_HW_DUAL_IC,
		&mp3314_bl_info.dual_ic, 0);
	if (ret < 0)
		LCD_KIT_ERR("parse dts dual_ic fail!\n");

	ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
		mp3314_bl_info.nodeoffset, MP3314_I2C_BUS_ID,
		&mp3314_bl_info.mp3314_i2c_bus_id, 0);
	if (ret < 0) {
		LCD_KIT_ERR("parse dts mp3314_i2c_bus_id fail!\n");
		mp3314_bl_info.mp3314_i2c_bus_id = 0;
		goto exit;
	}
	if (mp3314_bl_info.dual_ic) {
		ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
			mp3314_bl_info.nodeoffset, MP3314_2_I2C_BUS_ID,
			&mp3314_bl_info.mp3314_2_i2c_bus_id, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts mp3314_2_i2c_bus_id fail!\n");
			mp3314_bl_info.mp3314_2_i2c_bus_id = 0;
			goto exit;
		}
	}
	ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
		mp3314_bl_info.nodeoffset, GPIO_MP3314_EN_NAME,
		&mp3314_bl_info.mp3314_hw_en, 0);
	if (ret < 0) {
		LCD_KIT_ERR(" parse dts mp3314_hw_enable fail!\n");
		mp3314_bl_info.mp3314_hw_en = 0;
		return LCD_KIT_FAIL;
	}

	if (mp3314_bl_info.mp3314_hw_en) {
		ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
			mp3314_bl_info.nodeoffset, MP3314_HW_EN_GPIO,
			&mp3314_bl_info.mp3314_hw_en_gpio, 0);
		if (ret < 0) {
			LCD_KIT_ERR("parse dts mp3314_hw_en_gpio fail!\n");
			mp3314_bl_info.mp3314_hw_en_gpio = 0;
			goto exit;
		}
		if (mp3314_bl_info.dual_ic) {
			ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
				mp3314_bl_info.nodeoffset, MP3314_2_HW_EN_GPIO,
				&mp3314_bl_info.mp3314_2_hw_en_gpio, 0);
			if (ret < 0) {
				LCD_KIT_ERR("parse dts mp3314_2_hw_en_gpio fail!\n");
				mp3314_bl_info.mp3314_2_hw_en_gpio = 0;
				goto exit;
			}
			if (mp3314_bl_info.mp3314_hw_en_gpio == mp3314_bl_info.mp3314_2_hw_en_gpio) {
				is_dual_hw_en_gpio_same = true;
			}
		}
		ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
			mp3314_bl_info.nodeoffset, MP3314_HW_EN_DELAY,
			&mp3314_bl_info.bl_on_lk_mdelay, 0);
		if (ret < 0)
			LCD_KIT_INFO("parse dts bl_on_lk_mdelay fail!\n");
	}

	ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
		mp3314_bl_info.nodeoffset, MP3314_BL_LEVEL,
		&mp3314_bl_info.bl_level, MP3314_BL_DEFAULT_LEVEL);
	if (ret < 0)
		LCD_KIT_ERR("parse dts mp3314_bl_level fail!\n");

	ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
		mp3314_bl_info.nodeoffset, "mp3314_level_lsb",
		&mp3314_bl_info.mp3314_level_lsb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get mp3314_level_lsb dts failed\n");
		goto exit;
	}
	ret = lcd_kit_get_dts_u32_default(mp3314_bl_info.pfdt,
			mp3314_bl_info.nodeoffset, "mp3314_level_msb",
		&mp3314_bl_info.mp3314_level_msb, 0);
	if (ret < 0) {
		LCD_KIT_ERR("get mp3314_level_msb dts failed\n");
		goto exit;
	}

	ret = mp3314_backlight_ic_check();
	if (ret == LCD_KIT_OK) {
		pinfo->bias_bl_ic_checked = 1;
		LCD_KIT_INFO("mp3314 is checked\n");
	}
	LCD_KIT_INFO("[%s]:mp3314 is support\n", __FUNCTION__);

exit:
	return ret;
}

