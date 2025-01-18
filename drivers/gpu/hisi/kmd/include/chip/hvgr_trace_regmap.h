/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2020-2020. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#ifndef HVGR_TRACE_REGMAP_H
#define HVGR_TRACE_REGMAP_H

#define TRACE_COM             0x00000
#define TRACE_CH0_ETR         0x10000
#define TRACE_CH0_ETF         0x11000
#define TRACE_CH0_LV0_FUNNELA 0x12000
#define TRACE_CH0_LV0_FUNNELB 0x13000
#define TRACE_CH0_LV1_FUNNEL  0x14000

#define TRACE_CH1_ETR         0x16000
#define TRACE_CH1_ETF         0x17000
#define TRACE_CH1_LV0_FUNNELA 0x18000
#define TRACE_CH1_LV0_FUNNELB 0x19000
#define TRACE_CH1_LV1_FUNNEL  0x1A000

#define TRACE_CH2_ETR         0x1C000
#define TRACE_CH2_ETF         0x1D000
#define TRACE_CH2_LV0_FUNNELA 0x1E000
#define TRACE_CH2_LV0_FUNNELB 0x1F000
#define TRACE_CH2_LV1_FUNNEL  0x20000

#define SUB_TRACE_GPC0        0x40000
#define SUB_TRACE_GPC1        0x41000
#define SUB_TRACE_GPC2        0x42000
#define SUB_TRACE_GPC3        0x43000
#define SUB_TRACE_GPC4        0x44000
#define SUB_TRACE_GPC5        0x45000
#define SUB_TRACE_GPC6        0x46000
#define SUB_TRACE_GPC7        0x47000
#define SUB_TRACE_JM          0x50000
#define SUB_TRACE_BIN         0x51000
#define SUB_TRACE_L2          0x52000

#define TS_SEL       (TRACE_COM + 0x00)
#define TIMESTAMP_EN (TRACE_COM + 0x04)
#define TIMESTAMP_L  (TRACE_COM + 0x08)
#define TIMESTAMP_H  (TRACE_COM + 0x0C)

#define trace_atbid_cfg(r)   ((r) + 0x00)
#define trace_ctr0_cfg(r)    ((r) + 0x04)
#define trace_ctr1_cfg(r)    ((r) + 0x08)
#define trace_excpsrc_cfg(r) ((r) + 0x0C)
#define trace_ctoen_cfg(r)   ((r) + 0x10)
#define trace_ctrl_status(r) ((r) + 0x14)
#define soft_trace_period(r) ((r) + 0x18)
#define soft_trace_value(r)  ((r) + 0x1C)
#define soft_trace_ctrl(r)   ((r) + 0x20)
#define st_en(r)             ((r) + 0x24)
#define trace_vld_mask(r)    ((r) + 0x28)

#define trace_start_mask0(r, n)   ((r) + 0x100 + (n) * 0x40)
#define trace_start_mask1(r, n)   ((r) + 0x104 + (n) * 0x40)
#define trace_start_value0(r, n)  ((r) + 0x108 + (n) * 0x40)
#define trace_start_value1(r, n)  ((r) + 0x10C + (n) * 0x40)
#define trace_start_time0(r, n)   ((r) + 0x110 + (n) * 0x40)
#define trace_start_time1(r, n)   ((r) + 0x114 + (n) * 0x40)
#define trace_stop_mask0(r, n)    ((r) + 0x118 + (n) * 0x40)
#define trace_stop_mask1(r, n)    ((r) + 0x11C + (n) * 0x40)
#define trace_stop_value0(r, n)   ((r) + 0x120 + (n) * 0x40)
#define trace_stop_value1(r, n)   ((r) + 0x124 + (n) * 0x40)
#define trace_stop_time0(r, n)    ((r) + 0x128 + (n) * 0x40)
#define trace_stop_time1(r, n)    ((r) + 0x12C + (n) * 0x40)
#define trace_filter_mask0(r, n)  ((r) + 0x130 + (n) * 0x40)
#define trace_filter_mask1(r, n)  ((r) + 0x134 + (n) * 0x40)
#define trace_filter_value0(r, n) ((r) + 0x138 + (n) * 0x40)
#define trace_filter_value1(r, n) ((r) + 0x13C + (n) * 0x40)

#define FUNNELCONTROL        0x000
#define PRIORITYCONTROL      0x004
#define TF_ITATBDATA0        0xEEC
#define ITATBCTR2            0xEF0
#define ITATBCTR1            0xEF4
#define ITATBCTR0            0xEF8
#define TF_ITCTRL            0xF00
#define LOCKACCESS           0xFB0
#define LOCKSTATUS           0xFB4
#define AUTHENTICATIONSTATUS 0xFB8

#define RSZ         0x004
#define STS         0x00C
#define RRD         0x010
#define RRP         0x014
#define RWP         0x018
#define TRG         0x01C
#define CTL         0x020
#define RWD         0x024
#define MODE        0x028
#define LBUFLEVEL   0x02C
#define CBUFLEVEL   0x030
#define BUFWM       0x034
#define RRPHI       0x038
#define RWPHI       0x03C
#define AXICTL      0x110
#define DBALO       0x118
#define DBAHI       0x11C
#define FFSR        0x300
#define FFCR        0x304
#define PSCR        0x308
#define ITATBMDATA0 0xED0
#define ITATBMCTR2  0xED4
#define ITATBMCTR1  0xED8
#define ITATBMCTR0  0xEDC
#define ITMISCOP0   0xEE0
#define ITTRFLIN    0xEE8
#define ITATBDATA0  0xEEC
#define ATATBCTR2   0xEF0
#define ATATBCTR1   0xEF4
#define ATATBCTR0   0xEF8
#define ITCTRL      0xF00
#define CLAIMSET    0xFA0
#define CLAIMCLR    0xFA4
#define LAR         0xFB0
#define LSR         0xFB4
#define AUTHSTATUS  0xFB8
#define DEVID       0xFC8
#define DEVTYPE     0xFCC
#define PERIPHID4   0xFD0
#define PERIPHID5   0xFD4
#define PERIPHID6   0xFD8
#define PERIPHID7   0xFDC
#define PERIPHID0   0xFE0
#define PERIPHID1   0xFE4
#define PERIPHID2   0xFE8
#define PERIPHID3   0xFEC
#define COMPID0     0xFF0
#define COMPID1     0xFF4
#define COMPID2     0xFF8
#define COMPID3     0xFFC
#define trace_etr_reg(r, n)      ((r) + (n))
#define trace_etf_reg(r, n)      ((r) + (n))

#endif /* HVGR_TRACE_REGMAP_H */
