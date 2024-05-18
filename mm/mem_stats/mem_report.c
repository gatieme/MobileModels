/*
 * Copyright (c) Honor Device Co., Ltd. 2023. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifdef CONFIG_DMA_BUF_INFO
#include <linux/dma-buf.h>
#endif
#ifdef CONFIG_MEMCG_PROTECT_LRU
#include <linux/protect_lru.h>
#endif
#ifdef CONFIG_UNMOVABLE_ISOLATE
#include <linux/unmovable_isolate.h>
#endif
#include <log/hiview_hievent.h>

#define CASE_NAME_SIZE    64
#define ARG1_SIZE         128

#define BOOT_PERF_KEY_INFO_EVENT 902060016

extern struct ratelimit_state report_rs;
extern struct ratelimit_state buddy_report_rs;

struct mem_event_entry {
	char case_name[CASE_NAME_SIZE];
	char arg1[ARG1_SIZE];
	/* mem report using a workqueue*/
	struct work_struct event_work;
};

static void calculate_zone_element(unsigned long *min,
					unsigned long *low,
					unsigned long *high,
					unsigned long *reserved_highatomic,
					unsigned long *free_pcp)
{
	struct zone *zone;
	int cpu;

	for_each_populated_zone(zone) {
		*min  += min_wmark_pages(zone);
		*low  += low_wmark_pages(zone);
		*high += high_wmark_pages(zone);
		*reserved_highatomic += zone->nr_reserved_highatomic;

		for_each_online_cpu(cpu)
			*free_pcp += per_cpu_ptr(zone->per_cpu_pageset, cpu)->count;
	}
}

static void mem_event_workfn(struct work_struct *work)
{
	struct mem_event_entry *mem_entry =
		container_of(work, struct mem_event_entry, event_work);
	struct hiview_hievent* event;
	unsigned long min = 0, low = 0, high = 0, reserved_highatomic = 0, free_pcp = 0;

	calculate_zone_element(&min, &low, &high, &reserved_highatomic, &free_pcp);

	event = hiview_hievent_create(BOOT_PERF_KEY_INFO_EVENT);
	hiview_hievent_put_string(event, "CaseName", mem_entry->case_name);
	pr_info("CaseName = %s\n", mem_entry->case_name);
	hiview_hievent_put_string(event, "ARG", mem_entry->arg1);
	pr_info("ARG1 = %s\n", mem_entry->arg1);

	hiview_hievent_put_integral(event, "MIN", min);
	hiview_hievent_put_integral(event, "LOW", low);
	hiview_hievent_put_integral(event, "HIGH", high);
	hiview_hievent_put_integral(event, "RESERVED_HIGHATOMIC", reserved_highatomic);
	hiview_hievent_put_integral(event, "ACTIVE_ANON", global_node_page_state(NR_ACTIVE_ANON));
	hiview_hievent_put_integral(event, "INACTIVE_ANON", global_node_page_state(NR_INACTIVE_ANON));
	hiview_hievent_put_integral(event, "ISOLATED_ANON", global_node_page_state(NR_ISOLATED_ANON));
	hiview_hievent_put_integral(event, "ACTIVE_FILE", global_node_page_state(NR_ACTIVE_FILE));
	hiview_hievent_put_integral(event, "INACTIVE_FILE", global_node_page_state(NR_INACTIVE_FILE));
	hiview_hievent_put_integral(event, "ISOLATED_FILE", global_node_page_state(NR_ISOLATED_FILE));
#ifdef CONFIG_DMA_BUF_INFO
	hiview_hievent_put_integral(event, "DMA_BUF_USED", get_dma_buf_Used() >> PAGE_SHIFT);
#endif
#ifdef CONFIG_KGSL_PAGE_ALLOC_INFO
	hiview_hievent_put_integral(event, "KGSL_USED", global_node_page_state(NR_KGSL_PAGES));
#endif
#ifdef CONFIG_MEMCG_PROTECT_LRU
	hiview_hievent_put_integral(event, "PROTECTED", get_protected_pages());
#endif
	hiview_hievent_put_integral(event, "UNEVICTABLE", global_node_page_state(NR_UNEVICTABLE));
	hiview_hievent_put_integral(event, "DIRTY", global_node_page_state(NR_FILE_DIRTY));
	hiview_hievent_put_integral(event, "WRITEBACK", global_node_page_state(NR_WRITEBACK));
	hiview_hievent_put_integral(event, "SLAB_RECLAIMABLE", global_node_page_state_pages(NR_SLAB_RECLAIMABLE_B));
	hiview_hievent_put_integral(event, "SLAB_UNRECLAIMABLE", global_node_page_state_pages(NR_SLAB_UNRECLAIMABLE_B));
	hiview_hievent_put_integral(event, "MAPPED", global_node_page_state(NR_FILE_MAPPED));
	hiview_hievent_put_integral(event, "SHMEM", global_node_page_state(NR_SHMEM));
	hiview_hievent_put_integral(event, "PAGETABLES", global_node_page_state(NR_PAGETABLE));
	hiview_hievent_put_integral(event, "BOUNCE", global_zone_page_state(NR_BOUNCE));
#ifdef CONFIG_UNMOVABLE_ISOLATE
	hiview_hievent_put_integral(event, "FREE_UNMOVABLE_ISOLATE1", global_zone_page_state(NR_FREE_UNMOVABLE_ISOLATE1_PAGES));
	hiview_hievent_put_integral(event, "FREE_UNMOVABLE_ISOLATE2", global_zone_page_state(NR_FREE_UNMOVABLE_ISOLATE2_PAGES));
#endif
	hiview_hievent_put_integral(event, "KERNEL_MISC_RECLAIMABLE", global_node_page_state(NR_KERNEL_MISC_RECLAIMABLE));
	hiview_hievent_put_integral(event, "FREE", global_zone_page_state(NR_FREE_PAGES));
	hiview_hievent_put_integral(event, "FREE_PCP", free_pcp);
	hiview_hievent_put_integral(event, "FREE_CMA", global_zone_page_state(NR_FREE_CMA_PAGES));

	hiview_hievent_report(event);
	hiview_hievent_destroy(event);

	kfree(mem_entry);
}

