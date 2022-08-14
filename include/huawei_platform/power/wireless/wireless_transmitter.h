/*
 * wireless_transmitter.h
 *
 * wireless reverse charging driver
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd.
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

#ifndef _WIRELESS_TRANSMITTER_H_
#define _WIRELESS_TRANSMITTER_H_

#include <linux/power/huawei_charger.h>
#include <huawei_platform/power/hw_accessory.h>
#include <huawei_platform/power/wireless/wireless_charger.h>
#include <chipset_common/hwpower/battery_temp.h>
#include <huawei_platform/power/wireless/wireless_tx_pwr_src.h>
#include <huawei_platform/power/wireless/wireless_tx_pwr_ctrl.h>
#include <huawei_platform/power/wireless/wireless_tx_vset.h>
#include <huawei_platform/power/wireless/wireless_tx_cap.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_alarm.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_fod.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_chrg_curve.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_protection.h>
#include <chipset_common/hwpower/wireless_charge/wireless_tx_volt_check.h>

#define WL_TX_FAIL                       (-1)
#define WL_TX_SUCC                       0
#define WL_TX_MONITOR_INTERVAL           300
#define WL_TX_MONITOR_INTERVAL_MAX       3000

#define WL_TX_SOC_MIN                    20
#define WL_TX_BATT_TEMP_MAX              50
#define WL_TX_TBATT_DELTA_TH             15
#define WL_TX_BATT_TEMP_MIN              (-10)
#define WL_TX_BATT_TEMP_RESTORE          35
#define WL_TX_STR_LEN_16                 16
#define WL_TX_STR_LEN_32                 32

/* high power cfg */
#define WL_TX_HI_PWR_SOC_MIN             90
#define WL_TX_HI_PWR_SOC_BACK            5
#define WL_TX_HI_PWR_TBATT_MAX           37
#define WL_TX_HI_PWR_BP2CP_TBATT_MAX     42
#define WLTX_HI_PWR_TIME                 300000 /* 5min: 5*60*1000 */
#define WLTX_HI_PWR_HS_TIME              15000 /* 15s, handshake time */
#define WLTX_HI_PWR_ILIM                 1150
#define WLTX_RX_HIGH_VOUT                7000
#define WLTX_BP2CP_PWR_ILIM              1350
#define WLTX_ABNORMAL_IBAT               5500
#define WLTX_BP2CP_ABNORMAL_IBAT         8000

#define WLTX_IRQ_VSET_TIME               5000 /* 5s */

#define WL_TX_VIN_RETRY_CNT1             10
#define WL_TX_VIN_RETRY_CNT2             250
#define WL_TX_VIN_SLEEP_TIME             20
#define WL_TX_IIN_SAMPLE_LEN             10
#define WL_TX_FOP_SAMPLE_LEN             10
#define WL_TX_PING_TIMEOUT_1             120
#define WL_TX_PING_TIMEOUT_2             119
#define WL_TX_PING_CHECK_INTERVAL        20
#define WL_TX_PING_VIN_OVP_CNT           3
#define WL_TX_PING_VIN_UVP_CNT           10 /* 6s-10s */
#define WL_TX_I2C_ERR_CNT                5
#define WL_TX_IIN_LOW                    300 /* mA */
#define WL_TX_IIN_LOW_CNT                1800000 /* 30min: 30*60*1000 */
#define WL_TX_MODE_ERR_CNT               10
#define WL_TX_MODE_ERR_CNT1              3
#define WL_TX_MODE_ERR_CNT2              20
#define WL_TX_5VBST_MIN_FOP              138 /* kHz */

#define WL_TX_MONITOR_LOG_INTERVAL       3000
#define WL_TX_CHARGER_TYPE_MAX           12
#define WL_TX_OPEN_STATUS                2 /* 0:close, 1:open */

#define WL_TX_DMDLOG_SIZE                512
#define WL_TX_ACC_DEV_MAC_LEN            6
#define WL_TX_ACC_DEV_MODELID_LEN        3
#define WL_TX_ACC_DEV_SUBMODELID_LEN     1
#define WL_TX_ACC_DEV_VERSION_LEN        1
#define WL_TX_ACC_DEV_BUSINESS_LEN       1
#define WL_TX_ACC_DEV_INFO_CNT           12

