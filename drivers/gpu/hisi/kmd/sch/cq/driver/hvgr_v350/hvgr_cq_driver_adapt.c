/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_cq_driver_adapt.h"

#include <linux/kernel.h>
#include <linux/delay.h>
#include <securec.h>

#include "hvgr_cq_driver_base.h"
#include "hvgr_regmap.h"
#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_datan_api.h"

#include "hvgr_cq_debug_switch.h"
#include "hvgr_cq_schedule.h"
#include "hvgr_softjob.h"
#include "hvgr_cq_defs.h"
#include "hvgr_pm_api.h"
#include "dm/fcp/hvgr_fcp.h"
#include "hvgr_cq.h"
#include "hvgr_file.h"
#include "mem/hvgr_mem_zone.h"
#include "hvgr_kmd_defs.h"

#ifdef CONFIG_DFX_DEBUG_FS
#define CQ_DFX_ORDER_BUF_SIZE            cq_ringbuf_align(4096)
#define CQ_DFX_SYNC_BUF_SIZE             cq_ringbuf_align(1024 * 1024)
#define CQ_DFX_REPLAY_ORDER_BUF_SIZE     cq_ringbuf_align(4096)
#else
#define CQ_DFX_ORDER_BUF_SIZE            cq_ringbuf_align(1024)
#define CQ_DFX_SYNC_BUF_SIZE             cq_ringbuf_align(1024)
#define CQ_DFX_REPLAY_ORDER_BUF_SIZE     cq_ringbuf_align(1024)
#endif

static bool hvgr_cq_alloc_sw_dfxbuffer_memory(struct hvgr_ctx * const ctx,
	struct cq_sw_writeable_context *sw_wr_ctx);

static void hvgr_cq_free_sw_dfxbuffer_memory(struct hvgr_ctx * const ctx,
	struct cq_sw_writeable_context *sw_wr_ctx);

#ifdef CONFIG_DFX_DEBUG_FS
static void hvgr_cq_process_both_entry_buf(struct hvgr_ctx * const ctx,
	struct hvgr_cq_ctx * const cq_ctx);
#endif

static struct hvgr_cq_prioriy_cfg cq_pri_tbl[] = {
	{CQ_GLOBAL_PRIORITY_LOW_COMPUTE_L, 1, 0},
	{CQ_GLOBAL_PRIORITY_LOW_COMPUTE_H, 3, 0},
	{CQ_GLOBAL_PRIORITY_MEDIUM_COMPUTE_L, 6, 0},
	{CQ_GLOBAL_PRIORITY_MEDIUM_COMPUTE_H, 9, 0},
	{CQ_GLOBAL_PRIORITY_HIGH_COMPUTE_L, 12, 0},
	{CQ_GLOBAL_PRIORITY_HIGH_COMPUTE_H, 15, 0},
	{CQ_GLOBAL_PRIORITY_REALTIME_COMPUTE_L, 0, 1},
	{CQ_GLOBAL_PRIORITY_REALTIME_COMPUTE_H, 4, 1},
};

void hvgr_get_priority_cfg(uint32_t pri, uint32_t *weight, uint32_t *real)
{
	if (unlikely(pri >= ARRAY_SIZE(cq_pri_tbl)))
		return;
	*weight = cq_pri_tbl[pri].weight;
	*real = cq_pri_tbl[pri].real;
}

static void hvgr_cq_config_priority(struct hvgr_device * const gdev)
{
	uint32_t pri;
	uint32_t weight = 0;
	uint32_t real = 0;

	for (pri = 0; pri < ARRAY_SIZE(cq_pri_tbl); pri++) {
		/* The weight ranges from 0 to 15, four bits are required. */
		weight |= (cq_pri_tbl[pri].weight << (pri << 0x2));
		real |= (cq_pri_tbl[pri].real << pri);
	}
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ENTRYS_WEIGHT), weight);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ENTRYS_REALTIME), real);
}

void hvgr_cq_affinity_config(struct hvgr_device * const gdev, uint32_t channel_id)
{
	int sub_chn;
	uint32_t core_mask = hvgr_pm_get_availiable_cores(gdev);

	hvgr_cq_compute_affinity_init(gdev, channel_id, core_mask);

	for (sub_chn = RENDER_IDX; sub_chn < SUBCHN_MAX_IDX; sub_chn++)
		if (sub_chn != COMPUTE_IDX) {
			hvgr_write_reg(gdev,
				cq_control_reg(gdev,
				cq_bind_affinity_sub_channel(channel_id, sub_chn)), core_mask);
			hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
				gdev->dm_dev.fcp_data->ctx, cq_control_reg(gdev,
				cq_bind_affinity_sub_channel(channel_id, sub_chn)), core_mask);
		}
}

void hvgr_cq_multi_chain_enable_init(struct hvgr_device * const gdev,
	struct hvgr_cq_dev * const gcqctx, uint32_t channel_id)
{
#ifdef HVGR_BIND_CFG_OPEN
	uint32_t value;

