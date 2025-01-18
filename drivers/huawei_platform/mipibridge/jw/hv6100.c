/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "hv6100.h"
#include "mipibridge.h"

/* hv6100 config */
#define HV6100_ACF_ADDR_IN_DEVICE		0x40000  // acf addr
#define HV6100_VER_ADDR_IN_DEVICE		0x6C000  // version add in flash
#define HV6100_VER_ADDR_IN_BIN			0x2C000  // version add in firmware
#define HV6100_WRITE_DATA_MAX_LEN		0x2C15C

/* hv6100 spi cmd */
#define HV6100_SPI_SECTOR_ERASE_CMD		0x20        // 4KB Sector Erase(0.1s)
#define HV6100_SPI_BLOCK32_ERASE_CMD	0x52        // 32KB Block Erase(0.3s)
#define HV6100_SPI_BLOCK64_ERASE_CMD	0xD8        // 64KB Block Erase(0.5s)
#define HV6100_SPI_PAGE_PROGRAM_CMD		0x02        // 256B Write(0.7ms)
#define HV6100_SPI_READ_DATA_CMD		0x03        // Stand Read(Max 120MHz)
#define HV6100_SPI_READ_STATUS_CMD		0x05
#define HV6100_SPI_WRITE_STATUS_CMD		0x01
#define HV6100_SPI_WRITE_STATUS_CMD_EXPECT	0x00
#define HV6100_SPI_ENABLE_DISABLE_STATUS_CMD	0x02
#define HV6100_SPI_ENABLE_STATUS_CMD_EXPECT		0x02
#define HV6100_SPI_DISABLE_STATUS_CMD_EXPECT	0x00
#define HV6100_SPI_WRITE_ENABLE_CMD		0x06
#define HV6100_SPI_WRITE_DISABLE_CMD	0x04
#define HV6100_SPI_ERASE_PAGES_NUM		3
#define HV6100_SPI_WRITE_BUFF_LEN		256
#define HV6100_SPI_WRITE_BUFF_MAX_LEN	300
#define HV6100_SPI_LOAD_RETRY_TIMES		3
#define HV6100_SPI_CMD_RETRY_TIMES		50000
#define HV6100_SPI_WRITE_TEMP_BUFF_LEN	4
#define HV6100_SPI_READ_TEMP_BUFF_LEN	2

/* hv6100 uart cmd */
#define HV6100_MSG_IDX_HEADER_1		0
#define HV6100_MSG_IDX_HEADER_2		1
#define HV6100_MSG_IDX_HEADER_3		2
#define HV6100_MSG_IDX_INFO_1		3
#define HV6100_MSG_IDX_INFO_2		4
#define HV6100_MSG_IDX_INFO_3		5
#define HV6100_MSG_IDX_INFO_4		6
#define HV6100_MSG_IDX_TAIL_1		7
#define HV6100_MSG_IDX_TAIL_2		8
#define HV6100_MSG_IDX_TAIL_3		9
#define HV6100_MSG_HEADER_1		0xAA
#define HV6100_MSG_HEADER_2		0x87
#define HV6100_MSG_HEADER_3		0x37
#define HV6100_MSG_TAIL_1		0xAA
#define HV6100_MSG_TAIL_2		0x55
#define HV6100_MSG_TAIL_3		0xFF
#define HV6100_MSG_PRE_CHECK	0xA1016100
#define HV6100_MSG_CHECK_STATUS_NUM	8
#define HV6100_REG_CTRL_ADDR		0x00
#define HV6100_REG_BOOT_VER_ADDR	0x01
#define HV6100_REG_APP_VER_ADDR		0x02
#define HV6100_REG_X_ADDR			0x03
#define HV6100_REG_Y_ADDR			0x04
#define HV6100_REG_STATUS_ADDR		0x05
#define HV6100_REG_BOOT_APP_ADDR	0x06
#define HV6100_REG_RESULT_ADDR		0x07
#define HV6100_UART_MSG_BUFF_LEN		10
#define HV6100_UART_MSG_RECV_TIMEOUT	100
#define HV6100_UART_BUFF_LEN		32

/* hv6100 upgrade result */
#define HV6100_ADDR_RESULT			0x6C010
#define HV6100_RESULT_SIZE			4
#define HV6100_IDX_STATUS_ERASE		0
#define HV6100_IDX_STATUS_VERIFY	1
#define HV6100_IDX_VERIFY_NUM_H		2
#define HV6100_IDX_VERIFY_NUM_L		3
#define HV6100_SUCC			0x10
#define HV6100_ERR			0x01
#define HV6100_FW_VER_SIZE		4
#define HV6100_FW_VER_ADDR_0	0
#define HV6100_FW_VER_ADDR_1	1
#define HV6100_FW_VER_ADDR_2	2
#define HV6100_FW_VER_ADDR_3	3

