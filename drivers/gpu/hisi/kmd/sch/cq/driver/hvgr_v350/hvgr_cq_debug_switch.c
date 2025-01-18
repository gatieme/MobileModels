/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_cq_debug_switch.h"
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <securec.h>

#include "hvgr_asid_api.h"
#include "hvgr_dm_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_datan_api.h"
#include "hvgr_sch_api.h"

#include "hvgr_cq_driver_adapt.h"
#include "hvgr_cq_schedule.h"
#include "hvgr_cq.h"
#include "hvgr_cq_data.h"
#include "hvgr_defs.h"
#include "dm/fcp/hvgr_fcp.h"
#include "hvgr_cq_queue.h"
#include "hvgr_regmap.h"
#include "hvgr_log_api.h"
#include "hvgr_file.h"
#include "hvgr_cq_driver_base.h"

static void hvgr_cq_write_data(struct hvgr_device * const gdev, uint64_t addr, uint32_t value)
{
	(void)hvgr_pm_request_gpu(gdev, false);

	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu not ready", __func__);
		goto out_unlock;
	}

	if (hvgr_sch_suspend(gdev) != 0) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu suspend fail", __func__);
		goto out_unlock;
	}
	hvgr_write_reg(gdev, addr, value);
	hvgr_sch_resume(gdev);
out_unlock:
	hvgr_pm_release_gpu(gdev);
}

static void hvgr_cq_write_channel_data(struct hvgr_device * const gdev, uint64_t addr0,
	uint64_t addr1, uint32_t value)
{
	(void)hvgr_pm_request_gpu(gdev, false);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu not ready", __func__);
		goto out_unlock;
	}

	if (hvgr_sch_suspend(gdev) != 0) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu suspend fail", __func__);
		goto out_unlock;
	}

	hvgr_write_reg(gdev, addr0, value);
	hvgr_write_reg(gdev, addr1, value);
	hvgr_sch_resume(gdev);
out_unlock:
	hvgr_pm_release_gpu(gdev);
}

static int hvgr_cq_check_count_and_buf(struct hvgr_device * const gdev, char *buf,
	const char __user *ubuf, size_t count)
{
	if (count > CQ_DEBUG_BUFF_LEN) {
		hvgr_err(gdev, HVGR_CQ, "[%s] count out of memory", __func__);
		return -1;
	}
	if (copy_from_user(buf, ubuf, count) != 0) {
		hvgr_err(gdev, HVGR_CQ, "[%s] copy_from_user is fail", __func__);
		return -1;
	}
	return 0;
}

static int hvgr_cq_work_mode_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.work_mode;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DBG_EN));
	mutex_unlock(&pm_pwr->power_lock);

	if (value & CQ_WORK_MODE_DEBUG)
		seq_puts(sfile, "debug\n");
	else
		seq_puts(sfile, "normal\n");

	return 0;
}

static int hvgr_cq_work_mode_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_work_mode_show, in->i_private);
}

static ssize_t hvgr_cq_work_mode_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	unsigned long flags;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "debug")) {
		gcqctx->hw_cfg.work_mode = CQ_WORK_MODE_DEBUG;
	} else if (strstr(buf, "normal") || strstr(buf, "default")) {
		gcqctx->hw_cfg.work_mode = CQ_WORK_MODE_NORMAL;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] work_mode import %s invalid", __func__, buf);
		goto out_fail;
	}

	spin_lock_irqsave(&gcqctx->schedule_lock, flags);

	hvgr_cq_append_flag_all_queue(gdev, CQ_KMD_CTX_MOD_WORKMODE, false);
	hvgr_pm_gpu_reset(gdev, GPU_RESET_TYPE_NORMAL);

	spin_unlock_irqrestore(&gcqctx->schedule_lock, flags);
	return count;

out_fail:
	return -EINVAL;
}

static int hvgr_cq_bc_send_mode_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		value = gdev->cq_dev.hw_cfg.bc_send_mode;
	} else {
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_BC_SEND_MODE));
		cq_get_u32_bit(value, 0);
	}
	mutex_unlock(&pm_pwr->power_lock);

	if (value & CQ_BC_SEND_PARALLEL)
		seq_puts(sfile, "parallel\n");
	else
		seq_puts(sfile, "interleave\n");
	return 0;
}

static int hvgr_cq_bc_send_mode_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_bc_send_mode_show, in->i_private);
}

static ssize_t hvgr_cq_bc_send_mode_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	uint32_t value;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gcqctx->hw_cfg.bc_send_mode;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_BC_SEND_MODE));
	mutex_unlock(&pm_pwr->power_lock);

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "parallel") || strstr(buf, "default")) {
		gcqctx->hw_cfg.bc_send_mode = CQ_BC_SEND_PARALLEL;
		cq_set_u32_bit(value, 0, 1);
	} else if (strstr(buf, "interleave")) {
		gcqctx->hw_cfg.bc_send_mode = CQ_BC_SEND_INTERLEAVE;
		cq_set_u32_bit(value, 0, 0);
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		goto out_fail;
	}
	hvgr_cq_write_data(gdev, cq_control_reg(gdev, CQ_BC_SEND_MODE), value);
	return count;

