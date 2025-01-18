#ifndef __SOC_MEDIACOMMON_INTERFACE_H__
#define __SOC_MEDIACOMMON_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_MDC_TAG_ADDR(base) ((base) + (0x0000UL))
#define SOC_MediaCommon_APB_CTL_ADDR(base) ((base) + (0x0004UL))
#define SOC_MediaCommon_MDC_AXI_RST_EN_ADDR(base) ((base) + (0x118UL))
#define SOC_MediaCommon_MDC_APB_RST_EN_ADDR(base) ((base) + (0x11CUL))
#define SOC_MediaCommon_MDC_CORE_RST_EN_ADDR(base) ((base) + (0x120UL))
#define SOC_MediaCommon_MCU_OFF_INTS_ADDR(base) ((base) + (0x21CUL))
#define SOC_MediaCommon_MCU_OFF_INT_MSK_ADDR(base) ((base) + (0x220UL))
#define SOC_MediaCommon_MCU_OFF_CAM_INTS_ADDR(base) ((base) + (0x2B4UL))
#define SOC_MediaCommon_MCU_OFF_CAM_INT_MSK_ADDR(base) ((base) + (0x2B8UL))
#define SOC_MediaCommon_R8_INTS_ADDR(base) ((base) + (0x224UL))
#define SOC_MediaCommon_R8_INT_MSK_ADDR(base) ((base) + (0x228UL))
#define SOC_MediaCommon_ACPU_OFF_INTS_ADDR(base) ((base) + (0x234UL))
#define SOC_MediaCommon_ACPU_OFF_INT_MSK_ADDR(base) ((base) + (0x238UL))
#define SOC_MediaCommon_ACPU_OFF_CAM_INTS_ADDR(base) ((base) + (0x2ACUL))
#define SOC_MediaCommon_ACPU_OFF_CAM_INT_MSK_ADDR(base) ((base) + (0x2B0UL))
#define SOC_MediaCommon_MODULE_CLK_SEL_ADDR(base) ((base) + (0x0300UL))
#define SOC_MediaCommon_MODULE_CLK_EN_ADDR(base) ((base) + (0x304UL))
#define SOC_MediaCommon_GLB0_DBG_SEL_ADDR(base) ((base) + (0x310UL))
#define SOC_MediaCommon_DBG_IRQ_ACPU_ADDR(base) ((base) + (0x320UL))
#define SOC_MediaCommon_DBG_IRQ_MCU_ADDR(base) ((base) + (0x324UL))
#define SOC_MediaCommon_MDC_GLB_DBG_ADDR(base) ((base) + (0x0404UL))
#define SOC_MediaCommon_DSS_SPRAM_CTRL_ADDR(base) ((base) + (0x0600UL))
#define SOC_MediaCommon_DSS_PM_CTRL_ADDR(base) ((base) + (0x0604UL))
#define SOC_MediaCommon_GLB_DSLP_EN_ADDR(base) ((base) + (0x0608UL))
#define SOC_MediaCommon_DSS_TPRAM_CTRL_ADDR(base) ((base) + (0x060CUL))
#else
#define SOC_MediaCommon_MDC_TAG_ADDR(base) ((base) + (0x0000))
#define SOC_MediaCommon_APB_CTL_ADDR(base) ((base) + (0x0004))
#define SOC_MediaCommon_MDC_AXI_RST_EN_ADDR(base) ((base) + (0x118))
#define SOC_MediaCommon_MDC_APB_RST_EN_ADDR(base) ((base) + (0x11C))
#define SOC_MediaCommon_MDC_CORE_RST_EN_ADDR(base) ((base) + (0x120))
#define SOC_MediaCommon_MCU_OFF_INTS_ADDR(base) ((base) + (0x21C))
#define SOC_MediaCommon_MCU_OFF_INT_MSK_ADDR(base) ((base) + (0x220))
#define SOC_MediaCommon_MCU_OFF_CAM_INTS_ADDR(base) ((base) + (0x2B4))
#define SOC_MediaCommon_MCU_OFF_CAM_INT_MSK_ADDR(base) ((base) + (0x2B8))
#define SOC_MediaCommon_R8_INTS_ADDR(base) ((base) + (0x224))
#define SOC_MediaCommon_R8_INT_MSK_ADDR(base) ((base) + (0x228))
#define SOC_MediaCommon_ACPU_OFF_INTS_ADDR(base) ((base) + (0x234))
#define SOC_MediaCommon_ACPU_OFF_INT_MSK_ADDR(base) ((base) + (0x238))
#define SOC_MediaCommon_ACPU_OFF_CAM_INTS_ADDR(base) ((base) + (0x2AC))
#define SOC_MediaCommon_ACPU_OFF_CAM_INT_MSK_ADDR(base) ((base) + (0x2B0))
#define SOC_MediaCommon_MODULE_CLK_SEL_ADDR(base) ((base) + (0x0300))
#define SOC_MediaCommon_MODULE_CLK_EN_ADDR(base) ((base) + (0x304))
#define SOC_MediaCommon_GLB0_DBG_SEL_ADDR(base) ((base) + (0x310))
#define SOC_MediaCommon_DBG_IRQ_ACPU_ADDR(base) ((base) + (0x320))
#define SOC_MediaCommon_DBG_IRQ_MCU_ADDR(base) ((base) + (0x324))
#define SOC_MediaCommon_MDC_GLB_DBG_ADDR(base) ((base) + (0x0404))
#define SOC_MediaCommon_DSS_SPRAM_CTRL_ADDR(base) ((base) + (0x0600))
#define SOC_MediaCommon_DSS_PM_CTRL_ADDR(base) ((base) + (0x0604))
#define SOC_MediaCommon_GLB_DSLP_EN_ADDR(base) ((base) + (0x0608))
#define SOC_MediaCommon_DSS_TPRAM_CTRL_ADDR(base) ((base) + (0x060C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_PMM_OFF_INTS_ADDR(base) ((base) + (0x0010UL))
#define SOC_MediaCommon_PMM_OFF_INT_MSK_ADDR(base) ((base) + (0x0014UL))
#define SOC_MediaCommon_PMM_OFF_CAM_INTS_ADDR(base) ((base) + (0x0018UL))
#define SOC_MediaCommon_PMM_OFF_CAM_INT_MSK_ADDR(base) ((base) + (0x001CUL))
#define SOC_MediaCommon_DBG_IRQ_PMM_ADDR(base) ((base) + (0x0020UL))
#else
#define SOC_MediaCommon_PMM_OFF_INTS_ADDR(base) ((base) + (0x0010))
#define SOC_MediaCommon_PMM_OFF_INT_MSK_ADDR(base) ((base) + (0x0014))
#define SOC_MediaCommon_PMM_OFF_CAM_INTS_ADDR(base) ((base) + (0x0018))
#define SOC_MediaCommon_PMM_OFF_CAM_INT_MSK_ADDR(base) ((base) + (0x001C))
#define SOC_MediaCommon_DBG_IRQ_PMM_ADDR(base) ((base) + (0x0020))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_REG2CTRL_LBS_EN_ADDR(base) ((base) + (0x0100UL))
#define SOC_MediaCommon_REG2LBS_LBS_FRM_LEN_ADDR(base) ((base) + (0x0104UL))
#define SOC_MediaCommon_DBG_BUS_MODE_ADDR(base) ((base) + (0x0108UL))
#define SOC_MediaCommon_REG2LBS_LBS_FRM_ADDR(base) ((base) + (0x010CUL))
#define SOC_MediaCommon_REG2LBS_LBS_ID_ADDR(base) ((base) + (0x0110UL))
#define SOC_MediaCommon_REG2LBS_BUS_MSK_ADDR(base) ((base) + (0x0114UL))
#define SOC_MediaCommon_REG2HEAD_DIAG_ID_ADDR(base) ((base) + (0x0118UL))
#define SOC_MediaCommon_REG2HEAD_HSRV_ID_ADDR(base) ((base) + (0x011CUL))
#define SOC_MediaCommon_REG2HEAD_LSRV_ID_ADDR(base) ((base) + (0x0120UL))
#define SOC_MediaCommon_REG2HEAD_SESSION_ID_ADDR(base) ((base) + (0x0124UL))
#define SOC_MediaCommon_REG2HEAD_MSG_TYPE_ADDR(base) ((base) + (0x0128UL))
#define SOC_MediaCommon_DBG_BUS_BASE_ADDR_ADDR(base) ((base) + (0x012CUL))
#define SOC_MediaCommon_DBG_BUS_END_ADDR_ADDR(base) ((base) + (0x0130UL))
#define SOC_MediaCommon_DBG_PTR_ADDR_ADDR(base) ((base) + (0x0134UL))
#define SOC_MediaCommon_DBG_BUS_TIMING_ADDR(base) ((base) + (0x0138UL))
#define SOC_MediaCommon_DBG_BUS_LDI_SEL_ADDR(base) ((base) + (0x013CUL))
#define SOC_MediaCommon_DBG_BUS_END_ADDR(base) ((base) + (0x0140UL))
#define SOC_MediaCommon_REG2MEM_GATE_SEL_ADDR(base) ((base) + (0x0144UL))
#define SOC_MediaCommon_SP_MEM_CTRL0_LOG_ADDR(base) ((base) + (0x0148UL))
#define SOC_MediaCommon_TP_MEM_CTRL0_ADDR(base) ((base) + (0x014CUL))
#define SOC_MediaCommon_DBG_BUS_TIMING_SEL_ADDR(base) ((base) + (0x0150UL))
#define SOC_MediaCommon_MDC_DBG_WPTR_ADDR(base) ((base) + (0x0154UL))
#define SOC_MediaCommon_DBG_MCTL_INTS_ADDR(base) ((base) + (0x23CUL))
#define SOC_MediaCommon_DBG_MCTL_INT_MSK_ADDR(base) ((base) + (0x240UL))
#define SOC_MediaCommon_DBG_WCH1_INTS_ADDR(base) ((base) + (0x24CUL))
#define SOC_MediaCommon_DBG_WCH1_INT_MSK_ADDR(base) ((base) + (0x250UL))
#define SOC_MediaCommon_DBG_RCH_INTS_ADDR(base) ((base) + (0x264UL))
#define SOC_MediaCommon_DBG_RCH_V0_INT_MSK_ADDR(base) ((base) + (0x268UL))
#define SOC_MediaCommon_MDC_GLB_INTS_ADDR(base) ((base) + (0x294UL))
#define SOC_MediaCommon_MDC_GLB_INT_MSK_ADDR(base) ((base) + (0x298UL))
#else
#define SOC_MediaCommon_REG2CTRL_LBS_EN_ADDR(base) ((base) + (0x0100))
#define SOC_MediaCommon_REG2LBS_LBS_FRM_LEN_ADDR(base) ((base) + (0x0104))
#define SOC_MediaCommon_DBG_BUS_MODE_ADDR(base) ((base) + (0x0108))
#define SOC_MediaCommon_REG2LBS_LBS_FRM_ADDR(base) ((base) + (0x010C))
#define SOC_MediaCommon_REG2LBS_LBS_ID_ADDR(base) ((base) + (0x0110))
#define SOC_MediaCommon_REG2LBS_BUS_MSK_ADDR(base) ((base) + (0x0114))
#define SOC_MediaCommon_REG2HEAD_DIAG_ID_ADDR(base) ((base) + (0x0118))
#define SOC_MediaCommon_REG2HEAD_HSRV_ID_ADDR(base) ((base) + (0x011C))
#define SOC_MediaCommon_REG2HEAD_LSRV_ID_ADDR(base) ((base) + (0x0120))
#define SOC_MediaCommon_REG2HEAD_SESSION_ID_ADDR(base) ((base) + (0x0124))
#define SOC_MediaCommon_REG2HEAD_MSG_TYPE_ADDR(base) ((base) + (0x0128))
#define SOC_MediaCommon_DBG_BUS_BASE_ADDR_ADDR(base) ((base) + (0x012C))
#define SOC_MediaCommon_DBG_BUS_END_ADDR_ADDR(base) ((base) + (0x0130))
#define SOC_MediaCommon_DBG_PTR_ADDR_ADDR(base) ((base) + (0x0134))
#define SOC_MediaCommon_DBG_BUS_TIMING_ADDR(base) ((base) + (0x0138))
#define SOC_MediaCommon_DBG_BUS_LDI_SEL_ADDR(base) ((base) + (0x013C))
#define SOC_MediaCommon_DBG_BUS_END_ADDR(base) ((base) + (0x0140))
#define SOC_MediaCommon_REG2MEM_GATE_SEL_ADDR(base) ((base) + (0x0144))
#define SOC_MediaCommon_SP_MEM_CTRL0_LOG_ADDR(base) ((base) + (0x0148))
#define SOC_MediaCommon_TP_MEM_CTRL0_ADDR(base) ((base) + (0x014C))
#define SOC_MediaCommon_DBG_BUS_TIMING_SEL_ADDR(base) ((base) + (0x0150))
#define SOC_MediaCommon_MDC_DBG_WPTR_ADDR(base) ((base) + (0x0154))
#define SOC_MediaCommon_DBG_MCTL_INTS_ADDR(base) ((base) + (0x23C))
#define SOC_MediaCommon_DBG_MCTL_INT_MSK_ADDR(base) ((base) + (0x240))
#define SOC_MediaCommon_DBG_WCH1_INTS_ADDR(base) ((base) + (0x24C))
#define SOC_MediaCommon_DBG_WCH1_INT_MSK_ADDR(base) ((base) + (0x250))
#define SOC_MediaCommon_DBG_RCH_INTS_ADDR(base) ((base) + (0x264))
#define SOC_MediaCommon_DBG_RCH_V0_INT_MSK_ADDR(base) ((base) + (0x268))
#define SOC_MediaCommon_MDC_GLB_INTS_ADDR(base) ((base) + (0x294))
#define SOC_MediaCommon_MDC_GLB_INT_MSK_ADDR(base) ((base) + (0x298))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_CMDLIST_CH_PENDING_CLR_ADDR(base,i) ((base) + (0x0000+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ADDR(base,i) ((base) + (0x0004+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ADDR(base,i) ((base) + (0x0008+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_STAAD_ADDR(base,i) ((base) + (0x000C+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_CURAD_ADDR(base,i) ((base) + (0x0010+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_INTE_ADDR(base,i) ((base) + (0x0014+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_INTC_ADDR(base,i) ((base) + (0x0018+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_INTS_ADDR(base,i) ((base) + (0x001C+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_DBG_ADDR(base,i) ((base) + (0x0028+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_DBG_ADDR(base) ((base) + (0x0700UL))
#define SOC_MediaCommon_BUF_DBG_EN_ADDR(base) ((base) + (0x0704UL))
#define SOC_MediaCommon_BUF_DBG_CNT_CLR_ADDR(base) ((base) + (0x0708UL))
#define SOC_MediaCommon_BUF_DBG_CNT_ADDR(base) ((base) + (0x070CUL))
#define SOC_MediaCommon_CMDLIST_TIMEOUT_TH_ADDR(base) ((base) + (0x0710UL))
#define SOC_MediaCommon_CMDLIST_START_ADDR(base) ((base) + (0x0714UL))
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_EN_ADDR(base) ((base) + (0x0718UL))
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_DIS_ADDR(base) ((base) + (0x071CUL))
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_STATUS_ADDR(base) ((base) + (0x0720UL))
#define SOC_MediaCommon_CMDLIST_TASK_CONTINUE_ADDR(base) ((base) + (0x0724UL))
#define SOC_MediaCommon_CMDLIST_TASK_STATUS_ADDR(base) ((base) + (0x0728UL))
#define SOC_MediaCommon_CMDLIST_CTRL_ADDR(base) ((base) + (0x072CUL))
#define SOC_MediaCommon_CMDLIST_SECU_ADDR(base) ((base) + (0x0730UL))
#define SOC_MediaCommon_CMDLIST_INTS_ADDR(base) ((base) + (0x0734UL))
#define SOC_MediaCommon_CMDLIST_SWRST_ADDR(base) ((base) + (0x0738UL))
#define SOC_MediaCommon_CMD_MEM_CTRL_ADDR(base) ((base) + (0x073CUL))
#define SOC_MediaCommon_CMD_CLK_SEL_ADDR(base) ((base) + (0x0740UL))
#define SOC_MediaCommon_CMD_CLK_EN_ADDR(base) ((base) + (0x0744UL))
#else
#define SOC_MediaCommon_CMDLIST_CH_PENDING_CLR_ADDR(base,i) ((base) + (0x0000+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ADDR(base,i) ((base) + (0x0004+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ADDR(base,i) ((base) + (0x0008+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_STAAD_ADDR(base,i) ((base) + (0x000C+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_CURAD_ADDR(base,i) ((base) + (0x0010+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_INTE_ADDR(base,i) ((base) + (0x0014+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_INTC_ADDR(base,i) ((base) + (0x0018+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_INTS_ADDR(base,i) ((base) + (0x001C+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_CH_DBG_ADDR(base,i) ((base) + (0x0028+0x40*(i)))
#define SOC_MediaCommon_CMDLIST_DBG_ADDR(base) ((base) + (0x0700))
#define SOC_MediaCommon_BUF_DBG_EN_ADDR(base) ((base) + (0x0704))
#define SOC_MediaCommon_BUF_DBG_CNT_CLR_ADDR(base) ((base) + (0x0708))
#define SOC_MediaCommon_BUF_DBG_CNT_ADDR(base) ((base) + (0x070C))
#define SOC_MediaCommon_CMDLIST_TIMEOUT_TH_ADDR(base) ((base) + (0x0710))
#define SOC_MediaCommon_CMDLIST_START_ADDR(base) ((base) + (0x0714))
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_EN_ADDR(base) ((base) + (0x0718))
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_DIS_ADDR(base) ((base) + (0x071C))
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_STATUS_ADDR(base) ((base) + (0x0720))
#define SOC_MediaCommon_CMDLIST_TASK_CONTINUE_ADDR(base) ((base) + (0x0724))
#define SOC_MediaCommon_CMDLIST_TASK_STATUS_ADDR(base) ((base) + (0x0728))
#define SOC_MediaCommon_CMDLIST_CTRL_ADDR(base) ((base) + (0x072C))
#define SOC_MediaCommon_CMDLIST_SECU_ADDR(base) ((base) + (0x0730))
#define SOC_MediaCommon_CMDLIST_INTS_ADDR(base) ((base) + (0x0734))
#define SOC_MediaCommon_CMDLIST_SWRST_ADDR(base) ((base) + (0x0738))
#define SOC_MediaCommon_CMD_MEM_CTRL_ADDR(base) ((base) + (0x073C))
#define SOC_MediaCommon_CMD_CLK_SEL_ADDR(base) ((base) + (0x0740))
#define SOC_MediaCommon_CMD_CLK_EN_ADDR(base) ((base) + (0x0744))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_AIF_CH_CTL_0_ADDR(base) ((base) + (0x0000UL))
#define SOC_MediaCommon_AIF_CH_HS_0_ADDR(base) ((base) + (0x0004UL))
#define SOC_MediaCommon_AIF_CH_LS_0_ADDR(base) ((base) + (0x0008UL))
#define SOC_MediaCommon_AIF_CH_CTL_1_ADDR(base) ((base) + (0x0020UL))
#define SOC_MediaCommon_AIF_CH_HS_1_ADDR(base) ((base) + (0x0024UL))
#define SOC_MediaCommon_AIF_CH_LS_1_ADDR(base) ((base) + (0x0028UL))
#define SOC_MediaCommon_AIF_CH_CTL_2_ADDR(base) ((base) + (0x0040UL))
#define SOC_MediaCommon_AIF_CH_HS_2_ADDR(base) ((base) + (0x0044UL))
#define SOC_MediaCommon_AIF_CH_LS_2_ADDR(base) ((base) + (0x0048UL))
#define SOC_MediaCommon_AIF_CH_CTL_3_ADDR(base) ((base) + (0x0060UL))
#define SOC_MediaCommon_AIF_CH_HS_3_ADDR(base) ((base) + (0x0064UL))
#define SOC_MediaCommon_AIF_CH_LS_3_ADDR(base) ((base) + (0x0068UL))
#define SOC_MediaCommon_AIF_CH_CTL_4_ADDR(base) ((base) + (0x0080UL))
#define SOC_MediaCommon_AIF_CH_HS_4_ADDR(base) ((base) + (0x0084UL))
#define SOC_MediaCommon_AIF_CH_LS_4_ADDR(base) ((base) + (0x0088UL))
#define SOC_MediaCommon_AIF_CH_CTL_5_ADDR(base) ((base) + (0x00A0UL))
#define SOC_MediaCommon_AIF_CH_HS_5_ADDR(base) ((base) + (0x00A4UL))
#define SOC_MediaCommon_AIF_CH_LS_5_ADDR(base) ((base) + (0x00A8UL))
#define SOC_MediaCommon_AIF_CH_CTL_6_ADDR(base) ((base) + (0x00C0UL))
#define SOC_MediaCommon_AIF_CH_HS_6_ADDR(base) ((base) + (0x00C4UL))
#define SOC_MediaCommon_AIF_CH_LS_6_ADDR(base) ((base) + (0x00C8UL))
#define SOC_MediaCommon_AIF_CH_CTL_7_ADDR(base) ((base) + (0x00E0UL))
#define SOC_MediaCommon_AIF_CH_HS_7_ADDR(base) ((base) + (0x00E4UL))
#define SOC_MediaCommon_AIF_CH_LS_7_ADDR(base) ((base) + (0x00E8UL))
#define SOC_MediaCommon_AIF_CH_CTL_8_ADDR(base) ((base) + (0x0100UL))
#define SOC_MediaCommon_AIF_CH_HS_8_ADDR(base) ((base) + (0x0104UL))
#define SOC_MediaCommon_AIF_CH_LS_8_ADDR(base) ((base) + (0x0108UL))
#define SOC_MediaCommon_AIF_CH_CTL_9_ADDR(base) ((base) + (0x0120UL))
#define SOC_MediaCommon_AIF_CH_HS_9_ADDR(base) ((base) + (0x0124UL))
#define SOC_MediaCommon_AIF_CH_LS_9_ADDR(base) ((base) + (0x0128UL))
#define SOC_MediaCommon_AIF_CH_CTL_10_ADDR(base) ((base) + (0x0140UL))
#define SOC_MediaCommon_AIF_CH_HS_10_ADDR(base) ((base) + (0x0144UL))
#define SOC_MediaCommon_AIF_CH_LS_10_ADDR(base) ((base) + (0x0148UL))
#define SOC_MediaCommon_AIF_CH_CTL_11_ADDR(base) ((base) + (0x0160UL))
#define SOC_MediaCommon_AIF_CH_HS_11_ADDR(base) ((base) + (0x0164UL))
#define SOC_MediaCommon_AIF_CH_LS_11_ADDR(base) ((base) + (0x0168UL))
#define SOC_MediaCommon_AIF_CH_CTL_12_ADDR(base) ((base) + (0x0180UL))
#define SOC_MediaCommon_AIF_CH_HS_12_ADDR(base) ((base) + (0x0184UL))
#define SOC_MediaCommon_AIF_CH_LS_12_ADDR(base) ((base) + (0x0188UL))
#define SOC_MediaCommon_AIF_CH_MID_0_ADDR(base) ((base) + (0x0400UL))
#define SOC_MediaCommon_AIF_CH_MID_1_ADDR(base) ((base) + (0x0404UL))
#define SOC_MediaCommon_AIF_CH_MID_2_ADDR(base) ((base) + (0x0408UL))
#define SOC_MediaCommon_AIF_CH_MID_3_ADDR(base) ((base) + (0x040CUL))
#define SOC_MediaCommon_AIF_CH_MID_4_ADDR(base) ((base) + (0x0410UL))
#define SOC_MediaCommon_AIF_CH_MID_5_ADDR(base) ((base) + (0x0414UL))
#define SOC_MediaCommon_AIF_CH_MID_6_ADDR(base) ((base) + (0x0418UL))
#define SOC_MediaCommon_AIF_CH_MID_7_ADDR(base) ((base) + (0x041CUL))
#define SOC_MediaCommon_AIF_CH_MID_8_ADDR(base) ((base) + (0x0420UL))
#define SOC_MediaCommon_AIF_CH_MID_9_ADDR(base) ((base) + (0x0424UL))
#define SOC_MediaCommon_AIF_CH_MID_10_ADDR(base) ((base) + (0x0428UL))
#define SOC_MediaCommon_AIF_CH_MID_11_ADDR(base) ((base) + (0x042CUL))
#define SOC_MediaCommon_AIF_CH_MID_12_ADDR(base) ((base) + (0x0430UL))
#define SOC_MediaCommon_AIF_CH_MID_CMD_ADDR(base) ((base) + (0x0434UL))
#define SOC_MediaCommon_DSS0_MID_ADDR(base) ((base) + (0x0438UL))
#define SOC_MediaCommon_DSS1_MID_ADDR(base) ((base) + (0x043CUL))
#define SOC_MediaCommon_AXI0_RID_MSK0_ADDR(base) ((base) + (0x0800UL))
#define SOC_MediaCommon_AXI0_RID_MSK1_ADDR(base) ((base) + (0x0804UL))
#define SOC_MediaCommon_AXI0_WID_MSK_ADDR(base) ((base) + (0x0808UL))
#define SOC_MediaCommon_AXI0_R_QOS_MAP_ADDR(base) ((base) + (0x080CUL))
#define SOC_MediaCommon_AXI1_RID_MSK0_ADDR(base) ((base) + (0x0810UL))
#define SOC_MediaCommon_AXI1_RID_MSK1_ADDR(base) ((base) + (0x0814UL))
#define SOC_MediaCommon_AXI1_WID_MSK_ADDR(base) ((base) + (0x0818UL))
#define SOC_MediaCommon_AXI1_R_QOS_MAP_ADDR(base) ((base) + (0x081CUL))
#define SOC_MediaCommon_AIF_CLK_SEL0_ADDR(base) ((base) + (0x0820UL))
#define SOC_MediaCommon_AIF_CLK_SEL1_ADDR(base) ((base) + (0x0824UL))
#define SOC_MediaCommon_AIF_CLK_EN0_ADDR(base) ((base) + (0x0828UL))
#define SOC_MediaCommon_AIF_CLK_EN1_ADDR(base) ((base) + (0x082CUL))
#define SOC_MediaCommon_AIF_CH_CTL_CMD_ADDR(base) ((base) + (0x0830UL))
#define SOC_MediaCommon_MONITOR_TIMER_INI_ADDR(base) ((base) + (0x0834UL))
#define SOC_MediaCommon_DEBUG_BUF_BASE_ADDR(base) ((base) + (0x0838UL))
#define SOC_MediaCommon_DEBUG_CTRL_ADDR(base) ((base) + (0x083CUL))
#define SOC_MediaCommon_AIF_SHADOW_READ_ADDR(base) ((base) + (0x0840UL))
#define SOC_MediaCommon_AIF_MEM_CTRL_ADDR(base) ((base) + (0x0844UL))
#define SOC_MediaCommon_MONITOR_EN_ADDR(base) ((base) + (0x0848UL))
#define SOC_MediaCommon_MONITOR_CTRL_ADDR(base) ((base) + (0x084CUL))
#define SOC_MediaCommon_MONITOR_SAMPLE_MUN_ADDR(base) ((base) + (0x0850UL))
#define SOC_MediaCommon_MONITOR_SAMPLE_TIME_ADDR(base) ((base) + (0x0854UL))
#define SOC_MediaCommon_MONITOR_SAMPLE_FLOW_ADDR(base) ((base) + (0x0858UL))
#define SOC_MediaCommon_MONITOR_WR_ST_0_ADDR(base) ((base) + (0x0870UL))
#define SOC_MediaCommon_MONITOR_WR_ST_1_ADDR(base) ((base) + (0x0880UL))
#define SOC_MediaCommon_MONITOR_WR_ST_2_ADDR(base) ((base) + (0x0884UL))
#define SOC_MediaCommon_MONITOR_WR_ST_3_ADDR(base) ((base) + (0x0888UL))
#define SOC_MediaCommon_MONITOR_WR_ST_4_ADDR(base) ((base) + (0x088CUL))
#define SOC_MediaCommon_MONITOR_WR_ST_5_ADDR(base) ((base) + (0x0890UL))
#define SOC_MediaCommon_MONITOR_WR_ST_6_ADDR(base) ((base) + (0x0894UL))
#define SOC_MediaCommon_MONITOR_WR_ST_7_ADDR(base) ((base) + (0x0898UL))
#define SOC_MediaCommon_MONITOR_WR_ST_8_ADDR(base) ((base) + (0x089CUL))
#define SOC_MediaCommon_MONITOR_RD_ST_0_ADDR(base) ((base) + (0x08A0UL))
#define SOC_MediaCommon_MONITOR_RD_ST_1_ADDR(base) ((base) + (0x08B0UL))
#define SOC_MediaCommon_MONITOR_RD_ST_2_ADDR(base) ((base) + (0x08B4UL))
#define SOC_MediaCommon_MONITOR_RD_ST_3_ADDR(base) ((base) + (0x08B8UL))
#define SOC_MediaCommon_MONITOR_RD_ST_4_ADDR(base) ((base) + (0x08BCUL))
#define SOC_MediaCommon_MONITOR_RD_ST_5_ADDR(base) ((base) + (0x08C0UL))
#define SOC_MediaCommon_MONITOR_RD_ST_6_ADDR(base) ((base) + (0x08C4UL))
#define SOC_MediaCommon_MONITOR_RD_ST_7_ADDR(base) ((base) + (0x08C8UL))
#define SOC_MediaCommon_MONITOR_RD_ST_8_ADDR(base) ((base) + (0x08CCUL))
#define SOC_MediaCommon_MONITOR_OS_R0_ADDR(base) ((base) + (0x08D0UL))
#define SOC_MediaCommon_MONITOR_OS_R1_ADDR(base) ((base) + (0x08E0UL))
#define SOC_MediaCommon_MONITOR_OS_R2_ADDR(base) ((base) + (0x08E4UL))
#define SOC_MediaCommon_MONITOR_OS_R3_ADDR(base) ((base) + (0x08E8UL))
#define SOC_MediaCommon_MONITOR_OS_R4_ADDR(base) ((base) + (0x08ECUL))
#define SOC_MediaCommon_MONITOR_OS_W0_ADDR(base) ((base) + (0x08F0UL))
#define SOC_MediaCommon_MONITOR_OS_W1_ADDR(base) ((base) + (0x0900UL))
#define SOC_MediaCommon_MONITOR_OS_W2_ADDR(base) ((base) + (0x0904UL))
#define SOC_MediaCommon_MONITOR_OS_W3_ADDR(base) ((base) + (0x090CUL))
#define SOC_MediaCommon_AIF_STAT_0_ADDR(base) ((base) + (0x0910UL))
#define SOC_MediaCommon_AIF_STAT_1_ADDR(base) ((base) + (0x0914UL))
#define SOC_MediaCommon_AIF_STAT_2_ADDR(base) ((base) + (0x0918UL))
#define SOC_MediaCommon_AIF_STAT_3_ADDR(base) ((base) + (0x091CUL))
#define SOC_MediaCommon_AIF_STAT_4_ADDR(base) ((base) + (0x0920UL))
#define SOC_MediaCommon_AIF_STAT_5_ADDR(base) ((base) + (0x0924UL))
#define SOC_MediaCommon_AIF_STAT_6_ADDR(base) ((base) + (0x0928UL))
#define SOC_MediaCommon_AIF_STAT_7_ADDR(base) ((base) + (0x092CUL))
#define SOC_MediaCommon_AIF_STAT_8_ADDR(base) ((base) + (0x0930UL))
#define SOC_MediaCommon_AIF_STAT_9_ADDR(base) ((base) + (0x0934UL))
#define SOC_MediaCommon_AIF_STAT_10_ADDR(base) ((base) + (0x0938UL))
#define SOC_MediaCommon_AIF_STAT_11_ADDR(base) ((base) + (0x093CUL))
#define SOC_MediaCommon_AIF_STAT_12_ADDR(base) ((base) + (0x0940UL))
#define SOC_MediaCommon_AIF_STAT_13_ADDR(base) ((base) + (0x0944UL))
#define SOC_MediaCommon_AIF_STAT_14_ADDR(base) ((base) + (0x0948UL))
#define SOC_MediaCommon_AIF_STAT_15_ADDR(base) ((base) + (0x094CUL))
#define SOC_MediaCommon_MODULE_CLK_SEL_ADDR(base) ((base) + (0xA04UL))
#define SOC_MediaCommon_MODULE_CLK_EN_ADDR(base) ((base) + (0xA08UL))
#else
#define SOC_MediaCommon_AIF_CH_CTL_0_ADDR(base) ((base) + (0x0000))
#define SOC_MediaCommon_AIF_CH_HS_0_ADDR(base) ((base) + (0x0004))
#define SOC_MediaCommon_AIF_CH_LS_0_ADDR(base) ((base) + (0x0008))
#define SOC_MediaCommon_AIF_CH_CTL_1_ADDR(base) ((base) + (0x0020))
#define SOC_MediaCommon_AIF_CH_HS_1_ADDR(base) ((base) + (0x0024))
#define SOC_MediaCommon_AIF_CH_LS_1_ADDR(base) ((base) + (0x0028))
#define SOC_MediaCommon_AIF_CH_CTL_2_ADDR(base) ((base) + (0x0040))
#define SOC_MediaCommon_AIF_CH_HS_2_ADDR(base) ((base) + (0x0044))
#define SOC_MediaCommon_AIF_CH_LS_2_ADDR(base) ((base) + (0x0048))
#define SOC_MediaCommon_AIF_CH_CTL_3_ADDR(base) ((base) + (0x0060))
#define SOC_MediaCommon_AIF_CH_HS_3_ADDR(base) ((base) + (0x0064))
#define SOC_MediaCommon_AIF_CH_LS_3_ADDR(base) ((base) + (0x0068))
#define SOC_MediaCommon_AIF_CH_CTL_4_ADDR(base) ((base) + (0x0080))
#define SOC_MediaCommon_AIF_CH_HS_4_ADDR(base) ((base) + (0x0084))
#define SOC_MediaCommon_AIF_CH_LS_4_ADDR(base) ((base) + (0x0088))
#define SOC_MediaCommon_AIF_CH_CTL_5_ADDR(base) ((base) + (0x00A0))
#define SOC_MediaCommon_AIF_CH_HS_5_ADDR(base) ((base) + (0x00A4))
#define SOC_MediaCommon_AIF_CH_LS_5_ADDR(base) ((base) + (0x00A8))
#define SOC_MediaCommon_AIF_CH_CTL_6_ADDR(base) ((base) + (0x00C0))
#define SOC_MediaCommon_AIF_CH_HS_6_ADDR(base) ((base) + (0x00C4))
#define SOC_MediaCommon_AIF_CH_LS_6_ADDR(base) ((base) + (0x00C8))
#define SOC_MediaCommon_AIF_CH_CTL_7_ADDR(base) ((base) + (0x00E0))
#define SOC_MediaCommon_AIF_CH_HS_7_ADDR(base) ((base) + (0x00E4))
#define SOC_MediaCommon_AIF_CH_LS_7_ADDR(base) ((base) + (0x00E8))
#define SOC_MediaCommon_AIF_CH_CTL_8_ADDR(base) ((base) + (0x0100))
#define SOC_MediaCommon_AIF_CH_HS_8_ADDR(base) ((base) + (0x0104))
#define SOC_MediaCommon_AIF_CH_LS_8_ADDR(base) ((base) + (0x0108))
#define SOC_MediaCommon_AIF_CH_CTL_9_ADDR(base) ((base) + (0x0120))
#define SOC_MediaCommon_AIF_CH_HS_9_ADDR(base) ((base) + (0x0124))
#define SOC_MediaCommon_AIF_CH_LS_9_ADDR(base) ((base) + (0x0128))
#define SOC_MediaCommon_AIF_CH_CTL_10_ADDR(base) ((base) + (0x0140))
#define SOC_MediaCommon_AIF_CH_HS_10_ADDR(base) ((base) + (0x0144))
#define SOC_MediaCommon_AIF_CH_LS_10_ADDR(base) ((base) + (0x0148))
#define SOC_MediaCommon_AIF_CH_CTL_11_ADDR(base) ((base) + (0x0160))
#define SOC_MediaCommon_AIF_CH_HS_11_ADDR(base) ((base) + (0x0164))
#define SOC_MediaCommon_AIF_CH_LS_11_ADDR(base) ((base) + (0x0168))
#define SOC_MediaCommon_AIF_CH_CTL_12_ADDR(base) ((base) + (0x0180))
#define SOC_MediaCommon_AIF_CH_HS_12_ADDR(base) ((base) + (0x0184))
#define SOC_MediaCommon_AIF_CH_LS_12_ADDR(base) ((base) + (0x0188))
#define SOC_MediaCommon_AIF_CH_MID_0_ADDR(base) ((base) + (0x0400))
#define SOC_MediaCommon_AIF_CH_MID_1_ADDR(base) ((base) + (0x0404))
#define SOC_MediaCommon_AIF_CH_MID_2_ADDR(base) ((base) + (0x0408))
#define SOC_MediaCommon_AIF_CH_MID_3_ADDR(base) ((base) + (0x040C))
#define SOC_MediaCommon_AIF_CH_MID_4_ADDR(base) ((base) + (0x0410))
#define SOC_MediaCommon_AIF_CH_MID_5_ADDR(base) ((base) + (0x0414))
#define SOC_MediaCommon_AIF_CH_MID_6_ADDR(base) ((base) + (0x0418))
#define SOC_MediaCommon_AIF_CH_MID_7_ADDR(base) ((base) + (0x041C))
#define SOC_MediaCommon_AIF_CH_MID_8_ADDR(base) ((base) + (0x0420))
#define SOC_MediaCommon_AIF_CH_MID_9_ADDR(base) ((base) + (0x0424))
#define SOC_MediaCommon_AIF_CH_MID_10_ADDR(base) ((base) + (0x0428))
#define SOC_MediaCommon_AIF_CH_MID_11_ADDR(base) ((base) + (0x042C))
#define SOC_MediaCommon_AIF_CH_MID_12_ADDR(base) ((base) + (0x0430))
#define SOC_MediaCommon_AIF_CH_MID_CMD_ADDR(base) ((base) + (0x0434))
#define SOC_MediaCommon_DSS0_MID_ADDR(base) ((base) + (0x0438))
#define SOC_MediaCommon_DSS1_MID_ADDR(base) ((base) + (0x043C))
#define SOC_MediaCommon_AXI0_RID_MSK0_ADDR(base) ((base) + (0x0800))
#define SOC_MediaCommon_AXI0_RID_MSK1_ADDR(base) ((base) + (0x0804))
#define SOC_MediaCommon_AXI0_WID_MSK_ADDR(base) ((base) + (0x0808))
#define SOC_MediaCommon_AXI0_R_QOS_MAP_ADDR(base) ((base) + (0x080C))
#define SOC_MediaCommon_AXI1_RID_MSK0_ADDR(base) ((base) + (0x0810))
#define SOC_MediaCommon_AXI1_RID_MSK1_ADDR(base) ((base) + (0x0814))
#define SOC_MediaCommon_AXI1_WID_MSK_ADDR(base) ((base) + (0x0818))
#define SOC_MediaCommon_AXI1_R_QOS_MAP_ADDR(base) ((base) + (0x081C))
#define SOC_MediaCommon_AIF_CLK_SEL0_ADDR(base) ((base) + (0x0820))
#define SOC_MediaCommon_AIF_CLK_SEL1_ADDR(base) ((base) + (0x0824))
#define SOC_MediaCommon_AIF_CLK_EN0_ADDR(base) ((base) + (0x0828))
#define SOC_MediaCommon_AIF_CLK_EN1_ADDR(base) ((base) + (0x082C))
#define SOC_MediaCommon_AIF_CH_CTL_CMD_ADDR(base) ((base) + (0x0830))
#define SOC_MediaCommon_MONITOR_TIMER_INI_ADDR(base) ((base) + (0x0834))
#define SOC_MediaCommon_DEBUG_BUF_BASE_ADDR(base) ((base) + (0x0838))
#define SOC_MediaCommon_DEBUG_CTRL_ADDR(base) ((base) + (0x083C))
#define SOC_MediaCommon_AIF_SHADOW_READ_ADDR(base) ((base) + (0x0840))
#define SOC_MediaCommon_AIF_MEM_CTRL_ADDR(base) ((base) + (0x0844))
#define SOC_MediaCommon_MONITOR_EN_ADDR(base) ((base) + (0x0848))
#define SOC_MediaCommon_MONITOR_CTRL_ADDR(base) ((base) + (0x084C))
#define SOC_MediaCommon_MONITOR_SAMPLE_MUN_ADDR(base) ((base) + (0x0850))
#define SOC_MediaCommon_MONITOR_SAMPLE_TIME_ADDR(base) ((base) + (0x0854))
#define SOC_MediaCommon_MONITOR_SAMPLE_FLOW_ADDR(base) ((base) + (0x0858))
#define SOC_MediaCommon_MONITOR_WR_ST_0_ADDR(base) ((base) + (0x0870))
#define SOC_MediaCommon_MONITOR_WR_ST_1_ADDR(base) ((base) + (0x0880))
#define SOC_MediaCommon_MONITOR_WR_ST_2_ADDR(base) ((base) + (0x0884))
#define SOC_MediaCommon_MONITOR_WR_ST_3_ADDR(base) ((base) + (0x0888))
#define SOC_MediaCommon_MONITOR_WR_ST_4_ADDR(base) ((base) + (0x088C))
#define SOC_MediaCommon_MONITOR_WR_ST_5_ADDR(base) ((base) + (0x0890))
#define SOC_MediaCommon_MONITOR_WR_ST_6_ADDR(base) ((base) + (0x0894))
#define SOC_MediaCommon_MONITOR_WR_ST_7_ADDR(base) ((base) + (0x0898))
#define SOC_MediaCommon_MONITOR_WR_ST_8_ADDR(base) ((base) + (0x089C))
#define SOC_MediaCommon_MONITOR_RD_ST_0_ADDR(base) ((base) + (0x08A0))
#define SOC_MediaCommon_MONITOR_RD_ST_1_ADDR(base) ((base) + (0x08B0))
#define SOC_MediaCommon_MONITOR_RD_ST_2_ADDR(base) ((base) + (0x08B4))
#define SOC_MediaCommon_MONITOR_RD_ST_3_ADDR(base) ((base) + (0x08B8))
#define SOC_MediaCommon_MONITOR_RD_ST_4_ADDR(base) ((base) + (0x08BC))
#define SOC_MediaCommon_MONITOR_RD_ST_5_ADDR(base) ((base) + (0x08C0))
#define SOC_MediaCommon_MONITOR_RD_ST_6_ADDR(base) ((base) + (0x08C4))
#define SOC_MediaCommon_MONITOR_RD_ST_7_ADDR(base) ((base) + (0x08C8))
#define SOC_MediaCommon_MONITOR_RD_ST_8_ADDR(base) ((base) + (0x08CC))
#define SOC_MediaCommon_MONITOR_OS_R0_ADDR(base) ((base) + (0x08D0))
#define SOC_MediaCommon_MONITOR_OS_R1_ADDR(base) ((base) + (0x08E0))
#define SOC_MediaCommon_MONITOR_OS_R2_ADDR(base) ((base) + (0x08E4))
#define SOC_MediaCommon_MONITOR_OS_R3_ADDR(base) ((base) + (0x08E8))
#define SOC_MediaCommon_MONITOR_OS_R4_ADDR(base) ((base) + (0x08EC))
#define SOC_MediaCommon_MONITOR_OS_W0_ADDR(base) ((base) + (0x08F0))
#define SOC_MediaCommon_MONITOR_OS_W1_ADDR(base) ((base) + (0x0900))
#define SOC_MediaCommon_MONITOR_OS_W2_ADDR(base) ((base) + (0x0904))
#define SOC_MediaCommon_MONITOR_OS_W3_ADDR(base) ((base) + (0x090C))
#define SOC_MediaCommon_AIF_STAT_0_ADDR(base) ((base) + (0x0910))
#define SOC_MediaCommon_AIF_STAT_1_ADDR(base) ((base) + (0x0914))
#define SOC_MediaCommon_AIF_STAT_2_ADDR(base) ((base) + (0x0918))
#define SOC_MediaCommon_AIF_STAT_3_ADDR(base) ((base) + (0x091C))
#define SOC_MediaCommon_AIF_STAT_4_ADDR(base) ((base) + (0x0920))
#define SOC_MediaCommon_AIF_STAT_5_ADDR(base) ((base) + (0x0924))
#define SOC_MediaCommon_AIF_STAT_6_ADDR(base) ((base) + (0x0928))
#define SOC_MediaCommon_AIF_STAT_7_ADDR(base) ((base) + (0x092C))
#define SOC_MediaCommon_AIF_STAT_8_ADDR(base) ((base) + (0x0930))
#define SOC_MediaCommon_AIF_STAT_9_ADDR(base) ((base) + (0x0934))
#define SOC_MediaCommon_AIF_STAT_10_ADDR(base) ((base) + (0x0938))
#define SOC_MediaCommon_AIF_STAT_11_ADDR(base) ((base) + (0x093C))
#define SOC_MediaCommon_AIF_STAT_12_ADDR(base) ((base) + (0x0940))
#define SOC_MediaCommon_AIF_STAT_13_ADDR(base) ((base) + (0x0944))
#define SOC_MediaCommon_AIF_STAT_14_ADDR(base) ((base) + (0x0948))
#define SOC_MediaCommon_AIF_STAT_15_ADDR(base) ((base) + (0x094C))
#define SOC_MediaCommon_MODULE_CLK_SEL_ADDR(base) ((base) + (0xA04))
#define SOC_MediaCommon_MODULE_CLK_EN_ADDR(base) ((base) + (0xA08))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_MIF_ENABLE_ADDR(base) ((base) + (0x0000UL))
#define SOC_MediaCommon_MIF_MEM_CTRL_ADDR(base) ((base) + (0x0004UL))
#define SOC_MediaCommon_MIF_CTRL0_ADDR(base,j) ((base) + (0x0000+32*(j)))
#define SOC_MediaCommon_MIF_CTRL1_ADDR(base,j) ((base) + (0x0004+32*(j)))
#define SOC_MediaCommon_MIF_CTRL2_ADDR(base,j) ((base) + (0x0008+32*(j)))
#define SOC_MediaCommon_MIF_CTRL3_ADDR(base,j) ((base) + (0x000C+32*(j)))
#define SOC_MediaCommon_MIF_CTRL4_ADDR(base,j) ((base) + (0x0010+32*(j)))
#define SOC_MediaCommon_MIF_CTRL5_ADDR(base,j) ((base) + (0x0014+32*(j)))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0500UL))
#define SOC_MediaCommon_MIF_SHADOW_READ_ADDR(base) ((base) + (0x0504UL))
#define SOC_MediaCommon_MIF_CLK_CTL_ADDR(base) ((base) + (0x0508UL))
#define SOC_MediaCommon_MIF_STAT0_ADDR(base,k) ((base) + (0x0600+16*(k)))
#define SOC_MediaCommon_MIF_STAT1_ADDR(base,k) ((base) + (0x0604+16*(k)))
#define SOC_MediaCommon_MIF_STAT2_ADDR(base,k) ((base) + (0x0608+16*(k)))
#define SOC_MediaCommon_AIF_CMD_RELOAD_ADDR(base) ((base) + (0x0a00UL))
#else
#define SOC_MediaCommon_MIF_ENABLE_ADDR(base) ((base) + (0x0000))
#define SOC_MediaCommon_MIF_MEM_CTRL_ADDR(base) ((base) + (0x0004))
#define SOC_MediaCommon_MIF_CTRL0_ADDR(base,j) ((base) + (0x0000+32*(j)))
#define SOC_MediaCommon_MIF_CTRL1_ADDR(base,j) ((base) + (0x0004+32*(j)))
#define SOC_MediaCommon_MIF_CTRL2_ADDR(base,j) ((base) + (0x0008+32*(j)))
#define SOC_MediaCommon_MIF_CTRL3_ADDR(base,j) ((base) + (0x000C+32*(j)))
#define SOC_MediaCommon_MIF_CTRL4_ADDR(base,j) ((base) + (0x0010+32*(j)))
#define SOC_MediaCommon_MIF_CTRL5_ADDR(base,j) ((base) + (0x0014+32*(j)))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0500))
#define SOC_MediaCommon_MIF_SHADOW_READ_ADDR(base) ((base) + (0x0504))
#define SOC_MediaCommon_MIF_CLK_CTL_ADDR(base) ((base) + (0x0508))
#define SOC_MediaCommon_MIF_STAT0_ADDR(base,k) ((base) + (0x0600+16*(k)))
#define SOC_MediaCommon_MIF_STAT1_ADDR(base,k) ((base) + (0x0604+16*(k)))
#define SOC_MediaCommon_MIF_STAT2_ADDR(base,k) ((base) + (0x0608+16*(k)))
#define SOC_MediaCommon_AIF_CMD_RELOAD_ADDR(base) ((base) + (0x0a00))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_RCH_FLUSH_EN_ADDR(base) ((base) + (0x0108UL))
#define SOC_MediaCommon_WCH_FLUSH_EN_ADDR(base) ((base) + (0x0124UL))
#define SOC_MediaCommon_ISPIF_FLUSH_EN_ADDR(base) ((base) + (0x0134UL))
#define SOC_MediaCommon_RCH_OEN_ADDR(base) ((base) + (0x0168UL))
#define SOC_MediaCommon_WCH_IEN_ADDR(base) ((base) + (0x01A4UL))
#define SOC_MediaCommon_ISP_WCH_SEL_ADDR(base) ((base) + (0x01ACUL))
#define SOC_MediaCommon_MCTL_CLK_SEL_ADDR(base) ((base) + (0x01F0UL))
#define SOC_MediaCommon_MCTL_CLK_EN_ADDR(base) ((base) + (0x01F4UL))
#define SOC_MediaCommon_MOD_CLK_SEL_ADDR(base) ((base) + (0x01F8UL))
#define SOC_MediaCommon_MOD_CLK_EN_ADDR(base) ((base) + (0x01FCUL))
#define SOC_MediaCommon_MOD2_DBG_ADDR(base) ((base) + (0x0208UL))
#define SOC_MediaCommon_MOD9_DBG_ADDR(base) ((base) + (0x0224UL))
#define SOC_MediaCommon_MOD13_DBG_ADDR(base) ((base) + (0x0234UL))
#define SOC_MediaCommon_MOD2_STATUS_ADDR(base) ((base) + (0x0288UL))
#define SOC_MediaCommon_MOD9_STATUS_ADDR(base) ((base) + (0x02A4UL))
#define SOC_MediaCommon_MOD13_STATUS_ADDR(base) ((base) + (0x02B4UL))
#define SOC_MediaCommon_SW_DBG_ADDR(base) ((base) + (0x0300UL))
#define SOC_MediaCommon_SW1_STATUS_ADDR(base) ((base) + (0x0324UL))
#else
#define SOC_MediaCommon_RCH_FLUSH_EN_ADDR(base) ((base) + (0x0108))
#define SOC_MediaCommon_WCH_FLUSH_EN_ADDR(base) ((base) + (0x0124))
#define SOC_MediaCommon_ISPIF_FLUSH_EN_ADDR(base) ((base) + (0x0134))
#define SOC_MediaCommon_RCH_OEN_ADDR(base) ((base) + (0x0168))
#define SOC_MediaCommon_WCH_IEN_ADDR(base) ((base) + (0x01A4))
#define SOC_MediaCommon_ISP_WCH_SEL_ADDR(base) ((base) + (0x01AC))
#define SOC_MediaCommon_MCTL_CLK_SEL_ADDR(base) ((base) + (0x01F0))
#define SOC_MediaCommon_MCTL_CLK_EN_ADDR(base) ((base) + (0x01F4))
#define SOC_MediaCommon_MOD_CLK_SEL_ADDR(base) ((base) + (0x01F8))
#define SOC_MediaCommon_MOD_CLK_EN_ADDR(base) ((base) + (0x01FC))
#define SOC_MediaCommon_MOD2_DBG_ADDR(base) ((base) + (0x0208))
#define SOC_MediaCommon_MOD9_DBG_ADDR(base) ((base) + (0x0224))
#define SOC_MediaCommon_MOD13_DBG_ADDR(base) ((base) + (0x0234))
#define SOC_MediaCommon_MOD2_STATUS_ADDR(base) ((base) + (0x0288))
#define SOC_MediaCommon_MOD9_STATUS_ADDR(base) ((base) + (0x02A4))
#define SOC_MediaCommon_MOD13_STATUS_ADDR(base) ((base) + (0x02B4))
#define SOC_MediaCommon_SW_DBG_ADDR(base) ((base) + (0x0300))
#define SOC_MediaCommon_SW1_STATUS_ADDR(base) ((base) + (0x0324))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_CTL_EN_ADDR(base) ((base) + (0x0000UL))
#define SOC_MediaCommon_CTL_MUTEX_ADDR(base) ((base) + (0x0004UL))
#define SOC_MediaCommon_CTL_MUTEX_STATUS_ADDR(base) ((base) + (0x0008UL))
#define SOC_MediaCommon_CTL_MUTEXT_ISPIF_ADDR(base) ((base) + (0x0018UL))
#define SOC_MediaCommon_CTL_MUTEX_WCH_ADDR(base) ((base) + (0x0024UL))
#define SOC_MediaCommon_CTL_MUTEX_RCH_ADDR(base) ((base) + (0x0038UL))
#define SOC_MediaCommon_CTL_TOP_ADDR(base) ((base) + (0x0050UL))
#define SOC_MediaCommon_CTL_FLUSH_STATUS_ADDR(base) ((base) + (0x0054UL))
#define SOC_MediaCommon_CTL_CLEAR_ADDR(base) ((base) + (0x0058UL))
#define SOC_MediaCommon_CTL_CACK_TOUT_ADDR(base) ((base) + (0x0060UL))
#define SOC_MediaCommon_CTL_MUTEX_TOUT_ADDR(base) ((base) + (0x0064UL))
#define SOC_MediaCommon_CTL_STATUS_ADDR(base) ((base) + (0x0068UL))
#define SOC_MediaCommon_CTL_INTEN_ADDR(base) ((base) + (0x006CUL))
#define SOC_MediaCommon_CTL_SW_ST_ADDR(base) ((base) + (0x0070UL))
#define SOC_MediaCommon_CTL_ST_SEL_ADDR(base) ((base) + (0x0074UL))
#define SOC_MediaCommon_CTL_END_SEL_ADDR(base) ((base) + (0x0078UL))
#define SOC_MediaCommon_CTL_CLK_SEL_ADDR(base) ((base) + (0x0080UL))
#define SOC_MediaCommon_CTL_CLK_EN_ADDR(base) ((base) + (0x0084UL))
#define SOC_MediaCommon_CTL_DBG_ADDR(base) ((base) + (0x00E0UL))
#else
#define SOC_MediaCommon_CTL_EN_ADDR(base) ((base) + (0x0000))
#define SOC_MediaCommon_CTL_MUTEX_ADDR(base) ((base) + (0x0004))
#define SOC_MediaCommon_CTL_MUTEX_STATUS_ADDR(base) ((base) + (0x0008))
#define SOC_MediaCommon_CTL_MUTEXT_ISPIF_ADDR(base) ((base) + (0x0018))
#define SOC_MediaCommon_CTL_MUTEX_WCH_ADDR(base) ((base) + (0x0024))
#define SOC_MediaCommon_CTL_MUTEX_RCH_ADDR(base) ((base) + (0x0038))
#define SOC_MediaCommon_CTL_TOP_ADDR(base) ((base) + (0x0050))
#define SOC_MediaCommon_CTL_FLUSH_STATUS_ADDR(base) ((base) + (0x0054))
#define SOC_MediaCommon_CTL_CLEAR_ADDR(base) ((base) + (0x0058))
#define SOC_MediaCommon_CTL_CACK_TOUT_ADDR(base) ((base) + (0x0060))
#define SOC_MediaCommon_CTL_MUTEX_TOUT_ADDR(base) ((base) + (0x0064))
#define SOC_MediaCommon_CTL_STATUS_ADDR(base) ((base) + (0x0068))
#define SOC_MediaCommon_CTL_INTEN_ADDR(base) ((base) + (0x006C))
#define SOC_MediaCommon_CTL_SW_ST_ADDR(base) ((base) + (0x0070))
#define SOC_MediaCommon_CTL_ST_SEL_ADDR(base) ((base) + (0x0074))
#define SOC_MediaCommon_CTL_END_SEL_ADDR(base) ((base) + (0x0078))
#define SOC_MediaCommon_CTL_CLK_SEL_ADDR(base) ((base) + (0x0080))
#define SOC_MediaCommon_CTL_CLK_EN_ADDR(base) ((base) + (0x0084))
#define SOC_MediaCommon_CTL_DBG_ADDR(base) ((base) + (0x00E0))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_DMA_OFT_X0_ADDR(base) ((base) + (0x0000UL))
#define SOC_MediaCommon_DMA_OFT_Y0_ADDR(base) ((base) + (0x0004UL))
#define SOC_MediaCommon_DMA_OFT_X1_ADDR(base) ((base) + (0x0008UL))
#define SOC_MediaCommon_DMA_OFT_Y1_ADDR(base) ((base) + (0x000CUL))
#define SOC_MediaCommon_DMA_MASK0_ADDR(base) ((base) + (0x0010UL))
#define SOC_MediaCommon_DMA_MASK1_ADDR(base) ((base) + (0x0014UL))
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_ADDR(base) ((base) + (0x0018UL))
#define SOC_MediaCommon_DMA_CTRL_ADDR(base) ((base) + (0x001CUL))
#define SOC_MediaCommon_DMA_TILE_SCRAM_ADDR(base) ((base) + (0x0020UL))
#define SOC_MediaCommon_DMA_PULSE_ADDR(base) ((base) + (0x0028UL))
#define SOC_MediaCommon_RWCH_CFG0_ADDR(base) ((base) + (0x0030UL))
#define SOC_MediaCommon_DMA_DATA_ADDR0_ADDR(base) ((base) + (0x0060UL))
#define SOC_MediaCommon_DMA_STRIDE0_ADDR(base) ((base) + (0x0064UL))
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_ADDR(base) ((base) + (0x0068UL))
#define SOC_MediaCommon_DMA_DATA_NUM0_ADDR(base) ((base) + (0x006CUL))
#define SOC_MediaCommon_DMA_TEST0_ADDR(base) ((base) + (0x0070UL))
#define SOC_MediaCommon_DMA_TEST1_ADDR(base) ((base) + (0x0074UL))
#define SOC_MediaCommon_DMA_TEST3_ADDR(base) ((base) + (0x0078UL))
#define SOC_MediaCommon_DMA_TEST4_ADDR(base) ((base) + (0x007CUL))
#define SOC_MediaCommon_DMA_STATUS_Y_ADDR(base) ((base) + (0x0080UL))
#define SOC_MediaCommon_CH_RD_SHADOW_ADDR(base) ((base) + (0x00D0UL))
#define SOC_MediaCommon_CH_CTL_ADDR(base) ((base) + (0x00D4UL))
#define SOC_MediaCommon_CH_SECU_EN_ADDR(base) ((base) + (0x00D8UL))
#define SOC_MediaCommon_CH_SW_END_REQ_ADDR(base) ((base) + (0x00DCUL))
#define SOC_MediaCommon_CH_CLK_SEL_ADDR(base) ((base) + (0x00E0UL))
#define SOC_MediaCommon_CH_CLK_EN_ADDR(base) ((base) + (0x00E4UL))
#define SOC_MediaCommon_CH_DBG0_ADDR(base) ((base) + (0x00E8UL))
#define SOC_MediaCommon_CH_DBG1_ADDR(base) ((base) + (0x00ECUL))
#define SOC_MediaCommon_CH_DBG2_ADDR(base) ((base) + (0x00F0UL))
#define SOC_MediaCommon_CH_DBG3_ADDR(base) ((base) + (0x00F4UL))
#define SOC_MediaCommon_CH_DBG4_ADDR(base) ((base) + (0x00F8UL))
#define SOC_MediaCommon_CH_DBG5_ADDR(base) ((base) + (0x00FCUL))
#define SOC_MediaCommon_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100UL))
#define SOC_MediaCommon_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104UL))
#define SOC_MediaCommon_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108UL))
#define SOC_MediaCommon_DFC_DISP_FMT_ADDR(base) ((base) + (0x010CUL))
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110UL))
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114UL))
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118UL))
#define SOC_MediaCommon_DFC_ICG_MODULE_ADDR(base) ((base) + (0x011CUL))
#define SOC_MediaCommon_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120UL))
#define SOC_MediaCommon_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124UL))
#define SOC_MediaCommon_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128UL))
#define SOC_MediaCommon_BITEXT_CTL_ADDR(base) ((base) + (0x0140UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014CUL))
#define SOC_MediaCommon_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015CUL))
#define SOC_MediaCommon_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016CUL))
#define SOC_MediaCommon_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170UL))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174UL))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178UL))
#define SOC_MediaCommon_BITEXT_FILT_00_ADDR(base) ((base) + (0x017CUL))
#define SOC_MediaCommon_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180UL))
#define SOC_MediaCommon_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184UL))
#define SOC_MediaCommon_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188UL))
#define SOC_MediaCommon_BITEXT_FILT_11_ADDR(base) ((base) + (0x018CUL))
#define SOC_MediaCommon_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190UL))
#define SOC_MediaCommon_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194UL))
#define SOC_MediaCommon_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0UL))
#define SOC_MediaCommon_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4UL))
#define SOC_MediaCommon_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8UL))
#define SOC_MediaCommon_BITEXT_THD_R1_ADDR(base) ((base) + (0x01ACUL))
#define SOC_MediaCommon_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0UL))
#define SOC_MediaCommon_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4UL))
#define SOC_MediaCommon_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8UL))
#define SOC_MediaCommon_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BCUL))
#define SOC_MediaCommon_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0UL))
#define SOC_MediaCommon_CSC_IDC0_ADDR(base) ((base) + (0x0500UL))
#define SOC_MediaCommon_CSC_IDC2_ADDR(base) ((base) + (0x0504UL))
#define SOC_MediaCommon_CSC_ODC0_ADDR(base) ((base) + (0x0508UL))
#define SOC_MediaCommon_CSC_ODC2_ADDR(base) ((base) + (0x050CUL))
#define SOC_MediaCommon_CSC_P00_ADDR(base) ((base) + (0x0510UL))
#define SOC_MediaCommon_CSC_P01_ADDR(base) ((base) + (0x0514UL))
#define SOC_MediaCommon_CSC_P02_ADDR(base) ((base) + (0x0518UL))
#define SOC_MediaCommon_CSC_P10_ADDR(base) ((base) + (0x051CUL))
#define SOC_MediaCommon_CSC_P11_ADDR(base) ((base) + (0x0520UL))
#define SOC_MediaCommon_CSC_P12_ADDR(base) ((base) + (0x0524UL))
#define SOC_MediaCommon_CSC_P20_ADDR(base) ((base) + (0x0528UL))
#define SOC_MediaCommon_CSC_P21_ADDR(base) ((base) + (0x052CUL))
#define SOC_MediaCommon_CSC_P22_ADDR(base) ((base) + (0x0530UL))
#define SOC_MediaCommon_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0534UL))
#define SOC_MediaCommon_CSC_MPREC_ADDR(base) ((base) + (0x0538UL))
#define SOC_MediaCommon_CH_DEBUG_SEL_ADDR(base) ((base) + (0x600UL))
#define SOC_MediaCommon_DMA_BUF_CTRL_ADDR(base) ((base) + (0x0800UL))
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_ADDR(base) ((base) + (0x0804UL))
#define SOC_MediaCommon_DMA_BUF_CPU_START_ADDR(base) ((base) + (0x0808UL))
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_ADDR(base) ((base) + (0x080CUL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_ADDR(base) ((base) + (0x0810UL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_ADDR(base) ((base) + (0x814UL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_ADDR(base) ((base) + (0x818UL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_ADDR(base) ((base) + (0x81CUL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_ADDR(base) ((base) + (0x820UL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_ADDR(base) ((base) + (0x824UL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_ADDR(base) ((base) + (0x828UL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_ADDR(base) ((base) + (0x82CUL))
#define SOC_MediaCommon_DMA_REQ_END_ADDR(base) ((base) + (0x830UL))
#define SOC_MediaCommon_DMA_BUF_DBGCFG_ADDR(base) ((base) + (0x834UL))
#define SOC_MediaCommon_DMA_BUF_DBG0_ADDR(base) ((base) + (0x838UL))
#define SOC_MediaCommon_DMA_BUF_DBG1_ADDR(base) ((base) + (0x83CUL))
#define SOC_MediaCommon_DMA_BUF_DBG2_ADDR(base) ((base) + (0x840UL))
#define SOC_MediaCommon_DMA_BUF_DBG3_ADDR(base) ((base) + (0x844UL))
#define SOC_MediaCommon_DMA_BUF_DBG4_ADDR(base) ((base) + (0x848UL))
#define SOC_MediaCommon_DMA_BUF_DBG5_ADDR(base) ((base) + (0x84CUL))
#define SOC_MediaCommon_DMA_BUF_SIZE_ADDR(base) ((base) + (0x850UL))
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_ADDR(base) ((base) + (0x0854UL))
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_ADDR(base) ((base) + (0x0900UL))
#define SOC_MediaCommon_AFBCD_HREG_PIC_WIDTH_ADDR(base) ((base) + (0x0904UL))
#define SOC_MediaCommon_AFBCD_HREG_PIC_HEIGHT_ADDR(base) ((base) + (0x090CUL))
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_ADDR(base) ((base) + (0x0910UL))
#define SOC_MediaCommon_AFBCD_CTL_ADDR(base) ((base) + (0x0914UL))
#define SOC_MediaCommon_AFBCD_STR_ADDR(base) ((base) + (0x0918UL))
#define SOC_MediaCommon_LINE_CROP_ADDR(base) ((base) + (0x091CUL))
#define SOC_MediaCommon_INPUT_HEADER_STRIDE_ADDR(base) ((base) + (0x0920UL))
#define SOC_MediaCommon_AFBCD_PAYLOAD_STRIDE_ADDR(base) ((base) + (0x0924UL))
#define SOC_MediaCommon_MM_BASE_ADDR(base) ((base) + (0x0928UL))
#define SOC_MediaCommon_AFBCD_PAYLOAD_POINTER_ADDR(base) ((base) + (0x0930UL))
#define SOC_MediaCommon_HEIGHT_BF_STR_ADDR(base) ((base) + (0x0934UL))
#define SOC_MediaCommon_OS_CFG_ADDR(base) ((base) + (0x0938UL))
#define SOC_MediaCommon_AFBCD_MEM_CTRL_ADDR(base) ((base) + (0x093CUL))
#define SOC_MediaCommon_AFBCD_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0940UL))
#define SOC_MediaCommon_AFBCD_HEADER_POINTER_OFFSET_ADDR(base) ((base) + (0x0944UL))
#define SOC_MediaCommon_AFBCD_MONITOR_REG1_ADDR(base) ((base) + (0x0948UL))
#define SOC_MediaCommon_AFBCD_MONITOR_REG2_ADDR(base) ((base) + (0x094CUL))
#define SOC_MediaCommon_AFBCD_MONITOR_REG3_ADDR(base) ((base) + (0x0950UL))
#define SOC_MediaCommon_AFBCD_DEBUG_REG0_ADDR(base) ((base) + (0x0954UL))
#define SOC_MediaCommon_FBCD_CREG_FBCD_CTRL_MODE_ADDR(base) ((base) + (0x0960UL))
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_1_ADDR(base) ((base) + (0x0964UL))
#define SOC_MediaCommon_AFBCD_HREG_PLD_PTR_LO_1_ADDR(base) ((base) + (0x0968UL))
#define SOC_MediaCommon_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x096CUL))
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0970UL))
#define SOC_MediaCommon_FBCD_BLOCK_TYPE_ADDR(base) ((base) + (0x0974UL))
#define SOC_MediaCommon_MM_BASE_1_ADDR(base) ((base) + (0x0978UL))
#define SOC_MediaCommon_MM_BASE_2_ADDR(base) ((base) + (0x097CUL))
#define SOC_MediaCommon_MM_BASE_3_ADDR(base) ((base) + (0x0980UL))
#define SOC_MediaCommon_HFBCD_MEM_CTRL_ADDR(base) ((base) + (0x0984UL))
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_ADDR(base) ((base) + (0x0988UL))
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_ADDR(base) ((base) + (0x098CUL))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG1_ADDR(base) ((base) + (0x0990UL))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG2_ADDR(base) ((base) + (0x0994UL))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG3_ADDR(base) ((base) + (0x0998UL))
#define SOC_MediaCommon_HFBCD_DEBUG_REG0_ADDR(base) ((base) + (0x099CUL))
#define SOC_MediaCommon_AFBCD_MONTIOR_REG4_ADDR(base) ((base) + (0x09A0UL))
#define SOC_MediaCommon_AFBCD_MONTIOR_REG5_ADDR(base) ((base) + (0x09A4UL))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG4_ADDR(base) ((base) + (0x09A8UL))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG5_ADDR(base) ((base) + (0x09ACUL))
#define SOC_MediaCommon_DMA_ADDR_EXT_ADDR(base) ((base) + (0x0A40UL))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_ADDR(base) ((base) + (0x0A80UL))
#define SOC_MediaCommon_HEBC_HREG_PIC_WIDTH_ADDR(base) ((base) + (0x01B0UL))
#define SOC_MediaCommon_HEBC_HREG_PIC_HEIGHT_ADDR(base) ((base) + (0x01B8UL))
#define SOC_MediaCommon_HEBC_LINE_CROP_ADDR(base) ((base) + (0x0A84UL))
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_ADDR(base) ((base) + (0x0A88UL))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_ADDR(base) ((base) + (0x0A8CUL))
#define SOC_MediaCommon_HEBC_MM_BASE_ADDR(base) ((base) + (0x0A90UL))
#define SOC_MediaCommon_HEBC_PAYLOAD_POINTER_ADDR(base) ((base) + (0x0A94UL))
#define SOC_MediaCommon_HEBC_OS_CFG_ADDR(base) ((base) + (0x0A98UL))
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0A9CUL))
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_ADDR(base) ((base) + (0x0AA0UL))
#define SOC_MediaCommon_HEBC_TAG_VALUE0_ADDR(base) ((base) + (0x0AA4UL))
#define SOC_MediaCommon_HEBC_TAG_VALUE1_ADDR(base) ((base) + (0x0AA8UL))
#define SOC_MediaCommon_HEBC_TAG_VALUE2_ADDR(base) ((base) + (0x0AACUL))
#define SOC_MediaCommon_HEBC_TAG_VALUE3_ADDR(base) ((base) + (0x0AB0UL))
#define SOC_MediaCommon_HEBC_RESERVED0_ADDR(base) ((base) + (0x0AB4UL))
#define SOC_MediaCommon_HEBC_RESERVED1_ADDR(base) ((base) + (0x0AB8UL))
#define SOC_MediaCommon_HEBC_RESERVED2_ADDR(base) ((base) + (0x0ABCUL))
#define SOC_MediaCommon_HEBC_RESERVED3_ADDR(base) ((base) + (0x0AC0UL))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_ADDR(base) ((base) + (0x0AC4UL))
#define SOC_MediaCommon_HEBC_HREG_PLD_PTR_LO_1_ADDR(base) ((base) + (0x0258UL))
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x0AC8UL))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0268UL))
#define SOC_MediaCommon_HEBC_HREG_FORMAT_ADDR(base) ((base) + (0x0ACCUL))
#define SOC_MediaCommon_HEBC_MM_BASE_1_ADDR(base) ((base) + (0x0AD0UL))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0A00UL))
#else
#define SOC_MediaCommon_DMA_OFT_X0_ADDR(base) ((base) + (0x0000))
#define SOC_MediaCommon_DMA_OFT_Y0_ADDR(base) ((base) + (0x0004))
#define SOC_MediaCommon_DMA_OFT_X1_ADDR(base) ((base) + (0x0008))
#define SOC_MediaCommon_DMA_OFT_Y1_ADDR(base) ((base) + (0x000C))
#define SOC_MediaCommon_DMA_MASK0_ADDR(base) ((base) + (0x0010))
#define SOC_MediaCommon_DMA_MASK1_ADDR(base) ((base) + (0x0014))
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_ADDR(base) ((base) + (0x0018))
#define SOC_MediaCommon_DMA_CTRL_ADDR(base) ((base) + (0x001C))
#define SOC_MediaCommon_DMA_TILE_SCRAM_ADDR(base) ((base) + (0x0020))
#define SOC_MediaCommon_DMA_PULSE_ADDR(base) ((base) + (0x0028))
#define SOC_MediaCommon_RWCH_CFG0_ADDR(base) ((base) + (0x0030))
#define SOC_MediaCommon_DMA_DATA_ADDR0_ADDR(base) ((base) + (0x0060))
#define SOC_MediaCommon_DMA_STRIDE0_ADDR(base) ((base) + (0x0064))
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_ADDR(base) ((base) + (0x0068))
#define SOC_MediaCommon_DMA_DATA_NUM0_ADDR(base) ((base) + (0x006C))
#define SOC_MediaCommon_DMA_TEST0_ADDR(base) ((base) + (0x0070))
#define SOC_MediaCommon_DMA_TEST1_ADDR(base) ((base) + (0x0074))
#define SOC_MediaCommon_DMA_TEST3_ADDR(base) ((base) + (0x0078))
#define SOC_MediaCommon_DMA_TEST4_ADDR(base) ((base) + (0x007C))
#define SOC_MediaCommon_DMA_STATUS_Y_ADDR(base) ((base) + (0x0080))
#define SOC_MediaCommon_CH_RD_SHADOW_ADDR(base) ((base) + (0x00D0))
#define SOC_MediaCommon_CH_CTL_ADDR(base) ((base) + (0x00D4))
#define SOC_MediaCommon_CH_SECU_EN_ADDR(base) ((base) + (0x00D8))
#define SOC_MediaCommon_CH_SW_END_REQ_ADDR(base) ((base) + (0x00DC))
#define SOC_MediaCommon_CH_CLK_SEL_ADDR(base) ((base) + (0x00E0))
#define SOC_MediaCommon_CH_CLK_EN_ADDR(base) ((base) + (0x00E4))
#define SOC_MediaCommon_CH_DBG0_ADDR(base) ((base) + (0x00E8))
#define SOC_MediaCommon_CH_DBG1_ADDR(base) ((base) + (0x00EC))
#define SOC_MediaCommon_CH_DBG2_ADDR(base) ((base) + (0x00F0))
#define SOC_MediaCommon_CH_DBG3_ADDR(base) ((base) + (0x00F4))
#define SOC_MediaCommon_CH_DBG4_ADDR(base) ((base) + (0x00F8))
#define SOC_MediaCommon_CH_DBG5_ADDR(base) ((base) + (0x00FC))
#define SOC_MediaCommon_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100))
#define SOC_MediaCommon_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104))
#define SOC_MediaCommon_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108))
#define SOC_MediaCommon_DFC_DISP_FMT_ADDR(base) ((base) + (0x010C))
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110))
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114))
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118))
#define SOC_MediaCommon_DFC_ICG_MODULE_ADDR(base) ((base) + (0x011C))
#define SOC_MediaCommon_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120))
#define SOC_MediaCommon_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124))
#define SOC_MediaCommon_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128))
#define SOC_MediaCommon_BITEXT_CTL_ADDR(base) ((base) + (0x0140))
#define SOC_MediaCommon_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144))
#define SOC_MediaCommon_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148))
#define SOC_MediaCommon_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014C))
#define SOC_MediaCommon_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150))
#define SOC_MediaCommon_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154))
#define SOC_MediaCommon_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158))
#define SOC_MediaCommon_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015C))
#define SOC_MediaCommon_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160))
#define SOC_MediaCommon_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164))
#define SOC_MediaCommon_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168))
#define SOC_MediaCommon_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016C))
#define SOC_MediaCommon_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178))
#define SOC_MediaCommon_BITEXT_FILT_00_ADDR(base) ((base) + (0x017C))
#define SOC_MediaCommon_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180))
#define SOC_MediaCommon_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184))
#define SOC_MediaCommon_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188))
#define SOC_MediaCommon_BITEXT_FILT_11_ADDR(base) ((base) + (0x018C))
#define SOC_MediaCommon_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190))
#define SOC_MediaCommon_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194))
#define SOC_MediaCommon_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0))
#define SOC_MediaCommon_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4))
#define SOC_MediaCommon_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8))
#define SOC_MediaCommon_BITEXT_THD_R1_ADDR(base) ((base) + (0x01AC))
#define SOC_MediaCommon_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0))
#define SOC_MediaCommon_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4))
#define SOC_MediaCommon_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8))
#define SOC_MediaCommon_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BC))
#define SOC_MediaCommon_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0))
#define SOC_MediaCommon_CSC_IDC0_ADDR(base) ((base) + (0x0500))
#define SOC_MediaCommon_CSC_IDC2_ADDR(base) ((base) + (0x0504))
#define SOC_MediaCommon_CSC_ODC0_ADDR(base) ((base) + (0x0508))
#define SOC_MediaCommon_CSC_ODC2_ADDR(base) ((base) + (0x050C))
#define SOC_MediaCommon_CSC_P00_ADDR(base) ((base) + (0x0510))
#define SOC_MediaCommon_CSC_P01_ADDR(base) ((base) + (0x0514))
#define SOC_MediaCommon_CSC_P02_ADDR(base) ((base) + (0x0518))
#define SOC_MediaCommon_CSC_P10_ADDR(base) ((base) + (0x051C))
#define SOC_MediaCommon_CSC_P11_ADDR(base) ((base) + (0x0520))
#define SOC_MediaCommon_CSC_P12_ADDR(base) ((base) + (0x0524))
#define SOC_MediaCommon_CSC_P20_ADDR(base) ((base) + (0x0528))
#define SOC_MediaCommon_CSC_P21_ADDR(base) ((base) + (0x052C))
#define SOC_MediaCommon_CSC_P22_ADDR(base) ((base) + (0x0530))
#define SOC_MediaCommon_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0534))
#define SOC_MediaCommon_CSC_MPREC_ADDR(base) ((base) + (0x0538))
#define SOC_MediaCommon_CH_DEBUG_SEL_ADDR(base) ((base) + (0x600))
#define SOC_MediaCommon_DMA_BUF_CTRL_ADDR(base) ((base) + (0x0800))
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_ADDR(base) ((base) + (0x0804))
#define SOC_MediaCommon_DMA_BUF_CPU_START_ADDR(base) ((base) + (0x0808))
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_ADDR(base) ((base) + (0x080C))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_ADDR(base) ((base) + (0x0810))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_ADDR(base) ((base) + (0x814))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_ADDR(base) ((base) + (0x818))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_ADDR(base) ((base) + (0x81C))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_ADDR(base) ((base) + (0x820))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_ADDR(base) ((base) + (0x824))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_ADDR(base) ((base) + (0x828))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_ADDR(base) ((base) + (0x82C))
#define SOC_MediaCommon_DMA_REQ_END_ADDR(base) ((base) + (0x830))
#define SOC_MediaCommon_DMA_BUF_DBGCFG_ADDR(base) ((base) + (0x834))
#define SOC_MediaCommon_DMA_BUF_DBG0_ADDR(base) ((base) + (0x838))
#define SOC_MediaCommon_DMA_BUF_DBG1_ADDR(base) ((base) + (0x83C))
#define SOC_MediaCommon_DMA_BUF_DBG2_ADDR(base) ((base) + (0x840))
#define SOC_MediaCommon_DMA_BUF_DBG3_ADDR(base) ((base) + (0x844))
#define SOC_MediaCommon_DMA_BUF_DBG4_ADDR(base) ((base) + (0x848))
#define SOC_MediaCommon_DMA_BUF_DBG5_ADDR(base) ((base) + (0x84C))
#define SOC_MediaCommon_DMA_BUF_SIZE_ADDR(base) ((base) + (0x850))
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_ADDR(base) ((base) + (0x0854))
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_ADDR(base) ((base) + (0x0900))
#define SOC_MediaCommon_AFBCD_HREG_PIC_WIDTH_ADDR(base) ((base) + (0x0904))
#define SOC_MediaCommon_AFBCD_HREG_PIC_HEIGHT_ADDR(base) ((base) + (0x090C))
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_ADDR(base) ((base) + (0x0910))
#define SOC_MediaCommon_AFBCD_CTL_ADDR(base) ((base) + (0x0914))
#define SOC_MediaCommon_AFBCD_STR_ADDR(base) ((base) + (0x0918))
#define SOC_MediaCommon_LINE_CROP_ADDR(base) ((base) + (0x091C))
#define SOC_MediaCommon_INPUT_HEADER_STRIDE_ADDR(base) ((base) + (0x0920))
#define SOC_MediaCommon_AFBCD_PAYLOAD_STRIDE_ADDR(base) ((base) + (0x0924))
#define SOC_MediaCommon_MM_BASE_ADDR(base) ((base) + (0x0928))
#define SOC_MediaCommon_AFBCD_PAYLOAD_POINTER_ADDR(base) ((base) + (0x0930))
#define SOC_MediaCommon_HEIGHT_BF_STR_ADDR(base) ((base) + (0x0934))
#define SOC_MediaCommon_OS_CFG_ADDR(base) ((base) + (0x0938))
#define SOC_MediaCommon_AFBCD_MEM_CTRL_ADDR(base) ((base) + (0x093C))
#define SOC_MediaCommon_AFBCD_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0940))
#define SOC_MediaCommon_AFBCD_HEADER_POINTER_OFFSET_ADDR(base) ((base) + (0x0944))
#define SOC_MediaCommon_AFBCD_MONITOR_REG1_ADDR(base) ((base) + (0x0948))
#define SOC_MediaCommon_AFBCD_MONITOR_REG2_ADDR(base) ((base) + (0x094C))
#define SOC_MediaCommon_AFBCD_MONITOR_REG3_ADDR(base) ((base) + (0x0950))
#define SOC_MediaCommon_AFBCD_DEBUG_REG0_ADDR(base) ((base) + (0x0954))
#define SOC_MediaCommon_FBCD_CREG_FBCD_CTRL_MODE_ADDR(base) ((base) + (0x0960))
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_1_ADDR(base) ((base) + (0x0964))
#define SOC_MediaCommon_AFBCD_HREG_PLD_PTR_LO_1_ADDR(base) ((base) + (0x0968))
#define SOC_MediaCommon_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x096C))
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0970))
#define SOC_MediaCommon_FBCD_BLOCK_TYPE_ADDR(base) ((base) + (0x0974))
#define SOC_MediaCommon_MM_BASE_1_ADDR(base) ((base) + (0x0978))
#define SOC_MediaCommon_MM_BASE_2_ADDR(base) ((base) + (0x097C))
#define SOC_MediaCommon_MM_BASE_3_ADDR(base) ((base) + (0x0980))
#define SOC_MediaCommon_HFBCD_MEM_CTRL_ADDR(base) ((base) + (0x0984))
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_ADDR(base) ((base) + (0x0988))
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_ADDR(base) ((base) + (0x098C))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG1_ADDR(base) ((base) + (0x0990))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG2_ADDR(base) ((base) + (0x0994))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG3_ADDR(base) ((base) + (0x0998))
#define SOC_MediaCommon_HFBCD_DEBUG_REG0_ADDR(base) ((base) + (0x099C))
#define SOC_MediaCommon_AFBCD_MONTIOR_REG4_ADDR(base) ((base) + (0x09A0))
#define SOC_MediaCommon_AFBCD_MONTIOR_REG5_ADDR(base) ((base) + (0x09A4))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG4_ADDR(base) ((base) + (0x09A8))
#define SOC_MediaCommon_HFBCD_MONTIOR_REG5_ADDR(base) ((base) + (0x09AC))
#define SOC_MediaCommon_DMA_ADDR_EXT_ADDR(base) ((base) + (0x0A40))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_ADDR(base) ((base) + (0x0A80))
#define SOC_MediaCommon_HEBC_HREG_PIC_WIDTH_ADDR(base) ((base) + (0x01B0))
#define SOC_MediaCommon_HEBC_HREG_PIC_HEIGHT_ADDR(base) ((base) + (0x01B8))
#define SOC_MediaCommon_HEBC_LINE_CROP_ADDR(base) ((base) + (0x0A84))
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_ADDR(base) ((base) + (0x0A88))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_ADDR(base) ((base) + (0x0A8C))
#define SOC_MediaCommon_HEBC_MM_BASE_ADDR(base) ((base) + (0x0A90))
#define SOC_MediaCommon_HEBC_PAYLOAD_POINTER_ADDR(base) ((base) + (0x0A94))
#define SOC_MediaCommon_HEBC_OS_CFG_ADDR(base) ((base) + (0x0A98))
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0A9C))
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_ADDR(base) ((base) + (0x0AA0))
#define SOC_MediaCommon_HEBC_TAG_VALUE0_ADDR(base) ((base) + (0x0AA4))
#define SOC_MediaCommon_HEBC_TAG_VALUE1_ADDR(base) ((base) + (0x0AA8))
#define SOC_MediaCommon_HEBC_TAG_VALUE2_ADDR(base) ((base) + (0x0AAC))
#define SOC_MediaCommon_HEBC_TAG_VALUE3_ADDR(base) ((base) + (0x0AB0))
#define SOC_MediaCommon_HEBC_RESERVED0_ADDR(base) ((base) + (0x0AB4))
#define SOC_MediaCommon_HEBC_RESERVED1_ADDR(base) ((base) + (0x0AB8))
#define SOC_MediaCommon_HEBC_RESERVED2_ADDR(base) ((base) + (0x0ABC))
#define SOC_MediaCommon_HEBC_RESERVED3_ADDR(base) ((base) + (0x0AC0))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_ADDR(base) ((base) + (0x0AC4))
#define SOC_MediaCommon_HEBC_HREG_PLD_PTR_LO_1_ADDR(base) ((base) + (0x0258))
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x0AC8))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0268))
#define SOC_MediaCommon_HEBC_HREG_FORMAT_ADDR(base) ((base) + (0x0ACC))
#define SOC_MediaCommon_HEBC_MM_BASE_1_ADDR(base) ((base) + (0x0AD0))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0A00))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_ISPIF_EN_ADDR(base) ((base) + (0x000UL))
#define SOC_MediaCommon_ISPIF_CLK_SEL_ADDR(base) ((base) + (0x004UL))
#define SOC_MediaCommon_ISPIF_CLK_EN_ADDR(base) ((base) + (0x008UL))
#define SOC_MediaCommon_ISPIF_IN_SIZE_ADDR(base) ((base) + (0x00CUL))
#define SOC_MediaCommon_ISPIF_RD_SHADOW_ADDR(base) ((base) + (0x010UL))
#define SOC_MediaCommon_ISPIF_DBG0_ADDR(base) ((base) + (0x014UL))
#define SOC_MediaCommon_ISPIF_DBG1_ADDR(base) ((base) + (0x018UL))
#define SOC_MediaCommon_ISPIF_DBG2_ADDR(base) ((base) + (0x01CUL))
#define SOC_MediaCommon_ISPIF_DBG3_ADDR(base) ((base) + (0x020UL))
#define SOC_MediaCommon_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100UL))
#define SOC_MediaCommon_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104UL))
#define SOC_MediaCommon_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108UL))
#define SOC_MediaCommon_DFC_DISP_FMT_ADDR(base) ((base) + (0x010CUL))
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110UL))
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114UL))
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118UL))
#define SOC_MediaCommon_DFC_MODULE_EN_ADDR(base) ((base) + (0x011CUL))
#define SOC_MediaCommon_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120UL))
#define SOC_MediaCommon_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124UL))
#define SOC_MediaCommon_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128UL))
#define SOC_MediaCommon_BITEXT_CTL_ADDR(base) ((base) + (0x0140UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014CUL))
#define SOC_MediaCommon_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015CUL))
#define SOC_MediaCommon_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016CUL))
#define SOC_MediaCommon_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170UL))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174UL))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178UL))
#define SOC_MediaCommon_BITEXT_FILT_00_ADDR(base) ((base) + (0x017CUL))
#define SOC_MediaCommon_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180UL))
#define SOC_MediaCommon_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184UL))
#define SOC_MediaCommon_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188UL))
#define SOC_MediaCommon_BITEXT_FILT_11_ADDR(base) ((base) + (0x018CUL))
#define SOC_MediaCommon_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190UL))
#define SOC_MediaCommon_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194UL))
#define SOC_MediaCommon_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0UL))
#define SOC_MediaCommon_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4UL))
#define SOC_MediaCommon_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8UL))
#define SOC_MediaCommon_BITEXT_THD_R1_ADDR(base) ((base) + (0x01ACUL))
#define SOC_MediaCommon_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0UL))
#define SOC_MediaCommon_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4UL))
#define SOC_MediaCommon_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8UL))
#define SOC_MediaCommon_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BCUL))
#define SOC_MediaCommon_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0UL))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0200UL))
#else
#define SOC_MediaCommon_ISPIF_EN_ADDR(base) ((base) + (0x000))
#define SOC_MediaCommon_ISPIF_CLK_SEL_ADDR(base) ((base) + (0x004))
#define SOC_MediaCommon_ISPIF_CLK_EN_ADDR(base) ((base) + (0x008))
#define SOC_MediaCommon_ISPIF_IN_SIZE_ADDR(base) ((base) + (0x00C))
#define SOC_MediaCommon_ISPIF_RD_SHADOW_ADDR(base) ((base) + (0x010))
#define SOC_MediaCommon_ISPIF_DBG0_ADDR(base) ((base) + (0x014))
#define SOC_MediaCommon_ISPIF_DBG1_ADDR(base) ((base) + (0x018))
#define SOC_MediaCommon_ISPIF_DBG2_ADDR(base) ((base) + (0x01C))
#define SOC_MediaCommon_ISPIF_DBG3_ADDR(base) ((base) + (0x020))
#define SOC_MediaCommon_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100))
#define SOC_MediaCommon_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104))
#define SOC_MediaCommon_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108))
#define SOC_MediaCommon_DFC_DISP_FMT_ADDR(base) ((base) + (0x010C))
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110))
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114))
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118))
#define SOC_MediaCommon_DFC_MODULE_EN_ADDR(base) ((base) + (0x011C))
#define SOC_MediaCommon_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120))
#define SOC_MediaCommon_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124))
#define SOC_MediaCommon_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128))
#define SOC_MediaCommon_BITEXT_CTL_ADDR(base) ((base) + (0x0140))
#define SOC_MediaCommon_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144))
#define SOC_MediaCommon_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148))
#define SOC_MediaCommon_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014C))
#define SOC_MediaCommon_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150))
#define SOC_MediaCommon_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154))
#define SOC_MediaCommon_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158))
#define SOC_MediaCommon_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015C))
#define SOC_MediaCommon_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160))
#define SOC_MediaCommon_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164))
#define SOC_MediaCommon_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168))
#define SOC_MediaCommon_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016C))
#define SOC_MediaCommon_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178))
#define SOC_MediaCommon_BITEXT_FILT_00_ADDR(base) ((base) + (0x017C))
#define SOC_MediaCommon_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180))
#define SOC_MediaCommon_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184))
#define SOC_MediaCommon_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188))
#define SOC_MediaCommon_BITEXT_FILT_11_ADDR(base) ((base) + (0x018C))
#define SOC_MediaCommon_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190))
#define SOC_MediaCommon_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194))
#define SOC_MediaCommon_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0))
#define SOC_MediaCommon_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4))
#define SOC_MediaCommon_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8))
#define SOC_MediaCommon_BITEXT_THD_R1_ADDR(base) ((base) + (0x01AC))
#define SOC_MediaCommon_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0))
#define SOC_MediaCommon_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4))
#define SOC_MediaCommon_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8))
#define SOC_MediaCommon_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BC))
#define SOC_MediaCommon_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0200))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MediaCommon_DMA_OFT_X0_ADDR(base) ((base) + (0x0000UL))
#define SOC_MediaCommon_DMA_OFT_Y0_ADDR(base) ((base) + (0x0004UL))
#define SOC_MediaCommon_DMA_OFT_X1_ADDR(base) ((base) + (0x0008UL))
#define SOC_MediaCommon_DMA_OFT_Y1_ADDR(base) ((base) + (0x000CUL))
#define SOC_MediaCommon_DMA_MASK0_ADDR(base) ((base) + (0x0010UL))
#define SOC_MediaCommon_DMA_MASK1_ADDR(base) ((base) + (0x0014UL))
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_ADDR(base) ((base) + (0x0018UL))
#define SOC_MediaCommon_DMA_CTRL_ADDR(base) ((base) + (0x001CUL))
#define SOC_MediaCommon_DMA_TILE_SCRAM_ADDR(base) ((base) + (0x0020UL))
#define SOC_MediaCommon_DMA_PULSE_ADDR(base) ((base) + (0x0028UL))
#define SOC_MediaCommon_RWCH_CFG0_ADDR(base) ((base) + (0x0030UL))
#define SOC_MediaCommon_DMA_FIFO_CLR_ADDR(base) ((base) + (0x0034UL))
#define SOC_MediaCommon_DMA_COUNTER_DGB_ADDR(base) ((base) + (0x003CUL))
#define SOC_MediaCommon_DMA_ROT_BURST4_ADDR(base) ((base) + (0x0040UL))
#define SOC_MediaCommon_DMA_RSV1_ADDR(base) ((base) + (0x0044UL))
#define SOC_MediaCommon_DMA_RSV2_ADDR(base) ((base) + (0x0048UL))
#define SOC_MediaCommon_DMA_SW_MASK_EN_ADDR(base) ((base) + (0x004CUL))
#define SOC_MediaCommon_DMA_START_MASK0_ADDR(base) ((base) + (0x0050UL))
#define SOC_MediaCommon_DMA_END_MASK0_ADDR(base) ((base) + (0x0054UL))
#define SOC_MediaCommon_DMA_START_MASK1_ADDR(base) ((base) + (0x0058UL))
#define SOC_MediaCommon_DMA_END_MASK1_ADDR(base) ((base) + (0x005CUL))
#define SOC_MediaCommon_DMA_DATA_ADDR0_ADDR(base) ((base) + (0x0060UL))
#define SOC_MediaCommon_DMA_STRIDE0_ADDR(base) ((base) + (0x0064UL))
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_ADDR(base) ((base) + (0x0068UL))
#define SOC_MediaCommon_DMA_DATA_NUM0_ADDR(base) ((base) + (0x006CUL))
#define SOC_MediaCommon_DMA_TEST0_ADDR(base) ((base) + (0x0070UL))
#define SOC_MediaCommon_DMA_TEST1_ADDR(base) ((base) + (0x0074UL))
#define SOC_MediaCommon_DMA_TEST3_ADDR(base) ((base) + (0x0078UL))
#define SOC_MediaCommon_DMA_TEST4_ADDR(base) ((base) + (0x007CUL))
#define SOC_MediaCommon_DMA_STATUS_Y_ADDR(base) ((base) + (0x0080UL))
#define SOC_MediaCommon_DMA_DATA_ADDR1_ADDR(base) ((base) + (0x0084UL))
#define SOC_MediaCommon_DMA_STRIDE1_ADDR(base) ((base) + (0x0088UL))
#define SOC_MediaCommon_DMA_STRETCH_STRIDE1_ADDR(base) ((base) + (0x008CUL))
#define SOC_MediaCommon_DMA_DATA_NUM1_ADDR(base) ((base) + (0x0090UL))
#define SOC_MediaCommon_DMA_TEST0_U_ADDR(base) ((base) + (0x0094UL))
#define SOC_MediaCommon_DMA_TEST1_U_ADDR(base) ((base) + (0x0098UL))
#define SOC_MediaCommon_DMA_TEST3_U_ADDR(base) ((base) + (0x009CUL))
#define SOC_MediaCommon_DMA_TEST4_U_ADDR(base) ((base) + (0x00A0UL))
#define SOC_MediaCommon_DMA_STATUS_U_ADDR(base) ((base) + (0x00A4UL))
#define SOC_MediaCommon_CH_RD_SHADOW_ADDR(base) ((base) + (0x00D0UL))
#define SOC_MediaCommon_CH_CTL_ADDR(base) ((base) + (0x00D4UL))
#define SOC_MediaCommon_CH_SECU_EN_ADDR(base) ((base) + (0x00D8UL))
#define SOC_MediaCommon_CH_SW_END_REQ_ADDR(base) ((base) + (0x00DCUL))
#define SOC_MediaCommon_CH_CLK_SEL_ADDR(base) ((base) + (0x00E0UL))
#define SOC_MediaCommon_CH_CLK_EN_ADDR(base) ((base) + (0x00E4UL))
#define SOC_MediaCommon_CH_DBG0_ADDR(base) ((base) + (0x00E8UL))
#define SOC_MediaCommon_CH_DBG1_ADDR(base) ((base) + (0x00ECUL))
#define SOC_MediaCommon_CH_DBG2_ADDR(base) ((base) + (0x00F0UL))
#define SOC_MediaCommon_CH_DBG3_ADDR(base) ((base) + (0x00F4UL))
#define SOC_MediaCommon_CH_DBG4_ADDR(base) ((base) + (0x00F8UL))
#define SOC_MediaCommon_CH_DBG5_ADDR(base) ((base) + (0x00FCUL))
#define SOC_MediaCommon_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100UL))
#define SOC_MediaCommon_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104UL))
#define SOC_MediaCommon_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108UL))
#define SOC_MediaCommon_DFC_DISP_FMT_ADDR(base) ((base) + (0x010CUL))
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110UL))
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114UL))
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118UL))
#define SOC_MediaCommon_DFC_ICG_MODULE_ADDR(base) ((base) + (0x011CUL))
#define SOC_MediaCommon_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120UL))
#define SOC_MediaCommon_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124UL))
#define SOC_MediaCommon_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128UL))
#define SOC_MediaCommon_DFC_GLB_ALPHA_ADDR(base) ((base) + (0x012CUL))
#define SOC_MediaCommon_DFC_ALPHA_CTL_ADDR(base) ((base) + (0x0130UL))
#define SOC_MediaCommon_DFC_ALPHA_THD_ADDR(base) ((base) + (0x0134UL))
#define SOC_MediaCommon_BITEXT_CTL_ADDR(base) ((base) + (0x0140UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148UL))
#define SOC_MediaCommon_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014CUL))
#define SOC_MediaCommon_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158UL))
#define SOC_MediaCommon_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015CUL))
#define SOC_MediaCommon_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168UL))
#define SOC_MediaCommon_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016CUL))
#define SOC_MediaCommon_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170UL))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174UL))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178UL))
#define SOC_MediaCommon_BITEXT_FILT_00_ADDR(base) ((base) + (0x017CUL))
#define SOC_MediaCommon_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180UL))
#define SOC_MediaCommon_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184UL))
#define SOC_MediaCommon_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188UL))
#define SOC_MediaCommon_BITEXT_FILT_11_ADDR(base) ((base) + (0x018CUL))
#define SOC_MediaCommon_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190UL))
#define SOC_MediaCommon_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194UL))
#define SOC_MediaCommon_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0UL))
#define SOC_MediaCommon_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4UL))
#define SOC_MediaCommon_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8UL))
#define SOC_MediaCommon_BITEXT_THD_R1_ADDR(base) ((base) + (0x01ACUL))
#define SOC_MediaCommon_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0UL))
#define SOC_MediaCommon_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4UL))
#define SOC_MediaCommon_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8UL))
#define SOC_MediaCommon_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BCUL))
#define SOC_MediaCommon_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0UL))
#define SOC_MediaCommon_DITHER_CTL1_ADDR(base) ((base) + (0x01D0UL))
#define SOC_MediaCommon_DITHER_TRI_THD10_ADDR(base) ((base) + (0x01DCUL))
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_ADDR(base) ((base) + (0x01E8UL))
#define SOC_MediaCommon_BAYER_CTL_ADDR(base) ((base) + (0x01ECUL))
#define SOC_MediaCommon_BAYER_MATRIX_PART1_ADDR(base) ((base) + (0x01F4UL))
#define SOC_MediaCommon_BAYER_MATRIX_PART0_ADDR(base) ((base) + (0x01F8UL))
#define SOC_MediaCommon_SCF_EN_HSCL_STR_ADDR(base) ((base) + (0x0200UL))
#define SOC_MediaCommon_SCF_EN_VSCL_STR_ADDR(base) ((base) + (0x0204UL))
#define SOC_MediaCommon_SCF_H_V_ORDER_ADDR(base) ((base) + (0x0208UL))
#define SOC_MediaCommon_SCF_CH_CORE_GT_ADDR(base) ((base) + (0x020CUL))
#define SOC_MediaCommon_SCF_INPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0210UL))
#define SOC_MediaCommon_SCF_OUTPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0214UL))
#define SOC_MediaCommon_SCF_COEF_MEM_CTRL_ADDR(base) ((base) + (0x0218UL))
#define SOC_MediaCommon_SCF_EN_HSCL_ADDR(base) ((base) + (0x021CUL))
#define SOC_MediaCommon_SCF_EN_VSCL_ADDR(base) ((base) + (0x0220UL))
#define SOC_MediaCommon_SCF_ACC_HSCL_ADDR(base) ((base) + (0x0224UL))
#define SOC_MediaCommon_SCF_ACC_HSCL1_ADDR(base) ((base) + (0x0228UL))
#define SOC_MediaCommon_SCF_INC_HSCL_ADDR(base) ((base) + (0x0234UL))
#define SOC_MediaCommon_SCF_ACC_VSCL_ADDR(base) ((base) + (0x0238UL))
#define SOC_MediaCommon_SCF_ACC_VSCL1_ADDR(base) ((base) + (0x023CUL))
#define SOC_MediaCommon_SCF_INC_VSCL_ADDR(base) ((base) + (0x0248UL))
#define SOC_MediaCommon_SCF_EN_NONLINEAR_ADDR(base) ((base) + (0x024CUL))
#define SOC_MediaCommon_SCF_EN_MMP_ADDR(base) ((base) + (0x027CUL))
#define SOC_MediaCommon_SCF_DB_H0_ADDR(base) ((base) + (0x0280UL))
#define SOC_MediaCommon_SCF_DB_H1_ADDR(base) ((base) + (0x0284UL))
#define SOC_MediaCommon_SCF_DB_V0_ADDR(base) ((base) + (0x0288UL))
#define SOC_MediaCommon_SCF_DB_V1_ADDR(base) ((base) + (0x028CUL))
#define SOC_MediaCommon_SCF_LB_MEM_CTRL_ADDR(base) ((base) + (0x0290UL))
#define SOC_MediaCommon_PCSC_IDC0_ADDR(base) ((base) + (0x0400UL))
#define SOC_MediaCommon_PCSC_IDC2_ADDR(base) ((base) + (0x0404UL))
#define SOC_MediaCommon_PCSC_ODC0_ADDR(base) ((base) + (0x0408UL))
#define SOC_MediaCommon_PCSC_ODC2_ADDR(base) ((base) + (0x040CUL))
#define SOC_MediaCommon_PCSC_P00_ADDR(base) ((base) + (0x0410UL))
#define SOC_MediaCommon_PCSC_P01_ADDR(base) ((base) + (0x0414UL))
#define SOC_MediaCommon_PCSC_P02_ADDR(base) ((base) + (0x0418UL))
#define SOC_MediaCommon_PCSC_P10_ADDR(base) ((base) + (0x041CUL))
#define SOC_MediaCommon_PCSC_P11_ADDR(base) ((base) + (0x0420UL))
#define SOC_MediaCommon_PCSC_P12_ADDR(base) ((base) + (0x0424UL))
#define SOC_MediaCommon_PCSC_P20_ADDR(base) ((base) + (0x0428UL))
#define SOC_MediaCommon_PCSC_P21_ADDR(base) ((base) + (0x042CUL))
#define SOC_MediaCommon_PCSC_P22_ADDR(base) ((base) + (0x0430UL))
#define SOC_MediaCommon_PCSC_ICG_MODULE_ADDR(base) ((base) + (0x0434UL))
#define SOC_MediaCommon_PCSC_MPREC_ADDR(base) ((base) + (0x0438UL))
#define SOC_MediaCommon_POST_CLIP_DISP_SIZE_ADDR(base) ((base) + (0x0480UL))
#define SOC_MediaCommon_POST_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0484UL))
#define SOC_MediaCommon_POST_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0488UL))
#define SOC_MediaCommon_POST_CLIP_EN_ADDR(base) ((base) + (0x048CUL))
#define SOC_MediaCommon_CSC_IDC0_ADDR(base) ((base) + (0x0500UL))
#define SOC_MediaCommon_CSC_IDC2_ADDR(base) ((base) + (0x0504UL))
#define SOC_MediaCommon_CSC_ODC0_ADDR(base) ((base) + (0x0508UL))
#define SOC_MediaCommon_CSC_ODC2_ADDR(base) ((base) + (0x050CUL))
#define SOC_MediaCommon_CSC_P00_ADDR(base) ((base) + (0x0510UL))
#define SOC_MediaCommon_CSC_P01_ADDR(base) ((base) + (0x0514UL))
#define SOC_MediaCommon_CSC_P02_ADDR(base) ((base) + (0x0518UL))
#define SOC_MediaCommon_CSC_P10_ADDR(base) ((base) + (0x051CUL))
#define SOC_MediaCommon_CSC_P11_ADDR(base) ((base) + (0x0520UL))
#define SOC_MediaCommon_CSC_P12_ADDR(base) ((base) + (0x0524UL))
#define SOC_MediaCommon_CSC_P20_ADDR(base) ((base) + (0x0528UL))
#define SOC_MediaCommon_CSC_P21_ADDR(base) ((base) + (0x052CUL))
#define SOC_MediaCommon_CSC_P22_ADDR(base) ((base) + (0x0530UL))
#define SOC_MediaCommon_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0534UL))
#define SOC_MediaCommon_CSC_MPREC_ADDR(base) ((base) + (0x0538UL))
#define SOC_MediaCommon_ROT_FIRST_LNS_ADDR(base) ((base) + (0x0580UL))
#define SOC_MediaCommon_ROT_STATE_ADDR(base) ((base) + (0x0584UL))
#define SOC_MediaCommon_ROT_MEM_CTRL_ADDR(base) ((base) + (0x0588UL))
#define SOC_MediaCommon_ROT_SIZE_ADDR(base) ((base) + (0x058CUL))
#define SOC_MediaCommon_ROT_422_MODE_ADDR(base) ((base) + (0x0590UL))
#define SOC_MediaCommon_ROT_CPU_START0_ADDR(base) ((base) + (0x0594UL))
#define SOC_MediaCommon_ROT_CPU_ADDR0_ADDR(base) ((base) + (0x0598UL))
#define SOC_MediaCommon_ROT_CPU_RDATA0_ADDR(base) ((base) + (0x059CUL))
#define SOC_MediaCommon_ROT_CPU_RDATA1_ADDR(base) ((base) + (0x05A0UL))
#define SOC_MediaCommon_ROT_CPU_WDATA0_ADDR(base) ((base) + (0x05A4UL))
#define SOC_MediaCommon_ROT_CPU_WDATA1_ADDR(base) ((base) + (0x05A8UL))
#define SOC_MediaCommon_ROT_CPU_CTL1_ADDR(base) ((base) + (0x05ACUL))
#define SOC_MediaCommon_ROT_CPU_START1_ADDR(base) ((base) + (0x05B0UL))
#define SOC_MediaCommon_ROT_CPU_ADDR1_ADDR(base) ((base) + (0x05B4UL))
#define SOC_MediaCommon_ROT_CPU_RDATA2_ADDR(base) ((base) + (0x05B8UL))
#define SOC_MediaCommon_ROT_CPU_RDATA3_ADDR(base) ((base) + (0x05BCUL))
#define SOC_MediaCommon_ROT_CPU_WDATA2_ADDR(base) ((base) + (0x05C0UL))
#define SOC_MediaCommon_ROT_CPU_WDATA3_ADDR(base) ((base) + (0x05C4UL))
#define SOC_MediaCommon_CH_DEBUG_SEL_ADDR(base) ((base) + (0x600UL))
#define SOC_MediaCommon_DMA_BUF_CTRL_ADDR(base) ((base) + (0x0800UL))
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_ADDR(base) ((base) + (0x0804UL))
#define SOC_MediaCommon_DMA_BUF_CPU_START_ADDR(base) ((base) + (0x0808UL))
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_ADDR(base) ((base) + (0x080CUL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_ADDR(base) ((base) + (0x0810UL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_ADDR(base) ((base) + (0x814UL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_ADDR(base) ((base) + (0x818UL))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_ADDR(base) ((base) + (0x81CUL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_ADDR(base) ((base) + (0x820UL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_ADDR(base) ((base) + (0x824UL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_ADDR(base) ((base) + (0x828UL))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_ADDR(base) ((base) + (0x82CUL))
#define SOC_MediaCommon_DMA_REQ_END_ADDR(base) ((base) + (0x830UL))
#define SOC_MediaCommon_DMA_BUF_DBGCFG_ADDR(base) ((base) + (0x834UL))
#define SOC_MediaCommon_DMA_BUF_DBG0_ADDR(base) ((base) + (0x838UL))
#define SOC_MediaCommon_DMA_BUF_DBG1_ADDR(base) ((base) + (0x83CUL))
#define SOC_MediaCommon_DMA_BUF_DBG2_ADDR(base) ((base) + (0x840UL))
#define SOC_MediaCommon_DMA_BUF_DBG3_ADDR(base) ((base) + (0x844UL))
#define SOC_MediaCommon_DMA_BUF_DBG4_ADDR(base) ((base) + (0x848UL))
#define SOC_MediaCommon_DMA_BUF_DBG5_ADDR(base) ((base) + (0x84CUL))
#define SOC_MediaCommon_DMA_BUF_SIZE_ADDR(base) ((base) + (0x850UL))
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_ADDR(base) ((base) + (0x0854UL))
#define SOC_MediaCommon_AFBCE_HREG_PIC_BLKS_ADDR(base) ((base) + (0x0900UL))
#define SOC_MediaCommon_AFBCE_HREG_FORMAT_ADDR(base) ((base) + (0x0904UL))
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L0_ADDR(base) ((base) + (0x0908UL))
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L0_ADDR(base) ((base) + (0x090CUL))
#define SOC_MediaCommon_PICTURE_SIZE_ADDR(base) ((base) + (0x0910UL))
#define SOC_MediaCommon_HEADER_SRTIDE_0_ADDR(base) ((base) + (0x0918UL))
#define SOC_MediaCommon_PAYLOAD_STRIDE_0_ADDR(base) ((base) + (0x091CUL))
#define SOC_MediaCommon_ENC_OS_CFG_ADDR(base) ((base) + (0x0920UL))
#define SOC_MediaCommon_AFBCE_MEM_CTRL_ADDR(base) ((base) + (0x0924UL))
#define SOC_MediaCommon_AFBCE_QOS_CFG_ADDR(base) ((base) + (0x0928UL))
#define SOC_MediaCommon_FBCE_THRESHOLD_ADDR(base) ((base) + (0x092CUL))
#define SOC_MediaCommon_FBCE_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0930UL))
#define SOC_MediaCommon_AFBCE_HEADER_POINTER_OFFSET_ADDR(base) ((base) + (0x0934UL))
#define SOC_MediaCommon_AFBCE_MONITOR_REG1_ADDR(base) ((base) + (0x0938UL))
#define SOC_MediaCommon_AFBCE_MONITOR_REG2_ADDR(base) ((base) + (0x093CUL))
#define SOC_MediaCommon_AFBCE_MONITOR_REG3_ADDR(base) ((base) + (0x0940UL))
#define SOC_MediaCommon_AFBCE_DEBUG_REG0_ADDR(base) ((base) + (0x0944UL))
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_ADDR(base) ((base) + (0x0950UL))
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L1_ADDR(base) ((base) + (0x0954UL))
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L1_ADDR(base) ((base) + (0x0958UL))
#define SOC_MediaCommon_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x095CUL))
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0960UL))
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_ADDR(base) ((base) + (0x0964UL))
#define SOC_MediaCommon_AFBCE_MEM_CTRL_1_ADDR(base) ((base) + (0x0968UL))
#define SOC_MediaCommon_AFBCE_MONITOR_REG4_ADDR(base) ((base) + (0x096CUL))
#define SOC_MediaCommon_AFBCE_MONITOR_REG5_ADDR(base) ((base) + (0x0970UL))
#define SOC_MediaCommon_AFBCE_MONITOR_REG6_ADDR(base) ((base) + (0x0974UL))
#define SOC_MediaCommon_DMA_ADDR_EXT_ADDR(base) ((base) + (0x0A40UL))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_ADDR(base) ((base) + (0x0A80UL))
#define SOC_MediaCommon_HEBC_HREG_PIC_WIDTH_ADDR(base) ((base) + (0x01B0UL))
#define SOC_MediaCommon_HEBC_HREG_PIC_HEIGHT_ADDR(base) ((base) + (0x01B8UL))
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_ADDR(base) ((base) + (0x0A88UL))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_ADDR(base) ((base) + (0x0A8CUL))
#define SOC_MediaCommon_HEBC_PAYLOAD_POINTER_ADDR(base) ((base) + (0x0A94UL))
#define SOC_MediaCommon_HEBC_OS_CFG_ADDR(base) ((base) + (0x0A98UL))
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0A9CUL))
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_ADDR(base) ((base) + (0x0AA0UL))
#define SOC_MediaCommon_HEBC_TAG_VALUE0_ADDR(base) ((base) + (0x0AA4UL))
#define SOC_MediaCommon_HEBC_TAG_VALUE1_ADDR(base) ((base) + (0x0AA8UL))
#define SOC_MediaCommon_HEBC_TAG_VALUE2_ADDR(base) ((base) + (0x0AACUL))
#define SOC_MediaCommon_HEBC_TAG_VALUE3_ADDR(base) ((base) + (0x0AB0UL))
#define SOC_MediaCommon_HEBC_RESERVED0_ADDR(base) ((base) + (0x0AB4UL))
#define SOC_MediaCommon_HEBC_RESERVED1_ADDR(base) ((base) + (0x0AB8UL))
#define SOC_MediaCommon_HEBC_RESERVED2_ADDR(base) ((base) + (0x0ABCUL))
#define SOC_MediaCommon_HEBC_RESERVED3_ADDR(base) ((base) + (0x0AC0UL))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_ADDR(base) ((base) + (0x0AC4UL))
#define SOC_MediaCommon_HEBC_HREG_PLD_PTR_LO_1_ADDR(base) ((base) + (0x0258UL))
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x0AC8UL))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0268UL))
#define SOC_MediaCommon_HEBC_HREG_FORMAT_ADDR(base) ((base) + (0x0ACCUL))
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_ADDR(base) ((base) + (0x0AD4UL))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0A00UL))
#define SOC_MediaCommon_V0_SCF_VIDEO_6TAP_COEF_ADDR(base,l) ((base) + (0x1000+0x4*(l)))
#define SOC_MediaCommon_V0_SCF_VIDEO_5TAP_COEF_ADDR(base,m) ((base) + (0x3000+0x4*(m)))
#define SOC_MediaCommon_V0_SCF_VIDEO_4TAP_COEF_ADDR(base,n) ((base) + (0x3800+0x4*(n)))
#else
#define SOC_MediaCommon_DMA_OFT_X0_ADDR(base) ((base) + (0x0000))
#define SOC_MediaCommon_DMA_OFT_Y0_ADDR(base) ((base) + (0x0004))
#define SOC_MediaCommon_DMA_OFT_X1_ADDR(base) ((base) + (0x0008))
#define SOC_MediaCommon_DMA_OFT_Y1_ADDR(base) ((base) + (0x000C))
#define SOC_MediaCommon_DMA_MASK0_ADDR(base) ((base) + (0x0010))
#define SOC_MediaCommon_DMA_MASK1_ADDR(base) ((base) + (0x0014))
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_ADDR(base) ((base) + (0x0018))
#define SOC_MediaCommon_DMA_CTRL_ADDR(base) ((base) + (0x001C))
#define SOC_MediaCommon_DMA_TILE_SCRAM_ADDR(base) ((base) + (0x0020))
#define SOC_MediaCommon_DMA_PULSE_ADDR(base) ((base) + (0x0028))
#define SOC_MediaCommon_RWCH_CFG0_ADDR(base) ((base) + (0x0030))
#define SOC_MediaCommon_DMA_FIFO_CLR_ADDR(base) ((base) + (0x0034))
#define SOC_MediaCommon_DMA_COUNTER_DGB_ADDR(base) ((base) + (0x003C))
#define SOC_MediaCommon_DMA_ROT_BURST4_ADDR(base) ((base) + (0x0040))
#define SOC_MediaCommon_DMA_RSV1_ADDR(base) ((base) + (0x0044))
#define SOC_MediaCommon_DMA_RSV2_ADDR(base) ((base) + (0x0048))
#define SOC_MediaCommon_DMA_SW_MASK_EN_ADDR(base) ((base) + (0x004C))
#define SOC_MediaCommon_DMA_START_MASK0_ADDR(base) ((base) + (0x0050))
#define SOC_MediaCommon_DMA_END_MASK0_ADDR(base) ((base) + (0x0054))
#define SOC_MediaCommon_DMA_START_MASK1_ADDR(base) ((base) + (0x0058))
#define SOC_MediaCommon_DMA_END_MASK1_ADDR(base) ((base) + (0x005C))
#define SOC_MediaCommon_DMA_DATA_ADDR0_ADDR(base) ((base) + (0x0060))
#define SOC_MediaCommon_DMA_STRIDE0_ADDR(base) ((base) + (0x0064))
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_ADDR(base) ((base) + (0x0068))
#define SOC_MediaCommon_DMA_DATA_NUM0_ADDR(base) ((base) + (0x006C))
#define SOC_MediaCommon_DMA_TEST0_ADDR(base) ((base) + (0x0070))
#define SOC_MediaCommon_DMA_TEST1_ADDR(base) ((base) + (0x0074))
#define SOC_MediaCommon_DMA_TEST3_ADDR(base) ((base) + (0x0078))
#define SOC_MediaCommon_DMA_TEST4_ADDR(base) ((base) + (0x007C))
#define SOC_MediaCommon_DMA_STATUS_Y_ADDR(base) ((base) + (0x0080))
#define SOC_MediaCommon_DMA_DATA_ADDR1_ADDR(base) ((base) + (0x0084))
#define SOC_MediaCommon_DMA_STRIDE1_ADDR(base) ((base) + (0x0088))
#define SOC_MediaCommon_DMA_STRETCH_STRIDE1_ADDR(base) ((base) + (0x008C))
#define SOC_MediaCommon_DMA_DATA_NUM1_ADDR(base) ((base) + (0x0090))
#define SOC_MediaCommon_DMA_TEST0_U_ADDR(base) ((base) + (0x0094))
#define SOC_MediaCommon_DMA_TEST1_U_ADDR(base) ((base) + (0x0098))
#define SOC_MediaCommon_DMA_TEST3_U_ADDR(base) ((base) + (0x009C))
#define SOC_MediaCommon_DMA_TEST4_U_ADDR(base) ((base) + (0x00A0))
#define SOC_MediaCommon_DMA_STATUS_U_ADDR(base) ((base) + (0x00A4))
#define SOC_MediaCommon_CH_RD_SHADOW_ADDR(base) ((base) + (0x00D0))
#define SOC_MediaCommon_CH_CTL_ADDR(base) ((base) + (0x00D4))
#define SOC_MediaCommon_CH_SECU_EN_ADDR(base) ((base) + (0x00D8))
#define SOC_MediaCommon_CH_SW_END_REQ_ADDR(base) ((base) + (0x00DC))
#define SOC_MediaCommon_CH_CLK_SEL_ADDR(base) ((base) + (0x00E0))
#define SOC_MediaCommon_CH_CLK_EN_ADDR(base) ((base) + (0x00E4))
#define SOC_MediaCommon_CH_DBG0_ADDR(base) ((base) + (0x00E8))
#define SOC_MediaCommon_CH_DBG1_ADDR(base) ((base) + (0x00EC))
#define SOC_MediaCommon_CH_DBG2_ADDR(base) ((base) + (0x00F0))
#define SOC_MediaCommon_CH_DBG3_ADDR(base) ((base) + (0x00F4))
#define SOC_MediaCommon_CH_DBG4_ADDR(base) ((base) + (0x00F8))
#define SOC_MediaCommon_CH_DBG5_ADDR(base) ((base) + (0x00FC))
#define SOC_MediaCommon_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100))
#define SOC_MediaCommon_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104))
#define SOC_MediaCommon_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108))
#define SOC_MediaCommon_DFC_DISP_FMT_ADDR(base) ((base) + (0x010C))
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110))
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114))
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118))
#define SOC_MediaCommon_DFC_ICG_MODULE_ADDR(base) ((base) + (0x011C))
#define SOC_MediaCommon_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120))
#define SOC_MediaCommon_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124))
#define SOC_MediaCommon_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128))
#define SOC_MediaCommon_DFC_GLB_ALPHA_ADDR(base) ((base) + (0x012C))
#define SOC_MediaCommon_DFC_ALPHA_CTL_ADDR(base) ((base) + (0x0130))
#define SOC_MediaCommon_DFC_ALPHA_THD_ADDR(base) ((base) + (0x0134))
#define SOC_MediaCommon_BITEXT_CTL_ADDR(base) ((base) + (0x0140))
#define SOC_MediaCommon_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144))
#define SOC_MediaCommon_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148))
#define SOC_MediaCommon_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014C))
#define SOC_MediaCommon_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150))
#define SOC_MediaCommon_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154))
#define SOC_MediaCommon_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158))
#define SOC_MediaCommon_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015C))
#define SOC_MediaCommon_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160))
#define SOC_MediaCommon_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164))
#define SOC_MediaCommon_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168))
#define SOC_MediaCommon_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016C))
#define SOC_MediaCommon_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174))
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178))
#define SOC_MediaCommon_BITEXT_FILT_00_ADDR(base) ((base) + (0x017C))
#define SOC_MediaCommon_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180))
#define SOC_MediaCommon_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184))
#define SOC_MediaCommon_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188))
#define SOC_MediaCommon_BITEXT_FILT_11_ADDR(base) ((base) + (0x018C))
#define SOC_MediaCommon_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190))
#define SOC_MediaCommon_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194))
#define SOC_MediaCommon_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0))
#define SOC_MediaCommon_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4))
#define SOC_MediaCommon_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8))
#define SOC_MediaCommon_BITEXT_THD_R1_ADDR(base) ((base) + (0x01AC))
#define SOC_MediaCommon_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0))
#define SOC_MediaCommon_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4))
#define SOC_MediaCommon_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8))
#define SOC_MediaCommon_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BC))
#define SOC_MediaCommon_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0))
#define SOC_MediaCommon_DITHER_CTL1_ADDR(base) ((base) + (0x01D0))
#define SOC_MediaCommon_DITHER_TRI_THD10_ADDR(base) ((base) + (0x01DC))
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_ADDR(base) ((base) + (0x01E8))
#define SOC_MediaCommon_BAYER_CTL_ADDR(base) ((base) + (0x01EC))
#define SOC_MediaCommon_BAYER_MATRIX_PART1_ADDR(base) ((base) + (0x01F4))
#define SOC_MediaCommon_BAYER_MATRIX_PART0_ADDR(base) ((base) + (0x01F8))
#define SOC_MediaCommon_SCF_EN_HSCL_STR_ADDR(base) ((base) + (0x0200))
#define SOC_MediaCommon_SCF_EN_VSCL_STR_ADDR(base) ((base) + (0x0204))
#define SOC_MediaCommon_SCF_H_V_ORDER_ADDR(base) ((base) + (0x0208))
#define SOC_MediaCommon_SCF_CH_CORE_GT_ADDR(base) ((base) + (0x020C))
#define SOC_MediaCommon_SCF_INPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0210))
#define SOC_MediaCommon_SCF_OUTPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0214))
#define SOC_MediaCommon_SCF_COEF_MEM_CTRL_ADDR(base) ((base) + (0x0218))
#define SOC_MediaCommon_SCF_EN_HSCL_ADDR(base) ((base) + (0x021C))
#define SOC_MediaCommon_SCF_EN_VSCL_ADDR(base) ((base) + (0x0220))
#define SOC_MediaCommon_SCF_ACC_HSCL_ADDR(base) ((base) + (0x0224))
#define SOC_MediaCommon_SCF_ACC_HSCL1_ADDR(base) ((base) + (0x0228))
#define SOC_MediaCommon_SCF_INC_HSCL_ADDR(base) ((base) + (0x0234))
#define SOC_MediaCommon_SCF_ACC_VSCL_ADDR(base) ((base) + (0x0238))
#define SOC_MediaCommon_SCF_ACC_VSCL1_ADDR(base) ((base) + (0x023C))
#define SOC_MediaCommon_SCF_INC_VSCL_ADDR(base) ((base) + (0x0248))
#define SOC_MediaCommon_SCF_EN_NONLINEAR_ADDR(base) ((base) + (0x024C))
#define SOC_MediaCommon_SCF_EN_MMP_ADDR(base) ((base) + (0x027C))
#define SOC_MediaCommon_SCF_DB_H0_ADDR(base) ((base) + (0x0280))
#define SOC_MediaCommon_SCF_DB_H1_ADDR(base) ((base) + (0x0284))
#define SOC_MediaCommon_SCF_DB_V0_ADDR(base) ((base) + (0x0288))
#define SOC_MediaCommon_SCF_DB_V1_ADDR(base) ((base) + (0x028C))
#define SOC_MediaCommon_SCF_LB_MEM_CTRL_ADDR(base) ((base) + (0x0290))
#define SOC_MediaCommon_PCSC_IDC0_ADDR(base) ((base) + (0x0400))
#define SOC_MediaCommon_PCSC_IDC2_ADDR(base) ((base) + (0x0404))
#define SOC_MediaCommon_PCSC_ODC0_ADDR(base) ((base) + (0x0408))
#define SOC_MediaCommon_PCSC_ODC2_ADDR(base) ((base) + (0x040C))
#define SOC_MediaCommon_PCSC_P00_ADDR(base) ((base) + (0x0410))
#define SOC_MediaCommon_PCSC_P01_ADDR(base) ((base) + (0x0414))
#define SOC_MediaCommon_PCSC_P02_ADDR(base) ((base) + (0x0418))
#define SOC_MediaCommon_PCSC_P10_ADDR(base) ((base) + (0x041C))
#define SOC_MediaCommon_PCSC_P11_ADDR(base) ((base) + (0x0420))
#define SOC_MediaCommon_PCSC_P12_ADDR(base) ((base) + (0x0424))
#define SOC_MediaCommon_PCSC_P20_ADDR(base) ((base) + (0x0428))
#define SOC_MediaCommon_PCSC_P21_ADDR(base) ((base) + (0x042C))
#define SOC_MediaCommon_PCSC_P22_ADDR(base) ((base) + (0x0430))
#define SOC_MediaCommon_PCSC_ICG_MODULE_ADDR(base) ((base) + (0x0434))
#define SOC_MediaCommon_PCSC_MPREC_ADDR(base) ((base) + (0x0438))
#define SOC_MediaCommon_POST_CLIP_DISP_SIZE_ADDR(base) ((base) + (0x0480))
#define SOC_MediaCommon_POST_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0484))
#define SOC_MediaCommon_POST_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0488))
#define SOC_MediaCommon_POST_CLIP_EN_ADDR(base) ((base) + (0x048C))
#define SOC_MediaCommon_CSC_IDC0_ADDR(base) ((base) + (0x0500))
#define SOC_MediaCommon_CSC_IDC2_ADDR(base) ((base) + (0x0504))
#define SOC_MediaCommon_CSC_ODC0_ADDR(base) ((base) + (0x0508))
#define SOC_MediaCommon_CSC_ODC2_ADDR(base) ((base) + (0x050C))
#define SOC_MediaCommon_CSC_P00_ADDR(base) ((base) + (0x0510))
#define SOC_MediaCommon_CSC_P01_ADDR(base) ((base) + (0x0514))
#define SOC_MediaCommon_CSC_P02_ADDR(base) ((base) + (0x0518))
#define SOC_MediaCommon_CSC_P10_ADDR(base) ((base) + (0x051C))
#define SOC_MediaCommon_CSC_P11_ADDR(base) ((base) + (0x0520))
#define SOC_MediaCommon_CSC_P12_ADDR(base) ((base) + (0x0524))
#define SOC_MediaCommon_CSC_P20_ADDR(base) ((base) + (0x0528))
#define SOC_MediaCommon_CSC_P21_ADDR(base) ((base) + (0x052C))
#define SOC_MediaCommon_CSC_P22_ADDR(base) ((base) + (0x0530))
#define SOC_MediaCommon_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0534))
#define SOC_MediaCommon_CSC_MPREC_ADDR(base) ((base) + (0x0538))
#define SOC_MediaCommon_ROT_FIRST_LNS_ADDR(base) ((base) + (0x0580))
#define SOC_MediaCommon_ROT_STATE_ADDR(base) ((base) + (0x0584))
#define SOC_MediaCommon_ROT_MEM_CTRL_ADDR(base) ((base) + (0x0588))
#define SOC_MediaCommon_ROT_SIZE_ADDR(base) ((base) + (0x058C))
#define SOC_MediaCommon_ROT_422_MODE_ADDR(base) ((base) + (0x0590))
#define SOC_MediaCommon_ROT_CPU_START0_ADDR(base) ((base) + (0x0594))
#define SOC_MediaCommon_ROT_CPU_ADDR0_ADDR(base) ((base) + (0x0598))
#define SOC_MediaCommon_ROT_CPU_RDATA0_ADDR(base) ((base) + (0x059C))
#define SOC_MediaCommon_ROT_CPU_RDATA1_ADDR(base) ((base) + (0x05A0))
#define SOC_MediaCommon_ROT_CPU_WDATA0_ADDR(base) ((base) + (0x05A4))
#define SOC_MediaCommon_ROT_CPU_WDATA1_ADDR(base) ((base) + (0x05A8))
#define SOC_MediaCommon_ROT_CPU_CTL1_ADDR(base) ((base) + (0x05AC))
#define SOC_MediaCommon_ROT_CPU_START1_ADDR(base) ((base) + (0x05B0))
#define SOC_MediaCommon_ROT_CPU_ADDR1_ADDR(base) ((base) + (0x05B4))
#define SOC_MediaCommon_ROT_CPU_RDATA2_ADDR(base) ((base) + (0x05B8))
#define SOC_MediaCommon_ROT_CPU_RDATA3_ADDR(base) ((base) + (0x05BC))
#define SOC_MediaCommon_ROT_CPU_WDATA2_ADDR(base) ((base) + (0x05C0))
#define SOC_MediaCommon_ROT_CPU_WDATA3_ADDR(base) ((base) + (0x05C4))
#define SOC_MediaCommon_CH_DEBUG_SEL_ADDR(base) ((base) + (0x600))
#define SOC_MediaCommon_DMA_BUF_CTRL_ADDR(base) ((base) + (0x0800))
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_ADDR(base) ((base) + (0x0804))
#define SOC_MediaCommon_DMA_BUF_CPU_START_ADDR(base) ((base) + (0x0808))
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_ADDR(base) ((base) + (0x080C))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_ADDR(base) ((base) + (0x0810))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_ADDR(base) ((base) + (0x814))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_ADDR(base) ((base) + (0x818))
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_ADDR(base) ((base) + (0x81C))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_ADDR(base) ((base) + (0x820))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_ADDR(base) ((base) + (0x824))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_ADDR(base) ((base) + (0x828))
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_ADDR(base) ((base) + (0x82C))
#define SOC_MediaCommon_DMA_REQ_END_ADDR(base) ((base) + (0x830))
#define SOC_MediaCommon_DMA_BUF_DBGCFG_ADDR(base) ((base) + (0x834))
#define SOC_MediaCommon_DMA_BUF_DBG0_ADDR(base) ((base) + (0x838))
#define SOC_MediaCommon_DMA_BUF_DBG1_ADDR(base) ((base) + (0x83C))
#define SOC_MediaCommon_DMA_BUF_DBG2_ADDR(base) ((base) + (0x840))
#define SOC_MediaCommon_DMA_BUF_DBG3_ADDR(base) ((base) + (0x844))
#define SOC_MediaCommon_DMA_BUF_DBG4_ADDR(base) ((base) + (0x848))
#define SOC_MediaCommon_DMA_BUF_DBG5_ADDR(base) ((base) + (0x84C))
#define SOC_MediaCommon_DMA_BUF_SIZE_ADDR(base) ((base) + (0x850))
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_ADDR(base) ((base) + (0x0854))
#define SOC_MediaCommon_AFBCE_HREG_PIC_BLKS_ADDR(base) ((base) + (0x0900))
#define SOC_MediaCommon_AFBCE_HREG_FORMAT_ADDR(base) ((base) + (0x0904))
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L0_ADDR(base) ((base) + (0x0908))
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L0_ADDR(base) ((base) + (0x090C))
#define SOC_MediaCommon_PICTURE_SIZE_ADDR(base) ((base) + (0x0910))
#define SOC_MediaCommon_HEADER_SRTIDE_0_ADDR(base) ((base) + (0x0918))
#define SOC_MediaCommon_PAYLOAD_STRIDE_0_ADDR(base) ((base) + (0x091C))
#define SOC_MediaCommon_ENC_OS_CFG_ADDR(base) ((base) + (0x0920))
#define SOC_MediaCommon_AFBCE_MEM_CTRL_ADDR(base) ((base) + (0x0924))
#define SOC_MediaCommon_AFBCE_QOS_CFG_ADDR(base) ((base) + (0x0928))
#define SOC_MediaCommon_FBCE_THRESHOLD_ADDR(base) ((base) + (0x092C))
#define SOC_MediaCommon_FBCE_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0930))
#define SOC_MediaCommon_AFBCE_HEADER_POINTER_OFFSET_ADDR(base) ((base) + (0x0934))
#define SOC_MediaCommon_AFBCE_MONITOR_REG1_ADDR(base) ((base) + (0x0938))
#define SOC_MediaCommon_AFBCE_MONITOR_REG2_ADDR(base) ((base) + (0x093C))
#define SOC_MediaCommon_AFBCE_MONITOR_REG3_ADDR(base) ((base) + (0x0940))
#define SOC_MediaCommon_AFBCE_DEBUG_REG0_ADDR(base) ((base) + (0x0944))
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_ADDR(base) ((base) + (0x0950))
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L1_ADDR(base) ((base) + (0x0954))
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L1_ADDR(base) ((base) + (0x0958))
#define SOC_MediaCommon_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x095C))
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0960))
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_ADDR(base) ((base) + (0x0964))
#define SOC_MediaCommon_AFBCE_MEM_CTRL_1_ADDR(base) ((base) + (0x0968))
#define SOC_MediaCommon_AFBCE_MONITOR_REG4_ADDR(base) ((base) + (0x096C))
#define SOC_MediaCommon_AFBCE_MONITOR_REG5_ADDR(base) ((base) + (0x0970))
#define SOC_MediaCommon_AFBCE_MONITOR_REG6_ADDR(base) ((base) + (0x0974))
#define SOC_MediaCommon_DMA_ADDR_EXT_ADDR(base) ((base) + (0x0A40))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_ADDR(base) ((base) + (0x0A80))
#define SOC_MediaCommon_HEBC_HREG_PIC_WIDTH_ADDR(base) ((base) + (0x01B0))
#define SOC_MediaCommon_HEBC_HREG_PIC_HEIGHT_ADDR(base) ((base) + (0x01B8))
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_ADDR(base) ((base) + (0x0A88))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_ADDR(base) ((base) + (0x0A8C))
#define SOC_MediaCommon_HEBC_PAYLOAD_POINTER_ADDR(base) ((base) + (0x0A94))
#define SOC_MediaCommon_HEBC_OS_CFG_ADDR(base) ((base) + (0x0A98))
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_ADDR(base) ((base) + (0x0A9C))
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_ADDR(base) ((base) + (0x0AA0))
#define SOC_MediaCommon_HEBC_TAG_VALUE0_ADDR(base) ((base) + (0x0AA4))
#define SOC_MediaCommon_HEBC_TAG_VALUE1_ADDR(base) ((base) + (0x0AA8))
#define SOC_MediaCommon_HEBC_TAG_VALUE2_ADDR(base) ((base) + (0x0AAC))
#define SOC_MediaCommon_HEBC_TAG_VALUE3_ADDR(base) ((base) + (0x0AB0))
#define SOC_MediaCommon_HEBC_RESERVED0_ADDR(base) ((base) + (0x0AB4))
#define SOC_MediaCommon_HEBC_RESERVED1_ADDR(base) ((base) + (0x0AB8))
#define SOC_MediaCommon_HEBC_RESERVED2_ADDR(base) ((base) + (0x0ABC))
#define SOC_MediaCommon_HEBC_RESERVED3_ADDR(base) ((base) + (0x0AC0))
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_ADDR(base) ((base) + (0x0AC4))
#define SOC_MediaCommon_HEBC_HREG_PLD_PTR_LO_1_ADDR(base) ((base) + (0x0258))
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_ADDR(base) ((base) + (0x0AC8))
#define SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_1_ADDR(base) ((base) + (0x0268))
#define SOC_MediaCommon_HEBC_HREG_FORMAT_ADDR(base) ((base) + (0x0ACC))
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_ADDR(base) ((base) + (0x0AD4))
#define SOC_MediaCommon_REG_DEFAULT_ADDR(base) ((base) + (0x0A00))
#define SOC_MediaCommon_V0_SCF_VIDEO_6TAP_COEF_ADDR(base,l) ((base) + (0x1000+0x4*(l)))
#define SOC_MediaCommon_V0_SCF_VIDEO_5TAP_COEF_ADDR(base,m) ((base) + (0x3000+0x4*(m)))
#define SOC_MediaCommon_V0_SCF_VIDEO_4TAP_COEF_ADDR(base,n) ((base) + (0x3800+0x4*(n)))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_tag : 32;
    } reg;
} SOC_MediaCommon_MDC_TAG_UNION;
#endif
#define SOC_MediaCommon_MDC_TAG_mdc_tag_START (0)
#define SOC_MediaCommon_MDC_TAG_mdc_tag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_cpu_force : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_APB_CTL_UNION;
#endif
#define SOC_MediaCommon_APB_CTL_apb_cpu_force_START (0)
#define SOC_MediaCommon_APB_CTL_apb_cpu_force_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_axi_rst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_MDC_AXI_RST_EN_UNION;
#endif
#define SOC_MediaCommon_MDC_AXI_RST_EN_mdc_axi_rst_en_START (0)
#define SOC_MediaCommon_MDC_AXI_RST_EN_mdc_axi_rst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_apb_rst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_MDC_APB_RST_EN_UNION;
#endif
#define SOC_MediaCommon_MDC_APB_RST_EN_mdc_apb_rst_en_START (0)
#define SOC_MediaCommon_MDC_APB_RST_EN_mdc_apb_rst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_core_rst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_MDC_CORE_RST_EN_UNION;
#endif
#define SOC_MediaCommon_MDC_CORE_RST_EN_mdc_core_rst_en_START (0)
#define SOC_MediaCommon_MDC_CORE_RST_EN_mdc_core_rst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu_off_ints : 32;
    } reg;
} SOC_MediaCommon_MCU_OFF_INTS_UNION;
#endif
#define SOC_MediaCommon_MCU_OFF_INTS_mcu_off_ints_START (0)
#define SOC_MediaCommon_MCU_OFF_INTS_mcu_off_ints_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu_off_int_msk : 32;
    } reg;
} SOC_MediaCommon_MCU_OFF_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_MCU_OFF_INT_MSK_mcu_off_int_msk_START (0)
#define SOC_MediaCommon_MCU_OFF_INT_MSK_mcu_off_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu_off_cam_ints : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_MCU_OFF_CAM_INTS_UNION;
#endif
#define SOC_MediaCommon_MCU_OFF_CAM_INTS_mcu_off_cam_ints_START (0)
#define SOC_MediaCommon_MCU_OFF_CAM_INTS_mcu_off_cam_ints_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mcu_off_cam_int_msk : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_MCU_OFF_CAM_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_MCU_OFF_CAM_INT_MSK_mcu_off_cam_int_msk_START (0)
#define SOC_MediaCommon_MCU_OFF_CAM_INT_MSK_mcu_off_cam_int_msk_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r8_ints : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_R8_INTS_UNION;
#endif
#define SOC_MediaCommon_R8_INTS_r8_ints_START (0)
#define SOC_MediaCommon_R8_INTS_r8_ints_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r8_int_msk : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_R8_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_R8_INT_MSK_r8_int_msk_START (0)
#define SOC_MediaCommon_R8_INT_MSK_r8_int_msk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_off_ints : 32;
    } reg;
} SOC_MediaCommon_ACPU_OFF_INTS_UNION;
#endif
#define SOC_MediaCommon_ACPU_OFF_INTS_acpu_off_ints_START (0)
#define SOC_MediaCommon_ACPU_OFF_INTS_acpu_off_ints_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_off_int_msk : 32;
    } reg;
} SOC_MediaCommon_ACPU_OFF_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_ACPU_OFF_INT_MSK_acpu_off_int_msk_START (0)
#define SOC_MediaCommon_ACPU_OFF_INT_MSK_acpu_off_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_off_cam_ints : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_ACPU_OFF_CAM_INTS_UNION;
#endif
#define SOC_MediaCommon_ACPU_OFF_CAM_INTS_acpu_off_cam_ints_START (0)
#define SOC_MediaCommon_ACPU_OFF_CAM_INTS_acpu_off_cam_ints_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_off_cam_int_msk : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_ACPU_OFF_CAM_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_ACPU_OFF_CAM_INT_MSK_acpu_off_cam_int_msk_START (0)
#define SOC_MediaCommon_ACPU_OFF_CAM_INT_MSK_acpu_off_cam_int_msk_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int module_clk_sel : 32;
    } reg;
} SOC_MediaCommon_MODULE_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_MODULE_CLK_SEL_module_clk_sel_START (0)
#define SOC_MediaCommon_MODULE_CLK_SEL_module_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int module_clk_en : 32;
    } reg;
} SOC_MediaCommon_MODULE_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_MODULE_CLK_EN_module_clk_en_START (0)
#define SOC_MediaCommon_MODULE_CLK_EN_module_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb0_core_dbg_sel : 4;
        unsigned int mdc_sum_dbg_sel : 2;
        unsigned int mdc_sum_dbg_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int glb0_axi_dbg_sel : 2;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_MediaCommon_GLB0_DBG_SEL_UNION;
#endif
#define SOC_MediaCommon_GLB0_DBG_SEL_glb0_core_dbg_sel_START (0)
#define SOC_MediaCommon_GLB0_DBG_SEL_glb0_core_dbg_sel_END (3)
#define SOC_MediaCommon_GLB0_DBG_SEL_mdc_sum_dbg_sel_START (4)
#define SOC_MediaCommon_GLB0_DBG_SEL_mdc_sum_dbg_sel_END (5)
#define SOC_MediaCommon_GLB0_DBG_SEL_mdc_sum_dbg_en_START (6)
#define SOC_MediaCommon_GLB0_DBG_SEL_mdc_sum_dbg_en_END (6)
#define SOC_MediaCommon_GLB0_DBG_SEL_glb0_axi_dbg_sel_START (8)
#define SOC_MediaCommon_GLB0_DBG_SEL_glb0_axi_dbg_sel_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_irq_cpu : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_DBG_IRQ_ACPU_UNION;
#endif
#define SOC_MediaCommon_DBG_IRQ_ACPU_dbg_irq_cpu_START (0)
#define SOC_MediaCommon_DBG_IRQ_ACPU_dbg_irq_cpu_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_irq_mcu : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_DBG_IRQ_MCU_UNION;
#endif
#define SOC_MediaCommon_DBG_IRQ_MCU_dbg_irq_mcu_START (0)
#define SOC_MediaCommon_DBG_IRQ_MCU_dbg_irq_mcu_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_glb_dbg : 32;
    } reg;
} SOC_MediaCommon_MDC_GLB_DBG_UNION;
#endif
#define SOC_MediaCommon_MDC_GLB_DBG_mdc_glb_dbg_START (0)
#define SOC_MediaCommon_MDC_GLB_DBG_mdc_glb_dbg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_spram_ctrl : 32;
    } reg;
} SOC_MediaCommon_DSS_SPRAM_CTRL_UNION;
#endif
#define SOC_MediaCommon_DSS_SPRAM_CTRL_dss_spram_ctrl_START (0)
#define SOC_MediaCommon_DSS_SPRAM_CTRL_dss_spram_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_pm_ctrl : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_DSS_PM_CTRL_UNION;
#endif
#define SOC_MediaCommon_DSS_PM_CTRL_dss_pm_ctrl_START (0)
#define SOC_MediaCommon_DSS_PM_CTRL_dss_pm_ctrl_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_dslp_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_GLB_DSLP_EN_UNION;
#endif
#define SOC_MediaCommon_GLB_DSLP_EN_glb_dslp_en_START (0)
#define SOC_MediaCommon_GLB_DSLP_EN_glb_dslp_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_tpram_ctrl : 32;
    } reg;
} SOC_MediaCommon_DSS_TPRAM_CTRL_UNION;
#endif
#define SOC_MediaCommon_DSS_TPRAM_CTRL_dss_tpram_ctrl_START (0)
#define SOC_MediaCommon_DSS_TPRAM_CTRL_dss_tpram_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmm_off_ints : 32;
    } reg;
} SOC_MediaCommon_PMM_OFF_INTS_UNION;
#endif
#define SOC_MediaCommon_PMM_OFF_INTS_pmm_off_ints_START (0)
#define SOC_MediaCommon_PMM_OFF_INTS_pmm_off_ints_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmm_off_int_msk : 32;
    } reg;
} SOC_MediaCommon_PMM_OFF_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_PMM_OFF_INT_MSK_pmm_off_int_msk_START (0)
#define SOC_MediaCommon_PMM_OFF_INT_MSK_pmm_off_int_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmm_off_cam_ints : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PMM_OFF_CAM_INTS_UNION;
#endif
#define SOC_MediaCommon_PMM_OFF_CAM_INTS_pmm_off_cam_ints_START (0)
#define SOC_MediaCommon_PMM_OFF_CAM_INTS_pmm_off_cam_ints_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmm_off_cam_int_msk : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PMM_OFF_CAM_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_PMM_OFF_CAM_INT_MSK_pmm_off_cam_int_msk_START (0)
#define SOC_MediaCommon_PMM_OFF_CAM_INT_MSK_pmm_off_cam_int_msk_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_irq_pmm : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_DBG_IRQ_PMM_UNION;
#endif
#define SOC_MediaCommon_DBG_IRQ_PMM_dbg_irq_pmm_START (0)
#define SOC_MediaCommon_DBG_IRQ_PMM_dbg_irq_pmm_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2ctrl_lbs_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_REG2CTRL_LBS_EN_UNION;
#endif
#define SOC_MediaCommon_REG2CTRL_LBS_EN_reg2ctrl_lbs_en_START (0)
#define SOC_MediaCommon_REG2CTRL_LBS_EN_reg2ctrl_lbs_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2lbs_lbs_frm_len : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_REG2LBS_LBS_FRM_LEN_UNION;
#endif
#define SOC_MediaCommon_REG2LBS_LBS_FRM_LEN_reg2lbs_lbs_frm_len_START (0)
#define SOC_MediaCommon_REG2LBS_LBS_FRM_LEN_reg2lbs_lbs_frm_len_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_bus_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DBG_BUS_MODE_UNION;
#endif
#define SOC_MediaCommon_DBG_BUS_MODE_dbg_bus_mode_START (0)
#define SOC_MediaCommon_DBG_BUS_MODE_dbg_bus_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2lbs_lbs_frm : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_REG2LBS_LBS_FRM_UNION;
#endif
#define SOC_MediaCommon_REG2LBS_LBS_FRM_reg2lbs_lbs_frm_START (0)
#define SOC_MediaCommon_REG2LBS_LBS_FRM_reg2lbs_lbs_frm_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2lbs_lbs_id : 32;
    } reg;
} SOC_MediaCommon_REG2LBS_LBS_ID_UNION;
#endif
#define SOC_MediaCommon_REG2LBS_LBS_ID_reg2lbs_lbs_id_START (0)
#define SOC_MediaCommon_REG2LBS_LBS_ID_reg2lbs_lbs_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2lbs_bus_msk : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_REG2LBS_BUS_MSK_UNION;
#endif
#define SOC_MediaCommon_REG2LBS_BUS_MSK_reg2lbs_bus_msk_START (0)
#define SOC_MediaCommon_REG2LBS_BUS_MSK_reg2lbs_bus_msk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2head_diag_id : 32;
    } reg;
} SOC_MediaCommon_REG2HEAD_DIAG_ID_UNION;
#endif
#define SOC_MediaCommon_REG2HEAD_DIAG_ID_reg2head_diag_id_START (0)
#define SOC_MediaCommon_REG2HEAD_DIAG_ID_reg2head_diag_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2head_hsrv_id : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_REG2HEAD_HSRV_ID_UNION;
#endif
#define SOC_MediaCommon_REG2HEAD_HSRV_ID_reg2head_hsrv_id_START (0)
#define SOC_MediaCommon_REG2HEAD_HSRV_ID_reg2head_hsrv_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2head_lsrv_id : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_REG2HEAD_LSRV_ID_UNION;
#endif
#define SOC_MediaCommon_REG2HEAD_LSRV_ID_reg2head_lsrv_id_START (0)
#define SOC_MediaCommon_REG2HEAD_LSRV_ID_reg2head_lsrv_id_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2head_session_id : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_REG2HEAD_SESSION_ID_UNION;
#endif
#define SOC_MediaCommon_REG2HEAD_SESSION_ID_reg2head_session_id_START (0)
#define SOC_MediaCommon_REG2HEAD_SESSION_ID_reg2head_session_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2head_msg_type : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_REG2HEAD_MSG_TYPE_UNION;
#endif
#define SOC_MediaCommon_REG2HEAD_MSG_TYPE_reg2head_msg_type_START (0)
#define SOC_MediaCommon_REG2HEAD_MSG_TYPE_reg2head_msg_type_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int dbg_bus_base_addr : 28;
    } reg;
} SOC_MediaCommon_DBG_BUS_BASE_ADDR_UNION;
#endif
#define SOC_MediaCommon_DBG_BUS_BASE_ADDR_dbg_bus_base_addr_START (4)
#define SOC_MediaCommon_DBG_BUS_BASE_ADDR_dbg_bus_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int dbg_bus_end_addr : 28;
    } reg;
} SOC_MediaCommon_DBG_BUS_END_ADDR_UNION;
#endif
#define SOC_MediaCommon_DBG_BUS_END_ADDR_dbg_bus_end_addr_START (4)
#define SOC_MediaCommon_DBG_BUS_END_ADDR_dbg_bus_end_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int dbg_ptr_addr : 28;
    } reg;
} SOC_MediaCommon_DBG_PTR_ADDR_UNION;
#endif
#define SOC_MediaCommon_DBG_PTR_ADDR_dbg_ptr_addr_START (4)
#define SOC_MediaCommon_DBG_PTR_ADDR_dbg_ptr_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_bus_timing : 32;
    } reg;
} SOC_MediaCommon_DBG_BUS_TIMING_UNION;
#endif
#define SOC_MediaCommon_DBG_BUS_TIMING_dbg_bus_timing_START (0)
#define SOC_MediaCommon_DBG_BUS_TIMING_dbg_bus_timing_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_bus_ldi_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DBG_BUS_LDI_SEL_UNION;
#endif
#define SOC_MediaCommon_DBG_BUS_LDI_SEL_dbg_bus_ldi_sel_START (0)
#define SOC_MediaCommon_DBG_BUS_LDI_SEL_dbg_bus_ldi_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_bus_end : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DBG_BUS_END_UNION;
#endif
#define SOC_MediaCommon_DBG_BUS_END_dbg_bus_end_START (0)
#define SOC_MediaCommon_DBG_BUS_END_dbg_bus_end_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg2mem_gate_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_REG2MEM_GATE_SEL_UNION;
#endif
#define SOC_MediaCommon_REG2MEM_GATE_SEL_reg2mem_gate_sel_START (0)
#define SOC_MediaCommon_REG2MEM_GATE_SEL_reg2mem_gate_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sp_mem_ctrl0_log : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_SP_MEM_CTRL0_LOG_UNION;
#endif
#define SOC_MediaCommon_SP_MEM_CTRL0_LOG_sp_mem_ctrl0_log_START (0)
#define SOC_MediaCommon_SP_MEM_CTRL0_LOG_sp_mem_ctrl0_log_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_mem_ctrl0 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_TP_MEM_CTRL0_UNION;
#endif
#define SOC_MediaCommon_TP_MEM_CTRL0_tp_mem_ctrl0_START (0)
#define SOC_MediaCommon_TP_MEM_CTRL0_tp_mem_ctrl0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_bus_timing_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DBG_BUS_TIMING_SEL_UNION;
#endif
#define SOC_MediaCommon_DBG_BUS_TIMING_SEL_dbg_bus_timing_sel_START (0)
#define SOC_MediaCommon_DBG_BUS_TIMING_SEL_dbg_bus_timing_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_dbg_wptr : 32;
    } reg;
} SOC_MediaCommon_MDC_DBG_WPTR_UNION;
#endif
#define SOC_MediaCommon_MDC_DBG_WPTR_mdc_dbg_wptr_START (0)
#define SOC_MediaCommon_MDC_DBG_WPTR_mdc_dbg_wptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_mctl_ints : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_DBG_MCTL_INTS_UNION;
#endif
#define SOC_MediaCommon_DBG_MCTL_INTS_dbg_mctl_ints_START (0)
#define SOC_MediaCommon_DBG_MCTL_INTS_dbg_mctl_ints_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_mctl_int_msk : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_DBG_MCTL_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_DBG_MCTL_INT_MSK_dbg_mctl_int_msk_START (0)
#define SOC_MediaCommon_DBG_MCTL_INT_MSK_dbg_mctl_int_msk_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_wch1_ints : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_DBG_WCH1_INTS_UNION;
#endif
#define SOC_MediaCommon_DBG_WCH1_INTS_dbg_wch1_ints_START (0)
#define SOC_MediaCommon_DBG_WCH1_INTS_dbg_wch1_ints_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_wch1_int_msk : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_DBG_WCH1_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_DBG_WCH1_INT_MSK_dbg_wch1_int_msk_START (0)
#define SOC_MediaCommon_DBG_WCH1_INT_MSK_dbg_wch1_int_msk_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_rch_ints : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DBG_RCH_INTS_UNION;
#endif
#define SOC_MediaCommon_DBG_RCH_INTS_dbg_rch_ints_START (0)
#define SOC_MediaCommon_DBG_RCH_INTS_dbg_rch_ints_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_rch_v0_int_msk : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DBG_RCH_V0_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_DBG_RCH_V0_INT_MSK_dbg_rch_v0_int_msk_START (0)
#define SOC_MediaCommon_DBG_RCH_V0_INT_MSK_dbg_rch_v0_int_msk_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_glb_ints : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_MDC_GLB_INTS_UNION;
#endif
#define SOC_MediaCommon_MDC_GLB_INTS_mdc_glb_ints_START (0)
#define SOC_MediaCommon_MDC_GLB_INTS_mdc_glb_ints_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mdc_glb_int_msk : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_MDC_GLB_INT_MSK_UNION;
#endif
#define SOC_MediaCommon_MDC_GLB_INT_MSK_mdc_glb_int_msk_START (0)
#define SOC_MediaCommon_MDC_GLB_INT_MSK_mdc_glb_int_msk_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_pending_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_PENDING_CLR_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_PENDING_CLR_ch_pending_clr_START (0)
#define SOC_MediaCommon_CMDLIST_CH_PENDING_CLR_ch_pending_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_enable : 1;
        unsigned int ch_auto_single : 1;
        unsigned int ch_start_sel : 3;
        unsigned int ch_pause : 1;
        unsigned int ch_scene_sel : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_CTRL_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_enable_START (0)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_enable_END (0)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_auto_single_START (1)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_auto_single_END (1)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_start_sel_START (2)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_start_sel_END (4)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_pause_START (5)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_pause_END (5)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_scene_sel_START (6)
#define SOC_MediaCommon_CMDLIST_CH_CTRL_ch_scene_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_ctl_fsm : 4;
        unsigned int reserved : 4;
        unsigned int ch_dma_fsm : 2;
        unsigned int ch_idle : 1;
        unsigned int oa_idle : 1;
        unsigned int ch_cmd_done_id : 10;
        unsigned int ch_cmd_id : 10;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_STATUS_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_ctl_fsm_START (0)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_ctl_fsm_END (3)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_dma_fsm_START (8)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_dma_fsm_END (9)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_idle_START (10)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_idle_END (10)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_oa_idle_START (11)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_oa_idle_END (11)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_cmd_done_id_START (12)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_cmd_done_id_END (21)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_cmd_id_START (22)
#define SOC_MediaCommon_CMDLIST_CH_STATUS_ch_cmd_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int ch_start_addr : 28;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_STAAD_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_STAAD_ch_start_addr_START (4)
#define SOC_MediaCommon_CMDLIST_CH_STAAD_ch_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_cnt : 4;
        unsigned int ch_curr_addr : 28;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_CURAD_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_CURAD_ch_cnt_START (0)
#define SOC_MediaCommon_CMDLIST_CH_CURAD_ch_cnt_END (3)
#define SOC_MediaCommon_CMDLIST_CH_CURAD_ch_curr_addr_START (4)
#define SOC_MediaCommon_CMDLIST_CH_CURAD_ch_curr_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_onedone_inte : 1;
        unsigned int ch_alldone_inte : 1;
        unsigned int ch_axi_err_inte : 1;
        unsigned int ch_pending_inte : 1;
        unsigned int ch_start_inte : 1;
        unsigned int ch_badcmd_inte : 1;
        unsigned int ch_timeout_inte : 1;
        unsigned int ch_taskdone_inte : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_INTE_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_onedone_inte_START (0)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_onedone_inte_END (0)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_alldone_inte_START (1)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_alldone_inte_END (1)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_axi_err_inte_START (2)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_axi_err_inte_END (2)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_pending_inte_START (3)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_pending_inte_END (3)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_start_inte_START (4)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_start_inte_END (4)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_badcmd_inte_START (5)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_badcmd_inte_END (5)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_timeout_inte_START (6)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_timeout_inte_END (6)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_taskdone_inte_START (7)
#define SOC_MediaCommon_CMDLIST_CH_INTE_ch_taskdone_inte_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_onedone_intc : 1;
        unsigned int ch_alldone_intc : 1;
        unsigned int ch_axi_err_intc : 1;
        unsigned int ch_pending_intc : 1;
        unsigned int ch_start_intc : 1;
        unsigned int ch_badcmd_intc : 1;
        unsigned int ch_timeout_intc : 1;
        unsigned int ch_taskdone_intc : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_INTC_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_onedone_intc_START (0)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_onedone_intc_END (0)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_alldone_intc_START (1)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_alldone_intc_END (1)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_axi_err_intc_START (2)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_axi_err_intc_END (2)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_pending_intc_START (3)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_pending_intc_END (3)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_start_intc_START (4)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_start_intc_END (4)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_badcmd_intc_START (5)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_badcmd_intc_END (5)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_timeout_intc_START (6)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_timeout_intc_END (6)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_taskdone_intc_START (7)
#define SOC_MediaCommon_CMDLIST_CH_INTC_ch_taskdone_intc_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_onedone_ints : 1;
        unsigned int ch_alldone_ints : 1;
        unsigned int ch_axi_err_ints : 1;
        unsigned int ch_pending_ints : 1;
        unsigned int ch_start_ints : 1;
        unsigned int ch_badcmd_ints : 1;
        unsigned int ch_timeout_ints : 1;
        unsigned int ch_taskdone_ints : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_INTS_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_onedone_ints_START (0)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_onedone_ints_END (0)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_alldone_ints_START (1)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_alldone_ints_END (1)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_axi_err_ints_START (2)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_axi_err_ints_END (2)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_pending_ints_START (3)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_pending_ints_END (3)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_start_ints_START (4)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_start_ints_END (4)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_badcmd_ints_START (5)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_badcmd_ints_END (5)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_timeout_ints_START (6)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_timeout_ints_END (6)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_taskdone_ints_START (7)
#define SOC_MediaCommon_CMDLIST_CH_INTS_ch_taskdone_ints_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_dbg0 : 1;
        unsigned int cmd_dbg1 : 1;
        unsigned int cmd_dbg2 : 1;
        unsigned int cmd_dbg3 : 1;
        unsigned int cmd_dbg4 : 1;
        unsigned int cmd_dbg5 : 1;
        unsigned int cmd_dbg6 : 1;
        unsigned int cmd_dbg7 : 1;
        unsigned int cmd_dbg8 : 1;
        unsigned int cmd_dbg9 : 1;
        unsigned int cmd_dbg10 : 1;
        unsigned int cmd_dbg11 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_CMDLIST_CH_DBG_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg0_START (0)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg0_END (0)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg1_START (1)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg1_END (1)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg2_START (2)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg2_END (2)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg3_START (3)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg3_END (3)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg4_START (4)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg4_END (4)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg5_START (5)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg5_END (5)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg6_START (6)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg6_END (6)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg7_START (7)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg7_END (7)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg8_START (8)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg8_END (8)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg9_START (9)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg9_END (9)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg10_START (10)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg10_END (10)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg11_START (11)
#define SOC_MediaCommon_CMDLIST_CH_DBG_cmd_dbg11_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_axi_dbg : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_MediaCommon_CMDLIST_DBG_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_DBG_cmd_axi_dbg_START (0)
#define SOC_MediaCommon_CMDLIST_DBG_cmd_axi_dbg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf_dbg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_BUF_DBG_EN_UNION;
#endif
#define SOC_MediaCommon_BUF_DBG_EN_buf_dbg_en_START (0)
#define SOC_MediaCommon_BUF_DBG_EN_buf_dbg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf_dbg_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_BUF_DBG_CNT_CLR_UNION;
#endif
#define SOC_MediaCommon_BUF_DBG_CNT_CLR_buf_dbg_cnt_clr_START (0)
#define SOC_MediaCommon_BUF_DBG_CNT_CLR_buf_dbg_cnt_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf_dbg_cnt_th : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_BUF_DBG_CNT_UNION;
#endif
#define SOC_MediaCommon_BUF_DBG_CNT_buf_dbg_cnt_th_START (0)
#define SOC_MediaCommon_BUF_DBG_CNT_buf_dbg_cnt_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timeout_th : 32;
    } reg;
} SOC_MediaCommon_CMDLIST_TIMEOUT_TH_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_TIMEOUT_TH_timeout_th_START (0)
#define SOC_MediaCommon_CMDLIST_TIMEOUT_TH_timeout_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_START_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_START_start_START (0)
#define SOC_MediaCommon_CMDLIST_START_start_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mask_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_ADDR_MASK_EN_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_EN_addr_mask_en_START (0)
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_EN_addr_mask_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mask_dis : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_ADDR_MASK_DIS_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_DIS_addr_mask_dis_START (0)
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_DIS_addr_mask_dis_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mask_status : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_ADDR_MASK_STATUS_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_STATUS_addr_mask_status_START (0)
#define SOC_MediaCommon_CMDLIST_ADDR_MASK_STATUS_addr_mask_status_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_continue : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_TASK_CONTINUE_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_TASK_CONTINUE_task_continue_START (0)
#define SOC_MediaCommon_CMDLIST_TASK_CONTINUE_task_continue_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_status : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_TASK_STATUS_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_TASK_STATUS_task_status_START (0)
#define SOC_MediaCommon_CMDLIST_TASK_STATUS_task_status_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_mid : 4;
        unsigned int axi_qos : 2;
        unsigned int axi_mainpress : 2;
        unsigned int axi_outstd_depth : 4;
        unsigned int buf0_outstd_depth : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 8;
    } reg;
} SOC_MediaCommon_CMDLIST_CTRL_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_CTRL_axi_mid_START (0)
#define SOC_MediaCommon_CMDLIST_CTRL_axi_mid_END (3)
#define SOC_MediaCommon_CMDLIST_CTRL_axi_qos_START (4)
#define SOC_MediaCommon_CMDLIST_CTRL_axi_qos_END (5)
#define SOC_MediaCommon_CMDLIST_CTRL_axi_mainpress_START (6)
#define SOC_MediaCommon_CMDLIST_CTRL_axi_mainpress_END (7)
#define SOC_MediaCommon_CMDLIST_CTRL_axi_outstd_depth_START (8)
#define SOC_MediaCommon_CMDLIST_CTRL_axi_outstd_depth_END (11)
#define SOC_MediaCommon_CMDLIST_CTRL_buf0_outstd_depth_START (12)
#define SOC_MediaCommon_CMDLIST_CTRL_buf0_outstd_depth_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_secu : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_SECU_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_SECU_ch_secu_START (0)
#define SOC_MediaCommon_CMDLIST_SECU_ch_secu_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_ints : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_INTS_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_INTS_ch_ints_START (0)
#define SOC_MediaCommon_CMDLIST_INTS_ch_ints_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_swreset : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CMDLIST_SWRST_UNION;
#endif
#define SOC_MediaCommon_CMDLIST_SWRST_ch_swreset_START (0)
#define SOC_MediaCommon_CMDLIST_SWRST_ch_swreset_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_CMD_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_CMD_MEM_CTRL_cmd_mem_ctrl_START (0)
#define SOC_MediaCommon_CMD_MEM_CTRL_cmd_mem_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_clk_sel : 32;
    } reg;
} SOC_MediaCommon_CMD_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_CMD_CLK_SEL_cmd_clk_sel_START (0)
#define SOC_MediaCommon_CMD_CLK_SEL_cmd_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_clk_en : 32;
    } reg;
} SOC_MediaCommon_CMD_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_CMD_CLK_EN_cmd_clk_en_START (0)
#define SOC_MediaCommon_CMD_CLK_EN_cmd_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_0 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_0 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_0_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_0_axi_sel_0_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_0_axi_sel_0_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_0_credit_mode_0_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_0_credit_mode_0_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_0_max_cont_0_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_0_max_cont_0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_0 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_0 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_0 : 9;
        unsigned int credit_lth_0 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_0_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_0_credit_en_0_START (0)
#define SOC_MediaCommon_AIF_CH_HS_0_credit_en_0_END (0)
#define SOC_MediaCommon_AIF_CH_HS_0_credit_step_0_START (4)
#define SOC_MediaCommon_AIF_CH_HS_0_credit_step_0_END (10)
#define SOC_MediaCommon_AIF_CH_HS_0_credit_uth_0_START (12)
#define SOC_MediaCommon_AIF_CH_HS_0_credit_uth_0_END (20)
#define SOC_MediaCommon_AIF_CH_HS_0_credit_lth_0_START (21)
#define SOC_MediaCommon_AIF_CH_HS_0_credit_lth_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_0 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_0 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_0 : 9;
        unsigned int credit_lth_lower_0 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_0_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_0_credit_en_lower_0_START (0)
#define SOC_MediaCommon_AIF_CH_LS_0_credit_en_lower_0_END (0)
#define SOC_MediaCommon_AIF_CH_LS_0_credit_step_lower_0_START (4)
#define SOC_MediaCommon_AIF_CH_LS_0_credit_step_lower_0_END (10)
#define SOC_MediaCommon_AIF_CH_LS_0_credit_uth_lower_0_START (12)
#define SOC_MediaCommon_AIF_CH_LS_0_credit_uth_lower_0_END (20)
#define SOC_MediaCommon_AIF_CH_LS_0_credit_lth_lower_0_START (21)
#define SOC_MediaCommon_AIF_CH_LS_0_credit_lth_lower_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_1 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_1 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_1_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_1_axi_sel_1_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_1_axi_sel_1_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_1_credit_mode_1_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_1_credit_mode_1_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_1_max_cont_1_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_1_max_cont_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_1 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_1 : 9;
        unsigned int credit_lth_1 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_1_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_1_credit_en_1_START (0)
#define SOC_MediaCommon_AIF_CH_HS_1_credit_en_1_END (0)
#define SOC_MediaCommon_AIF_CH_HS_1_credit_step_1_START (4)
#define SOC_MediaCommon_AIF_CH_HS_1_credit_step_1_END (10)
#define SOC_MediaCommon_AIF_CH_HS_1_credit_uth_1_START (12)
#define SOC_MediaCommon_AIF_CH_HS_1_credit_uth_1_END (20)
#define SOC_MediaCommon_AIF_CH_HS_1_credit_lth_1_START (21)
#define SOC_MediaCommon_AIF_CH_HS_1_credit_lth_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_1 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_1 : 9;
        unsigned int credit_lth_lower_1 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_1_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_1_credit_en_lower_1_START (0)
#define SOC_MediaCommon_AIF_CH_LS_1_credit_en_lower_1_END (0)
#define SOC_MediaCommon_AIF_CH_LS_1_credit_step_lower_1_START (4)
#define SOC_MediaCommon_AIF_CH_LS_1_credit_step_lower_1_END (10)
#define SOC_MediaCommon_AIF_CH_LS_1_credit_uth_lower_1_START (12)
#define SOC_MediaCommon_AIF_CH_LS_1_credit_uth_lower_1_END (20)
#define SOC_MediaCommon_AIF_CH_LS_1_credit_lth_lower_1_START (21)
#define SOC_MediaCommon_AIF_CH_LS_1_credit_lth_lower_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_2 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_2 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_2 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_2_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_2_axi_sel_2_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_2_axi_sel_2_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_2_credit_mode_2_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_2_credit_mode_2_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_2_max_cont_2_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_2_max_cont_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_2 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_2 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_2 : 9;
        unsigned int credit_lth_2 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_2_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_2_credit_en_2_START (0)
#define SOC_MediaCommon_AIF_CH_HS_2_credit_en_2_END (0)
#define SOC_MediaCommon_AIF_CH_HS_2_credit_step_2_START (4)
#define SOC_MediaCommon_AIF_CH_HS_2_credit_step_2_END (10)
#define SOC_MediaCommon_AIF_CH_HS_2_credit_uth_2_START (12)
#define SOC_MediaCommon_AIF_CH_HS_2_credit_uth_2_END (20)
#define SOC_MediaCommon_AIF_CH_HS_2_credit_lth_2_START (21)
#define SOC_MediaCommon_AIF_CH_HS_2_credit_lth_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_2 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_2 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_2 : 9;
        unsigned int credit_lth_lower_2 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_2_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_2_credit_en_lower_2_START (0)
#define SOC_MediaCommon_AIF_CH_LS_2_credit_en_lower_2_END (0)
#define SOC_MediaCommon_AIF_CH_LS_2_credit_step_lower_2_START (4)
#define SOC_MediaCommon_AIF_CH_LS_2_credit_step_lower_2_END (10)
#define SOC_MediaCommon_AIF_CH_LS_2_credit_uth_lower_2_START (12)
#define SOC_MediaCommon_AIF_CH_LS_2_credit_uth_lower_2_END (20)
#define SOC_MediaCommon_AIF_CH_LS_2_credit_lth_lower_2_START (21)
#define SOC_MediaCommon_AIF_CH_LS_2_credit_lth_lower_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_3 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_3 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_3 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_3_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_3_axi_sel_3_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_3_axi_sel_3_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_3_credit_mode_3_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_3_credit_mode_3_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_3_max_cont_3_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_3_max_cont_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_3 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_3 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_3 : 9;
        unsigned int credit_lth_3 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_3_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_3_credit_en_3_START (0)
#define SOC_MediaCommon_AIF_CH_HS_3_credit_en_3_END (0)
#define SOC_MediaCommon_AIF_CH_HS_3_credit_step_3_START (4)
#define SOC_MediaCommon_AIF_CH_HS_3_credit_step_3_END (10)
#define SOC_MediaCommon_AIF_CH_HS_3_credit_uth_3_START (12)
#define SOC_MediaCommon_AIF_CH_HS_3_credit_uth_3_END (20)
#define SOC_MediaCommon_AIF_CH_HS_3_credit_lth_3_START (21)
#define SOC_MediaCommon_AIF_CH_HS_3_credit_lth_3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_3 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_3 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_3 : 9;
        unsigned int credit_lth_lower_3 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_3_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_3_credit_en_lower_3_START (0)
#define SOC_MediaCommon_AIF_CH_LS_3_credit_en_lower_3_END (0)
#define SOC_MediaCommon_AIF_CH_LS_3_credit_step_lower_3_START (4)
#define SOC_MediaCommon_AIF_CH_LS_3_credit_step_lower_3_END (10)
#define SOC_MediaCommon_AIF_CH_LS_3_credit_uth_lower_3_START (12)
#define SOC_MediaCommon_AIF_CH_LS_3_credit_uth_lower_3_END (20)
#define SOC_MediaCommon_AIF_CH_LS_3_credit_lth_lower_3_START (21)
#define SOC_MediaCommon_AIF_CH_LS_3_credit_lth_lower_3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_4 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_4 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_4 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_4_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_4_axi_sel_4_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_4_axi_sel_4_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_4_credit_mode_4_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_4_credit_mode_4_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_4_max_cont_4_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_4_max_cont_4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_4 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_4 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_4 : 9;
        unsigned int credit_lth_4 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_4_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_4_credit_en_4_START (0)
#define SOC_MediaCommon_AIF_CH_HS_4_credit_en_4_END (0)
#define SOC_MediaCommon_AIF_CH_HS_4_credit_step_4_START (4)
#define SOC_MediaCommon_AIF_CH_HS_4_credit_step_4_END (10)
#define SOC_MediaCommon_AIF_CH_HS_4_credit_uth_4_START (12)
#define SOC_MediaCommon_AIF_CH_HS_4_credit_uth_4_END (20)
#define SOC_MediaCommon_AIF_CH_HS_4_credit_lth_4_START (21)
#define SOC_MediaCommon_AIF_CH_HS_4_credit_lth_4_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_4 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_4 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_4 : 9;
        unsigned int credit_lth_lower_4 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_4_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_4_credit_en_lower_4_START (0)
#define SOC_MediaCommon_AIF_CH_LS_4_credit_en_lower_4_END (0)
#define SOC_MediaCommon_AIF_CH_LS_4_credit_step_lower_4_START (4)
#define SOC_MediaCommon_AIF_CH_LS_4_credit_step_lower_4_END (10)
#define SOC_MediaCommon_AIF_CH_LS_4_credit_uth_lower_4_START (12)
#define SOC_MediaCommon_AIF_CH_LS_4_credit_uth_lower_4_END (20)
#define SOC_MediaCommon_AIF_CH_LS_4_credit_lth_lower_4_START (21)
#define SOC_MediaCommon_AIF_CH_LS_4_credit_lth_lower_4_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_5 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_5 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_5 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_5_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_5_axi_sel_5_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_5_axi_sel_5_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_5_credit_mode_5_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_5_credit_mode_5_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_5_max_cont_5_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_5_max_cont_5_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_5 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_5 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_5 : 9;
        unsigned int credit_lth_5 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_5_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_5_credit_en_5_START (0)
#define SOC_MediaCommon_AIF_CH_HS_5_credit_en_5_END (0)
#define SOC_MediaCommon_AIF_CH_HS_5_credit_step_5_START (4)
#define SOC_MediaCommon_AIF_CH_HS_5_credit_step_5_END (10)
#define SOC_MediaCommon_AIF_CH_HS_5_credit_uth_5_START (12)
#define SOC_MediaCommon_AIF_CH_HS_5_credit_uth_5_END (20)
#define SOC_MediaCommon_AIF_CH_HS_5_credit_lth_5_START (21)
#define SOC_MediaCommon_AIF_CH_HS_5_credit_lth_5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_5 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_5 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_5 : 9;
        unsigned int credit_lth_lower_5 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_5_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_5_credit_en_lower_5_START (0)
#define SOC_MediaCommon_AIF_CH_LS_5_credit_en_lower_5_END (0)
#define SOC_MediaCommon_AIF_CH_LS_5_credit_step_lower_5_START (4)
#define SOC_MediaCommon_AIF_CH_LS_5_credit_step_lower_5_END (10)
#define SOC_MediaCommon_AIF_CH_LS_5_credit_uth_lower_5_START (12)
#define SOC_MediaCommon_AIF_CH_LS_5_credit_uth_lower_5_END (20)
#define SOC_MediaCommon_AIF_CH_LS_5_credit_lth_lower_5_START (21)
#define SOC_MediaCommon_AIF_CH_LS_5_credit_lth_lower_5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_6 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_6 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_6 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_6_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_6_axi_sel_6_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_6_axi_sel_6_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_6_credit_mode_6_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_6_credit_mode_6_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_6_max_cont_6_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_6_max_cont_6_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_6 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_6 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_6 : 9;
        unsigned int credit_lth_6 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_6_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_6_credit_en_6_START (0)
#define SOC_MediaCommon_AIF_CH_HS_6_credit_en_6_END (0)
#define SOC_MediaCommon_AIF_CH_HS_6_credit_step_6_START (4)
#define SOC_MediaCommon_AIF_CH_HS_6_credit_step_6_END (10)
#define SOC_MediaCommon_AIF_CH_HS_6_credit_uth_6_START (12)
#define SOC_MediaCommon_AIF_CH_HS_6_credit_uth_6_END (20)
#define SOC_MediaCommon_AIF_CH_HS_6_credit_lth_6_START (21)
#define SOC_MediaCommon_AIF_CH_HS_6_credit_lth_6_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_6 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_6 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_6 : 9;
        unsigned int credit_lth_lower_6 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_6_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_6_credit_en_lower_6_START (0)
#define SOC_MediaCommon_AIF_CH_LS_6_credit_en_lower_6_END (0)
#define SOC_MediaCommon_AIF_CH_LS_6_credit_step_lower_6_START (4)
#define SOC_MediaCommon_AIF_CH_LS_6_credit_step_lower_6_END (10)
#define SOC_MediaCommon_AIF_CH_LS_6_credit_uth_lower_6_START (12)
#define SOC_MediaCommon_AIF_CH_LS_6_credit_uth_lower_6_END (20)
#define SOC_MediaCommon_AIF_CH_LS_6_credit_lth_lower_6_START (21)
#define SOC_MediaCommon_AIF_CH_LS_6_credit_lth_lower_6_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_7 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_7 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_7 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_7_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_7_axi_sel_7_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_7_axi_sel_7_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_7_credit_mode_7_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_7_credit_mode_7_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_7_max_cont_7_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_7_max_cont_7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_7 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_7 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_7 : 9;
        unsigned int credit_lth_7 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_7_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_7_credit_en_7_START (0)
#define SOC_MediaCommon_AIF_CH_HS_7_credit_en_7_END (0)
#define SOC_MediaCommon_AIF_CH_HS_7_credit_step_7_START (4)
#define SOC_MediaCommon_AIF_CH_HS_7_credit_step_7_END (10)
#define SOC_MediaCommon_AIF_CH_HS_7_credit_uth_7_START (12)
#define SOC_MediaCommon_AIF_CH_HS_7_credit_uth_7_END (20)
#define SOC_MediaCommon_AIF_CH_HS_7_credit_lth_7_START (21)
#define SOC_MediaCommon_AIF_CH_HS_7_credit_lth_7_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_7 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_7 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_7 : 9;
        unsigned int credit_lth_lower_7 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_7_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_7_credit_en_lower_7_START (0)
#define SOC_MediaCommon_AIF_CH_LS_7_credit_en_lower_7_END (0)
#define SOC_MediaCommon_AIF_CH_LS_7_credit_step_lower_7_START (4)
#define SOC_MediaCommon_AIF_CH_LS_7_credit_step_lower_7_END (10)
#define SOC_MediaCommon_AIF_CH_LS_7_credit_uth_lower_7_START (12)
#define SOC_MediaCommon_AIF_CH_LS_7_credit_uth_lower_7_END (20)
#define SOC_MediaCommon_AIF_CH_LS_7_credit_lth_lower_7_START (21)
#define SOC_MediaCommon_AIF_CH_LS_7_credit_lth_lower_7_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_8 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_8 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_8 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_8_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_8_axi_sel_8_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_8_axi_sel_8_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_8_credit_mode_8_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_8_credit_mode_8_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_8_max_cont_8_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_8_max_cont_8_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_8 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_8 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_8 : 9;
        unsigned int credit_lth_8 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_8_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_8_credit_en_8_START (0)
#define SOC_MediaCommon_AIF_CH_HS_8_credit_en_8_END (0)
#define SOC_MediaCommon_AIF_CH_HS_8_credit_step_8_START (4)
#define SOC_MediaCommon_AIF_CH_HS_8_credit_step_8_END (10)
#define SOC_MediaCommon_AIF_CH_HS_8_credit_uth_8_START (12)
#define SOC_MediaCommon_AIF_CH_HS_8_credit_uth_8_END (20)
#define SOC_MediaCommon_AIF_CH_HS_8_credit_lth_8_START (21)
#define SOC_MediaCommon_AIF_CH_HS_8_credit_lth_8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_8 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_8 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_8 : 9;
        unsigned int credit_lth_lower_8 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_8_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_8_credit_en_lower_8_START (0)
#define SOC_MediaCommon_AIF_CH_LS_8_credit_en_lower_8_END (0)
#define SOC_MediaCommon_AIF_CH_LS_8_credit_step_lower_8_START (4)
#define SOC_MediaCommon_AIF_CH_LS_8_credit_step_lower_8_END (10)
#define SOC_MediaCommon_AIF_CH_LS_8_credit_uth_lower_8_START (12)
#define SOC_MediaCommon_AIF_CH_LS_8_credit_uth_lower_8_END (20)
#define SOC_MediaCommon_AIF_CH_LS_8_credit_lth_lower_8_START (21)
#define SOC_MediaCommon_AIF_CH_LS_8_credit_lth_lower_8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_9 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_9 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_9 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_9_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_9_axi_sel_9_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_9_axi_sel_9_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_9_credit_mode_9_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_9_credit_mode_9_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_9_max_cont_9_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_9_max_cont_9_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_9 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_9 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_9 : 9;
        unsigned int credit_lth_9 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_9_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_9_credit_en_9_START (0)
#define SOC_MediaCommon_AIF_CH_HS_9_credit_en_9_END (0)
#define SOC_MediaCommon_AIF_CH_HS_9_credit_step_9_START (4)
#define SOC_MediaCommon_AIF_CH_HS_9_credit_step_9_END (10)
#define SOC_MediaCommon_AIF_CH_HS_9_credit_uth_9_START (12)
#define SOC_MediaCommon_AIF_CH_HS_9_credit_uth_9_END (20)
#define SOC_MediaCommon_AIF_CH_HS_9_credit_lth_9_START (21)
#define SOC_MediaCommon_AIF_CH_HS_9_credit_lth_9_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_9 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_9 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_9 : 9;
        unsigned int credit_lth_lower_9 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_9_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_9_credit_en_lower_9_START (0)
#define SOC_MediaCommon_AIF_CH_LS_9_credit_en_lower_9_END (0)
#define SOC_MediaCommon_AIF_CH_LS_9_credit_step_lower_9_START (4)
#define SOC_MediaCommon_AIF_CH_LS_9_credit_step_lower_9_END (10)
#define SOC_MediaCommon_AIF_CH_LS_9_credit_uth_lower_9_START (12)
#define SOC_MediaCommon_AIF_CH_LS_9_credit_uth_lower_9_END (20)
#define SOC_MediaCommon_AIF_CH_LS_9_credit_lth_lower_9_START (21)
#define SOC_MediaCommon_AIF_CH_LS_9_credit_lth_lower_9_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_10 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_10 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_10 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_10_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_10_axi_sel_10_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_10_axi_sel_10_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_10_credit_mode_10_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_10_credit_mode_10_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_10_max_cont_10_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_10_max_cont_10_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_10 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_10 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_10 : 9;
        unsigned int credit_lth_10 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_10_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_10_credit_en_10_START (0)
#define SOC_MediaCommon_AIF_CH_HS_10_credit_en_10_END (0)
#define SOC_MediaCommon_AIF_CH_HS_10_credit_step_10_START (4)
#define SOC_MediaCommon_AIF_CH_HS_10_credit_step_10_END (10)
#define SOC_MediaCommon_AIF_CH_HS_10_credit_uth_10_START (12)
#define SOC_MediaCommon_AIF_CH_HS_10_credit_uth_10_END (20)
#define SOC_MediaCommon_AIF_CH_HS_10_credit_lth_10_START (21)
#define SOC_MediaCommon_AIF_CH_HS_10_credit_lth_10_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_10 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_10 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_10 : 9;
        unsigned int credit_lth_lower_10 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_10_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_10_credit_en_lower_10_START (0)
#define SOC_MediaCommon_AIF_CH_LS_10_credit_en_lower_10_END (0)
#define SOC_MediaCommon_AIF_CH_LS_10_credit_step_lower_10_START (4)
#define SOC_MediaCommon_AIF_CH_LS_10_credit_step_lower_10_END (10)
#define SOC_MediaCommon_AIF_CH_LS_10_credit_uth_lower_10_START (12)
#define SOC_MediaCommon_AIF_CH_LS_10_credit_uth_lower_10_END (20)
#define SOC_MediaCommon_AIF_CH_LS_10_credit_lth_lower_10_START (21)
#define SOC_MediaCommon_AIF_CH_LS_10_credit_lth_lower_10_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_11 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_11 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_11 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_11_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_11_axi_sel_11_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_11_axi_sel_11_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_11_credit_mode_11_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_11_credit_mode_11_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_11_max_cont_11_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_11_max_cont_11_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_11 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_11 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_11 : 9;
        unsigned int credit_lth_11 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_11_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_11_credit_en_11_START (0)
#define SOC_MediaCommon_AIF_CH_HS_11_credit_en_11_END (0)
#define SOC_MediaCommon_AIF_CH_HS_11_credit_step_11_START (4)
#define SOC_MediaCommon_AIF_CH_HS_11_credit_step_11_END (10)
#define SOC_MediaCommon_AIF_CH_HS_11_credit_uth_11_START (12)
#define SOC_MediaCommon_AIF_CH_HS_11_credit_uth_11_END (20)
#define SOC_MediaCommon_AIF_CH_HS_11_credit_lth_11_START (21)
#define SOC_MediaCommon_AIF_CH_HS_11_credit_lth_11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_11 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_11 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_11 : 9;
        unsigned int credit_lth_lower_11 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_11_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_11_credit_en_lower_11_START (0)
#define SOC_MediaCommon_AIF_CH_LS_11_credit_en_lower_11_END (0)
#define SOC_MediaCommon_AIF_CH_LS_11_credit_step_lower_11_START (4)
#define SOC_MediaCommon_AIF_CH_LS_11_credit_step_lower_11_END (10)
#define SOC_MediaCommon_AIF_CH_LS_11_credit_uth_lower_11_START (12)
#define SOC_MediaCommon_AIF_CH_LS_11_credit_uth_lower_11_END (20)
#define SOC_MediaCommon_AIF_CH_LS_11_credit_lth_lower_11_START (21)
#define SOC_MediaCommon_AIF_CH_LS_11_credit_lth_lower_11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_12 : 1;
        unsigned int reserved_0 : 7;
        unsigned int credit_mode_12 : 3;
        unsigned int reserved_1 : 1;
        unsigned int max_cont_12 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_12_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_12_axi_sel_12_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_12_axi_sel_12_END (0)
#define SOC_MediaCommon_AIF_CH_CTL_12_credit_mode_12_START (8)
#define SOC_MediaCommon_AIF_CH_CTL_12_credit_mode_12_END (10)
#define SOC_MediaCommon_AIF_CH_CTL_12_max_cont_12_START (12)
#define SOC_MediaCommon_AIF_CH_CTL_12_max_cont_12_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_12 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_12 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_12 : 9;
        unsigned int credit_lth_12 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_HS_12_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_HS_12_credit_en_12_START (0)
#define SOC_MediaCommon_AIF_CH_HS_12_credit_en_12_END (0)
#define SOC_MediaCommon_AIF_CH_HS_12_credit_step_12_START (4)
#define SOC_MediaCommon_AIF_CH_HS_12_credit_step_12_END (10)
#define SOC_MediaCommon_AIF_CH_HS_12_credit_uth_12_START (12)
#define SOC_MediaCommon_AIF_CH_HS_12_credit_uth_12_END (20)
#define SOC_MediaCommon_AIF_CH_HS_12_credit_lth_12_START (21)
#define SOC_MediaCommon_AIF_CH_HS_12_credit_lth_12_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int credit_en_lower_12 : 1;
        unsigned int reserved_0 : 3;
        unsigned int credit_step_lower_12 : 7;
        unsigned int reserved_1 : 1;
        unsigned int credit_uth_lower_12 : 9;
        unsigned int credit_lth_lower_12 : 9;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MediaCommon_AIF_CH_LS_12_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_LS_12_credit_en_lower_12_START (0)
#define SOC_MediaCommon_AIF_CH_LS_12_credit_en_lower_12_END (0)
#define SOC_MediaCommon_AIF_CH_LS_12_credit_step_lower_12_START (4)
#define SOC_MediaCommon_AIF_CH_LS_12_credit_step_lower_12_END (10)
#define SOC_MediaCommon_AIF_CH_LS_12_credit_uth_lower_12_START (12)
#define SOC_MediaCommon_AIF_CH_LS_12_credit_uth_lower_12_END (20)
#define SOC_MediaCommon_AIF_CH_LS_12_credit_lth_lower_12_START (21)
#define SOC_MediaCommon_AIF_CH_LS_12_credit_lth_lower_12_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_0 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_0_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_0_mid_0_START (0)
#define SOC_MediaCommon_AIF_CH_MID_0_mid_0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_1_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_1_mid_1_START (0)
#define SOC_MediaCommon_AIF_CH_MID_1_mid_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_2 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_2_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_2_mid_2_START (0)
#define SOC_MediaCommon_AIF_CH_MID_2_mid_2_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_3 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_3_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_3_mid_3_START (0)
#define SOC_MediaCommon_AIF_CH_MID_3_mid_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_4 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_4_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_4_mid_4_START (0)
#define SOC_MediaCommon_AIF_CH_MID_4_mid_4_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_5 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_5_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_5_mid_5_START (0)
#define SOC_MediaCommon_AIF_CH_MID_5_mid_5_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_6 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_6_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_6_mid_6_START (0)
#define SOC_MediaCommon_AIF_CH_MID_6_mid_6_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_7 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_7_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_7_mid_7_START (0)
#define SOC_MediaCommon_AIF_CH_MID_7_mid_7_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_8 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_8_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_8_mid_8_START (0)
#define SOC_MediaCommon_AIF_CH_MID_8_mid_8_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_9 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_9_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_9_mid_9_START (0)
#define SOC_MediaCommon_AIF_CH_MID_9_mid_9_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_10 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_10_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_10_mid_10_START (0)
#define SOC_MediaCommon_AIF_CH_MID_10_mid_10_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_11 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_11_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_11_mid_11_START (0)
#define SOC_MediaCommon_AIF_CH_MID_11_mid_11_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_12 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_12_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_12_mid_12_START (0)
#define SOC_MediaCommon_AIF_CH_MID_12_mid_12_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_cmd : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_AIF_CH_MID_CMD_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_MID_CMD_mid_cmd_START (0)
#define SOC_MediaCommon_AIF_CH_MID_CMD_mid_cmd_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss0_mid : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_DSS0_MID_UNION;
#endif
#define SOC_MediaCommon_DSS0_MID_dss0_mid_START (0)
#define SOC_MediaCommon_DSS0_MID_dss0_mid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss1_mid : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_DSS1_MID_UNION;
#endif
#define SOC_MediaCommon_DSS1_MID_dss1_mid_START (0)
#define SOC_MediaCommon_DSS1_MID_dss1_mid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_rid_msk0 : 32;
    } reg;
} SOC_MediaCommon_AXI0_RID_MSK0_UNION;
#endif
#define SOC_MediaCommon_AXI0_RID_MSK0_axi0_rid_msk0_START (0)
#define SOC_MediaCommon_AXI0_RID_MSK0_axi0_rid_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_rid_msk1 : 32;
    } reg;
} SOC_MediaCommon_AXI0_RID_MSK1_UNION;
#endif
#define SOC_MediaCommon_AXI0_RID_MSK1_axi0_rid_msk1_START (0)
#define SOC_MediaCommon_AXI0_RID_MSK1_axi0_rid_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_wid_msk : 32;
    } reg;
} SOC_MediaCommon_AXI0_WID_MSK_UNION;
#endif
#define SOC_MediaCommon_AXI0_WID_MSK_axi0_wid_msk_START (0)
#define SOC_MediaCommon_AXI0_WID_MSK_axi0_wid_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_rd_qos_map : 8;
        unsigned int axi0_wr_qos_map : 8;
        unsigned int axi0_rd_prs_map : 8;
        unsigned int axi0_wr_prs_map : 8;
    } reg;
} SOC_MediaCommon_AXI0_R_QOS_MAP_UNION;
#endif
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_rd_qos_map_START (0)
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_rd_qos_map_END (7)
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_wr_qos_map_START (8)
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_wr_qos_map_END (15)
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_rd_prs_map_START (16)
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_rd_prs_map_END (23)
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_wr_prs_map_START (24)
#define SOC_MediaCommon_AXI0_R_QOS_MAP_axi0_wr_prs_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_rid_msk0 : 32;
    } reg;
} SOC_MediaCommon_AXI1_RID_MSK0_UNION;
#endif
#define SOC_MediaCommon_AXI1_RID_MSK0_axi1_rid_msk0_START (0)
#define SOC_MediaCommon_AXI1_RID_MSK0_axi1_rid_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_rid_msk1 : 32;
    } reg;
} SOC_MediaCommon_AXI1_RID_MSK1_UNION;
#endif
#define SOC_MediaCommon_AXI1_RID_MSK1_axi1_rid_msk1_START (0)
#define SOC_MediaCommon_AXI1_RID_MSK1_axi1_rid_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_wid_msk : 32;
    } reg;
} SOC_MediaCommon_AXI1_WID_MSK_UNION;
#endif
#define SOC_MediaCommon_AXI1_WID_MSK_axi1_wid_msk_START (0)
#define SOC_MediaCommon_AXI1_WID_MSK_axi1_wid_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_rd_qos_map : 8;
        unsigned int axi1_wr_qos_map : 8;
        unsigned int axi1_rd_prs_map : 8;
        unsigned int axi1_wr_prs_map : 8;
    } reg;
} SOC_MediaCommon_AXI1_R_QOS_MAP_UNION;
#endif
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_rd_qos_map_START (0)
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_rd_qos_map_END (7)
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_wr_qos_map_START (8)
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_wr_qos_map_END (15)
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_rd_prs_map_START (16)
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_rd_prs_map_END (23)
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_wr_prs_map_START (24)
#define SOC_MediaCommon_AXI1_R_QOS_MAP_axi1_wr_prs_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_clk_sel0 : 32;
    } reg;
} SOC_MediaCommon_AIF_CLK_SEL0_UNION;
#endif
#define SOC_MediaCommon_AIF_CLK_SEL0_aif_clk_sel0_START (0)
#define SOC_MediaCommon_AIF_CLK_SEL0_aif_clk_sel0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_clk_sel1 : 32;
    } reg;
} SOC_MediaCommon_AIF_CLK_SEL1_UNION;
#endif
#define SOC_MediaCommon_AIF_CLK_SEL1_aif_clk_sel1_START (0)
#define SOC_MediaCommon_AIF_CLK_SEL1_aif_clk_sel1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_clk_en0 : 32;
    } reg;
} SOC_MediaCommon_AIF_CLK_EN0_UNION;
#endif
#define SOC_MediaCommon_AIF_CLK_EN0_aif_clk_en0_START (0)
#define SOC_MediaCommon_AIF_CLK_EN0_aif_clk_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_clk_en1 : 32;
    } reg;
} SOC_MediaCommon_AIF_CLK_EN1_UNION;
#endif
#define SOC_MediaCommon_AIF_CLK_EN1_aif_clk_en1_START (0)
#define SOC_MediaCommon_AIF_CLK_EN1_aif_clk_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_cmd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_AIF_CH_CTL_CMD_UNION;
#endif
#define SOC_MediaCommon_AIF_CH_CTL_CMD_axi_sel_cmd_START (0)
#define SOC_MediaCommon_AIF_CH_CTL_CMD_axi_sel_cmd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_ini : 32;
    } reg;
} SOC_MediaCommon_MONITOR_TIMER_INI_UNION;
#endif
#define SOC_MediaCommon_MONITOR_TIMER_INI_monitor_ini_START (0)
#define SOC_MediaCommon_MONITOR_TIMER_INI_monitor_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int debug_base : 28;
    } reg;
} SOC_MediaCommon_DEBUG_BUF_BASE_UNION;
#endif
#define SOC_MediaCommon_DEBUG_BUF_BASE_debug_base_START (4)
#define SOC_MediaCommon_DEBUG_BUF_BASE_debug_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos_mode : 1;
        unsigned int flux_mode : 1;
        unsigned int credit_th_sel : 1;
        unsigned int addr_protect_en : 1;
        unsigned int reserved : 12;
        unsigned int debug_depth : 16;
    } reg;
} SOC_MediaCommon_DEBUG_CTRL_UNION;
#endif
#define SOC_MediaCommon_DEBUG_CTRL_qos_mode_START (0)
#define SOC_MediaCommon_DEBUG_CTRL_qos_mode_END (0)
#define SOC_MediaCommon_DEBUG_CTRL_flux_mode_START (1)
#define SOC_MediaCommon_DEBUG_CTRL_flux_mode_END (1)
#define SOC_MediaCommon_DEBUG_CTRL_credit_th_sel_START (2)
#define SOC_MediaCommon_DEBUG_CTRL_credit_th_sel_END (2)
#define SOC_MediaCommon_DEBUG_CTRL_addr_protect_en_START (3)
#define SOC_MediaCommon_DEBUG_CTRL_addr_protect_en_END (3)
#define SOC_MediaCommon_DEBUG_CTRL_debug_depth_START (16)
#define SOC_MediaCommon_DEBUG_CTRL_debug_depth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_AIF_SHADOW_READ_UNION;
#endif
#define SOC_MediaCommon_AIF_SHADOW_READ_aif_rd_shadow_START (0)
#define SOC_MediaCommon_AIF_SHADOW_READ_aif_rd_shadow_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_AIF_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_AIF_MEM_CTRL_mem_ctrl_START (0)
#define SOC_MediaCommon_AIF_MEM_CTRL_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_MONITOR_EN_UNION;
#endif
#define SOC_MediaCommon_MONITOR_EN_monitor_en_START (0)
#define SOC_MediaCommon_MONITOR_EN_monitor_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_axi_sel_w : 1;
        unsigned int mon_axi_sel_r : 1;
        unsigned int reserved_0 : 2;
        unsigned int sample_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int sample_cmd_type : 2;
        unsigned int reserved_2 : 2;
        unsigned int sample_mid : 5;
        unsigned int reserved_3 : 15;
    } reg;
} SOC_MediaCommon_MONITOR_CTRL_UNION;
#endif
#define SOC_MediaCommon_MONITOR_CTRL_mon_axi_sel_w_START (0)
#define SOC_MediaCommon_MONITOR_CTRL_mon_axi_sel_w_END (0)
#define SOC_MediaCommon_MONITOR_CTRL_mon_axi_sel_r_START (1)
#define SOC_MediaCommon_MONITOR_CTRL_mon_axi_sel_r_END (1)
#define SOC_MediaCommon_MONITOR_CTRL_sample_mode_START (4)
#define SOC_MediaCommon_MONITOR_CTRL_sample_mode_END (5)
#define SOC_MediaCommon_MONITOR_CTRL_sample_cmd_type_START (8)
#define SOC_MediaCommon_MONITOR_CTRL_sample_cmd_type_END (9)
#define SOC_MediaCommon_MONITOR_CTRL_sample_mid_START (12)
#define SOC_MediaCommon_MONITOR_CTRL_sample_mid_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_end_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_MONITOR_SAMPLE_MUN_UNION;
#endif
#define SOC_MediaCommon_MONITOR_SAMPLE_MUN_window_end_num_START (0)
#define SOC_MediaCommon_MONITOR_SAMPLE_MUN_window_end_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_end_time : 32;
    } reg;
} SOC_MediaCommon_MONITOR_SAMPLE_TIME_UNION;
#endif
#define SOC_MediaCommon_MONITOR_SAMPLE_TIME_window_end_time_START (0)
#define SOC_MediaCommon_MONITOR_SAMPLE_TIME_window_end_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_end_flow : 32;
    } reg;
} SOC_MediaCommon_MONITOR_SAMPLE_FLOW_UNION;
#endif
#define SOC_MediaCommon_MONITOR_SAMPLE_FLOW_window_end_flow_START (0)
#define SOC_MediaCommon_MONITOR_SAMPLE_FLOW_window_end_flow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int real_cycle_w : 32;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_0_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_0_real_cycle_w_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_0_real_cycle_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_cycle_w : 32;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_1_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_1_window_cycle_w_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_1_window_cycle_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int writedata : 32;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_2_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_2_writedata_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_2_writedata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cmd_cnt : 32;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_3_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_3_wr_cmd_cnt_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_3_wr_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_done_cnt : 32;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_4_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_4_wr_done_cnt_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_4_wr_done_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wburst_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_5_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_5_wburst_cnt_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_5_wburst_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avr_wrcycle_cnt : 32;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_6_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_6_avr_wrcycle_cnt_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_6_avr_wrcycle_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int min_wrcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_7_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_7_min_wrcycle_cnt_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_7_min_wrcycle_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_wrcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_MONITOR_WR_ST_8_UNION;
#endif
#define SOC_MediaCommon_MONITOR_WR_ST_8_max_wrcycle_cnt_START (0)
#define SOC_MediaCommon_MONITOR_WR_ST_8_max_wrcycle_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int real_cycle_r : 32;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_0_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_0_real_cycle_r_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_0_real_cycle_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_cycle_r : 32;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_1_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_1_window_cycle_r_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_1_window_cycle_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int readdata : 32;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_2_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_2_readdata_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_2_readdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cmd_cnt : 32;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_3_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_3_rd_cmd_cnt_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_3_rd_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_done_cnt : 32;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_4_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_4_rd_done_cnt_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_4_rd_done_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rburst_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_5_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_5_rburst_cnt_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_5_rburst_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avr_rdcycle_cnt : 32;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_6_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_6_avr_rdcycle_cnt_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_6_avr_rdcycle_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int min_rdcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_7_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_7_min_rdcycle_cnt_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_7_min_rdcycle_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_rdcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_MONITOR_RD_ST_8_UNION;
#endif
#define SOC_MediaCommon_MONITOR_RD_ST_8_max_rdcycle_cnt_START (0)
#define SOC_MediaCommon_MONITOR_RD_ST_8_max_rdcycle_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_zero_r : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_R0_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_R0_channel_os_zero_r_START (0)
#define SOC_MediaCommon_MONITOR_OS_R0_channel_os_zero_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_r0 : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_R1_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_R1_channel_os_r0_START (0)
#define SOC_MediaCommon_MONITOR_OS_R1_channel_os_r0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_r1 : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_R2_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_R2_channel_os_r1_START (0)
#define SOC_MediaCommon_MONITOR_OS_R2_channel_os_r1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_r2 : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_R3_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_R3_channel_os_r2_START (0)
#define SOC_MediaCommon_MONITOR_OS_R3_channel_os_r2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_os_r : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_R4_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_R4_axi_os_r_START (0)
#define SOC_MediaCommon_MONITOR_OS_R4_axi_os_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_zero_w : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_W0_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_W0_channel_os_zero_w_START (0)
#define SOC_MediaCommon_MONITOR_OS_W0_channel_os_zero_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_w0 : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_W1_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_W1_channel_os_w0_START (0)
#define SOC_MediaCommon_MONITOR_OS_W1_channel_os_w0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_w1 : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_W2_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_W2_channel_os_w1_START (0)
#define SOC_MediaCommon_MONITOR_OS_W2_channel_os_w1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_os_w : 32;
    } reg;
} SOC_MediaCommon_MONITOR_OS_W3_UNION;
#endif
#define SOC_MediaCommon_MONITOR_OS_W3_axi_os_w_START (0)
#define SOC_MediaCommon_MONITOR_OS_W3_axi_os_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_0 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_0_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_0_aif_stat_0_START (0)
#define SOC_MediaCommon_AIF_STAT_0_aif_stat_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_1 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_1_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_1_aif_stat_1_START (0)
#define SOC_MediaCommon_AIF_STAT_1_aif_stat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_2 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_2_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_2_aif_stat_2_START (0)
#define SOC_MediaCommon_AIF_STAT_2_aif_stat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_3 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_3_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_3_aif_stat_3_START (0)
#define SOC_MediaCommon_AIF_STAT_3_aif_stat_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_4 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_4_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_4_aif_stat_4_START (0)
#define SOC_MediaCommon_AIF_STAT_4_aif_stat_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_5 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_5_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_5_aif_stat_5_START (0)
#define SOC_MediaCommon_AIF_STAT_5_aif_stat_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_6 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_6_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_6_aif_stat_6_START (0)
#define SOC_MediaCommon_AIF_STAT_6_aif_stat_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_7 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_7_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_7_aif_stat_7_START (0)
#define SOC_MediaCommon_AIF_STAT_7_aif_stat_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_8 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_8_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_8_aif_stat_8_START (0)
#define SOC_MediaCommon_AIF_STAT_8_aif_stat_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_9 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_9_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_9_aif_stat_9_START (0)
#define SOC_MediaCommon_AIF_STAT_9_aif_stat_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_10 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_10_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_10_aif_stat_10_START (0)
#define SOC_MediaCommon_AIF_STAT_10_aif_stat_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_11 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_11_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_11_aif_stat_11_START (0)
#define SOC_MediaCommon_AIF_STAT_11_aif_stat_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_12 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_12_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_12_aif_stat_12_START (0)
#define SOC_MediaCommon_AIF_STAT_12_aif_stat_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_13 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_13_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_13_aif_stat_13_START (0)
#define SOC_MediaCommon_AIF_STAT_13_aif_stat_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_14 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_14_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_14_aif_stat_14_START (0)
#define SOC_MediaCommon_AIF_STAT_14_aif_stat_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_15 : 32;
    } reg;
} SOC_MediaCommon_AIF_STAT_15_UNION;
#endif
#define SOC_MediaCommon_AIF_STAT_15_aif_stat_15_START (0)
#define SOC_MediaCommon_AIF_STAT_15_aif_stat_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int module_clk_sel : 32;
    } reg;
} SOC_MediaCommon_MODULE_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_MODULE_CLK_SEL_module_clk_sel_START (0)
#define SOC_MediaCommon_MODULE_CLK_SEL_module_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int module_clk_en : 32;
    } reg;
} SOC_MediaCommon_MODULE_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_MODULE_CLK_EN_module_clk_en_START (0)
#define SOC_MediaCommon_MODULE_CLK_EN_module_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enable : 1;
        unsigned int tagcache_en : 1;
        unsigned int abn_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int abn_time : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_MediaCommon_MIF_ENABLE_UNION;
#endif
#define SOC_MediaCommon_MIF_ENABLE_enable_START (0)
#define SOC_MediaCommon_MIF_ENABLE_enable_END (0)
#define SOC_MediaCommon_MIF_ENABLE_tagcache_en_START (1)
#define SOC_MediaCommon_MIF_ENABLE_tagcache_en_END (1)
#define SOC_MediaCommon_MIF_ENABLE_abn_en_START (2)
#define SOC_MediaCommon_MIF_ENABLE_abn_en_END (2)
#define SOC_MediaCommon_MIF_ENABLE_abn_time_START (8)
#define SOC_MediaCommon_MIF_ENABLE_abn_time_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mif_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_MIF_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_MIF_MEM_CTRL_mif_mem_ctrl_START (0)
#define SOC_MediaCommon_MIF_MEM_CTRL_mif_mem_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_MIF_CTRL0_UNION;
#endif
#define SOC_MediaCommon_MIF_CTRL0_ctrl_en_START (0)
#define SOC_MediaCommon_MIF_CTRL0_ctrl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int qos_en : 1;
        unsigned int bypass : 1;
        unsigned int reserved_1 : 3;
        unsigned int iivld_en : 1;
        unsigned int invalid_sel : 2;
        unsigned int reserved_2 : 5;
        unsigned int rw_type : 1;
        unsigned int initial_en : 1;
        unsigned int pref_va_ctl : 1;
        unsigned int reserved_3 : 12;
    } reg;
} SOC_MediaCommon_MIF_CTRL1_UNION;
#endif
#define SOC_MediaCommon_MIF_CTRL1_qos_en_START (4)
#define SOC_MediaCommon_MIF_CTRL1_qos_en_END (4)
#define SOC_MediaCommon_MIF_CTRL1_bypass_START (5)
#define SOC_MediaCommon_MIF_CTRL1_bypass_END (5)
#define SOC_MediaCommon_MIF_CTRL1_iivld_en_START (9)
#define SOC_MediaCommon_MIF_CTRL1_iivld_en_END (9)
#define SOC_MediaCommon_MIF_CTRL1_invalid_sel_START (10)
#define SOC_MediaCommon_MIF_CTRL1_invalid_sel_END (11)
#define SOC_MediaCommon_MIF_CTRL1_rw_type_START (17)
#define SOC_MediaCommon_MIF_CTRL1_rw_type_END (17)
#define SOC_MediaCommon_MIF_CTRL1_initial_en_START (18)
#define SOC_MediaCommon_MIF_CTRL1_initial_en_END (18)
#define SOC_MediaCommon_MIF_CTRL1_pref_va_ctl_START (19)
#define SOC_MediaCommon_MIF_CTRL1_pref_va_ctl_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stride0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_MIF_CTRL2_UNION;
#endif
#define SOC_MediaCommon_MIF_CTRL2_stride0_START (0)
#define SOC_MediaCommon_MIF_CTRL2_stride0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stride1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_MIF_CTRL3_UNION;
#endif
#define SOC_MediaCommon_MIF_CTRL3_stride1_START (0)
#define SOC_MediaCommon_MIF_CTRL3_stride1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stride2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_MIF_CTRL4_UNION;
#endif
#define SOC_MediaCommon_MIF_CTRL4_stride2_START (0)
#define SOC_MediaCommon_MIF_CTRL4_stride2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stride3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_MIF_CTRL5_UNION;
#endif
#define SOC_MediaCommon_MIF_CTRL5_stride3_START (0)
#define SOC_MediaCommon_MIF_CTRL5_stride3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_REG_DEFAULT_UNION;
#endif
#define SOC_MediaCommon_REG_DEFAULT_reg_default_START (0)
#define SOC_MediaCommon_REG_DEFAULT_reg_default_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mif_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_MIF_SHADOW_READ_UNION;
#endif
#define SOC_MediaCommon_MIF_SHADOW_READ_mif_rd_shadow_START (0)
#define SOC_MediaCommon_MIF_SHADOW_READ_mif_rd_shadow_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_en : 1;
        unsigned int clk_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_MIF_CLK_CTL_UNION;
#endif
#define SOC_MediaCommon_MIF_CLK_CTL_clk_en_START (0)
#define SOC_MediaCommon_MIF_CLK_CTL_clk_en_END (0)
#define SOC_MediaCommon_MIF_CLK_CTL_clk_sel_START (1)
#define SOC_MediaCommon_MIF_CLK_CTL_clk_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tag_status : 32;
    } reg;
} SOC_MediaCommon_MIF_STAT0_UNION;
#endif
#define SOC_MediaCommon_MIF_STAT0_tag_status_START (0)
#define SOC_MediaCommon_MIF_STAT0_tag_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_ostd : 5;
        unsigned int index_ostd : 5;
        unsigned int pref_state : 5;
        unsigned int fetch_state : 4;
        unsigned int abn_state : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_MIF_STAT1_UNION;
#endif
#define SOC_MediaCommon_MIF_STAT1_pref_ostd_START (0)
#define SOC_MediaCommon_MIF_STAT1_pref_ostd_END (4)
#define SOC_MediaCommon_MIF_STAT1_index_ostd_START (5)
#define SOC_MediaCommon_MIF_STAT1_index_ostd_END (9)
#define SOC_MediaCommon_MIF_STAT1_pref_state_START (10)
#define SOC_MediaCommon_MIF_STAT1_pref_state_END (14)
#define SOC_MediaCommon_MIF_STAT1_fetch_state_START (15)
#define SOC_MediaCommon_MIF_STAT1_fetch_state_END (18)
#define SOC_MediaCommon_MIF_STAT1_abn_state_START (19)
#define SOC_MediaCommon_MIF_STAT1_abn_state_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_tag_hit : 16;
        unsigned int fetch_tag_hit : 16;
    } reg;
} SOC_MediaCommon_MIF_STAT2_UNION;
#endif
#define SOC_MediaCommon_MIF_STAT2_pref_tag_hit_START (0)
#define SOC_MediaCommon_MIF_STAT2_pref_tag_hit_END (15)
#define SOC_MediaCommon_MIF_STAT2_fetch_tag_hit_START (16)
#define SOC_MediaCommon_MIF_STAT2_fetch_tag_hit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_cmd_reload : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_AIF_CMD_RELOAD_UNION;
#endif
#define SOC_MediaCommon_AIF_CMD_RELOAD_aif_cmd_reload_START (0)
#define SOC_MediaCommon_AIF_CMD_RELOAD_aif_cmd_reload_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_RCH_FLUSH_EN_UNION;
#endif
#define SOC_MediaCommon_RCH_FLUSH_EN_rch_flush_en_START (0)
#define SOC_MediaCommon_RCH_FLUSH_EN_rch_flush_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_WCH_FLUSH_EN_UNION;
#endif
#define SOC_MediaCommon_WCH_FLUSH_EN_wch_flush_en_START (0)
#define SOC_MediaCommon_WCH_FLUSH_EN_wch_flush_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_ISPIF_FLUSH_EN_UNION;
#endif
#define SOC_MediaCommon_ISPIF_FLUSH_EN_ispif_flush_en_START (0)
#define SOC_MediaCommon_ISPIF_FLUSH_EN_ispif_flush_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_oen : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_MediaCommon_RCH_OEN_UNION;
#endif
#define SOC_MediaCommon_RCH_OEN_rch_oen_START (0)
#define SOC_MediaCommon_RCH_OEN_rch_oen_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_ien : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_WCH_IEN_UNION;
#endif
#define SOC_MediaCommon_WCH_IEN_wch_ien_START (0)
#define SOC_MediaCommon_WCH_IEN_wch_ien_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_wch_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_ISP_WCH_SEL_UNION;
#endif
#define SOC_MediaCommon_ISP_WCH_SEL_isp_wch_sel_START (0)
#define SOC_MediaCommon_ISP_WCH_SEL_isp_wch_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mctl_clk_sel : 32;
    } reg;
} SOC_MediaCommon_MCTL_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_MCTL_CLK_SEL_mctl_clk_sel_START (0)
#define SOC_MediaCommon_MCTL_CLK_SEL_mctl_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mctl_clk_en : 32;
    } reg;
} SOC_MediaCommon_MCTL_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_MCTL_CLK_EN_mctl_clk_en_START (0)
#define SOC_MediaCommon_MCTL_CLK_EN_mctl_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mod_clk_sel : 32;
    } reg;
} SOC_MediaCommon_MOD_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_MOD_CLK_SEL_mod_clk_sel_START (0)
#define SOC_MediaCommon_MOD_CLK_SEL_mod_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mod_clk_en : 32;
    } reg;
} SOC_MediaCommon_MOD_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_MOD_CLK_EN_mod_clk_en_START (0)
#define SOC_MediaCommon_MOD_CLK_EN_mod_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MediaCommon_MOD2_DBG_UNION;
#endif
#define SOC_MediaCommon_MOD2_DBG_rch_dbg_START (0)
#define SOC_MediaCommon_MOD2_DBG_rch_dbg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_dbg : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MediaCommon_MOD9_DBG_UNION;
#endif
#define SOC_MediaCommon_MOD9_DBG_wch_dbg_START (0)
#define SOC_MediaCommon_MOD9_DBG_wch_dbg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_dbg : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MediaCommon_MOD13_DBG_UNION;
#endif
#define SOC_MediaCommon_MOD13_DBG_ispif_dbg_START (0)
#define SOC_MediaCommon_MOD13_DBG_ispif_dbg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_status : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_MOD2_STATUS_UNION;
#endif
#define SOC_MediaCommon_MOD2_STATUS_rch_status_START (0)
#define SOC_MediaCommon_MOD2_STATUS_rch_status_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_status : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_MOD9_STATUS_UNION;
#endif
#define SOC_MediaCommon_MOD9_STATUS_wch_status_START (0)
#define SOC_MediaCommon_MOD9_STATUS_wch_status_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_status : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_MOD13_STATUS_UNION;
#endif
#define SOC_MediaCommon_MOD13_STATUS_ispif_status_START (0)
#define SOC_MediaCommon_MOD13_STATUS_ispif_status_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_dbg : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_SW_DBG_UNION;
#endif
#define SOC_MediaCommon_SW_DBG_sw_dbg_START (0)
#define SOC_MediaCommon_SW_DBG_sw_dbg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw1_status : 32;
    } reg;
} SOC_MediaCommon_SW1_STATUS_UNION;
#endif
#define SOC_MediaCommon_SW1_STATUS_sw1_status_START (0)
#define SOC_MediaCommon_SW1_STATUS_sw1_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CTL_EN_UNION;
#endif
#define SOC_MediaCommon_CTL_EN_ctl_en_START (0)
#define SOC_MediaCommon_CTL_EN_ctl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_mutex_sw : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CTL_MUTEX_UNION;
#endif
#define SOC_MediaCommon_CTL_MUTEX_ctl_mutex_sw_START (0)
#define SOC_MediaCommon_CTL_MUTEX_ctl_mutex_sw_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_mutex_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CTL_MUTEX_STATUS_UNION;
#endif
#define SOC_MediaCommon_CTL_MUTEX_STATUS_ctl_mutex_status_START (0)
#define SOC_MediaCommon_CTL_MUTEX_STATUS_ctl_mutex_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_mutext_ispif : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_CTL_MUTEXT_ISPIF_UNION;
#endif
#define SOC_MediaCommon_CTL_MUTEXT_ISPIF_ctl_mutext_ispif_START (0)
#define SOC_MediaCommon_CTL_MUTEXT_ISPIF_ctl_mutext_ispif_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_mutex_wch : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CTL_MUTEX_WCH_UNION;
#endif
#define SOC_MediaCommon_CTL_MUTEX_WCH_ctl_mutex_wch_START (0)
#define SOC_MediaCommon_CTL_MUTEX_WCH_ctl_mutex_wch_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_mutex_rch : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CTL_MUTEX_RCH_UNION;
#endif
#define SOC_MediaCommon_CTL_MUTEX_RCH_ctl_mutex_rch_START (0)
#define SOC_MediaCommon_CTL_MUTEX_RCH_ctl_mutex_rch_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_sof_sel : 2;
        unsigned int reserved_0 : 1;
        unsigned int ctl_block_mode : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_MediaCommon_CTL_TOP_UNION;
#endif
#define SOC_MediaCommon_CTL_TOP_ctl_sof_sel_START (0)
#define SOC_MediaCommon_CTL_TOP_ctl_sof_sel_END (1)
#define SOC_MediaCommon_CTL_TOP_ctl_block_mode_START (3)
#define SOC_MediaCommon_CTL_TOP_ctl_block_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_mod_flush_status : 32;
    } reg;
} SOC_MediaCommon_CTL_FLUSH_STATUS_UNION;
#endif
#define SOC_MediaCommon_CTL_FLUSH_STATUS_ctl_mod_flush_status_START (0)
#define SOC_MediaCommon_CTL_FLUSH_STATUS_ctl_mod_flush_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_sw_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CTL_CLEAR_UNION;
#endif
#define SOC_MediaCommon_CTL_CLEAR_ctl_sw_clr_START (0)
#define SOC_MediaCommon_CTL_CLEAR_ctl_sw_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_cack_tout : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CTL_CACK_TOUT_UNION;
#endif
#define SOC_MediaCommon_CTL_CACK_TOUT_ctl_cack_tout_START (0)
#define SOC_MediaCommon_CTL_CACK_TOUT_ctl_cack_tout_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_mutex_tout : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_CTL_MUTEX_TOUT_UNION;
#endif
#define SOC_MediaCommon_CTL_MUTEX_TOUT_ctl_mutex_tout_START (0)
#define SOC_MediaCommon_CTL_MUTEX_TOUT_ctl_mutex_tout_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_status : 4;
        unsigned int ctl_no_clr_ack : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_CTL_STATUS_UNION;
#endif
#define SOC_MediaCommon_CTL_STATUS_ctl_status_START (0)
#define SOC_MediaCommon_CTL_STATUS_ctl_status_END (3)
#define SOC_MediaCommon_CTL_STATUS_ctl_no_clr_ack_START (4)
#define SOC_MediaCommon_CTL_STATUS_ctl_no_clr_ack_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_inten : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_CTL_INTEN_UNION;
#endif
#define SOC_MediaCommon_CTL_INTEN_ctl_inten_START (0)
#define SOC_MediaCommon_CTL_INTEN_ctl_inten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_sw_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CTL_SW_ST_UNION;
#endif
#define SOC_MediaCommon_CTL_SW_ST_ctl_sw_st_START (0)
#define SOC_MediaCommon_CTL_SW_ST_ctl_sw_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_st_sel : 1;
        unsigned int ctl_act_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_CTL_ST_SEL_UNION;
#endif
#define SOC_MediaCommon_CTL_ST_SEL_ctl_st_sel_START (0)
#define SOC_MediaCommon_CTL_ST_SEL_ctl_st_sel_END (0)
#define SOC_MediaCommon_CTL_ST_SEL_ctl_act_sel_START (1)
#define SOC_MediaCommon_CTL_ST_SEL_ctl_act_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_end_sel : 32;
    } reg;
} SOC_MediaCommon_CTL_END_SEL_UNION;
#endif
#define SOC_MediaCommon_CTL_END_SEL_ctl_end_sel_START (0)
#define SOC_MediaCommon_CTL_END_SEL_ctl_end_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_clk_sel : 32;
    } reg;
} SOC_MediaCommon_CTL_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_CTL_CLK_SEL_ctl_clk_sel_START (0)
#define SOC_MediaCommon_CTL_CLK_SEL_ctl_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_clk_en : 32;
    } reg;
} SOC_MediaCommon_CTL_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_CTL_CLK_EN_ctl_clk_en_START (0)
#define SOC_MediaCommon_CTL_CLK_EN_ctl_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_dbg : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MediaCommon_CTL_DBG_UNION;
#endif
#define SOC_MediaCommon_CTL_DBG_ctl_dbg_START (0)
#define SOC_MediaCommon_CTL_DBG_ctl_dbg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_x0 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_DMA_OFT_X0_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_X0_dma_oft_x0_START (0)
#define SOC_MediaCommon_DMA_OFT_X0_dma_oft_x0_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_y0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_DMA_OFT_Y0_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_Y0_dma_oft_y0_START (0)
#define SOC_MediaCommon_DMA_OFT_Y0_dma_oft_y0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_x1 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_DMA_OFT_X1_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_X1_dma_oft_x1_START (0)
#define SOC_MediaCommon_DMA_OFT_X1_dma_oft_x1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_y1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_DMA_OFT_Y1_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_Y1_dma_oft_y1_START (0)
#define SOC_MediaCommon_DMA_OFT_Y1_dma_oft_y1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_mask_y0 : 16;
        unsigned int dma_mask_x0 : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_MediaCommon_DMA_MASK0_UNION;
#endif
#define SOC_MediaCommon_DMA_MASK0_dma_mask_y0_START (0)
#define SOC_MediaCommon_DMA_MASK0_dma_mask_y0_END (15)
#define SOC_MediaCommon_DMA_MASK0_dma_mask_x0_START (16)
#define SOC_MediaCommon_DMA_MASK0_dma_mask_x0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_mask_y1 : 16;
        unsigned int dma_mask_x1 : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_MediaCommon_DMA_MASK1_UNION;
#endif
#define SOC_MediaCommon_DMA_MASK1_dma_mask_y1_START (0)
#define SOC_MediaCommon_DMA_MASK1_dma_mask_y1_END (15)
#define SOC_MediaCommon_DMA_MASK1_dma_mask_x1_START (16)
#define SOC_MediaCommon_DMA_MASK1_dma_mask_x1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stretch_size_vrt : 13;
        unsigned int dma_line_skip_step : 6;
        unsigned int reserved : 13;
    } reg;
} SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_UNION;
#endif
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_stretch_size_vrt_START (0)
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_stretch_size_vrt_END (12)
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_line_skip_step_START (13)
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_line_skip_step_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_page_8k : 1;
        unsigned int dma_tile_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int dma_pix_fmt : 5;
        unsigned int dma_va_en : 1;
        unsigned int dma_mirror_hrz_en : 1;
        unsigned int dma_mirror_vrt_en : 1;
        unsigned int dma_rot : 1;
        unsigned int dma_stretch_en : 1;
        unsigned int reserved_1 : 4;
        unsigned int dma_mask_en : 1;
        unsigned int dma_phy_scrambl_4 : 1;
        unsigned int dma_phy_scrambl_3 : 1;
        unsigned int dma_phy_scrambl_2 : 1;
        unsigned int dma_phy_scrambl_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dma_cross_128 : 1;
        unsigned int dma_tile_128byte_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 6;
    } reg;
} SOC_MediaCommon_DMA_CTRL_UNION;
#endif
#define SOC_MediaCommon_DMA_CTRL_dma_page_8k_START (0)
#define SOC_MediaCommon_DMA_CTRL_dma_page_8k_END (0)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_en_START (1)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_en_END (1)
#define SOC_MediaCommon_DMA_CTRL_dma_pix_fmt_START (3)
#define SOC_MediaCommon_DMA_CTRL_dma_pix_fmt_END (7)
#define SOC_MediaCommon_DMA_CTRL_dma_va_en_START (8)
#define SOC_MediaCommon_DMA_CTRL_dma_va_en_END (8)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_hrz_en_START (9)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_hrz_en_END (9)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_vrt_en_START (10)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_vrt_en_END (10)
#define SOC_MediaCommon_DMA_CTRL_dma_rot_START (11)
#define SOC_MediaCommon_DMA_CTRL_dma_rot_END (11)
#define SOC_MediaCommon_DMA_CTRL_dma_stretch_en_START (12)
#define SOC_MediaCommon_DMA_CTRL_dma_stretch_en_END (12)
#define SOC_MediaCommon_DMA_CTRL_dma_mask_en_START (17)
#define SOC_MediaCommon_DMA_CTRL_dma_mask_en_END (17)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_4_START (18)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_4_END (18)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_3_START (19)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_3_END (19)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_2_START (20)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_2_END (20)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_1_START (21)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_1_END (21)
#define SOC_MediaCommon_DMA_CTRL_dma_cross_128_START (23)
#define SOC_MediaCommon_DMA_CTRL_dma_cross_128_END (23)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_128byte_en_START (24)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_128byte_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_tile_scrambling_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_TILE_SCRAM_UNION;
#endif
#define SOC_MediaCommon_DMA_TILE_SCRAM_dma_tile_scrambling_en_START (0)
#define SOC_MediaCommon_DMA_TILE_SCRAM_dma_tile_scrambling_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_pulse : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_PULSE_UNION;
#endif
#define SOC_MediaCommon_DMA_PULSE_dma_pulse_START (0)
#define SOC_MediaCommon_DMA_PULSE_dma_pulse_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rwch_cfg0 : 32;
    } reg;
} SOC_MediaCommon_RWCH_CFG0_UNION;
#endif
#define SOC_MediaCommon_RWCH_CFG0_rwch_cfg0_START (0)
#define SOC_MediaCommon_RWCH_CFG0_rwch_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr0 : 32;
    } reg;
} SOC_MediaCommon_DMA_DATA_ADDR0_UNION;
#endif
#define SOC_MediaCommon_DMA_DATA_ADDR0_dma_addr0_START (0)
#define SOC_MediaCommon_DMA_DATA_ADDR0_dma_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stride0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int dma_l2t_interleave_n0 : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_MediaCommon_DMA_STRIDE0_UNION;
#endif
#define SOC_MediaCommon_DMA_STRIDE0_dma_stride0_START (0)
#define SOC_MediaCommon_DMA_STRIDE0_dma_stride0_END (12)
#define SOC_MediaCommon_DMA_STRIDE0_dma_l2t_interleave_n0_START (16)
#define SOC_MediaCommon_DMA_STRIDE0_dma_l2t_interleave_n0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stretch_stride0 : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_MediaCommon_DMA_STRETCH_STRIDE0_UNION;
#endif
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_dma_stretch_stride0_START (0)
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_dma_stretch_stride0_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_data_num0 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DMA_DATA_NUM0_UNION;
#endif
#define SOC_MediaCommon_DMA_DATA_NUM0_dma_data_num0_START (0)
#define SOC_MediaCommon_DMA_DATA_NUM0_dma_data_num0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test0_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST0_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST0_dma_test0_y_START (0)
#define SOC_MediaCommon_DMA_TEST0_dma_test0_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test1_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST1_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST1_dma_test1_y_START (0)
#define SOC_MediaCommon_DMA_TEST1_dma_test1_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test3_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST3_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST3_dma_test3_y_START (0)
#define SOC_MediaCommon_DMA_TEST3_dma_test3_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test4_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST4_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST4_dma_test4_y_START (0)
#define SOC_MediaCommon_DMA_TEST4_dma_test4_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status_y : 32;
    } reg;
} SOC_MediaCommon_DMA_STATUS_Y_UNION;
#endif
#define SOC_MediaCommon_DMA_STATUS_Y_dma_status_y_START (0)
#define SOC_MediaCommon_DMA_STATUS_Y_dma_status_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rwch_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CH_RD_SHADOW_UNION;
#endif
#define SOC_MediaCommon_CH_RD_SHADOW_rwch_rd_shadow_START (0)
#define SOC_MediaCommon_CH_RD_SHADOW_rwch_rd_shadow_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_en : 1;
        unsigned int ch_version_sel : 1;
        unsigned int ch_afbcd_en : 1;
        unsigned int ch_block_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int ch_hebc_en : 1;
        unsigned int ch_dmac_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int ch_frm_end_dly : 4;
        unsigned int ch_block_h : 13;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_MediaCommon_CH_CTL_UNION;
#endif
#define SOC_MediaCommon_CH_CTL_ch_en_START (0)
#define SOC_MediaCommon_CH_CTL_ch_en_END (0)
#define SOC_MediaCommon_CH_CTL_ch_version_sel_START (1)
#define SOC_MediaCommon_CH_CTL_ch_version_sel_END (1)
#define SOC_MediaCommon_CH_CTL_ch_afbcd_en_START (2)
#define SOC_MediaCommon_CH_CTL_ch_afbcd_en_END (2)
#define SOC_MediaCommon_CH_CTL_ch_block_en_START (3)
#define SOC_MediaCommon_CH_CTL_ch_block_en_END (3)
#define SOC_MediaCommon_CH_CTL_ch_hebc_en_START (7)
#define SOC_MediaCommon_CH_CTL_ch_hebc_en_END (7)
#define SOC_MediaCommon_CH_CTL_ch_dmac_en_START (8)
#define SOC_MediaCommon_CH_CTL_ch_dmac_en_END (8)
#define SOC_MediaCommon_CH_CTL_ch_frm_end_dly_START (12)
#define SOC_MediaCommon_CH_CTL_ch_frm_end_dly_END (15)
#define SOC_MediaCommon_CH_CTL_ch_block_h_START (16)
#define SOC_MediaCommon_CH_CTL_ch_block_h_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_secu_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CH_SECU_EN_UNION;
#endif
#define SOC_MediaCommon_CH_SECU_EN_ch_secu_en_START (0)
#define SOC_MediaCommon_CH_SECU_EN_ch_secu_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_sw_end_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CH_SW_END_REQ_UNION;
#endif
#define SOC_MediaCommon_CH_SW_END_REQ_ch_sw_end_req_START (0)
#define SOC_MediaCommon_CH_SW_END_REQ_ch_sw_end_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_sel : 32;
    } reg;
} SOC_MediaCommon_CH_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_CH_CLK_SEL_ch_clk_sel_START (0)
#define SOC_MediaCommon_CH_CLK_SEL_ch_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_en : 32;
    } reg;
} SOC_MediaCommon_CH_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_CH_CLK_EN_ch_clk_en_START (0)
#define SOC_MediaCommon_CH_CLK_EN_ch_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg0 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG0_UNION;
#endif
#define SOC_MediaCommon_CH_DBG0_ch_dbg0_START (0)
#define SOC_MediaCommon_CH_DBG0_ch_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg1 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG1_UNION;
#endif
#define SOC_MediaCommon_CH_DBG1_ch_dbg1_START (0)
#define SOC_MediaCommon_CH_DBG1_ch_dbg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg2 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG2_UNION;
#endif
#define SOC_MediaCommon_CH_DBG2_ch_dbg2_START (0)
#define SOC_MediaCommon_CH_DBG2_ch_dbg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg3 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG3_UNION;
#endif
#define SOC_MediaCommon_CH_DBG3_ch_dbg3_START (0)
#define SOC_MediaCommon_CH_DBG3_ch_dbg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg4 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG4_UNION;
#endif
#define SOC_MediaCommon_CH_DBG4_ch_dbg4_START (0)
#define SOC_MediaCommon_CH_DBG4_ch_dbg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg5 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG5_UNION;
#endif
#define SOC_MediaCommon_CH_DBG5_ch_dbg5_START (0)
#define SOC_MediaCommon_CH_DBG5_ch_dbg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int dfc_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_DFC_DISP_SIZE_UNION;
#endif
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_vrt_START (0)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_vrt_END (12)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_hrz_START (16)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_hrz_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_pix_in_num : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_PIX_IN_NUM_UNION;
#endif
#define SOC_MediaCommon_DFC_PIX_IN_NUM_dfc_pix_in_num_START (0)
#define SOC_MediaCommon_DFC_PIX_IN_NUM_dfc_pix_in_num_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MediaCommon_DFC_GLB_ALPHA01_UNION;
#endif
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha1_START (0)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha1_END (9)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha0_START (16)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ax_swap : 1;
        unsigned int dfc_img_fmt : 5;
        unsigned int dfc_uv_swap : 1;
        unsigned int dfc_rb_swap : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_DFC_DISP_FMT_UNION;
#endif
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_ax_swap_START (0)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_ax_swap_END (0)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_img_fmt_START (1)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_img_fmt_END (5)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_uv_swap_START (6)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_uv_swap_END (6)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_rb_swap_START (7)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_rb_swap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_right_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_left_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_DFC_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_right_clip_START (0)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_right_clip_END (5)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_left_clip_START (16)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_left_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_bot_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_top_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_DFC_CLIP_CTL_VRZ_UNION;
#endif
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_bot_clip_START (0)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_bot_clip_END (5)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_top_clip_START (16)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_top_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ctl_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_CTL_CLIP_EN_UNION;
#endif
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_START (0)
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_ICG_MODULE_UNION;
#endif
#define SOC_MediaCommon_DFC_ICG_MODULE_dfc_module_en_START (0)
#define SOC_MediaCommon_DFC_ICG_MODULE_dfc_module_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_dither_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_DITHER_ENABLE_UNION;
#endif
#define SOC_MediaCommon_DFC_DITHER_ENABLE_dfc_dither_en_START (0)
#define SOC_MediaCommon_DFC_DITHER_ENABLE_dfc_dither_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_left_pad : 6;
        unsigned int reserved_0 : 2;
        unsigned int dfc_right_pad : 6;
        unsigned int reserved_1 : 2;
        unsigned int dfc_top_pad : 6;
        unsigned int reserved_2 : 2;
        unsigned int dfc_bot_pad : 6;
        unsigned int reserved_3 : 1;
        unsigned int dfc_ctl_pad_enable : 1;
    } reg;
} SOC_MediaCommon_DFC_PADDING_CTL_UNION;
#endif
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_left_pad_START (0)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_left_pad_END (5)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_right_pad_START (8)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_right_pad_END (13)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_top_pad_START (16)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_top_pad_END (21)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_bot_pad_START (24)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_bot_pad_END (29)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_ctl_pad_enable_START (31)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_ctl_pad_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MediaCommon_DFC_GLB_ALPHA23_UNION;
#endif
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha3_START (0)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha3_END (9)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha2_START (16)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_en : 1;
        unsigned int bitext_rgb_en : 1;
        unsigned int bitext_alpha_en : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_BITEXT_CTL_UNION;
#endif
#define SOC_MediaCommon_BITEXT_CTL_bitext_en_START (0)
#define SOC_MediaCommon_BITEXT_CTL_bitext_en_END (0)
#define SOC_MediaCommon_BITEXT_CTL_bitext_rgb_en_START (1)
#define SOC_MediaCommon_BITEXT_CTL_bitext_rgb_en_END (1)
#define SOC_MediaCommon_BITEXT_CTL_bitext_alpha_en_START (2)
#define SOC_MediaCommon_BITEXT_CTL_bitext_alpha_en_END (2)
#define SOC_MediaCommon_BITEXT_CTL_bitext_reg_ini_cfg_en_START (3)
#define SOC_MediaCommon_BITEXT_CTL_bitext_reg_ini_cfg_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_0_bitext_reg_ini0_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_0_bitext_reg_ini0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_1_bitext_reg_ini0_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_1_bitext_reg_ini0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_2_bitext_reg_ini0_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_2_bitext_reg_ini0_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_3_bitext_reg_ini0_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_3_bitext_reg_ini0_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_0_bitext_reg_ini1_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_0_bitext_reg_ini1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_1_bitext_reg_ini1_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_1_bitext_reg_ini1_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_2_bitext_reg_ini1_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_2_bitext_reg_ini1_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_3_bitext_reg_ini1_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_3_bitext_reg_ini1_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_0_bitext_reg_ini2_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_0_bitext_reg_ini2_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_1_bitext_reg_ini2_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_1_bitext_reg_ini2_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_2_bitext_reg_ini2_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_2_bitext_reg_ini2_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_3_bitext_reg_ini2_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_3_bitext_reg_ini2_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_BITEXT_POWER_CTRL_C_UNION;
#endif
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_bitext_power_ctrl_c_START (0)
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_bitext_power_ctrl_c_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_bitext_power_ctrl_shift_START (0)
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_bitext_power_ctrl_shift_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_00_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_00_bitext_filt_00_START (0)
#define SOC_MediaCommon_BITEXT_FILT_00_bitext_filt_00_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_01_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_01_bitext_filt_01_START (0)
#define SOC_MediaCommon_BITEXT_FILT_01_bitext_filt_01_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_02_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_02_bitext_filt_02_START (0)
#define SOC_MediaCommon_BITEXT_FILT_02_bitext_filt_02_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_10_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_10_bitext_filt_10_START (0)
#define SOC_MediaCommon_BITEXT_FILT_10_bitext_filt_10_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_11_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_11_bitext_filt_11_START (0)
#define SOC_MediaCommon_BITEXT_FILT_11_bitext_filt_11_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_12_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_12_bitext_filt_12_START (0)
#define SOC_MediaCommon_BITEXT_FILT_12_bitext_filt_12_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_20_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_20_bitext_filt_20_START (0)
#define SOC_MediaCommon_BITEXT_FILT_20_bitext_filt_20_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_21_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_21_bitext_filt_21_START (0)
#define SOC_MediaCommon_BITEXT_FILT_21_bitext_filt_21_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_22_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_22_bitext_filt_22_START (0)
#define SOC_MediaCommon_BITEXT_FILT_22_bitext_filt_22_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_R0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_R0_bitext_thd_r0_START (0)
#define SOC_MediaCommon_BITEXT_THD_R0_bitext_thd_r0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_R1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_R1_bitext_thd_r1_START (0)
#define SOC_MediaCommon_BITEXT_THD_R1_bitext_thd_r1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_G0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_G0_bitext_thd_g0_START (0)
#define SOC_MediaCommon_BITEXT_THD_G0_bitext_thd_g0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_G1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_G1_bitext_thd_g1_START (0)
#define SOC_MediaCommon_BITEXT_THD_G1_bitext_thd_g1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_B0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_B0_bitext_thd_b0_START (0)
#define SOC_MediaCommon_BITEXT_THD_B0_bitext_thd_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_B1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_B1_bitext_thd_b1_START (0)
#define SOC_MediaCommon_BITEXT_THD_B1_bitext_thd_b1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_dbg0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT0_DBG0_UNION;
#endif
#define SOC_MediaCommon_BITEXT0_DBG0_bitext_dbg0_START (0)
#define SOC_MediaCommon_BITEXT0_DBG0_bitext_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_MediaCommon_CSC_IDC0_UNION;
#endif
#define SOC_MediaCommon_CSC_IDC0_csc_idc0_START (0)
#define SOC_MediaCommon_CSC_IDC0_csc_idc0_END (10)
#define SOC_MediaCommon_CSC_IDC0_csc_idc1_START (16)
#define SOC_MediaCommon_CSC_IDC0_csc_idc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_MediaCommon_CSC_IDC2_UNION;
#endif
#define SOC_MediaCommon_CSC_IDC2_csc_idc2_START (0)
#define SOC_MediaCommon_CSC_IDC2_csc_idc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_MediaCommon_CSC_ODC0_UNION;
#endif
#define SOC_MediaCommon_CSC_ODC0_csc_odc0_START (0)
#define SOC_MediaCommon_CSC_ODC0_csc_odc0_END (10)
#define SOC_MediaCommon_CSC_ODC0_csc_odc1_START (16)
#define SOC_MediaCommon_CSC_ODC0_csc_odc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_MediaCommon_CSC_ODC2_UNION;
#endif
#define SOC_MediaCommon_CSC_ODC2_csc_odc2_START (0)
#define SOC_MediaCommon_CSC_ODC2_csc_odc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P00_UNION;
#endif
#define SOC_MediaCommon_CSC_P00_csc_p00_START (0)
#define SOC_MediaCommon_CSC_P00_csc_p00_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P01_UNION;
#endif
#define SOC_MediaCommon_CSC_P01_csc_p01_START (0)
#define SOC_MediaCommon_CSC_P01_csc_p01_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P02_UNION;
#endif
#define SOC_MediaCommon_CSC_P02_csc_p02_START (0)
#define SOC_MediaCommon_CSC_P02_csc_p02_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P10_UNION;
#endif
#define SOC_MediaCommon_CSC_P10_csc_p10_START (0)
#define SOC_MediaCommon_CSC_P10_csc_p10_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P11_UNION;
#endif
#define SOC_MediaCommon_CSC_P11_csc_p11_START (0)
#define SOC_MediaCommon_CSC_P11_csc_p11_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P12_UNION;
#endif
#define SOC_MediaCommon_CSC_P12_csc_p12_START (0)
#define SOC_MediaCommon_CSC_P12_csc_p12_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P20_UNION;
#endif
#define SOC_MediaCommon_CSC_P20_csc_p20_START (0)
#define SOC_MediaCommon_CSC_P20_csc_p20_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P21_UNION;
#endif
#define SOC_MediaCommon_CSC_P21_csc_p21_START (0)
#define SOC_MediaCommon_CSC_P21_csc_p21_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P22_UNION;
#endif
#define SOC_MediaCommon_CSC_P22_csc_p22_START (0)
#define SOC_MediaCommon_CSC_P22_csc_p22_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CSC_ICG_MODULE_UNION;
#endif
#define SOC_MediaCommon_CSC_ICG_MODULE_csc_module_en_START (0)
#define SOC_MediaCommon_CSC_ICG_MODULE_csc_module_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_CSC_MPREC_UNION;
#endif
#define SOC_MediaCommon_CSC_MPREC_csc_mprec_START (0)
#define SOC_MediaCommon_CSC_MPREC_csc_mprec_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_debug_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_CH_DEBUG_SEL_UNION;
#endif
#define SOC_MediaCommon_CH_DEBUG_SEL_ch_debug_sel_START (0)
#define SOC_MediaCommon_CH_DEBUG_SEL_ch_debug_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_os_cfg : 6;
        unsigned int reserved_0 : 2;
        unsigned int dma_buf_qos_mask : 1;
        unsigned int dma_buf_cont_mask : 1;
        unsigned int dma_buf_l_e_mask : 1;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_MediaCommon_DMA_BUF_CTRL_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_os_cfg_START (0)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_os_cfg_END (5)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_qos_mask_START (8)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_qos_mask_END (8)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_cont_mask_START (9)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_cont_mask_END (9)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_l_e_mask_START (10)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_l_e_mask_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_ctl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_CTL_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_dma_buf_cpu_ctl_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_dma_buf_cpu_ctl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_START_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_START_dma_buf_cpu_start_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_START_dma_buf_cpu_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_addr : 9;
        unsigned int reserved : 22;
        unsigned int dma_buf_cpu_rw : 1;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_ADDR_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_addr_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_addr_END (8)
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_rw_START (31)
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata0 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA0_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_dma_buf_cpu_rdata0_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_dma_buf_cpu_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata1 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA1_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_dma_buf_cpu_rdata1_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_dma_buf_cpu_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata2 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA2_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_dma_buf_cpu_rdata2_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_dma_buf_cpu_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata3 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA3_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_dma_buf_cpu_rdata3_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_dma_buf_cpu_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata0 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA0_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_dma_buf_cpu_wdata0_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_dma_buf_cpu_wdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata1 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA1_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_dma_buf_cpu_wdata1_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_dma_buf_cpu_wdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata2 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA2_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_dma_buf_cpu_wdata2_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_dma_buf_cpu_wdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata3 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA3_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_dma_buf_cpu_wdata3_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_dma_buf_cpu_wdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_req_end : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_REQ_END_UNION;
#endif
#define SOC_MediaCommon_DMA_REQ_END_dma_req_end_START (0)
#define SOC_MediaCommon_DMA_REQ_END_dma_req_end_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbgcfg : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBGCFG_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBGCFG_dma_buf_dbgcfg_START (0)
#define SOC_MediaCommon_DMA_BUF_DBGCFG_dma_buf_dbgcfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg0 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG0_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG0_dma_buf_dbg0_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG0_dma_buf_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg1 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG1_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG1_dma_buf_dbg1_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG1_dma_buf_dbg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg2 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG2_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG2_dma_buf_dbg2_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG2_dma_buf_dbg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg3 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG3_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG3_dma_buf_dbg3_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG3_dma_buf_dbg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg4 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG4_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG4_dma_buf_dbg4_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG4_dma_buf_dbg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg5 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG5_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG5_dma_buf_dbg5_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG5_dma_buf_dbg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_img_width : 13;
        unsigned int reserved_0 : 3;
        unsigned int dma_buf_img_height : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_DMA_BUF_SIZE_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_width_START (0)
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_width_END (12)
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_height_START (16)
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_height_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_DMA_BUF_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_dma_buf_mem_ctrl_START (0)
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_dma_buf_mem_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_hdr_ptr_0 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_UNION;
#endif
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_afbcd_hdr_ptr_0_START (0)
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_afbcd_hdr_ptr_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_pic_width : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_AFBCD_HREG_PIC_WIDTH_UNION;
#endif
#define SOC_MediaCommon_AFBCD_HREG_PIC_WIDTH_afbcd_pic_width_START (0)
#define SOC_MediaCommon_AFBCD_HREG_PIC_WIDTH_afbcd_pic_width_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_pic_height : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_AFBCD_HREG_PIC_HEIGHT_UNION;
#endif
#define SOC_MediaCommon_AFBCD_HREG_PIC_HEIGHT_afbcd_pic_height_START (0)
#define SOC_MediaCommon_AFBCD_HREG_PIC_HEIGHT_afbcd_pic_height_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_block_split : 1;
        unsigned int afbcd_half_block : 1;
        unsigned int reserved_0 : 14;
        unsigned int reserved_1 : 5;
        unsigned int afbcd_color_transform : 1;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_MediaCommon_AFBCD_HREG_FORMAT_UNION;
#endif
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_afbcd_block_split_START (0)
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_afbcd_block_split_END (0)
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_afbcd_half_block_START (1)
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_afbcd_half_block_END (1)
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_afbcd_color_transform_START (21)
#define SOC_MediaCommon_AFBCD_HREG_FORMAT_afbcd_color_transform_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 6;
        unsigned int afbcd_half_block_mode : 2;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_MediaCommon_AFBCD_CTL_UNION;
#endif
#define SOC_MediaCommon_AFBCD_CTL_afbcd_half_block_mode_START (6)
#define SOC_MediaCommon_AFBCD_CTL_afbcd_half_block_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_stretch_inc : 8;
        unsigned int afbcd_stretch_acc : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_AFBCD_STR_UNION;
#endif
#define SOC_MediaCommon_AFBCD_STR_afbcd_stretch_inc_START (0)
#define SOC_MediaCommon_AFBCD_STR_afbcd_stretch_inc_END (7)
#define SOC_MediaCommon_AFBCD_STR_afbcd_stretch_acc_START (8)
#define SOC_MediaCommon_AFBCD_STR_afbcd_stretch_acc_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_bottom_crop_num : 8;
        unsigned int afbcd_top_crop_num : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_LINE_CROP_UNION;
#endif
#define SOC_MediaCommon_LINE_CROP_afbcd_bottom_crop_num_START (0)
#define SOC_MediaCommon_LINE_CROP_afbcd_bottom_crop_num_END (7)
#define SOC_MediaCommon_LINE_CROP_afbcd_top_crop_num_START (8)
#define SOC_MediaCommon_LINE_CROP_afbcd_top_crop_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_header_stride_0 : 14;
        unsigned int afbcd_header_start_pos : 2;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_INPUT_HEADER_STRIDE_UNION;
#endif
#define SOC_MediaCommon_INPUT_HEADER_STRIDE_afbcd_header_stride_0_START (0)
#define SOC_MediaCommon_INPUT_HEADER_STRIDE_afbcd_header_stride_0_END (13)
#define SOC_MediaCommon_INPUT_HEADER_STRIDE_afbcd_header_start_pos_START (14)
#define SOC_MediaCommon_INPUT_HEADER_STRIDE_afbcd_header_start_pos_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_payload_stride_0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_AFBCD_PAYLOAD_STRIDE_UNION;
#endif
#define SOC_MediaCommon_AFBCD_PAYLOAD_STRIDE_afbcd_payload_stride_0_START (0)
#define SOC_MediaCommon_AFBCD_PAYLOAD_STRIDE_afbcd_payload_stride_0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_mm_base_0 : 32;
    } reg;
} SOC_MediaCommon_MM_BASE_UNION;
#endif
#define SOC_MediaCommon_MM_BASE_afbcd_mm_base_0_START (0)
#define SOC_MediaCommon_MM_BASE_afbcd_mm_base_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_payload_ptr_0 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_PAYLOAD_POINTER_UNION;
#endif
#define SOC_MediaCommon_AFBCD_PAYLOAD_POINTER_afbcd_payload_ptr_0_START (0)
#define SOC_MediaCommon_AFBCD_PAYLOAD_POINTER_afbcd_payload_ptr_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_pic_height_bf_stretch : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_HEIGHT_BF_STR_UNION;
#endif
#define SOC_MediaCommon_HEIGHT_BF_STR_afbcd_pic_height_bf_stretch_START (0)
#define SOC_MediaCommon_HEIGHT_BF_STR_afbcd_pic_height_bf_stretch_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_mmrd_os : 4;
        unsigned int afbcd_mmwr_os : 4;
        unsigned int afbcd_ddrr_os : 6;
        unsigned int hfbcd_mmrd_os : 4;
        unsigned int hfbcd_mmwr_os : 4;
        unsigned int hfbcd_ddrr_os : 6;
        unsigned int reserved : 4;
    } reg;
} SOC_MediaCommon_OS_CFG_UNION;
#endif
#define SOC_MediaCommon_OS_CFG_afbcd_mmrd_os_START (0)
#define SOC_MediaCommon_OS_CFG_afbcd_mmrd_os_END (3)
#define SOC_MediaCommon_OS_CFG_afbcd_mmwr_os_START (4)
#define SOC_MediaCommon_OS_CFG_afbcd_mmwr_os_END (7)
#define SOC_MediaCommon_OS_CFG_afbcd_ddrr_os_START (8)
#define SOC_MediaCommon_OS_CFG_afbcd_ddrr_os_END (13)
#define SOC_MediaCommon_OS_CFG_hfbcd_mmrd_os_START (14)
#define SOC_MediaCommon_OS_CFG_hfbcd_mmrd_os_END (17)
#define SOC_MediaCommon_OS_CFG_hfbcd_mmwr_os_START (18)
#define SOC_MediaCommon_OS_CFG_hfbcd_mmwr_os_END (21)
#define SOC_MediaCommon_OS_CFG_hfbcd_ddrr_os_START (22)
#define SOC_MediaCommon_OS_CFG_hfbcd_ddrr_os_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_mem_ctrl_0 : 4;
        unsigned int afbcd_mem_ctrl_1 : 4;
        unsigned int afbcd_mem_ctrl_2 : 4;
        unsigned int afbcd_mem_ctrl_3 : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_AFBCD_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_0_START (0)
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_0_END (3)
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_1_START (4)
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_1_END (7)
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_2_START (8)
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_2_END (11)
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_3_START (12)
#define SOC_MediaCommon_AFBCD_MEM_CTRL_afbcd_mem_ctrl_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_scramble_mode : 2;
        unsigned int hfbcd_scramble_mode : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_AFBCD_SCRAMBLE_MODE_UNION;
#endif
#define SOC_MediaCommon_AFBCD_SCRAMBLE_MODE_afbcd_scramble_mode_START (0)
#define SOC_MediaCommon_AFBCD_SCRAMBLE_MODE_afbcd_scramble_mode_END (1)
#define SOC_MediaCommon_AFBCD_SCRAMBLE_MODE_hfbcd_scramble_mode_START (2)
#define SOC_MediaCommon_AFBCD_SCRAMBLE_MODE_hfbcd_scramble_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_header_pointer_offset : 32;
    } reg;
} SOC_MediaCommon_AFBCD_HEADER_POINTER_OFFSET_UNION;
#endif
#define SOC_MediaCommon_AFBCD_HEADER_POINTER_OFFSET_afbcd_header_pointer_offset_START (0)
#define SOC_MediaCommon_AFBCD_HEADER_POINTER_OFFSET_afbcd_header_pointer_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_monitor_reg1 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_MONITOR_REG1_UNION;
#endif
#define SOC_MediaCommon_AFBCD_MONITOR_REG1_afbcd_monitor_reg1_START (0)
#define SOC_MediaCommon_AFBCD_MONITOR_REG1_afbcd_monitor_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_monitor_reg2 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_MONITOR_REG2_UNION;
#endif
#define SOC_MediaCommon_AFBCD_MONITOR_REG2_afbcd_monitor_reg2_START (0)
#define SOC_MediaCommon_AFBCD_MONITOR_REG2_afbcd_monitor_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_monitor_reg3 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_MONITOR_REG3_UNION;
#endif
#define SOC_MediaCommon_AFBCD_MONITOR_REG3_afbcd_monitor_reg3_START (0)
#define SOC_MediaCommon_AFBCD_MONITOR_REG3_afbcd_monitor_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_debug_reg0 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_DEBUG_REG0_UNION;
#endif
#define SOC_MediaCommon_AFBCD_DEBUG_REG0_afbcd_debug_reg0_START (0)
#define SOC_MediaCommon_AFBCD_DEBUG_REG0_afbcd_debug_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_creg_fbcd_mode : 1;
        unsigned int fbcd_creg_hfbcd_noheader_mode : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_FBCD_CREG_FBCD_CTRL_MODE_UNION;
#endif
#define SOC_MediaCommon_FBCD_CREG_FBCD_CTRL_MODE_fbcd_creg_fbcd_mode_START (0)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CTRL_MODE_fbcd_creg_fbcd_mode_END (0)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CTRL_MODE_fbcd_creg_hfbcd_noheader_mode_START (1)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CTRL_MODE_fbcd_creg_hfbcd_noheader_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_hdr_ptr_1 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_1_UNION;
#endif
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_1_fbcd_hdr_ptr_1_START (0)
#define SOC_MediaCommon_AFBCD_HREG_HDR_PTR_LO_1_fbcd_hdr_ptr_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_payload_ptr_1 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_HREG_PLD_PTR_LO_1_UNION;
#endif
#define SOC_MediaCommon_AFBCD_HREG_PLD_PTR_LO_1_fbcd_payload_ptr_1_START (0)
#define SOC_MediaCommon_AFBCD_HREG_PLD_PTR_LO_1_fbcd_payload_ptr_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_header_stride_1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_HEADER_SRTIDE_1_UNION;
#endif
#define SOC_MediaCommon_HEADER_SRTIDE_1_fbcd_header_stride_1_START (0)
#define SOC_MediaCommon_HEADER_SRTIDE_1_fbcd_header_stride_1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_payload_stride_1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_PAYLOAD_STRIDE_1_UNION;
#endif
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_fbcd_payload_stride_1_START (0)
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_fbcd_payload_stride_1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_block_type : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_FBCD_BLOCK_TYPE_UNION;
#endif
#define SOC_MediaCommon_FBCD_BLOCK_TYPE_fbcd_block_type_START (0)
#define SOC_MediaCommon_FBCD_BLOCK_TYPE_fbcd_block_type_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_mm_base_1 : 32;
    } reg;
} SOC_MediaCommon_MM_BASE_1_UNION;
#endif
#define SOC_MediaCommon_MM_BASE_1_fbcd_mm_base_1_START (0)
#define SOC_MediaCommon_MM_BASE_1_fbcd_mm_base_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_mm_base_2 : 32;
    } reg;
} SOC_MediaCommon_MM_BASE_2_UNION;
#endif
#define SOC_MediaCommon_MM_BASE_2_fbcd_mm_base_2_START (0)
#define SOC_MediaCommon_MM_BASE_2_fbcd_mm_base_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_mm_base_3 : 32;
    } reg;
} SOC_MediaCommon_MM_BASE_3_UNION;
#endif
#define SOC_MediaCommon_MM_BASE_3_fbcd_mm_base_3_START (0)
#define SOC_MediaCommon_MM_BASE_3_fbcd_mm_base_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_mem_ctrl_0 : 4;
        unsigned int hfbcd_mem_ctrl_1 : 4;
        unsigned int hfbcd_mem_ctrl_2 : 4;
        unsigned int hfbcd_mem_ctrl_3 : 4;
        unsigned int hfbcd_mem_ctrl_4 : 4;
        unsigned int hfbcd_mem_ctrl_5 : 4;
        unsigned int hfbcd_mem_ctrl_6 : 4;
        unsigned int hfbcd_mem_ctrl_7 : 4;
    } reg;
} SOC_MediaCommon_HFBCD_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_0_START (0)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_0_END (3)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_1_START (4)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_1_END (7)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_2_START (8)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_2_END (11)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_3_START (12)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_3_END (15)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_4_START (16)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_4_END (19)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_5_START (20)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_5_END (23)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_6_START (24)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_6_END (27)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_7_START (28)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_hfbcd_mem_ctrl_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_mem_ctrl_8 : 4;
        unsigned int hfbcd_mem_ctrl_9 : 4;
        unsigned int hfbcd_mem_ctrl_10 : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_HFBCD_MEM_CTRL_1_UNION;
#endif
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_hfbcd_mem_ctrl_8_START (0)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_hfbcd_mem_ctrl_8_END (3)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_hfbcd_mem_ctrl_9_START (4)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_hfbcd_mem_ctrl_9_END (7)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_hfbcd_mem_ctrl_10_START (8)
#define SOC_MediaCommon_HFBCD_MEM_CTRL_1_hfbcd_mem_ctrl_10_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbcd_creg_clkgate_off : 1;
        unsigned int fbcd_creg_mem_sd_off : 1;
        unsigned int fbcd_creg_hfbcd_ip_auto_clk_gt_en : 1;
        unsigned int fbcd_creg_fbcd_auto_clk_gt_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_UNION;
#endif
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_clkgate_off_START (0)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_clkgate_off_END (0)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_mem_sd_off_START (1)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_mem_sd_off_END (1)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_hfbcd_ip_auto_clk_gt_en_START (2)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_hfbcd_ip_auto_clk_gt_en_END (2)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_fbcd_auto_clk_gt_en_START (3)
#define SOC_MediaCommon_FBCD_CREG_FBCD_CLK_GATE_fbcd_creg_fbcd_auto_clk_gt_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_monitor_reg1 : 32;
    } reg;
} SOC_MediaCommon_HFBCD_MONTIOR_REG1_UNION;
#endif
#define SOC_MediaCommon_HFBCD_MONTIOR_REG1_hfbcd_monitor_reg1_START (0)
#define SOC_MediaCommon_HFBCD_MONTIOR_REG1_hfbcd_monitor_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_monitor_reg2 : 32;
    } reg;
} SOC_MediaCommon_HFBCD_MONTIOR_REG2_UNION;
#endif
#define SOC_MediaCommon_HFBCD_MONTIOR_REG2_hfbcd_monitor_reg2_START (0)
#define SOC_MediaCommon_HFBCD_MONTIOR_REG2_hfbcd_monitor_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_monitor_reg3 : 32;
    } reg;
} SOC_MediaCommon_HFBCD_MONTIOR_REG3_UNION;
#endif
#define SOC_MediaCommon_HFBCD_MONTIOR_REG3_hfbcd_monitor_reg3_START (0)
#define SOC_MediaCommon_HFBCD_MONTIOR_REG3_hfbcd_monitor_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_debug_reg0 : 32;
    } reg;
} SOC_MediaCommon_HFBCD_DEBUG_REG0_UNION;
#endif
#define SOC_MediaCommon_HFBCD_DEBUG_REG0_hfbcd_debug_reg0_START (0)
#define SOC_MediaCommon_HFBCD_DEBUG_REG0_hfbcd_debug_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_monitor_reg4 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_MONTIOR_REG4_UNION;
#endif
#define SOC_MediaCommon_AFBCD_MONTIOR_REG4_afbcd_monitor_reg4_START (0)
#define SOC_MediaCommon_AFBCD_MONTIOR_REG4_afbcd_monitor_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbcd_monitor_reg5 : 32;
    } reg;
} SOC_MediaCommon_AFBCD_MONTIOR_REG5_UNION;
#endif
#define SOC_MediaCommon_AFBCD_MONTIOR_REG5_afbcd_monitor_reg5_START (0)
#define SOC_MediaCommon_AFBCD_MONTIOR_REG5_afbcd_monitor_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_monitor_reg4 : 32;
    } reg;
} SOC_MediaCommon_HFBCD_MONTIOR_REG4_UNION;
#endif
#define SOC_MediaCommon_HFBCD_MONTIOR_REG4_hfbcd_monitor_reg4_START (0)
#define SOC_MediaCommon_HFBCD_MONTIOR_REG4_hfbcd_monitor_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbcd_monitor_reg5 : 32;
    } reg;
} SOC_MediaCommon_HFBCD_MONTIOR_REG5_UNION;
#endif
#define SOC_MediaCommon_HFBCD_MONTIOR_REG5_hfbcd_monitor_reg5_START (0)
#define SOC_MediaCommon_HFBCD_MONTIOR_REG5_hfbcd_monitor_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr_ext0 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_DMA_ADDR_EXT_UNION;
#endif
#define SOC_MediaCommon_DMA_ADDR_EXT_dma_addr_ext0_START (0)
#define SOC_MediaCommon_DMA_ADDR_EXT_dma_addr_ext0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_hdr_ptr_0 : 32;
    } reg;
} SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_UNION;
#endif
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_hebc_hdr_ptr_0_START (0)
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_hebc_hdr_ptr_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_MediaCommon_HEBC_HREG_PIC_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_MediaCommon_HEBC_HREG_PIC_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_bottom_crop_num : 8;
        unsigned int hebc_top_crop_num : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_HEBC_LINE_CROP_UNION;
#endif
#define SOC_MediaCommon_HEBC_LINE_CROP_hebc_bottom_crop_num_START (0)
#define SOC_MediaCommon_HEBC_LINE_CROP_hebc_bottom_crop_num_END (7)
#define SOC_MediaCommon_HEBC_LINE_CROP_hebc_top_crop_num_START (8)
#define SOC_MediaCommon_HEBC_LINE_CROP_hebc_top_crop_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_header_stride_0 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_UNION;
#endif
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_hebc_header_stride_0_START (0)
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_hebc_header_stride_0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 20;
        unsigned int reserved_1: 12;
    } reg;
} SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_mm_base_0 : 32;
    } reg;
} SOC_MediaCommon_HEBC_MM_BASE_UNION;
#endif
#define SOC_MediaCommon_HEBC_MM_BASE_hebc_mm_base_0_START (0)
#define SOC_MediaCommon_HEBC_MM_BASE_hebc_mm_base_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MediaCommon_HEBC_PAYLOAD_POINTER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_mmrd_os : 4;
        unsigned int hebc_mmwr_os : 4;
        unsigned int hebc_ddrr_os : 6;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 6;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_MediaCommon_HEBC_OS_CFG_UNION;
#endif
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_mmrd_os_START (0)
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_mmrd_os_END (3)
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_mmwr_os_START (4)
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_mmwr_os_END (7)
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_ddrr_os_START (8)
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_ddrr_os_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_scramble_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_HEBC_SCRAMBLE_MODE_UNION;
#endif
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_hebc_scramble_mode_START (0)
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_hebc_scramble_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_UNION;
#endif
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_hebc_mode_START (0)
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_hebc_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value0 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE0_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE0_hebc_tag_value0_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE0_hebc_tag_value0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value1 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE1_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE1_hebc_tag_value1_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE1_hebc_tag_value1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value2 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE2_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE2_hebc_tag_value2_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE2_hebc_tag_value2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value3 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE3_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE3_hebc_tag_value3_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE3_hebc_tag_value3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved0 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED0_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED0_hebc_reserved0_START (0)
#define SOC_MediaCommon_HEBC_RESERVED0_hebc_reserved0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved1 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED1_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED1_hebc_reserved1_START (0)
#define SOC_MediaCommon_HEBC_RESERVED1_hebc_reserved1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved2 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED2_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED2_hebc_reserved2_START (0)
#define SOC_MediaCommon_HEBC_RESERVED2_hebc_reserved2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved3 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED3_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED3_hebc_reserved3_START (0)
#define SOC_MediaCommon_HEBC_RESERVED3_hebc_reserved3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_hdr_ptr_1 : 32;
    } reg;
} SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_UNION;
#endif
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_hebc_hdr_ptr_1_START (0)
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_hebc_hdr_ptr_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MediaCommon_HEBC_HREG_PLD_PTR_LO_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_header_stride_1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_UNION;
#endif
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_hebc_header_stride_1_START (0)
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_hebc_header_stride_1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 20;
        unsigned int reserved_1: 12;
    } reg;
} SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_color_transform : 1;
        unsigned int hebc_blk4x4_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_HEBC_HREG_FORMAT_UNION;
#endif
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_color_transform_START (0)
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_color_transform_END (0)
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_blk4x4_en_START (1)
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_blk4x4_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_mm_base_1 : 32;
    } reg;
} SOC_MediaCommon_HEBC_MM_BASE_1_UNION;
#endif
#define SOC_MediaCommon_HEBC_MM_BASE_1_hebc_mm_base_1_START (0)
#define SOC_MediaCommon_HEBC_MM_BASE_1_hebc_mm_base_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_REG_DEFAULT_UNION;
#endif
#define SOC_MediaCommon_REG_DEFAULT_reg_default_START (0)
#define SOC_MediaCommon_REG_DEFAULT_reg_default_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_ISPIF_EN_UNION;
#endif
#define SOC_MediaCommon_ISPIF_EN_ispif_en_START (0)
#define SOC_MediaCommon_ISPIF_EN_ispif_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_clk_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_ISPIF_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_ISPIF_CLK_SEL_ispif_clk_sel_START (0)
#define SOC_MediaCommon_ISPIF_CLK_SEL_ispif_clk_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_clk_en : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_ISPIF_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_ISPIF_CLK_EN_ispif_clk_en_START (0)
#define SOC_MediaCommon_ISPIF_CLK_EN_ispif_clk_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_in_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int ispif_in_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_ISPIF_IN_SIZE_UNION;
#endif
#define SOC_MediaCommon_ISPIF_IN_SIZE_ispif_in_height_START (0)
#define SOC_MediaCommon_ISPIF_IN_SIZE_ispif_in_height_END (12)
#define SOC_MediaCommon_ISPIF_IN_SIZE_ispif_in_width_START (16)
#define SOC_MediaCommon_ISPIF_IN_SIZE_ispif_in_width_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_ISPIF_RD_SHADOW_UNION;
#endif
#define SOC_MediaCommon_ISPIF_RD_SHADOW_ispif_rd_shadow_START (0)
#define SOC_MediaCommon_ISPIF_RD_SHADOW_ispif_rd_shadow_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_dbg0 : 32;
    } reg;
} SOC_MediaCommon_ISPIF_DBG0_UNION;
#endif
#define SOC_MediaCommon_ISPIF_DBG0_ispif_dbg0_START (0)
#define SOC_MediaCommon_ISPIF_DBG0_ispif_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_dbg1 : 32;
    } reg;
} SOC_MediaCommon_ISPIF_DBG1_UNION;
#endif
#define SOC_MediaCommon_ISPIF_DBG1_ispif_dbg1_START (0)
#define SOC_MediaCommon_ISPIF_DBG1_ispif_dbg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_dbg2 : 32;
    } reg;
} SOC_MediaCommon_ISPIF_DBG2_UNION;
#endif
#define SOC_MediaCommon_ISPIF_DBG2_ispif_dbg2_START (0)
#define SOC_MediaCommon_ISPIF_DBG2_ispif_dbg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ispif_dbg3 : 32;
    } reg;
} SOC_MediaCommon_ISPIF_DBG3_UNION;
#endif
#define SOC_MediaCommon_ISPIF_DBG3_ispif_dbg3_START (0)
#define SOC_MediaCommon_ISPIF_DBG3_ispif_dbg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int dfc_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_DFC_DISP_SIZE_UNION;
#endif
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_vrt_START (0)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_vrt_END (12)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_hrz_START (16)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_hrz_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_pix_in_num : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_PIX_IN_NUM_UNION;
#endif
#define SOC_MediaCommon_DFC_PIX_IN_NUM_dfc_pix_in_num_START (0)
#define SOC_MediaCommon_DFC_PIX_IN_NUM_dfc_pix_in_num_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MediaCommon_DFC_GLB_ALPHA01_UNION;
#endif
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha1_START (0)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha1_END (9)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha0_START (16)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ax_swap : 1;
        unsigned int dfc_img_fmt : 5;
        unsigned int dfc_uv_swap : 1;
        unsigned int dfc_rb_swap : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_DFC_DISP_FMT_UNION;
#endif
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_ax_swap_START (0)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_ax_swap_END (0)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_img_fmt_START (1)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_img_fmt_END (5)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_uv_swap_START (6)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_uv_swap_END (6)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_rb_swap_START (7)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_rb_swap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_right_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_left_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_DFC_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_right_clip_START (0)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_right_clip_END (5)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_left_clip_START (16)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_left_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_bot_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_top_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_DFC_CLIP_CTL_VRZ_UNION;
#endif
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_bot_clip_START (0)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_bot_clip_END (5)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_top_clip_START (16)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_top_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ctl_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_CTL_CLIP_EN_UNION;
#endif
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_START (0)
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_MODULE_EN_UNION;
#endif
#define SOC_MediaCommon_DFC_MODULE_EN_dfc_module_en_START (0)
#define SOC_MediaCommon_DFC_MODULE_EN_dfc_module_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_dither_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_DITHER_ENABLE_UNION;
#endif
#define SOC_MediaCommon_DFC_DITHER_ENABLE_dfc_dither_en_START (0)
#define SOC_MediaCommon_DFC_DITHER_ENABLE_dfc_dither_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_left_pad : 6;
        unsigned int reserved_0 : 2;
        unsigned int dfc_right_pad : 6;
        unsigned int reserved_1 : 2;
        unsigned int dfc_top_pad : 6;
        unsigned int reserved_2 : 2;
        unsigned int dfc_bot_pad : 6;
        unsigned int reserved_3 : 1;
        unsigned int dfc_ctl_pad_enable : 1;
    } reg;
} SOC_MediaCommon_DFC_PADDING_CTL_UNION;
#endif
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_left_pad_START (0)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_left_pad_END (5)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_right_pad_START (8)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_right_pad_END (13)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_top_pad_START (16)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_top_pad_END (21)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_bot_pad_START (24)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_bot_pad_END (29)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_ctl_pad_enable_START (31)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_ctl_pad_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MediaCommon_DFC_GLB_ALPHA23_UNION;
#endif
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha3_START (0)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha3_END (9)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha2_START (16)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_en : 1;
        unsigned int bitext_rgb_en : 1;
        unsigned int bitext_alpha_en : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_BITEXT_CTL_UNION;
#endif
#define SOC_MediaCommon_BITEXT_CTL_bitext_en_START (0)
#define SOC_MediaCommon_BITEXT_CTL_bitext_en_END (0)
#define SOC_MediaCommon_BITEXT_CTL_bitext_rgb_en_START (1)
#define SOC_MediaCommon_BITEXT_CTL_bitext_rgb_en_END (1)
#define SOC_MediaCommon_BITEXT_CTL_bitext_alpha_en_START (2)
#define SOC_MediaCommon_BITEXT_CTL_bitext_alpha_en_END (2)
#define SOC_MediaCommon_BITEXT_CTL_bitext_reg_ini_cfg_en_START (3)
#define SOC_MediaCommon_BITEXT_CTL_bitext_reg_ini_cfg_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_0_bitext_reg_ini0_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_0_bitext_reg_ini0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_1_bitext_reg_ini0_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_1_bitext_reg_ini0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_2_bitext_reg_ini0_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_2_bitext_reg_ini0_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_3_bitext_reg_ini0_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_3_bitext_reg_ini0_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_0_bitext_reg_ini1_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_0_bitext_reg_ini1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_1_bitext_reg_ini1_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_1_bitext_reg_ini1_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_2_bitext_reg_ini1_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_2_bitext_reg_ini1_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_3_bitext_reg_ini1_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_3_bitext_reg_ini1_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_0_bitext_reg_ini2_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_0_bitext_reg_ini2_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_1_bitext_reg_ini2_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_1_bitext_reg_ini2_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_2_bitext_reg_ini2_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_2_bitext_reg_ini2_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_3_bitext_reg_ini2_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_3_bitext_reg_ini2_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_BITEXT_POWER_CTRL_C_UNION;
#endif
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_bitext_power_ctrl_c_START (0)
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_bitext_power_ctrl_c_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_bitext_power_ctrl_shift_START (0)
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_bitext_power_ctrl_shift_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_00_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_00_bitext_filt_00_START (0)
#define SOC_MediaCommon_BITEXT_FILT_00_bitext_filt_00_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_01_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_01_bitext_filt_01_START (0)
#define SOC_MediaCommon_BITEXT_FILT_01_bitext_filt_01_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_02_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_02_bitext_filt_02_START (0)
#define SOC_MediaCommon_BITEXT_FILT_02_bitext_filt_02_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_10_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_10_bitext_filt_10_START (0)
#define SOC_MediaCommon_BITEXT_FILT_10_bitext_filt_10_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_11_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_11_bitext_filt_11_START (0)
#define SOC_MediaCommon_BITEXT_FILT_11_bitext_filt_11_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_12_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_12_bitext_filt_12_START (0)
#define SOC_MediaCommon_BITEXT_FILT_12_bitext_filt_12_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_20_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_20_bitext_filt_20_START (0)
#define SOC_MediaCommon_BITEXT_FILT_20_bitext_filt_20_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_21_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_21_bitext_filt_21_START (0)
#define SOC_MediaCommon_BITEXT_FILT_21_bitext_filt_21_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_22_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_22_bitext_filt_22_START (0)
#define SOC_MediaCommon_BITEXT_FILT_22_bitext_filt_22_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_R0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_R0_bitext_thd_r0_START (0)
#define SOC_MediaCommon_BITEXT_THD_R0_bitext_thd_r0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_R1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_R1_bitext_thd_r1_START (0)
#define SOC_MediaCommon_BITEXT_THD_R1_bitext_thd_r1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_G0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_G0_bitext_thd_g0_START (0)
#define SOC_MediaCommon_BITEXT_THD_G0_bitext_thd_g0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_G1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_G1_bitext_thd_g1_START (0)
#define SOC_MediaCommon_BITEXT_THD_G1_bitext_thd_g1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_B0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_B0_bitext_thd_b0_START (0)
#define SOC_MediaCommon_BITEXT_THD_B0_bitext_thd_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_B1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_B1_bitext_thd_b1_START (0)
#define SOC_MediaCommon_BITEXT_THD_B1_bitext_thd_b1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_dbg0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT0_DBG0_UNION;
#endif
#define SOC_MediaCommon_BITEXT0_DBG0_bitext_dbg0_START (0)
#define SOC_MediaCommon_BITEXT0_DBG0_bitext_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_REG_DEFAULT_UNION;
#endif
#define SOC_MediaCommon_REG_DEFAULT_reg_default_START (0)
#define SOC_MediaCommon_REG_DEFAULT_reg_default_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_x0 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_DMA_OFT_X0_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_X0_dma_oft_x0_START (0)
#define SOC_MediaCommon_DMA_OFT_X0_dma_oft_x0_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_y0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_DMA_OFT_Y0_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_Y0_dma_oft_y0_START (0)
#define SOC_MediaCommon_DMA_OFT_Y0_dma_oft_y0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_x1 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_DMA_OFT_X1_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_X1_dma_oft_x1_START (0)
#define SOC_MediaCommon_DMA_OFT_X1_dma_oft_x1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_oft_y1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_DMA_OFT_Y1_UNION;
#endif
#define SOC_MediaCommon_DMA_OFT_Y1_dma_oft_y1_START (0)
#define SOC_MediaCommon_DMA_OFT_Y1_dma_oft_y1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_mask_y0 : 16;
        unsigned int dma_mask_x0 : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_MediaCommon_DMA_MASK0_UNION;
#endif
#define SOC_MediaCommon_DMA_MASK0_dma_mask_y0_START (0)
#define SOC_MediaCommon_DMA_MASK0_dma_mask_y0_END (15)
#define SOC_MediaCommon_DMA_MASK0_dma_mask_x0_START (16)
#define SOC_MediaCommon_DMA_MASK0_dma_mask_x0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_mask_y1 : 16;
        unsigned int dma_mask_x1 : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_MediaCommon_DMA_MASK1_UNION;
#endif
#define SOC_MediaCommon_DMA_MASK1_dma_mask_y1_START (0)
#define SOC_MediaCommon_DMA_MASK1_dma_mask_y1_END (15)
#define SOC_MediaCommon_DMA_MASK1_dma_mask_x1_START (16)
#define SOC_MediaCommon_DMA_MASK1_dma_mask_x1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stretch_size_vrt : 13;
        unsigned int dma_line_skip_step : 6;
        unsigned int reserved : 13;
    } reg;
} SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_UNION;
#endif
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_stretch_size_vrt_START (0)
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_stretch_size_vrt_END (12)
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_line_skip_step_START (13)
#define SOC_MediaCommon_DMA_STRETCH_SIZE_VRT_dma_line_skip_step_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_page_8k : 1;
        unsigned int dma_tile_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int dma_pix_fmt : 5;
        unsigned int dma_va_en : 1;
        unsigned int dma_mirror_hrz_en : 1;
        unsigned int dma_mirror_vrt_en : 1;
        unsigned int dma_rot : 1;
        unsigned int dma_stretch_en : 1;
        unsigned int reserved_1 : 4;
        unsigned int dma_mask_en : 1;
        unsigned int dma_phy_scrambl_4 : 1;
        unsigned int dma_phy_scrambl_3 : 1;
        unsigned int dma_phy_scrambl_2 : 1;
        unsigned int dma_phy_scrambl_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dma_cross_128 : 1;
        unsigned int dma_tile_128byte_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 6;
    } reg;
} SOC_MediaCommon_DMA_CTRL_UNION;
#endif
#define SOC_MediaCommon_DMA_CTRL_dma_page_8k_START (0)
#define SOC_MediaCommon_DMA_CTRL_dma_page_8k_END (0)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_en_START (1)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_en_END (1)
#define SOC_MediaCommon_DMA_CTRL_dma_pix_fmt_START (3)
#define SOC_MediaCommon_DMA_CTRL_dma_pix_fmt_END (7)
#define SOC_MediaCommon_DMA_CTRL_dma_va_en_START (8)
#define SOC_MediaCommon_DMA_CTRL_dma_va_en_END (8)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_hrz_en_START (9)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_hrz_en_END (9)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_vrt_en_START (10)
#define SOC_MediaCommon_DMA_CTRL_dma_mirror_vrt_en_END (10)
#define SOC_MediaCommon_DMA_CTRL_dma_rot_START (11)
#define SOC_MediaCommon_DMA_CTRL_dma_rot_END (11)
#define SOC_MediaCommon_DMA_CTRL_dma_stretch_en_START (12)
#define SOC_MediaCommon_DMA_CTRL_dma_stretch_en_END (12)
#define SOC_MediaCommon_DMA_CTRL_dma_mask_en_START (17)
#define SOC_MediaCommon_DMA_CTRL_dma_mask_en_END (17)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_4_START (18)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_4_END (18)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_3_START (19)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_3_END (19)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_2_START (20)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_2_END (20)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_1_START (21)
#define SOC_MediaCommon_DMA_CTRL_dma_phy_scrambl_1_END (21)
#define SOC_MediaCommon_DMA_CTRL_dma_cross_128_START (23)
#define SOC_MediaCommon_DMA_CTRL_dma_cross_128_END (23)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_128byte_en_START (24)
#define SOC_MediaCommon_DMA_CTRL_dma_tile_128byte_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_tile_scrambling_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_TILE_SCRAM_UNION;
#endif
#define SOC_MediaCommon_DMA_TILE_SCRAM_dma_tile_scrambling_en_START (0)
#define SOC_MediaCommon_DMA_TILE_SCRAM_dma_tile_scrambling_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_pulse : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_PULSE_UNION;
#endif
#define SOC_MediaCommon_DMA_PULSE_dma_pulse_START (0)
#define SOC_MediaCommon_DMA_PULSE_dma_pulse_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rwch_cfg0 : 32;
    } reg;
} SOC_MediaCommon_RWCH_CFG0_UNION;
#endif
#define SOC_MediaCommon_RWCH_CFG0_rwch_cfg0_START (0)
#define SOC_MediaCommon_RWCH_CFG0_rwch_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_fifo_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_FIFO_CLR_UNION;
#endif
#define SOC_MediaCommon_DMA_FIFO_CLR_dma_fifo_clr_START (0)
#define SOC_MediaCommon_DMA_FIFO_CLR_dma_fifo_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_counter_en : 1;
        unsigned int dma_counter_inc_cnum : 4;
        unsigned int dma_counter_rst_cnum : 4;
        unsigned int wch_enc_slice_h : 8;
        unsigned int wch_enc_space : 4;
        unsigned int reserved : 11;
    } reg;
} SOC_MediaCommon_DMA_COUNTER_DGB_UNION;
#endif
#define SOC_MediaCommon_DMA_COUNTER_DGB_dma_counter_en_START (0)
#define SOC_MediaCommon_DMA_COUNTER_DGB_dma_counter_en_END (0)
#define SOC_MediaCommon_DMA_COUNTER_DGB_dma_counter_inc_cnum_START (1)
#define SOC_MediaCommon_DMA_COUNTER_DGB_dma_counter_inc_cnum_END (4)
#define SOC_MediaCommon_DMA_COUNTER_DGB_dma_counter_rst_cnum_START (5)
#define SOC_MediaCommon_DMA_COUNTER_DGB_dma_counter_rst_cnum_END (8)
#define SOC_MediaCommon_DMA_COUNTER_DGB_wch_enc_slice_h_START (9)
#define SOC_MediaCommon_DMA_COUNTER_DGB_wch_enc_slice_h_END (16)
#define SOC_MediaCommon_DMA_COUNTER_DGB_wch_enc_space_START (17)
#define SOC_MediaCommon_DMA_COUNTER_DGB_wch_enc_space_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_rot_burst4 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_ROT_BURST4_UNION;
#endif
#define SOC_MediaCommon_DMA_ROT_BURST4_dma_rot_burst4_START (0)
#define SOC_MediaCommon_DMA_ROT_BURST4_dma_rot_burst4_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_reload_rsv1_reg : 32;
    } reg;
} SOC_MediaCommon_DMA_RSV1_UNION;
#endif
#define SOC_MediaCommon_DMA_RSV1_dma_reload_rsv1_reg_START (0)
#define SOC_MediaCommon_DMA_RSV1_dma_reload_rsv1_reg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_rsv2_reg : 32;
    } reg;
} SOC_MediaCommon_DMA_RSV2_UNION;
#endif
#define SOC_MediaCommon_DMA_RSV2_dma_rsv2_reg_START (0)
#define SOC_MediaCommon_DMA_RSV2_dma_rsv2_reg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_sw_mask_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_SW_MASK_EN_UNION;
#endif
#define SOC_MediaCommon_DMA_SW_MASK_EN_dma_sw_mask_en_START (0)
#define SOC_MediaCommon_DMA_SW_MASK_EN_dma_sw_mask_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_start_mask0 : 32;
    } reg;
} SOC_MediaCommon_DMA_START_MASK0_UNION;
#endif
#define SOC_MediaCommon_DMA_START_MASK0_dma_start_mask0_START (0)
#define SOC_MediaCommon_DMA_START_MASK0_dma_start_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_end_mask0 : 32;
    } reg;
} SOC_MediaCommon_DMA_END_MASK0_UNION;
#endif
#define SOC_MediaCommon_DMA_END_MASK0_dma_end_mask0_START (0)
#define SOC_MediaCommon_DMA_END_MASK0_dma_end_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_start_mask1 : 32;
    } reg;
} SOC_MediaCommon_DMA_START_MASK1_UNION;
#endif
#define SOC_MediaCommon_DMA_START_MASK1_dma_start_mask1_START (0)
#define SOC_MediaCommon_DMA_START_MASK1_dma_start_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_end_mask1 : 32;
    } reg;
} SOC_MediaCommon_DMA_END_MASK1_UNION;
#endif
#define SOC_MediaCommon_DMA_END_MASK1_dma_end_mask1_START (0)
#define SOC_MediaCommon_DMA_END_MASK1_dma_end_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr0 : 32;
    } reg;
} SOC_MediaCommon_DMA_DATA_ADDR0_UNION;
#endif
#define SOC_MediaCommon_DMA_DATA_ADDR0_dma_addr0_START (0)
#define SOC_MediaCommon_DMA_DATA_ADDR0_dma_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stride0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int dma_l2t_interleave_n0 : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_MediaCommon_DMA_STRIDE0_UNION;
#endif
#define SOC_MediaCommon_DMA_STRIDE0_dma_stride0_START (0)
#define SOC_MediaCommon_DMA_STRIDE0_dma_stride0_END (12)
#define SOC_MediaCommon_DMA_STRIDE0_dma_l2t_interleave_n0_START (16)
#define SOC_MediaCommon_DMA_STRIDE0_dma_l2t_interleave_n0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stretch_stride0 : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_MediaCommon_DMA_STRETCH_STRIDE0_UNION;
#endif
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_dma_stretch_stride0_START (0)
#define SOC_MediaCommon_DMA_STRETCH_STRIDE0_dma_stretch_stride0_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_data_num0 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DMA_DATA_NUM0_UNION;
#endif
#define SOC_MediaCommon_DMA_DATA_NUM0_dma_data_num0_START (0)
#define SOC_MediaCommon_DMA_DATA_NUM0_dma_data_num0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test0_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST0_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST0_dma_test0_y_START (0)
#define SOC_MediaCommon_DMA_TEST0_dma_test0_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test1_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST1_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST1_dma_test1_y_START (0)
#define SOC_MediaCommon_DMA_TEST1_dma_test1_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test3_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST3_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST3_dma_test3_y_START (0)
#define SOC_MediaCommon_DMA_TEST3_dma_test3_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test4_y : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST4_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST4_dma_test4_y_START (0)
#define SOC_MediaCommon_DMA_TEST4_dma_test4_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status_y : 32;
    } reg;
} SOC_MediaCommon_DMA_STATUS_Y_UNION;
#endif
#define SOC_MediaCommon_DMA_STATUS_Y_dma_status_y_START (0)
#define SOC_MediaCommon_DMA_STATUS_Y_dma_status_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr1 : 32;
    } reg;
} SOC_MediaCommon_DMA_DATA_ADDR1_UNION;
#endif
#define SOC_MediaCommon_DMA_DATA_ADDR1_dma_addr1_START (0)
#define SOC_MediaCommon_DMA_DATA_ADDR1_dma_addr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stride1 : 13;
        unsigned int reserved_0 : 3;
        unsigned int dma_l2t_interleave_n1 : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_MediaCommon_DMA_STRIDE1_UNION;
#endif
#define SOC_MediaCommon_DMA_STRIDE1_dma_stride1_START (0)
#define SOC_MediaCommon_DMA_STRIDE1_dma_stride1_END (12)
#define SOC_MediaCommon_DMA_STRIDE1_dma_l2t_interleave_n1_START (16)
#define SOC_MediaCommon_DMA_STRIDE1_dma_l2t_interleave_n1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stretch_stride1 : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_MediaCommon_DMA_STRETCH_STRIDE1_UNION;
#endif
#define SOC_MediaCommon_DMA_STRETCH_STRIDE1_dma_stretch_stride1_START (0)
#define SOC_MediaCommon_DMA_STRETCH_STRIDE1_dma_stretch_stride1_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_data_num1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DMA_DATA_NUM1_UNION;
#endif
#define SOC_MediaCommon_DMA_DATA_NUM1_dma_data_num1_START (0)
#define SOC_MediaCommon_DMA_DATA_NUM1_dma_data_num1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test0_u : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST0_U_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST0_U_dma_test0_u_START (0)
#define SOC_MediaCommon_DMA_TEST0_U_dma_test0_u_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test1_u : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST1_U_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST1_U_dma_test1_u_START (0)
#define SOC_MediaCommon_DMA_TEST1_U_dma_test1_u_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test3_u : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST3_U_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST3_U_dma_test3_u_START (0)
#define SOC_MediaCommon_DMA_TEST3_U_dma_test3_u_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_test4_u : 32;
    } reg;
} SOC_MediaCommon_DMA_TEST4_U_UNION;
#endif
#define SOC_MediaCommon_DMA_TEST4_U_dma_test4_u_START (0)
#define SOC_MediaCommon_DMA_TEST4_U_dma_test4_u_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_status_u : 32;
    } reg;
} SOC_MediaCommon_DMA_STATUS_U_UNION;
#endif
#define SOC_MediaCommon_DMA_STATUS_U_dma_status_u_START (0)
#define SOC_MediaCommon_DMA_STATUS_U_dma_status_u_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rwch_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CH_RD_SHADOW_UNION;
#endif
#define SOC_MediaCommon_CH_RD_SHADOW_rwch_rd_shadow_START (0)
#define SOC_MediaCommon_CH_RD_SHADOW_rwch_rd_shadow_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_en : 1;
        unsigned int ch_version_sel : 1;
        unsigned int ch_afbce_en : 1;
        unsigned int ch_block_en : 1;
        unsigned int ch_last_block : 1;
        unsigned int reserved_0 : 2;
        unsigned int ch_hebc_en : 1;
        unsigned int ch_dmac_en : 1;
        unsigned int reserved_1 : 7;
        unsigned int ch_segment_h : 16;
    } reg;
} SOC_MediaCommon_CH_CTL_UNION;
#endif
#define SOC_MediaCommon_CH_CTL_ch_en_START (0)
#define SOC_MediaCommon_CH_CTL_ch_en_END (0)
#define SOC_MediaCommon_CH_CTL_ch_version_sel_START (1)
#define SOC_MediaCommon_CH_CTL_ch_version_sel_END (1)
#define SOC_MediaCommon_CH_CTL_ch_afbce_en_START (2)
#define SOC_MediaCommon_CH_CTL_ch_afbce_en_END (2)
#define SOC_MediaCommon_CH_CTL_ch_block_en_START (3)
#define SOC_MediaCommon_CH_CTL_ch_block_en_END (3)
#define SOC_MediaCommon_CH_CTL_ch_last_block_START (4)
#define SOC_MediaCommon_CH_CTL_ch_last_block_END (4)
#define SOC_MediaCommon_CH_CTL_ch_hebc_en_START (7)
#define SOC_MediaCommon_CH_CTL_ch_hebc_en_END (7)
#define SOC_MediaCommon_CH_CTL_ch_dmac_en_START (8)
#define SOC_MediaCommon_CH_CTL_ch_dmac_en_END (8)
#define SOC_MediaCommon_CH_CTL_ch_segment_h_START (16)
#define SOC_MediaCommon_CH_CTL_ch_segment_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_secu_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CH_SECU_EN_UNION;
#endif
#define SOC_MediaCommon_CH_SECU_EN_ch_secu_en_START (0)
#define SOC_MediaCommon_CH_SECU_EN_ch_secu_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_sw_end_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CH_SW_END_REQ_UNION;
#endif
#define SOC_MediaCommon_CH_SW_END_REQ_ch_sw_end_req_START (0)
#define SOC_MediaCommon_CH_SW_END_REQ_ch_sw_end_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_sel : 32;
    } reg;
} SOC_MediaCommon_CH_CLK_SEL_UNION;
#endif
#define SOC_MediaCommon_CH_CLK_SEL_ch_clk_sel_START (0)
#define SOC_MediaCommon_CH_CLK_SEL_ch_clk_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_en : 32;
    } reg;
} SOC_MediaCommon_CH_CLK_EN_UNION;
#endif
#define SOC_MediaCommon_CH_CLK_EN_ch_clk_en_START (0)
#define SOC_MediaCommon_CH_CLK_EN_ch_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg0 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG0_UNION;
#endif
#define SOC_MediaCommon_CH_DBG0_ch_dbg0_START (0)
#define SOC_MediaCommon_CH_DBG0_ch_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg1 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG1_UNION;
#endif
#define SOC_MediaCommon_CH_DBG1_ch_dbg1_START (0)
#define SOC_MediaCommon_CH_DBG1_ch_dbg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg2 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG2_UNION;
#endif
#define SOC_MediaCommon_CH_DBG2_ch_dbg2_START (0)
#define SOC_MediaCommon_CH_DBG2_ch_dbg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg3 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG3_UNION;
#endif
#define SOC_MediaCommon_CH_DBG3_ch_dbg3_START (0)
#define SOC_MediaCommon_CH_DBG3_ch_dbg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg4 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG4_UNION;
#endif
#define SOC_MediaCommon_CH_DBG4_ch_dbg4_START (0)
#define SOC_MediaCommon_CH_DBG4_ch_dbg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg5 : 32;
    } reg;
} SOC_MediaCommon_CH_DBG5_UNION;
#endif
#define SOC_MediaCommon_CH_DBG5_ch_dbg5_START (0)
#define SOC_MediaCommon_CH_DBG5_ch_dbg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int dfc_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_DFC_DISP_SIZE_UNION;
#endif
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_vrt_START (0)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_vrt_END (12)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_hrz_START (16)
#define SOC_MediaCommon_DFC_DISP_SIZE_dfc_size_hrz_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_pix_in_num : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_PIX_IN_NUM_UNION;
#endif
#define SOC_MediaCommon_DFC_PIX_IN_NUM_dfc_pix_in_num_START (0)
#define SOC_MediaCommon_DFC_PIX_IN_NUM_dfc_pix_in_num_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MediaCommon_DFC_GLB_ALPHA01_UNION;
#endif
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha1_START (0)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha1_END (9)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha0_START (16)
#define SOC_MediaCommon_DFC_GLB_ALPHA01_dfc_glb_alpha0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ax_swap : 1;
        unsigned int dfc_img_fmt : 5;
        unsigned int dfc_uv_swap : 1;
        unsigned int dfc_rb_swap : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_DFC_DISP_FMT_UNION;
#endif
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_ax_swap_START (0)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_ax_swap_END (0)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_img_fmt_START (1)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_img_fmt_END (5)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_uv_swap_START (6)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_uv_swap_END (6)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_rb_swap_START (7)
#define SOC_MediaCommon_DFC_DISP_FMT_dfc_rb_swap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_right_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_left_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_DFC_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_right_clip_START (0)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_right_clip_END (5)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_left_clip_START (16)
#define SOC_MediaCommon_DFC_CLIP_CTL_HRZ_dfc_left_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_bot_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_top_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_DFC_CLIP_CTL_VRZ_UNION;
#endif
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_bot_clip_START (0)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_bot_clip_END (5)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_top_clip_START (16)
#define SOC_MediaCommon_DFC_CLIP_CTL_VRZ_dfc_top_clip_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ctl_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_CTL_CLIP_EN_UNION;
#endif
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_START (0)
#define SOC_MediaCommon_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_ICG_MODULE_UNION;
#endif
#define SOC_MediaCommon_DFC_ICG_MODULE_dfc_module_en_START (0)
#define SOC_MediaCommon_DFC_ICG_MODULE_dfc_module_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_dither_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DFC_DITHER_ENABLE_UNION;
#endif
#define SOC_MediaCommon_DFC_DITHER_ENABLE_dfc_dither_en_START (0)
#define SOC_MediaCommon_DFC_DITHER_ENABLE_dfc_dither_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_left_pad : 6;
        unsigned int reserved_0 : 2;
        unsigned int dfc_right_pad : 6;
        unsigned int reserved_1 : 2;
        unsigned int dfc_top_pad : 6;
        unsigned int reserved_2 : 2;
        unsigned int dfc_bot_pad : 6;
        unsigned int reserved_3 : 1;
        unsigned int dfc_ctl_pad_enable : 1;
    } reg;
} SOC_MediaCommon_DFC_PADDING_CTL_UNION;
#endif
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_left_pad_START (0)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_left_pad_END (5)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_right_pad_START (8)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_right_pad_END (13)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_top_pad_START (16)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_top_pad_END (21)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_bot_pad_START (24)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_bot_pad_END (29)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_ctl_pad_enable_START (31)
#define SOC_MediaCommon_DFC_PADDING_CTL_dfc_ctl_pad_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MediaCommon_DFC_GLB_ALPHA23_UNION;
#endif
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha3_START (0)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha3_END (9)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha2_START (16)
#define SOC_MediaCommon_DFC_GLB_ALPHA23_dfc_glb_alpha2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int dfc_glb_alpha : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_MediaCommon_DFC_GLB_ALPHA_UNION;
#endif
#define SOC_MediaCommon_DFC_GLB_ALPHA_dfc_glb_alpha_START (16)
#define SOC_MediaCommon_DFC_GLB_ALPHA_dfc_glb_alpha_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_alpha_handle_mode : 2;
        unsigned int bayer_alpha_shift_mode : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_DFC_ALPHA_CTL_UNION;
#endif
#define SOC_MediaCommon_DFC_ALPHA_CTL_bayer_alpha_handle_mode_START (0)
#define SOC_MediaCommon_DFC_ALPHA_CTL_bayer_alpha_handle_mode_END (1)
#define SOC_MediaCommon_DFC_ALPHA_CTL_bayer_alpha_shift_mode_START (2)
#define SOC_MediaCommon_DFC_ALPHA_CTL_bayer_alpha_shift_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_alpha_thd : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DFC_ALPHA_THD_UNION;
#endif
#define SOC_MediaCommon_DFC_ALPHA_THD_bayer_alpha_thd_START (0)
#define SOC_MediaCommon_DFC_ALPHA_THD_bayer_alpha_thd_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_en : 1;
        unsigned int bitext_rgb_en : 1;
        unsigned int bitext_alpha_en : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_BITEXT_CTL_UNION;
#endif
#define SOC_MediaCommon_BITEXT_CTL_bitext_en_START (0)
#define SOC_MediaCommon_BITEXT_CTL_bitext_en_END (0)
#define SOC_MediaCommon_BITEXT_CTL_bitext_rgb_en_START (1)
#define SOC_MediaCommon_BITEXT_CTL_bitext_rgb_en_END (1)
#define SOC_MediaCommon_BITEXT_CTL_bitext_alpha_en_START (2)
#define SOC_MediaCommon_BITEXT_CTL_bitext_alpha_en_END (2)
#define SOC_MediaCommon_BITEXT_CTL_bitext_reg_ini_cfg_en_START (3)
#define SOC_MediaCommon_BITEXT_CTL_bitext_reg_ini_cfg_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_0_bitext_reg_ini0_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_0_bitext_reg_ini0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_1_bitext_reg_ini0_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_1_bitext_reg_ini0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_2_bitext_reg_ini0_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_2_bitext_reg_ini0_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI0_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI0_3_bitext_reg_ini0_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI0_3_bitext_reg_ini0_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_0_bitext_reg_ini1_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_0_bitext_reg_ini1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_1_bitext_reg_ini1_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_1_bitext_reg_ini1_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_2_bitext_reg_ini1_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_2_bitext_reg_ini1_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI1_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI1_3_bitext_reg_ini1_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI1_3_bitext_reg_ini1_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_0_bitext_reg_ini2_0_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_0_bitext_reg_ini2_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_1_bitext_reg_ini2_1_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_1_bitext_reg_ini2_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_2_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_2_bitext_reg_ini2_2_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_2_bitext_reg_ini2_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_MediaCommon_BITEXT_REG_INI2_3_UNION;
#endif
#define SOC_MediaCommon_BITEXT_REG_INI2_3_bitext_reg_ini2_3_START (0)
#define SOC_MediaCommon_BITEXT_REG_INI2_3_bitext_reg_ini2_3_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_BITEXT_POWER_CTRL_C_UNION;
#endif
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_bitext_power_ctrl_c_START (0)
#define SOC_MediaCommon_BITEXT_POWER_CTRL_C_bitext_power_ctrl_c_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_bitext_power_ctrl_shift_START (0)
#define SOC_MediaCommon_BITEXT_POWER_CTRL_SHIFT_bitext_power_ctrl_shift_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_00_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_00_bitext_filt_00_START (0)
#define SOC_MediaCommon_BITEXT_FILT_00_bitext_filt_00_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_01_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_01_bitext_filt_01_START (0)
#define SOC_MediaCommon_BITEXT_FILT_01_bitext_filt_01_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_02_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_02_bitext_filt_02_START (0)
#define SOC_MediaCommon_BITEXT_FILT_02_bitext_filt_02_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_10_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_10_bitext_filt_10_START (0)
#define SOC_MediaCommon_BITEXT_FILT_10_bitext_filt_10_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_11_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_11_bitext_filt_11_START (0)
#define SOC_MediaCommon_BITEXT_FILT_11_bitext_filt_11_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_12_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_12_bitext_filt_12_START (0)
#define SOC_MediaCommon_BITEXT_FILT_12_bitext_filt_12_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_20_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_20_bitext_filt_20_START (0)
#define SOC_MediaCommon_BITEXT_FILT_20_bitext_filt_20_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_21_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_21_bitext_filt_21_START (0)
#define SOC_MediaCommon_BITEXT_FILT_21_bitext_filt_21_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_BITEXT_FILT_22_UNION;
#endif
#define SOC_MediaCommon_BITEXT_FILT_22_bitext_filt_22_START (0)
#define SOC_MediaCommon_BITEXT_FILT_22_bitext_filt_22_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_R0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_R0_bitext_thd_r0_START (0)
#define SOC_MediaCommon_BITEXT_THD_R0_bitext_thd_r0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_R1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_R1_bitext_thd_r1_START (0)
#define SOC_MediaCommon_BITEXT_THD_R1_bitext_thd_r1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_G0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_G0_bitext_thd_g0_START (0)
#define SOC_MediaCommon_BITEXT_THD_G0_bitext_thd_g0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_G1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_G1_bitext_thd_g1_START (0)
#define SOC_MediaCommon_BITEXT_THD_G1_bitext_thd_g1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT_THD_B0_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_B0_bitext_thd_b0_START (0)
#define SOC_MediaCommon_BITEXT_THD_B0_bitext_thd_b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MediaCommon_BITEXT_THD_B1_UNION;
#endif
#define SOC_MediaCommon_BITEXT_THD_B1_bitext_thd_b1_START (0)
#define SOC_MediaCommon_BITEXT_THD_B1_bitext_thd_b1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_dbg0 : 32;
    } reg;
} SOC_MediaCommon_BITEXT0_DBG0_UNION;
#endif
#define SOC_MediaCommon_BITEXT0_DBG0_bitext_dbg0_START (0)
#define SOC_MediaCommon_BITEXT0_DBG0_bitext_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dither_en : 1;
        unsigned int dither_hifreq_noise_mode : 2;
        unsigned int dither_rgb_shift_mode : 1;
        unsigned int dither_unifrom_en : 1;
        unsigned int bayer_rgb_en : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_DITHER_CTL1_UNION;
#endif
#define SOC_MediaCommon_DITHER_CTL1_dither_en_START (0)
#define SOC_MediaCommon_DITHER_CTL1_dither_en_END (0)
#define SOC_MediaCommon_DITHER_CTL1_dither_hifreq_noise_mode_START (1)
#define SOC_MediaCommon_DITHER_CTL1_dither_hifreq_noise_mode_END (2)
#define SOC_MediaCommon_DITHER_CTL1_dither_rgb_shift_mode_START (3)
#define SOC_MediaCommon_DITHER_CTL1_dither_rgb_shift_mode_END (3)
#define SOC_MediaCommon_DITHER_CTL1_dither_unifrom_en_START (4)
#define SOC_MediaCommon_DITHER_CTL1_dither_unifrom_en_END (4)
#define SOC_MediaCommon_DITHER_CTL1_bayer_rgb_en_START (5)
#define SOC_MediaCommon_DITHER_CTL1_bayer_rgb_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dither_tri_thd10_b : 10;
        unsigned int dither_tri_thd10_g : 10;
        unsigned int dither_tri_thd10_r : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DITHER_TRI_THD10_UNION;
#endif
#define SOC_MediaCommon_DITHER_TRI_THD10_dither_tri_thd10_b_START (0)
#define SOC_MediaCommon_DITHER_TRI_THD10_dither_tri_thd10_b_END (9)
#define SOC_MediaCommon_DITHER_TRI_THD10_dither_tri_thd10_g_START (10)
#define SOC_MediaCommon_DITHER_TRI_THD10_dither_tri_thd10_g_END (19)
#define SOC_MediaCommon_DITHER_TRI_THD10_dither_tri_thd10_r_START (20)
#define SOC_MediaCommon_DITHER_TRI_THD10_dither_tri_thd10_r_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dither_tri_thd10_uni_b : 10;
        unsigned int dither_tri_thd10_uni_g : 10;
        unsigned int dither_tri_thd10_uni_r : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_DITHER_TRI_THD10_UNI_UNION;
#endif
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_dither_tri_thd10_uni_b_START (0)
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_dither_tri_thd10_uni_b_END (9)
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_dither_tri_thd10_uni_g_START (10)
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_dither_tri_thd10_uni_g_END (19)
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_dither_tri_thd10_uni_r_START (20)
#define SOC_MediaCommon_DITHER_TRI_THD10_UNI_dither_tri_thd10_uni_r_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int bayer_offset : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MediaCommon_BAYER_CTL_UNION;
#endif
#define SOC_MediaCommon_BAYER_CTL_bayer_offset_START (16)
#define SOC_MediaCommon_BAYER_CTL_bayer_offset_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_matrix_part1 : 32;
    } reg;
} SOC_MediaCommon_BAYER_MATRIX_PART1_UNION;
#endif
#define SOC_MediaCommon_BAYER_MATRIX_PART1_bayer_matrix_part1_START (0)
#define SOC_MediaCommon_BAYER_MATRIX_PART1_bayer_matrix_part1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_matrix_part0 : 32;
    } reg;
} SOC_MediaCommon_BAYER_MATRIX_PART0_UNION;
#endif
#define SOC_MediaCommon_BAYER_MATRIX_PART0_bayer_matrix_part0_START (0)
#define SOC_MediaCommon_BAYER_MATRIX_PART0_bayer_matrix_part0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_hscl_str : 1;
        unsigned int scf_en_hscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_SCF_EN_HSCL_STR_UNION;
#endif
#define SOC_MediaCommon_SCF_EN_HSCL_STR_scf_en_hscl_str_START (0)
#define SOC_MediaCommon_SCF_EN_HSCL_STR_scf_en_hscl_str_END (0)
#define SOC_MediaCommon_SCF_EN_HSCL_STR_scf_en_hscl_str_a_START (1)
#define SOC_MediaCommon_SCF_EN_HSCL_STR_scf_en_hscl_str_a_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_vscl_str : 1;
        unsigned int scf_en_vscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_SCF_EN_VSCL_STR_UNION;
#endif
#define SOC_MediaCommon_SCF_EN_VSCL_STR_scf_en_vscl_str_START (0)
#define SOC_MediaCommon_SCF_EN_VSCL_STR_scf_en_vscl_str_END (0)
#define SOC_MediaCommon_SCF_EN_VSCL_STR_scf_en_vscl_str_a_START (1)
#define SOC_MediaCommon_SCF_EN_VSCL_STR_scf_en_vscl_str_a_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_h_v_order : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_SCF_H_V_ORDER_UNION;
#endif
#define SOC_MediaCommon_SCF_H_V_ORDER_scf_h_v_order_START (0)
#define SOC_MediaCommon_SCF_H_V_ORDER_scf_h_v_order_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_a_core_gt : 1;
        unsigned int scf_r_core_gt : 1;
        unsigned int scf_g_core_gt : 1;
        unsigned int scf_b_core_gt : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_SCF_CH_CORE_GT_UNION;
#endif
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_a_core_gt_START (0)
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_a_core_gt_END (0)
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_r_core_gt_START (1)
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_r_core_gt_END (1)
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_g_core_gt_START (2)
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_g_core_gt_END (2)
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_b_core_gt_START (3)
#define SOC_MediaCommon_SCF_CH_CORE_GT_scf_b_core_gt_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_input_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int scf_input_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_SCF_INPUT_WIDTH_HEIGHT_UNION;
#endif
#define SOC_MediaCommon_SCF_INPUT_WIDTH_HEIGHT_scf_input_height_START (0)
#define SOC_MediaCommon_SCF_INPUT_WIDTH_HEIGHT_scf_input_height_END (12)
#define SOC_MediaCommon_SCF_INPUT_WIDTH_HEIGHT_scf_input_width_START (16)
#define SOC_MediaCommon_SCF_INPUT_WIDTH_HEIGHT_scf_input_width_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_output_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int scf_output_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_SCF_OUTPUT_WIDTH_HEIGHT_UNION;
#endif
#define SOC_MediaCommon_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_height_START (0)
#define SOC_MediaCommon_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_height_END (12)
#define SOC_MediaCommon_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_width_START (16)
#define SOC_MediaCommon_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_width_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_hcoef_mem_ctrl : 4;
        unsigned int scf_vcoef_mem_ctrl : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_SCF_COEF_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_SCF_COEF_MEM_CTRL_scf_hcoef_mem_ctrl_START (0)
#define SOC_MediaCommon_SCF_COEF_MEM_CTRL_scf_hcoef_mem_ctrl_END (3)
#define SOC_MediaCommon_SCF_COEF_MEM_CTRL_scf_vcoef_mem_ctrl_START (4)
#define SOC_MediaCommon_SCF_COEF_MEM_CTRL_scf_vcoef_mem_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_hscl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_SCF_EN_HSCL_UNION;
#endif
#define SOC_MediaCommon_SCF_EN_HSCL_scf_en_hscl_en_START (0)
#define SOC_MediaCommon_SCF_EN_HSCL_scf_en_hscl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_vscl_en : 1;
        unsigned int scf_out_buffer_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_SCF_EN_VSCL_UNION;
#endif
#define SOC_MediaCommon_SCF_EN_VSCL_scf_en_vscl_en_START (0)
#define SOC_MediaCommon_SCF_EN_VSCL_scf_en_vscl_en_END (0)
#define SOC_MediaCommon_SCF_EN_VSCL_scf_out_buffer_en_START (1)
#define SOC_MediaCommon_SCF_EN_VSCL_scf_out_buffer_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_hscl : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_SCF_ACC_HSCL_UNION;
#endif
#define SOC_MediaCommon_SCF_ACC_HSCL_scf_acc_hscl_START (0)
#define SOC_MediaCommon_SCF_ACC_HSCL_scf_acc_hscl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_hscl1 : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_MediaCommon_SCF_ACC_HSCL1_UNION;
#endif
#define SOC_MediaCommon_SCF_ACC_HSCL1_scf_acc_hscl1_START (0)
#define SOC_MediaCommon_SCF_ACC_HSCL1_scf_acc_hscl1_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_inc_hscl : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MediaCommon_SCF_INC_HSCL_UNION;
#endif
#define SOC_MediaCommon_SCF_INC_HSCL_scf_inc_hscl_START (0)
#define SOC_MediaCommon_SCF_INC_HSCL_scf_inc_hscl_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_vscl : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_MediaCommon_SCF_ACC_VSCL_UNION;
#endif
#define SOC_MediaCommon_SCF_ACC_VSCL_scf_acc_vscl_START (0)
#define SOC_MediaCommon_SCF_ACC_VSCL_scf_acc_vscl_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_vscl1 : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_MediaCommon_SCF_ACC_VSCL1_UNION;
#endif
#define SOC_MediaCommon_SCF_ACC_VSCL1_scf_acc_vscl1_START (0)
#define SOC_MediaCommon_SCF_ACC_VSCL1_scf_acc_vscl1_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_inc_vscl : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MediaCommon_SCF_INC_VSCL_UNION;
#endif
#define SOC_MediaCommon_SCF_INC_VSCL_scf_inc_vscl_START (0)
#define SOC_MediaCommon_SCF_INC_VSCL_scf_inc_vscl_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_sw_rst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_SCF_EN_NONLINEAR_UNION;
#endif
#define SOC_MediaCommon_SCF_EN_NONLINEAR_scf_sw_rst_START (0)
#define SOC_MediaCommon_SCF_EN_NONLINEAR_scf_sw_rst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_mmp : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_SCF_EN_MMP_UNION;
#endif
#define SOC_MediaCommon_SCF_EN_MMP_scf_en_mmp_START (0)
#define SOC_MediaCommon_SCF_EN_MMP_scf_en_mmp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_h0 : 32;
    } reg;
} SOC_MediaCommon_SCF_DB_H0_UNION;
#endif
#define SOC_MediaCommon_SCF_DB_H0_scf_debug_h0_START (0)
#define SOC_MediaCommon_SCF_DB_H0_scf_debug_h0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_h1 : 32;
    } reg;
} SOC_MediaCommon_SCF_DB_H1_UNION;
#endif
#define SOC_MediaCommon_SCF_DB_H1_scf_debug_h1_START (0)
#define SOC_MediaCommon_SCF_DB_H1_scf_debug_h1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_v0 : 32;
    } reg;
} SOC_MediaCommon_SCF_DB_V0_UNION;
#endif
#define SOC_MediaCommon_SCF_DB_V0_scf_debug_v0_START (0)
#define SOC_MediaCommon_SCF_DB_V0_scf_debug_v0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_v1 : 32;
    } reg;
} SOC_MediaCommon_SCF_DB_V1_UNION;
#endif
#define SOC_MediaCommon_SCF_DB_V1_scf_debug_v1_START (0)
#define SOC_MediaCommon_SCF_DB_V1_scf_debug_v1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_lb_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_SCF_LB_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_SCF_LB_MEM_CTRL_scf_lb_mem_ctrl_START (0)
#define SOC_MediaCommon_SCF_LB_MEM_CTRL_scf_lb_mem_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int pcsc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_MediaCommon_PCSC_IDC0_UNION;
#endif
#define SOC_MediaCommon_PCSC_IDC0_pcsc_idc0_START (0)
#define SOC_MediaCommon_PCSC_IDC0_pcsc_idc0_END (10)
#define SOC_MediaCommon_PCSC_IDC0_pcsc_idc1_START (16)
#define SOC_MediaCommon_PCSC_IDC0_pcsc_idc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_MediaCommon_PCSC_IDC2_UNION;
#endif
#define SOC_MediaCommon_PCSC_IDC2_pcsc_idc2_START (0)
#define SOC_MediaCommon_PCSC_IDC2_pcsc_idc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int pcsc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_MediaCommon_PCSC_ODC0_UNION;
#endif
#define SOC_MediaCommon_PCSC_ODC0_pcsc_odc0_START (0)
#define SOC_MediaCommon_PCSC_ODC0_pcsc_odc0_END (10)
#define SOC_MediaCommon_PCSC_ODC0_pcsc_odc1_START (16)
#define SOC_MediaCommon_PCSC_ODC0_pcsc_odc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_MediaCommon_PCSC_ODC2_UNION;
#endif
#define SOC_MediaCommon_PCSC_ODC2_pcsc_odc2_START (0)
#define SOC_MediaCommon_PCSC_ODC2_pcsc_odc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P00_UNION;
#endif
#define SOC_MediaCommon_PCSC_P00_pcsc_p00_START (0)
#define SOC_MediaCommon_PCSC_P00_pcsc_p00_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P01_UNION;
#endif
#define SOC_MediaCommon_PCSC_P01_pcsc_p01_START (0)
#define SOC_MediaCommon_PCSC_P01_pcsc_p01_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P02_UNION;
#endif
#define SOC_MediaCommon_PCSC_P02_pcsc_p02_START (0)
#define SOC_MediaCommon_PCSC_P02_pcsc_p02_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P10_UNION;
#endif
#define SOC_MediaCommon_PCSC_P10_pcsc_p10_START (0)
#define SOC_MediaCommon_PCSC_P10_pcsc_p10_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P11_UNION;
#endif
#define SOC_MediaCommon_PCSC_P11_pcsc_p11_START (0)
#define SOC_MediaCommon_PCSC_P11_pcsc_p11_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P12_UNION;
#endif
#define SOC_MediaCommon_PCSC_P12_pcsc_p12_START (0)
#define SOC_MediaCommon_PCSC_P12_pcsc_p12_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P20_UNION;
#endif
#define SOC_MediaCommon_PCSC_P20_pcsc_p20_START (0)
#define SOC_MediaCommon_PCSC_P20_pcsc_p20_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P21_UNION;
#endif
#define SOC_MediaCommon_PCSC_P21_pcsc_p21_START (0)
#define SOC_MediaCommon_PCSC_P21_pcsc_p21_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_PCSC_P22_UNION;
#endif
#define SOC_MediaCommon_PCSC_P22_pcsc_p22_START (0)
#define SOC_MediaCommon_PCSC_P22_pcsc_p22_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_PCSC_ICG_MODULE_UNION;
#endif
#define SOC_MediaCommon_PCSC_ICG_MODULE_pcsc_module_en_START (0)
#define SOC_MediaCommon_PCSC_ICG_MODULE_pcsc_module_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcsc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_PCSC_MPREC_UNION;
#endif
#define SOC_MediaCommon_PCSC_MPREC_pcsc_mprec_START (0)
#define SOC_MediaCommon_PCSC_MPREC_pcsc_mprec_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int post_clip_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_POST_CLIP_DISP_SIZE_UNION;
#endif
#define SOC_MediaCommon_POST_CLIP_DISP_SIZE_post_clip_size_vrt_START (0)
#define SOC_MediaCommon_POST_CLIP_DISP_SIZE_post_clip_size_vrt_END (12)
#define SOC_MediaCommon_POST_CLIP_DISP_SIZE_post_clip_size_hrz_START (16)
#define SOC_MediaCommon_POST_CLIP_DISP_SIZE_post_clip_size_hrz_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_right : 6;
        unsigned int reserved_0 : 10;
        unsigned int post_clip_left : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_POST_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_MediaCommon_POST_CLIP_CTL_HRZ_post_clip_right_START (0)
#define SOC_MediaCommon_POST_CLIP_CTL_HRZ_post_clip_right_END (5)
#define SOC_MediaCommon_POST_CLIP_CTL_HRZ_post_clip_left_START (16)
#define SOC_MediaCommon_POST_CLIP_CTL_HRZ_post_clip_left_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_bot : 6;
        unsigned int reserved_0 : 10;
        unsigned int post_clip_top : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_MediaCommon_POST_CLIP_CTL_VRZ_UNION;
#endif
#define SOC_MediaCommon_POST_CLIP_CTL_VRZ_post_clip_bot_START (0)
#define SOC_MediaCommon_POST_CLIP_CTL_VRZ_post_clip_bot_END (5)
#define SOC_MediaCommon_POST_CLIP_CTL_VRZ_post_clip_top_START (16)
#define SOC_MediaCommon_POST_CLIP_CTL_VRZ_post_clip_top_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_POST_CLIP_EN_UNION;
#endif
#define SOC_MediaCommon_POST_CLIP_EN_post_clip_enable_START (0)
#define SOC_MediaCommon_POST_CLIP_EN_post_clip_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_MediaCommon_CSC_IDC0_UNION;
#endif
#define SOC_MediaCommon_CSC_IDC0_csc_idc0_START (0)
#define SOC_MediaCommon_CSC_IDC0_csc_idc0_END (10)
#define SOC_MediaCommon_CSC_IDC0_csc_idc1_START (16)
#define SOC_MediaCommon_CSC_IDC0_csc_idc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_MediaCommon_CSC_IDC2_UNION;
#endif
#define SOC_MediaCommon_CSC_IDC2_csc_idc2_START (0)
#define SOC_MediaCommon_CSC_IDC2_csc_idc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_MediaCommon_CSC_ODC0_UNION;
#endif
#define SOC_MediaCommon_CSC_ODC0_csc_odc0_START (0)
#define SOC_MediaCommon_CSC_ODC0_csc_odc0_END (10)
#define SOC_MediaCommon_CSC_ODC0_csc_odc1_START (16)
#define SOC_MediaCommon_CSC_ODC0_csc_odc1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_MediaCommon_CSC_ODC2_UNION;
#endif
#define SOC_MediaCommon_CSC_ODC2_csc_odc2_START (0)
#define SOC_MediaCommon_CSC_ODC2_csc_odc2_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P00_UNION;
#endif
#define SOC_MediaCommon_CSC_P00_csc_p00_START (0)
#define SOC_MediaCommon_CSC_P00_csc_p00_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P01_UNION;
#endif
#define SOC_MediaCommon_CSC_P01_csc_p01_START (0)
#define SOC_MediaCommon_CSC_P01_csc_p01_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P02_UNION;
#endif
#define SOC_MediaCommon_CSC_P02_csc_p02_START (0)
#define SOC_MediaCommon_CSC_P02_csc_p02_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P10_UNION;
#endif
#define SOC_MediaCommon_CSC_P10_csc_p10_START (0)
#define SOC_MediaCommon_CSC_P10_csc_p10_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P11_UNION;
#endif
#define SOC_MediaCommon_CSC_P11_csc_p11_START (0)
#define SOC_MediaCommon_CSC_P11_csc_p11_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P12_UNION;
#endif
#define SOC_MediaCommon_CSC_P12_csc_p12_START (0)
#define SOC_MediaCommon_CSC_P12_csc_p12_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P20_UNION;
#endif
#define SOC_MediaCommon_CSC_P20_csc_p20_START (0)
#define SOC_MediaCommon_CSC_P20_csc_p20_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P21_UNION;
#endif
#define SOC_MediaCommon_CSC_P21_csc_p21_START (0)
#define SOC_MediaCommon_CSC_P21_csc_p21_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MediaCommon_CSC_P22_UNION;
#endif
#define SOC_MediaCommon_CSC_P22_csc_p22_START (0)
#define SOC_MediaCommon_CSC_P22_csc_p22_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_CSC_ICG_MODULE_UNION;
#endif
#define SOC_MediaCommon_CSC_ICG_MODULE_csc_module_en_START (0)
#define SOC_MediaCommon_CSC_ICG_MODULE_csc_module_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_CSC_MPREC_UNION;
#endif
#define SOC_MediaCommon_CSC_MPREC_csc_mprec_START (0)
#define SOC_MediaCommon_CSC_MPREC_csc_mprec_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_first_lns_en : 1;
        unsigned int rot_first_lns : 5;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_ROT_FIRST_LNS_UNION;
#endif
#define SOC_MediaCommon_ROT_FIRST_LNS_rot_first_lns_en_START (0)
#define SOC_MediaCommon_ROT_FIRST_LNS_rot_first_lns_en_END (0)
#define SOC_MediaCommon_ROT_FIRST_LNS_rot_first_lns_START (1)
#define SOC_MediaCommon_ROT_FIRST_LNS_rot_first_lns_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_state : 32;
    } reg;
} SOC_MediaCommon_ROT_STATE_UNION;
#endif
#define SOC_MediaCommon_ROT_STATE_rot_state_START (0)
#define SOC_MediaCommon_ROT_STATE_rot_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_mem_ctrl : 4;
        unsigned int rot_auto_lp_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MediaCommon_ROT_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_ROT_MEM_CTRL_rot_mem_ctrl_START (0)
#define SOC_MediaCommon_ROT_MEM_CTRL_rot_mem_ctrl_END (3)
#define SOC_MediaCommon_ROT_MEM_CTRL_rot_auto_lp_en_START (4)
#define SOC_MediaCommon_ROT_MEM_CTRL_rot_auto_lp_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_img_width : 13;
        unsigned int reserved_0 : 3;
        unsigned int rot_img_height : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_ROT_SIZE_UNION;
#endif
#define SOC_MediaCommon_ROT_SIZE_rot_img_width_START (0)
#define SOC_MediaCommon_ROT_SIZE_rot_img_width_END (12)
#define SOC_MediaCommon_ROT_SIZE_rot_img_height_START (16)
#define SOC_MediaCommon_ROT_SIZE_rot_img_height_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_yuv422_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_ROT_422_MODE_UNION;
#endif
#define SOC_MediaCommon_ROT_422_MODE_rot_yuv422_mode_START (0)
#define SOC_MediaCommon_ROT_422_MODE_rot_yuv422_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_start0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_ROT_CPU_START0_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_START0_rot_cpu_start0_START (0)
#define SOC_MediaCommon_ROT_CPU_START0_rot_cpu_start0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_addr0 : 12;
        unsigned int reserved : 19;
        unsigned int rot_cpu_rw0 : 1;
    } reg;
} SOC_MediaCommon_ROT_CPU_ADDR0_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_ADDR0_rot_cpu_addr0_START (0)
#define SOC_MediaCommon_ROT_CPU_ADDR0_rot_cpu_addr0_END (11)
#define SOC_MediaCommon_ROT_CPU_ADDR0_rot_cpu_rw0_START (31)
#define SOC_MediaCommon_ROT_CPU_ADDR0_rot_cpu_rw0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_rdata0 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_RDATA0_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_RDATA0_rot_cpu_rdata0_START (0)
#define SOC_MediaCommon_ROT_CPU_RDATA0_rot_cpu_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_rdata1 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_RDATA1_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_RDATA1_rot_cpu_rdata1_START (0)
#define SOC_MediaCommon_ROT_CPU_RDATA1_rot_cpu_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_wdata0 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_WDATA0_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_WDATA0_rot_cpu_wdata0_START (0)
#define SOC_MediaCommon_ROT_CPU_WDATA0_rot_cpu_wdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_wdata1 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_WDATA1_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_WDATA1_rot_cpu_wdata1_START (0)
#define SOC_MediaCommon_ROT_CPU_WDATA1_rot_cpu_wdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_ctl1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_ROT_CPU_CTL1_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_CTL1_rot_cpu_ctl1_START (0)
#define SOC_MediaCommon_ROT_CPU_CTL1_rot_cpu_ctl1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_start1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_ROT_CPU_START1_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_START1_rot_cpu_start1_START (0)
#define SOC_MediaCommon_ROT_CPU_START1_rot_cpu_start1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_addr1 : 12;
        unsigned int reserved : 19;
        unsigned int rot_cpu_rw1 : 1;
    } reg;
} SOC_MediaCommon_ROT_CPU_ADDR1_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_ADDR1_rot_cpu_addr1_START (0)
#define SOC_MediaCommon_ROT_CPU_ADDR1_rot_cpu_addr1_END (11)
#define SOC_MediaCommon_ROT_CPU_ADDR1_rot_cpu_rw1_START (31)
#define SOC_MediaCommon_ROT_CPU_ADDR1_rot_cpu_rw1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_rdata2 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_RDATA2_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_RDATA2_rot_cpu_rdata2_START (0)
#define SOC_MediaCommon_ROT_CPU_RDATA2_rot_cpu_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_rdata3 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_RDATA3_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_RDATA3_rot_cpu_rdata3_START (0)
#define SOC_MediaCommon_ROT_CPU_RDATA3_rot_cpu_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_wdata2 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_WDATA2_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_WDATA2_rot_cpu_wdata2_START (0)
#define SOC_MediaCommon_ROT_CPU_WDATA2_rot_cpu_wdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_cpu_wdata3 : 32;
    } reg;
} SOC_MediaCommon_ROT_CPU_WDATA3_UNION;
#endif
#define SOC_MediaCommon_ROT_CPU_WDATA3_rot_cpu_wdata3_START (0)
#define SOC_MediaCommon_ROT_CPU_WDATA3_rot_cpu_wdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_debug_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_CH_DEBUG_SEL_UNION;
#endif
#define SOC_MediaCommon_CH_DEBUG_SEL_ch_debug_sel_START (0)
#define SOC_MediaCommon_CH_DEBUG_SEL_ch_debug_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_os_cfg : 6;
        unsigned int reserved_0 : 2;
        unsigned int dma_buf_qos_mask : 1;
        unsigned int dma_buf_cont_mask : 1;
        unsigned int dma_buf_l_e_mask : 1;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_MediaCommon_DMA_BUF_CTRL_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_os_cfg_START (0)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_os_cfg_END (5)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_qos_mask_START (8)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_qos_mask_END (8)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_cont_mask_START (9)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_cont_mask_END (9)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_l_e_mask_START (10)
#define SOC_MediaCommon_DMA_BUF_CTRL_dma_buf_l_e_mask_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_ctl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_CTL_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_dma_buf_cpu_ctl_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_CTL_dma_buf_cpu_ctl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_START_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_START_dma_buf_cpu_start_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_START_dma_buf_cpu_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_addr : 9;
        unsigned int reserved : 22;
        unsigned int dma_buf_cpu_rw : 1;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_ADDR_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_addr_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_addr_END (8)
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_rw_START (31)
#define SOC_MediaCommon_DMA_BUF_CPU_ADDR_dma_buf_cpu_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata0 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA0_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_dma_buf_cpu_rdata0_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA0_dma_buf_cpu_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata1 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA1_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_dma_buf_cpu_rdata1_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA1_dma_buf_cpu_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata2 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA2_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_dma_buf_cpu_rdata2_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA2_dma_buf_cpu_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_rdata3 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_RDATA3_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_dma_buf_cpu_rdata3_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_RDATA3_dma_buf_cpu_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata0 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA0_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_dma_buf_cpu_wdata0_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA0_dma_buf_cpu_wdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata1 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA1_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_dma_buf_cpu_wdata1_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA1_dma_buf_cpu_wdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata2 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA2_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_dma_buf_cpu_wdata2_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA2_dma_buf_cpu_wdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_cpu_wdata3 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_CPU_WDATA3_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_dma_buf_cpu_wdata3_START (0)
#define SOC_MediaCommon_DMA_BUF_CPU_WDATA3_dma_buf_cpu_wdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_req_end : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_DMA_REQ_END_UNION;
#endif
#define SOC_MediaCommon_DMA_REQ_END_dma_req_end_START (0)
#define SOC_MediaCommon_DMA_REQ_END_dma_req_end_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbgcfg : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBGCFG_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBGCFG_dma_buf_dbgcfg_START (0)
#define SOC_MediaCommon_DMA_BUF_DBGCFG_dma_buf_dbgcfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg0 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG0_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG0_dma_buf_dbg0_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG0_dma_buf_dbg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg1 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG1_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG1_dma_buf_dbg1_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG1_dma_buf_dbg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg2 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG2_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG2_dma_buf_dbg2_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG2_dma_buf_dbg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg3 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG3_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG3_dma_buf_dbg3_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG3_dma_buf_dbg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg4 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG4_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG4_dma_buf_dbg4_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG4_dma_buf_dbg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_dbg5 : 32;
    } reg;
} SOC_MediaCommon_DMA_BUF_DBG5_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_DBG5_dma_buf_dbg5_START (0)
#define SOC_MediaCommon_DMA_BUF_DBG5_dma_buf_dbg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_img_width : 13;
        unsigned int reserved_0 : 3;
        unsigned int dma_buf_img_height : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_MediaCommon_DMA_BUF_SIZE_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_width_START (0)
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_width_END (12)
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_height_START (16)
#define SOC_MediaCommon_DMA_BUF_SIZE_dma_buf_img_height_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_buf_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_DMA_BUF_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_dma_buf_mem_ctrl_START (0)
#define SOC_MediaCommon_DMA_BUF_MEM_CTRL_dma_buf_mem_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_pic_blks : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MediaCommon_AFBCE_HREG_PIC_BLKS_UNION;
#endif
#define SOC_MediaCommon_AFBCE_HREG_PIC_BLKS_afbce_pic_blks_START (0)
#define SOC_MediaCommon_AFBCE_HREG_PIC_BLKS_afbce_pic_blks_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int reserved_1 : 5;
        unsigned int afbce_color_transform : 1;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_MediaCommon_AFBCE_HREG_FORMAT_UNION;
#endif
#define SOC_MediaCommon_AFBCE_HREG_FORMAT_afbce_color_transform_START (21)
#define SOC_MediaCommon_AFBCE_HREG_FORMAT_afbce_color_transform_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_hdr_ptr_0 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L0_UNION;
#endif
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L0_afbce_hdr_ptr_0_START (0)
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L0_afbce_hdr_ptr_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_payload_ptr_0 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L0_UNION;
#endif
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L0_afbce_payload_ptr_0_START (0)
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L0_afbce_payload_ptr_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_block_height : 16;
        unsigned int afbce_block_width : 10;
        unsigned int reserved : 6;
    } reg;
} SOC_MediaCommon_PICTURE_SIZE_UNION;
#endif
#define SOC_MediaCommon_PICTURE_SIZE_afbce_block_height_START (0)
#define SOC_MediaCommon_PICTURE_SIZE_afbce_block_height_END (15)
#define SOC_MediaCommon_PICTURE_SIZE_afbce_block_width_START (16)
#define SOC_MediaCommon_PICTURE_SIZE_afbce_block_width_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_header_stride_0 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_HEADER_SRTIDE_0_UNION;
#endif
#define SOC_MediaCommon_HEADER_SRTIDE_0_afbce_header_stride_0_START (0)
#define SOC_MediaCommon_HEADER_SRTIDE_0_afbce_header_stride_0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_payload_stride_0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_PAYLOAD_STRIDE_0_UNION;
#endif
#define SOC_MediaCommon_PAYLOAD_STRIDE_0_afbce_payload_stride_0_START (0)
#define SOC_MediaCommon_PAYLOAD_STRIDE_0_afbce_payload_stride_0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_ddrw_os : 6;
        unsigned int hfbce_ddrw_os : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_MediaCommon_ENC_OS_CFG_UNION;
#endif
#define SOC_MediaCommon_ENC_OS_CFG_afbce_ddrw_os_START (0)
#define SOC_MediaCommon_ENC_OS_CFG_afbce_ddrw_os_END (5)
#define SOC_MediaCommon_ENC_OS_CFG_hfbce_ddrw_os_START (6)
#define SOC_MediaCommon_ENC_OS_CFG_hfbce_ddrw_os_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_mem_ctrl_0 : 4;
        unsigned int afbce_mem_ctrl_1 : 4;
        unsigned int afbce_mem_ctrl_2 : 4;
        unsigned int hfbce_mem_ctrl_0 : 4;
        unsigned int hfbce_mem_ctrl_1 : 4;
        unsigned int hfbce_mem_ctrl_2 : 4;
        unsigned int hfbce_mem_ctrl_3 : 4;
        unsigned int hfbce_mem_ctrl_4 : 4;
    } reg;
} SOC_MediaCommon_AFBCE_MEM_CTRL_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MEM_CTRL_afbce_mem_ctrl_0_START (0)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_afbce_mem_ctrl_0_END (3)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_afbce_mem_ctrl_1_START (4)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_afbce_mem_ctrl_1_END (7)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_afbce_mem_ctrl_2_START (8)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_afbce_mem_ctrl_2_END (11)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_0_START (12)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_0_END (15)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_1_START (16)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_1_END (19)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_2_START (20)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_2_END (23)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_3_START (24)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_3_END (27)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_4_START (28)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_hfbce_mem_ctrl_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_qos_cfg : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MediaCommon_AFBCE_QOS_CFG_UNION;
#endif
#define SOC_MediaCommon_AFBCE_QOS_CFG_afbce_qos_cfg_START (0)
#define SOC_MediaCommon_AFBCE_QOS_CFG_afbce_qos_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_threshold : 3;
        unsigned int hfbce_threshold : 3;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_FBCE_THRESHOLD_UNION;
#endif
#define SOC_MediaCommon_FBCE_THRESHOLD_afbce_threshold_START (0)
#define SOC_MediaCommon_FBCE_THRESHOLD_afbce_threshold_END (2)
#define SOC_MediaCommon_FBCE_THRESHOLD_hfbce_threshold_START (3)
#define SOC_MediaCommon_FBCE_THRESHOLD_hfbce_threshold_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_scramble_mode : 2;
        unsigned int hfbce_scramble_mode : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_MediaCommon_FBCE_SCRAMBLE_MODE_UNION;
#endif
#define SOC_MediaCommon_FBCE_SCRAMBLE_MODE_afbce_scramble_mode_START (0)
#define SOC_MediaCommon_FBCE_SCRAMBLE_MODE_afbce_scramble_mode_END (1)
#define SOC_MediaCommon_FBCE_SCRAMBLE_MODE_hfbce_scramble_mode_START (2)
#define SOC_MediaCommon_FBCE_SCRAMBLE_MODE_hfbce_scramble_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_header_pointer_offset : 32;
    } reg;
} SOC_MediaCommon_AFBCE_HEADER_POINTER_OFFSET_UNION;
#endif
#define SOC_MediaCommon_AFBCE_HEADER_POINTER_OFFSET_afbce_header_pointer_offset_START (0)
#define SOC_MediaCommon_AFBCE_HEADER_POINTER_OFFSET_afbce_header_pointer_offset_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_monitor_reg1 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_MONITOR_REG1_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MONITOR_REG1_afbce_monitor_reg1_START (0)
#define SOC_MediaCommon_AFBCE_MONITOR_REG1_afbce_monitor_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_monitor_reg2 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_MONITOR_REG2_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MONITOR_REG2_afbce_monitor_reg2_START (0)
#define SOC_MediaCommon_AFBCE_MONITOR_REG2_afbce_monitor_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_monitor_reg3 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_MONITOR_REG3_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MONITOR_REG3_afbce_monitor_reg3_START (0)
#define SOC_MediaCommon_AFBCE_MONITOR_REG3_afbce_monitor_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_debug_reg0 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_DEBUG_REG0_UNION;
#endif
#define SOC_MediaCommon_AFBCE_DEBUG_REG0_afbce_debug_reg0_START (0)
#define SOC_MediaCommon_AFBCE_DEBUG_REG0_afbce_debug_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbce_creg_fbce_mode : 1;
        unsigned int fbce_creg_hfbce_bypass : 1;
        unsigned int reserved_0 : 2;
        unsigned int fbce_creg_hfbce_raw_en : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_UNION;
#endif
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_fbce_creg_fbce_mode_START (0)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_fbce_creg_fbce_mode_END (0)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_fbce_creg_hfbce_bypass_START (1)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_fbce_creg_hfbce_bypass_END (1)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_fbce_creg_hfbce_raw_en_START (4)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CTRL_MODE_fbce_creg_hfbce_raw_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_hdr_ptr_1 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L1_UNION;
#endif
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L1_afbce_hdr_ptr_1_START (0)
#define SOC_MediaCommon_AFBCE_HREG_HDR_PTR_L1_afbce_hdr_ptr_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_payload_ptr_1 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L1_UNION;
#endif
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L1_afbce_payload_ptr_1_START (0)
#define SOC_MediaCommon_AFBCE_HREG_PLD_PTR_L1_afbce_payload_ptr_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_header_stride_1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_HEADER_SRTIDE_1_UNION;
#endif
#define SOC_MediaCommon_HEADER_SRTIDE_1_afbce_header_stride_1_START (0)
#define SOC_MediaCommon_HEADER_SRTIDE_1_afbce_header_stride_1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_payload_stride_1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_MediaCommon_PAYLOAD_STRIDE_1_UNION;
#endif
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_afbce_payload_stride_1_START (0)
#define SOC_MediaCommon_PAYLOAD_STRIDE_1_afbce_payload_stride_1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fbce_creg_clkgate_off : 1;
        unsigned int fbce_creg_mem_sd_off : 1;
        unsigned int fbce_creg_hfbce_ip_auto_clk_gt_en : 1;
        unsigned int fbce_creg_fbce_auto_clk_gt_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_UNION;
#endif
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_clkgate_off_START (0)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_clkgate_off_END (0)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_mem_sd_off_START (1)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_mem_sd_off_END (1)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_hfbce_ip_auto_clk_gt_en_START (2)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_hfbce_ip_auto_clk_gt_en_END (2)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_fbce_auto_clk_gt_en_START (3)
#define SOC_MediaCommon_FBCE_CREG_FBCE_CLK_GATE_fbce_creg_fbce_auto_clk_gt_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hfbce_mem_ctrl_5 : 4;
        unsigned int hfbce_mem_ctrl_6 : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_MediaCommon_AFBCE_MEM_CTRL_1_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MEM_CTRL_1_hfbce_mem_ctrl_5_START (0)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_1_hfbce_mem_ctrl_5_END (3)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_1_hfbce_mem_ctrl_6_START (4)
#define SOC_MediaCommon_AFBCE_MEM_CTRL_1_hfbce_mem_ctrl_6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_monitor_reg4 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_MONITOR_REG4_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MONITOR_REG4_afbce_monitor_reg4_START (0)
#define SOC_MediaCommon_AFBCE_MONITOR_REG4_afbce_monitor_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_monitor_reg5 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_MONITOR_REG5_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MONITOR_REG5_afbce_monitor_reg5_START (0)
#define SOC_MediaCommon_AFBCE_MONITOR_REG5_afbce_monitor_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afbce_monitor_reg6 : 32;
    } reg;
} SOC_MediaCommon_AFBCE_MONITOR_REG6_UNION;
#endif
#define SOC_MediaCommon_AFBCE_MONITOR_REG6_afbce_monitor_reg6_START (0)
#define SOC_MediaCommon_AFBCE_MONITOR_REG6_afbce_monitor_reg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr_ext0 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MediaCommon_DMA_ADDR_EXT_UNION;
#endif
#define SOC_MediaCommon_DMA_ADDR_EXT_dma_addr_ext0_START (0)
#define SOC_MediaCommon_DMA_ADDR_EXT_dma_addr_ext0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_hdr_ptr_0 : 32;
    } reg;
} SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_UNION;
#endif
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_hebc_hdr_ptr_0_START (0)
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_hebc_hdr_ptr_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_MediaCommon_HEBC_HREG_PIC_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_MediaCommon_HEBC_HREG_PIC_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_header_stride_0 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_UNION;
#endif
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_hebc_header_stride_0_START (0)
#define SOC_MediaCommon_HEBC_INPUT_HEADER_STRIDE_hebc_header_stride_0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 20;
        unsigned int reserved_1: 12;
    } reg;
} SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MediaCommon_HEBC_PAYLOAD_POINTER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int hebc_ddrr_os : 6;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 6;
        unsigned int reserved_5 : 4;
    } reg;
} SOC_MediaCommon_HEBC_OS_CFG_UNION;
#endif
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_ddrr_os_START (8)
#define SOC_MediaCommon_HEBC_OS_CFG_hebc_ddrr_os_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_scramble_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_HEBC_SCRAMBLE_MODE_UNION;
#endif
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_hebc_scramble_mode_START (0)
#define SOC_MediaCommon_HEBC_SCRAMBLE_MODE_hebc_scramble_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_UNION;
#endif
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_hebc_mode_START (0)
#define SOC_MediaCommon_HEBC_CREG_FBCD_CTRL_MODE_hebc_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value0 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE0_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE0_hebc_tag_value0_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE0_hebc_tag_value0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value1 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE1_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE1_hebc_tag_value1_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE1_hebc_tag_value1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value2 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE2_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE2_hebc_tag_value2_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE2_hebc_tag_value2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_tag_value3 : 32;
    } reg;
} SOC_MediaCommon_HEBC_TAG_VALUE3_UNION;
#endif
#define SOC_MediaCommon_HEBC_TAG_VALUE3_hebc_tag_value3_START (0)
#define SOC_MediaCommon_HEBC_TAG_VALUE3_hebc_tag_value3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved0 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED0_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED0_hebc_reserved0_START (0)
#define SOC_MediaCommon_HEBC_RESERVED0_hebc_reserved0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved1 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED1_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED1_hebc_reserved1_START (0)
#define SOC_MediaCommon_HEBC_RESERVED1_hebc_reserved1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved2 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED2_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED2_hebc_reserved2_START (0)
#define SOC_MediaCommon_HEBC_RESERVED2_hebc_reserved2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_reserved3 : 32;
    } reg;
} SOC_MediaCommon_HEBC_RESERVED3_UNION;
#endif
#define SOC_MediaCommon_HEBC_RESERVED3_hebc_reserved3_START (0)
#define SOC_MediaCommon_HEBC_RESERVED3_hebc_reserved3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_hdr_ptr_1 : 32;
    } reg;
} SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_UNION;
#endif
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_hebc_hdr_ptr_1_START (0)
#define SOC_MediaCommon_HEBC_HREG_HDR_PTR_LO_1_hebc_hdr_ptr_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_MediaCommon_HEBC_HREG_PLD_PTR_LO_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_header_stride_1 : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_UNION;
#endif
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_hebc_header_stride_1_START (0)
#define SOC_MediaCommon_HEBC_HEADER_SRTIDE_1_hebc_header_stride_1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 20;
        unsigned int reserved_1: 12;
    } reg;
} SOC_MediaCommon_HEBC_PAYLOAD_STRIDE_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_color_transform : 1;
        unsigned int hebc_blk4x4_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MediaCommon_HEBC_HREG_FORMAT_UNION;
#endif
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_color_transform_START (0)
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_color_transform_END (0)
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_blk4x4_en_START (1)
#define SOC_MediaCommon_HEBC_HREG_FORMAT_hebc_blk4x4_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hebc_spblk_layout : 2;
        unsigned int reserved_0 : 6;
        unsigned int hebc_spblk_compact_num : 5;
        unsigned int reserved_1 : 3;
        unsigned int hebc_spblk_layout_switch_en : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_MediaCommon_HEBC_SPBLOCK_MODE_UNION;
#endif
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_hebc_spblk_layout_START (0)
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_hebc_spblk_layout_END (1)
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_hebc_spblk_compact_num_START (8)
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_hebc_spblk_compact_num_END (12)
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_hebc_spblk_layout_switch_en_START (16)
#define SOC_MediaCommon_HEBC_SPBLOCK_MODE_hebc_spblk_layout_switch_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MediaCommon_REG_DEFAULT_UNION;
#endif
#define SOC_MediaCommon_REG_DEFAULT_reg_default_START (0)
#define SOC_MediaCommon_REG_DEFAULT_reg_default_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_6tap_coef : 32;
    } reg;
} SOC_MediaCommon_V0_SCF_VIDEO_6TAP_COEF_UNION;
#endif
#define SOC_MediaCommon_V0_SCF_VIDEO_6TAP_COEF_scf_video_6tap_coef_START (0)
#define SOC_MediaCommon_V0_SCF_VIDEO_6TAP_COEF_scf_video_6tap_coef_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_5tap_coef : 32;
    } reg;
} SOC_MediaCommon_V0_SCF_VIDEO_5TAP_COEF_UNION;
#endif
#define SOC_MediaCommon_V0_SCF_VIDEO_5TAP_COEF_scf_video_5tap_coef_START (0)
#define SOC_MediaCommon_V0_SCF_VIDEO_5TAP_COEF_scf_video_5tap_coef_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_4tap_coef : 32;
    } reg;
} SOC_MediaCommon_V0_SCF_VIDEO_4TAP_COEF_UNION;
#endif
#define SOC_MediaCommon_V0_SCF_VIDEO_4TAP_COEF_scf_video_4tap_coef_START (0)
#define SOC_MediaCommon_V0_SCF_VIDEO_4TAP_COEF_scf_video_4tap_coef_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
