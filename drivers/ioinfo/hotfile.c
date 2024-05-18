/*
 * Copyright (c) Honor Technologies Co., Ltd. 2022. All rights reserved.
 * Description: According to file statistics, select and protect hot files.
 * Created by lipeng
 */
#include <linux/hotfile.h>
#include <trace/events/f2fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/tracepoint.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/namei.h>
#include <linux/mount.h>
#include <linux/path.h>
#include <trace/events/filemap.h>
#include <trace/events/android_fs.h>
#include <linux/blk-cgroup.h>

struct hotfile_stat hf_stat;
EXPORT_SYMBOL(hf_stat);

extern struct inode *ilookup(struct super_block *sb, unsigned long ino);

static inline struct hf_inode *hf_alloc_node(bool hnode_flag)
{
	struct hf_inode *node = kmem_cache_alloc(hf_stat.inode_cachep, GFP_ATOMIC);

	if (node) {
		if (hnode_flag)
			INIT_HLIST_BL_NODE(&node->hlist);
		else
			INIT_LIST_HEAD(&node->list);
	}
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	if (node)
		atomic_inc(&hf_debug.kmem_alloc_cnt);
	else
		atomic_inc(&hf_debug.kmem_alloc_fail);
#endif
	return node;
}

static inline void hf_free_node(struct hf_inode *node)
{
	kmem_cache_free(hf_stat.inode_cachep, node);
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	atomic_dec(&hf_debug.kmem_alloc_cnt);
#endif
}

static inline void hf_add_node(struct hlist_bl_head *head, struct hf_inode *node)
{
	hlist_bl_add_head(&node->hlist, head);
}

static inline struct hf_inode *hf_get_node(struct hlist_bl_head *head,
	u32 ino, u32 dev, u32 *list_len)
{
	struct hf_inode *node = NULL;
	struct hlist_bl_node *pos = NULL;
	u32 count = 0;

	hlist_bl_for_each_entry(node, pos, head, hlist) {
		count++;
		if ((node->ino == ino) && (node->dev == dev))
			return node;
	}
	if (list_len)
		*list_len = count;
	return NULL;
}

/*
 * Set protect flag for the hot file
 * @inode: hot file's inode.
 * @type: sys or app file, for fitting the correct level
 */
static inline void hf_set_protect_file(struct inode *inode, u32 type)
{
#if defined(CONFIG_TASK_PROTECT_LRU) || defined(CONFIG_MEMCG_PROTECT_LRU)
	if (!inode)
		return;
	if (type == HF_SYS)
		inode->i_protect = HF_PROTECT_LEVELS_SYS;
	else if (type == HF_APP)
		inode->i_protect = HF_PROTECT_LEVELS_APP;
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	hf_pr_info("ino:%lu, level:%d\n", inode->i_ino, inode->i_protect);
	atomic_inc(&hf_debug.inode_protect_set_cnt);
#endif
#endif
}

static inline void hf_clr_protect_file(struct inode *inode)
{
#if defined(CONFIG_TASK_PROTECT_LRU) || defined(CONFIG_MEMCG_PROTECT_LRU)
	if (!inode)
		return;
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	hf_pr_info("ino:%lu, old level:%d\n", inode->i_ino, inode->i_protect);
	atomic_inc(&hf_debug.inode_protect_clr_cnt);
#endif
	inode->i_protect = 0;
#endif
}

/*
 * Record the page access information
 * Stat page access by file/inode in hlist
 */
static void hf_page_access_record(void *ignore, struct page *page)
{
	struct hotfile_stat *hf = &hf_stat;
	struct inode *inode = NULL;
	struct hf_inode *node = NULL;
	struct hlist_bl_head *head = NULL;
	u32 ino;
	u32 dev;
	u32 size;
	u32 type;
	u32 list_len = 0;
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	u64 start_ns = ktime_get_ns();
	u64 now_ns;
	u64 delta;
#endif

	if (!page || !page->mapping || !page->mapping->host)
		return;
	if (hf->list_len_max >= HF_HASH_LIST_LEN_MAX)
		return;

	inode = page->mapping->host;
	if (!S_ISREG(inode->i_mode))
		return;
	if (!inode->i_sb)
		return;

	if (!HF_GET_FLAG(hf->enable_flag, HF_STAT_ENABLE))
		return;

	if (HF_GET_FLAG(hf->enable_flag, HF_SYS_STAT) &&
		(inode->i_sb->s_magic == HF_EROFS_SUPER_MAGIC)) {
		type = HF_SYS;
	} else if (HF_GET_FLAG(hf->enable_flag, HF_APP_STAT) &&
		(inode->i_sb->s_magic == HF_F2FS_SUPER_MAGIC)) {
#ifdef CONFIG_BLK_CGROUP_IOSMART
		if (!blk_is_topio())
			return;
#endif
		type = HF_APP;
	} else {
		return;
	}

	ino = (u32)inode->i_ino;
	dev = (u32)inode->i_sb->s_dev;
	size = (u32)HF_SIZE_IN_PAGE(inode->i_size);
	//search ino in hash table
	head = &hf->inode_hash[HF_HASH_KEY(ino)];
	hlist_bl_lock(head);
	node = hf_get_node(head, ino, dev, &list_len);
	if (!node) {
		//creat and add hf_inode to hash table
		node = hf_alloc_node(true);
		if (node) {
			node->ino = ino;
			node->dev = dev;
			node->count = 1;
			node->size = size;
			node->type = type;
			hf_add_node(head, node);
			list_len++;
		}
		if (list_len > hf->list_len_max)
			hf->list_len_max = list_len;
	} else {
		node->count++; //update access info
		if ((type == HF_APP) && (node->size != size))
			node->size = size;
		if (HF_GET_FLAG(hf->enable_flag, HF_SET_AUTO)) {
			if (HF_HOT_WEIGHT(node->count, node->size) > hf->hot[type].cfg_weight)
				hf_set_protect_file(inode, type);
		}
	}
	hlist_bl_unlock(head);
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	now_ns = ktime_get_ns();
	if (now_ns > start_ns) {
		delta = now_ns - start_ns;
		hf_debug.time_all_ns += delta;
		hf_debug.time_add_count++;
		if (hf_debug.time_max_ns < delta)
			hf_debug.time_max_ns = delta;
	}
#endif
}