out_fail:
	return -EINVAL;
}

#if hvgr_version_ge(HVGR_V350)
static int hvgr_cq_rt_rbc_send_mode_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.rt_rbc_send_mode << 1;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_JOBCHANIN_SEND_MODE));
	mutex_unlock(&pm_pwr->power_lock);
	if (test_bit(1, &value))
		seq_puts(sfile, "parallel\n");
	else
		seq_puts(sfile, "interleave\n");
	return 0;
}

static int hvgr_cq_rt_rbc_send_mode_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_rt_rbc_send_mode_show, in->i_private);
}

static ssize_t hvgr_cq_rt_rbc_send_mode_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	uint32_t value;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gcqctx->hw_cfg.rt_rbc_send_mode;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_JOBCHANIN_SEND_MODE));
	mutex_unlock(&pm_pwr->power_lock);

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "parallel") || strstr(buf, "default")) {
		gcqctx->hw_cfg.rt_rbc_send_mode = CQ_RT_RBC_SEND_PARALLEL;
		cq_set_u32_bit(value, 1, 1);
	} else if (strstr(buf, "interleave")) {
		gcqctx->hw_cfg.rt_rbc_send_mode = CQ_RT_RBC_SEND_INTERLEAVE;
		cq_set_u32_bit(value, 1, 0);
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		goto out_fail;
	}
	hvgr_cq_write_data(gdev, cq_control_reg(gdev, CQ_JOBCHANIN_SEND_MODE), value);
	return count;

out_fail:
	return -EINVAL;
}
#endif
static int hvgr_cq_sch_ubind_time_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	seq_printf(sfile, "%lu\n", gcqctx->hw_cfg.cq_schedule_unbind_time);
	return 0;
}

static int hvgr_cq_sch_ubind_time_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_sch_ubind_time_show, in->i_private);
}

static ssize_t hvgr_cq_sch_ubind_time_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	unsigned long num = 0;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_schedule_unbind_time = CQ_SCH_TIME_ROBIN_MS;
	} else {
		if (kstrtoul(buf, 0, &num) != 0)
			goto out_fail;
		gcqctx->hw_cfg.cq_schedule_unbind_time = (uint32_t)num;
	}
	return count;
out_fail:
	return -EINVAL;
}

static int hvgr_cq_cl_affinity_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	/*
	 * All channels are configured at the same time.
	 * Read only channel0 and COMPUTE_LOW_IDX.
	 */

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_cl_affinity;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev,
			cq_bind_affinity_sub_channel(CQ_CHANNEL0, COMPUTE_IDX)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%lu\n", value);
	return 0;
}

static int hvgr_cq_cl_affinity_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_cl_affinity_show, in->i_private);
}

static ssize_t hvgr_cq_cl_affinity_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	uint32_t chn;

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_cl_affinity = CQ_AFFITNITY_DEFAULT;
	} else {
		unsigned long num = 0;

		if (kstrtoul(buf, 0, &num) != 0)
			goto out_fail;
		gcqctx->hw_cfg.cq_cl_affinity = (uint32_t)num;
	}

	for (chn = 0; chn < CQ_CHANNEL_NUM; chn++) {
		hvgr_cq_write_channel_data(gdev, cq_control_reg(gdev,
			cq_bind_affinity_sub_channel(chn, COMPUTE_IDX)),
			cq_control_reg(gdev, cq_bind_affinity_sub_channel(chn, COMPUTE_IDX)),
			gcqctx->hw_cfg.cq_cl_affinity);
		hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
			gdev->dm_dev.fcp_data->ctx, cq_bind_affinity_sub_channel(chn, COMPUTE_IDX),
			gcqctx->hw_cfg.cq_cl_affinity);
		hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
			gdev->dm_dev.fcp_data->ctx, cq_bind_affinity_sub_channel(chn, COMPUTE_IDX),
			gcqctx->hw_cfg.cq_cl_affinity);
	}

	return count;

out_fail:
	return -EINVAL;
}

static int hvgr_cq_bind_waitcycle_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_bind_waitcycle;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_waitcycle(CQ_CHANNEL0)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%lu\n", value);
	return 0;
}

static int hvgr_cq_bind_waitcycle_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_bind_waitcycle_show, in->i_private);
}

