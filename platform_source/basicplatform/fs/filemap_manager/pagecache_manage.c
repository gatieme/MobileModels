/*
 * Copyright (c) 2017-2018 HiSilicon Technologies Co., Ltd.
 *
 * This source code is released for free distribution under the terms of the
 * GNU General Public License
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * File Name:    pagecache_manage.c
 */

#include <linux/backing-dev.h>
#include <linux/blkdev.h>
#include <linux/bootdevice/bootdevice.h>
#include <linux/err.h>
#include <linux/errno.h>
#ifdef CONFIG_FILE_MAP
#include <linux/file_map.h>
#endif
#include <linux/fs/pagecache_manage.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/mmzone.h>
#include <linux/module.h>
#include <linux/mount.h>
#include <linux/namei.h>
#include <linux/oom.h>
#include <linux/path.h>
#include <linux/pid.h>
#include <linux/proc_fs.h>
#include <linux/statfs.h>
#include <linux/swap.h>
#include <linux/sysctl.h>
#include <linux/version.h>
#include <linux/workqueue.h>
#include <linux/writeback.h>
#include <linux/sched/mm.h>

#include <internal.h>
#include "pagecache_manage_interface.h"

typedef enum tag_pch_log_level {
	LOG_LEVEL_ERROR = 0,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_INFO,
	LOG_LEVEL__DEBUG,
	LOG_LEVEL_TOTAL = LOG_LEVEL_INFO,
} pch_log_level;

pch_log_level g_pch_print_level = LOG_LEVEL_ERROR;

typedef enum tag_pch_fs_used {
	FS_TYPE_EXT4 = 0,
	FS_TYPE_F2FS,
	FS_TYPE_TOTAL = FS_TYPE_EXT4,
} pch_fs_type_used;

#define pch_print(level, fmt, ...) do { \
	if (level <= g_pch_print_level) \
		pr_err(fmt, ##__VA_ARGS__); \
} while (0)

#define SET_ERR_PAGE	2
#define NEXT_PAGE	1

/* default value set */
static unsigned int page_cache_func_enable = 1;
static unsigned int emmc_ra_ahead_size = 8;
static unsigned int emmc_ra_round_size = 8;
static unsigned int ufs_ra_ahead_size = 16;
static unsigned int ufs_ra_round_size = 16;
static unsigned int extend_ra_size = 16;
static unsigned int lowmem_ra_size = 8;
static unsigned int lowstorage_ratio = 1;
static unsigned int lowstorage_ra_size = 4;
static unsigned int lowstorage_extend_size = 16;
static unsigned int lowmem_reserved;

struct pch_info_desc {
#ifdef CONFIG_MAS_BLK
	struct blk_busyidle_event_node event_node;
#endif
	struct block_device	*bdev;
	struct timer_list	timer;
	/* Work Queues */
	struct work_struct	timeout_work;
	struct semaphore	work_sem;

	unsigned long timer_work_state;
	unsigned int func_enable;
	unsigned int boot_device;
	unsigned int readaround_ra_size;
	unsigned int readahead_ra_size;
	unsigned int readextend_ra_size;
	unsigned int lowmem_ra_size;
	unsigned int lowstorage_ratio;
	unsigned int fs_mount_stat;
};


static struct pch_info_desc *pch_info;

#define ARRAY_LOWMEM_ADJ_SIZE 4
#define BIT_MAP_COUNT  2
#define BAVAIL_RATION 100
static int lowmem_adj_size = 4;
static unsigned long lowmem_minfree[6] = {
	3 * 512, /* 6MB */
	2 * 1024, /* 8MB */
	4 * 1024, /* 16MB */
	16 * 1024, /* 64MB */
};
static int lowmem_minfree_size = 4;

static inline int is_userdata_mounted(void)
{
	return (pch_info->fs_mount_stat & USRDATA_IS_MOUNTED) ? 1 : 0;
}

static inline int is_userdata_umounted(void)
{
	return (pch_info->fs_mount_stat & USRDATA_IS_UMOUNTED) ? 1 : 0;
}

static inline int is_userdata_umounting(void)
{
	return (pch_info->fs_mount_stat & USRDATA_IS_UMOUNTING) ? 1 : 0;
}

static inline void clear_userdata_mounted(void)
{
	pch_info->fs_mount_stat &= ~USRDATA_IS_MOUNTED;
}

static inline void clear_userdata_umounted(void)
{
	pch_info->fs_mount_stat &= ~USRDATA_IS_UMOUNTED;
}

static inline void clear_userdata_umounting(void)
{
	pch_info->fs_mount_stat &= ~USRDATA_IS_UMOUNTING;
}

static inline void set_userdata_mounted(void)
{
	pch_info->fs_mount_stat |= USRDATA_IS_MOUNTED;
}

static inline void set_userdata_umounted(void)
{
	pch_info->fs_mount_stat |= USRDATA_IS_UMOUNTED;
}

static inline void set_userdata_umounting(void)
{
	pch_info->fs_mount_stat |= USRDATA_IS_UMOUNTING;
}

