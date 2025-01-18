// SPDX-License-Identifier: GPL-2.0
/*
 * power_i2c.c
 *
 * i2c interface for power module
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#include <securec.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_i2c.h>
#include <chipset_common/hwpower/common_module/power_printk.h>

#define HWLOG_TAG power_i2c
HWLOG_REGIST();

#define LEN_WR_MSG     1
#define LEN_RD_MSG     2
#define LEN_U8_REG     1
#define LEN_U16_REG    2
#define LEN_U8_DAT     1
#define LEN_U16_DAT    2
#define LEN_U8_PEC     1
#define LEN_WR_ADDR    1
#define LEN_RD_ADDR    1
#define CRC8_DATA_BITS_CNT  8
#define CRC8_HIGHEST_BIT    0x80
#define CRC8_STD_POLY       0x07    // polynomial:x8+x2+x+1,0x107 igonre hightest bit is 0x07

static u8 power_i2c_calc_crc8(u8 *data, u8 len)
{
	/*
	 * The PEC is a CRC-8 error-checking byte, calculated on all the
	 * message bytes (including addresses and read/write bits)
	 */
	int i;
	u8 crc = 0;

	if (!data || (len < 1)) {
		hwlog_err("invalid crc para\n");
		return 0;
	}
	while (len--) {
		crc ^= *data++;
		for (i = 0; i < CRC8_DATA_BITS_CNT; i++) {
			if (crc & CRC8_HIGHEST_BIT)
				crc = (crc << 1) ^ CRC8_STD_POLY;
			else
				crc <<= 1;
		}
	}
	return crc;
}

int power_i2c_read_block_without_cmd(struct i2c_client *client,
	u8 *buf, u8 buf_len)
{
	struct i2c_msg msg;

	if (!client || !buf) {
		hwlog_err("client or buf is null\n");
		return -EINVAL;
	}

	/* flags: I2C_M_RD is read data, from slave to master */
	msg.addr = client->addr;
	msg.flags = I2C_M_RD;
	msg.buf = buf;
	msg.len = buf_len;

	if (i2c_transfer(client->adapter, &msg, 1) != 1) {
		hwlog_err("addr=%x read fail\n", client->addr);
		return -EIO;
	}

	return 0;
}

int power_i2c_write_block(struct i2c_client *client, u8 *buf, u8 buf_len)
{
	struct i2c_msg msg[LEN_WR_MSG];

	if (!client || !buf) {
		hwlog_err("client or buf is null\n");
		return -EINVAL;
	}

	/* flags: 0 is write data, from master to slave */
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = buf;
	msg[0].len = buf_len;

	/* i2c_transfer return number of messages transferred */
	if (i2c_transfer(client->adapter, msg, LEN_WR_MSG) != LEN_WR_MSG) {
		hwlog_err("addr=%x write fail\n", client->addr);
		return -EIO;
	}

	return 0;
}

int power_i2c_read_block(struct i2c_client *client, u8 *cmd, u8 cmd_len,
	u8 *buf, u8 buf_len)
{
	struct i2c_msg msg[LEN_RD_MSG];

	if (!client || !cmd || !buf) {
		hwlog_err("client or cmd or buf is null\n");
		return -EINVAL;
	}

	/* the cmd to be written before reading data */
	/* flags: 0 is write data, from master to slave */
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = cmd;
	msg[0].len = cmd_len;

	/* flags: I2C_M_RD is read data, from slave to master */
	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].buf = buf;
	msg[1].len = buf_len;

	/* i2c_transfer return number of messages transferred */
	if (i2c_transfer(client->adapter, msg, LEN_RD_MSG) != LEN_RD_MSG) {
		hwlog_err("addr=%x read fail\n", client->addr);
		return -EIO;
	}

	return 0;
}

int power_i2c_u8_write_byte(struct i2c_client *client, u8 reg, u8 data)
{
	u8 buf[LEN_U8_REG + LEN_U8_DAT] = { 0 };

	/*
	 * buf[0]: 8bit slave register address
	 * buf[1]: 8bit data to be written
	 */
	buf[0] = reg;
	buf[1] = data;

	return power_i2c_write_block(client, buf, sizeof(buf));
}

int power_i2c_u8_write_word(struct i2c_client *client, u8 reg, u16 data)
{
	u8 buf[LEN_U8_REG + LEN_U16_DAT] = { 0 };

	/*
	 * buf[0]: 8bit slave register address
	 * buf[1]: low-8bit data to be written
	 * buf[2]: high-8bit data to be written
	 */
	buf[0] = reg;
	buf[1] = data & 0xff;
	buf[2] = data >> 8;

	return power_i2c_write_block(client, buf, sizeof(buf));
}

int power_i2c_u16_write_byte(struct i2c_client *client, u16 reg, u8 data)
{
	u8 buf[LEN_U16_REG + LEN_U8_DAT] = { 0 };

	/*
	 * buf[0]: high-8bit slave register address
	 * buf[1]: low-8bit slave register address
	 * buf[2]: data to be written
	 */
	buf[0] = reg >> 8;
	buf[1] = reg & 0xff;
	buf[2] = data;

	return power_i2c_write_block(client, buf, sizeof(buf));
}

