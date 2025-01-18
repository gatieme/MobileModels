/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: gear ctrl implement
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

#include <securec.h>
#include <linux/bio.h>
#include <linux/blk-mq.h>
#include <linux/blkdev.h>
#include <linux/delay.h>
#include <linux/gfp.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <scsi/scsi.h>
#include <scsi/scsi_device.h>
#include <scsi/scsi_host.h>

#include <platform_include/basicplatform/linux/hck/blk/hck_mas_ufs_gear_ctrl.h>
#include "blk.h"
#include "mas_blk_gear_ctrl.h"

struct gear_ctrl_work {
	struct work_struct gear_ctrl_work;
	struct request_queue *q;
	spinlock_t set_lock;
	u32 set_gear;
	struct mutex proc_lock;
	ktime_t last_highest_gear_set_time;
};

u32 g_mas_min_gear_level = MAS_GEAR_INVALID_MAIGC_NUM;
u32 g_mas_max_gear_level = MAS_GEAR_INVALID_MAIGC_NUM;
struct workqueue_struct *mas_proc_gear_ctrl_workqueue = NULL;
struct gear_ctrl_work g_mas_gear_ctrl;

bool g_mas_gear_auto_flag = true;
bool g_mas_gear_ctrl_device_abandon = false;
u32 g_mas_min_highest_gear_stay_time = 100;
u32 g_mas_ufs_rate = 70;
u32 g_mas_fg_num = 6;
u32 g_mas_sync_num = 6;

static void mas_gear_ctrl_work(struct work_struct *work)
{
	struct gear_ctrl_work *ctrl_work = container_of(work, struct gear_ctrl_work, gear_ctrl_work);
	struct request_queue *q = ctrl_work->q;
	struct blk_dev_lld *lld;
	struct scsi_device *sdev;
	struct Scsi_Host *shost;
	unsigned long flags;
	u32 proc_gear;
	int ret;

	if (unlikely(!q))
		return;

	lld = mas_blk_get_lld(q);
	sdev = q->queuedata;
	shost = sdev->host;
	if (unlikely(!lld || !lld->gear_ctrl_ops || !lld->gear_ctrl_ops->gear_ctrl))
		return;

	if (lld->gear_ctrl_ops->switch_latency_check)
		lld->gear_ctrl_ops->switch_latency_check(q, UFS_DSS_LATENCY_SCENARIO_ISSUE, 0, 0);
	mutex_lock(&ctrl_work->proc_lock);

	spin_lock_irqsave(&ctrl_work->set_lock, flags);
	proc_gear = ctrl_work->set_gear;
	spin_unlock_irqrestore(&ctrl_work->set_lock, flags);

	ret = lld->gear_ctrl_ops->gear_ctrl(q, proc_gear);
	if (ret)
		pr_debug("%s, gear switch failed %d\n", __func__, ret);

	spin_lock_irqsave(&ctrl_work->set_lock, flags);
	if (proc_gear == g_mas_max_gear_level)
		ctrl_work->last_highest_gear_set_time = ktime_get();
	spin_unlock_irqrestore(&ctrl_work->set_lock, flags);

	mutex_unlock(&ctrl_work->proc_lock);
	if (lld->gear_ctrl_ops->switch_latency_check)
		lld->gear_ctrl_ops->switch_latency_check(q, UFS_DSS_LATENCY_SCENARIO_FINISH, 0, 0);
}

void mas_gear_ctrl_init(struct request_queue *q)
{
	if (mas_proc_gear_ctrl_workqueue)
		return;

	g_mas_gear_ctrl.set_gear = 0;
	g_mas_gear_ctrl.last_highest_gear_set_time = 0;
	spin_lock_init(&g_mas_gear_ctrl.set_lock);
	mutex_init(&g_mas_gear_ctrl.proc_lock);

	INIT_WORK(&g_mas_gear_ctrl.gear_ctrl_work, mas_gear_ctrl_work);

	mas_proc_gear_ctrl_workqueue = alloc_workqueue("proc_gear_ctrl", WQ_HIGHPRI | WQ_UNBOUND, 0);
	if (g_mas_gear_auto_flag)
		mas_gear_ctrl_flow_init();

	return;
}