#ifdef CONFIG_DFX_DEBUG_FS
static struct ctl_table pch_table[] = {
	{
	  .procname	= "enabled",
	  .data		= &page_cache_func_enable,
	  .maxlen	= sizeof(page_cache_func_enable),
	  .mode		= 0400,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "emmc_readahead_ra_size",
	  .data		= &emmc_ra_ahead_size,
	  .maxlen	= sizeof(emmc_ra_ahead_size),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "emmc_readaound_ra_size",
	  .data		= &emmc_ra_round_size,
	  .maxlen	= sizeof(emmc_ra_round_size),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "ufs_readahead_ra_size",
	  .data		= &ufs_ra_ahead_size,
	  .maxlen	= sizeof(ufs_ra_ahead_size),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "ufs_readaound_ra_size",
	  .data		= &ufs_ra_round_size,
	  .maxlen	= sizeof(ufs_ra_round_size),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "readextend_ra_size",
	  .data		= &extend_ra_size,
	  .maxlen	= sizeof(extend_ra_size),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "lowmem_ra_size",
	  .data		= &lowmem_ra_size,
	  .maxlen	= sizeof(lowmem_ra_size),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "lowstorage_ratio",
	  .data		= &lowstorage_ratio,
	  .maxlen	= sizeof(lowstorage_ratio),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{
	  .procname	= "lowmem_reserved",
	  .data		= &lowmem_reserved,
	  .maxlen	= sizeof(lowmem_reserved),
	  .mode		= 0640,
	  .proc_handler	= proc_dointvec,
	},
	{ }
};

static struct ctl_table pch_root_table[] = {
	{ .procname	= "page_cache",
	  .mode		= 0555,
	  .child	= pch_table },
	{ }
};

static struct ctl_table_header *pch_table_header;
#endif

/*
 * Map blocks using the previous result first.
 */
void pch_map_block_first(struct ext4_map_blocks *map, sector_t *block_in_file, unsigned *page_block,
	unsigned blocks_per_page, sector_t *blocks) {
	unsigned relative_block;

	if ((map->m_flags & EXT4_MAP_MAPPED) &&
		*block_in_file > map->m_lblk &&
		*block_in_file < (map->m_lblk + map->m_len)) {
		unsigned map_offset = *block_in_file - map->m_lblk;
		unsigned last = map->m_len - map_offset;

		for (relative_block = 0; ; relative_block++) {
			if (relative_block == last) {
				/* needed? */
				map->m_flags &= ~EXT4_MAP_MAPPED;
				break;
			}
			if (*page_block == blocks_per_page)
				break;
			blocks[*page_block] = map->m_pblk + map_offset +
				relative_block;
			(*page_block)++;
			(*block_in_file)++;
		}
	}
}

int pch_map_more_blocks(unsigned first_hole, unsigned blocks_per_page, struct page *page,
	int fully_mapped, struct inode *inode, unsigned blkbits) {
	if (first_hole != blocks_per_page) {
		zero_user_segment(page, first_hole << blkbits,
				  PAGE_SIZE);
		if (first_hole == 0) {
			if (ext4_need_verity(inode, page->index) &&
			    !fsverity_verify_page(page))
				return SET_ERR_PAGE;
			SetPageUptodate(page);
			unlock_page(page);
			return NEXT_PAGE;
		}
	} else if (fully_mapped) {
		SetPageMappedToDisk(page);
	}
	return 0;
}

void pch_set_bio(struct bio **bio, sector_t next_block, struct inode *inode, sector_t *blocks,
	unsigned blkbits, struct block_device *bdev, unsigned int nr_pages,
	struct page *page, struct readahead_control *rac) {
	/*
	 * bio_alloc will _always_ be able to allocate a bio if
	 * __GFP_DIRECT_RECLAIM is set, see bio_alloc_bioset().
	 */
	*bio = bio_alloc(GFP_KERNEL,
		min_t(int, nr_pages, BIO_MAX_PAGES));
	fscrypt_set_bio_crypt_ctx(*bio, inode, next_block,
				  GFP_KERNEL);
	ext4_set_bio_post_read_ctx(*bio, inode, page->index);
	bio_set_dev(*bio, bdev);
	bio_set_op_attrs(*bio, REQ_OP_READ,
				rac ? REQ_RAHEAD : 0);
}

void pch_io_smart_end(unsigned io_submited, struct block_device *bdev) {
	if (io_submited)
		/* we have got one quota at the beginning, so sub 1 here */
		blk_throtl_get_quotas(bdev, PAGE_SIZE,
		    msecs_to_jiffies(100), true,
		    io_submited - 1);
}
void pch_io_smart_check(struct readahead_control *rac, unsigned int nr_pages, struct block_device *bdev)
{
	if (nr_pages && rac)
		/*
		 * Get one quota before read pages, when this ends,
		 * get the rest of quotas according to how many bios
		 * we submited in this routine.
		 */
		blk_throtl_get_quota(bdev, PAGE_SIZE,
		    msecs_to_jiffies(100), true);
}
void pch_fs_get_page(struct list_head *pages, struct readahead_control *rac, struct page **page)
{
	*page = list_entry(pages->prev, struct page, lru);
	list_del(&(*page)->lru);
	rac->_nr_pages--;
	rac->_index++;
}

void pch_update_blcoks(struct ext4_map_blocks *map, unsigned *page_block, sector_t *block_in_file,
	unsigned blocks_per_page, sector_t *blocks)
{
	unsigned relative_block;

	for (relative_block = 0; ; relative_block++) {
		if (relative_block == map->m_len) {
			/* needed? */
			map->m_flags &= ~EXT4_MAP_MAPPED;
					break;
		} else if (*page_block == blocks_per_page) {
			break;
		}
		blocks[*page_block] = map->m_pblk+relative_block;
		(*page_block)++;
		(*block_in_file)++;
	}
}

void pch_map_boundry(struct ext4_map_blocks *map, unsigned relative_block, unsigned blocks_per_page,
	struct bio *bio, sector_t *last_block_in_bio, sector_t *blocks, unsigned *io_submited, unsigned first_hole)
{
	if (((map->m_flags & EXT4_MAP_BOUNDARY) &&
		    (relative_block == map->m_len)) ||
		    (first_hole != blocks_per_page)) {
#ifdef CONFIG_BLK_CGROUP_IOSMART
			(*io_submited)++;
#endif
			ext4_submit_bio_read(bio);
			bio = NULL;
	} else {
		*last_block_in_bio = blocks[blocks_per_page - 1];
	}
}

void pch_confused(struct bio *bio, struct page *page, unsigned *io_submited)
{
	if (bio) {
#ifdef CONFIG_BLK_CGROUP_IOSMART
		(*io_submited)++;
#endif
		ext4_submit_bio_read(bio);
		bio = NULL;
	}
	if (!PageUptodate(page))
		block_read_full_page(page, ext4_get_block);
	else
		unlock_page(page);
}

void pch_set_error_page(struct page *page)
{
	SetPageError(page);
	zero_user_segment(page, 0,
			PAGE_SIZE);
	unlock_page(page);
}

void pch_map_init(struct ext4_map_blocks *map)
{
	map->m_pblk = 0;
	map->m_lblk = 0;
	map->m_len = 0;
	map->m_flags = 0;
}

void pch_block_data_init(sector_t *block_in_file, sector_t *next_block, sector_t *last_block,
	unsigned *page_block, unsigned blocks_per_page, unsigned int nr_pages,
	struct inode *inode, unsigned blocksize, struct page *page,
	unsigned blkbits, sector_t *last_block_in_file)
{
	*block_in_file = *next_block =
			(sector_t)page->index << (PAGE_SHIFT - blkbits);
	*last_block = *block_in_file + nr_pages * blocks_per_page;
	*last_block_in_file = (ext4_readpage_limit(inode) +
				      blocksize - 1) >> blkbits;
	if (*last_block > *last_block_in_file)
		*last_block = *last_block_in_file;
	*page_block = 0;
}

void pch_submit_bio(struct bio *bio, unsigned *io_submited)
{
	if (bio) {
#ifdef CONFIG_BLK_CGROUP_IOSMART
		(*io_submited)++;
#endif
		ext4_submit_bio_read(bio);
	}
}

int  pch_mapped(struct ext4_map_blocks *map, int *fully_mapped, unsigned *first_hole,
	unsigned *page_block, sector_t *block_in_file, unsigned blocks_per_page)
{
	if ((map->m_flags & EXT4_MAP_MAPPED) == 0) {
				*fully_mapped = 0;
				if (*first_hole == blocks_per_page)
					*first_hole = *page_block;
				(*page_block)++;
				(*block_in_file)++;
				return 1;
	}
	return 0;
}

int ext4_mas_mpage_readpages(struct inode *inode,
		struct readahead_control *rac, struct page *page, struct list_head *pages)
{
	struct bio *bio = NULL;
	sector_t last_block_in_bio = 0;
	const unsigned blkbits = inode->i_blkbits;
	const unsigned blocks_per_page = PAGE_SIZE >> blkbits;
	const unsigned blocksize = 1 << blkbits;
	sector_t next_block, block_in_file;
	sector_t last_block, last_block_in_file;
	sector_t blocks[MAX_BUF_PER_PAGE];
	unsigned page_block;
	struct block_device *bdev = inode->i_sb->s_bdev;
	int length;
	unsigned relative_block = 0;
#ifdef CONFIG_BLK_CGROUP_IOSMART
	unsigned io_submited = 0;
#endif
	struct ext4_map_blocks map;
	unsigned int nr_pages = rac ? readahead_count(rac) : 1;