int power_i2c_u16_write_word(struct i2c_client *client, u16 reg, u16 data)
{
	u8 buf[LEN_U16_REG + LEN_U16_DAT] = { 0 };

	/*
	 * buf[0]: high-8bit slave register address
	 * buf[1]: low-8bit slave register address
	 * buf[2]: low-8bit data to be written
	 * buf[3]: high-8bit data to be written
	 */
	buf[0] = reg >> 8;
	buf[1] = reg & 0xff;
	buf[2] = data & 0xff;
	buf[3] = data >> 8;

	return power_i2c_write_block(client, buf, sizeof(buf));
}

int power_i2c_u8_read_byte(struct i2c_client *client, u8 reg, u8 *data)
{
	u8 cmd[LEN_U8_REG] = { 0 };
	u8 buf[LEN_U8_DAT] = { 0 };

	/* cmd[0]: 8bit register */
	cmd[0] = reg;

	if (power_i2c_read_block(client, cmd, sizeof(cmd), buf, sizeof(buf)))
		return -EIO;

	/* buf[0]: 8bit data */
	*data = buf[0];
	return 0;
}

int power_i2c_u8_read_word(struct i2c_client *client, u8 reg, u16 *data, bool endian)
{
	u8 cmd[LEN_U8_REG] = { 0 };
	u8 buf[LEN_U16_DAT] = { 0 };

	/* cmd[0]: 8bit register */
	cmd[0] = reg;

	if (power_i2c_read_block(client, cmd, sizeof(cmd), buf, sizeof(buf)))
		return -EIO;

	/*
	 * endian is ture, buf[0]: high-8bit data, buf[1]: low-8bit data
	 * endian is false, buf[0]: low-8bit data, buf[1]: high-8bit data
	 */
	if (endian)
		*data = (buf[1] | (buf[0] << 8));
	else
		*data = (buf[0] | (buf[1] << 8));
	return 0;
}

int power_i2c_u16_read_byte(struct i2c_client *client, u16 reg, u8 *data)
{
	u8 cmd[LEN_U16_REG] = { 0 };
	u8 buf[LEN_U8_DAT] = { 0 };

	/* cmd[0]: high-8bit register, cmd[1]: low-8bit register */
	cmd[0] = reg >> 8;
	cmd[1] = reg & 0xff;

	if (power_i2c_read_block(client, cmd, sizeof(cmd), buf, sizeof(buf)))
		return -EIO;

	/* buf[0]: 8bit data */
	*data = buf[0];
	return 0;
}

int power_i2c_u16_read_word(struct i2c_client *client, u16 reg, u16 *data, bool endian)
{
	u8 cmd[LEN_U16_REG] = { 0 };
	u8 buf[LEN_U16_DAT] = { 0 };

	/* cmd[0]: high-8bit register, cmd[1]: low-8bit register */
	cmd[0] = reg >> 8;
	cmd[1] = reg & 0xff;

	if (power_i2c_read_block(client, cmd, sizeof(cmd), buf, sizeof(buf)))
		return -EIO;

	/*
	 * endian is ture, buf[0]: high-8bit data, buf[1]: low-8bit data
	 * endian is false, buf[0]: low-8bit data, buf[1]: high-8bit data
	 */
	if (endian)
		*data = (buf[1] | (buf[0] << 8));
	else
		*data = (buf[0] | (buf[1] << 8));
	return 0;
}

int power_i2c_u8_write_byte_mask(struct i2c_client *client, u8 reg, u8 data,
	u8 mask, u8 shift)
{
	u8 tmp_data = 0;

	if (power_i2c_u8_read_byte(client, reg, &tmp_data))
		return -EIO;

	tmp_data &= ~mask;
	tmp_data |= ((data << shift) & mask);

	return power_i2c_u8_write_byte(client, reg, tmp_data);
}

int power_i2c_u8_read_byte_mask(struct i2c_client *client, u8 reg, u8 *data,
	u8 mask, u8 shift)
{
	u8 tmp_data = 0;

	if (power_i2c_u8_read_byte(client, reg, &tmp_data))
		return -EIO;

	tmp_data &= mask;
	tmp_data >>= shift;
	*data = tmp_data;

	return 0;
}

int power_i2c_write_block_with_crc(struct i2c_client *client, u8 *buf, u8 buf_len)
{
	int ret;
	u8 *buf_crc = NULL;

	if (!client || !buf) {
		hwlog_err("client or buf is null\n");
		return -EINVAL;
	}

	buf_crc = kcalloc(LEN_WR_ADDR + buf_len + LEN_U8_PEC, sizeof(u8), GFP_KERNEL);
	if (!buf_crc)
		return -ENOMEM;

	buf_crc[0] = (client->addr << 1);
	memcpy_s(&buf_crc[LEN_WR_ADDR], buf_len + LEN_U8_PEC, buf, buf_len);
	buf_crc[LEN_WR_ADDR + buf_len] = power_i2c_calc_crc8(buf_crc, buf_len + LEN_WR_ADDR);
	ret = power_i2c_write_block(client, &buf_crc[LEN_WR_ADDR], buf_len + LEN_U8_PEC);

	kfree(buf_crc);
	return ret;
}

