#ifndef __SOC_IVP_INTERFACE_H__
#define __SOC_IVP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IVP_PRID_ADDR(base) ((base) + (0x0000UL))
#define SOC_IVP_OCDHALTONRESET_ADDR(base) ((base) + (0x0004UL))
#define SOC_IVP_STATVECTORSEL_ADDR(base) ((base) + (0x0008UL))
#define SOC_IVP_RUNSTALL_ADDR(base) ((base) + (0x000CUL))
#define SOC_IVP_PWAITMODE_ADDR(base) ((base) + (0x0010UL))
#define SOC_IVP_BINTERRUPT_ADDR(base) ((base) + (0x0100UL))
#define SOC_IVP_NMI_ADDR(base) ((base) + (0x0104UL))
#define SOC_IVP_VIC0_OUT0_ADDR(base) ((base) + (0x110UL))
#define SOC_IVP_VIC0_OUT1_ADDR(base) ((base) + (0x114UL))
#define SOC_IVP_VIC0_IN0_ADDR(base) ((base) + (0x118UL))
#define SOC_IVP_VIC0_IN1_ADDR(base) ((base) + (0x11CUL))
#define SOC_IVP_DSP_CORE_RESET_EN_ADDR(base) ((base) + (0x0200UL))
#define SOC_IVP_DSP_CORE_RESET_DIS_ADDR(base) ((base) + (0x0204UL))
#define SOC_IVP_DSP_CORE_RESET_STATUS_ADDR(base) ((base) + (0x0208UL))
#define SOC_IVP_REF_CLOCK_SEL_ADDR(base) ((base) + (0x020CUL))
#define SOC_IVP_APB_GATE_CLOCK_ADDR(base) ((base) + (0x0210UL))
#define SOC_IVP_BUS_GATE_CLOCK_ADDR(base) ((base) + (0x0214UL))
#define SOC_IVP_TIMER_WDG_RST_EN_ADDR(base) ((base) + (0x0218UL))
#define SOC_IVP_TIMER_WDG_RST_DIS_ADDR(base) ((base) + (0x021CUL))
#define SOC_IVP_TIMER_WDG_RST_STATUS_ADDR(base) ((base) + (0x0220UL))
#define SOC_IVP_DSPCORE_GATE_ADDR(base) ((base) + (0x0224UL))
#define SOC_IVP_DSPCRE_GATE_ST_ADDR(base) ((base) + (0x0228UL))
#define SOC_IVP_DEBUG_CONTROL_ADDR(base) ((base) + (0x02B0UL))
#define SOC_IVP_RESERVE_FOR_EC1_ADDR(base) ((base) + (0x02B4UL))
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_ADDR(base) ((base) + (0x30CUL))
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_ADDR(base) ((base) + (0x0310UL))
#define SOC_IVP_MEM_CTRL0_ADDR(base) ((base) + (0x0320UL))
#define SOC_IVP_MEM_CTRL1_ADDR(base) ((base) + (0x0324UL))
#define SOC_IVP_CRG_PERI_GT_ST_ADDR(base) ((base) + (0x032CUL))
#define SOC_IVP_SMMU_AWAKEBYPASS_ADDR(base) ((base) + (0x0330UL))
#define SOC_IVP_SMMU_PWR_HANDSHAKE_ST_ADDR(base) ((base) + (0x033CUL))
#define SOC_IVP_APB_IF_DLOCK_BYPASS_ADDR(base) ((base) + (0x0340UL))
#define SOC_IVP_ADDR_MON_EN_ADDR(base) ((base) + (0x0400UL))
#define SOC_IVP_ADDR_MON_CLR_ADDR(base) ((base) + (0x0404UL))
#define SOC_IVP_ADDR_MON_INTR_EN_ADDR(base) ((base) + (0x0408UL))
#define SOC_IVP_ADDR_MON_INTR_STAT_ADDR(base) ((base) + (0x040CUL))
#define SOC_IVP_ADDR_MON0_ADDR_BASE_ADDR(base) ((base) + (0x0410UL))
#define SOC_IVP_ADDR_MON0_ADDR_LEN_ADDR(base) ((base) + (0x0414UL))
#define SOC_IVP_ADDR_MON0_HIT_AWADDR_ADDR(base) ((base) + (0x0418UL))
#define SOC_IVP_ADDR_MON0_HIT_ARADDR_ADDR(base) ((base) + (0x041CUL))
#define SOC_IVP_ADDR_MON1_ADDR_BASE_ADDR(base) ((base) + (0x0420UL))
#define SOC_IVP_ADDR_MON1_ADDR_LEN_ADDR(base) ((base) + (0x0424UL))
#define SOC_IVP_ADDR_MON1_HIT_AWADDR_ADDR(base) ((base) + (0x0428UL))
#define SOC_IVP_ADDR_MON1_HIT_ARADDR_ADDR(base) ((base) + (0x042CUL))
#define SOC_IVP_ADDR_MON2_ADDR_BASE_ADDR(base) ((base) + (0x0430UL))
#define SOC_IVP_ADDR_MON2_ADDR_LEN_ADDR(base) ((base) + (0x0434UL))
#define SOC_IVP_ADDR_MON2_HIT_AWADDR_ADDR(base) ((base) + (0x0438UL))
#define SOC_IVP_ADDR_MON2_HIT_ARADDR_ADDR(base) ((base) + (0x043CUL))
#define SOC_IVP_ADDR_MON3_ADDR_BASE_ADDR(base) ((base) + (0x0440UL))
#define SOC_IVP_ADDR_MON3_ADDR_LEN_ADDR(base) ((base) + (0x0444UL))
#define SOC_IVP_ADDR_MON3_HIT_AWADDR_ADDR(base) ((base) + (0x0448UL))
#define SOC_IVP_ADDR_MON3_HIT_ARADDR_ADDR(base) ((base) + (0x044CUL))
#define SOC_IVP_ADDR_MON4_ADDR_BASE_ADDR(base) ((base) + (0x0450UL))
#define SOC_IVP_ADDR_MON4_ADDR_LEN_ADDR(base) ((base) + (0x0454UL))
#define SOC_IVP_ADDR_MON4_HIT_AWADDR_ADDR(base) ((base) + (0x0458UL))
#define SOC_IVP_ADDR_MON4_HIT_ARADDR_ADDR(base) ((base) + (0x045CUL))
#define SOC_IVP_ADDR_MON5_ADDR_BASE_ADDR(base) ((base) + (0x0460UL))
#define SOC_IVP_ADDR_MON5_ADDR_LEN_ADDR(base) ((base) + (0x0464UL))
#define SOC_IVP_ADDR_MON5_HIT_AWADDR_ADDR(base) ((base) + (0x0468UL))
#define SOC_IVP_ADDR_MON5_HIT_ARADDR_ADDR(base) ((base) + (0x046CUL))
#define SOC_IVP_ADDR_MON6_ADDR_BASE_ADDR(base) ((base) + (0x0470UL))
#define SOC_IVP_ADDR_MON6_ADDR_LEN_ADDR(base) ((base) + (0x0474UL))
#define SOC_IVP_ADDR_MON6_HIT_AWADDR_ADDR(base) ((base) + (0x0478UL))
#define SOC_IVP_ADDR_MON6_HIT_ARADDR_ADDR(base) ((base) + (0x047CUL))
#define SOC_IVP_ADDR_MON7_ADDR_BASE_ADDR(base) ((base) + (0x0480UL))
#define SOC_IVP_ADDR_MON7_ADDR_LEN_ADDR(base) ((base) + (0x0484UL))
#define SOC_IVP_ADDR_MON7_HIT_AWADDR_ADDR(base) ((base) + (0x0488UL))
#define SOC_IVP_ADDR_MON7_HIT_ARADDR_ADDR(base) ((base) + (0x048CUL))
#define SOC_IVP_SMMU_SW_GT_ADDR(base) ((base) + (0x0500UL))
#define SOC_IVP_SMMU_GT_ST_ADDR(base) ((base) + (0x0504UL))
#define SOC_IVP_SMMU_HW_GT_CNT_ADDR(base) ((base) + (0x050CUL))
#define SOC_IVP_SMMU_RST_EN_ADDR(base) ((base) + (0x0510UL))
#define SOC_IVP_SMMU_RST_DIS_ADDR(base) ((base) + (0x0514UL))
#define SOC_IVP_SMMU_RST_ST_ADDR(base) ((base) + (0x0518UL))
#define SOC_IVP_FAMA_CTRL0_ADDR(base) ((base) + (0x0530UL))
#define SOC_IVP_FAMA_ADDR_REMAP0_0_ADDR(base) ((base) + (0x0534UL))
#define SOC_IVP_FAMA_ADDR_REMAP0_1_ADDR(base) ((base) + (0x0538UL))
#define SOC_IVP_FAMA_ADDR_REMAP0_2_ADDR(base) ((base) + (0x053CUL))
#define SOC_IVP_FAMA_ADDR_REMAP1_0_ADDR(base) ((base) + (0x0540UL))
#define SOC_IVP_FAMA_ADDR_REMAP1_1_ADDR(base) ((base) + (0x0544UL))
#define SOC_IVP_FAMA_ADDR_REMAP1_2_ADDR(base) ((base) + (0x0548UL))
#define SOC_IVP_FAMA_ADDR_REMAP2_0_ADDR(base) ((base) + (0x054CUL))
#define SOC_IVP_FAMA_ADDR_REMAP2_1_ADDR(base) ((base) + (0x0550UL))
#define SOC_IVP_FAMA_ADDR_REMAP2_2_ADDR(base) ((base) + (0x0554UL))
#define SOC_IVP_FAMA_ADDR_REMAP3_0_ADDR(base) ((base) + (0x0558UL))
#define SOC_IVP_FAMA_ADDR_REMAP3_1_ADDR(base) ((base) + (0x055CUL))
#define SOC_IVP_FAMA_ADDR_REMAP3_2_ADDR(base) ((base) + (0x0560UL))
#define SOC_IVP_DEBUG_SIG_GRP1_ADDR(base) ((base) + (0x0600UL))
#define SOC_IVP_DEBUG_SIG_GRP2_ADDR(base) ((base) + (0x0604UL))
#define SOC_IVP_DEBUG_SIG_GRP3_ADDR(base) ((base) + (0x0608UL))
#define SOC_IVP_DEBUG_SIG_GRP4_ADDR(base) ((base) + (0x060CUL))
#define SOC_IVP_DEBUG_SIG_GRP5_ADDR(base) ((base) + (0x0610UL))
#define SOC_IVP_DEBUG_SIG_GRP6_ADDR(base) ((base) + (0x0614UL))
#define SOC_IVP_DEBUG_SIG_GRP7_ADDR(base) ((base) + (0x0618UL))
#define SOC_IVP_DEBUG_SIG_GRP8_ADDR(base) ((base) + (0x061CUL))
#define SOC_IVP_SUBSYS_VERSION_NUM_ADDR(base) ((base) + (0x0800UL))
#else
#define SOC_IVP_PRID_ADDR(base) ((base) + (0x0000))
#define SOC_IVP_OCDHALTONRESET_ADDR(base) ((base) + (0x0004))
#define SOC_IVP_STATVECTORSEL_ADDR(base) ((base) + (0x0008))
#define SOC_IVP_RUNSTALL_ADDR(base) ((base) + (0x000C))
#define SOC_IVP_PWAITMODE_ADDR(base) ((base) + (0x0010))
#define SOC_IVP_BINTERRUPT_ADDR(base) ((base) + (0x0100))
#define SOC_IVP_NMI_ADDR(base) ((base) + (0x0104))
#define SOC_IVP_VIC0_OUT0_ADDR(base) ((base) + (0x110))
#define SOC_IVP_VIC0_OUT1_ADDR(base) ((base) + (0x114))
#define SOC_IVP_VIC0_IN0_ADDR(base) ((base) + (0x118))
#define SOC_IVP_VIC0_IN1_ADDR(base) ((base) + (0x11C))
#define SOC_IVP_DSP_CORE_RESET_EN_ADDR(base) ((base) + (0x0200))
#define SOC_IVP_DSP_CORE_RESET_DIS_ADDR(base) ((base) + (0x0204))
#define SOC_IVP_DSP_CORE_RESET_STATUS_ADDR(base) ((base) + (0x0208))
#define SOC_IVP_REF_CLOCK_SEL_ADDR(base) ((base) + (0x020C))
#define SOC_IVP_APB_GATE_CLOCK_ADDR(base) ((base) + (0x0210))
#define SOC_IVP_BUS_GATE_CLOCK_ADDR(base) ((base) + (0x0214))
#define SOC_IVP_TIMER_WDG_RST_EN_ADDR(base) ((base) + (0x0218))
#define SOC_IVP_TIMER_WDG_RST_DIS_ADDR(base) ((base) + (0x021C))
#define SOC_IVP_TIMER_WDG_RST_STATUS_ADDR(base) ((base) + (0x0220))
#define SOC_IVP_DSPCORE_GATE_ADDR(base) ((base) + (0x0224))
#define SOC_IVP_DSPCRE_GATE_ST_ADDR(base) ((base) + (0x0228))
#define SOC_IVP_DEBUG_CONTROL_ADDR(base) ((base) + (0x02B0))
#define SOC_IVP_RESERVE_FOR_EC1_ADDR(base) ((base) + (0x02B4))
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_ADDR(base) ((base) + (0x30C))
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_ADDR(base) ((base) + (0x0310))
#define SOC_IVP_MEM_CTRL0_ADDR(base) ((base) + (0x0320))
#define SOC_IVP_MEM_CTRL1_ADDR(base) ((base) + (0x0324))
#define SOC_IVP_CRG_PERI_GT_ST_ADDR(base) ((base) + (0x032C))
#define SOC_IVP_SMMU_AWAKEBYPASS_ADDR(base) ((base) + (0x0330))
#define SOC_IVP_SMMU_PWR_HANDSHAKE_ST_ADDR(base) ((base) + (0x033C))
#define SOC_IVP_APB_IF_DLOCK_BYPASS_ADDR(base) ((base) + (0x0340))
#define SOC_IVP_ADDR_MON_EN_ADDR(base) ((base) + (0x0400))
#define SOC_IVP_ADDR_MON_CLR_ADDR(base) ((base) + (0x0404))
#define SOC_IVP_ADDR_MON_INTR_EN_ADDR(base) ((base) + (0x0408))
#define SOC_IVP_ADDR_MON_INTR_STAT_ADDR(base) ((base) + (0x040C))
#define SOC_IVP_ADDR_MON0_ADDR_BASE_ADDR(base) ((base) + (0x0410))
#define SOC_IVP_ADDR_MON0_ADDR_LEN_ADDR(base) ((base) + (0x0414))
#define SOC_IVP_ADDR_MON0_HIT_AWADDR_ADDR(base) ((base) + (0x0418))
#define SOC_IVP_ADDR_MON0_HIT_ARADDR_ADDR(base) ((base) + (0x041C))
#define SOC_IVP_ADDR_MON1_ADDR_BASE_ADDR(base) ((base) + (0x0420))
#define SOC_IVP_ADDR_MON1_ADDR_LEN_ADDR(base) ((base) + (0x0424))
#define SOC_IVP_ADDR_MON1_HIT_AWADDR_ADDR(base) ((base) + (0x0428))
#define SOC_IVP_ADDR_MON1_HIT_ARADDR_ADDR(base) ((base) + (0x042C))
#define SOC_IVP_ADDR_MON2_ADDR_BASE_ADDR(base) ((base) + (0x0430))
#define SOC_IVP_ADDR_MON2_ADDR_LEN_ADDR(base) ((base) + (0x0434))
#define SOC_IVP_ADDR_MON2_HIT_AWADDR_ADDR(base) ((base) + (0x0438))
#define SOC_IVP_ADDR_MON2_HIT_ARADDR_ADDR(base) ((base) + (0x043C))
#define SOC_IVP_ADDR_MON3_ADDR_BASE_ADDR(base) ((base) + (0x0440))
#define SOC_IVP_ADDR_MON3_ADDR_LEN_ADDR(base) ((base) + (0x0444))
#define SOC_IVP_ADDR_MON3_HIT_AWADDR_ADDR(base) ((base) + (0x0448))
#define SOC_IVP_ADDR_MON3_HIT_ARADDR_ADDR(base) ((base) + (0x044C))
#define SOC_IVP_ADDR_MON4_ADDR_BASE_ADDR(base) ((base) + (0x0450))
#define SOC_IVP_ADDR_MON4_ADDR_LEN_ADDR(base) ((base) + (0x0454))
#define SOC_IVP_ADDR_MON4_HIT_AWADDR_ADDR(base) ((base) + (0x0458))
#define SOC_IVP_ADDR_MON4_HIT_ARADDR_ADDR(base) ((base) + (0x045C))
#define SOC_IVP_ADDR_MON5_ADDR_BASE_ADDR(base) ((base) + (0x0460))
#define SOC_IVP_ADDR_MON5_ADDR_LEN_ADDR(base) ((base) + (0x0464))
#define SOC_IVP_ADDR_MON5_HIT_AWADDR_ADDR(base) ((base) + (0x0468))
#define SOC_IVP_ADDR_MON5_HIT_ARADDR_ADDR(base) ((base) + (0x046C))
#define SOC_IVP_ADDR_MON6_ADDR_BASE_ADDR(base) ((base) + (0x0470))
#define SOC_IVP_ADDR_MON6_ADDR_LEN_ADDR(base) ((base) + (0x0474))
#define SOC_IVP_ADDR_MON6_HIT_AWADDR_ADDR(base) ((base) + (0x0478))
#define SOC_IVP_ADDR_MON6_HIT_ARADDR_ADDR(base) ((base) + (0x047C))
#define SOC_IVP_ADDR_MON7_ADDR_BASE_ADDR(base) ((base) + (0x0480))
#define SOC_IVP_ADDR_MON7_ADDR_LEN_ADDR(base) ((base) + (0x0484))
#define SOC_IVP_ADDR_MON7_HIT_AWADDR_ADDR(base) ((base) + (0x0488))
#define SOC_IVP_ADDR_MON7_HIT_ARADDR_ADDR(base) ((base) + (0x048C))
#define SOC_IVP_SMMU_SW_GT_ADDR(base) ((base) + (0x0500))
#define SOC_IVP_SMMU_GT_ST_ADDR(base) ((base) + (0x0504))
#define SOC_IVP_SMMU_HW_GT_CNT_ADDR(base) ((base) + (0x050C))
#define SOC_IVP_SMMU_RST_EN_ADDR(base) ((base) + (0x0510))
#define SOC_IVP_SMMU_RST_DIS_ADDR(base) ((base) + (0x0514))
#define SOC_IVP_SMMU_RST_ST_ADDR(base) ((base) + (0x0518))
#define SOC_IVP_FAMA_CTRL0_ADDR(base) ((base) + (0x0530))
#define SOC_IVP_FAMA_ADDR_REMAP0_0_ADDR(base) ((base) + (0x0534))
#define SOC_IVP_FAMA_ADDR_REMAP0_1_ADDR(base) ((base) + (0x0538))
#define SOC_IVP_FAMA_ADDR_REMAP0_2_ADDR(base) ((base) + (0x053C))
#define SOC_IVP_FAMA_ADDR_REMAP1_0_ADDR(base) ((base) + (0x0540))
#define SOC_IVP_FAMA_ADDR_REMAP1_1_ADDR(base) ((base) + (0x0544))
#define SOC_IVP_FAMA_ADDR_REMAP1_2_ADDR(base) ((base) + (0x0548))
#define SOC_IVP_FAMA_ADDR_REMAP2_0_ADDR(base) ((base) + (0x054C))
#define SOC_IVP_FAMA_ADDR_REMAP2_1_ADDR(base) ((base) + (0x0550))
#define SOC_IVP_FAMA_ADDR_REMAP2_2_ADDR(base) ((base) + (0x0554))
#define SOC_IVP_FAMA_ADDR_REMAP3_0_ADDR(base) ((base) + (0x0558))
#define SOC_IVP_FAMA_ADDR_REMAP3_1_ADDR(base) ((base) + (0x055C))
#define SOC_IVP_FAMA_ADDR_REMAP3_2_ADDR(base) ((base) + (0x0560))
#define SOC_IVP_DEBUG_SIG_GRP1_ADDR(base) ((base) + (0x0600))
#define SOC_IVP_DEBUG_SIG_GRP2_ADDR(base) ((base) + (0x0604))
#define SOC_IVP_DEBUG_SIG_GRP3_ADDR(base) ((base) + (0x0608))
#define SOC_IVP_DEBUG_SIG_GRP4_ADDR(base) ((base) + (0x060C))
#define SOC_IVP_DEBUG_SIG_GRP5_ADDR(base) ((base) + (0x0610))
#define SOC_IVP_DEBUG_SIG_GRP6_ADDR(base) ((base) + (0x0614))
#define SOC_IVP_DEBUG_SIG_GRP7_ADDR(base) ((base) + (0x0618))
#define SOC_IVP_DEBUG_SIG_GRP8_ADDR(base) ((base) + (0x061C))
#define SOC_IVP_SUBSYS_VERSION_NUM_ADDR(base) ((base) + (0x0800))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IVP_IVP32_SLV_SEC_SEL_ADDR(base) ((base) + (0x0300UL))
#define SOC_IVP_IVP32_MST_SEC_SEL_ADDR(base) ((base) + (0x0304UL))
#define SOC_IVP_APB_IF_SEC_SEL_ADDR(base) ((base) + (0x0308UL))
#define SOC_IVP_START_REMAP_ADDR_ADDR(base) ((base) + (0x0314UL))
#define SOC_IVP_REMAP_LENGTH_ADDR(base) ((base) + (0x0318UL))
#define SOC_IVP_DDR_REMAP_ADDR_ADDR(base) ((base) + (0x031CUL))
#define SOC_IVP_REMAP_SECURITY_CFG_ADDR(base) ((base) + (0x0334UL))
#define SOC_IVP_IVP32_MST_MID_CFG_ADDR(base) ((base) + (0x0338UL))
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_ADDR(base) ((base) + (0x0344UL))
#define SOC_IVP_SMMU_INTEG_SEC_OVERRIDE_ADDR(base) ((base) + (0x051CUL))
#define SOC_IVP_SMMU_SPNIDEN_ADDR(base) ((base) + (0x0520UL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START0_ADDR(base) ((base) + (0x0580UL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END0_ADDR(base) ((base) + (0x0584UL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START1_ADDR(base) ((base) + (0x0588UL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END1_ADDR(base) ((base) + (0x058CUL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START2_ADDR(base) ((base) + (0x0590UL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END2_ADDR(base) ((base) + (0x0594UL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START3_ADDR(base) ((base) + (0x0598UL))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END3_ADDR(base) ((base) + (0x059CUL))
#define SOC_IVP_SYSCACHE_HINT_ADDR(base) ((base) + (0x05A0UL))
#define SOC_IVP_SYSCACHE_HINT_SECURITY_CFG_ADDR(base) ((base) + (0x05A4UL))
#else
#define SOC_IVP_IVP32_SLV_SEC_SEL_ADDR(base) ((base) + (0x0300))
#define SOC_IVP_IVP32_MST_SEC_SEL_ADDR(base) ((base) + (0x0304))
#define SOC_IVP_APB_IF_SEC_SEL_ADDR(base) ((base) + (0x0308))
#define SOC_IVP_START_REMAP_ADDR_ADDR(base) ((base) + (0x0314))
#define SOC_IVP_REMAP_LENGTH_ADDR(base) ((base) + (0x0318))
#define SOC_IVP_DDR_REMAP_ADDR_ADDR(base) ((base) + (0x031C))
#define SOC_IVP_REMAP_SECURITY_CFG_ADDR(base) ((base) + (0x0334))
#define SOC_IVP_IVP32_MST_MID_CFG_ADDR(base) ((base) + (0x0338))
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_ADDR(base) ((base) + (0x0344))
#define SOC_IVP_SMMU_INTEG_SEC_OVERRIDE_ADDR(base) ((base) + (0x051C))
#define SOC_IVP_SMMU_SPNIDEN_ADDR(base) ((base) + (0x0520))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START0_ADDR(base) ((base) + (0x0580))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END0_ADDR(base) ((base) + (0x0584))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START1_ADDR(base) ((base) + (0x0588))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END1_ADDR(base) ((base) + (0x058C))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START2_ADDR(base) ((base) + (0x0590))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END2_ADDR(base) ((base) + (0x0594))
#define SOC_IVP_SYSCACHE_HINT_ADDR_START3_ADDR(base) ((base) + (0x0598))
#define SOC_IVP_SYSCACHE_HINT_ADDR_END3_ADDR(base) ((base) + (0x059C))
#define SOC_IVP_SYSCACHE_HINT_ADDR(base) ((base) + (0x05A0))
#define SOC_IVP_SYSCACHE_HINT_SECURITY_CFG_ADDR(base) ((base) + (0x05A4))
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
} SOC_IVP_PRID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_dsp_ocdhaltonreset : 1;
        unsigned int reserved_0 : 15;
        unsigned int rpdebugenable : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_IVP_OCDHALTONRESET_UNION;
