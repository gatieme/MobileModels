/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager task status
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for tasl status API
 *
 */
#ifndef _SCM_TASK_STATUS_H_
#define _SCM_TASK_STATUS_H_

#include <linux/sched/prio.h>

// task important status.
#define SCM_IMST_INVALID 0x0
#define SCM_IMST_PRIO_LOW 0x1
#define SCM_IMST_PRIO_HIGH 0x2
#define SCM_IMST_PRIO_VIP 0x4
#define SCM_IMST_PRIO_GC 0x8
#define SCM_IMST_PROC_FOREGROUND 0x10
#define SCM_IMST_PROC_FOREGROUND_RELATED 0x20
#define SCM_IMST_PROC_BACKGROUND 0x40
#define SCM_IMST_PROC_UNKNOWN 0x80
#define SCM_IMST_MM_MMAPLOCKED 0x100

static inline bool _scm_is_kernel_thread(struct task_struct *task)
{
	return (task->flags & PF_KTHREAD);
}

#ifdef MAX_RT_PRIO
#define _SCM_SYS_RT_PRIO MAX_RT_PRIO
#else
#define _SCM_SYS_RT_PRIO MAX_USER_RT_PRIO
#endif

static inline bool _scm_task_is_rt(struct task_struct *task)
{
	return (task->prio < _SCM_SYS_RT_PRIO);
}

#define _CONFIG_SCM_TASK_STATUS_HAS_CACHE

#endif //_SCM_TASK_STATUS_H_
