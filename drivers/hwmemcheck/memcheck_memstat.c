/*
 * memcheck_memstat.c
 *
 * provide memstat information to user space to determine if leak happens
 *
 * Copyright (c) 2020 Honor Device Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "memcheck_common.h"
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/mm_inline.h>
#include <linux/swap.h>
#include <linux/swapops.h>
#include <linux/pagemap.h>
#include <linux/version.h>
#include <linux/signal.h>
#if (KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE)
#include <linux/pagewalk.h>
#endif
#if (KERNEL_VERSION(4, 14, 0) <= LINUX_VERSION_CODE)
#include <linux/sched/mm.h>
#include <linux/sched/task.h>
#endif
#include <chipset_common/hwmemcheck/memcheck.h>
#include <chipset_common/mm_track/mm_track.h>
#include <securec.h>

#define PSS_SHIFT	12
#define IDX_JAVA	0
#define IDX_NATIVE	1
#define IDX_MMAP	2
#define IDX_FDTRACK	3
#define ADDR_NUM	4

#define JAVA_TAG	"dalvik-"
#define JAVA_TAG_LEN	7
#define JAVA_TAG2	"maple_alloc_ros"
#define JAVA_TAG2_LEN	15

#define NATIVE_TAG2	"libc_malloc"
#define NATIVE_TAG2_LEN	11

struct memsize_stats {
	unsigned long resident;
	unsigned long swap;
	u64 pss;
	u64 native_rss;
	u64 java_rss;
	u64 mmap_rss;
	u64 vss;
};

enum heap_type {
	HEAP_OTHER,
	HEAP_JAVA,
	HEAP_NATIVE,
	HEAP_MMAP,
};

static char top_slub_name[MEMCHECK_MEM_NAME_MAX];
struct mm_slub_detail_info top_slab_info;
static struct mem_tag g_mmap_tag[MAX_TAG_NUM] = { 0 };
static const char *const java_tag[] = {
	"dalvik-alloc space",
	"dalvik-main space",
	"dalvik-large object space",
	"dalvik-free list large object space",
	"dalvik-non moving space",
	"dalvik-zygote space",
};

static const char *const native_tag[] = {
	"scudo",
	"GWP-ASan",
};

static u64 g_addr_array[][ADDR_NUM] = {
	/* MEMCMD_NONE */
	{ 0, 0, 0 },
	/* MEMCMD_ENABLE */
	{ ADDR_JAVA_ENABLE, ADDR_NATIVE_ENABLE, ADDR_MMAP_ENABLE , ADDR_FD_TRACK_ENABLE},
	/* MEMCMD_DISABLE */
	{ ADDR_JAVA_DISABLE, ADDR_NATIVE_DISABLE, ADDR_MMAP_DISABLE , 0 },
	/* MEMCMD_SAVE_LOG */
	{ ADDR_JAVA_SAVE, ADDR_NATIVE_SAVE, ADDR_MMAP_SAVE , 0 },
	/* MEMCMD_CLEAR_LOG */
	{ ADDR_JAVA_CLEAR, ADDR_NATIVE_CLEAR, ADDR_MMAP_CLEAR , 0 },
};

extern void get_top_slub_info(struct mm_slub_detail_info *top_slab_info);

static bool is_java_heap(const char *tag)
{
	int i;
	char *tmp = NULL;

	if (strncmp(tag, JAVA_TAG2, JAVA_TAG2_LEN) == 0)
		return true;

	for (i = 0; i < ARRAY_SIZE(java_tag); i++) {
		tmp = strstr(tag, java_tag[i]);

		if (tmp == tag)
			return true;
	}

	return false;
}

static bool is_native_heap(const char *tag)
{
	int i;
	char *tmp = NULL;

	if (strncmp(tag, NATIVE_TAG2, NATIVE_TAG2_LEN) == 0)
		return true;

	for (i = 0; i < ARRAY_SIZE(native_tag); i++) {
		tmp = strstr(tag, native_tag[i]);
		if (tmp == tag)
			return true;
	}
	return false;
}