	value = hvgr_read_reg(gdev,
		cq_control_reg(gdev, cq_bind_config(channel_id, RENDER_IDX)));
	cq_set_u32_bit4(value, gcqctx->hw_cfg.cq_multi_chain_enable);
	hvgr_write_reg(gdev,
		cq_control_reg(gdev, cq_bind_config(channel_id, RENDER_IDX)), value);
	hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
			gdev->dm_dev.fcp_data->ctx, cq_bind_config(channel_id, RENDER_IDX), value);
#endif
}

void hvgr_cq_compute_affinity_init(struct hvgr_device * const gdev,
	uint32_t channel_id, uint32_t core_mask)
{
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	uint32_t cq_cl_affinity = gcqctx->hw_cfg.cq_cl_affinity;

	/* cq_cl_affinity must be part of core_mask */
	cq_cl_affinity &= core_mask;
	if (cq_cl_affinity == 0) {
		hvgr_err(gdev, HVGR_CQ, "[cq]: %s: core_mask=%d, cq_cl_affinity=%d, not right",
			__func__, core_mask, gcqctx->hw_cfg.cq_cl_affinity);
		/* when config fail, report and recover config. */
		cq_cl_affinity = core_mask;
	}

	hvgr_write_reg(gdev,
		cq_control_reg(gdev, cq_bind_affinity_sub_channel(channel_id, COMPUTE_IDX)),
		cq_cl_affinity);
	hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
		gdev->dm_dev.fcp_data->ctx, cq_control_reg(gdev,
		cq_bind_affinity_sub_channel(channel_id, COMPUTE_IDX)), cq_cl_affinity);
}

void hvgr_cq_set_affinity(struct hvgr_device * const gdev,
	uint32_t channel_id, uint32_t core_mask)
{
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	uint32_t cq_cl_affinity = gcqctx->hw_cfg.cq_cl_affinity;
	uint32_t idx;

	/* cq_cl_affinity must be part of core_mask */
	cq_cl_affinity &= core_mask;
	if (cq_cl_affinity == 0) {
		hvgr_err(gdev, HVGR_CQ, "[cq]: %s: core_mask=%d, cq_cl_affinity=%d, not right",
			__func__, core_mask, gcqctx->hw_cfg.cq_cl_affinity);
		/* when config fail, report and recover config. */
		cq_cl_affinity = core_mask;
	}

	for (idx = RENDER_IDX; idx < SUBCHN_MAX_IDX; ++idx) {
		if (idx == COMPUTE_IDX) {
			hvgr_write_reg(gdev, cq_control_reg(gdev,
				cq_bind_affinity_sub_channel(channel_id, idx)), cq_cl_affinity);
			hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ,
				KDATAN_TL_WRITE_REG, gdev->dm_dev.fcp_data->ctx,
				cq_control_reg(gdev,
				cq_bind_affinity_sub_channel(channel_id, idx)), cq_cl_affinity);
		} else {
			hvgr_write_reg(gdev, cq_control_reg(gdev,
				cq_bind_affinity_sub_channel(channel_id, idx)), core_mask);
			hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ,
				KDATAN_TL_WRITE_REG, gdev->dm_dev.fcp_data->ctx,
				cq_control_reg(gdev,
				cq_bind_affinity_sub_channel(channel_id, idx)), core_mask);
		}
	}
}

static void hvgr_set_cq_bind_config(union reg_cq_bind_config *config,
	enum hvgr_cq_subchn_index index)
{
	/* Set as user guide render:0x3, bin:0x1, compute:0x4, bvhg:0x0, rt:0x8 */
	uint32_t basic_flush_type[SUBCHN_MAX_IDX] = {0x3, 0x1, 0x4, 0x0, 0x8};
	/* (index == RENDER_IDX) ? 0 : 1 , for now enable barrier on all channel */
	config->st.barrier = CQ_BIND_BARRIER_ENABLE;
	config->st.end_flush_l2 =
		(index == BIN_IDX) ? CQ_BIND_ENDFLUSH_NO : CQ_BIND_ENDFLUSH_CLEAN_AND_INVALIDATE;
	config->st.end_flush_shader_type = basic_flush_type[index];
}

static void hvgr_cq_config_bind_cfg(struct hvgr_device * const gdev, uint32_t channel_id)
{
	union reg_cq_bind_config config;
	uint32_t index;

	for (index = RENDER_IDX; index < SUBCHN_MAX_IDX; index++) {
		config.value = hvgr_read_reg(gdev,
			cq_control_reg(gdev, cq_bind_config(channel_id, index)));
		hvgr_set_cq_bind_config(&config, index);
		hvgr_write_reg(gdev, cq_control_reg(gdev, cq_bind_config(channel_id, index)),
			config.value);
		hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ,
			KDATAN_TL_WRITE_REG, gdev->dm_dev.fcp_data->ctx,
			cq_control_reg(gdev, cq_bind_config(channel_id, index)), config.value);
	}
}

