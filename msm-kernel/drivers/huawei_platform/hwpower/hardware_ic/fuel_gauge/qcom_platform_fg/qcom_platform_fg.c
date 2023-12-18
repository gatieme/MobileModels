// SPDX-License-Identifier: GPL-2.0
/*
 * qcom_platform_fg.c
 *
 * huawei qcom platform fuel guage driver
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

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/power_supply.h>
#include <linux/platform_device.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>
#include <huawei_platform/hwpower/common_module/power_glink.h>
#include <huawei_platform/hwpower/common_module/power_glink_interface.h>
#include <huawei_platform/hwpower/hardware_ic/qcom_platform_fg.h>
#include <chipset_common/hwpower/common_module/power_supply_interface.h>
#include <chipset_common/hwpower/common_module/power_devices_info.h>
#include <chipset_common/hwpower/common_module/power_common_macro.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_nv.h>
#include <chipset_common/hwpower/common_module/power_log.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <chipset_common/hwpower/battery/battery_model_public.h>
#include <chipset_common/hwpower/battery/battery_ocv.h>
#include <chipset_common/hwpower/battery/battery_soh.h>
#include <chipset_common/hwpower/coul/coul_nv_pool.h>
#include <chipset_common/hwpower/coul/coul_interface.h>
#include <chipset_common/hwpower/coul/coul_calibration.h>
#include <chipset_common/hwpower/hardware_monitor/ffc_control.h>
#include <chipset_common/hwmanufac/dev_detect/dev_detect.h>

#define HWLOG_TAG qplat_fg
HWLOG_REGIST();

static unsigned int g_qplat_fg_data[QPLAT_FG_MAX];
static struct qplat_fg_device *g_qplat_fg_dev;

static struct qplat_fg_device *qplat_fg_get_dev(void)
{
	if (!g_qplat_fg_dev) {
		hwlog_err("g_qplat_fg_dev is null\n");
		return NULL;
	}

	return g_qplat_fg_dev;
}

static void qplat_fg_parse_soft_reset(struct device_node *np,
	struct qplat_fg_device *di)
{
	int row, col, len;
	int idata[QPLAT_FG_VBAT_SOC_TABLE_ROW * QPLAT_FG_PAIR_TOTAL] = { 0 };

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np,
		"en_soft_reset", (u32 *)&di->en_soft_reset, 0);
	len = power_dts_read_string_array(power_dts_tag(HWLOG_TAG), np,
		"vbat_soc_table", idata, QPLAT_FG_VBAT_SOC_TABLE_ROW, QPLAT_FG_PAIR_TOTAL);
	if (len < 0)
		return;

	for (row = 0; row < len / QPLAT_FG_PAIR_TOTAL; row++) {
		col = row * QPLAT_FG_PAIR_TOTAL + QPLAT_FG_PAIR_VOLT_MIN;
		di->vbat_soc_pair[row].volt_min = idata[col];
		col = row * QPLAT_FG_PAIR_TOTAL + QPLAT_FG_PAIR_VOLT_MAX;
		di->vbat_soc_pair[row].volt_max = idata[col];
		col = row * QPLAT_FG_PAIR_TOTAL + QPLAT_FG_PAIR_SOC_U;
		di->vbat_soc_pair[row].soc_u = idata[col];

		hwlog_info("vbat_soc_table[%d]=%d %d %d\n", row,
			di->vbat_soc_pair[row].volt_min,
			di->vbat_soc_pair[row].volt_max,
			di->vbat_soc_pair[row].soc_u);
	}
}

static int get_soc_u(int vbat, struct qplat_fg_device *di)
{
	int i = 0;

	for (; i < QPLAT_FG_VBAT_SOC_TABLE_ROW; i++) {
		if ((vbat > di->vbat_soc_pair[i].volt_min) &&
			(vbat <= di->vbat_soc_pair[i].volt_max))
			return di->vbat_soc_pair[i].soc_u;
	}

	return -EPERM;
}

static void qplat_fg_reset_impl(struct qplat_fg_device *di)
{
	hwlog_info("%s qplat_fg need reset\n", __func__);
}

static void qplat_fg_soft_reset(struct qplat_fg_device *di)
{
	int min_vbat;
	int soc_u;
	char buf[POWER_DSM_BUF_SIZE_0128] = { 0 };
	u8 need_reset = 0;

	if (di->curr < QPLAT_FG_DISCHARGE_THRESHOLD) {
		di->ibat_record[di->record_idx] = di->curr;
		di->vbat_record[di->record_idx] = di->voltage;
		di->record_idx++;
	} else {
		di->record_idx = 0;
	}
	if (di->record_idx >= QPLAT_FG_RECORD_NUM) {
		min_vbat = power_get_min_value(di->vbat_record, QPLAT_FG_RECORD_NUM);
		soc_u = get_soc_u(min_vbat, di);
		if ((soc_u > 0) && ((soc_u - di->ui_soc) > QPLAT_FG_MAX_SOC_DIFF))
			need_reset = 1;
		di->record_idx = 0;
	}
	if (need_reset ||
		((di->ui_soc <= QPLAT_FG_FLAG_UPDATE_SOC) && (charge_get_done_type() == CHARGE_DONE))) {
		if (need_reset == 0)
			soc_u = QPLAT_FG_FULL_CAP;
		qplat_fg_reset_impl(di);
		hwlog_info("%s done, need_reset=%d\n", __func__, need_reset);
		if (!di->dmd_report_flag) {
			di->dmd_report_flag = true;
			snprintf(buf, POWER_DSM_BUF_SIZE_0128 - 1,
				"name=qplat_fgxxx,workaround=%d,vbat=%d,curr=%d,temp=%d,cycle=%d,soc_u=%d,soc=%d,diff_thres=%d\n",
				need_reset + 1, di->voltage, di->curr, di->temp, di->cycle, soc_u, di->ui_soc, QPLAT_FG_MAX_SOC_DIFF);
			power_dsm_report_dmd(POWER_DSM_PMU_BMS, DSM_PMU_BMS_BATTERY_VOL_SOC_DISMATCH, buf);
		}
	}
}

static int qplat_fg_is_ready(void *dev_data)
{
	struct qplat_fg_device *di = dev_data;

	if (!di)
		return 0;

	return 1;
}

static int qplat_fg_read_battery_temperature(void *dev_data)
{
	int temp = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_TEMP, &temp))
		return POWER_INVALID_TEMPERATURE;

	return temp;
}

static int qplat_fg_is_battery_exist(void *dev_data)
{
	int present = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_PRESENT, &present))
		return -EPERM;

	return present;
}

static int qplat_fg_read_battery_soc(void *dev_data)
{
	int soc = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CAPACITY, &soc))
		return -EPERM;

	return soc;
}

static int qplat_fg_read_battery_vol(void *dev_data)
{
	int vol = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_VOLTAGE_NOW, &vol))
		return -EPERM;

	return vol / POWER_UV_PER_MV;
}

static int qplat_fg_read_battery_current(void *dev_data)
{
	int cur = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CURRENT_NOW, &cur)) {
		hwlog_err("bk get current failed\n");
		return 0;
	}

	return cur;
}

static int qplat_fg_read_battery_avg_current(void *dev_data)
{
	int avg = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CURRENT_NOW, &avg))
		return 0;

	return avg;
}

static int qplat_fg_read_battery_fcc(void *dev_data)
{
	int fcc = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CHARGE_FULL, &fcc))
		return -EPERM;

	return fcc / POWER_UA_PER_MA;
}

static int qplat_fg_read_battery_cycle(void *dev_data)
{
	int ic_cycle = 0; /* cycle detected by ic */
	int acc_cycle = 0; /* accumulated cycle */

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CYCLE_COUNT, &ic_cycle))
		return -EPERM;

	(void)coul_nv_pool_set_para(COUL_NV_POOL_IC_TYPE_MAIN, COUL_NV_POOL_TEMP_CYCLE, ic_cycle);
	(void)coul_nv_pool_get_para(COUL_NV_POOL_IC_TYPE_MAIN, COUL_NV_POOL_TOTAL_CYCLE, &acc_cycle);
	acc_cycle += ic_cycle;

	return acc_cycle;
}

