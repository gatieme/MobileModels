/*
 * Thp driver code for goodix
 *
 * Copyright (c) 2012-2021 Honor Technologies Co., Ltd.
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
#include <linux/string.h>
#include "honor_thp.h"

#include <linux/time.h>
#include <linux/syscalls.h>

#define NO_ERR 0
#define ERR    1
#define ENABLE 1

#define GOODIX_IC_NAME "goodix"
#define THP_GOODIX_DEV_NODE_NAME "goodix_thp"

#define MODULE_INFO_READ_RETRY 5
#define FW_INFO_READ_RETRY 3
#define SEND_COMMAND_RETRY 3
#define SEND_COMMAND_MULTIPLE_RETRY 10
#define CHECK_COMMAND_RETRY 3

#define GOODIX_FRAME_ADDR_DEFAULT 0x8C05
#define GOODIX_CMD_ADDR_DEFAULT 0x58BF
#define GOODIX_FW_STATE_ADDR_DEFAULT 0xBFDE
#define GOODIX_FW_STATE_LEN_DEFAULT 10
#define GOODIX_MODULE_INFO_ADDR 0x452C
#define GOODIX_PROJECT_ID_ADDR 0xBDB4
#define GOODIX_AFE_INFO_ADDR 0x6D20
#define GOODIX_MAX_AFE_LEN 300
#define GOODIX_FRAME_LEN_OFFSET 20
#define GOODIX_FRAME_ADDR_OFFSET 22
#define GOODIX_FW_STATUS_LEN_OFFSET 91
#define GOODIX_FW_STATUS_ADDR_OFFSET 93
#define GOODIX_CMD_ADDR_OFFSET 102
/* GT9896 default addr */
#define GOODIX_FRAME_ADDR_DEFAULT_GT9896 0x4280
#define GOODIX_CMD_ADDR_DEFAULT_GT9896 0x4168
#define GOODIX_MODULE_INFO_ADDR_GT9896 0x4018
#define GOODIX_PROJECT_ID_ADDR_GT9896 0x4114
#define GOODIX_AFE_INFO_ADDR_GT9896 0x4014
#define GOODIX_MAX_AFE_LEN_GT9896 300
#define GOODIX_FRAME_LEN_OFFSET_GT9896 77
#define GOODIX_FRAME_ADDR_OFFSET_GT9896 79
#define GOODIX_CMD_ADDR_OFFSET_GT9896 67
#define GOODIX_READ_WRITE_BYTE_OFFSET_GT9896 5
#define GOODIX_CMD_ACK_OFFSET_GT9896 5
#define GOODIX_MASK_ID_FOR_GT9896 "YELSTO"
#define SPI_ARGS_WRITE_RETRY 5
#define GOODIX_SPI_TRANSFER_ARGS_ADDR 0x3082
#define SPI_TRANSFER_ARGS 0x0F
#define GOODIX_FRAME_LEN_MAX_GT9896 2048

/* GT9897 default addr */
#define GOODIX_FRAME_ADDR_DEFAULT_GT9897 0x10268
#define GOODIX_CMD_ADDR_DEFAULT_GT9897 0x10180
#define GOODIX_MODULE_INFO_ADDR_GT9897 0x1000C
#define GOODIX_PROJECT_ID_ADDR_GT9897 0x10028
#define GOODIX_AFE_INFO_ADDR_GT9897 0x10068
#define GOODIX_TOUCH_ADDR_DEFAULT_GT9897_DUAL 0x101A0
#define GOODIX_MAX_AFE_LEN_GT9897 300
#define GOODIX_FRAME_LEN_OFFSET_GT9897 77
#define GOODIX_FRAME_ADDR_OFFSET_GT9897 79
#define GOODIX_CMD_ADDR_OFFSET_GT9897 67
#define GOODIX_READ_WRITE_BYTE_OFFSET_GT9897 9
#define GOODIX_CMD_ACK_OFFSET_GT9897 1
#define CMD_PT_MODE_GT9897 0x84
#define CMD_PT_OUT_IDLE 0x9f
#define CMD_GESTURE_MODE_GT9897 0xA6
#define GOODIX_MASK_ID_FOR_GT9897 "BERLIN"
#define GOODIX_MASK_ID_FOR_GT9897_NOCODE "NOCODE"
#define GOODIX_GT9897S_SEND_CMD_WAIT_DELAY 10
#define GOODIX_FRAME_LEN_MAX_GT9897 2048
#define GOODIX_GESTURE_CMD_ADDR_GT9897 0x10282
#define GESTURE_CMD_SWITCH_ACK_GT9897 0xFD
#define GESTURE_CMD_SWITCH_GT9897 0x02
#define CMD_UDFP_EVENT_SWITCH_GT9897S 0xB3
#define CMD_AOD_EVENT_SWITCH_GT9897S 0xB4
#define CMD_LOWPOWER_SWITCH_GT9897S 0x97
#define CMD_TOUCH_GESTURE_SWITCH_GT9897S 0xA6
#define CMD_STYLUS_GESTURE_GT9897S 0xAE
#define CMD_SWITCH_INT_PIN 0xA9
#define CMD_SWITCH_INT_PIN_GT9897 0xA5
#define CMD_SWITCH_INT_AP 0x0
#define CMD_SWITCH_INT_SH 0x1
#define CMD_GESTURE_DOUBLE 0x02
#define GOODIX_DELAY_5MS_9897 5
#define GOODIX_FLASH_CTRLLER_REG1_GT9897 0xD806
#define GOODIX_FLASH_CTRLLER_REG2_GT9897 0xD006
#define GOODIX_FLASH_CTRLLER_REG3_GT9897 0xD808
#define GOODIX_FLASH_CTR_MODE_GT9897 0x77
#define GOODIX_FLASH_RW_MODE_GT9897 0x3C
#define GOODIX_FLASH_EN_MODE_GT9897 0xFA
#define GOODIX_DEBUG_LEN_START 38
#define GOODIX_DEBUG_LEN_END 159

/* GT9966 default addr */
#define GOODIX_FRAME_ADDR_DEFAULT_GT9966 0x1058C
#define GOODIX_TUI_FRAME_ADDR_GT9966 0x10274
#define GOODIX_TUI_FRAME_ADDR_GT9916 0x10308
#define GOODIX_CMD_ADDR_DEFAULT_GT9966 0x10174
#define GOODIX_MODULE_INFO_ADDR_GT9966 0x10014
#define GOODIX_PROJECT_ID_ADDR_GT9966 0x10030
#define GOODIX_AFE_INFO_ADDR_GT99966 0x10070
#define GOODIX_FRAME_LEN_MAX_GT9966 4096
#define GOODIX_READ_WRITE_BYTE_OFFSET_GT9966 8
#define CMD_LOWPOWER_SWITCH_GT9966 0x97
#define ENABLE_LP 0x01
#define DISABLE_LP 0x00
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
static struct udfp_mode_status gdix_set_mode;
#endif
/* 9X stylus3 bt connect status config info */
#define BT_CONNECT_STATUS_ADDR 0x10180
#define BT_CONNECT_STATUS_BUF_LEN 7
#define BT_CONNECT_BUF2 0x05
#define BT_CONNECT_BUF3 0xA4
#define BT_CONNECT_BUF4 0x02
#define BT_CONNECT_BUF5 0xAB
#define BT_DISCONNECT_BUF2 0x05
#define BT_DISCONNECT_BUF3 0xA4
#define BT_DISCONNECT_BUF5 0xA9
#define SEND_BT_CONNECT_STATUS_AFTER_RESET_DELAY 200
#define BT_CONNECT_STATUS_CHECK_ADDR 0x10169
#define BT_CONNECT_CMD_RETRY 3
#define BT_CHECK_DATA_LEN 1
#define BT_CONNECT_VALUE 1
#define BT_DISCONNECT_VALUE 0
#define BT_AFTER_WRITE_CMD_DELAY 20

#define CMD_ACK_IDLE_GT9897 0x01
#define CMD_ACK_BUSY_GT9897 0x02
#define CMD_ACK_BUFFER_OVERFLOW_GT9897 0x03
#define CMD_ACK_CHECKSUM_ERROR_GT9897 0x04
#define CMD_ACK_OK_GT9897 0x80
/* GT9916 default addr */
#define GOODIX_FRAME_ADDR_DEFAULT_GT9916 0x10400
#define GOODIX_FRAME_LEN_MAX_GT9916 2500

#define CMD_ACK_BUF_OVERFLOW 0x01
#define CMD_ACK_CHECKSUM_ERROR 0x02
#define CMD_ACK_BUSY 0x04
#define CMD_ACK_OK 0x80
#define CMD_ACK_IDLE 0xFF
#define CMD_ACK_UNKNOWN 0x00
#define CMD_ACK_ERROR (-1)

#define CMD_FRAME_DATA 0x90
#define CMD_HOVER 0x91
#define CMD_FORCE 0x92
#define CMD_SLEEP 0x96
#define CMD_SCREEN_ON_OFF 0x96
#define CMD_SCREEN_ON_OFF_9897  0xa5

#define CMD_PT_MODE 0x05
#define CMD_GESTURE_MODE 0xB5

#define IC_STATUS_GESTURE 0x01
#define IC_STATUS_POWEROF 0x02
#define IC_STATUS_UDFP 0x04
#define IC_STATUS_PT_TEST 0x08

#define PT_MODE 0

#define FEATURE_ENABLE 1
#define FEATURE_DISABLE 0

#define CMD_TUI_GT9966 0xB8
#define ENABLE_TUI 0x01
#define DISABLE_TUI 0x00

#define SPI_FLAG_WR 0xF0
#define SPI_FLAG_RD 0xF1
#define MASK_8BIT 0xFF
#define MASK_1BIT 0x01
#define MASK_32BIT 0xFFFF

#define GOODIX_MASK_ID "NOR_G1"
#define GOODIX_MASK_ID_LEN 6
#define MOVE_8BIT 8
#define MOVE_16BIT 16
#define MOVE_24BIT 24
#define MAX_FW_STATUS_DATA_LEN 64

#define SEND_COMMAND_WAIT_DELAY 10
#define SEND_COMMAND_END_DELAY 2
#define SEND_COMMAND_SPI_READ_LEN 1
#define COMMAND_BUF_LEN 5
#define COMMUNI_CHECK_RETRY_DELAY 10
#define DELAY_1MS 1
#define NO_DELAY 0
#define GET_AFE_INFO_RETRY_DELAY 10
#define DEBUG_AFE_DATA_BUF_LEN 20
#define DEBUG_AFE_DATA_BUF_OFFSET DEBUG_AFE_DATA_BUF_LEN

#define INFO_ADDR_BUF_LEN 2
#define IRQ_EVENT_TYPE_FRAME 0x80
#define IRQ_EVENT_TYPE_GESTURE 0x81
#define IRQ_EVENT_TYPE_GESTURE_GT9897_DUAL 0x20

#define GESTURE_EVENT_HEAD_LEN 6
#define GESTURE_TYPE_DOUBLE_TAP 0x01
#define GESTURE_EVENT_HEAD_LEN_GT9897_DUAL 8
#define GESTURE_TYPE_VALUE_GT897_DUAL 4
#define GESTURE_TYPE_DOUBLE_TAP_GT9897_DUAL 0xCC
#define GESTURE_TYPE_PEN_SINGLE_TAP_GT9897_DUAL 0xD0
#define GESTURE_DATA_MINI_SIZE_GT9897_DUAL 2
#define GOODIX_CUSTOME_INFO_LEN 30
#define GOODIX_GET_PROJECT_ID_RETRY 3
#define GOODIX_GET_PROJECT_RETRY_DELAY_10MS 10
#define IDLE_WAKE_FLAG 0xF0
#define IDLE_SPI_SPEED 3500
#define ACTIVE_SPI_SPEED 7500000
#define READ_WRITE_BYTE_OFFSET 1
#define READ_CMD_BUF_LEN 3
#define CMD_TOUCH_REPORT 0xAC
#define WAIT_FOR_SPI_BUS_RESUMED_DELAY 20
#define WAIT_FOR_SPI_BUS_READ_DELAY 5
#define GOODIX_SPI_READ_XFER_LEN 2
#define SPI_WAKEUP_RETRY 8
#define GOODIX_LCD_EFFECT_FLAG_POSITION 12
#define DEBUG_BUF_LEN 160
#define GET_AFE_BUF_LEN 2
#define WAIT_FOR_COMMUNICATION_CHECK_DELAY 10
#define GOODIX_BE_MODE 0
#define GOODIX_LE_MODE 1
#define DOUBLE_TAP_FLAG 2
#define SPI_READ_RETRY_TIME 20
#define SPI_DELAY_MS 5

#define GOODIX_SWITCH_CMD_LEN_9897 6
#define GOODIX_SWITCH_DATA_LEN_9897 2
#define GOODIX_SWITCH_BUFF_LEN_9897 8
#define COMMUNREG_GT9897    0xC900
#define COMMUNREG_DATA_LEN_GT9897    1
#define COMMUNREG_RETRY_TIME_GT9897  3

#define PEN_SWITCH 0xA4
#define STYLUS_CLOSE 0x00
#define STYLUS_OPEN 0x02
#define STYLUS_EVENT 3

#pragma pack(1)
struct thp_goodix_cmd_9897 {
	union {
		struct {
			u8 state;
			u8 ack;
			u8 len;
			u8 cmd;
			u8 data[GOODIX_SWITCH_DATA_LEN_9897];
			u16 checksum;
		};
		u8 buf[GOODIX_SWITCH_BUFF_LEN_9897];
	};
};
#pragma pack()

#pragma pack(1)
struct goodix_module_info {
	u8 mask_id[6]; /* 6 is mask id len */
	u8 mask_vid[3]; /* 3 is mask vid len */
	u8 pid[8]; /* 8 is pid len */
	u8 vid[4]; /* 4 is vid len */
	u8 sensor_id;
	u8 reserved[49]; /* 49 is reserved len */
	u8 checksum;
};
#pragma pack()

#pragma pack(1)
struct goodix_module_info_for_gt9896 {
	u8 mask_id[6]; /* 6 is mask id len */
	u8 mask_vid[4]; /* 4 is mask vid len */
	u8 pid[8]; /* 8 is pid len */
	u8 cid;
	u8 vid[4]; /* 4 is vid len */
	u8 sensor_id;
	u8 reserved[2]; /* 2 is reserved len */
	u16 checksum;
};
#pragma pack()

#pragma pack(1)
struct goodix_module_info_for_gt9966 {
	u8 rom_pid[6];               /* rom PID */
	u8 rom_vid[3];               /* Mask VID */
	u8 rom_vid_reserved;
	u8 patch_pid[8];              /* Patch PID */
	u8 patch_vid[4];              /* Patch VID */
	u8 patch_vid_reserved;
	u8 sensor_id;
	u8 reserved[2];
	u16 checksum;
};
#pragma pack()

#pragma pack(1)
struct goodix_device_info {
	struct goodix_module_info module_info;
	struct goodix_module_info_for_gt9896 module_info_for_gt9896;
	struct goodix_module_info_for_gt9896 module_info_for_gt9897;
	struct goodix_module_info_for_gt9966 module_info_for_gt9966;

	int goodix_frame_addr;
	int goodix_frame_len;
	int goodix_cmd_addr;
	int goodix_fw_status_addr;
	int goodix_fw_status_len;
	int goodix_touch_addr;
	int tui_finger_last_status;
	unsigned int thp_udfp_status;
	unsigned int goodix_ring_setting_switch;
	unsigned int goodix_stylus_status;
	unsigned int work_status;
	unsigned int goodix_esd_status;
	unsigned int aod_touch_status;
	/*
	 * stylus_gesture_status_only means enable instant write only
	 * no single, double click and FP
	 */
	unsigned int stylus_gesture_status_only;
	unsigned int stylus_gesture_status;
	bool stylus_gesture_status_lowpower;
	u8 *goodix_spi_tx_buf;
};
#pragma pack()

enum goodix_ic_type {
	GT9886,
	GT9896 = 1,
	GT9897 = 2,
	GT9966,
	GT9916,
};
enum gesture_data_offset_gt9897_daul {
	DATA0 = 0,
	DATA1,
	DATA2,
};

static int touch_driver_9x_bt_handler(struct thp_device *tdev,
	bool delay_enable);
static int touch_driver_gesture_event(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value);
static int touch_driver_gesture_event_9897(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value);
static int touch_driver_gesture_event_for_gt9897_dual(
	struct thp_device *tdev, unsigned int *gesture_wakeup_value);
static int touch_driver_switch_cmd(struct thp_device *tdev, u8 cmd, u8 status,
	int retry_count);
static int touch_driver_idle_wakeup(struct thp_device *tdev);
static int touch_driver_spi_active(struct thp_device *tdev);
static int touch_driver_spi_read_for_9897(struct thp_device *tdev,
	u8 *tx_buf, u8 *rx_buf, struct spi_transfer *xfers,
	struct spi_message *spi_msg, unsigned int addr, unsigned int len);
static int touch_driver_spi_write_for_9897(struct thp_device *tdev,
	u8 *tx_buf, unsigned int addr, struct spi_transfer *xfers,
	u8 *data, unsigned int len);
static int touch_driver_suspend_ap(struct thp_device *tdev);

