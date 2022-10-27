/*
 * Copyright (C) 2016 ST Microelectronics S.A.
 * Copyright (C) 2010 Stollmann E+V GmbH
 * Copyright (C) 2010 Trusted Logic S.A.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/version.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/irq.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/poll.h>
#include <linux/miscdevice.h>
#include <linux/spinlock.h>
#include <st21nfc.h>
#include <linux/of_gpio.h>
#include <linux/clk.h>
#include <linux/pm_wakeup.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/regulator/consumer.h>
#include "securec.h"
#include <linux/arm-smccc.h>
#ifdef CONFIG_HUAWEI_DSM
#include <dsm/dsm_pub.h>
#endif
#define SET_PMU_REG_BIT(reg_val, bit_pos) ((reg_val) |= 1<<(bit_pos))
#define CLR_PMU_REG_BIT(reg_val, bit_pos) ((reg_val) &= ~(1<<(bit_pos)))

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <hwmanufac/dev_detect/dev_detect.h>
#endif

#include <huawei_platform/log/hw_log.h>
#define HWLOG_TAG nfc
HWLOG_REGIST();
#define NFC_TRY_NUM 3
#define MAX_TIMES 10

#define MAX_BUFFER_SIZE 260

#define DRIVER_VERSION "2.0.0"

#define CHAR_0 48
#define CHAR_9 57
#define RSSI_MAX 65535
#define NFC_NCI_HEAD_TYPE 0x7E
#define DATA_HEAD_LEN 4

#define NCI_HEADER  3
#define HCI_HEADER  1
#define HEADER_LEN  (NCI_HEADER + HCI_HEADER)
#define DATA_LENGTH 4
#define INDEX_0_ID 0
#define INDEX_1_CR 1
#define INDEX_2_LEN 2
#define INDEX_3_HCI 3
#define CMD_LEN     6
#define NFC_REC_LEN 256
#define MAX_COUNT   100

/* define the active state of the WAKEUP pin */
#define ST21_IRQ_ACTIVE_HIGH 1
#define ST21_IRQ_ACTIVE_LOW 0

#define MAX_NFC_CHIP_TYPE_SIZE 32
#define LOOP_TIMEOUT 1000

static int g_nfc_ext_gpio; /* use extented gpio, eg.codec */
static int g_nfc_svdd_sw; /* use for svdd switch */
static int g_nfc_ese_type = NFC_WITHOUT_ESE; /* record ese type wired to nfcc by dts */
static char g_nfc_chip_type[MAX_NFC_CHIP_TYPE_SIZE];
static int g_is4bytesheader = 1;

/* prototypes */
static irqreturn_t st21nfc_dev_irq_handler(int irq, void *dev_id);
/*
 * The platform data member 'polarity_mode' defines
 * how the wakeup pin is configured and handled.
 * it can take the following values :
 *   IRQF_TRIGGER_RISING
 *   IRQF_TRIGGER_FALLING
 *   IRQF_TRIGGER_HIGH
 *   IRQF_TRIGGER_LOW
 */

static void get_ext_gpio_type(void);
static void gpio_set_value(unsigned int gpio, int val);
static int nfc_get_dts_config_string(const char *node_name,
				const char *prop_name,
				char *out_string,
				int out_string_len);
static int gpio_get_value(unsigned int gpio);
static void get_wake_lock_timeout(void);

struct st21nfc_platform {
	struct mutex read_mutex;
	struct mutex irq_wake_mutex;
	struct i2c_client *client;
	unsigned int irq_gpio;
	unsigned int reset_gpio;
	unsigned int ese_pwr_gpio;
	// unsigned int clkreq_gpio;
	unsigned int ena_gpio;
	unsigned int polarity_mode;
	unsigned int active_polarity; /* either 0 (low-active) or 1 (high-active) */
};

static bool irqIsAttached;
static bool device_open; /* Is device open? */
static void get_nfc_wired_ese_type(void);

/* 0 -- hisi cpu(default); 1 -- hisi pmu */
static int g_nfc_clk_src = NFC_CLK_SRC_CPU;
static int g_nfcservice_lock;

static int g_nfc_single_channel;
static int g_nfc_card_num;

static int nfc_at_result;
static int nfc_switch_state;
static int g_nfc_close_type;
static int firmware_update;
static char g_nfc_nxp_config_name[MAX_CONFIG_NAME_SIZE];
static char g_nfc_brcm_conf_name[MAX_CONFIG_NAME_SIZE];
static int g_nfc_ese_num;
static char g_nfc_fw_version[MAX_NFC_FW_VERSION_SIZE];
static int g_nfcservice_lock;
static int g_nfc_activated_se_info; /* record activated se info when nfc enable process */
static int g_nfc_hal_dmd_no; /* record last hal dmd no */
long st_nfc_get_rssi = 0;
static int g_ese_spi_bus = 0;
static int g_ese_clkreq_gpio = 0;

static int g_clk_status_flag = 0;/* use for judging whether clk has been enabled */
static int g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_DISABLE;

struct st21nfc_dev {
	wait_queue_head_t read_wq;
	struct miscdevice st21nfc_device;
	struct device *dev;
	bool irq_enabled;
	bool irq_wake_enabled;
	struct st21nfc_platform platform_data;
	spinlock_t irq_enabled_lock;

	struct pinctrl *pctrl;
	struct pinctrl_state *pinctrl_state_srclkenai;
	struct pinctrl_state *pinctrl_state_esespics;
	struct pinctrl_state *pinctrl_state_esespiclk;
	struct pinctrl_state *pinctrl_state_esespimo;
	struct pinctrl_state *pinctrl_state_esespimi;
	struct pinctrl_state *pinctrl_state_esepwrreq;
	int sim_switch;
	int sim_status;
	int enable_status;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 157)
	struct wakeup_source *wlock_read;
#else
	struct wakeup_source wlock_read;
#endif
};

static void st21nfc_disable_irq(struct st21nfc_dev *st21nfc_dev)
{
	unsigned long flags;
	hwlog_info("%s : Enter IRQ %d\n", __func__, st21nfc_dev->platform_data.client->irq);
	spin_lock_irqsave(&st21nfc_dev->irq_enabled_lock, flags);
	if (st21nfc_dev->irq_enabled) {
		disable_irq_nosync(st21nfc_dev->platform_data.client->irq);
		st21nfc_dev->irq_enabled = false;
	}
	spin_unlock_irqrestore(&st21nfc_dev->irq_enabled_lock, flags);
	hwlog_info("%s : exit , irq_enable=%d\n", __func__,st21nfc_dev->irq_enabled);
}

static void st21nfc_enable_irq(struct st21nfc_dev *st21nfc_dev)
{
	unsigned long flags;
	hwlog_info("%s : Enter IRQ %d\n", __func__, st21nfc_dev->platform_data.client->irq);
	spin_lock_irqsave(&st21nfc_dev->irq_enabled_lock, flags);
	if (!st21nfc_dev->irq_enabled) {
		st21nfc_dev->irq_enabled = true;
		enable_irq(st21nfc_dev->platform_data.client->irq);
	}
	spin_unlock_irqrestore(&st21nfc_dev->irq_enabled_lock, flags);
	hwlog_info("%s : exit , irq_enable=%d\n", __func__,st21nfc_dev->irq_enabled);
}

static void st21nfc_enable_irq_wake(struct st21nfc_dev *st21nfc_dev)
{
	int ret;
	mutex_lock(&st21nfc_dev->platform_data.irq_wake_mutex);
	if (!st21nfc_dev->irq_wake_enabled) {
		st21nfc_dev->irq_wake_enabled = true;
		hwlog_info("%s : begin to enable_irq_wake", __func__);
		ret = enable_irq_wake(st21nfc_dev->platform_data.client->irq);
		if (ret)
			pr_err("%s failed: ret=%d\n", __func__, ret);
	}
	mutex_unlock(&st21nfc_dev->platform_data.irq_wake_mutex);
}

static void st21nfc_disable_irq_wake(struct st21nfc_dev *st21nfc_dev)
{
	int ret;
	mutex_lock(&st21nfc_dev->platform_data.irq_wake_mutex);
	if (st21nfc_dev->irq_wake_enabled) {
		st21nfc_dev->irq_wake_enabled = false;
		hwlog_info("%s : begin to disable_irq_wake", __func__);
		ret = disable_irq_wake(st21nfc_dev->platform_data.client->irq);
		if (ret)
			pr_err("%s failed: ret=%d\n", __func__, ret);
	}
	mutex_unlock(&st21nfc_dev->platform_data.irq_wake_mutex);
}

static void print_hex_string(int bytes_read, char *buf, int len)
{
	int ret = 0;
	int i;
	// 1 hex byte match 2 characters, and add end symbol '\0'
	int buffer_len = bytes_read * 2 + 1;
	char *print_str = NULL;
	if (bytes_read > MAX_BUFFER_SIZE || bytes_read <= 0 ||
		bytes_read > len || buf == NULL) {
		hwlog_err("%s:param error \n", __func__);
		return;
	}
	print_str = (char *)kzalloc(buffer_len, GFP_KERNEL);
	if (print_str == NULL) {
		hwlog_err("%s:Cannot allocate memory for read tmpStr.\n",
			__func__);
		return;
	}
	(void)memset_s(print_str, buffer_len, 0x0, buffer_len);
	for (i = 0; i < bytes_read; i++) {
		// 1 hex byte match 2 characters
		ret = snprintf_s(&print_str[i * 2], buffer_len - i * 2, 2,
			"%02X", buf[i]);
		if (ret < 0) {
			hwlog_err("%s:snprintf_s fail, i=%d.\n", __func__, i);
			break;
		}
	}
	if (ret > 0)
		hwlog_info("%s RX: %s\n", __func__, print_str);

	kfree(print_str);
}

