/*
 * lp8556.h
 *
 * adapt for backlight driver
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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

#ifndef __LINUX_LP8556_H
#define __LINUX_LP8556_H

#ifndef LP8556_OK
#define LP8556_OK 0
#endif

#ifndef LP8556_FAIL
#define LP8556_FAIL (-1)
#endif

#define LP8556_SLAV_ADDR 0x2C
#define LP8556_I2C_SPEED                    100

#define DTS_COMP_LP8556 "ti,lp8556"
#define DTS_COMP_LP8556_E11 "ti,lp8556,e11"
#define LP8556_SUPPORT "lp8556_support"
#define LP8556_I2C_BUS_ID "lp8556_i2c_bus_id"
#define LP8556_2_I2C_BUS_ID "lp8556_2_i2c_bus_id"
#define GPIO_LP8556_EN_NAME "lp8556_hw_enable"
#define LP8556_HW_EN_GPIO "lp8556_hw_en_gpio"
#define LP8556_2_HW_EN_GPIO "lp8556_2_hw_en_gpio"

#define LP8556_HW_ENABLE "lp8556_hw_enable"
#define LP8556_HW_EN_DELAY	"bl_on_lk_mdelay"
#define LP8556_BL_LEVEL	"bl_level"
#define LP8556_HW_DUAL_IC	"dual_ic"

/* base reg */
#define LP8556_DEVICE_CONTROL		0X01
#define LP8556_EPROM_CFG0			0XA0
#define LP8556_EPROM_CFG1			0XA1
#define LP8556_EPROM_CFG2			0XA2
#define LP8556_EPROM_CFG3			0XA3
#define LP8556_EPROM_CFG4			0XA4
#define LP8556_EPROM_CFG5			0XA5
#define LP8556_EPROM_CFG6			0XA6
#define LP8556_EPROM_CFG7			0XA7
#define LP8556_EPROM_CFG9			0XA9
#define LP8556_EPROM_CFGA			0XAA
#define LP8556_EPROM_CFGE			0XAE
#define LP8556_EPROM_CFGF			0XAF
#define LP8556_EPROM_CFG98			0X98
#define LP8556_EPROM_CFG9E			0X9E
#define LP8556_EPROM_CFG00          0x00
#define LP8556_EPROM_CFG03          0x03
#define LP8556_EPROM_CFG04          0x04
#define LP8556_EPROM_CFG05          0x05
#define LP8556_EPROM_CFG10          0x10
#define LP8556_EPROM_CFG11          0x11
#define LP8556_LED_ENABLE			0X16
#define LP8556_FUALT_FLAG           0X02

#define LP8556_WRITE_LEN                    2
#define LP8556_RW_REG_MAX  22
#define LP8556_BL_DEFAULT_LEVEL             255
#define LP8556_E11_CFGF_VAL			0x1
#define LP8556_E03_E07_CFGF_VAL		0x3
#define LP8556_BL_MAX	4095

struct lp8556_backlight_information {
	/* whether support lp8556 or not */
	int lp8556_support;
	/* which i2c bus controller lp8556 mount */
	int lp8556_i2c_bus_id;
	int lp8556_2_i2c_bus_id;
	int lp8556_hw_en;
	/* lp8556 hw_en gpio */
	int lp8556_hw_en_gpio;
	int lp8556_2_hw_en_gpio;
	/* Dual lp8556 ic */
	int dual_ic;
	int lp8556_reg[LP8556_RW_REG_MAX];
	int bl_on_lk_mdelay;
	int bl_level;
	int nodeoffset;
	void *pfdt;
	int lp8556_level_lsb;
	int lp8556_level_msb;
	int is_need_compatible;
};

int lp8556_init(struct mtk_panel_info *pinfo);
void lp8556_set_backlight_status (void);

#endif /* __LINUX_LP8556_H */