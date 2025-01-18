#ifndef __DDR_SEC_FEATURE_H__
#define __DDR_SEC_FEATURE_H__ 
#include <global_ddr_map.h>
#include <soc_dmss_interface.h>
#include <ddr_define.h>
#include "ddr_dmss_mntn_struct.h"
#include "m3_sram_map.h"
typedef unsigned long long u64;
typedef unsigned int u32;
#define GENERAL_IPC_DATA_LEN 8
#define ASI_NUM_NEED_FIX(asi_num) \
    ((asi_num) == ASI_NUM_2 || (asi_num) == ASI_NUM_4 || (asi_num) == ASI_NUM_7 || \
    (asi_num) == ASI_NUM_9)
#define ASI_NUM_MAX DMSS_ASI_MAX
#define ASI_NUM_BYPASS(asi_num) \
    (((asi_num) == ASI_NUM_2) || ((asi_num) == ASI_NUM_4) || ((asi_num) == ASI_NUM_7) || \
                ((asi_num) == ASI_NUM_9) || ((asi_num) == ASI_NUM_10) || ((asi_num) == ASI_NUM_11) || \
                ((asi_num) == ASI_NUM_14) || ((asi_num) == ASI_NUM_15) || ((asi_num) == ASI_NUM_16))
#define SEC_RGN_ADDR_SHIFT (16)
#define SEC_RGN_ADDR_MASK (0xFFFFULL)
#define TUI_RGN_NUM 1
#define FACE_TA_ALGO_RGN_NUM 2
#define FACE_CAMERA_RGN_NUM 3
#define EID_FACE_2D_RGN_NUM 4
#define SUB_RGN_START_NUM 1
#define SUB_RGN_MAX_NUM 4
#define SUB_RGN_USED 4
#define FACE_3D_TA_FEATURE_NUM 1
#define FACE_3D_FEATURE_NUM 2
#define FACE_2D_FEATURE_NUM 3
#define KERNEL_PROTECT_RGN_NUM (SUB_RGN_MAX_NUM + 1)
#define HIFI_REBOOT_RGN_NUM (SUB_RGN_MAX_NUM + 2)
#define RECOVERY_RGN_NUM HIFI_REBOOT_RGN_NUM
#define KERNEL_PRMEM_RGN_NUM (SUB_RGN_MAX_NUM + 3)
#define RESERVED_RGN_NUM KERNEL_PRMEM_RGN_NUM
#define DMSS_ASI_PERI_RGN_NUM 32
#define SUB_BIT_RGN_NUM_MAX 3
#define SUB_BIT_RGN_NUM_0 0
#define SUB_BIT_RGN_NUM_1 1
#define SUB_BIT_RGN_NUM_2 2
#define SUB_BIT_RGN_NUM_3 3
#define SUB_GRN_ZONE_1M 0x100000U
#define SUB_GRN_ZONE_2M 0x200000U
#define SUB_BIT_MIN_NUM 1
#define SUB_BIT_MAX_NUM 128
#define SUB_RGN_DISABLE 0xffffffff
#define SUB_RGN_NUM(rgn_num) ((rgn_num) - 1)
#define IVP_ASI_NUM 1
#define ISP_ASI_NUM 3
#define SUBSYS_ASI_NUM 5
#define CPU_ASI_NUM 6
#define NPU_ASI_NUM 8
#define GPU_ASI_NUM 13
#define MODEM_ASI_MASK ((1U << 0) | (1U << 12))
#define VDEC_IVP_ASI_MASK (1U << IVP_ASI_NUM)
#define ISP_DSS_ASI_MASK (1U << ISP_ASI_NUM)
#define SUBSYS_ASI_MASK (1U << SUBSYS_ASI_NUM)
#define CPU_ASI_MASK (1U << CPU_ASI_NUM)
#define NPU_ASI_MASK (1U << NPU_ASI_NUM)
#define GPU_ASI_MASK (1U << GPU_ASI_NUM)
#define ALL_ASI_MASK ((1U << ASI_NUM_MAX) - 1)
#define DDR_SEC_ALL_ASI_MASK (MODEM_ASI_MASK | VDEC_IVP_ASI_MASK | \
 ISP_DSS_ASI_MASK | SUBSYS_ASI_MASK | CPU_ASI_MASK | NPU_ASI_MASK | GPU_ASI_MASK)