#define WLTX_FULL_BRIDGE_RX_PWR_TH       30 /* 3w */

/* rp demodulation timeout cfg */
#define WLTX_RP_DEMODULE_TIMEOUT_VAL     60

/* type must be increased one by one from 0 */
enum wltx_open_type {
	WLTX_OPEN_TYPE_BEGIN = 0,
	WLTX_OPEN_BY_CLIENT = WLTX_OPEN_TYPE_BEGIN, /* client:0, dont move */
	WLTX_OPEN_BY_HALL,
	WLTX_OPEN_BY_COIL_TEST,
	WLTX_OPEN_BY_LIGHTSTARP,
	WLTX_OPEN_TYPE_END,
};

enum wireless_tx_acc_info_index {
	WL_TX_ACC_INFO_BEGIN = 0,
	WL_TX_ACC_INFO_NO = WL_TX_ACC_INFO_BEGIN,
	WL_TX_ACC_INFO_STATE,
	WL_TX_ACC_INFO_MAC,
	WL_TX_ACC_INFO_MODEL_ID,
	WL_TX_ACC_INFO_SUBMODEL_ID,
	WL_TX_ACC_INFO_VERSION,
	WL_TX_ACC_INFO_BUSINESS,
	WL_TX_ACC_INFO_MAX,
};

enum wireless_tx_status_type {
	/* tx normal status */
	WL_TX_STATUS_DEFAULT = 0x00,    /* default */
	WL_TX_STATUS_PING,              /* TX ping RX */
	WL_TX_STATUS_PING_SUCC,         /* ping success */
	WL_TX_STATUS_IN_CHARGING,       /* in reverse charging status */
	WL_TX_STATUS_CHARGE_DONE,       /* RX charge done */
	/* tx error status */
	WL_TX_STATUS_FAULT_BASE = 0x10, /* base */
	WL_TX_STATUS_TX_CLOSE,          /* chip fault or user close TX mode */
	WL_TX_STATUS_RX_DISCONNECT,     /* monitor RX disconnect */
	WL_TX_STATUS_PING_TIMEOUT,      /* can not ping RX */
	WL_TX_STATUS_TBATT_LOW,         /* battery temperature too low */
	WL_TX_STATUS_TBATT_HIGH,        /* battery temperature too high */
	WL_TX_STATUS_IN_WL_CHARGING,    /* in wireless charging */
	WL_TX_STATUS_SOC_ERROR,         /* capacity is too low */
	WL_TX_STATUS_TX_INIT,           /* tx init by wdt reset */
	WL_TX_STATUS_TBATT_LIMIT_POWER, /* limit power by battery temperature */
};

enum wireless_tx_sysfs_type {
	WL_TX_SYSFS_TX_OPEN = 0,
	WL_TX_SYSFS_TX_STATUS,
	WL_TX_SYSFS_TX_IIN_AVG,
	WL_TX_SYSFS_DPING_FREQ,
	WL_TX_SYSFS_DPING_INTERVAL,
	WL_TX_SYSFS_MAX_FOP,
	WL_TX_SYSFS_MIN_FOP,
	WL_TX_SYSFS_TX_FOP,
	WL_TX_SYSFS_HANDSHAKE,
	WL_TX_SYSFS_CHK_TRXCOIL,
	WL_TX_SYSFS_TX_VIN,
	WL_TX_SYSFS_TX_IIN,
	WL_TX_SYSFS_LOG_INTERVAL,
};

enum wltx_acc_dev_state {
	WL_ACC_DEV_STATE_BEGIN = 0,
	WL_ACC_DEV_STATE_OFFLINE = WL_ACC_DEV_STATE_BEGIN,
	WL_ACC_DEV_STATE_ONLINE,
	WL_ACC_DEV_STATE_PING_SUCC,
	WL_ACC_DEV_STATE_END,
};

