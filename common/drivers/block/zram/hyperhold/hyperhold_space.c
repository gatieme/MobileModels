/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2022. All rights reserved.
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
 * Author:	Wang Fa <fa.wang@huawei.com>
 *
 * Create: 2021-12-15
 *
 */
#define pr_fmt(fmt) "[HYPERHOLD]" fmt

#include <linux/kernel.h>
#include <linux/blkdev.h>
#include <linux/atomic.h>
#include <linux/memcontrol.h>
#include <linux/mount.h>
#include <linux/file.h>
#include <linux/dcache.h>
#include <linux/types.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/hyperhold_inf.h>

#include "zram_drv.h"
#include "hyperhold.h"
#include "hyperhold_internal.h"

#define HP_PARTITION_PATH "/dev/block/by-name/hyperhold"
#define HP_FILE_PATH "/data/vendor/hyperhold/swapfile"
#define MAX_HP_FILE_PATH_LEN 128
#define MAX_HP_FILE_RATE (100UL)
#define MBYTE_TO_BYTE_FACTOR (1024UL * 1024UL)
#define MAX_HP_FILE_SZ_MBYTE (5UL * 1024UL)
#define MAX_HP_FILE_NUM MAX_HP_FILE_SZ_MBYTE
#define HP_FILE_SZ_MBYTE (128UL)
#define HP_EXT_NUM_PER_MBYTE (32UL)

static void hyperhold_space_set_zram(struct zram *zram,
	struct block_device *bdev, unsigned long nr_pages)
{
	down_write(&zram->init_lock);
	zram->bdev = bdev;
	zram->backing_dev = NULL;
	zram->nr_pages = nr_pages;
	up_write(&zram->init_lock);

	hh_print(HHLOG_ERR, "zram nr_pages %llu\n", nr_pages);
}

static void hyperhold_set_par_file(struct zram *zram,
	struct block_device *bdev, unsigned long nr_pages)
{
	struct space_info_para *space_info = hyperhold_space_info();

	space_info->par_file_num =(nr_pages << PAGE_SHIFT >> EXTENT_SHIFT) /
		space_info->nr_exts_per_file;
	if (space_info->par_file_num <= 0)
		return;

	space_info->allocated_file_num = space_info->par_file_num;
	space_info->enable_par_file = true;

	down_write(&zram->init_lock);
	zram->par_bdev = bdev;
	up_write(&zram->init_lock);

	hh_print(HHLOG_ERR, "file_num %u allocated_parfile_num %u\n",
		space_info->file_num, space_info->allocated_file_num);
}

bool hyperhold_get_par_file_enable(void)
{
	struct space_info_para *space_info = hyperhold_space_info();

	return space_info->enable_par_file;
}

static sector_t hyperhold_get_partition_sector(int ext_id)
{
	return ext_id * EXTENT_SECTOR_SIZE;
}

static sector_t hyperhold_get_file_sector(int ext_id)
{
	unsigned long file_index;
	unsigned long file_offset;
	struct space_info_para *space_info = hyperhold_space_info();

	file_index = ext_id / space_info->nr_exts_per_file;
	file_offset = ext_id % space_info->nr_exts_per_file;

	if (file_index >= space_info->file_inited_num) {
		hh_print(HHLOG_ERR, "ext_id err %d exts_num %llu inited_num %llu\n",
			ext_id, space_info->nr_exts_per_file, space_info->file_inited_num);
		return 0;
	}

	hh_print(HHLOG_DEBUG, "ext_id %d, file_index %llu, file_offset %llu, sector %llu\n",
			ext_id, file_index, file_offset, space_info->start_sector[file_index]);

	return space_info->start_sector[file_index] +
		file_offset * EXTENT_SECTOR_SIZE;
}

static int hyperhold_get_file_path(char *buff, unsigned long idnex)
{
	int ret;

	ret = snprintf(buff, MAX_HP_FILE_PATH_LEN, "%s_%lu",
		HP_FILE_PATH, idnex);
	if (ret <= 0)
		return -EAGAIN;

	return 0;
}

static int hyperhold_file_ops_check(struct hyperhold_file_ops *file_ops)
{
	if (!file_ops || !file_ops->alloc || !file_ops->check ||
		!file_ops->free || !file_ops->get_sector) {
		hh_print(HHLOG_ERR, "file_ops check fail\n");
		return -EINVAL;
	}

	return 0;
}

