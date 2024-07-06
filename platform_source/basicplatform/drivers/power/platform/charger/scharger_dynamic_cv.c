/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2023. All rights reserved.
 * Description: Device driver for scharger dynamic cv
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include "scharger_dynamic_cv.h"
#include <linux/time64.h>
#include <linux/timekeeping.h>
#include <linux/rtc.h>

#define DSM_BUFF_SIZE_MAX       1024
#define TIMESTAMP_STR_SIZE      32
#define SEC_PER_MIN             60
#define BASIC_YEAR              1900

#define BATT_AUX_NAME  "battery_gauge_aux"
#define BATT_MAIN_NAME "battery_gauge"
#define BATT_NAME_NOT_EXIST 1
#ifndef max
#define max(x, y) (((x) > (y)) ? (x) : (y))
#endif
#ifndef min
#define min(x, y) (((x) < (y)) ? (x) : (y))
#endif
enum chg_mode_state {
	NONE = 0,
	BUCK,
	LVC,
	SC,
	OTG_MODE,
	SOH_MODE
};

struct scharger_cv_ops *g_ops_cv = NULL;

int scharger_cv_ops_register(struct scharger_cv_ops *ops)
{
	int ret = 0;

	if (ops != NULL) {
		g_ops_cv = ops;
	} else {
		scharger_cv_err("scharger cv ops register fail!\n");
		ret = -EPERM;
	}
	return ret;
}

static int get_coul_vbat(int *vbat)
{
	int ret;
	struct power_supply *psy = NULL;
	union power_supply_propval val = {0};

	if (vbat == NULL)
		return -EINVAL;

	psy = power_supply_get_by_name("Battery");
	if (!psy) {
		scharger_cv_err("%s power supply Battery not exist\n", __func__);
		return -EINVAL;
	}

	ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_VOLTAGE_NOW, &val);
	power_supply_put(psy);

	*vbat = val.intval / PERMILLAGE;
	scharger_cv_inf("%s vbat:%d\n", __func__, *vbat);
	return ret;
}

static int get_coul_ibat(char *batt_name, int *ibat, enum power_supply_property psp)
{
	int ret;
	struct power_supply *psy = NULL;
	union power_supply_propval val = {0};

	if (ibat == NULL)
		return -EINVAL;

	psy = power_supply_get_by_name(batt_name);
	if (!psy) {
		scharger_cv_err("power supply %s not exist.\n", batt_name);
		return BATT_NAME_NOT_EXIST;
	}

	ret = power_supply_get_property(psy, psp, &val);
	power_supply_put(psy);

	*ibat = val.intval;
	scharger_cv_inf("%s %s psp:%d, ibat:%d\n", __func__, batt_name, psp, *ibat);
	return ret;
}

static int get_coul_tbat(int *tbat)
{
	int ret;
	struct power_supply *psy = NULL;
	union power_supply_propval val = {0};

	if (tbat == NULL)
		return -EINVAL;

	psy = power_supply_get_by_name("Battery");
	if (!psy) {
		scharger_cv_err("%s power supply Battery not exist\n", __func__);
		return -EINVAL;
	}

	ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_TEMP, &val);
	power_supply_put(psy);

	*tbat = val.intval / 10;
	scharger_cv_inf("%s tbat:%d\n", __func__, *tbat);
	return ret;
}

static int get_batt_capacity(int *cap)
{
	int ret;
	struct power_supply *psy = NULL;
	union power_supply_propval val = {0};

	if (cap == NULL)
		return -EINVAL;

	psy = power_supply_get_by_name("Battery");
	if (!psy) {
		scharger_cv_err("%s power supply Battery not exist\n", __func__);
		return -EINVAL;
	}

	ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_CAPACITY, &val);
	power_supply_put(psy);

	*cap = val.intval;
	scharger_cv_inf("%s batt_cap:%d\n", __func__, *cap);
	return ret;
}

