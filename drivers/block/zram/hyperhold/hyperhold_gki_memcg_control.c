/*
 * Copyright (c) Honor Technologies Co., Ltd. 2022. All rights reserved.
 * Description: hyperhold gki implement
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
 * Author:	Lin Kunli <linkunli.>
 * 		Wang Xin <wangxin23.>
 * 		Yi Pengxiang <yipengxiang.>
 * 		Tian xiaobin <tianxiaobin.>
 *
 * Create: 2022-7-12
 *
 */

#ifdef CONFIG_HYPERHOLD_GKI
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/spinlock.h>
#include <linux/hyperhold_inf.h>
#include <trace/hooks/mm.h>
#include <trace/hooks/vmscan.h>

#include "hyperhold_internal.h"
#include "hyperhold_area.h"
#include "hyperhold_list.h"
#include "hyperhold_gki_memcg_control.h"
#include "hyperhold.h"

static unsigned long mcgid2mcg[MEM_CGROUP_ID_MAX] = {0};
spinlock_t mcg_alloc_lock;
/* memcg score head */
enum score_head_init_status{
	SCORE_HEAD_NOT_INITED,
	SCORE_HEAD_INITED
};
static atomic_t gki_score_head_inited = ATOMIC_INIT(0);
static struct list_head gki_score_head;
static DEFINE_SPINLOCK(gki_score_list_lock);
static struct workqueue_struct *hyperhold_gki_memcgext_workqueue;
struct memcg_ext_release_req {
       struct delayed_work delayed_work;
	   struct mem_cgroup_ext *mcg_ext;
};

enum scan_balance {
	SCAN_EQUAL,
	SCAN_FRACT,
	SCAN_ANON,
	SCAN_FILE,
};

#ifdef CONFIG_HYPERHOLD_GKI_DEBUG
static atomic_t hyperhold_gki_memcg_id=ATOMIC_INIT(0);
#define HYPERHOLD_ESWAP_STAT_GKI_ITEMS 1
#endif

unsigned short get_mcg_id(struct mem_cgroup_ext *mcg_ext)
{
        return mcg_ext->mcg_ext_id;
}

static void tune_hyperhold_scan_type_callback(void *ignore, char *scan_balance)
{
	struct hyperhold_area *area = NULL;

	if(unlikely(!global_settings.zram))
		return;

	area = global_settings.zram->area;
	if(unlikely(!area))
		return;

	if(unlikely(current->pid == area->shrink_pid)){
		*scan_balance = SCAN_ANON;
		return;
	}

	if(unlikely(current->pid == hyperhold_gki_zswapd_pid_get()))
		*scan_balance = SCAN_ANON;
	return;
}

static inline void memcg_ext_inner_init()
{
	unsigned long flags;
	if (SCORE_HEAD_INITED == atomic_read(&gki_score_head_inited))
		return;

	hyperhold_gki_memcgext_workqueue = create_workqueue("proc_memcgext_destroy");
	if (unlikely(!hyperhold_gki_memcgext_workqueue)) {
		return;
	}

	spin_lock_irqsave(&gki_score_list_lock, flags);
	INIT_LIST_HEAD(&gki_score_head);
	atomic_set(&gki_score_head_inited,  SCORE_HEAD_INITED);
	spin_unlock_irqrestore(&gki_score_list_lock, flags);
}

struct mem_cgroup_ext *mem_cgroup_ext_from_memcg(struct mem_cgroup *mcg)
{
	if (!mcg) {
		hh_print(HHLOG_ERR, "get_mem_cgroup mcg is NULL\n");
		return NULL;
	}
	if (mcg->id.id > 0 && mcg->id.id <= MEM_CGROUP_ID_MAX)
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0)
		return (struct mem_cgroup_ext *)mcg->android_oem_data1;
#else
		return (struct mem_cgroup_ext *)mcg->android_vendor_data1;
#endif

	hh_print(HHLOG_DEBUG, "memcg_id invalid: %d\n", mcg->id.id);
	return NULL;
}

static struct mem_cgroup_ext *mem_cgroup_ext_from_id(unsigned short mcg_ext_id)
{
	struct hyperhold_area *area = NULL;
	struct zram *zram = global_settings.zram;
	struct mem_cgroup_ext * memcg_ext;