	pch_map_init(&map);
#ifdef CONFIG_BLK_CGROUP_IOSMART
	pch_io_smart_check(rac, nr_pages, bdev);
#endif

	for (; nr_pages; nr_pages--) {
		int fully_mapped = 1;
		unsigned first_hole = blocks_per_page;
		int ret;

		if (pages) {
			pch_fs_get_page(pages, rac, &page);
			if (add_to_page_cache_lru(page, rac->mapping, page->index,
				  readahead_gfp_mask(rac->mapping)))
				goto next_page;
			prefetchw(&page->flags);
		}

		if (page_has_buffers(page))
			goto confused;

		pch_block_data_init(&block_in_file, &next_block, &last_block, &page_block,
			blocks_per_page, nr_pages, inode, blocksize, page, blkbits, &last_block_in_file);
		pch_map_block_first(&map, &block_in_file,&page_block,blocks_per_page, blocks);

		while (page_block < blocks_per_page) {
			if (block_in_file < last_block) {
				map.m_lblk = block_in_file;
				map.m_len = last_block - block_in_file;

				if (ext4_map_blocks(NULL, inode, &map, 0) < 0) {
				set_error_page:
					pch_set_error_page(page);
					goto next_page;
				}
			}
			if(pch_mapped(&map, &fully_mapped, &first_hole, &page_block, &block_in_file, blocks_per_page))
				continue;
			if (first_hole != blocks_per_page)
				goto confused; /* hole -> non-hole */

			if (page_block && blocks[page_block-1] != map.m_pblk-1) /* Contiguous blocks? */
				goto confused;
			pch_update_blcoks(&map, &page_block, &block_in_file, blocks_per_page, blocks);
		}
		ret = pch_map_more_blocks(first_hole, blocks_per_page, page, fully_mapped, inode, blkbits);
		if(ret == NEXT_PAGE)
			goto next_page;
		else if(ret == SET_ERR_PAGE)
			goto set_error_page;

		if (fully_mapped && blocks_per_page == 1 &&
		    !PageUptodate(page) && cleancache_get_page(page) == 0) {
			SetPageUptodate(page);
			goto confused;
		}

		if (bio && (last_block_in_bio != blocks[0] - 1 ||
			    !fscrypt_mergeable_bio(bio, inode, next_block))) {
		submit_and_realloc:
#ifdef CONFIG_BLK_CGROUP_IOSMART
			io_submited++;
#endif
			ext4_submit_bio_read(bio);
			bio = NULL;
		}
		if (bio == NULL) {
			pch_set_bio(&bio, next_block, inode, blocks, blkbits, bdev, nr_pages, page, rac);
			bio->bi_iter.bi_sector = blocks[0] << (blkbits - 9);
			bio->bi_end_io = mpage_end_io;
		}

		length = first_hole << blkbits;
		if (bio_add_page(bio, page, length, 0) < length)
			goto submit_and_realloc;

		pch_map_boundry(&map, relative_block, blocks_per_page,bio, &last_block_in_bio, blocks, &io_submited, first_hole);
		goto next_page;
	confused:
		pch_confused(bio, page, &io_submited);
	next_page:
		if (rac)
			put_page(page);
	}

