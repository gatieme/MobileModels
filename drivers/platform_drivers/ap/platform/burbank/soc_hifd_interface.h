#ifndef __SOC_HIFD_INTERFACE_H__
#define __SOC_HIFD_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HiFD_VERSION_ADDR(base) ((base) + (0x0000UL))
#define SOC_HiFD_MEM_DEEP_SLP_OFF_ADDR(base) ((base) + (0x0004UL))
#define SOC_HiFD_START_ADDR(base) ((base) + (0x0010UL))
#define SOC_HiFD_HIFD_CLK_SEL_ADDR(base) ((base) + (0x0014UL))
#define SOC_HiFD_HIFD_CLK_EN_ADDR(base) ((base) + (0x0018UL))
#define SOC_HiFD_AUTO_CLR_EN_ADDR(base) ((base) + (0x001CUL))
#define SOC_HiFD_STATUS_ADDR(base) ((base) + (0x0020UL))
#define SOC_HiFD_BASE_ADDR_ADDR(base) ((base) + (0x0028UL))
#define SOC_HiFD_BASE_ADDR0_HI_ADDR(base) ((base) + (0x002CUL))
#define SOC_HiFD_MEM_CTRL_ADDR(base) ((base) + (0x0030UL))
#define SOC_HiFD_CFG_PM_CTRL_ADDR(base) ((base) + (0x0034UL))
#define SOC_HiFD_FDAI_INSTR_MEM_DSLP_EN_ADDR(base) ((base) + (0x0038UL))
#define SOC_HiFD_FDAI_INTS_ADDR(base) ((base) + (0x0040UL))
#define SOC_HiFD_FDAI_INT_MSK_ADDR(base) ((base) + (0x0044UL))
#define SOC_HiFD_CLEAR_EN_ADDR(base) ((base) + (0x0050UL))
#define SOC_HiFD_CLEAR_HOLD_TIME_ADDR(base) ((base) + (0x0054UL))
#define SOC_HiFD_CLEAR_STATE_ADDR(base) ((base) + (0x0058UL))
#define SOC_HiFD_CLEAR_DEBUG_IN_ADDR(base) ((base) + (0x005cUL))
#define SOC_HiFD_CLEAR_DEBUG_OUT_ADDR(base) ((base) + (0x0060UL))
#define SOC_HiFD_SPM_ERR_STATE_ADDR(base) ((base) + (0x0068UL))
#define SOC_HiFD_IPU_ARMPRESS_ADDR(base) ((base) + (0x0070UL))
#define SOC_HiFD_FDAI_RESERVE1_ADDR(base) ((base) + (0x0074UL))
#define SOC_HiFD_IPU_AWMPRESS_ADDR(base) ((base) + (0x0078UL))
#define SOC_HiFD_FDAI_RESERVE3_ADDR(base) ((base) + (0x007CUL))
#define SOC_HiFD_RECIP_4_ADDR(base) ((base) + (0x0080UL))
#define SOC_HiFD_RECIP_2_ADDR(base) ((base) + (0x0084UL))
#define SOC_HiFD_RECIP_9_ADDR(base) ((base) + (0x0088UL))
#define SOC_HiFD_RECIP_6_ADDR(base) ((base) + (0x008cUL))
#define SOC_HiFD_RECIP_3_ADDR(base) ((base) + (0x0090UL))
#define SOC_HiFD_RECIP_49_ADDR(base) ((base) + (0x0094UL))
#define SOC_HiFD_CAU_IMEM_LOAD_ADDR_ADDR(base) ((base) + (0x0098UL))
#define SOC_HiFD_CAU_RF_ADDR_ADDR(base) ((base) + (0x009CUL))
#define SOC_HiFD_CAU_RF_DATA_ADDR(base) ((base) + (0x0100UL))
#define SOC_HiFD_CAU_ID_PC_ADDR(base) ((base) + (0x0104UL))
#define SOC_HiFD_CAU_ID_INSTR_H_ADDR(base) ((base) + (0x0108UL))
#define SOC_HiFD_CAU_ID_INSTR_L_ADDR(base) ((base) + (0x010CUL))
#define SOC_HiFD_CAU_STATUS_ADDR(base) ((base) + (0x0110UL))
#define SOC_HiFD_CAU_DEBUG_INSTR_NUM_ADDR(base) ((base) + (0x0114UL))
#define SOC_HiFD_CAU_MAXPL_PAD_ADDR(base) ((base) + (0x0118UL))
#define SOC_HiFD_CAU_RESERVE9_ADDR(base) ((base) + (0x011CUL))
#define SOC_HiFD_CAU_STATUS1_ADDR(base) ((base) + (0x0120UL))
#define SOC_HiFD_CAU_STATUS2_ADDR(base) ((base) + (0x0124UL))
#define SOC_HiFD_CAU_STATUS3_ADDR(base) ((base) + (0x0128UL))
#define SOC_HiFD_MQ_RDMA_ORD_EN_ADDR(base) ((base) + (0x0130UL))
#define SOC_HiFD_VPU_RSV0_ADDR(base) ((base) + (0x0134UL))
#define SOC_HiFD_VPU_RSV1_ADDR(base) ((base) + (0x0138UL))
#define SOC_HiFD_VPU_RSV2_ADDR(base) ((base) + (0x013CUL))
#define SOC_HiFD_VPU_RSV3_ADDR(base) ((base) + (0x0140UL))
#define SOC_HiFD_VPU_RSV4_ADDR(base) ((base) + (0x0144UL))
#define SOC_HiFD_VPU_RSV5_ADDR(base) ((base) + (0x0148UL))
#define SOC_HiFD_VPU_RSV6_ADDR(base) ((base) + (0x014CUL))
#define SOC_HiFD_VPU_RSV7_ADDR(base) ((base) + (0x0150UL))
#define SOC_HiFD_PSCOEFS_VAL0_ADDR(base) ((base) + (0x0200UL))
#define SOC_HiFD_PSCOEFS_VAL1_ADDR(base) ((base) + (0x0204UL))
#define SOC_HiFD_PSCOEFS_VAL2_ADDR(base) ((base) + (0x0208UL))
#define SOC_HiFD_PSCOEFS_VAL3_ADDR(base) ((base) + (0x020cUL))
#define SOC_HiFD_PSCOEFS_VAL4_ADDR(base) ((base) + (0x0210UL))
#define SOC_HiFD_PSCOEFS_VAL5_ADDR(base) ((base) + (0x0214UL))
#define SOC_HiFD_PSCOEFS_VAL6_ADDR(base) ((base) + (0x0218UL))
#define SOC_HiFD_PSCOEFS_VAL7_ADDR(base) ((base) + (0x021cUL))
#define SOC_HiFD_PSCOEFS_VAL8_ADDR(base) ((base) + (0x0220UL))
#define SOC_HiFD_PSCOEFS_VAL9_ADDR(base) ((base) + (0x0224UL))
#define SOC_HiFD_PSCOEFS_VAL10_ADDR(base) ((base) + (0x0228UL))
#define SOC_HiFD_PSCOEFS_VAL11_ADDR(base) ((base) + (0x022cUL))
#define SOC_HiFD_PSCOEFS_VAL12_ADDR(base) ((base) + (0x0230UL))
#define SOC_HiFD_PSCOEFS_VAL13_ADDR(base) ((base) + (0x0234UL))
#define SOC_HiFD_PSCOEFS_VAL14_ADDR(base) ((base) + (0x0238UL))
#define SOC_HiFD_PSCOEFS_VAL15_ADDR(base) ((base) + (0x023cUL))
#define SOC_HiFD_PROP_CFG1_ADDR(base) ((base) + (0x0400UL))
#define SOC_HiFD_PROP_CFG2_ADDR(base) ((base) + (0x0404UL))
#define SOC_HiFD_PROP_CFG3_ADDR(base) ((base) + (0x0408UL))
#define SOC_HiFD_PROP_CFG4_ADDR(base) ((base) + (0x040cUL))
#define SOC_HiFD_PROP_CFG5_ADDR(base) ((base) + (0x0410UL))
#define SOC_HiFD_PROP_CFG6_ADDR(base) ((base) + (0x0414UL))
#define SOC_HiFD_PROP_CFG7_ADDR(base) ((base) + (0x0418UL))
#define SOC_HiFD_PROP_CFG8_ADDR(base) ((base) + (0x041CUL))
#define SOC_HiFD_PROP_CFG9_ADDR(base) ((base) + (0x0420UL))
#define SOC_HiFD_PROP_CFG10_ADDR(base) ((base) + (0x0424UL))
#define SOC_HiFD_PROP_CFG11_ADDR(base) ((base) + (0x0428UL))
#define SOC_HiFD_PROP_CFG12_ADDR(base) ((base) + (0x042CUL))
#define SOC_HiFD_PROP_CFG13_ADDR(base) ((base) + (0x0430UL))
#define SOC_HiFD_PROP_CFG14_ADDR(base) ((base) + (0x0434UL))
#define SOC_HiFD_PROP_CFG15_ADDR(base) ((base) + (0x0438UL))
#define SOC_HiFD_PROP_CFG16_ADDR(base) ((base) + (0x043CUL))
#define SOC_HiFD_PROP_CFG17_ADDR(base) ((base) + (0x0440UL))
#define SOC_HiFD_PROP_CFG18_ADDR(base) ((base) + (0x0444UL))
#define SOC_HiFD_PROP_CFG19_ADDR(base) ((base) + (0x0448UL))
#define SOC_HiFD_PROP_CFG20_ADDR(base) ((base) + (0x044CUL))
#define SOC_HiFD_PROP_CFG21_ADDR(base) ((base) + (0x0450UL))
#define SOC_HiFD_PROP_CFG22_ADDR(base) ((base) + (0x0454UL))
#define SOC_HiFD_PROP_CFG23_ADDR(base) ((base) + (0x0458UL))
#define SOC_HiFD_PROP_CFG24_ADDR(base) ((base) + (0x045CUL))
#define SOC_HiFD_PROP_CFG25_ADDR(base) ((base) + (0x0460UL))
#define SOC_HiFD_PROP_CFG26_ADDR(base) ((base) + (0x0464UL))
#define SOC_HiFD_PROP_CFG27_ADDR(base) ((base) + (0x0468UL))
#define SOC_HiFD_PROP_CFG28_ADDR(base) ((base) + (0x046CUL))
#define SOC_HiFD_PROP_CFG29_ADDR(base) ((base) + (0x0470UL))
#define SOC_HiFD_PROP_CFG30_ADDR(base) ((base) + (0x0474UL))
#define SOC_HiFD_PROP_CFG31_ADDR(base) ((base) + (0x0478UL))
#define SOC_HiFD_PROP_CFG32_ADDR(base) ((base) + (0x047CUL))
#define SOC_HiFD_PROP_CFG33_ADDR(base) ((base) + (0x0480UL))
#define SOC_HiFD_PROP_CFG34_ADDR(base) ((base) + (0x0484UL))
#define SOC_HiFD_PROP_CFG35_ADDR(base) ((base) + (0x0488UL))
#define SOC_HiFD_PROP_CFG36_ADDR(base) ((base) + (0x048CUL))
#define SOC_HiFD_PROP_CFG37_ADDR(base) ((base) + (0x0490UL))
#define SOC_HiFD_PROP_CFG38_ADDR(base) ((base) + (0x0494UL))
#define SOC_HiFD_PROP_CFG39_ADDR(base) ((base) + (0x0498UL))
#define SOC_HiFD_PROP_CFG40_ADDR(base) ((base) + (0x049CUL))
#define SOC_HiFD_PROP_CFG41_ADDR(base) ((base) + (0x04A0UL))
#define SOC_HiFD_PROP_CFG42_ADDR(base) ((base) + (0x04A4UL))
#define SOC_HiFD_PROP_CFG43_ADDR(base) ((base) + (0x04A8UL))
#define SOC_HiFD_PROP_CFG44_ADDR(base) ((base) + (0x04ACUL))
#define SOC_HiFD_PROP_CFG45_ADDR(base) ((base) + (0x04B0UL))
#define SOC_HiFD_PROP_CFG46_ADDR(base) ((base) + (0x04B4UL))
#define SOC_HiFD_PROP_CFG47_ADDR(base) ((base) + (0x04B8UL))
#define SOC_HiFD_PROP_CFG48_ADDR(base) ((base) + (0x04BCUL))
#define SOC_HiFD_PROP_CFG49_ADDR(base) ((base) + (0x04C0UL))
#define SOC_HiFD_PROP_CFG50_ADDR(base) ((base) + (0x04C4UL))
#define SOC_HiFD_PROP_CFG51_ADDR(base) ((base) + (0x04C8UL))
#define SOC_HiFD_PROP_CFG52_ADDR(base) ((base) + (0x04CCUL))
#define SOC_HiFD_PROP_CFG53_ADDR(base) ((base) + (0x04D0UL))
#define SOC_HiFD_PROP_CFG54_ADDR(base) ((base) + (0x04D4UL))
#define SOC_HiFD_PROP_CFG55_ADDR(base) ((base) + (0x04D8UL))
#define SOC_HiFD_PROP_CFG56_ADDR(base) ((base) + (0x04DCUL))
#define SOC_HiFD_PROP_CFG57_ADDR(base) ((base) + (0x04E0UL))
#define SOC_HiFD_PROP_CFG58_ADDR(base) ((base) + (0x04E4UL))
#define SOC_HiFD_PROP_CFG59_ADDR(base) ((base) + (0x04E8UL))
#define SOC_HiFD_PROP_CFG60_ADDR(base) ((base) + (0x04ECUL))
#define SOC_HiFD_PROP_CFG61_ADDR(base) ((base) + (0x04F0UL))
#define SOC_HiFD_PROP_CFG62_ADDR(base) ((base) + (0x04F4UL))
#define SOC_HiFD_PROP_CFG63_ADDR(base) ((base) + (0x04F8UL))
#define SOC_HiFD_PROP_CFG64_ADDR(base) ((base) + (0x04FCUL))
#define SOC_HiFD_MODULE_CLK_SEL_ADDR(base) ((base) + (0x0500UL))
#define SOC_HiFD_MODULE_CLK_EN_ADDR(base) ((base) + (0x0504UL))
#define SOC_HiFD_CH_CLK_SEL_ADDR(base) ((base) + (0x0508UL))
#define SOC_HiFD_CH_CLK_EN_ADDR(base) ((base) + (0x050CUL))
#define SOC_HiFD_PRE_SAMP_Y_OFFSET_ADDR(base) ((base) + (0x0800UL))
#define SOC_HiFD_PRE_SAMP_WIDTH_ADDR(base) ((base) + (0x0804UL))
#define SOC_HiFD_PRE_MODE_ADDR(base) ((base) + (0x0808UL))
#define SOC_HiFD_PRE_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0820UL))
#define SOC_HiFD_PRE_DFC_MODE_ADDR(base) ((base) + (0x0824UL))
#define SOC_HiFD_PRE_DFC_CLIP_CTL_VRT_ADDR(base) ((base) + (0x0828UL))
#define SOC_HiFD_PRE_CSC_IDC0_ADDR(base) ((base) + (0x0840UL))
#define SOC_HiFD_PRE_CSC_IDC2_ADDR(base) ((base) + (0x0844UL))
#define SOC_HiFD_PRE_CSC_ODC0_ADDR(base) ((base) + (0x0848UL))
#define SOC_HiFD_PRE_CSC_ODC2_ADDR(base) ((base) + (0x084CUL))
#define SOC_HiFD_PRE_CSC_P0_ADDR(base) ((base) + (0x0850UL))
#define SOC_HiFD_PRE_CSC_P1_ADDR(base) ((base) + (0x0854UL))
#define SOC_HiFD_PRE_CSC_P2_ADDR(base) ((base) + (0x0858UL))
#define SOC_HiFD_PRE_CSC_P3_ADDR(base) ((base) + (0x085CUL))
#define SOC_HiFD_PRE_CSC_P4_ADDR(base) ((base) + (0x0860UL))
#define SOC_HiFD_PRE_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0864UL))
#define SOC_HiFD_PRE_CSC_MPREC_ADDR(base) ((base) + (0x0868UL))
#define SOC_HiFD_PRE_SCF_INPUT_WIDTH_ADDR(base) ((base) + (0x0880UL))
#define SOC_HiFD_PRE_SCF_OUTPUT_WIDTH_ADDR(base) ((base) + (0x0884UL))
#define SOC_HiFD_PRE_SCF_EN_HSCL_STR_ADDR(base) ((base) + (0x0888UL))
#define SOC_HiFD_PRE_SCF_EN_VSCL_STR_ADDR(base) ((base) + (0x088CUL))
#define SOC_HiFD_PRE_SCF_H_V_ORDER_ADDR(base) ((base) + (0x0890UL))
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_ADDR(base) ((base) + (0x0894UL))
#define SOC_HiFD_PRE_SCF_EN_HSCL_ADDR(base) ((base) + (0x0898UL))
#define SOC_HiFD_PRE_SCF_EN_VSCL_ADDR(base) ((base) + (0x089CUL))
#define SOC_HiFD_PRE_SCF_INC_HSCL_ADDR(base) ((base) + (0x08A0UL))
#define SOC_HiFD_PRE_SCF_INC_VSCL_ADDR(base) ((base) + (0x08A4UL))
#define SOC_HiFD_PRE_POST_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x08C0UL))
#define SOC_HiFD_PRE_REA_WIDTH_ADDR(base) ((base) + (0x08E0UL))
#define SOC_HiFD_PRE_REA_PAD_HRZ_ADDR(base) ((base) + (0x08E4UL))
#define SOC_HiFD_PRE_REA_PAD_SHIFT_ADDR(base) ((base) + (0x08E8UL))
#define SOC_HiFD_RDMA_RAW_EN_ADDR(base) ((base) + (0x0900UL))
#define SOC_HiFD_RDMA_BLOCK_ROT_EN_ADDR(base) ((base) + (0x0904UL))
#define SOC_HiFD_RDMA_OUTSTANGING_ADDR(base) ((base) + (0x0940UL))
#define SOC_HiFD_RDMA_ARCACHE_ADDR(base) ((base) + (0x0944UL))
#define SOC_HiFD_RDMA_ARPROT_ADDR(base) ((base) + (0x0948UL))
#define SOC_HiFD_RDMA_ARQOS_ADDR(base) ((base) + (0x094CUL))
#define SOC_HiFD_RDMA_RESERVE0_ADDR(base) ((base) + (0x0980UL))
#define SOC_HiFD_RDMA_RESERVE1_ADDR(base) ((base) + (0x0984UL))
#define SOC_HiFD_RDMA_RESERVE2_ADDR(base) ((base) + (0x0988UL))
#define SOC_HiFD_RDMA_RESERVE3_ADDR(base) ((base) + (0x098CUL))
#define SOC_HiFD_DMA_AXUSER0_ADDR(base) ((base) + (0x0990UL))
#define SOC_HiFD_DMA_AXCH1_ADDR(base) ((base) + (0x0994UL))
#define SOC_HiFD_DMA_AXCH2_ADDR(base) ((base) + (0x0998UL))
#define SOC_HiFD_DMA_AXCH3_ADDR(base) ((base) + (0x099cUL))
#define SOC_HiFD_DMA_AXCH4_ADDR(base) ((base) + (0x09a0UL))
#define SOC_HiFD_DMA_AXCH5_ADDR(base) ((base) + (0x09a4UL))
#define SOC_HiFD_DMA_AXCH6_ADDR(base) ((base) + (0x09a8UL))
#define SOC_HiFD_DMA_AXCH7_ADDR(base) ((base) + (0x09acUL))
#define SOC_HiFD_DMA_AXCH8_ADDR(base) ((base) + (0x09b0UL))
#define SOC_HiFD_DMA_AXCH9_ADDR(base) ((base) + (0x09b4UL))
#define SOC_HiFD_RDMA_RESERVE4_ADDR(base) ((base) + (0x09b8UL))
#define SOC_HiFD_RDMA_RESERVE5_ADDR(base) ((base) + (0x09bcUL))
#define SOC_HiFD_RDMA_RESERVE6_ADDR(base) ((base) + (0x09c0UL))
#define SOC_HiFD_RDMA_RESERVE7_ADDR(base) ((base) + (0x09c4UL))
#define SOC_HiFD_RDMA_RESERVE8_ADDR(base) ((base) + (0x09c8UL))
#define SOC_HiFD_RDMA_RESERVE9_ADDR(base) ((base) + (0x09ccUL))
#define SOC_HiFD_RDMA_RESERVE10_ADDR(base) ((base) + (0x09d0UL))
#define SOC_HiFD_RDMA_RESERVE11_ADDR(base) ((base) + (0x09d4UL))
#define SOC_HiFD_WDMA_OUTSTANDING_ADDR(base) ((base) + (0x0a00UL))
#define SOC_HiFD_WDMA_RAW_EN_ADDR(base) ((base) + (0x0a04UL))
#define SOC_HiFD_WDMA_BLOCK_ROT_EN_ADDR(base) ((base) + (0x0a08UL))
#define SOC_HiFD_WDMA_HFBCE_AUTO_CLK_GT_EN_ADDR(base) ((base) + (0x0a0cUL))
#define SOC_HiFD_WDMA_THRESHOLD_ADDR(base) ((base) + (0x0a10UL))
#define SOC_HiFD_WDMA_DEBUG0_ADDR(base) ((base) + (0x0a14UL))
#define SOC_HiFD_WDMA_DEBUG1_ADDR(base) ((base) + (0x0a18UL))
#define SOC_HiFD_WDMA_MONITOR0_ADDR(base) ((base) + (0x0a1cUL))
#define SOC_HiFD_WDMA_MONITOR1_ADDR(base) ((base) + (0x0a20UL))
#define SOC_HiFD_WDMA_MONITOR2_ADDR(base) ((base) + (0x0a24UL))
#define SOC_HiFD_WDMA_MONITOR3_ADDR(base) ((base) + (0x0a28UL))
#define SOC_HiFD_WDMA_AWCACHE_ADDR(base) ((base) + (0x0a2cUL))
#define SOC_HiFD_WDMA_AWPROT_ADDR(base) ((base) + (0x0a30UL))
#define SOC_HiFD_WDMA_AWQOS_ADDR(base) ((base) + (0x0a34UL))
#define SOC_HiFD_BASE_ADDR1_ADDR(base) ((base) + (0x0a40UL))
#define SOC_HiFD_BASE_ADDR2_ADDR(base) ((base) + (0x0a44UL))
#define SOC_HiFD_BASE_ADDR3_ADDR(base) ((base) + (0x0a48UL))
#define SOC_HiFD_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0a4cUL))
#define SOC_HiFD_BLOCK_ALIGN_EN_ADDR(base) ((base) + (0x0a50UL))
#define SOC_HiFD_BASE_ADDR1_hi_ADDR(base) ((base) + (0x0a54UL))
#define SOC_HiFD_BASE_ADDR2_hi_ADDR(base) ((base) + (0x0a58UL))
#define SOC_HiFD_BASE_ADDR3_hi_ADDR(base) ((base) + (0x0a5CUL))
#define SOC_HiFD_X2X_ENABLE_DATA_PACKING_N_ADDR(base) ((base) + (0x0b00UL))
#define SOC_HiFD_OUT_OF_BOUNDARY_REPORT_EN_ADDR(base) ((base) + (0x0c00UL))
#define SOC_HiFD_OUT_OF_BOUNDARY_STATUS_ADDR(base) ((base) + (0x0c04UL))
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_ADDR(base) ((base) + (0x0c08UL))
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_SEL_ADDR(base) ((base) + (0x0c0cUL))
#define SOC_HiFD_DEBUG_MODE_ADDR(base) ((base) + (0x0c10UL))
#define SOC_HiFD_DEBUG_STEP_LEN_ADDR(base) ((base) + (0x0c14UL))
#define SOC_HiFD_DEBUG_BREAKPOINT_ADDR(base) ((base) + (0x0c18UL))
#define SOC_HiFD_DEBUG_RUN_ADDR(base) ((base) + (0x0c1cUL))
#define SOC_HiFD_DEBUG_SPM_RD_ADDR(base) ((base) + (0x0c20UL))
#define SOC_HiFD_DEBUG_SPM_ADDR_ADDR(base) ((base) + (0x0c24UL))
#define SOC_HiFD_DEBUG_SPM_RDATA0_ADDR(base) ((base) + (0x0c28UL))
#define SOC_HiFD_DEBUG_SPM_RDATA1_ADDR(base) ((base) + (0x0c2cUL))
#define SOC_HiFD_DEBUG_SPM_RDATA2_ADDR(base) ((base) + (0x0c30UL))
#define SOC_HiFD_DEBUG_SPM_RDATA3_ADDR(base) ((base) + (0x0c34UL))
#define SOC_HiFD_PROP_CFG65_ADDR(base) ((base) + (0x0d00UL))
#define SOC_HiFD_PROP_CFG66_ADDR(base) ((base) + (0x0d04UL))
#define SOC_HiFD_PROP_CFG67_ADDR(base) ((base) + (0x0d08UL))
#define SOC_HiFD_PROP_CFG68_ADDR(base) ((base) + (0x0d0cUL))
#define SOC_HiFD_PROP_CFG69_ADDR(base) ((base) + (0x0d10UL))
#define SOC_HiFD_PROP_CFG70_ADDR(base) ((base) + (0x0d14UL))
#define SOC_HiFD_PROP_CFG71_ADDR(base) ((base) + (0x0d1cUL))
#define SOC_HiFD_PROP_CFG72_ADDR(base) ((base) + (0x0d20UL))
#define SOC_HiFD_PROP_CFG73_ADDR(base) ((base) + (0x0d24UL))
#define SOC_HiFD_PROP_CFG74_ADDR(base) ((base) + (0x0d28UL))
#define SOC_HiFD_PROP_CFG75_ADDR(base) ((base) + (0x0d2cUL))
#define SOC_HiFD_PROP_CFG76_ADDR(base) ((base) + (0x0d30UL))
#define SOC_HiFD_PROP_CFG77_ADDR(base) ((base) + (0x0d34UL))
#define SOC_HiFD_INST_MEM_ADDR(base) ((base) + (0x1000~0x6fffUL))
#else
#define SOC_HiFD_VERSION_ADDR(base) ((base) + (0x0000))
#define SOC_HiFD_MEM_DEEP_SLP_OFF_ADDR(base) ((base) + (0x0004))
#define SOC_HiFD_START_ADDR(base) ((base) + (0x0010))
#define SOC_HiFD_HIFD_CLK_SEL_ADDR(base) ((base) + (0x0014))
#define SOC_HiFD_HIFD_CLK_EN_ADDR(base) ((base) + (0x0018))
#define SOC_HiFD_AUTO_CLR_EN_ADDR(base) ((base) + (0x001C))
#define SOC_HiFD_STATUS_ADDR(base) ((base) + (0x0020))
#define SOC_HiFD_BASE_ADDR_ADDR(base) ((base) + (0x0028))
#define SOC_HiFD_BASE_ADDR0_HI_ADDR(base) ((base) + (0x002C))
#define SOC_HiFD_MEM_CTRL_ADDR(base) ((base) + (0x0030))
#define SOC_HiFD_CFG_PM_CTRL_ADDR(base) ((base) + (0x0034))
#define SOC_HiFD_FDAI_INSTR_MEM_DSLP_EN_ADDR(base) ((base) + (0x0038))
#define SOC_HiFD_FDAI_INTS_ADDR(base) ((base) + (0x0040))
#define SOC_HiFD_FDAI_INT_MSK_ADDR(base) ((base) + (0x0044))
#define SOC_HiFD_CLEAR_EN_ADDR(base) ((base) + (0x0050))
#define SOC_HiFD_CLEAR_HOLD_TIME_ADDR(base) ((base) + (0x0054))
#define SOC_HiFD_CLEAR_STATE_ADDR(base) ((base) + (0x0058))
#define SOC_HiFD_CLEAR_DEBUG_IN_ADDR(base) ((base) + (0x005c))
#define SOC_HiFD_CLEAR_DEBUG_OUT_ADDR(base) ((base) + (0x0060))
#define SOC_HiFD_SPM_ERR_STATE_ADDR(base) ((base) + (0x0068))
#define SOC_HiFD_IPU_ARMPRESS_ADDR(base) ((base) + (0x0070))
#define SOC_HiFD_FDAI_RESERVE1_ADDR(base) ((base) + (0x0074))
#define SOC_HiFD_IPU_AWMPRESS_ADDR(base) ((base) + (0x0078))
#define SOC_HiFD_FDAI_RESERVE3_ADDR(base) ((base) + (0x007C))
#define SOC_HiFD_RECIP_4_ADDR(base) ((base) + (0x0080))
#define SOC_HiFD_RECIP_2_ADDR(base) ((base) + (0x0084))
#define SOC_HiFD_RECIP_9_ADDR(base) ((base) + (0x0088))
#define SOC_HiFD_RECIP_6_ADDR(base) ((base) + (0x008c))
#define SOC_HiFD_RECIP_3_ADDR(base) ((base) + (0x0090))
#define SOC_HiFD_RECIP_49_ADDR(base) ((base) + (0x0094))
#define SOC_HiFD_CAU_IMEM_LOAD_ADDR_ADDR(base) ((base) + (0x0098))
#define SOC_HiFD_CAU_RF_ADDR_ADDR(base) ((base) + (0x009C))
#define SOC_HiFD_CAU_RF_DATA_ADDR(base) ((base) + (0x0100))
#define SOC_HiFD_CAU_ID_PC_ADDR(base) ((base) + (0x0104))
#define SOC_HiFD_CAU_ID_INSTR_H_ADDR(base) ((base) + (0x0108))
#define SOC_HiFD_CAU_ID_INSTR_L_ADDR(base) ((base) + (0x010C))
#define SOC_HiFD_CAU_STATUS_ADDR(base) ((base) + (0x0110))
#define SOC_HiFD_CAU_DEBUG_INSTR_NUM_ADDR(base) ((base) + (0x0114))
#define SOC_HiFD_CAU_MAXPL_PAD_ADDR(base) ((base) + (0x0118))
#define SOC_HiFD_CAU_RESERVE9_ADDR(base) ((base) + (0x011C))
#define SOC_HiFD_CAU_STATUS1_ADDR(base) ((base) + (0x0120))
#define SOC_HiFD_CAU_STATUS2_ADDR(base) ((base) + (0x0124))
#define SOC_HiFD_CAU_STATUS3_ADDR(base) ((base) + (0x0128))
#define SOC_HiFD_MQ_RDMA_ORD_EN_ADDR(base) ((base) + (0x0130))
#define SOC_HiFD_VPU_RSV0_ADDR(base) ((base) + (0x0134))
#define SOC_HiFD_VPU_RSV1_ADDR(base) ((base) + (0x0138))
#define SOC_HiFD_VPU_RSV2_ADDR(base) ((base) + (0x013C))
#define SOC_HiFD_VPU_RSV3_ADDR(base) ((base) + (0x0140))
#define SOC_HiFD_VPU_RSV4_ADDR(base) ((base) + (0x0144))
#define SOC_HiFD_VPU_RSV5_ADDR(base) ((base) + (0x0148))
#define SOC_HiFD_VPU_RSV6_ADDR(base) ((base) + (0x014C))
#define SOC_HiFD_VPU_RSV7_ADDR(base) ((base) + (0x0150))
#define SOC_HiFD_PSCOEFS_VAL0_ADDR(base) ((base) + (0x0200))
#define SOC_HiFD_PSCOEFS_VAL1_ADDR(base) ((base) + (0x0204))
#define SOC_HiFD_PSCOEFS_VAL2_ADDR(base) ((base) + (0x0208))
#define SOC_HiFD_PSCOEFS_VAL3_ADDR(base) ((base) + (0x020c))
#define SOC_HiFD_PSCOEFS_VAL4_ADDR(base) ((base) + (0x0210))
#define SOC_HiFD_PSCOEFS_VAL5_ADDR(base) ((base) + (0x0214))
#define SOC_HiFD_PSCOEFS_VAL6_ADDR(base) ((base) + (0x0218))
#define SOC_HiFD_PSCOEFS_VAL7_ADDR(base) ((base) + (0x021c))
#define SOC_HiFD_PSCOEFS_VAL8_ADDR(base) ((base) + (0x0220))
#define SOC_HiFD_PSCOEFS_VAL9_ADDR(base) ((base) + (0x0224))
#define SOC_HiFD_PSCOEFS_VAL10_ADDR(base) ((base) + (0x0228))
#define SOC_HiFD_PSCOEFS_VAL11_ADDR(base) ((base) + (0x022c))
#define SOC_HiFD_PSCOEFS_VAL12_ADDR(base) ((base) + (0x0230))
#define SOC_HiFD_PSCOEFS_VAL13_ADDR(base) ((base) + (0x0234))
#define SOC_HiFD_PSCOEFS_VAL14_ADDR(base) ((base) + (0x0238))
#define SOC_HiFD_PSCOEFS_VAL15_ADDR(base) ((base) + (0x023c))
#define SOC_HiFD_PROP_CFG1_ADDR(base) ((base) + (0x0400))
#define SOC_HiFD_PROP_CFG2_ADDR(base) ((base) + (0x0404))
#define SOC_HiFD_PROP_CFG3_ADDR(base) ((base) + (0x0408))
#define SOC_HiFD_PROP_CFG4_ADDR(base) ((base) + (0x040c))
#define SOC_HiFD_PROP_CFG5_ADDR(base) ((base) + (0x0410))
#define SOC_HiFD_PROP_CFG6_ADDR(base) ((base) + (0x0414))
#define SOC_HiFD_PROP_CFG7_ADDR(base) ((base) + (0x0418))
#define SOC_HiFD_PROP_CFG8_ADDR(base) ((base) + (0x041C))
#define SOC_HiFD_PROP_CFG9_ADDR(base) ((base) + (0x0420))
#define SOC_HiFD_PROP_CFG10_ADDR(base) ((base) + (0x0424))
#define SOC_HiFD_PROP_CFG11_ADDR(base) ((base) + (0x0428))
#define SOC_HiFD_PROP_CFG12_ADDR(base) ((base) + (0x042C))
#define SOC_HiFD_PROP_CFG13_ADDR(base) ((base) + (0x0430))
#define SOC_HiFD_PROP_CFG14_ADDR(base) ((base) + (0x0434))
#define SOC_HiFD_PROP_CFG15_ADDR(base) ((base) + (0x0438))
#define SOC_HiFD_PROP_CFG16_ADDR(base) ((base) + (0x043C))
#define SOC_HiFD_PROP_CFG17_ADDR(base) ((base) + (0x0440))
#define SOC_HiFD_PROP_CFG18_ADDR(base) ((base) + (0x0444))
#define SOC_HiFD_PROP_CFG19_ADDR(base) ((base) + (0x0448))
#define SOC_HiFD_PROP_CFG20_ADDR(base) ((base) + (0x044C))
#define SOC_HiFD_PROP_CFG21_ADDR(base) ((base) + (0x0450))
#define SOC_HiFD_PROP_CFG22_ADDR(base) ((base) + (0x0454))
#define SOC_HiFD_PROP_CFG23_ADDR(base) ((base) + (0x0458))
#define SOC_HiFD_PROP_CFG24_ADDR(base) ((base) + (0x045C))
#define SOC_HiFD_PROP_CFG25_ADDR(base) ((base) + (0x0460))
#define SOC_HiFD_PROP_CFG26_ADDR(base) ((base) + (0x0464))
#define SOC_HiFD_PROP_CFG27_ADDR(base) ((base) + (0x0468))
#define SOC_HiFD_PROP_CFG28_ADDR(base) ((base) + (0x046C))
#define SOC_HiFD_PROP_CFG29_ADDR(base) ((base) + (0x0470))
#define SOC_HiFD_PROP_CFG30_ADDR(base) ((base) + (0x0474))
#define SOC_HiFD_PROP_CFG31_ADDR(base) ((base) + (0x0478))
#define SOC_HiFD_PROP_CFG32_ADDR(base) ((base) + (0x047C))
#define SOC_HiFD_PROP_CFG33_ADDR(base) ((base) + (0x0480))
#define SOC_HiFD_PROP_CFG34_ADDR(base) ((base) + (0x0484))
#define SOC_HiFD_PROP_CFG35_ADDR(base) ((base) + (0x0488))
#define SOC_HiFD_PROP_CFG36_ADDR(base) ((base) + (0x048C))
#define SOC_HiFD_PROP_CFG37_ADDR(base) ((base) + (0x0490))
#define SOC_HiFD_PROP_CFG38_ADDR(base) ((base) + (0x0494))
#define SOC_HiFD_PROP_CFG39_ADDR(base) ((base) + (0x0498))
#define SOC_HiFD_PROP_CFG40_ADDR(base) ((base) + (0x049C))
#define SOC_HiFD_PROP_CFG41_ADDR(base) ((base) + (0x04A0))
#define SOC_HiFD_PROP_CFG42_ADDR(base) ((base) + (0x04A4))
#define SOC_HiFD_PROP_CFG43_ADDR(base) ((base) + (0x04A8))
#define SOC_HiFD_PROP_CFG44_ADDR(base) ((base) + (0x04AC))
#define SOC_HiFD_PROP_CFG45_ADDR(base) ((base) + (0x04B0))
#define SOC_HiFD_PROP_CFG46_ADDR(base) ((base) + (0x04B4))
#define SOC_HiFD_PROP_CFG47_ADDR(base) ((base) + (0x04B8))
#define SOC_HiFD_PROP_CFG48_ADDR(base) ((base) + (0x04BC))
#define SOC_HiFD_PROP_CFG49_ADDR(base) ((base) + (0x04C0))
#define SOC_HiFD_PROP_CFG50_ADDR(base) ((base) + (0x04C4))
#define SOC_HiFD_PROP_CFG51_ADDR(base) ((base) + (0x04C8))
#define SOC_HiFD_PROP_CFG52_ADDR(base) ((base) + (0x04CC))
#define SOC_HiFD_PROP_CFG53_ADDR(base) ((base) + (0x04D0))
#define SOC_HiFD_PROP_CFG54_ADDR(base) ((base) + (0x04D4))
#define SOC_HiFD_PROP_CFG55_ADDR(base) ((base) + (0x04D8))
#define SOC_HiFD_PROP_CFG56_ADDR(base) ((base) + (0x04DC))
#define SOC_HiFD_PROP_CFG57_ADDR(base) ((base) + (0x04E0))
#define SOC_HiFD_PROP_CFG58_ADDR(base) ((base) + (0x04E4))
#define SOC_HiFD_PROP_CFG59_ADDR(base) ((base) + (0x04E8))
#define SOC_HiFD_PROP_CFG60_ADDR(base) ((base) + (0x04EC))
#define SOC_HiFD_PROP_CFG61_ADDR(base) ((base) + (0x04F0))
#define SOC_HiFD_PROP_CFG62_ADDR(base) ((base) + (0x04F4))
#define SOC_HiFD_PROP_CFG63_ADDR(base) ((base) + (0x04F8))
#define SOC_HiFD_PROP_CFG64_ADDR(base) ((base) + (0x04FC))
#define SOC_HiFD_MODULE_CLK_SEL_ADDR(base) ((base) + (0x0500))
#define SOC_HiFD_MODULE_CLK_EN_ADDR(base) ((base) + (0x0504))
#define SOC_HiFD_CH_CLK_SEL_ADDR(base) ((base) + (0x0508))
#define SOC_HiFD_CH_CLK_EN_ADDR(base) ((base) + (0x050C))
#define SOC_HiFD_PRE_SAMP_Y_OFFSET_ADDR(base) ((base) + (0x0800))
#define SOC_HiFD_PRE_SAMP_WIDTH_ADDR(base) ((base) + (0x0804))
#define SOC_HiFD_PRE_MODE_ADDR(base) ((base) + (0x0808))
#define SOC_HiFD_PRE_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0820))
#define SOC_HiFD_PRE_DFC_MODE_ADDR(base) ((base) + (0x0824))
#define SOC_HiFD_PRE_DFC_CLIP_CTL_VRT_ADDR(base) ((base) + (0x0828))
#define SOC_HiFD_PRE_CSC_IDC0_ADDR(base) ((base) + (0x0840))
#define SOC_HiFD_PRE_CSC_IDC2_ADDR(base) ((base) + (0x0844))
#define SOC_HiFD_PRE_CSC_ODC0_ADDR(base) ((base) + (0x0848))
#define SOC_HiFD_PRE_CSC_ODC2_ADDR(base) ((base) + (0x084C))
#define SOC_HiFD_PRE_CSC_P0_ADDR(base) ((base) + (0x0850))
#define SOC_HiFD_PRE_CSC_P1_ADDR(base) ((base) + (0x0854))
#define SOC_HiFD_PRE_CSC_P2_ADDR(base) ((base) + (0x0858))
#define SOC_HiFD_PRE_CSC_P3_ADDR(base) ((base) + (0x085C))
#define SOC_HiFD_PRE_CSC_P4_ADDR(base) ((base) + (0x0860))
#define SOC_HiFD_PRE_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0864))
#define SOC_HiFD_PRE_CSC_MPREC_ADDR(base) ((base) + (0x0868))
#define SOC_HiFD_PRE_SCF_INPUT_WIDTH_ADDR(base) ((base) + (0x0880))
#define SOC_HiFD_PRE_SCF_OUTPUT_WIDTH_ADDR(base) ((base) + (0x0884))
#define SOC_HiFD_PRE_SCF_EN_HSCL_STR_ADDR(base) ((base) + (0x0888))
#define SOC_HiFD_PRE_SCF_EN_VSCL_STR_ADDR(base) ((base) + (0x088C))
#define SOC_HiFD_PRE_SCF_H_V_ORDER_ADDR(base) ((base) + (0x0890))
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_ADDR(base) ((base) + (0x0894))
#define SOC_HiFD_PRE_SCF_EN_HSCL_ADDR(base) ((base) + (0x0898))
#define SOC_HiFD_PRE_SCF_EN_VSCL_ADDR(base) ((base) + (0x089C))
#define SOC_HiFD_PRE_SCF_INC_HSCL_ADDR(base) ((base) + (0x08A0))
#define SOC_HiFD_PRE_SCF_INC_VSCL_ADDR(base) ((base) + (0x08A4))
#define SOC_HiFD_PRE_POST_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x08C0))
#define SOC_HiFD_PRE_REA_WIDTH_ADDR(base) ((base) + (0x08E0))
#define SOC_HiFD_PRE_REA_PAD_HRZ_ADDR(base) ((base) + (0x08E4))
#define SOC_HiFD_PRE_REA_PAD_SHIFT_ADDR(base) ((base) + (0x08E8))
#define SOC_HiFD_RDMA_RAW_EN_ADDR(base) ((base) + (0x0900))
#define SOC_HiFD_RDMA_BLOCK_ROT_EN_ADDR(base) ((base) + (0x0904))
#define SOC_HiFD_RDMA_OUTSTANGING_ADDR(base) ((base) + (0x0940))
#define SOC_HiFD_RDMA_ARCACHE_ADDR(base) ((base) + (0x0944))
#define SOC_HiFD_RDMA_ARPROT_ADDR(base) ((base) + (0x0948))
#define SOC_HiFD_RDMA_ARQOS_ADDR(base) ((base) + (0x094C))
#define SOC_HiFD_RDMA_RESERVE0_ADDR(base) ((base) + (0x0980))
#define SOC_HiFD_RDMA_RESERVE1_ADDR(base) ((base) + (0x0984))
#define SOC_HiFD_RDMA_RESERVE2_ADDR(base) ((base) + (0x0988))
#define SOC_HiFD_RDMA_RESERVE3_ADDR(base) ((base) + (0x098C))
#define SOC_HiFD_DMA_AXUSER0_ADDR(base) ((base) + (0x0990))
#define SOC_HiFD_DMA_AXCH1_ADDR(base) ((base) + (0x0994))
#define SOC_HiFD_DMA_AXCH2_ADDR(base) ((base) + (0x0998))
#define SOC_HiFD_DMA_AXCH3_ADDR(base) ((base) + (0x099c))
#define SOC_HiFD_DMA_AXCH4_ADDR(base) ((base) + (0x09a0))
#define SOC_HiFD_DMA_AXCH5_ADDR(base) ((base) + (0x09a4))
#define SOC_HiFD_DMA_AXCH6_ADDR(base) ((base) + (0x09a8))
#define SOC_HiFD_DMA_AXCH7_ADDR(base) ((base) + (0x09ac))
#define SOC_HiFD_DMA_AXCH8_ADDR(base) ((base) + (0x09b0))
#define SOC_HiFD_DMA_AXCH9_ADDR(base) ((base) + (0x09b4))
#define SOC_HiFD_RDMA_RESERVE4_ADDR(base) ((base) + (0x09b8))
#define SOC_HiFD_RDMA_RESERVE5_ADDR(base) ((base) + (0x09bc))
#define SOC_HiFD_RDMA_RESERVE6_ADDR(base) ((base) + (0x09c0))
#define SOC_HiFD_RDMA_RESERVE7_ADDR(base) ((base) + (0x09c4))
#define SOC_HiFD_RDMA_RESERVE8_ADDR(base) ((base) + (0x09c8))
#define SOC_HiFD_RDMA_RESERVE9_ADDR(base) ((base) + (0x09cc))
#define SOC_HiFD_RDMA_RESERVE10_ADDR(base) ((base) + (0x09d0))
#define SOC_HiFD_RDMA_RESERVE11_ADDR(base) ((base) + (0x09d4))
#define SOC_HiFD_WDMA_OUTSTANDING_ADDR(base) ((base) + (0x0a00))
#define SOC_HiFD_WDMA_RAW_EN_ADDR(base) ((base) + (0x0a04))
#define SOC_HiFD_WDMA_BLOCK_ROT_EN_ADDR(base) ((base) + (0x0a08))
#define SOC_HiFD_WDMA_HFBCE_AUTO_CLK_GT_EN_ADDR(base) ((base) + (0x0a0c))
#define SOC_HiFD_WDMA_THRESHOLD_ADDR(base) ((base) + (0x0a10))
#define SOC_HiFD_WDMA_DEBUG0_ADDR(base) ((base) + (0x0a14))
#define SOC_HiFD_WDMA_DEBUG1_ADDR(base) ((base) + (0x0a18))
#define SOC_HiFD_WDMA_MONITOR0_ADDR(base) ((base) + (0x0a1c))
#define SOC_HiFD_WDMA_MONITOR1_ADDR(base) ((base) + (0x0a20))
#define SOC_HiFD_WDMA_MONITOR2_ADDR(base) ((base) + (0x0a24))
#define SOC_HiFD_WDMA_MONITOR3_ADDR(base) ((base) + (0x0a28))
#define SOC_HiFD_WDMA_AWCACHE_ADDR(base) ((base) + (0x0a2c))
#define SOC_HiFD_WDMA_AWPROT_ADDR(base) ((base) + (0x0a30))
#define SOC_HiFD_WDMA_AWQOS_ADDR(base) ((base) + (0x0a34))
#define SOC_HiFD_BASE_ADDR1_ADDR(base) ((base) + (0x0a40))
#define SOC_HiFD_BASE_ADDR2_ADDR(base) ((base) + (0x0a44))
#define SOC_HiFD_BASE_ADDR3_ADDR(base) ((base) + (0x0a48))
#define SOC_HiFD_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0a4c))
#define SOC_HiFD_BLOCK_ALIGN_EN_ADDR(base) ((base) + (0x0a50))
#define SOC_HiFD_BASE_ADDR1_hi_ADDR(base) ((base) + (0x0a54))
#define SOC_HiFD_BASE_ADDR2_hi_ADDR(base) ((base) + (0x0a58))
#define SOC_HiFD_BASE_ADDR3_hi_ADDR(base) ((base) + (0x0a5C))
#define SOC_HiFD_X2X_ENABLE_DATA_PACKING_N_ADDR(base) ((base) + (0x0b00))
#define SOC_HiFD_OUT_OF_BOUNDARY_REPORT_EN_ADDR(base) ((base) + (0x0c00))
#define SOC_HiFD_OUT_OF_BOUNDARY_STATUS_ADDR(base) ((base) + (0x0c04))
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_ADDR(base) ((base) + (0x0c08))
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_SEL_ADDR(base) ((base) + (0x0c0c))
#define SOC_HiFD_DEBUG_MODE_ADDR(base) ((base) + (0x0c10))
#define SOC_HiFD_DEBUG_STEP_LEN_ADDR(base) ((base) + (0x0c14))
#define SOC_HiFD_DEBUG_BREAKPOINT_ADDR(base) ((base) + (0x0c18))
#define SOC_HiFD_DEBUG_RUN_ADDR(base) ((base) + (0x0c1c))
#define SOC_HiFD_DEBUG_SPM_RD_ADDR(base) ((base) + (0x0c20))
#define SOC_HiFD_DEBUG_SPM_ADDR_ADDR(base) ((base) + (0x0c24))
#define SOC_HiFD_DEBUG_SPM_RDATA0_ADDR(base) ((base) + (0x0c28))
#define SOC_HiFD_DEBUG_SPM_RDATA1_ADDR(base) ((base) + (0x0c2c))
#define SOC_HiFD_DEBUG_SPM_RDATA2_ADDR(base) ((base) + (0x0c30))
#define SOC_HiFD_DEBUG_SPM_RDATA3_ADDR(base) ((base) + (0x0c34))
#define SOC_HiFD_PROP_CFG65_ADDR(base) ((base) + (0x0d00))
#define SOC_HiFD_PROP_CFG66_ADDR(base) ((base) + (0x0d04))
#define SOC_HiFD_PROP_CFG67_ADDR(base) ((base) + (0x0d08))
#define SOC_HiFD_PROP_CFG68_ADDR(base) ((base) + (0x0d0c))
#define SOC_HiFD_PROP_CFG69_ADDR(base) ((base) + (0x0d10))
#define SOC_HiFD_PROP_CFG70_ADDR(base) ((base) + (0x0d14))
#define SOC_HiFD_PROP_CFG71_ADDR(base) ((base) + (0x0d1c))
#define SOC_HiFD_PROP_CFG72_ADDR(base) ((base) + (0x0d20))
#define SOC_HiFD_PROP_CFG73_ADDR(base) ((base) + (0x0d24))
#define SOC_HiFD_PROP_CFG74_ADDR(base) ((base) + (0x0d28))
#define SOC_HiFD_PROP_CFG75_ADDR(base) ((base) + (0x0d2c))
#define SOC_HiFD_PROP_CFG76_ADDR(base) ((base) + (0x0d30))
#define SOC_HiFD_PROP_CFG77_ADDR(base) ((base) + (0x0d34))
#define SOC_HiFD_INST_MEM_ADDR(base) ((base) + (0x1000~0x6fff))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int version : 32;
    } reg;
} SOC_HiFD_VERSION_UNION;
#endif
#define SOC_HiFD_VERSION_version_START (0)
#define SOC_HiFD_VERSION_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_deep_slp_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_MEM_DEEP_SLP_OFF_UNION;
#endif
#define SOC_HiFD_MEM_DEEP_SLP_OFF_mem_deep_slp_off_START (0)
#define SOC_HiFD_MEM_DEEP_SLP_OFF_mem_deep_slp_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start : 1;
        unsigned int end_finish : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_START_UNION;