void hvgr_cq_hwcfg_init(struct hvgr_device * const gdev, uint32_t mode)
{
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	int chnid;

	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ENABLE), mode);
	for (chnid = 0; chnid < CQ_CHANNEL_NUM; chnid++) {
		hvgr_cq_multi_chain_enable_init(gdev, gcqctx, chnid);

		/* Affinity must precede bc_send_mode. */
		hvgr_cq_affinity_config(gdev, chnid);

		hvgr_cq_config_bind_cfg(gdev, chnid);

		hvgr_write_reg(gdev,
			cq_control_reg(gdev, cq_bind_waitcycle(chnid)),
				gcqctx->hw_cfg.cq_bind_waitcycle);
		hvgr_write_reg(gdev,
			cq_control_reg(gdev, cq_bind_empty_timeout(chnid)),
				gcqctx->hw_cfg.cq_queue_empty_timeout);
		hvgr_write_reg(gdev,
			cq_control_reg(gdev, cq_bind_sem_wait_timeout(chnid)),
				gcqctx->hw_cfg.cq_semp_wait_timeout);
	}

	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_DBG_EN), gcqctx->hw_cfg.work_mode);
	hvgr_info(gdev, HVGR_CQ, "[cq]: %s: cq_sch_mode=%u, bc_send_mode=%u, work_mode=%u",
		__func__, gcqctx->hw_cfg.cq_sch_mode, gcqctx->hw_cfg.bc_send_mode,
		gcqctx->hw_cfg.work_mode);
	/* Config priority */
	hvgr_cq_config_priority(gdev);
	/* sem_wait_polling_mode: set to 0 temporarily, hardware polling */
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_SEM_WAIT_POLLING_MODE),
		CQ_SEM_WAIT_MODE_POLLING);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_ENTRYS_OS), CQ_ENTRYS_OS_CFG);
#if CONFIG_HVGR_DFX_DATAN
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG), CQ_ENTRY_BOUNDARY_EN);
#endif
	/* config the ram size */
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_BINNING_RAM_SIZE), CQ_BINNING_RAM_SIZE_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_RENDER_RAM_SIZE), CQ_RENDER_RAM_SIZE_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_COMPUTE_RAM_SIZE), CQ_COMPUTER_RAM_SIZE_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_BVH_RAM_SIZE), CQ_BVH_RAM_SIZE_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_RT_RAM_SIZE), CQ_RT_RAM_SIZE_VALUE);

#if hvgr_version_ge(HVGR_V350)
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_MAX_RMU_COUNT), CQ_MAX_RMU_COUNT_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_MAX_RMU_SLICE_COUNT), CQ_MAX_RMU_SLICE_COUNT_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_MAX_VB_SHARP_COUNT), CQ_MAX_VB_SHARP_COUNT_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_RENDER_NODE_STYPE), CQ_RENDER_NODE_STYPE_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_MESH_NODE_STYPE), CQ_MESH_NODE_STYPE_VALUE);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_INTERNAL_UNIFORM_SIZE), CQ_INTERNAL_UNIFORM_SIZE_VALUE);
#endif
}

bool hvgr_cq_get_empty_flag(struct hvgr_device *gdev, uint32_t channel_id)
{
	union reg_cq_bind_entry_exe_status queue_status;

	queue_status.value =
		hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_entry_exe_status(channel_id)));
	return (queue_status.st.entry_exe_empty == 1) && (queue_status.st.queue_entry_empty == 1);
}

bool hvgr_cq_get_wait_flag(struct hvgr_device *gdev, uint32_t channel_id)
{
	union reg_cq_bind_entry_exe_status queue_status;

	queue_status.value =
		hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_entry_exe_status(channel_id)));
	return (queue_status.st.sem_wait_status) == 1;
}

static void hvgr_cq_get_profiling_timestamp(struct hvgr_device *gdev,
	struct token_callback_data *callback)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	struct timespec ts;

	getrawmonotonic(&ts);
#else
	struct timespec64 ts;

	ktime_get_raw_ts64(&ts);
#endif

	callback->profiling_data.soc_timestamp = hvgr_dm_get_soc_timestamp(gdev);
	callback->profiling_data.os_timestamp =
		(uint64_t)ts.tv_sec * 1000000000 + (uint64_t)ts.tv_nsec;
	hvgr_info(gdev, HVGR_CQ, "soc timestamp is %lu, os timestamp is %lu.",
		callback->profiling_data.soc_timestamp, callback->profiling_data.os_timestamp);
}