static ssize_t st_i2c_read(struct  st21nfc_dev *pdev, char *buf, int count)
{
	int ret = 0;
	int pinlev;
	bool isSuccess = false;
	int size = 0;
	int retry = 0;
	int hdrsz = g_is4bytesheader ? 4 : 3;
	int extra = 0;
	int bytes_read;

	if (count < DATA_HEAD_LEN || pdev == NULL || buf == NULL) {
		hwlog_info("%s:input param error\n", __func__);
		return -1;
	} else if (count > MAX_BUFFER_SIZE) {
		count = MAX_BUFFER_SIZE;
		hwlog_info("%s:count set max\n", __func__);
	}
	mutex_lock(&pdev->platform_data.read_mutex);
	pinlev = gpio_get_value(pdev->platform_data.irq_gpio);
	hwlog_info("%s: pinlev=0x%x\n", __func__, pinlev);

	/* Read data, we have 3 chances */
	do {
		bytes_read = i2c_master_recv(pdev->platform_data.client,
			buf, hdrsz);
		hwlog_info("%s : retry = %d, bytes_read = %d\n", __func__,
			retry, bytes_read);
		print_hex_string(bytes_read, buf, count);
		if (bytes_read == (int)hdrsz) {
			// 0x6000:nci cmd head
			if (hdrsz == DATA_HEAD_LEN &&
				buf[0] == 0x60 && buf[1] == 0x00)
				// read only 3 bytes until next Reset
				// We are either in loader mode or in older fw
				g_is4bytesheader = 0;
		}
		// 0x7E:st21nfc rsp data first byte
		if (hdrsz == DATA_HEAD_LEN && buf[0] != NFC_NCI_HEAD_TYPE) {
			// we read 1 payload byte already
			extra = 1;
		} else if (hdrsz == DATA_HEAD_LEN) {
			// we got dummy 7e,discard and continue as if not there
			// shift nci head byte[1][2][3] to heard byte[0][1][2]
			buf[0] = buf[1];
			buf[1] = buf[2];
			buf[2] = buf[3];
		}
		if (buf[0] != NFC_NCI_HEAD_TYPE &&
			buf[1] != NFC_NCI_HEAD_TYPE) {
			isSuccess = true;
		} else {
			// we got some dummy bytes read (on top of extra byte)
			// shift nci head byte[1][2] to heard byte[0][1]
			if (buf[1] != NFC_NCI_HEAD_TYPE) {
				buf[0] = buf[1];
				buf[1] = buf[2];
				// read 1 byte data to buf[3]
				bytes_read = i2c_master_recv(
					pdev->platform_data.client, buf + 2, 1);
				if (bytes_read == 1)
					isSuccess = true;
			} else if (buf[2] != NFC_NCI_HEAD_TYPE) {
				buf[0] = buf[2];
				// read 2 bytes data to buf[1]buf[2]
				bytes_read = i2c_master_recv(
					pdev->platform_data.client, buf + 1, 2);
				if (bytes_read == 2)
					isSuccess = true;
			} else {
				// there was no data ready, wait 3ms
				msleep(3);
			}
		}
		if (isSuccess == true) {
			// buf[2]: payload length
			int remaining = buf[2];
			bytes_read = 0;
			// read remaining data,3 + extra:
			// 3 bytes nci head and length of extra payload
			if (remaining - extra > 0)
				bytes_read = i2c_master_recv(
					pdev->platform_data.client,
					buf + 3 + extra,
					remaining - extra);

			if (bytes_read == remaining - extra)
				// 3: nci head length
				size = 3 + extra + bytes_read;
			else
				isSuccess = false;
		}
		retry++;
		// 0x6F02: firmware log, skip this log
		if ((buf[0] == 0x6F && buf[1] == 0x02) && isSuccess == true) {
			isSuccess = false;
			retry = 0;
			print_hex_string(size, buf, count);
		}
	} while(isSuccess == false && retry < MAX_TIMES);

	print_hex_string(size, buf, count);
	if (false == isSuccess) {
		hwlog_err("%s : i2c_master_recv returned %d, line = %d\n", __func__, bytes_read, __LINE__);
		ret = -EIO;
	}
	mutex_unlock(&pdev->platform_data.read_mutex);
	return ret;
}

static ssize_t st_i2c_write(struct  st21nfc_dev *pdev, const char *buf, int count)
{
	char tmp[MAX_BUFFER_SIZE];
	int ret = count;
	char *tmpStr = NULL;
	int retry;
	int i;
	bool isSuccess = false;

	if (count > MAX_BUFFER_SIZE)
		count = MAX_BUFFER_SIZE;

	tmpStr = (char *)kzalloc(sizeof(tmp)*2 + 1, GFP_KERNEL);
	if (!tmpStr) {
		hwlog_info("%s:Cannot allocate memory for write tmpStr.\n", __func__);
		return -ENOMEM;
	}
	/* Write data */
	for (retry = 0; retry < NFC_TRY_NUM; retry++) {
	    ret = i2c_master_send(pdev->platform_data.client, buf, count);
		for (i = 0; i < count; i++) {
			snprintf(&tmpStr[i * 2], 3, "%02X", buf[i]);
		}
		hwlog_info("%s : retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);
		if (ret == (int)count) {
			isSuccess = true;
			break;
		} else {
			if (retry > 0) {
				hwlog_info("%s : send data try =%d returned %d\n", __func__, retry, ret);
			}
			msleep(1);
			continue;
		}
	}
	kfree(tmpStr);
	if (false == isSuccess) {
		hwlog_err("%s : i2c_master_send returned %d\n", __func__, ret);
		ret = -EIO;
	}
	return ret;
}

static ssize_t nfc_get_rssi_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
	int i = 0;
	int flag = 1;
	st_nfc_get_rssi = 0;
	if (buf != NULL) {
		if (buf[0] == '-') {
			flag = -1;
			i++;
		}
		while (buf[i] != '\0') {
			if ((buf[i] >= CHAR_0) && (buf[i] <= CHAR_9) && (st_nfc_get_rssi <= RSSI_MAX)) {
				st_nfc_get_rssi = (long)(st_nfc_get_rssi * 10) + (buf[i] - CHAR_0); /* file storage str */
			}
			i++;
		}
		st_nfc_get_rssi = flag * st_nfc_get_rssi;
	}
	return (ssize_t)count;
}

static ssize_t nfc_get_rssi_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	pr_info("%s:%s,%ld\n", __func__, buf, st_nfc_get_rssi);
	return (ssize_t)(snprintf(buf, 256, "%ld", st_nfc_get_rssi));
}


static ssize_t nfc_recovery_close_nfc_store(struct device *dev, struct device_attribute *attr,
            const char *buf, size_t count)
{
	return (ssize_t)count;
}

