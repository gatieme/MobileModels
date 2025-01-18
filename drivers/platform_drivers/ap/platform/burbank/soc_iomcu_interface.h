#ifndef __SOC_IOMCU_INTERFACE_H__
#define __SOC_IOMCU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOMCU_CLK_SEL_ADDR(base) ((base) + (0x000UL))
#define SOC_IOMCU_CFG_DIV0_ADDR(base) ((base) + (0x004UL))
#define SOC_IOMCU_CFG_DIV1_ADDR(base) ((base) + (0x008UL))
#define SOC_IOMCU_RTC_CFG_ADDR(base) ((base) + (0x00CUL))
#define SOC_IOMCU_CLKEN0_ADDR(base) ((base) + (0x010UL))
#define SOC_IOMCU_CLKDIS0_ADDR(base) ((base) + (0x014UL))
#define SOC_IOMCU_CLKSTAT0_ADDR(base) ((base) + (0x018UL))
#define SOC_IOMCU_RSTEN0_ADDR(base) ((base) + (0x020UL))
#define SOC_IOMCU_RSTDIS0_ADDR(base) ((base) + (0x024UL))
#define SOC_IOMCU_RSTSTAT0_ADDR(base) ((base) + (0x028UL))
#define SOC_IOMCU_M7_CFG0_ADDR(base) ((base) + (0x030UL))
#define SOC_IOMCU_M7_CFG1_ADDR(base) ((base) + (0x034UL))
#define SOC_IOMCU_M7_STAT0_ADDR(base) ((base) + (0x038UL))
#define SOC_IOMCU_M7_STAT1_ADDR(base) ((base) + (0x03CUL))
#define SOC_IOMCU_DDR_ACCESS_WINDOW_ADDR(base) ((base) + (0x040UL))
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_ADDR(base) ((base) + (0x044UL))
#define SOC_IOMCU_HACK_ACCESS_WINDOW_ADDR(base) ((base) + (0x048UL))
#define SOC_IOMCU_DLOCK_BYPASS_ADDR(base) ((base) + (0x04CUL))
#define SOC_IOMCU_MEM_CTRL_PGT_ADDR(base) ((base) + (0x050UL))
#define SOC_IOMCU_MEM_CTRL_ADDR(base) ((base) + (0x054UL))
#define SOC_IOMCU_SYS_STAT_ADDR(base) ((base) + (0x058UL))
#define SOC_IOMCU_SYS_CONFIG_ADDR(base) ((base) + (0x05CUL))
#define SOC_IOMCU_WAKEUP_EN_ADDR(base) ((base) + (0x060UL))
#define SOC_IOMCU_WAKEUP_CLR_ADDR(base) ((base) + (0x064UL))
#define SOC_IOMCU_WAKEUP_STAT_ADDR(base) ((base) + (0x068UL))
#define SOC_IOMCU_COMB_INT_RAW_ADDR(base) ((base) + (0x070UL))
#define SOC_IOMCU_COMB_INT_MSK_ADDR(base) ((base) + (0x074UL))
#define SOC_IOMCU_COMB_INT_STAT_ADDR(base) ((base) + (0x078UL))
#define SOC_IOMCU_BUS_AUTO_FREQ_ADDR(base) ((base) + (0x080UL))
#define SOC_IOMCU_MISC_CTRL_ADDR(base) ((base) + (0x084UL))
#define SOC_IOMCU_NOC_CTRL_ADDR(base) ((base) + (0x088UL))
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_ADDR(base) ((base) + (0x08CUL))
#define SOC_IOMCU_CLKEN1_ADDR(base) ((base) + (0x090UL))
#define SOC_IOMCU_CLKDIS1_ADDR(base) ((base) + (0x094UL))
#define SOC_IOMCU_CLKSTAT1_ADDR(base) ((base) + (0x098UL))
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ADDR(base) ((base) + (0x09CUL))
#define SOC_IOMCU_SEC_TZPC_ADDR(base) ((base) + (0x0100UL))
#define SOC_IOMCU_SEC_RES_ADDR(base) ((base) + (0x104UL))
#define SOC_IOMCU_MEM_CTRL6_ADDR(base) ((base) + (0x108UL))
#define SOC_IOMCU_MEM_CTRL_TCM_ADDR(base) ((base) + (0x19CUL))
#define SOC_IOMCU_MEM_CTRL2_ADDR(base) ((base) + (0x200UL))
#define SOC_IOMCU_MEM_CTRL3_ADDR(base) ((base) + (0x204UL))
#define SOC_IOMCU_TCP_CTRL_ADDR(base) ((base) + (0x208UL))
#define SOC_IOMCU_MEM_CTRL4_ADDR(base) ((base) + (0x20CUL))
#define SOC_IOMCU_MEM_CTRL5_ADDR(base) ((base) + (0x210UL))
#define SOC_IOMCU_ARADDR_CHK_ADDR(base) ((base) + (0x214UL))
#define SOC_IOMCU_AWADDR_CHK_ADDR(base) ((base) + (0x218UL))
#define SOC_IOMCU_MID_CTRL_ADDR(base) ((base) + (0x21CUL))
#define SOC_IOMCU_CCM_CTRL_ADDR(base) ((base) + (0x220UL))
#define SOC_IOMCU_ARC_RB0_ADDR(base) ((base) + (0x224UL))
#define SOC_IOMCU_ARC_CTRL_ADDR(base) ((base) + (0x228UL))
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_ADDR(base) ((base) + (0x22CUL))
#define SOC_IOMCU_DCCM0_ERR_ADDR_ADDR(base) ((base) + (0x230UL))
#define SOC_IOMCU_DCCM1_ERR_ADDR_ADDR(base) ((base) + (0x234UL))
#define SOC_IOMCU_ICCM0_ERR_ADDR_ADDR(base) ((base) + (0x238UL))
#define SOC_IOMCU_CCM_RB0_ADDR(base) ((base) + (0x23CUL))
#define SOC_IOMCU_CCM_RB1_ADDR(base) ((base) + (0x240UL))
#define SOC_IOMCU_ARC_RB1_ADDR(base) ((base) + (0x244UL))
#define SOC_IOMCU_ARC_AP_PARAM0_ADDR(base) ((base) + (0x248UL))
#define SOC_IOMCU_ARC_AP_PARAM1_ADDR(base) ((base) + (0x24CUL))
#define SOC_IOMCU_ARC_EVENT_EN0_ADDR(base) ((base) + (0x250UL))
#define SOC_IOMCU_ARC_EVENT_EN1_ADDR(base) ((base) + (0x254UL))
#define SOC_IOMCU_ARC_EVENT_EN2_ADDR(base) ((base) + (0x258UL))
#define SOC_IOMCU_ARC_EVENT_EN3_ADDR(base) ((base) + (0x25CUL))
#define SOC_IOMCU_ARC_IRQ_EN0_ADDR(base) ((base) + (0x260UL))
#define SOC_IOMCU_ARC_IRQ_EN1_ADDR(base) ((base) + (0x264UL))
#define SOC_IOMCU_ARC_IRQ_EN2_ADDR(base) ((base) + (0x268UL))
#define SOC_IOMCU_ARC_IRQ_EN3_ADDR(base) ((base) + (0x26CUL))
#define SOC_IOMCU_ARC_EVENT_EN4_ADDR(base) ((base) + (0x270UL))
#define SOC_IOMCU_ARC_EVENT_EN5_ADDR(base) ((base) + (0x274UL))
#define SOC_IOMCU_ARC_EVENT_EN6_ADDR(base) ((base) + (0x278UL))
#define SOC_IOMCU_ARC_EVENT_EN7_ADDR(base) ((base) + (0x27CUL))
#define SOC_IOMCU_M7_AHB_DBG_INFO1_ADDR(base) ((base) + (0x280UL))
#define SOC_IOMCU_M7_AHB_DBG_INFO2_ADDR(base) ((base) + (0x284UL))
#define SOC_IOMCU_M7_AHB_TIME_CFG_ADDR(base) ((base) + (0x288UL))
#define SOC_IOMCU_M7_AHB_TIMEOUT_ADDR(base) ((base) + (0x28CUL))
#define SOC_IOMCU_RESERVED_REG0_ADDR(base) ((base) + (0x290UL))
#define SOC_IOMCU_RESERVED_REG1_ADDR(base) ((base) + (0x294UL))
#else
#define SOC_IOMCU_CLK_SEL_ADDR(base) ((base) + (0x000))
#define SOC_IOMCU_CFG_DIV0_ADDR(base) ((base) + (0x004))
#define SOC_IOMCU_CFG_DIV1_ADDR(base) ((base) + (0x008))
#define SOC_IOMCU_RTC_CFG_ADDR(base) ((base) + (0x00C))
#define SOC_IOMCU_CLKEN0_ADDR(base) ((base) + (0x010))
#define SOC_IOMCU_CLKDIS0_ADDR(base) ((base) + (0x014))
#define SOC_IOMCU_CLKSTAT0_ADDR(base) ((base) + (0x018))
#define SOC_IOMCU_RSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_IOMCU_RSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_IOMCU_RSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_IOMCU_M7_CFG0_ADDR(base) ((base) + (0x030))
#define SOC_IOMCU_M7_CFG1_ADDR(base) ((base) + (0x034))
#define SOC_IOMCU_M7_STAT0_ADDR(base) ((base) + (0x038))
#define SOC_IOMCU_M7_STAT1_ADDR(base) ((base) + (0x03C))
#define SOC_IOMCU_DDR_ACCESS_WINDOW_ADDR(base) ((base) + (0x040))
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_ADDR(base) ((base) + (0x044))
#define SOC_IOMCU_HACK_ACCESS_WINDOW_ADDR(base) ((base) + (0x048))
#define SOC_IOMCU_DLOCK_BYPASS_ADDR(base) ((base) + (0x04C))
#define SOC_IOMCU_MEM_CTRL_PGT_ADDR(base) ((base) + (0x050))
#define SOC_IOMCU_MEM_CTRL_ADDR(base) ((base) + (0x054))
#define SOC_IOMCU_SYS_STAT_ADDR(base) ((base) + (0x058))
#define SOC_IOMCU_SYS_CONFIG_ADDR(base) ((base) + (0x05C))
#define SOC_IOMCU_WAKEUP_EN_ADDR(base) ((base) + (0x060))
#define SOC_IOMCU_WAKEUP_CLR_ADDR(base) ((base) + (0x064))
#define SOC_IOMCU_WAKEUP_STAT_ADDR(base) ((base) + (0x068))
#define SOC_IOMCU_COMB_INT_RAW_ADDR(base) ((base) + (0x070))
#define SOC_IOMCU_COMB_INT_MSK_ADDR(base) ((base) + (0x074))
#define SOC_IOMCU_COMB_INT_STAT_ADDR(base) ((base) + (0x078))
#define SOC_IOMCU_BUS_AUTO_FREQ_ADDR(base) ((base) + (0x080))
#define SOC_IOMCU_MISC_CTRL_ADDR(base) ((base) + (0x084))
#define SOC_IOMCU_NOC_CTRL_ADDR(base) ((base) + (0x088))
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_ADDR(base) ((base) + (0x08C))
#define SOC_IOMCU_CLKEN1_ADDR(base) ((base) + (0x090))
#define SOC_IOMCU_CLKDIS1_ADDR(base) ((base) + (0x094))
#define SOC_IOMCU_CLKSTAT1_ADDR(base) ((base) + (0x098))
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ADDR(base) ((base) + (0x09C))
#define SOC_IOMCU_SEC_TZPC_ADDR(base) ((base) + (0x0100))
#define SOC_IOMCU_SEC_RES_ADDR(base) ((base) + (0x104))
#define SOC_IOMCU_MEM_CTRL6_ADDR(base) ((base) + (0x108))
#define SOC_IOMCU_MEM_CTRL_TCM_ADDR(base) ((base) + (0x19C))
#define SOC_IOMCU_MEM_CTRL2_ADDR(base) ((base) + (0x200))
#define SOC_IOMCU_MEM_CTRL3_ADDR(base) ((base) + (0x204))
#define SOC_IOMCU_TCP_CTRL_ADDR(base) ((base) + (0x208))
#define SOC_IOMCU_MEM_CTRL4_ADDR(base) ((base) + (0x20C))
#define SOC_IOMCU_MEM_CTRL5_ADDR(base) ((base) + (0x210))
#define SOC_IOMCU_ARADDR_CHK_ADDR(base) ((base) + (0x214))
#define SOC_IOMCU_AWADDR_CHK_ADDR(base) ((base) + (0x218))
#define SOC_IOMCU_MID_CTRL_ADDR(base) ((base) + (0x21C))
#define SOC_IOMCU_CCM_CTRL_ADDR(base) ((base) + (0x220))
#define SOC_IOMCU_ARC_RB0_ADDR(base) ((base) + (0x224))
#define SOC_IOMCU_ARC_CTRL_ADDR(base) ((base) + (0x228))
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_ADDR(base) ((base) + (0x22C))
#define SOC_IOMCU_DCCM0_ERR_ADDR_ADDR(base) ((base) + (0x230))
#define SOC_IOMCU_DCCM1_ERR_ADDR_ADDR(base) ((base) + (0x234))
#define SOC_IOMCU_ICCM0_ERR_ADDR_ADDR(base) ((base) + (0x238))
#define SOC_IOMCU_CCM_RB0_ADDR(base) ((base) + (0x23C))
#define SOC_IOMCU_CCM_RB1_ADDR(base) ((base) + (0x240))
#define SOC_IOMCU_ARC_RB1_ADDR(base) ((base) + (0x244))
#define SOC_IOMCU_ARC_AP_PARAM0_ADDR(base) ((base) + (0x248))
#define SOC_IOMCU_ARC_AP_PARAM1_ADDR(base) ((base) + (0x24C))
#define SOC_IOMCU_ARC_EVENT_EN0_ADDR(base) ((base) + (0x250))
#define SOC_IOMCU_ARC_EVENT_EN1_ADDR(base) ((base) + (0x254))
#define SOC_IOMCU_ARC_EVENT_EN2_ADDR(base) ((base) + (0x258))
#define SOC_IOMCU_ARC_EVENT_EN3_ADDR(base) ((base) + (0x25C))
#define SOC_IOMCU_ARC_IRQ_EN0_ADDR(base) ((base) + (0x260))
#define SOC_IOMCU_ARC_IRQ_EN1_ADDR(base) ((base) + (0x264))
#define SOC_IOMCU_ARC_IRQ_EN2_ADDR(base) ((base) + (0x268))
#define SOC_IOMCU_ARC_IRQ_EN3_ADDR(base) ((base) + (0x26C))
#define SOC_IOMCU_ARC_EVENT_EN4_ADDR(base) ((base) + (0x270))
#define SOC_IOMCU_ARC_EVENT_EN5_ADDR(base) ((base) + (0x274))
#define SOC_IOMCU_ARC_EVENT_EN6_ADDR(base) ((base) + (0x278))
#define SOC_IOMCU_ARC_EVENT_EN7_ADDR(base) ((base) + (0x27C))
#define SOC_IOMCU_M7_AHB_DBG_INFO1_ADDR(base) ((base) + (0x280))
#define SOC_IOMCU_M7_AHB_DBG_INFO2_ADDR(base) ((base) + (0x284))
#define SOC_IOMCU_M7_AHB_TIME_CFG_ADDR(base) ((base) + (0x288))
#define SOC_IOMCU_M7_AHB_TIMEOUT_ADDR(base) ((base) + (0x28C))
#define SOC_IOMCU_RESERVED_REG0_ADDR(base) ((base) + (0x290))
#define SOC_IOMCU_RESERVED_REG1_ADDR(base) ((base) + (0x294))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_mcu_sel : 2;
        unsigned int clk_mcu_sel_stat : 2;
        unsigned int clk_peri1_sel_spi2 : 2;
        unsigned int clk_peri1_sel_stat_spi2 : 2;
        unsigned int clk_nocbus_sel : 2;
        unsigned int clk_nocbus_sel_stat : 2;
        unsigned int clk_peri0_sel : 2;
        unsigned int clk_peri1_sel : 2;
        unsigned int clk_peri2_sel : 2;
        unsigned int clk_peri3_sel : 2;
        unsigned int clk_peri0_sel_stat : 2;
        unsigned int clk_peri1_sel_stat : 2;
        unsigned int clk_peri2_sel_stat : 2;
        unsigned int clk_peri3_sel_stat : 2;
        unsigned int clk_pll_stable : 1;
        unsigned int clk_fll_stable : 1;
        unsigned int sel_ftimer_clk : 2;
    } reg;
} SOC_IOMCU_CLK_SEL_UNION;
#endif
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_START (0)
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_END (1)
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_stat_START (2)
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_stat_END (3)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_spi2_START (4)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_spi2_END (5)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_spi2_START (6)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_spi2_END (7)
#define SOC_IOMCU_CLK_SEL_clk_nocbus_sel_START (8)
#define SOC_IOMCU_CLK_SEL_clk_nocbus_sel_END (9)
#define SOC_IOMCU_CLK_SEL_clk_nocbus_sel_stat_START (10)
#define SOC_IOMCU_CLK_SEL_clk_nocbus_sel_stat_END (11)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_START (12)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_END (13)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_START (14)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_END (15)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_START (16)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_END (17)
#define SOC_IOMCU_CLK_SEL_clk_peri3_sel_START (18)
#define SOC_IOMCU_CLK_SEL_clk_peri3_sel_END (19)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_stat_START (20)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_stat_END (21)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_START (22)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_END (23)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_stat_START (24)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_stat_END (25)
#define SOC_IOMCU_CLK_SEL_clk_peri3_sel_stat_START (26)
#define SOC_IOMCU_CLK_SEL_clk_peri3_sel_stat_END (27)
#define SOC_IOMCU_CLK_SEL_clk_pll_stable_START (28)
#define SOC_IOMCU_CLK_SEL_clk_pll_stable_END (28)
#define SOC_IOMCU_CLK_SEL_clk_fll_stable_START (29)
#define SOC_IOMCU_CLK_SEL_clk_fll_stable_END (29)
#define SOC_IOMCU_CLK_SEL_sel_ftimer_clk_START (30)
#define SOC_IOMCU_CLK_SEL_sel_ftimer_clk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_mcu0_div : 2;
        unsigned int iomcu_apb_l_div_pre : 2;
        unsigned int iomcu_apb_l_div : 2;
        unsigned int reserved_0 : 1;
        unsigned int iomcu_apb_l_div_en : 1;
        unsigned int iomcu_apb_h_div : 2;
        unsigned int iomcu_mcu1_div : 2;
        unsigned int iomcu_peri0_div : 2;
        unsigned int reserved_1 : 1;
        unsigned int iomcu_peri_ahb_div_en : 1;
        unsigned int iomcu_peri1_div : 2;
        unsigned int iomcu_peri2_div : 2;
        unsigned int iomcu_peri3_div : 2;
        unsigned int reserved_2 : 1;
        unsigned int iomcu_peri_div_en : 1;
        unsigned int iomcu_div : 6;
        unsigned int reserved_3 : 1;
        unsigned int iomcu_div_en : 1;
    } reg;
} SOC_IOMCU_CFG_DIV0_UNION;
#endif
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu0_div_START (0)
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu0_div_END (1)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_pre_START (2)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_pre_END (3)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_START (4)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_END (5)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_en_START (7)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_en_END (7)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_h_div_START (8)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_h_div_END (9)
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu1_div_START (10)
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu1_div_END (11)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri0_div_START (12)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri0_div_END (13)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_ahb_div_en_START (15)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_ahb_div_en_END (15)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri1_div_START (16)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri1_div_END (17)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri2_div_START (18)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri2_div_END (19)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri3_div_START (20)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri3_div_END (21)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_div_en_START (23)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_div_en_END (23)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_START (24)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_END (29)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_en_START (31)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_mcu0_div_nopending : 2;
        unsigned int iomcu_mcu1_div_nopending : 2;
        unsigned int reserved_0 : 3;
        unsigned int iomcu_mcu1_div_en : 1;
        unsigned int ftimer_div0 : 2;
        unsigned int ftimer_div1 : 2;
        unsigned int ftimer_div2 : 2;
        unsigned int reserved_1 : 1;
        unsigned int ftimer_div_en : 1;
        unsigned int iomcu_peri1_div_spi2 : 2;
        unsigned int reserved_2 : 5;
        unsigned int iomcu_peri_div_en_spi2 : 1;
        unsigned int auto_cpu_freq_bypass : 1;
        unsigned int tcp_hclk_div : 2;
        unsigned int tcp_pclk_div : 2;
        unsigned int reserved_3 : 2;
        unsigned int acpu_ctrl_en : 1;
    } reg;
} SOC_IOMCU_CFG_DIV1_UNION;
#endif
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu0_div_nopending_START (0)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu0_div_nopending_END (1)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_nopending_START (2)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_nopending_END (3)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_en_START (7)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_en_END (7)
#define SOC_IOMCU_CFG_DIV1_ftimer_div0_START (8)
#define SOC_IOMCU_CFG_DIV1_ftimer_div0_END (9)
#define SOC_IOMCU_CFG_DIV1_ftimer_div1_START (10)
#define SOC_IOMCU_CFG_DIV1_ftimer_div1_END (11)
#define SOC_IOMCU_CFG_DIV1_ftimer_div2_START (12)
#define SOC_IOMCU_CFG_DIV1_ftimer_div2_END (13)
#define SOC_IOMCU_CFG_DIV1_ftimer_div_en_START (15)
#define SOC_IOMCU_CFG_DIV1_ftimer_div_en_END (15)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri1_div_spi2_START (16)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri1_div_spi2_END (17)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri_div_en_spi2_START (23)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri_div_en_spi2_END (23)
#define SOC_IOMCU_CFG_DIV1_auto_cpu_freq_bypass_START (24)
#define SOC_IOMCU_CFG_DIV1_auto_cpu_freq_bypass_END (24)
#define SOC_IOMCU_CFG_DIV1_tcp_hclk_div_START (25)
#define SOC_IOMCU_CFG_DIV1_tcp_hclk_div_END (26)
#define SOC_IOMCU_CFG_DIV1_tcp_pclk_div_START (27)
#define SOC_IOMCU_CFG_DIV1_tcp_pclk_div_END (28)
#define SOC_IOMCU_CFG_DIV1_acpu_ctrl_en_START (31)
#define SOC_IOMCU_CFG_DIV1_acpu_ctrl_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtc_clk_sel : 1;
        unsigned int rtc_crc_clken : 1;
        unsigned int reserved_0 : 2;
        unsigned int rtc_div_quotient : 11;
        unsigned int reserved_1 : 1;
        unsigned int rtc_div_remainder : 10;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_IOMCU_RTC_CFG_UNION;
