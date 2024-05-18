/*
 * Thp driver code for himax
 *
 * Copyright (c) 2012-2020 Honor Technologies Co., Ltd.
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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/spi/spi.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <asm/byteorder.h>
#include "honor_thp.h"
#include <linux/firmware.h>
#if defined(CONFIG_HMX_DB)
#include <linux/regulator/consumer.h>
#endif

#define THP_PEN_HX83122_DEV_NODE_NAME "himax-hx83122-pen"
#define HX83122_PEN_IC_NAME "himax_pen"

#define FWU_PEN_FW_CRC_ERROR 3
#define SPI_PEN_BITS_PER_WORD_READ 8
#define SPI_PEN_FORMAT_ARRAY_SIZE 3
#define COMM_PEN_TEST_RW_RETRY_TIME 3
#define NO_ERR_PEN 0
#define HIMAX_PEN_BUS_RETRY_TIMES 10
#define HIMAX_NORMAL_PEN_DATA_LEN 4
#define HIMAX_NORMAL_PEN_ADDR_LEN 4
#define HIMAX_BEGING_PEN_ADDR 0x00
#define HIMAX_PEN_REG_DATA_LEN 1
#define HIMAX_PEN_CONTI_BURST_ADDR 0x13
#define HIMAX_PEN_CONTI_BURST_EN 0x31
#define HIMAX_PEN_SSOFF_ADDR_FIRST 0x31
#define HIMAX_PEN_SSOFF_CMD_FIRST 0x27
#define HIMAX_PEN_SSOFF_ADDR_SECOND 0x32
#define HIMAX_PEN_SSOFF_CMD_SECOND 0x95
#define HIMAX_PEN_AUTO_PLUS_4_ADDR 0x0D
#define HIMAX_PEN_AUTO_PLUS_4_DIS 0x10
#define HIMAX_PEN_121A_AUTO_PLUS_4_DIS 0x12
#define HIMAX_PEN_WAKEUP_ADDR 0x08
#define HIMAX_PEN_FW_SSOFF 0x0C
#define HIMAX_PEN_REG_READ_EN_ADDR 0x0C
#define HIMAX_PEN_EVENT_STACK_CMD_ADDR 0x30
#define HIMAX_PEN_REG_READ_EN 0x00
#define HIMAX_PEN_CHK_FW_STATUS 0x900000A8
#define HIMAX_PEN_CLK_ON_ADDR 0x9000005C
#define HIMAX_PEN_CLK_ON_CMD 0x000000A5
#define HIMAX_PEN_CLK_ON_DELAY_MS 20
#define HIMAX_PEN_ICID_ADDR 0x900000D0
#define HIMAX_PEN_102D_TCON_RST_ADDR 0x80020020
#define HIMAX_PEN_102D_TCON_RST_ON_CMD 0x00000000
#define HIMAX_PEN_102D_TCON_RST_OFF_CMD 0x00000001
#define HIMAX_PEN_102E_TCON_RST_ADDR 0x80020004
#define HIMAX_PEN_102E_TCON_RST_ON_CMD 0x00000000
#define HIMAX_PEN_102D_ADC_RST_ADDR 0x80020094
#define HIMAX_PEN_102D_ADC_RST_ON_CMD 0x00000000
#define HIMAX_PEN_102D_ADC_RST_OFF_CMD 0x00000001
#define HIMAX_PEN_RESET_DELAY_MS 10
#define HIMAX_PEN_RAWDATA_ADDR 0x10000000


#define HIMAX_PEN_HISPEED_SUPPORT_REG 0x80000040
#define HIMAX_PEN_HISPEED_SUPPORT_VAL 0x00000001
#define SUSPEND_PEN_IN_GESTURE 1
#define RESUME_PEN_OUT_GESTURE 0

#define PEN_INFO_SECTION_NUM 2
#define PEN_INFO_START_ADDR 0x20000
#define PEN_INFO_PAGE_LENGTH 0x1000
#define PEN_NOR_READ_LENGTH 128

#define HX_PEN_83121A_ID_PART_1 0x83
#define HX_PEN_83121A_ID_PART_2 0x12
#define HX_PEN_83121A_ID_PART_3 0x1A
#define HX_PEN_83122A_ID_PART_1 0x83
#define HX_PEN_83122A_ID_PART_2 0x12
#define HX_PEN_83122A_ID_PART_3 0x2A



#define WAIT_FOR_PEN_SPI_BUS_RESUMED_DELAY 20
#define WAIT_FOR_PEN_SPI_BUS_RESUMED_DELAY_QCOM 100
#define WAIT_FOR_PEN_SPI_BUS_READ_DELAY 5
#define GESTURE_PEN_EVENT_RETRY_TIME 20


#define PEN_LOW_8BIT 0x100
#define PEN_HIGH_8BIT 0x1000000
#define STR_PEN_TYPE 0
#define NUM_PEN_TYPE 1
#define FUNC_PEN_EN 1
#define FUNC_PEN_DIS 0
#define DATA_PEN_INIT 0x00000000
#define ADDR_PEN_READ_MODE_CHK 0x900000A8
#define ADDR_PEN_DD_OSC_HX83102 0x9000009C
#define DATA_PEN_DD_OSC_HX83102_EN 0x000000DD
#define ADDR_PEN_DD_PW_HX83102 0x90000280
#define DATA_PEN_DD_PW_HX83102_EN 0x000000A5
#define ENTER_PEN_SAVE_MODE 0x0C
#define REG_PEN_WRITE_INTERVAL 20
#define CRC_PEN_DATA_THREE 0x00
#define CRC_PEN_DATA_TWO 0x99
#define ONE_BYTE_PEN_LEN 8
#define LOW_PEN_BIT 0x01
#define FW_PEN_CRC_TRY_TIMES 100
#define HX_PEN_DDREG_FORMAT 0x30000000
#define HX_PEN_DDREG_REG_IDX 12
#define HX_PEN_DDREG_BANK_IDX 8
#define REFORMAT_PEN_SIZE 4
#define MOVE_8BIT_PEN 8
#define MOVE_16BIT_PEN 16
#define MOVE_24BIT_PEN 24
#define ADDR_PEN_EN_BURST_MODE 0x13
#define DATA_PEN_EN_BURST_MODE 0x31
#define ADDR_PEN_AHB 0x0D
#define DATA_PEN_AHB 0x10


#define FOUR_BYTE_CMD_PEN 4
#define ADDR_PEN_CRC 0x80050020
#define ADDR_PEN_CRC_DATAMAXLEN_SET 0x80050028
#define ADDR_PEN_CRC_STATUS_SET 0x80050000
#define ADDR_PEN_CRC_RESULT 0x80050018
#define HX_PEN_SLEEP_10MS 10

#define THP_PROJECTID_PEN_VENDOR_NAME_LEN 3
#define VENDOR_NAME_BOE_PEN "boe"
#define VENDOR_NAME_INX_PEN "cmi"

#define HX_BOE_TX_NUM_PEN 32
#define HX_BOE_RX_NUM_PEN 48
#define HX_INX_TX_NUM_PEN 30
#define HX_INX_RX_NUM_PEN 48
#define HX_DB_CLICK_PEN 0x01
#define HX_WAKEUP_MEMO_PEN 0x02
#define BYTE_2_PEN 2
#define OFFSET_GES_PEN 14

static int pen_driver_83112_get_frame(struct thp_device *tdev, char *buf, unsigned int len);
enum Temp_Data {
	PEN_DATA_0 = 0,
	PEN_DATA_1,
	PEN_DATA_2,
	PEN_DATA_3,
	PEN_DATA_4,
	PEN_DATA_5,
	PEN_DATA_6,
	PEN_DATA_7,
	PEN_DATA_8,
};

static u32 himax_pen_id_match_table[] = {
	0x83112A00, /* chip HX83112A id */
	0x83112B00, /* chip HX83112B id */
	0x83112C00, /* chip HX83112C id */
	0x83112E00, /* chip HX83112E id */
	0x83102D00, /* chip HX83102D id */
	0x83102E00, /* chip HX83102E id */
	0x83121A00, /* chip HX83121A id */
	0x83122A00, /* chip HX83122A id */
};