	if(!zram)
		return NULL;
	area = zram->area;

	if(mcg_ext_id > 0 && mcg_ext_id < HH_MEM_CGROUP_EXT_ID_MAX){
		spin_lock(&(area->mcg_ext_lock));
		if(test_bit(mcg_ext_id,area->mcg_ext_bitmap)) {
			memcg_ext = (struct mem_cgroup_ext *)area->mcg_ext_rmap[mcg_ext_id];
			spin_unlock(&(area->mcg_ext_lock));
			return memcg_ext;
		}
		spin_unlock(&(area->mcg_ext_lock));
	}
	return NULL;
}

struct mem_cgroup_ext* mem_cgroup_ext_from_mcg_id(unsigned short mcgid)
{
	struct mem_cgroup *mcg;
	if(mcgid > 0 && mcgid < MEM_CGROUP_ID_MAX)
	{
		spin_lock(&mcg_alloc_lock);
		mcg = (struct mem_cgroup *)mcgid2mcg[mcgid];
		spin_unlock(&mcg_alloc_lock);
		if(!mcg)
			return NULL;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0)
		return (struct mem_cgroup_ext *) mcg->android_oem_data1;
#else
		return (struct mem_cgroup_ext *) mcg->android_vendor_data1;
#endif
	}
	hh_print(HHLOG_ERR, "memcg_id: %d invalid\n", mcgid);
	return NULL;
}

struct mem_cgroup_ext *get_mem_cgroup (unsigned short mcg_id)
{
	return mem_cgroup_ext_from_id(mcg_id);
}

unsigned short get_mem_cgroup_id(struct mem_cgroup_ext *mcg_ext)
{
	if(!mcg_ext){
		hh_print(HHLOG_ERR,"invalid mem_cgroup_ext\n");
		return 0;
	}
	return mcg_ext->mcg_ext_id;
}

bool mem_cgroup_ext_check(struct mem_cgroup_ext *mcg_ext)
{
	int id=0;
	if(!mcg_ext)
		return false;
	id = mcg_ext->mcg_ext_id;
	return id > 0 && id <= HH_MEM_CGROUP_EXT_ID_MAX;
}

struct mem_cgroup_ext *get_next_memcg_ext(struct mem_cgroup_ext *mcg_ext_prev)
{
	struct mem_cgroup_ext *memcg = NULL;
	struct list_head *pos = NULL;
	unsigned long flags;

	if (SCORE_HEAD_NOT_INITED == atomic_read(&gki_score_head_inited))
		return memcg;

	spin_lock_irqsave(&gki_score_list_lock, flags);

	if (unlikely(!mcg_ext_prev))
		pos = &gki_score_head;
	else
		pos = &mcg_ext_prev->score_node;

	if (list_empty(pos)) /* deleted node */
		goto unlock;

	if (pos->next == &gki_score_head)
		goto unlock;

	memcg = list_entry(pos->next,
			struct mem_cgroup_ext, score_node);
	if (!memcg->mcg || !css_tryget(&memcg->mcg->css))
		memcg = NULL;

unlock:
	spin_unlock_irqrestore(&gki_score_list_lock, flags);
	if (mcg_ext_prev && mcg_ext_prev->mcg)
		css_put(&mcg_ext_prev->mcg->css);

	return memcg;
}

void get_next_memcg_ext_break(struct mem_cgroup_ext *memcg_ext)
{
	if(memcg_ext)
		css_put(&memcg_ext->mcg->css);
}

void memcg_app_score_sort_ext(struct mem_cgroup_ext *target)
{
	struct list_head *pos = NULL;
	unsigned long flags;

	if (SCORE_HEAD_NOT_INITED == atomic_read(&gki_score_head_inited))
		return;

	spin_lock_irqsave(&gki_score_list_lock, flags);
	list_for_each(pos, &gki_score_head) {
		struct mem_cgroup_ext *memcg_ext = list_entry(pos,
				struct mem_cgroup_ext, score_node);
		if (atomic64_read(&memcg_ext->memcg_reclaimed.app_score) <
			atomic64_read(&target->memcg_reclaimed.app_score))
			break;
	}
	list_move_tail(&target->score_node, pos);
	spin_unlock_irqrestore(&gki_score_list_lock, flags);
}