struct wireless_tx_device_ops {
	void (*pre_ps)(bool);
	int (*chip_reset)(void);
	void (*rx_enable)(int);
	void (*rx_sleep_enable)(int);
	int (*check_fwupdate)(enum wireless_mode);
	int (*kick_watchdog)(void);
	int (*tx_chip_init)(enum wltx_open_type);
	int (*tx_stop_config)(void);
	int (*enable_tx_mode)(bool);
	int (*get_tx_iin)(u16 *);
	int (*get_tx_vin)(u16 *);
	int (*get_tx_vrect)(u16 *);
	int (*get_chip_temp)(u8 *);
	int (*get_tx_fop)(u16 *);
	int (*get_duty)(u8 *);
	int (*get_cep)(u8 *);
	int (*get_ptx)(u32 *);
	int (*get_prx)(u32 *);
	int (*get_ploss)(s32 *);
	int (*get_ploss_id)(u8 *);
	int (*set_tx_ilimit)(int);
	int (*set_tx_max_fop)(u16);
	int (*get_tx_max_fop)(u16 *);
	int (*set_tx_min_fop)(u16);
	int (*get_tx_min_fop)(u16 *);
	int (*set_tx_ping_frequency)(u16);
	int (*get_tx_ping_frequency)(u16 *);
	int (*set_tx_ping_interval)(u16);
	int (*get_tx_ping_interval)(u16 *);
	bool (*check_rx_disconnect)(void);
	bool (*in_tx_mode)(void);
	bool (*in_rx_mode)(void);
	void (*set_tx_open_flag)(bool);
	int (*set_tx_fod_coef)(u32, u8);
	void (*set_rp_dm_timeout_val)(u8);
	void (*activate_tx_chip)(void);
	int (*set_bridge)(int, enum wltx_bridge_type);
	int (*get_full_bridge_ith)(void);
};

struct wltx_logic_ops {
	enum wltx_open_type type;
	bool (*can_rev_charge_check)(void);
};

struct wltx_acc_dev {
	u8 dev_state;
	u8 dev_no;
	u8 dev_mac[WL_TX_ACC_DEV_MAC_LEN];
	u8 dev_model_id[WL_TX_ACC_DEV_MODELID_LEN];
	u8 dev_submodel_id;
	u8 dev_version;
	u8 dev_business;
	u8 dev_info_cnt;
};

struct wltx_get_rx_private_data {
	u8 product_type;
	u16 pmax;
};

struct wltx_log_data {
	u8 temp;
	u8 duty;
	u8 ploss_id;
	u8 cep;
	u16 iin;
	u16 iin_avg;
	u16 vin;
	u16 vrect;
	u16 fop;
	u16 fop_avg;
	u32 ptx;
	u32 prx;
	s32 ploss;
	int soc;
	int tbatt;
};

struct wireless_tx_device_info {
	struct device *dev;
	struct notifier_block tx_event_nb;
	struct work_struct wireless_tx_check_work;
	struct work_struct wireless_tx_evt_work;
	struct delayed_work wireless_tx_monitor_work;
	struct wireless_tx_device_ops *tx_ops;
	struct wltx_logic_ops *logic_ops;
	struct wltx_vset_para tx_vset;
	struct wltx_vout_para tx_vout;
	struct wltx_cap_data tx_cap;
	struct wltx_get_rx_private_data rx_data;
	struct wltx_cc_cfg cc_cfg;
	struct wltx_protect_cfg protect_cfg;
	struct wltx_fod_cfg fod_cfg;
	struct wltx_high_vctrl_data high_vctrl;
	enum wltx_open_type tx_open_type;
	enum wltx_pwr_type pwr_type;
	enum wltx_pwr_src cur_pwr_src;
	enum wltx_pwr_sw_scene cur_pwr_sw_scn;
	unsigned int tx_vset_tbat_high;
	unsigned int tx_vset_tbat_low;
	unsigned int tx_high_pwr_soc;
	unsigned int tx_dc_done_buck_ilim;
	unsigned int tx_high_pwr_ilim;
	unsigned int ps_need_ext_pwr;
	unsigned int monitor_interval;
	unsigned int ping_timeout;
	unsigned int tx_event_type;
	unsigned int tx_event_data;
	unsigned int tx_iin_avg;
	unsigned int tx_fop_avg;
	unsigned int i2c_err_cnt;
	unsigned int tx_mode_err_cnt;
	unsigned int tx_iin_low_cnt;
	unsigned long hs_time_out; /* hs: handshake */
	unsigned long hp_time_out; /* hp: high power */
	unsigned long irq_vset_time_out;
	unsigned int tx_rp_timeout_lim_volt;
	bool tx_pd_flag; /* tx power down by itself */
	bool standard_rx;
	bool stop_reverse_charge; /* record driver state */
	int gpio_tx_boost_en;
	struct qi_protocol_acc_device_info *wireless_tx_acc;
	int log_interval;
	int limit_power_flag;
};

