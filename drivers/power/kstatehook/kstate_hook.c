/*
 * This program is used for create hook in kstate.
 *
 * HONOR POWER
 */

#include <trace/hooks/kstate_hook.h>

kstate_binder_cb kernel_binder_cb_hook = NULL;
kstate_kill_cb kernel_kill_cb = NULL;
kstate_exempt_async_invocation_cb kstate_is_async_call_exempted = NULL;


void kstate_binder_cb_hook(kstate_binder_cb kstate_cb_hook)
{
    kernel_binder_cb_hook = kstate_cb_hook;
}
EXPORT_SYMBOL_GPL(kstate_binder_cb_hook);

void kstate_kill_cb_hook(kstate_kill_cb kstate_cb_hook)
{
    kernel_kill_cb = kstate_cb_hook;
}
EXPORT_SYMBOL_GPL(kstate_kill_cb_hook);

void kstate_exempt_async_invocation_cb_hook(kstate_exempt_async_invocation_cb kstate_cb_hook)
{
	kstate_is_async_call_exempted = kstate_cb_hook;
}
EXPORT_SYMBOL_GPL(kstate_exempt_async_invocation_cb_hook);