#endif
#define SOC_IOMCU_RTC_CFG_rtc_clk_sel_START (0)
#define SOC_IOMCU_RTC_CFG_rtc_clk_sel_END (0)
#define SOC_IOMCU_RTC_CFG_rtc_crc_clken_START (1)
#define SOC_IOMCU_RTC_CFG_rtc_crc_clken_END (1)
#define SOC_IOMCU_RTC_CFG_rtc_div_quotient_START (4)
#define SOC_IOMCU_RTC_CFG_rtc_div_quotient_END (14)
#define SOC_IOMCU_RTC_CFG_rtc_div_remainder_START (16)
#define SOC_IOMCU_RTC_CFG_rtc_div_remainder_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_clken0_0dmac : 1;
        unsigned int iomcu_clken0_lwdt : 1;
        unsigned int iomcu_clken0_2timer : 1;
        unsigned int iomcu_clken0_3i2c0 : 1;
        unsigned int iomcu_clken0_3i2c1 : 1;
        unsigned int iomcu_clken0_5i3c1 : 1;
        unsigned int iomcu_clken0_6gpio0 : 1;
        unsigned int iomcu_clken0_7gpio1 : 1;
        unsigned int iomcu_clken0_8gpio2 : 1;
        unsigned int iomcu_clken0_9gpio3 : 1;
        unsigned int iomcu_clken0_10spi0 : 1;
        unsigned int iomcu_clken0_11uart3 : 1;
        unsigned int iomcu_clken0_12uart7 : 1;
        unsigned int iomcu_clken0_13blpwm : 1;
        unsigned int iomcu_clken0_14fclk_mcu : 1;
        unsigned int iomcu_clken0_15clk_mcu : 1;
        unsigned int iomcu_clken0_16clk_etm : 1;
        unsigned int iomcu_clken0_17aclk_mcu : 1;
        unsigned int iomcu_clken0_18hclk_mcu : 1;
        unsigned int iomcu_clken0_19clk_fll : 1;
        unsigned int iomcu_clken0_20clk_ppll0 : 1;
        unsigned int iomcu_clken0_21clk_dapb : 1;
        unsigned int iomcu_clken0_22clk_atb : 1;
        unsigned int iomcu_clken0_23pclk_rtc : 1;
        unsigned int iomcu_clken0_24clk_ctm : 1;
        unsigned int iomcu_clken0_25clk_tcxo_in : 1;
        unsigned int iomcu_clken0_26i2c5 : 1;
        unsigned int iomcu_clken0_27i3c2 : 1;
        unsigned int iomcu_clken0_28tcm : 1;
        unsigned int iomcu_clken0_29ao_bus : 1;
        unsigned int iomcu_clken0_30spi2 : 1;
        unsigned int iomcu_clken0_31uart8 : 1;
    } reg;
} SOC_IOMCU_CLKEN0_UNION;
#endif
#define SOC_IOMCU_CLKEN0_iomcu_clken0_0dmac_START (0)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_0dmac_END (0)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_lwdt_START (1)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_lwdt_END (1)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_2timer_START (2)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_2timer_END (2)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_3i2c0_START (3)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_3i2c0_END (3)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_3i2c1_START (4)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_3i2c1_END (4)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_5i3c1_START (5)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_5i3c1_END (5)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_6gpio0_START (6)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_6gpio0_END (6)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_7gpio1_START (7)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_7gpio1_END (7)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_8gpio2_START (8)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_8gpio2_END (8)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_9gpio3_START (9)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_9gpio3_END (9)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_10spi0_START (10)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_10spi0_END (10)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_11uart3_START (11)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_11uart3_END (11)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_12uart7_START (12)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_12uart7_END (12)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_13blpwm_START (13)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_13blpwm_END (13)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_14fclk_mcu_START (14)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_14fclk_mcu_END (14)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_15clk_mcu_START (15)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_15clk_mcu_END (15)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_16clk_etm_START (16)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_16clk_etm_END (16)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_17aclk_mcu_START (17)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_17aclk_mcu_END (17)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_18hclk_mcu_START (18)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_18hclk_mcu_END (18)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_19clk_fll_START (19)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_19clk_fll_END (19)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_20clk_ppll0_START (20)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_20clk_ppll0_END (20)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_21clk_dapb_START (21)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_21clk_dapb_END (21)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_22clk_atb_START (22)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_22clk_atb_END (22)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_23pclk_rtc_START (23)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_23pclk_rtc_END (23)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_24clk_ctm_START (24)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_24clk_ctm_END (24)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_25clk_tcxo_in_START (25)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_25clk_tcxo_in_END (25)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_26i2c5_START (26)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_26i2c5_END (26)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_27i3c2_START (27)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_27i3c2_END (27)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_28tcm_START (28)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_28tcm_END (28)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_29ao_bus_START (29)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_29ao_bus_END (29)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_30spi2_START (30)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_30spi2_END (30)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_31uart8_START (31)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_clkdis0_0dmac : 1;
        unsigned int iomcu_clkdis0_lwdt : 1;
        unsigned int iomcu_clkdis0_2timer : 1;
        unsigned int iomcu_clkdis0_3i2c0 : 1;
        unsigned int iomcu_clkdis0_3i2c1 : 1;
        unsigned int iomcu_clkdis0_5i3c1 : 1;
        unsigned int iomcu_clkdis0_6gpio0 : 1;
        unsigned int iomcu_clkdis0_7gpio1 : 1;
        unsigned int iomcu_clkdis0_8gpio2 : 1;
        unsigned int iomcu_clkdis0_9gpio3 : 1;
        unsigned int iomcu_clkdis0_10spi0 : 1;
        unsigned int iomcu_clkdis0_11uart3 : 1;
        unsigned int iomcu_clkdis0_12uart7 : 1;
        unsigned int iomcu_clkdis0_13blpwm : 1;
        unsigned int iomcu_clkdis0_14fclk_mcu : 1;
        unsigned int iomcu_clkdis0_15clk_mcu : 1;
        unsigned int iomcu_clkdis0_16clk_etm : 1;
        unsigned int iomcu_clkdis0_17aclk_mcu : 1;
        unsigned int iomcu_clkdis0_18hclk_mcu : 1;
        unsigned int iomcu_clkdis0_19clk_fll : 1;
        unsigned int iomcu_clkdis0_20clk_ppll0 : 1;
        unsigned int iomcu_clkdis0_21clk_dapb : 1;
        unsigned int iomcu_clkdis0_22clk_atb : 1;
        unsigned int iomcu_clkdis0_23pclk_rtc : 1;
        unsigned int iomcu_clkdis0_24clk_ctm : 1;
        unsigned int iomcu_clkdis0_25clk_tcxo_in : 1;
        unsigned int iomcu_clkdis0_26i2c5 : 1;
        unsigned int iomcu_clkdis0_27i3c2 : 1;
        unsigned int iomcu_clkdis0_28tcm : 1;
        unsigned int iomcu_clkdis0_29ao_bus : 1;
        unsigned int iomcu_clkdis0_30spi2 : 1;
        unsigned int iomcu_clkdis0_31uart8 : 1;
    } reg;
} SOC_IOMCU_CLKDIS0_UNION;
#endif
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_0dmac_START (0)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_0dmac_END (0)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_lwdt_START (1)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_lwdt_END (1)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_2timer_START (2)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_2timer_END (2)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_3i2c0_START (3)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_3i2c0_END (3)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_3i2c1_START (4)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_3i2c1_END (4)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_5i3c1_START (5)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_5i3c1_END (5)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_6gpio0_START (6)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_6gpio0_END (6)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_7gpio1_START (7)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_7gpio1_END (7)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_8gpio2_START (8)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_8gpio2_END (8)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_9gpio3_START (9)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_9gpio3_END (9)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_10spi0_START (10)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_10spi0_END (10)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_11uart3_START (11)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_11uart3_END (11)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_12uart7_START (12)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_12uart7_END (12)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_13blpwm_START (13)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_13blpwm_END (13)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_14fclk_mcu_START (14)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_14fclk_mcu_END (14)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_15clk_mcu_START (15)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_15clk_mcu_END (15)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_16clk_etm_START (16)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_16clk_etm_END (16)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_17aclk_mcu_START (17)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_17aclk_mcu_END (17)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_18hclk_mcu_START (18)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_18hclk_mcu_END (18)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_19clk_fll_START (19)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_19clk_fll_END (19)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_20clk_ppll0_START (20)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_20clk_ppll0_END (20)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_21clk_dapb_START (21)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_21clk_dapb_END (21)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_22clk_atb_START (22)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_22clk_atb_END (22)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_23pclk_rtc_START (23)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_23pclk_rtc_END (23)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_24clk_ctm_START (24)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_24clk_ctm_END (24)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_25clk_tcxo_in_START (25)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_25clk_tcxo_in_END (25)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_26i2c5_START (26)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_26i2c5_END (26)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_27i3c2_START (27)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_27i3c2_END (27)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_28tcm_START (28)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_28tcm_END (28)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_29ao_bus_START (29)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_29ao_bus_END (29)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_30spi2_START (30)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_30spi2_END (30)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_31uart8_START (31)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_clkstat0_0dmac : 1;
        unsigned int iomcu_clkstat0_lwdt : 1;
        unsigned int iomcu_clkstat0_2timer : 1;
        unsigned int iomcu_clkstat0_3i2c0 : 1;
        unsigned int iomcu_clkstat0_3i2c1 : 1;
        unsigned int iomcu_clkstat0_5i3c1 : 1;
        unsigned int iomcu_clkstat0_6gpio0 : 1;
        unsigned int iomcu_clkstat0_7gpio1 : 1;
        unsigned int iomcu_clkstat0_8gpio2 : 1;
        unsigned int iomcu_clkstat0_9gpio3 : 1;
        unsigned int iomcu_clkstat0_10spi0 : 1;
        unsigned int iomcu_clkstat0_11uart3 : 1;
        unsigned int iomcu_clkstat0_12uart7 : 1;
        unsigned int iomcu_clkstat0_13blpwm : 1;
        unsigned int iomcu_clkstat0_14fclk_mcu : 1;
        unsigned int iomcu_clkstat0_15clk_mcu : 1;
        unsigned int iomcu_clkstat0_16clk_etm : 1;
        unsigned int iomcu_clkstat0_17aclk_mcu : 1;
        unsigned int iomcu_clkstat0_18hclk_mcu : 1;
        unsigned int iomcu_clkstat0_19clk_fll : 1;
        unsigned int iomcu_clkstat0_20clk_ppll0 : 1;
        unsigned int iomcu_clkstat0_21clk_dapb : 1;
        unsigned int iomcu_clkstat0_22clk_atb : 1;
        unsigned int iomcu_clkstat0_23pclk_rtc : 1;
        unsigned int iomcu_clkstat0_24clk_ctm : 1;
        unsigned int iomcu_clkstat0_25clk_tcxo_in : 1;
        unsigned int iomcu_clkstat0_26i2c5 : 1;
        unsigned int iomcu_clkstat0_27i3c2 : 1;
        unsigned int iomcu_clkstat0_28tcm : 1;
        unsigned int iomcu_clkstat0_29ao_bus : 1;
        unsigned int iomcu_clkstat0_30spi2 : 1;
        unsigned int iomcu_clkstat0_31uart8 : 1;
    } reg;
} SOC_IOMCU_CLKSTAT0_UNION;
#endif
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_0dmac_START (0)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_0dmac_END (0)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_lwdt_START (1)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_lwdt_END (1)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_2timer_START (2)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_2timer_END (2)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_3i2c0_START (3)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_3i2c0_END (3)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_3i2c1_START (4)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_3i2c1_END (4)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_5i3c1_START (5)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_5i3c1_END (5)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_6gpio0_START (6)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_6gpio0_END (6)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_7gpio1_START (7)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_7gpio1_END (7)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_8gpio2_START (8)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_8gpio2_END (8)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_9gpio3_START (9)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_9gpio3_END (9)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_10spi0_START (10)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_10spi0_END (10)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_11uart3_START (11)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_11uart3_END (11)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_12uart7_START (12)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_12uart7_END (12)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_13blpwm_START (13)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_13blpwm_END (13)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_14fclk_mcu_START (14)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_14fclk_mcu_END (14)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_15clk_mcu_START (15)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_15clk_mcu_END (15)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_16clk_etm_START (16)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_16clk_etm_END (16)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_17aclk_mcu_START (17)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_17aclk_mcu_END (17)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_18hclk_mcu_START (18)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_18hclk_mcu_END (18)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_19clk_fll_START (19)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_19clk_fll_END (19)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_20clk_ppll0_START (20)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_20clk_ppll0_END (20)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_21clk_dapb_START (21)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_21clk_dapb_END (21)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_22clk_atb_START (22)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_22clk_atb_END (22)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_23pclk_rtc_START (23)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_23pclk_rtc_END (23)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_24clk_ctm_START (24)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_24clk_ctm_END (24)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_25clk_tcxo_in_START (25)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_25clk_tcxo_in_END (25)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_26i2c5_START (26)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_26i2c5_END (26)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_27i3c2_START (27)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_27i3c2_END (27)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_28tcm_START (28)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_28tcm_END (28)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_29ao_bus_START (29)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_29ao_bus_END (29)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_30spi2_START (30)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_30spi2_END (30)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_31uart8_START (31)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_rsten0_0dma : 1;
        unsigned int iomcu_rsten0_1wdt : 1;
        unsigned int iomcu_rsten0_2timer : 1;
        unsigned int iomcu_rsten0_3i2c0 : 1;
        unsigned int iomcu_rsten0_3i2c1 : 1;
        unsigned int iomcu_rsten0_5i3c1 : 1;
        unsigned int iomcu_rsten0_6gpio0 : 1;
        unsigned int iomcu_rsten0_7gpio1 : 1;
        unsigned int iomcu_rsten0_8gpio2 : 1;
        unsigned int iomcu_rsten0_9gpio3 : 1;
        unsigned int iomcu_rsten0_10spi0 : 1;
        unsigned int iomcu_rsten0_11uart3 : 1;
        unsigned int iomcu_rsten0_12uart7 : 1;
        unsigned int iomcu_rsten0_13blpwm : 1;
        unsigned int iomcu_rsten0_14mcu_sys : 1;
        unsigned int iomcu_rsten0_15mcu_etm : 1;
        unsigned int iomcu_rsten0_16dmmu : 1;
        unsigned int iomcu_rsten0_17ftimer : 1;
        unsigned int iomcu_rsten0_18i2c5 : 1;
        unsigned int iomcu_rsten0_19tcm : 1;
        unsigned int iomcu_rsten0_20reserved : 1;
        unsigned int iomcu_rsten0_21dapb : 1;
        unsigned int iomcu_rsten0_22atb : 1;
        unsigned int iomcu_rsten0_23rtc : 1;
        unsigned int iomcu_rsten0_24ctm : 1;
        unsigned int iomcu_rsten0_25i2c8 : 1;
        unsigned int iomcu_rsten0_26_p_tcp : 1;
        unsigned int iomcu_rsten0_27i3c2 : 1;
        unsigned int iomcu_rsten0_28i3c3 : 1;
        unsigned int iomcu_rsten0_29i3c : 1;
        unsigned int iomcu_rsten0_30spi2 : 1;
        unsigned int iomcu_rsten0_31uart8 : 1;
    } reg;
} SOC_IOMCU_RSTEN0_UNION;
#endif
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_0dma_START (0)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_0dma_END (0)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_1wdt_START (1)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_1wdt_END (1)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_2timer_START (2)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_2timer_END (2)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c0_START (3)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c0_END (3)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c1_START (4)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c1_END (4)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_5i3c1_START (5)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_5i3c1_END (5)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_6gpio0_START (6)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_6gpio0_END (6)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_7gpio1_START (7)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_7gpio1_END (7)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_8gpio2_START (8)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_8gpio2_END (8)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_9gpio3_START (9)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_9gpio3_END (9)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_10spi0_START (10)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_10spi0_END (10)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_11uart3_START (11)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_11uart3_END (11)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_12uart7_START (12)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_12uart7_END (12)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_13blpwm_START (13)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_13blpwm_END (13)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_14mcu_sys_START (14)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_14mcu_sys_END (14)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_15mcu_etm_START (15)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_15mcu_etm_END (15)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_16dmmu_START (16)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_16dmmu_END (16)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_17ftimer_START (17)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_17ftimer_END (17)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_18i2c5_START (18)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_18i2c5_END (18)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_19tcm_START (19)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_19tcm_END (19)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_20reserved_START (20)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_20reserved_END (20)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_21dapb_START (21)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_21dapb_END (21)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_22atb_START (22)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_22atb_END (22)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_23rtc_START (23)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_23rtc_END (23)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_24ctm_START (24)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_24ctm_END (24)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_25i2c8_START (25)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_25i2c8_END (25)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_26_p_tcp_START (26)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_26_p_tcp_END (26)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_27i3c2_START (27)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_27i3c2_END (27)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_28i3c3_START (28)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_28i3c3_END (28)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_29i3c_START (29)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_29i3c_END (29)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_30spi2_START (30)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_30spi2_END (30)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_31uart8_START (31)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_rstdis0_0dma : 1;
        unsigned int iomcu_rstdis0_1wdt : 1;
        unsigned int iomcu_rstdis0_2timer : 1;
        unsigned int iomcu_rstdis0_3i2c0 : 1;
        unsigned int iomcu_rstdis0_3i2c1 : 1;
        unsigned int iomcu_rstdis0_5i3c1 : 1;
        unsigned int iomcu_rstdis0_6gpio0 : 1;
        unsigned int iomcu_rstdis0_7gpio1 : 1;
        unsigned int iomcu_rstdis0_8gpio2 : 1;
        unsigned int iomcu_rstdis0_9gpio3 : 1;
        unsigned int iomcu_rstdis0_10spi0 : 1;
        unsigned int iomcu_rstdis0_11uart3 : 1;
        unsigned int iomcu_rstdis0_12uart7 : 1;
        unsigned int iomcu_rstdis0_13blpwm : 1;
        unsigned int iomcu_rstdis0_14mcu_sys : 1;
        unsigned int iomcu_rstdis0_15mcu_etm : 1;
        unsigned int iomcu_rstdis0_16dmmu : 1;
        unsigned int iomcu_rstdis0_17ftimer : 1;
        unsigned int iomcu_rstdis0_18i2c5 : 1;
        unsigned int iomcu_rstdis0_19tcm : 1;
        unsigned int iomcu_rstdis0_20reserved : 1;
        unsigned int iomcu_rstdis0_21dapb : 1;
        unsigned int iomcu_rstdis0_22atb : 1;
        unsigned int iomcu_rstdis0_23rtc : 1;
        unsigned int iomcu_rstdis0_24ctm : 1;
        unsigned int iomcu_rstdis0_25i2c8 : 1;
        unsigned int iomcu_rstdis0_26_p_tcp : 1;
        unsigned int iomcu_rstdis0_27i3c2 : 1;
        unsigned int iomcu_rstdis0_28i3c3 : 1;
        unsigned int iomcu_rstdis0_29i3c : 1;
        unsigned int iomcu_rstdis0_30spi2 : 1;
        unsigned int iomcu_rstdis0_31uart8 : 1;
    } reg;
} SOC_IOMCU_RSTDIS0_UNION;
#endif
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_0dma_START (0)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_0dma_END (0)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_1wdt_START (1)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_1wdt_END (1)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_2timer_START (2)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_2timer_END (2)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c0_START (3)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c0_END (3)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c1_START (4)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c1_END (4)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_5i3c1_START (5)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_5i3c1_END (5)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_6gpio0_START (6)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_6gpio0_END (6)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_7gpio1_START (7)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_7gpio1_END (7)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_8gpio2_START (8)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_8gpio2_END (8)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_9gpio3_START (9)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_9gpio3_END (9)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_10spi0_START (10)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_10spi0_END (10)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_11uart3_START (11)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_11uart3_END (11)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_12uart7_START (12)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_12uart7_END (12)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_13blpwm_START (13)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_13blpwm_END (13)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_14mcu_sys_START (14)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_14mcu_sys_END (14)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_15mcu_etm_START (15)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_15mcu_etm_END (15)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_16dmmu_START (16)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_16dmmu_END (16)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_17ftimer_START (17)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_17ftimer_END (17)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_18i2c5_START (18)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_18i2c5_END (18)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_19tcm_START (19)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_19tcm_END (19)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_20reserved_START (20)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_20reserved_END (20)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_21dapb_START (21)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_21dapb_END (21)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_22atb_START (22)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_22atb_END (22)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_23rtc_START (23)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_23rtc_END (23)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_24ctm_START (24)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_24ctm_END (24)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_25i2c8_START (25)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_25i2c8_END (25)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_26_p_tcp_START (26)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_26_p_tcp_END (26)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_27i3c2_START (27)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_27i3c2_END (27)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_28i3c3_START (28)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_28i3c3_END (28)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_29i3c_START (29)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_29i3c_END (29)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_30spi2_START (30)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_30spi2_END (30)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_31uart8_START (31)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_rststats0_0dma : 1;
        unsigned int iomcu_rststats0_1wdt : 1;
        unsigned int iomcu_rststats0_2timer : 1;
        unsigned int iomcu_rststats0_3i2c0 : 1;
        unsigned int iomcu_rststats0_3i2c1 : 1;
        unsigned int iomcu_rststats0_5i3c1 : 1;
        unsigned int iomcu_rststats0_6gpio0 : 1;
        unsigned int iomcu_rststats0_7gpio1 : 1;
        unsigned int iomcu_rststats0_8gpio2 : 1;
        unsigned int iomcu_rststats0_9gpio3 : 1;
        unsigned int iomcu_rststats0_10spi0 : 1;
        unsigned int iomcu_rststats0_11uart3 : 1;
        unsigned int iomcu_rststats0_12uart7 : 1;
        unsigned int iomcu_rststats0_13blpwm : 1;
        unsigned int iomcu_rststats0_14mcu_sys : 1;
        unsigned int iomcu_rststats0_15mcu_etm : 1;
        unsigned int iomcu_rststats0_16dmmu : 1;
        unsigned int iomcu_rststats0_17ftimer : 1;
        unsigned int iomcu_rststats0_18i2c5 : 1;
        unsigned int iomcu_rststats0_19tcm : 1;
        unsigned int iomcu_rststats0_20reserved : 1;
        unsigned int iomcu_rststats0_21dapb : 1;
        unsigned int iomcu_rststats0_22atb : 1;
        unsigned int iomcu_rststats0_23rtc : 1;
        unsigned int iomcu_rststats0_24ctm : 1;
        unsigned int iomcu_rststats0_25i2c8 : 1;
        unsigned int iomcu_rststats0_26_p_tcp : 1;
        unsigned int iomcu_rststats0_27i3c2 : 1;
        unsigned int iomcu_rststats0_28i3c3 : 1;
        unsigned int iomcu_rststats0_29i3c : 1;
        unsigned int iomcu_rststats0_30spi2 : 1;
        unsigned int iomcu_rststat0_31uart8 : 1;
    } reg;
} SOC_IOMCU_RSTSTAT0_UNION;
#endif
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_0dma_START (0)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_0dma_END (0)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_1wdt_START (1)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_1wdt_END (1)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_2timer_START (2)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_2timer_END (2)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c0_START (3)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c0_END (3)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c1_START (4)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c1_END (4)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_5i3c1_START (5)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_5i3c1_END (5)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_6gpio0_START (6)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_6gpio0_END (6)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_7gpio1_START (7)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_7gpio1_END (7)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_8gpio2_START (8)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_8gpio2_END (8)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_9gpio3_START (9)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_9gpio3_END (9)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_10spi0_START (10)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_10spi0_END (10)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_11uart3_START (11)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_11uart3_END (11)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_12uart7_START (12)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_12uart7_END (12)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_13blpwm_START (13)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_13blpwm_END (13)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_14mcu_sys_START (14)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_14mcu_sys_END (14)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_15mcu_etm_START (15)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_15mcu_etm_END (15)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_16dmmu_START (16)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_16dmmu_END (16)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_17ftimer_START (17)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_17ftimer_END (17)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_18i2c5_START (18)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_18i2c5_END (18)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_19tcm_START (19)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_19tcm_END (19)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_20reserved_START (20)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_20reserved_END (20)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_21dapb_START (21)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_21dapb_END (21)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_22atb_START (22)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_22atb_END (22)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_23rtc_START (23)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_23rtc_END (23)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_24ctm_START (24)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_24ctm_END (24)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_25i2c8_START (25)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_25i2c8_END (25)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_26_p_tcp_START (26)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_26_p_tcp_END (26)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_27i3c2_START (27)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_27i3c2_END (27)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_28i3c3_START (28)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_28i3c3_END (28)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_29i3c_START (29)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_29i3c_END (29)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_30spi2_START (30)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_30spi2_END (30)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststat0_31uart8_START (31)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststat0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_wait : 1;
        unsigned int hclken_sleeping_bypass : 1;
        unsigned int hifi_dtcm_remap_bypass : 1;
        unsigned int ocram_remap_bypass : 1;
        unsigned int cpu_initvtor : 25;
        unsigned int ahbs_ready_error_clr : 1;
        unsigned int cfg_bigend : 1;
        unsigned int cpu_iadbgprot : 1;
    } reg;
} SOC_IOMCU_M7_CFG0_UNION;
#endif
#define SOC_IOMCU_M7_CFG0_cpu_wait_START (0)
#define SOC_IOMCU_M7_CFG0_cpu_wait_END (0)
#define SOC_IOMCU_M7_CFG0_hclken_sleeping_bypass_START (1)
#define SOC_IOMCU_M7_CFG0_hclken_sleeping_bypass_END (1)
#define SOC_IOMCU_M7_CFG0_hifi_dtcm_remap_bypass_START (2)
#define SOC_IOMCU_M7_CFG0_hifi_dtcm_remap_bypass_END (2)
#define SOC_IOMCU_M7_CFG0_ocram_remap_bypass_START (3)
#define SOC_IOMCU_M7_CFG0_ocram_remap_bypass_END (3)
#define SOC_IOMCU_M7_CFG0_cpu_initvtor_START (4)
#define SOC_IOMCU_M7_CFG0_cpu_initvtor_END (28)
#define SOC_IOMCU_M7_CFG0_ahbs_ready_error_clr_START (29)
#define SOC_IOMCU_M7_CFG0_ahbs_ready_error_clr_END (29)
#define SOC_IOMCU_M7_CFG0_cfg_bigend_START (30)
#define SOC_IOMCU_M7_CFG0_cfg_bigend_END (30)
#define SOC_IOMCU_M7_CFG0_cpu_iadbgprot_START (31)
#define SOC_IOMCU_M7_CFG0_cpu_iadbgprot_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfgstcalib_cycclecnt : 24;
        unsigned int cfgstcalib_precision : 1;
        unsigned int cfgstcalib_ticken : 1;
        unsigned int halt_bypass : 1;
        unsigned int hack_remap_bypass : 1;
        unsigned int mmbuf_remap_bypass : 1;
        unsigned int aclken_sleeping_bypass : 1;
        unsigned int deepsleeping_bypass : 1;
        unsigned int clken_sleeping_bypass : 1;
    } reg;
} SOC_IOMCU_M7_CFG1_UNION;
#endif
#define SOC_IOMCU_M7_CFG1_cfgstcalib_cycclecnt_START (0)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_cycclecnt_END (23)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_precision_START (24)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_precision_END (24)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_ticken_START (25)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_ticken_END (25)
#define SOC_IOMCU_M7_CFG1_halt_bypass_START (26)
#define SOC_IOMCU_M7_CFG1_halt_bypass_END (26)
#define SOC_IOMCU_M7_CFG1_hack_remap_bypass_START (27)
#define SOC_IOMCU_M7_CFG1_hack_remap_bypass_END (27)
#define SOC_IOMCU_M7_CFG1_mmbuf_remap_bypass_START (28)
#define SOC_IOMCU_M7_CFG1_mmbuf_remap_bypass_END (28)
#define SOC_IOMCU_M7_CFG1_aclken_sleeping_bypass_START (29)
#define SOC_IOMCU_M7_CFG1_aclken_sleeping_bypass_END (29)
#define SOC_IOMCU_M7_CFG1_deepsleeping_bypass_START (30)
#define SOC_IOMCU_M7_CFG1_deepsleeping_bypass_END (30)
#define SOC_IOMCU_M7_CFG1_clken_sleeping_bypass_START (31)
#define SOC_IOMCU_M7_CFG1_clken_sleeping_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m7_iaddr_stat : 29;
        unsigned int ahbs_ready_error_stat : 1;
        unsigned int cpu_halt_stat : 1;
        unsigned int cpu_lockup : 1;
    } reg;
} SOC_IOMCU_M7_STAT0_UNION;
#endif
#define SOC_IOMCU_M7_STAT0_m7_iaddr_stat_START (0)
#define SOC_IOMCU_M7_STAT0_m7_iaddr_stat_END (28)
#define SOC_IOMCU_M7_STAT0_ahbs_ready_error_stat_START (29)
#define SOC_IOMCU_M7_STAT0_ahbs_ready_error_stat_END (29)
#define SOC_IOMCU_M7_STAT0_cpu_halt_stat_START (30)
#define SOC_IOMCU_M7_STAT0_cpu_halt_stat_END (30)
#define SOC_IOMCU_M7_STAT0_cpu_lockup_START (31)
#define SOC_IOMCU_M7_STAT0_cpu_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m7_sleeping_stat : 1;
        unsigned int m7_deepsleeping_stat : 1;
        unsigned int m7_ahbs_ready_stat : 1;
        unsigned int m7_tcp_ahb_wr_bypass : 1;
        unsigned int m7_tcp_ahb_rd_bypass : 1;
        unsigned int m7_dma_wr_bypass : 1;
        unsigned int m7_dma_rd_bypass : 1;
        unsigned int m7_ahb_wr_bypass : 1;
        unsigned int m7_ahb_rd_bypass : 1;
        unsigned int m7_sc_stat : 9;
        unsigned int m7_etmpwrupreq : 1;
        unsigned int check_enable : 1;
        unsigned int sys_sleep_mode_r : 3;
        unsigned int nmi_ack : 1;
        unsigned int check_addr_clr : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_IOMCU_M7_STAT1_UNION;