static bool is_mmap_heap(const char *tag)
{
	size_t i;
	char *tmp = NULL;

	for (i = 0; i < ARRAY_SIZE(g_mmap_tag); i++) {
		if (strlen(g_mmap_tag[i].name) == 0)
			return false;
		tmp = strstr(tag, g_mmap_tag[i].name);
		if (tmp == tag)
			return true;
	}
	return false;
}

static enum heap_type memcheck_get_heap_type(const char *name)
{
	enum heap_type type = HEAP_OTHER;

	if (!name)
		return type;

	if (is_native_heap(name))
		type = HEAP_NATIVE;
	else if (is_java_heap(name))
		type = HEAP_JAVA;
	else if (is_mmap_heap(name))
		type = HEAP_MMAP;
	return type;
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0))
static struct page **alloc_page_pointers(size_t num)
{
	struct page **page = NULL;
	size_t page_len = sizeof(**page) * num;

	page = kzalloc(page_len, GFP_KERNEL);
	if (!page)
		return ERR_PTR(-ENOMEM);

	return page;
}

static size_t do_strncpy_from_remote_string(char *dst, long page_offset,
					    struct page **page, long num_pin,
					    long count)
{
	long i;
	size_t sz;
	size_t strsz;
	size_t copy_sum = 0;
	long page_left = min((long)PAGE_SIZE - page_offset, count);
	const char *p = NULL;
	const char *kaddr = NULL;

	count = min(count, num_pin * (long)PAGE_SIZE - page_offset);

	for (i = 0; i < num_pin; i++) {
		kaddr = (const char *)kmap(page[i]);
		if (!kaddr)
			break;

		if (i == 0) {
			p = kaddr + page_offset;
			sz = page_left;
		} else {
			p = kaddr;
			sz = min((long)PAGE_SIZE, count - page_left -
				 (i - 1) * (long)PAGE_SIZE);
		}

		strsz = strnlen(p, sz);
		memcpy(dst, p, strsz);

		kunmap(page[i]);

		dst += strsz;
		copy_sum += strsz;

		if (strsz != sz)
			break;
	}

	for (i = 0; i < num_pin; i++)
		put_page(page[i]);

	return copy_sum;

}

static long strncpy_from_remote_user(char *dst, struct mm_struct *remote_mm,
				     const char __user *src, long count)
{
	long num_pin;
	size_t copy_sum;
	struct page **page = NULL;

	uintptr_t src_page_start = (uintptr_t)src & PAGE_MASK;
	uintptr_t src_page_offset = (uintptr_t)(src - src_page_start);
	size_t num_pages = DIV_ROUND_UP(src_page_offset + count,
					(long)PAGE_SIZE);

	page = alloc_page_pointers(num_pages);
	if (IS_ERR_OR_NULL(page))
		return PTR_ERR(page);
#if (KERNEL_VERSION(5, 10, 0) <= LINUX_VERSION_CODE)
	num_pin = get_user_pages_remote(remote_mm,
					src_page_start, num_pages, 0,
					page, NULL, NULL);
#elif (KERNEL_VERSION(4, 14, 0) <= LINUX_VERSION_CODE)
	num_pin = get_user_pages_remote(current, remote_mm,
					src_page_start, num_pages, 0,
					page, NULL, NULL);
#else
	num_pin = get_user_pages_remote(current, remote_mm,
					src_page_start, num_pages, 0,
					page, NULL);
#endif
	if (num_pin < 1) {
		kfree(page);
		return 0;
	}

	copy_sum = do_strncpy_from_remote_string(dst, src_page_offset, page,
						 num_pin, count);
	kfree(page);

	return copy_sum;

}
#endif

