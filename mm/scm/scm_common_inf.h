/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager interface
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for API, structure defination.
 *
 */
#ifndef _SCM_COMMON_INF_H_
#define _SCM_COMMON_INF_H_

#include <linux/gfp.h>
#include <linux/memcontrol.h>
#include <linux/mm_types.h>
#include <linux/sched.h>
#include <linux/shrinker.h>
#include <linux/types.h>

// hook entries
extern long scm_mem_available_update(long available);

extern void scm_reclaim_path_type_dr(u64 *ext);
extern void
scm_reclaim_update_scan_control(u64 *ext, unsigned long *nr_to_reclaim,
				struct mem_cgroup *target_mem_cgroup,
				bool *file_is_tiny, bool *may_writepage);
extern void scm_reclaim_should_continue(u64 *ext, unsigned long *nr_to_reclaim,
					unsigned long *nr_reclaimed,
					bool *continue_reclaim);

extern bool scm_reclaim_shrink_slab_bypass(gfp_t gfp_mask, int nid,
					   struct mem_cgroup *memcg,
					   int priority);
extern long scm_shrinker_do_shrink_slab(struct shrinker *shrinker,
					long org_freeable);
extern struct page *scm_qos_pool_alloc_pages(gfp_t alloc_gfp, int order,
					     int alloc_flags, int step);
extern bool scm_qos_pool_free_to_fill(struct page *page, unsigned int order,
				      unsigned long pfn, int migratetype,
				      bool remove);
extern unsigned long scm_fault_around_bytes_get(unsigned long nr_pages);
extern int scm_qos_alloc_harder_decide(struct task_struct *task);
extern bool scm_qos_pcp_should_bypass(struct task_struct *task);

#endif // _SCM_COMMON_INF_H_