static ssize_t hvgr_cq_bind_waitcycle_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_bind_waitcycle = CQ_BIND_WAITCYCLE_DEFAULT;
	} else {
		unsigned long num = 0;

		if (kstrtoul(buf, 0, &num) != 0)
			goto out_fail;
		gcqctx->hw_cfg.cq_bind_waitcycle = (uint32_t)num;
	}

	hvgr_cq_write_channel_data(gdev, cq_control_reg(gdev, cq_bind_waitcycle(CQ_CHANNEL0)),
		cq_control_reg(gdev, cq_bind_waitcycle(CQ_CHANNEL1)),
		gcqctx->hw_cfg.cq_bind_waitcycle);
	hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
		gdev->dm_dev.fcp_data->ctx, cq_bind_waitcycle(CQ_CHANNEL0), gcqctx->hw_cfg.cq_bind_waitcycle);
	hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
		gdev->dm_dev.fcp_data->ctx, cq_bind_waitcycle(CQ_CHANNEL1), gcqctx->hw_cfg.cq_bind_waitcycle);
	return count;

out_fail:
	return -EINVAL;
}

static int hvgr_cq_queue_empty_timeout_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_queue_empty_timeout;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev,
			cq_bind_empty_timeout(CQ_CHANNEL0)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%lu\n", value);
	return 0;
}

static int hvgr_cq_queue_empty_timeout_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_queue_empty_timeout_show, in->i_private);
}

static ssize_t hvgr_cq_queue_empty_timeout_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_queue_empty_timeout = CQ_BIND_TIME_OUT_VALUE;
	} else {
		unsigned long num = 0;

		if (kstrtoul(buf, 0, &num) != 0)
			goto out_fail;
		gcqctx->hw_cfg.cq_queue_empty_timeout = (uint32_t)num;
	}

	hvgr_cq_write_channel_data(gdev, cq_control_reg(gdev, cq_bind_empty_timeout(CQ_CHANNEL0)),
		cq_control_reg(gdev, cq_bind_empty_timeout(CQ_CHANNEL1)),
		gcqctx->hw_cfg.cq_queue_empty_timeout);
	return count;

out_fail:
	return -EINVAL;
}

static int hvgr_cq_wait_semp_timeout_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_semp_wait_timeout;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev,
			cq_bind_sem_wait_timeout(CQ_CHANNEL0)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%lu\n", value);
	return 0;
}

static int hvgr_cq_wait_semp_timeout_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_wait_semp_timeout_show, in->i_private);
}

static ssize_t hvgr_cq_wait_semp_timeout_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_semp_wait_timeout = CQ_BIND_TIME_OUT_VALUE;
	} else {
		unsigned long num = 0;

		if (kstrtoul(buf, 0, &num) != 0)
			goto out_fail;
		gcqctx->hw_cfg.cq_semp_wait_timeout = (uint32_t)num;
	}

	hvgr_cq_write_channel_data(gdev, cq_control_reg(gdev, cq_bind_sem_wait_timeout(CQ_CHANNEL0)),
		cq_control_reg(gdev, cq_bind_sem_wait_timeout(CQ_CHANNEL1)),
		gcqctx->hw_cfg.cq_semp_wait_timeout);

	return count;

out_fail:
	return -EINVAL;
}

static void hvgr_cq_set_multi_chain(struct hvgr_device * const gdev,
	struct hvgr_cq_dev * const gcqctx, uint32_t channel_id)
{
	uint32_t value = 0;
	int i;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		goto out;
	for (i = RENDER_IDX; i < SUBCHN_MAX_IDX; i++) {
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_config(channel_id, i)));
		cq_set_u32_bit4(value, gcqctx->hw_cfg.cq_multi_chain_enable);
		hvgr_write_reg(gdev, cq_control_reg(gdev, cq_bind_config(channel_id, i)), value);
		hvgr_datan_jobtrace(gdev->dm_dev.fcp_data->ctx, JOBTRACE_TYPE_OBJ, KDATAN_TL_WRITE_REG,
			gdev->dm_dev.fcp_data->ctx, cq_bind_config(channel_id, i), value);
	}
out:
	mutex_unlock(&pm_pwr->power_lock);
}

static int hvgr_cq_multi_chain_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	uint32_t val;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_multi_chain_enable;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev,
			cq_bind_config(CQ_CHANNEL0, RENDER_IDX)));
	mutex_unlock(&pm_pwr->power_lock);

	val = cq_get_u32_bit4(value);
	if (val & CQ_DISABLE_MULTI_CHAIN)
		seq_puts(sfile, "disabled\n");
	else
		seq_puts(sfile, "enable\n");

	return 0;
}

static int hvgr_cq_multi_chain_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_multi_chain_show, in->i_private);
}

static ssize_t hvgr_cq_multi_chain_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	uint32_t chn;

	(void)hvgr_pm_request_gpu(gdev, false);

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "disable") || strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_multi_chain_enable = CQ_DISABLE_MULTI_CHAIN;
	} else if (strstr(buf, "enable")) {
		gcqctx->hw_cfg.cq_multi_chain_enable = CQ_ENABLE_MULTI_CHAIN;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		goto out_fail;
	}

	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu not ready", __func__);
		goto out_fail;
	}

	if (hvgr_sch_suspend(gdev) != 0) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu suspend fail", __func__);
		goto out_fail;
	}

	for (chn = 0; chn < CQ_CHANNEL_NUM; chn++)
		hvgr_cq_set_multi_chain(gdev, gcqctx, chn);

	hvgr_sch_resume(gdev);

	hvgr_pm_release_gpu(gdev);
	return count;

