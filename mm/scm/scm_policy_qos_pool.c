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
 *  This file is for qos pool policy.
 *
 */
#include "scm_internal.h"
#include <linux/delay.h>
#include <linux/sched/stat.h>
#include <uapi/linux/sched/types.h>

/*
*	qos pool
*/
#define SCM_QOS_POOL_MAX_WATERMARK (1000 * SZ_1M)
#define SCM_QOS_POOL_HIGH_WATERMARK_UN (80 * SZ_1M)
#define SCM_QOS_POOL_LOW_WATERMARK_UN (30 * SZ_1M)
#define SCM_QOS_POOL_HIGH_WATERMARK_MO (80 * SZ_1M)
#define SCM_QOS_POOL_LOW_WATERMARK_MO (30 * SZ_1M)
#define SCM_QOS_POOL_NICE (15)
#define SCM_QOS_KSWAPD_NICE (-2)

// SCM qos pool return code
#define SCM_SUCCESS (0)
#define SCM_NEED_RETRY (1)
#define SCM_COMMON_ERRNO (-1)
#define SCM_FILL_POOL_ERRNO (-2)
#define SCM_FREE_TINY_ERRNO (-3)
#define SCM_ORDER_NOT_MATCH_ERRNO (-4)
#define SCM_FLAG_NOT_MATCH_ERRNO (-5)
#define SCM_POOL_FULL_ERRNO (-6)

// #define SCM_CONFIG_HAS_FILL_WORKER

typedef struct _scm_qos_page_pool {
	struct list_head high_items;
	struct list_head low_items;
	gfp_t gfp_mask;
	gfp_t gfp_allowed;
	unsigned int order;
	atomic_t high_watermark;
	atomic_t low_watermark;

	int high_count;
	int low_count;
	atomic_t count;
	atomic64_t work_filled_count;
	atomic64_t free_filled_count;
	atomic64_t allocated0_count;
	atomic64_t allocated1_count;
	atomic64_t bypass0_count;
	atomic64_t bypass1_count;
	atomic64_t alloc_fail_count;
#ifdef CONFIG_HONOR_SCM_DEBUG
	unsigned long pass_reasons[10];
#endif
} scm_qos_page_pool;

typedef struct _scm_qos_pool {
	scm_qos_page_pool m;
	scm_qos_page_pool u;
	struct task_struct *fill_worker;
	unsigned long freed_count[MIGRATE_TYPES + 16];
} scm_qos_pool;

static struct _scm_qos_pool g_scm_qos_pool;
static struct _scm_qos_pool *scm_qp = &g_scm_qos_pool;

// limit: not suitable for numa architecture
#ifdef CONFIG_NUMA
#error("should be check")
#endif

#ifndef CONFIG_ARM64
#error("should be check")
#endif

#define QOS_POOL_REFILL_WAKEUP_LIMIT_MS 10
#define GFP_POOL_ALLOC_FLAG (GFP_USER | __GFP_MOVABLE)

static DEFINE_SPINLOCK(scm_qos_lock);
#define SCM_QOS_LOCK() spin_lock_irqsave(&scm_qos_lock, scm_qos_lock_flag)
#define SCM_QOS_UNLOCK() \
	spin_unlock_irqrestore(&scm_qos_lock, scm_qos_lock_flag)

static gfp_t QOS_POOL_GFP_FILL_MOVABLE =
	(GFP_HIGHUSER_MOVABLE | __GFP_ZERO | __GFP_NOWARN | __GFP_NORETRY) &
	~__GFP_RECLAIM;
static gfp_t QOS_POOL_GFP_FILL_UNMOVABLE =
	(GFP_HIGHUSER | __GFP_ZERO | __GFP_NOWARN | __GFP_NORETRY) &
	~__GFP_RECLAIM;
