/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_mmu_api.h"
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/rcupdate.h>
#include <securec.h>

#include "hvgr_regmap.h"
#include "hvgr_mem_zone.h"
#include "hvgr_mem_opts.h"
#include "hvgr_mem_pool.h"
#include "hvgr_memory_data.h"
#include "hvgr_dm_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_asid_api.h"
#include "hvgr_log_api.h"
#include "hvgr_mmu_driver.h"


enum fault_type {
	FAULT_TYPE_CMDQ_ERR,
	FAULT_TYPE_EVENTQ_ERR,
	FAULT_TYPE_CMD_SYNC
};

static void hvgr_mmu_clear_fault(struct hvgr_device * const gdev, enum fault_type type)
{
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_CLEAR), 1 << (int)type);
}

static void hvgr_mmu_unmask_fault(struct hvgr_device * const gdev, enum fault_type type)
{
	uint32_t fault_mask;
	unsigned long flags;

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);
	fault_mask = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK));
	fault_mask |= (1 << type);

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK), fault_mask);
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);
}

static const char *hvgr_mmu_get_access_type(uint32_t access_type)
{
	switch (access_type) {
	case MMU_ACCESS_TYPE_ATOMIC:
		return "ATOMIC";
	case MMU_ACCESS_TYPE_EXECUTE:
		return "EXECUTE";
	case MMU_ACCESS_TYPE_READ:
		return "READ";
	case MMU_ACCESS_TYPE_WRITE:
		return "WRITE";
	default:
		WARN_ON(1);
		return "UNKNOWN";
	}
}

static void hvgr_mmu_show_fault_info(struct hvgr_device * const gdev, struct hvgr_ctx *ctx,
	struct hvgr_mmu_event_info *event, char *reason)
{
	struct hvgr_mmu_buf *cd = &gdev->mem_dev.cd_buf;
	union hvgr_mmu_context_descriptor *pt = cd->kva;
	union hvgr_mmu_context_descriptor *t = NULL;
	uint32_t ssid;

	if (event->opcode == MMU_EVENT_C_BAD_CD) {
		if (pt == NULL) {
			hvgr_err(gdev, HVGR_MEM, "%s cd kva is null", __func__);
			return;
		}
		ssid = event->op_data.translation.ssid;
		t = &pt[ssid];
		hvgr_err(gdev, HVGR_MEM,
			"Bad CD: %u\n"
			"Bad CD ptr: %pK\n"
			"CD val0: 0x%x\n"
			"CD val1: 0x%x\n"
			"CD val2: 0x%x\n"
			"CD val3: 0x%x\n"
			"CD val4: 0x%x\n"
			"CD val5: 0x%x\n",
			ssid,
			t,
			t->value[0],
			t->value[1],
			t->value[2],
			t->value[3],
			t->value[4],
			t->value[5]);
	} else {
		hvgr_err(gdev, HVGR_MEM,
			"Unhandled Page fault VA %pK\n"
			"Reason: %s\n"
			"pid: %d\n"
			"tgid: %d\n"
			"task_name: %s\n"
			"access type 0x%x: %s\n"
			"utlb id: 0x%x\n"
			"source id: 0x%x\n"
			"stream id: 0x%x\n"
			"mem_info: 0x%x\n"
			"jasid: 0x%x\n"
			"ssid: %d\n"
			"asid: %d\n"
			"stag:  0x%x\n",
			(void *)((uint64_t)(event->va) << 12),
			reason,
			(ctx == NULL ? 0 : ctx->pid),
			(ctx == NULL ? 0 : ctx->tgid),
			(ctx == NULL ? "unknown" : ctx->process_name),
			event->access_type, hvgr_mmu_get_access_type(event->access_type),
			event->utlb_id,
			event->source_id,
			event->stream_id,
			event->mem_info,
			event->jasid,
			event->op_data.translation.ssid,
			event->op_data.translation.asid,
			event->op_data.translation.stag_info.stag);
	}
}

