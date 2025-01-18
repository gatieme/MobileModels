#include <linux/mutex.h>
#include <linux/rbtree.h>
#include <linux/debugfs.h>
#include <linux/dma-mapping.h>
#include <linux/module.h>
#include <linux/delay.h>
#ifndef CONFIG_LIBLINUX
#include <linux/pid.h>
#include <linux/mm_types.h>
#endif

#include "hvgr_mem_api.h"
#include "hvgr_log_api.h"
#include "../../mem/hvgr_mem_interval_tree.h"
#include "../../mem/hvgr_mem_pool.h"

/* max node in cache tree */
#define CACHE_MAX 8000
/* max pages in cache tree 200m */
#define CACHE_MAX_PAGES 51200
/* reclaim batch pages when exceed CACHE_MAX_PAGES */
#define CACHE_RECLAIM_BATCH_PAGES 6400
/* max wasted page when fuzz match */
#define PAGE_UP_LIMIT 256
/* max wasted page struct when fuzz match */
#define MAX_PAGE_UP_LIMIT 4096
/* if list size >= LIST_MAX */
#define LIST_MAX 20
/* if a node is recently reused by LRU_LIFT_CNT times, move it to list head */
#define LRU_LIFT_CNT 4

static DEFINE_SPINLOCK(cache_lock);

static unsigned int sameva_cache_max = CACHE_MAX;
static unsigned int sameva_cache_max_pages = CACHE_MAX_PAGES;
static unsigned int sameva_cache_reclaim_batch_pages = CACHE_RECLAIM_BATCH_PAGES;
static unsigned int sameva_cache_page_up_limit = PAGE_UP_LIMIT;
static unsigned int sameva_cache_max_page_up_limit = MAX_PAGE_UP_LIMIT;
static unsigned int sameva_cache_list_max = LIST_MAX;
static unsigned int sameva_cache_lru_lift_cnt = LRU_LIFT_CNT;
static bool sameva_cache_allow_non_growable = false;

#ifdef CONFIG_DFX_DEBUG_FS
module_param(sameva_cache_max, uint, S_IRUGO | S_IWUSR);
module_param(sameva_cache_max_pages, uint, S_IRUGO | S_IWUSR);
module_param(sameva_cache_reclaim_batch_pages, uint, S_IRUGO | S_IWUSR);
module_param(sameva_cache_page_up_limit, uint, S_IRUGO | S_IWUSR);
module_param(sameva_cache_max_page_up_limit, uint, S_IRUGO | S_IWUSR);
module_param(sameva_cache_list_max, uint, S_IRUGO | S_IWUSR);
module_param(sameva_cache_lru_lift_cnt, uint, S_IRUGO | S_IWUSR);
module_param(sameva_cache_allow_non_growable, bool, S_IRUGO | S_IWUSR);
#endif

struct hvgr_mem_cache_key {
	uint64_t attribute;
	uint64_t pages;
	uint64_t max_pages;
};

static struct hvgr_ctx *area_ctx(struct hvgr_mem_area * const area)
{
	return container_of(area->zone->pmem, struct hvgr_ctx, mem_ctx);
}

struct hvgr_cache_shrinker {
	struct shrinker s;
	/* index ctx for query */
	struct list_head ctx_head;
	/* lru_head for all ctx nodes, order is old to new */
	struct list_head lru_head;
	unsigned long pages;
	struct task_struct *task;
};

static struct hvgr_cache_shrinker shrinker = {
	.ctx_head = LIST_HEAD_INIT(shrinker.ctx_head),
	.lru_head = LIST_HEAD_INIT(shrinker.lru_head),
};

/* assert cache_lock is held */
static void cache_try_lift(struct hvgr_mem_area * const area)
{
	if (area->lru_cnt >= sameva_cache_lru_lift_cnt) {
		list_del_init(&area->lru_node);
		list_add_tail(&area->lru_node, &shrinker.lru_head);
		area->lru_cnt = 0;
	} else {
		area->lru_cnt += 1;
	}
}

static unsigned long cache_shrinker_max_pages(const struct hvgr_cache_shrinker * const s)
{
	unsigned long pages = 0;

	spin_lock(&cache_lock);
	pages = s->pages;
	spin_unlock(&cache_lock);
	return pages;
}

static unsigned long cache_query(struct shrinker *s, struct shrink_control *sc)
{
	struct hvgr_cache_shrinker *sr = container_of(s, struct hvgr_cache_shrinker, s);
	return cache_shrinker_max_pages(sr);
}