#define ASI_MAX_RGN 32
#define DDR_SEC_GRANULARITY 16
#define REG_BIT_NUM 32
#define KERNEL_END_ADDR RESERVED_KERNEL_CAN_RUN_END
#define INVALID_REGION_INDEX 0x5e5e5e5e
#define BITS_WIDTH_MASK(num) ((u32)(((1UL << (num)) - 1)))
#define VALUE_SHIFT_WIDTH(value,width_bit) ((u32)((value) << (width_bit)))
#ifndef BITS_MASK
#define BITS_MASK(start,end) \
 (((0x1ULL << (unsigned int)(((end) - (start)) + 1)) - 1) << (start))
#endif
#define TRANSFORM_TO_SEC_RGN_CFG_ADDR(addr) \
 (((~(BITS_MASK(0, DDR_SEC_GRANULARITY - 1))) & (addr)) >> DDR_SEC_GRANULARITY)
#define IPC_EXCEPTED_RST 0
#define IPC_NOT_EXCEPTED_RST (-1)
#define DDR_NO_CFG_TYPE 0xFFFFFFFF
#define MPU_CHECK_SEC_ADDR_BIT 0
#define MPU_CHECK_UNSEC_ADDR_BIT 1
#define MPU_CHECK_SEC_ADDR (1ULL << MPU_CHECK_SEC_ADDR_BIT)
#define MPU_CHECK_UNSEC_ADDR (1ULL << MPU_CHECK_UNSEC_ADDR_BIT)
#define MPU_CHECK_MIXED_ATTR_ADDR ((1ULL << MPU_CHECK_SEC_ADDR_BIT) | (1ULL << MPU_CHECK_UNSEC_ADDR_BIT))
enum sec_rgn_cover_status {
 COVERED = 0,
 NO_COVERED
};
enum ddr_ipc_type {
 DDR_TEEOS_CFG_HIFI_RESET = 0,
 DDR_TEEOS_CFG_SUB_RGN,
 DDR_TEEOS_CFG_MPU,
 DDR_TEEOS_CHECK_SEC_REGION,
 DDR_TEEOS_CFG_DMSS_REG,
 DDR_TEEOS_GET_CPU_REG,
 DDR_TEEOS_RESERVED_ADDR,
 DDR_TEEOS_CFG_DDRC_CA_REG,
 DDR_TEEOS_TZMP2_CHK_SEC,
 DDR_BL31_KERNEL_CODE_PROTECT,
 DDR_BL31_KERNEL_PRMEM_PROTECT,
 DDR_BL31_GET_CHECK_PHY_ADDR_INFO,
 DDR_BL31_INSTRUMENT_CFG_SWITCH,
 DDR_CFG_SEC_EC_LOCK,
 DDR_IPC_TYPE_MAX
};
enum reg_cfg_type {
 DDR_GET_DMSS_VAL = 0,
 DDR_SET_DDRC_CA_VAL
};
enum ddr_ipc_cfg_type {
 DDR_IPC_SET_SEC = 0,
 DDR_IPC_UNSET_SEC,
 DDR_IPC_CHECK_SEC,
 DDR_IPC_CHECK_UNSEC
};
enum mpu_ipc_cfg_type {
 MPU_IPC_SET_SEC = 0,
 MPU_IPC_UNSET_SEC,
 MPU_IPC_CHECK_SEC
};
enum {
 ASI_NUM_0 = 0,
 ASI_NUM_1,
 ASI_NUM_2,
 ASI_NUM_3,
 ASI_NUM_4,
 ASI_NUM_5,
 ASI_NUM_6,
 ASI_NUM_7,
 ASI_NUM_8,
 ASI_NUM_9,
 ASI_NUM_10,
 ASI_NUM_11,
 ASI_NUM_12,
 ASI_NUM_13,
 ASI_NUM_14,
 ASI_NUM_15,
 ASI_NUM_16,
};
enum asi_num_type {
 ASI_NUM_TYPE_0 = 0,
 ASI_NUM_TYPE_1n2,
 ASI_NUM_TYPE_3n4,
 ASI_NUM_TYPE_5,
 ASI_NUM_TYPE_6n7,
 ASI_NUM_TYPE_8n9,
 ASI_NUM_TYPE_12,
 ASI_NUM_TYPE_13n14n15n16,
 ASI_NUM_TYPE_MAX,
};
struct sec_rgn_cfg {
 unsigned int rgn_en : 1;
 unsigned int attri : 4;
 unsigned long long start_addr;
 unsigned long long end_addr;
 unsigned int mid_wr;
 unsigned int mid_rd;
};
struct sec_cfg_ipc_info {
 unsigned int ipc_cmd;
 unsigned int ack;
 unsigned int sec_ipc_type;
 unsigned int sec_cfg_type;
 unsigned reserved[4];
};
struct sec_ipc_common_info {
 unsigned int sec_ipc_type;
 unsigned int sec_cfg_type;
};
struct sub_rgn_cfg {
 unsigned int sec_feature;
 unsigned int region_num;
 unsigned long long start_addr;
 unsigned long long end_addr;
 unsigned int granularity_size;
};
struct teeos_rgn_cfg_info {
 struct sec_ipc_common_info common_info;
 unsigned long long start_addr;
 unsigned long long end_addr;
};
struct teeos_rgn_check_info {
 struct sec_ipc_common_info common_info;
 unsigned long long start_addr;
 unsigned long long end_addr;
};
struct teeos_sub_rgn_cfg_info {
 struct sec_ipc_common_info common_info;
 struct sub_rgn_cfg sub_pro_cfg;
 unsigned int sub_rgn_cfg_addr;
 unsigned int sub_rgn_cfg_size;
};
struct teeos_check_reserved_addr {
 struct sec_ipc_common_info common_info;
 struct sub_rgn_cfg sub_pro_cfg;
 unsigned long long addr;
 unsigned long long size;
};
struct asi_sec_rgn_regs {
 SOC_DMSS_ASI_SEC_RGN_MAP0_UNION rgn_map0;
 SOC_DMSS_ASI_SEC_RGN_MAP1_UNION rgn_map1;
 SOC_DMSS_ASI_SEC_MID_WR_UNION rgn_mid_wr;
 SOC_DMSS_ASI_SEC_MID_RD_UNION rgn_mid_rd;
};
struct asi_sec_rgn_info {
 SOC_DMSS_ASI_RTL_INF2_UNION asi_rtl_inf2;
 struct asi_sec_rgn_regs regs[DMSS_SEC_REGION_MAX];
};
struct teeos_cpu_sec_rgn_info {
 struct sec_ipc_common_info common_info;
 struct asi_sec_rgn_info rgn_info;
};
struct teeos_hifi_reset_cfg_info {
 struct sec_ipc_common_info common_info;
 unsigned long long start_addr;
 unsigned long long end_addr;
};
struct teeos_hifi_reset_clean_info {
 struct sec_ipc_common_info common_info;
};
struct teeos_cfg_dmss_reg_info {
 struct sec_ipc_common_info common_info;
 unsigned int reg_shift_addr;
 unsigned int reg_val;
};
struct teeos_ddrc_ca_cfg_info {
 struct sec_ipc_common_info common_info;
 unsigned int ca_rd_enable;
};
struct teeos_tzmp2_cfg_info {
 struct sec_ipc_common_info common_info;
 unsigned int start_reg;
 unsigned int reg_start_bit;
 unsigned int bit_length_total;
};
struct teeos_share_mem_tzmp2_info {
 struct teeos_cfg_dmss_reg_info cfg_dmss_reg_info;
 struct teeos_tzmp2_cfg_info tzmp2_cfg_info;
};
struct teeos_tzmp2_check_sec_info {
 struct sec_ipc_common_info common_info;
 unsigned int start_reg;
 unsigned int start_bit;
 unsigned int bit_length;
};
struct bl31_sec_rgn_set_info {
 struct sec_ipc_common_info common_info;
 struct sec_rgn_cfg rgn_info;
};
struct bl31_check_phy_addr_key_info {
 struct sec_ipc_common_info common_info;
 unsigned int asi_num;
 unsigned int attri;
 unsigned int mid;
 unsigned long long start_addr;
 unsigned long long end_addr;
};
struct bl31_check_phy_addr_sec_info {
 struct bl31_check_phy_addr_key_info key_info;
 struct asi_sec_rgn_info rgn_info;
};
struct bl31_kernel_code_cfg_info {
 struct sec_ipc_common_info common_info;
 unsigned long long start_addr;
 unsigned long long end_addr;
};
struct bl31_kernel_prmem_cfg_info {
 struct sec_ipc_common_info common_info;
 unsigned long long start_addr;
 unsigned long long end_addr;
};
enum teeos_share_mem_index {
 TEEOS_SUB_RGN_CFG = 0,
 TEEOS_RGN_CHECK,
 TEEOS_HIFI_RESET_CFG,
 TEEOS_HIFI_RESET_CLEAN,
 TEEOS_CPU_SEC_RGN,
 TEEOS_CHK_RESERVED_ADDR,
 TEEOS_CFG_DMSS_REG,
 TEEOS_CFG_DDRC_CA_REG,
 TEEOS_TZMP2_CFG,
 TEEOS_TZMP2_CHK_SEC,
 TEEOS_SEC_PROTECT_TYPE_MAX
};
struct teeos_share_mem_phy_map {
 unsigned long long phy_addr;
 unsigned long long phy_size;
 unsigned long long map_addr;
};
#define ALIGN_BYTES 8
#define _ALIGN(addr,size) (((addr) + (size) - 1) & (~((size) - 1)))
#define DDR_DMSS_SEC_ENHANCE_INFO_BASE RESERVED_DMSS_REGS_BACKUP_BASE
#define DDR_DMSS_SEC_ENHANCE_INFO_SIZE (0x1000)
#define DDR_SEC_DMSS_MNTN_SHARE_MEM_INFO_BASE DDR_DMSS_SEC_ENHANCE_INFO_BASE
#define DDR_SEC_DMSS_MNTN_IPC_INFO_ADDR DDR_SEC_DMSS_MNTN_SHARE_MEM_INFO_BASE
#define DDR_SEC_DMSS_MNTN_IPC_INFO_SIZE _ALIGN(sizeof(struct ddr_mntn_ipc_info), ALIGN_BYTES)
#define DDR_SEC_DMSS_MNTN_REGS_INFO_ADDR (DDR_SEC_DMSS_MNTN_IPC_INFO_ADDR + DDR_SEC_DMSS_MNTN_IPC_INFO_SIZE)
#define DDR_SEC_DMSS_MNTN_REGS_INFO_SIZE _ALIGN(sizeof(struct ddr_dmss_mntn_desc), ALIGN_BYTES)
#define DDR_SEC_DMSS_MNTN_SHARE_MEM_INFO_SIZE (DDR_SEC_DMSS_MNTN_IPC_INFO_SIZE + \
       DDR_SEC_DMSS_MNTN_REGS_INFO_SIZE)
