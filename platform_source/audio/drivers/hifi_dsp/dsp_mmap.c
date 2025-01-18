/*
 * dsp mmap.c
 *
 * dsp mmap driver.
 *
 * Copyright (c) 2023 Huawei Technologies Co., Ltd.
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

#include "dsp_mmap.h"
#include "dsp_misc.h"

#include <linux/mutex.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/dma-mapping.h>
#include <asm/memory.h>

#include "audio_hifi.h"
#include "drv_mailbox_msg.h"
#include "bsp_drv_ipc.h"
#include "dsp_om.h"
#include "om_debug.h"

#include <linux/mm_lb/mm_lb.h>
#include "dsp_msg.h"
#include "platform_base_addr_info.h"
#include "audio_common_msg.h"
#include "audio_ddr_map.h"
#include "audio_pcm_ddr_map.h"

#define HVS_DATA_SIZE (18 * 1024 * 1024)
#define HVS_PARAM_SIZE (7 * 1024 * 1024 + 1024 * 512)
#define HVS_MMAP_OFFSET PAGE_SIZE

enum dsp_mmap_type {
	DSP_MMAP_TYPE_BASE,
	DSP_MMAP_TYPE_OFFLOAD,
	DSP_MMAP_TYPE_BUTT
};

struct dsp_mmap_info {
	unsigned long size;
	unsigned long offset;
	int ref_cnt;

	unsigned char *virt;
	uintptr_t phy;
	unsigned long malloc_size;
	bool is_mmaped;

	uintptr_t (*init_buf)(struct dsp_mmap_info *map_info);
	void (*deinit_buf)(struct dsp_mmap_info *map_info);
};

struct dsp_misc_mmap {
	struct device *dev;
	struct mutex mmap_mutex;
	struct dsp_mmap_info mmap_list[DSP_MMAP_TYPE_BUTT];
};

static struct dsp_misc_mmap g_dsp_mmap;

static uintptr_t base_buf_init(struct dsp_mmap_info *map_info)
{
	return map_info->phy;
}

static void base_buf_deinit(struct dsp_mmap_info *map_info)
{
	map_info->is_mmaped = false;
}

unsigned long dsp_misc_get_phys(void)
{
	struct dsp_mmap_info *map_info = &g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_OFFLOAD];

	if (map_info->phy == 0)
		return (unsigned long)((uintptr_t)g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_BASE].phy - DSP_UNSEC_BASE_ADDR);

	return (unsigned long)(map_info->phy - CMA_UNSEC_BASE_ADDR);
}

static uintptr_t cma_buf_init(struct dsp_mmap_info *map_info)
{
	dma_addr_t dma_handle;

	if (map_info->virt != NULL || map_info->phy != 0 || map_info->is_mmaped) {
		logw("dsp_mmap cma memory already mmaped, not map again\n");
		return 0;
	}

	map_info->virt = dma_alloc_coherent(g_dsp_mmap.dev,
		map_info->malloc_size, &dma_handle, GFP_KERNEL);
	if (map_info->virt == NULL) {
		loge("dsp_mmap cma memory alloc err\n");
		return 0;
	}

	map_info->phy = (uintptr_t)dma_handle;
	logi("dsp_mmap cma buffer alloc %lu success\n", map_info->malloc_size);
	return map_info->phy;
}

static void cma_buf_deinit(struct dsp_mmap_info *map_info)
{
	if (map_info->virt == NULL || map_info->phy == 0) {
		logw("dsp_mmap pcm offload buf is already free\n");
		return;
	}

	dma_free_coherent(g_dsp_mmap.dev, map_info->malloc_size,
		map_info->virt, map_info->phy);
	map_info->phy = 0;
	map_info->virt = NULL;
	map_info->is_mmaped = false;
	logi("dsp_mmap cma buffer release %lu success\n", map_info->malloc_size);
}

int dsp_misc_spatial_audio_proc_sync(const void *para_in, unsigned int para_size_in)
{
	loge("hvs unspport proc\n");
	return ERROR;
}

static struct dsp_mmap_info* get_mmap_info(unsigned long offset, unsigned long size)
{
	int i;
	struct dsp_mmap_info *map_info = NULL;

	for (i = 0; i < DSP_MMAP_TYPE_BUTT; i++) {
		map_info = &g_dsp_mmap.mmap_list[i];
		if (map_info->offset == offset && map_info->size == size) {
			logi("type %d, offset %lu, size %lu \n", i, offset, size);
			return map_info;
		}
	}
	return NULL;
}

static void dsp_vma_open(struct vm_area_struct *vma)
{
	struct dsp_mmap_info *map_info = NULL;

	if (vma == NULL || vma->vm_private_data == NULL)
		return;

	mutex_lock(&g_dsp_mmap.mmap_mutex);
	map_info = (struct dsp_mmap_info *)vma->vm_private_data;
	map_info->ref_cnt++;
	mutex_unlock(&g_dsp_mmap.mmap_mutex);

	logi("dsp_mmap vma open size %lu offset %lu ref:%d\n", map_info->size, map_info->offset, map_info->ref_cnt);
}

static void dsp_vma_close(struct vm_area_struct *vma)
{
	struct dsp_mmap_info *map_info = NULL;

	if (vma == NULL || vma->vm_private_data == NULL)
		return;

	mutex_lock(&g_dsp_mmap.mmap_mutex);
	map_info = (struct dsp_mmap_info *)vma->vm_private_data;
	if (map_info->ref_cnt > 0) {
		map_info->ref_cnt--;
		if (map_info->ref_cnt == 0)
			map_info->deinit_buf(map_info);
	} else {
		logw("dsp_mmap vma close ref err:%d\n", map_info->ref_cnt);
	}
	mutex_unlock(&g_dsp_mmap.mmap_mutex);

	logi("dsp_mmap vma close size %lu offset %lu ref:%d\n", map_info->size, map_info->offset, map_info->ref_cnt);
}

static const struct vm_operations_struct dsp_vm_ops = {
	.open = dsp_vma_open,
	.close = dsp_vma_close,
};

int dsp_misc_mmap_common(struct file *file, struct vm_area_struct *vma, unsigned long offset)
{
	unsigned long size;
	uintptr_t phys = 0;
	struct dsp_mmap_info *map_info = NULL;
	int ret;

	if (!vma) {
		logi("input error: vma is NULL\n");
		return ERROR;
	}

	size = ((unsigned long)vma->vm_end - (unsigned long)vma->vm_start);
	logi("dsp_mmap common map size %lu offset %lu\n", size, offset);

	mutex_lock(&g_dsp_mmap.mmap_mutex);
	map_info = get_mmap_info(offset, size);
	if (!map_info) {
		mutex_unlock(&g_dsp_mmap.mmap_mutex);
		loge("map_info is NULL\n");
		return ERROR;
	}

	phys = map_info->init_buf(map_info);
	if (phys == 0) {
		mutex_unlock(&g_dsp_mmap.mmap_mutex);
		loge("dsp_mmap get phys buffer fail, size: %lu\n", size);
		return -ENOMEM;
	}

	vma->vm_page_prot = pgprot_writecombine(PAGE_SHARED);
	ret = remap_pfn_range(vma, vma->vm_start, __phys_to_pfn(phys), size, vma->vm_page_prot);
	if (ret != 0) {
		map_info->deinit_buf(map_info);
		mutex_unlock(&g_dsp_mmap.mmap_mutex);
		loge("dsp_mmap remap pfn range ret %d\n", ret);
		return -ENOMEM;
	}

	vma->vm_ops = &dsp_vm_ops;
	vma->vm_private_data = (void *)map_info;

	map_info->is_mmaped = true;
	map_info->ref_cnt++;
	mutex_unlock(&g_dsp_mmap.mmap_mutex);

	return ret;
}

int dsp_misc_mmap(struct file *file, struct vm_area_struct *vma)
{
	unsigned long offset = 0;

	if (!vma) {
		logi("input error: vma is NULL\n");
		return ERROR;
	}

	offset = vma->vm_pgoff << PAGE_SHIFT;
	return dsp_misc_mmap_common(file, vma, offset);
}

void dsp_misc_mmap_probe(struct platform_device *pdev, uintptr_t base_phy)
{
	memset(&g_dsp_mmap, 0, sizeof(g_dsp_mmap));

	g_dsp_mmap.dev = &pdev->dev;
	mutex_init(&g_dsp_mmap.mmap_mutex);

	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_BASE].size = DSP_MUSIC_DATA_SIZE;
	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_BASE].init_buf = base_buf_init;
	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_BASE].deinit_buf = base_buf_deinit;
	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_BASE].phy = base_phy;

	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_OFFLOAD].size = MEM_CMA_RESERVE_MUSIC_DATA_SIZE;
	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_OFFLOAD].malloc_size = MEM_CMA_RESERVE_MUSIC_DATA_SIZE;
	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_OFFLOAD].init_buf = cma_buf_init;
	g_dsp_mmap.mmap_list[DSP_MMAP_TYPE_OFFLOAD].deinit_buf = cma_buf_deinit;


}

void dsp_misc_mmap_remove(void)
{
	int i;
	struct dsp_mmap_info *map_info = NULL;

	mutex_lock(&g_dsp_mmap.mmap_mutex);
	for (i = 0; i < DSP_MMAP_TYPE_BUTT; i++) {
		map_info = &g_dsp_mmap.mmap_list[i];
		map_info->deinit_buf(map_info);
	}
	mutex_unlock(&g_dsp_mmap.mmap_mutex);

	mutex_destroy(&g_dsp_mmap.mmap_mutex);
	memset(&g_dsp_mmap, 0, sizeof(g_dsp_mmap));
}

