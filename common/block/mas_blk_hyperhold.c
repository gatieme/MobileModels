/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description:  hyperhold helper function in block
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

#include <linux/kernel.h>
#include <linux/blk-mq.h>
#include <linux/blkdev.h>

#include "mas_blk.h"

void blk_mq_tagset_health_query_register(
	struct blk_mq_tag_set *tag_set, lld_query_health_fn func)
{
	if (tag_set)
		tag_set->lld_func.health_query = func;
}

int blk_lld_health_query(struct block_device *bi_bdev, u8 *pre_eol_info,
	u8 *life_time_est_a, u8 *life_time_est_b)
{
	struct blk_dev_lld *lld_fn = NULL;
	struct request_queue *q = NULL;

	if ((!bi_bdev) || (!pre_eol_info) || (!life_time_est_a) ||
		(!life_time_est_b))
		return -EPERM;

	q = bdev_get_queue(bi_bdev);
	lld_fn = mas_blk_get_lld(q);
	if (lld_fn && lld_fn->health_query)
		return lld_fn->health_query(q, pre_eol_info, life_time_est_a,
			life_time_est_b);

	return -EPERM;
}
