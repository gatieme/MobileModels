/*
 * memcg_reclaim.c
 *
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
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
 */

#include <linux/mm.h>
#include <linux/sched/mm.h>
#include <linux/module.h>
#include <linux/gfp.h>
#include <linux/kernel_stat.h>
#include <linux/swap.h>
#include <linux/pagemap.h>
#include <linux/init.h>
#include <linux/highmem.h>
#include <linux/vmpressure.h>
#include <linux/vmstat.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/writeback.h>
#include <linux/blkdev.h>
#include <linux/buffer_head.h>
#include <linux/mm_inline.h>
#include <linux/backing-dev.h>
#include <linux/rmap.h>
#include <linux/topology.h>
#include <linux/cpu.h>
#include <linux/cpuset.h>
#include <linux/compaction.h>
#include <linux/notifier.h>
#include <linux/rwsem.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/memcontrol.h>
#include <linux/delayacct.h>
#include <linux/sysctl.h>
#include <linux/oom.h>
#include <linux/prefetch.h>
#include <linux/printk.h>
#include <linux/dax.h>
#include <linux/psi.h>
#include <linux/sched/loadavg.h>
#include <linux/version.h>
#include <linux/sched.h>

#include <asm/tlbflush.h>
#include <asm/div64.h>
#include <linux/atomic.h>
#include <linux/swapops.h>
#include <linux/balloon_compaction.h>
#include <trace/events/vmscan.h>
#include <uapi/linux/sched/types.h>

#ifdef CONFIG_MEMCG_PROTECT_LRU
#include <linux/protect_lru.h>
#endif
#ifdef CONFIG_HW_RECLAIM_ACCT
#include <chipset_common/reclaim_acct/qcom/reclaim_acct.h>
#endif
#ifdef CONFIG_HW_KSWAPD_ACCT
#include <linux/kswapd_acct.h>
#endif
#include <linux/hyperhold_inf.h>
#include <linux/memcg_policy.h>
#include <linux/parallel_swapd.h>
#include "memcg_policy_internal.h"
#include "internal.h"

static wait_queue_head_t snapshotd_wait;
static atomic_t snapshotd_wait_flag;
static atomic_t snapshotd_init_flag = ATOMIC_LONG_INIT(0);
static struct task_struct *snapshotd_task;

atomic64_t shrink_sys_cnt = ATOMIC64_INIT(0);
atomic64_t shrink_sys_page = ATOMIC64_INIT(0);

/*
 * From 0 .. 100.  Higher means more swappy.
 */
#define DEFAULT_HYPERHOLD_SWAPPINESS 100
#define PERCENT_CONSTANT 100

static int hyperhold_swappiness = DEFAULT_HYPERHOLD_SWAPPINESS;
static int hyperhold_lowmem_swappiness = DEFAULT_HYPERHOLD_SWAPPINESS;

void set_hyperhold_swappiness(int swappiness)
{
	hyperhold_swappiness = swappiness;
}

int get_hyperhold_swappiness(void)
{
	return hyperhold_enable() ? hyperhold_swappiness : vm_swappiness;
}

void set_hyperhold_lowmem_swappiness(int swappiness)
{
	hyperhold_lowmem_swappiness = swappiness;
}

int get_hyperhold_lowmem_swappiness(void)
{
	return hyperhold_enable() ? hyperhold_lowmem_swappiness : vm_swappiness;
}

#ifdef CONFIG_HUAWEI_DIRECT_SWAPPINESS
#define DEFAULT_HYPERHOLD_DR_SWAPPINESS 0

static int hyperhold_dr_swappiness = DEFAULT_HYPERHOLD_DR_SWAPPINESS;

void set_hyperhold_dr_swappiness(int dr_swappiness)
{
	hyperhold_dr_swappiness = dr_swappiness;
}

int get_hyperhold_dr_swappiness(void)
{
	return hyperhold_dr_swappiness;
}
#endif

inline u64 get_shrink_sys_cnt_value(void)
{
	return atomic64_read(&shrink_sys_cnt);
}

inline u64 get_skrink_sys_page_value(void)
{
	return atomic64_read(&shrink_sys_page);
}

static inline struct lruvec *__mem_cgroup_lruvec(struct mem_cgroup *memcg,
					       struct pglist_data *pgdat)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	return mem_cgroup_lruvec(memcg, pgdat);
#else
	return mem_cgroup_lruvec(pgdat, memcg);
#endif
}

static inline unsigned long __totalram_pages(void)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	return totalram_pages();
#else
	return totalram_pages;
#endif
}

static unsigned long move_pages_to_page_list(struct lruvec *lruvec,
		enum lru_list lru, struct list_head *page_list)
{
	unsigned long nr_isolated = 0;
	struct page *page = NULL;
	struct list_head *src = &lruvec->lists[lru];

	while (!list_empty(src)) {
		page = lru_to_page(src);

		if (PageUnevictable(page))
			continue;

		if (likely(get_page_unless_zero(page))) {
			if (isolate_lru_page(page)) {
				put_page(page);
				continue;
			}
			put_page(page);
		} else {
			continue;
		}

		if (PageUnevictable(page)) {
			putback_lru_page(page);
			continue;
		}

		/*
		 * MADV_FREE clears pte dirty bit and then marks the page
		 * lazyfree (clear SwapBacked). Inbetween if this lazyfreed page
		 * is touched by user then it becomes dirty.  PPR in
		 * shrink_page_list in try_to_unmap finds the page dirty, marks
		 * it back as PageSwapBacked and skips reclaim. This can cause
		 * isolated count mismatch.
		 */
		if (PageAnon(page) && !PageSwapBacked(page)) {
			putback_lru_page(page);
			continue;
		}

		list_add(&page->lru, page_list);
		nr_isolated++;
	}
	return nr_isolated;
}

unsigned long reclaim_all_anon_memcg(struct pglist_data *pgdat,
		struct mem_cgroup *memcg)
{
	LIST_HEAD(page_list);
	struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);
	unsigned long nr_reclaimed;
	struct page *page = NULL;
	struct reclaim_stat stat = {};
	struct scan_control sc = {
		.gfp_mask = GFP_KERNEL,
		.may_writepage = 1,
		.may_unmap = 1,
		.may_swap = 1,
	};
#ifdef CONFIG_HW_RECLAIM_ACCT
	enum lru_list lru = LRU_INACTIVE_ANON;

	reclaimacct_shrinklist_start(is_file_lru(lru));
#endif
	count_vm_event(FREEZE_RECLAIM_TIMES);
	move_pages_to_page_list(lruvec,
			LRU_INACTIVE_ANON, &page_list);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	nr_reclaimed = shrink_page_list(&page_list, NULL, &sc,
			&stat, true);
#else
	nr_reclaimed = shrink_page_list(&page_list, NULL, &sc,
			TTU_IGNORE_ACCESS, &stat, true);
#endif
	count_vm_events(FREEZE_RECLAIMED, nr_reclaimed);

	while (!list_empty(&page_list)) {
		page = lru_to_page(&page_list);
		list_del(&page->lru);
		putback_lru_page(page);
	}

#ifdef CONFIG_HW_RECLAIM_ACCT
	reclaimacct_shrinklist_end(is_file_lru(lru));
#endif
	return nr_reclaimed;
}

u64 get_memcg_anon_pages(struct mem_cgroup *memcg)
{
	int nid;
	pg_data_t *pgdat = NULL;
	u64 memcg_anon = 0;

	for_each_online_node(nid) {
		pgdat = NODE_DATA(nid);
		struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);
		memcg_anon += lruvec_lru_size(lruvec, LRU_ACTIVE_ANON, MAX_NR_ZONES);
		memcg_anon += lruvec_lru_size(lruvec, LRU_INACTIVE_ANON, MAX_NR_ZONES);
	}

	return memcg_anon;
}

u64 get_sys_anon_size_memcgs(void)
{
	int nid;
	u64 score;
	u64 total_system_anon = 0;
	struct mem_cgroup *memcg = NULL;
	while ((memcg = get_next_memcg(memcg))) {
		score = atomic64_read(&memcg->memcg_reclaimed.app_score);
		if (score < SHRINK_SYS_ANON_MIN_SCORE || score > SHRINK_SYS_ANON_MAX_SCORE)
			continue;

		total_system_anon += get_memcg_anon_pages(memcg);
	}
	total_system_anon = total_system_anon * PAGE_SIZE / SZ_1M;

	return total_system_anon;
}

void force_shrink_sys_anon_memcgs(void)
{
	int nid;
	u64 score;
	u64 memcg_anon = 0;
	u64 total_reclaimed = 0;
	u64 shrink_root_thre_pg = get_shrink_root_thre_sz() * SZ_1M / PAGE_SIZE;
	u64 shrink_sys_tgt_pg = get_shrink_sys_tgt_sz() * SZ_1M / PAGE_SIZE;
	u64 shrink_sys_skip_pg = get_shrink_sys_skip_sz() * SZ_1M / PAGE_SIZE;
	unsigned int emergency_swap_ratio = get_emergency_swap_ratio();
	struct mem_cgroup *memcg = NULL;
	pg_data_t *pgdat = NULL;

	if (!shrink_sys_anon_enabled())
		return;

	if (get_sys_anon_size_memcgs() < get_shrink_sys_thre_sz())
		return;

	pr_info("force_shrink_sys, total size %llu MB", get_sys_anon_size_memcgs());
	while ((memcg = get_next_memcg(memcg))) {
		score = atomic64_read(&memcg->memcg_reclaimed.app_score);
		if (score >= SHRINK_SYS_ANON_MIN_SCORE &&
			atomic_read(&memcg->memcg_reclaimed.ub_zram2ufs_ratio) < emergency_swap_ratio)
			atomic_set(&memcg->memcg_reclaimed.ub_zram2ufs_ratio, emergency_swap_ratio);
		if (score < SHRINK_SYS_ANON_MIN_SCORE || score > SHRINK_SYS_ANON_MAX_SCORE)
			continue;

		memcg_anon = get_memcg_anon_pages(memcg);
		if (memcg_anon < shrink_sys_skip_pg)
			continue;
		if (memcg == root_mem_cgroup && memcg_anon < shrink_root_thre_pg)
			continue;

		for_each_online_node(nid) {
			pgdat = NODE_DATA(nid);
			total_reclaimed += reclaim_all_anon_memcg(pgdat, memcg);
		}
		pr_info("force_shrink_sys, reclaim memcg %s, origin size %llu MB, total_reclaimed %llu MB",
				memcg->name, memcg_anon * PAGE_SIZE / SZ_1M, total_reclaimed * PAGE_SIZE / SZ_1M);

		if (total_reclaimed >= shrink_sys_tgt_pg)
			break;
	}
	atomic64_inc(&shrink_sys_cnt);
	atomic64_add(total_reclaimed, &shrink_sys_page);
}

