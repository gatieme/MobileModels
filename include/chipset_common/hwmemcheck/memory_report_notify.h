/*
 * Copyright (C) 2022 Honor Device Co.Ltd
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

#ifndef __MEMORY_REPORT_NOTIFY_H__
#define __MEMORY_REPORT_NOTIFY_H__

#include <linux/types.h>

#define PROC_NAME_LEN 16
#define GPU_MEM_LEAK_TYPE 1100

struct memory_report_info {
	unsigned int mem_type;
	pid_t pid;
	char pname[PROC_NAME_LEN];
	unsigned int mem_size;
	unsigned int mem_ratio;
	unsigned long leak_duration;
};

void send_memory_report(const struct memory_report_info *leak_proc);

#endif /* __MEMORY_REPORT_NOTIFY_H__ */