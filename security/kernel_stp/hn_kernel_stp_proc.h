/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
 * Description: the hn_kernel_stp_proc.h for kernel stp
 * Author: jiayunlong <jiayunlong@hihonor.com>
 * Create: 2021-08-30
 */

#ifndef _HN_KERNEL_STP_PROC_H_
#define _HN_KERNEL_STP_PROC_H_

#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/uidgid.h>
#include "hn_kernel_stp_utils.h"
#include "hn_kernel_stp_scanner.h"

#define KERNEL_STP_TRIGGER_MARK 0xffffffff
#define KERNEL_STP_PROC_MAX_LEN 1023
#define KERNEL_STP_PROC_HEX_BASE 16

int kernel_stp_proc_init(void);
void kernel_stp_proc_exit(void);

#endif /* _HN_KERNEL_STP_PROC_H_ */

