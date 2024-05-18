/*
 * sy7758.h
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

#ifndef __LINUX_SY7758_H
#define __LINUX_SY7758_H

#ifndef SY7758_OK
#define SY7758_OK 0
#endif

#ifndef SY7758_FAIL
#define SY7758_FAIL (-1)
#endif

#define SY7758_INIT_CMD_NUM 15
#define SY7758_SLAV_ADDR    0x2E
#define SY7758_I2C_SPEED    100

#define DTS_COMP_SY7758     "sy,sy7758"
#define SY7758_SUPPORT      "sy7758_support"
#define SY7758_I2C_BUS_ID   "sy7758_i2c_bus_id"
#define SY7758_2_I2C_BUS_ID "sy7758_2_i2c_bus_id"
#define GPIO_SY7758_EN_NAME "sy7758_hw_enable"
#define SY7758_HW_EN_GPIO   "sy7758_hw_en_gpio"
#define SY7758_2_HW_EN_GPIO "sy7758_2_hw_en_gpio"
#define SY7758_HW_ENABLE    "sy7758_hw_enable"
#define SY7758_HW_EN_DELAY  "bl_on_lk_mdelay"
#define SY7758_BL_LEVEL	    "bl_level"
#define SY7758_HW_DUAL_IC   "dual_ic"

/* base reg */
#define SY7758_DEVICE_CONTROL   0x01
#define SY7758_EPROM_CFG0       0xA0
#define SY7758_EPROM_CFG1       0xA1
#define SY7758_EPROM_CFG2       0xA2
#define SY7758_EPROM_CFG3       0xA3
#define SY7758_EPROM_CFG4       0xA4
#define SY7758_EPROM_CFG5       0xA5
#define SY7758_EPROM_CFG6       0xA6
#define SY7758_EPROM_CFG7       0xA7
#define SY7758_EPROM_CFG9       0xA9
#define SY7758_EPROM_CFGA       0xAA
#define SY7758_EPROM_CFGE       0xAE
#define SY7758_EPROM_CFG98      0x98
#define SY7758_EPROM_CFG9E      0x9E
#define SY7758_EPROM_CFG00      0x00
#define SY7758_EPROM_CFG03      0x03
#define SY7758_EPROM_CFG04      0x04
#define SY7758_EPROM_CFG05      0x05
#define SY7758_EPROM_CFG10      0x10
#define SY7758_EPROM_CFG11      0x11
#define SY7758_LED_ENABLE       0x16
#define SY7758_FUALT_FLAG       0x02

#define SY7758_WRITE_LEN 2
#define SY7758_RW_REG_MAX 23
#define SY7758_BL_DEFAULT_LEVEL 255
#define SY7758_BL_MAX 4095

struct sy7758_backlight_information {
	/* whether support sy7758 or not */
	int sy7758_support;
	/* which i2c bus controller sy7758 mount */
	int sy7758_i2c_bus_id;
	int sy7758_2_i2c_bus_id;
	int sy7758_hw_en;
	/* sy7758 hw_en gpio */
	int sy7758_hw_en_gpio;
	int sy7758_2_hw_en_gpio;
	/* Dual sy7758 ic */
	int dual_ic;
	int sy7758_reg[SY7758_RW_REG_MAX];
	int bl_on_lk_mdelay;
	int bl_level;
	int nodeoffset;
	void *pfdt;
	int sy7758_level_lsb;
	int sy7758_level_msb;
	int ctrl_enable;
};

int sy7758_init(struct mtk_panel_info *pinfo);
#ifdef MTK_LCD_KIT_LK2_SUPPORT
void sy7758_set_backlight_status(void *fdt);
#else
void sy7758_set_backlight_status (void);
#endif

#endif /* __LINUX_SY7758_H */
