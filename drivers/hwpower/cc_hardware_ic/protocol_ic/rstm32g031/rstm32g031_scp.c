// SPDX-License-Identifier: GPL-2.0
/*
 * rstm32g031_protocol.c
 *
 * rstm32g031 protocol driver
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

#include "rstm32g031_scp.h"
#include "rstm32g031_i2c.h"
#include <linux/random.h>
#include <chipset_common/hwpower/common_module/power_delay.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_scp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_fcp.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/reverse_charge/reverse_charge.h>
#include <securec.h>

#define HWLOG_TAG rstm32g031_scp
HWLOG_REGIST();

int rstm32g031_pre_init_check(struct rstm32g031_device_info *di)
{
	int ret;
	u8 reg_val = 0;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_read_byte(di, RSTM32G031_ID_REG, &reg_val);
	if (ret) {
		hwlog_err("read id err, ret:%d\n", ret);
		return ret;
	}
	di->dev_id = reg_val;

	if (di->dev_id == RHC32L110_ID_REG_VALUE) {
		ret = rstm32g031_read_byte(di, RHC32L110_FW_PATCH_VER_REG, &reg_val);
		if (ret)
			return -EINVAL;
		di->fw_ver = reg_val;

		ret = rstm32g031_read_byte(di, RHC32L110_FW_SUB_VER_REG, &reg_val);
		if (ret)
			return -EINVAL;
		di->fw_ver |= reg_val << 8; /* sub ver shift 8 bit */

		hwlog_info("hc32l110 fw_ver:%x\n", di->fw_ver);
	}

	if ((di->dev_id != RSTM32G031_ID_REG_VALUE) &&
		(di->dev_id != RHC32L110_ID_REG_VALUE))
		return -EINVAL;

	return 0;
}

int rstm32g031_enable_sleep(void *dev_data, int enable)
{
	int ret;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	if (enable && di->irq_active) {
		disable_irq(di->irq_int);
		di->irq_active = 0;
	}
	ret = rstm32g031_write_mask(di, RSTM32G031_RSCP_CTL_REG,
		RSTM32G031_RSCP_CTL_REG_SLEEP_EN_MASK,
		RSTM32G031_RSCP_CTL_REG_SLEEP_EN_SHIFT, enable);
	if (ret) { /* ensure sleep succ, or dpdm will be hold by mcu */
		rstm32g031_ic_reset(di);
		ret = rstm32g031_write_mask(di, RSTM32G031_RSCP_CTL_REG,
			RSTM32G031_RSCP_CTL_REG_SLEEP_EN_MASK,
			RSTM32G031_RSCP_CTL_REG_SLEEP_EN_SHIFT, enable);
	}

	di->in_sleep = 1;
	return ret;
}

static int rstm32g031_enable_rscp(void *dev_data, int enable)
{
	int ret;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_write_mask(di, RSTM32G031_RSCP_CTL_REG,
		RSTM32G031_RSCP_CTL_REG_RSCP_EN_MASK,
		RSTM32G031_RSCP_CTL_REG_RSCP_EN_SHIFT, enable);
	if (ret)
		hwlog_err("enable rscp fail\n");

	return ret;
}

static int rstm32g031_get_request_ibus(void *dev_data)
{
	int ret;
	u8 reg_val;
	int request_ibus;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_read_byte(di, RSTM32G031_REG_DATA_REG_CURRENT_SET, &reg_val);
	if (ret) {
		hwlog_err("read request ibus err, ret:%d\n", ret);
		return ret;
	}

	request_ibus = (int)(s16)reg_val * RSTM32G031_REG_DATA_REG_CURRENT_STEP;
	hwlog_info("request ibus is %d", request_ibus);
	return request_ibus;
}

static int rstm32g031_get_request_vbus(void *dev_data)
{
	int ret;
	u8 value[BYTE_TWO] = { 0 };
	int request_vbus;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_read_block(di,
		RSTM32G031_REG_DATA_REG_VOLTAGE_SET, value, BYTE_TWO);
	if (ret) {
		hwlog_err("read request vbus err, ret:%d\n", ret);
		return ret;
	}

	request_vbus = (value[0] << POWER_BITS_PER_BYTE) | value[1];
	hwlog_info("request vbus is %d", request_vbus);
	return request_vbus;
}

