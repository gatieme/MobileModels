/*
 * direct_charger.h
 *
 * direct charger driver
 *
 * Copyright (c) 2020-2023 Huawei Technologies Co., Ltd.
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

#ifndef _DIRECT_CHARGER_H_
#define _DIRECT_CHARGER_H_

#include <linux/module.h>
#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/hrtimer.h>
#include <linux/workqueue.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/pm_wakeup.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <huawei_platform/power/huawei_charger.h>
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwpower/common_module/power_ui_ne.h>
#ifdef CONFIG_SUPERSWITCH_FSC
#include <huawei_platform/usb/superswitch/fsc/core/hw_scp.h>
#endif
#ifdef CONFIG_WIRELESS_CHARGER
#include <huawei_platform/power/wireless/wireless_charger.h>
#endif
#include <chipset_common/hwpower/direct_charge/direct_charge_charging_info.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_control.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_power_supply.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_error_handle.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_device_id.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_para_parse.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_path_switch.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_adapter.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_uevent.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_check.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_ic_manager.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_cable.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_test.h>
#include <chipset_common/hwpower/direct_charge/multi_ic_check.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_mmi.h>
#include <chipset_common/hwpower/direct_charge/direct_charge_comp.h>
#include <chipset_common/hwpower/direct_charge/direct_charger_constants.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_dts.h>

struct direct_charge_temp_para {
	int temp_min;
	int temp_max;
	int temp_cur_max;
};

/*
 * define multistage (cc)constant current and (cv)constant voltage
 * support up to 5 parameters list on dts
 */

enum direct_charge_volt_info {
	DC_PARA_VOL_TH = 0,
	DC_PARA_CUR_TH_HIGH,
	DC_PARA_CUR_TH_LOW,
	DC_PARA_VOLT_TOTAL,
};

struct direct_charge_volt_para {
	int vol_th;
	int cur_th_high;
	int cur_th_low;
};

/*
 * define voltage parameters of different batteries
 * at different temperature threshold
 * support up to 16 parameters list on dts
 */

enum direct_charge_bat_info {
	DC_PARA_BAT_ID = 0,
	DC_PARA_TEMP_LOW,
	DC_PARA_TEMP_HIGH,
	DC_PARA_INDEX,
	DC_PARA_BAT_TOTAL,
};

struct direct_charge_bat_para {
	int temp_low;
	int temp_high;
	int parse_ok;
	char batid[DC_BAT_BRAND_LEN_MAX];
	char volt_para_index[DC_VOLT_NODE_LEN_MAX];
};

/*
 * define dc time threshold with maximum current
 * support up to 7 parameters list on dts
 */
enum direct_charge_time_info {
	DC_TIME_INFO_TIME_TH,
	DC_TIME_INFO_IBAT_MAX,
	DC_TIME_INFO_MAX,
};

struct direct_charge_time_para {
	int time_th;
	int ibat_max;
};

struct direct_charge_time_para_group {
	u32 mode;
	struct direct_charge_time_para time_info[DC_TIME_PARA_LEVEL];
};

struct direct_charge_volt_para_group {
	struct direct_charge_volt_para volt_info[DC_VOLT_LEVEL];
	struct direct_charge_bat_para bat_info;
	int stage_size;
};

struct direct_charge_vstep_para {
	int curr_gap;
	int vstep;
};

/* define lvc mos info */
struct dc_lvc_mos_para {
	bool enable;
	int is_support;
	int ibat_th;
	int curr_offset;
	int err_cnt_th;
	int err_th;
	int err_cnt;
};

struct direct_charge_soc_ibat_th_para {
	int soc;
	int ibat_th;
};

