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
 *  This file is for qos reclaim policy.
 *
 */
#include "scm_internal.h"

// for shrink_node process.
enum scm_shrink_mode {
	SHRINK_MODE_DEFAULT = 0,
	SHRINK_MODE_FORCE_SLAB, // force shrink slab.
	SHRINK_MODE_SLOW,
	SHRINK_MODE_FAST,
	SHRINK_MODE_VIP,
	SHRINK_MODE_MAX,
};

enum scm_reclaim_invoker {
	ALL,
	KSWAPD,
	DIRECT_RECLAIM,
	NODE_RECLAIM,
	SOFT_LIMIT,
	RCC_RECLAIM,
	FILE_RECLAIM,
	ANON_RECLAIM,
	PROCESS_RECLAIM,
	OTHER_RECLAIM
};

//do not largger than the size of u64!
typedef struct _scm_sc_ext_u64 {
	u64 scm_quick_mode : 4;
	u64 invoker : 4;
} scm_sc_ext_u64;
STATIC_ASSERT(sizeof(scm_sc_ext_u64) <= sizeof(u64));

typedef struct _scm_scan_control {
	atomic64_t nr_min_anon_pages;
	atomic64_t nr_min_file_pages;
	atomic64_t total_count;
	atomic64_t memcg_count;
	atomic64_t global_count;
	atomic64_t kernel_count;
	atomic64_t user_count;
	atomic64_t kswapd_count;
	atomic64_t direct_count;
	atomic64_t slab_shrink_count;
	atomic64_t slab_bypass_count;
} scm_scan_control;

static scm_scan_control g_scm_sc;
static scm_scan_control *scm_sc = &g_scm_sc;

bool scm_reclaim_enabled(void)
{
	return _scm_enabled(POLICY_RECLAIM_TYPE) ? true : false;
}

#define SCM_MEMCGP_SKIP 8
static inline bool _scm_global_reclaim(struct mem_cgroup *memcg)
{
	// do nothing with root memcg, and we treat memcg which id less than 8 as root memcg.
	return (!memcg) || (memcg->id.id < SCM_MEMCGP_SKIP);
}

static inline int _scm_reclaim_memcg_id(struct mem_cgroup *memcg)
{
	return memcg ? memcg->id.id : -1;
}

static inline void _scm_config_to_reclaim_anon(bool *file_is_tiny)
{
	*file_is_tiny = true;
}

bool scm_reclaim_should_shrink_slab(u64 ext)
{
	scm_sc_ext_u64 *sc_ext_u64 = (scm_sc_ext_u64 *)(ext);
	if (!sc_ext_u64)
		return true;

	if (!_scm_enabled(POLICY_RECLAIM_TYPE)) {
		return true;
	}
	if (sc_ext_u64->scm_quick_mode == SHRINK_MODE_FORCE_SLAB) {
		return true;
	}
	return (sc_ext_u64->scm_quick_mode >= SHRINK_MODE_FAST) ? false : true;
}

bool _scm_reclaim_node_should_continue(u64 *ext, unsigned long *nr_to_reclaim,
				       unsigned long *nr_reclaimed)
{
	scm_sc_ext_u64 *sc_ext_u64 = (scm_sc_ext_u64 *)(ext);
	if (!sc_ext_u64)
		return true;

	if (!_scm_enabled(POLICY_RECLAIM_TYPE)) {
		return true;
	}
#ifdef CONFIG_HONOR_SCM_DEBUG
	if (_scm_debug_enabled(POLICY_RECLAIM_TYPE)) {
		pr_info("scm: sc shoulud continue scm_quick_mode=%d\n",
			sc_ext_u64->scm_quick_mode);
	}
#endif
	if (sc_ext_u64->scm_quick_mode == SHRINK_MODE_DEFAULT) {
		return true;
	}
	if (sc_ext_u64->scm_quick_mode >= SHRINK_MODE_VIP) {
		return (*nr_reclaimed >= *nr_to_reclaim) ? false : true;
	}
	return true;
}