	pch_submit_bio(bio, &io_submited);
#ifdef CONFIG_BLK_CGROUP_IOSMART
	pch_io_smart_end(io_submited, bdev);
#endif
	return 0;
}

/*
 * Function name: pch_thread_task_state
 * Discription: check wether thread foreground
 * Parameters:
 *      @ NULL
 * return value:
 *      @ 0: foreground state
 *      @ other: background state
 */

/*
 * Function name: pch_lowmem_check
 * Discription: check wether lowmem state
 * Parameters:
 *      @ NULL
 * return value:
 *      @ 2: mem high_wmark state
 *      @ 1: mem low_wmark state
 *      @ 0: normal state
 */
int pch_lowmem_check(void)
{
	unsigned long watermark;
	struct zone *zone = NULL;
	int ret = MEM_NORMAL_WMARK;

	zone = (first_online_pgdat())->node_zones;
	if (zone == NULL)
		return ret;

	watermark = high_wmark_pages(zone) + (2UL << (unsigned int)lowmem_reserved);
	if (!zone_watermark_ok(zone, 0, watermark, 0, 0))
		ret = MEM_HIGH_WMARK;

	watermark = low_wmark_pages(zone);
	if (!zone_watermark_ok(zone, 0, watermark, 0, 0))
		ret = MEM_LOW_WMARK;

	return ret;
}

/*
 * Function name: pch_lowmem_check2
 * Discription: check wether lowmem state for io using purpose
 * Parameters:
 *      @ NULL
 * return value:
 *      @ 2: mem high_wmark state
 *      @ 1: mem low_wmark state
 *      @ 0: normal state
 */
int pch_lowmem_check2(void)
{
	int array_size = ARRAY_LOWMEM_ADJ_SIZE;
	int i;
	unsigned long minfree = 0;

	unsigned long other_file = global_node_page_state(NR_FILE_PAGES) -
				global_node_page_state(NR_SHMEM) -
				total_swapcache_pages();
	unsigned long other_free = global_zone_page_state(NR_FREE_PAGES) -
				global_zone_page_state(NR_FREE_CMA_PAGES) -
				totalreserve_pages;

	if (lowmem_adj_size < array_size)
		array_size = lowmem_adj_size;
	if (lowmem_minfree_size < array_size)
		array_size = lowmem_minfree_size;
	for (i = 0; i < array_size; i++) {
		minfree = lowmem_minfree[i];
		if (other_free < minfree && other_file < minfree)
			return 1;
	}

	return 0;
}

#ifdef CONFIG_DFX_DEBUG_FS

enum GET_PAGE_SIMULATE_TYPE_E {
	GET_PAGE_NO_SIMULATE = 0, /* The value can't be changed! */
	GET_PAGE_SIMULATE_ALWAYS_FAIL,
	GET_PAGE_SIMULATE_ALWAYS_SUCC,
};

static enum GET_PAGE_SIMULATE_TYPE_E get_page_simulate_type
		= GET_PAGE_NO_SIMULATE;
int pch_get_page_sim_type_set(int type)
{
	get_page_simulate_type = type;
	return get_page_simulate_type;
}

#endif

/**
 * pch_get_page - find and get a page reference
 * @mapping: the address_space to search
 * @offset: the page index
 * @fgp_flags: PCG flags
 * @gfp_mask: gfp mask to use for the page cache data page allocation
 *
 */
struct page *pch_get_page(struct address_space *mapping, pgoff_t offset,
	int fgp_flags, gfp_t gfp_mask)
{
#ifdef CONFIG_DFX_DEBUG_FS
	struct page *page = NULL;
	int pcg_flag;

	if (likely(get_page_simulate_type == GET_PAGE_NO_SIMULATE))
		return pagecache_get_page(mapping, offset, fgp_flags, gfp_mask);
	switch (get_page_simulate_type) {
	case GET_PAGE_SIMULATE_ALWAYS_FAIL:
		return NULL;
	case GET_PAGE_SIMULATE_ALWAYS_SUCC:
		pcg_flag = fgp_flags | ((int)(FGP_CREAT | FGP_LOCK));
		if (!(fgp_flags & FGP_LOCK)) {
			page = pagecache_get_page(mapping, offset,
				pcg_flag, gfp_mask);
			if (page) {
				unlock_page(page);
				put_page(page);
			}
			return page;
		}
		pcg_flag = fgp_flags | ((int)(FGP_CREAT));
		return pagecache_get_page(mapping, offset,
				pcg_flag, gfp_mask);
	default:
		break;
	}
#endif
	return pagecache_get_page(mapping, offset, fgp_flags, gfp_mask);
}


/*
 * Function name: pch_shrink_read_pages
 * Discription: shrink generic read page size
 * Parameters:
 *      @ unsigned long nr
 * return value:
 *      @ ra_pages: the page size need to read
 */
unsigned long pch_shrink_read_pages(unsigned long nr)
{
	unsigned long ra_pages;

	if (!pch_info || !pch_info->func_enable)
		return min(nr, MAX_RA_PAGES);

	if (pch_info->readahead_ra_size < nr)
		ra_pages = pch_info->readaround_ra_size;
	else
		ra_pages = nr;

	if ((pch_lowmem_check() >= MEM_HIGH_WMARK) &&
			(pch_info->lowmem_ra_size < ra_pages))
		ra_pages = pch_info->lowmem_ra_size;

	return min(ra_pages, MAX_RA_PAGES);
}

/*
 * Function name: pch_shrink_mmap_pages
 * Discription: shrink mmap read page size
 * Parameters:
 *      @ unsigned long nr
 * return value:
 *      @ ra_pages: the page size need to read
 */
unsigned long pch_shrink_mmap_pages(unsigned long nr)
{
	unsigned long ra_pages;

	if (!pch_info || !pch_info->func_enable)
		return min(nr, MAX_RA_PAGES);

	if (pch_info->readaround_ra_size < nr)
		ra_pages = pch_info->readaround_ra_size;
	else
		ra_pages = nr;

	if ((pch_lowmem_check() >= MEM_HIGH_WMARK) &&
			(pch_info->lowmem_ra_size < ra_pages))
		ra_pages = pch_info->lowmem_ra_size;

	return min(ra_pages, MAX_RA_PAGES);
}

/*
 * Function name: pch_shrink_mmap_async_pages
 * Discription: shrink mmap async read page size
 * Parameters:
 *      @ unsigned long nr
 * return value:
 *      @ ra_pages: the page size need to read
 */
unsigned long pch_shrink_mmap_async_pages(unsigned long nr)
{
	unsigned long ra_pages;

	if (!pch_info || !pch_info->func_enable)
		return min(nr, MAX_RA_PAGES);

	if (pch_lowmem_check())
		ra_pages = 0;
	else
		ra_pages = nr;

	return ra_pages;
}

int pch_read_pages(struct address_space *mapping, struct file *filp,
		struct list_head *pages, unsigned int nr_pages, gfp_t gfp, struct readahead_control *rac, bool skip_page)
{
	struct blk_plug plug;
	unsigned page_idx;
	int ret = 0;

	if (!readahead_count(rac))
		goto skip;

	blk_start_plug(&plug);

	if (mapping->a_ops->mas_readahead) {
		ret = mapping->a_ops->mas_readahead(filp, mapping, pages, nr_pages, rac);
		/* Clean up the remaining pages */
		while (!list_empty(pages)) {
			struct page *victim;
			victim = lru_to_page(pages);
			list_del(&victim->lru);
			unlock_page(victim);
			put_page(victim);
			rac->_nr_pages--;
			rac->_index++;
		}
		goto out;
	}

