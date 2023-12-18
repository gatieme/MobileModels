// SPDX-License-Identifier: GPL-2.0
/*
 * DMABUF System heap exporter
 * Originally copied from: drivers/dma-buf/heaps/system_heap.c as of commit
 * 263e38f82cbb ("dma-buf: heaps: Remove redundant heap identifier from system
 * heap name")
 *
 * Additions taken from modifications to drivers/dma-buf/heaps/system-heap.c,
 * from patches submitted, are listed below:
 *
 * Addition that modifies dma_buf ops to use SG tables taken from
 * drivers/dma-buf/heaps/system-heap.c in:
 * https://lore.kernel.org/lkml/20201017013255.43568-2-john.stultz@linaro.org/
 *
 * Addition that skips unneeded syncs in the dma_buf ops taken from
 * https://lore.kernel.org/lkml/20201017013255.43568-5-john.stultz@linaro.org/
 *
 * Addition that tries to allocate higher order pages taken from
 * https://lore.kernel.org/lkml/20201017013255.43568-6-john.stultz@linaro.org/
 *
 * Addition that implements an uncached heap taken from
 * https://lore.kernel.org/lkml/20201017013255.43568-8-john.stultz@linaro.org/,
 * with our own modificaitons made to account for core kernel changes that are
 * a part of the patch series.
 *
 * Pooling functionality taken from:
 * Git-repo: https://git.linaro.org/people/john.stultz/android-dev.git
 * Branch: dma-buf-heap-perf
 * Git-commit: 6f080eb67dce63c6efa57ef564ca4cd762ccebb0
 * Git-commit: 6fb9593b928c4cb485bef4e88c59c6b9fdf11352
 *
 * Deferred free functionality taken from drivers/dma-buf/heaps/system-heap.c
 * from commit f10ff61bd1ef ("Merge "dt-bindings: ipcc: Add WPSS client to
 * IPCC header"")
 *
 * Copyright (C) 2011 Google, Inc.
 * Copyright (C) 2019, 2020 Linaro Ltd.
 *
 * Portions based off of Andrew Davis' SRAM heap:
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *	Andrew F. Davis <afd@ti.com>
 *
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 */

#include <linux/dma-buf.h>
#include <linux/dma-mapping.h>
#include <linux/dma-heap.h>
#include <linux/err.h>
#include <linux/highmem.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/scatterlist.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/kthread.h>
#include <linux/qcom_dma_heap.h>
#include <linux/ktime.h>
#include <linux/sched/cputime.h>
#include <uapi/linux/sched/types.h>

#include "qcom_dma_heap_secure_utils.h"
#include "qcom_dynamic_page_pool.h"
#include "qcom_sg_ops.h"
#include "qcom_system_heap.h"

#define DEFAULT_PREFILL_LOW_PERCENT 40UL
#define DEFAULT_PREFILL_HIGH_PERCENT 100UL
#define DEFAULT_ALLOC_WARN_TIME_THRESH 6000
#define POOL_ALLOC_BATCH 128
#define MAX_POOL_PREFILL_PERCENT 500
#define QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_4MS 4000
#define QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_6MS 6000
#define QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_8MS 8000
#define QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_11MS 11000
#define QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_16MS 16000
#define QCOM_SYSTEM_HEAP_ALLOC_PAGE_THRESH 32

#define DYNAMIC_POOL_FILL_MARK (100 * SZ_1M)
#define DYNAMIC_POOL_LOW_MARK_PERCENT 40UL
#define DYNAMIC_POOL_LOW_MARK ((DYNAMIC_POOL_FILL_MARK * DYNAMIC_POOL_LOW_MARK_PERCENT) / 100)

#define DYNAMIC_POOL_REFILL_DEFER_WINDOW_MS 10
#define DYNAMIC_POOL_KTHREAD_NICE_VAL 10

#define MAX_POOL_WATER_MARK (236 * SZ_1M) /* 236MB */

static struct qcom_system_heap *inner_qcom_sys_heap = NULL;

static struct qcom_system_heap_alloc_stats heap_alloc_stats;

static void get_global_mem_wmarks(unsigned long *low, unsigned long *min, unsigned long *num_free);

