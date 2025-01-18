#ifndef __AVS_CONFIG_INFO_H__
#define __AVS_CONFIG_INFO_H__ 
#include <avs_common.h>
#include <soc_lpmcu_coresight_baseaddr_interface.h>
#include <soc_acpu_baseaddr_interface.h>
#include <soc_fcm_local_ananke_core_interface.h>
#include <soc_fcm_local_enyo_core_interface.h>
#include <soc_fcm_local_ip_interface.h>
#include <soc_corecrg_b_m_interface.h>
#include <soc_corecrg_l_l3_interface.h>
#include <soc_pmctrl_interface.h>
#ifdef AVS_XLOADER
#define AVS_CRGPERI_BASE SOC_LPMCU_PERI_CRG_BASE_ADDR
#define AVS_PMC_BASE SOC_LPMCU_PMC_BASE_ADDR
#define AVS_LIT_L3_CORE_CRG_BASE SOC_LPMCU_CORE_CRG_L_L3_BASE_ADDR
#define AVS_B_M_CORE_CRG_BASE SOC_LPMCU_CORE_CRG_B_M_BASE_ADDR
#define AVS_FCM_LOCAL_BASE SOC_LPMCU_FCM_LOCAL_IP_BASE_ADDR
#define AVS_CPU_LOCAL_BASE SOC_LPMCU_FCM_CORE0_LOCAL_CFG_BASE_ADDR
#define AVS_NPU_SYSCTRL_BASE SOC_LPMCU_npu_sysctrl_BASE_ADDR
#define AVS_NPU_CPU_SYSCTRL_BASE SOC_LPMCU_sysctrl_npu_cpu_BASE_ADDR
#define AVS_NPU_CRG_BASE SOC_LPMCU_npu_crg_BASE_ADDR
#else
#define AVS_LIT_L3_CORE_CRG_BASE SOC_ACPU_CORE_CRG_L_L3_BASE_ADDR
#define AVS_CRGPERI_BASE SOC_ACPU_PERI_CRG_BASE_ADDR
#define AVS_PMC_BASE SOC_ACPU_PMC_BASE_ADDR
#define AVS_B_M_CORE_CRG_BASE SOC_ACPU_CORE_CRG_B_M_BASE_ADDR
#define AVS_FCM_LOCAL_BASE SOC_ACPU_FCM_LOCAL_IP_BASE_ADDR
#define AVS_CPU_LOCAL_BASE SOC_ACPU_FCM_CORE0_LOCAL_CFG_BASE_ADDR
#define AVS_NPU_SYSCTRL_BASE SOC_ACPU_npu_sysctrl_BASE_ADDR
#define AVS_NPU_CPU_SYSCTRL_BASE SOC_ACPU_sysctrl_npu_cpu_BASE_ADDR
#define AVS_NPU_CRG_BASE SOC_ACPU_npu_crg_BASE_ADDR
#endif
#define MAX_HPM_CLUSTER 6
#define BIT_MASK_WIDTH 16
#define CLUSTER_MAX_HPM_CORE 4
#define HPM_SENSOR_OFFSET 4
#define HPM_SENSOR_MASK 0x3
#define HPM_DIV 6
#define HPM_DIV_MASK 0xF
#define HPM_OPC_MASK 0x3FF
#define LH_HPMDIV_MASK 0x3
struct hpm_sensor_reg {
 unsigned int addr;
 unsigned int mask;
 unsigned int offset;
};
struct hpm_clkdiv_reg {
 unsigned int addr;
 unsigned int div;
 unsigned int mask;
 unsigned int offset;
};
struct hpm_nx_reg {
 unsigned int en_addr;
 unsigned int hpm_en_bit;
 unsigned int hpmx_en_bit;
 unsigned int stat_addr;
 unsigned int vld_bit;
 unsigned int vldx_bit;
 unsigned int val_mask;
 unsigned int val_offset;
 unsigned int valx_offset;
};
struct hpm_nxsel_reg {
 unsigned int sel_addr;
 unsigned int sel_offset;
 unsigned int sel_mask;
 unsigned int type_bit;
 unsigned int hpmen_addr;
 unsigned int en_bit;
 unsigned int hpmopc_addr;
 unsigned int opc_vld_bit;
 unsigned int val_mask;
 unsigned int val_offset;
};
struct hpm_clkgt_reg {
 unsigned int en_addr;
 unsigned int dis_addr;
 unsigned int clkgt_bit;
};
struct hpm_clk_reg {
 unsigned int bit_mask_flag;
 unsigned int en_addr;
 unsigned int dis_addr;
 unsigned int offset;
 unsigned int mask;
};
struct hpm_rst_reg {
 unsigned int disrst_addr;
 unsigned int enrst_addr;
 unsigned int offset;
 unsigned int mask;
};
struct hpm_reg_info {
 struct hpm_sensor_reg sen_reg;
 struct hpm_clkdiv_reg div_reg;
 struct hpm_nx_reg nx_reg;
 struct hpm_nxsel_reg nxsel_reg;
};
struct hpm_lhvolt_div_reg {
 unsigned int addr;
 unsigned int lh_offset;
 unsigned int div;
 unsigned int mask;
};
struct cluster_hpm_config {
 unsigned int core_num;
 unsigned int hpm_type;
 struct hpm_lhvolt_div_reg lhvol_divreg;
 struct hpm_clkgt_reg clkgt_reg;
 struct hpm_clk_reg clk_reg;
 struct hpm_rst_reg rst_reg;
 struct hpm_rst_reg rst_reg_sub;
 struct hpm_reg_info hpm_reg[CLUSTER_MAX_HPM_CORE];
};
enum hpm_reg_type {
 NX_TYPE,
 NX_SEL_TYPE,
 HPM_TYPE_MAX,
};
struct cluster_hpm_config g_hpm_info[AVS_MAX_CLUSTER] = {
 {
  .core_num = 4,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (SOC_CRGPERIPH_CLKDIV31_ADDR(0) + AVS_CRGPERI_BASE),
   .lh_offset = (SOC_CRGPERIPH_CLKDIV31_div_hpm_h_START),
   .div = 0,
   .mask = LH_HPMDIV_MASK,
  },
  .clkgt_reg = {
   .en_addr = (SOC_CRGPERIPH_PEREN5_ADDR(0) + AVS_CRGPERI_BASE),
   .dis_addr = (SOC_CRGPERIPH_PERDIS5_ADDR(0) + AVS_CRGPERI_BASE),
   .clkgt_bit = (SOC_CRGPERIPH_PEREN5_gt_clk_fcm_monitor_sensor_START),
  },
  .clk_reg = {
   .bit_mask_flag = 1,
   .en_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .dis_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_little_START),
   .mask = 0xF,
  },
  .rst_reg = {
   .disrst_addr = (SOC_FCM_LOCAL_IP_RST_DIS_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .enrst_addr = (SOC_FCM_LOCAL_IP_RST_EN_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_little_START),
   .mask = 0xF,
  },
  .rst_reg_sub = {
   .disrst_addr = 0,
   .enrst_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE),
     .hpm_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE),
     .vld_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_START),
    },
   },
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x1000),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x1000),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x1000),
     .hpm_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x1000),
     .vld_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_START),
    },
   },
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x2000),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x2000),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x2000),
     .hpm_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x2000),
     .vld_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_START),
    },
   },
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x3000),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x3000),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x3000),
     .hpm_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x3000),
     .vld_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ANANKE_CORE_ANANKE_HPM_STAT_hpmx_opc_START),
    },
   },
  },
 },
 {
  .core_num = 3,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (SOC_CRGPERIPH_CLKDIV31_ADDR(0) + AVS_CRGPERI_BASE),
   .lh_offset = (SOC_CRGPERIPH_CLKDIV31_div_hpm_h_START),
   .div = 0,
   .mask = LH_HPMDIV_MASK,
  },
  .clkgt_reg = {
   .en_addr = (SOC_CRGPERIPH_PEREN5_ADDR(0) + AVS_CRGPERI_BASE),
   .dis_addr = (SOC_CRGPERIPH_PERDIS5_ADDR(0) + AVS_CRGPERI_BASE),
   .clkgt_bit = (SOC_CRGPERIPH_PEREN5_gt_clk_fcm_monitor_sensor_START),
  },
  .clk_reg = {
   .bit_mask_flag = 1,
   .en_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .dis_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_middle_START),
   .mask = 0x7,
  },
  .rst_reg = {
   .disrst_addr = (SOC_FCM_LOCAL_IP_RST_DIS_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .enrst_addr = (SOC_FCM_LOCAL_IP_RST_EN_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_middle_START),
   .mask = 0x7,
  },
  .rst_reg_sub = {
   .disrst_addr = 0,
   .enrst_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x4000),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x4000),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x4000),
     .hpm_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x4000),
     .vld_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_START),
    },
   },
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x5000),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x5000),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x5000),
     .hpm_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x5000),
     .vld_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_START),
    },
   },
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x6000),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x6000),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x6000),
     .hpm_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x6000),
     .vld_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_START),
    },
   },
  },
 },
 {
  .core_num = 1,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (SOC_CRGPERIPH_CLKDIV31_ADDR(0) + AVS_CRGPERI_BASE),
   .lh_offset = (SOC_CRGPERIPH_CLKDIV31_div_hpm_h_START),
   .div = 0,
   .mask = LH_HPMDIV_MASK,
  },
  .clkgt_reg = {
   .en_addr = (SOC_CRGPERIPH_PEREN5_ADDR(0) + AVS_CRGPERI_BASE),
   .dis_addr = (SOC_CRGPERIPH_PERDIS5_ADDR(0) + AVS_CRGPERI_BASE),
   .clkgt_bit = (SOC_CRGPERIPH_PEREN5_gt_clk_fcm_monitor_sensor_START),
  },
  .clk_reg = {
   .bit_mask_flag = 1,
   .en_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .dis_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_big_START),
   .mask = 0x1,
  },
  .rst_reg = {
   .disrst_addr = (SOC_FCM_LOCAL_IP_RST_DIS_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .enrst_addr = (SOC_FCM_LOCAL_IP_RST_EN_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_big_START),
   .mask = 0x1,
  },
  .rst_reg_sub = {
   .disrst_addr = 0,
   .enrst_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x7000),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x7000),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x7000),
     .hpm_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_CFG_REG_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_ADDR(0) + AVS_CPU_LOCAL_BASE + 0x7000),
     .vld_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_valid_START),
     .vldx_bit = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_ENYO_CORE_DEIMOS_HPM_STAT_hpmx_opc_START),
    },
   },
  },
 },
 {
  .core_num = 1,
  .hpm_type = NX_TYPE,
  .lhvol_divreg = {
   .addr = (SOC_CRGPERIPH_CLKDIV31_ADDR(0) + AVS_CRGPERI_BASE),
   .lh_offset = (SOC_CRGPERIPH_CLKDIV31_div_hpm_h_START),
   .div = 0,
   .mask = LH_HPMDIV_MASK,
  },
  .clkgt_reg = {
   .en_addr = (SOC_CRGPERIPH_PEREN5_ADDR(0) + AVS_CRGPERI_BASE),
   .dis_addr = (SOC_CRGPERIPH_PERDIS5_ADDR(0) + AVS_CRGPERI_BASE),
   .clkgt_bit = (SOC_CRGPERIPH_PEREN5_gt_clk_fcm_monitor_sensor_START),
  },
  .clk_reg = {
   .bit_mask_flag = 1,
   .en_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .dis_addr = (SOC_FCM_LOCAL_IP_CLKEN1_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_scu_START),
   .mask = 0x1,
  },
  .rst_reg = {
   .disrst_addr = (SOC_FCM_LOCAL_IP_RST_DIS_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .enrst_addr = (SOC_FCM_LOCAL_IP_RST_EN_ADDR(0) + AVS_FCM_LOCAL_BASE),
   .offset = (SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_scu_START),
   .mask = 0x1,
  },
  .rst_reg_sub = {
   .disrst_addr = 0,
   .enrst_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (SOC_FCM_LOCAL_IP_CTRL5_ADDR(0) + AVS_FCM_LOCAL_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_FCM_LOCAL_IP_CTRL5_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_FCM_LOCAL_IP_CTRL5_ADDR(0) + AVS_FCM_LOCAL_BASE),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_FCM_LOCAL_IP_CTRL5_hpm_clk_div_START),
    },
    .nx_reg = {
     .en_addr = (SOC_FCM_LOCAL_IP_CTRL5_ADDR(0) + AVS_FCM_LOCAL_BASE),
     .hpm_en_bit = (SOC_FCM_LOCAL_IP_CTRL5_hpm_en_START),
     .hpmx_en_bit = (SOC_FCM_LOCAL_IP_CTRL5_hpmx_en_START),
     .stat_addr = (SOC_FCM_LOCAL_IP_STAT0_ADDR(0) + AVS_FCM_LOCAL_BASE),
     .vld_bit = (SOC_FCM_LOCAL_IP_STAT0_fcm_hpm_opc_vld_START),
     .vldx_bit = (SOC_FCM_LOCAL_IP_STAT0_fcm_hpmx_opc_vld_START),
     .val_mask = HPM_OPC_MASK,
     .val_offset = (SOC_FCM_LOCAL_IP_STAT0_fcm_hpm_opc_START),
     .valx_offset = (SOC_FCM_LOCAL_IP_STAT0_fcm_hpmx_opc_START),
    },
   },
  },
 },
 {
  .core_num = 8,
  .hpm_type = NX_SEL_TYPE,
  .lhvol_divreg = {
   .addr = (SOC_CRGPERIPH_CLKDIV31_ADDR(0) + AVS_CRGPERI_BASE),
   .lh_offset = (SOC_CRGPERIPH_CLKDIV31_div_hpm_l_START),
   .div = 0,
   .mask = LH_HPMDIV_MASK,
  },
  .clkgt_reg = {
   .en_addr = (SOC_CRGPERIPH_PEREN5_ADDR(0) + AVS_CRGPERI_BASE),
   .dis_addr = (SOC_CRGPERIPH_PERDIS5_ADDR(0) + AVS_CRGPERI_BASE),
   .clkgt_bit = (SOC_CRGPERIPH_PERDIS5_gt_clk_gpuhpm_START),
  },
  .clk_reg = {
   .bit_mask_flag = 0,
   .en_addr = 0,
   .dis_addr = 0,
   .offset = 0,
   .mask = 0,
  },
  .rst_reg = {
   .disrst_addr = (SOC_CRGPERIPH_PERRSTDIS3_ADDR(0) + AVS_CRGPERI_BASE),
   .enrst_addr = (SOC_CRGPERIPH_PERRSTEN3_ADDR(0) + AVS_CRGPERI_BASE),
   .offset = (SOC_CRGPERIPH_PERRSTEN3_ip_rst_g3dshpm15_START),
   .mask = 0x7FEF,
  },
  .rst_reg_sub = {
   .disrst_addr = (SOC_CRGPERIPH_PERRSTDIS5_ADDR(0) + AVS_CRGPERI_BASE),
   .enrst_addr = (SOC_CRGPERIPH_PERRSTEN5_ADDR(0) + AVS_CRGPERI_BASE),
   .offset = (SOC_CRGPERIPH_PERRSTDIS5_ip_rst_g3dshpm9_START),
   .mask = 0x7,
  },
  .hpm_reg = {
   {
    .sen_reg = {
     .addr = (SOC_PMCTRL_GPU_HPMCLKDIV_ADDR(0) + AVS_PMC_BASE),
     .mask = HPM_SENSOR_MASK,
     .offset = (SOC_PMCTRL_GPU_HPMCLKDIV_gpu_hpm_clk_div_START + HPM_SENSOR_OFFSET),
    },
    .div_reg = {
     .addr = (SOC_PMCTRL_GPU_HPMCLKDIV_ADDR(0) + AVS_PMC_BASE),
     .div = HPM_DIV,
     .mask = HPM_DIV_MASK,
     .offset = (SOC_PMCTRL_GPU_HPMCLKDIV_gpu_hpm_clk_div_START),
    },
    .nxsel_reg = {
     .sel_addr = (SOC_PMCTRL_GPU_HPMSEL_ADDR(0) + AVS_PMC_BASE),
     .sel_offset = (SOC_PMCTRL_GPU_HPMSEL_gpu_hpm_addr_sel_START),
     .sel_mask = (0x1F),
     .type_bit = (SOC_PMCTRL_GPU_HPMSEL_gpu_hpm_type_sel_START),
     .hpmen_addr = (SOC_PMCTRL_GPU_HPMEN_ADDR(0) + AVS_PMC_BASE),
     .en_bit = (SOC_PMCTRL_GPU_HPMEN_gpu_hpm_en_START),
     .hpmopc_addr = (SOC_PMCTRL_GPU_HPMOPC_ADDR(0) + AVS_PMC_BASE),
     .opc_vld_bit = (SOC_PMCTRL_GPU_HPMOPC_gpu_hpm_opc_vld_START),
     .val_mask = (HPM_OPC_MASK),
     .val_offset = (SOC_PMCTRL_GPU_HPMOPC_gpu_hpm_opc_START),
    },
   },
  },
 },
};
#endif
