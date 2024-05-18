/*
* Simple driver for Texas Instruments LM3630 LED Flash driver chip
* Copyright (C) 2012 Texas Instruments
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#ifndef __LINUX_RT4539_H
#define __LINUX_RT4539_H

#include <linux/module.h>
#include <linux/regmap.h>
#include <linux/gpio.h>
#include <linux/i2c.h>

#define RT4539_NAME "rt4539"
#define DTS_COMP_RT4539 "rt,rt4539"

#define GPIO_DIR_OUT 1
#define GPIO_OUT_ONE 1
#define GPIO_OUT_ZERO 0

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


#define REG_MAX 0x21
#define BL_MAX 4095
#define BL_DISABLE_CTL 0x7E

#define rt4539_emerg(msg, ...)    \
	do { if (rt4539_msg_level > 0)  \
		printk(KERN_EMERG "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define rt4539_alert(msg, ...)    \
	do { if (rt4539_msg_level > 1)  \
		printk(KERN_ALERT "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define rt4539_crit(msg, ...)    \
	do { if (rt4539_msg_level > 2)  \
		printk(KERN_CRIT "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define rt4539_err(msg, ...)    \
	do { if (rt4539_msg_level > 3)  \
		printk(KERN_ERR "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define rt4539_warning(msg, ...)    \
	do { if (rt4539_msg_level > 4)  \
		printk(KERN_WARNING "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define rt4539_notice(msg, ...)    \
	do { if (rt4539_msg_level > 5)  \
		printk(KERN_NOTICE "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define rt4539_info(msg, ...)    \
	do { if (rt4539_msg_level > 6)  \
		printk(KERN_INFO "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define rt4539_debug(msg, ...)    \
	do { if (rt4539_msg_level > 7)  \
		printk(KERN_DEBUG "[rt4539]%s: "msg, __func__, ## __VA_ARGS__); } while (0)

struct rt4539_chip_data {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	struct semaphore test_sem;
};

#define RT4539_RW_REG_MAX  12

struct rt4539_backlight_information {
	/* whether support rt4539 or not */
	int rt4539_support;
	/* which i2c bus controller rt4539 mount */
	int rt4539_2_i2c_bus_id;
	int rt4539_hw_en;
	/* rt4539 hw_en gpio */
	int rt4539_hw_en_gpio;
	int rt4539_2_hw_en_gpio;
	int rt4539_reg[RT4539_RW_REG_MAX];
	int dual_ic;
	int bl_on_kernel_mdelay;
	int rt4539_level_lsb;
	int rt4539_level_msb;
	int bl_led_num;
};

#endif /* __LINUX_RT4539_H */


