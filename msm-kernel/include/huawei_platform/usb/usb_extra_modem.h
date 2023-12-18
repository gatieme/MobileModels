/*
 * usb_extra_modem.h
 *
 * header file for usb_extra_modem driver
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#ifndef _USB_EXTRA_MODEM_H_
#define _USB_EXTRA_MODEM_H_

#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/workqueue.h>
#include <linux/delay.h>

#define UEM_BASE_DEC                      10

#define UEM_LOADSWITCH_GPIO_DISABLE       0
#define UEM_LOADSWITCH_GPIO_ENABLE        1

#define UEM_UEVENT_SIZE                   3
#define UEM_UVDM_DATA_SIZE                2
#define UEM_UVDM_FUNCTION                 6
#define UEM_VID                           0x3426
#define UEM_PID                           0x2999
#define UEM_OTG_VBUS_DELAY                10
#define UEM_VBUS_SWITCH2Q6_DELAY          150
#define UEM_ATTACH_WORK_DELAY             100
#define UEM_VBUS_INSERT_DELAY             300
#define UEM_OTG_INSERT_DELAY              150
#define UEM_CHARGE_INFO_DELAY             250
#define UEM_DR_SWAP_DELAY                 1500
#define UEM_NCM_ENUMERATION_TIME_OUT      25000
#define UEM_UEVENT_INFO_LEN               16
#define UEM_UEVENT_ENVP_OFFSET1           1

enum uem_loadswitch_gpio {
	LOADSWITCH_GPIO_Q4,
	LOADSWITCH_GPIO_Q5,
};

enum uem_vbus_control {
	UEM_VBUS_DISABLE,
	UEM_VBUS_ENABLE,
};

enum uem_usb_phy_hiz {
	USB_PHY_HIZ_DISABLE,
	USB_PHY_HIZ_ENABLE,
};

enum uem_hwuvdm_command {
	UEM_HWUVDM_CMD_CMOS_Q2_CLOSE = 1,
	UEM_HWUVDM_CMD_VBUS_INSERT = 2,
	UEM_HWUVDM_CMD_CHARGE_READY = 3,
	UEM_HWUVDM_CMD_OTG_INSERT = 4,
	UEM_HWUVDM_CMD_OTG_DISCONNECT = 5,
	UEM_HWUVDM_CMD_CMOS_Q3_OPEN = 6,
	UEM_HWUVDM_CMD_PMU_ENABLE = 7,
	UEM_HWUVDM_CMD_PMU_DISABLE = 8,
	UEM_HWUVDM_CMD_REQUEST_CHARGE_INFO = 9,
	UEM_HWUVDM_CMD_AUDIO_INSERT = 10,
	UEM_HWUVDM_CMD_MODEM_WAKEUP = 11,
	UEM_HWUVDM_CMD_USB_POWERON = 12,
	UEM_HWUVDM_CMD_USB_POWEROFF = 13,
	UEM_HWUVDM_CMD_CMOS_Q3_CLOSE = 14,
	UEM_HWUVDM_CMD_AUDIO_DISCONNECT = 15,
};

enum uem_event_value {
	UEM_EVENT_NOTIFY_VAL_ATTACH,
	UEM_EVENT_NOTIFY_VAL_VBUS_INSERT,
	UEM_EVENT_NOTIFY_VAL_OTG_INSERT,
	UEM_EVENT_NOTIFY_VAL_OTG_DISCONNECT,
	UEM_EVENT_NOTIFY_VAL_REQUEST_CHARGE_INFO,
	UEM_EVENT_NOTIFY_VAL_DC_CABLE,
	UEM_EVENT_NOTIFY_VAL_LOADSWITCH_DISABLE,
	UEM_EVENT_NOTIFY_VAL_AUDIO_INSERT,
	UEM_EVENT_NOTIFY_VAL_AUDIO_DISCONNECT,
	UEM_EVENT_NOTIFY_VAL_RESET_MESSAGE,
};

struct uem_dev_info {
	struct device *dev;
	struct notifier_block ext_modem_nb;
	struct notifier_block connect_nb;
	struct notifier_block hw_usb_nb;
	struct work_struct event_work;
	struct delayed_work attach_work;
	struct delayed_work vbus_insert_work;
	struct delayed_work otg_insert_work;
	struct delayed_work charge_info_work;
	struct delayed_work dr_swap_work;
	struct delayed_work ncm_enumeration_work;
	struct delayed_work usb_power_work;
	struct delayed_work host_ctl_work;
	struct wakeup_source *uem_lock;
	struct mutex notifier_lock;
	struct mutex otg_status_lock;
	int gpio_q4;
	int gpio_q5;
	unsigned long event_type;
	u32 event_data;
	u32 charge_resistance;
	u32 charge_leak_current;
	u32 uem_fcp_flag;
	unsigned int usb_speed;
	bool attach_status;
	bool modem_active_status;
	bool otg_status;
	bool vbus_status;
	bool wlrx_status;
	bool charger_check_flag;
	bool enumeration_flag;
	const char *module_id;
};

#ifdef CONFIG_USB_EXTRA_MODEM
struct uem_dev_info *uem_get_dev_info(void);
unsigned int uem_get_charge_resistance(void);
unsigned int uem_get_charge_leak_current(void);
bool uem_check_online_status(void);
void uem_handle_detach_event(void);
void uem_switch_vbus_output(int state);
void uem_check_charger_type(u32 msg);
#else
static inline struct uem_dev_info *uem_get_dev_info(void)
{
	return NULL;
}

static inline unsigned int uem_get_charge_resistance(void)
{
	return 0;
}

static inline unsigned int uem_get_charge_leak_current(void)
{
	return 0;
}

static inline bool uem_check_online_status(void)
{
	return false;
}

static inline void uem_handle_detach_event(void)
{
}

static inline void uem_switch_vbus_output(int state)
{
}

static inline void uem_check_charger_type(u32 msg)
{
}
#endif /* CONFIG_USB_EXTRA_MODEM */
#endif /* _USB_EXTRA_MODEM_H_ */