struct himax_thp_pen_private_data {
	int hx_get_frame_optimized_flag;
	u32 himax_ic_83102_flag;
	u32 himax_ic_83121_flag;
	u32 himax_ic_83122_flag;
	u32 himax_ic_hispeed_support;
	u32 himax_gesture_need_lcd_rst;
	u32 himax_gesture_need_msleep_for_qcom;
};

static struct spi_device *hx_pen_spi_dev;
static struct himax_thp_pen_private_data thp_pen_private_data;

struct himax_pen_spi_buf {
	uint8_t *w_buf;
	uint8_t *r_buf_a;
	uint8_t *r_buf_b;
} g_himax_pen_spi_buf;


static void pen_vendor_assign_data(uint32_t cmd, uint8_t *tmp_value, uint32_t length)
{
	tmp_value[PEN_DATA_3] = cmd / PEN_HIGH_8BIT;
	tmp_value[PEN_DATA_2] = (cmd >> MOVE_16BIT_PEN) % PEN_LOW_8BIT;
	tmp_value[PEN_DATA_1] = (cmd >> MOVE_8BIT_PEN) % PEN_LOW_8BIT;
	tmp_value[PEN_DATA_0] = cmd % PEN_LOW_8BIT;
}

static void pen_himax_assign_data(uint32_t cmd, uint8_t *tmp_value)
{
	int index = 3;

	tmp_value[index--] = cmd / 0x1000000;
	tmp_value[index--] = (cmd >> 16) % 0x100;
	tmp_value[index--] = (cmd >> 8) % 0x100;
	tmp_value[index--] = cmd % 0x100;
}

static void pen_driver_spi_complete(void *arg)
{
	complete(arg);
}

static int pen_driver_spi_sync(struct thp_device *tdev,
	struct spi_message *message)
{
	int status;
	DECLARE_COMPLETION_ONSTACK(done);

	message->complete = pen_driver_spi_complete;
	message->context = &done;

	if (hx_pen_spi_dev == NULL) {
		status = -ESHUTDOWN;
	} else {
		status = thp_pen_spi_sync(hx_pen_spi_dev, message);
	}

	return status;
}

static int pen_driver_spi_read(struct thp_device *tdev,
	uint8_t *command, uint8_t command_len,
	uint8_t *data, unsigned int length, uint8_t to_retry)
{
	struct spi_message message;
	struct spi_transfer xfer[2];
	int retry;
	int error;

	spi_message_init(&message);

	memset(xfer, 0, sizeof(xfer));

	xfer[0].tx_buf = command;
	xfer[0].len = command_len;
	spi_message_add_tail(&xfer[0], &message);

	xfer[1].rx_buf = data;
	xfer[1].len = length;
	spi_message_add_tail(&xfer[1], &message);

	for (retry = 0; retry < to_retry; retry++) {
		error = thp_pen_spi_sync(hx_pen_spi_dev, &message);
		if (unlikely(error))
			thp_log_err(tdev->thp_core, "SPI read error: %d\n", error);
		else
			break;
	}

	if (retry == to_retry) {
		thp_log_err(tdev->thp_core, "%s: SPI read error retry over %d\n",
			__func__, to_retry);
		return -EIO;
	}

	return 0;
}

