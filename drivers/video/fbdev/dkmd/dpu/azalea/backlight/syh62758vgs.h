/*
* Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
* Description: backlight driver of syh62758vgs
* Create: 2023-06-13
*/

#ifndef __LINUX_SYH62758VGS_H
#define __LINUX_SYH62758VGS_H

#include "dpu_fb.h"

#if defined(CONFIG_LCDKIT_DRIVER)
#include "lcdkit_panel.h"
#endif

#define SYH62758VGS_NAME "syh62758vgs"
#define DTS_COMP_SYH62758VGS "syh,syh62758vgs"

#define syh62758vgs_bit_offset(x)  (1<<(x))

/* base reg */
#define SYH62758VGS_DEVICE_CONTROL      0X01
#define SYH62758VGS_DEVICE_CHECK        0X03
#define SYH62758VGS_EPROM_CFG0          0XA0
#define SYH62758VGS_EPROM_CFG1          0XA1
#define SYH62758VGS_EPROM_CFG2          0XA2
#define SYH62758VGS_EPROM_CFG3          0XA3
#define SYH62758VGS_EPROM_CFG4          0XA4
#define SYH62758VGS_EPROM_CFG5          0XA5
#define SYH62758VGS_EPROM_CFG6          0XA6
#define SYH62758VGS_EPROM_CFG7          0XA7
#define SYH62758VGS_EPROM_CFG9          0XA9
#define SYH62758VGS_EPROM_CFGA          0XAA
#define SYH62758VGS_EPROM_CFGE          0XAE
#define SYH62758VGS_EPROM_CFG98         0X98
#define SYH62758VGS_EPROM_CFG9E         0X9E
#define SYH62758VGS_LED_ENABLE          0X16
#define SYH62758VGS_FUALT_FLAG          0X02
#define SYH62758VGS_ENABLE_ALL_LEDS      0x3f
#define SYH62758VGS_DISABLE_ALL_LEDS     0X00
#define SYH62758VGS_FAULT_SHORT_BIT      6
#define SYH62758VGS_FAULT_OPEN_BIT       7
#define SYH62758VGS_LED1_SHORT_ERR_BIT   10
#define SYH62758VGS_LED1_OPEN_ERR_BIT    4
#define SYH62758VGS_LED_NUM              6

#define TEST_OK                  0
#define TEST_ERROR_DEV_NULL      syh62758vgs_bit_offset(0)
#define TEST_ERROR_DATA_NULL     syh62758vgs_bit_offset(1)
#define TEST_ERROR_CLIENT_NULL   syh62758vgs_bit_offset(2)
#define TEST_ERROR_I2C           syh62758vgs_bit_offset(3)
#define TEST_ERROR_LED1_OPEN     syh62758vgs_bit_offset(4)
#define TEST_ERROR_LED2_OPEN     syh62758vgs_bit_offset(5)
#define TEST_ERROR_LED3_OPEN     syh62758vgs_bit_offset(6)
#define TEST_ERROR_LED4_OPEN     syh62758vgs_bit_offset(7)
#define TEST_ERROR_LED5_OPEN     syh62758vgs_bit_offset(8)
#define TEST_ERROR_LED6_OPEN     syh62758vgs_bit_offset(9)

#define SYH62758VGS_BL_MIN 0
#define SYH62758VGS_BL_MAX 4095

/* I2C Bus number */
#define I2C3_BUSNUM 3
#define I2C4_BUSNUM 4

#define syh62758vgs_emrg(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 0) \
			printk(KERN_EMERG "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758vgs_alert(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 1) \
			printk(KERN_ALERT "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758vgs_crit(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 2) \
			printk(KERN_CRIT "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758vgs_err(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 3) \
			printk(KERN_ERR "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758vgs_warning(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 4) \
			printk(KERN_WARNING "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758vgs_notice(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 5) \
			printk(KERN_NOTICE "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758vgs_info(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 6) \
			printk(KERN_INFO "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)
#define syh62758vgs_debug(msg, ...) \
	do { \
		if (syh62758vgs_msg_level > 7) \
			printk(KERN_DEBUG "[syh backlight]%s: "msg, \
				__func__, ## __VA_ARGS__); \
	} while (0)

struct syh62758vgs_chip_data {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	struct semaphore test_sem;
};

#define GPIO_SYH62758VGS_EN_NAME "syh62758vgs_hw_en"
#define SYH62758VGS_RW_REG_MAX  18
#define SYH62758VGS_DEVICE_CONTROL_VAL 0x84
#define SYH62758VGS_EPROM_CFG9E_VAL 0x02
#define SYH62758VGS_DEVICE_ID 0x63

enum syh62758vgs_dual_ic {
	DUAL_SYH62758VGS_NONE = 0,
	DUAL_SYH62758VGS_I3C,
	DUAL_SYH62758VGS_I2C,
};

struct syh62758vgs_backlight_information {
	/* whether support syh62758vgs or not */
	int syh62758vgs_support;
	/* which i2c bus controller syh62758vgs mount */
	int syh62758vgs_i2c_bus_id;
	/* which i2c bus controller the second syh62758vgs mount */
	int syh62758vgs_2_i2c_bus_id;
	/* syh62758vgs hw_en gpio */
	int syh62758vgs_hw_en_gpio;
	/* syh62758vgs 2 hw_en gpio */
	int syh62758vgs_2_hw_en_gpio;
	int syh62758vgs_reg[SYH62758VGS_RW_REG_MAX];
	int dual_ic;
	int bl_on_kernel_mdelay;
	int bl_write_reg_mdelay_1;
	int bl_write_reg_mdelay_2;
	int syh62758vgs_level_lsb;
	int syh62758vgs_level_msb;
	int bl_led_num;
};

#endif /* __LINUX_SYH62758VGS_H */