out_fail:
	hvgr_pm_release_gpu(gdev);
	return -EINVAL;
}

static int hvgr_cq_phychn_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	seq_printf(sfile, "%s %s\n",
		gcqctx->channel_info[CQ_PRIORITY_LOW].available ? "enabled" : "disabled",
		gcqctx->channel_info[CQ_PRIORITY_HIGH].available ? "enabled" : "disabled");

	return 0;
}

static int hvgr_cq_phychn_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_phychn_show, in->i_private);
}

static ssize_t hvgr_cq_phychn_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	char chn_low_buf[CQ_DEBUGFS_NAME_LEN_MAX] = {0};
	char chn_high_buf[CQ_DEBUGFS_NAME_LEN_MAX] = {0};
	int items;

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	items = sscanf_s(buf, "%s %s", chn_low_buf, CQ_DEBUGFS_NAME_LEN_MAX, chn_high_buf,
		CQ_DEBUGFS_NAME_LEN_MAX);
	if (items != CQ_CHANNEL_NUM) {
		hvgr_err(gdev, HVGR_CQ, "[%s] items(%d) not right\n", __func__, items);
		goto out_fail;
	}

	gcqctx->channel_info[CQ_CHANNEL0].available =
		strstr(chn_low_buf, "enable") ? true : false;
	gcqctx->channel_info[CQ_CHANNEL1].available =
		strstr(chn_high_buf, "enable") ? true : false;
	gcqctx->channel_info[CQ_CHANNEL2].available =
		strstr(chn_low_buf, "enable") ? true : false;
	gcqctx->channel_info[CQ_CHANNEL3].available =
		strstr(chn_high_buf, "enable") ? true : false;

	return count;

out_fail:
	return -EINVAL;
}

#define CQ_STATUS_INFO_MAX_LEN 256

static int hvgr_cq_status_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	int wrlen = 0;
	struct cq_channel *chn = NULL;
	struct hvgr_cq_ctx *cq_ctx = NULL;
	int idx;
	char buffer[CQ_STATUS_INFO_MAX_LEN] = {0};
	uint32_t status_reg;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		seq_puts(sfile, "GPU NO POWER\n");
		mutex_unlock(&pm_pwr->power_lock);
		return 0;
	}

	wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN, CQ_STATUS_INFO_MAX_LEN - 1,
		"gdev. ver = 14\n");

	for (idx = 0; idx < CQ_CHANNEL_NUM; idx++) {
		chn = &gcqctx->channel_info[idx];
		cq_ctx = chn->running_queue;
		if (cq_ctx == NULL) {
			wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
				CQ_STATUS_INFO_MAX_LEN - wrlen - 1,
				"chn %d : IDLE\n", idx);
			continue;
		}

		status_reg = hvgr_get_bind_status(gdev, idx);
		wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
			CQ_STATUS_INFO_MAX_LEN - wrlen - 1,
			"chn %d : ctx_%u : %d (%d:%d) : %d. %d, run_cnt = %d, status = 0x%x\n",
			idx, cq_ctx->ctx->id, cq_ctx->queue_id,
			cq_ctx->sw_wr_ctx->queue_put_index,
			cq_ctx->sw_wr_ctx->queue_get_index,
			cq_ctx->status, cq_ctx->get_index,
			cq_ctx->running_counter, status_reg);
	}

	mutex_unlock(&pm_pwr->power_lock);

	wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
		CQ_STATUS_INFO_MAX_LEN - wrlen - 1,
		"channel schedules : %d\n", gcqctx->channel_sche_times);

	seq_printf(sfile, "%s\n", buffer);
	return 0;
}


static int hvgr_cq_status_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_status_show, in->i_private);
}


static int hvgr_cq_unbind_timeout_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	seq_printf(sfile, "reset_timeout_normal:%lu reset_timeout_cl:%lu\n",
		gcqctx->reset_timeout_normal, gcqctx->reset_timeout_cl);
	return 0;
}

static int hvgr_cq_unbind_timeout_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_unbind_timeout_show, in->i_private);
}

static ssize_t hvgr_cq_unbind_timeout_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	int items;

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "default")) {
		gcqctx->reset_timeout_normal = CQ_SCH_UNBIND_TIME_OUT;
		if (!hvgr_is_fpga(gdev))
			gcqctx->reset_timeout_cl = CQ_SCH_CL_UNBIND_TIME_OUT;
		else
			gcqctx->reset_timeout_cl = CQ_SCH_CL_UNBIND_TIME_OUT_FPGA;
	} else {
		items = sscanf_s(buf, "%lu %lu", &gcqctx->reset_timeout_normal,
			&gcqctx->reset_timeout_cl);
		if (items != 2) {
			hvgr_err(gdev, HVGR_CQ, "sscanf_s failed items = %d\n", items);
			gcqctx->reset_timeout_normal = CQ_SCH_UNBIND_TIME_OUT;
			if (!hvgr_is_fpga(gdev))
				gcqctx->reset_timeout_cl = CQ_SCH_CL_UNBIND_TIME_OUT;
			else
				gcqctx->reset_timeout_cl = CQ_SCH_CL_UNBIND_TIME_OUT_FPGA;
			goto out_fail;
		}
	}
	return count;
