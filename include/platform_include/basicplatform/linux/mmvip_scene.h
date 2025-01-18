#ifndef __MMVIP_SCENE_H
#define __MMVIP_SCENE_H

#include <linux/swap.h>
#include <linux/page-isolation.h>
#include <linux/mmzone.h> /* for clear pcp_vip: struct per_cpu_pages */
#include <linux/gfp.h>
#include <trace/events/kmem.h>

#define MMVIP_CAM_VAL     (0xfffffff)
#define MAX_CAM_NAME_P    (4)
#define FPI_NONE          ((__force fpi_t)0)

#ifdef CONFIG_MM_VIP
#define is_migrate_vip(migratetype) unlikely((migratetype) == MIGRATE_VIP)
#define is_migrate_vip_page(_page) (get_pageblock_migratetype(_page) == MIGRATE_VIP)
extern atomic_t mmvip_page_num;
extern int mm_vip_pool_pages;
#endif

struct cmp_name {
	const char *name;
};

bool is_mm_vip_scene(void);
void set_gfp_vip(gfp_t *gfp_mask);
void set_migrate_vip(struct page *page, int *migratetype);
void add_mmvip_page_num(struct page *page, int *migratetype, unsigned int order);
void add_pcppages_count(struct per_cpu_pages *pcp, int migratetype, int count);
void sub_pcppages_count(struct per_cpu_pages *pcp, int migratetype);
void free_pcppages_vip(struct page *page, struct zone *zone,
			struct per_cpu_pages *pcp, int migratetype);
bool migrate_vip_check(struct page *page);

static inline void add_vip_page_num(int migratetype, unsigned int order, struct page *page)
{
	if (migratetype == MIGRATE_VIP) {
		atomic_add(1 << order, &mmvip_page_num);
		SetPageVip(page);
	}
}

static inline void sub_vip_page_num(unsigned int order, struct page *page)
{
	if (PageVip(page)) {
		atomic_add(-(1 << order), &mmvip_page_num);
		ClearPageVip(page);
	}
}

static inline void change_vip_page_num(int migratetype, unsigned int order, struct page *page)
{
	if (migratetype != MIGRATE_VIP || !PageVip(page)) {
		if (migratetype == MIGRATE_VIP) {
			atomic_add(1 << order, &mmvip_page_num);
			SetPageVip(page);
		} else if (PageVip(page)) {
			atomic_add(-(1 << order), &mmvip_page_num);
			ClearPageVip(page);
		}
	}
}

static inline int get_vip_page_num()
{
	return atomic_read(&mmvip_page_num);
}

static inline void change_migrate_type_vip(struct page* page, int *migratetype)
{
	if (mm_vip_pool_pages == 0 && *migratetype == MIGRATE_VIP) {
		*migratetype = MIGRATE_MOVABLE;
		set_pageblock_migratetype(page, *migratetype);
	}
}

#endif /* __MMVIP_SCENE_H__ */
