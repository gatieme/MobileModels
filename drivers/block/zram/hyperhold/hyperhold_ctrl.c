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
 * Create: 2020-4-16
 *
 */
#define pr_fmt(fmt) "[HYPERHOLD]" fmt

#include <linux/kernel.h>
#include <linux/blkdev.h>
#include <linux/atomic.h>
#include <linux/memcontrol.h>
#include <linux/version.h>
#include "zram_drv.h"
#include "hyperhold.h"
#include "hyperhold_internal.h"

#ifdef CONFIG_HYPERHOLD_GKI
#include <linux/kernel_read_file.h>
#include <linux/string.h>

#include "hyperhold_gki_zswapd.h"
#endif


#define HYPERHOLD_WDT_EXPIRE_DEFAULT 4*3600
#define PRE_EOL_INFO_OVER_VAL 2
#define LIFE_TIME_EST_OVER_VAL 8
#define HYPERHOLD_BLOCK_DEV_NAME "/dev/block/by-name/hyperhold"

#ifdef CONFIG_HYPERHOLD_GKI
struct hyperhold_cfg global_settings;
extern int get_ufs_health_info(u8 *pre_eol_info, u8 *life_time_est_a, u8 *life_time_est_b);
#else
static struct hyperhold_cfg global_settings;
#endif

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

#ifndef CONFIG_HYPERHOLD_GKI
static size_t hyperhold_zsmalloc_parse(void *data)
{
	struct zs_ext_para *ext_para = (struct zs_ext_para *)data;

	return ext_para->alloc_size;
}
#endif

unsigned long hyperhold_zsmalloc(struct zs_pool *zs_pool,
		size_t size, struct hyperhold_page_pool *pool)
{
	gfp_t gfp = __GFP_DIRECT_RECLAIM | __GFP_KSWAPD_RECLAIM |
		__GFP_NOWARN | __GFP_HIGHMEM |	__GFP_MOVABLE;
#ifdef CONFIG_ZS_MALLOC_EXT
	struct zs_ext_para ext_para;
	unsigned long ret;

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
	hh_print(HHLOG_INFO, "hyperhold wdt was feeded\n");
	if (en && hyperhold_wdt_enable())
		mod_timer(&global_settings.wdt_timer,
			jiffies + msecs_to_jiffies(
			global_settings.wdt_expire_s * MSEC_PER_SEC));
}

bool hyperhold_enable(void)
{
	return !!atomic_read(&global_settings.enable);
}
EXPORT_SYMBOL(hyperhold_enable);

static void hyperhold_set_enable(bool en)
{
	hyperhold_set_reclaim_in_enable(en);

	if (!hyperhold_enable())
		atomic_set(&global_settings.enable, en ? 1 : 0);
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 61)
static void hyperhold_wdt_timeout(struct timer_list *timer)
#else
static void hyperhold_wdt_timeout(unsigned long data)
#endif
{
	hh_print(HHLOG_ERR,
		"hyperhold wdt is triggered! Hyperhold is disabled!\n");
	hyperhold_set_reclaim_in_disable();
}

#ifdef CONFIG_HYPERHOLD_GKI
void hyperhold_close_bdev(struct block_device *bdev,
					struct file *backing_dev)
#else
static void hyperhold_close_bdev(struct block_device *bdev,
					struct file *backing_dev)
#endif
{
	if (bdev)
		blkdev_put(bdev, FMODE_READ | FMODE_WRITE | FMODE_EXCL);

	if (backing_dev)
		filp_close(backing_dev, NULL);
}

static struct file *hyperhold_open_bdev(const char *file_name)
{
	struct file *backing_dev = NULL;

#ifdef CONFIG_HYPERHOLD_GKI
	backing_dev = filp_open_block(file_name, O_RDWR | O_LARGEFILE, 0);
#else
	backing_dev = filp_open(file_name, O_RDWR | O_LARGEFILE, 0);
#endif
	if (unlikely(IS_ERR(backing_dev))) {
		hh_print(HHLOG_ERR, "open the %s failed! eno = %lld\n",
					file_name, PTR_ERR(backing_dev));
		backing_dev = NULL;
		return NULL;
	}

	if (unlikely(!S_ISBLK(backing_dev->f_mapping->host->i_mode))) {
		hh_print(HHLOG_ERR, "%s isn't a blk device\n", file_name);
		hyperhold_close_bdev(NULL, backing_dev);
		return NULL;
	}

