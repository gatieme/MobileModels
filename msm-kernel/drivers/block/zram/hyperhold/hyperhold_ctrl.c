/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
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
 * Author:	He Biao <hebiao6@huawei.com>
 *		Wang Cheng Ke <wangchengke2@huawei.com>
 *		Wang Fa <fa.wang@huawei.com>
 *
 * Create: 2020-4-16
 *
 */
#define pr_fmt(fmt) "[HYPERHOLD]" fmt

#include <linux/kernel.h>
#include <linux/blkdev.h>
#include <linux/atomic.h>
#include <linux/memcontrol.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>
#ifdef CONFIG_BLK_INLINE_ENCRYPTION
#include <linux/fscrypt.h>
#include <linux/blk-crypto.h>
#endif

#include "zram_drv.h"
#include "hyperhold.h"
#include "hyperhold_internal.h"

#define HYPERHOLD_WDT_EXPIRE_DEFAULT 3600
#define PRE_EOL_INFO_OVER_VAL 2
#define LIFE_TIME_EST_OVER_VAL 8
#define HYPERHOLD_KEY_BUFF_SIZE 128
#ifdef CONFIG_BLK_INLINE_ENCRYPTION
#define HYPERHOLD_DUN_SIZE 8
#endif

struct zs_ext_para {
	struct hyperhold_page_pool *pool;
	size_t alloc_size;
	bool fast;
	bool nofail;
};

struct hyperhold_cfg {
	bool cfg_flag;
	atomic_t enable;
	atomic_t reclaim_in_enable;
	atomic_t watchdog_protect;
	int log_level;
	struct timer_list wdt_timer;
	unsigned long wdt_expire_s;
	struct hyperhold_stat *stat;
	struct workqueue_struct *reclaim_wq;
	struct zram *zram;
	sector_t start_sector;
	struct space_para_cfg space_para;
	struct space_info_para space_info;
	atomic_t crypto_enable;
#ifdef CONFIG_BLK_INLINE_ENCRYPTION
	struct blk_crypto_key crypto_key_base;
#endif
};

static struct hyperhold_cfg global_settings;

void *hyperhold_malloc(size_t size, bool fast, bool nofail)
{
	void *mem = NULL;

	if (likely(fast)) {
		mem = kzalloc(size, GFP_ATOMIC);
		if (likely(mem || !nofail))
			return mem;
	}

	mem = kzalloc(size, GFP_NOIO);

	return mem;
}

void hyperhold_free(const void *mem)
{
	kfree(mem);
}

static struct page *hyperhold_alloc_page_common(
					void *data, gfp_t gfp)
{
	struct page *page = NULL;
	struct zs_ext_para *ext_para =
		(struct zs_ext_para *)data;

	if (ext_para->pool) {
		spin_lock(&ext_para->pool->page_pool_lock);
		if (!list_empty(&ext_para->pool->page_pool_list)) {
			page = list_first_entry(
				&ext_para->pool->page_pool_list,
				struct page, lru);
			list_del(&page->lru);
		}
		spin_unlock(&ext_para->pool->page_pool_lock);
	}

	if (!page) {
		if (ext_para->fast) {
			page = alloc_page(GFP_ATOMIC);
			if (likely(page))
				goto out;
		}
		if (ext_para->nofail)
			page = alloc_page(GFP_NOIO);
		else
			page = alloc_page(gfp);
	}
out:
	return page;
}

static size_t hyperhold_zsmalloc_parse(void *data)
{
	struct zs_ext_para *ext_para = (struct zs_ext_para *)data;

	return ext_para->alloc_size;
}

unsigned long hyperhold_zsmalloc(struct zs_pool *zs_pool,
		size_t size, struct hyperhold_page_pool *pool)
{
	unsigned long ret;
	gfp_t gfp = __GFP_DIRECT_RECLAIM | __GFP_KSWAPD_RECLAIM |
		__GFP_NOWARN | __GFP_HIGHMEM |	__GFP_MOVABLE;
#ifdef CONFIG_ZS_MALLOC_EXT
	struct zs_ext_para ext_para;

	ext_para.alloc_size = size;
	ext_para.pool = pool;
	ext_para.fast = true;
	ext_para.nofail = true;
	ret = zs_malloc(zs_pool, (size_t)(&ext_para), gfp);
	if (!ret)
		hh_print(HHLOG_ERR,
			 "alloc handle failed, size = %lu, gfp = %d\n",
			 size, gfp);

	return ret;
#else
	return zs_malloc(zs_pool, size, gfp);
#endif
}