static void hvgr_mmu_fault_reason(struct hvgr_mmu_event_info *event, char **reason)
{
	switch (event->opcode) {
	case MMU_EVENT_C_BAD_STE:
		*reason = "ste config error";
		break;
	case MMU_EVENT_C_BAD_CD:
		*reason = "cd config error";
		break;
	case MMU_EVENT_F_TRANSLATION:
		*reason = "translation error";
		break;
	case MMU_EVENT_F_ACCESS:
		*reason = "accsee error";
		break;
	case MMU_EVENT_F_PERMISSION:
		*reason = "permission error";
		break;
	case MMU_EVENT_MEMATTR_IDX:
		*reason = "memattr idx error";
		break;
	default:
		*reason = "unknown error";
		break;
	}
}

/* ctx may NULL, just for log */
static void hvgr_mmu_reset_gpu(struct hvgr_device * const gdev, struct hvgr_ctx *ctx,
	struct hvgr_mmu_event_info *event, char *reason)
{
	hvgr_mmu_show_fault_info(gdev, ctx, event, reason);
	hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);
}

static bool hvgr_mmu_fault_area_illegal(struct hvgr_mem_area *fault_area, char **reset_reason)
{
	if (fault_area == NULL) {
		*reset_reason = "Memory is not mapped on the GPU";
		return true;
	}

	if ((fault_area->attribute & HVGR_MEM_ATTR_GROWABLE) == 0) {
		*reset_reason = "Memory is not growable";
		return true;
	}

	return false;
}

static bool hvgr_mmu_fault_no_need_proc(uint64_t fault_addr, struct hvgr_mem_area *fault_area,
	uint64_t *add_pages)
{
	uint64_t offset;
	uint64_t offset_page;
	uint64_t new_pages;
	uint64_t temp_pages;

	offset = fault_addr - fault_area->gva;
	offset_page = offset >> PAGE_SHIFT;

	if (offset_page < fault_area->pages)
		return true;

	new_pages = offset_page - fault_area->pages + 1;
	if (fault_area->extent != 0) {
		temp_pages = new_pages % fault_area->extent;
		if (temp_pages != 0)
			new_pages = new_pages + fault_area->extent - temp_pages;
	}

	if (new_pages + fault_area->pages > fault_area->max_pages)
		new_pages = fault_area->max_pages - fault_area->pages;

	if (new_pages == 0)
		return true;

	*add_pages = new_pages;
	return false;
}

static long hvgr_mmu_fault_add_pages(struct hvgr_ctx *ctx, struct hvgr_mem_area *fault_area,
	uint64_t add_pages, uint64_t fault_addr)
{
	long ret;
	uint64_t add_gva;
	struct page **pages = NULL;
	struct hvgr_mmu_setup_paras mmu_para = {0};

	mutex_lock(&fault_area->mutex);
	pages = &fault_area->page_array[fault_area->pages];

	ret = hvgr_mem_pool_ctx_alloc(ctx, add_pages, (void **)pages,
		hvgr_mem_get_sc_id(fault_area->attribute));
	if (ret != 0) {
		mutex_unlock(&fault_area->mutex);
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu fault alloc 0x%lx pages fail %d",
			ctx->id, add_pages, ret);
		return ret;
	}

	add_gva = fault_area->gva + (fault_area->pages << PAGE_SHIFT);
	hvgr_mem_attr2flag(fault_area);

	mmu_para.gva = add_gva;
	mmu_para.page_array = pages;
	mmu_para.pages = add_pages;
	mmu_para.mmu_flag = fault_area->mmu_flag;
	mmu_para.flags = fault_area->flags;

	ret = hvgr_mmu_set_up(ctx, &mmu_para);
	if (ret != 0) {
		hvgr_mem_pool_ctx_free(ctx, add_pages, (void **)pages, 0,
			hvgr_mem_get_sc_id(fault_area->attribute));
		mutex_unlock(&fault_area->mutex);
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u mmu fault setup pt 0x%lx pages fail %d",
			ctx->id, add_pages, ret);
		return ret;
	}

	fault_area->pages += add_pages;
	mutex_unlock(&fault_area->mutex);

	hvgr_mmu_hal_flush_pt(ctx, fault_addr, add_pages);
	return 0;
}

