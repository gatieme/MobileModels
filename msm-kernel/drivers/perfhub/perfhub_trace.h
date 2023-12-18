/*
 * perfhub_trace.h
 *
 * implement perfhub
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#undef TRACE_SYSTEM
#define TRACE_SYSTEM sched_perfhub

#if !defined(_TRACE_PERFHUB_TRACE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_PERFHUB_TRACE_H
#include <linux/tracepoint.h>

#if defined(CONFIG_HW_PERFHUB_TRACE)
/*
 * Tracepoint for sched_setaffinity
 */
TRACE_EVENT(sched_set_affinity,

	TP_PROTO(struct task_struct *p, const struct cpumask *mask),

	TP_ARGS(p, mask),

	TP_STRUCT__entry(
		__array(   char,	comm,	TASK_COMM_LEN	)
		__field(   pid_t,	pid			)
		__bitmask( cpus,	num_possible_cpus()	)
	),

	TP_fast_assign(
		__entry->pid = p->pid;
		memcpy(__entry->comm, p->comm, TASK_COMM_LEN);
		__assign_bitmask(cpus, cpumask_bits(mask), num_possible_cpus());
	),

	TP_printk("comm=%s pid=%d cpus=%s",
		__entry->comm, __entry->pid, __get_bitmask(cpus))
);
#endif

#endif /* _TRACE_PERFHUB_TRACE_H */

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH ../../drivers/perfhub
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE perfhub_trace

/* This part must be outside protection */
#include <trace/define_trace.h>