static int qplat_fg_read_battery_rm(void *dev_data)
{
	int rm = 0;
	int cap = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CAPACITY, &cap))
		return -EPERM;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CHARGE_FULL, &rm))
		return -EPERM;

	return rm * cap / QPLAT_FG_FULL_CAP;
}

static int qplat_fg_read_battery_charge_counter(void *dev_data)
{
	int rm = 0;
	int cap = 0;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CAPACITY, &cap))
		return -EPERM;

	if (power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CHARGE_FULL, &rm))
		return -EPERM;

	return rm * cap / QPLAT_FG_FULL_CAP;
}

static int qplat_fg_set_battery_low_voltage(int val, void *dev_data)
{
	return 0;
}

static int qplat_fg_set_last_capacity(int capacity, void *dev_data)
{
	int ret;
	struct qplat_fg_device *di = dev_data;

	if (!di || (capacity > QPLAT_FG_FULL_CAP) || (capacity < 0))
		return 0;

	ret = power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_LAST_CAP_REG_VALUE,
		&capacity, GLINK_DATA_ONE);
	if (ret) {
		hwlog_err("failed to set original reg val of last cap\n");
		return ret;
	}
	hwlog_info("set_last_capacity:%d cap\n", capacity);

	return 0;
}

static int qplat_fg_get_last_capacity(void *dev_data)
{
	int ret;
	int last_cap = 0;
	int reset_cap = 0;
	struct qplat_fg_device *di = dev_data;
	int cap = qplat_fg_read_battery_soc(di);

	if (!di)
		return last_cap;

	ret = power_glink_interface_get_property_value(POWER_GLINK_PROP_ID_LAST_CAP_REG_VALUE,
		&last_cap, GLINK_DATA_ONE);
	if (ret) {
		hwlog_err("failed to get original reg val of last cap\n");
		return cap;
	}

	hwlog_info("get_last_capacity last:%d,cur:%d\n", last_cap, cap);
	if ((last_cap <= 0) || (cap <= 0))
		return cap;

	if (abs(last_cap - cap) >= QPLAT_FG_CAPACITY_TH)
		return cap;

	ret = power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_LAST_CAP_REG_VALUE,
		&reset_cap, GLINK_DATA_ONE);
	if (ret) {
		hwlog_err("failed to reset last cap\n");
		return cap;
	}

	return last_cap;
}

