/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "dra_def_legacy.h"
#include "dra_hal.h"

#define DRA_LOWPHY_ADDR(addr) ((addr)&0xffffffff)
#define DRA_HIGHPHY_ADDR(addr) (((addr) >> 32) & 0xff)
#define DRA_OPIPE_REG_START DRA_OPIPE_BASE_ADDR_L(0)
#define DRA_OPIPE_REG_END DRA_OPIPE_CFG_DONE(5)
#define DRA_FIFO_RESERVE_CNT 0x800

void __dra_release_pool_init(struct dra *dra)
{
    struct dra_fifo *fifo = &dra->release.fifo;
    writel(DRA_LOWPHY_ADDR(fifo->phy), dra->regs + DRA_RLS_POOL_ADDR_L);
    writel(DRA_HIGHPHY_ADDR(fifo->phy), dra->regs + DRA_RLS_POOL_ADDR_H);
    writel(fifo->depth - 1, dra->regs + DRA_RLS_POOL_DEPTH);
    fifo->uthrl = 1;
    writel(fifo->uthrl, dra->regs + DRA_RLS_POOL_UP_THRH);
    writel(0, dra->regs + DRA_RLS_POOL_WPTR);
    writel(0, dra->regs + DRA_RLS_POOL_RPTR);
}

void dra_ddr_buf_fifo_init(struct dra *dra, struct dra_fifo *fifo, unsigned int level) {}

void dra_fifo_init(struct dra *dra, struct dra_fifo *fifo, int level)
{
    writel(DRA_LOWPHY_ADDR(fifo->phy), dra->regs + DRA_OPIPE_BASE_ADDR_L(level));
    writel(DRA_HIGHPHY_ADDR(fifo->phy), dra->regs + DRA_OPIPE_BASE_ADDR_H(level));
    writel(fifo->depth - 1, dra->regs + DRA_OPIPE_DEPTH(level));
    writel(0, dra->regs + DRA_OPIPE_WPTR(level));
    writel(0, dra->regs + DRA_OPIPE_RPTR(level));
    writel(fifo->uthrl, dra->regs + DRA_OPIPE_UP_THRH(level));
    writel(fifo->dthrl, dra->regs + DRA_OPIPE_DN_THRH(level));
    writel(1, dra->regs + DRA_OPIPE_CFG_DONE(level));
}

void dra_force_fifo_full(struct dra *dra, struct dra_fifo *fifo, int level)
{
    writel_relaxed(fifo->depth - 5, dra->regs + DRA_OPIPE_WPTR(level)); // reserve 5 to prevent filling opipe
}

int dra_ipipe_init(struct dra *dra, struct dra_ipipe *ipipe, unsigned int idx)
{
    struct dra_fifo *fifo = &ipipe->fifo;
    writel((unsigned int)DRA_LOWPHY_ADDR(fifo->phy), (void *)(dra->regs + DRA_IPIPE_BASE_ADDR_L(idx)));
    writel((unsigned int)DRA_HIGHPHY_ADDR(fifo->phy), (void *)(dra->regs + DRA_IPIPE_BASE_ADDR_H(idx)));
    writel(fifo->depth - 1, (void *)(dra->regs + DRA_IPIPE_DEPTH(idx)));
    writel(fifo->uthrl, (void *)(dra->regs + DRA_IPIPE_UP_THRH(idx)));
    writel(fifo->dthrl, (void *)(dra->regs + DRA_IPIPE_DN_THRH(idx)));

    writel((unsigned int)DRA_LOWPHY_ADDR(fifo->update_write_addr), (void *)(dra->regs + DRA_IPIPE_PTR_ADDR_L(idx)));
    writel((unsigned int)DRA_HIGHPHY_ADDR(fifo->update_write_addr), (void *)(dra->regs + DRA_IPIPE_PTR_ADDR_H(idx)));
    writel(0, (void *)(dra->regs + DRA_IPIPE_WPTR(idx)));
    writel(0, (void *)(dra->regs + DRA_IPIPE_RPTR(idx)));
    writel(1, (void *)(dra->regs + DRA_IPIPE_CTRL(idx)));
    return 0;
}