static int get_ibat_max(enum power_supply_property psp)
{
	int ibat_aux;
	int ibat_main;
	int ibat_max;
	int ret;

	get_coul_ibat(BATT_MAIN_NAME, &ibat_main, psp);
	ret = get_coul_ibat(BATT_AUX_NAME, &ibat_aux, psp);
	if (ret == BATT_NAME_NOT_EXIST) {
		scharger_cv_err("%s get %s not exist\n", __func__, BATT_AUX_NAME);
		ibat_max = ibat_main;
	} else {
		ibat_max = max(ibat_aux, ibat_main);
	}

	return ibat_max;
}

static int scharger_cv_mode_check(struct scharger_cv_device_info *di)
{
	int charge_done;
	int buck_mode;
	int charge_en;
	int batt_cap;
	int ibat_avg_max;
	int ibat_now_max;

	scharger_cv_dbg("%s +\n", __func__);

	charge_done = g_ops_cv->get_charge_done_state();
	get_batt_capacity(&batt_cap);
	buck_mode = g_ops_cv->get_chg_mode();
	charge_en = g_ops_cv->get_chg_enable();
	di->cv_ori_new = g_ops_cv->get_vterm();
	ibat_avg_max = get_ibat_max(POWER_SUPPLY_PROP_CURRENT_AVG);
	ibat_now_max = get_ibat_max(POWER_SUPPLY_PROP_CURRENT_NOW);

	scharger_cv_inf("%s charge_done:%d, buck_mode:%d,charge_en:%d,cv_ori:%d,vbat_max:%d,ibat_now_max:%d,ibat_avg_max:%d\n",
		 __func__, charge_done, buck_mode, charge_en, di->cv_ori_new, di->vbat_max, ibat_now_max, ibat_avg_max);

	/* current cv neets to be close to vbat max and less than 20mV */
	if (charge_done == 0 && buck_mode == BUCK  && ibat_avg_max < di->ibat_thre &&
			 ibat_now_max < di->ibat_thre && charge_en == 1 && di->vbat_max - di->cv_ori_new >= 0 &&
			 di->vbat_max - di->cv_ori_new < 20 && batt_cap >= BATT_CAP_97)
		return 1;

	return 0;
}

static int clear_cv_data(struct scharger_cv_device_info *di)
{
	int ret = 0;

	scharger_cv_dbg("%s +\n", __func__);

	g_ops_cv->clear_cv_trim_flag();
	di->cv_sample_count = 0;
	di->first_sample_flag = 1;

	ret = memset_s(&di->batt_vol[0], sizeof(di->batt_vol), 0, sizeof(di->batt_vol));
	if (ret != 0) {
		scharger_cv_err("%s memset_s failed\n", __func__);
		return -1;
	}

	return 0;
}

static int get_ibat_min(enum power_supply_property psp)
{
	int ibat_main;
	int ibat_aux;
	int ibat_min;
	int ret = 0;

	get_coul_ibat(BATT_MAIN_NAME, &ibat_main, psp);
	ret = get_coul_ibat(BATT_AUX_NAME, &ibat_aux, psp);
	if (ret == BATT_NAME_NOT_EXIST) {
		scharger_cv_dbg("%s get %s ibat_aux fail, single batt\n", __func__, BATT_AUX_NAME);
		ibat_min = ibat_main;
	} else {
		ibat_min = min(ibat_aux, ibat_main);
	}

	return ibat_min;
}

static int cv_get_timestamp(char *str, int len)
{
	struct timespec64 tv = {0};
	struct rtc_time tm = {0};

	if (str == NULL) {
		scharger_cv_err("%s input para is null\n", __func__);
		return -EINVAL;
	}

	ktime_get_real_ts64(&tv);
	tv.tv_sec -= (long)sys_tz.tz_minuteswest * SEC_PER_MIN;
	rtc_time64_to_tm(tv.tv_sec, &tm);

	(void)sprintf_s(str, len, "%04d-%02d-%02d %02d:%02d:%02d",
		 tm.tm_year + BASIC_YEAR, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
		 tm.tm_min, tm.tm_sec);

	return strlen(str);
}