/* gt9966 spi read */
static int touch_driver_spi_read_for_9966(struct thp_device *tdev,
	u8 *tx_buf, u8 *rx_buf, struct spi_transfer *xfers,
	struct spi_message *spi_msg,
	unsigned int addr, unsigned int len)
{
	int index = 0;

	tx_buf[index++] = SPI_FLAG_RD; /* 0xF1 start read flag */
	tx_buf[index++] = (addr >> MOVE_24BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = addr & MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;

	xfers[0].tx_buf = tx_buf;
	xfers[0].rx_buf = rx_buf;
	xfers[0].len = len + GOODIX_READ_WRITE_BYTE_OFFSET_GT9966;
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	/* 1 means transfers of a message need to chip select change */
	xfers[0].cs_change = 1;
#endif
	spi_message_add_tail(xfers, spi_msg);
	return 0;
}

static int touch_driver_spi_read(struct thp_device *tdev, unsigned int addr,
	u8 *data, unsigned int len)
{
	struct spi_device *spi = NULL;
	u8 *rx_buf = NULL;
	u8 *tx_buf = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;
	u8 *start_cmd_buf = (u8 *)private_data->goodix_spi_tx_buf;
	struct spi_transfer xfers[GOODIX_SPI_READ_XFER_LEN];
	struct spi_message spi_msg;
	int ret;
	int index = 0;
	struct thp_core_data *cd = NULL;
	int retry = 0;

	if ((data == NULL) || (tdev->tx_buff == NULL) ||
		(tdev->rx_buff == NULL) || (tdev->thp_core == NULL) ||
		(tdev->thp_core->sdev == NULL)) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}
	if (tdev->thp_core->support_vendor_ic_type == GT9897) {
		if ((len + GOODIX_READ_WRITE_BYTE_OFFSET_GT9897) >
			THP_MAX_FRAME_SIZE) {
			thp_log_err(tdev->thp_core, "%s:invalid len:%d\n", __func__, len);
			return -EINVAL;
		}
	} else if (tdev->thp_core->support_vendor_ic_type == GT9966) {
		if ((len + GOODIX_READ_WRITE_BYTE_OFFSET_GT9966) > THP_MAX_FRAME_SIZE) {
			thp_log_err(tdev->thp_core, "%s:invalid len:%d\n", __func__, len);
			return -EINVAL;
		}
	} else {
		if ((len + READ_WRITE_BYTE_OFFSET) > THP_MAX_FRAME_SIZE) {
			thp_log_err(tdev->thp_core, "%s:invalid len:%d\n", __func__, len);
			return -EINVAL;
		}
	}
	if (start_cmd_buf == NULL) {
		thp_log_err(tdev->thp_core, "%s:start_cmd_buf null\n", __func__);
		return -EINVAL;
	}
	ret = thp_bus_lock(tdev->thp_core);
	if (ret < 0) {
		thp_log_err(tdev->thp_core, "%s:get lock failed:%d\n", __func__, ret);
		return ret;
	}
	spi = tdev->thp_core->sdev;
	rx_buf = tdev->rx_buff;
	tx_buf = tdev->tx_buff;
	cd = tdev->thp_core;
	spi_message_init(&spi_msg);
	memset(xfers, 0, sizeof(xfers));

	if (cd->support_vendor_ic_type == GT9896) {
		tx_buf[index++] = SPI_FLAG_RD; /* 0xF1 start read flag */
		tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
		tx_buf[index++] = addr & MASK_8BIT;
		tx_buf[index++] = MASK_8BIT;
		tx_buf[index++] = MASK_8BIT;

		xfers[0].tx_buf = tx_buf;
		xfers[0].rx_buf = rx_buf;
		xfers[0].len = len + GOODIX_READ_WRITE_BYTE_OFFSET_GT9896;
		xfers[0].cs_change = 1;
		spi_message_add_tail(&xfers[0], &spi_msg);
	} else if (cd->support_vendor_ic_type == GT9897) {
		touch_driver_spi_read_for_9897(tdev, tx_buf, rx_buf,
			&xfers[0], &spi_msg, addr, len);
	} else if (cd->support_vendor_ic_type == GT9966 ||
		cd->support_vendor_ic_type == GT9916) {
		touch_driver_spi_read_for_9966(tdev, tx_buf, rx_buf,
			&xfers[0], &spi_msg, addr, len);
	} else {
		/* 0xF0 start write flag */
		start_cmd_buf[index++] = SPI_FLAG_WR;
		start_cmd_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
		start_cmd_buf[index++] = addr & MASK_8BIT;

		xfers[0].tx_buf = start_cmd_buf;
		xfers[0].len = READ_CMD_BUF_LEN;
		xfers[0].cs_change = 1;
		spi_message_add_tail(&xfers[0], &spi_msg);

		tx_buf[0] = SPI_FLAG_RD; /* 0xF1 start read flag */
		xfers[1].tx_buf = tx_buf;
		xfers[1].rx_buf = rx_buf;
		xfers[1].len = len + READ_WRITE_BYTE_OFFSET;
		xfers[1].cs_change = 1;
		spi_message_add_tail(&xfers[1], &spi_msg);
	}

	while (retry < SPI_READ_RETRY_TIME) {
		ret = thp_spi_sync(spi, &spi_msg);
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "Spi transfer error:%d\n", ret);
			if ((gdix_set_mode.lowpower_mode == 1) && cd->support_lowpower_no_irq) {
				thp_log_err(tdev->thp_core, "In lowpower state\n");
				private_data->goodix_esd_status = 1;
			}
			if (cd->suspended) {
				if (cd->support_no_spi_retry) {
					thp_log_info(tdev->thp_core, "support spi no retry, break\n");
					break;
				}
				retry++;
				msleep(SPI_DELAY_MS);
				continue;
			}
		}
		break;
	}

	if (cd->support_vendor_ic_type == GT9896)
		memcpy(data, &rx_buf[GOODIX_READ_WRITE_BYTE_OFFSET_GT9896],
			len);
	else if (cd->support_vendor_ic_type == GT9897)
		memcpy(data, &rx_buf[GOODIX_READ_WRITE_BYTE_OFFSET_GT9897],
			len);
	else if (cd->support_vendor_ic_type == GT9966 ||
		cd->support_vendor_ic_type == GT9916)
		memcpy(data, &rx_buf[GOODIX_READ_WRITE_BYTE_OFFSET_GT9966],
			len);
	else
		memcpy(data, &rx_buf[READ_WRITE_BYTE_OFFSET], len);
	thp_bus_unlock(tdev->thp_core);

	return ret;
}

static int touch_driver_spi_read_for_9897(struct thp_device *tdev,
	u8 *tx_buf, u8 *rx_buf, struct spi_transfer *xfers,
	struct spi_message *spi_msg,
	unsigned int addr, unsigned int len)
{
	int index = 0;

	tx_buf[index++] = SPI_FLAG_RD; /* 0xF1 start read flag */
	tx_buf[index++] = (addr >> MOVE_24BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = addr & MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;

	xfers[0].tx_buf = tx_buf;
	xfers[0].rx_buf = rx_buf;
	xfers[0].len = len + GOODIX_READ_WRITE_BYTE_OFFSET_GT9897;
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	/* 1 means transfers of a message need to chip select change */
	xfers[0].cs_change = 1;
#endif
	spi_message_add_tail(xfers, spi_msg);
	return 0;
}

static int touch_driver_spi_write(struct thp_device *tdev,
	unsigned int addr, u8 *data, unsigned int len)
{
	struct spi_device *spi = NULL;
	u8 *tx_buf = NULL;
	struct spi_transfer xfers;
	struct spi_message spi_msg;
	int ret;
	int index = 0;
	struct thp_core_data *cd = NULL;

	if ((data == NULL) || (tdev->tx_buff == NULL) ||
		(tdev->rx_buff == NULL) || (tdev->thp_core == NULL) ||
		(tdev->thp_core->sdev == NULL)) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}
	ret = thp_bus_lock(tdev->thp_core);
	if (ret < 0) {
		thp_log_err(tdev->thp_core, "%s:get lock failed\n", __func__);
		return -EINVAL;
	}
	spi = tdev->thp_core->sdev;
	tx_buf = tdev->tx_buff;
	cd = tdev->thp_core;
	spi_message_init(&spi_msg);
	memset(&xfers, 0, sizeof(xfers));

	if (cd->support_vendor_ic_type == GT9897 ||
		cd->support_vendor_ic_type == GT9966 ||
		cd->support_vendor_ic_type == GT9916) {
		touch_driver_spi_write_for_9897(tdev, tx_buf, addr,
			&xfers, data, len);
	} else {
		if (addr || (cd->support_vendor_ic_type == GT9896)) {
			tx_buf[index++] = SPI_FLAG_WR; /* 0xF1 start read flag */
			tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
			tx_buf[index++] = addr & MASK_8BIT;
			memcpy(&tx_buf[index++], data, len);
			xfers.len = len + 3;
		} else {
			memcpy(&tx_buf[0], data, len);
			xfers.len = len;
		}
	}

	xfers.tx_buf = tx_buf;
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	xfers.cs_change = 1;
#endif
	spi_message_add_tail(&xfers, &spi_msg);
	ret = thp_spi_sync(spi, &spi_msg);
	if (ret < 0)
		thp_log_err(tdev->thp_core, "Spi transfer error:%d, addr 0x%x\n", ret, addr);
	thp_bus_unlock(tdev->thp_core);

	return ret;
}

static int touch_driver_spi_write_for_9897(struct thp_device *tdev,
	u8 *tx_buf, unsigned int addr, struct spi_transfer *xfers,
	u8 *data, unsigned int len)
{
	int index = 0;

	tx_buf[index++] = SPI_FLAG_WR; /* 0xF1 start read flag */
	tx_buf[index++] = (addr >> MOVE_24BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = addr & MASK_8BIT;
	memcpy(&tx_buf[index++], data, len);
	xfers->len = len + 5; /* 5:WR header buf len */
	return 0;
}
static int touch_driver_get_cmd_ack(struct thp_device *tdev,
	unsigned int ack_reg)
{
	int ret;
	int i;
	u8 cmd_ack = 0;

	for (i = 0; i < CHECK_COMMAND_RETRY; i++) {
		/* check command result */
		ret = touch_driver_spi_read(tdev, ack_reg,
			&cmd_ack, 1);
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "%s: failed read cmd ack info, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		if (cmd_ack != CMD_ACK_OK) {
			ret = CMD_ACK_ERROR;
			if (cmd_ack == CMD_ACK_BUF_OVERFLOW) {
				mdelay(10); /* delay 10 ms */
				break;
			} else if ((cmd_ack == CMD_ACK_BUSY) ||
				(cmd_ack == CMD_ACK_UNKNOWN)) {
				mdelay(1); /* delay 1 ms */
				continue;
			}
			mdelay(1); /* delay 1 ms */
			break;
		}
		ret = 0;
		mdelay(SEND_COMMAND_END_DELAY);
		goto exit;
	}
exit:
	return ret;
}

#define GOODIX_SWITCH_CMD_BUF_LEN 6
static int touch_driver_switch_cmd_for_9896(struct thp_device *tdev,
	u8 cmd, u16 data)
{
	int ret;
	int i;
	int index = 0;
	u8 cmd_buf[GOODIX_SWITCH_CMD_BUF_LEN] = {0};
	u16 checksum = 0;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	checksum += cmd;
	checksum += data >> MOVE_8BIT;
	checksum += data & 0xFF;
	cmd_buf[index++] = cmd;
	cmd_buf[index++] = (u8)(data >> MOVE_8BIT);
	cmd_buf[index++] = (u8)(data & 0xFF);
	cmd_buf[index++] = (u8)(checksum >> MOVE_8BIT);
	cmd_buf[index++] = (u8)(checksum & 0xFF);
	cmd_buf[index++] = 0; /* cmd_buf[5] is used to clear cmd ack data */

	for (i = 0; i < SEND_COMMAND_RETRY; i++) {
		ret = touch_driver_spi_write(tdev, private_data->goodix_cmd_addr, cmd_buf,
			sizeof(cmd_buf));
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "%s: failed send command, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		ret = touch_driver_get_cmd_ack(tdev, private_data->goodix_cmd_addr +
			GOODIX_CMD_ACK_OFFSET_GT9896);
		if (ret == CMD_ACK_ERROR) {
			thp_log_err(tdev->thp_core, "%s: cmd ack info is error\n", __func__);
			continue;
		} else {
			break;
		}
	}
	return ret;
}

static int touch_driver_get_cmd_ack_for_9897(struct thp_device *tdev,
	unsigned int ack_reg)
{
	int ret;
	int i;
	u8 cmd_ack = 0;

	for (i = 0; i < CHECK_COMMAND_RETRY; i++) {
		/* check command result */
		ret = touch_driver_spi_read(tdev, ack_reg,
			&cmd_ack, 1);
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "%s: failed read cmd ack info, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		if (cmd_ack != CMD_ACK_OK_GT9897) {
			ret = CMD_ACK_ERROR;
			if (cmd_ack == CMD_ACK_BUFFER_OVERFLOW_GT9897) {
				mdelay(10); /* delay 10 ms */
				break;
			} else if ((cmd_ack == CMD_ACK_BUSY_GT9897) ||
				(cmd_ack == CMD_ACK_UNKNOWN)) {
				mdelay(1); /* delay 1 ms */
				continue;
			}
			mdelay(1); /* delay 1 ms */
			break;
		}
		ret = 0;
		msleep(GOODIX_GT9897S_SEND_CMD_WAIT_DELAY);
		goto exit;
	}
exit:
	thp_log_info(tdev->thp_core, "%s: command state ack info: 0x%x\n", __func__, cmd_ack);
	return ret;
}

static int touch_drive_switch_cmd_for_9897(
	struct thp_device *tdev, u8 cmd, u16 data, int retry)
{
	int ret;
	int i;
	struct thp_goodix_cmd_9897 cmd_send;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	memset(&cmd_send, 0, sizeof(cmd_send));

	cmd_send.len = GOODIX_SWITCH_CMD_LEN_9897;
	cmd_send.cmd = cmd;
	cmd_send.data[0] = data & MASK_8BIT;
	cmd_send.data[1] = (data >> MOVE_8BIT) & MASK_8BIT;
	cmd_send.checksum = cpu_to_le16(cmd_send.len + cmd_send.cmd +
					cmd_send.data[0] + cmd_send.data[1]);

	for (i = 0; i < retry; i++) {
		ret = touch_driver_spi_write(tdev, private_data->goodix_cmd_addr,
			cmd_send.buf, sizeof(cmd_send));
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "%s: failed send command, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		ret = touch_driver_get_cmd_ack_for_9897(tdev, private_data->goodix_cmd_addr +
			GOODIX_CMD_ACK_OFFSET_GT9897);
		if (ret == CMD_ACK_ERROR) {
			thp_log_err(tdev->thp_core, "%s: cmd ack info is error\n", __func__);
			continue;
		} else {
			break;
		}
	}
	return ret;
}

