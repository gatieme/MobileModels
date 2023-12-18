#undef TRACE_SYSTEM
#define TRACE_SYSTEM rtg

#if !defined(_TRACE_RTG_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_RTG_H
#include <linux/sched/numa_balancing.h>
#include <linux/tracepoint.h>
#include <linux/binfmts.h>

#include "frame.h"
#include "frame_info.h"
#include "rtg.h"

TRACE_EVENT(rtg_frame_sched,

		TP_PROTO(int rtgid, const char *s, s64 value),

		TP_ARGS(rtgid, s, value),
		TP_STRUCT__entry(
			__field(int, rtgid)
			__field(struct frame_info *, frame)
			__field(pid_t, pid)
			__string(str, s)
			__field(s64, value)
		),

		TP_fast_assign(
			__assign_str(str, s);
			__entry->rtgid = rtgid != -1 ? rtgid : (current->grp ? current->grp->id : 0);
			__entry->frame = rtg_frame_info(rtgid);
			__entry->pid = __entry->frame ? ((__entry->frame->pid_task) ?
							((__entry->frame->pid_task)->pid) :
							current->tgid) : current->tgid;
			__entry->value = value;
		),
		TP_printk("C|%d|%s_%d|%lld", __entry->pid, __get_str(str), __entry->rtgid, __entry->value)
);

#endif /* _TRACE_RTG_H */

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH ../../kernel/sched/hw_rtg/include
#define TRACE_INCLUDE_FILE trace

#include <trace/define_trace.h>