#endif
#define SOC_HiFD_START_start_START (0)
#define SOC_HiFD_START_start_END (0)
#define SOC_HiFD_START_end_finish_START (1)
#define SOC_HiFD_START_end_finish_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifd_clk_sel : 32;
    } reg;
} SOC_HiFD_HIFD_CLK_SEL_UNION;
#endif
#define SOC_HiFD_HIFD_CLK_SEL_hifd_clk_sel_START (0)
#define SOC_HiFD_HIFD_CLK_SEL_hifd_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifd_clk_en : 32;
    } reg;
} SOC_HiFD_HIFD_CLK_EN_UNION;
#endif
#define SOC_HiFD_HIFD_CLK_EN_hifd_clk_en_START (0)
#define SOC_HiFD_HIFD_CLK_EN_hifd_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int auto_clr_en : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_AUTO_CLR_EN_UNION;
#endif
#define SOC_HiFD_AUTO_CLR_EN_auto_clr_en_START (0)
#define SOC_HiFD_AUTO_CLR_EN_auto_clr_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int finish_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_STATUS_UNION;
#endif
#define SOC_HiFD_STATUS_finish_status_START (0)
#define SOC_HiFD_STATUS_finish_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr : 32;
    } reg;
} SOC_HiFD_BASE_ADDR_UNION;
#endif
#define SOC_HiFD_BASE_ADDR_base_addr_START (0)
#define SOC_HiFD_BASE_ADDR_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr0_hi : 32;
    } reg;
} SOC_HiFD_BASE_ADDR0_HI_UNION;
#endif
#define SOC_HiFD_BASE_ADDR0_HI_base_addr0_hi_START (0)
#define SOC_HiFD_BASE_ADDR0_HI_base_addr0_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_s : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_MEM_CTRL_UNION;
#endif
#define SOC_HiFD_MEM_CTRL_mem_ctrl_s_START (0)
#define SOC_HiFD_MEM_CTRL_mem_ctrl_s_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_pm_ctrl : 32;
    } reg;
} SOC_HiFD_CFG_PM_CTRL_UNION;
#endif
#define SOC_HiFD_CFG_PM_CTRL_cfg_pm_ctrl_START (0)
#define SOC_HiFD_CFG_PM_CTRL_cfg_pm_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int mem_dslp_en : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_HiFD_FDAI_INSTR_MEM_DSLP_EN_UNION;
#endif
#define SOC_HiFD_FDAI_INSTR_MEM_DSLP_EN_mem_dslp_en_START (1)
#define SOC_HiFD_FDAI_INSTR_MEM_DSLP_EN_mem_dslp_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdai_ints : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HiFD_FDAI_INTS_UNION;
#endif
#define SOC_HiFD_FDAI_INTS_fdai_ints_START (0)
#define SOC_HiFD_FDAI_INTS_fdai_ints_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdai_int_msk : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HiFD_FDAI_INT_MSK_UNION;
#endif
#define SOC_HiFD_FDAI_INT_MSK_fdai_int_msk_START (0)
#define SOC_HiFD_FDAI_INT_MSK_fdai_int_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_clear_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_CLEAR_EN_UNION;
#endif
#define SOC_HiFD_CLEAR_EN_cfg_clear_en_START (0)
#define SOC_HiFD_CLEAR_EN_cfg_clear_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_clear_holdtime : 32;
    } reg;
} SOC_HiFD_CLEAR_HOLD_TIME_UNION;
#endif
#define SOC_HiFD_CLEAR_HOLD_TIME_cfg_clear_holdtime_START (0)
#define SOC_HiFD_CLEAR_HOLD_TIME_cfg_clear_holdtime_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clear_state : 1;
        unsigned int submodule_clear_ack : 2;
        unsigned int reserved : 29;
    } reg;
} SOC_HiFD_CLEAR_STATE_UNION;
#endif
#define SOC_HiFD_CLEAR_STATE_clear_state_START (0)
#define SOC_HiFD_CLEAR_STATE_clear_state_END (0)
#define SOC_HiFD_CLEAR_STATE_submodule_clear_ack_START (1)
#define SOC_HiFD_CLEAR_STATE_submodule_clear_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clear_debug_in : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_CLEAR_DEBUG_IN_UNION;
#endif
#define SOC_HiFD_CLEAR_DEBUG_IN_clear_debug_in_START (0)
#define SOC_HiFD_CLEAR_DEBUG_IN_clear_debug_in_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_out : 32;
    } reg;
} SOC_HiFD_CLEAR_DEBUG_OUT_UNION;
#endif
#define SOC_HiFD_CLEAR_DEBUG_OUT_debug_out_START (0)
#define SOC_HiFD_CLEAR_DEBUG_OUT_debug_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spm_err_state : 32;
    } reg;
} SOC_HiFD_SPM_ERR_STATE_UNION;
#endif
#define SOC_HiFD_SPM_ERR_STATE_spm_err_state_START (0)
#define SOC_HiFD_SPM_ERR_STATE_spm_err_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipu_armpress : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_IPU_ARMPRESS_UNION;
#endif
#define SOC_HiFD_IPU_ARMPRESS_ipu_armpress_START (0)
#define SOC_HiFD_IPU_ARMPRESS_ipu_armpress_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdai_reserve1 : 32;
    } reg;
} SOC_HiFD_FDAI_RESERVE1_UNION;
#endif
#define SOC_HiFD_FDAI_RESERVE1_fdai_reserve1_START (0)
#define SOC_HiFD_FDAI_RESERVE1_fdai_reserve1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipu_awmpress : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_IPU_AWMPRESS_UNION;
#endif
#define SOC_HiFD_IPU_AWMPRESS_ipu_awmpress_START (0)
#define SOC_HiFD_IPU_AWMPRESS_ipu_awmpress_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdai_reserve3 : 32;
    } reg;
} SOC_HiFD_FDAI_RESERVE3_UNION;
#endif
#define SOC_HiFD_FDAI_RESERVE3_fdai_reserve3_START (0)
#define SOC_HiFD_FDAI_RESERVE3_fdai_reserve3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int recip_4 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_RECIP_4_UNION;
#endif
#define SOC_HiFD_RECIP_4_recip_4_START (0)
#define SOC_HiFD_RECIP_4_recip_4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int recip_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_RECIP_2_UNION;
#endif
#define SOC_HiFD_RECIP_2_recip_2_START (0)
#define SOC_HiFD_RECIP_2_recip_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int recip_9 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_RECIP_9_UNION;
#endif
#define SOC_HiFD_RECIP_9_recip_9_START (0)
#define SOC_HiFD_RECIP_9_recip_9_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int recip_6 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_RECIP_6_UNION;
#endif
#define SOC_HiFD_RECIP_6_recip_6_START (0)
#define SOC_HiFD_RECIP_6_recip_6_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int recip_3 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_RECIP_3_UNION;
#endif
#define SOC_HiFD_RECIP_3_recip_3_START (0)
#define SOC_HiFD_RECIP_3_recip_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int recip_49 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_RECIP_49_UNION;
#endif
#define SOC_HiFD_RECIP_49_recip_49_START (0)
#define SOC_HiFD_RECIP_49_recip_49_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_imem_load_addr : 32;
    } reg;
} SOC_HiFD_CAU_IMEM_LOAD_ADDR_UNION;
#endif
#define SOC_HiFD_CAU_IMEM_LOAD_ADDR_cau_imem_load_addr_START (0)
#define SOC_HiFD_CAU_IMEM_LOAD_ADDR_cau_imem_load_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_rf_addr : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HiFD_CAU_RF_ADDR_UNION;
#endif
#define SOC_HiFD_CAU_RF_ADDR_cau_rf_addr_START (0)
#define SOC_HiFD_CAU_RF_ADDR_cau_rf_addr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_rf_data : 32;
    } reg;
} SOC_HiFD_CAU_RF_DATA_UNION;
#endif
#define SOC_HiFD_CAU_RF_DATA_cau_rf_data_START (0)
#define SOC_HiFD_CAU_RF_DATA_cau_rf_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_id_pc : 32;
    } reg;
} SOC_HiFD_CAU_ID_PC_UNION;
#endif
#define SOC_HiFD_CAU_ID_PC_cau_id_pc_START (0)
#define SOC_HiFD_CAU_ID_PC_cau_id_pc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_id_instr_high : 32;
    } reg;
} SOC_HiFD_CAU_ID_INSTR_H_UNION;
#endif
#define SOC_HiFD_CAU_ID_INSTR_H_cau_id_instr_high_START (0)
#define SOC_HiFD_CAU_ID_INSTR_H_cau_id_instr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_id_instr_low : 32;
    } reg;
} SOC_HiFD_CAU_ID_INSTR_L_UNION;
#endif
#define SOC_HiFD_CAU_ID_INSTR_L_cau_id_instr_low_START (0)
#define SOC_HiFD_CAU_ID_INSTR_L_cau_id_instr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_status : 32;
    } reg;
} SOC_HiFD_CAU_STATUS_UNION;
#endif
#define SOC_HiFD_CAU_STATUS_cau_status_START (0)
#define SOC_HiFD_CAU_STATUS_cau_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_debug_instr_num : 32;
    } reg;
} SOC_HiFD_CAU_DEBUG_INSTR_NUM_UNION;
#endif
#define SOC_HiFD_CAU_DEBUG_INSTR_NUM_cau_debug_instr_num_START (0)
#define SOC_HiFD_CAU_DEBUG_INSTR_NUM_cau_debug_instr_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_maxpl_pad : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HiFD_CAU_MAXPL_PAD_UNION;
#endif
#define SOC_HiFD_CAU_MAXPL_PAD_cau_maxpl_pad_START (0)
#define SOC_HiFD_CAU_MAXPL_PAD_cau_maxpl_pad_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_rsv9 : 32;
    } reg;
} SOC_HiFD_CAU_RESERVE9_UNION;
#endif
#define SOC_HiFD_CAU_RESERVE9_cau_rsv9_START (0)
#define SOC_HiFD_CAU_RESERVE9_cau_rsv9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_vpu0 : 32;
    } reg;
} SOC_HiFD_CAU_STATUS1_UNION;
#endif
#define SOC_HiFD_CAU_STATUS1_cau_vpu0_START (0)
#define SOC_HiFD_CAU_STATUS1_cau_vpu0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_vpu1 : 32;
    } reg;
} SOC_HiFD_CAU_STATUS2_UNION;
#endif
#define SOC_HiFD_CAU_STATUS2_cau_vpu1_START (0)
#define SOC_HiFD_CAU_STATUS2_cau_vpu1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cau_memq : 32;
    } reg;
} SOC_HiFD_CAU_STATUS3_UNION;
#endif
#define SOC_HiFD_CAU_STATUS3_cau_memq_START (0)
#define SOC_HiFD_CAU_STATUS3_cau_memq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mq_rdma_order_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_MQ_RDMA_ORD_EN_UNION;
#endif
#define SOC_HiFD_MQ_RDMA_ORD_EN_mq_rdma_order_en_START (0)
#define SOC_HiFD_MQ_RDMA_ORD_EN_mq_rdma_order_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv0 : 32;
    } reg;
} SOC_HiFD_VPU_RSV0_UNION;
#endif
#define SOC_HiFD_VPU_RSV0_vpu_rsv0_START (0)
#define SOC_HiFD_VPU_RSV0_vpu_rsv0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv1 : 32;
    } reg;
} SOC_HiFD_VPU_RSV1_UNION;
#endif
#define SOC_HiFD_VPU_RSV1_vpu_rsv1_START (0)
#define SOC_HiFD_VPU_RSV1_vpu_rsv1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv2 : 32;
    } reg;
} SOC_HiFD_VPU_RSV2_UNION;
#endif
#define SOC_HiFD_VPU_RSV2_vpu_rsv2_START (0)
#define SOC_HiFD_VPU_RSV2_vpu_rsv2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv3 : 32;
    } reg;
} SOC_HiFD_VPU_RSV3_UNION;
#endif
#define SOC_HiFD_VPU_RSV3_vpu_rsv3_START (0)
#define SOC_HiFD_VPU_RSV3_vpu_rsv3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv4 : 32;
    } reg;
} SOC_HiFD_VPU_RSV4_UNION;
#endif
#define SOC_HiFD_VPU_RSV4_vpu_rsv4_START (0)
#define SOC_HiFD_VPU_RSV4_vpu_rsv4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv5 : 32;
    } reg;
} SOC_HiFD_VPU_RSV5_UNION;
#endif
#define SOC_HiFD_VPU_RSV5_vpu_rsv5_START (0)
#define SOC_HiFD_VPU_RSV5_vpu_rsv5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv6 : 32;
    } reg;
} SOC_HiFD_VPU_RSV6_UNION;
#endif
#define SOC_HiFD_VPU_RSV6_vpu_rsv6_START (0)
#define SOC_HiFD_VPU_RSV6_vpu_rsv6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpu_rsv7 : 32;
    } reg;
} SOC_HiFD_VPU_RSV7_UNION;
#endif
#define SOC_HiFD_VPU_RSV7_vpu_rsv7_START (0)
#define SOC_HiFD_VPU_RSV7_vpu_rsv7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_0 : 10;
        unsigned int pscoefs_1_0 : 10;
        unsigned int pscoefs_0_0 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL0_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL0_pscoefs_2_0_START (0)
