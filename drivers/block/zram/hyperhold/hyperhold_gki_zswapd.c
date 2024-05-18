#include <linux/sched/mm.h>
#include <linux/mutex.h>
#include <linux/psi.h>
#include <trace/events/block.h>
#include <linux/cpuset.h>
#include <linux/sched.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/swap.h>
#include <uapi/linux/sched/types.h>
#include <linux/version.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/wait.h>
#include <linux/mmzone.h>
#include <linux/memcontrol.h>

#if (defined CONFIG_ZSWAPD_GKI) && (defined CONFIG_HYPERHOLD_GKI)
#include <linux/hyperhold_inf.h>

#include "hyperhold_gki_memcg_control.h"
#include "hyperhold_internal.h"
#include "hyperhold_gki_zswapd.h"
#include "hyperhold_area.h"


enum hhgki_zswapd_pressure_level {
	HYGKI_LEVEL_LOW = 0,
	HYGKI_LEVEL_MEDIUM,
	HYGKI_LEVEL_CRITICAL,
	HYGKI_LEVEL_COUNT
};

static wait_queue_head_t hhgki_snapshotd_wait;
static atomic_t hhgki_snapshotd_wait_flag;
static atomic_t hhgki_snapshotd_init_flag = ATOMIC_LONG_INIT(0);
static struct task_struct *hhgki_snapshotd_task;

static wait_queue_head_t hhgki_zswapd_wait;
static atomic_t hhgki_zswapd_wait_flag;
struct task_struct *hhgki_zswapd_task;
static pid_t hhgki_zswapd_pid = -1;
static unsigned long long hhgki_area_last_anon_pagefault;
static unsigned long hhgki_last_anon_snapshot_time;
unsigned long long hhgki_global_anon_refault_ratio;
unsigned long long hhgki_zswapd_skip_interval;
bool hhgki_last_round_is_empty;
unsigned long hhgki_last_zswapd_time;

#define HYKGI_MAX_APP_SCORE 1001
#define HYGKI_MAX_RATIO 100
static DEFINE_MUTEX(hhgki_pressure_event_lock);
struct eventfd_ctx *hhgki_zswapd_press_efd[HYGKI_LEVEL_COUNT];
#define ZRAM_WM_RATIO 37
#define COMPRESS_RATIO 30
atomic64_t hhgki_zram_wm_ratio = ATOMIC_LONG_INIT(ZRAM_WM_RATIO);
atomic64_t hhgki_compress_ratio = ATOMIC_LONG_INIT(COMPRESS_RATIO);
struct hhgki_zswapd_param {
	unsigned int min_score;
	unsigned int max_score;
	unsigned int ub_mem2zram_ratio;
	unsigned int ub_zram2ufs_ratio;
	unsigned int refault_threshold;
};
#define MAX_RECLAIM_SIZE 100
atomic_t hhgki_avail_buffers = ATOMIC_INIT(0);
atomic_t hhgki_min_avail_buffers = ATOMIC_INIT(0);
atomic_t hhgki_high_avail_buffers = ATOMIC_INIT(0);
atomic_t hhgki_eswap_avail_buffers = ATOMIC_INIT(0);
atomic_t hhgki_max_reclaim_size = ATOMIC_INIT(MAX_RECLAIM_SIZE);
atomic_t hhgki_pause_zswapd_interval = ATOMIC_INIT(3);
atomic_t hhgki_pause_zswapd = ATOMIC_INIT(0);
atomic64_t hhgki_free_swap_threshold = ATOMIC64_INIT(0);
atomic64_t hhgki_zram_crit_thres = ATOMIC_LONG_INIT(0);
atomic64_t hhgki_zswapd_min_anon_size = ATOMIC_LONG_INIT(0);
#define AREA_ANON_REFAULT_THRESHOLD 22000
#define ANON_REFAULT_SNAPSHOT_MIN_INTERVAL 200
#define EMPTY_ROUND_SKIP_INTERNVAL 20
#define MAX_SKIP_INTERVAL 1000
#define EMPTY_ROUND_CHECK_THRESHOLD 10
atomic64_t hhgki_area_anon_refault_threshold =
	ATOMIC_LONG_INIT(AREA_ANON_REFAULT_THRESHOLD);
atomic64_t hhgki_anon_refault_snapshot_min_interval =
	ATOMIC_LONG_INIT(ANON_REFAULT_SNAPSHOT_MIN_INTERVAL);
atomic64_t hhgki_empty_round_skip_interval =
	ATOMIC_LONG_INIT(EMPTY_ROUND_SKIP_INTERNVAL);
atomic64_t hhgki_max_skip_interval =
	ATOMIC_LONG_INIT(MAX_SKIP_INTERVAL);
atomic64_t hhgki_empty_round_check_threshold =
	ATOMIC_LONG_INIT(EMPTY_ROUND_CHECK_THRESHOLD);
static atomic_t hhgki_memcg_eswap_type = ATOMIC_INIT(0);
static atomic_t hhgki_memcg_eswap_memcg_ext_id = ATOMIC_INIT(0);

inline u64 hhgki_get_zram_wm_ratio_value(void)
{
	return atomic64_read(&hhgki_zram_wm_ratio);
}

inline u64 hhgki_get_compress_ratio_value(void)
{
	return atomic64_read(&hhgki_compress_ratio);
}