static inline void memcg_app_score_list_del(struct mem_cgroup_ext *target)
{
	unsigned long flags;
	spin_lock_irqsave(&gki_score_list_lock, flags);
	list_del_init(&target->score_node);
	spin_unlock_irqrestore(&gki_score_list_lock, flags);
}

static void memcg_ext_release_work(struct work_struct *work)
{
	struct delayed_work *delayed_work;
	struct memcg_ext_release_req *rq;
	struct mem_cgroup_ext *mcg_ext;
	struct mem_cgroup *mcg;
	struct zram *zram;
	bool zram_lru_empty;
	bool ext_lru_empty;

	hh_print(HHLOG_INFO, "memcg_ext_release_work enter\n");
	if (!work)
		return;
	delayed_work = to_delayed_work(work);
	rq = container_of(delayed_work, struct memcg_ext_release_req, delayed_work);
	if (!rq || !rq->mcg_ext)
		return;
	mcg_ext = rq->mcg_ext;
	mcg = mcg_ext->mcg;
	zram = mcg_ext->zram;

	if (!mcg)
		goto free_rq;

	if(!zram)
		goto out;

	if (!zram->area || !zram->area->obj_table || !zram->area->ext_table)
		goto out;

	/* wait here until memcg has no data in zram_lru and ext_lru, cause there
	 * is no way to notify swap layer to modify swap_entry_t if we release
	 * zram_lru and ext_lru.
	*/
	zram_lru_empty = hh_list_empty(mcg_idx(zram->area, mcg_ext->mcg_ext_id),
			zram->area->obj_table);
	ext_lru_empty = hh_list_empty(mcg_idx(zram->area, mcg_ext->mcg_ext_id),
			zram->area->ext_table);
	if (!zram_lru_empty || !ext_lru_empty) {
		hh_print(HHLOG_INFO, "wait for mcg_ext_id %d\n", mcg_ext->mcg_ext_id);
		if (!hyperhold_gki_memcgext_workqueue)
			queue_delayed_work(hyperhold_gki_memcgext_workqueue,
					&rq->delayed_work, msecs_to_jiffies(2));
		return;
	}
	hh_print(HHLOG_INFO, "mcg_ext_id  %d\n", mcg_ext->mcg_ext_id);

out:
	if (0 != atomic_read(&mcg_ext->valid)) {
		atomic_set(&mcg_ext->valid, 0);
		css_put(&mcg->css);
		hh_print(HHLOG_INFO, "mcg_ext_id css put %d\n", mcg_ext->mcg_ext_id);
	}
free_rq:
	hyperhold_free(rq);
	hh_print(HHLOG_INFO, "memcg_ext_release_work end\n");
}

static void memcg_ext_release(struct mem_cgroup_ext *mcg_ext)
{
	struct memcg_ext_release_req *req;

	if (!hyperhold_gki_memcgext_workqueue)
		return;

	req = hyperhold_malloc(sizeof(struct memcg_ext_release_req), true, false);
	if (unlikely(!req)) {
		req = hyperhold_malloc(sizeof(struct memcg_ext_release_req), true, false);
		if (unlikely(!req)) {
			hh_print(HHLOG_ERR, "alloc memcg_ext_release_req fail!\n");
			return;
		}
	}
	req->mcg_ext = mcg_ext;
	hh_print(HHLOG_INFO, "mcg_ext_id %d\n", mcg_ext->mcg_ext_id);
	INIT_DELAYED_WORK(&req->delayed_work, memcg_ext_release_work);
	queue_delayed_work(hyperhold_gki_memcgext_workqueue,
			&req->delayed_work, msecs_to_jiffies(1));
}


#define MEMCGP_SKIP 7
static struct mem_cgroup_ext *memcg_ext_alloc(struct mem_cgroup *mcg)
{
	struct mem_cgroup_ext *mcg_ext;

	if (mcg->id.id <= MEMCGP_SKIP)
		return NULL;
	mcg_ext = kzalloc(sizeof(struct mem_cgroup_ext),GFP_ATOMIC);
	if (!mcg_ext)
		return NULL;

