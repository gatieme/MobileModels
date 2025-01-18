/* SPDX-License-Identifier: GPL-2.0 */
/*
 * rstm32g031_i2c.h
 *
 * rstm32g031 i2c header file
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#ifndef _RSTM32G031_I2C_H_
#define _RSTM32G031_I2C_H_

#include "rstm32g031.h"

int rstm32g031_write_block(struct rstm32g031_device_info *di,
	u8 reg, u8 *value, unsigned int num_bytes);
int rstm32g031_read_block(struct rstm32g031_device_info *di,
	u8 reg, u8 *value, unsigned int num_bytes);
int rstm32g031_write_byte(struct rstm32g031_device_info *di, u8 reg, u8 value);
int rstm32g031_read_byte(struct rstm32g031_device_info *di, u8 reg, u8 *value);
int rstm32g031_write_mask(struct rstm32g031_device_info *di,
	u8 reg, u8 mask, u8 shift, u8 value);
int rstm32g031_read_word_bootloader(struct rstm32g031_device_info *di,
	u8 *buf, u8 buf_len);
int rstm32g031_write_word_bootloader(struct rstm32g031_device_info *di,
	u8 *cmd, u8 cmd_len);

#endif /* _RSTM32G031_I2C_H_ */
