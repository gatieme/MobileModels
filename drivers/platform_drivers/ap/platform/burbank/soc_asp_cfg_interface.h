#ifndef __SOC_ASP_CFG_INTERFACE_H__
#define __SOC_ASP_CFG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ASP_CFG_R_RST_CTRLEN_ADDR(base) ((base) + (0x0000UL))
#define SOC_ASP_CFG_R_RST_CTRLDIS_ADDR(base) ((base) + (0x0004UL))
#define SOC_ASP_CFG_R_RST_CTRLSTAT_ADDR(base) ((base) + (0x0008UL))
#define SOC_ASP_CFG_R_GATE_EN_ADDR(base) ((base) + (0x000CUL))
#define SOC_ASP_CFG_R_GATE_DIS_ADDR(base) ((base) + (0x0010UL))
#define SOC_ASP_CFG_R_GATE_CLKEN_ADDR(base) ((base) + (0x0014UL))
#define SOC_ASP_CFG_R_GATE_CLKSTAT_ADDR(base) ((base) + (0x0018UL))
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_ADDR(base) ((base) + (0x001CUL))
#define SOC_ASP_CFG_R_CLK1_DIV_ADDR(base) ((base) + (0x0020UL))
#define SOC_ASP_CFG_R_CLK_SEL_ADDR(base) ((base) + (0x0038UL))
#define SOC_ASP_CFG_R_DSP_NMI_ADDR(base) ((base) + (0x003CUL))
#define SOC_ASP_CFG_R_DSP_PRID_ADDR(base) ((base) + (0x0040UL))
#define SOC_ASP_CFG_R_DSP_RUNSTALL_ADDR(base) ((base) + (0x0044UL))
#define SOC_ASP_CFG_R_DSP_STATVECTORSEL_ADDR(base) ((base) + (0x0048UL))
#define SOC_ASP_CFG_R_DSP_OCDHALTONRESET_ADDR(base) ((base) + (0x004CUL))
#define SOC_ASP_CFG_R_DSP_STATUS_ADDR(base) ((base) + (0x0050UL))
#define SOC_ASP_CFG_R_BUS_PRIORITY_ADDR(base) ((base) + (0x0058UL))
#define SOC_ASP_CFG_R_CG_EN_ADDR(base) ((base) + (0x005CUL))
#define SOC_ASP_CFG_R_OCRAM_RET_ADDR(base) ((base) + (0x0060UL))
#define SOC_ASP_CFG_R_INTR_NS_INI_ADDR(base) ((base) + (0x0064UL))
#define SOC_ASP_CFG_R_INTR_NS_EN_ADDR(base) ((base) + (0x0068UL))
#define SOC_ASP_CFG_R_INTR_NS_MASK_ADDR(base) ((base) + (0x006CUL))
#define SOC_ASP_CFG_R_DLOCK_BP_ADDR(base) ((base) + (0x0078UL))
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ADDR(base) ((base) + (0x007CUL))
#define SOC_ASP_CFG_R_DSP_RAM_RET_ADDR(base) ((base) + (0x0084UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_ADDR(base) ((base) + (0x0090UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_ADDR(base) ((base) + (0x0094UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_ADDR(base) ((base) + (0x0098UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_ADDR(base) ((base) + (0x009CUL))
#define SOC_ASP_CFG_R_TZ_SECURE_N_ADDR(base) ((base) + (0x0100UL))
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ADDR(base) ((base) + (0x0104UL))
#define SOC_ASP_CFG_R_INTR_S_INI_ADDR(base) ((base) + (0x010CUL))
#define SOC_ASP_CFG_R_INTR_S_EN_ADDR(base) ((base) + (0x0110UL))
#define SOC_ASP_CFG_R_INTR_S_MASK_ADDR(base) ((base) + (0x0114UL))
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_ADDR(base) ((base) + (0x0118UL))
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_ADDR(base) ((base) + (0x011CUL))
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ADDR(base) ((base) + (0x0120UL))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ADDR(base) ((base) + (0x124UL))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x128UL))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x12CUL))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ADDR(base) ((base) + (0x130UL))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x134UL))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x138UL))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ADDR(base) ((base) + (0x13CUL))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x140UL))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x144UL))
#define SOC_ASP_CFG_R_MMBUF_CTRL_ADDR(base) ((base) + (0x0148UL))
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_ADDR(base) ((base) + (0x014CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_ADDR(base) ((base) + (0x0160UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_ADDR(base) ((base) + (0x0164UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_ADDR(base) ((base) + (0x0168UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_ADDR(base) ((base) + (0x016CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_ADDR(base) ((base) + (0x0170UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_ADDR(base) ((base) + (0x0174UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_ADDR(base) ((base) + (0x0178UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_ADDR(base) ((base) + (0x017CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_ADDR(base) ((base) + (0x0180UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_ADDR(base) ((base) + (0x0184UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_ADDR(base) ((base) + (0x0188UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_ADDR(base) ((base) + (0x018CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_ADDR(base) ((base) + (0x0190UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_ADDR(base) ((base) + (0x0194UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_ADDR(base) ((base) + (0x0198UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_ADDR(base) ((base) + (0x019CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_ADDR(base) ((base) + (0x01A0UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_ADDR(base) ((base) + (0x01A4UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_ADDR(base) ((base) + (0x01A8UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_ADDR(base) ((base) + (0x01ACUL))
#define SOC_ASP_CFG_R_MEMORY_CTRL_ADDR(base) ((base) + (0x01B0UL))
#define SOC_ASP_CFG_R_SLIMBUS_PRIMARY_ADDR_ADDR(base) ((base) + (0x01B4UL))
#define SOC_ASP_CFG_R_SLIMBUS_ID_ADDR_ADDR(base) ((base) + (0x01B8UL))
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_ADDR(base) ((base) + (0x01BCUL))
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_ADDR(base) ((base) + (0x01C0UL))
#define SOC_ASP_CFG_R_DSD_DIV_ADDR(base) ((base) + (0x01D4UL))
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_ADDR(base) ((base) + (0x01D8UL))
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_ADDR(base) ((base) + (0x01DCUL))
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_ADDR(base) ((base) + (0x0200UL))
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_ADDR(base) ((base) + (0x0204UL))
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_ADDR(base) ((base) + (0x0208UL))
#define SOC_ASP_CFG_R_HIFIDSP_FAULTST_ADDR(base) ((base) + (0x00A4UL))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ADDR(base) ((base) + (0x234UL))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x238UL))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x23CUL))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ADDR(base) ((base) + (0x240UL))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x244UL))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x248UL))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ADDR(base) ((base) + (0x24CUL))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x250UL))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x254UL))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ADDR(base) ((base) + (0x258UL))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x25CUL))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x260UL))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ADDR(base) ((base) + (0x264UL))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x268UL))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x26CUL))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x274UL))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x278UL))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ADDR(base) ((base) + (0x27CUL))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x280UL))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x284UL))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ADDR(base) ((base) + (0x288UL))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x28CUL))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x290UL))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ADDR(base) ((base) + (0x294UL))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x298UL))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x29CUL))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ADDR(base) ((base) + (0x2A0UL))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x2A4UL))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x2A8UL))
#define SOC_ASP_CFG_R_MEMORY_CTRL_SPC_ADDR_ADDR(base) ((base) + (0x02ACUL))
#else
#define SOC_ASP_CFG_R_RST_CTRLEN_ADDR(base) ((base) + (0x0000))
#define SOC_ASP_CFG_R_RST_CTRLDIS_ADDR(base) ((base) + (0x0004))
#define SOC_ASP_CFG_R_RST_CTRLSTAT_ADDR(base) ((base) + (0x0008))
#define SOC_ASP_CFG_R_GATE_EN_ADDR(base) ((base) + (0x000C))
#define SOC_ASP_CFG_R_GATE_DIS_ADDR(base) ((base) + (0x0010))
#define SOC_ASP_CFG_R_GATE_CLKEN_ADDR(base) ((base) + (0x0014))
#define SOC_ASP_CFG_R_GATE_CLKSTAT_ADDR(base) ((base) + (0x0018))
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_ADDR(base) ((base) + (0x001C))
#define SOC_ASP_CFG_R_CLK1_DIV_ADDR(base) ((base) + (0x0020))
#define SOC_ASP_CFG_R_CLK_SEL_ADDR(base) ((base) + (0x0038))
#define SOC_ASP_CFG_R_DSP_NMI_ADDR(base) ((base) + (0x003C))
#define SOC_ASP_CFG_R_DSP_PRID_ADDR(base) ((base) + (0x0040))
#define SOC_ASP_CFG_R_DSP_RUNSTALL_ADDR(base) ((base) + (0x0044))
#define SOC_ASP_CFG_R_DSP_STATVECTORSEL_ADDR(base) ((base) + (0x0048))
#define SOC_ASP_CFG_R_DSP_OCDHALTONRESET_ADDR(base) ((base) + (0x004C))
#define SOC_ASP_CFG_R_DSP_STATUS_ADDR(base) ((base) + (0x0050))
#define SOC_ASP_CFG_R_BUS_PRIORITY_ADDR(base) ((base) + (0x0058))
#define SOC_ASP_CFG_R_CG_EN_ADDR(base) ((base) + (0x005C))
#define SOC_ASP_CFG_R_OCRAM_RET_ADDR(base) ((base) + (0x0060))
#define SOC_ASP_CFG_R_INTR_NS_INI_ADDR(base) ((base) + (0x0064))
#define SOC_ASP_CFG_R_INTR_NS_EN_ADDR(base) ((base) + (0x0068))
#define SOC_ASP_CFG_R_INTR_NS_MASK_ADDR(base) ((base) + (0x006C))
#define SOC_ASP_CFG_R_DLOCK_BP_ADDR(base) ((base) + (0x0078))
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ADDR(base) ((base) + (0x007C))
#define SOC_ASP_CFG_R_DSP_RAM_RET_ADDR(base) ((base) + (0x0084))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_ADDR(base) ((base) + (0x0090))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_ADDR(base) ((base) + (0x0094))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_ADDR(base) ((base) + (0x0098))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_ADDR(base) ((base) + (0x009C))
#define SOC_ASP_CFG_R_TZ_SECURE_N_ADDR(base) ((base) + (0x0100))
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ADDR(base) ((base) + (0x0104))
#define SOC_ASP_CFG_R_INTR_S_INI_ADDR(base) ((base) + (0x010C))
#define SOC_ASP_CFG_R_INTR_S_EN_ADDR(base) ((base) + (0x0110))
#define SOC_ASP_CFG_R_INTR_S_MASK_ADDR(base) ((base) + (0x0114))
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_ADDR(base) ((base) + (0x0118))
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_ADDR(base) ((base) + (0x011C))
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ADDR(base) ((base) + (0x0120))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ADDR(base) ((base) + (0x124))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x128))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x12C))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ADDR(base) ((base) + (0x130))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x134))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x138))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ADDR(base) ((base) + (0x13C))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x140))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x144))
#define SOC_ASP_CFG_R_MMBUF_CTRL_ADDR(base) ((base) + (0x0148))
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_ADDR(base) ((base) + (0x014C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_ADDR(base) ((base) + (0x0160))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_ADDR(base) ((base) + (0x0164))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_ADDR(base) ((base) + (0x0168))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_ADDR(base) ((base) + (0x016C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_ADDR(base) ((base) + (0x0170))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_ADDR(base) ((base) + (0x0174))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_ADDR(base) ((base) + (0x0178))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_ADDR(base) ((base) + (0x017C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_ADDR(base) ((base) + (0x0180))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_ADDR(base) ((base) + (0x0184))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_ADDR(base) ((base) + (0x0188))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_ADDR(base) ((base) + (0x018C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_ADDR(base) ((base) + (0x0190))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_ADDR(base) ((base) + (0x0194))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_ADDR(base) ((base) + (0x0198))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_ADDR(base) ((base) + (0x019C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_ADDR(base) ((base) + (0x01A0))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_ADDR(base) ((base) + (0x01A4))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_ADDR(base) ((base) + (0x01A8))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_ADDR(base) ((base) + (0x01AC))
#define SOC_ASP_CFG_R_MEMORY_CTRL_ADDR(base) ((base) + (0x01B0))
#define SOC_ASP_CFG_R_SLIMBUS_PRIMARY_ADDR_ADDR(base) ((base) + (0x01B4))
#define SOC_ASP_CFG_R_SLIMBUS_ID_ADDR_ADDR(base) ((base) + (0x01B8))
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_ADDR(base) ((base) + (0x01BC))
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_ADDR(base) ((base) + (0x01C0))
#define SOC_ASP_CFG_R_DSD_DIV_ADDR(base) ((base) + (0x01D4))
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_ADDR(base) ((base) + (0x01D8))
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_ADDR(base) ((base) + (0x01DC))
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_ADDR(base) ((base) + (0x0200))
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_ADDR(base) ((base) + (0x0204))
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_ADDR(base) ((base) + (0x0208))
#define SOC_ASP_CFG_R_HIFIDSP_FAULTST_ADDR(base) ((base) + (0x00A4))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ADDR(base) ((base) + (0x234))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x238))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x23C))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ADDR(base) ((base) + (0x240))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x244))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x248))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ADDR(base) ((base) + (0x24C))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x250))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x254))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ADDR(base) ((base) + (0x258))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x25C))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x260))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ADDR(base) ((base) + (0x264))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x268))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x26C))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x274))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x278))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ADDR(base) ((base) + (0x27C))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x280))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x284))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ADDR(base) ((base) + (0x288))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x28C))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x290))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ADDR(base) ((base) + (0x294))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x298))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x29C))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ADDR(base) ((base) + (0x2A0))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x2A4))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x2A8))
#define SOC_ASP_CFG_R_MEMORY_CTRL_SPC_ADDR_ADDR(base) ((base) + (0x02AC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_codec_n : 1;
        unsigned int rst_dsd_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int preset_dsd_n : 1;
        unsigned int rst_dsp_n : 1;
        unsigned int rst_dsp_debug_n : 1;
        unsigned int rst_ipc_n : 1;
        unsigned int reserved_1 : 1;
        unsigned int rst_dmac_n : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int rst_ocram_n : 1;
        unsigned int rst_watchdog_n : 1;
        unsigned int rst_slimbus_base_n : 1;
        unsigned int rst_slimbus_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int rst_gpio_n : 1;
        unsigned int rst_timer0_n : 1;
        unsigned int rst_timer1_n : 1;
        unsigned int reserved_5 : 1;
        unsigned int dsp_jtag_srst_req_n : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 10;
    } reg;
} SOC_ASP_CFG_R_RST_CTRLEN_UNION;
#endif
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_codec_n_START (0)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_codec_n_END (0)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dsd_n_START (1)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dsd_n_END (1)
#define SOC_ASP_CFG_R_RST_CTRLEN_preset_dsd_n_START (3)
#define SOC_ASP_CFG_R_RST_CTRLEN_preset_dsd_n_END (3)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dsp_n_START (4)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dsp_n_END (4)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dsp_debug_n_START (5)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dsp_debug_n_END (5)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_ipc_n_START (6)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_ipc_n_END (6)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dmac_n_START (8)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_dmac_n_END (8)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_ocram_n_START (11)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_ocram_n_END (11)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_watchdog_n_START (12)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_watchdog_n_END (12)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_slimbus_base_n_START (13)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_slimbus_base_n_END (13)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_slimbus_n_START (14)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_slimbus_n_END (14)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_gpio_n_START (16)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_gpio_n_END (16)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_timer0_n_START (17)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_timer0_n_END (17)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_timer1_n_START (18)
#define SOC_ASP_CFG_R_RST_CTRLEN_rst_timer1_n_END (18)
#define SOC_ASP_CFG_R_RST_CTRLEN_dsp_jtag_srst_req_n_START (20)
#define SOC_ASP_CFG_R_RST_CTRLEN_dsp_jtag_srst_req_n_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_codec_n : 1;
        unsigned int rst_dsd_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int preset_dsd_n : 1;
        unsigned int rst_dsp_n : 1;
        unsigned int rst_dsp_debug_n : 1;
        unsigned int rst_ipc_n : 1;
        unsigned int reserved_1 : 1;
        unsigned int rst_dmac_n : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int rst_ocram_n : 1;
        unsigned int rst_watchdog_n : 1;
        unsigned int rst_slimbus_base_n : 1;
        unsigned int rst_slimbus_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int rst_gpio_n : 1;
        unsigned int rst_timer0_n : 1;
        unsigned int rst_timer1_n : 1;
        unsigned int reserved_5 : 1;
        unsigned int dsp_jtag_srst_req_n : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 10;
    } reg;
} SOC_ASP_CFG_R_RST_CTRLDIS_UNION;
#endif
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_codec_n_START (0)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_codec_n_END (0)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dsd_n_START (1)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dsd_n_END (1)
#define SOC_ASP_CFG_R_RST_CTRLDIS_preset_dsd_n_START (3)
#define SOC_ASP_CFG_R_RST_CTRLDIS_preset_dsd_n_END (3)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dsp_n_START (4)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dsp_n_END (4)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dsp_debug_n_START (5)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dsp_debug_n_END (5)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_ipc_n_START (6)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_ipc_n_END (6)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dmac_n_START (8)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_dmac_n_END (8)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_ocram_n_START (11)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_ocram_n_END (11)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_watchdog_n_START (12)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_watchdog_n_END (12)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_slimbus_base_n_START (13)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_slimbus_base_n_END (13)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_slimbus_n_START (14)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_slimbus_n_END (14)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_gpio_n_START (16)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_gpio_n_END (16)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_timer0_n_START (17)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_timer0_n_END (17)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_timer1_n_START (18)
#define SOC_ASP_CFG_R_RST_CTRLDIS_rst_timer1_n_END (18)
#define SOC_ASP_CFG_R_RST_CTRLDIS_dsp_jtag_srst_req_n_START (20)
#define SOC_ASP_CFG_R_RST_CTRLDIS_dsp_jtag_srst_req_n_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_codec_n : 1;
        unsigned int rst_dsd_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int preset_dsd_n : 1;
        unsigned int rst_dsp_n : 1;
        unsigned int rst_dsp_debug_n : 1;
        unsigned int rst_ipc_n : 1;
        unsigned int reserved_1 : 1;
        unsigned int rst_dmac_n : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int rst_ocram_n : 1;
        unsigned int rst_watchdog_n : 1;
        unsigned int rst_slimbus_base_n : 1;
        unsigned int rst_slimbus_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int rst_gpio_n : 1;
        unsigned int rst_timer0_n : 1;
        unsigned int rst_timer1_n : 1;
        unsigned int reserved_5 : 1;
        unsigned int dsp_jtag_srst_req_n : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 10;
    } reg;
} SOC_ASP_CFG_R_RST_CTRLSTAT_UNION;
#endif
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_codec_n_START (0)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_codec_n_END (0)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsd_n_START (1)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsd_n_END (1)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_preset_dsd_n_START (3)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_preset_dsd_n_END (3)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_n_START (4)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_n_END (4)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_debug_n_START (5)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_debug_n_END (5)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ipc_n_START (6)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ipc_n_END (6)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dmac_n_START (8)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dmac_n_END (8)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ocram_n_START (11)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ocram_n_END (11)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_watchdog_n_START (12)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_watchdog_n_END (12)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_slimbus_base_n_START (13)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_slimbus_base_n_END (13)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_slimbus_n_START (14)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_slimbus_n_END (14)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_gpio_n_START (16)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_gpio_n_END (16)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer0_n_START (17)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer0_n_END (17)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer1_n_START (18)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer1_n_END (18)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_dsp_jtag_srst_req_n_START (20)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_dsp_jtag_srst_req_n_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hifidspclk : 1;
        unsigned int gt_codec_clk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_dsd_clk : 1;
        unsigned int gt_dsd_sysclk : 1;
        unsigned int gt_ipchclk : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_dmachclk : 1;
        unsigned int gt_clk_aspdsd_out : 1;
        unsigned int gt_asp_dmmu_clk : 1;
        unsigned int gt_ocramhclk : 1;
        unsigned int gt_wdhclk : 1;
        unsigned int gt_slimbushclk : 1;
        unsigned int gt_slimbus_base_clk : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_gpiohclk : 1;
        unsigned int gt_timer0hclk : 1;
        unsigned int gt_timer1hclk : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 7;
    } reg;
} SOC_ASP_CFG_R_GATE_EN_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_EN_gt_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_EN_gt_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_EN_gt_codec_clk_START (1)
#define SOC_ASP_CFG_R_GATE_EN_gt_codec_clk_END (1)
#define SOC_ASP_CFG_R_GATE_EN_gt_dsd_clk_START (7)
#define SOC_ASP_CFG_R_GATE_EN_gt_dsd_clk_END (7)
#define SOC_ASP_CFG_R_GATE_EN_gt_dsd_sysclk_START (8)
#define SOC_ASP_CFG_R_GATE_EN_gt_dsd_sysclk_END (8)
#define SOC_ASP_CFG_R_GATE_EN_gt_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_EN_gt_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_EN_gt_dmachclk_START (11)
#define SOC_ASP_CFG_R_GATE_EN_gt_dmachclk_END (11)
#define SOC_ASP_CFG_R_GATE_EN_gt_clk_aspdsd_out_START (12)
#define SOC_ASP_CFG_R_GATE_EN_gt_clk_aspdsd_out_END (12)
#define SOC_ASP_CFG_R_GATE_EN_gt_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_EN_gt_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_EN_gt_ocramhclk_START (14)
#define SOC_ASP_CFG_R_GATE_EN_gt_ocramhclk_END (14)
#define SOC_ASP_CFG_R_GATE_EN_gt_wdhclk_START (15)
#define SOC_ASP_CFG_R_GATE_EN_gt_wdhclk_END (15)
#define SOC_ASP_CFG_R_GATE_EN_gt_slimbushclk_START (16)
#define SOC_ASP_CFG_R_GATE_EN_gt_slimbushclk_END (16)
#define SOC_ASP_CFG_R_GATE_EN_gt_slimbus_base_clk_START (17)
#define SOC_ASP_CFG_R_GATE_EN_gt_slimbus_base_clk_END (17)
#define SOC_ASP_CFG_R_GATE_EN_gt_gpiohclk_START (21)
#define SOC_ASP_CFG_R_GATE_EN_gt_gpiohclk_END (21)
#define SOC_ASP_CFG_R_GATE_EN_gt_timer0hclk_START (22)
#define SOC_ASP_CFG_R_GATE_EN_gt_timer0hclk_END (22)
#define SOC_ASP_CFG_R_GATE_EN_gt_timer1hclk_START (23)
#define SOC_ASP_CFG_R_GATE_EN_gt_timer1hclk_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hifidspclk : 1;
        unsigned int gt_codec_clk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_dsd_clk : 1;
        unsigned int gt_dsd_sysclk : 1;
        unsigned int gt_ipchclk : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_dmachclk : 1;
        unsigned int gt_clk_aspdsd_out : 1;
        unsigned int gt_asp_dmmu_clk : 1;
        unsigned int gt_ocramhclk : 1;
        unsigned int gt_wdhclk : 1;
        unsigned int gt_slimbushclk : 1;
        unsigned int gt_slimbus_base_clk : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_gpiohclk : 1;
        unsigned int gt_timer0hclk : 1;
        unsigned int gt_timer1hclk : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 7;
    } reg;
} SOC_ASP_CFG_R_GATE_DIS_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_DIS_gt_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_DIS_gt_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_DIS_gt_codec_clk_START (1)
#define SOC_ASP_CFG_R_GATE_DIS_gt_codec_clk_END (1)
#define SOC_ASP_CFG_R_GATE_DIS_gt_dsd_clk_START (7)
#define SOC_ASP_CFG_R_GATE_DIS_gt_dsd_clk_END (7)
#define SOC_ASP_CFG_R_GATE_DIS_gt_dsd_sysclk_START (8)
#define SOC_ASP_CFG_R_GATE_DIS_gt_dsd_sysclk_END (8)
#define SOC_ASP_CFG_R_GATE_DIS_gt_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_DIS_gt_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_DIS_gt_dmachclk_START (11)
#define SOC_ASP_CFG_R_GATE_DIS_gt_dmachclk_END (11)
#define SOC_ASP_CFG_R_GATE_DIS_gt_clk_aspdsd_out_START (12)
#define SOC_ASP_CFG_R_GATE_DIS_gt_clk_aspdsd_out_END (12)
#define SOC_ASP_CFG_R_GATE_DIS_gt_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_DIS_gt_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_DIS_gt_ocramhclk_START (14)
#define SOC_ASP_CFG_R_GATE_DIS_gt_ocramhclk_END (14)
#define SOC_ASP_CFG_R_GATE_DIS_gt_wdhclk_START (15)
#define SOC_ASP_CFG_R_GATE_DIS_gt_wdhclk_END (15)
#define SOC_ASP_CFG_R_GATE_DIS_gt_slimbushclk_START (16)
#define SOC_ASP_CFG_R_GATE_DIS_gt_slimbushclk_END (16)
#define SOC_ASP_CFG_R_GATE_DIS_gt_slimbus_base_clk_START (17)
#define SOC_ASP_CFG_R_GATE_DIS_gt_slimbus_base_clk_END (17)
#define SOC_ASP_CFG_R_GATE_DIS_gt_gpiohclk_START (21)
#define SOC_ASP_CFG_R_GATE_DIS_gt_gpiohclk_END (21)
#define SOC_ASP_CFG_R_GATE_DIS_gt_timer0hclk_START (22)
#define SOC_ASP_CFG_R_GATE_DIS_gt_timer0hclk_END (22)
#define SOC_ASP_CFG_R_GATE_DIS_gt_timer1hclk_START (23)
#define SOC_ASP_CFG_R_GATE_DIS_gt_timer1hclk_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hifidspclk : 1;
        unsigned int gt_codec_clk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_dsd_clk : 1;
        unsigned int gt_dsd_sysclk : 1;
        unsigned int gt_ipchclk : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_dmachclk : 1;
        unsigned int gt_clk_aspdsd_out : 1;
        unsigned int gt_asp_dmmu_clk : 1;
        unsigned int gt_ocramhclk : 1;
        unsigned int gt_wdhclk : 1;
        unsigned int gt_slimbushclk : 1;
        unsigned int gt_slimbus_base_clk : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_gpiohclk : 1;
        unsigned int gt_timer0hclk : 1;
        unsigned int gt_timer1hclk : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 7;
    } reg;
} SOC_ASP_CFG_R_GATE_CLKEN_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_codec_clk_START (1)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_codec_clk_END (1)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dsd_clk_START (7)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dsd_clk_END (7)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dsd_sysclk_START (8)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dsd_sysclk_END (8)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dmachclk_START (11)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dmachclk_END (11)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_clk_aspdsd_out_START (12)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_clk_aspdsd_out_END (12)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ocramhclk_START (14)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ocramhclk_END (14)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_wdhclk_START (15)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_wdhclk_END (15)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_slimbushclk_START (16)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_slimbushclk_END (16)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_slimbus_base_clk_START (17)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_slimbus_base_clk_END (17)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_gpiohclk_START (21)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_gpiohclk_END (21)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer0hclk_START (22)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer0hclk_END (22)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer1hclk_START (23)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer1hclk_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_hifidspclk : 1;
        unsigned int st_codec_clk : 1;
        unsigned int st_pclk_codec : 1;
        unsigned int st_clk_asp_dsd_out : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_dsd_clk : 1;
        unsigned int st_dsd_sysclk : 1;
        unsigned int st_ipchclk : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_dmachclk0 : 1;
        unsigned int st_dmachclk1 : 1;
        unsigned int st_asp_dmmu_clk : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_ocramhclk : 1;
        unsigned int st_wdhclk : 1;
        unsigned int st_slimbushclk : 1;
        unsigned int st_slimbus_base_clk : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int st_gpiohclk : 1;
        unsigned int st_timer0hclk : 1;
        unsigned int st_timer1hclk : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_ASP_CFG_R_GATE_CLKSTAT_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_codec_clk_START (1)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_codec_clk_END (1)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_pclk_codec_START (2)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_pclk_codec_END (2)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_clk_asp_dsd_out_START (3)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_clk_asp_dsd_out_END (3)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dsd_clk_START (7)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dsd_clk_END (7)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dsd_sysclk_START (8)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dsd_sysclk_END (8)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk0_START (11)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk0_END (11)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk1_START (12)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk1_END (12)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ocramhclk_START (15)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ocramhclk_END (15)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_wdhclk_START (16)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_wdhclk_END (16)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_slimbushclk_START (17)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_slimbushclk_END (17)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_slimbus_base_clk_START (18)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_slimbus_base_clk_END (18)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_gpiohclk_START (27)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_gpiohclk_END (27)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer0hclk_START (28)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer0hclk_END (28)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer1hclk_START (29)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer1hclk_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_siobclk_div : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_dsd_clk_div : 1;
        unsigned int gt_asp_tcxo_div : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 23;
    } reg;
} SOC_ASP_CFG_R_GATE_CLKDIV_EN_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_siobclk_div_START (2)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_siobclk_div_END (2)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_dsd_clk_div_START (6)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_dsd_clk_div_END (6)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_asp_tcxo_div_START (7)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_asp_tcxo_div_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_siobclk : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ASP_CFG_R_CLK1_DIV_UNION;
#endif
#define SOC_ASP_CFG_R_CLK1_DIV_div_siobclk_START (0)
#define SOC_ASP_CFG_R_CLK1_DIV_div_siobclk_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int dsd_slave_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int slimbus_base_clk_sel : 1;
        unsigned int watchdog_clken_sel : 1;
        unsigned int timer0_1_clken_sel : 1;
        unsigned int timer0_2_clken_sel : 1;
        unsigned int timer1_1_clken_sel : 1;
        unsigned int timer1_2_clken_sel : 1;
        unsigned int reserved_5 : 1;
        unsigned int dsd_clk_inv_en : 1;
        unsigned int hifidsp_clk_sel : 1;
        unsigned int reserved_6 : 1;
        unsigned int write_en : 16;
    } reg;
} SOC_ASP_CFG_R_CLK_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_CLK_SEL_dsd_slave_en_START (1)
#define SOC_ASP_CFG_R_CLK_SEL_dsd_slave_en_END (1)
#define SOC_ASP_CFG_R_CLK_SEL_slimbus_base_clk_sel_START (6)
#define SOC_ASP_CFG_R_CLK_SEL_slimbus_base_clk_sel_END (6)
#define SOC_ASP_CFG_R_CLK_SEL_watchdog_clken_sel_START (7)
#define SOC_ASP_CFG_R_CLK_SEL_watchdog_clken_sel_END (7)
#define SOC_ASP_CFG_R_CLK_SEL_timer0_1_clken_sel_START (8)
#define SOC_ASP_CFG_R_CLK_SEL_timer0_1_clken_sel_END (8)
#define SOC_ASP_CFG_R_CLK_SEL_timer0_2_clken_sel_START (9)
#define SOC_ASP_CFG_R_CLK_SEL_timer0_2_clken_sel_END (9)
#define SOC_ASP_CFG_R_CLK_SEL_timer1_1_clken_sel_START (10)
#define SOC_ASP_CFG_R_CLK_SEL_timer1_1_clken_sel_END (10)
#define SOC_ASP_CFG_R_CLK_SEL_timer1_2_clken_sel_START (11)
#define SOC_ASP_CFG_R_CLK_SEL_timer1_2_clken_sel_END (11)
#define SOC_ASP_CFG_R_CLK_SEL_dsd_clk_inv_en_START (13)
#define SOC_ASP_CFG_R_CLK_SEL_dsd_clk_inv_en_END (13)
#define SOC_ASP_CFG_R_CLK_SEL_hifidsp_clk_sel_START (14)
#define SOC_ASP_CFG_R_CLK_SEL_hifidsp_clk_sel_END (14)
#define SOC_ASP_CFG_R_CLK_SEL_write_en_START (16)
#define SOC_ASP_CFG_R_CLK_SEL_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_dsp_nmi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CFG_R_DSP_NMI_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_NMI_r_dsp_nmi_START (0)
#define SOC_ASP_CFG_R_DSP_NMI_r_dsp_nmi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_prid : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CFG_R_DSP_PRID_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_PRID_dsp_prid_START (0)
#define SOC_ASP_CFG_R_DSP_PRID_dsp_prid_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_runstall : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_R_DSP_RUNSTALL_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_RUNSTALL_dsp_runstall_START (0)
#define SOC_ASP_CFG_R_DSP_RUNSTALL_dsp_runstall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_statvectorsel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_R_DSP_STATVECTORSEL_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_STATVECTORSEL_dsp_statvectorsel_START (0)
#define SOC_ASP_CFG_R_DSP_STATVECTORSEL_dsp_statvectorsel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_ocdhaltonreset : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_R_DSP_OCDHALTONRESET_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_OCDHALTONRESET_dsp_ocdhaltonreset_START (0)
#define SOC_ASP_CFG_R_DSP_OCDHALTONRESET_dsp_ocdhaltonreset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_xocdmode : 1;
        unsigned int dsp_pwaitmode : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ASP_CFG_R_DSP_STATUS_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_STATUS_dsp_xocdmode_START (0)
#define SOC_ASP_CFG_R_DSP_STATUS_dsp_xocdmode_END (0)
#define SOC_ASP_CFG_R_DSP_STATUS_dsp_pwaitmode_START (1)
#define SOC_ASP_CFG_R_DSP_STATUS_dsp_pwaitmode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dsp_ar_qos : 2;
        unsigned int dsp_aw_qos : 2;
        unsigned int dma_ar_qos : 2;
        unsigned int dma_aw_qos : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int asp_slv_priority : 2;
        unsigned int dsp_mst_priority : 2;
        unsigned int dmac_priority : 2;
        unsigned int reserved_2 : 2;
        unsigned int asp_mst_priority : 3;
        unsigned int dsp_slv_priority : 3;
        unsigned int ocram_priority : 3;
        unsigned int x2h_priority : 3;
    } reg;
} SOC_ASP_CFG_R_BUS_PRIORITY_UNION;
#endif
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_ar_qos_START (0)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_ar_qos_END (1)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_aw_qos_START (2)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_aw_qos_END (3)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dma_ar_qos_START (4)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dma_ar_qos_END (5)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dma_aw_qos_START (6)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dma_aw_qos_END (7)
#define SOC_ASP_CFG_R_BUS_PRIORITY_asp_slv_priority_START (12)
#define SOC_ASP_CFG_R_BUS_PRIORITY_asp_slv_priority_END (13)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_mst_priority_START (14)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_mst_priority_END (15)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dmac_priority_START (16)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dmac_priority_END (17)
#define SOC_ASP_CFG_R_BUS_PRIORITY_asp_mst_priority_START (20)
#define SOC_ASP_CFG_R_BUS_PRIORITY_asp_mst_priority_END (22)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_slv_priority_START (23)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_slv_priority_END (25)
#define SOC_ASP_CFG_R_BUS_PRIORITY_ocram_priority_START (26)
#define SOC_ASP_CFG_R_BUS_PRIORITY_ocram_priority_END (28)
#define SOC_ASP_CFG_R_BUS_PRIORITY_x2h_priority_START (29)
#define SOC_ASP_CFG_R_BUS_PRIORITY_x2h_priority_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_axi_m1_cg_en : 1;
        unsigned int dw_axi_m2_cg_en : 1;
        unsigned int dw_axi_m3_cg_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int dw_axi_s1_cg_en : 1;
        unsigned int dw_axi_s2_cg_en : 1;
        unsigned int dw_axi_s3_cg_en : 1;
        unsigned int dw_axi_s4_cg_en : 1;
        unsigned int dw_axi_s0_cg_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int dmac_hclk0_cg_en : 1;
        unsigned int dmac_hclk1_cg_en : 1;
        unsigned int reserved_2 : 3;
        unsigned int lat_mon_bp : 1;
        unsigned int write_en : 16;
    } reg;
} SOC_ASP_CFG_R_CG_EN_UNION;
#endif
#define SOC_ASP_CFG_R_CG_EN_dw_axi_m1_cg_en_START (0)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_m1_cg_en_END (0)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_m2_cg_en_START (1)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_m2_cg_en_END (1)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_m3_cg_en_START (2)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_m3_cg_en_END (2)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s1_cg_en_START (4)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s1_cg_en_END (4)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s2_cg_en_START (5)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s2_cg_en_END (5)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s3_cg_en_START (6)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s3_cg_en_END (6)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s4_cg_en_START (7)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s4_cg_en_END (7)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s0_cg_en_START (8)
#define SOC_ASP_CFG_R_CG_EN_dw_axi_s0_cg_en_END (8)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk0_cg_en_START (10)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk0_cg_en_END (10)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk1_cg_en_START (11)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk1_cg_en_END (11)
#define SOC_ASP_CFG_R_CG_EN_lat_mon_bp_START (15)
#define SOC_ASP_CFG_R_CG_EN_lat_mon_bp_END (15)
#define SOC_ASP_CFG_R_CG_EN_write_en_START (16)
#define SOC_ASP_CFG_R_CG_EN_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slp : 4;
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 8;
        unsigned int write_en : 16;
    } reg;
} SOC_ASP_CFG_R_OCRAM_RET_UNION;
#endif
#define SOC_ASP_CFG_R_OCRAM_RET_slp_START (0)
#define SOC_ASP_CFG_R_OCRAM_RET_slp_END (3)
#define SOC_ASP_CFG_R_OCRAM_RET_write_en_START (16)
#define SOC_ASP_CFG_R_OCRAM_RET_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int i2c_hifi_intr : 1;
        unsigned int mcpu_hifi_intr : 1;
        unsigned int bbe16_hifi_intr : 1;
        unsigned int slimbus_intr_arm : 1;
        unsigned int ldrx2hifi_time_int_ns : 1;
        unsigned int l2drx2hifi_time_int_ns : 1;
        unsigned int intr_usb3_mmc_ns : 1;
        unsigned int intr_ipc_npu_ns : 3;
        unsigned int slimbus_intr_hifi : 1;
        unsigned int reserved_0 : 1;
        unsigned int dma_intr_ns : 1;
        unsigned int intr1_nonsecure_ipc : 1;
        unsigned int intr0_nonsecure_ipc : 1;
        unsigned int intr_dsp_nmi : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CFG_R_INTR_NS_INI_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_NS_INI_i2c_hifi_intr_START (0)
#define SOC_ASP_CFG_R_INTR_NS_INI_i2c_hifi_intr_END (0)
#define SOC_ASP_CFG_R_INTR_NS_INI_mcpu_hifi_intr_START (1)
#define SOC_ASP_CFG_R_INTR_NS_INI_mcpu_hifi_intr_END (1)
#define SOC_ASP_CFG_R_INTR_NS_INI_bbe16_hifi_intr_START (2)
#define SOC_ASP_CFG_R_INTR_NS_INI_bbe16_hifi_intr_END (2)
#define SOC_ASP_CFG_R_INTR_NS_INI_slimbus_intr_arm_START (3)
#define SOC_ASP_CFG_R_INTR_NS_INI_slimbus_intr_arm_END (3)
#define SOC_ASP_CFG_R_INTR_NS_INI_ldrx2hifi_time_int_ns_START (4)
#define SOC_ASP_CFG_R_INTR_NS_INI_ldrx2hifi_time_int_ns_END (4)
#define SOC_ASP_CFG_R_INTR_NS_INI_l2drx2hifi_time_int_ns_START (5)
#define SOC_ASP_CFG_R_INTR_NS_INI_l2drx2hifi_time_int_ns_END (5)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_usb3_mmc_ns_START (6)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_usb3_mmc_ns_END (6)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_ipc_npu_ns_START (7)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_ipc_npu_ns_END (9)
#define SOC_ASP_CFG_R_INTR_NS_INI_slimbus_intr_hifi_START (10)
#define SOC_ASP_CFG_R_INTR_NS_INI_slimbus_intr_hifi_END (10)
#define SOC_ASP_CFG_R_INTR_NS_INI_dma_intr_ns_START (12)
#define SOC_ASP_CFG_R_INTR_NS_INI_dma_intr_ns_END (12)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_nonsecure_ipc_START (13)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_nonsecure_ipc_END (13)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_nonsecure_ipc_START (14)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_nonsecure_ipc_END (14)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_dsp_nmi_START (15)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_dsp_nmi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int i2c_hifi_intr : 1;
        unsigned int mcpu_hifi_intr : 1;
        unsigned int bbe16_hifi_intr : 1;
        unsigned int slimbus_intr_arm : 1;
        unsigned int ldrx2hifi_time_int_ns : 1;
        unsigned int l2drx2hifi_time_int_ns : 1;
        unsigned int intr_usb3_mmc_ns : 1;
        unsigned int intr_ipc_npu_ns : 3;
        unsigned int slimbus_intr_hifi : 1;
        unsigned int reserved_0 : 1;
        unsigned int dma_intr_ns : 1;
        unsigned int intr1_nonsecure_ipc : 1;
        unsigned int intr0_nonsecure_ipc : 1;
        unsigned int intr_dsp_nmi : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CFG_R_INTR_NS_EN_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_NS_EN_i2c_hifi_intr_START (0)
#define SOC_ASP_CFG_R_INTR_NS_EN_i2c_hifi_intr_END (0)
#define SOC_ASP_CFG_R_INTR_NS_EN_mcpu_hifi_intr_START (1)
#define SOC_ASP_CFG_R_INTR_NS_EN_mcpu_hifi_intr_END (1)
#define SOC_ASP_CFG_R_INTR_NS_EN_bbe16_hifi_intr_START (2)
#define SOC_ASP_CFG_R_INTR_NS_EN_bbe16_hifi_intr_END (2)
#define SOC_ASP_CFG_R_INTR_NS_EN_slimbus_intr_arm_START (3)
#define SOC_ASP_CFG_R_INTR_NS_EN_slimbus_intr_arm_END (3)
#define SOC_ASP_CFG_R_INTR_NS_EN_ldrx2hifi_time_int_ns_START (4)
#define SOC_ASP_CFG_R_INTR_NS_EN_ldrx2hifi_time_int_ns_END (4)
#define SOC_ASP_CFG_R_INTR_NS_EN_l2drx2hifi_time_int_ns_START (5)
#define SOC_ASP_CFG_R_INTR_NS_EN_l2drx2hifi_time_int_ns_END (5)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_usb3_mmc_ns_START (6)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_usb3_mmc_ns_END (6)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_ipc_npu_ns_START (7)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_ipc_npu_ns_END (9)
#define SOC_ASP_CFG_R_INTR_NS_EN_slimbus_intr_hifi_START (10)
#define SOC_ASP_CFG_R_INTR_NS_EN_slimbus_intr_hifi_END (10)
#define SOC_ASP_CFG_R_INTR_NS_EN_dma_intr_ns_START (12)
#define SOC_ASP_CFG_R_INTR_NS_EN_dma_intr_ns_END (12)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_nonsecure_ipc_START (13)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_nonsecure_ipc_END (13)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_nonsecure_ipc_START (14)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_nonsecure_ipc_END (14)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_dsp_nmi_START (15)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_dsp_nmi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int i2c_hifi_intr : 1;
        unsigned int mcpu_hifi_intr : 1;
        unsigned int bbe16_hifi_intr : 1;
        unsigned int slimbus_intr_arm : 1;
        unsigned int ldrx2hifi_time_int_ns : 1;
        unsigned int l2drx2hifi_time_int_ns : 1;
        unsigned int intr_usb3_mmc_ns : 1;
        unsigned int intr_ipc_npu_ns : 3;
        unsigned int slimbus_intr_hifi : 1;
        unsigned int reserved_0 : 1;
        unsigned int dma_intr_ns : 1;
        unsigned int intr1_nonsecure_ipc : 1;
        unsigned int intr0_nonsecure_ipc : 1;
        unsigned int intr_dsp_nmi : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CFG_R_INTR_NS_MASK_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_NS_MASK_i2c_hifi_intr_START (0)
#define SOC_ASP_CFG_R_INTR_NS_MASK_i2c_hifi_intr_END (0)
#define SOC_ASP_CFG_R_INTR_NS_MASK_mcpu_hifi_intr_START (1)
#define SOC_ASP_CFG_R_INTR_NS_MASK_mcpu_hifi_intr_END (1)
#define SOC_ASP_CFG_R_INTR_NS_MASK_bbe16_hifi_intr_START (2)
#define SOC_ASP_CFG_R_INTR_NS_MASK_bbe16_hifi_intr_END (2)
#define SOC_ASP_CFG_R_INTR_NS_MASK_slimbus_intr_arm_START (3)
#define SOC_ASP_CFG_R_INTR_NS_MASK_slimbus_intr_arm_END (3)
#define SOC_ASP_CFG_R_INTR_NS_MASK_ldrx2hifi_time_int_ns_START (4)
#define SOC_ASP_CFG_R_INTR_NS_MASK_ldrx2hifi_time_int_ns_END (4)
#define SOC_ASP_CFG_R_INTR_NS_MASK_l2drx2hifi_time_int_ns_START (5)
#define SOC_ASP_CFG_R_INTR_NS_MASK_l2drx2hifi_time_int_ns_END (5)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_usb3_mmc_ns_START (6)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_usb3_mmc_ns_END (6)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_ipc_npu_ns_START (7)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_ipc_npu_ns_END (9)
#define SOC_ASP_CFG_R_INTR_NS_MASK_slimbus_intr_hifi_START (10)
#define SOC_ASP_CFG_R_INTR_NS_MASK_slimbus_intr_hifi_END (10)
#define SOC_ASP_CFG_R_INTR_NS_MASK_dma_intr_ns_START (12)
#define SOC_ASP_CFG_R_INTR_NS_MASK_dma_intr_ns_END (12)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr1_nonsecure_ipc_START (13)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr1_nonsecure_ipc_END (13)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr0_nonsecure_ipc_START (14)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr0_nonsecure_ipc_END (14)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_dsp_nmi_START (15)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_dsp_nmi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dlock_bp_dmmu : 1;
        unsigned int dlock_bp_codec : 1;
        unsigned int dlock_bp_h2p : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int dlock_bp_dsd : 1;
        unsigned int dlock_bp_slimbus : 1;
        unsigned int dlock_bp_edmac : 1;
        unsigned int dlock_bp_ipc : 1;
        unsigned int dlock_bp_watchdog : 1;
        unsigned int dlock_bp_cfg : 1;
        unsigned int dlock_bp_gpio : 1;
        unsigned int dlock_bp_timer0 : 1;
        unsigned int dlock_bp_timer1 : 1;
        unsigned int write_en : 16;
    } reg;
} SOC_ASP_CFG_R_DLOCK_BP_UNION;
#endif
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_dmmu_START (0)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_dmmu_END (0)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_codec_START (1)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_codec_END (1)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_h2p_START (2)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_h2p_END (2)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_dsd_START (7)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_dsd_END (7)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_slimbus_START (8)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_slimbus_END (8)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_edmac_START (9)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_edmac_END (9)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_ipc_START (10)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_ipc_END (10)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_watchdog_START (11)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_watchdog_END (11)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_cfg_START (12)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_cfg_END (12)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_gpio_START (13)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_gpio_END (13)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer0_START (14)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer0_END (14)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer1_START (15)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer1_END (15)
#define SOC_ASP_CFG_R_DLOCK_BP_write_en_START (16)
#define SOC_ASP_CFG_R_DLOCK_BP_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_dsp_nmi : 1;
        unsigned int intr0_nonsecure_ipc : 1;
        unsigned int intr1_nonsecure_ipc : 1;
        unsigned int intr0_secure_ipc : 1;
        unsigned int intr1_secure_ipc : 1;
        unsigned int intr_asp_timer0_0 : 1;
        unsigned int intr_asp_timer0_1 : 1;
        unsigned int intr_asp_timer1_0 : 1;
        unsigned int intr_asp_timer1_1 : 1;
        unsigned int general_see2hifi_intr : 1;
        unsigned int intr_dsd_mask : 1;
        unsigned int intr_crypto_enhance2hifi : 1;
        unsigned int intr_usb3_mmc_ns : 1;
        unsigned int intr_mad_wakeup : 1;
        unsigned int dma_intr : 1;
        unsigned int dma_intr_ns : 1;
        unsigned int ldrx2hifi_time_int : 1;
        unsigned int intr_addr_monitor : 1;
        unsigned int intr_watch_dog : 1;
        unsigned int ipc_int : 1;
        unsigned int slimbus_intr : 1;
        unsigned int mcpu_hifi_intr : 1;
        unsigned int bbe16_hifi_intr : 1;
        unsigned int i2c_hifi_intr : 1;
        unsigned int intr_gpio_hifi : 1;
        unsigned int tds_hifi_intr : 1;
        unsigned int intr_npu2asp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ASP_CFG_R_DSP_BINTERRUPT_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_dsp_nmi_START (0)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_dsp_nmi_END (0)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr0_nonsecure_ipc_START (1)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr0_nonsecure_ipc_END (1)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr1_nonsecure_ipc_START (2)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr1_nonsecure_ipc_END (2)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr0_secure_ipc_START (3)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr0_secure_ipc_END (3)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr1_secure_ipc_START (4)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr1_secure_ipc_END (4)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer0_0_START (5)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer0_0_END (5)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer0_1_START (6)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer0_1_END (6)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer1_0_START (7)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer1_0_END (7)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer1_1_START (8)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_asp_timer1_1_END (8)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_general_see2hifi_intr_START (9)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_general_see2hifi_intr_END (9)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_dsd_mask_START (10)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_dsd_mask_END (10)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_crypto_enhance2hifi_START (11)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_crypto_enhance2hifi_END (11)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_usb3_mmc_ns_START (12)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_usb3_mmc_ns_END (12)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_mad_wakeup_START (13)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_mad_wakeup_END (13)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_dma_intr_START (14)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_dma_intr_END (14)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_dma_intr_ns_START (15)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_dma_intr_ns_END (15)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ldrx2hifi_time_int_START (16)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ldrx2hifi_time_int_END (16)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_addr_monitor_START (17)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_addr_monitor_END (17)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_watch_dog_START (18)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_watch_dog_END (18)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ipc_int_START (19)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ipc_int_END (19)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_slimbus_intr_START (20)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_slimbus_intr_END (20)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_mcpu_hifi_intr_START (21)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_mcpu_hifi_intr_END (21)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_bbe16_hifi_intr_START (22)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_bbe16_hifi_intr_END (22)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_i2c_hifi_intr_START (23)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_i2c_hifi_intr_END (23)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_gpio_hifi_START (24)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_gpio_hifi_END (24)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_tds_hifi_intr_START (25)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_tds_hifi_intr_END (25)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_npu2asp_START (26)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_intr_npu2asp_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dram0_pgt_ctrl : 3;
        unsigned int dram1_pgt_ctrl : 3;
        unsigned int iram0_pgt_ctrl : 3;
        unsigned int iram1_pgt_ctrl : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int write_en : 16;
    } reg;
} SOC_ASP_CFG_R_DSP_RAM_RET_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_RAM_RET_dram0_pgt_ctrl_START (0)
#define SOC_ASP_CFG_R_DSP_RAM_RET_dram0_pgt_ctrl_END (2)
#define SOC_ASP_CFG_R_DSP_RAM_RET_dram1_pgt_ctrl_START (3)
#define SOC_ASP_CFG_R_DSP_RAM_RET_dram1_pgt_ctrl_END (5)
#define SOC_ASP_CFG_R_DSP_RAM_RET_iram0_pgt_ctrl_START (6)
#define SOC_ASP_CFG_R_DSP_RAM_RET_iram0_pgt_ctrl_END (8)
#define SOC_ASP_CFG_R_DSP_RAM_RET_iram1_pgt_ctrl_START (9)
#define SOC_ASP_CFG_R_DSP_RAM_RET_iram1_pgt_ctrl_END (11)
#define SOC_ASP_CFG_R_DSP_RAM_RET_write_en_START (16)
#define SOC_ASP_CFG_R_DSP_RAM_RET_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifidsp_flag0 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG0_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_hifidsp_flag0_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_hifidsp_flag0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifidsp_flag1 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG1_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_hifidsp_flag1_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_hifidsp_flag1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifidsp_flag2 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG2_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_hifidsp_flag2_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_hifidsp_flag2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifidsp_flag3 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG3_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_hifidsp_flag3_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_hifidsp_flag3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_secure_dmmu_n : 1;
        unsigned int tz_secure_codec_n : 1;
        unsigned int tz_secure_slimbus_data_n : 1;
        unsigned int tz_secure_dsd_data_n : 1;
        unsigned int tz_secure_codec_data_n : 1;
        unsigned int tz_secure_asp_cfg_n : 1;
        unsigned int tz_secure_dsd_n : 1;
        unsigned int tz_secure_slimbus_n : 1;
        unsigned int tz_secure_edamc_n : 1;
        unsigned int tz_secure_ipc_n : 1;
        unsigned int tz_secure_watchdog_n : 1;
        unsigned int tz_secure_dsp_n : 1;
        unsigned int tz_secure_gpio_n : 1;
        unsigned int tz_secure_timer0_n : 1;
        unsigned int tz_secure_timer1_n : 1;
        unsigned int dsp_mst_secure_n : 1;
        unsigned int write_en : 16;
    } reg;
} SOC_ASP_CFG_R_TZ_SECURE_N_UNION;
#endif
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dmmu_n_START (0)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dmmu_n_END (0)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_codec_n_START (1)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_codec_n_END (1)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_slimbus_data_n_START (2)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_slimbus_data_n_END (2)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dsd_data_n_START (3)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dsd_data_n_END (3)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_codec_data_n_START (4)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_codec_data_n_END (4)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asp_cfg_n_START (5)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asp_cfg_n_END (5)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dsd_n_START (6)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dsd_n_END (6)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_slimbus_n_START (7)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_slimbus_n_END (7)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_edamc_n_START (8)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_edamc_n_END (8)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_ipc_n_START (9)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_ipc_n_END (9)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_watchdog_n_START (10)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_watchdog_n_END (10)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dsp_n_START (11)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dsp_n_END (11)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_gpio_n_START (12)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_gpio_n_END (12)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer0_n_START (13)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer0_n_END (13)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer1_n_START (14)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer1_n_END (14)
#define SOC_ASP_CFG_R_TZ_SECURE_N_dsp_mst_secure_n_START (15)
#define SOC_ASP_CFG_R_TZ_SECURE_N_dsp_mst_secure_n_END (15)
#define SOC_ASP_CFG_R_TZ_SECURE_N_write_en_START (16)
#define SOC_ASP_CFG_R_TZ_SECURE_N_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocram_r0size : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ASP_CFG_R_OCRAM_R0SIZE_UNION;
#endif
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ocram_r0size_START (0)
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ocram_r0size_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crypto_enhance2hifi_fast_intr : 1;
        unsigned int intr0_modem_ipc2hifi_s : 1;
        unsigned int intr1_modem_ipc2hifi_s : 1;
        unsigned int intr_general_see_hifi_fast0 : 1;
        unsigned int crypto_enhance2hifi_comm_intr : 1;
        unsigned int intr_general_see_hifi_comm : 1;
        unsigned int intr_ao_ipc_comm : 1;
        unsigned int intr_ao_ipc_fast : 1;
        unsigned int intr_ipc_npu_s : 3;
        unsigned int intr_mad_wakeup : 1;
        unsigned int addr_mon_intr : 1;
        unsigned int intr_tds_hifi : 1;
        unsigned int intr_dma_s : 1;
        unsigned int intr_ipc : 1;
        unsigned int intr_dsd : 1;
        unsigned int intr_watch_dog : 1;
        unsigned int intr_asp_timer1_1 : 1;
        unsigned int intr_asp_timer1_0 : 1;
        unsigned int intr_asp_timer0_1 : 1;
        unsigned int intr_asp_timer0_0 : 1;
        unsigned int intr_gpio_hifi : 1;
        unsigned int intr1_secure_ipc : 1;
        unsigned int intr0_secure_ipc : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_CFG_R_INTR_S_INI_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_S_INI_crypto_enhance2hifi_fast_intr_START (0)
#define SOC_ASP_CFG_R_INTR_S_INI_crypto_enhance2hifi_fast_intr_END (0)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_modem_ipc2hifi_s_START (1)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_modem_ipc2hifi_s_END (1)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_modem_ipc2hifi_s_START (2)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_modem_ipc2hifi_s_END (2)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_general_see_hifi_fast0_START (3)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_general_see_hifi_fast0_END (3)
#define SOC_ASP_CFG_R_INTR_S_INI_crypto_enhance2hifi_comm_intr_START (4)
#define SOC_ASP_CFG_R_INTR_S_INI_crypto_enhance2hifi_comm_intr_END (4)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_general_see_hifi_comm_START (5)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_general_see_hifi_comm_END (5)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_comm_START (6)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_comm_END (6)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_fast_START (7)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_fast_END (7)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ipc_npu_s_START (8)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ipc_npu_s_END (10)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_mad_wakeup_START (11)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_mad_wakeup_END (11)
#define SOC_ASP_CFG_R_INTR_S_INI_addr_mon_intr_START (12)
#define SOC_ASP_CFG_R_INTR_S_INI_addr_mon_intr_END (12)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_tds_hifi_START (13)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_tds_hifi_END (13)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_dma_s_START (14)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_dma_s_END (14)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ipc_START (15)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ipc_END (15)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_dsd_START (16)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_dsd_END (16)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_watch_dog_START (17)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_watch_dog_END (17)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_1_START (18)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_1_END (18)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_0_START (19)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_0_END (19)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_1_START (20)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_1_END (20)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_0_START (21)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_0_END (21)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_gpio_hifi_START (22)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_gpio_hifi_END (22)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_secure_ipc_START (23)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_secure_ipc_END (23)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_secure_ipc_START (24)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_secure_ipc_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crypto_enhance2hifi_fast_intr : 1;
        unsigned int intr0_modem_ipc2hifi_s : 1;
        unsigned int intr1_modem_ipc2hifi_s : 1;
        unsigned int intr_general_see_hifi_fast0 : 1;
        unsigned int crypto_enhance2hifi_comm_intr : 1;
        unsigned int intr_general_see_hifi_comm : 1;
        unsigned int intr_ao_ipc_comm : 1;
        unsigned int intr_ao_ipc_fast : 1;
        unsigned int intr_ipc_npu_s : 3;
        unsigned int intr_mad_wakeup : 1;
        unsigned int addr_mon_intr : 1;
        unsigned int intr_tds_hifi : 1;
        unsigned int intr_dma_s : 1;
        unsigned int intr_ipc : 1;
        unsigned int intr_dsd : 1;
        unsigned int intr_watch_dog : 1;
        unsigned int intr_asp_timer1_1 : 1;
        unsigned int intr_asp_timer1_0 : 1;
        unsigned int intr_asp_timer0_1 : 1;
        unsigned int intr_asp_timer0_0 : 1;
        unsigned int intr_gpio_hifi : 1;
        unsigned int intr1_secure_ipc : 1;
        unsigned int intr0_secure_ipc : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_CFG_R_INTR_S_EN_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_S_EN_crypto_enhance2hifi_fast_intr_START (0)
#define SOC_ASP_CFG_R_INTR_S_EN_crypto_enhance2hifi_fast_intr_END (0)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_modem_ipc2hifi_s_START (1)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_modem_ipc2hifi_s_END (1)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_modem_ipc2hifi_s_START (2)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_modem_ipc2hifi_s_END (2)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_general_see_hifi_fast0_START (3)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_general_see_hifi_fast0_END (3)
#define SOC_ASP_CFG_R_INTR_S_EN_crypto_enhance2hifi_comm_intr_START (4)
#define SOC_ASP_CFG_R_INTR_S_EN_crypto_enhance2hifi_comm_intr_END (4)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_general_see_hifi_comm_START (5)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_general_see_hifi_comm_END (5)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_comm_START (6)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_comm_END (6)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_fast_START (7)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_fast_END (7)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ipc_npu_s_START (8)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ipc_npu_s_END (10)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_mad_wakeup_START (11)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_mad_wakeup_END (11)
#define SOC_ASP_CFG_R_INTR_S_EN_addr_mon_intr_START (12)
#define SOC_ASP_CFG_R_INTR_S_EN_addr_mon_intr_END (12)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_tds_hifi_START (13)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_tds_hifi_END (13)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_dma_s_START (14)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_dma_s_END (14)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ipc_START (15)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ipc_END (15)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_dsd_START (16)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_dsd_END (16)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_watch_dog_START (17)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_watch_dog_END (17)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_1_START (18)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_1_END (18)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_0_START (19)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_0_END (19)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_1_START (20)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_1_END (20)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_0_START (21)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_0_END (21)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_gpio_hifi_START (22)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_gpio_hifi_END (22)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_secure_ipc_START (23)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_secure_ipc_END (23)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_secure_ipc_START (24)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_secure_ipc_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crypto_enhance2hifi_fast_intr : 1;
        unsigned int intr0_modem_ipc2hifi_s : 1;
        unsigned int intr1_modem_ipc2hifi_s : 1;
        unsigned int intr_general_see_hifi_fast0 : 1;
        unsigned int crypto_enhance2hifi_comm_intr : 1;
        unsigned int intr_general_see_hifi_comm : 1;
        unsigned int intr_ao_ipc_comm : 1;
        unsigned int intr_ao_ipc_fast : 1;
        unsigned int intr_ipc_npu_s : 3;
        unsigned int intr_mad_wakeup : 1;
        unsigned int addr_mon_intr : 1;
        unsigned int intr_tds_hifi : 1;
        unsigned int intr_dma_s : 1;
        unsigned int intr_ipc : 1;
        unsigned int intr_dsd_mask : 1;
        unsigned int intr_watch_dog : 1;
        unsigned int intr_asp_timer1_1 : 1;
        unsigned int intr_asp_timer1_0 : 1;
        unsigned int intr_asp_timer0_1 : 1;
        unsigned int intr_asp_timer0_0 : 1;
        unsigned int intr_gpio_hifi : 1;
        unsigned int intr1_secure_ipc : 1;
        unsigned int intr0_secure_ipc : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_ASP_CFG_R_INTR_S_MASK_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_S_MASK_crypto_enhance2hifi_fast_intr_START (0)
#define SOC_ASP_CFG_R_INTR_S_MASK_crypto_enhance2hifi_fast_intr_END (0)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_modem_ipc2hifi_s_START (1)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_modem_ipc2hifi_s_END (1)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_modem_ipc2hifi_s_START (2)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_modem_ipc2hifi_s_END (2)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_general_see_hifi_fast0_START (3)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_general_see_hifi_fast0_END (3)
#define SOC_ASP_CFG_R_INTR_S_MASK_crypto_enhance2hifi_comm_intr_START (4)
#define SOC_ASP_CFG_R_INTR_S_MASK_crypto_enhance2hifi_comm_intr_END (4)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_general_see_hifi_comm_START (5)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_general_see_hifi_comm_END (5)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_comm_START (6)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_comm_END (6)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_fast_START (7)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_fast_END (7)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ipc_npu_s_START (8)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ipc_npu_s_END (10)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_mad_wakeup_START (11)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_mad_wakeup_END (11)
#define SOC_ASP_CFG_R_INTR_S_MASK_addr_mon_intr_START (12)
#define SOC_ASP_CFG_R_INTR_S_MASK_addr_mon_intr_END (12)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_tds_hifi_START (13)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_tds_hifi_END (13)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_dma_s_START (14)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_dma_s_END (14)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ipc_START (15)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ipc_END (15)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_dsd_mask_START (16)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_dsd_mask_END (16)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_watch_dog_START (17)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_watch_dog_END (17)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_1_START (18)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_1_END (18)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_0_START (19)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_0_END (19)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_1_START (20)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_1_END (20)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_0_START (21)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_0_END (21)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_gpio_hifi_START (22)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_gpio_hifi_END (22)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_secure_ipc_START (23)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_secure_ipc_END (23)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_secure_ipc_START (24)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_secure_ipc_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 8;
        unsigned int dsp_addr_remapping_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_CFG_R_DSP_REMAPPING_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_remap_length_END (7)
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_dsp_addr_remapping_en_START (8)
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_dsp_addr_remapping_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 20;
        unsigned int asp_reserved_start_addr : 12;
    } reg;
} SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_asp_reserved_start_addr_START (20)
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_asp_reserved_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 20;
        unsigned int ddr_start_addr : 12;
    } reg;
} SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ddr_start_addr_START (20)
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ddr_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ppll0_en : 1;
        unsigned int fll_en : 1;
        unsigned int mmbuf_clk_en : 1;
        unsigned int aobus_clk_en : 1;
        unsigned int asp_pwr_req_hifi : 2;
        unsigned int aobus_clk_sel : 2;
        unsigned int audio_fll_ctrl : 2;
        unsigned int reserved : 3;
        unsigned int asp_sclk_sw2fll_req : 1;
        unsigned int asp_sclk_sw2fll_ack : 1;
        unsigned int asp_sclk_sw2fll_lock : 1;
        unsigned int write_en : 16;
    } reg;
} SOC_ASP_CFG_R_MMBUF_CTRL_UNION;
#endif
#define SOC_ASP_CFG_R_MMBUF_CTRL_ppll0_en_START (0)
#define SOC_ASP_CFG_R_MMBUF_CTRL_ppll0_en_END (0)
#define SOC_ASP_CFG_R_MMBUF_CTRL_fll_en_START (1)
#define SOC_ASP_CFG_R_MMBUF_CTRL_fll_en_END (1)
#define SOC_ASP_CFG_R_MMBUF_CTRL_mmbuf_clk_en_START (2)
#define SOC_ASP_CFG_R_MMBUF_CTRL_mmbuf_clk_en_END (2)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_en_START (3)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_en_END (3)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_pwr_req_hifi_START (4)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_pwr_req_hifi_END (5)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_sel_START (6)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_sel_END (7)
#define SOC_ASP_CFG_R_MMBUF_CTRL_audio_fll_ctrl_START (8)
#define SOC_ASP_CFG_R_MMBUF_CTRL_audio_fll_ctrl_END (9)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_req_START (13)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_req_END (13)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_ack_START (14)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_ack_END (14)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_lock_START (15)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_lock_END (15)
#define SOC_ASP_CFG_R_MMBUF_CTRL_write_en_START (16)
#define SOC_ASP_CFG_R_MMBUF_CTRL_write_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifidsp_idle_time_cfgcnt : 8;
        unsigned int div_hifidsp_clk_auto : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dsp_pwaitmode_bypass : 1;
        unsigned int dw_axi_m1_st_bypass : 1;
        unsigned int dw_axi_m2_st_bypass : 1;
        unsigned int dw_axi_m3_st_bypass : 1;
        unsigned int reserved_3 : 1;
        unsigned int dmmu_clkup_req_bypass : 1;
        unsigned int reserved_4 : 12;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_hifidsp_idle_time_cfgcnt_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_hifidsp_idle_time_cfgcnt_END (7)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_div_hifidsp_clk_auto_START (8)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_div_hifidsp_clk_auto_END (10)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dsp_pwaitmode_bypass_START (14)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dsp_pwaitmode_bypass_END (14)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dw_axi_m1_st_bypass_START (15)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dw_axi_m1_st_bypass_END (15)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dw_axi_m2_st_bypass_START (16)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dw_axi_m2_st_bypass_END (16)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dw_axi_m3_st_bypass_START (17)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dw_axi_m3_st_bypass_END (17)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dmmu_clkup_req_bypass_START (19)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dmmu_clkup_req_bypass_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor0_en : 1;
        unsigned int addr_monitor1_en : 1;
        unsigned int addr_monitor2_en : 1;
        unsigned int addr_monitor3_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor0_en_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor0_en_END (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor1_en_START (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor1_en_END (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor2_en_START (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor2_en_END (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor3_en_START (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_addr_monitor3_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor_intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_addr_monitor_intr_clr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_addr_monitor_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor0_intr_en : 1;
        unsigned int addr_monitor1_intr_en : 1;
        unsigned int addr_monitor2_intr_en : 1;
        unsigned int addr_monitor3_intr_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor0_intr_en_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor0_intr_en_END (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor1_intr_en_START (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor1_intr_en_END (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor2_intr_en_START (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor2_intr_en_END (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor3_intr_en_START (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_addr_monitor3_intr_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor0_arhit_intr_stat : 1;
        unsigned int addr_monitor0_awhit_intr_stat : 1;
        unsigned int addr_monitor1_arhit_intr_stat : 1;
        unsigned int addr_monitor1_awhit_intr_stat : 1;
        unsigned int addr_monitor2_arhit_intr_stat : 1;
        unsigned int addr_monitor2_awhit_intr_stat : 1;
        unsigned int addr_monitor3_arhit_intr_stat : 1;
        unsigned int addr_monitor3_awhit_intr_stat : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor0_arhit_intr_stat_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor0_arhit_intr_stat_END (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor0_awhit_intr_stat_START (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor0_awhit_intr_stat_END (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor1_arhit_intr_stat_START (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor1_arhit_intr_stat_END (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor1_awhit_intr_stat_START (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor1_awhit_intr_stat_END (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor2_arhit_intr_stat_START (4)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor2_arhit_intr_stat_END (4)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor2_awhit_intr_stat_START (5)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor2_awhit_intr_stat_END (5)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor3_arhit_intr_stat_START (6)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor3_arhit_intr_stat_END (6)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor3_awhit_intr_stat_START (7)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_addr_monitor3_awhit_intr_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor0_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_addr_monitor0_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_addr_monitor0_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor0_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_addr_monitor0_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_addr_monitor0_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor0_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_addr_monitor0_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_addr_monitor0_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor0_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_addr_monitor0_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_addr_monitor0_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor1_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_addr_monitor1_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_addr_monitor1_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor1_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_addr_monitor1_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_addr_monitor1_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor1_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_addr_monitor1_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_addr_monitor1_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor1_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_addr_monitor1_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_addr_monitor1_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor2_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_addr_monitor2_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_addr_monitor2_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor2_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_addr_monitor2_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_addr_monitor2_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor2_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_addr_monitor2_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_addr_monitor2_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor2_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_addr_monitor2_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_addr_monitor2_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor3_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_addr_monitor3_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_addr_monitor3_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int addr_monitor3_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_addr_monitor3_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_addr_monitor3_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor3_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_addr_monitor3_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_addr_monitor3_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_monitor3_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_addr_monitor3_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_addr_monitor3_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_ASP_CFG_R_MEMORY_CTRL_UNION;
#endif
#define SOC_ASP_CFG_R_MEMORY_CTRL_mem_ctrl_s_START (0)
#define SOC_ASP_CFG_R_MEMORY_CTRL_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slimbus_primary : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_R_SLIMBUS_PRIMARY_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_SLIMBUS_PRIMARY_ADDR_slimbus_primary_START (0)
#define SOC_ASP_CFG_R_SLIMBUS_PRIMARY_ADDR_slimbus_primary_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int slimbus_id : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CFG_R_SLIMBUS_ID_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_SLIMBUS_ID_ADDR_slimbus_id_START (0)
#define SOC_ASP_CFG_R_SLIMBUS_ID_ADDR_slimbus_id_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dat_fmt_cfg_0 : 2;
        unsigned int dat_fmt_cfg_1 : 2;
        unsigned int dat_fmt_cfg_2 : 2;
        unsigned int dat_fmt_cfg_3 : 2;
        unsigned int dat_fmt_cfg_4 : 2;
        unsigned int dat_fmt_cfg_5 : 2;
        unsigned int dat_fmt_cfg_6 : 2;
        unsigned int dat_fmt_cfg_7 : 2;
        unsigned int dma_mask_clr : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_UNION;
#endif
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_0_START (0)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_0_END (1)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_1_START (2)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_1_END (3)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_2_START (4)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_2_END (5)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_3_START (6)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_3_END (7)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_4_START (8)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_4_END (9)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_5_START (10)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_5_END (11)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_6_START (12)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_6_END (13)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_7_START (14)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dat_fmt_cfg_7_END (15)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dma_mask_clr_START (16)
#define SOC_ASP_CFG_R_SLIM_DAT_FMT_CFG_dma_mask_clr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int reserved : 7;
        unsigned int chl_rght_fst : 8;
        unsigned int dat_rght_msb : 8;
        unsigned int dat_rght_fst : 8;
    } reg;
} SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_UNION;
#endif
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_bypass_START (0)
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_bypass_END (0)
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_chl_rght_fst_START (8)
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_chl_rght_fst_END (15)
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_dat_rght_msb_START (16)
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_dat_rght_msb_END (23)
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_dat_rght_fst_START (24)
#define SOC_ASP_CFG_R_SLIM_DAT_CHNL_CFG_dat_rght_fst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_dsd_clk : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ASP_CFG_R_DSD_DIV_UNION;
#endif
#define SOC_ASP_CFG_R_DSD_DIV_div_dsd_clk_START (0)
#define SOC_ASP_CFG_R_DSD_DIV_div_dsd_clk_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int sc_asp_mid0 : 6;
        unsigned int sc_asp_mid1 : 6;
        unsigned int reserved_1 : 2;
        unsigned int audio_dma_sel : 1;
        unsigned int voice_dma_sel : 1;
        unsigned int ultr_dma_sel : 1;
        unsigned int mic_dma_sel : 1;
        unsigned int spa_dma_sel : 1;
        unsigned int reserved_2 : 9;
        unsigned int intr_vad_wakeup : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CFG_R_CODEC_DMA_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_sc_asp_mid0_START (2)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_sc_asp_mid0_END (7)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_sc_asp_mid1_START (8)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_sc_asp_mid1_END (13)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_audio_dma_sel_START (16)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_audio_dma_sel_END (16)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_voice_dma_sel_START (17)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_voice_dma_sel_END (17)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_ultr_dma_sel_START (18)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_ultr_dma_sel_END (18)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_mic_dma_sel_START (19)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_mic_dma_sel_END (19)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_spa_dma_sel_START (20)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_spa_dma_sel_END (20)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_intr_vad_wakeup_START (30)
#define SOC_ASP_CFG_R_CODEC_DMA_SEL_intr_vad_wakeup_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acc_addr_moni_bypass_addr : 32;
    } reg;
} SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_acc_addr_moni_bypass_addr_START (0)
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_acc_addr_moni_bypass_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure_en_ddr_remap : 1;
        unsigned int secure_en_ddr_harq_remap : 1;
        unsigned int secure_en_ddr_mmbuf_remap : 1;
        unsigned int secure_en_ddr_ocram_remap : 1;
        unsigned int secure_en_ddr_cache0_remap : 1;
        unsigned int secure_en_ddr_cache1_remap : 1;
        unsigned int secure_en_ddr_cache2_remap : 1;
        unsigned int secure_en_ddr_cache3_remap : 1;
        unsigned int secure_en_ddr_cache4_remap : 1;
        unsigned int secure_en_sc_mid : 1;
        unsigned int secure_en_hifi_s2_remap : 1;
        unsigned int secure_en_ddr_cache5_remap : 1;
        unsigned int secure_en_ddr_cache6_remap : 1;
        unsigned int secure_en_ddr_cache7_remap : 1;
        unsigned int secure_en_ddr_cache8_remap : 1;
        unsigned int tz_secure_clkrst_n : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_UNION;
#endif
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_remap_START (0)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_remap_END (0)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_harq_remap_START (1)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_harq_remap_END (1)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_mmbuf_remap_START (2)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_mmbuf_remap_END (2)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_ocram_remap_START (3)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_ocram_remap_END (3)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache0_remap_START (4)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache0_remap_END (4)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache1_remap_START (5)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache1_remap_END (5)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache2_remap_START (6)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache2_remap_END (6)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache3_remap_START (7)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache3_remap_END (7)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache4_remap_START (8)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache4_remap_END (8)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_sc_mid_START (9)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_sc_mid_END (9)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_hifi_s2_remap_START (10)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_hifi_s2_remap_END (10)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache5_remap_START (11)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache5_remap_END (11)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache6_remap_START (12)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache6_remap_END (12)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache7_remap_START (13)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache7_remap_END (13)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache8_remap_START (14)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache8_remap_END (14)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_tz_secure_clkrst_n_START (15)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_tz_secure_clkrst_n_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_mem_ctrl_d1w2r_START (0)
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int double_exception : 16;
        unsigned int user_def : 4;
        unsigned int multiple_fault : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_double_exception_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_double_exception_END (15)
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_user_def_START (16)
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_user_def_END (19)
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_multiple_fault_START (20)
#define SOC_ASP_CFG_R_HIFIDSP_FAULTINFO_multiple_fault_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pfatalerror : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FAULTST_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FAULTST_pfatalerror_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FAULTST_pfatalerror_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int reserved : 2;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_remap_length_START (0)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_remap_length_END (8)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_remap_en_START (9)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_remap_en_END (9)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_length : 9;
        unsigned int remap_en : 1;
        unsigned int remap_awcache : 4;
        unsigned int remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_length_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_length_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 12;
        unsigned int des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_spc : 32;
    } reg;
} SOC_ASP_CFG_R_MEMORY_CTRL_SPC_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_MEMORY_CTRL_SPC_ADDR_mem_ctrl_spc_START (0)
#define SOC_ASP_CFG_R_MEMORY_CTRL_SPC_ADDR_mem_ctrl_spc_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