#ifdef CONFIG_HYPERHOLD_FILE_LRU
static inline bool is_swap_not_allowed(struct scan_control *sc, int swappiness)
{
	return !sc->may_swap || !swappiness || !get_nr_swap_pages();
}

#ifdef CONFIG_HUAWEI_DIRECT_SWAPPINESS
static inline int get_direct_swappiness(void)
{
#if defined(CONFIG_HYPERHOLD_CORE) && defined(CONFIG_HYPERHOLD_ZSWAPD)
	return hyperhold_enable() ? hyperhold_dr_swappiness : direct_vm_swappiness;
#else
	return direct_vm_swappiness;
#endif
}
#endif

static bool is_kswapd_high_load(void)
{
	bool fit_cpu = false;
	int policy;

	policy = get_kswapd_track_load_policy();
	switch (policy) {
	case TRACK_BIG_CPU:
		fit_cpu = is_max_cap_orig_cpu(smp_processor_id());
		break;
	case TRACK_ALL_CPU:
		fit_cpu = true;
		break;
	default:
		return false;
	}

	return fit_cpu && task_util(current) > get_kswapd_high_load_threshold();
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
static inline void get_anon_file_ratio(int swappiness,
		struct lruvec *lruvec, struct pglist_data *pgdat,
		u64 *fraction, u64 *denominator, struct scan_control *sc)
{
	unsigned long anon_prio, file_prio;
	unsigned long anon, file;
	unsigned long ap, fp;

	/*
	 * With swappiness at 100, anonymous and file have the same priority.
	 * This scanning priority is essentially the inverse of IO cost.
	 */
	anon_prio = swappiness;
	file_prio = 200 - anon_prio;

	/*
	 * OK, so we have swap space and a fair amount of page cache
	 * pages.  We use the recently rotated / recently scanned
	 * ratios to determine how valuable each cache is.
	 *
	 * Because workloads change over time (and to avoid overflow)
	 * we keep these statistics as a floating average, which ends
	 * up weighing recent references more than old ones.
	 *
	 * anon in [0], file in [1]
	 */

	anon  = lruvec_lru_size(lruvec, LRU_ACTIVE_ANON, MAX_NR_ZONES) +
		lruvec_lru_size(lruvec, LRU_INACTIVE_ANON, MAX_NR_ZONES);
	file  = lruvec_lru_size(lruvec, LRU_ACTIVE_FILE, MAX_NR_ZONES) +
		lruvec_lru_size(lruvec, LRU_INACTIVE_FILE, MAX_NR_ZONES);

	struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;

	spin_lock_irq(&pgdat->lru_lock);
	if (unlikely(reclaim_stat->recent_scanned[0] > anon / 4)) {
		reclaim_stat->recent_scanned[0] /= 2;
		reclaim_stat->recent_rotated[0] /= 2;
	}

	if (unlikely(reclaim_stat->recent_scanned[1] > file / 4)) {
		reclaim_stat->recent_scanned[1] /= 2;
		reclaim_stat->recent_rotated[1] /= 2;
	}

	/*
	 * The amount of pressure on anon vs file pages is inversely
	 * proportional to the fraction of recently scanned pages on
	 * each list that were recently referenced and in active use.
	 */
	ap = anon_prio * (reclaim_stat->recent_scanned[0] + 1);
	ap /= reclaim_stat->recent_rotated[0] + 1;

	fp = file_prio * (reclaim_stat->recent_scanned[1] + 1);
	fp /= reclaim_stat->recent_rotated[1] + 1;
	spin_unlock_irq(&pgdat->lru_lock);

	fraction[0] = ap;
	fraction[1] = fp;
	*denominator = ap + fp + 1;
}
#else
static inline void get_anon_file_ratio(int swappiness,
		struct lruvec *lruvec, struct pglist_data *pgdat,
		u64 *fraction, u64 *denominator, struct scan_control *sc)
{
	unsigned long anon_prio, file_prio;
	unsigned long ap, fp;
	unsigned long anon_cost, file_cost, total_cost;

	/*
	 * With swappiness at 100, anonymous and file have the same priority.
	 * This scanning priority is essentially the inverse of IO cost.
	 */
	anon_prio = swappiness;
	file_prio = 200 - anon_prio;

	/*
	* Determine the scan balance between anon and file LRUs.
	*/
	spin_lock_irq(&pgdat->lru_lock);
	sc->anon_cost =
		lruvec_page_state(lruvec, WORKINGSET_ANON_COST);
	sc->file_cost =
		lruvec_page_state(lruvec, WORKINGSET_FILE_COST);
	spin_unlock_irq(&pgdat->lru_lock);

	/*
	* Calculate the pressure balance between anon and file pages.
	*
	* The amount of pressure we put on each LRU is inversely
	* proportional to the cost of reclaiming each list, as
	* determined by the share of pages that are refaulting, times
	* the relative IO cost of bringing back a swapped out
	* anonymous page vs reloading a filesystem page (swappiness).
	*
	* Although we limit that influence to ensure no list gets
	* left behind completely: at least a third of the pressure is
	* applied, before swappiness.
	*
	* With swappiness at 100, anon and file have equal IO cost.
	*/
	total_cost = sc->anon_cost + sc->file_cost;
	anon_cost = total_cost + sc->anon_cost;
	file_cost = total_cost + sc->file_cost;
	total_cost = anon_cost + file_cost;

	ap = anon_prio * (total_cost + 1);
	ap /= anon_cost + 1;

	fp = file_prio * (total_cost + 1);
	fp /= file_cost + 1;

	fraction[0] = ap;
	fraction[1] = fp;
	*denominator = ap + fp;
}
#endif

static bool target_mem_cgroup_reclaim(struct scan_control *sc)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	return cgroup_reclaim(sc);
#else
	return global_reclaim(sc);
#endif
}

static inline bool inactive_is_low_hyperhold(struct lruvec *lruvec,
          bool file, struct scan_control *sc,
          bool trace, enum lru_list inactive_lru)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
      return inactive_is_low(lruvec, inactive_lru);
#else
      return inactive_list_is_low(lruvec, file, sc, trace);
#endif
}

static void get_scan_counts(struct pglist_data *pgdat,
		struct scan_control *sc, unsigned long *nr,
		unsigned long *lru_pages)
{
	int swappiness = get_hyperhold_swappiness();
	struct lruvec *lruvec = node_lruvec(pgdat);
	u64 fraction[2];
	u64 denominator;
	enum scan_balance scan_balance;
	enum lru_list lru;
	unsigned long pgdatfile;
	unsigned long pgdatfree;
	int z;
	unsigned long total_high_wmark = 0;
	bool inactive_file_is_low;

	inactive_file_is_low = inactive_is_low_hyperhold(lruvec, true,
		sc, false, LRU_INACTIVE_FILE);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	if (inactive_file_is_low)
		sc->may_deactivate |= DEACTIVATE_FILE;
	else
		sc->may_deactivate &= ~DEACTIVATE_FILE;
#endif

#ifdef CONFIG_HUAWEI_DIRECT_SWAPPINESS
	if (!current_is_kswapd())
		swappiness = get_direct_swappiness();
	else if (is_in_direct_reclaim())
		swappiness = get_hyperhold_lowmem_swappiness();
	else if (is_kswapd_high_load())
		swappiness = get_kswapd_high_load_swappiness();
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
	if (!target_mem_cgroup_reclaim(sc) && !swappiness) {
		scan_balance = SCAN_FILE;
		goto out;
	}
#else
	pgdatfile = node_page_state(pgdat, NR_ACTIVE_FILE) +
		node_page_state(pgdat, NR_INACTIVE_FILE);
	if (pgdatfile <= 20 * SZ_1M / PAGE_SIZE)
		swappiness = 0;

	/* If we have no swap space, do not bother scanning anon pages. */
	if (is_swap_not_allowed(sc, swappiness)) {
		scan_balance = SCAN_FILE;
		goto out;
	}
#endif

	/*
	 * Do not apply any pressure balancing cleverness when the
	 * system is close to OOM, scan both anon and file equally
	 * (unless the swappiness setting disagrees with swapping).
	 */
	if (!sc->priority && swappiness) {
		scan_balance = SCAN_EQUAL;
		goto out;
	}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
	if (target_mem_cgroup_reclaim(sc)) {
#endif
		pgdatfree = sum_zone_node_page_state(pgdat->node_id, NR_FREE_PAGES);
		pgdatfile = node_page_state(pgdat, NR_ACTIVE_FILE) +
			node_page_state(pgdat, NR_INACTIVE_FILE);

		for (z = 0; z < MAX_NR_ZONES; z++) {
			struct zone *zone = &pgdat->node_zones[z];

			if (!managed_zone(zone))
				continue;

			total_high_wmark += high_wmark_pages(zone);
		}

		if (unlikely(pgdatfile + pgdatfree <= total_high_wmark)) {
			/*
			 * Force SCAN_ANON if there are enough inactive
			 * anonymous pages on the LRU in eligible zones.
			 * Otherwise, the small LRU gets thrashed.
			 */
			if (!inactive_is_low_hyperhold(lruvec, false,
				sc, false, LRU_INACTIVE_ANON) &&
				(lruvec_lru_size(lruvec, LRU_INACTIVE_ANON,
					sc->reclaim_idx) >>
					(unsigned int)sc->priority)) {
				scan_balance = SCAN_ANON;
				goto out;
			}
		}
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
	}
#endif

	/*
	 * If there is enough inactive page cache, i.e. if the size of the
	 * inactive list is greater than that of the active list *and* the
	 * inactive list actually has some pages to scan on this priority, we
	 * do not reclaim anything from the anonymous working set right now.
	 * Without the second condition we could end up never scanning an
	 * lruvec even if it has plenty of old anonymous pages unless the
	 * system is under heavy pressure.
	 */

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
	if (!IS_ENABLED(CONFIG_BALANCE_ANON_FILE_RECLAIM) &&
	    !inactive_file_is_low &&
	    lruvec_lru_size(lruvec, LRU_INACTIVE_FILE, sc->reclaim_idx) >> sc->priority) {
		scan_balance = SCAN_FILE;
		goto out;
	}
#else
	if (enough_inactive_file == 0 &&
		!inactive_file_is_low &&
		(lruvec_lru_size(lruvec, LRU_INACTIVE_FILE,
			sc->reclaim_idx) >> (unsigned int)sc->priority)) {
		scan_balance = SCAN_FILE;
		goto out;
	}
#endif

	scan_balance = SCAN_FRACT;
	get_anon_file_ratio(swappiness, lruvec, pgdat, fraction, &denominator, sc);
out:
#ifdef CONFIG_HUAWEI_RCC
	if (sc->rcc_mode) {
		if (sc->rcc_mode == RCC_MODE_ANON)
			scan_balance = SCAN_ANON;
		else if (sc->rcc_mode == RCC_MODE_FILE)
			scan_balance = SCAN_FILE;
		else
			scan_balance = SCAN_EQUAL;
	}
#endif
	*lru_pages = 0;
	for_each_evictable_lru(lru) {
		int file = is_file_lru(lru); /*lint !e578*/
		unsigned long lruvec_size;
		unsigned long scan;

		lruvec_size = lruvec_lru_size(lruvec, lru, sc->reclaim_idx);
		scan = lruvec_size >> (unsigned int)sc->priority;
		/*
		 * If the cgroup's already been deleted, make sure to
		 * scrape out the remaining cache.
		 */
		switch (scan_balance) {
		case SCAN_EQUAL:
			/* Scan lists relative to size */
			break;
		case SCAN_FRACT:
			/*
			 * Scan types proportional to swappiness and
			 * their relative recent reclaim efficiency.
			 * Make sure we don't miss the last page
			 * because of a round-off error.
			 */
			scan = DIV64_U64_ROUND_UP(scan * fraction[file],
					denominator); /*lint !e644*/
			break;
		case SCAN_FILE:
		case SCAN_ANON:
			/* Scan one type exclusively */
			if ((scan_balance == SCAN_FILE) != file) {
				lruvec_size = 0;
				scan = 0;
			}
			break;
		default:
			break;
		}

		*lru_pages += lruvec_size;
		nr[lru] = scan;
	}
}

