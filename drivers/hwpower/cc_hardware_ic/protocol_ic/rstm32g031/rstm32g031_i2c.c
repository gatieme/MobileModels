// SPDX-License-Identifier: GPL-2.0
/*
 * rstm32g031_i2c.c
 *
 * rstm32g031 i2c interface
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

#include "rstm32g031_i2c.h"
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG rstm32g031_i2c
HWLOG_REGIST();

int rstm32g031_write_block(struct rstm32g031_device_info *di, u8 reg, u8 *value,
	unsigned int num_bytes)
{
	u8 *buf = NULL;

	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	buf = kzalloc(num_bytes + 1, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	buf[0] = reg;
	memcpy(&buf[1], value, num_bytes);
	return power_i2c_write_block(di->client, buf, num_bytes + 1);
}

int rstm32g031_read_block(struct rstm32g031_device_info *di, u8 reg, u8 *value,
	unsigned int num_bytes)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_read_block(di->client, &reg, 1, value, num_bytes);
}

int rstm32g031_write_byte(struct rstm32g031_device_info *di, u8 reg, u8 value)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_u8_write_byte(di->client, reg, value);
}

int rstm32g031_read_byte(struct rstm32g031_device_info *di, u8 reg, u8 *value)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_u8_read_byte(di->client, reg, value);
}

int rstm32g031_write_mask(struct rstm32g031_device_info *di, u8 reg, u8 mask,
	u8 shift, u8 value)
{
	int ret;
	u8 val = 0;

	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	ret = rstm32g031_read_byte(di, reg, &val);
	if (ret < 0)
		return ret;

	val &= ~mask;
	val |= ((value << shift) & mask);

	return rstm32g031_write_byte(di, reg, val);
}

int rstm32g031_read_word_bootloader(struct rstm32g031_device_info *di,
	u8 *buf, u8 buf_len)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_read_block_without_cmd(di->client, buf, buf_len);
}

int rstm32g031_write_word_bootloader(struct rstm32g031_device_info *di,
	u8 *cmd, u8 cmd_len)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_write_block(di->client, cmd, cmd_len);
}
