/*
 * bias_bl_utils.h
 *
 * bias_bl_utils head file for honor paltform i2c device
 *
 * Copyright (c) 2019-2019 Honor Device Co., Ltd.
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
#ifndef _BIAS_BL_UTILS_H_
#define _BIAS_BL_UTILS_H_

#include <libfdt.h>

#define FASTBOOT_ERR(msg, args...) do { \
	printf("[LCD_KIT/E]%s: "msg, __func__, ##args); \
} while (0)

#define FASTBOOT_INFO(msg, args...) do { \
	printf("[LCD_KIT/I]%s: "msg, __func__, ##args); \
} while (0)

#define LCD_RET_FAIL (-1)
#define LCD_RET_OK    0
#define INVALID_VALUE 64

enum mtk_i2c_bus_num {
	I2C_BUS_0 = 0,
	I2C_BUS_1 = 1,
	I2C_BUS_2 = 2,
	I2C_BUS_3 = 3,
	I2C_BUS_4 = 4,
	I2C_BUS_5 = 5,
	I2C_BUS_6 = 6,
	I2C_BUS_7 = 7,
	I2C_BUS_8 = 8,
	I2C_BUS_9 = 9,
	I2C_BUS_INVALID = 64
};

enum {
        I2C0 = 0,
        I2C1 = 1,
        I2C2 = 2,
        I2C3 = 3,
        I2C4 = 4,
        I2C5 = 5,
        I2C6 = 6,
        I2C7 = 7,
        I2C8 = 8,
        I2C9 = 9,
        I2C10 = 10,
        I2C11 = 11,
        I2C12 = 12,
        I2C13 = 13,
};

void bias_bl_ops_init(void);
#endif
