/*
 * Copyright (c) Honor Technologies Co., Ltd. 2020. All rights reserved.
 * Description: hyperhold implement
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
 * Create: 2020-5-15
 *
 */
#define pr_fmt(fmt) "[HYPERHOLD]" fmt

#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/atomic.h>
#include <linux/zsmalloc.h>
#include <linux/memcontrol.h>
#include <linux/hyperhold_inf.h>
#include <log/log_usertype.h>
#include "hyperhold_internal.h"
#ifdef CONFIG_HYPERHOLD_GKI
#include "hyperhold_internal.h"
#endif
#define SCENARIO_NAME_LEN 32
#define MBYTE_SHIFT 20
/*
 * BETA_USER_READ:The number of times the beta user reads in a day, 6 times per day.
 */
#define BETA_USER_READ 6


static char scenario_name[HYPERHOLD_SCENARIO_BUTT][SCENARIO_NAME_LEN] = {
	"reclaim_in",
	"fault_out",
	"batch_out",
	"pre_out"
};


#ifdef CONFIG_HYPERHOLD_GKI
static ssize_t hyperhold_stats_show(struct hyperhold_stat *stat, char *buf, ssize_t buf_size, ssize_t off)
{
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_RECLAIMIN_CNT,atomic64_read(&stat->reclaimin_cnt));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_RECLAIMIN_BYTES,atomic64_read(&stat->reclaimin_bytes) >> MBYTE_SHIFT);
	if (PAGE_SHIFT < MBYTE_SHIFT)
		off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
				ENUM_RECLAIMIN_PAGES,
				atomic64_read(&stat->reclaimin_pages) >> (MBYTE_SHIFT - PAGE_SHIFT));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_RECLAIMIN_INFIGHT,atomic64_read(&stat->reclaimin_infight));

	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_BATCHOUT_CNT,atomic64_read(&stat->batchout_cnt));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_BATCHOUT_BYTES,atomic64_read(&stat->batchout_bytes) >> MBYTE_SHIFT);
	if (PAGE_SHIFT < MBYTE_SHIFT)
		off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
				ENUM_BATCHOUT_PAGES,
				atomic64_read(&stat->batchout_pages) >> (MBYTE_SHIFT - PAGE_SHIFT));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_BATCHOUT_INFLIGHT,atomic64_read(&stat->batchout_inflight));

	return off;
}

static ssize_t hyperhold_area_info_show(struct hyperhold_stat *stat, char *buf, ssize_t buf_size, ssize_t off)
{
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_FAULT_CNT,atomic64_read(&stat->fault_cnt));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_HYPERHOLD_FAULT_CNT,atomic64_read(&stat->hyperhold_fault_cnt));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_REOUT_PAGES,atomic64_read(&stat->reout_pages) >> (MBYTE_SHIFT - PAGE_SHIFT));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_REOUT_BYTES,atomic64_read(&stat->reout_bytes) >> MBYTE_SHIFT);

	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_ZRAM_STORED_PAGES,atomic64_read(&stat->zram_stored_pages));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_ZRAM_STORED_SIZE,atomic64_read(&stat->zram_stored_size));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_STORED_PAGES,atomic64_read(&stat->stored_pages) >> (MBYTE_SHIFT - PAGE_SHIFT));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_STORED_SIZE,atomic64_read(&stat->stored_size) >> MBYTE_SHIFT);

	off += scnprintf(buf + off, buf_size - off, "%d:%lld MB\n",
			ENUM_NOTIFY_FREE,atomic64_read(&stat->notify_free) >> (MBYTE_SHIFT - EXTENT_SHIFT));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_FRAG_CNT,atomic64_read(&stat->frag_cnt));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_MCG_CNT,atomic64_read(&stat->mcg_cnt));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_EXT_CNT,atomic64_read(&stat->ext_cnt));

	return off;
}

