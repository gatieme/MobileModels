/*
 * Copyright (c) Honor Device Co., Ltd. 2021-2021. All rights reserved.
 * Description: the hn_kernel_stp_saudit.h
 * Author: jiayunlong <jiayunlong@hihonor.com>
 * Create: 2021-08-30
 */

#ifndef _HN_KERNEL_STP_SAUDIT_H_
#define _HN_KERNEL_STP_SAUDIT_H_

#include <linux/time.h>
#include <linux/statfs.h>
#include <linux/stacktrace.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/version.h>
#include <security/hn_kernel_stp_interface.h>
#define SAUDIT_STACK_DEPTH 16
#define SAUDIT_SELF_DEPTH 2
#define SAUDIT_BUFSIZ 1024

struct saudit_buffer {
	struct stp_item item;
	char            info[SAUDIT_BUFSIZ];
	size_t          offset;
	unsigned int    flags;
	unsigned int    delay;
};

enum saudit_flags {
	SAUDIT_ASYNC   = (1 << 0),
	SAUDIT_ATOMIC  = (1 << 1),
	SAUDIT_TRACE   = (1 << 2),
	SAUDIT_REF     = (1 << 3),
};

struct saudit_upload_work {
	struct work_struct worker;
	struct saudit_buffer sab;
};

#endif /* _HN_KERNEL_STP_SAUDIT_H_ */