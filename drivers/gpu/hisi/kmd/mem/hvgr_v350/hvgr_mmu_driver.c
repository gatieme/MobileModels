/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>
#include <asm/barrier.h>

#include <securec.h>
#include "hvgr_log_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_mmu_driver.h"
#include "hvgr_dm_api.h"
#include "hvgr_mmu_struct.h"
#include "hvgr_mmu_entry.h"
#include "hvgr_fcp.h"
#include "hvgr_datan_api.h"

enum mmu_buffer_type {
	MMU_BUFFER_CD,
	MMU_BUFFER_CMDQ,
	MMU_BUFFER_EVENTQ,
};

#define mmu_buffer_free(bf) do { \
	if ((bf)->kva != NULL) { \
		vunmap((bf)->kva); \
		(bf)->kva = NULL; \
	} \
	if ((bf)->buf_page != NULL) { \
		__free_pages((bf)->buf_page, (bf)->page_order); \
		(bf)->buf_page = NULL; \
	} \
} while (0)

#define MMU_INIT_ALLOC_PAGES_TRY_MAX_TIMES  (3u)
#define MMU_INIT_VMAP_TRY_MAX_TIMES         (3u)

#define mmu_wrap(x)                         (((x) > 0) ? 0 : 1)

#define mmu_cr1_set_queue_pbha(x)           ((u32)(x) << 12)
#define mmu_cr1_set_queue_sh(x)             ((u32)(x) << 8)
#define mmu_cr1_set_queue_memattr(x)        ((u32)(x))

#define mmu_cd_set_pbha(x)                  ((u32)(x) << 12)
#define mmu_cd_set_sh(x)                    ((u32)(x) << 8)
#define mmu_cd_set_memattr(x)               ((u32)(x))

#define mmu_set_base_l(x)                   ((u32)(x) & 0xffffffe0)
#define mmu_set_log2size(x)                 ((u32)(x))
#define mmu_set_base_h(x)                   ((u32)(((x) >> 32) & 0xfff))

#define mmu_cr0_set_memattr_bitmap(x)       ((u32)(x) << 8)
#define MMU_CR0_EVENT_GRANULE_PAGE          ((u32)0 << 3)
#define MMU_CR0_EVENT_GRANULE_ASID          ((u32)1 << 3)
#define MMU_CR0_STE_INVALID                 ((u32)0 << 0)
#define MMU_CR0_STE_VALID                   ((u32)1 << 0)

#define MMU_IRQ_MASK_CMD_SYNC               ((u32)1 << 2)
#define MMU_IRQ_MASK_EVENTQ_ERR             ((u32)1 << 1)
#define MMU_IRQ_MASK_CMDQ_ERR               ((u32)1 << 0)

static int hvgr_mmu_buffer_init(struct hvgr_device * const gdev, struct hvgr_mmu_buf *bf,
	enum mmu_buffer_type type)
{
	struct page *page = NULL;
	struct page *page_array[MMU_CD_PAGES_CNT];
	uint32_t idx;
	uint32_t order;
	uint32_t page_nums;
	void *addr;
	gfp_t gfp = GFP_KERNEL | __GFP_ZERO | __GFP_NOWARN;
	pgprot_t prot = PAGE_KERNEL;
	uint32_t try_times = MMU_INIT_ALLOC_PAGES_TRY_MAX_TIMES;

	if (type == MMU_BUFFER_CD)
		order = MMU_CD_ORDER;
	else
		order = 0;

	page_nums = 1 << order;

	while (try_times > 0) {
		page = alloc_pages(gfp, order);
		if (page != NULL)
			break;
		hvgr_err(gdev, HVGR_MEM, "%s alloc pages failed cnt %u", __func__, try_times);
		udelay(1);
		try_times--;
	}
	if (try_times == 0)
		return -1;

	for (idx = 0; idx < page_nums; idx++)
		page_array[idx] = &page[idx];

	prot = pgprot_writecombine(prot);

	try_times = MMU_INIT_VMAP_TRY_MAX_TIMES;
	while (try_times > 0) {
		addr = vmap(page_array, page_nums, VM_MAP, prot);
		if (addr != NULL)
			break;
		hvgr_err(gdev, HVGR_MEM, "%s vmap failed cnt %u", __func__, try_times);
		udelay(1);
		try_times--;
	}
	if (try_times == 0) {
		__free_pages(page, page_nums);
		return -1;
	}

	bf->page_nums = page_nums;
	bf->buf_page = page;
	bf->page_order = order;
	bf->kva = addr;