static void hvgr_cq_irq_do_notify(struct hvgr_cq_ctx * const cq_ctx, struct hvgr_device *gdev,
	uint32_t channel_id, enum protect_flag *flag)
{
	union reg_cq_bind_status_notify notify;
	struct token_callback_data *callback = NULL;
	unsigned long flags;

	notify.value = hvgr_read_reg(gdev,
		cq_control_reg(gdev, cq_bind_top_notify_info(channel_id)));

	while ((notify.st.entry_info_vld == 1) && (notify.st.entry_id != 0)) {
		if (unlikely(!hvgr_token_is_valid(cq_ctx->ctx, notify.st.entry_id)))
			return;

		hvgr_info(cq_ctx->ctx->gdev, HVGR_CQ, "%s token=%d, put:get(%d:%d)\n",
			__func__, notify.st.entry_id,
			cq_ctx->sw_wr_ctx->queue_put_index, cq_ctx->sw_wr_ctx->queue_get_index);

		hvgr_datan_jobtrace(cq_ctx->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_NEW_WAIT_IRQ,
			cq_ctx->ctx, cq_ctx->queue_id, channel_id,
			KDATAN_JOBTRACE_IRQ_NOTIFY_STATUS, notify.value);

		callback = cq_ctx->ctx->ctx_cq.token_callback[notify.st.entry_id];
		if (callback != NULL && callback->ctx != NULL) {
			/* We do not need to check hold_en when the callback->ctx is null. */
			spin_lock_irqsave(&callback->lock, flags);
			if ((callback->flags & HVGR_TOKEN_HOLD_EN_IN) != 0)
				*flag = CQ_PROTECT_MODE_IN;
			else if ((callback->flags & HVGR_TOKEN_HOLD_EN_OUT) != 0)
				*flag = CQ_PROTECT_MODE_OUT;
			else if ((callback->flags & HVGR_TOKEN_FREQ_HINT) != 0)
				callback->cq_ctx = cq_ctx;
			else
				*flag = CQ_PROTECT_MODE_INVALID;
			if ((callback->flags & HVGR_TOKEN_CL_PROFILING_EXEC) != 0 ||
				(callback->flags & HVGR_TOKEN_CL_PROFILING_COMPLETE) != 0)
				hvgr_cq_get_profiling_timestamp(cq_ctx->ctx->gdev, callback);
			spin_unlock_irqrestore(&callback->lock, flags);
		}

		hvgr_info(cq_ctx->ctx->gdev, HVGR_CQ, "%s hold_en =%d, channel_id=%d, token=%d",
			__func__, *flag, channel_id, notify.st.entry_id);
		hvgr_token_finish(cq_ctx, notify.st.entry_id);
		notify.value = hvgr_read_reg(gdev,
			cq_control_reg(gdev, cq_bind_top_notify_info(channel_id)));
	}
}

static void hvgr_cq_irq_do_subq(struct hvgr_cq_ctx * const cq_ctx,
	struct hvgr_device *gdev, uint32_t chnid, uint32_t sub_q_mask)
{
	uint32_t idx;
	union reg_cq_bind_status_subq status;
	struct token_callback_data *callback = NULL;
	unsigned long flags;

	for (idx = 0; idx < CQ_IRQ_STATUS_SUBQ_BIT_NUMS; idx++) {
		if ((sub_q_mask & (1u << idx)) == 0)
			continue;

		status.value = hvgr_read_reg(gdev,
			cq_control_reg(gdev, cq_bind_status_subq(chnid, idx)));
		while ((status.st.entry_info_vld == 1) && (status.st.entry_id != 0)) {
			hvgr_datan_jobtrace(cq_ctx->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_NEW_WAIT_IRQ,
				cq_ctx->ctx, cq_ctx->queue_id, chnid,
				KDATAN_JOBTRACE_IRQ_SUBQ0_STATUS + idx, status.value);
			hvgr_info(cq_ctx->ctx->gdev, HVGR_CQ,
				"%s token=%d, entry_type=%d, put:get(%d:%d)\n",
				__func__, status.st.entry_id, status.st.entry_type,
				cq_ctx->sw_wr_ctx->queue_put_index,
				cq_ctx->sw_wr_ctx->queue_get_index);

			/* If we found error token, break to avoid deadloop. */
			if (unlikely(!hvgr_token_is_valid(cq_ctx->ctx, status.st.entry_id))) {
				hvgr_info(cq_ctx->ctx->gdev, HVGR_CQ,
					"%s token=%d, idx=%d, channel=%d\n",
					__func__, status.st.entry_id, idx, chnid);
				break;
			}

			callback = cq_ctx->ctx->ctx_cq.token_callback[status.st.entry_id];
			if (callback != NULL) {
				spin_lock_irqsave(&callback->lock, flags);
				if ((callback->flags & HVGR_TOKEN_FREQ_HINT) != 0)
					callback->cq_ctx = cq_ctx;
				if ((callback->flags & HVGR_TOKEN_CL_PROFILING_EXEC) != 0 ||
					(callback->flags & HVGR_TOKEN_CL_PROFILING_COMPLETE) != 0)
					hvgr_cq_get_profiling_timestamp(cq_ctx->ctx->gdev, callback);
				spin_unlock_irqrestore(&callback->lock, flags);
			}

			hvgr_token_finish(cq_ctx, status.st.entry_id);
			status.value = hvgr_read_reg(gdev,
				cq_control_reg(gdev, cq_bind_status_subq(chnid, idx)));
		}
	}
}

static void hvgr_cq_irq_do_entry_boundary(struct hvgr_cq_ctx * const cq_ctx,
	struct hvgr_device *gdev, uint32_t chnid)
{
	union reg_cq_bind_status_boundary status;
	char *job_status[] = {
		"start",
		"done",
		"not availible",
		"stop"
	};