#ifndef CONFIG_LIBLINUX
extern int do_munmap(struct mm_struct *mm, unsigned long start, size_t len, struct list_head *uf);
#endif
static void cache_free_area(struct hvgr_mem_area *area)
{
	struct hvgr_ctx *ctx = NULL;
	int ret = 0;
	struct hvgr_device *gdev = hvgr_get_device();
	unsigned long len;
	unsigned long addr;
#ifndef CONFIG_LIBLINUX
	struct mm_struct *mm = NULL;
#endif
	BUG_ON(area->zone == NULL);
	BUG_ON(area->property != HVGR_MEM_PROPERTY_SAME_VA);
	BUG_ON(area->page_array == NULL);
	/* see hvgr_mem_zone_free_memory, but we are in relcaim context */
	if (area->attribute & HVGR_MEM_MASK_KMD_ACCESS)
		hvgr_mem_unmap_kva(area);

	/* see hvgr_mem_sameva_free */
	hvgr_mem_unmap_gva(area);
	/* free other va in current context */
	len = area->max_pages << PAGE_SHIFT;
	addr = area->uva;

	ctx = area_ctx(area);

#ifdef CONFIG_LIBLINUX
	ret = liblinux_pal_usermap_munmap_sp(addr, len, ctx->tgid);
	if (ret != 0)
		hvgr_err(gdev, HVGR_MEM, "liblinux_pal_usermap_munmap_sp fail addr=0x%lx, len=0x%lx ret %d tgid %d\n",
			 addr, len, ret, ctx->tgid);
#else /* !CONFIG_LIBLINUX */
	mm = pid_task(ctx->pid, PIDTYPE_PID)->mm;
	mmap_write_lock(mm);
	ret = do_munmap(mm, addr, len, NULL);
	if (ret != 0)
		hvgr_err(gdev, HVGR_MEM, "do_munamp failed addr=0x%lx, len=0x%lx ret %d tgid %d\n",
			 addr, len, ret, ctx->tgid);
	mmap_write_unlock(mm);
#endif

	BUG_ON(atomic_read(&area->ref_cnt) != 0);
	hvgr_mem_free_page_array(ctx, area);
	hvgr_mem_delete_area(area);
}

static unsigned long cache_free(struct shrinker *s, struct shrink_control *sc)
{
	LIST_HEAD(freelist);
	unsigned long nr_pages_to_free = sc->nr_to_scan;
	unsigned long nr_pages_free = 0;
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_area *tmp = NULL;
	struct hvgr_cache_shrinker *sr = container_of(s, struct hvgr_cache_shrinker, s);

	spin_lock(&cache_lock);
	while (!list_empty(&sr->lru_head)) {
		area = list_first_entry(&sr->lru_head, struct hvgr_mem_area, lru_node);
		struct hvgr_ctx *ctx = area_ctx(area);
		struct hvgr_mem_area *child = NULL;

		list_for_each_entry_safe(child, tmp, &area->child, child) {
			list_del_init(&child->child);
			list_add_tail(&child->child, &freelist);
			nr_pages_free += area->pages;
			ctx->root_size -= 1;
			ctx->root_pages -= area->pages;
			shrinker.pages -= area->pages;

			if (nr_pages_free >= nr_pages_to_free)
				goto reclaim_enough;
		}

		list_add_tail(&area->child, &freelist);
		rb_erase(&area->cache_node, area->cache_root);
		RB_CLEAR_NODE(&(area->cache_node));
		list_del(&area->lru_node);

		nr_pages_free += area->pages;
		ctx->root_size -= 1;
		ctx->root_pages -= area->pages;
		shrinker.pages -= area->pages;

		if (nr_pages_free >= nr_pages_to_free)
			break;
	}
reclaim_enough:
	spin_unlock(&cache_lock);

	list_for_each_entry_safe(area, tmp, &freelist, child) {
		list_del(&area->child);
		cache_free_area(area);
	}
	sc->nr_scanned = nr_pages_free;
	return nr_pages_free;
}

static bool shrinker_running = false;

static int shrinker_task(void *data)
{
	struct hvgr_cache_shrinker *sr = (struct hvgr_cache_shrinker *)data;

	while (!kthread_should_stop()) {
		struct shrink_control sc = { 0 };
		unsigned long reclaimed = 0;
		unsigned long steps;
		unsigned int i;
		__set_current_state(TASK_UNINTERRUPTIBLE);
		schedule();
		shrinker_running = true;
		steps = sameva_cache_reclaim_batch_pages / 256;
		if (steps == 0)
			steps = 1;
		for (i = 0; i < steps; i++) {
			sc.nr_to_scan = 256;
			reclaimed += sr->s.scan_objects(&sr->s, &sc);
			msleep(10);
		}
		pr_info("sameva cache reclaim %ld pages\n", reclaimed);
		shrinker_running = false;
	}
	return 0;
}

