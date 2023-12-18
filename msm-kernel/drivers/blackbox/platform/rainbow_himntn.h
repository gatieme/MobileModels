/*
 * process for himntn function
 *
 * Copyright (c) 2019-2019 Huawei Technologies Co., Ltd.
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

#ifndef _RAINBOW_HIMNTN_H
#define _RAINBOW_HIMNTN_H

#include <linux/printk.h>

/*
 * factory version config default
 * 0000000000011100100001011111001011111110
 * beta version config default
 * 0000000000000100000001011011001011111110
 * commercial version config default
 * 0000000000000100001000000000000000000000
 */
#define HIMNTN_DEFAULT_FACTORY 0x1C85F2FE
#define HIMNTN_DEFAULT_BETA 0x405B2FE
#define HIMNTN_DEDAULT_COMMERCIAL 0x4200000

/*
 * Description: himntn log level switch, close when code upload
 * 4: print all level log
 * 3: print ERR/WARN/INFO level log
 * 2: print ERR/WARN level log
 * 1: print only ERR level log
 */
#define HIMNTN_LOG_LEVEL 4

enum log_level_enum {
	HIMNTN_LOG_ERROR = 1,
	HIMNTN_LOG_WARNING,
	HIMNTN_LOG_INFO,
	HIMNTN_LOG_DEBUG,
	HIMNTN_LOG_UNKNOWN,
};

/* log print control implement */
#define HIMNTN_ERR(msg, ...)                                               \
do {                                                                       \
	if (HIMNTN_LOG_LEVEL >= HIMNTN_LOG_ERROR)                          \
		pr_err("[HIMNTN/E]%s: " msg, __func__, ##__VA_ARGS__);     \
} while (0)

#define HIMNTN_WARNING(msg, ...)                                           \
do {                                                                       \
	if (HIMNTN_LOG_LEVEL >= HIMNTN_LOG_WARNING)                        \
		pr_warn("[HIMNTN/W]%s: " msg, __func__, ##__VA_ARGS__);    \
} while (0)

#define HIMNTN_INFO(msg, ...)                                              \
do {                                                                       \
	if (HIMNTN_LOG_LEVEL >= HIMNTN_LOG_INFO)                           \
		pr_info("[HIMNTN/I]%s: " msg, __func__, ##__VA_ARGS__);    \
} while (0)

#define HIMNTN_DEBUG(msg, ...)                                             \
do {                                                                       \
	if (HIMNTN_LOG_LEVEL >= HIMNTN_LOG_DEBUG)                          \
		pr_debug("[HIMNTN/D]%s: " msg, __func__, ##__VA_ARGS__);   \
} while (0)

/*
 * 1000000000000000000000000000000000000000
 * before get item switch, the value from partition
 * should be >> calculate with this value
 */
#define BASE_VALUE_GET_SWITCH 0x8000000000

unsigned long long get_global_himntn_data(void);
void set_global_himntn_data(unsigned long long value);

#endif

