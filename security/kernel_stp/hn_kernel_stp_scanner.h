/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
 * Description: the hn_kernel_stp_scanner.h for kernel stp
 * Author: jiayunlong <jiayunlong@hihonor.com>
 * Create: 2021-08-30
 */

#ifndef _HN_KERNEL_STP_SCANNER_H_
#define _HN_KERNEL_STP_SCANNER_H_

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/mutex.h>
#include "hn_kernel_stp_utils.h"
#include <security/hn_kernel_stp_interface.h>

#define KSTP_SCAN_LIST_INIT 1
#define KSTP_SCAN_LIST_UNINIT 0

struct kernel_stp_scanner_node {
	struct list_head stp_scanner_list; /* kernel stp scanner list */
	stp_cb callbackfunc; /* detection modules callbackfunc */
};

struct kernel_stp_scan_work {
	stp_cb callbackfunc; /* detection modules callbackfunc */
	struct work_struct work;
};

int kernel_stp_scanner_init(void);

void kernel_stp_scanner(void);

void kernel_stp_scanner_exit(void);

#endif /* _HN_KERNEL_STP_SCANNER_H_ */