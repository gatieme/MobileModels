/* SPDX-License-Identifier: GPL-2.0 */
/*
 * hw_pogopin.h
 *
 * huawei pogopin driver
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _HW_POGOPIN_H_
#define _HW_POGOPIN_H_

#include <linux/power_supply.h>
#include <chipset_common/hwpower/common_module/power_wakeup.h>

#ifndef HIGH
#define HIGH                       1
#endif
#ifndef LOW
#define LOW                        0
#endif

#ifndef TRUE
#define TRUE                       1
#endif
#ifndef FALSE
#define FALSE                      0
#endif

#define POGOPIN_DELAYED_50MS       50
#define POGOPIN_DELAYED_5000MS     5000
#define POGOPIN_MOS_DELAYED        120 /* mos open has 120 delay */
#define POGOPIN_TIME_DELAYE_200MS  200
#define POGOPIN_TIME_DELAYE_300MS  300
#define POGOPIN_TIMEOUT_500MS      500
#define CHECK_TIMES                5

#define POGOPIN_CHARGER_INSERT     1
#define POGOPIN_CHARGER_REMOVE     0

#define POGOPIN_TYPEC_MODE           0
#define POGOPIN_MICROB_CHARGER_MODE  1
#define POGOPIN_MICROB_OTG_MODE      2

#define POGOPIN_IIN_CURRENT        2000
#define POGOPIN_ICHG_CURRENT       2100

#define POGOPIN_SUPPORT            1
#define POGOPIN_NOT_SUPPORT        0

#define POGOPIN_EXTCON_NEEDED      1
#define POGOPIN_EXTCON_NOT_NEEDED  0

enum pogo_status {
	POGO_NONE = 0,
	POGO_CHARGER,
	POGO_OTG,
	POGO_STATUS_END,
};

#define STATE_ON                   1
#define STATE_OFF                  0
struct pogopin_info {
	struct platform_device *pdev;
	struct pogopin_cc_ops *ops;
	int pogo_support;
	int pogopin_extcon_needed;
	int usb_switch_gpio;
	int pogo_path_switch_gpio;
	int buck_boost_gpio;
	int pogopin_int_gpio;
	int pogopin_int_irq;
	int typec_int_gpio;
	struct delayed_work work;
	int current_int_status;
	struct completion dev_off_completion;
	bool fcp_support;
	int typec_int_irq;
	int pogo_gpio_status;
	struct device_node *aux_switch_node;
	struct work_struct typec_int_work;
	enum pogo_status pogo_insert_status;
	struct wakeup_source *wakelock;
};

struct pogopin_cc_ops {
	int (*typec_detect_disable)(bool);
	int (*typec_detect_vbus)(void);
};

enum pogopin_sysfs_type {
	POGOPIN_SYSFS_INTERFACE_TYPE = 0,
};

enum current_working_interface {
	POGOPIN_INTERFACE_BEGIN = 0,
	TYPEC_INTERFACE,
	POGOPIN_INTERFACE,
	POGOPIN_AND_TYPEC,
	NO_INTERFACE = POGOPIN_INTERFACE_BEGIN,
	POGOPIN_INTERFACE_END,
};

enum typec_event {
	TYPEC_DEVICE_REMOVE = 0,
	TYPEC_DEVICE_RE_CHECK,
};

enum pogopin_event {
	POGOPIN_EVENT_START = 0,
	POGOPIN_PLUG_IN_OTG, /* notify pogopin otg plug in */
	POGOPIN_PLUG_OUT_OTG, /* notify pogopin otg plug out */
	POGOPIN_CHARGER_OUT_COMPLETE, /* notify pogopin charger out */
	POGOPIN_PLUG_IN_MICROUSB,
	POGOPIN_PLUG_OUT_MICROUSB,
	POGOPIN_EVENT_END,
};