#define SOC_HiFD_PSCOEFS_VAL0_pscoefs_2_0_END (9)
#define SOC_HiFD_PSCOEFS_VAL0_pscoefs_1_0_START (10)
#define SOC_HiFD_PSCOEFS_VAL0_pscoefs_1_0_END (19)
#define SOC_HiFD_PSCOEFS_VAL0_pscoefs_0_0_START (20)
#define SOC_HiFD_PSCOEFS_VAL0_pscoefs_0_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_1 : 10;
        unsigned int pscoefs_1_1 : 10;
        unsigned int pscoefs_0_1 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL1_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL1_pscoefs_2_1_START (0)
#define SOC_HiFD_PSCOEFS_VAL1_pscoefs_2_1_END (9)
#define SOC_HiFD_PSCOEFS_VAL1_pscoefs_1_1_START (10)
#define SOC_HiFD_PSCOEFS_VAL1_pscoefs_1_1_END (19)
#define SOC_HiFD_PSCOEFS_VAL1_pscoefs_0_1_START (20)
#define SOC_HiFD_PSCOEFS_VAL1_pscoefs_0_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_2 : 10;
        unsigned int pscoefs_1_2 : 10;
        unsigned int pscoefs_0_2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL2_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL2_pscoefs_2_2_START (0)