/* firmware bin path */
#define JW_PATH_FW "mipibridge/hv6100.bin"

static uint8_t g_rdata_buf[HV6100_SPI_WRITE_BUFF_LEN] = {0};
static uint8_t g_wdata_buf[HV6100_SPI_WRITE_BUFF_MAX_LEN] = {0};
static uint8_t g_hv6100_trans_buffer[HV6100_UART_BUFF_LEN] = {0};
static const struct firmware *g_firmware = NULL;

static int hv6100_spi_transfer_read_check(uint8_t judge, uint8_t except)
{
	uint8_t tmp_rchar[HV6100_SPI_READ_TEMP_BUFF_LEN] = {0xff, 0xff};
	int ret = MIPI_BRIDGE_OK;
	int retry = 0;

	do {
		ret = mipibridge_spi_recive_transfer(HV6100_SPI_READ_STATUS_CMD, tmp_rchar, 1);
		if (ret < 0) {
			mipibridge_errmsg("mipibridge_spi_recive_transfer fail!\n");
			return MIPI_BRIDGE_FAIL;
		}
		retry++;
	} while (((tmp_rchar[0] & judge) != except) && retry < HV6100_SPI_CMD_RETRY_TIMES);

	if (retry >= HV6100_SPI_CMD_RETRY_TIMES) {
		mipibridge_errmsg("mipibridge_spi_recive_transfer retry %d fail tmp_rchar[0] = 0x%x, is not 0x%x!\n",
			HV6100_SPI_CMD_RETRY_TIMES, tmp_rchar[0], except);
		return MIPI_BRIDGE_FAIL;
	}

	return MIPI_BRIDGE_OK;
}

static int hv6100_spi_flash_erase(unsigned long erase_addr, uint8_t erase_type)
{
	uint8_t tmp_tchar[HV6100_SPI_WRITE_TEMP_BUFF_LEN] = {0};
	int ret = MIPI_BRIDGE_OK;
	int retry = 0;

	tmp_tchar[0] = HV6100_SPI_WRITE_ENABLE_CMD;
	ret = mipibridge_spi_send_transfer(tmp_tchar, 1); /* 1: length of sent bytes */
	if (ret < 0)
		goto err;

	ret = hv6100_spi_transfer_read_check(HV6100_SPI_ENABLE_DISABLE_STATUS_CMD, HV6100_SPI_ENABLE_STATUS_CMD_EXPECT);
	if (ret < 0)
		goto err;

	tmp_tchar[0] = erase_type;
	tmp_tchar[1] = (uint8_t)(erase_addr >> SHIFT_16);	/* 1: bit17~24 */
	tmp_tchar[2] = (uint8_t)(erase_addr >> SHIFT_8);	/* 2: bit8~16  */
	tmp_tchar[3] = (uint8_t)(erase_addr & 0xff);		/* 3: bit0~7   */
	ret = mipibridge_spi_send_transfer(tmp_tchar, 4);	/* 4: length of sent bytes */
	if (ret < 0)
		goto err;

	ret = hv6100_spi_transfer_read_check(HV6100_SPI_WRITE_STATUS_CMD, HV6100_SPI_WRITE_STATUS_CMD_EXPECT);
	if (ret < 0)
		goto err;

	tmp_tchar[0] = HV6100_SPI_WRITE_DISABLE_CMD;
	ret = mipibridge_spi_send_transfer(tmp_tchar, 1); /* 1: length of sent bytes */
	if (ret < 0)
		goto err;

	ret = hv6100_spi_transfer_read_check(HV6100_SPI_ENABLE_DISABLE_STATUS_CMD, HV6100_SPI_DISABLE_STATUS_CMD_EXPECT);
	if (ret < 0)
		goto err;

	return ret;

err:
	mipibridge_errmsg("hv6100_spi_transfer fail!\n");
	return MIPI_BRIDGE_FAIL;
}