static void qcom_system_heap_alloc_stat(struct qcom_system_heap_alloc_stats *stats,
					unsigned long long alloc_time,
					unsigned long from_pool_pages,
					unsigned long from_buddy_pages)
{
	atomic64_inc(&stats->alloc_total_times);
	if (alloc_time >= QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_16MS)
		atomic64_inc(&stats->stat_greater_16ms);
	else if (alloc_time >= QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_11MS)
		atomic64_inc(&stats->stat_11to16ms);
	else if (alloc_time >= QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_8MS)
		atomic64_inc(&stats->stat_8to11ms);
	else if (alloc_time >= QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_6MS)
		atomic64_inc(&stats->stat_6to8ms);
	else if (alloc_time >= QCOM_SYSTEM_HEAP_ALLOC_TIME_THRESH_4MS)
		atomic64_inc(&stats->stat_4to6ms);
	else
		atomic64_inc(&stats->stat_less_4ms);
	if (from_buddy_pages <= QCOM_SYSTEM_HEAP_ALLOC_PAGE_THRESH)
		atomic64_inc(&stats->alloc_from_pool_total_times);
	else if (from_pool_pages <= QCOM_SYSTEM_HEAP_ALLOC_PAGE_THRESH)
		atomic64_inc(&stats->alloc_from_buddy_total_times);
	else
		atomic64_inc(&stats->alloc_from_pool_and_buddy_total_times);
}
static int get_dynamic_pool_fillmark(struct dynamic_page_pool *pool)
{
	return DYNAMIC_POOL_FILL_MARK / (PAGE_SIZE << pool->order);
}

static bool dynamic_pool_fillmark_reached(struct dynamic_page_pool *pool)
{
	return atomic_read(&pool->count) >= get_dynamic_pool_fillmark(pool);
}

static int get_dynamic_pool_lowmark(struct dynamic_page_pool *pool)
{
	return DYNAMIC_POOL_LOW_MARK / (PAGE_SIZE << pool->order);
}

static bool dynamic_pool_count_below_lowmark(struct dynamic_page_pool *pool)
{
	return atomic_read(&pool->count) < get_dynamic_pool_lowmark(pool);
}

/* do a simple check to see if we are in any low memory situation */
static bool dynamic_pool_refill_ok(struct dynamic_page_pool *pool)
{
	struct zonelist *zonelist;
	struct zoneref *z;
	struct zone *zone;
	int mark;
	enum zone_type classzone_idx = gfp_zone(pool->gfp_mask);
	s64 delta;

	/* check if we are within the refill defer window */
	delta = ktime_ms_delta(ktime_get(), pool->last_low_watermark_ktime);
	if (delta < DYNAMIC_POOL_REFILL_DEFER_WINDOW_MS)
		return false;

	zonelist = node_zonelist(numa_node_id(), pool->gfp_mask);
	/*
	 * make sure that if we allocate a pool->order page from buddy,
	 * we don't put the zone watermarks go below the high threshold.
	 * This makes sure there's no unwanted repetitive refilling and
	 * reclaiming of buddy pages on the pool.
	 */
	for_each_zone_zonelist(zone, z, zonelist, classzone_idx) {
		if (!strcmp(zone->name, "DMA32"))
			continue;

		mark = high_wmark_pages(zone);
		mark += 1 << pool->order;
		if (!zone_watermark_ok_safe(zone, pool->order, mark,
					    classzone_idx)) {
			pool->last_low_watermark_ktime = ktime_get();
			return false;
		}
	}

	return true;
}

static void dynamic_page_pool_refill(struct dynamic_page_pool *pool)
{
	struct page *page;
	gfp_t gfp_refill = (pool->gfp_mask | __GFP_RECLAIM) & ~__GFP_NORETRY;

	/* skip refilling order 0 pools */
	if (!pool->order)
		return;

	while (!dynamic_pool_fillmark_reached(pool) && dynamic_pool_refill_ok(pool)) {
		page = alloc_pages(gfp_refill, pool->order);
		if (!page)
			break;

		dynamic_page_pool_add(pool, page);
	}
}

static int system_heap_clear_pages(struct page **pages, int num, pgprot_t pgprot)
{
	void *addr = vmap(pages, num, VM_MAP, pgprot);

	if (!addr)
		return -ENOMEM;
	memset(addr, 0, PAGE_SIZE * num);
	vunmap(addr);
	return 0;
}

static int system_heap_zero_buffer(struct qcom_sg_buffer *buffer)
{
	struct sg_table *sgt = &buffer->sg_table;
	struct sg_page_iter piter;
	struct page *pages[32];
	int p = 0;
	int ret = 0;

	for_each_sgtable_page(sgt, &piter, 0) {
		pages[p++] = sg_page_iter_page(&piter);
		if (p == ARRAY_SIZE(pages)) {
			ret = system_heap_clear_pages(pages, p, PAGE_KERNEL);
			if (ret)
				return ret;
			p = 0;
		}
	}
	if (p)
		ret = system_heap_clear_pages(pages, p, PAGE_KERNEL);

	return ret;
}

static inline int order_to_index(unsigned int order)
{
	int i;

	for (i = 0; i < NUM_ORDERS; i++)
		if (order == orders[i])
			return i;
	return NUM_ORDERS - 1;
}

static void system_heap_buf_free(struct deferred_freelist_item *item,
				 enum df_reason reason)
{
	struct qcom_system_heap *sys_heap;
	struct qcom_sg_buffer *buffer;
	struct sg_table *table;
	struct scatterlist *sg;
	int i, j;