static int qplat_fg_set_vterm_dec(int vterm, void *dev_data)
{
	return 0;
}

static const char *qplat_fg_get_coul_model(void *dev_data)
{
	return "qplat_fgxxx";
}

static struct coul_interface_ops qplat_fg_ops = {
	.type_name = "main",
	.is_coul_ready = qplat_fg_is_ready,
	.is_battery_exist = qplat_fg_is_battery_exist,
	.get_battery_capacity = qplat_fg_read_battery_soc,
	.get_battery_voltage = qplat_fg_read_battery_vol,
	.get_battery_current = qplat_fg_read_battery_current,
	.get_battery_avg_current = qplat_fg_read_battery_avg_current,
	.get_battery_temperature = qplat_fg_read_battery_temperature,
	.get_battery_fcc = qplat_fg_read_battery_fcc,
	.get_battery_cycle = qplat_fg_read_battery_cycle,
	.set_battery_low_voltage = qplat_fg_set_battery_low_voltage,
	.get_battery_last_capacity = qplat_fg_get_last_capacity,
	.set_battery_last_capacity = qplat_fg_set_last_capacity,
	.get_battery_rm = qplat_fg_read_battery_rm,
	.get_battery_charge_counter = qplat_fg_read_battery_charge_counter,
	.set_vterm_dec = qplat_fg_set_vterm_dec,
	.get_coul_model = qplat_fg_get_coul_model,
};

