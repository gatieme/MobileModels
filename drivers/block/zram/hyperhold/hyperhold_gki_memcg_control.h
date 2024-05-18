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
 * Author:	Lin Kunli <linkunli.>
 *		Wang Xin<wang23.>
 *
 * Create: 2022-8-27
 *
 */

#ifdef CONFIG_HYPERHOLD_GKI

#ifndef HYPERHOLD_GKI_MEMCG_CONTROL_H
#define HYPERHOLD_GKI_MEMCG_CONTROL_H

#include <linux/device.h>
#include <linux/memcontrol.h>
#include <linux/cpumask.h>

#include "zram_drv.h"

#define HH_MEM_CGROUP_EXT_ID_MAX MEM_CGROUP_ID_MAX
#define MEM_CGROUP_NAME_MAX_LEN 100
#define APPSCORE_MAX_LEN 100
#define HYPERHOLD_MEMCG_INFO_ITEMS 2
#define HYPERHOLD_APPSCORE_ITEMS 2
#define APPSCORE_MAX 1000
#define APPSCORE_MIN 0

struct memcg_reclaim {
	atomic64_t ub_ufs2zram_ratio;
	atomic_t ub_zram2ufs_ratio;
	atomic64_t app_score;
	atomic_t fault_type;
	atomic_t ub_mem2zram_ratio;
	atomic_t refault_threshold;
	/* anon refault */
	unsigned long long reclaimed_pagefault;
};

struct mem_cgroup_ext {
	atomic_t valid;
	unsigned long zram_lru;
	unsigned long ext_lru;
	struct list_head link_list;
	spinlock_t zram_init_lock;
	struct zram *zram;
	struct mem_cgroup *mcg;
	unsigned short mcg_ext_id;

	atomic64_t zram_stored_size;
	atomic64_t zram_page_size;
	unsigned long zram_watermark;

	atomic_t hyperhold_extcnt;
	atomic_t hyperhold_peakextcnt;

	atomic64_t hyperhold_stored_pages;
	atomic64_t hyperhold_stored_size;
	atomic64_t hyperhold_ext_notify_free;

	atomic64_t hyperhold_outcnt;
	atomic64_t hyperhold_incnt;
	atomic64_t hyperhold_allfaultcnt;
	atomic64_t hyperhold_faultcnt;

	atomic64_t hyperhold_outextcnt;
	atomic64_t hyperhold_inextcnt;

	atomic64_t zram_idle_size;
	atomic64_t zram_idle_page;

	bool in_swapin;
	atomic64_t hyperhold_cold_writeback;

	struct memcg_reclaim memcg_reclaimed;
	struct list_head score_node;
	char name[MEM_CGROUP_NAME_MAX_LEN];
};

static inline unsigned long hyperhold_memcg_page_state_local(struct mem_cgroup *memcg, int idx)
{
	long x = 0;
	int cpu;

	for_each_possible_cpu(cpu)
		x += per_cpu(memcg->vmstats_percpu->state[idx], cpu);
#ifdef CONFIG_SMP
	if (x < 0)
		x = 0;
#endif
	return x;
}



int hyperhold_mcg_reclaim(unsigned short mcgid, void *data);
unsigned long hyperhold_mcg_shrink(unsigned short mcgid, unsigned long nr_to_shrink);
struct mem_cgroup_ext *mem_cgroup_ext_from_memcg(struct mem_cgroup *mcg);
struct mem_cgroup_ext* mem_cgroup_ext_from_mcg_id(unsigned short mcgid);
struct mem_cgroup_ext *get_mem_cgroup (unsigned short mcg_id);
unsigned short get_mem_cgroup_id(struct mem_cgroup_ext *mcg_ext);
bool mem_cgroup_ext_check(struct mem_cgroup_ext *mcg_ext);
struct mem_cgroup_ext *get_next_memcg_ext(struct mem_cgroup_ext *mcg_ext_prev);
void get_next_memcg_ext_break(struct mem_cgroup_ext *memcg_ext);
void memcg_app_score_sort_ext(struct mem_cgroup_ext *target);
void memcg_ext_init(void);
unsigned short get_mcg_id(struct mem_cgroup_ext *mcg_ext);
ssize_t hyperhold_appscore_show(struct device *dev,
	struct device_attribute *attr, char *buf);
ssize_t hyperhold_appscore_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_force_swapout_store(struct device *dev,
       struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_force_swapin_store(struct device *dev,
       struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_memcg_info_show(struct device *dev,
	struct device_attribute *attr, char *buf);
ssize_t hyperhold_force_shrink_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t len);
void force_shrink_anon_enable(void);
void force_shrink_anon_disable(void);
#ifdef CONFIG_HYPERHOLD_GKI_DEBUG
ssize_t hyperhold_memcg_stat_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_memcg_stat_show(struct device *dev,
		struct device_attribute *attr, char *buf);
#endif
#endif

#endif

