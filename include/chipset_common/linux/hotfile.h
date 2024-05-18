/*
 * Copyright (c) Honor Technologies Co., Ltd. 2022. All rights reserved.
 * Description: According to file statistics, select and protect hot files.
 * Created by lipeng
 */

#ifndef _HOT_FILE_H
#define _HOT_FILE_H

#include <linux/types.h>
#include <linux/mutex.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/list_bl.h>

typedef u32 block_t;
typedef u32 nid_t;

#define NR_PAGE_TYPE                    3
#define HF_STAT_ENABLE			0x00000001 //start or stop the feature
#define HF_SYS_STAT				0x00000002 //enable system file stat
#define HF_APP_STAT				0x00000004 //enable app file stat
#define HF_SET_AUTO				0x00000008 //set protect file flag when stat

#define HF_GET_FLAG(v, flag)	((v) & (flag))
#define HF_SET_FLAG(v, flag)	((v) |= (flag))
#define HF_CLR_FLAG(v, flag)	((v) &= ~(flag))
#define HF_IS_ENABLE(v, flag)	(((v) & (flag)) ? 1 : 0)

#define HF_HOT_SIZE_MAX_DEF		1000 //MB
#define HF_HOT_MIN_FSIZE_DEF	16 //KB
#define HF_HOT_WEIGHT(m, n)		((n) ? ((m) * 100 / (n)) : 0)
#define HF_HOT_WEIGHT_MIN_INIT	0xFFFFFFFF
#define HF_HOT_WEIGHT_DEF		HF_HOT_WEIGHT(10, 1)
#define HF_HOT_WEIGHT_TO_TRH(m)	((m) / 100)
#define HF_HOT_TRH_TO_WEIGHT(m)	HF_HOT_WEIGHT(m, 1)

#define HF_HOT_PROC_DIR			"fs/hotfile"
#define HF_HOT_PROC_SYS_FLIST	"fs/hotfile/file_sys_list"
#define HF_HOT_PROC_APP_FLIST	"fs/hotfile/file_app_list"
#define HF_HOT_PROC_SYS_FN_LIST	"fs/hotfile/file_name_sys_list"
#define HF_HOT_PROC_APP_FN_LIST	"fs/hotfile/file_name_app_list"

#define HF_SIZE_IN_PAGE(n)		(((n) + PAGE_SIZE - 1) >> PAGE_SHIFT)
#define HF_MB_TO_PAGE(n)		((n) << 8)
#define HF_PAGE_TO_MB(n)		((n) >> 8)
#define HF_KB_TO_PAGE(n)		(((n) + 3) >> 2)
#define HF_PAGE_TO_KB(n)		((n) << 2)

#define HF_HASH_BUCKET_NUM		0x4000
#define HF_HASH_KEY(val)		((val) & (HF_HASH_BUCKET_NUM - 1))
#define HF_HASH_LIST_LEN_MAX	200
#define HF_EROFS_SUPER_MAGIC	0xE0F5E1E2
#define HF_F2FS_SUPER_MAGIC		F2FS_SUPER_MAGIC
#define HF_MODE_RO				0440
#define HF_MODE_WO				0220
#define HF_MODE_RW				0660

#define HF_CMD_STR_MAX_LEN		10
#define HF_PROTECT_CMD_SET		1
#define HF_PROTECT_CMD_CLR		2
#define HF_PROTECT_FLAG_SYS		0x01
#define HF_PROTECT_FLAG_APP		0x02
#define HF_PROTECT_LEVELS_SYS	1
#define HF_PROTECT_LEVELS_APP	2

#define HF_ATTR(_name, _mode, _show, _store) \
	static struct kobj_attribute kobj_attr_##_name =\
	__ATTR(_name, _mode, _show, _store)

#define hf_pr_info(fmt, arg...) pr_info("[hotfile] %s,"fmt, __func__, ##arg)

enum hf_area_type {
	HF_SYS,
	HF_APP,
	HF_CNT
};

struct hf_inode {
	union {
		struct hlist_bl_node hlist;
		struct list_head list;
	};
	u32 ino;
	u32 dev;
	u32 count; //access count in page
	u32 size:24; //file size in page
	u32 type:8; //system file or application file
};

struct hf_hot {
	struct list_head hot_head; //hot file list
	u32 cfg_limit; //max size of hot files in page
	u32 cfg_weight; //the threshold value of hot files
	u32 cfg_min_fsize; //min file size in page
	u32 file_cnt; //file count
	u32 size_sum; //size of all files, in page
	u32 min_weight; //min weight in all hot files
};

struct hotfile_stat {
	u32 enable_flag; //status of file stat
	u32 list_len_max; //max list len in all hlist
	struct mutex cmd_mutex; //command process lock
	struct kmem_cache *inode_cachep;
	struct kobject *io_dir;
	struct hlist_bl_head *inode_hash;
	struct hf_hot hot[HF_CNT];
};

#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
struct hotfile_debug {
	atomic_t kmem_alloc_cnt;
	atomic_t kmem_alloc_fail;
	atomic_t inode_del_cnt;
	atomic_t inode_protect_set_cnt;
	atomic_t inode_protect_clr_cnt;
	u32 other_alloc_fail;
	u32 inode_protect_fail;
	u32 inode_get_fs_fail;
	u32 critical_err;
	u64 time_all_ns;
	u64 time_add_count;
	u64 time_max_ns;
};
struct hotfile_debug hf_debug;
#endif

extern struct hotfile_stat hf_stat;
extern struct inode *hf_get_inode(u32, u32);
#endif /* _HOT_FILE_H */
