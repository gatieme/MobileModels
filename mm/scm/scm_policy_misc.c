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
 *  This file is for misc policies.
 *
 */
#include "scm_internal.h"

// ==================== scm qos alloc harder module =======================

#define ST_ORG_POLICY_USED (-1)
#define ST_SCM_POLICY_ALLOC_NORMAL (0)
#define ST_SCM_POLICY_ALLOC_VIP (1)
int scm_qos_alloc_harder_decide(struct task_struct *task)
{
	uint32_t im_status;
	if (!_scm_enabled(POLICY_SCM_ALLOC_HARDER)) {
		return ST_ORG_POLICY_USED;
	}
	im_status = scm_task_status_get(task);
	if (im_status & (SCM_IMST_PRIO_VIP | SCM_IMST_MM_MMAPLOCKED)) {
		return ST_SCM_POLICY_ALLOC_VIP;
	}
	if ((im_status & (SCM_IMST_PROC_FOREGROUND | SCM_IMST_PRIO_LOW)) ==
	    SCM_IMST_PROC_FOREGROUND) {
		return ST_SCM_POLICY_ALLOC_VIP;
	}
	return ST_SCM_POLICY_ALLOC_NORMAL;
}

// ==================== pcp qos module =======================

struct _scm_pcp_qos {
	int alloc;
	int bypass;
};

static struct _scm_pcp_qos g_scm_pcp_qos;
static struct _scm_pcp_qos *scm_pcp_qos = &g_scm_pcp_qos;

bool scm_qos_pcp_should_bypass(struct task_struct *task)
{
	uint32_t im_status;
	if (!_scm_enabled(POLICY_QOS_PCP)) {
		return false;
	}
	im_status = scm_task_status_get(task);
	if (im_status & (SCM_IMST_PROC_FOREGROUND | SCM_IMST_PRIO_VIP |
			 SCM_IMST_MM_MMAPLOCKED)) {
		scm_pcp_qos->alloc++;
		return false;
	}
	if ((im_status &
	     (SCM_IMST_PROC_FOREGROUND_RELATED | SCM_IMST_PRIO_LOW)) ==
	    SCM_IMST_PROC_FOREGROUND_RELATED) {
		scm_pcp_qos->alloc++;
		return false;
	}
	scm_pcp_qos->bypass++;
	return true;
}

void scm_qos_pcp_show(char *buf, int len)
{
	snprintf(BUF, LEN, "pcp: alloc= %d, bypass = %d\n",
		 scm_pcp_qos->alloc, scm_pcp_qos->bypass);
}

// ==================== background slowpath module =======================
#define SCM_BG_SLOWPATH_FACTOR_DEFAULT 4

struct _scm_bg_slowpath {
	atomic64_t factor;
	atomic64_t total_check;
	atomic64_t reclaim_count;
};

static struct _scm_bg_slowpath g_bg_slowpath = { 0 };
static struct _scm_bg_slowpath *scm_bg_slowpath = &g_bg_slowpath;

static __always_inline bool
_scm_bg_slowpath_can_do(gfp_t gfp_mask, unsigned int order, int alloc_flags)
{
	if (order != 0)
		return false;
	// GFP_KERNEL = (__GFP_RECLAIM | __GFP_IO | __GFP_FS)
	if ((gfp_mask & GFP_KERNEL) != GFP_KERNEL) {
		return false;
	}
	return true;
}

static inline bool _scm_bg_slowpath_should_do(struct task_struct *task,
					      uint32_t im_status)
{
	if (unlikely(im_status == SCM_IMST_INVALID)) {
		return false;
	}
	// is high prio or fg
	if (im_status &
	    (SCM_IMST_PRIO_VIP | SCM_IMST_PRIO_GC | SCM_IMST_PROC_FOREGROUND |
	     SCM_IMST_PROC_FOREGROUND_RELATED | SCM_IMST_MM_MMAPLOCKED)) {
		return false;
	}
	return true;
}