static void hyperhold_update_max_use_exts(void)
{
	struct space_para_cfg *space_para = hyperhold_space_para();
	struct space_info_para *space_info = hyperhold_space_info();
	unsigned long max_use_nr_exts;
	unsigned long limit_use_nr_exts;
	unsigned long max_ext_num = space_info->file_inited_num *
		space_info->nr_exts_per_file;

	max_use_nr_exts = space_para->space_size * HP_EXT_NUM_PER_MBYTE;
	limit_use_nr_exts = (max_ext_num * space_info->space_rate) / MAX_HP_FILE_RATE;
	if (max_use_nr_exts > limit_use_nr_exts)
		max_use_nr_exts = limit_use_nr_exts;

	atomic64_set(&space_info->max_ext_num, max_use_nr_exts);
}

static void hyperhold_alloc_file_proc(unsigned long start_file_index)
{
	int ret;
	unsigned long file_index;
	char file_path[MAX_HP_FILE_PATH_LEN] = { 0 };
	struct space_info_para *space_info = hyperhold_space_info();
	unsigned long long file_size;

	if (start_file_index >= space_info->file_num)
		return;

	file_size = (unsigned long long)space_info->file_size * MBYTE_TO_BYTE_FACTOR;
	hh_print(HHLOG_ERR, "file_size %llu %llu\n", space_info->file_size, file_size);
	for (file_index = start_file_index; file_index < space_info->file_num;
		++file_index) {
		ret = hyperhold_get_file_path(file_path, file_index);
		if (unlikely(ret)) {
			hh_print(HHLOG_ERR, "hyperhold_get_file_path %u fail\n",
				file_index);
			break;
		}

		if (!space_info->file_ops->check(file_path, file_size))
			continue;

		space_info->file_ops->free(file_path, file_size);
		ret = space_info->file_ops->alloc(file_path, file_size);
		if (ret)
			break;

		hh_print(HHLOG_ERR, "alloc new file_index %u\n", file_index);
	}

	space_info->allocated_file_num = file_index;
	hh_print(HHLOG_ERR, "allocated_file_num %u\n", file_index);
}

static void hyperhold_free_file_proc(unsigned long file_num,
	unsigned long start_file_index)
{
	int ret;
	unsigned long cnt;
	char file_path[MAX_HP_FILE_PATH_LEN] = { 0 };
	struct space_info_para *space_info = hyperhold_space_info();
	unsigned long long file_size;

	file_size = (unsigned long long)space_info->file_size * MBYTE_TO_BYTE_FACTOR;
	for (cnt = 0; cnt < file_num; ++cnt) {
		ret = hyperhold_get_file_path(file_path, start_file_index + cnt);
		if (unlikely(ret)) {
			hh_print(HHLOG_ERR, "hyperhold_get_file_path %u fail\n", cnt);
			break;
		}

		space_info->file_ops->free(file_path, file_size);
	}
}

int hyperhold_get_bdev(const char *dir_name, struct block_device **bdev)
{
	int ret = 0;
	struct file *file = NULL;
	struct super_block *sb = NULL;
	struct space_info_para *space_info = hyperhold_space_info();

	file = filp_open(dir_name, O_RDONLY, S_IRWXU);
	if (IS_ERR_OR_NULL(file)) {
		hh_print(HHLOG_ERR, "open file %s error %ld", dir_name,
			 PTR_ERR(file));
		return -EINVAL;
	}

	sb = file->f_path.mnt->mnt_sb;
	if (!sb || (sb->s_magic != space_info->file_magic)) {
		ret = -ENOENT;
		hh_print(HHLOG_ERR, "mount info error!\n");
		goto out;
	}

	hh_print(HHLOG_DEBUG, "path = %s fstype = %s\n", dir_name,
		 sb->s_type->name);
	*bdev = sb->s_bdev;
out:
	filp_close(file, NULL);
	return ret;
}

static int hyperhold_check_space_setting(struct blk_hp_set_space *space_setting)
{
	struct space_info_para *space_info = hyperhold_space_info();

	if (space_setting->space_type >= HP_SPACE_TYPE_BUTT) {
		hh_print(HHLOG_ERR, "space_type type %d err\n", space_setting->space_type);
		return -EINVAL;
	}

	if ((space_setting->space_type == HP_FILE_SPACE) &&
		((space_setting->space_size > MAX_HP_FILE_SZ_MBYTE) ||
		!space_setting->space_size)) {
		hh_print(HHLOG_ERR, "space setting err: %llu %llu %llu\n",
			space_setting->space_size, MAX_HP_FILE_SZ_MBYTE, space_info->file_size);
		return -EINVAL;
	}

	return 0;
}