// static gfp_t QOS_POOL_GFP_ALLOC_UNMOVABLE = (GFP_USER);
// static gfp_t QOS_POOL_GFP_ALLOC_MOVABLE = (GFP_USER | __GFP_MOVABLE);
static gfp_t QOS_POOL_GFP_ALLOC_UNMOVABLE =
	(__GFP_HARDWALL); // only simple check.
static gfp_t QOS_POOL_GFP_ALLOC_MOVABLE = (__GFP_HARDWALL | __GFP_MOVABLE);

static void scm_qos_pool_add_page(scm_qos_page_pool *pool, struct page *page)
{
	unsigned long scm_qos_lock_flag;

	SCM_QOS_LOCK();
	if (PageHighMem(page)) {
		list_add_tail(&page->lru, &pool->high_items);
		pool->high_count++;
	} else {
		list_add_tail(&page->lru, &pool->low_items);
		pool->low_count++;
	}
	atomic_inc(&pool->count);
	SCM_QOS_UNLOCK();
}

static struct page *scm_qos_pool_remove_page(scm_qos_page_pool *pool)
{
	unsigned long scm_qos_lock_flag;
	struct page *page = NULL;

	SCM_QOS_LOCK();

	if (pool->high_count > 0) {
		page = list_first_entry(&pool->high_items, struct page, lru);
		pool->high_count--;
	} else if (pool->low_count > 0) {
		page = list_first_entry(&pool->low_items, struct page, lru);
		pool->low_count--;
	} else {
		//BUG();
		SCM_QOS_UNLOCK();
		return NULL;
	}
	atomic_dec(&pool->count);
	list_del(&page->lru);
	SCM_QOS_UNLOCK();

	return page;
}

static __always_inline int scm_qos_pool_high_watermark(scm_qos_page_pool *pool)
{
	return atomic_read(&pool->high_watermark);
}

static __always_inline int scm_qos_pool_low_watermark(scm_qos_page_pool *pool)
{
	return atomic_read(&pool->low_watermark);
}

static __always_inline bool scm_qos_pool_is_full(scm_qos_page_pool *pool)
{
	return atomic_read(&pool->count) >= scm_qos_pool_high_watermark(pool);
}

static __always_inline bool scm_qos_pool_is_half_full(scm_qos_page_pool *pool)
{
	uint64_t half = (scm_qos_pool_high_watermark(pool) +
			 scm_qos_pool_low_watermark(pool)) >> 1;
	return atomic_read(&pool->count) >= half;
}

static __always_inline bool pool_count_is_zero(scm_qos_page_pool *pool)
{
	return atomic_read(&pool->count) == 0;
}

static __always_inline bool pool_count_is_low(scm_qos_page_pool *pool)
{
	return atomic_read(&pool->count) < scm_qos_pool_low_watermark(pool);
}

static __always_inline bool pool_count_is_critical(scm_qos_page_pool *pool)
{
	return atomic_read(&pool->count) <
	       (scm_qos_pool_low_watermark(pool) >> 1);
}

#ifdef SCM_CONFIG_HAS_FILL_WORKER

static int _scm_qos_pool_fill_once(scm_qos_page_pool *pool, int nr_total_pages)
{
	int nr_pages;
	struct page *page;
	gfp_t gfp_fill = (pool->gfp_mask | __GFP_RECLAIM) & ~__GFP_NORETRY;
	for (nr_pages = 0; nr_pages < nr_total_pages; nr_pages++) {
		page = alloc_pages(gfp_fill, pool->order);
		if (!page) {
			return SCM_FILL_POOL_ERRNO;
		}
		scm_qos_pool_add_page(pool, page);
		atomic64_inc(&pool->work_filled_count);
	}
	return SCM_SUCCESS;
}

static int _scm_qos_pool_try_fill_once(scm_qos_page_pool *pool,
				       int nr_total_pages)
{
	if (scm_qos_pool_is_full(pool)) {
		return SCM_POOL_FULL_ERRNO;
	}
	if (_scm_stat_cpu_busy() || _scm_free_page_is_tiny()) {
		msleep(1);
		return SCM_NEED_RETRY;
	}
	if (_scm_qos_pool_fill_once(pool, nr_total_pages) < 0) {
		return SCM_FILL_POOL_ERRNO;
	}
	return SCM_NEED_RETRY;
}