unsigned long zram_zsmalloc(struct zs_pool *zs_pool,
				size_t size, gfp_t gfp)
{
#ifdef CONFIG_ZS_MALLOC_EXT
	unsigned long ret;
	struct zs_ext_para ext_para;

	if (!is_ext_pool(zs_pool))
		return zs_malloc(zs_pool, size, gfp);

	ext_para.alloc_size = size;
	ext_para.pool = NULL;
	ext_para.fast = false;
	ext_para.nofail = false;
	ret = zs_malloc(zs_pool, (size_t)(&ext_para), gfp);
	if (!ret && (gfp | GFP_NOIO) == GFP_NOIO)
		hh_print(HHLOG_ERR,
			 "alloc handle failed, size = %lu, gfp = %d\n",
			 size, gfp);

	return ret;
#else
	return zs_malloc(zs_pool, size, gfp);
#endif
}

struct page *hyperhold_alloc_page(
		struct hyperhold_page_pool *pool, gfp_t gfp,
		bool fast, bool nofail)
{
	struct zs_ext_para ext_para;

	ext_para.pool = pool;
	ext_para.fast = fast;
	ext_para.nofail = nofail;

	return hyperhold_alloc_page_common((void *)&ext_para, gfp);
}

void hyperhold_page_recycle(struct page *page,
				struct hyperhold_page_pool *pool)
{
	if (pool) {
		spin_lock(&pool->page_pool_lock);
		list_add(&page->lru, &pool->page_pool_list);
		spin_unlock(&pool->page_pool_lock);
	} else {
		__free_page(page);
	}
}

struct space_para_cfg *hyperhold_space_para(void)
{
	return &global_settings.space_para;
}

struct space_info_para *hyperhold_space_info(void)
{
	return &global_settings.space_info;
}

int hyperhold_loglevel(void)
{
	return global_settings.log_level;
}

static void hyperhold_wdt_expire_set(unsigned long expire)
{
	global_settings.wdt_expire_s = expire;
}

static void hyperhold_wdt_set_enable(bool en)
{
	atomic_set(&global_settings.watchdog_protect, en ? 1 : 0);
}

static bool hyperhold_wdt_enable(void)
{
	return !!atomic_read(&global_settings.watchdog_protect);
}

bool hyperhold_reclaim_in_enable(void)
{
	return !!atomic_read(&global_settings.reclaim_in_enable);
}

static void hyperhold_set_reclaim_in_disable(void)
{
	atomic_set(&global_settings.reclaim_in_enable, false);
}

static void hyperhold_set_reclaim_in_enable(bool en)
{
	del_timer_sync(&global_settings.wdt_timer);
	atomic_set(&global_settings.reclaim_in_enable, en ? 1 : 0);
	if (en && hyperhold_wdt_enable())
		mod_timer(&global_settings.wdt_timer,
			jiffies + msecs_to_jiffies(
			global_settings.wdt_expire_s * MSEC_PER_SEC));
}

bool hyperhold_enable(void)
{
	return !!atomic_read(&global_settings.enable);
}

bool hyperhold_is_file_space(void)
{
	return (global_settings.space_para.space_type == HP_FILE_SPACE);
}

static void hyperhold_set_enable(bool en)
{
	hyperhold_set_reclaim_in_enable(en);

	if (!hyperhold_enable())
		atomic_set(&global_settings.enable, en ? 1 : 0);
}

void hyperhold_set_cfg(void)
{
	global_settings.cfg_flag = true;
}

bool hyperhold_get_cfg(void)
{
	return global_settings.cfg_flag;
}