static int recovery_close_nfc(struct i2c_client *client, struct st21nfc_dev *pdev)
{
	int ret;
	int nfc_rece_length = 256;
	unsigned char recv_buf[256] = {0};
	const  char core_reset_cmd[] = { 0x20, 0x00, 0x01, 0x00 };
	const  char init_cmd[] = { 0x20, 0x01, 0x02, 0x00, 0x00 };
	const  char set_ven_config[] = { 0x2f, 0x02, 0x02, 0x02, 0x00 };
	unsigned int fw_version = 0;

	/* reset */
	pr_info("%s Double Pulse Request,reset_gpio=%d\n", __func__, pdev->platform_data.reset_gpio);
	if (pdev->platform_data.reset_gpio != 0) {
		/* pulse low for 20 millisecs */
		gpio_set_value(pdev->platform_data.reset_gpio, 0);
		pr_info("%s,reset_gpio=%d\n", __func__, gpio_get_value(pdev->platform_data.reset_gpio));
		msleep(20);
		gpio_set_value(pdev->platform_data.reset_gpio, 1);
		msleep(10);
		/* pulse low for 20 millisecs */
		gpio_set_value(pdev->platform_data.reset_gpio, 0);
		msleep(20);
		gpio_set_value(pdev->platform_data.reset_gpio, 1);
		pr_info("%s done Double Pulse Request,reset_gpio=%d\n", __func__,gpio_get_value(pdev->platform_data.reset_gpio));
	}
	g_is4bytesheader = 1;
	msleep(10);

	/* read response */
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	if ((ret < 0) || !((recv_buf[0] == 0x60) && (recv_buf[1] == 0x00))) {
		pr_err("%s: reset failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	fw_version = (recv_buf[10] << 24) | (recv_buf[11] << 16)
		| (recv_buf[12] << 8) | recv_buf[13];
	pr_info("%s: fw_version, 0x%x\n", __func__, fw_version);
	if (fw_version == 0) {
		pr_err("%s: no firmware inside, nothing to do.\n", __func__);
		goto FAILED;
	}
	// send core reset command
	ret = st_i2c_write(pdev, core_reset_cmd, sizeof(core_reset_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	/* read response */
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	if ((ret < 0) || !(((recv_buf[0] == 0x40) && (recv_buf[1] == 0x00)) || ((recv_buf[0] == 0x60) && (recv_buf[1] == 0x00)))) {
		pr_err("%s: st_i2c_read core reset failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	/* read response */
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	if ((ret < 0) || !(((recv_buf[0] == 0x40) && (recv_buf[1] == 0x00)) || ((recv_buf[0] == 0x60) && (recv_buf[1] == 0x00)))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	/* write CORE_INIT_CMD */
	ret = st_i2c_write(pdev, init_cmd, sizeof(init_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	/* read response */
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	if ((ret < 0) || !(((recv_buf[0] == 0x40) && (recv_buf[1] == 0x01)) || ((recv_buf[0] == 0x60) && (recv_buf[1] == 0x06) ))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	if ((ret < 0) || !(((recv_buf[0] == 0x40) && (recv_buf[1] == 0x01)) || ((recv_buf[0] == 0x60) && (recv_buf[1] == 0x06) ))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	msleep(2);

	/* write set_ven_config */
	ret = st_i2c_write(pdev, set_ven_config, sizeof(set_ven_config));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	/*read response*/
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	if ((ret < 0) || !((recv_buf[0] == 0x4F) && (recv_buf[1] == 0x02) && (recv_buf[3] == 0x00))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	msleep(2);
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	if ((ret < 0) || !((recv_buf[0] == 0x60) && (recv_buf[1] == 0x00))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	msleep(2);
	// read PROP_LOG_MODE_NTF data, otherwise will lead to IRQ keeping high. No need care of read result
	ret = st_i2c_read(pdev, recv_buf, nfc_rece_length);
	return 0;

FAILED:
	return -1;
}

static int nfc_i2c_check(struct i2c_client *client, struct  st21nfc_dev *dev)
{
	int ret = -1;
	unsigned char recv_buf[MAX_BUFFER_SIZE] = {0};

	/* reset */
	pr_info("%s Double Pulse Request, reset_gpio=%u\n", __func__,
		dev->platform_data.reset_gpio);
	if (dev->platform_data.reset_gpio != 0) {
		/* pulse low for 20 millisecs */
		gpio_set_value(dev->platform_data.reset_gpio, 0);
		pr_info("%s,reset_gpio=%d\n", __func__,
			gpio_get_value(dev->platform_data.reset_gpio));
		msleep(20);
		gpio_set_value(dev->platform_data.reset_gpio, 1);
		msleep(10);
		/* pulse low for 20 millisecs */
		gpio_set_value(dev->platform_data.reset_gpio, 0);
		msleep(20);
		gpio_set_value(dev->platform_data.reset_gpio, 1);
		pr_info("%s done , reset_gpio=%d\n", __func__,
			gpio_get_value(dev->platform_data.reset_gpio));
	}
	/* wait 20 millisecs */
	msleep(20);
	/* read response */
	ret = st_i2c_read(dev, recv_buf, sizeof(recv_buf));
	return ret;
}

static ssize_t nfc_recovery_close_nfc_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int status = -1;
	struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev;
	st21nfc_dev = i2c_get_clientdata(i2c_client_dev);
	if (st21nfc_dev == NULL) {
		pr_err("%s: st21nfc_dev == NULL!\n", __func__);
		return 0;
	}
	pr_info("%s: enter!\n", __func__);
	status = recovery_close_nfc(i2c_client_dev, st21nfc_dev);
	if (status < 0) {
		pr_err("%s: recovery_close_nfc error!\n", __func__);
	}
	status = 0; // not block recovery in ST
	pr_info("%s: status=%d\n", __func__, status);
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d\n", status));
}

static ssize_t nfc_clk_src_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", g_nfc_clk_src));
}

static ssize_t nfc_calibration_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return -1;
}

int st_nfc_record_dmd_info(long dmd_no, const char *dmd_info)
{
	return 0;
}

static ssize_t nfc_hal_dmd_info_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	long val = 0;
	char dmd_info_from_hal[64] = {'\0'};
	/* The length of DMD error number is 9. */
	if (sscanf(buf, "%9ld", &val) == 1) {
		if (val < NFC_DMD_NUMBER_MIN || val > NFC_DMD_NUMBER_MAX) {
			return (ssize_t)count;
		}
		g_nfc_hal_dmd_no = val;
		/*
		 * The max length of content for current dmd description set as 63.
		 * Example for DMD Buf: '923002014 CoreReset:600006A000D1A72000'.
		 * A space as a separator is between dmd error no and description.
		 */
		if (sscanf(buf, "%*s%63s", dmd_info_from_hal) == 1) {
			st_nfc_record_dmd_info(val, dmd_info_from_hal);
		}
	} else {
		pr_err("%s: get dmd number error\n", __func__);
	}
	return (ssize_t)count;
}

static ssize_t nfc_hal_dmd_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", g_nfc_hal_dmd_no));
}

static ssize_t nfc_activated_se_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", g_nfc_activated_se_info));
}

static ssize_t nfc_activated_se_info_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	int val = 0;
	if (sscanf(buf, "%1d", &val) == 1) {
		g_nfc_activated_se_info = val;
	} else {
		pr_err("%s: set g_nfc_activated_se_info error\n", __func__);
		g_nfc_activated_se_info = 0;
	}
	pr_info("%s: g_nfc_activated_se_info:%d\n", __func__, g_nfc_activated_se_info);
	return (ssize_t)count;
}

static ssize_t nfcservice_lock_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", g_nfcservice_lock));
}

static ssize_t nfcservice_lock_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	int val = 0;

	if (sscanf(buf, "%1d", &val) == 1) {
		g_nfcservice_lock = val;
	} else {
		pr_err("%s: set g_nfcservice_lock error\n", __func__);
		g_nfcservice_lock = 0;
	}
	pr_info("%s: g_nfcservice_lock:%d\n", __func__, g_nfcservice_lock);
	return (ssize_t)count;
}

static ssize_t nfc_fw_version_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int ret = -1;

	memset(g_nfc_fw_version, 0, MAX_NFC_FW_VERSION_SIZE);
	ret = nfc_get_dts_config_string("nfc_fw_version", "nfc_fw_version",
		g_nfc_fw_version, sizeof(g_nfc_fw_version));

	if (ret != 0) {
		memset(g_nfc_fw_version, 0, MAX_NFC_FW_VERSION_SIZE);
		pr_err("%s: can't get nfc g_nfc_fw_version, default FW 8.1.24\n", __func__);
		strcpy(g_nfc_fw_version, "FW 8.1.24");
	}
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%s", g_nfc_fw_version));
}

static int nfc_get_dts_config_u32(const char *node_name, const char *prop_name, u32 *pvalue)
{
	struct device_node *np = NULL;
	int ret = -1;

	for_each_node_with_property(np, node_name) {
		ret = of_property_read_u32(np, prop_name, pvalue);
		if (ret != 0) {
			pr_debug("%s: can not get prop values with prop_name: %s\n", __func__, prop_name);
		} else {
			pr_info("%s: %s=%d\n", __func__, prop_name, *pvalue);
		}
	}
	return ret;
}

void st_set_nfc_ese_num(void)
{
	int ret = -1;
	ret = nfc_get_dts_config_u32("st_nfc_ese_num", "st_nfc_ese_num", &g_nfc_ese_num);
	if (ret != 0) {
		g_nfc_ese_num = 1;
		pr_err("%s: can't get nfc ese num config node, g_nfc_ese_num default value is 1!\n", __func__);
	}
}

static int st_set_nfc_spi_bus(void)
{
	int ret = -1;
	ret = nfc_get_dts_config_u32("ese_config_spi_bus", "ese_config_spi_bus", &g_ese_spi_bus);
	if (ret != 0) {
		pr_err("%s: can't get nfc spi_bus config node!use default value\n", __func__);
		g_ese_spi_bus = 5;
		return 0;
	}
	pr_err("%s: g_ese_spi_bus = %d\n", __func__, g_ese_spi_bus);
	return 0;
}

static int st_set_nfc_clkreq_gpio(void)
{
	int ret = -1;
	ret = nfc_get_dts_config_u32("gpio_svdd_pwr_req", "gpio_svdd_pwr_req", &g_ese_clkreq_gpio);
	if (ret != 0) {
		pr_err("%s: can't get nfc gpio_svdd_pwr_req config node!use default value\n", __func__);
		g_ese_clkreq_gpio = 19;
		return 0;
	}
	pr_err("%s: g_ese_clkreq_gpio = %d\n", __func__, g_ese_clkreq_gpio);

	return 0;
}

void write_conf_to_tee(void)
{
	struct arm_smccc_res res;
	uint32_t x1;
	uint32_t x2;
	uint16_t gpio_svdd_pwr_req = g_ese_clkreq_gpio; // gpio69
	uint8_t spi_bus = g_ese_spi_bus; // spi1
	uint8_t ese_type = 1; // ese type 1:ST

	x1 = ese_type;
	x1 = x1 | (spi_bus << OFFSET_8);
	x1 = x1 | (ESE_MAGIC_NUM << OFFSET_16);

	x2 = gpio_svdd_pwr_req;
	x2 = x2 | (ESE_MAGIC_NUM << OFFSET_16);
	arm_smccc_1_1_smc(MTK_SIP_KERNEL_ESE_CONF_TO_TEE_ADDR_AARCH64, x1, x2, 0, &res);
	pr_err("%s: write_conf_to_tee, x1:0x%X x2:0x%X\n", __func__, x1, x2);
}

static ssize_t nfc_ese_num_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d\n", (unsigned char)g_nfc_ese_num));
}

void st_set_nfc_nxp_config_name(void)
{
	int ret = -1;

	memset(g_nfc_nxp_config_name, 0, MAX_CONFIG_NAME_SIZE);
	ret = nfc_get_dts_config_string("st_nfc_nxp_name", "st_nfc_nxp_name",
					g_nfc_nxp_config_name, sizeof(g_nfc_nxp_config_name));

	if (ret != 0) {
		memset(g_nfc_nxp_config_name, 0, MAX_CONFIG_NAME_SIZE);
		pr_err("%s: can't get nfc nxp config name\n", __func__);
		return;
	}
	pr_info("%s: nfc nxp config name:%s\n", __func__, g_nfc_nxp_config_name);
}

void st_set_nfc_brcm_config_name(void)
{
	int ret = -1;

	memset(g_nfc_brcm_conf_name, 0, MAX_CONFIG_NAME_SIZE);
	ret = nfc_get_dts_config_string("st_nfc_brcm_conf_name", "st_nfc_brcm_conf_name",
					g_nfc_brcm_conf_name, sizeof(g_nfc_brcm_conf_name));

	if (ret != 0) {
		memset(g_nfc_brcm_conf_name, 0, MAX_CONFIG_NAME_SIZE);
		pr_err("%s: can't get nfc brcm config name\n", __func__);
		return;
	}
	pr_info("%s: nfc brcm config name:%s\n", __func__, g_nfc_brcm_conf_name);
}

static int check_sim_status(struct i2c_client *client, struct  st21nfc_dev *pdev)
{
	int ret;
	int nfc_rece_length = 200;
	int i = 0;
	unsigned int simStatus;

	unsigned char recvBuf[200] = {0};
	const  char init_cmd[] = { 0x20, 0x01, 0x02, 0x00, 0x00 };
	const  char set_mode_on[] = { 0x2F, 0x02, 0x02, 0x02, 0x01 };
	const  char core_init[] = { 0x20, 0x01, 0x02, 0x00, 0x00 };
	const  char hci_network[] = { 0x01, 0x00, 0x02, 0x81, 0x03 };
	const  char ese_cmd[]  = { 0x01, 0x00, 0x04, 0x81, 0x01, 0x03, 0xC0 };
	const  char send_cmd[] = { 0x22, 0x00, 0x00 };
	const  char ese_acti_cmd[] = { 0x22, 0x01, 0x02, 0x82, 0x01 };
	const  char ese_deac_cmd[] = { 0x22, 0x01, 0x02, 0x82, 0x00 };
	const  char sim_act_cmd[] = { 0x22, 0x01, 0x02, 0x81, 0x01 };
	const  char sim_deact_cmd[] = { 0x22, 0x01, 0x02, 0x81, 0x00 };

	/* reset */
	pr_info("%s Double Pulse Request,reset_gpio=%d\n", __func__,pdev->platform_data.reset_gpio);
	if (pdev->platform_data.reset_gpio != 0) {
		/* pulse low for 20 millisecs */
		gpio_set_value(pdev->platform_data.reset_gpio, 0);
		pr_info("%s,reset_gpio=%d\n", __func__,gpio_get_value(pdev->platform_data.reset_gpio));
		msleep(20);
		gpio_set_value(pdev->platform_data.reset_gpio, 1);
		msleep(10);
		/* pulse low for 20 millisecs */
		gpio_set_value(pdev->platform_data.reset_gpio, 0);
		msleep(20);
		gpio_set_value(pdev->platform_data.reset_gpio, 1);

		pr_info("%s done Double Pulse Request,reset_gpio=%d\n", __func__,gpio_get_value(pdev->platform_data.reset_gpio));
	}
	msleep(10);

	pdev->sim_status = 0;
	simStatus = 0;

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if ((ret < 0) || !((recvBuf[0] == 0x60) && (recvBuf[1] == 0x00))) {
		pr_err("%s: reset failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* write CORE_INIT_CMD */
	ret = st_i2c_write(pdev, init_cmd, sizeof(init_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if ((ret < 0) || !((recvBuf[0] == 0x40) && (recvBuf[1] == 0x01) && (recvBuf[3] == 0x00))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	udelay(500);

	/* write Set mode ON */
	ret = st_i2c_write(pdev, set_mode_on, sizeof(set_mode_on));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if ((ret < 0) || !((recvBuf[0] == 0x4F) && (recvBuf[1] == 0x02) && (recvBuf[3] == 0x00))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	udelay(1000);

	/* write CORE_INIT_CMD */
	ret = st_i2c_write(pdev, core_init, sizeof(core_init));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if (ret < 0) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	udelay(1000);

	/* write Open HCI network */
	ret = st_i2c_write(pdev, hci_network, sizeof(hci_network));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if (ret < 0) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	udelay(1000);

	/* write Set C0 (== SE HCI ID) */
	ret = st_i2c_write(pdev, ese_cmd, sizeof(ese_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if (ret < 0) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	udelay(1000);

	/* write send_CMD */
	ret = st_i2c_write(pdev, send_cmd, sizeof(send_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_read failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if ((ret < 0) || !((recvBuf[0] == 0x42) && (recvBuf[1] == 0x00) && (recvBuf[3] == 0x00))) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	udelay(1000);

	/* write acti cmd */
	ret = st_i2c_write(pdev, ese_acti_cmd, sizeof(ese_acti_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if (ret < 0) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	for (i = 0;i < nfc_rece_length; i++) {
		// 0x62 and 0x00 is ese keyword of rsp, 3 is offset of 0x00
		if (recvBuf[i] == 0x62 && (i + 3) < sizeof(recvBuf)) {
			if ( recvBuf[i + 3] == 0x00) {
				pr_err("%s: eSE_SUPPORT_CARD_EMULATION", __func__);
				simStatus |= eSE_SUPPORT_CARD_EMULATION;
				pdev->sim_status = (int)simStatus;
			}
		}
	}

	mdelay(10);
	/* write deac cmd */
	ret = st_i2c_write(pdev, ese_deac_cmd, sizeof(ese_deac_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if (ret < 0) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	mdelay(10);

    /* write deac cmd */
	ret = st_i2c_write(pdev, sim_act_cmd, sizeof(sim_act_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

    /* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if (ret < 0) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	for (i = 0; i < sizeof(recvBuf); i++) {
		// 0x62 and 0x00 is uicc keyword of rsp, 3 is offset of 0x00
		if (recvBuf[i] == 0x62 && (i + 3) < sizeof(recvBuf)) {
			if (recvBuf[i + 3] == 0x00) {
				pr_err("%s: UICC_SUPPORT_CARD_EMULATION", __func__);
				simStatus |= UICC_SUPPORT_CARD_EMULATION;
				pdev->sim_status = (int)simStatus;
			}
		}
	}

	mdelay(5);

	/* write deac cmd */
	ret = st_i2c_write(pdev, sim_deact_cmd, sizeof(sim_deact_cmd));
	if (ret < 0) {
		pr_err("%s: st_i2c_write failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}
	/* read response */
	ret = st_i2c_read(pdev, recvBuf, nfc_rece_length);
	if (ret < 0) {
		pr_err("%s: st_i2c_read core init failed, ret:%d\n", __func__, ret);
		goto FAILED;
	}

	return pdev->sim_status;

FAILED:
	pdev->sim_status = ret;
	return ret;
}


static ssize_t nfc_sim_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int status = -1;
	struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev;
	st21nfc_dev = i2c_get_clientdata(i2c_client_dev);
	if (st21nfc_dev == NULL) {
		pr_err("%s: st21nfc_dev == NULL!\n", __func__);
		return status;
	}
	pr_info("%s: enter!\n", __func__);
	status = check_sim_status(i2c_client_dev, st21nfc_dev);
	if (status < 0) {
		pr_err("%s: check_sim_status error!\n", __func__);
	}
	pr_info("%s: status=%d\n", __func__, status);
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d\n", status));
}

static ssize_t nfc_brcm_conf_name_store(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	return (ssize_t)count;
}

static ssize_t nfc_brcm_conf_name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, strlen(g_nfc_brcm_conf_name)+1, "%s", g_nfc_brcm_conf_name));
}

static ssize_t nxp_config_name_store(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	return (ssize_t)count;
}

static ssize_t nxp_config_name_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, strlen(g_nfc_nxp_config_name)+1, "%s", g_nfc_nxp_config_name));
}


static ssize_t nfc_wired_ese_info_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", g_nfc_ese_type));
}

static ssize_t nfc_wired_ese_info_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	int val = 0;
	if (sscanf(buf, "%1d", &val) == 1) {
		g_nfc_ese_type = val;
	} else {
		pr_err("%s: set g_nfc_ese_type  error\n", __func__);
	}
	pr_err("%s: g_nfc_ese_type:%d\n", __func__,g_nfc_ese_type);
	return (ssize_t)count;
}

static ssize_t nfc_sim_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev;
	st21nfc_dev = i2c_get_clientdata(i2c_client_dev);
	if (st21nfc_dev == NULL) {
		pr_err("%s: st21nfc_dev == NULL!\n", __func__);
		return 0;
	}
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d\n", st21nfc_dev->sim_switch));
}

static ssize_t nfc_sim_switch_store(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev;
	int val = 0;

	st21nfc_dev = i2c_get_clientdata(i2c_client_dev);
	if (st21nfc_dev == NULL) {
		pr_err("%s: st21nfc_dev == NULL!\n", __func__);
		return 0;
	}
	if (sscanf(buf, "%1d", &val) == 1) {
		if (val >= 1 && val <= 3) {
			st21nfc_dev->sim_switch = val;
		} else {
			return -EINVAL;
		}
	} else
		return -EINVAL;
	return (ssize_t)count;
}

static ssize_t nfc_at_result_store(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	if (buf != NULL) {
		nfc_at_result=buf[0]-CHAR_0; /*file storage str*/
	}
	return (ssize_t)count;
}

static ssize_t nfc_at_result_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, sizeof(nfc_at_result)+1, "%d", nfc_at_result));
}

static ssize_t nfc_single_channel_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", g_nfc_single_channel));
}

static ssize_t nfc_switch_state_store(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	if (buf != NULL) {
		nfc_switch_state=buf[0]-CHAR_0; /* file storage str */
	}
	return (ssize_t)count;
}

static ssize_t nfc_switch_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, sizeof(nfc_switch_state)+1, "%d", nfc_switch_state));
}

static ssize_t nfc_close_type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", g_nfc_close_type));
}

static ssize_t nfc_close_type_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	int val = 0;
	if (sscanf(buf, "%1d", &val) == 1) {
		g_nfc_close_type = val;
	} else {
		pr_err("%s: set g_nfc_close_type error\n", __func__);
		g_nfc_close_type = 0;
	}
	pr_info("%s: g_nfc_close_type:%d\n", __func__, g_nfc_close_type);
	return (ssize_t)count;
}

static ssize_t nfc_fwupdate_store(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{

	if ('1' == buf[0]) {
		firmware_update = 1;
		pr_info("%s:firmware update success\n", __func__);
	}

	return (ssize_t)count;
}

static ssize_t nfc_fwupdate_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, sizeof(firmware_update)+1, "%d", firmware_update));
}

