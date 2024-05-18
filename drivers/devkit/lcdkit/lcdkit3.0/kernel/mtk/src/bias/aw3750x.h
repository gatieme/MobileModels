/*
 * Copyright (c) aw3750x, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __LINUX_AW3750X_LED_H__
#define __LINUX_AW3750X_LED_H__

#define AW3750x_VENDOR_ID_MASK	(3 << 0)
#define AW3750x_VENDOR_ID		0x01

#define AW37501_VERSION_ID		0x16
#define AW37501A_VERSION_ID		0x96
#define AW37501B_DEVICE_ID		0x05
#define AW37502_VERSION_ID		0x12
#define AW37503_VERSION_ID		0x04
#define AW37504_VERSION_ID		0x40
#define AW37505_VERSION_ID		0x00

#define AW37501_LOAD_CAPABILITY	0x96
#define AW37502_LOAD_CAPABILITY	0x92
#define AW37503_LOAD_CAPABILITY	0x84
#define AW37504_LOAD_CAPABILITY	0x84

/* aw3750x register */
#define AW3750X_REG_VOUTP		0x00
#define AW3750X_REG_VOUTN		0x01
#define AW3750X_REG_APPS		0x03
#define AW3750X_REG_CTRL		0x04
#define AW3750X_REG_DEVID		0x06

#define AW3750X_REG_PRO			0x21
#define AW3750X_REG_VERSION		0x44
#define AW3750X_REG_TRIM		0x46
#define AW3750X_REG_PRO2		0x61

#define AW3750X_REG_MAX			0x4f
#define AW3750X_OPEN_CMD		0x4C
#define AW3750X_OPEN_CMD2		0x2C

#define AW3750X_OPEN_LIMIT_CURRENT	0x96
#define AW3750X_CLOSE_CMD			0x00
#define AW3750X_OUT_CLEAR			0xE0

/*register read/write access*/
#define REG_NONE_ACCESS			0
#define REG_RD_ACCESS			(1 << 0)
#define REG_WR_ACCESS			(1 << 1)
#define AW_I2C_RETRIES			5

#define AW3750X_SOFT_RESET		(1 << 5)
#define AW_SOFT_RESET_MASK		~(1 << 5)
#define AW3750X_APPS_APPS_BIT		(1 << 6)
#define AW3750X_CTRL_ILMTNCP_BIT	(1 << 3)

#define AW3750X_DISN_ENABLE		(1 << 0)
#define AW3750X_DISN_DISABLE	(~(1 << 0))
#define AW3750X_DISP_ENABLE		(1 << 1)
#define AW3750X_DISP_DISABLE	(~(1 << 1))
#define AW3750X_DISN_MASK		(~(1 << 0))
#define AW3750X_DISP_MASK		(~(1 << 1))

#define AW3750X_ENN_ENABLE		(1 << 4)
#define AW3750X_ENN_DISABLE		(~(1 << 4))
#define AW3750X_ENP_ENABLE		(1 << 3)
#define AW3750X_ENP_DISABLE		(~(1 << 3))
#define AW3750X_ENP_IS_ENABLE	(1 << 3)
#define AW3750X_ENN_IS_ENABLE	(~(1 << 3))
#define AW3750X_ENN_MASK		(~(1 << 4))
#define AW3750X_ENP_MASK		(~(1 << 3))

#define AW_CURRENT_40MA			40000
#define AW_CURRENT_80MA			80000
#define AW_CURRENT_100MA		100000
#define AW_CURRENT_120MA		120000
#define AW_CURRENT_150MA		150000
#define AW_CURRENT_220MA		220000

#define AW37501_CURRENT_GET		(3 << 6)
#define AW37501_CURRENT_MASK	(~(3 << 6))

#define AW37502_CURRENT_GET		(3 << 6)
#define AW37502_CURRENT_MASK	(~(3 << 6))

#define AW37503_CURRENT_GET		(3 << 6)
#define AW37503_CURRENT_CLEAR	(~(3 << 6))

#define AW37505_CURRENT_GET		(1 << 6)
#define AW37505_CURRENT_MASK	(~(1 << 6))

#define AW37501_CURRENT_40MA_VAL	0
#define AW37501_CURRENT_80MA_VAL	(1 << 6)
#define AW37501_CURRENT_100MA_VAL	(2 << 6)

#define AW37501B_CURRENT_40MA_VAL	0
#define AW37501B_CURRENT_80MA_VAL	(1 << 6)
#define AW37501B_CURRENT_120MA_VAL	(2 << 6)
#define AW37501B_CURRENT_150MA_VAL	(3 << 6)

#define AW37502_CURRENT_40MA_VAL	0
#define AW37502_CURRENT_80MA_VAL	(1 << 6)
#define AW37502_CURRENT_100MA_VAL	(1 << 7)

