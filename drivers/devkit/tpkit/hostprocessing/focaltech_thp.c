/*
 * Thp driver code for focaltech
 *
 * Copyright (c) 2012-2050 Huawei Technologies Co., Ltd.
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
#include "huawei_thp.h"

#define FOCALTECH_IC_NAME "focaltech"
#define THP_FOCALTECH_DEV_NODE_NAME "focaltech"

#define DEFAULT_TOUCH_PANEL 0
#define DATA_HEAD 0x3F
#define DATA_MASK 0xFF
#define COMOND_HEAD 0xC0
#define COMOND_READ_ONE 0x81
#define COMOND_WRITE_ONE 0x01
#define COMOND_ADDR_RESET 0x55
#define COMMOND_READ_DATA 0x3A
#define COMOND_ADDR_DETECT 0x90
#define CHIP_DETECT_FAILE_ONE 0x00
#define CHIP_DETECT_FAILE_TWO 0xFF
#define CHIP_DETECT_FAILE_THR 0xEF
#define CHIP_DETECT_RETRY_NUMB 3
#define DELAY_AFTER_FIRST_BYTE 30

#define FTS_IC_NAME_LEN 2
#define FTS_PRODUCT_NAME_LEN 4
#define FTS_READ_CMD 0xA0
#define FTS_WRITE_CMD 0x00
#define SPI_DUMMY_BYTE 0x07
#define DATA_CRC_EN 0x20
#define CRC_REG_VALUE 0xFFFF
#define CRC_CHECK_BIT_SIZE 8
#define CRC_CHECK_CODE 0x8408
#define CRC_BUF_MIN_SIZE 2
#define CRC_LOW_BIT_CHECK 0x01
#define CRC_BIT_CHECK 1
#define ADDR_OFFSET 0x02
#define ADDR_RAWDATA 0x01
#define ADDR_FRAME 0x3A
#define DELAY8_AFTER_RST 8
#define GET_HIGH_BIT 8
#define SPI_RETRY_NUMBER 3
#define CS_HIGH_DELAY 150
#define FTS_REG_GESTURE_EN 0xD0
#define FTS_REG_GESTURE_DATA 0xD3
#define FTS_REG_LEN 1
#define FTS_OFF_STS 3
#define FTS_GESTURE_DATA_LEN 30
#define FTS_GESTURE_STR_LEN_MAX 152
#define FTS_GESTURE_ID_BIT 2
#define FTS_GESTURE_ID_VALUE 0x24
#define FTS_GESTURE_STYLUS_ID_VALUE 0x25
#define GESTURE_DATA_ENABLE 1
#define GESTURE_INFO_BIT 3
#define GESTURE_INFO_VALUE 0x80
#define BT_CONNECT_CMD_RETRY 3
#define STYLUS3_CONNECT 2
#define FTS_REG_BT 0xC5
#define SLEEP_RETRY_NUM 3
#define SLEEP_BUF_BIT 3
#define SPI_INDEX 2
/*
 * Here we use "fts_ic_type" to identify focal ICs' types:
 * 1.FT8615_SERIES includes ft8615 and ft8719,
 * and "support_vendor_ic_type" is 0 in dts.
 * 2.FT8720_SERIES includes ft8720 and ft8009,
 * but ft8009 has some differences in ecc and get_frame command,
 * and this series should config "support_vendor_ic_type" to 1.
 * 3.The future focal ic almost belongs to FT8720_SERIES,
 * so we have to config the "support_vendor_ic_type" to 1 in dts.
 */
enum fts_ic_type {
	FT8615_SERIES,
	FT8720_SERIES = 1,
};

enum fts_gesture_event {
	FTS_DOUBLE_CLICK_WAKEUP_EVENT,
	FTS_STYLUS_WAKEUP_TO_MEMO_EVENT = 1,
};

enum fts_stylus_status_cmd {
	FTS_STYLUS_CMD_DISCONNECT = 0,
	FTS_STYLUS_CMD_CONNECT = 1,
};

static bool is_ic_ft8009;

/* spi interface */
static int touch_driver_spi_transfer(const char *tx_buf,
	char *rx_buf, unsigned int len)
{
	int rc;

	struct thp_core_data *cd = thp_get_core_data(DEFAULT_TOUCH_PANEL);
	struct spi_device *sdev = cd->sdev;
	struct spi_message msg;
	struct spi_transfer xfer1 = {
		.tx_buf = tx_buf,
		.rx_buf = rx_buf,
		.len = len,
	};
	struct spi_transfer xfer[SPI_INDEX];

	if (cd->suspended && (!cd->need_work_in_suspend) &&
		(!((cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) &&
		cd->support_gesture_mode)))
		return 0;

	if (cd->support_vendor_ic_type == FT8720_SERIES) {
		spi_message_init(&msg);
		spi_message_add_tail(&xfer1, &msg);
	} else {
		memset(xfer, 0, sizeof(xfer));

		spi_message_init(&msg);
		xfer[0].tx_buf = &tx_buf[0];
		if (rx_buf)
			xfer[0].rx_buf = &rx_buf[0];
		xfer[0].len = 1;
		xfer[0].delay_usecs = DELAY_AFTER_FIRST_BYTE;
		spi_message_add_tail(&xfer[0], &msg);
		if (len > 1) {
			xfer[1].tx_buf = &tx_buf[1];
			if (rx_buf)
				xfer[1].rx_buf = &rx_buf[1];
			xfer[1].len = len - 1;
			spi_message_add_tail(&xfer[1], &msg);
		}
	}

	mutex_lock(&cd->spi_mutex);
	if (!cd->not_support_cs_control)
		thp_spi_cs_set(GPIO_HIGH);
	rc = spi_sync(sdev, &msg);
	mutex_unlock(&cd->spi_mutex);

	return rc;
}