enum heap_type memcheck_anon_vma_name(struct vm_area_struct *vma)
{
	enum heap_type type = HEAP_OTHER;
	char *out_name = NULL;
#if (KERNEL_VERSION(5, 15, 0) <= LINUX_VERSION_CODE)
	struct anon_vma_name *anon_name = anon_vma_name(vma);
	out_name = anon_name->name;
#else
	const char __user *name_user = vma_get_anon_name(vma);
	unsigned long max_len = min((unsigned long)NAME_MAX + 1,
				    (unsigned long)PAGE_SIZE);
	long retcpy;

	out_name = kzalloc(max_len, GFP_KERNEL);
	if (!out_name)
		return type;

	retcpy = strncpy_from_remote_user(out_name, vma->vm_mm,
					  name_user, max_len);
	if (retcpy <= 0)
		goto free_name;
#endif
	type = memcheck_get_heap_type(out_name);

#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 15, 0))
free_name:
	kfree(out_name);
#endif

	return type;
}

enum heap_type memcheck_get_type(struct vm_area_struct *vma)
{
	char *name = NULL;
	struct mm_struct *mm = vma->vm_mm;
	enum heap_type type = HEAP_OTHER;
	struct anon_vma_name *anon_name;

	/* file map is never heap in Android Q */
	if (vma->vm_file)
		return type;

	/* get rid of stack */
	if ((vma->vm_start <= vma->vm_mm->start_stack) &&
	    (vma->vm_end >= vma->vm_mm->start_stack))
		return type;

	if ((vma->vm_ops) && (vma->vm_ops->name)) {
		name = (char *)vma->vm_ops->name(vma);
		if (name)
			goto got_name;
	}

	name = (char *)arch_vma_name(vma);
	if (name)
		goto got_name;

	/* get rid of vdso */
	if (!mm)
		return type;

	/* main thread native heap */
	if ((vma->vm_start <= mm->brk) && (vma->vm_end >= mm->start_brk))
		return HEAP_NATIVE;

	anon_name = anon_vma_name(vma);
	if (anon_name)
		return memcheck_anon_vma_name(vma);

got_name:
	return memcheck_get_heap_type(name);
}

static void memcheck_pte_entry(pte_t *pte, unsigned long addr,
			       struct mm_walk *walk)
{
	struct memsize_stats *mss = walk->private;
	struct vm_area_struct *vma = walk->vma;
	struct page *page = NULL;

	if (pte_present(*pte)) {
		page = vm_normal_page(vma, addr, *pte);
	} else if (is_swap_pte(*pte)) {
		swp_entry_t swpent = pte_to_swp_entry(*pte);

		if (!non_swap_entry(swpent))
			mss->swap += PAGE_SIZE;
		else if (is_migration_entry(swpent))
			page = pfn_swap_entry_to_page(swpent);
	}
	if (page)
		mss->resident += PAGE_SIZE;
}

static int memcheck_pte_range(pmd_t *pmd, unsigned long addr,
			      unsigned long end, struct mm_walk *walk)
{
	struct vm_area_struct *vma = walk->vma;
	pte_t *pte = NULL;
	spinlock_t *ptl = NULL;

#ifdef CONFIG_TRANSPARENT_HUGEPAGE
	ptl = pmd_trans_huge_lock(pmd, vma);
	if (ptl) {
		memcheck_info("pmd_trans_huge_lock pmd=%p.\n", pmd);
		spin_unlock(ptl);
		cond_resched();
		return 0;
	}

	if (pmd_trans_unstable(pmd)) {
		memcheck_info("pmd_trans_unstable pmd=%p.\n", pmd);
		cond_resched();
		return 0;
	}
#endif

	pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
	for (; addr != end; pte++, addr += PAGE_SIZE)
		memcheck_pte_entry(pte, addr, walk);
	pte_unmap_unlock(pte - 1, ptl);

	cond_resched();
	return 0;
}