void dra_interupt_init(struct dra *dra)
{
    dra->int_mask |= DRA_RLS_FULL_WR_INT_MASK | DRA_SAFE_CHK_INT_MASK | DRA_DDR_RLS_INT_MASK;
    writel_relaxed(dra->int_mask, dra->regs + DRA_OPIPE_INT_RAW);
    writel_relaxed(dra->int_mask, dra->regs + DRA_OPIPE_INT_MSK);
    writel_relaxed(0, dra->regs + DRA_IPIPE_INT_MSK0);
    return;
}

void dra_ipipe_read_update(struct dra *dra, unsigned int rptr, unsigned int idx)
{
    writel_relaxed(rptr, (void *)(dra->regs + DRA_IPIPE_RPTR(idx)));
}

inline void dra_input(struct dra *dra, unsigned long long buf, struct dra_opipe *opipe)
{
    writeq_relaxed(buf, dra->regs + DRA_ALLOC_ADDR_L(opipe->level, 0));
}

void dra_rls_input(struct dra *dra, unsigned long long buf, struct dra_rls_ch *rls, unsigned int level)
{
    writeq_relaxed(buf, dra->regs + DRA_ALLOC_ADDR_L(level, 0));
    dra->opipes[level].delay_free_cnt++;
}

unsigned int dra_hal_set_adq(struct dra *dra, unsigned int level, unsigned long long adqbase, unsigned int write,
    unsigned int depth, unsigned int idx)
{
    unsigned int dthrl = depth - 2 * DRA_BURST_LEN; // reserve 2 * DRA_BURST_LEN as dthrl
    unsigned int uthrl = depth - DRA_BURST_LEN; // reserve

    writel_relaxed((unsigned int)adqbase & 0xffffffffU, (void *)(dra->regs + DRA_IPIPE_BASE_ADDR_L(idx)));
    writel_relaxed((unsigned int)(adqbase >> 32) & 0xff, (void *)(dra->regs + DRA_IPIPE_BASE_ADDR_H(idx))); // 32 high bits
    writel_relaxed(depth - 1, (void *)(dra->regs + DRA_IPIPE_DEPTH(idx)));
    writel_relaxed(0, (void *)(dra->regs + DRA_IPIPE_WPTR(idx)));
    writel_relaxed(0, (void *)(dra->regs + DRA_IPIPE_RPTR(idx)));
    writel_relaxed(uthrl, (void *)(dra->regs + DRA_IPIPE_UP_THRH(idx)));
    writel_relaxed(dthrl, (void *)(dra->regs + DRA_IPIPE_DN_THRH(idx)));

    writel_relaxed(write, (void *)(dra->regs + DRA_IPIPE_PTR_ADDR_L(idx)));
    writel_relaxed(0, (void *)(dra->regs + DRA_IPIPE_PTR_ADDR_H(idx)));
    writel(1, (void *)(dra->regs + DRA_IPIPE_CTRL(idx)));
    return dra->phy_regs + DRA_IPIPE_RPTR(idx);
}

unsigned int dra_get_space(struct dra *dra, struct dra_opipe *opipe)
{
    unsigned int total;

    total = readl(dra->regs + DRA_OPIPE_SPACE(opipe->level)) - 0xf;
    if (total > DRA_FIFO_RESERVE_CNT) {
        total = DRA_FIFO_RESERVE_CNT;
    }

    return total;
}

unsigned int dra_get_intr_status(struct dra *dra)
{
    return readl(dra->regs + DRA_OPIPE_INT_RAW);
}