static int touch_driver_hardware_reset_to_rom(struct thp_device *tdev)
{
	int rc;
	int index = 0;
	unsigned char cmd[3]; /* 3 byte once */

	if (!tdev) {
		thp_log_info("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	/* reset */
	gpio_direction_output(tdev->gpios->rst_gpio, THP_RESET_LOW);
	thp_do_time_delay(tdev->timing_config.boot_reset_low_delay_ms);

	gpio_set_value(tdev->gpios->rst_gpio, THP_RESET_HIGH);
	thp_do_time_delay(tdev->timing_config.boot_reset_hi_delay_ms);

	mdelay(8); /* 8ms sequence delay */

	cmd[index++] = COMOND_HEAD;
	cmd[index++] = COMOND_WRITE_ONE;
	cmd[index++] = COMOND_ADDR_RESET;
	rc = touch_driver_spi_transfer(cmd, cmd, ARRAY_SIZE(cmd));
	if (rc) {
		thp_log_err("%s:write 0x55 command fail\n", __func__);
		return rc;
	}

	mdelay(8); /* 8ms sequence delay */
	return 0;
}

static int touch_driver_hardware_reset_to_rom_new(struct thp_device *tdev)
{
	int rc;
	int index = 0;
	unsigned char cmd[4] = { 0x0 }; /* 4 byte once */

	/* reset */
#ifndef CONFIG_HUAWEI_THP_MTK
	gpio_direction_output(tdev->gpios->rst_gpio, THP_RESET_LOW);
	thp_do_time_delay(tdev->timing_config.boot_reset_low_delay_ms);
	gpio_set_value(tdev->gpios->rst_gpio, THP_RESET_HIGH);
	thp_do_time_delay(tdev->timing_config.boot_reset_hi_delay_ms);
#else
	if (tdev->thp_core->support_pinctrl == 0) {
		thp_log_info("%s: not support pinctrl\n", __func__);
		return -EINVAL;
	}
	pinctrl_select_state(tdev->thp_core->pctrl,
		tdev->thp_core->mtk_pinctrl.reset_low);
	thp_do_time_delay(tdev->timing_config.boot_reset_low_delay_ms);
	pinctrl_select_state(tdev->thp_core->pctrl,
		tdev->thp_core->mtk_pinctrl.reset_high);
	thp_do_time_delay(tdev->timing_config.boot_reset_hi_delay_ms);
#endif
	mdelay(DELAY8_AFTER_RST);

	cmd[index++] = COMOND_ADDR_RESET;
	cmd[index++] = FTS_WRITE_CMD;
	cmd[index++] = 0x00; /* high bit */
	cmd[index++] = 0x00; /* low bit */
	rc = touch_driver_spi_transfer(cmd, cmd, ARRAY_SIZE(cmd));
	if (rc) {
		thp_log_err("%s:write 0x55 command fail\n", __func__);
		return rc;
	}
	mdelay(DELAY8_AFTER_RST);
	return 0;
}

static u8 cal_ecc_xor8(u8 *buf, u16 buflen)
{
	u16 i;
	u8 result = 0;

	for (i = 0; i < buflen; i++)
		result ^= buf[i];

	return result;
}

static int rdata_crc_check(u8 *rdata, u16 rlen)
{
	u16 i;
	u16 j;
	u16 crc_read;
	u16 crc_calc = CRC_REG_VALUE;

	if (rdata == NULL) {
		thp_log_err("%s: rdata is NULL\n", __func__);
		return -EIO;
	}
	if (rlen < CRC_BUF_MIN_SIZE) {
		thp_log_err("%s: thp_check_frame_valid buf less than 2: %d\n",
			__func__, rlen);
		return -EIO;
	}
	for (i = 0; i < (rlen - CRC_BUF_MIN_SIZE); i++) {
		crc_calc ^= rdata[i];
		for (j = 0; j < CRC_CHECK_BIT_SIZE; j++) {
			if (crc_calc & CRC_LOW_BIT_CHECK)
				crc_calc = (crc_calc >> CRC_BIT_CHECK) ^
					CRC_CHECK_CODE;
			else
				crc_calc = (crc_calc >> CRC_BIT_CHECK);
		}
	}
	/* rlen - 1 is to get the last element of rdata array */
	crc_read = (u16)(rdata[rlen - 1] << CRC_CHECK_BIT_SIZE) +
		rdata[rlen - CRC_BUF_MIN_SIZE];
	if (crc_calc != crc_read) {
		thp_log_err("%s: ecc fail:cal %x != buf %x\n",
			__func__, crc_calc, crc_read);
		return -EIO;
	}
	return 0;
}

static int touch_driver_check_frame_valid(u8 *buf, u16 len)
{
	u16 ecc_buf;
	u16 ecc_cal;
	struct thp_core_data *cd = thp_get_core_data(DEFAULT_TOUCH_PANEL);

	if ((cd->support_vendor_ic_type == FT8720_SERIES) && (!is_ic_ft8009))
		return rdata_crc_check(buf, len + ADDR_OFFSET);
	if (len < 2) {
		thp_log_err("%s: buf len < 2 %d\n", __func__, len);
		return -EIO;
	}
	ecc_cal = (u16)cal_ecc_xor8(buf, len - 2);
	ecc_buf = (u16)((buf[len - 2] << 8) + buf[len - 1]);
	if (ecc_cal != ecc_buf) {
		thp_log_err("ecc fail:cal(%x) != buf(%x)\n", ecc_cal, ecc_buf);
		return -EIO;
	}

	return 0;
}

static void touch_driver_projectid_to_ic_type(struct thp_core_data *cd)
{
	char temp_buf[FTS_IC_NAME_LEN + 1] = {0};

	strncpy(temp_buf, cd->project_id + FTS_PRODUCT_NAME_LEN,
		FTS_IC_NAME_LEN);
	if (!strncmp("9D", temp_buf, FTS_IC_NAME_LEN)) {
		is_ic_ft8009 = true;
		cd->support_vendor_ic_type = FT8720_SERIES;
		cd->spi_config.mode = 0;
		cd->sdev->mode = 0;
		thp_log_info("%s: ic is 9D, spi reconfiged\n", __func__);
	}
}

static int thp_parse_extra_config(struct device_node *thp_node,
	struct thp_core_data *cd)
{
	int rc;
	unsigned int value = 0;

	if (!thp_node || !cd) {
		thp_log_info("%s: input null\n", __func__);
		return -ENODEV;
	}
	rc = of_property_read_u32(thp_node, "reset_status_in_suspend_mode",
		&value);
	if (!rc) {
		cd->reset_status_in_suspend_mode = value;
		thp_log_info("%s: reset_status_in_suspend_mode %u\n",
			__func__, value);
	}

	cd->fts_gesture_no_offset = 0;
	rc = of_property_read_u32(thp_node, "fts_gesture_no_offset", &value);
	if (!rc) {
		cd->fts_gesture_no_offset = value;
		thp_log_info("%s: gesture no offset %u\n", __func__, value);
	}
	return 0;
}

static int touch_driver_init(struct thp_device *tdev)
{
	struct thp_core_data *cd = NULL;
	struct device_node *fts_node = NULL;

	thp_log_info("%s: called\n", __func__);
	if (!tdev) {
		thp_log_info("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	cd = tdev->thp_core;
	fts_node = of_get_child_by_name(cd->thp_node,
						THP_FOCALTECH_DEV_NODE_NAME);
	if (!fts_node) {
		thp_log_info("%s: dev not config in dts\n",
				__func__);
		return -ENODEV;
	}

	if (thp_parse_spi_config(fts_node, cd))
		thp_log_err("%s: spi config parse fail\n",
			__func__);

	if (thp_parse_timing_config(fts_node, &tdev->timing_config))
		thp_log_err("%s: timing config parse fail\n",
			__func__);

	if (thp_parse_feature_config(fts_node, cd))
		thp_log_err("%s: feature_config fail\n", __func__);
	if (thp_parse_extra_config(fts_node, cd))
		thp_log_err("%s: extra_config fail\n", __func__);

	touch_driver_projectid_to_ic_type(cd);

	return 0;
}

/* free tdev and buffers */
static void touch_driver_dev_free(struct thp_device *tdev)
{
	thp_log_info("%s: called\n", __func__);
	if (tdev != NULL) {
		if (tdev->rx_buff != NULL) {
			kfree(tdev->rx_buff);
			tdev->rx_buff = NULL;
		}
		if (tdev->tx_buff != NULL) {
			kfree(tdev->tx_buff);
			tdev->tx_buff = NULL;
		}
		kfree(tdev);
		tdev = NULL;
	}
}

static void touch_driver_chip_detect_exit(struct thp_device *tdev)
{
	if (tdev->thp_core->fast_booting_solution)
		touch_driver_dev_free(tdev);
}

static int touch_driver_bt_handler(struct thp_device *tdev, bool delay_enable);

static void touch_driver_stylus_connect_in_power(struct thp_device *tdev)
{
	if (tdev->thp_core->send_bt_status_to_fw)
		if (touch_driver_bt_handler(tdev, true))
			thp_log_err("power on send stylus3 connect status fail\n");
}

static int touch_driver_chip_detect(struct thp_device *tdev)
{
	int rc;
	int i;
	unsigned char cmd[3]; /* 3 bytes once */
	/* 20 bytes for spi transfer */
	unsigned char cmd1[20] = {0};
	u32 txlen = 0;

	if (!tdev) {
		thp_log_info("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	for (i = 0; i < CHIP_DETECT_RETRY_NUMB; i++) {
		if (tdev->thp_core->support_vendor_ic_type == FT8720_SERIES) {
			rc = touch_driver_hardware_reset_to_rom_new(tdev);
			if (rc) {
				thp_log_err("%s:write 0x55 command fail\n",
					__func__);
				continue;
			}

			cmd1[txlen++] = COMOND_ADDR_DETECT;
			cmd1[txlen++] = FTS_READ_CMD;
			cmd1[txlen++] = 0x00; /* high bit */
			cmd1[txlen++] = 0x02; /* low bit */
			txlen = SPI_DUMMY_BYTE + ADDR_OFFSET;
			if (FTS_READ_CMD & DATA_CRC_EN)
				txlen = txlen + ADDR_OFFSET;

			rc = touch_driver_spi_transfer(cmd1, cmd1, txlen);
			if (rc) {
				thp_log_err("%s:write 0x90 command fail\n",
					__func__);
				goto exit;
			}

			if ((cmd1[SPI_DUMMY_BYTE] == CHIP_DETECT_FAILE_ONE) ||
			    (cmd1[SPI_DUMMY_BYTE] == CHIP_DETECT_FAILE_TWO) ||
			    (cmd1[SPI_DUMMY_BYTE] == CHIP_DETECT_FAILE_THR)) {
				thp_log_err(
					"%s:chip id read fail, ret=%d, i=%d, data=%x\n",
					__func__, rc, i, cmd1[SPI_DUMMY_BYTE]);
			} else {
				thp_log_info(
					"%s:chip id read success, chip id:0x%X,0x%X\n",
					__func__, cmd1[SPI_DUMMY_BYTE],
					cmd1[SPI_DUMMY_BYTE + 1]);
				touch_driver_stylus_connect_in_power(tdev);
				return 0;
			}
			/* Delay 50ms to retry if reading ic id failed */
			msleep(50);
		} else {
			rc = touch_driver_hardware_reset_to_rom(tdev);
			if (rc) {
				thp_log_err("%s:write 0x55 command fail\n",
					__func__);
				continue;
			}

			cmd[0] = COMOND_HEAD;
			cmd[1] = COMOND_READ_ONE;
			cmd[2] = COMOND_ADDR_DETECT;
			rc = touch_driver_spi_transfer(cmd, cmd,
				ARRAY_SIZE(cmd));
			if (rc) {
				thp_log_err("%s:write 0x90 command fail\n",
					__func__);
				goto exit;
			}
			msleep(10); /* 10ms sequential */

			cmd[0] = DATA_HEAD;
			cmd[1] = DATA_MASK;
			cmd[2] = DATA_MASK;
			rc = touch_driver_spi_transfer(cmd, cmd,
				ARRAY_SIZE(cmd));
			if (rc) {
				thp_log_err("%s:read 0x90 data fail\n",
					__func__);
				goto exit;
			}

			if ((cmd[1] == CHIP_DETECT_FAILE_ONE) ||
				(cmd[1] == CHIP_DETECT_FAILE_TWO) ||
				(cmd[1] == CHIP_DETECT_FAILE_THR)) {
				thp_log_err("%s:chip id read fail\n",
					__func__);
				thp_log_err("ret=%d, i=%d, data=%x\n",
					rc, i, cmd[1]);
			} else {
				thp_log_info("%s:chip id read success\n",
					__func__);
				thp_log_info("chip id:0x%X%X\n",
					cmd[1], cmd[2]); /* cmd[2] data mask */
				return 0;
			}
			msleep(50); /* 50ms sequential */
		}
	}
exit:
	touch_driver_chip_detect_exit(tdev);

	return -EIO;
}

static int touch_driver_get_frame(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	int ret;
	unsigned char *w_buf = NULL;
	unsigned char *r_buf = NULL;
	u32 txlen = 0;

	if (!tdev) {
		thp_log_info("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	if (!tdev->tx_buff || !tdev->rx_buff) {
		thp_log_err("%s: out of memory\n", __func__);
		return -ENOMEM;
	}
	if (!buf) {
		thp_log_info("%s: input buf null\n", __func__);
		return -ENOMEM;
	}

	if ((!len) || (len >= THP_MAX_FRAME_SIZE - 1)) {
		thp_log_info("%s: read len: %u illegal\n", __func__, len);
		return -ENOMEM;
	}

	w_buf = tdev->tx_buff;
	r_buf = tdev->rx_buff;
	memset(tdev->tx_buff, 0xFF, THP_MAX_FRAME_SIZE);
	memset(tdev->rx_buff, 0, THP_MAX_FRAME_SIZE);

	if (tdev->thp_core->support_vendor_ic_type == FT8720_SERIES) {
		w_buf[txlen++] = is_ic_ft8009 ? ADDR_RAWDATA : ADDR_FRAME;
		w_buf[txlen++] = FTS_READ_CMD;
		w_buf[txlen++] = (len >> 8) & 0xFF; /* get high 8 bit */
		w_buf[txlen++] = len & 0xFF; /* get low 8 bit */
		txlen = SPI_DUMMY_BYTE + len;
		txlen = txlen + ADDR_OFFSET;

		ret = touch_driver_spi_transfer(w_buf, r_buf, txlen);
		if (ret < 0) {
			thp_log_err("spi transfer fail\n");
			return ret;
		}

		ret = touch_driver_check_frame_valid(r_buf +
						SPI_DUMMY_BYTE,
						txlen - SPI_DUMMY_BYTE -
						ADDR_OFFSET);
		if (ret < 0) {
			ret = touch_driver_spi_transfer(w_buf, r_buf, txlen);
			if (ret < 0) {
				thp_log_err("spi transfer fail\n");
				return ret;
			}
		}
		memcpy(buf, r_buf + SPI_DUMMY_BYTE, len);
	} else {
		w_buf[0] = COMMOND_READ_DATA;
		ret = touch_driver_spi_transfer(w_buf, r_buf, len + 1);
		if (ret < 0) {
			thp_log_err("spi transfer fail\n");
			return ret;
		}
		ret = touch_driver_check_frame_valid(r_buf + 1, len);
		if (ret < 0) {
			ret = touch_driver_spi_transfer(w_buf, r_buf, len + 1);
			if (ret < 0) {
				thp_log_err("spi transfer fail\n");
				return ret;
			}
		}
		memcpy(buf, r_buf + 1, len);
	}
	return 0;
}

static void touch_driver_power_on_cs(struct thp_device *tdev)
{
	if (!tdev->thp_core->not_support_cs_control)
		gpio_set_value(tdev->gpios->cs_gpio, GPIO_HIGH);
#ifdef CONFIG_HUAWEI_THP_QCOM
	if (tdev->thp_core->support_control_cs_off &&
		(!IS_ERR_OR_NULL(tdev->thp_core->qcom_pinctrl.cs_high))) {
		pinctrl_select_state(tdev->thp_core->pctrl, tdev->thp_core->qcom_pinctrl.cs_high);
		thp_log_info("%s: cs to high\n", __func__);
	}
#endif
}

static void touch_driver_power_off_cs(struct thp_device *tdev)
{
	if (!tdev->thp_core->not_support_cs_control)
		gpio_set_value(tdev->gpios->cs_gpio, GPIO_LOW);
#ifdef CONFIG_HUAWEI_THP_QCOM
	if (tdev->thp_core->support_control_cs_off &&
		(!IS_ERR_OR_NULL(tdev->thp_core->qcom_pinctrl.cs_low))) {
		pinctrl_select_state(tdev->thp_core->pctrl, tdev->thp_core->qcom_pinctrl.cs_low);
		thp_log_info("%s: cs to low\n", __func__);
	}
#endif
}

static int touch_driver_resume(struct thp_device *tdev)
{
	thp_log_info("%s: called\n", __func__);
	if (!tdev) {
		thp_log_info("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
#ifndef CONFIG_HUAWEI_THP_MTK
	touch_driver_power_on_cs(tdev);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
#else
	if (tdev->thp_core->support_pinctrl == 0) {
		thp_log_info("%s: not support pinctrl\n", __func__);
		return -EINVAL;
	}
	pinctrl_select_state(tdev->thp_core->pctrl,
		tdev->thp_core->mtk_pinctrl.cs_high);
	if (tdev->thp_core->reset_status_in_suspend_mode)
		thp_log_info("%s: reset retains high\n", __func__);
	else
		pinctrl_select_state(tdev->thp_core->pctrl,
			tdev->thp_core->mtk_pinctrl.reset_high);
#endif
	thp_do_time_delay(tdev->timing_config.resume_reset_after_delay_ms);

	return 0;
}

static int touch_driver_wrong_touch(struct thp_device *tdev)
{
	if ((!tdev) || (!tdev->thp_core)) {
		thp_log_err("%s: input dev is null\n", __func__);
		return -EINVAL;
	}

	if (tdev->thp_core->support_gesture_mode) {
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		tdev->thp_core->easy_wakeup_info.off_motion_on = true;
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		thp_log_info("%s, done\n", __func__);
	}
	return 0;
}

static int touch_driver_send_fw_cmd(struct thp_device *tdev, enum fts_stylus_status_cmd value)
{
	int i;
	int ret;
	unsigned char w_buf[SPI_DUMMY_BYTE + FTS_REG_LEN];
	unsigned char r_buf[SPI_DUMMY_BYTE + FTS_REG_LEN];
	u32 index = 0;
	u32 txlen;

	thp_log_info("%s: called; value: %d\n", __func__, value);
	w_buf[index++] = FTS_REG_BT;
	w_buf[index++] = FTS_WRITE_CMD;
	w_buf[index++] = 0x00;
	w_buf[index++] = 0x01;
	txlen = SPI_DUMMY_BYTE + FTS_REG_LEN;
	w_buf[SPI_DUMMY_BYTE] = value;

	for (i = 0; i < SPI_RETRY_NUMBER; i++) {
		ret = touch_driver_spi_transfer(w_buf, r_buf, txlen);
		if ((ret == 0) && ((r_buf[FTS_OFF_STS] & FTS_READ_CMD) == 0))
			break;

		thp_log_info("data write addr:%x,status:%x,retry:%d,ret:%d",
			FTS_REG_BT, r_buf[FTS_OFF_STS], i, ret);
		ret = -EIO;
		udelay(CS_HIGH_DELAY);
	}
	if (ret < 0)
		thp_log_err("data write addr:%x fail,status:%x,ret:%d",
			FTS_REG_BT, r_buf[FTS_OFF_STS], ret);

	return ret;
}

static int touch_driver_bt_handler(struct thp_device *tdev,
	bool delay_enable)
{
	unsigned int stylus3_status;
	int i;
	int ret;

	stylus3_status = atomic_read(&tdev->thp_core->last_stylus3_status);

	thp_log_info("%s enter, delay_enable = %d, stylus3_status = %d\n",
		__func__, delay_enable, stylus3_status);
	for (i = 0; i < BT_CONNECT_CMD_RETRY; i++) {
		if ((stylus3_status & STYLUS3_CONNECT) == STYLUS3_CONNECT)
			ret = touch_driver_send_fw_cmd(tdev, FTS_STYLUS_CMD_CONNECT);
		else
			ret = touch_driver_send_fw_cmd(tdev, FTS_STYLUS_CMD_DISCONNECT);

		if (!ret)
			break;
	}
	if (i == BT_CONNECT_CMD_RETRY) {
		thp_log_err("%s, send stylus status fail, retry = %d\n", __func__, i);
		ret = -EINVAL;
	}

	return ret;
}

static void touch_driver_enter_gesture_mode(struct thp_device *tdev)
{
	int i;
	int ret;
	unsigned char w_buf[SPI_DUMMY_BYTE + FTS_REG_LEN];
	unsigned char r_buf[SPI_DUMMY_BYTE + FTS_REG_LEN];
	u32 index = 0;
	u32 txlen;

	thp_log_info("%s: called\n", __func__);
	w_buf[index++] = FTS_REG_GESTURE_EN;
	w_buf[index++] = FTS_WRITE_CMD;
	w_buf[index++] = (FTS_REG_LEN >> GET_HIGH_BIT) & 0xFF;
	w_buf[index++] = FTS_REG_LEN & 0xFF;
	txlen = SPI_DUMMY_BYTE + FTS_REG_LEN;
	w_buf[SPI_DUMMY_BYTE] = GESTURE_DATA_ENABLE;

	for (i = 0; i < SPI_RETRY_NUMBER; i++) {
		ret = touch_driver_spi_transfer(w_buf, r_buf, txlen);
		if ((ret == 0) && ((r_buf[FTS_OFF_STS] & FTS_READ_CMD) == 0))
			break;
		thp_log_info("data write addr:%x,status:%x,retry:%d,ret:%d",
			FTS_REG_GESTURE_EN, r_buf[FTS_OFF_STS], i, ret);
		ret = -EIO;
		udelay(CS_HIGH_DELAY);
	}
	if (ret < 0)
		thp_log_err("data write addr:%x fail,status:%x,ret:%d",
			FTS_REG_GESTURE_EN, r_buf[FTS_OFF_STS], ret);
	mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
	tdev->thp_core->easy_wakeup_info.off_motion_on = true;
	mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
}

static void parse_gesture_info(u8 *gesture_buffer)
{
	int cnt = 0;
	char str[FTS_GESTURE_STR_LEN_MAX];
	int str_len_max = FTS_GESTURE_STR_LEN_MAX;
	int i;

	if ((gesture_buffer[GESTURE_INFO_BIT] & GESTURE_INFO_VALUE) ==
		GESTURE_INFO_VALUE) {
		for (i = 0; i < FTS_GESTURE_DATA_LEN; i++)
			cnt += snprintf(str + cnt, str_len_max - cnt, "%02X ",
				gesture_buffer[i]);
		thp_log_info("%s: %s\n", __func__, str);
	}
}

static int touch_driver_gesture_data_identify(unsigned char *gesture_data)
{
	int offset_bit;
	int gesture_data_val = 0;
	struct thp_core_data *cd = thp_get_core_data(DEFAULT_TOUCH_PANEL);

	/*
	 * distinguish historical projects. fts_gesture_no_offset is
	 * 0: Inndicates the historical item logic. Use gesture_data[2] to determine the gesture function value.
	 * 1: Use gesture_data[0] to determine the gesture function value.
	 */
	if (cd->fts_gesture_no_offset) {
		offset_bit = 0;
	} else {
		if (gesture_data[0] != GESTURE_DATA_ENABLE) {
			thp_log_err("gesture is disabled");
			return -EINVAL;
		}
		offset_bit = FTS_GESTURE_ID_BIT;
	}
	gesture_data_val = gesture_data[offset_bit];
	if (gesture_data_val == FTS_GESTURE_ID_VALUE)
		return FTS_DOUBLE_CLICK_WAKEUP_EVENT;
	else if (gesture_data_val == FTS_GESTURE_STYLUS_ID_VALUE)
		return FTS_STYLUS_WAKEUP_TO_MEMO_EVENT;

	return  -EINVAL;
}

static int touch_driver_read_gesture_data(void)
{
	int ret;
	int i;
	unsigned char w_buf[SPI_DUMMY_BYTE + FTS_GESTURE_DATA_LEN];
	unsigned char r_buf[SPI_DUMMY_BYTE + FTS_GESTURE_DATA_LEN];
	u32 txlen = 0;
	unsigned char *gesture_data = NULL;

	thp_log_info("%s: called\n", __func__);
	w_buf[txlen++] = FTS_REG_GESTURE_DATA;
	w_buf[txlen++] = FTS_READ_CMD;
	w_buf[txlen++] = (FTS_GESTURE_DATA_LEN >> GET_HIGH_BIT) & 0xFF;
	w_buf[txlen++] = FTS_GESTURE_DATA_LEN & 0xFF;
	txlen = SPI_DUMMY_BYTE + FTS_GESTURE_DATA_LEN + ADDR_OFFSET;
	for (i = 0; i < SPI_RETRY_NUMBER; i++) {
		ret = touch_driver_spi_transfer(w_buf, r_buf, txlen);
		if ((ret == 0) && ((r_buf[FTS_OFF_STS] & FTS_READ_CMD) == 0)) {
			ret = touch_driver_check_frame_valid(r_buf +
				SPI_DUMMY_BYTE,
				txlen - SPI_DUMMY_BYTE - ADDR_OFFSET);
			if (ret < 0) {
				thp_log_info("addr:%x crc abnormal,retry:%d",
					FTS_REG_GESTURE_DATA, i);
				udelay(CS_HIGH_DELAY);
				continue;
			}
			break;
		}
		thp_log_info("addr:%x status:%x,ret:%d",
			FTS_REG_GESTURE_DATA, r_buf[FTS_OFF_STS], ret);
		ret = -EIO;
		udelay(CS_HIGH_DELAY);
	}
	if (ret < 0) {
		thp_log_err("data read(addr:%x) %s,status:%x,ret:%d",
			FTS_REG_GESTURE_DATA,
			(i >= SPI_RETRY_NUMBER) ? "crc abnormal" : "fail",
			r_buf[FTS_OFF_STS], ret);
		return ret;
	}
	gesture_data = r_buf + SPI_DUMMY_BYTE;
	parse_gesture_info(gesture_data);

	return touch_driver_gesture_data_identify(gesture_data);
}

static int touch_driver_gesture_event_dispatch(unsigned int *gesture_wakeup_value,
	enum fts_gesture_event fts_gesture)
{
	if (!gesture_wakeup_value) {
		thp_log_err("%s: gesture_wakeup_value is null\n", __func__);
		return -EINVAL;
	}

	switch (fts_gesture) {
	case FTS_DOUBLE_CLICK_WAKEUP_EVENT:
		*gesture_wakeup_value = TS_DOUBLE_CLICK;
		break;
	case FTS_STYLUS_WAKEUP_TO_MEMO_EVENT:
		*gesture_wakeup_value = TS_STYLUS_WAKEUP_TO_MEMO;
		break;
	default:
		thp_log_err("%s:invalid  value\n", __func__);
		return -EINVAL;
	}
	return 0;
}

int touch_driver_report_gesture(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value)
{
	int gesture_data;

	if ((!tdev) || (!tdev->thp_core) || (!tdev->thp_core->sdev)) {
		thp_log_info("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	if ((!gesture_wakeup_value) ||
		(!tdev->thp_core->support_gesture_mode)) {
		thp_log_err("%s, gesture not support\n", __func__);
		return -EINVAL;
	}
	gesture_data = touch_driver_read_gesture_data();
	if (gesture_data < 0) {
		thp_log_err("%s: gesture data read or write fail\n", __func__);
		return -EINVAL;
	}
	mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
	if (tdev->thp_core->easy_wakeup_info.off_motion_on == true) {
		tdev->thp_core->easy_wakeup_info.off_motion_on = false;
		if (touch_driver_gesture_event_dispatch(gesture_wakeup_value, gesture_data) < 0)
			thp_log_err("%s, set gesture_wakeup_value fail\n", __func__);
	}
	mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
	return 0;
}

static int touch_driver_suspend(struct thp_device *tdev)
{
	int pt_test_station;

	thp_log_info("%s: called\n", __func__);
	if (!tdev) {
		thp_log_info("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	if (tdev->thp_core->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE &&
		tdev->thp_core->lcd_gesture_mode_support) {
		thp_log_info("%s: TS_GESTURE_MODE\n", __func__);
		touch_driver_enter_gesture_mode(tdev);
		return 0;
	}
	pt_test_station = is_pt_test_mode(tdev);
#ifndef CONFIG_HUAWEI_THP_MTK
	if (pt_test_station)
		thp_log_info("%s: PT sleep mode\n", __func__);
	else
		gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	touch_driver_power_off_cs(tdev);
#else
	if (tdev->thp_core->support_pinctrl == 0) {
		thp_log_info("%s: not support pinctrl\n", __func__);
		return -EINVAL;
	}
	if (pt_test_station) {
		thp_log_info("%s: PT sleep mode\n", __func__);
	} else {
		if (tdev->thp_core->reset_status_in_suspend_mode)
			thp_log_info("%s: reset retains high\n", __func__);
		else
			pinctrl_select_state(tdev->thp_core->pctrl,
				tdev->thp_core->mtk_pinctrl.reset_low);
	}
	pinctrl_select_state(tdev->thp_core->pctrl,
		tdev->thp_core->mtk_pinctrl.cs_low);
#endif
	thp_do_time_delay(tdev->timing_config.suspend_reset_after_delay_ms);

	return 0;
}

static void touch_driver_exit(struct thp_device *tdev)
{
	thp_log_info("%s: called\n", __func__);
	if (tdev) {
		kfree(tdev->tx_buff);
		tdev->tx_buff = NULL;
		kfree(tdev->rx_buff);
		tdev->rx_buff = NULL;
		kfree(tdev);
		tdev = NULL;
	}
}
static int touch_driver_second_poweroff(void)
{
	struct thp_core_data *cd = thp_get_core_data(DEFAULT_TOUCH_PANEL);
	struct thp_device *tdev = cd->thp_dev;
	int ret;
	int i;
	unsigned char *w_buf = NULL;
	unsigned char *r_buf = NULL;
	u32 txlen = 0;

	thp_log_info("%s: called\n", __func__);
	if (!tdev || !tdev->tx_buff || !tdev->rx_buff) {
		thp_log_err("%s: tdev/tx_buff/rx_buff null\n", __func__);
		return -ENOMEM;
	}

	w_buf = tdev->tx_buff;
	r_buf = tdev->rx_buff;

	for (i = 0; i < SLEEP_RETRY_NUM; i++) {
		udelay(150); /* delay 150us */
		w_buf[txlen++] = 0x62; /* power off twice command */
		w_buf[txlen++] = FTS_WRITE_CMD; /* 0x00  write */
		w_buf[txlen++] = 0x00;
		w_buf[txlen++] = 0x00;
		ret = touch_driver_spi_transfer(w_buf, r_buf, txlen);
		if ((ret < 0) || ((r_buf[SLEEP_BUF_BIT] & 0xA0) != 0)) {
			thp_log_err("data write addr:%x fail,status:%x,ret:%d",
				0x62, r_buf[SLEEP_BUF_BIT], ret);
			continue;
		} else {
			break;
		}
	}
	return ret;
}

struct thp_device_ops fts_dev_ops = {
	.init = touch_driver_init,
	.detect = touch_driver_chip_detect,
	.get_frame = touch_driver_get_frame,
	.resume = touch_driver_resume,
	.suspend = touch_driver_suspend,
	.exit = touch_driver_exit,
	.spi_transfer = touch_driver_spi_transfer,
	.chip_wrong_touch = touch_driver_wrong_touch,
	.chip_gesture_report = touch_driver_report_gesture,
	.second_poweroff = touch_driver_second_poweroff,
	.bt_handler = touch_driver_bt_handler,
};

/* malloc tdev and buffers */
struct thp_device *touch_driver_dev_malloc(void)
{
	struct thp_device *tdev = NULL;

	thp_log_info("%s: called\n", __func__);
	tdev = kzalloc(sizeof(*tdev), GFP_KERNEL);
	if (!tdev)
		goto err_touch_driver_dev_free;
	tdev->tx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!tdev->tx_buff)
		goto err_touch_driver_dev_free;
	tdev->rx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!tdev->rx_buff)
		goto err_touch_driver_dev_free;

	return tdev;

err_touch_driver_dev_free:
	touch_driver_dev_free(tdev);
	thp_log_err("%s: Malloc thp_device failed\n", __func__);

	return NULL;
}

static int __init touch_driver_module_init(void)
{
	int rc = 0;
	struct thp_device *tdev = NULL;
	struct thp_core_data *cd = thp_get_core_data(DEFAULT_TOUCH_PANEL);

	tdev = touch_driver_dev_malloc();
	if (!tdev) {
		thp_log_err("%s: thp device malloc fail\n", __func__);
		return -ENOMEM;
	}

	tdev->ic_name = FOCALTECH_IC_NAME;
	tdev->ops = &fts_dev_ops;
	if (cd && cd->fast_booting_solution) {
		thp_send_detect_cmd(tdev, DEFAULT_TOUCH_PANEL, NO_SYNC_TIMEOUT);
		/*
		 * The thp_register_dev will be called later to complete
		 * the real detect action.If it fails, the detect function will
		 * release the resources requested here.
		 */
		return 0;
	}
	rc = thp_register_dev(tdev, DEFAULT_TOUCH_PANEL);
	if (rc) {
		thp_log_err("%s: register fail\n", __func__);
		touch_driver_dev_free(tdev);
	}

	return rc;
}

static void __exit touch_driver_module_exit(void)
{
	thp_log_info("%s: called\n", __func__);
};

module_init(touch_driver_module_init);
module_exit(touch_driver_module_exit);
MODULE_AUTHOR("focaltech");
MODULE_DESCRIPTION("focaltech driver");
MODULE_LICENSE("GPL");