	mcg_ext->mcg = mcg;
	INIT_LIST_HEAD(&mcg_ext->score_node);
	spin_lock_init(&mcg_ext->zram_init_lock);
	atomic64_set(&mcg_ext->memcg_reclaimed.app_score, 300);
	atomic64_set(&mcg_ext->memcg_reclaimed.ub_ufs2zram_ratio, 100);
	atomic_set(&mcg_ext->memcg_reclaimed.ub_zram2ufs_ratio, 10);
	atomic_set(&mcg_ext->memcg_reclaimed.ub_mem2zram_ratio, 60);
	atomic_set(&mcg_ext->memcg_reclaimed.refault_threshold, 50);
	atomic64_set(&mcg_ext->hyperhold_cold_writeback, 0);
	atomic_set(&mcg_ext->valid, 0);
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0)
	mcg->android_oem_data1 = (u64)mcg_ext;
#else
	mcg->android_vendor_data1 = (u64)mcg_ext;
#endif

	spin_lock(&mcg_alloc_lock);
	mcgid2mcg[mcg->id.id] = (u64)mcg;
	spin_unlock(&mcg_alloc_lock);

	atomic_set(&mcg_ext->valid, 1);
	hh_print(HHLOG_INFO,"mem_cgroup ext alloc mcg_id=%d", mcg->id.id);
	return mcg_ext;
}

static void mem_cgroup_css_online_callback(void *ignore,
		struct cgroup_subsys_state *css, struct mem_cgroup *mcg)
{
	struct mem_cgroup_ext *mcg_ext = mem_cgroup_ext_from_memcg(mcg);

	if (!css_tryget_online(&mcg->css)) {
		return;
	}

	if (!mcg_ext) {
		mcg_ext = memcg_ext_alloc(mcg);
		if (!mcg_ext){
			css_put(&mcg->css);
			return;
		}
	}

	cgroup_path(css->cgroup, mcg_ext->name, MEM_CGROUP_NAME_MAX_LEN);

	hh_print(HHLOG_INFO,"mem_cgroup mem_cgroup_css_online_callback mcg_id=%d, memcg=%s",
		mcg->id.id, mcg_ext->name);
	memcg_app_score_sort_ext(mcg_ext);
	return;
}
static void mem_cgroup_css_offline_callback(void *ignore,
		struct cgroup_subsys_state *css, struct mem_cgroup *mcg)
{
	struct mem_cgroup_ext *mcg_ext = NULL;
	if(!mcg)
		return;
	mcg_ext = mem_cgroup_ext_from_memcg(mcg);
	if(NULL == mcg_ext)
		return;

	memcg_app_score_list_del(mcg_ext);
	memcg_ext_release(mcg_ext);
	hh_print(HHLOG_INFO,"mem_cgroup mem_cgroup_css_offline_callback mcg_id=%d, memcg=%s",
			mcg->id.id, mcg_ext->name);
	return;
}

static void mem_cgroup_id_remove_callback(void *ignore, struct mem_cgroup *mcg)
{
	if (!mcg)
		return;
	spin_lock(&mcg_alloc_lock);
	mcgid2mcg[mcg->id.id] = 0;
	spin_unlock(&mcg_alloc_lock);
	hh_print(HHLOG_INFO,"mem_cgroup mem_cgroup_id_remove_callback mcg_id=%d", mcg->id.id);
}

static void mem_cgroup_free_callback(void *ignore, struct mem_cgroup *mcg)
{
	struct zram *zram = NULL;
	struct mem_cgroup_ext *mcg_ext;
	struct hyperhold_area *area;
	int id = 0;

	hh_print(HHLOG_INFO,"mem_cgroup mem_cgroup_free_callback enter");
	if (!mcg)
		return;
	/*mcg id is 0 after mem_cgroup_id_remove, so we can not use mem_cgroup_ext_from_memcg to get mem_cgroup_ext pointer*/
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0)
	mcg_ext = (struct mem_cgroup_ext *)mcg->android_oem_data1;
#else
	mcg_ext = (struct mem_cgroup_ext *)mcg->android_vendor_data1;
