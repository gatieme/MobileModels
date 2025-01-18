/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_PCIE_H
#define HVGR_PCIE_H

#include <linux/list.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>

#define PCI_VENDOR_ID_HVGR     0x19e5
#define PCIE_DEVICE_ID_HVGR    0x3690

#define HVGR_PCIE_RC_ID 1

#define HVGR_PCIE_REG_JM_TOP        0x100000
#define HVGR_PCIE_REG_GLOBAL_RESET  0x300000


enum hvgr_pcie_irqs_type {
	PCIE_GPU_IRQ,
	PCIE_MMU_IRQ,
	PCIE_JOB_IRQ,
	PCIE_FCP_IRQ,
	PCIE_CQ_IRQ,
	PCIE_CC_IRQ,
	PCIE_GPU_IRQ_CNT
};

#endif /* HVGR_PCIE_H */