#endif
#define SOC_IVP_OCDHALTONRESET_ivp32_dsp_ocdhaltonreset_START (0)
#define SOC_IVP_OCDHALTONRESET_ivp32_dsp_ocdhaltonreset_END (0)
#define SOC_IVP_OCDHALTONRESET_rpdebugenable_START (16)
#define SOC_IVP_OCDHALTONRESET_rpdebugenable_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_dsp_statvectorsel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IVP_STATVECTORSEL_UNION;
#endif
#define SOC_IVP_STATVECTORSEL_ivp32_dsp_statvectorsel_START (0)
#define SOC_IVP_STATVECTORSEL_ivp32_dsp_statvectorsel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_dsp_runstall : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IVP_RUNSTALL_UNION;
#endif
#define SOC_IVP_RUNSTALL_ivp32_dsp_runstall_START (0)
#define SOC_IVP_RUNSTALL_ivp32_dsp_runstall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_dsp_pwaitmode : 1;
        unsigned int reserved_0 : 7;
        unsigned int PDebugiDMA : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_IVP_PWAITMODE_UNION;
#endif
#define SOC_IVP_PWAITMODE_ivp32_dsp_pwaitmode_START (0)
#define SOC_IVP_PWAITMODE_ivp32_dsp_pwaitmode_END (0)
#define SOC_IVP_PWAITMODE_PDebugiDMA_START (8)
#define SOC_IVP_PWAITMODE_PDebugiDMA_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_normal_ns_ipc : 1;
        unsigned int intr0_ns_ipc : 1;
        unsigned int intr1_ns_ipc : 1;
        unsigned int intr_normal_s_ipc : 1;
        unsigned int intr0_s_ipc : 1;
        unsigned int intr1_s_ipc : 1;
        unsigned int intr_timer0_0 : 1;
        unsigned int intr_timer0_1 : 1;
        unsigned int intr_ipp2ivp[0] : 1;
        unsigned int intr_ipp2ivp[1] : 1;
        unsigned int intr_ipp2ivp[2] : 1;
        unsigned int intr_ipp2ivp[3] : 1;
        unsigned int intr_uart_print : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ivp_dsp_nmi : 1;
        unsigned int reserved_2 : 1;
        unsigned int vic0_out_irq_reg : 1;
        unsigned int intr_wdg : 1;
        unsigned int intr_ipp2ivp[4] : 1;
        unsigned int intr_ipp2ivp[5] : 1;
        unsigned int intr_ipp2ivp[6] : 1;
        unsigned int intr_ipp2ivp[7] : 1;
        unsigned int intr_nonsecure_npu_mbx2ivp32 : 2;
        unsigned int intr_secure_npu_mbx2ivp32 : 2;
        unsigned int intr_nonsecure_npu_ipc2ivp32 : 1;
        unsigned int intr_secure_npu_ipc2ivp32 : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_IVP_BINTERRUPT_UNION;