static bool scm_qos_pool_should_be_clean(scm_qos_pool *qp)
{
	if (atomic_read(&qp->u.count) <= 0 && atomic_read(&qp->m.count) <= 0) {
		return false;
	}
	if (!_scm_enabled(POLICY_QOS_POOL_STEP0 | POLICY_QOS_POOL_STEP1)) {
		return true;
	}
	return false;
}

static void scm_qos_pool_fill(scm_qos_pool *qp)
{
	int ret;
	do {
		ret = _scm_qos_pool_try_fill_once(&qp->m, 512);
		ret += _scm_qos_pool_try_fill_once(&qp->u, 512);
		cond_resched();
	} while (ret > 0 && !scm_qos_pool_should_be_clean(qp));
}

static void scm_qos_clean_one_pool(scm_qos_page_pool *pool)
{
	struct page *page;

	while (atomic_read(&pool->count) > 0) {
		page = scm_qos_pool_remove_page(pool);
		if (!page) {
			break;
		}
		__free_pages(page, pool->order);
		atomic64_dec(&pool->work_filled_count);
	}
}

static void scm_qos_pool_clean(scm_qos_pool *qp)
{
	scm_qos_clean_one_pool(&qp->u);
	scm_qos_clean_one_pool(&qp->m);
}

static bool scm_qos_pool_should_be_fill(scm_qos_pool *qp)
{
	if (!_scm_enabled(POLICY_QOS_POOL_STEP0 | POLICY_QOS_POOL_STEP1)) {
		return false;
	}
	return pool_count_is_low(&qp->m) || pool_count_is_low(&qp->u);
}

int scm_qos_pool_fill_worker(void *data)
{
	scm_qos_pool *qp = (scm_qos_pool *)data;

	for (;;) {
		// TODO: add more running limit here.
		if (scm_qos_pool_should_be_fill(qp)) {
			scm_qos_pool_fill(qp);
		}
		if (scm_qos_pool_should_be_clean(qp)) {
			scm_qos_pool_clean(qp);
		}
		set_current_state(TASK_INTERRUPTIBLE);
		if (unlikely(kthread_should_stop())) {
			set_current_state(TASK_RUNNING);
			break;
		}
		schedule();
		set_current_state(TASK_RUNNING);
	}

	return 0;
}

static __always_inline bool is_scm_qos_pool_fill_worker(scm_qos_pool *qp)
{
	if (qp->fill_worker == NULL)
		return false;
	return (current->pid == qp->fill_worker->pid) ? true : false;
}

static void scm_qos_pool_wakeup_fill_worker(scm_qos_pool *qp)
{
	static ktime_t last_wakeup_ktime = 0;
	if (!qp->fill_worker ||
	    !_scm_enabled(POLICY_QOS_POOL_STEP0 | POLICY_QOS_POOL_STEP1)) {
		return;
	}
	if (ktime_ms_delta(ktime_get(), last_wakeup_ktime) <
	    QOS_POOL_REFILL_WAKEUP_LIMIT_MS) {
		return;
	}

	last_wakeup_ktime = ktime_get();
	wake_up_process(qp->fill_worker);
}

static struct task_struct *
scm_qos_pool_create_fill_worker(scm_qos_pool *qos_pool)
{
	struct task_struct *thread;

	thread = kthread_run(scm_qos_pool_fill_worker, qos_pool,
			     "scm-qos-worker");
	if (IS_ERR(thread)) {
		pr_err("%s: failed to create worker thread: %ld\n", __func__,
		       PTR_ERR(thread));
		return NULL;
	}

	set_user_nice(thread, SCM_QOS_POOL_NICE);
	return thread;
}
#else
#define is_scm_qos_pool_fill_worker(qp) false
#define scm_qos_pool_wakeup_fill_worker(qp)
#define scm_qos_pool_create_fill_worker(qp) NULL
#endif

