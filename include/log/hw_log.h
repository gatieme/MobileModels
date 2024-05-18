/*
 * hw_log.h
 *
 * hwlog interfaces, supporting log tag and level
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

#ifndef _LINUX_HWLOG_H
#define _LINUX_HWLOG_H

#include <linux/printk.h>
#include <linux/types.h>

enum {
	HILOG_ERR	    = 1U << 0,
	HILOG_WARNING	= 1U << 1,
	HILOG_INFO	    = 1U << 2,
	HILOG_DEBUG	    = 1U << 3,
	HILOG_DEBUG1	= 1U << 4,
	HILOG_DEBUG2	= 1U << 5,
	HILOG_DEBUG3	= 1U << 6,
	HILOG_DEBUG4	= 1U << 7,
};

#define HWLOG_TAG_DEFALUT_LEVEL (HILOG_ERR | HILOG_WARNING | HILOG_INFO)

struct honor_log_tag {
	const char *name;
	u32 level;
};

#define TAG_STRUCT_NAME(name) _hwtag_##name

#define hw_fmt_tag(TAG, LEVEL) "[" #LEVEL "/" #TAG "] "

#define HILOG_REGIST()							\
	HILOG_REGIST_TAG_LEVEL(HWLOG_TAG, HWLOG_TAG_DEFALUT_LEVEL)

#define HILOG_REGIST_LEVEL(level)					\
	HILOG_REGIST_TAG_LEVEL(HWLOG_TAG, level)

#define HILOG_REGIST_TAG_LEVEL(name, level)				\
	_HILOG_REGIST_TAG_LEVEL(name, level)

#define _HILOG_REGIST_TAG_LEVEL(name, level)				\
	static struct honor_log_tag TAG_STRUCT_NAME(name)		\
	__used								\
	= { #name, level }

#define hilog_err(x...)          _hilog_err(HWLOG_TAG, ##x)
#define _hilog_err(TAG, x...)    __hilog_err(TAG, ##x)
#define __hilog_err(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_ERR)		\
			pr_err(hw_fmt_tag(TAG, E) fmt, ##__VA_ARGS__);	\
	} while (0)

#define hilog_warn(x...)         _hilog_warn(HWLOG_TAG, ##x)
#define _hilog_warn(TAG, x...)   __hilog_warn(TAG, ##x)
#define __hilog_warn(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_WARNING)		\
			pr_err(hw_fmt_tag(TAG, W) fmt, ##__VA_ARGS__);	\
	} while (0)

#define hilog_info(x...)         _hilog_info(HWLOG_TAG, ##x)
#define _hilog_info(TAG, x...)   __hilog_info(TAG, ##x)
#define __hilog_info(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_INFO)		\
			pr_info(hw_fmt_tag(TAG, I) fmt, ##__VA_ARGS__);	\
	} while (0)

#define hilog_debug(x...)        _hilog_debug(HWLOG_TAG, ##x)
#define _hilog_debug(TAG, x...)  __hilog_debug(TAG, ##x)
#define __hilog_debug(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_DEBUG)		\
			pr_err(hw_fmt_tag(TAG, D) fmt, ##__VA_ARGS__);	\
	} while (0)

#define hilog_debug1(x...)       _hilog_debug1(HWLOG_TAG, ##x)
#define _hilog_debug1(TAG, x...) __hilog_debug1(TAG, ##x)
#define __hilog_debug1(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_DEBUG1)		\
			pr_err(hw_fmt_tag(TAG, D1) fmt, ##__VA_ARGS__);	\
	} while (0)

#define hilog_debug2(x...)       _hilog_debug2(HWLOG_TAG, ##x)
#define _hilog_debug2(TAG, x...) __hilog_debug2(TAG, ##x)
#define __hilog_debug2(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_DEBUG2)		\
			pr_err(hw_fmt_tag(TAG, D2) fmt, ##__VA_ARGS__);	\
	} while (0)

#define hilog_debug3(x...)       _hilog_debug3(HWLOG_TAG, ##x)
#define _hilog_debug3(TAG, x...) __hilog_debug3(TAG, ##x)
#define __hilog_debug3(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_DEBUG3)		\
			pr_err(hw_fmt_tag(TAG, D3) fmt, ##__VA_ARGS__);	\
	} while (0)

#define hilog_debug4(x...)       _hilog_debug4(HWLOG_TAG, ##x)
#define _hilog_debug4(TAG, x...) __hilog_debug4(TAG, ##x)
#define __hilog_debug4(TAG, fmt, ...)					\
	do {								\
		if (TAG_STRUCT_NAME(TAG).level & HILOG_DEBUG4)		\
			pr_err(hw_fmt_tag(TAG, D4) fmt, ##__VA_ARGS__);	\
	} while (0)

#endif