/*
 * inode delete from fs
 */
static void hf_f2fs_delete_inode(struct inode *inode, u32 unlink_flag)
{
	struct hotfile_stat *hf = &hf_stat;
	struct hf_inode *node = NULL;
	struct hlist_bl_head *head = NULL;
	static u32 unlink_ino;
	u32 ino;
	u32 dev;

	if (!inode || !inode->i_sb)
		return;
	if (inode->i_nlink)
		return;
	if (!S_ISREG(inode->i_mode))
		return;
	if (!HF_GET_FLAG(hf->enable_flag, HF_STAT_ENABLE))
		return;

	ino = (u32)inode->i_ino;
	if (unlink_flag) {
		unlink_ino = ino;
	} else {
		if (unlink_ino == ino)
			return;
	}
	dev = (u32)inode->i_sb->s_dev;
	head = &hf->inode_hash[HF_HASH_KEY(ino)];
	hlist_bl_lock(head);
	node = hf_get_node(head, ino, dev, NULL);
	if (node) {
		hlist_bl_del(&node->hlist);
		hf_free_node(node);
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
		atomic_inc(&hf_debug.inode_del_cnt);
#endif
	}
	hlist_bl_unlock(head);
}

static void hf_f2fs_unlink_process(void *ignore, struct inode *inode, int ret)
{
	hf_f2fs_delete_inode(inode, 1);
}

static void hf_f2fs_truncate_process(void *ignore, struct inode *inode)
{
	hf_f2fs_delete_inode(inode, 0);
}

/*
 * Add the file to hot file list when it's a hot file
 * @node: file node
 */
static void hf_add_hot_files(struct hf_inode *node)
{
	struct hf_hot *hot = NULL;
	struct hf_inode *hot_node = NULL;
	struct hf_inode *cur_node = NULL;
	struct list_head *pos = NULL;
	struct list_head *tmp = NULL;
	u32 weight;
	u32 cur_weight;

#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	if (!node || (node->type >= HF_CNT))
		WARN_ON(1);
#else
	if (!node || (node->type >= HF_CNT))
		return;
#endif

	hot = &hf_stat.hot[node->type];
	if (node->size < hot->cfg_min_fsize)
		return;

	weight = HF_HOT_WEIGHT(node->count, node->size);
	if ((hot->size_sum >= hot->cfg_limit) && (weight <= hot->min_weight))
		return;

	//creat new hot node
	hot_node = hf_alloc_node(false);
	if (!hot_node)
		return;
	hot_node->ino = node->ino;
	hot_node->dev = node->dev;
	hot_node->count = node->count;
	hot_node->size = node->size;
	hot_node->type = node->type;

	//add hot node to list
	if (weight <= hot->min_weight) {
		list_add_tail(&hot_node->list, &hot->hot_head);
		hot->min_weight = weight;
	} else {
		list_for_each(pos, &hot->hot_head) {
			cur_node = list_entry(pos, struct hf_inode, list);
			cur_weight = HF_HOT_WEIGHT(cur_node->count, cur_node->size);
			if (weight > cur_weight) {
				list_add_tail(&hot_node->list, &cur_node->list);
				break;
			}
		}
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
		if (pos == &hot->hot_head) {
			hf_debug.critical_err++;
			hf_free_node(hot_node);
			return;
		}
#endif
	}
	hot->size_sum += hot_node->size;
	hot->file_cnt++;
	if (hot->size_sum <= hot->cfg_limit)
		return;

	//delete oversize node from list
	list_for_each_prev_safe(pos, tmp, &hot->hot_head) {
		cur_node = list_entry(pos, struct hf_inode, list);
		if (hot->size_sum - cur_node->size >= hot->cfg_limit) {
			hot->size_sum -= cur_node->size;
			hot->file_cnt--;
			list_del(&cur_node->list);
			hf_free_node(cur_node);
		} else {
			hot->min_weight = HF_HOT_WEIGHT(cur_node->count, cur_node->size);
			break;
		}
	}
}

/*
 * Release previous hot files resources
 * @hot: hot file information
 */
static void hf_reset_hot_files(struct hf_hot *hot)
{
	struct hf_inode *cur_node = NULL;
	struct list_head *pos = NULL;
	struct list_head *tmp = NULL;

	list_for_each_safe(pos, tmp, &hot->hot_head) {
		cur_node = list_entry(pos, struct hf_inode, list);
		list_del(&cur_node->list);
		hf_free_node(cur_node);
	}
	hot->file_cnt = 0;
	hot->size_sum = 0;
	hot->min_weight = HF_HOT_WEIGHT_MIN_INIT;
}

