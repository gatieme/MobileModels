#ifndef __SOC_SMMUV3_INTERFACE_H__
#define __SOC_SMMUV3_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUV3_SMMU_LP_REQ_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUV3_SMMU_LP_ACK_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_REQ_ADDR(base) ((base) + (0x0008UL))
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_ACK_ADDR(base) ((base) + (0x000CUL))
#define SOC_SMMUV3_SMMU_TCU_MID_ADDR(base) ((base) + (0x0010UL))
#define SOC_SMMUV3_SMMU_TOP_MEM_CTRL_ADDR(base) ((base) + (0x0014UL))
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_ADDR(base) ((base) + (0x020UL))
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_ADDR(base) ((base) + (0x024UL))
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE0_ADDR(base) ((base) + (0x028UL))
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE1_ADDR(base) ((base) + (0x02CUL))
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE0_ADDR(base,n) ((base) + ((n)*0x10+0x30UL))
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE1_ADDR(base,n) ((base) + ((n)*0x10+0x34UL))
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_ADDR(base) ((base) + (0x070UL))
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_ADDR(base) ((base) + (0x074UL))
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_ADDR(base) ((base) + (0x078UL))
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_ADDR(base) ((base) + (0x07CUL))
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_ADDR(base) ((base) + (0x080UL))
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_ADDR(base) ((base) + (0x084UL))
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_ADDR(base) ((base) + (0x088UL))
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_ADDR(base) ((base) + (0x08CUL))
#else
#define SOC_SMMUV3_SMMU_LP_REQ_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUV3_SMMU_LP_ACK_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_REQ_ADDR(base) ((base) + (0x0008))
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_ACK_ADDR(base) ((base) + (0x000C))
#define SOC_SMMUV3_SMMU_TCU_MID_ADDR(base) ((base) + (0x0010))
#define SOC_SMMUV3_SMMU_TOP_MEM_CTRL_ADDR(base) ((base) + (0x0014))
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_ADDR(base) ((base) + (0x020))
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_ADDR(base) ((base) + (0x024))
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE0_ADDR(base) ((base) + (0x028))
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE1_ADDR(base) ((base) + (0x02C))
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE0_ADDR(base,n) ((base) + ((n)*0x10+0x30))
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE1_ADDR(base,n) ((base) + ((n)*0x10+0x34))
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_ADDR(base) ((base) + (0x070))
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_ADDR(base) ((base) + (0x074))
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_ADDR(base) ((base) + (0x078))
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_ADDR(base) ((base) + (0x07C))
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_ADDR(base) ((base) + (0x080))
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_ADDR(base) ((base) + (0x084))
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_ADDR(base) ((base) + (0x088))
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_ADDR(base) ((base) + (0x08C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUV3_TTW_OPT_FUNC_BYPASS_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUV3_CACHELINE_INV_ALL_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUV3_TCU_TTW_OPT_MEM_CTRL_ADDR(base) ((base) + (0x0008UL))
#define SOC_SMMUV3_REPLACE_POLICY_SEL_ADDR(base) ((base) + (0x000CUL))
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL0_ADDR(base) ((base) + (0x0010UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL1_ADDR(base) ((base) + (0x0014UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY0_ADDR(base) ((base) + (0x0018UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY1_ADDR(base) ((base) + (0x001CUL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT0_ADDR(base) ((base) + (0x0020UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT1_ADDR(base) ((base) + (0x0024UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT2_ADDR(base) ((base) + (0x0028UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT3_ADDR(base) ((base) + (0x002CUL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT4_ADDR(base) ((base) + (0x0030UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT5_ADDR(base) ((base) + (0x0034UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT6_ADDR(base) ((base) + (0x0038UL))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT7_ADDR(base) ((base) + (0x003CUL))
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ADDR(base) ((base) + (0x040UL))
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_CLR_ADDR(base) ((base) + (0x044UL))
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_EN_ADDR(base) ((base) + (0x048UL))
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_STAT_ADDR(base) ((base) + (0x04CUL))
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_CLR_ADDR(base) ((base) + (0x050UL))
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_EN_ADDR(base) ((base) + (0x054UL))
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_STAT_ADDR(base) ((base) + (0x058UL))
#define SOC_SMMUV3_AUTO_CLK_GATE_EN_ADDR(base) ((base) + (0x05CUL))
#else
#define SOC_SMMUV3_TTW_OPT_FUNC_BYPASS_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUV3_CACHELINE_INV_ALL_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUV3_TCU_TTW_OPT_MEM_CTRL_ADDR(base) ((base) + (0x0008))
#define SOC_SMMUV3_REPLACE_POLICY_SEL_ADDR(base) ((base) + (0x000C))
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL0_ADDR(base) ((base) + (0x0010))
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL1_ADDR(base) ((base) + (0x0014))
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY0_ADDR(base) ((base) + (0x0018))
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY1_ADDR(base) ((base) + (0x001C))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT0_ADDR(base) ((base) + (0x0020))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT1_ADDR(base) ((base) + (0x0024))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT2_ADDR(base) ((base) + (0x0028))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT3_ADDR(base) ((base) + (0x002C))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT4_ADDR(base) ((base) + (0x0030))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT5_ADDR(base) ((base) + (0x0034))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT6_ADDR(base) ((base) + (0x0038))
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT7_ADDR(base) ((base) + (0x003C))
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ADDR(base) ((base) + (0x040))
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_CLR_ADDR(base) ((base) + (0x044))
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_EN_ADDR(base) ((base) + (0x048))
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_STAT_ADDR(base) ((base) + (0x04C))
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_CLR_ADDR(base) ((base) + (0x050))
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_EN_ADDR(base) ((base) + (0x054))
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_STAT_ADDR(base) ((base) + (0x058))
#define SOC_SMMUV3_AUTO_CLK_GATE_EN_ADDR(base) ((base) + (0x05C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUV3_SMMU_MSTR_GLB_BYPASS_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUV3_SMMU_MSTR_DEBUG_MODE_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUV3_SMMU_MSTR_MEM_CTRL_ADDR(base) ((base) + (0x0008UL))
#define SOC_SMMUV3_SMMU_MSTR_CLK_EN_ADDR(base) ((base) + (0x000CUL))
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_0_ADDR(base) ((base) + (0x0010UL))
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_1_ADDR(base) ((base) + (0x0014UL))
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_2_ADDR(base) ((base) + (0x0018UL))
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_0_ADDR(base) ((base) + (0x001CUL))
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_1_ADDR(base) ((base) + (0x0020UL))
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_2_ADDR(base) ((base) + (0x0024UL))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_0_ADDR(base) ((base) + (0x0028UL))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_1_ADDR(base) ((base) + (0x002CUL))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_2_ADDR(base) ((base) + (0x0030UL))
#define SOC_SMMUV3_SMMU_MSTR_INPT_SEL_ADDR(base) ((base) + (0x0034UL))
#define SOC_SMMUV3_SMMU_MSTR_RESERVED_0_ADDR(base) ((base) + (0x0038UL))
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_ADDR(base) ((base) + (0x0040UL))
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_ADDR(base) ((base) + (0x0044UL))
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_ADDR(base) ((base) + (0x0048UL))
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_ADDR(base) ((base) + (0x004CUL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_0_ADDR(base) ((base) + (0x0050UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_1_ADDR(base) ((base) + (0x0054UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_2_ADDR(base) ((base) + (0x0058UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_3_ADDR(base) ((base) + (0x005CUL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_ADDR(base) ((base) + (0x0060UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_5_ADDR(base) ((base) + (0x0064UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_6_ADDR(base) ((base) + (0x0068UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_ADDR(base) ((base) + (0x0070UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_1_ADDR(base) ((base) + (0x0074UL))
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_OUT_ADDR(base) ((base) + (0x0078UL))
#define SOC_SMMUV3_SMMU_MSTR_RESERVED_2_ADDR(base) ((base) + (0x007CUL))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_ADDR(base,m) ((base) + ((m)*0x4+0x100UL))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_1_ADDR(base,m) ((base) + ((m)*0x4+0x260UL))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_2_ADDR(base,m) ((base) + ((m)*0x4+0x3C0UL))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_3_ADDR(base,m) ((base) + ((m)*0x4+0x520UL))
#else
#define SOC_SMMUV3_SMMU_MSTR_GLB_BYPASS_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUV3_SMMU_MSTR_DEBUG_MODE_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUV3_SMMU_MSTR_MEM_CTRL_ADDR(base) ((base) + (0x0008))
#define SOC_SMMUV3_SMMU_MSTR_CLK_EN_ADDR(base) ((base) + (0x000C))
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_0_ADDR(base) ((base) + (0x0010))
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_1_ADDR(base) ((base) + (0x0014))
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_2_ADDR(base) ((base) + (0x0018))
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_0_ADDR(base) ((base) + (0x001C))
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_1_ADDR(base) ((base) + (0x0020))
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_2_ADDR(base) ((base) + (0x0024))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_0_ADDR(base) ((base) + (0x0028))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_1_ADDR(base) ((base) + (0x002C))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_2_ADDR(base) ((base) + (0x0030))
#define SOC_SMMUV3_SMMU_MSTR_INPT_SEL_ADDR(base) ((base) + (0x0034))
#define SOC_SMMUV3_SMMU_MSTR_RESERVED_0_ADDR(base) ((base) + (0x0038))
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_ADDR(base) ((base) + (0x0040))
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_ADDR(base) ((base) + (0x0044))
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_ADDR(base) ((base) + (0x0048))
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_ADDR(base) ((base) + (0x004C))
#define SOC_SMMUV3_SMMU_MSTR_DBG_0_ADDR(base) ((base) + (0x0050))
#define SOC_SMMUV3_SMMU_MSTR_DBG_1_ADDR(base) ((base) + (0x0054))
#define SOC_SMMUV3_SMMU_MSTR_DBG_2_ADDR(base) ((base) + (0x0058))
#define SOC_SMMUV3_SMMU_MSTR_DBG_3_ADDR(base) ((base) + (0x005C))
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_ADDR(base) ((base) + (0x0060))
#define SOC_SMMUV3_SMMU_MSTR_DBG_5_ADDR(base) ((base) + (0x0064))
#define SOC_SMMUV3_SMMU_MSTR_DBG_6_ADDR(base) ((base) + (0x0068))
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_ADDR(base) ((base) + (0x0070))
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_1_ADDR(base) ((base) + (0x0074))
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_OUT_ADDR(base) ((base) + (0x0078))
#define SOC_SMMUV3_SMMU_MSTR_RESERVED_2_ADDR(base) ((base) + (0x007C))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_ADDR(base,m) ((base) + ((m)*0x4+0x100))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_1_ADDR(base,m) ((base) + ((m)*0x4+0x260))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_2_ADDR(base,m) ((base) + ((m)*0x4+0x3C0))
#define SOC_SMMUV3_SMMU_MSTR_SMRX_3_ADDR(base,m) ((base) + ((m)*0x4+0x520))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUV3_RD_CMD_TOTAL_CNT_ADDR(base,q) ((base) + ((q)*0x4+0x0UL))
#define SOC_SMMUV3_RD_CMD_MISS_CNT_ADDR(base,q) ((base) + ((q)*0x4+0x160UL))
#define SOC_SMMUV3_RD_DATA_TOTAL_CNT_ADDR(base,q) ((base) + ((q)*0x4+0x2C0UL))
#define SOC_SMMUV3_RD_CMD_CASE_CNT_ADDR(base,s) ((base) + ((s)*0x4+0x420UL))
#define SOC_SMMUV3_RD_CMD_TRANS_LATENCY_ADDR(base) ((base) + (0x0438UL))
#define SOC_SMMUV3_WR_CMD_TOTAL_CNT_ADDR(base,r) ((base) + ((r)*0x4+0x0500UL))
#define SOC_SMMUV3_WR_CMD_MISS_CNT_ADDR(base,r) ((base) + ((r)*0x4+0x660UL))
#define SOC_SMMUV3_WR_DATA_TOTAL_CNT_ADDR(base,r) ((base) + ((r)*0x4+0x7C0UL))
#define SOC_SMMUV3_WR_CMD_CASE_CNT_ADDR(base,s) ((base) + ((s)*0x4+0x920UL))
#define SOC_SMMUV3_WR_CMD_TRANS_LATENCY_ADDR(base) ((base) + (0x0938UL))
#else
#define SOC_SMMUV3_RD_CMD_TOTAL_CNT_ADDR(base,q) ((base) + ((q)*0x4+0x0))
#define SOC_SMMUV3_RD_CMD_MISS_CNT_ADDR(base,q) ((base) + ((q)*0x4+0x160))
#define SOC_SMMUV3_RD_DATA_TOTAL_CNT_ADDR(base,q) ((base) + ((q)*0x4+0x2C0))
#define SOC_SMMUV3_RD_CMD_CASE_CNT_ADDR(base,s) ((base) + ((s)*0x4+0x420))
#define SOC_SMMUV3_RD_CMD_TRANS_LATENCY_ADDR(base) ((base) + (0x0438))
#define SOC_SMMUV3_WR_CMD_TOTAL_CNT_ADDR(base,r) ((base) + ((r)*0x4+0x0500))
#define SOC_SMMUV3_WR_CMD_MISS_CNT_ADDR(base,r) ((base) + ((r)*0x4+0x660))
#define SOC_SMMUV3_WR_DATA_TOTAL_CNT_ADDR(base,r) ((base) + ((r)*0x4+0x7C0))
#define SOC_SMMUV3_WR_CMD_CASE_CNT_ADDR(base,s) ((base) + ((s)*0x4+0x920))
#define SOC_SMMUV3_WR_CMD_TRANS_LATENCY_ADDR(base) ((base) + (0x0938))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUV3_SMMU_IDR0_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUV3_SMMU_IDR1_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUV3_SMMU_IDR2_ADDR(base) ((base) + (0x0008UL))
#define SOC_SMMUV3_SMMU_IDR3_ADDR(base) ((base) + (0x000CUL))
#define SOC_SMMUV3_SMMU_IDR4_ADDR(base) ((base) + (0x0010UL))
#define SOC_SMMUV3_SMMU_IDR5_ADDR(base) ((base) + (0x0014UL))
#define SOC_SMMUV3_SMMU_IIDR_ADDR(base) ((base) + (0x0018UL))
#define SOC_SMMUV3_SMMU_AIDR_ADDR(base) ((base) + (0x001CUL))
#define SOC_SMMUV3_SMMU_CR0_ADDR(base) ((base) + (0x0020UL))
#define SOC_SMMUV3_SMMU_CR0ACK_ADDR(base) ((base) + (0x0024UL))
#define SOC_SMMUV3_SMMU_CR1_ADDR(base) ((base) + (0x0028UL))
#define SOC_SMMUV3_SMMU_CR2_ADDR(base) ((base) + (0x002CUL))
#define SOC_SMMUV3_SMMU_STATUSR_ADDR(base) ((base) + (0x0040UL))
#define SOC_SMMUV3_SMMU_GBPA_ADDR(base) ((base) + (0x0044UL))
#define SOC_SMMUV3_SMMU_AGBPA_ADDR(base) ((base) + (0x0048UL))
#define SOC_SMMUV3_SMMU_IRQ_CTRL_ADDR(base) ((base) + (0x0050UL))
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_ADDR(base) ((base) + (0x0054UL))
#define SOC_SMMUV3_SMMU_GERROR_ADDR(base) ((base) + (0x0060UL))
#define SOC_SMMUV3_SMMU_GERRORN_ADDR(base) ((base) + (0x0064UL))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x0068UL))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x006CUL))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x0070UL))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x0074UL))
#define SOC_SMMUV3_SMMU_STRTAB_BASE0_ADDR(base) ((base) + (0x0080UL))
#define SOC_SMMUV3_SMMU_STRTAB_BASE1_ADDR(base) ((base) + (0x0084UL))
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x0088UL))
#define SOC_SMMUV3_SMMU_CMDQ_BASE0_ADDR(base) ((base) + (0x0090UL))
#define SOC_SMMUV3_SMMU_CMDQ_BASE1_ADDR(base) ((base) + (0x0094UL))
#define SOC_SMMUV3_SMMU_CMDQ_PROD_ADDR(base) ((base) + (0x0098UL))
#define SOC_SMMUV3_SMMU_CMDQ_CONS_ADDR(base) ((base) + (0x009CUL))
#define SOC_SMMUV3_SMMU_EVENTQ_BASE0_ADDR(base) ((base) + (0x00A0UL))
#define SOC_SMMUV3_SMMU_EVENTQ_BASE1_ADDR(base) ((base) + (0x00A4UL))
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_ADDR(base) ((base) + (0x100A8UL))
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_ADDR(base) ((base) + (0x100ACUL))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00B0UL))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00B4UL))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x00B8UL))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x00BCUL))
#define SOC_SMMUV3_SMMU_PRIQ_BASE0_ADDR(base) ((base) + (0x00C0UL))
#define SOC_SMMUV3_SMMU_PRIQ_BASE1_ADDR(base) ((base) + (0x00C4UL))
#define SOC_SMMUV3_SMMU_PRIQ_PROD_ADDR(base) ((base) + (0x100C8UL))
#define SOC_SMMUV3_SMMU_PRIQ_CONS_ADDR(base) ((base) + (0x100CCUL))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00D0UL))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00D4UL))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG1_ADDR(base) ((base) + (0x00D8UL))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG2_ADDR(base) ((base) + (0x00DCUL))
#define SOC_SMMUV3_SMMU_PIDR4_ADDR(base) ((base) + (0x0FD0UL))
#define SOC_SMMUV3_SMMU_PIDR5_ADDR(base) ((base) + (0x0FD4UL))
#define SOC_SMMUV3_SMMU_PIDR6_ADDR(base) ((base) + (0x0FD8UL))
#define SOC_SMMUV3_SMMU_PIDR7_ADDR(base) ((base) + (0x0FDCUL))
#define SOC_SMMUV3_SMMU_PIDR0_ADDR(base) ((base) + (0x0FE0UL))
#define SOC_SMMUV3_SMMU_PIDR1_ADDR(base) ((base) + (0x0FE4UL))
#define SOC_SMMUV3_SMMU_PIDR2_ADDR(base) ((base) + (0x0FE8UL))
#define SOC_SMMUV3_SMMU_PIDR3_ADDR(base) ((base) + (0x0FECUL))
#define SOC_SMMUV3_SMMU_CIDR0_ADDR(base) ((base) + (0x0FF0UL))
#define SOC_SMMUV3_SMMU_CIDR1_ADDR(base) ((base) + (0x0FF4UL))
#define SOC_SMMUV3_SMMU_CIDR2_ADDR(base) ((base) + (0x0FF8UL))
#define SOC_SMMUV3_SMMU_CIDR3_ADDR(base) ((base) + (0x0FFCUL))
#define SOC_SMMUV3_SMMU_PMCG_EVCNTR_ADDR(base,i) ((base) + (0x22000+(i)*4UL))
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_ADDR(base) ((base) + (0x2400UL))
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER_ADDR(base,t) ((base) + (0x2404+(t)*4UL))
#define SOC_SMMUV3_SMMU_PMCG_SVR_ADDR(base,i) ((base) + (0x22600+(i)*4UL))
#define SOC_SMMUV3_SMMU_PMCG_SMR_ADDR(base,j) ((base) + (0x2A00+(j)*4UL))
#define SOC_SMMUV3_SMMU_PMCG_CNTENSET0_0_ADDR(base) ((base) + (0x2C00UL))
#define SOC_SMMUV3_SMMU_PMCG_CNTENSET0_1_ADDR(base) ((base) + (0x2C04UL))
#define SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_0_ADDR(base) ((base) + (0x2C20UL))
#define SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_1_ADDR(base) ((base) + (0x2C24UL))
#define SOC_SMMUV3_SMMU_PMCG_INTENSET0_0_ADDR(base) ((base) + (0x2C40UL))
#define SOC_SMMUV3_SMMU_PMCG_INTENSET0_1_ADDR(base) ((base) + (0x2C44UL))
#define SOC_SMMUV3_SMMU_PMCG_INTENCLR0_0_ADDR(base) ((base) + (0x2C60UL))
#define SOC_SMMUV3_SMMU_PMCG_INTENCLR0_1_ADDR(base) ((base) + (0x2C64UL))
#define SOC_SMMUV3_SMMU_PMCG_OVSCLR0_0_ADDR(base) ((base) + (0x22C80UL))
#define SOC_SMMUV3_SMMU_PMCG_OVSCLR0_1_ADDR(base) ((base) + (0x22C84UL))
#define SOC_SMMUV3_SMMU_PMCG_OVSSET0_0_ADDR(base) ((base) + (0x22CC0UL))
#define SOC_SMMUV3_SMMU_PMCG_OVSSET0_1_ADDR(base) ((base) + (0x22CC4UL))
#define SOC_SMMUV3_SMMU_PMCG_CAPR_ADDR(base) ((base) + (0x22D88UL))
#define SOC_SMMUV3_SMMU_PMCG_SCR_ADDR(base) ((base) + (0x2DF8UL))
#define SOC_SMMUV3_SMMU_PMCG_CFGR_ADDR(base) ((base) + (0x2E00UL))
#define SOC_SMMUV3_SMMU_PMCG_CR_ADDR(base) ((base) + (0x2E04UL))
#define SOC_SMMUV3_SMMU_PMCG_CEID0_0_ADDR(base) ((base) + (0x2E20UL))
#define SOC_SMMUV3_SMMU_PMCG_CEID0_1_ADDR(base) ((base) + (0x2E24UL))
#define SOC_SMMUV3_SMMU_PMCG_CEID1_0_ADDR(base) ((base) + (0x2E28UL))
#define SOC_SMMUV3_SMMU_PMCG_CEID1_1_ADDR(base) ((base) + (0x2E2CUL))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRL_ADDR(base) ((base) + (0x2E50UL))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRLACK_ADDR(base) ((base) + (0x2E54UL))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG0_0_ADDR(base) ((base) + (0x2E58UL))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG0_1_ADDR(base) ((base) + (0x2E5CUL))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG1_ADDR(base) ((base) + (0x2E60UL))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG2_ADDR(base) ((base) + (0x2E64UL))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_STATUS_ADDR(base) ((base) + (0x2E68UL))
#define SOC_SMMUV3_SMMU_PMCG_AIDR_ADDR(base) ((base) + (0x2E70UL))
#define SOC_SMMUV3_SMMU_PMCG_PMAUTHSTATUS_ADDR(base) ((base) + (0x2FB8UL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR4_ADDR(base) ((base) + (0x2FD0UL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR5_ADDR(base) ((base) + (0x2FD4UL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR6_ADDR(base) ((base) + (0x2FD8UL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR7_ADDR(base) ((base) + (0x2FDCUL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR0_ADDR(base) ((base) + (0x2FE0UL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR1_ADDR(base) ((base) + (0x2FE4UL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR2_ADDR(base) ((base) + (0x2FE8UL))
#define SOC_SMMUV3_SMMU_PMCG_PIDR3_ADDR(base) ((base) + (0x2FECUL))
#define SOC_SMMUV3_SMMU_PMCG_CIDR0_ADDR(base) ((base) + (0x2FF0UL))
#define SOC_SMMUV3_SMMU_PMCG_CIDR1_ADDR(base) ((base) + (0x2FF4UL))
#define SOC_SMMUV3_SMMU_PMCG_CIDR2_ADDR(base) ((base) + (0x2FF8UL))
#define SOC_SMMUV3_SMMU_PMCG_CIDR3_ADDR(base) ((base) + (0x2FFCUL))
#define SOC_SMMUV3_SMMU_S_IDR0_ADDR(base) ((base) + (0x8000UL))
#define SOC_SMMUV3_SMMU_S_IDR1_ADDR(base) ((base) + (0x8004UL))
#define SOC_SMMUV3_SMMU_S_IDR2_ADDR(base) ((base) + (0x8008UL))
#define SOC_SMMUV3_SMMU_S_IDR3_ADDR(base) ((base) + (0x800CUL))
#define SOC_SMMUV3_SMMU_S_IDR4_ADDR(base) ((base) + (0x8010UL))
#define SOC_SMMUV3_SMMU_S_CR0_ADDR(base) ((base) + (0x8020UL))
#define SOC_SMMUV3_SMMU_S_CR0ACK_ADDR(base) ((base) + (0x8024UL))
#define SOC_SMMUV3_SMMU_S_CR1_ADDR(base) ((base) + (0x8028UL))
#define SOC_SMMUV3_SMMU_S_CR2_ADDR(base) ((base) + (0x802CUL))
#define SOC_SMMUV3_SMMU_S_INIT_ADDR(base) ((base) + (0x803CUL))
#define SOC_SMMUV3_SMMU_S_GBPA_ADDR(base) ((base) + (0x8044UL))
#define SOC_SMMUV3_SMMU_S_AGBPA_ADDR(base) ((base) + (0x8048UL))
#define SOC_SMMUV3_SMMU_S_IRQ_CTRL_ADDR(base) ((base) + (0x8050UL))
#define SOC_SMMUV3_SMMU_S_IRQ_CTRLACK_ADDR(base) ((base) + (0x8054UL))
#define SOC_SMMUV3_SMMU_S_GERROR_ADDR(base) ((base) + (0x8060UL))
#define SOC_SMMUV3_SMMU_S_GERRORN_ADDR(base) ((base) + (0x8064UL))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x8068UL))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x806CUL))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x8070UL))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x8074UL))
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE0_ADDR(base) ((base) + (0x8080UL))
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE1_ADDR(base) ((base) + (0x8084UL))
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x8088UL))
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE0_ADDR(base) ((base) + (0x8090UL))
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE1_ADDR(base) ((base) + (0x8094UL))
#define SOC_SMMUV3_SMMU_S_CMDQ_PROD_ADDR(base) ((base) + (0x8098UL))
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_ADDR(base) ((base) + (0x809CUL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE0_ADDR(base) ((base) + (0x80A0UL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE1_ADDR(base) ((base) + (0x80A4UL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_ADDR(base) ((base) + (0x80A8UL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_ADDR(base) ((base) + (0x80ACUL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x80B0UL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x80B4UL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x80B8UL))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x80BCUL))
#define SOC_SMMUV3_SMMU_TCU_CTRL_ADDR(base) ((base) + (0x8E00UL))
#define SOC_SMMUV3_SMMU_TCU_QOS_ADDR(base) ((base) + (0x8E04UL))
#define SOC_SMMUV3_SMMU_TCU_CFG_ADDR(base) ((base) + (0x8E08UL))
#define SOC_SMMUV3_SMMU_TCU_STATUS_ADDR(base) ((base) + (0x8E10UL))
#define SOC_SMMUV3_SMMU_TCU_SCR_ADDR(base) ((base) + (0x8E18UL))
#define SOC_SMMUV3_SMMU_TCU_ERRFR_ADDR(base) ((base) + (0x8E80UL))
#define SOC_SMMUV3_SMMU_TCU_ERRCTRL_ADDR(base) ((base) + (0x8E88UL))
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_ADDR(base) ((base) + (0x8E90UL))
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_ADDR(base) ((base) + (0x8EC0UL))
#define SOC_SMMUV3_SMMU_TCU_NODE_CTRL_ADDR(base,n) ((base) + (0x9000+(n)*4UL))
#define SOC_SMMUV3_SMMU_TCU_NODE_STATUS_ADDR(base,n) ((base) + (0x9400+(n)*4UL))
#else
#define SOC_SMMUV3_SMMU_IDR0_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUV3_SMMU_IDR1_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUV3_SMMU_IDR2_ADDR(base) ((base) + (0x0008))
#define SOC_SMMUV3_SMMU_IDR3_ADDR(base) ((base) + (0x000C))
#define SOC_SMMUV3_SMMU_IDR4_ADDR(base) ((base) + (0x0010))
#define SOC_SMMUV3_SMMU_IDR5_ADDR(base) ((base) + (0x0014))
#define SOC_SMMUV3_SMMU_IIDR_ADDR(base) ((base) + (0x0018))
#define SOC_SMMUV3_SMMU_AIDR_ADDR(base) ((base) + (0x001C))
#define SOC_SMMUV3_SMMU_CR0_ADDR(base) ((base) + (0x0020))
#define SOC_SMMUV3_SMMU_CR0ACK_ADDR(base) ((base) + (0x0024))
#define SOC_SMMUV3_SMMU_CR1_ADDR(base) ((base) + (0x0028))
#define SOC_SMMUV3_SMMU_CR2_ADDR(base) ((base) + (0x002C))
#define SOC_SMMUV3_SMMU_STATUSR_ADDR(base) ((base) + (0x0040))
#define SOC_SMMUV3_SMMU_GBPA_ADDR(base) ((base) + (0x0044))
#define SOC_SMMUV3_SMMU_AGBPA_ADDR(base) ((base) + (0x0048))
#define SOC_SMMUV3_SMMU_IRQ_CTRL_ADDR(base) ((base) + (0x0050))
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_ADDR(base) ((base) + (0x0054))
#define SOC_SMMUV3_SMMU_GERROR_ADDR(base) ((base) + (0x0060))
#define SOC_SMMUV3_SMMU_GERRORN_ADDR(base) ((base) + (0x0064))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x0068))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x006C))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x0070))
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x0074))
#define SOC_SMMUV3_SMMU_STRTAB_BASE0_ADDR(base) ((base) + (0x0080))
#define SOC_SMMUV3_SMMU_STRTAB_BASE1_ADDR(base) ((base) + (0x0084))
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x0088))
#define SOC_SMMUV3_SMMU_CMDQ_BASE0_ADDR(base) ((base) + (0x0090))
#define SOC_SMMUV3_SMMU_CMDQ_BASE1_ADDR(base) ((base) + (0x0094))
#define SOC_SMMUV3_SMMU_CMDQ_PROD_ADDR(base) ((base) + (0x0098))
#define SOC_SMMUV3_SMMU_CMDQ_CONS_ADDR(base) ((base) + (0x009C))
#define SOC_SMMUV3_SMMU_EVENTQ_BASE0_ADDR(base) ((base) + (0x00A0))
#define SOC_SMMUV3_SMMU_EVENTQ_BASE1_ADDR(base) ((base) + (0x00A4))
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_ADDR(base) ((base) + (0x100A8))
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_ADDR(base) ((base) + (0x100AC))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00B0))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00B4))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x00B8))
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x00BC))
#define SOC_SMMUV3_SMMU_PRIQ_BASE0_ADDR(base) ((base) + (0x00C0))
#define SOC_SMMUV3_SMMU_PRIQ_BASE1_ADDR(base) ((base) + (0x00C4))
#define SOC_SMMUV3_SMMU_PRIQ_PROD_ADDR(base) ((base) + (0x100C8))
#define SOC_SMMUV3_SMMU_PRIQ_CONS_ADDR(base) ((base) + (0x100CC))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x00D0))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x00D4))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG1_ADDR(base) ((base) + (0x00D8))
#define SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG2_ADDR(base) ((base) + (0x00DC))
#define SOC_SMMUV3_SMMU_PIDR4_ADDR(base) ((base) + (0x0FD0))
#define SOC_SMMUV3_SMMU_PIDR5_ADDR(base) ((base) + (0x0FD4))
#define SOC_SMMUV3_SMMU_PIDR6_ADDR(base) ((base) + (0x0FD8))
#define SOC_SMMUV3_SMMU_PIDR7_ADDR(base) ((base) + (0x0FDC))
#define SOC_SMMUV3_SMMU_PIDR0_ADDR(base) ((base) + (0x0FE0))
#define SOC_SMMUV3_SMMU_PIDR1_ADDR(base) ((base) + (0x0FE4))
#define SOC_SMMUV3_SMMU_PIDR2_ADDR(base) ((base) + (0x0FE8))
#define SOC_SMMUV3_SMMU_PIDR3_ADDR(base) ((base) + (0x0FEC))
#define SOC_SMMUV3_SMMU_CIDR0_ADDR(base) ((base) + (0x0FF0))
#define SOC_SMMUV3_SMMU_CIDR1_ADDR(base) ((base) + (0x0FF4))
#define SOC_SMMUV3_SMMU_CIDR2_ADDR(base) ((base) + (0x0FF8))
#define SOC_SMMUV3_SMMU_CIDR3_ADDR(base) ((base) + (0x0FFC))
#define SOC_SMMUV3_SMMU_PMCG_EVCNTR_ADDR(base,i) ((base) + (0x22000+(i)*4))
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_ADDR(base) ((base) + (0x2400))
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER_ADDR(base,t) ((base) + (0x2404+(t)*4))
#define SOC_SMMUV3_SMMU_PMCG_SVR_ADDR(base,i) ((base) + (0x22600+(i)*4))
#define SOC_SMMUV3_SMMU_PMCG_SMR_ADDR(base,j) ((base) + (0x2A00+(j)*4))
#define SOC_SMMUV3_SMMU_PMCG_CNTENSET0_0_ADDR(base) ((base) + (0x2C00))
#define SOC_SMMUV3_SMMU_PMCG_CNTENSET0_1_ADDR(base) ((base) + (0x2C04))
#define SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_0_ADDR(base) ((base) + (0x2C20))
#define SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_1_ADDR(base) ((base) + (0x2C24))
#define SOC_SMMUV3_SMMU_PMCG_INTENSET0_0_ADDR(base) ((base) + (0x2C40))
#define SOC_SMMUV3_SMMU_PMCG_INTENSET0_1_ADDR(base) ((base) + (0x2C44))
#define SOC_SMMUV3_SMMU_PMCG_INTENCLR0_0_ADDR(base) ((base) + (0x2C60))
#define SOC_SMMUV3_SMMU_PMCG_INTENCLR0_1_ADDR(base) ((base) + (0x2C64))
#define SOC_SMMUV3_SMMU_PMCG_OVSCLR0_0_ADDR(base) ((base) + (0x22C80))
#define SOC_SMMUV3_SMMU_PMCG_OVSCLR0_1_ADDR(base) ((base) + (0x22C84))
#define SOC_SMMUV3_SMMU_PMCG_OVSSET0_0_ADDR(base) ((base) + (0x22CC0))
#define SOC_SMMUV3_SMMU_PMCG_OVSSET0_1_ADDR(base) ((base) + (0x22CC4))
#define SOC_SMMUV3_SMMU_PMCG_CAPR_ADDR(base) ((base) + (0x22D88))
#define SOC_SMMUV3_SMMU_PMCG_SCR_ADDR(base) ((base) + (0x2DF8))
#define SOC_SMMUV3_SMMU_PMCG_CFGR_ADDR(base) ((base) + (0x2E00))
#define SOC_SMMUV3_SMMU_PMCG_CR_ADDR(base) ((base) + (0x2E04))
#define SOC_SMMUV3_SMMU_PMCG_CEID0_0_ADDR(base) ((base) + (0x2E20))
#define SOC_SMMUV3_SMMU_PMCG_CEID0_1_ADDR(base) ((base) + (0x2E24))
#define SOC_SMMUV3_SMMU_PMCG_CEID1_0_ADDR(base) ((base) + (0x2E28))
#define SOC_SMMUV3_SMMU_PMCG_CEID1_1_ADDR(base) ((base) + (0x2E2C))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRL_ADDR(base) ((base) + (0x2E50))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRLACK_ADDR(base) ((base) + (0x2E54))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG0_0_ADDR(base) ((base) + (0x2E58))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG0_1_ADDR(base) ((base) + (0x2E5C))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG1_ADDR(base) ((base) + (0x2E60))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CFG2_ADDR(base) ((base) + (0x2E64))
#define SOC_SMMUV3_SMMU_PMCG_IRQ_STATUS_ADDR(base) ((base) + (0x2E68))
#define SOC_SMMUV3_SMMU_PMCG_AIDR_ADDR(base) ((base) + (0x2E70))
#define SOC_SMMUV3_SMMU_PMCG_PMAUTHSTATUS_ADDR(base) ((base) + (0x2FB8))
#define SOC_SMMUV3_SMMU_PMCG_PIDR4_ADDR(base) ((base) + (0x2FD0))
#define SOC_SMMUV3_SMMU_PMCG_PIDR5_ADDR(base) ((base) + (0x2FD4))
#define SOC_SMMUV3_SMMU_PMCG_PIDR6_ADDR(base) ((base) + (0x2FD8))
#define SOC_SMMUV3_SMMU_PMCG_PIDR7_ADDR(base) ((base) + (0x2FDC))
#define SOC_SMMUV3_SMMU_PMCG_PIDR0_ADDR(base) ((base) + (0x2FE0))
#define SOC_SMMUV3_SMMU_PMCG_PIDR1_ADDR(base) ((base) + (0x2FE4))
#define SOC_SMMUV3_SMMU_PMCG_PIDR2_ADDR(base) ((base) + (0x2FE8))
#define SOC_SMMUV3_SMMU_PMCG_PIDR3_ADDR(base) ((base) + (0x2FEC))
#define SOC_SMMUV3_SMMU_PMCG_CIDR0_ADDR(base) ((base) + (0x2FF0))
#define SOC_SMMUV3_SMMU_PMCG_CIDR1_ADDR(base) ((base) + (0x2FF4))
#define SOC_SMMUV3_SMMU_PMCG_CIDR2_ADDR(base) ((base) + (0x2FF8))
#define SOC_SMMUV3_SMMU_PMCG_CIDR3_ADDR(base) ((base) + (0x2FFC))
#define SOC_SMMUV3_SMMU_S_IDR0_ADDR(base) ((base) + (0x8000))
#define SOC_SMMUV3_SMMU_S_IDR1_ADDR(base) ((base) + (0x8004))
#define SOC_SMMUV3_SMMU_S_IDR2_ADDR(base) ((base) + (0x8008))
#define SOC_SMMUV3_SMMU_S_IDR3_ADDR(base) ((base) + (0x800C))
#define SOC_SMMUV3_SMMU_S_IDR4_ADDR(base) ((base) + (0x8010))
#define SOC_SMMUV3_SMMU_S_CR0_ADDR(base) ((base) + (0x8020))
#define SOC_SMMUV3_SMMU_S_CR0ACK_ADDR(base) ((base) + (0x8024))
#define SOC_SMMUV3_SMMU_S_CR1_ADDR(base) ((base) + (0x8028))
#define SOC_SMMUV3_SMMU_S_CR2_ADDR(base) ((base) + (0x802C))
#define SOC_SMMUV3_SMMU_S_INIT_ADDR(base) ((base) + (0x803C))
#define SOC_SMMUV3_SMMU_S_GBPA_ADDR(base) ((base) + (0x8044))
#define SOC_SMMUV3_SMMU_S_AGBPA_ADDR(base) ((base) + (0x8048))
#define SOC_SMMUV3_SMMU_S_IRQ_CTRL_ADDR(base) ((base) + (0x8050))
#define SOC_SMMUV3_SMMU_S_IRQ_CTRLACK_ADDR(base) ((base) + (0x8054))
#define SOC_SMMUV3_SMMU_S_GERROR_ADDR(base) ((base) + (0x8060))
#define SOC_SMMUV3_SMMU_S_GERRORN_ADDR(base) ((base) + (0x8064))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_0_ADDR(base) ((base) + (0x8068))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_1_ADDR(base) ((base) + (0x806C))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG1_ADDR(base) ((base) + (0x8070))
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG2_ADDR(base) ((base) + (0x8074))
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE0_ADDR(base) ((base) + (0x8080))
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE1_ADDR(base) ((base) + (0x8084))
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_ADDR(base) ((base) + (0x8088))
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE0_ADDR(base) ((base) + (0x8090))
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE1_ADDR(base) ((base) + (0x8094))
#define SOC_SMMUV3_SMMU_S_CMDQ_PROD_ADDR(base) ((base) + (0x8098))
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_ADDR(base) ((base) + (0x809C))
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE0_ADDR(base) ((base) + (0x80A0))
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE1_ADDR(base) ((base) + (0x80A4))
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_ADDR(base) ((base) + (0x80A8))
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_ADDR(base) ((base) + (0x80AC))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_0_ADDR(base) ((base) + (0x80B0))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_1_ADDR(base) ((base) + (0x80B4))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG1_ADDR(base) ((base) + (0x80B8))
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG2_ADDR(base) ((base) + (0x80BC))
#define SOC_SMMUV3_SMMU_TCU_CTRL_ADDR(base) ((base) + (0x8E00))
#define SOC_SMMUV3_SMMU_TCU_QOS_ADDR(base) ((base) + (0x8E04))
#define SOC_SMMUV3_SMMU_TCU_CFG_ADDR(base) ((base) + (0x8E08))
#define SOC_SMMUV3_SMMU_TCU_STATUS_ADDR(base) ((base) + (0x8E10))
#define SOC_SMMUV3_SMMU_TCU_SCR_ADDR(base) ((base) + (0x8E18))
#define SOC_SMMUV3_SMMU_TCU_ERRFR_ADDR(base) ((base) + (0x8E80))
#define SOC_SMMUV3_SMMU_TCU_ERRCTRL_ADDR(base) ((base) + (0x8E88))
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_ADDR(base) ((base) + (0x8E90))
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_ADDR(base) ((base) + (0x8EC0))
#define SOC_SMMUV3_SMMU_TCU_NODE_CTRL_ADDR(base,n) ((base) + (0x9000+(n)*4))
#define SOC_SMMUV3_SMMU_TCU_NODE_STATUS_ADDR(base,n) ((base) + (0x9400+(n)*4))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUV3_SMMU_TBU_CR_ADDR(base) ((base) + (0x0000UL))
#define SOC_SMMUV3_SMMU_TBU_CRACK_ADDR(base) ((base) + (0x0004UL))
#define SOC_SMMUV3_SMMU_TBU_SCR_ADDR(base) ((base) + (0x8E18UL))
#define SOC_SMMUV3_SMMU_TBU_PIDR4_ADDR(base) ((base) + (0x0FD0UL))
#define SOC_SMMUV3_SMMU_TBU_PIDR5_ADDR(base) ((base) + (0x0FD4UL))
#define SOC_SMMUV3_SMMU_TBU_PIDR6_ADDR(base) ((base) + (0x0FD8UL))
#define SOC_SMMUV3_SMMU_TBU_PIDR7_ADDR(base) ((base) + (0x0FDCUL))
#define SOC_SMMUV3_SMMU_TBU_PIDR0_ADDR(base) ((base) + (0x0FE0UL))
#define SOC_SMMUV3_SMMU_TBU_PIDR1_ADDR(base) ((base) + (0x0FE4UL))
#define SOC_SMMUV3_SMMU_TBU_PIDR2_ADDR(base) ((base) + (0x0FE8UL))
#define SOC_SMMUV3_SMMU_TBU_PIDR3_ADDR(base) ((base) + (0x0FECUL))
#define SOC_SMMUV3_SMMU_TBU_CIDR0_ADDR(base) ((base) + (0x0FF0UL))
#define SOC_SMMUV3_SMMU_TBU_CIDR1_ADDR(base) ((base) + (0x0FF4UL))
#define SOC_SMMUV3_SMMU_TBU_CIDR2_ADDR(base) ((base) + (0x0FF8UL))
#define SOC_SMMUV3_SMMU_TBU_CIDR3_ADDR(base) ((base) + (0x0FFCUL))
#else
#define SOC_SMMUV3_SMMU_TBU_CR_ADDR(base) ((base) + (0x0000))
#define SOC_SMMUV3_SMMU_TBU_CRACK_ADDR(base) ((base) + (0x0004))
#define SOC_SMMUV3_SMMU_TBU_SCR_ADDR(base) ((base) + (0x8E18))
#define SOC_SMMUV3_SMMU_TBU_PIDR4_ADDR(base) ((base) + (0x0FD0))
#define SOC_SMMUV3_SMMU_TBU_PIDR5_ADDR(base) ((base) + (0x0FD4))
#define SOC_SMMUV3_SMMU_TBU_PIDR6_ADDR(base) ((base) + (0x0FD8))
#define SOC_SMMUV3_SMMU_TBU_PIDR7_ADDR(base) ((base) + (0x0FDC))
#define SOC_SMMUV3_SMMU_TBU_PIDR0_ADDR(base) ((base) + (0x0FE0))
#define SOC_SMMUV3_SMMU_TBU_PIDR1_ADDR(base) ((base) + (0x0FE4))
#define SOC_SMMUV3_SMMU_TBU_PIDR2_ADDR(base) ((base) + (0x0FE8))
#define SOC_SMMUV3_SMMU_TBU_PIDR3_ADDR(base) ((base) + (0x0FEC))
#define SOC_SMMUV3_SMMU_TBU_CIDR0_ADDR(base) ((base) + (0x0FF0))
#define SOC_SMMUV3_SMMU_TBU_CIDR1_ADDR(base) ((base) + (0x0FF4))
#define SOC_SMMUV3_SMMU_TBU_CIDR2_ADDR(base) ((base) + (0x0FF8))
#define SOC_SMMUV3_SMMU_TBU_CIDR3_ADDR(base) ((base) + (0x0FFC))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVCNTR_ADDR(base,k) ((base) + (0x10000+(k)*4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_ADDR(base) ((base) + (0x400UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER_ADDR(base,u) ((base) + (0x404+(u)*4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_SVR_ADDR(base,k) ((base) + (0x10600+(k)*4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_SMR_ADDR(base,l) ((base) + (0xA00+(l)*4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_0_ADDR(base) ((base) + (0xC00UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_1_ADDR(base) ((base) + (0xC04UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_0_ADDR(base) ((base) + (0xC20UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_1_ADDR(base) ((base) + (0xC24UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_0_ADDR(base) ((base) + (0xC40UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_1_ADDR(base) ((base) + (0xC44UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_0_ADDR(base) ((base) + (0xC60UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_1_ADDR(base) ((base) + (0xC64UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_0_ADDR(base) ((base) + (0x10C80UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_1_ADDR(base) ((base) + (0x10C84UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_0_ADDR(base) ((base) + (0x10CC0UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_1_ADDR(base) ((base) + (0x10CC4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CAPR_ADDR(base) ((base) + (0x10D88UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_ADDR(base) ((base) + (0xDF8UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_ADDR(base) ((base) + (0xE00UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CR_ADDR(base) ((base) + (0xE04UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_0_ADDR(base) ((base) + (0xE20UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_1_ADDR(base) ((base) + (0xE24UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_0_ADDR(base) ((base) + (0xE28UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_1_ADDR(base) ((base) + (0xE2CUL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRL_ADDR(base) ((base) + (0xE50UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRLACK_ADDR(base) ((base) + (0xE54UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG0_0_ADDR(base) ((base) + (0xE58UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG0_1_ADDR(base) ((base) + (0xE5CUL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG1_ADDR(base) ((base) + (0xE60UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG2_ADDR(base) ((base) + (0xE64UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_STATUS_ADDR(base) ((base) + (0xE68UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_AIDR_ADDR(base) ((base) + (0xE70UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PMAUTHSTATUS_ADDR(base) ((base) + (0xFB8UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR4_ADDR(base) ((base) + (0xFD0UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR5_ADDR(base) ((base) + (0xFD4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR6_ADDR(base) ((base) + (0xFD8UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR7_ADDR(base) ((base) + (0xFDCUL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR0_ADDR(base) ((base) + (0xFE0UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR1_ADDR(base) ((base) + (0xFE4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR2_ADDR(base) ((base) + (0xFE8UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR3_ADDR(base) ((base) + (0xFECUL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR0_ADDR(base) ((base) + (0xFF0UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR1_ADDR(base) ((base) + (0xFF4UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR2_ADDR(base) ((base) + (0xFF8UL))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR3_ADDR(base) ((base) + (0xFFCUL))
#else
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVCNTR_ADDR(base,k) ((base) + (0x10000+(k)*4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_ADDR(base) ((base) + (0x400))
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER_ADDR(base,u) ((base) + (0x404+(u)*4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_SVR_ADDR(base,k) ((base) + (0x10600+(k)*4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_SMR_ADDR(base,l) ((base) + (0xA00+(l)*4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_0_ADDR(base) ((base) + (0xC00))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_1_ADDR(base) ((base) + (0xC04))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_0_ADDR(base) ((base) + (0xC20))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_1_ADDR(base) ((base) + (0xC24))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_0_ADDR(base) ((base) + (0xC40))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_1_ADDR(base) ((base) + (0xC44))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_0_ADDR(base) ((base) + (0xC60))
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_1_ADDR(base) ((base) + (0xC64))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_0_ADDR(base) ((base) + (0x10C80))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_1_ADDR(base) ((base) + (0x10C84))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_0_ADDR(base) ((base) + (0x10CC0))
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_1_ADDR(base) ((base) + (0x10CC4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CAPR_ADDR(base) ((base) + (0x10D88))
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_ADDR(base) ((base) + (0xDF8))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_ADDR(base) ((base) + (0xE00))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CR_ADDR(base) ((base) + (0xE04))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_0_ADDR(base) ((base) + (0xE20))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_1_ADDR(base) ((base) + (0xE24))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_0_ADDR(base) ((base) + (0xE28))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_1_ADDR(base) ((base) + (0xE2C))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRL_ADDR(base) ((base) + (0xE50))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRLACK_ADDR(base) ((base) + (0xE54))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG0_0_ADDR(base) ((base) + (0xE58))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG0_1_ADDR(base) ((base) + (0xE5C))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG1_ADDR(base) ((base) + (0xE60))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG2_ADDR(base) ((base) + (0xE64))
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_STATUS_ADDR(base) ((base) + (0xE68))
#define SOC_SMMUV3_SMMU_TBU_PMCG_AIDR_ADDR(base) ((base) + (0xE70))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PMAUTHSTATUS_ADDR(base) ((base) + (0xFB8))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR4_ADDR(base) ((base) + (0xFD0))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR5_ADDR(base) ((base) + (0xFD4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR6_ADDR(base) ((base) + (0xFD8))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR7_ADDR(base) ((base) + (0xFDC))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR0_ADDR(base) ((base) + (0xFE0))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR1_ADDR(base) ((base) + (0xFE4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR2_ADDR(base) ((base) + (0xFE8))
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR3_ADDR(base) ((base) + (0xFEC))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR0_ADDR(base) ((base) + (0xFF0))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR1_ADDR(base) ((base) + (0xFF4))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR2_ADDR(base) ((base) + (0xFF8))
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR3_ADDR(base) ((base) + (0xFFC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_qreqn_cg : 1;
        unsigned int tcu_qreqn_pd : 1;
        unsigned int tbu0_qreqn_cg : 1;
        unsigned int tbu0_qreqn_pd : 1;
        unsigned int tbu1_qreqn_cg : 1;
        unsigned int tbu1_qreqn_pd : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUV3_SMMU_LP_REQ_UNION;
#endif
#define SOC_SMMUV3_SMMU_LP_REQ_tcu_qreqn_cg_START (0)
#define SOC_SMMUV3_SMMU_LP_REQ_tcu_qreqn_cg_END (0)
#define SOC_SMMUV3_SMMU_LP_REQ_tcu_qreqn_pd_START (1)
#define SOC_SMMUV3_SMMU_LP_REQ_tcu_qreqn_pd_END (1)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu0_qreqn_cg_START (2)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu0_qreqn_cg_END (2)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu0_qreqn_pd_START (3)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu0_qreqn_pd_END (3)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu1_qreqn_cg_START (4)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu1_qreqn_cg_END (4)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu1_qreqn_pd_START (5)
#define SOC_SMMUV3_SMMU_LP_REQ_tbu1_qreqn_pd_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_qacceptn_cg : 1;
        unsigned int tcu_qdeny_cg : 1;
        unsigned int tcu_qactive_cg : 1;
        unsigned int reserved_0 : 1;
        unsigned int tcu_qacceptn_pd : 1;
        unsigned int tcu_qdeny_pd : 1;
        unsigned int tcu_qactive_pd : 1;
        unsigned int reserved_1 : 1;
        unsigned int tbu0_qacceptn_cg : 1;
        unsigned int tbu0_qdeny_cg : 1;
        unsigned int tbu0_qactive_cg : 1;
        unsigned int reserved_2 : 1;
        unsigned int tbu0_qacceptn_pd : 1;
        unsigned int tbu0_qdeny_pd : 1;
        unsigned int tbu0_qactive_pd : 1;
        unsigned int reserved_3 : 1;
        unsigned int tbu1_qacceptn_cg : 1;
        unsigned int tbu1_qdeny_cg : 1;
        unsigned int tbu1_qactive_cg : 1;
        unsigned int reserved_4 : 1;
        unsigned int tbu1_qacceptn_pd : 1;
        unsigned int tbu1_qdeny_pd : 1;
        unsigned int tbu1_qactive_pd : 1;
        unsigned int reserved_5 : 9;
    } reg;
} SOC_SMMUV3_SMMU_LP_ACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qacceptn_cg_START (0)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qacceptn_cg_END (0)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qdeny_cg_START (1)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qdeny_cg_END (1)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qactive_cg_START (2)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qactive_cg_END (2)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qacceptn_pd_START (4)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qacceptn_pd_END (4)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qdeny_pd_START (5)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qdeny_pd_END (5)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qactive_pd_START (6)
#define SOC_SMMUV3_SMMU_LP_ACK_tcu_qactive_pd_END (6)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qacceptn_cg_START (8)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qacceptn_cg_END (8)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qdeny_cg_START (9)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qdeny_cg_END (9)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qactive_cg_START (10)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qactive_cg_END (10)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qacceptn_pd_START (12)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qacceptn_pd_END (12)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qdeny_pd_START (13)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qdeny_pd_END (13)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qactive_pd_START (14)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu0_qactive_pd_END (14)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qacceptn_cg_START (16)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qacceptn_cg_END (16)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qdeny_cg_START (17)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qdeny_cg_END (17)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qactive_cg_START (18)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qactive_cg_END (18)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qacceptn_pd_START (20)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qacceptn_pd_END (20)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qdeny_pd_START (21)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qdeny_pd_END (21)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qactive_pd_START (22)
#define SOC_SMMUV3_SMMU_LP_ACK_tbu1_qactive_pd_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_qtw_buf_en_req : 1;
        unsigned int tcu_qtw_buf_inv_req : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SMMUV3_SMMU_TCU_QTW_BUF_REQ_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_REQ_tcu_qtw_buf_en_req_START (0)
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_REQ_tcu_qtw_buf_en_req_END (0)
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_REQ_tcu_qtw_buf_inv_req_START (1)
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_REQ_tcu_qtw_buf_inv_req_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_qtw_buf_en_ack : 1;
        unsigned int tcu_qtw_buf_inv_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SMMUV3_SMMU_TCU_QTW_BUF_ACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_ACK_tcu_qtw_buf_en_ack_START (0)
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_ACK_tcu_qtw_buf_en_ack_END (0)
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_ACK_tcu_qtw_buf_inv_ack_START (1)
#define SOC_SMMUV3_SMMU_TCU_QTW_BUF_ACK_tcu_qtw_buf_inv_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_mid : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUV3_SMMU_TCU_MID_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_MID_tcu_mid_START (0)
#define SOC_SMMUV3_SMMU_TCU_MID_tcu_mid_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SMMUV3_SMMU_TOP_MEM_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_TOP_MEM_CTRL_mem_ctrl_s_START (0)
#define SOC_SMMUV3_SMMU_TOP_MEM_CTRL_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_req : 1;
        unsigned int tbu0_soft_rst_req : 1;
        unsigned int tbu1_soft_rst_req : 1;
        unsigned int reserved_0 : 5;
        unsigned int tcu_soft_rst_force_ack : 1;
        unsigned int tbu0_soft_rst_force_ack : 1;
        unsigned int tbu1_soft_rst_force_ack : 1;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_SMMUV3_SMMU_SOFT_RST_REQ_UNION;
#endif
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tcu_soft_rst_req_START (0)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tcu_soft_rst_req_END (0)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu0_soft_rst_req_START (1)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu0_soft_rst_req_END (1)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu1_soft_rst_req_START (2)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu1_soft_rst_req_END (2)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tcu_soft_rst_force_ack_START (8)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tcu_soft_rst_force_ack_END (8)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu0_soft_rst_force_ack_START (9)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu0_soft_rst_force_ack_END (9)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu1_soft_rst_force_ack_START (10)
#define SOC_SMMUV3_SMMU_SOFT_RST_REQ_tbu1_soft_rst_force_ack_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_ack : 1;
        unsigned int tbu0_soft_rst_ack : 1;
        unsigned int tbu1_soft_rst_ack : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUV3_SMMU_SOFT_RST_ACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_tcu_soft_rst_ack_START (0)
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_tcu_soft_rst_ack_END (0)
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_tbu0_soft_rst_ack_START (1)
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_tbu0_soft_rst_ack_END (1)
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_tbu1_soft_rst_ack_START (2)
#define SOC_SMMUV3_SMMU_SOFT_RST_ACK_tbu1_soft_rst_ack_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_stat0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE0_tcu_soft_rst_stat0_START (0)
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE0_tcu_soft_rst_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_soft_rst_stat1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE1_tcu_soft_rst_stat1_START (0)
#define SOC_SMMUV3_SMMU_TCU_SOFT_RST_STATE1_tcu_soft_rst_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_soft_rst_stat0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE0_tbu_soft_rst_stat0_START (0)
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE0_tbu_soft_rst_stat0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_soft_rst_stat1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE1_tbu_soft_rst_stat1_START (0)
#define SOC_SMMUV3_SMMU_TBU_SOFT_RST_STATE1_tbu_soft_rst_stat1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_ns_mask : 1;
        unsigned int tcu_cmd_sync_irpt_ns_mask : 1;
        unsigned int tcu_global_irpt_ns_mask : 1;
        unsigned int tcu_ras_irpt_mask : 1;
        unsigned int tcu_pmu_int_mask : 1;
        unsigned int tcu_evento_mask : 1;
        unsigned int reserved_0 : 2;
        unsigned int tbu0_global_irpt_ns_mask : 1;
        unsigned int tbu0_pmu_irpt_mask : 1;
        unsigned int tbu0_mstr_irpt_mask : 1;
        unsigned int reserved_1 : 1;
        unsigned int tbu1_global_irpt_ns_mask : 1;
        unsigned int tbu1_pmu_irpt_mask : 1;
        unsigned int tbu1_mstr_irpt_mask : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_MASK_NS_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_event_q_irpt_ns_mask_START (0)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_event_q_irpt_ns_mask_END (0)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_cmd_sync_irpt_ns_mask_START (1)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_cmd_sync_irpt_ns_mask_END (1)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_global_irpt_ns_mask_START (2)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_global_irpt_ns_mask_END (2)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_ras_irpt_mask_START (3)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_ras_irpt_mask_END (3)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_pmu_int_mask_START (4)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_pmu_int_mask_END (4)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_evento_mask_START (5)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tcu_evento_mask_END (5)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu0_global_irpt_ns_mask_START (8)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu0_global_irpt_ns_mask_END (8)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu0_pmu_irpt_mask_START (9)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu0_pmu_irpt_mask_END (9)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu0_mstr_irpt_mask_START (10)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu0_mstr_irpt_mask_END (10)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu1_global_irpt_ns_mask_START (12)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu1_global_irpt_ns_mask_END (12)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu1_pmu_irpt_mask_START (13)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu1_pmu_irpt_mask_END (13)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu1_mstr_irpt_mask_START (14)
#define SOC_SMMUV3_SMMU_IRPT_MASK_NS_tbu1_mstr_irpt_mask_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_ns_raw : 1;
        unsigned int tcu_cmd_sync_irpt_ns_raw : 1;
        unsigned int tcu_global_irpt_ns_raw : 1;
        unsigned int tcu_ras_irpt_raw : 1;
        unsigned int tcu_pmu_int_raw : 1;
        unsigned int tcu_evento_raw : 1;
        unsigned int reserved_0 : 2;
        unsigned int tbu0_global_irpt_ns_raw : 1;
        unsigned int tbu0_pmu_irpt_raw : 1;
        unsigned int tbu0_mstr_irpt_raw : 1;
        unsigned int reserved_1 : 1;
        unsigned int tbu1_global_irpt_ns_raw : 1;
        unsigned int tbu1_pmu_irpt_raw : 1;
        unsigned int tbu1_mstr_irpt_raw : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_RAW_NS_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_event_q_irpt_ns_raw_START (0)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_event_q_irpt_ns_raw_END (0)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_cmd_sync_irpt_ns_raw_START (1)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_cmd_sync_irpt_ns_raw_END (1)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_global_irpt_ns_raw_START (2)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_global_irpt_ns_raw_END (2)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_ras_irpt_raw_START (3)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_ras_irpt_raw_END (3)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_pmu_int_raw_START (4)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_pmu_int_raw_END (4)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_evento_raw_START (5)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tcu_evento_raw_END (5)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu0_global_irpt_ns_raw_START (8)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu0_global_irpt_ns_raw_END (8)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu0_pmu_irpt_raw_START (9)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu0_pmu_irpt_raw_END (9)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu0_mstr_irpt_raw_START (10)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu0_mstr_irpt_raw_END (10)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu1_global_irpt_ns_raw_START (12)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu1_global_irpt_ns_raw_END (12)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu1_pmu_irpt_raw_START (13)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu1_pmu_irpt_raw_END (13)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu1_mstr_irpt_raw_START (14)
#define SOC_SMMUV3_SMMU_IRPT_RAW_NS_tbu1_mstr_irpt_raw_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_ns_stat : 1;
        unsigned int tcu_cmd_sync_irpt_ns_stat : 1;
        unsigned int tcu_global_irpt_ns_stat : 1;
        unsigned int tcu_ras_irpt_stat : 1;
        unsigned int tcu_pmu_int_stat : 1;
        unsigned int tcu_evento_stat : 1;
        unsigned int reserved_0 : 2;
        unsigned int tbu0_global_irpt_ns_stat : 1;
        unsigned int tbu0_pmu_irpt_stat : 1;
        unsigned int tbu0_mstr_irpt_stat : 1;
        unsigned int reserved_1 : 1;
        unsigned int tbu1_global_irpt_ns_stat : 1;
        unsigned int tbu1_pmu_irpt_stat : 1;
        unsigned int tbu1_mstr_irpt_stat : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_STAT_NS_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_event_q_irpt_ns_stat_START (0)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_event_q_irpt_ns_stat_END (0)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_cmd_sync_irpt_ns_stat_START (1)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_cmd_sync_irpt_ns_stat_END (1)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_global_irpt_ns_stat_START (2)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_global_irpt_ns_stat_END (2)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_ras_irpt_stat_START (3)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_ras_irpt_stat_END (3)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_pmu_int_stat_START (4)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_pmu_int_stat_END (4)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_evento_stat_START (5)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tcu_evento_stat_END (5)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu0_global_irpt_ns_stat_START (8)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu0_global_irpt_ns_stat_END (8)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu0_pmu_irpt_stat_START (9)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu0_pmu_irpt_stat_END (9)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu0_mstr_irpt_stat_START (10)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu0_mstr_irpt_stat_END (10)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu1_global_irpt_ns_stat_START (12)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu1_global_irpt_ns_stat_END (12)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu1_pmu_irpt_stat_START (13)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu1_pmu_irpt_stat_END (13)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu1_mstr_irpt_stat_START (14)
#define SOC_SMMUV3_SMMU_IRPT_STAT_NS_tbu1_mstr_irpt_stat_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_ns_clr : 1;
        unsigned int tcu_cmd_sync_irpt_ns_clr : 1;
        unsigned int tcu_global_irpt_ns_clr : 1;
        unsigned int tcu_ras_irpt_clr : 1;
        unsigned int tcu_pmu_int_clr : 1;
        unsigned int tcu_evento_clr : 1;
        unsigned int reserved_0 : 2;
        unsigned int tbu0_global_irpt_ns_clr : 1;
        unsigned int tbu0_pmu_irpt_clr : 1;
        unsigned int tbu0_mstr_irpt_clr : 1;
        unsigned int reserved_1 : 1;
        unsigned int tbu1_global_irpt_ns_clr : 1;
        unsigned int tbu1_pmu_irpt_clr : 1;
        unsigned int tbu1_mstr_irpt_clr : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_CLR_NS_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_event_q_irpt_ns_clr_START (0)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_event_q_irpt_ns_clr_END (0)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_cmd_sync_irpt_ns_clr_START (1)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_cmd_sync_irpt_ns_clr_END (1)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_global_irpt_ns_clr_START (2)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_global_irpt_ns_clr_END (2)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_ras_irpt_clr_START (3)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_ras_irpt_clr_END (3)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_pmu_int_clr_START (4)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_pmu_int_clr_END (4)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_evento_clr_START (5)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tcu_evento_clr_END (5)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu0_global_irpt_ns_clr_START (8)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu0_global_irpt_ns_clr_END (8)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu0_pmu_irpt_clr_START (9)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu0_pmu_irpt_clr_END (9)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu0_mstr_irpt_clr_START (10)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu0_mstr_irpt_clr_END (10)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu1_global_irpt_ns_clr_START (12)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu1_global_irpt_ns_clr_END (12)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu1_pmu_irpt_clr_START (13)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu1_pmu_irpt_clr_END (13)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu1_mstr_irpt_clr_START (14)
#define SOC_SMMUV3_SMMU_IRPT_CLR_NS_tbu1_mstr_irpt_clr_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_s_mask : 1;
        unsigned int tcu_cmd_sync_irpt_s_mask : 1;
        unsigned int tcu_global_irpt_s_mask : 1;
        unsigned int reserved_0 : 5;
        unsigned int tbu0_global_irpt_s_mask : 1;
        unsigned int reserved_1 : 3;
        unsigned int tbu1_global_irpt_s_mask : 1;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_MASK_S_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tcu_event_q_irpt_s_mask_START (0)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tcu_event_q_irpt_s_mask_END (0)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tcu_cmd_sync_irpt_s_mask_START (1)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tcu_cmd_sync_irpt_s_mask_END (1)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tcu_global_irpt_s_mask_START (2)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tcu_global_irpt_s_mask_END (2)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tbu0_global_irpt_s_mask_START (8)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tbu0_global_irpt_s_mask_END (8)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tbu1_global_irpt_s_mask_START (12)
#define SOC_SMMUV3_SMMU_IRPT_MASK_S_tbu1_global_irpt_s_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_s_raw : 1;
        unsigned int tcu_cmd_sync_irpt_s_raw : 1;
        unsigned int tcu_global_irpt_s_raw : 1;
        unsigned int reserved_0 : 5;
        unsigned int tbu0_global_irpt_s_raw : 1;
        unsigned int reserved_1 : 3;
        unsigned int tbu1_global_irpt_s_raw : 1;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_RAW_S_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tcu_event_q_irpt_s_raw_START (0)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tcu_event_q_irpt_s_raw_END (0)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tcu_cmd_sync_irpt_s_raw_START (1)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tcu_cmd_sync_irpt_s_raw_END (1)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tcu_global_irpt_s_raw_START (2)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tcu_global_irpt_s_raw_END (2)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tbu0_global_irpt_s_raw_START (8)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tbu0_global_irpt_s_raw_END (8)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tbu1_global_irpt_s_raw_START (12)
#define SOC_SMMUV3_SMMU_IRPT_RAW_S_tbu1_global_irpt_s_raw_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_s_stat : 1;
        unsigned int tcu_cmd_sync_irpt_s_stat : 1;
        unsigned int tcu_global_irpt_s_stat : 1;
        unsigned int reserved_0 : 5;
        unsigned int tbu0_global_irpt_s_stat : 1;
        unsigned int reserved_1 : 3;
        unsigned int tbu1_global_irpt_s_stat : 1;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_STAT_S_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tcu_event_q_irpt_s_stat_START (0)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tcu_event_q_irpt_s_stat_END (0)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tcu_cmd_sync_irpt_s_stat_START (1)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tcu_cmd_sync_irpt_s_stat_END (1)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tcu_global_irpt_s_stat_START (2)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tcu_global_irpt_s_stat_END (2)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tbu0_global_irpt_s_stat_START (8)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tbu0_global_irpt_s_stat_END (8)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tbu1_global_irpt_s_stat_START (12)
#define SOC_SMMUV3_SMMU_IRPT_STAT_S_tbu1_global_irpt_s_stat_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_event_q_irpt_s_clr : 1;
        unsigned int tcu_cmd_sync_irpt_s_clr : 1;
        unsigned int tcu_global_irpt_s_clr : 1;
        unsigned int reserved_0 : 5;
        unsigned int tbu0_global_irpt_s_clr : 1;
        unsigned int reserved_1 : 3;
        unsigned int tbu1_global_irpt_s_clr : 1;
        unsigned int reserved_2 : 19;
    } reg;
} SOC_SMMUV3_SMMU_IRPT_CLR_S_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tcu_event_q_irpt_s_clr_START (0)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tcu_event_q_irpt_s_clr_END (0)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tcu_cmd_sync_irpt_s_clr_START (1)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tcu_cmd_sync_irpt_s_clr_END (1)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tcu_global_irpt_s_clr_START (2)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tcu_global_irpt_s_clr_END (2)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tbu0_global_irpt_s_clr_START (8)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tbu0_global_irpt_s_clr_END (8)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tbu1_global_irpt_s_clr_START (12)
#define SOC_SMMUV3_SMMU_IRPT_CLR_S_tbu1_global_irpt_s_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_opt_func_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_TTW_OPT_FUNC_BYPASS_UNION;
#endif
#define SOC_SMMUV3_TTW_OPT_FUNC_BYPASS_tcu_ttw_opt_func_bypass_START (0)
#define SOC_SMMUV3_TTW_OPT_FUNC_BYPASS_tcu_ttw_opt_func_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cacheline_inv_all : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_CACHELINE_INV_ALL_UNION;
#endif
#define SOC_SMMUV3_CACHELINE_INV_ALL_cacheline_inv_all_START (0)
#define SOC_SMMUV3_CACHELINE_INV_ALL_cacheline_inv_all_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_d1w2r_cfg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUV3_TCU_TTW_OPT_MEM_CTRL_UNION;
#endif
#define SOC_SMMUV3_TCU_TTW_OPT_MEM_CTRL_mem_ctrl_d1w2r_cfg_START (0)
#define SOC_SMMUV3_TCU_TTW_OPT_MEM_CTRL_mem_ctrl_d1w2r_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int replace_policy_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_REPLACE_POLICY_SEL_UNION;
#endif
#define SOC_SMMUV3_REPLACE_POLICY_SEL_replace_policy_sel_START (0)
#define SOC_SMMUV3_REPLACE_POLICY_SEL_replace_policy_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_full0_state : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_FULL0_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL0_tcu_ttw_cmd_fifo_full0_state_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL0_tcu_ttw_cmd_fifo_full0_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_full1_state : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_FULL1_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL1_tcu_ttw_cmd_fifo_full1_state_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_FULL1_tcu_ttw_cmd_fifo_full1_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_empty0_state : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_EMPTY0_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY0_tcu_ttw_cmd_fifo_empty0_state_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY0_tcu_ttw_cmd_fifo_empty0_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_empty1_state : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_EMPTY1_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY1_tcu_ttw_cmd_fifo_empty1_state_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_EMPTY1_tcu_ttw_cmd_fifo_empty1_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt0 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT0_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT0_tcu_ttw_cmd_fifo_cnt0_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT0_tcu_ttw_cmd_fifo_cnt0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt1 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT1_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT1_tcu_ttw_cmd_fifo_cnt1_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT1_tcu_ttw_cmd_fifo_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt2 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT2_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT2_tcu_ttw_cmd_fifo_cnt2_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT2_tcu_ttw_cmd_fifo_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt3 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT3_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT3_tcu_ttw_cmd_fifo_cnt3_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT3_tcu_ttw_cmd_fifo_cnt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt4 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT4_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT4_tcu_ttw_cmd_fifo_cnt4_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT4_tcu_ttw_cmd_fifo_cnt4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt5 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT5_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT5_tcu_ttw_cmd_fifo_cnt5_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT5_tcu_ttw_cmd_fifo_cnt5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt6 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT6_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT6_tcu_ttw_cmd_fifo_cnt6_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT6_tcu_ttw_cmd_fifo_cnt6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_fifo_cnt7 : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_FIFO_CNT7_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT7_tcu_ttw_cmd_fifo_cnt7_START (0)
#define SOC_SMMUV3_TTW_CMD_FIFO_CNT7_tcu_ttw_cmd_fifo_cnt7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ttw_rdata_fifo_full : 1;
        unsigned int ttw_rdata_fifo_afull : 1;
        unsigned int ttw_rdata_fifo_empty : 1;
        unsigned int ttw_rdata_fifo_cnt : 3;
        unsigned int tcu_ttw_rdata_fifo_stat : 26;
    } reg;
} SOC_SMMUV3_TTW_RDATA_FIFO_STAT_UNION;
#endif
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_full_START (0)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_full_END (0)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_afull_START (1)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_afull_END (1)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_empty_START (2)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_empty_END (2)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_cnt_START (3)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_ttw_rdata_fifo_cnt_END (5)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_tcu_ttw_rdata_fifo_stat_START (6)
#define SOC_SMMUV3_TTW_RDATA_FIFO_STAT_tcu_ttw_rdata_fifo_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ttw_cmd_hit_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_TTW_CMD_HIT_CNT_CLR_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_CLR_ttw_cmd_hit_cnt_clr_START (0)
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_CLR_ttw_cmd_hit_cnt_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ttw_cmd_hit_cnt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_TTW_CMD_HIT_CNT_EN_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_EN_ttw_cmd_hit_cnt_en_START (0)
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_EN_ttw_cmd_hit_cnt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_hit_cnt : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_HIT_CNT_STAT_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_STAT_tcu_ttw_cmd_hit_cnt_START (0)
#define SOC_SMMUV3_TTW_CMD_HIT_CNT_STAT_tcu_ttw_cmd_hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ttw_cmd_miss_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_TTW_CMD_MISS_CNT_CLR_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_CLR_ttw_cmd_miss_cnt_clr_START (0)
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_CLR_ttw_cmd_miss_cnt_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ttw_cmd_miss_cnt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_TTW_CMD_MISS_CNT_EN_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_EN_ttw_cmd_miss_cnt_en_START (0)
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_EN_ttw_cmd_miss_cnt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_ttw_cmd_miss_cnt : 32;
    } reg;
} SOC_SMMUV3_TTW_CMD_MISS_CNT_STAT_UNION;
#endif
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_STAT_tcu_ttw_cmd_miss_cnt_START (0)
#define SOC_SMMUV3_TTW_CMD_MISS_CNT_STAT_tcu_ttw_cmd_miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int auto_clk_gate_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_AUTO_CLK_GATE_EN_UNION;
#endif
#define SOC_SMMUV3_AUTO_CLK_GATE_EN_auto_clk_gate_en_START (0)
#define SOC_SMMUV3_AUTO_CLK_GATE_EN_auto_clk_gate_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_GLB_BYPASS_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_GLB_BYPASS_glb_bypass_START (0)
#define SOC_SMMUV3_SMMU_MSTR_GLB_BYPASS_glb_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_mode : 1;
        unsigned int axilock_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DEBUG_MODE_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DEBUG_MODE_debug_mode_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DEBUG_MODE_debug_mode_END (0)
#define SOC_SMMUV3_SMMU_MSTR_DEBUG_MODE_axilock_en_START (1)
#define SOC_SMMUV3_SMMU_MSTR_DEBUG_MODE_axilock_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_bp_d1w2r : 16;
        unsigned int mem_ctrl_d1w2r : 16;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_MEM_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_MEM_CTRL_mem_ctrl_bp_d1w2r_START (0)
#define SOC_SMMUV3_SMMU_MSTR_MEM_CTRL_mem_ctrl_bp_d1w2r_END (15)
#define SOC_SMMUV3_SMMU_MSTR_MEM_CTRL_mem_ctrl_d1w2r_START (16)
#define SOC_SMMUV3_SMMU_MSTR_MEM_CTRL_mem_ctrl_d1w2r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_clk_en : 2;
        unsigned int core_clk_en : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_CLK_EN_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_CLK_EN_apb_clk_en_START (0)
#define SOC_SMMUV3_SMMU_MSTR_CLK_EN_apb_clk_en_END (1)
#define SOC_SMMUV3_SMMU_MSTR_CLK_EN_core_clk_en_START (2)
#define SOC_SMMUV3_SMMU_MSTR_CLK_EN_core_clk_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_req_0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_END_REQ_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_0_end_req_0_START (0)
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_0_end_req_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_req_1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_END_REQ_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_1_end_req_1_START (0)
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_1_end_req_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_req_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_END_REQ_2_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_2_end_req_2_START (0)
#define SOC_SMMUV3_SMMU_MSTR_END_REQ_2_end_req_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_ack_0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_END_ACK_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_0_end_ack_0_START (0)
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_0_end_ack_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_ack_1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_END_ACK_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_1_end_ack_1_START (0)
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_1_end_ack_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_ack_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_END_ACK_2_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_2_end_ack_2_START (0)
#define SOC_SMMUV3_SMMU_MSTR_END_ACK_2_end_ack_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stream_start_0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_SMRX_START_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_0_stream_start_0_START (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_0_stream_start_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stream_start_1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_SMRX_START_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_1_stream_start_1_START (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_1_stream_start_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stream_start_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_SMRX_START_2_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_2_stream_start_2_START (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_START_2_stream_start_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smr_start_sel : 1;
        unsigned int end_req_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_INPT_SEL_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_INPT_SEL_smr_start_sel_START (0)
#define SOC_SMMUV3_SMMU_MSTR_INPT_SEL_smr_start_sel_END (0)
#define SOC_SMMUV3_SMMU_MSTR_INPT_SEL_end_req_sel_START (1)
#define SOC_SMMUV3_SMMU_MSTR_INPT_SEL_end_req_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_RESERVED_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_va_err0_msk : 1;
        unsigned int rd_va_err1_msk : 1;
        unsigned int wr_va_err0_msk : 1;
        unsigned int wr_va_err1_msk : 1;
        unsigned int wdata_burst_msk : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_INTMASK_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_rd_va_err0_msk_START (0)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_rd_va_err0_msk_END (0)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_rd_va_err1_msk_START (1)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_rd_va_err1_msk_END (1)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_wr_va_err0_msk_START (2)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_wr_va_err0_msk_END (2)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_wr_va_err1_msk_START (3)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_wr_va_err1_msk_END (3)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_wdata_burst_msk_START (4)
#define SOC_SMMUV3_SMMU_MSTR_INTMASK_wdata_burst_msk_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_va_err0_raw : 1;
        unsigned int rd_va_err1_raw : 1;
        unsigned int wr_va_err0_raw : 1;
        unsigned int wr_va_err1_raw : 1;
        unsigned int wdata_burst_raw : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_INTRAW_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_rd_va_err0_raw_START (0)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_rd_va_err0_raw_END (0)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_rd_va_err1_raw_START (1)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_rd_va_err1_raw_END (1)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_wr_va_err0_raw_START (2)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_wr_va_err0_raw_END (2)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_wr_va_err1_raw_START (3)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_wr_va_err1_raw_END (3)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_wdata_burst_raw_START (4)
#define SOC_SMMUV3_SMMU_MSTR_INTRAW_wdata_burst_raw_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_va_err0_stat : 1;
        unsigned int rd_va_err1_stat : 1;
        unsigned int wr_va_err0_stat : 1;
        unsigned int wr_va_err1_stat : 1;
        unsigned int wdata_burst_stat : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_INTSTAT_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_rd_va_err0_stat_START (0)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_rd_va_err0_stat_END (0)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_rd_va_err1_stat_START (1)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_rd_va_err1_stat_END (1)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_wr_va_err0_stat_START (2)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_wr_va_err0_stat_END (2)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_wr_va_err1_stat_START (3)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_wr_va_err1_stat_END (3)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_wdata_burst_stat_START (4)
#define SOC_SMMUV3_SMMU_MSTR_INTSTAT_wdata_burst_stat_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_va_err0_clr : 1;
        unsigned int rd_va_err1_clr : 1;
        unsigned int wr_va_err0_clr : 1;
        unsigned int wr_va_err1_clr : 1;
        unsigned int wdata_burst_clr : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_INTCLR_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_rd_va_err0_clr_START (0)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_rd_va_err0_clr_END (0)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_rd_va_err1_clr_START (1)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_rd_va_err1_clr_END (1)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_wr_va_err0_clr_START (2)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_wr_va_err0_clr_END (2)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_wr_va_err1_clr_START (3)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_wr_va_err1_clr_END (3)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_wdata_burst_clr_START (4)
#define SOC_SMMUV3_SMMU_MSTR_INTCLR_wdata_burst_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_sid : 8;
        unsigned int reserved : 8;
        unsigned int rd_addr_msb : 16;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_0_rd_sid_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_0_rd_sid_END (7)
#define SOC_SMMUV3_SMMU_MSTR_DBG_0_rd_addr_msb_START (16)
#define SOC_SMMUV3_SMMU_MSTR_DBG_0_rd_addr_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_addr : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_1_rd_addr_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_1_rd_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_sid : 8;
        unsigned int reserved : 8;
        unsigned int wr_addr_msb : 16;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_2_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_2_wr_sid_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_2_wr_sid_END (7)
#define SOC_SMMUV3_SMMU_MSTR_DBG_2_wr_addr_msb_START (16)
#define SOC_SMMUV3_SMMU_MSTR_DBG_2_wr_addr_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_addr : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_3_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_3_wr_addr_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_3_wr_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awid : 8;
        unsigned int awlen : 4;
        unsigned int reserved : 4;
        unsigned int wid : 8;
        unsigned int wdata_len : 8;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_4_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_awid_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_awid_END (7)
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_awlen_START (8)
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_awlen_END (11)
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_wid_START (16)
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_wid_END (23)
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_wdata_len_START (24)
#define SOC_SMMUV3_SMMU_MSTR_DBG_4_wdata_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_5_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_5_awaddr_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_5_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int awaddr_msb : 16;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_6_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_6_awaddr_msb_START (16)
#define SOC_SMMUV3_SMMU_MSTR_DBG_6_awaddr_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_addr : 16;
        unsigned int dbg_cfg_cs : 1;
        unsigned int dbg_cfg_wr : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_dbg_cfg_addr_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_dbg_cfg_addr_END (15)
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_dbg_cfg_cs_START (16)
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_dbg_cfg_cs_END (16)
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_dbg_cfg_wr_START (17)
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_0_dbg_cfg_wr_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_wdata : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_1_dbg_cfg_wdata_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_IN_1_dbg_cfg_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_rdata : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_DBG_PORT_OUT_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_OUT_dbg_cfg_rdata_START (0)
#define SOC_SMMUV3_SMMU_MSTR_DBG_PORT_OUT_dbg_cfg_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_RESERVED_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int ssidv_mask_en : 1;
        unsigned int reserved_0 : 6;
        unsigned int backward_win : 12;
        unsigned int reserved_1 : 4;
        unsigned int len : 8;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_SMRX_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_bypass_START (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_bypass_END (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_ssidv_mask_en_START (1)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_ssidv_mask_en_END (1)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_backward_win_START (8)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_backward_win_END (19)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_len_START (24)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_0_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int forward_win : 12;
        unsigned int va_str : 20;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_SMRX_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_SMRX_1_forward_win_START (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_1_forward_win_END (11)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_1_va_str_START (12)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_1_va_str_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int page_stride : 12;
        unsigned int va_end : 20;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_SMRX_2_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_SMRX_2_page_stride_START (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_2_page_stride_END (11)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_2_va_end_START (12)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_2_va_end_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int va_str_msb : 16;
        unsigned int va_end_msb : 16;
    } reg;
} SOC_SMMUV3_SMMU_MSTR_SMRX_3_UNION;
#endif
#define SOC_SMMUV3_SMMU_MSTR_SMRX_3_va_str_msb_START (0)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_3_va_str_msb_END (15)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_3_va_end_msb_START (16)
#define SOC_SMMUV3_SMMU_MSTR_SMRX_3_va_end_msb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cmd_total_cnt : 32;
    } reg;
} SOC_SMMUV3_RD_CMD_TOTAL_CNT_UNION;
#endif
#define SOC_SMMUV3_RD_CMD_TOTAL_CNT_rd_cmd_total_cnt_START (0)
#define SOC_SMMUV3_RD_CMD_TOTAL_CNT_rd_cmd_total_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cmd_miss_cnt : 32;
    } reg;
} SOC_SMMUV3_RD_CMD_MISS_CNT_UNION;
#endif
#define SOC_SMMUV3_RD_CMD_MISS_CNT_rd_cmd_miss_cnt_START (0)
#define SOC_SMMUV3_RD_CMD_MISS_CNT_rd_cmd_miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_data_total_cnt : 32;
    } reg;
} SOC_SMMUV3_RD_DATA_TOTAL_CNT_UNION;
#endif
#define SOC_SMMUV3_RD_DATA_TOTAL_CNT_rd_data_total_cnt_START (0)
#define SOC_SMMUV3_RD_DATA_TOTAL_CNT_rd_data_total_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cmd_case_cnt : 32;
    } reg;
} SOC_SMMUV3_RD_CMD_CASE_CNT_UNION;
#endif
#define SOC_SMMUV3_RD_CMD_CASE_CNT_rd_cmd_case_cnt_START (0)
#define SOC_SMMUV3_RD_CMD_CASE_CNT_rd_cmd_case_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cmd_max_latency : 16;
        unsigned int rd_cmd_avg_latency : 16;
    } reg;
} SOC_SMMUV3_RD_CMD_TRANS_LATENCY_UNION;
#endif
#define SOC_SMMUV3_RD_CMD_TRANS_LATENCY_rd_cmd_max_latency_START (0)
#define SOC_SMMUV3_RD_CMD_TRANS_LATENCY_rd_cmd_max_latency_END (15)
#define SOC_SMMUV3_RD_CMD_TRANS_LATENCY_rd_cmd_avg_latency_START (16)
#define SOC_SMMUV3_RD_CMD_TRANS_LATENCY_rd_cmd_avg_latency_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cmd_total_cnt : 32;
    } reg;
} SOC_SMMUV3_WR_CMD_TOTAL_CNT_UNION;
#endif
#define SOC_SMMUV3_WR_CMD_TOTAL_CNT_wr_cmd_total_cnt_START (0)
#define SOC_SMMUV3_WR_CMD_TOTAL_CNT_wr_cmd_total_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cmd_miss_cnt : 32;
    } reg;
} SOC_SMMUV3_WR_CMD_MISS_CNT_UNION;
#endif
#define SOC_SMMUV3_WR_CMD_MISS_CNT_wr_cmd_miss_cnt_START (0)
#define SOC_SMMUV3_WR_CMD_MISS_CNT_wr_cmd_miss_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_data_total_cnt : 32;
    } reg;
} SOC_SMMUV3_WR_DATA_TOTAL_CNT_UNION;
#endif
#define SOC_SMMUV3_WR_DATA_TOTAL_CNT_wr_data_total_cnt_START (0)
#define SOC_SMMUV3_WR_DATA_TOTAL_CNT_wr_data_total_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cmd_case_cnt : 32;
    } reg;
} SOC_SMMUV3_WR_CMD_CASE_CNT_UNION;
#endif
#define SOC_SMMUV3_WR_CMD_CASE_CNT_wr_cmd_case_cnt_START (0)
#define SOC_SMMUV3_WR_CMD_CASE_CNT_wr_cmd_case_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cmd_max_latency : 16;
        unsigned int wr_cmd_avg_latency : 16;
    } reg;
} SOC_SMMUV3_WR_CMD_TRANS_LATENCY_UNION;
#endif
#define SOC_SMMUV3_WR_CMD_TRANS_LATENCY_wr_cmd_max_latency_START (0)
#define SOC_SMMUV3_WR_CMD_TRANS_LATENCY_wr_cmd_max_latency_END (15)
#define SOC_SMMUV3_WR_CMD_TRANS_LATENCY_wr_cmd_avg_latency_START (16)
#define SOC_SMMUV3_WR_CMD_TRANS_LATENCY_wr_cmd_avg_latency_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s2p : 1;
        unsigned int s1p : 1;
        unsigned int ttf : 2;
        unsigned int cohacc : 1;
        unsigned int btm : 1;
        unsigned int httu : 2;
        unsigned int dormhint : 1;
        unsigned int hyp : 1;
        unsigned int ats : 1;
        unsigned int ns1ats : 1;
        unsigned int asid16 : 1;
        unsigned int msi : 1;
        unsigned int sev : 1;
        unsigned int atos : 1;
        unsigned int pri : 1;
        unsigned int vmw : 1;
        unsigned int vmid16 : 1;
        unsigned int cd2l : 1;
        unsigned int vatos : 1;
        unsigned int ttendian : 2;
        unsigned int reserved_0 : 1;
        unsigned int stall_model : 2;
        unsigned int term_model : 1;
        unsigned int st_level : 2;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SMMUV3_SMMU_IDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_IDR0_s2p_START (0)
#define SOC_SMMUV3_SMMU_IDR0_s2p_END (0)
#define SOC_SMMUV3_SMMU_IDR0_s1p_START (1)
#define SOC_SMMUV3_SMMU_IDR0_s1p_END (1)
#define SOC_SMMUV3_SMMU_IDR0_ttf_START (2)
#define SOC_SMMUV3_SMMU_IDR0_ttf_END (3)
#define SOC_SMMUV3_SMMU_IDR0_cohacc_START (4)
#define SOC_SMMUV3_SMMU_IDR0_cohacc_END (4)
#define SOC_SMMUV3_SMMU_IDR0_btm_START (5)
#define SOC_SMMUV3_SMMU_IDR0_btm_END (5)
#define SOC_SMMUV3_SMMU_IDR0_httu_START (6)
#define SOC_SMMUV3_SMMU_IDR0_httu_END (7)
#define SOC_SMMUV3_SMMU_IDR0_dormhint_START (8)
#define SOC_SMMUV3_SMMU_IDR0_dormhint_END (8)
#define SOC_SMMUV3_SMMU_IDR0_hyp_START (9)
#define SOC_SMMUV3_SMMU_IDR0_hyp_END (9)
#define SOC_SMMUV3_SMMU_IDR0_ats_START (10)
#define SOC_SMMUV3_SMMU_IDR0_ats_END (10)
#define SOC_SMMUV3_SMMU_IDR0_ns1ats_START (11)
#define SOC_SMMUV3_SMMU_IDR0_ns1ats_END (11)
#define SOC_SMMUV3_SMMU_IDR0_asid16_START (12)
#define SOC_SMMUV3_SMMU_IDR0_asid16_END (12)
#define SOC_SMMUV3_SMMU_IDR0_msi_START (13)
#define SOC_SMMUV3_SMMU_IDR0_msi_END (13)
#define SOC_SMMUV3_SMMU_IDR0_sev_START (14)
#define SOC_SMMUV3_SMMU_IDR0_sev_END (14)
#define SOC_SMMUV3_SMMU_IDR0_atos_START (15)
#define SOC_SMMUV3_SMMU_IDR0_atos_END (15)
#define SOC_SMMUV3_SMMU_IDR0_pri_START (16)
#define SOC_SMMUV3_SMMU_IDR0_pri_END (16)
#define SOC_SMMUV3_SMMU_IDR0_vmw_START (17)
#define SOC_SMMUV3_SMMU_IDR0_vmw_END (17)
#define SOC_SMMUV3_SMMU_IDR0_vmid16_START (18)
#define SOC_SMMUV3_SMMU_IDR0_vmid16_END (18)
#define SOC_SMMUV3_SMMU_IDR0_cd2l_START (19)
#define SOC_SMMUV3_SMMU_IDR0_cd2l_END (19)
#define SOC_SMMUV3_SMMU_IDR0_vatos_START (20)
#define SOC_SMMUV3_SMMU_IDR0_vatos_END (20)
#define SOC_SMMUV3_SMMU_IDR0_ttendian_START (21)
#define SOC_SMMUV3_SMMU_IDR0_ttendian_END (22)
#define SOC_SMMUV3_SMMU_IDR0_stall_model_START (24)
#define SOC_SMMUV3_SMMU_IDR0_stall_model_END (25)
#define SOC_SMMUV3_SMMU_IDR0_term_model_START (26)
#define SOC_SMMUV3_SMMU_IDR0_term_model_END (26)
#define SOC_SMMUV3_SMMU_IDR0_st_level_START (27)
#define SOC_SMMUV3_SMMU_IDR0_st_level_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sidsize : 6;
        unsigned int ssidsize : 5;
        unsigned int priqs : 5;
        unsigned int eventqs : 5;
        unsigned int cmdqs : 5;
        unsigned int attr_perms_ovr : 1;
        unsigned int attr_types_ovr : 1;
        unsigned int rel : 1;
        unsigned int queues_preset : 1;
        unsigned int tables_preset : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_SMMUV3_SMMU_IDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_IDR1_sidsize_START (0)
#define SOC_SMMUV3_SMMU_IDR1_sidsize_END (5)
#define SOC_SMMUV3_SMMU_IDR1_ssidsize_START (6)
#define SOC_SMMUV3_SMMU_IDR1_ssidsize_END (10)
#define SOC_SMMUV3_SMMU_IDR1_priqs_START (11)
#define SOC_SMMUV3_SMMU_IDR1_priqs_END (15)
#define SOC_SMMUV3_SMMU_IDR1_eventqs_START (16)
#define SOC_SMMUV3_SMMU_IDR1_eventqs_END (20)
#define SOC_SMMUV3_SMMU_IDR1_cmdqs_START (21)
#define SOC_SMMUV3_SMMU_IDR1_cmdqs_END (25)
#define SOC_SMMUV3_SMMU_IDR1_attr_perms_ovr_START (26)
#define SOC_SMMUV3_SMMU_IDR1_attr_perms_ovr_END (26)
#define SOC_SMMUV3_SMMU_IDR1_attr_types_ovr_START (27)
#define SOC_SMMUV3_SMMU_IDR1_attr_types_ovr_END (27)
#define SOC_SMMUV3_SMMU_IDR1_rel_START (28)
#define SOC_SMMUV3_SMMU_IDR1_rel_END (28)
#define SOC_SMMUV3_SMMU_IDR1_queues_preset_START (29)
#define SOC_SMMUV3_SMMU_IDR1_queues_preset_END (29)
#define SOC_SMMUV3_SMMU_IDR1_tables_preset_START (30)
#define SOC_SMMUV3_SMMU_IDR1_tables_preset_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ba_vatos : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SMMUV3_SMMU_IDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_IDR2_ba_vatos_START (0)
#define SOC_SMMUV3_SMMU_IDR2_ba_vatos_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int had : 1;
        unsigned int pbha : 1;
        unsigned int xnx : 1;
        unsigned int reserved_1: 27;
    } reg;
} SOC_SMMUV3_SMMU_IDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_IDR3_had_START (2)
#define SOC_SMMUV3_SMMU_IDR3_had_END (2)
#define SOC_SMMUV3_SMMU_IDR3_pbha_START (3)
#define SOC_SMMUV3_SMMU_IDR3_pbha_END (3)
#define SOC_SMMUV3_SMMU_IDR3_xnx_START (4)
#define SOC_SMMUV3_SMMU_IDR3_xnx_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_IDR4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int oas : 3;
        unsigned int reserved_0: 1;
        unsigned int gran4k : 1;
        unsigned int gran16k : 1;
        unsigned int gran64k : 1;
        unsigned int reserved_1: 3;
        unsigned int vax : 2;
        unsigned int reserved_2: 4;
        unsigned int stall_max : 16;
    } reg;
} SOC_SMMUV3_SMMU_IDR5_UNION;
#endif
#define SOC_SMMUV3_SMMU_IDR5_oas_START (0)
#define SOC_SMMUV3_SMMU_IDR5_oas_END (2)
#define SOC_SMMUV3_SMMU_IDR5_gran4k_START (4)
#define SOC_SMMUV3_SMMU_IDR5_gran4k_END (4)
#define SOC_SMMUV3_SMMU_IDR5_gran16k_START (5)
#define SOC_SMMUV3_SMMU_IDR5_gran16k_END (5)
#define SOC_SMMUV3_SMMU_IDR5_gran64k_START (6)
#define SOC_SMMUV3_SMMU_IDR5_gran64k_END (6)
#define SOC_SMMUV3_SMMU_IDR5_vax_START (10)
#define SOC_SMMUV3_SMMU_IDR5_vax_END (11)
#define SOC_SMMUV3_SMMU_IDR5_stall_max_START (16)
#define SOC_SMMUV3_SMMU_IDR5_stall_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int implementer : 12;
        unsigned int revision : 4;
        unsigned int variant : 4;
        unsigned int productid : 12;
    } reg;
} SOC_SMMUV3_SMMU_IIDR_UNION;
#endif
#define SOC_SMMUV3_SMMU_IIDR_implementer_START (0)
#define SOC_SMMUV3_SMMU_IIDR_implementer_END (11)
#define SOC_SMMUV3_SMMU_IIDR_revision_START (12)
#define SOC_SMMUV3_SMMU_IIDR_revision_END (15)
#define SOC_SMMUV3_SMMU_IIDR_variant_START (16)
#define SOC_SMMUV3_SMMU_IIDR_variant_END (19)
#define SOC_SMMUV3_SMMU_IIDR_productid_START (20)
#define SOC_SMMUV3_SMMU_IIDR_productid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int archminorrev : 4;
        unsigned int archmajorrev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SMMUV3_SMMU_AIDR_UNION;
#endif
#define SOC_SMMUV3_SMMU_AIDR_archminorrev_START (0)
#define SOC_SMMUV3_SMMU_AIDR_archminorrev_END (3)
#define SOC_SMMUV3_SMMU_AIDR_archmajorrev_START (4)
#define SOC_SMMUV3_SMMU_AIDR_archmajorrev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmuen : 1;
        unsigned int priqen : 1;
        unsigned int eventqen : 1;
        unsigned int cmdqen : 1;
        unsigned int atschk : 1;
        unsigned int reserved_0: 1;
        unsigned int vmw : 3;
        unsigned int reserved_1: 23;
    } reg;
} SOC_SMMUV3_SMMU_CR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_CR0_smmuen_START (0)
#define SOC_SMMUV3_SMMU_CR0_smmuen_END (0)
#define SOC_SMMUV3_SMMU_CR0_priqen_START (1)
#define SOC_SMMUV3_SMMU_CR0_priqen_END (1)
#define SOC_SMMUV3_SMMU_CR0_eventqen_START (2)
#define SOC_SMMUV3_SMMU_CR0_eventqen_END (2)
#define SOC_SMMUV3_SMMU_CR0_cmdqen_START (3)
#define SOC_SMMUV3_SMMU_CR0_cmdqen_END (3)
#define SOC_SMMUV3_SMMU_CR0_atschk_START (4)
#define SOC_SMMUV3_SMMU_CR0_atschk_END (4)
#define SOC_SMMUV3_SMMU_CR0_vmw_START (6)
#define SOC_SMMUV3_SMMU_CR0_vmw_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmuen : 1;
        unsigned int priqen : 1;
        unsigned int eventqen : 1;
        unsigned int cmdqen : 1;
        unsigned int atschk : 1;
        unsigned int reserved_0: 1;
        unsigned int vmw : 3;
        unsigned int reserved_1: 23;
    } reg;
} SOC_SMMUV3_SMMU_CR0ACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_CR0ACK_smmuen_START (0)
#define SOC_SMMUV3_SMMU_CR0ACK_smmuen_END (0)
#define SOC_SMMUV3_SMMU_CR0ACK_priqen_START (1)
#define SOC_SMMUV3_SMMU_CR0ACK_priqen_END (1)
#define SOC_SMMUV3_SMMU_CR0ACK_eventqen_START (2)
#define SOC_SMMUV3_SMMU_CR0ACK_eventqen_END (2)
#define SOC_SMMUV3_SMMU_CR0ACK_cmdqen_START (3)
#define SOC_SMMUV3_SMMU_CR0ACK_cmdqen_END (3)
#define SOC_SMMUV3_SMMU_CR0ACK_atschk_START (4)
#define SOC_SMMUV3_SMMU_CR0ACK_atschk_END (4)
#define SOC_SMMUV3_SMMU_CR0ACK_vmw_START (6)
#define SOC_SMMUV3_SMMU_CR0ACK_vmw_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int queue_ic : 2;
        unsigned int queue_oc : 2;
        unsigned int queue_sh : 2;
        unsigned int table_ic : 2;
        unsigned int table_oc : 2;
        unsigned int table_sh : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUV3_SMMU_CR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_CR1_queue_ic_START (0)
