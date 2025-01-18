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
#include <scsi/scsi_host.h>
#include <scsi/scsi_device.h>
#include <securec.h>
#include "blk.h"
#include "mas_blk_gear_ctrl.h"
#include "scsi_gear_ctrl.h"

ssize_t mas_gear_ctrl_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;
	struct blk_dev_lld *lld = mas_blk_get_lld(q);

	if (unlikely(!lld || !lld->gear_ctrl_ops || !lld->gear_ctrl_ops->gear_level_get ||
		     !lld->gear_ctrl_ops->gear_level_cap_get))
		goto out;

	if (g_mas_gear_ctrl_device_abandon)
		goto out;

	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		goto out;

	if (unlikely(g_mas_min_gear_level == MAS_GEAR_INVALID_MAIGC_NUM)) {
		ret = lld->gear_ctrl_ops->gear_level_cap_get(q, &g_mas_min_gear_level, &g_mas_max_gear_level);
		if (ret)
			goto out;
	}

	if (val <= g_mas_max_gear_level && val >= g_mas_min_gear_level)
		mas_queue_gear_ctrl_change(q, (u32)val, -1);
out:
	return (ssize_t)count;
}

ssize_t mas_gear_ctrl_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;
	u32 cur_gear;
	int ret1, ret2;
	struct blk_dev_lld *lld = mas_blk_get_lld(q);

	if (unlikely(!lld || !lld->gear_ctrl_ops || !lld->gear_ctrl_ops->gear_level_get ||
		     !lld->gear_ctrl_ops->gear_level_cap_get))
		return offset;

	ret1 = lld->gear_ctrl_ops->gear_level_get(q, &cur_gear);
	ret2 = lld->gear_ctrl_ops->gear_level_cap_get(q, &g_mas_min_gear_level, &g_mas_max_gear_level);
	if (ret1 || ret2) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "can't get current gear level or cap: %d, %d\n", ret1, ret2);
	} else {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "cur_gear = %u, min_level = %u, max_level = %u\n", cur_gear, g_mas_min_gear_level,
				    g_mas_max_gear_level);
	}
	return offset < 0 ? 0 : offset;
}

ssize_t mas_gear_auto_enable_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	mas_blk_auto_gear_ctrl(!!val);
	return (ssize_t)count;
}

ssize_t mas_gear_auto_enable_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "mas_gear_auto_flag: %d\n",
			    g_mas_gear_auto_flag);

	return offset < 0 ? 0 : offset;
}

ssize_t mas_gear_ufs_rate_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	if (val <= 100)
		g_mas_ufs_rate = (u32)val;

	return (ssize_t)count;
}

ssize_t mas_gear_ufs_rate_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "mas_ufs_rate: %u\n", g_mas_ufs_rate);

	return offset < 0 ? 0 : offset;
}

ssize_t mas_gear_fg_num_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	g_mas_fg_num = (u32)val;

	return (ssize_t)count;
}

ssize_t mas_gear_fg_num_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "mas_fg_num: %u\n", g_mas_fg_num);

	return offset < 0 ? 0 : offset;
}

ssize_t mas_gear_flow_cnt_per_ms_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	g_mas_gear_ctrl_flow_threshold_cnt_per_ms = (u32)val;

	return (ssize_t)count;
}

ssize_t mas_gear_flow_cnt_per_ms_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "flowctrl_cnt_per_ms: %u/ms\n",
			    g_mas_gear_ctrl_flow_threshold_cnt_per_ms);

	return offset < 0 ? 0 : offset;
}

ssize_t mas_gear_flow_threshold_size_per_100us_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	g_mas_gear_ctrl_flow_threshold_size_per_100us = (u32)val;

	return (ssize_t)count;
}

ssize_t mas_gear_flow_threshold_size_per_100us_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "flow_threshold_size_per_100us: %u/100us\n",
			    g_mas_gear_ctrl_flow_threshold_size_per_100us);

	return offset < 0 ? 0 : offset;
}

ssize_t mas_gear_flow_threshold_inflat_size_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	g_mas_gear_ctrl_inflat_threshold_size = (u32)val;

	return (ssize_t)count;
}

ssize_t mas_gear_flow_threshold_inflat_size_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "inflat_threshold_size: %u\n",
			    g_mas_gear_ctrl_inflat_threshold_size);

	return offset < 0 ? 0 : offset;
}

ssize_t mas_gear_sync_num_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	g_mas_sync_num = (u32)val;

	return (ssize_t)count;
}

ssize_t mas_gear_sync_num_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "mas_sync_num: %u\n", g_mas_sync_num);

	return offset < 0 ? 0 : offset;
}

ssize_t mas_min_gear_stay_time_store(struct request_queue *q, const char *page, size_t count)
{
	ssize_t ret;
	unsigned long val;

	if (g_mas_gear_ctrl_device_abandon)
		return (ssize_t)count;
	ret = queue_var_store(&val, page, count);
	if (ret < 0)
		return (ssize_t)count;

	g_mas_min_highest_gear_stay_time = (u32)val;

	return (ssize_t)count;
}

ssize_t mas_min_gear_stay_time_show(struct request_queue *q, char *page)
{
	ssize_t offset = 0;

	if (g_mas_gear_ctrl_device_abandon) {
		offset = snprintf_s(page + offset, PAGE_SIZE - offset, PAGE_SIZE - offset - 1,
				    "not support gear ctrl!\n");
		return offset < 0 ? 0 : offset;
	}
	offset = snprintf_s(page, PAGE_SIZE - offset, PAGE_SIZE - offset - 1, "min_gear4_time: %llu\n",
			    g_mas_min_highest_gear_stay_time);

	return offset < 0 ? 0 : offset;
}

