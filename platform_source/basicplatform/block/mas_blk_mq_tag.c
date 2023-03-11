/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: mas block MQ tag
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

#include <linux/types.h>
#include <linux/version.h>
#include <linux/sbitmap.h>
#include <linux/blk-mq.h>

#include "blk-mq.h"
#include "blk-mq-tag.h"
#include "mas_blk_mq_tag.h"

struct bt_iter_data {
	struct blk_mq_hw_ctx *hctx;
	busy_iter_fn *fn;
	void *data;
	bool reserved;
	bool prior;
};

struct bt_tags_iter_data {
	struct blk_mq_tags *tags;
	busy_tag_iter_fn *fn;
	void *data;
	bool reserved;
	bool prior;
};

static bool ufs_tagset_bt_iter(
		struct sbitmap *bitmap, unsigned int bitnr, void *data)
{
	struct bt_iter_data *iter_data = data;
	struct blk_mq_hw_ctx *hctx = iter_data->hctx;
	struct blk_mq_tags *tags = hctx->tags;
	struct request *rq = NULL;

	if (iter_data->reserved)
		bitnr += tags->reserved_tags_id_offset;
	if (iter_data->prior)
		bitnr += tags->high_prio_tags_id_offset;

	rq = tags->rqs[bitnr];

	/*
	 * We can hit rq == NULL here, because the tagging functions
	 * test and set the bit before assining ->rqs[].
	 */
	if (rq && rq->q == hctx->queue && iter_data->fn)
		iter_data->fn(hctx, rq, iter_data->data, iter_data->reserved);

	return true;
}

static inline void ufs_tagset_bt_for_each(
	struct sbitmap_queue *bt, struct bt_iter_data *iter_data)
{
	sbitmap_for_each_set(&bt->sb, ufs_tagset_bt_iter, iter_data);
}

void ufs_tagset_tag_busy_iter(
	struct blk_mq_hw_ctx *hctx, busy_iter_fn *fn, void *priv)
{
	struct bt_iter_data iter_data;
	struct blk_mq_tags *tags = hctx->tags;

	iter_data.hctx = hctx;
	iter_data.fn = fn;
	iter_data.data = priv;
	iter_data.reserved = false;
	iter_data.prior = false;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	ufs_tagset_bt_for_each(tags->bitmap_tags, &iter_data);
#else
	ufs_tagset_bt_for_each(&tags->bitmap_tags, &iter_data);
#endif

	if (tags->nr_high_prio_tags) {
		iter_data.prior = true;
		ufs_tagset_bt_for_each(&tags->highprio_tags, &iter_data);
	}

	if (tags->nr_reserved_tags) {
		iter_data.reserved = true;
		iter_data.prior = false;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		ufs_tagset_bt_for_each(tags->breserved_tags, &iter_data);
#else
		ufs_tagset_bt_for_each(&tags->breserved_tags, &iter_data);
#endif
	}
}

static bool ufs_tagset_bt_tags_iter(
	struct sbitmap *bitmap, unsigned int bitnr, void *data)
{
	struct bt_tags_iter_data *iter_data = data;
	struct blk_mq_tags *tags = iter_data->tags;
	struct request *rq = NULL;

	if (iter_data->reserved)
		bitnr += tags->reserved_tags_id_offset;
	if (iter_data->prior)
		bitnr += tags->high_prio_tags_id_offset;

	rq = tags->rqs[bitnr];

	if (iter_data->fn)
		iter_data->fn(rq, iter_data->data, iter_data->reserved);
	return true;
}

static inline void ufs_tagset_bt_tags_for_each(
	struct sbitmap_queue *bt, const struct bt_tags_iter_data *iter_data)
{
	if (iter_data->tags->rqs)
		sbitmap_for_each_set(
			&bt->sb, ufs_tagset_bt_tags_iter, (void *)iter_data);
}

static inline bool ufs_sbitmap_is_fg(struct blk_mq_alloc_data *data)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	return (data->cmd_flags & REQ_FG_META) && !(data->mas_io_flag & REQ_VIP);
#else
	return (data->io_flag & REQ_FG_META) && !(data->io_flag & REQ_VIP);
#endif
}

#define FG_WAIT_TAG_TIMEOUT_MS 500ull
static inline bool ufs_sbitmap_fg_starved(struct blk_mq_alloc_data *data)
{
	if (!data->wait_tag_start)
		return false;

	return ktime_after(ktime_get(),
		ktime_add_ms(data->wait_tag_start, FG_WAIT_TAG_TIMEOUT_MS));
}