#define SOC_SMMUV3_SMMU_CR1_queue_ic_END (1)
#define SOC_SMMUV3_SMMU_CR1_queue_oc_START (2)
#define SOC_SMMUV3_SMMU_CR1_queue_oc_END (3)
#define SOC_SMMUV3_SMMU_CR1_queue_sh_START (4)
#define SOC_SMMUV3_SMMU_CR1_queue_sh_END (5)
#define SOC_SMMUV3_SMMU_CR1_table_ic_START (6)
#define SOC_SMMUV3_SMMU_CR1_table_ic_END (7)
#define SOC_SMMUV3_SMMU_CR1_table_oc_START (8)
#define SOC_SMMUV3_SMMU_CR1_table_oc_END (9)
#define SOC_SMMUV3_SMMU_CR1_table_sh_START (10)
#define SOC_SMMUV3_SMMU_CR1_table_sh_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int e2h : 1;
        unsigned int recinvsid : 1;
        unsigned int ptm : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUV3_SMMU_CR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_CR2_e2h_START (0)
#define SOC_SMMUV3_SMMU_CR2_e2h_END (0)
#define SOC_SMMUV3_SMMU_CR2_recinvsid_START (1)
#define SOC_SMMUV3_SMMU_CR2_recinvsid_END (1)
#define SOC_SMMUV3_SMMU_CR2_ptm_START (2)
#define SOC_SMMUV3_SMMU_CR2_ptm_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dormant : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_STATUSR_UNION;
#endif
#define SOC_SMMUV3_SMMU_STATUSR_dormant_START (0)
#define SOC_SMMUV3_SMMU_STATUSR_dormant_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int memattr : 4;
        unsigned int mtcfg : 1;
        unsigned int reserved_0: 3;
        unsigned int alloccfg : 4;
        unsigned int shcfg : 2;
        unsigned int reserved_1: 2;
        unsigned int privcfg : 2;
        unsigned int instcfg : 2;
        unsigned int abort : 1;
        unsigned int reserved_2: 10;
        unsigned int update : 1;
    } reg;
} SOC_SMMUV3_SMMU_GBPA_UNION;
#endif
#define SOC_SMMUV3_SMMU_GBPA_memattr_START (0)
#define SOC_SMMUV3_SMMU_GBPA_memattr_END (3)
#define SOC_SMMUV3_SMMU_GBPA_mtcfg_START (4)
#define SOC_SMMUV3_SMMU_GBPA_mtcfg_END (4)
#define SOC_SMMUV3_SMMU_GBPA_alloccfg_START (8)
#define SOC_SMMUV3_SMMU_GBPA_alloccfg_END (11)
#define SOC_SMMUV3_SMMU_GBPA_shcfg_START (12)
#define SOC_SMMUV3_SMMU_GBPA_shcfg_END (13)
#define SOC_SMMUV3_SMMU_GBPA_privcfg_START (16)
#define SOC_SMMUV3_SMMU_GBPA_privcfg_END (17)
#define SOC_SMMUV3_SMMU_GBPA_instcfg_START (18)
#define SOC_SMMUV3_SMMU_GBPA_instcfg_END (19)
#define SOC_SMMUV3_SMMU_GBPA_abort_START (20)
#define SOC_SMMUV3_SMMU_GBPA_abort_END (20)
#define SOC_SMMUV3_SMMU_GBPA_update_START (31)
#define SOC_SMMUV3_SMMU_GBPA_update_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_AGBPA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gerror_irqen : 1;
        unsigned int priq_irqen : 1;
        unsigned int eventq_irqen : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUV3_SMMU_IRQ_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRQ_CTRL_gerror_irqen_START (0)