static int cv_dmd_report_trim_info(struct scharger_cv_device_info *di, int err_num)
{
#ifdef CONFIG_HUAWEI_DSM
	char timestamp[TIMESTAMP_STR_SIZE] = {0};
	char dsm_buf[DSM_BUFF_SIZE_MAX] = {0};
	int tmp_len = 0;

	if (di == NULL)
		return -1;

	cv_get_timestamp(timestamp, TIMESTAMP_STR_SIZE);
	tmp_len += sprintf_s(dsm_buf, DSM_BUFF_SIZE_MAX, "%s\n", timestamp);

	/* cv trim key info */
	tmp_len += sprintf_s(dsm_buf + tmp_len, DSM_BUFF_SIZE_MAX - tmp_len,
		"[cv trim info]average vbat:%d,cv ori val :%d, cv new set:%d\n",
		di->vbat_average,di->cv_ori, di->cv_new_set);

	scharger_cv_inf("[%s] dsm_buf: %s\n",__func__,dsm_buf);
	/* report */
	return power_dsm_report_dmd(POWER_DSM_BATTERY, err_num, dsm_buf);
#else
	return 0;
#endif
}

static void scharger_cv_get_data_work(struct work_struct *work)
{
	struct scharger_cv_device_info *di = container_of(work, struct scharger_cv_device_info,
		 get_data_work.work);
	int cv_mode_flag = 0;
	int vbat;
	int tbat;
	int ret = 0;
	int ibat_avg_min;
	int ibat_now_min;

	scharger_cv_dbg("%s +\n", __func__);

	cv_mode_flag = scharger_cv_mode_check(di);
	scharger_cv_inf("%s cv_mode_flag = %d \n", __func__,cv_mode_flag);
	if (cv_mode_flag == 1) {
		/* first time meet the conditions, record original cv */
		if (di->first_sample_flag == 1)
			di->cv_ori = di->cv_ori_new;

		if (di->cv_ori != di->cv_ori_new) {
			scharger_cv_err("%s cv_ori is changed, finish trim!\n", __func__);
			di->working_flag = CV_ABNORMAL;
			di->protect_cnt = 0;
			g_ops_cv->reset_cv_value();
			cancel_delayed_work(&di->calcu_trim_val_work);
			return;
		}
		get_coul_vbat(&vbat);
		ibat_avg_min = get_ibat_min(POWER_SUPPLY_PROP_CURRENT_AVG);
		ibat_now_min = get_ibat_min(POWER_SUPPLY_PROP_CURRENT_NOW);
		get_coul_tbat(&tbat);
	} else {
		ret = memset_s(&di->batt_vol[0], sizeof(di->batt_vol), 0, sizeof(di->batt_vol));
		if (ret != 0) {
			scharger_cv_err("%s memset_s failed\n", __func__);
			di->working_flag = CV_ABNORMAL;
			di->protect_cnt = 0;
			g_ops_cv->reset_cv_value();
			cancel_delayed_work(&di->calcu_trim_val_work);
			return;
		}
		di->first_sample_flag = 1;
		di->cv_sample_count = 0;
		(void)queue_delayed_work(system_power_efficient_wq, &di->get_data_work,
			 msecs_to_jiffies(SAMPLE_CYCLE_MS));
		return;
	}

	if (ibat_avg_min > di->cv_ibat_min_thre && ibat_now_min > di->cv_ibat_min_thre && tbat <= COUL_PRECISION_TEMP_HIGH &&
			 tbat >= COUL_PRECISION_TEMP_LOW && vbat <= di->vbat_max - di->vbat_max_margin) {
		if (di->cv_sample_count < DATA_COUNT) {
			di->batt_vol[di->cv_sample_count] = vbat;
		} else {
			di->batt_vol[0] = vbat;
			di->cv_sample_count = 0;
		}
		di->first_sample_flag = 0;
		scharger_cv_inf ("%s di->batt_vol[%d] = %d\n", __func__, di->cv_sample_count, vbat);
		di->cv_sample_count++;
	} else {
		scharger_cv_err("%s temp, vbat or ibat check fail, clear data\n", __func__);
		ret = memset_s(&di->batt_vol[0], sizeof(di->batt_vol), 0, sizeof(di->batt_vol));
		if (ret != 0) {
			scharger_cv_err("%s memset_s failed\n", __func__);
			di->working_flag = CV_ABNORMAL;
			di->protect_cnt = 0;
			g_ops_cv->reset_cv_value();
			cancel_delayed_work(&di->calcu_trim_val_work);
			return;
		}
		di->first_sample_flag = 1;
		di->cv_sample_count = 0;
	}

	(void)queue_delayed_work(system_power_efficient_wq, &di->get_data_work,
			 msecs_to_jiffies(SAMPLE_CYCLE_MS));
}