static void hvgr_mmu_cmd_sync_worker(struct work_struct *work)
{
	struct hvgr_device *gdev;
	struct hvgr_mem_dev *mem_dev;
	struct hvgr_mmu_fault_worker *worker;

	worker = container_of(work, struct hvgr_mmu_fault_worker, cmd_sync_work);
	mem_dev = container_of(worker, struct hvgr_mem_dev, fault_worker);
	gdev = container_of(mem_dev, struct hvgr_device, mem_dev);

	hvgr_err(gdev, HVGR_MEM, "%s enter", __func__);

	hvgr_mmu_clear_fault(gdev, FAULT_TYPE_CMD_SYNC);
	hvgr_mmu_unmask_fault(gdev, FAULT_TYPE_CMD_SYNC);
	atomic_dec(&gdev->mem_dev.pending_faults);
}

static int hvgr_mmu_trans_fault_proc(struct hvgr_device * const gdev, struct hvgr_ctx *ctx,
	struct hvgr_mmu_event_info *event, char **reset_reason)
{
	struct hvgr_mem_area *fault_area = NULL;
	int ret = 0;
	uint64_t fault_addr;
	uint64_t add_pages = 0;

	if (ctx == NULL) {
		*reset_reason = "ctx is null";
		hvgr_err(gdev, HVGR_MEM, "mmu fault ctx is NULL");
		return 0;
	}

	mutex_lock(&ctx->mem_ctx.area_mutex);
	fault_addr = ((uint64_t)(event->va) << 12);
	fault_area = hvgr_mem_zone_find_area_by_gva_range(&ctx->mem_ctx, fault_addr);
	if (hvgr_mmu_fault_area_illegal(fault_area, reset_reason)) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mmu fault trans area illegal %s", *reset_reason);
		ret = -1;
		goto out;
	}

	if (hvgr_mmu_fault_no_need_proc(fault_addr, fault_area, &add_pages)) {
		goto out;
	}

	if (hvgr_mmu_fault_add_pages(ctx, fault_area, add_pages, fault_addr) != 0) {
		hvgr_err(ctx->gdev, HVGR_MEM, "mmu fault add pages failed");
		*reset_reason = "Add pages fail";
		ret = -1;
		goto out;
	}

out:
	mutex_unlock(&ctx->mem_ctx.area_mutex);
	return ret;
}

static struct hvgr_ctx *hvgr_mmu_eventq_get_ctx(struct hvgr_device * const gdev,
	struct hvgr_mmu_event_info *event)
{
	struct hvgr_ctx *ctx;

	if (event->opcode != MMU_EVENT_F_ACCESS && event->opcode != MMU_EVENT_F_TRANSLATION)
		return NULL;

	ctx = hvgr_cq_lookup_ctx(gdev, event->op_data.translation.asid);
	if (ctx == NULL)
		hvgr_err(gdev, HVGR_MEM, "mmu fault %u not found ctx %u",
			event->opcode, event->op_data.translation.asid);

	return ctx;
}

static void hvgr_mmu_eventq_err_worker(struct work_struct *work)
{
	struct hvgr_device *gdev;
	struct hvgr_mem_dev *mem_dev;
	struct hvgr_mmu_fault_worker *worker;
	struct hvgr_mmu_event_info *event;
	int ret = 0;
	char *reason = NULL;
	struct hvgr_ctx *ctx;

	worker = container_of(work, struct hvgr_mmu_fault_worker, eventq_work);
	mem_dev = container_of(worker, struct hvgr_mem_dev, fault_worker);
	gdev = container_of(mem_dev, struct hvgr_device, mem_dev);

	event = hvgr_mmu_get_event(gdev);
	while (event) {
		ctx = hvgr_mmu_eventq_get_ctx(gdev, event);

		if (event->opcode == MMU_EVENT_F_ACCESS) {
			hvgr_err(gdev, HVGR_MEM, "mmu eventq faccess enter");
		} else if (event->opcode == MMU_EVENT_F_TRANSLATION) {
			ret = hvgr_mmu_trans_fault_proc(gdev, ctx, event, &reason);
		} else {
			hvgr_err(gdev, HVGR_MEM, "mmu fault %u, need to reset gpu", event->opcode);
			hvgr_mmu_fault_reason(event, &reason);
			ret = -1;
		}

		if (ctx)
			hvgr_cq_sched_release_ctx(gdev, ctx);

		if (ret == 0) {
			/* after proc cmdq resume */
			hvgr_mmu_cmdq_resume(ctx, gdev, event->op_data.translation.asid,
				event->op_data.translation.stag_info.stag);
		} else {
			/* process failed and reset gpu */
			hvgr_mmu_reset_gpu(gdev, ctx, event, reason);
			goto out;
		}

		hvgr_info(gdev, HVGR_MEM, "eventq proc success");
		hvgr_mmu_event_done(gdev);
		event = hvgr_mmu_get_event(gdev);
	}

	hvgr_mmu_clear_fault(gdev, FAULT_TYPE_EVENTQ_ERR);
	hvgr_mmu_unmask_fault(gdev, FAULT_TYPE_EVENTQ_ERR);
out:
	atomic_dec(&gdev->mem_dev.pending_faults);
}


