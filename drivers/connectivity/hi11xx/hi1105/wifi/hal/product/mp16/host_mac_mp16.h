/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * 功能说明   : HOST MAC OPS接口
 * 作者       : wifi
 * 创建日期   : 2012年10月18日
 */

#ifndef HOST_MAC_MP16_H
#define HOST_MAC_MP16_H

#include "oal_ext_if.h"
#include "frw_ext_if.h"
#include "hal_common.h"
#include "host_hal_device.h"

#if (_PRE_TEST_MODE == _PRE_TEST_MODE_ST)
#define MP16_MAC_CFG_HOST_REG_BUTT       0xBC
#define MP16_MAC_RPT_HOST_REG_BUTT       0xBC
#define MP16_DFX_REG_BANK_BUTT           0xBC
#define MP16_MAC_CFG_DMAC_BANK0_REG_BUTT 0xBC
#define MP16_MAC_RPT_DMAC_REG_BUTT       0xBC
#define MP16_MAC_CFG_DMAC_BANK4_REG_BUTT 0xBC
#define MP16_RX_CHN_EST_REG_BANK_BUTT    0xBC
#define MP16_RF_CTRL_REG_BANK_BUTT       0xBC
#define MP16_CALI_TEST_REG_BANK_BUTT     0xBC
#define MP16_PHY_GLB_REG_BANK_BUTT       0xBC
#define MP16_RX_AGC_REG_BANK_BUTT        0xBC
#define MP16_GLB_CTL_RB_REG_BANK_BUTT    0x200
#define MP16_MAC_RPT_SMAC_REG_BANK_BUTT 0x2A0

uint32_t g_st_host_mp16_mac_cfg_host_reg_base[MP16_MAC_CFG_HOST_REG_BUTT];
uint32_t g_st_host_mp16_mac_rpt_host_reg_base[MP16_MAC_RPT_HOST_REG_BUTT];
uint32_t g_st_host_mp16_dfx_reg_bank_base[MP16_DFX_REG_BANK_BUTT];
uint32_t g_st_host_mp16_mac_cfg_dmac_bank0_reg_base[MP16_MAC_CFG_DMAC_BANK0_REG_BUTT];
uint32_t g_st_host_mp16_mac_rpt_dmac_reg_base[MP16_MAC_RPT_DMAC_REG_BUTT];
uint32_t g_st_host_mp16_mac_cfg_dmac_bank4_reg_base[MP16_MAC_CFG_DMAC_BANK4_REG_BUTT];
uint32_t g_st_host_mp16_rx_chn_est_reg_band_base[MP16_RX_CHN_EST_REG_BANK_BUTT];
uint32_t mp16_rf_ctrl_reg_bank_0_base[MP16_RF_CTRL_REG_BANK_BUTT];
uint32_t mp16_cali_test_reg_bank_0_base[MP16_CALI_TEST_REG_BANK_BUTT];
uint32_t mp16_phy_glb_reg_bank_base[MP16_PHY_GLB_REG_BANK_BUTT];
uint32_t mp16_rx_agc_reg_bank_base[MP16_RX_AGC_REG_BANK_BUTT];
uint32_t mp16_glb_ctl_rb_reg_bank_base[MP16_GLB_CTL_RB_REG_BANK_BUTT];
uint32_t mp16_mac_rpt_smac_reg_bank_base[MP16_MAC_RPT_SMAC_REG_BANK_BUTT];

#define MP16_MAC_CFG_HOST_REG_BASE             ((uint32_t)&g_st_host_mp16_mac_cfg_host_reg_base[0]) /* ST使用 */
#define MP16_MAC_RPT_HOST_REG_BASE             ((uint32_t)&g_st_host_mp16_mac_rpt_host_reg_base[0])
#define MP16_DFX_REG_BANK_BASE                 ((uint32_t)&g_st_host_mp16_dfx_reg_bank_base[0])
#define MP16_MAC_CFG_DMAC_BANK0_REG_BASE       ((uint32_t)&g_st_host_mp16_mac_cfg_dmac_bank0_reg_base[0])
#define MP16_MAC_RPT_DMAC_REG_BASE             ((uint32_t)&g_st_host_mp16_mac_rpt_dmac_reg_base[0])
#define MP16_MAC_CFG_DMAC_BANK4_REG_BASE       ((uint32_t)&g_st_host_mp16_mac_cfg_dmac_bank4_reg_base[0])
#define MP16_RX_CHN_EST_REG_BANK_BASE          ((uint32_t)&g_st_host_mp16_rx_chn_est_reg_band_base[0])
#define MP16_RF_CTRL_REG_BANK_0_BASE           ((uint32_t)&mp16_rf_ctrl_reg_bank_0_base[0])
#define MP16_CALI_TEST_REG_BANK_0_BASE         ((uint32_t)&mp16_cali_test_reg_bank_0_base[0])
#define MP16_PHY_GLB_REG_BANK_BASE             ((uint32_t)&mp16_phy_glb_reg_bank_base[0])
#define MP16_RX_AGC_REG_BANK_BASE              ((uint32_t)&mp16_rx_agc_reg_bank_base[0])
#define MP16_GLB_CTL_RB_BASE_BASE              ((uint32_t)&mp16_glb_ctl_rb_reg_bank_base[0])
#define MP16_MAC_RPT_SMAC_REG_BASE        ((uint32_t)&mp16_mac_rpt_smac_reg_bank_base[0])
/* _PRE_TEST_MODE_ST */
#else