out_fail:
	return -EINVAL;
}

static void hvgr_cq_sch_time_enable(struct seq_file *sfile,
	struct cq_dfx_time *cq_schtime_dfx, int i)
{
	uint64_t submitalloc_dfx_time;
	uint64_t sch_time;
	uint64_t run_time;

	if (cq_schtime_dfx->submit_time > 0) {
		seq_printf(sfile, "queue number:%d bind_count:%d\n", i, cq_schtime_dfx->bind_count);
		seq_printf(sfile, "queue number:%d unbind_count:%d\n",
			i, cq_schtime_dfx->unbind_count);

		submitalloc_dfx_time = cq_schtime_dfx->submit_time - cq_schtime_dfx->alloc_time;
		seq_printf(sfile, "queue number:%d submitalloc_dfx_time:%lld us\n",
			i, submitalloc_dfx_time / 1000);

		seq_printf(sfile, "queue number: %d run_time:%lld us\n", i,
			cq_schtime_dfx->run_time / 1000);

		if (cq_schtime_dfx->sch_is_free) {
			run_time = cq_schtime_dfx->free_time - cq_schtime_dfx->submit_time;
			seq_printf(sfile, "queue number:%d total_time:%lld us\n",
				i, run_time / 1000);
		} else {
			seq_printf(sfile, "not free\n");
			run_time = cq_schtime_dfx->unbind_time - cq_schtime_dfx->submit_time;
			seq_printf(sfile, "queue number:%d total_time:%lld us\n",
				i, run_time / 1000);
		}
	}
}

static int hvgr_cq_sch_time_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	struct cq_dfx_time *cq_schtime_dfx  = NULL;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx_tmp = NULL;

	seq_printf(sfile, "%s\n", gcqctx->sch_time_enable ? "enabled" : "disabled");

	mutex_lock(&gdev->dm_dev.ctx_list_mutex);
	list_for_each_entry_safe(ctx_tmp, tmp, &gdev->dm_dev.ctx_list, dev_link) {
		for (int i = 0; i < CQ_QUEUE_NUM_PER_CTX; i++) {
			cq_schtime_dfx = &ctx_tmp->ctx_cq.cq_ctx[i].cq_schtime_dfx;
			hvgr_cq_sch_time_enable(sfile, cq_schtime_dfx , i);
		}
	}
	mutex_unlock(&gdev->dm_dev.ctx_list_mutex);

	return 0;
}

static int hvgr_cq_sch_time_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_sch_time_show, in->i_private);
}

static ssize_t hvgr_cq_sch_time_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	struct cq_dfx_time *cq_schtime_dfx  = NULL;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx_tmp = NULL;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	bool is_enable = false;

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		return -EINVAL;


	if (strstr(buf, "disable") || strstr(buf, "default")) {
		gcqctx->sch_time_enable = false;
	} else if (strstr(buf, "enable")) {
		gcqctx->sch_time_enable = true;
	} else if (sysfs_streq("clear", buf)) {
		mutex_lock(&gdev->dm_dev.ctx_list_mutex);
		list_for_each_entry_safe(ctx_tmp, tmp, &gdev->dm_dev.ctx_list, dev_link) {
			for (int i = 0; i < CQ_QUEUE_NUM_PER_CTX; i++) {
				cq_schtime_dfx = &ctx_tmp->ctx_cq.cq_ctx[i].cq_schtime_dfx;
				(void)memset_s(cq_schtime_dfx, sizeof(*cq_schtime_dfx),
					0, sizeof(*cq_schtime_dfx));
			}
		}
		mutex_unlock(&gdev->dm_dev.ctx_list_mutex);
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		return -EINVAL;
	}
	return count;
}

static int hvgr_cq_entry_boundary_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	uint32_t value;
	bool bit_val;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		bit_val = gdev->cq_dev.hw_cfg.cq_entry_boundary;
	} else {
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG));
		bit_val = cq_get_u32_bit(value, CQ_ENTRY_BOUNDARY_EN_BIT);
	}
	mutex_unlock(&pm_pwr->power_lock);

	if (bit_val)
		seq_puts(sfile, "enable\n");
	else
		seq_puts(sfile, "disable\n");

	return 0;
}

