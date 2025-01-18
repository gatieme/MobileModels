// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_charge_boost.c
 *
 * reverse charge boost api
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#include <chipset_common/hwpower/reverse_charge/reverse_charge.h>
#include <huawei_platform/log/hw_log.h>

#define HWLOG_TAG reverse_charge_bst
HWLOG_REGIST();

int boost_set_vcg_on(int enable)
{
	struct boost_ops *l_ops = NULL;

	l_ops = boost_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->set_vcg_on) {
		hwlog_err("set_vcg_on is null\n");
		return -EPERM;
	}

	hwlog_info("%s: %d\n", __func__, enable);
	return l_ops->set_vcg_on(l_ops->dev_data, enable);
}

int boost_set_vbus(int vbus)
{
	struct boost_ops *l_ops = NULL;

	l_ops = boost_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->set_vbus || (vbus < 0)) {
		hwlog_err("set_vbus is null, or vbus invalid\n");
		return -EPERM;
	}

	hwlog_info("%s: %d\n", __func__, vbus);

	return l_ops->set_vbus(l_ops->dev_data, vbus);
}

int boost_set_ibus(int ibus)
{
	struct boost_ops *l_ops = NULL;

	l_ops = boost_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->set_ibus  || (ibus < 0)) {
		hwlog_err("set_ibus is null, or ibus invalid\n");
		return -EPERM;
	}

	hwlog_info("%s: %d\n", __func__, ibus);
	return l_ops->set_ibus(l_ops->dev_data, ibus);
}

int boost_ic_enable(int enable)
{
	struct boost_ops *l_ops = NULL;

	l_ops = boost_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->ic_enable) {
		hwlog_err("ic_enable is null\n");
		return -EPERM;
	}

	hwlog_info("%s:%d\n", __func__, enable);
	return l_ops->ic_enable(l_ops->dev_data, enable);
}

int boost_set_idle_mode(int mode)
{
	struct boost_ops *l_ops = NULL;

	l_ops = boost_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->set_idle_mode) {
		hwlog_err("set_idle_mode is null\n");
		return -EPERM;
	}

	hwlog_info("%s: %d\n", __func__, mode);
	return l_ops->set_idle_mode(l_ops->dev_data, mode);
}

