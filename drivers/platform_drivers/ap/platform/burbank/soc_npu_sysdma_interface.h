#ifndef __SOC_NPU_SYSDMA_INTERFACE_H__
#define __SOC_NPU_SYSDMA_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_SYSDMA_INT_MASK0_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_SYSDMA_INT_MASK1_ADDR(base) ((base) + (0x0004UL))
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_SYSDMA_INT_CLR0_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_SYSDMA_INT_CLR1_ADDR(base) ((base) + (0x001CUL))
#define SOC_NPU_SYSDMA_MASK_INT0_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_SYSDMA_MASK_INT1_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_SYSDMA_RAW_INT0_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_SYSDMA_RAW_INT1_ADDR(base) ((base) + (0x002CUL))
#define SOC_NPU_SYSDMA_SDMA_CTRL_ADDR(base) ((base) + (0x0030UL))
#define SOC_NPU_SYSDMA_DEBUG_SQE0_ADDR(base) ((base) + (0x0034UL))
#define SOC_NPU_SYSDMA_DEBUG_SQE1_ADDR(base) ((base) + (0x0038UL))
#define SOC_NPU_SYSDMA_DEBUG_SQE2_ADDR(base) ((base) + (0x003CUL))
#define SOC_NPU_SYSDMA_DEBUG_SQE3_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_SYSDMA_DEBUG_SQE4_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_SYSDMA_DEBUG_SQE5_ADDR(base) ((base) + (0x0048UL))
#define SOC_NPU_SYSDMA_DEBUG_SQE6_ADDR(base) ((base) + (0x004CUL))
#define SOC_NPU_SYSDMA_DEBUG_SQE7_ADDR(base) ((base) + (0x0050UL))
#define SOC_NPU_SYSDMA_DMA_STATUS0_ADDR(base) ((base) + (0x0064UL))
#define SOC_NPU_SYSDMA_DMA_STATUS1_ADDR(base) ((base) + (0x0068UL))
#define SOC_NPU_SYSDMA_DMA_STATUS2_ADDR(base) ((base) + (0x006CUL))
#define SOC_NPU_SYSDMA_DMA_STATUS3_ADDR(base) ((base) + (0x0070UL))
#define SOC_NPU_SYSDMA_DMA_STATUS4_ADDR(base) ((base) + (0x0074UL))
#define SOC_NPU_SYSDMA_DMA_STATUS5_ADDR(base) ((base) + (0x0078UL))
#define SOC_NPU_SYSDMA_DMA_STATUS6_ADDR(base) ((base) + (0x007CUL))
#define SOC_NPU_SYSDMA_DMA_STATUS7_ADDR(base) ((base) + (0x0080UL))
#define SOC_NPU_SYSDMA_DMA_STATUS8_ADDR(base) ((base) + (0x0084UL))
#define SOC_NPU_SYSDMA_DMA_STATUS9_ADDR(base) ((base) + (0x0088UL))
#define SOC_NPU_SYSDMA_DMA_STATUS10_ADDR(base) ((base) + (0x008CUL))
#define SOC_NPU_SYSDMA_DMA_STATUS11_ADDR(base) ((base) + (0x0090UL))
#define SOC_NPU_SYSDMA_DMA_STATUS12_ADDR(base) ((base) + (0x0094UL))
#define SOC_NPU_SYSDMA_DMA_STATUS13_ADDR(base) ((base) + (0x0098UL))
#define SOC_NPU_SYSDMA_DMA_STATUS14_ADDR(base) ((base) + (0x009CUL))
#define SOC_NPU_SYSDMA_DMA_STATUS15_ADDR(base) ((base) + (0x00A0UL))
#define SOC_NPU_SYSDMA_DMA_TIMEOUT_TH_ADDR(base) ((base) + (0x00B0UL))
#define SOC_NPU_SYSDMA_CH_CTRL_ADDR(base,m) ((base) + (0x1000+0x40*(m)))
#define SOC_NPU_SYSDMA_STATUS_ADDR(base,m) ((base) + (0x1004+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_SID_ADDR(base,m) ((base) + (0x1008+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_SID_ADDR(base,m) ((base) + (0x100C+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_BASE_H_ADDR(base,m) ((base) + (0x1010+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_BASE_L_ADDR(base,m) ((base) + (0x1014+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_BASE_H_ADDR(base,m) ((base) + (0x1018+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_BASE_L_ADDR(base,m) ((base) + (0x101C+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_WP_ADDR(base,m) ((base) + (0x1020+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_RP_ADDR(base,m) ((base) + (0x1024+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_WP_ADDR(base,m) ((base) + (0x1028+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_RPL_ADDR(base,m) ((base) + (0x102C+0x40*(m)))
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_L_ADDR(base) ((base) + (0x3040UL))
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_H_ADDR(base) ((base) + (0x3044UL))
#define SOC_NPU_SYSDMA_L2_SIZE_ADDR(base) ((base) + (0x3054UL))
#define SOC_NPU_SYSDMA_BIU_CTRL0_ADDR(base) ((base) + (0x3060UL))
#define SOC_NPU_SYSDMA_BIU_CTRL1_ADDR(base) ((base) + (0x3064UL))
#define SOC_NPU_SYSDMA_BIU_CTRL2_ADDR(base) ((base) + (0x3068UL))
#define SOC_NPU_SYSDMA_BIU_CTRL3_ADDR(base) ((base) + (0x306CUL))
#define SOC_NPU_SYSDMA_BIU_CTRL4_ADDR(base) ((base) + (0x3070UL))
#define SOC_NPU_SYSDMA_BIU_CTRL5_ADDR(base) ((base) + (0x3074UL))
#define SOC_NPU_SYSDMA_BIU_STATUS0_ADDR(base) ((base) + (0x3080UL))
#define SOC_NPU_SYSDMA_BIU_STATUS1_ADDR(base) ((base) + (0x3084UL))
#define SOC_NPU_SYSDMA_BIU_STATUS2_ADDR(base) ((base) + (0x3088UL))
#define SOC_NPU_SYSDMA_BIU_STATUS3_ADDR(base) ((base) + (0x308CUL))
#define SOC_NPU_SYSDMA_BIU_STATUS4_ADDR(base) ((base) + (0x3090UL))
#define SOC_NPU_SYSDMA_BIU_STATUS5_ADDR(base) ((base) + (0x3094UL))
#define SOC_NPU_SYSDMA_BIU_STATUS6_ADDR(base) ((base) + (0x3098UL))
#define SOC_NPU_SYSDMA_BIU_STATUS7_ADDR(base) ((base) + (0x309CUL))
#define SOC_NPU_SYSDMA_BIU_STATUS8_ADDR(base) ((base) + (0x30A0UL))
#define SOC_NPU_SYSDMA_BIU_STATUS9_ADDR(base) ((base) + (0x30A4UL))
#define SOC_NPU_SYSDMA_BIU_STATUS10_ADDR(base) ((base) + (0x30A8UL))
#define SOC_NPU_SYSDMA_BIU_STATUS11_ADDR(base) ((base) + (0x30ACUL))
#define SOC_NPU_SYSDMA_BRIF_DBG0_H_ADDR(base) ((base) + (0x3100UL))
#define SOC_NPU_SYSDMA_BRIF_DBG0_L_ADDR(base) ((base) + (0x3104UL))
#define SOC_NPU_SYSDMA_BRIF_DBG1_H_ADDR(base) ((base) + (0x3108UL))
#define SOC_NPU_SYSDMA_BRIF_DBG1_L_ADDR(base) ((base) + (0x310CUL))
#define SOC_NPU_SYSDMA_BRIF_DBG2_H_ADDR(base) ((base) + (0x3110UL))
#define SOC_NPU_SYSDMA_BRIF_DBG2_L_ADDR(base) ((base) + (0x3114UL))
#define SOC_NPU_SYSDMA_BRIF_DBG3_H_ADDR(base) ((base) + (0x3118UL))
#define SOC_NPU_SYSDMA_BRIF_DBG3_L_ADDR(base) ((base) + (0x311CUL))
#define SOC_NPU_SYSDMA_BWIF_DBG0_H_ADDR(base) ((base) + (0x3120UL))
#define SOC_NPU_SYSDMA_BWIF_DBG0_L_ADDR(base) ((base) + (0x3124UL))
#define SOC_NPU_SYSDMA_BWIF_DBG1_H_ADDR(base) ((base) + (0x3128UL))
#define SOC_NPU_SYSDMA_BWIF_DBG1_L_ADDR(base) ((base) + (0x312CUL))
#define SOC_NPU_SYSDMA_BWIF_DBG2_H_ADDR(base) ((base) + (0x3130UL))
#define SOC_NPU_SYSDMA_BWIF_DBG2_L_ADDR(base) ((base) + (0x3134UL))
#define SOC_NPU_SYSDMA_BWIF_DBG3_H_ADDR(base) ((base) + (0x3138UL))
#define SOC_NPU_SYSDMA_BWIF_DBG3_L_ADDR(base) ((base) + (0x313CUL))
#define SOC_NPU_SYSDMA_BRIF_RETIRE_CNT_ADDR(base) ((base) + (0x3140UL))
#define SOC_NPU_SYSDMA_BWIF_RETIRE_CNT_ADDR(base) ((base) + (0x3144UL))
#define SOC_NPU_SYSDMA_SQE_RD_REQ_CNT_ADDR(base) ((base) + (0x3148UL))
#define SOC_NPU_SYSDMA_SQE_RD_RSP_CNT_ADDR(base) ((base) + (0x314CUL))
#define SOC_NPU_SYSDMA_CQE_WR_REQ_CNT_ADDR(base) ((base) + (0x3150UL))
#define SOC_NPU_SYSDMA_CQE_WR_RSP_CNT_ADDR(base) ((base) + (0x3154UL))
#define SOC_NPU_SYSDMA_BLK_RD_REQ_CNT_ADDR(base) ((base) + (0x3158UL))
#define SOC_NPU_SYSDMA_BLK_WR_REQ_CNT_ADDR(base) ((base) + (0x315CUL))
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ADDR(base) ((base) + (0x3160UL))
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_ADDR(base) ((base) + (0x3164UL))
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_ADDR(base) ((base) + (0x3168UL))
#define SOC_NPU_SYSDMA_WR_USE_CNT_ADDR(base) ((base) + (0x316CUL))
#else
#define SOC_NPU_SYSDMA_INT_MASK0_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_SYSDMA_INT_MASK1_ADDR(base) ((base) + (0x0004))
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_SYSDMA_INT_CLR0_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_SYSDMA_INT_CLR1_ADDR(base) ((base) + (0x001C))
#define SOC_NPU_SYSDMA_MASK_INT0_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_SYSDMA_MASK_INT1_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_SYSDMA_RAW_INT0_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_SYSDMA_RAW_INT1_ADDR(base) ((base) + (0x002C))
#define SOC_NPU_SYSDMA_SDMA_CTRL_ADDR(base) ((base) + (0x0030))
#define SOC_NPU_SYSDMA_DEBUG_SQE0_ADDR(base) ((base) + (0x0034))
#define SOC_NPU_SYSDMA_DEBUG_SQE1_ADDR(base) ((base) + (0x0038))
#define SOC_NPU_SYSDMA_DEBUG_SQE2_ADDR(base) ((base) + (0x003C))
#define SOC_NPU_SYSDMA_DEBUG_SQE3_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_SYSDMA_DEBUG_SQE4_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_SYSDMA_DEBUG_SQE5_ADDR(base) ((base) + (0x0048))
#define SOC_NPU_SYSDMA_DEBUG_SQE6_ADDR(base) ((base) + (0x004C))
#define SOC_NPU_SYSDMA_DEBUG_SQE7_ADDR(base) ((base) + (0x0050))
#define SOC_NPU_SYSDMA_DMA_STATUS0_ADDR(base) ((base) + (0x0064))
#define SOC_NPU_SYSDMA_DMA_STATUS1_ADDR(base) ((base) + (0x0068))
#define SOC_NPU_SYSDMA_DMA_STATUS2_ADDR(base) ((base) + (0x006C))
#define SOC_NPU_SYSDMA_DMA_STATUS3_ADDR(base) ((base) + (0x0070))
#define SOC_NPU_SYSDMA_DMA_STATUS4_ADDR(base) ((base) + (0x0074))
#define SOC_NPU_SYSDMA_DMA_STATUS5_ADDR(base) ((base) + (0x0078))
#define SOC_NPU_SYSDMA_DMA_STATUS6_ADDR(base) ((base) + (0x007C))
#define SOC_NPU_SYSDMA_DMA_STATUS7_ADDR(base) ((base) + (0x0080))
#define SOC_NPU_SYSDMA_DMA_STATUS8_ADDR(base) ((base) + (0x0084))
#define SOC_NPU_SYSDMA_DMA_STATUS9_ADDR(base) ((base) + (0x0088))
#define SOC_NPU_SYSDMA_DMA_STATUS10_ADDR(base) ((base) + (0x008C))
#define SOC_NPU_SYSDMA_DMA_STATUS11_ADDR(base) ((base) + (0x0090))
#define SOC_NPU_SYSDMA_DMA_STATUS12_ADDR(base) ((base) + (0x0094))
#define SOC_NPU_SYSDMA_DMA_STATUS13_ADDR(base) ((base) + (0x0098))
#define SOC_NPU_SYSDMA_DMA_STATUS14_ADDR(base) ((base) + (0x009C))
#define SOC_NPU_SYSDMA_DMA_STATUS15_ADDR(base) ((base) + (0x00A0))
#define SOC_NPU_SYSDMA_DMA_TIMEOUT_TH_ADDR(base) ((base) + (0x00B0))
#define SOC_NPU_SYSDMA_CH_CTRL_ADDR(base,m) ((base) + (0x1000+0x40*(m)))
#define SOC_NPU_SYSDMA_STATUS_ADDR(base,m) ((base) + (0x1004+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_SID_ADDR(base,m) ((base) + (0x1008+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_SID_ADDR(base,m) ((base) + (0x100C+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_BASE_H_ADDR(base,m) ((base) + (0x1010+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_BASE_L_ADDR(base,m) ((base) + (0x1014+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_BASE_H_ADDR(base,m) ((base) + (0x1018+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_BASE_L_ADDR(base,m) ((base) + (0x101C+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_WP_ADDR(base,m) ((base) + (0x1020+0x40*(m)))
#define SOC_NPU_SYSDMA_SQ_RP_ADDR(base,m) ((base) + (0x1024+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_WP_ADDR(base,m) ((base) + (0x1028+0x40*(m)))
#define SOC_NPU_SYSDMA_CQ_RPL_ADDR(base,m) ((base) + (0x102C+0x40*(m)))
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_L_ADDR(base) ((base) + (0x3040))
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_H_ADDR(base) ((base) + (0x3044))
#define SOC_NPU_SYSDMA_L2_SIZE_ADDR(base) ((base) + (0x3054))
#define SOC_NPU_SYSDMA_BIU_CTRL0_ADDR(base) ((base) + (0x3060))
#define SOC_NPU_SYSDMA_BIU_CTRL1_ADDR(base) ((base) + (0x3064))
#define SOC_NPU_SYSDMA_BIU_CTRL2_ADDR(base) ((base) + (0x3068))
#define SOC_NPU_SYSDMA_BIU_CTRL3_ADDR(base) ((base) + (0x306C))
#define SOC_NPU_SYSDMA_BIU_CTRL4_ADDR(base) ((base) + (0x3070))
#define SOC_NPU_SYSDMA_BIU_CTRL5_ADDR(base) ((base) + (0x3074))
#define SOC_NPU_SYSDMA_BIU_STATUS0_ADDR(base) ((base) + (0x3080))
#define SOC_NPU_SYSDMA_BIU_STATUS1_ADDR(base) ((base) + (0x3084))
#define SOC_NPU_SYSDMA_BIU_STATUS2_ADDR(base) ((base) + (0x3088))
#define SOC_NPU_SYSDMA_BIU_STATUS3_ADDR(base) ((base) + (0x308C))
#define SOC_NPU_SYSDMA_BIU_STATUS4_ADDR(base) ((base) + (0x3090))
#define SOC_NPU_SYSDMA_BIU_STATUS5_ADDR(base) ((base) + (0x3094))
#define SOC_NPU_SYSDMA_BIU_STATUS6_ADDR(base) ((base) + (0x3098))
#define SOC_NPU_SYSDMA_BIU_STATUS7_ADDR(base) ((base) + (0x309C))
#define SOC_NPU_SYSDMA_BIU_STATUS8_ADDR(base) ((base) + (0x30A0))
#define SOC_NPU_SYSDMA_BIU_STATUS9_ADDR(base) ((base) + (0x30A4))
#define SOC_NPU_SYSDMA_BIU_STATUS10_ADDR(base) ((base) + (0x30A8))
#define SOC_NPU_SYSDMA_BIU_STATUS11_ADDR(base) ((base) + (0x30AC))
#define SOC_NPU_SYSDMA_BRIF_DBG0_H_ADDR(base) ((base) + (0x3100))
#define SOC_NPU_SYSDMA_BRIF_DBG0_L_ADDR(base) ((base) + (0x3104))
#define SOC_NPU_SYSDMA_BRIF_DBG1_H_ADDR(base) ((base) + (0x3108))
#define SOC_NPU_SYSDMA_BRIF_DBG1_L_ADDR(base) ((base) + (0x310C))
#define SOC_NPU_SYSDMA_BRIF_DBG2_H_ADDR(base) ((base) + (0x3110))
#define SOC_NPU_SYSDMA_BRIF_DBG2_L_ADDR(base) ((base) + (0x3114))
#define SOC_NPU_SYSDMA_BRIF_DBG3_H_ADDR(base) ((base) + (0x3118))
#define SOC_NPU_SYSDMA_BRIF_DBG3_L_ADDR(base) ((base) + (0x311C))
#define SOC_NPU_SYSDMA_BWIF_DBG0_H_ADDR(base) ((base) + (0x3120))
#define SOC_NPU_SYSDMA_BWIF_DBG0_L_ADDR(base) ((base) + (0x3124))
#define SOC_NPU_SYSDMA_BWIF_DBG1_H_ADDR(base) ((base) + (0x3128))
#define SOC_NPU_SYSDMA_BWIF_DBG1_L_ADDR(base) ((base) + (0x312C))
#define SOC_NPU_SYSDMA_BWIF_DBG2_H_ADDR(base) ((base) + (0x3130))
#define SOC_NPU_SYSDMA_BWIF_DBG2_L_ADDR(base) ((base) + (0x3134))
#define SOC_NPU_SYSDMA_BWIF_DBG3_H_ADDR(base) ((base) + (0x3138))
#define SOC_NPU_SYSDMA_BWIF_DBG3_L_ADDR(base) ((base) + (0x313C))
#define SOC_NPU_SYSDMA_BRIF_RETIRE_CNT_ADDR(base) ((base) + (0x3140))
#define SOC_NPU_SYSDMA_BWIF_RETIRE_CNT_ADDR(base) ((base) + (0x3144))
#define SOC_NPU_SYSDMA_SQE_RD_REQ_CNT_ADDR(base) ((base) + (0x3148))
#define SOC_NPU_SYSDMA_SQE_RD_RSP_CNT_ADDR(base) ((base) + (0x314C))
#define SOC_NPU_SYSDMA_CQE_WR_REQ_CNT_ADDR(base) ((base) + (0x3150))
#define SOC_NPU_SYSDMA_CQE_WR_RSP_CNT_ADDR(base) ((base) + (0x3154))
#define SOC_NPU_SYSDMA_BLK_RD_REQ_CNT_ADDR(base) ((base) + (0x3158))
#define SOC_NPU_SYSDMA_BLK_WR_REQ_CNT_ADDR(base) ((base) + (0x315C))
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ADDR(base) ((base) + (0x3160))
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_ADDR(base) ((base) + (0x3164))
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_ADDR(base) ((base) + (0x3168))
#define SOC_NPU_SYSDMA_WR_USE_CNT_ADDR(base) ((base) + (0x316C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_done_mask : 1;
        unsigned int ch0_data_r_err_mask : 1;
        unsigned int ch0_data_w_err_mask : 1;
        unsigned int ch0_sq_r_err_mask : 1;
        unsigned int ch0_cq_w_err_mask : 1;
        unsigned int ch0_tout_err_mask : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch1_done_mask : 1;
        unsigned int ch1_data_r_err_mask : 1;
        unsigned int ch1_data_w_err_mask : 1;
        unsigned int ch1_sq_r_err_mask : 1;
        unsigned int ch1_cq_w_err_mask : 1;
        unsigned int ch1_tout_err_mask : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch2_done_mask : 1;
        unsigned int ch2_data_r_err_mask : 1;
        unsigned int ch2_data_w_err_mask : 1;
        unsigned int ch2_sq_r_err_mask : 1;
        unsigned int ch2_cq_w_err_mask : 1;
        unsigned int ch2_tout_err_mask : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch3_done_mask : 1;
        unsigned int ch3_data_r_err_mask : 1;
        unsigned int ch3_data_w_err_mask : 1;
        unsigned int ch3_sq_r_err_mask : 1;
        unsigned int ch3_cq_w_err_mask : 1;
        unsigned int ch3_tout_err_mask : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_MASK0_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_done_mask_START (0)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_done_mask_END (0)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_data_r_err_mask_START (1)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_data_r_err_mask_END (1)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_data_w_err_mask_START (2)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_data_w_err_mask_END (2)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_sq_r_err_mask_START (3)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_sq_r_err_mask_END (3)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_cq_w_err_mask_START (4)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_cq_w_err_mask_END (4)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_tout_err_mask_START (5)