static int pen_driver_spi_write(struct thp_device *tdev,
	uint8_t *buf, unsigned int length)
{
	int ret;
	struct spi_message message;

	struct spi_transfer	t = {
		.tx_buf		= buf,
		.len		= length,
		.bits_per_word = SPI_PEN_BITS_PER_WORD_READ,
	};
	spi_message_init(&message);
	spi_message_add_tail(&t, &message);

	ret = pen_driver_spi_sync(tdev, &message);

	return ret;
}

#define READ_PEN_COMMAND_HEAD 0xF5
#define READ_PEN_COMMAND_TAIL 0x00
static int pen_driver_83102_bus_read(struct thp_device *tdev,
	uint8_t command, uint8_t *data,
	unsigned int length, uint8_t toretry)
{
	uint8_t spi_format_buf[SPI_PEN_FORMAT_ARRAY_SIZE];

	if (!tdev) {
		thp_log_info(tdev->thp_core, "%s:dev is invalid\n", __func__);
		return -EINVAL;
	}
	if (!data) {
		thp_log_info(tdev->thp_core, "%s:data addr is invalid\n", __func__);
		return -EINVAL;
	}
	if (!length) {
		thp_log_info(tdev->thp_core, "%s:read length is invalid\n", __func__);
		return -EINVAL;
	}
	/* 0xF3 is head of command */
	spi_format_buf[PEN_DATA_0] = READ_PEN_COMMAND_HEAD;
	spi_format_buf[PEN_DATA_1] = command;
	/* 0x00 is tail of command */
	spi_format_buf[PEN_DATA_2] = READ_PEN_COMMAND_TAIL;

	return pen_driver_spi_read(tdev, &spi_format_buf[PEN_DATA_0],
		SPI_PEN_FORMAT_ARRAY_SIZE, data, length, toretry);
}

static int pen_driver_bus_read(struct thp_device *tdev, uint8_t command,
	uint8_t *data, unsigned int length, uint8_t to_retry)
{
	uint8_t *spi_format_buf = g_himax_pen_spi_buf.r_buf_b;
	struct himax_thp_pen_private_data *himax_p = NULL;
	int ret;
	int index = 0;

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return -EINVAL;
	}
	himax_p = tdev->private_data;
	if ((himax_p->himax_ic_83102_flag) || (himax_p->himax_ic_83121_flag)
	|| (himax_p->himax_ic_83122_flag)) {
		ret = pen_driver_83102_bus_read(tdev,
			command, data, length, to_retry);
		return ret;
	}
	if (!spi_format_buf) {
		thp_log_info(tdev->thp_core, "%s:spi_format_buf is NULL\n", __func__);
		return -EINVAL;
	}
	/* 0xF3 is head of command */
	spi_format_buf[index++] = 0xF3;
	spi_format_buf[index++] = command;
	/* 0x00 is tail of command */
	spi_format_buf[index++] = 0x00;

	return pen_driver_spi_read(tdev, &spi_format_buf[0],
		SPI_PEN_FORMAT_ARRAY_SIZE, data, length, to_retry);
}

#define WRITE_PEN_COMMAND_HEAD 0xF4
static int pen_driver_83102_bus_write(struct thp_device *tdev,
	uint8_t command, uint8_t *data,
	unsigned int length, uint8_t toretry)
{
	uint8_t spi_format_buf[HIMAX_NORMAL_PEN_DATA_LEN + HIMAX_NORMAL_PEN_ADDR_LEN + PEN_DATA_2];
	int i;

	if (!tdev) {
		thp_log_info(tdev->thp_core, "%s:dev is invalid\n", __func__);
		return -EINVAL;
	}
	if (!data) {
		thp_log_info(tdev->thp_core, "%s:data addr is invalid\n", __func__);
		return -EINVAL;
	}
	if (!length) {
		thp_log_info(tdev->thp_core, "%s:read length is invalid\n", __func__);
		return -EINVAL;
	}

	/* 0xF2 is head of command */
	spi_format_buf[PEN_DATA_0] = WRITE_PEN_COMMAND_HEAD;
	spi_format_buf[PEN_DATA_1] = command;

	for (i = PEN_DATA_0; i < length; i++)
		spi_format_buf[i + PEN_DATA_2] = data[i];

	return pen_driver_spi_write(tdev, spi_format_buf, length + PEN_DATA_2);
}

