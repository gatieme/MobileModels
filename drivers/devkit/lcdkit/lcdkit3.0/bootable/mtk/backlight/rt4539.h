/*
 * rt4539.h
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

#ifndef __LINUX_RT4539_H
#define __LINUX_RT4539_H

#ifndef RT4539_OK
#define RT4539_OK 0
#endif

#ifndef RT4539_FAIL
#define RT4539_FAIL (-1)
#endif

#define RT4539_SLAV_ADDR 0x3C
#define RT4539_I2C_SPEED 100

#define DTS_COMP_RT4539     "rt,rt4539"
#define RT4539_SUPPORT      "rt4539_support"
#define RT4539_I2C_BUS_ID   "rt4539_i2c_bus_id"
#define RT4539_2_I2C_BUS_ID "rt4539_2_i2c_bus_id"
#define GPIO_RT4539_EN_NAME "rt4539_hw_enable"
#define RT4539_HW_EN_GPIO   "rt4539_hw_en_gpio"
#define RT4539_2_HW_EN_GPIO "rt4539_2_hw_en_gpio"
#define RT4539_HW_ENABLE    "rt4539_hw_enable"
#define RT4539_HW_EN_DELAY  "bl_on_lk_mdelay"
#define RT4539_BL_LEVEL     "bl_level"
#define RT4539_HW_DUAL_IC   "dual_ic"

/* base reg */
#define RT4539_EPROM_CFG00 0x00
#define RT4539_EPROM_CFG01 0x01
#define RT4539_EPROM_CFG02 0x02
#define RT4539_EPROM_CFG03 0x03
#define RT4539_EPROM_CFG06 0x06
#define RT4539_EPROM_CFG07 0x07
#define RT4539_EPROM_CFG08 0x08
#define RT4539_EPROM_CFG09 0x09
#define RT4539_EPROM_CFG0A 0x0A
#define RT4539_BL_CONTROL  0x0B
#define RT4539_EPROM_CFG05 0x05
#define RT4539_EPROM_CFG04 0x04

#define RT4539_WRITE_LEN 2
#define RT4539_RW_REG_MAX 12
#define RT4539_BL_DEFAULT_LEVEL 255
#define RT4539_BL_MAX 4095
#define BL_DISABLE_CTL 0x7E

struct rt4539_backlight_information {
	/* whether support rt4539 or not */
	int rt4539_support;
	/* which i2c bus controller rt4539 mount */
	int rt4539_i2c_bus_id;
	int rt4539_2_i2c_bus_id;
	int rt4539_hw_en;
	/* rt4539 hw_en gpio */
	int rt4539_hw_en_gpio;
	int rt4539_2_hw_en_gpio;
	/* Dual rt4539 ic */
	int dual_ic;
	int rt4539_reg[RT4539_RW_REG_MAX];
	int bl_on_lk_mdelay;
	int bl_level;
	int nodeoffset;
	void *pfdt;
	int rt4539_level_lsb;
	int rt4539_level_msb;
};

int rt4539_init(struct mtk_panel_info *pinfo);
#ifdef MTK_LCD_KIT_LK2_SUPPORT
void rt4539_set_backlight_status(void *fdt);
#else
void rt4539_set_backlight_status(void);
#endif

#endif /* __LINUX_RT4539_H */