#endif
#define SOC_IOMCU_M7_STAT1_m7_sleeping_stat_START (0)
#define SOC_IOMCU_M7_STAT1_m7_sleeping_stat_END (0)
#define SOC_IOMCU_M7_STAT1_m7_deepsleeping_stat_START (1)
#define SOC_IOMCU_M7_STAT1_m7_deepsleeping_stat_END (1)
#define SOC_IOMCU_M7_STAT1_m7_ahbs_ready_stat_START (2)
#define SOC_IOMCU_M7_STAT1_m7_ahbs_ready_stat_END (2)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_wr_bypass_START (3)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_wr_bypass_END (3)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_rd_bypass_START (4)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_rd_bypass_END (4)
#define SOC_IOMCU_M7_STAT1_m7_dma_wr_bypass_START (5)
#define SOC_IOMCU_M7_STAT1_m7_dma_wr_bypass_END (5)
#define SOC_IOMCU_M7_STAT1_m7_dma_rd_bypass_START (6)
#define SOC_IOMCU_M7_STAT1_m7_dma_rd_bypass_END (6)
#define SOC_IOMCU_M7_STAT1_m7_ahb_wr_bypass_START (7)
#define SOC_IOMCU_M7_STAT1_m7_ahb_wr_bypass_END (7)
#define SOC_IOMCU_M7_STAT1_m7_ahb_rd_bypass_START (8)
#define SOC_IOMCU_M7_STAT1_m7_ahb_rd_bypass_END (8)
#define SOC_IOMCU_M7_STAT1_m7_sc_stat_START (9)
#define SOC_IOMCU_M7_STAT1_m7_sc_stat_END (17)
#define SOC_IOMCU_M7_STAT1_m7_etmpwrupreq_START (18)
#define SOC_IOMCU_M7_STAT1_m7_etmpwrupreq_END (18)
#define SOC_IOMCU_M7_STAT1_check_enable_START (19)
#define SOC_IOMCU_M7_STAT1_check_enable_END (19)
#define SOC_IOMCU_M7_STAT1_sys_sleep_mode_r_START (20)
#define SOC_IOMCU_M7_STAT1_sys_sleep_mode_r_END (22)
#define SOC_IOMCU_M7_STAT1_nmi_ack_START (23)
#define SOC_IOMCU_M7_STAT1_nmi_ack_END (23)
#define SOC_IOMCU_M7_STAT1_check_addr_clr_START (24)
#define SOC_IOMCU_M7_STAT1_check_addr_clr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_access_window : 32;
    } reg;
} SOC_IOMCU_DDR_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_DDR_ACCESS_WINDOW_ddr_access_window_START (0)
#define SOC_IOMCU_DDR_ACCESS_WINDOW_ddr_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mmbuf_access_window : 32;
    } reg;
} SOC_IOMCU_MMBUF_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_mmbuf_access_window_START (0)
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_mmbuf_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hack_access_window : 32;
    } reg;
} SOC_IOMCU_HACK_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_HACK_ACCESS_WINDOW_hack_access_window_START (0)
#define SOC_IOMCU_HACK_ACCESS_WINDOW_hack_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass_for_watchdog : 1;
        unsigned int bypass_for_timer : 1;
        unsigned int bypass_for_spi : 1;
        unsigned int bypass_for_gpio0 : 1;
        unsigned int bypass_for_gpio1 : 1;
        unsigned int bypass_for_gpio2 : 1;
        unsigned int bypass_for_gpio3 : 1;
        unsigned int bypass_for_i2c0 : 1;
        unsigned int bypass_for_i2c1 : 1;
        unsigned int bypass_for_i3c1 : 1;
        unsigned int bypass_for_uart3 : 1;
        unsigned int bypass_for_blpwm : 1;
        unsigned int bypass_for_uart7 : 1;
        unsigned int bypass_for_dma : 1;
        unsigned int bypass_for_rtc : 1;
        unsigned int bypass_for_i3c2 : 1;
        unsigned int bypass_for_uart8 : 1;
        unsigned int bypass_for_spi2 : 1;
        unsigned int bypass_for_i2c5 : 1;
        unsigned int bypass_for_dmmu : 1;
        unsigned int bypass_for_ftimer : 1;
        unsigned int bypass_for_i3c : 1;
        unsigned int bypass_for_tcp : 1;
        unsigned int bypass_for_i3c3 : 1;
        unsigned int bypass_for_tcm : 1;
        unsigned int bypass_for_i2c8 : 1;
        unsigned int reserved : 6;
    } reg;
} SOC_IOMCU_DLOCK_BYPASS_UNION;
#endif
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_watchdog_START (0)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_watchdog_END (0)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_timer_START (1)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_timer_END (1)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi_START (2)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi_END (2)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio0_START (3)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio0_END (3)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio1_START (4)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio1_END (4)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio2_START (5)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio2_END (5)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio3_START (6)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio3_END (6)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c0_START (7)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c0_END (7)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c1_START (8)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c1_END (8)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c1_START (9)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c1_END (9)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart3_START (10)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart3_END (10)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_blpwm_START (11)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_blpwm_END (11)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart7_START (12)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart7_END (12)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dma_START (13)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dma_END (13)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_rtc_START (14)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_rtc_END (14)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c2_START (15)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c2_END (15)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart8_START (16)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart8_END (16)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi2_START (17)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi2_END (17)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c5_START (18)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c5_END (18)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dmmu_START (19)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dmmu_END (19)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_ftimer_START (20)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_ftimer_END (20)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c_START (21)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c_END (21)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_tcp_START (22)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_tcp_END (22)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c3_START (23)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c3_END (23)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_tcm_START (24)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_tcm_END (24)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c8_START (25)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c8_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_bank0 : 3;
        unsigned int mem_ctrl_bank1 : 3;
        unsigned int mem_ctrl_bank2 : 3;
        unsigned int mem_ctrl_bank3 : 3;
        unsigned int mem_ctrl_bank4 : 3;
        unsigned int mem_ctrl_bank5 : 3;
        unsigned int mem_ctrl_bank6 : 3;
        unsigned int mem_ctrl_icache : 3;
        unsigned int mem_ctrl_dcache : 3;
        unsigned int reserved_0 : 1;
        unsigned int mem_ctrl_map_table : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_IOMCU_MEM_CTRL_PGT_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank0_START (0)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank0_END (2)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank1_START (3)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank1_END (5)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank2_START (6)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank2_END (8)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank3_START (9)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank3_END (11)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank4_START (12)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank4_END (14)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank5_START (15)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank5_END (17)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank6_START (18)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank6_END (20)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_icache_START (21)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_icache_END (23)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_dcache_START (24)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_dcache_END (26)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_map_table_START (28)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_map_table_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int mem_ctrl_bank24 : 3;
        unsigned int mem_ctrl_bank7 : 3;
        unsigned int mem_ctrl_bank8 : 3;
        unsigned int mem_ctrl_bank9 : 3;
        unsigned int mem_ctrl_bank10 : 3;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_IOMCU_MEM_CTRL_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank24_START (12)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank24_END (14)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank7_START (15)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank7_END (17)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank8_START (18)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank8_END (20)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank9_START (21)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank9_END (23)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank10_START (24)