struct direct_charge_device {
	struct device *dev;
	struct hrtimer calc_thld_timer;
	struct hrtimer anomaly_det_timer;
	struct hrtimer control_timer;
	struct hrtimer kick_wtd_timer;
	struct workqueue_struct *charging_wq;
	struct workqueue_struct *kick_wtd_wq;
	struct work_struct calc_thld_work;
	struct work_struct anomaly_det_work;
	struct work_struct control_work;
	struct work_struct fault_work;
	struct work_struct kick_wtd_work;
	struct notifier_block fault_nb;
	struct direct_charge_volt_para volt_para[DC_VOLT_LEVEL];
	struct direct_charge_volt_para orig_volt_para[DC_VOLT_LEVEL];
	struct direct_charge_volt_para_group orig_volt_para_p[DC_VOLT_GROUP_MAX];
	struct direct_charge_temp_para temp_para[DC_TEMP_LEVEL];
	struct direct_charge_time_para time_para[DC_TIME_PARA_LEVEL];
	struct direct_charge_time_para_group time_para_p[DC_TIME_GROUP_MAX];
	struct direct_charge_vstep_para vstep_para[DC_VSTEP_PARA_LEVEL];
	struct direct_charge_soc_ibat_th_para soc_ibat_th_para[DC_GROUP_MAX];
	struct multi_ic_check_para multi_ic_check_info;
	struct multi_ic_check_mode_para multi_ic_mode_para;
	struct dc_lvc_mos_para lvc_mos_dts;
	struct dc_comp_para comp_para;
	struct nty_data *fault_data;
	int time_para_parse_ok;
	int time_para_p_parse_ok;
	int stage_need_to_jump[2 * DC_VOLT_LEVEL];
	int error_cnt;
	u32 multi_ic_error_cnt;
	int working_mode;
	int cur_mode;
	int local_mode;
	int curr_offset;
	int multi2single_ibat_delta;
	u32 use_5a;
	u32 use_8a;
	int sysfs_enable_charger;
	u32 sysfs_mainsc_enable_charger;
	u32 sysfs_auxsc_enable_charger;
	unsigned int sysfs_disable_charger[DC_DISABLE_END];
	u32 threshold_caculation_interval;
	u32 charge_control_interval;
	u32 force_disable;
	int cur_stage;
	int cur_vbat_th;
	int cur_ibat_th_high;
	int cur_ibat_th_low;
	int multi_ic_ibat_th;
	int vbat;
	int ibat;
	int ibat_abnormal_cnt;
	int ibat_abnormal_th;
	int vadapt;
	int iadapt;
	int tadapt;
	int ls_vbus;
	int ls_ibus;
	int tls;
	int stage_size;
	int stage_group_size;
	int volt_para_test_flag;
	int turbo_test_flag;
	int pre_stage;
	int adaptor_vset;
	int max_tls;
	int adaptor_iset;
	int init_delt_vset;
	int init_delt_iset;
	int init_adapter_vset;
	int delta_err;
	int vstep;
	int scp_stop_charging_flag_info;
	int stop_charging_flag_error;
	int max_dc_bat_vol;
	int min_dc_bat_vol;
	int min_ibat_th;
	int super_ico_current;
	int bst_ctrl;
	int scp_power_en;
	int compensate_r;
	int all_stage_compensate_r_en;
	int compensate_v;
	u32 cc_protect;
	int ls_id;
	const char *ls_name;
	int vol_err_th;
	int need_check_tx_iin;
	int adaptor_leakage_current_th;
	int dc_succ_flag;
	int scp_cable_detect_enable;
	u32 dc_multi_ic_start_time;
	unsigned int charge_fault;
	int adaptor_vendor_id;
	u32 scp_work_on_charger;
	int dc_err_report_flag;
	int dc_open_retry_cnt;
	int reverse_ocp_cnt;
	int otp_cnt;
	int adp_otp_cnt;
	int dc_volt_ratio;
	unsigned int dc_stage;
	int cutoff_normal_flag;
	char dsm_buff[DC_DMDLOG_SIZE];
	int err_type_cnt[DC_EH_END];
	int scp_stop_charging_complete_flag;
	struct wakeup_source *charging_lock;
	int sc_conv_ocp_count;
	int iin_thermal_default;
	int last_basp_level;
	u32 reset_adap_volt_enabled;
	unsigned int vterm_dec;
	unsigned int ichg_ratio;
	int bat_temp_before_charging;
	u32 low_temp_hysteresis;
	u32 orig_low_temp_hysteresis;
	u32 high_temp_hysteresis;
	u32 orig_high_temp_hysteresis;
	u32 startup_iin_limit;
	u32 hota_iin_limit;
	bool nonstd_cable_flag;
	u32 need_wired_sw_off;
	int max_pwr;
	int ui_max_pwr;
	int product_max_pwr;
	bool pri_inversion;
	int cur_inversion;
	u32 adapter_type;
	struct dc_test_info curr_info;
	u32 cc_unsafe_sc_enable;
	bool cc_safe;
	u32 use_higher_vbat;
	u32 tbat_id;
	u32 support_series_bat_mode;
	u32 bat_cell_num;
	u32 charge_time;
	u32 stop_charging_sleep_enable;
	u32 need_boost_5v;
	u32 prot_type;
	u32 recharge_vbat_th;
	u32 battery_connect_mode;
	u32 pmu_mode_set_flag;
	int regulation_by_ibat;
	int vadapt_diff_th;
	int dfg_disable;
	int sysfs_disable;
	u32 wtd_timeout;
	u32 kick_wtd_time;
};
typedef struct aging_safe_policy_tag {
	unsigned int level;       /* basp level */
	unsigned int dc_volt_dec;  /* direct_charge voltage decrease mV */
	unsigned int nondc_volt_dec;  /* non-direct_charge voltage decrease mV */
	unsigned int cur_ratio; /* current discount ratio:cur_ratio/100 */
	unsigned int cur_ratio_policy; /* 0:apply ratio policy for all segments */
					/* 1:apply ratio policy for max current */
	unsigned int learned_fcc; /* used as charging current 1C after fcc learned */
} aging_safe_policy_type;