/*
 * Search hot files in all stats files
 */
static void hf_search_hot_files(void)
{
	struct hotfile_stat *hf = &hf_stat;
	struct hf_inode *node = NULL;
	struct hlist_bl_node *pos = NULL;
	struct hlist_bl_head *head = NULL;
	int i;

	hf_reset_hot_files(&hf->hot[HF_SYS]);
	hf_reset_hot_files(&hf->hot[HF_APP]);
	for (i = 0; i < HF_HASH_BUCKET_NUM; i++) {
		head = &hf->inode_hash[i];
		hlist_bl_lock(head);
		if (hlist_bl_empty(head)) {
			hlist_bl_unlock(head);
			continue;
		}
		hlist_bl_for_each_entry(node, pos, head, hlist) {
			hf_add_hot_files(node);
		}
		hlist_bl_unlock(head);
	}
}

/*
 * Start statistics file access information
 */
static void hf_stat_start(void)
{
	struct hotfile_stat *hf = &hf_stat;
	int ret = 0;
	int i;

	hf_pr_info("Hot file stat enable.");
	if (HF_GET_FLAG(hf->enable_flag, HF_STAT_ENABLE))
		return;

	//init hash table
	if (hf->inode_hash)
		return;
	hf->inode_hash = kvmalloc(sizeof(struct hlist_bl_head) * HF_HASH_BUCKET_NUM,
		GFP_KERNEL);
	if (!hf->inode_hash) {
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
		hf_debug.other_alloc_fail++;
#endif
		return;
	}
	for (i = 0; i < HF_HASH_BUCKET_NUM; i++)
		INIT_HLIST_BL_HEAD(&hf->inode_hash[i]);
	hf->list_len_max = 0;

	//register tracepoint
	ret = register_trace_mm_filemap_add_to_page_cache(hf_page_access_record, NULL);
	if (ret)
		hf_pr_info("ERR: register add_to_page_cache tracepoint failed.");
	ret = register_trace_f2fs_unlink_exit(hf_f2fs_unlink_process, NULL);
	if (ret)
		hf_pr_info("ERR: register f2fs_unlink tracepoint failed.");
	ret = register_trace_f2fs_truncate(hf_f2fs_truncate_process, NULL);
	if (ret)
		hf_pr_info("ERR: register f2fs_truncate tracepoint failed.");

	HF_SET_FLAG(hf->enable_flag, HF_STAT_ENABLE);
}

/*
 * End statistics file access information, and get hot files
 */
static void hf_stat_end(void)
{
	struct hotfile_stat *hf = &hf_stat;
	struct hf_inode *node = NULL;
	struct hlist_bl_node *pos = NULL;
	struct hlist_bl_node *temp = NULL;
	struct hlist_bl_head *head = NULL;
	int i;

	hf_pr_info("Hot file stat disable.");
	if (!HF_GET_FLAG(hf->enable_flag, HF_STAT_ENABLE)) {
		hf_pr_info("Status is already disabled");
		return;
	}

	HF_CLR_FLAG(hf->enable_flag, HF_STAT_ENABLE);
	if (!hf->inode_hash) {
		hf_pr_info("ERR: inode_hash is NULL.");
		return;
	}

	//unregister tracepoint
	unregister_trace_mm_filemap_add_to_page_cache(hf_page_access_record, NULL);
	unregister_trace_f2fs_unlink_exit(hf_f2fs_unlink_process, NULL);
	unregister_trace_f2fs_truncate(hf_f2fs_truncate_process, NULL);
	tracepoint_synchronize_unregister();

	hf_search_hot_files();

	//free hash table
	for (i = 0; i < HF_HASH_BUCKET_NUM; i++) {
		head = &hf->inode_hash[i];
		hlist_bl_lock(head);
		if (hlist_bl_empty(head)) {
			hlist_bl_unlock(head);
			continue;
		}
		hlist_bl_for_each_entry_safe(node, pos, temp, head, hlist) {
			hlist_bl_del(&node->hlist);
			hf_free_node(node);
		}
		hlist_bl_unlock(head);
	}
	kvfree(hf->inode_hash);
	hf->inode_hash = NULL;
	hf->list_len_max = 0;
}

/*
 * Start or end the feature
 * enable=1: start; enable=0: end.
 * The internal information will be cleared when ended.
 */
static ssize_t hf_enable_stat_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	int ret;
	u16 enable;

	ret = kstrtou16(buf, 10, &enable);
	if (ret)
		return ret;

	mutex_lock(&hf_stat.cmd_mutex);
	if (enable)
		hf_stat_start();
	else
		hf_stat_end();
	mutex_unlock(&hf_stat.cmd_mutex);
	return len;
}

static ssize_t hf_enable_stat_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n",
		HF_IS_ENABLE(hf_stat.enable_flag, HF_STAT_ENABLE));
}

/*
 * Pause or resume recording system file access information.
 * enable=1: Resume; enable=0:Pause.
 * The premise is that the HF_STAT_ENABLE is enable
 */
static ssize_t hf_enable_stat_sys_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	struct hotfile_stat *hf = &hf_stat;
	int ret;
	u16 enable;

	ret = kstrtou16(buf, 10, &enable);
	if (ret)
		return ret;

	if (enable)
		HF_SET_FLAG(hf->enable_flag, HF_SYS_STAT);
	else
		HF_CLR_FLAG(hf->enable_flag, HF_SYS_STAT);
	return len;
}