static ssize_t nfc_enable_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev;
	st21nfc_dev = i2c_get_clientdata(i2c_client_dev);
	if (st21nfc_dev == NULL) {
		pr_err("%s: st21nfc_dev == NULL!\n", __func__);
		return 0;
	}
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d\n", st21nfc_dev->enable_status));
}

static ssize_t nfc_enable_status_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev;
	int val = 0;

	st21nfc_dev = i2c_get_clientdata(i2c_client_dev);
	if (st21nfc_dev == NULL) {
		pr_err("%s: st21nfc_dev == NULL!\n", __func__);
		return 0;
	}
	if (sscanf(buf, "%1d", &val) == 1) {
		if (val == ENABLE_START) {
			st21nfc_dev->enable_status = ENABLE_START;
		} else if (val == ENABLE_END) {
			st21nfc_dev->enable_status = ENABLE_END;
		} else {
			return -EINVAL;
		}
	} else
		return -EINVAL;
	return (ssize_t)count;
}

void st_set_nfc_single_channel(void)
{
	int ret = -1;
	char single_channel_dts_str[MAX_CONFIG_NAME_SIZE] = {0};

	memset(single_channel_dts_str, 0, MAX_CONFIG_NAME_SIZE);
	ret = nfc_get_dts_config_string("st_nfc_single_channel", "st_nfc_single_channel",
		single_channel_dts_str, sizeof(single_channel_dts_str));

	if (ret != 0) {
		memset(single_channel_dts_str, 0, MAX_CONFIG_NAME_SIZE);
		pr_err("%s: can't get nfc single channel dts config\n", __func__);
		g_nfc_single_channel = 0;
		return;
	}
	if (!strcasecmp(single_channel_dts_str, "true")) {
		g_nfc_single_channel = 1;
	}
	pr_err("%s: nfc single channel:%d\n", __func__, g_nfc_single_channel);
}

void st_set_nfc_card_num(void)
{
	int ret = nfc_get_dts_config_u32("st_nfc_card_num", "st_nfc_card_num", &g_nfc_card_num);
	if (ret != 0) {
		g_nfc_card_num = 1;
		pr_err("%s: can't get nfc card num config!\n", __func__);
	}
}

static ssize_t nfc_card_num_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d\n", (unsigned char)g_nfc_card_num));
}

static ssize_t nfc_chip_type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return (ssize_t)(snprintf(buf, strlen(g_nfc_chip_type)+1, "%s", g_nfc_chip_type));
}

static ssize_t nfc_svdd_sw_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	int val = 0;

	if (sscanf(buf, "%1d", &val) == 1) {
		switch (val) {
		default:
			pr_err("%s: svdd switch error, val:%d[0:pulldown, 1:pullup]\n", __func__, val);
			break;
		}
	} else {
		pr_err("%s: val len error\n", __func__);
		return (ssize_t)count;
	}
	pr_err("%s: nfc svdd switch to %d\n", __func__, val);
	return (ssize_t)count;
}

static ssize_t nfc_svdd_sw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int sw_status = 0;
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d", sw_status));
}

static ssize_t rd_nfc_sim_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int status = -1;
	struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev;
	st21nfc_dev = i2c_get_clientdata(i2c_client_dev);
	if (st21nfc_dev == NULL) {
		pr_err("%s:	st21nfc_dev == NULL!\n", __func__);
		return status;
	}
	return (ssize_t)(snprintf(buf, MAX_ATTRIBUTE_BUFFER_SIZE-1, "%d\n", st21nfc_dev->sim_status));
}

void st_set_nfc_chip_type_name(void)
{
	int ret = -1;

	memset(g_nfc_chip_type, 0, MAX_NFC_CHIP_TYPE_SIZE);
	ret = nfc_get_dts_config_string("st_nfc_chip_type", "st_nfc_chip_type",
		g_nfc_chip_type, sizeof(g_nfc_chip_type));

	if (ret != 0) {
		memset(g_nfc_chip_type, 0, MAX_NFC_CHIP_TYPE_SIZE);
		pr_err("%s: can't get nfc st_nfc_chip_type, default pn547\n", __func__);
		strcpy(g_nfc_chip_type, "st21nfc");
	}

	pr_err("%s: nfc chip type name:%s\n", __func__, g_nfc_chip_type);
}