static void hvgr_cq_set_entry_boundary(struct hvgr_device * const gdev, bool is_enable)
{
	uint32_t value;
	uint32_t chn;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		hvgr_err(gdev, HVGR_CQ, "[%s] fail, pm not ready", __func__);
		goto out;
	}

	/* set CQ_DFX_CONFIG cq_entry_boundary_irq_en */
	value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG));
	cq_set_u32_bit(value, CQ_ENTRY_BOUNDARY_EN_BIT, is_enable);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG), value);

	/* set CQ_IRQ_MASK irq_entry_boudary_mask */
	for (chn = 0; chn < CQ_CHANNEL_NUM; chn++) {
		if (is_enable)
			hvgr_write_reg(gdev, cq_control_reg(gdev, cq_irq_clear(chn)),
				1 << CQ_IRQ_ENTRY_BOUNDARY_BIT);

		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_irq_mask(chn)));
		cq_set_u32_bit(value, CQ_IRQ_ENTRY_BOUNDARY_BIT, is_enable);
		hvgr_write_reg(gdev, cq_control_reg(gdev, cq_irq_mask(chn)), value);
	}
out:
	mutex_unlock(&pm_pwr->power_lock);
}

static int hvgr_cq_entry_boundary_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_entry_boundary_show, in->i_private);
}

static ssize_t hvgr_cq_entry_boundary_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		return -EINVAL;

	if (strstr(buf, "enable") || strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_entry_boundary = HVGR_ENABLE;
	} else if (strstr(buf, "disable")) {
		gcqctx->hw_cfg.cq_entry_boundary = HVGR_DISABLE;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		return -EINVAL;
	}

	hvgr_pm_request_gpu(gdev, false);

	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu not ready", __func__);
		goto out_fail;
	}

	if (hvgr_cq_suspend(gdev) != 0) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu suspend fail", __func__);
		goto out_fail;
	}

	hvgr_cq_set_entry_boundary(gdev, gcqctx->hw_cfg.cq_entry_boundary);

	hvgr_cq_resume(gdev);

	hvgr_pm_release_gpu(gdev);
	return count;

out_fail:
	hvgr_pm_release_gpu(gdev);
	return -EINVAL;
}

static int hvgr_cq_order_dump_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	uint32_t value;
	bool order_enable;
	char *status[] = {
		"stop",
		"start"
	};

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		value = gdev->cq_dev.hw_cfg.cq_order_dump;
	} else {
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG));
		order_enable = cq_get_u32_bit(value, CQ_PRINT_ORDER_EN_BIT);
	}
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%s\n", status[order_enable]);
	return 0;
}

static int hvgr_cq_sync_dump_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	uint32_t value;
	bool sync_enable;
	char *status[] = {
		"stop",
		"start"
	};

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		value = gdev->cq_dev.hw_cfg.cq_sync_dump;
	} else {
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG));
		sync_enable = cq_get_u32_bit(value, CQ_PRINT_SYNC_EN_BIT);
	}
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%s\n", status[sync_enable]);
	return 0;
}

static int hvgr_cq_order_dump_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_order_dump_show, in->i_private);
}

static int hvgr_cq_sync_dump_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_sync_dump_show, in->i_private);
}

static void hvgr_cq_set_ordersync_dump(struct hvgr_device * const gdev,
	bool is_enable, bool is_order)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	uint32_t value;
	uint32_t chn;
	uint32_t dfx_bit = is_order ? CQ_PRINT_ORDER_EN_BIT : CQ_PRINT_SYNC_EN_BIT;
	uint32_t irq_bit = is_order ? CQ_IRQ_ORDER_BUF_FULL_BIT : CQ_IRQ_SYNC_BUF_FULL_BIT;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		hvgr_err(gdev, HVGR_CQ, "[%s] fail, pm not ready", __func__);
		goto out;
	}

	/* set CQ_DFX_CONFIG cq_print_order_en, cq_print_sync_en */
	value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG));
	cq_set_u32_bit(value, dfx_bit, is_enable);
	hvgr_write_reg(gdev, cq_control_reg(gdev, CQ_DFX_CONFIG), value);

	/* set CQ_IRQ_MASK irq_sync_buf_full_mask, irq_order_buf_full_mask */
	for (chn = 0; chn < CQ_CHANNEL_NUM; chn++) {
		hvgr_write_reg(gdev, cq_control_reg(gdev, cq_irq_clear(chn)), 1 << irq_bit);

		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_irq_mask(chn)));
		cq_set_u32_bit(value, irq_bit, is_enable);
		hvgr_write_reg(gdev, cq_control_reg(gdev, cq_irq_mask(chn)), value);
	}
out:
	mutex_unlock(&pm_pwr->power_lock);
}

static void hvgr_cq_entry_buf_dump_by_ctx(struct hvgr_device * const gdev,
	struct hvgr_ctx * ctx, bool is_order)
{
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	uint32_t dump_pid = is_order ? gcqctx->order_dump_pid : gcqctx->sync_dump_pid;
	uint32_t idx;
	void *kva = NULL;
	struct hvgr_cq_ctx *cq_ctx = NULL;