static int pen_driver_bus_write(struct thp_device *tdev, uint8_t command,
	uint8_t *data, unsigned int length, uint8_t to_retry)
{
	uint8_t *spi_format_buf = g_himax_pen_spi_buf.w_buf;
	struct himax_thp_pen_private_data *himax_p = NULL;
	int i;
	int ret;

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return -EINVAL;
	}
	himax_p = tdev->private_data;
	if ((himax_p->himax_ic_83102_flag) || (himax_p->himax_ic_83121_flag)
	|| (himax_p->himax_ic_83122_flag)) {
		ret = pen_driver_83102_bus_write(tdev,
			command, data, length, to_retry);
		return ret;
	}
	if (!spi_format_buf) {
		thp_log_info(tdev->thp_core, "%s:spi_format_buf is NULL\n", __func__);
		return -EINVAL;
	}
	/* 0xF2 is head of command */
	spi_format_buf[0] = 0xF2;
	spi_format_buf[1] = command;

	for (i = 0; i < length; i++)
		spi_format_buf[i + 2] = data[i];

	/* 2 bytes of head */
	return pen_driver_spi_write(tdev, spi_format_buf, length + 2);
}

static int pen_driver_register_read(struct thp_device *tdev,
	uint8_t *read_addr, unsigned int read_length, uint8_t *read_data)
{
	uint8_t tmp_data[HIMAX_NORMAL_PEN_DATA_LEN];
	/* Restore the address */
	unsigned int address;
	int index = 0;

	address = (read_addr[3] << MOVE_24BIT_PEN) + (read_addr[2] << MOVE_16BIT_PEN) +
		(read_addr[1] << MOVE_8BIT_PEN) + read_addr[0];
	tmp_data[index++] = (uint8_t)address;
	tmp_data[index++] = (uint8_t)(address >> MOVE_8BIT_PEN);
	tmp_data[index++] = (uint8_t)(address >> MOVE_16BIT_PEN);
	tmp_data[index++] = (uint8_t)(address >> MOVE_24BIT_PEN);

	if (pen_driver_bus_write(tdev, HIMAX_BEGING_PEN_ADDR, tmp_data,
		HIMAX_NORMAL_PEN_DATA_LEN, HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: i2c access fail!\n", __func__);
		return -ENOMEM;
	}

	tmp_data[0] = HIMAX_PEN_REG_READ_EN;
	if (pen_driver_bus_write(tdev, HIMAX_PEN_REG_READ_EN_ADDR, tmp_data, 1,
		HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: i2c access fail!\n", __func__);
		return -ENOMEM;
	}

	if (pen_driver_bus_read(tdev, HIMAX_PEN_WAKEUP_ADDR, read_data,
		read_length, HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: i2c access fail!\n", __func__);
		return -ENOMEM;
	}

	return 0;
}

static void pen_driver_83102_interface_on(struct thp_device *tdev)
{
	uint8_t tmp_data[HIMAX_NORMAL_PEN_DATA_LEN];

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s:dev null!\n", __func__);
		return;
	}
	if (pen_driver_bus_read(tdev, HIMAX_PEN_WAKEUP_ADDR, tmp_data,
		HIMAX_NORMAL_PEN_DATA_LEN, HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: i2c access fail!\n", __func__);
		return;
	}
}

static void pen_driver_interface_on(struct thp_device *tdev)
{
	uint8_t *tmp_data = g_himax_pen_spi_buf.r_buf_a;
	struct himax_thp_pen_private_data *himax_p = NULL;

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return;
	}
	himax_p = tdev->private_data;
	if ((himax_p->himax_ic_83102_flag) || (himax_p->himax_ic_83121_flag)
	|| (himax_p->himax_ic_83122_flag)) {
		pen_driver_83102_interface_on(tdev);
		return;
	}
	if (!tmp_data) {
		thp_log_info(tdev->thp_core, "%s:tmp_data is NULL\n", __func__);
		return;
	}
	/* Read a dummy register to wake up I2C */
	if (pen_driver_bus_read(tdev, HIMAX_PEN_WAKEUP_ADDR, tmp_data,
		HIMAX_NORMAL_PEN_DATA_LEN, HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: i2c access fail!\n", __func__);
		return;
	}
}

#if defined(CONFIG_HMX_DB)
static int pen_driver_regulator_configure(struct device *dev)
{
	int ret;
	struct regulator *reg;
	struct regulator *reg2;
	struct thp_core_data *cd = NULL;

	cd = thp_get_core_data();
	if (!cd) {
		thp_log_err(cd, "%s: null ptr\n", __func__);
		return -EINVAL;
	}

	if (!dev) {
		thp_log_err(cd, "%s:dev null!\n", __func__);
		return;
	}
	reg = regulator_get(dev, "vdd");
	if (IS_ERR(reg)) {
		thp_log_err(cd, "%s: Failed to get regulator vdd\n",
			__func__);
		ret = PTR_ERR(reg);
		return ret;
	}

	reg2 = regulator_get(dev, "avdd");
	if (IS_ERR(reg2)) {
		thp_log_err(cd, "%s: Failed to get regulator avdd\n",
		  __func__);
		ret = PTR_ERR(reg2);
		regulator_put(reg);
		return ret;
	}

	ret = regulator_enable(reg);
	if (ret) {
		thp_log_err(cd, "%s: Failed to enable regulator vdd\n",
		  __func__);
		return ret;
	}
	thp_do_time_delay(HIMAX_PEN_CLK_ON_DELAY_MS);

	ret = regulator_enable(reg2);
	if (ret) {
		thp_log_err(cd, "%s: Failed to enable regulator avdd\n",
		 __func__);
		return ret;
	}
	thp_do_time_delay(HIMAX_PEN_CLK_ON_DELAY_MS);

	thp_log_info(cd, "%s: configure regulator succeed!\n", __func__);

	return 0;
}
#endif

static int pen_driver_parse_gesture_data(struct thp_device *tdev,
	const u8 *data, unsigned int *gesture_wakeup_value)
{
	struct thp_core_data *cd = NULL;
	int length;
	int tx_num;
	int rx_num;

	cd = thp_get_core_data();
	if (!cd) {
		thp_log_err(tdev->thp_core, "%s: null ptr\n", __func__);
		return -EINVAL;
	}
	if (!strncmp(cd->vendor_name,
		VENDOR_NAME_BOE_PEN, THP_PROJECTID_PEN_VENDOR_NAME_LEN)) {
		tx_num = HX_BOE_TX_NUM_PEN;
		rx_num = HX_BOE_RX_NUM_PEN;
	} else if (!strncmp(cd->vendor_name,
		VENDOR_NAME_INX_PEN, THP_PROJECTID_PEN_VENDOR_NAME_LEN)) {
		tx_num = HX_INX_TX_NUM_PEN;
		rx_num = HX_INX_RX_NUM_PEN;
	} else {
		thp_log_err(tdev->thp_core, "%s: not support this vendor_id\n", __func__);
		return -EINVAL;
	}
	length = BYTE_2_PEN * tx_num * rx_num + OFFSET_GES_PEN;
	length--;
	if ((data[length] == HX_DB_CLICK_PEN) ||
		(data[length - 1] == HX_DB_CLICK_PEN)) {
		*gesture_wakeup_value = TS_DOUBLE_CLICK;
	} else if ((data[length] == HX_WAKEUP_MEMO_PEN) ||
		(data[length - 1] == HX_WAKEUP_MEMO_PEN)) {
		*gesture_wakeup_value = TS_STYLUS_WAKEUP_TO_MEMO;
	} else {
		thp_log_err(tdev->thp_core, "%s: not support this gesture\n", __func__);
		return -EINVAL;
	}
	return NO_ERR_PEN;
}

static int pen_driver_gesture_report(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value)
{
	int retval;
	int i;
	u8 *frame_read_buf = NULL;
	struct himax_thp_pen_private_data *himax_p = NULL;

	thp_log_info(tdev->thp_core, "%s enter\n", __func__);
	if ((!tdev) || (!tdev->thp_core) ||
		(!tdev->thp_core->sdev) || (!tdev->thp_core->frame_read_buf)) {
		thp_log_err(tdev->thp_core, "%s: input dev is null\n", __func__);
		return -EINVAL;
	}
	if ((gesture_wakeup_value == NULL) ||
		(!tdev->thp_core->support_gesture_mode)) {
		thp_log_err(tdev->thp_core, "%s, gesture not support\n", __func__);
		return -EINVAL;
	}
	frame_read_buf = (u8 *)tdev->thp_core->frame_read_buf;
	himax_p = tdev->private_data;
	if (himax_p->himax_gesture_need_msleep_for_qcom)
		msleep(WAIT_FOR_PEN_SPI_BUS_RESUMED_DELAY_QCOM);
	else
		msleep(WAIT_FOR_PEN_SPI_BUS_RESUMED_DELAY);
	/* wait spi bus resume */
	for (i = 0; i < GESTURE_PEN_EVENT_RETRY_TIME; i++) {
		retval = pen_driver_83112_get_frame(tdev,
			frame_read_buf, THP_MAX_FRAME_SIZE);
		if (retval) {
			thp_log_err(tdev->thp_core, "%s: spi not work normal, ret %d retry\n",
				__func__, retval);
			msleep(WAIT_FOR_PEN_SPI_BUS_READ_DELAY);
		} else {
			thp_log_info(tdev->thp_core, "%s: spi work normal, got gesture\n",
				__func__);
			break;
		}
	}
	if (retval) {
		thp_log_err(tdev->thp_core, "%s: failed read gesture head info, ret %d\n",
			__func__, retval);
		return retval;
	}
	retval = pen_driver_parse_gesture_data(tdev,
		frame_read_buf, gesture_wakeup_value);

	thp_log_info(tdev->thp_core, "%s exit\n", __func__);
	return retval;
}

static int pen_driver_init(struct thp_device *tdev)
{
	int rc;
	unsigned int value = 0;
	struct thp_core_data *cd = tdev->thp_core;
	struct device_node *hx83112_node = of_get_child_by_name(cd->thp_node,
						THP_PEN_HX83122_DEV_NODE_NAME);
	struct himax_thp_pen_private_data *himax_p = tdev->private_data;

	thp_log_info(tdev->thp_core, "Enter %s\n", __func__);

	hx_pen_spi_dev = tdev->sdev;

	thp_log_info(tdev->thp_core, "%s: called\n", __func__);

	if (!hx83112_node) {
		thp_log_err(tdev->thp_core, "%s: dev not config in dts\n", __func__);
		return -ENODEV;
	}

	rc = of_property_read_u32(hx83112_node, "get_frame_optimized_method",
		&value);
	if (rc) {
		himax_p->hx_get_frame_optimized_flag = 0;
		thp_log_err(tdev->thp_core,
			"%s:hx_get_frame_optimized_method_flag not found,use default value\n",
			__func__);
	} else {
		himax_p->hx_get_frame_optimized_flag = value;
		thp_log_info(tdev->thp_core, "%s:hx_get_frame_optimized_method_flag %d\n",
			__func__, value);
	}

	rc = of_property_read_u32(hx83112_node,
		"himax_ic_83122_flag", &value);
	if (rc) {
		himax_p->himax_ic_83122_flag = 0;
		thp_log_err(tdev->thp_core, "%s: 83122_flag not found\n",
			__func__);
	} else {
		himax_p->himax_ic_83122_flag = value;
		thp_log_info(tdev->thp_core, "%s: 122_flag %d\n",
			__func__, value);
	}

	rc = of_property_read_u32(hx83112_node,
		"himax_ic_hispeed_support", &value);
	if (rc) {
		himax_p->himax_ic_hispeed_support = 0;
		thp_log_err(tdev->thp_core, "%s: hispeed_flag not found\n",
			__func__);
	} else {
		himax_p->himax_ic_hispeed_support = value;
		thp_log_info(tdev->thp_core, "%s: hispeed_flag %d\n",
			__func__, value);
	}

	rc = of_property_read_u32(hx83112_node,
		"himax_gesture_need_lcd_rst", &value);
	if (rc) {
		himax_p->himax_gesture_need_lcd_rst = 0;
		thp_log_err(tdev->thp_core, "%s: need_lcd_rst not found\n",
			__func__);
	} else {
		himax_p->himax_gesture_need_lcd_rst = value;
		thp_log_info(tdev->thp_core, "%s: lcd_rst_flag %d\n",
			__func__, value);
	}

	rc = of_property_read_u32(hx83112_node,
		"himax_gesture_need_msleep_for_qcom", &value);
	if (rc) {
		himax_p->himax_gesture_need_msleep_for_qcom = 0;
		thp_log_err(tdev->thp_core, "%s: need_msleep not found\n",
			__func__);
	} else {
		himax_p->himax_gesture_need_msleep_for_qcom = value;
		thp_log_info(tdev->thp_core, "%s: msleep_for_qcom flag %d\n",
			__func__, value);
	}
	rc = thp_pen_parse_spi3_config(hx83112_node, cd);
	if (rc) {
		thp_log_err(tdev->thp_core, "%s: spi config parse fail\n", __func__);
		return -ENODEV;
	}

	rc = thp_pen_parse_timing_config(tdev->thp_core, hx83112_node, &tdev->timing_config);
	if (rc) {
		thp_log_err(tdev->thp_core, "%s: timing config parse fail\n", __func__);
		return -ENODEV;
	}
	return 0;
}

static int pen_driver_121_communication_check(struct thp_device *tdev)
{
	uint8_t tmp_addr[HIMAX_NORMAL_PEN_ADDR_LEN] = {0};
	uint8_t tmp_data[HIMAX_NORMAL_PEN_DATA_LEN] = {0};
	uint8_t ic_name[HIMAX_NORMAL_PEN_DATA_LEN] = {0};
	int ret;
	int i;
	int j;

	for (i = 0; i < COMM_PEN_TEST_RW_RETRY_TIME; i++) {
		pen_himax_assign_data(HIMAX_PEN_ICID_ADDR, tmp_addr);
		ret = pen_driver_register_read(tdev,
			tmp_addr, HIMAX_NORMAL_PEN_DATA_LEN, tmp_data);
		for (j = PEN_DATA_0; j < ARRAY_SIZE(himax_pen_id_match_table); j++) {
			pen_vendor_assign_data(himax_pen_id_match_table[j],
				ic_name, HIMAX_NORMAL_PEN_DATA_LEN);
			if ((tmp_data[PEN_DATA_3] == HX_PEN_83122A_ID_PART_1) &&
				(tmp_data[PEN_DATA_2] == HX_PEN_83122A_ID_PART_2) &&
				(tmp_data[PEN_DATA_1] == HX_PEN_83122A_ID_PART_3)) {
				break;
			} else if ((tmp_data[PEN_DATA_3] == HX_PEN_83121A_ID_PART_1) &&
				(tmp_data[PEN_DATA_2] == HX_PEN_83121A_ID_PART_2) &&
				(tmp_data[PEN_DATA_1] == HX_PEN_83121A_ID_PART_3)) {
				break;
			} else if ((tmp_data[PEN_DATA_3] == ic_name[PEN_DATA_3]) &&
				(tmp_data[PEN_DATA_2] == ic_name[PEN_DATA_2]) &&
				(tmp_data[PEN_DATA_1] == ic_name[PEN_DATA_1])) {
				break;
			}
		}
		if (j < ARRAY_SIZE(himax_pen_id_match_table)) {
			thp_log_info(tdev->thp_core, "vendor ic found\n");
			break;
		}
		thp_log_err(tdev->thp_core, "%s:Read driver ID register Fail:\n", __func__);
	}

	if (i == COMM_PEN_TEST_RW_RETRY_TIME)
		return -EINVAL;

	return 0;
}

static void pen_driver_timing_work(struct thp_device *tdev)
{
	struct thp_core_data *cd = NULL;
	uint8_t tmp_data[HIMAX_NORMAL_PEN_DATA_LEN];

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return;
	}
	cd = tdev->thp_core;
	thp_log_info(tdev->thp_core, "%s:called,do hard reset\n", __func__);
#if (IS_ENABLED(CONFIG_HONOR_THP_MTK))
	pinctrl_select_state(cd->pctrl, cd->mtk_pinctrl.cs_high);
#endif
	tmp_data[0] = HIMAX_PEN_SSOFF_CMD_FIRST;
	if (pen_driver_bus_write(tdev, HIMAX_PEN_SSOFF_ADDR_FIRST, tmp_data, 1,
		HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: i2c first access fail!\n", __func__);
		return;
	}

	tmp_data[0] = HIMAX_PEN_SSOFF_CMD_SECOND;
	if (pen_driver_bus_write(tdev, HIMAX_PEN_SSOFF_ADDR_SECOND, tmp_data, 1,
		HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: i2c second access fail!\n", __func__);
		return;
	}
}

static int pen_driver_83121_chip_detect(struct thp_device *tdev)
{
	int ret;

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return -EINVAL;
	}

	pen_driver_timing_work(tdev);

	thp_bus_lock(tdev->thp_core);
	ret = pen_driver_121_communication_check(tdev);
	if (ret) {
		thp_log_err(tdev->thp_core, "%s: ic communication check fail\n", __func__);
		thp_bus_unlock(tdev->thp_core);
		return -EINVAL;
	}
	thp_bus_unlock(tdev->thp_core);

	return ret;

}

static int pen_driver_83102_get_dsram_data(struct thp_device *tdev,
	char *info_data, unsigned int len)
{
	unsigned char tmp_addr[HIMAX_NORMAL_PEN_ADDR_LEN] = {0};
	unsigned int read_size = len;
	uint8_t *temp_info_data = NULL;
	int ret;

	if (!info_data) {
		thp_log_err(tdev->thp_core, "%s:info_data is NULL\n", __func__);
		return -EINVAL;
	}
	temp_info_data = kzalloc(read_size, GFP_KERNEL);
	if (!temp_info_data) {
		thp_log_err(tdev->thp_core, "%s: temp_info_data malloc fail\n", __func__);
		return -ENOMEM;
	}
	thp_bus_lock(tdev->thp_core);
	/* 1. turn on burst mode */
	pen_driver_interface_on(tdev);
	/* 2. get RawData from sram */
	pen_himax_assign_data(HIMAX_PEN_RAWDATA_ADDR, tmp_addr);
	ret = pen_driver_register_read(tdev, tmp_addr, read_size,
		temp_info_data);
	if (ret) {
		thp_bus_unlock(tdev->thp_core);
		goto exit;
	}
	thp_bus_unlock(tdev->thp_core);

	memcpy(info_data, temp_info_data, read_size);
exit:
	kfree(temp_info_data);
	temp_info_data = NULL;

	return ret;
}

static int pen_driver_get_dsram_data(struct thp_device *tdev,
	char *info_data, unsigned int len)
{
	unsigned char tmp_addr[HIMAX_NORMAL_PEN_ADDR_LEN] = {0};
	unsigned int read_size = len;
	uint8_t *temp_info_data = NULL;
	int ret;
	struct himax_thp_pen_private_data *himax_p = tdev->private_data;

	if (!len) {
		thp_log_err(tdev->thp_core, "%s:len is invalid\n", __func__);
		return -EINVAL;
	}
	if (!info_data) {
		thp_log_err(tdev->thp_core, "%s:info_data is NULL\n", __func__);
		return -EINVAL;
	}
	if ((himax_p->himax_ic_83102_flag) || (himax_p->himax_ic_83121_flag)
	|| (himax_p->himax_ic_83122_flag)) {
		ret = pen_driver_83102_get_dsram_data(tdev, info_data, len);
		return ret;
	}
	temp_info_data = kzalloc(read_size, GFP_KERNEL);
	if (!temp_info_data) {
		thp_log_err(tdev->thp_core, "%s: temp_info_data malloc fail\n", __func__);
		return -ENOMEM;
	}
	ret = thp_bus_lock(tdev->thp_core);
	if (ret < 0) {
		thp_log_err(tdev->thp_core, "%s:get lock failed\n", __func__);
		kfree(temp_info_data);
		return -EINVAL;
	}

	pen_himax_assign_data(HIMAX_PEN_RAWDATA_ADDR, tmp_addr);
	if (himax_p->hx_get_frame_optimized_flag) {
		if (pen_driver_bus_read(tdev, HIMAX_PEN_EVENT_STACK_CMD_ADDR,
			temp_info_data, read_size, HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
			thp_log_err(tdev->thp_core, "%s: spi access fail!\n", __func__);
			ret = -ENOMEM;
		}
	} else {
		pen_driver_interface_on(tdev);
		ret = pen_driver_register_read(tdev, tmp_addr, read_size,
			temp_info_data);
	}

	thp_bus_unlock(tdev->thp_core);

	memcpy(info_data, temp_info_data, read_size);
	kfree(temp_info_data);
	temp_info_data = NULL;

	return ret;
}

static int pen_driver_get_event_stack(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	unsigned int read_size = len;

	if (!len) {
		thp_log_err(tdev->thp_core, "%s:len is invalid\n", __func__);
		return -EINVAL;
	}
	if (!buf) {
		thp_log_err(tdev->thp_core, "%s:buf is null\n", __func__);
		return -EINVAL;
	}
	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s:dev is null\n", __func__);
		return -EINVAL;
	}
	thp_bus_lock(tdev->thp_core);

	if (pen_driver_bus_read(tdev, HIMAX_PEN_EVENT_STACK_CMD_ADDR,
		buf, read_size, HIMAX_PEN_BUS_RETRY_TIMES) < 0) {
		thp_log_err(tdev->thp_core, "%s: spi access fail!\n", __func__);
		thp_bus_unlock(tdev->thp_core);
		return -EINVAL;
	}

	thp_bus_unlock(tdev->thp_core);

	return NO_ERR_PEN;
}

static int pen_driver_83102_get_frame(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	struct himax_thp_pen_private_data *himax_p = NULL;

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: input dev null\n", __func__);
		return -EINVAL;
	}
	himax_p = tdev->private_data;

	if (!len) {
		thp_log_err(tdev->thp_core, "%s: read len illegal\n", __func__);
		return -EINVAL;
	}

	if (himax_p->hx_get_frame_optimized_flag)
		return pen_driver_get_event_stack(tdev, buf, len);
	else
		return pen_driver_get_dsram_data(tdev, buf, len);
}

static int pen_driver_83112_get_frame(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	int ret;
	struct himax_thp_pen_private_data *himax_p = NULL;

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: input dev null\n", __func__);
		return -EINVAL;
	}
	if (!buf) {
		thp_log_err(tdev->thp_core, "%s: buf null\n", __func__);
		return -EINVAL;
	}
	if (!len) {
		thp_log_err(tdev->thp_core, "%s: read len illegal\n", __func__);
		return -EINVAL;
	}
	himax_p = tdev->private_data;
	if ((himax_p->himax_ic_83102_flag) || (himax_p->himax_ic_83121_flag)
	|| (himax_p->himax_ic_83122_flag)) {
		ret = pen_driver_83102_get_frame(tdev, buf, len);
		return ret;
	}
	return pen_driver_get_dsram_data(tdev, buf, len);
}

static int pen_driver_83112_resume(struct thp_device *tdev)
{
	struct himax_thp_pen_private_data *himax_p = NULL;
	thp_log_debug(tdev->thp_core, "%s: called_\n", __func__);

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return -EINVAL;
	}
#if (IS_ENABLED(CONFIG_HONOR_THP_MTK))
	pinctrl_select_state(tdev->thp_core->pctrl, tdev->thp_core->mtk_pinctrl.cs_high);
#endif
	himax_p = tdev->private_data;
	return 0;
}