static ssize_t hf_enable_stat_sys_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n",
		HF_IS_ENABLE(hf_stat.enable_flag, HF_SYS_STAT));
}

/*
 * Pause or resume recording app file access information.
 * enable=1: Resume; enable=0:Pause.
 * The premise is that the HF_STAT_ENABLE is enable
 */
static ssize_t hf_enable_stat_app_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	struct hotfile_stat *hf = &hf_stat;
	int ret;
	u16 enable;

	ret = kstrtou16(buf, 10, &enable);
	if (ret)
		return ret;

	if (enable)
		HF_SET_FLAG(hf->enable_flag, HF_APP_STAT);
	else
		HF_CLR_FLAG(hf->enable_flag, HF_APP_STAT);
	return len;
}

static ssize_t hf_enable_stat_app_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n",
		HF_IS_ENABLE(hf_stat.enable_flag, HF_APP_STAT));
}


/*
 * Set sys hot file limit size
 */
static ssize_t hf_hot_limit_sys_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	int ret;
	u32 size;

	ret = kstrtou32(buf, 10, &size);
	if (ret)
		return ret;

	if (size > HF_HOT_SIZE_MAX_DEF)
		size = HF_HOT_SIZE_MAX_DEF;
	hf_stat.hot[HF_SYS].cfg_limit = HF_MB_TO_PAGE(size);
	return len;
}

static ssize_t hf_hot_limit_sys_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d MB\n", HF_PAGE_TO_MB(hf_stat.hot[HF_SYS].cfg_limit));
}

/*
 * Set app hot file limit size
 */
static ssize_t hf_hot_limit_app_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	int ret;
	u32 size;

	ret = kstrtou32(buf, 10, &size);
	if (ret)
		return ret;

	if (size > HF_HOT_SIZE_MAX_DEF)
		size = HF_HOT_SIZE_MAX_DEF;
	hf_stat.hot[HF_APP].cfg_limit = HF_MB_TO_PAGE(size);
	return len;
}

static ssize_t hf_hot_limit_app_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d MB\n", HF_PAGE_TO_MB(hf_stat.hot[HF_APP].cfg_limit));
}

/*
 * Set the weight threshold value of hot files
 */
static ssize_t hf_hot_threshold_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	int ret;
	u32 size;

	ret = kstrtou32(buf, 10, &size);
	if (ret)
		return ret;

	hf_stat.hot[HF_SYS].cfg_weight = HF_HOT_TRH_TO_WEIGHT(size);
	hf_stat.hot[HF_APP].cfg_weight = HF_HOT_TRH_TO_WEIGHT(size);
	return len;
}

static ssize_t hf_hot_threshold_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n",
		HF_HOT_WEIGHT_TO_TRH(hf_stat.hot[HF_SYS].cfg_weight));
}

/*
 * Set the min file size of hot files
 */
static ssize_t hf_min_fsize_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	int ret;
	u32 size;

	ret = kstrtou32(buf, 10, &size);
	if (ret)
		return ret;

	if (size == 0)
		size = HF_HOT_MIN_FSIZE_DEF;
	hf_stat.hot[HF_SYS].cfg_min_fsize = HF_KB_TO_PAGE(size);
	hf_stat.hot[HF_APP].cfg_min_fsize = HF_KB_TO_PAGE(size);
	return len;
}

static ssize_t hf_min_fsize_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d KB\n", HF_PAGE_TO_KB(hf_stat.hot[HF_SYS].cfg_min_fsize));
}

/*
 * Enalbe or Disable the auto protect hot file feature, normally disable.
 */
static ssize_t hf_enable_set_auto_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	struct hotfile_stat *hf = &hf_stat;
	int ret;
	u32 flag;

	ret = kstrtou32(buf, 10, &flag);
	if (ret)
		return ret;

	if (flag)
		HF_SET_FLAG(hf->enable_flag, HF_SET_AUTO);
	else
		HF_CLR_FLAG(hf->enable_flag, HF_SET_AUTO);
	return len;
}

static ssize_t hf_enable_set_auto_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n",
		HF_IS_ENABLE(hf_stat.enable_flag, HF_SET_AUTO));
}

/*
 * Get inode by ino and device
 * @ino: file's ino
 * @dev: the device id which the ino belongs
 */
struct inode *hf_get_inode(u32 ino, u32 dev)
{
	struct block_device *bdev = NULL;
	struct super_block *sb = NULL;
	struct inode *inode = NULL;

	bdev = blkdev_get_no_open(dev);
	if (!bdev)
		goto err;

	sb = get_super(bdev);
	blkdev_put_no_open(bdev);
	if (!sb)
		goto err;

	if ((sb->s_magic != HF_EROFS_SUPER_MAGIC) &&
		(sb->s_magic != HF_F2FS_SUPER_MAGIC)) {
		drop_super(sb);
		goto err;
	}

	inode = ilookup(sb, (unsigned long)ino);
	drop_super(sb);
	return inode;
err:
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	hf_debug.inode_get_fs_fail++;
#endif
	return NULL;
}
EXPORT_SYMBOL(hf_get_inode);

/*
 * Set or clear the protect flag for the hot files.
 * @hot: Hot files information
 * @action: set or clr command
 */
