// SPDX-License-Identifier: GPL-2.0
/*
 * reverse_charge_protocol.c
 *
 * reverse charge protocol api
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
#include <chipset_common/hwpower/reverse_charge/reverse_charge_scp_auth.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge_protocol.h>
#include <huawei_platform/log/hw_log.h>

#define HWLOG_TAG reverse_charge_rprot
HWLOG_REGIST();

int rprot_auth_process(void)
{
	u8 data[RSCP_AUTH_RANDOM_LEN] = { 0 };
	u8 *rscp_random = NULL;
	u8 rscp_random_len;
	int i;
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	hwlog_info("%s enter\n", __func__);

	if (rprot_get_random_value(data, RSCP_AUTH_RANDOM_LEN))
		return -EPERM;

	rscp_random = rscp_auth_get_hash_data_header();
	rscp_random_len = rscp_auth_get_hash_data_size();

	rscp_auth_clean_hash_data();

	for (i = 0; i < rscp_random_len; i++)
		rscp_random[i] = data[i];

	rscp_auth_wait_completion();

	rscp_auth_clean_hash_data();
	return 0;
}

int rprot_ic_reset(void)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->ic_reset) {
		hwlog_err("ic_reset is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->ic_reset(l_ops->dev_data);
}

int rprot_get_rt_ibus(void)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->get_rt_ibus) {
		hwlog_err("get_ibus is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->get_rt_ibus(l_ops->dev_data);
}

int rprot_update_vbus(int vbus)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->update_vbus || (vbus < 0)) {
		hwlog_err("update_vbus is null, or vbus invalid\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->update_vbus(l_ops->dev_data, vbus);
}

int rprot_update_drop_cur(int ibus)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->update_drop_cur || (ibus < 0)) {
		hwlog_err("update_drop_cur is null, or ibus invalid\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->update_drop_cur(l_ops->dev_data, ibus);
}

int rprot_enable_rscp(int enable)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_rscp) {
		hwlog_err("enable_rscp is null\n");
		return -EPERM;
	}

	hwlog_info("%s:%d\n", __func__, enable);

	return l_ops->enable_rscp(l_ops->dev_data, enable);
}

int rprot_enable_sleep(int enable)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->enable_sleep) {
		hwlog_err("enable_sleep is null\n");
		return -EPERM;
	}

	hwlog_info("%s:%d\n", __func__, enable);

	return l_ops->enable_sleep(l_ops->dev_data, enable);
}

int rprot_get_request_vbus(void)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->get_request_vbus) {
		hwlog_err("get_request_vbus is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->get_request_vbus(l_ops->dev_data);
}

int rprot_get_request_ibus(void)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->get_request_ibus) {
		hwlog_err("get_request_ibus is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->get_request_ibus(l_ops->dev_data);
}

int rprot_check_protocol_state(void)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->check_protocol_state) {
		hwlog_err("check_protocol_state is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->check_protocol_state(l_ops->dev_data);
}

int rprot_detect_device(void)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->detect_device) {
		hwlog_err("detect_device is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->detect_device(l_ops->dev_data);
}

int rprot_get_dev_det_result(void)
{
	struct rprotocol_ops *l_ops = NULL;

	l_ops = rprotocol_get_ops();
	if (!l_ops)
		return -EPERM;

	if (!l_ops->get_dev_det_result) {
		hwlog_err("get_dev_det_result is null\n");
		return -EPERM;
	}

	hwlog_info("%s\n", __func__);

	return l_ops->get_dev_det_result(l_ops->dev_data);
}

int rprot_get_random_value(u8 *data, int data_len)
{
	struct rprotocol_ops *l_ops = rprotocol_get_ops();

	if (!l_ops)
		return -EINVAL;

	if (!l_ops->get_random_value) {
		hwlog_err("get_random_value is null\n");
		return -EINVAL;
	}

	return l_ops->get_random_value(l_ops->dev_data, data, data_len);
}

int rprot_set_rscp_auth_result(u8 *auth_result, int len)
{
	struct rprotocol_ops *l_ops = rprotocol_get_ops();

	if (!l_ops || !auth_result)
		return -EINVAL;

	if (!l_ops->set_rscp_auth_result) {
		hwlog_err("set_rscp_auth_result is null\n");
		return -ENOTSUPP;
	}

	return l_ops->set_rscp_auth_result(l_ops->dev_data, auth_result, len);
}

int rprot_set_power_curve(struct rchg_power_curve *power_curve)
{
	struct rprotocol_ops *l_ops = rprotocol_get_ops();

	if (!l_ops || !power_curve)
		return -EINVAL;

	if (!l_ops->set_power_curve) {
		hwlog_err("set_power_curve is null\n");
		return -ENOTSUPP;
	}

	return l_ops->set_power_curve(l_ops->dev_data, power_curve);
}