#define AW37503_CURRENT_80MA_VAL	0
#define AW37503_CURRENT_150MA_VAL	(3 << 6)
#define AW37503_CURRENT_MASK		(~(3 << 6))

#define AW37504_CURRENT_CTRL		(1 << 3)
#define AW37504_CURRENT_APPS		(1 << 6)
#define AW37504_CURRENT_CTRL_MASK	(~(1 << 3))
#define AW37504_CURRENT_APPS_MASK	(~(1 << 6))

#define AW37505_CURRENT_80MA_VAL	(0)
#define AW37505_CURRENT_150MA_VAL	(1 << 6)

#define MIN_VOLTAGE				4000000
#define MIN_VOLTAGE_VAL			0x00
#define MAX_VOLTAGE_VAL			0x19

#define AW37501_MAX_VOLTAGE		0X14
#define AW37502_MAX_VOLTAGE		0X19
#define AW37503_MAX_VOLTAGE		0X14
#define AW37505_MAX_VOLTAGE		0X19


#define N_VOLTAGE				26
#define UV_STEP					100000

#define MAX_LOO_CURRENT			370
#define MIN_LOD_CURRENT			270
#define LOO_CURRENT_MASK		(~(1 << 4))
#define LOD_CURRENT_VAL			(1 << 4)

typedef struct {
	int voutp;
	int voutn;
	u8  vout_reg;
} AW_VOUT;

#define LCD_BIAS_VOL_40 4000000
#define LCD_BIAS_VOL_41 4100000
#define LCD_BIAS_VOL_42 4200000
#define LCD_BIAS_VOL_43 4300000
#define LCD_BIAS_VOL_44 4400000
#define LCD_BIAS_VOL_45 4500000
#define LCD_BIAS_VOL_46 4600000
#define LCD_BIAS_VOL_47 4700000
#define LCD_BIAS_VOL_48 4800000
#define LCD_BIAS_VOL_49 4900000
#define LCD_BIAS_VOL_50 5000000
#define LCD_BIAS_VOL_51 5100000
#define LCD_BIAS_VOL_52 5200000
#define LCD_BIAS_VOL_53 5300000
#define LCD_BIAS_VOL_54 5400000
#define LCD_BIAS_VOL_55 5500000
#define LCD_BIAS_VOL_56 5600000
#define LCD_BIAS_VOL_57 5700000
#define LCD_BIAS_VOL_58 5800000
#define LCD_BIAS_VOL_59 5900000
#define LCD_BIAS_VOL_60 6000000

enum {
	AW3750X_VOL_40 = 0x00,
	AW3750X_VOL_41 = 0x01,
	AW3750X_VOL_42 = 0x02,
	AW3750X_VOL_43 = 0x03,
	AW3750X_VOL_44 = 0x04,
	AW3750X_VOL_45 = 0x05,
	AW3750X_VOL_46 = 0x06,
	AW3750X_VOL_47 = 0x07,
	AW3750X_VOL_48 = 0x08,
	AW3750X_VOL_49 = 0x09,
	AW3750X_VOL_50 = 0x0A,
	AW3750X_VOL_51 = 0x0B,
	AW3750X_VOL_52 = 0x0C,
	AW3750X_VOL_53 = 0x0D,
	AW3750X_VOL_54 = 0x0E,
	AW3750X_VOL_55 = 0x0F,
	AW3750X_VOL_56 = 0x10,
	AW3750X_VOL_57 = 0x11,
	AW3750X_VOL_58 = 0x12,
	AW3750X_VOL_59 = 0x13,
	AW3750X_VOL_60 = 0x14,
	AW3750X_VOL_MAX
};

struct aw3750x_voltage {
        int voltage;
        unsigned char value;
};

struct aw3750x_pinctrl {
	struct pinctrl *pinctrl;
	struct pinctrl_state *aw_enn_default;
	struct pinctrl_state *aw_enn_high;
	struct pinctrl_state *aw_enn_low;
	struct pinctrl_state *aw_enp_default;
	struct pinctrl_state *aw_enp_high;
	struct pinctrl_state *aw_enp_low;
};

struct aw3750x_power {
	struct i2c_client *client;
	struct device *dev;
	struct mutex lock;
	struct aw3750x_pinctrl pinctrl;
	struct regulator_init_data *init_data;
	struct regulator_dev *regulators[2];
	struct device_node *aw_node[2];
	int vendorID;
	int enn_gpio;
	int enp_gpio;
	int offset;
	int limit;
	int power_mode;
	int read_power_mode;
	int outp;
	int outn;
	int outn_set;
	int outp_set;
	int read_outp;
	int read_outn;
	int aw3750x_gpio_ctrl;
	u8 aw3750x_version_id;
	unsigned select;

};

#endif
