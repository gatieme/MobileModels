/*
 * npu_pm_framework.h
 *
 * about npu pm
 *
 * Copyright (c) 2012-2020 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef __NPU_PM_FRAMEWORK_H
#define __NPU_PM_FRAMEWORK_H

#include <linux/types.h>
#include <linux/irq.h>
#include <linux/jiffies.h>
#include <linux/list.h>
#include <linux/semaphore.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/io.h>
#include <linux/delay.h>

#include "npu_common.h"
#include "npu_proc_ctx.h"
#include "npu_except_mgr.h"

typedef int (*software_ops_func)(u8 dev_id);
typedef void (*hardware_ops_func)(void);

struct npu_dev_res_software_ops {
	software_ops_func npu_res_software_init;
	software_ops_func npu_res_software_available;
	software_ops_func npu_res_software_recycle;
	software_ops_func npu_res_software_deinit;
	struct list_head list;
};

struct npu_dev_res_hardware_ops {
	hardware_ops_func npu_res_hardware_init;
	hardware_ops_func npu_res_hardware_available;
	hardware_ops_func npu_res_hardware_recycle;
	hardware_ops_func npu_res_hardware_deinit;
	struct list_head list;
};

enum npu_power_stage {
	NPU_PM_DOWN,
	NPU_PM_NPUCPU,
	NPU_PM_SMMU,
	NPU_PM_TS,
	NPU_PM_UP
};

int npu_powerup(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, u32 work_mode);

int npu_powerdown(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx);

int npu_pm_enter_workmode(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, u32 workmode);

int npu_pm_exit_workmode(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, u32 workmode);

int npu_pm_proc_send_task_enter_wm(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, uint32_t work_mode);

int npu_pm_proc_release_task_exit_wm(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, u32 num, u32 work_mode);

int npu_pm_proc_ioctl_enter_wm(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, npu_work_mode_info_t *wm_info);

int npu_pm_proc_ioctl_exit_wm(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, u32 work_mode);

int npu_pm_proc_release_exit_wm(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx);

int npu_pm_proc_ffrt_enter_wm(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, u32 work_mode);

int npu_pm_proc_ffrt_exit_wm(struct npu_proc_ctx *proc_ctx,
	struct npu_dev_ctx *dev_ctx, u32 work_mode);

int npu_ctrl_core(u8 dev_id, u32 core_num);

int npu_enable_interframe_ilde(struct npu_proc_ctx *proc_ctx, uint32_t enable);

void npu_pm_adapt_init(struct npu_dev_ctx *dev_ctx);

int npu_pm_handle_exception(struct npu_dev_ctx *dev_ctx, struct npu_exception_record* er);

int npu_pm_handle_power_up(struct npu_dev_ctx *dev_ctx);

#endif