static ssize_t hyperhold_fail_show(struct hyperhold_stat *stat, char *buf, ssize_t buf_size, ssize_t off)
{
	int i;

	for (i = 0; i < HYPERHOLD_SCENARIO_BUTT; ++i) {
		off += scnprintf(buf + off, buf_size - off, "%d_%s:%lld\n",
				ENUM_IO_FAIL_CNT,
				scenario_name[i], atomic64_read(&stat->io_fail_cnt[i]));
		off += scnprintf(buf + off, buf_size - off, "%d_%s:%lld\n",
				ENUM_ALLOC_FAIL_CNT,
				scenario_name[i], atomic64_read(&stat->alloc_fail_cnt[i]));
	}
	return off;
}


static ssize_t hyperhold_extent_day_show(struct hyperhold_stat *stat, char *buf, ssize_t buf_size, ssize_t off)
{
	static int count = 0;

	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
		ENUM_DAILY_EXT_MAX,atomic64_read(&stat->daily_ext_max));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
		ENUM_DAILY_EXT_MIN,atomic64_read(&stat->daily_ext_min));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
		ENUM_MISS_FREE,atomic64_read(&stat->miss_free));
	off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
		ENUM_MCGID_CLEAR,atomic64_read(&stat->mcgid_clear));
#ifdef CONFIG_HYPERHOLD_DEBUG
	off += scnprintf(buf + off, buf_size - off, "%d:%lu\n",
		ENUM_NR_PAGES,stat->nr_pages);
#endif

#if IS_ENABLED(CONFIG_LOGGER)
	if (unlikely(get_logusertype_flag() == BETA_USER )){
#else
	if (false) {
#endif
		count++;
		if (BETA_USER_READ == count){
			off += scnprintf(buf + off, buf_size - off, "%d:%lld\n", ENUM_EXT_DAY,
				(atomic64_read(&stat->daily_ext_max) -
				atomic64_read(&stat->daily_ext_min)) >> (MBYTE_SHIFT-EXTENT_SHIFT));
			count = 0;
			atomic64_set(&stat->daily_ext_max, atomic64_read(&stat->ext_cnt));
			atomic64_set(&stat->daily_ext_min, atomic64_read(&stat->ext_cnt));
		} else {
			off += scnprintf(buf + off, buf_size - off, "%d:%lld\n", ENUM_EXT_DAY,0);
		}
	} else {
		off += scnprintf(buf + off, buf_size - off, "%d:%lld\n", ENUM_EXT_DAY,
			(atomic64_read(&stat->daily_ext_max) -
			atomic64_read(&stat->daily_ext_min)) >> (MBYTE_SHIFT-EXTENT_SHIFT));
		atomic64_set(&stat->daily_ext_max, atomic64_read(&stat->ext_cnt));
		atomic64_set(&stat->daily_ext_min, atomic64_read(&stat->ext_cnt));
	}

	return off;
}


static ssize_t hyperhold_lat_show(struct hyperhold_stat *stat, char *buf, ssize_t buf_size, ssize_t off)
{
	int i;

	for (i = 0; i < HYPERHOLD_SCENARIO_BUTT; ++i) {
		off += scnprintf(buf + off, buf_size - off, "%d_%s_total:%lld\n",
				ENUM_LAT,
				scenario_name[i],
				atomic64_read(&stat->lat[i].total_lat));
		off += scnprintf(buf + off, buf_size - off, "%d_%s_max:%lld\n",
				ENUM_LAT,
				scenario_name[i],
				atomic64_read(&stat->lat[i].max_lat));
		off += scnprintf(buf + off, buf_size - off, "%d_%s_timeout:%lld\n",
				ENUM_LAT,
				scenario_name[i],
				atomic64_read(&stat->lat[i].timeout_cnt));
	}
	return off;
}


static ssize_t hyperhold_in_size_day_show(struct hyperhold_stat *stat, char *buf, ssize_t buf_size, ssize_t off)
{
	static long long hyperhold_in_size_day_tmp = 0;
	static int in_count = 0;

#if IS_ENABLED(CONFIG_LOGGER)
	if (unlikely(get_logusertype_flag() == BETA_USER )){
#else
	if (false) {
#endif
		in_count++;
		if (BETA_USER_READ == in_count){
			off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
				ENUM_DAY_IN_SISE,
				(atomic64_read(&stat->batchout_bytes) -
 				hyperhold_in_size_day_tmp) >> MBYTE_SHIFT);
			in_count = 0;
			hyperhold_in_size_day_tmp = atomic64_read(&stat->batchout_bytes);
		} else {
			off += scnprintf(buf + off, buf_size - off, "%d:%lld\n", ENUM_DAY_IN_SISE, 0);
		}
	} else {
		off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_DAY_IN_SISE,
			(atomic64_read(&stat->batchout_bytes) -
			hyperhold_in_size_day_tmp) >> MBYTE_SHIFT);
		hyperhold_in_size_day_tmp = atomic64_read(&stat->batchout_bytes);
	}
	return off;
}

