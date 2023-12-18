/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 */

#ifndef _QCOM_SYSTEM_HEAP_H
#define _QCOM_SYSTEM_HEAP_H

#include <linux/dma-heap.h>
#include <linux/err.h>
#include "qcom_dynamic_page_pool.h"

#define USAGE_GFX_PREALLOC 1

struct qcom_system_heap {
	int uncached;
	struct dynamic_page_pool **pool_list;
	/* page pool pre-alloc */
	unsigned long usage;
	unsigned long pool_watermark;
	unsigned long prefill_low_percent;
	unsigned long prefill_high_percent;
	unsigned long alloc_warn_time_thresh;
	struct task_struct *pool_watermark_kthread;
	wait_queue_head_t pool_watermark_wait;
	atomic_t wait_flag;
	spinlock_t pool_watermark_lock;
};

struct qcom_system_heap_alloc_stats {
	atomic64_t alloc_total_times;
	atomic64_t alloc_from_pool_total_times;
	atomic64_t alloc_from_buddy_total_times;
	atomic64_t alloc_from_pool_and_buddy_total_times;
	atomic64_t stat_less_4ms;
	atomic64_t stat_4to6ms;
	atomic64_t stat_6to8ms;
	atomic64_t stat_8to11ms;
	atomic64_t stat_11to16ms;
	atomic64_t stat_greater_16ms;
};

#ifdef CONFIG_QCOM_DMABUF_HEAPS_SYSTEM
void qcom_system_heap_create(const char *name, const char *system_alias, bool uncached);
struct page *qcom_sys_heap_alloc_largest_available(struct dynamic_page_pool **pools,
						   unsigned long size,
						   unsigned int max_order,
						   bool *from_pool);
bool is_qcom_system_heap(void *dma_heap);
long qcom_system_pool_gt_wm_pages(void);
#else
bool is_qcom_system_heap(void *dma_heap)
{
	return false;
}

long qcom_system_pool_gt_wm_pages(void)
{
	return 0;
}

struct page *qcom_sys_heap_alloc_largest_available(struct dynamic_page_pool **pools,
						   unsigned long size,
						   unsigned int max_order,
						   bool *from_pool)
{
	return ERR_PTR(-EOPNOTSUPP);
}

static void qcom_system_heap_create(const char *name, const char *system_alias, bool uncached)
{

}
#endif

#endif /* _QCOM_SYSTEM_HEAP_H */