#endif
	if (!mcg_ext)
		return;
	id = mcg_ext->mcg_ext_id;
	zram = global_settings.zram;
	if(!zram || id == 0)
		goto out;

	hh_print(HHLOG_INFO,"mem_cgroup mem_cgroup_free_callback name:%s",mcg_ext->name);

	area = zram->area;
	hyperhold_mem_cgroup_remove(mcg);
	spin_lock(&area->mcg_ext_lock);
	test_and_clear_bit(id,area->mcg_ext_bitmap);
	area->mcg_ext_rmap[id] = 0;
	spin_unlock(&area->mcg_ext_lock);

out:
	kfree(mcg_ext);
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0)
	mcg->android_oem_data1 = 0;
#else
	mcg->android_vendor_data1 = 0;
#endif
	hh_print(HHLOG_INFO,"mem_cgroup mem_cgroup_free_callback end mcg_id=%d, mcg_ext_id=%d", mcg->id.id, id);
	return;
}

void memcg_ext_init(void)
{
	memcg_ext_inner_init();
	spin_lock_init(&mcg_alloc_lock);
	register_trace_android_vh_mem_cgroup_css_online(mem_cgroup_css_online_callback, NULL);
	register_trace_android_vh_mem_cgroup_css_offline(mem_cgroup_css_offline_callback, NULL);
	register_trace_android_vh_mem_cgroup_id_remove(mem_cgroup_id_remove_callback, NULL);
	register_trace_android_vh_mem_cgroup_free(mem_cgroup_free_callback, NULL);
	register_trace_android_vh_tune_scan_type(tune_hyperhold_scan_type_callback,NULL);
}

ssize_t hyperhold_memcg_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t size =0;
	struct list_head *pos =NULL;
	unsigned long flags;

	if(SCORE_HEAD_NOT_INITED == atomic_read(&gki_score_head_inited))
		return 0;

	spin_lock_irqsave(&gki_score_list_lock,flags);
	list_for_each(pos,&gki_score_head) {
		struct mem_cgroup_ext *memcg_ext = list_entry(pos,
				struct mem_cgroup_ext, score_node);
		if(memcg_ext){
			size += scnprintf(buf +size, PAGE_SIZE - size,
					"%s,%d\n",memcg_ext->name,
					memcg_ext->mcg->id.id);
		}
	}
	spin_unlock_irqrestore(&gki_score_list_lock,flags);

	return size;
}

ssize_t hyperhold_force_swapout_store(struct device *dev,
       struct device_attribute *attr, const char *buf, size_t len)
{
       int ret;
       unsigned long mcgid;
       unsigned long size;

       ret = kstrtoul(buf, 0, &mcgid);
       if (unlikely(ret)) {
               hh_print(HHLOG_ERR, "mcgid is error!\n");
               return EINVAL;
       }

       hh_print(HHLOG_INFO, "force swapout mcgid is :%lu\n", mcgid);

       size = FT_RECLAIM_SZ * MIN_RECLAIM_ZRAM_SZ;
       ret = hyperhold_mcg_reclaim(mcgid, (void *)&size);

       if (unlikely(ret < 0)) {
               hh_print(HHLOG_ERR, "force swapout mcgid:%lu, ret:%d error!\n", mcgid,ret);
       } else {
               hh_print(HHLOG_DEBUG, "force swapout mcgid:%lu size:%d\n", mcgid, size);
       }
       return len;
}

ssize_t hyperhold_force_swapin_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	int ret;
	unsigned long mcgid;
	unsigned long size;
	struct mem_cgroup_ext *mcg_ext;
	/** const unsigned int ratio = 100; */

	ret = kstrtoul(buf, 0, &mcgid);
	if (unlikely(ret)) {
		hh_print(HHLOG_ERR, "mcgid is error!\n");
		return -EINVAL;
	}

	hh_print(HHLOG_INFO, "force swapin mcgid is :%lu\n", mcgid);

	mcg_ext = mem_cgroup_ext_from_mcg_id((unsigned short)mcgid);
	if(NULL == mcg_ext)
		return -EINVAL;
	size = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_STORED_SZ);
	/** size = atomic64_read(&mcg->memcg_reclaimed.ub_ufs2zram_ratio) * size / ratio; */
	size = (((size)+EXTENT_SIZE-1)&(~(EXTENT_SIZE-1)));

	hyperhold_batch_out(mcg_ext,size,false);
	hh_print(HHLOG_DEBUG,"HHGKI: hyperhold_batch_out ret\n");

	return len;
}

