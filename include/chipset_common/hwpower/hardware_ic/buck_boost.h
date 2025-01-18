/* SPDX-License-Identifier: GPL-2.0 */
/*
 * buck_boost.h
 *
 * buck_boost macro, interface etc.
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

#ifndef _BUCK_BOOST_H_
#define _BUCK_BOOST_H_

#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/workqueue.h>

#define BBST_DEFAULT_VOUT                 3450
#define BBST_GET_OPS_RETRY_CNT            3
#define BBST_TYPE_MAIN                    BIT(0)
#define BBST_TYPE_AUX                     BIT(1)
#define BBST_NO_USER                      0
#define DBG_BUCK_BOOST_FLAG               0x2023
#define BBST_VOUT_TABLE_MAX_SIZE          8
#define BBST_INDEX_DEFAULT                0
#define BBST_VOTE_NAME_LEN                32

enum buck_boost_user_id {
	BBST_USER_BEGIN = 0,
	BBST_USER_LPM = BBST_USER_BEGIN,
	BBST_USER_CAMERA,
	BBST_USER_BOOST_5V,
	BBST_USER_BOOST_RSMC,
	BBST_USER_BOOST_HW_SATE,
	BBST_USER_BOOST_HX,
	BBST_USER_BOOST_DISCHG,
	BBST_USER_BOOST_FAC,
	BBST_USER_END,
};

enum {
	BBST_GPIO_VOUT_VOLTAGE = 0,
	BBST_GPIO_VOUT_VALUE,
	BBST_GPIO_VOUT_END,
};

struct bbst_gpio_vout_table {
	unsigned int output_voltage;
	unsigned int gpio_value;
};

struct buck_boost_user_data {
	unsigned int id;
	const char *name;
};

struct buck_boost_ops {
	void *dev_data;
	unsigned int index;
	bool (*pwr_good)(void *dev_data);
	int (*set_vout)(unsigned int vol, void *dev_data);
	int (*set_pwm_enable)(unsigned int enable, void *dev_data);
	bool (*set_enable)(unsigned int enable, void *dev_data);
	void (*monitor_state)(void *dev_data);
};

struct buck_boost_context {
	struct buck_boost_ops *ops;
	unsigned int const_vout;
	unsigned int need_init_vout;
	char vout_vote_object[BBST_VOTE_NAME_LEN];
	char mode_vote_object[BBST_VOTE_NAME_LEN];
};

struct buck_boost_dev {
	struct device *dev;
	struct buck_boost_context *bbst_context;
	struct delayed_work monitor_work;
	int retry_cnt;
	int path_num;
	int bbst_gpio_en;
	int boost_use_gpio;
	int *bbst_gpio_vout;
	int gpio_vout_num;
	struct bbst_gpio_vout_table *vout_table;
	int vout_table_size;
	int test_flag;
	int delay_ms;
	int need_monitor_state;
};

#ifdef CONFIG_BUCKBOOST
extern int buck_boost_ops_register(struct buck_boost_ops *ops);
extern int buck_boost_set_pwm_enable(unsigned int enable, unsigned int type);
extern bool buck_boost_pwr_good(unsigned int type);
extern int buckboost_set_vout(unsigned int vol, unsigned int user, unsigned int index);
extern bool buckboost_set_enable(unsigned int enable, unsigned int user, unsigned int index);
/* following interfaces are for gugong old version, forbidden to use! */
extern int buck_boost_set_vout(unsigned int vol, unsigned int user);
extern bool buck_boost_set_enable(unsigned int enable, unsigned int user);
#else
static inline int buck_boost_ops_register(struct buck_boost_ops *ops)
{
	return 0;
}

static inline int buck_boost_set_pwm_enable(unsigned int enable, unsigned int type)
{
	return 0;
}

static inline int buck_boost_set_vout(unsigned int vol, unsigned int user)
{
	return 0;
}

static inline bool buck_boost_pwr_good(unsigned int type)
{
	return true;
}

static inline bool buck_boost_set_enable(unsigned int enable, unsigned int user)
{
	return true;
}

static inline int buckboost_set_vout(unsigned int vol, unsigned int user, unsigned int index)
{
	return 0;
}
 
static inline bool buckboost_set_enable(unsigned int enable, unsigned int user, unsigned int index)
{
	return true;
}
#endif /* CONFIG_BUCKBOOST */

#endif /* _BUCK_BOOST_H_ */