static __always_inline struct page *
_scm_qos_alloc_page_from_pool(scm_qos_page_pool *pool)
{
	return scm_qos_pool_remove_page(pool);
}

static __always_inline bool
_scm_qos_pool_page_flags_matched(scm_qos_page_pool *pool, gfp_t gfp_mask,
				 unsigned int order, int alloc_flags)
{
	if (gfp_mask & (___GFP_DMA | ___GFP_DMA32)) {
		return false;
	}
	if ((gfp_mask & pool->gfp_allowed) != pool->gfp_allowed) {
		return false;
	}
	return true;
}

static inline bool __scm_qos_allow_alloc_from_pool(scm_qos_page_pool *pool,
						   uint32_t im_status,
						   int alloc_mode)
{
	if (alloc_mode == 0) {
		if (pool_count_is_critical(pool)) {
			return false;
		}
		if (im_status & SCM_IMST_PRIO_GC) {
			return true;
		}
		if ((im_status &
		     (SCM_IMST_PROC_FOREGROUND | SCM_IMST_PRIO_VIP)) ==
		    SCM_IMST_PROC_FOREGROUND) {
			return true;
		}

	} else if (alloc_mode == 1) {
		if (im_status & (SCM_IMST_PRIO_VIP | SCM_IMST_MM_MMAPLOCKED)) {
			return true;
		}
	} else if (alloc_mode == 2) {
		if (im_status & (SCM_IMST_PROC_FOREGROUND | SCM_IMST_PRIO_GC |
				 SCM_IMST_PRIO_VIP | SCM_IMST_MM_MMAPLOCKED)) {
			return true;
		}
		if (scm_qos_pool_is_half_full(pool) &&
		    !(im_status & SCM_IMST_PRIO_LOW)) {
			return true;
		}
	}
	return false;
}

static __always_inline int
__scm_qos_can_alloc_from_pool(uint32_t im_status, scm_qos_page_pool *pool,
			      gfp_t gfp_mask, unsigned int order,
			      int alloc_flags, int alloc_mode)
{
	if (alloc_mode == 0 && !_scm_free_page_is_tiny())
		return SCM_FREE_TINY_ERRNO;

	if (order != pool->order)
		return SCM_ORDER_NOT_MATCH_ERRNO;

	if (!_scm_qos_pool_page_flags_matched(pool, gfp_mask, order,
					      alloc_flags))
		return SCM_FLAG_NOT_MATCH_ERRNO;

	// if (fatal_signal_pending(current))
	// 	return -6;

	if (__scm_qos_allow_alloc_from_pool(pool, im_status, alloc_mode))
		return SCM_SUCCESS;

	return SCM_COMMON_ERRNO;
}

static __always_inline void
scm_qos_pool_try_wakeup_fill_worker(uint32_t im_status, scm_qos_pool *qp)
{
#ifdef SCM_CONFIG_HAS_FILL_WORKER
	// wakeup fill_worker in low prio task, when pages in pool is low.
	if (!(pool_count_is_low(&qp->u) || pool_count_is_low(&qp->m))) {
		return;
	}
	if ((im_status & (SCM_IMST_PROC_FOREGROUND_RELATED | SCM_IMST_PRIO_GC |
			  SCM_IMST_PRIO_VIP)) ==
	    SCM_IMST_PROC_FOREGROUND_RELATED) {
		scm_qos_pool_wakeup_fill_worker(qp);
	}
#endif
}

static __always_inline int __scm_qos_get_alloc_mode(int step)
{
	if (step == 0 && _scm_enabled(POLICY_QOS_POOL_STEP0)) {
		return 0;
	}
	if (step == 1 && _scm_enabled(POLICY_QOS_POOL_STEP1)) {
		if (_scm_enabled(POLICY_QOS_POOL_STEP0) == 0)
			return 1; // both step0 and step1 are enabled
		else
			return 2; // only step1 is enabled
	}

	return -1;
}