#define ISOLATE_LIMIT_CNT 5
void shrink_anon_memcg(struct pglist_data *pgdat,
		struct mem_cgroup *memcg, struct scan_control *sc,
		unsigned long *nr)
{
	struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);
	unsigned long nr_to_scan;
	enum lru_list lru;
	unsigned long nr_reclaimed = 0;
	struct blk_plug plug;

	blk_start_plug(&plug);

	while (nr[LRU_INACTIVE_ANON] || nr[LRU_ACTIVE_ANON]) {
		for (lru = 0; lru <= LRU_ACTIVE_ANON; lru++) {
			if (nr[lru]) {
				nr_to_scan = min(nr[lru], SWAP_CLUSTER_MAX);
				nr[lru] -= nr_to_scan;
				nr_reclaimed +=
					shrink_list(lru, nr_to_scan,
							lruvec, sc);
			}
		}
		if (sc->nr_reclaimed >= sc->nr_to_reclaim ||
				(sc->isolate_count > ISOLATE_LIMIT_CNT &&
				sc->invoker == DIRECT_RECLAIM))
			break;
	}
	blk_finish_plug(&plug);
	sc->nr_reclaimed += nr_reclaimed;
	sc->nr_reclaimed_anon += nr_reclaimed;
}

static void shrink_anon(struct pglist_data *pgdat,
		struct scan_control *sc, unsigned long *nr)
{
	unsigned long reclaimed;
	unsigned long scanned;
	struct mem_cgroup *memcg = NULL;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,0))
	struct mem_cgroup *root = root_mem_cgroup;
#endif
	unsigned long nr_memcg[NR_LRU_LISTS];
	unsigned long nr_node_active = lruvec_lru_size(
			node_lruvec(pgdat), LRU_ACTIVE_ANON, MAX_NR_ZONES);
	unsigned long nr_node_inactive = lruvec_lru_size(
			node_lruvec(pgdat), LRU_INACTIVE_ANON, MAX_NR_ZONES);

	while ((memcg = get_next_memcg(memcg))) {
#ifdef CONFIG_MEMCG_SKIP_RECLAIM
		if (memcg->skip_reclaim_anon)
			continue;
#endif
		struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);

		reclaimed = sc->nr_reclaimed;
		scanned = sc->nr_scanned;

		nr_memcg[LRU_ACTIVE_ANON] = nr[LRU_ACTIVE_ANON] *
			lruvec_lru_size(lruvec, LRU_ACTIVE_ANON,
					MAX_NR_ZONES) / (nr_node_active + 1);
		nr_memcg[LRU_INACTIVE_ANON] = nr[LRU_INACTIVE_ANON] *
			lruvec_lru_size(lruvec, LRU_INACTIVE_ANON,
					MAX_NR_ZONES) / (nr_node_inactive + 1);
		nr_memcg[LRU_ACTIVE_FILE] = 0;
		nr_memcg[LRU_INACTIVE_FILE] = 0;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
		mem_cgroup_calculate_protection(root, memcg);

		if (mem_cgroup_below_min(memcg)) {
			/*
			 * Hard protection.
			 * If there is no reclaimable memory, OOM.
			 */
			continue;
		} else if (mem_cgroup_below_low(memcg)) {
			/*
			 * Soft protection.
			 * Respect the protection only as long as
			 * there is an unprotected supply
			 * of reclaimable memory from other cgroups.
			 */
			if (!sc->memcg_low_reclaim) {
				sc->memcg_low_skipped = 1;
				continue;
			}
			memcg_memory_event(memcg, MEMCG_LOW);
		}
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,0))
		switch (mem_cgroup_protected(root, memcg)) {
		case MEMCG_PROT_MIN:
			/*
			 * Hard protection.
			 * If there is no reclaimable memory, OOM.
			 */
			continue;
		case MEMCG_PROT_LOW:
			/*
			 * Soft protection.
			 * Respect the protection only as long as
			 * there is an unprotected supply
			 * of reclaimable memory from other cgroups.
			 */
			if (!sc->memcg_low_reclaim) {
				sc->memcg_low_skipped = 1;
				continue;
			}
			memcg_memory_event(memcg, MEMCG_LOW);
			break;
		case MEMCG_PROT_NONE:
			break;
		}
#endif

		shrink_anon_memcg(pgdat, memcg, sc, nr_memcg);

		vmpressure(sc->gfp_mask, memcg, false,
				sc->nr_scanned - scanned,
				sc->nr_reclaimed - reclaimed);

		if (sc->nr_reclaimed >= sc->nr_to_reclaim ||
			(sc->isolate_count > ISOLATE_LIMIT_CNT &&
			sc->invoker == DIRECT_RECLAIM)) {
			get_next_memcg_break(memcg);
			break;
		}
	}
}

static void shrink_file(struct pglist_data *pgdat,
		struct scan_control *sc, unsigned long *nr)
{
	struct lruvec *lruvec = node_lruvec(pgdat);
	unsigned long nr_to_scan;
	enum lru_list lru;
	unsigned long nr_reclaimed = 0;
	struct blk_plug plug;

	blk_start_plug(&plug);

	while (nr[LRU_ACTIVE_FILE] || nr[LRU_INACTIVE_FILE]) {
		for (lru = LRU_INACTIVE_FILE; lru <= LRU_ACTIVE_FILE; lru++) {
			if (nr[lru]) {
				nr_to_scan = min(nr[lru], SWAP_CLUSTER_MAX);
				nr[lru] -= nr_to_scan;
				nr_reclaimed +=
					shrink_list(lru,
							nr_to_scan,
							lruvec, sc);
			}
		}
	}
	blk_finish_plug(&plug);
	sc->nr_reclaimed += nr_reclaimed;
	sc->nr_reclaimed_file += nr_reclaimed;
}

static bool writeback_throttling_sane_hyperhold(struct scan_control *sc)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	return writeback_throttling_sane(sc);
#else
	return sane_reclaim(sc);
#endif
}

#if CONFIG_RAMTURBO
static inline void allow_to_wake_up_dr(pg_data_t *pgdat)
{
	if (waitqueue_active(&pgdat->pfmemalloc_wait) &&
		allow_direct_reclaim(pgdat)) {
#ifdef CONFIG_HW_KSWAPD_ACCT
		kswapdacct_change_block_status();
#endif
		wake_up_all(&pgdat->pfmemalloc_wait);
	}
}
#endif