	for (page_idx = 0; page_idx < nr_pages; page_idx++) {
		struct page *page = lru_to_page(pages);
		list_del(&page->lru);
		if (!add_to_page_cache_lru(page, mapping, page->index, gfp))
				mapping->a_ops->readpage(filp, page);
			put_page(page);
		rac->_index += rac->_nr_pages;
		rac->_nr_pages = 0;
	}
	ret = 0;

out:
	blk_finish_plug(&plug);
	BUG_ON(readahead_count(rac));
	BUG_ON(!list_empty(pages));
skip:
	if (skip_page)
		rac->_index++;
	return ret;
}

/*
 * Function name: pch_get_index_vip_first
 * Discription: get index by vip first
 * Parameters:
 *      @ int i: count
 *      @ int min, max: range is [min, max], closed interval
 *      @ int vip: Mr Alpha
 * return value:
 *      @ int: >= 0 for a index
 *             other means no index at this time
 */
static inline int pch_get_index_vip_first(int i, int min, int max, int vip)
{
	int ret;

	ret = vip + ((i % 2) ? (-(i + 1) / 2) : ((i + 1) / 2));

	if (ret < min)
		return -1;

	if (ret > max)
		return -1;

	return ret;
}

static void pch_reorder_io_list(unsigned long long *pg_idx_bm,
	int bm_count, struct list_head *page_tmp, struct list_head *page_pool,
	pgoff_t offset, struct readahead_control *ractl)
{
	unsigned int i;
	struct page *page = NULL;
	unsigned int start = 0;

	for (i = 0; i < (BITS_PER_LONG_LONG << 1); i++) {
		if ((i >> 6) > bm_count)
			return;

		if (pg_idx_bm[i >> 6] & (1ULL << (unsigned int)(i % 64))) {
			page = list_first_entry(page_tmp,
				struct page, lru);
			list_del(&page->lru);
			page->index = i + offset;
			if (start == 0)
				ractl->_index = page->index;
			start++;
			list_add(&page->lru, page_pool);
			if (list_empty(page_tmp))
				return;
		}
	}
}

/*
 * pch_do_page_cache_readaround actually reads a chunk of disk.
 * It allocates all the pages first, then submits them all for I/O.
 * This avoids the very bad behaviour which would occur
 * if page allocations are causing VM writeback.
 * We really don't want to intermingle reads and writes like that.
 *
 * vip_n for very important page No.
 *
 * Returns the number of pages requested, or the maximum amount of I/O allowed.
 */
static void pch_do_page_cache_readaround(struct readahead_control *ractl,
		struct file *filp, pgoff_t offset, unsigned long nr_to_read,
		unsigned long lookahead_size, unsigned long vip_n)
{
	struct address_space *mapping = ractl->mapping;
	struct inode *inode = mapping->host;
	struct page *page = NULL;
	unsigned long end_index; /* The last page we want to read */
	LIST_HEAD(page_tmp);
	LIST_HEAD(page_pool);
	int page_idx;
	unsigned long i;
	pgoff_t pgofs;
	unsigned int nofs;
	loff_t isize = i_size_read(inode);
	gfp_t gfp_mask = readahead_gfp_mask(mapping);
	unsigned long long pg_idx_bm[BIT_MAP_COUNT] = {0};
#ifdef CONFIG_FILE_MAP
	bool badpted = false;
	unsigned long old_nr_to_read = nr_to_read;
#endif
	/*
	 * If the number of read is greater than size of pg_idx_bm,
	 * the optimise of vip should be disabled.
	 */
	if (unlikely(nr_to_read >= (BITS_PER_LONG_LONG << 1)))
		vip_n = 0;

	if (unlikely(isize == 0))
		return;

	end_index = ((isize - 1) >> PAGE_SHIFT);

#ifdef CONFIG_FILE_MAP
	badpted = file_map_ra_adapt();
	if (badpted)
		nr_to_read = file_map_data_analysis(inode, offset,
					nr_to_read, end_index, true);
#endif
	/*
	 * Partway through the readahead operation, we will have added
	 * locked pages to the page cache, but will not yet have submitted
	 * them for I/O.  Adding another page may need to allocate memory,
	 * which can trigger memory reclaim.  Telling the VM we're in
	 * the middle of a filesystem operation will cause it to not
	 * touch file-backed pages, preventing a deadlock.  Most (all?)
	 * filesystems already specify __GFP_NOFS in their mapping's
	 * gfp_mask, but let's be explicit here.
	 */
	nofs = memalloc_nofs_save();

	/*
	 * Actually read count is dependent on the cache missed count
	 * and available page number.
	 * The sequence of page allocation is from center to two sides
	 */
	for (i = 0; i < (nr_to_read << 1); i++) {
		page_idx = pch_get_index_vip_first(i, 0,
			min_t(int, nr_to_read - 1, end_index - offset), vip_n);
		if (page_idx < 0)
			continue;

		pgofs = offset + page_idx;

#ifdef CONFIG_FILE_MAP
		if (badpted && (old_nr_to_read == nr_to_read) &&
			!file_map_is_set(inode, pgofs)) {
			file_map_stat_ignore_inc(1);
			continue;
		}
#endif
		page = xa_load(&mapping->i_pages, pgofs);
		if (page && !xa_is_value(page))
			continue;

		page = __page_cache_alloc(gfp_mask);
		if (unlikely(!page))
			break;

		if (likely(vip_n)) {
			pg_idx_bm[page_idx >> 6] |=
				1ULL << (unsigned int)(page_idx % 64);
				list_add(&page->lru, &page_tmp);
		} else {
			page->index = pgofs;
			list_add(&page->lru, &page_pool);
			if (page_idx == nr_to_read - lookahead_size)
				SetPageReadahead(page);
		}
		ractl->_nr_pages++;
	}

#ifdef CONFIG_FILE_MAP
	if (badpted)
		file_map_stat_total_inc((long)ractl->_nr_pages);
#endif

	/*
	 * Now start the IO.  We ignore I/O errors - if the page is not
	 * uptodate then the caller will launch readpage again, and
	 * will then handle the error.
	 */
	if (likely(ractl->_nr_pages)) {
		/*
		* Before we start the IO, we should reorder the io list
		* by the file offset
		*/
		if (likely(vip_n))
			pch_reorder_io_list(pg_idx_bm, BIT_MAP_COUNT,
				&page_tmp, &page_pool, offset, ractl);
		pch_read_pages(mapping, filp, &page_pool, ractl->_nr_pages, gfp_mask, ractl, false);
	}
#ifdef CONFIG_DFX_DEBUG_FS
	BUG_ON(!list_empty(&page_pool));
#endif
	memalloc_nofs_restore(nofs);
}

void pch_read_around(struct readahead_control *ractl,
				   struct file_ra_state *ra,
				   struct file *file,
				   pgoff_t offset)
{
	pgoff_t start;
	/* The unit of size is 4K page */
	unsigned long size;

	/* shrink pre-fetch size when low memory */
	size = pch_shrink_mmap_pages(ra->ra_pages);

	/* calculate start address */
	start = (pgoff_t)max_t(long, 0, offset - (size >> 1));

	ractl->_index = start;
	/* use temporary variable to avoid conflicts */
	pch_do_page_cache_readaround(ractl, file, start, size,
			0, offset - start);

	ra->start = start;
	ra->size = size;
}
#ifdef CONFIG_SPECULATIVE_PAGE_FAULT
static void __pch_mmap_readextend(unsigned long vm_flags,
				    struct file_ra_state *ra,
				    struct file *file,
				    pgoff_t offset,
				    int forward)
#else
static void __pch_mmap_readextend(struct vm_area_struct *vma,
				    struct file_ra_state *ra,
				    struct file *file,
				    pgoff_t offset,
				    int forward)
#endif
{
	struct address_space *mapping = file->f_mapping;
	struct inode *inode = mapping->host;
	loff_t isize = i_size_read(inode);
	pgoff_t end_index, pch_index;
	unsigned long req_size;
	DEFINE_READAHEAD(ractl, file, mapping, offset);

	if (isize <= 0)
		return;
	end_index = ((unsigned int)(isize - 1) >> PAGE_SHIFT);
	/* If we don't want any read-ahead, don't bother */
#ifdef CONFIG_SPECULATIVE_PAGE_FAULT
	if (vm_flags & VM_RAND_READ)
#else
	if (vma->vm_flags & VM_RAND_READ)
#endif
		return;
	if (!ra->ra_pages)
		return;
#ifdef CONFIG_SPECULATIVE_PAGE_FAULT
	if (vm_flags & VM_SEQ_READ)
#else
	if (vma->vm_flags & VM_SEQ_READ)
#endif
		return;

	/*
	 * Do we miss much more than hit in this file? If so,
	 * stop bothering with read-ahead. It will only hurt.
	 */
	if (ra->mmap_miss > MAX_MMAP_LOTSAMISS)
		return;

	/*
	 * Defer asynchronous read-ahead on IO congestion.
	 */
	if (inode_read_congested(mapping->host))
		return;
	/*
	 * As the extend readahead is after the sync readahead,
	 * we can't disable extend RA by check the PG_readahead.
	 * The page with PG_readahead has been checked or submitted
	 * by sync readahead just now.
	 * It should be exist, so we skip the readahead page check.
	 *
	 * When this function was called, the page which cause the
	 * filemap fault wasn't in cache, so it's unnecessary to move
	 * the readahead window according to the offset.
	 * We can set extend readahead window just as sync readahead.
	 */

	if (!forward) {
		/*
		 * Check if the sync read window include the file start pos
		 * If yes, unnecessary do extend readahead.
		 */
		pch_index = (pgoff_t)max_t(long, 0, offset - ra->size / 2);
		if (pch_index == 0)
			return;

		/*
		 * Check if the extend async read window
		 * include the file start pos or not
		 */
		pch_index = (pgoff_t)max_t(
			long, 0, offset - pch_info->readextend_ra_size);
		/*
		 * If yes, we read all from start of the file
		 * If no, we set extend async read window as expected
		 */
		if (pch_index == 0)
			req_size = offset;
		else
			req_size = pch_info->readextend_ra_size - ra->size / 2;

		ractl._index = pch_index;
		do_page_cache_ra(&ractl, req_size, 0);
	} else {
		/*
		 * Check if the sync read window include the file end pos or not
		 * If yes, unnecessary do extend readahead.
		 */
		pch_index =
			(pgoff_t)min_t(long, end_index, offset + ra->size / 2);
		if (pch_index == end_index)
			return;
		/*
		 * We don't check the file end condition, because
		 * __do_page_cache_readahead will help us do it!
		 * We can just set window and read it directly.
		 */
		pch_index = offset + ra->size / 2;
		ractl._index = pch_index;
		do_page_cache_ra(&ractl, pch_info->readaround_ra_size, 0);
	}
}

/*
 * Function name: pch_mmap_readextend
 * Discription: mmap extend read flow
 * Parameters:
 *      @ struct vm_area_struct
 *      @ struct file_ra_state
 *      @ struct file
 *      @ pgoff_t offset
 * return value:
 *      @ NULL
 */
#ifdef CONFIG_SPECULATIVE_PAGE_FAULT
void pch_mmap_readextend(unsigned long vm_flags,
				    struct file_ra_state *ra,
				    struct file *file,
				    pgoff_t offset)
#else
void pch_mmap_readextend(struct vm_area_struct *vma,
				    struct file_ra_state *ra,
				    struct file *file,
				    pgoff_t offset)
#endif
{
	if (!pch_info || !pch_info->func_enable)
		return;

	/*
	 * if lowmem status, no extend read
	 */
	if (pch_lowmem_check())
		return;
#ifdef CONFIG_SPECULATIVE_PAGE_FAULT
	__pch_mmap_readextend(vm_flags, ra, file, offset, 1);
#else
	__pch_mmap_readextend(vma, ra, file, offset, 1);
#endif
}

/**
 * timer_work_in_progress - determine whether there is timer work in progress
 *
 * Determine whether there is work waiting to be handled.
 */
static inline bool timer_work_in_progress(void)
{
	return test_bit(TIMER_WORK_IS_RUNING, &pch_info->timer_work_state);
}

/*
 * Function name: pch_user_statfs
 * Discription: get user volume size
 * Parameters:
 *      @ NULL
 * return value:
 *      @ 1: user volume size is low
 *      @ 0: user volume size is high
 *      @ other: error failed
 */
static int pch_user_statfs(void)
{
	char *data = "/data";
	struct kstatfs st;
	struct path path;
	int error;
	unsigned int lookup_flags = LOOKUP_FOLLOW | LOOKUP_AUTOMOUNT;
	unsigned int ratio, ret;

	memset(&st, 0, sizeof(st)); /* unsafe_function_ignore: memset */

	error = kern_path(data, lookup_flags, &path);
	if (!error) {
		error = vfs_statfs(&path, &st);
		path_put(&path);
	}

	if  (error)
		return error;

	ratio = (int) ((st.f_bavail * (u64)BAVAIL_RATION) / st.f_blocks);
	if  ((ratio <= pch_info->lowstorage_ratio) &&
			(st.f_bavail <= STORAGE_IS_1G))
		ret = USER_SPACE_IS_LOW;
	else
		ret = USER_SPACE_IS_HIGH;

	return ret;
}

void pch_timeout_work(struct work_struct *work)
{
	struct super_block *sb = NULL;
	struct backing_dev_info *bdi = NULL;
	struct bdi_writeback *wb = NULL;
	unsigned long background_thresh;
	unsigned long dirty_thresh;
	unsigned long nr_dirty;
	int userdata_state;

	down(&pch_info->work_sem);
	set_bit(TIMER_WORK_IS_RUNING, &pch_info->timer_work_state);

	if (!is_userdata_mounted()) {
		clear_bit(TIMER_WORK_IS_RUNING, &pch_info->timer_work_state);
		up(&pch_info->work_sem);
		return;
	}

	sb = pch_info->bdev->bd_super;
	bdi = sb->s_bdi;
	wb = &bdi->wb;

	userdata_state = pch_user_statfs();
	if (userdata_state == USER_SPACE_IS_LOW) {
		pch_info->readaround_ra_size = lowstorage_ra_size;
		pch_info->readahead_ra_size = lowstorage_ra_size;
		pch_info->readextend_ra_size = lowstorage_extend_size;
	} else if (userdata_state == USER_SPACE_IS_HIGH) {
		pch_info->readextend_ra_size = extend_ra_size;
		if (pch_info->boot_device == BOOT_DEVICE_EMMC) {
			pch_info->readahead_ra_size = emmc_ra_ahead_size;
			pch_info->readaround_ra_size = emmc_ra_round_size;
		} else if (pch_info->boot_device  == BOOT_DEVICE_UFS) {
			pch_info->readahead_ra_size = ufs_ra_ahead_size;
			pch_info->readaround_ra_size = ufs_ra_round_size;
		}
	} else {
		pch_print(LOG_LEVEL_ERROR, "%s: err userdata_state = %d.\n", __func__, userdata_state);
	}

	global_dirty_limits(&background_thresh, &dirty_thresh);

	nr_dirty = global_node_page_state(NR_FILE_DIRTY) +
				global_node_page_state(NR_WRITEBACK);
	if (nr_dirty < dirty_thresh) {
		clear_bit(TIMER_WORK_IS_RUNING, &pch_info->timer_work_state);
		up(&pch_info->work_sem);
		return;
	}

	if (!wb) {
		clear_bit(TIMER_WORK_IS_RUNING, &pch_info->timer_work_state);
		up(&pch_info->work_sem);
		return;
	}

	if (unlikely(!writeback_in_progress(wb)))
		wb_start_background_writeback(wb);

	clear_bit(TIMER_WORK_IS_RUNING, &pch_info->timer_work_state);
	up(&pch_info->work_sem);
}

void pch_timeout_timer(struct timer_list *timer)
{
	if (!timer_work_in_progress())
		schedule_work(&pch_info->timeout_work);
}

#ifdef CONFIG_MAS_BLK
/*
 * Function name: pch_io_idle_notify_handler
 * Discription: blk busy/idle event notify handler
 * Parameters:
 *      @ struct blk_busyidle_nb
 *      @ enum blk_idle_notify_state
 * return value:
 *      @ BUSYIDLE_NO_IO
 *      @ BUSYIDLE_IO_TRIGGERED
 *      @ other: failed
 */
static enum blk_busyidle_callback_ret pch_io_idle_notify_handler(
		struct blk_busyidle_event_node *nb, enum blk_idle_notify_state state)
{
	if (state == BLK_IDLE_NOTIFY)
		mod_timer(&pch_info->timer, jiffies + msecs_to_jiffies(5000));
	else if (state == BLK_BUSY_NOTIFY)
		del_timer(&pch_info->timer);