void hyperhold_used_exts_num_inc(void)
{
	struct space_info_para *space_info = hyperhold_space_info();

	atomic64_inc(&space_info->used_exts_num);
}

void hyperhold_used_exts_num_dec(void)
{
	struct space_info_para *space_info = hyperhold_space_info();

	atomic64_dec(&space_info->used_exts_num);
}

static void hyperhold_save_space_setting(struct blk_hp_set_space *space_setting)
{
	struct space_para_cfg *space_para = hyperhold_space_para();
	struct space_info_para *space_info = hyperhold_space_info();
	unsigned long total_file_size;

	space_para->space_type = space_setting->space_type;
	if (space_para->space_type == HP_FILE_SPACE) {
		space_para->space_size = space_setting->space_size;
		space_info->nr_exts_per_file = space_info->file_size * HP_EXT_NUM_PER_MBYTE;
		space_info->file_num = (space_para->space_size +
			space_info->file_size - 1) / space_info->file_size;
		space_info->nr_exts = space_info->nr_exts_per_file * space_info->file_num;
		total_file_size = space_info->file_num * space_info->file_size;
		space_info->nr_pages =
			(total_file_size * MBYTE_TO_BYTE_FACTOR) >> PAGE_SHIFT;
		space_info->allocated_file_num = 0;
	}

	hh_print(HHLOG_ERR, "space_type %u space_size %u\n",
		space_para->space_type, space_para->space_size);
	hh_print(HHLOG_ERR, "file_num %u allocated_file_num %u\n",
		space_info->file_num, space_info->allocated_file_num);
	hh_print(HHLOG_ERR, "nr_pages %u nr_exts %u\n",
		space_info->nr_pages, space_info->nr_exts);
}

static int hyperhold_get_file_para(void)
{
	struct space_info_para *space_info = hyperhold_space_info();
	struct hyperhold_file_ops *file_ops = hyperhold_get_file_ops();

	if (hyperhold_file_ops_check(file_ops))
		return -EFAULT;

	space_info->file_size = HP_FILE_SZ_MBYTE;
	space_info->file_ops = file_ops;
	space_info->space_rate = MAX_HP_FILE_RATE;
	space_info->file_magic = F2FS_SUPER_MAGIC;

	return 0;
}

static void hyperhold_space_update_file_info(void)
{
	int ret;
	unsigned long loop;
	char file_path[MAX_HP_FILE_PATH_LEN] = { 0 };
	struct space_info_para *space_info = hyperhold_space_info();

	if (space_info->file_inited_num == space_info->allocated_file_num)
		return;

	for (loop = space_info->file_inited_num;
		loop < space_info->allocated_file_num; ++loop) {
		ret = hyperhold_get_file_path(file_path, loop);
		if (unlikely(ret)) {
			hh_print(HHLOG_ERR, "hyperhold_get_file_path %u fail\n", loop);
			return;
		}

		ret = space_info->file_ops->get_sector(file_path,
			space_info->start_sector + loop);
		if (ret) {
			hh_print(HHLOG_ERR, "get %d start_sector failed\n", loop);
			return;
		}
		space_info->file_inited_num = loop + 1;
	}

	for (loop = 0; loop < space_info->file_inited_num; ++loop)
		hh_print(HHLOG_ERR, "fileindex %d start_sector %lu\n",
			loop, space_info->start_sector[loop]);

	hyperhold_update_max_use_exts();
}

static void hyperhold_expend_space_proc(void)
{
	struct space_info_para *space_info = hyperhold_space_info();
	unsigned long start_file_index = space_info->allocated_file_num;

	if (space_info->file_num > space_info->allocated_file_num)
		hyperhold_alloc_file_proc(start_file_index);

	hyperhold_space_update_file_info();
}

static void hyperhold_close_bdev(struct block_device *bdev,
					struct file *backing_dev)
{
	if (bdev)
		blkdev_put(bdev, FMODE_READ | FMODE_WRITE | FMODE_EXCL);

	if (backing_dev)
		filp_close(backing_dev, NULL);
}

static struct file *hyperhold_open_bdev(const char *file_name)
{
	struct file *backing_dev = NULL;

