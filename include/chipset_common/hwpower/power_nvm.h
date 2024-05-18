/*
 * power_nvm.h
 *
 * nvm for power module
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _POWER_NVM_H_
#define _POWER_NVM_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/slab.h>

#define POWER_NVM_WR_BUF_SIZE     32
#define POWER_NVM_STRING_MAX_LEN  32
#define POWER_NVM_UEVENT_MAX_LEN  64
#define POWER_NVM_UEVENT_PREFIX   "SET_BMS_NVM"


enum power_nvm_sysfs_type {
	POWER_NVM_SYSFS_BEGIN = 0,
	POWER_NVM_SYSFS_INDEX = POWER_NVM_SYSFS_BEGIN,
	POWER_NVM_SYSFS_VALUE,
	POWER_NVM_SYSFS_END,
};

enum power_nvm_id {
	POWER_NVM_INT_ID_BEGIN = 0,
	POWER_NVM_INT_ID_FG_LAST_SOC = POWER_NVM_INT_ID_BEGIN,
	POWER_NVM_INT_ID_CYLCE_COUNT,
	POWER_NVM_INT_ID_END = 20,
	POWER_NVM_STRING_ID_BEGIN = POWER_NVM_INT_ID_END,
	POWER_NVM_STRING_ID_BATT_SN = POWER_NVM_STRING_ID_BEGIN,
	POWER_NVM_STRING_ID_END = 30,
	POWER_NVM_ID_MAX = POWER_NVM_STRING_ID_END,
};

#define POWER_NVM_INT_DATA_NUM        (POWER_NVM_INT_ID_END - POWER_NVM_INT_ID_BEGIN)
#define POWER_NVM_STRING_DATA_NUM     (POWER_NVM_STRING_ID_END - POWER_NVM_STRING_ID_BEGIN)

struct power_nvm_data {
	int int_data[POWER_NVM_INT_DATA_NUM];
	char string_data[POWER_NVM_STRING_DATA_NUM][POWER_NVM_STRING_MAX_LEN];
};

struct power_nvm_dev {
	struct device *dev;
	int index;
	struct power_nvm_data data;
	int update_flag[POWER_NVM_ID_MAX];
};

int power_nvm_read_int(int index, int *value);
int power_nvm_read_string(int index, char *value);

int power_nvm_write_int(int index, int value);
int power_nvm_write_string(int index, char *value);

#endif /* _POWER_NVM_H_ */