#endif
#define SOC_IVP_BINTERRUPT_intr_normal_ns_ipc_START (0)
#define SOC_IVP_BINTERRUPT_intr_normal_ns_ipc_END (0)
#define SOC_IVP_BINTERRUPT_intr0_ns_ipc_START (1)
#define SOC_IVP_BINTERRUPT_intr0_ns_ipc_END (1)
#define SOC_IVP_BINTERRUPT_intr1_ns_ipc_START (2)
#define SOC_IVP_BINTERRUPT_intr1_ns_ipc_END (2)
#define SOC_IVP_BINTERRUPT_intr_normal_s_ipc_START (3)
#define SOC_IVP_BINTERRUPT_intr_normal_s_ipc_END (3)
#define SOC_IVP_BINTERRUPT_intr0_s_ipc_START (4)
#define SOC_IVP_BINTERRUPT_intr0_s_ipc_END (4)
#define SOC_IVP_BINTERRUPT_intr1_s_ipc_START (5)
#define SOC_IVP_BINTERRUPT_intr1_s_ipc_END (5)
#define SOC_IVP_BINTERRUPT_intr_timer0_0_START (6)
#define SOC_IVP_BINTERRUPT_intr_timer0_0_END (6)
#define SOC_IVP_BINTERRUPT_intr_timer0_1_START (7)
#define SOC_IVP_BINTERRUPT_intr_timer0_1_END (7)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [0]_START (8)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [0]_END (8)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [1]_START (9)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [1]_END (9)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [2]_START (10)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [2]_END (10)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [3]_START (11)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [3]_END (11)
#define SOC_IVP_BINTERRUPT_intr_uart_print_START (12)
#define SOC_IVP_BINTERRUPT_intr_uart_print_END (12)
#define SOC_IVP_BINTERRUPT_ivp_dsp_nmi_START (15)
#define SOC_IVP_BINTERRUPT_ivp_dsp_nmi_END (15)
#define SOC_IVP_BINTERRUPT_vic0_out_irq_reg_START (17)
#define SOC_IVP_BINTERRUPT_vic0_out_irq_reg_END (17)
#define SOC_IVP_BINTERRUPT_intr_wdg_START (18)
#define SOC_IVP_BINTERRUPT_intr_wdg_END (18)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [4]_START (19)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [4]_END (19)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [5]_START (20)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [5]_END (20)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [6]_START (21)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [6]_END (21)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [7]_START (22)
#define SOC_IVP_BINTERRUPT_intr_ipp2ivp [7]_END (22)
#define SOC_IVP_BINTERRUPT_intr_nonsecure_npu_mbx2ivp32_START (23)
#define SOC_IVP_BINTERRUPT_intr_nonsecure_npu_mbx2ivp32_END (24)
#define SOC_IVP_BINTERRUPT_intr_secure_npu_mbx2ivp32_START (25)
#define SOC_IVP_BINTERRUPT_intr_secure_npu_mbx2ivp32_END (26)
#define SOC_IVP_BINTERRUPT_intr_nonsecure_npu_ipc2ivp32_START (27)
#define SOC_IVP_BINTERRUPT_intr_nonsecure_npu_ipc2ivp32_END (27)
#define SOC_IVP_BINTERRUPT_intr_secure_npu_ipc2ivp32_START (28)
#define SOC_IVP_BINTERRUPT_intr_secure_npu_ipc2ivp32_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_dsp_nmi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IVP_NMI_UNION;
#endif
#define SOC_IVP_NMI_ivp32_dsp_nmi_START (0)
#define SOC_IVP_NMI_ivp32_dsp_nmi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic0_out_irq_mask : 32;
    } reg;
} SOC_IVP_VIC0_OUT0_UNION;
#endif
#define SOC_IVP_VIC0_OUT0_vic0_out_irq_mask_START (0)
#define SOC_IVP_VIC0_OUT0_vic0_out_irq_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic0_out_irq_raw : 32;
    } reg;
} SOC_IVP_VIC0_OUT1_UNION;
#endif
#define SOC_IVP_VIC0_OUT1_vic0_out_irq_raw_START (0)
#define SOC_IVP_VIC0_OUT1_vic0_out_irq_raw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic0_in_irq_level_mask : 32;
    } reg;
} SOC_IVP_VIC0_IN0_UNION;
#endif
#define SOC_IVP_VIC0_IN0_vic0_in_irq_level_mask_START (0)
#define SOC_IVP_VIC0_IN0_vic0_in_irq_level_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vic0_in_irq_level_force : 32;
    } reg;
} SOC_IVP_VIC0_IN1_UNION;
#endif
#define SOC_IVP_VIC0_IN1_vic0_in_irq_level_force_START (0)
#define SOC_IVP_VIC0_IN1_vic0_in_irq_level_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ivp32_debug_en : 1;
        unsigned int rst_ivp32_processor_en : 1;
        unsigned int rst_ivp32_jtag_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_IVP_DSP_CORE_RESET_EN_UNION;