void dra_get_big_pool_ptr(struct dra *dra, struct dra_opipe *opipe, unsigned int *wptr, unsigned int *rptr)
{
    *wptr = readl(dra->regs + DRA_OPIPE_WPTR(opipe->level));
    *rptr = readl(dra->regs + DRA_OPIPE_RPTR(opipe->level));
}

unsigned int dra_get_busy_cnt(struct dra *dra, struct dra_opipe *opipe)
{
    unsigned int space, cnt;

    space = readl(dra->regs + DRA_OPIPE_SPACE(opipe->level));
    cnt = opipe->fifo.depth - space;
    if (cnt > opipe->fifo.dthrl + DRA_FIFO_RESERVE_CNT) {
        cnt = cnt - opipe->fifo.dthrl - DRA_FIFO_RESERVE_CNT;
    } else {
        cnt = 0;
    }

    return cnt;
}

unsigned int dra_get_rls(struct dra *dra)
{
    return readl_relaxed(dra->regs + DRA_RLS_POOL_WPTR);
}

void dra_set_rls(struct dra *dra, unsigned int rptr)
{
    writel_relaxed(rptr, dra->regs + DRA_RLS_POOL_RPTR);
}

void dra_set_intr(struct dra *dra)
{
    writel_relaxed(dra->int_mask, dra->regs + DRA_OPIPE_INT_MSK);
}

void dra_top_intr(struct dra *dra)
{
    unsigned int status;

    status = readl(dra->regs + DRA_OPIPE_INT_STAT);
    if (unlikely(status & DRA_SAFE_CHK_INT_MASK)) {
        /* clear raw */
        writel(DRA_SAFE_CHK_INT_MASK, dra->regs + DRA_OPIPE_INT_RAW);
        dra->status.safe_check_err++;
    }
    if (unlikely(status & DRA_RLS_FULL_WR_INT_MASK)) {
        /* clear raw */
        writel(DRA_RLS_FULL_WR_INT_MASK, dra->regs + DRA_OPIPE_INT_RAW);
        dra->status.rls_full++;
    }

    dra->irq_status = status;
    writel(DRA_SAFE_CHK_INT_MASK, dra->regs + DRA_OPIPE_INT_MSK);
}

void dra_basic_cfg(struct dra *dra)
{
    writel(dra->fifo_timer_en, dra->regs + DRA_TIMER_EN);
}

int dra_hal_suspend(struct dra *dra)
{
    unsigned int i;

    /* close timer_en and turn down opipe down waterline */
    writel(0, dra->regs + DRA_TIMER_EN);
    for (i = 0; i < DRA_OPIPE_ALLOC_LEVELS; i++) {
        writel(dra->opipes[i].fifo.dthrl / 4, dra->regs + DRA_OPIPE_DN_THRH(i)); // turn down dthrl to 1 / 4
    }
    writel(DRA_RELEASE_THRSH_LP, dra->regs + DRA_RLS_POOL_UP_THRH);

    writel_relaxed(dra->int_mask, dra->regs + DRA_OPIPE_INT_MSK);

    return 0;
}

int dra_hal_resume(struct dra *dra)
{
    unsigned int i;

    /* restore dra timer_en and opipe down waterline */
    writel(dra->fifo_timer_en, dra->regs + DRA_TIMER_EN);
    for (i = 0; i < DRA_OPIPE_ALLOC_LEVELS; i++) {
        writel(dra->opipes[i].fifo.dthrl, dra->regs + DRA_OPIPE_DN_THRH(i));
    }
    writel(dra->release.fifo.uthrl, dra->regs + DRA_RLS_POOL_UP_THRH);

    return 0;
}

int dra_hal_prepare(struct dra *dra)
{
    unsigned int i;
    unsigned int idx;

    for (i = 0; i < dra->max_cpu_ipipes; i++) {
        idx = dra->cpu_ipipes[i].idx;
        writel(0, dra->regs + DRA_IPIPE_CTRL(idx));
    }
    return 0;
}

