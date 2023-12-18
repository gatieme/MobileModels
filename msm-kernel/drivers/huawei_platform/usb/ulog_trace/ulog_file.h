/*
 * ulog_file.h
 *
 * save adsp log
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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

#ifndef _ULOG_FILE_H_
#define _ULOG_FILE_H_

#include <linux/types.h>
#include <linux/fs.h>
#include <linux/stat.h>

#define ULOG_FILE_NAME_SIZE                 256
#define ULOG_FILE_MAX_SIZE                  4194304 /* 4M */
#define ULOG_FILE_PATH                      "/data/log/charge-log/qbg-adsp-log-chg-"
#define ULOG_FILE_DIR                       "/data/log/charge-log/"
#define ULOG_FILE_NAME                      "qbg-adsp-log-chg"
#define ULOG_ADSP_FILE_LENGTH               36
#define ULOG_FILE_CHECK_CNT                 300
#define ULOG_FILE_MAX_SAVE                  5
#define ULOG_BASIC_YEAR                     1900
#define ULOG_DATA_HEAD_SIZE                 256
#define IOCTL_ULOGTRACE_READ                _IO('Q', 0x01)
#define IOCTL_ULOGTRACE_WRITE               _IO('Q', 0x02)
#define IOCTL_ULOGTRACE_LEVEL               _IO('Q', 0x04)
#define IOCTL_ULOGTRACE_CATEGORIES          _IO('Q', 0x08)
#define IOCTL_ULOGTRACE_PERIOD              _IO('Q', 0x10)
#define IOCTL_ULOGTRACE_MODE                _IO('Q', 0x20)
#define IOCTL_ULOGTRACE_CMD                 _IO('Q', 0x03)
#define IOCTL_ULOGTRACE_PARA                _IO('Q', 0x3c)

struct ulog_file {
	char name[ULOG_FILE_NAME_SIZE];
};

struct ulog_getdents_callback {
	struct dir_context ctx;
	int file_num;
	time64_t earliest_file_time;
	char earliest_file_name[ULOG_FILE_NAME_SIZE];
};

void ulog_init(struct ulog_file *file);
int ulog_write(struct ulog_file *file, const char *data, u32 size);

#endif /* _ULOG_FILE_H_ */