#endif
#define SOC_IVP_DSP_CORE_RESET_EN_rst_ivp32_debug_en_START (0)
#define SOC_IVP_DSP_CORE_RESET_EN_rst_ivp32_debug_en_END (0)
#define SOC_IVP_DSP_CORE_RESET_EN_rst_ivp32_processor_en_START (1)
#define SOC_IVP_DSP_CORE_RESET_EN_rst_ivp32_processor_en_END (1)
#define SOC_IVP_DSP_CORE_RESET_EN_rst_ivp32_jtag_en_START (2)
#define SOC_IVP_DSP_CORE_RESET_EN_rst_ivp32_jtag_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ivp32_debug_dis : 1;
        unsigned int rst_ivp32_processor_dis : 1;
        unsigned int rst_ivp32_jtag_dis : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_IVP_DSP_CORE_RESET_DIS_UNION;
#endif
#define SOC_IVP_DSP_CORE_RESET_DIS_rst_ivp32_debug_dis_START (0)
#define SOC_IVP_DSP_CORE_RESET_DIS_rst_ivp32_debug_dis_END (0)
#define SOC_IVP_DSP_CORE_RESET_DIS_rst_ivp32_processor_dis_START (1)
#define SOC_IVP_DSP_CORE_RESET_DIS_rst_ivp32_processor_dis_END (1)
#define SOC_IVP_DSP_CORE_RESET_DIS_rst_ivp32_jtag_dis_START (2)
#define SOC_IVP_DSP_CORE_RESET_DIS_rst_ivp32_jtag_dis_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_ivp32_debug : 1;
        unsigned int rst_ivp32_processor : 1;
        unsigned int rst_ivp32_jtag : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_IVP_DSP_CORE_RESET_STATUS_UNION;
#endif
#define SOC_IVP_DSP_CORE_RESET_STATUS_rst_ivp32_debug_START (0)
#define SOC_IVP_DSP_CORE_RESET_STATUS_rst_ivp32_debug_END (0)
#define SOC_IVP_DSP_CORE_RESET_STATUS_rst_ivp32_processor_START (1)
#define SOC_IVP_DSP_CORE_RESET_STATUS_rst_ivp32_processor_END (1)
#define SOC_IVP_DSP_CORE_RESET_STATUS_rst_ivp32_jtag_START (2)
#define SOC_IVP_DSP_CORE_RESET_STATUS_rst_ivp32_jtag_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int refclk_sel_timer0_0 : 1;
        unsigned int refclk_sel_timer0_1 : 1;
        unsigned int refclk_sel_timer1_0 : 1;
        unsigned int refclk_sel_timer1_1 : 1;
        unsigned int refclk_sel_watchdog : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_IVP_REF_CLOCK_SEL_UNION;
#endif
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer0_0_START (0)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer0_0_END (0)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer0_1_START (1)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer0_1_END (1)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer1_0_START (2)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer1_0_END (2)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer1_1_START (3)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_timer1_1_END (3)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_watchdog_START (4)
#define SOC_IVP_REF_CLOCK_SEL_refclk_sel_watchdog_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_watchdog_if : 1;
        unsigned int gt_pclk_watchdog_cnt : 1;
        unsigned int gt_pclk_timer0_if : 1;
        unsigned int gt_pclk_timer0_cnt : 1;
        unsigned int gt_pclk_timer1_if : 1;
        unsigned int gt_pclk_timer1_cnt : 1;
        unsigned int ivp_vp_dma_clken : 1;
        unsigned int ivp_vp_dma_cfg_clken : 1;
        unsigned int ivp_vp_x2p_cfg_clken : 1;
        unsigned int ivp_vp_cfg_clken : 1;
        unsigned int gt_clk_ivp_hwa0 : 1;
        unsigned int gt_clk_ivp_hwa1 : 1;
        unsigned int gt_clk_ivp_hwa_apb_slv : 1;
        unsigned int gt_clk_ivp_hwa_apb_mst : 1;
        unsigned int gt_pclk_dpm_cfg : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_IVP_APB_GATE_CLOCK_UNION;
#endif
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_watchdog_if_START (0)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_watchdog_if_END (0)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_watchdog_cnt_START (1)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_watchdog_cnt_END (1)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer0_if_START (2)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer0_if_END (2)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer0_cnt_START (3)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer0_cnt_END (3)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer1_if_START (4)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer1_if_END (4)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer1_cnt_START (5)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_timer1_cnt_END (5)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_dma_clken_START (6)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_dma_clken_END (6)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_dma_cfg_clken_START (7)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_dma_cfg_clken_END (7)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_x2p_cfg_clken_START (8)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_x2p_cfg_clken_END (8)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_cfg_clken_START (9)
#define SOC_IVP_APB_GATE_CLOCK_ivp_vp_cfg_clken_END (9)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa0_START (10)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa0_END (10)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa1_START (11)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa1_END (11)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa_apb_slv_START (12)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa_apb_slv_END (12)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa_apb_mst_START (13)
#define SOC_IVP_APB_GATE_CLOCK_gt_clk_ivp_hwa_apb_mst_END (13)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_dpm_cfg_START (14)
#define SOC_IVP_APB_GATE_CLOCK_gt_pclk_dpm_cfg_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_axi_m1_cg_en : 1;
        unsigned int dw_axi_m2_cg_en : 1;
        unsigned int dw_axi_s1_cg_en : 1;
        unsigned int dw_axi_s2_cg_en : 1;
        unsigned int dw_axi_s3_cg_en : 1;
        unsigned int dw_axi_s4_cg_en : 1;
        unsigned int dw_axi_s5_cg_en : 1;
        unsigned int defaut_slv_cg_en : 1;
        unsigned int x2p_pclk_cg_en : 1;
        unsigned int x2p_aclk_cg_en : 1;
        unsigned int ivp32_cfg_pclk_cg_en : 1;
        unsigned int x2x_aclk_cg_en : 1;
        unsigned int dma_x2x_aclk_cg_en : 1;
        unsigned int data_mst_x2x_aclk_cg_en : 1;
        unsigned int inst_mst_x2x_aclk_cg_en : 1;
        unsigned int data_slv_x2x_aclk_cg_en : 1;
        unsigned int inst_slv_x2x_aclk_cg_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_IVP_BUS_GATE_CLOCK_UNION;
#endif
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_m1_cg_en_START (0)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_m1_cg_en_END (0)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_m2_cg_en_START (1)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_m2_cg_en_END (1)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s1_cg_en_START (2)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s1_cg_en_END (2)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s2_cg_en_START (3)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s2_cg_en_END (3)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s3_cg_en_START (4)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s3_cg_en_END (4)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s4_cg_en_START (5)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s4_cg_en_END (5)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s5_cg_en_START (6)
#define SOC_IVP_BUS_GATE_CLOCK_dw_axi_s5_cg_en_END (6)
#define SOC_IVP_BUS_GATE_CLOCK_defaut_slv_cg_en_START (7)
#define SOC_IVP_BUS_GATE_CLOCK_defaut_slv_cg_en_END (7)
#define SOC_IVP_BUS_GATE_CLOCK_x2p_pclk_cg_en_START (8)
#define SOC_IVP_BUS_GATE_CLOCK_x2p_pclk_cg_en_END (8)
#define SOC_IVP_BUS_GATE_CLOCK_x2p_aclk_cg_en_START (9)
#define SOC_IVP_BUS_GATE_CLOCK_x2p_aclk_cg_en_END (9)
#define SOC_IVP_BUS_GATE_CLOCK_ivp32_cfg_pclk_cg_en_START (10)
#define SOC_IVP_BUS_GATE_CLOCK_ivp32_cfg_pclk_cg_en_END (10)
#define SOC_IVP_BUS_GATE_CLOCK_x2x_aclk_cg_en_START (11)
#define SOC_IVP_BUS_GATE_CLOCK_x2x_aclk_cg_en_END (11)
#define SOC_IVP_BUS_GATE_CLOCK_dma_x2x_aclk_cg_en_START (12)
#define SOC_IVP_BUS_GATE_CLOCK_dma_x2x_aclk_cg_en_END (12)
#define SOC_IVP_BUS_GATE_CLOCK_data_mst_x2x_aclk_cg_en_START (13)
#define SOC_IVP_BUS_GATE_CLOCK_data_mst_x2x_aclk_cg_en_END (13)
#define SOC_IVP_BUS_GATE_CLOCK_inst_mst_x2x_aclk_cg_en_START (14)
#define SOC_IVP_BUS_GATE_CLOCK_inst_mst_x2x_aclk_cg_en_END (14)
#define SOC_IVP_BUS_GATE_CLOCK_data_slv_x2x_aclk_cg_en_START (15)
#define SOC_IVP_BUS_GATE_CLOCK_data_slv_x2x_aclk_cg_en_END (15)
#define SOC_IVP_BUS_GATE_CLOCK_inst_slv_x2x_aclk_cg_en_START (16)
#define SOC_IVP_BUS_GATE_CLOCK_inst_slv_x2x_aclk_cg_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32timer0_en : 1;
        unsigned int ip_rst_ivp32timer1_en : 1;
        unsigned int ip_rst_ivp32watchdog_en : 1;
        unsigned int ivp_vp_dma_soft_rst_en : 1;
        unsigned int ivp_vp_dma_cfg_soft_rst_en : 1;
        unsigned int ip_rst_ivp_hwa0_en : 1;
        unsigned int ip_rst_ivp_hwa1_en : 1;
        unsigned int ip_rst_ivp32dpm : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_IVP_TIMER_WDG_RST_EN_UNION;