#define MP16_MAC_CFG_HOST_REG_BASE                        0x40020000
#define MP16_MAC_RPT_HOST_REG_BASE                        0x40030000
#define MP16_DFX_REG_BANK_BASE                            0x40064000
#define MP16_MAC_CFG_DMAC_BANK0_REG_BASE                  0x40022000
#define MP16_MAC_RPT_DMAC_REG_BASE                        0x40032000
#define MP16_MAC_CFG_DMAC_BANK4_REG_BASE                  0x4002A000
#define MP16_RX_CHN_EST_REG_BANK_BASE                     0x40072800
#define MP16_RF_CTRL_REG_BANK_0_BASE                      0x40064800
#define MP16_CALI_TEST_REG_BANK_0_BASE                    0x40061000
#define MP16_PHY_GLB_REG_BANK_BASE                        0x40060800
#define MP16_GLB_CTL_RB_BASE_BASE                         0x40000000
#define MP16_RX_AGC_REG_BANK_BASE                         0x40062800
#define MP16_MAC_RPT_SMAC_REG_BASE                         0x40034000

/* != _PRE_TEST_MODE_ST */
#endif

/* PHY 寄存器 */
#define MP16_MAC_HOST_INTR_CLR_REG                        (MP16_MAC_CFG_HOST_REG_BASE + 0x50)
#define MP16_MAC_HOST_INTR_MASK_REG                       (MP16_MAC_CFG_HOST_REG_BASE + 0x54)
#define MP16_DFX_REG_BANK_PHY_INTR_RPT_REG                (MP16_DFX_REG_BANK_BASE + 0xBC)     /* PHY中断状态 */
#define MP16_DFX_REG_BANK_CFG_INTR_MASK_HOST_REG          (MP16_DFX_REG_BANK_BASE + 0xB0)
#define MP16_DFX_REG_BANK_CFG_INTR_CLR_REG                (MP16_DFX_REG_BANK_BASE + 0xB8)
#define MP16_PHY_GLB_REG_BANK_FTM_CFG_REG                 (MP16_PHY_GLB_REG_BANK_BASE + 0x38) /* FTM配置寄存器 */
#define MP16_RX_AGC_REG_BANK_CFG_AGC_WEAK_SIG_EN_REG      (MP16_RX_AGC_REG_BANK_BASE + 0x1F4)
/* 信道估计通用寄存器 */
#define MP16_RX_CHN_EST_REG_BANK_CHN_EST_COM_REG          (MP16_RX_CHN_EST_REG_BANK_BASE + 0x1B0)
#define MP16_RF_CTRL_REG_BANK_0_CFG_ONLINE_CALI_USE_RF_REG_EN_REG     (MP16_RF_CTRL_REG_BANK_0_BASE + 0x34)
/* FIFO使能对应的寄存器配置地址 */
#define MP16_CALI_TEST_REG_BANK_0_FIFO_FORCE_EN_REG       (MP16_CALI_TEST_REG_BANK_0_BASE + 0x28)
#define MP16_PHY_GLB_REG_BANK_PHY_BW_MODE_REG        (MP16_PHY_GLB_REG_BANK_BASE + 0x4) /* 频宽模式配置寄存器 */

#define MP16_MAC_RPT_SMAC_INTR_CNT_REG                   (MP16_MAC_RPT_SMAC_REG_BASE + 0x2A0) /* SMAC中断计数器 */