static int memcheck_get_mss(pid_t pid, struct memsize_stats *mss_total)
{
	struct task_struct *tsk = NULL;
	struct mm_struct *mm = NULL;
	struct vm_area_struct *vma = NULL;
	enum heap_type type;
	struct memsize_stats mss;

#if (KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE)
	struct mm_walk_ops memstat_walk_ops = {
		.pmd_entry = memcheck_pte_range,
	};
	struct mm_walk memstat_walk = {
		.ops = &memstat_walk_ops,
		.private = &mss,
	};
#else
	struct mm_walk memstat_walk = {
		.pmd_entry = memcheck_pte_range,
		.private = &mss,
	};
#endif

	rcu_read_lock();
	tsk = find_task_by_vpid(pid);
	if (tsk)
		get_task_struct(tsk);
	rcu_read_unlock();
	if (!tsk)
		return -EINVAL;

	mm = get_task_mm(tsk);
	if (!mm) {
		put_task_struct(tsk);
		return -EINVAL;
	}

	memset(mss_total, 0, sizeof(*mss_total));

#if (KERNEL_VERSION(5, 10, 0) <= LINUX_VERSION_CODE)
	mmap_read_lock(mm);
#else
	down_read(&mm->mmap_sem);
#endif
	vma = mm->mmap;
	while (vma) {
		memset(&mss, 0, sizeof(mss));
		memstat_walk.mm = vma->vm_mm;
		if ((vma->vm_mm) && (!is_vm_hugetlb_page(vma))) {
#if (KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE)
			walk_page_range(memstat_walk.mm, vma->vm_start, vma->vm_end,
					memstat_walk.ops, memstat_walk.private);
#else
			walk_page_range(vma->vm_start, vma->vm_end,
					&memstat_walk);
#endif

			/* simply add swap to resident to get a total rss */
			mss.resident += mss.swap;
			mss_total->resident += mss.resident;
			mss_total->vss += vma->vm_end - vma->vm_start;

			type = memcheck_get_type(vma);
			if (type == HEAP_JAVA)
				mss_total->java_rss += mss.resident;
			else if (type == HEAP_NATIVE)
				mss_total->native_rss += mss.resident;
			else if (type == HEAP_MMAP)
				mss_total->mmap_rss += mss.resident;
		}
		vma = vma->vm_next;
	}
#if (KERNEL_VERSION(5, 10, 0) <= LINUX_VERSION_CODE)
	mmap_read_unlock(mm);
#else
	up_read(&mm->mmap_sem);
#endif
	mmput(mm);
	put_task_struct(tsk);
	return 0;
}

static void memcheck_set_tags(const void *buf, u16 num)
{
	size_t size;
	size_t i;
	errno_t err;
	struct memstat_all *mem_stat_ptr = NULL;
	if ((!buf) || num > MAX_TAG_TYPE_NUM) {
		memcheck_err("memtag param illegal or buf is null, num is %d!", num);
		return;
	}

	size = sizeof(struct memstat_all) + sizeof(struct mem_tag_info) * num;
	mem_stat_ptr = kvmalloc(size, __GFP_ZERO);
	if (!mem_stat_ptr) {
		memcheck_err("memstat_all malloc failed!");
		return;
	}
	if (copy_from_user(mem_stat_ptr, buf, size)) {
		memcheck_err("copy_from_user failed\n");
		kvfree(mem_stat_ptr);
		return;
	}
	for (i = 0; i < num; i++) {
		if (mem_stat_ptr->tag_list[i].type == IDX_MMAP) {
			err = memcpy_s(g_mmap_tag, sizeof(g_mmap_tag), mem_stat_ptr->tag_list[i].tag_body,
				sizeof(mem_stat_ptr->tag_list[i].tag_body));
			if (err != EOK) {
				memcheck_err("memcpy_s failed, err = %d\n", err);
				kvfree(mem_stat_ptr);
				return;
			}
		}
	}
	kvfree(mem_stat_ptr);
}

