// SPDX-License-Identifier: GPL-2.0
/*
 * hl7136_i2c.c
 *
 * hl7136 i2c interface
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

#include "hl7136.h"
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <securec.h>

#define HWLOG_TAG hl7136_i2c
HWLOG_REGIST();

int hl7136_read_block(struct hl7136_device_info *di, u8 *value,
	u8 reg, unsigned int num_bytes)
{
	return power_i2c_read_block(di->client, &reg, 1, value, num_bytes);
}

int hl7136_write_block(struct hl7136_device_info *di, u8 reg, u8 *value,
	unsigned int num_bytes)
{
	u8 *buf = NULL;
	int ret;

	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	buf = kzalloc(num_bytes + 1, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	buf[0] = reg;
	if (memcpy_s(&buf[1], num_bytes, value, num_bytes) != EOK) {
		kfree(buf);
		return -ENOMEM;
	}

	ret = power_i2c_write_block(di->client, buf, num_bytes + 1);
	kfree(buf);
	return ret;
}


int hl7136_write_byte(struct hl7136_device_info *di, u8 reg, u8 value)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_u8_write_byte(di->client, reg, value);
}

int hl7136_read_byte(struct hl7136_device_info *di, u8 reg, u8 *value)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_u8_read_byte(di->client, reg, value);
}

int hl7136_write_mask(struct hl7136_device_info *di, u8 reg, u8 mask, u8 shift,
	u8 value)
{
	int ret;
	u8 val = 0;

	ret = hl7136_read_byte(di, reg, &val);
	if (ret < 0)
		return ret;

	val &= ~mask;
	val |= ((value << shift) & mask);

	return hl7136_write_byte(di, reg, val);
}

int hl7136_read_word(struct hl7136_device_info *di, u8 reg, u16 *value)
{
	if (!di || (di->chip_already_init == 0)) {
		hwlog_err("chip not init\n");
		return -EIO;
	}

	return power_i2c_u8_read_word(di->client, reg, value, true);
}