#define MP16_MAC_HOST_INTR_STATUS_REG                    (MP16_MAC_RPT_HOST_REG_BASE + 0x0)  /* Host的中断状态 */
/* BA INFO BUFFER的写指针上报 */
#define MP16_MAC_BA_INFO_BUF_WPTR_REG                    (MP16_MAC_RPT_HOST_REG_BASE + 0x4)
#define MP16_MAC_RX_NORM_DATA_FREE_RING_RPTR_REG         (MP16_MAC_RPT_HOST_REG_BASE + 0x8)  /* rx-ndata-frrptr */
#define MP16_MAC_RX_SMALL_DATA_FREE_RING_RPTR_REG        (MP16_MAC_RPT_HOST_REG_BASE + 0xC)  /* rx-sdata-frrptr */
#define MP16_MAC_RX_DATA_CMP_RING_WPTR_REG               (MP16_MAC_RPT_HOST_REG_BASE + 0x10)
#define MP16_MAC_RPT_HOST_FREE_RING_STATUS_REG           (MP16_MAC_RPT_HOST_REG_BASE + 0x14) /* F RING上报信息 */
#define MP16_MAC_RX_PPDU_HOST_DESC_FREE_RING_RPTR_REG  (MP16_MAC_RPT_HOST_REG_BASE + 0x18)
#define MP16_MAC_RPT_PPDU_HOST_FREE_RING_STATUS_REG    (MP16_MAC_RPT_HOST_REG_BASE + 0x1C)
/* TX BA INFO BUFFER深度配置寄存器 */
#define MP16_MAC_TX_BA_INFO_BUF_DEPTH_REG                 (MP16_MAC_CFG_HOST_REG_BASE + 0x0)
/* TX BA INFO BUFFER基地址配置寄存器 */
#define MP16_MAC_TX_BA_INFO_BUF_ADDR_LSB_REG              (MP16_MAC_CFG_HOST_REG_BASE + 0x4)
/* TX BA INFO BUFFER基地址配置寄存器 */
#define MP16_MAC_TX_BA_INFO_BUF_ADDR_MSB_REG              (MP16_MAC_CFG_HOST_REG_BASE + 0x8)
/* TX BA INFO WPTR BUFFER基地址配置寄存器 */
#define MP16_MAC_TX_BA_INFO_WPTR_REG                      (MP16_MAC_CFG_HOST_REG_BASE + 0xC)
/* TX BA INFO RPTR BUFFER基地址配置寄存器 */
#define MP16_MAC_TX_BA_INFO_RPTR_REG                      (MP16_MAC_CFG_HOST_REG_BASE + 0x10)
#define MP16_MAC_RX_DATA_BUFF_LEN_REG                     (MP16_MAC_CFG_HOST_REG_BASE + 0x1C)
#define MP16_MAC_RX_NORM_DATA_FREE_RING_ADDR_LSB_REG      (MP16_MAC_CFG_HOST_REG_BASE + 0x20)
#define MP16_MAC_RX_NORM_DATA_FREE_RING_ADDR_MSB_REG      (MP16_MAC_CFG_HOST_REG_BASE + 0x24)
#define MP16_MAC_RX_SMALL_DATA_FREE_RING_ADDR_LSB_REG     (MP16_MAC_CFG_HOST_REG_BASE + 0x28)
#define MP16_MAC_RX_SMALL_DATA_FREE_RING_ADDR_MSB_REG     (MP16_MAC_CFG_HOST_REG_BASE + 0x2C)
#define MP16_MAC_RX_DATA_CMP_RING_ADDR_LSB_REG            (MP16_MAC_CFG_HOST_REG_BASE + 0x30)
#define MP16_MAC_RX_DATA_CMP_RING_ADDR_MSB_REG            (MP16_MAC_CFG_HOST_REG_BASE + 0x34)
#define MP16_MAC_RX_NORM_DATA_FREE_RING_SIZE_REG          (MP16_MAC_CFG_HOST_REG_BASE + 0x38)
#define MP16_MAC_RX_SMALL_DATA_FREE_RING_SIZE_REG         (MP16_MAC_CFG_HOST_REG_BASE + 0x3C)
#define MP16_MAC_RX_DATA_CMP_RING_SIZE_REG                (MP16_MAC_CFG_HOST_REG_BASE + 0x40)
#define MP16_MAC_RX_NORM_DATA_FREE_RING_WPTR_REG          (MP16_MAC_CFG_HOST_REG_BASE + 0x44)
#define MP16_MAC_RX_SMALL_DATA_FREE_RING_WPTR_REG         (MP16_MAC_CFG_HOST_REG_BASE + 0x48)
#define MP16_MAC_RX_DATA_CMP_RING_RPTR_REG                (MP16_MAC_CFG_HOST_REG_BASE + 0x4C)
#define MP16_MAC_HOST_INTR_CLR_REG                        (MP16_MAC_CFG_HOST_REG_BASE + 0x50) /* Host中断清除 */
#define MP16_MAC_HOST_INTR_MASK_REG                       (MP16_MAC_CFG_HOST_REG_BASE + 0x54) /* Host中断屏蔽 */
#define MP16_MAC_RX_DATA_CMP_RING_WPTR_CFG_REG            (MP16_MAC_CFG_HOST_REG_BASE + 0x58)
#define MP16_MAC_RX_NORM_DATA_FREE_RING_RPTR_CFG_REG      (MP16_MAC_CFG_HOST_REG_BASE + 0x5C)
#define MP16_MAC_RX_SMALL_DATA_FREE_RING_RPTR_CFG_REG     (MP16_MAC_CFG_HOST_REG_BASE + 0x60)
/* RX过滤控制寄存器 */
#define MP16_MAC_RX_FRAMEFILT_REG                         (MP16_MAC_CFG_DMAC_BANK0_REG_BASE + 0x54)
/* RX过滤控制寄存器2 */
#define MP16_MAC_RX_FRAMEFILT2_REG                        (MP16_MAC_CFG_DMAC_BANK0_REG_BASE + 0x58)

