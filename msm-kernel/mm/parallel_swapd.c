/*
 * parallel_swapd.c
 *
 * Copyright (C) Huawei Technologies Co., Ltd. 2022. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/cpumask.h>
#include <linux/module.h>
#include <linux/parallel_swapd.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/version.h>
#include <linux/workqueue.h>

#include <asm/arch_timer.h>
#include <asm/uaccess.h>

static int parad_enable;

int get_parad_enable(void)
{
	return parad_enable;
}

u64 parad_get_counter(void)
{
	return arch_timer_read_counter();
}

static u64 zswapd_cnt;
static u64 zswapd_work[NR_CPUS];
static u64 zswapd_nr_scanned;
static u64 zswapd_nr_reclaimed;
static atomic_t zswapd_wakeup = ATOMIC_INIT(0);
static atomic_t zswapd_realwake = ATOMIC_INIT(0);
static atomic_t zswapd_suitable = ATOMIC_INIT(0);
static atomic_t zswapd_interval = ATOMIC_INIT(0);
static atomic_t zswapd_refault = ATOMIC_INIT(0);
static atomic_t zswapd_shrink_anon = ATOMIC_INIT(0);

void parad_stat_add(enum parad_state state, u64 counter)
{
	switch (state) {
	case PARAD_ZSWAPD:
		zswapd_cnt += counter;
		break;
	case PARAD_ZSWAPD_WORK:
		zswapd_work[smp_processor_id()] += counter;
		break;
	case PARAD_ZSWAPD_NR_SCANNED:
		zswapd_nr_scanned += counter;
		break;
	case PARAD_ZSWAPD_NR_RECLAIMED:
		zswapd_nr_reclaimed += counter;
		break;
	case PARAD_ZSWAPD_WAKEUP:
		atomic_add(counter, &zswapd_wakeup);
		break;
	case PARAD_ZSWAPD_REALWAKE:
		atomic_add(counter, &zswapd_realwake);
		break;
	case PARAD_ZSWAPD_SUITABLE:
		atomic_add(counter, &zswapd_suitable);
		break;
	case PARAD_ZSWAPD_INTERVAL:
		atomic_add(counter, &zswapd_interval);
		break;
	case PARAD_ZSWAPD_REFAULT:
		atomic_add(counter, &zswapd_refault);
		break;
	case PARAD_ZSWAPD_SHRINK_ANON:
		atomic_add(counter, &zswapd_shrink_anon);
		break;
	}
}

static int stat_show(struct seq_file *seq, void *v)
{
	int cpu;

	seq_printf(seq, "zswapd:\t\t %16ld\n", zswapd_cnt);
	seq_printf(seq, "nr_scanned:\t %16ld\n", zswapd_nr_scanned);
	seq_printf(seq, "nr_reclaimed:\t %16ld\n", zswapd_nr_reclaimed);
	for_each_online_cpu(cpu) {
		seq_printf(seq, "cpu[%d]:\t\t %16ld\n", cpu,
			   zswapd_work[cpu]);
	}
	seq_printf(seq, "zswapd_wakeup:\t %16ld\n",
		   atomic_read(&zswapd_wakeup));
	seq_printf(seq, "zswapd_realwake:\t %16ld\n",
		   atomic_read(&zswapd_realwake));
	seq_printf(seq, "zswapd_suitable:\t %16ld\n",
		   atomic_read(&zswapd_suitable));
	seq_printf(seq, "zswapd_interval:\t %16ld\n",
		   atomic_read(&zswapd_interval));
	seq_printf(seq, "zswapd_refault:\t %16ld\n",
		   atomic_read(&zswapd_refault));
	seq_printf(seq, "zswapd_shrink_anon:\t %16ld\n",
		   atomic_read(&zswapd_shrink_anon));

	return 0;
}

static ssize_t stat_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	int cpu;

	zswapd_cnt = 0;
	zswapd_nr_scanned = 0;
	zswapd_nr_reclaimed = 0;

	for_each_online_cpu(cpu)
		zswapd_work[cpu] = 0;
	atomic_set(&zswapd_wakeup, 0);
	atomic_set(&zswapd_realwake, 0);
	atomic_set(&zswapd_suitable, 0);
	atomic_set(&zswapd_interval, 0);
	atomic_set(&zswapd_refault, 0);
	atomic_set(&zswapd_shrink_anon, 0);

	return count;
}

static int stat_open(struct inode *inode, struct file *filp)
{
	return single_open(filp, stat_show, NULL);
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
static const struct file_operations stat_ops = {
	.open = stat_open,
	.read = seq_read,
	.write = stat_write,
};
#else
static const struct proc_ops stat_ops = {
	.proc_open = stat_open,
	.proc_read = seq_read,
	.proc_write = stat_write,
};
#endif

static int enable_show(struct seq_file *seq, void *v)
{
	seq_printf(seq, "parad enabled: %d\n", parad_enable);
	return 0;
}

static ssize_t enable_write(struct file *file, const char __user *buffer,
			    size_t count, loff_t *pos)
{
	char enable;

	if (count > 0) {
		if (get_user(enable, buffer))
			return -EFAULT;

		if (enable == '0')
			parad_enable = 0;
		else if (enable == '1')
			parad_enable = 1;
		else
			return -EINVAL;
	}

	return count;
}

static int enable_open(struct inode *inode, struct file *filp)
{
	return single_open(filp, enable_show, NULL);
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
static const struct file_operations enable_ops = {
	.open = enable_open,
	.read = seq_read,
	.write = enable_write,
};
#else
static const struct proc_ops enable_ops = {
	.proc_open = enable_open,
	.proc_read = seq_read,
	.proc_write = enable_write,
};
#endif

static int parad_proc_create(void)
{
	static struct proc_dir_entry *root;

	root = proc_mkdir("parad", NULL);

	proc_create("enable", 0660, root, &enable_ops);
	proc_create("stat", 0440, root, &stat_ops);

	return 0;
}

struct workqueue_struct *mm_parad_wq;

static int mm_parad_init(void)
{
	int i, unmask[] = { 0, 7 };
	struct workqueue_attrs *attrs;

	attrs = alloc_workqueue_attrs();
	if (!attrs)
		return -EFAULT;

	for (i = 0; i < ARRAY_SIZE(unmask); i++)
		cpumask_clear_cpu(unmask[i], attrs->cpumask);
	attrs->nice = 15;
	attrs->no_numa = true;

	mm_parad_wq = alloc_workqueue(
		"mm_parad", WQ_MEM_RECLAIM | WQ_UNBOUND | WQ_FREEZABLE, 6);
	apply_workqueue_attrs(mm_parad_wq, attrs);

	parad_proc_create();

	return 0;
}
module_init(mm_parad_init);
