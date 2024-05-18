/*
 * Copyright (C) 2020-2023 HONOR, Inc.
 * Smart Cache Manager helper
 * Author:
 * 		lizhiwei<lizhiwei3@hihonor.com>,
 * 		wangxin<wangxin23@honor.com>,
 * 		qiyichuan<qiyichuan@hihonor.com>,
 * 		yangxuzhe<yangxuzhe@hihonor.com>,
 * 		zhangzhongshi<zhangzhongshi@hihonor.com>
 *
 *  This file is for sub policies management.
 *
 */
#include "scm_common_inf.h"
#include "scm_internal.h"

#include <trace/hooks/cgroup.h>
#include <trace/hooks/mm.h>
#include <trace/hooks/vmscan.h>

ssize_t scm_event_store(struct kobject *kobj, struct kobj_attribute *attr,
			const char *buf, size_t len)
{
	uint64_t value = 0;
	if (STR_GET_U64(buf, "DEBUG=", &value)) {
		_scm_enable_debug(value);
	} else if (STR_GET_U64(buf, "ENABLE=", &value)) {
		_scm_enable(value);
		scm_qos_pool_enable(value);
	} else if (STR_GET_U64(buf, "FAULT_AROUND_BYTES=", &value)) {
		scm_fault_around_bytes_set(value);
	} else if (STR_GET_U64(buf, "BG_SLOWPATH_FACTOR=", &value)) {
		scm_bg_slowpath_set_factor(value);
	} else if (STR_GET_U64(buf, "WATERMARK_MIN_FREE=", &value)) {
		scm_wm_set_min_free(value);
	} else if (STR_GET_U64(buf, "WATERMARK_MIN_FILE=", &value)) {
		scm_wm_set_min_file(value);
	} else if (STR_GET_U64(buf, "WATERMARK_MIN_ANON=", &value)) {
		scm_wm_set_min_anon(value);
	} else if (STR_GET_U64(buf, "WATERMARK_MIN_SWAP=", &value)) {
		scm_wm_set_min_swap(value);
	} else if (STR_EQ(buf, "SHRINKER_TYPE_")) {
		scm_shrinker_set_typed_wm(buf + strlen("SHRINKER_TYPE_"));
	} else if (STR_GET_U64(buf, "AVAILABLE_RESERVED=", &value)) {
		scm_mem_available_set(value);
	} else if (STR_GET_U64(buf, "QOS_POOL_MO_MIN_PAGE=", &value)) {
		scm_qos_pool_set_low(true, (int)value);
	} else if (STR_GET_U64(buf, "QOS_POOL_MO_MAX_PAGE=", &value)) {
		scm_qos_pool_set_high(true, (int)value);
	} else if (STR_GET_U64(buf, "QOS_POOL_UN_MIN_PAGE=", &value)) {
		scm_qos_pool_set_low(false, (int)value);
	} else if (STR_GET_U64(buf, "QOS_POOL_UN_MAX_PAGE=", &value)) {
		scm_qos_pool_set_high(false, (int)value);
	} else {
		pr_err("scm: unknown event: [%s] size=%zu\n", buf, strlen(buf));
		return len;
	}
	return len;
}

ssize_t scm_event_show(struct kobject *kobj, struct kobj_attribute *attr,
		       char *buf)
{
	int len = PAGE_SIZE;
	*buf = '\0';

	snprintf(BUF, LEN, "enabled = 0x%llx\n", atomic64_read(&scm->enabled));
	snprintf(BUF, LEN, "debug = 0x%llx\n", scm->debug);
	scm_task_status_show(BUF, LEN);
	scm_fault_around_bytes_show(BUF, LEN);
	scm_mem_available_show(BUF, LEN);
	scm_reclaim_show(BUF, LEN);
	scm_shrinker_show(BUF, LEN);
	scm_qos_pool_show(BUF, LEN);
	scm_misc_modules_show(BUF, LEN);

	return strlen(buf);
}

static void scm_hook_si_mem_available(void *ignore, long *available)
{
	*available = scm_mem_available_update(*available);
}