#define SOC_HiFD_PSCOEFS_VAL2_pscoefs_2_2_END (9)
#define SOC_HiFD_PSCOEFS_VAL2_pscoefs_1_2_START (10)
#define SOC_HiFD_PSCOEFS_VAL2_pscoefs_1_2_END (19)
#define SOC_HiFD_PSCOEFS_VAL2_pscoefs_0_2_START (20)
#define SOC_HiFD_PSCOEFS_VAL2_pscoefs_0_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_3 : 10;
        unsigned int pscoefs_1_3 : 10;
        unsigned int pscoefs_0_3 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL3_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL3_pscoefs_2_3_START (0)
#define SOC_HiFD_PSCOEFS_VAL3_pscoefs_2_3_END (9)
#define SOC_HiFD_PSCOEFS_VAL3_pscoefs_1_3_START (10)
#define SOC_HiFD_PSCOEFS_VAL3_pscoefs_1_3_END (19)
#define SOC_HiFD_PSCOEFS_VAL3_pscoefs_0_3_START (20)
#define SOC_HiFD_PSCOEFS_VAL3_pscoefs_0_3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_4 : 10;
        unsigned int pscoefs_1_4 : 10;
        unsigned int pscoefs_0_4 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL4_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL4_pscoefs_2_4_START (0)
#define SOC_HiFD_PSCOEFS_VAL4_pscoefs_2_4_END (9)
#define SOC_HiFD_PSCOEFS_VAL4_pscoefs_1_4_START (10)
#define SOC_HiFD_PSCOEFS_VAL4_pscoefs_1_4_END (19)
#define SOC_HiFD_PSCOEFS_VAL4_pscoefs_0_4_START (20)
#define SOC_HiFD_PSCOEFS_VAL4_pscoefs_0_4_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_5 : 10;
        unsigned int pscoefs_1_5 : 10;
        unsigned int pscoefs_0_5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL5_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL5_pscoefs_2_5_START (0)
#define SOC_HiFD_PSCOEFS_VAL5_pscoefs_2_5_END (9)
#define SOC_HiFD_PSCOEFS_VAL5_pscoefs_1_5_START (10)
#define SOC_HiFD_PSCOEFS_VAL5_pscoefs_1_5_END (19)
#define SOC_HiFD_PSCOEFS_VAL5_pscoefs_0_5_START (20)
#define SOC_HiFD_PSCOEFS_VAL5_pscoefs_0_5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_6 : 10;
        unsigned int pscoefs_1_6 : 10;
        unsigned int pscoefs_0_6 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL6_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL6_pscoefs_2_6_START (0)
#define SOC_HiFD_PSCOEFS_VAL6_pscoefs_2_6_END (9)
#define SOC_HiFD_PSCOEFS_VAL6_pscoefs_1_6_START (10)
#define SOC_HiFD_PSCOEFS_VAL6_pscoefs_1_6_END (19)
#define SOC_HiFD_PSCOEFS_VAL6_pscoefs_0_6_START (20)
#define SOC_HiFD_PSCOEFS_VAL6_pscoefs_0_6_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_7 : 10;
        unsigned int pscoefs_1_7 : 10;
        unsigned int pscoefs_0_7 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL7_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL7_pscoefs_2_7_START (0)
#define SOC_HiFD_PSCOEFS_VAL7_pscoefs_2_7_END (9)
#define SOC_HiFD_PSCOEFS_VAL7_pscoefs_1_7_START (10)
#define SOC_HiFD_PSCOEFS_VAL7_pscoefs_1_7_END (19)
#define SOC_HiFD_PSCOEFS_VAL7_pscoefs_0_7_START (20)
#define SOC_HiFD_PSCOEFS_VAL7_pscoefs_0_7_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_8 : 10;
        unsigned int pscoefs_1_8 : 10;
        unsigned int pscoefs_0_8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL8_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL8_pscoefs_2_8_START (0)
#define SOC_HiFD_PSCOEFS_VAL8_pscoefs_2_8_END (9)
#define SOC_HiFD_PSCOEFS_VAL8_pscoefs_1_8_START (10)
#define SOC_HiFD_PSCOEFS_VAL8_pscoefs_1_8_END (19)
#define SOC_HiFD_PSCOEFS_VAL8_pscoefs_0_8_START (20)
#define SOC_HiFD_PSCOEFS_VAL8_pscoefs_0_8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_9 : 10;
        unsigned int pscoefs_1_9 : 10;
        unsigned int pscoefs_0_9 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL9_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL9_pscoefs_2_9_START (0)
#define SOC_HiFD_PSCOEFS_VAL9_pscoefs_2_9_END (9)
#define SOC_HiFD_PSCOEFS_VAL9_pscoefs_1_9_START (10)
#define SOC_HiFD_PSCOEFS_VAL9_pscoefs_1_9_END (19)
#define SOC_HiFD_PSCOEFS_VAL9_pscoefs_0_9_START (20)
#define SOC_HiFD_PSCOEFS_VAL9_pscoefs_0_9_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_10 : 10;
        unsigned int pscoefs_1_10 : 10;
        unsigned int pscoefs_0_10 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL10_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL10_pscoefs_2_10_START (0)
#define SOC_HiFD_PSCOEFS_VAL10_pscoefs_2_10_END (9)
#define SOC_HiFD_PSCOEFS_VAL10_pscoefs_1_10_START (10)
#define SOC_HiFD_PSCOEFS_VAL10_pscoefs_1_10_END (19)
#define SOC_HiFD_PSCOEFS_VAL10_pscoefs_0_10_START (20)
#define SOC_HiFD_PSCOEFS_VAL10_pscoefs_0_10_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_11 : 10;
        unsigned int pscoefs_1_11 : 10;
        unsigned int pscoefs_0_11 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL11_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL11_pscoefs_2_11_START (0)