static int ufs_sbitmap_queue_get(
	struct blk_mq_alloc_data *data, struct sbitmap_queue *bt)
{
	if (unlikely(ufs_sbitmap_is_fg(data) && ufs_mq_vip_tag_wait_cnt(data) &&
		     !ufs_sbitmap_fg_starved(data)))
		return -1;

#ifdef CONFIG_MAS_UNISTORE_PRESERVE
	if (!mas_blk_is_section_ready(data->q, data->bio))
		return -1;

	if (mas_blk_is_reserved_empty(data))
		return -1;
#endif

	return __sbitmap_queue_get(bt);
}

static int ufs_try_get_tag(struct blk_mq_alloc_data *data,
	struct sbitmap_queue *bt, struct blk_mq_hw_ctx *hctx)
{
	int tag;

	tag = ufs_sbitmap_queue_get(data, bt);
	if (tag != -1)
		return tag;

	/*
	 * We're out of tags on this hardware queue, kick any
	 * pending IO submits before going to sleep waiting for
	 * some to complete.
	 */
	blk_mq_run_hw_queue(hctx, false);

	/*
	 * Retry tag allocation after running the hardware queue,
	 * as running the queue may also have found completions.
	 */
	return ufs_sbitmap_queue_get(data, bt);
}

static unsigned int ufs_tagset_bt_get_slowpath(
	struct blk_mq_alloc_data *data, struct sbitmap_queue *bt,
	struct blk_mq_hw_ctx *hctx)
{
	struct sbq_wait_state *bs = NULL;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	DEFINE_SBQ_WAIT(wait);
#else
	DEFINE_WAIT(wait);
#endif
	int tag;
	unsigned int flags;
	unsigned int mas_flags;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	flags = data->cmd_flags;
	mas_flags = data->mas_io_flag;
#else
	flags = mas_flags = data->io_flag;
#endif

	if (mas_flags & REQ_VIP)
		ufs_mq_inc_vip_wait_cnt(data);

	if (ufs_sbitmap_is_fg(data))
		data->wait_tag_start = ktime_get();

	bs = &bt->ws[0];
	do {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		sbitmap_prepare_to_wait(bt, bs, &wait, TASK_UNINTERRUPTIBLE);
#else
		prepare_to_wait(&bs->wait, &wait, TASK_UNINTERRUPTIBLE);
#endif

		tag = ufs_try_get_tag(data, bt, hctx);
		if (tag != -1)
			break;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5,10,0))
		blk_mq_put_ctx(data->ctx);
#endif
		if (ufs_sbitmap_is_fg(data)) {
			if (!io_schedule_timeout(1))
				reset_vip_wait_cnt(data);
		} else {
			io_schedule();
		}

		data->ctx = blk_mq_get_ctx(data->q);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		data->hctx = blk_mq_map_queue(data->q, flags, data->ctx);
#else
		data->hctx = blk_mq_map_queue(data->q, data->ctx->cpu);
#endif
		if (!data->hctx)
			break;

		if (likely(hctx == data->hctx))
			goto finish_wait;

		if (likely(flags & REQ_SYNC)) {
			if (likely(!(flags & REQ_FG_META)))
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
				bt = data->hctx->tags->bitmap_tags;
#else
				bt = &data->hctx->tags->bitmap_tags;
#endif
			else
				bt = &data->hctx->tags->highprio_tags;
		} else {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
			bt = data->hctx->tags->breserved_tags;
#else
			bt = &data->hctx->tags->breserved_tags;
#endif
		}
		hctx = data->hctx;
finish_wait:
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		sbitmap_finish_wait(bt, bs, &wait);
#else
		finish_wait(&bs->wait, &wait);
#endif
	} while (1);

	if (mas_flags & REQ_VIP)
		ufs_mq_dec_vip_wait_cnt(data);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	sbitmap_finish_wait(bt, bs, &wait);
#else
	finish_wait(&bs->wait, &wait);
#endif

	return (unsigned int)tag;
}

unsigned int ufs_tagset_bt_get(
	struct blk_mq_alloc_data *data, struct sbitmap_queue *bt,
	struct blk_mq_hw_ctx *hctx)
{
	int tag;

	if (!hctx)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		return BLK_MQ_NO_TAG;
#else
		return BLK_MQ_TAG_FAIL;
#endif