	hvgr_info(gdev, HVGR_MEM, "%s type %u init %pK", __func__, type, addr);

	return 0;
}

static int hvgr_mmu_wait_cmdq_cons(struct hvgr_device * const gdev,
	uint32_t target_idx, uint32_t prod_wrap)
{
	uint32_t max_loops = 100000;
	uint32_t cmdq_cons;
	uint32_t cur_idx;
	uint32_t cons_wrap;

	cmdq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS));
	cur_idx = mmu_cmdq_get_idx(cmdq_cons);
	cons_wrap = mmu_cmdq_get_wrap(cmdq_cons);

	while (--max_loops) {
		if ((prod_wrap == cons_wrap) && (cur_idx >= target_idx))
			break;
		if ((prod_wrap != cons_wrap) && (cur_idx < target_idx))
			break;
		cmdq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS));
		cur_idx = mmu_cmdq_get_idx(cmdq_cons);
		cons_wrap = mmu_cmdq_get_wrap(cmdq_cons);
	}
	if (max_loops == 0)
		return -1;

	return 0;
}

static int hvgr_mmu_cmdq_prod(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	struct hvgr_mmu_cmd_info *cmds, uint32_t cmds_num)
{
	struct hvgr_mmu_buf *cmdq_buf = &gdev->mem_dev.cmdq_buf;
	struct hvgr_mmu_cmd_info *pt;
	uint32_t cmdq_prod;
	uint32_t wrap;
	uint32_t wr_idx;
	int ret;
	uint32_t i;
	unsigned long flags;
#ifdef CONFIG_HVGR_DFX_DATAN
	struct datan_jobtrace_ctx *djctx = &ctx->datan_ctx.jobtrace_ctx;
	struct hvgr_jobtrace_worker *worker = &djctx->worker;
#endif

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);

	cmdq_prod = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_PROD));
	wr_idx = mmu_cmdq_get_idx(cmdq_prod);
	wrap = mmu_cmdq_get_wrap(cmdq_prod);
	pt = cmdq_buf->kva;

	for (i = 0; i < cmds_num; i++) {
		memcpy_s(&pt[wr_idx], MMU_CMDQ_INFO_SIZE, &cmds[i], MMU_CMDQ_INFO_SIZE);
		hvgr_datan_jobtrace(ctx, JOBTRACE_TYPE_OBJ, KDATAN_JD_DUMP_CMDQ, ctx);

		if (likely(wr_idx < (MMU_CMDQ_MAX_CNT - 1))) {
			wr_idx = wr_idx + 1;
		} else {
			wr_idx = 0;
			wrap = mmu_wrap(wrap);
		}

		smp_mb();
		hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_PROD),
			mmu_cmdq_set_wrap(wrap) | wr_idx);
		ret = hvgr_mmu_wait_cmdq_cons(gdev, wr_idx, wrap);
		if (ret !=0 )
			goto out;

#ifdef CONFIG_HVGR_DFX_DATAN
		if (djctx->flag) {
			uint32_t target_idx = djctx->cmdq_prod_cons_helper.target_idx;
			djctx->cmdq_prod_cons_helper.val[target_idx] = mmu_cmdq_set_wrap(wrap) | wr_idx;
			if (target_idx == (CMDQ_PROD_BUFFER_LEN - 1))
				djctx->cmdq_prod_cons_helper.target_idx = 0;
			else
				++(djctx->cmdq_prod_cons_helper.target_idx);
			(void)queue_work(worker->jobtrace_wq, &worker->cmdq_prod_cons_worker);
		}
#endif
	}

out:
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);

	return ret;
}

int hvgr_mmu_cmdq_tlb_invalid_asid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t asid)
{
	struct hvgr_mmu_cmd_info cmd = {0};

	cmd.opcode = MMU_CMD_TLBI_NH_ASID;
	cmd.op_data.tlbi_asid.asid = asid;
	hvgr_info(gdev, HVGR_MEM, "%s asid: %u", __func__, asid);

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, 1);
}

int hvgr_mmu_cmdq_cd_invalid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t ssid)
{
	struct hvgr_mmu_cmd_info cmd = {0};

	cmd.opcode = MMU_CMD_CFGI_CD;
	cmd.op_data.cdi.ssid = ssid;
	hvgr_info(gdev, HVGR_MEM, "%s ssid: %u", __func__, ssid);

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, 1);
}

