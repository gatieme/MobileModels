/* Module internals
 *
 * Copyright (C) 2016 Hisilicon, Inc. All Rights Reserved.
 * Written by 187560@Hisilicon
 *
 * These coded instructions, statements, and computer programs are the
 * copyrighted works and confidential proprietary information of
 * Hisilicon Inc. and its licensors, and are licensed to the recipient
 * under the terms of a separate license agreement.  They may be
 * adapted and modified by bona fide purchasers under the terms of the
 * separate license agreement for internal use, but no adapted or
 * modified version may be disclosed or distributed to third parties
 * in any manner, medium, or form, in whole or in part, without the
 * prior written consent of Hisilicon Inc.
 */

#ifndef _IPU_SMMU_DRV_H
#define _IPU_SMMU_DRV_H

#define IPU_SMMU_ENABLE
#define CAMBRICON_IPU_IRQ

#define IPU_BASE_ADDRESS 0xff400000

int ipu_smmu_init(unsigned int ttbr0);
int ipu_smmu_init_es(unsigned int ttbr0);
unsigned int ipu_get_smmu_base_phy(struct device *dev);

#endif