void mem_alloc_report(const char *device_type, const char *device_name, size_t len,
				const char *reason, u64 wait_ms)
{
	struct mem_event_entry *mem_entry;

	if (unlikely(in_interrupt() || irqs_disabled() || in_atomic())) {
		return;
	}

	if (!__ratelimit(&report_rs))
		return;

	warn_alloc(GFP_KERNEL, NULL,
			"%s:%s alloc %s, alloc-size:%lu, stall: %lld ms",
			device_type, device_name, reason, len, wait_ms);

	mem_entry = kzalloc(sizeof(struct mem_event_entry), GFP_ATOMIC);
	if (!mem_entry) {
		pr_err("mem_entry alloc fail\n");
		return;
	}
	INIT_WORK(&mem_entry->event_work, mem_event_workfn);

	snprintf(mem_entry->case_name, sizeof(char) * CASE_NAME_SIZE, "%s_%s_alloc_%s",
			device_name, device_type, reason);
	snprintf(mem_entry->arg1, sizeof(char) * ARG1_SIZE, "pid_%d_%s_%s_%s_alloc_size_%lu_%s_%lld_ms",
			current->pid, current->comm, device_type, device_name, len, reason, wait_ms);

	schedule_work(&mem_entry->event_work);
}
EXPORT_SYMBOL_GPL(mem_alloc_report);

void mem_anomal_report(const char *anomal_name, unsigned long len, unsigned long threshold, unsigned int *nr)
{
	struct mem_event_entry *mem_entry;

	if (unlikely(in_interrupt() || irqs_disabled() || in_atomic())) {
		return;
	}

	if (!__ratelimit(&report_rs))
		return;

	warn_alloc(GFP_KERNEL, NULL, "%s_value:%lu, more than threshold-%u time:%u", anomal_name, len, threshold, *nr);

	mem_entry = kzalloc(sizeof(struct mem_event_entry), GFP_ATOMIC);
	if (!mem_entry) {
		pr_err("mem_entry alloc fail\n");
		return;
	}

	INIT_WORK(&mem_entry->event_work, mem_event_workfn);
	snprintf(mem_entry->case_name, sizeof(char) * CASE_NAME_SIZE, "%s", anomal_name);
	snprintf(mem_entry->arg1, sizeof(char) * ARG1_SIZE, "pid_%d_%s_%s_value_%lu_more_than_thres_%lu_time_%u",
			current->pid, current->comm, anomal_name, len, threshold, *nr);

	schedule_work(&mem_entry->event_work);
	// clear anomal times
	*nr = 0;
}
EXPORT_SYMBOL_GPL(mem_anomal_report);

#define BUDDY_INFO_EVENT 902500009
#define BUDDY_KEY_LEN    14
static void __buddyinfo_report(struct work_struct *work);
static DECLARE_WORK(buddyinfo_wk, __buddyinfo_report);
static void buddyinfo_event_report( struct zone *zone)
{
	int order;
#ifdef CONFIG_HONOR_ZONE_ISOLATE
	int zi_index = 0;
#endif
	unsigned long buddy[MAX_ORDER] = {0};
	unsigned long free;
	struct hiview_hievent* event;

	free = global_zone_page_state(NR_FREE_PAGES);

#ifdef CONFIG_HONOR_ZONE_ISOLATE
	for (zi_index = 0; zi_index < ZONE_ISOLATE_COUNT; zi_index++) {
		for (order = 0; order < MAX_ORDER; ++order)
			buddy[order] += zone->free_area[zi_index][order].nr_free;
	}
#else
	for (order = 0; order < MAX_ORDER; ++order)
		buddy[order] = zone->free_area[order].nr_free;
#endif

	event = hiview_hievent_create(BUDDY_INFO_EVENT);
	hiview_hievent_put_integral(event, "TotalSize", free);
	for (order = 0; order < MAX_ORDER; order++) {
		char key[BUDDY_KEY_LEN] = {0};

		snprintf(key, sizeof(key), "O%dMemfreeInfo", order);
		hiview_hievent_put_integral(event, key, buddy[order]);
	}
	hiview_hievent_report(event);
	hiview_hievent_destroy(event);
}

static void __buddyinfo_report(struct work_struct *work)
{
	pg_data_t *pgdat;

	for_each_online_pgdat(pgdat) {
		int zoneid;

		for (zoneid = 0; zoneid < MAX_NR_ZONES; zoneid++) {
			struct zone *zone = &pgdat->node_zones[zoneid];
			if (!populated_zone(zone))
				continue;

			buddyinfo_event_report(zone);
		}
	}
}

void buddyinfo_report(void)
{
	if (!__ratelimit(&buddy_report_rs))
		return;

	if (unlikely(in_interrupt() || irqs_disabled() || in_atomic())) {
		return;
	}

	schedule_work(&buddyinfo_wk);
}
EXPORT_SYMBOL_GPL(buddyinfo_report);