	backing_dev = filp_open(file_name, O_RDWR | O_LARGEFILE, 0);
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

static void hyperhold_check_partition_space(struct zram *zram, const char *file_name)
{
	struct file *backing_dev = NULL;
	struct inode *inode = NULL;
	unsigned long nr_pages;
	struct block_device *bdev = NULL;
	int err;
	int nr_par_file;

	nr_par_file = 0;
	backing_dev = hyperhold_open_bdev(file_name);
	if (!backing_dev) {
		hh_print(HHLOG_ERR, "%s open bdev failed!\n", file_name);
		return;
	}

	if (!backing_dev->f_mapping) {
		hh_print(HHLOG_ERR, "%s no f_mapping!\n", file_name);
		return;
	}
	if (!backing_dev->f_mapping->host) {
		hh_print(HHLOG_ERR, "%s no host!\n", file_name);
		return;
	}
	inode = backing_dev->f_mapping->host;

	bdev = bdgrab(I_BDEV(inode));
	err = blkdev_get(bdev, FMODE_READ | FMODE_WRITE | FMODE_EXCL, zram);
	if (unlikely(err < 0)) {
		hh_print(HHLOG_ERR, "%s blkdev_get failed! eno = %d\n",
					file_name, err);
		bdev = NULL;
		goto out;
	}

	nr_pages = (unsigned long)i_size_read(inode) >> PAGE_SHIFT;

	err = set_blocksize(bdev, PAGE_SIZE);
	if (unlikely(err)) {
		hh_print(HHLOG_ERR,
			"%s set blocksize failed! eno = %d\n", file_name, err);
		goto out;
	}

	err = hyperhold_health_check(bdev);
	if (unlikely(err)) {
		hh_print(HHLOG_ERR, "health check failed\n");
		goto out;
	}

	hyperhold_set_par_file(zram, bdev, nr_pages);
	return;
out:
	hyperhold_close_bdev(bdev, backing_dev);
}

static int hyperhold_bind(struct zram *zram, const char *file_name)
{
	struct file *backing_dev = NULL;
	struct inode *inode = NULL;
	unsigned long nr_pages;
	unsigned long max_use_nr_exts;
	struct block_device *bdev = NULL;
	int err;
	struct space_info_para *space_info = hyperhold_space_info();

	backing_dev = hyperhold_open_bdev(file_name);
	if (unlikely(!backing_dev))
		return -EINVAL;

	inode = backing_dev->f_mapping->host;

	bdev = bdgrab(I_BDEV(inode));
	err = blkdev_get(bdev, FMODE_READ | FMODE_WRITE | FMODE_EXCL, zram);
	if (unlikely(err < 0)) {
		hh_print(HHLOG_ERR, "%s blkdev_get failed! eno = %d\n",
					file_name, err);
		bdev = NULL;
		goto out;
	}

	nr_pages = (unsigned long)i_size_read(inode) >> PAGE_SHIFT;

	err = set_blocksize(bdev, PAGE_SIZE);
	if (unlikely(err)) {
		hh_print(HHLOG_ERR,
			"%s set blocksize failed! eno = %d\n", file_name, err);
		goto out;
	}

	err = hyperhold_health_check(bdev);
	if (unlikely(err)) {
		hh_print(HHLOG_ERR, "health check failed\n");
		goto out;
	}

	hyperhold_space_set_zram(zram, bdev, nr_pages);

	space_info->nr_pages = nr_pages;
	max_use_nr_exts = nr_pages << PAGE_SHIFT >> EXTENT_SHIFT;
	space_info->nr_exts = max_use_nr_exts;
	atomic64_set(&space_info->max_ext_num, max_use_nr_exts);

	return 0;
out:
	hyperhold_close_bdev(bdev, backing_dev);

	return err;
}

static int hyperhold_alloc_partition_space(struct zram *zram)
{
	int ret = hyperhold_bind(zram, HP_PARTITION_PATH);

	return ret;
}

int hyperhold_set_space(struct blk_hp_set_space *space_setting)
{
	int ret;

	if (hyperhold_get_cfg()) {
		hh_print(HHLOG_ERR, "space_para cfg again\n");
		return -EINVAL;
	}

	ret = hyperhold_check_space_setting(space_setting);
	if (ret)
		return ret;

	ret = hyperhold_get_file_para();
	if (ret)
		return ret;

	hyperhold_save_space_setting(space_setting);
	hyperhold_set_cfg();
	return 0;
}

int hyperhold_free_filespace(void)
{
	int ret;

	ret = hyperhold_get_file_para();
	if (ret) {
		hh_print(HHLOG_ERR, "get file para fail\n");
		return ret;
	}

	hyperhold_free_file_proc(MAX_HP_FILE_NUM, 0);
	return 0;
}

void hyperhold_expend_space(bool en)
{
	if (!en)
		return;

	if (hyperhold_is_file_space())
		hyperhold_expend_space_proc();
}

unsigned long hperhold_get_max_ext_num(void)
{
	struct space_info_para *space_info = hyperhold_space_info();

	return atomic64_read(&space_info->max_ext_num);
}

sector_t hyperhold_get_sector(int ext_id)
{
	if (hyperhold_is_file_space())
		return hyperhold_get_file_sector(ext_id);
	else
		return hyperhold_get_partition_sector(ext_id);
}

void hyperhold_space_sector_deinit(void)
{
	struct space_info_para *space_info = hyperhold_space_info();

	if (space_info->start_sector) {
		vfree(space_info->start_sector);
		space_info->start_sector = NULL;
	}
}

int hyperhold_space_file_sector_init(void)
{
	unsigned long loop;
	struct space_info_para *space_info = hyperhold_space_info();

	space_info->start_sector = vzalloc(space_info->file_num * sizeof(sector_t));
	if (!space_info->start_sector) {
		hh_print(HHLOG_ERR, "start_sector alloc failed\n");
		return -ENOMEM;
	}

	if (space_info->enable_par_file) {
		for (loop = space_info->file_inited_num;
			loop < space_info->par_file_num; ++loop) {
			*(space_info->start_sector + loop) = loop * EXTENT_SECTOR_SIZE *
				space_info->nr_exts_per_file;
			space_info->file_inited_num = loop + 1;
			hh_print(HHLOG_ERR, "file_inited_num %u\n", space_info->file_inited_num);
		}
	}

	hh_print(HHLOG_ERR, "file_inited_num %u\n", space_info->file_inited_num);
	for (loop = 0; loop < space_info->file_inited_num; ++loop)
		hh_print(HHLOG_ERR, "fileindex %d start_sector %lu\n",
			loop, space_info->start_sector[loop]);

	return 0;
}

static int hyperhold_alloc_file_space(struct zram *zram)
{
	int ret;
	struct block_device *bdev = NULL;
	struct space_info_para *space_info = hyperhold_space_info();

	hyperhold_check_partition_space(zram, HP_PARTITION_PATH);

	ret = hyperhold_get_bdev("/data/vendor", &bdev);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "hyperhold_get_bdev fail\n");
		return -EINVAL;
	}

	if (!bdev) {
		hh_print(HHLOG_ERR, "bdev is null\n");
		return -EINVAL;
	}

	ret = hyperhold_health_check(bdev);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "health check failed\n");
		return hyperhold_free_filespace();
	}

	hyperhold_alloc_file_proc(space_info->par_file_num);
	hyperhold_free_file_proc(MAX_HP_FILE_NUM - space_info->allocated_file_num,
		space_info->allocated_file_num);

	hyperhold_space_set_zram(zram, bdev, space_info->nr_pages);

	return 0;
}