	return BUSYIDLE_NO_IO;
}
#endif

/*
 * Function name: mount_fs_register_pch
 * Discription: register blk busy/idle event
 *		    when fs is mounted
 * Parameters:
 *      @ struct path
 * return value:
 *      @ NULL
 */
void mount_fs_register_pch(struct vfsmount *mnt)
{
	struct super_block *sb = mnt->mnt_sb;
#ifdef CONFIG_MAS_BLK
	int ret = 0;
#endif
	if (!pch_info) {
		pch_print(LOG_LEVEL_WARNING, "%s: lack of pch_info, return.\n",
			__func__);
		return;
	}

	if (sb->s_magic == F2FS_SUPER_MAGIC) {
		if (is_userdata_umounted()) {
			clear_userdata_umounted();
			set_userdata_mounted();
		} else {
			pch_print(LOG_LEVEL_INFO,
				"%s: data remount, return.\n", __func__);
			return;
		}
	} else {
		pch_print(LOG_LEVEL_INFO,
				"%s: other partitions, return.\n", __func__);
		return;
	}

	if (is_userdata_mounted()) {
		if (pch_info->bdev)
			return;

		if (!sb->s_bdev)
			return;

		pch_info->bdev = sb->s_bdev;
#ifdef CONFIG_MAS_BLK
		pch_info->event_node.busyidle_callback = pch_io_idle_notify_handler;
		if (sizeof(pch_info->event_node.subscriber) <= strlen(PCH_DEV_NAME)) {
			pch_print(LOG_LEVEL_ERROR,
				"%s: subscriber length is too small\n", __func__);
			return;
		}

		strncpy(pch_info->event_node.subscriber, PCH_DEV_NAME, strlen(PCH_DEV_NAME));
		ret = blk_busyidle_event_subscribe(
				pch_info->bdev, &pch_info->event_node);
		if (ret)
			pch_print(LOG_LEVEL_ERROR, "%s: blk busy/idle init failed.\n", __func__);
#endif
	}
}

/*
 * Function name: umounting_fs_register_pch
 * Discription: unregister blk busy/idle event
 *		    when fs unmount
 * Parameters:
 *      @ struct super_block
 * return value:
 *      @ NULL
 */
void umounting_fs_register_pch(struct super_block *sb)
{
#ifdef CONFIG_MAS_BLK
	int ret = 0;
#endif
	if (!pch_info) {
		pch_print(LOG_LEVEL_WARNING,
			"%s: lack of pch_info, return.\n",
			__func__);
		return;
	}

	if (sb->s_magic == F2FS_SUPER_MAGIC) {
		if (is_userdata_mounted()) {
			clear_userdata_mounted();
			set_userdata_umounting();

			if (pch_info->bdev) {
				del_timer_sync(&pch_info->timer);
				flush_work(&pch_info->timeout_work);
#ifdef CONFIG_MAS_BLK
				down(&pch_info->work_sem);
				ret = blk_busyidle_event_unsubscribe(&pch_info->event_node);
				if (ret) {
					pch_print(LOG_LEVEL_ERROR, "%s: blk busy/idle clear failed.\n", __func__);
					up(&pch_info->work_sem);
					return;
				}
				up(&pch_info->work_sem);
#endif
			}
		} else {
			pch_print(LOG_LEVEL_INFO,
				"%s: data re-umount, return.\n", __func__);
			return;
		}
	} else {
		pch_print(LOG_LEVEL_INFO,
				"%s: other partitions, return.\n", __func__);
		return;
	}
}

/*
 * Function name: umounted_fs_register_pch
 * Discription: unregister blk busy/idle event
 * Parameters:
 *      @ struct super_block
 * return value:
 *      @ NULL
 */
void umounted_fs_register_pch(struct super_block *sb)
{
	if (sb->s_magic == F2FS_SUPER_MAGIC) {
		if (is_userdata_umounting()) {
			clear_userdata_umounting();
			set_userdata_umounted();
		} else {
			pch_print(LOG_LEVEL_INFO,
				"%s: data remount, return.\n", __func__);
			return;
		}
	} else {
		pch_print(LOG_LEVEL_INFO,
				"%s: other partitions, return.\n", __func__);
		return;
	}
}

/* optimize write-back */
/* pgae lru-list reintegration */

/*
 * Function name:pch_ioctl.
 * Discription:complement get usr info.
 * return value:
 *          @ 0 - success.
 *          @ -1- failure.
 */
#ifdef CONFIG_DFX_DEBUG_FS
static long pch_ioctl(struct file *file, u_int cmd, u_long arg)
{
	pch_print(LOG_LEVEL_INFO, "%s: %d: cmd=0x%x.\n", __func__, __LINE__, cmd);

	switch (cmd) {
	case PCH_IOCTL_CMD_Z:
		break;
	case PCH_IOCTL_CMD_O:
		break;
	default:
		break;
	}

	return 0;
}

static const struct file_operations pch_fops = {
	.owner          = THIS_MODULE,
	.unlocked_ioctl = pch_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = pch_ioctl,
#endif
};
#endif

int pch_emui_bootstat_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%d\n", pch_info->func_enable);
	return 0;
}

