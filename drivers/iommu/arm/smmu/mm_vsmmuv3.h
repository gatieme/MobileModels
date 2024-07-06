/* Copyright (c) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef _MM_VSMMUV3_H
#define _MM_VSMMUV3_H

#include "platform_smmu_v3.h"
#include <securec.h>

#ifdef CONFIG_MM_RDA_SMMU
long mm_vsmmu_ioc_write_reg(unsigned int smmuid, unsigned int offset,
						unsigned int size, unsigned long value);
long mm_vsmmu_ioc_read_reg(unsigned int smmuid, unsigned int offset,
						unsigned int size, unsigned long *value);
void mm_vsmmu_sync_pgd(unsigned long base);
void set_vsmmu_device(struct arm_smmu_device *smmu);
void clear_vsmmu_device(struct arm_smmu_device *smmu);
#else
static inline long mm_vsmmu_ioc_write_reg(unsigned int smmuid,
		unsigned int offset, unsigned int size, unsigned long value)
{
	return 0;
}
static inline long mm_vsmmu_ioc_read_reg(unsigned int smmuid,
		unsigned int offset, unsigned int size, unsigned long *value)
{
	return 0;
}
static inline void mm_vsmmu_sync_pgd(unsigned long base)
{
	return;
}
static inline void set_vsmmu_device(struct arm_smmu_device *smmu) {}
static inline void clear_vsmmu_device(struct arm_smmu_device *smmu) {}
#endif
#endif