static int hv6100_spi_flash_write(unsigned long page_addr, uint8_t *wdata_buf, unsigned int wdata_len)
{
	uint8_t tmp_tchar[HV6100_SPI_WRITE_TEMP_BUFF_LEN] = {0};
	int ret = MIPI_BRIDGE_OK;
	int retry = 0;

	if (!wdata_buf || wdata_len > HV6100_SPI_WRITE_BUFF_LEN)
		return MIPI_BRIDGE_FAIL;

	tmp_tchar[0] = HV6100_SPI_WRITE_ENABLE_CMD;
	ret = mipibridge_spi_send_transfer(tmp_tchar, 1); /* 1: length of sent bytes */
	if (ret < 0)
		goto err;

	ret = hv6100_spi_transfer_read_check(HV6100_SPI_ENABLE_DISABLE_STATUS_CMD, HV6100_SPI_ENABLE_STATUS_CMD_EXPECT);
	if (ret < 0)
		goto err;

	g_wdata_buf[0] = HV6100_SPI_PAGE_PROGRAM_CMD;
	g_wdata_buf[1] = (uint8_t)(page_addr >> SHIFT_16);	/* 1: bit17~24 */
	g_wdata_buf[2] = (uint8_t)(page_addr >> SHIFT_8);	/* 2: bit8~16  */
	g_wdata_buf[3] = (uint8_t)(page_addr & 0xff);		/* 3: bit0~7   */
	ret = memcpy_s(&g_wdata_buf[4], HV6100_SPI_WRITE_BUFF_LEN, wdata_buf, wdata_len);	/* 4: length of sent head bytes */
	if (ret != EOK) {
		mipibridge_errmsg("memcpy_s fail err %d\n", ret);
		return MIPI_BRIDGE_FAIL;
	}
	ret = mipibridge_spi_send_transfer(g_wdata_buf, 4 + wdata_len);	/* 4: length of sent head bytes */
	if (ret < 0)
		goto err;

	ret = hv6100_spi_transfer_read_check(HV6100_SPI_WRITE_STATUS_CMD, HV6100_SPI_WRITE_STATUS_CMD_EXPECT);
	if (ret < 0)
		goto err;

	tmp_tchar[0] = HV6100_SPI_WRITE_DISABLE_CMD;
	ret = mipibridge_spi_send_transfer(tmp_tchar, 1); /* 1: length of sent bytes */
	if (ret < 0)
		goto err;

	ret = hv6100_spi_transfer_read_check(HV6100_SPI_ENABLE_DISABLE_STATUS_CMD, HV6100_SPI_DISABLE_STATUS_CMD_EXPECT);
	if (ret < 0)
		goto err;

	return ret;

err:
	mipibridge_errmsg("hv6100_spi_transfer fail!\n");
	return MIPI_BRIDGE_FAIL;
}

static int hv6100_spi_flash_read(unsigned long read_addr, uint8_t *rdata_buf, unsigned int rdata_len)
{
	uint8_t tmp_tchar[HV6100_SPI_WRITE_TEMP_BUFF_LEN] = {0};
	int ret = MIPI_BRIDGE_OK;

	if (!rdata_buf || rdata_len == 0) {
		mipibridge_errmsg("rdata_buf is NULL!\n");
		return MIPI_BRIDGE_FAIL;
	}

	tmp_tchar[0] = HV6100_SPI_READ_DATA_CMD;
	tmp_tchar[1] = (uint8_t)(read_addr >> SHIFT_16);	/* 1: bit17~24 */
	tmp_tchar[2] = (uint8_t)(read_addr >> SHIFT_8);		/* 2: bit8~16  */
	tmp_tchar[3] = (uint8_t)(read_addr & 0xff);			/* 3: bit0~7   */
	ret = mipibridge_spi_send_and_receive_transfer(tmp_tchar, 4, rdata_buf, rdata_len); /* 4: length of sent head bytes */

	return ret;
}

static int hv6100_spi_firmware_load_and_check(uint32_t load_addr, uint8_t *data_addr, uint32_t len)
{
	int ret = MIPI_BRIDGE_OK;
	int retry = 0;
	int i = 0;

	if (!data_addr)
		return MIPI_BRIDGE_FAIL;

	if (len == 0) {
		mipibridge_infomsg("write data len is 0\n");
		return MIPI_BRIDGE_OK;
	}

	do {
		ret = hv6100_spi_flash_write(load_addr, data_addr, len);
		if (ret) {
			mipibridge_errmsg("hv6100_spi_flash_write 0x%x fail!\n", load_addr);
			return MIPI_BRIDGE_FAIL;
		}
		ret = hv6100_spi_flash_read(load_addr, g_rdata_buf, len);
		if (ret) {
			mipibridge_errmsg("hv6100_spi_flash_read 0x%x fail!\n", load_addr);
			return MIPI_BRIDGE_FAIL;
		}
		for (i = 0; i < len; i++) {
			if (g_rdata_buf[i] != *(data_addr + i)) {
				mipibridge_errmsg("addr:[0x%x]|val:0x%x write 0x%x fail!\n", load_addr + i, g_rdata_buf[i], *(data_addr + i));
				retry++;
				break;
			}
		}
	} while (retry > 0 && retry < HV6100_SPI_LOAD_RETRY_TIMES && i < len);

	return retry == HV6100_SPI_LOAD_RETRY_TIMES ? MIPI_BRIDGE_FAIL : MIPI_BRIDGE_OK;
}

