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

/* options of NTC battery temperature */
#define BATTERY_TEMPERATURE_MIN             (-32767)
#define BATTERY_TEMPERATURE_MAX             32767
#define BATTERY_TEMPERATURE_0_C             0
#define BATTERY_TEMPERATURE_5_C             5

#define CHARGER_SET_DISABLE_FLAGS           1

#define MIN_CHARGING_CURRENT_OFFSET         (-20)
#define BATTERY_FULL_CHECK_TIMIES           2
#define CHARGER_SET_DISABLE_FLAGS           1
#define CHARGER_CLEAR_DISABLE_FLAGS         0

/* charge threshold */
#define NO_CHG_TEMP_LOW                     0
#define NO_CHG_TEMP_HIGH                    50
#define BATT_EXIST_TEMP_LOW                 (-40)
#define DEFAULT_NORMAL_TEMP                 25

#define DEFAULT_FCP_TEST_DELAY              6000
#define FCP_READ_DELAY                      100

enum battery_event_type {
	BATTERY_EVENT_HEALTH,
	BATTERY_EVETN_MAX,
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
	unsigned int input_event;
	unsigned long event;
	struct delayed_work smb_charger_work;
	int fcp_test_delay;
	struct notifier_block nb;
	int weaksource_cnt;
	struct mutex event_type_lock;
	unsigned int charge_done_maintain_fcp;
	unsigned int term_exceed_time;
	unsigned int clear_water_intrused_flag_after_read;
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
	u32 pd_cur_trans_ratio;
	u32 vterm_dec;
	int release_lock_support;
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
int huawei_charger_get_charge_enable(int *val);
void huawei_charger_update_iin_thermal(void);
void huawei_charger_set_fcp_current_limit(unsigned int value);
void huawei_charger_set_rsmc_limit(int val);
void huawei_charger_set_dc_disable_flags(bool disable, int type);
bool huawei_charger_in_dc_path(void);
int huawei_charger_get_ibus(void);
int huawei_charger_get_vterm_dec(unsigned int *value);
void fcp_charge_entry(void);
int huawei_charger_get_iin_thermal_charge_type(void);
bool huawei_charger_get_dc_enable_hiz_status(void);
unsigned int huawei_charger_get_hota_iin_limit(void);
unsigned int huawei_charger_get_startup_iin_limit(void);
#else
static inline struct charge_device_info *get_charger_device_info(void)
{
	return NULL;
}

static inline int adaptor_cfg_for_wltx_vbus(int vol, int cur)
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

static inline void huawei_charger_set_rsmc_limit(int val)
{
}

static inline void huawei_charger_set_dc_disable_flags(bool disable, int type)
{
}

static inline bool huawei_charger_in_dc_path(void)
{
	return false;
}

static inline int huawei_charger_get_ibus(void)
{
	return 0;
}

static inline int huawei_charger_get_vterm_dec(unsigned int *value)
{
	return 0;
}

static inline void fcp_charge_entry(void)
{
}

static inline void huawei_charger_set_fcp_current_limit(unsigned int value)
{
}

static inline int huawei_charger_get_iin_thermal_charge_type(void)
{
	return 0;
}

static inline bool huawei_charger_get_dc_enable_hiz_status(void)
{
	return false;
}

static inline unsigned int huawei_charger_get_hota_iin_limit(void)
{
	return 0;
}

static inline unsigned int huawei_charger_get_startup_iin_limit(void)
{
	return 0;
}
#endif /* CONFIG_HUAWEI_CHARGER */

#ifdef CONFIG_HUAWEI_BUCK_CHARGER
int charge_set_hiz_enable_by_direct_charge(int enable);
void buck_charge_init_chip(void);
void buck_charge_stop_charging(void);
void buck_charge_entry(void);
void buck_charge_set_pd_vbus_state(struct pd_dpm_vbus_state *vbus_state);
bool charge_support_thirdparty_buck(void);
int buck_sysfs_set_dcp_enable_charger(int val);
int buck_sysfs_set_dcp_iin_thermal_array(unsigned int idx, unsigned int val);
int charge_set_input_current_max(void);
int charge_get_input_current_max(void);
int charge_set_input_current(int iin);
int charge_set_iin_rt_curr(int iin_rt_curr);
int get_charge_done_type(void);
void buck_charge_update_iterm(int iterm);
#else
static inline int charge_set_hiz_enable_by_direct_charge(int enable)
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

static inline int charge_set_input_current_max(void)
{
	return -EINVAL;
}

static inline int charge_get_input_current_max(void)
{
	return -EINVAL;
}

static inline int charge_set_input_current(int iin)
{
	return -EINVAL;
}

static inline int charge_set_iin_rt_curr(int iin_rt_curr)
{
	return -EINVAL;
}

static inline int get_charge_done_type(void)
{
	return CHARGE_DONE_NON;
}

static inline void buck_charge_update_iterm(int iterm)
{
}
#endif /* CONFIG_HUAWEI_BUCK_CHARGER */

int get_eoc_max_delay_count(void);
#endif