#define SOC_HiFD_PSCOEFS_VAL11_pscoefs_2_11_END (9)
#define SOC_HiFD_PSCOEFS_VAL11_pscoefs_1_11_START (10)
#define SOC_HiFD_PSCOEFS_VAL11_pscoefs_1_11_END (19)
#define SOC_HiFD_PSCOEFS_VAL11_pscoefs_0_11_START (20)
#define SOC_HiFD_PSCOEFS_VAL11_pscoefs_0_11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_12 : 10;
        unsigned int pscoefs_1_12 : 10;
        unsigned int pscoefs_0_12 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL12_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL12_pscoefs_2_12_START (0)
#define SOC_HiFD_PSCOEFS_VAL12_pscoefs_2_12_END (9)
#define SOC_HiFD_PSCOEFS_VAL12_pscoefs_1_12_START (10)
#define SOC_HiFD_PSCOEFS_VAL12_pscoefs_1_12_END (19)
#define SOC_HiFD_PSCOEFS_VAL12_pscoefs_0_12_START (20)
#define SOC_HiFD_PSCOEFS_VAL12_pscoefs_0_12_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_13 : 10;
        unsigned int pscoefs_1_13 : 10;
        unsigned int pscoefs_0_13 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL13_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL13_pscoefs_2_13_START (0)
#define SOC_HiFD_PSCOEFS_VAL13_pscoefs_2_13_END (9)
#define SOC_HiFD_PSCOEFS_VAL13_pscoefs_1_13_START (10)
#define SOC_HiFD_PSCOEFS_VAL13_pscoefs_1_13_END (19)
#define SOC_HiFD_PSCOEFS_VAL13_pscoefs_0_13_START (20)
#define SOC_HiFD_PSCOEFS_VAL13_pscoefs_0_13_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_14 : 10;
        unsigned int pscoefs_1_14 : 10;
        unsigned int pscoefs_0_14 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL14_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL14_pscoefs_2_14_START (0)
#define SOC_HiFD_PSCOEFS_VAL14_pscoefs_2_14_END (9)
#define SOC_HiFD_PSCOEFS_VAL14_pscoefs_1_14_START (10)
#define SOC_HiFD_PSCOEFS_VAL14_pscoefs_1_14_END (19)
#define SOC_HiFD_PSCOEFS_VAL14_pscoefs_0_14_START (20)
#define SOC_HiFD_PSCOEFS_VAL14_pscoefs_0_14_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pscoefs_2_15 : 10;
        unsigned int pscoefs_1_15 : 10;
        unsigned int pscoefs_0_15 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PSCOEFS_VAL15_UNION;
#endif
#define SOC_HiFD_PSCOEFS_VAL15_pscoefs_2_15_START (0)
#define SOC_HiFD_PSCOEFS_VAL15_pscoefs_2_15_END (9)
#define SOC_HiFD_PSCOEFS_VAL15_pscoefs_1_15_START (10)
#define SOC_HiFD_PSCOEFS_VAL15_pscoefs_1_15_END (19)
#define SOC_HiFD_PSCOEFS_VAL15_pscoefs_0_15_START (20)
#define SOC_HiFD_PSCOEFS_VAL15_pscoefs_0_15_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int feat_stride : 6;
        unsigned int reserved_0 : 2;
        unsigned int pre_topn : 10;
        unsigned int reserved_1 : 2;
        unsigned int post_topn : 10;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_HiFD_PROP_CFG1_UNION;
#endif
#define SOC_HiFD_PROP_CFG1_feat_stride_START (0)
#define SOC_HiFD_PROP_CFG1_feat_stride_END (5)
#define SOC_HiFD_PROP_CFG1_pre_topn_START (8)
#define SOC_HiFD_PROP_CFG1_pre_topn_END (17)
#define SOC_HiFD_PROP_CFG1_post_topn_START (20)
#define SOC_HiFD_PROP_CFG1_post_topn_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh : 10;
        unsigned int min_size_w : 10;
        unsigned int min_size_h : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PROP_CFG2_UNION;
#endif
#define SOC_HiFD_PROP_CFG2_nms_thresh_START (0)
#define SOC_HiFD_PROP_CFG2_nms_thresh_END (9)
#define SOC_HiFD_PROP_CFG2_min_size_w_START (10)
#define SOC_HiFD_PROP_CFG2_min_size_w_END (19)
#define SOC_HiFD_PROP_CFG2_min_size_h_START (20)
#define SOC_HiFD_PROP_CFG2_min_size_h_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int im_info_w : 12;
        unsigned int reserved_0: 4;
        unsigned int im_info_h : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_HiFD_PROP_CFG3_UNION;
#endif
#define SOC_HiFD_PROP_CFG3_im_info_w_START (0)
#define SOC_HiFD_PROP_CFG3_im_info_w_END (11)
#define SOC_HiFD_PROP_CFG3_im_info_h_START (16)
#define SOC_HiFD_PROP_CFG3_im_info_h_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int delta_copy_base_addr : 16;
        unsigned int score_num : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_HiFD_PROP_CFG4_UNION;
#endif
#define SOC_HiFD_PROP_CFG4_delta_copy_base_addr_START (0)
#define SOC_HiFD_PROP_CFG4_delta_copy_base_addr_END (15)
#define SOC_HiFD_PROP_CFG4_score_num_START (16)
#define SOC_HiFD_PROP_CFG4_score_num_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int delta_base_addr0 : 16;
        unsigned int delta_jump_addr0 : 16;
    } reg;
} SOC_HiFD_PROP_CFG5_UNION;
#endif
#define SOC_HiFD_PROP_CFG5_delta_base_addr0_START (0)
#define SOC_HiFD_PROP_CFG5_delta_base_addr0_END (15)
#define SOC_HiFD_PROP_CFG5_delta_jump_addr0_START (16)
#define SOC_HiFD_PROP_CFG5_delta_jump_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int score_base_addr0 : 16;
        unsigned int score_index_base_addr0 : 16;
    } reg;
} SOC_HiFD_PROP_CFG6_UNION;
#endif
#define SOC_HiFD_PROP_CFG6_score_base_addr0_START (0)
#define SOC_HiFD_PROP_CFG6_score_base_addr0_END (15)
#define SOC_HiFD_PROP_CFG6_score_index_base_addr0_START (16)
#define SOC_HiFD_PROP_CFG6_score_index_base_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int delta_base_addr_md1 : 16;
        unsigned int delta_copy_base_addr_md1 : 16;
    } reg;
} SOC_HiFD_PROP_CFG7_UNION;
#endif
#define SOC_HiFD_PROP_CFG7_delta_base_addr_md1_START (0)
#define SOC_HiFD_PROP_CFG7_delta_base_addr_md1_END (15)
#define SOC_HiFD_PROP_CFG7_delta_copy_base_addr_md1_START (16)
#define SOC_HiFD_PROP_CFG7_delta_copy_base_addr_md1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int score_base_addr_md1 : 16;
        unsigned int score_index_base_addr_md1 : 16;
    } reg;
} SOC_HiFD_PROP_CFG8_UNION;
#endif
#define SOC_HiFD_PROP_CFG8_score_base_addr_md1_START (0)
#define SOC_HiFD_PROP_CFG8_score_base_addr_md1_END (15)
#define SOC_HiFD_PROP_CFG8_score_index_base_addr_md1_START (16)
#define SOC_HiFD_PROP_CFG8_score_index_base_addr_md1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int delta_total_cnt0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_PROP_CFG9_UNION;
#endif
#define SOC_HiFD_PROP_CFG9_delta_total_cnt0_START (0)
#define SOC_HiFD_PROP_CFG9_delta_total_cnt0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_base_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_PROP_CFG10_UNION;
#endif
#define SOC_HiFD_PROP_CFG10_nms_base_addr_START (0)
#define SOC_HiFD_PROP_CFG10_nms_base_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_width : 8;
        unsigned int prop_height : 8;
        unsigned int anchor_type : 5;
        unsigned int reserved : 11;
    } reg;
} SOC_HiFD_PROP_CFG11_UNION;
#endif
#define SOC_HiFD_PROP_CFG11_prop_width_START (0)
#define SOC_HiFD_PROP_CFG11_prop_width_END (7)
#define SOC_HiFD_PROP_CFG11_prop_height_START (8)
#define SOC_HiFD_PROP_CFG11_prop_height_END (15)
#define SOC_HiFD_PROP_CFG11_anchor_type_START (16)
#define SOC_HiFD_PROP_CFG11_anchor_type_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int im_info_scale : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_HiFD_PROP_CFG12_UNION;
#endif
#define SOC_HiFD_PROP_CFG12_im_info_scale_START (0)
#define SOC_HiFD_PROP_CFG12_im_info_scale_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dx_scale : 14;
        unsigned int reserved_0: 2;
        unsigned int dx_shift : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_HiFD_PROP_CFG13_UNION;
#endif
#define SOC_HiFD_PROP_CFG13_dx_scale_START (0)
#define SOC_HiFD_PROP_CFG13_dx_scale_END (13)
#define SOC_HiFD_PROP_CFG13_dx_shift_START (16)
#define SOC_HiFD_PROP_CFG13_dx_shift_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_scale : 16;
        unsigned int dw_shift : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_HiFD_PROP_CFG14_UNION;
#endif
#define SOC_HiFD_PROP_CFG14_dw_scale_START (0)
#define SOC_HiFD_PROP_CFG14_dw_scale_END (15)
#define SOC_HiFD_PROP_CFG14_dw_shift_START (16)
#define SOC_HiFD_PROP_CFG14_dw_shift_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int src1_score_base_addr : 16;
        unsigned int src0_score_base_addr : 16;
    } reg;
} SOC_HiFD_PROP_CFG15_UNION;
#endif
#define SOC_HiFD_PROP_CFG15_src1_score_base_addr_START (0)
#define SOC_HiFD_PROP_CFG15_src1_score_base_addr_END (15)
#define SOC_HiFD_PROP_CFG15_src0_score_base_addr_START (16)
#define SOC_HiFD_PROP_CFG15_src0_score_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_score_base_addr_md1 : 16;
        unsigned int src_score_base_addr_md1 : 16;
    } reg;
} SOC_HiFD_PROP_CFG16_UNION;
#endif
#define SOC_HiFD_PROP_CFG16_nms_score_base_addr_md1_START (0)
#define SOC_HiFD_PROP_CFG16_nms_score_base_addr_md1_END (15)
#define SOC_HiFD_PROP_CFG16_src_score_base_addr_md1_START (16)
#define SOC_HiFD_PROP_CFG16_src_score_base_addr_md1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1 : 10;
        unsigned int min_size_w_md1 : 10;
        unsigned int min_size_h_md1 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_HiFD_PROP_CFG17_UNION;
#endif
#define SOC_HiFD_PROP_CFG17_nms_thresh_md1_START (0)
#define SOC_HiFD_PROP_CFG17_nms_thresh_md1_END (9)
#define SOC_HiFD_PROP_CFG17_min_size_w_md1_START (10)
#define SOC_HiFD_PROP_CFG17_min_size_w_md1_END (19)
#define SOC_HiFD_PROP_CFG17_min_size_h_md1_START (20)
#define SOC_HiFD_PROP_CFG17_min_size_h_md1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dx_scale_md1 : 14;
        unsigned int reserved_0 : 2;
        unsigned int dx_shift_md1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG18_UNION;
#endif
#define SOC_HiFD_PROP_CFG18_dx_scale_md1_START (0)
#define SOC_HiFD_PROP_CFG18_dx_scale_md1_END (13)
#define SOC_HiFD_PROP_CFG18_dx_shift_md1_START (16)
#define SOC_HiFD_PROP_CFG18_dx_shift_md1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_scale_md1 : 16;
        unsigned int dw_shift_md1 : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_HiFD_PROP_CFG19_UNION;
#endif
#define SOC_HiFD_PROP_CFG19_dw_scale_md1_START (0)
#define SOC_HiFD_PROP_CFG19_dw_scale_md1_END (15)
#define SOC_HiFD_PROP_CFG19_dw_shift_md1_START (16)
#define SOC_HiFD_PROP_CFG19_dw_shift_md1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s_scale_md1 : 12;
        unsigned int reserved_0 : 4;
        unsigned int s_shift_md1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG20_UNION;
#endif
#define SOC_HiFD_PROP_CFG20_s_scale_md1_START (0)
#define SOC_HiFD_PROP_CFG20_s_scale_md1_END (11)
#define SOC_HiFD_PROP_CFG20_s_shift_md1_START (16)
#define SOC_HiFD_PROP_CFG20_s_shift_md1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int im_info_w_md1 : 12;
        unsigned int reserved_0 : 4;
        unsigned int im_info_h_md1 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_HiFD_PROP_CFG21_UNION;
#endif
#define SOC_HiFD_PROP_CFG21_im_info_w_md1_START (0)
#define SOC_HiFD_PROP_CFG21_im_info_w_md1_END (11)
#define SOC_HiFD_PROP_CFG21_im_info_h_md1_START (16)
#define SOC_HiFD_PROP_CFG21_im_info_h_md1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int im_info_scale_md1 : 11;
        unsigned int reserved_0 : 5;
        unsigned int en_16b_md1 : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_HiFD_PROP_CFG22_UNION;
