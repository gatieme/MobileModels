/*
 * log_usertype.c
 *
 * drivers to indicate user types in kernel
 *
 * Copyright (c) Honor Device Co., Ltd. 2018-2019. All rights reserved.
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

#include <log/log_usertype.h>

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/version.h>

/* log_usertype must be initialized to 0 to prevent version errors */
static unsigned int log_usertype = 0;

unsigned int get_log_usertype(void)
{
	return log_usertype;
}
EXPORT_SYMBOL(get_log_usertype);

static void set_log_usertype(int value)
{
	log_usertype = value;
}

static int log_usertype_info_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", log_usertype);
	return 0;
}

static int log_usertype_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, log_usertype_info_show, NULL);
}

static ssize_t log_usertype_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *data)
{
	char tmp;

	/* should be '0' to '9' with '\0' */
	if (count > 2)
		return -EINVAL;

	/* should be assigned only once */
	if (get_log_usertype() > 0)
		return -EINVAL;

	if (copy_from_user(&tmp, buffer, 1))
		return -EFAULT;

	if ((tmp >= '1') && (tmp <= '9'))
		set_log_usertype((unsigned int)(tmp - '0'));

	return count;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
static const struct proc_ops log_usertype_proc_fops = {
	.proc_open		= log_usertype_proc_open,
	.proc_read		= seq_read,
	.proc_write		= log_usertype_proc_write,
	.proc_lseek		= seq_lseek,
	.proc_release	= single_release,
};
#else
static const struct file_operations log_usertype_proc_fops = {
	.open			= log_usertype_proc_open,
	.read			= seq_read,
	.write			= log_usertype_proc_write,
	.llseek			= seq_lseek,
	.release		= single_release,
};
#endif

static struct proc_dir_entry *proc_usertype = NULL;

void log_usertype_proc_init(void)
{
	proc_usertype = proc_create("log-usertype", 0600, NULL, &log_usertype_proc_fops);
	if (proc_usertype == NULL) {
		pr_err("log_usertype_proc_init failed");
	}
}

void log_usertype_proc_exit(void)
{
	if (proc_usertype) {
		proc_remove(proc_usertype);
		proc_usertype = NULL;
	}
}