	return backing_dev;
}

static int hyperhold_bind(struct zram *zram, const char *file_name)
{
	struct file *backing_dev = NULL;
	struct inode *inode = NULL;
	unsigned long nr_pages;
	struct block_device *bdev = NULL;
	int err;

	backing_dev = hyperhold_open_bdev(file_name);
	if (unlikely(!backing_dev))
		return -EINVAL;

	inode = backing_dev->f_mapping->host;

	bdev = blkdev_get_by_dev(inode->i_rdev,
                        FMODE_READ | FMODE_WRITE | FMODE_EXCL, zram);
	if (IS_ERR(bdev)) {
                err = PTR_ERR(bdev);
		hh_print(HHLOG_ERR, "%s blkdev_get_by_dev failed! eno = %d\n",
                                        file_name, err);
                bdev = NULL;
                goto out;
        }
	nr_pages = (unsigned long)i_size_read(inode) >> PAGE_SHIFT;
#ifdef CONFIG_HYPERHOLD_DEBUG
	global_settings.stat->nr_pages = nr_pages;
#endif
	err = set_blocksize(bdev, PAGE_SIZE);
	if (unlikely(err)) {
		hh_print(HHLOG_ERR,
			"%s set blocksize failed! eno = %d\n", file_name, err);
		goto out;
	}

	down_write(&zram->init_lock);
	zram->bdev = bdev;
	zram->backing_dev = backing_dev;
	zram->nr_pages = nr_pages;
	up_write(&zram->init_lock);

	return 0;
out:
	hyperhold_close_bdev(bdev, backing_dev);

	return err;
}

static void hyperhold_put_mapped_bdev(struct block_device *bdev)
{
	if (bdev)
		blkdev_put(bdev, FMODE_READ);
}

static struct block_device *hyperhold_get_mapped_bdev(const char *file_name)
{
	struct block_device *bdev = NULL;
	int err;

	bdev= blkdev_get_by_path(file_name, FMODE_READ, NULL);
	if (IS_ERR(bdev)) {
		err = PTR_ERR(bdev);
		hh_print(HHLOG_ERR, "get_bdev %s blkdev_get_by_patch failed! eno = %d\n",
                                        file_name, err);
                return NULL;
 	}
	return bdev;
}

static void hyperhold_stat_init(struct hyperhold_stat *stat)
{
	int i;

	atomic64_set(&stat->reclaimin_cnt, 0);
	atomic64_set(&stat->reclaimin_bytes, 0);
	atomic64_set(&stat->reclaimin_pages, 0);
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
	atomic64_set(&stat->notify_free, 0);
	atomic64_set(&stat->frag_cnt, 0);
	atomic64_set(&stat->mcg_cnt, 0);
	atomic64_set(&stat->ext_cnt, 0);
	atomic64_set(&stat->daily_ext_max, 0);
	atomic64_set(&stat->daily_ext_min, 0);
	atomic64_set(&stat->miss_free, 0);
	atomic64_set(&stat->mcgid_clear, 0);
#ifdef CONFIG_ZSWAPD_GKI
	atomic64_set(&stat->zswapd_wakeup, 0);
	atomic64_set(&stat->zswapd_refault, 0);
	atomic64_set(&stat->zswapd_swapout, 0);
	atomic64_set(&stat->zswapd_critical_press, 0);
	atomic64_set(&stat->zswapd_medium_press, 0);
	atomic64_set(&stat->zswapd_snapshot_times, 0);
	atomic64_set(&stat->zswapd_empty_round, 0);
	atomic64_set(&stat->zswapd_empty_round_skip_times, 0);
#endif

	for (i = 0; i < HYPERHOLD_SCENARIO_BUTT; ++i) {
		atomic64_set(&stat->io_fail_cnt[i], 0);
		atomic64_set(&stat->alloc_fail_cnt[i], 0);
		atomic64_set(&stat->lat[i].total_lat, 0);
		atomic64_set(&stat->lat[i].max_lat, 0);
	}

	stat->record.num = 0;
	spin_lock_init(&stat->record.lock);
}

