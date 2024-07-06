/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_mem_sc_hal.h"

#include <linux/kernel.h>
#include <linux/version.h>
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#include <linux/hisi/mm_lb.h>
#else
#include <linux/mm_lb/mm_lb.h>
#endif
#include <linux/of.h>
#include <linux/slab.h>
#include <securec.h>

#include "hvgr_log_api.h"

#define SC_GID_NUM 3u

/* used for config gid override\qos override\schint override */
#define GPU_CTRL_P0_8_ADDR_OFFSET               0x020u
#define GPU_CTRL_P0_8_ADDR_VALUE                0x4u
/* used for mapping policy index[0-7] to gid register */
#define GPU_CTRL_P0_25_ADDR_OFFSET              0x06Cu
#define GPU_CTRL_P0_25_ADDR_VALUE               0x02200000u
/* used for mapping policy index[8-15] to gid register  */
#define GPU_CTRL_P0_26_ADDR_OFFSET              0x070u
#define GPU_CTRL_P0_26_ADDR_VALUE               0x33333000u
/* used for config the policy index[0-7] read policy */
#define GPU_CTRL_P0_27_ADDR_OFFSET              0x074u
#define GPU_CTRL_P0_27_ADDR_VALUE               0x09900000u
/* used for config the policy index[8-15] read policy */
#define GPU_CTRL_P0_28_ADDR_OFFSET              0x078u
#define GPU_CTRL_P0_28_ADDR_VALUE               0x998b8000u
/* used for config the policy index[0-7] write policy */
#define GPU_CTRL_P0_29_ADDR_OFFSET              0x07Cu
#define GPU_CTRL_P0_29_ADDR_VALUE               0x09800000u
/* used for config the policy index[8-15] write policy */
#define GPU_CTRL_P0_30_ADDR_OFFSET              0x080u
#define GPU_CTRL_P0_30_ADDR_VALUE               0x98998000u

#define SC_IDX_NUM                              16
#define SC_GID_MAX_VALUE                        8u

#define hvgr_sc_max_bytes(v)    ((((v) >> 16) & 0x7fffu) * 128u)

static const int sc_policy_idx_to_id_remap[SC_IDX_NUM] =
	{0, 2, 2, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0};

/* under noremp, umd can use sc_id 2/3/6  */
static const int sc_policy_idx_to_id_noremap[SC_IDX_NUM] =
	{0, 3, 2, 3, 3, 3, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3};

static bool sc_gid_remap_en = false;

static void kmd_sc_deinit_policy(struct list_head *node)
{
	struct hvgr_sc_policy_info *info = NULL;

	if (node == NULL)
		return;

	list_del(node);
	info = container_of(node, struct hvgr_sc_policy_info, node);
	kfree(info);
}

static void hvgr_sc_deinit_policy_list(struct list_head *head)
{
	struct list_head *node = NULL;
	struct list_head *next = NULL;

	if (head == NULL || list_empty(head))
		return;

	node = head->next;
	while (node != head) {
		next = node->next;
		kmd_sc_deinit_policy(node);
		node = next;
	};

	INIT_LIST_HEAD(head);
}

static int hvgr_sc_init_policy_list(struct hvgr_device * const gdev, struct list_head *head)
{
	int ret;
	uint32_t sc_gids[SC_GID_NUM] = {0};
	uint32_t i;
	struct hvgr_sc_policy_info *info = NULL;

	ret = of_property_read_u32_array(gdev->dev->of_node, "sc-gids", sc_gids, SC_GID_NUM);
	if (ret) {
		hvgr_err(gdev, HVGR_MEM, "There is no sc-gids cfg");
		return -EINVAL;
	}

	for (i = 0; i < SC_GID_NUM; i++) {
		info = kzalloc(sizeof(*info), GFP_KERNEL);
		if (info == NULL)
			goto failed;
		INIT_LIST_HEAD(&info->node);

		info->policy_id = sc_gids[i];
		info->sc_gid = lb_get_master_policy(info->policy_id, MASTER_GID);
		if (info->sc_gid == 0u) {
			hvgr_err(gdev, HVGR_MEM, "sc policy_id %u get gid %u error",
				info->policy_id, info->sc_gid);
			continue;
		}
		info->cache_policy = lb_get_master_policy(info->policy_id, MASTER_PLC);
		info->cache_quota = lb_get_master_policy(info->policy_id, MASTER_QUOTA);

		hvgr_err(gdev, HVGR_MEM,
			"sc policy_id %u sc_gid %u cache_policy 0x%lx cache_quota 0x%lx",
			info->policy_id, info->sc_gid, info->cache_policy, info->cache_quota);

		list_add(&info->node, head);
	}

	return 0;
failed:
	hvgr_sc_deinit_policy_list(head);
	hvgr_err(gdev, HVGR_MEM, "init policy list fail");
	return -EINVAL;
}