inline unsigned int hhgki_get_avail_buffers_value(void)
{
	return atomic_read(&hhgki_avail_buffers);
}

inline unsigned int hhgki_get_min_avail_buffers_value(void)
{
	return atomic_read(&hhgki_min_avail_buffers);
}

inline unsigned int hhgki_get_high_avail_buffers_value(void)
{
	return atomic_read(&hhgki_high_avail_buffers);
}

inline unsigned int hhgki_get_eswap_avail_buffers_value(void)
{
	return atomic_read(&hhgki_eswap_avail_buffers);
}

inline u64 hhgki_get_zswapd_max_reclaim_size(void)
{
	return atomic_read(&hhgki_max_reclaim_size);
}

inline unsigned int hhgki_get_zswapd_pause_interval(void)
{
	return atomic_read(&hhgki_pause_zswapd_interval);
}

inline unsigned int hhgki_get_zswapd_pause_stat(void)
{
	return atomic_read(&hhgki_pause_zswapd);
}

inline void hhgki_set_zswapd_pause_stat(unsigned int value)
{
	atomic_set(&hhgki_pause_zswapd, value);
}

inline u64 hhgki_get_free_swap_threshold_value(void)
{
	return atomic64_read(&hhgki_free_swap_threshold);
}

inline unsigned long long hhgki_get_area_anon_refault_threshold_value(void)
{
	return atomic64_read(&hhgki_area_anon_refault_threshold);
}

inline unsigned long hhgki_get_anon_refault_snapshot_min_interval_value(void)
{
	return atomic64_read(&hhgki_anon_refault_snapshot_min_interval);
}
inline unsigned long long hhgki_get_empty_round_skip_interval_value(void)
{
	return atomic64_read(&hhgki_empty_round_skip_interval);
}
inline unsigned long long hhgki_get_max_skip_interval_value(void)
{
	return atomic64_read(&hhgki_max_skip_interval);
}
inline unsigned long long hhgki_get_empty_round_check_threshold_value(void)
{
	return atomic64_read(&hhgki_empty_round_check_threshold);
}
inline unsigned long long hhgki_get_zswapd_min_anon_size(void)
{
	return atomic64_read(&hhgki_zswapd_min_anon_size);
}
inline u64 hhgki_get_zram_critical_threshold_value(void)
{
	return atomic64_read(&hhgki_zram_crit_thres);
}

#if (KERNEL_VERSION(5, 0, 0) < LINUX_VERSION_CODE)
static void hhgki_zswapd_pause_timer_handle(struct timer_list *unused)
{
	hhgki_set_zswapd_pause_stat(0);
}
#else
static void hhgki_zswapd_pause_timer_handle(unsigned long data)
{
	hhgki_set_zswapd_pause_stat(0);
}
#endif

#if (KERNEL_VERSION(5, 0, 0) < LINUX_VERSION_CODE)
static DEFINE_TIMER(hhgki_zswapd_pause_timer, hhgki_zswapd_pause_timer_handle);
#else
static DEFINE_TIMER(hhgki_zswapd_pause_timer, hhgki_zswapd_pause_timer_handle, 0, 0);
#endif



void hhgki_zswapd_pressure_report(enum hhgki_zswapd_pressure_level level)
{
	int ret;

	if (hhgki_zswapd_press_efd[level] == NULL){
		hh_print(HHLOG_INFO, "HHGKI: eventfd %u err \n", level);
		return;
	}

	ret = eventfd_signal(hhgki_zswapd_press_efd[level], 1);
	if (ret < 0)
		pr_err("HHGKI: SWAP-MM: %s : level:%u, ret:%d ", __func__, level, ret);
}


#define M(x) ((x) >> (20 - PAGE_SHIFT))
unsigned int hhgki_calc_sys_cur_avail_buffers(void)
{
	return M(si_mem_available());
}

pid_t hhgki_get_zswapd_pid(void)
{
	return hhgki_zswapd_pid;
}

static bool hhgki_min_buffer_is_suitable(void)
{
	u32 curr_buffers = hhgki_calc_sys_cur_avail_buffers();
	u32 min_avail = hhgki_get_min_avail_buffers_value();

	hh_print(HHLOG_INFO, "curr_buffers:%lu ,min_avail: %lu\n", curr_buffers, min_avail);
	return curr_buffers >= min_avail;
}

static bool hhgki_buffer_is_suitable(void)
{
	u32 curr_buffers = hhgki_calc_sys_cur_avail_buffers();
	u32 avail = hhgki_get_avail_buffers_value();

	hh_print(HHLOG_INFO, "curr_buffers:%lu ,avail: %lu\n", curr_buffers, avail);
	return curr_buffers >= avail;
}

static bool hhgki_high_buffer_is_suitable(void)
{
	u32 curr_buffers = hhgki_calc_sys_cur_avail_buffers();
	u32 high_avail = hhgki_get_high_avail_buffers_value();

	hh_print(HHLOG_INFO, "curr_buffers:%lu ,high_avail: %lu\n", curr_buffers, high_avail);
	return curr_buffers >= high_avail;
}


static void hhgki_snapshot_anon_refaults(void)
{
	struct mem_cgroup_ext *memcg_ext = NULL;

	while ((memcg_ext = get_next_memcg_ext(memcg_ext)))
		memcg_ext->memcg_reclaimed.reclaimed_pagefault =
			hyperhold_read_mcg_ext_stats(memcg_ext, MCG_ANON_FAULT_CNT);

	hhgki_area_last_anon_pagefault = hyperhold_get_zram_pagefault();
	hhgki_last_anon_snapshot_time = jiffies;
}

