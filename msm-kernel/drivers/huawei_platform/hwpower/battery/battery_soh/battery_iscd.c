// SPDX-License-Identifier: GPL-2.0
/*
 * battery_iscd.c
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

#include "battery_iscd.h"
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/workqueue.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/device.h>
#include <linux/time.h>
#include <linux/alarmtimer.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <securec.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_supply.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_printk.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <huawei_platform/hwpower/common_module/power_platform_macro.h>
#include <chipset_common/hwpower/hardware_ic/buck_boost.h>
#include <chipset_common/hwpower/coul/coul_interface.h>
#include <huawei_platform/hwpower/common_module/power_platform.h>

#define HWLOG_TAG battery_iscd
HWLOG_REGIST();

static struct bsoh_device *g_bsoh_dev;
struct notifier_block g_ocv_update_notify;
static struct work_struct g_ocv_uevent_work;
static struct work_struct g_iscd_ocv_collect_work;
static struct delayed_work g_iscd_cc_collect_work;
struct alarm g_iscd_ocv_collect_alarm;
static struct iscd_device_info *g_iscd_info = NULL;
char *g_dmd_content;

static int dump_ocv_to_buf(struct iscd_ocv_data *ocv, char *buf, int buf_size)
{
	int ret;
	ret = snprintf_s(buf, buf_size, buf_size - 1,
		"tm:%ld,volt_uv:%d,soc_uah:%d,cc:%ld,temp:%d,pc:%d,lv:%d,cyc:%d",
		ocv->sample_time_sec, ocv->ocv_volt_uv, ocv->ocv_soc_uah, ocv->cc_value,
		ocv->tbatt, ocv->pc, ocv->ocv_level, ocv->batt_chargecycles);
	if (ret < 0)
		hwlog_err("dump ocv info failed\n");

	hwlog_info("ocv_info: %s\n", buf);
	return ret;
}

static void iscd_soh_uevent_work(struct work_struct *work)
{
	int ret;
	char *event_buf = NULL;

	event_buf = kzalloc(BSOH_EVENT_NOTIFY_SIZE, GFP_KERNEL);
	if (!event_buf || !g_iscd_info)
		return;

	hwlog_info("soh_evt_to_send\n");
	ret = dump_ocv_to_buf(&g_iscd_info->ocv_update_data, event_buf, BSOH_EVENT_NOTIFY_SIZE);
	if (ret > 0)
		bsoh_uevent_rcv(BSOH_EVT_OCV_UPDATE, event_buf);

	kfree(event_buf);
}

static void iscd_shutdown_collecting(void)
{
	hwlog_err("iscd quit collecting\n");
	alarm_try_to_cancel(&g_iscd_ocv_collect_alarm);
	cancel_delayed_work(&g_iscd_cc_collect_work);

	if (!g_iscd_info) {
		hwlog_err("%s di is null\n", __func__);
		return;
	}
	g_iscd_info->last_sample_time = 0;
	(void)memset_s(&g_iscd_info->ocv_update_data,
		sizeof(g_iscd_info->ocv_update_data), 0, sizeof(g_iscd_info->ocv_update_data));
}

static void iscd_event_notify(struct bsoh_device *di, unsigned int event)
{
	if (!di || !di->dev)
		return;

	switch (event) {
	case VCHRG_START_AC_CHARGING_EVENT:
	case VCHRG_START_USB_CHARGING_EVENT:
		hwlog_err("VCHRG_START_CHARGING_EVENT\n");
		power_event_notify_sysfs(&di->dev->kobj, "iscd", "iscd_process_event");
		break;
	case VCHRG_STOP_CHARGING_EVENT:
		hwlog_err("VCHRG_STOP_CHARGING_EVENT\n");
		power_event_notify_sysfs(&di->dev->kobj, "iscd", "iscd_process_event");
		break;
	default:
		break;
	};
}

static int iscd_charge_event_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	if (!g_iscd_info) {
		hwlog_err("di is null, stop ocv collect work\n");
		return NOTIFY_OK;
	}

	switch (event) {
	case POWER_NE_CHARGING_START:
		hwlog_err("POWER_NE_CHARGING_START\n");
		g_iscd_info->current_event = ISCD_START_CHARGE_EVENT;
		g_iscd_info->iscd_state_machine = WAIT_CHARGE_DONE;
		break;
	case POWER_NE_CHARGING_STOP:
		hwlog_err("POWER_NE_CHARGING_STOP\n");
		g_iscd_info->current_event = ISCD_STOP_CHARGE_EVENT;
		g_iscd_info->iscd_state_machine = NOT_CHARGING;
		g_iscd_info->illegal_status = 0;
		iscd_shutdown_collecting();
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int iscd_charge_chg_event_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	if (!g_iscd_info) {
		hwlog_err("di is null, stop ocv collect work\n");
		return NOTIFY_OK;
	}

	switch (event) {
	case POWER_NE_CHG_CHARGING_DONE:
		hwlog_err("iscd charge done\n");
		struct timespec64 tv = {0};
		g_iscd_info->current_event = ISCD_CHARGE_DONE_EVENT;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		ktime_get_coarse_real_ts64(&tv);
		g_iscd_info->last_sample_time = tv.tv_sec;
#else
		g_iscd_info->last_sample_time = current_kernel_time().tv_sec;
#endif
		if (g_iscd_info->iscd_state_machine == CHARGE_DONE_RECHARGE)
			cancel_delayed_work(&g_iscd_cc_collect_work);
		g_iscd_info->iscd_state_machine = CHARGE_DONE_COLLECTING;
		alarm_start_relative(&g_iscd_ocv_collect_alarm,
			ktime_set(ISCD_OCV_WORK_INTERVAL, (unsigned long)0));
		break;
	case POWER_NE_CHG_CHARGING_RECHARGE:
		hwlog_err("iscd charge recharge\n");
		if (g_iscd_info->iscd_state_machine == CHARGE_DONE_COLLECTING) {
			g_iscd_info->current_event = ISCD_RECHARGE_EVENT;
			g_iscd_info->iscd_state_machine = CHARGE_DONE_RECHARGE;
			schedule_delayed_work(&g_iscd_cc_collect_work, 0);
			alarm_try_to_cancel(&g_iscd_ocv_collect_alarm);
		}
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static void iscd_cc_collect_work(struct work_struct *work)
{
	int cur = coul_interface_get_battery_current(COUL_TYPE_MAIN);

	if (!g_iscd_info) {
		hwlog_err("di is null, stop cc collect work\n");
		return;
	}

	hwlog_err("cc_collect cur %d", cur);

	g_iscd_info->ocv_update_data.cc_value += cur * ISCD_CC_INTEGRAL_INTERVAL *
		CURRENT_OUTPUT_NEGATIVE * POWER_UA_PER_MA / (POWER_SEC_PER_MIN * POWER_MIN_PER_HOUR);

	if (g_iscd_info->iscd_state_machine == CHARGE_DONE_RECHARGE)
		schedule_delayed_work(&g_iscd_cc_collect_work,
			msecs_to_jiffies(ISCD_CC_INTEGRAL_INTERVAL * POWER_MS_PER_S));
}

static int iscd_get_ocv_average(void)
{
	int ocv_now;
	int ocv_min = ISCD_OCV_MIN_DEFAULT;
	int ocv_max = 0;
	int ocv_sum = 0;

	for (int i = 0; i < ISCD_OCV_SAMPLE_TIMES; i++) {
		ocv_now = coul_interface_get_battery_voltage(COUL_TYPE_MAIN) * POWER_UV_PER_MV;
		ocv_sum += ocv_now;
		ocv_min = power_min_positive(ocv_now, ocv_min);
		ocv_max = power_max_positive(ocv_now, ocv_max);
		hwlog_err("ocv_now %d ocv_min %d ocv_max %d ocv_sum %d i %d\n",
			ocv_now, ocv_min, ocv_max, ocv_sum, i);
		if (i != ISCD_OCV_SAMPLE_TIMES - 1)
			msleep(ISCD_OCV_SAMPLE_INTERVAL);
	}

	return (ocv_sum - ocv_min - ocv_max) / (ISCD_OCV_SAMPLE_TIMES - ISCD_OCV_EXCLUDED_TIMES);
}

static void iscd_ocv_collect_work(struct work_struct *work)
{
	int tbatt = coul_interface_get_battery_temperature(COUL_TYPE_MAIN) / POWER_TENTH;
	int cur;
	struct timespec64 tv = {0};

	if (!g_iscd_info) {
		hwlog_err("di is null, stop ocv collect work\n");
		goto stop_work;
	}

	if ((tbatt > ISCD_COLLECT_TEMP_LIMIT_HIGH) || (tbatt < ISCD_COLLECT_TEMP_LIMIT_LOW))
		goto try_next_time;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	time64_t delta_time;
	ktime_get_coarse_real_ts64(&tv);
	g_iscd_info->ocv_update_data.sample_time_sec = tv.tv_sec;
#else
	time_t delta_time;
	g_iscd_info->ocv_update_data.sample_time_sec = current_kernel_time().tv_sec;
#endif
	delta_time = g_iscd_info->ocv_update_data.sample_time_sec - g_iscd_info->last_sample_time;
	hwlog_err("last sample time %lds, now %lds\n",
		g_iscd_info->last_sample_time, g_iscd_info->ocv_update_data.sample_time_sec);
	g_iscd_info->last_sample_time = g_iscd_info->ocv_update_data.sample_time_sec;
	g_iscd_info->ocv_update_data.ocv_volt_uv = iscd_get_ocv_average();
	g_iscd_info->ocv_update_data.batt_chargecycles =
		coul_interface_get_battery_cycle(COUL_TYPE_MAIN) * ISCD_CYCLE_UPLOAD_FACTOR;
	cur = coul_interface_get_battery_current(COUL_TYPE_MAIN);
	g_iscd_info->ocv_update_data.cc_value += cur * delta_time * CURRENT_OUTPUT_NEGATIVE *
		POWER_UA_PER_MA / (POWER_SEC_PER_MIN * POWER_MIN_PER_HOUR);
	g_iscd_info->ocv_update_data.tbatt = coul_interface_get_battery_temperature(COUL_TYPE_MAIN);
	g_iscd_info->ocv_update_data.ocv_level = ISCD_DEFAULT_OCV_LEVEL;
	cal_uah_by_ocv(g_iscd_info->pc_ocv_lut, g_iscd_info->ocv_update_data.tbatt,
		g_iscd_info->ocv_update_data.ocv_volt_uv, &g_iscd_info->ocv_update_data.ocv_soc_uah);
	g_iscd_info->ocv_update_data.pc = interpolate_pc_high_precision(g_iscd_info->pc_ocv_lut,
		g_iscd_info->ocv_update_data.tbatt,
		g_iscd_info->ocv_update_data.ocv_volt_uv / POWER_UV_PER_MV);

	if (g_iscd_info->iscd_state_machine != CHARGE_DONE_COLLECTING ||
		g_iscd_info->ocv_update_data.ocv_volt_uv < ISCD_OCV_VALID_THRESHOLD) {
		hwlog_err("quit charge done collecting, stop collect ocv : %d",
			g_iscd_info->iscd_state_machine);
		iscd_shutdown_collecting();
		goto stop_work;
	}

	schedule_work(&g_ocv_uevent_work);

try_next_time:
	alarm_start_relative(&g_iscd_ocv_collect_alarm,
		ktime_set(ISCD_OCV_WORK_INTERVAL, (unsigned long)0));
stop_work:
	power_wakeup_unlock(g_iscd_info->wake_lock, false);
}

static enum alarmtimer_restart iscd_ocv_collect_timer_call(struct alarm *alarm, ktime_t now)
{
	power_wakeup_lock(g_iscd_info->wake_lock, false);
	hwlog_err("alarmtimer trigger\n");
	schedule_work(&g_iscd_ocv_collect_work);
	return ALARMTIMER_NORESTART;
}

static void iscd_dmd_content_prepare(char *buff, unsigned int size)
{
	const char *bat_brand = POWER_SUPPLY_DEFAULT_BRAND;
	int ret;

	(void)power_supply_get_str_property_value(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_BRAND, &bat_brand);
	if (!bat_brand || !g_dmd_content)
		return;
	ret = snprintf_s(buff, size, size - 1,
		"batt_brand:%s, dmd_content:%s\n", bat_brand, g_dmd_content);
	if (ret < 0)
		hwlog_err("iscd dmd content prepare fail\n");
}

int iscd_send_uevent_notify(void)
{
	char *envp_ext[] = { "BATTERY_EVENT=FATAL_ISC", NULL };
	int ret;

	if (!g_bsoh_dev) {
		hwlog_err("driver for isc probe uncorrect\n");
		return -ENODEV;
	}

	ret = kobject_uevent_env(&g_bsoh_dev->dev->kobj, KOBJ_CHANGE, envp_ext);
	if (ret) {
		hwlog_err("iscd uevent notify failed\n");
		return ret;
	}
	return 0;
}

#define QPLAT_FG_PSY_NAME "bk_battery"
#ifdef CONFIG_SYSFS
static ssize_t iscd_data_show(struct device *dev,
	struct device_attribute *attr, char *buff)
{
	int ret;
	ret = memcpy_s(buff, sizeof(g_iscd_info->ocv_update_data),
		&g_iscd_info->ocv_update_data, sizeof(g_iscd_info->ocv_update_data));
	if (ret)
		hwlog_err("iscd data copy fail\n");
	return sizeof(g_iscd_info->ocv_update_data);
}

static ssize_t iscd_imonitor_data_show(struct device *dev,
	struct device_attribute *attr, char *buff)
{
	int ret = 0;
	const char *bat_brand = POWER_SUPPLY_DEFAULT_BRAND;
	struct iscd_imonitor_data data;

	(void)memset_s(&data, sizeof(data), 0, sizeof(data));
	power_supply_get_int_property_value(QPLAT_FG_PSY_NAME,
		POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN, &data.fcc);
	data.bat_cyc = coul_interface_get_battery_cycle(COUL_TYPE_MAIN);
	data.q_max = get_qmax_with_basp();
	(void)power_supply_get_str_property_value(POWER_PLATFORM_BAT_PSY_NAME,
		POWER_SUPPLY_PROP_BRAND, &bat_brand);
	if (bat_brand)
		ret = memcpy_s(data.bat_man, ISCD_BASIC_INFO_MAX_LEN, bat_brand,
			strnlen(bat_brand, ISCD_BASIC_INFO_MAX_LEN - 1));

	ret += memcpy_s(buff, sizeof(data), &data, sizeof(data));
	if (ret)
		hwlog_err("iscd monitor data copy fail\n");
	return sizeof(data);
}

static ssize_t iscd_process_event_show(struct device *dev,
	struct device_attribute *attr, char *buff)
{
	int value = -1;
	int ret;

	switch (g_iscd_info->current_event) {
	case ISCD_OCV_UPDATE_EVENT:
	case ISCD_START_CHARGE_EVENT:
	case ISCD_STOP_CHARGE_EVENT:
	case ISCD_CHARGE_DONE_EVENT:
	case ISCD_RECHARGE_EVENT:
		ret = memcpy_s(buff, sizeof(g_iscd_info->current_event),
			&g_iscd_info->current_event, sizeof(g_iscd_info->current_event));
		if (ret)
			hwlog_err("iscd current event copy fail\n");
		return sizeof(g_iscd_info->current_event);
	default:
		ret = memcpy_s(buff, sizeof(value), &value, sizeof(value));
		if (ret)
			hwlog_err("iscd current event copy fail\n");
		return sizeof(value);
	}
}

static ssize_t iscd_battery_current_avg_show(struct device *dev,
	struct device_attribute *attr, char *buff)
{
	int current_avg_ma;
	int ret;

	current_avg_ma = charge_get_battery_current_avg();
	ret = memcpy_s(buff, sizeof(current_avg_ma), &current_avg_ma, sizeof(current_avg_ma));
	if (ret)
		hwlog_err("iscd current avg copy fail\n");
	return sizeof(current_avg_ma);
}

static ssize_t iscd_uevent_notify_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int prompt;
	int ret;

	if (kstrtoint(buf, 0, &prompt))
		return -EPERM;

	if (prompt) {
		ret = iscd_send_uevent_notify();
		if (ret)
			return ret;
	}
	return count;
}

static ssize_t iscd_dmd_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct iscd_dmd_data dmd;
	int ret;

	if (count != sizeof(dmd))
		return -EPERM;

	ret = memcpy_s(&dmd, sizeof(dmd), buf, sizeof(dmd));
	ret += memset_s(g_dmd_content, ISCD_MAX_FATAL_ISC_DMD_NUM,
		0, ISCD_MAX_FATAL_ISC_DMD_NUM);
	ret += memcpy_s(g_dmd_content, ISCD_MAX_FATAL_ISC_DMD_NUM,
		dmd.buff, ISCD_MAX_FATAL_ISC_DMD_NUM - 1);
	if (ret)
		hwlog_err("iscd dmd store memory fail\n");
	bsoh_dmd_append("iscd", dmd.err_no);
	return count;
}

static ssize_t iscd_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", g_iscd_info->iscd_status);
}

static ssize_t iscd_status_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int status = 0;

	if (kstrtouint(buf, 0, &status))
		return -EPERM;

	g_iscd_info->iscd_status = status;
	return count;
}

static ssize_t iscd_limit_support_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", g_iscd_info->iscd_trigger_type);
}

static ssize_t iscd_limit_support_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int trigger_type = 0;

	if (kstrtouint(buf, 0, &trigger_type))
		return -EPERM;

	g_iscd_info->iscd_trigger_type = trigger_type;
	return count;
}

static ssize_t iscd_illegal_status_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", g_iscd_info->illegal_status);
}

static ssize_t iscd_illegal_status_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int illegal_status = 0;

	if (kstrtouint(buf, 0, &illegal_status))
		return -EPERM;

	g_iscd_info->illegal_status = illegal_status;
	g_iscd_info->iscd_state_machine = QUIT_COLLECTING;
	hwlog_info("stop collecting, illegal status %d\n", g_iscd_info->illegal_status);
	iscd_shutdown_collecting();
	return count;
}

static DEVICE_ATTR_RO(iscd_data);
static DEVICE_ATTR_RO(iscd_process_event);
static DEVICE_ATTR_RO(iscd_imonitor_data);
static DEVICE_ATTR_RO(iscd_battery_current_avg);
static DEVICE_ATTR_WO(iscd_uevent_notify);
static DEVICE_ATTR_WO(iscd_dmd);
static DEVICE_ATTR_RW(iscd_status);
static DEVICE_ATTR_RW(iscd_limit_support);
static DEVICE_ATTR_RW(iscd_illegal_status);

static struct attribute *g_iscd_attrs[] = {
	&dev_attr_iscd_data.attr,
	&dev_attr_iscd_process_event.attr,
	&dev_attr_iscd_imonitor_data.attr,
	&dev_attr_iscd_battery_current_avg.attr,
	&dev_attr_iscd_uevent_notify.attr,
	&dev_attr_iscd_dmd.attr,
	&dev_attr_iscd_status.attr,
	&dev_attr_iscd_limit_support.attr,
	&dev_attr_iscd_illegal_status.attr,
	NULL,
};

static struct attribute_group g_iscd_group = {
	.name = "iscd",
	.attrs = g_iscd_attrs,
};

static int iscd_sysfs_create_group(struct bsoh_device *di)
{
	return sysfs_create_group(&di->dev->kobj, &g_iscd_group);
}

static void iscd_sysfs_remove_group(struct bsoh_device *di)
{
	sysfs_remove_group(&di->dev->kobj, &g_iscd_group);
}
#else
static inline int iscd_sysfs_create_group(struct bsoh_device *di)
{
	return 0;
}

static inline void iscd_sysfs_remove_group(struct bsoh_device *di)
{
}
#endif /* CONFIG_SYSFS */

