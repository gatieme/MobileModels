/*
 * kswapd_acct.c
 *
 * kswapd effciency accounting
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

#include <linux/kswapd_acct.h>

#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/moduleparam.h>
#include <linux/mm.h>
#include <linux/sched/clock.h>
#include <linux/sched/task.h>
#include <linux/slab.h>
#include <linux/vmstat.h>
#include <linux/types.h>
#include <platform/trace/hooks/memcheck.h>

const u64 ns_to_ms = 1000000;

struct kswapd_acct {
	u64 start[KSWAPD_NUMS];
	u64 delay[KSWAPD_NUMS];
	u64 scanned[KSWAPD_NUMS];
	u64 reclaimed[KSWAPD_NUMS];
	u64 nr_to_scanned[NR_LRU_LISTS];
	uintptr_t shrinker_ptr;
	u64 shrinker_delay_max;
	u64 shrinker_start;
	bool is_blocked;
} *g_kswapd_acct;
static DEFINE_SPINLOCK(g_kswapd_acct_lock);

struct total_kswapd_acct {
	u64 delay[DELAY_LEVEL_NUMS][KSWAPD_NUMS];
	u64 count[DELAY_LEVEL_NUMS][KSWAPD_NUMS];
	u64 scanned[DELAY_LEVEL_NUMS][KSWAPD_NUMS];
	u64 reclaimed[DELAY_LEVEL_NUMS][KSWAPD_NUMS];
	uintptr_t shrinker_ptr;
	u64 shrinker_delay_max;
} *g_total_kswapd_acct;
static DEFINE_SPINLOCK(g_total_kswapd_acct_lock);

static bool g_kswapdacct_is_off = true;
static int g_kswapdacct_disable = 1;
static int g_kswapdacct_delay_threshold = DEFAULT_DELAY_THRESHOLD;
static int g_kswapdacct_trace_enable = 0;

void kswapdacct_start(void)
{
	if (g_kswapdacct_disable || g_kswapdacct_is_off
			|| !g_kswapd_acct)
		return;

	kswapd_stage_start(KSWAPD_SHRINKNODE);
}

void kswapdacct_get_nr_to_scan(const unsigned long *nr)
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	enum lru_list lru;
	for_each_evictable_lru(lru) {
		g_kswapd_acct->nr_to_scanned[lru] += nr[lru];
	}
	return;
}

static void show_delay_info(void)
{
	u64 delay[KSWAPD_NUMS];
	int i;
	for (i = 0; i < KSWAPD_NUMS; i++)
		delay[i] = g_kswapd_acct->delay[i] / ns_to_ms;

	pr_err(
		"kswapdacct: Kswapd delay %s=%llums %s=%llums %s=%llums %s=%llums\n",
		KSWAPDNODE_STR, delay[KSWAPD_SHRINKNODE],
		SHRINKFILE_STR, delay[KSWAPD_SHRINKFILE],
		SHRINKANON_STR, delay[KSWAPD_SHRINKANON],
		SHRINKSLAB_STR, delay[KSWAPD_SHRINKSLAB]);

	pr_err(
		"kswapdacct: Kswapd nr_to_scan %s=%llu %s=%llu %s=%llu %s=%llu %s=%llu",
		LRU_INACTIVE_ANON_STR,
		g_kswapd_acct->nr_to_scanned[LRU_INACTIVE_ANON],
		LRU_ACTIVE_ANON_STR,
		g_kswapd_acct->nr_to_scanned[LRU_ACTIVE_ANON],
		LRU_INACTIVE_FILE_STR,
		g_kswapd_acct->nr_to_scanned[LRU_INACTIVE_FILE],
		LRU_ACTIVE_FILE_STR,
		g_kswapd_acct->nr_to_scanned[LRU_ACTIVE_FILE],
		LRU_UNEVICTABLE_STR,
		g_kswapd_acct->nr_to_scanned[LRU_UNEVICTABLE]
	);

	pr_err(
		"kswapdacct: Kswapd scanned %s=%llu %s=%llu %s=%llu %s=%llu\n",
		KSWAPDNODE_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKNODE],
		SHRINKFILE_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKFILE],
		SHRINKANON_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKANON],
		SHRINKSLAB_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKSLAB]);

	pr_err(
		"kswapdacct: Kswapd reclaimed %s=%llu %s=%llu %s=%llu %s=%llu\n",
		KSWAPDNODE_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKNODE],
		SHRINKFILE_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKFILE],
		SHRINKANON_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKANON],
		SHRINKSLAB_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKSLAB]);

	if (g_kswapd_acct->shrinker_ptr != NULL)
		pr_err("kswapdacct: Kswapd shrinker_ptr: %pS delay_max: %-15llu\n",
		((struct shrinker*)g_kswapd_acct->shrinker_ptr)->scan_objects,
		g_kswapd_acct->shrinker_delay_max);
}

static void print_trace_info(void)
{
	u64 delay[KSWAPD_NUMS];
	int i;
	for (i = 0; i < KSWAPD_NUMS; i++)
		delay[i] = g_kswapd_acct->delay[i] / ns_to_ms;

	trace_printk(
		"kswapdacct: Kswapd delay %s=%llums %s=%llums %s=%llums %s=%llums\n",
		KSWAPDNODE_STR, delay[KSWAPD_SHRINKNODE],
		SHRINKFILE_STR, delay[KSWAPD_SHRINKFILE],
		SHRINKANON_STR, delay[KSWAPD_SHRINKANON],
		SHRINKSLAB_STR, delay[KSWAPD_SHRINKSLAB]);

	trace_printk(
		"kswapdacct: Kswapd nr_to_scan %s=%llu %s=%llu %s=%llu %s=%llu %s=%llu",
		LRU_INACTIVE_ANON_STR,
		g_kswapd_acct->nr_to_scanned[LRU_INACTIVE_ANON],
		LRU_ACTIVE_ANON_STR,
		g_kswapd_acct->nr_to_scanned[LRU_ACTIVE_ANON],
		LRU_INACTIVE_FILE_STR,
		g_kswapd_acct->nr_to_scanned[LRU_INACTIVE_FILE],
		LRU_ACTIVE_FILE_STR,
		g_kswapd_acct->nr_to_scanned[LRU_ACTIVE_FILE],
		LRU_UNEVICTABLE_STR,
		g_kswapd_acct->nr_to_scanned[LRU_UNEVICTABLE]
	);

	trace_printk(
		"kswapdacct: Kswapd scanned %s=%llu %s=%llu %s=%llu %s=%llu\n",
		KSWAPDNODE_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKNODE],
		SHRINKFILE_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKFILE],
		SHRINKANON_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKANON],
		SHRINKSLAB_STR,
		g_kswapd_acct->scanned[KSWAPD_SHRINKSLAB]);

	trace_printk(
		"kswapdacct: Kswapd reclaimed %s=%llu %s=%llu %s=%llu %s=%llu\n",
		KSWAPDNODE_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKNODE],
		SHRINKFILE_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKFILE],
		SHRINKANON_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKANON],
		SHRINKSLAB_STR,
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKSLAB]);

	if (g_kswapd_acct->shrinker_ptr != NULL)
		trace_printk("kswapdacct: Kswapd shrinker_ptr: %pS delay_max: %-15llu\n",
			((struct shrinker*)g_kswapd_acct->shrinker_ptr)->scan_objects,
			g_kswapd_acct->shrinker_delay_max);
}

void kswapdacct_end(void)
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	kswapd_stage_end(KSWAPD_SHRINKNODE);
	spin_lock(&g_kswapd_acct_lock);
	int i;
	for (i = 1; i < KSWAPD_NUMS; ++i) {
		g_kswapd_acct->scanned[KSWAPD_SHRINKNODE] +=
				g_kswapd_acct->scanned[i];
		g_kswapd_acct->reclaimed[KSWAPD_SHRINKNODE] +=
				g_kswapd_acct->reclaimed[i];
	}

	if (g_kswapdacct_delay_threshold < 0) {
		pr_info("kswapdacct: kswapdacct_delay_threshold negative, reset with 300");
		g_kswapdacct_delay_threshold = DEFAULT_DELAY_THRESHOLD;
	}

	u64 delay_threshold = (u64)g_kswapdacct_delay_threshold * ns_to_ms;
	u64 block_threshold = BLOCK_DELAY_THRESHOLD * ns_to_ms;
	if (g_kswapd_acct->delay[KSWAPD_SHRINKNODE] > delay_threshold ||
			(g_kswapd_acct->is_blocked && g_kswapd_acct->delay[KSWAPD_SHRINKNODE] > block_threshold)) {
		show_delay_info();
		pr_info("kswapdacct: ------------------------------------------");
		show_mem(SHOW_MEM_FILTER_NODES, NULL);
	}

	if (g_kswapdacct_trace_enable)
		print_trace_info();

	spin_unlock(&g_kswapd_acct_lock);
	kswapdacct_collect_data();
	kswapdacct_clear_data();
}

void kswapdacct_clear_data()
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	spin_lock(&g_kswapd_acct_lock);

	g_kswapd_acct->shrinker_ptr = 0;
	g_kswapd_acct->shrinker_delay_max = 0;
	g_kswapd_acct->is_blocked = false;
	int i;
	for (i = 0; i < KSWAPD_NUMS; ++i) {
		g_kswapd_acct->delay[i] = 0;
		g_kswapd_acct->reclaimed[i] = 0;
		g_kswapd_acct->scanned[i] = 0;
	}
	enum lru_list lru;
	for_each_evictable_lru(lru) {
		g_kswapd_acct->nr_to_scanned[lru] = 0;
	}
	spin_unlock(&g_kswapd_acct_lock);
}

void kswapd_stage_start(int type)
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	g_kswapd_acct->start[type] = ktime_get_ns();
}

void kswapdacct_change_block_status()
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	g_kswapd_acct->is_blocked = true;
}

void kswapd_stage_end(int type)
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	u64 end = ktime_get_ns();
	u64 start = g_kswapd_acct->start[type];
	g_kswapd_acct->delay[type] += (end - start);
}

void kswapd_stage_count(int type, u64 reclaimed_delta, u64 scanned_delta)
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	g_kswapd_acct->reclaimed[type] += reclaimed_delta;
	g_kswapd_acct->scanned[type] += scanned_delta;
}

void kswapdacct_shrinker_start()
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	g_kswapd_acct->shrinker_start = ktime_get_ns();
}

void kswapdacct_shrinker_end(uintptr_t shrinker_ptr)
{
	if (g_kswapdacct_disable || !g_kswapd_acct)
		return;

	u64 end = ktime_get_ns();
	u64 start = g_kswapd_acct->shrinker_start;
	u64 shrinker_delay = (end - start);
	if (shrinker_delay > g_kswapd_acct->shrinker_delay_max) {
		g_kswapd_acct->shrinker_delay_max = shrinker_delay;
		g_kswapd_acct->shrinker_ptr = shrinker_ptr;
	}
}
void kswapdacct_collect_data(void)
{
	if (g_kswapdacct_disable || !g_kswapd_acct || !g_total_kswapd_acct)
		return;

	int i, j;
	const u64 delay[DELAY_LEVEL_NUMS] = {
		DELAY_LEVEL0, DELAY_LEVEL1, DELAY_LEVEL2, DELAY_LEVEL3, DELAY_LEVEL4, DELAY_LEVEL5
	};

	spin_lock(&g_total_kswapd_acct_lock);
	g_total_kswapd_acct->shrinker_ptr = g_kswapd_acct->shrinker_ptr;
	g_total_kswapd_acct->shrinker_delay_max = g_kswapd_acct->shrinker_delay_max;

	int delay_type = 0;
	for (j = DELAY_LEVEL_NUMS - 1; j >= 0; --j) {
		if (g_kswapd_acct->delay[KSWAPD_SHRINKNODE] >= delay[j]) {
			delay_type = j;
			break;
		}
	}
	for (i = 0; i < KSWAPD_NUMS; ++i) {
		g_total_kswapd_acct->delay[delay_type][i] += g_kswapd_acct->delay[i];
		g_total_kswapd_acct->count[delay_type][i] += 1;
		g_total_kswapd_acct->reclaimed[delay_type][i] += g_kswapd_acct->reclaimed[i];
		g_total_kswapd_acct->scanned[delay_type][i] += g_kswapd_acct->scanned[i];
	}
	spin_unlock(&g_total_kswapd_acct_lock);
	return;
}

u64 kswapdacct_get_data(int type, int level, int stub)
{
	u64 ret = 0;
	if (g_kswapdacct_is_off || !g_total_kswapd_acct)
		return 0;

	spin_lock(&g_total_kswapd_acct_lock);
	switch (type) {
	case KSWAPD_DELAY:
		ret = g_total_kswapd_acct->delay[level][stub];
		break;
	case KSWAPD_COUNT:
		ret = g_total_kswapd_acct->count[level][stub];
		break;
	case KSWAPD_SCANNED:
		if (level != -1) {
			ret = g_total_kswapd_acct->scanned[level][stub];
		} else {
			int i;
			for (i = 0; i < DELAY_LEVEL_NUMS; i++)
				ret += g_total_kswapd_acct->scanned[i][stub];
		}
		break;
	case KSWAPD_RECLAIMED:
		if (level != -1) {
			ret = g_total_kswapd_acct->reclaimed[level][stub];
		} else {
			int i;
			for (i = 0; i < DELAY_LEVEL_NUMS; i++)
				ret += g_total_kswapd_acct->reclaimed[i][stub];
		}
		break;
	case KSWAPD_SHRINKER:
		if (stub == 0) {
			ret = g_total_kswapd_acct->shrinker_ptr;
		} else {
			ret = g_total_kswapd_acct->shrinker_delay_max;
		}
		break;
	default: /* impossible */
		ret = 0;
		break;
	}
	spin_unlock(&g_total_kswapd_acct_lock);
	return ret;
}