static bool hhgki_get_area_anon_refault_status(void)
{
	const unsigned int percent_constant = 1000;
	unsigned long long cur_anon_pagefault;
	unsigned long long cur_time;
	unsigned long long ratio;

	cur_anon_pagefault = hyperhold_get_zram_pagefault();
	cur_time = jiffies;

	if (cur_anon_pagefault == hhgki_area_last_anon_pagefault
		|| cur_time == hhgki_last_anon_snapshot_time)
		return false;

	ratio = (cur_anon_pagefault - hhgki_area_last_anon_pagefault) *
		percent_constant / (jiffies_to_msecs(cur_time -
					hhgki_last_anon_snapshot_time) + 1);

	hhgki_global_anon_refault_ratio = ratio;

	if (ratio > hhgki_get_area_anon_refault_threshold_value())
		return true;

	return false;
}

static bool hhgki_anon_size_is_low(void)
{
	unsigned long nr_anon_pages = global_node_page_state(NR_INACTIVE_ANON) +
		global_node_page_state(NR_ACTIVE_ANON);
	unsigned long anon_min_pages = hhgki_get_zswapd_min_anon_size() *
		SZ_1M / PAGE_SIZE; /* MB to pages */
	return nr_anon_pages < anon_min_pages;
}

void hhgki_wakeup_snapshotd(void)
{
	unsigned long curr_snapshot_interval;

	curr_snapshot_interval =
		jiffies_to_msecs(jiffies - hhgki_last_anon_snapshot_time);

	if (curr_snapshot_interval >=
		hhgki_get_anon_refault_snapshot_min_interval_value()) {
		atomic_set(&hhgki_snapshotd_wait_flag, 1);
		wake_up_interruptible(&hhgki_snapshotd_wait);
	}
}

static int hhgki_snapshotd(void *p)
{
	int ret;
	struct hyperhold_stat *stat = hyperhold_get_stat_obj();

	while (!kthread_should_stop()) {
		/*lint -e578 */
		ret = wait_event_interruptible(hhgki_snapshotd_wait,
			atomic_read(&hhgki_snapshotd_wait_flag));
		/*lint +e578 */
		if (ret)
			continue;

		atomic_set(&hhgki_snapshotd_wait_flag, 0);

		hhgki_snapshot_anon_refaults();
		atomic64_inc(&stat->zswapd_snapshot_times);
	}

	return 0;
}

void hhgki_set_snapshotd_init_flag(unsigned int val)
{
	atomic_set(&hhgki_snapshotd_init_flag, val);
}
/*
 * This hhgki_snapshotd start function will be called by init.
 */
int hhgki_snapshotd_run(void)
{
	atomic_set(&hhgki_snapshotd_wait_flag, 0);
	init_waitqueue_head(&hhgki_snapshotd_wait);
	hhgki_snapshotd_task = kthread_run(hhgki_snapshotd, NULL, "hhgki_snapshotd");
	if (IS_ERR(hhgki_snapshotd_task)) {
		pr_err("Failed to start hhgki_snapshotd\n");
		return PTR_ERR(hhgki_snapshotd_task);
	}

	return 0;
}

void hhgki_snapshotd_stop(void)
{
	struct task_struct *snapshotd_task = hhgki_snapshotd_task; /*lint !e578*/

	if (snapshotd_task) {
		kthread_stop(snapshotd_task);
		snapshotd_task = NULL;
	}
}

int hhgki_get_zram_current_watermark(void)
{
	long long diff_buffers;
	const unsigned int percent_constant = 10;
	u64 nr_total;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 61)
	nr_total = totalram_pages();
#else
	nr_total = totalram_pages;
#endif
	diff_buffers = hhgki_get_avail_buffers_value() - hhgki_calc_sys_cur_avail_buffers(); /* B_target - B_current */
	diff_buffers *= SZ_1M / PAGE_SIZE; /* MB to page */
  	diff_buffers *= hhgki_get_compress_ratio_value(); /* after_comp to before_comp */
	diff_buffers = diff_buffers * percent_constant / nr_total; /* page to ratio */
	/*lint -e666 */
	return min(hhgki_get_zram_wm_ratio_value(), hhgki_get_zram_wm_ratio_value() - diff_buffers);
	/*lint +e666 */
}

bool hhgki_zram_watermark_ok(void)
{
	const unsigned int percent_constant = 100;
	u64 curr_ratio;
	u64 nr_zram_used;
	u64 nr_wm;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 61)
        nr_wm = totalram_pages();
#else
        nr_wm = totalram_pages;
#endif

	curr_ratio = hhgki_get_zram_current_watermark();
	nr_zram_used = hyperhold_get_zram_used_pages();
	nr_wm = nr_wm * curr_ratio / percent_constant;
	if (nr_zram_used > nr_wm)
		return true;
	return false;
}

bool hhgki_zram_watermark_exceed(void)
{
	u64 nr_zram_used;
	const u64 nr_wm =
		hhgki_get_zram_critical_threshold_value() * (SZ_1M / PAGE_SIZE);

	if (!nr_wm)
		return false;

	nr_zram_used = hyperhold_get_zram_used_pages();
	if (nr_zram_used > nr_wm)
		return true;
	return false;
}