ssize_t hyperhold_force_shrink_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t len)
{
	int mcgid;
	int ret;
	unsigned long nr_to_reclaim;
	struct mem_cgroup_ext *mcg_ext = NULL;
	struct hyperhold_area *area = global_settings.zram->area;

	if(!area)
		return -EINVAL;

	if(sscanf(buf, "%d,%lu", &mcgid, &nr_to_reclaim) != 2){
		hh_print(HHLOG_ERR, "force_shrink invalid\n");
		return -EINVAL;
	}

	mcg_ext = mem_cgroup_ext_from_mcg_id(mcgid);
	if(!mcg_ext){
		hh_print(HHLOG_ERR, "force_shrink mcg id invalid\n");
		return -EINVAL;
	}

	hh_print(HHLOG_INFO, "force swap mcgid is :%lu\n", mcgid);
	mutex_lock(&area->shrink_lock);
	area->shrink_pid = current->pid;
	ret = hyperhold_mcg_shrink(mcgid, nr_to_reclaim/PAGE_SIZE);
	mutex_unlock(&area->shrink_lock);

	if (unlikely(!ret))
		hh_print(HHLOG_ERR, "force swap mcgid:%lu error!\n", mcgid);
	else
		hh_print(HHLOG_INFO, "force swap mcgid:%lu success!\n", mcgid);

	return len;
}

#ifdef CONFIG_HYPERHOLD_GKI_DEBUG
ssize_t hyperhold_memcg_stat_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t len)
{
	int mcg_id;

	if (sscanf(buf, "%d", &mcg_id) !=
			HYPERHOLD_ESWAP_STAT_GKI_ITEMS) {
		hh_print(HHLOG_ERR, "memcg id invalid\n");
		return -EINVAL;
	}

	atomic_set(&hyperhold_gki_memcg_id, mcg_id);
	return len;
}

ssize_t hyperhold_memcg_stat_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	unsigned long mcg_zram_stored_size;
	unsigned long mcg_disk_stored_size;
	ssize_t size;
	int mcg_id;
	struct mem_cgroup_ext *mcg_ext;

	mcg_id = atomic_read(&hyperhold_gki_memcg_id);
	mcg_ext = mem_cgroup_ext_from_mcg_id(mcg_id);

	if(!mcg_ext) {
		return scnprintf(buf, PAGE_SIZE, "memcg id invalid: %d\n", mcg_id);
		return 0;
	}
	mcg_zram_stored_size = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_ZRAM_STORED_SZ);
	mcg_disk_stored_size = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_STORED_SZ);

	size = scnprintf(buf, PAGE_SIZE, "mcgid:%d ,extid:%d\n"
			"mcg_zram_stored_size:%lu\n"
			"mcg_disk_stored_size:%lu\n",
			mcg_id, mcg_ext->mcg_ext_id,
			mcg_zram_stored_size,
			mcg_disk_stored_size);
	return size;

}
#endif

ssize_t hyperhold_appscore_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t len)
{
	int mcg_id = 0;
	int appscore = 0;
	struct mem_cgroup_ext *mcg_ext = NULL;
	struct mem_cgroup *mcg = NULL;

	if (sscanf(buf, "%d,%d", &mcg_id, &appscore) !=
			HYPERHOLD_APPSCORE_ITEMS) {
		hh_print(HHLOG_ERR, "appscore invalid\n");
		return -EINVAL;
	}

	if (mcg_id < 0 || mcg_id > MEM_CGROUP_ID_MAX){
		hh_print(HHLOG_ERR, "memcg %d is invalid\n", mcg_id);
		return -EINVAL;
	}

	if (appscore > APPSCORE_MAX || appscore < APPSCORE_MIN){
		hh_print(HHLOG_ERR, "appscore %d invalid\n", appscore);
		return -EINVAL;
	}


	spin_lock(&mcg_alloc_lock);
	mcg = (struct mem_cgroup *)mcgid2mcg[mcg_id];
	if(!mcg || !css_tryget(&mcg->css)){
		spin_unlock(&mcg_alloc_lock);
		return -EINVAL;
	}
	spin_unlock(&mcg_alloc_lock);
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0)
	mcg_ext = (struct mem_cgroup_ext *)mcg->android_oem_data1;