#endif
#define SOC_HiFD_PROP_CFG22_im_info_scale_md1_START (0)
#define SOC_HiFD_PROP_CFG22_im_info_scale_md1_END (10)
#define SOC_HiFD_PROP_CFG22_en_16b_md1_START (16)
#define SOC_HiFD_PROP_CFG22_en_16b_md1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv1 : 32;
    } reg;
} SOC_HiFD_PROP_CFG23_UNION;
#endif
#define SOC_HiFD_PROP_CFG23_prop_rsv1_START (0)
#define SOC_HiFD_PROP_CFG23_prop_rsv1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv2 : 32;
    } reg;
} SOC_HiFD_PROP_CFG24_UNION;
#endif
#define SOC_HiFD_PROP_CFG24_prop_rsv2_START (0)
#define SOC_HiFD_PROP_CFG24_prop_rsv2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv3 : 32;
    } reg;
} SOC_HiFD_PROP_CFG25_UNION;
#endif
#define SOC_HiFD_PROP_CFG25_prop_rsv3_START (0)
#define SOC_HiFD_PROP_CFG25_prop_rsv3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv4 : 32;
    } reg;
} SOC_HiFD_PROP_CFG26_UNION;
#endif
#define SOC_HiFD_PROP_CFG26_prop_rsv4_START (0)
#define SOC_HiFD_PROP_CFG26_prop_rsv4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv5 : 32;
    } reg;
} SOC_HiFD_PROP_CFG27_UNION;
#endif
#define SOC_HiFD_PROP_CFG27_prop_rsv5_START (0)
#define SOC_HiFD_PROP_CFG27_prop_rsv5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv6 : 32;
    } reg;
} SOC_HiFD_PROP_CFG28_UNION;
#endif
#define SOC_HiFD_PROP_CFG28_prop_rsv6_START (0)
#define SOC_HiFD_PROP_CFG28_prop_rsv6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv7 : 32;
    } reg;
} SOC_HiFD_PROP_CFG29_UNION;
#endif
#define SOC_HiFD_PROP_CFG29_prop_rsv7_START (0)
#define SOC_HiFD_PROP_CFG29_prop_rsv7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_rsv8 : 32;
    } reg;
} SOC_HiFD_PROP_CFG30_UNION;
#endif
#define SOC_HiFD_PROP_CFG30_prop_rsv8_START (0)
#define SOC_HiFD_PROP_CFG30_prop_rsv8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor00_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor00_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG31_UNION;
#endif
#define SOC_HiFD_PROP_CFG31_anchor00_base_x0_START (0)
#define SOC_HiFD_PROP_CFG31_anchor00_base_x0_END (9)
#define SOC_HiFD_PROP_CFG31_anchor00_base_y0_START (16)
#define SOC_HiFD_PROP_CFG31_anchor00_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor00_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor00_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG32_UNION;
#endif
#define SOC_HiFD_PROP_CFG32_anchor00_base_x1_START (0)
#define SOC_HiFD_PROP_CFG32_anchor00_base_x1_END (9)
#define SOC_HiFD_PROP_CFG32_anchor00_base_y1_START (16)
#define SOC_HiFD_PROP_CFG32_anchor00_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor01_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor01_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG33_UNION;
#endif
#define SOC_HiFD_PROP_CFG33_anchor01_base_x0_START (0)
#define SOC_HiFD_PROP_CFG33_anchor01_base_x0_END (9)
#define SOC_HiFD_PROP_CFG33_anchor01_base_y0_START (16)
#define SOC_HiFD_PROP_CFG33_anchor01_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor01_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor01_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG34_UNION;
#endif
#define SOC_HiFD_PROP_CFG34_anchor01_base_x1_START (0)
#define SOC_HiFD_PROP_CFG34_anchor01_base_x1_END (9)
#define SOC_HiFD_PROP_CFG34_anchor01_base_y1_START (16)
#define SOC_HiFD_PROP_CFG34_anchor01_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor02_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor02_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG35_UNION;
#endif
#define SOC_HiFD_PROP_CFG35_anchor02_base_x0_START (0)
#define SOC_HiFD_PROP_CFG35_anchor02_base_x0_END (9)
#define SOC_HiFD_PROP_CFG35_anchor02_base_y0_START (16)
#define SOC_HiFD_PROP_CFG35_anchor02_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor02_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor02_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG36_UNION;
#endif
#define SOC_HiFD_PROP_CFG36_anchor02_base_x1_START (0)
#define SOC_HiFD_PROP_CFG36_anchor02_base_x1_END (9)
#define SOC_HiFD_PROP_CFG36_anchor02_base_y1_START (16)
#define SOC_HiFD_PROP_CFG36_anchor02_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor03_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor03_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG37_UNION;
#endif
#define SOC_HiFD_PROP_CFG37_anchor03_base_x0_START (0)
#define SOC_HiFD_PROP_CFG37_anchor03_base_x0_END (9)
#define SOC_HiFD_PROP_CFG37_anchor03_base_y0_START (16)
#define SOC_HiFD_PROP_CFG37_anchor03_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor03_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor03_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG38_UNION;
#endif
#define SOC_HiFD_PROP_CFG38_anchor03_base_x1_START (0)
#define SOC_HiFD_PROP_CFG38_anchor03_base_x1_END (9)
#define SOC_HiFD_PROP_CFG38_anchor03_base_y1_START (16)
#define SOC_HiFD_PROP_CFG38_anchor03_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor04_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor04_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG39_UNION;
#endif
#define SOC_HiFD_PROP_CFG39_anchor04_base_x0_START (0)
#define SOC_HiFD_PROP_CFG39_anchor04_base_x0_END (9)
#define SOC_HiFD_PROP_CFG39_anchor04_base_y0_START (16)
#define SOC_HiFD_PROP_CFG39_anchor04_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor04_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor04_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG40_UNION;
#endif
#define SOC_HiFD_PROP_CFG40_anchor04_base_x1_START (0)
#define SOC_HiFD_PROP_CFG40_anchor04_base_x1_END (9)
#define SOC_HiFD_PROP_CFG40_anchor04_base_y1_START (16)
#define SOC_HiFD_PROP_CFG40_anchor04_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor05_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor05_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG41_UNION;
#endif
#define SOC_HiFD_PROP_CFG41_anchor05_base_x0_START (0)
#define SOC_HiFD_PROP_CFG41_anchor05_base_x0_END (9)
#define SOC_HiFD_PROP_CFG41_anchor05_base_y0_START (16)
#define SOC_HiFD_PROP_CFG41_anchor05_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor05_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor05_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG42_UNION;
#endif
#define SOC_HiFD_PROP_CFG42_anchor05_base_x1_START (0)
#define SOC_HiFD_PROP_CFG42_anchor05_base_x1_END (9)
#define SOC_HiFD_PROP_CFG42_anchor05_base_y1_START (16)
#define SOC_HiFD_PROP_CFG42_anchor05_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor06_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor06_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG43_UNION;
#endif
#define SOC_HiFD_PROP_CFG43_anchor06_base_x0_START (0)
#define SOC_HiFD_PROP_CFG43_anchor06_base_x0_END (9)
#define SOC_HiFD_PROP_CFG43_anchor06_base_y0_START (16)
#define SOC_HiFD_PROP_CFG43_anchor06_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor06_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor06_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG44_UNION;
#endif
#define SOC_HiFD_PROP_CFG44_anchor06_base_x1_START (0)
#define SOC_HiFD_PROP_CFG44_anchor06_base_x1_END (9)
#define SOC_HiFD_PROP_CFG44_anchor06_base_y1_START (16)
#define SOC_HiFD_PROP_CFG44_anchor06_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor07_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor07_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG45_UNION;
#endif
#define SOC_HiFD_PROP_CFG45_anchor07_base_x0_START (0)
#define SOC_HiFD_PROP_CFG45_anchor07_base_x0_END (9)
#define SOC_HiFD_PROP_CFG45_anchor07_base_y0_START (16)
#define SOC_HiFD_PROP_CFG45_anchor07_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor07_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor07_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG46_UNION;
#endif
#define SOC_HiFD_PROP_CFG46_anchor07_base_x1_START (0)
#define SOC_HiFD_PROP_CFG46_anchor07_base_x1_END (9)
#define SOC_HiFD_PROP_CFG46_anchor07_base_y1_START (16)
#define SOC_HiFD_PROP_CFG46_anchor07_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor08_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor08_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG47_UNION;
#endif
#define SOC_HiFD_PROP_CFG47_anchor08_base_x0_START (0)
#define SOC_HiFD_PROP_CFG47_anchor08_base_x0_END (9)
#define SOC_HiFD_PROP_CFG47_anchor08_base_y0_START (16)
#define SOC_HiFD_PROP_CFG47_anchor08_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor08_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor08_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG48_UNION;
#endif
#define SOC_HiFD_PROP_CFG48_anchor08_base_x1_START (0)
#define SOC_HiFD_PROP_CFG48_anchor08_base_x1_END (9)
#define SOC_HiFD_PROP_CFG48_anchor08_base_y1_START (16)
#define SOC_HiFD_PROP_CFG48_anchor08_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor09_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor09_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG49_UNION;
#endif
#define SOC_HiFD_PROP_CFG49_anchor09_base_x0_START (0)
#define SOC_HiFD_PROP_CFG49_anchor09_base_x0_END (9)
#define SOC_HiFD_PROP_CFG49_anchor09_base_y0_START (16)
#define SOC_HiFD_PROP_CFG49_anchor09_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor09_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor09_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG50_UNION;
#endif
#define SOC_HiFD_PROP_CFG50_anchor09_base_x1_START (0)
#define SOC_HiFD_PROP_CFG50_anchor09_base_x1_END (9)
#define SOC_HiFD_PROP_CFG50_anchor09_base_y1_START (16)
#define SOC_HiFD_PROP_CFG50_anchor09_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor10_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor10_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG51_UNION;
#endif
#define SOC_HiFD_PROP_CFG51_anchor10_base_x0_START (0)
#define SOC_HiFD_PROP_CFG51_anchor10_base_x0_END (9)
#define SOC_HiFD_PROP_CFG51_anchor10_base_y0_START (16)
#define SOC_HiFD_PROP_CFG51_anchor10_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor10_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor10_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG52_UNION;
#endif
#define SOC_HiFD_PROP_CFG52_anchor10_base_x1_START (0)
#define SOC_HiFD_PROP_CFG52_anchor10_base_x1_END (9)
#define SOC_HiFD_PROP_CFG52_anchor10_base_y1_START (16)
#define SOC_HiFD_PROP_CFG52_anchor10_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor11_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor11_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG53_UNION;
#endif
#define SOC_HiFD_PROP_CFG53_anchor11_base_x0_START (0)
#define SOC_HiFD_PROP_CFG53_anchor11_base_x0_END (9)
#define SOC_HiFD_PROP_CFG53_anchor11_base_y0_START (16)
#define SOC_HiFD_PROP_CFG53_anchor11_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor11_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor11_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG54_UNION;
#endif
#define SOC_HiFD_PROP_CFG54_anchor11_base_x1_START (0)
#define SOC_HiFD_PROP_CFG54_anchor11_base_x1_END (9)
#define SOC_HiFD_PROP_CFG54_anchor11_base_y1_START (16)
#define SOC_HiFD_PROP_CFG54_anchor11_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor12_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor12_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG55_UNION;
#endif
#define SOC_HiFD_PROP_CFG55_anchor12_base_x0_START (0)
#define SOC_HiFD_PROP_CFG55_anchor12_base_x0_END (9)
#define SOC_HiFD_PROP_CFG55_anchor12_base_y0_START (16)
#define SOC_HiFD_PROP_CFG55_anchor12_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor12_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor12_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG56_UNION;
#endif
#define SOC_HiFD_PROP_CFG56_anchor12_base_x1_START (0)
#define SOC_HiFD_PROP_CFG56_anchor12_base_x1_END (9)
#define SOC_HiFD_PROP_CFG56_anchor12_base_y1_START (16)
#define SOC_HiFD_PROP_CFG56_anchor12_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor13_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor13_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG57_UNION;
#endif
#define SOC_HiFD_PROP_CFG57_anchor13_base_x0_START (0)
#define SOC_HiFD_PROP_CFG57_anchor13_base_x0_END (9)
#define SOC_HiFD_PROP_CFG57_anchor13_base_y0_START (16)
#define SOC_HiFD_PROP_CFG57_anchor13_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor13_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor13_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG58_UNION;
#endif
#define SOC_HiFD_PROP_CFG58_anchor13_base_x1_START (0)
#define SOC_HiFD_PROP_CFG58_anchor13_base_x1_END (9)
#define SOC_HiFD_PROP_CFG58_anchor13_base_y1_START (16)
#define SOC_HiFD_PROP_CFG58_anchor13_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor14_base_x0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor14_base_y0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG59_UNION;
#endif
#define SOC_HiFD_PROP_CFG59_anchor14_base_x0_START (0)
#define SOC_HiFD_PROP_CFG59_anchor14_base_x0_END (9)
#define SOC_HiFD_PROP_CFG59_anchor14_base_y0_START (16)
#define SOC_HiFD_PROP_CFG59_anchor14_base_y0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int anchor14_base_x1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int anchor14_base_y1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG60_UNION;
#endif
#define SOC_HiFD_PROP_CFG60_anchor14_base_x1_START (0)
#define SOC_HiFD_PROP_CFG60_anchor14_base_x1_END (9)
#define SOC_HiFD_PROP_CFG60_anchor14_base_y1_START (16)
#define SOC_HiFD_PROP_CFG60_anchor14_base_y1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_00 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_01 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG61_UNION;
#endif
#define SOC_HiFD_PROP_CFG61_nms_thresh_md1_00_START (0)
#define SOC_HiFD_PROP_CFG61_nms_thresh_md1_00_END (9)
#define SOC_HiFD_PROP_CFG61_nms_thresh_md1_01_START (16)
#define SOC_HiFD_PROP_CFG61_nms_thresh_md1_01_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_02 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_03 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG62_UNION;
#endif
#define SOC_HiFD_PROP_CFG62_nms_thresh_md1_02_START (0)
#define SOC_HiFD_PROP_CFG62_nms_thresh_md1_02_END (9)
#define SOC_HiFD_PROP_CFG62_nms_thresh_md1_03_START (16)
#define SOC_HiFD_PROP_CFG62_nms_thresh_md1_03_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_04 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_05 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG63_UNION;
#endif
#define SOC_HiFD_PROP_CFG63_nms_thresh_md1_04_START (0)
#define SOC_HiFD_PROP_CFG63_nms_thresh_md1_04_END (9)
#define SOC_HiFD_PROP_CFG63_nms_thresh_md1_05_START (16)
#define SOC_HiFD_PROP_CFG63_nms_thresh_md1_05_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_06 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_07 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG64_UNION;
#endif
#define SOC_HiFD_PROP_CFG64_nms_thresh_md1_06_START (0)
#define SOC_HiFD_PROP_CFG64_nms_thresh_md1_06_END (9)
#define SOC_HiFD_PROP_CFG64_nms_thresh_md1_07_START (16)
#define SOC_HiFD_PROP_CFG64_nms_thresh_md1_07_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int module_clk_sel : 32;
    } reg;
} SOC_HiFD_MODULE_CLK_SEL_UNION;
#endif
#define SOC_HiFD_MODULE_CLK_SEL_module_clk_sel_START (0)
#define SOC_HiFD_MODULE_CLK_SEL_module_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int module_clk_en : 32;
    } reg;
} SOC_HiFD_MODULE_CLK_EN_UNION;
#endif
#define SOC_HiFD_MODULE_CLK_EN_module_clk_en_START (0)
#define SOC_HiFD_MODULE_CLK_EN_module_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_sel : 32;
    } reg;
} SOC_HiFD_CH_CLK_SEL_UNION;
#endif
#define SOC_HiFD_CH_CLK_SEL_ch_clk_sel_START (0)
#define SOC_HiFD_CH_CLK_SEL_ch_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_en : 32;
    } reg;
} SOC_HiFD_CH_CLK_EN_UNION;
#endif
#define SOC_HiFD_CH_CLK_EN_ch_clk_en_START (0)
#define SOC_HiFD_CH_CLK_EN_ch_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_samp_y_c_offset : 10;
        unsigned int reserved_0 : 6;
        unsigned int pre_samp_y_c_width : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_HiFD_PRE_SAMP_Y_OFFSET_UNION;
#endif
#define SOC_HiFD_PRE_SAMP_Y_OFFSET_pre_samp_y_c_offset_START (0)
#define SOC_HiFD_PRE_SAMP_Y_OFFSET_pre_samp_y_c_offset_END (9)
#define SOC_HiFD_PRE_SAMP_Y_OFFSET_pre_samp_y_c_width_START (16)
#define SOC_HiFD_PRE_SAMP_Y_OFFSET_pre_samp_y_c_width_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_samp_width : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HiFD_PRE_SAMP_WIDTH_UNION;
#endif
#define SOC_HiFD_PRE_SAMP_WIDTH_pre_samp_width_START (0)
#define SOC_HiFD_PRE_SAMP_WIDTH_pre_samp_width_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_input_mode : 2;
        unsigned int reserved_0 : 6;
        unsigned int ultra_red_colour : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HiFD_PRE_MODE_UNION;
#endif
#define SOC_HiFD_PRE_MODE_pre_input_mode_START (0)
#define SOC_HiFD_PRE_MODE_pre_input_mode_END (1)
#define SOC_HiFD_PRE_MODE_ultra_red_colour_START (8)
#define SOC_HiFD_PRE_MODE_ultra_red_colour_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_dfc_right_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int pre_dfc_left_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_HiFD_PRE_DFC_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_HiFD_PRE_DFC_CLIP_CTL_HRZ_pre_dfc_right_clip_START (0)
#define SOC_HiFD_PRE_DFC_CLIP_CTL_HRZ_pre_dfc_right_clip_END (5)
#define SOC_HiFD_PRE_DFC_CLIP_CTL_HRZ_pre_dfc_left_clip_START (16)
#define SOC_HiFD_PRE_DFC_CLIP_CTL_HRZ_pre_dfc_left_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_dfc_module_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int dfc_ax_swap : 1;
        unsigned int dfc_img_fmt : 5;
        unsigned int dfc_uv_swap : 1;
        unsigned int dfc_rb_swap : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HiFD_PRE_DFC_MODE_UNION;
#endif
#define SOC_HiFD_PRE_DFC_MODE_pre_dfc_module_en_START (0)
#define SOC_HiFD_PRE_DFC_MODE_pre_dfc_module_en_END (0)
#define SOC_HiFD_PRE_DFC_MODE_dfc_ax_swap_START (8)
#define SOC_HiFD_PRE_DFC_MODE_dfc_ax_swap_END (8)
#define SOC_HiFD_PRE_DFC_MODE_dfc_img_fmt_START (9)
#define SOC_HiFD_PRE_DFC_MODE_dfc_img_fmt_END (13)
#define SOC_HiFD_PRE_DFC_MODE_dfc_uv_swap_START (14)
#define SOC_HiFD_PRE_DFC_MODE_dfc_uv_swap_END (14)
#define SOC_HiFD_PRE_DFC_MODE_dfc_rb_swap_START (15)
#define SOC_HiFD_PRE_DFC_MODE_dfc_rb_swap_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_dfc_bot_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int pre_dfc_top_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_HiFD_PRE_DFC_CLIP_CTL_VRT_UNION;
#endif
#define SOC_HiFD_PRE_DFC_CLIP_CTL_VRT_pre_dfc_bot_clip_START (0)
#define SOC_HiFD_PRE_DFC_CLIP_CTL_VRT_pre_dfc_bot_clip_END (5)
#define SOC_HiFD_PRE_DFC_CLIP_CTL_VRT_pre_dfc_top_clip_START (16)
#define SOC_HiFD_PRE_DFC_CLIP_CTL_VRT_pre_dfc_top_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_idc0 : 11;
        unsigned int reserved_0 : 5;
        unsigned int pre_csc_idc1 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_HiFD_PRE_CSC_IDC0_UNION;
#endif
#define SOC_HiFD_PRE_CSC_IDC0_pre_csc_idc0_START (0)
#define SOC_HiFD_PRE_CSC_IDC0_pre_csc_idc0_END (10)
#define SOC_HiFD_PRE_CSC_IDC0_pre_csc_idc1_START (16)
#define SOC_HiFD_PRE_CSC_IDC0_pre_csc_idc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_HiFD_PRE_CSC_IDC2_UNION;
#endif
#define SOC_HiFD_PRE_CSC_IDC2_pre_csc_idc2_START (0)
#define SOC_HiFD_PRE_CSC_IDC2_pre_csc_idc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_odc0 : 11;
        unsigned int reserved_0 : 5;
        unsigned int pre_csc_odc1 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_HiFD_PRE_CSC_ODC0_UNION;
#endif
#define SOC_HiFD_PRE_CSC_ODC0_pre_csc_odc0_START (0)
#define SOC_HiFD_PRE_CSC_ODC0_pre_csc_odc0_END (10)
#define SOC_HiFD_PRE_CSC_ODC0_pre_csc_odc1_START (16)
#define SOC_HiFD_PRE_CSC_ODC0_pre_csc_odc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_HiFD_PRE_CSC_ODC2_UNION;
#endif
#define SOC_HiFD_PRE_CSC_ODC2_pre_csc_odc2_START (0)
#define SOC_HiFD_PRE_CSC_ODC2_pre_csc_odc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_p00 : 13;
        unsigned int reserved_0 : 3;
        unsigned int pre_csc_p01 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_HiFD_PRE_CSC_P0_UNION;
#endif
#define SOC_HiFD_PRE_CSC_P0_pre_csc_p00_START (0)
#define SOC_HiFD_PRE_CSC_P0_pre_csc_p00_END (12)
#define SOC_HiFD_PRE_CSC_P0_pre_csc_p01_START (16)
#define SOC_HiFD_PRE_CSC_P0_pre_csc_p01_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_p02 : 13;
        unsigned int reserved_0 : 3;
        unsigned int pre_csc_p10 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_HiFD_PRE_CSC_P1_UNION;
#endif
#define SOC_HiFD_PRE_CSC_P1_pre_csc_p02_START (0)
#define SOC_HiFD_PRE_CSC_P1_pre_csc_p02_END (12)
#define SOC_HiFD_PRE_CSC_P1_pre_csc_p10_START (16)
#define SOC_HiFD_PRE_CSC_P1_pre_csc_p10_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_p11 : 13;
        unsigned int reserved_0 : 3;
        unsigned int pre_csc_p12 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_HiFD_PRE_CSC_P2_UNION;