	buffer = container_of(item, struct qcom_sg_buffer, deferred_free);
	sys_heap = dma_heap_get_drvdata(buffer->heap);
	/* Zero the buffer pages before adding back to the pool */
	if (reason == DF_NORMAL)
		if (system_heap_zero_buffer(buffer))
			reason = DF_UNDER_PRESSURE; // On failure, just free

	table = &buffer->sg_table;
	for_each_sg(table->sgl, sg, table->nents, i) {
		struct page *page = sg_page(sg);

		if (reason == DF_UNDER_PRESSURE) {
			__free_pages(page, compound_order(page));
		} else {
			for (j = 0; j < NUM_ORDERS; j++) {
				if (compound_order(page) == orders[j])
					break;
			}
			dynamic_page_pool_free(sys_heap->pool_list[j], page);
		}
	}
	sg_free_table(table);
	kfree(buffer);
}

static void system_heap_free(struct qcom_sg_buffer *buffer)
{
	deferred_free(&buffer->deferred_free, system_heap_buf_free,
		      PAGE_ALIGN(buffer->len) / PAGE_SIZE);
}

struct page *qcom_sys_heap_alloc_largest_available(struct dynamic_page_pool **pools,
						   unsigned long size,
						   unsigned int max_order,
						   bool *from_pool)
{
	struct page *page = NULL;
	int i;
	*from_pool = false;
	for (i = 0; i < NUM_ORDERS; i++) {
		unsigned long flags;

		if (size <  (PAGE_SIZE << orders[i]))
			continue;
		if (max_order < orders[i])
			continue;
		if (pools[i]->high_count + pools[i]->low_count > 0) {
			spin_lock_irqsave(&pools[i]->lock, flags);
			if (pools[i]->high_count)
				page = dynamic_page_pool_remove(pools[i], true);
			else if (pools[i]->low_count)
				page = dynamic_page_pool_remove(pools[i],
								false);
			spin_unlock_irqrestore(&pools[i]->lock, flags);
		}
		if (!page)
			page = alloc_pages(pools[i]->gfp_mask, pools[i]->order);
		else
			*from_pool = true;
		if (!page)
			continue;

		if (IS_ENABLED(CONFIG_QCOM_DMABUF_HEAPS_PAGE_POOL_REFILL) &&
		    pools[i]->order &&
		    dynamic_pool_count_below_lowmark(pools[i]))
			wake_up_process(pools[i]->refill_worker);

		return page;
	}
	return NULL;
}

