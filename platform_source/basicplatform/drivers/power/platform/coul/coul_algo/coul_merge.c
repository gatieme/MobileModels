/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Converged calculation of two batteries
 *
 * This software is licensed under the terms of the GNU General Public
 * License, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/module.h>
#include <linux/power_supply.h>
#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/reboot.h>
#include <linux/suspend.h>
#include <linux/pm_wakeup.h>
#include <linux/workqueue.h>

#include <platform_include/basicplatform/linux/power/platform/coul/coul_merge_drv.h>
#include <platform_include/basicplatform/linux/power/platform/coul/coul_drv.h>
#include <platform_include/basicplatform/linux/power/platform/bci_battery.h>
#ifdef CONFIG_DIRECT_CHARGER
#include <huawei_platform/power/direct_charger/direct_charger.h>
#endif
#include "coul_nv.h"
#include <huawei_platform/power/batt_info_pub.h>

#define coul_merge_debug(fmt, args...) pr_debug("[coul_merge]" fmt, ## args)
#define coul_merge_info(fmt, args...) pr_info("[coul_merge]" fmt, ## args)
#define coul_merge_warn(fmt, args...) pr_warn("[coul_merge]" fmt, ## args)
#define coul_merge_err(fmt, args...) pr_err("[coul_merge]" fmt, ## args)

#define CALCULATE_SOC_MS                (20 * 1000)
#define BATTRY_SN_LEN                   16
#define CATHODE_INDEX                   10
#define TYPE_SILICON_CHARS_LEN          6
#define BATTRY_SN_CHAR_SIZE              (BATTRY_SN_LEN * 2 + 4)

static struct coul_merge_device *g_coul_merge = NULL;
static char g_type_silicon_chars[] = { 'K', 'L', 'N', 'U', 'V', 'Y' };

/* cap_ratio_1 == 0 indicate only one battery */
static bool is_battery_count_one(void)
{
	struct coul_merge_device *di = NULL;

	if(!g_coul_merge) {
		coul_merge_err("%s g_coul_merge is null.\n", __func__);
		return true;
	}
	di = g_coul_merge;

	if(di->cap_ratio_1)
		return false;

	return true;
}

int coul_merge_is_battery_exist(void)
{
	int exist_0, exist_1;

	if (is_battery_count_one())
		return coul_merge_drv_is_battery_exist(BATT_0);

	exist_0 = coul_merge_drv_is_battery_exist(BATT_0);
	exist_1 = coul_merge_drv_is_battery_exist(BATT_1);
	return (int)((unsigned int)exist_0 & (unsigned int)exist_1);
}

int coul_merge_is_battery_reach_threshold(void)
{
	return coul_merge_drv_is_battery_reach_threshold(BATT_0);
}

int coul_merge_battery_voltage(void)
{
	int vol_0, vol_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_voltage_mv(BATT_0);

	vol_0 = coul_merge_drv_battery_voltage_mv(BATT_0);
	vol_1 = coul_merge_drv_battery_voltage_mv(BATT_1);
	return max(vol_0, vol_1);
}

char *coul_merge_battery_brand(void)
{
	return coul_merge_drv_battery_brand(BATT_0);
}

int coul_merge_battery_id_voltage(void)
{
	return coul_merge_drv_battery_id_voltage(BATT_0);
}

int coul_merge_battery_voltage_uv(void)
{
	int vol_0, vol_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_voltage_uv(BATT_0);

	vol_0 = coul_merge_drv_battery_voltage_uv(BATT_0);
	vol_1 = coul_merge_drv_battery_voltage_uv(BATT_1);
	return max(vol_0, vol_1);
}

int coul_merge_battery_current(void)
{
	int curr_0, curr_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_current(BATT_0);

	curr_0 = coul_merge_drv_battery_current(BATT_0);
	curr_1 = coul_merge_drv_battery_current(BATT_1);

	if (g_coul_merge && g_coul_merge->is_series_bat)
		return (curr_0 + curr_1) / HALF;

	return curr_0 + curr_1;
}
int coul_merge_battery_resistance(void)
{
	int res_0, res_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_resistance(BATT_0);

	res_0 = coul_merge_drv_battery_resistance(BATT_0);
	res_1 = coul_merge_drv_battery_resistance(BATT_1);

	if (g_coul_merge && g_coul_merge->is_series_bat)
		return res_0 + res_1;

	return (res_0 + res_1) / 2;
}

