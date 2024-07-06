/* Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/regmap.h>
#include <linux/debugfs.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/pm.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/of_graph.h>
#include <linux/kthread.h>
#include <securec.h>
#include "ti983_ser_config.h"
#include "ti_deser_config.h"
#include "log.h"
#include "drv_mcu.h"
#include "lcd_sysfs.h"
#include "lcd_sysfs_for_dp.h"

static uint32_t g_ivi_last_backlight = 0;
static struct i2c_client *g_ti983_client;

static ssize_t ser1_pattern_test_port0(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = g_ti983_client;

	sysfs_info("enter");
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x40, 0x30);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x41, 0x29);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x42, 0x08);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x41, 0x28);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x42, 0x95);

	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x41, 0x69);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x42, 0x08);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x41, 0x68);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, 0x42, 0x95);
	sysfs_info("finish");

	return strlen(buf);
}

static ssize_t ser2_pattern_test_port0(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = g_ti983_client;

	sysfs_info("enter");
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x40, 0x30);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x41, 0x29);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x42, 0x08);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x41, 0x28);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x42, 0x95);

	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x41, 0x69);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x42, 0x08);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x41, 0x68);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, 0x42, 0x95);
	sysfs_info("finish");

	return strlen(buf);
}

static ssize_t deser_pattern_test_port0(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = g_ti983_client;
	sysfs_info("enter");
	i2c_write_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_PASSENGER_ALIAS, 0x40, 0x50);
	i2c_write_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_PASSENGER_ALIAS, 0x41, 0x00);
	i2c_write_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_PASSENGER_ALIAS, 0x42, 0x95);
	sysfs_info("finish");

	return strlen(buf);
}

static ssize_t ser1_main_regs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int i = 0;
	int ret = 0;
	unsigned char reg_value = 0;
	struct i2c_client *client = g_ti983_client;

	if (buf == NULL) {
		sysfs_err("buff is null\n");
		return -EINVAL;
	}
	ret = memset_s(buf, sizeof(buf), 0, PAGE_SIZE);
	if (ret != 0)
		sysfs_err("memset_s error");

	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "[main_reg_list:]\n");
	if (ret < 0)
		sysfs_err("ser main_reg_list printf err");

	for (i = 0; i <= SER_MAIN_REG_MAXCNT; i++) {
		i2c_read_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, i, &reg_value);

		if ((i + 1) % COLUMN_NUM == 0) {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x\n", i, reg_value);
			if (ret < 0)
				sysfs_err("ser main regs show err for column");
		} else {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x", i, reg_value);
			if (ret < 0)
				sysfs_err("ser main regs show err");
		}
	}
	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "\n");
	if (ret < 0)
		sysfs_err("ser main regs show err for last page");
	sysfs_info("%s\n", buf);

	return strlen(buf);
}

// [reg_addr]:[reg_val]
static ssize_t ser1_main_regs_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int reg_addr = 0;
	unsigned int reg_val = 0;
	int ret = -1;
	char *p = NULL;
	char reg_buf[REG_BUF_LEN];
	struct i2c_client *client = g_ti983_client;

	ret = memset_s(reg_buf, sizeof(reg_buf), 0, REG_BUF_LEN);
	if (ret != 0)
		sysfs_err("memset_s error");

	p = strchr(buf, ':');
	if (p == NULL) {
		sysfs_err("err:can not find '!'\n");
		return -EINVAL;
	}
	ret = memcpy_s(reg_buf, sizeof(reg_buf), buf, p - buf);
	if (ret != 0)
		sysfs_err("memcpy_s error");

	ret = kstrtoint(reg_buf, HEXADECIMAL, &reg_addr);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}

	if (reg_addr > SER_MAIN_REG_MAXCNT) {
		sysfs_err("err:your input [] is too big!\n");
		return -EINVAL;
	}

	ret = kstrtoint(p + 1, HEXADECIMAL, &reg_val);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}

	sysfs_err("reg[0x%x] = 0x%x\n", reg_addr, reg_val);
	i2c_write_reg(client->adapter, DS90UB983_SER1_I2C_7BIT_ADDR, reg_addr, reg_val);

	return count;
}

static ssize_t ser2_main_regs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int i = 0;
	int ret = 0;
	unsigned char reg_value = 0;
	struct i2c_client *client = g_ti983_client;

	if (buf == NULL) {
		sysfs_err("buff is null\n");
		return -EINVAL;
	}
	ret = memset_s(buf, sizeof(buf), 0, PAGE_SIZE);
	if (ret != 0)
		sysfs_err("memset_s error");

	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "[main_reg_list:]\n");
	if (ret < 0)
		sysfs_err("ser main_reg_list printf err");

	for (i = 0; i <= SER_MAIN_REG_MAXCNT; i++) {
		i2c_read_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, i, &reg_value);

		if ((i + 1) % COLUMN_NUM == 0) {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x\n", i, reg_value);
			if (ret < 0)
				sysfs_err("ser main regs show err for column");
		} else {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x", i, reg_value);
			if (ret < 0)
				sysfs_err("ser main regs show err");
		}
	}
	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "\n");
	if (ret < 0)
		sysfs_err("ser main regs show err for last page");
	sysfs_info("%s\n", buf);

	return strlen(buf);
}

// [reg_addr]:[reg_val]
static ssize_t ser2_main_regs_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int reg_addr = 0;
	unsigned int reg_val = 0;
	int ret = -1;
	char *p = NULL;
	char reg_buf[REG_BUF_LEN];
	struct i2c_client *client = g_ti983_client;

	ret = memset_s(reg_buf, sizeof(reg_buf), 0, REG_BUF_LEN);
	if (ret != 0)
		sysfs_err("memset_s error");

	p = strchr(buf, ':');
	if (p == NULL) {
		sysfs_err("err:can not find '!'\n");
		return -EINVAL;
	}
	ret = memcpy_s(reg_buf, sizeof(reg_buf), buf, p - buf);
	if (ret != 0)
		sysfs_err("memcpy_s error");

	ret = kstrtoint(reg_buf, HEXADECIMAL, &reg_addr);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}

	if (reg_addr > SER_MAIN_REG_MAXCNT) {
		sysfs_err("err:your input [] is too big!\n");
		return -EINVAL;
	}

	ret = kstrtoint(p + 1, HEXADECIMAL, &reg_val);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}
	sysfs_info("reg[0x%x] = 0x%x\n", reg_addr, reg_val);
	i2c_write_reg(client->adapter, DS90UB983_SER2_I2C_7BIT_ADDR, reg_addr, reg_val);

	return count;
}

static ssize_t deser_passanger_main_regs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int i = 0;
	unsigned char reg_value = 0;
	struct i2c_client *client = g_ti983_client;
	int ret = 0;

	if (buf == NULL) {
		sysfs_err("buff is null\n");
		return -EINVAL;
	}
	ret = memset_s(buf, sizeof(buf), 0, PAGE_SIZE);
	if (ret != 0)
		sysfs_err("memset_s error");

	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
		PAGE_SIZE - strlen(buf), "[main_reg_list:]\n");
	if (ret < 0)
		sysfs_err("deser main_reg_list printf err");

	for (i = 0; i <= SER_MAIN_REG_MAXCNT; i++) {
		i2c_read_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_PASSENGER_ALIAS, i, &reg_value);

		if ((i + 1) % COLUMN_NUM == 0) {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x\n", i, reg_value);
			if (ret < 0)
				sysfs_err("dser main regs show err for column");
		} else {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x", i, reg_value);
			if (ret < 0)
				sysfs_err("dser main regs show err");
		}
	}
	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "\n");
	if (ret < 0)
		sysfs_err("dser main regs show err for last page");
	sysfs_info("%s\n", buf);

	return strlen(buf);
}

// [reg_addr]:[reg_val]
static ssize_t deser_passanger_main_regs_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	unsigned int reg_addr = 0;
	unsigned int reg_val = 0;
	int ret = -1;
	char *p = NULL;
	char reg_buf[REG_BUF_LEN];
	struct i2c_client *client = g_ti983_client;

	ret = memset_s(reg_buf, sizeof(reg_buf), 0, REG_BUF_LEN);
	if (ret != 0)
		sysfs_err("memset_s error");

	p = strchr(buf, ':');
	if (p == NULL) {
		sysfs_err("err:can not find '!'\n");
		return -EINVAL;
	}
	ret = memcpy_s(reg_buf, sizeof(reg_buf), buf, p - buf);
	if (ret != 0)
		sysfs_err("memcpy_s error");

	ret = kstrtoint(reg_buf, HEXADECIMAL, &reg_addr);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}

	if (reg_addr > SER_MAIN_REG_MAXCNT) {
		sysfs_err("err:your input [] is too big!\n");
		return -EINVAL;
	}

	ret = kstrtoint(p + 1, HEXADECIMAL, &reg_val);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}
	sysfs_info("reg[0x%x] = 0x%x\n", reg_addr, reg_val);
	i2c_write_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_PASSENGER_ALIAS, reg_addr, reg_val);

	return count;
}

static ssize_t deser_arhud_main_regs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int i = 0;
	unsigned char reg_value = 0;
	struct i2c_client *client = g_ti983_client;
	int ret = 0;

	if (buf == NULL) {
		sysfs_err("buff is null\n");
		return -EINVAL;
	}
	ret = memset_s(buf, sizeof(buf), 0, PAGE_SIZE);
	if (ret != 0)
		sysfs_err("memset_s error");

	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "[main_reg_list:]\n");
	if (ret < 0)
		sysfs_err("deser main_reg_list printf err");

	for (i = 0; i <= SER_MAIN_REG_MAXCNT; i++) {
		i2c_read_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_SMART_ALIAS, i, &reg_value);

		if ((i + 1) % COLUMN_NUM == 0) {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x\n", i, reg_value);
			if (ret < 0)
				sysfs_err("dser main regs show err for column");
		} else {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x", i, reg_value);
			if (ret < 0)
				sysfs_err("dser main regs show err");
		}
	}
	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "\n");
	if (ret < 0)
		sysfs_err("dser main regs show err for last page");

	sysfs_info("%s\n", buf);

	return strlen(buf);
}

// [reg_addr]:[reg_val]
static ssize_t deser_arhud_main_regs_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	unsigned int reg_addr = 0;
	unsigned int reg_val = 0;
	int ret = -1;
	char *p = NULL;
	char reg_buf[REG_BUF_LEN];
	struct i2c_client *client = g_ti983_client;

	ret = memset_s(reg_buf, sizeof(reg_buf), 0, REG_BUF_LEN);
	if (ret != 0)
		sysfs_err("memset_s error");

	p = strchr(buf, ':');
	if (p == NULL) {
		sysfs_err("err:can not find '!'\n");
		return -EINVAL;
	}
	ret = memcpy_s(reg_buf, sizeof(reg_buf), buf, p - buf);
	if (ret != 0)
		sysfs_err("memcpy_s error");

	ret = kstrtoint(reg_buf, HEXADECIMAL, &reg_addr);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}

	if (reg_addr > SER_MAIN_REG_MAXCNT) {
		sysfs_err("err:your input [] is too big!\n");
		return -EINVAL;
	}

	ret = kstrtoint(p + 1, HEXADECIMAL, &reg_val);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}
	sysfs_info("reg[0x%x] = 0x%x\n", reg_addr, reg_val);
	i2c_write_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_SMART_ALIAS, reg_addr, reg_val);

	return count;
}

static ssize_t deser_maxview_main_regs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int i = 0;
	unsigned char reg_value = 0;
	struct i2c_client *client = g_ti983_client;
	int ret = 0;

	if (buf == NULL) {
		sysfs_err("buff is null\n");
		return -EINVAL;
	}
	ret = memset_s(buf, sizeof(buf), 0, PAGE_SIZE);
	if (ret != 0)
		sysfs_err("memset_s error");

	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "[main_reg_list:]\n");
	if (ret < 0)
		sysfs_err("deser main_reg_list printf err");

	for (i = 0; i <= SER_MAIN_REG_MAXCNT; i++) {
		i2c_read_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_METER_ALIAS, i, &reg_value);

		if ((i + 1) % COLUMN_NUM == 0) {
			ret = snprintf_s(
				buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "0x%02x--0x%02x\n", i, reg_value);
			if (ret < 0)
				sysfs_err("dser main regs show err for column");
		} else {
			ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf),
				PAGE_SIZE - strlen(buf), "0x%02x--0x%02x", i, reg_value);
			if (ret < 0)
				sysfs_err("dser main regs show err");
		}
	}
	ret = snprintf_s(buf + strlen(buf), PAGE_SIZE - strlen(buf), PAGE_SIZE - strlen(buf), "\n");
	if (ret < 0)
		sysfs_err("dser main regs show err for last page");
	sysfs_info("%s\n", buf);

	return strlen(buf);
}

// [reg_addr]:[reg_val]
static ssize_t deser_maxview_main_regs_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	unsigned int reg_addr = 0;
	unsigned int reg_val = 0;
	int ret = -1;
	char *p = NULL;
	char reg_buf[REG_BUF_LEN];
	struct i2c_client *client = g_ti983_client;

	ret = memset_s(reg_buf, sizeof(reg_buf), 0, REG_BUF_LEN);
	if (ret != 0)
		sysfs_err("memset_s error");

	p = strchr(buf, ':');
	if (p == NULL) {
		sysfs_err("err:can not find '!'\n");
		return -EINVAL;
	}
	ret = memcpy_s(reg_buf, sizeof(reg_buf), buf, p - buf);
	if (ret != 0)
		sysfs_err("memcpy_s error");

	ret = kstrtoint(reg_buf, HEXADECIMAL, &reg_addr);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}

	if (reg_addr > SER_MAIN_REG_MAXCNT) {
		sysfs_err("err:your input [] is too big!\n");
		return -EINVAL;
	}

	ret = kstrtoint(p + 1, HEXADECIMAL, &reg_val);
	if (ret != 0) {
		sysfs_err("err: kstrtoint failed!\n");
		return -EINVAL;
	}
	sysfs_info("reg[0x%x] = 0x%x\n", reg_addr, reg_val);
	i2c_write_reg(client->adapter, DS90UH988_I2C_7BIT_ADDR_METER_ALIAS, reg_addr, reg_val);

	return count;
}

static ssize_t ser_brightness_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct i2c_client *client = g_ti983_client;
	int ret = 0;
	int brightness = 0;

	ret = kstrtoint(buf, DECIMAL, &brightness);
	if (ret != 0) {
		sysfs_err("%s err: kstrtoint failed!", buf);
		return -EINVAL;
	}

	ret = set_backlight_to_smart_panel(g_ti983_client, brightness);
	if (ret < 0)
		sysfs_err("set backlight brightness to %d failed", brightness);
	g_ivi_last_backlight = brightness;
	sysfs_info("set backlight brightness to %d", brightness);

	return count;
}

static ssize_t ser_brightness_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct i2c_client *client = g_ti983_client;
	int ret = 0;
	int brightness = 0;

	if (buf == NULL) {
		sysfs_err("buff is null\n");
		return -EINVAL;
	}
	ret = memset_s(buf, PAGE_SIZE, 0, PAGE_SIZE);
	if (ret != 0)
		sysfs_err("memset_s error");

	brightness = get_backlight_from_smart_panel(g_ti983_client);
	if (brightness < 0)
		sysfs_err("get backlight from mcu failed");

	ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE, "ser_backlight:%d\n", brightness);
	if (ret < 0)
		sysfs_err("ser brightness show page");

	return strlen(buf);
}

static DEVICE_ATTR(ser1_pattern_port0, 0640, ser1_pattern_test_port0, NULL);
static DEVICE_ATTR(ser2_pattern_port0, 0640, ser2_pattern_test_port0, NULL);
static DEVICE_ATTR(deser_pattern_port0, 0640, deser_pattern_test_port0, NULL);
static DEVICE_ATTR(ser1_main_regs, 0640, ser1_main_regs_show, ser1_main_regs_store);
static DEVICE_ATTR(ser2_main_regs, 0640, ser2_main_regs_show, ser2_main_regs_store);
static DEVICE_ATTR(deser_passanger_main_regs, 0640, deser_passanger_main_regs_show, deser_passanger_main_regs_store);
static DEVICE_ATTR(deser_arhud_main_regs, 0640, deser_arhud_main_regs_show, deser_arhud_main_regs_store);
static DEVICE_ATTR(deser_maxview_main_regs, 0640, deser_maxview_main_regs_show, deser_maxview_main_regs_store);
static DEVICE_ATTR(ser_brightness, 0640, ser_brightness_show, ser_brightness_store);

static struct attribute *g_dp_sysfs_fs_ops[] = {
	&dev_attr_ser1_pattern_port0.attr,
	&dev_attr_ser2_pattern_port0.attr,
	&dev_attr_deser_pattern_port0.attr,
	&dev_attr_ser1_main_regs.attr,
	&dev_attr_ser2_main_regs.attr,
	&dev_attr_deser_passanger_main_regs.attr,
	&dev_attr_deser_arhud_main_regs.attr,
	&dev_attr_deser_maxview_main_regs.attr,
	&dev_attr_ser_brightness.attr,
	NULL,
};

struct attribute_group sysfs_attr_group_dp = {
	.attrs = g_dp_sysfs_fs_ops,
};

int lcd_sysfs_init_for_dp(struct i2c_client *client)
{
	int ret = LCD_OK;
	g_ti983_client = client;
	ret = sysfs_create_group(&(client->dev.kobj), &sysfs_attr_group_dp);
	if (ret)
		sysfs_err("create fs node fail\n");

	return ret;
}