static struct dma_buf *system_heap_allocate(struct dma_heap *heap,
					       unsigned long len,
					       unsigned long fd_flags,
					       unsigned long heap_flags)
{
	struct qcom_system_heap *sys_heap;
	struct qcom_sg_buffer *buffer;
	DEFINE_DMA_BUF_EXPORT_INFO(exp_info);
	unsigned long size_remaining = len;
	unsigned int max_order = orders[0];
	struct dma_buf *dmabuf;
	struct sg_table *table;
	struct scatterlist *sg;
	struct list_head pages;
	struct page *page, *tmp_page;
	int i, ret = -ENOMEM;
	bool from_pool = false;
	unsigned long from_pool_pages[NUM_ORDERS] = {0, 0, 0};
	unsigned long from_buddy_pages[NUM_ORDERS] = {0, 0, 0};
	unsigned long long time;
	unsigned long long run_time;
	unsigned long long run_delay = 0;
	unsigned long free_pages = 0;
	unsigned long num_pages;
	int batch_count;

	get_global_mem_wmarks(NULL, NULL, &free_pages);
	time = ktime_get();
	run_time = task_sched_runtime(current);
#ifdef CONFIG_SCHED_INFO
	run_delay = current->sched_info.run_delay;
#endif
	buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
	if (!buffer)
		return ERR_PTR(-ENOMEM);

	sys_heap = dma_heap_get_drvdata(heap);

	INIT_LIST_HEAD(&buffer->attachments);
	mutex_init(&buffer->lock);
	buffer->heap = heap;
	buffer->len = len;
	buffer->uncached = sys_heap->uncached;
	buffer->free = system_heap_free;

	INIT_LIST_HEAD(&pages);
	i = 0;
	while (size_remaining > 0) {
		/*
		 * Avoid trying to allocate memory if the process
		 * has been killed by SIGKILL
		 */
		if (fatal_signal_pending(current))
			goto free_buffer;
		if (max_order == 0) {
			batch_count = PAGE_ALIGN(size_remaining) / PAGE_SIZE;
			batch_count = batch_count < POOL_ALLOC_BATCH ?
						    batch_count : POOL_ALLOC_BATCH;
			batch_count = dynamic_page_pool_remove_batch(
				sys_heap->pool_list[NUM_ORDERS - 1], &pages,
				batch_count);
			if (batch_count > 0) {
				size_remaining -= batch_count * PAGE_SIZE;
				from_pool_pages[NUM_ORDERS - 1] += batch_count;
				i += batch_count;
				continue;
			}
		}

		page = qcom_sys_heap_alloc_largest_available(sys_heap->pool_list,
						     size_remaining,
						     max_order,
						     &from_pool);
		if (!page)
			goto free_buffer;

		list_add_tail(&page->lru, &pages);
		size_remaining -= page_size(page);
		max_order = compound_order(page);
		if (from_pool)
			from_pool_pages[order_to_index(max_order)] += 1 << max_order;
		else
			from_buddy_pages[order_to_index(max_order)] += 1 << max_order;

		i++;
	}

	table = &buffer->sg_table;
	if (sg_alloc_table(table, i, GFP_KERNEL))
		goto free_buffer;

	sg = table->sgl;
	list_for_each_entry_safe(page, tmp_page, &pages, lru) {
		sg_set_page(sg, page, page_size(page), 0);
		sg = sg_next(sg);
		list_del(&page->lru);
	}

	/*
	 * For uncached buffers, we need to initially flush cpu cache, since
	 * the __GFP_ZERO on the allocation means the zeroing was done by the
	 * cpu and thus it is likely cached. Map (and implicitly flush) and
	 * unmap it now so we don't get corruption later on.
	 */
	if (buffer->uncached) {
		dma_map_sgtable(dma_heap_get_dev(heap), table, DMA_BIDIRECTIONAL, 0);
		dma_unmap_sgtable(dma_heap_get_dev(heap), table, DMA_BIDIRECTIONAL, 0);
	}

	buffer->vmperm = mem_buf_vmperm_alloc(table);

	if (IS_ERR(buffer->vmperm)) {
		ret = PTR_ERR(buffer->vmperm);
		goto free_sg;
	}

	/* create the dmabuf */
	exp_info.exp_name = dma_heap_get_name(heap);
	exp_info.size = buffer->len;
	exp_info.flags = fd_flags;
	exp_info.priv = buffer;
	dmabuf = mem_buf_dma_buf_export(&exp_info, &qcom_sg_buf_ops);
	if (IS_ERR(dmabuf)) {
		ret = PTR_ERR(dmabuf);
		goto vmperm_release;
	}
	time = ktime_us_delta(ktime_get(), time);
	run_time = ktime_us_delta(task_sched_runtime(current), run_time);
#ifdef CONFIG_SCHED_INFO
	run_delay = ktime_us_delta(current->sched_info.run_delay, run_delay);
#endif
	if (run_time >= sys_heap->alloc_warn_time_thresh)
		pr_warn("%s: alloc_size %zu time_cost %lld run_time %llu delay %llu from_pool_pages [%lu %lu %lu] "
			"from_buddy_pages [%lu %lu %lu] free-pages %lu pool_watermark %lu",
			__func__, len, time, run_time, run_delay, from_pool_pages[0], from_pool_pages[1],
			from_pool_pages[2], from_buddy_pages[0], from_buddy_pages[1], from_buddy_pages[2],
			free_pages, sys_heap->pool_watermark);
	qcom_system_heap_alloc_stat(&heap_alloc_stats, run_time,
				    from_pool_pages[0] + from_pool_pages[1] + from_pool_pages[2],
				    from_buddy_pages[0] + from_buddy_pages[1] + from_buddy_pages[2]);
	smp_rmb();
	if (sys_heap->usage == USAGE_GFX_PREALLOC) {
		num_pages = PAGE_ALIGN(len) / PAGE_SIZE;
		spin_lock(&sys_heap->pool_watermark_lock);
		if (sys_heap->pool_watermark > num_pages)
			sys_heap->pool_watermark -= num_pages;
		else
			sys_heap->pool_watermark = 0;

		spin_unlock(&sys_heap->pool_watermark_lock);
	}
	return dmabuf;

vmperm_release:
	mem_buf_vmperm_release(buffer->vmperm);
free_sg:
	sg_free_table(table);
free_buffer:
	list_for_each_entry_safe(page, tmp_page, &pages, lru)
		__free_pages(page, compound_order(page));
	kfree(buffer);

	return ERR_PTR(ret);
}

static int system_heap_refill_worker(void *data)
{
	struct dynamic_page_pool **pool_list = data;
	int i;

	for (;;) {
		for (i = 0; i < NUM_ORDERS; i++) {
			if (dynamic_pool_count_below_lowmark(pool_list[i]))
				dynamic_page_pool_refill(pool_list[i]);
		}

		set_current_state(TASK_INTERRUPTIBLE);
		if (unlikely(kthread_should_stop())) {
			set_current_state(TASK_RUNNING);
			break;
		}
		schedule();

		set_current_state(TASK_RUNNING);
	}

	return 0;
}

