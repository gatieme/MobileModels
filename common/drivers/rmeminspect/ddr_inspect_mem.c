/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Ddr kernel driver.
 * Author: qinbo
 * Create: 2022-10-13
 */

#include <linux/export.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/memblock.h>
#include <linux/stddef.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/ddr_inspect_mem.h>

struct ddr_inspect g_ddr_inst = {{0}, 0};

static void __init ddr_print_info(struct ddr_inspect *ddr_inst)
{
	int i;
	for (i = 0; i < INSPECT_SEG_MAX; i++) {
		pr_info("ddr inspect seg_idx[%d]:%d\n", i, ddr_inst->seg_idx[i]);
	}
	pr_info("ddr inspect cnt[%d]\n", ddr_inst->seg_cnt);
}

static void __init ddr_inspect_bad_mem(phys_addr_t base, phys_addr_t size)
{
	memblock_remove(base, size);
}

static void __init ddr_cmdline_err_handle(struct ddr_inspect *ddr_inst)
{
	int i;
	for (i = 0; i < INSPECT_SEG_MAX; i++) {
		ddr_inst->seg_idx[i] = 0;
	}
	ddr_inst->seg_cnt = 0;
}

static int __init early_parse_ddr_cmdline(char *p)
{
	int value;
	char *token = NULL;
	char ddr_copy[MAX_INSPECT_LEN] = {0};
	char *s;
	struct ddr_inspect *ddr_inst = &g_ddr_inst;

	if (p == NULL) {
		return 0;
	}

	strlcpy(ddr_copy, p, sizeof(ddr_copy));
	s = ddr_copy;
	token = strsep(&s, ",");
	while (token) {
		if (kstrtoint(token, INSPECT_BASE_DEC, &value) != 0) {
			ddr_cmdline_err_handle(ddr_inst);
			return 0;
		}
		if (ddr_inst->seg_cnt >= INSPECT_SEG_MAX) {
			return 0;
		}
		ddr_inst->seg_idx[ddr_inst->seg_cnt] = value;
		ddr_inst->seg_cnt++;
		token = strsep(&s, ",");
	}
	return 0;
}

early_param("ddr_inspect", early_parse_ddr_cmdline);

void __init ddr_inspect_mem(void)
{
	int i;
	phys_addr_t base;
	phys_addr_t size;
	int inspect_cnt = 0;
	struct ddr_inspect *ddr_inst = &g_ddr_inst;

	size = (phys_addr_t)DDR_INSPECT_SIZE;

	for (i = 0; i < ddr_inst->seg_cnt ; i++) {
		if (inspect_cnt >= MAX_INSPECT_CNT)
			break;
		base = (phys_addr_t)(ddr_inst->seg_idx[i] * DDR_INSPECT_SIZE);

		if (!memblock_is_region_memory(base, DDR_INSPECT_SIZE)) {
			continue;
		}
		if (!memblock_is_map_memory(base)) {
			continue;
		}
		if (memblock_is_region_reserved(base, DDR_INSPECT_SIZE)) {
			continue;
		}
		ddr_inspect_bad_mem(base, size);
		inspect_cnt++;
	}
}
