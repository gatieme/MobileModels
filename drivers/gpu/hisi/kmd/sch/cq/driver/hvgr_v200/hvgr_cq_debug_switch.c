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
#include "hvgr_log_api.h"
#include "hvgr_sch_api.h"

#include "hvgr_cq_driver_adapt.h"
#include "hvgr_cq_schedule.h"
#include "hvgr_cq.h"
#include "hvgr_cq_data.h"
#include "hvgr_defs.h"
#include "dm/hvgr_dm_defs.h"
#include "hvgr_cq_queue.h"
#include "hvgr_regmap.h"

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
	return (ssize_t)count;

out_fail:
	return -EINVAL;
}

static int hvgr_cq_sch_mode_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_sch_mode;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_SCH_MODE));
	mutex_unlock(&pm_pwr->power_lock);

	if (value & CQ_SCH_MODE_PARALLEL)
		seq_puts(sfile, "parallel\n");
	else
		seq_puts(sfile, "serial\n");

	return 0;
}

static int hvgr_cq_sch_mode_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_sch_mode_show, in->i_private);
}

static ssize_t hvgr_cq_sch_mode_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "parallel") || strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_sch_mode = CQ_SCH_MODE_PARALLEL;
	} else if (strstr(buf, "serial")) {
		gcqctx->hw_cfg.cq_sch_mode = CQ_SCH_MODE_SERIAL;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		goto out_fail;
	}

	hvgr_cq_write_data(gdev, cq_control_reg(gdev, CQ_SCH_MODE), gcqctx->hw_cfg.cq_sch_mode);
	return (ssize_t)count;

out_fail:
	return -EINVAL;
}

static int hvgr_cq_bc_send_mode_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.bc_send_mode;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, CQ_BC_SEND_MODE));
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
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "interleave") || strstr(buf, "default")) {
		gcqctx->hw_cfg.bc_send_mode = CQ_BC_SEND_INTERLEAVE;
	} else if (strstr(buf, "parallel")) {
		gcqctx->hw_cfg.bc_send_mode = CQ_BC_SEND_PARALLEL;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		goto out_fail;
	}

	hvgr_cq_write_data(gdev, cq_control_reg(gdev, CQ_BC_SEND_MODE),
		gcqctx->hw_cfg.bc_send_mode);
	return (ssize_t)count;

out_fail:
	return -EINVAL;
}

static int hvgr_cq_timeout_func_enable_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	uint32_t val;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_semp_wait_timeout_switch;
	else
		/* All channels are configured at the same time. Read only channel0. */
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_misccfg(CQ_CHANNEL0)));
	mutex_unlock(&pm_pwr->power_lock);

	val = cq_get_u32_bit4(value);
	if (val & CQ_ENABLE_TIMEOUT_SWITCH)
		seq_puts(sfile, "enabled\n");
	else
		seq_puts(sfile, "disabled\n");

	return 0;
}

static int hvgr_cq_timeout_func_enable_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_timeout_func_enable_show, in->i_private);
}

static ssize_t hvgr_cq_timeout_func_enable_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	uint32_t value;

	(void)hvgr_pm_request_gpu(gdev, false);

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (strstr(buf, "enable")) {
		gcqctx->hw_cfg.cq_semp_wait_timeout_switch = CQ_ENABLE_TIMEOUT_SWITCH;
	} else if (strstr(buf, "disable") || strstr(buf, "default")) {
		gcqctx->hw_cfg.cq_semp_wait_timeout_switch = CQ_DISABLE_TIMEOUT_SWITCH;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] timeout_func_enable import %s invalid",
			__func__, buf);
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

	value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_misccfg(CQ_CHANNEL0)));
	cq_set_u32_bit4(value, gcqctx->hw_cfg.cq_semp_wait_timeout_switch);
	hvgr_write_reg(gdev, cq_control_reg(gdev, cq_bind_misccfg(CQ_CHANNEL0)), value);

	value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_misccfg(CQ_CHANNEL1)));
	cq_set_u32_bit4(value, gcqctx->hw_cfg.cq_semp_wait_timeout_switch);
	hvgr_write_reg(gdev, cq_control_reg(gdev, cq_bind_misccfg(CQ_CHANNEL1)), value);

	hvgr_sch_resume(gdev);

	hvgr_pm_release_gpu(gdev);
	return (ssize_t)count;

out_fail:
	hvgr_pm_release_gpu(gdev);
	return -EINVAL;
}

static int hvgr_cq_sch_ubind_time_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	seq_printf(sfile, "%u\n", gcqctx->hw_cfg.cq_schedule_unbind_time);
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
	return (ssize_t)count;
out_fail:
	return -EINVAL;
}

