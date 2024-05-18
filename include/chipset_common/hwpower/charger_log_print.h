/*
 * power_log_print.h
 *
 * power log interfaces, supporting log tag and level
 *
 * Copyright (c) 2022-2022 Honor Technologies Co., Ltd.
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

#ifndef _CHARGER_LOG_PRINT_H
#define _CHARGER_LOG_PRINT_H

#include <linux/printk.h>
#include <linux/types.h>

enum {
	CHGLOG_ERR	= 1U << 0,
	CHGLOG_WARNING	= 1U << 1,
	CHGLOG_INFO	= 1U << 2,
	CHGLOG_DEBUG	= 1U << 3,
	CHGLOG_DEBUG1	= 1U << 4,
	CHGLOG_DEBUG2	= 1U << 5,
	CHGLOG_DEBUG3	= 1U << 6,
	CHGLOG_DEBUG4	= 1U << 7,
};

#define CHGLOG_TAG_DEFALUT_LEVEL (CHGLOG_ERR | CHGLOG_WARNING | CHGLOG_INFO)

struct chg_log_tag {
	const char *name;
	u32 level;
};

#define CHG_TAG_STRUCT_NAME(name) _chgtag_##name

#define chg_fmt_tag(TAG, LEVEL) "[HICHG_" #LEVEL "_" #TAG"]" "%s "

#define CHGLOG_REGIST()							\
	CHGLOG_REGIST_TAG_LEVEL(CHGLOG_TAG, CHGLOG_TAG_DEFALUT_LEVEL)

#define CHGLOG_REGIST_LEVEL(level)					\
	CHGLOG_REGIST_TAG_LEVEL(CHGLOG_TAG, level)

#define CHGLOG_REGIST_TAG_LEVEL(name, level)				\
	_CHGLOG_REGIST_TAG_LEVEL(name, level)

#define _CHGLOG_REGIST_TAG_LEVEL(name, level)				\
	static struct chg_log_tag CHG_TAG_STRUCT_NAME(name)		\
	__used								\
	__attribute__((unused, __section__("__chglog_tag")))		\
	= { #name, level }

#define chglog_err(x...)          _chglog_err(CHGLOG_TAG, ##x)
#define _chglog_err(TAG, x...)    __chglog_err(TAG, ##x)
#define __chglog_err(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_ERR)		\
			pr_err(chg_fmt_tag(TAG, E) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#define chglog_warn(x...)         _chglog_warn(CHGLOG_TAG, ##x)
#define _chglog_warn(TAG, x...)   __chglog_warn(TAG, ##x)
#define __chglog_warn(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_WARNING)		\
			pr_err(chg_fmt_tag(TAG, W) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#define chglog_info(x...)         _chglog_info(CHGLOG_TAG, ##x)
#define _chglog_info(TAG, x...)   __chglog_info(TAG, ##x)
#define __chglog_info(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_INFO)		\
			pr_info(chg_fmt_tag(TAG, I) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#define chglog_debug(x...)        _chglog_debug(CHGLOG_TAG, ##x)
#define _chglog_debug(TAG, x...)  __chglog_debug(TAG, ##x)
#define __chglog_debug(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_DEBUG)		\
			pr_err(chg_fmt_tag(TAG, D) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#define chglog_debug1(x...)       _chglog_debug1(CHGLOG_TAG, ##x)
#define _chglog_debug1(TAG, x...) __chglog_debug1(TAG, ##x)
#define __chglog_debug1(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_DEBUG1)		\
			pr_err(chg_fmt_tag(TAG, D1) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#define chglog_debug2(x...)       _chglog_debug2(CHGLOG_TAG, ##x)
#define _chglog_debug2(TAG, x...) __chglog_debug2(TAG, ##x)
#define __chglog_debug2(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_DEBUG2)		\
			pr_err(chg_fmt_tag(TAG, D2) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#define chglog_debug3(x...)       _chglog_debug3(CHGLOG_TAG, ##x)
#define _chglog_debug3(TAG, x...) __chglog_debug3(TAG, ##x)
#define __chglog_debug3(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_DEBUG3)		\
			pr_err(chg_fmt_tag(TAG, D3) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#define chglog_debug4(x...)       _chglog_debug4(CHGLOG_TAG, ##x)
#define _chglog_debug4(TAG, x...) __chglog_debug4(TAG, ##x)
#define __chglog_debug4(TAG, fmt, ...)					\
	do {								\
		if (CHG_TAG_STRUCT_NAME(TAG).level & CHGLOG_DEBUG4)		\
			pr_err(chg_fmt_tag(TAG, D4) fmt, __func__, ##__VA_ARGS__);	\
	} while (0)

#endif /* _CHARGER_LOG_PRINT_H */
