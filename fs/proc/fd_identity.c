// SPDX-License-Identifier: GPL-2.0
#include <linux/sched/signal.h>
#include <linux/errno.h>
#include <linux/dcache.h>
#include <linux/path.h>
#include <linux/fdtable.h>
#include <linux/namei.h>
#include <linux/pid.h>
#include <linux/security.h>
#include <linux/file.h>
#include <linux/seq_file.h>
#include <linux/fs.h>

#include <linux/proc_fs.h>

#include "../mount.h"
#include "internal.h"
#include "fd.h"


static int dump_fd(const void *data, struct file *file, unsigned int fd) {
	struct seq_file *m = (struct seq_file *)data;

	seq_printf(m, "%zd %x\n", fd, file);
	return 0;
}

static int seq_show(struct seq_file *m, void *v)
{
	int ret = -ENOENT;
	struct task_struct *task;

	task = get_proc_task(m->private);
	if (!task) {
		return -ENOENT;
	}

	task_lock(task);
	ret = iterate_fd(task->files, 0, dump_fd, m);
	task_unlock(task);
	put_task_struct(task);

	return ret;
}

static int seq_fdidentity_open(struct inode *inode, struct file *file)
{
	return single_open(file, seq_show, inode);
}

const struct file_operations proc_fdidentity_file_operations = {
	.open           = seq_fdidentity_open,
	.read           = seq_read,
	.llseek         = seq_lseek,
	.release        = single_release,
};