void mas_queue_gear_ctrl_change(struct request_queue *q, u32 set_gear, int cond)
{
	int ret;
	struct blk_dev_lld *lld = mas_blk_get_lld(q);
	unsigned long flags;
	u32 last_set;
	u32 cur_gear;

	if (unlikely(!lld || !lld->gear_ctrl_ops || !mas_proc_gear_ctrl_workqueue))
		return;

	if (unlikely(!lld->gear_ctrl_ops->gear_level_get))
		return;

	ret = lld->gear_ctrl_ops->gear_level_get(q, &cur_gear);
	if (unlikely(ret))
		return;

	spin_lock_irqsave(&g_mas_gear_ctrl.set_lock, flags);
	if (set_gear == g_mas_max_gear_level)
		g_mas_gear_ctrl.last_highest_gear_set_time = ktime_get();
	last_set = g_mas_gear_ctrl.set_gear;
	g_mas_gear_ctrl.set_gear = set_gear;
	g_mas_gear_ctrl.q = q;
	spin_unlock_irqrestore(&g_mas_gear_ctrl.set_lock, flags);
	if (cur_gear != set_gear) {
		if (!work_busy(&g_mas_gear_ctrl.gear_ctrl_work) ||
		    (last_set == g_mas_min_gear_level && set_gear == g_mas_max_gear_level)) {
			if (lld->gear_ctrl_ops->switch_latency_check)
				lld->gear_ctrl_ops->switch_latency_check(q, UFS_DSS_LATENCY_SCENARIO_REQUEST, set_gear,
									 cond);
			queue_work(mas_proc_gear_ctrl_workqueue, &g_mas_gear_ctrl.gear_ctrl_work);
		}
	}
}

void mas_blk_mq_tagset_gear_ctrl_register(struct blk_mq_tag_set *tag_set, struct lld_gear_ctrl_ops *ops)
{
	if (tag_set)
		tag_set->lld_func.gear_ctrl_ops = ops;
}

void mas_blk_auto_gear_ctrl(bool enable)
{
	if (enable == false && g_mas_gear_auto_flag == true)
		mas_gear_ctrl_flow_destory();
	else if (enable == true && g_mas_gear_auto_flag == false)
		mas_gear_ctrl_flow_init();
	g_mas_gear_auto_flag = enable;
}

void mas_blk_disable_gear_ctrl(bool enable)
{
	mas_blk_auto_gear_ctrl(!enable);
	g_mas_gear_ctrl_device_abandon = enable;
}

bool mas_blk_check_gear_ctrl_abandon_on_device(void)
{
	return g_mas_gear_ctrl_device_abandon;
}

static bool mas_blk_check_lrb_over_threshold(struct request_queue *q)
{
	int ret;
	unsigned long lrb_in_use = 0;
	struct blk_dev_lld *lld = mas_blk_get_lld(q);

	if (unlikely(!lld || !lld->gear_ctrl_ops || !lld->gear_ctrl_ops->read_gear_use_rate))
		return true;

	ret = lld->gear_ctrl_ops->read_gear_use_rate(q, &lrb_in_use);
	if (unlikely(ret))
		return true;

	if (lrb_in_use >= g_mas_ufs_rate)
		return true;
	else
		return false;
}

static bool mas_blk_check_io_over_threshold(struct request_queue *q,
					    unsigned long mas_fg_num,
					    unsigned long mas_sync_num)
{
	unsigned long fg_io, vip_io, sync_io;
	int ret;

	ret = mas_blk_get_fg_vip_sync_io_num(q, &fg_io, &vip_io, &sync_io);
	return ((fg_io + vip_io) >= mas_fg_num || sync_io >= mas_sync_num);
}

static inline void mas_queue_busy_change_gear_flow_update(struct request *req)
{
	if (req && !blk_rq_is_passthrough(req) && (req->cmd_flags & REQ_SYNC))
		mas_gear_ctrl_flow_add(req);
	else
		mas_gear_ctrl_flow_add(NULL);
}