bool hyperhold_crypto_enable(void)
{
	return !!atomic_read(&global_settings.crypto_enable);
}

static void hyperhold_set_crypto_enable(bool en)
{
	atomic_set(&global_settings.crypto_enable, en ? 1 : 0);
}

#ifdef CONFIG_BLK_INLINE_ENCRYPTION
struct blk_crypto_key *hyperhold_get_crypto_key_base(void)
{
	return &global_settings.crypto_key_base;
}

static int hyeprhold_set_key_proc(u8 *raw, u32 raw_size)
{
	int ret;
	struct request_queue *q = NULL;

	if (!global_settings.zram || !global_settings.zram->bdev) {
		hh_print(HHLOG_ERR, "bedv is null\n");
		return -EFAULT;
	}

	q = bdev_get_queue(global_settings.zram->bdev);
	if (!q) {
		hh_print(HHLOG_ERR, "queue is null\n");
		return -EFAULT;
	}

	ret = blk_crypto_init_key(&global_settings.crypto_key_base,
		raw, raw_size, true, BLK_ENCRYPTION_MODE_AES_256_XTS,
		HYPERHOLD_DUN_SIZE, PAGE_SIZE);
	if (ret) {
		hh_print(HHLOG_ERR, "blk_crypto_init_key fail %d\n", ret);

		return -EFAULT;
	}
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
	ret = blk_crypto_start_using_key(&global_settings.crypto_key_base, q);
#else
	ret = blk_crypto_start_using_mode(BLK_ENCRYPTION_MODE_AES_256_XTS,
		HYPERHOLD_DUN_SIZE, PAGE_SIZE, true, q);
#endif
	if (ret) {
		hh_print(HHLOG_ERR, "blk_crypto_start_using_mode fail %d\n", ret);

		return -EFAULT;
	}

	hyperhold_set_crypto_enable(true);

	return 0;
}
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
static void hyperhold_wdt_timeout(struct timer_list *unused)
#else
static void hyperhold_wdt_timeout(unsigned long data)
#endif
{
	hh_print(HHLOG_ERR,
		"hyperhold wdt is triggered! Hyperhold is disabled!\n");
	hyperhold_set_reclaim_in_disable();
}

static void hyperhold_stat_init(struct hyperhold_stat *stat)
{
	int i;

	atomic64_set(&stat->reclaimin_cnt, 0);
	atomic64_set(&stat->reclaimin_bytes, 0);
	atomic64_set(&stat->reclaimin_pages, 0);
#ifdef CONFIG_HYPERHOLD_ZSWAPD
	atomic64_set(&stat->zswapd_reclaimin_bytes, 0);
#endif
#ifdef CONFIG_RAMTURBO
	atomic64_set(&stat->app_active_reclaimin_bytes, 0);
#endif
	atomic64_set(&stat->reclaimin_infight, 0);
	atomic64_set(&stat->batchout_cnt, 0);
	atomic64_set(&stat->batchout_bytes, 0);
	atomic64_set(&stat->batchout_pages, 0);
	atomic64_set(&stat->batchout_inflight, 0);
	atomic64_set(&stat->fault_cnt, 0);
	atomic64_set(&stat->hyperhold_fault_cnt, 0);
	atomic64_set(&stat->reout_pages, 0);
	atomic64_set(&stat->reout_bytes, 0);
	atomic64_set(&stat->zram_stored_pages, 0);
	atomic64_set(&stat->zram_stored_size, 0);
	atomic64_set(&stat->stored_pages, 0);
	atomic64_set(&stat->stored_size, 0);
	atomic64_set(&stat->zram_stored_hot_pages, 0);
	atomic64_set(&stat->zram_stored_hot_size, 0);
	atomic64_set(&stat->stored_hot_pages, 0);
	atomic64_set(&stat->stored_hot_size, 0);
	atomic64_set(&stat->parfile_stored_pages, 0);
	atomic64_set(&stat->parfile_stored_size, 0);
	atomic64_set(&stat->notify_free, 0);
	atomic64_set(&stat->frag_cnt, 0);
	atomic64_set(&stat->mcg_cnt, 0);
	atomic64_set(&stat->ext_cnt, 0);
	atomic64_set(&stat->miss_free, 0);
	atomic64_set(&stat->mcgid_clear, 0);

	atomic64_set(&stat->fault_hot_cnt, 0);
	atomic64_set(&stat->hyperhold_hot_fault_cnt, 0);
	atomic64_set(&stat->hyperhold_hot_fault_cnt_fg, 0);
	atomic64_set(&stat->zram_stored_reout_size, 0);
	atomic64_set(&stat->zram_stored_reout_pages, 0);
	atomic64_set(&stat->zram_stored_reout_hot_size, 0);
	atomic64_set(&stat->zram_stored_reout_hot_pages, 0);

	atomic64_set(&stat->sys_fault_cnt, 0);
	atomic64_set(&stat->sys_hyperhold_fault_cnt, 0);

	for (i = 0; i < HYPERHOLD_SCENARIO_BUTT; ++i) {
		atomic64_set(&stat->io_fail_cnt[i], 0);
		atomic64_set(&stat->alloc_fail_cnt[i], 0);
		atomic64_set(&stat->lat[i].total_lat, 0);
		atomic64_set(&stat->lat[i].max_lat, 0);
	}
	for (i = 0; i < FAULT_OUT_LAT_DIST; ++i)
		atomic64_set(&stat->fault_out_lat_dist[i], 0);
	for (i = 0; i < FAULT_OUT_LAT_DIST; ++i)
		atomic64_set(&stat->fault_out_lat_dist_fg[i], 0);
	stat->record.num = 0;
	spin_lock_init(&stat->record.lock);
}

