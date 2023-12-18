/*
 * switch_interface.h
 *
 * switch_interface header file
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

#ifndef _SWITCH_INTERFACE_
#define _SWITCH_INTERFACE_

#include <linux/device.h>
#include <linux/delay.h>
#include <linux/workqueue.h>

#define SWITCH_INTERFACE_FCP_SUPPORT_DEFAULT    0
#define SWITCH_INTERFACE_SCP_SUPPORT_DEFAULT    0
#define SWITCH_INTERFACE_POWER_BY_5V_DEFAULT    0

struct switch_interface_charger_ops {
	int (*accp_adapter_reg_read)(int* val, int reg);
	int (*accp_adapter_reg_write)(int val, int reg);
	int (*accp_adapter_detect)(void *dev_data);
	int (*accp_adapter_reset)(void *dev_data);
	int (*accp_chip_reset)(void *dev_data);
	int (*accp_read_master_status)(void *dev_data);
	int (*is_accp_charger_type)(void *dev_data);
};

struct switch_interface_control_ops {
	int (*dump_regs)(char *buf);
	int (*jigpin_ctrl_store)(int jig_val);
	int (*jigpin_ctrl_show)(char *buf);
	int (*switchctrl_store)(int action);
	int (*switchctrl_show)(char *buf);
	int (*manual_switch)(int input_select);
	void (*detach_work)(void);
};

struct switch_interface_bc12_ops {
	unsigned int (*get_charger_type)(void);
	int (*chg_type_det)(bool en);
	int (*dcd_timeout)(bool enable_flag);
	int (*dcd_timeout_status)(void);
};

struct switch_interface_info_ops {
	bool (*chip_init_status)(void);
};

struct switch_interface_di {
	struct device *dev;
	u32 fcp_support;
	u32 scp_support;
	u32 power_by_5v;
	struct delayed_work detach_delayed_work;
	struct switch_interface_charger_ops *chg_ops;
	struct switch_interface_control_ops *ctrl_ops;
	struct switch_interface_bc12_ops *bc12_ops;
	struct switch_interface_info_ops *info_ops;
};

struct switch_interface_di *switch_interface_get_device_info(void);
struct switch_interface_charger_ops *switch_interface_get_charger_ops(void);
struct switch_interface_control_ops *switch_interface_get_control_ops(void);
struct switch_interface_bc12_ops *switch_interface_get_bc12_ops(void);
struct switch_interface_info_ops *switch_interface_get_info_ops(void);
void switch_interface_control_ops_register(struct switch_interface_control_ops *ops);
void switch_interface_charger_ops_register(struct switch_interface_charger_ops *ops);
void switch_interface_bc12_ops_register(struct switch_interface_bc12_ops *ops);
void switch_interface_info_ops_register(struct switch_interface_info_ops *ops);
unsigned int switch_interface_get_charger_type(void);
void switch_charger_protocol_register(struct switch_interface_di *di);
void switch_control_sysfs_init(struct switch_interface_di *di);
void switch_control_sysfs_exit(struct switch_interface_di *di);
int switch_control_manual_switch(int input_select);
int switch_control_manual_detach(void);
void switch_control_manual_detach_work(struct work_struct *work);

#endif /* _SWITCH_INTERFACE_ */
