/*
 * Copyright (c) Honor Device Co., Ltd. 2022-2022. All rights reserved.
 * Description:micro dump pagedump function
 * Author: Lu Laicheng
 * Create: 2022-03-22
 */

#include <micro_dump.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0)
#define TRACK_ADDRS_COUNT 16
struct track {
	unsigned long addr;
#ifdef CONFIG_STACKTRACE
	unsigned long addrs[TRACK_ADDRS_COUNT];
#endif
	int cpu;
	int pid;
	unsigned long when;
};

enum track_item { TRACK_ALLOC, TRACK_FREE };
#endif

static struct track *micro_get_track(struct kmem_cache *s, void *object,
	enum track_item alloc)
{
	struct track *p;

	if (s->offset)
		p = object + s->offset + sizeof(void *);
	else
		p = object + s->inuse;

	return p + alloc;
}

static void micro_print_track(const char *s, struct track *t, unsigned long pr_time)
{
	if (!t->addr)
		return;

	pr_err("INFO: %s in %pS age=%lu cpu=%u pid=%d\n",
	       s, (void *)t->addr, pr_time - t->when, t->cpu, t->pid);
#ifdef CONFIG_STACKTRACE
	{
		int i;
		for (i = 0; i < TRACK_ADDRS_COUNT; i++)
			if (t->addrs[i])
				pr_err("\t%pS\n", (void *)t->addrs[i]);
			else
				break;
	}
#endif
}

static void micro_print_tracking(struct kmem_cache *s, void *object)
{
 	unsigned long pr_time = jiffies;
 	if (!(s->flags & SLAB_STORE_USER))
 		return;

	micro_print_track("Allocated", micro_get_track(s, object, TRACK_ALLOC), pr_time);
	micro_print_track("Freed", micro_get_track(s, object, TRACK_FREE), pr_time);
}

static void get_slab_page_info(unsigned long addr, struct microdump_page_info *info)
{
	unsigned long start;
	struct page *page;
	int order;

	page = virt_to_head_page((void *)addr);
	if (!page) {
		info->type = TYPE_NONE;
		return;
	}

	order = compound_order(page);
	start = (unsigned long)page_address(page);
	info->page = page;
	info->order = order;
	info->start_vir_addr = start;
	info->phy_addr = __pa(addr);
	if (PageSlab(page)) {
		info->type = TYPE_SLAB;
	} else {
		// just a page, not for slab
		info->type = TYPE_PAGE;
	}
}

void microdump_addr_page_info(unsigned long addr, struct microdump_page_info *info)
{
	if (!info)
		return;

#ifndef IN_REGION
#define IN_REGION(a, b, c) ((a) >= (b) && (a) <= (c))
#endif
#ifndef IN_REGION_PHYS
#define IN_REGION_PHYS(a, b, c) (__phys_to_virt((a)) >= (__phys_to_virt((b))) && __phys_to_virt((a)) <= (__phys_to_virt((c))))
#endif

	if (IN_REGION(addr, __phys_to_virt(micro_memblock->memory.regions[0].base), (unsigned long)high_memory_addr)) {
		get_slab_page_info(addr, info);
	} else if (IN_REGION(addr, module_alloc_base_addr, module_alloc_base_addr + MODULES_VSIZE)) {
		info->type = TYPE_MODULE;
	} else if (IN_REGION(addr, VMALLOC_START, VMALLOC_END)) {
		// vmalloc include :data, bss, init, rodata, text, pci io, fixed
		info->type = TYPE_VMALLOC;
		if (IN_REGION_PHYS(addr, _text_addr, _etext_addr)) {
			info->type = TYPE_TEXT;
		} else if (IN_REGION_PHYS(addr, __bss_start_addr, __bss_stop_addr)) {
			info->type = TYPE_BSS;
		} else if (IN_REGION_PHYS(addr, _sdata_addr, _edata_addr)) {
			info->type = TYPE_DATA;
		} else if (IN_REGION_PHYS(addr, __init_begin_addr, __init_end_addr)) {
			info->type = TYPE_INIT;
		} else if (IN_REGION_PHYS(addr, __start_rodata_addr, __init_begin_addr)) {
			info->type = TYPE_RODATA;
		}
	} else if (IN_REGION(addr, VMEMMAP_START, VMEMMAP_START + VMEMMAP_SIZE)) {
		info->type = TYPE_VMEM;
	} else if (IN_REGION(addr, PCI_IO_START, PCI_IO_END)) {
		info->type = TYPE_PCI_IO;
	} else if (IN_REGION(addr, FIXADDR_START, FIXADDR_TOP)) {
		info->type = TYPE_FIXED;
	} else {
		info->type = TYPE_NONE;
	}
}