static bool hyperhold_global_setting_init(struct zram *zram)
{
	if (unlikely(global_settings.stat))
		return false;

	global_settings.log_level = HHLOG_ERR;
	global_settings.zram = zram;
	hyperhold_wdt_set_enable(true);
	hyperhold_set_enable(false);
	hyperhold_set_crypto_enable(false);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
	timer_setup(&global_settings.wdt_timer, hyperhold_wdt_timeout, 0);
#else
	init_timer(&global_settings.wdt_timer);
	global_settings.wdt_timer.function = hyperhold_wdt_timeout;
#endif
	hyperhold_wdt_expire_set(HYPERHOLD_WDT_EXPIRE_DEFAULT);
	global_settings.stat = hyperhold_malloc(
				sizeof(struct hyperhold_stat), false, true);
	if (unlikely(!global_settings.stat)) {
		hh_print(HHLOG_ERR, "global stat allocation failed!\n");

		return false;
	}

	hyperhold_stat_init(global_settings.stat);
	global_settings.reclaim_wq = alloc_workqueue("hyperhold_reclaim",
							WQ_CPU_INTENSIVE, 0);
	if (unlikely(!global_settings.reclaim_wq)) {
		hh_print(HHLOG_ERR,
				"reclaim workqueue allocation failed!\n");
		hyperhold_free(global_settings.stat);
		global_settings.stat = NULL;

		return false;
	}

	return true;
}

static void hyperhold_global_setting_deinit(void)
{
	destroy_workqueue(global_settings.reclaim_wq);
	hyperhold_free(global_settings.stat);
	global_settings.stat = NULL;
	global_settings.zram = NULL;
}

struct workqueue_struct *hyperhold_get_reclaim_workqueue(void)
{
	return global_settings.reclaim_wq;
}