#define DDR_TEEOS_SHARE_MEM_RGN_INFO_BASE (DDR_SEC_DMSS_MNTN_SHARE_MEM_INFO_BASE + DDR_SEC_DMSS_MNTN_SHARE_MEM_INFO_SIZE)
#define DDR_TEEOS_SUB_RGN_CFG_INFO_BASE DDR_TEEOS_SHARE_MEM_RGN_INFO_BASE
#define DDR_TEEOS_SUB_RGN_CFG_INFO_SIZE _ALIGN((sizeof(struct teeos_sub_rgn_cfg_info)), ALIGN_BYTES)
#define DDR_TEEOS_RGN_CHECK_INFO_BASE (DDR_TEEOS_SUB_RGN_CFG_INFO_BASE + DDR_TEEOS_SUB_RGN_CFG_INFO_SIZE)
#define DDR_TEEOS_RGN_CHECK_INFO_SIZE _ALIGN((sizeof(struct teeos_rgn_check_info)), ALIGN_BYTES)
#define DDR_TEEOS_HIFI_RESET_CFG_INFO_BASE (DDR_TEEOS_RGN_CHECK_INFO_BASE + DDR_TEEOS_RGN_CHECK_INFO_SIZE)
#define DDR_TEEOS_HIFI_RESET_CFG_INFO_SIZE _ALIGN((sizeof(struct teeos_hifi_reset_cfg_info)), ALIGN_BYTES)
#define DDR_TEEOS_HIFI_RESET_CLEAN_INFO_BASE (DDR_TEEOS_HIFI_RESET_CFG_INFO_BASE + DDR_TEEOS_HIFI_RESET_CFG_INFO_SIZE)
#define DDR_TEEOS_HIFI_RESET_CLEAN_INFO_SIZE _ALIGN((sizeof(struct teeos_hifi_reset_clean_info)), ALIGN_BYTES)
#define DDR_TEEOS_CPU_SEC_RGN_INFO_BASE (DDR_TEEOS_HIFI_RESET_CLEAN_INFO_BASE + DDR_TEEOS_HIFI_RESET_CLEAN_INFO_SIZE)
#define DDR_TEEOS_CPU_SEC_RGN_INFO_SIZE _ALIGN((sizeof(struct teeos_cpu_sec_rgn_info)), ALIGN_BYTES)
#define DDR_TEEOS_CHK_RESERVED_ADDR_BASE (DDR_TEEOS_CPU_SEC_RGN_INFO_BASE + DDR_TEEOS_CPU_SEC_RGN_INFO_SIZE)
#define DDR_TEEOS_CHK_RESERVED_ADDR_SIZE _ALIGN((sizeof(struct teeos_check_reserved_addr)), ALIGN_BYTES)
#define DDR_TEEOS_SHARE_MEM_RGN_INFO_SIZE (DDR_TEEOS_SUB_RGN_CFG_INFO_SIZE + \
       DDR_TEEOS_RGN_CHECK_INFO_SIZE + DDR_TEEOS_HIFI_RESET_CFG_INFO_SIZE + \
       DDR_TEEOS_HIFI_RESET_CLEAN_INFO_SIZE + DDR_TEEOS_CPU_SEC_RGN_INFO_SIZE + \
       DDR_TEEOS_CHK_RESERVED_ADDR_SIZE)
