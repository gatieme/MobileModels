/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Ppr kernel driver header.
 * Author: qinbo
 * Create: 2022-10-13
 */

#ifndef ___DDR_INSPECT_MEM_H___
#define ___DDR_INSPECT_MEM_H___

#define DDR_INSPECT_SIZE	(64 * 1024 * 1024)
#define INIT_PPR_IDX		0xFFFFFFFFFFFFFFFF
#define DDR_TEST_PATTERN	0x5A5A5A5A5A5A5A5A
#define MAX_INSPECT_CNT		2
#define MAX_TEST_SIZE		(2 * 1024 * 1024 * 1024)
#define MAX_INSPECT_LEN		64
#define INSPECT_BASE_DEC	10
#define INSPECT_SEG_MAX		8

struct ddr_inspect {
	unsigned long seg_idx[INSPECT_SEG_MAX];
	unsigned int seg_cnt;
};

#ifdef CONFIG_MEM_INSPECT
extern void __init ddr_inspect_mem(void);
#else
static inline void __init ddr_inspect_mem(void)
{
}
#endif

#endif
