/*
 * kswapdacct_show.c
 *
 * kswapd delay accounting data
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/version.h>
#include <linux/mmzone.h>
#include <linux/kswapd_acct.h>

const u64 ns2ms = 1000000;

const char *stub_name[KSWAPD_NUMS] = {
	KSWAPDNODE_STR,
	SHRINKFILE_STR,
	SHRINKANON_STR,
	SHRINKSLAB_STR
};

const char *type_name[KSWAPD_SHOW_NUMS] = {
	KSWAPD_DELAY_STR,
	KSWAPD_COUNT_STR,
	KSWAPD_RECLAIMED_STR,
	KSWAPD_SCANNED_STR
};

static void print_info_by_delay(struct seq_file *m, int type, int stub)
{
	int j;
	u64 result = 0;
	seq_printf(m, "%s_%s\t\t", stub_name[stub], type_name[type]);
	for (j = 0; j < DELAY_LEVEL_NUMS; j++) {
		result = kswapdacct_get_data(type, j, stub);
		if (type == KSWAPD_DELAY)
			result = result / ns2ms;
		seq_printf(m, "%-15llu ", result);
	}
	seq_puts(m, "\n");
}

static void print_info_shrinker(struct seq_file *m)
{
	uintptr_t shrinker_ptr = kswapdacct_get_data(KSWAPD_SHRINKSLAB, 0, 0);
	u64 shrinker_max_delay = kswapdacct_get_data(KSWAPD_SHRINKSLAB, 0, 1) / ns2ms;
	if (shrinker_ptr != NULL)
		seq_printf(m, "shrinker_ptr: %pS delay_max: %llums\n",
				shrinker_ptr, shrinker_max_delay);
}

static void print_info_total(struct seq_file *m, int type, int stub)
{
	seq_printf(m, "%s_%s\t\t", stub_name[stub], type_name[type]);
	u64 result = kswapdacct_get_data(type, -1, stub);
	seq_printf(m, "%-15llu ", result);
	seq_puts(m, "\n");
}

static int kswapdacct_proc_show(struct seq_file *m, void *v)
{
	int i, j;
	seq_puts(m, "watch_point(unit:ms/-)\t\t0-5ms\t\t5-10ms\t\t");
	seq_puts(m, "10-50ms\t\t50-100ms\t100-500ms\t>500ms\n");

	print_info_by_delay(m, KSWAPD_COUNT, KSWAPD_SHRINKNODE);

	for (i = 0; i < KSWAPD_NUMS; i++) {
		print_info_by_delay(m, KSWAPD_DELAY, i);

		if (i != KSWAPD_SHRINKSLAB)
			print_info_by_delay(m, KSWAPD_SCANNED, i);

		print_info_by_delay(m, KSWAPD_RECLAIMED, i);
	}
	print_info_shrinker(m);

	seq_puts(m, "----------------------------------------------------------\n");

	seq_puts(m, "watch_point(unit:page/-)\n");
	for (i = 0; i < KSWAPD_NUMS; i++) {
		if (i != KSWAPD_SHRINKSLAB)
			print_info_total(m, KSWAPD_SCANNED, i);

		print_info_total(m, KSWAPD_RECLAIMED, i);
	}
	return 0;
}

static int kswapdacct_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, kswapdacct_proc_show, NULL);
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
static const struct file_operations kswapdacct_proc_fops = {
	.open = kswapdacct_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#else
static const struct proc_ops kswapdacct_proc_fops = {
	.proc_open = kswapdacct_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#endif

static int __init proc_kswapdacct_init(void)
{
	proc_create("kswapdacct", 0440, NULL, &kswapdacct_proc_fops);
	return 0;
}

fs_initcall(proc_kswapdacct_init);

