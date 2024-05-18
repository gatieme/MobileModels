/*
 * hwlog_kernel.c
 *
 * drivers to write messages to logger nodes
 *
 * Copyright (c) Honor Device Co., Ltd. 2017-2019. All rights reserved.
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

#include <log/hwlog_kernel.h>

#include <linux/fs.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/uio.h>
#include <linux/version.h>

#include <log/hw_log.h>
#include <log/hw_logger.h>

#define MAX_WORK_COUNT		20
#define MAX_TAG_SIZE		64
#define MAX_MSG_SIZE		256
#define HWLOG_TAG		hwlog_kernel

HILOG_REGIST();
#ifdef CONFIG_LOGGER_LEGACY
static struct file *filp[HW_LOG_ID_MAX] = { NULL, NULL, NULL };

static const char *log_name[HW_LOG_ID_MAX] = {
	[HW_LOG_ID_EXCEPTION]	= LOG_EXCEPTION_FS,
	[HW_LOG_ID_JANK]	    = LOG_JANK_FS,
	[HW_LOG_ID_DUBAI]	    = LOG_DUBAI_FS,
};
#else
static const char *dev_name[HW_LOG_ID_MAX] = {
	[HW_LOG_ID_EXCEPTION]	= LOGGER_LOG_EXCEPTION,
	[HW_LOG_ID_JANK]	    = LOGGER_LOG_JANK,
	[HW_LOG_ID_DUBAI]	    = LOGGER_LOG_DUBAI,
};
#endif

static int CHECK_CODE = LOGGER_CHECK_MAGIC;

struct hwlog_work {
	int waiting;
	u16 bufid;
	u16 prio;
	int taglen;
	u16 janktagid;
	u64 uptime;
	u64 realtime;
	char tagid[MAX_MSG_SIZE];
	int msglen;
	char msg[MAX_MSG_SIZE];
	struct work_struct writelog;
};

static bool hwlog_wq_inited;
static int work_index;
struct hwlog_work hwlog_work[MAX_WORK_COUNT];
struct workqueue_struct *hwlog_wq;

static int __write_hwlog_to_kernel_init(struct hwlog_work *phwlog);
static int __write_to_kernel_kernel(struct hwlog_work *phwlog);
static int (*write_hwlog_to_kernel)(struct hwlog_work *phwlog) =
					__write_hwlog_to_kernel_init;
static DEFINE_MUTEX(hwlogfile_mutex);
static DEFINE_RAW_SPINLOCK(hwlog_spinlock);

void hwlog_write(struct work_struct *p_work)
{
	struct hwlog_work *work = container_of(p_work, struct hwlog_work, writelog);

	write_hwlog_to_kernel(work);
	work->waiting = 0;
}

int hwlog_wq_init(void)
{
	unsigned int i;

	if (hwlog_wq_inited) {
		hilog_err("create hwlog_wq again\n");
		return 1;
	}
	hwlog_wq = create_singlethread_workqueue("hwlog_wq");
	if (!hwlog_wq) {
		hilog_err("failed to create hwlog_wq\n");
		return 1;
	}
	hilog_info("hw_log: created hwlog_wq\n");

	for (i = 0; i < MAX_WORK_COUNT; i++) {
		INIT_WORK(&(hwlog_work[i].writelog), hwlog_write);
		hwlog_work[i].waiting = 0;
	}
	hwlog_wq_inited = true;
	work_index = 0;

	return 0;
}

void hwlog_wq_destroy(void)
{
	if (hwlog_wq) {
		destroy_workqueue(hwlog_wq);
		hwlog_wq = NULL;
	}
#ifdef CONFIG_LOGGER_LEGACY

	for (int i = 0; i < HW_LOG_ID_MAX; i++) {
		if (!IS_ERR(filp[i])) {
			filp_close(filp[i], NULL);
			filp[i] = NULL;
		}
	}
#endif
	hwlog_wq_inited = false;
}

#ifdef CONFIG_LOGGER_LEGACY
static int __write_hwlog_to_kernel_init(struct hwlog_work *phwlog)
{
	unsigned int i;
	int err_count = 0;
	mm_segment_t oldfs;

	if (phwlog->bufid >= HW_LOG_ID_MAX)
		return 0;

	mutex_lock(&hwlogfile_mutex);
	if (__write_hwlog_to_kernel_init == write_hwlog_to_kernel) {
		oldfs = get_fs();
		set_fs(KERNEL_DS);
		for (i = 0; i < HW_LOG_ID_MAX; i++) {
			filp[i] = filp_open(log_name[i], O_WRONLY, 0);
			if (IS_ERR(filp[i]))
				err_count++;
		}
		set_fs(oldfs);
		if (err_count == HW_LOG_ID_MAX) {
			hilog_err("failed to open\n");
			mutex_unlock(&hwlogfile_mutex);
			return 0;
		}
		write_hwlog_to_kernel = __write_to_kernel_kernel;
	}
	mutex_unlock(&hwlogfile_mutex);
	return write_hwlog_to_kernel(phwlog);
}

static int __write_to_kernel_kernel(struct hwlog_work *phwlog)
{
	struct iovec vec[6];
	unsigned long vcount = 0;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
	struct iov_iter iter;
#else
	mm_segment_t oldfs;
#endif
	int ret;

	if (phwlog->bufid >= HW_LOG_ID_MAX)
		return 0;

	if (unlikely(!phwlog)) {
		hilog_err("invalid arguments\n");
		return -1;
	}

	if (IS_ERR(filp[phwlog->bufid])) {
		hilog_err("file descriptor to %s is invalid: %ld\n",
			log_name[phwlog->bufid], PTR_ERR(filp[phwlog->bufid]));
		return -1;
	}

	vec[vcount].iov_base = &CHECK_CODE;
	vec[vcount++].iov_len = sizeof(CHECK_CODE);

	if (phwlog->bufid == HW_LOG_ID_JANK) {
		vec[vcount].iov_base  = &phwlog->prio;
		vec[vcount++].iov_len = 2;
		vec[vcount].iov_base  = &phwlog->janktagid;
		vec[vcount++].iov_len = 2;
		vec[vcount].iov_base  = &phwlog->uptime;
		vec[vcount++].iov_len = sizeof(phwlog->uptime);
		vec[vcount].iov_base  = &phwlog->realtime;
		vec[vcount++].iov_len = sizeof(phwlog->realtime);
		vec[vcount].iov_base  = phwlog->msg;
		vec[vcount++].iov_len = phwlog->msglen;
	} else {
		vec[vcount].iov_base  = &phwlog->prio;
		vec[vcount++].iov_len = 1;
		vec[vcount].iov_base  = phwlog->tagid;
		vec[vcount++].iov_len = phwlog->taglen;
		vec[vcount].iov_base  = phwlog->msg;
		vec[vcount++].iov_len = phwlog->msglen;
	}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
	iov_iter_init(&iter, WRITE, vec, vcount, iov_length(vec, vcount));
	ret = vfs_iter_write(filp[phwlog->bufid], &iter,
				&filp[phwlog->bufid]->f_pos, 0);
#else
	oldfs = get_fs();
	set_fs(KERNEL_DS);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 9, 0))
	ret = vfs_writev(filp[phwlog->bufid], vec, vcount,
			 &(filp[phwlog->bufid])->f_pos, 0);
#else
	ret = vfs_writev(filp[phwlog->bufid], vec, vcount,
			 &(filp[phwlog->bufid])->f_pos);
#endif
	set_fs(oldfs);
#endif

	if (unlikely(ret < 0))
		hilog_err("failed to write %s\n", log_name[phwlog->bufid]);

	return ret;
}
#else
static int __write_hwlog_to_kernel_init(struct hwlog_work *phwlog)
{
	if (phwlog->bufid >= HW_LOG_ID_MAX)
		return 0;

	mutex_lock(&hwlogfile_mutex);
	if (__write_hwlog_to_kernel_init == write_hwlog_to_kernel) {
		write_hwlog_to_kernel = __write_to_kernel_kernel;
	}
	mutex_unlock(&hwlogfile_mutex);
	return write_hwlog_to_kernel(phwlog);
}

static int __write_to_kernel_kernel(struct hwlog_work *phwlog)
{
	int ret;
	struct iovec vec[6];
	unsigned long vcount = 0;

	if (unlikely(!phwlog || phwlog->bufid >= HW_LOG_ID_MAX)) {
		hilog_err("invalid arguments\n");
		return -1;
	}

	vec[vcount].iov_base = &CHECK_CODE;
	vec[vcount++].iov_len = sizeof(CHECK_CODE);

	if (phwlog->bufid == HW_LOG_ID_JANK) {
		vec[vcount].iov_base  = &phwlog->prio;
		vec[vcount++].iov_len = 2;
		vec[vcount].iov_base  = &phwlog->janktagid;
		vec[vcount++].iov_len = 2;
		vec[vcount].iov_base  = &phwlog->uptime;
		vec[vcount++].iov_len = sizeof(phwlog->uptime);
		vec[vcount].iov_base  = &phwlog->realtime;
		vec[vcount++].iov_len = sizeof(phwlog->realtime);
		vec[vcount].iov_base  = phwlog->msg;
		vec[vcount++].iov_len = phwlog->msglen;
	} else {
		vec[vcount].iov_base  = &phwlog->prio;
		vec[vcount++].iov_len = 1;
		vec[vcount].iov_base  = phwlog->tagid;
		vec[vcount++].iov_len = phwlog->taglen;
		vec[vcount].iov_base  = phwlog->msg;
		vec[vcount++].iov_len = phwlog->msglen;
	}

	ret = send_hievent_vector(dev_name[phwlog->bufid], vec, vcount);

	if (unlikely(ret < 0))
		hilog_err("failed to write %s\n", dev_name[phwlog->bufid]);

	return ret;
}
#endif

static struct hwlog_work *get_hwlog_work(void)
{
	struct hwlog_work *work = NULL;
	unsigned long flags;

	if (!hwlog_wq_inited) {
		hilog_err("hwlog_wq is not initialized.\n");
		return NULL;
	}

	raw_spin_lock_irqsave(&hwlog_spinlock, flags);
	work = &hwlog_work[work_index];
	if (!work->waiting) {
		work->waiting = 1;
		work_index++;
		if (work_index >= MAX_WORK_COUNT)
			work_index = 0;
	} else {
		work = NULL;
	}
	raw_spin_unlock_irqrestore(&hwlog_spinlock, flags);

	return work;
}

int hievent_to_write(int prio, int bufid, const char *tag, const char *fmt, ...)
{
	struct hwlog_work *work = get_hwlog_work();
	va_list args;
	int len;

	if (strlen(tag) >= MAX_MSG_SIZE)
		return 0;

	if (!work) {
		hilog_err("hwlog_wq is full, failed.\n");
		return -1;
	}
	work->bufid = bufid;
	work->prio = prio;
	memcpy(work->tagid, tag, strlen(tag) + 1);
	work->taglen = strlen(tag) + 1;
	va_start(args, fmt);
	len = vscnprintf(work->msg, MAX_MSG_SIZE, fmt, args);
	va_end(args);
	work->msglen = len + 1;

	queue_work(hwlog_wq, &(work->writelog));

	return 0;
}
EXPORT_SYMBOL(hievent_to_write);

int hievent_to_jank(int tag, int prio, const char *fmt, ...)
{
	struct hwlog_work *work = get_hwlog_work();
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
	struct timespec64 upts, realts;
#else
	struct timespec upts, realts;
#endif
	va_list args;
	int len;

	if (!work) {
		hilog_err("hwlog_wq is full, logd_to_jank failed.\n");
		return -1;
	}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
	ktime_get_ts64(&upts);
	realts = upts;
	ktime_get_boottime_ts64(&realts);
#else
	ktime_get_ts(&upts);
	realts = upts;
	get_monotonic_boottime(&realts);
#endif

	work->bufid = HW_LOG_ID_JANK;
	work->prio = prio;
	work->janktagid = tag;
	work->uptime = (u64)upts.tv_sec * 1000 + upts.tv_nsec / 1000000;
	work->realtime = (u64)realts.tv_sec * 1000 + realts.tv_nsec / 1000000;

	va_start(args, fmt);
	len = vscnprintf(work->msg, MAX_MSG_SIZE, fmt, args);
	va_end(args);
	work->msglen = len + 1;
	queue_work(hwlog_wq, &(work->writelog));

	return 0;
}
EXPORT_SYMBOL(hievent_to_jank);