static void scm_hook_shrink_slab_bypass(void *ignore, gfp_t gfp_mask, int nid,
					struct mem_cgroup *memcg, int prio,
					bool *bypass)
{
	*bypass = scm_reclaim_shrink_slab_bypass(gfp_mask, nid, memcg, prio);
}

static void scm_hook_do_shrink_slab(void *ignore, struct shrinker *shrinker,
				    long *freeable)
{
	*freeable = scm_shrinker_do_shrink_slab(shrinker, *freeable);
}

static void scm_hook_reclaim_sc(void *ignore, u64 *ext,
				unsigned long *nr_to_reclaim,
				struct mem_cgroup *target_mem_cgroup,
				bool *file_is_tiny, bool *may_writepage)
{
	scm_reclaim_update_scan_control(ext, nr_to_reclaim, target_mem_cgroup,
					file_is_tiny, may_writepage);
}

static void scm_hook_dr_path(void *ignore, u64 *ext)
{
	scm_reclaim_path_type_dr(ext);
}

static void scm_hook_continue_reclaim(void *ignore, u64 *ext,
				      unsigned long *nr_to_reclaim,
				      unsigned long *nr_reclaimed,
				      bool *continue_reclaim)
{
	scm_reclaim_should_continue(ext, nr_to_reclaim, nr_reclaimed,
				    continue_reclaim);
}

void scm_hook_alloc_pages(void *ignore, gfp_t alloc_gfp, int order,
			  int alloc_flags, int step, struct page **page)
{
	*page = scm_qos_pool_alloc_pages(alloc_gfp, order, alloc_flags, step);
}

void scm_hook_free_pages(void *ignore, struct page **page, unsigned int order,
			 unsigned long pfn, int migratetype, bool remove)
{
	if (scm_qos_pool_free_to_fill(*page, order, pfn, migratetype, remove)) {
		*page = NULL;
	}
}

void scm_hook_gfp_to_alloc_flags(void *ignore, gfp_t gfp_mask,
				 int *should_alloc_harder)
{
	*should_alloc_harder = scm_qos_alloc_harder_decide(current);
}

void scm_hook_buddy_rmqueue(void *ignore, int order, gfp_t gfp_mask,
			    bool *pcp_bypass)
{
	if (scm_qos_pcp_should_bypass(current)) {
		*pcp_bypass = true;
	}
}

static void scm_hook_do_fault_around(void *ignore, unsigned long *nr_pages)
{
	*nr_pages = scm_fault_around_bytes_get(*nr_pages);
}

#define SCM_REGISTER_HOOK(typ, func) \
	register_trace_android_##typ##_##func(scm_hook_##func, NULL)

void _scm_hooks_init(void)
{
	// for scm_reclaim policy
	SCM_REGISTER_HOOK(vh, shrink_slab_bypass);
	SCM_REGISTER_HOOK(rvh, do_shrink_slab);
	SCM_REGISTER_HOOK(rvh, reclaim_sc);
	SCM_REGISTER_HOOK(rvh, dr_path);
	SCM_REGISTER_HOOK(rvh, continue_reclaim);

	// for scm_qos_pool policy
	SCM_REGISTER_HOOK(rvh, alloc_pages);
	SCM_REGISTER_HOOK(rvh, free_pages);
	SCM_REGISTER_HOOK(rvh, gfp_to_alloc_flags);
	SCM_REGISTER_HOOK(rvh, buddy_rmqueue);

	// for scm misc sub_modules policy
	SCM_REGISTER_HOOK(rvh, do_fault_around);
	SCM_REGISTER_HOOK(rvh, si_mem_available);
}

void __init scm_sub_modules_init(void)
{
	scm_task_status_init();
	scm_watermark_init();
	scm_mem_available_init();

	scm_reclaim_init();
	scm_shrinker_init();
	scm_qos_pool_init();
	scm_misc_modules_init();

	_scm_hooks_init();
	_scm_enable(POLICY_DEFAULT);
}
