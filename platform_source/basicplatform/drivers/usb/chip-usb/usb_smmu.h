/*
 * Copyright (C) 2023 Hisilicon
 * Author: Hisillicon <>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _LOCAL_USB_SMMU_H_
#define _LOCAL_USB_SMMU_H_
#include <linux/platform_drivers/usb/usb_reg_cfg.h>
#include "usb_misc_ctrl.h"

struct usb_smmu {
	u32 smmu_id;
	u32 sid;
	u32 tbu_num;
	bool support_smmu;
	bool bypass_smmu;
	void __iomem *tbu_base;
	void __iomem *tbu_sid_base;
	u32 mmusid_off[2];
	struct chip_usb_reg_cfg *usb_smmu_hsdt1_unreset;
	struct chip_usb_reg_cfg *usb_smmu_tbu_unreset;
	struct chip_usb_reg_cfg *usb_smmu_hsdt1_reset;
	struct chip_usb_reg_cfg *usb_smmu_tbu_reset;
};

#define TBU_CONFIG_TIMEOUT      100
#define TBU_CR                  0x0
#define TBU_CRACK               0x4
#define TBU_EN_REQ_BIT          BIT(0)
#define TBU_EN_ACK_BIT          BIT(0)
#define TBU_CONNCT_STATUS_BIT   BIT(1)
#define TBU_TOK_TRANS_MSK       (0xFF << 8)
#define TBU_TOK_TRANS           0x8
#define TBU_DEFALUT_TOK_TRANS   0x3
#define MAX_TBU_INDEX 2
#define ENABLE 1
#define DISABLE 0

int usb_smmu_init(struct chip_usb_misc_ctrl *misc_ctrl);
int usb_disable_smmu(struct chip_usb_misc_ctrl *misc_ctrl);
int get_smmu_info(struct chip_usb_misc_ctrl *misc_ctrl);

#endif