static int iscd_parse_ocv_temp_lut(struct bsoh_device *di)
{
	int i, row, col, array_len, idata;
	const char *tmp_string = NULL;

	array_len = power_dts_read_count_strings(power_dts_tag(HWLOG_TAG), di->dev->of_node,
		"iscd_ocv_temp_para", ISCD_OCV_GROUP_SIZE, ISCD_PARA_TOTAL);
	if (array_len < 0) {
		hwlog_err("ocv temp lut parse invalid\n");
		return -EINVAL;
	}

	g_iscd_info->pc_ocv_lut.lut_num = array_len / ISCD_PARA_TOTAL;
	for (i = 0; i < array_len; i++) {
		if (power_dts_read_string_index(power_dts_tag(HWLOG_TAG),
			di->dev->of_node, "iscd_ocv_temp_para", i, &tmp_string))
			return -EINVAL;

		row = i / ISCD_PARA_TOTAL;
		col = i % ISCD_PARA_TOTAL;
		switch (col) {
		case ISCD_PARA_TEMP_LOW:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return -EINVAL;
			if (idata < ISCD_COLLECT_TEMP_LIMIT_LOW || idata > ISCD_COLLECT_TEMP_LIMIT_HIGH) {
				hwlog_err("invalid temp_low=%d\n", idata);
				return -EINVAL;
			}
			g_iscd_info->pc_ocv_lut.ocv_info_group[row].lut_para.temp_low = idata;
			break;
		case ISCD_PARA_TEMP_HIGH:
			if (kstrtoint(tmp_string, POWER_BASE_DEC, &idata))
				return -EINVAL;
			if (idata < ISCD_COLLECT_TEMP_LIMIT_LOW || idata > ISCD_COLLECT_TEMP_LIMIT_HIGH) {
				hwlog_err("invalid temp_high=%d\n", idata);
				return -EINVAL;
			}
			g_iscd_info->pc_ocv_lut.ocv_info_group[row].lut_para.temp_high = idata;
			break;
		case ISCD_PARA_INDEX:
			(void)strncpy_s(g_iscd_info->pc_ocv_lut.ocv_info_group[row].lut_para.para_index,
				ISCD_OCV_LUT_LEN_MAX, tmp_string, ISCD_OCV_LUT_LEN_MAX - 1);
			break;
		default:
			break;
		}
	}
	return 0;
}