	tag = ufs_sbitmap_queue_get(data, bt);
	if (likely(tag != -1))
		return (unsigned int)tag;

#ifdef CONFIG_MAS_UNISTORE_PRESERVE
	if (blk_queue_query_unistore_enable(data->q) &&
		(data->mas_io_flag & MAS_REQ_RECOVERY))
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		return BLK_MQ_NO_TAG;
#else
		return BLK_MQ_TAG_FAIL;
#endif
#endif

	return ufs_tagset_bt_get_slowpath(data, bt, hctx);
}

#ifdef CONFIG_MAS_UNISTORE_PRESERVE
static unsigned int ufs_tagset_bt_get_slowpath_unistore(
	struct blk_mq_alloc_data *data, struct sbitmap_queue *bt,
	struct blk_mq_hw_ctx *hctx, bool *highprio)
{
	struct sbq_wait_state *bs = NULL;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	DEFINE_SBQ_WAIT(wait);
#else
	DEFINE_WAIT(wait);
#endif
	int tag = -1;
	unsigned int flags;

	bs = &bt->ws[0];
	do {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		sbitmap_prepare_to_wait(bt, bs, &wait, TASK_UNINTERRUPTIBLE);
#else
		prepare_to_wait(&bs->wait, &wait, TASK_UNINTERRUPTIBLE);
#endif

		if (!(data->mas_io_flag & MAS_REQ_LBA) &&
			mas_blk_match_expected_lba(data->q, data->bio)) {
			data->mas_io_flag |= MAS_REQ_LBA;
			bt = &data->hctx->tags->highprio_tags;
			*highprio = true;
		}

		if (mas_blk_is_section_ready(data->q, data->bio)) {
			tag = ufs_try_get_tag(data, bt, hctx);
			if (tag != -1)
				break;
		}
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		flags = data->cmd_flags;
#else
		flags = data->io_flag;
		blk_mq_put_ctx(data->ctx);
#endif

		io_schedule_timeout(HZ/10); /* 0.1 seconds */

		data->ctx = blk_mq_get_ctx(data->q);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		data->hctx = blk_mq_map_queue(data->q, data->cmd_flags, data->ctx);
#else
		data->hctx = blk_mq_map_queue(data->q, data->ctx->cpu);
#endif
		if (!data->hctx)
			break;

		if (likely(hctx == data->hctx))
			goto finish_wait;

		if (!(flags & REQ_FG_META) &&
			!(data->mas_io_flag & MAS_REQ_LBA))
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
			bt = data->hctx->tags->bitmap_tags;
#else
			bt = &data->hctx->tags->bitmap_tags;
#endif
		else
			bt = &data->hctx->tags->highprio_tags;

		hctx = data->hctx;
finish_wait:
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		sbitmap_finish_wait(bt, bs, &wait);
#else
		finish_wait(&bs->wait, &wait);
#endif
	} while (1);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	sbitmap_finish_wait(bt, bs, &wait);
#else
	finish_wait(&bs->wait, &wait);
#endif

	return (unsigned int)tag;
}

unsigned int ufs_tagset_bt_get_unistore(
	struct blk_mq_alloc_data *data, bool *highprio)
{
	int tag = 0;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	struct sbitmap_queue *bt = data->hctx->tags->bitmap_tags;
#else
	struct sbitmap_queue *bt = &data->hctx->tags->bitmap_tags;
#endif
	struct blk_mq_hw_ctx *hctx = data->hctx;

	if (!hctx)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		return BLK_MQ_NO_TAG;
#else
		return BLK_MQ_TAG_FAIL;
#endif

	tag = ufs_sbitmap_queue_get(data, bt);
	if (likely(tag != -1))
		return (unsigned int)tag;

	return ufs_tagset_bt_get_slowpath_unistore(data, bt, hctx, highprio);
}
#endif

static int ufs_tagset_init_bitmap_tags(
	struct blk_mq_tags *tags, int node, int alloc_policy)
{
	unsigned int depth = tags->nr_tags - tags->nr_reserved_tags -
			     tags->nr_high_prio_tags;
	bool round_robin = alloc_policy == BLK_TAG_ALLOC_RR;