static int hv6100_spi_firmware_version_check(uint8_t *fw_data)
{
	int ret = MIPI_BRIDGE_OK;
	uint32_t bridge_version = 0;
	uint32_t fw_version = 0;

	if (!fw_data) {
		mipibridge_errmsg("firmware err!!!\n");
		return FIRMWARE_ERROR_FW;
	}

	/* 4: length of read bytes */
	ret = hv6100_spi_flash_read(HV6100_VER_ADDR_IN_DEVICE, g_rdata_buf, HV6100_FW_VER_SIZE);
	if (ret < 0) {
		mipibridge_errmsg("hv6100_spi_flash_read fail!\n");
		return FIRMWARE_UPGRADE_FAIL;
	}

	bridge_version = (g_rdata_buf[HV6100_FW_VER_ADDR_2] << SHIFT_8) | g_rdata_buf[HV6100_FW_VER_ADDR_3];
	mipibridge_infomsg("bridge_version = 0x%x, version = %x-%x-%x-%x\n", bridge_version,
		g_rdata_buf[HV6100_FW_VER_ADDR_0], g_rdata_buf[HV6100_FW_VER_ADDR_1],
		g_rdata_buf[HV6100_FW_VER_ADDR_2], g_rdata_buf[HV6100_FW_VER_ADDR_3]);

	fw_version = (fw_data[HV6100_VER_ADDR_IN_BIN + HV6100_FW_VER_ADDR_2] << SHIFT_8)
		| fw_data[HV6100_VER_ADDR_IN_BIN + HV6100_FW_VER_ADDR_3];
	mipibridge_infomsg("fw_version = 0x%x, version = %x-%x-%x-%x\n", fw_version,
		fw_data[HV6100_VER_ADDR_IN_BIN],
		fw_data[HV6100_VER_ADDR_IN_BIN + HV6100_FW_VER_ADDR_1],
		fw_data[HV6100_VER_ADDR_IN_BIN + HV6100_FW_VER_ADDR_2],
		fw_data[HV6100_VER_ADDR_IN_BIN + HV6100_FW_VER_ADDR_3]);

	if (fw_version <= bridge_version) {
		mipibridge_errmsg("older firmware, bridge_version=0x%x, fs_version=0x%x\n",
			bridge_version, fw_version);
		return FIRMWARE_UPGRADE_OLD;
	}

	return FIRMWARE_UPGRADE_CHECK_OK;
}

static int hv6100_spi_firmware_flash_erase(void)
{
	int ret = MIPI_BRIDGE_OK;
	int i = 0;
	bool sts_ok = false;

	do {
		ret = hv6100_spi_flash_erase(HV6100_VER_ADDR_IN_DEVICE, HV6100_SPI_SECTOR_ERASE_CMD);
		if (ret < 0) {
			i++;
			mipibridge_errmsg("erase %d times fail, retry\n", i);
			continue;
		}
		ret = hv6100_spi_flash_read(HV6100_VER_ADDR_IN_DEVICE, g_rdata_buf, HV6100_FW_VER_SIZE);
		if (ret < 0) {
			i++;
			mipibridge_errmsg("read %d times fail, retry\n", i);
			continue;
		}

		sts_ok = g_rdata_buf[HV6100_FW_VER_ADDR_0] == 0xFF &&
			g_rdata_buf[HV6100_FW_VER_ADDR_1] == 0xFF &&
			g_rdata_buf[HV6100_FW_VER_ADDR_2] == 0xFF &&
			g_rdata_buf[HV6100_FW_VER_ADDR_3] == 0xFF;
		if (!sts_ok) {
			i++;
			mipibridge_errmsg("erase version fail %d times, version = 0x%x-%x-%x-%x\n",
				i, g_rdata_buf[HV6100_FW_VER_ADDR_0], g_rdata_buf[HV6100_FW_VER_ADDR_1],
				g_rdata_buf[HV6100_FW_VER_ADDR_2], g_rdata_buf[HV6100_FW_VER_ADDR_3]);
			continue;
		}

		break;
	} while (i < HV6100_SPI_LOAD_RETRY_TIMES);

	if (i >= HV6100_SPI_LOAD_RETRY_TIMES) {
		mipibridge_errmsg("retry %d times, erase err! return \n", i);
		return MIPI_BRIDGE_FAIL;
	}

	for (i = 0; i < HV6100_SPI_ERASE_PAGES_NUM; i++) {
		ret = hv6100_spi_flash_erase(HV6100_ACF_ADDR_IN_DEVICE + i * (1 << SHIFT_16), HV6100_SPI_BLOCK64_ERASE_CMD);
		if (ret < 0) {
			mipibridge_errmsg("hv6100_spi_flash_erase 0x%x fail\n", HV6100_ACF_ADDR_IN_DEVICE + i * (1 << SHIFT_16));
			return ret;
		}
	}

	return ret;
}