static void qplat_fg_get_nv_data(struct qplat_fg_device *di)
{
	int total_cycle = 0;
	int temp_cycle = 0;

	(void)coul_nv_pool_get_para(COUL_NV_POOL_IC_TYPE_MAIN, COUL_NV_POOL_OCV_INDEX, &di->ocv_idx);
	(void)coul_nv_pool_get_para(COUL_NV_POOL_IC_TYPE_MAIN, COUL_NV_POOL_TOTAL_CYCLE, &total_cycle);
	(void)coul_nv_pool_get_para(COUL_NV_POOL_IC_TYPE_MAIN, COUL_NV_POOL_TEMP_CYCLE, &temp_cycle);

	hwlog_info("ocv_idx=%d, total_cycle=%d, temp_cycle=%d\n",
		di->ocv_idx, total_cycle, temp_cycle);
}

static int qplat_fg_get_calibration_curr(int *val, void *dev_data)
{
	struct qplat_fg_device *di = dev_data;

	if (!di || !val) {
		hwlog_err("di or val is null\n");
		return -EPERM;
	}

	*val = qplat_fg_read_battery_current(di);

	return 0;
}

static int qplat_fg_get_calibration_vol(int *val, void *dev_data)
{
	struct qplat_fg_device *di = dev_data;
	int vol;

	if (!di || !val) {
		hwlog_err("di or val is null\n");
		return -EPERM;
	}

	vol = qplat_fg_read_battery_vol(di);
	if (vol < 0)
		return vol;

	*val = vol * POWER_UV_PER_MV;

	return 0;
}

static unsigned int qplat_fg_get_curr_cali_reg_val(unsigned int k_reg, unsigned int val)
{
	long long k_actual = k_reg;
	long long curr_gain = val;
	long long k_actual_comp;
	unsigned int k_reg_val;

	k_actual -= (POWER_U16_MAX + 1);
	k_actual_comp = k_actual * curr_gain / QPLAT_FG_DEFAULT_CURR_GAIN;
	k_actual_comp += (POWER_U16_MAX + 1);
	k_reg_val = k_actual_comp;
	hwlog_info("k_reg_old: %u k_reg_new: %u curr_gain:%d\n",
		k_reg, k_reg_val, curr_gain);

	return k_reg_val;
}

static int qplat_fg_set_current_gain(unsigned int val, void *dev_data)
{
	struct qplat_fg_device *di = dev_data;
	int ret = 0;
	unsigned int k_reg;
	unsigned int k_reg_o;

	if (val == 0) {
		hwlog_err("invalid val of current gain\n");
		return ret;
	}

	if (!di) {
		hwlog_err("di or val is null\n");
		return -EPERM;
	}

	ret = power_nv_read(POWER_NV_QCOUL, g_qplat_fg_data, sizeof(g_qplat_fg_data));
	if (ret) {
		hwlog_err("power_nv_read fail\n");
		return ret;
	}

	k_reg_o = g_qplat_fg_data[QPLAT_FG_CURR_CALI_REGISTER];
	if (k_reg_o == 0) {
		ret = power_glink_interface_get_property_value(POWER_GLINK_PROP_ID_CURR_CALI,
			&k_reg_o, GLINK_DATA_ONE);
		if (ret) {
			hwlog_err("power_glink_get_property_value fail\n");
			return ret;
		}
	}

	k_reg = qplat_fg_get_curr_cali_reg_val(k_reg_o, val);

	ret = power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_CURR_CALI,
		&k_reg, GLINK_DATA_ONE);
	if (ret) {
		hwlog_err("power_glink_set_property_value fail\n");
		return ret;
	}

	g_qplat_fg_data[QPLAT_FG_CURR_CALI_REGISTER] = k_reg_o;
	ret = power_nv_write(POWER_NV_QCOUL, g_qplat_fg_data, sizeof(g_qplat_fg_data));

	return ret;
}

static int qplat_fg_set_voltage_gain(unsigned int val, void *dev_data)
{
	return 0;
}

static int qplat_fg_enable_cali_mode(int enable, void *dev_data)
{
	return 0;
}

