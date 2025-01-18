/* SPDX-License-Identifier: GPL-2.0 */
/*
 * reverse_charge.h
 *
 * reverse charge module
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

#ifndef _REVERSE_CHARGE_H_
#define _REVERSE_CHARGE_H_

#include <linux/errno.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <huawei_platform/power/huawei_charger.h>

#define POWER_RCHG_TEMP					"reverse_chg"

/* define otg state of charger */
#define RCHG_ENABLE                    1
#define RCHG_DISABLE                   0
#define RCHG_PWR_CONSUM_RATIO          22
#define RCHG_CONTROL_WORK_DELAY_TIME   200
#define RCHG_SOC_PROTECT_TH            20
#define RCHG_TEMP_H_PROTECT_TH         50
#define RCHG_TEMP_L_PROTECT_TH         10
#define RCHG_VBAT_PROTECT_TH           3400
#define RCHG_VBUS_OUTPUT               5000
#define RCHG_IBUS_OUTPUT               1500
#define RCHG_IBUS_H_TEMP               500
#define RCHG_MMI_PASS_VBUS             7500
#define RCHG_MMI_PASS_IBAT             2000
#define RCHG_MV                        1000
#define RCHG_MAX_VOL                   10
#define RCHG_MIN_VOL                   0

#define BST_IDLE_STATE                 1
#define BST_NORMAL_STATE               0
#define BST_VCG_ON                     1
#define BST_VCG_OFF                    0
#define OUTPUT_MODE_SCP                1
#define BST_EN                         1
#define BST_DIS                        0
#define RSCP_EN                        1

#define MAX_SIZE                       1024
#define AUTH_TIMEOUT                   50
/*
 * define sysfs type with reverse charge
 * RCHG is simplified identifier with reverse-charge
 */
enum reverse_charge_sysfs_type {
	RCHG_SYSFS_BEGIN = 0,
	RCHG_SYSFS_RCHG_ENABLE = RCHG_SYSFS_BEGIN,
	RCHG_SYSFS_RCHG_SUCCESS,
	RCHG_SYSFS_RCHG_HV_SUPPORT,
	RCHG_SYSFS_RCHG_VOL_TEST,
	RCHG_SYSFS_END,
};

#define RCHG_THRE_PARA_LEVEL           15
#define RCHG_POWER_CURVE_PARA_LEVEL    3

enum rchg_thre_info {
	RCHG_THRE_HIGH = 0,
	RCHG_THRE_LOW,
	RCHG_THRE_IBUS,
	RCHG_THRE_TOTAL,
};

struct rchg_thre_para {
	int thre_high;
	int thre_low;
	int ibus_limit;
};

struct rchg_power_curve {
	int power_curve;
	int volt_curve;
	int current_curve;
};

struct rchg_boost_device_data {
	unsigned int id;
	const char *name;
};

enum rch_boost_device_id {
	BOOST_DEVICE_ID_BEGIN = 0,
	BOOST_DEVICE_ID_SC8726 = BOOST_DEVICE_ID_BEGIN,
	BOOST_DEVICE_ID_END,
};

struct boost_ops {
	const char *chip_name;
	void *dev_data;
	int (*set_vcg_on)(void *dev_data, int enable);
	int (*set_vbus)(void *dev_data, int vbus);
	int (*set_ibus)(void *dev_data, int ibus);
	int (*ic_enable)(void *dev_data, int enable);
	int (*set_idle_mode)(void *dev_data, int mode);
};

struct rchg_rprotocol_device_data {
	unsigned int id;
	const char *name;
};

enum rch_rprotocol_device_id {
	RPROTOCOL_DEVICE_ID_BEGIN = 0,
	RPROTOCOL_DEVICE_ID_STM32G031 = RPROTOCOL_DEVICE_ID_BEGIN,
	RPROTOCOL_DEVICE_ID_END,
};

enum rch_write_status {
	WRITE_DEFAULT = 0,
	WRITE_START,
	PWK_EVT_PROCESS,
	WRITE_DONE,
};

struct rprotocol_ops {
	const char *chip_name;
	void *dev_data;
	int (*ic_reset)(void *dev_data);
	int (*update_vbus)(void *dev_data, int vbus);
	int (*update_drop_cur)(void *dev_data, int ibus);
	int (*enable_rscp)(void *dev_data, int enable);
	int (*enable_sleep)(void *dev_data, int enable);
	int (*get_request_vbus)(void *dev_data);
	int (*get_request_ibus)(void *dev_data);
	int (*get_rt_ibus)(void *dev_data);
	int (*check_protocol_state)(void *dev_data);
	int (*detect_device)(void *dev_data);
	int (*get_dev_det_result)(void *dev_data);
	int (*get_random_value)(void *dev_data, u8 *data, int data_len);
	int (*set_rscp_auth_result)(void *dev_data, u8 *data, int data_len);
	int (*set_power_curve)(void *dev_data, struct rchg_power_curve* power_curve);
};

struct reverse_charge_device {
	struct device *dev;
	struct delayed_work rchg_control_work;
	struct delayed_work psy_tst_work;
	struct delayed_work rchg_vol_test_work;
	struct delayed_work rchg_test_exit_work;
	struct work_struct rchg_auth_process_work;
	struct boost_ops *bst_ops;
	struct rprotocol_ops *rprot_ops;
	struct rchg_thre_para soc_para[RCHG_THRE_PARA_LEVEL];
	struct rchg_thre_para temp_para[RCHG_THRE_PARA_LEVEL];
	struct rchg_thre_para temp_para1[RCHG_THRE_PARA_LEVEL];
	struct rchg_thre_para pwr_consum_para[RCHG_THRE_PARA_LEVEL];
	struct notifier_block rchg_nb;
	struct notifier_block pwrkey_nb;
	struct wakeup_source *rchg_lock;
	int soc_protect_th;
	int temp_h_protect_th;
	int temp_l_protect_th;
	int vbat_protect_th;
	int vbus_init;
	int ibus_init;
	int ibus_h_temp;
	int mmi_pass_vbus;
	int mmi_pass_ibat;
	int bst_dev_id;
	int rprot_dev_id;
	int rchg_use_boost;
	int rchg_hv_support;
	int last_icon_type;
	int test_process;
	int write_value;
	int otg_mode;
	int rchg_ignore_work_flag;
	struct rchg_power_curve power_curve[RCHG_POWER_CURVE_PARA_LEVEL];
};

#ifdef CONFIG_REVERSE_CHARGE
int reverse_charge_enable(int enable);
int boost_ops_register(struct boost_ops *ops);
int rprotocol_ops_register(struct rprotocol_ops *ops);
struct boost_ops *boost_get_ops(void);
struct rprotocol_ops *rprotocol_get_ops(void);
int reverse_charge_enable(int enable);
#else
static inline int boost_ops_register(struct boost_ops *ops)
{
	return 0;
}

static inline int rprotocol_ops_register(struct rprotocol_ops *ops)
{
	return 0;
}

static inline struct boost_ops *boost_get_ops(void)
{
	return NULL;
}
static inline struct rprotocol_ops *rprotocol_get_ops(void)
{
	return NULL;
}

static inline int reverse_charge_enable(int enable)
{
	charge_otg_mode_enable(enable, VBUS_CH_USER_WIRED_OTG);
	return 0;
}

#endif
#endif /* _REVERSE_CHARGE_H_ */