#endif
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32timer0_en_START (0)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32timer0_en_END (0)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32timer1_en_START (1)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32timer1_en_END (1)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32watchdog_en_START (2)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32watchdog_en_END (2)
#define SOC_IVP_TIMER_WDG_RST_EN_ivp_vp_dma_soft_rst_en_START (3)
#define SOC_IVP_TIMER_WDG_RST_EN_ivp_vp_dma_soft_rst_en_END (3)
#define SOC_IVP_TIMER_WDG_RST_EN_ivp_vp_dma_cfg_soft_rst_en_START (4)
#define SOC_IVP_TIMER_WDG_RST_EN_ivp_vp_dma_cfg_soft_rst_en_END (4)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp_hwa0_en_START (5)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp_hwa0_en_END (5)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp_hwa1_en_START (6)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp_hwa1_en_END (6)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32dpm_START (7)
#define SOC_IVP_TIMER_WDG_RST_EN_ip_rst_ivp32dpm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32timer0_dis : 1;
        unsigned int ip_rst_ivp32timer1_dis : 1;
        unsigned int ip_rst_ivp32watchdog_dis : 1;
        unsigned int ivp_vp_dma_soft_rst_dis : 1;
        unsigned int ivp_vp_dma_cfg_soft_rst_dis : 1;
        unsigned int ip_rst_ivp_hwa0_dis : 1;
        unsigned int ip_rst_ivp_hwa1_dis : 1;
        unsigned int ip_rst_ivp32dpm_dis : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_IVP_TIMER_WDG_RST_DIS_UNION;
#endif
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32timer0_dis_START (0)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32timer0_dis_END (0)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32timer1_dis_START (1)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32timer1_dis_END (1)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32watchdog_dis_START (2)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32watchdog_dis_END (2)
#define SOC_IVP_TIMER_WDG_RST_DIS_ivp_vp_dma_soft_rst_dis_START (3)
#define SOC_IVP_TIMER_WDG_RST_DIS_ivp_vp_dma_soft_rst_dis_END (3)
#define SOC_IVP_TIMER_WDG_RST_DIS_ivp_vp_dma_cfg_soft_rst_dis_START (4)
#define SOC_IVP_TIMER_WDG_RST_DIS_ivp_vp_dma_cfg_soft_rst_dis_END (4)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp_hwa0_dis_START (5)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp_hwa0_dis_END (5)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp_hwa1_dis_START (6)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp_hwa1_dis_END (6)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32dpm_dis_START (7)
#define SOC_IVP_TIMER_WDG_RST_DIS_ip_rst_ivp32dpm_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32timer0 : 1;
        unsigned int ip_rst_ivp32timer1 : 1;
        unsigned int ip_rst_ivp32watchdog : 1;
        unsigned int ivp_vp_dma_soft_rst : 1;
        unsigned int ivp_vp_dma_cfg_soft_rst : 1;
        unsigned int ip_rst_ivp_hwa0 : 1;
        unsigned int ip_rst_ivp_hwa1 : 1;
        unsigned int ip_rst_ivp32dpm : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_IVP_TIMER_WDG_RST_STATUS_UNION;
#endif
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32timer0_START (0)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32timer0_END (0)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32timer1_START (1)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32timer1_END (1)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32watchdog_START (2)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32watchdog_END (2)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ivp_vp_dma_soft_rst_START (3)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ivp_vp_dma_soft_rst_END (3)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ivp_vp_dma_cfg_soft_rst_START (4)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ivp_vp_dma_cfg_soft_rst_END (4)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp_hwa0_START (5)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp_hwa0_END (5)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp_hwa1_START (6)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp_hwa1_END (6)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32dpm_START (7)
#define SOC_IVP_TIMER_WDG_RST_STATUS_ip_rst_ivp32dpm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ivp32dsp_core : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IVP_DSPCORE_GATE_UNION;
#endif
#define SOC_IVP_DSPCORE_GATE_gt_clk_ivp32dsp_core_START (0)
#define SOC_IVP_DSPCORE_GATE_gt_clk_ivp32dsp_core_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_ivp32dsp_core : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IVP_DSPCRE_GATE_ST_UNION;
#endif
#define SOC_IVP_DSPCRE_GATE_ST_st_clk_ivp32dsp_core_START (0)
#define SOC_IVP_DSPCRE_GATE_ST_st_clk_ivp32dsp_core_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbgen : 1;
        unsigned int niden : 1;
        unsigned int spiden : 1;
        unsigned int spniden : 1;
        unsigned int ivp_cfg_reserved_a0_ctrl : 28;
    } reg;
} SOC_IVP_DEBUG_CONTROL_UNION;
#endif
#define SOC_IVP_DEBUG_CONTROL_dbgen_START (0)
#define SOC_IVP_DEBUG_CONTROL_dbgen_END (0)
#define SOC_IVP_DEBUG_CONTROL_niden_START (1)
#define SOC_IVP_DEBUG_CONTROL_niden_END (1)
#define SOC_IVP_DEBUG_CONTROL_spiden_START (2)
#define SOC_IVP_DEBUG_CONTROL_spiden_END (2)
#define SOC_IVP_DEBUG_CONTROL_spniden_START (3)
#define SOC_IVP_DEBUG_CONTROL_spniden_END (3)
#define SOC_IVP_DEBUG_CONTROL_ivp_cfg_reserved_a0_ctrl_START (4)
#define SOC_IVP_DEBUG_CONTROL_ivp_cfg_reserved_a0_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp_cfg_reserved_a1_ctrl : 32;
    } reg;
} SOC_IVP_RESERVE_FOR_EC1_UNION;
#endif
#define SOC_IVP_RESERVE_FOR_EC1_ivp_cfg_reserved_a1_ctrl_START (0)
#define SOC_IVP_RESERVE_FOR_EC1_ivp_cfg_reserved_a1_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int interconnect_slv1_priority : 3;
        unsigned int interconnect_slv2_priority : 3;
        unsigned int interconnect_slv3_priority : 3;
        unsigned int interconnect_slv4_priority : 3;
        unsigned int interconnect_slv5_priority : 3;
        unsigned int interconnect_slv6_priority : 3;
        unsigned int reserved_0 : 6;
        unsigned int interconnect_mst1_priority : 2;
        unsigned int interconnect_mst2_priority : 2;
        unsigned int interconnect_mst3_priority : 2;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_IVP_INTERCONNECT_PRIORITY_CFG_UNION;
#endif
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv1_priority_START (0)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv1_priority_END (2)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv2_priority_START (3)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv2_priority_END (5)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv3_priority_START (6)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv3_priority_END (8)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv4_priority_START (9)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv4_priority_END (11)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv5_priority_START (12)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv5_priority_END (14)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv6_priority_START (15)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_slv6_priority_END (17)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_mst1_priority_START (24)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_mst1_priority_END (25)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_mst2_priority_START (26)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_mst2_priority_END (27)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_mst3_priority_START (28)
#define SOC_IVP_INTERCONNECT_PRIORITY_CFG_interconnect_mst3_priority_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_dsp_core_awqos : 4;
        unsigned int cfg_dsp_core_arqos : 4;
        unsigned int cfg_micro_dma_awqos : 4;
        unsigned int cfg_micro_dma_arqos : 4;
        unsigned int cfg_dsp_instr_arqos : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_IVP32_SYSTEM_QOS_CFG_UNION;
#endif
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_dsp_core_awqos_START (0)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_dsp_core_awqos_END (3)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_dsp_core_arqos_START (4)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_dsp_core_arqos_END (7)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_micro_dma_awqos_START (8)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_micro_dma_awqos_END (11)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_micro_dma_arqos_START (12)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_micro_dma_arqos_END (15)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_dsp_instr_arqos_START (16)
#define SOC_IVP_IVP32_SYSTEM_QOS_CFG_cfg_dsp_instr_arqos_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_spram_mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_IVP_MEM_CTRL0_UNION;
#endif
#define SOC_IVP_MEM_CTRL0_ivp32_spram_mem_ctrl_s_START (0)
#define SOC_IVP_MEM_CTRL0_ivp32_spram_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_tpram_mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IVP_MEM_CTRL1_UNION;
#endif
#define SOC_IVP_MEM_CTRL1_ivp32_tpram_mem_ctrl_d1w2r_START (0)
#define SOC_IVP_MEM_CTRL1_ivp32_tpram_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_ivp32dsp_wd_apb : 1;
        unsigned int st_clk_ivp32dsp_wd_cnt : 1;
        unsigned int st_clk_ivp32dsp_timer0_apb : 1;
        unsigned int st_clk_ivp32dsp_timer0_cnt : 1;
        unsigned int st_clk_ivp32dsp_timer1_apb : 1;
        unsigned int st_clk_ivp32dsp_timer1_cnt : 1;
        unsigned int st_clk_ivp32dsp_dpm_apb : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_IVP_CRG_PERI_GT_ST_UNION;
#endif
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_wd_apb_START (0)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_wd_apb_END (0)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_wd_cnt_START (1)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_wd_cnt_END (1)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer0_apb_START (2)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer0_apb_END (2)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer0_cnt_START (3)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer0_cnt_END (3)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer1_apb_START (4)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer1_apb_END (4)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer1_cnt_START (5)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_timer1_cnt_END (5)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_dpm_apb_START (6)
#define SOC_IVP_CRG_PERI_GT_ST_st_clk_ivp32dsp_dpm_apb_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass_smmu_slv_awake_mode : 1;
        unsigned int bypass_smmu_cfg_awake_mode : 1;
        unsigned int gt_bclk_smmu0_bypass : 1;
        unsigned int gt_cclk_smmu0_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_IVP_SMMU_AWAKEBYPASS_UNION;
#endif
#define SOC_IVP_SMMU_AWAKEBYPASS_bypass_smmu_slv_awake_mode_START (0)
#define SOC_IVP_SMMU_AWAKEBYPASS_bypass_smmu_slv_awake_mode_END (0)
#define SOC_IVP_SMMU_AWAKEBYPASS_bypass_smmu_cfg_awake_mode_START (1)
#define SOC_IVP_SMMU_AWAKEBYPASS_bypass_smmu_cfg_awake_mode_END (1)
#define SOC_IVP_SMMU_AWAKEBYPASS_gt_bclk_smmu0_bypass_START (2)
#define SOC_IVP_SMMU_AWAKEBYPASS_gt_bclk_smmu0_bypass_END (2)
#define SOC_IVP_SMMU_AWAKEBYPASS_gt_cclk_smmu0_bypass_START (3)
#define SOC_IVP_SMMU_AWAKEBYPASS_gt_cclk_smmu0_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cactive_smmu0_bclk : 1;
        unsigned int cactive_smmu0_cclk : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_SMMU_PWR_HANDSHAKE_ST_UNION;
