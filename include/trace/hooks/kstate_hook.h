/*
 * This program is used for create hook in kstate.
 *
 * HONOR POWER
 */

#ifndef _KSTATE_HOOK_H
#define _KSTATE_HOOK_H

#include <linux/device.h>
#include <linux/slab.h>
#include <linux/sched/signal.h>
#include <linux/capability.h>

typedef int(*kstate_binder_cb)(int, int);
typedef int(*kstate_kill_cb)(int, int);
typedef bool(*kstate_exempt_async_invocation_cb)(int);

void kstate_binder_cb_hook(kstate_binder_cb kstate_cb_hook);
void kstate_kill_cb_hook(kstate_kill_cb kstate_cb_hook);
void kstate_exempt_async_invocation_cb_hook(kstate_exempt_async_invocation_cb kstate_cb_hook);

extern kstate_binder_cb kernel_binder_cb_hook;
extern kstate_kill_cb kernel_kill_cb;
extern kstate_exempt_async_invocation_cb kstate_is_async_call_exempted;

#endif