static int hv6100_spi_write_result(int cmd, int verify_times)
{
	uint8_t result[HV6100_RESULT_SIZE] = { 0 };
	int addr = 0;
	int ret = 0;

	if (cmd < UPGRADE_FLASH_ERASE_ERR || cmd >= UPGRADE_FLASH_MAX) {
		mipibridge_errmsg("cmd = %d, verify_times = %d\n", cmd, verify_times);
		return MIPI_BRIDGE_FAIL;
	}

	mipibridge_infomsg("cmd = %d, verify_times = %d\n", cmd, verify_times);

	if (cmd == UPGRADE_FLASH_ERASE_ERR) {
		result[HV6100_IDX_STATUS_ERASE] = HV6100_ERR;
	} else if (cmd == UPGRADE_FLASH_WRITE_ERR) {
		result[HV6100_IDX_STATUS_ERASE] = HV6100_SUCC;
		result[HV6100_IDX_STATUS_VERIFY] = HV6100_ERR;
	} else if (cmd == UPGRADE_FLASH_SUCC) {
		result[HV6100_IDX_STATUS_ERASE] = HV6100_SUCC;
		result[HV6100_IDX_STATUS_VERIFY] = HV6100_SUCC;
	}

	result[HV6100_IDX_VERIFY_NUM_H] = (uint8_t)(verify_times >> SHIFT_8);;
	result[HV6100_IDX_VERIFY_NUM_L] = (uint8_t)(verify_times & 0xFF);

	mipibridge_infomsg("upgrade result[] = 0x%x-%x-%x-%x\n",
		result[HV6100_IDX_STATUS_ERASE], result[HV6100_IDX_STATUS_VERIFY],
		result[HV6100_IDX_VERIFY_NUM_H], result[HV6100_IDX_VERIFY_NUM_L]);
	ret = hv6100_spi_firmware_load_and_check(HV6100_ADDR_RESULT, result, HV6100_RESULT_SIZE);
	if (ret < 0) {
		mipibridge_errmsg("save_and_check fail! ret = %d\n", ret);
		return ret;
	}

	return FIRMWARE_UPGRADE_SUCC;
}

static int hv6100_spi_firmware_flash_write(const struct firmware *firmware)
{
	uint32_t i = 0;
	uint32_t pack_num = 0;
	uint32_t load_addr = HV6100_ACF_ADDR_IN_DEVICE;
	uint32_t load_len = 0;
	uint8_t *data_addr = NULL;

	if (!firmware || firmware->size > HV6100_WRITE_DATA_MAX_LEN || !firmware->data) {
		mipibridge_errmsg("firmware err!\n");
		return FIRMWARE_NOT_FIND_FW;
	}

	pack_num = firmware->size >> SHIFT_8;
	data_addr = (uint8_t *)(firmware->data);
	mipibridge_infomsg("pack_num is %d, load_addr is 0x%x\n", pack_num, load_addr);

	for (i = 0; i <= pack_num; i++) {
		/* first send the last pack */
		load_len = (i != pack_num) ? HV6100_SPI_WRITE_BUFF_LEN : (firmware->size % HV6100_SPI_WRITE_BUFF_LEN);
		if (hv6100_spi_firmware_load_and_check(load_addr, data_addr, load_len) < 0) {
			mipibridge_errmsg("load_and_check fail\n");
			hv6100_spi_write_result(UPGRADE_FLASH_WRITE_ERR, i);
			return FIRMWARE_UPGRADE_FAIL;
		}
		load_addr += HV6100_SPI_WRITE_BUFF_LEN;
		data_addr += HV6100_SPI_WRITE_BUFF_LEN;
	}

	hv6100_spi_write_result(UPGRADE_FLASH_SUCC, pack_num);
	return FIRMWARE_UPGRADE_SUCC;
}