static struct device_attribute pn547_attr[] = {
	__ATTR(nfc_fwupdate, 0664, nfc_fwupdate_show, nfc_fwupdate_store),
	__ATTR(nxp_config_name, 0664, nxp_config_name_show, nxp_config_name_store),
	__ATTR(nfc_brcm_conf_name, 0664, nfc_brcm_conf_name_show, nfc_brcm_conf_name_store),
	__ATTR(nfc_sim_switch, 0664, nfc_sim_switch_show, nfc_sim_switch_store),
	__ATTR(nfc_sim_status, 0444, nfc_sim_status_show, NULL),
	__ATTR(rd_nfc_sim_status, 0444, rd_nfc_sim_status_show, NULL),
	__ATTR(nfc_enable_status, 0664, nfc_enable_status_show, nfc_enable_status_store),
	__ATTR(nfc_card_num, 0444, nfc_card_num_show, NULL),
	__ATTR(nfc_chip_type, 0444, nfc_chip_type_show, NULL),
	__ATTR(nfc_fw_version, 0444, nfc_fw_version_show, NULL),
	__ATTR(nfcservice_lock, 0664, nfcservice_lock_show, nfcservice_lock_store),
	__ATTR(nfc_svdd_sw, 0664, nfc_svdd_sw_show, nfc_svdd_sw_store),
	__ATTR(nfc_close_type, 0664, nfc_close_type_show, nfc_close_type_store),
	__ATTR(nfc_single_channel, 0444, nfc_single_channel_show, NULL),
	__ATTR(nfc_wired_ese_type, 0444, nfc_wired_ese_info_show, nfc_wired_ese_info_store),
	__ATTR(nfc_activated_se_info, 0664, nfc_activated_se_info_show, nfc_activated_se_info_store),
	__ATTR(nfc_hal_dmd, 0664, nfc_hal_dmd_info_show, nfc_hal_dmd_info_store),
	__ATTR(nfc_calibration, 0444, nfc_calibration_show, NULL),
	__ATTR(nfc_clk_src, 0444, nfc_clk_src_show, NULL),
	__ATTR(nfc_at_result, 0664, nfc_at_result_show, nfc_at_result_store),
	__ATTR(nfc_switch_state, 0664, nfc_switch_state_show, nfc_switch_state_store),
	__ATTR(nfc_ese_num, 0444, nfc_ese_num_show, NULL),
	__ATTR(nfc_recovery_close_nfc, 0664, nfc_recovery_close_nfc_show, nfc_recovery_close_nfc_store),
	__ATTR(st_nfc_get_rssi, 0664, nfc_get_rssi_show, nfc_get_rssi_store),
};

static int create_sysfs_interfaces(struct device *dev)
{
	int i;
	for (i = 0; i < ARRAY_SIZE(pn547_attr); i++) {
		if (device_create_file(dev, pn547_attr + i)) {
			goto ERROR;
		}
	}

	return 0;

ERROR:
	for ( ; i >= 0; i--) {
		device_remove_file(dev, pn547_attr + i);
	}

	pr_err("%s:pn547 unable to create sysfs interface.\n", __func__);
	return -1;
}

static int st21nfc_loc_set_polaritymode(struct st21nfc_dev *st21nfc_dev,
					int mode)
{

	struct i2c_client *client = st21nfc_dev->platform_data.client;
	unsigned int irq_type;
	int ret;

	st21nfc_dev->platform_data.polarity_mode = mode;
	/* setup irq_flags */
	switch (mode) {
	case IRQF_TRIGGER_RISING:
		irq_type = IRQ_TYPE_EDGE_RISING;
		st21nfc_dev->platform_data.active_polarity = 1;
		break;
	case IRQF_TRIGGER_FALLING:
		irq_type = IRQ_TYPE_EDGE_FALLING;
		st21nfc_dev->platform_data.active_polarity = 0;
		break;
	case IRQF_TRIGGER_HIGH:
		irq_type = IRQ_TYPE_LEVEL_HIGH;
		st21nfc_dev->platform_data.active_polarity = 1;
		break;
	case IRQF_TRIGGER_LOW:
		irq_type = IRQ_TYPE_LEVEL_LOW;
		st21nfc_dev->platform_data.active_polarity = 0;
		break;
	default:
		irq_type = IRQF_TRIGGER_FALLING;
		st21nfc_dev->platform_data.active_polarity = 0;
		break;
	}
	if (irqIsAttached) {
		free_irq(client->irq, st21nfc_dev);
		irqIsAttached = false;
	}
	/*
	 * request irq.  the irq is set whenever the chip has data available
	 * for reading.  it is cleared when all data has been read.
	 */
	pr_debug("%s : requesting IRQ %d\n", __func__, client->irq);
	st21nfc_dev->irq_enabled = true;

	ret = request_irq(client->irq, st21nfc_dev_irq_handler,
		mode,
		client->name, st21nfc_dev);
	if (!ret)
		irqIsAttached = true;

	return ret;
}

static irqreturn_t st21nfc_dev_irq_handler(int irq, void *dev_id)
{
	struct st21nfc_dev *st21nfc_dev = dev_id;
	st21nfc_disable_irq(st21nfc_dev);

	/*set a wakelock to avoid entering into suspend */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 157)
	if (WAKE_LOCK_TIMEOUT_ENALBE == g_wake_lock_timeout) {
		__pm_wakeup_event(st21nfc_dev->wlock_read, 5 * HZ);
	} else {
		__pm_wakeup_event(st21nfc_dev->wlock_read, 1 * HZ);
	}
#else
	if (WAKE_LOCK_TIMEOUT_ENALBE == g_wake_lock_timeout) {
		__pm_wakeup_event(&st21nfc_dev->wlock_read, 5 * HZ);
	} else {
		__pm_wakeup_event(&st21nfc_dev->wlock_read, 1 * HZ);
	}
#endif

	/* Wake up waiting readers */
	wake_up(&st21nfc_dev->read_wq);

	return IRQ_HANDLED;
}