static int pen_driver_83112_suspend(struct thp_device *tdev)
{
	struct thp_core_data *cd = NULL;
	struct himax_thp_pen_private_data *himax_p = NULL;

	thp_log_info(tdev->thp_core, "%s: called\n", __func__);

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return -EINVAL;
	}
	himax_p = tdev->private_data;
	cd = thp_get_core_data();
	if (!cd) {
		thp_log_err(tdev->thp_core, "%s: null ptr\n", __func__);
		return -EINVAL;
	}
	if ((cd->easy_wakeup_info.sleep_mode != TS_GESTURE_MODE) ||
		(!cd->support_gesture_mode)) {

		pinctrl_select_state(cd->pctrl, cd->pins_idle);
		thp_do_time_delay(
			tdev->timing_config.suspend_reset_after_delay_ms);
	} else {
		thp_log_info(tdev->thp_core, "%s: suspend in gesture mode\n", __func__);
	}
	return 0;
}

static void pen_driver_83112_exit(struct thp_device *tdev)
{
	struct himax_thp_pen_private_data *himax_p = NULL;

	if (!tdev) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return;
	}

	himax_p = tdev->private_data;
	thp_log_info(tdev->thp_core, "%s: called\n", __func__);

	if ((!himax_p->himax_ic_83102_flag) && (!himax_p->himax_ic_83121_flag)
	&& (!himax_p->himax_ic_83122_flag)) {
		kfree(g_himax_pen_spi_buf.w_buf);
		g_himax_pen_spi_buf.w_buf = NULL;
		kfree(g_himax_pen_spi_buf.r_buf_a);
		g_himax_pen_spi_buf.r_buf_a = NULL;
		kfree(g_himax_pen_spi_buf.r_buf_b);
		g_himax_pen_spi_buf.r_buf_b = NULL;
		goto exit;
	}