#define SOC_SMMUV3_SMMU_IRQ_CTRL_gerror_irqen_END (0)
#define SOC_SMMUV3_SMMU_IRQ_CTRL_priq_irqen_START (1)
#define SOC_SMMUV3_SMMU_IRQ_CTRL_priq_irqen_END (1)
#define SOC_SMMUV3_SMMU_IRQ_CTRL_eventq_irqen_START (2)
#define SOC_SMMUV3_SMMU_IRQ_CTRL_eventq_irqen_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gerror_irqen : 1;
        unsigned int priq_irqen : 1;
        unsigned int eventq_irqen : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SMMUV3_SMMU_IRQ_CTRLACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_gerror_irqen_START (0)
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_gerror_irqen_END (0)
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_priq_irqen_START (1)
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_priq_irqen_END (1)
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_eventq_irqen_START (2)
#define SOC_SMMUV3_SMMU_IRQ_CTRLACK_eventq_irqen_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdq_err : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_err : 1;
        unsigned int priq_abt_err : 1;
        unsigned int msi_cmdq_abt_err : 1;
        unsigned int msi_eventq_abt_err : 1;
        unsigned int msi_priq_abt_err : 1;
        unsigned int msi_gerror_abt_err : 1;
        unsigned int sfm_err : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SMMUV3_SMMU_GERROR_UNION;