bool scm_bg_slowpath_should_do(uint32_t im_status, gfp_t gfp_mask,
			       unsigned int order, int alloc_flags)
{
	uint64_t total_check;
	if (!_scm_enabled(POLICY_QOS_BACKGROUND_SLOWPATH)) {
		return false;
	}
	if (!_scm_free_page_is_tiny()) {
		return false;
	}
	if (!_scm_bg_slowpath_can_do(gfp_mask, order, alloc_flags)) {
		return false;
	}
	if (!_scm_bg_slowpath_should_do(current, im_status)) {
		return false;
	}
	total_check = atomic64_inc_return(&scm_bg_slowpath->total_check);
	if ((total_check % atomic64_read(&scm_bg_slowpath->factor)) > 0) {
		return false;
	}
	atomic64_inc(&scm_bg_slowpath->reclaim_count);
	return true;
}

void scm_bg_slowpath_show(char *buf, int len)
{
	snprintf(BUF, LEN,
		 "bg_slowpath = [factor = %llu, total = %llu, slow = %llu]\n",
		 atomic64_read(&scm_bg_slowpath->factor),
		 atomic64_read(&scm_bg_slowpath->total_check),
		 atomic64_read(&scm_bg_slowpath->reclaim_count));
}

void scm_bg_slowpath_set_factor(uint64_t factor)
{
	if (factor == 0) {
		pr_err("scm: set_bg_slowpath_factor(%llu), invalid args.\n",
		       factor);
		return;
	}
#ifdef CONFIG_HONOR_SCM_DEBUG
	pr_info("scm: set_bg_slowpath_factor(%llu -> %llu).\n",
		atomic64_read(&scm_bg_slowpath->factor), factor);
#endif
	atomic64_set(&scm_bg_slowpath->factor, factor);
}

static void __init scm_bg_slowpath_init(void)
{
	atomic64_set(&scm_bg_slowpath->factor, SCM_BG_SLOWPATH_FACTOR_DEFAULT);
}

// ==================== fault_around_bytes module =======================
#define MAX_VALID_FAULT_AROUND_SIZE rounddown_pow_of_two(PAGE_SIZE * 64)
static unsigned long fault_around_bytes_vip __read_mostly =
	rounddown_pow_of_two(32768);

static unsigned long scm_fault_around_bytes_get_dynamic(unsigned long nr_pages)
{
	uint32_t im_status;
	unsigned long vip_nr_pages;
	vip_nr_pages = fault_around_bytes_vip >> PAGE_SHIFT;
	if (vip_nr_pages <= nr_pages || !_scm_enabled(POLICY_FAULT_AROUND)) {
		return nr_pages;
	}
	im_status = scm_task_status_get(current);
	if (!_scm_free_page_is_tiny() &&
	    (im_status & (SCM_IMST_PROC_FOREGROUND | SCM_IMST_PRIO_VIP)) ==
		    (SCM_IMST_PROC_FOREGROUND | SCM_IMST_PRIO_VIP)) {
		return vip_nr_pages;
	}
	return nr_pages;
}

void scm_fault_around_bytes_set(uint64_t size_bytes)
{
	size_bytes = rounddown_pow_of_two(size_bytes);
	if (size_bytes < PAGE_SIZE) {
		size_bytes = 0;
	} else if (size_bytes > MAX_VALID_FAULT_AROUND_SIZE) {
		size_bytes = MAX_VALID_FAULT_AROUND_SIZE;
	}
	fault_around_bytes_vip = size_bytes;
#ifdef CONFIG_HONOR_SCM_DEBUG
	pr_info("scm: scm_set_dynamic_fault_around_bytes: %ld.\n", size_bytes);
#endif
}

unsigned long scm_fault_around_bytes_get(unsigned long nr_pages)
{
	return scm_fault_around_bytes_get_dynamic(nr_pages);
}

void scm_fault_around_bytes_show(char *buf, int len)
{
	snprintf(BUF, LEN, "fault_around_bytes_ex = %ld B\n",
		 fault_around_bytes_vip);
}

// ================= misc modules ========================
void scm_misc_modules_show(char *buf, int len)
{
	scm_bg_slowpath_show(BUF, LEN);
	scm_fault_around_bytes_show(BUF, LEN);
	scm_qos_pcp_show(BUF, LEN);
}

void __init scm_misc_modules_init(void)
{
	scm_bg_slowpath_init();
}