#endif
#define SOC_HiFD_PRE_CSC_P2_pre_csc_p11_START (0)
#define SOC_HiFD_PRE_CSC_P2_pre_csc_p11_END (12)
#define SOC_HiFD_PRE_CSC_P2_pre_csc_p12_START (16)
#define SOC_HiFD_PRE_CSC_P2_pre_csc_p12_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_p20 : 13;
        unsigned int reserved_0 : 3;
        unsigned int pre_csc_p21 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_HiFD_PRE_CSC_P3_UNION;
#endif
#define SOC_HiFD_PRE_CSC_P3_pre_csc_p20_START (0)
#define SOC_HiFD_PRE_CSC_P3_pre_csc_p20_END (12)
#define SOC_HiFD_PRE_CSC_P3_pre_csc_p21_START (16)
#define SOC_HiFD_PRE_CSC_P3_pre_csc_p21_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_p22 : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_HiFD_PRE_CSC_P4_UNION;
#endif
#define SOC_HiFD_PRE_CSC_P4_pre_csc_p22_START (0)
#define SOC_HiFD_PRE_CSC_P4_pre_csc_p22_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_PRE_CSC_ICG_MODULE_UNION;
#endif
#define SOC_HiFD_PRE_CSC_ICG_MODULE_pre_csc_module_en_START (0)
#define SOC_HiFD_PRE_CSC_ICG_MODULE_pre_csc_module_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HiFD_PRE_CSC_MPREC_UNION;
#endif
#define SOC_HiFD_PRE_CSC_MPREC_pre_csc_mprec_START (0)
#define SOC_HiFD_PRE_CSC_MPREC_pre_csc_mprec_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_input_width : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HiFD_PRE_SCF_INPUT_WIDTH_UNION;
#endif
#define SOC_HiFD_PRE_SCF_INPUT_WIDTH_pre_scf_input_width_START (0)
#define SOC_HiFD_PRE_SCF_INPUT_WIDTH_pre_scf_input_width_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_output_width : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HiFD_PRE_SCF_OUTPUT_WIDTH_UNION;
#endif
#define SOC_HiFD_PRE_SCF_OUTPUT_WIDTH_pre_scf_output_width_START (0)
#define SOC_HiFD_PRE_SCF_OUTPUT_WIDTH_pre_scf_output_width_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_en_hscl_str : 1;
        unsigned int pre_scf_en_hscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_PRE_SCF_EN_HSCL_STR_UNION;
#endif
#define SOC_HiFD_PRE_SCF_EN_HSCL_STR_pre_scf_en_hscl_str_START (0)
#define SOC_HiFD_PRE_SCF_EN_HSCL_STR_pre_scf_en_hscl_str_END (0)
#define SOC_HiFD_PRE_SCF_EN_HSCL_STR_pre_scf_en_hscl_str_a_START (1)
#define SOC_HiFD_PRE_SCF_EN_HSCL_STR_pre_scf_en_hscl_str_a_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_en_vscl_str : 1;
        unsigned int pre_scf_en_vscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_PRE_SCF_EN_VSCL_STR_UNION;
#endif
#define SOC_HiFD_PRE_SCF_EN_VSCL_STR_pre_scf_en_vscl_str_START (0)
#define SOC_HiFD_PRE_SCF_EN_VSCL_STR_pre_scf_en_vscl_str_END (0)
#define SOC_HiFD_PRE_SCF_EN_VSCL_STR_pre_scf_en_vscl_str_a_START (1)
#define SOC_HiFD_PRE_SCF_EN_VSCL_STR_pre_scf_en_vscl_str_a_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_h_v_order : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_PRE_SCF_H_V_ORDER_UNION;
#endif
#define SOC_HiFD_PRE_SCF_H_V_ORDER_pre_scf_h_v_order_START (0)
#define SOC_HiFD_PRE_SCF_H_V_ORDER_pre_scf_h_v_order_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_a_core_gt : 1;
        unsigned int pre_scf_r_core_gt : 1;
        unsigned int pre_scf_g_core_gt : 1;
        unsigned int pre_scf_b_core_gt : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_HiFD_PRE_SCF_CH_CORE_GT_UNION;
#endif
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_a_core_gt_START (0)
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_a_core_gt_END (0)
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_r_core_gt_START (1)
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_r_core_gt_END (1)
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_g_core_gt_START (2)
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_g_core_gt_END (2)
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_b_core_gt_START (3)
#define SOC_HiFD_PRE_SCF_CH_CORE_GT_pre_scf_b_core_gt_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_en_hscl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_PRE_SCF_EN_HSCL_UNION;
#endif
#define SOC_HiFD_PRE_SCF_EN_HSCL_pre_scf_en_hscl_en_START (0)
#define SOC_HiFD_PRE_SCF_EN_HSCL_pre_scf_en_hscl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_en_vscl_en : 1;
        unsigned int pre_scf_out_buffer_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_PRE_SCF_EN_VSCL_UNION;
#endif
#define SOC_HiFD_PRE_SCF_EN_VSCL_pre_scf_en_vscl_en_START (0)
#define SOC_HiFD_PRE_SCF_EN_VSCL_pre_scf_en_vscl_en_END (0)
#define SOC_HiFD_PRE_SCF_EN_VSCL_pre_scf_out_buffer_en_START (1)
#define SOC_HiFD_PRE_SCF_EN_VSCL_pre_scf_out_buffer_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_inc_hscl : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_HiFD_PRE_SCF_INC_HSCL_UNION;
#endif
#define SOC_HiFD_PRE_SCF_INC_HSCL_pre_scf_inc_hscl_START (0)
#define SOC_HiFD_PRE_SCF_INC_HSCL_pre_scf_inc_hscl_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_scf_inc_vscl : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_HiFD_PRE_SCF_INC_VSCL_UNION;
#endif
#define SOC_HiFD_PRE_SCF_INC_VSCL_pre_scf_inc_vscl_START (0)
#define SOC_HiFD_PRE_SCF_INC_VSCL_pre_scf_inc_vscl_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_post_clip_left : 6;
        unsigned int reserved_0 : 10;
        unsigned int pre_post_clip_right : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_HiFD_PRE_POST_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_HiFD_PRE_POST_CLIP_CTL_HRZ_pre_post_clip_left_START (0)
#define SOC_HiFD_PRE_POST_CLIP_CTL_HRZ_pre_post_clip_left_END (5)
#define SOC_HiFD_PRE_POST_CLIP_CTL_HRZ_pre_post_clip_right_START (16)
#define SOC_HiFD_PRE_POST_CLIP_CTL_HRZ_pre_post_clip_right_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_rea_input_width : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_HiFD_PRE_REA_WIDTH_UNION;
#endif
#define SOC_HiFD_PRE_REA_WIDTH_pre_rea_input_width_START (0)
#define SOC_HiFD_PRE_REA_WIDTH_pre_rea_input_width_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_rea_pad_left : 6;
        unsigned int reserved_0 : 10;
        unsigned int pre_rea_pad_right : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_HiFD_PRE_REA_PAD_HRZ_UNION;
#endif
#define SOC_HiFD_PRE_REA_PAD_HRZ_pre_rea_pad_left_START (0)
#define SOC_HiFD_PRE_REA_PAD_HRZ_pre_rea_pad_left_END (5)
#define SOC_HiFD_PRE_REA_PAD_HRZ_pre_rea_pad_right_START (16)
#define SOC_HiFD_PRE_REA_PAD_HRZ_pre_rea_pad_right_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_rea_pad_shift_r : 8;
        unsigned int pre_rea_pad_shift_g : 8;
        unsigned int pre_rea_pad_shift_b : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HiFD_PRE_REA_PAD_SHIFT_UNION;
#endif
#define SOC_HiFD_PRE_REA_PAD_SHIFT_pre_rea_pad_shift_r_START (0)
#define SOC_HiFD_PRE_REA_PAD_SHIFT_pre_rea_pad_shift_r_END (7)
#define SOC_HiFD_PRE_REA_PAD_SHIFT_pre_rea_pad_shift_g_START (8)
#define SOC_HiFD_PRE_REA_PAD_SHIFT_pre_rea_pad_shift_g_END (15)
#define SOC_HiFD_PRE_REA_PAD_SHIFT_pre_rea_pad_shift_b_START (16)
#define SOC_HiFD_PRE_REA_PAD_SHIFT_pre_rea_pad_shift_b_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdam_raw_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_RDMA_RAW_EN_UNION;
#endif
#define SOC_HiFD_RDMA_RAW_EN_rdam_raw_en_START (0)
#define SOC_HiFD_RDMA_RAW_EN_rdam_raw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_block_rot_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_RDMA_BLOCK_ROT_EN_UNION;
#endif
#define SOC_HiFD_RDMA_BLOCK_ROT_EN_rdma_block_rot_en_START (0)
#define SOC_HiFD_RDMA_BLOCK_ROT_EN_rdma_block_rot_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_outstanding : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HiFD_RDMA_OUTSTANGING_UNION;
#endif
#define SOC_HiFD_RDMA_OUTSTANGING_rdma_outstanding_START (0)
#define SOC_HiFD_RDMA_OUTSTANGING_rdma_outstanding_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_arcache : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HiFD_RDMA_ARCACHE_UNION;
#endif
#define SOC_HiFD_RDMA_ARCACHE_rdma_arcache_START (0)
#define SOC_HiFD_RDMA_ARCACHE_rdma_arcache_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_arprot : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HiFD_RDMA_ARPROT_UNION;
#endif
#define SOC_HiFD_RDMA_ARPROT_rdma_arprot_START (0)
#define SOC_HiFD_RDMA_ARPROT_rdma_arprot_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_arqos : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HiFD_RDMA_ARQOS_UNION;
#endif
#define SOC_HiFD_RDMA_ARQOS_rdma_arqos_START (0)
#define SOC_HiFD_RDMA_ARQOS_rdma_arqos_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future0 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE0_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE0_rdma_future0_START (0)
#define SOC_HiFD_RDMA_RESERVE0_rdma_future0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future1 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE1_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE1_rdma_future1_START (0)
#define SOC_HiFD_RDMA_RESERVE1_rdma_future1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future2 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE2_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE2_rdma_future2_START (0)
#define SOC_HiFD_RDMA_RESERVE2_rdma_future2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future3 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE3_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE3_rdma_future3_START (0)
#define SOC_HiFD_RDMA_RESERVE3_rdma_future3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int dma_axuser0 : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HiFD_DMA_AXUSER0_UNION;
#endif
#define SOC_HiFD_DMA_AXUSER0_dma_axuser0_START (8)
#define SOC_HiFD_DMA_AXUSER0_dma_axuser0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos1 : 4;
        unsigned int dma_axcache1 : 4;
        unsigned int dma_axuser1 : 8;
        unsigned int dma_axprot1 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH1_UNION;
#endif
#define SOC_HiFD_DMA_AXCH1_dma_axqos1_START (0)
#define SOC_HiFD_DMA_AXCH1_dma_axqos1_END (3)
#define SOC_HiFD_DMA_AXCH1_dma_axcache1_START (4)
#define SOC_HiFD_DMA_AXCH1_dma_axcache1_END (7)
#define SOC_HiFD_DMA_AXCH1_dma_axuser1_START (8)
#define SOC_HiFD_DMA_AXCH1_dma_axuser1_END (15)
#define SOC_HiFD_DMA_AXCH1_dma_axprot1_START (16)
#define SOC_HiFD_DMA_AXCH1_dma_axprot1_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos2 : 4;
        unsigned int dma_axcache2 : 4;
        unsigned int dma_axuser2 : 8;
        unsigned int dma_axprot2 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH2_UNION;
#endif
#define SOC_HiFD_DMA_AXCH2_dma_axqos2_START (0)
#define SOC_HiFD_DMA_AXCH2_dma_axqos2_END (3)
#define SOC_HiFD_DMA_AXCH2_dma_axcache2_START (4)
#define SOC_HiFD_DMA_AXCH2_dma_axcache2_END (7)
#define SOC_HiFD_DMA_AXCH2_dma_axuser2_START (8)
#define SOC_HiFD_DMA_AXCH2_dma_axuser2_END (15)
#define SOC_HiFD_DMA_AXCH2_dma_axprot2_START (16)
#define SOC_HiFD_DMA_AXCH2_dma_axprot2_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos3 : 4;
        unsigned int dma_axcache3 : 4;
        unsigned int dma_axuser3 : 8;
        unsigned int dma_axprot3 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH3_UNION;
#endif
#define SOC_HiFD_DMA_AXCH3_dma_axqos3_START (0)
#define SOC_HiFD_DMA_AXCH3_dma_axqos3_END (3)
#define SOC_HiFD_DMA_AXCH3_dma_axcache3_START (4)
#define SOC_HiFD_DMA_AXCH3_dma_axcache3_END (7)
#define SOC_HiFD_DMA_AXCH3_dma_axuser3_START (8)
#define SOC_HiFD_DMA_AXCH3_dma_axuser3_END (15)
#define SOC_HiFD_DMA_AXCH3_dma_axprot3_START (16)
#define SOC_HiFD_DMA_AXCH3_dma_axprot3_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos4 : 4;
        unsigned int dma_axcache4 : 4;
        unsigned int dma_axuser4 : 8;
        unsigned int dma_axprot4 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH4_UNION;
#endif
#define SOC_HiFD_DMA_AXCH4_dma_axqos4_START (0)
#define SOC_HiFD_DMA_AXCH4_dma_axqos4_END (3)
#define SOC_HiFD_DMA_AXCH4_dma_axcache4_START (4)
#define SOC_HiFD_DMA_AXCH4_dma_axcache4_END (7)
#define SOC_HiFD_DMA_AXCH4_dma_axuser4_START (8)
#define SOC_HiFD_DMA_AXCH4_dma_axuser4_END (15)
#define SOC_HiFD_DMA_AXCH4_dma_axprot4_START (16)
#define SOC_HiFD_DMA_AXCH4_dma_axprot4_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos5 : 4;
        unsigned int dma_axcache5 : 4;
        unsigned int dma_axuser5 : 8;
        unsigned int dma_axprot5 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH5_UNION;
#endif
#define SOC_HiFD_DMA_AXCH5_dma_axqos5_START (0)
#define SOC_HiFD_DMA_AXCH5_dma_axqos5_END (3)
#define SOC_HiFD_DMA_AXCH5_dma_axcache5_START (4)
#define SOC_HiFD_DMA_AXCH5_dma_axcache5_END (7)
#define SOC_HiFD_DMA_AXCH5_dma_axuser5_START (8)
#define SOC_HiFD_DMA_AXCH5_dma_axuser5_END (15)
#define SOC_HiFD_DMA_AXCH5_dma_axprot5_START (16)
#define SOC_HiFD_DMA_AXCH5_dma_axprot5_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos6 : 4;
        unsigned int dma_axcache6 : 4;
        unsigned int dma_axuser6 : 8;
        unsigned int dma_axprot6 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH6_UNION;
#endif
#define SOC_HiFD_DMA_AXCH6_dma_axqos6_START (0)
#define SOC_HiFD_DMA_AXCH6_dma_axqos6_END (3)
#define SOC_HiFD_DMA_AXCH6_dma_axcache6_START (4)
#define SOC_HiFD_DMA_AXCH6_dma_axcache6_END (7)
#define SOC_HiFD_DMA_AXCH6_dma_axuser6_START (8)
#define SOC_HiFD_DMA_AXCH6_dma_axuser6_END (15)
#define SOC_HiFD_DMA_AXCH6_dma_axprot6_START (16)
#define SOC_HiFD_DMA_AXCH6_dma_axprot6_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos7 : 4;
        unsigned int dma_axcache7 : 4;
        unsigned int dma_axuser7 : 8;
        unsigned int dma_axprot7 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH7_UNION;
#endif
#define SOC_HiFD_DMA_AXCH7_dma_axqos7_START (0)
#define SOC_HiFD_DMA_AXCH7_dma_axqos7_END (3)
#define SOC_HiFD_DMA_AXCH7_dma_axcache7_START (4)
#define SOC_HiFD_DMA_AXCH7_dma_axcache7_END (7)
#define SOC_HiFD_DMA_AXCH7_dma_axuser7_START (8)
#define SOC_HiFD_DMA_AXCH7_dma_axuser7_END (15)
#define SOC_HiFD_DMA_AXCH7_dma_axprot7_START (16)
#define SOC_HiFD_DMA_AXCH7_dma_axprot7_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos8 : 4;
        unsigned int dma_axcache8 : 4;
        unsigned int dma_axuser8 : 8;
        unsigned int dma_axprot8 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH8_UNION;
#endif
#define SOC_HiFD_DMA_AXCH8_dma_axqos8_START (0)
#define SOC_HiFD_DMA_AXCH8_dma_axqos8_END (3)
#define SOC_HiFD_DMA_AXCH8_dma_axcache8_START (4)
#define SOC_HiFD_DMA_AXCH8_dma_axcache8_END (7)
#define SOC_HiFD_DMA_AXCH8_dma_axuser8_START (8)
#define SOC_HiFD_DMA_AXCH8_dma_axuser8_END (15)
#define SOC_HiFD_DMA_AXCH8_dma_axprot8_START (16)
#define SOC_HiFD_DMA_AXCH8_dma_axprot8_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_axqos9 : 4;
        unsigned int dma_axcache9 : 4;
        unsigned int dma_axuser9 : 8;
        unsigned int dma_axprot9 : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_HiFD_DMA_AXCH9_UNION;