#ifdef CONFIG_HONOR_SCM_DEBUG
static void _scm_qos_pool_dump_bypass_reson(char *buf, int len,
					    scm_qos_page_pool *pool)
{
	int i;
	int total = 0;
	const char *name = (pool == &scm_qp->u) ? "u" : "m";
	snprintf(BUF, LEN, "scm: qos_pool_%s.pass_reason[", name);
	for (i = 1; i < SCM_ARRAY_COUNT(pool->pass_reasons); i++) {
		if (pool->pass_reasons[i] == 0) {
			continue;
		}
		total += pool->pass_reasons[i];
		snprintf(BUF, LEN, "%d: %d, ", i, pool->pass_reasons[i]);
	}
	snprintf(BUF, LEN, "t:%d]\n", total);
}
static void _scm_qos_pool_inc_bypass_reson(scm_qos_page_pool *pool, int cur)
{
	if (cur < 1 || cur >= SCM_ARRAY_COUNT(pool->pass_reasons)) {
		return;
	}
	pool->pass_reasons[cur]++;
}
#else
#define _scm_qos_pool_dump_bypass_reson(buf, len, pool)
#define _scm_qos_pool_inc_bypass_reson(pool, cur)
#endif

static __always_inline int
_scm_qos_can_alloc_from_pool(uint32_t im_status, scm_qos_page_pool *pool,
			     gfp_t gfp_mask, unsigned int order,
			     int alloc_flags, int step)
{
	int ret = SCM_COMMON_ERRNO;
	int alloc_mode = __scm_qos_get_alloc_mode(step);

	if (alloc_mode < 0) {
		if (pool_count_is_zero(pool)) {
			goto out;
		}
		alloc_mode = step;
	}

	ret = __scm_qos_can_alloc_from_pool(im_status, pool, gfp_mask, order,
					    alloc_flags, alloc_mode);
out:
#ifdef CONFIG_HONOR_SCM_DEBUG
	if (ret < 0) {
		_scm_qos_pool_inc_bypass_reson(pool, -ret);
		if (_scm_debug_enabled(POLICY_QOS_POOL_STEP0 |
				       POLICY_QOS_POOL_STEP1)) {
			printk("scm: tgid=%d, pool_%s.%d_pass_reason=%d, order=%d, mask=%#x(%pGg)\n",
			       current->tgid, (pool == &scm_qp->u) ? "u" : "m",
			       step, ret, order, gfp_mask, &gfp_mask);
		}
	}
#endif
	return ret;
}

void scm_qos_pool_wakeup_pool_worker(void)
{
	scm_qos_pool_wakeup_fill_worker(scm_qp);
}

long scm_qos_pool_used_pages(void)
{
	return atomic_read(&scm_qp->u.count) + atomic_read(&scm_qp->m.count);
}

struct page *scm_qos_pool_alloc_pages(gfp_t alloc_gfp, int order,
				      int alloc_flags, int step)
{
	struct page *page;
	scm_qos_pool *qp = scm_qp;
	scm_qos_page_pool *pool = (alloc_gfp & ___GFP_MOVABLE) ? &qp->m :
								 &qp->u;

	uint32_t im_status = scm_task_status_get2(current, alloc_gfp);

	if (is_scm_qos_pool_fill_worker(qp)) {
		return NULL;
	}

	if (_scm_qos_can_alloc_from_pool(im_status, pool, alloc_gfp, order,
					 alloc_flags, step) < 0) {
		atomic64_inc(step == 0 ? &pool->bypass0_count :
					 &pool->bypass1_count);
		return NULL;
	}
	page = _scm_qos_alloc_page_from_pool(pool);
	if (page != NULL) {
		atomic64_inc(step == 0 ? &pool->allocated0_count :
					 &pool->allocated1_count);
	} else {
		atomic64_inc(&pool->alloc_fail_count);
	}
	scm_qos_pool_try_wakeup_fill_worker(im_status, qp);
	return page;
}

