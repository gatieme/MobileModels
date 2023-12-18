/*
 * switch_charger_protocol.c
 *
 * driver file for switch_charger_protocol
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

#include "switch_interface.h"
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_fcp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_scp.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_power_supply.h>
#ifdef CONFIG_BOOST_5V
#include <chipset_common/hwpower/hardware_ic/boost_5v.h>
#endif /* CONFIG_BOOST_5V */
#include <huawei_platform/power/direct_charger/direct_charger.h>

#define HWLOG_TAG switch_charger_protocol
HWLOG_REGIST();

static int switch_accp_adapter_detect(void *dev_data)
{
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	return ops->accp_adapter_detect(dev_data);
}

static int switch_fcp_reg_read_block(int reg, int *val, int num,
	void *dev_data)
{
	int ret;
	int i;
	int data = 0;
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	if (!val) {
		hwlog_err("val is null\n");
		return -EINVAL;
	}

	for (i = 0; i < num; i++) {
		ret = ops->accp_adapter_reg_read(&data, reg + i);
		if (ret) {
			hwlog_err("fcp read failed(reg=0x%x)\n", reg + i);
			return -EINVAL;
		}

		val[i] = data;
	}

	return 0;
}

static int switch_fcp_reg_write_block(int reg, const int *val, int num,
	void *dev_data)
{
	int ret;
	int i;
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	if (!val) {
		hwlog_err("val is null\n");
		return -EINVAL;
	}

	for (i = 0; i < num; i++) {
		ret = ops->accp_adapter_reg_write(val[i], reg + i);
		if (ret) {
			hwlog_err("fcp write failed(reg=0x%x)\n", reg + i);
			return -EINVAL;
		}
	}

	return 0;
}

static int switch_fcp_chip_reset(void *dev_data)
{
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	return ops->accp_chip_reset(dev_data);
}

static int switch_fcp_adapter_reset(void *dev_data)
{
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	return ops->accp_adapter_reset(dev_data);
}

static int switch_fcp_read_master_status(void *dev_data)
{
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	return ops->accp_read_master_status(dev_data);
}

static int switch_fcp_stop_charge_config(void *dev_data)
{
	struct switch_interface_di *di = switch_interface_get_device_info();
#ifdef CONFIG_BOOST_5V
	int ret;
	int disable;
#endif

	if (!di)
		return -EINVAL;

#ifdef CONFIG_DIRECT_CHARGER
	if (!direct_charge_get_cutoff_normal_flag()) {
#endif /* CONFIG_DIRECT_CHARGER */
#ifdef CONFIG_BOOST_5V
		if (di->power_by_5v) {
			ret = boost_5v_enable(DISABLE, BOOST_CTRL_FCP);
			disable = dc_set_bst_ctrl(DISABLE);
			if (ret || disable) {
				hwlog_err("%s 5v boost close fail\n", __func__);
				return -EINVAL;
			}
			hwlog_info("%s 5v boost close\n", __func__);
		}
#endif /* CONFIG_BOOST_5V */
#ifdef CONFIG_DIRECT_CHARGER
	}
#endif /* CONFIG_DIRECT_CHARGER */
	return 0;
}

static int switch_is_fcp_charger_type(void *dev_data)
{
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	return ops->is_accp_charger_type(dev_data);
}

static struct fcp_protocol_ops switch_fcp_protocol_ops = {
	.chip_name = "fsa9685",
	.reg_read = switch_fcp_reg_read_block,
	.reg_write = switch_fcp_reg_write_block,
	.detect_adapter = switch_accp_adapter_detect,
	.soft_reset_master = switch_fcp_chip_reset,
	.soft_reset_slave = switch_fcp_adapter_reset,
	.get_master_status = switch_fcp_read_master_status,
	.stop_charging_config = switch_fcp_stop_charge_config,
	.is_accp_charger_type = switch_is_fcp_charger_type,
};

static int switch_scp_adapter_reg_read(int *val, int reg)
{
	int ret;
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	ret = ops->accp_adapter_reg_read(val, reg);
	if (ret) {
		hwlog_err("%s error reg = %d\n", __func__, reg);
		return -EINVAL;
	}
	return 0;
}

static int switch_scp_adapter_reg_write(int val, int reg)
{
	int ret;
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	ret = ops->accp_adapter_reg_write(val, reg);
	if (ret) {
		hwlog_err("%s error reg = %d\n", __func__, reg);
		return -EINVAL;
	}
	return 0;
}

static int switch_scp_reg_read_block(int reg, int *val, int num,
	void *dev_data)
{
	int ret;
	int i;
	int data = 0;

	if (!val) {
		hwlog_err("val is null\n");
		return -EINVAL;
	}

	for (i = 0; i < num; i++) {
		ret = switch_scp_adapter_reg_read(&data, reg + i);
		if (ret) {
			hwlog_err("scp read failed(reg=0x%x)\n", reg + i);
			return -EINVAL;
		}

		val[i] = data;
	}

	return 0;
}

static int switch_scp_reg_write_block(int reg, const int *val, int num,
	void *dev_data)
{
	int ret;
	int i;

	if (!val) {
		hwlog_err("val is null\n");
		return -EINVAL;
	}

	for (i = 0; i < num; i++) {
		ret = switch_scp_adapter_reg_write(val[i], reg + i);
		if (ret) {
			hwlog_err("scp write failed(reg=0x%x)\n", reg + i);
			return -EINVAL;
		}
	}

	return 0;
}

#ifdef CONFIG_DIRECT_CHARGER
static int switch_scp_adapter_reset(void *dev_data)
{
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();

	if (!ops)
		return -EPERM;

	return ops->accp_adapter_reset(dev_data);
}

static int switch_scp_chip_reset(void *dev_data)
{
	struct switch_interface_charger_ops *ops = switch_interface_get_charger_ops();
	struct switch_interface_di *di = switch_interface_get_device_info();

	if (!ops)
		return -EPERM;

	if (!di)
		return -EINVAL;

	if (di->power_by_5v)
		return 0;

	return ops->accp_chip_reset(dev_data);
}

static int switch_scp_exit(void *dev_data)
{
	struct switch_interface_di *di = switch_interface_get_device_info();

	if (!di)
		return -EINVAL;

	if (di->power_by_5v)
		return 0;

#ifdef CONFIG_BOOST_5V
	if (di->power_by_5v) {
		boost_5v_enable(DISABLE, BOOST_CTRL_FCP);
		dc_set_bst_ctrl(DISABLE);
	}
#endif /* CONFIG_BOOST_5V */
	hwlog_info("%s:5v boost close!\n", __func__);
	return 0;
}
#endif /* CONFIG_DIRECT_CHARGER */

static struct scp_protocol_ops switch_scp_protocol_ops = {
	.chip_name = "fsa9685",
	.reg_read = switch_scp_reg_read_block,
	.reg_write = switch_scp_reg_write_block,
	.detect_adapter = switch_accp_adapter_detect,
	.soft_reset_master = switch_scp_chip_reset,
	.soft_reset_slave = switch_scp_adapter_reset,
	.post_exit = switch_scp_exit,
};

void switch_charger_protocol_register(struct switch_interface_di *di)
{
	if (!di)
		return;

	if (di->fcp_support)
		hwfcp_ops_register(&switch_fcp_protocol_ops);

#ifdef CONFIG_DIRECT_CHARGER
	if (di->scp_support)
		hwscp_ops_register(&switch_scp_protocol_ops);
#endif /* CONFIG_DIRECT_CHARGER */
}
