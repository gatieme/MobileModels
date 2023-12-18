#undef TRACE_SYSTEM
#define TRACE_SYSTEM render_rt

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_RENDER_RT_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_RENDER_RT_H

#include <linux/sched.h>
#include <linux/tracepoint.h>
#include <trace/hooks/vendor_hooks.h>

struct task_struct;
DECLARE_HOOK(android_vh_remove_render_rthread,
	TP_PROTO(struct task_struct *task),
	TP_ARGS(task));

DECLARE_RESTRICTED_HOOK(android_rvh_add_waker_to_render_rthread,
	TP_PROTO(struct task_struct *task),
	TP_ARGS(task), 1);

DECLARE_RESTRICTED_HOOK(android_rvh_add_render_rthread,
	TP_PROTO(struct task_struct *task),
	TP_ARGS(task), 1);

#endif /* _TRACE_HOOK_RENDER_RT_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