#endif
#define SOC_SMMUV3_SMMU_GERROR_cmdq_err_START (0)
#define SOC_SMMUV3_SMMU_GERROR_cmdq_err_END (0)
#define SOC_SMMUV3_SMMU_GERROR_eventq_abt_err_START (2)
#define SOC_SMMUV3_SMMU_GERROR_eventq_abt_err_END (2)
#define SOC_SMMUV3_SMMU_GERROR_priq_abt_err_START (3)
#define SOC_SMMUV3_SMMU_GERROR_priq_abt_err_END (3)
#define SOC_SMMUV3_SMMU_GERROR_msi_cmdq_abt_err_START (4)
#define SOC_SMMUV3_SMMU_GERROR_msi_cmdq_abt_err_END (4)
#define SOC_SMMUV3_SMMU_GERROR_msi_eventq_abt_err_START (5)
#define SOC_SMMUV3_SMMU_GERROR_msi_eventq_abt_err_END (5)
#define SOC_SMMUV3_SMMU_GERROR_msi_priq_abt_err_START (6)
#define SOC_SMMUV3_SMMU_GERROR_msi_priq_abt_err_END (6)
#define SOC_SMMUV3_SMMU_GERROR_msi_gerror_abt_err_START (7)
#define SOC_SMMUV3_SMMU_GERROR_msi_gerror_abt_err_END (7)
#define SOC_SMMUV3_SMMU_GERROR_sfm_err_START (8)
#define SOC_SMMUV3_SMMU_GERROR_sfm_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdq_err : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_err : 1;
        unsigned int priq_abt_err : 1;
        unsigned int msi_cmdq_abt_err : 1;
        unsigned int msi_eventq_abt_err : 1;
        unsigned int msi_priq_abt_err : 1;
        unsigned int msi_gerror_abt_err : 1;
        unsigned int sfm_err : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SMMUV3_SMMU_GERRORN_UNION;
