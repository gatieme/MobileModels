#ifndef __SOC_LPM3_CFG_INTERFACE_H__
#define __SOC_LPM3_CFG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_LPM3_CFG_ACCESS_WIN_ADDR(base) ((base) + (0x000UL))
#define SOC_LPM3_CFG_HALT_BYPASS_ADDR(base) ((base) + (0x004UL))
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_ADDR(base) ((base) + (0x008UL))
#define SOC_LPM3_CFG_DLOCK_BYPASS_ADDR(base) ((base) + (0x00CUL))
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_ADDR(base) ((base) + (0x010UL))
#define SOC_LPM3_CFG_TESTPIN_EN_ADDR(base) ((base) + (0x014UL))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_ADDR(base) ((base) + (0x018UL))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_ADDR(base) ((base) + (0x01CUL))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL0_ADDR(base) ((base) + (0x020UL))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT0_ADDR(base) ((base) + (0x024UL))
#define SOC_LPM3_CFG_NMI_SOFT_ADDR(base) ((base) + (0x028UL))
#define SOC_LPM3_CFG_LPMCU_NMI_EN_ADDR(base) ((base) + (0x02CUL))
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_ADDR(base) ((base) + (0x030UL))
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_ADDR(base) ((base) + (0x034UL))
#define SOC_LPM3_CFG_LPMCU_ISP_INT_CTRL_ADDR(base) ((base) + (0x060UL))
#define SOC_LPM3_CFG_LPMCU_ISP_INT_STAT_ADDR(base) ((base) + (0x064UL))
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_ADDR(base) ((base) + (0x068UL))
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_ADDR(base) ((base) + (0x06CUL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_ADDR(base) ((base) + (0x070UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_ADDR(base) ((base) + (0x074UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_ADDR(base) ((base) + (0x078UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_ADDR(base) ((base) + (0x07CUL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_ADDR(base) ((base) + (0x080UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_ADDR(base) ((base) + (0x084UL))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_ADDR(base) ((base) + (0x088UL))
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_ADDR(base) ((base) + (0x08CUL))
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_ADDR(base) ((base) + (0x090UL))
#define SOC_LPM3_CFG_LPMCU_DBG_INFO1_ADDR(base) ((base) + (0x094UL))
#define SOC_LPM3_CFG_LPMCU_PIEACK0_31_ADDR(base) ((base) + (0x600UL))
#define SOC_LPM3_CFG_LPMCU_PIEINT0_31_ADDR(base) ((base) + (0x624UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_ADDR(base) ((base) + (0x660UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_ADDR(base) ((base) + (0x664UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_ADDR(base) ((base) + (0x668UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_ADDR(base) ((base) + (0x66CUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_ADDR(base) ((base) + (0x670UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_ADDR(base) ((base) + (0x674UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_ADDR(base) ((base) + (0x678UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_ADDR(base) ((base) + (0x67CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_ADDR(base) ((base) + (0x680UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_ADDR(base) ((base) + (0x684UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_ADDR(base) ((base) + (0x688UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_ADDR(base) ((base) + (0x68CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_ADDR(base) ((base) + (0x690UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_ADDR(base) ((base) + (0x694UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_ADDR(base) ((base) + (0x698UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_ADDR(base) ((base) + (0x69CUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_ADDR(base) ((base) + (0x6A0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_ADDR(base) ((base) + (0x6A4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_ADDR(base) ((base) + (0x6A8UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_ADDR(base) ((base) + (0x6ACUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_ADDR(base) ((base) + (0x6B0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_ADDR(base) ((base) + (0x6B4UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_ADDR(base) ((base) + (0x6B8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_ADDR(base) ((base) + (0x6BCUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_ADDR(base) ((base) + (0x6C0UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_ADDR(base) ((base) + (0x6C4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_ADDR(base) ((base) + (0x6C8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_ADDR(base) ((base) + (0x6CCUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_ADDR(base) ((base) + (0x6D0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_ADDR(base) ((base) + (0x6D4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_ADDR(base) ((base) + (0x6D8UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_ADDR(base) ((base) + (0x6DCUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_ADDR(base) ((base) + (0x6E0UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_ADDR(base) ((base) + (0x6E4UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_ADDR(base) ((base) + (0x6E8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_ADDR(base) ((base) + (0x6ECUL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_ADDR(base) ((base) + (0x6F0UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_ADDR(base) ((base) + (0x6F4UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_ADDR(base) ((base) + (0x6F8UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_ADDR(base) ((base) + (0x6FCUL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_ADDR(base) ((base) + (0x700UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_ADDR(base) ((base) + (0x704UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_ADDR(base) ((base) + (0x708UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_ADDR(base) ((base) + (0x70CUL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_ADDR(base) ((base) + (0x710UL))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_ADDR(base) ((base) + (0x714UL))
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_ADDR(base) ((base) + (0x718UL))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_ADDR(base) ((base) + (0x71CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_ADDR(base) ((base) + (0x800UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_ADDR(base) ((base) + (0x804UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_ADDR(base) ((base) + (0x808UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_ADDR(base) ((base) + (0x80CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_ADDR(base) ((base) + (0x810UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_ADDR(base) ((base) + (0x814UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_ADDR(base) ((base) + (0x818UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_ADDR(base) ((base) + (0x81CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_ADDR(base) ((base) + (0x820UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_ADDR(base) ((base) + (0x824UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_ADDR(base) ((base) + (0x828UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_ADDR(base) ((base) + (0x82CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_ADDR(base) ((base) + (0x830UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_ADDR(base) ((base) + (0x834UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_ADDR(base) ((base) + (0x838UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_ADDR(base) ((base) + (0x83CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_ADDR(base) ((base) + (0x840UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_ADDR(base) ((base) + (0x844UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_ADDR(base) ((base) + (0x848UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_ADDR(base) ((base) + (0x84CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_ADDR(base) ((base) + (0x850UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_ADDR(base) ((base) + (0x854UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_ADDR(base) ((base) + (0x858UL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_ADDR(base) ((base) + (0x85CUL))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_ADDR(base) ((base) + (0x860UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_ADDR(base) ((base) + (0x900UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_ADDR(base) ((base) + (0x904UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_ADDR(base) ((base) + (0x908UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_ADDR(base) ((base) + (0x90CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_ADDR(base) ((base) + (0x910UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_ADDR(base) ((base) + (0x914UL))
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_ADDR(base) ((base) + (0x918UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_ADDR(base) ((base) + (0x91CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_ADDR(base) ((base) + (0x920UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_ADDR(base) ((base) + (0x924UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_ADDR(base) ((base) + (0x928UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_ADDR(base) ((base) + (0x92CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_ADDR(base) ((base) + (0x930UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_ADDR(base) ((base) + (0x934UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_ADDR(base) ((base) + (0x938UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_ADDR(base) ((base) + (0x93CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_ADDR(base) ((base) + (0x940UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_ADDR(base) ((base) + (0x944UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_ADDR(base) ((base) + (0x948UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_ADDR(base) ((base) + (0x94CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_ADDR(base) ((base) + (0x950UL))
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_ADDR(base) ((base) + (0x954UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_ADDR(base) ((base) + (0x958UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_ADDR(base) ((base) + (0x95CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_ADDR(base) ((base) + (0x960UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_ADDR(base) ((base) + (0x964UL))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_ADDR(base) ((base) + (0x968UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_ADDR(base) ((base) + (0x96CUL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_ADDR(base) ((base) + (0x970UL))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_ADDR(base) ((base) + (0x974UL))
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_ADDR(base) ((base) + (0x978UL))
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_ADDR(base) ((base) + (0x97CUL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA0_ADDR(base) ((base) + (0xA00UL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA1_ADDR(base) ((base) + (0xA04UL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA2_ADDR(base) ((base) + (0xA08UL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA3_ADDR(base) ((base) + (0xA0CUL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA4_ADDR(base) ((base) + (0xA10UL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA5_ADDR(base) ((base) + (0xA14UL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA6_ADDR(base) ((base) + (0xA18UL))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA7_ADDR(base) ((base) + (0xA1CUL))
#define SOC_LPM3_CFG_LPMCU_ENHANCE_CTRL_ADDR(base) ((base) + (0xF00UL))
#define SOC_LPM3_CFG_LPMCU_RSV_ENHANCE_CTRL_ADDR(base) ((base) + (0xF04UL))
#else
#define SOC_LPM3_CFG_ACCESS_WIN_ADDR(base) ((base) + (0x000))
#define SOC_LPM3_CFG_HALT_BYPASS_ADDR(base) ((base) + (0x004))
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_ADDR(base) ((base) + (0x008))
#define SOC_LPM3_CFG_DLOCK_BYPASS_ADDR(base) ((base) + (0x00C))
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_ADDR(base) ((base) + (0x010))
#define SOC_LPM3_CFG_TESTPIN_EN_ADDR(base) ((base) + (0x014))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_ADDR(base) ((base) + (0x018))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_ADDR(base) ((base) + (0x01C))
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL0_ADDR(base) ((base) + (0x020))
#define SOC_LPM3_CFG_LPMCU_RSV_STAT0_ADDR(base) ((base) + (0x024))
#define SOC_LPM3_CFG_NMI_SOFT_ADDR(base) ((base) + (0x028))
#define SOC_LPM3_CFG_LPMCU_NMI_EN_ADDR(base) ((base) + (0x02C))
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_ADDR(base) ((base) + (0x030))
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_ADDR(base) ((base) + (0x034))
#define SOC_LPM3_CFG_LPMCU_ISP_INT_CTRL_ADDR(base) ((base) + (0x060))
#define SOC_LPM3_CFG_LPMCU_ISP_INT_STAT_ADDR(base) ((base) + (0x064))
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_ADDR(base) ((base) + (0x068))
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_ADDR(base) ((base) + (0x06C))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_ADDR(base) ((base) + (0x070))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_ADDR(base) ((base) + (0x074))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_ADDR(base) ((base) + (0x078))
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_ADDR(base) ((base) + (0x07C))
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_ADDR(base) ((base) + (0x080))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_ADDR(base) ((base) + (0x084))
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_ADDR(base) ((base) + (0x088))
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_ADDR(base) ((base) + (0x08C))
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_ADDR(base) ((base) + (0x090))
#define SOC_LPM3_CFG_LPMCU_DBG_INFO1_ADDR(base) ((base) + (0x094))
#define SOC_LPM3_CFG_LPMCU_PIEACK0_31_ADDR(base) ((base) + (0x600))
#define SOC_LPM3_CFG_LPMCU_PIEINT0_31_ADDR(base) ((base) + (0x624))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_ADDR(base) ((base) + (0x660))
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_ADDR(base) ((base) + (0x664))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_ADDR(base) ((base) + (0x668))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_ADDR(base) ((base) + (0x66C))
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_ADDR(base) ((base) + (0x670))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_ADDR(base) ((base) + (0x674))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_ADDR(base) ((base) + (0x678))
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_ADDR(base) ((base) + (0x67C))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_ADDR(base) ((base) + (0x680))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_ADDR(base) ((base) + (0x684))
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_ADDR(base) ((base) + (0x688))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_ADDR(base) ((base) + (0x68C))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_ADDR(base) ((base) + (0x690))
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_ADDR(base) ((base) + (0x694))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_ADDR(base) ((base) + (0x698))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_ADDR(base) ((base) + (0x69C))
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_ADDR(base) ((base) + (0x6A0))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_ADDR(base) ((base) + (0x6A4))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_ADDR(base) ((base) + (0x6A8))
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_ADDR(base) ((base) + (0x6AC))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_ADDR(base) ((base) + (0x6B0))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_ADDR(base) ((base) + (0x6B4))
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_ADDR(base) ((base) + (0x6B8))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_ADDR(base) ((base) + (0x6BC))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_ADDR(base) ((base) + (0x6C0))
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_ADDR(base) ((base) + (0x6C4))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_ADDR(base) ((base) + (0x6C8))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_ADDR(base) ((base) + (0x6CC))
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_ADDR(base) ((base) + (0x6D0))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_ADDR(base) ((base) + (0x6D4))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_ADDR(base) ((base) + (0x6D8))
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_ADDR(base) ((base) + (0x6DC))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_ADDR(base) ((base) + (0x6E0))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_ADDR(base) ((base) + (0x6E4))
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_ADDR(base) ((base) + (0x6E8))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_ADDR(base) ((base) + (0x6EC))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_ADDR(base) ((base) + (0x6F0))
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_ADDR(base) ((base) + (0x6F4))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_ADDR(base) ((base) + (0x6F8))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_ADDR(base) ((base) + (0x6FC))
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_ADDR(base) ((base) + (0x700))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_ADDR(base) ((base) + (0x704))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_ADDR(base) ((base) + (0x708))
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_ADDR(base) ((base) + (0x70C))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_ADDR(base) ((base) + (0x710))
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_ADDR(base) ((base) + (0x714))
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_ADDR(base) ((base) + (0x718))
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_ADDR(base) ((base) + (0x71C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_ADDR(base) ((base) + (0x800))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_ADDR(base) ((base) + (0x804))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_ADDR(base) ((base) + (0x808))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_ADDR(base) ((base) + (0x80C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_ADDR(base) ((base) + (0x810))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_ADDR(base) ((base) + (0x814))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_ADDR(base) ((base) + (0x818))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_ADDR(base) ((base) + (0x81C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_ADDR(base) ((base) + (0x820))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_ADDR(base) ((base) + (0x824))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_ADDR(base) ((base) + (0x828))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_ADDR(base) ((base) + (0x82C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_ADDR(base) ((base) + (0x830))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_ADDR(base) ((base) + (0x834))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_ADDR(base) ((base) + (0x838))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_ADDR(base) ((base) + (0x83C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_ADDR(base) ((base) + (0x840))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_ADDR(base) ((base) + (0x844))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_ADDR(base) ((base) + (0x848))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_ADDR(base) ((base) + (0x84C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_ADDR(base) ((base) + (0x850))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_ADDR(base) ((base) + (0x854))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_ADDR(base) ((base) + (0x858))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_ADDR(base) ((base) + (0x85C))
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_ADDR(base) ((base) + (0x860))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_ADDR(base) ((base) + (0x900))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_ADDR(base) ((base) + (0x904))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_ADDR(base) ((base) + (0x908))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_ADDR(base) ((base) + (0x90C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_ADDR(base) ((base) + (0x910))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_ADDR(base) ((base) + (0x914))
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_ADDR(base) ((base) + (0x918))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_ADDR(base) ((base) + (0x91C))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_ADDR(base) ((base) + (0x920))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_ADDR(base) ((base) + (0x924))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_ADDR(base) ((base) + (0x928))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_ADDR(base) ((base) + (0x92C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_ADDR(base) ((base) + (0x930))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_ADDR(base) ((base) + (0x934))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_ADDR(base) ((base) + (0x938))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_ADDR(base) ((base) + (0x93C))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_ADDR(base) ((base) + (0x940))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_ADDR(base) ((base) + (0x944))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_ADDR(base) ((base) + (0x948))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_ADDR(base) ((base) + (0x94C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_ADDR(base) ((base) + (0x950))
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_ADDR(base) ((base) + (0x954))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_ADDR(base) ((base) + (0x958))
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_ADDR(base) ((base) + (0x95C))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_ADDR(base) ((base) + (0x960))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_ADDR(base) ((base) + (0x964))
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_ADDR(base) ((base) + (0x968))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_ADDR(base) ((base) + (0x96C))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_ADDR(base) ((base) + (0x970))
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_ADDR(base) ((base) + (0x974))
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_ADDR(base) ((base) + (0x978))
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_ADDR(base) ((base) + (0x97C))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA0_ADDR(base) ((base) + (0xA00))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA1_ADDR(base) ((base) + (0xA04))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA2_ADDR(base) ((base) + (0xA08))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA3_ADDR(base) ((base) + (0xA0C))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA4_ADDR(base) ((base) + (0xA10))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA5_ADDR(base) ((base) + (0xA14))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA6_ADDR(base) ((base) + (0xA18))
#define SOC_LPM3_CFG_LPMCU_FPB_DATA7_ADDR(base) ((base) + (0xA1C))
#define SOC_LPM3_CFG_LPMCU_ENHANCE_CTRL_ADDR(base) ((base) + (0xF00))
#define SOC_LPM3_CFG_LPMCU_RSV_ENHANCE_CTRL_ADDR(base) ((base) + (0xF04))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 28;
        unsigned int access_win : 4;
    } reg;
} SOC_LPM3_CFG_ACCESS_WIN_UNION;
#endif
#define SOC_LPM3_CFG_ACCESS_WIN_access_win_START (28)
#define SOC_LPM3_CFG_ACCESS_WIN_access_win_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int halt_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_HALT_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_HALT_BYPASS_halt_bypass_START (0)
#define SOC_LPM3_CFG_HALT_BYPASS_halt_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pmctrl_apb_auto_clken_bypass : 1;
        unsigned int lpram_multi_ctrl : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPRAM_MULTI_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_pmctrl_apb_auto_clken_bypass_START (0)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_pmctrl_apb_auto_clken_bypass_END (0)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_lpram_multi_ctrl_START (1)
#define SOC_LPM3_CFG_LPRAM_MULTI_CTRL_lpram_multi_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass_for_i2c1 : 1;
        unsigned int bypass_for_ccrg : 1;
        unsigned int bypass_for_tsen : 1;
        unsigned int bypass_for_pmc : 1;
        unsigned int bypass_for_uart : 1;
        unsigned int bypass_for_i2c : 1;
        unsigned int bypass_for_apb2spi : 1;
        unsigned int bypass_for_pcrg : 1;
        unsigned int bypass_for_wdog : 1;
        unsigned int bypass_for_timer : 1;
        unsigned int reserved_0 : 1;
        unsigned int bypass_for_cssys : 1;
        unsigned int reserved_1 : 1;
        unsigned int bypass_for_rom : 1;
        unsigned int bypass_for_ram : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_LPM3_CFG_DLOCK_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_i2c1_START (0)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_i2c1_END (0)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ccrg_START (1)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ccrg_END (1)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_tsen_START (2)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_tsen_END (2)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pmc_START (3)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pmc_END (3)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_uart_START (4)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_uart_END (4)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_i2c_START (5)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_i2c_END (5)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_apb2spi_START (6)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_apb2spi_END (6)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pcrg_START (7)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_pcrg_END (7)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_wdog_START (8)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_wdog_END (8)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_timer_START (9)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_timer_END (9)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_cssys_START (11)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_cssys_END (11)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_rom_START (13)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_rom_END (13)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ram_START (14)
#define SOC_LPM3_CFG_DLOCK_BYPASS_bypass_for_ram_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timclken_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_TIMCLKEN_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_timclken_bypass_START (0)
#define SOC_LPM3_CFG_TIMCLKEN_BYPASS_timclken_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int testpin_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_TESTPIN_EN_UNION;
#endif
#define SOC_LPM3_CFG_TESTPIN_EN_testpin_en_START (0)
#define SOC_LPM3_CFG_TESTPIN_EN_testpin_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_repair_err_clr : 1;
        unsigned int mbist_mux_sel : 1;
        unsigned int lpmcu_intr_to_aotcp : 1;
        unsigned int intr_repair_err_clr_1 : 1;
        unsigned int reserved_0 : 12;
        unsigned int vbat_drop_protect_db_cfg : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_START (0)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_END (0)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_mbist_mux_sel_START (1)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_mbist_mux_sel_END (1)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_lpmcu_intr_to_aotcp_START (2)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_lpmcu_intr_to_aotcp_END (2)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_1_START (3)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_intr_repair_err_clr_1_END (3)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_vbat_drop_protect_db_cfg_START (16)
#define SOC_LPM3_CFG_LPMCU_RSV_CTRL_vbat_drop_protect_db_cfg_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_dfs_ok : 1;
        unsigned int lpram_dso0 : 1;
        unsigned int lpram_dso1 : 1;
        unsigned int npu_rst_enhance_stat : 1;
        unsigned int fdul_rst_enhance_stat : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_STAT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_dss_dfs_ok_START (0)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_dss_dfs_ok_END (0)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_lpram_dso0_START (1)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_lpram_dso0_END (1)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_lpram_dso1_START (2)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_lpram_dso1_END (2)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_npu_rst_enhance_stat_START (3)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_npu_rst_enhance_stat_END (3)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_fdul_rst_enhance_stat_START (4)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT_fdul_rst_enhance_stat_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int boot_remap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_STAT0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_RSV_STAT0_boot_remap_START (0)
#define SOC_LPM3_CFG_LPMCU_RSV_STAT0_boot_remap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_nmi_soft : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_NMI_SOFT_UNION;
#endif
#define SOC_LPM3_CFG_NMI_SOFT_intr_nmi_soft_START (0)
#define SOC_LPM3_CFG_NMI_SOFT_intr_nmi_soft_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_nmi_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_NMI_EN_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_NMI_EN_intr_nmi_en_START (0)
#define SOC_LPM3_CFG_LPMCU_NMI_EN_intr_nmi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int auto_clkgt_cfg_ccrg : 1;
        unsigned int reserved_1 : 1;
        unsigned int auto_clkgt_cfg_pmc : 1;
        unsigned int reserved_2 : 1;
        unsigned int auto_clkgt_cfg_i2c : 1;
        unsigned int reserved_3 : 1;
        unsigned int auto_clkgt_cfg_pcrg : 1;
        unsigned int auto_clkgt_cfg_wdog : 1;
        unsigned int auto_clkgt_cfg_timer : 1;
        unsigned int auto_clkgt_cfg_cssys : 1;
        unsigned int reserved_4 : 1;
        unsigned int auto_clkgt_cfg_rom : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int auto_clkgt_cfg_apb : 1;
        unsigned int reserved_9 : 14;
    } reg;
} SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_ccrg_START (1)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_ccrg_END (1)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pmc_START (3)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pmc_END (3)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_i2c_START (5)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_i2c_END (5)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pcrg_START (7)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_pcrg_END (7)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_wdog_START (8)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_wdog_END (8)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_timer_START (9)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_timer_END (9)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_cssys_START (10)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_cssys_END (10)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_rom_START (12)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_rom_END (12)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_apb_START (17)
#define SOC_LPM3_CFG_LPMCU_ATCLKCG_CTRL_auto_clkgt_cfg_apb_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_wd0nmi_en : 1;
        unsigned int lpmcu_wd1nmi_en : 1;
        unsigned int lpmcu_wd2nmi_en : 1;
        unsigned int lpmcu_wd3nmi_en : 1;
        unsigned int lpmcu_wd4nmi_en : 1;
        unsigned int lpmcu_wd5nmi_en : 1;
        unsigned int lpmcu_wd6nmi_en : 1;
        unsigned int lpmcu_wd7nmi_en : 1;
        unsigned int lpmcu_wd8nmi_en : 1;
        unsigned int lpmcu_wd9nmi_en : 1;
        unsigned int lpmcu_wd10nmi_en : 1;
        unsigned int lpmcu_wd11nmi_en : 1;
        unsigned int lpmcu_wd12nmi_en : 1;
        unsigned int lpmcu_wd13nmi_en : 1;
        unsigned int lpmcu_wd14nmi_en : 1;
        unsigned int lpmcu_wd15nmi_en : 1;
        unsigned int lpmcu_wd16nmi_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_LPM3_CFG_LPMCU_WD2NMI_EN_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd0nmi_en_START (0)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd0nmi_en_END (0)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd1nmi_en_START (1)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd1nmi_en_END (1)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd2nmi_en_START (2)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd2nmi_en_END (2)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd3nmi_en_START (3)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd3nmi_en_END (3)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd4nmi_en_START (4)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd4nmi_en_END (4)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd5nmi_en_START (5)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd5nmi_en_END (5)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd6nmi_en_START (6)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd6nmi_en_END (6)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd7nmi_en_START (7)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd7nmi_en_END (7)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd8nmi_en_START (8)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd8nmi_en_END (8)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd9nmi_en_START (9)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd9nmi_en_END (9)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd10nmi_en_START (10)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd10nmi_en_END (10)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd11nmi_en_START (11)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd11nmi_en_END (11)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd12nmi_en_START (12)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd12nmi_en_END (12)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd13nmi_en_START (13)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd13nmi_en_END (13)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd14nmi_en_START (14)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd14nmi_en_END (14)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd15nmi_en_START (15)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd15nmi_en_END (15)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd16nmi_en_START (16)
#define SOC_LPM3_CFG_LPMCU_WD2NMI_EN_lpmcu_wd16nmi_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp2ddr_dfs_int_en : 1;
        unsigned int isp2ddr_dfs_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_ISP_INT_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_ISP_INT_CTRL_isp2ddr_dfs_int_en_START (0)
#define SOC_LPM3_CFG_LPMCU_ISP_INT_CTRL_isp2ddr_dfs_int_en_END (0)
#define SOC_LPM3_CFG_LPMCU_ISP_INT_CTRL_isp2ddr_dfs_int_clr_START (1)
#define SOC_LPM3_CFG_LPMCU_ISP_INT_CTRL_isp2ddr_dfs_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp2ddr_dfs_int_raw : 1;
        unsigned int isp2ddr_dfs_int_msk : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_ISP_INT_STAT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_ISP_INT_STAT_isp2ddr_dfs_int_raw_START (0)
#define SOC_LPM3_CFG_LPMCU_ISP_INT_STAT_isp2ddr_dfs_int_raw_END (0)
#define SOC_LPM3_CFG_LPMCU_ISP_INT_STAT_isp2ddr_dfs_int_msk_START (1)
#define SOC_LPM3_CFG_LPMCU_ISP_INT_STAT_isp2ddr_dfs_int_msk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_sync_cg_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_lpmcu_sync_cg_bypass_START (0)
#define SOC_LPM3_CFG_LPMCU_SYNC_CG_BYPASS_lpmcu_sync_cg_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_dmss_hclk_gt : 1;
        unsigned int lpmcu_dmc_hclk_gt_a : 1;
        unsigned int lpmcu_dmc_hclk_gt_b : 1;
        unsigned int lpmcu_dmc_hclk_gt_c : 1;
        unsigned int lpmcu_dmc_hclk_gt_d : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmss_hclk_gt_START (0)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmss_hclk_gt_END (0)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_a_START (1)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_a_END (1)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_b_START (2)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_b_END (2)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_c_START (3)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_c_END (3)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_d_START (4)
#define SOC_LPM3_CFG_LPMCU_DMSS_DMC_HCLK_GT_lpmcu_dmc_hclk_gt_d_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pctrl_time_cfg : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_lpmcu_pctrl_time_cfg_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIME_CFG_lpmcu_pctrl_time_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pctrl_timeout_int_en : 1;
        unsigned int lpmcu_pctrl_timeout_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_en_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_en_END (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_clr_START (1)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_CTRL_lpmcu_pctrl_timeout_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pctrl_timeout_int_raw : 1;
        unsigned int lpmcu_pctrl_timeout_int_msk : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_raw_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_raw_END (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_msk_START (1)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_INT_STAT_lpmcu_pctrl_timeout_int_msk_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pctrl_timeout_bypass : 1;
        unsigned int lpmcu_pctrl_timeout_resperr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_bypass_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_bypass_END (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_resperr_START (1)
#define SOC_LPM3_CFG_LPMCU_PCTRL_TIMEOUT_bypass_lpmcu_pctrl_timeout_resperr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lp_pctrl_apb_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_lp_pctrl_apb_sel_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_APB_SEL_lp_pctrl_apb_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pctrl_dbg_info1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_lpmcu_pctrl_dbg_info1_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO1_lpmcu_pctrl_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pctrl_dbg_info2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_lpmcu_pctrl_dbg_info2_START (0)
#define SOC_LPM3_CFG_LPMCU_PCTRL_DBG_INFO2_lpmcu_pctrl_dbg_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lp_dmcbus_hprot_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int radio_mode : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_lp_dmcbus_hprot_sel_START (0)
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_lp_dmcbus_hprot_sel_END (0)
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_radio_mode_START (3)
#define SOC_LPM3_CFG_LPMCU_DMCBUS_HPROT_SEL_radio_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_mskint_h1 : 1;
        unsigned int temp_mskint_h2 : 1;
        unsigned int temp_mskint_h3 : 1;
        unsigned int temp_mskint_h4 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_LPM3_CFG_LPMCU_TSENSOR_INT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h1_START (0)
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h1_END (0)
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h2_START (1)
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h2_END (1)
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h3_START (2)
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h3_END (2)
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h4_START (3)
#define SOC_LPM3_CFG_LPMCU_TSENSOR_INT_temp_mskint_h4_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_info_corecrg : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_DBG_INFO1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_DBG_INFO1_dbg_info_corecrg_START (0)
#define SOC_LPM3_CFG_LPMCU_DBG_INFO1_dbg_info_corecrg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieack0_31 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEACK0_31_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEACK0_31_lpmcu_pieack0_31_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEACK0_31_lpmcu_pieack0_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieint0_31 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEINT0_31_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEINT0_31_lpmcu_pieint0_31_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEINT0_31_lpmcu_pieint0_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_lpmcu_pie_primifr10_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR10_lpmcu_pie_primifr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_lpmcu_pieimr10_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR10_lpmcu_pieimr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_lpmcu_pie_maskifr10_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR10_lpmcu_pie_maskifr10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_lpmcu_pie_primifr11_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR11_lpmcu_pie_primifr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_lpmcu_pieimr11_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR11_lpmcu_pieimr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_lpmcu_pie_maskifr11_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR11_lpmcu_pie_maskifr11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_lpmcu_pie_primifr12_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR12_lpmcu_pie_primifr12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_lpmcu_pieimr12_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR12_lpmcu_pieimr12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_lpmcu_pie_maskifr12_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR12_lpmcu_pie_maskifr12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr13 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_lpmcu_pie_primifr13_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR13_lpmcu_pie_primifr13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr13 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR13_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_lpmcu_pieimr13_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR13_lpmcu_pieimr13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr13 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_lpmcu_pie_maskifr13_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR13_lpmcu_pie_maskifr13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr14 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_lpmcu_pie_primifr14_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR14_lpmcu_pie_primifr14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr14 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR14_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_lpmcu_pieimr14_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR14_lpmcu_pieimr14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr14 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_lpmcu_pie_maskifr14_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR14_lpmcu_pie_maskifr14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr15 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_lpmcu_pie_primifr15_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR15_lpmcu_pie_primifr15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr15 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR15_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_lpmcu_pieimr15_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR15_lpmcu_pieimr15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr15 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_lpmcu_pie_maskifr15_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR15_lpmcu_pie_maskifr15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr16 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_lpmcu_pie_primifr16_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR16_lpmcu_pie_primifr16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr16 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR16_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_lpmcu_pieimr16_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR16_lpmcu_pieimr16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr16 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_lpmcu_pie_maskifr16_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR16_lpmcu_pie_maskifr16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr17 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_lpmcu_pie_primifr17_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR17_lpmcu_pie_primifr17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr17 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR17_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_lpmcu_pieimr17_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR17_lpmcu_pieimr17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr17 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_lpmcu_pie_maskifr17_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR17_lpmcu_pie_maskifr17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr18 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_lpmcu_pie_primifr18_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR18_lpmcu_pie_primifr18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr18 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR18_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_lpmcu_pieimr18_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR18_lpmcu_pieimr18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr18 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_lpmcu_pie_maskifr18_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR18_lpmcu_pie_maskifr18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr19 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_lpmcu_pie_primifr19_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR19_lpmcu_pie_primifr19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr19 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR19_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_lpmcu_pieimr19_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR19_lpmcu_pieimr19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr19 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_lpmcu_pie_maskifr19_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR19_lpmcu_pie_maskifr19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_lpmcu_pie_primifr20_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR20_lpmcu_pie_primifr20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_lpmcu_pieimr20_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR20_lpmcu_pieimr20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_lpmcu_pie_maskifr20_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR20_lpmcu_pie_maskifr20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_lpmcu_pie_primifr21_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR21_lpmcu_pie_primifr21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_lpmcu_pieimr21_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR21_lpmcu_pieimr21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_lpmcu_pie_maskifr21_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR21_lpmcu_pie_maskifr21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_lpmcu_pie_primifr22_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR22_lpmcu_pie_primifr22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_lpmcu_pieimr22_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR22_lpmcu_pieimr22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_lpmcu_pie_maskifr22_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR22_lpmcu_pie_maskifr22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr23 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_lpmcu_pie_primifr23_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR23_lpmcu_pie_primifr23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr23 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR23_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_lpmcu_pieimr23_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR23_lpmcu_pieimr23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr23 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_lpmcu_pie_maskifr23_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR23_lpmcu_pie_maskifr23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr24 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_lpmcu_pie_primifr24_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR24_lpmcu_pie_primifr24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr24 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR24_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_lpmcu_pieimr24_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR24_lpmcu_pieimr24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr24 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_lpmcu_pie_maskifr24_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR24_lpmcu_pie_maskifr24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_primifr25 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_lpmcu_pie_primifr25_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_PRIMIFR25_lpmcu_pie_primifr25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pieimr25 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIEIMR25_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_lpmcu_pieimr25_START (0)
#define SOC_LPM3_CFG_LPMCU_PIEIMR25_lpmcu_pieimr25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_pie_maskifr25 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_lpmcu_pie_maskifr25_START (0)
#define SOC_LPM3_CFG_LPMCU_PIE_MASKIFR25_lpmcu_pie_maskifr25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_icfg_addr_scr0_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR0_icfg_addr_scr0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_icfg_addr_scr1_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR1_icfg_addr_scr1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_icfg_addr_scr2_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR2_icfg_addr_scr2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_icfg_addr_scr3_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR3_icfg_addr_scr3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_icfg_addr_scr4_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR4_icfg_addr_scr4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_icfg_addr_scr5_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR5_icfg_addr_scr5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_icfg_addr_scr6_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR6_icfg_addr_scr6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_scr7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_icfg_addr_scr7_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_SCR7_icfg_addr_scr7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_icfg_addr_len0_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN0_icfg_addr_len0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_icfg_addr_len1_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN1_icfg_addr_len1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_icfg_addr_len2_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN2_icfg_addr_len2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_icfg_addr_len3_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN3_icfg_addr_len3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_icfg_addr_len4_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN4_icfg_addr_len4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_icfg_addr_len5_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN5_icfg_addr_len5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_icfg_addr_len6_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN6_icfg_addr_len6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_icfg_addr_len7_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_LEN7_icfg_addr_len7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst0 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_icfg_addr_dst0_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST0_icfg_addr_dst0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst1 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_icfg_addr_dst1_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST1_icfg_addr_dst1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst2 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_icfg_addr_dst2_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST2_icfg_addr_dst2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst3 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_icfg_addr_dst3_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST3_icfg_addr_dst3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst4 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_icfg_addr_dst4_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST4_icfg_addr_dst4_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst5 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_icfg_addr_dst5_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST5_icfg_addr_dst5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst6 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_icfg_addr_dst6_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST6_icfg_addr_dst6_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst7 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_icfg_addr_dst7_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DST7_icfg_addr_dst7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_default : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_icfg_addr_default_START (0)
#define SOC_LPM3_CFG_LPMCU_FAMA_ICFG_ADDR_DEFAULT_icfg_addr_default_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_cfg1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_lpmcu_prob_addr_cfg1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG1_lpmcu_prob_addr_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_msk1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_lpmcu_prob_addr_msk1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK1_lpmcu_prob_addr_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_ref1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_lpmcu_prob_addr_ref1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF1_lpmcu_prob_addr_ref1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_cfg1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_lpmcu_prob_data_cfg1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG1_lpmcu_prob_data_cfg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_mask1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_lpmcu_prob_data_mask1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK1_lpmcu_prob_data_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_ref1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_lpmcu_prob_data_ref1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF1_lpmcu_prob_data_ref1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_en1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_EN1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_lpmcu_prob_en1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_EN1_lpmcu_prob_en1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_cnt1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_lpmcu_prob_cnt1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT1_lpmcu_prob_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_cnt_clr1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_lpmcu_prob_cnt_clr1_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR1_lpmcu_prob_cnt_clr1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_hit10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_lpmcu_prob_addr_hit10_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT10_lpmcu_prob_addr_hit10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_hit11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_lpmcu_prob_addr_hit11_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT11_lpmcu_prob_addr_hit11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_hit12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_lpmcu_prob_addr_hit12_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT12_lpmcu_prob_addr_hit12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_hit10 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_lpmcu_prob_data_hit10_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT10_lpmcu_prob_data_hit10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_hit11 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_lpmcu_prob_data_hit11_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT11_lpmcu_prob_data_hit11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_hit12 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_lpmcu_prob_data_hit12_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT12_lpmcu_prob_data_hit12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_cfg2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_lpmcu_prob_addr_cfg2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_CFG2_lpmcu_prob_addr_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_msk2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_lpmcu_prob_addr_msk2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_MSK2_lpmcu_prob_addr_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_ref2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_lpmcu_prob_addr_ref2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_REF2_lpmcu_prob_addr_ref2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_cfg2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_lpmcu_prob_data_cfg2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_CFG2_lpmcu_prob_data_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_mask2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_lpmcu_prob_data_mask2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_MASK2_lpmcu_prob_data_mask2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_ref2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_lpmcu_prob_data_ref2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_REF2_lpmcu_prob_data_ref2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_en2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_EN2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_lpmcu_prob_en2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_EN2_lpmcu_prob_en2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_cnt2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_lpmcu_prob_cnt2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT2_lpmcu_prob_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_cnt_clr2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_lpmcu_prob_cnt_clr2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CNT_CLR2_lpmcu_prob_cnt_clr2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_hit20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_lpmcu_prob_addr_hit20_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT20_lpmcu_prob_addr_hit20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_hit21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_lpmcu_prob_addr_hit21_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT21_lpmcu_prob_addr_hit21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_addr_hit22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_lpmcu_prob_addr_hit22_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_ADDR_HIT22_lpmcu_prob_addr_hit22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_hit20 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_lpmcu_prob_data_hit20_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT20_lpmcu_prob_data_hit20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_hit21 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_lpmcu_prob_data_hit21_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT21_lpmcu_prob_data_hit21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_data_hit22 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_lpmcu_prob_data_hit22_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_DATA_HIT22_lpmcu_prob_data_hit22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_prob_clken2 : 1;
        unsigned int lpmcu_prob_clken1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROB_CLKEN_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken2_START (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken2_END (0)
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken1_START (1)
#define SOC_LPM3_CFG_LPMCU_PROB_CLKEN_lpmcu_prob_clken1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_probhit_topint : 1;
        unsigned int lpmcu_probhit_int2 : 1;
        unsigned int lpmcu_probhit_int1 : 1;
        unsigned int lpmcu_probhit_primint2 : 1;
        unsigned int lpmcu_probhit_primint1 : 1;
        unsigned int reserved_0 : 3;
        unsigned int lpmcu_probhitint_msk2 : 1;
        unsigned int lpmcu_probhitint_msk1 : 1;
        unsigned int reserved_1 : 2;
        unsigned int lpmcu_probhitint_clr2 : 1;
        unsigned int lpmcu_probhitint_clr1 : 1;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_LPM3_CFG_LPMCU_PROBHIT_INT_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_topint_START (0)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_topint_END (0)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int2_START (1)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int2_END (1)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int1_START (2)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_int1_END (2)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint2_START (3)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint2_END (3)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint1_START (4)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhit_primint1_END (4)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk2_START (8)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk2_END (8)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk1_START (9)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_msk1_END (9)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr2_START (12)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr2_END (12)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr1_START (13)
#define SOC_LPM3_CFG_LPMCU_PROBHIT_INT_lpmcu_probhitint_clr1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data0 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA0_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA0_lpmcu_fpb_data0_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA0_lpmcu_fpb_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data1 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA1_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA1_lpmcu_fpb_data1_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA1_lpmcu_fpb_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data2 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA2_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA2_lpmcu_fpb_data2_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA2_lpmcu_fpb_data2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data3 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA3_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA3_lpmcu_fpb_data3_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA3_lpmcu_fpb_data3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data4 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA4_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA4_lpmcu_fpb_data4_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA4_lpmcu_fpb_data4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data5 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA5_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA5_lpmcu_fpb_data5_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA5_lpmcu_fpb_data5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data6 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA6_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA6_lpmcu_fpb_data6_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA6_lpmcu_fpb_data6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpmcu_fpb_data7 : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_FPB_DATA7_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_FPB_DATA7_lpmcu_fpb_data7_START (0)
#define SOC_LPM3_CFG_LPMCU_FPB_DATA7_lpmcu_fpb_data7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int npu_rst_enhance_ctrl : 1;
        unsigned int fdul_rst_enhance_ctrl : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_LPM3_CFG_LPMCU_ENHANCE_CTRL_UNION;
#endif
#define SOC_LPM3_CFG_LPMCU_ENHANCE_CTRL_npu_rst_enhance_ctrl_START (0)
#define SOC_LPM3_CFG_LPMCU_ENHANCE_CTRL_npu_rst_enhance_ctrl_END (0)
#define SOC_LPM3_CFG_LPMCU_ENHANCE_CTRL_fdul_rst_enhance_ctrl_START (1)
#define SOC_LPM3_CFG_LPMCU_ENHANCE_CTRL_fdul_rst_enhance_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LPM3_CFG_LPMCU_RSV_ENHANCE_CTRL_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