#define SOC_NPU_SYSDMA_INT_MASK0_ch0_tout_err_mask_END (5)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_done_mask_START (8)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_done_mask_END (8)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_data_r_err_mask_START (9)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_data_r_err_mask_END (9)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_data_w_err_mask_START (10)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_data_w_err_mask_END (10)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_sq_r_err_mask_START (11)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_sq_r_err_mask_END (11)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_cq_w_err_mask_START (12)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_cq_w_err_mask_END (12)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_tout_err_mask_START (13)
#define SOC_NPU_SYSDMA_INT_MASK0_ch1_tout_err_mask_END (13)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_done_mask_START (16)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_done_mask_END (16)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_data_r_err_mask_START (17)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_data_r_err_mask_END (17)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_data_w_err_mask_START (18)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_data_w_err_mask_END (18)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_sq_r_err_mask_START (19)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_sq_r_err_mask_END (19)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_cq_w_err_mask_START (20)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_cq_w_err_mask_END (20)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_tout_err_mask_START (21)
#define SOC_NPU_SYSDMA_INT_MASK0_ch2_tout_err_mask_END (21)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_done_mask_START (24)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_done_mask_END (24)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_data_r_err_mask_START (25)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_data_r_err_mask_END (25)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_data_w_err_mask_START (26)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_data_w_err_mask_END (26)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_sq_r_err_mask_START (27)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_sq_r_err_mask_END (27)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_cq_w_err_mask_START (28)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_cq_w_err_mask_END (28)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_tout_err_mask_START (29)
#define SOC_NPU_SYSDMA_INT_MASK0_ch3_tout_err_mask_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_done_mask : 1;
        unsigned int ch4_data_r_err_mask : 1;
        unsigned int ch4_data_w_err_mask : 1;
        unsigned int ch4_sq_r_err_mask : 1;
        unsigned int ch4_cq_w_err_mask : 1;
        unsigned int ch4_tout_err_mask : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch5_done_mask : 1;
        unsigned int ch5_data_r_err_mask : 1;
        unsigned int ch5_data_w_err_mask : 1;
        unsigned int ch5_sq_r_err_mask : 1;
        unsigned int ch5_cq_w_err_mask : 1;
        unsigned int ch5_tout_err_mask : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch6_done_mask : 1;
        unsigned int ch6_data_r_err_mask : 1;
        unsigned int ch6_data_w_err_mask : 1;
        unsigned int ch6_sq_r_err_mask : 1;
        unsigned int ch6_cq_w_err_mask : 1;
        unsigned int ch6_tout_err_mask : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch7_done_mask : 1;
        unsigned int ch7_data_r_err_mask : 1;
        unsigned int ch7_data_w_err_mask : 1;
        unsigned int ch7_sq_r_err_mask : 1;
        unsigned int ch7_cq_w_err_mask : 1;
        unsigned int ch7_tout_err_mask : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_MASK1_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_done_mask_START (0)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_done_mask_END (0)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_data_r_err_mask_START (1)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_data_r_err_mask_END (1)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_data_w_err_mask_START (2)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_data_w_err_mask_END (2)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_sq_r_err_mask_START (3)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_sq_r_err_mask_END (3)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_cq_w_err_mask_START (4)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_cq_w_err_mask_END (4)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_tout_err_mask_START (5)
