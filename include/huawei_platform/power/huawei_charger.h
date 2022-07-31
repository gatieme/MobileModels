/*
 * drivers/power/huawei_charger.h
 *
 * huawei charger driver
 *
 * Copyright (C) 2012-2015 HUAWEI, Inc.
 * Author: HUAWEI, Inc.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/
#include <linux/version.h>
#include <linux/mutex.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/power_supply.h>
#include <chipset_common/hwpower/adapter/adapter_test.h>
#include <chipset_common/hwpower/charger/charger_common_interface.h>
#include <chipset_common/hwpower/common_module/power_dts.h>
#include <chipset_common/hwpower/common_module/power_dsm.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <chipset_common/hwpower/common_module/power_ui_ne.h>
#include <huawei_platform/power/huawei_charger_common.h>
#include <chipset_common/hwpower/protocol/adapter_protocol.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_scp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_fcp.h>
#include <chipset_common/hwpower/protocol/adapter_protocol_pd.h>
#include <chipset_common/hwpower/hardware_monitor/water_detect.h>
#include <chipset_common/hwpower/charger/charger_event.h>

#if (KERNEL_VERSION(4, 14, 0) > LINUX_VERSION_CODE)
#include <linux/qpnp/qpnp-adc.h>
#endif

#ifndef _HUAWEI_CHARGER
#define _HUAWEI_CHARGER

/* marco define area */
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/*
 * Running test result
 * And charge abnormal info
 */
#define CHARGE_STATUS_FAIL      (0 << 0)  /* Indicate running test charging status fail */
#define CHARGE_STATUS_PASS      (1 << 0)  /* Indicate running test charging status pass */
#define BATTERY_FULL            (1 << 1)
#define USB_NOT_PRESENT         (1 << 2)
#define REGULATOR_BOOST         (1 << 3)
#define CHARGE_LIMIT            (1 << 4)
#define BATTERY_HEALTH          (1 << 5)
#define CHARGER_OVP             (1 << 6)
#define OCP_ABNORML             (1 << 7)
#define BATTERY_VOL_ABNORML     (1 << 8)
#define BATTERY_TEMP_ABNORML    (1 << 9)
#define BATTERY_ABSENT          (1 << 10)

#define CHARGE_OCP_THR          (-4500000)    /* charge current abnormal threshold */
#define BATTERY_OCP_THR         6000000     /* discharge current abnormal threshold */
#define BATTERY_VOL_THR_HI      4500000     /* battery voltage abnormal high threshold */
#define BATTERY_VOL_THR_LO      2500000     /* battery voltage abnormal low threshold */
#define BATTERY_TEMP_HI         780         /* battery high temp threshold */
#define BATTERY_TEMP_LO         (-100)        /* battery low temp threshold */
#define WARM_VOL_BUFFER         100         /* warm_bat_mv need have a 100mV buffer */
#define WARM_TEMP_THR           390 /* battery warm temp threshold for running test */
#define HOT_TEMP_THR            600 /* battery overheat threshold for running test */
#define BATT_FULL               100         /* battery full capactiy */
#define COLD_HOT_TEMP_BUFFER    200         /* temp buffer */
#define PASS_MASK               0x1E        /* Running test pass mask */
#define FAIL_MASK               0x7E0       /* Running test fail mask */
#define WARM_VOL_THR            4100    /* battery regulation voltage in mV when warm */
#define HOT_TEMP                650     /* battery hot temp threshold */
#define COLD_TEMP               0       /* battery cold temp threshold */

#define MAX_SIZE                1024

#define SMB_START_CHARGING      0x40
#define SMB_STOP_CHARGING       0x60
#define QPNP_SMBCHARGER_TIMEOUT 30000

#define THERMAL_REASON_SIZE     16
#define ERR_NO_STRING_SIZE      256
#define EOC_DISABLE             FALSE

#define NO_EVENT                (-1)

/* 0: dbc close charger, 1: dbc open charger, 2: dbc not control charger */
#define CHARGER_NOT_DBC_CONTROL             2