static ssize_t hyperhold_out_size_day_show(struct hyperhold_stat *stat, char *buf, ssize_t buf_size, ssize_t off)
{
	static long long hyperhold_out_size_day_tmp = 0;
	static int out_count = 0;

#if IS_ENABLED(CONFIG_LOGGER)
	if (unlikely(get_logusertype_flag() == BETA_USER )){
#else
	if (false) {
#endif
		out_count++;
		if (BETA_USER_READ == out_count){
			off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
				ENUM_DAY_OUT_SISE,
				(atomic64_read(&stat->reclaimin_bytes) -
				hyperhold_out_size_day_tmp) >> MBYTE_SHIFT);
			out_count = 0;
			hyperhold_out_size_day_tmp = atomic64_read(&stat->reclaimin_bytes);
		} else {
			off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",ENUM_DAY_OUT_SISE,0);
		}
	} else {
		off += scnprintf(buf + off, buf_size - off, "%d:%lld\n",
			ENUM_DAY_OUT_SISE,
			(atomic64_read(&stat->reclaimin_bytes) -
			hyperhold_out_size_day_tmp) >> MBYTE_SHIFT);
		hyperhold_out_size_day_tmp = atomic64_read(&stat->reclaimin_bytes);
	}
	return off;
}

ssize_t hyperhold_psi_show(char *buf, ssize_t buf_size, ssize_t off)
{
	ssize_t index = off;
	struct hyperhold_stat *stat = NULL;

	if (!hyperhold_enable())
		return index;

	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");
		return index;
	}

	index = hyperhold_stats_show(stat, buf, buf_size, index);
	index = hyperhold_area_info_show(stat, buf, buf_size, index);
	index = hyperhold_extent_day_show(stat, buf, buf_size, index);
	index = hyperhold_fail_show(stat, buf, buf_size, index);
	index = hyperhold_lat_show(stat, buf, buf_size, index);
	index = hyperhold_in_size_day_show(stat, buf, buf_size, index);
	index = hyperhold_out_size_day_show(stat, buf, buf_size, index);

	return index;
}
#else
static void hyperhold_lat_show(struct seq_file *m,
	struct hyperhold_stat *stat)
{
	int i;

	for (i = 0; i < HYPERHOLD_SCENARIO_BUTT; ++i) {
		seq_printf(m, "hyperhold_%s_total_lat: %lld\n",
			scenario_name[i],
			atomic64_read(&stat->lat[i].total_lat));
		seq_printf(m, "hyperhold_%s_max_lat: %lld\n",
			scenario_name[i],
			atomic64_read(&stat->lat[i].max_lat));
		seq_printf(m, "hyperhold_%s_timeout_cnt: %lld\n",
			scenario_name[i],
			atomic64_read(&stat->lat[i].timeout_cnt));
	}
}

static void hyperhold_stats_show(struct seq_file *m,
	struct hyperhold_stat *stat)
{
	seq_printf(m, "hyperhold_out_times: %lld\n",
		atomic64_read(&stat->reclaimin_cnt));
	seq_printf(m, "hyperhold_out_comp_size: %lld MB\n",
		atomic64_read(&stat->reclaimin_bytes) >> MBYTE_SHIFT);
	if (PAGE_SHIFT < MBYTE_SHIFT)
		seq_printf(m, "hyperhold_out_ori_size: %lld MB\n",
			atomic64_read(&stat->reclaimin_pages) >>
				(MBYTE_SHIFT - PAGE_SHIFT));
	seq_printf(m, "hyperhold_in_times: %lld\n",
		atomic64_read(&stat->batchout_cnt));
	seq_printf(m, "hyperhold_in_comp_size: %lld MB\n",
		atomic64_read(&stat->batchout_bytes) >> MBYTE_SHIFT);
	if (PAGE_SHIFT < MBYTE_SHIFT)
		seq_printf(m, "hyperhold_in_ori_size: %lld MB\n",
		atomic64_read(&stat->batchout_pages) >>
			(MBYTE_SHIFT - PAGE_SHIFT));
	seq_printf(m, "hyperhold_all_fault: %lld\n",
		atomic64_read(&stat->fault_cnt));
	seq_printf(m, "hyperhold_fault: %lld\n",
		atomic64_read(&stat->hyperhold_fault_cnt));
}