int coul_merge_fifo_avg_current(void)
{
	int curr_0, curr_1;

	if (is_battery_count_one())
		return coul_merge_drv_fifo_avg_current(BATT_0);

	curr_0 = coul_merge_drv_fifo_avg_current(BATT_0);
	curr_1 = coul_merge_drv_fifo_avg_current(BATT_1);

	if (g_coul_merge && g_coul_merge->is_series_bat)
		return (curr_0 + curr_1) / HALF;

	return curr_1 + curr_0;
}

int coul_merge_battery_current_avg(void)
{
	int curr_0, curr_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_current_avg(BATT_0);

	curr_0 = coul_merge_drv_battery_current_avg(BATT_0);
	curr_1 = coul_merge_drv_battery_current_avg(BATT_1);

	if (g_coul_merge && g_coul_merge->is_series_bat)
		return (curr_0 + curr_1) / HALF;

	return (curr_1 + curr_0);
}

int coul_merge_battery_capacity(void)
{
	int soc_0, soc_1;
	struct coul_merge_device *di = NULL;

	if(!g_coul_merge) {
		coul_merge_err("%s g_coul_merge is null.\n", __func__);
		return 0;
	}
	di = g_coul_merge;

	if (is_battery_count_one()) {
		di->soc = coul_merge_drv_battery_capacity(BATT_0);
		coul_merge_info("%s mSoc %d\n", __func__, di->soc);
		return di->soc;
	}

	soc_0 = coul_merge_drv_battery_capacity(BATT_0);
	soc_1 = coul_merge_drv_battery_capacity(BATT_1);
	di->soc = soc_0 * di->cap_ratio_0 + soc_1 * di->cap_ratio_1;
	di->soc /= PERMILLAGE;
	coul_merge_info("%s soc_0 %d, soc_1 %d, mSoc %d\n", __func__, soc_0, soc_1, di->soc);
	return di->soc;
}

static int coul_merge_get_capacity(void)
{
	struct coul_merge_device *di = NULL;

	if(!g_coul_merge) {
		coul_merge_err("%s g_coul_merge is null.\n", __func__);
		return 0;
	}
	di = g_coul_merge;

	coul_merge_info("%s soc %d\n", __func__, di->soc);
	return di->soc;
}

static int coul_merge_get_unfiltered_capacity(void)
{
	int soc_0, soc_1;
	struct coul_merge_device *di = NULL;

	if(!g_coul_merge) {
		coul_merge_err("%s g_coul_merge is null.\n", __func__);
		return 0;
	}
	di = g_coul_merge;

	if (is_battery_count_one()) {
		soc_0 = coul_merge_drv_battery_unfiltered_capacity(BATT_0);
		coul_merge_info("%s unfiltered soc %d\n", __func__, soc_0);
		return soc_0;
	}

	soc_0 = coul_merge_drv_battery_unfiltered_capacity(BATT_0);
	soc_1 = coul_merge_drv_battery_unfiltered_capacity(BATT_1);
	coul_merge_info("%s unfiltered soc %d\n", __func__,
		(soc_0 * di->cap_ratio_0 + soc_1 * di->cap_ratio_1) / PERMILLAGE);
	return (soc_0 * di->cap_ratio_0 + soc_1 * di->cap_ratio_1) / PERMILLAGE;
}

int coul_merge_battery_temperature(void)
{
	return coul_merge_drv_battery_temperature(BATT_0);
}

static int coul_merge_battery_removed_before_boot(void)
{
	return coul_merge_drv_battery_removed_before_boot(BATT_0);
}

#ifdef CONFIG_BATT_SOH
int coul_merge_convert_mv2regval(int mv)
{
	return coul_merge_drv_convert_mv2regval(BATT_0,mv);
}

