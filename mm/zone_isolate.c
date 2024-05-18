/*
 * Copyright (c) Honor Device Co., Ltd. 2016-2022. All rights reserved.
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
 *
 * Provide external call interfaces of Process reclaim information.
 */

#include <linux/stddef.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/interrupt.h>
#include <linux/pagemap.h>
#include <linux/jiffies.h>
#include <linux/memblock.h>
#include <linux/compiler.h>
#include <linux/kernel.h>
#include <linux/kasan.h>
#include <linux/module.h>
#include <linux/suspend.h>
#include <linux/pagevec.h>
#include <linux/blkdev.h>
#include <linux/slab.h>
#include <linux/ratelimit.h>
#include <linux/oom.h>
#include <linux/topology.h>
#include <linux/sysctl.h>
#include <linux/cpu.h>
#include <linux/cpuset.h>
#include <linux/memory_hotplug.h>
#include <linux/nodemask.h>
#include <linux/vmalloc.h>
#include <linux/vmstat.h>
#include <linux/mempolicy.h>
#include <linux/memremap.h>
#include <linux/stop_machine.h>
#include <linux/sort.h>
#include <linux/pfn.h>
#include <linux/backing-dev.h>
#include <linux/fault-inject.h>
#include <linux/page-isolation.h>
#include <linux/page_ext.h>
#include <linux/debugobjects.h>
#include <linux/kmemleak.h>
#include <linux/compaction.h>
#include <trace/events/kmem.h>
#include <trace/events/oom.h>
#include <linux/prefetch.h>
#include <linux/mm_inline.h>
#include <linux/migrate.h>
#include <linux/hugetlb.h>
#include <linux/sched/rt.h>
#include <linux/sched/mm.h>
#include <linux/page_owner.h>
#include <linux/kthread.h>
#include <linux/memcontrol.h>
#include <linux/ftrace.h>
#include <linux/lockdep.h>
#include <linux/nmi.h>
#include <linux/psi.h>
#include <asm/sections.h>
#include <asm/tlbflush.h>
#include <asm/div64.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/cpu.h>
#include <linux/cpumask.h>
#include <linux/vmstat.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/debugfs.h>
#include <linux/math64.h>
#include <linux/writeback.h>
#include "internal.h"

#include <linux/zone_isolate.h>

#include "internal.h"

#define HIGH_ORDER_TO_ZI_INDEX 1
#define SIZE_WRITE_DATA 16
#ifdef CONFIG_HONOR_ZONE_ISOLATE_DEBUG
static unsigned long zi_index_alloc_record[ZONE_ISOLATE_COUNT][MAX_ORDER][MIGRATE_TYPES] = {0, };
static unsigned int show_order = 0;

static char * const zone_names[MAX_NR_ZONES] = {
#ifdef CONFIG_ZONE_DMA
	 "DMA",
#endif
#ifdef CONFIG_ZONE_DMA32
	 "DMA32",
#endif
	 "Normal",
#ifdef CONFIG_HIGHMEM
	 "HighMem",
#endif
	 "Movable",
#ifdef CONFIG_ZONE_DEVICE
	 "Device",
#endif
};

void record_zi_index(unsigned int zi_index, unsigned int order, int migratetype)
{
	zi_index_alloc_record[zi_index][order][migratetype]++;
}

static int zone_isolate_info_show(struct seq_file *m, void *p)
{
	unsigned int order, t, zi_index;
	pg_data_t *pgdat = NODE_DATA(0);
	int zone_type;		/* needs to be signed */

	for (zone_type = 0; zone_type < MAX_NR_ZONES; zone_type++) {
		struct zone *zone = &pgdat->node_zones[zone_type];

		if (!managed_zone(zone)) {
			continue;
		}
		seq_printf(m, "---------------------------------------------------------------------------------------------------------------\n");
		seq_printf(m, "zone_name = %s, show_order = %u\n", zone_names[zone_type], show_order);
		for (zi_index = 0; zi_index < ZONE_ISOLATE_COUNT; zi_index++)
			seq_printf(m, "[%d]: end_pfn = %lu, mid_pfn = %lu\n", zi_index, zone->zi_info[zi_index].end_pfn, zone->zi_info[zi_index].mid_pfn);
		seq_printf(m, "\n---------------------------------------------------------------------------------------------------------------\n");

		for (zi_index = 0; zi_index < ZONE_ISOLATE_COUNT; zi_index++) {
			seq_printf(m, "zone_name = %s\n", zone_names[zone_type]);
			seq_printf(m, "zi_index = %u\n", zi_index);
			seq_printf(m, "order ");
			for (t = 0; t < MIGRATE_TYPES; t++)
				seq_printf(m, "%12s", migratetype_names[t]);
			seq_printf(m, "\n");
			for (order = 0; order < MAX_ORDER; order++) {
				seq_printf(m, "%6u", order);
				for (t = 0; t < MIGRATE_TYPES; t++)
					seq_printf(m, "%12lu ", zi_index_alloc_record[zi_index][order][t]);
				seq_printf(m, "\n");
			}
			seq_printf(m, "--------------------------------------------------------------\n");
		}
	}

   return 0;
}