bool shrink_nodes(pg_data_t *pgdat, struct scan_control *sc)
{
	struct reclaim_state *reclaim_state = current->reclaim_state;
	unsigned long nr_reclaimed, nr_scanned;
	bool reclaimable = false;
#ifdef CONFIG_HW_KSWAPD_ACCT
	u64 reclaimed, scanned;
	bool is_kswapd = current_is_kswapd();
#endif
#ifdef CONFIG_MEMCG_PROTECT_LRU
	shrink_prot_memcg_by_overratio();
#endif
#ifdef CONFIG_HW_KSWAPD_ACCT
	if (is_kswapd)
		kswapdacct_start();
#endif
	do {
		/* Get scan count for file and anon */
		unsigned long node_lru_pages = 0;
		unsigned long nr[NR_LRU_LISTS] = {0};
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
		struct mem_cgroup *root = root_mem_cgroup;
		memset(&sc->nr, 0, sizeof(sc->nr));
#endif
		nr_reclaimed = sc->nr_reclaimed;
		nr_scanned = sc->nr_scanned;

		get_scan_counts(pgdat, sc, nr, &node_lru_pages);
#ifdef CONFIG_HW_KSWAPD_ACCT
		if (is_kswapd) {
			kswapdacct_get_nr_to_scan(nr);
			reclaimed = sc->nr_reclaimed_file;
			scanned = sc->nr_scanned_file;
			kswapd_stage_start(KSWAPD_SHRINKFILE);
		}
#endif
		/* Shrink the Total-File-LRU */
		shrink_file(pgdat, sc, nr);
#ifdef CONFIG_HW_KSWAPD_ACCT
		if (is_kswapd) {
			kswapd_stage_end(KSWAPD_SHRINKFILE);
			kswapd_stage_count(KSWAPD_SHRINKFILE,
					sc->nr_reclaimed_file - reclaimed, sc->nr_scanned_file - scanned);
			reclaimed = sc->nr_reclaimed_anon;
			scanned = sc->nr_scanned_anon;
			kswapd_stage_start(KSWAPD_SHRINKANON);
		}
#endif
#if CONFIG_RAMTURBO
		/*
		 * wakeup direct reclaim sooner if there's alread
		 * enough memory been reclaimed
		 */
		if (current_is_kswapd())
			allow_to_wake_up_dr(pgdat);
#endif
		/* Shrink Anon by iterating score_list */
		shrink_anon(pgdat, sc, nr);
#ifdef CONFIG_HW_KSWAPD_ACCT
		if (is_kswapd) {
			kswapd_stage_end(KSWAPD_SHRINKANON);
			kswapd_stage_count(KSWAPD_SHRINKANON,
					sc->nr_reclaimed_anon - reclaimed, sc->nr_scanned_anon - scanned);
		}
#endif
		/* only kswapd will shrink slab objs */
		if (current_is_kswapd()) {
#ifdef CONFIG_HW_KSWAPD_ACCT
			kswapd_stage_start(KSWAPD_SHRINKSLAB);
#endif
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0))
			shrink_slab(sc->gfp_mask, pgdat->node_id, NULL,
					sc->nr_scanned - nr_scanned,
					node_lru_pages);
#else
#if CONFIG_RAMTURBO
			/*
			 * wakeup direct reclaim sooner if there's alread
			 * enough memory been reclaimed
			 */
			allow_to_wake_up_dr(pgdat);
#endif
			shrink_slab(sc->gfp_mask, pgdat->node_id, root,
						sc->priority);
#endif
#ifdef CONFIG_HW_KSWAPD_ACCT
			kswapd_stage_end(KSWAPD_SHRINKSLAB);
#endif
		}

		if (reclaim_state) {
#ifdef CONFIG_HW_KSWAPD_ACCT
			kswapd_stage_count(KSWAPD_SHRINKSLAB, reclaim_state->reclaimed_slab, 0);
#endif
			sc->nr_reclaimed += reclaim_state->reclaimed_slab;
			reclaim_state->reclaimed_slab = 0;
		}

		/* Record the subtree's reclaim efficiency */
		vmpressure(sc->gfp_mask, sc->target_mem_cgroup, true,
			   sc->nr_scanned - nr_scanned,
			   sc->nr_reclaimed - nr_reclaimed);

		if (sc->nr_reclaimed - nr_reclaimed)
			reclaimable = true;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
		if (current_is_kswapd()) {
			/*
			 * If reclaim is isolating dirty pages under writeback,
			 * it implies that the long-lived page allocation rate
			 * is exceeding the page laundering rate. Either the
			 * global limits are not being effective at throttling
			 * processes due to the page distribution throughout
			 * zones or there is heavy usage of a slow backing
			 * device. The only option is to throttle from reclaim
			 * context which is not ideal as there is no guarantee
			 * the dirtying process is throttled in the same way
			 * balance_dirty_pages() manages.
			 *
			 * Once a node is flagged PGDAT_WRITEBACK, kswapd will
			 * count the number of pages under pages flagged for
			 * immediate reclaim and stall if any are encountered
			 * in the nr_immediate check below.
			 */
			if (sc->nr.writeback && sc->nr.writeback == sc->nr.taken)
				set_bit(PGDAT_WRITEBACK, &pgdat->flags);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
			/*
			 * Tag a node as congested if all the dirty pages
			 * scanned were backed by a congested BDI and
			 * wait_iff_congested will stall.
			 */
			if (sc->nr.dirty && sc->nr.dirty == sc->nr.congested)
				set_bit(PGDAT_CONGESTED, &pgdat->flags);
#endif
			/* Allow kswapd to start writing pages during reclaim. */
			if (sc->nr.unqueued_dirty == sc->nr.file_taken)
				set_bit(PGDAT_DIRTY, &pgdat->flags);

			/*
			 * If kswapd scans pages marked marked for immediate
			 * reclaim and under writeback (nr_immediate), it
			 * implies that pages are cycling through the LRU
			 * faster than they are written so also forcibly stall.
			 */
			if (sc->nr.immediate)
				congestion_wait(BLK_RW_ASYNC, HZ/10);
		}
		/*
		 * Legacy memcg will stall in page writeback so avoid forcibly
		 * stalling in wait_iff_congested().
		 */
		if (!target_mem_cgroup_reclaim(sc) &&
            writeback_throttling_sane_hyperhold(sc) &&
		    sc->nr.dirty && sc->nr.dirty == sc->nr.congested)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
			set_bit(LRUVEC_CONGESTED, &node_lruvec(pgdat)->flags);
#else
			set_memcg_congestion(pgdat, root, true);
#endif
		/*
		 * Stall direct reclaim for IO completions if underlying BDIs
		 * and node is congested. Allow kswapd to continue until it
		 * starts encountering unqueued dirty pages or cycling through
		 * the LRU too quickly.
		 */
		if (!sc->hibernation_mode && !current_is_kswapd() &&
			current_may_throttle() &&
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
			test_bit(LRUVEC_CONGESTED, &node_lruvec(pgdat)->flags))
#else
			pgdat_memcg_congested(pgdat, root))
#endif
			wait_iff_congested(BLK_RW_ASYNC, HZ/10);
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,4,0))
	} while (should_continue_reclaim(pgdat, sc->nr_reclaimed - nr_reclaimed,
					 sc));
#else
	} while (should_continue_reclaim(pgdat, sc->nr_reclaimed - nr_reclaimed,
					 sc->nr_scanned - nr_scanned, sc));
#endif
#ifdef CONFIG_HW_KSWAPD_ACCT
		if (is_kswapd)
			kswapdacct_end();
#endif
	/*
	 * Kswapd gives up on balancing particular nodes after too
	 * many failures to reclaim anything from them and goes to
	 * sleep. On reclaim progress, reset the failure counter. A
	 * successful direct reclaim run will revive a dormant kswapd.
	 */
	if (reclaimable)
		pgdat->kswapd_failures = 0;

	return reclaimable;
}
#endif

static pid_t kswapd_pid = -1;

pid_t get_kswapd_pid(void)
{
	return kswapd_pid;
}

void set_kswapd_pid(pid_t pid)
{
	kswapd_pid = pid;
}

bool is_swap_full(void)
{
	const unsigned int percent_constant = 100;
	long free_swap_pages = get_nr_swap_pages();
	if (total_swap_pages == 0)
		return true;
	return ((total_swap_pages - free_swap_pages) * percent_constant >=
		total_swap_pages * get_swap_full_ratio());
}

#ifdef CONFIG_HYPERHOLD_ZSWAPD
static pid_t zswapd_pid = -1;
static unsigned long long area_last_anon_pagefault;
static unsigned long last_anon_snapshot_time;
unsigned long long global_anon_refault_ratio;
unsigned long long zswapd_skip_interval = 1000;
bool last_round_is_empty;
unsigned long last_zswapd_time;

unsigned int calc_sys_cur_avail_buffers(void)
{
	const unsigned int percent_constant = 100;
	unsigned long freemem;
	unsigned long active_file;
	unsigned long inactive_file;
	unsigned long inactive_anon;
	unsigned long buffers;
#ifndef CONFIG_HYPERHOLD_QCOM
	unsigned long ion;
#endif

	freemem = global_zone_page_state(NR_FREE_PAGES) *
		PAGE_SIZE / SZ_1K;
	active_file = global_node_page_state(NR_ACTIVE_FILE) *
		PAGE_SIZE / SZ_1K;
	inactive_file = global_node_page_state(NR_INACTIVE_FILE) *
		PAGE_SIZE / SZ_1K;
	inactive_anon = global_node_page_state(NR_INACTIVE_ANON) *
		PAGE_SIZE / SZ_1K;
#ifdef CONFIG_HYPERHOLD_QCOM
	buffers = freemem + inactive_file * get_inactive_file_ratio_value() /
		percent_constant + active_file * get_active_file_ratio_value() /
		percent_constant + global_node_page_state(NR_KERNEL_MISC_RECLAIMABLE);;
#else
	ion = global_zone_page_state(NR_IONCACHE_PAGES) *
		PAGE_SIZE / SZ_1K;
	buffers = freemem + inactive_file * get_inactive_file_ratio_value() /
		percent_constant + active_file * get_active_file_ratio_value() /
		percent_constant + ion;
#endif
#ifdef CONFIG_HYPERHOLD_CORE
	buffers += (get_hyperhold_cache_pages() << PAGE_SHIFT) / SZ_1K;
#endif
	return (buffers * SZ_1K / SZ_1M);  /* kb to mb */
}

unsigned long get_mempsi(void)
{
	return get_psi(&psi_system, PSI_MEM);
}

unsigned long get_iopsi(void)
{
	return get_psi(&psi_system, PSI_IO);
}

unsigned long get_cpupsi(void)
{
	return get_psi(&psi_system, PSI_CPU);
}

void zswapd_status_show(struct seq_file *m)
{
	unsigned long mempsi, iopsi, cpupsi;
	unsigned int buffers = calc_sys_cur_avail_buffers();

	mempsi = get_mempsi();
	iopsi = get_iopsi();
	cpupsi = get_cpupsi();

	seq_printf(m, "buffer_size:%u\n", buffers);
	seq_printf(m, "recent_refault:%lu\n", global_anon_refault_ratio);
	seq_printf(m, "CPUPSI_avg10:%lu.%02lu\n",
		LOAD_INT(cpupsi), LOAD_FRAC(cpupsi));
	seq_printf(m, "MEMPSI_avg10:%lu.%02lu\n",
		LOAD_INT(mempsi), LOAD_FRAC(mempsi));
	seq_printf(m, "IOPSI_avg10:%lu.%02lu\n",
		LOAD_INT(iopsi), LOAD_FRAC(iopsi));
}