unsigned short memcheck_get_memstat(const void *buf, struct memstat_all *p)
{
	int ret;
	unsigned int i;
	struct memsize_stats mss_total;
	unsigned short result = 0;

	/* get userspace memstat */
	if ((p->type & MTYPE_USER_PSS) || (p->type & MTYPE_USER_VSS)) {
		memset(&mss_total, 0, sizeof(mss_total));
		if (strlen(g_mmap_tag[0].name) == 0 && p->tag_type_num > 0) {
			memcheck_set_tags(buf, p->tag_type_num);
		}

		/* read the smaps */
		ret = memcheck_get_mss(p->id, &mss_total);
		if (!ret) {
			if (p->type & MTYPE_USER_PSS_JAVA) {
				p->pss.java_pss = mss_total.java_rss;
				result = result | MTYPE_USER_PSS_JAVA;
			}
			if (p->type & MTYPE_USER_PSS_NATIVE) {
				p->pss.native_pss = mss_total.native_rss;
				result = result | MTYPE_USER_PSS_NATIVE;
			}
			if (p->type & MTYPE_USER_PSS_MMAP) {
				p->mmap_pss = mss_total.mmap_rss;
				result = result | MTYPE_USER_PSS_MMAP;
			}
			if (p->type & MTYPE_USER_PSS)
				p->total_pss = mss_total.resident;
			if (p->type & MTYPE_USER_VSS) {
				p->vss = mss_total.vss;
				result = result | MTYPE_USER_VSS;
			}
		}
	}
	if (p->type & MTYPE_USER_ION) {
		p->ion_pid = get_ion_by_pid(p->id);
		if (p->ion_pid)
			result = result | MTYPE_USER_ION;
	}

	if (!(p->type & MTYPE_KERNEL))
		return result;

	/* get kernel memstat */
	for (i = 0; i < NUM_KERN_MAX; i++) {
		if (TEST_BIT(p->type, i + IDX_KERN_START)) {
			p->memory = get_mem_total(i);
			if (p->memory) {
				result |= (1 << (i + IDX_KERN_START));
				break;
			}
		}
	}
	return result;
}

static bool process_disappear(u64 t, const struct track_cmd *cmd)
{
	if (cmd->cmd == MEMCMD_ENABLE)
		return false;
	if (cmd->timestamp != nsec_to_clock_t(t))
		return true;

	return false;
}

void memcheck_save_top_slub(const char *name)
{
	memcpy(top_slub_name, name, sizeof(top_slub_name));
}

char *memcheck_get_top_slub(void)
{
	return top_slub_name;
}

int memcheck_do_kernel_command(const struct track_cmd *cmd)
{
	int ret = 0;

	switch (cmd->cmd) {
	case MEMCMD_ENABLE:
		if (cmd->type == MTYPE_KERN_SLUB) {
			if (strlen(cmd->sample_info.mem_name) != 0) {
				memcheck_info("given slub is %s\n", cmd->sample_info.mem_name);
				memcheck_save_top_slub(cmd->sample_info.mem_name);
			} else {
				get_top_slub_info(&top_slab_info);
				memcheck_save_top_slub(top_slab_info.name);
				memcheck_info("top slub is %s\n", top_slab_info.name);
			}
			if (strlen(top_slub_name) == 0) {
				memcheck_err("no invalid slub name to track\n");
				return -EINVAL;
			}
			memcheck_info("start to track slub: %s\n", top_slub_name);
			ret = mm_track_on(SLUB_TRACK, top_slub_name);
		} else if (cmd->type == MTYPE_KERN_BUDDY) {
			ret = mm_track_on(BUDDY_TRACK, "buddy");
		} else if (cmd->type == MTYPE_KERN_LSLUB) {
			ret = mm_track_on(LSLUB_TRACK, "lsub");
		}
		if (ret)
			memcheck_err("trace on failed, memtype=%d\n",
					cmd->type);
		else
			memcheck_info("trace on success, memtype=%d\n",
					cmd->type);
		break;
	case MEMCMD_DISABLE:
		if (cmd->type == MTYPE_KERN_SLUB)
			ret = mm_track_off(SLUB_TRACK, top_slub_name);
		else if (cmd->type == MTYPE_KERN_BUDDY)
			ret = mm_track_off(BUDDY_TRACK, "buddy");
		else if (cmd->type == MTYPE_KERN_LSLUB)
			ret = mm_track_off(LSLUB_TRACK, "lsub");
		if (ret)
			memcheck_err("trace off failed, memtype=%d\n",
					cmd->type);
		else
			memcheck_info("trace off success, memtype=%d\n",
					cmd->type);
		break;
	case MEMCMD_SAVE_LOG:
		break;
	case MEMCMD_CLEAR_LOG:
		break;
	default:
		break;
	}

	return ret;
}

