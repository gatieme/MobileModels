/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: rpmb ffa interface for kernel redirect to secure partition
 * Create: 2023-02-07
 */

#ifndef __RPMB_FFA_H__
#define __RPMB_FFA_H__

#include <linux/types.h>

#ifdef CONFIG_RPMB_FFA_SUPPORT
int rpmb_ffa_send(u64 arg0, u64 arg1, u64 arg2, u64 arg3);
#endif

#endif /* __RPMB_FFA_H__ */