static int hv6100_spi_firmware_load(struct device *dev)
{
	int ret = 0;
	mipibridge_infomsg("enter\n");

	if (!dev) {
		mipibridge_errmsg("dev NULL\n");
		return FIRMWARE_UPGRADE_FAIL;
	}

	if (!g_firmware || g_firmware->size > HV6100_WRITE_DATA_MAX_LEN || !g_firmware->data) {
		mipibridge_errmsg("firmware err!\n");
		ret = FIRMWARE_ERROR_FW;
		goto err;
	}

	ret = hv6100_spi_firmware_version_check((uint8_t *)(g_firmware->data));
	if (ret != FIRMWARE_UPGRADE_CHECK_OK) {
		mipibridge_errmsg("check fw version err, not upgrade! ret=%d\n", ret);
		goto err;
	}

	ret = hv6100_spi_firmware_flash_erase();
	if (ret < 0) {
		ret = FIRMWARE_UPGRADE_FAIL;
		hv6100_spi_write_result(UPGRADE_FLASH_ERASE_ERR, 0);
		goto err;
	}

	ret = hv6100_spi_firmware_flash_write(g_firmware);
err:
	mipibridge_infomsg("exit, ret=%d\n", ret);
	release_firmware(g_firmware);
	/* FIRMWARE_UPGRADE_SUCC:success, other:fail */
	return ret;
}

static int hv6100_uart_recv(uint8_t *buffer, size_t len, unsigned int *value)
{
	bool sts_ok = false;

	if (!buffer || len < HV6100_UART_MSG_BUFF_LEN) {
		mipibridge_errmsg("buffer err, len = %d\n", len);
		return MIPI_BRIDGE_FAIL;
	}

	/* 0:head1 1:head2 2:head3 3:bit25~31 4:bit16~24 5:bit8~15 6:bit0~7 7:tail1 8:tail2 9:tail3 */
	sts_ok = buffer[HV6100_MSG_IDX_HEADER_1] == HV6100_MSG_HEADER_1 &&
		buffer[HV6100_MSG_IDX_HEADER_2] == HV6100_MSG_HEADER_2 &&
		buffer[HV6100_MSG_IDX_HEADER_3] == HV6100_MSG_HEADER_3 &&
		buffer[HV6100_MSG_IDX_TAIL_1] == HV6100_MSG_TAIL_1 &&
		buffer[HV6100_MSG_IDX_TAIL_2] == HV6100_MSG_TAIL_2 &&
		buffer[HV6100_MSG_IDX_TAIL_3] == HV6100_MSG_TAIL_3;
	if (sts_ok) {
		*value = FOUR_U8_TO_U32(buffer[HV6100_MSG_IDX_INFO_1], buffer[HV6100_MSG_IDX_INFO_2],
			buffer[HV6100_MSG_IDX_INFO_3], buffer[HV6100_MSG_IDX_INFO_4]);
		mipibridge_errmsg("recv data = 0x%x\n", *value);
		return MIPI_BRIDGE_OK;
	}

	mipibridge_errmsg("buffer[0-9] = %x-%x-%x-%x-%x-%x-%x-%x-%x-%x\n",
		buffer[HV6100_MSG_IDX_HEADER_1], buffer[HV6100_MSG_IDX_HEADER_2], buffer[HV6100_MSG_IDX_HEADER_3],
		buffer[HV6100_MSG_IDX_INFO_1], buffer[HV6100_MSG_IDX_INFO_2],
		buffer[HV6100_MSG_IDX_INFO_3], buffer[HV6100_MSG_IDX_INFO_4],
		buffer[HV6100_MSG_IDX_TAIL_1], buffer[HV6100_MSG_IDX_TAIL_2], buffer[HV6100_MSG_IDX_TAIL_3]);
	return MIPI_BRIDGE_FAIL;
}

static int hv6100_uart_send_pre_check()
{
	int ret = MIPI_BRIDGE_OK;
	int len = 0;
    size_t read_len = 0;
	unsigned int check_data = HV6100_MSG_PRE_CHECK;
	unsigned int recv_data = 0;
    uint8_t buffer[HV6100_UART_BUFF_LEN] = {0};

	/* add protocol header 0xAA 0x87 0x37 */
	g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_1;
	g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_2;
    g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_3;
	/* add serialNum and change the 0x5c to 0x5c 0x5c */
	g_hv6100_trans_buffer[len++] = 0xA0; /* A0:check */
    g_hv6100_trans_buffer[len++] = 0x00;
    g_hv6100_trans_buffer[len++] = 0x00;
    g_hv6100_trans_buffer[len++] = 0x00;
	/* add protocol tail 0xAA 0x55 0xFF */
	g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_1;
	g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_2;
    g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_3;
	ret = mipibridge_uart_write(g_hv6100_trans_buffer, len);
    if (ret < 0) {
		mipibridge_errmsg("uart write err ret = %d\n", ret);
		return ret;
	}

    ret = mipibridge_uart_read(buffer, &read_len, HV6100_UART_MSG_RECV_TIMEOUT,
		HV6100_UART_MSG_BUFF_LEN);
    if (ret < 0) {
		mipibridge_errmsg("uart read err ret = %d\n", ret);
		return ret;
	}

	ret = hv6100_uart_recv(buffer, read_len, &recv_data);
	if (ret < 0 || recv_data != check_data) {
		mipibridge_errmsg("uart hv6100_uart_recv 0x%x raad 0x%x err ret = %d\n", check_data, recv_data, ret);
		return ret;
	}

	return ret;
}

