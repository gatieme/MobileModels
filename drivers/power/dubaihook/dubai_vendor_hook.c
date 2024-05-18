/*
 * This program is used for create hook in dubai.
 *
 * HONOR POWER
 */

#include <trace/hooks/dubai_vendor_hook.h>

dubaiLogIrqWakeup kernelWakeupHook = NULL;
dubaiSetRtcTimer kernelAlarmtimerHook = NULL;
dubaiUpdateSuspend kernelWakeupReasonHook = NULL;
dubaiLogUevent kernelKobjectHook = NULL;
dubaiLogKworker kernelWorkqueueHook = NULL;
dubaiLogBinderStats kernelBinderHook = NULL;

void dubai_log_irq_wakeup_hook(dubaiLogIrqWakeup dubaiWakeupHook)
{
    kernelWakeupHook = dubaiWakeupHook;
}
EXPORT_SYMBOL_GPL(dubai_log_irq_wakeup_hook);

void dubai_set_rtc_timer_hook(dubaiSetRtcTimer dubaiAlarmtimerHook)
{
    kernelAlarmtimerHook = dubaiAlarmtimerHook;
}
EXPORT_SYMBOL_GPL(dubai_set_rtc_timer_hook);

void dubai_update_suspend_abort_reason_hook(dubaiUpdateSuspend dubaiWakeupReasonHook)
{
    kernelWakeupReasonHook = dubaiWakeupReasonHook;
}
EXPORT_SYMBOL_GPL(dubai_update_suspend_abort_reason_hook);

void dubai_log_uevent_hook(dubaiLogUevent dubaiKobjectHook)
{
	kernelKobjectHook = dubaiKobjectHook;
}
EXPORT_SYMBOL_GPL(dubai_log_uevent_hook);

void dubai_log_kworker_hook(dubaiLogKworker dubaiWorkqueueHook)
{
	kernelWorkqueueHook = dubaiWorkqueueHook;
}
EXPORT_SYMBOL_GPL(dubai_log_kworker_hook);

void dubai_log_binder_stats_hook(dubaiLogBinderStats dubaiBinderHook)
{
	kernelBinderHook = dubaiBinderHook;
}
EXPORT_SYMBOL_GPL(dubai_log_binder_stats_hook);