#endif
#define SOC_IVP_SMMU_PWR_HANDSHAKE_ST_cactive_smmu0_bclk_START (0)
#define SOC_IVP_SMMU_PWR_HANDSHAKE_ST_cactive_smmu0_bclk_END (0)
#define SOC_IVP_SMMU_PWR_HANDSHAKE_ST_cactive_smmu0_cclk_START (1)
#define SOC_IVP_SMMU_PWR_HANDSHAKE_ST_cactive_smmu0_cclk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dlock_bp_timer0 : 1;
        unsigned int dlock_bp_timer1 : 1;
        unsigned int dlock_bp_watchdog : 1;
        unsigned int dlock_bp_vpcfg : 1;
        unsigned int dlock_bp_hwacfg : 1;
        unsigned int dlock_bp_dpm : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_IVP_APB_IF_DLOCK_BYPASS_UNION;
#endif
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_timer0_START (0)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_timer0_END (0)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_timer1_START (1)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_timer1_END (1)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_watchdog_START (2)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_watchdog_END (2)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_vpcfg_START (3)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_vpcfg_END (3)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_hwacfg_START (4)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_hwacfg_END (4)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_dpm_START (5)
#define SOC_IVP_APB_IF_DLOCK_BYPASS_dlock_bp_dpm_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon0_en : 1;
        unsigned int addr_mon1_en : 1;
        unsigned int addr_mon2_en : 1;
        unsigned int addr_mon3_en : 1;
        unsigned int addr_mon4_en : 1;
        unsigned int addr_mon5_en : 1;
        unsigned int addr_mon6_en : 1;
        unsigned int addr_mon7_en : 1;
        unsigned int reserved_0 : 8;
        unsigned int wch_mon_sel : 3;
        unsigned int rch_mon_sel : 3;
        unsigned int reserved_1 : 2;
        unsigned int wch_illegal_remap_en : 1;
        unsigned int rch_illegal_remap_en : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_IVP_ADDR_MON_EN_UNION;
#endif
#define SOC_IVP_ADDR_MON_EN_addr_mon0_en_START (0)
#define SOC_IVP_ADDR_MON_EN_addr_mon0_en_END (0)
#define SOC_IVP_ADDR_MON_EN_addr_mon1_en_START (1)
#define SOC_IVP_ADDR_MON_EN_addr_mon1_en_END (1)
#define SOC_IVP_ADDR_MON_EN_addr_mon2_en_START (2)
#define SOC_IVP_ADDR_MON_EN_addr_mon2_en_END (2)
#define SOC_IVP_ADDR_MON_EN_addr_mon3_en_START (3)
#define SOC_IVP_ADDR_MON_EN_addr_mon3_en_END (3)
#define SOC_IVP_ADDR_MON_EN_addr_mon4_en_START (4)
#define SOC_IVP_ADDR_MON_EN_addr_mon4_en_END (4)
#define SOC_IVP_ADDR_MON_EN_addr_mon5_en_START (5)
#define SOC_IVP_ADDR_MON_EN_addr_mon5_en_END (5)
#define SOC_IVP_ADDR_MON_EN_addr_mon6_en_START (6)
#define SOC_IVP_ADDR_MON_EN_addr_mon6_en_END (6)
#define SOC_IVP_ADDR_MON_EN_addr_mon7_en_START (7)
#define SOC_IVP_ADDR_MON_EN_addr_mon7_en_END (7)
#define SOC_IVP_ADDR_MON_EN_wch_mon_sel_START (16)
#define SOC_IVP_ADDR_MON_EN_wch_mon_sel_END (18)
#define SOC_IVP_ADDR_MON_EN_rch_mon_sel_START (19)
#define SOC_IVP_ADDR_MON_EN_rch_mon_sel_END (21)
#define SOC_IVP_ADDR_MON_EN_wch_illegal_remap_en_START (24)
#define SOC_IVP_ADDR_MON_EN_wch_illegal_remap_en_END (24)
#define SOC_IVP_ADDR_MON_EN_rch_illegal_remap_en_START (25)
#define SOC_IVP_ADDR_MON_EN_rch_illegal_remap_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IVP_ADDR_MON_CLR_UNION;
#endif
#define SOC_IVP_ADDR_MON_CLR_addr_mon_clr_START (0)
#define SOC_IVP_ADDR_MON_CLR_addr_mon_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon0_intr_en : 1;
        unsigned int addr_mon1_intr_en : 1;
        unsigned int addr_mon2_intr_en : 1;
        unsigned int addr_mon3_intr_en : 1;
        unsigned int addr_mon4_intr_en : 1;
        unsigned int addr_mon5_intr_en : 1;
        unsigned int addr_mon6_intr_en : 1;
        unsigned int addr_mon7_intr_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_IVP_ADDR_MON_INTR_EN_UNION;
#endif
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon0_intr_en_START (0)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon0_intr_en_END (0)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon1_intr_en_START (1)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon1_intr_en_END (1)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon2_intr_en_START (2)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon2_intr_en_END (2)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon3_intr_en_START (3)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon3_intr_en_END (3)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon4_intr_en_START (4)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon4_intr_en_END (4)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon5_intr_en_START (5)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon5_intr_en_END (5)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon6_intr_en_START (6)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon6_intr_en_END (6)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon7_intr_en_START (7)
#define SOC_IVP_ADDR_MON_INTR_EN_addr_mon7_intr_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon7_arhit : 1;
        unsigned int addr_mon7_awhit : 1;
        unsigned int addr_mon6_arhit : 1;
        unsigned int addr_mon6_awhit : 1;
        unsigned int addr_mon5_arhit : 1;
        unsigned int addr_mon5_awhit : 1;
        unsigned int addr_mon4_arhit : 1;
        unsigned int addr_mon4_awhit : 1;
        unsigned int addr_mon3_arhit : 1;
        unsigned int addr_mon3_awhit : 1;
        unsigned int addr_mon2_arhit : 1;
        unsigned int addr_mon2_awhit : 1;
        unsigned int addr_mon1_arhit : 1;
        unsigned int addr_mon1_awhit : 1;
        unsigned int addr_mon0_arhit : 1;
        unsigned int addr_mon0_awhit : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_IVP_ADDR_MON_INTR_STAT_UNION;
#endif
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon7_arhit_START (0)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon7_arhit_END (0)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon7_awhit_START (1)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon7_awhit_END (1)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon6_arhit_START (2)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon6_arhit_END (2)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon6_awhit_START (3)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon6_awhit_END (3)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon5_arhit_START (4)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon5_arhit_END (4)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon5_awhit_START (5)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon5_awhit_END (5)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon4_arhit_START (6)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon4_arhit_END (6)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon4_awhit_START (7)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon4_awhit_END (7)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon3_arhit_START (8)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon3_arhit_END (8)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon3_awhit_START (9)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon3_awhit_END (9)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon2_arhit_START (10)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon2_arhit_END (10)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon2_awhit_START (11)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon2_awhit_END (11)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon1_arhit_START (12)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon1_arhit_END (12)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon1_awhit_START (13)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon1_awhit_END (13)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon0_arhit_START (14)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon0_arhit_END (14)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon0_awhit_START (15)
#define SOC_IVP_ADDR_MON_INTR_STAT_addr_mon0_awhit_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon0_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON0_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON0_ADDR_BASE_addr_mon0_addr_base_START (0)
#define SOC_IVP_ADDR_MON0_ADDR_BASE_addr_mon0_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon0_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON0_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON0_ADDR_LEN_addr_mon0_addr_len_START (0)
#define SOC_IVP_ADDR_MON0_ADDR_LEN_addr_mon0_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon0_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON0_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON0_HIT_AWADDR_addr_mon0_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON0_HIT_AWADDR_addr_mon0_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon0_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON0_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON0_HIT_ARADDR_addr_mon0_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON0_HIT_ARADDR_addr_mon0_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon1_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON1_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON1_ADDR_BASE_addr_mon1_addr_base_START (0)
#define SOC_IVP_ADDR_MON1_ADDR_BASE_addr_mon1_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon1_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON1_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON1_ADDR_LEN_addr_mon1_addr_len_START (0)
#define SOC_IVP_ADDR_MON1_ADDR_LEN_addr_mon1_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon1_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON1_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON1_HIT_AWADDR_addr_mon1_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON1_HIT_AWADDR_addr_mon1_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon1_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON1_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON1_HIT_ARADDR_addr_mon1_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON1_HIT_ARADDR_addr_mon1_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon2_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON2_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON2_ADDR_BASE_addr_mon2_addr_base_START (0)
#define SOC_IVP_ADDR_MON2_ADDR_BASE_addr_mon2_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon2_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON2_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON2_ADDR_LEN_addr_mon2_addr_len_START (0)
#define SOC_IVP_ADDR_MON2_ADDR_LEN_addr_mon2_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon2_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON2_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON2_HIT_AWADDR_addr_mon2_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON2_HIT_AWADDR_addr_mon2_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon2_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON2_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON2_HIT_ARADDR_addr_mon2_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON2_HIT_ARADDR_addr_mon2_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon3_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON3_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON3_ADDR_BASE_addr_mon3_addr_base_START (0)
#define SOC_IVP_ADDR_MON3_ADDR_BASE_addr_mon3_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon3_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON3_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON3_ADDR_LEN_addr_mon3_addr_len_START (0)
#define SOC_IVP_ADDR_MON3_ADDR_LEN_addr_mon3_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon3_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON3_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON3_HIT_AWADDR_addr_mon3_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON3_HIT_AWADDR_addr_mon3_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon3_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON3_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON3_HIT_ARADDR_addr_mon3_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON3_HIT_ARADDR_addr_mon3_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon4_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON4_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON4_ADDR_BASE_addr_mon4_addr_base_START (0)
#define SOC_IVP_ADDR_MON4_ADDR_BASE_addr_mon4_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon4_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON4_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON4_ADDR_LEN_addr_mon4_addr_len_START (0)
#define SOC_IVP_ADDR_MON4_ADDR_LEN_addr_mon4_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon4_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON4_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON4_HIT_AWADDR_addr_mon4_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON4_HIT_AWADDR_addr_mon4_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon4_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON4_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON4_HIT_ARADDR_addr_mon4_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON4_HIT_ARADDR_addr_mon4_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon5_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON5_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON5_ADDR_BASE_addr_mon5_addr_base_START (0)
#define SOC_IVP_ADDR_MON5_ADDR_BASE_addr_mon5_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon5_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON5_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON5_ADDR_LEN_addr_mon5_addr_len_START (0)
#define SOC_IVP_ADDR_MON5_ADDR_LEN_addr_mon5_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon5_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON5_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON5_HIT_AWADDR_addr_mon5_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON5_HIT_AWADDR_addr_mon5_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon5_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON5_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON5_HIT_ARADDR_addr_mon5_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON5_HIT_ARADDR_addr_mon5_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon6_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON6_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON6_ADDR_BASE_addr_mon6_addr_base_START (0)
#define SOC_IVP_ADDR_MON6_ADDR_BASE_addr_mon6_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon6_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON6_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON6_ADDR_LEN_addr_mon6_addr_len_START (0)
#define SOC_IVP_ADDR_MON6_ADDR_LEN_addr_mon6_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon6_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON6_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON6_HIT_AWADDR_addr_mon6_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON6_HIT_AWADDR_addr_mon6_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon6_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON6_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON6_HIT_ARADDR_addr_mon6_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON6_HIT_ARADDR_addr_mon6_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon7_addr_base : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON7_ADDR_BASE_UNION;
#endif
#define SOC_IVP_ADDR_MON7_ADDR_BASE_addr_mon7_addr_base_START (0)
#define SOC_IVP_ADDR_MON7_ADDR_BASE_addr_mon7_addr_base_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon7_addr_len : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_ADDR_MON7_ADDR_LEN_UNION;
#endif
#define SOC_IVP_ADDR_MON7_ADDR_LEN_addr_mon7_addr_len_START (0)
#define SOC_IVP_ADDR_MON7_ADDR_LEN_addr_mon7_addr_len_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon7_hit_awaddr : 32;
    } reg;
} SOC_IVP_ADDR_MON7_HIT_AWADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON7_HIT_AWADDR_addr_mon7_hit_awaddr_START (0)
#define SOC_IVP_ADDR_MON7_HIT_AWADDR_addr_mon7_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mon7_hit_araddr : 32;
    } reg;
} SOC_IVP_ADDR_MON7_HIT_ARADDR_UNION;
#endif
#define SOC_IVP_ADDR_MON7_HIT_ARADDR_addr_mon7_hit_araddr_START (0)
#define SOC_IVP_ADDR_MON7_HIT_ARADDR_addr_mon7_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_bclk_smmu0_soft : 1;
        unsigned int gt_cclk_smmu0_soft : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_SMMU_SW_GT_UNION;
