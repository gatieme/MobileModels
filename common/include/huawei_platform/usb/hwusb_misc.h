/*
 * hwusb_misc.h
 *
 * header file for usb misc driver
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

#ifndef _HW_USB_MISC_H_
#define _HW_USB_MISC_H_

#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/workqueue.h>
#include <linux/delay.h>

struct huawei_usb_misc_ops {
	void *dev_data;
	int (*sc_regn_enable)(bool en, void *dev_data);
	int (*adc_enable)(bool en, void *dev_data);
};

struct usb_misc_dev_info {
	struct device *dev;
	struct huawei_usb_misc_ops *p_ops;
};

#ifdef CONFIG_HWUSB_MISC
int huawei_usb_misc_ops_register(struct huawei_usb_misc_ops *ops);
int charger_regn_adc_enable(bool enable, bool force, const char *client_name);
#else
static inline int huawei_usb_misc_ops_register(struct huawei_usb_misc_ops *ops)
{
	return -1;
}
static inline int charger_regn_adc_enable(bool enable, bool force, const char *client_name)
{
	return -1;
}
#endif

#endif /* _HW_USB_MISC_H_ */
