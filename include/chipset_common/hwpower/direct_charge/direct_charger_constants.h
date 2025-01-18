/*
 * direct_charger_constants.h
 *
 * direct charger constants
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
 
#ifndef _DIRECT_CHARGE_CONSTANTS_H_
#define _DIRECT_CHARGE_CONSTANTS_H_
 
#define DC_DMDLOG_SIZE                2048
#define REVERSE_OCP_CNT               3
#define OTP_CNT                       3
#define ADP_OTP_CNT                   3
#define DOUBLE_SIZE                   2
 
/* sensor_id#scene_id#stage */
#define DC_THERMAL_REASON_SIZE        16
 
#define DC_ERROR_RESISTANCE           (-99999)
#define DC_MAX_RESISTANCE             10000
#define DC_CHARGE_TYPE_LVC            3
#define DC_CHARGE_TYPE_SC             2
#define DC_CHARGE_TYPE_FCP            4
#define DC_CHARGE_TYPE_SC4            5
 
#define DC_ERR_CNT_MAX                8
#define DC_MULTI_ERR_CNT_MAX          4
#define DC_OPEN_RETRY_CNT_MAX         3
#define DC_OPEN_CHECK_IC_CYCLE        5
#define DC_FULL_RES_ERR_MAX           6
 
#define INVALID                       (-1)
#define VALID                         0
#define WAIT_LS_DISCHARGE             200
#define MAX_TIMES_FOR_SET_ADAPTER_VOL 30
#define MIN_CURRENT_FOR_RES_DETECT    800
#define CURRENT_SET_FOR_RES_DETECT    1000
 
#define ENABLE                        1
#define DISABLE                       0
 
#define VBUS_ON_THRESHOLD             3000
#define VBAT_VBUS_DIFFERENCE          150
#define KICK_WATCHDOG_TIME            1000
#define WATCHDOG_TIMEOUT              2000
#define BATTERY_CAPACITY_HIGH_TH      95
 
#define DC_LS_RECOVERY_DELAY          500 /* ms */
 
#define DC_IN_CHARGING_STAGE          0
#define DC_NOT_IN_CHARGING_STAGE      (-1)
 
#define DC_IN_CHARGE_DONE_STAGE       0
#define DC_NOT_IN_CHARGE_DONE_STAGE   (-1)
 
#define DC_SET_DISABLE_FLAGS          1
#define DC_CLEAR_DISABLE_FLAGS        0
 
#define BASP_PARA_SCALE               100
#define BASP_RATIO_POLICY_ALL         0 /* apply ratio policy for all segments */
#define BASP_RATIO_POLICY_MAX         1 /* apply ratio policy for max current */
#define BASP_PARA_LEVEL 10
 
#define DC_SC_CUR_LEN                 64
 
#define SC_IN_OUT_VOLT_RATE           2
 
/* basp */
#define BASP_VTERM_DEC_MIN            0
#define BASP_VTERM_DEC_MAX            100 /* mv */
#define BASP_VTERM_DEC_DEFAULT        0
#define BASP_ICHG_RATIO_MIN           70
#define BASP_ICHG_RATIO_MAX           100
#define BASP_ICHG_RATIO_DEFAULT       100
#define BASP_VTERM_DEC_DEFAULT        0
 
#define DC_SINGLEIC_CURRENT_LIMIT     8000
#define DC_MULTI_IC_IBAT_TH           4000
#define DC_CURRENT_OFFSET             300
#define MIN_CURRENT_FOR_MULTI_IC      500
#define LVC_MIN_CURRENT_FOR_MULTI_IC  200
 
/* for charge temp hysteresis */
#define DC_LOW_TEMP_MAX               10
#define DC_HIGH_TEMP_MAX              45

#define DC_TEMP_LEVEL                 5
#define DC_VOLT_LEVEL                 8

#define DC_VSTEP_PARA_LEVEL           4
#define DC_GROUP_MAX                  4
#define DC_TIME_PARA_LEVEL            7

#define DC_VOLT_GROUP_MAX             16
#define DC_TIME_GROUP_MAX             8
#define DC_BAT_BRAND_LEN_MAX          64
#define DC_VOLT_NODE_LEN_MAX          16

enum direct_charge_mode_set {
	AND_SET = 0x0,
	OR_SET = 0x1,
};

/*
 * define stage type with direct charge
 * DC is simplified identifier with direct-charge
 */
enum direct_charge_stage_type {
	DC_STAGE_BEGIN = 0,
	DC_STAGE_DEFAULT = DC_STAGE_BEGIN,
	DC_STAGE_ADAPTER_DETECT,
	DC_STAGE_SWITCH_DETECT,
	DC_STAGE_CHARGE_INIT,
	DC_STAGE_SECURITY_CHECK,
	DC_STAGE_SUCCESS,
	DC_STAGE_CHARGING,
	DC_STAGE_CHARGE_DONE,
	DC_STAGE_END,
};

enum direct_charge_succ_flag {
	DC_SUCCESS,
	DC_ERROR,
};

/*
 * define disable type with direct charge
 * DC is simplified identifier with direct-charge
 */
enum direct_charge_disable_type {
	DC_DISABLE_BEGIN = 0,
	DC_DISABLE_SYS_NODE = DC_DISABLE_BEGIN,
	DC_DISABLE_FATAL_ISC_TYPE,
	DC_DISABLE_WIRELESS_TX,
	DC_DISABLE_BATT_CERTIFICATION_TYPE,
	DC_DISABLE_RSMC, /* rsmc:halifa */
	DC_DISABLE_END,
};

/*
 * define temprature threshold with maximum current
 * support up to 5 parameters list on dts
 */
enum direct_charge_temp_info {
	DC_TEMP_MIN = 0,
	DC_TEMP_MAX,
	DC_TEMP_CUR_MAX,
	DC_TEMP_TOTAL,
};

enum dc_iin_thermal_channel_type {
	DC_CHANNEL_TYPE_BEGIN = 0,
	DC_SINGLE_CHANNEL = DC_CHANNEL_TYPE_BEGIN,
	DC_DUAL_CHANNEL,
	DC_CHANNEL_TYPE_END,
};

enum direct_charge_vstep_info {
	DC_VSTEP_INFO_CURR_GAP,
	DC_VSTEP_INFO_VSTEP,
	DC_VSTEP_INFO_MAX,
};

enum direct_charge_soc_ibat_th_info {
	DC_SOC_IBAT_TH_SOC,
	DC_SOC_IBAT_TH_IBAT,
	DC_SOC_IBAT_TH_MAX,
};

#endif /* _DIRECT_CHARGE_CONSTANTS_H_ */