static inline scm_qos_page_pool *_scm_qos_pool_get_pool(scm_qos_pool *qp,
							int migratetype)
{
	if (migratetype == MIGRATE_MOVABLE) {
		return &qp->m;
	} else if (migratetype == MIGRATE_UNMOVABLE) {
		return &qp->u;
	}
	return NULL;
}

bool scm_qos_pool_free_to_fill(struct page *page, unsigned int order,
			       unsigned long pfn, int migratetype, bool remove)
{
	scm_qos_page_pool *pool;
	scm_qos_pool *qp = scm_qp;
	qp->freed_count[migratetype] += 1;
#ifdef CONFIG_HONOR_SCM_DEBUG
	if (_scm_debug_enabled(POLICY_QOS_POOL_STEP0 | POLICY_QOS_POOL_STEP1)) {
		printk("scm: free_filled: order = %d, pfn = 0x%lx. type =%d, free =%d mB\n",
		       order, pfn, migratetype,
		       PAGE2MB(_scm_stat_get_free_pages()));
	}
#endif
	if (order != 0 ||
	    !_scm_enabled(POLICY_QOS_POOL_STEP0 | POLICY_QOS_POOL_STEP1) ||
	    _scm_free_page_is_critical()) {
		return false;
	}
	pool = _scm_qos_pool_get_pool(qp, migratetype);
	if (pool == NULL || scm_qos_pool_is_full(pool)) {
		return false;
	}
	if (remove) {
		list_del(&page->lru);
	}
	scm_qos_pool_add_page(pool, page);
	atomic64_inc(&pool->free_filled_count);
	return true;
}

void scm_qos_pool_set_high(bool movable, int high_watermark)
{
	scm_qos_pool *qp = scm_qp;
	scm_qos_page_pool *pool = movable ? &qp->m : &qp->u;
	int max_count = SCM_QOS_POOL_MAX_WATERMARK / (PAGE_SIZE << pool->order);
	if (high_watermark < 0 || high_watermark > max_count) {
		pr_err("scm: failed to config qos_pool(%d) high_watermark to %d, out of range.\n",
		       (int)movable, high_watermark);
		return;
	}
	atomic_set(&pool->high_watermark, high_watermark);
	if (atomic_read(&pool->low_watermark) > high_watermark ||
	    atomic_read(&pool->low_watermark) <= 0) {
		atomic_set(&pool->low_watermark, high_watermark / 2);
	}
	scm_qos_pool_wakeup_fill_worker(qp);
#ifdef CONFIG_HONOR_SCM_DEBUG
	pr_info("scm: config qos_pool(%d) watermark to (*%d, %d).\n",
		(int)movable, atomic_read(&pool->low_watermark),
		high_watermark);
#endif
}

void scm_qos_pool_set_low(bool movable, int low_watermark)
{
	scm_qos_pool *qp = scm_qp;
	scm_qos_page_pool *pool = movable ? &qp->m : &qp->u;
	int high_watermark = atomic_read(&pool->high_watermark);
	if (low_watermark < 0 || low_watermark > high_watermark) {
		pr_err("scm: failed to config qos_pool(%d) low_watermark to %d, out of range.\n",
		       (int)movable, low_watermark);
		return;
	}
	atomic_set(&pool->low_watermark, low_watermark);
#ifdef CONFIG_HONOR_SCM_DEBUG
	pr_info("scm: config qos_pool(%d) watermark to (%d, *%d).\n",
		(int)movable, atomic_read(&pool->low_watermark),
		high_watermark);
#endif
}

void scm_qos_pool_enable(uint64_t policy)
{
	if (_scm_enabled(POLICY_QOS_POOL_STEP0 | POLICY_QOS_POOL_STEP1)) {
		scm_qos_pool_wakeup_fill_worker(scm_qp);
	}
}