static struct hvgr_sc_policy_info *hvgr_sc_get_policy_info(struct hvgr_device * const gdev, uint32_t gid)
{
	struct list_head *info_node = NULL;
	struct list_head *info_head = NULL;
	struct hvgr_sc_policy_info *info = NULL;

	if (gid > SC_GID_MAX_VALUE)
		return NULL;

	info_head = &gdev->mem_dev.sc_data.policy_info_list;
	list_for_each(info_node, info_head) {
		info = container_of(info_node, struct hvgr_sc_policy_info, node);
		if (info->sc_gid == gid)
			return info;
	}

	hvgr_err(gdev, HVGR_MEM, "The policy with gid %u is not exist", gid);
	return NULL;
}

static void kmd_sc_init_config(struct hvgr_device * const gdev)
{
	int ret;
	struct hvgr_sc_dev_data *sc_data = &gdev->mem_dev.sc_data;
	uint32_t values_buf;

	/* Get page table GID info */
	sc_data->pgd_mem_gid = 0;
	ret = of_property_read_u32(gdev->dev->of_node, "pgd_memory_gid",
		&values_buf);
	if (ret)
		hvgr_info(gdev, HVGR_MEM, "There is no pgd_memory_gid cfg");
	else if (hvgr_sc_get_policy_info(gdev, values_buf))
		sc_data->pgd_mem_gid = values_buf;

	hvgr_err(gdev, HVGR_MEM, "%s pgd_mem_gid:0x%x", __func__, sc_data->pgd_mem_gid);

	/* Get partial stream config */
	ret = of_property_read_u32(gdev->dev->of_node, "sc-partial-stream-cfg",
		&sc_data->sc_ps_cfg);
	if (ret) {
		sc_data->sc_ps_cfg = 0;
		hvgr_info(gdev, HVGR_MEM, "There is no partial stream config");
	}

	hvgr_err(gdev, HVGR_MEM, "%s sc_ps_cfg:0x%x", __func__, sc_data->sc_ps_cfg);

	/* Get StreamID-GID map info */
	ret = of_property_read_u32_array(gdev->dev->of_node, "streamid-gid-map",
		sc_data->sc_streamid_gid_map, HVGR_STREAM_ID_NUMBER);
	if (ret) {
		if (memset_s(sc_data->sc_streamid_gid_map, sizeof(sc_data->sc_streamid_gid_map),
			0, sizeof(sc_data->sc_streamid_gid_map)) != 0)
		hvgr_info(gdev, HVGR_MEM, "There is no stream to gid map");
	}

	sc_data->pbha_mode = 0;
	ret = of_property_read_u32(gdev->dev->of_node, "pbha_mode",
		&sc_data->pbha_mode);
	if (ret == 0 && sc_data->pbha_mode != 0) {
		if (sc_data->pbha_mode != 1)
			dev_warn(gdev->dev, "pbha_mode cfg is irregular\n");
		sc_data->pbha_mode = 1;
	}

	sc_data->pgd_cache_enable = 1;
	sc_data->sc_ps_hebc_only = 1;
	hvgr_err(gdev, HVGR_MEM, "%s pbha_mode:0x%x pgd_cache_enable:0x%x", __func__,
		sc_data->pbha_mode, sc_data->pgd_cache_enable);
}

