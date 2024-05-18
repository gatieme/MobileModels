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
 *  This file is for internal function/globals.
 *
 */
#include "scm_internal.h"

// ==============  scm global ================

static smart_cache_manager _g_scm = { 0 };
smart_cache_manager *scm = &_g_scm;

// ==============  watermark ================

#define BG_WATERMARK_MIN_FREE 128 // in mB
#define BG_WATERMARK_MIN_FILE 512 // in mB
#define BG_WATERMARK_MIN_ANON 1280 // in mB
#define BG_WATERMARK_MIN_SWAP 512 // in mB

static void __scm_watermark_set(const char *name, atomic64_t *p,
				uint64_t value_mb)
{
	uint64_t min_pages = MB2PAGE(value_mb);
	if (min_pages == 0) {
		pr_err("scm: set_watermark_%s(%llu) mB, invalid args.\n", name,
		       value_mb);
		return;
	}
#ifdef CONFIG_HONOR_SCM_DEBUG
	pr_info("scm: set_watermark_%s(%llu -> %llu) mB.\n", name,
		PAGE2MB(atomic64_read(p)), PAGE2MB(min_pages));
#endif
	atomic64_set(p, min_pages);
}

void scm_wm_set_min_free(uint64_t value_mb)
{
	__scm_watermark_set("min_free", &scm->wm.nr_min_free, value_mb);
}

void scm_wm_set_min_file(uint64_t value_mb)
{
	__scm_watermark_set("min_file", &scm->wm.nr_min_file, value_mb);
}

void scm_wm_set_min_anon(uint64_t value_mb)
{
	__scm_watermark_set("min_anon", &scm->wm.nr_min_anon, value_mb);
}

void scm_wm_set_min_swap(uint64_t value_mb)
{
	__scm_watermark_set("min_swap", &scm->wm.nr_min_swap, value_mb);
}

void scm_watermark_show(char *buf, int len)
{
	snprintf(
		BUF, LEN,
		"tiny_min_watermark = [swap = %llu, file = %llu, anon = %llu, free "
		"= %llu] mB\n",
		PAGE2MB(atomic64_read(&scm->wm.nr_min_swap)),
		PAGE2MB(atomic64_read(&scm->wm.nr_min_file)),
		PAGE2MB(atomic64_read(&scm->wm.nr_min_anon)),
		PAGE2MB(atomic64_read(&scm->wm.nr_min_free)));
}

void __init scm_watermark_init(void)
{
	scm_wm_set_min_free(BG_WATERMARK_MIN_FREE);
	scm_wm_set_min_file(BG_WATERMARK_MIN_FILE);
	scm_wm_set_min_anon(BG_WATERMARK_MIN_ANON);
	scm_wm_set_min_swap(BG_WATERMARK_MIN_SWAP);
}

// ==============  mem_available ================
#define SCM_AVAILABLE_RESERVED_DEFAULT 100 // in mB
#define SCM_AVAILABLE_MAX_RESERVED 2000 // in mB

static long _scm_mem_available_update(long available)
{
	long keep_more_as_used = 0;

	if (!_scm_enabled(POLICY_RESERVE_MIN_CACHE)) {
		return available;
	}
	if (keep_more_as_used >
	    (long)atomic64_read(&scm->available.nr_max_reserved)) {
		keep_more_as_used =
			(long)atomic64_read(&scm->available.nr_max_reserved);
	}
	available -= keep_more_as_used;
	if (_scm_free_page_is_tiny()) {
		available -= MB2PAGE(60);
	}
	if (available < 0)
		available = 0;
	return available;
}

void scm_mem_available_show(char *buf, int len)
{
	snprintf(BUF, LEN, "max_available_reserved = %llu mB\n",
		 PAGE2MB(atomic64_read(&scm->available.nr_max_reserved)));
	snprintf(BUF, LEN, "mem_available_called = %lld\n",
		 atomic64_read(&scm->available.count));
}

void scm_mem_available_set(uint64_t value_mb)
{
	if (value_mb > SCM_AVAILABLE_MAX_RESERVED) {
		pr_err("scm: invalid mem_available: %llu\n", value_mb);
		return;
	}
	atomic64_set(&scm->available.nr_max_reserved, MB2PAGE(value_mb));
}

// available: in page unit.
long scm_mem_available_update(long available)
{
	long ret, count;
	count = atomic64_inc_return(&scm->available.count);
	available += scm_qos_pool_used_pages();

	if (!_scm_enabled(POLICY_RESERVE_AVAILABLE)) {
		return available;
	}
	ret = _scm_mem_available_update(available);

	if (_scm_debug_enabled(POLICY_RESERVE_AVAILABLE)) {
		pr_info("scm: mem_available(count: %ld, from: %ld, to: %ld) diff=%ld.\n",
			count, available, ret, available - ret);
	}
	return ret;
}

void __init scm_mem_available_init(void)
{
	atomic64_set(&scm->available.nr_max_reserved,
		     MB2PAGE(SCM_AVAILABLE_RESERVED_DEFAULT));
}