int memcheck_do_command(const struct track_cmd *cmd)
{
	int ret = 0;
	struct task_struct *p = NULL;
#if (KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE)
	struct kernel_siginfo info = { 0 };
#else
	struct siginfo info = { 0 };
#endif
	u64 addr = 0;
	bool is_java = (cmd->type & MTYPE_USER_PSS_JAVA) ? true : false;
	bool is_native = (cmd->type & MTYPE_USER_PSS_NATIVE) ? true : false;
	bool is_mmap = (cmd->type & MTYPE_USER_PSS_MMAP) ? true : false;
	bool is_fdtrack = (cmd->type & MTYPE_USER_PSS_FDTRACK) ? true : false;

	if (cmd->type & MTYPE_KERNEL)
		return memcheck_do_kernel_command(cmd);

	if (is_native && is_mmap) {
		memcheck_err("invalid type=%d\n", cmd->type);
		return -EFAULT;
	}
	memset(&info, 0, sizeof(info));
	info.si_signo = SIGNO_MEMCHECK;
	info.si_errno = 0;
	info.si_code = SI_TKILL;
	info.si_pid = task_tgid_vnr(current);
	info.si_uid = from_kuid_munged(current_user_ns(), current_uid());

	rcu_read_lock();
	p = find_task_by_vpid(cmd->id);
	if (p)
		get_task_struct(p);
	rcu_read_unlock();

	if (p && (task_tgid_vnr(p) == cmd->id)) {
#if (KERNEL_VERSION(5, 10, 0) <= LINUX_VERSION_CODE)
		u64 start_boottime = p->start_boottime;
#else
		u64 start_boottime = p->real_start_time;
#endif
		if (process_disappear(start_boottime, cmd)) {
			memcheck_err("pid %d disappear\n", cmd->id);
			ret = MEMCHECK_PID_INVALID;
			goto err_pid_disappear;
		}

		if (is_java) {
			addr = g_addr_array[cmd->cmd][IDX_JAVA];
			if (cmd->cmd == MEMCMD_ENABLE)
				info.si_int = (cmd->sample_info.param.full_threshold << SIGNO_VALUE_SHIFT) | cmd->sample_info.param.rate;
		}
		if (is_native)
			addr |= g_addr_array[cmd->cmd][IDX_NATIVE];

		if (is_mmap)
			addr |= g_addr_array[cmd->cmd][IDX_MMAP];

		if (is_fdtrack)
			addr |= g_addr_array[cmd->cmd][IDX_FDTRACK];

		info.si_addr = (void *)addr;
		if (is_java || is_native || is_mmap || is_fdtrack)
			ret = do_send_sig_info(SIGNO_MEMCHECK, &info, p, false);
	}

err_pid_disappear:
	if (p)
		put_task_struct(p);
	if ((!ret) && (cmd->cmd == MEMCMD_SAVE_LOG))
		memcheck_wait_stack_ready(cmd->type);
	else if ((!ret) && (cmd->cmd == MEMCMD_CLEAR_LOG))
		memcheck_stack_clear();

	return ret;
}
