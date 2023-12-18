/* SPDX-License-Identifier: GPL-2.0 */
/*
 * charging_core.c
 *
 * charging core driver for buck charge
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

#ifndef _CHARGING_CORE_
#define _CHARGING_CORE_

#include <linux/device.h>
#ifdef CONFIG_BATTERY_DATA
#include <linux/power/platform/battery_data.h>
#endif
#include <huawei_platform/power/huawei_charger.h>

/* marco define area */
#define VDPM_BY_CAPACITY            0
#define VDPM_BY_VOLTAGE             1

#define VDPM_PARA_LEVEL             5
#define TEMP_PARA_LEVEL             10
#define VOLT_PARA_LEVEL             4
#define SEGMENT_PARA_LEVEL          3

#define MAX_BATT_CHARGE_CUR_RATIO   70 /* 0.7C */

#define VDPM_CBAT_MIN               (-32767)
#define VDPM_CBAT_MAX               32767
#define VDPM_VOLT_MIN               3880
#define VDPM_VOLT_MAX               5080
#define VDPM_DELTA_LIMIT_5          5

#define INDUCTANCE_PARA_LEVEL       4
#define INDUCTANCE_CBAT_MIN         (-32767)
#define INDUCTANCE_CBAT_MAX         32767
#define INDUCTANCE_IIN_MIN          0
#define INDUCTANCE_IIN_MAX          5000
#define INDUCTANCE_CAP_DETA         5

#define INVALID_CURRENT_SET         0

#define OVERHEAT_TIMES              2

#define FIRST_RUN_TRUE              1
#define FIRST_RUN_FALSE             0

#define BATT_BRAND_STRING_MAX       32
#define BATT_BRAND_NUM_MAX          5

/* struct define area */
enum vdpm_para_info {
	VDPM_PARA_CAP_MIN = 0,
	VDPM_PARA_CAP_MAX,
	VDPM_PARA_DPM,
	VDPM_PARA_CAP_BACK,
	VDPM_PARA_TOTAL,
};

enum inductance_para_info {
	INDUCTANCE_PARA_CAP_MIN = 0,
	INDUCTANCE_PARA_CAP_MAX,
	INDUCTANCE_PARA_IIN,
	INDUCTANCE_PARA_CAP_BACK,
	INDUCTANCE_PARA_TOTAL,
};

enum segment_type_info {
	SEGMENT_TYPE_BY_VBAT_ICHG = 0,
	SEGMENT_TYPE_BY_VBAT,
	SEGMENT_TYPE_BY_DEFAULT,
};

struct charge_temp_data {
	int temp_min;
	int temp_max;
	int iin_temp;
	int ichg_temp;
	int vterm_temp;
	int temp_back;
};

struct charge_volt_data {
	int vbat_min;
	int vbat_max;
	int iin_volt;
	int ichg_volt;
	int volt_back;
};

struct charge_vdpm_data {
	int cap_min;
	int cap_max;
	int vin_dpm;
	int cap_back;
};

struct charge_segment_data {
	int vbat_min;
	int vbat_max;
	int ichg_segment;
	int vterm_segment;
	int volt_back;
};

struct charge_inductance_data {
	int cap_min;
	int cap_max;
	int iin_inductance;
	int cap_back;
};

/* charge terminal current is different, based on battery model */
enum {
	CHARGE_ITERM_PARA_BATT_BRAND,
	CHARGE_ITERM_PARA_ITERM,
	CHARGE_ITERM_PARA_TOTAL,
};

struct charge_core_data {
	unsigned int iin;
	unsigned int ichg;
	unsigned int vterm;
	unsigned int iin_ac;
	unsigned int ichg_ac;
	unsigned int iin_usb;
	unsigned int ichg_usb;
	unsigned int iin_nonstd;
	unsigned int ichg_nonstd;
	unsigned int iin_bc_usb;
	unsigned int ichg_bc_usb;
	unsigned int iin_vr;
	unsigned int ichg_vr;
	unsigned int iin_pd;
	unsigned int ichg_pd;
	unsigned int iin_fcp;
	unsigned int ichg_fcp;
	unsigned int iin_nor_scp;
	unsigned int ichg_nor_scp;
	unsigned int iin_weaksource;
	unsigned int iterm;
	unsigned int initial_iterm;
	unsigned int vdpm;
	unsigned int vdpm_control_type;
	unsigned int vdpm_buf_limit;
	unsigned int iin_max;
	unsigned int ichg_max;
	unsigned int otg_curr;
	unsigned int iin_typech;
	unsigned int ichg_typech;
	unsigned int typec_support;
	unsigned int segment_type;
	unsigned int segment_level;
	unsigned int temp_level;
	unsigned int high_temp_limit;
	bool warm_triggered;
	unsigned int iin_wireless;
	unsigned int ichg_wireless;
	unsigned int vterm_bsoh;
	unsigned int ichg_bsoh;
	unsigned int battery_cell_num;
	unsigned int vterm_low_th;
	unsigned int vterm_high_th;
};

struct charge_core_info {
	struct device *dev;
	struct charge_temp_data temp_para[TEMP_PARA_LEVEL];
	struct charge_volt_data volt_para[VOLT_PARA_LEVEL];
	struct charge_vdpm_data vdpm_para[VDPM_PARA_LEVEL];
	struct charge_segment_data segment_para[SEGMENT_PARA_LEVEL];
	struct charge_inductance_data inductance_para[VDPM_PARA_LEVEL];
	struct charge_core_data data;
};

enum temp_para_info {
	TEMP_PARA_TEMP_MIN = 0,
	TEMP_PARA_TEMP_MAX,
	TEMP_PARA_IIN,
	TEMP_PARA_ICHG,
	TEMP_PARA_VTERM,
	TEMP_PARA_TEMP_BACK,
	TEMP_PARA_TOTAL,
};

#ifdef CONFIG_HUAWEI_BUCK_CHARGER
/* variable and function declarationn area */
struct charge_core_data *charge_core_get_params(void);
#else
static inline struct charge_core_data *charge_core_get_params(void)
{
	return NULL;
}
#endif /* CONFIG_HUAWEI_BUCK_CHARGER */
#endif /* _CHARGING_CORE_ */