static void hf_set_file_protect_status(struct hf_hot *hot, u32 action)
{
	struct list_head *pos = NULL;
	struct hf_inode *cur_node = NULL;
	struct inode *inode = NULL;

	list_for_each(pos, &hot->hot_head) {
		cur_node = list_entry(pos, struct hf_inode, list);
		inode = hf_get_inode(cur_node->ino, cur_node->dev);
		if (inode) {
			if (action == HF_PROTECT_CMD_SET)
				hf_set_protect_file(inode, cur_node->type);
			else if (action == HF_PROTECT_CMD_CLR)
				hf_clr_protect_file(inode);
			iput(inode);
		} else {
			hf_pr_info("inode not found, ino:%u, dev:%u.\n",
				cur_node->ino, cur_node->dev);
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
			hf_debug.inode_protect_fail++;
#endif
		}
	}
}

static void hf_send_cmd(u32 cmd, u32 flag)
{
	hf_pr_info("cmd:%u, flag:%u\n", cmd, flag);
	mutex_lock(&hf_stat.cmd_mutex);
	if (flag & HF_PROTECT_FLAG_SYS)
		hf_set_file_protect_status(&hf_stat.hot[HF_SYS], cmd);
	if (flag & HF_PROTECT_FLAG_APP)
		hf_set_file_protect_status(&hf_stat.hot[HF_APP], cmd);
	mutex_unlock(&hf_stat.cmd_mutex);
}

/*
 * Set or clear the protect flag for hot files.
 * @buf: command string
 * set: set all hot files protect flag.
 * set_sys: set sys hot files protect flag.
 * set_app: set app hot files protect flag.
 * clr*: clear the hot files protect flag, oposite of "set*" operation
 */
static ssize_t hf_command_store(struct kobject *kobj,
	struct kobj_attribute *attr, const char *buf, size_t len)
{
	char cmd_buf[HF_CMD_STR_MAX_LEN] = {0};
	ssize_t sz;
	u32 cmd;
	u32 flag;

	sz = strscpy(cmd_buf, buf, sizeof(cmd_buf) - 1);
	if (sz <= 0)
		return -EINVAL;

	if (!strcmp(cmd_buf, "set")) {
		cmd = HF_PROTECT_CMD_SET;
		flag = HF_PROTECT_FLAG_SYS | HF_PROTECT_FLAG_APP;
	} else if (!strcmp(cmd_buf, "set_sys")) {
		cmd = HF_PROTECT_CMD_SET;
		flag = HF_PROTECT_FLAG_SYS;
	} else if (!strcmp(cmd_buf, "set_app")) {
		cmd = HF_PROTECT_CMD_SET;
		flag = HF_PROTECT_FLAG_APP;
	} else if (!strcmp(cmd_buf, "clr")) {
		cmd = HF_PROTECT_CMD_CLR;
		flag = HF_PROTECT_FLAG_SYS | HF_PROTECT_FLAG_APP;
	} else if (!strcmp(cmd_buf, "clr_sys")) {
		cmd = HF_PROTECT_CMD_CLR;
		flag = HF_PROTECT_FLAG_SYS;
	} else if (!strcmp(cmd_buf, "clr_app")) {
		cmd = HF_PROTECT_CMD_CLR;
		flag = HF_PROTECT_FLAG_APP;
	} else {
		hf_pr_info("command invalid:%s\n", cmd_buf);
		return len;
	}

	hf_send_cmd(cmd, flag);
	return len;
}

/*
 * Debug information for the feature.
 */
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
static ssize_t hf_run_info_show(struct kobject *kobj,
	struct kobj_attribute *attr, char *buf)
{
	struct hotfile_stat *hf = &hf_stat;
	struct hf_hot *hot = NULL;
	struct hf_inode *hot_node = NULL;
	struct hf_inode *node = NULL;
	struct hlist_bl_node *pos = NULL;
	struct hlist_bl_head *head = NULL;
	char *hot_type_name[HF_CNT] = {"[HOT_SYS]", "[HOT_APP]"};
	u32 all_file_cnt = 0;
	u32 sys_file_cnt = 0;
	u32 bucket_used_cnt = 0;
	u32 list_len_max = 0;
	u32 node_cnt;
	int ret = 0;
	int i;

	mutex_lock(&hf_stat.cmd_mutex);
	if (HF_GET_FLAG(hf->enable_flag, HF_STAT_ENABLE)) {
		for (i = 0; i < HF_HASH_BUCKET_NUM; i++) {
			head = &hf->inode_hash[i];
			hlist_bl_lock(head);
			if (hlist_bl_empty(head)) {
				hlist_bl_unlock(head);
				continue;
			}
			bucket_used_cnt++;
			node_cnt = 0;
			hlist_bl_for_each_entry(node, pos, head, hlist) {
				node_cnt++;
				if (node->type == HF_SYS)
					sys_file_cnt++;
			}
			all_file_cnt += node_cnt;
			if (list_len_max < node_cnt)
				list_len_max = node_cnt;
			hlist_bl_unlock(head);
		}
	}

