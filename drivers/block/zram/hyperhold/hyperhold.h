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

#ifndef HYPERHOLD_H
#define HYPERHOLD_H

#ifdef CONFIG_HYPERHOLD_GKI
#include "hyperhold_gki_memcg_control.h"
#endif

#if (defined CONFIG_HYPERHOLD_CORE) || (defined CONFIG_HYPERHOLD_GKI)
extern void hyperhold_init(struct zram *zram);
#ifdef CONFIG_HYPERHOLD_GKI
void hyperhold_gki_zram_exit(void);
void hyperhold_mem_cgroup_remove(struct mem_cgroup *memcg);
int hyperhold_batch_out(struct mem_cgroup_ext *mcg,
				unsigned long size, bool preload);
ssize_t hyperhold_cold_writeback_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t len);
#ifdef CONFIG_HYPERHOLD_GKI_DEBUG
ssize_t hyperhold_gki_debug_level_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
ssize_t hyperhold_gki_debug_level_show(struct device *dev,
		struct device_attribute *attr, char *buf);
#endif

#else
extern int hyperhold_batch_out(struct mem_cgroup *mcg,
				unsigned long size, bool preload);
#endif
extern void hyperhold_track(struct zram *zram,
			u32 index, struct mem_cgroup *memcg);
extern void hyperhold_untrack(struct zram *zram, u32 index);
extern unsigned long hyperhold_reclaim_in(unsigned long size);
extern int hyperhold_fault_out(struct zram *zram, u32 index);
extern bool hyperhold_delete(struct zram *zram, u32 index);
extern void hyperhold_mem_cgroup_remove(struct mem_cgroup *memcg);
extern unsigned long zram_zsmalloc(struct zs_pool *zs_pool,
					size_t size, gfp_t gfp);
#ifdef CONFIG_HYPERHOLD_DEBUG_FS
extern ssize_t hyperhold_ft_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hyperhold_ft_show(struct device *dev,
	struct device_attribute *attr, char *buf);
#endif
extern ssize_t hyperhold_report_show(struct device *dev,
	struct device_attribute *attr, char *buf);
extern ssize_t hyperhold_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hyperhold_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf);
extern ssize_t hyperhold_mapper_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hyperhold_mapper_show(struct device *dev,
	struct device_attribute *attr, char *buf);

extern struct task_struct *get_task_from_proc(struct inode *inode);

extern void hyperhold_idle_inc(struct zram *zram, u32 index);
extern void hyperhold_idle_dec(struct zram *zram, u32 index);
extern void hyperhold_idle_reclaim(void);
extern bool hyperhold_enable(void);


#else
static inline void hyperhold_init(struct zram *zram) {}
static inline void hyperhold_track(struct zram *zram, u32 index,
					struct mem_cgroup *mem_cgroup) {}
static inline void hyperhold_untrack(struct zram *zram, u32 index) {}
static inline unsigned long hyperhold_reclaim_in(unsigned long size)
{
	return 0;
}
static inline int hyperhold_batch_out(struct mem_cgroup *mcg,
				unsigned long size, bool preload)
{
	return 0;
}
static inline int hyperhold_fault_out(struct zram *zram, u32 index)
{
	return 0;
}
static inline bool hyperhold_delete(struct zram *zram, u32 index)
{
	return true;
}
static inline void hyperhold_mem_cgroup_remove(struct mem_cgroup *memcg) {}
static inline ssize_t hyperhold_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	return len;
}

static inline ssize_t hyperhold_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return 0;
}

#ifdef CONFIG_HYPERHOLD_DEBUG_FS
static inline  ssize_t hyperhold_ft_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	return len;
}

static inline ssize_t hyperhold_ft_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return 0;
}
#endif

static inline ssize_t hyperhold_report_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return 0;
}

static inline void hyperhold_idle_inc(struct zram *zram, u32 index) {}
static inline void hyperhold_idle_dec(struct zram *zram, u32 index) {}
static inline void hyperhold_idle_reclaim(void) {}
static inline bool hyperhold_enable(void)
{
	return false;
}
#endif


#endif
