/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager helper
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for module register.
 *
 */
#include "scm_internal.h"
#include "scm_sub_modules.h"

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 15, 0)
MODULE_IMPORT_NS(MINIDUMP);
#endif

struct scm_module {
	/* sysfs node */
	struct kobject *kobj;
};

static struct scm_module scm_module;

#define SCM_MODE_RO 0440
#define SCM_MODE_WO 0200
#define SCM_MODE_RW 0660
#define SCM_ATTR(_name, _mode, _show, _store)     \
	struct kobj_attribute kobj_attr_##_name = \
		__ATTR(_name, _mode, _show, _store)

static SCM_ATTR(event, SCM_MODE_RW, scm_event_show, scm_event_store);

static struct attribute *scm_attrs[] = {
	&kobj_attr_event.attr,
	NULL,
};

static struct attribute_group scm_module_attr_group = {
	.attrs = scm_attrs,
};

static struct kobject *scm_sysfs_create(void)
{
	int err;
	struct kobject *kobj = NULL;
	kobj = kobject_create_and_add("scm", kernel_kobj);

	if (!kobj) {
		pr_err("scm: failed to create sysfs node.\n");
		return NULL;
	}
	err = sysfs_create_group(kobj, &scm_module_attr_group);
	if (err) {
		pr_err("scm: failed to create sysfs attrs.\n");
		kobject_put(kobj);
		return NULL;
	}
	return kobj;
}

static int __init scm_init(void)
{
	scm_sub_modules_init();
	scm_module.kobj = scm_sysfs_create();
	pr_info("scm: module inited.\n");
	return 0;
}

module_init(scm_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("davidly <davidly.lizhiwei.>");
MODULE_DESCRIPTION("Smart Cache Manager");
