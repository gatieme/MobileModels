/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager module
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 */

#ifndef _SCM_SUB_MODULES_H_
#define _SCM_SUB_MODULES_H_

#include <linux/kobject.h>
#include <linux/types.h>

extern void __init scm_sub_modules_init(void);

extern ssize_t scm_event_store(struct kobject *kobj,
			       struct kobj_attribute *attr, const char *buf,
			       size_t len);
extern ssize_t scm_event_show(struct kobject *kobj, struct kobj_attribute *attr,
			      char *buf);

#endif // _SCM_SUB_MODULES_H_