void hhgki_wakeup_zswapd(void)
{
	unsigned long curr_interval;
	struct hyperhold_stat *stat = hyperhold_get_stat_obj();

	if (IS_ERR(hhgki_zswapd_task))
		return;

	if (!wq_has_sleeper(&hhgki_zswapd_wait))
		return;

	/* make anon pagefault snapshots */
	/* wake up hhgki_snapshotd */
	if (atomic_read(&hhgki_snapshotd_init_flag) == 1)
		hhgki_wakeup_snapshotd();

	/* wake up when the buffer is lower than min_avail_buffer */
	if (hhgki_min_buffer_is_suitable())
		return;

	curr_interval =
		jiffies_to_msecs(jiffies - hhgki_last_zswapd_time);
	if (curr_interval < hhgki_zswapd_skip_interval) {
		atomic64_inc(&stat->zswapd_empty_round_skip_times);
		return;
	}

	atomic_set(&hhgki_zswapd_wait_flag, 1);
	wake_up_interruptible(&hhgki_zswapd_wait);
}

void hhgki_wake_all_zswapd(void)
{
	unsigned int zswapd_pause_interval_tmp;


	// 1 means pause trigger hhgki_zswapd_task
	if (hhgki_get_zswapd_pause_stat() == 1)
		return;

	hhgki_set_zswapd_pause_stat(1);
	zswapd_pause_interval_tmp = hhgki_get_zswapd_pause_interval();
	mod_timer(&hhgki_zswapd_pause_timer, jiffies + (HZ * zswapd_pause_interval_tmp));

	hhgki_wakeup_zswapd();
}

static unsigned long zswapd_shrink_memcg(unsigned long nr_to_shrink)
{
	struct mem_cgroup_ext *memcg_ext = NULL;
	struct mem_cgroup *memcg;
	int i, ub_mem2zram_ratio;
	unsigned long nr_shrinked = 0;
	unsigned long nr_to_shrink_mcg = 0;
	unsigned long nr_zram, nr_eswap;
	unsigned long memcg_anon_size = 0;
	unsigned long total = 0;

	while ((memcg_ext = get_next_memcg_ext(memcg_ext))) {

		/* reclaim and try to meet the high buffer watermark */
		if (hhgki_high_buffer_is_suitable()) {
			get_next_memcg_ext_break(memcg_ext);
			break;
		}

		memcg = memcg_ext->mcg;
		if(!memcg || !css_tryget(&memcg->css))
			continue;

		nr_zram = atomic64_read(&(memcg_ext->zram_page_size));
		nr_eswap = atomic64_read(&(memcg_ext->hyperhold_stored_pages));
		ub_mem2zram_ratio = atomic_read(&(memcg_ext->memcg_reclaimed.ub_mem2zram_ratio));

		for (i = 0; i < NR_INACTIVE_FILE; i++){
			memcg_anon_size += hyperhold_memcg_page_state_local(memcg, NR_LRU_BASE + i);
		}

		total = nr_zram + nr_eswap + memcg_anon_size;

		hh_print(HHLOG_INFO, "memcg: %d, anon_size is:%lu\n",get_mcg_id(memcg_ext),memcg_anon_size);

		i = ((nr_zram + nr_eswap) * 100)/(total + 1);

		if (i > ub_mem2zram_ratio)
			continue;

		nr_to_shrink_mcg = total*ub_mem2zram_ratio/100 - (nr_zram + nr_eswap);
		nr_shrinked += hyperhold_mcg_shrink(memcg->id.id, nr_to_shrink_mcg);

		hh_print(HHLOG_INFO, "memcg:%s id:%d, ext_id:%d, nr_shrinked: %lu\n", memcg_ext->name,
				memcg->id.id, get_mcg_id(memcg_ext), nr_shrinked);

		css_put(&memcg->css);

		if (nr_shrinked >= nr_to_shrink) {
			get_next_memcg_ext_break(memcg_ext);
			break;
		}
	}

	return nr_shrinked;
}

static u64 hhgki_calc_nr_to_reclaim(void)
{
	u32 curr_buffers;
	u64 high_buffers;
	u64 max_reclaim_size_value;
	u64 reclaim_size = 0;

	high_buffers = hhgki_get_high_avail_buffers_value();
	curr_buffers = hhgki_calc_sys_cur_avail_buffers();
	max_reclaim_size_value = hhgki_get_zswapd_max_reclaim_size();
	if (curr_buffers < high_buffers)
		reclaim_size = high_buffers - curr_buffers;

	/* once max reclaim target is max_reclaim_size_value */
	reclaim_size = min(reclaim_size, max_reclaim_size_value);

	return reclaim_size * SZ_1M / PAGE_SIZE; /* MB to pages */
}

