/*
 * power_platform_interface.h
 *
 * interface for power module
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
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

#ifndef _POWER_PLATFORM_INTERFACE_H_
#define _POWER_PLATFORM_INTERFACE_H_

#include <linux/version.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/err.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <linux/jiffies.h>
#include <linux/kernel.h>
#include <linux/types.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
void wakeup_source_init(struct wakeup_source *ws, const char *name);
void wakeup_source_trash(struct wakeup_source *ws);
#endif


#endif /* _POWER_PLATFORM_INTERFACE_H_ */
