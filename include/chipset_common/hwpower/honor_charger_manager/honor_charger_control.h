/*
 * honor_charger_control.h
 *
 * honor charger control driver
 *
 * Copyright (c) 2022-2022 Honor Technologies Co., Ltd.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef _HONOR_CHARGER_CONTROL
#define _HONOR_CHARGER_CONTROL

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/usb/otg.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/power_supply.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/notifier.h>
#include <linux/mutex.h>
#include <linux/spmi.h>
#include <linux/sysfs.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/pm_wakeup.h>
#include <linux/time.h>
#include <linux/timekeeping.h>
#include <linux/kthread.h>
#include <linux/version.h>
#include <linux/workqueue.h>
#include <linux/alarmtimer.h>
#include <hwpower/honor_charger_type.h>

typedef enum charge_path_prop {
	PROP_SET_BEGIN = 0,
	PROP_SET_CHARGER_TYPE,
	PROP_SET_OTG_ENABLE,
	PROP_EN_HV_CHARGER,
	PROP_SET_PROT_TYPE,
	PROP_SET_ADAPTOR_MODE,
	PROP_SET_CHAREGR_PLUGOUT_TYPE,
	PROP_SET_WDT_ENABLE,
	PROP_SET_MAX_COUNT,
} charge_path_prop;

typedef enum charge_path_status {
	CHARGER_STATUS_DEFAULT = 0,
	CHARGER_STATUS_READY,
	CHARGER_STATUS_RUNNING,
	CHARGER_STATUS_FAIL,
	CHARGER_STATUS_DONE,
} charge_path_status;

typedef enum charger_path_type
{
	CHARGER_PATH_SC = 0,
	CHARGER_PATH_BUCK,
	CHARGER_PATH_COUNT,
} charger_path_type;

typedef struct {
	void *private_data;
	charger_path_type path_type;
	charge_path_status (*get_charger_status)(void);
	int (*charger_running)(void);
	int (*charger_init)(void);
	int (*charger_stop)(void);
	int (*charger_exit)(void);
	int (*charger_set_prop)(charge_path_prop prop, void *data, int val);
} charger_path_ops;

typedef struct honor_charger_control_info {
	struct device *dev;
	struct delayed_work control_work;
	struct wakeup_source control_wakelock;
	struct alarm charger_control_timer;
	struct device_node *np;
	charger_path_ops* path_ops[CHARGER_PATH_COUNT];
	wait_queue_head_t wait_que;
	/* mutex define here */
	struct mutex charger_control_lock;
	/* enum define here */
	charger_path_type cur_path;
	charger_path_type next_path;
	/* int define here */
	int charger_type;
	int prot_type;
	int adapter_mode;
	int polling_interval;
	/* bool define here */
	bool resume_need_wakelock;
	bool chg_full_unlock_support;
	bool charger_path_is_ready;
	bool charger_control_plug_state;
} honor_charger_control_info;

typedef enum {
	PD_EVENT_DEVICE_BEGIN,
	PD_EVENT_DEVICE_ATTACHED,
	PD_EVENT_DEVICE_DETACHED,
	PD_EVENT_OTG_ATTACHED,
	PD_EVENT_OTG_DETACHED,
	PD_EVENT_DEVICE_MAX,
} pd_event_list;

typedef int (*pd_port_status_callback)(unsigned long event, void *data);
int charger_control_path_register(charger_path_ops *ops);
void charger_control_enable_otg(bool en);
void wakeup_charger_thread(void);
void charger_control_chg_type_notify(int chg_type);
void charger_control_set_plug_state(bool state);
void handle_charger_plugin_event(void);
void handle_charger_plugout_event(void);
/* init start */
int charger_event_queue_init(void);
void charger_event_queue_exit(void);
void honor_charger_interface_init(struct honor_charger_control_info *di);
void honor_charger_interface_exit(void);
/* init end */
#endif /* _HONOR_CHARGER_CONTROL */