static void zswapd_shrink()
{
	unsigned long nr_to_reclaim;
	unsigned long nr_reclaimed = 0;
	unsigned long loop_cnt = 3;
	const unsigned int increase_rate = 2;
	struct hyperhold_stat *stat = hyperhold_get_stat_obj();

	do {
		unsigned long last_reclaimed = 0;

		/* reclaim and try to meet the high buffer watermark */
		if (hhgki_high_buffer_is_suitable())
			break;

		nr_to_reclaim = hhgki_calc_nr_to_reclaim();
		hh_print(HHLOG_INFO, "nr_to_reclaim: %lu\n", nr_to_reclaim);
		last_reclaimed = zswapd_shrink_memcg(nr_to_reclaim);
		nr_reclaimed += last_reclaimed;

		if(nr_reclaimed >= nr_to_reclaim)
			break;

		if (try_to_freeze() || kthread_should_stop())
			break;

		loop_cnt--;
	} while (loop_cnt >= 1);

	/*
	 * When meets the first empty round, set the interval to t.
	 * If the following round is still empty, set the interval
	 * to 2t. If the round is always empty, then 4t, 8t, and so on.
	 * But make sure the interval is not more than the max_skip_interval.
	 * Once a non-empty round occurs, reset the interval to 0.
	 */
	if (nr_reclaimed < hhgki_get_empty_round_check_threshold_value()) {
		if(stat)
			atomic64_inc(&stat->zswapd_empty_round);
		if (hhgki_last_round_is_empty)
			hhgki_zswapd_skip_interval = min(hhgki_zswapd_skip_interval *
				increase_rate,
				hhgki_get_max_skip_interval_value());/*lint !e666*/
		else
			hhgki_zswapd_skip_interval =
				hhgki_get_empty_round_skip_interval_value();
		hhgki_last_round_is_empty = true;
	} else {
		hhgki_zswapd_skip_interval = 0;
		hhgki_last_round_is_empty = false;
	}
	hh_print(HHLOG_INFO, "HHGKI: nr_reclaimed: %lu ,hhgki_zswapd_skip_interval: %llu ,hhgki_last_round_is_empty: %d\n",
		nr_reclaimed, hhgki_zswapd_skip_interval, hhgki_last_round_is_empty);
}

static int hhgki_zswapd(void *p)
{
	struct task_struct *tsk = current;
	struct hyperhold_stat *stat = hyperhold_get_stat_obj();

	/* save hhgki_zswapd pid for schedule strategy */
	hhgki_zswapd_pid = tsk->pid;
	set_freezable();

	while (!kthread_should_stop()) {
		bool refault = false;
		bool low_anon = false;
		u32 curr_buffers, avail;
		u64 size;

		/*lint -e578 */
		(void)wait_event_freezable(hhgki_zswapd_wait,
			atomic_read(&hhgki_zswapd_wait_flag));
		/*lint +e578 */
		atomic_set(&hhgki_zswapd_wait_flag, 0);
		atomic64_inc(&stat->zswapd_wakeup);
		hhgki_zswapd_pressure_report(HYGKI_LEVEL_LOW);
		hh_print(HHLOG_INFO, "hhgki_zswapd is ZSWAPD_WAKEUP\n");

		if (hhgki_get_area_anon_refault_status()) {
			refault = true;
			atomic64_inc(&stat->zswapd_refault);
			hh_print(HHLOG_INFO, "hhgki_zswapd is ZSWAPD_REFAULT\n");
			goto do_eswap;
		}

		if (hhgki_anon_size_is_low()) {
			low_anon = true;
			hh_print(HHLOG_INFO, "hhgki_zswapd hhgki_anon_size_is_low\n");
			goto do_eswap;
		}

		zswapd_shrink();
		hhgki_last_zswapd_time = jiffies;

do_eswap:
		if (!hyperhold_reclaim_work_running() &&
			(hhgki_zram_watermark_ok() || refault || low_anon)) {

			avail = hhgki_get_eswap_avail_buffers_value();
			if (avail == 0)
				avail = hhgki_get_high_avail_buffers_value();
			curr_buffers = hhgki_calc_sys_cur_avail_buffers();
			size = (avail - curr_buffers) * SZ_1M;
			hh_print(HHLOG_INFO, "curr_buffers:%lu ,avail: %lu\n", curr_buffers, avail);
			if (curr_buffers < avail) {
				atomic64_inc(&stat->zswapd_swapout);
				size = hyperhold_reclaim_in(size);
				hh_print(HHLOG_INFO, "HHGKI: ZSWAPD_SWAPOUT size: %llu\n", size);
			}
		}

		if (!hhgki_buffer_is_suitable()) {
			if (hhgki_zram_watermark_exceed()) {
				hhgki_zswapd_pressure_report(HYGKI_LEVEL_CRITICAL);
				atomic64_inc(&stat->zswapd_critical_press);
				hh_print(HHLOG_INFO, "ZSWAPD_CRITICAL_PRESS\n");
			} else {
				hhgki_zswapd_pressure_report(HYGKI_LEVEL_MEDIUM);
				atomic64_inc(&stat->zswapd_medium_press);
				hh_print(HHLOG_INFO, "ZSWAPD_MEDIUM_PRESS\n");
			}
		}
	}

	return 0;
}

/*
 * This hhgki_zswapd_task start function will be called by init and node-hot-add.
 */
int hhgki_zswapd_run(void)
{
	const unsigned int priority_less = 5;
	struct sched_param param = {
		.sched_priority = MAX_PRIO - priority_less,
	};

	if (hhgki_zswapd_task || !global_settings.zram)
		return 0;

	atomic_set(&hhgki_zswapd_wait_flag, 0);
	init_waitqueue_head(&hhgki_zswapd_wait);
	hhgki_zswapd_task = kthread_create(hhgki_zswapd, NULL, "hhgki_zswapd");
	if (IS_ERR(hhgki_zswapd_task)) {
		pr_err("Failed to start hhgki_zswapd_task\n");
		return PTR_ERR(hhgki_zswapd_task);
	}

	sched_setscheduler_nocheck(hhgki_zswapd_task, SCHED_NORMAL, &param);
	set_user_nice(hhgki_zswapd_task, PRIO_TO_NICE(param.sched_priority));
	wake_up_process(hhgki_zswapd_task);

	return 0;
}

