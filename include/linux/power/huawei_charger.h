/*
 * drivers/power/huawei_charger.h
 *
 *huawei charger driver
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
//#include <chipset_common/hwpower/adapter/adapter_test.h>
//#include <chipset_common/hwpower/charger/charger_type.h>
#include <chipset_common/hwpower/power_dts.h>
#include <chipset_common/hwpower/power_dsm.h>
#include <chipset_common/hwpower/power_event_ne.h>
#include <chipset_common/hwpower/power_ui_ne.h>
#include <huawei_platform/power/huawei_charger_common.h>
#include <chipset_common/hwpower/adapter_protocol.h>
#include <chipset_common/hwpower/adapter_protocol_scp.h>
#include <chipset_common/hwpower/adapter_protocol_fcp.h>
#include <chipset_common/hwpower/adapter_protocol_pd.h>
#include <chipset_common/hwpower/water_detect.h>


#if (KERNEL_VERSION(4, 14, 0) > LINUX_VERSION_CODE)
#include <linux/qpnp/qpnp-adc.h>
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4,0 )
struct timespec64 current_kernel_time(void);
struct timespec64 current_kernel_time64(void);
#endif
void wakeup_source_init(struct wakeup_source *ws, const char *name);
void wakeup_source_trash(struct wakeup_source *ws);
#ifndef _HUAWEI_CHARGER
#define _HUAWEI_CHARGER

/* marco define area */
#ifndef TRUE
#define TRUE (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif

/* fcp detect */
#define FCP_ADAPTER_DETECT_FAIL 1
#define FCP_ADAPTER_DETECT_SUCC 0
#define FCP_ADAPTER_DETECT_OTHER -1

/*
 *Running test result
 *And charge abnormal info
 */
#define CHARGE_STATUS_FAIL      (0<<0)  /* Indicate running test charging status fail */
#define CHARGE_STATUS_PASS      (1<<0)  /* Indicate running test charging status pass */
#define BATTERY_FULL            (1<<1)
#define USB_NOT_PRESENT         (1<<2)
#define REGULATOR_BOOST         (1<<3)
#define CHARGE_LIMIT            (1<<4)
#define BATTERY_HEALTH          (1<<5)
#define CHARGER_OVP             (1<<6)
#define OCP_ABNORML             (1<<7)
#define BATTERY_VOL_ABNORML     (1<<8)
#define BATTERY_TEMP_ABNORML    (1<<9)
#define BATTERY_ABSENT          (1<<10)

#define CHARGE_OCP_THR          -4500000    /* charge current abnormal threshold */
#define BATTERY_OCP_THR         6000000     /* discharge current abnormal threshold */
#define BATTERY_VOL_THR_HI      4500000     /* battery voltage abnormal high threshold */
#define BATTERY_VOL_THR_LO      2500000     /* battery voltage abnormal low threshold */
#define BATTERY_TEMP_HI         780         /* battery high temp threshold */
#define BATTERY_TEMP_LO         -100        /* battery low temp threshold */
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
#define CHARGELOG_SIZE          2048

#define SMB_START_CHARGING      (0x40)
#define SMB_STOP_CHARGING       (0x60)
#define QPNP_SMBCHARGER_TIMEOUT (30000)

#define MV_TO_V                 1000
#define UV_TO_MV                1000
#define UA_TO_MA                1000

#define THERMAL_REASON_SIZE     16
#define ERR_NO_STRING_SIZE      256
#define HIZ_MODE_ENABLE         TRUE
#define HIZ_MODE_DISABLE        FALSE
#define EOC_DISABLE             FALSE
#define CHG_LOG_STR_LEN         30

enum charge_done_type {
	CHARGE_DONE_NON = 0,
	CHARGE_DONE,
};

