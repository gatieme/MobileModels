/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager system status
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for system status API
 *
 */
#ifndef _SCM_SYS_STATUS_H_
#define _SCM_SYS_STATUS_H_

#include <linux/swap.h>
#include <linux/vmstat.h>
#include <../../kernel/sched/sched.h>

static inline unsigned long _scm_stat_get_free_pages(void)
{
	return global_zone_page_state(NR_FREE_PAGES);
}

static inline unsigned long _scm_stat_get_file_pages(void)
{
	return global_node_page_state(NR_LRU_BASE + NR_INACTIVE_FILE) +
	       global_node_page_state(NR_LRU_BASE + NR_ACTIVE_FILE);
}

static inline unsigned long _scm_stat_get_anon_pages(void)
{
	return global_node_page_state(NR_LRU_BASE + NR_INACTIVE_ANON) +
	       global_node_page_state(NR_LRU_BASE + NR_ACTIVE_ANON);
}

static inline unsigned long _scm_stat_get_swap_free_pages(void)
{
	return atomic_long_read(&nr_swap_pages); // not exactly, for quick.
}

static inline _scm_stat_get_nr_running(void)
{
	int i;
	int _nr_running = 0;
	for_each_online_cpu(i) {
		_nr_running += cpu_rq(i)->nr_running;
	}
	return _nr_running;
}

#define _SCM_TASK_RUNNING_COUNT_LIMIT 24
static inline bool _scm_stat_cpu_busy(void)
{
	int _nr_running = _scm_stat_get_nr_running();
	return _nr_running > _SCM_TASK_RUNNING_COUNT_LIMIT;
}

#endif //_SCM_SYS_STATUS_H_