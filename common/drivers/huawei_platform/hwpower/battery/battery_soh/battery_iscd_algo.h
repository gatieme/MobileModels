 /* SPDX-License-Identifier: GPL-2.0 */
 /*
  * battery_iscd_algo.h
  *
  * algorithem for battery iscd
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

#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>

#define PERMILLAGE              1000
#define SOC_FULL                100
#define ISCD_OCV_PARA_LEVEL     10 /* soc level:55 60 65 70 75 80 85 90 95 100 */
#define ISCD_OCV_GROUP_SIZE     3 /* 10degree 25degree 40degree */
#define ISCD_OCV_LUT_LEN_MAX    20


struct lut_info {
	int temp_low;
	int temp_high;
	char para_index[ISCD_OCV_LUT_LEN_MAX];
};

struct ocv_info {
	int ocv;
	int soc;
};

struct ocv_info_group {
	struct lut_info lut_para;
	struct ocv_info ocv_para[ISCD_OCV_PARA_LEVEL];
};

struct pc_ocv_lut_info {
	int lut_num;
	int rows;
	int cols;
	struct ocv_info_group ocv_info_group[ISCD_OCV_GROUP_SIZE];
};

int get_qmax_with_basp(void);
int linear_interpolate(int y0, int x0, int y1, int x1, int x);
int is_between(int left, int right, int value);
int calc_pc_between_temps(const struct pc_ocv_lut_info lut,
	int batt_temp, int ocv, int j);
int interpolate_pc_high_precision(const struct pc_ocv_lut_info lut,
	int batt_temp, int ocv);
int calc_pc_by_ocv(const struct pc_ocv_lut_info lut, int ocv, int i, int j);
int cal_uah_by_ocv(struct pc_ocv_lut_info lut, int batt_temp, int ocv_uv, int *ocv_soc_uah);
