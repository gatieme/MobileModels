#include <linux/cpufreq_times.h>
#include <linux/cpumask.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel_stat.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/sched/stat.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/time.h>
#include <linux/irqnr.h>
#include <linux/sched/cputime.h>
#include <linux/tick.h>
#include "securec.h"

#define DMIPS_NUM 16
#define MIN_CPUTIME_UID 1000
#define MIN_CPUTIME 2000
#define INIT_PID 1
#define KTHREADD_PID 2

int dmips_value_buffer[DMIPS_NUM];

static int show_perflogd(struct seq_file *p, void *v)
{
	unsigned long proc_id;
	unsigned long proc_cputime_total;
	struct task_struct *task;

	proc_cputime_total = 0;
	rcu_read_lock();
	task = &init_task;
	for_each_process(task) {
		if (task->tgid == INIT_PID || task->tgid == KTHREADD_PID)
			continue;
		if (task->real_parent && task->real_parent->tgid == KTHREADD_PID && !strstr(task->comm, "swapd"))
			continue;
		proc_cputime_total = get_proc_cpu_load(task, dmips_value_buffer, DMIPS_NUM);
		if (proc_cputime_total > 0) {
			proc_id = task->pid;
			seq_printf(p, "%lu ", proc_id);
			seq_printf(p, "%lu\n", proc_cputime_total);
		}
	}
	rcu_read_unlock();
	return 0;
}

static int perflogd_open(struct inode *inode, struct file *file)
{
	return single_open(file, show_perflogd, NULL);
}

static ssize_t perflogd_write(struct file *filp, const char __user *userbuf, size_t count, loff_t *ppos)
{
	int ret;
	ret = memset_s(dmips_value_buffer, sizeof(dmips_value_buffer), 0, sizeof(dmips_value_buffer));
	if (ret != 0) {
		printk(KERN_ERR "perflogd memset_s failed\n");
		return -EFAULT;
	}
	if ((count < 0) || (count > DMIPS_NUM)) {
		printk(KERN_ERR "perflogd invalid count\n");
		return -EFAULT;
	}

	char recv_buf[DMIPS_NUM] = {0};
	if (copy_from_user(recv_buf, userbuf, count)) {
		printk(KERN_ERR "perflogd copy_from_user failed\n");
		return -EFAULT;
	}

	for (int i =  0; i < DMIPS_NUM; i++) {
		dmips_value_buffer[i] = (int)(recv_buf[i]);
	}

	return 0;
}

static const struct proc_ops proc_perflogd_operations = {
	.proc_open		= perflogd_open,
	.proc_write		= perflogd_write,
	.proc_read		= seq_read,
	.proc_lseek		= seq_lseek,
	.proc_release	= single_release,
};

static int show_perflogd_cputime(struct seq_file *p, void *v)
{
	unsigned long proc_id;
	u64 clock_time;
	struct task_struct *task;
	u64 utime;
	u64 stime;
	u32 uid;

	rcu_read_lock();
	task = &init_task;
	for_each_process(task) {
		uid = task_uid(task).val;
		if (uid < MIN_CPUTIME_UID)
			continue;
		utime = 0;
		stime = 0;
		proc_id = task->pid;
		thread_group_cputime_adjusted(task, &utime, &stime);
		clock_time = nsec_to_clock_t(utime + stime);
		if (clock_time < MIN_CPUTIME)
			continue;
		seq_printf(p, "%lu ", proc_id);
		seq_printf(p, "%lu ", uid);
		seq_printf(p, "%llu\n", clock_time);
	}
	rcu_read_unlock();
	return 0;
}

static int perflogd_cputime_open(struct inode *inode, struct file *file)
{
	return single_open(file, show_perflogd_cputime, NULL);
}

static const struct proc_ops proc_perflogd_cputime_operations = {
	.proc_open		= perflogd_cputime_open,
	.proc_read		= seq_read,
	.proc_lseek		= seq_lseek,
	.proc_release	= single_release,
};

static int __init proc_perflogd_init(void)
{
	proc_create("perflogd", 0446, NULL, &proc_perflogd_operations);
	proc_create("perflogd_cputime", 0446, NULL, &proc_perflogd_cputime_operations);
	return 0;
}
module_init(proc_perflogd_init);