int coul_merge_convert_regval2ua(unsigned int reg_val)
{
	return coul_merge_drv_convert_regval2ua(BATT_0,reg_val);
}

int coul_merge_convert_regval2uv(unsigned int reg_val)
{
	return coul_merge_drv_convert_regval2uv(BATT_0,reg_val);
}
#endif

int coul_merge_battery_rm(void)
{
	int rm_0, rm_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_rm(BATT_0);

	rm_0 = coul_merge_drv_battery_rm(BATT_0);
	rm_1 = coul_merge_drv_battery_rm(BATT_1);

	return rm_0 + rm_1;
}

int coul_merge_battery_fcc(void)
{
	int fcc_0, fcc_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_fcc(BATT_0);

	fcc_0 = coul_merge_drv_battery_fcc(BATT_0);
	fcc_1 = coul_merge_drv_battery_fcc(BATT_1);

	return fcc_0 + fcc_1;
}

int coul_merge_battery_fcc_design(void)
{
	int fcc_0, fcc_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_fcc_design(BATT_0);

	fcc_0 = coul_merge_drv_battery_fcc_design(BATT_0);
	fcc_1 = coul_merge_drv_battery_fcc_design(BATT_1);

	return fcc_0 + fcc_1;
}

int coul_merge_battery_health(void)
{
	int health_0, health_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_health(BATT_0);

	health_0 = coul_merge_drv_battery_health(BATT_0);
	health_1 = coul_merge_drv_battery_health(BATT_1);

	if(health_0 > POWER_SUPPLY_HEALTH_GOOD)
		return health_0;
	return health_1;
}

/* battery health level 0: Unknown, 1:CRITICAL, 2:LOW, 3:NORMAL, 4:HIGH, 5:FULL */
static int coul_merge_battery_capacity_level(void)
{
	struct coul_merge_device *di = g_coul_merge;
	int capacity, status;

	if (di == NULL)
		return POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;

	if (!coul_merge_is_battery_exist())
		return POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;

	capacity = di->soc;
	if ((capacity > CAPACITY_FULL) || (capacity < CAPACITY_MIN))
		status = POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;
	else if ((capacity >= CAPACITY_MIN) && (capacity <= CAPACITY_CRITICAL))
		status = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
	else if ((capacity > CAPACITY_CRITICAL) && (capacity <= CAPACITY_LOW))
		status = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
	else if ((capacity >= CAPACITY_HIGH) && (capacity < CAPACITY_FULL))
		status = POWER_SUPPLY_CAPACITY_LEVEL_HIGH;
	else if (capacity == CAPACITY_FULL)
		status = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
	else
		status = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;

	return status;
}

int coul_merge_battery_technology(void)
{
	return coul_merge_drv_battery_technology(BATT_0);
}

int coul_merge_battery_vbat_max(void)
{
	int vbat_0, vbat_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_vbat_max(BATT_0);

	vbat_0 = coul_merge_drv_battery_vbat_max(BATT_0);
	vbat_1 = coul_merge_drv_battery_vbat_max(BATT_1);

	return max(vbat_0, vbat_1);
}

int coul_merge_battery_cycle_count(void)
{
	int cycle_0, cycle_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_cycle_count(BATT_0);

	cycle_0 = coul_merge_drv_battery_cycle_count(BATT_0);
	cycle_1 = coul_merge_drv_battery_cycle_count(BATT_1);

	return max(cycle_0, cycle_1);
}

int coul_merge_battery_get_limit_fcc(void)
{
	int  fcc_0, fcc_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_get_limit_fcc(BATT_0);

	fcc_0 = coul_merge_drv_battery_get_limit_fcc(BATT_0);
	fcc_1 = coul_merge_drv_battery_get_limit_fcc(BATT_1);

	return fcc_0 + fcc_1;
}

int coul_merge_low_temp_opt(void)
{
	return coul_merge_drv_low_temp_opt(BATT_0);
}

int coul_merge_battery_cc(void)
{
	int cc_0, cc_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_cc_uah(BATT_0);

	cc_0 = coul_merge_drv_battery_cc_uah(BATT_0);
	cc_1 = coul_merge_drv_battery_cc_uah(BATT_1);

	return cc_0 + cc_1;
}