#define CMD_ACK_OFFSET 4
static int touch_driver_switch_cmd(struct thp_device *tdev,
	u8 cmd, u8 status, int retry_count)
{
	int ret = 0;
	int retry = 0;
	int index = 0;
	u8 cmd_buf[COMMAND_BUF_LEN];
	u8 cmd_ack = 0;
	struct thp_core_data *cd = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (tdev->thp_core == NULL) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	if (cd->support_vendor_ic_type == GT9896)
		return touch_driver_switch_cmd_for_9896(tdev, cmd, status);
	else if (cd->support_vendor_ic_type == GT9897 ||
		cd->support_vendor_ic_type == GT9966 ||
		cd->support_vendor_ic_type == GT9916)
		return touch_drive_switch_cmd_for_9897(tdev, cmd, status, retry_count);

	if (touch_driver_idle_wakeup(tdev)) {
		thp_log_err(tdev->thp_core, "failed wakeup idle before send command\n");
		return -EINVAL;
	}
	cmd_buf[index++] = cmd;
	cmd_buf[index++] = status;
	cmd_buf[index++] = 0 - cmd_buf[1] - cmd_buf[0]; /* checksum */
	cmd_buf[index++] = 0;
	cmd_buf[index++] = 0; /* use to clear cmd ack flag */
	while (retry++ < SEND_COMMAND_RETRY) {
		ret = touch_driver_spi_write(tdev, private_data->goodix_cmd_addr,
					cmd_buf, sizeof(cmd_buf));
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "%s: failed send command, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}

		ret = touch_driver_spi_read(tdev, private_data->goodix_cmd_addr + CMD_ACK_OFFSET,
					&cmd_ack, SEND_COMMAND_SPI_READ_LEN);
		if (ret < 0) {
			thp_log_err(tdev->thp_core,
				"%s: failed read command ack info, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}

		if (cmd_ack != CMD_ACK_OK) {
			ret = -EINVAL;
			thp_log_debug(tdev->thp_core, "%s: command state ack info 0x%x\n",
					__func__, cmd_ack);
			if (cmd_ack == CMD_ACK_BUF_OVERFLOW ||
				cmd_ack == CMD_ACK_BUSY)
				mdelay(SEND_COMMAND_WAIT_DELAY);
		} else {
			ret = 0;
			mdelay(SEND_COMMAND_END_DELAY);
			break;
		}
	}
	return ret;
}

static int thp_parse_feature_ic_config(struct device_node *thp_node,
	struct thp_core_data *cd)
{
	int rc;
	unsigned int value = 0;

	rc = of_property_read_u32(thp_node, "cmd_gesture_mode",
		&cd->cmd_gesture_mode);
	if (rc) {
		if (cd->support_vendor_ic_type == GT9897)
			cd->cmd_gesture_mode = CMD_GESTURE_MODE_GT9897;
		else
			cd->cmd_gesture_mode = CMD_GESTURE_MODE;
	}
	thp_log_info(cd, "%s:cd->cmd_gesture_mode = 0x%X, rc = %d\n",
			__func__, cd->cmd_gesture_mode, rc);

	cd->gesture_mode_double_tap = 0;
	rc = of_property_read_u32(thp_node, "gesture_mode_double_tap",
		&cd->gesture_mode_double_tap);
	if (!rc)
		thp_log_info(cd, "%s:gesture_mode_double_tap parsed:%d\n",
			__func__, cd->gesture_mode_double_tap);

	rc = of_property_read_u32(thp_node, "support_lowpower_no_irq", &value);
	if (!rc) {
		cd->support_lowpower_no_irq = value;
		thp_log_info(cd, "%s: support_lowpower_no_irq %u\n", __func__, value);
	}
	rc = of_property_read_u32(thp_node, "support_no_spi_retry", &value);
	if (!rc) {
		cd->support_no_spi_retry = value;
		thp_log_info(cd, "%s: support_no_spi_retry %u\n", __func__, value);
	}

	return rc;
}

static int touch_driver_init(struct thp_device *tdev)
{
	int rc;
	struct thp_core_data *cd = NULL;
	struct device_node *goodix_node = NULL;

	cd = tdev->thp_core;
	goodix_node = of_get_child_by_name(cd->thp_node,
					THP_GOODIX_DEV_NODE_NAME);

	thp_log_info(tdev->thp_core, "%s: called, ic_type %d\n", __func__,
		cd->support_vendor_ic_type);
	if (!goodix_node) {
		thp_log_info(tdev->thp_core, "%s: dev not config in dts\n", __func__);
		return -ENODEV;
	}

	rc = thp_parse_spi_config(goodix_node, cd);
	if (rc)
		thp_log_err(tdev->thp_core, "%s: spi config parse fail\n", __func__);

	rc = thp_parse_timing_config(tdev->thp_core, goodix_node, &tdev->timing_config);
	if (rc)
		thp_log_err(tdev->thp_core, "%s: timing config parse fail\n", __func__);

	rc = thp_parse_feature_config(goodix_node, cd);
	if (rc)
		thp_log_err(tdev->thp_core, "%s: feature_config fail\n", __func__);

	rc = thp_parse_feature_ic_config(goodix_node, cd);
	if (rc)
		thp_log_err(tdev->thp_core, "%s: feature_ic_config fail, use default\n",
			__func__);

	if (cd->support_gesture_mode) {
		cd->easy_wakeup_info.sleep_mode = TS_POWER_OFF_MODE;
		cd->easy_wakeup_info.easy_wakeup_gesture = false;
		cd->easy_wakeup_info.off_motion_on = false;
	}
	rc = thp_parse_trigger_config(goodix_node, cd);
	if (rc)
		thp_log_err(tdev->thp_core, "%s: trigger_config fail\n", __func__);
	return 0;
}

#ifdef CONFIG_ARCH_QTI_VM
static int checksum_u8_cmp(u8 *data, int size)
{
	u32 cal_checksum = 0;
	u32 r_checksum = 0;
	u32 i;

	if (size < 2)
		return ERR;

	for (i = 0; i < size - 2; i++)
		cal_checksum += data[i];
	r_checksum = data[size - 2] + (data[size - 1] << 8);

	return (cal_checksum & 0xFFFF) == r_checksum ? NO_ERR : ERR;
}
#endif

static u8 checksum_u8(u8 *data, u32 size)
{
	u8 checksum = 0;
	u32 i;
	int zero_count = 0;

	for (i = 0; i < size; i++) {
		checksum += data[i];
		if (!data[i])
			zero_count++;
	}
	return (zero_count == size) ? MASK_8BIT : checksum;
}

static u16 checksum16_cmp(struct thp_device *tdev, u8 *data, u32 size, int mode)
{
	u16 cal_checksum = 0;
	u16 checksum;
	u32 i;

	if (size < sizeof(checksum)) {
		thp_log_err(tdev->thp_core, "%s:inval parm\n", __func__);
		return ERR;
	}
	for (i = 0; i < size - sizeof(checksum); i++)
		cal_checksum += data[i];
	if (mode == GOODIX_BE_MODE)
		checksum = (data[size - sizeof(checksum)] << MOVE_8BIT) +
			data[size - 1];
	else
		checksum = data[size - sizeof(checksum)] +
			(data[size - 1] << MOVE_8BIT);

	if (cal_checksum == 0 && checksum == 0)
		return ERR;

	return (cal_checksum == checksum) ? NO_ERR : ERR;
}

#if IS_ENABLED(CONFIG_HONOR_THP_QCOM)
static void touch_driver_init_set(struct thp_device *tdev)
{
	int ret, i;
	u8 reg_val[2]  = {0};
	u8 temp_buf[2] = {0};

	for (i = 0 ; i < COMMUNREG_RETRY_TIME_GT9897 ; i++) {
		/* 0-set */
		reg_val[0] = 0x01;
		ret = touch_driver_spi_write(tdev, COMMUNREG_GT9897, reg_val,
			COMMUNREG_DATA_LEN_GT9897);
		thp_log_err(tdev->thp_core, "%s: write 0XC900, val[0]= %d\n",
				__func__, reg_val[0]);
		if (ret)
			thp_log_err(tdev->thp_core, "%s: failed write 0XC900, ret %d\n",
				__func__, ret);
		msleep(1);
		/* 1-read */
		ret = touch_driver_spi_read(tdev, COMMUNREG_GT9897, temp_buf, sizeof(temp_buf));
		thp_log_err(tdev->thp_core, "%s: read 0XC900, temp_buf[0]= %d\n",
				__func__, temp_buf[0]);
		if (ret)
			thp_log_err(tdev->thp_core, "%s:  failed read 0XC900, ret %d\n",
				__func__, ret);
		/* 2-compare */
		if (temp_buf[0] == reg_val[0]) {
			break;
		}
	}
}
#endif

static int touch_driver_communication_check_for_9897(
	struct thp_device *tdev)
{
	int len;
	int ret;
	int retry;
	u8 temp_buf[GOODIX_MASK_ID_LEN + 1] = {0};
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	len = sizeof(private_data->module_info_for_gt9897);
	memset(&private_data->module_info_for_gt9897, 0, len);
#if IS_ENABLED(CONFIG_HONOR_THP_QCOM)
	touch_driver_init_set(tdev);
#endif
	for (retry = 0; retry < MODULE_INFO_READ_RETRY; retry++) {
		ret = touch_driver_spi_read(tdev,
			GOODIX_MODULE_INFO_ADDR_GT9897,
			(u8 *)&private_data->module_info_for_gt9897, len);
		/* print 32*3 data (rowsize=32,groupsize=3),0:no ascii */
		print_hex_dump(KERN_INFO, "[I/THP] module info: ",
			DUMP_PREFIX_NONE, 32, 3,
			(u8 *)&private_data->module_info_for_gt9897, len, 0);
		if (!ret && !checksum16_cmp(tdev, (u8 *)&private_data->module_info_for_gt9897,
					len, GOODIX_LE_MODE))
			break;
		/* retry need delay 10ms */
		msleep(WAIT_FOR_COMMUNICATION_CHECK_DELAY);
#if IS_ENABLED(CONFIG_HONOR_THP_QCOM)
		touch_driver_init_set(tdev);
#endif
	}
	thp_log_info(tdev->thp_core, "hw info: ret %d, retry %d\n", ret, retry);
	if (retry == MODULE_INFO_READ_RETRY) {
		thp_log_err(tdev->thp_core, "%s: failed read module info\n", __func__);
		return -EINVAL;
	}
	if (memcmp(private_data->module_info_for_gt9897.mask_id, GOODIX_MASK_ID_FOR_GT9897,
		GOODIX_MASK_ID_LEN)) {
		if (memcmp(private_data->module_info_for_gt9897.mask_id,
			GOODIX_MASK_ID_FOR_GT9897_NOCODE, GOODIX_MASK_ID_LEN)) {
			memcpy(temp_buf, private_data->module_info_for_gt9897.mask_id,
				GOODIX_MASK_ID_LEN);
			thp_log_err(tdev->thp_core, "invalied mask id %s != %s\n",
				temp_buf, GOODIX_MASK_ID_FOR_GT9897);
			return -EINVAL;
		}
		memcpy(temp_buf, private_data->module_info_for_gt9897.mask_id,
			GOODIX_MASK_ID_LEN);
		thp_log_err(tdev->thp_core, "invalied mask id %s = %s\n",
			temp_buf, GOODIX_MASK_ID_FOR_GT9897_NOCODE);
	}
	thp_log_info(tdev->thp_core, "%s: communication check passed\n", __func__);
	memcpy(temp_buf, private_data->module_info_for_gt9897.mask_id, GOODIX_MASK_ID_LEN);
	temp_buf[GOODIX_MASK_ID_LEN] = '\0';
	thp_log_info(tdev->thp_core, "MASK_ID %s : ver %*ph\n", temp_buf,
		(u32)sizeof(private_data->module_info_for_gt9897.mask_vid),
		private_data->module_info_for_gt9897.mask_vid);
	thp_log_info(tdev->thp_core, "PID %s : ver %*ph\n", private_data->module_info_for_gt9897.pid,
		(u32)sizeof(private_data->module_info_for_gt9897.vid),
		private_data->module_info_for_gt9897.vid);
	return 0;
}

static int touch_driver_communication_check_for_9966(
	struct thp_device *tdev)
{
	int len;
	int ret;
	int retry;
	u8 temp_buf[DEBUG_BUF_LEN] = {0};
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	len = sizeof(private_data->module_info_for_gt9966);
	memset(&private_data->module_info_for_gt9966, 0, len);
	for (retry = 0; retry < MODULE_INFO_READ_RETRY; retry++) {
		ret = touch_driver_spi_read(tdev,
			GOODIX_MODULE_INFO_ADDR_GT9966,
			(u8 *)&private_data->module_info_for_gt9966, len);

		thp_log_debug(tdev->thp_core, "module_info:%*ph\n", len, (u8 *)&private_data->module_info_for_gt9966);
		if (!ret && !checksum16_cmp(tdev, (u8 *)&private_data->module_info_for_gt9966,
					len, GOODIX_LE_MODE))
			break;
		/* retry need delay 10ms */
		msleep(10);
	}
	thp_log_info(tdev->thp_core, "hw info: ret %d, retry %d\n", ret, retry);
	if (retry == MODULE_INFO_READ_RETRY) {
		thp_log_err(tdev->thp_core, "%s: failed read module info\n", __func__);
		return -EINVAL;
	}

	memcpy(temp_buf, private_data->module_info_for_gt9966.rom_pid, sizeof(private_data->module_info_for_gt9966.rom_pid));
	thp_log_info(tdev->thp_core, "rom_pid:%s\n", temp_buf);
	thp_log_info(tdev->thp_core, "rom_vid:%*ph\n", sizeof(private_data->module_info_for_gt9966.rom_vid),
		private_data->module_info_for_gt9966.rom_vid);
	memcpy(temp_buf, private_data->module_info_for_gt9966.patch_vid, sizeof(private_data->module_info_for_gt9966.patch_pid));
	thp_log_info(tdev->thp_core, "patch_pid:%s\n", temp_buf);
	thp_log_info(tdev->thp_core, "patch_vid:%*ph\n", sizeof(private_data->module_info_for_gt9966.patch_vid),
		private_data->module_info_for_gt9966.patch_vid);

	return 0;
}

static int touch_driver_communication_check_for_9896(
	struct thp_device *tdev)
{
	int ret;
	int len;
	int retry;
	u8 temp_buf[GOODIX_MASK_ID_LEN + 1] = {0};
	u8 wr_val;
	u8 rd_val;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	len = sizeof(private_data->module_info_for_gt9896);
	memset(&private_data->module_info_for_gt9896, 0, len);

	wr_val = SPI_TRANSFER_ARGS;
	for (retry = 0; retry < SPI_ARGS_WRITE_RETRY; retry++) {
		ret = touch_driver_spi_write(tdev,
			GOODIX_SPI_TRANSFER_ARGS_ADDR, &wr_val, 1);
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "%s:  spi write failed, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		ret = touch_driver_spi_read(tdev, GOODIX_SPI_TRANSFER_ARGS_ADDR,
			&rd_val, 1);
		if (ret < 0) {
			thp_log_err(tdev->thp_core, "%s: spi read fail, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		if (wr_val == rd_val)
			break;
		thp_log_info(tdev->thp_core, "%s:wr:0x%X, rd:0x%X", __func__, wr_val, rd_val);
	}
	for (retry = 0; retry < MODULE_INFO_READ_RETRY; retry++) {
		ret = touch_driver_spi_read(tdev,
			GOODIX_MODULE_INFO_ADDR_GT9896,
			(u8 *)&private_data->module_info_for_gt9896, len);
		/* print 32*3 data (rowsize=32,groupsize=3),0:no ascii */
		print_hex_dump(KERN_INFO, "[I/THP] module info: ",
			DUMP_PREFIX_NONE, 32, 3,
			(u8 *)&private_data->module_info_for_gt9896, len, 0);
		if (!ret)
			break;
		/* retry need delay 10ms */
		msleep(WAIT_FOR_COMMUNICATION_CHECK_DELAY);
	}
	thp_log_info(tdev->thp_core, "hw info: ret %d, retry %d\n", ret, retry);
	if (retry == MODULE_INFO_READ_RETRY) {
		thp_log_err(tdev->thp_core, "%s: failed read module info\n", __func__);
		return -EINVAL;
	}
	if (memcmp(private_data->module_info_for_gt9896.mask_id, GOODIX_MASK_ID_FOR_GT9896,
		GOODIX_MASK_ID_LEN)) {
		memcpy(temp_buf, private_data->module_info_for_gt9896.mask_id,
			GOODIX_MASK_ID_LEN);
		thp_log_err(tdev->thp_core, "%s: invalied mask id %s != %s\n", __func__,
			temp_buf, GOODIX_MASK_ID_FOR_GT9896);
		return -EINVAL;
	}
	thp_log_info(tdev->thp_core, "%s: communication check passed\n", __func__);
	memcpy(temp_buf, private_data->module_info_for_gt9896.mask_id, GOODIX_MASK_ID_LEN);
	temp_buf[GOODIX_MASK_ID_LEN] = '\0';
	thp_log_info(tdev->thp_core, "MASK_ID %s : ver %*ph\n", temp_buf,
		(u32)sizeof(private_data->module_info_for_gt9896.mask_vid),
		private_data->module_info_for_gt9896.mask_vid);
	thp_log_info(tdev->thp_core, "PID %s : ver %*ph\n", private_data->module_info_for_gt9896.pid,
		(u32)sizeof(private_data->module_info_for_gt9896.vid),
		private_data->module_info_for_gt9896.vid);
	return 0;
}

static int touch_driver_communication_check(struct thp_device *tdev)
{
	int ret;
	int len;
	int retry;
	u8 temp_buf[GOODIX_MASK_ID_LEN + 1] = {0};
	u8 checksum;
	struct thp_core_data *cd = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (tdev->thp_core == NULL) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	thp_log_info(tdev->thp_core, "%s, ic_type %d\n", __func__,
		cd->support_vendor_ic_type);
	if (cd->support_vendor_ic_type == GT9896)
		return touch_driver_communication_check_for_9896(tdev);
	else if (cd->support_vendor_ic_type == GT9897)
		return touch_driver_communication_check_for_9897(tdev);
	else if (cd->support_vendor_ic_type == GT9966 ||
		cd->support_vendor_ic_type == GT9916)
		return touch_driver_communication_check_for_9966(tdev);

	len = sizeof(private_data->module_info);
	memset(&private_data->module_info, 0, len);

	for (retry = 0; retry < MODULE_INFO_READ_RETRY; retry++) {
		ret = touch_driver_spi_read(tdev, GOODIX_MODULE_INFO_ADDR,
				(u8 *)&private_data->module_info, len);
		/* print 32*3 data (rowsize=32,groupsize=3) */
		print_hex_dump(KERN_INFO, "[I/THP] module info: ",
				DUMP_PREFIX_NONE,
				32, 3, (u8 *)&private_data->module_info, len, 0);
		checksum = checksum_u8((u8 *)&private_data->module_info, len);
		if (!ret && !checksum)
			break;

		mdelay(COMMUNI_CHECK_RETRY_DELAY);
	}

	thp_log_info(tdev->thp_core, "hw info: ret %d, checksum 0x%x, retry %d\n", ret,
		checksum, retry);
	if (retry == MODULE_INFO_READ_RETRY) {
		thp_log_err(tdev->thp_core, "%s:failed read module info\n", __func__);
		return -EINVAL;
	}

	if (memcmp(private_data->module_info.mask_id, GOODIX_MASK_ID,
			sizeof(GOODIX_MASK_ID) - 1)) {
		memcpy(temp_buf, private_data->module_info.mask_id, GOODIX_MASK_ID_LEN);
		thp_log_err(tdev->thp_core, "%s: invalied mask id %s != %s\n",
			__func__, temp_buf, GOODIX_MASK_ID);
		return -EINVAL;
	}

	thp_log_info(tdev->thp_core, "%s: communication check passed\n", __func__);
	memcpy(temp_buf, private_data->module_info.mask_id, GOODIX_MASK_ID_LEN);
	temp_buf[GOODIX_MASK_ID_LEN] = '\0';
	thp_log_info(tdev->thp_core, "MASK_ID %s : ver %*ph\n", temp_buf,
		(u32)sizeof(private_data->module_info.mask_vid), private_data->module_info.mask_vid);
	thp_log_info(tdev->thp_core, "PID %s : ver %*ph\n", private_data->module_info.pid,
		(u32)sizeof(private_data->module_info.vid), private_data->module_info.vid);
	return 0;
}

static int touch_driver_power_init(struct thp_core_data *cd)
{
	int ret;

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(cd, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#endif
	ret = thp_power_supply_get(cd, THP_VCC);
	if (ret)
		thp_log_err(cd, "%s:vcc fail\n", __func__);
	ret = thp_power_supply_get(cd, THP_IOVDD);
	if (ret)
		thp_log_err(cd, "%s:iovdd fail\n", __func__);

	return 0;
}

static void touch_driver_power_release(struct thp_core_data *cd)
{
#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(cd, "%s: called in QTVM, do nothing\n", __func__);
	return;
#endif
	thp_power_supply_put(cd, THP_VCC);
	thp_power_supply_put(cd, THP_IOVDD);
}

static int touch_driver_power_on(struct thp_device *tdev)
{
	int ret;

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#else
	thp_log_info(tdev->thp_core, "%s: called\n", __func__);
#endif
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	gpio_set_value(tdev->gpios->cs_gpio, GPIO_HIGH);
#endif
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_VCC, THP_POWER_ON, 0);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vcc fail\n", __func__);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_IOVDD, THP_POWER_ON, 1);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:iovdd fail\n", __func__);

	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
	return ret;
}

#define AFTER_VCC_POWERON_DELAY 65
#define AFTER_FIRST_RESET_GPIO_HIGH_DELAY 40
static int touch_driver_power_on_for_9896(struct thp_device *tdev)
{
	int ret;

	thp_log_info(tdev->thp_core, "%s:called\n", __func__);
	gpio_set_value(tdev->gpios->cs_gpio, GPIO_HIGH);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_VCC, THP_POWER_ON, NO_DELAY);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vcc fail\n", __func__);
	udelay(AFTER_VCC_POWERON_DELAY);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_IOVDD, THP_POWER_ON, 3); /* 3ms */
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vddio fail\n", __func__);

	thp_log_info(tdev->thp_core, "%s pull up tp ic reset\n", __func__);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
	return ret;
}

#define AFTER_IOVDD_DELAY_9897 7
#define AFTER_DVDD_RST_DELAY_9897 12
static int touch_driver_power_on_for_9897(struct thp_device *tdev)
{
	int ret;
	u8 regval;
	struct thp_core_data *cd = tdev->thp_core;

	if (cd == NULL) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}
	thp_log_info(tdev->thp_core, "%s:called\n", __func__);
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	gpio_set_value(tdev->gpios->cs_gpio, GPIO_HIGH);
#else
	if (cd->support_control_cs_off) {
		pinctrl_select_state(tdev->thp_core->pctrl,
			tdev->thp_core->mtk_pinctrl.cs_high);
		thp_log_info(tdev->thp_core, "%s:cs on\n", __func__);
	}