/* options of NTC battery temperature */
#define BATTERY_TEMPERATURE_MIN             (-32767)
#define BATTERY_TEMPERATURE_MAX             32767
#define BATTERY_TEMPERATURE_0_C             0
#define BATTERY_TEMPERATURE_5_C             5

#define CHARGER_SET_DISABLE_FLAGS           1

#define MIN_CHARGING_CURRENT_OFFSET         (-10)
#define BATTERY_FULL_CHECK_TIMIES           2
#define CHARGER_SET_DISABLE_FLAGS           1
#define CHARGER_CLEAR_DISABLE_FLAGS         0

/* charge threshold */
#define NO_CHG_TEMP_LOW                     0
#define NO_CHG_TEMP_HIGH                    50
#define BATT_EXIST_TEMP_LOW                 (-40)
#define DEFAULT_NORMAL_TEMP                 25


#define FFC_VTERM_START_FLAG                BIT(0)
#define FFC_VETRM_END_FLAG                  BIT(1)

enum battery_event_type {
	BATTERY_EVENT_HEALTH,
	BATTERY_EVETN_MAX,
};

enum charge_sysfs_type {
	CHARGE_SYSFS_IIN_THERMAL = 0,
	CHARGE_SYSFS_IIN_RUNNINGTEST,
	CHARGE_SYSFS_IIN_RT_CURRENT,
	CHARGE_SYSFS_ENABLE_CHARGER,
	CHARGE_SYSFS_FACTORY_DIAG_CHARGER,
	CHARGE_SYSFS_RUNNING_TEST_STATUS,
	CHARGE_SYSFS_UPDATE_VOLT_NOW,
	CHARGE_SYSFS_IBUS,
	CHARGE_SYSFS_VBUS,
	CHARGE_SYSFS_HIZ,
	CHARGE_SYSFS_CHARGE_TYPE,
	CHARGE_SYSFS_CHARGE_TERM_VOLT_DESIGN,
	CHARGE_SYSFS_CHARGE_TERM_CURR_DESIGN,
	CHARGE_SYSFS_CHARGE_TERM_VOLT_SETTING,
	CHARGE_SYSFS_CHARGE_TERM_CURR_SETTING,
	CHARGE_SYSFS_DBC_CHARGE_CONTROL,
	CHARGE_SYSFS_DBC_CHARGE_DONE,
	CHARGE_SYSFS_ADAPTOR_TEST,
	CHARGE_SYSFS_ADAPTOR_VOLTAGE,
	CHARGE_SYSFS_REGULATION_VOLTAGE,
	CHARGE_SYSFS_PLUGUSB,
	CHARGE_SYSFS_THERMAL_REASON,
	CHARGE_SYSFS_VTERM_DEC,
	CHARGE_SYSFS_ICHG_RATIO,
	CHARGE_SYSFS_CHARGER_ONLINE,
	CHARGE_SYSFS_WATCHDOG_DISABLE,
};

enum iin_thermal_charge_type {
	IIN_THERMAL_CHARGE_TYPE_BEGIN = 0,
	IIN_THERMAL_WCURRENT_5V = IIN_THERMAL_CHARGE_TYPE_BEGIN,
	IIN_THERMAL_WCURRENT_9V,
	IIN_THERMAL_WLCURRENT_5V,
	IIN_THERMAL_WLCURRENT_9V,
	IIN_THERMAL_CHARGE_TYPE_END,
};

enum charge_fault_type {
	CHARGE_FAULT_NON = 0,
	CHARGE_FAULT_BOOST_OCP,
	CHARGE_FAULT_VBAT_OVP,
	CHARGE_FAULT_SCHARGER,
	CHARGE_FAULT_I2C_ERR,
	CHARGE_FAULT_WEAKSOURCE,
	CHARGE_FAULT_CHARGE_DONE,
	CHARGE_FAULT_TOTAL,
};

#define CHIP_RESP_TIME	                200
#define FCP_DETECT_DELAY_IN_POWEROFF_CHARGE 2000
#define VBUS_VOL_READ_CNT               3
#define COOL_LIMIT                      11
#define WARM_LIMIT                      44
#define WARM_CUR_RATIO                  35
#define RATIO_BASE      100
#define IBIS_RATIO      120

#define VBUS_VOLTAGE_ABNORMAL_MAX_COUNT   2