pid_t get_zswapd_pid(void)
{
	return zswapd_pid;
}

static bool min_buffer_is_suitable(void)
{
	u32 curr_buffers = calc_sys_cur_avail_buffers();

	if (curr_buffers >= get_min_avail_buffers_value())
		return true;

	return false;
}

static bool buffer_is_suitable(void)
{
	u32 curr_buffers = calc_sys_cur_avail_buffers();

	if (curr_buffers >= get_avail_buffers_value())
		return true;

	return false;
}

static bool high_buffer_is_suitable(void)
{
	u32 curr_buffers = calc_sys_cur_avail_buffers();

	if (curr_buffers >= get_high_avail_buffers_value())
		return true;

	return false;
}

static void snapshot_anon_refaults(void)
{
	struct mem_cgroup *memcg = NULL;

	while ((memcg = get_next_memcg(memcg)))
		memcg->memcg_reclaimed.reclaimed_pagefault =
			hyperhold_read_mcg_stats(memcg, MCG_ANON_FAULT_CNT);

	area_last_anon_pagefault = hyperhold_get_zram_pagefault();
	last_anon_snapshot_time = jiffies;
}

/*
 * Return true if refault changes between two read operations.
 */
static bool get_memcg_anon_refault_status(struct mem_cgroup *memcg)
{
	const unsigned int percent_constant = 100;
	unsigned long long cur_anon_pagefault;
	unsigned long anon_total;
	unsigned long long ratio;

	struct mem_cgroup_per_node *mz = NULL;
	struct lruvec *lruvec = NULL;

	if (!memcg)
		return false;

	cur_anon_pagefault =
		hyperhold_read_mcg_stats(memcg, MCG_ANON_FAULT_CNT);

	if (cur_anon_pagefault == memcg->memcg_reclaimed.reclaimed_pagefault)
		return false;

	mz = mem_cgroup_nodeinfo(memcg, 0);
	if (!mz)
		return false;
	lruvec = &mz->lruvec;
	if (!lruvec)
		return false;
	anon_total = lruvec_lru_size(lruvec, LRU_ACTIVE_ANON, MAX_NR_ZONES) +
		lruvec_lru_size(lruvec, LRU_INACTIVE_ANON, MAX_NR_ZONES) +
		hyperhold_read_mcg_stats(memcg, MCG_DISK_STORED_PG_SZ) +
		hyperhold_read_mcg_stats(memcg, MCG_ZRAM_PG_SZ);

	ratio = (cur_anon_pagefault -
		memcg->memcg_reclaimed.reclaimed_pagefault) *
		percent_constant / (anon_total + 1);

	if (ratio > (unsigned int)atomic_read(
			&memcg->memcg_reclaimed.refault_threshold))
		return true;

	return false;
}

static bool get_area_anon_refault_status(void)
{
	const unsigned int percent_constant = 1000;
	unsigned long long cur_anon_pagefault;
	unsigned long long cur_time;
	unsigned long long ratio;

	cur_anon_pagefault = hyperhold_get_zram_pagefault();
	cur_time = jiffies;

	if (cur_anon_pagefault == area_last_anon_pagefault
		|| cur_time == last_anon_snapshot_time)
		return false;

	ratio = (cur_anon_pagefault - area_last_anon_pagefault) *
		percent_constant / (jiffies_to_msecs(cur_time -
					last_anon_snapshot_time) + 1);

	global_anon_refault_ratio = ratio;

	if (ratio > get_area_anon_refault_threshold_value())
		return true;

	return false;
}

void wakeup_snapshotd(void)
{
	unsigned long curr_snapshot_interval;

	curr_snapshot_interval =
		jiffies_to_msecs(jiffies - last_anon_snapshot_time);
	if (curr_snapshot_interval >=
		get_anon_refault_snapshot_min_interval_value()) {
		atomic_set(&snapshotd_wait_flag, 1);
		wake_up_interruptible(&snapshotd_wait);
	}
}

static int snapshotd(void *p)
{
	int ret;

	while (!kthread_should_stop()) {
		/*lint -e578 */
		ret = wait_event_interruptible(snapshotd_wait,
			atomic_read(&snapshotd_wait_flag));
		/*lint +e578 */
		if (ret)
			continue;

		atomic_set(&snapshotd_wait_flag, 0);

		snapshot_anon_refaults();
		count_vm_event(ZSWAPD_SNAPSHOT_TIMES);
	}

	return 0;
}

void set_snapshotd_init_flag(unsigned int val)
{
	atomic_set(&snapshotd_init_flag, val);
}
/*
 * This snapshotd start function will be called by init.
 */
int snapshotd_run(void)
{
	atomic_set(&snapshotd_wait_flag, 0);
	init_waitqueue_head(&snapshotd_wait);
	snapshotd_task = kthread_run(snapshotd, NULL, "snapshotd");
	if (IS_ERR(snapshotd_task)) {
		pr_err("Failed to start snapshotd\n");
		return PTR_ERR(snapshotd_task);
	}

	return 0;
}

static int __init snapshotd_init(void)
{
	snapshotd_run();

	return 0;
}

module_init(snapshotd_init)

int get_zswapd_eswap_policy(void)
{
#define UNSET_ZRAM_WM_RATIO 0
	if (get_zram_wm_ratio_value() == UNSET_ZRAM_WM_RATIO)
		return CHECK_BUFFER_ONLY;
	else
		return CHECK_BUFFER_ZRAMRAITO_BOTH;
}

u64 get_policy_zram_wm_ratio(void)
{
#define DEFAULT_ZRAM_WM_RATIO 37
	enum zswapd_eswap_policy policy = get_zswapd_eswap_policy();
	if (policy == CHECK_BUFFER_ONLY)
		return DEFAULT_ZRAM_WM_RATIO;
	else
		return get_zram_wm_ratio_value();
}

int get_zram_current_watermark(void)
{
	long long diff_buffers;
	const unsigned int percent_constant = 10;
	u64 nr_total;
	u64 zram_wm_ratio = get_policy_zram_wm_ratio();

	nr_total = __totalram_pages();
	diff_buffers = get_avail_buffers_value() -
		calc_sys_cur_avail_buffers(); /* B_target - B_current */
	diff_buffers *= SZ_1M / PAGE_SIZE; /* MB to page */
	diff_buffers *=
		get_compress_ratio_value(); /* after_comp to before_comp */
	diff_buffers = diff_buffers * percent_constant /
		nr_total; /* page to ratio */
	/*lint -e666 */
	return min(zram_wm_ratio, zram_wm_ratio - diff_buffers);
	/*lint +e666 */
}

bool zram_watermark_ok(void)
{
	const unsigned int percent_constant = 100;
	u64 curr_ratio;
	u64 nr_zram_used;
	u64 nr_wm;

	curr_ratio = get_zram_current_watermark();
	nr_zram_used = hyperhold_get_zram_used_pages();
	nr_wm = __totalram_pages() * curr_ratio / percent_constant;
	if (nr_zram_used > nr_wm)
		return true;
	return false;
}

bool zram_watermark_exceed(void)
{
	u64 nr_zram_used;
	const u64 nr_wm =
		get_zram_critical_threshold_value() * (SZ_1M / PAGE_SIZE);

	if (!nr_wm)
		return false;

	nr_zram_used = hyperhold_get_zram_used_pages();
	if (nr_zram_used > nr_wm)
		return true;
	return false;
}

static bool too_many_file_cache(void)
{
	if (!is_zswapd_drop_caches_enabled())
		return false;

	unsigned long freemem;
	unsigned long active_file;
	unsigned long inactive_file;
	unsigned long active_anon;
	unsigned long inactive_anon;
	long free_swap;

	/* skip when free > 40M */
	freemem = global_zone_page_state(NR_FREE_PAGES);
	if (freemem > 10 * SZ_1K)
		return false;

	/* skip when anon > 1200M */
	active_anon = global_node_page_state(NR_ACTIVE_ANON);
	inactive_anon = global_node_page_state(NR_INACTIVE_ANON);
	if (active_anon + inactive_anon > 1200 * SZ_1M / PAGE_SIZE)
		return false;

	/* skip when free_swap > 2G */
	free_swap = get_nr_swap_pages();
	if (free_swap > 2 * SZ_1G / PAGE_SIZE)
		return false;

	/* skip when file < 2G */
	active_file = global_node_page_state(NR_ACTIVE_FILE);
	inactive_file = global_node_page_state(NR_INACTIVE_FILE);
	if (active_file + inactive_file < 2 * SZ_1G / PAGE_SIZE)
		return false;

	return true;
}

void wakeup_zswapd(pg_data_t *pgdat)
{
	unsigned long curr_interval;

	if (IS_ERR(pgdat->zswapd))
		return;

	if (!wq_has_sleeper(&pgdat->zswapd_wait))
		return;

	/* make anon pagefault snapshots */
	/* wake up snapshotd */
	if (atomic_read(&snapshotd_init_flag) == 1)
		wakeup_snapshotd();

	/* wake up when the buffer is lower than min_avail_buffer */
	if (min_buffer_is_suitable() && !too_many_file_cache()) {
		parad_stat_add(PARAD_ZSWAPD_SUITABLE, 1);
		return;
	}

	curr_interval =
		jiffies_to_msecs(jiffies - last_zswapd_time);
	if (curr_interval < zswapd_skip_interval) {
		count_vm_event(ZSWAPD_EMPTY_ROUND_SKIP_TIMES);
		parad_stat_add(PARAD_ZSWAPD_INTERVAL, 1);
		return;
	}

	atomic_set(&pgdat->zswapd_wait_flag, 1);
	parad_stat_add(PARAD_ZSWAPD_REALWAKE, 1);
	wake_up_interruptible(&pgdat->zswapd_wait);
}

void wake_all_zswapd(void)
{
	pg_data_t *pgdat = NULL;
	int nid;

	for_each_online_node(nid) {
		pgdat = NODE_DATA(nid);
		wakeup_zswapd(pgdat);
	}
}

