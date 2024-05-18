/*
 * power_wakeup.h
 *
 * wakeup operation for power module
 *
 * Copyright (c) 2020-2020 Honor Device Co., Ltd.
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

#ifndef _POWER_WAKEUP_H_
#define _POWER_WAKEUP_H_

#include <linux/device.h>
#include <linux/types.h>
#include <linux/pm_wakeup.h>
#include <linux/version.h>

#if IS_ENABLED(CONFIG_HONOR_CHARGER_DECOUP)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
void wakeup_source_init(struct wakeup_source *ws, const char *name);
void wakeup_source_trash(struct wakeup_source *ws);
#endif /* LINUX_VERSION_CODE */
#endif /* CONFIG_HONOR_CHARGER_DECOUP */

#endif /* _POWER_WAKEUP_H_ */