int power_i2c_read_block_with_crc(struct i2c_client *client, u8 *cmd, u8 cmd_len,
	u8 *buf, u8 buf_len)
{
	int ret;
	u8 pec_val;
	int pec_index;
	int data_index;
	int buf_crc_len;
	u8 *buf_crc = NULL;

	if (!client || !cmd || !buf) {
		hwlog_err("client or cmd or buf is null\n");
		return -EINVAL;
	}

	buf_crc_len = LEN_WR_ADDR + cmd_len + LEN_RD_ADDR + buf_len + LEN_U8_PEC;
	buf_crc = kcalloc(buf_crc_len, sizeof(u8), GFP_KERNEL);
	if (!buf_crc)
		return -ENOMEM;

	buf_crc[0] = (client->addr << 1);
	memcpy_s(&buf_crc[LEN_WR_ADDR], buf_crc_len - LEN_WR_ADDR, cmd, cmd_len);
	buf_crc[LEN_RD_ADDR + cmd_len] = ((client->addr << 1) | I2C_M_RD);
	data_index = LEN_WR_ADDR + cmd_len + LEN_RD_ADDR;
	ret = power_i2c_read_block(client, cmd, cmd_len, &buf_crc[data_index], buf_len + LEN_U8_PEC);
	if (ret) {
		kfree(buf_crc);
		return ret;
	}

	if (buf_len > LEN_U16_DAT)
		/* when read block,the first u8 is the below len of data */
		pec_index = buf_crc[data_index] + data_index + sizeof(buf_crc[data_index]);
	else
		pec_index = buf_len + data_index;
	if (pec_index >= buf_crc_len) {
		hwlog_err("i2c data len error, pec_index:%d, buf_crc_len:%d\n", pec_index, buf_crc_len);
		kfree(buf_crc);
		return -EIO;
	}

	pec_val = power_i2c_calc_crc8(buf_crc, pec_index);
	if (pec_val != buf_crc[pec_index]) {
		hwlog_err("crc check fail\n");
		kfree(buf_crc);
		return -EIO;
	}
	memcpy_s(&buf[0], buf_len, &buf_crc[data_index], buf_len);

	kfree(buf_crc);
	return ret;
}

int power_i2c_u8_write_word_with_crc(struct i2c_client *client, u8 reg, u16 data)
{
	u8 buf[LEN_U8_REG + LEN_U16_DAT] = {0};

	/*
	 * buf[0]: 8bit slave register address
	 * buf[1]: low-8bit data to be written
	 * buf[2]: high-8bit data to be written
	 */
	buf[0] = reg;
	buf[1] = data & POWER_MASK_BYTE;
	buf[2] = data >> POWER_BITS_PER_BYTE;

	return power_i2c_write_block_with_crc(client, buf, sizeof(buf));
}

int power_i2c_u8_read_word_with_crc(struct i2c_client *client, u8 reg, u16 *data, bool endian)
{
	u8 cmd[LEN_U8_REG] = {0};
	u8 buf[LEN_U16_DAT] = {0};

	/* cmd[0]: 8bit register */
	cmd[0] = reg;

	if (power_i2c_read_block_with_crc(client, cmd, sizeof(cmd), buf, sizeof(buf)))
		return -EIO;

	/*
	 * endian is ture, buf[0]: high-8bit data, buf[1]: low-8bit data
	 * endian is false, buf[0]: low-8bit data, buf[1]: high-8bit data
	 */
	if (endian)
		*data = (buf[1] | (buf[0] << POWER_BITS_PER_BYTE));
	else
		*data = (buf[0] | (buf[1] << POWER_BITS_PER_BYTE));
	return 0;
}

int power_i2c_u8_write_byte_with_crc(struct i2c_client *client, u8 reg, u8 data)
{
	u8 buf[LEN_U8_REG + LEN_U8_DAT] = {0};

	/*
	 * buf[0]: 8bit slave register address
	 * buf[1]: 8bit data to be written
	 */
	buf[0] = reg;
	buf[1] = data;

	return power_i2c_write_block_with_crc(client, buf, sizeof(buf));
}

int power_i2c_u8_read_byte_with_crc(struct i2c_client *client, u8 reg, u8 *data)
{
	u8 cmd[LEN_U8_REG] = {0};
	u8 buf[LEN_U8_DAT] = {0};

	/* cmd[0]: 8bit register */
	cmd[0] = reg;

	if (power_i2c_read_block_with_crc(client, cmd, sizeof(cmd), buf, sizeof(buf)))
		return -EIO;

	/* buf[0]: 8bit data */
	*data = buf[0];
	return 0;
}
