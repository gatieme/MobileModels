/*
* Simple driver for Texas Instruments LM3630 LED Flash driver chip
* Copyright (C) 2012 Texas Instruments
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#ifndef __LINUX_LM36274_H
#define __LINUX_LM36274_H

#define LM36274_NAME "lm36274"
#define DTS_COMP_LM36274 "ti,lm36274"

#define MAX_RATE_NUM 9
/* base reg */
#define REG_REVISION 0x01
#define REG_BL_CONFIG_1 0x02
#define REG_BL_CONFIG_2 0x03
#define REG_BL_BRIGHTNESS_LSB 0x04
#define REG_BL_BRIGHTNESS_MSB 0x05
#define REG_AUTO_FREQ_LOW 0x06
#define REG_AUTO_FREQ_HIGH 0x07
#define REG_BL_ENABLE 0x08
#define REG_DISPLAY_BIAS_CONFIG_1 0x09
#define REG_DISPLAY_BIAS_CONFIG_2 0x0A
#define REG_DISPLAY_BIAS_CONFIG_3 0x0B
#define REG_LCM_BOOST_BIAS 0x0C
#define REG_VPOS_BIAS 0x0D
#define REG_VNEG_BIAS 0x0E
#define REG_FLAGS 0x0F
#define REG_BL_OPTION_1 0x10
#define REG_BL_OPTION_2 0x11
#define REG_PWM_TO_DIGITAL_LSB 0x12
#define REG_PWM_TO_DIGITAL_MSB 0x13
#define REG_MAX 0x13

/* mask code */
#define MASK_BL_LSB 0x07
#define DEVICE_FAULT_OCCUR 0

#define BL_MIN 0
#define BL_MAX 2047

#ifndef BIT
#define BIT(x)  (1<<(x))
#endif

#define LOG_LEVEL_INFO 8

#define LM36274_EMERG(msg, ...)    \
	do { if (lm36274_msg_level > 0)  \
		printk(KERN_EMERG "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define LM36274_ALERT(msg, ...)    \
	do { if (lm36274_msg_level > 1)  \
		printk(KERN_ALERT "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define LM36274_CRIT(msg, ...)    \
	do { if (lm36274_msg_level > 2)  \
		printk(KERN_CRIT "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define LM36274_ERR(msg, ...)    \
	do { if (lm36274_msg_level > 3)  \
		printk(KERN_ERR "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define LM36274_WARNING(msg, ...)    \
	do { if (lm36274_msg_level > 4)  \
		printk(KERN_WARNING "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define LM36274_NOTICE(msg, ...)    \
	do { if (lm36274_msg_level > 5)  \
		printk(KERN_NOTICE "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define LM36274_INFO(msg, ...)    \
	do { if (lm36274_msg_level > 6)  \
		printk(KERN_INFO "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define LM36274_DEBUG(msg, ...)    \
	do { if (lm36274_msg_level > 7)  \
		printk(KERN_DEBUG "[lm36274]%s: "msg, __func__, ## __VA_ARGS__); } while (0)

struct lm36274_chip_data {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	struct semaphore test_sem;
};
#define LM36274_RW_REG_MAX 13

static struct backlight_information {
	/* whether support lm36274 or not */
	int lm36274_support;
	/* which i2c bus controller lm36274 mount */
	int lm36274_i2c_bus_id;
	/* lm36274 hw_en gpio */
	int lm36274_hw_en_gpio;
	int lm36274_reg[LM36274_RW_REG_MAX];
};

static struct backlight_information bl_info;

static char *lm36274_dts_string[LM36274_RW_REG_MAX] = {
	"lm36274_bl_config_1",
	"lm36274_bl_config_2",
	"lm36274_auto_freq_low",
	"lm36274_auto_freq_high",
	"lm36274_display_bias_config_1",
	"lm36274_display_bias_config_2",
	"lm36274_display_bias_config_3",
	"lm36274_lcm_boost_bias",
	"lm36274_vpos_bias",
	"lm36274_vneg_bias",
	"lm36274_bl_option_1",
	"lm36274_bl_option_2",
	"lm36274_bl_en",
};

static char lm36274_reg_addr[LM36274_RW_REG_MAX] = {
		REG_BL_CONFIG_1,
		REG_BL_CONFIG_2,
		REG_AUTO_FREQ_LOW,
		REG_AUTO_FREQ_HIGH,
		REG_DISPLAY_BIAS_CONFIG_1,
		REG_DISPLAY_BIAS_CONFIG_2,
		REG_DISPLAY_BIAS_CONFIG_3,
		REG_LCM_BOOST_BIAS,
		REG_VPOS_BIAS,
		REG_VNEG_BIAS,
		REG_BL_OPTION_1,
		REG_BL_OPTION_2,
		REG_BL_ENABLE,
};

ssize_t lm36274_set_backlight_reg(uint32_t bl_level);

#endif /* __LINUX_LM36274_H */