static long get_pool_size_bytes(struct dma_heap *heap)
{
	long total_size = 0;
	int i;
	struct qcom_system_heap *sys_heap = dma_heap_get_drvdata(heap);

	for (i = 0; i < NUM_ORDERS; i++)
		total_size += dynamic_page_pool_total(sys_heap->pool_list[i], true);

	return total_size << PAGE_SHIFT;
}

static const struct dma_heap_ops system_heap_ops = {
	.allocate = system_heap_allocate,
	.get_pool_size = get_pool_size_bytes,
};

static void pool_watermark_wakeup(void)
{
	struct qcom_system_heap *sys_heap = inner_qcom_sys_heap;
	if (!sys_heap)
		return;
	atomic_set(&sys_heap->wait_flag, 1);
	wake_up_interruptible(&sys_heap->pool_watermark_wait);
}

static int fill_pool_once(struct dynamic_page_pool *pool)
{
	struct page *page = NULL;

	page = alloc_pages(pool->gfp_mask, pool->order);
	if (!page)
		return -ENOMEM;

	dynamic_page_pool_free(pool, page);

	return 0;
}

static void fill_pool_watermark(struct dynamic_page_pool **pools,
				unsigned long watermark_nr_pages)
{
	unsigned int i = 0;
	unsigned long count = 0;

	for (i = 0; i < NUM_ORDERS; i++) {
		while (watermark_nr_pages) {
			if (fill_pool_once(pools[i]))
				break;

			count = 1UL << pools[i]->order;
			if (watermark_nr_pages >= count)
				watermark_nr_pages -= count;
			else
				watermark_nr_pages = 0;
		}
	}
}

static long qcom_system_heap_pool_pages(struct qcom_system_heap *heap)
{
	long nr_pool_total = 0;
	int i = 0;

	if (!heap)
		return 0;

	for (i = 0; i < NUM_ORDERS; i++)
		nr_pool_total += dynamic_page_pool_total(heap->pool_list[i], true);

	return nr_pool_total;
}

static int pool_watermark_kthread(void *p)
{
	struct qcom_system_heap *heap = (struct qcom_system_heap *)p;
	int ret = 0;
	long nr_fill_pages = 0;

	if (!heap)
		return -EINVAL;

	while (!kthread_should_stop()) {
		ret = wait_event_interruptible(heap->pool_watermark_wait,
						atomic_read(&heap->wait_flag));
		if (ret)
			continue;

		atomic_set(&heap->wait_flag, 0);
		if (heap->pool_watermark <= LONG_MAX)
			nr_fill_pages = (long)heap->pool_watermark -
					qcom_system_heap_pool_pages(heap);
		if (nr_fill_pages <= 0)
			continue;
		pr_info("dma_heap %s run, fill %ld while watermark %lu pages",
			__func__, nr_fill_pages, heap->pool_watermark);

		fill_pool_watermark(heap->pool_list, nr_fill_pages);

		pr_info("dma_heap %s finish, pool %ld while watermark %lu pages",
			__func__, qcom_system_heap_pool_pages(heap), heap->pool_watermark);
	}

	return 0;
}

static bool pool_watermark_check(struct qcom_system_heap *heap,
				 unsigned long nr_watermark)
{
	unsigned long nr_pool_count = 0;

	if (!nr_watermark)
		return false;

	nr_pool_count = (unsigned long)qcom_system_heap_pool_pages(heap);
	if (nr_pool_count >= nr_watermark)
		return false;

	return true;
}

void set_system_pool_watermark(unsigned long watermark)
{
	unsigned long nr_watermark = watermark / PAGE_SIZE;
	bool pool_wakeup = true;
	struct qcom_system_heap *heap = inner_qcom_sys_heap;

	if (!heap || !wq_has_sleeper(&heap->pool_watermark_wait))
		return;

	pool_wakeup = pool_watermark_check(heap, nr_watermark);
	spin_lock(&heap->pool_watermark_lock);
	heap->pool_watermark = nr_watermark;
	spin_unlock(&heap->pool_watermark_lock);

	if (pool_wakeup)
		pool_watermark_wakeup();
}

static ssize_t sys_pool_watermark_bytes_store(struct kobject *kobj,
					      struct kobj_attribute *attr,
					      const char *buf, size_t size)
{
	unsigned long val = 0;
	int ret = 0;

	ret = kstrtoul(buf, 0, &val);
	if (ret)
		return ret;

	if (val > MAX_POOL_WATER_MARK)
		val = MAX_POOL_WATER_MARK;

	pr_info("dma_heap %s: %lu", __func__, val);
	set_system_pool_watermark(val);

	return size;
}

static ssize_t sys_pool_watermark_bytes_show(struct kobject *kobj,
					     struct kobj_attribute *attr, char *buf)
{
	u64 nr_pages = 0;
	if (inner_qcom_sys_heap)
		nr_pages = (u64)(inner_qcom_sys_heap->pool_watermark);
	return sysfs_emit(buf, "%llu\n", nr_pages << PAGE_SHIFT);
}