static bool hyperhold_global_setting_init(struct zram *zram)
{
	if (unlikely(global_settings.stat))
		return false;

#ifdef CONFIG_HYPERHOLD_GKI_DEBUG
	global_settings.log_level = HHLOG_DEBUG;
#else
	global_settings.log_level = HHLOG_ERR;
#endif

	global_settings.zram = zram;
	hyperhold_wdt_set_enable(true);
	hyperhold_set_enable(false);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 61)
	timer_setup(&global_settings.wdt_timer, hyperhold_wdt_timeout, 0);
#else
	setup_timer(&global_settings.wdt_timer, hyperhold_wdt_timeout, 0ul);
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

/*
 * This interface will be called when user set the ZRAM size.
 * Hyperhold init here.
 */
void hyperhold_init(struct zram *zram)
{
	int ret = 0;
	const char *real_name = HYPERHOLD_BLOCK_DEV_NAME;
	const char *mapper_name = global_settings.mapper_name;
	struct block_device *real_bdev = NULL;

	if (!hyperhold_global_setting_init(zram))
		return;

	if (mapper_name != NULL) {
		real_bdev = hyperhold_get_mapped_bdev(real_name);
		if (!real_bdev) {
			hh_print(HHLOG_ERR, "get storage device failed! %d\n", ret);
			return;
		}
		ret = hyperhold_bind(zram, mapper_name);
	} else {
		ret = hyperhold_bind(zram, real_name);
	}
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR,
			"bind storage device failed! %d\n", ret);
		hyperhold_put_mapped_bdev(real_bdev);
		hyperhold_global_setting_deinit();
		return;
	}

	global_settings.real_bdev = real_bdev ? : zram->bdev;
#ifndef CONFIG_HYPERHOLD_GKI
	zs_pool_enable_ext(zram->mem_pool, true,
			hyperhold_zsmalloc_parse);
	zs_pool_ext_malloc_register(zram->mem_pool,
			hyperhold_alloc_page_common);
#else
	memcg_ext_init();
	hhgki_zswapd_init();
#endif
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

	ret = hyperhold_manager_init(global_settings.zram);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "init manager failed! %d\n", ret);

		return -EINVAL;
	}

	ret = hyperhold_schedule_init();
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "init schedule failed! %d\n", ret);
		hyperhold_manager_deinit(global_settings.zram);

		return -EINVAL;
	}

	return 0;
}

struct hyperhold_stat *hyperhold_get_stat_obj(void)
{
	return global_settings.stat;
}

#ifndef CONFIG_HYPERHOLD_GKI
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0)
int __attribute__((weak)) blk_lld_health_query(struct block_device *bi_bdev,
	u8 *pre_eol_info, u8 *life_time_est_a, u8 *life_time_est_b)
{

#ifndef UFS_IOCTL_QUERY
#define UFS_IOCTL_QUERY			0x5388
#define UPIU_QUERY_OPCODE_READ_DESC	0x1

#define QUERY_DESC_IDN_HEALTH 0x9
#define QUERY_DESC_HEALTH_DEF_SIZE 0x25

#define HEALTH_DESC_PARAM_EOL_INFO 0x2
#define HEALTH_DESC_PARAM_LIFE_TIME_EST_A 0x3
#define HEALTH_DESC_PARAM_LIFE_TIME_EST_B 0x4
#endif
	struct ufs_ioctl_query_data {
		__u32 opcode;
		__u8 idn;
		__u16 buf_size;
		__u8 buffer[QUERY_DESC_HEALTH_DEF_SIZE];
	} query = { 0 };
	int ret = -ENOTSUPP;
	struct block_device *ufs_dev = bi_bdev->bd_contains;
	if (ufs_dev) {
		mm_segment_t old_fs = get_fs();
		set_fs(KERNEL_DS);
		query.opcode = UPIU_QUERY_OPCODE_READ_DESC;
		query.idn = QUERY_DESC_IDN_HEALTH;
		query.buf_size = QUERY_DESC_HEALTH_DEF_SIZE;
		ret = blkdev_ioctl(ufs_dev, FMODE_READ, UFS_IOCTL_QUERY,
				(unsigned long)&query);
		set_fs(old_fs);
		if (ret == 0) {
			*pre_eol_info = query.buffer[HEALTH_DESC_PARAM_EOL_INFO];
			*life_time_est_a = query.buffer[HEALTH_DESC_PARAM_LIFE_TIME_EST_A];
			*life_time_est_b = query.buffer[HEALTH_DESC_PARAM_LIFE_TIME_EST_B];
		}
	}
	return ret;
}
#else
int __attribute__((weak)) blk_lld_health_query(struct block_device *bi_bdev,
	u8 *pre_eol_info, u8 *life_time_est_a, u8 *life_time_est_b)
 {
	*pre_eol_info = 1;
	*life_time_est_a = 3;
	*life_time_est_b = 3;
	hh_print(HHLOG_ERR, "weak blk_lld_health_query\n");
	return 0;
 }
