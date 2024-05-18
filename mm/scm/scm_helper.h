/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager helper
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for API, structure defination.
 *
 */
#ifndef _SCM_HELPER_H_
#define _SCM_HELPER_H_

#include <linux/string.h>
#include <linux/types.h>
#include <linux/version.h>

#define MB(x) ((unsigned long)(x) << 20)
#define BYTE2PAGE(x) ((x) >> 12)
#define PAGE2KB(x) ((x) << 2)
#define KB2PAGE(x) ((x) >> 2)
#define PAGE2MB(x) ((x) >> 8)
#define MB2PAGE(x) ((x) << 8)

#define MS_TO_NS(x) ((x) * (1000 * 1000))
#define NS_TO_MS(x) ((x) / (1000 * 1000))

#define SCM_ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))

#define __MIN(a, b) ((a) < (b) ? (a) : (b))
#define __MAX(a, b) ((a) > (b) ? (a) : (b))

#define STATIC_ASSERT(condition) typedef char p__LINE__[(condition) ? 1 : -1];
#ifndef __maybe_unused
#define __maybe_unused
#endif

#define BUF (buf + strlen(buf))
#define LEN ((len > strlen(buf)) ? (len - strlen(buf)) : 0)

#define STR_EQ(buf, taget) !strncmp(buf, taget, strlen(taget))
#define STR_GET_U64(buf, taget, v) \
	(STR_EQ(buf, taget) && !kstrtou64(buf + strlen(taget), 0, v))

static inline int64_t _scm_elapsed_ts(uint64_t now, uint64_t start,
				      uint64_t def_value)
{
	return (now > start) ? (now - start) : def_value;
}

#endif //_SCM_TASK_STATUS_H_
