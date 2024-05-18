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

#ifndef HYPERHOLD_INTERNAL_H
#define HYPERHOLD_INTERNAL_H

#include <linux/version.h>
#include <linux/sched.h>
#include <linux/hyperhold_inf.h>

#ifdef CONFIG_HYPERHOLD_GKI
#include <linux/cgroup.h>
#include "hyperhold_gki_memcg_control.h"
#endif

#ifdef CONFIG_HYPERHOLD_GKI
#define HYPERHOLD_MEMCG_ESWAP_SINGLE 1
#define HYPERHOLD_MEMCG_ESWAP_ALL 2
#define HYPERHOLD_MEMCG_ESWAP_ITEMS 2
#endif


#define MAX_FAIL_RECORD_NUM 10

enum {
	HHLOG_ERR = 0,
	HHLOG_WARN,
	HHLOG_INFO,
	HHLOG_DEBUG,
	HHLOG_MAX
};

static inline void pr_none(void) {}

#define pt(f, ...)	pr_err("<%s>:"f, __func__, ##__VA_ARGS__)
#define cur_lvl()	hyperhold_loglevel()

#define hh_print(l, f, ...) \
	(l <= cur_lvl() ? pt(f, ##__VA_ARGS__) : pr_none())

int hyperhold_loglevel(void);

struct zs_ext_para {
	struct hyperhold_page_pool *pool;
	size_t alloc_size;
	bool fast;
	bool nofail;
};

struct hyperhold_cfg {
	atomic_t enable;
	atomic_t reclaim_in_enable;
	atomic_t watchdog_protect;
	int log_level;
	struct timer_list wdt_timer;
	unsigned long wdt_expire_s;
	struct hyperhold_stat *stat;
	struct workqueue_struct *reclaim_wq;
	struct zram *zram;
	const char *mapper_name;
	struct block_device *real_bdev;
};

#ifdef CONFIG_HYPERHOLD_GKI
extern struct hyperhold_cfg global_settings;
#endif

enum hyperhold_scenario {
	HYPERHOLD_RECLAIM_IN = 0,
	HYPERHOLD_FAULT_OUT,
	HYPERHOLD_BATCH_OUT,
	HYPERHOLD_PRE_OUT,
	HYPERHOLD_SCENARIO_BUTT
};

enum hyperhold_key_point {
	HYPERHOLD_START = 0,
	HYPERHOLD_INIT,
	HYPERHOLD_IOENTRY_ALLOC,
	HYPERHOLD_FIND_EXTENT,
	HYPERHOLD_IO_EXTENT,
	HYPERHOLD_SEGMENT_ALLOC,
	HYPERHOLD_BIO_ALLOC,
	HYPERHOLD_SUBMIT_BIO,
	HYPERHOLD_END_IO,
	HYPERHOLD_SCHED_WORK,
	HYPERHOLD_END_WORK,
	HYPERHOLD_CALL_BACK,
	HYPERHOLD_WAKE_UP,
	HYPERHOLD_ZRAM_LOCK,
	HYPERHOLD_DONE,
	HYPERHOLD_KYE_POINT_BUTT
};

enum hyperhold_fail_point {
	HYPERHOLD_FAULT_OUT_INIT_FAIL = 0,
	HYPERHOLD_FAULT_OUT_ENTRY_ALLOC_FAIL,
	HYPERHOLD_FAULT_OUT_IO_ENTRY_PARA_FAIL,
	HYPERHOLD_FAULT_OUT_SEGMENT_ALLOC_FAIL,
	HYPERHOLD_FAULT_OUT_BIO_ALLOC_FAIL,
	HYPERHOLD_FAULT_OUT_BIO_ADD_FAIL,
	HYPERHOLD_FAULT_OUT_IO_FAIL,
	HYPERHOLD_FAIL_POINT_BUTT
};

struct hyperhold_fail_record {
	unsigned char task_comm[TASK_COMM_LEN];
	enum hyperhold_fail_point point;
	ktime_t time;
	u32 index;
	int ext_id;
};

struct hyperhold_fail_record_info {
	int num;
	spinlock_t lock;
	struct hyperhold_fail_record record[MAX_FAIL_RECORD_NUM];
};

struct hyperhold_key_point_info {
	unsigned int record_cnt;
	unsigned int end_cnt;
	ktime_t first_time;
	ktime_t last_time;
	s64 proc_total_time;
	s64 proc_max_time;
	unsigned long long last_ravg_sum;
	unsigned long long proc_ravg_sum;
	spinlock_t time_lock;
};

struct hyperhold_key_point_record {
	struct timer_list lat_monitor;
	unsigned long warning_threshold;
	int page_cnt;
	int segment_cnt;
	int nice;
	pid_t pid;
	pid_t tgid;
	bool timeout_flag;
	unsigned char task_comm[TASK_COMM_LEN];
	struct task_struct *task;
	enum hyperhold_scenario scenario;
	struct hyperhold_key_point_info key_point[HYPERHOLD_KYE_POINT_BUTT];
};

struct hyperhold_lat_stat {
	atomic64_t total_lat;
	atomic64_t max_lat;
	atomic64_t timeout_cnt;
};

struct hyperhold_stat {
	atomic64_t reclaimin_cnt;
	atomic64_t reclaimin_bytes;
	atomic64_t reclaimin_pages;
	atomic64_t reclaimin_infight;
	atomic64_t batchout_cnt;
	atomic64_t batchout_bytes;
	atomic64_t batchout_pages;
	atomic64_t batchout_inflight;
	atomic64_t fault_cnt;
	atomic64_t hyperhold_fault_cnt;
	atomic64_t reout_pages;
	atomic64_t reout_bytes;
	atomic64_t zram_stored_pages;
	atomic64_t zram_stored_size;
	atomic64_t stored_pages;
	atomic64_t stored_size;
	atomic64_t notify_free;
	atomic64_t frag_cnt;
	atomic64_t mcg_cnt;
	atomic64_t ext_cnt;
	atomic64_t daily_ext_max;
	atomic64_t daily_ext_min;
	atomic64_t miss_free;
	atomic64_t mcgid_clear;
#ifdef CONFIG_ZSWAPD_GKI
	atomic64_t zswapd_wakeup;
	atomic64_t zswapd_refault;
	atomic64_t zswapd_swapout;
	atomic64_t zswapd_critical_press;
	atomic64_t zswapd_medium_press;
	atomic64_t zswapd_snapshot_times;
	atomic64_t zswapd_empty_round;
	atomic64_t zswapd_empty_round_skip_times;
#endif
#ifdef CONFIG_HYPERHOLD_DEBUG
	unsigned long nr_pages;
#endif
	atomic64_t io_fail_cnt[HYPERHOLD_SCENARIO_BUTT];
	atomic64_t alloc_fail_cnt[HYPERHOLD_SCENARIO_BUTT];
	struct hyperhold_lat_stat lat[HYPERHOLD_SCENARIO_BUTT];
	struct hyperhold_fail_record_info record;
};

enum hyperhold_stat_enum {
	ENUM_RECLAIMIN_CNT,
	ENUM_RECLAIMIN_BYTES,
	ENUM_RECLAIMIN_PAGES,
	ENUM_RECLAIMIN_INFIGHT,
	ENUM_BATCHOUT_CNT,
	ENUM_BATCHOUT_BYTES,
	ENUM_BATCHOUT_PAGES,
	ENUM_BATCHOUT_INFLIGHT,
	ENUM_FAULT_CNT,
	ENUM_HYPERHOLD_FAULT_CNT,
	ENUM_REOUT_PAGES,
	ENUM_REOUT_BYTES,
	ENUM_ZRAM_STORED_PAGES,
	ENUM_ZRAM_STORED_SIZE,
	ENUM_STORED_PAGES,
	ENUM_STORED_SIZE,
	ENUM_NOTIFY_FREE,
	ENUM_FRAG_CNT,
	ENUM_MCG_CNT,
	ENUM_EXT_CNT,
	ENUM_DAILY_EXT_MAX,
	ENUM_DAILY_EXT_MIN,
	ENUM_MISS_FREE,
	ENUM_MCGID_CLEAR,
	ENUM_EXT_DAY,
	ENUM_IO_FAIL_CNT,
	ENUM_ALLOC_FAIL_CNT,
	ENUM_LAT,
	ENUM_DAY_IN_SISE,
	ENUM_DAY_OUT_SISE,
	ENUM_HYPERHOLD_STAT_CNT,
#ifdef CONFIG_HYPERHOLD_DEBUG
	ENUM_NR_PAGES,
#endif
};

struct hyperhold_page_pool {
	struct list_head page_pool_list;
	spinlock_t page_pool_lock;
};

struct hyperhold_buffer {
	struct zram *zram;
	struct hyperhold_page_pool *pool;
	struct page **dest_pages;
};

struct hyperhold_entry {
	int ext_id;
	sector_t addr;
	struct page **dest_pages;
	int pages_sz;
	struct list_head list;
	void *private;
	void *manager_private;
};

struct hyperhold_io {
	struct block_device *bdev;
	enum hyperhold_scenario scenario;
	void (*done_callback)(struct hyperhold_entry *, int);
	void (*complete_notify)(void *);
	void *private;
	struct hyperhold_key_point_record *record;
};

void *hyperhold_malloc(size_t size, bool fast, bool nofail);

void hyperhold_free(const void *mem);

unsigned long hyperhold_zsmalloc(struct zs_pool *zs_pool,
			size_t size, struct hyperhold_page_pool *pool);

struct page *hyperhold_alloc_page(
		struct hyperhold_page_pool *pool, gfp_t gfp,
		bool fast, bool nofail);

void hyperhold_page_recycle(struct page *page,
		struct hyperhold_page_pool *pool);

struct hyperhold_stat *hyperhold_get_stat_obj(void);

int hyperhold_manager_init(struct zram *zram);

#ifdef CONFIG_HYPERHOLD_GKI
void hyperhold_manager_memcg_init(struct mem_cgroup *sysmemcg, struct zram *zram);
void hyperhold_manager_memcg_deinit(struct mem_cgroup *sysmcg);
void hyperhold_zram_lru_add(struct zram *zram, u32 index,
					struct mem_cgroup_ext *memcg);
unsigned long hyperhold_extent_create(struct mem_cgroup_ext *memcg, int *ext_id,
					struct hyperhold_buffer *dest_buf,
					void **private);
int hyperhold_find_extent_by_memcg(struct mem_cgroup_ext *mcg,
			struct hyperhold_buffer *dest_buf, void **private);
struct mem_cgroup_ext *hyperhold_zram_get_memcg(struct zram *zram, u32 index);
void hyperhold_close_bdev(struct block_device *bdev,
					struct file *backing_dev);
extern int hhgki_zswapd_init(void);
extern int hhgki_zswapd_deinit(void);
extern void hhgki_wake_all_zswapd(void);
extern bool hhgki_zram_watermark_ok(void);
extern ssize_t hyperhold_psi_show(char *buf, ssize_t buf_size, ssize_t off);
extern ssize_t hyperhold_memcg_eswap_info(int type, char *buf, int mcg_id);
extern pid_t hyperhold_gki_zswapd_pid_get(void);
extern int alloc_bitmap(unsigned long *bitmap, int max, int last_bit);
extern unsigned long long hyperhold_read_mcg_ext_stats(struct mem_cgroup_ext *mcg_ext,
				enum hyperhold_mcg_member mcg_member);

#else
void hyperhold_manager_memcg_init(struct mem_cgroup *memcg, struct zram *zram);
void hyperhold_manager_memcg_deinit(struct mem_cgroup *mcg);
void hyperhold_zram_lru_add(struct zram *zram, u32 index,
					struct mem_cgroup *memcg);
unsigned long hyperhold_extent_create(struct mem_cgroup *memcg, int *ext_id,
					struct hyperhold_buffer *dest_buf,
					void **private);
int hyperhold_find_extent_by_memcg(struct mem_cgroup *mcg,
			struct hyperhold_buffer *dest_buf, void **private);
struct mem_cgroup *hyperhold_zram_get_memcg(struct zram *zram, u32 index);
#endif

void hyperhold_zram_lru_del(struct zram *zram, u32 index);

void hyperhold_extent_register(void *private);

void hyperhold_extent_objs_del(struct zram *zram, u32 index);

int hyperhold_find_extent_by_idx(
	unsigned long eswpentry, struct hyperhold_buffer *buf, void **private);

void hyperhold_extent_destroy(void *private, enum hyperhold_scenario scenario);

void hyperhold_extent_exception(enum hyperhold_scenario scenario,
					void *private);

void hyperhold_manager_deinit(struct zram *zram);

int hyperhold_schedule_init(void);

void *hyperhold_plug_start(struct hyperhold_io *io_para);

int hyperhold_read_extent(void *io_handler,
				struct hyperhold_entry *io_entry);

int hyperhold_write_extent(void *io_handler,
				struct hyperhold_entry *io_entry);

int hyperhold_plug_finish(void *io_handler);

void hyperhold_perf_start(
	struct hyperhold_key_point_record *record,
	ktime_t stsrt, unsigned long long start_ravg_sum,
	enum hyperhold_scenario scenario);

void hyperhold_perf_end(struct hyperhold_key_point_record *record);

void hyperhold_perf_lat_start(
	struct hyperhold_key_point_record *record,
	enum hyperhold_key_point type);

void hyperhold_perf_lat_end(
	struct hyperhold_key_point_record *record,
	enum hyperhold_key_point type);

void hyperhold_perf_lat_point(
	struct hyperhold_key_point_record *record,
	enum hyperhold_key_point type);

void hyperhold_perf_async_perf(
	struct hyperhold_key_point_record *record,
	enum hyperhold_key_point type, ktime_t start,
	unsigned long long start_ravg_sum);

void hyperhold_perf_io_stat(
	struct hyperhold_key_point_record *record, int page_cnt,
	int segment_cnt);

static inline unsigned long long hyperhold_get_ravg_sum(void)
{
#ifdef CONFIG_HW_TASK_RAVG_SUM
#if KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE
	return current->wts.ravg_sum;
#else
	return current->ravg.ravg_sum;
#endif
#else
	return 0;
#endif
}

void hyperhold_fail_record(enum hyperhold_fail_point point,
	u32 index, int ext_id, unsigned char *task_comm);

bool hyperhold_enable(void);
bool hyperhold_reclaim_in_enable(void);
struct workqueue_struct *hyperhold_get_reclaim_workqueue(void);

#endif

void memcg_idle_count(struct zram *zram);
void memcg_idle_inc(struct zram *zram, u32 index);
void memcg_idle_dec(struct zram *zram, u32 index);
