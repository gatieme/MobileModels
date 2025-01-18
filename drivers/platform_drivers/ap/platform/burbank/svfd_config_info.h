#ifndef __SVFD_CONFIG_INFO_H__
#define __SVFD_CONFIG_INFO_H__ 
#include <soc_lpmcu_coresight_baseaddr_interface.h>
#include <soc_fcm_local_ananke_core_interface.h>
#include <soc_fcm_local_enyo_core_interface.h>
#include <soc_fcm_local_ip_interface.h>
#include <soc_corecrg_b_m_interface.h>
#include <soc_corecrg_l_l3_interface.h>
#include <soc_pmctrl_interface.h>
#include <soc_npucrg_interface.h>
#include <soc_npu_sctrl_interface.h>
#define MAX_SVFD_CLUSTER 3
#define SVFD_DMODE_MASK 0x3
#define SVFD_DATA_MASK 0x3F
#define SVFD_PATCH_MASK 0xFFF
#define SVFD_VDM_BIT 1
#define SVFD_CPM_BIT 0
#ifdef AVS_XLOADER
#define AVS_CRGPERI_BASE SOC_LPMCU_PERI_CRG_BASE_ADDR
#define AVS_LIT_L3_CORE_CRG_BASE SOC_LPMCU_CORE_CRG_L_L3_BASE_ADDR
#define AVS_B_M_CORE_CRG_BASE SOC_LPMCU_CORE_CRG_B_M_BASE_ADDR
#else
#define AVS_LIT_L3_CORE_CRG_BASE SOC_ACPU_CORE_CRG_L_L3_BASE_ADDR
#define AVS_CRGPERI_BASE SOC_ACPU_PERI_CRG_BASE_ADDR
#define AVS_B_M_CORE_CRG_BASE SOC_ACPU_CORE_CRG_B_M_BASE_ADDR
#endif
struct cpm_ffs_reg_info {
 unsigned int rstdis_addr;
 unsigned int rsten_addr;
 unsigned int cpm_bit;
 unsigned int ffs_bit;
};
struct vs_ctrl0_reg_info {
 unsigned int addr;
 unsigned int chip_cfg_val;
 unsigned int init_flag;
 unsigned int patch_offset;
 unsigned int patch_mask;
 unsigned int dmode_offset;
 unsigned int dmode_mask;
 unsigned int dlimit_e_bit;
};
struct vs_ctrl2_reg_info {
 unsigned int addr;
 unsigned int thsd_mask;
 unsigned int thsd_offset;
 unsigned int svfd_mode_offset;
 unsigned int svfd_mode_mask;
};
struct vs_ctrl_reg_info {
 unsigned int addr;
 unsigned int icg_en_bit;
 unsigned int need_init;
};
struct vs_cpm_data_reg_info {
 unsigned int addr;
 unsigned int data_f_offset;
 unsigned int data_r_offset;
 unsigned int dll_lock_bit;
 unsigned int data_mask;
};
struct cluster_svfd_config {
 struct cpm_ffs_reg_info cpmffs_reg;
 struct vs_ctrl0_reg_info vsctrl0_reg;
 struct vs_ctrl2_reg_info vsctrl2_reg;
 struct vs_ctrl_reg_info vsctrl_reg;
 struct vs_cpm_data_reg_info cpmd_reg;
};
enum svfd_data_mode {
 CPM_DIRECT_OUTPUT,
 CPM_MIN_OUTPUT,
 CPM_MAX_OUTPUT,
 CPM_NOT_OT_OUTPUT,
 CPM_MODE_MAX,
};
enum cpmffs_reset_mode {
 CPM_MODE,
 FFS_MODE,
 CPM_FFS_MODE,
 CPMFFS_MODE_MAX,
};
typedef union
{
 unsigned int value;
 struct
 {
  unsigned int reserved_0 : 4;
  unsigned int svfd_ulvt_ll : 4;
  unsigned int svfd_ulvt_sl : 4;
  unsigned int svfd_lvt_ll : 4;
  unsigned int svfd_lvt_sl : 4;
  unsigned int reserved_1 : 12;
 } reg;
} AVS_SVFD_PATCH_UNION;
struct cluster_svfd_config g_svfd_info[MAX_SVFD_CLUSTER] = {
 {
  .cpmffs_reg = {
   .rstdis_addr = (SOC_CRGPERIPH_PERRSTDIS5_ADDR(0) + AVS_CRGPERI_BASE),
   .rsten_addr = (SOC_CRGPERIPH_PERRSTEN5_ADDR(0) + AVS_CRGPERI_BASE),
   .cpm_bit = (SOC_CRGPERIPH_PERRSTDIS5_ip_rst_svfd_cpm_little_START),
   .ffs_bit = (SOC_CRGPERIPH_PERRSTDIS5_ip_rst_svfd_ffs_little_START),
  },
  .vsctrl0_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .chip_cfg_val = 0x750F6000,
   .init_flag = 0,
   .patch_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_ulvt_sl_little_START),
   .patch_mask = SVFD_PATCH_MASK,
   .dmode_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_cmp_data_mode_little_START),
   .dmode_mask = SVFD_DMODE_MASK,
   .dlimit_e_bit = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_data_limit_e_little_START),
  },
  .vsctrl2_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .thsd_mask = 0xFFF,
   .thsd_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfs_cpm_threshold_r_little_START),
   .svfd_mode_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfd_enalbe_mode_little_START),
   .svfd_mode_mask = 0x3,
  },
  .vsctrl_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_CTRL_LITTLE_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .icg_en_bit = (SOC_CORECRG_L_L3_VS_CTRL_LITTLE_sel_ckmux_little_icg_START),
   .need_init = 1,
  },
  .cpmd_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .data_f_offset = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_f_little_START),
   .data_r_offset = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_r_little_START),
   .dll_lock_bit = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_dll_lock_little_START),
   .data_mask = SVFD_DATA_MASK,
  }
 },
 {
  .cpmffs_reg = {
   .rstdis_addr = (SOC_CRGPERIPH_PERRSTDIS0_ADDR(0) + AVS_CRGPERI_BASE),
   .rsten_addr = (SOC_CRGPERIPH_PERRSTEN0_ADDR(0) + AVS_CRGPERI_BASE),
   .cpm_bit = (SOC_CRGPERIPH_PERRSTEN0_ip_rst_svfd_cpm_middle0_START),
   .ffs_bit = (SOC_CRGPERIPH_PERRSTEN0_ip_rst_svfd_ffs_middle0_START),
  },
  .vsctrl0_reg = {
   .addr = (SOC_CORECRG_B_M_VS_SVFD_CTRL0_MIDDLE0_ADDR(0) + AVS_B_M_CORE_CRG_BASE),
   .chip_cfg_val = 0x750F6000,
   .init_flag = 0,
   .patch_offset = (SOC_CORECRG_B_M_VS_SVFD_CTRL0_MIDDLE0_svfd_ulvt_sl_middle0_START),
   .patch_mask = SVFD_PATCH_MASK,
   .dmode_offset = (SOC_CORECRG_B_M_VS_SVFD_CTRL0_MIDDLE0_svfd_cmp_data_mode_middle0_START),
   .dmode_mask = SVFD_DMODE_MASK,
   .dlimit_e_bit = (SOC_CORECRG_B_M_VS_SVFD_CTRL0_MIDDLE0_svfd_data_limit_e_middle0_START),
  },
  .vsctrl2_reg = {
   .addr = (SOC_CORECRG_B_M_VS_SVFD_CTRL2_MIDDLE0_ADDR(0) + AVS_B_M_CORE_CRG_BASE),
   .thsd_mask = 0xFFF,
   .thsd_offset = (SOC_CORECRG_B_M_VS_SVFD_CTRL2_MIDDLE0_svfs_cpm_threshold_r_middle0_START),
   .svfd_mode_offset = (SOC_CORECRG_B_M_VS_SVFD_CTRL2_MIDDLE0_svfd_enalbe_mode_middle0_START),
   .svfd_mode_mask = 0x3,
  },
  .vsctrl_reg = {
   .addr = (SOC_CORECRG_B_M_VS_CTRL_MIDDLE0_ADDR(0) + AVS_B_M_CORE_CRG_BASE),
   .icg_en_bit = (SOC_CORECRG_B_M_VS_CTRL_MIDDLE0_sel_ckmux_middle0_icg_START),
   .need_init = 1,
  },
  .cpmd_reg = {
   .addr = (SOC_CORECRG_B_M_VS_CPM_DATA_STAT_MIDDLE0_ADDR(0) + AVS_B_M_CORE_CRG_BASE),
   .data_f_offset = (SOC_CORECRG_B_M_VS_CPM_DATA_STAT_MIDDLE0_svfd_cpm_data_f_middle0_START),
   .data_r_offset = (SOC_CORECRG_B_M_VS_CPM_DATA_STAT_MIDDLE0_svfd_cpm_data_r_middle0_START),
   .dll_lock_bit = (SOC_CORECRG_B_M_VS_CPM_DATA_STAT_MIDDLE0_svfd_dll_lock_middle0_START),
   .data_mask = SVFD_DATA_MASK,
  }
 },
 {
  .cpmffs_reg = {
   .rstdis_addr = (SOC_CRGPERIPH_PERRSTDIS0_ADDR(0) + AVS_CRGPERI_BASE),
   .rsten_addr = (SOC_CRGPERIPH_PERRSTEN0_ADDR(0) + AVS_CRGPERI_BASE),
   .cpm_bit = (SOC_CRGPERIPH_PERRSTDIS0_ip_rst_svfd_cpm_l3_START),
   .ffs_bit = (SOC_CRGPERIPH_PERRSTDIS0_ip_rst_svfd_ffs_l3_START),
  },
  .vsctrl0_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .chip_cfg_val = 0x750F6000,
   .init_flag = 0,
   .patch_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_ulvt_sl_l3_START),
   .patch_mask = SVFD_PATCH_MASK,
   .dmode_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_cmp_data_mode_l3_START),
   .dmode_mask = SVFD_DMODE_MASK,
   .dlimit_e_bit = (SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_data_limit_e_l3_START),
  },
  .vsctrl2_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .thsd_mask = 0xFFF,
   .thsd_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfs_cpm_threshold_r_l3_START),
   .svfd_mode_offset = (SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfd_enalbe_mode_l3_START),
   .svfd_mode_mask = 0x3,
  },
  .vsctrl_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_CTRL_L3_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .icg_en_bit = (SOC_CORECRG_L_L3_VS_CTRL_L3_sel_ckmux_l3_icg_START),
   .need_init = 1,
  },
  .cpmd_reg = {
   .addr = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_ADDR(0) + AVS_LIT_L3_CORE_CRG_BASE),
   .data_f_offset = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_f_l3_START),
   .data_r_offset = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_r_l3_START),
   .dll_lock_bit = (SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_dll_lock_l3_START),
   .data_mask = SVFD_DATA_MASK,
  }
 },
};
#endif
