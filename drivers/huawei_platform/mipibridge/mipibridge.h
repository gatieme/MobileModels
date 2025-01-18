/*
 * mipibridge.h
 *
 * interface for huawei mipibridge driver
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#ifndef _MIPIBRIDGE_H_
#define _MIPIBRIDGE_H_
#include <linux/kernel.h>
#include <linux/types.h>
#include <securec.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/sysfs.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <asm/ioctls.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/err.h>
#include <linux/mutex.h>
#include <linux/vmalloc.h>
#include <linux/jiffies.h>
#include <linux/completion.h>
#include <linux/firmware.h>
#include <linux/workqueue.h>
#include <linux/spi/spi.h>
#include <linux/time.h>
#include <linux/amba/pl022.h>
#include <linux/semaphore.h>

/* success or fail */
#define MIPI_BRIDGE_OK 0
#define MIPI_BRIDGE_FAIL -1

/* log level */
#define MIPIBRIDGE_LOG_FLOW 2
#define MIPIBRIDGE_LOG_INFO 1
#define MIPIBRIDGE_LOG_WARN 0
#define MIPIBRIDGE_LOG_ERR 0

int mipibridge_log_level(void);
#define mipibridge_flowmsg(fmt, args...) \
do { \
	if (mipibridge_log_level() >= MIPIBRIDGE_LOG_FLOW) \
		printk(KERN_INFO "mipibridge:%s:" fmt, __FUNCTION__, ##args); \
} while (0)

#define mipibridge_infomsg(fmt, args...) \
do { \
	if (mipibridge_log_level() >= MIPIBRIDGE_LOG_INFO) \
		printk(KERN_INFO "mipibridge:%s:" fmt, __FUNCTION__, ##args); \
} while (0)

#define mipibridge_warnmsg(fmt, args...) \
do { \
	if (mipibridge_log_level() >= MIPIBRIDGE_LOG_WARN) \
		printk(KERN_INFO "mipibridge:%s:" fmt, __FUNCTION__, ##args); \
} while (0)

#define mipibridge_errmsg(fmt, args...) \
do { \
	if (mipibridge_log_level() >= MIPIBRIDGE_LOG_ERR) \
		printk(KERN_ERR "mipibridge:%s:" fmt, __FUNCTION__, ##args); \
} while (0)

/* device */
#define PANEL_HV6100 "hv6100"
#define PANEL_UG1009 "ug1009"

/* bit ops */
#define SHIFT_8 8
#define SHIFT_16 16
#define SHIFT_24 24
#define LOWER_8_BITS(x) (((x) & 0xff))
#define LOWER_16_BITS(x) (((x) & 0xffff))
#define FOUR_U8_TO_U32(a, b, c ,d) ((u8)(a) << SHIFT_24 | (u8)(b) << SHIFT_16 | (u8)(c) << SHIFT_8 | (u8)(d))

enum {
	FIRMWARE_UPGRADE_DEFAUL = 0,
	FIRMWARE_UPGRADE_SUCC,
	FIRMWARE_UPGRADE_OLD,
	FIRMWARE_UPGRADE_DOING,
	FIRMWARE_UPGRADE_FAIL,
	FIRMWARE_NOT_FIND_FW,
	FIRMWARE_ERROR_FW,
	FIRMWARE_UPGRADE_SPI_ERR,
	FIRMWARE_UPGRADE_CHECK_OK,
};

enum {
	UPGRADE_MODE_NORAML_UPGRADE = 1,
};

enum {
	UPGRADE_FLASH_ERASE_ERR = 0,
	UPGRADE_FLASH_WRITE_ERR,
	UPGRADE_FLASH_SUCC,
	UPGRADE_FLASH_MAX,
};

struct mipibridge_uart
{
	u32 support;
	const char *tty_name;
	u32 default_baud;
	u32 uart_recv_support;
	void (*recv_fuc)(u8 *recv_buff, unsigned int len);
	struct delayed_work recv_work;
	struct semaphore sem;
};

struct mipibridge_fw_upd_time {
	ktime_t start;
	ktime_t end;
	s64 actual_time;
};

struct mipibridge_fw {
	u32 support;
	u32 status;
	struct work_struct upgrade_work;
	int (*fw_update)(struct device *dev);
	int (*open_fw)(struct device *dev);
	struct mipibridge_fw_upd_time time;
};

struct mipibridge_device_info {
	struct device *dev;
	const char *device;
	u32 id_pin;
	struct mipibridge_uart uart;
	struct mipibridge_fw fw;
};

struct mipibridge_panel_map {
	char *device;
	int (*callback)(struct mipibridge_device_info *di);
};

int mipibridge_parse_u32(const struct device_node *np, const char *prop_name,
	unsigned int *out, unsigned int def);
int mipibridge_uart_recv_enable(int want_len);
int mipibridge_uart_read(u8 *buf, size_t *len, int time_out, int want_len);
int mipibridge_uart_write(u8 *buf, size_t len);
int mipibridge_uart_register(struct mipibridge_uart *uart);
int mipibridge_set_spi_freq_and_mode(u32 max_speed_hz, u32 mode);
int mipibridge_spi_send_transfer(uint8_t *wdata, unsigned int wlen);
int mipibridge_spi_recive_transfer(uint8_t cmd, uint8_t *rbuf, unsigned int rlen);
int mipibridge_spi_send_and_receive_transfer(uint8_t *wdata, unsigned int wlen, uint8_t *rbuf, unsigned int rlen);

#endif /* _MIPIBRIDGE_H_ */
