/*
 * qbg_file.h
 *
 * save qbg adsp log
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

#ifndef _QBG_FILE_H_
#define _QBG_FILE_H_

#include <linux/types.h>
#include <linux/fs.h>
#include <linux/stat.h>

#define QBG_FILE_NAME_SIZE                 256
#define QBG_FILE_MAX_SIZE                  4194304 /* 4M */
#define QBG_FILE_PATH                      "/data/log/charge-log/qbg-adsp-log-"
#define QBG_FILE_DIR                       "/data/log/charge-log/"
#define QBG_FILE_NAME                      "qbg-adsp-log"
#define QBG_ADSP_FILE_LENGTH               32
#define QBG_FILE_CHECK_CNT                 300
#define QBG_FILE_MAX_SAVE                  5
#define QBG_BASIC_YEAR                     1900
#define QBG_DATA_HEAD_SIZE                 256

#define QBG_DUMP_CONTEXT_SIZE              ((612 + 3) / 4)
#define QBG_COL                            4
#define QBG_COL1                           1
#define QBG_COL2                           2
#define QBG_COL3                           3
#define QBG_UNIT_100                       100

struct qbg_log_file {
	char name[QBG_FILE_NAME_SIZE];
};

struct qbg_getdents_callback {
	struct dir_context ctx;
	int file_num;
	time64_t earliest_file_time;
	char earliest_file_name[QBG_FILE_NAME_SIZE];
};

void qbg_log_init(struct qbg_log_file *file);
int qbg_log_write(struct qbg_log_file *file, const u8 *data, u32 size);

#endif /* _QBG_FILE_H_ */
