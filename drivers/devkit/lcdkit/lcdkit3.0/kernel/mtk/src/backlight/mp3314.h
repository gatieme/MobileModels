/*
* Simple driver for Texas Instruments LM3630 LED Flash driver chip
* Copyright (C) 2012 Texas Instruments
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#ifndef __LINUX_MP3314_H
#define __LINUX_MP3314_H

#include <linux/module.h>
#include <linux/regmap.h>
#include <linux/gpio.h>
#include <linux/i2c.h>

#define MP3314_NAME "mp3314"
#define DTS_COMP_MP3314 "mp,mp3314"

#define GPIO_DIR_OUT                        1
#define GPIO_OUT_ONE                        1
#define GPIO_OUT_ZERO                       0

/* base reg */
#define MP3314_EPROM_CFG00                      0X00
#define MP3314_EPROM_CFG01                      0X01
#define MP3314_BL_EN_CTL                        0X02
#define MP3314_EPROM_CFG03                      0X03
#define MP3314_EPROM_CFG04                      0X04
#define MP3314_EPROM_CFG05                      0X05
#define MP3314_EPROM_CFG06                      0X06
#define MP3314_EPROM_CFG07                      0X07
#define MP3314_EPROM_CFG08                      0X08
#define MP3314_EPROM_CFG09                      0X09
#define MP3314_EPROM_CFG0A                      0X0A
#define MP3314_EPROM_CFG0B                      0X0B
#define MP3314_EPROM_CFG0C                      0X0C
#define MP3314_EPROM_CFG0D                      0X0D
#define MP3314_EPROM_CFG0E                      0x0E
#define MP3314_EPROM_CFG0F                      0x0F
#define MP3314_EPROM_CFG10                      0x10
#define MP3314_EPROM_CFG11                      0x11
#define MP3314_EPROM_CFG1D                      0x1D
#define MP3314_EPROM_CFG1F                      0x1F


#define REG_MAX                             0x21

#define BL_MAX 65535
#define MP3314_BL_DEFAULT_LEVEL 4095
#define BL_DISABLE_CTL			0x9C

#define mp3314_emerg(msg, ...)    \
	do { if (mp3314_msg_level > 0)  \
		printk(KERN_EMERG "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define mp3314_alert(msg, ...)    \
	do { if (mp3314_msg_level > 1)  \
		printk(KERN_ALERT "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define mp3314_crit(msg, ...)    \
	do { if (mp3314_msg_level > 2)  \
		printk(KERN_CRIT "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define mp3314_err(msg, ...)    \
	do { if (mp3314_msg_level > 3)  \
		printk(KERN_ERR "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define mp3314_warning(msg, ...)    \
	do { if (mp3314_msg_level > 4)  \
		printk(KERN_WARNING "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define mp3314_notice(msg, ...)    \
	do { if (mp3314_msg_level > 5)  \
		printk(KERN_NOTICE "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define mp3314_info(msg, ...)    \
	do { if (mp3314_msg_level > 6)  \
		printk(KERN_INFO "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define mp3314_debug(msg, ...)    \
	do { if (mp3314_msg_level > 7)  \
		printk(KERN_DEBUG "[mp3314]%s: "msg, __func__, ## __VA_ARGS__); } while (0)

struct mp3314_chip_data {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	struct semaphore test_sem;
};

#define MP3314_RW_REG_MAX  16

struct mp3314_backlight_information {
	/* whether support mp3314 or not */
	int mp3314_support;
	/* which i2c bus controller mp3314 mount */
	int mp3314_2_i2c_bus_id;
	int mp3314_hw_en;
	/* mp3314 hw_en gpio */
	int mp3314_hw_en_gpio;
	int mp3314_2_hw_en_gpio;
	int mp3314_reg[MP3314_RW_REG_MAX];
	int dual_ic;
	int bl_on_kernel_mdelay;
	int mp3314_level_lsb;
	int mp3314_level_msb;
	int bl_led_num;
	int bl_level;
};

#endif /* __LINUX_MP3314_H */


