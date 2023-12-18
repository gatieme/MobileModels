/*
 * hw_top_task.h
 *
 * trace header for hw top task
 *
 * Copyright (c) 2021-2022 Huawei Technologies Co., Ltd.
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

TRACE_EVENT(sched_top_task_load_update_history,

	TP_PROTO(struct rq *rq, struct task_struct *p,
		unsigned int stats_policy, unsigned int hist_size,
		u32 runtime, int sample, int event,
		u64 sum, u32 avg, u32 load_avg),
	TP_ARGS(rq, p, stats_policy, hist_size, runtime, sample,
		event, sum, avg, load_avg),

	TP_STRUCT__entry(
		__field(int,	cpu)
		__field(int,	top_task_pid)
		__field(int,	policy)
		__field(int,	hist_size)
		__field(u32,	runtime)
		__field(int,	sample)
		__field(int,	event)
		__field(u64,	sum)
		__field(u64,	avg)
		__field(u64,	load_avg)
	),

	TP_fast_assign(
		__entry->cpu		= cpu_of(rq);
		__entry->top_task_pid	= p->pid;
		__entry->policy		= stats_policy;
		__entry->hist_size	= hist_size;
		__entry->runtime	= runtime;
		__entry->sample		= sample;
		__entry->event		= event;
		__entry->sum		= sum;
		__entry->avg		= avg;
		__entry->load_avg	= load_avg;
	),

	TP_printk("cpu=%d top_task_pid=%d stats_policy=%d hist_size=%d runtime=%lu "
		  "sample=%d event=%d sum=%llu avg=%llu load_avg=%llu",
		__entry->cpu, __entry->top_task_pid, __entry->policy,
		__entry->hist_size, __entry->runtime, __entry->sample,
		__entry->event, __entry->sum, __entry->avg, __entry->load_avg)
);
