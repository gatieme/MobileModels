/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager internal interface
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for internal API, structure defination.
 *
 */
#ifndef _SCM_INTERNAL_H_
#define _SCM_INTERNAL_H_

#define SCM_MODULE_NAME "scm"
#include "scm_helper.h"
#include "scm_internal_def.h"
#include "scm_sys_status.h"
#include "scm_task_status.h"

typedef struct _scm_watermark {
	atomic64_t nr_min_free;
	atomic64_t nr_min_file;
	atomic64_t nr_min_anon;
	atomic64_t nr_min_swap;
} scm_watermark;

typedef struct _scm_mem_available {
	atomic64_t count;
	atomic64_t nr_max_reserved;
} scm_mem_available;

typedef struct _smart_cache_manager {
	atomic64_t enabled;
	uint64_t debug;
	struct _scm_watermark wm;
	struct _scm_mem_available available;
} smart_cache_manager;

extern smart_cache_manager *scm;

static inline void _scm_enable(uint64_t policy)
{
	atomic64_set(&scm->enabled, (policy & POLICY_ALL));
}

static inline bool _scm_enabled(uint64_t policy)
{
	return ((atomic64_read(&scm->enabled) & policy)) ? true : false;
}

#ifdef CONFIG_HONOR_SCM_DEBUG
static inline void _scm_enable_debug(uint64_t level)
{
	scm->debug = level;
}

static bool inline _scm_debug_enabled(uint64_t policy)
{
	return (scm->debug & policy) ? true : false;
}
#else
#define _scm_enable_debug(level)
#define _scm_debug_enabled(level) false
#endif // CONFIG_HONOR_SCM_DEBUG

static inline bool _scm_free_page_is_tiny(void)
{
	return (_scm_stat_get_free_pages() <
		atomic64_read(&scm->wm.nr_min_free));
}

static inline bool _scm_free_page_is_critical(void)
{
	return (_scm_stat_get_free_pages() <
		(atomic64_read(&scm->wm.nr_min_free) >> 1));
}

static inline bool _scm_file_page_is_tiny(void)
{
	return (_scm_stat_get_file_pages() <
		atomic64_read(&scm->wm.nr_min_file));
}

static inline bool _scm_anon_page_is_tiny(void)
{
	return (_scm_stat_get_anon_pages() <
		atomic64_read(&scm->wm.nr_min_anon));
}

static inline bool _scm_swap_free_page_is_tiny(void)
{
	return (_scm_stat_get_swap_free_pages() <
		atomic64_read(&scm->wm.nr_min_swap));
}

extern void __init scm_task_status_init(void);
extern void scm_task_status_show(char *buf, int len);
extern uint32_t scm_task_status_get(struct task_struct *task);
extern uint32_t scm_task_status_get2(struct task_struct *task, gfp_t gfp_mask);

extern void __init scm_watermark_init(void);
extern void scm_watermark_show(char *buf, int len);
extern void scm_wm_set_min_free(uint64_t value_mb);
extern void scm_wm_set_min_file(uint64_t value_mb);
extern void scm_wm_set_min_anon(uint64_t value_mb);
extern void scm_wm_set_min_swap(uint64_t value_mb);

extern void __init scm_mem_available_init(void);
extern void scm_mem_available_show(char *buf, int len);
extern void scm_mem_available_set(uint64_t value_mb);

extern void __init scm_reclaim_init(void);
extern void scm_reclaim_show(char *buf, int len);

extern void __init scm_shrinker_init(void);
extern void scm_shrinker_show(char *buf, int len);
extern void scm_shrinker_set_typed_wm(const char *buf);

extern void __init scm_qos_pool_init(void);
extern void scm_qos_pool_show(char *buf, int len);
extern void scm_qos_pool_set_low(bool movable, int watermark_mb);
extern void scm_qos_pool_set_high(bool movable, int watermark_mb);
extern void scm_qos_pool_enable(uint64_t policy);
extern long scm_qos_pool_used_pages(void);

extern void __init scm_misc_modules_init(void);
extern void scm_misc_modules_show(char *buf, int len);
extern void scm_bg_slowpath_set_factor(uint64_t factor);
extern void scm_fault_around_bytes_show(char *buf, int len);
extern void scm_fault_around_bytes_set(uint64_t size_bytes);

#endif /*_SCM_INTERNAL_H_*/
