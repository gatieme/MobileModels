 /* SPDX-License-Identifier: GPL-2.0 */
 /*
  * battery_iscd_algo.h
  *
  * algorithem for battery iscd
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

#include "battery_iscd_algo.h"

#define HWLOG_TAG battery_iscd
HWLOG_REGIST();
/* get y according to : y = ax +b, a = (y1 - y0) / (x1 - x0) */
int linear_interpolate(int y0, int x0, int y1, int x1, int x)
{
	if ((y0 == y1) || (x == x0))
		return y0;
	if ((x1 == x0) || (x == x1))
		return y1;

	return y0 + ((y1 - y0) * (x - x0) / (x1 - x0));
}

/* judge whether value locates in zone [left, right] or [right, left] 1: yes 0: no */
int is_between(int left, int right, int value)
{
	if ((left >= right) && (left >= value) && (value >= right))
		return 1;
	if ((left <= right) && (left <= value) && (value <= right))
		return 1;

	return 0;
}

int calc_pc_by_ocv(const struct pc_ocv_lut_info lut, int ocv,
	int i, int j)
{
	int pc;

	if ((i >= ISCD_OCV_PARA_LEVEL) || (j >= ISCD_OCV_GROUP_SIZE)) {
		hwlog_err("calc_pc_by_ocv input invalid: i=%d, j=%d\n", i, j);
		return -EINVAL;
	}

	if ((ocv == lut.ocv_info_group[j].ocv_para[i].ocv) || (i == 0))
		return lut.ocv_info_group[j].ocv_para[i].soc * PERMILLAGE;
	pc = linear_interpolate(lut.ocv_info_group[j].ocv_para[i].soc * PERMILLAGE,
		lut.ocv_info_group[j].ocv_para[i].ocv,
		lut.ocv_info_group[j].ocv_para[i - 1].soc * PERMILLAGE,
		lut.ocv_info_group[j].ocv_para[i - 1].ocv, ocv);
	hwlog_err("calc_pc_by_ocv pc %d\n", pc);
	return pc;
}

static int calc_pc_by_ocv_not_exceed_bound(
	struct pc_ocv_lut_info lut, int batt_temp, int ocv, int j, int rows)
{
	int i, pcj, pcj_minus_one, pc;

	if ((rows >= ISCD_OCV_PARA_LEVEL) || (j >= ISCD_OCV_GROUP_SIZE)) {
		hwlog_err("calc_pc_by_ocv input invalid: i=%d, j=%d\n", i, j);
		return -EINVAL;
	}

	pcj_minus_one = 0;
	pcj = 0;
	for (i = 0; i < rows - 1; i++) {
		if ((pcj == 0) &&
			is_between(lut.ocv_info_group[j].ocv_para[i].ocv,
				lut.ocv_info_group[j].ocv_para[i + 1].ocv, ocv))
			pcj = linear_interpolate(
				lut.ocv_info_group[j].ocv_para[i].soc * PERMILLAGE,
				lut.ocv_info_group[j].ocv_para[i].ocv,
				lut.ocv_info_group[j].ocv_para[i + 1].soc * PERMILLAGE,
				lut.ocv_info_group[j].ocv_para[i + 1].ocv, ocv);

		if ((pcj_minus_one == 0) &&
			is_between(lut.ocv_info_group[j - 1].ocv_para[i].ocv,
				lut.ocv_info_group[j - 1].ocv_para[i + 1].ocv, ocv))
			pcj_minus_one = linear_interpolate(
				lut.ocv_info_group[j].ocv_para[i].soc * PERMILLAGE,
				lut.ocv_info_group[j - 1].ocv_para[i].ocv,
				lut.ocv_info_group[j].ocv_para[i + 1].soc * PERMILLAGE,
				lut.ocv_info_group[j - 1].ocv_para[i + 1].ocv, ocv);

		if (pcj && pcj_minus_one) {
			pc = linear_interpolate(pcj_minus_one,
				lut.ocv_info_group[j - 1].lut_para.temp_low,
				pcj, lut.ocv_info_group[j].lut_para.temp_low, batt_temp);
			return pc;
		}
	}
	hwlog_err("pcj %d, pcj_minus_one %d\n", pcj, pcj_minus_one);
	if (pcj)
		return pcj;

	if (pcj_minus_one)
		return pcj_minus_one;

	hwlog_err("%d ocv wasn't found for temp %d in the LUT returning 100%\n", ocv, batt_temp);
	return PERMILLAGE * SOC_FULL;
}

int calc_pc_between_temps(const struct pc_ocv_lut_info lut,
	int batt_temp, int ocv, int j)
{
	int pcj, pcj_minus_one, pc, rows;

	rows = lut.rows;
	pcj_minus_one = 0;
	pcj = 0;
	if (ocv >= lut.ocv_info_group[j].ocv_para[0].ocv) {
		pcj = linear_interpolate(lut.ocv_info_group[j].ocv_para[0].soc * PERMILLAGE,
			lut.ocv_info_group[j].ocv_para[0].ocv,
			lut.ocv_info_group[j].ocv_para[1].soc * PERMILLAGE,
			lut.ocv_info_group[j].ocv_para[1].ocv, ocv);
		pcj_minus_one = linear_interpolate(lut.ocv_info_group[j].ocv_para[0].soc * PERMILLAGE,
			lut.ocv_info_group[j - 1].ocv_para[0].ocv,
			lut.ocv_info_group[j].ocv_para[1].soc * PERMILLAGE,
			lut.ocv_info_group[j - 1].ocv_para[0].ocv, ocv);
		if (pcj && pcj_minus_one) {
			pc = linear_interpolate(pcj_minus_one,
				lut.ocv_info_group[j - 1].lut_para.temp_low,
				pcj, lut.ocv_info_group[j].lut_para.temp_low, batt_temp);
			return pc;
		}
		if (pcj)
			return pcj;

		if (pcj_minus_one)
			return pcj_minus_one;
	}

	if (ocv <= lut.ocv_info_group[j - 1].ocv_para[rows - 1].ocv)
		return lut.ocv_info_group[j - 1].ocv_para[rows - 1].soc * PERMILLAGE;

	return calc_pc_by_ocv_not_exceed_bound(lut, batt_temp, ocv, j, rows);
}

 /* look for pc, percent of uah, may exceed PERMILLAGE * SOC_FULL */