enum battery_event_type
{
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
	CHARGE_SYSFS_CHARGELOG_HEAD,
	CHARGE_SYSFS_CHARGELOG,
	CHARGE_SYSFS_UPDATE_VOLT_NOW,
	CHARGE_SYSFS_IBUS,
	CHARGE_SYSFS_VBUS,
	CHARGE_SYSFS_HIZ,
	CHARGE_SYSFS_CHARGE_TYPE,
	CHARGE_SYSFS_CHARGE_TERM_VOLT_DESIGN,
	CHARGE_SYSFS_CHARGE_TERM_CURR_DESIGN,
	CHARGE_SYSFS_CHARGE_TERM_VOLT_SETTING,
	CHARGE_SYSFS_CHARGE_TERM_CURR_SETTING,
	CHARGE_SYSFS_FCP_SUPPORT,
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

enum charger_type {
	CHARGER_TYPE_USB = 0,      /* SDP */
	CHARGER_TYPE_BC_USB,       /* CDP */
	CHARGER_TYPE_NON_STANDARD, /* UNKNOW */
	CHARGER_TYPE_STANDARD,     /* DCP */
	CHARGER_TYPE_FCP,          /* FCP */
	CHARGER_REMOVED,           /* not connected */
	USB_EVENT_OTG_ID,
	CHARGER_TYPE_VR,           /* VR charger */
	CHARGER_TYPE_TYPEC,        /* PD charger */
	CHARGER_TYPE_PD,           /* PD charger */
	CHARGER_TYPE_SCP,          /* SCP charger */
	CHARGER_TYPE_WIRELESS,     /* wireless charger */
	CHARGER_TYPE_POGOPIN,      /* pogopin charger */
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

enum charger_event_type {
	START_SINK = 0,
	STOP_SINK,
	START_SOURCE,
	STOP_SOURCE,
	START_SINK_WIRELESS,
	STOP_SINK_WIRELESS,
	CHARGER_MAX_EVENT,
};

enum fcp_check_stage_type {
 	FCP_STAGE_DEFAUTL,
 	FCP_STAGE_SUPPORT_DETECT,
 	FCP_STAGE_ADAPTER_DETECT,
 	FCP_STAGE_ADAPTER_ENABLE,
 	FCP_STAGE_SUCESS,
 	FCP_STAGE_CHARGE_DONE,
 	FCP_STAGE_RESET_ADAPTOR,
 	FCP_STAGE_ERROR,
};

enum fcp_retry_operate_type {
 	FCP_RETRY_OPERATE_DEFAUTL,
 	FCP_RETRY_OPERATE_RESET_ADAPTER,
 	FCP_RETRY_OPERATE_RESET_SWITCH,
 	FCP_RETRY_OPERATE_UNVALID,
};

enum reset_adapter_source_type {
	RESET_ADAPTER_SYSFS = 0,
	RESET_ADAPTER_WIRELESS_TX,
	RESET_ADAPTER_TOTAL,
};

enum fcp_test_result{
     FCP_TEST_SUCC,
     FCP_TEST_FAIL,
     FCP_TEST_NOT_SUPPORT,
};

#define CHAGRE_STATE_NORMAL              (0x00)
#define CHAGRE_STATE_VBUS_OVP           (0x01)
#define CHAGRE_STATE_NOT_PG               (0x02)
#define CHAGRE_STATE_WDT_FAULT         (0x04)
#define CHAGRE_STATE_BATT_OVP           (0x08)
#define CHAGRE_STATE_CHRG_DONE         (0x10)
#define CHAGRE_STATE_INPUT_DPM          (0x20)
#define CHAGRE_STATE_NTC_FAULT          (0x40)
#define CHAGRE_STATE_CV_MODE            0x80

#define CHARGE_CURRENT_0000_MA          0
#define CHARGE_CURRENT_0100_MA          100000
#define CHARGE_CURRENT_0150_MA          150000
#define CHARGE_CURRENT_0500_MA          500000
#define CHARGE_CURRENT_0800_MA          800000
#define CHARGE_CURRENT_1000_MA          1000000
#define CHARGE_CURRENT_1200_MA          1200000
#define CHARGE_CURRENT_1900_MA          1900000
#define CHARGE_CURRENT_2000_MA          2000000
#define CHARGE_CURRENT_4000_MA          4000000
#define CHARGE_CURRENT_MAX_MA           32767000
#define CHIP_RESP_TIME	                200
#define FCP_DETECT_DELAY_IN_POWEROFF_CHARGE 2000
#define VBUS_VOL_READ_CNT               3
#define VBUS_VOLTAGE_13400_MV           13400
#define SLEEP_110MS                     110
#define COOL_LIMIT                      11
#define WARM_LIMIT                      44
#define WARM_CUR_RATIO                  35
#define RATIO_BASE      100
#define IBIS_RATIO      120
#define MV_PER_VOLT     1000

#define VBUS_VOLTAGE_7000_MV              (7000)
#define VBUS_VOLTAGE_6500_MV              (6500)
#define VBUS_VOLTAGE_ABNORMAL_MAX_COUNT (2)
/* fcp detect */
#define FCP_ADAPTER_DETECT_FAIL 1
#define FCP_ADAPTER_DETECT_SUCC 0
#define FCP_ADAPTER_DETECT_OTHER -1

#define FCP_CHECK_CNT_MAX     3
enum disable_charger_type {
 	CHARGER_SYS_NODE = 0,
 	CHARGER_FATAL_ISC_TYPE,
 	CHARGER_WIRELESS_TX,
 	BATT_CERTIFICATION_TYPE,
 	__MAX_DISABLE_CHAGER,
};


#define ADAPTER_0V                    (0)
#define ADAPTER_5V                    (5)
#define ADAPTER_7V                    7
#define ADAPTER_9V                    (9)
#define ADAPTER_12V                   (12)

static const char *const fcp_check_stage[] = {
 	[0] = "FCP_STAGE_DEFAUTL",
 	[1] = "FCP_STAGE_SUPPORT_DETECT",
 	[2] = "FCP_STAGE_ADAPTER_DETECT",
 	[3] = "FCP_STAGE_ADAPTER_ENABLE",
 	[4] = "FCP_STAGE_SUCESS",
};

struct charger_event_queue {
	enum charger_event_type *event;
	unsigned int num_event;
	unsigned int max_event;
	unsigned int enpos, depos;
	unsigned int overlay, overlay_index;
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

enum charge_done_sleep_type {
	CHARGE_DONE_SLEEP_DISABLED = 0,
	CHARGE_DONE_SLEEP_ENABLED,
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

struct charge_sysfs_data
{
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
	unsigned int disable_charger[__MAX_DISABLE_CHAGER];
	unsigned int batfet_disable;
	unsigned int vr_charger_type;
	unsigned int dbc_charge_control;
	unsigned int support_ico;
	unsigned int water_intrused;
	unsigned int fcp_support;
	enum charge_done_type charge_done_status;
	enum charge_done_sleep_type charge_done_sleep_status;
	char *reg_value;
	char *reg_head;
	char *bootloader_info;
	struct mutex dump_reg_lock;
	struct mutex dump_reg_head_lock;
	struct mutex bootloader_info_lock;
	int vterm;
	int iterm;
	int charger_cvcal_value;
	int charger_cvcal_clear;
	int charger_get_cvset;
};

struct charge_switch_ops {
	enum charger_type (*get_charger_type)(void);
};


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
	struct charge_ops *ops;
	struct charge_switch_ops *sw_ops;
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
	enum charger_type charger_type;
	enum typec_input_current typec_current_mode;
	enum power_supply_type charger_source;
	enum charge_fault_type charge_fault;
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
	u32 force_disable_dc_path;
	u32 scp_adp_normal_chg;
	u32 startup_iin_limit;
	u32 hota_iin_limit;
#ifdef CONFIG_DIRECT_CHARGER
	int ignore_pluggin_and_plugout_flag;
	int support_scp_power;
#endif
	struct spmi_device *spmi;
	struct power_supply *usb_psy;
	struct power_supply *pc_port_psy;
	struct power_supply *batt_psy;
    struct power_supply *chg_psy;
	struct power_supply *bms_psy;
	struct power_supply *bk_batt_psy;
	struct power_supply *main_psy;
	int chrg_config;
	int factory_diag;
	unsigned int input_event;
	unsigned long event;
	struct delayed_work smb_charger_work;
	struct delayed_work otg_type_work;
	int fcp_test_delay;
	int reset_adapter;
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
	u32 rt_curr_th;
	u32 rt_test_time;
	bool rt_test_succ;
	u32 increase_term_volt_en;
	int en_eoc_max_delay;
	const char *usb_psy_name;
	const char *bk_battery_psy_name;
	const char *main_psy_name;
	const char *bms_psy_name;
	int otg_type;
};

#ifdef CONFIG_DIRECT_CHARGER
void direct_charger_disconnect_update_charger_type(void);
void ignore_pluggin_and_pluggout_interrupt(void);
void restore_pluggin_pluggout_interrupt(void);
int get_direct_charge_flag(void);
int charger_disable_usbpd(bool disable);
void wired_connect_send_icon_uevent(int icon_type);
void wired_disconnect_send_icon_uevent(void);
#endif
void wireless_connect_send_icon_uevent(int icon_type);
void charge_send_icon_uevent(int icon_type);

int get_charge_done_type(void);

enum charge_wakelock_flag {
	CHARGE_NEED_WAKELOCK,
	CHARGE_NO_NEED_WAKELOCK,
};
/*adaptor protocol test*/
enum adaptor_name {
	TYPE_SCP,
	TYPE_FCP,
	TYPE_PD,
	TYPE_SC,
	TYPE_HSC,
	TYPE_OTHER,
};

enum test_state {
	DETECT_FAIL = 0,
	DETECT_SUCC = 1,
	PROTOCOL_FINISH_SUCC = 2,
};

struct adaptor_test_attr{
	enum adaptor_name charger_type;
	char adaptor_str_name[10];
	enum test_state result;
};

/* variable and function declarationn area */
void chg_set_adaptor_test_result(enum adaptor_name charger_type, enum test_state result);
extern int is_usb_ovp(void);
void strncat_length_protect(char *dst, char *src);
int get_loginfo_int(struct power_supply *psy, int property);
extern  int huawei_handle_charger_event(unsigned long event);
int battery_health_handler(void);
void cap_learning_event_done_notify(void);
struct charge_device_info *get_charger_device_info(void);
void reset_fcp_flag(void);
void fcp_set_stage_status(enum fcp_check_stage_type stage_type);
int get_fcp_charging_flag(void);
void set_fcp_charging_flag(int val);
bool get_pd_charge_flag(void);
int get_reset_adapter(void);
int get_first_insert(void);
void set_first_insert(int flag);
int fcp_test_is_support(void);
int fcp_test_detect_adapter(void);
int huawei_battery_capacity(void);
int get_eoc_max_delay_count(void);
int adaptor_cfg_for_wltx_vbus(int vol, int cur);
bool adaptor_cfg_for_normal_chg(int vol, int cur);
void charger_vbus_init_handler(int vbus);
int charger_get_output_voltage(int *output_voltage);


#ifdef CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION
int usb_charger_register_notifier(struct notifier_block *nb);
int usb_charger_notifier_unregister(struct notifier_block *nb);
#else
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
static inline int usb_charger_register_notifier(struct notifier_block *nb)
{
	return 0;
}
static inline int usb_charger_notifier_unregister(struct notifier_block *nb)
{
	return 0;
}
#endif
#endif /* CONFIG_HUAWEI_POWER_EMBEDDED_ISOLATION */
#endif