static int __init cache_shrinker_init(void)
{
	shrinker.s.count_objects = cache_query;
	shrinker.s.scan_objects = cache_free;
	shrinker.task = kthread_run(shrinker_task, &shrinker, "hvgr-ldk-lru-shrinker");
	if (IS_ERR(shrinker.task)) {
		pr_err("%s: Failed to create task\n", __func__);
	}
	return register_shrinker(&shrinker.s);
}
device_initcall(cache_shrinker_init);

static void shrinker_wakeup(void)
{
	wake_up_process(shrinker.task);
}

static int area_cmp_key(struct hvgr_mem_area * const area, struct hvgr_mem_cache_key *key)
{
	if (area->attribute > key->attribute) {
		return 1;
	} else if (area->attribute == key->attribute) {
		if (area->pages > key->pages) {
			return 1;
		} else if (area->pages == key->pages) {
			return area->max_pages - key->max_pages;
		} else {
			return -1;
		}
	} else {
		return -1;
	}

}

static bool para_can_cache(struct hvgr_mem_alloc_para * const para)
{
	if (para->va != 0 || para->property != HVGR_MEM_PROPERTY_SAME_VA)
		return false;
	if (!sameva_cache_allow_non_growable && para->pages == para->max_pages)
		return false;
	return true;
}

static bool area_can_fit_para(struct hvgr_mem_area * const area,
        struct hvgr_mem_alloc_para * const para)
{
	if (area->attribute != para->attribute)
		return false;
	if (area->pages < para->pages || area->pages > para->pages + sameva_cache_page_up_limit)
		return false;
	if (area->max_pages < para->max_pages || area->max_pages > para->max_pages + sameva_cache_max_page_up_limit)
		return false;
	return true;
}

struct hvgr_mem_area *hvgr_mem_get_cache(struct hvgr_ctx * const ctx, struct hvgr_mem_alloc_para * const para,
					 struct hvgr_mem_area_va *area_va,  bool user_buf)
{
	struct rb_node **link = NULL;
	struct rb_node *rb_node = NULL;
	struct hvgr_mem_area *last_area = NULL;
	struct hvgr_mem_area *area_candidate = NULL;
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_ctx *pmem = NULL;
	struct hvgr_mem_cache_key key = {
		.attribute = para->attribute,
		.pages = para->pages,
		.max_pages = para->max_pages,
	};

	if (!ctx->cache_enabled)
		return NULL;

	if (!para_can_cache(para))
		return NULL;

	spin_lock(&cache_lock);

	link = &(ctx->root.rb_node);
	while (*link) {
		int cmp;
		rb_node = *link;
		last_area = rb_entry(rb_node, struct hvgr_mem_area, cache_node);

		cmp = area_cmp_key(last_area, &key);
		if (cmp == 0) {
			area = last_area;
			break;
		}

		if (area_can_fit_para(last_area, para))
			area_candidate = last_area;

		if (cmp > 0)
			link = &(rb_node->rb_left);
		else
			link = &(rb_node->rb_right);
	}
	if (area == NULL) {
		area = area_candidate;
	}
	if (area != NULL) {
		if (list_empty(&area->child)) {
			/* last node */
			rb_erase(&area->cache_node, &ctx->root);
			RB_CLEAR_NODE(&(area->cache_node));
			list_del_init(&area->lru_node);
			area->child_cnt = 0;
			area->child_reuse_cnt = 0;
			area->lru_cnt = 0;
		} else {
			struct hvgr_mem_area *head = area;
			area->child_cnt -= 1;
			cache_try_lift(area);
			/* remove child */
			area = list_last_entry(&area->child, struct hvgr_mem_area, child);
			list_del_init(&area->child);
			head->child_reuse_cnt -= area->reuse_cnt;
		}

		ctx->root_size--;
		ctx->root_pages -= area->pages;
		shrinker.pages -= area->pages;
		area->reuse_cnt += 1;
	}

	spin_unlock(&cache_lock);