#ifdef CONFIG_POGO_PIN
extern void pogopin_cc_register_ops(struct pogopin_cc_ops *ops);
extern bool pogopin_is_support(void);
extern int pogopin_get_interface_status(void);
extern bool pogopin_otg_from_buckboost(void);
extern void pogopin_5pin_completion_devoff(void);
extern unsigned long pogopin_5pin_wait_for_completion(unsigned long timeout);
extern void pogopin_5pin_reinit_completion_devoff(void);
extern void pogopin_5pin_typec_detect_disable(bool en);
extern void pogopin_5pin_otg_in_switch_from_typec(void);
extern void pogopin_5pin_remove_switch_to_typec(void);
extern void pogopin_5pin_int_irq_disable(bool en);
extern bool pogopin_5pin_get_fcp_support(void);
extern void pogopin_3pin_typec_otg_buckboost_ctrl(bool enable);
extern bool pogopin_3pin_ignore_pogo_vbus_in_event(void);
extern int pogopin_3pin_get_input_current(void);
extern int pogopin_3pin_get_charger_current(void);
extern int pogopin_event_notifier_register(struct notifier_block *nb);
extern bool pogopin_is_charging(void);
extern bool pogopin_is_support(void);
extern bool pogopin_extcon_is_needed(void);
extern void pogopin_event_notify(enum pogopin_event event);
extern void pogopin_event_notify_with_data(enum pogopin_event event, u32 data);
extern int pogopin_event_notifier_unregister(struct notifier_block *nb);
extern void pogopin_otg_status_change_process(uint8_t value);
extern void pogopin_5pin_set_pogo_status(enum pogo_status status);
extern void pogopin_5pin_set_ana_audio_status(bool status);
extern bool pogopin_5pin_get_ana_audio_status(void);
extern void pogopin_set_usb_mode(int plug_in);
extern void pogopin_set_buck_boost_gpio(int value);
#else
static inline void pogopin_cc_register_ops(struct pogopin_cc_ops *ops)
{
}

static inline bool pogopin_is_support(void)
{
	return 0;
}

static inline void pogopin_5pin_completion_devoff(void)
{
}

static inline unsigned long pogopin_5pin_wait_for_completion(
	unsigned long timeout)
{
	return 0;
}

static inline void pogopin_5pin_reinit_completion_devoff(void)
{
}

static inline int pogopin_get_interface_status(void)
{
	return 0;
}

static inline void pogopin_5pin_typec_detect_disable(bool en)
{
}

static inline void pogopin_5pin_otg_in_switch_from_typec(void)
{
}

static inline void pogopin_5pin_remove_switch_to_typec(void)
{
}

static inline void pogopin_5pin_int_irq_disable(bool en)
{
}

static inline bool pogopin_5pin_get_fcp_support(void)
{
	return true;
}

static inline void pogopin_3pin_typec_otg_buckboost_ctrl(bool enable)
{
}

static inline bool pogopin_3pin_ignore_pogo_vbus_in_event(void)
{
	return false;
}

static inline bool pogopin_otg_from_buckboost(void)
{
	return false;
}

static inline int pogopin_3pin_get_input_current(void)
{
	return 0;
}

static inline int pogopin_3pin_get_charger_current(void)
{
	return 0;
}

static inline int pogopin_event_notifier_register(struct notifier_block *nb)
{
	return 0;
}

static inline int pogopin_event_notifier_unregister(struct notifier_block *nb)
{
	return 0;
}

static inline bool pogopin_is_charging(void)
{
	return false;
}

static inline bool pogopin_is_support(void)
{
	return false;
}


static inline  bool pogopin_extcon_is_needed(void)
{
	return false;
}

static inline void pogopin_event_notify(enum pogopin_event event)
{
}

static inline void pogopin_event_notify_with_data(enum pogopin_event event, u32 data)
{
}

static inline void pogopin_otg_status_change_process(uint8_t value)
{
}

static inline void pogopin_5pin_set_pogo_status(enum pogo_status status)
{
}

static inline void pogopin_5pin_set_ana_audio_status(bool status)
{
}

static inline bool pogopin_5pin_get_ana_audio_status(void)
{
	return false;
}

static inline void pogopin_set_usb_mode(int plug_in)
{
}

static inline void pogopin_set_buck_boost_gpio(int value)
{
}
#endif /* CONFIG_POGO_PIN */

#endif /* _HW_POGOPIN_H_ */