#endif
#define SOC_IVP_SMMU_SW_GT_gt_bclk_smmu0_soft_START (0)
#define SOC_IVP_SMMU_SW_GT_gt_bclk_smmu0_soft_END (0)
#define SOC_IVP_SMMU_SW_GT_gt_cclk_smmu0_soft_START (1)
#define SOC_IVP_SMMU_SW_GT_gt_cclk_smmu0_soft_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_bclk_smmu0 : 1;
        unsigned int st_cclk_smmu0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_SMMU_GT_ST_UNION;
#endif
#define SOC_IVP_SMMU_GT_ST_st_bclk_smmu0_START (0)
#define SOC_IVP_SMMU_GT_ST_st_bclk_smmu0_END (0)
#define SOC_IVP_SMMU_GT_ST_st_cclk_smmu0_START (1)
#define SOC_IVP_SMMU_GT_ST_st_cclk_smmu0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cactive_smmu0_bclk_cnt : 6;
        unsigned int cactive_smmu0_cclk_cnt : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_IVP_SMMU_HW_GT_CNT_UNION;
#endif
#define SOC_IVP_SMMU_HW_GT_CNT_cactive_smmu0_bclk_cnt_START (0)
#define SOC_IVP_SMMU_HW_GT_CNT_cactive_smmu0_bclk_cnt_END (5)
#define SOC_IVP_SMMU_HW_GT_CNT_cactive_smmu0_cclk_cnt_START (6)
#define SOC_IVP_SMMU_HW_GT_CNT_cactive_smmu0_cclk_cnt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_brst_smmu0_en : 1;
        unsigned int ip_crst_smmu0_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_SMMU_RST_EN_UNION;
#endif
#define SOC_IVP_SMMU_RST_EN_ip_brst_smmu0_en_START (0)
#define SOC_IVP_SMMU_RST_EN_ip_brst_smmu0_en_END (0)
#define SOC_IVP_SMMU_RST_EN_ip_crst_smmu0_en_START (1)
#define SOC_IVP_SMMU_RST_EN_ip_crst_smmu0_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_brst_smmu0_dis : 1;
        unsigned int ip_crst_smmu0_dis : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_SMMU_RST_DIS_UNION;
#endif
#define SOC_IVP_SMMU_RST_DIS_ip_brst_smmu0_dis_START (0)
#define SOC_IVP_SMMU_RST_DIS_ip_brst_smmu0_dis_END (0)
#define SOC_IVP_SMMU_RST_DIS_ip_crst_smmu0_dis_START (1)
#define SOC_IVP_SMMU_RST_DIS_ip_crst_smmu0_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_brst_smmu0 : 1;
        unsigned int ip_crst_smmu0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_SMMU_RST_ST_UNION;
#endif
#define SOC_IVP_SMMU_RST_ST_ip_brst_smmu0_START (0)
#define SOC_IVP_SMMU_RST_ST_ip_brst_smmu0_END (0)
#define SOC_IVP_SMMU_RST_ST_ip_crst_smmu0_START (1)
#define SOC_IVP_SMMU_RST_ST_ip_crst_smmu0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 5;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 7;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 7;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 7;
    } reg;
} SOC_IVP_FAMA_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_scr0_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP0_0_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP0_0_icfg_addr_scr0_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP0_0_icfg_addr_scr0_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_len0_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP0_1_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP0_1_icfg_addr_len0_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP0_1_icfg_addr_len0_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 22;
        unsigned int reserved_1 : 5;
        unsigned int icfg_addr_dst0_reserved : 5;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP0_2_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP0_2_icfg_addr_dst0_reserved_START (27)
#define SOC_IVP_FAMA_ADDR_REMAP0_2_icfg_addr_dst0_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr1 : 22;
        unsigned int icfg_addr_scr1_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP1_0_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP1_0_icfg_addr_scr1_START (0)
#define SOC_IVP_FAMA_ADDR_REMAP1_0_icfg_addr_scr1_END (21)
#define SOC_IVP_FAMA_ADDR_REMAP1_0_icfg_addr_scr1_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP1_0_icfg_addr_scr1_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_len1_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP1_1_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP1_1_icfg_addr_len1_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP1_1_icfg_addr_len1_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 27;
        unsigned int icfg_addr_dst1_reserved : 5;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP1_2_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP1_2_icfg_addr_dst1_reserved_START (27)
#define SOC_IVP_FAMA_ADDR_REMAP1_2_icfg_addr_dst1_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_scr2_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP2_0_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP2_0_icfg_addr_scr2_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP2_0_icfg_addr_scr2_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_len2_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP2_1_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP2_1_icfg_addr_len2_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP2_1_icfg_addr_len2_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 27;
        unsigned int icfg_addr_dst2_reserved : 5;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP2_2_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP2_2_icfg_addr_dst2_reserved_START (27)
#define SOC_IVP_FAMA_ADDR_REMAP2_2_icfg_addr_dst2_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_scr3_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP3_0_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP3_0_icfg_addr_scr3_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP3_0_icfg_addr_scr3_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_len3_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP3_1_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP3_1_icfg_addr_len3_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP3_1_icfg_addr_len3_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 22;
        unsigned int icfg_addr_dst3_reserved : 10;
    } reg;
} SOC_IVP_FAMA_ADDR_REMAP3_2_UNION;
#endif
#define SOC_IVP_FAMA_ADDR_REMAP3_2_icfg_addr_dst3_reserved_START (22)
#define SOC_IVP_FAMA_ADDR_REMAP3_2_icfg_addr_dst3_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all1 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP1_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP1_pdebug_all1_START (0)
#define SOC_IVP_DEBUG_SIG_GRP1_pdebug_all1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all2 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP2_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP2_pdebug_all2_START (0)
#define SOC_IVP_DEBUG_SIG_GRP2_pdebug_all2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all3 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP3_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP3_pdebug_all3_START (0)
#define SOC_IVP_DEBUG_SIG_GRP3_pdebug_all3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all4 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP4_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP4_pdebug_all4_START (0)
#define SOC_IVP_DEBUG_SIG_GRP4_pdebug_all4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all5 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP5_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP5_pdebug_all5_START (0)
#define SOC_IVP_DEBUG_SIG_GRP5_pdebug_all5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all6 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP6_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP6_pdebug_all6_START (0)
#define SOC_IVP_DEBUG_SIG_GRP6_pdebug_all6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all7 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP7_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP7_pdebug_all7_START (0)
#define SOC_IVP_DEBUG_SIG_GRP7_pdebug_all7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdebug_all8 : 32;
    } reg;
} SOC_IVP_DEBUG_SIG_GRP8_UNION;
#endif
#define SOC_IVP_DEBUG_SIG_GRP8_pdebug_all8_START (0)
#define SOC_IVP_DEBUG_SIG_GRP8_pdebug_all8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int subsys_version_num : 32;
    } reg;
} SOC_IVP_SUBSYS_VERSION_NUM_UNION;
#endif
#define SOC_IVP_SUBSYS_VERSION_NUM_subsys_version_num_START (0)
#define SOC_IVP_SUBSYS_VERSION_NUM_subsys_version_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_instr_slv_sec_sel : 1;
        unsigned int ivp32_slv_sec_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_IVP32_SLV_SEC_SEL_UNION;
#endif
#define SOC_IVP_IVP32_SLV_SEC_SEL_ivp32_instr_slv_sec_sel_START (0)
#define SOC_IVP_IVP32_SLV_SEC_SEL_ivp32_instr_slv_sec_sel_END (0)
#define SOC_IVP_IVP32_SLV_SEC_SEL_ivp32_slv_sec_sel_START (0)
#define SOC_IVP_IVP32_SLV_SEC_SEL_ivp32_slv_sec_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int micro_dma_read_sec : 1;
        unsigned int micro_dma_write_sec : 1;
        unsigned int dsp_core_read_sec : 1;
        unsigned int dsp_core_write_sec : 1;
        unsigned int dsp_instr_read_sec : 1;
        unsigned int ivp_trusted_nsaid_en : 1;
        unsigned int ivp_protected_nsaid_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IVP_IVP32_MST_SEC_SEL_UNION;