static struct kobj_attribute sys_pool_watermark_bytes =
	__ATTR_RW(sys_pool_watermark_bytes);

static ssize_t sys_pool_count_bytes_show(struct kobject *kobj,
					 struct kobj_attribute *attr,
					 char *buf)
{
	u64 nr_pages = (u64)qcom_system_heap_pool_pages(inner_qcom_sys_heap);

	return sysfs_emit(buf, "%llu\n", nr_pages << PAGE_SHIFT);
}

static struct kobj_attribute sys_pool_count_bytes =
	__ATTR_RO(sys_pool_count_bytes);

static void get_global_mem_wmarks(unsigned long *low,
				  unsigned long *min, unsigned long *free_pages)
{
	struct zonelist *zonelist;
	struct zoneref *z;
	struct zone *zone;
	unsigned long wmark_low = 0;
	unsigned long wmark_min = 0;
	unsigned long num_free = 0;
	enum zone_type classzone_idx = gfp_zone(LOW_ORDER_GFP);
	zonelist = node_zonelist(numa_node_id(), LOW_ORDER_GFP);

	for_each_zone_zonelist(zone, z, zonelist, classzone_idx) {
		wmark_low += low_wmark_pages(zone);
		wmark_min += min_wmark_pages(zone);
		num_free += zone_page_state(zone, NR_FREE_PAGES);
	}

	if (low)
		*low = wmark_low;

	if (min)
		*min = wmark_min;

	if (free_pages)
		*free_pages = num_free;
}

static unsigned long calc_dynamic_system_pool_watermark(unsigned long nr_watermark)
{
	unsigned long num_min = 0;
	unsigned long num_low = 0;
	unsigned long num_free = 0;
	unsigned long min_wmark, low_wmark;
	unsigned long pages_in_pool;
	unsigned long max_to_fill;
	unsigned long low_percent;
	unsigned long high_percent;

	if (!inner_qcom_sys_heap)
		return nr_watermark;

	low_percent = inner_qcom_sys_heap->prefill_low_percent;
	high_percent = inner_qcom_sys_heap->prefill_high_percent;
	get_global_mem_wmarks(&num_min, &num_low, &num_free);
	pages_in_pool = qcom_system_heap_pool_pages(inner_qcom_sys_heap);
	pr_info("dma_heap mem-info %s: %lu %lu %lu %lu", __func__, num_free, num_low, num_min, pages_in_pool);
	if (num_min >= num_low || low_percent > high_percent || pages_in_pool >= nr_watermark)
		return nr_watermark;

	min_wmark = num_min + ((num_low - num_min) *  low_percent) / 100 ;
	low_wmark = num_min + ((num_low - num_min) *  high_percent) / 100 ;
	if (num_free <= low_wmark)
		return pages_in_pool;

	max_to_fill = num_free - min_wmark;
	if (max_to_fill <=  nr_watermark - pages_in_pool)
		nr_watermark = pages_in_pool + max_to_fill;

	return nr_watermark;
}

static ssize_t sys_pool_dynamic_watermark_bytes_store(struct kobject *kobj,
						      struct kobj_attribute *attr,
						      const char *buf, size_t size)
{
	unsigned long val = 0;
	int ret = 0;

	ret = kstrtoul(buf, 0, &val);
	if (ret)
		return ret;
	if (!inner_qcom_sys_heap)
		return ret;

	if (val > MAX_POOL_WATER_MARK)
		val = MAX_POOL_WATER_MARK;

	if (val)
		inner_qcom_sys_heap->usage = USAGE_GFX_PREALLOC;
	else
		inner_qcom_sys_heap->usage = 0;

	smp_wmb();
	val = calc_dynamic_system_pool_watermark(val);
	pr_info("dma_heap %s: %lu", __func__, val);
	set_system_pool_watermark(val);

	return size;
}
static struct kobj_attribute sys_pool_dynamic_watermark_bytes =
	__ATTR_WO(sys_pool_dynamic_watermark_bytes);

static ssize_t sys_pool_prefill_low_percent_store(struct kobject *kobj,
						  struct kobj_attribute *attr,
						  const char *buf, size_t size)
{
	unsigned long val = 0;
	int ret = 0;

	ret = kstrtoul(buf, 0, &val);
	if (ret)
		return ret;

	if (val > MAX_POOL_PREFILL_PERCENT)
		val = MAX_POOL_PREFILL_PERCENT;
	if (inner_qcom_sys_heap)
		inner_qcom_sys_heap->prefill_low_percent = val;
	pr_info("dma_heap %s: new prefill_low_percent %lu", __func__, val);

	return size;
}