static int iscd_parse_ocv_info(struct bsoh_device *di)
{
	int i, j, row, col, len;
	int idata[ISCD_OCV_PARA_LEVEL * ISCD_OCV_INFO_TOTAL] = { 0 };
	char *ocv_para;

	for (j = 0; j < g_iscd_info->pc_ocv_lut.lut_num; j++) {
		ocv_para = g_iscd_info->pc_ocv_lut.ocv_info_group[j].lut_para.para_index;
		len = power_dts_read_string_array(power_dts_tag(HWLOG_TAG), di->dev->of_node,
			ocv_para, idata, ISCD_OCV_PARA_LEVEL, ISCD_OCV_INFO_TOTAL);
		if (len < 0)
			return -EINVAL;
		for (row = 0; row < len / ISCD_OCV_INFO_TOTAL; row++) {
			col = row * ISCD_OCV_INFO_TOTAL + ISCD_OCV_INFO_OCV;
			g_iscd_info->pc_ocv_lut.ocv_info_group[j].ocv_para[row].ocv = idata[col];
			col = row * ISCD_OCV_INFO_TOTAL + ISCD_OCV_INFO_SOC;
			g_iscd_info->pc_ocv_lut.ocv_info_group[j].ocv_para[row].soc = idata[col];
		}

		for (i = 0; i < ISCD_OCV_PARA_LEVEL; i++)
			hwlog_info("%s[%d]=%d %d\n",
			g_iscd_info->pc_ocv_lut.ocv_info_group[j].lut_para.para_index, i,
			g_iscd_info->pc_ocv_lut.ocv_info_group[j].ocv_para[i].ocv,
			g_iscd_info->pc_ocv_lut.ocv_info_group[j].ocv_para[i].soc);
	}

	return 0;
}