#endif
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_IOVDD,
		THP_POWER_ON, AFTER_IOVDD_DELAY_9897);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vddio fail\n", __func__);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_VCC, THP_POWER_ON,
		AFTER_DVDD_RST_DELAY_9897);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vcc fail\n", __func__);
	thp_log_info(tdev->thp_core, "%s pull up tp ic reset\n", __func__);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
	mdelay(GOODIX_DELAY_5MS_9897);
	regval = GOODIX_FLASH_CTR_MODE_GT9897;
	touch_driver_spi_write(tdev, GOODIX_FLASH_CTRLLER_REG1_GT9897,
				&regval, 1);
	regval = GOODIX_FLASH_RW_MODE_GT9897;
	touch_driver_spi_write(tdev, GOODIX_FLASH_CTRLLER_REG2_GT9897,
				&regval, 1);
	mdelay(GOODIX_DELAY_5MS_9897);
	regval = GOODIX_FLASH_EN_MODE_GT9897;
	touch_driver_spi_write(tdev, GOODIX_FLASH_CTRLLER_REG3_GT9897,
				&regval, 1);
	return ret;
}

static int touch_driver_power_on_for_9966(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = tdev->thp_core;

	if (cd == NULL) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#else
	thp_log_info(tdev->thp_core, "%s: called\n", __func__);
#endif

#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	gpio_set_value(tdev->gpios->cs_gpio, GPIO_HIGH);
#else
	if (cd->support_control_cs_off) {
		pinctrl_select_state(tdev->thp_core->pctrl,
			tdev->thp_core->mtk_pinctrl.cs_high);
		thp_log_info(tdev->thp_core, "%s:cs on\n", __func__);
	}
#endif
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_IOVDD,
		THP_POWER_ON, AFTER_IOVDD_DELAY_9897);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vddio fail\n", __func__);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_VCC, THP_POWER_ON,
		AFTER_DVDD_RST_DELAY_9897);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vcc fail\n", __func__);
	thp_log_info(tdev->thp_core, "%s pull up tp ic reset\n", __func__);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);

	return ret;
}

static int touch_driver_power_off(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = tdev->thp_core;

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#endif

	if (!cd) {
		thp_log_err(tdev->thp_core, "%s: have null ptr\n", __func__);
		return -EINVAL;
	}
	thp_log_info(tdev->thp_core, "%s pull down tp ic reset\n", __func__);
	if (cd->support_control_cs_off) {
		pinctrl_select_state(tdev->thp_core->pctrl,
			tdev->thp_core->pins_idle);
		thp_log_info(tdev->thp_core, "%s:cs off\n", __func__);
	} else {
		gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	}
	thp_do_time_delay(tdev->timing_config.suspend_reset_after_delay_ms);

	ret = thp_power_supply_ctrl(tdev->thp_core, THP_IOVDD, THP_POWER_OFF, NO_DELAY);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:iovdd fail\n", __func__);
	ret = thp_power_supply_ctrl(tdev->thp_core, THP_VCC, THP_POWER_OFF, NO_DELAY);
	if (ret)
		thp_log_err(tdev->thp_core, "%s:vcc fail\n", __func__);
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	gpio_set_value(tdev->gpios->cs_gpio, GPIO_LOW);
#endif
	return ret;
}

static void touch_driver_timing_work(struct thp_device *tdev)
{
	thp_log_info(tdev->thp_core, "%s:called,do hard reset delay:%d\n", __func__,
		tdev->timing_config.boot_reset_after_delay_ms);
	gpio_direction_output(tdev->gpios->rst_gpio, THP_RESET_HIGH);
	thp_do_time_delay(tdev->timing_config.boot_reset_after_delay_ms);
}

static int le16_data_check(u8 *data, int size)
{
	int i;
	int non_zero_count = 0;
	u16 checksum = 0;

	for (i = 0; i < (size - (int)(sizeof(u16))); i++) {
		checksum += data[i];
		if (data[i])
			non_zero_count++;
	}

	checksum -= data[i] + (data[i + 1] << MOVE_8BIT);

	return non_zero_count ? checksum : MASK_8BIT;
}

#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
static int le32_data_check(u8 *data, int size)
{
	int i;
	int non_zero_count = 0;
	u32 checksum = 0;
	u32 r_checksum;

	for (i = 0; i < (size - sizeof(checksum)); i += 2) {
		checksum += data[i] + (data[i + 1] << 8);
		if (data[i])
			non_zero_count++;
	}

	r_checksum = le32_to_cpup((__le32 *)&data[i]);
	checksum -= r_checksum;

	return non_zero_count ? checksum : MASK_8BIT;
}
#endif

static u16 checksum_16(struct thp_device *tdev, u8 *data, int size)
{
	int i;
	int non_zero_count = 0;
	u16 checksum = 0;

	if ((data == NULL) || (size <= sizeof(u16))) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return MASK_8BIT;
	}

	for (i = 0; i < (size - sizeof(u16)); i++) {
		checksum += data[i];
		if (data[i])
			non_zero_count++;
	}

	checksum += (data[i] << MOVE_8BIT) + data[i + 1];

	return non_zero_count ? checksum : MASK_8BIT;
}

static u32 checksum_32(struct thp_device *tdev, u8 *data, int size)
{
	int i;
	const int factor = 2;
	int non_zero_count = 0;
	u32 checksum = 0;

	if ((data == NULL) || (size <= sizeof(u32))) {
		thp_log_err(tdev->thp_core, "%s: tdev null\n", __func__);
		return MASK_8BIT;
	}

	for (i = 0; i < (size - sizeof(u32)); i += factor) {
		checksum += ((data[i] << MOVE_8BIT) | data[i + 1]);
		if (data[i] || data[i + 1])
			non_zero_count++;
	}

	checksum += (data[i] << MOVE_24BIT) + (data[i + 1] << MOVE_16BIT) +
		    (data[i + 2] << MOVE_8BIT) + data[i + 3];

	return non_zero_count ? checksum : MASK_8BIT;
}

static u32 checksum32_cmp(struct thp_device *tdev, u8 *data, int size)
{
	u32 cal_checksum = 0;
	u32 r_checksum;
	int i;

	if (size < GESTURE_DATA_MINI_SIZE_GT9897_DUAL) {
		thp_log_err(tdev->thp_core, "%s:inval parm\n", __func__);
		return MASK_32BIT;
	}
	for (i = 0; i < size - GESTURE_DATA_MINI_SIZE_GT9897_DUAL; i++)
		cal_checksum += data[i];

	r_checksum = data[size - DATA2] + (data[size - DATA1] << MOVE_8BIT);
	return ((cal_checksum & MASK_32BIT) == r_checksum) ? 0 : MASK_32BIT;
}

static void touch_driver_show_afe_debug_info(struct thp_device *tdev)
{
	u8 debug_buf[DEBUG_BUF_LEN] = {0};
	int ret;

	ret = touch_driver_spi_read(tdev,
		GOODIX_AFE_INFO_ADDR_GT9896,
		debug_buf, sizeof(debug_buf));
	if (ret) {
		thp_log_err(tdev->thp_core, "%s: failed read debug buf, ret %d\n",
			__func__, ret);
		return;
	}
	thp_log_info(tdev->thp_core, "debug_buf[0-20] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf); /* offset 0 */
	thp_log_info(tdev->thp_core, "debug_buf[20-40] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf +
		DEBUG_AFE_DATA_BUF_OFFSET); /* offset 20 */
	thp_log_info(tdev->thp_core, "debug_buf[40-60] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf +
		DEBUG_AFE_DATA_BUF_OFFSET * 2); /* offset 40 */
	thp_log_info(tdev->thp_core, "debug_buf[60-80] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf +
		DEBUG_AFE_DATA_BUF_OFFSET * 3); /* offset 60 */
	thp_log_info(tdev->thp_core, "debug_buf[80-100] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf +
		DEBUG_AFE_DATA_BUF_OFFSET * 4); /* offset 80 */
	thp_log_info(tdev->thp_core, "debug_buf[100-120] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf +
		DEBUG_AFE_DATA_BUF_OFFSET * 5); /* offset 100 */
	thp_log_info(tdev->thp_core, "debug_buf[120-140] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf +
		DEBUG_AFE_DATA_BUF_OFFSET * 6); /* offset 120 */
	thp_log_info(tdev->thp_core, "debug_buf[140-160] %*ph\n",
		DEBUG_AFE_DATA_BUF_LEN, debug_buf +
		DEBUG_AFE_DATA_BUF_OFFSET * 7); /* offset 140 */
}

static void touch_driver_get_afe_addr(struct thp_device *tdev, const u8 * const afe_data_buf,
	unsigned int len)
{
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if ((len <= 0) || (len > GOODIX_MAX_AFE_LEN_GT9896)) {
		thp_log_err(tdev->thp_core, "%s:invalid len:%d\n", __func__, len);
		return;
	}

	thp_log_info(tdev->thp_core, "%s: try get useful info from afe data\n",
		__func__);
	private_data->goodix_frame_addr =
		(afe_data_buf[GOODIX_FRAME_ADDR_OFFSET_GT9896] <<
		MOVE_8BIT) +
		afe_data_buf[GOODIX_FRAME_ADDR_OFFSET_GT9896 + 1];
	private_data->goodix_frame_len =
		(afe_data_buf[GOODIX_FRAME_LEN_OFFSET_GT9896] <<
		MOVE_8BIT) +
		afe_data_buf[GOODIX_FRAME_LEN_OFFSET_GT9896 + 1];
	private_data->goodix_cmd_addr =
		(afe_data_buf[GOODIX_CMD_ADDR_OFFSET_GT9896] <<
		MOVE_8BIT) +
		afe_data_buf[GOODIX_CMD_ADDR_OFFSET_GT9896 + 1];

	thp_log_info(tdev->thp_core, "%s: frame addr 0x%x, len %d, cmd addr 0x%x\n",
		__func__, private_data->goodix_frame_addr,
		private_data->goodix_frame_len, private_data->goodix_cmd_addr);
}

static int touch_driver_get_afe_info_for_9896(struct thp_device *tdev)
{
	int ret;
	int retry;
	int afe_data_len;
	u8 buf[GET_AFE_BUF_LEN] = {0};
	u8 afe_data_buf[GOODIX_MAX_AFE_LEN_GT9896] = {0};
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	for (retry = 0; retry < FW_INFO_READ_RETRY; retry++) {
		ret = touch_driver_spi_read(tdev, GOODIX_AFE_INFO_ADDR_GT9896,
			buf, sizeof(buf));
		if (ret) {
			thp_log_err(tdev->thp_core, "%s: failed read afe data length, ret %d\n",
				__func__, ret);
			goto error;
		}

		afe_data_len = (buf[0] << MOVE_8BIT) | buf[1];
		/* data len must be equal or less than GOODIX_MAX_AFE_LEN */
		if ((afe_data_len == 0) ||
			(afe_data_len > GOODIX_MAX_AFE_LEN_GT9896)) {
			thp_log_err(tdev->thp_core, "%s: invalid afe_data_len %d\n",
				__func__, afe_data_len);
			mdelay(GET_AFE_INFO_RETRY_DELAY);
			continue;
		}

		ret = touch_driver_spi_read(tdev, GOODIX_AFE_INFO_ADDR_GT9896,
			afe_data_buf, afe_data_len);
		if (ret) {
			thp_log_err(tdev->thp_core, "%s: failed read afe data, ret %d\n",
				__func__, ret);
			goto error;
		}
		if (!checksum16_cmp(tdev, afe_data_buf, afe_data_len,
				GOODIX_BE_MODE)) {
			thp_log_info(tdev->thp_core, "%s: successfuly read afe data\n",
				__func__);
			break;
		}
		thp_log_err(tdev->thp_core, "%s: afe data checksum error\n", __func__);
		touch_driver_show_afe_debug_info(tdev);
		mdelay(GET_AFE_INFO_RETRY_DELAY);
	}
	if (retry != FW_INFO_READ_RETRY) {
		touch_driver_get_afe_addr(tdev, afe_data_buf,
			GOODIX_MAX_AFE_LEN_GT9896);
		return 0;
	}
error:
	thp_log_err(tdev->thp_core, "%s: failed get afe info, use default\n", __func__);
	private_data->goodix_frame_addr = GOODIX_FRAME_ADDR_DEFAULT_GT9896;
	private_data->goodix_frame_len = GOODIX_FRAME_LEN_MAX_GT9896;
	private_data->goodix_cmd_addr = GOODIX_CMD_ADDR_DEFAULT_GT9896;
	thp_log_err(tdev->thp_core, "%s: afe data checksum error\n", __func__);
	return -EINVAL;
}

static int touch_driver_get_afe_info_for_9897(struct thp_device *tdev)
{
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	private_data->goodix_frame_addr = GOODIX_FRAME_ADDR_DEFAULT_GT9897;
	private_data->goodix_frame_len = GOODIX_FRAME_LEN_MAX_GT9897;
	private_data->goodix_cmd_addr = GOODIX_CMD_ADDR_DEFAULT_GT9897;
	thp_log_info(tdev->thp_core, "addr info, frame 0x%x:%d, cmd 0x%x\n",
		private_data->goodix_frame_addr, private_data->goodix_frame_len,
		private_data->goodix_cmd_addr);
	return 0;
}

static int touch_driver_get_afe_info_for_9966(struct thp_device *tdev)
{
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (tdev->thp_core->support_vendor_ic_type == GT9916) {
		private_data->goodix_frame_addr = GOODIX_FRAME_ADDR_DEFAULT_GT9916;
		private_data->goodix_frame_len = GOODIX_FRAME_LEN_MAX_GT9916;
	} else {
		private_data->goodix_frame_addr = GOODIX_FRAME_ADDR_DEFAULT_GT9966;
		private_data->goodix_frame_len = GOODIX_FRAME_LEN_MAX_GT9966;
	}
	private_data->goodix_cmd_addr = GOODIX_CMD_ADDR_DEFAULT_GT9966;
	thp_log_info(tdev->thp_core, "addr info, frame 0x%x:%d, cmd 0x%x\n",
		private_data->goodix_frame_addr, private_data->goodix_frame_len,
		private_data->goodix_cmd_addr);
	return 0;
}

static int touch_driver_get_afe_info(struct thp_device *tdev)
{
	int ret;
	int retry;
	unsigned int afe_data_len;
	u8 buf[INFO_ADDR_BUF_LEN] = {0};
	u8 afe_data_buf[GOODIX_MAX_AFE_LEN] = {0};
	struct thp_core_data *cd = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;
	private_data->goodix_frame_addr = GOODIX_FRAME_ADDR_DEFAULT;
	private_data->goodix_cmd_addr = GOODIX_CMD_ADDR_DEFAULT;
	private_data->goodix_fw_status_addr = GOODIX_FW_STATE_ADDR_DEFAULT;
	private_data->goodix_fw_status_len = GOODIX_FW_STATE_LEN_DEFAULT;
	private_data->goodix_touch_addr = GOODIX_TOUCH_ADDR_DEFAULT_GT9897_DUAL;

	if (tdev->thp_core == NULL) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	if (cd->support_vendor_ic_type == GT9896)
		return touch_driver_get_afe_info_for_9896(tdev);
	else if (cd->support_vendor_ic_type == GT9897)
		return touch_driver_get_afe_info_for_9897(tdev);
	else if (cd->support_vendor_ic_type == GT9966 ||
		cd->support_vendor_ic_type == GT9916)
		return touch_driver_get_afe_info_for_9966(tdev);

	for (retry = 0; retry < FW_INFO_READ_RETRY; retry++) {
		ret = touch_driver_spi_read(tdev, GOODIX_AFE_INFO_ADDR,
				buf, sizeof(buf));
		if (ret) {
			thp_log_err(tdev->thp_core, "%s: failed read afe data length, ret %d\n",
				__func__, ret);
			goto err_out;
		}

		afe_data_len = (buf[0] << MOVE_8BIT) | buf[1];
		/* data len must be equal or less than GOODIX_MAX_AFE_LEN */
		if ((afe_data_len == 0) || (afe_data_len > GOODIX_MAX_AFE_LEN)
			|| (afe_data_len & MASK_1BIT)) {
			thp_log_err(tdev->thp_core, "%s: invalied afe_data_len 0x%x retry\n",
				__func__, afe_data_len);
			mdelay(GET_AFE_INFO_RETRY_DELAY);
			continue;
		}
		thp_log_info(tdev->thp_core, "%s: got afe data len %d\n",
				__func__, afe_data_len);
		ret = touch_driver_spi_read(tdev,
			GOODIX_AFE_INFO_ADDR + INFO_ADDR_BUF_LEN,
			afe_data_buf, afe_data_len);
		if (ret) {
			thp_log_err(tdev->thp_core, "%s: failed read afe data, ret %d\n",
				__func__, ret);
			goto err_out;
		}

		if (!checksum_32(tdev, afe_data_buf, afe_data_len)) {
			thp_log_info(tdev->thp_core, "%s: successfuly read afe data\n",
				__func__);
			break;
		}
		thp_log_err(tdev->thp_core,
			"%s: afe data checksum error, checksum 0x%x, retry\n",
			__func__, checksum_32(tdev, afe_data_buf, afe_data_len));
		thp_log_err(tdev->thp_core, "afe_data_buf[0-20] %*ph\n",
			DEBUG_AFE_DATA_BUF_LEN, afe_data_buf); /* offset 0 */
		thp_log_err(tdev->thp_core, "afe_data_buf[20-40] %*ph\n",
			DEBUG_AFE_DATA_BUF_LEN, afe_data_buf +
			DEBUG_AFE_DATA_BUF_OFFSET); /* offset 20 */
		thp_log_err(tdev->thp_core, "afe_data_buf[40-60] %*ph\n",
			DEBUG_AFE_DATA_BUF_LEN, afe_data_buf +
			DEBUG_AFE_DATA_BUF_OFFSET * 2); /* offset 40 */
		thp_log_err(tdev->thp_core, "afe_data_buf[60-80] %*ph\n",
			DEBUG_AFE_DATA_BUF_LEN, afe_data_buf +
			DEBUG_AFE_DATA_BUF_OFFSET * 3); /* offset 60 */
		thp_log_err(tdev->thp_core, "afe_data_buf[80-100] %*ph\n",
			DEBUG_AFE_DATA_BUF_LEN, afe_data_buf +
			DEBUG_AFE_DATA_BUF_OFFSET * 4); /* offset 80 */
		mdelay(GET_AFE_INFO_RETRY_DELAY);
	}

	if (retry != FW_INFO_READ_RETRY) {
		thp_log_info(tdev->thp_core, "%s: try get useful info from afe data\n",
			__func__);
		private_data->goodix_frame_addr =
			(afe_data_buf[GOODIX_FRAME_ADDR_OFFSET] << MOVE_8BIT) +
			afe_data_buf[GOODIX_FRAME_ADDR_OFFSET + 1];
		private_data->goodix_frame_len =
			(afe_data_buf[GOODIX_FRAME_LEN_OFFSET] << MOVE_8BIT) +
			afe_data_buf[GOODIX_FRAME_LEN_OFFSET + 1];
		private_data->goodix_cmd_addr =
			(afe_data_buf[GOODIX_CMD_ADDR_OFFSET] << MOVE_8BIT) +
			afe_data_buf[GOODIX_CMD_ADDR_OFFSET + 1];
		private_data->goodix_fw_status_addr =
			(afe_data_buf[GOODIX_FW_STATUS_ADDR_OFFSET] <<
			MOVE_8BIT) +
			afe_data_buf[GOODIX_FW_STATUS_ADDR_OFFSET + 1];
		private_data->goodix_fw_status_len =
			(afe_data_buf[GOODIX_FW_STATUS_LEN_OFFSET] <<
			MOVE_8BIT) +
			afe_data_buf[GOODIX_FW_STATUS_LEN_OFFSET + 1];
		ret = 0;
	} else {
		thp_log_err(tdev->thp_core, "%s: failed get afe info, use default\n", __func__);
		ret = -EINVAL;
	}

err_out:
	thp_log_info(tdev->thp_core, "%s: frame addr 0x%x, len %d, cmd addr 0x%x\n", __func__,
			private_data->goodix_frame_addr, private_data->goodix_frame_len,
			private_data->goodix_cmd_addr);
	thp_log_info(tdev->thp_core, "%s: fw status addr 0x%x, len %d\n", __func__,
			private_data->goodix_fw_status_addr, private_data->goodix_fw_status_len);
	return ret;
}

static int touch_driver_chip_detect(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	thp_log_info(tdev->thp_core, "%s: called\n", __func__);

	private_data->goodix_spi_tx_buf = kzalloc(READ_CMD_BUF_LEN, GFP_KERNEL);
	if (private_data->goodix_spi_tx_buf == NULL) {
		thp_log_err(tdev->thp_core, "%s: goodix_spi_tx_buf null\n", __func__);
		ret = -ENOMEM;
		goto exit;
	}
	cd = tdev->thp_core;

#ifdef CONFIG_ARCH_QTI_VM
	private_data->tui_finger_last_status = TP_EVENT_FINGER_UP;
	// the project id is used to load afe lib and not used in qtvm side, just use dummy one.
	memcpy(tdev->thp_core->project_id, "9876543210", THP_PROJECT_ID_LEN);
	thp_log_debug(tdev->thp_core, "%s: called in QTVM, set project id directly\n", __func__);
	return 0;
#else
	thp_log_info(tdev->thp_core, "%s: ic_type %d\n", __func__, cd->support_vendor_ic_type);
#endif
	touch_driver_power_init(cd);
	if (cd->support_vendor_ic_type == GT9896)
		ret = touch_driver_power_on_for_9896(tdev);
	else if (cd->support_vendor_ic_type == GT9897)
		ret = touch_driver_power_on_for_9897(tdev);
	else if (cd->support_vendor_ic_type == GT9966 ||
		cd->support_vendor_ic_type == GT9916)
		ret = touch_driver_power_on_for_9966(tdev);
	else
		ret = touch_driver_power_on(tdev);
	if (ret)
		thp_log_err(tdev->thp_core, "%s: power on failed\n", __func__);

	touch_driver_timing_work(tdev);

	if (touch_driver_communication_check(tdev)) {
		thp_log_err(tdev->thp_core, "%s:communication check fail\n", __func__);
		touch_driver_power_off(tdev);
		/* check old panel */
		if (cd->support_reuse_ic_type) {
			cd->support_vendor_ic_type = GT9896;
			ret = touch_driver_power_on_for_9896(tdev);
		} else {
			cd->support_vendor_ic_type = GT9886;
			ret = touch_driver_power_on(tdev);
		}
		if (ret)
			thp_log_err(tdev->thp_core, "%s: power on failed\n", __func__);
		touch_driver_timing_work(tdev);
		if (touch_driver_communication_check(tdev)) {
			thp_log_err(tdev->thp_core, "%s:check old fail\n", __func__);
			touch_driver_power_off(tdev);
			touch_driver_power_release(cd);
			ret = -ENODEV;
			goto exit;
		}
	}

	if ((cd->send_bt_status_to_fw) && (cd->support_dual_chip_arch) &&
		(cd->support_vendor_ic_type == GT9897)) {
		cd->enter_stylus3_mmi_test = false;
		if (touch_driver_9x_bt_handler(tdev, false))
			thp_log_err(tdev->thp_core, "power on send stylus3 connect status fail\n");
	}

	if (touch_driver_get_afe_info(tdev))
		thp_log_err(tdev->thp_core, "%s: failed get afe addr info\n", __func__);
	return 0;
exit:
	kfree(private_data->goodix_spi_tx_buf);
	private_data->goodix_spi_tx_buf = NULL;
	if (tdev->thp_core->fast_booting_solution) {
		kfree(tdev->tx_buff);
		tdev->tx_buff = NULL;
		kfree(tdev->rx_buff);
		tdev->rx_buff = NULL;
		kfree(tdev);
		tdev = NULL;
	}
	return ret;
}

#pragma pack(1)
struct frame_head {
	u8 sync;
	u16 frame_index;
	u16 cur_frame_len;
	u16 nxt_frame_len;
	/* 0- 7 for pack_en; 8 - 31 for type en */
	u32 data_en;
	u8 touch_pack_index;
	u8 stylus_pack_index;
	u8 res;
	u16 checksum;
};
#pragma pack()
#define FRAME_HEAD_LEN 16
#define DEFAULT_FRAME_LEN 2500
#define FRAME_HEAD_LEN_GT9897S 16
#define FW_ATTR_INFO_LEN_GT9897S 22
#define FW_LOG_INFO_LEN_GT9897S 128
#define UDFP_DATA_LEN_GT9897S 68
#define UDFP_DATA_LEN_MIN 32
#define UDFP_TAIL_FRAME_INDEX 2
#define FW_LOG_OFFSET_GT9897S (FRAME_HEAD_LEN_GT9897S + \
	FW_ATTR_INFO_LEN_GT9897S)