	status.value = hvgr_read_reg(gdev,
		cq_control_reg(gdev, cq_bind_entry_boundary_info(chnid)));
	while ((status.st.entry_info_vld == 1) && (status.st.entry_id != 0)) {
		hvgr_info(gdev, HVGR_CQ, "[Chn: %d qid: %u ctx_%u]: entry id: %d entry type: %d %s.\n",
			chnid, cq_ctx->queue_id, cq_ctx->ctx->id, status.st.entry_id,
			status.st.entry_type, job_status[status.st.job_chain_status]);
		hvgr_datan_jobtrace(cq_ctx->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_NEW_WAIT_IRQ,
			cq_ctx->ctx, cq_ctx->queue_id, chnid, KDATAN_JOBTRACE_IRQ_BOUNDARY_STATUS, status.value);
		hvgr_info(gdev, HVGR_CQ,"wml: boundary irq %u\n", status.value);
		status.value = hvgr_read_reg(gdev,
			cq_control_reg(gdev, cq_bind_entry_boundary_info(chnid)));
	}

	hvgr_info(gdev, HVGR_CQ, "[Chn: %d qid: %u ctx_%u]: entry id: %d entry type: %d %s.\n",
		chnid, cq_ctx->queue_id, cq_ctx->ctx->id, status.st.entry_id, status.st.entry_type,
		job_status[status.st.job_chain_status]);
}

static void hvgr_cq_irq_do_order_buf_full(struct hvgr_cq_ctx * const cq_ctx,
	struct hvgr_device *gdev, uint32_t chnid)
{
#ifdef CONFIG_DFX_DEBUG_FS
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	void *kva = NULL;

	if (!gcqctx->hw_cfg.cq_order_dump)
		return;

	if (atomic_read(&cq_ctx->is_order_buffer_inuse))
		return;

	atomic_set(&cq_ctx->is_order_buffer_inuse, true);
	cq_ctx->last_channel_id = chnid;

	if ((uint32_t)cq_ctx->ctx->pid == gcqctx->order_dump_pid || gcqctx->order_dump_pid == 0) {
		hvgr_info(gdev, HVGR_CQ, "order buf full pid[%u] chn[%u] dump.\n",
			cq_ctx->ctx->pid, chnid);

		queue_work(gdev->cq_dev.entry_dump_wq, &cq_ctx->order_dump_work);
	} else {
		kva = hvgr_cq_get_entry_buffer_kva(cq_ctx, ORDER_DUMP);
		hvgr_cq_clear_buf_full(kva, cq_ctx, ORDER_DUMP, false);
	}
#endif
}

static void hvgr_cq_irq_do_sync_buf_full(struct hvgr_cq_ctx * const cq_ctx,
	struct hvgr_device *gdev, uint32_t chnid)
{
#ifdef CONFIG_DFX_DEBUG_FS
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	void *kva = NULL;

	if (!gcqctx->hw_cfg.cq_sync_dump)
		return;

	if (atomic_read(&cq_ctx->is_sync_buffer_inuse))
		return;

	atomic_set(&cq_ctx->is_sync_buffer_inuse, true);
	cq_ctx->last_channel_id = chnid;

	if ((uint32_t)cq_ctx->ctx->pid == gcqctx->sync_dump_pid || gcqctx->sync_dump_pid == 0) {
		hvgr_info(gdev, HVGR_CQ, "sync buf full pid[%u] chn[%u] dump.\n",
			cq_ctx->ctx->pid, chnid);

		queue_work(gdev->cq_dev.entry_dump_wq, &cq_ctx->sync_dump_work);
	} else {
		kva = hvgr_cq_get_entry_buffer_kva(cq_ctx, SYNC_DUMP);
		hvgr_cq_clear_buf_full(kva, cq_ctx, SYNC_DUMP, false);
	}
#endif
}

static void hvgr_cq_irq_do_exe_empty(struct hvgr_cq_ctx * const cq_ctx,
	struct hvgr_device *gdev, uint32_t chnid)
{
}

static inline struct hvgr_cq_ctx *hvgr_cq_get_channel_ctx(struct hvgr_device *gdev,
	uint32_t channel_id)
{
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;

	return gcqctx->channel_info[channel_id].running_queue;
}

void hvgr_cq_schedule_do_channel_irq(struct hvgr_device * const gdev, uint32_t chn)
{
	union reg_cq_irq irq_state;
	bool sche_en = false;
	struct hvgr_cq_ctx *cq_ctx = hvgr_cq_get_channel_ctx(gdev, chn);
	enum protect_flag flag = CQ_PROTECT_MODE_INVALID;

	irq_state.value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_irq_status(chn)));

	if (unlikely(cq_ctx == NULL)) {
		hvgr_err(gdev, HVGR_CQ, "%s chn(%d) reg value 0x%x not right\n",
			__func__, chn, irq_state.value);
		hvgr_write_reg(gdev, cq_control_reg(gdev, cq_irq_clear(chn)), irq_state.value);
		return;
	}

	if ((irq_state.value & CQ_IRQ_STATUS_SUBQ_BIG_MASK) != 0) {
		hvgr_cq_irq_do_subq(cq_ctx, gdev, chn,
			irq_state.value >> CQ_IRQ_STATUS_SUBQ_BIT_START);
		sche_en = true;
	}

	if (irq_state.st.notify != 0) {
		hvgr_cq_irq_do_notify(cq_ctx, gdev, chn, &flag);
		sche_en = true;
	}

	if (irq_state.st.sync_buf_full != 0)
		hvgr_cq_irq_do_sync_buf_full(cq_ctx, gdev, chn);

	if (irq_state.st.order_buf_full != 0)
		hvgr_cq_irq_do_order_buf_full(cq_ctx, gdev, chn);

	if (irq_state.st.entry_boundary != 0)
		hvgr_cq_irq_do_entry_boundary(cq_ctx, gdev, chn);

	if (irq_state.st.entry_exe_empty != 0)
		hvgr_cq_irq_do_exe_empty(cq_ctx, gdev, chn);

	/* we resolve stop irq at last, to avoid irq left after stop.
	 * when we receive hold_en, we ignore current stop to enter or exit protect mode.
	 */
	if (irq_state.st.stop != 0) {
		hvgr_info(gdev, HVGR_CQ, "%s chn(%d) stop,qid=%u,ctx_%u\n",
			__func__, chn, cq_ctx->queue_id, cq_ctx->ctx->id);
		hvgr_cq_irq_do_stop(cq_ctx, gdev, chn);
		sche_en = true;
	}

	/* clear the entry dump irq when dump completed */
	irq_state.st.sync_buf_full = 0;
	irq_state.st.order_buf_full = 0;
	hvgr_write_reg(gdev, cq_control_reg(gdev, cq_irq_clear(chn)), irq_state.value);
	if (sche_en)
		hvgr_cq_schedule_channel(gdev, chn, flag, false);
}

