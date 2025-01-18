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

#define pr_fmt(fmt) "[BLK-IO]" fmt

#include <linux/bio.h>
#include <linux/blk-mq.h>
#include <linux/blkdev.h>
#include <linux/delay.h>
#include <linux/gfp.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include "blk.h"
#include "mas_blk_gear_ctrl.h"

#define GEAR_CTRL_FLOW_MIN_CNT 8
#define GEAR_CTRL_FLOW_MIN_TIME_US 1000
u32 g_mas_gear_ctrl_flow_threshold_cnt_per_ms = 4;
u32 g_mas_gear_ctrl_flow_threshold_size_per_100us = 8; /* size in pages */
u32 g_mas_gear_ctrl_inflat_threshold_size = 256; /* size in pages */

ktime_t g_flow_start;
int g_flow_cnt;
int g_flow_size;
spinlock_t flow_lock;

atomic_t g_inflat_size;
atomic_t g_flow_cnt_last;
atomic_t g_flow_size_last;
atomic_t g_flow_last_spend_time;

void mas_gear_ctrl_flow_config(u32 size_per_100us, u32 cnt_per_ms)
{
	g_mas_gear_ctrl_flow_threshold_cnt_per_ms = cnt_per_ms;
	g_mas_gear_ctrl_flow_threshold_size_per_100us = size_per_100us;
}

void mas_gear_ctrl_flow_init(void)
{
	atomic_set(&g_inflat_size, 0);
	atomic_set(&g_flow_cnt_last, 0);
	atomic_set(&g_flow_size_last, 0);
	atomic_set(&g_flow_last_spend_time, 0);
	g_flow_size = 0;
	g_flow_cnt = 0;
	g_flow_start = ktime_set(0, 0);
	spin_lock_init(&flow_lock);
}

void mas_gear_ctrl_flow_drop(void)
{
	unsigned long flags;

	atomic_set(&g_inflat_size, 0);
	atomic_set(&g_flow_cnt_last, 0);
	atomic_set(&g_flow_size_last, 0);
	atomic_set(&g_flow_last_spend_time, 0);
	spin_lock_irqsave(&flow_lock, flags);
	g_flow_size = 0;
	g_flow_cnt = 0;
	g_flow_start = ktime_set(0, 0);
	spin_unlock_irqrestore(&flow_lock, flags);
}

void mas_gear_ctrl_flow_destory(void)
{
	return mas_gear_ctrl_flow_drop();
}

void mas_gear_ctrl_flow_delete_wait(struct request *req)
{
	int c, dec, sub = (int)(blk_rq_bytes(req) / PAGE_SIZE);

	do {
		c = atomic_read(&g_inflat_size);
		if (c >= sub)
			dec = c - sub;
		else
			dec = 0;
	} while (!atomic_try_cmpxchg(&g_inflat_size, &c, dec));
}

void mas_gear_ctrl_flow_add(struct request *req)
{
	int io_size = req ? (int)(blk_rq_bytes(req) / PAGE_SIZE) : 0;
	int spend_us;
	int flow_cnt;
	int flow_size;
	bool update = false;
	ktime_t now = ktime_get();
	unsigned long flags;

	atomic_add(io_size, &g_inflat_size);
	spin_lock_irqsave(&flow_lock, flags);
	g_flow_size += io_size;
	g_flow_cnt += (int)!!io_size;
	if (req && g_flow_cnt == 1) {
		g_flow_start = now;
	} else {
		spend_us = (int)ktime_us_delta(now, g_flow_start);
		if ((g_flow_cnt >= GEAR_CTRL_FLOW_MIN_CNT) || (spend_us > GEAR_CTRL_FLOW_MIN_TIME_US)) {
			flow_cnt = g_flow_cnt;
			flow_size = g_flow_size;
			g_flow_cnt = 0;
			g_flow_size = 0;
			update = true;
		}
	}
	spin_unlock_irqrestore(&flow_lock, flags);
	if (update) {
		atomic_set(&g_flow_cnt_last, flow_cnt);
		atomic_set(&g_flow_size_last, flow_size);
		atomic_set(&g_flow_last_spend_time, spend_us);
	}
}

void mas_gear_ctrl_flow_get(int *flow_cnt , int *flow_size, int *spend_us, int *inflat_size)
{
	*inflat_size = atomic_read(&g_inflat_size);
	*flow_cnt = atomic_read(&g_flow_cnt_last);
	*flow_size = atomic_read(&g_flow_size_last);
	*spend_us = atomic_read(&g_flow_last_spend_time);
}