#define UDFP_DATA_OFFSET_GT9897S (FRAME_HEAD_LEN_GT9897S + \
	FW_ATTR_INFO_LEN_GT9897S + FW_LOG_INFO_LEN_GT9897S)
#define CHECKSUM_SIZE_U16 2
#define CHECKSUM_SIZE_U32 4
#define SCREENOFF_FRAME_LEN_GT9897S  (FRAME_HEAD_LEN_GT9897S + \
	FW_ATTR_INFO_LEN_GT9897S + FW_LOG_INFO_LEN_GT9897S + \
	UDFP_DATA_LEN_GT9897S + UDFP_TAIL_FRAME_INDEX + CHECKSUM_SIZE_U32)
#define DEFAULT_FRAME_LEN_GT9897S 2300
#define UDFP_PACK_EN BIT(2)

static int touch_driver_get_next_frame_len(struct thp_device *tdev, u8 *buf)
{
	struct frame_head cur_head;
	static struct frame_head pre_head = { 0, 0, 0, FRAME_HEAD_LEN,
		FRAME_HEAD_LEN, 0, 0, 0, 0 };

	memcpy(&cur_head, buf, sizeof(cur_head));

	cur_head.frame_index = le16_to_cpu(cur_head.frame_index);
	cur_head.cur_frame_len = le16_to_cpu(cur_head.cur_frame_len);
	cur_head.nxt_frame_len = le16_to_cpu(cur_head.nxt_frame_len);
	cur_head.checksum = le16_to_cpu(cur_head.checksum);

	if (le16_data_check(buf, sizeof(cur_head))) {
		thp_log_err(tdev->thp_core, "frame head checksum erro\n");
		return pre_head.nxt_frame_len;
	}

	if ((cur_head.nxt_frame_len < sizeof(cur_head)) ||
		(cur_head.nxt_frame_len > THP_MAX_FRAME_SIZE)) {
		thp_log_err(tdev->thp_core, "next frame len invalid %d\n",
			cur_head.nxt_frame_len);
		return pre_head.nxt_frame_len;
	}

	pre_head = cur_head;
	return cur_head.nxt_frame_len;
}

#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
/*
 * set_udfp_state set udfp event monitor
 * @state: true for enable udfp event monitor,
 * false for disable.
 * return 0 for success.
 */
static int touch_driver_set_udfp_state(struct thp_device *tdev,
	u8 state)
{
	int ret;

	thp_log_info(tdev->thp_core, "%s: called state = %u\n", __func__, state);

	ret = touch_driver_switch_cmd(tdev, CMD_UDFP_EVENT_SWITCH_GT9897S,
		state, SEND_COMMAND_MULTIPLE_RETRY);
	if (!ret)
		gdix_set_mode.udfp_mode = state;
	else
		thp_log_err(tdev->thp_core, "%s failed enable udfp_mode\n", __func__);
	return ret;
}

/*
 * set_aod_state set aod event monitor
 * @state true for enable aod event monitor,
 * false for disable.
 * return 0 for success.
 */
static int touch_driver_set_aod_state(struct thp_device *tdev,
	u8 state, struct thp_aod_window window)
{
	return 0;
}

/*
 * set_lowpower_state set lowpower state
 * @state true for enter lowpower state,
 * false for exit.
 * return 0 for success
 */
static int touch_driver_set_lowpower_state(struct thp_device *tdev,
	u8 state)
{
	int ret;
	struct thp_core_data *cd = tdev->thp_core;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (cd->work_status != SUSPEND_DONE) {
		thp_log_info(tdev->thp_core, "%s: resumed, not handle lp\n", __func__);
		return NO_ERR;
	}
	thp_log_info(tdev->thp_core, "%s: called state = %u\n", __func__, state);
	if (gdix_set_mode.lowpower_mode == state) {
		thp_log_info(tdev->thp_core, "%s:don't repeat old status %u\n",
			__func__, state);
		return 0;
	}
	if ((state == 0) && cd->support_lowpower_no_irq && private_data->goodix_esd_status) {
		touch_driver_switch_cmd(tdev, 0xC0, ENABLE, SEND_COMMAND_MULTIPLE_RETRY);
		thp_log_err(tdev->thp_core, "status reset\n");
		msleep(200);
		ret = touch_driver_suspend_ap(tdev);
		private_data->goodix_esd_status = 0;
		return ret;
	}

	ret = touch_driver_switch_cmd(tdev, CMD_LOWPOWER_SWITCH_GT9897S,
		state, SEND_COMMAND_MULTIPLE_RETRY);
	if (!ret)
		gdix_set_mode.lowpower_mode = state;
	else
		thp_log_err(tdev->thp_core, "%s failed enable lowpower_mode\n", __func__);
	return ret;
}

/*
 * set_gesture_state set_set_gesture_state
 * @state 0 Disable Click Gesture
 * @touch_click
 * state  = 1
 * 0x01 : Single Click Gesture
 * 0x02 : Double Click Gesture
 * return 0 for success
 */
static int touch_driver_set_touch_gesture_state(
	struct thp_device *tdev, u8 state, u8 touch_click)
{
	int ret;

	thp_log_info(tdev->thp_core, "%s: called state = %u touch_click = %u\n",
		__func__, state, touch_click);
	if (!state)
		ret = touch_driver_switch_cmd(tdev,
			CMD_TOUCH_GESTURE_SWITCH_GT9897S, 0, SEND_COMMAND_MULTIPLE_RETRY);
	else
		ret = touch_driver_switch_cmd(tdev,
			CMD_TOUCH_GESTURE_SWITCH_GT9897S, touch_click,
			SEND_COMMAND_MULTIPLE_RETRY);
	if (!ret) {
		if (!state)
			gdix_set_mode.touch_gesture = 0;
		else
			gdix_set_mode.touch_gesture = touch_click;
	} else {
		thp_log_err(tdev->thp_core, "%s failed set touch_gesture\n", __func__);
	}
	return ret;
}

/*
 * goodix_recover_fw_state -goodix_recover_fw_state
 * @state: recover state
 */
static void touch_driver_recover_fw_state(struct thp_device *tdev)
{
	int ret;

	thp_log_info(tdev->thp_core, "%s called\n", __func__);

	/* 0 After fw reset ,resend shb cmd */
	ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
		CMD_SWITCH_INT_SH, SEND_COMMAND_RETRY);
	if (ret)
		thp_log_err(tdev->thp_core, "failed enable switch shb\n");
	/* After fw reset ,resend udfp cmd */
	if (gdix_set_mode.udfp_mode)
		touch_driver_set_udfp_state(tdev, gdix_set_mode.udfp_mode);
	if (gdix_set_mode.lowpower_mode)
		touch_driver_set_lowpower_state(tdev,
			gdix_set_mode.lowpower_mode);
	if (gdix_set_mode.touch_gesture)
		touch_driver_set_touch_gesture_state(tdev, ENABLE,
			gdix_set_mode.touch_gesture);
}

#ifdef CONFIG_ARCH_QTI_VM
static int goodix_touch_handler(struct thp_device *tdev, struct thp_udfp_data *udfp_data)
{
	int ret = 0;
	u8 rx_buf[100];
	u8 tx_buf[8] = {0};
	int touch_num;
	int i;
	u8 *coor_data;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	udfp_data->tpud_data.udfp_event = TP_FP_EVENT_MAX;
	if (tdev->thp_core->support_vendor_ic_type == GT9916)
		ret = touch_driver_spi_read(tdev, GOODIX_TUI_FRAME_ADDR_GT9916,
			rx_buf, sizeof(rx_buf));
	else if (tdev->thp_core->support_vendor_ic_type == GT9966)
		ret = touch_driver_spi_read(tdev, GOODIX_TUI_FRAME_ADDR_GT9966,
			rx_buf, sizeof(rx_buf));
	else
		thp_log_err(tdev->thp_core, "IC type is unknown\n");
	if (ret) {
		thp_log_err(tdev->thp_core, "read touch data failed\n");
		return ret;
	}

	if (tdev->thp_core->support_vendor_ic_type == GT9916)
		ret = touch_driver_spi_write(tdev, GOODIX_TUI_FRAME_ADDR_GT9916,
			tx_buf, sizeof(tx_buf));
	else if (tdev->thp_core->support_vendor_ic_type == GT9966)
		ret = touch_driver_spi_write(tdev, GOODIX_TUI_FRAME_ADDR_GT9966,
			tx_buf, sizeof(tx_buf));
	else
		thp_log_err(tdev->thp_core, "IC type is unknown\n");
	if (ret) {
		thp_log_err(tdev->thp_core, "write touch data failed, ret: %d\n", ret);
		return ret;
	}

	if (checksum_u8_cmp(rx_buf, 8)) {
		thp_log_err(tdev->thp_core, "touch head checksum err[%*ph]\n", 8, rx_buf);
		return -EINVAL;
	}

	if ((rx_buf[0] & 0x80) == 0) {
		thp_log_err(tdev->thp_core, "invalid event type[%x]\n", rx_buf[0]);
		return -EINVAL;
	}

	touch_num = rx_buf[2] & 0x0F;
	if (touch_num == 0) {/* release all fingers */
		if (private_data->tui_finger_last_status != TP_EVENT_FINGER_UP) {
			udfp_data->tpud_data.udfp_event = TP_EVENT_FINGER_UP;
			private_data->tui_finger_last_status = TP_EVENT_FINGER_UP;
		}
		return 0;
	} else {
		if (private_data->tui_finger_last_status != TP_EVENT_FINGER_DOWN) {
			udfp_data->tpud_data.udfp_event = TP_EVENT_FINGER_DOWN;
			private_data->tui_finger_last_status = TP_EVENT_FINGER_DOWN;
		}
	}

	ret = checksum_u8_cmp(&rx_buf[8], touch_num * 8 + 2);
	if (ret) {
		thp_log_err(tdev->thp_core, "touch data checksum err\n");
		return -EINVAL;
	}

	coor_data = &rx_buf[8];
	for (i = 0; i < touch_num; i++) {
		udfp_data->tpud_data.tp_x = le16_to_cpup((__le16 *)(coor_data + 2));
		udfp_data->tpud_data.tp_y = le16_to_cpup((__le16 *)(coor_data + 4));
		coor_data += 8;
	}

	return 0;
}
#endif

static int parse_event_info(struct thp_device *tdev, const u8 *read_buff, unsigned int len,
	struct thp_udfp_data *udfp_data)
{
	unsigned int tpfp_event[TP_FP_VALID_EVENT_NUM] = { TP_EVENT_FINGER_DOWN,
		TP_EVENT_FINGER_UP, TP_EVENT_HOVER_DOWN, TP_EVENT_HOVER_UP,
		TP_EVENT_FINGER_UP_QDB };
	int i;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (!read_buff || !udfp_data || (len == 0)) {
		thp_log_err(tdev->thp_core, "%s: data is NULL\n", __func__);
		return -EINVAL;
	}
	thp_log_info(tdev->thp_core, "%s: called\n", __func__);