#define SOC_IOMCU_MEM_CTRL_mem_ctrl_bank10_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sys_stat : 4;
        unsigned int xtal_ready : 2;
        unsigned int gt_clk_mmbuf : 1;
        unsigned int aximux_dlock_wr : 1;
        unsigned int aximux_dlock_id : 4;
        unsigned int aximux_dlock_slv : 1;
        unsigned int aximux_dlock_mst : 1;
        unsigned int tcpc_busy_stat : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_IOMCU_SYS_STAT_UNION;
#endif
#define SOC_IOMCU_SYS_STAT_sys_stat_START (0)
#define SOC_IOMCU_SYS_STAT_sys_stat_END (3)
#define SOC_IOMCU_SYS_STAT_xtal_ready_START (4)
#define SOC_IOMCU_SYS_STAT_xtal_ready_END (5)
#define SOC_IOMCU_SYS_STAT_gt_clk_mmbuf_START (6)
#define SOC_IOMCU_SYS_STAT_gt_clk_mmbuf_END (6)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_wr_START (7)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_wr_END (7)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_id_START (8)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_id_END (11)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_slv_START (12)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_slv_END (12)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_mst_START (13)
#define SOC_IOMCU_SYS_STAT_aximux_dlock_mst_END (13)
#define SOC_IOMCU_SYS_STAT_tcpc_busy_stat_START (14)
#define SOC_IOMCU_SYS_STAT_tcpc_busy_stat_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sleep_mode : 1;
        unsigned int ppll0_en : 1;
        unsigned int fll_en : 1;
        unsigned int auto_cksel_dmmu : 1;
        unsigned int auto_cksel_iomcu : 1;
        unsigned int aximux_m7_priority : 1;
        unsigned int iomcu_sclk_sw2fll_req : 1;
        unsigned int iomcu_fll_ctrl : 5;
        unsigned int reserved_0 : 1;
        unsigned int pclkdbg_en : 1;
        unsigned int txev : 1;
        unsigned int req_out_en : 1;
        unsigned int atclken : 1;
        unsigned int iomcu_logic_low_req : 1;
        unsigned int iomcu_sram_low_req : 1;
        unsigned int i3c0_sel : 1;
        unsigned int i3c1_sel : 1;
        unsigned int i3c3_sel : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_IOMCU_SYS_CONFIG_UNION;
