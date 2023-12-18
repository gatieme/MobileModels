/*
 * walt_hw.h
 *
 * common platform WALT header file
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd
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
#ifndef __HW_WALT_H__
#define __HW_WALT_H__

#include <linux/version.h>

#ifdef CONFIG_HW_SCHED_WALT
#include <linux/kobject.h>
#endif

#if defined(CONFIG_HW_RTG_WALT) || defined(CONFIG_HW_TOP_TASK) \
	|| defined(CONFIG_HW_TASK_RAVG_SUM)
static inline int exiting_task(struct task_struct *p)
{
	return p->flags & PF_EXITING;
}
#endif

#ifdef CONFIG_HW_SCHED_WALT
extern unsigned int sysctl_sched_use_walt_cpu_util;
extern unsigned int sysctl_sched_use_walt_task_util;
extern unsigned int sysctl_sched_walt_init_task_load_pct;
extern unsigned int sysctl_sched_walt_cpu_overload_irqload;
extern bool walt_disabled;

extern int walt_cpu_overload_irqload(int cpu);

extern int sysctl_sched_walt_init_task_load_pct_sysctl_handler(
		struct ctl_table *table, int write, void __user *buffer,
		size_t *length, loff_t *ppos);

extern ssize_t walt_init_task_load_pct_show(struct kobject *kobj,
		struct kobj_attribute *attr, char *buf);

extern ssize_t walt_init_task_load_pct_store(struct kobject *kobj,
		struct kobj_attribute *attr, const char *buf, size_t count);

static inline bool use_pelt_freq(void)
{
	return (!sysctl_sched_use_walt_cpu_util || walt_disabled);
}

#ifdef CONFIG_HAVE_QCOM_SCHED_WALT
extern unsigned int sysctl_sched_init_task_load_pct;
#endif

#else /* !CONFIG_HW_SCHED_WALT */

#define walt_cpu_overload_irqload(cpu) false

static inline bool use_pelt_freq(void)
{
	return true;
}

#endif /* CONFIG_HW_SCHED_WALT */

#endif