static void zswapd_shrink_active_list(unsigned long nr_to_scan,
	struct lruvec *lruvec, struct scan_control *sc, enum lru_list lru)
{
	unsigned long nr_scanned;
	unsigned long nr_taken;
	LIST_HEAD(l_hold);
	LIST_HEAD(l_inactive);
	struct page *page = NULL;
	unsigned int nr_deactivate;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 4, 0))
	isolate_mode_t isolate_mode = 0;
#endif
	struct pglist_data *pgdat = lruvec_pgdat(lruvec);

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	struct zone_reclaim_stat *reclaim_stat = &lruvec->reclaim_stat;
	struct zone_reclaim_stat *node_reclaim_stat;

	node_reclaim_stat = &pgdat->lruvec.reclaim_stat;
#endif

	lru_add_drain();

	spin_lock_irq(&pgdat->lru_lock);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	nr_taken = isolate_lru_pages(nr_to_scan, lruvec, &l_hold,
				     &nr_scanned, sc, lru);
#else
	nr_taken = isolate_lru_pages(nr_to_scan, lruvec, &l_hold,
				     &nr_scanned, sc, isolate_mode, lru);
#endif
	__mod_node_page_state(pgdat, NR_ISOLATED_ANON, nr_taken);

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	reclaim_stat->recent_scanned[0] += nr_taken;
	node_reclaim_stat->recent_scanned[0] += nr_taken;
#endif

	__count_vm_events(PGREFILL, nr_scanned);
	count_memcg_events(lruvec_memcg(lruvec), PGREFILL, nr_scanned);
	spin_unlock_irq(&pgdat->lru_lock);

	while (!list_empty(&l_hold)) {
		cond_resched();
		page = lru_to_page(&l_hold);
		list_del(&page->lru);

		if (unlikely(!page_evictable(page))) {
			putback_lru_page(page);
			continue;
		}

		ClearPageActive(page);	/* we are de-activating */
		SetPageWorkingset(page);
		list_add(&page->lru, &l_inactive);
	}
	spin_lock_irq(&pgdat->lru_lock);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,4,0))
	nr_deactivate = move_pages_to_lru(lruvec, &l_inactive);
#else
	nr_deactivate = move_active_pages_to_lru(lruvec, &l_inactive,
			&l_hold, lru - LRU_ACTIVE);
#endif
	/*lint -e501*/
	__mod_node_page_state(pgdat, NR_ISOLATED_ANON, -nr_taken);
	/*lint +e501*/
	spin_unlock_irq(&pgdat->lru_lock);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	mem_cgroup_uncharge_list(&l_inactive);
	free_unref_page_list(&l_inactive);
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
	mem_cgroup_uncharge_list(&l_hold);
	free_unref_page_list(&l_hold);
#else
	mem_cgroup_uncharge_list(&l_hold);
	free_hot_cold_page_list(&l_hold, true);
#endif
	trace_mm_vmscan_lru_zswapd_shrink_active(pgdat->node_id,
			nr_taken, nr_deactivate, sc->priority);
}

static unsigned long zswapd_shrink_list(enum lru_list lru,
		unsigned long nr_to_scan, struct lruvec *lruvec,
		struct scan_control *sc)
{
#ifdef CONFIG_HW_RECLAIM_ACCT
	unsigned long nr_reclaimed;

	reclaimacct_shrinklist_start(is_file_lru(lru));
#endif
	if (is_active_lru(lru)) {
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
		if (inactive_is_low(lruvec, lru))
#else
		if (inactive_list_is_low(lruvec, is_file_lru(lru), sc, true))
#endif
			zswapd_shrink_active_list(nr_to_scan, lruvec, sc, lru);
#ifdef CONFIG_HW_RECLAIM_ACCT
		reclaimacct_shrinklist_end(is_file_lru(lru));
#endif
		return 0;
	}

#ifdef CONFIG_HW_RECLAIM_ACCT
	nr_reclaimed = shrink_inactive_list(nr_to_scan, lruvec, sc, lru);
	reclaimacct_shrinklist_end(is_file_lru(lru));
	return nr_reclaimed;
#else
	return shrink_inactive_list(nr_to_scan, lruvec, sc, lru);
#endif
}

static void zswapd_shrink_anon_memcg(struct pglist_data *pgdat,
		struct mem_cgroup *memcg, struct scan_control *sc,
		unsigned long *nr)
{
	struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);
	unsigned long nr_to_scan;
	enum lru_list lru;
	unsigned long nr_reclaimed = 0;
	struct blk_plug plug;

	blk_start_plug(&plug);

	while (nr[LRU_INACTIVE_ANON] || nr[LRU_ACTIVE_ANON]) {
		for (lru = 0; lru <= LRU_ACTIVE_ANON; lru++) {
			if (nr[lru]) {
				nr_to_scan = min(nr[lru], SWAP_CLUSTER_MAX);
				nr[lru] -= nr_to_scan;
				nr_reclaimed +=
					zswapd_shrink_list(lru,
							nr_to_scan,
							lruvec, sc);
			}
		}
	}
	blk_finish_plug(&plug);
	sc->nr_reclaimed += nr_reclaimed;

}

#ifdef CONFIG_PARA_SWAPD
static bool zswapd_shrink_anon_legacy(pg_data_t *pgdat, struct scan_control *sc)
#else
static bool zswapd_shrink_anon(pg_data_t *pgdat, struct scan_control *sc)
#endif
{
	unsigned long nr[NR_LRU_LISTS];
	struct mem_cgroup *memcg = NULL;
	const u32 percent_constant = 100;

	while ((memcg = get_next_memcg(memcg))) {
#ifdef CONFIG_MEMCG_SKIP_RECLAIM
		if (memcg->skip_reclaim_anon)
			continue;
#endif
		struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);
		u64 nr_active, nr_inactive;
		u64 nr_zram, nr_eswap;
		u64 zram_ratio;

		/* reclaim and try to meet the high buffer watermark */
		if (high_buffer_is_suitable()) {
			get_next_memcg_break(memcg);
			break;
		}

#ifdef CONFIG_MEMCG_PROTECT_LRU
		/* Skip if it is a protect memcg. */
		if (is_prot_memcg(memcg, false))
			continue;
#endif

		if (get_memcg_anon_refault_status(memcg)) {
			count_vm_event(ZSWAPD_MEMCG_REFAULT_SKIP);
			continue;
		}

		nr_active = lruvec_lru_size(lruvec, LRU_ACTIVE_ANON,
				MAX_NR_ZONES);
		nr_inactive = lruvec_lru_size(lruvec,
				LRU_INACTIVE_ANON, MAX_NR_ZONES);
		nr_zram = hyperhold_read_mcg_stats(memcg, MCG_ZRAM_PG_SZ);
		nr_eswap =
			hyperhold_read_mcg_stats(memcg, MCG_DISK_STORED_PG_SZ);

		zram_ratio = (nr_zram + nr_eswap) * percent_constant /
			(nr_inactive + nr_active + nr_zram + nr_eswap + 1);

		if (zram_ratio >= (u32)atomic_read(
				&memcg->memcg_reclaimed.ub_mem2zram_ratio)) {
			count_vm_event(ZSWAPD_MEMCG_RATIO_SKIP);
			continue;
		}

		nr[LRU_ACTIVE_ANON] = nr_active >> (unsigned int)sc->priority;
		nr[LRU_INACTIVE_ANON] =
				nr_inactive >> (unsigned int)sc->priority;
		nr[LRU_ACTIVE_FILE] = 0;
		nr[LRU_INACTIVE_FILE] = 0;
#ifdef CONFIG_HYPERHOLD_FILE_LRU
		zswapd_shrink_anon_memcg(pgdat, memcg, sc, nr);
#else
		shrink_node_memcg(pgdat, memcg, sc, nr);
#endif
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,0))
		shrink_slab(sc->gfp_mask, pgdat->node_id, memcg,
							sc->priority);
#endif
		if (sc->nr_reclaimed >= sc->nr_to_reclaim) {
			get_next_memcg_break(memcg);
			break;
		}
	}

	return sc->nr_scanned >= sc->nr_to_reclaim;
}

static unsigned long __reclaim_anon_memcg(struct pglist_data *pgdat,
		struct mem_cgroup *memcg, enum lru_list lru)
{
	LIST_HEAD(page_list);
	struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);
	unsigned long nr_reclaimed;
	struct page *page = NULL;
	struct reclaim_stat stat = {};
	struct scan_control sc = {
		.gfp_mask = GFP_KERNEL,
		.may_writepage = 1,
		.may_unmap = 1,
		.may_swap = 1,
	};
#ifdef CONFIG_HW_RECLAIM_ACCT
	reclaimacct_shrinklist_start(is_file_lru(lru));
#endif
	count_vm_event(FREEZE_RECLAIM_TIMES);
	move_pages_to_page_list(lruvec,
			lru, &page_list);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	nr_reclaimed = shrink_page_list(&page_list, NULL, &sc,
			&stat, true);
#else
	nr_reclaimed = shrink_page_list(&page_list, NULL, &sc,
			TTU_IGNORE_ACCESS, &stat, true);
#endif
	count_vm_events(FREEZE_RECLAIMED, nr_reclaimed);

	while (!list_empty(&page_list)) {
		page = lru_to_page(&page_list);
		list_del(&page->lru);
		putback_lru_page(page);
	}

#ifdef CONFIG_HW_RECLAIM_ACCT
	reclaimacct_shrinklist_end(is_file_lru(lru));
#endif
	return nr_reclaimed;
}

unsigned long reclaim_anon_memcg(struct pglist_data *pgdat,
		struct mem_cgroup *memcg, bool reclaim_all)
{
	unsigned long nr_reclaimed;

	nr_reclaimed = __reclaim_anon_memcg(pgdat, memcg, LRU_INACTIVE_ANON);
	if (reclaim_all)
		nr_reclaimed += __reclaim_anon_memcg(pgdat, memcg, LRU_ACTIVE_ANON);

	return nr_reclaimed;
}