#endif
#endif

static int hyperhold_health_check(void)
{
	int ret;
	u8 pre_eol_info = PRE_EOL_INFO_OVER_VAL;
	u8 life_time_est_a = LIFE_TIME_EST_OVER_VAL;
	u8 life_time_est_b = LIFE_TIME_EST_OVER_VAL;

	if (unlikely(!global_settings.real_bdev)) {
		hh_print(HHLOG_ERR, "bdev is null!\n");

		return -EFAULT;
	}

#ifdef CONFIG_HYPERHOLD_GKI
	ret = get_ufs_health_info(&pre_eol_info, &life_time_est_a, &life_time_est_b);
#else
	ret = blk_lld_health_query(global_settings.real_bdev, &pre_eol_info,
		&life_time_est_a, &life_time_est_b);
#endif
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

	return 0;
}

ssize_t hyperhold_enable_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	int ret;
	unsigned long val;

	ret = kstrtoul(buf, 0, &val);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "val is error!\n");

		return -EINVAL;
	}

	/* hyperhold must be close when over 70% life time uesd */
	if (hyperhold_health_check())
		val = false;

	if (hyperhold_set_enable_init(!!val))
		return -EINVAL;

	hyperhold_set_enable(!!val);

	return len;
}

ssize_t hyperhold_enable_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "hyperhold %s reclaim_in %s\n",
		hyperhold_enable() ? "enable" : "disable",
		hyperhold_reclaim_in_enable() ? "enable" : "disable");
}

ssize_t hyperhold_mapper_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	if (global_settings.mapper_name)
		kfree(global_settings.mapper_name);
	global_settings.mapper_name = kstrdup(buf, GFP_KERNEL);
	return len;
}

ssize_t hyperhold_mapper_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%s\n", global_settings.mapper_name ? : "");
}

#ifdef CONFIG_HYPERHOLD_GKI
void hyperhold_gki_zram_exit(void)
{
	struct zram *zram = global_settings.zram;

	if(!zram)
		return;
	global_settings.zram = NULL;
	down_write(&zram->init_lock);
	if(zram->bitmap)
		kfree(zram->bitmap);
	hyperhold_close_bdev(zram->bdev,zram->backing_dev);
	down_write(&zram->init_lock);
#ifdef CONFIG_ZSWAPD_GKI
	hhgki_zswapd_deinit();
#endif
}

#ifdef CONFIG_HYPERHOLD_GKI_DEBUG
static void hyperhold_gki_loglevel_set(int level)
{
	global_settings.log_level = level;
}

ssize_t hyperhold_gki_debug_level_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	unsigned long val;
	int ret;

	if (!hyperhold_enable())
		return len;

	ret = kstrtoul(buf,0,&val);
	if(unlikely(ret))
		return -EINVAL;
	hyperhold_gki_loglevel_set((int)val);

	return len;
}

ssize_t hyperhold_gki_debug_level_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	ssize_t size = 0;
	size += scnprintf(buf + size, PAGE_SIZE - size,
				"Hyperhold log level: %d\n",
				hyperhold_loglevel());
	return size;
}
#endif
#endif



#ifdef CONFIG_HYPERHOLD_DEBUG_FS
static void hyperhold_loglevel_set(int level)
{
	global_settings.log_level = level;
}

static bool ft_get_val(const char *buf, const char *token, unsigned long *val)
{
	int ret = -EINVAL;
	char *str = strstr(buf, token);

	if (str)
		ret = kstrtoul(str + strlen(token), 0, val);

	return ret == 0;
}

ssize_t hyperhold_ft_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	char *type_buf = NULL;
	unsigned long val;

	if (!hyperhold_enable())
		return len;

	type_buf = strstrip((char *)buf);
	if (ft_get_val(type_buf, "idle", &val)) {
		memcg_idle_count(global_settings.zram);
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