static ssize_t st21nfc_dev_read(struct file *filp, char __user *buf,
				size_t count, loff_t *offset)
{
	struct st21nfc_dev *st21nfc_dev = container_of(filp->private_data,
						       struct st21nfc_dev,
						       st21nfc_device);
	char tmp[MAX_BUFFER_SIZE] = { 0};
	int ret;
	int pinlev = 0;
	bool isSuccess = false;
	int retry;

	if (count > MAX_BUFFER_SIZE)
		count = MAX_BUFFER_SIZE;

	mutex_lock(&st21nfc_dev->platform_data.read_mutex);
	pinlev = gpio_get_value(st21nfc_dev->platform_data.irq_gpio);

	if (((pinlev > 0) && (st21nfc_dev->platform_data.active_polarity == 0))
	    || ((pinlev == 0) && (st21nfc_dev->platform_data.active_polarity == 1))) {
		hwlog_info("%s: read called but no IRQ, return dummy data,pinlev=0x%x\n",__func__,pinlev);
		memset(tmp, 0x7E, count);
		if (copy_to_user(buf, tmp, count)) {
			hwlog_err("%s : failed to copy to user space\n", __func__);
			ret = -EFAULT;
			goto FAIL;
		}
        mutex_unlock(&st21nfc_dev->platform_data.read_mutex);
		return count;
	}
	hwlog_info("%s: pinlev=0x%x\n",__func__,pinlev);
	memset(tmp, 0x00, sizeof(tmp));
	/* Read data , we have 3 chances*/
	for (retry = 0; retry < NFC_TRY_NUM; retry++) {
	    ret = i2c_master_recv(st21nfc_dev->platform_data.client, tmp, count);
		hwlog_info("%s : retry = %d, data ret = %d, expect count = %3d, header: %02x%02x%02x%02x%02x\n", __func__,
			retry, ret, (int)count, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
		if (ret == (int)count) {
			isSuccess = true;
			break;
		} else {
			hwlog_info("%s : read data try =%d returned %d\n", __func__, retry, ret);
			msleep(1);
		}
	}

	if (false == isSuccess) {
		hwlog_err("%s : i2c_master_recv returned %d\n", __func__, ret);
		ret = -EIO;
	}
	mutex_unlock(&st21nfc_dev->platform_data.read_mutex);

	if (ret < 0) {
		hwlog_err("%s: i2c_master_recv returned %d\n", __func__, ret);
		return ret;
	}
	if (ret > count) {
		hwlog_err("%s: received too many bytes from i2c (%d)\n",
		       __func__, ret);
		return -EIO;
	}
	if (copy_to_user(buf, tmp, ret)) {
		hwlog_err("%s : failed to copy to user space\n", __func__);
		return -EFAULT;
	}
	return ret;

FAIL:
	mutex_unlock(&st21nfc_dev->platform_data.read_mutex);
	return (size_t)ret;
}

static ssize_t st21nfc_dev_write(struct file *filp, const char __user *buf,
				 size_t count, loff_t *offset)
{
	struct st21nfc_dev *st21nfc_dev = NULL;
	char data_buf[MAX_BUFFER_SIZE] = {0};
	char *send_buf = NULL;
	int send_times = 1;
	int send_length = 0;
	int retry, j;
	int ret = -ENOMEM;
	bool isSuccess = false;

	/* max size is 512 */
	if (count > MAX_BUFFER_SIZE)
		count = MAX_BUFFER_SIZE;

	st21nfc_dev = container_of(filp->private_data,
		struct st21nfc_dev, st21nfc_device);
	if (copy_from_user(data_buf, buf, count)) {
		hwlog_err("%s : failed to copy from user space\n", __func__);
		return -EFAULT;
	}
	for (j = 0; j < send_times; j++) {
		send_buf = data_buf;
		send_length = count;
		isSuccess = false;
		/* Send data */
		for(retry = 0; retry < NFC_TRY_NUM; retry++) {
			ret = i2c_master_send(st21nfc_dev->platform_data.client,
				send_buf, send_length);
			hwlog_info("%s : retry = %d, ret = %d, expect count = %3d, header: %02x%02x%02x%02x%02x\n",
				__func__, retry, ret, (int)send_length, send_buf[0],
				send_buf[1], send_buf[2], send_buf[3], send_buf[4]);
			if(ret == (int)send_length) {
				isSuccess = true;
				break;
			} else {
				if (retry > 0)
					hwlog_info("%s : send data retry =%d return %d\n",
						__func__, retry, ret);
				msleep(1);
				continue;
			}
		}
		if (isSuccess == false) {
			hwlog_err("%s : send returned %d\n", __func__, ret);
			ret = -EIO;
		}
	}
	return ret;
}

static int st21nfc_dev_open(struct inode *inode, struct file *filp)
{
	int ret = 0;
	struct st21nfc_dev *st21nfc_dev = NULL;
	if (device_open) {
		ret = -EBUSY;
		pr_err("%s : device already opened ret= %d\n", __func__, ret);
		} else {
		device_open = true;
		st21nfc_dev = container_of(filp->private_data,
						       struct st21nfc_dev,
						       st21nfc_device);

		pr_debug("%s : device_open = %d", __func__, device_open);
		pr_debug("%s : %d,%d ", __func__, imajor(inode), iminor(inode));

		pr_debug("%s: st21nfc_dev ptr %p\n", __func__, st21nfc_dev);
    }
	return ret;
}

static int st21nfc_release(struct inode *inode, struct file *file)
{
	device_open = false;
	pr_debug("%s : device_open  = %d\n", __func__, device_open);
	return 0;
}

static long st21nfc_dev_ioctl(struct file *filp, unsigned int cmd,
			      unsigned long arg)
{
	struct st21nfc_dev *st21nfc_dev = container_of(filp->private_data,
						       struct st21nfc_dev,
						       st21nfc_device);

	int ret = 0;
	int timeout_loop = 0;
	int value;

	switch (cmd) {

	case ST21NFC_SET_POLARITY_FALLING:
		pr_info(" ### ST21NFC_SET_POLARITY_FALLING ###");
		st21nfc_loc_set_polaritymode(st21nfc_dev, IRQF_TRIGGER_FALLING);
		break;

	case ST21NFC_SET_POLARITY_RISING:
		pr_info(" ### ST21NFC_SET_POLARITY_RISING ###");
		st21nfc_loc_set_polaritymode(st21nfc_dev, IRQF_TRIGGER_RISING);
		break;

	case ST21NFC_SET_POLARITY_LOW:
		pr_info(" ### ST21NFC_SET_POLARITY_LOW ###");
		st21nfc_loc_set_polaritymode(st21nfc_dev, IRQF_TRIGGER_LOW);
		break;

	case ST21NFC_SET_POLARITY_HIGH:
		pr_info(" ### ST21NFC_SET_POLARITY_HIGH ###");
		st21nfc_loc_set_polaritymode(st21nfc_dev, IRQF_TRIGGER_HIGH);
		break;

	case ST21NFC_PULSE_RESET:
		// when gpiod_eSE_PWR is HIGH , it means eSE session is ongoing , delay sometime to do Double Pulse Request
		do {
			value = gpio_get_value(st21nfc_dev->platform_data.ese_pwr_gpio);
			pr_err("%s eSE_PWR_REQ pin level = %d, count= %d\n", __func__, value, timeout_loop);
			if (value == 0)
				break;

			msleep(5); // wait 5ms
		} while (++timeout_loop < LOOP_TIMEOUT);
		/* Double pulse is done to exit Quick boot mode.*/
		pr_err("%s Double Pulse Request,reset_gpio=%d\n", __func__,st21nfc_dev->platform_data.reset_gpio);
		if (st21nfc_dev->platform_data.reset_gpio != 0) {
			/* pulse low for 20 millisecs */
			gpio_set_value(st21nfc_dev->platform_data.reset_gpio,
					0);
			pr_err("%s,reset_gpio=%d\n", __func__,gpio_get_value(st21nfc_dev->platform_data.reset_gpio));
			msleep(20);
			gpio_set_value(st21nfc_dev->platform_data.reset_gpio,
					1);
			msleep(10);
			/* pulse low for 20 millisecs */
			gpio_set_value(st21nfc_dev->platform_data.reset_gpio,
					0);
			msleep(20);
			gpio_set_value(st21nfc_dev->platform_data.reset_gpio,
					1);

			pr_err("%s done Double Pulse Request,reset_gpio pin level=%d\n", __func__,gpio_get_value(st21nfc_dev->platform_data.reset_gpio));
		}
		break;

	case ST21NFC_GET_WAKEUP:
		/* deliver state of Wake_up_pin as return value of ioctl */
		ret = gpio_get_value(st21nfc_dev->platform_data.irq_gpio);
		/*
		 * ret shall be equal to 1 if gpio level equals to polarity.
		 * Warning: depending on gpio_get_value implementation,
		 * it can returns a value different than 1 in case of high level
		 */
		if (((ret == 0)
		     && (st21nfc_dev->platform_data.active_polarity == 0))
		    || ((ret > 0)
			&& (st21nfc_dev->platform_data.active_polarity == 1))) {
			ret = 1;
		} else {
			ret = 0;
		}
		hwlog_info("%s get gpio result %d\n", __func__, ret);
		break;
	case ST21NFC_GET_POLARITY:
		ret = st21nfc_dev->platform_data.polarity_mode;
		pr_debug("%s get polarity %d\n", __func__, ret);
		break;
    case ST21NFC_RECOVERY:
        /* For ST21NFCD usage only */
		pr_info("%s Recovery Request\n", __func__);
        if (st21nfc_dev->platform_data.reset_gpio != 0) {
			/* pulse low for 20 millisecs */
			gpio_set_value(st21nfc_dev->platform_data.reset_gpio, 0);
			msleep(10);
			/* during the reset, force IRQ OUT as DH output instead of input in normal usage */
			ret = gpio_direction_output(st21nfc_dev->platform_data.irq_gpio, 1);
			if (ret) {
				pr_err("%s : gpio_direction_output failed\n", __FILE__);
				ret = -ENODEV;
				break;
			}
			gpio_set_value(st21nfc_dev->platform_data.irq_gpio, 1);
			msleep(10);
			gpio_set_value(st21nfc_dev->platform_data.reset_gpio, 1);
			pr_info("%s done Pulse Request\n", __func__);
		}
		msleep(20);
		gpio_set_value(st21nfc_dev->platform_data.irq_gpio, 0);
		msleep(20);
		gpio_set_value(st21nfc_dev->platform_data.irq_gpio, 1);
		msleep(20);
		gpio_set_value(st21nfc_dev->platform_data.irq_gpio, 0);
		msleep(20);
		pr_info("%s Recovery procedure finished\n", __func__);
		ret = gpio_direction_input(st21nfc_dev->platform_data.irq_gpio);
		if (ret) {
			pr_err("%s : gpio_direction_input failed\n", __FILE__);
			ret = -ENODEV;
		}
		break;
	case ST21NFC_SET_RESET_LOW:
		// set reset to low when Vps_io is low.
		pr_info("%s set reset to low\n", __func__);
		gpio_set_value(st21nfc_dev->platform_data.reset_gpio, 0);
		break;
	default:
		pr_err("%s bad ioctl %u\n", __func__, cmd);
		ret = -EINVAL;
		break;
	}

	return ret;
}

static unsigned int st21nfc_poll(struct file *file, poll_table *wait)
{
	struct st21nfc_dev *st21nfc_dev = container_of(file->private_data,
						       struct st21nfc_dev,
						       st21nfc_device);
	unsigned int mask = 0;
	int pinlev = 0;

	/* wait for Wake_up_pin == high  */
	hwlog_info("%s call poll_Wait\n", __func__);
	poll_wait(file, &st21nfc_dev->read_wq, wait);
	pinlev = gpio_get_value(st21nfc_dev->platform_data.irq_gpio);

	if (((pinlev == 0) && (st21nfc_dev->platform_data.active_polarity == 0))
	    || ((pinlev > 0)
		&& (st21nfc_dev->platform_data.active_polarity == 1))) {
		hwlog_info("%s return ready\n", __func__);
		mask = POLLIN | POLLRDNORM;	/* signal data avail */
		st21nfc_disable_irq(st21nfc_dev);
	} else {
		/* Wake_up_pin  is low. Activate ISR  */
		if (!st21nfc_dev->irq_enabled) {
			hwlog_info("%s enable irq\n", __func__);
			st21nfc_enable_irq(st21nfc_dev);
		} else {
			hwlog_info("%s irq already enabled\n", __func__);
		}

	}
	return mask;
}

static const struct file_operations st21nfc_dev_fops = {
	.owner = THIS_MODULE,
	.llseek = no_llseek,
	.read = st21nfc_dev_read,
	.write = st21nfc_dev_write,
	.open = st21nfc_dev_open,
	.poll = st21nfc_poll,
	.release = st21nfc_release,

	.unlocked_ioctl = st21nfc_dev_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = st21nfc_dev_ioctl
#endif
};

static ssize_t st21nfc_show_i2c_addr(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = to_i2c_client(dev);

	if (client != NULL)
		return sprintf(buf, "0x%.2x\n", client->addr);
	return 0;
} /* st21nfc_show_i2c_addr() */

static ssize_t st21nfc_change_i2c_addr(struct device *dev,
				       struct device_attribute *attr,
				       const char *buf, size_t count)
{

	struct st21nfc_dev *data = dev_get_drvdata(dev);
	long new_addr = 0;

	if (data != NULL && data->platform_data.client != NULL) {
		if (!kstrtol(buf, 10, &new_addr)) {
			mutex_lock(&data->platform_data.read_mutex);
			data->platform_data.client->addr = new_addr;
			mutex_unlock(&data->platform_data.read_mutex);
			return count;
		}
		return -EINVAL;
	}
	return 0;
} /* st21nfc_change_i2c_addr() */

static ssize_t st21nfc_version(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%s\n", DRIVER_VERSION);
} /* st21nfc_version */

static DEVICE_ATTR(i2c_addr, S_IRUGO | S_IWUSR, st21nfc_show_i2c_addr,
		   st21nfc_change_i2c_addr);

static DEVICE_ATTR(version, S_IRUGO, st21nfc_version, NULL);

static struct attribute *st21nfc_attrs[] = {
	&dev_attr_i2c_addr.attr,
	&dev_attr_version.attr,
	NULL,
};

static struct attribute_group st21nfc_attr_grp = {
	.attrs = st21nfc_attrs,
};

#ifdef CONFIG_OF
static int nfc_parse_dt(struct device *dev, struct st21nfc_platform_data *pdata)
{
	int r = 0;
	struct device_node *np = dev->of_node;

	np = of_find_compatible_node(NULL, NULL, "st,st21nfc");
	if (IS_ERR_OR_NULL(np)) {
		pr_err("[dsc]%s: cannot find compatible node \"%s\"", __func__, "st,st21nfc");
		return -ENODEV;
	}

	pdata->reset_gpio = of_get_named_gpio(np, "st,reset_gpio", 0);
	if ((!gpio_is_valid(pdata->reset_gpio))) {
		pr_err("[dsc]%s: fail to get reset_gpio\n", __func__);
		return -EINVAL;
	}

	pdata->ese_pwr_gpio = of_get_named_gpio(np, "st,ese_pwr_gpio", 0);
	if ((!gpio_is_valid(pdata->ese_pwr_gpio))) {
		pr_err("[dsc]%s: fail to get ese_pwr_gpio\n", __func__);
		return -EINVAL;
	}

	pdata->irq_gpio = of_get_named_gpio(np, "st,irq_gpio", 0);
	if ((!gpio_is_valid(pdata->irq_gpio))) {
		pr_err("[dsc]%s: fail to get irq_gpio\n", __func__);
		return -EINVAL;
	}

	pdata->polarity_mode = 0;

	pr_err("[dsc]%s : get reset_gpio[%d], irq_gpio[%d], polarity_mode[%d]\n",
	       __func__, pdata->reset_gpio, pdata->irq_gpio, pdata->polarity_mode);

	return r;
}
#else
static int nfc_parse_dt(struct device *dev, struct st21nfc_platform_data *pdata)
{
	return 0;
}
#endif

static int st21nfc_get_resource(struct  st21nfc_dev *pdev,	struct i2c_client *client)
{
	int ret = 0;
	char *nfc_clk_status = NULL;
	ret = of_property_read_string(client->dev.of_node, "clk_status", (const char **)&nfc_clk_status);
	if (ret) {
		pr_err("[%s,%d]:read clk status fail\n", __func__, __LINE__);
		return -ENODEV;
	} else if (!strcmp(nfc_clk_status, "pmu")) {
		pr_err("[%s,%d]:clock source is pmu\n", __func__, __LINE__);
		g_nfc_clk_src = NFC_CLK_SRC_PMU;
	} else if (!strcmp(nfc_clk_status, "xtal")) {
		pr_err("[%s,%d]:clock source is XTAL\n", __func__, __LINE__);
		g_nfc_clk_src = NFC_CLK_SRC_XTAL;
	} else {
		pr_err("[%s,%d]:clock source is cpu by default\n", __func__, __LINE__);
		g_nfc_clk_src = NFC_CLK_SRC_CPU;
	}

	return 0;
}

static int st21nfc_enable_clk(struct	st21nfc_dev *pdev, int enableflg)
{
	int ret = 0;
	pr_err("%s: pmu clk is controlled by clk_req gpio or xtal .\n", __func__);
	g_clk_status_flag = enableflg;

	return ret;
}

static void get_nfc_svdd_sw(void)
{
	char nfc_svdd_sw_str[MAX_DETECT_SE_SIZE] = {0};
	int ret = -1;

	memset(nfc_svdd_sw_str, 0, MAX_DETECT_SE_SIZE);
	ret = nfc_get_dts_config_string("nfc_svdd_sw", "nfc_svdd_sw",
		nfc_svdd_sw_str, sizeof(nfc_svdd_sw_str));

	if (ret != 0) {
		memset(nfc_svdd_sw_str, 0, MAX_DETECT_SE_SIZE);
		g_nfc_svdd_sw = NFC_SWP_WITHOUT_SW;
		pr_err("%s: can't get_nfc_svdd_sw\n", __func__);
	} else {
		g_nfc_svdd_sw = NFC_SWP_WITHOUT_SW;
	}
	pr_info("%s: g_nfc_svdd_sw:%d\n", __func__, g_nfc_svdd_sw);
}

static int st21nfc_pinctrl_lookup_select(struct pinctrl *st21nfc_pinctrl,
	struct pinctrl_state **pin_state, const char *pinctrl_name)
{
	int ret = 0;
	struct pinctrl_state *state;
	state = pinctrl_lookup_state(
			st21nfc_pinctrl, pinctrl_name);
	if (IS_ERR_OR_NULL(state)) {
		ret = PTR_ERR(state);
		pr_err("%s: get %s error: %d\n", __func__, pinctrl_name, ret);
		return -1;
	}

	ret = pinctrl_select_state(st21nfc_pinctrl, state);
	if (ret < 0) {
		pr_err("%s: select %s error: %d\n", __func__, pinctrl_name, ret);
	} else {
		*pin_state = state;
		pr_info("%s: st21nfc select %s success\n", __func__, pinctrl_name);
	}
	return 0;
}

static int st21nfc_pinctrl_init(struct st21nfc_dev * nfc_dev)
{
	int ret = 0;

	nfc_dev->pctrl = devm_pinctrl_get(nfc_dev->dev);
	if (IS_ERR_OR_NULL(nfc_dev->pctrl)) {
		ret = PTR_ERR(nfc_dev->pctrl);
		pr_err("%s: get st21nfc_pinctrl error: %d\n", __func__, ret);
		goto err_pinctrl_get;
	}

	st21nfc_pinctrl_lookup_select(nfc_dev->pctrl,
		&nfc_dev->pinctrl_state_srclkenai, "srclkenai");
	st21nfc_pinctrl_lookup_select(nfc_dev->pctrl,
		&nfc_dev->pinctrl_state_esespics, "esespics");
	st21nfc_pinctrl_lookup_select(nfc_dev->pctrl,
		&nfc_dev->pinctrl_state_esespiclk, "esespiclk");
	st21nfc_pinctrl_lookup_select(nfc_dev->pctrl,
		&nfc_dev->pinctrl_state_esespimo, "esespimo");
	st21nfc_pinctrl_lookup_select(nfc_dev->pctrl,
		&nfc_dev->pinctrl_state_esespimi, "esespimi");
	st21nfc_pinctrl_lookup_select(nfc_dev->pctrl,
		&nfc_dev->pinctrl_state_esepwrreq, "esepwrreq");
	devm_pinctrl_put(nfc_dev->pctrl);

err_pinctrl_get:
	nfc_dev->pctrl = NULL;
	return ret;
}

static int st21nfc_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	int ret;
	int status = -1;
	struct st21nfc_platform_data *platform_data = NULL;
	struct st21nfc_dev *st21nfc_dev = NULL;
	struct gpio_desc *desc = NULL;

	printk("st21nfc_probe\n");

	if (client->dev.of_node) {
		platform_data = devm_kzalloc(&client->dev,
			sizeof(struct st21nfc_platform_data), GFP_KERNEL);
		if (!platform_data) {
			dev_err(&client->dev,
			"nfc-nci prob: Failed to allocate memory\n");
			return -ENOMEM;
		}
		pr_info("%s : Parse st21nfc DTS \n", __func__);
		ret = nfc_parse_dt(&client->dev, platform_data);
		if (ret) {
			return ret;
		}
	} else {
		platform_data = client->dev.platform_data;
		pr_info("%s : No st21nfc DTS \n", __func__);
	}
	if (!platform_data) {
		return -EINVAL;
	}
	dev_dbg(&client->dev,"nfc-nci probe: %s, inside nfc-nci flags = %x\n",
	__func__, client->flags);

	if (platform_data == NULL) {
		dev_err(&client->dev, "nfc-nci probe: failed\n");
		return -ENODEV;
	}

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		pr_err("%s : need I2C_FUNC_I2C\n", __func__);
		return -ENODEV;
	}

	st21nfc_dev = kzalloc(sizeof(*st21nfc_dev), GFP_KERNEL);
	if (st21nfc_dev == NULL) {
		dev_err(&client->dev,
			"failed to allocate memory for module data\n");
		ret = -ENOMEM;
		goto err_exit;
	}

	pr_debug("%s : dev_cb_addr %p\n", __func__, st21nfc_dev);

	get_ext_gpio_type();
	get_nfc_svdd_sw();
	ret = st21nfc_get_resource(st21nfc_dev, client);
	if (ret < 0) {
		pr_err("[%s,%d]:st21nfc probe get resource failed\n", __func__, __LINE__);
	}
	get_wake_lock_timeout();
	get_nfc_wired_ese_type();

	/* store for later use */
	st21nfc_dev->platform_data.irq_gpio = platform_data->irq_gpio;
	st21nfc_dev->platform_data.ena_gpio = platform_data->ena_gpio;
	st21nfc_dev->platform_data.reset_gpio = platform_data->reset_gpio;
	st21nfc_dev->platform_data.ese_pwr_gpio = platform_data->ese_pwr_gpio;
	st21nfc_dev->platform_data.polarity_mode = platform_data->polarity_mode;
	st21nfc_dev->platform_data.client = client;
	st21nfc_dev->dev = &client->dev;

	ret = create_sysfs_interfaces(&client->dev);
	if (ret < 0) {
		pr_err("[%s,%d]:Failed to create_sysfs_interfaces\n", __func__, __LINE__);
		ret = -ENODEV;
		goto err_free_buffer;
	}
	ret = sysfs_create_link(NULL, &client->dev.kobj, "nfc");
	if (ret < 0) {
		pr_err("[%s,%d]:Failed to sysfs_create_link\n", __func__, __LINE__);
		ret = -ENODEV;
		goto err_free_buffer;
	}

	ret = gpio_request(platform_data->irq_gpio, "irq_gpio");
	if (ret) {
		pr_err("%s : gpio_request failed\n", __FILE__);
		ret = -ENODEV;
		goto err_free_buffer;
	}

	desc = gpio_to_desc(platform_data->irq_gpio);
	if (!desc)
	    pr_err("%s : gpio_to_desc for irq_gpio is null!\n", __FILE__);
	if (!gpio_is_valid(platform_data->irq_gpio))
	    pr_err("%s : gpio %d (irq_gpio) is not valid!\n", __FILE__, platform_data->irq_gpio);

	ret = gpio_direction_input(platform_data->irq_gpio);
	if (ret) {
		pr_err("%s : gpio_direction_input failed\n", __FILE__);
		ret = -ENODEV;
		goto err_free_buffer;
	}

	st21nfc_dev->platform_data.client->irq = platform_data->irq_gpio;

	/* initialize irqIsAttached variable */
	irqIsAttached = false;

	/* initialize device_open variable */
	device_open = 0;

	/* handle optional RESET */
	if (platform_data->reset_gpio != 0) {
		ret = gpio_request(platform_data->reset_gpio, "reset_gpio");
		if (ret) {
			pr_err("%s : reset gpio_request failed\n", __FILE__);
			ret = -ENODEV;
			goto err_free_buffer;
		}
		desc = gpio_to_desc(platform_data->reset_gpio);
		if (!desc)
		    pr_err("%s : gpio_to_desc for reset_gpio is null!\n", __FILE__);
		if (!gpio_is_valid(platform_data->reset_gpio))
		    pr_err("%s : gpio %d (reset_gpio) is not valid!\n", __FILE__, platform_data->reset_gpio);

		ret = gpio_direction_output(platform_data->reset_gpio, 1);
		if (ret) {
			pr_err("%s : reset gpio_direction_output failed\n",
			       __FILE__);
			ret = -ENODEV;
			goto err_free_buffer;
		}
	}

	st21nfc_pinctrl_init(st21nfc_dev);

	/* set up optional ENA gpio */
	if (platform_data->ena_gpio != 0) {
		ret = gpio_request(platform_data->ena_gpio, "st21nfc_ena");
		if (ret) {
			pr_err("%s : ena gpio_request failed\n", __FILE__);
			ret = -ENODEV;
			goto err_free_buffer;
		}
		ret = gpio_direction_output(platform_data->ena_gpio, 0);//xinhua
		if (ret) {
			pr_err("%s : ena gpio_direction_output failed\n",
			       __FILE__);
			ret = -ENODEV;
			goto err_free_buffer;
		}
	}
	client->irq = gpio_to_irq(platform_data->irq_gpio);

	enable_irq_wake(client->irq);
	st21nfc_dev->irq_wake_enabled = true;
	ret = nfc_i2c_check(client, st21nfc_dev);
	gpio_set_value(st21nfc_dev->platform_data.reset_gpio, 0);
	if (ret < 0) {
		ret = -ENODEV;
		pr_err("%s : nfc_check_enable failed\n", __FILE__);
		goto err_free_buffer;
	}
	/* init mutex and queues */
	init_waitqueue_head(&st21nfc_dev->read_wq);
	mutex_init(&st21nfc_dev->platform_data.read_mutex);
	mutex_init(&st21nfc_dev->platform_data.irq_wake_mutex);
	spin_lock_init(&st21nfc_dev->irq_enabled_lock);
    pr_err("%s : debug irq_gpio = %d, client-irq =  %d\n", __func__, platform_data->irq_gpio, client->irq);
	st21nfc_dev->st21nfc_device.minor = MISC_DYNAMIC_MINOR;
	st21nfc_dev->st21nfc_device.name = "st21nfc";
	st21nfc_dev->st21nfc_device.fops = &st21nfc_dev_fops;
	st21nfc_dev->st21nfc_device.parent = &client->dev;
    st21nfc_dev->sim_switch = CARD1_SELECT;

	i2c_set_clientdata(client, st21nfc_dev);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 157)
	st21nfc_dev->wlock_read = wakeup_source_register(st21nfc_dev->dev, "nfc_read");
	if (st21nfc_dev->wlock_read == NULL) {
		pr_err("%s: nfc_locker wakeup_source_register error \n", __func__);
		goto err_wakeup_source_create;
	}