int coul_merge_battery_cc_cache(void)
{
	int cc_0, cc_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_cc_cache(BATT_0);

	cc_0 = coul_merge_drv_battery_cc_cache(BATT_0);
	cc_1 = coul_merge_drv_battery_cc_cache(BATT_1);

	return cc_0 + cc_1;
}

int coul_merge_battery_get_qmax(void)
{
	int qmax_0, qmax_1;

	if (is_battery_count_one())
		return coul_merge_drv_battery_get_qmax(BATT_0);

	qmax_0 = coul_merge_drv_battery_get_qmax(BATT_0);
	qmax_1 = coul_merge_drv_battery_get_qmax(BATT_1);

	return qmax_0 + qmax_1;
}

static int coul_merge_get_soc_by_ocv(int temp, int ocv)
{
	return coul_merge_drv_get_soc_by_ocv(BATT_0, temp, ocv);
}

/*
 * put the new event en queue
 * if the event_queue is full, return -ENOSPC
 */
static int coul_event_enqueue(struct coul_merge_device *di,
		  unsigned int *event)
{
	unsigned long flags;
	int ret = 0;

	spin_lock_irqsave(&(di->event_lock), flags);
	if (kfifo_in(&di->event_fifo, event, 1) == 0) {
		coul_merge_err("drop event %d\n", *event);
		ret = -ENOSPC;
	}
	spin_unlock_irqrestore(&(di->event_lock), flags);

	return ret;
}

/*
 * get event frome event_queue
 * return the numbers of event dequeued, currently it is 1
 */
static int coul_event_dequeue(struct coul_merge_device *di,
		  unsigned int *event)
{
	return kfifo_out_spinlocked(&di->event_fifo, event,
				    1, &di->event_lock);
}

int coul_merge_charger_event_rcv(unsigned int event)
{
	struct coul_merge_device *di = g_coul_merge;

	if (di == NULL) {
		coul_merge_err("di is NULL\n");
		return -1;
	}

	if (!coul_event_enqueue(di, &event)) {
		queue_delayed_work(system_power_efficient_wq,
			&di->coul_rcv_event_work, 0);
	} else {
		coul_merge_err("can't enqueue event:%d\n", event);
		return -EBUSY;
	}

	return 0;
}

static void coul_merge_rcv_event_work(struct work_struct *work)
{
	unsigned int event = 0;
	struct coul_merge_device *di = container_of(work,
		struct coul_merge_device, coul_rcv_event_work.work);

	coul_merge_info("%s +\n", __func__);
	mutex_lock(&di->lock);
	while (coul_event_dequeue(di, &event)) {
		coul_merge_drv_charger_event_rcv(BATT_0, event);
		if (!is_battery_count_one())
			coul_merge_drv_charger_event_rcv(BATT_1, event);
	}
	mutex_unlock(&di->lock);
	coul_merge_info("%s -\n", __func__);
}

static int coul_merge_update_basp_policy(unsigned int level,
	unsigned int nondc_volt_dec)
{
	int ret;
	if (is_battery_count_one())
		return coul_merge_drv_battery_update_basp_policy(BATT_0, level, nondc_volt_dec);

	ret = coul_merge_drv_battery_update_basp_policy(BATT_0, level, nondc_volt_dec);
	ret += coul_merge_drv_battery_update_basp_policy(BATT_1, level, nondc_volt_dec);

	return ret;
}

static int coul_merge_is_smart_battery(void)
{
	return coul_merge_drv_is_smart_battery(BATT_0);
}

static int coul_merge_get_desired_charging_current(void)
{
	int curr_0, curr_1;

	if (is_battery_count_one())
		return coul_merge_drv_get_desired_charging_current(BATT_0);

	curr_0 = coul_merge_drv_get_desired_charging_current(BATT_0);
	curr_1 = coul_merge_drv_get_desired_charging_current(BATT_1);

	return min(curr_0, curr_1);
}