#endif
#define SOC_SMMUV3_SMMU_GERRORN_cmdq_err_START (0)
#define SOC_SMMUV3_SMMU_GERRORN_cmdq_err_END (0)
#define SOC_SMMUV3_SMMU_GERRORN_eventq_abt_err_START (2)
#define SOC_SMMUV3_SMMU_GERRORN_eventq_abt_err_END (2)
#define SOC_SMMUV3_SMMU_GERRORN_priq_abt_err_START (3)
#define SOC_SMMUV3_SMMU_GERRORN_priq_abt_err_END (3)
#define SOC_SMMUV3_SMMU_GERRORN_msi_cmdq_abt_err_START (4)
#define SOC_SMMUV3_SMMU_GERRORN_msi_cmdq_abt_err_END (4)
#define SOC_SMMUV3_SMMU_GERRORN_msi_eventq_abt_err_START (5)
#define SOC_SMMUV3_SMMU_GERRORN_msi_eventq_abt_err_END (5)
#define SOC_SMMUV3_SMMU_GERRORN_msi_priq_abt_err_START (6)
#define SOC_SMMUV3_SMMU_GERRORN_msi_priq_abt_err_END (6)
#define SOC_SMMUV3_SMMU_GERRORN_msi_gerror_abt_err_START (7)
#define SOC_SMMUV3_SMMU_GERRORN_msi_gerror_abt_err_END (7)
#define SOC_SMMUV3_SMMU_GERRORN_sfm_err_START (8)
#define SOC_SMMUV3_SMMU_GERRORN_sfm_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int addr : 30;
    } reg;
} SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_0_addr_START (2)
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_1_addr_START (0)
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG0_1_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data : 32;
    } reg;
} SOC_SMMUV3_SMMU_GERROR_IRQ_CFG1_UNION;
#endif
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG1_data_START (0)
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG1_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int memattr : 4;
        unsigned int sh : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUV3_SMMU_GERROR_IRQ_CFG2_UNION;
