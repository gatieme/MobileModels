/*
 * rt8979_osc.c
 *
 * osc with rt8979 driver
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#include "rt8979_osc.h"
#include <linux/delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include "usbswitch_rt8979.h"
#include "rt8979_reg.h"
#include "switch_chip_i2c.h"

#define HWLOG_TAG rt8979_osc
HWLOG_REGIST();

static int rt8979_osc_lower_bound;  /* lower bound for OSC setting */
static int rt8979_osc_upper_bound;  /* upper bound for OSC setting */
static int rt8979_osc_trim_code;    /* OSC trimming setting (read from IC) */
static int rt8979_osc_trim_adjust;  /* OSC adjustment */
static int rt8979_osc_trim_default; /* While attaching reset OSC adjustment */

int rt8979_get_osc_trim_default(void)
{
	return rt8979_osc_trim_default;
}

void rt8979_set_osc_trim_adjust(int val)
{
	rt8979_osc_trim_adjust = val;
}

static int rt8979_write_osc_pretrim(void)
{
	int retval;
	struct rt8979_device_info *di = rt8979_get_dev_info();

	if (!di)
		return -EINVAL;

	retval = switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_VAL1);
	if (retval < 0)
		return retval;
	retval = switch_write_reg(di->client, RT8979_REG_EFUSE_CTRL, RT8979_REG_EFUSE_CTRL_VAL);
	if (retval < 0) {
		switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_DEFAULT_VAL);
		return retval;
	}
	retval = switch_write_reg(di->client, RT8979_REG_EFUSE_PRETRIM_DATA,
		(rt8979_osc_trim_code + rt8979_osc_trim_adjust) ^ RT8979_REG_EFUSE_PRETRIM_DATA_VAL);
	if (retval < 0) {
		switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_DEFAULT_VAL);
		return retval;
	}
	retval = switch_write_reg(di->client, RT8979_REG_EFUSE_PRETRIM_ENABLE,
		RT8979_REG_EFUSE_PRETRIM_ENABLE_VAL);
	usleep_range(WRITE_OSC_PRETRIM_DELAY_MIN, WRITE_OSC_PRETRIM_DELAY_MAX);
	retval = switch_read_reg(di->client, RT8979_REG_EFUSE_READ_DATA);
	hwlog_info("%s : trim code read = %d\n", __func__, retval);

	retval = switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_DEFAULT_VAL);
	return retval;
}

int rt8979_adjust_osc(int8_t val)
{
	int8_t temp;

	temp = rt8979_osc_trim_code + rt8979_osc_trim_adjust + val;
	if (temp > rt8979_osc_upper_bound || temp < rt8979_osc_lower_bound) {
		hwlog_err("%s : reach to upper/lower bound %d / %d\n", __func__,
			rt8979_osc_trim_code, rt8979_osc_trim_adjust);
		return -RT8979_FAIL;
	}

	rt8979_osc_trim_adjust += val;
	hwlog_info("%s : adjust osc trim code %d / %d\n", __func__,
		rt8979_osc_trim_code, rt8979_osc_trim_adjust);

	return rt8979_write_osc_pretrim();
}

int rt8979_init_osc_params(struct rt8979_device_info *di)
{
	int retval;

	hwlog_info("%s : entry\n", __func__);
	retval = switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_VAL1);
	if (retval < 0)
		return retval;

	retval = switch_write_reg(di->client, RT8979_REG_EFUSE_CTRL, RT8979_REG_EFUSE_CTRL_VAL);
	if (retval < 0) {
		switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_DEFAULT_VAL);
		return retval;
	}

	retval = switch_write_reg(di->client, RT8979_REG_EFUSE_PRETRIM_ENABLE,
		RT8979_REG_EFUSE_PRETRIM_ENABLE_VAL1);
	if (retval < 0) {
		switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_DEFAULT_VAL);
		return retval;
	}
	usleep_range(WRITE_OSC_PRETRIM_DELAY_MIN_DEFAULT, WRITE_OSC_PRETRIM_DELAY_MIN);
	retval = switch_read_reg(di->client, RT8979_REG_EFUSE_READ_DATA);
	if (retval < 0) {
		switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_DEFAULT_VAL);
		return retval;
	}
	hwlog_info("%s : trim code read = %d\n", __func__, retval);
	rt8979_osc_trim_code = retval;
	rt8979_osc_lower_bound = RT8979_OSC_BOUND_MIN;
	rt8979_osc_upper_bound = RT8979_OSC_BOUND_MAX;
	rt8979_osc_trim_adjust = RT8979_OSC_TRIM_ADJUST_DEFAULT;

	retval = rt8979_osc_trim_code + rt8979_osc_trim_adjust;
	if (retval < rt8979_osc_lower_bound)
		retval = rt8979_osc_lower_bound;
	if (retval > rt8979_osc_upper_bound)
		retval = rt8979_osc_upper_bound;
	rt8979_osc_trim_default = retval - rt8979_osc_trim_code;
	rt8979_osc_trim_adjust = rt8979_osc_trim_default;

	retval = switch_write_reg(di->client, RT8979_REG_EFUSE_PRETRIM_DATA,
		(retval) ^ RT8979_REG_EFUSE_PRETRIM_DATA_VAL);
	hwlog_info("%s : trim code = %d, rt8979_osc_trim_adjust = %d, %d\n",
		__func__, rt8979_osc_trim_code, rt8979_osc_trim_adjust,
		(rt8979_osc_trim_code + rt8979_osc_trim_adjust) ^ RT8979_REG_EFUSE_PRETRIM_DATA_VAL);
	if (retval < 0) {
		switch_write_reg(di->client, RT8979_REG_TEST_MODE, RT8979_REG_TEST_MODE_DEFAULT_VAL);
		return retval;
	}
	switch_write_reg(di->client, RT8979_REG_EFUSE_PRETRIM_ENABLE,
		RT8979_REG_EFUSE_PRETRIM_ENABLE_VAL);
	usleep_range(WRITE_OSC_PRETRIM_DELAY_MIN, WRITE_OSC_PRETRIM_DELAY_MAX);
	retval = switch_read_reg(di->client, RT8979_REG_EFUSE_READ_DATA);
	hwlog_info("%s : trim code read = %d\n", __func__, retval);

	retval = switch_write_reg(di->client, RT8979_REG_TEST_MODE,
		RT8979_REG_TEST_MODE_DEFAULT_VAL);
	return retval;
}