enum disable_charger_type {
	CHARGER_SYS_NODE = 0,
	CHARGER_FATAL_ISC_TYPE,
	CHARGER_WIRELESS_TX,
	BATT_CERTIFICATION_TYPE,
	__MAX_DISABLE_CHAGER,
};

struct charge_iin_regl_lut {
	int total_stage;
	int *iin_regl_para;
};

/* detected type-c protocol current when as a slave and in charge */
enum typec_input_current {
	TYPEC_DEV_CURRENT_DEFAULT = 0,
	TYPEC_DEV_CURRENT_MID,
	TYPEC_DEV_CURRENT_HIGH,
	TYPEC_DEV_CURRENT_NOT_READY,
};

enum hisi_charger_type {
	CHARGER_TYPE_SDP = 0,   /* Standard Downstreame Port */
	CHARGER_TYPE_CDP,       /* Charging Downstreame Port */
	CHARGER_TYPE_DCP,       /* Dedicate Charging Port */
	CHARGER_TYPE_UNKNOWN,   /* non-standard */
	CHARGER_TYPE_NONE,      /* not connected */

	/* other messages */
	PLEASE_PROVIDE_POWER,   /* host mode, provide power */
	CHARGER_TYPE_ILLEGAL,   /* illegal type */
};

struct charge_sysfs_data {
	int iin_rt;
	int iin_rt_curr;
	int hiz_mode;
	int ibus;
	int vbus;
	int inputcurrent;
	int voltage_sys;
	unsigned int adc_conv_rate;
	unsigned int iin_thl;
	unsigned int iin_thl_array[IIN_THERMAL_CHARGE_TYPE_END];
	unsigned int ichg_thl;
	unsigned int ichg_rt;
	unsigned int vterm_rt;
	unsigned int charge_limit;
	unsigned int wdt_disable;
	unsigned int charge_enable;
	unsigned int fcp_charge_enable;
	unsigned int disable_charger[__MAX_DISABLE_CHAGER];
	unsigned int batfet_disable;
	unsigned int vr_charger_type;
	unsigned int dbc_charge_control;
	unsigned int support_ico;
	unsigned int water_intrused;
	int charge_done_status;
	int charge_done_sleep_status;
	int vterm;
	int iterm;
	int charger_cvcal_value;
	int charger_cvcal_clear;
	int charger_get_cvset;
};

struct ico_input {
	unsigned int charger_type;
	unsigned int iin_max;
	unsigned int ichg_max;
	unsigned int vterm;
};

struct ico_output {
	unsigned int input_current;
	unsigned int charge_current;
};

struct charge_device_ops {
	int (*chip_init)(struct charge_init_data *init_crit);
	int (*set_adc_conv_rate)(int rate_mode);
	int (*set_input_current)(int value);
	void (*set_input_current_thermal)(int val1, int val2);
	int (*set_charge_current)(int value);
	void (*set_charge_current_thermal)(int val1, int val2);
	int (*dev_check)(void);
	int (*set_terminal_voltage)(int value);
	int (*set_dpm_voltage)(int value);
	int (*set_terminal_current)(int value);
	int (*set_charge_enable)(int enable);
	int (*get_charge_enable_status)(void);
	int (*set_otg_enable)(int enable);
	int (*set_term_enable)(int enable);
	int (*get_charge_state)(unsigned int *state);
	int (*reset_watchdog_timer)(void);
	int (*set_watchdog_timer)(int value);
	int (*set_batfet_disable)(int disable);
	int (*get_ibus)(void);
	int (*get_vbus)(unsigned int *value);
	int (*check_charger_plugged)(void);
	int (*check_input_dpm_state)(void);
	int (*check_input_vdpm_state)(void);
	int (*check_input_idpm_state)(void);
	int (*set_covn_start)(int enable);
	int (*set_charger_hiz)(int enable);
	int (*set_otg_current)(int value);
	int (*stop_charge_config)(void);
	int (*set_otg_switch_mode_enable)(int enable);
	int (*get_vbat_sys)(void);
	int (*set_vbus_vset)(u32);
	int (*set_mivr)(u32);
	int (*set_uvp_ovp)(void);
	int (*turn_on_ico)(struct ico_input *, struct ico_output *);
	int (*set_force_term_enable)(int enable);
	int (*get_charger_state)(void);
	int (*soft_vbatt_ovp_protect)(void);
	int (*rboost_buck_limit)(void);
	int (*get_charge_current)(void);
	int (*get_iin_set)(void);
	int (*set_boost_voltage)(int voltage);
	int (*get_dieid)(char *dieid, unsigned int len);
	int (*get_vbat)(void);
	int (*get_terminal_voltage)(void);
	int (*get_vusb)(int *value);
	int (*set_pretrim_code)(int val);
	int (*get_dieid_for_nv)(u8 *dieid, unsigned int len);
	/* charger type detection */
	int (*enable_chg_type_det)(bool en);
};

