/* SPDX-License-Identifier: GPL-2.0 */
/*
 * battery_iscd.h
 *
 * driver adapter for iscd.
 *
 * Copyright (c) 2022-2023 Huawei Technologies Co., Ltd.
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

#ifndef _BATTERY_ISCD_H_
#define _BATTERY_ISCD_H_

#include <chipset_common/hwpower/battery/battery_soh.h>
#include <linux/time.h>
#include <linux/version.h>
#include <linux/notifier.h>
#include <linux/timer.h>
#include <linux/limits.h>
#include "battery_iscd_algo.h"

#define CURRENT_OUTPUT_NEGATIVE        (-1)
#define CHARGE_DONE_RECHARGE           2
#define ISCD_OCV_WORK_INTERVAL         600
#define ISCD_OCV_SAMPLE_INTERVAL       500
#define ISCD_OCV_SAMPLE_TIMES          5
#define ISCD_OCV_EXCLUDED_TIMES        2
#define ISCD_OCV_MIN_DEFAULT           INT_MAX
#define ISCD_OCV_VALID_THRESHOLD       4000000
#define ISCD_CYCLE_UPLOAD_FACTOR       100
#define ISCD_BASIC_INFO_MAX_LEN        32
#define ISCD_FATAL_ISC_DMD_LINE_SIZE   42
#define ISCD_MAX_FATAL_ISC_NUM         20
#define ISCD_COLLECT_TEMP_LIMIT_HIGH   50
#define ISCD_COLLECT_TEMP_LIMIT_LOW    10
#define ISCD_DEFAULT_OCV_LEVEL         0
#define ISCD_CC_INTEGRAL_INTERVAL      5 /* 5s */
#define ISCD_MAX_FATAL_ISC_DMD_NUM \
	(((ISCD_MAX_FATAL_ISC_NUM + 1) * (ISCD_FATAL_ISC_DMD_LINE_SIZE)) + 1)

enum hrtimer_restart iscd_ocv_collect_timer_func(struct hrtimer *timer);

struct iscd_ocv_data {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	time64_t sample_time_sec;
#else
	time_t sample_time_sec;
#endif
	int ocv_volt_uv; /* uV */
	int ocv_soc_uah; /* uAh */
	s64 cc_value; /* uAh */
	int tbatt;
	int pc;
	int ocv_level;
	int batt_chargecycles;
};

struct iscd_device_info {
	int current_event;
	int illegal_status;
	unsigned int iscd_status;
	unsigned int iscd_trigger_type;
	unsigned int iscd_state_machine;
	struct bsoh_device *dev;
	struct iscd_ocv_data ocv_update_data;
	struct pc_ocv_lut_info pc_ocv_lut;
	struct wakeup_source *wake_lock;
	struct notifier_block chg_event_nb;
	struct notifier_block event_nb;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	time64_t last_sample_time;
#else
	time_t last_sample_time;
#endif
};

struct iscd_dmd_data {
	char buff[ISCD_MAX_FATAL_ISC_DMD_NUM];
	int err_no;
};

struct iscd_imonitor_data {
	unsigned int fcc;
	unsigned int bat_cyc; /* Battery charging cycles */
	unsigned int q_max; /* battery QMAX */
	char bat_man[ISCD_BASIC_INFO_MAX_LEN]; /* battery manufactor id */
};

enum iscd_state_machine_status {
	WAIT_CHARGE_DONE,
	CHARGE_DONE_COLLECTING,
	RECHARGE,
	QUIT_COLLECTING,
	NOT_CHARGING,
};

enum iscd_event {
	ISCD_OCV_UPDATE_EVENT,
	ISCD_START_CHARGE_EVENT,
	ISCD_STOP_CHARGE_EVENT,
	ISCD_CHARGE_DONE_EVENT,
	ISCD_RECHARGE_EVENT,
};

enum iscd_para {
	ISCD_PARA_TEMP_LOW,
	ISCD_PARA_TEMP_HIGH,
	ISCD_PARA_INDEX,
	ISCD_PARA_TOTAL,
};

enum iscd_ocv_info {
	ISCD_OCV_INFO_OCV,
	ISCD_OCV_INFO_SOC,
	ISCD_OCV_INFO_TOTAL,
};

enum working_pa_list {
	PA_WORKING = 1,
	IBAT_OVER_TH = 8,
};
#endif /* _BATTERY_ISCD_H_ */
