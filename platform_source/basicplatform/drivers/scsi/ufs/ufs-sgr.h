/*
 * ufs_test.h
 *
 * Copyright (c) 2019-2020 Huawei Technologies Co., Ltd.
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
 
#ifndef _UFS_SGR_H_
#define _UFS_SGR_H_
 
#define SOC_SCTRL_SCISOEN_ADDR(base)                          ((base) + (0x040UL))
#define SOC_SCTRL_SCISODIS_ADDR(base)                         ((base) + (0x044UL))
#define SOC_SCTRL_SCPEREN4_ADDR(base)                         ((base) + (0x1B0UL))
#define SOC_SCTRL_SCPERRSTSTAT1_ADDR(base)                    ((base) + (0x214UL))
#define SOC_SCTRL_SCPERCTRL6_ADDR(base)                       ((base) + (0x318UL))
#define SOC_SCTRL_SCCLKDIV9_ADDR(base)                        ((base) + (0x274UL))
#define SOC_SCTRL_SCPERCTRL17_ADDR(base)                      ((base) + (0x344UL))

#define soc_ufs_sysctrl_ufs_reset_ctrl_addr(base)             ((base) + (0x008UL))
#define soc_ufs_sysctrl_crg_ufs_cfg1_addr(base)               ((base) + (0x004UL))
 
#define SOC_SCTRL_SCISODIS_ufs_mphy_top_iso_en_START     (9)
#define SOC_SCTRL_SCISODIS_ufs_mphy_iso_en_START         (10)
#define SOC_SCTRL_SCPEREN4_gt_clk_ufs_subsys_START       (14)
#endif /* _UFS_SGR_H_ */