	ret += snprintf(buf + ret, PAGE_SIZE - ret, "all_file_cnt:%d, sys_file_cnt:%d\n",
		all_file_cnt, sys_file_cnt);
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "bucket_used_cnt:%d\n",
		bucket_used_cnt);
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "list_len_max:%d\n",
		list_len_max);
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "kmem_alloc_cnt:%d\n",
		atomic_read(&hf_debug.kmem_alloc_cnt));
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "inode_del_cnt:%d\n",
		atomic_read(&hf_debug.inode_del_cnt));
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "inode_protect_set_cnt:%d\n",
		atomic_read(&hf_debug.inode_protect_set_cnt));
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "inode_protect_clr_cnt:%d\n",
		atomic_read(&hf_debug.inode_protect_clr_cnt));
	ret += snprintf(buf + ret, PAGE_SIZE - ret,
		"total_time:%llu, count:%llu, avg_time:%llu, max_time:%llu\n",
		hf_debug.time_all_ns, hf_debug.time_add_count,
		hf_debug.time_all_ns / hf_debug.time_add_count, hf_debug.time_max_ns);

	ret += snprintf(buf + ret, PAGE_SIZE - ret, "kmem_alloc_fail:%d\n",
		atomic_read(&hf_debug.kmem_alloc_fail));
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "other_alloc_fail:%d\n",
		hf_debug.other_alloc_fail);
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "inode_protect_fail:%d\n",
		hf_debug.inode_protect_fail);
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "inode_get_fs_fail:%d\n",
		hf_debug.inode_get_fs_fail);
	ret += snprintf(buf + ret, PAGE_SIZE - ret, "critical_err:%d\n",
		hf_debug.critical_err);

	for (i = 0; i < HF_CNT; i++) {
		ret += snprintf(buf + ret, PAGE_SIZE - ret, "%s\n", hot_type_name[i]);
		hot = &hf_stat.hot[i];
		ret += snprintf(buf + ret, PAGE_SIZE - ret, "  hot count:%d\n", hot->file_cnt);
		ret += snprintf(buf + ret, PAGE_SIZE - ret, "  hot size:%d\n", hot->size_sum);
		ret += snprintf(buf + ret, PAGE_SIZE - ret, "  min_weight:%d\n", hot->min_weight);
		if (!list_empty(&hot->hot_head)) {
			hot_node = list_first_entry(&hot->hot_head, struct hf_inode, list);
			ret += snprintf(buf + ret, PAGE_SIZE - ret, "  max_weight:%d\n",
				HF_HOT_WEIGHT(hot_node->count, hot_node->size));
		}
	}
	mutex_unlock(&hf_stat.cmd_mutex);
	return ret;
}
#endif

HF_ATTR(hotfile_enable_stat, HF_MODE_RW, hf_enable_stat_show, hf_enable_stat_store);
HF_ATTR(hotfile_enable_stat_sys, HF_MODE_RW, hf_enable_stat_sys_show, hf_enable_stat_sys_store);
HF_ATTR(hotfile_enable_stat_app, HF_MODE_RW, hf_enable_stat_app_show, hf_enable_stat_app_store);
HF_ATTR(hotfile_limit_sys_mbytes, HF_MODE_RW, hf_hot_limit_sys_show, hf_hot_limit_sys_store);
HF_ATTR(hotfile_limit_app_mbytes, HF_MODE_RW, hf_hot_limit_app_show, hf_hot_limit_app_store);
HF_ATTR(hotfile_hot_threshold, HF_MODE_RW, hf_hot_threshold_show, hf_hot_threshold_store);
HF_ATTR(hotfile_min_fsize_kbytes, HF_MODE_RW, hf_min_fsize_show, hf_min_fsize_store);
HF_ATTR(hotfile_enable_set_auto, HF_MODE_RW, hf_enable_set_auto_show, hf_enable_set_auto_store);
HF_ATTR(hotfile_command, HF_MODE_WO, NULL, hf_command_store);
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
HF_ATTR(hotfile_run_info, HF_MODE_RO, hf_run_info_show, NULL);
#endif

static const struct attribute *hf_attrs[] = {
	&kobj_attr_hotfile_enable_stat.attr,
	&kobj_attr_hotfile_enable_stat_sys.attr,
	&kobj_attr_hotfile_enable_stat_app.attr,
	&kobj_attr_hotfile_limit_sys_mbytes.attr,
	&kobj_attr_hotfile_limit_app_mbytes.attr,
	&kobj_attr_hotfile_hot_threshold.attr,
	&kobj_attr_hotfile_min_fsize_kbytes.attr,
	&kobj_attr_hotfile_enable_set_auto.attr,
	&kobj_attr_hotfile_command.attr,
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	&kobj_attr_hotfile_run_info.attr,
#endif
	NULL,
};

#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
/*
 * Show hot files name list.
 */
static void hf_file_name_list_show(struct seq_file *m,
	struct hotfile_stat *hf, u32 type)
{
	struct hf_hot *hot = NULL;
	struct hf_inode *hot_node = NULL;
	struct list_head *pos = NULL;
	struct inode *inode = NULL;
	char *fname = NULL;
	char *pbuf = NULL;

	if (!m || !hf || (type >= HF_CNT))
		return;
	fname = kvmalloc(PATH_MAX, GFP_KERNEL);
	if (!fname)
		return;

	hot = &hf->hot[type];
	mutex_lock(&hf->cmd_mutex);
	if (HF_GET_FLAG(hf->enable_flag, HF_STAT_ENABLE))
		hf_search_hot_files();