int hvgr_mmu_cmdq_resume(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t asid, uint32_t stag)
{
	struct hvgr_mmu_cmd_info cmd = {0};

	cmd.opcode = MMU_CMD_RESUME;
	cmd.op_data.resume.asid = asid;
	cmd.op_data.resume.stag_info.stag = stag;
	hvgr_info(gdev, HVGR_MEM, "%s asid: %u", __func__, asid);

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, 1);
}

int hvgr_mmu_cmdq_tlb_invalid_va(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, uint32_t asid,
	uint64_t gva, uint32_t pages)
{
	struct hvgr_mmu_cmd_info cmd = {0};

	cmd.opcode = MMU_CMD_TLBI_NH_VA;
	cmd.op_data.tlbi_va.asid = asid;
	cmd.op_data.tlbi_va.va_start = (uint32_t)(gva >> 12);
	cmd.op_data.tlbi_va.va_end = cmd.op_data.tlbi_va.va_start + pages;
	cmd.op_data.tlbi_va.granule = MMU_ADRMODE_4K;
	hvgr_info(gdev, HVGR_MEM, "%s asid: %u, va: %p:%p", __func__, asid, u64_to_ptr(gva),
		u64_to_ptr(gva + (pages << 12)));

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, 1);
}

int hvgr_mmu_cmdq_sync(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev)
{
	struct hvgr_mmu_cmd_info cmd = {0};

	cmd.opcode = MMU_CMD_SYNC;
	hvgr_info(gdev, HVGR_MEM, "%s enter", __func__);

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, 1);
}

struct hvgr_mmu_event_info *hvgr_mmu_get_event(struct hvgr_device * const gdev)
{
	uint32_t eventq_cons;
	uint32_t eventq_prod;
	uint32_t r_wrap;
	uint32_t w_wrap;
	uint32_t rd_idx;
	uint32_t wr_idx;
	struct hvgr_mmu_event_info *event = NULL;
	struct hvgr_mmu_buf *eventq_buf = &gdev->mem_dev.eventq_buf;
	struct hvgr_mmu_event_info *pt;

	eventq_prod = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_PROD));
	eventq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_CONS));
	rd_idx = mmu_eventq_get_idx(eventq_cons);
	r_wrap = mmu_eventq_get_wrap(eventq_cons);
	wr_idx = mmu_eventq_get_idx(eventq_prod);
	w_wrap = mmu_eventq_get_wrap(eventq_prod);
	if ((r_wrap == w_wrap) && (rd_idx >= wr_idx)) {
		hvgr_info(gdev, HVGR_MEM, "eventq read empty %u:%u", wr_idx, rd_idx);
		goto out;
	}

	pt = eventq_buf->kva;
	event = &pt[rd_idx];

	if (rd_idx < MMU_EVENTQ_MAX_CNT - 1) {
		rd_idx = rd_idx + 1;
	} else {
		rd_idx = 0;
		r_wrap = mmu_wrap(r_wrap);
	}
	eventq_buf->idx = rd_idx;
	eventq_buf->wrap = r_wrap;

out:
	return event;
}

void hvgr_mmu_event_done(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_buf *eventq_buf = &gdev->mem_dev.eventq_buf;

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_CONS),
		mmu_eventq_set_wrap(eventq_buf->wrap) | eventq_buf->idx);
}

int hvgr_mmu_init_cd(struct hvgr_ctx *ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_mmu_buf *cd = &gdev->mem_dev.cd_buf;
	union hvgr_mmu_context_descriptor *pt = cd->kva;
	union hvgr_mmu_context_descriptor *t = &pt[ctx->ssid];

	t->st.asid = ctx->asid;
	t->st.memattr = AS_MEMATTR_AARCH64;

	t->st.ttb0_l = (ctx->mem_ctx.pgd_pa >> MMU_TTB0_PA_OFFSET_L) & MMU_TTB0_PA_MASK_L;
	t->st.ttb0_h = (ctx->mem_ctx.pgd_pa >> MMU_TTB0_PA_OFFSET_H) & MMU_TTB0_PA_MASK_H;
	t->st.asid = ctx->asid;

	if (hvgr_mem_is_cpu_coherent(gdev))
		t->st.ptw_sh = MMU_PTW_SH_MEMATTR_OUT_SHAREABLE;

	t->st.adrmode = MMU_ADRMODE_4K;

	t->st.ptw_memattr = MMU_PTW_MEMATTR_NON_CACHEABLE;
	t->st.write_execute_never = 0;
	t->st.affd = 1;
	t->st.ptw_pbha = 0;

	hvgr_info(gdev, HVGR_MEM, "%s enter", __func__);

	return 0;
}