#define DDR_TEEOS_SHARE_MEM_TZMP2_INFO_BASE (DDR_TEEOS_SHARE_MEM_RGN_INFO_BASE + DDR_TEEOS_SHARE_MEM_RGN_INFO_SIZE)
#define DDR_TEEOS_CFG_DMSS_REG_INFO_BASE DDR_TEEOS_SHARE_MEM_TZMP2_INFO_BASE
#define DDR_TEEOS_CFG_DMSS_REG_INFO_SIZE _ALIGN((sizeof(struct teeos_cfg_dmss_reg_info)), ALIGN_BYTES)
#define DDR_TEEOS_CFG_DDRC_CA_REG_INFO_BASE (DDR_TEEOS_CFG_DMSS_REG_INFO_BASE + DDR_TEEOS_CFG_DMSS_REG_INFO_SIZE)
#define DDR_TEEOS_CFG_DDRC_CA_REG_INFO_SIZE _ALIGN((sizeof(struct teeos_ddrc_ca_cfg_info)), ALIGN_BYTES)
#define DDR_TEEOS_TZMP2_CFG_INFO_BASE (DDR_TEEOS_CFG_DDRC_CA_REG_INFO_BASE + DDR_TEEOS_CFG_DDRC_CA_REG_INFO_SIZE)
#define DDR_TEEOS_TZMP2_CFG_INFO_SIZE _ALIGN((sizeof(struct teeos_tzmp2_cfg_info)), ALIGN_BYTES)
#define DDR_TEEOS_TZMP2_CHK_SEC_BASE (DDR_TEEOS_TZMP2_CFG_INFO_BASE + DDR_TEEOS_TZMP2_CFG_INFO_SIZE)
#define DDR_TEEOS_TZMP2_CHK_SEC_SIZE _ALIGN((sizeof(struct teeos_tzmp2_check_sec_info)), ALIGN_BYTES)
#define DDR_TEEOS_SHARE_MEM_TZMP2_INFO_SIZE (DDR_TEEOS_CFG_DMSS_REG_INFO_SIZE + DDR_TEEOS_CFG_DDRC_CA_REG_INFO_SIZE + \
       DDR_TEEOS_TZMP2_CFG_INFO_SIZE + DDR_TEEOS_TZMP2_CHK_SEC_SIZE)