void hhgki_zswapd_stop(void)
{
	struct task_struct *hhgki_zswapd = hhgki_zswapd_task; /*lint !e578*/

	if (hhgki_zswapd) {
		kthread_stop(hhgki_zswapd);
		hhgki_zswapd = NULL;
	}

	hhgki_zswapd_pid = -1;
}

int hhgki_zswapd_init(void)
{
	hhgki_snapshotd_run();
	hhgki_zswapd_run();
	return 0;
}


int hhgki_zswapd_deinit(void)
{
	hhgki_zswapd_stop();
	hhgki_snapshotd_stop();
	return 0;
}

ssize_t hyperhold_avail_buffers_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	const unsigned int params_num = 4;
	unsigned int avail_buffers_value;
	unsigned int min_avail_buffers_value;
	unsigned int high_avail_buffers_value;
	u64 free_swap_threshold_value;

	buf = skip_spaces(buf);

	if (sscanf(buf, "%u,%u,%u,%llu",
		&avail_buffers_value,
		&min_avail_buffers_value,
		&high_avail_buffers_value,
		&free_swap_threshold_value) != params_num)
		return -EINVAL;
	atomic_set(&hhgki_avail_buffers, avail_buffers_value);
	atomic_set(&hhgki_min_avail_buffers, min_avail_buffers_value);
	atomic_set(&hhgki_high_avail_buffers, high_avail_buffers_value);
	atomic64_set(&hhgki_free_swap_threshold,
		(free_swap_threshold_value * (SZ_1M / PAGE_SIZE)));

	if (atomic_read(&hhgki_min_avail_buffers) == 0)
		hhgki_set_snapshotd_init_flag(0);
	else
		hhgki_set_snapshotd_init_flag(1);

	hhgki_wake_all_zswapd();

	return len;
}

ssize_t hyperhold_eswap_avail_buffers_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
    const unsigned int base = 10;
	unsigned int eswap_avail_buffers_value;
	int ret;

	buf = skip_spaces(buf);
	ret = kstrtouint(buf, base, &eswap_avail_buffers_value);
	if (ret)
		return -EINVAL;

	atomic_set(&hhgki_eswap_avail_buffers, eswap_avail_buffers_value);

	return len;
}

ssize_t hyperhold_zswapd_max_reclaim_size_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	const unsigned int base = 10;
	u32 max_reclaim_size_value;
	int ret;

	buf = skip_spaces(buf);
	ret = kstrtouint(buf, base, &max_reclaim_size_value);
	if (ret)
	   return -EINVAL;

	atomic_set(&hhgki_max_reclaim_size, max_reclaim_size_value);

	return len;
}

ssize_t hyperhold_pause_zswapd_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	const unsigned int base = 10;
	unsigned int pause_zswapd_interval_tmp;
	int ret;

	buf = skip_spaces(buf);
	ret = kstrtouint(buf, base, &pause_zswapd_interval_tmp);
	if (ret)
		return -EINVAL;

	atomic_set(&hhgki_pause_zswapd_interval, pause_zswapd_interval_tmp);

	return len;
}

ssize_t hyperhold_area_anon_refault_threshold_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	u64 val;
	int ret;
	const unsigned int base = 10;

	buf = skip_spaces(buf);
	ret = kstrtoull(buf, base, &val);
	if (ret)
		return -EINVAL;

	atomic64_set(&hhgki_area_anon_refault_threshold, val);

	return len;
}

ssize_t hyperhold_empty_round_skip_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	u64 val;
	int ret;
	const unsigned int base = 10;

	buf = skip_spaces(buf);
	ret = kstrtoull(buf, base, &val);
	if (ret)
		return -EINVAL;

	atomic64_set(&hhgki_empty_round_skip_interval, val);

	return len;
}

ssize_t hyperhold_max_skip_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	u64 val;
	int ret;
	const unsigned int base = 10;

	buf = skip_spaces(buf);
	ret = kstrtoull(buf, base, &val);
	if (ret)
		return -EINVAL;

	atomic64_set(&hhgki_max_skip_interval, val);

	return len;
}

ssize_t hyperhold_empty_round_check_threshold_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	u64 val;
	int ret;
	const unsigned int base = 10;

	buf = skip_spaces(buf);
	ret = kstrtoull(buf, base, &val);
	if (ret)
		return -EINVAL;

	atomic64_set(&hhgki_empty_round_check_threshold, val);

	return len;
}

ssize_t hyperhold_anon_refault_snapshot_min_interval_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	u64 val;
	int ret;
	const unsigned int base = 10;

	buf = skip_spaces(buf);
	ret = kstrtoull(buf, base, &val);
	if (ret)
		return -EINVAL;

	atomic64_set(&hhgki_anon_refault_snapshot_min_interval, val);

	return len;
}

ssize_t hyperhold_zswapd_min_anon_size_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	u64 val;
	int ret;
	const unsigned int base = 10;

	buf = skip_spaces(buf);
	ret = kstrtoull(buf, base, &val);
	if (ret)
		return -EINVAL;

	atomic64_set(&hhgki_zswapd_min_anon_size, val);

	return len;
}