extern int wireless_tx_ops_register(struct wireless_tx_device_ops *ops);
extern void wireless_get_qi_charge_done_type(u8 data);
#ifdef CONFIG_WIRELESS_CHARGER
struct wireless_tx_device_info *wltx_get_dev_info(void);
bool wltx_is_tx_open_by_hall(void);
int wltx_msleep(int sleep_ms);
bool wireless_is_in_tx_mode(void);
bool wireless_tx_get_tx_open_flag(void);
int wireless_tx_logic_ops_register(struct wltx_logic_ops *ops);
void wltx_reset_reverse_charging(void);
void wltx_open_tx(enum wltx_open_type type, bool enable);
void wltx_cancle_work_handler(void);
void wltx_restart_work_handler(void);
void wireless_tx_set_tx_status(enum wireless_tx_status_type event);
int wltx_get_tx_iin(u16 *tx_iin);
enum wltx_stage wireless_tx_get_stage(void);
void wltx_ps_get_tx_vin(u16 *vin);
void wltx_activate_tx_chip(void);
void wireless_tx_set_tx_open_flag(bool enable);
int wltx_ic_get_duty(u8 *duty);
int wltx_ic_get_cep(u8 *cep);
int wltx_ic_get_ptx(u32 *ptx);
int wltx_ic_get_prx(u32 *prx);
int wltx_ic_get_ploss(s32 *ploss);
int wltx_ic_get_ploss_id(u8 *id);
#else
static inline struct wireless_tx_device_info *wltx_get_dev_info(void)
{
	return NULL;
}

static inline bool wltx_is_tx_open_by_hall(void)
{
	return false;
}

static inline int wltx_msleep(int sleep_ms)
{
	return 0;
}

static inline bool wireless_is_in_tx_mode(void)
{
	return false;
}

static inline bool wireless_tx_get_tx_open_flag(void)
{
	return false;
}

static inline int wireless_tx_logic_ops_register(struct wltx_logic_ops *ops)
{
	return 0;
}
static inline int wltx_get_tx_iin(u16 *tx_iin)
{
	return 0;
}

static inline int wltx_ic_get_duty(u8 *duty)
{
	return -1;
}

static inline int wltx_ic_get_cep(u8 *cep)
{
	return -1;
}

static inline int wltx_ic_get_ptx(u32 *ptx)
{
	return -1;
}

static inline int wltx_ic_get_prx(u32 *prx)
{
	return -1;
}

static inline int wltx_ic_get_ploss(s32 *ploss)
{
	return -1;
}

static inline int wltx_ic_get_ploss_id(u8 *id)
{
	return -1;
}

static inline void wltx_reset_reverse_charging(void) {}
static inline void wltx_open_tx(enum wltx_open_type type, bool enable) {}
static inline void wltx_cancle_work_handler(void) {}
static inline void wltx_restart_work_handler(void) {}
static inline void wireless_tx_set_tx_status(enum wireless_tx_status_type event) {}
static inline void wltx_ps_get_tx_vin(u16 *vin) {};
static inline void wltx_activate_tx_chip(void) {};
static inline void wireless_tx_set_tx_open_flag(bool enable) {};
#endif /* CONFIG_WIRELESS_CHARGER */

#endif /* _WIRELESS_TRANSMITTER_H_ */