/* DMAC中断屏蔽寄存器 */
#define MP16_MAC_DMAC_INTR_MASK_REG                       (MP16_MAC_CFG_DMAC_BANK0_REG_BASE + 0x4)
/* 接收控制寄存器 */
#define MP16_MAC_RX_CTRL_REG                              (MP16_MAC_CFG_DMAC_BANK0_REG_BASE + 0x20)
/* CSI采样上报配置寄存器 */
#define MP16_MAC_CSI_PROCESS_REG                          (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x0)
/* CSI采样上报片外循环BUF基地址LSB */
#define MP16_MAC_CSI_BUF_BASE_ADDR_LSB_REG                (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x4)
/* CSI采样上报片外循环BUF基地址MSB */
#define MP16_MAC_CSI_BUF_BASE_ADDR_MSB_REG                (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x8)
/* CSI采样上报片外循环BUF大小 */
#define MP16_MAC_CSI_BUF_SIZE_REG                         (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0xC)
/* CSI采样白名单低32位 */
#define MP16_MAC_CSI_WHITELIST_ADDR_LSB_0_REG             (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x10)
/* CSI采样白名单高16位 */
#define MP16_MAC_CSI_WHITELIST_ADDR_MSB_0_REG             (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x14)
/* 定位信息上报 */
#define MP16_MAC_LOCATION_INFO_MASK_REG                   (MP16_MAC_RPT_DMAC_REG_BASE + 0x70)
/* CSI上报地址高32bit */
#define MP16_MAC_CSI_INFO_ADDR_MSB_REG                    (MP16_MAC_RPT_DMAC_REG_BASE + 0x1B0)
/* CSI上报地址低32bit */
#define MP16_MAC_CSI_INFO_ADDR_LSB_REG                    (MP16_MAC_RPT_DMAC_REG_BASE + 0x1B4)
/* FTM上报地址高32bit */
#define MP16_MAC_FTM_INFO_ADDR_MSB_REG                    (MP16_MAC_RPT_DMAC_REG_BASE + 0x1B8)
/* FTM上报地址低32bit */
#define MP16_MAC_FTM_INFO_ADDR_LSB_REG                    (MP16_MAC_RPT_DMAC_REG_BASE + 0x1BC)

/* VAP当前的Timestamp状态值（低32bit），单位us */
#define MP16_MAC_VAP_TSFTIMER_RDVALL_STATUS_12_REG      (MP16_MAC_RPT_DMAC_REG_BASE + 0x140)
/* 通用定时器状态寄存器 */
#define MP16_MAC_SMAC_COMMON_TIMER_STATUS_REG         (MP16_MAC_RPT_SMAC_REG_BASE + 0x10)

/* FTM采样上报配置寄存器 */
#define MP16_MAC_FTM_PROCESS_REG                          (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x110)
/* FTM采样上报片外循环BUF基地址LSB */
#define MP16_MAC_FTM_BUF_BASE_ADDR_LSB_REG                (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x114)
/* FTM采样上报片外循环BUF基地址MSB */
#define MP16_MAC_FTM_BUF_BASE_ADDR_MSB_REG                (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x118)
/* FTM采样白名单低32位 */
#define MP16_MAC_FTM_WHITELIST_ADDR_LSB_0_REG             (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x12C)
/* FTM采样白名单高16位 */
#define MP16_MAC_FTM_WHITELIST_ADDR_MSB_0_REG             (MP16_MAC_CFG_DMAC_BANK4_REG_BASE + 0x130)