int interpolate_pc_high_precision(const struct pc_ocv_lut_info lut,
	int batt_temp, int ocv)
{
	int i, j, pc, rows;

	/* batt_temp is in tenths of degC - convert it to degC for lookups */
	batt_temp = batt_temp / POWER_TENTH;
	hwlog_err("batt_temp %d ocv %d\n", batt_temp, ocv);

	if (lut.lut_num < 1) {
		hwlog_err("lut_num:%d are small in [%s]\n",
			lut.lut_num, __func__);
		return PERMILLAGE * SOC_FULL;
	}

	rows = lut.rows;
	batt_temp = clamp_val(batt_temp, lut.ocv_info_group[0].lut_para.temp_low,
		lut.ocv_info_group[0].lut_para.temp_high);
	for (j = 0; j < lut.cols; j++) {
		if (batt_temp <= lut.ocv_info_group[j].lut_para.temp_high)
			break;
	}

	/* temp match edge or smaller than lowest */
	if ((batt_temp == lut.ocv_info_group[j].lut_para.temp_low || (j == 0))) {
		/* found an exact match for temp in the table */
		if (ocv >= lut.ocv_info_group[j].ocv_para[0].ocv) {   /* bigger than biggest ocv when temp match */
			pc = linear_interpolate(lut.ocv_info_group[j].ocv_para[1].soc * PERMILLAGE,
				lut.ocv_info_group[j].ocv_para[1].ocv,
				lut.ocv_info_group[j].ocv_para[0].soc * PERMILLAGE,
				lut.ocv_info_group[j].ocv_para[0].ocv, ocv);
			return pc;
		}

		/* smaller than smallest ocv when temp match */
		if (ocv <= lut.ocv_info_group[j].ocv_para[rows - 1].ocv)
			return lut.ocv_info_group[j].ocv_para[rows - 1].soc * PERMILLAGE;
		for (i = 0; i < rows; i++) {
			if (ocv >= lut.ocv_info_group[j].ocv_para[i].ocv)
				return calc_pc_by_ocv(lut, ocv, i, j);
		}
	}

	/* batt_temp is within temperature for column j-1 and j */
	return calc_pc_between_temps(lut, batt_temp, ocv, j);
}

/* need wait basp take action and gauge learn fcc done */
int get_qmax_with_basp()
{
	int fcc;
	int vdec;
	int qmax_decrease_percent;
	int qmax_decrease;
	int voltage_max_set;
	int voltage_max_design;
	int calculate_temp = 10;    /* avoid compile error when transfer int to float */

	if (power_supply_get_int_property_value("battery",
		POWER_SUPPLY_PROP_CHARGE_FULL, &fcc)) {
		hwlog_err("get fcc failed\n");
		return -ENOENT;
	}

	if (power_supply_get_int_property_value("battery",
		POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN, &voltage_max_design)) {
		hwlog_err("get voltage max design of battery failed\n");
		return -ENOENT;
	}

	if (power_supply_get_int_property_value("battery",
		POWER_SUPPLY_PROP_VOLTAGE_MAX, &voltage_max_set)) {
		hwlog_err("get voltage max failed\n");
		return -ENOENT;
	}

	vdec = voltage_max_design - voltage_max_set;
	if (vdec >= voltage_max_design || vdec < 0)
		return -EINVAL;

	qmax_decrease_percent = calculate_temp * (vdec / 10) / POWER_UV_PER_MV; /* every 10mv decrease 1% qmax */
	qmax_decrease = fcc * qmax_decrease_percent / (POWER_PERCENT * calculate_temp);
	hwlog_err("iscd_get_qmax fcc %d, vdec %d , decrease_percent %d qmax_decrease %d\n",
		fcc, vdec, qmax_decrease_percent, qmax_decrease);

	return fcc + qmax_decrease;
}

int cal_uah_by_ocv(struct pc_ocv_lut_info lut, int batt_temp, int ocv_uv, int *ocv_soc_uah)
{
	int pc;
	long long qmax;

	if ((lut.lut_num < 1) || (!ocv_soc_uah)) {
		hwlog_err("[%s] para null\n", __func__);
		return -EINVAL;
	}

	qmax = get_qmax_with_basp();
	if (qmax < 0)
		hwlog_err("qmax invalid");

	pc = interpolate_pc_high_precision(lut,
		batt_temp, ocv_uv / POWER_UV_PER_MV);

	hwlog_err("qmax = %llduAh, pc = %d/100000, ocv_soc = %llduAh\n",
		qmax, pc, qmax * pc / (SOC_FULL * PERMILLAGE));
	*ocv_soc_uah = (int)(qmax * pc / (SOC_FULL * PERMILLAGE));

	return ((*ocv_soc_uah > 0) ? 0 : -EINVAL);
}