	seq_puts(m, "dev ino count size fname\n");
	list_for_each(pos, &hot->hot_head) {
		hot_node = list_entry(pos, struct hf_inode, list);
		inode = hf_get_inode(hot_node->ino, hot_node->dev);
		if (inode) {
			pbuf = android_fstrace_get_pathname(fname, PATH_MAX, inode);
			iput(inode);
		} else {
			pbuf = NULL;
		}
		seq_printf(m, "%u %u %u %u %s\n",	hot_node->dev, hot_node->ino,
			hot_node->count, hot_node->size, pbuf ? pbuf : "NULL");
	}
	mutex_unlock(&hf->cmd_mutex);
	kvfree(fname);
}

static int hf_app_fn_list_proc_show(struct seq_file *m, void *v)
{
	struct hotfile_stat *hf = (struct hotfile_stat *)m->private;

	hf_file_name_list_show(m, hf, HF_APP);
	return 0;
}

static int hf_app_fn_list_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, hf_app_fn_list_proc_show, PDE_DATA(inode));
}

static const struct proc_ops hf_app_fn_list_proc_fops = {
	.proc_open = hf_app_fn_list_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};

static int hf_sys_fn_list_proc_show(struct seq_file *m, void *v)
{
	struct hotfile_stat *hf = (struct hotfile_stat *)m->private;

	hf_file_name_list_show(m, hf, HF_SYS);
	return 0;
}

static int hf_sys_fn_list_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, hf_sys_fn_list_proc_show, PDE_DATA(inode));
}

static const struct proc_ops hf_sys_fn_list_proc_fops = {
	.proc_open = hf_sys_fn_list_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};
#endif

/*
 * Show hot files ino list. the list item is "dev ino"
 * @type: APP or SYS hot files
 */
static void hf_file_list_show(struct seq_file *m,
	struct hotfile_stat *hf, u32 type)
{
	struct hf_hot *hot = NULL;
	struct hf_inode *hot_node = NULL;
	struct list_head *pos = NULL;

	if (!m || !hf || (type >= HF_CNT))
		return;
	hot = &hf->hot[type];
	mutex_lock(&hf->cmd_mutex);
	if (HF_GET_FLAG(hf->enable_flag, HF_STAT_ENABLE))
		hf_search_hot_files();

	list_for_each(pos, &hot->hot_head) {
		hot_node = list_entry(pos, struct hf_inode, list);
		seq_printf(m, "%d %d\n", hot_node->dev, hot_node->ino);
	}
	mutex_unlock(&hf->cmd_mutex);
}

static void hf_add_hot_files_from_user(char *flist_buf, u32 type)
{
	struct hf_inode *hot_node = NULL;
	struct hf_hot *hot = NULL;
	char *line = NULL;
	u32 dev = 0;
	u32 ino = 0;

	if (!flist_buf || (type >= HF_CNT))
		return;

	hot = &hf_stat.hot[type];
	line = flist_buf;
	while (line) {
		if (sscanf(line, "%u %u", &dev, &ino) != 2)
			break;
		hot_node = hf_alloc_node(false);
		if (!hot_node)
			break;
		hot_node->ino = ino;
		hot_node->dev = dev;
		hot_node->count = 0;
		hot_node->size = 0;
		hot_node->type = type;
		list_add_tail(&hot_node->list, &hot->hot_head);
		hot->file_cnt++;

		line = strchr(line, '\n');
		if (line)
			line++;
	}
}

/*
 * Get and construct hot files list from user input
 * @type: APP or SYS hot files
 */
static ssize_t hf_file_list_write(const char __user *buf, size_t count,
	struct hotfile_stat *hf, u32 type)
{
	char *kbuf = NULL;

	if (!buf || !hf || (type >= HF_CNT))
		return -EINVAL;

	kbuf = kvzalloc(count + 1, GFP_KERNEL);
	if (!kbuf) {
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
		hf_debug.other_alloc_fail++;
#endif
		return -ENOMEM;
	}

	if (copy_from_user(kbuf, buf, count)) {
		kvfree(kbuf);
		return -EFAULT;
	}

	mutex_lock(&hf->cmd_mutex);
	hf_reset_hot_files(&hf->hot[type]);
	hf_add_hot_files_from_user(kbuf, type);
	mutex_unlock(&hf->cmd_mutex);

	kvfree(kbuf);
	return count;
}

static int hf_app_flist_proc_show(struct seq_file *m, void *v)
{
	struct hotfile_stat *hf = (struct hotfile_stat *)m->private;

	hf_file_list_show(m, hf, HF_APP);
	return 0;
}

static ssize_t hf_app_flist_proc_write(struct file *file,
				const char __user *buf,	size_t count, loff_t *pos)
{
	struct hotfile_stat *hf = PDE_DATA(file_inode(file));

	return hf_file_list_write(buf, count, hf, HF_APP);
}

static int hf_app_flist_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, hf_app_flist_proc_show, PDE_DATA(inode));
}

static const struct proc_ops hf_app_flist_proc_fops = {
	.proc_open = hf_app_flist_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = hf_app_flist_proc_write,
};

static int hf_sys_flist_proc_show(struct seq_file *m, void *v)
{
	struct hotfile_stat *hf = (struct hotfile_stat *)m->private;

	hf_file_list_show(m, hf, HF_SYS);
	return 0;
}

static ssize_t hf_sys_flist_proc_write(struct file *file,
	const char __user *buf,	size_t count, loff_t *pos)
{
	struct hotfile_stat *hf = PDE_DATA(file_inode(file));

	return hf_file_list_write(buf, count, hf, HF_SYS);
}

