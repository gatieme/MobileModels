/*
 * pred_load.h
 *
 * pred load sched trace events
 *
 * Copyright (c) 2020-2021 Huawei Technologies Co., Ltd.
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
#ifdef CONFIG_HW_SCHED_PRED_LOAD
#include <securec.h>

TRACE_EVENT(predl_adjust_runtime,

	TP_PROTO(struct task_struct *p, u64 task_util, u64 capacity_curr),

	TP_ARGS(p, task_util, capacity_curr),

	TP_STRUCT__entry(
		__array(	char,	comm,   TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	u64,	util			)
		__field(	u64,	cap			)
	),

	TP_fast_assign(
		memcpy_s(__entry->comm, TASK_COMM_LEN, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->util		= task_util;
		__entry->cap		= capacity_curr;
	),

	TP_printk("%d (%s): task_util=%lu cpu_cap_curr=%lu",
		__entry->pid, __entry->comm, __entry->util, __entry->cap)
);

TRACE_EVENT(predl_window_rollover,

	TP_PROTO(int cpu),

	TP_ARGS(cpu),

	TP_STRUCT__entry(
		__field(	int,	cpu	)
	),

	TP_fast_assign(
		__entry->cpu	= cpu;
	),

	TP_printk("cpu=%d", __entry->cpu)
);

TRACE_EVENT(predl_update_history,

	TP_PROTO(struct task_struct *p),

	TP_ARGS(p),

	TP_STRUCT__entry(
		__array(	char,	comm,   TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__array(	u32,	hist, RAVG_HIST_SIZE_MAX)
	),

	TP_fast_assign(
		memcpy_s(__entry->comm, TASK_COMM_LEN, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		memcpy_s(__entry->hist, RAVG_HIST_SIZE_MAX * sizeof(u32),
			 walt_task_struct_get(p, predl_sum_history), RAVG_HIST_SIZE_MAX * sizeof(u32));
	),

	TP_printk("%d (%s): hist (%u %u %u %u %u)",
		__entry->pid, __entry->comm,
		__entry->hist[0], __entry->hist[1],
		__entry->hist[2], __entry->hist[3],
		__entry->hist[4])
);

TRACE_EVENT(predl_get_busy,

	TP_PROTO(struct task_struct *p, u32 runtime, int bidx, u32 predl),

	TP_ARGS(p, runtime, bidx, predl),

	TP_STRUCT__entry(
		__array(	char,	comm, TASK_COMM_LEN	)
		__field(	pid_t,	pid			)
		__field(	u32,	runtime			)
		__field(	int,	bidx			)
		__array(	u8,	bucket, NUM_BUSY_BUCKETS)
		__field(	u32,	predl			)
	),

	TP_fast_assign(
		memcpy_s(__entry->comm, TASK_COMM_LEN, p->comm, TASK_COMM_LEN);
		__entry->pid		= p->pid;
		__entry->runtime	= runtime;
		__entry->bidx		= bidx;
		memcpy_s(__entry->bucket, NUM_BUSY_BUCKETS * sizeof(u8),
			 walt_task_struct_get(p, predl_busy_buckets), NUM_BUSY_BUCKETS * sizeof(u8));
		__entry->predl		= predl;
	),

	TP_printk("%d (%s): runtime %u bidx %d buckets (%u %u %u %u %u %u %u %u %u %u) predl %u",
		__entry->pid, __entry->comm,
		__entry->runtime, __entry->bidx,
		__entry->bucket[0], __entry->bucket[1], __entry->bucket[2],
		__entry->bucket[3], __entry->bucket[4], __entry->bucket[5],
		__entry->bucket[6], __entry->bucket[7], __entry->bucket[8],
		__entry->bucket[9], __entry->predl)
);
#ifdef CONFIG_HW_SCHED_PRED_LOAD_WINDOW_SIZE_SYNC
TRACE_EVENT(pred_load_window_change,

	TP_PROTO(unsigned int predl_window_size, unsigned int new_predl_window_size
		, u64 change_time),

	TP_ARGS(predl_window_size, new_predl_window_size, change_time),

	TP_STRUCT__entry(
		__field(unsigned int, predl_window_size)
		__field(unsigned int, new_predl_window_size)
		__field(u64, change_time)
	),

	TP_fast_assign(
		__entry->predl_window_size = predl_window_size;
		__entry->new_predl_window_size = new_predl_window_size;
		__entry->change_time = change_time;
	),

	TP_printk("from=%u to=%u at=%lu",
		__entry->predl_window_size, __entry->new_predl_window_size,
		__entry->change_time)
	);
#endif
#endif /* CONFIG_HW_SCHED_PRED_LOAD */
