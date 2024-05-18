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
#include <linux/err.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/sizes.h>
#include <linux/mem_report.h>

static unsigned int nr_anomal_free;
static unsigned int nr_anomal_file;
static unsigned int nr_anomal_anon;
static unsigned int nr_anomal_isolate;

void isolated_detect(int file, unsigned long inactive, unsigned long isolated)
{
	/* if isolated less, abanon detect*/
	if (isolated < 10)
		return;

	inactive >>= isolated_threshold;

	if (isolated > inactive) {

		nr_anomal_isolate++;
		mem_anomal_report(file > 0 ? "file_isolated_anomal" : "anon_isolated_anomal",
			isolated, inactive, &nr_anomal_isolate);
	}
}
EXPORT_SYMBOL_GPL(isolated_detect);

void page_detect(void)
{
	unsigned long active_anon, inactive_anon, active_file, inactive_file, free;

	active_anon = global_node_page_state(NR_ACTIVE_ANON);
	inactive_anon = global_node_page_state(NR_INACTIVE_ANON);
	active_file = global_node_page_state(NR_ACTIVE_FILE);
	inactive_file = global_node_page_state(NR_INACTIVE_FILE);
	free = global_zone_page_state(NR_FREE_PAGES);

	if (free < free_page_min) {
		nr_anomal_free++;
		mem_anomal_report("free_anomal", free, free_page_min, &nr_anomal_free);
	} else if ((active_anon +inactive_anon) > used_page_max) {
		nr_anomal_anon++;
		mem_anomal_report("anon_anomal", (active_anon + inactive_anon), used_page_max, &nr_anomal_anon);
	} else if ((active_file +inactive_file) > used_page_max) {
		nr_anomal_file++;
		mem_anomal_report("file_anomal", (active_file + inactive_file), used_page_max, &nr_anomal_file);
	}
}
EXPORT_SYMBOL_GPL(page_detect);