bool is_kernel_addr(unsigned long addr)
{
	struct microdump_page_info info;
	microdump_addr_page_info(addr, &info);
	return (info.type != TYPE_NONE);
}

static bool page_has_dump(unsigned long addr)
{
	unsigned long page_start;
	int i, j;

	page_start = addr & PAGE_ALIGN_MASK;

	for (i = 0; i < MAX_DUMP_ADDR_NUM; i++) {
		for (j = 0; j <= g_exp_ctrl.dump_size[i]; j += PAGE_SIZE) {
			if (page_start == ((g_exp_ctrl.dump_addr[i] + PAGE_SIZE * j) & PAGE_ALIGN_MASK)) {
				return true;
			}
		}
	}
	return false;
}

static bool bytes_has_dump(unsigned long addr, int nr_byte)
{
	unsigned long line_start;
	int i;

	line_start = addr;
	for (i = 0; i < MAX_DUMP_ADDR_NUM; i++) {
		if (g_exp_ctrl.dump_addr[i] <= addr) {
			if (g_exp_ctrl.dump_addr[i] + g_exp_ctrl.dump_size[i] >= addr + nr_byte) {
				return true;
			}
		}
	}
	return false;
}

static void mem_save_dump(unsigned long addr, int nr_byte)
{
	int i;

	for (i = 0; i < MAX_DUMP_ADDR_NUM; i++) {
		if (g_exp_ctrl.dump_addr[i] == 0) {
			g_exp_ctrl.dump_addr[i] = addr;
			g_exp_ctrl.dump_size[i] = nr_byte;
			break;
		}
	}
}

bool microdump_check_addr_valid(unsigned long addr)
{
	unsigned long par;
#define MICR0_SYS_PAR_EL1_F BIT(0)
	asm volatile("at s1e1r, %0" :: "r" (addr));
	isb();
	par = read_sysreg(par_el1);
	if (par & MICR0_SYS_PAR_EL1_F)
		return false;
	return true;
}

#ifdef CONFIG_SLUB
static inline void *freelist_ptr(const struct kmem_cache *s, void *ptr,
				unsigned long ptr_addr)
{
#ifdef CONFIG_SLAB_FREELIST_HARDENED
	return (void *)((uintptr_t)ptr ^ s->random ^
			swab((unsigned long)kasan_reset_tag((void *)ptr_addr)));
#else
	return ptr;
#endif
}

/* Returns the freelist pointer recorded at location ptr_addr. */
static inline void *freelist_dereference(const struct kmem_cache *s, void *ptr_addr)
{
	return freelist_ptr(s, (void *)*(unsigned long *)(ptr_addr), (uintptr_t)ptr_addr);
}

static inline void *get_free_ptr(struct kmem_cache *s, void *object)
{
	object = kasan_reset_tag(object);
	if (microdump_check_addr_valid((unsigned long)(uintptr_t)object)) {
		return freelist_dereference(s, object + s->offset);
	} else {
		return NULL;
	}
}