int hyperhold_health_check(struct block_device *bdev)
{
#ifdef CONFIG_MAS_BLK
	int ret;
	u8 pre_eol_info = PRE_EOL_INFO_OVER_VAL;
	u8 life_time_est_a = LIFE_TIME_EST_OVER_VAL;
	u8 life_time_est_b = LIFE_TIME_EST_OVER_VAL;

	if (unlikely(!global_settings.zram)) {
		hh_print(HHLOG_ERR, "zram is null!\n");

		return -EFAULT;
	}

	ret = blk_lld_health_query(bdev, &pre_eol_info,
		&life_time_est_a, &life_time_est_b);
	if (ret) {
		hh_print(HHLOG_ERR, "query health err %d!\n", ret);

		return ret;
	}

	if ((pre_eol_info >= PRE_EOL_INFO_OVER_VAL) ||
		(life_time_est_a >= LIFE_TIME_EST_OVER_VAL) ||
		(life_time_est_b >= LIFE_TIME_EST_OVER_VAL)) {
		hh_print(HHLOG_ERR, "over life time uesd %u %u %u\n",
			pre_eol_info, life_time_est_a, life_time_est_b);

		return -EPERM;
	}

	hh_print(HHLOG_DEBUG, "life time uesd %u %u %u\n",
			pre_eol_info, life_time_est_a, life_time_est_b);
#endif

	return 0;
}

/*
 * This interface will be called when user set the ZRAM size.
 * Hyperhold init here.
 */
void hyperhold_init(struct zram *zram)
{
	if (!hyperhold_global_setting_init(zram))
		return;

	if (!!hyperhold_alloc_space(zram)) {
		hh_print(HHLOG_ERR, "alloc space failed! %d\n");
		hyperhold_global_setting_deinit();
		return;
	}

	zs_pool_enable_ext(zram->mem_pool, true,
			hyperhold_zsmalloc_parse);
	zs_pool_ext_malloc_register(zram->mem_pool,
			hyperhold_alloc_page_common);
}

static int hyperhold_set_enable_init(bool en)
{
	int ret;

	if (hyperhold_enable() || !en)
		return 0;

	if (!global_settings.stat) {
		hh_print(HHLOG_ERR, "global_settings.stat is null!\n");

		return -EINVAL;
	}

	if (hyperhold_is_file_space()) {
		ret = hyperhold_space_file_sector_init();
		if (unlikely(ret)) {
			hh_print(HHLOG_ERR, "init space_sector failed! %d\n", ret);
			return -EINVAL;
		}
	}

	ret = hyperhold_manager_init(global_settings.zram);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "init manager failed! %d\n", ret);
		hyperhold_space_sector_deinit();

		return -EINVAL;
	}

	ret = hyperhold_schedule_init();
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "init schedule failed! %d\n", ret);
		hyperhold_manager_deinit(global_settings.zram);
		hyperhold_space_sector_deinit();
		return -EINVAL;
	}

	return 0;
}

struct hyperhold_stat *hyperhold_get_stat_obj(void)
{
	return global_settings.stat;
}

struct zram *hyperhold_get_global_zram(void)
{
	return global_settings.zram;
}

ssize_t hyperhold_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	int ret;
	unsigned long val;
	bool en;

	ret = kstrtoul(buf, 0, &val);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "val is error!\n");

		return -EINVAL;
	}

	if (!global_settings.zram || !global_settings.zram->bdev) {
		hh_print(HHLOG_ERR, "bedv is null\n");
		return -EFAULT;
	}

	if (!!hyperhold_health_check(global_settings.zram->bdev)) {
		hh_print(HHLOG_ERR, "health check failed\n");
		ret = false;
	}

	en = !!val;
	if (hyperhold_set_enable_init(en))
		return -EINVAL;

	hyperhold_set_enable(en);

	hyperhold_expend_space(en);

	return len;
}

ssize_t hyperhold_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int len;

	len = snprintf(buf, PAGE_SIZE, "hyperhold %s reclaim_in %s\n",
		hyperhold_enable() ? "enable" : "disable",
		hyperhold_reclaim_in_enable() ? "enable" : "disable");

	len += snprintf(buf + len, PAGE_SIZE - len,
		"cfg_flag %d space_type %llu, space_size %llu\n",
		global_settings.cfg_flag,
		global_settings.space_para.space_type,
		global_settings.space_para.space_size);

	len += snprintf(buf + len, PAGE_SIZE - len,
		"file_num %llu, allocated_file_num %llu file_inited_num %llu\n",
		global_settings.space_info.file_num,
		global_settings.space_info.allocated_file_num,
		global_settings.space_info.file_inited_num);

	len += snprintf(buf + len, PAGE_SIZE - len,
		"nr_pages %llu, nr_exts %llu, nr_exts_per_file %llu\n",
		global_settings.space_info.nr_pages,
		global_settings.space_info.nr_exts,
		global_settings.space_info.nr_exts_per_file);

	len += snprintf(buf + len, PAGE_SIZE - len,
		"max_ext_num %llu, used_exts_num %llu\n"
		"enable_par_file %d, par_file_num %llu\n",
		atomic64_read(&global_settings.space_info.max_ext_num),
		atomic64_read(&global_settings.space_info.used_exts_num),
		global_settings.space_info.enable_par_file,
		global_settings.space_info.par_file_num);

	return len;
}