static int coul_merge_get_desired_charging_voltage(void)
{
	int vol_0, vol_1;

	if (is_battery_count_one())
		return coul_merge_drv_get_desired_charging_voltage(BATT_0);

	vol_0 = coul_merge_drv_get_desired_charging_voltage(BATT_0);
	vol_1 = coul_merge_drv_get_desired_charging_voltage(BATT_1);

	return min(vol_0, vol_1);
}

static void coul_merge_set_work_interval(struct coul_merge_device *di)
{
	if (di->soc > LOW_SOC)
		di->soc_work_interval = CALCULATE_SOC_MS;
	else
		di->soc_work_interval = CALCULATE_SOC_MS / HALF;

#ifdef CONFIG_DIRECT_CHARGER
	if (direct_charge_in_charging_stage() == DC_IN_CHARGING_STAGE &&
		(coul_merge_drv_get_charge_state(BATT_0) == CHARGING_STATE_CHARGE_START) &&
		(di->soc_work_interval > (CALCULATE_SOC_MS / QUARTER)))
		di->soc_work_interval = CALCULATE_SOC_MS / QUARTER;
#endif
}

static void batt_soc_algo_work(void)
{
	if (is_battery_count_one()) {
		coul_merge_drv_calc(BATT_0);
	} else {
		coul_merge_drv_calc(BATT_0);
		coul_merge_drv_calc(BATT_1);
	}
}

static void coul_merge_monitor_work(struct work_struct *work)
{
	struct coul_merge_device *di = container_of(work,
		struct coul_merge_device, calculate_soc_delayed_work.work);

	mutex_lock(&di->lock);

	coul_merge_info("%s start\n", __func__);

	batt_soc_algo_work();
	coul_merge_battery_capacity();
	coul_merge_set_work_interval(di);

	coul_merge_info("%s end\n", __func__);

	mutex_unlock(&di->lock);

	if (!coul_merge_is_battery_exist()) {
		coul_merge_info("battery not exist, do not calc soc any more\n");
		return;
	}

	queue_delayed_work(system_power_efficient_wq,
		&di->calculate_soc_delayed_work, msecs_to_jiffies(di->soc_work_interval));
}

static void coul_merge_resume_work(struct work_struct *work)
{
	struct coul_merge_device *di = container_of(work,
		struct coul_merge_device, merge_resume_work);

	coul_merge_info("%s: +\n", __func__);

	if (di == NULL) {
		coul_merge_err("%s: failed to get coul_merge_device\n", __func__);
		return;
	}

	if (!di->resume_wake_lock) {
		coul_merge_err("%s: failed to get resume_wake_lock\n", __func__);
		return;
	}

	if (!is_battery_count_one())
		coul_merge_drv_resume(BATT_1);
	coul_merge_drv_resume(BATT_0);

	coul_merge_battery_capacity();

	__pm_relax(di->resume_wake_lock);

	coul_merge_info("%s: -\n", __func__);
}

static void get_soc_dts_info(struct coul_merge_device *di,
	const struct device_node *np)
{
	int ret;
	unsigned int last_soc_enable = 0;
	unsigned int startup_delta_soc = 0;

	ret = of_property_read_u32(np, "last_soc_enable", &last_soc_enable);
	if (ret)
		coul_merge_err("dts:can not get last_soc_enable, use default : %u\n",
			last_soc_enable);
	di->last_soc_enable = (int)last_soc_enable;
	coul_merge_info("dts:get last_soc_enable = %u\n", last_soc_enable);

	ret = of_property_read_u32(np, "startup_delta_soc", &startup_delta_soc);
	if (ret)
		coul_merge_err("dts:can not get delta_soc,use default: %u!\n",
			startup_delta_soc);
	di->startup_delta_soc = (int)startup_delta_soc;
	coul_merge_info("dts:get delta_soc = %u\n", startup_delta_soc);
}