static int hv6100_uart_write_data(uint8_t addr, unsigned int value)
{
	int ret = MIPI_BRIDGE_OK;
	int len = 0;
    size_t read_len = 0;
	unsigned int check_data = (0xC1 << SHIFT_24) | (addr << SHIFT_16) | LOWER_16_BITS(value);
	unsigned int recv_data = 0;
    uint8_t buffer[HV6100_UART_BUFF_LEN] = {0};

	/* add protocol header 0xAA 0x87 0x37 */
	g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_1;
	g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_2;
    g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_3;

	g_hv6100_trans_buffer[len++] = 0xC0; /* C0:write */
    g_hv6100_trans_buffer[len++] = addr;
    g_hv6100_trans_buffer[len++] = (value >> SHIFT_8) & 0xff;
    g_hv6100_trans_buffer[len++] = value & 0xff;
	/* add protocol tail 0xAA 0x55 0xFF */
	g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_1;
	g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_2;
    g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_3;
	ret = mipibridge_uart_write(g_hv6100_trans_buffer, len);
    if (ret < 0) {
		mipibridge_errmsg("uart write err ret = %d\n", ret);
		return ret;
	}

    ret = mipibridge_uart_read(buffer, &read_len, HV6100_UART_MSG_RECV_TIMEOUT, HV6100_UART_MSG_BUFF_LEN);
    if (ret < 0) {
		mipibridge_errmsg("uart read err ret = %d\n", ret);
		return ret;
	}

	ret = hv6100_uart_recv(buffer, read_len, &recv_data);
	if (ret < 0 || recv_data != check_data) {
		mipibridge_errmsg("uart hv6100_uart_recv 0x%x err ret = %d\n", check_data, ret);
		return ret;
	}

	return ret;
}

static int hv6100_uart_read_data(uint8_t addr, unsigned int *recv_data)
{
	int ret = MIPI_BRIDGE_OK;
	int len = 0;
    size_t read_len = 0;
    uint8_t buffer[HV6100_UART_BUFF_LEN] = {0};

	if (!recv_data)
		return MIPI_BRIDGE_FAIL;

	/* add protocol header 0xAA 0x87 0x37 */
	g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_1;
	g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_2;
    g_hv6100_trans_buffer[len++] = HV6100_MSG_HEADER_3;

	g_hv6100_trans_buffer[len++] = 0xB0; /* B0:write */
    g_hv6100_trans_buffer[len++] = addr;
    g_hv6100_trans_buffer[len++] = 0x00;
    g_hv6100_trans_buffer[len++] = 0x00;
	/* add protocol tail 0xAA 0x55 0xFF */
	g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_1;
	g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_2;
    g_hv6100_trans_buffer[len++] = HV6100_MSG_TAIL_3;
	ret = mipibridge_uart_write(g_hv6100_trans_buffer, len);
    if (ret < 0) {
		mipibridge_errmsg("uart write err ret = %d\n", ret);
		return ret;
	}

    ret = mipibridge_uart_read(buffer, &read_len, HV6100_UART_MSG_RECV_TIMEOUT, HV6100_UART_MSG_BUFF_LEN);
    if (ret < 0) {
		mipibridge_errmsg("uart read err ret = %d\n", ret);
		return ret;
	}

	ret = hv6100_uart_recv(buffer, read_len, recv_data);
	if (ret < 0) {
		mipibridge_errmsg("uart hv6100_uart_recv ret = %d\n", ret);
		return ret;
	}

	return ret;
}

static int hv6100_uart_send_data(uint8_t addr, unsigned int value)
{
	int ret = MIPI_BRIDGE_OK;

	ret = hv6100_uart_send_pre_check();
	if (ret < 0) {
		mipibridge_errmsg("uart hv6100_uart_send_pre_check err ret = %d\n", ret);
		return ret;
	}

	ret = hv6100_uart_write_data(addr, value);
	if (ret < 0) {
		mipibridge_errmsg("uart hv6100_uart_write_data err ret = %d\n", ret);
		return ret;
	}

	return ret;
}