struct charge_core_data;

struct charge_device_info {
	struct device *dev;
	struct notifier_block usb_nb;
	struct notifier_block fault_nb;
	struct notifier_block typec_nb;
	struct delayed_work charge_work;
	struct delayed_work plugout_uscp_work;
	struct delayed_work pd_voltage_change_work;
	struct work_struct usb_work;
	struct work_struct fault_work;
	struct charge_sysfs_data sysfs_data;
	struct charge_device_ops *ops;
	struct charge_core_data *core_data;
	struct hrtimer timer;
	struct mutex mutex_hiz;
#ifdef CONFIG_TCPC_CLASS
	struct notifier_block tcpc_nb;
	struct tcpc_device *tcpc;
	unsigned int tcpc_otg;
	struct mutex tcpc_otg_lock;
	struct pd_dpm_vbus_state *vbus_state;
#endif
	unsigned int pd_input_current;
	unsigned int pd_charge_current;
	enum typec_input_current typec_current_mode;
	unsigned int charge_fault;
	unsigned int charge_enable;
	unsigned int input_current;
	unsigned int charge_current;
	unsigned int input_typec_current;
	unsigned int charge_typec_current;
	unsigned int enable_current_full;
	unsigned int check_current_full_count;
	unsigned int check_full_count;
	unsigned int start_attemp_ico;
	unsigned int support_standard_ico;
	unsigned int ico_current_mode;
	unsigned int ico_all_the_way;
	unsigned int fcp_vindpm;
	unsigned int hiz_ref;
	unsigned int check_ibias_sleep_time;
	unsigned int need_filter_pd_event;
	unsigned int boost_5v_enable;
	u32 force_disable_dc_path;
	u32 scp_adp_normal_chg;
	u32 startup_iin_limit;
	u32 hota_iin_limit;
#ifdef CONFIG_DIRECT_CHARGER
	int support_scp_power;
#endif
	struct spmi_device *spmi;
	struct power_supply *usb_psy;
	struct power_supply *pc_port_psy;
	struct power_supply *batt_psy;
	struct power_supply *chg_psy;
	struct power_supply *bms_psy;
	struct power_supply *bk_batt_psy;
	int chrg_config;
	int factory_diag;
	unsigned int input_event;
	unsigned long event;
	struct delayed_work smb_charger_work;
	int fcp_test_delay;
	struct notifier_block nb;
	int weaksource_cnt;
	struct mutex event_type_lock;
	unsigned int charge_done_maintain_fcp;
	unsigned int term_exceed_time;
	struct work_struct event_work;
	spinlock_t event_spin_lock;
	struct charger_event_queue event_queue;
	unsigned int clear_water_intrused_flag_after_read;
	char thermal_reason[THERMAL_REASON_SIZE];
	int avg_iin_ma;
	int max_iin_ma;
	int current_full_status;
#ifdef CONFIG_HUAWEI_YCABLE
	struct notifier_block ycable_nb;
#endif
#ifdef CONFIG_POGO_PIN
	struct notifier_block pogopin_nb;
#endif
	int iin_regulation_enabled;
	int iin_regl_interval;
	int iin_now;
	int iin_target;
	struct mutex iin_regl_lock;
	struct charge_iin_regl_lut iin_regl_lut;
	struct delayed_work iin_regl_work;
	u32 increase_term_volt_en;
	int en_eoc_max_delay;
	u32 smart_charge_support;
	bool is_dc_enable_hiz;
	u32 ffc_vterm_flag;
	u32 pd_cur_trans_ratio;
};