#endif
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG2_memattr_START (0)
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG2_memattr_END (3)
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG2_sh_START (4)
#define SOC_SMMUV3_SMMU_GERROR_IRQ_CFG2_sh_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int addr : 26;
    } reg;
} SOC_SMMUV3_SMMU_STRTAB_BASE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_STRTAB_BASE0_addr_START (6)
#define SOC_SMMUV3_SMMU_STRTAB_BASE0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved_0: 14;
        unsigned int ra : 1;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_STRTAB_BASE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_STRTAB_BASE1_addr_START (0)
#define SOC_SMMUV3_SMMU_STRTAB_BASE1_addr_END (15)
#define SOC_SMMUV3_SMMU_STRTAB_BASE1_ra_START (30)
#define SOC_SMMUV3_SMMU_STRTAB_BASE1_ra_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log2size : 6;
        unsigned int split : 5;
        unsigned int reserved_0: 5;
        unsigned int fmt : 2;
        unsigned int reserved_1: 14;
    } reg;
} SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_UNION;
#endif
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_log2size_START (0)
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_log2size_END (5)
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_split_START (6)
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_split_END (10)
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_fmt_START (16)
#define SOC_SMMUV3_SMMU_STRTAB_BASE_CFG_fmt_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log2size : 5;
        unsigned int addr : 27;
    } reg;
} SOC_SMMUV3_SMMU_CMDQ_BASE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_CMDQ_BASE0_log2size_START (0)
#define SOC_SMMUV3_SMMU_CMDQ_BASE0_log2size_END (4)
#define SOC_SMMUV3_SMMU_CMDQ_BASE0_addr_START (5)
#define SOC_SMMUV3_SMMU_CMDQ_BASE0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved_0: 14;
        unsigned int ra : 1;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_CMDQ_BASE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_CMDQ_BASE1_addr_START (0)
#define SOC_SMMUV3_SMMU_CMDQ_BASE1_addr_END (15)
#define SOC_SMMUV3_SMMU_CMDQ_BASE1_ra_START (30)
#define SOC_SMMUV3_SMMU_CMDQ_BASE1_ra_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr : 19;
        unsigned int wr_wrap : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_SMMUV3_SMMU_CMDQ_PROD_UNION;
#endif
#define SOC_SMMUV3_SMMU_CMDQ_PROD_wr_START (0)
#define SOC_SMMUV3_SMMU_CMDQ_PROD_wr_END (18)
#define SOC_SMMUV3_SMMU_CMDQ_PROD_wr_wrap_START (19)
#define SOC_SMMUV3_SMMU_CMDQ_PROD_wr_wrap_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd : 19;
        unsigned int rd_wrap : 1;
        unsigned int reserved_0: 4;
        unsigned int err : 7;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_CMDQ_CONS_UNION;
#endif
#define SOC_SMMUV3_SMMU_CMDQ_CONS_rd_START (0)
#define SOC_SMMUV3_SMMU_CMDQ_CONS_rd_END (18)
#define SOC_SMMUV3_SMMU_CMDQ_CONS_rd_wrap_START (19)
#define SOC_SMMUV3_SMMU_CMDQ_CONS_rd_wrap_END (19)
#define SOC_SMMUV3_SMMU_CMDQ_CONS_err_START (24)
#define SOC_SMMUV3_SMMU_CMDQ_CONS_err_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log2size : 5;
        unsigned int addr : 27;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_BASE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_BASE0_log2size_START (0)
#define SOC_SMMUV3_SMMU_EVENTQ_BASE0_log2size_END (4)
#define SOC_SMMUV3_SMMU_EVENTQ_BASE0_addr_START (5)
#define SOC_SMMUV3_SMMU_EVENTQ_BASE0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved_0: 14;
        unsigned int wa : 1;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_BASE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_BASE1_addr_START (0)
#define SOC_SMMUV3_SMMU_EVENTQ_BASE1_addr_END (15)
#define SOC_SMMUV3_SMMU_EVENTQ_BASE1_wa_START (30)
#define SOC_SMMUV3_SMMU_EVENTQ_BASE1_wa_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr : 19;
        unsigned int wr_wrap : 1;
        unsigned int reserved : 11;
        unsigned int ovflg : 1;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_PROD_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_wr_START (0)
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_wr_END (18)
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_wr_wrap_START (19)
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_wr_wrap_END (19)
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_ovflg_START (31)
#define SOC_SMMUV3_SMMU_EVENTQ_PROD_ovflg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd : 19;
        unsigned int rd_wrap : 1;
        unsigned int reserved : 11;
        unsigned int ovackflg : 1;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_CONS_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_rd_START (0)
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_rd_END (18)
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_rd_wrap_START (19)
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_rd_wrap_END (19)
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_ovackflg_START (31)
#define SOC_SMMUV3_SMMU_EVENTQ_CONS_ovackflg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int addr : 30;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_0_addr_START (2)
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_1_addr_START (0)
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG0_1_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data : 32;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG1_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG1_data_START (0)
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG1_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int memattr : 4;
        unsigned int sh : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG2_UNION;