#define SOC_NPU_SYSDMA_INT_MASK1_ch4_tout_err_mask_END (5)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_done_mask_START (8)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_done_mask_END (8)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_data_r_err_mask_START (9)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_data_r_err_mask_END (9)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_data_w_err_mask_START (10)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_data_w_err_mask_END (10)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_sq_r_err_mask_START (11)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_sq_r_err_mask_END (11)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_cq_w_err_mask_START (12)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_cq_w_err_mask_END (12)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_tout_err_mask_START (13)
#define SOC_NPU_SYSDMA_INT_MASK1_ch5_tout_err_mask_END (13)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_done_mask_START (16)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_done_mask_END (16)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_data_r_err_mask_START (17)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_data_r_err_mask_END (17)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_data_w_err_mask_START (18)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_data_w_err_mask_END (18)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_sq_r_err_mask_START (19)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_sq_r_err_mask_END (19)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_cq_w_err_mask_START (20)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_cq_w_err_mask_END (20)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_tout_err_mask_START (21)
#define SOC_NPU_SYSDMA_INT_MASK1_ch6_tout_err_mask_END (21)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_done_mask_START (24)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_done_mask_END (24)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_data_r_err_mask_START (25)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_data_r_err_mask_END (25)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_data_w_err_mask_START (26)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_data_w_err_mask_END (26)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_sq_r_err_mask_START (27)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_sq_r_err_mask_END (27)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_cq_w_err_mask_START (28)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_cq_w_err_mask_END (28)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_tout_err_mask_START (29)
#define SOC_NPU_SYSDMA_INT_MASK1_ch7_tout_err_mask_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_done_mask_dis : 1;
        unsigned int ch0_data_r_err_mask_dis : 1;
        unsigned int ch0_data_w_err_mask_dis : 1;
        unsigned int ch0_sq_r_err_mask_dis : 1;
        unsigned int ch0_cq_w_err_mask_dis : 1;
        unsigned int ch0_tout_err_mask_dis : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch1_done_mask_dis : 1;
        unsigned int ch1_data_r_err_mask_dis : 1;
        unsigned int ch1_data_w_err_mask_dis : 1;
        unsigned int ch1_sq_r_err_mask_dis : 1;
        unsigned int ch1_cq_w_err_mask_dis : 1;
        unsigned int ch1_tout_err_mask_dis : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch2_done_mask_dis : 1;
        unsigned int ch2_data_r_err_mask_dis : 1;
        unsigned int ch2_data_w_err_mask_dis : 1;
        unsigned int ch2_sq_r_err_mask_dis : 1;
        unsigned int ch2_cq_w_err_mask_dis : 1;
        unsigned int ch2_tout_err_mask_dis : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch3_done_mask_dis : 1;
        unsigned int ch3_data_r_err_mask_dis : 1;
        unsigned int ch3_data_w_err_mask_dis : 1;
        unsigned int ch3_sq_r_err_mask_dis : 1;
        unsigned int ch3_cq_w_err_mask_dis : 1;
        unsigned int ch3_tout_err_mask_dis : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_MASK_DIS0_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_done_mask_dis_START (0)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_done_mask_dis_END (0)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_data_r_err_mask_dis_START (1)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_data_r_err_mask_dis_END (1)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_data_w_err_mask_dis_START (2)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_data_w_err_mask_dis_END (2)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_sq_r_err_mask_dis_START (3)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_sq_r_err_mask_dis_END (3)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_cq_w_err_mask_dis_START (4)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_cq_w_err_mask_dis_END (4)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_tout_err_mask_dis_START (5)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch0_tout_err_mask_dis_END (5)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_done_mask_dis_START (8)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_done_mask_dis_END (8)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_data_r_err_mask_dis_START (9)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_data_r_err_mask_dis_END (9)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_data_w_err_mask_dis_START (10)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_data_w_err_mask_dis_END (10)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_sq_r_err_mask_dis_START (11)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_sq_r_err_mask_dis_END (11)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_cq_w_err_mask_dis_START (12)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_cq_w_err_mask_dis_END (12)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_tout_err_mask_dis_START (13)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch1_tout_err_mask_dis_END (13)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_done_mask_dis_START (16)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_done_mask_dis_END (16)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_data_r_err_mask_dis_START (17)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_data_r_err_mask_dis_END (17)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_data_w_err_mask_dis_START (18)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_data_w_err_mask_dis_END (18)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_sq_r_err_mask_dis_START (19)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_sq_r_err_mask_dis_END (19)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_cq_w_err_mask_dis_START (20)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_cq_w_err_mask_dis_END (20)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_tout_err_mask_dis_START (21)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch2_tout_err_mask_dis_END (21)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_done_mask_dis_START (24)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_done_mask_dis_END (24)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_data_r_err_mask_dis_START (25)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_data_r_err_mask_dis_END (25)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_data_w_err_mask_dis_START (26)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_data_w_err_mask_dis_END (26)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_sq_r_err_mask_dis_START (27)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_sq_r_err_mask_dis_END (27)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_cq_w_err_mask_dis_START (28)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_cq_w_err_mask_dis_END (28)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_tout_err_mask_dis_START (29)
#define SOC_NPU_SYSDMA_INT_MASK_DIS0_ch3_tout_err_mask_dis_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_done_mask_dis : 1;
        unsigned int ch4_data_r_err_mask_dis : 1;
        unsigned int ch4_data_w_err_mask_dis : 1;
        unsigned int ch4_sq_r_err_mask_dis : 1;
        unsigned int ch4_cq_w_err_mask_dis : 1;
        unsigned int ch4_tout_err_mask_dis : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch5_done_mask_dis : 1;
        unsigned int ch5_data_r_err_mask_dis : 1;
        unsigned int ch5_data_w_err_mask_dis : 1;
        unsigned int ch5_sq_r_err_mask_dis : 1;
        unsigned int ch5_cq_w_err_mask_dis : 1;
        unsigned int ch5_tout_err_mask_dis : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch6_done_mask_dis : 1;
        unsigned int ch6_data_r_err_mask_dis : 1;
        unsigned int ch6_data_w_err_mask_dis : 1;
        unsigned int ch6_sq_r_err_mask_dis : 1;
        unsigned int ch6_cq_w_err_mask_dis : 1;
        unsigned int ch6_tout_err_mask_dis : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch7_done_mask_dis : 1;
        unsigned int ch7_data_r_err_mask_dis : 1;
        unsigned int ch7_data_w_err_mask_dis : 1;
        unsigned int ch7_sq_r_err_mask_dis : 1;
        unsigned int ch7_cq_w_err_mask_dis : 1;
        unsigned int ch7_tout_err_mask_dis : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_MASK_DIS1_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_done_mask_dis_START (0)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_done_mask_dis_END (0)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_data_r_err_mask_dis_START (1)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_data_r_err_mask_dis_END (1)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_data_w_err_mask_dis_START (2)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_data_w_err_mask_dis_END (2)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_sq_r_err_mask_dis_START (3)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_sq_r_err_mask_dis_END (3)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_cq_w_err_mask_dis_START (4)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_cq_w_err_mask_dis_END (4)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_tout_err_mask_dis_START (5)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch4_tout_err_mask_dis_END (5)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_done_mask_dis_START (8)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_done_mask_dis_END (8)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_data_r_err_mask_dis_START (9)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_data_r_err_mask_dis_END (9)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_data_w_err_mask_dis_START (10)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_data_w_err_mask_dis_END (10)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_sq_r_err_mask_dis_START (11)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_sq_r_err_mask_dis_END (11)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_cq_w_err_mask_dis_START (12)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_cq_w_err_mask_dis_END (12)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_tout_err_mask_dis_START (13)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch5_tout_err_mask_dis_END (13)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_done_mask_dis_START (16)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_done_mask_dis_END (16)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_data_r_err_mask_dis_START (17)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_data_r_err_mask_dis_END (17)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_data_w_err_mask_dis_START (18)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_data_w_err_mask_dis_END (18)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_sq_r_err_mask_dis_START (19)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_sq_r_err_mask_dis_END (19)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_cq_w_err_mask_dis_START (20)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_cq_w_err_mask_dis_END (20)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_tout_err_mask_dis_START (21)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch6_tout_err_mask_dis_END (21)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_done_mask_dis_START (24)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_done_mask_dis_END (24)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_data_r_err_mask_dis_START (25)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_data_r_err_mask_dis_END (25)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_data_w_err_mask_dis_START (26)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_data_w_err_mask_dis_END (26)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_sq_r_err_mask_dis_START (27)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_sq_r_err_mask_dis_END (27)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_cq_w_err_mask_dis_START (28)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_cq_w_err_mask_dis_END (28)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_tout_err_mask_dis_START (29)