static int value_compare(const void *val_a, const void *val_b)
{
	return (*(int*)val_a - *(int*)val_b);
}

static int scharger_cv_get_vbat_average(struct scharger_cv_device_info *di)
{
	int i;
	int vbat_sum = 0;
	int vbat_average;

	/* Remove the largest two and the smallest two, and calculate the average value of the remaining data */
	sort(di->batt_vol, DATA_COUNT, sizeof(int), value_compare, NULL);
	for (i = 2; i < DATA_COUNT - 2; i++) {
		vbat_sum += di->batt_vol[i];
		scharger_cv_inf("%s vbat[%d]:%d!\n",__func__, i , di->batt_vol[i]);
	}
	vbat_average = vbat_sum / (DATA_COUNT - 4);

	return vbat_average;
}

static void scharger_cv_calcu_trim_val_work(struct work_struct *work)
{
	struct scharger_cv_device_info *di = container_of(work, struct scharger_cv_device_info,
		 calcu_trim_val_work.work);
	int ret = 0;
	int delta_v;

	scharger_cv_dbg("%s +\n", __func__);

	/* batt_vol data is ready */
	if (di->batt_vol[DATA_COUNT - 1] == 0) {
		scharger_cv_inf("%s batt_vol data not ready\n", __func__);
		(void)queue_delayed_work(system_power_efficient_wq, &di->calcu_trim_val_work,
			 msecs_to_jiffies(CALCU_CYCLE_MS));
		return;
	}

	di->vbat_average = scharger_cv_get_vbat_average(di);
	delta_v = di->vbat_max - di->vbat_max_margin - di->vbat_average;
	if (delta_v < 0) {
		scharger_cv_err("%s delta_v:%d is negative, stop trim\n", __func__, delta_v);
		di->working_flag = CV_ABNORMAL;
		di->protect_cnt = 0;
		g_ops_cv->reset_cv_value();
		cancel_delayed_work(&di->get_data_work);
		return;
	}
	if (delta_v > di->delta_cv_max) {
		scharger_cv_err("%s delta_v %d is greater than delta_cv_max %d\n", __func__, delta_v, di->delta_cv_max);
		delta_v = di->delta_cv_max;
	}
	di->cv_new_set = di->cv_ori + delta_v;

#ifdef CONFIG_HUAWEI_DSM
	cv_dmd_report_trim_info(di,POWER_DSM_CHARGE_DYNAMIC_CV_TRIM_INFO);
#endif

	scharger_cv_err("%s delta_v:%d vbat_average:%d, cv_new_set:%d\n", __func__, delta_v,di->vbat_average, di->cv_new_set);
	ret = g_ops_cv->set_vterm(di->cv_ori, di->cv_new_set);
	if (ret)
		scharger_cv_err("%s set vterm fail\n", __func__);

	cancel_delayed_work(&di->get_data_work);
	(void)queue_delayed_work(system_power_efficient_wq, &di->safety_protect_work,
		 msecs_to_jiffies(JUDGE_TRIM_COMPLETE_CYCLE_MS));
}