static void _scm_qos_pool_freed_page_show(char *buf, int len)
{
	int mt;
	snprintf(BUF, LEN, "qos_pool_freed = [");
	for (mt = 0; mt < MIGRATE_TYPES; mt++) {
		snprintf(BUF, LEN, "%d, ", scm_qp->freed_count[mt]);
	}
	snprintf(BUF, LEN, "]\n");
}

static void _scm_qos_page_pool_show(char *buf, int len, const char *name,
				    scm_qos_page_pool *pool)
{
	snprintf(BUF, LEN, "qos_pool_range.%s = (%d, %d)\n", name,
		 atomic_read(&pool->low_watermark),
		 atomic_read(&pool->high_watermark));
	snprintf(
		BUF, LEN,
		"qos_pool_count.%s = %d, %llu, %llu, %llu, %llu, %llu, %llu, %llu\n",
		name, atomic_read(&pool->count),
		atomic64_read(&pool->work_filled_count),
		atomic64_read(&pool->free_filled_count),
		atomic64_read(&pool->bypass0_count),
		atomic64_read(&pool->bypass1_count),
		atomic64_read(&pool->allocated0_count),
		atomic64_read(&pool->allocated1_count),
		atomic64_read(&pool->alloc_fail_count));

	_scm_qos_pool_dump_bypass_reson(BUF, LEN, pool);
}

void scm_qos_pool_show(char *buf, int len)
{
	_scm_qos_page_pool_show(BUF, LEN, "u", &scm_qp->u);
	_scm_qos_page_pool_show(BUF, LEN, "m", &scm_qp->m);
	_scm_qos_pool_freed_page_show(BUF, LEN);
}

static void __init _scm_qos_init_one_pool(scm_qos_page_pool *pool, int order,
					  gfp_t gfp_fill, gfp_t gfp_alloc,
					  unsigned long wm_low_mb,
					  unsigned long wm_high_mb)
{
	pool->gfp_allowed = gfp_alloc;
	pool->gfp_mask = gfp_fill;
	pool->order = 0;

	INIT_LIST_HEAD(&pool->low_items);
	INIT_LIST_HEAD(&pool->high_items);

	atomic_set(&pool->count, 0);
	atomic_set(&pool->low_watermark,
		   wm_low_mb / (PAGE_SIZE << pool->order));
	atomic_set(&pool->high_watermark,
		   wm_high_mb / (PAGE_SIZE << pool->order));
}

void __init scm_qos_pool_init(void)
{
	unsigned long scm_qos_lock_flag;
	scm_qos_pool *qp = scm_qp;
	struct task_struct *fill_worker = NULL;

	SCM_QOS_LOCK();
	_scm_qos_init_one_pool(&qp->m, 0, QOS_POOL_GFP_FILL_MOVABLE,
			       QOS_POOL_GFP_ALLOC_MOVABLE,
			       SCM_QOS_POOL_LOW_WATERMARK_MO,
			       SCM_QOS_POOL_HIGH_WATERMARK_MO);
	_scm_qos_init_one_pool(&qp->u, 0, QOS_POOL_GFP_FILL_UNMOVABLE,
			       QOS_POOL_GFP_ALLOC_UNMOVABLE,
			       SCM_QOS_POOL_LOW_WATERMARK_UN,
			       SCM_QOS_POOL_HIGH_WATERMARK_UN);
	SCM_QOS_UNLOCK();

#ifdef SCM_CONFIG_HAS_FILL_WORKER
	fill_worker = scm_qos_pool_create_fill_worker(qp);
	if (fill_worker == NULL) {
		pr_info("scm qos pool init failed\n");
		return;
	}
#endif
	SCM_QOS_LOCK();
	qp->fill_worker = fill_worker;
	SCM_QOS_UNLOCK();
	pr_info("scm qos pool init success\n");
}