#endif
#define SOC_IVP_IVP32_MST_SEC_SEL_micro_dma_read_sec_START (0)
#define SOC_IVP_IVP32_MST_SEC_SEL_micro_dma_read_sec_END (0)
#define SOC_IVP_IVP32_MST_SEC_SEL_micro_dma_write_sec_START (1)
#define SOC_IVP_IVP32_MST_SEC_SEL_micro_dma_write_sec_END (1)
#define SOC_IVP_IVP32_MST_SEC_SEL_dsp_core_read_sec_START (2)
#define SOC_IVP_IVP32_MST_SEC_SEL_dsp_core_read_sec_END (2)
#define SOC_IVP_IVP32_MST_SEC_SEL_dsp_core_write_sec_START (3)
#define SOC_IVP_IVP32_MST_SEC_SEL_dsp_core_write_sec_END (3)
#define SOC_IVP_IVP32_MST_SEC_SEL_dsp_instr_read_sec_START (4)
#define SOC_IVP_IVP32_MST_SEC_SEL_dsp_instr_read_sec_END (4)
#define SOC_IVP_IVP32_MST_SEC_SEL_ivp_trusted_nsaid_en_START (5)
#define SOC_IVP_IVP32_MST_SEC_SEL_ivp_trusted_nsaid_en_END (5)
#define SOC_IVP_IVP32_MST_SEC_SEL_ivp_protected_nsaid_en_START (6)
#define SOC_IVP_IVP32_MST_SEC_SEL_ivp_protected_nsaid_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_secure_timer0_n : 1;
        unsigned int tz_secure_timer1_n : 1;
        unsigned int tzsecure_watchdog_n : 1;
        unsigned int tz_secure_cfg_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 10;
        unsigned int tz_secure_timer0_n_wr_en : 1;
        unsigned int tz_secure_timer1_n_wr_en : 1;
        unsigned int tzsecure_watchdog_n_wr_en : 1;
        unsigned int tz_secure_cfg_n_wr_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 10;
    } reg;
} SOC_IVP_APB_IF_SEC_SEL_UNION;
#endif
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer0_n_START (0)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer0_n_END (0)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer1_n_START (1)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer1_n_END (1)
#define SOC_IVP_APB_IF_SEC_SEL_tzsecure_watchdog_n_START (2)
#define SOC_IVP_APB_IF_SEC_SEL_tzsecure_watchdog_n_END (2)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_cfg_n_START (3)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_cfg_n_END (3)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer0_n_wr_en_START (16)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer0_n_wr_en_END (16)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer1_n_wr_en_START (17)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_timer1_n_wr_en_END (17)
#define SOC_IVP_APB_IF_SEC_SEL_tzsecure_watchdog_n_wr_en_START (18)
#define SOC_IVP_APB_IF_SEC_SEL_tzsecure_watchdog_n_wr_en_END (18)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_cfg_n_wr_en_START (19)
#define SOC_IVP_APB_IF_SEC_SEL_tz_secure_cfg_n_wr_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_mst_start_remap_addr : 12;
        unsigned int reserved_0 : 4;
        unsigned int ivp32_instr_start_remap_addr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_IVP_START_REMAP_ADDR_UNION;
#endif
#define SOC_IVP_START_REMAP_ADDR_ivp32_mst_start_remap_addr_START (0)
#define SOC_IVP_START_REMAP_ADDR_ivp32_mst_start_remap_addr_END (11)
#define SOC_IVP_START_REMAP_ADDR_ivp32_instr_start_remap_addr_START (16)
#define SOC_IVP_START_REMAP_ADDR_ivp32_instr_start_remap_addr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_mst_remap_length : 8;
        unsigned int ivp32_instr_remap_length : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_IVP_REMAP_LENGTH_UNION;
#endif
#define SOC_IVP_REMAP_LENGTH_ivp32_mst_remap_length_START (0)
#define SOC_IVP_REMAP_LENGTH_ivp32_mst_remap_length_END (7)
#define SOC_IVP_REMAP_LENGTH_ivp32_instr_remap_length_START (8)
#define SOC_IVP_REMAP_LENGTH_ivp32_instr_remap_length_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivp32_mst_ddr_addr_base : 16;
        unsigned int ivp32_instr_ddr_addr_base : 16;
    } reg;
} SOC_IVP_DDR_REMAP_ADDR_UNION;
#endif
#define SOC_IVP_DDR_REMAP_ADDR_ivp32_mst_ddr_addr_base_START (0)
#define SOC_IVP_DDR_REMAP_ADDR_ivp32_mst_ddr_addr_base_END (15)
#define SOC_IVP_DDR_REMAP_ADDR_ivp32_instr_ddr_addr_base_START (16)
#define SOC_IVP_DDR_REMAP_ADDR_ivp32_instr_ddr_addr_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start_remap_addr_security_sel : 1;
        unsigned int remap_length_security_sel : 1;
        unsigned int ddr_remap_addr_security_sel : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_IVP_REMAP_SECURITY_CFG_UNION;
#endif
#define SOC_IVP_REMAP_SECURITY_CFG_start_remap_addr_security_sel_START (0)
#define SOC_IVP_REMAP_SECURITY_CFG_start_remap_addr_security_sel_END (0)
#define SOC_IVP_REMAP_SECURITY_CFG_remap_length_security_sel_START (1)
#define SOC_IVP_REMAP_SECURITY_CFG_remap_length_security_sel_END (1)
#define SOC_IVP_REMAP_SECURITY_CFG_ddr_remap_addr_security_sel_START (2)
#define SOC_IVP_REMAP_SECURITY_CFG_ddr_remap_addr_security_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_dsp_core_mid : 7;
        unsigned int reserved_0 : 1;
        unsigned int cfg_micro_dma_mid : 7;
        unsigned int reserved_1 : 1;
        unsigned int cfg_dsp_inst_mid : 7;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_IVP_IVP32_MST_MID_CFG_UNION;
#endif
#define SOC_IVP_IVP32_MST_MID_CFG_cfg_dsp_core_mid_START (0)
#define SOC_IVP_IVP32_MST_MID_CFG_cfg_dsp_core_mid_END (6)
#define SOC_IVP_IVP32_MST_MID_CFG_cfg_micro_dma_mid_START (8)
#define SOC_IVP_IVP32_MST_MID_CFG_cfg_micro_dma_mid_END (14)
#define SOC_IVP_IVP32_MST_MID_CFG_cfg_dsp_inst_mid_START (16)
#define SOC_IVP_IVP32_MST_MID_CFG_cfg_dsp_inst_mid_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_dsp_core_awcache : 4;
        unsigned int cfg_dsp_core_arcache : 4;
        unsigned int cfg_dsp_idma_awcache : 4;
        unsigned int cfg_dsp_idma_arcache : 4;
        unsigned int cfg_dsp_inst_arcache : 4;
        unsigned int reserved_0 : 4;
        unsigned int cfg_dsp_core_axcache_override : 1;
        unsigned int cfg_dsp_idma_axcache_override : 1;
        unsigned int cfg_dsp_inst_axcache_override : 1;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_IVP_IVP32_MST_AXCACHE_CFG_UNION;
#endif
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_core_awcache_START (0)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_core_awcache_END (3)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_core_arcache_START (4)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_core_arcache_END (7)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_idma_awcache_START (8)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_idma_awcache_END (11)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_idma_arcache_START (12)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_idma_arcache_END (15)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_inst_arcache_START (16)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_inst_arcache_END (19)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_core_axcache_override_START (24)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_core_axcache_override_END (24)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_idma_axcache_override_START (25)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_idma_axcache_override_END (25)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_inst_axcache_override_START (26)
#define SOC_IVP_IVP32_MST_AXCACHE_CFG_cfg_dsp_inst_axcache_override_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_integ_sec_override : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IVP_SMMU_INTEG_SEC_OVERRIDE_UNION;
#endif
#define SOC_IVP_SMMU_INTEG_SEC_OVERRIDE_smmu_integ_sec_override_START (0)
#define SOC_IVP_SMMU_INTEG_SEC_OVERRIDE_smmu_integ_sec_override_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_spniden : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IVP_SMMU_SPNIDEN_UNION;
#endif
#define SOC_IVP_SMMU_SPNIDEN_smmu_spniden_START (0)
#define SOC_IVP_SMMU_SPNIDEN_smmu_spniden_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_sta0 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_START0_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_START0_cfg_addr_sta0_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_START0_cfg_addr_sta0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_end0 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_END0_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_END0_cfg_addr_end0_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_END0_cfg_addr_end0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_sta1 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_START1_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_START1_cfg_addr_sta1_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_START1_cfg_addr_sta1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_end1 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_END1_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_END1_cfg_addr_end1_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_END1_cfg_addr_end1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_sta2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_START2_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_START2_cfg_addr_sta2_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_START2_cfg_addr_sta2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_end2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_END2_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_END2_cfg_addr_end2_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_END2_cfg_addr_end2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_sta3 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_START3_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_START3_cfg_addr_sta3_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_START3_cfg_addr_sta3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_addr_end3 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_IVP_SYSCACHE_HINT_ADDR_END3_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_ADDR_END3_cfg_addr_end3_START (0)
#define SOC_IVP_SYSCACHE_HINT_ADDR_END3_cfg_addr_end3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sc_axhint0 : 4;
        unsigned int cfg_sc_axhint1 : 4;
        unsigned int cfg_sc_axhint2 : 4;
        unsigned int cfg_sc_axhint3 : 4;
        unsigned int cfg_sc_axhint_default : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_IVP_SYSCACHE_HINT_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint0_START (0)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint0_END (3)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint1_START (4)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint1_END (7)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint2_START (8)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint2_END (11)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint3_START (12)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint3_END (15)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint_default_START (16)
#define SOC_IVP_SYSCACHE_HINT_cfg_sc_axhint_default_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int syscache_addr_security_sel : 1;
        unsigned int syscache_axhit_security_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IVP_SYSCACHE_HINT_SECURITY_CFG_UNION;
#endif
#define SOC_IVP_SYSCACHE_HINT_SECURITY_CFG_syscache_addr_security_sel_START (0)
#define SOC_IVP_SYSCACHE_HINT_SECURITY_CFG_syscache_addr_security_sel_END (0)
#define SOC_IVP_SYSCACHE_HINT_SECURITY_CFG_syscache_axhit_security_sel_START (1)
#define SOC_IVP_SYSCACHE_HINT_SECURITY_CFG_syscache_axhit_security_sel_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
