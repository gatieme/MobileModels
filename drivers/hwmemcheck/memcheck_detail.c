/*
 * memcheck_detail.c
 *
 * save and read detailed information from native or java process, send signal to them
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
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

#include "memcheck_detail.h"
#include "memcheck_ioctl.h"
#include <linux/vmalloc.h>
#include <linux/slab.h>
#include <linux/jiffies.h>
#include <linux/version.h>
#if (KERNEL_VERSION(4, 14, 0) <= LINUX_VERSION_CODE)
#include <linux/sched/signal.h>
#else
#include <linux/sched.h>
#endif

/* for native detail information save and read */
#define NATIVE_DETAIL_WAIT_TIME_SEC	5
static DEFINE_MUTEX(native_detail_mutex);
static void *native_detail_buf;
static u64 native_detail_len;
static wait_queue_head_t native_detail_ready;
static bool is_waiting;

int memcheck_detail_write(const void *buf, const struct detail_info *info)
{
	char *tmp = NULL;

	tmp = vzalloc(info->size + 1);
	if (!tmp)
		return -EFAULT;
	if (copy_from_user(tmp, buf + sizeof(*info), info->size)) {
		vfree(tmp);
		memcheck_err("copy_from_user failed\n");
		return -EFAULT;
	}
	tmp[info->size] = 0;

	mutex_lock(&native_detail_mutex);
	if (native_detail_buf)
		vfree(native_detail_buf);
	native_detail_buf = tmp;
	native_detail_len = info->size;
	mutex_unlock(&native_detail_mutex);

	if (is_waiting)
		wake_up_interruptible(&native_detail_ready);

	return 0;
}

static int memcheck_wait_native_detail_ready(void)
{
	int ret;

	mutex_lock(&native_detail_mutex);
	is_waiting = true;
	init_waitqueue_head(&native_detail_ready);
	mutex_unlock(&native_detail_mutex);
	ret = wait_event_interruptible_timeout(native_detail_ready,
					native_detail_buf,
					NATIVE_DETAIL_WAIT_TIME_SEC * HZ);
	mutex_lock(&native_detail_mutex);
	if (native_detail_buf && ret > 0) {
		memcheck_info("get native detail info successfully\n");
		ret = 0;
	} else if (!ret) {
		memcheck_err("wait for native detail info timeout\n");
		ret = -ETIMEDOUT;
	} else if (ret < 0) {
		memcheck_err("wait for native detail info return %d\n", ret);
		ret = -EFAULT;
	} else {
		memcheck_err("can not get native detail info return %d\n", ret);
		ret = -EFAULT;
	}
	is_waiting = false;
	mutex_unlock(&native_detail_mutex);

	return ret;
}

static int memcheck_send_native_signal(const struct detail_info *info)
{
	int ret = 0;
	struct task_struct *p = NULL;
#if (KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE)
	kernel_siginfo_t siginfo;

	clear_siginfo(&siginfo);
#else
	struct siginfo siginfo;

	memset(&siginfo, 0, sizeof(siginfo));
#endif

	siginfo.si_signo = SIGNO_MEMCHECK;
	siginfo.si_errno = 0;
	siginfo.si_code = SI_TKILL;
	siginfo.si_pid = task_tgid_vnr(current);
	siginfo.si_uid = from_kuid_munged(current_user_ns(), current_uid());

	rcu_read_lock();
	p = find_task_by_vpid(info->id);
	if (p)
		get_task_struct(p);
	rcu_read_unlock();

	if (p && (task_tgid_vnr(p) == info->id)) {
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		if (info->timestamp != nsec_to_clock_t(p->real_start_time)) {
#else
		if (info->timestamp != nsec_to_clock_t(p->start_boottime)) {
#endif
			memcheck_err("pid %d disappear\n", info->id);
			ret = MEMCHECK_PID_INVALID;
			goto err_pid_disappear;
		}

		siginfo.si_addr = (void *)ADDR_NATIVE_DETAIL_INFO;
		ret = do_send_sig_info(SIGNO_MEMCHECK, &siginfo, p, false);
		memcheck_info("send signal to pid %d, ret=%d\n", info->id, ret);
	}

err_pid_disappear:
	if (p)
		put_task_struct(p);
	if (!ret)
		ret = memcheck_wait_native_detail_ready();

	return ret;
}

int memcheck_detail_read(void *buf, struct detail_info *info)
{
	int ret = -EFAULT;
	size_t len;

	ret = memcheck_send_native_signal(info);
	if (ret) {
		memcheck_info("failed to send native singal\n");
		return ret;
	}

	mutex_lock(&native_detail_mutex);
	len = min(native_detail_len, info->size - sizeof(*info));
	if (len && copy_to_user(buf + sizeof(*info), native_detail_buf, len)) {
		memcheck_err("header copy_to_user failed\n");
		goto unlock;
	}

	if (len != info->size) {
		info->size = len;
		if (copy_to_user(buf, info, sizeof(*info))) {
			memcheck_err("message copy_to_user failed\n");
			goto unlock;
		}
	}
	memcheck_info("read native detail success, len=%lu\n", len);
	vfree(native_detail_buf);
	native_detail_buf = NULL;
	native_detail_len = 0;
	ret = 0;
unlock:
	mutex_unlock(&native_detail_mutex);

	return ret;
}