void dra_hal_complete(struct dra *dra)
{
    unsigned int i;
    unsigned int idx;

    for (i = 0; i < dra->max_cpu_ipipes; i++) {
        idx = dra->cpu_ipipes[i].idx;
        writel(1, dra->regs + DRA_IPIPE_CTRL(idx));
    }
}

void dra_detach(struct dra *dra)
{
    int i, idx;

    writel_relaxed(0, dra->regs + DRA_IPIPE_CTRL(DRA_IPIPE_FOR_PFA_512));
    writel_relaxed(0, dra->regs + DRA_IPIPE_CTRL(DRA_IPIPE_FOR_PFA_2K));
    writel_relaxed(0, dra->regs + DRA_IPIPE_CTRL(DRA_IPIPE_FOR_PFA_TFT_512));
    writel_relaxed(0, dra->regs + DRA_IPIPE_CTRL(DRA_IPIPE_FOR_PFA_TFT_2K));

    for (i = 0; i < dra->max_cpu_ipipes; i++) {
        idx = dra->cpu_ipipes[i].idx;
        writel(0, dra->regs + DRA_IPIPE_CTRL(idx));
    }
}

void dra_fifo_reinit(struct dra *dra, struct dra_fifo *fifo, int level)
{
    writel_relaxed(DRA_LOWPHY_ADDR(fifo->phy), dra->regs + DRA_OPIPE_BASE_ADDR_L(level));
    writel_relaxed(DRA_HIGHPHY_ADDR(fifo->phy), dra->regs + DRA_OPIPE_BASE_ADDR_H(level));
    writel_relaxed(fifo->depth - 1, dra->regs + DRA_OPIPE_DEPTH(level));
    writel_relaxed(0, dra->regs + DRA_OPIPE_WPTR(level));
    writel_relaxed(0, dra->regs + DRA_OPIPE_RPTR(level));
    writel_relaxed(fifo->uthrl, dra->regs + DRA_OPIPE_UP_THRH(level));
    writel_relaxed(fifo->dthrl, dra->regs + DRA_OPIPE_DN_THRH(level));
    writel(1, dra->regs + DRA_OPIPE_CFG_DONE(level));
    fifo->read = 0;
    fifo->write = 0;
}

void dra_hds_transreport_hal(struct dra *dra, struct dra_debug_info *dbg_info)
{
    int level;

    dbg_info->irq_mask = readl(dra->regs + DRA_OPIPE_INT_MSK);
    dbg_info->irq_raw = readl(dra->regs + DRA_OPIPE_INT_RAW);

    for (level = 0; level < DRA_OPIPE_LEVEL_INVALID; level++) {
        dbg_info->opipe_dbg[level].wptr = readl(dra->regs + DRA_OPIPE_WPTR(level));
        dbg_info->opipe_dbg[level].rptr = readl(dra->regs + DRA_OPIPE_RPTR(level));
    }
}

void __dra_set_backup_regs(struct dra *dra, unsigned int idx, unsigned int start, unsigned int end)
{
    unsigned int num;

    num = dra->back_regs_num;
    if (idx < DRA_BACK_REGS_NUM) {
        num += dra->back[idx].num;
        if (num < DRA_DUMP_REG_NUM) {
            dra->back[idx].start = (char *)dra->regs + start;
            dra->back[idx].num = (end - start) / sizeof(unsigned int) + 1;
            dra->back_regs_num = num;
        }
    }
}

void dra_set_backup_regs(struct dra *dra)
{
    __dra_set_backup_regs(dra, 0, DRA_GLB_CTRL, DRA_HAC_BP_INVALID_DATA_H);
    __dra_set_backup_regs(dra, 1, DRA_OPIPE_REG_START, DRA_OPIPE_REG_END);
}

void dra_rls_fifo_init(struct dra *dra, struct dra_rls_ch *rls, unsigned int level){}