exit:
	kfree(tdev->tx_buff);
	tdev->tx_buff = NULL;
	kfree(tdev->rx_buff);
	tdev->rx_buff = NULL;
	kfree(tdev);
	tdev = NULL;
}

static struct thp_device_ops hx83121_dev_ops = {
	.init = pen_driver_init,
	.detect = pen_driver_83121_chip_detect,
	.get_frame = pen_driver_83112_get_frame,
	.chip_gesture_report = pen_driver_gesture_report,
	.resume = pen_driver_83112_resume,
	.suspend = pen_driver_83112_suspend,
	.exit = pen_driver_83112_exit,
};

int himax_pen_driver_module_init(struct thp_core_data *cd)
{
	int rc = 0;
	struct thp_device *dev = NULL;

	thp_log_debug(cd, "%s: called\n", __func__);

	dev = kzalloc(sizeof(struct thp_device), GFP_KERNEL);
	if (!dev) {
		thp_log_err(cd, "%s: thp device malloc fail\n", __func__);
		return -ENOMEM;
	}

	dev->tx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	dev->rx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!dev->tx_buff || !dev->rx_buff) {
		thp_log_err(cd, "%s: out of memory\n", __func__);
		rc = -ENOMEM;
		goto err;
	}

	dev->ic_name = HX83122_PEN_IC_NAME;
	dev->dev_node_name = THP_PEN_HX83122_DEV_NODE_NAME;
	dev->ops = &hx83121_dev_ops;
	dev->private_data = (void *)&thp_pen_private_data;
	thp_pen_send_detect_cmd(cd, dev, NO_SYNC_TIMEOUT);
	// rc = thp_pen_register_dev(cd, dev);

	return rc;
err:
	kfree(dev->tx_buff);
	dev->tx_buff = NULL;
	kfree(dev->rx_buff);
	dev->rx_buff = NULL;
	kfree(dev);
	dev = NULL;
	return rc;
}