	if (area != NULL) {
		hvgr_info(ctx->gdev, HVGR_MEM,
			"reuse ctx_%u alloc mem prot=%lu:0x%lx, page:%lu/%lu uva/gva=0x%lx",
			ctx->id, area->property, area->attribute, area->pages,
			area->max_pages, area->gva);

		pmem = &ctx->mem_ctx;

		mutex_lock(&pmem->area_mutex);
		(void)hvgr_kv_add(&pmem->area_rec, &area->node);
		hvgr_mem_uva_range_insert(ctx, area);

		if (area_va != NULL) {
			area_va->uva = area->uva;
			area_va->gva = area->gva;
			area_va->kva = area->kva;
		}

		if (user_buf)
			area->user_buf = true;
		mutex_unlock(&pmem->area_mutex);
	}

	return area;
}

int hvgr_mem_set_cache(struct hvgr_ctx * const ctx,
		       struct hvgr_mem_area *const area)
{
	struct rb_node **link = NULL;
	struct rb_node *rb_node = NULL;
	struct hvgr_mem_area *last_area = NULL;
	struct hvgr_mem_cache_key key = {
		.attribute = area->attribute,
		.pages = area->pages,
		.max_pages = area->max_pages
	};
	int ret = 0;
	bool need_reclaim = false;
	unsigned long i;

	spin_lock(&cache_lock);
	if (!ctx->cache_enabled) {
		ret = -ENOSYS;
		goto err_out;
	}

	if (area->property != HVGR_MEM_PROPERTY_SAME_VA) {
		ret = -EINVAL;
		goto err_out;
	}

	if (atomic_read(&area->ref_cnt) != 0) {
		ret = -EINVAL;
		goto err_out;
	}

	if (!sameva_cache_allow_non_growable && area->pages == area->max_pages) {
		ret = -EINVAL;
		goto err_out;
	}

	if (ctx->root_size > sameva_cache_max || shrinker.pages > sameva_cache_max_pages) {
		need_reclaim = true;
	}

	link = &ctx->root.rb_node;
	while (*link) {
		int cmp;
		rb_node = *link;
		last_area = rb_entry(rb_node, struct hvgr_mem_area, cache_node);

		cmp = area_cmp_key(last_area, &key);
		if (cmp == 0)
			break;
		if (cmp > 0)
			link = &(rb_node->rb_left);
		else
			link = &(rb_node->rb_right);
	}

	if (*link != NULL) {
		/* found */
		if (last_area->child_cnt > sameva_cache_list_max) {
			ret = -EINVAL;
			goto err_out;
		}
		list_add_tail(&area->child, &last_area->child);
		last_area->child_cnt += 1;
		last_area->child_reuse_cnt += area->reuse_cnt;
	} else {
		/* not found */
		rb_link_node(&area->cache_node, rb_node, link);
		rb_insert_color(&area->cache_node, &ctx->root);
		area->child_cnt = 1;
		area->child_reuse_cnt = area->reuse_cnt;
		/* the area is new and not in lru list */
		list_add_tail(&area->lru_node, &shrinker.lru_head);
	}

	for (i = 0; i < area->pages; i++) {
		dma_addr_t dma_addr;

		clear_page(page_address(area->page_array[i]));
		dma_addr = hvgr_mem_get_page_dma_addr(area->page_array[i]);
		dma_sync_single_for_device(ctx->gdev->dev, dma_addr, PAGE_SIZE, DMA_BIDIRECTIONAL);
	}

	ctx->root_size++;
	ctx->root_pages += area->pages;
	shrinker.pages += area->pages;

	if (need_reclaim && !shrinker_running) {
		shrinker_wakeup();
	}

	spin_unlock(&cache_lock);
	return 0;
err_out:
	spin_unlock(&cache_lock);
	return ret;
}