	/* read_buff [0:3] = version */
	udfp_data->tpud_data.version = read_buff[0] +
		(read_buff[1] << MOVE_8BIT) + (read_buff[2] << MOVE_16BIT) +
		(read_buff[3] << MOVE_24BIT);
	/* read_buff [4:7] = udfp_event */
	udfp_data->tpud_data.udfp_event = read_buff[4] +
		(read_buff[5] << MOVE_8BIT) + (read_buff[6] << MOVE_16BIT) +
		(read_buff[7] << MOVE_24BIT);
	for (i = 0; i < TP_FP_VALID_EVENT_NUM; i++) {
		if ((udfp_data->tpud_data.udfp_event == tpfp_event[i]) &&
			private_data->thp_udfp_status)
			break;
	}
	if (i == TP_FP_VALID_EVENT_NUM)
		udfp_data->tpud_data.udfp_event = TP_FP_EVENT_MAX;
	/* read_buff [32:35]  = tp_x */
	udfp_data->tpud_data.tp_x = read_buff[32] +
		(read_buff[33] << MOVE_8BIT) + (read_buff[34] << MOVE_16BIT) +
		(read_buff[35] << MOVE_24BIT);
	/* read_buff [36:39]  = tp_y */
	udfp_data->tpud_data.tp_y = read_buff[36] +
		(read_buff[37] << MOVE_8BIT) + (read_buff[38] << MOVE_16BIT) +
		(read_buff[39] << MOVE_24BIT);
	/* read_buff [56:59]  = aod_event */
	udfp_data->aod_event = read_buff[56] + (read_buff[57] << MOVE_8BIT) +
		(read_buff[58] << MOVE_16BIT) + (read_buff[59] << MOVE_24BIT);
	/* read_buff [60:63]  = key_event */
	udfp_data->key_event = read_buff[60] + (read_buff[61] << MOVE_8BIT) +
		(read_buff[62] << MOVE_16BIT) + (read_buff[63] << MOVE_24BIT);
	thp_log_info(tdev->thp_core, "%s:version:%x, udfp_event:%d, aod:%u, key:%u\n",
		__func__, udfp_data->tpud_data.version,
		udfp_data->tpud_data.udfp_event, udfp_data->aod_event,
		udfp_data->key_event);
	if (udfp_data->key_event == DOUBLE_TAP_FLAG)
		udfp_data->key_event = TS_DOUBLE_CLICK;
	if (udfp_data->key_event == STYLUS_EVENT)
		udfp_data->key_event = TS_STYLUS_WAKEUP_TO_MEMO;
	return NO_ERR;
}

/*
 * touch_driver_get_event_info - get off screen event info
 * @buf used for store event data.
 * return 0 for success.
 */
static int touch_driver_get_event_info(struct thp_device *tdev,
	struct thp_udfp_data *udfp_data)
{
	u8 frame_buf[SCREENOFF_FRAME_LEN_GT9897S] = { 0 };
	struct frame_head *head_info = NULL;
	int ret;
	u8 i;
	u16 tail_index;
	u8 buf[UDFP_DATA_LEN_GT9897S + 1] = { 0 };
	struct thp_core_data *cd = tdev->thp_core;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

#ifdef CONFIG_ARCH_QTI_VM
	return goodix_touch_handler(tdev, udfp_data);
#endif

	if (!udfp_data) {
		thp_log_err(tdev->thp_core, "%s: udfp_data null\n", __func__);
		return -EINVAL;
	}
	if (cd->support_lowpower_no_irq && private_data->goodix_esd_status) {
		thp_log_err(tdev->thp_core, "%s: No processing in lowpower state\n", __func__);
		return -EFAULT;
	}
	ret = touch_driver_spi_read(tdev, private_data->goodix_frame_addr, frame_buf,
		SCREENOFF_FRAME_LEN_GT9897S);
	for (i = GOODIX_DEBUG_LEN_START; i < GOODIX_DEBUG_LEN_END; i = i + 8)
		thp_log_info(tdev->thp_core, "tp_info %d~%d: %x, %x, %x, %x, %x, %x, %x, %x\n",
			i - GOODIX_DEBUG_LEN_START,
			i - GOODIX_DEBUG_LEN_START + 7,
			frame_buf[i], frame_buf[i + 1],
			frame_buf[i + 2], frame_buf[i + 3],
			frame_buf[i + 4], frame_buf[i + 5],
			frame_buf[i + 6], frame_buf[i + 7]);
	/* frame_buf[22]: judge esd event bit[6] = 1: esd event */
	if (frame_buf[22] & (1 << 6)) {
		/* 0xC0: soft reset cmd */
		touch_driver_switch_cmd(tdev, 0xC0, ENABLE, SEND_COMMAND_MULTIPLE_RETRY);
		thp_log_err(tdev->thp_core, "esd_event\n");
		msleep(180);
		ret = touch_driver_suspend_ap(tdev);
		return ret;
	}
	if ((ret < 0) || le32_data_check(frame_buf, sizeof(frame_buf))) {
		thp_log_err(tdev->thp_core, "failed get valied frame data, %d,len %d",
			ret, sizeof(frame_buf));
		thp_log_info(tdev->thp_core, "fw_log:%*ph", FRAME_HEAD_LEN_GT9897S, frame_buf);
		tdev->thp_core->event_anomaly_count++;
		if (tdev->thp_core->event_anomaly_count > EVENT_ANOMALY_MAX_COUNT) {
			thp_log_err(tdev->thp_core, "event_anomaly_count++ %u, self recovery\n",
				tdev->thp_core->event_anomaly_count);
			tdev->thp_core->event_anomaly_count = 0;
			ret = touch_driver_suspend_ap(tdev);
		}
		return -EINVAL;
	}
	tail_index = (frame_buf[SCREENOFF_FRAME_LEN_GT9897S -
		CHECKSUM_SIZE_U32 - 1] << 8) |
	(frame_buf[SCREENOFF_FRAME_LEN_GT9897S - CHECKSUM_SIZE_U32 -
		UDFP_TAIL_FRAME_INDEX]);
	thp_log_info(tdev->thp_core, "tail frame index:%u\n", tail_index);

	head_info = (struct frame_head *)frame_buf;
	head_info->data_en = le32_to_cpu(head_info->data_en);
	if (!(head_info->data_en & UDFP_PACK_EN)) {
		thp_log_err(tdev->thp_core, "no udfp package 0x%x", head_info->data_en);
		touch_driver_recover_fw_state(tdev);
		return -EFAULT;
	}

	memcpy(buf, frame_buf + UDFP_DATA_OFFSET_GT9897S,
		UDFP_DATA_LEN_GT9897S);
	thp_log_info(tdev->thp_core, "udfp:%*ph", UDFP_DATA_LEN_MIN, buf);
	thp_log_info(tdev->thp_core, "udfp:%*ph", UDFP_DATA_LEN_GT9897S - UDFP_DATA_LEN_MIN,
		buf + UDFP_DATA_LEN_MIN);
	ret = parse_event_info(tdev, buf, UDFP_DATA_LEN_GT9897S + 1, udfp_data);
	if (ret) {
		thp_log_err(tdev->thp_core, "%s: parse_event_info fail\n", __func__);
		goto out;
	}
out:
	thp_log_info(tdev->thp_core, "%s end\n", __func__);
	return ret;
}
#endif

static int touch_driver_get_frame(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	int ret;
	static int frame_len = DEFAULT_FRAME_LEN;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (buf == NULL) {
		thp_log_info(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -ENOMEM;
	}

	if (!len) {
		thp_log_info(tdev->thp_core, "%s: read len illegal\n", __func__);
		return -ENOMEM;
	}

	if ((tdev->thp_core->support_vendor_ic_type == GT9897) &&
		(tdev->thp_core->support_dual_chip_arch)) {
		ret = touch_driver_spi_read(tdev, private_data->goodix_frame_addr, buf,
			frame_len);
		frame_len = touch_driver_get_next_frame_len(tdev, buf);
		return ret;
	}

	return touch_driver_spi_read(tdev, private_data->goodix_frame_addr, buf, len);
}

static int touch_driver_gesture_report(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value)
{
	int retval;

	thp_log_info(tdev->thp_core, "%s\n", __func__);

	if ((tdev->thp_core->support_vendor_ic_type == GT9897) &&
		(tdev->thp_core->support_dual_chip_arch))
		retval = touch_driver_gesture_event_for_gt9897_dual(tdev,
			gesture_wakeup_value);
	else if ((tdev->thp_core->support_vendor_ic_type == GT9897 ||
		tdev->thp_core->support_vendor_ic_type == GT9966 ||
		tdev->thp_core->support_vendor_ic_type == GT9916) &&
		tdev->thp_core->gesture_mode_double_tap)
		retval = touch_driver_gesture_event_9897(tdev,
			gesture_wakeup_value);
	else
		retval = touch_driver_gesture_event(tdev, gesture_wakeup_value);
	if (retval != 0) {
		thp_log_info(tdev->thp_core, "[%s] ->get event failed\n", __func__);
		return -EINVAL;
	}
	return 0;
}

static int touch_driver_tui_enable_switch(
	struct thp_device *tdev, u8 switch_value)
{
	int result;

	if (switch_value) {
		result = touch_driver_switch_cmd(tdev,
			CMD_TUI_GT9966, ENABLE_TUI, SEND_COMMAND_RETRY);
		if (result)
			thp_log_err(tdev->thp_core, "failed enable tui mode\n");
	} else {
		result =  touch_driver_switch_cmd(tdev,
			CMD_TUI_GT9966, DISABLE_TUI, SEND_COMMAND_RETRY);
		if (result)
			thp_log_err(tdev->thp_core, "failed disable tui mode\n");
	}

	thp_log_info(tdev->thp_core, "%s, send cmd to TP IC suc\n", __func__);
	return result;
}

static int touch_driver_wakeup_gesture_enable_switch(
	struct thp_device *tdev, u8 switch_value)
{
	int retval = NO_ERR;
	int result;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (switch_value) {
		result = touch_driver_switch_cmd(tdev,
			tdev->thp_core->cmd_gesture_mode, FEATURE_ENABLE,
			SEND_COMMAND_RETRY);
		if (result)
			thp_log_err(tdev->thp_core, "failed enable gesture mode\n");

		retval = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF,
				FEATURE_ENABLE, SEND_COMMAND_RETRY);
		if (result || retval) {
			thp_log_err(tdev->thp_core, "failed enable gesture mode\n");
		} else {
			private_data->work_status |= IC_STATUS_GESTURE;
			thp_log_info(tdev->thp_core, "enable gesture mode\n");
		}
	} else {
		retval =  touch_driver_switch_cmd(tdev,
			tdev->thp_core->cmd_gesture_mode, FEATURE_DISABLE,
			SEND_COMMAND_RETRY);
		if (retval) {
			thp_log_err(tdev->thp_core, "failed disable gesture mode\n");
		} else {
			thp_log_info(tdev->thp_core, "disable gesture mode\n");
			private_data->work_status &= ~IC_STATUS_GESTURE;
		}
	}

	thp_log_info(tdev->thp_core, "%s, write TP IC\n", __func__);
	return retval;
}

static int touch_driver_wakeup_gesture_enable_switch_9897(
	struct thp_device *tdev, u8 switch_value)
{
	int retval;
	int result;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (switch_value) {
		retval = touch_driver_switch_cmd(tdev,
			CMD_SCREEN_ON_OFF_9897, 1, SEND_COMMAND_RETRY);
		msleep(20); /* delay time 20ms */
		result = touch_driver_switch_cmd(tdev,
			tdev->thp_core->cmd_gesture_mode,
			GESTURE_CMD_SWITCH_GT9897, SEND_COMMAND_RETRY);
		if (!(result || retval)) {
			private_data->work_status |= IC_STATUS_GESTURE;
			thp_log_info(tdev->thp_core, "enable gesture mode\n");
			return retval;
		}
		thp_log_err(tdev->thp_core, "failed enable gesture mode\n");
		return -EINVAL;
	}
	retval = touch_driver_switch_cmd(tdev,
		tdev->thp_core->cmd_gesture_mode, FEATURE_DISABLE, SEND_COMMAND_RETRY);
	if (retval) {
		thp_log_err(tdev->thp_core, "failed disable gesture mode\n");
	} else {
		thp_log_info(tdev->thp_core, "disable gesture mode\n");
		private_data->work_status &= ~IC_STATUS_GESTURE;
	}
	return retval;
}

static int touch_driver_wrong_touch(struct thp_device *tdev)
{
	if (tdev->thp_core->support_gesture_mode) {
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		tdev->thp_core->easy_wakeup_info.off_motion_on = true;
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		thp_log_info(tdev->thp_core, "[%s] ->done\n", __func__);
	}
	return 0;
}

/* call this founction when TPIC in gesture mode
 *  return: if get valied gesture type 0 is returened
 */
#define GESTURE_EVENT_RETRY_TIME 10
static int touch_driver_gesture_event(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value)
{
	u8 sync_flag = 0;
	int retval;
	u16 gesture_type;
	u8 gesture_event_head[GESTURE_EVENT_HEAD_LEN + 1] = {0};
	int i;
	int result;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (!(private_data->work_status & IC_STATUS_GESTURE)) {
		thp_log_info(tdev->thp_core, "%s:please enable gesture mode first\n", __func__);
		retval = -EINVAL;
		goto err_out;
	}
	msleep(WAIT_FOR_SPI_BUS_RESUMED_DELAY);
	/* wait spi bus resume */
	for (i = 0; i < GESTURE_EVENT_RETRY_TIME; i++) {
		retval = touch_driver_spi_read(tdev, private_data->goodix_frame_addr,
				gesture_event_head, sizeof(gesture_event_head));
		if (retval == 0)
			break;
		thp_log_err(tdev->thp_core, "%s: spi not work normal, ret %d retry\n",
				__func__, retval);
		msleep(WAIT_FOR_SPI_BUS_READ_DELAY);
	}
	if (retval) {
		thp_log_err(tdev->thp_core, "%s: failed read gesture head info, ret %d\n",
			__func__, retval);
		return -EINVAL;
	}

	thp_log_info(tdev->thp_core, "gesute_data:%*ph\n", (u32)sizeof(gesture_event_head),
			gesture_event_head);
	if (gesture_event_head[0] != IRQ_EVENT_TYPE_GESTURE) {
		thp_log_err(tdev->thp_core, "%s: not gesture irq event, event_type 0x%x\n",
			__func__, gesture_event_head[0]);
		retval = -EINVAL;
		goto err_out;
	}

	if (checksum_16(tdev, gesture_event_head + 1, GESTURE_EVENT_HEAD_LEN)) {
		thp_log_err(tdev->thp_core, "gesture data checksum error\n");
		retval = -EINVAL;
		goto err_out;
	}

	gesture_type = (gesture_event_head[1] << MOVE_8BIT) +
			gesture_event_head[2];
	if (gesture_type == GESTURE_TYPE_DOUBLE_TAP) {
		thp_log_info(tdev->thp_core, "found valid gesture type\n");
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		if (tdev->thp_core->easy_wakeup_info.off_motion_on == true) {
			tdev->thp_core->easy_wakeup_info.off_motion_on = false;
			*gesture_wakeup_value = TS_DOUBLE_CLICK;
		}
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		retval = 0;
	} else {
		thp_log_err(tdev->thp_core, "found invalid gesture type:0x%x\n", gesture_type);
		retval = -EINVAL;
	}
	/* clean sync flag */
	if (touch_driver_spi_write(tdev, private_data->goodix_frame_addr, &sync_flag, 1))
		thp_log_err(tdev->thp_core, "%s: clean sync flag fail", __func__);
	return retval;

err_out:
	/* clean sync flag */
	if (touch_driver_spi_write(tdev, private_data->goodix_frame_addr, &sync_flag, 1))
		thp_log_err(tdev->thp_core, "%s: clean sync flag fail", __func__);
	/* resend gesture command */
	result = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF,
		FEATURE_ENABLE, SEND_COMMAND_RETRY);
	if (result)
		thp_log_err(tdev->thp_core, "resend SCREEN_ON_OFF command\n");

	retval = touch_driver_switch_cmd(tdev,
		tdev->thp_core->cmd_gesture_mode, FEATURE_ENABLE, SEND_COMMAND_RETRY);
	private_data->work_status |= IC_STATUS_GESTURE;
	if (result || retval)
		thp_log_err(tdev->thp_core, "resend gesture command\n");
	else
		thp_log_info(tdev->thp_core, "success resend gesture command\n");
	return -EINVAL;
}

static int touch_driver_gesture_event_9897(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value)
{
	u8 sync_flag;
	int retval;
	int i;
	u8 gesture_event_head[GESTURE_EVENT_HEAD_LEN] = {0};
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (!(private_data->work_status & IC_STATUS_GESTURE)) {
		thp_log_info(tdev->thp_core, "please enable gesture mode first\n");
		return -EINVAL;
	}
	msleep(WAIT_FOR_SPI_BUS_RESUMED_DELAY);
	/* wait spi bus resume */
	for (i = 0; i < GESTURE_EVENT_RETRY_TIME; i++) {
		retval = touch_driver_spi_read(tdev,
			GOODIX_GESTURE_CMD_ADDR_GT9897,
			gesture_event_head, sizeof(gesture_event_head));
		if (retval == 0)
			break;
		thp_log_err(tdev->thp_core, "spi work abnormal, retval = %d\n", retval);
		msleep(WAIT_FOR_SPI_BUS_READ_DELAY);
	}
	thp_log_info(tdev->thp_core, "gesture_data:%*ph\n", (u32)sizeof(gesture_event_head),
		gesture_event_head);
	if (!(gesture_event_head[0] & GESTURE_CMD_SWITCH_GT9897)) {
		thp_log_err(tdev->thp_core, "invalid type:0x%x\n", gesture_event_head[0]);
		return -EINVAL;
	}
	mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
	if (tdev->thp_core->easy_wakeup_info.off_motion_on == true) {
		tdev->thp_core->easy_wakeup_info.off_motion_on = false;
		*gesture_wakeup_value = TS_DOUBLE_CLICK;
	}
	mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
	sync_flag = gesture_event_head[0] & GESTURE_CMD_SWITCH_ACK_GT9897;
	thp_log_info(tdev->thp_core, "sync_flag:%x\n", sync_flag);
	retval = touch_driver_spi_write(tdev, GOODIX_GESTURE_CMD_ADDR_GT9897,
		&sync_flag, 1);
	return retval;
}