static void *microdump_nearest_obj(struct kmem_cache *cache, struct page *page, void *x)
{
	void *last_object;
	void *result;
	void *object;

	object = x - (x - page_address(page)) % cache->size;
	if (object != x) {
		MD_PRINT("SLUB: slub 0x%lx not align object=0x%lx ,page_address=0x%lx size=0x%x\n",
				x, object, page_address(page), cache->size);
	}
	last_object = page_address(page) + (page->objects - 1) * cache->size;
	result = (unlikely(object > last_object)) ? last_object : object;

	result = common_fixup_red_left(cache, result);
	return result;
}

static inline void print_slub_info(struct page *page, void *slub_info, bool free)
{
	struct kmem_cache *cache = page->slab_cache;
	MD_PRINT("SLUB: 0x%lx,pa(0x%lx),0x%lx objects=%u used=%u freelist=0x%lx flags=0x%04lx, %s, cache name:%s, %d\n",
		page, __pa(slub_info), slub_info, page->objects, page->inuse, page->freelist, page->flags,
		free ? "free" : "not free", cache->name, cache->size);
}

#define MAX_PAGE_OBJECTS (PAGE_SIZE >> 4)

static phys_addr_t find_prev_slab_and_print_slub(phys_addr_t pa_addr, void* ptr,
	struct microdump_page_info* info)
{
	void *va = ptr;
	struct kmem_cache *slab_kmem_cache = NULL;
	struct page *compound_page = info->page;
	void *slub_info = NULL;
	void *s;
	int free_count = 0;
	phys_addr_t pre;

	if (pa_addr == 0 || va == NULL || compound_page == NULL) {
		return 0;
	}
	if (!PageSlab(compound_page))
		return 0;

	slab_kmem_cache = compound_page->slab_cache;
	if (!slab_kmem_cache)
		return 0;

	slub_info = microdump_nearest_obj(slab_kmem_cache, compound_page, va);
	if (!slub_info) {
		return 0;
	}

	for (s = compound_page->freelist; s != NULL; s = get_free_ptr(slab_kmem_cache, s)) {
		if (s == slub_info)
			break;

		free_count++;
		if (free_count > (compound_page->objects - compound_page->inuse) || free_count > MAX_PAGE_OBJECTS)
			break;
	}

	if (s == slub_info)
		print_slub_info(compound_page, slub_info, true);
	else
		print_slub_info(compound_page, slub_info, false);

	if (slab_kmem_cache->flags & SLAB_STORE_USER)
		micro_print_tracking(slab_kmem_cache, slub_info);

	// prev slab info
	if (slub_info - slab_kmem_cache->size <= page_address(compound_page)) {
		pre = __pa(slub_info - slab_kmem_cache->size);
	} else {
		pre = 0;
	}

	return pre;
}

static void check_and_print_slub_info(unsigned long ptr, struct microdump_page_info *info)
{
	phys_addr_t prev_slub;

	if (microdump_check_addr_valid(ptr)) {
		if (info && info->type == TYPE_SLAB) {
			MD_PRINT("SLUB:0x%lx - pa:%px\n", (void*)ptr, (void*)__pa(ptr));
			prev_slub = find_prev_slab_and_print_slub((phys_addr_t)info->phy_addr, (void*)ptr, info);
			if (prev_slub)
				prev_slub = find_prev_slab_and_print_slub(prev_slub, __va(prev_slub), info);
		}
	}
}
#endif

static void dump_page_summary_info(unsigned long addr, unsigned long start,
	unsigned long end, const char *name)
{
	MD_PRINT("%s page, addr:0x%lx , rang:(0x%lx--0x%lx)\n", name, addr, start, end);
}