static ssize_t sys_pool_prefill_low_percent_show(struct kobject *kobj,
						 struct kobj_attribute *attr, char *buf)
{
	unsigned long val = 0;
	if (inner_qcom_sys_heap)
		val = inner_qcom_sys_heap->prefill_low_percent;
	return sysfs_emit(buf, "%lu\n", val);
}

static struct kobj_attribute sys_pool_prefill_low_percent =
	__ATTR_RW(sys_pool_prefill_low_percent);

static ssize_t sys_pool_prefill_high_percent_store(struct kobject *kobj,
						   struct kobj_attribute *attr,
						   const char *buf, size_t size)
{
	unsigned long val = 0;
	int ret = 0;

	ret = kstrtoul(buf, 0, &val);
	if (ret)
		return ret;

	if (val > MAX_POOL_PREFILL_PERCENT)
		val = MAX_POOL_PREFILL_PERCENT;
	if (inner_qcom_sys_heap)
		inner_qcom_sys_heap->prefill_high_percent = val;
	pr_info("dma_heap %s: new prefill_high_percent %lu", __func__, val);

	return size;
}

static ssize_t sys_pool_prefill_high_percent_show(struct kobject *kobj,
						  struct kobj_attribute *attr, char *buf)
{
	unsigned long val = 0;
	if (inner_qcom_sys_heap)
		val = inner_qcom_sys_heap->prefill_high_percent;
	return sysfs_emit(buf, "%lu\n", val);
}

static struct kobj_attribute sys_pool_prefill_high_percent =
	__ATTR_RW(sys_pool_prefill_high_percent);

static ssize_t sys_heap_alloc_warn_time_thresh_store(struct kobject *kobj,
						     struct kobj_attribute *attr,
						     const char *buf, size_t size)
{
	unsigned long val = 0;
	int ret = 0;

	ret = kstrtoul(buf, 0, &val);
	if (ret)
		return ret;
	if (inner_qcom_sys_heap)
		inner_qcom_sys_heap->alloc_warn_time_thresh = val;
	pr_info("dma_heap %s: new alloc_warn_time_thresh %lu", __func__, val);

	return size;
}

static ssize_t sys_heap_alloc_warn_time_thresh_show(struct kobject *kobj,
						    struct kobj_attribute *attr, char *buf)
{
	unsigned long val = 0;
	if (inner_qcom_sys_heap)
		val = inner_qcom_sys_heap->alloc_warn_time_thresh;
	return sysfs_emit(buf, "%lu\n", val);
}

static ssize_t sys_heap_alloc_stats_show(struct kobject *kobj,
					 struct kobj_attribute *attr,
					 char *buf)
{
	return sysfs_emit(buf, "%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",
			  atomic64_read(&heap_alloc_stats.alloc_total_times),
			  atomic64_read(&heap_alloc_stats.alloc_from_pool_total_times),
			  atomic64_read(&heap_alloc_stats.alloc_from_buddy_total_times),
			  atomic64_read(&heap_alloc_stats.alloc_from_pool_and_buddy_total_times),
			  atomic64_read(&heap_alloc_stats.stat_less_4ms),
			  atomic64_read(&heap_alloc_stats.stat_4to6ms),
			  atomic64_read(&heap_alloc_stats.stat_6to8ms),
			  atomic64_read(&heap_alloc_stats.stat_8to11ms),
			  atomic64_read(&heap_alloc_stats.stat_11to16ms),
			  atomic64_read(&heap_alloc_stats.stat_greater_16ms));
}

static struct kobj_attribute sys_heap_alloc_stats =
	__ATTR_RO(sys_heap_alloc_stats);

static struct kobj_attribute sys_heap_alloc_warn_time_thresh =
	__ATTR_RW(sys_heap_alloc_warn_time_thresh);
static struct attribute *system_pool_attrs[] = {
	&sys_pool_watermark_bytes.attr,
	&sys_pool_count_bytes.attr,
	&sys_pool_dynamic_watermark_bytes.attr,
	&sys_pool_prefill_low_percent.attr,
	&sys_pool_prefill_high_percent.attr,
	&sys_heap_alloc_warn_time_thresh.attr,
	&sys_heap_alloc_stats.attr,
	NULL,
};

static const struct attribute_group system_pool_group = {
	.attrs = system_pool_attrs,
};

bool is_qcom_system_heap(void *dma_heap)
{
	struct dma_heap *heap = (struct dma_heap *)dma_heap;
	struct qcom_system_heap *sys_heap = NULL;
	if (!heap || !inner_qcom_sys_heap)
		return false;

	sys_heap = dma_heap_get_drvdata(heap);
	if (!sys_heap)
		return false;
	return (sys_heap == inner_qcom_sys_heap);
}