#define SOC_NPU_SYSDMA_INT_MASK_DIS1_ch7_tout_err_mask_dis_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_done_mask_val : 1;
        unsigned int ch0_data_r_err_mask_val : 1;
        unsigned int ch0_data_w_err_mask_val : 1;
        unsigned int ch0_sq_r_err_mask_val : 1;
        unsigned int ch0_cq_w_err_mask_val : 1;
        unsigned int ch0_tout_err_mask_val : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch1_done_mask_val : 1;
        unsigned int ch1_data_r_err_mask_val : 1;
        unsigned int ch1_data_w_err_mask_val : 1;
        unsigned int ch1_sq_r_err_mask_val : 1;
        unsigned int ch1_cq_w_err_mask_val : 1;
        unsigned int ch1_tout_err_mask_val : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch2_done_mask_val : 1;
        unsigned int ch2_data_r_err_mask_val : 1;
        unsigned int ch2_data_w_err_mask_val : 1;
        unsigned int ch2_sq_r_err_mask_val : 1;
        unsigned int ch2_cq_w_err_mask_val : 1;
        unsigned int ch2_tout_err_mask_val : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch3_done_mask_val : 1;
        unsigned int ch3_data_r_err_mask_val : 1;
        unsigned int ch3_data_w_err_mask_val : 1;
        unsigned int ch3_sq_r_err_mask_val : 1;
        unsigned int ch3_cq_w_err_mask_val : 1;
        unsigned int ch3_tout_err_mask_val : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_MASK_VAL0_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_done_mask_val_START (0)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_done_mask_val_END (0)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_data_r_err_mask_val_START (1)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_data_r_err_mask_val_END (1)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_data_w_err_mask_val_START (2)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_data_w_err_mask_val_END (2)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_sq_r_err_mask_val_START (3)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_sq_r_err_mask_val_END (3)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_cq_w_err_mask_val_START (4)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_cq_w_err_mask_val_END (4)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_tout_err_mask_val_START (5)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch0_tout_err_mask_val_END (5)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_done_mask_val_START (8)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_done_mask_val_END (8)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_data_r_err_mask_val_START (9)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_data_r_err_mask_val_END (9)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_data_w_err_mask_val_START (10)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_data_w_err_mask_val_END (10)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_sq_r_err_mask_val_START (11)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_sq_r_err_mask_val_END (11)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_cq_w_err_mask_val_START (12)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_cq_w_err_mask_val_END (12)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_tout_err_mask_val_START (13)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch1_tout_err_mask_val_END (13)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_done_mask_val_START (16)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_done_mask_val_END (16)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_data_r_err_mask_val_START (17)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_data_r_err_mask_val_END (17)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_data_w_err_mask_val_START (18)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_data_w_err_mask_val_END (18)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_sq_r_err_mask_val_START (19)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_sq_r_err_mask_val_END (19)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_cq_w_err_mask_val_START (20)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_cq_w_err_mask_val_END (20)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_tout_err_mask_val_START (21)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch2_tout_err_mask_val_END (21)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_done_mask_val_START (24)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_done_mask_val_END (24)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_data_r_err_mask_val_START (25)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_data_r_err_mask_val_END (25)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_data_w_err_mask_val_START (26)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_data_w_err_mask_val_END (26)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_sq_r_err_mask_val_START (27)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_sq_r_err_mask_val_END (27)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_cq_w_err_mask_val_START (28)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_cq_w_err_mask_val_END (28)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_tout_err_mask_val_START (29)
#define SOC_NPU_SYSDMA_INT_MASK_VAL0_ch3_tout_err_mask_val_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_done_mask_val : 1;
        unsigned int ch4_data_r_err_mask_val : 1;
        unsigned int ch4_data_w_err_mask_val : 1;
        unsigned int ch4_sq_r_err_mask_val : 1;
        unsigned int ch4_cq_w_err_mask_val : 1;
        unsigned int ch4_tout_err_mask_val : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch5_done_mask_val : 1;
        unsigned int ch5_data_r_err_mask_val : 1;
        unsigned int ch5_data_w_err_mask_val : 1;
        unsigned int ch5_sq_r_err_mask_val : 1;
        unsigned int ch5_cq_w_err_mask_val : 1;
        unsigned int ch5_tout_err_mask_val : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch6_done_mask_val : 1;
        unsigned int ch6_data_r_err_mask_val : 1;
        unsigned int ch6_data_w_err_mask_val : 1;
        unsigned int ch6_sq_r_err_mask_val : 1;
        unsigned int ch6_cq_w_err_mask_val : 1;
        unsigned int ch6_tout_err_mask_val : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch7_done_mask_val : 1;
        unsigned int ch7_data_r_err_mask_val : 1;
        unsigned int ch7_data_w_err_mask_val : 1;
        unsigned int ch7_sq_r_err_mask_val : 1;
        unsigned int ch7_cq_w_err_mask_val : 1;
        unsigned int ch7_tout_err_mask_val : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_MASK_VAL1_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_done_mask_val_START (0)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_done_mask_val_END (0)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_data_r_err_mask_val_START (1)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_data_r_err_mask_val_END (1)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_data_w_err_mask_val_START (2)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_data_w_err_mask_val_END (2)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_sq_r_err_mask_val_START (3)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_sq_r_err_mask_val_END (3)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_cq_w_err_mask_val_START (4)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_cq_w_err_mask_val_END (4)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_tout_err_mask_val_START (5)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch4_tout_err_mask_val_END (5)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_done_mask_val_START (8)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_done_mask_val_END (8)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_data_r_err_mask_val_START (9)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_data_r_err_mask_val_END (9)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_data_w_err_mask_val_START (10)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_data_w_err_mask_val_END (10)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_sq_r_err_mask_val_START (11)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_sq_r_err_mask_val_END (11)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_cq_w_err_mask_val_START (12)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_cq_w_err_mask_val_END (12)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_tout_err_mask_val_START (13)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch5_tout_err_mask_val_END (13)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_done_mask_val_START (16)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_done_mask_val_END (16)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_data_r_err_mask_val_START (17)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_data_r_err_mask_val_END (17)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_data_w_err_mask_val_START (18)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_data_w_err_mask_val_END (18)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_sq_r_err_mask_val_START (19)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_sq_r_err_mask_val_END (19)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_cq_w_err_mask_val_START (20)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_cq_w_err_mask_val_END (20)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_tout_err_mask_val_START (21)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch6_tout_err_mask_val_END (21)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_done_mask_val_START (24)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_done_mask_val_END (24)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_data_r_err_mask_val_START (25)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_data_r_err_mask_val_END (25)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_data_w_err_mask_val_START (26)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_data_w_err_mask_val_END (26)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_sq_r_err_mask_val_START (27)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_sq_r_err_mask_val_END (27)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_cq_w_err_mask_val_START (28)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_cq_w_err_mask_val_END (28)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_tout_err_mask_val_START (29)
#define SOC_NPU_SYSDMA_INT_MASK_VAL1_ch7_tout_err_mask_val_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_done_clr : 1;
        unsigned int ch0_data_r_err_clr : 1;
        unsigned int ch0_data_w_err_clr : 1;
        unsigned int ch0_sq_r_err_clr : 1;
        unsigned int ch0_cq_w_err_clr : 1;
        unsigned int ch0_tout_err_clr : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch1_done_clr : 1;
        unsigned int ch1_data_r_err_clr : 1;
        unsigned int ch1_data_w_err_clr : 1;
        unsigned int ch1_sq_r_err_clr : 1;
        unsigned int ch1_cq_w_err_clr : 1;
        unsigned int ch1_tout_err_clr : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch2_done_clr : 1;
        unsigned int ch2_data_r_err_clr : 1;
        unsigned int ch2_data_w_err_clr : 1;
        unsigned int ch2_sq_r_err_clr : 1;
        unsigned int ch2_cq_w_err_clr : 1;
        unsigned int ch2_tout_err_clr : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch3_done_clr : 1;
        unsigned int ch3_data_r_err_clr : 1;
        unsigned int ch3_data_w_err_clr : 1;
        unsigned int ch3_sq_r_err_clr : 1;
        unsigned int ch3_cq_w_err_clr : 1;
        unsigned int ch3_tout_err_clr : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_CLR0_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_done_clr_START (0)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_done_clr_END (0)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_data_r_err_clr_START (1)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_data_r_err_clr_END (1)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_data_w_err_clr_START (2)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_data_w_err_clr_END (2)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_sq_r_err_clr_START (3)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_sq_r_err_clr_END (3)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_cq_w_err_clr_START (4)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_cq_w_err_clr_END (4)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_tout_err_clr_START (5)
#define SOC_NPU_SYSDMA_INT_CLR0_ch0_tout_err_clr_END (5)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_done_clr_START (8)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_done_clr_END (8)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_data_r_err_clr_START (9)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_data_r_err_clr_END (9)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_data_w_err_clr_START (10)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_data_w_err_clr_END (10)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_sq_r_err_clr_START (11)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_sq_r_err_clr_END (11)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_cq_w_err_clr_START (12)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_cq_w_err_clr_END (12)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_tout_err_clr_START (13)
#define SOC_NPU_SYSDMA_INT_CLR0_ch1_tout_err_clr_END (13)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_done_clr_START (16)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_done_clr_END (16)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_data_r_err_clr_START (17)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_data_r_err_clr_END (17)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_data_w_err_clr_START (18)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_data_w_err_clr_END (18)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_sq_r_err_clr_START (19)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_sq_r_err_clr_END (19)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_cq_w_err_clr_START (20)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_cq_w_err_clr_END (20)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_tout_err_clr_START (21)
#define SOC_NPU_SYSDMA_INT_CLR0_ch2_tout_err_clr_END (21)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_done_clr_START (24)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_done_clr_END (24)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_data_r_err_clr_START (25)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_data_r_err_clr_END (25)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_data_w_err_clr_START (26)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_data_w_err_clr_END (26)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_sq_r_err_clr_START (27)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_sq_r_err_clr_END (27)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_cq_w_err_clr_START (28)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_cq_w_err_clr_END (28)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_tout_err_clr_START (29)
#define SOC_NPU_SYSDMA_INT_CLR0_ch3_tout_err_clr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_done_clr : 1;
        unsigned int ch4_data_r_err_clr : 1;
        unsigned int ch4_data_w_err_clr : 1;
        unsigned int ch4_sq_r_err_clr : 1;
        unsigned int ch4_cq_w_err_clr : 1;
        unsigned int ch4_tout_err_clr : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch5_done_clr : 1;
        unsigned int ch5_data_r_err_clr : 1;
        unsigned int ch5_data_w_err_clr : 1;
        unsigned int ch5_sq_r_err_clr : 1;
        unsigned int ch5_cq_w_err_clr : 1;
        unsigned int ch5_tout_err_clr : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch6_done_clr : 1;
        unsigned int ch6_data_r_err_clr : 1;
        unsigned int ch6_data_w_err_clr : 1;
        unsigned int ch6_sq_r_err_clr : 1;
        unsigned int ch6_cq_w_err_clr : 1;
        unsigned int ch6_tout_err_clr : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch7_done_clr : 1;
        unsigned int ch7_data_r_err_clr : 1;
        unsigned int ch7_data_w_err_clr : 1;
        unsigned int ch7_sq_r_err_clr : 1;
        unsigned int ch7_cq_w_err_clr : 1;
        unsigned int ch7_tout_err_clr : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_INT_CLR1_UNION;