#endif
#define SOC_IOMCU_SYS_CONFIG_sleep_mode_START (0)
#define SOC_IOMCU_SYS_CONFIG_sleep_mode_END (0)
#define SOC_IOMCU_SYS_CONFIG_ppll0_en_START (1)
#define SOC_IOMCU_SYS_CONFIG_ppll0_en_END (1)
#define SOC_IOMCU_SYS_CONFIG_fll_en_START (2)
#define SOC_IOMCU_SYS_CONFIG_fll_en_END (2)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_dmmu_START (3)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_dmmu_END (3)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_iomcu_START (4)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_iomcu_END (4)
#define SOC_IOMCU_SYS_CONFIG_aximux_m7_priority_START (5)
#define SOC_IOMCU_SYS_CONFIG_aximux_m7_priority_END (5)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sclk_sw2fll_req_START (6)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sclk_sw2fll_req_END (6)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_ctrl_START (7)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_ctrl_END (11)
#define SOC_IOMCU_SYS_CONFIG_pclkdbg_en_START (13)
#define SOC_IOMCU_SYS_CONFIG_pclkdbg_en_END (13)
#define SOC_IOMCU_SYS_CONFIG_txev_START (14)
#define SOC_IOMCU_SYS_CONFIG_txev_END (14)
#define SOC_IOMCU_SYS_CONFIG_req_out_en_START (15)
#define SOC_IOMCU_SYS_CONFIG_req_out_en_END (15)
#define SOC_IOMCU_SYS_CONFIG_atclken_START (16)
#define SOC_IOMCU_SYS_CONFIG_atclken_END (16)
#define SOC_IOMCU_SYS_CONFIG_iomcu_logic_low_req_START (17)
#define SOC_IOMCU_SYS_CONFIG_iomcu_logic_low_req_END (17)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sram_low_req_START (18)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sram_low_req_END (18)
#define SOC_IOMCU_SYS_CONFIG_i3c0_sel_START (19)
#define SOC_IOMCU_SYS_CONFIG_i3c0_sel_END (19)
#define SOC_IOMCU_SYS_CONFIG_i3c1_sel_START (20)
#define SOC_IOMCU_SYS_CONFIG_i3c1_sel_END (20)
#define SOC_IOMCU_SYS_CONFIG_i3c3_sel_START (21)
#define SOC_IOMCU_SYS_CONFIG_i3c3_sel_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wakeup_en : 1;
        unsigned int soft_int_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IOMCU_WAKEUP_EN_UNION;
#endif
#define SOC_IOMCU_WAKEUP_EN_wakeup_en_START (0)
#define SOC_IOMCU_WAKEUP_EN_wakeup_en_END (0)
#define SOC_IOMCU_WAKEUP_EN_soft_int_en_START (1)
#define SOC_IOMCU_WAKEUP_EN_soft_int_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wakeup_clr : 1;
        unsigned int soft_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IOMCU_WAKEUP_CLR_UNION;
#endif
#define SOC_IOMCU_WAKEUP_CLR_wakeup_clr_START (0)
#define SOC_IOMCU_WAKEUP_CLR_wakeup_clr_END (0)
#define SOC_IOMCU_WAKEUP_CLR_soft_int_clr_START (1)
#define SOC_IOMCU_WAKEUP_CLR_soft_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wakeup_stat : 1;
        unsigned int soft_int_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IOMCU_WAKEUP_STAT_UNION;
#endif
#define SOC_IOMCU_WAKEUP_STAT_wakeup_stat_START (0)
#define SOC_IOMCU_WAKEUP_STAT_wakeup_stat_END (0)
#define SOC_IOMCU_WAKEUP_STAT_soft_int_stat_START (1)
#define SOC_IOMCU_WAKEUP_STAT_soft_int_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpio0_int_raw : 1;
        unsigned int gpio1_int_raw : 1;
        unsigned int gpio2_int_raw : 1;
        unsigned int gpio3_int_raw : 1;
        unsigned int timer1_int_raw : 1;
        unsigned int timer2_int_raw : 1;
        unsigned int soft_int_raw : 1;
        unsigned int dss_rise_int_raw : 1;
        unsigned int dss_down_int_raw : 1;
        unsigned int sys_wakeup_int_raw : 1;
        unsigned int sys_sleep_int_raw : 1;
        unsigned int reserved_0 : 1;
        unsigned int ftimer_int1_raw : 1;
        unsigned int ftimer_int2_raw : 1;
        unsigned int intr_wakeup_swing_enter_req_raw : 1;
        unsigned int intr_wakeup_swing_exit_req_raw : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_IOMCU_COMB_INT_RAW_UNION;
#endif
#define SOC_IOMCU_COMB_INT_RAW_gpio0_int_raw_START (0)
#define SOC_IOMCU_COMB_INT_RAW_gpio0_int_raw_END (0)
#define SOC_IOMCU_COMB_INT_RAW_gpio1_int_raw_START (1)
#define SOC_IOMCU_COMB_INT_RAW_gpio1_int_raw_END (1)
#define SOC_IOMCU_COMB_INT_RAW_gpio2_int_raw_START (2)
#define SOC_IOMCU_COMB_INT_RAW_gpio2_int_raw_END (2)
#define SOC_IOMCU_COMB_INT_RAW_gpio3_int_raw_START (3)
#define SOC_IOMCU_COMB_INT_RAW_gpio3_int_raw_END (3)
#define SOC_IOMCU_COMB_INT_RAW_timer1_int_raw_START (4)
#define SOC_IOMCU_COMB_INT_RAW_timer1_int_raw_END (4)
#define SOC_IOMCU_COMB_INT_RAW_timer2_int_raw_START (5)
#define SOC_IOMCU_COMB_INT_RAW_timer2_int_raw_END (5)
#define SOC_IOMCU_COMB_INT_RAW_soft_int_raw_START (6)
#define SOC_IOMCU_COMB_INT_RAW_soft_int_raw_END (6)
#define SOC_IOMCU_COMB_INT_RAW_dss_rise_int_raw_START (7)
#define SOC_IOMCU_COMB_INT_RAW_dss_rise_int_raw_END (7)
#define SOC_IOMCU_COMB_INT_RAW_dss_down_int_raw_START (8)
#define SOC_IOMCU_COMB_INT_RAW_dss_down_int_raw_END (8)
#define SOC_IOMCU_COMB_INT_RAW_sys_wakeup_int_raw_START (9)
#define SOC_IOMCU_COMB_INT_RAW_sys_wakeup_int_raw_END (9)
#define SOC_IOMCU_COMB_INT_RAW_sys_sleep_int_raw_START (10)
#define SOC_IOMCU_COMB_INT_RAW_sys_sleep_int_raw_END (10)
#define SOC_IOMCU_COMB_INT_RAW_ftimer_int1_raw_START (12)
#define SOC_IOMCU_COMB_INT_RAW_ftimer_int1_raw_END (12)
#define SOC_IOMCU_COMB_INT_RAW_ftimer_int2_raw_START (13)
#define SOC_IOMCU_COMB_INT_RAW_ftimer_int2_raw_END (13)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_enter_req_raw_START (14)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_enter_req_raw_END (14)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_exit_req_raw_START (15)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_exit_req_raw_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpio0_int_msk : 1;
        unsigned int gpio1_int_msk : 1;
        unsigned int gpio2_int_msk : 1;
        unsigned int gpio3_int_msk : 1;
        unsigned int timer1_int_msk : 1;
        unsigned int timer2_int_msk : 1;
        unsigned int soft_int_msk : 1;
        unsigned int dss_rise_int_msk : 1;
        unsigned int dss_down_int_msk : 1;
        unsigned int dss_rise_int_clr : 1;
        unsigned int dss_down_int_clr : 1;
        unsigned int sys_wakeup_int_msk : 1;
        unsigned int sys_wakeup_int_clr : 1;
        unsigned int sys_sleep_int_msk : 1;
        unsigned int sys_sleep_int_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ftimer_int2_mask : 1;
        unsigned int ftimer_int1_mask : 1;
        unsigned int intr_wakeup_swing_enter_req_en : 1;
        unsigned int intr_wakeup_swing_exit_req_en : 1;
        unsigned int intr_wakeup_swing_enter_req_clr : 1;
        unsigned int intr_wakeup_swing_exit_req_clr : 1;
        unsigned int intr_wakeup_swing_enter_req_msk : 1;
        unsigned int intr_wakeup_swing_exit_req_msk : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_IOMCU_COMB_INT_MSK_UNION;