static void hyperhold_area_info_show(struct seq_file *m,
	struct hyperhold_stat *stat)
{
	seq_printf(m, "hyperhold_reout_ori_size: %lld MB\n",
		atomic64_read(&stat->reout_pages) >>
			(MBYTE_SHIFT - PAGE_SHIFT));
	seq_printf(m, "hyperhold_reout_comp_size: %lld MB\n",
		atomic64_read(&stat->reout_bytes) >> MBYTE_SHIFT);
	seq_printf(m, "hyperhold_store_comp_size: %lld MB\n",
		atomic64_read(&stat->stored_size) >> MBYTE_SHIFT);
	seq_printf(m, "hyperhold_store_ori_size: %lld MB\n",
		atomic64_read(&stat->stored_pages) >>
			(MBYTE_SHIFT - PAGE_SHIFT));
	seq_printf(m, "hyperhold_notify_free_size: %lld MB\n",
		atomic64_read(&stat->notify_free) >>
			(MBYTE_SHIFT - EXTENT_SHIFT));
	seq_printf(m, "hyperhold_store_memcg_cnt: %lld\n",
		atomic64_read(&stat->mcg_cnt));
	seq_printf(m, "hyperhold_store_extent_cnt: %lld\n",
		atomic64_read(&stat->ext_cnt));
	seq_printf(m, "hyperhold_store_fragment_cnt: %lld\n",
		atomic64_read(&stat->frag_cnt));
}

static void hyperhold_fail_show(struct seq_file *m,
	struct hyperhold_stat *stat)
{
	int i;

	for (i = 0; i < HYPERHOLD_SCENARIO_BUTT; ++i) {
		seq_printf(m, "hyperhold_%s_io_fail_cnt: %lld\n",
			scenario_name[i],
			atomic64_read(&stat->io_fail_cnt[i]));
		seq_printf(m, "hyperhold_%s_alloc_fail_cnt: %lld\n",
			scenario_name[i],
			atomic64_read(&stat->alloc_fail_cnt[i]));
	}
}

