/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * dpu_trace.h
 *
 * The driver of adaptive frame rate
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

#if !defined(_DPU_TRACE_H_) || defined(TRACE_HEADER_MULTI_READ)
#define _DPU_TRACE_H_

#include <linux/stringify.h>
#include <linux/types.h>
#include <linux/tracepoint.h>

#undef TRACE_SYSTEM
#define TRACE_SYSTEM gfx
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE dpu_trace

TRACE_EVENT(tracing_mark_write,
	TP_PROTO(char type, const struct task_struct *task,
		const char *name, int val),
	TP_ARGS(type, task, name, val),
	TP_STRUCT__entry(
			__field(char, type)
			__field(int, pid)
			__string(trace_name, name)
			__field(int, val)
	),
	TP_fast_assign(
			__entry->type = type;
			__entry->pid = task ? task->tgid : 0;
			__assign_str(trace_name, name);
			__entry->val = val;
	),
	TP_printk("%c|%d|%s|%d", __entry->type,
			__entry->pid, __get_str(trace_name), __entry->val)
);

#define dpu_atrace trace_tracing_mark_write

#define DPU_ATRACE_BEGIN(name) dpu_atrace('B', current, name, 0)
#define DPU_ATRACE_END(name) dpu_atrace('E', current, name, 0)
#define DPU_ATRACE_BEGIN_WITH_VALUE(name,value) dpu_atrace('B', current, name, value)
#define DPU_ATRACE_END_WITH_VALUE(name,value) dpu_atrace('E', current, name, value)
#define DPU_ATRACE_FUNC() DPU_ATRACE_BEGIN(__func__)
#define DPU_ATRACE_INT(name, value) dpu_atrace('C', current, name, value)

#define DPU_ATRACE_BEGIN_WITH_GID_VALUE(name, task, value) dpu_atrace('B', task, name, value)
#define DPU_ATRACE_END_WITH_GID_VALUE(name, task,value) dpu_atrace('E', task, name, value)
#define DPU_ATRACE_INT_WITH_GID_VALUE(name, task, value) dpu_atrace('C', task, name, value)

#define DPU_ATRACE_BEGIN_WITH_GID(name, task) dpu_atrace('B', task, name, 0)
#define DPU_ATRACE_END_WITH_GID(name, task) dpu_atrace('E', task, name, 0)

#endif /* _DPU_TRACE_H_ */

/* This part must be outside protection */
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#include <trace/define_trace.h>
