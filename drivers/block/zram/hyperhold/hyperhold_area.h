/*
 * Copyright (c) Honor Technologies Co., Ltd. 2020. All rights reserved.
 * Description: hyperhold header file
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
 * Author:	He Biao <hebiao6.>
 *		Wang Cheng Ke <wangchengke2.>
 *		Wang Fa <fa.wang.>
 *
 * Create: 2020-4-16
 *
 */

#ifndef _HYPERHOLD_AREA_H
#define _HYPERHOLD_AREA_H

#include <linux/memcontrol.h>

struct hyperhold_area {
	unsigned long size;
	int nr_objs;
	int nr_exts;
	int nr_mcgs;

	unsigned long *bitmap;
	atomic_t last_alloc_bit;

	struct hh_list_table *ext_table;
	struct hh_list_head *ext;

	struct hh_list_table *obj_table;
	struct hh_list_head *rmap;
	struct hh_list_head *lru;

	atomic_t stored_exts;
	atomic_t *ext_stored_pages;
#ifdef CONFIG_HYPERHOLD_GKI
	struct mutex idle_lock;
	int idle_pid;
	struct mutex shrink_lock;
	int shrink_pid;
	spinlock_t mcg_ext_lock;
	unsigned long *mcg_ext_bitmap;
	unsigned long *mcg_ext_rmap;
	unsigned int mcg_id_cnt[HH_MEM_CGROUP_EXT_ID_MAX +1];
#else
	unsigned int mcg_id_cnt[MEM_CGROUP_ID_MAX + 1];
#endif
};

#ifdef CONFIG_HYPERHOLD_GKI
struct mem_cgroup_ext *get_mem_cgroup(unsigned short mcg_id);
int hyperhold_alloc_extent(struct hyperhold_area *area, struct mem_cgroup_ext *mcg);
int get_memcg_extent(struct hyperhold_area *area, struct mem_cgroup_ext *mcg);
int get_memcg_zram_entry(struct hyperhold_area *area, struct mem_cgroup_ext *mcg);
int alloc_bitmap(unsigned long *bitmap, int max, int last_bit);
#else
struct mem_cgroup *get_mem_cgroup(unsigned short mcg_id);
int hyperhold_alloc_extent(struct hyperhold_area *area, struct mem_cgroup *mcg);
int get_memcg_extent(struct hyperhold_area *area, struct mem_cgroup *mcg);
int get_memcg_zram_entry(struct hyperhold_area *area, struct mem_cgroup *mcg);
#endif

int obj_idx(struct hyperhold_area *area, int idx);
int ext_idx(struct hyperhold_area *area, int idx);
int mcg_idx(struct hyperhold_area *area, int idx);

void free_hyperhold_area(struct hyperhold_area *area);
struct hyperhold_area *alloc_hyperhold_area(unsigned long ori_size,
					    unsigned long comp_size);
void hyperhold_free_extent(struct hyperhold_area *area, int ext_id);
int get_extent(struct hyperhold_area *area, int ext_id);
void put_extent(struct hyperhold_area *area, int ext_id);
int get_extent_zram_entry(struct hyperhold_area *area, int ext_id);
#endif