int pch_emui_bootstat_proc_open(struct inode *p_inode,
		struct file *p_file)
{
	return single_open(p_file, __cfi_pch_emui_bootstat_proc_show, NULL);
}

ssize_t pch_emui_bootstat_proc_write(struct file *p_file,
		const char __user *userbuf, size_t count, loff_t *ppos)
{
	char buf;
	char getvalue;

	if (pch_info->func_enable == 1)
		return -1;

	if (count == 0)
		return -1;

	if (!userbuf)
		return -1;

	if (copy_from_user(&buf, userbuf, sizeof(char)))
		return -1;

	getvalue = buf - 48;

	if (getvalue != 1) {
		pch_print(LOG_LEVEL_ERROR, "%s: input error.\n", __func__);
		return -1;
	}

	pch_info->func_enable = 1;
	page_cache_func_enable = 1;

	return (ssize_t)count;
}

static const struct proc_ops pch_emui_boot_done_fops = {
	.proc_open		= __cfi_pch_emui_bootstat_proc_open,
	.proc_read		= seq_read,
	.proc_write		= __cfi_pch_emui_bootstat_proc_write,
	.proc_lseek		= seq_lseek,
	.proc_release	= single_release,
};

static void pch_emui_boot_check_init(void)
{
	if (!proc_mkdir("pch_status", NULL)) {
		pch_print(LOG_LEVEL_ERROR, "%s: proc mk error.\n", __func__);
		return;
	}

	proc_create("pch_status/pch_enabled", 0660,
		 (struct proc_dir_entry *)NULL, &pch_emui_boot_done_fops);
}

