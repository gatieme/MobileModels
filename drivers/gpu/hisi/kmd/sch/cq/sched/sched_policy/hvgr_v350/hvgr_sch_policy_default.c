/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_cq_schedule.h"

#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/list.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/moduleparam.h>
#include <securec.h>

#include "hvgr_regmap.h"

#include "apicmd/hvgr_kmd_defs.h"
#include "hvgr_dm_api.h"
#include "hvgr_mmu_api.h"
#include "mem/hvgr_as.h"
#include "hvgr_mem_api.h"
#include "hvgr_sch_policy_manager.h"
#include "hvgr_sch_policy_default.h"

#include "hvgr_cq_driver_base.h"
#include "hvgr_wq.h"
#include "hvgr_msync.h"
#include "hvgr_softjob.h"
#include "hvgr_cq_queue.h"
#include "hvgr_log_api.h"
#include "hvgr_asid_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_cq_debug_switch.h"
#include "hvgr_cq.h"

static void hvgr_get_queue_pri_tbl(struct hvgr_cq_ctx * const cq_ctx, uint32_t *weight,
	uint32_t *real)
{
	struct cq_sw_writeable_context *sw_wr_ctx;

	sw_wr_ctx = cq_ctx->sw_wr_ctx;
	if (unlikely(sw_wr_ctx == NULL))
		return;

	hvgr_get_priority_cfg(cq_ctx->priority, weight, real);
}

static struct hvgr_cq_ctx *hvgr_sch_dequque_cq_ctx(struct cq_pending *pending_queue)
{
	struct list_head *cq_item = NULL;
	struct hvgr_cq_ctx *cq_ctx = NULL;

	cq_item = pending_queue->pending_list.next;
	list_del(cq_item);
	cq_ctx = container_of(cq_item, struct hvgr_cq_ctx, pending_item);
	return cq_ctx;
}

static inline bool hvgr_sch_is_clear_quque_count(struct hvgr_cq_dev * const gcqctx,
	struct cq_pending *pending_queue)
{
	if (pending_queue->real == 1 && gcqctx->real_counter_sum == gcqctx->real_weight_sum)
		return true;

	if (pending_queue->real == 0 && gcqctx->no_real_counter_sum == gcqctx->no_real_weight_sum)
		return true;
	return false;
}

static struct hvgr_cq_ctx *hvgr_sch_weight_round_robin(struct hvgr_device * const gdev,
	uint32_t *cnt_sum, uint32_t real)
{
	int idx;
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	struct cq_pending *pending_queue = NULL;
	struct hvgr_cq_ctx *cq_ctx = NULL;
	struct hvgr_cq_ctx *zero_w_cq_ctx = NULL;

	hvgr_info(gdev, HVGR_CQ, "%s enter: sum = %u, real = %u", __func__, *cnt_sum, real);

	for (idx = CQ_PRIORITY_MAX - 1; idx >= 0; idx--) {
		pending_queue = &gcqctx->pending_queue[idx];
		if (pending_queue->real != real)
			continue;
		hvgr_info(gdev, HVGR_CQ, "%s begin: sum = %u, priority = %u,"
			"counter = %u, weight = %u", __func__, *cnt_sum, idx,
			pending_queue->dequeue_counter, pending_queue->weight);
		if (pending_queue->dequeue_counter < pending_queue->weight) {
			if (list_empty(&pending_queue->pending_list)) {
				hvgr_info(gdev, HVGR_CQ, "%s, pending list empry", __func__);
				*cnt_sum +=
					pending_queue->weight - pending_queue->dequeue_counter;
				pending_queue->dequeue_counter = pending_queue->weight;
			} else {
				hvgr_info(gdev, HVGR_CQ, "%s pending list not empry", __func__);
				pending_queue->dequeue_counter++;
				(*cnt_sum)++;
				cq_ctx = hvgr_sch_dequque_cq_ctx(pending_queue);
				break;
			}
		} else {
			/*
			 * When the queue whose weight is not zero is empty, the queue whose weight
			 * is zero is scheduled.
			 */
			if (pending_queue->weight != 0)
				continue;
			if (list_empty(&pending_queue->pending_list))
				continue;
			/* By design, there is only one priority queue with a weight of zero. */
			zero_w_cq_ctx = hvgr_sch_dequque_cq_ctx(pending_queue);
			hvgr_info(gdev, HVGR_CQ, "%s zero weight queue scheduled", __func__);
		}
		hvgr_info(gdev, HVGR_CQ, "%s after: sum = %u, priority = %u,"
			"counter = %u, weight = %u", __func__, *cnt_sum, idx,
			pending_queue->dequeue_counter, pending_queue->weight);
	}
	hvgr_info(gdev, HVGR_CQ, "%s exit: sum = %u, real = %u", __func__, *cnt_sum, real);
	cq_ctx = cq_ctx == NULL ? zero_w_cq_ctx : cq_ctx;
	return cq_ctx;
}

