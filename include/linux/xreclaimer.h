/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) Honor Device Co., Ltd. 2020. All rights reserved.
 * Description: xreclaimer header file
 * Author: Miao Xie <miaoxie.>
 * Create: 2020-06-29
 */
#ifndef _LINUX_XRECLAIMER_H
#define _LINUX_XRECLAIMER_H

#include <linux/version.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/signal.h>
#include <linux/sched/signal.h>
#include <linux/xreclaimer_types.h>

#ifdef CONFIG_XRECLAIMER
extern unsigned int sysctl_xreclaimer_enable;

#ifdef CONFIG_SYSCTL
extern int xreclaimer_init_sysctl(void);
#else
int xreclaimer_init_sysctl(void)
{
}
#endif

extern void xreclaimer_quick_reclaim(struct task_struct *tsk);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
/* Refer to is_si_special() and si_fromuser() in signal.c */
static inline bool __is_si_special(const struct kernel_siginfo *info)
{
	return info <= SEND_SIG_PRIV;
}

static inline bool __is_si_fromuser(const struct kernel_siginfo *info)
{
	return (!__is_si_special(info) && SI_FROMUSER(info));
}

extern void xreclaimer_cond_quick_reclaim(struct task_struct *tsk,
						 int sig, struct kernel_siginfo *info,
						 bool skip);
#else
/* Refer to is_si_special() and si_fromuser() in signal.c */
static inline bool __is_si_special(const struct siginfo *info)
{
	return info <= SEND_SIG_FORCED;
}

static inline bool __is_si_fromuser(const struct siginfo *info)
{
	return (!__is_si_special(info) && SI_FROMUSER(info));
}

extern void xreclaimer_cond_quick_reclaim(struct task_struct *tsk,
						 int sig, struct siginfo *info,
						 bool skip);
#endif

extern void xreclaimer_cond_self_reclaim(int exit_code);

extern void xreclaimer_mm_init(struct mm_struct *mm);

static inline void xreclaimer_inc_mm_tasks(struct mm_struct *mm)
{
	spin_lock(&mm->page_table_lock);
	mm->mm_xreclaimer.xrmm_ntasks++;
	spin_unlock(&mm->page_table_lock);
}

static inline void xreclaimer_dec_mm_tasks(struct mm_struct *mm)
{
	spin_lock(&mm->page_table_lock);
	mm->mm_xreclaimer.xrmm_ntasks--;
	spin_unlock(&mm->page_table_lock);
}

extern void xreclaimer_exit_mmap(struct mm_struct *mm);
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
static inline void xreclaimer_cond_quick_reclaim(struct task_struct *tsk,
						 int sig, struct kernel_siginfo *info,
						 bool skip)
{
}
#else
static inline void xreclaimer_cond_quick_reclaim(struct task_struct *tsk,
						 int sig, struct siginfo *info,
						 bool skip)
{
}
#endif

static inline void xreclaimer_cond_self_reclaim(int exit_code)
{
}

static inline void xreclaimer_mm_init(struct mm_struct *mm)
{
}

static inline void xreclaimer_inc_mm_tasks(struct mm_struct *mm)
{
}

static inline void xreclaimer_dec_mm_tasks(struct mm_struct *mm)
{
}

static inline void xreclaimer_exit_mmap(struct mm_struct *mm)
{
}
#endif
#endif
