/*
 * Copyright (c) Honor Device Co., Ltd. 2023. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ctype.h>
#include <linux/mm.h>
#include <linux/gfp.h>
#include <linux/kernel_stat.h>
#include <linux/init.h>
#include <linux/pagemap.h>
#include <linux/pagevec.h>
#include <linux/migrate.h>

struct mem_stats_attribute {
	struct attribute attr;
	void *value;
	 ssize_t(*show) (void *, char *);
	 ssize_t(*store) (void *, const char *, size_t);
};

/* rule:
 *   mem_total   free_min
 *      8 GB       8 MB
 *      12GB       12MB
 *      16GB       16MB
 */
#define free_min(nr)  ((nr) >> 10)
/* max file_page、anon_page value is (totalram_pages*5/8) */
#define used_max(nr)  ((nr) * 5 >> 3)

/* if isolated > inactive/32, predicate the value anomal*/
#define ISOLATED_THRESHOLD    5
/* the interval of report buddy info */
#define BUDDY_REPORT_INTERVAL  (2 * 60 * 60)
/* the interval of report mem event */
#define REPORT_INTERVAL  (8 * 60 * 60)
/* the minimum interval of report event */
#define MIN_REPORT_INTERVAL 10

unsigned long free_page_min;
EXPORT_SYMBOL_GPL(free_page_min);
unsigned long used_page_max;
EXPORT_SYMBOL_GPL(used_page_max);
unsigned long isolated_threshold;
EXPORT_SYMBOL_GPL(isolated_threshold);
unsigned int report_rs_interval;
unsigned int buddy_report_rs_interval;
DEFINE_RATELIMIT_STATE(report_rs, REPORT_INTERVAL * HZ, 1);
EXPORT_SYMBOL_GPL(report_rs);
DEFINE_RATELIMIT_STATE(buddy_report_rs, BUDDY_REPORT_INTERVAL * HZ, 1);
EXPORT_SYMBOL_GPL(buddy_report_rs);

/* simple show/store functions for attributes */
static ssize_t mem_stats_attr_show(void *ptr, char *buf)
{
	return sysfs_emit(buf, "%u\n", *((unsigned long *)ptr));
}

static ssize_t mem_stats_attr_store(void *ptr, const char *buf, size_t count)
{
	unsigned long *value = ptr;

	if (isdigit(*buf))
		*value = simple_strtoul(buf, NULL, 0);

	return count;
}

static ssize_t report_rs_store(void *ptr, const char *buf, size_t count)
{
	unsigned int *value = ptr;
	unsigned int tmp;

	if (isdigit(*buf)) {
		tmp = simple_strtoul(buf, NULL, 0);
		if (tmp >= MIN_REPORT_INTERVAL) {
			*value = tmp;
			report_rs.interval = tmp * HZ;
		}

	}

	return count;
}

static ssize_t buddy_report_rs_store(void *ptr, const char *buf, size_t count)
{
	unsigned int *value = ptr;
	unsigned int tmp;

	if (isdigit(*buf)) {
		tmp = simple_strtoul(buf, NULL, 0);
		if (tmp >= MIN_REPORT_INTERVAL) {
			*value = tmp;
			buddy_report_rs.interval = tmp * HZ;
		}

	}

	return count;
}

/* Set of show/store abstract level functions for mem_stats object */
static ssize_t mem_stats_show(struct kobject *kobj, struct attribute *attr,
				 char *buffer)
{
	struct mem_stats_attribute *mem_stats_attr;

	mem_stats_attr = (struct mem_stats_attribute *)attr;
	if (mem_stats_attr->show)
		return mem_stats_attr->show(mem_stats_attr->value, buffer);
	return -EIO;
}

static ssize_t mem_stats_store(struct kobject *kobj,
				struct attribute *attr, const char *buffer,
				size_t count)
{
	struct mem_stats_attribute *mem_stats_attr;

	mem_stats_attr = (struct mem_stats_attribute *)attr;
	if (mem_stats_attr->store)
		return mem_stats_attr->store(mem_stats_attr->value, buffer, count);
	return -EIO;
}

static const struct sysfs_ops mem_stats_sysfs_ops = {
	.show = mem_stats_show,
	.store = mem_stats_store
};

#define mem_stats_attr(_name,_mode,_show,_store)			\
static struct mem_stats_attribute mem_stats_attr_##_name = {		\
	.attr = {.name = __stringify(_name), .mode = _mode },	\
	.value  = &_name,					\
	.show   = _show,					\
	.store  = _store,					\
};

mem_stats_attr(free_page_min, S_IRUGO | S_IWUSR,
	mem_stats_attr_show, mem_stats_attr_store);
mem_stats_attr(used_page_max, S_IRUGO | S_IWUSR,
	mem_stats_attr_show, mem_stats_attr_store);
mem_stats_attr(isolated_threshold, S_IRUGO | S_IWUSR,
	mem_stats_attr_show, mem_stats_attr_store);
mem_stats_attr(report_rs_interval, S_IRUGO | S_IWUSR,
	mem_stats_attr_show, report_rs_store);
mem_stats_attr(buddy_report_rs_interval, S_IRUGO | S_IWUSR,
	mem_stats_attr_show, buddy_report_rs_store);

static struct mem_stats_attribute *mem_stats_attrs[] = {
	&mem_stats_attr_free_page_min,
	&mem_stats_attr_used_page_max,
	&mem_stats_attr_isolated_threshold,
	&mem_stats_attr_report_rs_interval,
	&mem_stats_attr_buddy_report_rs_interval,
	NULL,
};

/*
static const struct attribute_group mem_stats_attr_group = {
	.attrs = mem_stats_attrs,
};
*/

static void mem_stats_release_main_kobj(struct kobject *kobj)
{
	pr_info("here to module_put(THIS_MODULE)\n");

	kfree(kobj);

	/* last reference to topkobject has been removed,
	 * NOW release our ref count on the core module
	 */
	module_put(THIS_MODULE);
}

static struct kobj_type ktype_mem_stats_kobj = {
	.release = mem_stats_release_main_kobj,
	.sysfs_ops = &mem_stats_sysfs_ops,
	.default_attrs = (struct attribute **)mem_stats_attrs,
};

static int __init mem_stats_init_sysfs(void)
{
	int err;
	unsigned long nr_total;
	struct kobject *mem_stats_kobj;

	nr_total = totalram_pages();
	free_page_min = free_min(nr_total);
	used_page_max = used_max(nr_total);
	isolated_threshold = ISOLATED_THRESHOLD;
	report_rs_interval = report_rs.interval / HZ;
	buddy_report_rs_interval = buddy_report_rs.interval / HZ;

	mem_stats_kobj = kzalloc(sizeof(struct kobject), GFP_KERNEL);
	if (!mem_stats_kobj) {
		return -ENOMEM;
	}

	/* Instanstiate the mem_stats object */
	err = kobject_init_and_add(mem_stats_kobj,
				   &ktype_mem_stats_kobj,
				   mm_kobj, "mem_stats");
	if (err) {
		pr_err("Failed to register mem_stats\n");
		goto kobject_init_and_add_fail;
	}

	return 0;

kobject_init_and_add_fail:
	kobject_put(mem_stats_kobj);
	return err;
}
subsys_initcall(mem_stats_init_sysfs);