static int microdump_unique_info_ext_by_page(unsigned long ptr, int *start, int *size,
	struct microdump_page_info *info)
{
	int by_page = 0;
	switch (info->type) {
	case TYPE_VMALLOC:
		dump_page_summary_info(ptr, VMALLOC_START, VMALLOC_END, "vmalloc");
		by_page = 1;
		*start = 0;
		*size = PAGE_SIZE;
		break;
	case TYPE_PAGE:
		dump_page_summary_info(ptr, __phys_to_virt(micro_memblock->memory.regions[0].base),
			(unsigned long)high_memory_addr, "liner");
		by_page = 1;
		*start = 0;
		*size = PAGE_SIZE >> 4; // 4: print 1/16 pagesize
		break;
	case TYPE_STACK:
		// 4:stack deep is 4 page
		dump_page_summary_info(ptr, info->start_vir_addr, info->start_vir_addr + 4 * PAGE_SIZE, "stack");
		by_page = 1;
		*start = 0;
		*size = PAGE_SIZE;
		break;
	default:
		break;
	}
	return by_page;
}

static void microdump_unique_info_ext(unsigned long ptr, int *start, int *size,
	struct microdump_page_info *info)
{
	switch (info->type) {
	case TYPE_BSS:
		dump_page_summary_info(ptr, __phys_to_virt(__bss_start_addr), __phys_to_virt(__bss_stop_addr), "bss");
		*start = (int)(sizeof(unsigned long))*8;
		*size = PAGE_SIZE >> 2; // 2: print 1/4 pagesize
		break;
	case TYPE_DATA:
		dump_page_summary_info(ptr, __phys_to_virt(_sdata_addr), __phys_to_virt(_edata_addr), "data");
		*start = (int)(sizeof(unsigned long)) * 8;
		*size = PAGE_SIZE >> 3; // 3: print 1/8 pagesize
		break;
#ifdef CONFIG_SLUB
	case TYPE_SLAB:
		dump_page_summary_info(ptr, __phys_to_virt(micro_memblock->memory.regions[0].base),
			(unsigned long)high_memory_addr, "liner");
		check_and_print_slub_info(ptr, info);
		*start = (int)(sizeof(unsigned long)) * 8;
		*size = PAGE_SIZE >> 4; // 4: print 1/16 pagesize
		break;
#endif
	case TYPE_VMEM:
		dump_page_summary_info(ptr, VMEMMAP_START, VMEMMAP_START + VMEMMAP_SIZE, "vmemmap");
		*start = (int)(sizeof(unsigned long)) * 8;
		*size = PAGE_SIZE >> 4; // 4: print 1/16 pagesize
		break;
	case TYPE_MODULE:
		dump_page_summary_info(ptr, module_alloc_base_addr, module_alloc_base_addr + MODULES_VSIZE, "module");
		*start = (int)(sizeof(unsigned long)) * 8;
		*size = PAGE_SIZE >> 4; // 4: print 1/16 pagesize
		break;
	case TYPE_RODATA:
	case TYPE_NONE:
	case TYPE_INIT:
	case TYPE_KIMAGE:
	case TYPE_TEXT:
	case TYPE_FIXED:
	case TYPE_PCI_IO:
	default:
		MD_PRINT("other info:\n");
		*start = 0;
		*size = 0;
		break;
	}
}


static int microdump_unique_info(unsigned long ptr, int *start, int *size,
	struct microdump_page_info *info)
{
	int by_page;
	by_page = microdump_unique_info_ext_by_page(ptr, start, size, info);
	microdump_unique_info_ext(ptr, start, size, info);
	return by_page;
}