#endif
#define SOC_HiFD_DMA_AXCH9_dma_axqos9_START (0)
#define SOC_HiFD_DMA_AXCH9_dma_axqos9_END (3)
#define SOC_HiFD_DMA_AXCH9_dma_axcache9_START (4)
#define SOC_HiFD_DMA_AXCH9_dma_axcache9_END (7)
#define SOC_HiFD_DMA_AXCH9_dma_axuser9_START (8)
#define SOC_HiFD_DMA_AXCH9_dma_axuser9_END (15)
#define SOC_HiFD_DMA_AXCH9_dma_axprot9_START (16)
#define SOC_HiFD_DMA_AXCH9_dma_axprot9_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future4 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE4_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE4_rdma_future4_START (0)
#define SOC_HiFD_RDMA_RESERVE4_rdma_future4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future5 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE5_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE5_rdma_future5_START (0)
#define SOC_HiFD_RDMA_RESERVE5_rdma_future5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future6 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE6_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE6_rdma_future6_START (0)
#define SOC_HiFD_RDMA_RESERVE6_rdma_future6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future7 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE7_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE7_rdma_future7_START (0)
#define SOC_HiFD_RDMA_RESERVE7_rdma_future7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future8 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE8_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE8_rdma_future8_START (0)
#define SOC_HiFD_RDMA_RESERVE8_rdma_future8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future9 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE9_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE9_rdma_future9_START (0)
#define SOC_HiFD_RDMA_RESERVE9_rdma_future9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future10 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE10_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE10_rdma_future10_START (0)
#define SOC_HiFD_RDMA_RESERVE10_rdma_future10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdma_future11 : 32;
    } reg;
} SOC_HiFD_RDMA_RESERVE11_UNION;
#endif
#define SOC_HiFD_RDMA_RESERVE11_rdma_future11_START (0)
#define SOC_HiFD_RDMA_RESERVE11_rdma_future11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_os : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HiFD_WDMA_OUTSTANDING_UNION;
#endif
#define SOC_HiFD_WDMA_OUTSTANDING_wdma_os_START (0)
#define SOC_HiFD_WDMA_OUTSTANDING_wdma_os_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_raw_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_WDMA_RAW_EN_UNION;
#endif
#define SOC_HiFD_WDMA_RAW_EN_wdma_raw_en_START (0)
#define SOC_HiFD_WDMA_RAW_EN_wdma_raw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_block_rot_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_WDMA_BLOCK_ROT_EN_UNION;
#endif
#define SOC_HiFD_WDMA_BLOCK_ROT_EN_wdma_block_rot_en_START (0)
#define SOC_HiFD_WDMA_BLOCK_ROT_EN_wdma_block_rot_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_hfbce_auto_clk_gt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_WDMA_HFBCE_AUTO_CLK_GT_EN_UNION;
#endif
#define SOC_HiFD_WDMA_HFBCE_AUTO_CLK_GT_EN_wdma_hfbce_auto_clk_gt_en_START (0)
#define SOC_HiFD_WDMA_HFBCE_AUTO_CLK_GT_EN_wdma_hfbce_auto_clk_gt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_threshold : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_HiFD_WDMA_THRESHOLD_UNION;
#endif
#define SOC_HiFD_WDMA_THRESHOLD_wdma_threshold_START (0)
#define SOC_HiFD_WDMA_THRESHOLD_wdma_threshold_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_debug0 : 32;
    } reg;
} SOC_HiFD_WDMA_DEBUG0_UNION;
#endif
#define SOC_HiFD_WDMA_DEBUG0_wdma_debug0_START (0)
#define SOC_HiFD_WDMA_DEBUG0_wdma_debug0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_debug1 : 32;
    } reg;
} SOC_HiFD_WDMA_DEBUG1_UNION;
#endif
#define SOC_HiFD_WDMA_DEBUG1_wdma_debug1_START (0)
#define SOC_HiFD_WDMA_DEBUG1_wdma_debug1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_monitor0 : 32;
    } reg;
} SOC_HiFD_WDMA_MONITOR0_UNION;
#endif
#define SOC_HiFD_WDMA_MONITOR0_wdma_monitor0_START (0)
#define SOC_HiFD_WDMA_MONITOR0_wdma_monitor0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_monitor1 : 32;
    } reg;
} SOC_HiFD_WDMA_MONITOR1_UNION;
#endif
#define SOC_HiFD_WDMA_MONITOR1_wdma_monitor1_START (0)
#define SOC_HiFD_WDMA_MONITOR1_wdma_monitor1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_monitor2 : 32;
    } reg;
} SOC_HiFD_WDMA_MONITOR2_UNION;
#endif
#define SOC_HiFD_WDMA_MONITOR2_wdma_monitor2_START (0)
#define SOC_HiFD_WDMA_MONITOR2_wdma_monitor2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_monitor3 : 32;
    } reg;
} SOC_HiFD_WDMA_MONITOR3_UNION;
#endif
#define SOC_HiFD_WDMA_MONITOR3_wdma_monitor3_START (0)
#define SOC_HiFD_WDMA_MONITOR3_wdma_monitor3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_awcache : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HiFD_WDMA_AWCACHE_UNION;
#endif
#define SOC_HiFD_WDMA_AWCACHE_wdma_awcache_START (0)
#define SOC_HiFD_WDMA_AWCACHE_wdma_awcache_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_prot : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HiFD_WDMA_AWPROT_UNION;
#endif
#define SOC_HiFD_WDMA_AWPROT_wdma_prot_START (0)
#define SOC_HiFD_WDMA_AWPROT_wdma_prot_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdma_qos : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_HiFD_WDMA_AWQOS_UNION;
#endif
#define SOC_HiFD_WDMA_AWQOS_wdma_qos_START (0)
#define SOC_HiFD_WDMA_AWQOS_wdma_qos_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr1 : 32;
    } reg;
} SOC_HiFD_BASE_ADDR1_UNION;
#endif
#define SOC_HiFD_BASE_ADDR1_base_addr1_START (0)
#define SOC_HiFD_BASE_ADDR1_base_addr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr2 : 32;
    } reg;
} SOC_HiFD_BASE_ADDR2_UNION;
#endif
#define SOC_HiFD_BASE_ADDR2_base_addr2_START (0)
#define SOC_HiFD_BASE_ADDR2_base_addr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr3 : 32;
    } reg;
} SOC_HiFD_BASE_ADDR3_UNION;
#endif
#define SOC_HiFD_BASE_ADDR3_base_addr3_START (0)
#define SOC_HiFD_BASE_ADDR3_base_addr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scramble_mode : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_HiFD_SCRAMBLE_MODE_UNION;
#endif
#define SOC_HiFD_SCRAMBLE_MODE_scramble_mode_START (0)
#define SOC_HiFD_SCRAMBLE_MODE_scramble_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int block_align_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_BLOCK_ALIGN_EN_UNION;
#endif
#define SOC_HiFD_BLOCK_ALIGN_EN_block_align_en_START (0)
#define SOC_HiFD_BLOCK_ALIGN_EN_block_align_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr1_hi : 32;
    } reg;
} SOC_HiFD_BASE_ADDR1_hi_UNION;
#endif
#define SOC_HiFD_BASE_ADDR1_hi_base_addr1_hi_START (0)
#define SOC_HiFD_BASE_ADDR1_hi_base_addr1_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr2_hi : 32;
    } reg;
} SOC_HiFD_BASE_ADDR2_hi_UNION;
#endif
#define SOC_HiFD_BASE_ADDR2_hi_base_addr2_hi_START (0)
#define SOC_HiFD_BASE_ADDR2_hi_base_addr2_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int base_addr3_hi : 32;
    } reg;
} SOC_HiFD_BASE_ADDR3_hi_UNION;
#endif
#define SOC_HiFD_BASE_ADDR3_hi_base_addr3_hi_START (0)
#define SOC_HiFD_BASE_ADDR3_hi_base_addr3_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int x2x_enable_data_packing_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_X2X_ENABLE_DATA_PACKING_N_UNION;
#endif
#define SOC_HiFD_X2X_ENABLE_DATA_PACKING_N_x2x_enable_data_packing_n_START (0)
#define SOC_HiFD_X2X_ENABLE_DATA_PACKING_N_x2x_enable_data_packing_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int out_of_boundary_report_en : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_HiFD_OUT_OF_BOUNDARY_REPORT_EN_UNION;
#endif
#define SOC_HiFD_OUT_OF_BOUNDARY_REPORT_EN_out_of_boundary_report_en_START (0)
#define SOC_HiFD_OUT_OF_BOUNDARY_REPORT_EN_out_of_boundary_report_en_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int out_of_boundary : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_HiFD_OUT_OF_BOUNDARY_STATUS_UNION;
#endif
#define SOC_HiFD_OUT_OF_BOUNDARY_STATUS_out_of_boundary_START (0)
#define SOC_HiFD_OUT_OF_BOUNDARY_STATUS_out_of_boundary_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int out_of_boundary_addr : 16;
    } reg;
} SOC_HiFD_OUT_OF_BOUNDARY_ADDR_UNION;
#endif
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_out_of_boundary_addr_START (16)
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_out_of_boundary_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_sel : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_HiFD_OUT_OF_BOUNDARY_ADDR_SEL_UNION;
#endif
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_SEL_addr_sel_START (0)
#define SOC_HiFD_OUT_OF_BOUNDARY_ADDR_SEL_addr_sel_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_DEBUG_MODE_UNION;
#endif
#define SOC_HiFD_DEBUG_MODE_debug_mode_START (0)
#define SOC_HiFD_DEBUG_MODE_debug_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_step_len : 32;
    } reg;
} SOC_HiFD_DEBUG_STEP_LEN_UNION;
#endif
#define SOC_HiFD_DEBUG_STEP_LEN_debug_step_len_START (0)
#define SOC_HiFD_DEBUG_STEP_LEN_debug_step_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_breakpoint : 32;
    } reg;
} SOC_HiFD_DEBUG_BREAKPOINT_UNION;
#endif
#define SOC_HiFD_DEBUG_BREAKPOINT_debug_breakpoint_START (0)
#define SOC_HiFD_DEBUG_BREAKPOINT_debug_breakpoint_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_run : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HiFD_DEBUG_RUN_UNION;
#endif
#define SOC_HiFD_DEBUG_RUN_debug_run_START (0)
#define SOC_HiFD_DEBUG_RUN_debug_run_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_spm_rd_permit : 1;
        unsigned int debug_spm_rd_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HiFD_DEBUG_SPM_RD_UNION;
#endif
#define SOC_HiFD_DEBUG_SPM_RD_debug_spm_rd_permit_START (0)
#define SOC_HiFD_DEBUG_SPM_RD_debug_spm_rd_permit_END (0)
#define SOC_HiFD_DEBUG_SPM_RD_debug_spm_rd_en_START (1)
#define SOC_HiFD_DEBUG_SPM_RD_debug_spm_rd_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_spm_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HiFD_DEBUG_SPM_ADDR_UNION;
#endif
#define SOC_HiFD_DEBUG_SPM_ADDR_debug_spm_addr_START (0)
#define SOC_HiFD_DEBUG_SPM_ADDR_debug_spm_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_spm_rdata0 : 32;
    } reg;
} SOC_HiFD_DEBUG_SPM_RDATA0_UNION;
#endif
#define SOC_HiFD_DEBUG_SPM_RDATA0_debug_spm_rdata0_START (0)
#define SOC_HiFD_DEBUG_SPM_RDATA0_debug_spm_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_spm_rdata1 : 32;
    } reg;
} SOC_HiFD_DEBUG_SPM_RDATA1_UNION;
#endif
#define SOC_HiFD_DEBUG_SPM_RDATA1_debug_spm_rdata1_START (0)
#define SOC_HiFD_DEBUG_SPM_RDATA1_debug_spm_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_spm_rdata2 : 32;
    } reg;
} SOC_HiFD_DEBUG_SPM_RDATA2_UNION;
#endif
#define SOC_HiFD_DEBUG_SPM_RDATA2_debug_spm_rdata2_START (0)
#define SOC_HiFD_DEBUG_SPM_RDATA2_debug_spm_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_spm_rdata3 : 32;
    } reg;
} SOC_HiFD_DEBUG_SPM_RDATA3_UNION;
#endif
#define SOC_HiFD_DEBUG_SPM_RDATA3_debug_spm_rdata3_START (0)
#define SOC_HiFD_DEBUG_SPM_RDATA3_debug_spm_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_08 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_09 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG65_UNION;
#endif
#define SOC_HiFD_PROP_CFG65_nms_thresh_md1_08_START (0)
#define SOC_HiFD_PROP_CFG65_nms_thresh_md1_08_END (9)
#define SOC_HiFD_PROP_CFG65_nms_thresh_md1_09_START (16)
#define SOC_HiFD_PROP_CFG65_nms_thresh_md1_09_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_11 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG66_UNION;
#endif
#define SOC_HiFD_PROP_CFG66_nms_thresh_md1_10_START (0)
#define SOC_HiFD_PROP_CFG66_nms_thresh_md1_10_END (9)
#define SOC_HiFD_PROP_CFG66_nms_thresh_md1_11_START (16)
#define SOC_HiFD_PROP_CFG66_nms_thresh_md1_11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_12 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_13 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG67_UNION;
#endif
#define SOC_HiFD_PROP_CFG67_nms_thresh_md1_12_START (0)
#define SOC_HiFD_PROP_CFG67_nms_thresh_md1_12_END (9)
#define SOC_HiFD_PROP_CFG67_nms_thresh_md1_13_START (16)
#define SOC_HiFD_PROP_CFG67_nms_thresh_md1_13_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nms_thresh_md1_14 : 10;
        unsigned int reserved_0 : 6;
        unsigned int nms_thresh_md1_15 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG68_UNION;
#endif
#define SOC_HiFD_PROP_CFG68_nms_thresh_md1_14_START (0)
#define SOC_HiFD_PROP_CFG68_nms_thresh_md1_14_END (9)
#define SOC_HiFD_PROP_CFG68_nms_thresh_md1_15_START (16)
#define SOC_HiFD_PROP_CFG68_nms_thresh_md1_15_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_00 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_01 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG69_UNION;
#endif
#define SOC_HiFD_PROP_CFG69_prop_cnt_md1_00_START (0)
#define SOC_HiFD_PROP_CFG69_prop_cnt_md1_00_END (9)
#define SOC_HiFD_PROP_CFG69_prop_cnt_md1_01_START (16)
#define SOC_HiFD_PROP_CFG69_prop_cnt_md1_01_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_02 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_03 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG70_UNION;
#endif
#define SOC_HiFD_PROP_CFG70_prop_cnt_md1_02_START (0)
#define SOC_HiFD_PROP_CFG70_prop_cnt_md1_02_END (9)
#define SOC_HiFD_PROP_CFG70_prop_cnt_md1_03_START (16)
#define SOC_HiFD_PROP_CFG70_prop_cnt_md1_03_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_04 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_05 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG71_UNION;
#endif
#define SOC_HiFD_PROP_CFG71_prop_cnt_md1_04_START (0)
#define SOC_HiFD_PROP_CFG71_prop_cnt_md1_04_END (9)
#define SOC_HiFD_PROP_CFG71_prop_cnt_md1_05_START (16)
#define SOC_HiFD_PROP_CFG71_prop_cnt_md1_05_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_06 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_07 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG72_UNION;
#endif
#define SOC_HiFD_PROP_CFG72_prop_cnt_md1_06_START (0)
#define SOC_HiFD_PROP_CFG72_prop_cnt_md1_06_END (9)
#define SOC_HiFD_PROP_CFG72_prop_cnt_md1_07_START (16)
#define SOC_HiFD_PROP_CFG72_prop_cnt_md1_07_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_08 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_09 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG73_UNION;
#endif
#define SOC_HiFD_PROP_CFG73_prop_cnt_md1_08_START (0)
#define SOC_HiFD_PROP_CFG73_prop_cnt_md1_08_END (9)
#define SOC_HiFD_PROP_CFG73_prop_cnt_md1_09_START (16)
#define SOC_HiFD_PROP_CFG73_prop_cnt_md1_09_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_11 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG74_UNION;
#endif
#define SOC_HiFD_PROP_CFG74_prop_cnt_md1_10_START (0)
#define SOC_HiFD_PROP_CFG74_prop_cnt_md1_10_END (9)
#define SOC_HiFD_PROP_CFG74_prop_cnt_md1_11_START (16)
#define SOC_HiFD_PROP_CFG74_prop_cnt_md1_11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_12 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_13 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG75_UNION;
#endif
#define SOC_HiFD_PROP_CFG75_prop_cnt_md1_12_START (0)
#define SOC_HiFD_PROP_CFG75_prop_cnt_md1_12_END (9)
#define SOC_HiFD_PROP_CFG75_prop_cnt_md1_13_START (16)
#define SOC_HiFD_PROP_CFG75_prop_cnt_md1_13_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prop_cnt_md1_14 : 10;
        unsigned int reserved_0 : 6;
        unsigned int prop_cnt_md1_15 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_HiFD_PROP_CFG76_UNION;
#endif
#define SOC_HiFD_PROP_CFG76_prop_cnt_md1_14_START (0)
#define SOC_HiFD_PROP_CFG76_prop_cnt_md1_14_END (9)
#define SOC_HiFD_PROP_CFG76_prop_cnt_md1_15_START (16)
#define SOC_HiFD_PROP_CFG76_prop_cnt_md1_15_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cls_threshold : 12;
        unsigned int reserved_0 : 4;
        unsigned int params_mc_wait_num : 8;
        unsigned int multi_class_mode_en : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_HiFD_PROP_CFG77_UNION;
#endif
#define SOC_HiFD_PROP_CFG77_cls_threshold_START (0)
#define SOC_HiFD_PROP_CFG77_cls_threshold_END (11)
#define SOC_HiFD_PROP_CFG77_params_mc_wait_num_START (16)
#define SOC_HiFD_PROP_CFG77_params_mc_wait_num_END (23)
#define SOC_HiFD_PROP_CFG77_multi_class_mode_en_START (24)
#define SOC_HiFD_PROP_CFG77_multi_class_mode_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inst_mem : 32;
    } reg;
} SOC_HiFD_INST_MEM_UNION;
#endif
#define SOC_HiFD_INST_MEM_inst_mem_START (0)
#define SOC_HiFD_INST_MEM_inst_mem_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