static void hyperhold_extent_day_show(struct seq_file *m,
	struct hyperhold_stat *stat)
{
	static int count = 0;

#if IS_ENABLED(CONFIG_LOGGER)
	if (unlikely(get_logusertype_flag() == BETA_USER )){
#else
	if (false) {
#endif
		count++;
		if (BETA_USER_READ == count){
			seq_printf(m, "hyperhold_extent_cnt_day: %lld\n",
				(atomic64_read(&stat->daily_ext_max) -
				atomic64_read(&stat->daily_ext_min)) >> (MBYTE_SHIFT-EXTENT_SHIFT));
			count = 0;
			atomic64_set(&stat->daily_ext_max, atomic64_read(&stat->ext_cnt));
			atomic64_set(&stat->daily_ext_min, atomic64_read(&stat->ext_cnt));
		} else {
			seq_printf(m, "hyperhold_extent_cnt_day: %lld\n", 0);
		}
	} else {
		seq_printf(m, "hyperhold_extent_cnt_day: %lld\n",
			(atomic64_read(&stat->daily_ext_max) -
			atomic64_read(&stat->daily_ext_min)) >> (MBYTE_SHIFT-EXTENT_SHIFT));
		atomic64_set(&stat->daily_ext_max, atomic64_read(&stat->ext_cnt));
		atomic64_set(&stat->daily_ext_min, atomic64_read(&stat->ext_cnt));
	}
}

static void hyperhold_in_size_day_show(struct seq_file *m,
	struct hyperhold_stat *stat)
{
	static long long hyperhold_in_size_day_tmp = 0;
	static int in_count = 0;

#if IS_ENABLED(CONFIG_LOGGER)
	if (unlikely(get_logusertype_flag() == BETA_USER )){
#else
	if (false) {
#endif
		in_count++;
		if (BETA_USER_READ == in_count){
			seq_printf(m, "hyperhold_in_size_day: %lld\n",
				(atomic64_read(&stat->batchout_bytes) -
				hyperhold_in_size_day_tmp) >> MBYTE_SHIFT);
			in_count = 0;
			hyperhold_in_size_day_tmp = atomic64_read(&stat->batchout_bytes);
		} else {
			seq_printf(m, "hyperhold_in_size_day: %lld\n", 0);
		}
	} else {
		seq_printf(m, "hyperhold_in_size_day: %lld\n",
			(atomic64_read(&stat->batchout_bytes) -
			hyperhold_in_size_day_tmp) >> MBYTE_SHIFT);
		hyperhold_in_size_day_tmp = atomic64_read(&stat->batchout_bytes);
	}
}

static void hyperhold_out_size_day_show(struct seq_file *m,
	struct hyperhold_stat *stat)
{
	static long long hyperhold_out_size_day_tmp = 0;
	static int out_count = 0;

#if IS_ENABLED(CONFIG_LOGGER)
	if (unlikely(get_logusertype_flag() == BETA_USER )){
#else
	if (false) {
#endif
		out_count++;
		if (BETA_USER_READ == out_count){
			seq_printf(m, "hyperhold_out_size_day: %lld\n",
				(atomic64_read(&stat->reclaimin_bytes) -
				hyperhold_out_size_day_tmp) >> MBYTE_SHIFT);
			out_count = 0;
			hyperhold_out_size_day_tmp = atomic64_read(&stat->reclaimin_bytes);
		} else {
			seq_printf(m, "hyperhold_out_size_day: %lld\n", 0);
		}
	} else {
		seq_printf(m, "hyperhold_out_size_day: %lld\n",
			(atomic64_read(&stat->reclaimin_bytes) -
			hyperhold_out_size_day_tmp) >> MBYTE_SHIFT);
		hyperhold_out_size_day_tmp = atomic64_read(&stat->reclaimin_bytes);
	}
}

void hyperhold_psi_show(struct seq_file *m)
{
	struct hyperhold_stat *stat = NULL;

	if (!hyperhold_enable())
		return;

	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");
		return;
	}

	hyperhold_stats_show(m, stat);
	hyperhold_area_info_show(m, stat);
	hyperhold_lat_show(m, stat);
	hyperhold_fail_show(m, stat);
	hyperhold_extent_day_show(m, stat);
	hyperhold_in_size_day_show(m, stat);
	hyperhold_out_size_day_show(m, stat);
}
#endif

unsigned long hyperhold_get_zram_used_pages(void)
{
	struct hyperhold_stat *stat = NULL;

	if (!hyperhold_enable())
		return 0;

	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");

		return 0;
	}

	return atomic64_read(&stat->zram_stored_pages);
}

unsigned long long hyperhold_get_zram_pagefault(void)
{
	struct hyperhold_stat *stat = NULL;

	if (!hyperhold_enable())
		return 0;

	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");

		return 0;
	}

	return atomic64_read(&stat->fault_cnt);
}

bool hyperhold_reclaim_work_running(void)
{
	struct hyperhold_stat *stat = NULL;

	if (!hyperhold_enable())
		return false;

	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");

		return 0;
	}

	return atomic64_read(&stat->reclaimin_infight) ? true : false;
}

