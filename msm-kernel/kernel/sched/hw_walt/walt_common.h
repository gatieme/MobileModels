/*
 * walt_common.h
 *
 * common macro for member get
 *
 * Copyright (c) 2021-2021 Huawei Technologies Co., Ltd.
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
#ifndef __WALT_COMMON_H__
#define __WALT_COMMON_H__

#include <linux/version.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))

#define walt_task_struct_addr(p) ((struct walt_task_struct *)((p)->android_vendor_data1))
#define walt_rq_addr(rq) ((struct walt_rq *)((rq)->android_vendor_data1))
#define walt_ktime_clock walt_ktime_get_ns

#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(5,4,0))

#define walt_task_struct_addr(p) (&((p)->wts))
#define walt_rq_addr(rq) (&((rq)->wrq))
#define walt_ktime_clock sched_ktime_clock

#else

#define walt_task_struct_addr(p) (&((p)->ravg))
#define walt_rq_addr(rq) (rq)
#define walt_ktime_clock sched_ktime_clock

#endif

#define walt_task_struct_get(p, member)       ((walt_task_struct_addr(p))->member)
#define walt_task_struct_set(p, member, val)  (((walt_task_struct_addr(p))->member) = (val))
#define walt_task_struct_add(p, member, val)  (((walt_task_struct_addr(p))->member) += (val))

#define walt_rq_get(rq, member)               ((walt_rq_addr(rq))->member)
#define walt_rq_set(rq, member, val)          (((walt_rq_addr(rq))->member) = (val))
#define walt_rq_add(rq, member, val)          (((walt_rq_addr(rq))->member) += (val))


#ifdef CONFIG_HAVE_QCOM_SCHED_WALT
#if ( LINUX_VERSION_CODE < KERNEL_VERSION(5,4,0) )
#define walt_update_task_ravg update_task_ravg
#elif ( LINUX_VERSION_CODE < KERNEL_VERSION(5,10,0) )
#define sched_cluster walt_sched_cluster
#endif

#define walt_cpu_high_irqload sched_cpu_high_irqload
#define walt_ravg_window sched_ravg_window
#define walt_irqload sched_irqload
#endif

#endif /* __WALT_COMMON_H__ */
