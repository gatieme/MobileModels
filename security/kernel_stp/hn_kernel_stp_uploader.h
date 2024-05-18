/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
 * Description: the hn_kernel_stp_uploader.h for kernel stp
 * Author: jiayunlong <jiayunlong@hihonor.com>
 * Create: 2021-08-30
 */

#ifndef _HN_KERNEL_STP_UPLOADER_H_
#define _HN_KERNEL_STP_UPLOADER_H_

#include <linux/kobject.h>
#include <linux/slab.h>
#include <security/hn_kernel_stp_interface.h>
#include "hn_kernel_stp_utils.h"

#define KERNEL_STP_UEVENT_LEN  2
#define STP_INFO_MAXLEN   1024

int kernel_stp_uploader_init(void);
void kernel_stp_uploader_exit(void);
#endif /* _HN_KERNEL_STP_UPLOADER_H_*/