#ifdef CONFIG_DIRECT_CHARGER
void direct_charge_set_di(struct direct_charge_device *di);
void direct_charge_set_di_by_mode(int mode);
struct direct_charge_device *direct_charge_get_di(void);
struct direct_charge_device *direct_charge_get_di_by_mode(int mode);
unsigned int direct_charge_get_stage_status(void);
unsigned int direct_charge_get_stage_status_by_mode(int mode);
const char *direct_charge_get_stage_status_string(unsigned int stage);
void direct_charge_set_stage_status(unsigned int stage);
void direct_charge_set_stage_status_default(void);
int direct_charge_in_charging_stage(void);
void direct_charge_set_disable_flags(int val, int type);
int direct_charge_get_product_max_current(int mode);
int direct_charge_battery_temp_handler(int value);
void direct_charge_force_disable_dc_path(void);
int direct_charge_init_adapter_and_device(void);
int direct_charge_switch_path_to_normal_charging(void);
int direct_charge_switch_path_to_dc_charging(void);
int direct_charge_open_charging_path(void);
bool direct_charge_get_stop_charging_complete_flag(void);
int direct_charge_detect_adapter_again(void);
void direct_charge_exit(void);
int direct_charge_get_cutoff_normal_flag(void);
void direct_charge_update_cutoff_normal_flag(void);
bool direct_charge_check_timeout(void);
void direct_charge_update_charge_info(void);
int direct_charge_fault_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data);
void direct_charge_stop_charging(void);
void direct_charge_select_charging_param(void);
void direct_charge_select_charging_stage(void);
void direct_charge_soh_policy(void);
int direct_charge_get_vstep(int mode);
bool direct_charge_check_priority_inversion(void);
bool direct_charge_is_priority_inversion(void);
int lvc_get_di(struct direct_charge_device **di);
int lvc_set_disable_flags(int val, int type);
int sc_get_di(struct direct_charge_device **di);
int sc_set_disable_flags(int val, int type);
int sc4_get_di(struct direct_charge_device **di);
int sc4_set_disable_flags(int val, int type);
int direct_charge_get_succ_flag(void);
#else
static inline void direct_charge_set_di(struct direct_charge_device *di)
{
}