static int rstm32g031_update_drop_cur(void *dev_data, int ibus)
{
	int ret;
	int drop_val;
	struct rstm32g031_device_info *di = dev_data;

	if (!di || (ibus <= 0))
		return -ENODEV;

	if (ibus >= di->param_dts.max_design_ibus)
		return rstm32g031_write_mask(di, RSTM32G031_REG_DATA_REG_SSTS_POWER,
			RSTM32G031_REG_SSTS_POWER_ENABLE_MASK,
			RSTM32G031_REG_SSTS_POWER_ENABLE_SHIFT,
			RSTM32G031_REG_SSTS_POWER_DISABLE);

	ret = rstm32g031_write_mask(di, RSTM32G031_REG_DATA_REG_SSTS_POWER,
		RSTM32G031_REG_SSTS_POWER_ENABLE_MASK,
		RSTM32G031_REG_SSTS_POWER_ENABLE_SHIFT,
		RSTM32G031_REG_SSTS_POWER_ENABLE);

	drop_val = (ibus * RSTM32G031_REG_SSTS_POWER_DROP_FACTOR) /
		di->param_dts.max_design_ibus;
	hwlog_info("drop val is %d\n", drop_val);
	ret = rstm32g031_write_mask(di, RSTM32G031_REG_DATA_REG_SSTS_POWER,
		RSTM32G031_REG_SSTS_POWER_DPARTO_MASK,
		RSTM32G031_REG_SSTS_POWER_DPARTO_SHIFT,
		drop_val);

	return ret;
}

static int rstm32g031_get_rt_ibus(void *dev_data)
{
	int ret;
	u8 reg_val;
	int ibus;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_read_byte(di, RSTM32G031_REG_DATA_REG_CURRENT_GET, &reg_val);
	if (ret) {
		hwlog_err("read ibus err, ret:%d\n", ret);
		return ret;
	}

	ibus = (int)(s16)reg_val * RSTM32G031_REG_DATA_REG_CURRENT_STEP;
	hwlog_info("ibus is %d", ibus);
	return ibus;
}

static int rstm32g031_update_vbus(void *dev_data, int vbus)
{
	int ret;
	u8 value[BYTE_TWO] = { 0 };
	struct rstm32g031_device_info *di = dev_data;

	if (!di || (vbus <= 0))
		return -ENODEV;

	value[0] = (vbus >> POWER_BITS_PER_BYTE) & POWER_MASK_BYTE;
	value[1] = vbus & POWER_MASK_BYTE;
	ret = rstm32g031_write_block(di,
		RSTM32G031_REG_DATA_REG_VOLTAGE_GET, value, BYTE_TWO);

	return ret;
}

static int rstm32g031_set_k(struct rstm32g031_device_info *di)
{
	int ret;
	u8 val1 = 0;
	u8 val2 = 0;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_write_byte(di, RHC32L110_K_LOW_REG, di->param_dts.k_low);
	if (ret) {
		hwlog_err("set k low bit err, ret:%d\n", ret);
		return ret;
	}

	ret = rstm32g031_write_byte(di, RHC32L110_K_HIGH_REG, di->param_dts.k_high);
	if (ret)
		hwlog_err("set k high bit err, ret:%d\n", ret);

	return ret;
}

int rstm32g031_ic_reset(void *dev_data)
{
	int ret;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	if (!di->irq_active) {
		di->irq_active = 1;
		enable_irq(di->irq_int);
	}

	/* 0:enable pin pull low */
	ret = gpio_direction_output(di->gpio_enable, 0);
	power_usleep(DT_USLEEP_2MS);

	/* 1:reset pin pull low */
	ret += gpio_direction_output(di->gpio_reset, 1);
	power_usleep(DT_USLEEP_2MS);
	/* 0:reset pin pull high */
	ret += gpio_direction_output(di->gpio_reset, 0);
	power_msleep(DT_MSLEEP_100MS, 0, NULL);

	if (ret)
		hwlog_err("hard reset fail\n");

	if ((di->param_dts.k_low > 0) && (di->param_dts.k_high > 0))
		rstm32g031_set_k(di);

	di->in_sleep = 0;
	return ret;
}