#endif
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG2_memattr_START (0)
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG2_memattr_END (3)
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG2_sh_START (4)
#define SOC_SMMUV3_SMMU_EVENTQ_IRQ_CFG2_sh_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_BASE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_BASE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_PROD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_CONS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PRIQ_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr4 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR4_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR4_smmu_pidr4_START (0)
#define SOC_SMMUV3_SMMU_PIDR4_smmu_pidr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr5 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR5_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR5_smmu_pidr5_START (0)
#define SOC_SMMUV3_SMMU_PIDR5_smmu_pidr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr6 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR6_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR6_smmu_pidr6_START (0)
#define SOC_SMMUV3_SMMU_PIDR6_smmu_pidr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr7 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR7_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR7_smmu_pidr7_START (0)
#define SOC_SMMUV3_SMMU_PIDR7_smmu_pidr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR0_smmu_pidr0_START (0)
#define SOC_SMMUV3_SMMU_PIDR0_smmu_pidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR1_smmu_pidr1_START (0)
#define SOC_SMMUV3_SMMU_PIDR1_smmu_pidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR2_smmu_pidr2_START (0)
#define SOC_SMMUV3_SMMU_PIDR2_smmu_pidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_PIDR3_smmu_pidr3_START (0)
#define SOC_SMMUV3_SMMU_PIDR3_smmu_pidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_cidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_CIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_CIDR0_smmu_cidr0_START (0)
#define SOC_SMMUV3_SMMU_CIDR0_smmu_cidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_cidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_CIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_CIDR1_smmu_cidr1_START (0)
#define SOC_SMMUV3_SMMU_CIDR1_smmu_cidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_cidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_CIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_CIDR2_smmu_cidr2_START (0)
#define SOC_SMMUV3_SMMU_CIDR2_smmu_cidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_cidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_CIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_CIDR3_smmu_cidr3_START (0)
#define SOC_SMMUV3_SMMU_CIDR3_smmu_cidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evcntr : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_EVCNTR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_EVCNTR_evcntr_START (0)
#define SOC_SMMUV3_SMMU_PMCG_EVCNTR_evcntr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event : 8;
        unsigned int reserved : 21;
        unsigned int filter_sid_span : 1;
        unsigned int filter_sec_sid : 1;
        unsigned int ovfcap : 1;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_EVTYPER0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_event_START (0)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_event_END (7)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_filter_sid_span_START (29)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_filter_sid_span_END (29)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_filter_sec_sid_START (30)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_filter_sec_sid_END (30)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_ovfcap_START (31)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER0_ovfcap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event : 8;
        unsigned int reserved : 23;
        unsigned int ovfcap : 1;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_EVTYPER_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER_event_START (0)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER_event_END (7)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER_ovfcap_START (31)
#define SOC_SMMUV3_SMMU_PMCG_EVTYPER_ovfcap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svr : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_SVR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_SVR_svr_START (0)
#define SOC_SMMUV3_SMMU_PMCG_SVR_svr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int streamid : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_SMR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_SMR_streamid_START (0)
#define SOC_SMMUV3_SMMU_PMCG_SMR_streamid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnten : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CNTENSET0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CNTENSET0_0_cnten_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CNTENSET0_0_cnten_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CNTENSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntclr : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_0_cntclr_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_0_cntclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CNTENCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inten : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_INTENSET0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_INTENSET0_0_inten_START (0)
#define SOC_SMMUV3_SMMU_PMCG_INTENSET0_0_inten_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_INTENSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intclr : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_INTENCLR0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_INTENCLR0_0_intclr_START (0)
#define SOC_SMMUV3_SMMU_PMCG_INTENCLR0_0_intclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_INTENCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ovsclr : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_OVSCLR0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_OVSCLR0_0_ovsclr_START (0)
#define SOC_SMMUV3_SMMU_PMCG_OVSCLR0_0_ovsclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_OVSCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ovsset : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_OVSSET0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_OVSSET0_0_ovsset_START (0)
#define SOC_SMMUV3_SMMU_PMCG_OVSSET0_0_ovsset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_OVSSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int capture : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CAPR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CAPR_capture_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CAPR_capture_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int so : 1;
        unsigned int nsra : 1;
        unsigned int nsmsi : 1;
        unsigned int reserved : 28;
        unsigned int readasone : 1;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_SCR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_SCR_so_START (0)
#define SOC_SMMUV3_SMMU_PMCG_SCR_so_END (0)
#define SOC_SMMUV3_SMMU_PMCG_SCR_nsra_START (1)
#define SOC_SMMUV3_SMMU_PMCG_SCR_nsra_END (1)
#define SOC_SMMUV3_SMMU_PMCG_SCR_nsmsi_START (2)
#define SOC_SMMUV3_SMMU_PMCG_SCR_nsmsi_END (2)
#define SOC_SMMUV3_SMMU_PMCG_SCR_readasone_START (31)
#define SOC_SMMUV3_SMMU_PMCG_SCR_readasone_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nctr : 6;
        unsigned int reserved_0 : 2;
        unsigned int size : 6;
        unsigned int reserved_1 : 6;
        unsigned int reloc_ctrs : 1;
        unsigned int msi : 1;
        unsigned int capture : 1;
        unsigned int sid_filter_type : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CFGR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CFGR_nctr_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_nctr_END (5)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_size_START (8)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_size_END (13)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_reloc_ctrs_START (20)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_reloc_ctrs_END (20)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_msi_START (21)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_msi_END (21)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_capture_START (22)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_capture_END (22)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_sid_filter_type_START (23)
#define SOC_SMMUV3_SMMU_PMCG_CFGR_sid_filter_type_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int e : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CR_e_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CR_e_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CEID0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CEID0_0_event_en_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CEID0_0_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CEID0_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CEID0_1_event_en_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CEID0_1_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CEID1_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CEID1_0_event_en_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CEID1_0_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CEID1_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CEID1_1_event_en_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CEID1_1_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irqen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_IRQ_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRL_irqen_START (0)
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRL_irqen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irqen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_IRQ_CTRLACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRLACK_irqen_START (0)
#define SOC_SMMUV3_SMMU_PMCG_IRQ_CTRLACK_irqen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_IRQ_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int archminorrev : 4;
        unsigned int archmajorrev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_AIDR_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_AIDR_archminorrev_START (0)
#define SOC_SMMUV3_SMMU_PMCG_AIDR_archminorrev_END (3)
#define SOC_SMMUV3_SMMU_PMCG_AIDR_archmajorrev_START (4)
#define SOC_SMMUV3_SMMU_PMCG_AIDR_archmajorrev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pmauthstatus : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PMAUTHSTATUS_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PMAUTHSTATUS_smmu_pmcg_pmauthstatus_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PMAUTHSTATUS_smmu_pmcg_pmauthstatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr4 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR4_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR4_smmu_pmcg_pidr4_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR4_smmu_pmcg_pidr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr5 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR5_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR5_smmu_pmcg_pidr5_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR5_smmu_pmcg_pidr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr6 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR6_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR6_smmu_pmcg_pidr6_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR6_smmu_pmcg_pidr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr7 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR7_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR7_smmu_pmcg_pidr7_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR7_smmu_pmcg_pidr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR0_smmu_pmcg_pidr0_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR0_smmu_pmcg_pidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR1_smmu_pmcg_pidr1_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR1_smmu_pmcg_pidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR2_smmu_pmcg_pidr2_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR2_smmu_pmcg_pidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_PIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_PIDR3_smmu_pmcg_pidr3_START (0)
#define SOC_SMMUV3_SMMU_PMCG_PIDR3_smmu_pmcg_pidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CIDR0_smmu_pmcg_cidr0_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CIDR0_smmu_pmcg_cidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CIDR1_smmu_pmcg_cidr1_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CIDR1_smmu_pmcg_cidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CIDR2_smmu_pmcg_cidr2_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CIDR2_smmu_pmcg_cidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_PMCG_CIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_PMCG_CIDR3_smmu_pmcg_cidr3_START (0)
#define SOC_SMMUV3_SMMU_PMCG_CIDR3_smmu_pmcg_cidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 13;
        unsigned int msi : 1;
        unsigned int reserved_1 : 10;
        unsigned int stall_model : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_SMMUV3_SMMU_S_IDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_IDR0_msi_START (13)
#define SOC_SMMUV3_SMMU_S_IDR0_msi_END (13)
#define SOC_SMMUV3_SMMU_S_IDR0_stall_model_START (24)
#define SOC_SMMUV3_SMMU_S_IDR0_stall_model_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s_sidsize : 6;
        unsigned int reserved : 25;
        unsigned int secure_impl : 1;
    } reg;
} SOC_SMMUV3_SMMU_S_IDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_IDR1_s_sidsize_START (0)
#define SOC_SMMUV3_SMMU_S_IDR1_s_sidsize_END (5)
#define SOC_SMMUV3_SMMU_S_IDR1_secure_impl_START (31)
#define SOC_SMMUV3_SMMU_S_IDR1_secure_impl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_S_IDR2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_S_IDR3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_S_IDR4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmuen : 1;
        unsigned int reserved_0: 1;
        unsigned int eventqen : 1;
        unsigned int cmdqen : 1;
        unsigned int reserved_1: 1;
        unsigned int sif : 1;
        unsigned int reserved_2: 3;
        unsigned int nsstalld : 1;
        unsigned int reserved_3: 22;
    } reg;
} SOC_SMMUV3_SMMU_S_CR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CR0_smmuen_START (0)
#define SOC_SMMUV3_SMMU_S_CR0_smmuen_END (0)
#define SOC_SMMUV3_SMMU_S_CR0_eventqen_START (2)
#define SOC_SMMUV3_SMMU_S_CR0_eventqen_END (2)
#define SOC_SMMUV3_SMMU_S_CR0_cmdqen_START (3)
#define SOC_SMMUV3_SMMU_S_CR0_cmdqen_END (3)
#define SOC_SMMUV3_SMMU_S_CR0_sif_START (5)
#define SOC_SMMUV3_SMMU_S_CR0_sif_END (5)
#define SOC_SMMUV3_SMMU_S_CR0_nsstalld_START (9)
#define SOC_SMMUV3_SMMU_S_CR0_nsstalld_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmuen : 1;
        unsigned int reserved_0: 1;
        unsigned int eventqen : 1;
        unsigned int cmdqen : 1;
        unsigned int reserved_1: 1;
        unsigned int sif : 1;
        unsigned int reserved_2: 3;
        unsigned int nsstalld : 1;
        unsigned int reserved_3: 22;
    } reg;
} SOC_SMMUV3_SMMU_S_CR0ACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CR0ACK_smmuen_START (0)
#define SOC_SMMUV3_SMMU_S_CR0ACK_smmuen_END (0)
#define SOC_SMMUV3_SMMU_S_CR0ACK_eventqen_START (2)
#define SOC_SMMUV3_SMMU_S_CR0ACK_eventqen_END (2)
#define SOC_SMMUV3_SMMU_S_CR0ACK_cmdqen_START (3)
#define SOC_SMMUV3_SMMU_S_CR0ACK_cmdqen_END (3)
#define SOC_SMMUV3_SMMU_S_CR0ACK_sif_START (5)
#define SOC_SMMUV3_SMMU_S_CR0ACK_sif_END (5)
#define SOC_SMMUV3_SMMU_S_CR0ACK_nsstalld_START (9)
#define SOC_SMMUV3_SMMU_S_CR0ACK_nsstalld_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int queue_ic : 2;
        unsigned int queue_oc : 2;
        unsigned int queue_sh : 2;
        unsigned int table_ic : 2;
        unsigned int table_oc : 2;
        unsigned int table_sh : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_SMMUV3_SMMU_S_CR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CR1_queue_ic_START (0)
#define SOC_SMMUV3_SMMU_S_CR1_queue_ic_END (1)
#define SOC_SMMUV3_SMMU_S_CR1_queue_oc_START (2)
#define SOC_SMMUV3_SMMU_S_CR1_queue_oc_END (3)
#define SOC_SMMUV3_SMMU_S_CR1_queue_sh_START (4)
#define SOC_SMMUV3_SMMU_S_CR1_queue_sh_END (5)
#define SOC_SMMUV3_SMMU_S_CR1_table_ic_START (6)
#define SOC_SMMUV3_SMMU_S_CR1_table_ic_END (7)
#define SOC_SMMUV3_SMMU_S_CR1_table_oc_START (8)
#define SOC_SMMUV3_SMMU_S_CR1_table_oc_END (9)
#define SOC_SMMUV3_SMMU_S_CR1_table_sh_START (10)
#define SOC_SMMUV3_SMMU_S_CR1_table_sh_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int recinvsid : 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 29;
    } reg;
} SOC_SMMUV3_SMMU_S_CR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CR2_recinvsid_START (1)
#define SOC_SMMUV3_SMMU_S_CR2_recinvsid_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inv_all : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_S_INIT_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_INIT_inv_all_START (0)
#define SOC_SMMUV3_SMMU_S_INIT_inv_all_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int memattr : 4;
        unsigned int mtcfg : 1;
        unsigned int reserved_0: 3;
        unsigned int alloccfg : 4;
        unsigned int shcfg : 2;
        unsigned int nscfg : 2;
        unsigned int privcfg : 2;
        unsigned int instcfg : 2;
        unsigned int abort : 1;
        unsigned int reserved_1: 10;
        unsigned int update : 1;
    } reg;
} SOC_SMMUV3_SMMU_S_GBPA_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_GBPA_memattr_START (0)
#define SOC_SMMUV3_SMMU_S_GBPA_memattr_END (3)
#define SOC_SMMUV3_SMMU_S_GBPA_mtcfg_START (4)
#define SOC_SMMUV3_SMMU_S_GBPA_mtcfg_END (4)
#define SOC_SMMUV3_SMMU_S_GBPA_alloccfg_START (8)
#define SOC_SMMUV3_SMMU_S_GBPA_alloccfg_END (11)
#define SOC_SMMUV3_SMMU_S_GBPA_shcfg_START (12)
#define SOC_SMMUV3_SMMU_S_GBPA_shcfg_END (13)
#define SOC_SMMUV3_SMMU_S_GBPA_nscfg_START (14)
#define SOC_SMMUV3_SMMU_S_GBPA_nscfg_END (15)
#define SOC_SMMUV3_SMMU_S_GBPA_privcfg_START (16)
#define SOC_SMMUV3_SMMU_S_GBPA_privcfg_END (17)
#define SOC_SMMUV3_SMMU_S_GBPA_instcfg_START (18)
#define SOC_SMMUV3_SMMU_S_GBPA_instcfg_END (19)
#define SOC_SMMUV3_SMMU_S_GBPA_abort_START (20)
#define SOC_SMMUV3_SMMU_S_GBPA_abort_END (20)
#define SOC_SMMUV3_SMMU_S_GBPA_update_START (31)
#define SOC_SMMUV3_SMMU_S_GBPA_update_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_S_AGBPA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gerror_irqen : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_irqen : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_SMMUV3_SMMU_S_IRQ_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_IRQ_CTRL_gerror_irqen_START (0)
#define SOC_SMMUV3_SMMU_S_IRQ_CTRL_gerror_irqen_END (0)
#define SOC_SMMUV3_SMMU_S_IRQ_CTRL_eventq_irqen_START (2)
#define SOC_SMMUV3_SMMU_S_IRQ_CTRL_eventq_irqen_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gerror_irqen : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_irqen : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_SMMUV3_SMMU_S_IRQ_CTRLACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_IRQ_CTRLACK_gerror_irqen_START (0)
#define SOC_SMMUV3_SMMU_S_IRQ_CTRLACK_gerror_irqen_END (0)
#define SOC_SMMUV3_SMMU_S_IRQ_CTRLACK_eventq_irqen_START (2)
#define SOC_SMMUV3_SMMU_S_IRQ_CTRLACK_eventq_irqen_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdq_err : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_err : 1;
        unsigned int reserved_1 : 1;
        unsigned int msi_cmdq_abt_err : 1;
        unsigned int msi_eventq_abt_err : 1;
        unsigned int reserved_2 : 1;
        unsigned int msi_gerror_abt_err : 1;
        unsigned int sfm_err : 1;
        unsigned int reserved_3 : 23;
    } reg;
} SOC_SMMUV3_SMMU_S_GERROR_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_GERROR_cmdq_err_START (0)
#define SOC_SMMUV3_SMMU_S_GERROR_cmdq_err_END (0)
#define SOC_SMMUV3_SMMU_S_GERROR_eventq_abt_err_START (2)
#define SOC_SMMUV3_SMMU_S_GERROR_eventq_abt_err_END (2)
#define SOC_SMMUV3_SMMU_S_GERROR_msi_cmdq_abt_err_START (4)
#define SOC_SMMUV3_SMMU_S_GERROR_msi_cmdq_abt_err_END (4)
#define SOC_SMMUV3_SMMU_S_GERROR_msi_eventq_abt_err_START (5)
#define SOC_SMMUV3_SMMU_S_GERROR_msi_eventq_abt_err_END (5)
#define SOC_SMMUV3_SMMU_S_GERROR_msi_gerror_abt_err_START (7)
#define SOC_SMMUV3_SMMU_S_GERROR_msi_gerror_abt_err_END (7)
#define SOC_SMMUV3_SMMU_S_GERROR_sfm_err_START (8)
#define SOC_SMMUV3_SMMU_S_GERROR_sfm_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdq_err : 1;
        unsigned int reserved_0 : 1;
        unsigned int eventq_abt_err : 1;
        unsigned int reserved_1 : 1;
        unsigned int msi_cmdq_abt_err : 1;
        unsigned int msi_eventq_abt_err : 1;
        unsigned int reserved_2 : 1;
        unsigned int msi_gerror_abt_err : 1;
        unsigned int sfm_err : 1;
        unsigned int reserved_3 : 23;
    } reg;
} SOC_SMMUV3_SMMU_S_GERRORN_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_GERRORN_cmdq_err_START (0)
#define SOC_SMMUV3_SMMU_S_GERRORN_cmdq_err_END (0)
#define SOC_SMMUV3_SMMU_S_GERRORN_eventq_abt_err_START (2)
#define SOC_SMMUV3_SMMU_S_GERRORN_eventq_abt_err_END (2)
#define SOC_SMMUV3_SMMU_S_GERRORN_msi_cmdq_abt_err_START (4)
#define SOC_SMMUV3_SMMU_S_GERRORN_msi_cmdq_abt_err_END (4)
#define SOC_SMMUV3_SMMU_S_GERRORN_msi_eventq_abt_err_START (5)
#define SOC_SMMUV3_SMMU_S_GERRORN_msi_eventq_abt_err_END (5)
#define SOC_SMMUV3_SMMU_S_GERRORN_msi_gerror_abt_err_START (7)
#define SOC_SMMUV3_SMMU_S_GERRORN_msi_gerror_abt_err_END (7)
#define SOC_SMMUV3_SMMU_S_GERRORN_sfm_err_START (8)
#define SOC_SMMUV3_SMMU_S_GERRORN_sfm_err_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int addr : 30;
    } reg;
} SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_0_addr_START (2)
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_1_addr_START (0)
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG0_1_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data : 32;
    } reg;
} SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG1_data_START (0)
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG1_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int memattr : 4;
        unsigned int sh : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG2_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG2_memattr_START (0)
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG2_memattr_END (3)
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG2_sh_START (4)
#define SOC_SMMUV3_SMMU_S_GERROR_IRQ_CFG2_sh_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 6;
        unsigned int addr : 26;
    } reg;
} SOC_SMMUV3_SMMU_S_STRTAB_BASE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE0_addr_START (6)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved_0: 14;
        unsigned int ra : 1;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_S_STRTAB_BASE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE1_addr_START (0)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE1_addr_END (15)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE1_ra_START (30)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE1_ra_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log2size : 6;
        unsigned int split : 5;
        unsigned int reserved_0: 5;
        unsigned int fmt : 2;
        unsigned int reserved_1: 14;
    } reg;
} SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_log2size_START (0)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_log2size_END (5)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_split_START (6)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_split_END (10)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_fmt_START (16)
#define SOC_SMMUV3_SMMU_S_STRTAB_BASE_CFG_fmt_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log2size : 5;
        unsigned int addr : 27;
    } reg;
} SOC_SMMUV3_SMMU_S_CMDQ_BASE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE0_log2size_START (0)
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE0_log2size_END (4)
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE0_addr_START (5)
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved_0: 14;
        unsigned int ra : 1;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_S_CMDQ_BASE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE1_addr_START (0)
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE1_addr_END (15)
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE1_ra_START (30)
#define SOC_SMMUV3_SMMU_S_CMDQ_BASE1_ra_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr : 19;
        unsigned int wr_wrap : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_SMMUV3_SMMU_S_CMDQ_PROD_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CMDQ_PROD_wr_START (0)