static struct coul_cali_ops qplat_fg_cali_ops = {
	.dev_name = "aux",
	.get_current = qplat_fg_get_calibration_curr,
	.get_voltage = qplat_fg_get_calibration_vol,
	.set_current_gain = qplat_fg_set_current_gain,
	.set_voltage_gain = qplat_fg_set_voltage_gain,
	.set_cali_mode = qplat_fg_enable_cali_mode,
};

static int qplat_fg_get_log_head(char *buffer, int size, void *dev_data)
{
	struct qplat_fg_device *di = dev_data;

	if (!di || !buffer)
		return -EPERM;

	snprintf(buffer, size, "Qtemp   Qvbat   Qibat   Qrm      Qsoc   Qfcc   ");

	return 0;
}

static int qplat_fg_dump_log_data(char *buffer, int size, void *dev_data)
{
	struct qplat_fg_device *di = dev_data;
	struct qplat_fg_display_data dis_data;

	if (!di || !buffer)
		return -EPERM;

	dis_data.vbat = qplat_fg_read_battery_vol(di);
	dis_data.ibat = qplat_fg_read_battery_current(di);
	dis_data.rm = qplat_fg_read_battery_rm(di);
	dis_data.temp = qplat_fg_read_battery_temperature(di);
	dis_data.soc = qplat_fg_read_battery_soc(di);
	dis_data.fcc = qplat_fg_read_battery_fcc(di);
	snprintf(buffer, size, "%-8d%-8d%-8d%-9d%-7d%-7d",
		dis_data.temp, dis_data.vbat, dis_data.ibat,
		dis_data.rm, dis_data.soc, dis_data.fcc);

	return 0;
}

static struct power_log_ops qplat_fg_log_ops = {
	.dev_name = "qplat_fg",
	.dump_log_head = qplat_fg_get_log_head,
	.dump_log_content = qplat_fg_dump_log_data,
};

static void qplat_fg_cali_init(void)
{
	unsigned int val_reg;
	unsigned int k_reg;
	unsigned int curr_gain = 0;

	coul_cali_get_para(COUL_CALI_MODE_AUX, COUL_CALI_PARA_CUR_A, &curr_gain);
	power_nv_read(POWER_NV_QCOUL, g_qplat_fg_data, sizeof(g_qplat_fg_data));
	k_reg = g_qplat_fg_data[QPLAT_FG_CURR_CALI_REGISTER];
	hwlog_info("curr_gain: %u k_reg: %u", curr_gain, k_reg);
	if ((curr_gain == 0) || (k_reg == 0))
		return;

	val_reg = qplat_fg_get_curr_cali_reg_val(k_reg, curr_gain);
	if (power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_CURR_CALI,
		&val_reg, GLINK_DATA_ONE))
		hwlog_err("fail to set original reg val of curr cali\n");
}

static void qplat_fg_dynamic_change_iterm_setting(struct qplat_fg_device *di, struct ffc_ctrl_charge_info *ndata)
{
	int next_iterm;

	if (!ndata || !di->dynamic_change_iterm_en || (ndata->iterm <= 0))
		return;

	next_iterm = ndata->iterm + di->iterm_delta;
	if ((di->iterm != next_iterm) && (di->iterm >= 0)) {
		if (power_glink_interface_set_property_value(POWER_GLINK_PROP_ID_SET_IBATT_FULL,
			&next_iterm, GLINK_DATA_ONE)) {
			hwlog_err("fail to set original reg val of ibatt full\n");
			return;
		}
		hwlog_info("set ibatt full val: %d\n", next_iterm);
		di->iterm = next_iterm;
	}
}