ssize_t hyperhold_cache_show(struct device *dev,
		struct device_attribute *attrr, char *buf)
{
	ssize_t size = 0;

	hyperhold_cache_state(global_settings.zram, buf, &size);

	return size;
}

static bool ft_get_val(const char *buf, const char *token, unsigned long *val)
{
	int ret = -EINVAL;
	char *str = strstr(buf, token);

	if (str)
		ret = kstrtoul(str + strlen(token), 0, val);

	return ret == 0;
}

ssize_t hyperhold_cache_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	char *type_buf = NULL;
	unsigned long val;

	if (!hyperhold_enable())
		return len;

	type_buf = strstrip((char *)buf);
	if (ft_get_val(type_buf, "cachelevel=", &val)) {
		hyperhold_set_cache_level(global_settings.zram, (int)val);
		goto out;
	}

out:
	return len;
}

ssize_t hyperhold_key_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	int ret;
	u32 val;
	u8 raw[HYPERHOLD_KEY_BUFF_SIZE];
	u32 raw_size;

	ret = kstrtou32(buf, 0, &val);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "val is error %d\n", ret);

		return -EINVAL;
	}

	if (hyperhold_crypto_enable()) {
		hh_print(HHLOG_ERR, "hyperhold crypto has enabled, set again!\n");
		hyperhold_set_crypto_enable(false);
	}

	ret = hyperhold_get_keyring_key(val, raw, HYPERHOLD_KEY_BUFF_SIZE, &raw_size);
	if (ret) {
		hh_print(HHLOG_ERR, "hyperhold_get_keyring_key fail %d!\n", ret);

		return -EINVAL;
	}

#ifdef CONFIG_BLK_INLINE_ENCRYPTION
	ret = hyeprhold_set_key_proc(raw, raw_size);
	if (ret) {
		hh_print(HHLOG_ERR, "hyeprhold_set_key_proc fail %d!\n", ret);

		return -EINVAL;
	}
#endif
	memset(raw, 0, HYPERHOLD_KEY_BUFF_SIZE);
	raw_size = 0;
	return len;
}

ssize_t hyperhold_key_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "crypto %s\n",
		hyperhold_crypto_enable() ? "enable" : "disable");
}

static int hyperhold_get_hp_cmd(struct block_device *bdev,
	unsigned long arg, struct blk_hp_cmd *cmd)
{
	void __user *argp = (void __user *)arg;

	if (!arg || !bdev) {
		hh_print(HHLOG_ERR, "arg or bdev null\n");
		return -EFAULT;
	}

	if (copy_from_user(cmd, argp, sizeof(struct blk_hp_cmd))) {
		hh_print(HHLOG_ERR, "copy_from_user failed\n");
		return -EFAULT;
	}

	return 0;
}

static int hyperhold_get_space_setting(struct blk_hp_set_space *space_setting,
	struct blk_hp_cmd *cmd)
{
	if (!cmd->cust_argp) {
		hh_print(HHLOG_ERR, "cust_argp is null\n");
		return -EFAULT;
	}

	if (copy_from_user(space_setting, cmd->cust_argp, sizeof(struct blk_hp_set_space))) {
		hh_print(HHLOG_ERR, "copy_from_user failed\n");
		return -EFAULT;
	}

	return 0;
}