void hvgr_cq_dump_debug_register(struct hvgr_device * const gdev)
{
	/* dupm register */
	hvgr_debug(gdev, HVGR_CQ, "  CQ_BIND_SUBCHN_OS=0x%08x    0x%08x    0x%08x    0x%08x",
		hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_subchn_os(0))),
		hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_subchn_os(1))),
		hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_subchn_os(2))),
		hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_subchn_os(3))));
	hvgr_debug(gdev, HVGR_CQ, "  CQ_DBG_EN=0x%08x    CQ_DFX_CONFIG=0x%08x",
		hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DBG_EN)),
		hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG)));

	hvgr_datan_dump_chain_state(gdev);
}

int hvgr_cq_register_irq(struct hvgr_device * const gdev)
{
	if (hvgr_register_irq(gdev, CQ_IRQ, hvgr_cq_irq_handler) != 0) {
		hvgr_err(gdev, HVGR_CQ, "Register cq irq handler failed.");
		return -1;
	}
	return 0;
}

void hvgr_cq_alloc_sw_dfx_memory(struct hvgr_ctx * const ctx,
	struct cq_sw_writeable_context *sw_wr_ctx)
{
	/* alloc dfx buffer memory */
	if (hvgr_cq_alloc_sw_dfxbuffer_memory(ctx, sw_wr_ctx) == false)
		hvgr_err(ctx->gdev, HVGR_CQ, "alloc dfx buffer fail ctx[%u].", ctx->id);
}

void hvgr_cq_free_sw_dfx_memory(struct hvgr_ctx * const ctx,
	struct hvgr_cq_ctx * const cq_ctx)
{
	if (unlikely((ctx == NULL) || (cq_ctx == NULL)))
		return;

#ifdef CONFIG_DFX_DEBUG_FS
	hvgr_cq_process_both_entry_buf(ctx, cq_ctx);
#endif
	hvgr_cq_free_sw_dfxbuffer_memory(ctx, cq_ctx->sw_wr_ctx);
}

#ifdef CONFIG_DFX_DEBUG_FS
void *hvgr_cq_get_entry_buffer_kva(struct hvgr_cq_ctx * const cq_ctx, bool is_order)
{
	struct cq_sw_writeable_context *cq_wr_ctx = NULL;
	struct hvgr_mem_area *area = NULL;
	uint64_t entry_buf_ptr;

	if (unlikely(cq_ctx == NULL))
		return NULL;

	cq_wr_ctx = cq_ctx->sw_wr_ctx;
	if (unlikely(cq_wr_ctx == NULL))
		return NULL;

	entry_buf_ptr = is_order ?
		cq_wr_ctx->dfx_buf_info.order_buf_ptr : cq_wr_ctx->dfx_buf_info.sync_buf_ptr;
	area = hvgr_mem_zone_find_area_by_gva_range(&cq_ctx->ctx->mem_ctx, entry_buf_ptr);
	if (area == NULL)
		return NULL;

	if (((area->attribute & HVGR_MEM_ATTR_KMD_ACCESS) == 0) || (area->kva == 0)) {
		hvgr_err(cq_ctx->ctx->gdev, HVGR_CQ,
			"find kva error, buf[%pK], attr[0x%lx], kva[%pK], is_order[%u].\n",
			entry_buf_ptr, area->attribute, area->kva, is_order);
		return NULL;
	}

	return u64_to_ptr(entry_buf_ptr - area->uva + area->kva);
}