static void coul_merge_parse_dts(struct coul_merge_device *di)
{
	struct device_node *np = di->dev->of_node;
	int ret;

	ret = of_property_read_u32(np, "is_series_bat", &di->is_series_bat);
	if (ret) {
		coul_merge_info("dts:can not get is_series_bat,use default 0\n");
		di->is_series_bat = 0;
	} else {
		coul_merge_info("dts:get is_series_bat = %u\n", di->is_series_bat);
	}

	ret = of_property_read_u32(np, "cap_ratio_0", &di->cap_ratio_0);
	if (ret) {
		coul_merge_info("dts:can not get cap_ratio_0,use default 1000\n");
		di->cap_ratio_0 = 1000;
	} else {
		coul_merge_info("dts:get cap_ratio_0 = %u\n", di->cap_ratio_0);
	}

	ret = of_property_read_u32(np, "cap_ratio_1", &di->cap_ratio_1);
	if (ret) {
		coul_merge_info("dts:can not get cap_ratio_1,use default 0\n");
		di->cap_ratio_1 = 0;
	} else {
		coul_merge_info("dts:get cap_ratio_1 = %u\n", di->cap_ratio_1);
	}

	get_soc_dts_info(di, np);
}

static int coul_merge_shutdown_prepare(struct notifier_block *nb,
	unsigned long event, void *data)
{
	struct coul_merge_device *di =
		container_of(nb, struct coul_merge_device, reboot_nb);
	int last_soc = bci_show_capacity();

	switch (event) {
	case SYS_DOWN:
	case SYS_HALT:
	case SYS_POWER_OFF:
		coul_merge_info("coul prepare to shutdown, event = %lu\n", event);
		if (last_soc >= 0)
			coul_merge_drv_save_last_soc(last_soc);
		cancel_delayed_work_sync(&di->calculate_soc_delayed_work);
		if (!is_battery_count_one())
			coul_merge_drv_shutdown(BATT_1);
		coul_merge_drv_shutdown(BATT_0);
		break;
	default:
		coul_merge_err("error event, coul ignore, event = %lu\n", event);
		break;
	}
	return 0;
}

#ifdef CONFIG_PM
/* suspend function, called when coul enter sleep, v9 no sleep */
static int coul_merge_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct coul_merge_device *di = platform_get_drvdata(pdev);

	coul_merge_info("%s: +\n", __func__);

	if (coul_merge_is_battery_exist())
		cancel_delayed_work(&di->calculate_soc_delayed_work);

	/* The sequence of BATT_1 and BATT_0 cannot be changed.
	    because only BATT_0 controls the chip enter or out the ECO.
	*/
	if (!is_battery_count_one())
		coul_merge_drv_suspend(BATT_1);
	coul_merge_drv_suspend(BATT_0);

	coul_merge_info("%s: -\n", __func__);

	return 0;
}

/* called when coul wakeup from deep sleep */
static int coul_merge_resume(struct platform_device *pdev)
{
	struct coul_merge_device *di = platform_get_drvdata(pdev);

	coul_merge_info("%s: +\n", __func__);

	di->soc_work_interval = CALCULATE_SOC_MS / HALF;
	queue_delayed_work(system_power_efficient_wq,
			&di->calculate_soc_delayed_work,
			round_jiffies_relative(msecs_to_jiffies(
				(unsigned int)di->soc_work_interval)));

	/* The sequence of BATT_1 and BATT_0 cannot be changed.
	    because only BATT_0 controls the chip enter or out the ECO.
	*/
	__pm_stay_awake(di->resume_wake_lock);
	queue_work(system_power_efficient_wq, &di->merge_resume_work);

	coul_merge_info("%s: -\n", __func__);
	return 0;
}
#endif

static int coul_merge_coul_is_ready(void)
{
	if(g_coul_merge)
		return 1;
	else
		return 0;
}

/* 0: invalid battery, 1: successed */
static struct chrg_para_lut *coul_merge_battery_charge_params(void)
{
	return coul_merge_drv_battery_charge_params(BATT_0);
}

static void get_cur_calibration(int *cur_offset_a, int *cur_offset_b)
{
	struct coul_batt_cali_info info = { 0 };
	info.batt_index = 0;
	info.charge_mode = PARALLEL_MODE;
	info.data_type = BATT_DATA_CUR_CALI;
	info.a = DEFAULT_C_OFF_A;
	info.b = DEFAULT_C_OFF_B;

	if (cur_offset_a == NULL || cur_offset_b == NULL) {
		coul_merge_err("%s input para is null\n", __func__);
		return;
	}

	if (coul_merge_drv_get_cali(&info))
		coul_merge_err("%s failed, use DEFAULT_C_OFF_A and DEFAULT_C_OFF_B!\n", __func__);

	*cur_offset_a = info.a;
	*cur_offset_b = info.b;
}