/* master: 0x4002_0000~0x4003_ffff slave: 0x4004_0000~0x4005_ffff */
#define MP16_MAC_BANK_REG_OFFSET 0x20000
/* fpga 阶段暂未定主副偏移 后续修改适配 */
#define MP16_PHY_BANK_REG_OFFSET 0x40000

/* DMAC通用计数器中断屏蔽寄存器 */
#define MP16_MAC_DMAC_COMMON_TIMER_MASK_REG       (MP16_MAC_CFG_DMAC_BANK0_REG_BASE + 0x124)
/* 通用定时器相关参数配置 */
#define MP16_MAC_COMMON_TIMER_CTRL_0_REG          (MP16_MAC_CFG_DMAC_BANK0_REG_BASE + 0x128)
/* 通用定时器定时值配置 */
#define MP16_MAC_COMMON_TIMER_VAL_0_REG           (MP16_MAC_CFG_DMAC_BANK0_REG_BASE + 0x1A8)
#define MP16_W_SOFT_INT_SET_AON_REG               (MP16_GLB_CTL_RB_BASE_BASE + 0x104)

#define MP16_MAC_CFG_SMAC_REG_BASE          0x4002E000
#define MP16_MAC_CFG_DMAC_BANK2_REG_BASE    0x40026000
#define MP16_MAC_RX_RING_RESET_CTRL_REG     (MP16_MAC_CFG_SMAC_REG_BASE + 0x13C) /* RING复位 */
#define MP16_MAC_HWMAC_STARTUP_REG          (MP16_MAC_CFG_SMAC_REG_BASE + 0x140) /* HWMAC开关配置寄存器 */
#define MP16_MAC_COEX_ABORT_CTRL_REG        (MP16_MAC_CFG_DMAC_BANK2_REG_BASE + 0x300) /* 共存控制寄存器 */
#define MP16_MAC_CFG_COEX_ABORT_EN_MASK      0x1
#define MP16_MAC_CFG_HWMAC_STARTUP_EN_MASK   0x1
#define MP16_MAC_COMMON_TIMER_OFFSET         0x4
#define MP16_MAC_RPT_HOST_INTR_DATA_RING_OVERRUN_OFFSET  5
#define MP16_MAC_RPT_HOST_INTR_DATA_RING_OVERRUN_MASK    0x20
#define MP16_MAC_RPT_HOST_INTR_SMALL_RING_EMPTY_OFFSET   4
#define MP16_MAC_RPT_HOST_INTR_SMALL_RING_EMPTY_MASK     0x10
#define MP16_MAC_RPT_HOST_INTR_NORM_RING_EMPTY_OFFSET    3
#define MP16_MAC_RPT_HOST_INTR_NORM_RING_EMPTY_MASK      0x8
#define MP16_MAC_RPT_HOST_INTR_RX_COMPLETE_OFFSET        2
#define MP16_MAC_RPT_HOST_INTR_RX_COMPLETE_MASK          0x4

#define MP16_MAC_MAX_COMMON_TIMER 31 /* 通用定时器个数 */
void mp16_host_mac_irq_mask(hal_host_device_stru *hal_device, uint32_t irq);
void mp16_host_mac_irq_unmask(hal_host_device_stru *hal_device, uint32_t irq);
void mp16_get_host_mac_int_mask(hal_host_device_stru *hal_device, uint32_t *p_mask);
void mp16_set_host_mac_irq_mask(hal_host_device_stru *hal_device, uint32_t intr_mask);
void mp16_clear_host_mac_int_status(hal_host_device_stru *hal_device, uint32_t status);
void mp16_get_host_mac_int_status(hal_host_device_stru *hal_device, uint32_t *p_status);
uint32_t mp16_regs_addr_transfer(hal_host_device_stru *hal_device, uint32_t reg_addr);
void mp16_clear_host_phy_int_status(hal_host_device_stru *hal_device, uint32_t status);
void mp16_get_host_phy_int_mask(hal_host_device_stru *hal_device, uint32_t *p_mask);
void mp16_set_host_phy_irq_mask(hal_host_device_stru *hal_device, uint32_t mask);
void mp16_get_host_phy_int_status(hal_host_device_stru *hal_device, uint32_t *p_status);
int32_t mp16_host_regs_addr_init(hal_host_device_stru *hal_device);
uint32_t mp16_get_dev_rx_filt_mac_status(uint64_t *reg_status);
uint32_t mp16_regs_addr_get_offset(uint8_t device_id, uint32_t reg_addr);
uint32_t mp16_get_host_mac_common_timer_status(hal_host_device_stru *hal_device);
hal_mac_common_timer *mp16_get_host_mac_common_timer_ptr(uint8_t id);
#endif