static int touch_driver_gesture_event_for_gt9897_dual(
	struct thp_device *tdev, unsigned int *gesture_wakeup_value)
{
	u8 sync_flag = 0;
	int retval;
	u16 gesture_type;
	u8 gesture_event_head[GESTURE_EVENT_HEAD_LEN_GT9897_DUAL] = {0};
	int i;
	int result;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (!(private_data->work_status & IC_STATUS_GESTURE)) {
		thp_log_err(tdev->thp_core, "please enable gesture mode first\n");
		retval = -EINVAL;
		goto err_out;
	}
	msleep(WAIT_FOR_SPI_BUS_RESUMED_DELAY);
	/* wait spi bus resume */
	for (i = 0; i < GESTURE_EVENT_RETRY_TIME; i++) {
		retval = touch_driver_spi_read(tdev, private_data->goodix_touch_addr,
			gesture_event_head, sizeof(gesture_event_head));
		if (retval == 0)
			break;
		thp_log_err(tdev->thp_core, "spi not work normal, ret %d retry\n", retval);
		msleep(WAIT_FOR_SPI_BUS_READ_DELAY);
	}
	if (retval) {
		thp_log_err(tdev->thp_core, "failed read gesture head info, ret %d\n", retval);
		return -EINVAL;
	}

	thp_log_info(tdev->thp_core, "gesute_data:%*ph\n", (u32)sizeof(gesture_event_head),
		gesture_event_head);
	if (gesture_event_head[0] != IRQ_EVENT_TYPE_GESTURE_GT9897_DUAL) {
		thp_log_err(tdev->thp_core, "not gesture irq event, event_type 0x%x\n",
			gesture_event_head[0]);
		retval = -EINVAL;
		goto err_out;
	}

	if (checksum32_cmp(tdev, gesture_event_head,
		GESTURE_EVENT_HEAD_LEN_GT9897_DUAL)) {
		thp_log_err(tdev->thp_core, "gesture data checksum error\n");
		retval = -EINVAL;
		goto err_out;
	}

	gesture_type = gesture_event_head[GESTURE_TYPE_VALUE_GT897_DUAL];
	if (gesture_type == GESTURE_TYPE_DOUBLE_TAP_GT9897_DUAL) {
		thp_log_info(tdev->thp_core, "found valid gesture type\n");
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		*gesture_wakeup_value = TS_DOUBLE_CLICK;
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		retval = 0;
	} else if (gesture_type == GESTURE_TYPE_PEN_SINGLE_TAP_GT9897_DUAL) {
		thp_log_info(tdev->thp_core, "found valid gesture type\n");
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		*gesture_wakeup_value = TS_STYLUS_WAKEUP_TO_MEMO;
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		retval = 0;
	} else {
		thp_log_err(tdev->thp_core, "found invalid gesture type:0x%x\n", gesture_type);
		retval = -EINVAL;
	}
	/* clean sync flag */
	if (touch_driver_spi_write(tdev, private_data->goodix_touch_addr, &sync_flag, 1))
		thp_log_err(tdev->thp_core, "clean sync flag fail\n");
	return retval;

err_out:
	/* clean sync flag */
	if (touch_driver_spi_write(tdev, private_data->goodix_touch_addr, &sync_flag, 1))
		thp_log_err(tdev->thp_core, "clean sync flag before resend gesture cmd fail\n");
	/* resend gesture command */
	result = touch_driver_switch_cmd(tdev,
		CMD_SCREEN_ON_OFF, FEATURE_ENABLE, SEND_COMMAND_RETRY);
	if (result)
		thp_log_err(tdev->thp_core, "resend SCREEN_ON_OFF command\n");

	retval = touch_driver_switch_cmd(tdev,
		tdev->thp_core->cmd_gesture_mode, FEATURE_ENABLE, SEND_COMMAND_RETRY);
	private_data->work_status |= IC_STATUS_GESTURE;
	if (result || retval)
		thp_log_err(tdev->thp_core, "resend gesture command\n");
	else
		thp_log_info(tdev->thp_core, "success resend gesture command\n");
	return -EINVAL;
}

static int touch_driver_resume_ap(struct thp_device *tdev)
{
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	thp_set_irq_status(tdev->thp_core, THP_IRQ_DISABLE);
#endif
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	mdelay(tdev->timing_config.resume_reset_after_delay_ms);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
#if !(IS_ENABLED(CONFIG_HONOR_THP_MTK))
	thp_set_irq_status(tdev->thp_core, THP_IRQ_ENABLE);
#endif
	return 0;
}

#ifdef CONFIG_HONOR_SHB_THP
#define NEED_RESET 1
static int touch_driver_resume_shb(struct thp_device *tdev)
{
	int ret;

	if ((!tdev->thp_core) || (!tdev->gpios)) {
		thp_log_err(tdev->thp_core, "%s: have null ptr\n", __func__);
		return -EINVAL;
	}
	if (tdev->thp_core->need_resume_reset == NEED_RESET) {
		gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
		mdelay(tdev->timing_config.resume_reset_after_delay_ms);
		gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
		thp_log_info(tdev->thp_core, "%s:reset when resume\n", __func__);
		return 0;
	}
	if (tdev->thp_core->support_vendor_ic_type == GT9897 ||
		tdev->thp_core->support_vendor_ic_type == GT9966 ||
		tdev->thp_core->support_vendor_ic_type == GT9916)
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN_GT9897,
			CMD_SWITCH_INT_AP, SEND_COMMAND_RETRY);
	else
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_AP, SEND_COMMAND_RETRY);
	if (ret) {
		thp_log_err(tdev->thp_core, "%s:touch_driver_switch_cmd send err, ret = %d\n",
			__func__, ret);
		return ret;
	}
	thp_log_info(tdev->thp_core, "%s:touch_driver_switch_cmd send: switch int ap\n",
		__func__);
	return ret;
}
#endif

static int touch_driver_resume(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

#if IS_ENABLED(CONFIG_HONOR_THP_QCOM)
	gdix_set_mode.lowpower_mode = 0;
#endif

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#endif

	cd = tdev->thp_core;
	thp_log_info(tdev->thp_core, "%s, ic_type %d\n", __func__,
		tdev->thp_core->support_vendor_ic_type);
	tdev->thp_core->event_anomaly_count = 0;
	private_data->goodix_esd_status = 0;
	/* if pt mode, we should reset */
	if (is_pt_test_mode(tdev)) {
		ret = touch_driver_resume_ap(tdev);
		if (tdev->thp_core->support_vendor_ic_type == GT9896)
			thp_do_time_delay(
				tdev->timing_config.boot_reset_after_delay_ms);
		thp_log_info(tdev->thp_core, "%s:pt mode called end\n", __func__);
		return ret;
	}
	if (private_data->thp_udfp_status ||
		(tdev->thp_core->easy_wakeup_info.sleep_mode ==
		TS_GESTURE_MODE) || private_data->stylus_gesture_status ||
		(private_data->aod_touch_status && !cd->talk_mode_flag) ||
		private_data->goodix_ring_setting_switch) {
#ifdef CONFIG_HONOR_SHB_THP
		if (tdev->thp_core->support_shb_thp)
			ret = touch_driver_resume_shb(tdev);
		else
#endif
			ret = touch_driver_resume_ap(tdev);
		thp_log_info(tdev->thp_core, "%s: called end\n", __func__);
		return ret;
	}
	if (tdev->thp_core->support_vendor_ic_type == GT9896)
		ret = touch_driver_power_on_for_9896(tdev);
	else if (tdev->thp_core->support_vendor_ic_type == GT9897)
		ret = touch_driver_power_on_for_9897(tdev);
	else if (tdev->thp_core->support_vendor_ic_type == GT9966 ||
		tdev->thp_core->support_vendor_ic_type == GT9916)
		ret = touch_driver_power_on_for_9966(tdev);
	else
		ret = touch_driver_power_on(tdev);
	thp_log_info(tdev->thp_core, "%s: called end\n", __func__);
	return ret;
}

static int touch_driver_after_resume(struct thp_device *tdev)
{
	int ret = 0;
	struct thp_core_data *cd = tdev->thp_core;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#else
	thp_log_info(tdev->thp_core, "%s: called\n", __func__);
#endif

	if ((cd->send_bt_status_to_fw) && (cd->support_dual_chip_arch) &&
		(cd->support_vendor_ic_type == GT9897)) {
		ret = touch_driver_9x_bt_handler(tdev, false);
		if (ret) {
			thp_log_err(tdev->thp_core, "power on send stylus3 connect status fail\n");
			ret = -EINVAL;
		}
		return ret;
	}

	thp_do_time_delay(tdev->timing_config.boot_reset_after_delay_ms);
	if (!private_data->thp_udfp_status && !is_pt_test_mode(tdev)) {
		/* Turn off sensorhub report when
		 * fingerprintud  isn't in work state.
		 */
		ret = touch_driver_switch_cmd(tdev, CMD_TOUCH_REPORT, 0,
			SEND_COMMAND_RETRY);
		if (ret)
			thp_log_err(tdev->thp_core, "failed send CMD_TOUCH_REPORT mode\n");
	}

	return ret;
}

static int send_stylus3_status_to_fw(struct thp_device *tdev,
	u8 *bt_status_buf, u8 check_status_data)
{
	int i;
	int ret;
	u8 check_value;

	thp_log_info(tdev->thp_core, "check_status_data = %d\n", check_status_data);
	for (i = 0; i < BT_CONNECT_CMD_RETRY; i++) {
		ret = touch_driver_spi_write(tdev,
			BT_CONNECT_STATUS_ADDR,
			bt_status_buf, BT_CONNECT_STATUS_BUF_LEN);
		if (ret)
			continue;
		msleep(BT_AFTER_WRITE_CMD_DELAY);

		ret = touch_driver_spi_read(tdev,
			BT_CONNECT_STATUS_CHECK_ADDR,
			&check_value, BT_CHECK_DATA_LEN);
		if (ret)
			continue;

		if (check_status_data == check_value)
			break;
	}

	if (i == BT_CONNECT_CMD_RETRY)
		ret = -EINVAL;

	return ret;
}

static int touch_driver_9x_bt_handler(struct thp_device *tdev,
	bool delay_enable)
{
	int ret;
	unsigned int stylus3_status;
	u8 bt_connect_value;
	u8 bt_connect_buf[BT_CONNECT_STATUS_BUF_LEN] = {0, 0,
		BT_CONNECT_BUF2, BT_CONNECT_BUF3, BT_CONNECT_BUF4,
		BT_CONNECT_BUF5, 0};
	u8 bt_disconnect_buf[BT_CONNECT_STATUS_BUF_LEN] = {0, 0,
		BT_DISCONNECT_BUF2, BT_DISCONNECT_BUF3, 0,
		BT_DISCONNECT_BUF5, 0};
	u8 *bt_status_buf_addr = NULL;

	stylus3_status = atomic_read(&tdev->thp_core->last_stylus3_status);

	if (delay_enable == true)
		msleep(SEND_BT_CONNECT_STATUS_AFTER_RESET_DELAY);

	if (stylus3_status > 0) {
		bt_status_buf_addr = bt_connect_buf;
		bt_connect_value = BT_CONNECT_VALUE;
	} else {
		bt_status_buf_addr = bt_disconnect_buf;
		bt_connect_value = BT_DISCONNECT_VALUE;
	}

	ret = send_stylus3_status_to_fw(tdev,
		bt_status_buf_addr, bt_connect_value);
	if (ret) {
		thp_log_err(tdev->thp_core, "%s: send stylus3 status to fw fail\n", __func__);
		return ret;
	}
	thp_log_info(tdev->thp_core, "%s: status: %d, check data is: %d\n",
		__func__, stylus3_status, bt_connect_value);

	return ret;
}

#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
static int touch_driver_set_ap_state(struct thp_device *tdev)
{
	int ret = 0;
	struct thp_core_data *cd = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	cd = tdev->thp_core;
	if (tdev->thp_core->easy_wakeup_info.sleep_mode ==
		TS_GESTURE_MODE) {
		ret = touch_driver_set_touch_gesture_state(tdev,
			ENABLE, CMD_GESTURE_DOUBLE);
		if (ret)
			thp_log_err(tdev->thp_core, "failed to set_touch_gesture\n");
	}
	if (private_data->thp_udfp_status) {
		ret = touch_driver_set_udfp_state(tdev, ENABLE);
		if (ret)
			thp_log_err(tdev->thp_core, "failed to set_udfp\n");
	}
	if (cd->aod_touch_status) {
		ret = touch_driver_switch_cmd(tdev,
			CMD_AOD_EVENT_SWITCH_GT9897S, ENABLE, SEND_COMMAND_MULTIPLE_RETRY);
		if (ret)
			thp_log_err(tdev->thp_core, "failed to aod\n");
	}
	return ret;
}
#endif

static int touch_driver_suspend_ap(struct thp_device *tdev)
{
	int ret;
	struct goodix_device_info *private_data =
		(struct goodix_device_info *)tdev->private_data;

	if ((tdev->thp_core->support_vendor_ic_type == GT9897 ||
		tdev->thp_core->support_vendor_ic_type == GT9966 ||
		tdev->thp_core->support_vendor_ic_type == GT9916) &&
		tdev->thp_core->gesture_mode_double_tap)
		ret = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF_9897, 1,
			SEND_COMMAND_MULTIPLE_RETRY);
	else
		ret = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF, 1,
			SEND_COMMAND_MULTIPLE_RETRY);
	if (ret)
		thp_log_err(tdev->thp_core, "failed to screen_on off\n");
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
	if (tdev->thp_core->use_ap_gesture) {
		if (private_data->stylus_gesture_status_only &&
			!thp_get_status(tdev->thp_core, THP_STATUS_STYLUS3)) {
			ret = touch_driver_switch_cmd(tdev,
				CMD_LOWPOWER_SWITCH_GT9966,
				ENABLE_LP, SEND_COMMAND_MULTIPLE_RETRY);
			private_data->stylus_gesture_status_lowpower = true;
			thp_log_info(tdev->thp_core, "instant write enable only set lowpower state\n");
			return ret;
		}
		ret = touch_driver_set_ap_state(tdev);
		if (ret)
			thp_log_err(tdev->thp_core, "failed to set ap state\n");
		return ret;
	}
#endif
	if (tdev->thp_core->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) {
		thp_log_info(tdev->thp_core, "%s TS_GESTURE_MODE\n", __func__);
		if ((tdev->thp_core->support_vendor_ic_type == GT9897 ||
			tdev->thp_core->support_vendor_ic_type == GT9966 ||
			tdev->thp_core->support_vendor_ic_type == GT9916) &&
			tdev->thp_core->gesture_mode_double_tap)
			ret = touch_driver_wakeup_gesture_enable_switch_9897(
				tdev, FEATURE_ENABLE);
		else
			ret = touch_driver_wakeup_gesture_enable_switch(tdev,
				FEATURE_ENABLE);
		if (ret)
			thp_log_err(tdev->thp_core, "failed to wakeup gesture enable\n");
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		tdev->thp_core->easy_wakeup_info.off_motion_on = true;
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
	}
#ifdef CONFIG_HONOR_SHB_THP
struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	if (tdev->thp_core->tsa_event_to_udfp && private_data->thp_udfp_status) {
		mdelay(10);
		ret = send_tp_ap_event(sizeof(private_data->thp_udfp_status),
			(void *)&private_data->thp_udfp_status,
			ST_CMD_TYPE_FINGERPRINT_SWITCH);
	}
#endif
	return ret;
}

#ifdef CONFIG_HONOR_SHB_THP
static int touch_driver_suspend_shb(struct thp_device *tdev)
{
	int ret;

	if (tdev->thp_core->support_vendor_ic_type == GT9897 ||
		tdev->thp_core->support_vendor_ic_type == GT9966 ||
		tdev->thp_core->support_vendor_ic_type == GT9916)
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN_GT9897,
			CMD_SWITCH_INT_SH, SEND_COMMAND_RETRY);
	else
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_SH, SEND_COMMAND_RETRY);
	if (ret) {
		thp_log_err(tdev->thp_core, "%s:touch_driver_switch_cmd send err, ret = %d\n",
			__func__, ret);
		return ret;
	}
	thp_log_info(tdev->thp_core, "%s:touch_driver_switch_cmd send: switch int shb\n",
		__func__);
	return ret;
}

#define INPUTHUB_POWER_SWITCH_START_BIT 9
#define INPUTHUB_POWER_SWITCH_START_OFFSET 1
static void touch_driver_poweroff_status(void)
{
	struct thp_core_data *cd = thp_get_core_data();
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	cd->poweroff_function_status =
		((cd->double_click_switch << THP_DOUBLE_CLICK_ON) |
		(private_data->thp_udfp_status << THP_TPUD_ON) |
		(cd->ring_setting_switch << THP_RING_SUPPORT) |
		(cd->ring_switch << THP_RING_ON) |
		(private_data->goodix_stylus_status << THP_PEN_MODE_ON) |
		(cd->phone_status << THP_PHONE_STATUS) |
		(cd->single_click_switch << THP_SINGLE_CLICK_ON) |
		(cd->volume_side_status << THP_VOLUME_SIDE_STATUS_LEFT));
	if (cd->aod_display_support)
		cd->poweroff_function_status |=
		(cd->aod_touch_status << THP_AOD_TOUCH_STATUS);
	if ((cd->power_switch >= POWER_KEY_OFF_CTRL) &&
		(cd->power_switch < POWER_MAX_STATUS))
	/*
	 * cd->poweroff_function_status 0~8 bit saved function flag
	 * eg:double_click, finger_status, ring_switch,and so on.
	 * cd->poweroff_function_status 9~16 bit saved screen-on-off reason flag
	 * cd->power_switch is a value(1~8) which stand for screen-on-off reason
	 */
		cd->poweroff_function_status |=
			(1 << (INPUTHUB_POWER_SWITCH_START_BIT +
			cd->power_switch - INPUTHUB_POWER_SWITCH_START_OFFSET));
}
#endif