#else
	wakeup_source_init(&st21nfc_dev->wlock_read, "nfc_read");
#endif

	ret = misc_register(&st21nfc_dev->st21nfc_device);
	if (ret) {
		pr_err("%s : misc_register failed\n", __FILE__);
		goto err_misc_register;
	}

	if (sysfs_create_group(&client->dev.kobj, &st21nfc_attr_grp)) {
		pr_err("%s : sysfs_create_group failed\n", __FILE__);
		goto err_request_irq_failed;
	}

	pr_info("%s : requesting IRQ %d\n", __func__, client->irq);
	st21nfc_dev->irq_enabled = true;
	ret = request_irq(client->irq, st21nfc_dev_irq_handler, IRQF_TRIGGER_HIGH, client->name, st21nfc_dev);
	if (!ret) {
		irqIsAttached = true;
		pr_info("%s: request_irq OK, irqIsAttached is true!\n", __func__);
	} else {
		dev_err(&client->dev, "request_irq failed\n");
		goto err_request_irq_failed;
	}

	st21nfc_disable_irq(st21nfc_dev);
	st21nfc_enable_clk(st21nfc_dev, 1);
	status = recovery_close_nfc(client, st21nfc_dev);
	if (status < 0)
		pr_err("%s: recovery_close_nfc error!\n", __func__);
	if (platform_data->ena_gpio != 0)
		gpio_set_value(platform_data->ena_gpio, 1);

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
	/* detect current device successful, set the flag as present */
	set_hw_dev_flag(DEV_I2C_NFC);
	pr_info("%s set_hw_dev_flag success.\n", __func__);
