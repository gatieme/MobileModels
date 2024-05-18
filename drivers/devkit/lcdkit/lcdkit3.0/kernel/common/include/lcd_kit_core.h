/*
 * lcd_kit_core.h
 *
 * lcdkit core function for lcdkit head file
 *
 * Copyright (c) 2018-2019 Honor Device Co., Ltd.
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

#ifndef _LCD_KIT_CORE_H_
#define _LCD_KIT_CORE_H_
#include <linux/types.h>
#include <linux/kobject.h>

/* lcd kit ops, provide to lcd kit module register */
struct lcd_kit_ops {
	bool (*lcd_kit_support)(void);
	int (*create_sysfs)(struct kobject *obj);
	int (*get_project_id)(char *buff);
	int (*read_project_id)(void);
	int (*get_2d_barcode)(char *buff);
	int (*get_status_by_type)(int type, int *status);
	int (*get_pt_station_status)(void);
	int (*avdd_mipi_ctrl)(void *hld, int enable);
	int (*get_lcd_status)(void);
	int (*get_panel_power_status)(void);
	int (*power_monitor_on)(void);
	int (*power_monitor_off)(void);
	int (*set_vss_by_thermal)(void);
	int (*write_otp_gamma)(u8 *buf);
	int (*proximity_power_off)(void);
	int (*get_sn_code)(void);
	int (*get_panel_ver)(void);
	bool (*panel_event_skip_delay)(void *hld,
		uint32_t event, uint32_t data);
};

struct timeval
{
	long tv_sec;
	long tv_usec;
};

/* TS sync */
#define NO_SYNC    0
#define SHORT_SYNC 5

/* TS Event */
enum lcd_kit_ts_pm_type {
	TS_BEFORE_SUSPEND = 0,
	TS_SUSPEND_DEVICE,
	TS_RESUME_DEVICE,
	TS_AFTER_RESUME,
	TS_EARLY_SUSPEND,
	TS_IC_SHUT_DOWN,
	TS_2ND_POWER_OFF,
};

// #if IS_ENABLED(CONFIG_TP_QCOM_8450)
enum lcd_kit_usb_pm_type {
	USB_RESUME_DEVICE,
	USB_SUSPEND_DEVICE,
	USB_AOD_ON,
	USB_AOD_OFF,
};

enum usb_kit_panel_index {
	MAIN_LCD_PANEL = 0,
	SUB_LCD_PANEL,
};
// #endif

enum lcd_kit_bat_heating_type {
	BAT_HEATING_LCD_ON = 0,
	BAT_HEATING_LCD_OFF,
};

enum lcd_kit_bat_leakage_type {
	BAT_LEAKAGE_LCD_ON = 0,
	BAT_LEAKAGE_LCD_OFF,
};
/* ts type */
enum ts_kit_type {
	LCD_ONLINE_TYPE,
	PT_STATION_TYPE,
};

enum lcd_kit_type {
	TS_GESTURE_FUNCTION,
};

enum lcd_kit_panel_state {
	LCD_POWER_STATE_OFF,
	LCD_POWER_STATE_ON,
};

/* lcd kit ops, provide to ts kit module register */
struct ts_kit_ops {
	int (*ts_power_notify)(enum lcd_kit_ts_pm_type type, int sync);
	int (*get_tp_status_by_type)(int type, int *status);
	int (*read_otp_gamma)(u8 *buf, int len);
	bool (*get_tp_proxmity)(void);
	int (*ts_multi_power_notify)(enum lcd_kit_ts_pm_type type,
		int sync, int panel_index);
	bool (*get_afe_status)(struct timeval *record_tv);
	int (*send_esd_event)(u32 val);
};

// #if IS_ENABLED(CONFIG_TP_QCOM_8450)
struct usb_kit_ops {
	int (*usb_power_notify)(enum lcd_kit_usb_pm_type type, int sync);
	int (*usb_multi_power_notify)(enum lcd_kit_usb_pm_type type,
		int sync, int panel_index);
};

struct bat_heating_ops{
	int (*bat_heating_notify)(enum lcd_kit_bat_heating_type type,int sync);
	int (*bat_heating_multi_notify)(enum lcd_kit_bat_heating_type type,int sync,int panel_index);
};

struct bat_leakage_kit_ops{
	int (*bat_leakage_notify)(enum lcd_kit_bat_leakage_type type,int sync);
	int (*bat_leakage_multi_notify)(enum lcd_kit_bat_leakage_type type,int sync,int panel_index);
};

extern struct lcd_kit_ops *lcd_kit_get_ops(void);
extern int lcd_kit_ops_register(struct lcd_kit_ops *ops);
extern int lcd_kit_ops_unregister(struct lcd_kit_ops *ops);
extern struct ts_kit_ops *ts_kit_get_ops(void);
// #endif
#endif
