/*
* Simple driver for Texas Instruments LM3630 LED Flash driver chip
* Copyright (C) 2012 Texas Instruments
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#ifndef __LINUX_SY7758_H
#define __LINUX_SY7758_H

#include <linux/module.h>
#include <linux/regmap.h>
#include <linux/gpio.h>
#include <linux/i2c.h>

#define SY7758_NAME "sy7758"
#define DTS_COMP_SY7758 "sy,sy7758"

#define SY7758_INIT_CMD_NUM 15
#define GPIO_DIR_OUT        1
#define GPIO_OUT_ONE        1
#define GPIO_OUT_ZERO       0

/* base reg */
#define SY7758_DEVICE_CONTROL 0x01
#define SY7758_EPROM_CFG0     0xA0
#define SY7758_EPROM_CFG1     0xA1
#define SY7758_EPROM_CFG2     0xA2
#define SY7758_EPROM_CFG3     0xA3
#define SY7758_EPROM_CFG4     0xA4
#define SY7758_EPROM_CFG5     0xA5
#define SY7758_EPROM_CFG6     0xA6
#define SY7758_EPROM_CFG7     0xA7
#define SY7758_EPROM_CFG9     0xA9
#define SY7758_EPROM_CFGA     0xAA
#define SY7758_EPROM_CFGE     0xAE
#define SY7758_EPROM_CFG98    0x98
#define SY7758_EPROM_CFG9E    0x9E
#define SY7758_EPROM_CFG00    0x00
#define SY7758_EPROM_CFG03    0x03
#define SY7758_EPROM_CFG04    0x04
#define SY7758_EPROM_CFG05    0x05
#define SY7758_EPROM_CFG10    0x10
#define SY7758_EPROM_CFG11    0x11
#define SY7758_LED_ENABLE     0x16
#define SY7758_FUALT_FLAG     0x02

#define REG_MAX 0x21
#define BL_MAX 4095

#define sy7758_emerg(msg, ...)    \
	do { if (sy7758_msg_level > 0)  \
		printk(KERN_EMERG "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define sy7758_alert(msg, ...)    \
	do { if (sy7758_msg_level > 1)  \
		printk(KERN_ALERT "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define sy7758_crit(msg, ...)    \
	do { if (sy7758_msg_level > 2)  \
		printk(KERN_CRIT "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define sy7758_err(msg, ...)    \
	do { if (sy7758_msg_level > 3)  \
		printk(KERN_ERR "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define sy7758_warning(msg, ...)    \
	do { if (sy7758_msg_level > 4)  \
		printk(KERN_WARNING "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define sy7758_notice(msg, ...)    \
	do { if (sy7758_msg_level > 5)  \
		printk(KERN_NOTICE "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define sy7758_info(msg, ...)    \
	do { if (sy7758_msg_level > 6)  \
		printk(KERN_INFO "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define sy7758_debug(msg, ...)    \
	do { if (sy7758_msg_level > 7)  \
		printk(KERN_DEBUG "[sy7758]%s: "msg, __func__, ## __VA_ARGS__); } while (0)

struct sy7758_chip_data {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	struct semaphore test_sem;
};

#define SY7758_RW_REG_MAX  23

struct sy7758_backlight_information {
	/* whether support sy7758 or not */
	int sy7758_support;
	/* which i2c bus controller sy7758 mount */
	int sy7758_2_i2c_bus_id;
	int sy7758_hw_en;
	/* sy7758 hw_en gpio */
	int sy7758_hw_en_gpio;
	int sy7758_2_hw_en_gpio;
	int sy7758_reg[SY7758_RW_REG_MAX];
	int dual_ic;
	int bl_on_kernel_mdelay;
	int sy7758_level_lsb;
	int sy7758_level_msb;
	int bl_led_num;
	int ctrl_enable;
};

#endif /* __LINUX_SY7758_H */