int hyperhold_alloc_space(struct zram *zram)
{
	if (hyperhold_is_file_space()) {
		return hyperhold_alloc_file_space(zram);
	} else {
		return hyperhold_alloc_partition_space(zram);
	}
}

unsigned long hyperhold_file_bit2id(unsigned long bit)
{
	unsigned long file_index;
	unsigned long file_offset;
	struct space_info_para *space_info = hyperhold_space_info();

	file_index = bit / space_info->nr_exts_per_file;
	file_offset = bit % space_info->nr_exts_per_file;

	return file_index * space_info->nr_exts_per_file +
		space_info->nr_exts_per_file - 1 - file_offset;
}

unsigned long hyperhold_file_id2bit(unsigned long ext_id)
{
	unsigned long file_index;
	unsigned long file_offset;
	struct space_info_para *space_info = hyperhold_space_info();

	file_index = ext_id / space_info->nr_exts_per_file;
	file_offset = ext_id % space_info->nr_exts_per_file;

	return file_index * space_info->nr_exts_per_file +
		space_info->nr_exts_per_file - 1 - file_offset;
}

bool io_spacetype_different(struct hyperhold_segment *segment,
	struct hyperhold_entry *io_entry)
{
	struct space_info_para *space_info = hyperhold_space_info();

	if (!space_info->enable_par_file)
		return false;

	if (ext_to_par_file(io_entry->ext_id) == segment->to_par_file)
		return false;

	return true;
}

bool ext_to_par_file(int ext_id)
{
	struct space_info_para *space_info = hyperhold_space_info();

	if (!space_info->enable_par_file)
		return false;

	return (ext_id / space_info->nr_exts_per_file) < space_info->par_file_num;
}