static int rstm32g031_check_protocol_state(void *dev_data)
{
	int ret;
	u8 reg_val;
	int output_mode;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_read_byte(di, RSTM32G031_REG_CTRL_BYTE0, &reg_val);
	if (ret) {
		hwlog_err("check protocol state err, ret:%d\n", ret);
		return ret;
	}

	output_mode = (reg_val & RSTM32G031_REG_OUTPUT_MODE_MASK) >>
		RSTM32G031_REG_OUTPUT_MODE_SHIFT;
	hwlog_info("output_mode is %d", output_mode);
	return output_mode;
}

static int rstm32g031_get_random_value(void *dev_data, u8 *data, int data_len)
{
	struct rstm32g031_device_info *di = dev_data;
	int ret, i;
	u8 write_data[RSTM32G031_SCP_RANDOM_LEN] = { 0 };

	if (!data || !di || (data_len != RSTM32G031_SCP_RANDOM_VALID_LEN))
		return -ENODEV;

	ret = rstm32g031_read_block(di, RSTM32G031_REG_CTRL_BYTE0,
		data, RSTM32G031_SCP_RANDOM_LEN);
	if (ret) {
		hwlog_err("read slave random fail, ret:%d\n", ret);
		return ret;
	}

	for (i = 0; i < RSTM32G031_SCP_RANDOM_LEN; i++)
		get_random_bytes(&data[RSTM32G031_SCP_RANDOM_LEN + i], sizeof(unsigned char));

	memcpy_s(write_data, RSTM32G031_SCP_RANDOM_LEN, &data[RSTM32G031_SCP_RANDOM_LEN], RSTM32G031_SCP_RANDOM_LEN);

	ret = rstm32g031_write_block(di, RSTM32G031_REG_RANDOM_BYTE,
		write_data, RSTM32G031_SCP_RANDOM_LEN);
	if (ret) {
		hwlog_err("write master random fail, ret:%d\n", ret);
		return ret;
	}

	ret = rstm32g031_read_byte(di, RSTM32G031_REG_KEY_INDEX, &data[data_len - 1]);
	if (ret) {
		hwlog_err("read key index fail, ret:%d\n", ret);
		return ret;
	}
	return 0;
}

static int rstm32g031_set_rscp_auth_result(void *dev_data, u8 *data, int data_len)
{
	u8 write_data[RSTM32G031_SCP_AUTH_RESULT_BUF_LEN] = { 0 };
	struct rstm32g031_device_info *di = dev_data;
	int ret, i;

	if (!di || !data)
		return -ENODEV;

	memcpy_s(write_data, RSTM32G031_SCP_AUTH_RESULT_BUF_LEN, data, data_len);

	ret = rstm32g031_write_block(di, RSTM32G031_REG_AUTH_BYTE,
		write_data, data_len);
	if (ret) {
		hwlog_err("write auth byte fail\n");
		return ret;
	}

	return 0;
}

