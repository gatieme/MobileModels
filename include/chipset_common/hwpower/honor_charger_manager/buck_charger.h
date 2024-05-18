/*
 * buck_charger.h
 *
 * buck charger driver
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
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

#ifndef _BUCK_CHARGER_H_
#define _BUCK_CHARGER_H_

#include <hwpower/power_interface.h>
#include <hwpower/honor_charger_type.h>
#include <hwpower/honor_charger_manager/honor_charger_control.h>
#include <hwpower/buck_charger_interface.h>

#define SOC_100_PERCENT                  100

#define CUR_LEVEL_TEMP_BELOW_0_DEGREE    0
#define CUR_LEVEL_TEMP_0_TO_5_DEGREE     1
#define CUR_LEVEL_TEMP_5_TO_10_DEGREE    2
#define CUR_LEVEL_TEMP_10_TO_45_DEGREE   3
#define CUR_LEVEL_TEMP_45_TO_50_DEGREE   4
#define CUR_LEVEL_TEMP_EXCEED_50_DEGREE  5

#define VDPM_PARA_LEVEL                  (5)
#define TEMP_PARA_LEVEL                  (6)

#define SUPPORT_BUCK_CHARGER_MONITOR     BIT(0)
#define SUPPORT_SELECT_CHARGING_CUR      BIT(1)
#define SUPPORT_SELECT_JEITA_PARA        BIT(2)
#define SUPPORT_SET_VDPM                 BIT(3)
#define SUPPORT_CHECK_HIGH_VOL           BIT(4)
#define SUPPORT_ENABLE_CHARGE            BIT(5)
#define SUPPORT_SW_CHECK_CHARGE_TERM     BIT(6)
#define SUPPORT_CHECK_CHARGE_STATUS      BIT(8)

#define VDPM_CBAT_MIN               (-32767)
#define VDPM_CBAT_MAX               (32767)
#define VDPM_VOLT_MIN               (3880)
#define VDPM_VOLT_MAX               (5080)

#define TEMP_TBAT_MIN               (-32767)
#define TEMP_TBAT_MAX               (100)
#define TEMP_IIN_MIN                (0)
#define TEMP_IIN_MAX                (3000)
#define TEMP_ICHG_MIN               (0)
#define TEMP_ICHG_MAX               (3000)
#define TEMP_VTERM_MIN              (3800)
#define TEMP_VTERM_MAX              (4500)

#define MIN_CHARGING_CURRENT_OFFSET (-10)

#define JEITA_TEMP_ILIM_DEFAULT_MA  1000
#define JEITA_TEMP_ICHRG_DEFAULT_MA 500
#define JEITA_TEMP_VTERM_DEFAULT_MV 4400
#define BUCK_DOUBLE_85_CHG_TEMP_MAX (65)
#define BUCK_DOUBLE_85_CHG_TEMP_MIN (-30)

#define DEFAULT_CTC_IIN_CURRENT     1000
#define DEFAULT_CTC_ICHG_CURRENT    1000
#define CHARGE_CURRENT_500_MA       500
#define VDPM_DEFAULT_MV             4600
#define TBAT_DEFAULT                25

#define UNIT_1000                   1000
#define UNIT_10                     10

#define OVER_VOL_CHARGING_DISABLED  0
#define OVER_VOL_CHARGING_ENABLE    1

#define VBUS_VOLTAGE_13400_MV       13400

#define DEFAULT_MAX_BUFFER_LEN      32
#define DEFAULT_BAT_PSY_NAME        "battery"
#define MONITOR_RUNNING             1
#define MONITOR_STOP                0

#define ICHG_AVERAGED_ARRAY_LEN     10

/* temp add start */
struct honor_charge_temp_data {
	int temp_min;
	int temp_max;
	int iin_temp;
	int ichg_temp;
	int vterm_temp;
	int temp_back;
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

struct honor_charge_vdpm_data {
	int cap_min;
	int cap_max;
	int vin_dpm;
	int cap_back;
};

enum vdpm_para_info {
	VDPM_PARA_CAP_MIN = 0,
	VDPM_PARA_CAP_MAX,
	VDPM_PARA_DPM,
	VDPM_PARA_CAP_BACK,
	VDPM_PARA_TOTAL,
};

enum chg_type_det_chips {
	RT9471D_BC12 = 0,
	SGM41511H_BC12 = RT9471D_BC12,
	RT8979_BC12,
	FSA9685_BC12,
};

enum {
	HIGHVOL_DEFAULT = 0,
	HIGHVOL_9v,
	HIGHVOL_5v,
	HIGHVOL_DONE,
	HIGHVOL_STOP,
	HIGHVOL_MAX,
};

struct buck_charger_check_error {
	void (*check_error_info)(int val);
};

struct buck_charger_soft_term_rechg {
	int ichg_averaged_array[ICHG_AVERAGED_ARRAY_LEN];
	unsigned int sw_term_re_chg_cnt;
	unsigned int sw_term_chg_done_cnt;
	unsigned int sw_term_rechg_time;
	unsigned int sw_term_exceed_time;
	bool sw_term_chg_done_state;
	bool ichg_aver_running_frist;
	bool warm_triggered;
};

/* temp add end */
struct buck_charge_core_data  {
	unsigned int iin_ac;
	unsigned int ichg_ac;
	unsigned int iin_usb;
	unsigned int ichg_usb;
	unsigned int iin_nonstd;
	unsigned int ichg_nonstd;
	unsigned int iin_bc_usb;
	unsigned int ichg_bc_usb;
	unsigned int iin_fcp;
	unsigned int ichg_fcp;
	unsigned int iin_ctc;
	unsigned int ichg_ctc;
	unsigned int high_vol_charger_max_vol;
	unsigned int battery_cv;
	unsigned int iterm;
	unsigned int support_over_vol_charging;
	unsigned int over_vol_charging_vterm;
	unsigned int over_vol_iterm_higher_35_degree;
	unsigned int over_vol_iterm_higher_25_degree;
	unsigned int over_vol_iterm_higher_10_degree;
	unsigned int vdpm_back_limit;
	unsigned int temp_back_limit;
	int last_bat_temp;
	unsigned char vdpm_levels;
	unsigned char jeita_temp_levels;
	struct honor_charge_vdpm_data vdpm_data[VDPM_PARA_LEVEL];
	struct honor_charge_temp_data temp_data[TEMP_PARA_LEVEL];
};

struct buck_charge_device_info {
	struct device *dev;
	struct device_node *np;
	struct power_supply_desc buck_chg_desc;
	struct power_supply_config buck_chg_cfg;
	struct power_supply *buck_chg_psy;
	struct buck_charge_core_data *buck_core_data;
	struct buck_charger_check_error *check_error_ops;
	struct buck_charger_soft_term_rechg sw_term_rechg;