static int hyperhold_set_space_proc(struct blk_hp_cmd *cmd)
{
	int ret;
	struct blk_hp_set_space space_setting;

	ret = hyperhold_get_space_setting(&space_setting, cmd);
	if (ret)
		return ret;

	return hyperhold_set_space(&space_setting);
}

static int hyperhold_cfg_space(struct blk_hp_cmd *hp_cmd)
{
	if (hp_cmd->cmd == CUST_BLK_HP_SET_SPACE) {
		return hyperhold_set_space_proc(hp_cmd);
	} else if (hp_cmd->cmd == CUST_BLK_HP_FREE_SPACE) {
		if (hyperhold_enable()) {
			hh_print(HHLOG_ERR, "hyperhold enable, free fail\n");
			return -EPERM;
		}
		return hyperhold_free_filespace();
	} else {
		return -EINVAL;
	}
}

int hyperhold_ioctl(struct block_device *bdev, fmode_t mode,
	unsigned int cmd, unsigned long arg)
{
	int ret;
	struct blk_hp_cmd hp_cmd;

	ret = hyperhold_get_hp_cmd(bdev, arg, &hp_cmd);
	if (ret)
		return ret;

	cmd = 0;
	return hyperhold_cfg_space(&hp_cmd);
}

#ifdef CONFIG_HYPERHOLD_DEBUG_FS
static void hyperhold_loglevel_set(int level)
{
	global_settings.log_level = level;
}

ssize_t hyperhold_ft_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	char *type_buf = NULL;
	unsigned long val;

	if (!hyperhold_enable())
		return len;

	type_buf = strstrip((char *)buf);
#ifdef CONFIG_HYPERHOLD_WRITEBACK
	if (ft_get_val(type_buf, "idle", &val)) {
		memcg_idle_count(global_settings.zram);
		goto out;
	}
#endif
	if (ft_get_val(type_buf, "cachelevel=", &val)) {
		hyperhold_set_cache_level(global_settings.zram, (int)val);
		goto out;
	}
	if (ft_get_val(type_buf, "drop=", &val)) {
		hyperhold_drop_cache(global_settings.zram, val);
		goto out;
	}
	if (ft_get_val(type_buf, "move=", &val)) {
		hyperhold_move_cache(global_settings.zram, (int)val);
		goto out;
	}
	if (ft_get_val(type_buf, "loglevel=", &val)) {
		hyperhold_loglevel_set((int)val);
		goto out;
	}

	if (ft_get_val(type_buf, "watchdog=", &val)) {
		if (val)
			hyperhold_wdt_expire_set(val);
		hyperhold_wdt_set_enable(!!val);
	}
out:
	return len;
}

ssize_t hyperhold_ft_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t size = 0;
	struct hyperhold_stat *stat = hyperhold_get_stat_obj();

	size += scnprintf(buf + size, PAGE_SIZE,
			"Hyperhold enable: %s\n",
			hyperhold_enable() ? "Yes" : "No");
	size += scnprintf(buf + size, PAGE_SIZE - size,
			"Hyperhold watchdog enable: %s\n",
			hyperhold_wdt_enable() ? "Yes" : "No");
	size += scnprintf(buf + size, PAGE_SIZE - size,
				"Hyperhold watchdog expire(s): %lu\n",
				global_settings.wdt_expire_s);
	size += scnprintf(buf + size, PAGE_SIZE - size,
				"Hyperhold log level: %d\n",
				hyperhold_loglevel());
	if (stat)
		size += scnprintf(buf + size, PAGE_SIZE - size,
				"Hyperhold mcgid clear: %ld\n",
				atomic64_read(&stat->mcgid_clear));

	return size;
}
#endif

static int __init hyperhold_module_init(void)
{
	atomic_set(&global_settings.enable, 0);
	global_settings.cfg_flag = false;
	memset(&global_settings.space_para, 0, sizeof(struct space_para_cfg));
	memset(&global_settings.space_info, 0, sizeof(struct space_info_para));
	atomic64_set(&global_settings.space_info.max_ext_num, 0);
	atomic64_set(&global_settings.space_info.used_exts_num, 0);

	return 0;
}
module_init(hyperhold_module_init);