static ssize_t zone_isolate_info_write(struct file *file, const char __user *buff, size_t len, loff_t *ppos)
{
	char write_data[SIZE_WRITE_DATA] = {0};
	int ret = 0;
	/* if len is greater than SIZE_WRITE_DATA ,it may cause an overflow of write_data in function copy_from_user */
	if (len > SIZE_WRITE_DATA) {
		return -EFAULT;
	}
	if (copy_from_user(&write_data, buff, len)) {
		return -EFAULT;
	}
	ret = kstrtouint(write_data, 10, &show_order);

	return len;
}

static int zone_isolate_info_open(struct inode *inode, struct file *file)
{
	return single_open(file, zone_isolate_info_show, NULL);
}

const struct proc_ops zone_isolate_info_fops = {
	.proc_flags	= PROC_ENTRY_PERMANENT,
	.proc_open	= zone_isolate_info_open,
	.proc_read	= seq_read,
	.proc_write	= zone_isolate_info_write,
	.proc_lseek	= seq_lseek,
	.proc_release	= seq_release,
};
#endif // CONFIG_HONOR_ZONE_ISOLATE_DEBUG

void add_page_to_list(struct page *page, struct zone *zone, unsigned int order, int mt)
{
	struct list_head *list = &(zone->free_area[0][order].free_list[mt]);
	unsigned long pfn = 0, mid_pfn = 0;
	int i = 0;

	pfn = page_to_pfn(page);

	if (unlikely(pfn > zone->zi_info[ZONE_ISOLATE_COUNT - 1].end_pfn)) {
		list = &(zone->free_area[ZONE_ISOLATE_COUNT - 1][order].free_list[mt]);
		mid_pfn = zone->zi_info[ZONE_ISOLATE_COUNT - 1].mid_pfn;
		goto add_page;
	}

	for (i = 0; i < ZONE_ISOLATE_COUNT; i++) {
		if (pfn <= zone->zi_info[i].end_pfn) {
			list = &(zone->free_area[i][order].free_list[mt]);
			mid_pfn = zone->zi_info[i].mid_pfn;
			break;
		}
	}

add_page:
	if (pfn >= mid_pfn)
		list_add_tail(&page->lru, list);
	else
		list_add(&page->lru, list);
}

int page_to_zi_index(struct page *page)
{
	struct zone *zone = page_zone(page);
	unsigned long pfn = page_to_pfn(page);
	int zi_index = 0;

	if (unlikely(pfn > zone->zi_info[ZONE_ISOLATE_COUNT - 1].end_pfn))
		return ZONE_ISOLATE_COUNT - 1;

	for (zi_index = 0; zi_index < ZONE_ISOLATE_COUNT; zi_index++) {
		if (pfn <= zone->zi_info[zi_index].end_pfn)
			return zi_index;
	}

	return zi_index;
}

/* zone0 has about 10% UNMOVABLE_ISOLATE */
int count_percent[ZONE_ISOLATE_COUNT] = {40, 20, 20, 20};
void setup_zone_isolate(struct zone *zone)
{
	int i = 0;
	unsigned long count_end_pfn = 0;
	unsigned long count_mid_pfn = 0;
	unsigned long pfn;
	unsigned long start_pfn = zone->zone_start_pfn;
	unsigned long end_pfn = zone_end_pfn(zone);
	unsigned long end_pfn_pages[ZONE_ISOLATE_COUNT];// = zone_managed_pages(zone) / ZONE_ISOLATE_COUNT;
	unsigned long mid_pfn_pages[ZONE_ISOLATE_COUNT];// = end_pfn_pages / 2;
	bool mid_pfn_inited = false;
	struct page *page;

	for (i = 0; i < ZONE_ISOLATE_COUNT; i++) {
		end_pfn_pages[i] = zone_managed_pages(zone) * count_percent[i] / 100;
		mid_pfn_pages[i] = end_pfn_pages[i] / 2;
	}
	i = 0;
	for (pfn = start_pfn; pfn < end_pfn; pfn += pageblock_nr_pages) {
		if (i == ZONE_ISOLATE_COUNT)
			break;

		page = pfn_to_online_page(pfn);
		if (!page)
			continue;

		if (page_zone(page) != zone)
			continue;

		count_end_pfn++;
		if (!mid_pfn_inited) {
			count_mid_pfn++;

			if (count_mid_pfn * pageblock_nr_pages > mid_pfn_pages[i]) {
				zone->zi_info[i].mid_pfn = pfn + pageblock_nr_pages -1;
				mid_pfn_inited = true;
			}
		}


		if (count_end_pfn * pageblock_nr_pages > end_pfn_pages[i]) {
			zone->zi_info[i].end_pfn = pfn + pageblock_nr_pages -1;
			i++;
			count_end_pfn = 0;
			count_mid_pfn = 0;
			mid_pfn_inited = false;
		}
	}

	zone->zi_info[ZONE_ISOLATE_COUNT - 1].end_pfn = end_pfn;
}

/* first alloc in zone0, let zone3 more free for compact */
int zi_index_index[4][4] = {
	{2, 3, 0, 1},
	{3, 2, 1, 0},
	{0, 1, 2, 3},
	{1, 0, 3, 2}
};

unsigned int get_zi_index(unsigned int current_zi_index, unsigned int order, int migratetype)
{
	int index;
	if (migratetype == MIGRATE_UNMOVABLE || migratetype == MIGRATE_RECLAIMABLE)
		index = 0;
	else
		index = 2;
	if (order >= HIGH_ORDER_TO_ZI_INDEX)
		index++;

	return zi_index_index[index][current_zi_index];
}
