/*
 * mp3314.h
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

#ifndef __LINUX_MP3314_H
#define __LINUX_MP3314_H

#ifndef MP3314_OK
#define MP3314_OK 0
#endif

#ifndef MP3314_FAIL
#define MP3314_FAIL (-1)
#endif

#define MP3314_SLAV_ADDR 0x28
#define MP3314_I2C_SPEED                    100

#define DTS_COMP_MP3314 "mp,mp3314"
#define MP3314_SUPPORT "mp3314_support"
#define MP3314_I2C_BUS_ID "mp3314_i2c_bus_id"
#define MP3314_2_I2C_BUS_ID "mp3314_2_i2c_bus_id"
#define GPIO_MP3314_EN_NAME "mp3314_hw_enable"
#define MP3314_HW_EN_GPIO "mp3314_hw_en_gpio"
#define MP3314_2_HW_EN_GPIO "mp3314_2_hw_en_gpio"

#define MP3314_HW_ENABLE "mp3314_hw_enable"
#define MP3314_HW_EN_DELAY	"bl_on_lk_mdelay"
#define MP3314_BL_LEVEL	"bl_level"
#define MP3314_HW_DUAL_IC	"dual_ic"

/* base reg */
#define MP3314_EPROM_CFG00			0X00
#define MP3314_EPROM_CFG01			0X01
#define MP3314_BL_EN_CTL			0X02
#define MP3314_EPROM_CFG03			0X03
#define MP3314_EPROM_CFG04			0X04
#define MP3314_EPROM_CFG05			0X05
#define MP3314_EPROM_CFG06			0X06
#define MP3314_EPROM_CFG07			0X07
#define MP3314_EPROM_CFG08			0X08
#define MP3314_EPROM_CFG09			0X09
#define MP3314_EPROM_CFG0A			0X0A
#define MP3314_EPROM_CFG0B			0X0B
#define MP3314_EPROM_CFG0C			0X0C
#define MP3314_EPROM_CFG0D			0X0D
#define MP3314_EPROM_CFG0E                      0x0E
#define MP3314_EPROM_CFG0F                      0x0F
#define MP3314_EPROM_CFG10                      0x10
#define MP3314_EPROM_CFG11                      0x11
#define MP3314_EPROM_CFG1D                      0x1D
#define MP3314_EPROM_CFG1F                      0x1F

#define MP3314_WRITE_LEN 2
#define MP3314_RW_REG_MAX  16
#define MP3314_BL_DEFAULT_LEVEL 255
#define MP3314_BL_MAX 65535
#define BL_DISABLE_CTL 0X9C
struct mp3314_backlight_information {
	/* whether support mp3314 or not */
	int mp3314_support;
	/* which i2c bus controller mp3314 mount */
	int mp3314_i2c_bus_id;
	int mp3314_2_i2c_bus_id;
	int mp3314_hw_en;
	/* mp3314 hw_en gpio */
	int mp3314_hw_en_gpio;
	int mp3314_2_hw_en_gpio;
	/* Dual mp3314 ic */
	int dual_ic;
	int mp3314_reg[MP3314_RW_REG_MAX];
	int bl_on_lk_mdelay;
	int bl_level;
	int nodeoffset;
	void *pfdt;
	int mp3314_level_lsb;
	int mp3314_level_msb;
};

int mp3314_init(struct mtk_panel_info *pinfo);
#ifdef MTK_LCD_KIT_LK2_SUPPORT
void mp3314_set_backlight_status(void *fdt);
#else
void mp3314_set_backlight_status(void);
#endif

#endif /* __LINUX_MP3314_H */