void hvgr_mem_disable_cache(struct hvgr_ctx * const ctx)
{
	struct rb_node *node = NULL;
	struct rb_node *tmp = NULL;
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mem_ctx *pmem = NULL;
	unsigned long reuse_cnt = 0;
	unsigned long reuse_pages = 0;
	unsigned long wasted_nodes = 0;
	unsigned long wasted_pages = 0;

	spin_lock(&cache_lock);

	if (!ctx->cache_enabled) {
		spin_unlock(&cache_lock);
		return;
	}

	ctx->cache_enabled = false;

	pmem = &ctx->mem_ctx;

	list_del_init(&ctx->lru_node);

	node = rb_first(&ctx->root);
	while (node != NULL) {
		struct list_head *head;
		struct list_head *next;
		tmp = rb_next(node);
		area = rb_entry(node, struct hvgr_mem_area, cache_node);
		rb_erase(&area->cache_node, &ctx->root);
		RB_CLEAR_NODE(&(area->cache_node));
		list_del_init(&area->lru_node);
		shrinker.pages -= area->pages;

		(void)hvgr_kv_add(&pmem->area_rec, &area->node);
		hvgr_mem_uva_range_insert(ctx, area);

		reuse_cnt += area->reuse_cnt;
		reuse_pages += area->pages * area->reuse_cnt;
		if (area->reuse_cnt == 0) {
			wasted_nodes += 1;
			wasted_pages += area->pages;
		}

		head = &area->child;
		while (!list_empty(head)) {
			next = head->next;
			list_del_init(head);
			head = next;
			area = container_of(head, struct hvgr_mem_area, child);
			reuse_cnt += area->reuse_cnt;
			reuse_pages += area->pages * area->reuse_cnt;
			if (area->reuse_cnt == 0) {
				wasted_nodes += 1;
				wasted_pages += area->pages;
			}
			shrinker.pages -= area->pages;
			(void)hvgr_kv_add(&pmem->area_rec, &area->node);
			hvgr_mem_uva_range_insert(ctx, area);
		}

		node = tmp;
	}

	spin_unlock(&cache_lock);

	dev_info(ctx->gdev->dev, "ctx_%u cache disabed, node count: %ld, pages:%ld, reuse count:%ld, reuse pages:%ld\n",
		 ctx->id, ctx->root_size, ctx->root_pages, reuse_cnt, reuse_pages);
}

#ifdef CONFIG_DFX_DEBUG_FS
static int hvgr_cache_stat_show(struct seq_file *sfile, void *data)
{
	struct hvgr_ctx *ctx = sfile->private;
	struct rb_node *node;
	struct hvgr_mem_area *area = NULL;
	unsigned long total_wasted_pages = 0;
	unsigned long total_wasted_nodes = 0;

	spin_lock(&cache_lock);
	for (node = rb_first(&ctx->root); node; node = rb_next(node)) {
		struct list_head *head;
		struct list_head *next;

		unsigned long list_len = 1;
		unsigned long reuse_cnt = 0;
		unsigned long wasted_nodes = 0;
		unsigned long wasted_pages = 0;

		area = rb_entry(node, struct hvgr_mem_area, cache_node);
		reuse_cnt += area->reuse_cnt;
		if (area->reuse_cnt == 0) {
			wasted_nodes += 1;
			wasted_pages += area->pages;
		}

		head = &area->child;
		next = head->next;
		while (next != head) {
			area = container_of(next, struct hvgr_mem_area, child);

			list_len += 1;
			reuse_cnt += area->reuse_cnt;
			if (area->reuse_cnt == 0) {
				wasted_nodes += 1;
				wasted_pages += area->pages;
			}
			next = next->next;
		}

		seq_printf(sfile, "\tlen: %ld prot=%lu:0x%lx page: %lu/%lu uva/gva=0x%lx, " \
			   "reuse: %ld, wasted: %ld nodes/%ld pages\n",
			   list_len, area->property, area->attribute, area->pages, area->max_pages, area->gva,
			   reuse_cnt, wasted_nodes, wasted_pages);
		total_wasted_pages += wasted_pages;
		total_wasted_nodes += wasted_nodes;
	}
	seq_printf(sfile, "Total: %ld nodes/%ld pages\nTotal wasted: %ld nodes/%ld pages\n",
		   ctx->root_size, ctx->root_pages, total_wasted_nodes, total_wasted_pages);
	seq_printf(sfile, "Shrinker: %ld pages\n", shrinker.pages);
	spin_unlock(&cache_lock);
	return 0;
}

static int hvgr_cache_stat_open(struct inode *in, struct file *file)
{
	return single_open(file, hvgr_cache_stat_show, in->i_private);
}

static const struct file_operations hvgr_cache_stat_fops = {
	.open = hvgr_cache_stat_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
#endif /* CONFIG_DFX_DEBUG_FS */

void hvgr_mem_enable_cache(struct hvgr_ctx * ctx)
{
	ctx->root = RB_ROOT;
	ctx->root_size = 0;
	ctx->root_pages = 0;
	ctx->cache_enabled = true;
#ifdef CONFIG_DFX_DEBUG_FS
	debugfs_create_file("cache_stat", S_IRUGO, ctx->debugfs_dir, ctx, &hvgr_cache_stat_fops);
#endif /* CONFIG_DFX_DEBUG_FS */
	INIT_LIST_HEAD(&ctx->lru_node);
	spin_lock(&cache_lock);
	list_add(&ctx->lru_node, &shrinker.ctx_head);
	spin_unlock(&cache_lock);
}