#ifdef CONFIG_RAMTURBO
unsigned long all_active_reclaim_by_memcg(struct pglist_data *pgdat,
		struct mem_cgroup *memcg, unsigned int active_ratio)
{
	LIST_HEAD(page_list);
	struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);
	unsigned long nr_reclaimed;
	unsigned long nr_to_scan;
	unsigned long nr_to_shrink_active_size;
	struct page *page = NULL;
	unsigned long start_active, start_inactive, end_active, end_inactive;
	struct reclaim_stat stat = {};
	struct scan_control sc = {
		.gfp_mask = GFP_KERNEL,
		.may_writepage = 1,
		.may_unmap = 1,
		.may_swap = 1,
	};

#ifdef CONFIG_HW_RECLAIM_ACCT
	reclaimacct_shrinklist_start(false);
#endif
	start_active = jiffies;
	nr_to_shrink_active_size = lruvec_lru_size(lruvec, LRU_ACTIVE_ANON, MAX_NR_ZONES)
		/ PERCENT_CONSTANT * active_ratio;
	while (nr_to_shrink_active_size > 0) {
		nr_to_scan = min(nr_to_shrink_active_size, SWAP_CLUSTER_MAX);
		nr_to_shrink_active_size -= nr_to_scan;
		zswapd_shrink_active_list(nr_to_scan, lruvec, &sc, LRU_ACTIVE_ANON);
	}
	end_active = jiffies;
	pr_debug("RAMTURBO: %s active_lru shrinked %lupages(%luBytes) takes %lums, speed=%luMB/ms",
		__func__, nr_to_shrink_active_size, (nr_to_shrink_active_size * PAGE_SIZE),
		jiffies_to_msecs(end_active - start_active),
		(nr_to_shrink_active_size * PAGE_SIZE / SZ_1M * (jiffies_to_msecs(end_active - start_active))));

#ifdef CONFIG_HW_RECLAIM_ACCT
	reclaimacct_shrinklist_end(false);

	reclaimacct_shrinklist_start(false);
#endif

	start_inactive = jiffies;
	move_pages_to_page_list(lruvec,
			LRU_INACTIVE_ANON, &page_list);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	nr_reclaimed = shrink_page_list(&page_list, NULL, &sc,
			&stat, true);
#else
	nr_reclaimed = shrink_page_list(&page_list, NULL, &sc,
			TTU_IGNORE_ACCESS, &stat, true);
#endif

	while (!list_empty(&page_list)) {
		page = lru_to_page(&page_list);
		list_del(&page->lru);
		putback_lru_page(page);
	}

#ifdef CONFIG_HW_RECLAIM_ACCT
	reclaimacct_shrinklist_end(false);
#endif
	end_inactive = jiffies;

	pr_debug("RAMTURBO: %s inactive_lru shrinked %lupages(%luBytes) takes %lums, speed=%luMB/ms",
		__func__, nr_reclaimed, (nr_reclaimed * PAGE_SIZE),
		jiffies_to_msecs(end_inactive - start_inactive),
		(nr_reclaimed * PAGE_SIZE / SZ_1M * (jiffies_to_msecs(end_inactive - start_inactive))));

	/* Add active reclaimed size here, make it to total shrinked size*/
	nr_reclaimed += nr_to_shrink_active_size;

	pr_debug("RAMTURBO: %s total shrinked %lupages(%luBytes) takes %lums, speed=%luMB/ms",
		__func__, nr_reclaimed, (nr_reclaimed * PAGE_SIZE),
		jiffies_to_msecs(end_inactive - start_active),
		(nr_reclaimed * PAGE_SIZE / SZ_1M * (jiffies_to_msecs(end_inactive - start_active))));

	return nr_reclaimed;
}
#endif /* end of CONFIG_RAMTURBO */

#ifdef CONFIG_PARA_SWAPD
static void parad_zwork_fn(struct work_struct *work)
{
	struct mm_parad_work *parad =
		container_of(work, struct mm_parad_work, work);
	struct mem_cgroup *memcg  = parad->memcg;
	struct pglist_data *pgdat = parad->pgdat;
	struct scan_control sc;
	unsigned long nr_scanned, nr_reclaimed, nr_reclaimed_anon,
		isolate_count, nr_writedblock, nr_scanned_file, nr_scanned_anon,
		start = parad_get_counter();

	spin_lock_irq(&pgdat->lru_lock);
	sc = *parad->sc;
	spin_unlock_irq(&pgdat->lru_lock);

	nr_scanned        = sc.nr_scanned;
	nr_scanned_file   = sc.nr_scanned_file;
	nr_scanned_anon   = sc.nr_scanned_anon;
	nr_reclaimed      = sc.nr_reclaimed;
	nr_reclaimed_anon = sc.nr_reclaimed_anon;
	isolate_count     = sc.isolate_count;
#ifdef CONFIG_HUAWEI_SWAP_ZDATA
	nr_writedblock    = sc.nr_writedblock;
#endif

	zswapd_shrink_anon_memcg(pgdat, memcg, &sc, parad->nr);

	/* give back the real reclaimed info of per memcg to k/zswapd sc */
	spin_lock_irq(&pgdat->lru_lock);
	parad->sc->nr_scanned        += sc.nr_scanned - nr_scanned;
	parad->sc->nr_reclaimed      += sc.nr_reclaimed - nr_reclaimed;
	parad->sc->nr_reclaimed_anon += sc.nr_reclaimed_anon - nr_reclaimed_anon;
	parad->sc->isolate_count     += sc.isolate_count - isolate_count;
#ifdef CONFIG_HUAWEI_SWAP_ZDATA
	parad->sc->nr_writedblock    += sc.nr_writedblock - nr_writedblock;
#endif
	parad->sc->nr_scanned_file   += sc.nr_scanned_file - nr_scanned_file;
	parad->sc->nr_scanned_anon   += sc.nr_scanned_anon - nr_scanned_anon;
	spin_unlock_irq(&pgdat->lru_lock);

	parad_stat_add(PARAD_ZSWAPD_WORK, parad_get_counter() - start);
	clear_bit(F_PARAD_RECLAIMING, &parad->flags);
	css_put(&memcg->css);
}

static bool zswapd_shrink_anon(pg_data_t *pgdat, struct scan_control *sc)
{
	bool ret;
	struct mem_cgroup *memcg = NULL;
	struct mm_parad_work *parad;
	const unsigned int percent_constant = 100;

	unsigned long nr_scanned = sc->nr_scanned,
		      nr_reclaimed = sc->nr_reclaimed,
		      start = parad_get_counter();

	if (get_parad_enable() == 0) {
		ret = zswapd_shrink_anon_legacy(pgdat, sc);
		goto out;
	}

	while ((memcg = get_next_memcg(memcg))) {
#ifdef CONFIG_MEMCG_SKIP_RECLAIM
		if (memcg->skip_reclaim_anon)
			continue;
#endif
		u64 nr_active, nr_inactive, nr_zram, nr_eswap, zram_ratio;
		struct lruvec *lruvec = __mem_cgroup_lruvec(memcg, pgdat);

		/* reclaim and try to meet the high buffer watermark */
		if (high_buffer_is_suitable()) {
			get_next_memcg_break(memcg);
			break;
		}

		/*
		 * WARNING: need lru_lock of sc ?
		 **/
		if (sc->nr_reclaimed >= sc->nr_to_reclaim) {
			get_next_memcg_break(memcg);
			break;
		}

#ifdef CONFIG_MEMCG_PROTECT_LRU
		/* Skip if it is a protect memcg. */
		if (is_prot_memcg(memcg, false))
			continue;
#endif

		if (get_memcg_anon_refault_status(memcg)) {
			count_vm_event(ZSWAPD_MEMCG_REFAULT_SKIP);
			continue;
		}

		nr_active = lruvec_lru_size(lruvec, LRU_ACTIVE_ANON,
				MAX_NR_ZONES);
		nr_inactive = lruvec_lru_size(lruvec,
				LRU_INACTIVE_ANON, MAX_NR_ZONES);
		nr_zram = hyperhold_read_mcg_stats(memcg, MCG_ZRAM_PG_SZ);
		nr_eswap =
			hyperhold_read_mcg_stats(memcg, MCG_DISK_STORED_PG_SZ);

		zram_ratio = (nr_zram + nr_eswap) * percent_constant /
			(nr_inactive + nr_active + nr_zram + nr_eswap + 1);

		if (zram_ratio >= (u32)atomic_read(
				&memcg->memcg_reclaimed.ub_mem2zram_ratio)) {
			count_vm_event(ZSWAPD_MEMCG_RATIO_SKIP);
			continue;
		}

		if (test_and_set_bit(F_PARAD_RECLAIMING, &memcg->zpara.flags))
			continue;

		parad = &memcg->zpara;
		parad->nr[LRU_ACTIVE_ANON] = nr_active >> (unsigned int)sc->priority;
		parad->nr[LRU_INACTIVE_ANON] =
				nr_inactive >> (unsigned int)sc->priority;
		parad->nr[LRU_ACTIVE_FILE] = 0;
		parad->nr[LRU_INACTIVE_FILE] = 0;

		if (!parad->nr[LRU_ACTIVE_ANON] && !parad->nr[LRU_INACTIVE_ANON]) {
			clear_bit(F_PARAD_RECLAIMING, &parad->flags);
			continue;
		}

		parad->memcg = memcg;
		parad->pgdat = pgdat;
		parad->sc    = sc;

		css_get(&memcg->css);
		INIT_WORK(&parad->work, parad_zwork_fn);
		queue_work(mm_parad_wq, &parad->work);
	}

	flush_workqueue(mm_parad_wq);

	ret = sc->nr_scanned >= sc->nr_to_reclaim;
out:
	parad_stat_add(PARAD_ZSWAPD, parad_get_counter() - start);
	parad_stat_add(PARAD_ZSWAPD_NR_SCANNED, sc->nr_scanned - nr_scanned);
	parad_stat_add(PARAD_ZSWAPD_NR_RECLAIMED, sc->nr_reclaimed - nr_reclaimed);

	return ret;
}
#endif

static u64 __calc_nr_to_reclaim(void)
{
	u32 curr_buffers;
	u64 high_buffers;
	u64 max_reclaim_size_value;
	u64 reclaim_size = 0;

	high_buffers = get_high_avail_buffers_value();
	curr_buffers = calc_sys_cur_avail_buffers();
	max_reclaim_size_value = get_zswapd_max_reclaim_size();
	if (curr_buffers < high_buffers)
		reclaim_size = high_buffers - curr_buffers;

	/* once max reclaim target is max_reclaim_size_value */
	reclaim_size = min(reclaim_size, max_reclaim_size_value);

	return reclaim_size * SZ_1M / PAGE_SIZE; /* MB to pages */
}