#endif
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_done_clr_START (0)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_done_clr_END (0)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_data_r_err_clr_START (1)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_data_r_err_clr_END (1)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_data_w_err_clr_START (2)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_data_w_err_clr_END (2)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_sq_r_err_clr_START (3)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_sq_r_err_clr_END (3)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_cq_w_err_clr_START (4)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_cq_w_err_clr_END (4)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_tout_err_clr_START (5)
#define SOC_NPU_SYSDMA_INT_CLR1_ch4_tout_err_clr_END (5)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_done_clr_START (8)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_done_clr_END (8)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_data_r_err_clr_START (9)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_data_r_err_clr_END (9)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_data_w_err_clr_START (10)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_data_w_err_clr_END (10)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_sq_r_err_clr_START (11)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_sq_r_err_clr_END (11)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_cq_w_err_clr_START (12)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_cq_w_err_clr_END (12)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_tout_err_clr_START (13)
#define SOC_NPU_SYSDMA_INT_CLR1_ch5_tout_err_clr_END (13)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_done_clr_START (16)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_done_clr_END (16)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_data_r_err_clr_START (17)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_data_r_err_clr_END (17)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_data_w_err_clr_START (18)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_data_w_err_clr_END (18)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_sq_r_err_clr_START (19)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_sq_r_err_clr_END (19)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_cq_w_err_clr_START (20)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_cq_w_err_clr_END (20)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_tout_err_clr_START (21)
#define SOC_NPU_SYSDMA_INT_CLR1_ch6_tout_err_clr_END (21)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_done_clr_START (24)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_done_clr_END (24)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_data_r_err_clr_START (25)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_data_r_err_clr_END (25)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_data_w_err_clr_START (26)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_data_w_err_clr_END (26)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_sq_r_err_clr_START (27)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_sq_r_err_clr_END (27)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_cq_w_err_clr_START (28)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_cq_w_err_clr_END (28)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_tout_err_clr_START (29)
#define SOC_NPU_SYSDMA_INT_CLR1_ch7_tout_err_clr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_done_mint : 1;
        unsigned int ch0_data_r_err_mint : 1;
        unsigned int ch0_data_w_err_mint : 1;
        unsigned int ch0_sq_r_err_mint : 1;
        unsigned int ch0_cq_w_err_mint : 1;
        unsigned int ch0_tout_err_mint : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch1_done_mint : 1;
        unsigned int ch1_data_r_err_mint : 1;
        unsigned int ch1_data_w_err_mint : 1;
        unsigned int ch1_sq_r_err_mint : 1;
        unsigned int ch1_cq_w_err_mint : 1;
        unsigned int ch1_tout_err_mint : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch2_done_mint : 1;
        unsigned int ch2_data_r_err_mint : 1;
        unsigned int ch2_data_w_err_mint : 1;
        unsigned int ch2_sq_r_err_mint : 1;
        unsigned int ch2_cq_w_err_mint : 1;
        unsigned int ch2_tout_err_mint : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch3_done_mint : 1;
        unsigned int ch3_data_r_err_mint : 1;
        unsigned int ch3_data_w_err_mint : 1;
        unsigned int ch3_sq_r_err_mint : 1;
        unsigned int ch3_cq_w_err_mint : 1;
        unsigned int ch3_tout_err_mint : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_MASK_INT0_UNION;
#endif
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_done_mint_START (0)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_done_mint_END (0)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_data_r_err_mint_START (1)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_data_r_err_mint_END (1)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_data_w_err_mint_START (2)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_data_w_err_mint_END (2)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_sq_r_err_mint_START (3)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_sq_r_err_mint_END (3)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_cq_w_err_mint_START (4)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_cq_w_err_mint_END (4)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_tout_err_mint_START (5)
#define SOC_NPU_SYSDMA_MASK_INT0_ch0_tout_err_mint_END (5)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_done_mint_START (8)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_done_mint_END (8)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_data_r_err_mint_START (9)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_data_r_err_mint_END (9)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_data_w_err_mint_START (10)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_data_w_err_mint_END (10)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_sq_r_err_mint_START (11)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_sq_r_err_mint_END (11)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_cq_w_err_mint_START (12)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_cq_w_err_mint_END (12)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_tout_err_mint_START (13)
#define SOC_NPU_SYSDMA_MASK_INT0_ch1_tout_err_mint_END (13)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_done_mint_START (16)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_done_mint_END (16)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_data_r_err_mint_START (17)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_data_r_err_mint_END (17)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_data_w_err_mint_START (18)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_data_w_err_mint_END (18)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_sq_r_err_mint_START (19)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_sq_r_err_mint_END (19)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_cq_w_err_mint_START (20)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_cq_w_err_mint_END (20)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_tout_err_mint_START (21)
#define SOC_NPU_SYSDMA_MASK_INT0_ch2_tout_err_mint_END (21)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_done_mint_START (24)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_done_mint_END (24)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_data_r_err_mint_START (25)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_data_r_err_mint_END (25)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_data_w_err_mint_START (26)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_data_w_err_mint_END (26)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_sq_r_err_mint_START (27)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_sq_r_err_mint_END (27)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_cq_w_err_mint_START (28)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_cq_w_err_mint_END (28)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_tout_err_mint_START (29)
#define SOC_NPU_SYSDMA_MASK_INT0_ch3_tout_err_mint_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_done_mint : 1;
        unsigned int ch4_data_r_err_mint : 1;
        unsigned int ch4_data_w_err_mint : 1;
        unsigned int ch4_sq_r_err_mint : 1;
        unsigned int ch4_cq_w_err_mint : 1;
        unsigned int ch4_tout_err_mint : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch5_done_mint : 1;
        unsigned int ch5_data_r_err_mint : 1;
        unsigned int ch5_data_w_err_mint : 1;
        unsigned int ch5_sq_r_err_mint : 1;
        unsigned int ch5_cq_w_err_mint : 1;
        unsigned int ch5_tout_err_mint : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch6_done_mint : 1;
        unsigned int ch6_data_r_err_mint : 1;
        unsigned int ch6_data_w_err_mint : 1;
        unsigned int ch6_sq_r_err_mint : 1;
        unsigned int ch6_cq_w_err_mint : 1;
        unsigned int ch6_tout_err_mint : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch7_done_mint : 1;
        unsigned int ch7_data_r_err_mint : 1;
        unsigned int ch7_data_w_err_mint : 1;
        unsigned int ch7_sq_r_err_mint : 1;
        unsigned int ch7_cq_w_err_mint : 1;
        unsigned int ch7_tout_err_mint : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_MASK_INT1_UNION;
#endif
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_done_mint_START (0)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_done_mint_END (0)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_data_r_err_mint_START (1)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_data_r_err_mint_END (1)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_data_w_err_mint_START (2)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_data_w_err_mint_END (2)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_sq_r_err_mint_START (3)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_sq_r_err_mint_END (3)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_cq_w_err_mint_START (4)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_cq_w_err_mint_END (4)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_tout_err_mint_START (5)
#define SOC_NPU_SYSDMA_MASK_INT1_ch4_tout_err_mint_END (5)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_done_mint_START (8)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_done_mint_END (8)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_data_r_err_mint_START (9)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_data_r_err_mint_END (9)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_data_w_err_mint_START (10)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_data_w_err_mint_END (10)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_sq_r_err_mint_START (11)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_sq_r_err_mint_END (11)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_cq_w_err_mint_START (12)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_cq_w_err_mint_END (12)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_tout_err_mint_START (13)
#define SOC_NPU_SYSDMA_MASK_INT1_ch5_tout_err_mint_END (13)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_done_mint_START (16)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_done_mint_END (16)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_data_r_err_mint_START (17)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_data_r_err_mint_END (17)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_data_w_err_mint_START (18)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_data_w_err_mint_END (18)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_sq_r_err_mint_START (19)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_sq_r_err_mint_END (19)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_cq_w_err_mint_START (20)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_cq_w_err_mint_END (20)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_tout_err_mint_START (21)
#define SOC_NPU_SYSDMA_MASK_INT1_ch6_tout_err_mint_END (21)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_done_mint_START (24)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_done_mint_END (24)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_data_r_err_mint_START (25)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_data_r_err_mint_END (25)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_data_w_err_mint_START (26)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_data_w_err_mint_END (26)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_sq_r_err_mint_START (27)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_sq_r_err_mint_END (27)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_cq_w_err_mint_START (28)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_cq_w_err_mint_END (28)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_tout_err_mint_START (29)
#define SOC_NPU_SYSDMA_MASK_INT1_ch7_tout_err_mint_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_done_rint : 1;
        unsigned int ch0_data_r_err_rint : 1;
        unsigned int ch0_data_w_err_rint : 1;
        unsigned int ch0_sq_r_err_rint : 1;
        unsigned int ch0_cq_w_err_rint : 1;
        unsigned int ch0_tout_err_rint : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch1_done_rint : 1;
        unsigned int ch1_data_r_err_rint : 1;
        unsigned int ch1_data_w_err_rint : 1;
        unsigned int ch1_sq_r_err_rint : 1;
        unsigned int ch1_cq_w_err_rint : 1;
        unsigned int ch1_tout_err_rint : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch2_done_rint : 1;
        unsigned int ch2_data_r_err_rint : 1;
        unsigned int ch2_data_w_err_rint : 1;
        unsigned int ch2_sq_r_err_rint : 1;
        unsigned int ch2_cq_w_err_rint : 1;
        unsigned int ch2_tout_err_rint : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch3_done_rint : 1;
        unsigned int ch3_data_r_err_rint : 1;
        unsigned int ch3_data_w_err_rint : 1;
        unsigned int ch3_sq_r_err_rint : 1;
        unsigned int ch3_cq_w_err_rint : 1;
        unsigned int ch3_tout_err_rint : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_RAW_INT0_UNION;