void hvgr_mmu_set_cd_valid(struct hvgr_ctx *ctx, bool valid)
{
	struct hvgr_device *gdev = ctx->gdev;
	uint32_t idx = ctx->ssid;
	struct hvgr_mmu_buf *cd = &gdev->mem_dev.cd_buf;
	union hvgr_mmu_context_descriptor *pt = cd->kva;

	pt[idx].st.valid = valid ? 1 : 0;

	hvgr_info(gdev, HVGR_MEM, "%s valid %u", __func__, pt[idx].st.valid);
}

int hvgr_mmu_init(struct hvgr_device * const gdev)
{
	int ret;

	ret = hvgr_mmu_buffer_init(gdev, &gdev->mem_dev.cd_buf, MMU_BUFFER_CD);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "mmu cd init failed");
		return ret;
	}

	ret = hvgr_mmu_buffer_init(gdev, &gdev->mem_dev.cmdq_buf, MMU_BUFFER_CMDQ);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "mmu cmdq init failed");
		mmu_buffer_free(&gdev->mem_dev.cd_buf);
		return ret;
	}

	ret = hvgr_mmu_buffer_init(gdev, &gdev->mem_dev.eventq_buf, MMU_BUFFER_EVENTQ);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "mmu cmdq eventq failed");
		mmu_buffer_free(&gdev->mem_dev.cd_buf);
		mmu_buffer_free(&gdev->mem_dev.cmdq_buf);
		return ret;
	}

	hvgr_info(gdev, HVGR_MEM, "%s success", __func__);

	return 0;
}

void hvgr_mmu_term(struct hvgr_device * const gdev)
{
	mmu_buffer_free(&gdev->mem_dev.cd_buf);
	mmu_buffer_free(&gdev->mem_dev.cmdq_buf);
	mmu_buffer_free(&gdev->mem_dev.eventq_buf);

	hvgr_info(gdev, HVGR_MEM, "%s success", __func__);
	return;
}

int hvgr_mmu_global_reg_init(struct hvgr_device * const gdev)
{
	uint64_t phys_cd, phys_cmdq, phys_eventq;
	uint32_t mmu_sh = 0;
	uint32_t mmu_pbha = 0;
	uint32_t mmu_attr = 0;
	struct page *page;

	if (hvgr_mem_is_cpu_coherent(gdev))
		mmu_sh = MMU_PTW_SH_MEMATTR_OUT_SHAREABLE;

	/* non cacheable */
	mmu_attr = 0xcc;

	/* refer to v300, only set in HVGR_FEATURE_SYSTEM_CACHE */
	mmu_pbha = 0;

	/* cd global reg */
	page = gdev->mem_dev.cd_buf.buf_page;
	if (page == NULL)
		return -1;

	phys_cd = page_to_phys(page);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CD_CFG),
		mmu_cd_set_memattr(mmu_attr) | mmu_cd_set_sh(mmu_sh) | mmu_cd_set_pbha(mmu_pbha));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CD_BASE_L),
		mmu_set_base_l(phys_cd) | mmu_set_log2size(MMU_CD_LOG2SIZE));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CD_BASE_H),
		mmu_set_base_h(phys_cd));

	/* cmdq global reg */
	page = gdev->mem_dev.cmdq_buf.buf_page;
	if (page == NULL)
		return -1;

	phys_cmdq = page_to_phys(page);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_BASE_L),
		mmu_set_base_l(phys_cmdq) | mmu_set_log2size(MMU_CMDQ_LOG2SIZE));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_BASE_H),
		mmu_set_base_h(phys_cmdq));

	/* eventq global reg */
	page = gdev->mem_dev.eventq_buf.buf_page;
	if (page == NULL)
		return -1;

	phys_eventq = page_to_phys(page);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_BASE_L),
		mmu_set_base_l(phys_eventq) | mmu_set_log2size(MMU_EVENTQ_LOG2SIZE));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_BASE_H),
		mmu_set_base_h(phys_eventq));

	/* CR1 */
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CR1),
		mmu_cr1_set_queue_pbha(mmu_pbha) | mmu_cr1_set_queue_sh(mmu_sh) | mmu_cr1_set_queue_memattr(mmu_attr));

	/* CR0 */
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CR0),
		mmu_cr0_set_memattr_bitmap(0xff) | MMU_CR0_EVENT_GRANULE_ASID | MMU_CR0_STE_VALID);

	return 0;
}