static int cv_dmd_report_compensate_info(struct scharger_cv_device_info *di,
	int err_num, int cur_vbat)
{
#ifdef CONFIG_HUAWEI_DSM
	char timestamp[TIMESTAMP_STR_SIZE] = {0};
	char dsm_buf[DSM_BUFF_SIZE_MAX] = {0};
	int tmp_len = 0;

	if (di == NULL)
		return -1;

	cv_get_timestamp(timestamp, TIMESTAMP_STR_SIZE);
	tmp_len += sprintf_s(dsm_buf, DSM_BUFF_SIZE_MAX, "%s\n", timestamp);

	/* cv compensate info */
	tmp_len += sprintf_s(dsm_buf + tmp_len, DSM_BUFF_SIZE_MAX - tmp_len,
		"[dynamic cv protect]delta_v :%d, cur vbat:%d\n",
		di->cv_new_set - di->cv_ori,cur_vbat);

	scharger_cv_inf("[%s] dsm_buf:  %s\n",__func__,dsm_buf);
	/* report */
	return power_dsm_report_dmd(POWER_DSM_BATTERY, err_num, dsm_buf);
#else
	return 0;
#endif
}

static void scharger_cv_safety_protect_work(struct work_struct *work)
{
	struct scharger_cv_device_info *di = container_of(work, struct scharger_cv_device_info,
		 safety_protect_work.work);
	int vbat;

	if (g_ops_cv->get_chg_mode() != BUCK) {
		scharger_cv_inf("[%s] Not buck mode, exit protect work\n", __func__);
		di->working_flag = CV_ABNORMAL;
		di->protect_cnt = 0;
		g_ops_cv->reset_cv_value();
		return;
	}

	get_coul_vbat(&vbat);
	scharger_cv_inf("[%s] current vbat:%d!\n", __func__, vbat);

	if (di->vbat_max - vbat <= CV_PROTECT_MARGIN) {
		scharger_cv_err("[%s] safe threshold reached %dmv\n", __func__, vbat);
		di->protect_cnt++;
	} else {
		di->protect_cnt = 0;
	}

#ifdef CONFIG_HUAWEI_DSM
	if (di->protect_cnt >= CV_PROTECT_CNT || di->cv_new_set - di->cv_ori > di->delta_cv_max)
		cv_dmd_report_compensate_info(di, POWER_DSM_CHARGE_DYNAMIC_CV_TRIM_MAX, vbat);
#endif

	if (di->protect_cnt >= CV_PROTECT_CNT) {
		scharger_cv_err("[%s] protect_cnt >= 5, reset cv\n", __func__);
		di->working_flag = CV_ABNORMAL;
		di->protect_cnt = 0;
		g_ops_cv->reset_cv_value();
		return;
	}

	(void)queue_delayed_work(system_power_efficient_wq, &di->safety_protect_work,
		 msecs_to_jiffies(JUDGE_TRIM_COMPLETE_CYCLE_MS));
}

static int check_cv_ops(void)
{
	if (g_ops_cv == NULL || g_ops_cv->set_vterm == NULL || g_ops_cv->clear_cv_trim_flag == NULL
		|| g_ops_cv->get_charge_done_state == NULL || g_ops_cv->get_chg_mode == NULL
		|| g_ops_cv->get_chg_enable == NULL || g_ops_cv->get_vterm == NULL || g_ops_cv->reset_cv_value == NULL) {
		scharger_cv_err("%s g_ops_cv is NULL or member is NULL\n", __func__);
		return -1;
	}

	return 0;
}

void start_cv_trim(struct scharger_cv_device_info *di)
{
	int ret;
	scharger_cv_inf("%s + \n", __func__);

	ret = clear_cv_data(di);
	if (ret != 0) {
		scharger_cv_err("%s clear cv data fail\n", __func__);
		return;
	}

	(void)queue_delayed_work(system_power_efficient_wq, &di->get_data_work,
		 msecs_to_jiffies(0));
	(void)queue_delayed_work(system_power_efficient_wq, &di->calcu_trim_val_work,
		 msecs_to_jiffies(0));
}