#endif
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_done_rint_START (0)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_done_rint_END (0)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_data_r_err_rint_START (1)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_data_r_err_rint_END (1)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_data_w_err_rint_START (2)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_data_w_err_rint_END (2)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_sq_r_err_rint_START (3)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_sq_r_err_rint_END (3)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_cq_w_err_rint_START (4)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_cq_w_err_rint_END (4)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_tout_err_rint_START (5)
#define SOC_NPU_SYSDMA_RAW_INT0_ch0_tout_err_rint_END (5)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_done_rint_START (8)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_done_rint_END (8)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_data_r_err_rint_START (9)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_data_r_err_rint_END (9)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_data_w_err_rint_START (10)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_data_w_err_rint_END (10)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_sq_r_err_rint_START (11)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_sq_r_err_rint_END (11)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_cq_w_err_rint_START (12)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_cq_w_err_rint_END (12)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_tout_err_rint_START (13)
#define SOC_NPU_SYSDMA_RAW_INT0_ch1_tout_err_rint_END (13)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_done_rint_START (16)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_done_rint_END (16)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_data_r_err_rint_START (17)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_data_r_err_rint_END (17)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_data_w_err_rint_START (18)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_data_w_err_rint_END (18)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_sq_r_err_rint_START (19)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_sq_r_err_rint_END (19)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_cq_w_err_rint_START (20)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_cq_w_err_rint_END (20)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_tout_err_rint_START (21)
#define SOC_NPU_SYSDMA_RAW_INT0_ch2_tout_err_rint_END (21)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_done_rint_START (24)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_done_rint_END (24)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_data_r_err_rint_START (25)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_data_r_err_rint_END (25)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_data_w_err_rint_START (26)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_data_w_err_rint_END (26)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_sq_r_err_rint_START (27)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_sq_r_err_rint_END (27)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_cq_w_err_rint_START (28)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_cq_w_err_rint_END (28)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_tout_err_rint_START (29)
#define SOC_NPU_SYSDMA_RAW_INT0_ch3_tout_err_rint_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_done_rint : 1;
        unsigned int ch4_data_r_err_rint : 1;
        unsigned int ch4_data_w_err_rint : 1;
        unsigned int ch4_sq_r_err_rint : 1;
        unsigned int ch4_cq_w_err_rint : 1;
        unsigned int ch4_tout_err_rint : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch5_done_rint : 1;
        unsigned int ch5_data_r_err_rint : 1;
        unsigned int ch5_data_w_err_rint : 1;
        unsigned int ch5_sq_r_err_rint : 1;
        unsigned int ch5_cq_w_err_rint : 1;
        unsigned int ch5_tout_err_rint : 1;
        unsigned int reserved_1 : 2;
        unsigned int ch6_done_rint : 1;
        unsigned int ch6_data_r_err_rint : 1;
        unsigned int ch6_data_w_err_rint : 1;
        unsigned int ch6_sq_r_err_rint : 1;
        unsigned int ch6_cq_w_err_rint : 1;
        unsigned int ch6_tout_err_rint : 1;
        unsigned int reserved_2 : 2;
        unsigned int ch7_done_rint : 1;
        unsigned int ch7_data_r_err_rint : 1;
        unsigned int ch7_data_w_err_rint : 1;
        unsigned int ch7_sq_r_err_rint : 1;
        unsigned int ch7_cq_w_err_rint : 1;
        unsigned int ch7_tout_err_rint : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_SYSDMA_RAW_INT1_UNION;
#endif
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_done_rint_START (0)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_done_rint_END (0)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_data_r_err_rint_START (1)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_data_r_err_rint_END (1)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_data_w_err_rint_START (2)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_data_w_err_rint_END (2)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_sq_r_err_rint_START (3)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_sq_r_err_rint_END (3)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_cq_w_err_rint_START (4)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_cq_w_err_rint_END (4)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_tout_err_rint_START (5)
#define SOC_NPU_SYSDMA_RAW_INT1_ch4_tout_err_rint_END (5)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_done_rint_START (8)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_done_rint_END (8)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_data_r_err_rint_START (9)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_data_r_err_rint_END (9)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_data_w_err_rint_START (10)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_data_w_err_rint_END (10)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_sq_r_err_rint_START (11)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_sq_r_err_rint_END (11)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_cq_w_err_rint_START (12)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_cq_w_err_rint_END (12)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_tout_err_rint_START (13)
#define SOC_NPU_SYSDMA_RAW_INT1_ch5_tout_err_rint_END (13)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_done_rint_START (16)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_done_rint_END (16)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_data_r_err_rint_START (17)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_data_r_err_rint_END (17)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_data_w_err_rint_START (18)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_data_w_err_rint_END (18)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_sq_r_err_rint_START (19)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_sq_r_err_rint_END (19)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_cq_w_err_rint_START (20)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_cq_w_err_rint_END (20)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_tout_err_rint_START (21)
#define SOC_NPU_SYSDMA_RAW_INT1_ch6_tout_err_rint_END (21)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_done_rint_START (24)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_done_rint_END (24)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_data_r_err_rint_START (25)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_data_r_err_rint_END (25)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_data_w_err_rint_START (26)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_data_w_err_rint_END (26)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_sq_r_err_rint_START (27)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_sq_r_err_rint_END (27)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_cq_w_err_rint_START (28)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_cq_w_err_rint_END (28)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_tout_err_rint_START (29)
#define SOC_NPU_SYSDMA_RAW_INT1_ch7_tout_err_rint_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_en : 1;
        unsigned int dbg_mode : 3;
        unsigned int dbg_ch_sel : 3;
        unsigned int reserved_0 : 1;
        unsigned int dbg_w_pattern : 8;
        unsigned int switch_en : 1;
        unsigned int l2_r_err_clr : 1;
        unsigned int l2_w_err_clr : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_NPU_SYSDMA_SDMA_CTRL_UNION;
#endif
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_en_START (0)
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_en_END (0)
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_mode_START (1)
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_mode_END (3)
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_ch_sel_START (4)
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_ch_sel_END (6)
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_w_pattern_START (8)
#define SOC_NPU_SYSDMA_SDMA_CTRL_dbg_w_pattern_END (15)
#define SOC_NPU_SYSDMA_SDMA_CTRL_switch_en_START (16)
#define SOC_NPU_SYSDMA_SDMA_CTRL_switch_en_END (16)
#define SOC_NPU_SYSDMA_SDMA_CTRL_l2_r_err_clr_START (17)
#define SOC_NPU_SYSDMA_SDMA_CTRL_l2_r_err_clr_END (17)
#define SOC_NPU_SYSDMA_SDMA_CTRL_l2_w_err_clr_START (18)
#define SOC_NPU_SYSDMA_SDMA_CTRL_l2_w_err_clr_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ie : 1;
        unsigned int mode : 3;
        unsigned int status : 4;
        unsigned int w_pattern : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE0_UNION;
#endif
#define SOC_NPU_SYSDMA_DEBUG_SQE0_ie_START (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE0_ie_END (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE0_mode_START (1)
#define SOC_NPU_SYSDMA_DEBUG_SQE0_mode_END (3)
#define SOC_NPU_SYSDMA_DEBUG_SQE0_status_START (4)
#define SOC_NPU_SYSDMA_DEBUG_SQE0_status_END (7)
#define SOC_NPU_SYSDMA_DEBUG_SQE0_w_pattern_START (8)
#define SOC_NPU_SYSDMA_DEBUG_SQE0_w_pattern_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s_sid : 8;
        unsigned int s_subsid : 8;
        unsigned int d_sid : 8;
        unsigned int d_subsid : 8;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE1_UNION;
#endif
#define SOC_NPU_SYSDMA_DEBUG_SQE1_s_sid_START (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE1_s_sid_END (7)
#define SOC_NPU_SYSDMA_DEBUG_SQE1_s_subsid_START (8)
#define SOC_NPU_SYSDMA_DEBUG_SQE1_s_subsid_END (15)
#define SOC_NPU_SYSDMA_DEBUG_SQE1_d_sid_START (16)
#define SOC_NPU_SYSDMA_DEBUG_SQE1_d_sid_END (23)
#define SOC_NPU_SYSDMA_DEBUG_SQE1_d_subsid_START (24)
#define SOC_NPU_SYSDMA_DEBUG_SQE1_d_subsid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int length : 32;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE3_UNION;
#endif
#define SOC_NPU_SYSDMA_DEBUG_SQE3_length_START (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE3_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s_addr_l : 32;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE4_UNION;
#endif
#define SOC_NPU_SYSDMA_DEBUG_SQE4_s_addr_l_START (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE4_s_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s_addr_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE5_UNION;
#endif
#define SOC_NPU_SYSDMA_DEBUG_SQE5_s_addr_h_START (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE5_s_addr_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d_addr_l : 32;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE6_UNION;
#endif
#define SOC_NPU_SYSDMA_DEBUG_SQE6_d_addr_l_START (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE6_d_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int d_addr_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_DEBUG_SQE7_UNION;
#endif
#define SOC_NPU_SYSDMA_DEBUG_SQE7_d_addr_h_START (0)
#define SOC_NPU_SYSDMA_DEBUG_SQE7_d_addr_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe0 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS0_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS0_sqe0_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS0_sqe0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe1 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS1_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS1_sqe1_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS1_sqe1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe2 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS2_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS2_sqe2_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS2_sqe2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe3 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS3_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS3_sqe3_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS3_sqe3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe4 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS4_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS4_sqe4_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS4_sqe4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe5 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS5_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS5_sqe5_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS5_sqe5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe6 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS6_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS6_sqe6_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS6_sqe6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe7 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS7_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS7_sqe7_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS7_sqe7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status8 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS8_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS8_dma_status8_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS8_dma_status8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status9 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS9_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS9_dma_status9_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS9_dma_status9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status10 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS10_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS10_dma_status10_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS10_dma_status10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status11 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS11_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS11_dma_status11_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS11_dma_status11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status12 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS12_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS12_dma_status12_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS12_dma_status12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status13 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS13_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS13_dma_status13_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS13_dma_status13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status14 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS14_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS14_dma_status14_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS14_dma_status14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status15 : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_STATUS15_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_STATUS15_dma_status15_START (0)
#define SOC_NPU_SYSDMA_DMA_STATUS15_dma_status15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timeout_th : 32;
    } reg;
} SOC_NPU_SYSDMA_DMA_TIMEOUT_TH_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_TIMEOUT_TH_timeout_th_START (0)
#define SOC_NPU_SYSDMA_DMA_TIMEOUT_TH_timeout_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_en : 1;
        unsigned int ch_srst : 1;
        unsigned int qos : 2;
        unsigned int sq_size : 4;
        unsigned int cq_size : 4;
        unsigned int cqe_fmt_sel : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_NPU_SYSDMA_CH_CTRL_UNION;
#endif
#define SOC_NPU_SYSDMA_CH_CTRL_ch_en_START (0)
#define SOC_NPU_SYSDMA_CH_CTRL_ch_en_END (0)
#define SOC_NPU_SYSDMA_CH_CTRL_ch_srst_START (1)
#define SOC_NPU_SYSDMA_CH_CTRL_ch_srst_END (1)
#define SOC_NPU_SYSDMA_CH_CTRL_qos_START (2)
#define SOC_NPU_SYSDMA_CH_CTRL_qos_END (3)
#define SOC_NPU_SYSDMA_CH_CTRL_sq_size_START (4)
#define SOC_NPU_SYSDMA_CH_CTRL_sq_size_END (7)
#define SOC_NPU_SYSDMA_CH_CTRL_cq_size_START (8)
#define SOC_NPU_SYSDMA_CH_CTRL_cq_size_END (11)
#define SOC_NPU_SYSDMA_CH_CTRL_cqe_fmt_sel_START (12)
#define SOC_NPU_SYSDMA_CH_CTRL_cqe_fmt_sel_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_status : 1;
        unsigned int reserved : 7;
        unsigned int blk_cnt : 24;
    } reg;
} SOC_NPU_SYSDMA_STATUS_UNION;
#endif
#define SOC_NPU_SYSDMA_STATUS_ch_status_START (0)
#define SOC_NPU_SYSDMA_STATUS_ch_status_END (0)
#define SOC_NPU_SYSDMA_STATUS_blk_cnt_START (8)
#define SOC_NPU_SYSDMA_STATUS_blk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_sid : 8;
        unsigned int reserved_0 : 8;
        unsigned int sq_sub_sid : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_NPU_SYSDMA_SQ_SID_UNION;