void hvgr_sc_init(struct hvgr_device * const gdev)
{
	int ret;
	struct hvgr_sc_dev_data *sc_data = &gdev->mem_dev.sc_data;

	INIT_LIST_HEAD(&sc_data->policy_info_list);
	ret = hvgr_sc_init_policy_list(gdev, &sc_data->policy_info_list);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "sc init policy list fail");
		return;
	}

	kmd_sc_init_config(gdev);
}

void hvgr_sc_deinit(struct hvgr_device * const gdev)
{
	struct hvgr_sc_dev_data *sc_data = &gdev->mem_dev.sc_data;

	hvgr_sc_deinit_policy_list(&sc_data->policy_info_list);
}

uint32_t hvgr_sc_id_to_policy_id(uint32_t idx)
{
	if (idx >= SC_IDX_NUM)
		return 0;

	if (sc_gid_remap_en)
		return sc_policy_idx_to_id_remap[idx];
	else
		return sc_policy_idx_to_id_noremap[idx];
}

int hvgr_sc_vm_insert_pfn_prot(struct page **pages, uint32_t page_nr, pgprot_t *prot)
{
	if ((pages == NULL) || (page_nr == 0) || (prot == NULL))
		return -EINVAL;

	/*
	 * L.B intergration: Add page's GID information to vm_page_prot,
	 *                   So SMMU can handle CPU PTE correctly.
	 * 1. Hisi-driver provide the function
	 *    lb_prot_build(struct page*, pgprot_t*)
	 *    to add the GID info in the returned pgprot_t*.
	 *    Like:lb_prot_build(phys_to_page(phys), &vma->vm_page_prot);
	 * 2. Call lb_prot_build() function to get vm_page_prot with GID.
	 */
	/* check pages with same policy id. */
	return lb_prot_build(pages[0], prot);
}

bool hvgr_sc_gid_remap_is_enable(void)
{
	return sc_gid_remap_en;
}

void hvgr_sc_config_remap(struct hvgr_device * const gdev)
{
	/* check the register document for more detail */
	if (gdev->dm_dev.ctrl_reg.reg_base == NULL) {
		hvgr_err(gdev, HVGR_MEM, "the gpu ctrl register is unioremapped");
		return;
	}
	sc_gid_remap_en = true;
	/* value 4 make sure gid override is open */
	writel(GPU_CTRL_P0_8_ADDR_VALUE,
		gdev->dm_dev.ctrl_reg.reg_base + GPU_CTRL_P0_8_ADDR_OFFSET);
	/*
	 * config the relation between gid and policy index as the array:
	 * kmd_sc_gidremap_reg_value
	 */
	writel(GPU_CTRL_P0_25_ADDR_VALUE,
		gdev->dm_dev.ctrl_reg.reg_base + GPU_CTRL_P0_25_ADDR_OFFSET);
	writel(GPU_CTRL_P0_26_ADDR_VALUE,
		gdev->dm_dev.ctrl_reg.reg_base + GPU_CTRL_P0_26_ADDR_OFFSET);
	/*
	 * config read policy for policy[0-15]. Four bit is one read policy.
	 * 4'b0000 [1'b0, 3'b000]{[3]: schint enable or not.[2-0]: read policy}
	 */
	writel(GPU_CTRL_P0_27_ADDR_VALUE,
		gdev->dm_dev.ctrl_reg.reg_base + GPU_CTRL_P0_27_ADDR_OFFSET);
	writel(GPU_CTRL_P0_28_ADDR_VALUE,
		gdev->dm_dev.ctrl_reg.reg_base + GPU_CTRL_P0_28_ADDR_OFFSET);
	/*
	 * config write policy for policy[0-15]. Four bit is one read policy.
	 * 4'b0000 [1'b0, 3'b000]{[3]: schint enable or not.[2-0]: write policy}
	 */
	writel(GPU_CTRL_P0_29_ADDR_VALUE,
		gdev->dm_dev.ctrl_reg.reg_base + GPU_CTRL_P0_29_ADDR_OFFSET);
	writel(GPU_CTRL_P0_30_ADDR_VALUE,
		gdev->dm_dev.ctrl_reg.reg_base + GPU_CTRL_P0_30_ADDR_OFFSET);
}