#endif
#define SOC_IOMCU_COMB_INT_MSK_gpio0_int_msk_START (0)
#define SOC_IOMCU_COMB_INT_MSK_gpio0_int_msk_END (0)
#define SOC_IOMCU_COMB_INT_MSK_gpio1_int_msk_START (1)
#define SOC_IOMCU_COMB_INT_MSK_gpio1_int_msk_END (1)
#define SOC_IOMCU_COMB_INT_MSK_gpio2_int_msk_START (2)
#define SOC_IOMCU_COMB_INT_MSK_gpio2_int_msk_END (2)
#define SOC_IOMCU_COMB_INT_MSK_gpio3_int_msk_START (3)
#define SOC_IOMCU_COMB_INT_MSK_gpio3_int_msk_END (3)
#define SOC_IOMCU_COMB_INT_MSK_timer1_int_msk_START (4)
#define SOC_IOMCU_COMB_INT_MSK_timer1_int_msk_END (4)
#define SOC_IOMCU_COMB_INT_MSK_timer2_int_msk_START (5)
#define SOC_IOMCU_COMB_INT_MSK_timer2_int_msk_END (5)
#define SOC_IOMCU_COMB_INT_MSK_soft_int_msk_START (6)
#define SOC_IOMCU_COMB_INT_MSK_soft_int_msk_END (6)
#define SOC_IOMCU_COMB_INT_MSK_dss_rise_int_msk_START (7)
#define SOC_IOMCU_COMB_INT_MSK_dss_rise_int_msk_END (7)
#define SOC_IOMCU_COMB_INT_MSK_dss_down_int_msk_START (8)
#define SOC_IOMCU_COMB_INT_MSK_dss_down_int_msk_END (8)
#define SOC_IOMCU_COMB_INT_MSK_dss_rise_int_clr_START (9)
#define SOC_IOMCU_COMB_INT_MSK_dss_rise_int_clr_END (9)
#define SOC_IOMCU_COMB_INT_MSK_dss_down_int_clr_START (10)
#define SOC_IOMCU_COMB_INT_MSK_dss_down_int_clr_END (10)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_msk_START (11)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_msk_END (11)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_clr_START (12)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_clr_END (12)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_msk_START (13)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_msk_END (13)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_clr_START (14)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_clr_END (14)
#define SOC_IOMCU_COMB_INT_MSK_ftimer_int2_mask_START (17)
#define SOC_IOMCU_COMB_INT_MSK_ftimer_int2_mask_END (17)
#define SOC_IOMCU_COMB_INT_MSK_ftimer_int1_mask_START (18)
#define SOC_IOMCU_COMB_INT_MSK_ftimer_int1_mask_END (18)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_en_START (19)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_en_END (19)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_en_START (20)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_en_END (20)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_clr_START (21)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_clr_END (21)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_clr_START (22)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_clr_END (22)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_msk_START (23)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_msk_END (23)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_msk_START (24)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_msk_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpio0_int_mskd : 1;
        unsigned int gpio1_int_mskd : 1;
        unsigned int gpio2_int_mskd : 1;
        unsigned int gpio3_int_mskd : 1;
        unsigned int timer1_int_mskd : 1;
        unsigned int timer2_int_mskd : 1;
        unsigned int soft_int_mskd : 1;
        unsigned int dss_rise_int_mskd : 1;
        unsigned int dss_down_int_mskd : 1;
        unsigned int sys_wakeup_int_mskd : 1;
        unsigned int sys_sleep_int_mskd : 1;
        unsigned int reserved_0 : 1;
        unsigned int ftimer_int1_maskd : 1;
        unsigned int ftimer_int2_maskd : 1;
        unsigned int intr_wakeup_swing_enter_req_mskd : 1;
        unsigned int intr_wakeup_swing_exit_req_mskd : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_IOMCU_COMB_INT_STAT_UNION;
#endif
#define SOC_IOMCU_COMB_INT_STAT_gpio0_int_mskd_START (0)
#define SOC_IOMCU_COMB_INT_STAT_gpio0_int_mskd_END (0)
#define SOC_IOMCU_COMB_INT_STAT_gpio1_int_mskd_START (1)
#define SOC_IOMCU_COMB_INT_STAT_gpio1_int_mskd_END (1)
#define SOC_IOMCU_COMB_INT_STAT_gpio2_int_mskd_START (2)
#define SOC_IOMCU_COMB_INT_STAT_gpio2_int_mskd_END (2)
#define SOC_IOMCU_COMB_INT_STAT_gpio3_int_mskd_START (3)
#define SOC_IOMCU_COMB_INT_STAT_gpio3_int_mskd_END (3)
#define SOC_IOMCU_COMB_INT_STAT_timer1_int_mskd_START (4)
#define SOC_IOMCU_COMB_INT_STAT_timer1_int_mskd_END (4)
#define SOC_IOMCU_COMB_INT_STAT_timer2_int_mskd_START (5)
#define SOC_IOMCU_COMB_INT_STAT_timer2_int_mskd_END (5)
#define SOC_IOMCU_COMB_INT_STAT_soft_int_mskd_START (6)
#define SOC_IOMCU_COMB_INT_STAT_soft_int_mskd_END (6)
#define SOC_IOMCU_COMB_INT_STAT_dss_rise_int_mskd_START (7)
#define SOC_IOMCU_COMB_INT_STAT_dss_rise_int_mskd_END (7)
#define SOC_IOMCU_COMB_INT_STAT_dss_down_int_mskd_START (8)
#define SOC_IOMCU_COMB_INT_STAT_dss_down_int_mskd_END (8)
#define SOC_IOMCU_COMB_INT_STAT_sys_wakeup_int_mskd_START (9)
#define SOC_IOMCU_COMB_INT_STAT_sys_wakeup_int_mskd_END (9)
#define SOC_IOMCU_COMB_INT_STAT_sys_sleep_int_mskd_START (10)
#define SOC_IOMCU_COMB_INT_STAT_sys_sleep_int_mskd_END (10)
#define SOC_IOMCU_COMB_INT_STAT_ftimer_int1_maskd_START (12)
#define SOC_IOMCU_COMB_INT_STAT_ftimer_int1_maskd_END (12)
#define SOC_IOMCU_COMB_INT_STAT_ftimer_int2_maskd_START (13)
#define SOC_IOMCU_COMB_INT_STAT_ftimer_int2_maskd_END (13)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_enter_req_mskd_START (14)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_enter_req_mskd_END (14)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_exit_req_mskd_START (15)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_exit_req_mskd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int auto_m7_freq_bypass : 1;
        unsigned int auto32k_sw_num : 5;
        unsigned int auto_num_in : 10;
        unsigned int auto_num_out : 10;
        unsigned int aximux_acg_bypass : 1;
        unsigned int noc_clkgate_bypass : 1;
        unsigned int reserved : 2;
        unsigned int dma_cg_err : 1;
        unsigned int m7_axi_cg_err : 1;
    } reg;
} SOC_IOMCU_BUS_AUTO_FREQ_UNION;
#endif
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_m7_freq_bypass_START (0)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_m7_freq_bypass_END (0)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto32k_sw_num_START (1)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto32k_sw_num_END (5)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_in_START (6)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_in_END (15)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_out_START (16)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_out_END (25)
#define SOC_IOMCU_BUS_AUTO_FREQ_aximux_acg_bypass_START (26)
#define SOC_IOMCU_BUS_AUTO_FREQ_aximux_acg_bypass_END (26)
#define SOC_IOMCU_BUS_AUTO_FREQ_noc_clkgate_bypass_START (27)
#define SOC_IOMCU_BUS_AUTO_FREQ_noc_clkgate_bypass_END (27)
#define SOC_IOMCU_BUS_AUTO_FREQ_dma_cg_err_START (30)
#define SOC_IOMCU_BUS_AUTO_FREQ_dma_cg_err_END (30)
#define SOC_IOMCU_BUS_AUTO_FREQ_m7_axi_cg_err_START (31)
#define SOC_IOMCU_BUS_AUTO_FREQ_m7_axi_cg_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spi_cs : 4;
        unsigned int clk_tp_ctrl : 1;
        unsigned int dmac_ckgt_dis : 1;
        unsigned int cfg_itcm_size : 4;
        unsigned int cfg_dtcm_size : 4;
        unsigned int spi2_cs : 4;
        unsigned int i3c_i2c_sel : 1;
        unsigned int uart_sel : 1;
        unsigned int spi2_sel : 2;
        unsigned int cg_off : 1;
        unsigned int tcm_int_sel : 1;
        unsigned int ahb_err_bypass : 1;
        unsigned int env_o_ext_cycle : 5;
        unsigned int spi0_sel : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_IOMCU_MISC_CTRL_UNION;
#endif
#define SOC_IOMCU_MISC_CTRL_spi_cs_START (0)
#define SOC_IOMCU_MISC_CTRL_spi_cs_END (3)
#define SOC_IOMCU_MISC_CTRL_clk_tp_ctrl_START (4)
#define SOC_IOMCU_MISC_CTRL_clk_tp_ctrl_END (4)
#define SOC_IOMCU_MISC_CTRL_dmac_ckgt_dis_START (5)
#define SOC_IOMCU_MISC_CTRL_dmac_ckgt_dis_END (5)
#define SOC_IOMCU_MISC_CTRL_cfg_itcm_size_START (6)
#define SOC_IOMCU_MISC_CTRL_cfg_itcm_size_END (9)
#define SOC_IOMCU_MISC_CTRL_cfg_dtcm_size_START (10)
#define SOC_IOMCU_MISC_CTRL_cfg_dtcm_size_END (13)
#define SOC_IOMCU_MISC_CTRL_spi2_cs_START (14)
#define SOC_IOMCU_MISC_CTRL_spi2_cs_END (17)
#define SOC_IOMCU_MISC_CTRL_i3c_i2c_sel_START (18)
#define SOC_IOMCU_MISC_CTRL_i3c_i2c_sel_END (18)
#define SOC_IOMCU_MISC_CTRL_uart_sel_START (19)
#define SOC_IOMCU_MISC_CTRL_uart_sel_END (19)
#define SOC_IOMCU_MISC_CTRL_spi2_sel_START (20)
#define SOC_IOMCU_MISC_CTRL_spi2_sel_END (21)
#define SOC_IOMCU_MISC_CTRL_cg_off_START (22)
#define SOC_IOMCU_MISC_CTRL_cg_off_END (22)
#define SOC_IOMCU_MISC_CTRL_tcm_int_sel_START (23)
#define SOC_IOMCU_MISC_CTRL_tcm_int_sel_END (23)
#define SOC_IOMCU_MISC_CTRL_ahb_err_bypass_START (24)
#define SOC_IOMCU_MISC_CTRL_ahb_err_bypass_END (24)
#define SOC_IOMCU_MISC_CTRL_env_o_ext_cycle_START (25)
#define SOC_IOMCU_MISC_CTRL_env_o_ext_cycle_END (29)
#define SOC_IOMCU_MISC_CTRL_spi0_sel_START (30)
#define SOC_IOMCU_MISC_CTRL_spi0_sel_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_iomcu_dma_mst_awqos : 2;
        unsigned int noc_iomcu_dma_mst_arqos : 2;
        unsigned int reserved_0 : 2;
        unsigned int noc_iomcu_ahb_tcp_mst_requser : 2;
        unsigned int noc_iomcu_ahb_mst_requser : 2;
        unsigned int noc_ahb_mst_mid : 6;
        unsigned int noc_ahb_tcp_mst_mid : 6;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_IOMCU_NOC_CTRL_UNION;
#endif
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_dma_mst_awqos_START (0)
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_dma_mst_awqos_END (1)
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_dma_mst_arqos_START (2)
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_dma_mst_arqos_END (3)
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_ahb_tcp_mst_requser_START (6)
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_ahb_tcp_mst_requser_END (7)
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_ahb_mst_requser_START (8)
#define SOC_IOMCU_NOC_CTRL_noc_iomcu_ahb_mst_requser_END (9)
#define SOC_IOMCU_NOC_CTRL_noc_ahb_mst_mid_START (10)
#define SOC_IOMCU_NOC_CTRL_noc_ahb_mst_mid_END (15)
#define SOC_IOMCU_NOC_CTRL_noc_ahb_tcp_mst_mid_START (16)
#define SOC_IOMCU_NOC_CTRL_noc_ahb_tcp_mst_mid_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifi_dtcm_access_window : 32;
    } reg;
} SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_hifi_dtcm_access_window_START (0)
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_hifi_dtcm_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_clken1_0peri0 : 1;
        unsigned int iomcu_clken1_1peri1 : 1;
        unsigned int iomcu_clken1_2peri2 : 1;
        unsigned int iomcu_clken1_3peri3 : 1;
        unsigned int iomcu_clken1_4dmmu : 1;
        unsigned int iomcu_clken1_ref_ftimer : 1;
        unsigned int iomcu_clken1_t_ftimer : 1;
        unsigned int iomcu_clken1_p_ftimer : 1;
        unsigned int iomcu_clken1_ftimer : 1;
        unsigned int iomcu_clken1_i3c : 1;
        unsigned int iomcu_clken1_h_tcp : 1;
        unsigned int iomcu_clken1_p_tcp : 1;
        unsigned int iomcu_clken1_i3c3 : 1;
        unsigned int iomcu_clken1_rtt : 1;
        unsigned int iomcu_clken1_i2c8 : 1;
        unsigned int iomcu_clken1_1peri1_spi2 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_CLKEN1_UNION;