#endif
#define SOC_NPU_SYSDMA_SQ_SID_sq_sid_START (0)
#define SOC_NPU_SYSDMA_SQ_SID_sq_sid_END (7)
#define SOC_NPU_SYSDMA_SQ_SID_sq_sub_sid_START (16)
#define SOC_NPU_SYSDMA_SQ_SID_sq_sub_sid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_sid : 8;
        unsigned int reserved_0 : 8;
        unsigned int cq_sub_sid : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_NPU_SYSDMA_CQ_SID_UNION;
#endif
#define SOC_NPU_SYSDMA_CQ_SID_cq_sid_START (0)
#define SOC_NPU_SYSDMA_CQ_SID_cq_sid_END (7)
#define SOC_NPU_SYSDMA_CQ_SID_cq_sub_sid_START (16)
#define SOC_NPU_SYSDMA_CQ_SID_cq_sub_sid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_base_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_SQ_BASE_H_UNION;
#endif
#define SOC_NPU_SYSDMA_SQ_BASE_H_sq_base_h_START (0)
#define SOC_NPU_SYSDMA_SQ_BASE_H_sq_base_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_base_l : 32;
    } reg;
} SOC_NPU_SYSDMA_SQ_BASE_L_UNION;
#endif
#define SOC_NPU_SYSDMA_SQ_BASE_L_sq_base_l_START (0)
#define SOC_NPU_SYSDMA_SQ_BASE_L_sq_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_base_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_CQ_BASE_H_UNION;
#endif
#define SOC_NPU_SYSDMA_CQ_BASE_H_cq_base_h_START (0)
#define SOC_NPU_SYSDMA_CQ_BASE_H_cq_base_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_base_l : 32;
    } reg;
} SOC_NPU_SYSDMA_CQ_BASE_L_UNION;
#endif
#define SOC_NPU_SYSDMA_CQ_BASE_L_cq_base_l_START (0)
#define SOC_NPU_SYSDMA_CQ_BASE_L_cq_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_wp : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_SQ_WP_UNION;
#endif
#define SOC_NPU_SYSDMA_SQ_WP_sq_wp_START (0)
#define SOC_NPU_SYSDMA_SQ_WP_sq_wp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sq_rp : 16;
        unsigned int sq_rp_p : 16;
    } reg;
} SOC_NPU_SYSDMA_SQ_RP_UNION;
#endif
#define SOC_NPU_SYSDMA_SQ_RP_sq_rp_START (0)
#define SOC_NPU_SYSDMA_SQ_RP_sq_rp_END (15)
#define SOC_NPU_SYSDMA_SQ_RP_sq_rp_p_START (16)
#define SOC_NPU_SYSDMA_SQ_RP_sq_rp_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_wp : 16;
        unsigned int cq_wp_p : 16;
    } reg;
} SOC_NPU_SYSDMA_CQ_WP_UNION;
#endif
#define SOC_NPU_SYSDMA_CQ_WP_cq_wp_START (0)
#define SOC_NPU_SYSDMA_CQ_WP_cq_wp_END (15)
#define SOC_NPU_SYSDMA_CQ_WP_cq_wp_p_START (16)
#define SOC_NPU_SYSDMA_CQ_WP_cq_wp_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cq_rp : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_CQ_RPL_UNION;
#endif
#define SOC_NPU_SYSDMA_CQ_RPL_cq_rp_START (0)
#define SOC_NPU_SYSDMA_CQ_RPL_cq_rp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_vaddr_base_l : 32;
    } reg;
} SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_L_UNION;
#endif
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_L_l2_vaddr_base_l_START (0)
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_L_l2_vaddr_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_vaddr_base_h : 32;
    } reg;
} SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_H_UNION;
#endif
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_H_l2_vaddr_base_h_START (0)
#define SOC_NPU_SYSDMA_L2_REMAP_VADDR_BASE_H_l2_vaddr_base_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_size : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_SYSDMA_L2_SIZE_UNION;
#endif
#define SOC_NPU_SYSDMA_L2_SIZE_l2_size_START (0)
#define SOC_NPU_SYSDMA_L2_SIZE_l2_size_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_credit_en : 1;
        unsigned int r_credit_en_dynam : 1;
        unsigned int w_credit_en : 1;
        unsigned int w_credit_en_dynam : 1;
        unsigned int credit_mode_dynam : 2;
        unsigned int reserved_0 : 2;
        unsigned int rosd_cfg : 6;
        unsigned int reserved_1 : 2;
        unsigned int wosd_cfg : 5;
        unsigned int reserved_2 : 3;
        unsigned int mon_en : 1;
        unsigned int mon_axi_sel : 1;
        unsigned int aif_clk_en : 1;
        unsigned int aif_clk_sel : 1;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_NPU_SYSDMA_BIU_CTRL0_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_CTRL0_r_credit_en_START (0)
#define SOC_NPU_SYSDMA_BIU_CTRL0_r_credit_en_END (0)
#define SOC_NPU_SYSDMA_BIU_CTRL0_r_credit_en_dynam_START (1)
#define SOC_NPU_SYSDMA_BIU_CTRL0_r_credit_en_dynam_END (1)
#define SOC_NPU_SYSDMA_BIU_CTRL0_w_credit_en_START (2)
#define SOC_NPU_SYSDMA_BIU_CTRL0_w_credit_en_END (2)
#define SOC_NPU_SYSDMA_BIU_CTRL0_w_credit_en_dynam_START (3)
#define SOC_NPU_SYSDMA_BIU_CTRL0_w_credit_en_dynam_END (3)
#define SOC_NPU_SYSDMA_BIU_CTRL0_credit_mode_dynam_START (4)
#define SOC_NPU_SYSDMA_BIU_CTRL0_credit_mode_dynam_END (5)
#define SOC_NPU_SYSDMA_BIU_CTRL0_rosd_cfg_START (8)
#define SOC_NPU_SYSDMA_BIU_CTRL0_rosd_cfg_END (13)
#define SOC_NPU_SYSDMA_BIU_CTRL0_wosd_cfg_START (16)
#define SOC_NPU_SYSDMA_BIU_CTRL0_wosd_cfg_END (20)
#define SOC_NPU_SYSDMA_BIU_CTRL0_mon_en_START (24)
#define SOC_NPU_SYSDMA_BIU_CTRL0_mon_en_END (24)
#define SOC_NPU_SYSDMA_BIU_CTRL0_mon_axi_sel_START (25)
#define SOC_NPU_SYSDMA_BIU_CTRL0_mon_axi_sel_END (25)
#define SOC_NPU_SYSDMA_BIU_CTRL0_aif_clk_en_START (26)
#define SOC_NPU_SYSDMA_BIU_CTRL0_aif_clk_en_END (26)
#define SOC_NPU_SYSDMA_BIU_CTRL0_aif_clk_sel_START (27)
#define SOC_NPU_SYSDMA_BIU_CTRL0_aif_clk_sel_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_osd_th_dynam : 6;
        unsigned int reserved_0 : 10;
        unsigned int w_osd_th_dynam : 5;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_NPU_SYSDMA_BIU_CTRL1_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_CTRL1_r_osd_th_dynam_START (0)
#define SOC_NPU_SYSDMA_BIU_CTRL1_r_osd_th_dynam_END (5)
#define SOC_NPU_SYSDMA_BIU_CTRL1_w_osd_th_dynam_START (16)
#define SOC_NPU_SYSDMA_BIU_CTRL1_w_osd_th_dynam_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_credit_step : 7;
        unsigned int r_credit_lth : 9;
        unsigned int r_credit_uth : 9;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_SYSDMA_BIU_CTRL2_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_CTRL2_r_credit_step_START (0)
#define SOC_NPU_SYSDMA_BIU_CTRL2_r_credit_step_END (6)
#define SOC_NPU_SYSDMA_BIU_CTRL2_r_credit_lth_START (7)
#define SOC_NPU_SYSDMA_BIU_CTRL2_r_credit_lth_END (15)
#define SOC_NPU_SYSDMA_BIU_CTRL2_r_credit_uth_START (16)
#define SOC_NPU_SYSDMA_BIU_CTRL2_r_credit_uth_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_credit_step_dynam : 7;
        unsigned int r_credit_lth_dynam : 9;
        unsigned int r_credit_uth_dynam : 9;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_SYSDMA_BIU_CTRL3_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_CTRL3_r_credit_step_dynam_START (0)
#define SOC_NPU_SYSDMA_BIU_CTRL3_r_credit_step_dynam_END (6)
#define SOC_NPU_SYSDMA_BIU_CTRL3_r_credit_lth_dynam_START (7)
#define SOC_NPU_SYSDMA_BIU_CTRL3_r_credit_lth_dynam_END (15)
#define SOC_NPU_SYSDMA_BIU_CTRL3_r_credit_uth_dynam_START (16)
#define SOC_NPU_SYSDMA_BIU_CTRL3_r_credit_uth_dynam_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_credit_step_dynam : 7;
        unsigned int w_credit_lth_dynam : 9;
        unsigned int w_credit_uth_dynam : 9;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_SYSDMA_BIU_CTRL4_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_CTRL4_w_credit_step_dynam_START (0)
#define SOC_NPU_SYSDMA_BIU_CTRL4_w_credit_step_dynam_END (6)
#define SOC_NPU_SYSDMA_BIU_CTRL4_w_credit_lth_dynam_START (7)
#define SOC_NPU_SYSDMA_BIU_CTRL4_w_credit_lth_dynam_END (15)
#define SOC_NPU_SYSDMA_BIU_CTRL4_w_credit_uth_dynam_START (16)
#define SOC_NPU_SYSDMA_BIU_CTRL4_w_credit_uth_dynam_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_credit_step : 7;
        unsigned int w_credit_lth : 9;
        unsigned int w_credit_uth : 9;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_SYSDMA_BIU_CTRL5_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_CTRL5_w_credit_step_START (0)
#define SOC_NPU_SYSDMA_BIU_CTRL5_w_credit_step_END (6)
#define SOC_NPU_SYSDMA_BIU_CTRL5_w_credit_lth_START (7)
#define SOC_NPU_SYSDMA_BIU_CTRL5_w_credit_lth_END (15)
#define SOC_NPU_SYSDMA_BIU_CTRL5_w_credit_uth_START (16)
#define SOC_NPU_SYSDMA_BIU_CTRL5_w_credit_uth_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_cycle : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS0_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS0_stat_cycle_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS0_stat_cycle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_wcmd_num : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS1_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS1_stat_wcmd_num_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS1_stat_wcmd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_rcmd_num : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS2_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS2_stat_rcmd_num_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS2_stat_rcmd_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_wlat_raw : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS3_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS3_stat_wlat_raw_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS3_stat_wlat_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_rlat_raw : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS4_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS4_stat_rlat_raw_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS4_stat_rlat_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_flux_wr : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS5_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS5_stat_flux_wr_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS5_stat_flux_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_flux_rd : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS6_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS6_stat_flux_rd_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS6_stat_flux_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_wstrob : 16;
        unsigned int axi1_wstrob : 16;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS7_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS7_axi0_wstrob_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS7_axi0_wstrob_END (15)