ssize_t hyperhold_zram_critical_threshold_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	u64 val;
	int ret;
	const unsigned int base = 10;

	buf = skip_spaces(buf);
	ret = kstrtoull(buf, base, &val);
	if (ret)
		return -EINVAL;

	atomic64_set(&hhgki_zram_crit_thres, val);

	return len;
}

ssize_t hyperhold_zswapd_pressure_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	const unsigned int params_num = 2;
	unsigned int efd;
	unsigned int level;
	struct fd efile;
	int ret;

	hh_print(HHLOG_INFO, "HHGKI: eventfd start\n");
	buf = skip_spaces(buf);
	if (sscanf(buf, "%u %u", &efd, &level) != params_num) {
		hh_print(HHLOG_INFO, "HHGKI: eventfd num err\n");
		return -EINVAL;
	}

	if (level >= HYGKI_LEVEL_COUNT)
		return -EINVAL;

	hh_print(HHLOG_INFO, "HHGKI: receive eventfd %u \n", level);
	mutex_lock(&hhgki_pressure_event_lock);
	efile = fdget(efd);
	if (!efile.file) {
		hh_print(HHLOG_INFO, "HHGKI: eventfd %u err \n", level);
		ret = -EBADF;
		goto out;
	}
	hhgki_zswapd_press_efd[level] = eventfd_ctx_fileget(efile.file);
	if (IS_ERR(hhgki_zswapd_press_efd[level])) {
		ret = PTR_ERR(hhgki_zswapd_press_efd[level]);
		hh_print(HHLOG_INFO, "HHGKI: eventfd %u err \n", level);
		goto out_put_efile;
	}
	fdput(efile);
	mutex_unlock(&hhgki_pressure_event_lock);
	hh_print(HHLOG_INFO, "HHGKI: receive eventfd %u ok \n", level);
	return len;

out_put_efile:
	fdput(efile);
out:
	mutex_unlock(&hhgki_pressure_event_lock);

	hh_print(HHLOG_INFO, "HHGKI: eventfd error \n");
	return len;
}

ssize_t hyperhold_zswapd_pid_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%d\n", hhgki_get_zswapd_pid());
}

ssize_t hyperhold_zswapd_single_memcg_param_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	struct mem_cgroup_ext *memcg_ext;
	unsigned short memcg_id;
	unsigned int ub_mem2zram_ratio;
	unsigned int ub_zram2ufs_ratio;
	unsigned int refault_threshold;
	const unsigned int params_num = 4;

	buf = skip_spaces(buf);
	if (sscanf(buf, "%hu,%u,%u,%u",
		&memcg_id,
		&ub_mem2zram_ratio,
		&ub_zram2ufs_ratio,
		&refault_threshold) != params_num)
		return -EINVAL;

	memcg_ext = mem_cgroup_ext_from_mcg_id(memcg_id);

	if (ub_mem2zram_ratio > HYGKI_MAX_RATIO || ub_zram2ufs_ratio > HYGKI_MAX_RATIO || !memcg_ext)
		return -EINVAL;

	atomic_set(&memcg_ext->memcg_reclaimed.ub_mem2zram_ratio,
		ub_mem2zram_ratio);
	atomic_set(&memcg_ext->memcg_reclaimed.ub_zram2ufs_ratio,
		ub_zram2ufs_ratio);
	atomic_set(&memcg_ext->memcg_reclaimed.refault_threshold,
		refault_threshold);

	return len;
}

ssize_t hyperhold_zram_wm_ratio_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
    int ret;
	u64 val;

	ret = kstrtoull(buf, 0, &val);
	if (unlikely(ret)) {
			hh_print(HHLOG_ERR, "zram_wm_ratio is error!\n");
			return EINVAL;
	}

	if (val > HYGKI_MAX_RATIO)
		return -EINVAL;

	atomic64_set(&hhgki_zram_wm_ratio, val);

	return len;
}

ssize_t hyperhold_compress_ratio_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
    int ret;
	u64 val;

	ret = kstrtoull(buf, 0, &val);
	if (unlikely(ret)) {
			hh_print(HHLOG_ERR, "hyperhold_compress_ratio_store is error!\n");
			return EINVAL;
	}

	if (val > HYGKI_MAX_RATIO)
		return -EINVAL;

	atomic64_set(&hhgki_compress_ratio, val);

	return len;
}

ssize_t hyperhold_zswapd_pressure_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	unsigned int buffers = hhgki_calc_sys_cur_avail_buffers();

 	return scnprintf(buf, PAGE_SIZE, "buffer size: %u MB, recent refault: %llu\n",
		buffers, hhgki_global_anon_refault_ratio);
}

ssize_t hyperhold_avail_buffers_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	ssize_t sz;
	sz = scnprintf(buf, PAGE_SIZE, "hhgki_avail_buffers: %u\n"
									"hhgki_min_avail_buffers: %u\n"
									"hhgki_high_avail_buffers: %u\n"
									"hhgki_free_swap_threshold: %u\n"
									"hhgki_eswap_avail_buffers: %u\n",
									atomic_read(&hhgki_avail_buffers),
									atomic_read(&hhgki_min_avail_buffers),
									atomic_read(&hhgki_high_avail_buffers),
									(atomic64_read(&hhgki_free_swap_threshold) * PAGE_SIZE / SZ_1M),
									atomic_read(&hhgki_eswap_avail_buffers));
	return sz;
}

