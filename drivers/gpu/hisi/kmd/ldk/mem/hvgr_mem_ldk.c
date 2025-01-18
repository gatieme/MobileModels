/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: Override some interfaces in kernel/oh-ldk/drivers/gpu/hisi/kmd/mem
 * Author: Huawei OS Kernel Lab
 * Create: Thur Oct 19 14:59:26 2023
 */

#include <linux/mman.h>
#include <linux/vmalloc.h>
#include <linux/rwsem.h>
#include <linux/mm.h>
#include <linux/delay.h>
#include <linux/bitops.h>
#include <linux/rcupdate.h>

#include "hvgr_dm_api.h"
#include "hvgr_mem_opts.h"
#include "hvgr_log_api.h"

#define PFN_ARRAY_SIZE 256

long hvgr_mem_setup_cpu_mmu(struct vm_area_struct *vma, struct hvgr_setup_cpu_mmu_paras *paras)
{
	int ret;
	uint32_t idx;
	uint32_t index = 0;
	struct pfn_range array[PFN_ARRAY_SIZE];
	struct page **pages = paras->page_array;
	uint64_t page_nums = paras->page_nums;
	unsigned long addr = paras->addr;
	unsigned long addr_start = addr;

	for (idx = 0; idx < page_nums; idx++) {
		if (unlikely(pages[idx] == NULL)) {
			pr_err("insert pages page_%u is NULL", idx);
			goto error;
		}

		if (index >= PFN_ARRAY_SIZE) {
			ret = remap_pfn_range_batch(vma, addr_start, array, index, paras->vm_page_prot);
			if (ret != 0) {
				pr_err("insert pages vm insert pfn fail %d", ret);
				goto error;
			}
			index = 0;
			addr_start = addr;
		}

		array[index].start = page_to_pfn(pages[idx]);
		array[index].end = page_to_pfn(pages[idx]) + 1;
		index++;
		addr += PAGE_SIZE;
	}

	if (index > 0) {
		ret = remap_pfn_range_batch(vma, addr_start, array, index, paras->vm_page_prot);
		if (ret != 0) {
			pr_err("insert pages vm insert pfn fail %d", ret);
			goto error;
		}
	}
	return 0;

error:
	if (addr_start > paras->addr)
		zap_vma_ptes(vma, paras->addr, addr_start - paras->addr);
	return -1;
}

vm_fault_t hvgr_mem_vm_fault(struct vm_fault *vmf)
{
	vm_fault_t ret;
	struct hvgr_mem_area *area = NULL;
	struct vm_area_struct *vma = vmf->vma;
	uint32_t page_offset;
	uint64_t insert_addr;
	phys_addr_t phys;
	struct hvgr_device *gdev = hvgr_get_device();
	struct pfn_range array[PFN_ARRAY_SIZE];
	int index = 0;
	unsigned long addr_start;

	if (gdev == NULL)
		return VM_FAULT_SIGBUS;

	area = (struct hvgr_mem_area *)vma->vm_private_data;
	if (area == NULL) {
		pr_err("vm fault addr 0x%lx no area", vmf->address);
		return VM_FAULT_SIGBUS;
	}

	hvgr_info(gdev, HVGR_MEM, "vm fault addr 0x%lx, prot=%lu:0x%lx, page:%lu/%lu uva/gva=0x%lx",
		vmf->address, area->property, area->attribute, area->pages,
		area->max_pages, area->gva);

	if ((area->property != HVGR_MEM_PROPERTY_SAME_VA &&
		area->property != HVGR_MEM_PROPERTY_IMPORT) ||
		(area->attribute & HVGR_MEM_MASK_UMD_ACCESS) == 0) {
		hvgr_err(gdev, HVGR_MEM, "vm fault addr 0x%lx area property %lu 0x%lx error",
			vmf->address, area->property, area->attribute);
		return VM_FAULT_SIGBUS;
	}

	page_offset = (uint32_t)((vmf->address - area->uva) >> PAGE_SHIFT);
	if (page_offset >= area->pages) {
		hvgr_err(gdev, HVGR_MEM, "vm fault addr 0x%lx out of area 0x%lx size 0x%lx",
			vmf->address, area->uva, area->pages);
		return VM_FAULT_SIGBUS;
	}

	mutex_lock(&area->mutex);
	if (atomic_read(&area->import.data.umm.free_tlb_cnt) != 0) {
		hvgr_err(gdev, HVGR_MEM,
			"dma buffer page was freed, do not allow memory growable");
		mutex_unlock(&area->mutex);
		return VM_FAULT_SIGBUS;
	}

	insert_addr = vmf->address & PAGE_MASK;
	addr_start = vmf->address & PAGE_MASK;
	while (page_offset < area->pages && insert_addr < vma->vm_end) {
		if (index >= PFN_ARRAY_SIZE) {
			ret = vmf_insert_pfn_batch(vma, addr_start, array, (unsigned long)index);
			if (ret != VM_FAULT_NOPAGE) {
				hvgr_err(gdev, HVGR_MEM, "vm fault addr 0x%lx insert addr 0x%lx fail %d\n",
					vmf->address, insert_addr, (int)ret);
				mutex_unlock(&area->mutex);
				return ret;
			}
			index = 0;
			addr_start = insert_addr;
		}
#ifdef HVGR_FEATURE_SYSTEM_CACHE
		if (hvgr_sc_vm_insert_pfn_prot(&area->page_array[page_offset], 1,
			&vma->vm_page_prot) != 0) {
			hvgr_err(gdev, HVGR_MEM,
				"vm fault addr 0x%lx sc insert addr 0x%lx fail",
				vmf->address, insert_addr);
			mutex_unlock(&area->mutex);
			return VM_FAULT_SIGBUS;
		}
#endif
		phys = page_to_phys(area->page_array[page_offset]);
		array[index].start = PFN_DOWN(phys);
		array[index].end = array[index].start + 1;
		index++;
		page_offset++;
		insert_addr += PAGE_SIZE;
		gdev->mem_dev.statics.grow_pages++;
	}

	if (index > 0) {
			ret = vmf_insert_pfn_batch(vma, addr_start, array, (unsigned long)index);
			if (ret != VM_FAULT_NOPAGE) {
				hvgr_err(gdev, HVGR_MEM, "vm fault addr 0x%lx insert addr 0x%lx fail %d\n",
					vmf->address, insert_addr, (int)ret);
				mutex_unlock(&area->mutex);
				return ret;
			}
	}

	mutex_unlock(&area->mutex);
	return VM_FAULT_NOPAGE;
}