#ifdef CONFIG_HYPERHOLD_GKI
unsigned long long hyperhold_read_mcg_stats_internal(struct mem_cgroup_ext *mcg_ext,
				enum hyperhold_mcg_member mcg_member)
{
	unsigned long long val = 0;
	int extcnt;
	switch (mcg_member) {
	case MCG_ZRAM_STORED_SZ:
		val = atomic64_read(&mcg_ext->zram_stored_size);
		break;
	case MCG_ZRAM_PG_SZ:
		val = atomic64_read(&mcg_ext->zram_page_size);
		break;
	case MCG_DISK_STORED_SZ:
		val = atomic64_read(&mcg_ext->hyperhold_stored_size);
		break;
	case MCG_DISK_STORED_PG_SZ:
		val = atomic64_read(&mcg_ext->hyperhold_stored_pages);
		break;
	case MCG_ANON_FAULT_CNT:
		val = atomic64_read(&mcg_ext->hyperhold_allfaultcnt);
		break;
	case MCG_DISK_FAULT_CNT:
		val = atomic64_read(&mcg_ext->hyperhold_faultcnt);
		break;
	case MCG_SWAPOUT_CNT:
		val = atomic64_read(&mcg_ext->hyperhold_outcnt);
		break;
	case MCG_SWAPOUT_SZ:
		val = atomic64_read(&mcg_ext->hyperhold_outextcnt) << EXTENT_SHIFT;
		break;
	case MCG_SWAPIN_CNT:
		val = atomic64_read(&mcg_ext->hyperhold_incnt);
		break;
	case MCG_SWAPIN_SZ:
		val = atomic64_read(&mcg_ext->hyperhold_inextcnt) << EXTENT_SHIFT;
		break;
	case MCG_DISK_SPACE:
		extcnt = atomic_read(&mcg_ext->hyperhold_extcnt);
		if (extcnt < 0)
			extcnt = 0;
		val = ((unsigned long long) extcnt) << EXTENT_SHIFT; /*lint !e571*/
		break;
	case MCG_DISK_SPACE_PEAK:
		extcnt = atomic_read(&mcg_ext->hyperhold_peakextcnt);
		if (extcnt < 0)
			extcnt = 0;
		val = ((unsigned long long) extcnt) << EXTENT_SHIFT; /*lint !e571*/
		break;
	default:
		break;
	}

	return val;

}


unsigned long long hyperhold_read_mcg_stats(struct mem_cgroup *mcg,
				enum hyperhold_mcg_member mcg_member)
{
	struct mem_cgroup_ext *mcg_ext = NULL;
	if (!hyperhold_enable())
		return 0;

	mcg_ext = mem_cgroup_ext_from_memcg(mcg);
	if (!mcg_ext)
		return 0;
	return hyperhold_read_mcg_stats_internal(mcg_ext, mcg_member);
}

unsigned long long hyperhold_read_mcg_ext_stats(struct mem_cgroup_ext *mcg_ext,
				enum hyperhold_mcg_member mcg_member)
{
	if (!hyperhold_enable() || !mem_cgroup_ext_check(mcg_ext))
		return 0;

	return hyperhold_read_mcg_stats_internal(mcg_ext, mcg_member);
}


#else
unsigned long long hyperhold_read_mcg_stats(struct mem_cgroup *mcg,
				enum hyperhold_mcg_member mcg_member)
{
	unsigned long long val = 0;
	int extcnt;

	if (!hyperhold_enable())
		return 0;

	switch (mcg_member) {
	case MCG_ZRAM_STORED_SZ:
		val = atomic64_read(&mcg->zram_stored_size);
		break;
	case MCG_ZRAM_PG_SZ:
		val = atomic64_read(&mcg->zram_page_size);
		break;
	case MCG_DISK_STORED_SZ:
		val = atomic64_read(&mcg->hyperhold_stored_size);
		break;
	case MCG_DISK_STORED_PG_SZ:
		val = atomic64_read(&mcg->hyperhold_stored_pages);
		break;
	case MCG_ANON_FAULT_CNT:
		val = atomic64_read(&mcg->hyperhold_allfaultcnt);
		break;
	case MCG_DISK_FAULT_CNT:
		val = atomic64_read(&mcg->hyperhold_faultcnt);
		break;
	case MCG_SWAPOUT_CNT:
		val = atomic64_read(&mcg->hyperhold_outcnt);
		break;
	case MCG_SWAPOUT_SZ:
		val = atomic64_read(&mcg->hyperhold_outextcnt) << EXTENT_SHIFT;
		break;
	case MCG_SWAPIN_CNT:
		val = atomic64_read(&mcg->hyperhold_incnt);
		break;
	case MCG_SWAPIN_SZ:
		val = atomic64_read(&mcg->hyperhold_inextcnt) << EXTENT_SHIFT;
		break;
	case MCG_DISK_SPACE:
		extcnt = atomic_read(&mcg->hyperhold_extcnt);
		if (extcnt < 0)
			extcnt = 0;
		val = ((unsigned long long) extcnt) << EXTENT_SHIFT; /*lint !e571*/
		break;
	case MCG_DISK_SPACE_PEAK:
		extcnt = atomic_read(&mcg->hyperhold_peakextcnt);
		if (extcnt < 0)
			extcnt = 0;
		val = ((unsigned long long) extcnt) << EXTENT_SHIFT; /*lint !e571*/
		break;
	default:
		break;
	}

