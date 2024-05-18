/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM mutex

#undef TRACE_INCLUDE_PATH


#if !defined(_TRACE_MUTEX_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MUTEX_H

#include <linux/tracepoint.h>

TRACE_EVENT(mutex_lock_contention,

	TP_PROTO(int pid, unsigned long time),

	TP_ARGS(pid, time),

	TP_STRUCT__entry(__field(int, pid)
			 __field(unsigned long, time)
	),

	TP_fast_assign(__entry->pid = pid;
			   __entry->time = time),

	TP_printk("pid=%d ts=%ld", __entry->pid, __entry->time)
);

TRACE_EVENT(mutex_lock_contention_length,

	TP_PROTO(const char *name, int pid, unsigned long time),

	TP_ARGS(name, pid, time),

	TP_STRUCT__entry(__field(const char *, name)
		     __field(int, pid)
		     __field(unsigned long, time)
	),

	TP_fast_assign(__entry->name = name;
		   __entry->pid = pid;
		   __entry->time = time),

	TP_printk("name=%s pid=%d ts=%ld", __entry->name, __entry->pid,
		      __entry->time)
);

TRACE_EVENT(mutex_wakeup,

	TP_PROTO(int target_pid, int sender_pid),

	TP_ARGS(target_pid, sender_pid),

	TP_STRUCT__entry(__field(int, target_pid)
		     __field(int, sender_pid)
	),

	TP_fast_assign(__entry->target_pid = target_pid;
		   __entry->sender_pid = sender_pid),

	TP_printk("tpid=%d spid=%ld", __entry->target_pid, __entry->sender_pid)
);

#endif

#include <trace/define_trace.h>