static int iscd_parse_dts(struct bsoh_device *di)
{
	int ret;
	if (!di || !di->dev) {
		hwlog_err("iscd di is null\n");
		return -ENODEV;
	}
	g_iscd_info->pc_ocv_lut.rows = ISCD_OCV_PARA_LEVEL;
	g_iscd_info->pc_ocv_lut.cols = ISCD_OCV_GROUP_SIZE;
	ret = iscd_parse_ocv_temp_lut(di);
	if (ret) {
		hwlog_err("iscd_parse_ocv_temp_lut fail\n");
		return ret;
	}

	ret = iscd_parse_ocv_info(di);
	if (ret) {
		hwlog_err("iscd_parse_ocv_info fail\n");
		return ret;
	}

	return 0;
}

static int iscd_sys_init(struct bsoh_device *di)
{
	int ret;

	hwlog_info("iscd init begin\n");

	if (!di || !di->dev)
		return -ENODEV;

	g_iscd_info = kzalloc(sizeof(*g_iscd_info), GFP_KERNEL);
	if (!g_iscd_info)
		return -ENOMEM;

	ret = iscd_sysfs_create_group(di);
	if (ret)
		goto fail_free_mem;

	ret = iscd_parse_dts(di);
	if (ret)
		goto fail_free_mem;

	g_iscd_info->dev = di;
	g_iscd_info->wake_lock = power_wakeup_source_register(di->dev, "iscd_detect");
	INIT_WORK(&g_ocv_uevent_work, iscd_soh_uevent_work);
	INIT_WORK(&g_iscd_ocv_collect_work, iscd_ocv_collect_work);
	INIT_DELAYED_WORK(&g_iscd_cc_collect_work, iscd_cc_collect_work);

	alarm_init(&g_iscd_ocv_collect_alarm, ALARM_REALTIME, iscd_ocv_collect_timer_call);
	g_iscd_info->chg_event_nb.notifier_call = iscd_charge_chg_event_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CHG, &g_iscd_info->chg_event_nb);
	if (ret)
		goto fail_free_mem;

	g_iscd_info->event_nb.notifier_call = iscd_charge_event_notifier_call;
	ret = power_event_bnc_register(POWER_BNT_CHARGING, &g_iscd_info->event_nb);
	if (ret) {
		goto fail_unregister_chg;
	}

	kfree(g_dmd_content);
	g_dmd_content = kzalloc(ISCD_MAX_FATAL_ISC_DMD_NUM, GFP_KERNEL);
	if (!g_dmd_content)
		goto fail_unregister_all;

	g_bsoh_dev = di;
	g_iscd_info->current_event = 0;
	hwlog_info("iscd init ok\n");
	return 0;