void scm_reclaim_should_continue(u64 *ext, unsigned long *nr_to_reclaim,
				 unsigned long *nr_reclaimed,
				 bool *continue_reclaim)
{
	*continue_reclaim = _scm_reclaim_node_should_continue(
		ext, nr_to_reclaim, nr_reclaimed);
}

void _scm_qos_update_dr_scan_control(scm_sc_ext_u64 *sc_ext,
				     unsigned long *nr_to_reclaim,
				     uint32_t im_status, bool *file_is_tiny,
				     bool *may_writepage)
{
	if (_scm_file_page_is_tiny()) {
		_scm_config_to_reclaim_anon(file_is_tiny);
	}
	if (im_status & SCM_IMST_MM_MMAPLOCKED) {
		sc_ext->scm_quick_mode = SHRINK_MODE_VIP;
		*nr_to_reclaim = min(*nr_to_reclaim, SWAP_CLUSTER_MAX / 8);
		*may_writepage = false;
	} else if (im_status & (SCM_IMST_PRIO_VIP | SCM_IMST_PRIO_GC)) {
		sc_ext->scm_quick_mode = SHRINK_MODE_VIP;
		*may_writepage = false;
		if (!_scm_task_is_rt(current)) {
			*nr_to_reclaim = min(*nr_to_reclaim, SWAP_CLUSTER_MAX / 2);
		}
	} else if (im_status & (SCM_IMST_PROC_FOREGROUND)) {
		sc_ext->scm_quick_mode = SHRINK_MODE_FAST;
		*may_writepage = false;
		if (!_scm_task_is_rt(current)) {
			*nr_to_reclaim = min(*nr_to_reclaim, SWAP_CLUSTER_MAX / 2);
		}
	} else if (im_status & SCM_IMST_PROC_FOREGROUND_RELATED) {
		*nr_to_reclaim = max(*nr_to_reclaim, SWAP_CLUSTER_MAX * 2);
	} else if (im_status & SCM_IMST_PROC_BACKGROUND) {
		sc_ext->scm_quick_mode = SHRINK_MODE_SLOW;
		_scm_config_to_reclaim_anon(file_is_tiny);
		*nr_to_reclaim = max(*nr_to_reclaim + SWAP_CLUSTER_MAX,
				     SWAP_CLUSTER_MAX * 2);
	}
}

void _scm_qos_update_kswapd_scan_control(scm_sc_ext_u64 *sc_ext,
					 bool *file_is_tiny,
					 unsigned long *nr_to_reclaim)
{
#ifdef CONFIG_HONOR_SCM_DEBUG
	if (_scm_debug_enabled(POLICY_RECLAIM_TYPE)) {
		pr_info("scm: kswapd_sc=%lld, dr_sc=%lld, file_is_tiny=%d, reclaim=%d, swap_free=%d, anon=%d, free=%d\n",
			atomic64_read(&scm_sc->kswapd_count),
			atomic64_read(&scm_sc->direct_count), *file_is_tiny,
			PAGE2MB(*nr_to_reclaim),
			PAGE2MB(_scm_stat_get_swap_free_pages()),
			PAGE2MB(_scm_stat_get_anon_pages()),
			PAGE2MB(_scm_stat_get_free_pages()));
	}
#endif
}

void _scm_qos_update_oth_scan_control(scm_sc_ext_u64 *sc_ext,
				      unsigned long *nr_to_reclaim,
				      struct mem_cgroup *target_mem_cgroup,
				      bool *may_writepage)
{
	if (!*may_writepage) {
		return;
	}
	if (!_scm_global_reclaim(target_mem_cgroup)) {
		return;
	}
	*nr_to_reclaim = max(*nr_to_reclaim + SWAP_CLUSTER_MAX * 2,
			     SWAP_CLUSTER_MAX * 3);
}