static int qplat_fg_event_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct qplat_fg_device *di = qplat_fg_get_dev();
	int cycle;

	if (!di || !di->launch_flag)
		return NOTIFY_OK;

	switch (event) {
	case POWER_NE_BUCK_FFC_CHARGE:
		qplat_fg_dynamic_change_iterm_setting(di, data);
		break;
	case POWER_NE_CHARGING_START:
		di->dmd_report_flag = false;
		cycle = qplat_fg_read_battery_cycle(di); /* trggered cycle calculation */
		hwlog_info("charging start cycle=%d\n", cycle);
		break;
	case POWER_NE_CHARGING_STOP:
	case POWER_NE_CHARGING_SUSPEND:
		di->dmd_report_flag = false;
		break;
	default:
		return NOTIFY_OK;
	}

	hwlog_info("receive event=%lu\n", event);

	return NOTIFY_OK;
}

static int qplat_fg_ocv_change_event_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct qplat_fg_device *di = container_of(nb, struct qplat_fg_device, ocv_change_event_nb);
	int cutoff_voltage = 3100; /* 3100: default cutoff voltage in ADSP */
	int ret;

	if (!di || !di->launch_flag)
		return NOTIFY_OK;

	hwlog_info("receive event=%lu\n", event);

	switch (event) {
	case POWER_NE_BATTERY_OCV_CHANGE:
		ret = battery_ocv_get_ocv_by_cap(BATTERY_OCV_CUTOFF_CAPACITY, &cutoff_voltage);
		if (ret) {
			hwlog_info("get ocv cutoff error, ret:%d\n", ret);
			break;
		}
		ret = power_glink_interface_set_property_value(
			POWER_GLINK_PROP_ID_SET_CUTOFF_VOLTAGE_FOR_BASP, &cutoff_voltage, GLINK_DATA_ONE);
		if (ret)
			hwlog_info("set ocv cutoff error, ret:%d\n", ret);
		break;
	default:
		return NOTIFY_OK;
	}

	return NOTIFY_OK;
}

static void qplat_fg_update_data(struct qplat_fg_device *di)
{
	di->voltage = qplat_fg_read_battery_vol(di);
	di->curr = qplat_fg_read_battery_current(di);
	di->ui_soc = qplat_fg_read_battery_soc(di);
	di->temp = qplat_fg_read_battery_temperature(di);
	di->cycle = qplat_fg_read_battery_cycle(di);

	hwlog_info("vol=%d current=%d cap=%d temp=%d cycle=%d\n",
		di->voltage, di->curr, di->ui_soc, di->temp, di->cycle);
}

static void qplat_fg_bat_work(struct work_struct *work)
{
	struct delayed_work *delay_work = NULL;
	struct qplat_fg_device *di = NULL;

	delay_work = container_of(work, struct delayed_work, work);
	if (!delay_work)
		return;
	di = container_of(delay_work, struct qplat_fg_device, battery_delay_work);
	if (!di)
		return;

	qplat_fg_update_data(di);

	if (di->en_soft_reset)
		qplat_fg_soft_reset(di);

	queue_delayed_work(di->qbg_workqueue, &di->battery_delay_work,
		msecs_to_jiffies(QPLAT_FG_QUEUE_DELAYED_WORK_TIME));
}

int qplat_fg_register(void)
{
	struct power_devices_info_data *power_dev_info = NULL;
	struct qplat_fg_device *di = g_qplat_fg_dev;

	if (!di)
		return -EPERM;

	(void)bat_model_name();
	qplat_fg_cali_init();
	qplat_fg_log_ops.dev_data = (void *)di;
	power_log_ops_register(&qplat_fg_log_ops);
	qplat_fg_ops.dev_data = di;
	coul_interface_ops_register(&qplat_fg_ops);
	qplat_fg_cali_ops.dev_data = di;
	coul_cali_ops_register(&qplat_fg_cali_ops);
	power_dev_info = power_devices_info_register();
	if (power_dev_info) {
		power_dev_info->dev_name = di->dev->driver->name;
		power_dev_info->dev_id = 0;
		power_dev_info->ver_id = 0;
	}
	if (!di->en_basp)
		bsoh_unregister_sub_sys(BSOH_SUB_SYS_BASP);
	di->launch_flag = true;
	di->qbg_workqueue = create_singlethread_workqueue("qbg_gauge");
	INIT_DELAYED_WORK(&di->battery_delay_work, qplat_fg_bat_work);
	queue_delayed_work(di->qbg_workqueue, &di->battery_delay_work,
		msecs_to_jiffies(QPLAT_FG_QUEUE_DELAYED_WORK_TIME));

	return 0;
}
EXPORT_SYMBOL_GPL(qplat_fg_register);