/* kswapd account module initialize */
static int kswapdacct_init_handle(void *p)
{
	g_total_kswapd_acct = kzalloc(sizeof(struct total_kswapd_acct),
				     GFP_KERNEL);
	if (!g_total_kswapd_acct)
		goto alloc_show_failed;

	g_kswapd_acct = kzalloc(sizeof(struct kswapd_acct), GFP_KERNEL);
	if (!g_total_kswapd_acct)
		goto alloc_show_failed;

	g_kswapdacct_is_off = 0;
	pr_info("kswapdacct: enabled\n");
	return 0;
alloc_acct_failed:
	kfree(g_total_kswapd_acct);
	kfree(g_kswapd_acct);
	g_total_kswapd_acct = NULL;
	g_kswapd_acct = NULL;
alloc_show_failed:
kswapdacct_disabled:
	g_kswapdacct_is_off = 1;
	pr_err("kswapdacct: disabled\n");
	return 0;
}

static int __init kswapdacct_module_init(void)
{
	struct task_struct *task = NULL;

	task = kthread_run(kswapdacct_init_handle, NULL, "kswapdacct_init");
	if (IS_ERR(task))
		pr_err("kswapdacct: run kswapdacct_init failed\n");
	else
		pr_info("kswapdacct: run kswapdacct_init successfully\n");
	return 0;
}

late_initcall(kswapdacct_module_init);

module_param_named(kswapdacct_disable, g_kswapdacct_disable, int, 0644);
module_param_named(kswapdacct_delay_threshold, g_kswapdacct_delay_threshold, int, 0644);
module_param_named(kswapdacct_trace_enable, g_kswapdacct_trace_enable, int, 0644);