static int is_cathode_type_silicon(char type)
{
	int i;

	for (i = 0; i < TYPE_SILICON_CHARS_LEN; i++) {
		if (type == g_type_silicon_chars[i])
			return 1;
	}
	return 0;
}

static enum bat_model_bat_type coul_merge_get_cathode_type(void)
{
	char buf[BATTRY_SN_CHAR_SIZE] = {0};
	enum bat_model_bat_type ret_type = BAT_CATHODE_TYPE_GRAPHITE;
	char type;
	int ret;

	ret = get_battery_identifier(buf, BATTRY_SN_CHAR_SIZE, 0, BATTRY_SN_LEN);
	if (ret) {
		coul_merge_err("%s error get_battery_identifier, ret=%d\n", __func__, ret);
		return ret_type;
	}

	type = buf[CATHODE_INDEX];
	if (is_cathode_type_silicon(type))
		ret_type = BAT_CATHODE_TYPE_SILICON;
#ifdef CONFIG_DFX_DEBUG_FS
	coul_merge_info("%s get_battery_identifier buf=%s, ret_type=%d\n",
		__func__, buf, ret_type);
#endif
	return ret_type;
}

struct coulometer_ops coul_merge_ops = {
	.is_coul_ready = coul_merge_coul_is_ready,
	.is_battery_exist = coul_merge_is_battery_exist,
	.is_battery_reach_threshold = coul_merge_is_battery_reach_threshold,
	.battery_brand = coul_merge_battery_brand,
	.battery_id_voltage = coul_merge_battery_id_voltage,
	.battery_voltage = coul_merge_battery_voltage,
	.battery_voltage_uv = coul_merge_battery_voltage_uv,
	.battery_current = coul_merge_battery_current,
	.battery_resistance = coul_merge_battery_resistance,
	.fifo_avg_current = coul_merge_fifo_avg_current,
	.battery_current_avg = coul_merge_battery_current_avg,
	/* The coul_merge_battery_capacity function cannot be used.
	   Otherwise, the startup SOC will be overwritten. */
	.battery_capacity = coul_merge_get_capacity,
	.battery_unfiltered_capacity = coul_merge_get_unfiltered_capacity,
	.battery_temperature = coul_merge_battery_temperature,
	.battery_temperature_for_charger =
		coul_merge_battery_temperature,
	.battery_rm = coul_merge_battery_rm,
	.battery_fcc = coul_merge_battery_fcc,
	.battery_fcc_design = coul_merge_battery_fcc_design,
	.battery_health = coul_merge_battery_health,
	.battery_capacity_level = coul_merge_battery_capacity_level,
	.battery_technology = coul_merge_battery_technology,
	.battery_vbat_max = coul_merge_battery_vbat_max,
	.charger_event_rcv = coul_merge_charger_event_rcv,
	.battery_cycle_count = coul_merge_battery_cycle_count,
	.get_battery_limit_fcc = coul_merge_battery_get_limit_fcc,
	.coul_low_temp_opt = coul_merge_low_temp_opt,
	.battery_cc = coul_merge_battery_cc,
	.battery_cc_cache = coul_merge_battery_cc_cache,
	.get_qmax = coul_merge_battery_get_qmax,
	.get_soc_by_ocv = coul_merge_get_soc_by_ocv,
	.battery_charge_params = coul_merge_battery_charge_params,
	.update_basp_policy = coul_merge_update_basp_policy,
	.is_smart_battery = coul_merge_is_smart_battery,
	.get_desired_charging_current = coul_merge_get_desired_charging_current,
	.get_desired_charging_voltage = coul_merge_get_desired_charging_voltage,
	.get_c_calibration = get_cur_calibration,
	.get_cathode_type = coul_merge_get_cathode_type,
	.chip_temperature = coul_merge_battery_temperature,
	.battery_removed_before_boot = coul_merge_battery_removed_before_boot,
#ifdef CONFIG_BATT_SOH
	.convert_mv2regval = coul_merge_convert_mv2regval,
	.convert_regval2ua = coul_merge_convert_regval2ua,
	.convert_regval2uv = coul_merge_convert_regval2uv,
#endif
};