static struct hvgr_cq_ctx *hvgr_sch_dequeue_from_pending(struct hvgr_device * const gdev)
{
	int idx;
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	struct cq_pending *pending_queue = NULL;
	struct hvgr_cq_ctx *cq_ctx = NULL;

	/* Real time queue first shcedule. */
	cq_ctx = hvgr_sch_weight_round_robin(gdev, &gcqctx->real_counter_sum,
		HVGR_SCHED_PRI_REAL_TIME);
	if (cq_ctx != NULL)
		goto out;

	/* No real time queue second schedule. */
	cq_ctx = hvgr_sch_weight_round_robin(gdev, &gcqctx->no_real_counter_sum,
		HVGR_SCHED_PRI_NO_REAL_TIME);
out:
	for (idx = CQ_PRIORITY_MAX - 1; idx >= 0; idx--) {
		pending_queue = &gcqctx->pending_queue[idx];
		if (hvgr_sch_is_clear_quque_count(gcqctx, pending_queue))
			pending_queue->dequeue_counter = 0;
	}

	if (gcqctx->real_counter_sum == gcqctx->real_weight_sum)
		gcqctx->real_counter_sum = 0;

	if (gcqctx->no_real_counter_sum == gcqctx->no_real_weight_sum)
		gcqctx->no_real_counter_sum = 0;

	return cq_ctx;
}

static struct hvgr_cq_ctx *hvgr_sch_policy_dequeue(struct hvgr_device * const gdev)
{
	struct hvgr_cq_ctx *cq_ctx = NULL;
	bool repeat = false;

	cq_ctx = hvgr_sch_dequeue_from_pending(gdev);
	/* repeat 2 times for scena of  0 0 6 0 0. */
	if ((cq_ctx == NULL) && !repeat) {
		repeat = true;
		cq_ctx = hvgr_sch_dequeue_from_pending(gdev);
	}

	return cq_ctx;
}

static uint32_t hvgr_sch_policy_get_channel(struct hvgr_cq_dev * const gcqctx,
	struct hvgr_cq_ctx * const cq_ctx)
{
	uint32_t min_weight = 0xff;
	uint32_t chn;
	uint32_t channel = CQ_CHANNEL_ID_INVALID;
	uint32_t real = 0;
	uint32_t weight = 0;
	uint32_t run_q_real;
	uint32_t run_q_weight;

	hvgr_get_queue_pri_tbl(cq_ctx, &weight, &real);
	for (chn = 0; chn < CQ_CHANNEL_NUM; chn++) {
		struct hvgr_cq_ctx *running_cq = NULL;

		if (unlikely(!gcqctx->channel_info[chn].available))
			continue;

		running_cq = gcqctx->channel_info[chn].running_queue;
		if (running_cq == NULL) {
			channel = chn;
			break;
		}
		/* New queue real is 0, no preemption. */
		if (real == 0)
			continue;

		run_q_real = 0;
		run_q_weight = -1;
		hvgr_get_queue_pri_tbl(running_cq, &run_q_weight, &run_q_real);
		/* Run quque real is 1, no preemption. */
		if (run_q_real == 1)
			continue;
		if (run_q_weight < min_weight) {
			hvgr_info(cq_ctx->ctx->gdev, HVGR_CQ,
				"%s High-privilege queue preempts low-privilege queue.\n", __func__);
			channel = running_cq->channel_id;
			min_weight = run_q_weight;
		}
	}
	return channel;
}

void hvgr_sch_policy_init(struct hvgr_cq_dev * const gcqctx)
{
	struct hvgr_sch_policy_opts *opts = &gcqctx->policy_opts[CQ_POLICY_REAL_WEIGHT_ROUND_ROBIN];

	opts->get_queue = hvgr_sch_policy_dequeue;
	opts->get_channel = hvgr_sch_policy_get_channel;
	gcqctx->cur_policy = CQ_POLICY_REAL_WEIGHT_ROUND_ROBIN;
}