static int hvgr_cq_serial_timeslice_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	uint32_t value;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	if (hvgr_pm_get_gpu_status(gdev) != HVGR_PM_GPU_READY)
		value = gdev->cq_dev.hw_cfg.cq_serial_timeslice;
	else
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_timeslice(CQ_CHANNEL0)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%u\n", value);
	return 0;
}

static int hvgr_cq_serial_timeslice_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_serial_timeslice_show, in->i_private);
}

static ssize_t hvgr_cq_serial_timeslice_write(struct file *file,
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
		gcqctx->hw_cfg.cq_serial_timeslice = CQ_TIMESLICE_VALUE;
	} else {
		if (kstrtoul(buf, 0, &num) != 0)
			goto out_fail;
		gcqctx->hw_cfg.cq_serial_timeslice = (uint32_t)num;
	}

	hvgr_cq_write_channel_data(gdev, cq_control_reg(gdev, cq_bind_timeslice(CQ_CHANNEL0)),
		cq_control_reg(gdev, cq_bind_timeslice(CQ_CHANNEL1)),
		gcqctx->hw_cfg.cq_serial_timeslice);

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
			cq_bind_affinity_sub_channel(CQ_CHANNEL0, COMPUTE_LOW_IDX)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%u\n", value);
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

	for (chn = 0; chn < CQ_CHANNEL_NUM; chn++)
		hvgr_cq_write_channel_data(gdev,
			cq_control_reg(gdev,
			cq_bind_affinity_sub_channel(CQ_CHANNEL0, COMPUTE_LOW_IDX)),
			cq_control_reg(gdev,
			cq_bind_affinity_sub_channel(CQ_CHANNEL0, COMPUTE_HIGH_IDX)),
			gcqctx->hw_cfg.cq_cl_affinity);

	return (ssize_t)count;

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

	seq_printf(sfile, "%u\n", value);
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
	return (ssize_t)count;

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
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_timeout(CQ_CHANNEL0)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%u\n", value);
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

	hvgr_cq_write_channel_data(gdev, cq_control_reg(gdev, cq_bind_timeout(CQ_CHANNEL0)),
		cq_control_reg(gdev, cq_bind_timeout(CQ_CHANNEL1)),
		gcqctx->hw_cfg.cq_queue_empty_timeout);
	return (ssize_t)count;

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
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_timeout_1(CQ_CHANNEL0)));
	mutex_unlock(&pm_pwr->power_lock);

	seq_printf(sfile, "%u\n", value);
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
		if (hvgr_is_fpga(gdev))
			gcqctx->hw_cfg.cq_queue_empty_timeout = CQ_EMPTY_TIMEOUT_IN_FPGA;
		else
			gcqctx->hw_cfg.cq_queue_empty_timeout = CQ_EMPTY_TIMEOUT_IN_CHIP;
	} else {
		unsigned long num = 0;

		if (kstrtoul(buf, 0, &num) != 0)
			goto out_fail;
		gcqctx->hw_cfg.cq_semp_wait_timeout = (uint32_t)num;
	}

	hvgr_cq_write_channel_data(gdev, cq_control_reg(gdev, cq_bind_timeout_1(CQ_CHANNEL0)),
		cq_control_reg(gdev, cq_bind_timeout_1(CQ_CHANNEL1)),
		gcqctx->hw_cfg.cq_semp_wait_timeout);
	return (ssize_t)count;

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
	for (i = RENDER_LOW_IDX; i <= RENDER_HIGH_IDX; i++) {
		value = hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_config(channel_id, i)));
		cq_set_u32_bit4(value, gcqctx->hw_cfg.cq_multi_chain_enable);
		hvgr_write_reg(gdev, cq_control_reg(gdev, cq_bind_config(channel_id, i)), value);
	}
out:
	mutex_unlock(&pm_pwr->power_lock);
	return;
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
			cq_bind_config(CQ_CHANNEL0, RENDER_LOW_IDX)));
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
	return (ssize_t)count;

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

	return (ssize_t)count;

out_fail:
	return -EINVAL;
}

static ssize_t hvgr_cq_status_ctx_set(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};
	unsigned long pid;

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		goto out_fail;

	if (kstrtoul(buf, 0, &pid) != 0)
		goto out_fail;
	gcqctx->collect_pid = (int)pid;
	hvgr_err(gdev, HVGR_CQ, "%s collect_pid=%d\n", __func__, gcqctx->collect_pid);
	return (ssize_t)count;

out_fail:
	return -EINVAL;
}

#define CQ_STATUS_INFO_MAX_LEN 8192