static void zswapd_shrink_node(pg_data_t *pgdat)
{
	struct scan_control sc = {
		.gfp_mask = GFP_KERNEL,
		.order = 0,
		.priority = DEF_PRIORITY / 2,
		.may_writepage = !laptop_mode,
		.may_unmap = 1,
		.may_swap = 1,
		.reclaim_idx = MAX_NR_ZONES - 1,
	};
	const unsigned int increase_rate = 2;

	do {
		unsigned long nr_reclaimed = sc.nr_reclaimed;
		bool raise_priority = true;

		/* reclaim and try to meet the high buffer watermark */
		if (high_buffer_is_suitable())
			break;

		sc.nr_scanned = 0;
		sc.nr_to_reclaim = __calc_nr_to_reclaim();

		if (zswapd_shrink_anon(pgdat, &sc))
			raise_priority = false;
		if (try_to_freeze() || kthread_should_stop())
			break;

		nr_reclaimed = sc.nr_reclaimed - nr_reclaimed;
		count_vm_events(ZSWAPD_SCANNED, sc.nr_scanned);
		if (raise_priority || !nr_reclaimed)
			sc.priority--;
	} while (sc.priority >= 1);

	count_vm_events(ZSWAPD_RECLAIMED, sc.nr_reclaimed);

	/*
	 * When meets the first empty round, set the interval to t.
	 * If the following round is still empty, set the interval
	 * to 2t. If the round is always empty, then 4t, 8t, and so on.
	 * But make sure the interval is not more than the max_skip_interval.
	 * Once a non-empty round occurs, reset the interval to 0.
	 */
	if (sc.nr_reclaimed < get_empty_round_check_threshold_value()) {
		count_vm_event(ZSWAPD_EMPTY_ROUND);
		if (last_round_is_empty)
			zswapd_skip_interval = min(zswapd_skip_interval *
				increase_rate,
				get_max_skip_interval_value());/*lint !e666*/
		else
			zswapd_skip_interval =
				get_empty_round_skip_interval_value();
		last_round_is_empty = true;
	} else {
		zswapd_skip_interval = 0;
		last_round_is_empty = false;
	}
}

u64 zram_watermark_diff(void)
{
#define SWAP_MORE_ZRAM (50 * (SZ_1M))
	const unsigned int percent_constant = 100;
	u64 curr_ratio;
	u64 nr_zram_used;
	u64 nr_wm;

	curr_ratio = get_zram_current_watermark();
	nr_zram_used = hyperhold_get_zram_used_pages();
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
	nr_wm = totalram_pages() * curr_ratio / percent_constant;
#else
	nr_wm = totalram_pages * curr_ratio / percent_constant;
#endif
	if (nr_zram_used > nr_wm)
		return (nr_zram_used - nr_wm) * PAGE_SIZE + SWAP_MORE_ZRAM;

	return 0;
}

u64 zswapd_buffer_diff(void)
{
	u64 avail;
	u64 curr_buffers;

	avail = get_high_avail_buffers_value();
	curr_buffers = calc_sys_cur_avail_buffers();
	if (curr_buffers < avail)
		return (avail - curr_buffers) * SZ_1M;

	return 0;
}

u64 get_do_eswap_size(bool refault)
{
	u64 size = 0;
	enum zswapd_eswap_policy policy = get_zswapd_eswap_policy();
	if (policy == CHECK_BUFFER_ZRAMRAITO_BOTH)
		size = max(zram_watermark_diff(), zswapd_buffer_diff());
	else if (policy == CHECK_BUFFER_ONLY && (zram_watermark_ok() || refault))
		size = zswapd_buffer_diff();
	return size;
}

static void zswapd_drop_caches(struct super_block *sb, void *unused)
{
	struct inode *inode = NULL;
	struct inode *toput_inode = NULL;
	unsigned long nr_pages = 0;
	spin_lock(&sb->s_inode_list_lock);
	list_for_each_entry(inode, &sb->s_inodes, i_sb_list) {
		spin_lock(&inode->i_lock);
		/*
		 * We must skip inodes in unusual state. We may also skip
		 * inodes without pages but we deliberately won't in case
		 * we need to reschedule to avoid softlockups.
		 */
		if ((inode->i_state & (I_FREEING|I_WILL_FREE|I_NEW)) ||
		    (inode->i_mapping->nrpages == 0 && !need_resched())) {
			spin_unlock(&inode->i_lock);
			continue;
		}
		__iget(inode);
		spin_unlock(&inode->i_lock);
		spin_unlock(&sb->s_inode_list_lock);

		nr_pages = invalidate_mapping_pages(inode->i_mapping, 0, -1);
		iput(toput_inode);
		toput_inode = inode;

		cond_resched();
		spin_lock(&sb->s_inode_list_lock);
	}
	spin_unlock(&sb->s_inode_list_lock);
	iput(toput_inode);
	pr_info("zswapd: zswapd drop %lu pages", nr_pages);
}

static int zswapd(void *p)
{
	pg_data_t *pgdat = (pg_data_t *)p;
	struct task_struct *tsk = current;
	const struct cpumask *cpumask = cpumask_of_node(pgdat->node_id);

	/* save zswapd pid for schedule strategy */
	zswapd_pid = tsk->pid;

	if (!cpumask_empty(cpumask))
		set_cpus_allowed_ptr(tsk, cpumask);

	set_freezable();

	while (!kthread_should_stop()) {
		bool refault = false;
		u64 size = 0;

		/*lint -e578 */
		(void)wait_event_freezable(pgdat->zswapd_wait,
			atomic_read(&pgdat->zswapd_wait_flag));
		/*lint +e578 */
		atomic_set(&pgdat->zswapd_wait_flag, 0);
		count_vm_event(ZSWAPD_WAKEUP);
		zswapd_pressure_report(LEVEL_LOW);

		if (is_swap_full()) {
			zswapd_pressure_report(LEVEL_CRITICAL);
			count_vm_event(ZSWAPD_CRITICAL_PRESS);
		}
		if (too_many_file_cache()) {
			iterate_supers(zswapd_drop_caches, NULL);
			count_vm_event(DROP_PAGECACHE);
			count_vm_event(ZSWAPD_DROP_CACHE);
			pr_info("zswapd: too many file cache and low free, drop cache!");
		}

		if (get_area_anon_refault_status()) {
			refault = true;
			count_vm_event(ZSWAPD_REFAULT);
			parad_stat_add(PARAD_ZSWAPD_REFAULT, 1);
			goto do_eswap;
		}
		parad_stat_add(PARAD_ZSWAPD_SHRINK_ANON, 1);

#ifdef CONFIG_RAMTURBO
		if (unlikely(is_zram_anon_comp_enabled()))
			zswapd_shrink_node(pgdat);
#endif

do_eswap:
		last_zswapd_time = jiffies;
		if (!hyperhold_reclaim_work_running()) {
			size = get_do_eswap_size(refault);
			if (size >= SZ_1M) {
				count_vm_event(ZSWAPD_SWAPOUT);
#ifdef CONFIG_HYPERHOLD_CORE
				size = hyperhold_reclaim_in(size);
#endif
			}
		}

		if (!min_buffer_is_suitable()) {
			zswapd_pressure_report(LEVEL_MEDIUM);
			count_vm_event(ZSWAPD_MEDIUM_PRESS);
		}
	}

	return 0;
}

/*
 * This zswapd start function will be called by init and node-hot-add.
 */
int zswapd_run(int nid)
{
	pg_data_t *pgdat = NODE_DATA(nid);
	const unsigned int priority_less = 5;
	struct sched_param param = {
		.sched_priority = MAX_PRIO - priority_less,
	};

	if (pgdat->zswapd)
		return 0;

	atomic_set(&pgdat->zswapd_wait_flag, 0);
	pgdat->zswapd = kthread_create(zswapd, pgdat, "zswapd%d", nid);
	if (IS_ERR(pgdat->zswapd)) {
		pr_err("Failed to start zswapd on node %d\n", nid);
		return PTR_ERR(pgdat->zswapd);
	}

	sched_setscheduler_nocheck(pgdat->zswapd, SCHED_NORMAL, &param);
	set_user_nice(pgdat->zswapd, PRIO_TO_NICE(param.sched_priority));
	wake_up_process(pgdat->zswapd);

	return 0;
}

/*
 * Called by memory hotplug when all memory in a node is offlined.  Caller must
 * hold mem_hotplug_begin/end().
 */
void zswapd_stop(int nid)
{
	struct task_struct *zswapd = NODE_DATA(nid)->zswapd; /*lint !e578*/

	if (zswapd) {
		kthread_stop(zswapd);
		NODE_DATA(nid)->zswapd = NULL;
	}

	zswapd_pid = -1;
}

/* It's optimal to keep kswapds on the same CPUs as their memory, but
 * not required for correctness.  So if the last cpu in a node goes
 * away, we get changed to run anywhere: as the first one comes back,
 * restore their cpu bindings.
 */
static int zswapd_cpu_online(unsigned int cpu)
{
	int nid;

	for_each_node_state(nid, N_MEMORY) {
		pg_data_t *pgdat = NODE_DATA(nid);
		const struct cpumask *mask;

		mask = cpumask_of_node(pgdat->node_id);
		/*lint -e574 */
		if (cpumask_any_and(cpu_online_mask, mask) < nr_cpu_ids)
		/*lint +e574 */
			/* One of our CPUs online: restore mask */
			set_cpus_allowed_ptr(pgdat->zswapd, mask);
	}
	return 0;
}

static int __init zswapd_init(void)
{
	int nid;
	int ret;

	ret = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN,
					"mm/zswapd:online", zswapd_cpu_online,
					NULL);
	if (ret < 0) {
		pr_err("zswapd: failed to register hotplug callbacks.\n");
		return ret;
	}

	for_each_node_state(nid, N_MEMORY)
		zswapd_run(nid);

	return 0;
}
module_init(zswapd_init)
#endif
