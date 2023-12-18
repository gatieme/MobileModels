#undef TRACE_SYSTEM
#define TRACE_SYSTEM huawei_ltpo

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_HUAWEI_LTPO_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_HUAWEI_LTPO_H

#include <linux/types.h>
#include <linux/tracepoint.h>
#include <trace/hooks/vendor_hooks.h>

DECLARE_RESTRICTED_HOOK(android_rvh_get_average_fps,
	TP_PROTO(int *out_fps_counter),
	TP_ARGS(out_fps_counter), 1);

#endif /* _TRACE_HOOK_CPU_H */
/* This part must be outside protection */
#include <trace/define_trace.h>