static int qplat_fg_parse_dts(struct qplat_fg_device *di)
{
	struct device_node *np = di->dev->of_node;

	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "iterm_delta",
		&di->iterm_delta, QPLAT_FG_DEFAULT_ITERM_DELTA);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "dynamic_change_iterm_en",
		&di->dynamic_change_iterm_en, 0);
	(void)power_dts_read_u32(power_dts_tag(HWLOG_TAG), np, "en_basp",
		&di->en_basp, 0);
	qplat_fg_parse_soft_reset(np, di);

	return 0;
}

static int qplat_fg_probe(struct platform_device *pdev)
{
	struct qplat_fg_device *di = NULL;
	int ret;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;

	ret = qplat_fg_parse_dts(di);
	if (ret) {
		hwlog_err("parse dts err\n");
		return ret;
	}

	qplat_fg_get_nv_data(di);
	di->qplat_fg_event_nb.notifier_call = qplat_fg_event_notifier_call;
	power_event_bnc_register(POWER_BNT_CHARGING, &di->qplat_fg_event_nb);
	di->qplat_fg_event_buck_nb.notifier_call = qplat_fg_event_notifier_call;
	power_event_bnc_register(POWER_BNT_BUCK_CHARGE, &di->qplat_fg_event_buck_nb);
	di->ocv_change_event_nb.notifier_call = qplat_fg_ocv_change_event_notifier_call;
	power_event_bnc_register(POWER_BNT_BATTERY, &di->ocv_change_event_nb);

	g_qplat_fg_dev = di;
	platform_set_drvdata(pdev, di);

	return 0;
}

static int qplat_fg_remove(struct platform_device *pdev)
{
	struct qplat_fg_device *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;

	power_event_bnc_unregister(POWER_BNT_BATTERY, &di->ocv_change_event_nb);
	power_event_bnc_unregister(POWER_BNT_BUCK_CHARGE, &di->qplat_fg_event_buck_nb);
	power_event_bnc_unregister(POWER_BNT_CHARGING, &di->qplat_fg_event_nb);
	g_qplat_fg_dev = NULL;
	return 0;
}

#ifdef CONFIG_PM
static int qplat_fg_resume(struct platform_device *pdev)
{
	struct qplat_fg_device *di = platform_get_drvdata(pdev);

	if (!di)
		return 0;

	di->record_idx = 0;
	queue_delayed_work(di->qbg_workqueue, &di->battery_delay_work,
		msecs_to_jiffies(QPLAT_FG_QUEUE_DELAYED_WORK_TIME));

	return 0;
}

static int qplat_fg_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct qplat_fg_device *di = platform_get_drvdata(pdev);

	if (!di)
		return 0;

	cancel_delayed_work_sync(&di->battery_delay_work);

	return 0;
}
#endif /* CONFIG_PM */

static const struct of_device_id qplat_fg_match_table[] = {
	{
		.compatible = "huawei,qcom_platform_fg",
		.data = NULL,
	},
	{},
};

static struct platform_driver qplat_fg_driver = {
	.probe = qplat_fg_probe,
	.remove = qplat_fg_remove,
#ifdef CONFIG_PM
	.resume = qplat_fg_resume,
	.suspend = qplat_fg_suspend,
#endif /* CONFIG_PM */
	.driver = {
		.name = "huawei,qcom_platform_fg",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(qplat_fg_match_table),
	},
};

static int __init qplat_fg_init(void)
{
	return platform_driver_register(&qplat_fg_driver);
}

static void __exit qplat_fg_exit(void)
{
	platform_driver_unregister(&qplat_fg_driver);
}

subsys_initcall_sync(qplat_fg_init);
module_exit(qplat_fg_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("qcom platform fuel gauge driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
