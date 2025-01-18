/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
 */

#ifndef LITE_HCK_INET_H
#define LITE_HCK_INET_H

#include <linux/netdevice.h>
#include <platform_include/basicplatform/linux/lite_vendor_hooks.h>
/*
 * Follwing tracepoints are not exported in trace and provide a
 * mechanism for vendor modules to hok and extend functionality
 */
#ifndef CONFIG_HCK

#define CALL_HCK_LITE_HOOK(name, args...)
#define REGISTER_HCK_LITE_HOOK(name, probe)
#define REGISTER_HCK_LITE_DATA_HOOK(name, probe, data)

#else

DECLARE_HCK_LITE_HOOK(nip_ninet_ehashfn_lhck,
		TP_PROTO(const struct sock *sk, u32 *ret),
		TP_ARGS(sk, ret));

#endif /* CONFIG_HCK */

#endif /* LITE_HCK_INET_H */