#ifdef CONFIG_DIRECT_CHARGER
void wired_connect_send_icon_uevent(int icon_type);
void wired_disconnect_send_icon_uevent(void);
#endif

extern int is_usb_ovp(void);
extern  int huawei_handle_charger_event(unsigned long event);
int battery_health_handler(void);
void cap_learning_event_done_notify(void);

struct pd_dpm_vbus_state;

#ifdef CONFIG_HUAWEI_CHARGER
struct charge_device_info *get_charger_device_info(void);
int adaptor_cfg_for_wltx_vbus(int vol, int cur);
void charge_set_adapter_voltage(int val,
	unsigned int type, unsigned int delay_time);
int charge_otg_mode_enable(int enable, unsigned int user);
int huawei_charger_get_charge_enable(int *val);
void huawei_charger_update_iin_thermal(void);
int huawei_charger_set_ichg_jeita_limit(unsigned int value);
int huawei_charger_set_vterm_jeita_limit(unsigned int value);
void huawei_charger_set_fcp_current_limit(unsigned int value);
void fcp_charge_entry(void);
#else
static inline struct charge_device_info *get_charger_device_info(void)
{
	return NULL;
}

static inline int adaptor_cfg_for_wltx_vbus(int vol, int cur)
{
	return 0;
}

static inline void charge_set_adapter_voltage(int val,
	unsigned int type, unsigned int delay_time)
{
}

static inline int charge_otg_mode_enable(int enable, unsigned int user)
{
	return 0;
}

static inline int huawei_charger_get_charge_enable(int *val)
{
	return 0;
}

static inline void huawei_charger_update_iin_thermal(void)
{
}

static inline int huawei_charger_set_ichg_jeita_limit(unsigned int value)
{
	return 0;
}

static inline int huawei_charger_set_vterm_jeita_limit(unsigned int value)
{
	return 0;
}

static inline void fcp_charge_entry(void)
{
}

static inline void huawei_charger_set_fcp_current_limit(unsigned int value)
{
}
#endif /* CONFIG_HUAWEI_CHARGER */

#ifdef CONFIG_HUAWEI_BUCK_CHARGER
int charge_ops_register(struct charge_device_ops *ops);
int charge_set_hiz_enable_by_direct_charge(int enable);
int charger_set_hiz(int enable);
void buck_charge_init_chip(void);
void buck_charge_stop_charging(void);
void buck_charge_entry(void);
void buck_charge_set_pd_vbus_state(struct pd_dpm_vbus_state *vbus_state);
bool charge_support_thirdparty_buck(void);
int buck_sysfs_set_dcp_enable_charger(int val);
int buck_sysfs_set_dcp_iin_thermal_array(unsigned int idx, unsigned int val);
int charge_get_iin_set(void);
int charge_set_dev_iin(int iin);
#else
static inline int charge_ops_register(struct charge_device_ops *ops)
{
	return -EPERM;
}

static inline int charge_set_hiz_enable_by_direct_charge(int enable)
{
	return -EPERM;
}

static inline int charger_set_hiz(int enable)
{
	return -EPERM;
}

static inline void buck_charge_init_chip(void)
{
}

static inline void buck_charge_stop_charging(void)
{
}

static inline void buck_charge_entry(void)
{
}

static inline void buck_charge_set_pd_vbus_state(struct pd_dpm_vbus_state *vbus_state)
{
}

static inline bool charge_support_thirdparty_buck(void)
{
	return false;
}

static inline int buck_sysfs_set_dcp_enable_charger(int val)
{
	return -EINVAL;
}

static inline int buck_sysfs_set_dcp_iin_thermal_array(unsigned int idx, unsigned int val)
{
	return -EINVAL;
}

static inline int charge_get_iin_set(void)
{
	return -EINVAL;
}

static inline int charge_set_dev_iin(int iin)
{
	return -EINVAL;
}
#endif

int get_first_insert(void);
void set_first_insert(int flag);
int get_eoc_max_delay_count(void);
#endif