void hvgr_cq_clear_buf_full(void *buffer, struct hvgr_cq_ctx * const cq_ctx,
	bool is_order, bool need_lock)
{
	unsigned long flags;
	struct hvgr_device * const gdev = cq_ctx->ctx->gdev;
	uint32_t channel_id = cq_ctx->last_channel_id;
	uint32_t size = is_order ? CQ_DFX_ORDER_BUF_SIZE : CQ_DFX_SYNC_BUF_SIZE;
	uint32_t irq_bit = is_order ? CQ_IRQ_ORDER_BUF_FULL_BIT : CQ_IRQ_SYNC_BUF_FULL_BIT;
	atomic_t *buffer_inuse =
		is_order ? &cq_ctx->is_order_buffer_inuse : &cq_ctx->is_sync_buffer_inuse;

	if (buffer != NULL)
		memset_s(buffer, size, 0, size);

	if (need_lock)
		spin_lock_irqsave(&gdev->cq_dev.schedule_lock, flags);

	atomic_set(buffer_inuse, false);
	hvgr_write_reg(gdev, cq_control_reg(gdev, cq_irq_clear(channel_id)), 1 << irq_bit);

	if (need_lock)
		spin_unlock_irqrestore(&gdev->cq_dev.schedule_lock, flags);
}

static bool hvgr_cq_get_entry_dump_file_name(char *file_name, int len,
	struct hvgr_cq_ctx * const cq_ctx, bool is_order)
{
	char *dump_type[] = {
		"sync",
		"order"
	};

	if (file_name == NULL)
		return false;

	if (!hvgr_file_make_dir(HVGR_ENTRY_DMUP_DIR, HVGR_ENTRY_DMUP_DIR_MODE)) {
		hvgr_err(cq_ctx->ctx->gdev, HVGR_CQ, "%s make dir fail, pid[%d], qid[%u]\n",
			__func__, cq_ctx->ctx->pid, cq_ctx->queue_id);
		return false;
	}

	(void)snprintf_s(file_name, len, len - 1, HVGR_ENTRY_DMUP_DIR HVGR_ENTRY_DMUP_FILE,
		cq_ctx->ctx->pid, cq_ctx->queue_id, dump_type[is_order]);
	return true;
}

static uint32_t hvgr_cq_get_entry_dump_size(void *buffer, bool is_order, bool is_full)
{
	uint32_t *size_used = NULL;
	uint32_t *data = NULL;
	uint32_t full_size = is_order ? CQ_DFX_ORDER_BUF_SIZE : CQ_DFX_SYNC_BUF_SIZE;

	/* buffer full irq, dump max len */
	if (is_full)
		return full_size;

	/* no len && no data, do not dump */
	size_used = (uint32_t *)buffer;
	data = (uint32_t *)(buffer + HVGR_ENTRY_DUMP_HEAD_LEN);
	if ((*size_used == 0) && (*data == 0))
		return 0;

	/* vaild len, compute dump size */
	if (*size_used != 0)
		return (*size_used) * sizeof(uint32_t) + HVGR_ENTRY_DUMP_HEAD_LEN;

	return full_size;
}

static void hvgr_cq_entry_buff_dump(void *buffer, struct hvgr_cq_ctx * const cq_ctx,
	char *file_name, bool is_order, bool is_full)
{
	uint32_t buffer_size;
	struct file *data_file = NULL;
	mm_segment_t old_fs;
	struct hvgr_device * const gdev = cq_ctx->ctx->gdev;

	buffer_size = hvgr_cq_get_entry_dump_size(buffer, is_order, is_full);
	if (buffer_size == 0) {
		hvgr_info(gdev, HVGR_CQ, "[%s] nothing to dump.\n", file_name);
		return;
	}

	old_fs = get_fs();
	set_fs(KERNEL_DS);
	data_file = filp_open(file_name, O_CREAT | O_WRONLY | O_APPEND, S_IRUGO | S_IWUSR);
	if (IS_ERR_OR_NULL(data_file)) {
		set_fs(old_fs);
		hvgr_err(gdev, HVGR_CQ, "file open [%s] error.\n", file_name);
		return;
	}

	hvgr_info(gdev, HVGR_CQ, "start dump[%s], address[%pK], len[%u].\n",
		file_name, buffer, buffer_size);
	hvgr_file_write_to_file(data_file, (char *)buffer, buffer_size, &data_file->f_pos);
	vfs_fsync(data_file, 0);

	filp_close(data_file, NULL);
	set_fs(old_fs);
	return;
}

void hvgr_cq_ordersync_entry_dump(struct hvgr_device * const gdev,
	struct hvgr_cq_ctx * const cq_ctx, bool is_order, bool is_full)
{
	char file_name[MAX_FILE_NAME_SIZE] = {0};
	void *kva = NULL;
	struct mutex *dump_lock = is_order ?
		(&cq_ctx->dump_order_lock) : (&cq_ctx->dump_sync_lock);

	mutex_lock(dump_lock);
	kva = hvgr_cq_get_entry_buffer_kva(cq_ctx, is_order);
	if (kva == NULL)
		goto END;

	if (!hvgr_cq_get_entry_dump_file_name(file_name, MAX_FILE_NAME_SIZE, cq_ctx, is_order))
		goto END;

	hvgr_cq_entry_buff_dump(kva, cq_ctx, file_name, is_order, is_full);

END:
	mutex_unlock(dump_lock);
	hvgr_cq_clear_buf_full(kva, cq_ctx, is_order, true);
}