static void hvgr_cq_status_show_by_ctx(struct seq_file *sfile, void *data, struct hvgr_ctx *ctx)
{
	int idx;
	struct token_callback_data *callback = NULL;
	uint32_t dep_idx;
	char buffer[CQ_STATUS_INFO_MAX_LEN] = {0};
	int wrlen = 0;
	uint32_t dep_num_max;

	wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
		CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "ctx_id: %u, pid=%d, tgid=%d\n",
		ctx->id, ctx->pid, ctx->tgid);

	wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
		CQ_STATUS_INFO_MAX_LEN - wrlen - 1,
		"token   flag,  sempaddr, sempvalue, now_value, dep token.\n");

	for (idx = 0; idx < CQ_TOKEN_NUMS; idx++) {
		callback = ctx->ctx_cq.token_callback[idx];
		if (callback == NULL)
			continue;

		if (callback->set_flag == 0)
			continue;

		if (CQ_STATUS_INFO_MAX_LEN - wrlen < 200) {
			wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
				CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "no space left.");
			break;
		}

		wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
			CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "%08d ", idx);

		wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
			CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "%08u ", callback->flags);

		wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
			CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "0x%08x ",
			callback->cq_event.sem_addr);

		wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
			CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "0x%08x ",
			callback->cq_event.sem_value);

		if (callback->cq_event.sem_addr != 0)
			wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
				CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "0x%08x ",
				*(volatile uint64_t *)u64_to_ptr(callback->cq_event.sem_addr));
		else
			wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
				CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "0x%08x ", 0xdead);

		dep_num_max = (callback->dep_own_nums > HVGR_TOKEN_DEP_NUMS) ?
			HVGR_TOKEN_DEP_NUMS : callback->dep_own_nums;
		for (dep_idx = 0; dep_idx < dep_num_max; dep_idx++)
			wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
				CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "%u ",
				callback->dep_own_token[dep_idx]);

		wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
			CQ_STATUS_INFO_MAX_LEN - wrlen - 1, "\n");
	}

	seq_printf(sfile, "%s\n", buffer);
	return;
}

static int hvgr_cq_status_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx_tmp = NULL;

	mutex_lock(&gdev->dm_dev.ctx_list_mutex);
	list_for_each_entry_safe(ctx_tmp, tmp, &gdev->dm_dev.ctx_list, dev_link) {
		if (gcqctx->collect_pid == 0) {
			hvgr_cq_status_show_by_ctx(sfile, data, ctx_tmp);
			continue;
		}

		if ((ctx_tmp->tgid == gcqctx->collect_pid) ||
			(ctx_tmp->pid == gcqctx->collect_pid))
			hvgr_cq_status_show_by_ctx(sfile, data, ctx_tmp);
	}
	mutex_unlock(&gdev->dm_dev.ctx_list_mutex);
	return 0;
}

static int hvgr_cq_status_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_status_show, in->i_private);
}

static int hvgr_cq_fence_status_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_ctx *tmp = NULL;
	struct hvgr_ctx *ctx_tmp = NULL;
	char buffer[CQ_STATUS_INFO_MAX_LEN] = {0};
	int wrlen = 0;

	mutex_lock(&gdev->dm_dev.ctx_list_mutex);
	list_for_each_entry_safe(ctx_tmp, tmp, &gdev->dm_dev.ctx_list, dev_link) {
		wrlen += snprintf_s(&buffer[wrlen], CQ_STATUS_INFO_MAX_LEN - wrlen,
			CQ_STATUS_INFO_MAX_LEN - wrlen - 1,
			"ctx_id: %u, pid=%d, tgid=%d, tot_t_cnt=%d, tot_w_cnt=%d, "
			"com_t_cnt=%d, com_w_cnt=%d, unc_t_cnt:%d, unc_w_cnt:%d\n",
			ctx_tmp->id, ctx_tmp->pid, ctx_tmp->tgid,
			atomic_read(&ctx_tmp->ctx_cq.trigger_total_cnt),
			atomic_read(&ctx_tmp->ctx_cq.wait_total_cnt),
			atomic_read(&ctx_tmp->ctx_cq.trigger_complte_cnt),
			atomic_read(&ctx_tmp->ctx_cq.wait_complte_cnt),
			atomic_read(&ctx_tmp->ctx_cq.trigger_uncomplte_cnt),
			atomic_read(&ctx_tmp->ctx_cq.wait_uncomplte_cnt));
	}
	mutex_unlock(&gdev->dm_dev.ctx_list_mutex);

	seq_printf(sfile, "%s\n", buffer);
	return 0;
}

static int hvgr_cq_fence_status_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_fence_status_show, in->i_private);
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
		items = sscanf_s(buf, "%ld %ld", &gcqctx->reset_timeout_normal,
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
	return (ssize_t)count;
out_fail:
	return -EINVAL;
}

static int hvgr_cq_fence_timeout_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	seq_printf(sfile, "%s\n",gcqctx->fence_timeout_enable ? "enabled" : "disabled");

	return 0;
}

static int hvgr_cq_fence_timeout_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_fence_timeout_show, in->i_private);
}

