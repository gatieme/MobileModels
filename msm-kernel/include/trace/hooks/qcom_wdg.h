/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: qcom watchdog stop pet interface hook
 * Author: dongjunfeng  dongjunfeng@huawei.com
 * Create: 2022-06-16
 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM qcom_wdg
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_QCOM_WDT_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_QCOM_WDT_H
#include <linux/tracepoint.h>
#include <trace/hooks/vendor_hooks.h>
/*
 * Following tracepoints are not exported in tracefs and provide a
 * mechanism for vendor modules to hook and extend functionality
 */
DECLARE_HOOK(android_vh_qwdt_pet_stop,
	TP_PROTO(void *unused),
	TP_ARGS(unused));

/* macro versions of hooks are no longer required */

#endif /* _TRACE_HOOK_QCOM_WDT_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