static int touch_driver_suspend(struct thp_device *tdev)
{
	int ret = 0;
	struct thp_core_data *cd = NULL;
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;
	unsigned int stylus3_status;

	if (tdev->thp_core == NULL) {
		thp_log_err(tdev->thp_core, "%s: invalid input\n", __func__);
		return -EINVAL;
	}

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(tdev->thp_core, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#endif

	cd = tdev->thp_core;
	private_data->thp_udfp_status = thp_get_status(cd, THP_STATUS_UDFP);
	private_data->stylus_gesture_status = cd->stylus_gesture_status;
	private_data->aod_touch_status = cd->aod_touch_status;
	private_data->stylus_gesture_status_only = (!private_data->thp_udfp_status &&
		!private_data->aod_touch_status &&
		!cd->easy_wakeup_info.sleep_mode &&
		private_data->stylus_gesture_status);
	if ((cd->support_vendor_ic_type == GT9897) &&
		(cd->support_dual_chip_arch) &&
		(cd->easy_wakeup_info.sleep_mode == TS_POWER_OFF_MODE))
		private_data->goodix_stylus_status = FEATURE_DISABLE;
	private_data->goodix_ring_setting_switch = cd->ring_setting_switch;
	thp_log_info(tdev->thp_core, "%s:gesture_status:%d,finger_status:%u\n",
		__func__, cd->easy_wakeup_info.sleep_mode, private_data->thp_udfp_status);
	thp_log_info(tdev->thp_core,
		"%s:ring_support:%u,ring_switch:%u,phone_status:%u,ring_setting_switch:%u\n",
		__func__, cd->support_ring_feature, cd->ring_switch,
		cd->phone_status, private_data->goodix_ring_setting_switch);
	thp_log_info(tdev->thp_core, "%s:stylus_status:%u,aod_touch_status:%u, talk_mode_flag:%u\n",
		__func__, private_data->stylus_gesture_status, cd->aod_touch_status, cd->talk_mode_flag);
	stylus3_status = atomic_read(&tdev->thp_core->last_stylus3_status);
	if (cd->support_gesture_mode) {
		if ((stylus3_status > 0) && (cd->stylus_gesture_status == 0)) {
			ret = touch_driver_switch_cmd(tdev, PEN_SWITCH, STYLUS_CLOSE, SEND_COMMAND_RETRY);
			if (ret)
				thp_log_err(tdev->thp_core, "%s:close pen failed,ret = %d\n", __func__, ret);
		}
	}
	if (is_pt_test_mode(tdev)) {
		thp_log_info(tdev->thp_core, "%s: suspend PT mode\n", __func__);
		if (cd->support_vendor_ic_type == GT9966) {
			ret = touch_driver_switch_cmd(tdev,
				CMD_PT_OUT_IDLE, PT_MODE, SEND_COMMAND_RETRY);
			if (!ret)
				msleep(30);
		}
		if (cd->support_vendor_ic_type == GT9897 ||
			cd->support_vendor_ic_type == GT9966 ||
			cd->support_vendor_ic_type == GT9916)
			ret = touch_driver_switch_cmd(tdev,
				CMD_PT_MODE_GT9897, PT_MODE, SEND_COMMAND_RETRY);
		else
			ret = touch_driver_switch_cmd(tdev,
				CMD_PT_MODE, PT_MODE, SEND_COMMAND_RETRY);
		if (ret)
			thp_log_err(tdev->thp_core, "failed enable PT mode\n");
	} else if (private_data->thp_udfp_status || private_data->goodix_ring_setting_switch ||
		(cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) ||
		private_data->stylus_gesture_status || (cd->aod_touch_status && !cd->talk_mode_flag)) {
		if (cd->support_shb_thp) {
#ifdef CONFIG_HONOR_SHB_THP
			touch_driver_poweroff_status();
			ret = touch_driver_suspend_shb(tdev);
#endif
		} else {
			ret = touch_driver_suspend_ap(tdev);
		}
	} else {
		if (tdev->thp_core->support_shb_thp)
			/* 0:all function was closed */
			tdev->thp_core->poweroff_function_status = 0;
		ret = touch_driver_power_off(tdev);
		thp_log_info(tdev->thp_core, "enter poweroff mode: ret = %d\n", ret);
	}
	thp_log_info(tdev->thp_core, "%s: called end\n", __func__);
	return ret;
}

static void touch_driver_get_oem_info(struct thp_device *tdev,
	const char *buff)
{
	struct thp_core_data *cd = tdev->thp_core;
	char lcd_effect_flag;
	int ret;

	if ((!buff) || (!tdev->thp_core)) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return;
	}
	if (tdev->thp_core->support_oem_info == THP_OEM_INFO_LCD_EFFECT_TYPE) {
		/* The 12th byte is lcd_effect_flag, and 0xaa is valid */
		lcd_effect_flag = buff[GOODIX_LCD_EFFECT_FLAG_POSITION - 1];
		memset(cd->oem_info_data, 0, sizeof(cd->oem_info_data));
		ret = snprintf(cd->oem_info_data, OEM_INFO_DATA_LENGTH,
			"0x%x", lcd_effect_flag);
		if (ret < 0)
			thp_log_info(tdev->thp_core, "%s:snprintf error\n", __func__);
		thp_log_info(tdev->thp_core, "%s:lcd effect flag :%s\n", __func__,
			cd->oem_info_data);
		return;
	}
	thp_log_info(tdev->thp_core, "%s:not support oem info\n", __func__);
}

static int touch_driver_is_valid_project_id(const char *id)
{
	int i;

	if (id == NULL)
		return false;
	for (i = 0; i < THP_PROJECT_ID_LEN; i++) {
		if (!isascii(*id) || !isalnum(*id))
			return false;
		id++;
	}
	return true;
}

static int touch_driver_get_project_id_for_989x(struct thp_device *tdev,
	unsigned int addr, char *buf, unsigned int len)
{
	char proj_id[THP_PROJECT_ID_LEN + 1] = {0};
	int ret;
	struct thp_core_data *cd = NULL;

	cd = tdev->thp_core;
	ret = touch_driver_spi_read(tdev, addr, proj_id, THP_PROJECT_ID_LEN);
	if (ret) {
		thp_log_err(tdev->thp_core, "%s:Project_id Read ERR\n", __func__);
		return -EIO;
	}
	proj_id[THP_PROJECT_ID_LEN] = '\0';

	if (touch_driver_is_valid_project_id(proj_id)) {
		strncpy(buf, proj_id, len);
	} else {
		thp_log_err(tdev->thp_core, "%s:get project id fail\n", __func__);
		if (cd->project_id_dummy) {
			thp_log_err(tdev->thp_core, "%s:use dummy prj id\n", __func__);
			strncpy(buf, cd->project_id_dummy, len);
			return 0;
		}
		return -EIO;
	}
	thp_log_info(tdev->thp_core, "%s call end\n", __func__);
	return 0;
}

static int touch_driver_get_project_id(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	int retry;
	char proj_id[GOODIX_CUSTOME_INFO_LEN + 1] = {0};
	int ret;
	struct thp_core_data *cd = NULL;

	if (buf == NULL) {
		thp_log_err(tdev->thp_core, "%s: have null pointer\n", __func__);
		return -EINVAL;
	}

#ifdef CONFIG_ARCH_QTI_VM
	thp_log_debug(cd, "%s: called in QTVM, do nothing\n", __func__);
	return 0;
#endif

	cd = tdev->thp_core;
	if (cd->support_vendor_ic_type == GT9896)
		return touch_driver_get_project_id_for_989x(tdev,
			GOODIX_PROJECT_ID_ADDR_GT9896, buf, len);
	else if (cd->support_vendor_ic_type == GT9897)
		return touch_driver_get_project_id_for_989x(tdev,
			GOODIX_PROJECT_ID_ADDR_GT9897, buf, len);
	else if (cd->support_vendor_ic_type == GT9966 ||
			cd->support_vendor_ic_type == GT9916)
		return touch_driver_get_project_id_for_989x(tdev,
			GOODIX_PROJECT_ID_ADDR_GT9966, buf, len);

	for (retry = 0; retry < GOODIX_GET_PROJECT_ID_RETRY; retry++) {
		ret = touch_driver_spi_read(tdev, GOODIX_PROJECT_ID_ADDR,
			proj_id, GOODIX_CUSTOME_INFO_LEN);
		if (ret) {
			thp_log_err(tdev->thp_core, "Project_id Read ERR\n");
			return -EIO;
		}

		if (!checksum_u8(proj_id, GOODIX_CUSTOME_INFO_LEN)) {
			proj_id[THP_PROJECT_ID_LEN] = '\0';
			if (!is_valid_project_id(proj_id)) {
				thp_log_err(tdev->thp_core, "get project id fail\n");
				return -EIO;
			}
			strncpy(buf, proj_id, len);
			thp_log_info(tdev->thp_core, "%s:get project id:%s\n", __func__, buf);
			touch_driver_get_oem_info(tdev, proj_id);
			return 0;
		}
		thp_log_err(tdev->thp_core, "%s:get project id fail, retry\n", __func__);
		mdelay(GOODIX_GET_PROJECT_RETRY_DELAY_10MS);
	}

	return -EIO;
}

static int touch_driver_suspend_connect_pen(struct thp_device *tdev)
{
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;
	int ret;

	if (private_data->stylus_gesture_status_lowpower) {
		ret = touch_driver_switch_cmd(tdev,
			CMD_LOWPOWER_SWITCH_GT9966,
			DISABLE_LP, SEND_COMMAND_MULTIPLE_RETRY);
		if (ret) {
			thp_log_err(tdev->thp_core, "%s:disable lowpower failed\n", __func__);
			return ret;
		}
		private_data->stylus_gesture_status_lowpower = false;
	}
	ret = touch_driver_switch_cmd(
		tdev, PEN_SWITCH, STYLUS_OPEN,
		SEND_COMMAND_RETRY);
	return ret;
}

static void touch_driver_exit(struct thp_device *tdev)
{
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	thp_log_info(tdev->thp_core, "%s: called\n", __func__);
	kfree(tdev->tx_buff);
	kfree(tdev->rx_buff);
	kfree(tdev);
	kfree(private_data->goodix_spi_tx_buf);
	private_data->goodix_spi_tx_buf = NULL;
}

static int touch_driver_afe_notify_callback(struct thp_device *tdev,
	unsigned long event)
{
	return touch_driver_get_afe_info(tdev);
}

#define GOODIX_SPI_ACTIVE_DELAY 1000
int touch_driver_spi_active(struct thp_device *tdev)
{
	int ret;
	u8 wake_flag = IDLE_WAKE_FLAG;

	ret = thp_set_spi_max_speed(tdev->thp_core, IDLE_SPI_SPEED);
	if (ret) {
		thp_log_err(tdev->thp_core, "failed set spi speed to %dHz, ret %d\n",
			IDLE_SPI_SPEED, ret);
		return ret;
	}

	ret = touch_driver_spi_write(tdev, 0, &wake_flag, sizeof(wake_flag));
	if (ret)
		thp_log_err(tdev->thp_core, "failed write wakeup flag %x, ret %d",
				wake_flag, ret);
	thp_log_info(tdev->thp_core, "[%s] tdev->sdev->max_speed_hz-> %d\n", __func__,
			tdev->sdev->max_speed_hz);

	ret = thp_set_spi_max_speed(tdev->thp_core, ACTIVE_SPI_SPEED);
	if (ret) {
		thp_log_err(tdev->thp_core, "failed reset speed to %dHz, ret %d\n",
			tdev->sdev->max_speed_hz, ret);
		return ret;
	}

	udelay(GOODIX_SPI_ACTIVE_DELAY);
	return ret;
}

#define FW_STAUTE_DATA_MASK  0x04
#define FW_STAUTE_DATA_FLAG  0xAA
static int touch_driver_idle_wakeup(struct thp_device *tdev)
{
	int ret;
	int i;
	u8 fw_status_data[MAX_FW_STATUS_DATA_LEN] = {0};
	struct goodix_device_info *private_data = (struct goodix_device_info *)tdev->private_data;

	thp_log_debug(tdev->thp_core, "%s\n", __func__);

	if (!private_data->goodix_fw_status_addr || !private_data->goodix_fw_status_len ||
		private_data->goodix_fw_status_len > MAX_FW_STATUS_DATA_LEN) {
		thp_log_err(tdev->thp_core, "%s: invalid fw status reg, length: %d\n",
			__func__, private_data->goodix_fw_status_len);
		return 0;
	}
	ret = touch_driver_spi_read(tdev, private_data->goodix_fw_status_addr,
		fw_status_data, private_data->goodix_fw_status_len);
	if (ret) {
		thp_log_err(tdev->thp_core, "failed read fw status info data, ret %d\n", ret);
		return -EIO;
	}

	if (!checksum_16(tdev, fw_status_data, private_data->goodix_fw_status_len) &&
		!(fw_status_data[0] & FW_STAUTE_DATA_MASK) &&
		(fw_status_data[private_data->goodix_fw_status_len - 3] ==
			FW_STAUTE_DATA_FLAG))
		return 0;

	thp_log_debug(tdev->thp_core, "fw status data:%*ph\n",
			private_data->goodix_fw_status_len, fw_status_data);
	thp_log_debug(tdev->thp_core, "need do spi wakeup\n");
	for (i = 0; i < SPI_WAKEUP_RETRY; i++) {
		ret = touch_driver_spi_active(tdev);
		if (ret) {
			thp_log_debug(tdev->thp_core, "failed write spi active flag, ret %d\n",
				ret);
			continue;
		}
		/* recheck spi state */
		ret = touch_driver_spi_read(tdev, private_data->goodix_fw_status_addr,
			fw_status_data, private_data->goodix_fw_status_len);
		if (ret) {
			thp_log_err(tdev->thp_core,
				"[recheck]failed read fw status info data, ret %d\n",
				ret);
			continue;
		}

		if (!checksum_16(tdev, fw_status_data, private_data->goodix_fw_status_len) &&
			!(fw_status_data[0] & FW_STAUTE_DATA_MASK) &&
			(fw_status_data[private_data->goodix_fw_status_len - 3] ==
				FW_STAUTE_DATA_FLAG))
			return 0;

		thp_log_debug(tdev->thp_core, "fw status data:%*ph\n",
			private_data->goodix_fw_status_len, fw_status_data);
		thp_log_debug(tdev->thp_core, "failed wakeup form idle retry %d\n", i);
	}
	return -EIO;
}

#ifdef CONFIG_HONOR_SHB_THP
static int touch_driver_switch_int_sh(struct thp_device *tdev)
{
	int retval;

	thp_log_info(tdev->thp_core, "%s: called\n", __func__);
	if (tdev->thp_core->support_vendor_ic_type == GT9897 ||
		tdev->thp_core->support_vendor_ic_type == GT9966 ||
		tdev->thp_core->support_vendor_ic_type == GT9916)
		retval = touch_driver_switch_cmd(tdev,
			CMD_SWITCH_INT_PIN_GT9897,
			CMD_SWITCH_INT_SH, SEND_COMMAND_RETRY);
	else
		retval = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_SH, SEND_COMMAND_RETRY);
	if (retval != 0) {
		thp_log_info(tdev->thp_core, "%s: switch int to shb failed\n", __func__);
		return -EINVAL;
	}
	return 0;
}

static int touch_driver_switch_int_ap(struct thp_device *tdev)
{
	int retval;

	thp_log_info(tdev->thp_core, "%s: called\n", __func__);
	if (tdev->thp_core->support_vendor_ic_type == GT9897 ||
		tdev->thp_core->support_vendor_ic_type == GT9966 ||
		tdev->thp_core->support_vendor_ic_type == GT9916)
		retval = touch_driver_switch_cmd(tdev,
			CMD_SWITCH_INT_PIN_GT9897,
			CMD_SWITCH_INT_AP, SEND_COMMAND_RETRY);
	else
		retval = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_AP, SEND_COMMAND_RETRY);
	if (retval != 0) {
		thp_log_info(tdev->thp_core, "%s: switch int to ap failed\n", __func__);
		return -EINVAL;
	}
	return 0;
}
#endif

struct thp_device_ops goodix_dev_ops = {
	.init = touch_driver_init,
	.detect = touch_driver_chip_detect,
	.get_frame = touch_driver_get_frame,
	.resume = touch_driver_resume,
	.after_resume = touch_driver_after_resume,
	.suspend = touch_driver_suspend,
	.get_project_id = touch_driver_get_project_id,
	.exit = touch_driver_exit,
	.afe_notify = touch_driver_afe_notify_callback,
	.chip_wakeup_gesture_enable_switch =
		touch_driver_wakeup_gesture_enable_switch,
	.tui_enable_switch = touch_driver_tui_enable_switch,
	.chip_wrong_touch = touch_driver_wrong_touch,
	.chip_gesture_report = touch_driver_gesture_report,
	//.bt_handler = touch_driver_9x_bt_handler,
#ifdef CONFIG_HONOR_SHB_THP
	.switch_int_sh = touch_driver_switch_int_sh,
	.switch_int_ap = touch_driver_switch_int_ap,
#endif
#if (IS_ENABLED(CONFIG_HONOR_THP_QCOM) || IS_ENABLED(CONFIG_HONOR_THP_MTK))
	.get_event_info = touch_driver_get_event_info,
	.tp_lowpower_ctrl = touch_driver_set_lowpower_state,
	.tp_aod_event_ctrl = touch_driver_set_aod_state,
	.suspend_connect_pen = touch_driver_suspend_connect_pen,
#endif

};

int goodix_driver_module_init(struct thp_core_data *cd)
{
	int rc;
	struct thp_device *dev = kzalloc(sizeof(struct thp_device), GFP_KERNEL);
	struct goodix_device_info *device_info = kzalloc(sizeof(struct goodix_device_info), GFP_KERNEL);
	int len;

	thp_log_debug(cd, "%s: called\n", __func__);
	if (dev == NULL) {
		thp_log_err(cd, "%s: thp device malloc fail\n", __func__);
		return -ENOMEM;
	}
	if (device_info == NULL) {
		thp_log_err(cd, "%s: goodix device info malloc fail\n", __func__);
		return -ENOMEM;
	}
	len = sizeof(struct goodix_device_info);
	memset(device_info, 0, len);
	dev->private_data = device_info;

	dev->tx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	dev->rx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	if ((dev->tx_buff == NULL) || (dev->rx_buff == NULL)) {
		thp_log_err(cd, "%s: out of memory\n", __func__);
		rc = -ENOMEM;
		goto err;
	}

	dev->ic_name = GOODIX_IC_NAME;
	dev->dev_node_name = THP_GOODIX_DEV_NODE_NAME;
	dev->ops = &goodix_dev_ops;
	if (cd && cd->fast_booting_solution) {
		thp_send_detect_cmd(cd, dev, NO_SYNC_TIMEOUT);
		/*
		 * The thp_register_dev will be called later to complete
		 * the real detect action.If it fails, the detect function will
		 * release the resources requested here.
		 */
		return 0;
	}
	rc = thp_register_dev(cd, dev);
	if (rc) {
		thp_log_err(cd, "%s: register fail\n", __func__);
		goto err;
	}

	return rc;
err:
	kfree(dev->tx_buff);
	dev->tx_buff = NULL;
	kfree(dev->rx_buff);
	dev->rx_buff = NULL;
	kfree(dev);
	dev = NULL;
	kfree(device_info);
	device_info = NULL;
	return rc;
}
