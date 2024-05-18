/*
 * lcd_kit_power.h
 *
 * lcdkit power function head file for lcd driver
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

#ifndef __LCD_KIT_POWER_H_
#define __LCD_KIT_POWER_H_

/* macro */
/* backlight */
#define BACKLIGHT_NAME "backlight"
/* bias */
#define BIAS_NAME "bias"
#define VSN_NAME  "dsv_pos"
#define VSP_NAME  "dsv_neg"
/* vci */
#define VCI_NAME  "lcd_vci"
/* iovcc */
#define IOVCC_NAME "iovcc"
/* vdd */
#define VDD_NAME  "vdd"
/* gpio */
#define GPIO_NAME "gpio"

#define LDO_ENABLE 1
#define LDO_DISABLE 0

enum {
	WAIT_TYPE_US = 0,
	WAIT_TYPE_MS,
};

/* dtype for gpio */
enum {
	DTYPE_GPIO_REQUEST,
	DTYPE_GPIO_FREE,
	DTYPE_GPIO_INPUT,
	DTYPE_GPIO_OUTPUT,
	DTYPE_GPIO_PMX,
	DTYPE_GPIO_PULL,
};

enum gpio_operator {
	GPIO_REQ,
	GPIO_FREE,
	GPIO_HIGH,
	GPIO_LOW,
};

/* gpio desc */
struct gpio_desc {
	int dtype;
	int waittype;
	int wait;
	char *label;
	unsigned int *gpio;
	int value;
};

/* dtype for vcc */
enum {
	DTYPE_VCC_GET,
	DTYPE_VCC_PUT,
	DTYPE_VCC_ENABLE,
	DTYPE_VCC_DISABLE,
	DTYPE_VCC_SET_VOLTAGE,
};

/* vcc desc */
struct regulate_bias_desc {
	int min_uv;
	int max_uv;
	int waittype;
	int wait;
};

/* struct */
struct gpio_power_arra {
	enum gpio_operator oper;
	unsigned int num;
	struct gpio_desc *cm;
};

struct event_callback {
	unsigned int event;
	int (*func)(void *data);
};

extern unsigned int g_lcd_kit_gpio;

void lcd_kit_gpio_tx(unsigned int type, unsigned int op);

#endif