static ssize_t hvgr_cq_fence_timeout_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		return -EINVAL;

	if (strstr(buf, "disable") || strstr(buf, "default")) {
		gcqctx->fence_timeout_enable = false;
	} else if (strstr(buf, "enable")) {
		gcqctx->fence_timeout_enable = true;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		return -EINVAL;
	}

	return (ssize_t)count;
}

static int hvgr_cq_semp_timeout_show(struct seq_file *sfile, void *data)
{
	struct hvgr_device *gdev = sfile->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;

	seq_printf(sfile, "%s\n",gcqctx->semp_timeout_enable ? "enabled" : "disabled");

	return 0;
}

static int hvgr_cq_semp_timeout_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cq_semp_timeout_show, in->i_private);
}

static ssize_t hvgr_cq_semp_timeout_write(struct file *file,
	const char __user *ubuf, size_t count, loff_t *ppos)
{
	struct seq_file *s = file->private_data;
	struct hvgr_device *gdev = s->private;
	struct hvgr_cq_dev *gcqctx = &gdev->cq_dev;
	char buf[CQ_DEBUG_BUFF_LEN] = {0};

	if (hvgr_cq_check_count_and_buf(gdev, buf, ubuf, count) != 0)
		return -EINVAL;

	if (strstr(buf, "disable") || strstr(buf, "default")) {
		gcqctx->semp_timeout_enable = false;
	} else if (strstr(buf, "enable")) {
		gcqctx->semp_timeout_enable = true;
	} else {
		hvgr_err(gdev, HVGR_CQ, "[%s] import %s invalid", __func__, buf);
		return -EINVAL;
	}

	return (ssize_t)count;
}

static const struct file_operations cq_work_mode_config = {
	.open = hvgr_cq_work_mode_open,
	.read = seq_read,
	.write = hvgr_cq_work_mode_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_sch_mode_config = {
	.open = hvgr_cq_sch_mode_open,
	.read = seq_read,
	.write = hvgr_cq_sch_mode_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_bc_send_mode_config = {
	.open = hvgr_cq_bc_send_mode_open,
	.read = seq_read,
	.write = hvgr_cq_bc_send_mode_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_timeout_func_enable_config = {
	.open = hvgr_cq_timeout_func_enable_open,
	.read = seq_read,
	.write = hvgr_cq_timeout_func_enable_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_sch_unbind_time_config = {
	.open = hvgr_cq_sch_ubind_time_open,
	.read = seq_read,
	.write = hvgr_cq_sch_ubind_time_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_serial_timeslice_config = {
	.open = hvgr_cq_serial_timeslice_open,
	.read = seq_read,
	.write = hvgr_cq_serial_timeslice_write,
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
	.write = hvgr_cq_status_ctx_set,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_fence_status = {
	.open = hvgr_cq_fence_status_open,
	.read = seq_read,
	.write = hvgr_cq_status_ctx_set,
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

static const struct file_operations cq_fence_timeout_config = {
	.open = hvgr_cq_fence_timeout_open,
	.read = seq_read,
	.write = hvgr_cq_fence_timeout_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static const struct file_operations cq_semp_timeout_config = {
	.open = hvgr_cq_semp_timeout_open,
	.read = seq_read,
	.write = hvgr_cq_semp_timeout_write,
	.llseek = seq_lseek,
	.release = single_release,
};

struct hvgr_cq_debugfs_files cq_debugs_files[] = {
	{"cq_work_mode", 0644, &cq_work_mode_config},
	{"cq_sch_mode", 0644, &cq_sch_mode_config},
	{"cq_bc_send_mode", 0644, &cq_bc_send_mode_config},
	{"cq_semp_wait_timeout_switch", 0644, &cq_timeout_func_enable_config},
	{"cq_cl_affinity", 0644, &cq_cl_affinity_config},
	{"cq_bind_waitcycle", 0644, &cq_bind_waitcycle_config},
	{"cq_queue_empty_timeout", 0644, &cq_queue_empty_timeout_config},
	{"cq_semp_wait_timeout", 0644, &cq_wait_semp_timeout_config},
	{"cq_multi_chain", 0644, &cq_multi_chain_config},
	{"cq_sch_unbind_time", 0644, &cq_sch_unbind_time_config},
	{"cq_serial_timeslice", 0644, &cq_serial_timeslice_config},
	{"cq_phychn_switch", 0644, &cq_phychn_config},
	{"cq_status", 0644, &cq_status_info},
	{"cq_unbind_timeout", 0644, &cq_unbind_timeout_config},
	{"cq_fence_timeout", 0644, &cq_fence_timeout_config},
	{"cq_semp_timeout", 0644, &cq_semp_timeout_config},
	{"cq_fence_status", 0644, &cq_fence_status},
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