	pr_err("depth = %d, reserved = %d, high prio = %d \r\n", depth,
		tags->nr_reserved_tags, tags->nr_high_prio_tags);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	if (sbitmap_queue_init_node(&tags->__bitmap_tags, depth, -1, round_robin,
		    GFP_KERNEL, node))
#else
	if (sbitmap_queue_init_node(&tags->bitmap_tags, depth, -1, round_robin,
				GFP_KERNEL, node))
#endif
		goto enomem;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	if (sbitmap_queue_init_node(&tags->__breserved_tags,
		    tags->nr_reserved_tags, -1, round_robin, GFP_KERNEL, node))
#else
	if (sbitmap_queue_init_node(&tags->breserved_tags,
				tags->nr_reserved_tags, -1, round_robin, GFP_KERNEL, node))
#endif
		goto enomem1;

	if (sbitmap_queue_init_node(&tags->highprio_tags,
		    tags->nr_high_prio_tags, -1, round_robin, GFP_KERNEL, node))
		goto enomem2;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	tags->bitmap_tags = &tags->__bitmap_tags;
	tags->breserved_tags = &tags->__breserved_tags;
#endif
	tags->tags_id_offset = 0;
	tags->reserved_tags_id_offset = depth;
	tags->high_prio_tags_id_offset = tags->nr_reserved_tags + depth;
	return 0;

enomem2:
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	sbitmap_queue_free(tags->breserved_tags);
#else
	sbitmap_queue_free(&tags->breserved_tags);
#endif
enomem1:
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	sbitmap_queue_free(&tags->__bitmap_tags);
#else
	sbitmap_queue_free(&tags->bitmap_tags);
#endif
enomem:
	pr_err("%s: error nomem\n", __func__);
	return -ENOMEM;
}

/* caller make sure input params are valid */
void ufs_tagset_all_tag_busy_iter(
	struct blk_mq_tags *tags, busy_tag_iter_fn *fn, const void *priv)
{
	struct bt_tags_iter_data iter_data;

	iter_data.tags = tags;
	iter_data.fn = fn;
	iter_data.data = (void *)priv;

	iter_data.reserved = false;
	iter_data.prior = false;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	ufs_tagset_bt_tags_for_each(tags->bitmap_tags, &iter_data);
#else
	ufs_tagset_bt_tags_for_each(&tags->bitmap_tags, &iter_data);
#endif

	if (tags->nr_high_prio_tags) {
		iter_data.prior = true;
		ufs_tagset_bt_tags_for_each(&tags->highprio_tags, &iter_data);
	}

	if (tags->nr_reserved_tags) {
		iter_data.reserved = true;
		iter_data.prior = false;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		ufs_tagset_bt_tags_for_each(tags->breserved_tags, &iter_data);
#else
		ufs_tagset_bt_tags_for_each(&tags->breserved_tags, &iter_data);
#endif
	}
}

void ufs_tagset_free_tags(struct blk_mq_tags *tags)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	sbitmap_queue_free(tags->bitmap_tags);
	sbitmap_queue_free(tags->breserved_tags);
#else
	sbitmap_queue_free(&tags->bitmap_tags);
	sbitmap_queue_free(&tags->breserved_tags);
#endif
	sbitmap_queue_free(&tags->highprio_tags);
	kfree(tags);
}

int ufs_mq_tag_wakeup_all(struct blk_mq_tags *tags)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	sbitmap_queue_wake_all(tags->bitmap_tags);
	sbitmap_queue_wake_all(tags->breserved_tags);
#else
	sbitmap_queue_wake_all(&tags->bitmap_tags);
	sbitmap_queue_wake_all(&tags->breserved_tags);
#endif
	sbitmap_queue_wake_all(&tags->highprio_tags);
	return 0;
}

struct blk_mq_tags *ufs_tagset_init_tags(
	unsigned int total_tags, unsigned int reserved_tags,
	unsigned int high_prio_tags, int node, int alloc_policy)
{
	struct blk_mq_tags *tags = NULL;
	int ret;

	tags = kzalloc_node(sizeof(*tags), GFP_KERNEL, node);
	if (!tags)
		return NULL;

	tags->nr_tags = total_tags;
	tags->nr_reserved_tags = reserved_tags;
	tags->nr_high_prio_tags = high_prio_tags;

	spin_lock_init(&tags->lock);
	ret = ufs_tagset_init_bitmap_tags(tags, node, alloc_policy);
	if (ret) {
		pr_err("Failed to init tagset bitmaps!\n");
		kfree(tags);
		return NULL;
	}

	return tags;
}