static bool mas_queue_busy_change_gear_in_stay_time(u32 cur_gear)
{
	ktime_t now;
	unsigned long flags;
	bool ret = false;

	spin_lock_irqsave(&g_mas_gear_ctrl.set_lock, flags);
	if (g_mas_gear_ctrl.set_gear == g_mas_max_gear_level) {
		now = ktime_get();
		if (ktime_ms_delta(now, g_mas_gear_ctrl.last_highest_gear_set_time) <= g_mas_min_highest_gear_stay_time) {
			g_mas_gear_ctrl.last_highest_gear_set_time = now;
			ret = cur_gear == g_mas_max_gear_level;
		}
	}
	spin_unlock_irqrestore(&g_mas_gear_ctrl.set_lock, flags);
	return ret;
}


static int mas_queue_get_dss_gear_level(struct request_queue *q)
{
	int ret = GEAR_CTRL_REASON_MAX - 1;
	int flow_cnt;
	int flow_size;
	int spend_us;
	int inflat_size;

	mas_gear_ctrl_flow_get(&flow_cnt, &flow_size, &spend_us, &inflat_size);
	if (inflat_size >= g_mas_gear_ctrl_inflat_threshold_size || !--ret)
		goto out;
	if ((spend_us && (flow_cnt * 1000 / spend_us >= g_mas_gear_ctrl_flow_threshold_cnt_per_ms)) || !--ret)
		goto out;
	if ((spend_us && (flow_size * 100 / spend_us >= g_mas_gear_ctrl_flow_threshold_size_per_100us)) || !--ret)
		goto out;
	if (mas_blk_check_io_over_threshold(q, g_mas_fg_num, g_mas_sync_num) || !--ret)
		goto out;
	if (mas_blk_check_lrb_over_threshold(q) || !--ret)
		goto out;
out:
	return ret;
}

void mas_queue_busy_change_gear(struct request_queue *q, struct request *req)
{
	struct blk_dev_lld *lld;
	int cond;
	u32 cur_gear;
	int ret;

	if (!q || !req || !mas_proc_gear_ctrl_workqueue || !g_mas_gear_auto_flag)
		return;

	lld = mas_blk_get_lld(q);
	if (unlikely(!lld || !lld->gear_ctrl_ops))
		return;
	if (unlikely(g_mas_min_gear_level == MAS_GEAR_INVALID_MAIGC_NUM)) {
		if (!lld->gear_ctrl_ops->gear_level_cap_get)
			return;

		if (lld->gear_ctrl_ops->gear_level_cap_get(q, &g_mas_min_gear_level, &g_mas_max_gear_level))
			return;
	}

	mas_queue_busy_change_gear_flow_update(req);

	if (unlikely(!lld->gear_ctrl_ops->gear_level_get))
		return;
	ret = lld->gear_ctrl_ops->gear_level_get(q, &cur_gear);
	if (unlikely(ret))
		return;
	if (mas_queue_busy_change_gear_in_stay_time(cur_gear))
		return;

	cond = mas_queue_get_dss_gear_level(q);
	mas_queue_gear_ctrl_change(q, cond ? g_mas_max_gear_level : g_mas_min_gear_level, cond);
}

void mas_queue_ioback_change_gear(struct request_queue *q, struct request *req)
{
	if (mas_proc_gear_ctrl_workqueue && g_mas_gear_auto_flag && req &&
	    !blk_rq_is_passthrough(req) && (req->cmd_flags & REQ_SYNC))
		return mas_gear_ctrl_flow_delete_wait(req);
}

void mas_blk_gear_ctrl_reinit(void)
{
	mas_gear_ctrl_flow_drop();
}

static void hck_mas_blk_gear_ctrl_reinit(void *data)
{
	return mas_blk_gear_ctrl_reinit();
}

static struct request_queue *g_last_request_queue = NULL;