fail_unregister_all:
	power_event_bnc_unregister(POWER_BNT_CHARGING, &g_iscd_info->event_nb);
fail_unregister_chg:
	power_event_bnc_unregister(POWER_BNT_CHG, &g_iscd_info->chg_event_nb);
fail_free_mem:
	kfree(g_iscd_info);
	g_iscd_info = NULL;
	return -EINVAL;
}

static void iscd_sys_exit(struct bsoh_device *di)
{
	iscd_sysfs_remove_group(di);
	kfree(g_dmd_content);
	power_wakeup_source_unregister(g_iscd_info->wake_lock);
	kfree(g_iscd_info);
	g_bsoh_dev = NULL;
	g_dmd_content = NULL;
	g_iscd_info = NULL;
}

static const struct bsoh_sub_sys g_iscd_sys = {
	.sys_init = iscd_sys_init,
	.sys_exit = iscd_sys_exit,
	.event_notify = iscd_event_notify,
	.dmd_prepare = iscd_dmd_content_prepare,
	.type_name = "iscd",
	.notify_node = "iscd_process_event",
};

static int __init iscd_init(void)
{
	bsoh_register_sub_sys(BSOH_SUB_SYS_ISCD, &g_iscd_sys);
	return 0;
}

static void __exit iscd_exit(void)
{
}

subsys_initcall(iscd_init);
module_exit(iscd_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("battery iscd driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