	for (idx = 0; idx < ARRAY_SIZE(ctx->ctx_cq.cq_ctx); idx++) {
		if (ctx->ctx_cq.cq_ctx[idx].sw_wr_ctx == NULL)
			continue;

		cq_ctx = &ctx->ctx_cq.cq_ctx[idx];
		if ((dump_pid == 0) || ((uint32_t)ctx->pid == dump_pid)) {
			hvgr_cq_ordersync_entry_dump(gdev, cq_ctx, is_order, false);
		} else {
			kva = hvgr_cq_get_entry_buffer_kva(cq_ctx, is_order);
			hvgr_cq_clear_buf_full(kva, cq_ctx, is_order, false);
		}
	}
}

static void hvgr_cq_entry_buf_dump(struct hvgr_device * const gdev, bool is_order)
{
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx_tmp = NULL;

	mutex_lock(&gdev->dm_dev.ctx_list_mutex);
	list_for_each_entry_safe(ctx_tmp, tmp, &gdev->dm_dev.ctx_list, dev_link) {
		if (unlikely(ctx_tmp == NULL))
			continue;

		hvgr_cq_entry_buf_dump_by_ctx(gdev, ctx_tmp, is_order);
	}
	mutex_unlock(&gdev->dm_dev.ctx_list_mutex);
	return;
}

enum cq_entry_dump_op {
	ENTRY_DUMP_START = 0,
	ENTRY_DUMP_STOP = 1,
	ENTRY_DUMP_ERR_RUNNING = 2,
	ENTRY_DUMP_ERR_NOTSATRT = 3
};

static ssize_t hvgr_cq_entry_dump_op(struct hvgr_device * const gdev, bool is_order,
	enum cq_entry_dump_op action)
{
	if ((action != ENTRY_DUMP_START) && (action != ENTRY_DUMP_STOP)) {
		hvgr_err(gdev, HVGR_CQ, "[%s] wrong action[%u], do nothing.",
			__func__, (uint32_t)action);
		return -EINVAL;
	}

	if (action == ENTRY_DUMP_START)
		(void)hvgr_file_make_dir(HVGR_ENTRY_DMUP_DIR, HVGR_ENTRY_DMUP_DIR_MODE);

	hvgr_pm_request_gpu(gdev, false);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu not ready", __func__);
		goto out_fail;
	}

	if (hvgr_cq_suspend(gdev) != 0) {
		hvgr_err(gdev, HVGR_CQ, "[%s] gpu suspend fail", __func__);
		goto out_fail;
	}

	if (action == ENTRY_DUMP_STOP)
		hvgr_cq_entry_buf_dump(gdev, is_order);

	hvgr_cq_set_ordersync_dump(gdev, action == ENTRY_DUMP_START, is_order);

	hvgr_cq_resume(gdev);

	hvgr_pm_release_gpu(gdev);
	return 0;

out_fail:
	hvgr_pm_release_gpu(gdev);
	return -EINVAL;
}

static enum cq_entry_dump_op hvgr_cq_get_action(bool last_cfg, bool new_cfg)
{
	enum cq_entry_dump_op action;
	if (new_cfg == HVGR_ENABLE) {
		if (last_cfg == HVGR_DISABLE)
			action = ENTRY_DUMP_START;
		else
			action = ENTRY_DUMP_ERR_RUNNING;
	} else {
		if (last_cfg == HVGR_DISABLE)
			action = ENTRY_DUMP_ERR_NOTSATRT;
		else
			action = ENTRY_DUMP_STOP;
	}

	return action;
}

static ssize_t hvgr_cq_ordersync_dump_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos, bool is_order)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	int items;
	uint32_t enable_control;
	uint32_t pid;
	bool last_cfg = is_order ? gcqctx->hw_cfg.cq_order_dump : gcqctx->hw_cfg.cq_sync_dump;
	bool *set_cfg = is_order ? &gcqctx->hw_cfg.cq_order_dump : &gcqctx->hw_cfg.cq_sync_dump;
	uint32_t *set_pid = is_order ? &gcqctx->order_dump_pid : &gcqctx->sync_dump_pid;
	ssize_t ret;
	enum cq_entry_dump_op action;

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		return -EINVAL;

	if (strstr(buf, "default") || strstr(buf, "disable")) {
		*set_cfg = HVGR_DISABLE;
	} else {
		items = sscanf_s(buf, "%u %u", &enable_control, &pid);
		if (items != 2) {
			hvgr_err(gdev, HVGR_CQ, "sscanf_s failed items = %d\n", items);
			return -EINVAL;
		}

		if (enable_control) {
			*set_cfg = HVGR_ENABLE;
			*set_pid = pid;
		} else {
			*set_cfg = HVGR_DISABLE;
		}
	}

	action = hvgr_cq_get_action(last_cfg, *set_cfg);
	hvgr_err(gdev, HVGR_CQ, "[%s] set entry dump is_order[%u], pid[%u], action[%u]\n",
		__func__, is_order, *set_pid, (uint32_t)action);
	ret = hvgr_cq_entry_dump_op(gdev, is_order, action);
	if (ret == 0)
		return count;

	return -EINVAL;
}