long qcom_system_pool_gt_wm_pages(void)
{
	long nr_pages = qcom_system_heap_pool_pages(inner_qcom_sys_heap);
	if (!inner_qcom_sys_heap)
		return 0;
	if (inner_qcom_sys_heap->pool_watermark >= LONG_MAX)
		return 0;
	return (nr_pages - (long)inner_qcom_sys_heap->pool_watermark);
}

void qcom_system_heap_create(const char *name, const char *system_alias, bool uncached)
{
	struct dma_heap_export_info exp_info;
	struct dma_heap *heap;
	struct qcom_system_heap *sys_heap;
	struct task_struct *refill_worker;
	struct sched_attr attr = { .sched_nice = DYNAMIC_POOL_KTHREAD_NICE_VAL };
	int ret;
	int i;

	ret = dynamic_page_pool_init_shrinker();
	if (ret)
		goto out;

	sys_heap = kzalloc(sizeof(*sys_heap), GFP_KERNEL);
	if (!sys_heap) {
		ret = -ENOMEM;
		goto out;
	}

	exp_info.name = name;
	exp_info.ops = &system_heap_ops;
	exp_info.priv = sys_heap;

	sys_heap->uncached = uncached;

	sys_heap->pool_list = dynamic_page_pool_create_pools(0, NULL);
	if (IS_ERR(sys_heap->pool_list)) {
		ret = PTR_ERR(sys_heap->pool_list);
		goto free_heap;
	}

	if (IS_ENABLED(CONFIG_QCOM_DMABUF_HEAPS_PAGE_POOL_REFILL)) {
		refill_worker = kthread_run(system_heap_refill_worker, sys_heap->pool_list,
					    "%s-pool-refill-thread", name);
		if (IS_ERR(refill_worker)) {
			pr_err("%s: failed to create %s-pool-refill-thread: %ld\n",
				__func__, name, PTR_ERR(refill_worker));
			ret = PTR_ERR(refill_worker);
			goto free_pools;
		}

		ret = sched_setattr(refill_worker, &attr);
		if (ret) {
			pr_warn("%s: failed to set task priority for %s-pool-refill-thread: ret = %d\n",
				__func__, name, ret);
			goto stop_worker;
		}

		for (i = 0; i < NUM_ORDERS; i++)
			sys_heap->pool_list[i]->refill_worker = refill_worker;
	}

	heap = dma_heap_add(&exp_info);
	if (IS_ERR(heap)) {
		ret = PTR_ERR(heap);
		goto stop_worker;
	}

	if (uncached) {
		dma_coerce_mask_and_coherent(dma_heap_get_dev(heap),
					     DMA_BIT_MASK(64));
	} else {
		for (i = 0; i < NUM_ORDERS; i++)
			sys_heap->pool_list[i]->dma_heap = (void *)heap;

		ret = dma_heap_sys_pool_watermark_init("system", &system_pool_group);
		if (ret) {
			pr_err("%s: dma_heap_sys_pool_watermark_init failed!\n", __func__);
			goto free_pools;
		}

		atomic_set(&sys_heap->wait_flag, 0);
		init_waitqueue_head(&sys_heap->pool_watermark_wait);
		sys_heap->pool_watermark_kthread = kthread_run(pool_watermark_kthread, sys_heap,
							       "sys_pool_watermark");
		if (IS_ERR(sys_heap->pool_watermark_kthread)) {
			pr_err("dma_heap %s: kthread_create failed!\n", __func__);
			goto free_pools;
		}
		spin_lock_init(&sys_heap->pool_watermark_lock);
		sys_heap->pool_watermark = 0;
		sys_heap->prefill_low_percent = DEFAULT_PREFILL_LOW_PERCENT;
		sys_heap->prefill_high_percent = DEFAULT_PREFILL_HIGH_PERCENT;
		sys_heap->alloc_warn_time_thresh = DEFAULT_ALLOC_WARN_TIME_THRESH;
		inner_qcom_sys_heap = sys_heap;
	}

	pr_info("%s: DMA-BUF Heap: Created '%s'\n", __func__, name);

	if (system_alias != NULL) {
		exp_info.name = system_alias;

		heap = dma_heap_add(&exp_info);
		if (IS_ERR(heap)) {
			pr_err("%s: Failed to create '%s', error is %d\n", __func__,
			       system_alias, PTR_ERR(heap));
			return;
		}

		dma_coerce_mask_and_coherent(dma_heap_get_dev(heap), DMA_BIT_MASK(64));

		pr_info("%s: DMA-BUF Heap: Created '%s'\n", __func__, system_alias);
	}

	return;

stop_worker:
	if (IS_ENABLED(CONFIG_QCOM_DMABUF_HEAPS_PAGE_POOL_REFILL))
		kthread_stop(refill_worker);

free_pools:
	dynamic_page_pool_release_pools(sys_heap->pool_list);

free_heap:
	kfree(sys_heap);

out:
	pr_err("%s: Failed to create '%s', error is %d\n", __func__, name, ret);
}