#define SOC_NPU_SYSDMA_BIU_STATUS7_axi1_wstrob_START (16)
#define SOC_NPU_SYSDMA_BIU_STATUS7_axi1_wstrob_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_rosd : 8;
        unsigned int axi0_wosd : 8;
        unsigned int axi1_rosd : 8;
        unsigned int axi1_wosd : 8;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS8_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi0_rosd_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi0_rosd_END (7)
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi0_wosd_START (8)
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi0_wosd_END (15)
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi1_rosd_START (16)
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi1_rosd_END (23)
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi1_wosd_START (24)
#define SOC_NPU_SYSDMA_BIU_STATUS8_axi1_wosd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int biu_idle : 1;
        unsigned int l2_r_err : 1;
        unsigned int l2_w_err : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS9_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS9_biu_idle_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS9_biu_idle_END (0)
#define SOC_NPU_SYSDMA_BIU_STATUS9_l2_r_err_START (1)
#define SOC_NPU_SYSDMA_BIU_STATUS9_l2_r_err_END (1)
#define SOC_NPU_SYSDMA_BIU_STATUS9_l2_w_err_START (2)
#define SOC_NPU_SYSDMA_BIU_STATUS9_l2_w_err_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_r_err_vaddr_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS10_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS10_l2_r_err_vaddr_l_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS10_l2_r_err_vaddr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_w_err_vaddr_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BIU_STATUS11_UNION;
#endif
#define SOC_NPU_SYSDMA_BIU_STATUS11_l2_w_err_vaddr_l_START (0)
#define SOC_NPU_SYSDMA_BIU_STATUS11_l2_w_err_vaddr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg0_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG0_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG0_H_brif_dbg0_h_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG0_H_brif_dbg0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg0_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG0_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG0_L_brif_dbg0_l_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG0_L_brif_dbg0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg1_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG1_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG1_H_brif_dbg1_h_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG1_H_brif_dbg1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg1_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG1_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG1_L_brif_dbg1_l_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG1_L_brif_dbg1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg2_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG2_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG2_H_brif_dbg2_h_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG2_H_brif_dbg2_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg2_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG2_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG2_L_brif_dbg2_l_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG2_L_brif_dbg2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg3_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG3_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG3_H_brif_dbg3_h_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG3_H_brif_dbg3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_dbg3_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BRIF_DBG3_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_DBG3_L_brif_dbg3_l_START (0)
#define SOC_NPU_SYSDMA_BRIF_DBG3_L_brif_dbg3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg0_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG0_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG0_H_bwif_dbg0_h_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG0_H_bwif_dbg0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg0_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG0_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG0_L_bwif_dbg0_l_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG0_L_bwif_dbg0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg1_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG1_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG1_H_bwif_dbg1_h_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG1_H_bwif_dbg1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg1_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG1_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG1_L_bwif_dbg1_l_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG1_L_bwif_dbg1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg2_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG2_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG2_H_bwif_dbg2_h_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG2_H_bwif_dbg2_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg2_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG2_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG2_L_bwif_dbg2_l_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG2_L_bwif_dbg2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg3_h : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG3_H_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG3_H_bwif_dbg3_h_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG3_H_bwif_dbg3_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_dbg3_l : 32;
    } reg;
} SOC_NPU_SYSDMA_BWIF_DBG3_L_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_DBG3_L_bwif_dbg3_l_START (0)
#define SOC_NPU_SYSDMA_BWIF_DBG3_L_bwif_dbg3_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brif_retire_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_BRIF_RETIRE_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_BRIF_RETIRE_CNT_brif_retire_cnt_START (0)
#define SOC_NPU_SYSDMA_BRIF_RETIRE_CNT_brif_retire_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_retire_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_BWIF_RETIRE_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_BWIF_RETIRE_CNT_bwif_retire_cnt_START (0)
#define SOC_NPU_SYSDMA_BWIF_RETIRE_CNT_bwif_retire_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe_rd_req_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_SQE_RD_REQ_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_SQE_RD_REQ_CNT_sqe_rd_req_cnt_START (0)
#define SOC_NPU_SYSDMA_SQE_RD_REQ_CNT_sqe_rd_req_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sqe_rd_rsp_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_SQE_RD_RSP_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_SQE_RD_RSP_CNT_sqe_rd_rsp_cnt_START (0)
#define SOC_NPU_SYSDMA_SQE_RD_RSP_CNT_sqe_rd_rsp_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cqe_wr_req_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_CQE_WR_REQ_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_CQE_WR_REQ_CNT_cqe_wr_req_cnt_START (0)
#define SOC_NPU_SYSDMA_CQE_WR_REQ_CNT_cqe_wr_req_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cqe_wr_rsp_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_CQE_WR_RSP_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_CQE_WR_RSP_CNT_cqe_wr_rsp_cnt_START (0)
#define SOC_NPU_SYSDMA_CQE_WR_RSP_CNT_cqe_wr_rsp_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_rd_req_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_BLK_RD_REQ_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_BLK_RD_REQ_CNT_blk_rd_req_cnt_START (0)
#define SOC_NPU_SYSDMA_BLK_RD_REQ_CNT_blk_rd_req_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_wr_req_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_BLK_WR_REQ_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_BLK_WR_REQ_CNT_blk_wr_req_cnt_START (0)
#define SOC_NPU_SYSDMA_BLK_WR_REQ_CNT_blk_wr_req_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_cur_st : 2;
        unsigned int ch1_cur_st : 2;
        unsigned int ch2_cur_st : 2;
        unsigned int ch3_cur_st : 2;
        unsigned int ch4_cur_st : 2;
        unsigned int ch5_cur_st : 2;
        unsigned int ch6_cur_st : 2;
        unsigned int ch7_cur_st : 2;
        unsigned int srif_cur_st : 3;
        unsigned int sdec_cur_st : 3;
        unsigned int cwif_cur_st : 3;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_SYSDMA_DMA_INER_FSM_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch0_cur_st_START (0)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch0_cur_st_END (1)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch1_cur_st_START (2)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch1_cur_st_END (3)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch2_cur_st_START (4)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch2_cur_st_END (5)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch3_cur_st_START (6)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch3_cur_st_END (7)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch4_cur_st_START (8)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch4_cur_st_END (9)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch5_cur_st_START (10)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch5_cur_st_END (11)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch6_cur_st_START (12)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch6_cur_st_END (13)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch7_cur_st_START (14)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_ch7_cur_st_END (15)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_srif_cur_st_START (16)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_srif_cur_st_END (18)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_sdec_cur_st_START (19)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_sdec_cur_st_END (21)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_cwif_cur_st_START (22)
#define SOC_NPU_SYSDMA_DMA_INER_FSM_cwif_cur_st_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bwif_pld_fifo_ufl : 1;
        unsigned int bwif_pld_fifo_ovf : 1;
        unsigned int bwif_pld_fifo_ful : 1;
        unsigned int bwif_pld_fifo_emp : 1;
        unsigned int bwif_pld_fifo_fill : 2;
        unsigned int reserved_0 : 2;
        unsigned int cqe_fifo_ufl : 1;
        unsigned int cqe_fifo_ovf : 1;
        unsigned int cqe_fifo_ful : 1;
        unsigned int cqe_fifo_emp : 1;
        unsigned int cqe_fifo_fill : 2;
        unsigned int reserved_1 : 2;
        unsigned int bwif_err_fifo_ufl : 1;
        unsigned int bwif_err_fifo_ovf : 1;
        unsigned int bwif_err_fifo_ful : 1;
        unsigned int bwif_err_fifo_emp : 1;
        unsigned int bwif_err_fifo_fill : 4;
        unsigned int brif_err_fifo_ufl : 1;
        unsigned int brif_err_fifo_ovf : 1;
        unsigned int brif_err_fifo_ful : 1;
        unsigned int brif_err_fifo_emp : 1;
        unsigned int brif_err_fifo_fill : 4;
    } reg;
} SOC_NPU_SYSDMA_DMA_INER_FIFO_0_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_ufl_START (0)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_ufl_END (0)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_ovf_START (1)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_ovf_END (1)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_ful_START (2)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_ful_END (2)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_emp_START (3)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_emp_END (3)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_fill_START (4)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_pld_fifo_fill_END (5)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_ufl_START (8)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_ufl_END (8)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_ovf_START (9)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_ovf_END (9)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_ful_START (10)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_ful_END (10)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_emp_START (11)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_emp_END (11)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_fill_START (12)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_cqe_fifo_fill_END (13)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_ufl_START (16)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_ufl_END (16)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_ovf_START (17)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_ovf_END (17)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_ful_START (18)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_ful_END (18)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_emp_START (19)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_emp_END (19)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_fill_START (20)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_bwif_err_fifo_fill_END (23)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_ufl_START (24)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_ufl_END (24)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_ovf_START (25)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_ovf_END (25)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_ful_START (26)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_ful_END (26)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_emp_START (27)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_emp_END (27)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_fill_START (28)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_0_brif_err_fifo_fill_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cid_fifo_ufl : 1;
        unsigned int cid_fifo_ovf : 1;
        unsigned int cid_fifo_ful : 1;
        unsigned int cid_fifo_emp : 1;
        unsigned int cid_fifo_fill : 2;
        unsigned int reserved_0 : 2;
        unsigned int bwif_stp_fifo_ufl : 1;
        unsigned int bwif_stp_fifo_ovf : 1;
        unsigned int bwif_stp_fifo_ful : 1;
        unsigned int bwif_stp_fifo_emp : 1;
        unsigned int bwif_stp_fifo_fill : 4;
        unsigned int brif_stp_fifo_ufl : 1;
        unsigned int brif_stp_fifo_ovf : 1;
        unsigned int brif_stp_fifo_ful : 1;
        unsigned int brif_stp_fifo_emp : 1;
        unsigned int brif_stp_fifo_fill : 4;
        unsigned int sw_en_patten : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_SYSDMA_DMA_INER_FIFO_1_UNION;
#endif
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_ufl_START (0)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_ufl_END (0)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_ovf_START (1)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_ovf_END (1)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_ful_START (2)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_ful_END (2)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_emp_START (3)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_emp_END (3)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_fill_START (4)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_cid_fifo_fill_END (5)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_ufl_START (8)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_ufl_END (8)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_ovf_START (9)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_ovf_END (9)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_ful_START (10)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_ful_END (10)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_emp_START (11)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_emp_END (11)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_fill_START (12)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_bwif_stp_fifo_fill_END (15)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_ufl_START (16)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_ufl_END (16)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_ovf_START (17)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_ovf_END (17)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_ful_START (18)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_ful_END (18)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_emp_START (19)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_emp_END (19)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_fill_START (20)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_brif_stp_fifo_fill_END (23)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_sw_en_patten_START (24)
#define SOC_NPU_SYSDMA_DMA_INER_FIFO_1_sw_en_patten_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_use_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SYSDMA_WR_USE_CNT_UNION;
#endif
#define SOC_NPU_SYSDMA_WR_USE_CNT_wr_use_cnt_START (0)
#define SOC_NPU_SYSDMA_WR_USE_CNT_wr_use_cnt_END (15)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
