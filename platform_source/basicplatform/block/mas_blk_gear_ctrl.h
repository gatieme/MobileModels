/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: gear ctrl implement
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef __MAS_BLK_GEAR_CTRL_H__
#define __MAS_BLK_GEAR_CTRL_H__

#include <linux/bio.h>
#include <linux/blk-mq.h>
#include <linux/blkdev.h>
#include <linux/types.h>
#include "blk.h"

#define MAS_GEAR_INVALID_MAIGC_NUM 0xA5A5A5A5
/***************************************************************************************************
***********************************    for sysfs    ************************************************
***************************************************************************************************/
extern u32 g_mas_gear_ctrl_flow_threshold_size;
extern u32 g_mas_gear_ctrl_flow_threshold_cnt;
extern u32 g_mas_gear_ctrl_flow_window_time_us;
extern bool g_mas_gear_auto_flag;
extern bool g_mas_gear_ctrl_device_abandon;
extern u32 g_mas_min_highest_gear_stay_time;
extern u32 g_mas_ufs_rate;
extern u32 g_mas_fg_num;
extern u32 g_mas_sync_num;
extern u32 g_mas_min_gear_level;
extern u32 g_mas_max_gear_level;
extern bool g_mas_gear_auto_io_back;

void mas_queue_gear_ctrl_change(struct request_queue *q, u32 set_gear);

/***************************************************************************************************
******************************    flow control interface    ****************************************
***************************************************************************************************/
struct mas_gear_ctrl_flow_count {
	struct mas_gear_ctrl_flow_count *self;
	struct list_head use_list;
	struct list_head drop_list;
	spinlock_t set_lock;
	u32 total;
	u32 cnt;
};

struct mas_gear_ctrl_flow_item {
	struct list_head ilist;
	bool inflat;
	u32 size;
	struct request *req;
	ktime_t ts;
};

extern struct mas_gear_ctrl_flow_count g_mas_gear_ctrl_flow_cnt;
void mas_gear_ctrl_flow_init(struct mas_gear_ctrl_flow_count *cf);
void mas_gear_ctrl_flow_get_size_and_cnt(struct mas_gear_ctrl_flow_count *cf, u32 *size, u32 *cnt);
void mas_gear_ctrl_flow_add(struct mas_gear_ctrl_flow_count *cf, struct request *req);
void mas_gear_ctrl_flow_destory(struct mas_gear_ctrl_flow_count *cf);
void mas_gear_ctrl_flow_delete_wait(struct request *req);
void mas_gear_ctrl_flow_drop(struct mas_gear_ctrl_flow_count *cf);
void mas_blk_gear_ctrl_reinit(void);

void mas_queue_busy_change_gear(struct request_queue *q, struct request *req);
void mas_blk_disable_gear_ctrl(bool enable);
void mas_blk_auto_gear_ctrl(bool enable);

#endif