long hvgr_mmu_fault_wq_init(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_fault_worker *worker =  &gdev->mem_dev.fault_worker;

	worker->fault_wq = alloc_workqueue("hvgr_fault", WQ_HIGHPRI | WQ_UNBOUND, 1);
	if (worker->fault_wq == NULL) {
		hvgr_err(gdev, HVGR_MEM, "mmu fault alloc wq failed");
		return -EINVAL;
	}

	INIT_WORK(&worker->cmd_sync_work, hvgr_mmu_cmd_sync_worker);
	INIT_WORK(&worker->eventq_work, hvgr_mmu_eventq_err_worker);

	return 0;
}

static void hvgr_mmu_cmdq_err_proc(struct hvgr_device * const gdev)
{
	uint32_t cmdq_cons;

	cmdq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS));
	cmdq_cons = cmdq_cons >> 24;

	hvgr_err(gdev, HVGR_MEM, "cmdq err %u, start to reset gpu", cmdq_cons);
	hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);
}

static void hvgr_mmu_int_process(struct hvgr_device * const gdev, uint32_t stat)
{
	uint32_t irq_mask;
	uint32_t val;
	unsigned long flags;
	struct hvgr_mmu_fault_worker *worker = &gdev->mem_dev.fault_worker;
	uint32_t cmd_sync = stat & MMU_IRQ_CMD_SYNC_MASK;
	uint32_t eventq_fault = stat & MMU_IRQ_EVENTQ_ERR_MASK;
	uint32_t cmdq_fault = stat & MMU_IRQ_CMDQ_ERR_MASK;

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);
	irq_mask = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK));
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK), MMU_IRQ_MASK_DISABLE_ALL);
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);

	worker->protected_mode = false;

	if (cmdq_fault) {
		hvgr_mmu_cmdq_err_proc(gdev);
		return;
	}

	if (cmd_sync) {
		WARN_ON(work_pending(&worker->cmd_sync_work));
		atomic_inc(&gdev->mem_dev.pending_faults);
		(void)queue_work(worker->fault_wq, &worker->cmd_sync_work);
		irq_mask &= ~MMU_IRQ_CMD_SYNC_MASK;
	}

	if (eventq_fault) {
		WARN_ON(work_pending(&worker->eventq_work));
		atomic_inc(&gdev->mem_dev.pending_faults);
		(void)queue_work(worker->fault_wq, &worker->eventq_work);
		irq_mask &= ~MMU_IRQ_EVENTQ_ERR_MASK;
	}

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);
	val = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK));
	val |= irq_mask;
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK), val);
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);
}

irqreturn_t hvgr_mmu_irq_handler(int irq, void *data)
{
	struct hvgr_device * const gdev = (struct hvgr_device * const)data;
	uint32_t stat;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_POWER_OFF)
		return IRQ_NONE;

	stat = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_RPT));
	if (stat == 0)
		return IRQ_NONE;

	hvgr_mmu_int_process(gdev, stat);

	return IRQ_HANDLED;
}

long hvgr_mmu_irq_init(struct hvgr_device * const gdev)
{
	if (hvgr_mmu_fault_wq_init(gdev) != 0)
		return -EINVAL;

	return hvgr_register_irq(gdev, MMU_IRQ, hvgr_mmu_irq_handler);
}

void hvgr_flush_mmu_faults(struct hvgr_device * const gdev)
{
	if (atomic_read(&gdev->mem_dev.pending_faults) == 0)
		return;

	flush_workqueue(gdev->mem_dev.fault_worker.fault_wq);
}

