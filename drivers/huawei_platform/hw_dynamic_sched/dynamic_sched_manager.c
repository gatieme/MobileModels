/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "../kernel/sched/sched.h"

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mutex.h>
#include <linux/miscdevice.h>
#include <linux/time.h>
#include <linux/init.h>
#include <uapi/linux/sched/types.h>
#include <linux/workqueue.h>
#include <linux/types.h>

#define IOCTL_MAGIC 'K'
#define IOCTL_SET_MSG _IOW(IOCTL_MAGIC, 1, unsigned int)

#define MONITOR_WORK_DELAY 20

static DEFINE_MUTEX(dynamic_sched_mutex);

static int g_working_locked = 0;

/*
 * Define a delayed work for monitoring
 * the operational state of the task.
 */
struct dynamic_sched_delayed_work_s {
	struct delayed_work d_work;
	pid_t producer_pid;
	pid_t valid_waker_pid;
} *g_dynamic_sched_delayed_work;

static int dynamic_sched_manager_open(struct inode *inode, struct file *file)
{
	pr_info("%s: /dev/hw_dynamic_sched opened\n", __func__);
	return 0;
}

static int dynamic_sched_manager_release(struct inode *inode, struct file *file)
{
	pr_info("%s: /dev/hw_dynamic_sched released\n", __func__);
	return 0;
}

static void update_waker_pid(struct task_struct *producer_task)
{
	if (producer_task->sched_waker == NULL)
		return;

	if (likely(producer_task->tgid != producer_task->sched_waker->tgid))
		return;

	g_dynamic_sched_delayed_work->valid_waker_pid = producer_task->sched_waker->pid;
}

static bool is_need_boost_waker_prio(struct task_struct* producer_task, struct task_struct* waker_task)
{
	if (likely(producer_task->on_rq))
		return false;
	
	if (producer_task->tgid != waker_task->tgid)
		return false;

	if (g_dynamic_sched_delayed_work->valid_waker_pid == 0)
		return false;

	return true;
}

static int set_dynamic_task_prio(pid_t producer_pid)
{
	struct task_struct *producer_task = find_get_task_by_vpid(producer_pid);
	if (producer_task != NULL) {
#ifdef CONFIG_SCHED_VIP_PI
 		request_vip_boost(producer_task, 1, VIP_BOOST_HW_DYNAMIC_SCHED);
#endif

		g_dynamic_sched_delayed_work->producer_pid = producer_pid;
		update_waker_pid(producer_task);

		struct task_struct *waker_task = find_get_task_by_vpid(g_dynamic_sched_delayed_work->valid_waker_pid);
		if (waker_task != NULL) {
			if (is_need_boost_waker_prio(producer_task, waker_task)) {
#ifdef CONFIG_SCHED_VIP_PI
				request_vip_boost(waker_task, 1, VIP_BOOST_HW_DYNAMIC_SCHED);
#endif
			}
			put_task_struct(waker_task);
		}

		put_task_struct(producer_task);
		queue_delayed_work(system_power_efficient_wq, &g_dynamic_sched_delayed_work->d_work, msecs_to_jiffies(MONITOR_WORK_DELAY));

		return 0;
	}

	return -1;
}

static void clear_boosted_prio(pid_t pid)
{
	struct task_struct *task = find_get_task_by_vpid(pid);
	if (task != NULL) {
#ifdef CONFIG_SCHED_VIP_PI
 		clear_vip_boost(task, VIP_BOOST_HW_DYNAMIC_SCHED);
#endif
		put_task_struct(task);
	}
}

static void task_monitor_work_hdl(struct work_struct *work)
{
	clear_boosted_prio(g_dynamic_sched_delayed_work->producer_pid);
	clear_boosted_prio(g_dynamic_sched_delayed_work->valid_waker_pid);

	mutex_lock(&dynamic_sched_mutex);
	g_working_locked = 0;
	mutex_unlock(&dynamic_sched_mutex);
}

static long dynamic_sched_manager_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int err = 0;
	pid_t pid = 0;

	mutex_lock(&dynamic_sched_mutex);
	if (g_working_locked) {
		mutex_unlock(&dynamic_sched_mutex);
		return -EBUSY;
	}

	g_working_locked = 1;
	mutex_unlock(&dynamic_sched_mutex);

	switch (cmd) {
		case IOCTL_SET_MSG:
			err = copy_from_user(&pid,
				(unsigned int __user *)arg, sizeof(unsigned int));
			if (err) {
				pr_err("%s: failed to copy message from user\n", __func__);
				err = -EFAULT;
				goto reset_working_lock;
			}

			err = set_dynamic_task_prio(pid);
			if (err) {
				err = -EFAULT;
				goto reset_working_lock;
			}
			break;
		default:
			err = -ENOTTY;  // Unknown command
			goto reset_working_lock;
	}

	return err;

reset_working_lock:
	mutex_lock(&dynamic_sched_mutex);
	g_working_locked = 0;
	mutex_unlock(&dynamic_sched_mutex);
	return err;
}

static struct file_operations dynamic_sched_manager_fops = {
	.owner = THIS_MODULE,
	.open = dynamic_sched_manager_open,
	.release = dynamic_sched_manager_release,
	.unlocked_ioctl = dynamic_sched_manager_ioctl,
};

static struct miscdevice g_hw_dynamic_sched_md = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "hw_dynamic_sched",
    .fops = &dynamic_sched_manager_fops,
};

static int __init dynamic_sched_manager_init(void)
{
    int ret = 0;
    bool is_enabled = false;

    struct device_node *dn = of_find_node_by_name(NULL, "huawei_dynamic_sched_manager");
    if (!dn)
        return -1;

    is_enabled = of_property_read_bool(dn, "enabled");
    if (!is_enabled)
        return -1;

    ret = misc_register(&g_hw_dynamic_sched_md);
    if (ret != 0)
        return ret;

    g_dynamic_sched_delayed_work = kmalloc(sizeof(struct dynamic_sched_delayed_work_s), GFP_KERNEL);
    if (!g_dynamic_sched_delayed_work) {
		misc_deregister(&g_hw_dynamic_sched_md);
		return -ENOMEM;
	}

	INIT_DELAYED_WORK(&g_dynamic_sched_delayed_work->d_work, task_monitor_work_hdl);
	g_dynamic_sched_delayed_work->producer_pid = 0;
	g_dynamic_sched_delayed_work->valid_waker_pid = 0;
	mutex_init(&dynamic_sched_mutex);

    return 0;
}

module_init(dynamic_sched_manager_init);
MODULE_LICENSE("GPL");
