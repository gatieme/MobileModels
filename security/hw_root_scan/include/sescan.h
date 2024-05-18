/*
 * Copyright (c) Honor Device Co., Ltd. 2016-2019. All rights reserved.
 * Description: the sescan.h for selinux status checking
 * Author: Yongzheng Wu <Wu.Yongzheng.>
 *         likun <quentin.lee.>
 *         likan <likan82.>
 * Create: 2016-06-18
 */

#ifndef _SESCAN_H_
#define _SESCAN_H_

#include <asm/sections.h>
#include <linux/crypto.h>
#include <linux/kallsyms.h>
#include <linux/kernel.h>
#include <linux/scatterlist.h>
#include <linux/security.h>
#include <linux/string.h>
#include <linux/version.h>
#include <crypto/hash.h>
#include <crypto/hash_info.h>
#include "./include/hw_rscan_utils.h"

#define ENFORCING_ENABLED 1
#define ENFORCING_DISABLED 0
/* selinux_enforcing is kernel variable */
#ifdef CONFIG_SECURITY_SELINUX_DEVELOP

#ifdef CONFIG_MTK_PLATFORM
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 186)
extern int selinux_enforcing;
#define SELINUX_ENFORCING selinux_enforcing
#endif
#else    /* QCOM platform */
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 17, 0)
extern int selinux_enforcing;
#define SELINUX_ENFORCING selinux_enforcing
#endif
#endif

#else
#define SELINUX_ENFORCING 1
#endif

int get_selinux_enforcing_from_kernel(void);
int get_selinux_enforcing(void);
int sescan_hookhash(uint8_t *hash, size_t hash_len);

#endif
