/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM thermal

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_THERMAL_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_THERMAL_H

#include <linux/tracepoint.h>
#include <trace/hooks/vendor_hooks.h>

#ifdef __GENKSYMS__
struct thermal_zone_device;
#else
/* struct thermal_zone_device */
#include <linux/thermal.h>
#endif /* __GENKSYMS__ */
DECLARE_HOOK(android_vh_enable_thermal_genl_check,
	TP_PROTO(int event, int tz_id, int *enable_thermal_genl),
	TP_ARGS(event, tz_id, enable_thermal_genl));

DECLARE_HOOK(android_vh_thermal_pm_notify_suspend,
	     TP_PROTO(struct thermal_zone_device *tz, int *irq_wakeable),
	     TP_ARGS(tz, irq_wakeable));

DECLARE_HOOK(android_vh_get_gpu_power_params,
	TP_PROTO(unsigned int *voltage_scale_num, s64 *volt_scale,
		 unsigned int *dyn_cap_item_num, s64 *dyn_cap,
		 int array_size, int *ret),
	TP_ARGS(voltage_scale_num, volt_scale,
		dyn_cap_item_num, dyn_cap, array_size, ret));

struct thermal_cooling_device;
DECLARE_HOOK(android_vh_disable_thermal_cooling_stats,
	TP_PROTO(struct thermal_cooling_device *cdev, bool *disable_stats),
	TP_ARGS(cdev, disable_stats));

#endif /* _TRACE_HOOK_THERMAL_H */
/* This part must be outside protection */
#include <trace/define_trace.h>