#define DDR_BL31_SHARE_MEM_RGN_INFO_BASE (DDR_TEEOS_SHARE_MEM_TZMP2_INFO_BASE + DDR_TEEOS_SHARE_MEM_TZMP2_INFO_SIZE)
#define DDR_BL31_KERNEL_CODE_CFG_INFO_BASE DDR_BL31_SHARE_MEM_RGN_INFO_BASE
#define DDR_BL31_KERNEL_CODE_CFG_INFO_SIZE _ALIGN((sizeof(struct bl31_kernel_code_cfg_info)), ALIGN_BYTES)
#define DDR_BL31_KERNEL_PRMEM_CFG_INFO_BASE (DDR_BL31_KERNEL_CODE_CFG_INFO_BASE + DDR_BL31_KERNEL_CODE_CFG_INFO_SIZE)
#define DDR_BL31_KERNEL_PRMEM_CFG_INFO_SIZE _ALIGN((sizeof(struct bl31_kernel_prmem_cfg_info)), ALIGN_BYTES)
#define DDR_BL31_CHECK_PHY_ADDR_SEC_INFO_BASE (DDR_BL31_KERNEL_PRMEM_CFG_INFO_BASE + DDR_BL31_KERNEL_PRMEM_CFG_INFO_SIZE)
#define DDR_BL31_CHECK_PHY_ADDR_SEC_INFO_SIZE _ALIGN((sizeof(struct bl31_check_phy_addr_sec_info)), ALIGN_BYTES)
#define DDR_BL31_SHARE_MEM_RGN_INFO_SIZE (DDR_BL31_KERNEL_CODE_CFG_INFO_SIZE + DDR_BL31_KERNEL_PRMEM_CFG_INFO_SIZE + \
       DDR_BL31_CHECK_PHY_ADDR_SEC_INFO_SIZE)
