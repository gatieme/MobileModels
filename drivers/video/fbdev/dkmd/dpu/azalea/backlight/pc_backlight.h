/*
 * pc_backlight.h
 *
 * backlight function interface & definition
 *
 * Copyright (c) 2018-2019 Huawei Technologies Co., Ltd.
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
#ifndef PC_BACKLIGHT_H
#define PC_BACKLIGHT_H

#define LOG_LEVEL_INFO 7
#define bl_merge(msg, ...)    \
	do { if (pcbl_msg_level > 0)  \
		pr_emerg("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define bl_alert(msg, ...)    \
	do { if (pcbl_msg_level > 1)  \
		pr_alert("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define bl_crit(msg, ...)    \
	do { if (pcbl_msg_level > 2)  \
		pr_crit("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define bl_err(msg, ...)    \
	do { if (pcbl_msg_level > 3)  \
		pr_err("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define bl_warning(msg, ...)    \
	do { if (pcbl_msg_level > 4)  \
		pr_warn("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define bl_notice(msg, ...)    \
	do { if (pcbl_msg_level > 5)  \
		pr_info("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define bl_info(msg, ...)    \
	do { if (pcbl_msg_level > 6)  \
		pr_info("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)
#define bl_debug(msg, ...)    \
	do { if (pcbl_msg_level > 7)  \
		pr_info("[pc_backlight]%s: "msg, __func__, ## __VA_ARGS__); } while (0)

int bl_chip_config(void);
#endif /* PC_BACKLIGHT_H */