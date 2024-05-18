/*
 * Copyright (C) 2022 Honor Device Co.Ltd
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <chipset_common/hwmemcheck/memory_report_notify.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <securec.h>

static struct memory_report_info global_memory_report;

static struct kobject *memory_report_kobj;

static ssize_t memleak_report_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	if (global_memory_report.pid <= 0) {
		return 0;
	}
	return scnprintf(buf, PAGE_SIZE, "%u,%d,%s,%u,%u,%lu\n", global_memory_report.mem_type, global_memory_report.pid,
					 global_memory_report.pname, global_memory_report.mem_size, global_memory_report.mem_ratio,
					 global_memory_report.leak_duration);
}

static struct kobj_attribute memleak_report_attr = __ATTR_RO(memleak_report);

static struct attribute *memory_report_sysfs_attrs[] = {
	&memleak_report_attr.attr,
	NULL,
};

static const struct attribute_group memory_report_sysfs_attr_group = {
	.attrs = memory_report_sysfs_attrs,
};

static void memory_report_notify(struct work_struct *work)
{
	sysfs_notify(memory_report_kobj, NULL, "memleak_report");
}

static DECLARE_WORK(reporting_done, memory_report_notify);

static DEFINE_SPINLOCK(memory_report_lock);

void send_memory_report(const struct memory_report_info *leak_proc)
{
	if (leak_proc == NULL) {
		return;
	}
	spin_lock(&memory_report_lock);
	memcpy_s(&global_memory_report, sizeof(global_memory_report), leak_proc, sizeof(global_memory_report));
	spin_unlock(&memory_report_lock);
	pr_info("send_memory_report pid %u, name: %s, mem_size: %u\n", global_memory_report.pid,
			global_memory_report.pname, global_memory_report.mem_size);
	schedule_work(&reporting_done);
}
EXPORT_SYMBOL(send_memory_report);

/*
 * Set up report notification: create sysfs node
 * /sys/kernel/memory_report/.
 */
static int memory_report_notify_setup(void)
{
	int err = -1;

	memory_report_kobj = kobject_create_and_add("memory_report", kernel_kobj);
	if (unlikely(!memory_report_kobj)) {
		goto error;
	}
	err = sysfs_create_group(memory_report_kobj, &memory_report_sysfs_attr_group);
	if (unlikely(err)) {
		goto error;
	}
	return err;

error:
	if (unlikely(memory_report_kobj)) {
		kobject_del(memory_report_kobj);
	}
	return err;
}
late_initcall(memory_report_notify_setup);