static void hvgr_cq_process_both_entry_buf(struct hvgr_ctx * const ctx,
	struct hvgr_cq_ctx * const cq_ctx)
{
	struct hvgr_device * const gdev = ctx->gdev;
	struct hvgr_cq_dev * const gcqctx = &ctx->gdev->cq_dev;
	uint32_t order_pid = gcqctx->order_dump_pid;
	uint32_t sync_pid = gcqctx->sync_dump_pid;
	void *kva = NULL;

	if (!(gcqctx->hw_cfg.cq_order_dump || gcqctx->hw_cfg.cq_sync_dump))
		return;

	if (cq_ctx->sw_wr_ctx == NULL)
		return;

	if (gcqctx->hw_cfg.cq_order_dump) {
		kva = hvgr_cq_get_entry_buffer_kva(cq_ctx, ORDER_DUMP);
		hvgr_cq_clear_buf_full(kva, cq_ctx, ORDER_DUMP, false);
	}

	if (gcqctx->hw_cfg.cq_sync_dump) {
		kva = hvgr_cq_get_entry_buffer_kva(cq_ctx, SYNC_DUMP);
		hvgr_cq_clear_buf_full(kva, cq_ctx, SYNC_DUMP, false);
	}
}
#endif

static void hvgr_cq_fill_dfx_buffer(struct cq_sw_writeable_context *sw_wr_ctx, uint64_t addr)
{
	if (!sw_wr_ctx)
		return;

	sw_wr_ctx->dfx_buf_info.order_buf_ptr = addr;
	sw_wr_ctx->dfx_buf_info.order_buf_size = CQ_DFX_ORDER_BUF_SIZE / sizeof(uint32_t);
	addr += CQ_DFX_ORDER_BUF_SIZE;

	sw_wr_ctx->dfx_buf_info.sync_buf_ptr = addr;
	sw_wr_ctx->dfx_buf_info.sync_buf_size = CQ_DFX_SYNC_BUF_SIZE / sizeof(uint32_t);
	addr += CQ_DFX_SYNC_BUF_SIZE;

#if hvgr_version_lt(HVGR_V350)
	sw_wr_ctx->dfx_buf_info.replay_order_buf_ptr = addr;
	sw_wr_ctx->dfx_buf_info.replay_order_buf_size =
		CQ_DFX_REPLAY_ORDER_BUF_SIZE / sizeof(uint32_t);
#endif
}

static bool hvgr_cq_alloc_sw_dfxbuffer_memory(struct hvgr_ctx * const ctx,
	struct cq_sw_writeable_context *sw_wr_ctx)
{
	uint64_t size = 0;
	struct hvgr_mem_area *dfx_buffer_area = NULL;
	struct hvgr_mem_alloc_para para;

	size = hvgr_mem_page_align(CQ_DFX_ORDER_BUF_SIZE + CQ_DFX_SYNC_BUF_SIZE +
		CQ_DFX_REPLAY_ORDER_BUF_SIZE);
	para.property = HVGR_MEM_PROPERTY_SAME_VA;
	para.attribute = HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_CPU_WR |
		HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_GPU_WR | HVGR_MEM_ATTR_KMD_ACCESS;
	para.pages = hvgr_page_nums(size);
	para.max_pages = para.pages;
	dfx_buffer_area = hvgr_mem_allocate(ctx, &para, NULL, false);
	if (!dfx_buffer_area)
		return false;

	hvgr_cq_fill_dfx_buffer(sw_wr_ctx, dfx_buffer_area->uva);
	return true;
}

static void hvgr_cq_free_sw_dfxbuffer_memory(struct hvgr_ctx * const ctx,
	struct cq_sw_writeable_context *sw_wr_ctx)
{
	if (unlikely(sw_wr_ctx == NULL))
		return;

	hvgr_mem_free(ctx, sw_wr_ctx->dfx_buf_info.order_buf_ptr);
}

void hvgr_cq_config_bc_send_mode(struct hvgr_device *gdev)
{
#if hvgr_version_ge(HVGR_V350)
	uint32_t core_mask = hvgr_pm_get_availiable_cores(gdev);
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	uint32_t bc_send_mode = gcqctx->hw_cfg.bc_send_mode;
	uint32_t rt_rbc_send_mode = gcqctx->hw_cfg.rt_rbc_send_mode;

	/* We must set bc_send_mode as interleave when single core. */
	if (hweight32(core_mask) == 1) {
		bc_send_mode = CQ_BC_SEND_INTERLEAVE;
		rt_rbc_send_mode = CQ_BC_SEND_INTERLEAVE;
	}
	hvgr_write_reg(gdev,
		cq_control_reg(gdev, CQ_JOBCHANIN_SEND_MODE), (rt_rbc_send_mode << 1) | bc_send_mode);
#else
	uint32_t core_mask = hvgr_pm_get_availiable_cores(gdev);
	struct hvgr_cq_dev * const gcqctx = &gdev->cq_dev;
	uint32_t bc_send_mode = gcqctx->hw_cfg.bc_send_mode;

	if (hweight32(core_mask) == 1)
		bc_send_mode = CQ_BC_SEND_INTERLEAVE;
	hvgr_write_reg(gdev,
		cq_control_reg(gdev, CQ_BC_SEND_MODE), bc_send_mode);
#endif
}