#define DDR_SEC_PROTECT_USED_END_ADDR (DDR_BL31_SHARE_MEM_RGN_INFO_BASE + DDR_BL31_SHARE_MEM_RGN_INFO_SIZE)
#define DDR_SEC_DMSS_BACKUP_ADDR (DDR_DMSS_SEC_ENHANCE_INFO_BASE + DDR_DMSS_SEC_ENHANCE_INFO_SIZE)
#define DDR_SEC_DMSS_BACKUP_SIZE 0x4000
 #define M3_DDR_STORAGE_MEM_DDR_MPU_ADDR (DDR_SEC_DMSS_BACKUP_ADDR)
 #define M3_DDR_STORAGE_MEM_DDR_MPU_SIZE (0x2400)
 #define M3_DDR_STORAGE_MEM_DDR_SECURITY_ADDR (M3_DDR_STORAGE_MEM_DDR_MPU_ADDR + M3_DDR_STORAGE_MEM_DDR_MPU_SIZE)
 #define M3_DDR_STORAGE_MEM_DDR_SECURITY_SIZE (0x1800)
 #define DDRC_DDR_PERI_SEC_RGN0_SAVE_BASE (M3_DDR_STORAGE_MEM_DDR_SECURITY_ADDR + M3_DDR_STORAGE_MEM_DDR_SECURITY_SIZE)
 #define DDRC_DDR_PERI_SEC_RGN0_SAVE_SIZE DDRC_LPRAM_PERI_SEC_RGN0_SAVE_SIZE
 #define DDRC_DDR_PERI_SEC_RGNX_SAVE_BASE (DDRC_DDR_PERI_SEC_RGN0_SAVE_BASE + DDRC_DDR_PERI_SEC_RGN0_SAVE_SIZE)
 #define DDRC_DDR_PERI_SEC_RGNX_SAVE_SIZE DDRC_LPRAM_PERI_SEC_RGNX_SAVE_SIZE
#if ((DDRC_DDR_PERI_SEC_RGNX_SAVE_BASE + DDRC_DDR_PERI_SEC_RGNX_SAVE_SIZE) > (DDR_SEC_DMSS_BACKUP_ADDR + DDR_SEC_DMSS_BACKUP_SIZE))
 #error "ddr sec dmss backup is overflow!!"
#endif
#define DDR_SEC_PROTECT_MAX_END_ADDR (RESERVED_DMSS_REGS_BACKUP_BASE + RESERVED_DMSS_REGS_BACKUP_SIZE)
#endif