#define SOC_SMMUV3_SMMU_S_CMDQ_PROD_wr_END (18)
#define SOC_SMMUV3_SMMU_S_CMDQ_PROD_wr_wrap_START (19)
#define SOC_SMMUV3_SMMU_S_CMDQ_PROD_wr_wrap_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd : 19;
        unsigned int rd_wrap : 1;
        unsigned int reserved_0: 4;
        unsigned int err : 7;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_S_CMDQ_CONS_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_rd_START (0)
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_rd_END (18)
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_rd_wrap_START (19)
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_rd_wrap_END (19)
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_err_START (24)
#define SOC_SMMUV3_SMMU_S_CMDQ_CONS_err_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int log2size : 5;
        unsigned int addr : 27;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_BASE0_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE0_log2size_START (0)
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE0_log2size_END (4)
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE0_addr_START (5)
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved_0: 14;
        unsigned int wa : 1;
        unsigned int reserved_1: 1;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_BASE1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE1_addr_START (0)
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE1_addr_END (15)
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE1_wa_START (30)
#define SOC_SMMUV3_SMMU_S_EVENTQ_BASE1_wa_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr : 19;
        unsigned int wr_wrap : 1;
        unsigned int reserved : 11;
        unsigned int ovflg : 1;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_PROD_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_wr_START (0)
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_wr_END (18)
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_wr_wrap_START (19)
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_wr_wrap_END (19)
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_ovflg_START (31)
#define SOC_SMMUV3_SMMU_S_EVENTQ_PROD_ovflg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd : 19;
        unsigned int rd_wrap : 1;
        unsigned int reserved : 11;
        unsigned int ovackflg : 1;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_CONS_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_rd_START (0)
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_rd_END (18)
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_rd_wrap_START (19)
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_rd_wrap_END (19)
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_ovackflg_START (31)
#define SOC_SMMUV3_SMMU_S_EVENTQ_CONS_ovackflg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 2;
        unsigned int addr : 30;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_0_addr_START (2)
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_0_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_1_addr_START (0)
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG0_1_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data : 32;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG1_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG1_data_START (0)
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG1_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int memattr : 4;
        unsigned int sh : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG2_UNION;
#endif
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG2_memattr_START (0)
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG2_memattr_END (3)
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG2_sh_START (4)
#define SOC_SMMUV3_SMMU_S_EVENTQ_IRQ_CFG2_sh_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aux_lo : 8;
        unsigned int wcs1l0_dis : 1;
        unsigned int wcs1l1_dis : 1;
        unsigned int wcs1l2_dis : 1;
        unsigned int wcs1l3_dis : 1;
        unsigned int wcs2l0_dis : 1;
        unsigned int wcs2l1_dis : 1;
        unsigned int wcs2l2_dis : 1;
        unsigned int wcs2l3_dis : 1;
        unsigned int aux_hi : 16;
    } reg;
} SOC_SMMUV3_SMMU_TCU_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_CTRL_aux_lo_START (0)
#define SOC_SMMUV3_SMMU_TCU_CTRL_aux_lo_END (7)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l0_dis_START (8)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l0_dis_END (8)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l1_dis_START (9)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l1_dis_END (9)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l2_dis_START (10)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l2_dis_END (10)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l3_dis_START (11)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs1l3_dis_END (11)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l0_dis_START (12)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l0_dis_END (12)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l1_dis_START (13)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l1_dis_END (13)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l2_dis_START (14)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l2_dis_END (14)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l3_dis_START (15)
#define SOC_SMMUV3_SMMU_TCU_CTRL_wcs2l3_dis_END (15)
#define SOC_SMMUV3_SMMU_TCU_CTRL_aux_hi_START (16)
#define SOC_SMMUV3_SMMU_TCU_CTRL_aux_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos_ptw0 : 4;
        unsigned int qos_ptw1 : 4;
        unsigned int qos_ptw2 : 4;
        unsigned int qos_ptw3 : 4;
        unsigned int qos_queue : 4;
        unsigned int qos_msi : 4;
        unsigned int qos_dvmsync : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_SMMUV3_SMMU_TCU_QOS_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw0_START (0)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw0_END (3)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw1_START (4)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw1_END (7)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw2_START (8)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw2_END (11)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw3_START (12)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_ptw3_END (15)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_queue_START (16)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_queue_END (19)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_msi_START (20)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_msi_END (23)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_dvmsync_START (24)
#define SOC_SMMUV3_SMMU_TCU_QOS_qos_dvmsync_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int xlate_slots : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SMMUV3_SMMU_TCU_CFG_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_CFG_xlate_slots_START (4)
#define SOC_SMMUV3_SMMU_TCU_CFG_xlate_slots_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int gnt_xlate_slots : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SMMUV3_SMMU_TCU_STATUS_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_STATUS_gnt_xlate_slots_START (4)
#define SOC_SMMUV3_SMMU_TCU_STATUS_gnt_xlate_slots_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ns_uarch : 1;
        unsigned int ns_ras : 1;
        unsigned int reserved_0: 1;
        unsigned int ns_init : 1;
        unsigned int reserved_1: 28;
    } reg;
} SOC_SMMUV3_SMMU_TCU_SCR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_SCR_ns_uarch_START (0)
#define SOC_SMMUV3_SMMU_TCU_SCR_ns_uarch_END (0)
#define SOC_SMMUV3_SMMU_TCU_SCR_ns_ras_START (1)
#define SOC_SMMUV3_SMMU_TCU_SCR_ns_ras_END (1)
#define SOC_SMMUV3_SMMU_TCU_SCR_ns_init_START (3)
#define SOC_SMMUV3_SMMU_TCU_SCR_ns_init_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ed : 2;
        unsigned int reserved_0: 4;
        unsigned int fi : 2;
        unsigned int reserved_1: 24;
    } reg;
} SOC_SMMUV3_SMMU_TCU_ERRFR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_ERRFR_ed_START (0)
#define SOC_SMMUV3_SMMU_TCU_ERRFR_ed_END (1)
#define SOC_SMMUV3_SMMU_TCU_ERRFR_fi_START (6)
#define SOC_SMMUV3_SMMU_TCU_ERRFR_fi_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 3;
        unsigned int fi : 1;
        unsigned int reserved_1: 28;
    } reg;
} SOC_SMMUV3_SMMU_TCU_ERRCTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_ERRCTRL_fi_START (3)
#define SOC_SMMUV3_SMMU_TCU_ERRCTRL_fi_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int serr : 8;
        unsigned int ierr : 8;
        unsigned int reserved_0: 8;
        unsigned int ce : 2;
        unsigned int reserved_1: 1;
        unsigned int of : 1;
        unsigned int reserved_2: 2;
        unsigned int v : 1;
        unsigned int reserved_3: 1;
    } reg;
} SOC_SMMUV3_SMMU_TCU_ERRSTATUS_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_serr_START (0)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_serr_END (7)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_ierr_START (8)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_ierr_END (15)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_ce_START (24)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_ce_END (25)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_of_START (27)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_of_END (27)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_v_START (30)
#define SOC_SMMUV3_SMMU_TCU_ERRSTATUS_v_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dwc : 1;
        unsigned int twc : 1;
        unsigned int dcc : 1;
        unsigned int tcc : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SMMUV3_SMMU_TCU_ERRGEN_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_dwc_START (0)
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_dwc_END (0)
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_twc_START (1)
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_twc_END (1)
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_dcc_START (2)
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_dcc_END (2)
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_tcc_START (3)
#define SOC_SMMUV3_SMMU_TCU_ERRGEN_tcc_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pri_level : 2;
        unsigned int reserved_0: 2;
        unsigned int dis_dvm : 1;
        unsigned int reserved_1: 27;
    } reg;
} SOC_SMMUV3_SMMU_TCU_NODE_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_NODE_CTRL_pri_level_START (0)
#define SOC_SMMUV3_SMMU_TCU_NODE_CTRL_pri_level_END (1)
#define SOC_SMMUV3_SMMU_TCU_NODE_CTRL_dis_dvm_START (4)
#define SOC_SMMUV3_SMMU_TCU_NODE_CTRL_dis_dvm_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int connected : 1;
        unsigned int ats : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SMMUV3_SMMU_TCU_NODE_STATUS_UNION;
#endif
#define SOC_SMMUV3_SMMU_TCU_NODE_STATUS_connected_START (0)
#define SOC_SMMUV3_SMMU_TCU_NODE_STATUS_connected_END (0)
#define SOC_SMMUV3_SMMU_TCU_NODE_STATUS_ats_START (1)
#define SOC_SMMUV3_SMMU_TCU_NODE_STATUS_ats_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_en_req : 1;
        unsigned int hazard_dis : 1;
        unsigned int mtlb_dis : 1;
        unsigned int utlb_dis : 1;
        unsigned int clk_gt_ctrl : 2;
        unsigned int reserved_0 : 2;
        unsigned int max_tok_trans : 8;
        unsigned int pref_qos : 4;
        unsigned int cmd_hazard_size : 2;
        unsigned int pref_hazard_size : 2;
        unsigned int cmd_qos : 4;
        unsigned int cmd_qos_en : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SMMUV3_SMMU_TBU_CR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_CR_tbu_en_req_START (0)
#define SOC_SMMUV3_SMMU_TBU_CR_tbu_en_req_END (0)
#define SOC_SMMUV3_SMMU_TBU_CR_hazard_dis_START (1)
#define SOC_SMMUV3_SMMU_TBU_CR_hazard_dis_END (1)
#define SOC_SMMUV3_SMMU_TBU_CR_mtlb_dis_START (2)
#define SOC_SMMUV3_SMMU_TBU_CR_mtlb_dis_END (2)
#define SOC_SMMUV3_SMMU_TBU_CR_utlb_dis_START (3)
#define SOC_SMMUV3_SMMU_TBU_CR_utlb_dis_END (3)
#define SOC_SMMUV3_SMMU_TBU_CR_clk_gt_ctrl_START (4)
#define SOC_SMMUV3_SMMU_TBU_CR_clk_gt_ctrl_END (5)
#define SOC_SMMUV3_SMMU_TBU_CR_max_tok_trans_START (8)
#define SOC_SMMUV3_SMMU_TBU_CR_max_tok_trans_END (15)
#define SOC_SMMUV3_SMMU_TBU_CR_pref_qos_START (16)
#define SOC_SMMUV3_SMMU_TBU_CR_pref_qos_END (19)
#define SOC_SMMUV3_SMMU_TBU_CR_cmd_hazard_size_START (20)
#define SOC_SMMUV3_SMMU_TBU_CR_cmd_hazard_size_END (21)
#define SOC_SMMUV3_SMMU_TBU_CR_pref_hazard_size_START (22)
#define SOC_SMMUV3_SMMU_TBU_CR_pref_hazard_size_END (23)
#define SOC_SMMUV3_SMMU_TBU_CR_cmd_qos_START (24)
#define SOC_SMMUV3_SMMU_TBU_CR_cmd_qos_END (27)
#define SOC_SMMUV3_SMMU_TBU_CR_cmd_qos_en_START (28)
#define SOC_SMMUV3_SMMU_TBU_CR_cmd_qos_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tbu_en_ack : 1;
        unsigned int tbu_connected : 1;
        unsigned int reserved_0 : 6;
        unsigned int tok_trans_gnt : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SMMUV3_SMMU_TBU_CRACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_CRACK_tbu_en_ack_START (0)
#define SOC_SMMUV3_SMMU_TBU_CRACK_tbu_en_ack_END (0)
#define SOC_SMMUV3_SMMU_TBU_CRACK_tbu_connected_START (1)
#define SOC_SMMUV3_SMMU_TBU_CRACK_tbu_connected_END (1)
#define SOC_SMMUV3_SMMU_TBU_CRACK_tok_trans_gnt_START (8)
#define SOC_SMMUV3_SMMU_TBU_CRACK_tok_trans_gnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ns_uarch : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_TBU_SCR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_SCR_ns_uarch_START (0)
#define SOC_SMMUV3_SMMU_TBU_SCR_ns_uarch_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr4 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR4_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR4_smmu_tbu_pidr4_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR4_smmu_tbu_pidr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr5 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR5_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR5_smmu_tbu_pidr5_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR5_smmu_tbu_pidr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr6 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR6_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR6_smmu_tbu_pidr6_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR6_smmu_tbu_pidr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr7 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR7_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR7_smmu_tbu_pidr7_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR7_smmu_tbu_pidr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR0_smmu_tbu_pidr0_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR0_smmu_tbu_pidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR1_smmu_tbu_pidr1_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR1_smmu_tbu_pidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR2_smmu_tbu_pidr2_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR2_smmu_tbu_pidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_pidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PIDR3_smmu_tbu_pidr3_START (0)
#define SOC_SMMUV3_SMMU_TBU_PIDR3_smmu_tbu_pidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_cidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_CIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_CIDR0_smmu_tbu_cidr0_START (0)
#define SOC_SMMUV3_SMMU_TBU_CIDR0_smmu_tbu_cidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_cidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_CIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_CIDR1_smmu_tbu_cidr1_START (0)
#define SOC_SMMUV3_SMMU_TBU_CIDR1_smmu_tbu_cidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_cidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_CIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_CIDR2_smmu_tbu_cidr2_START (0)
#define SOC_SMMUV3_SMMU_TBU_CIDR2_smmu_tbu_cidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_tbu_cidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_CIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_CIDR3_smmu_tbu_cidr3_START (0)
#define SOC_SMMUV3_SMMU_TBU_CIDR3_smmu_tbu_cidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int evcntr : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_EVCNTR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVCNTR_evcntr_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVCNTR_evcntr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event : 8;
        unsigned int reserved : 21;
        unsigned int filter_sid_span : 1;
        unsigned int filter_sec_sid : 1;
        unsigned int ovfcap : 1;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_event_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_event_END (7)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_filter_sid_span_START (29)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_filter_sid_span_END (29)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_filter_sec_sid_START (30)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_filter_sec_sid_END (30)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_ovfcap_START (31)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER0_ovfcap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event : 8;
        unsigned int reserved : 23;
        unsigned int ovfcap : 1;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER_event_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER_event_END (7)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER_ovfcap_START (31)
#define SOC_SMMUV3_SMMU_TBU_PMCG_EVTYPER_ovfcap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svr : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_SVR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_SVR_svr_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SVR_svr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int streamid : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_SMR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_SMR_streamid_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SMR_streamid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnten : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_0_cnten_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_0_cnten_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CNTENSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cntclr : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_0_cntclr_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_0_cntclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CNTENCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inten : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_0_inten_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_0_inten_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_INTENSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intclr : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_0_intclr_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_0_intclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_INTENCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ovsclr : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_0_ovsclr_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_0_ovsclr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_OVSCLR0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ovsset : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_0_ovsset_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_0_ovsset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_OVSSET0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int capture : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CAPR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CAPR_capture_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CAPR_capture_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int so : 1;
        unsigned int nsra : 1;
        unsigned int nsmsi : 1;
        unsigned int reserved : 28;
        unsigned int readasone : 1;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_SCR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_so_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_so_END (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_nsra_START (1)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_nsra_END (1)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_nsmsi_START (2)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_nsmsi_END (2)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_readasone_START (31)
#define SOC_SMMUV3_SMMU_TBU_PMCG_SCR_readasone_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nctr : 6;
        unsigned int reserved_0 : 2;
        unsigned int size : 6;
        unsigned int reserved_1 : 6;
        unsigned int reloc_ctrs : 1;
        unsigned int msi : 1;
        unsigned int capture : 1;
        unsigned int sid_filter_type : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_nctr_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_nctr_END (5)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_size_START (8)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_size_END (13)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_reloc_ctrs_START (20)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_reloc_ctrs_END (20)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_msi_START (21)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_msi_END (21)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_capture_START (22)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_capture_END (22)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_sid_filter_type_START (23)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CFGR_sid_filter_type_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int e : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CR_e_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CR_e_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_0_event_en_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_0_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_1_event_en_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID0_1_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_0_event_en_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_0_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_1_event_en_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CEID1_1_event_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irqen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRL_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRL_irqen_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRL_irqen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irqen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRLACK_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRLACK_irqen_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CTRLACK_irqen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_IRQ_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int archminorrev : 4;
        unsigned int archmajorrev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_AIDR_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_AIDR_archminorrev_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_AIDR_archminorrev_END (3)
#define SOC_SMMUV3_SMMU_TBU_PMCG_AIDR_archmajorrev_START (4)
#define SOC_SMMUV3_SMMU_TBU_PMCG_AIDR_archmajorrev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pmauthstatus : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PMAUTHSTATUS_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PMAUTHSTATUS_smmu_pmcg_pmauthstatus_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PMAUTHSTATUS_smmu_pmcg_pmauthstatus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr4 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR4_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR4_smmu_pmcg_pidr4_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR4_smmu_pmcg_pidr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr5 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR5_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR5_smmu_pmcg_pidr5_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR5_smmu_pmcg_pidr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr6 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR6_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR6_smmu_pmcg_pidr6_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR6_smmu_pmcg_pidr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr7 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR7_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR7_smmu_pmcg_pidr7_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR7_smmu_pmcg_pidr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR0_smmu_pmcg_pidr0_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR0_smmu_pmcg_pidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR1_smmu_pmcg_pidr1_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR1_smmu_pmcg_pidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR2_smmu_pmcg_pidr2_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR2_smmu_pmcg_pidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_pidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_PIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR3_smmu_pmcg_pidr3_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_PIDR3_smmu_pmcg_pidr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr0 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CIDR0_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR0_smmu_pmcg_cidr0_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR0_smmu_pmcg_cidr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr1 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CIDR1_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR1_smmu_pmcg_cidr1_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR1_smmu_pmcg_cidr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr2 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CIDR2_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR2_smmu_pmcg_cidr2_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR2_smmu_pmcg_cidr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_pmcg_cidr3 : 32;
    } reg;
} SOC_SMMUV3_SMMU_TBU_PMCG_CIDR3_UNION;
#endif
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR3_smmu_pmcg_cidr3_START (0)
#define SOC_SMMUV3_SMMU_TBU_PMCG_CIDR3_smmu_pmcg_cidr3_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