#endif
#define SOC_IOMCU_CLKEN1_iomcu_clken1_0peri0_START (0)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_0peri0_END (0)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_START (1)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_END (1)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_2peri2_START (2)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_2peri2_END (2)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_3peri3_START (3)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_3peri3_END (3)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_4dmmu_START (4)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_4dmmu_END (4)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_ref_ftimer_START (5)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_ref_ftimer_END (5)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_t_ftimer_START (6)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_t_ftimer_END (6)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_p_ftimer_START (7)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_p_ftimer_END (7)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_ftimer_START (8)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_ftimer_END (8)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c_START (9)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c_END (9)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_h_tcp_START (10)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_h_tcp_END (10)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_p_tcp_START (11)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_p_tcp_END (11)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c3_START (12)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c3_END (12)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_rtt_START (13)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_rtt_END (13)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c8_START (14)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c8_END (14)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_spi2_START (15)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_spi2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_clkdis1_0peri0 : 1;
        unsigned int iomcu_clkdis1_1peri1 : 1;
        unsigned int iomcu_clkdis1_2peri2 : 1;
        unsigned int iomcu_clkdis1_3peri3 : 1;
        unsigned int iomcu_clkdis1_4dmmu : 1;
        unsigned int iomcu_clkdis1_ref_ftimer : 1;
        unsigned int iomcu_clkdis1_t_ftimer : 1;
        unsigned int iomcu_clkdis1_p_ftimer : 1;
        unsigned int iomcu_clkdis1_ftimer : 1;
        unsigned int iomcu_clkdis1_i3c : 1;
        unsigned int iomcu_clkdis1_h_tcp : 1;
        unsigned int iomcu_clkdis1_p_tcp : 1;
        unsigned int iomcu_clkdis1_i3c3 : 1;
        unsigned int iomcu_clkdis1_rtt : 1;
        unsigned int iomcu_clkdis1_i2c8 : 1;
        unsigned int iomcu_clkdis1_1peri1_spi2 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_CLKDIS1_UNION;
#endif
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_0peri0_START (0)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_0peri0_END (0)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_START (1)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_END (1)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_2peri2_START (2)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_2peri2_END (2)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_3peri3_START (3)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_3peri3_END (3)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_4dmmu_START (4)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_4dmmu_END (4)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ref_ftimer_START (5)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ref_ftimer_END (5)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_t_ftimer_START (6)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_t_ftimer_END (6)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_ftimer_START (7)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_ftimer_END (7)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ftimer_START (8)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ftimer_END (8)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c_START (9)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c_END (9)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_h_tcp_START (10)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_h_tcp_END (10)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_tcp_START (11)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_tcp_END (11)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c3_START (12)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c3_END (12)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_rtt_START (13)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_rtt_END (13)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c8_START (14)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c8_END (14)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_spi2_START (15)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_spi2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_clkstat1_0peri0 : 1;
        unsigned int iomcu_clkstat1_1peri1 : 1;
        unsigned int iomcu_clkstat1_2peri2 : 1;
        unsigned int iomcu_clkstat1_3peri3 : 1;
        unsigned int iomcu_clkstat1_4dmmu : 1;
        unsigned int iomcu_clkstat1_ref_ftimer : 1;
        unsigned int iomcu_clkstat1_t_ftimer : 1;
        unsigned int iomcu_clkstat1_p_ftimer : 1;
        unsigned int iomcu_clkstat1_ftimer : 1;
        unsigned int iomcu_clkstat1_i3c : 1;
        unsigned int iomcu_clkstat1_h_tcp : 1;
        unsigned int iomcu_clkstat1_p_tcp : 1;
        unsigned int iomcu_clkstat1_i3c3 : 1;
        unsigned int iomcu_clkstat1_rtt : 1;
        unsigned int iomcu_clkstat1_i2c8 : 1;
        unsigned int iomcu_clkstat1_1peri1_spi2 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_CLKSTAT1_UNION;
#endif
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_0peri0_START (0)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_0peri0_END (0)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_START (1)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_END (1)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_2peri2_START (2)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_2peri2_END (2)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_3peri3_START (3)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_3peri3_END (3)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_4dmmu_START (4)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_4dmmu_END (4)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_ref_ftimer_START (5)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_ref_ftimer_END (5)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_t_ftimer_START (6)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_t_ftimer_END (6)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_p_ftimer_START (7)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_p_ftimer_END (7)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_ftimer_START (8)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_ftimer_END (8)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c_START (9)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c_END (9)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_h_tcp_START (10)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_h_tcp_END (10)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_p_tcp_START (11)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_p_tcp_END (11)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c3_START (12)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c3_END (12)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_rtt_START (13)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_rtt_END (13)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c8_START (14)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c8_END (14)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_spi2_START (15)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_spi2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ocram_access_window : 32;
    } reg;
} SOC_IOMCU_OCRAM_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ocram_access_window_START (0)
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ocram_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_AHB_tzpc : 1;
        unsigned int iomcu_AXI_tzpc : 1;
        unsigned int iomcu_dmmu_tzpc : 1;
        unsigned int iomcu_i3c1_tzpc : 1;
        unsigned int iomcu_i2c1_tzpc : 1;
        unsigned int iomcu_spi2_tzpc : 1;
        unsigned int iomcu_uart8_tzpc : 1;
        unsigned int iomcu_i3c2_tzpc : 1;
        unsigned int iomcu_i2c5_tzpc : 1;
        unsigned int iomcu_spi_tzpc : 1;
        unsigned int iomcu_i2c0_tzpc : 1;
        unsigned int iomcu_uart3_tzpc : 1;
        unsigned int iomcu_blpwm_tzpc : 1;
        unsigned int iomcu_uart7_tzpc : 1;
        unsigned int iomcu_i3c_tzpc : 1;
        unsigned int iomcu_gpio0_tzpc : 1;
        unsigned int iomcu_gpio1_tzpc : 1;
        unsigned int iomcu_gpio2_tzpc : 1;
        unsigned int iomcu_gpio3_tzpc : 1;
        unsigned int iomcu_wdg_tzpc : 1;
        unsigned int iomcu_timer_tzpc : 1;
        unsigned int iomcu_sctrl_tzpc : 1;
        unsigned int iomcu_rtc_tzpc : 1;
        unsigned int iomcu_m7_tzpc : 1;
        unsigned int iomcu_ftimer_tzpc : 1;
        unsigned int iomcu_tcp_tzpc : 1;
        unsigned int iomcu_ahb_tcp_tzpc : 1;
        unsigned int iomcu_i3c3_tzpc : 1;
        unsigned int iomcu_tcm_tzpc : 1;
        unsigned int iomcu_i2c8_tzpc : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_IOMCU_SEC_TZPC_UNION;
#endif
#define SOC_IOMCU_SEC_TZPC_iomcu_AHB_tzpc_START (0)
#define SOC_IOMCU_SEC_TZPC_iomcu_AHB_tzpc_END (0)
#define SOC_IOMCU_SEC_TZPC_iomcu_AXI_tzpc_START (1)
#define SOC_IOMCU_SEC_TZPC_iomcu_AXI_tzpc_END (1)
#define SOC_IOMCU_SEC_TZPC_iomcu_dmmu_tzpc_START (2)
#define SOC_IOMCU_SEC_TZPC_iomcu_dmmu_tzpc_END (2)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c1_tzpc_START (3)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c1_tzpc_END (3)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c1_tzpc_START (4)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c1_tzpc_END (4)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi2_tzpc_START (5)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi2_tzpc_END (5)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart8_tzpc_START (6)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart8_tzpc_END (6)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c2_tzpc_START (7)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c2_tzpc_END (7)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c5_tzpc_START (8)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c5_tzpc_END (8)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi_tzpc_START (9)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi_tzpc_END (9)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c0_tzpc_START (10)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c0_tzpc_END (10)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart3_tzpc_START (11)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart3_tzpc_END (11)
#define SOC_IOMCU_SEC_TZPC_iomcu_blpwm_tzpc_START (12)
#define SOC_IOMCU_SEC_TZPC_iomcu_blpwm_tzpc_END (12)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart7_tzpc_START (13)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart7_tzpc_END (13)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c_tzpc_START (14)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c_tzpc_END (14)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio0_tzpc_START (15)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio0_tzpc_END (15)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio1_tzpc_START (16)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio1_tzpc_END (16)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio2_tzpc_START (17)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio2_tzpc_END (17)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio3_tzpc_START (18)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio3_tzpc_END (18)
#define SOC_IOMCU_SEC_TZPC_iomcu_wdg_tzpc_START (19)
#define SOC_IOMCU_SEC_TZPC_iomcu_wdg_tzpc_END (19)
#define SOC_IOMCU_SEC_TZPC_iomcu_timer_tzpc_START (20)
#define SOC_IOMCU_SEC_TZPC_iomcu_timer_tzpc_END (20)
#define SOC_IOMCU_SEC_TZPC_iomcu_sctrl_tzpc_START (21)
#define SOC_IOMCU_SEC_TZPC_iomcu_sctrl_tzpc_END (21)
#define SOC_IOMCU_SEC_TZPC_iomcu_rtc_tzpc_START (22)
#define SOC_IOMCU_SEC_TZPC_iomcu_rtc_tzpc_END (22)
#define SOC_IOMCU_SEC_TZPC_iomcu_m7_tzpc_START (23)
#define SOC_IOMCU_SEC_TZPC_iomcu_m7_tzpc_END (23)
#define SOC_IOMCU_SEC_TZPC_iomcu_ftimer_tzpc_START (24)
#define SOC_IOMCU_SEC_TZPC_iomcu_ftimer_tzpc_END (24)
#define SOC_IOMCU_SEC_TZPC_iomcu_tcp_tzpc_START (25)
#define SOC_IOMCU_SEC_TZPC_iomcu_tcp_tzpc_END (25)
#define SOC_IOMCU_SEC_TZPC_iomcu_ahb_tcp_tzpc_START (26)
#define SOC_IOMCU_SEC_TZPC_iomcu_ahb_tcp_tzpc_END (26)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c3_tzpc_START (27)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c3_tzpc_END (27)
#define SOC_IOMCU_SEC_TZPC_iomcu_tcm_tzpc_START (28)
#define SOC_IOMCU_SEC_TZPC_iomcu_tcm_tzpc_END (28)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c8_tzpc_START (29)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c8_tzpc_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_se_reserved : 32;
    } reg;
} SOC_IOMCU_SEC_RES_UNION;
#endif
#define SOC_IOMCU_SEC_RES_iomcu_se_reserved_START (0)
#define SOC_IOMCU_SEC_RES_iomcu_se_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_spi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_MEM_CTRL6_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL6_mem_ctrl_spi_START (0)
#define SOC_IOMCU_MEM_CTRL6_mem_ctrl_spi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcm_mem_ctrl : 32;
    } reg;
} SOC_IOMCU_MEM_CTRL_TCM_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL_TCM_tcm_mem_ctrl_START (0)
#define SOC_IOMCU_MEM_CTRL_TCM_tcm_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int cache_mem_ctrl : 16;
    } reg;
} SOC_IOMCU_MEM_CTRL2_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL2_cache_mem_ctrl_START (16)
#define SOC_IOMCU_MEM_CTRL2_cache_mem_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_bank11 : 3;
        unsigned int mem_ctrl_bank12 : 3;
        unsigned int mem_ctrl_bank13 : 3;
        unsigned int mem_ctrl_bank14 : 3;
        unsigned int mem_ctrl_bank15 : 3;
        unsigned int mem_ctrl_bank16 : 3;
        unsigned int mem_ctrl_bank17 : 3;
        unsigned int mem_ctrl_bank18 : 3;
        unsigned int mem_ctrl_bank19 : 3;
        unsigned int mem_ctrl_bank20 : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_IOMCU_MEM_CTRL3_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank11_START (0)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank11_END (2)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank12_START (3)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank12_END (5)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank13_START (6)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank13_END (8)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank14_START (9)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank14_END (11)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank15_START (12)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank15_END (14)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank16_START (15)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank16_END (17)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank17_START (18)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank17_END (20)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank18_START (21)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank18_END (23)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank19_START (24)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank19_END (26)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank20_START (27)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank20_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_mcu_sel_tcp : 2;
        unsigned int auto32k_switch_tcp : 1;
        unsigned int fll_en_in_tcp : 1;
        unsigned int fll_gt_in_tcp : 1;
        unsigned int tcp_mem_ctrl_num : 5;
        unsigned int tcp_mem_ctrl : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_IOMCU_TCP_CTRL_UNION;
