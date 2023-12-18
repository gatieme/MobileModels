/*
 * lcd_kit_sysfs_fac.h
 *
 * lcdkit factory sys node function for lcd driver head file
 *
 * Copyright (c) 2022-2024 Huawei Technologies Co., Ltd.
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

#ifndef _LCD_KIT_SYSFS_FAC_H_
#define _LCD_KIT_SYSFS_FAC_H_
#include "lcd_kit_common.h"
#define LCD_KIT_PCD_DETECT_OPEN  1
#define LCD_KIT_PCD_DETECT_CLOSE 0

int lcd_kit_sysfs_fac_init(struct device *dev);
#endif