static int scharger_cv_charger_event(struct notifier_block *chg_nb,
	       unsigned long event, void *priv_data)
{
	struct scharger_cv_device_info *di = container_of(chg_nb, struct scharger_cv_device_info, chg_nb);
	if (di == NULL) {
		scharger_cv_err("%s data is NULL\n", __func__);
		return -EINVAL;
	}

	scharger_cv_inf("%s event: %ld\n", __func__, event);

	switch (event) {
	case VCHRG_START_AC_CHARGING_EVENT:
		if (di->working_flag != CV_IDLE)
			return NOTIFY_OK;
		di->working_flag = CV_WORKING;
		start_cv_trim(di);
		break;
	case VCHRG_CHARGE_DONE_EVENT:
	case VCHRG_STOP_CHARGING_EVENT:
		if (di->working_flag != CV_IDLE) {
			di->protect_cnt = 0;
			di->working_flag = CV_IDLE;
			g_ops_cv->reset_cv_value();
			cancel_delayed_work(&di->get_data_work);
			cancel_delayed_work(&di->calcu_trim_val_work);
			cancel_delayed_work(&di->safety_protect_work);
			scharger_cv_inf("%s event:%ld, cancel cv trim!\n", __func__, event);
		}
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static int scharger_cv_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct device *dev = &pdev->dev;
	struct scharger_cv_device_info *di = NULL;

	scharger_cv_dbg("%s +\n", __func__);

	di = devm_kzalloc(dev, sizeof(*di), GFP_KERNEL);
	if (!di) {
		scharger_cv_err("[%s]di is null.\n", __func__);
		return -ENOMEM;
	}
	di->dev = dev;

	ret = check_cv_ops();
	if (ret) {
		scharger_cv_err("%s ops register fail!\n", __func__);
		return 0;
	}

	ret = of_property_read_u32(dev->of_node, "vbat_max", (u32 *)&(di->vbat_max));
	if (ret)
		scharger_cv_err("get vbat_max failed\n");
	ret = of_property_read_u32(dev->of_node, "ibat_thre", (u32 *)&(di->ibat_thre));
	if (ret)
		scharger_cv_err("get ibat_thre failed\n");
	ret = of_property_read_u32(dev->of_node, "vbat_max_margin", (u32 *)&(di->vbat_max_margin));
	if (ret)
		scharger_cv_err("get vbat_max_margin failed\n");
	ret = of_property_read_u32(dev->of_node, "delta_cv_max", (u32 *)&(di->delta_cv_max));
	if (ret)
		scharger_cv_err("get delta_cv_max failed\n");
	ret = of_property_read_u32(dev->of_node, "cv_ibat_min_thre", (u32 *)&(di->cv_ibat_min_thre));
	if (ret) {
		di->cv_ibat_min_thre = CV_IBAT_MIN_DEFAULT;
		scharger_cv_err("cv_ibat_min_thre set default 10\n");
	}

	INIT_DELAYED_WORK(&di->get_data_work, scharger_cv_get_data_work);
	INIT_DELAYED_WORK(&di->calcu_trim_val_work, scharger_cv_calcu_trim_val_work);
	INIT_DELAYED_WORK(&di->safety_protect_work, scharger_cv_safety_protect_work);

	di->chg_nb.notifier_call = scharger_cv_charger_event;
	ret += bci_register_notifier(&di->chg_nb, 1);
	if (ret != 0)
		scharger_cv_err("%s notifier_register failed\n", __func__);

	scharger_cv_dbg("[%s]-\n", __func__);
	return 0;
}

static int scharger_cv_remove(struct platform_device *pdev)
{
	return 0;
}

const static struct of_device_id of_scharger_cv_match_tbl[] = {
	{
		.compatible = "hisilicon,scharger_cv",
		.data = NULL,
	},
	{},
};

static struct platform_driver scharger_cv_driver = {
	.driver = {
		.name	= "scharger_cv",
		.owner  = THIS_MODULE,
		.of_match_table = of_scharger_cv_match_tbl,
	},
	.probe	= scharger_cv_probe,
	.remove	= scharger_cv_remove,
};

static int __init scharger_dynamic_cv_init(void)
{
	return platform_driver_register(&scharger_cv_driver);
}

static void __exit scharger_dynamic_cv_exit(void)
{
	platform_driver_unregister(&scharger_cv_driver);
}

late_initcall(scharger_dynamic_cv_init);
module_exit(scharger_dynamic_cv_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("schargerV700 dynamic cv driver");