#else
	mcg_ext = (struct mem_cgroup_ext *)mcg->android_vendor_data1;
#endif

	if(!mcg_ext) {
		hh_print(HHLOG_ERR, "memcg %d is invalid\n", mcg_id);
		css_put(&mcg->css);
		return -EINVAL;
	}

	atomic64_set(&mcg_ext->memcg_reclaimed.app_score, appscore);
	memcg_app_score_sort_ext(mcg_ext);

	css_put(&mcg->css);

	return len;
}

ssize_t hyperhold_appscore_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t size = 0;
	unsigned short mcgextid = 0;
	unsigned short mcgid=0;
	struct list_head *pos = NULL;
	unsigned long flags;

	if (SCORE_HEAD_NOT_INITED == atomic_read(&gki_score_head_inited))
		return size;

	spin_lock_irqsave(&gki_score_list_lock, flags);
	list_for_each(pos, &gki_score_head) {
		struct mem_cgroup_ext *memcg_ext = list_entry(pos,
				struct mem_cgroup_ext, score_node);
		mcgextid = get_mcg_id(memcg_ext);
		mcgid = memcg_ext->mcg->id.id;
		size += scnprintf(buf + size, PAGE_SIZE-size,
					"%d,%d,%d\n", mcgid, mcgextid,
					atomic64_read(&memcg_ext->memcg_reclaimed.app_score));
	}
	spin_unlock_irqrestore(&gki_score_list_lock, flags);

	return size;
}

ssize_t hyperhold_memcg_eswap_info(int type, char *buf, int mcg_id)
{
	unsigned long swap_out_cnt = 0;
	unsigned long swap_out_size = 0;
	unsigned long swap_in_size = 0;
	unsigned long swap_in_cnt = 0;
	unsigned long page_fault_cnt = 0;
	unsigned long cur_eswap_size = 0;
	unsigned long max_eswap_size = 0;
	ssize_t size = 0;
	struct mem_cgroup_ext *mcg_ext = NULL;

	if(type == HYPERHOLD_MEMCG_ESWAP_SINGLE) {
		mcg_ext = mem_cgroup_ext_from_mcg_id(mcg_id);
		if(!mcg_ext)
			return 0;
		swap_out_cnt = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPOUT_CNT);
		swap_out_size = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPOUT_SZ);
		swap_in_size = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPIN_SZ);
		swap_in_cnt = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPIN_CNT);
		page_fault_cnt = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_FAULT_CNT);
		cur_eswap_size = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_SPACE);
		max_eswap_size = hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_SPACE_PEAK);
	} else if (type == HYPERHOLD_MEMCG_ESWAP_ALL) {
		while ((mcg_ext = get_next_memcg_ext(mcg_ext))) {
			swap_out_cnt += hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPOUT_CNT);
			swap_out_size += hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPOUT_SZ);
			swap_in_size += hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPIN_SZ);
			swap_in_cnt += hyperhold_read_mcg_ext_stats(mcg_ext, MCG_SWAPIN_CNT);
			page_fault_cnt += hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_FAULT_CNT);
			cur_eswap_size += hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_SPACE);
			max_eswap_size += hyperhold_read_mcg_ext_stats(mcg_ext, MCG_DISK_SPACE_PEAK);
		}
	} else {
		return  scnprintf(buf, PAGE_SIZE, "param error\n");
	}

	size = scnprintf(buf, PAGE_SIZE, "swapOutTotal:%lu\n"
										"swapOutSize:%lu MB\n"
										"swapInSize:%lu MB\n"
										"swapInTotal:%lu\n"
										"pageInTotal:%lu\n"
										"swapSizeCur:%lu MB\n"
										"swapSizeMax:%lu MB\n",
										swap_out_cnt,
										swap_out_size / SZ_1M,
										swap_in_size / SZ_1M,
										swap_in_cnt,
										page_fault_cnt,
										cur_eswap_size / SZ_1M,
										max_eswap_size / SZ_1M);

	return size;
}

#endif
