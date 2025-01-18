/*
* Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
* Description: backlight driver of syh62758
* Create: 2023-06-13
*/

#ifndef __LINUX_SYH62758_H
#define __LINUX_SYH62758_H

#include "dpu_fb.h"

#if defined(CONFIG_LCDKIT_DRIVER)
#include "lcdkit_panel.h"
#endif

#define SYH62758_NAME "syh62758"
#define DTS_COMP_SYH62758 "syh,syh62758"

/* base reg */
#define SYH62758_DEVICE_CONTROL 0X01
#define SYH62758_LED_ENABLE 0XA3
#define SYH62758_FUALT_FLAG 0X02

#define SYH62758_ENABLE_ALL_LEDS      0x3f
#define SYH62758_DISABLE_ALL_LEDS     0X00
#define SYH62758_FAULT_SHORT_BIT      6
#define SYH62758_FAULT_OPEN_BIT       7
#define SYH62758_LED1_SHORT_ERR_BIT   10
#define SYH62758_LED1_OPEN_ERR_BIT    4
#define SYH62758_LED_NUM              6

#define TEST_OK                  0
#define TEST_ERROR_DEV_NULL      bit(0)
#define TEST_ERROR_DATA_NULL     bit(1)
#define TEST_ERROR_CLIENT_NULL   bit(2)
#define TEST_ERROR_I2C           bit(3)
#define TEST_ERROR_LED1_OPEN     bit(4)
#define TEST_ERROR_LED2_OPEN     bit(5)
#define TEST_ERROR_LED3_OPEN     bit(6)
#define TEST_ERROR_LED4_OPEN     bit(7)
#define TEST_ERROR_LED5_OPEN     bit(8)
#define TEST_ERROR_LED6_OPEN     bit(9)

#define SYH62758_BL_MIN 0
#define SYH62758_BL_MAX 4095

/* I2C Bus number */
#define I2C3_BUSNUM 3
#define I2C4_BUSNUM 4

#ifndef BIT
#define bit(x)  (1<<(x))
#endif

#define syh62758_emrg(msg, ...) \
	do { \
		if (syh62758_msg_level > 0) \
			printk(KERN_EMERG "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758_alert(msg, ...) \
	do { \
		if (syh62758_msg_level > 1) \
			printk(KERN_ALERT "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758_crit(msg, ...) \
	do { \
		if (syh62758_msg_level > 2) \
			printk(KERN_CRIT "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758_err(msg, ...) \
	do { \
		if (syh62758_msg_level > 3) \
			printk(KERN_ERR "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758_warning(msg, ...) \
	do { \
		if (syh62758_msg_level > 4) \
			printk(KERN_WARNING "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758_notice(msg, ...) \
	do { \
		if (syh62758_msg_level > 5) \
			printk(KERN_NOTICE "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758_info(msg, ...) \
	do { \
		if (syh62758_msg_level > 6) \
			printk(KERN_INFO "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758_debug(msg, ...) \
	do { \
		if (syh62758_msg_level > 7) \
			printk(KERN_DEBUG "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)

struct syh62758_chip_data {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	struct semaphore test_sem;
};

#define GPIO_SYH62758_EN_NAME "syh62758_hw_en"
#define SYH62758_RW_REG_MAX  2

enum syh62758_dual_ic {
	DUAL_SYH62758_NONE = 0,
	DUAL_SYH62758_I3C,
	DUAL_SYH62758_I2C,
};

struct syh62758_backlight_information {
	/* whether support syh62758 or not */
	int syh62758_support;
	/* which i2c bus controller syh62758 mount */
	int syh62758_i2c_bus_id;
	/* which i2c bus controller the second syh62758 mount */
	int syh62758_2_i2c_bus_id;
	/* syh62758 hw_en gpio */
	int syh62758_hw_en_gpio;
	/* syh62758 2 hw_en gpio */
	int syh62758_2_hw_en_gpio;
	int syh62758_reg[SYH62758_RW_REG_MAX];
	int dual_ic;
	int bl_on_kernel_mdelay;
	int syh62758_level_lsb;
	int syh62758_level_msb;
	int bl_led_num;
};

ssize_t syh62758_set_backlight_init(uint32_t bl_level);

#endif /* __LINUX_SYH62758_H */