static ssize_t hvgr_cq_order_dump_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	return hvgr_cq_ordersync_dump_write(file, ubuf, count, ppos, ORDER_DUMP);
}

static ssize_t hvgr_cq_sync_dump_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	return hvgr_cq_ordersync_dump_write(file, ubuf, count, ppos, SYNC_DUMP);
}

static const struct file_operations cq_bc_send_mode_config = {
	.open = hvgr_cq_bc_send_mode_open,
	.read = seq_read,
	.write = hvgr_cq_bc_send_mode_write,
	.llseek = seq_lseek,
	.release = single_release,
};

#if hvgr_version_ge(HVGR_V350)
static const struct file_operations cq_rt_rbc_send_mode_config = {
	.open = hvgr_cq_rt_rbc_send_mode_open,
	.read = seq_read,
	.write = hvgr_cq_rt_rbc_send_mode_write,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif

static const struct file_operations cq_sch_unbind_time_config = {
	.open = hvgr_cq_sch_ubind_time_open,
	.read = seq_read,
	.write = hvgr_cq_sch_ubind_time_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_cl_affinity_config = {
	.open = hvgr_cq_cl_affinity_open,
	.read = seq_read,
	.write = hvgr_cq_cl_affinity_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_bind_waitcycle_config = {
	.open = hvgr_cq_bind_waitcycle_open,
	.read = seq_read,
	.write = hvgr_cq_bind_waitcycle_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_queue_empty_timeout_config = {
	.open = hvgr_cq_queue_empty_timeout_open,
	.read = seq_read,
	.write = hvgr_cq_queue_empty_timeout_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_wait_semp_timeout_config = {
	.open = hvgr_cq_wait_semp_timeout_open,
	.read = seq_read,
	.write = hvgr_cq_wait_semp_timeout_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_multi_chain_config = {
	.open = hvgr_cq_multi_chain_open,
	.read = seq_read,
	.write = hvgr_cq_multi_chain_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_phychn_config = {
	.open = hvgr_cq_phychn_open,
	.read = seq_read,
	.write = hvgr_cq_phychn_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_status_info = {
	.open = hvgr_cq_status_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_unbind_timeout_config = {
	.open = hvgr_cq_unbind_timeout_open,
	.read = seq_read,
	.write = hvgr_cq_unbind_timeout_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_sch_time_config = {
	.open = hvgr_cq_sch_time_open,
	.read = seq_read,
	.write = hvgr_cq_sch_time_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_entry_boundary_config = {
	.open = hvgr_cq_entry_boundary_open,
	.read = seq_read,
	.write = hvgr_cq_entry_boundary_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_order_dump_config = {
	.open = hvgr_cq_order_dump_open,
	.read = seq_read,
	.write = hvgr_cq_order_dump_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_sync_dump_config = {
	.open = hvgr_cq_sync_dump_open,
	.read = seq_read,
	.write = hvgr_cq_sync_dump_write,
	.llseek = seq_lseek,
	.release = single_release,
};

struct hvgr_cq_debugfs_files cq_debugs_files[] = {
	{"cq_bc_send_mode", 0644, &cq_bc_send_mode_config},
#if hvgr_version_ge(HVGR_V350)
	{"cq_rt_rbc_send_mode", 0644, &cq_rt_rbc_send_mode_config},
#endif
	{"cq_cl_affinity", 0644, &cq_cl_affinity_config},
	{"cq_bind_waitcycle", 0644, &cq_bind_waitcycle_config},
	{"cq_queue_empty_timeout", 0644, &cq_queue_empty_timeout_config},
	{"cq_semp_wait_timeout", 0644, &cq_wait_semp_timeout_config},
	{"cq_multi_chain", 0644, &cq_multi_chain_config},
	{"cq_sch_unbind_time", 0644, &cq_sch_unbind_time_config},
	{"cq_phychn_switch", 0644, &cq_phychn_config},
	{"cq_status", 0644, &cq_status_info},
	{"cq_unbind_timeout", 0644, &cq_unbind_timeout_config},
	{"cq_schtime_show", 0644, &cq_sch_time_config},
	{"cq_entry_boundary", 0644, &cq_entry_boundary_config},
	{"cq_order_dump", 0644, &cq_order_dump_config},
	{"cq_sync_dump", 0644, &cq_sync_dump_config},
};

int hvgr_cq_debugfs_init(struct hvgr_device * const gdev)
{
	uint32_t idx;
	struct dentry *cq_debugfs_directory = debugfs_create_dir("cq", gdev->root_debugfs_dir);

	if (cq_debugfs_directory == NULL) {
		hvgr_err(gdev, HVGR_CQ, "Couldn't create cq debugfs directory\n");
		return -ENOMEM;
	}

	for (idx = 0; idx < ARRAY_SIZE(cq_debugs_files); idx++)
		debugfs_create_file(cq_debugs_files[idx].name, cq_debugs_files[idx].mode,
			cq_debugfs_directory, gdev, cq_debugs_files[idx].fops);

	return 0;
}