#endif
#define SOC_IOMCU_TCP_CTRL_clk_mcu_sel_tcp_START (0)
#define SOC_IOMCU_TCP_CTRL_clk_mcu_sel_tcp_END (1)
#define SOC_IOMCU_TCP_CTRL_auto32k_switch_tcp_START (2)
#define SOC_IOMCU_TCP_CTRL_auto32k_switch_tcp_END (2)
#define SOC_IOMCU_TCP_CTRL_fll_en_in_tcp_START (3)
#define SOC_IOMCU_TCP_CTRL_fll_en_in_tcp_END (3)
#define SOC_IOMCU_TCP_CTRL_fll_gt_in_tcp_START (4)
#define SOC_IOMCU_TCP_CTRL_fll_gt_in_tcp_END (4)
#define SOC_IOMCU_TCP_CTRL_tcp_mem_ctrl_num_START (5)
#define SOC_IOMCU_TCP_CTRL_tcp_mem_ctrl_num_END (9)
#define SOC_IOMCU_TCP_CTRL_tcp_mem_ctrl_START (10)
#define SOC_IOMCU_TCP_CTRL_tcp_mem_ctrl_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_dma : 16;
        unsigned int mem_ctrl_bank21 : 3;
        unsigned int reserved_0 : 1;
        unsigned int mem_ctrl_bank22 : 3;
        unsigned int reserved_1 : 1;
        unsigned int mem_ctrl_bank23 : 3;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_IOMCU_MEM_CTRL4_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_dma_START (0)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_dma_END (15)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_bank21_START (16)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_bank21_END (18)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_bank22_START (20)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_bank22_END (22)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_bank23_START (24)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_bank23_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_i3c : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_IOMCU_MEM_CTRL5_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL5_mem_ctrl_i3c_START (0)
#define SOC_IOMCU_MEM_CTRL5_mem_ctrl_i3c_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int araddr_chk : 32;
    } reg;
} SOC_IOMCU_ARADDR_CHK_UNION;
#endif
#define SOC_IOMCU_ARADDR_CHK_araddr_chk_START (0)
#define SOC_IOMCU_ARADDR_CHK_araddr_chk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awaddr_chk : 32;
    } reg;
} SOC_IOMCU_AWADDR_CHK_UNION;
#endif
#define SOC_IOMCU_AWADDR_CHK_awaddr_chk_START (0)
#define SOC_IOMCU_AWADDR_CHK_awaddr_chk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_mst_mid : 6;
        unsigned int axi_mst_mid : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_IOMCU_MID_CTRL_UNION;
#endif
#define SOC_IOMCU_MID_CTRL_dma_mst_mid_START (0)
#define SOC_IOMCU_MID_CTRL_dma_mst_mid_END (5)
#define SOC_IOMCU_MID_CTRL_axi_mst_mid_START (6)
#define SOC_IOMCU_MID_CTRL_axi_mst_mid_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ccm_ctrl : 15;
        unsigned int ccm_cs_bypass : 1;
        unsigned int ccm_clk_en : 15;
        unsigned int dccm_dmi_priority : 1;
    } reg;
} SOC_IOMCU_CCM_CTRL_UNION;
#endif
#define SOC_IOMCU_CCM_CTRL_ccm_ctrl_START (0)
#define SOC_IOMCU_CCM_CTRL_ccm_ctrl_END (14)
#define SOC_IOMCU_CCM_CTRL_ccm_cs_bypass_START (15)
#define SOC_IOMCU_CCM_CTRL_ccm_cs_bypass_END (15)
#define SOC_IOMCU_CCM_CTRL_ccm_clk_en_START (16)
#define SOC_IOMCU_CCM_CTRL_ccm_clk_en_END (30)
#define SOC_IOMCU_CCM_CTRL_dccm_dmi_priority_START (31)
#define SOC_IOMCU_CCM_CTRL_dccm_dmi_priority_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cti_rtt_filters : 26;
        unsigned int arc_run_ack : 1;
        unsigned int arc_halt_ack : 1;
        unsigned int core_stalled : 1;
        unsigned int sys_tf_halt_r : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_IOMCU_ARC_RB0_UNION;
#endif
#define SOC_IOMCU_ARC_RB0_cti_rtt_filters_START (0)
#define SOC_IOMCU_ARC_RB0_cti_rtt_filters_END (25)
#define SOC_IOMCU_ARC_RB0_arc_run_ack_START (26)
#define SOC_IOMCU_ARC_RB0_arc_run_ack_END (26)
#define SOC_IOMCU_ARC_RB0_arc_halt_ack_START (27)
#define SOC_IOMCU_ARC_RB0_arc_halt_ack_END (27)
#define SOC_IOMCU_ARC_RB0_core_stalled_START (28)
#define SOC_IOMCU_ARC_RB0_core_stalled_END (28)
#define SOC_IOMCU_ARC_RB0_sys_tf_halt_r_START (29)
#define SOC_IOMCU_ARC_RB0_sys_tf_halt_r_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcnum : 8;
        unsigned int clusternum : 8;
        unsigned int ccm_intr_clear : 1;
        unsigned int ccm_intr_bypass : 1;
        unsigned int ap_param0_read : 1;
        unsigned int ap_param1_read : 1;
        unsigned int ap_param0_write : 1;
        unsigned int ap_param1_write : 1;
        unsigned int dbg_cache_rst_disable : 1;
        unsigned int env_ext_cycle : 5;
        unsigned int reserved : 4;
    } reg;
} SOC_IOMCU_ARC_CTRL_UNION;
#endif
#define SOC_IOMCU_ARC_CTRL_arcnum_START (0)
#define SOC_IOMCU_ARC_CTRL_arcnum_END (7)
#define SOC_IOMCU_ARC_CTRL_clusternum_START (8)
#define SOC_IOMCU_ARC_CTRL_clusternum_END (15)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_clear_START (16)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_clear_END (16)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_bypass_START (17)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_bypass_END (17)
#define SOC_IOMCU_ARC_CTRL_ap_param0_read_START (18)
#define SOC_IOMCU_ARC_CTRL_ap_param0_read_END (18)
#define SOC_IOMCU_ARC_CTRL_ap_param1_read_START (19)
#define SOC_IOMCU_ARC_CTRL_ap_param1_read_END (19)
#define SOC_IOMCU_ARC_CTRL_ap_param0_write_START (20)
#define SOC_IOMCU_ARC_CTRL_ap_param0_write_END (20)
#define SOC_IOMCU_ARC_CTRL_ap_param1_write_START (21)
#define SOC_IOMCU_ARC_CTRL_ap_param1_write_END (21)
#define SOC_IOMCU_ARC_CTRL_dbg_cache_rst_disable_START (22)
#define SOC_IOMCU_ARC_CTRL_dbg_cache_rst_disable_END (22)
#define SOC_IOMCU_ARC_CTRL_env_ext_cycle_START (23)
#define SOC_IOMCU_ARC_CTRL_env_ext_cycle_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_mcu_frac_div : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_UNION;
#endif
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_clk_mcu_frac_div_START (0)
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_clk_mcu_frac_div_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dccm0_lo_err_addr : 16;
        unsigned int dccm0_hi_err_addr : 16;
    } reg;
} SOC_IOMCU_DCCM0_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_lo_err_addr_START (0)
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_lo_err_addr_END (15)
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_hi_err_addr_START (16)
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_hi_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dccm1_lo_err_addr : 16;
        unsigned int dccm1_hi_err_addr : 16;
    } reg;
} SOC_IOMCU_DCCM1_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_lo_err_addr_START (0)
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_lo_err_addr_END (15)
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_hi_err_addr_START (16)
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_hi_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iccm_bank0_err_addr : 16;
        unsigned int iccm_bank1_err_addr : 16;
    } reg;
} SOC_IOMCU_ICCM0_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank0_err_addr_START (0)
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank0_err_addr_END (15)
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank1_err_addr_START (16)
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank1_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dccm0_lo_err_cnt : 8;
        unsigned int dccm0_hi_err_cnt : 8;
        unsigned int dccm1_lo_err_cnt : 8;
        unsigned int dccm1_hi_err_cnt : 8;
    } reg;
} SOC_IOMCU_CCM_RB0_UNION;
#endif
#define SOC_IOMCU_CCM_RB0_dccm0_lo_err_cnt_START (0)
#define SOC_IOMCU_CCM_RB0_dccm0_lo_err_cnt_END (7)
#define SOC_IOMCU_CCM_RB0_dccm0_hi_err_cnt_START (8)
#define SOC_IOMCU_CCM_RB0_dccm0_hi_err_cnt_END (15)
#define SOC_IOMCU_CCM_RB0_dccm1_lo_err_cnt_START (16)
#define SOC_IOMCU_CCM_RB0_dccm1_lo_err_cnt_END (23)
#define SOC_IOMCU_CCM_RB0_dccm1_hi_err_cnt_START (24)
#define SOC_IOMCU_CCM_RB0_dccm1_hi_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iccm0_bank0_err_cnt : 8;
        unsigned int iccm0_bank1_err_cnt : 8;
        unsigned int dccm0_lo_out_bound_err : 1;
        unsigned int dccm0_hi_out_bound_err : 1;
        unsigned int dccm1_lo_out_bound_err : 1;
        unsigned int dccm1_hi_out_bound_err : 1;
        unsigned int iccm0_bank0_out_bound_err : 1;
        unsigned int iccm0_bank1_out_bound_err : 1;
        unsigned int ccm_err_status : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_IOMCU_CCM_RB1_UNION;
#endif
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_err_cnt_START (0)
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_err_cnt_END (7)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_err_cnt_START (8)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_err_cnt_END (15)
#define SOC_IOMCU_CCM_RB1_dccm0_lo_out_bound_err_START (16)
#define SOC_IOMCU_CCM_RB1_dccm0_lo_out_bound_err_END (16)
#define SOC_IOMCU_CCM_RB1_dccm0_hi_out_bound_err_START (17)
#define SOC_IOMCU_CCM_RB1_dccm0_hi_out_bound_err_END (17)
#define SOC_IOMCU_CCM_RB1_dccm1_lo_out_bound_err_START (18)
#define SOC_IOMCU_CCM_RB1_dccm1_lo_out_bound_err_END (18)
#define SOC_IOMCU_CCM_RB1_dccm1_hi_out_bound_err_START (19)
#define SOC_IOMCU_CCM_RB1_dccm1_hi_out_bound_err_END (19)
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_out_bound_err_START (20)
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_out_bound_err_END (20)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_out_bound_err_START (21)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_out_bound_err_END (21)
#define SOC_IOMCU_CCM_RB1_ccm_err_status_START (22)
#define SOC_IOMCU_CCM_RB1_ccm_err_status_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cti_ap_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_IOMCU_ARC_RB1_UNION;
#endif
#define SOC_IOMCU_ARC_RB1_cti_ap_status_START (0)
#define SOC_IOMCU_ARC_RB1_cti_ap_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ap_param0 : 32;
    } reg;
} SOC_IOMCU_ARC_AP_PARAM0_UNION;
#endif
#define SOC_IOMCU_ARC_AP_PARAM0_ap_param0_START (0)
#define SOC_IOMCU_ARC_AP_PARAM0_ap_param0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ap_param1 : 32;
    } reg;
} SOC_IOMCU_ARC_AP_PARAM1_UNION;
#endif
#define SOC_IOMCU_ARC_AP_PARAM1_ap_param1_START (0)
#define SOC_IOMCU_ARC_AP_PARAM1_ap_param1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en0 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN0_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN0_event_en0_START (0)
#define SOC_IOMCU_ARC_EVENT_EN0_event_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en1 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN1_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN1_event_en1_START (0)
#define SOC_IOMCU_ARC_EVENT_EN1_event_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en2 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN2_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN2_event_en2_START (0)
#define SOC_IOMCU_ARC_EVENT_EN2_event_en2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en3 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN3_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN3_event_en3_START (0)
#define SOC_IOMCU_ARC_EVENT_EN3_event_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irq_en0 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN0_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN0_irq_en0_START (0)
#define SOC_IOMCU_ARC_IRQ_EN0_irq_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irq_en1 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN1_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN1_irq_en1_START (0)
#define SOC_IOMCU_ARC_IRQ_EN1_irq_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irq_en2 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN2_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN2_irq_en2_START (0)
#define SOC_IOMCU_ARC_IRQ_EN2_irq_en2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irq_en3 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN3_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN3_irq_en3_START (0)
#define SOC_IOMCU_ARC_IRQ_EN3_irq_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en4 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN4_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN4_event_en4_START (0)
#define SOC_IOMCU_ARC_EVENT_EN4_event_en4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en5 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN5_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN5_event_en5_START (0)
#define SOC_IOMCU_ARC_EVENT_EN5_event_en5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en6 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN6_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN6_event_en6_START (0)
#define SOC_IOMCU_ARC_EVENT_EN6_event_en6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_en7 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN7_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN7_event_en7_START (0)
#define SOC_IOMCU_ARC_EVENT_EN7_event_en7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m7_ahb_dbg_info1 : 32;
    } reg;
} SOC_IOMCU_M7_AHB_DBG_INFO1_UNION;
#endif
#define SOC_IOMCU_M7_AHB_DBG_INFO1_m7_ahb_dbg_info1_START (0)
#define SOC_IOMCU_M7_AHB_DBG_INFO1_m7_ahb_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m7_ahb_dbg_info2 : 32;
    } reg;
} SOC_IOMCU_M7_AHB_DBG_INFO2_UNION;
#endif
#define SOC_IOMCU_M7_AHB_DBG_INFO2_m7_ahb_dbg_info2_START (0)
#define SOC_IOMCU_M7_AHB_DBG_INFO2_m7_ahb_dbg_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m7_ahb_time_cfg : 32;
    } reg;
} SOC_IOMCU_M7_AHB_TIME_CFG_UNION;
#endif
#define SOC_IOMCU_M7_AHB_TIME_CFG_m7_ahb_time_cfg_START (0)
#define SOC_IOMCU_M7_AHB_TIME_CFG_m7_ahb_time_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m7_ahb_timeout_bypass : 1;
        unsigned int m7_ahb_timeout_resperr : 1;
        unsigned int m7_ahb_dbg_timeout_int_en : 1;
        unsigned int m7_ahb_dbg_timeout_int_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_IOMCU_M7_AHB_TIMEOUT_UNION;
#endif
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_bypass_START (0)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_bypass_END (0)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_resperr_START (1)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_resperr_END (1)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_en_START (2)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_en_END (2)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_clr_START (3)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_reserved_reg0 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG0_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG0_iomcu_reserved_reg0_START (0)
#define SOC_IOMCU_RESERVED_REG0_iomcu_reserved_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int iomcu_reserved_reg1 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG1_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG1_iomcu_reserved_reg1_START (0)
#define SOC_IOMCU_RESERVED_REG1_iomcu_reserved_reg1_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