static inline void direct_charge_set_di_by_mode(int mode)
{
}

static inline struct direct_charge_device *direct_charge_get_di(void)
{
	return NULL;
}

static inline struct direct_charge_device *direct_charge_get_di_by_mode(int mode)
{
	return NULL;
}

static inline unsigned int direct_charge_get_stage_status(void)
{
	return DC_STAGE_DEFAULT;
}

static inline unsigned int direct_charge_get_stage_status_by_mode(int mode)
{
	return DC_STAGE_DEFAULT;
}

static inline const char *direct_charge_get_stage_status_string(
	unsigned int stage)
{
	return "illegal stage status";
}

static inline void direct_charge_set_stage_status(unsigned int stage)
{
}

static inline void direct_charge_set_stage_status_default(void)
{
}

static inline int direct_charge_in_charging_stage(void)
{
	return -1;
}

static inline void direct_charge_set_disable_flags(int val, int type)
{
}

static inline int direct_charge_get_product_max_current(int mode)
{
	return -1;
}

static inline int direct_charge_battery_temp_handler(int value)
{
	return 0;
}

static inline int direct_charge_get_device_delta_err(int mode)
{
	return -EINVAL;
}

static inline void direct_charge_force_disable_dc_path(void)
{
}

static inline int direct_charge_init_adapter_and_device(void)
{
	return -1;
}

static inline int direct_charge_switch_path_to_normal_charging(void)
{
	return -1;
}

static inline int direct_charge_switch_path_to_dc_charging(void)
{
	return -1;
}

static inline int direct_charge_open_charging_path(void)
{
	return -1;
}

static inline bool direct_charge_get_stop_charging_complete_flag(void)
{
	return true;
}

static inline int direct_charge_detect_adapter_again(void)
{
	return -1;
}

static inline void direct_charge_exit(void)
{
}

static inline int direct_charge_get_cutoff_normal_flag(void)
{
	return -1;
}

static inline void direct_charge_update_cutoff_normal_flag(void)
{
}

static inline bool direct_charge_check_timeout(void)
{
	return false;
}

static inline void direct_charge_update_charge_info(void)
{
}

static inline int direct_charge_fault_notifier_call(struct notifier_block *nb,
	unsigned long event, void *data)
{
	return NOTIFY_OK;
}

static inline void direct_charge_stop_charging(void)
{
}

static inline void direct_charge_select_charging_param(void)
{
}

static inline void direct_charge_select_charging_stage(void)
{
}

static inline void direct_charge_soh_policy(void)
{
}

static inline int direct_charge_get_vstep(int mode)
{
	return -EINVAL;
}

static inline bool direct_charge_check_priority_inversion(void)
{
	return false;
}

static inline bool direct_charge_is_priority_inversion(void)
{
	return false;
}

static inline int lvc_get_di(struct direct_charge_device **di)
{
	return -1;
}

static inline int lvc_set_disable_flags(int val, int type)
{
	return -1;
}

static inline int sc_get_di(struct direct_charge_device **di)
{
	return -1;
}

static inline int sc_set_disable_flags(int val, int type)
{
	return -1;
}

static inline int sc4_get_di(struct direct_charge_device **di)
{
	return -1;
}

static inline int sc4_set_disable_flags(int val, int type)
{
	return -1;
}

static inline int direct_charge_get_succ_flag(void)
{
	return -1;
}
#endif /* CONFIG_DIRECT_CHARGER */

#endif /* _DIRECT_CHARGER_H_ */