static void dump_page_data(unsigned long ptr, int nr_page, struct microdump_page_info *info)
{
	unsigned long addr = ptr;
	int by_page;
	int start = 0;
	int size = 0;
	int pages;
	struct microdump_page_info *pre_info_priv = NULL;
	struct microdump_page_info info_priv;

	memset_s(&info_priv, sizeof(info_priv), 0, sizeof(info_priv));
	if (info) {
		pre_info_priv = info;
	} else {
		pre_info_priv = &info_priv;
		microdump_addr_page_info(addr, pre_info_priv);
	}

	by_page = microdump_unique_info(ptr, &start, &size, pre_info_priv);
	if (pre_info_priv->type == TYPE_NONE)
		return;
	if (!page_has_dump(addr)) {
		mem_save_dump(addr, nr_page * PAGE_SIZE);
		nr_page = (nr_page > TASK_MULTIPLE_PAGE_SIZE) ? TASK_MULTIPLE_PAGE_SIZE : nr_page;
		pages = nr_page;
		do {
			if (!microdump_check_addr_valid(addr)) {
				break;
			}

			addr += PAGE_SIZE;
		} while (--nr_page > 0);

		g_exp_ctrl.print_func(ptr & PAGE_ALIGN_MASK, (pages - nr_page) * PAGE_SIZE, pre_info_priv);
	} else {
		MD_PRINT("addr %lx has dumped\n", ptr);
	}
}

static void dump_byte_data(unsigned long ptr, int before_byte, int nr_byte, struct microdump_page_info *info)
{
	unsigned long addr = ptr;
	int align_bytes;

	if (microdump_check_addr_valid(addr - before_byte)) {
		addr -= before_byte;
		nr_byte += before_byte;
		align_bytes = addr % LINE_SIZE;
		addr =  addr & LINE_ALIGN_MASK;
	} else {
		MD_PRINT("previous page is invalid, print it from the start of this page");
		addr = addr & PAGE_ALIGN_MASK;
		align_bytes = (addr % PAGE_SIZE);
	}

	// real length
	nr_byte += align_bytes;
	align_bytes = (addr % PAGE_SIZE);

	if (!microdump_check_addr_valid(addr + nr_byte)) {
		MD_PRINT("next page is invalid, print it to the end of the last valid page");
		while (!microdump_check_addr_valid(addr + nr_byte)) {
			if (nr_byte + align_bytes > PAGE_SIZE) {
				nr_byte -= PAGE_SIZE;
			}
		}

		align_bytes = PAGE_SIZE - ((addr + nr_byte) % PAGE_SIZE);
		nr_byte += align_bytes;
	} else {
		// align tail
		align_bytes = LINE_SIZE - ((addr + nr_byte) % LINE_SIZE);
		nr_byte += align_bytes;
	}

	if (!bytes_has_dump(addr, nr_byte)) {
		mem_save_dump(addr, nr_byte);
		g_exp_ctrl.print_func(addr, nr_byte, info);
	} else {
		MD_PRINT("dump_page addr %lx is invalid\n", ptr);
	}
}


void microdump_page_dump_checked(unsigned long ptr, int nr_page, struct microdump_page_info *info)
{
	dump_page_data(ptr, nr_page, info);
}

void microdump_page_dump(unsigned long ptr, int nr_page, struct microdump_page_info *info)
{
	if (!microdump_check_addr_valid(ptr)) {
		MD_PRINT("dump_page check addr %lx is invalid\n", ptr);
		return;
	}

	dump_page_data(ptr, nr_page, info);
}

void microdump_byte_dump_checked(unsigned long ptr, int before_byte, int nr_byte,
	struct microdump_page_info *info)
{
	unsigned long addr = ptr;
	int by_page;
	int start = 0;
	int size = 0;
	struct microdump_page_info *pre_info_priv = NULL;
	struct microdump_page_info info_priv;

	if (info) {
		pre_info_priv = info;
	} else {
		memset_s(&info_priv, sizeof(info_priv), 0, sizeof(info_priv));
		pre_info_priv = &info_priv;
		microdump_addr_page_info(addr, pre_info_priv);
	}

	by_page = microdump_unique_info(ptr, &start, &size, pre_info_priv);

	if (pre_info_priv->type == TYPE_NONE)
		return;

	if (by_page) {
		dump_page_data(ptr, size / PAGE_SIZE, pre_info_priv);
	} else {
		nr_byte = (nr_byte > size) ? nr_byte : size;
		before_byte = (before_byte > start) ? before_byte : start;
		dump_byte_data(ptr, before_byte, nr_byte, info);
	}
}
