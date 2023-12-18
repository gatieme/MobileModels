/* SPDX-License-Identifier: GPL-2.0 */
/*
 * qcom_platform_fg.h
 *
 * qcom platform fuel guage driver
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#ifndef _QCOM_PLATFORM_FG_H_
#define _QCOM_PLATFORM_FG_H_

#include <linux/errno.h>

#define QPLAT_FG_DEFAULT_ITERM_DELTA     200
#define QPLAT_FG_DEFAULT_CURR_GAIN       1000000
#define QPLAT_FG_CURR_GAIN_COVERSION     10000
#define QPLAT_FG_CAPACITY_TH             7
#define QPLAT_FG_FULL_CAP                100
#define QPLAT_FG_PSY_NAME                "bk_battery"
#define QPLAT_FG_VBAT_SOC_TABLE_ROW      11
#define QPLAT_FG_FLAG_UPDATE_SOC         90
#define QPLAT_FG_RECORD_NUM              5
#define QPLAT_FG_MAX_SOC_DIFF            20
#define QPLAT_FG_QUEUE_DELAYED_WORK_TIME 5000
#define QPLAT_FG_DISCHARGE_THRESHOLD     (-10)

enum {
	QPLAT_FG_CURR_CALI_REGISTER = 0,
	QPLAT_FG_MAX,
};

enum qplat_fg_vat_soc_pair_info {
	QPLAT_FG_PAIR_VOLT_MIN = 0,
	QPLAT_FG_PAIR_VOLT_MAX,
	QPLAT_FG_PAIR_SOC_U,
	QPLAT_FG_PAIR_TOTAL,
};

struct qplat_fg_vat_soc_pair {
	int volt_min;
	int volt_max;
	int soc_u;
};

struct qplat_fg_device {
	struct device *dev;
	int dynamic_change_iterm_en;
	int iterm_delta;
	int iterm;
	struct notifier_block qplat_fg_event_nb;
	struct notifier_block qplat_fg_event_buck_nb;
	struct notifier_block ocv_change_event_nb;
	int ocv_idx;
	bool launch_flag;
	struct workqueue_struct *qbg_workqueue;
	struct delayed_work battery_delay_work;
	struct qplat_fg_vat_soc_pair vbat_soc_pair[QPLAT_FG_VBAT_SOC_TABLE_ROW];
	int ibat_record[QPLAT_FG_RECORD_NUM];
	int vbat_record[QPLAT_FG_RECORD_NUM];
	int record_idx;
	int voltage;
	int curr;
	int ui_soc;
	int temp;
	int cycle;
	int en_soft_reset;
	bool dmd_report_flag;
	unsigned int en_basp;
};

struct qplat_fg_display_data {
	int temp;
	int vbat;
	int ibat;
	int rm;
	int soc;
	int fcc;
};

int qplat_fg_register(void);

#endif /* _QCOM_PLATFORM_FG_H_ */