	return val;
}
#endif

void hyperhold_fail_record(enum hyperhold_fail_point point,
	u32 index, int ext_id, unsigned char *task_comm)
{
	struct hyperhold_stat *stat = NULL;
	unsigned long flags;
	unsigned int copylen = strlen(task_comm) + 1;

	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");
		return;
	}

	if (copylen > TASK_COMM_LEN) {
		hh_print(HHLOG_ERR, "task_comm len %d is err\n", copylen);
		return;
	}

	spin_lock_irqsave(&stat->record.lock, flags);
	if (stat->record.num < MAX_FAIL_RECORD_NUM) {
		stat->record.record[stat->record.num].point = point;
		stat->record.record[stat->record.num].index = index;
		stat->record.record[stat->record.num].ext_id = ext_id;
		stat->record.record[stat->record.num].time = ktime_get();
		memcpy(stat->record.record[stat->record.num].task_comm,
			task_comm, copylen);
		stat->record.num++;
	}
	spin_unlock_irqrestore(&stat->record.lock, flags);
}

static void hyperhold_fail_record_get(
	struct hyperhold_fail_record_info *record_info)
{
	struct hyperhold_stat *stat = NULL;
	unsigned long flags;

	if (!hyperhold_enable())
		return;

	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");
		return;
	}

	spin_lock_irqsave(&stat->record.lock, flags);
	memcpy(record_info, &stat->record,
		sizeof(struct hyperhold_fail_record_info));
	stat->record.num = 0;
	spin_unlock_irqrestore(&stat->record.lock, flags);
}

static ssize_t hyperhold_fail_record_show(char *buf)
{
	int i;
	ssize_t size = 0;
	struct hyperhold_fail_record_info record_info = { 0 };

	hyperhold_fail_record_get(&record_info);

	size += scnprintf(buf + size, PAGE_SIZE,
			"hyperhold_fail_record_num: %d\n", record_info.num);
	for (i = 0; i < record_info.num; ++i)
		size += scnprintf(buf + size, PAGE_SIZE - size,
			"point[%u]time[%lld]taskname[%s]index[%u]ext_id[%d]\n",
			record_info.record[i].point,
			ktime_us_delta(ktime_get(),
				record_info.record[i].time),
			record_info.record[i].task_comm,
			record_info.record[i].index,
			record_info.record[i].ext_id);

	return size;
}

ssize_t hyperhold_report_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return hyperhold_fail_record_show(buf);
}


#ifdef CONFIG_HYPERHOLD_DEBUG
unsigned long hyperhold_stored_size(void)
{
	struct hyperhold_stat *stat;
	if (!hyperhold_enable())
		return 0;
	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");
		return 0;
	}
	return atomic64_read(&stat->stored_size) >> PAGE_SHIFT;
}

unsigned long hyperhold_eswap_used(void)
{
	struct hyperhold_stat *stat;
	if (!hyperhold_enable())
		return 0;
	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");
		return 0;
	}
	return atomic64_read(&stat->ext_cnt) << (EXTENT_SHIFT - PAGE_SHIFT);
}

unsigned long hyperhold_eswap_total(void)
{
	struct hyperhold_stat *stat;
	if (!hyperhold_enable())
		return 0;
	stat = hyperhold_get_stat_obj();
	if (unlikely(!stat)) {
		hh_print(HHLOG_ERR, "can't get stat obj!\n");
		return 0;
	}
	return stat->nr_pages;
}
#endif