static int hv6100_uart_recv_data(uint8_t addr, unsigned int *recv_data)
{
	int ret = MIPI_BRIDGE_OK;

	ret = hv6100_uart_send_pre_check();
	if (ret < 0) {
		mipibridge_errmsg("uart hv6100_uart_send_pre_check err ret = %d\n", ret);
		return ret;
	}

	ret = hv6100_uart_read_data(addr, recv_data);
	if (ret < 0) {
		mipibridge_errmsg("uart hv6100_uart_read_data err ret = %d\n", ret);
		return ret;
	}

	return ret;
}

static void hv6100_uart_read_ic_status(void)
{
	int i = 0;
	unsigned int recv_data[HV6100_MSG_CHECK_STATUS_NUM] = {0};

	for (i = 0; i < HV6100_MSG_CHECK_STATUS_NUM; i++)
		hv6100_uart_recv_data(i, &recv_data[i]);

	mipibridge_infomsg(" 0x0000 | 0x0001 | 0x0002 | 0x0003 | 0x0004 | 0x0005| 0x0006| 0x0007\n");
	mipibridge_infomsg("--------+-------+--------+--------+--------+--------\n");
	mipibridge_infomsg(" 0x%4x | 0x%4x | 0x%4x | x:%4d | y:%4d | 0x%4x | 0x%4x| 0x%4x\n", 
		LOWER_16_BITS(recv_data[HV6100_REG_CTRL_ADDR]), LOWER_16_BITS(recv_data[HV6100_REG_BOOT_VER_ADDR]),
		LOWER_16_BITS(recv_data[HV6100_REG_APP_VER_ADDR]), LOWER_16_BITS(recv_data[HV6100_REG_X_ADDR]), 
		LOWER_16_BITS(recv_data[HV6100_REG_Y_ADDR]), LOWER_16_BITS(recv_data[HV6100_REG_STATUS_ADDR]),
		LOWER_16_BITS(recv_data[HV6100_REG_BOOT_APP_ADDR]), LOWER_16_BITS(recv_data[HV6100_REG_RESULT_ADDR]));
	mipibridge_infomsg("====================================================\n");
}

static void hv6100_uart_recv_ic_status(u8 *recv_buff, unsigned int len)
{
	int i = 0;
	unsigned int recv_data = 0;

	if (hv6100_uart_recv(recv_buff, len, &recv_data) < 0)
		return;

	mipibridge_errmsg("recv_data 0x%x\n", recv_data);
}

static int hv6100_read_firmware(struct device *dev)
{
	int ret = MIPI_BRIDGE_OK;

	if (!dev) {
		mipibridge_errmsg("dev NULL\n");
		return FIRMWARE_UPGRADE_FAIL;
	}

	ret = request_firmware(&g_firmware, JW_PATH_FW, dev);
	if (ret < 0) {
		mipibridge_errmsg("request firmware fail %d\n", ret);
		return FIRMWARE_NOT_FIND_FW;
	}

	if (!g_firmware || g_firmware->size > HV6100_WRITE_DATA_MAX_LEN || !g_firmware->data) {
		mipibridge_errmsg("firmware err!\n");
		return FIRMWARE_ERROR_FW;
	}

	mipibridge_infomsg("exit, ret=%d, firmware_size=%d\n", ret, g_firmware->size);
	return ret;
}

int hv6100_probe(struct mipibridge_device_info *di)
{
	int ret = MIPI_BRIDGE_OK;
	int spi_jatg_gpio = 0;
	struct device_node *dn = NULL;

	if (!di || !di->dev ) {
		mipibridge_errmsg("dev NULL\n");
		return MIPI_BRIDGE_FAIL;
	}

	dn = of_get_child_by_name(di->dev->of_node, PANEL_HV6100);
	if (dn) {
		mipibridge_parse_u32(dn, "spi_jatg_gpio", &spi_jatg_gpio, 0);
		ret = gpio_request_one(spi_jatg_gpio, GPIOF_OUT_INIT_HIGH, "hv6100_spi");
		if (ret) {
			mipibridge_errmsg("gpio_request %d failed\n", spi_jatg_gpio);
			return ret;
		}
	}

	mipibridge_infomsg("di->uart.support:%d, di->uart.uart_recv_support:%d, di->fw.support:%d\n",
		di->uart.support, di->uart.uart_recv_support, di->fw.support);
	if (di->uart.support && di->uart.uart_recv_support) {
		/* only read once */
		hv6100_uart_read_ic_status();
		di->uart.recv_fuc = hv6100_uart_recv_ic_status;
		/* enable mipibridge err report */
		mipibridge_uart_recv_enable(HV6100_UART_MSG_BUFF_LEN);
	}

	if (di->fw.support) {
		di->fw.fw_update = hv6100_spi_firmware_load;
		di->fw.open_fw = hv6100_read_firmware;
	}

	return MIPI_BRIDGE_OK;
}