	struct votable *main_charge_votable;
	struct votable *main_input_votable;
	struct votable *main_constant_voltage_votable;
	struct votable *main_charge_enable_votable;
	struct votable *main_iterm_votable;
	struct votable *main_vdpm_votable;
	struct votable *main_hiz_votable;
	struct votable *main_watchdog_votable;
	struct votable *aux_charge_votable;
	struct votable *aux_input_votable;
	struct votable *aux_constant_voltage_votable;
	struct votable *aux_charge_enable_votable;
	struct votable *aux_iterm_votable;
	struct votable *aux_vdpm_votable;
	struct votable *aux_hiz_votable;
	struct votable *aux_watchdog_votable;

	honor_charge_type charger_type;
	int basp_vterm_dec_mv;
	int buck_monitor_func_control;
	int bat_temp_id;
	int current_adapter_vol;

	unsigned int hw_cur_chg_state;
	unsigned int hw_pre_chg_state;

	unsigned int last_vdpm_level;
	unsigned int last_temp_level;

	bool smart_recharge_support;
	bool already_set_icon;
	bool jeita_running_first;
	bool vdpm_running_first;
	bool high_vol_soc100_restore5v;

	char battery_psy_name[DEFAULT_MAX_BUFFER_LEN];
};

int charger_power_supply_init(struct buck_charge_device_info *di);
void charger_power_supply_exit(void);
int honor_charger_log_info_init(void);
void honor_charger_log_info_exit(void);
void buck_charger_adapter_init(struct buck_charge_device_info *di);
void buck_charger_adapter_exit(void);
int buck_charger_check_error_register(struct buck_charger_check_error *ops);
#endif /* _BUCK_CHARGER_H_ */
