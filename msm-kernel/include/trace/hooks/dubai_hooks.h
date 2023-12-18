/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: qcom ddr_freq_residency interface hook
 * Author: tuyongcheng tuyongcheng1@huawei.com
 * Create: 2022-06-28
 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM dubai_hooks

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_DUBAI_HOOKS_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_DUBAI_HOOKS_H

#include <linux/tracepoint.h>
#include <soc/qcom/soc_sleep_stats.h>
#include <trace/hooks/vendor_hooks.h>

DECLARE_HOOK(android_vh_ddr_stats_get_residency,
	TP_PROTO(int freq_count, struct ddr_freq_residency *data, int *ret),
	TP_ARGS(freq_count, data, ret));

DECLARE_HOOK(android_vh_ddr_stats_get_freq_count,
	TP_PROTO(int32_t *freq_cnt),
	TP_ARGS(freq_cnt));

#endif /* _TRACE_HOOK_DUBAI_HOOKS_H) */
/* This part must be outside protection */
#include <trace/define_trace.h>