static int hf_sys_flist_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, hf_sys_flist_proc_show, PDE_DATA(inode));
}

static const struct proc_ops hf_sys_flist_proc_fops = {
	.proc_open = hf_sys_flist_proc_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
	.proc_write = hf_sys_flist_proc_write,
};

static struct kobject *hf_interface_create(void)
{
	struct kobject *io_kobj = NULL;
	int err;
	struct proc_dir_entry *proc_entry = NULL;

	io_kobj = kobject_create_and_add("io", kernel_kobj);
	if (!io_kobj) {
		hf_pr_info("failed to create sysfs io.\n");
		return NULL;
	}

	err = sysfs_create_files(io_kobj, hf_attrs);
	if (err) {
		hf_pr_info("failed to create sysfs io attrs.\n");
		kobject_put(io_kobj);
		return NULL;
	}

	proc_entry = proc_mkdir(HF_HOT_PROC_DIR, NULL);
	if (proc_entry) {
		proc_entry = proc_create_data(HF_HOT_PROC_SYS_FLIST, HF_MODE_RW,
			NULL, &hf_sys_flist_proc_fops, &hf_stat);
		if (!proc_entry)
			hf_pr_info("Create proc/%s fail.\n", HF_HOT_PROC_SYS_FLIST);
		proc_entry = proc_create_data(HF_HOT_PROC_APP_FLIST, HF_MODE_RW,
			NULL, &hf_app_flist_proc_fops, &hf_stat);
		if (!proc_entry)
			hf_pr_info("Create proc/%s fail.\n", HF_HOT_PROC_APP_FLIST);
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
		proc_entry = proc_create_data(HF_HOT_PROC_SYS_FN_LIST, HF_MODE_RO,
			NULL, &hf_sys_fn_list_proc_fops, &hf_stat);
		if (!proc_entry)
			hf_pr_info("Create proc/%s fail.\n", HF_HOT_PROC_SYS_FN_LIST);
		proc_entry = proc_create_data(HF_HOT_PROC_APP_FN_LIST, HF_MODE_RO,
			NULL, &hf_app_fn_list_proc_fops, &hf_stat);
		if (!proc_entry)
			hf_pr_info("Create proc/%s fail.\n", HF_HOT_PROC_APP_FN_LIST);
#endif
	}

	return io_kobj;
}

static void hf_interface_remove(struct kobject *kobj)
{
	if (!kobj)
		return;
	kobject_put(kobj);
#ifdef CONFIG_HONOR_HOTFILE_DETECT_DEBUG
	remove_proc_entry(HF_HOT_PROC_SYS_FN_LIST, NULL);
	remove_proc_entry(HF_HOT_PROC_APP_FN_LIST, NULL);
#endif
	remove_proc_entry(HF_HOT_PROC_SYS_FLIST, NULL);
	remove_proc_entry(HF_HOT_PROC_APP_FLIST, NULL);
	remove_proc_entry(HF_HOT_PROC_DIR, NULL);
}

static void hf_resource_exit(void)
{
	struct hotfile_stat *hf = &hf_stat;

	mutex_lock(&hf_stat.cmd_mutex);
	hf_stat_end();
	hf_reset_hot_files(&hf->hot[HF_SYS]);
	hf_reset_hot_files(&hf->hot[HF_APP]);
	mutex_unlock(&hf_stat.cmd_mutex);

	if (hf->io_dir) {
		hf_interface_remove(hf->io_dir);
		hf->io_dir = NULL;
	}
	if (hf->inode_cachep) {
		kmem_cache_destroy(hf->inode_cachep);
		hf->inode_cachep = NULL;
	}
}

static void hf_init_hot_data(struct hf_hot *hot)
{
	INIT_LIST_HEAD(&hot->hot_head);
	hot->cfg_limit = HF_MB_TO_PAGE(HF_HOT_SIZE_MAX_DEF);
	hot->cfg_weight = HF_HOT_WEIGHT_DEF;
	hot->cfg_min_fsize = HF_KB_TO_PAGE(HF_HOT_MIN_FSIZE_DEF);
	hot->min_weight = HF_HOT_WEIGHT_MIN_INIT;
}

static int hf_resource_init(void)
{
	struct hotfile_stat *hf = &hf_stat;

	memset(hf, 0, sizeof(struct hotfile_stat));

	/* hf_inode slab cache */
	hf->inode_cachep = kmem_cache_create("hotfile_cache",
					sizeof(struct hf_inode), 0,
					SLAB_HWCACHE_ALIGN, NULL);
	if (!hf->inode_cachep)
		return -ENOMEM;

	hf->io_dir = hf_interface_create();
	if (!hf->io_dir)
		return -ENOMEM;

	mutex_init(&hf->cmd_mutex);
	hf_init_hot_data(&hf->hot[HF_SYS]);
	hf_init_hot_data(&hf->hot[HF_APP]);
	return 0;
}

static int __init hot_files_init(void)
{
	int ret;

	ret = hf_resource_init();
	if (ret) {
		hf_resource_exit();
		pr_err("hotfile: resource init failed.\n");
	} else {
		hf_pr_info("init success.\n");
	}
	return ret;
}

static void __exit hot_files_exit(void)
{
	hf_pr_info("exit.\n");
	hf_resource_exit();
}

module_init(hot_files_init);
module_exit(hot_files_exit);

MODULE_LICENSE("GPL");