#endif
    st_set_nfc_chip_type_name();
	st_set_nfc_single_channel();
	st_set_nfc_card_num();
	st_set_nfc_nxp_config_name();
	st_set_nfc_ese_num();
	if ((st_set_nfc_spi_bus() == 0) && (st_set_nfc_clkreq_gpio() == 0))
		write_conf_to_tee();

	return 0;

err_request_irq_failed:
	misc_deregister(&st21nfc_dev->st21nfc_device);

err_misc_register:
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 157)
	pr_info("%s ++ wakeup_source_unregister\n", __func__);
	wakeup_source_unregister(st21nfc_dev->wlock_read);
#else
	pr_info("%s ++ wakeup_source_trash\n", __func__);
	wakeup_source_trash(&st21nfc_dev->wlock_read);
#endif

err_wakeup_source_create:
	mutex_destroy(&st21nfc_dev->platform_data.read_mutex);
	mutex_destroy(&st21nfc_dev->platform_data.irq_wake_mutex);

err_free_buffer:
	kfree(st21nfc_dev);

err_exit:
	gpio_free(platform_data->irq_gpio);
	if (platform_data->ena_gpio != 0)
		gpio_free(platform_data->ena_gpio);
	return ret;
}

static int st21nfc_remove(struct i2c_client *client)
{
	struct st21nfc_dev *st21nfc_dev;

	st21nfc_dev = i2c_get_clientdata(client);
	free_irq(client->irq, st21nfc_dev);
	misc_deregister(&st21nfc_dev->st21nfc_device);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 157)
	pr_info("%s ++ wakeup_source_unregister\n", __func__);
	wakeup_source_unregister(st21nfc_dev->wlock_read);
#else
	pr_info("%s ++ wakeup_source_trash\n", __func__);
	wakeup_source_trash(&st21nfc_dev->wlock_read);
#endif
	mutex_destroy(&st21nfc_dev->platform_data.read_mutex);
	mutex_destroy(&st21nfc_dev->platform_data.irq_wake_mutex);
	gpio_free(st21nfc_dev->platform_data.irq_gpio);
	if (st21nfc_dev->platform_data.ena_gpio != 0)
		gpio_free(st21nfc_dev->platform_data.ena_gpio);
	kfree(st21nfc_dev);

	return 0;
}

static int st21nfc_suspend(struct device *dev)
{
	int pinlev, count;
	unsigned char recv_buf[NFC_REC_LEN] = {0};
	struct i2c_client *client = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev = i2c_get_clientdata(client);
	if (!device_open) {
		count = 0;
		pinlev = gpio_get_value(st21nfc_dev->platform_data.irq_gpio);
		hwlog_info("%s: pinlev=0x%x\n", __func__, pinlev);
		while (pinlev == 1 && count < MAX_COUNT) {
			(void)st_i2c_read(st21nfc_dev, recv_buf, NFC_REC_LEN);
			msleep(20); // WAIT 20ms
			pinlev = gpio_get_value(st21nfc_dev->platform_data.irq_gpio);
			count++;
		}
	}

	st21nfc_enable_irq(st21nfc_dev);
	st21nfc_enable_irq_wake(st21nfc_dev);
	hwlog_info("%s st21nfc_enable_irq_wake success.\n", __func__);
	return 0;
}

static int st21nfc_resume(struct device *dev)
{
	struct i2c_client *client = container_of(dev, struct i2c_client, dev);
	struct st21nfc_dev *st21nfc_dev = i2c_get_clientdata(client);

	st21nfc_disable_irq_wake(st21nfc_dev);
	st21nfc_disable_irq(st21nfc_dev);
	hwlog_info("%s st21nfc_disable_irq_wake success.\n", __func__);
	return 0;
}

static const struct dev_pm_ops st21nfc_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(st21nfc_suspend, st21nfc_resume)
};

static const struct i2c_device_id st21nfc_id[] = {
	{"st21nfc", 0},
	{}
};

static struct of_device_id st21nfc_of_match[] = {
	{ .compatible = "st,st21nfc", },  //it's same as the compatible of nfc in dts.
	{}
};

// MODULE_DEVICE_TABLE(of, st21nfc_of_match);
static struct i2c_driver st21nfc_driver = {
	.id_table = st21nfc_id,
	.driver = {
		.name	= "st21nfc",
		.owner	= THIS_MODULE,
		.pm = &st21nfc_pm_ops,
		.of_match_table	= st21nfc_of_match,
	},
	.probe		= st21nfc_probe,
	.remove		= st21nfc_remove,
};

/*
 * module load/unload record keeping
 */
static int __init st21nfc_dev_init(void)
{
	printk("%s: Loading st21nfc driver\n", __func__);
	return i2c_add_driver(&st21nfc_driver);
}

module_init(st21nfc_dev_init);

static void __exit st21nfc_dev_exit(void)
{
	pr_debug("Unloading st21nfc driver\n");
	i2c_del_driver(&st21nfc_driver);
}

/*lint -restore*/
/*
 * g_nfc_ext_gpio bit 0: 1 -- dload use extented gpio, 0 -- dload use soc gpio
 * g_nfc_ext_gpio bit 1: 1 -- irq use extented gpio, 0 -- irq use soc gpio
 */
 /*lint -save -e* */
static void get_ext_gpio_type(void)
{
	g_nfc_ext_gpio = 0;
	pr_err("%s: g_nfc_ext_gpio:%d\n", __func__, g_nfc_ext_gpio);
}

/*lint -save -e* */
EXPORT_SYMBOL(gpio_get_value);
static void get_wake_lock_timeout(void)
{
	char wake_lock_str[MAX_WAKE_LOCK_TIMEOUT_SIZE] = {0};
	int ret = -1;

	memset(wake_lock_str, 0, MAX_WAKE_LOCK_TIMEOUT_SIZE);
	ret = nfc_get_dts_config_string("wake_lock_timeout", "wake_lock_timeout",
	wake_lock_str, sizeof(wake_lock_str));

	if (ret != 0) {
		memset(wake_lock_str, 0, MAX_WAKE_LOCK_TIMEOUT_SIZE);
		g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_DISABLE;
		hwlog_err("%s: can't find wake_lock_timeout node, g_wake_lock_timeout default value is WAKE_LOCK_TIMEOUT_DISABLE\n", __func__);
		return;
	} else {
		if (!strncasecmp(wake_lock_str, "ok", strlen("ok"))) {
			g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_ENALBE;
		} else {
			g_wake_lock_timeout = WAKE_LOCK_TIMEOUT_DISABLE;
		}
	}
	hwlog_info("%s: g_wake_lock_timeout:%d\n", __func__, g_wake_lock_timeout);
	return;
}

static int nfc_get_dts_config_string(const char *node_name,
				const char *prop_name,
				char *out_string,
				int out_string_len)
{
	struct device_node *np = NULL;
	const char *out_value = NULL;
	int ret = -1;

	for_each_node_with_property(np, node_name) {
		ret = of_property_read_string(np, prop_name, (const char **)&out_value);
		if (ret != 0) {
			pr_info("%s: can not get prop values with prop_name: %s\n",
							__func__, prop_name);
		} else {
			if (NULL == out_value) {
				pr_info("%s: error out_value = NULL\n", __func__);
				ret = -1;
			} else if (strlen(out_value) >= out_string_len) {
			pr_info("%s: error out_value len :%d >= out_string_len:%d\n",
					__func__, (int)strlen(out_value), (int)out_string_len);
				ret = -1;
			} else {
				strncpy(out_string, out_value, strlen(out_value));
				pr_info("%s: =%s\n", __func__, out_string);
			}
		}
	}
	return ret;
}

static void get_nfc_wired_ese_type(void)
{
	char nfc_on_str[MAX_DETECT_SE_SIZE] = {0};
	int ret = -1;

	memset(nfc_on_str, 0, MAX_DETECT_SE_SIZE);
	ret = nfc_get_dts_config_string("st_nfc_ese_type", "st_nfc_ese_type",
	nfc_on_str, sizeof(nfc_on_str));

	if (ret != 0) {
		memset(nfc_on_str, 0, MAX_DETECT_SE_SIZE);
		g_nfc_ese_type = NFC_WITHOUT_ESE;
		pr_err("%s: can't find st_nfc_ese_type node, g_nfc_ese_type value is default value NFC_WITHOUT_ESE\n", __func__);
		return;
	} else {
		g_nfc_ese_type = NFC_WITHOUT_ESE;
	}
	pr_err("%s: g_nfc_ese_type:%d\n", __func__, g_nfc_ese_type);
}

module_exit(st21nfc_dev_exit);

MODULE_AUTHOR("Norbert Kawulski");
MODULE_DESCRIPTION("NFC ST21NFC driver");
MODULE_VERSION(DRIVER_VERSION);
MODULE_LICENSE("GPL");