static inline void
_scm_reclaim_update_scan_control(u64 *ext, unsigned long *nr_to_reclaim,
				 struct mem_cgroup *target_mem_cgroup,
				 bool *file_is_tiny, bool *may_writepage)
{
	uint32_t im_status;
	scm_sc_ext_u64 *sc_ext_u64 = (scm_sc_ext_u64 *)(ext);

	sc_ext_u64->scm_quick_mode = SHRINK_MODE_DEFAULT;
	atomic64_inc(&scm_sc->total_count);
	atomic64_inc(_scm_is_kernel_thread(current) ? &scm_sc->kernel_count :
						      &scm_sc->user_count);
	atomic64_inc(_scm_global_reclaim(target_mem_cgroup) ?
			     &scm_sc->global_count :
			     &scm_sc->memcg_count);

	if (!_scm_enabled(POLICY_RECLAIM_TYPE)) {
		return;
	}

	im_status = scm_task_status_get(current);
	if (sc_ext_u64->invoker == DIRECT_RECLAIM) {
		atomic64_inc(&scm_sc->direct_count);
		_scm_qos_update_dr_scan_control(sc_ext_u64, nr_to_reclaim,
						im_status, file_is_tiny,
						may_writepage);
	} else if (current_is_kswapd()) {
		atomic64_inc(&scm_sc->kswapd_count);
		_scm_qos_update_kswapd_scan_control(sc_ext_u64, file_is_tiny,
						    nr_to_reclaim);
	} else {
		_scm_qos_update_oth_scan_control(sc_ext_u64, nr_to_reclaim,
						 target_mem_cgroup,
						 may_writepage);
	}
#ifdef CONFIG_HONOR_SCM_DEBUG
	if (_scm_debug_enabled(POLICY_RECLAIM_TYPE)) {
		pr_info("scm: sc invoker=%d, scm_quick_mode=%d, file_is_tiny=%d, may_writepage=%d\n",
			sc_ext_u64->invoker, sc_ext_u64->scm_quick_mode,
			*file_is_tiny, *may_writepage);
	}
#endif
}

void scm_reclaim_update_scan_control(u64 *ext, unsigned long *nr_to_reclaim,
				     struct mem_cgroup *target_mem_cgroup,
				     bool *file_is_tiny, bool *may_writepage)
{
	_scm_reclaim_update_scan_control(ext, nr_to_reclaim, target_mem_cgroup,
					 file_is_tiny, may_writepage);
}

void scm_reclaim_path_type_dr(u64 *ext)
{
	scm_sc_ext_u64 *sc_ext_u64 = (scm_sc_ext_u64 *)(ext);
	sc_ext_u64->invoker = DIRECT_RECLAIM;
}

#ifdef CONFIG_HONOR_SCM_DEBUG
static inline void
_scm_reclaim_shrink_node_update_counter(struct mem_cgroup *target_memcg)

{
	atomic64_inc(&scm_sc->total_count);
	atomic64_inc(_scm_is_kernel_thread(current) ? &scm_sc->kernel_count :
						      &scm_sc->user_count);
	atomic64_inc(_scm_global_reclaim(target_memcg) ? &scm_sc->global_count :
							 &scm_sc->memcg_count);
	atomic64_inc(current_is_kswapd() ? &scm_sc->kswapd_count :
					   &scm_sc->direct_count);
}
#else
#define _scm_reclaim_shrink_node_update_counter(target_memcg)
#endif

bool scm_reclaim_shrink_slab_bypass(gfp_t gfp_mask, int nid,
				    struct mem_cgroup *memcg, int priority)
{
	if (!_scm_enabled(POLICY_RECLAIM_TYPE)) {
		return false;
	}
	if (current_is_kswapd()) {
		return false;
	}
	return true;
}

void scm_reclaim_show(char *buf, int len)
{
	snprintf(
		BUF, LEN,
		"reclaim_called: [total = %llu, direct = %llu, kswapd = %llu, kernel = %llu, user = %llu]\n",
		atomic64_read(&scm_sc->total_count),
		atomic64_read(&scm_sc->direct_count),
		atomic64_read(&scm_sc->kswapd_count),
		atomic64_read(&scm_sc->kernel_count),
		atomic64_read(&scm_sc->user_count));
	snprintf(BUF, LEN, "shrink_slab: [shrinked = %llu, bypass = %llu]\n",
		 atomic64_read(&scm_sc->slab_shrink_count),
		 atomic64_read(&scm_sc->slab_bypass_count));
}

void __init scm_reclaim_init(void)
{
	return;
}