static int rstm32g031_set_power_curve(void *dev_data, struct rchg_power_curve *power_curve)
{
	struct rstm32g031_device_info *di = dev_data;
	int ret, volt_curve, cur_curve, max_power_decimal, max_power_integer, cur_limit;
	int cur_limit_index = 0;

	if (!di || !power_curve)
		return -ENODEV;

	if (power_curve->power_curve <= 0 || power_curve->volt_curve <= 0
		|| power_curve->current_curve <= 0) {
		hwlog_info("not set power curve, use default para\n");
		return 0;
	}
	volt_curve = power_curve->volt_curve / VOLT_CURVE_STEP;
	cur_curve = power_curve->current_curve / CUR_CURVE_STEP;
	max_power_decimal = (power_curve->volt_curve * power_curve->current_curve) % MAX_POWER_CURVE_SETP;
	max_power_integer = (power_curve->volt_curve * power_curve->current_curve) / MAX_POWER_CURVE_SETP;
	cur_limit = power_curve->current_curve;

	while (cur_limit % 10 == 0) {
		cur_limit_index++;
		cur_limit /= 10;
	}

	if (!cur_limit_index || cur_limit > RSTM32G031_SCP_CUR_LIMIT_BASE_MAX) {
		hwlog_info("%s invalid para\n", __func__);
		return 0;
	}

	cur_limit = (cur_limit_index << 6) | cur_limit;

	ret = rstm32g031_write_byte(di, RSTM32G031_REG_POWER_CURVE_COUNT, power_curve->power_curve);
	ret += rstm32g031_write_byte(di, RSTM32G031_REG_VOLTAGE_RANGE1, volt_curve);
	ret += rstm32g031_write_byte(di, RSTM32G031_REG_MAX_OUTPUT_CURRENT1, cur_curve);
	ret += rstm32g031_write_byte(di, RSTM32G031_REG_MAX_POWER_DEC, max_power_decimal);
	ret += rstm32g031_write_byte(di, RSTM32G031_REG_MAX_POWER_INT, max_power_integer);
	ret += rstm32g031_write_byte(di, RSTM32G031_REG_MAX_OUTPUT_CURRENT, cur_limit);
	if (ret) {
		hwlog_err("write power curve fail\n");
		return ret;
	}

	hwlog_info("%s power_curve=0x%x, volt_curve=0x%x, cur_curve=0x%x, decimal=0x%x, integer=0x%x, cur_limit=0x%x\n",
		__func__, power_curve->power_curve, volt_curve, cur_curve, max_power_decimal, max_power_integer, cur_limit);
	return 0;
}

static int rstm32g031_detect_device(void *dev_data)
{
	int ret;
	struct rstm32g031_device_info *di = dev_data;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_write_mask(di, RSTM32G031_RSCP_CTL_REG,
		RSTM32G031_RSCP_CTL_REG_DEV_DET_EN_MASK,
		RSTM32G031_RSCP_CTL_REG_DEV_DET_EN_SHIFT,
		1); // 1 : enalbe detect device

	return ret;
}

static int rstm32g031_get_dev_det_result(void *dev_data)
{
	int ret;
	u8 reg_val;
	struct rstm32g031_device_info *di = dev_data;
	int result;

	if (!di)
		return -ENODEV;

	ret = rstm32g031_read_byte(di, RHC32L110_DEV_DET_RESULT_REG, &reg_val);
	if (ret) {
		hwlog_err("check protocol state err, ret:%d\n", ret);
		return ret;
	}

	result = reg_val & RHC32L110_DEV_DET_RESULT_REG_MASK;
	hwlog_info("%s:%d\n", __func__, result);

	return result;
}

static struct rprotocol_ops rstm32g031_hwscp_ops = {
	.chip_name = "rstm32g031",
	.ic_reset = rstm32g031_ic_reset,
	.update_vbus = rstm32g031_update_vbus,
	.get_rt_ibus = rstm32g031_get_rt_ibus,
	.update_drop_cur = rstm32g031_update_drop_cur,
	.enable_rscp = rstm32g031_enable_rscp,
	.enable_sleep = rstm32g031_enable_sleep,
	.get_request_vbus = rstm32g031_get_request_vbus,
	.get_request_ibus = rstm32g031_get_request_ibus,
	.check_protocol_state = rstm32g031_check_protocol_state,
	.detect_device = rstm32g031_detect_device,
	.get_dev_det_result = rstm32g031_get_dev_det_result,
	.get_random_value = rstm32g031_get_random_value,
	.set_rscp_auth_result = rstm32g031_set_rscp_auth_result,
	.set_power_curve = rstm32g031_set_power_curve,
};

int rstm32g031_hwscp_register(struct rstm32g031_device_info *di)
{
	rstm32g031_hwscp_ops.dev_data = (void *)di;
	return rprotocol_ops_register(&rstm32g031_hwscp_ops);
}