ssize_t hyperhold_eswap_avail_buffers_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "hhgki_eswap_avail_buffers: %u\n",
		atomic_read(&hhgki_eswap_avail_buffers));
}

ssize_t hyperhold_zswapd_max_reclaim_size_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "zswapd_max_reclaim_size: %u\n",
		atomic_read(&hhgki_max_reclaim_size));
}

ssize_t hyperhold_pause_zswapd_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "pause_zswapd_interval: %u\n"
										"pause_zswapd_stat: %u\n",
										atomic_read(&hhgki_pause_zswapd_interval),
										atomic_read(&hhgki_pause_zswapd));
}

ssize_t hyperhold_area_anon_refault_threshold_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%lld\n", atomic64_read(&hhgki_area_anon_refault_threshold));
}

ssize_t hyperhold_empty_round_skip_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%lld\n", atomic64_read(&hhgki_empty_round_skip_interval));
}

ssize_t hyperhold_max_skip_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%lld\n", atomic64_read(&hhgki_max_skip_interval));
}

ssize_t hyperhold_empty_round_check_threshold_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%lld\n", atomic64_read(&hhgki_empty_round_check_threshold));
}

ssize_t hyperhold_anon_refault_snapshot_min_interval_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%lld\n", atomic64_read(&hhgki_anon_refault_snapshot_min_interval));
}

ssize_t hyperhold_zswapd_min_anon_size_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%lld\n", atomic64_read(&hhgki_zswapd_min_anon_size));
}

ssize_t hyperhold_zram_critical_threshold_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%lld\n", atomic64_read(&hhgki_zram_crit_thres));
}

ssize_t hyperhold_zswapd_single_memcg_param_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct mem_cgroup_ext *memcg = NULL;
	ssize_t size = 0;

	while ((memcg = get_next_memcg_ext(memcg))) {
		size += scnprintf(buf + size, PAGE_SIZE, "%d,%d,%d,%d,%d\n",
				memcg->mcg->id.id,
				get_mcg_id(memcg),
				memcg->memcg_reclaimed.ub_mem2zram_ratio,
				memcg->memcg_reclaimed.ub_zram2ufs_ratio,
				memcg->memcg_reclaimed.refault_threshold);
	}

	return size;
}


ssize_t hyperhold_zram_wm_ratio_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%llu\n", atomic64_read(&hhgki_zram_wm_ratio));
}

ssize_t hyperhold_compress_ratio_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
 	return scnprintf(buf, PAGE_SIZE, "%llu\n", atomic64_read(&hhgki_compress_ratio));
}
ssize_t hyperhold_psi_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return hyperhold_psi_show(buf, PAGE_SIZE, 0);
}

ssize_t hyperhold_eswap_stat_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	int mcg_id;
	int type;

	if (sscanf(buf, "%d,%d", &type, &mcg_id) !=
		HYPERHOLD_MEMCG_ESWAP_ITEMS) {
		hh_print(HHLOG_ERR, "eswap invalid\n");
		return -EINVAL;
	}

	atomic_set(&hhgki_memcg_eswap_type, type);
	atomic_set(&hhgki_memcg_eswap_memcg_ext_id, mcg_id);
	return len;
}

ssize_t hyperhold_eswap_stat_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int mcg_id;
	int type;

	type = atomic_read(&hhgki_memcg_eswap_type);
	mcg_id = atomic_read(&hhgki_memcg_eswap_memcg_ext_id);

	return hyperhold_memcg_eswap_info(type, buf, mcg_id);
}

ssize_t hyperhold_zswapd_stat_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret;
	struct hyperhold_stat *stat = hyperhold_get_stat_obj();
	if(!stat) {
		return  scnprintf(buf, PAGE_SIZE, "stat err\n");
	}

	ret = scnprintf(buf, PAGE_SIZE,
		    "zswapd_running:%llu\n"
			"zswapd_hit_refaults:%llu\n"
			"zswapd_medium_press:%llu\n"
			"zswapd_critical_press:%llu\n"
			"zswapd_swapout:%llu\n"
			"zswapd_empty_round:%llu\n"
			"zswapd_empty_round_skip_times:%llu\n"
			"zswapd_snapshot_times:%llu\n",
			atomic64_read(&stat->zswapd_wakeup),
			atomic64_read(&stat->zswapd_refault),
			atomic64_read(&stat->zswapd_medium_press),
			atomic64_read(&stat->zswapd_critical_press),
			atomic64_read(&stat->zswapd_swapout),
			atomic64_read(&stat->zswapd_empty_round),
			atomic64_read(&stat->zswapd_empty_round_skip_times),
			atomic64_read(&stat->zswapd_snapshot_times));

	return ret;
}



ssize_t hyperhold_zswapd_trigger_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	hhgki_wake_all_zswapd();
	return len;
}

ssize_t hyperhold_zswapd_trigger_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = scnprintf(buf, PAGE_SIZE, "zswapd_pause_stat: %u\n"
			"zswapd_pause_interval: %u\n"
			"min_buffer_is_suitable: %d\n",
			hhgki_get_zswapd_pause_stat(),
			hhgki_get_zswapd_pause_interval(),
			hhgki_min_buffer_is_suitable()
			);
	return ret;
}

pid_t hyperhold_gki_zswapd_pid_get(void)
{
	return hhgki_zswapd_pid;
}


#endif