static void hck_mas_queue_busy_change_gear(struct request_queue *q, struct request *req)
{
	if (unlikely(!ufs_dss_check_request_queue_ok(q)))
		return;

	if (unlikely(!g_last_request_queue))
		g_last_request_queue = q;
	mas_queue_busy_change_gear(q, req);
}

static void hck_mas_queue_ioback_change_gear(struct request_queue *q, struct request *req)
{
	if (unlikely(!ufs_dss_check_request_queue_ok(q)))
		return;

	mas_queue_ioback_change_gear(q, req);
}

static void hck_mas_blk_fill_gear_info(char *info, int len)
{
	struct request_queue *q = g_last_request_queue;
	u32 cur_gear;
	bool in_change = false;
	struct lld_gear_ctrl_ops *gear_ops = NULL;
	int ret;

	gear_ops = ufs_dss_get_ops(q);
	if (unlikely(!gear_ops || !gear_ops->gear_level_get))
		goto unrecognize;

	if (g_mas_gear_ctrl_device_abandon)
		goto fdisable;

	ret = gear_ops->gear_level_get(q, &cur_gear);
	if (unlikely(ret))
		goto unrecognize;

	if (cur_gear == g_mas_min_gear_level)
		goto min_level;
	in_change = !!(work_busy(&g_mas_gear_ctrl.gear_ctrl_work) & WORK_BUSY_RUNNING);
	ret = snprintf_s(info, (size_t)len, (size_t)(len - 1), "%s", in_change ? "to low" : "at high");
	goto out;

min_level:
	ret = snprintf_s(info, (size_t)len, (size_t)(len - 1), "%s", in_change ? "to high" : "at low");
	goto out;
unrecognize:
	ret = snprintf_s(info, (size_t)len, (size_t)(len - 1), "unkown level");
	goto out;
fdisable:
	ret = snprintf_s(info, (size_t)len, (size_t)(len - 1), "disable");
out:
	if (ret < 0)
		info[0] = '\0';
	else
		info[ret] = '\0';
	return;
}

static int __init mas_gear_ctrl_hck_init(void)
{
	static bool registered = false;

	if (!registered) {
		REGISTER_HCK_VH(mas_queue_busy_change_gear, hck_mas_queue_busy_change_gear);
		REGISTER_HCK_VH(mas_queue_ioback_change_gear, hck_mas_queue_ioback_change_gear);
		REGISTER_HCK_VH(mas_blk_gear_ctrl_reinit, hck_mas_blk_gear_ctrl_reinit);
		REGISTER_HCK_VH(mas_blk_fill_gear_info, hck_mas_blk_fill_gear_info);
		registered = true;
	}

	return 0;
}
__initcall(mas_gear_ctrl_hck_init);

bool ufs_dss_check_request_queue_ok(struct request_queue *q)
{
	struct scsi_device *sdev = NULL;
	struct Scsi_Host *shost = NULL;

	if (likely(q))
		sdev = q->queuedata;
	else
		return false;

	if (likely(sdev))
		shost = sdev->host;
	else
		return false;

	if (unlikely(!shost || sdev->type != TYPE_DISK || !(shost->queue_quirk_flag & SHOST_QUIRK(SHOST_QUIRK_HUFS_MQ))))
		return false;

	return true;
}

struct lld_gear_ctrl_ops *ufs_dss_get_ops(struct request_queue *q)
{
	struct blk_dev_lld *lld = NULL;

	if (!ufs_dss_check_request_queue_ok(q) || !mas_proc_gear_ctrl_workqueue)
		return NULL;
	lld = mas_blk_get_lld(q);
	if (unlikely(!lld || !lld->gear_ctrl_ops))
		return NULL;
	if (unlikely(!lld->gear_ctrl_ops->gear_ctrl ||
				!lld->gear_ctrl_ops->read_gear_use_rate ||
				!lld->gear_ctrl_ops->gear_level_get ||
				!lld->gear_ctrl_ops->gear_level_cap_get ||
				!lld->gear_ctrl_ops->switch_latency_check))
		return NULL;
	return lld->gear_ctrl_ops;
}