/*
 * Function name: hisi_page_cache_manage_init
 * Discription: hisi page cache module init
 * Parameters:
 *      @ NULL
 * return value:
 *      @ 0: init succeed
 *      @ other: init failed
 */
int __init hisi_page_cache_manage_init(void)
{
	int ret = 0;
	enum bootdevice_type boot_device_type;
#ifdef CONFIG_DFX_DEBUG_FS
	int major = 0;
	struct class *pch_class = NULL;
	struct device *pch_device = NULL;
#endif

	pch_print(LOG_LEVEL_INFO, "%s: module init ++.\n", __func__);

	pch_info = kzalloc(sizeof(struct pch_info_desc), GFP_KERNEL);
	if (!pch_info)
		return -ENOMEM;

	pch_info->func_enable = page_cache_func_enable;
	pch_info->lowmem_ra_size = lowmem_ra_size;
	pch_info->readextend_ra_size = extend_ra_size;
	pch_info->lowstorage_ratio = lowstorage_ratio;
	pch_info->fs_mount_stat = 0;
	boot_device_type = get_bootdevice_type();
	if (boot_device_type == BOOT_DEVICE_EMMC) {
		pch_info->boot_device = BOOT_DEVICE_EMMC;
		pch_info->readahead_ra_size = emmc_ra_ahead_size;
		pch_info->readaround_ra_size = emmc_ra_round_size;
	} else if (boot_device_type == BOOT_DEVICE_UFS) {
		pch_info->boot_device = BOOT_DEVICE_UFS;
		pch_info->readahead_ra_size = ufs_ra_ahead_size;
		pch_info->readaround_ra_size = ufs_ra_round_size;
	} else {
		pch_print(LOG_LEVEL_ERROR,
				"%s: device not supported.\n", __func__);
		ret = -1;
		goto pch_kfree;
	}

#ifdef CONFIG_DFX_DEBUG_FS
	/*
	 * creat a debug fs node in proc/sys/page_cache
	 */
	pch_table_header = register_sysctl_table(pch_root_table);
	if (!pch_table_header) {
		pch_print(LOG_LEVEL_ERROR,
				"%s: sysctl register fail.\n", __func__);
		ret = -ENOMEM;
		goto pch_kfree;
	}

	/*
	 * creat a char dev in sys/class/pagecache_helper
	 */
	major = register_chrdev(0, PCH_DEV_NAME, &pch_fops);
	if (major <= 0) {
		pch_print(LOG_LEVEL_ERROR,
				"%s: unable to get major dev.\n", __func__);
		ret = -EFAULT;
		goto register_chrdev_error;
	}

	pch_class = class_create(THIS_MODULE, PCH_DEV_NAME);
	if (IS_ERR(pch_class)) {
		pch_print(LOG_LEVEL_ERROR,
				"%s: class_create error.\n", __func__);
		ret = -EFAULT;
		goto class_create_error;
	}

	pch_device = device_create(pch_class, NULL,
			MKDEV((unsigned int)major, 0), NULL, PCH_DEV_NAME);
	if (IS_ERR(pch_device)) {
		pch_print(LOG_LEVEL_ERROR,
				"%s: pdev_create error.\n", __func__);
		ret = -EFAULT;
		goto device_create_error;
	}
#endif

	pch_emui_boot_check_init();
	timer_setup(&pch_info->timer, __cfi_pch_timeout_timer, 0);
	/* Initialize work queues */
	INIT_WORK(&pch_info->timeout_work, __cfi_pch_timeout_work);
	sema_init(&pch_info->work_sem, 1);

	set_userdata_umounted();

	pch_print(LOG_LEVEL_INFO, "%s: module init --.\n", __func__);

	return ret;

#ifdef CONFIG_DFX_DEBUG_FS
device_create_error:
	class_destroy(pch_class);
class_create_error:
	unregister_chrdev(major, PCH_DEV_NAME);
register_chrdev_error:
	unregister_sysctl_table(pch_table_header);
#endif
pch_kfree:
	kfree(pch_info);
	pch_info = NULL;

	return ret;
}

/*
 * Function name: hisi_page_cache_manage_exit
 * Discription: hisi page cache  module exit
 * Parameters:
 *      @ NULL
 * return value:
 *      @ NULL
 */
void __exit hisi_page_cache_manage_exit(void)
{
	pch_print(LOG_LEVEL_INFO, "%s: module exit ++.\n", __func__);

	remove_proc_entry("pch_status/pch_enabled", NULL);
	remove_proc_entry("pch_status", NULL);

#ifdef CONFIG_DFX_DEBUG_FS
	unregister_sysctl_table(pch_table_header);
#endif
	kfree(pch_info);
	pch_info = NULL;
	pch_print(LOG_LEVEL_INFO, "%s: module exit --.\n", __func__);
}

module_init(__cfi_hisi_page_cache_manage_init)
module_exit(__cfi_hisi_page_cache_manage_exit)

MODULE_DESCRIPTION("Flash Friendly Page Cache Evo-System");
MODULE_LICENSE("GPL");