/* smooth first soc to avoid soc jump in startup step */
static void coul_merge_startup_soc(struct coul_merge_device *di)
{
	int last_powerdown_soc;

	last_powerdown_soc = coul_merge_drv_get_last_soc();
	if ((!di->last_soc_enable) || (last_powerdown_soc < 0))
		return;

	if(abs(di->soc - last_powerdown_soc) < di->startup_delta_soc)
		di->soc = last_powerdown_soc;

	coul_merge_info("battery soc=%d, last soc %d\n", di->soc, last_powerdown_soc);
}

static void coul_merge_init_soc(struct coul_merge_device *di)
{
	batt_soc_algo_work();
	coul_merge_battery_capacity();
	coul_merge_startup_soc(di);
}

static int coul_merge_probe(struct platform_device *pdev)
{
	struct coul_merge_device *di = NULL;
	int ret;

	if (!pdev || !pdev->dev.of_node)
		return -ENODEV;

	di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	di->dev = &pdev->dev;
	coul_merge_parse_dts(di);
	mutex_init(&di->lock);
	spin_lock_init(&di->event_lock);
	INIT_KFIFO(di->event_fifo);
	di->soc_work_interval = CALCULATE_SOC_MS;
	INIT_DELAYED_WORK(&di->calculate_soc_delayed_work, coul_merge_monitor_work);
	INIT_DELAYED_WORK(&di->coul_rcv_event_work, coul_merge_rcv_event_work);
	INIT_WORK(&di->merge_resume_work, coul_merge_resume_work);
	di->reboot_nb.notifier_call = coul_merge_shutdown_prepare;
	register_reboot_notifier(&(di->reboot_nb));

	platform_set_drvdata(pdev, di);
	g_coul_merge = di;
	coul_merge_init_soc(di);

	/* create sysfs */
	ret = coul_merge_create_sysfs(di);
	if (ret) {
		coul_merge_err("%s failed to create sysfs\n", __func__);
		return -1;
	}

	queue_delayed_work(system_power_efficient_wq,
		&di->calculate_soc_delayed_work, msecs_to_jiffies(di->soc_work_interval));

	ret = coul_drv_coul_ops_register(&coul_merge_ops, KCOUL);
	if (ret)
		coul_merge_err("%s: coul_merge_ops fail\n", __func__);

	di->resume_wake_lock = wakeup_source_register(di->dev, "coulresume_wakelock");
	if (!di->resume_wake_lock) {
		coul_merge_err("%s resume_wake_lock register failed\n", __func__);
		return -1;
	}

	coul_merge_info("%s: succ, soc %d\n", __func__, di->soc);
	return 0;
}

static int coul_merge_remove(struct platform_device *pdev)
{
	struct coul_merge_device *di = platform_get_drvdata(pdev);

	if (!di)
		return -ENODEV;
	mutex_destroy(&di->lock);
	g_coul_merge = NULL;
	return 0;
}

static const struct of_device_id coul_merge_match_table[] = {
	{
		.compatible = "hisilicon,coul_merge",
		.data = NULL,
	},
	{},
};

static struct platform_driver coul_merge_driver = {
	.probe = coul_merge_probe,
	.remove = coul_merge_remove,
#ifdef CONFIG_PM
	.suspend = coul_merge_suspend,
	.resume = coul_merge_resume,
#endif
	.driver = {
		.name = "hisilicon,coul_merge",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(coul_merge_match_table),
	},
};

static int __init coul_merge_init(void)
{
	return  platform_driver_register(&coul_merge_driver);
}

static void __exit coul_merge_exit(void)
{
	platform_driver_unregister(&coul_merge_driver);
}

rootfs_initcall(coul_merge_init);
module_exit(coul_merge_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("battery driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
