#ifndef __SOC_CORECRG_L_L3_INTERFACE_H__
#define __SOC_CORECRG_L_L3_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CORECRG_L_L3_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_CORECRG_L_L3_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_CORECRG_L_L3_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_CORECRG_L_L3_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_CORECRG_L_L3_PERI_STAT0_ADDR(base) ((base) + (0x060UL))
#define SOC_CORECRG_L_L3_CLKDIV0_ADDR(base) ((base) + (0x080UL))
#define SOC_CORECRG_L_L3_VS_CTRL_EN_LITTLE_ADDR(base) ((base) + (0x100UL))
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_LITTLE_ADDR(base) ((base) + (0x104UL))
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_ADDR(base) ((base) + (0x108UL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_ADDR(base) ((base) + (0x10CUL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_ADDR(base) ((base) + (0x110UL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_ADDR(base) ((base) + (0x114UL))
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_ADDR(base) ((base) + (0x118UL))
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_ADDR(base) ((base) + (0x11CUL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_LITTLE_ADDR(base) ((base) + (0x120UL))
#define SOC_CORECRG_L_L3_VS_CTRL_EN_L3_ADDR(base) ((base) + (0x130UL))
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_L3_ADDR(base) ((base) + (0x134UL))
#define SOC_CORECRG_L_L3_VS_CTRL_L3_ADDR(base) ((base) + (0x138UL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_ADDR(base) ((base) + (0x13CUL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_ADDR(base) ((base) + (0x140UL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_ADDR(base) ((base) + (0x144UL))
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_ADDR(base) ((base) + (0x148UL))
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_ADDR(base) ((base) + (0x14CUL))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_L3_ADDR(base) ((base) + (0x150UL))
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_ADDR(base) ((base) + (0x1E0UL))
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_ADDR(base) ((base) + (0x1E4UL))
#define SOC_CORECRG_L_L3_APLL0_CFG0_ADDR(base) ((base) + (0x1E8UL))
#define SOC_CORECRG_L_L3_APLL0_CFG1_ADDR(base) ((base) + (0x1ECUL))
#define SOC_CORECRG_L_L3_APLL0_CFG2_ADDR(base) ((base) + (0x1F0UL))
#define SOC_CORECRG_L_L3_APLL1_CFG0_ADDR(base) ((base) + (0x1F4UL))
#define SOC_CORECRG_L_L3_APLL1_CFG1_ADDR(base) ((base) + (0x1F8UL))
#define SOC_CORECRG_L_L3_APLL1_CFG2_ADDR(base) ((base) + (0x1FCUL))
#define SOC_CORECRG_L_L3_FCM_CLKEN_ADDR(base) ((base) + (0x200UL))
#define SOC_CORECRG_L_L3_APLL0_STAT_ADDR(base) ((base) + (0x250UL))
#define SOC_CORECRG_L_L3_APLL1_STAT_ADDR(base) ((base) + (0x254UL))
#define SOC_CORECRG_L_L3_APLL0_CFG3_ADDR(base) ((base) + (0x258UL))
#define SOC_CORECRG_L_L3_APLL1_CFG3_ADDR(base) ((base) + (0x25CUL))
#else
#define SOC_CORECRG_L_L3_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_CORECRG_L_L3_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_CORECRG_L_L3_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_CORECRG_L_L3_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_CORECRG_L_L3_PERI_STAT0_ADDR(base) ((base) + (0x060))
#define SOC_CORECRG_L_L3_CLKDIV0_ADDR(base) ((base) + (0x080))
#define SOC_CORECRG_L_L3_VS_CTRL_EN_LITTLE_ADDR(base) ((base) + (0x100))
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_LITTLE_ADDR(base) ((base) + (0x104))
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_ADDR(base) ((base) + (0x108))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_ADDR(base) ((base) + (0x10C))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_ADDR(base) ((base) + (0x110))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_ADDR(base) ((base) + (0x114))
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_ADDR(base) ((base) + (0x118))
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_ADDR(base) ((base) + (0x11C))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_LITTLE_ADDR(base) ((base) + (0x120))
#define SOC_CORECRG_L_L3_VS_CTRL_EN_L3_ADDR(base) ((base) + (0x130))
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_L3_ADDR(base) ((base) + (0x134))
#define SOC_CORECRG_L_L3_VS_CTRL_L3_ADDR(base) ((base) + (0x138))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_ADDR(base) ((base) + (0x13C))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_ADDR(base) ((base) + (0x140))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_ADDR(base) ((base) + (0x144))
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_ADDR(base) ((base) + (0x148))
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_ADDR(base) ((base) + (0x14C))
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_L3_ADDR(base) ((base) + (0x150))
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_ADDR(base) ((base) + (0x1E0))
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_ADDR(base) ((base) + (0x1E4))
#define SOC_CORECRG_L_L3_APLL0_CFG0_ADDR(base) ((base) + (0x1E8))
#define SOC_CORECRG_L_L3_APLL0_CFG1_ADDR(base) ((base) + (0x1EC))
#define SOC_CORECRG_L_L3_APLL0_CFG2_ADDR(base) ((base) + (0x1F0))
#define SOC_CORECRG_L_L3_APLL1_CFG0_ADDR(base) ((base) + (0x1F4))
#define SOC_CORECRG_L_L3_APLL1_CFG1_ADDR(base) ((base) + (0x1F8))
#define SOC_CORECRG_L_L3_APLL1_CFG2_ADDR(base) ((base) + (0x1FC))
#define SOC_CORECRG_L_L3_FCM_CLKEN_ADDR(base) ((base) + (0x200))
#define SOC_CORECRG_L_L3_APLL0_STAT_ADDR(base) ((base) + (0x250))
#define SOC_CORECRG_L_L3_APLL1_STAT_ADDR(base) ((base) + (0x254))
#define SOC_CORECRG_L_L3_APLL0_CFG3_ADDR(base) ((base) + (0x258))
#define SOC_CORECRG_L_L3_APLL1_CFG3_ADDR(base) ((base) + (0x25C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_apll0_sscg : 1;
        unsigned int gt_clk_apll1_sscg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 7;
    } reg;
} SOC_CORECRG_L_L3_PEREN0_UNION;
#endif
#define SOC_CORECRG_L_L3_PEREN0_gt_clk_apll0_sscg_START (0)
#define SOC_CORECRG_L_L3_PEREN0_gt_clk_apll0_sscg_END (0)
#define SOC_CORECRG_L_L3_PEREN0_gt_clk_apll1_sscg_START (1)
#define SOC_CORECRG_L_L3_PEREN0_gt_clk_apll1_sscg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_apll0_sscg : 1;
        unsigned int gt_clk_apll1_sscg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 7;
    } reg;
} SOC_CORECRG_L_L3_PERDIS0_UNION;
#endif
#define SOC_CORECRG_L_L3_PERDIS0_gt_clk_apll0_sscg_START (0)
#define SOC_CORECRG_L_L3_PERDIS0_gt_clk_apll0_sscg_END (0)
#define SOC_CORECRG_L_L3_PERDIS0_gt_clk_apll1_sscg_START (1)
#define SOC_CORECRG_L_L3_PERDIS0_gt_clk_apll1_sscg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_apll0_sscg : 1;
        unsigned int gt_clk_apll1_sscg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 7;
    } reg;
} SOC_CORECRG_L_L3_PERCLKEN0_UNION;
#endif
#define SOC_CORECRG_L_L3_PERCLKEN0_gt_clk_apll0_sscg_START (0)
#define SOC_CORECRG_L_L3_PERCLKEN0_gt_clk_apll0_sscg_END (0)
#define SOC_CORECRG_L_L3_PERCLKEN0_gt_clk_apll1_sscg_START (1)
#define SOC_CORECRG_L_L3_PERCLKEN0_gt_clk_apll1_sscg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_apll0_sscg : 1;
        unsigned int st_clk_apll1_sscg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 7;
    } reg;
} SOC_CORECRG_L_L3_PERSTAT0_UNION;
#endif
#define SOC_CORECRG_L_L3_PERSTAT0_st_clk_apll0_sscg_START (0)
#define SOC_CORECRG_L_L3_PERSTAT0_st_clk_apll0_sscg_END (0)
#define SOC_CORECRG_L_L3_PERSTAT0_st_clk_apll1_sscg_START (1)
#define SOC_CORECRG_L_L3_PERSTAT0_st_clk_apll1_sscg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_cpu_little : 1;
        unsigned int st_clk_cpu_l3 : 1;
        unsigned int sw_ack_clk_cpul_pll_sw : 2;
        unsigned int sw_ack_clk_l3_pll_sw : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_CORECRG_L_L3_PERI_STAT0_UNION;
#endif
#define SOC_CORECRG_L_L3_PERI_STAT0_st_clk_cpu_little_START (0)
#define SOC_CORECRG_L_L3_PERI_STAT0_st_clk_cpu_little_END (0)
#define SOC_CORECRG_L_L3_PERI_STAT0_st_clk_cpu_l3_START (1)
#define SOC_CORECRG_L_L3_PERI_STAT0_st_clk_cpu_l3_END (1)
#define SOC_CORECRG_L_L3_PERI_STAT0_sw_ack_clk_cpul_pll_sw_START (2)
#define SOC_CORECRG_L_L3_PERI_STAT0_sw_ack_clk_cpul_pll_sw_END (3)
#define SOC_CORECRG_L_L3_PERI_STAT0_sw_ack_clk_l3_pll_sw_START (4)
#define SOC_CORECRG_L_L3_PERI_STAT0_sw_ack_clk_l3_pll_sw_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dvfs_clkdiv_little : 2;
        unsigned int dvfs_clkdiv_l3 : 2;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORECRG_L_L3_CLKDIV0_UNION;
#endif
#define SOC_CORECRG_L_L3_CLKDIV0_dvfs_clkdiv_little_START (0)
#define SOC_CORECRG_L_L3_CLKDIV0_dvfs_clkdiv_little_END (1)
#define SOC_CORECRG_L_L3_CLKDIV0_dvfs_clkdiv_l3_START (2)
#define SOC_CORECRG_L_L3_CLKDIV0_dvfs_clkdiv_l3_END (3)
#define SOC_CORECRG_L_L3_CLKDIV0_bitmasken_START (16)
#define SOC_CORECRG_L_L3_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vs_ctrl_en_little : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORECRG_L_L3_VS_CTRL_EN_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CTRL_EN_LITTLE_vs_ctrl_en_little_START (0)
#define SOC_CORECRG_L_L3_VS_CTRL_EN_LITTLE_vs_ctrl_en_little_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vs_ctrl_bypass_little : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORECRG_L_L3_VS_CTRL_BYPASS_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_LITTLE_vs_ctrl_bypass_little_START (0)
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_LITTLE_vs_ctrl_bypass_little_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int little_cpu0_wfi_wfe_bypass : 1;
        unsigned int little_cpu1_wfi_wfe_bypass : 1;
        unsigned int little_cpu2_wfi_wfe_bypass : 1;
        unsigned int little_cpu3_wfi_wfe_bypass : 1;
        unsigned int little_l2_idle_div_mod : 2;
        unsigned int little_cfg_cnt_cpu_wake_quit : 16;
        unsigned int little_cpu_wake_up_mode : 2;
        unsigned int little_cpu_l2_idle_switch_bypass : 1;
        unsigned int little_cpu_l2_idle_gt_en : 1;
        unsigned int little_dvfs_div_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int sel_ckmux_little_icg : 1;
        unsigned int cpu_clk_div_cfg_little : 2;
    } reg;
} SOC_CORECRG_L_L3_VS_CTRL_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu0_wfi_wfe_bypass_START (1)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu0_wfi_wfe_bypass_END (1)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu1_wfi_wfe_bypass_START (2)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu1_wfi_wfe_bypass_END (2)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu2_wfi_wfe_bypass_START (3)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu2_wfi_wfe_bypass_END (3)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu3_wfi_wfe_bypass_START (4)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu3_wfi_wfe_bypass_END (4)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_l2_idle_div_mod_START (5)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_l2_idle_div_mod_END (6)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu_wake_up_mode_START (23)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu_wake_up_mode_END (24)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu_l2_idle_gt_en_START (26)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_cpu_l2_idle_gt_en_END (26)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_dvfs_div_en_START (27)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_little_dvfs_div_en_END (27)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_sel_ckmux_little_icg_START (29)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_sel_ckmux_little_icg_END (29)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_cpu_clk_div_cfg_little_START (30)
#define SOC_CORECRG_L_L3_VS_CTRL_LITTLE_cpu_clk_div_cfg_little_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_data_limit_e_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int svfd_pulse_width_sel_little : 1;
        unsigned int reserved_1 : 1;
        unsigned int svfd_ulvt_ll_little : 4;
        unsigned int svfd_ulvt_sl_little : 4;
        unsigned int svfd_lvt_ll_little : 4;
        unsigned int svfd_lvt_sl_little : 4;
        unsigned int svfd_trim_little : 2;
        unsigned int svfd_d_rate1_little : 2;
        unsigned int svfd_d_rate_little : 2;
        unsigned int svfd_off_mode_little : 1;
        unsigned int svfd_div64_en_little : 1;
        unsigned int svfd_cpm_period_little : 1;
        unsigned int svfd_edge_sel_little : 1;
        unsigned int svfd_cmp_data_mode_little : 2;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_data_limit_e_little_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_data_limit_e_little_END (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_pulse_width_sel_little_START (2)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_pulse_width_sel_little_END (2)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_ulvt_ll_little_START (4)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_ulvt_ll_little_END (7)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_ulvt_sl_little_START (8)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_ulvt_sl_little_END (11)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_lvt_ll_little_START (12)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_lvt_ll_little_END (15)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_lvt_sl_little_START (16)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_lvt_sl_little_END (19)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_trim_little_START (20)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_trim_little_END (21)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_d_rate1_little_START (22)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_d_rate1_little_END (23)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_d_rate_little_START (24)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_d_rate_little_END (25)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_off_mode_little_START (26)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_off_mode_little_END (26)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_div64_en_little_START (27)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_div64_en_little_END (27)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_cpm_period_little_START (28)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_cpm_period_little_END (28)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_edge_sel_little_START (29)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_edge_sel_little_END (29)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_cmp_data_mode_little_START (30)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_LITTLE_svfd_cmp_data_mode_little_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_glitch_test_little : 1;
        unsigned int reserved_0 : 3;
        unsigned int svfd_test_ffs_little : 8;
        unsigned int svfd_test_cpm_little : 8;
        unsigned int svfd_off_time_step_little : 7;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_glitch_test_little_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_glitch_test_little_END (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_test_ffs_little_START (4)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_test_ffs_little_END (11)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_test_cpm_little_START (12)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_test_cpm_little_END (19)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_off_time_step_little_START (20)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_LITTLE_svfd_off_time_step_little_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_enalbe_mode_little : 2;
        unsigned int svfs_cpm_threshold_r_little : 6;
        unsigned int svfs_cpm_threshold_f_little : 6;
        unsigned int vol_drop_en_little : 1;
        unsigned int svfd_cmp_data_clr_little : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfd_enalbe_mode_little_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfd_enalbe_mode_little_END (1)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfs_cpm_threshold_r_little_START (2)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfs_cpm_threshold_r_little_END (7)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfs_cpm_threshold_f_little_START (8)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfs_cpm_threshold_f_little_END (13)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_vol_drop_en_little_START (14)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_vol_drop_en_little_END (14)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfd_cmp_data_clr_little_START (15)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_svfd_cmp_data_clr_little_END (15)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_bitmasken_START (16)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_LITTLE_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_cpm_data_r_little : 8;
        unsigned int svfd_cpm_data_f_little : 8;
        unsigned int svfd_dll_lock_little : 1;
        unsigned int svfd_cpm_data_norst_little : 6;
        unsigned int reserved : 9;
    } reg;
} SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_r_little_START (0)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_r_little_END (7)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_f_little_START (8)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_f_little_END (15)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_dll_lock_little_START (16)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_dll_lock_little_END (16)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_norst_little_START (17)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_LITTLE_svfd_cpm_data_norst_little_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_test_out_ffs_little : 4;
        unsigned int svfd_test_out_cpm_little : 4;
        unsigned int svfd_glitch_result_little : 1;
        unsigned int idle_low_freq_en_little : 1;
        unsigned int vbat_drop_protect_ind_little : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_svfd_test_out_ffs_little_START (0)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_svfd_test_out_ffs_little_END (3)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_svfd_test_out_cpm_little_START (4)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_svfd_test_out_cpm_little_END (7)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_svfd_glitch_result_little_START (8)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_svfd_glitch_result_little_END (8)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_idle_low_freq_en_little_START (9)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_idle_low_freq_en_little_END (9)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_vbat_drop_protect_ind_little_START (10)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_LITTLE_vbat_drop_protect_ind_little_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_svfd_freq_down_en_little : 1;
        unsigned int sel_svfd_freq_down_en_little : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL3_LITTLE_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_LITTLE_sw_svfd_freq_down_en_little_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_LITTLE_sw_svfd_freq_down_en_little_END (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_LITTLE_sel_svfd_freq_down_en_little_START (1)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_LITTLE_sel_svfd_freq_down_en_little_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vs_ctrl_en_l3 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORECRG_L_L3_VS_CTRL_EN_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CTRL_EN_L3_vs_ctrl_en_l3_START (0)
#define SOC_CORECRG_L_L3_VS_CTRL_EN_L3_vs_ctrl_en_l3_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vs_ctrl_bypass_l3 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CORECRG_L_L3_VS_CTRL_BYPASS_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_L3_vs_ctrl_bypass_l3_START (0)
#define SOC_CORECRG_L_L3_VS_CTRL_BYPASS_L3_vs_ctrl_bypass_l3_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int l3_cpu0_wfi_wfe_bypass : 1;
        unsigned int l3_cpu1_wfi_wfe_bypass : 1;
        unsigned int l3_cpu2_wfi_wfe_bypass : 1;
        unsigned int l3_cpu3_wfi_wfe_bypass : 1;
        unsigned int l3_l2_idle_div_mod : 2;
        unsigned int l3_cfg_cnt_cpu_wake_quit : 16;
        unsigned int l3_cpu_wake_up_mode : 2;
        unsigned int l3_cpu_l2_idle_switch_bypass : 1;
        unsigned int l3_cpu_l2_idle_gt_en : 1;
        unsigned int l3_dvfs_div_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int sel_ckmux_l3_icg : 1;
        unsigned int cpu_clk_div_cfg_l3 : 2;
    } reg;
} SOC_CORECRG_L_L3_VS_CTRL_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu0_wfi_wfe_bypass_START (1)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu0_wfi_wfe_bypass_END (1)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu1_wfi_wfe_bypass_START (2)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu1_wfi_wfe_bypass_END (2)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu2_wfi_wfe_bypass_START (3)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu2_wfi_wfe_bypass_END (3)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu3_wfi_wfe_bypass_START (4)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu3_wfi_wfe_bypass_END (4)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_l2_idle_div_mod_START (5)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_l2_idle_div_mod_END (6)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cfg_cnt_cpu_wake_quit_START (7)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cfg_cnt_cpu_wake_quit_END (22)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu_wake_up_mode_START (23)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu_wake_up_mode_END (24)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu_l2_idle_switch_bypass_START (25)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu_l2_idle_switch_bypass_END (25)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu_l2_idle_gt_en_START (26)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_cpu_l2_idle_gt_en_END (26)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_dvfs_div_en_START (27)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_l3_dvfs_div_en_END (27)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_sel_ckmux_l3_icg_START (29)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_sel_ckmux_l3_icg_END (29)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_cpu_clk_div_cfg_l3_START (30)
#define SOC_CORECRG_L_L3_VS_CTRL_L3_cpu_clk_div_cfg_l3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_data_limit_e_l3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int svfd_pulse_width_sel_l3 : 1;
        unsigned int reserved_1 : 1;
        unsigned int svfd_ulvt_ll_l3 : 4;
        unsigned int svfd_ulvt_sl_l3 : 4;
        unsigned int svfd_lvt_ll_l3 : 4;
        unsigned int svfd_lvt_sl_l3 : 4;
        unsigned int svfd_trim_l3 : 2;
        unsigned int svfd_d_rate1_l3 : 2;
        unsigned int svfd_d_rate_l3 : 2;
        unsigned int svfd_off_mode_l3 : 1;
        unsigned int svfd_div64_en_l3 : 1;
        unsigned int svfd_cpm_period_l3 : 1;
        unsigned int svfd_edge_sel_l3 : 1;
        unsigned int svfd_cmp_data_mode_l3 : 2;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_data_limit_e_l3_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_data_limit_e_l3_END (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_pulse_width_sel_l3_START (2)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_pulse_width_sel_l3_END (2)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_ulvt_ll_l3_START (4)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_ulvt_ll_l3_END (7)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_ulvt_sl_l3_START (8)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_ulvt_sl_l3_END (11)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_lvt_ll_l3_START (12)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_lvt_ll_l3_END (15)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_lvt_sl_l3_START (16)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_lvt_sl_l3_END (19)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_trim_l3_START (20)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_trim_l3_END (21)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_d_rate1_l3_START (22)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_d_rate1_l3_END (23)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_d_rate_l3_START (24)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_d_rate_l3_END (25)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_off_mode_l3_START (26)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_off_mode_l3_END (26)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_div64_en_l3_START (27)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_div64_en_l3_END (27)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_cpm_period_l3_START (28)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_cpm_period_l3_END (28)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_edge_sel_l3_START (29)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_edge_sel_l3_END (29)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_cmp_data_mode_l3_START (30)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL0_L3_svfd_cmp_data_mode_l3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_glitch_test_little : 1;
        unsigned int reserved_0 : 3;
        unsigned int svfd_test_ffs_little : 8;
        unsigned int svfd_test_cpm_little : 8;
        unsigned int svfd_off_time_step_l3 : 7;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_glitch_test_little_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_glitch_test_little_END (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_test_ffs_little_START (4)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_test_ffs_little_END (11)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_test_cpm_little_START (12)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_test_cpm_little_END (19)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_off_time_step_l3_START (20)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL1_L3_svfd_off_time_step_l3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_enalbe_mode_l3 : 2;
        unsigned int svfs_cpm_threshold_r_l3 : 6;
        unsigned int svfs_cpm_threshold_f_l3 : 6;
        unsigned int vol_drop_en_l3 : 1;
        unsigned int svfd_cmp_data_clr_l3 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfd_enalbe_mode_l3_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfd_enalbe_mode_l3_END (1)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfs_cpm_threshold_r_l3_START (2)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfs_cpm_threshold_r_l3_END (7)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfs_cpm_threshold_f_l3_START (8)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfs_cpm_threshold_f_l3_END (13)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_vol_drop_en_l3_START (14)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_vol_drop_en_l3_END (14)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfd_cmp_data_clr_l3_START (15)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_svfd_cmp_data_clr_l3_END (15)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_bitmasken_START (16)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL2_L3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_cpm_data_r_l3 : 8;
        unsigned int svfd_cpm_data_f_l3 : 8;
        unsigned int svfd_dll_lock_l3 : 1;
        unsigned int svfd_cpm_data_norst_l3 : 6;
        unsigned int reserved : 9;
    } reg;
} SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_r_l3_START (0)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_r_l3_END (7)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_f_l3_START (8)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_f_l3_END (15)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_dll_lock_l3_START (16)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_dll_lock_l3_END (16)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_norst_l3_START (17)
#define SOC_CORECRG_L_L3_VS_CPM_DATA_STAT_L3_svfd_cpm_data_norst_l3_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int svfd_test_out_ffs_l3 : 4;
        unsigned int svfd_test_out_cpm_l3 : 4;
        unsigned int svfd_glitch_result_l3 : 1;
        unsigned int idle_low_freq_en_l3 : 1;
        unsigned int vbat_drop_protect_ind_l3 : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_CORECRG_L_L3_VS_TEST_STAT_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_svfd_test_out_ffs_l3_START (0)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_svfd_test_out_ffs_l3_END (3)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_svfd_test_out_cpm_l3_START (4)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_svfd_test_out_cpm_l3_END (7)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_svfd_glitch_result_l3_START (8)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_svfd_glitch_result_l3_END (8)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_idle_low_freq_en_l3_START (9)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_idle_low_freq_en_l3_END (9)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_vbat_drop_protect_ind_l3_START (10)
#define SOC_CORECRG_L_L3_VS_TEST_STAT_L3_vbat_drop_protect_ind_l3_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_svfd_freq_down_en_l3 : 1;
        unsigned int sel_svfd_freq_down_en_l3 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CORECRG_L_L3_VS_SVFD_CTRL3_L3_UNION;
#endif
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_L3_sw_svfd_freq_down_en_l3_START (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_L3_sw_svfd_freq_down_en_l3_END (0)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_L3_sel_svfd_freq_down_en_l3_START (1)
#define SOC_CORECRG_L_L3_VS_SVFD_CTRL3_L3_sel_svfd_freq_down_en_l3_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll0_ssc_reset : 1;
        unsigned int apll0_ssc_disable : 1;
        unsigned int apll0_ssc_downspread : 1;
        unsigned int apll0_ssc_spread : 3;
        unsigned int apll0_ssc_divval : 4;
        unsigned int apll1_ssc_bypass_ssmod_dynammic : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_CORECRG_L_L3_APLL0SSCCTRL_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_reset_START (0)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_reset_END (0)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_disable_START (1)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_disable_END (1)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_downspread_START (2)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_downspread_END (2)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_spread_START (3)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_spread_END (5)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_divval_START (6)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll0_ssc_divval_END (9)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll1_ssc_bypass_ssmod_dynammic_START (10)
#define SOC_CORECRG_L_L3_APLL0SSCCTRL_apll1_ssc_bypass_ssmod_dynammic_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll1_ssc_reset : 1;
        unsigned int apll1_ssc_disable : 1;
        unsigned int apll1_ssc_downspread : 1;
        unsigned int apll1_ssc_spread : 3;
        unsigned int apll1_ssc_divval : 4;
        unsigned int apll1_ssc_bypass_ssmod_dynammic : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_CORECRG_L_L3_APLL1SSCCTRL_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_reset_START (0)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_reset_END (0)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_disable_START (1)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_disable_END (1)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_downspread_START (2)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_downspread_END (2)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_spread_START (3)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_spread_END (5)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_divval_START (6)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_divval_END (9)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_bypass_ssmod_dynammic_START (10)
#define SOC_CORECRG_L_L3_APLL1SSCCTRL_apll1_ssc_bypass_ssmod_dynammic_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_reg_sel : 1;
        unsigned int read_en : 1;
        unsigned int input_cfg_en : 1;
        unsigned int test_mode : 1;
        unsigned int unlock_clear : 1;
        unsigned int dll_en : 1;
        unsigned int pll_lock_ate_sel : 2;
        unsigned int test_data_sel : 4;
        unsigned int bias_ctrl : 2;
        unsigned int icp_ctrl : 2;
        unsigned int updn_sel : 1;
        unsigned int reserved : 2;
        unsigned int int_mask : 3;
        unsigned int pfd_div_ratio : 4;
        unsigned int freq_threshold : 6;
    } reg;
} SOC_CORECRG_L_L3_APLL0_CFG0_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL0_CFG0_sta_reg_sel_START (0)
#define SOC_CORECRG_L_L3_APLL0_CFG0_sta_reg_sel_END (0)
#define SOC_CORECRG_L_L3_APLL0_CFG0_read_en_START (1)
#define SOC_CORECRG_L_L3_APLL0_CFG0_read_en_END (1)
#define SOC_CORECRG_L_L3_APLL0_CFG0_input_cfg_en_START (2)
#define SOC_CORECRG_L_L3_APLL0_CFG0_input_cfg_en_END (2)
#define SOC_CORECRG_L_L3_APLL0_CFG0_test_mode_START (3)
#define SOC_CORECRG_L_L3_APLL0_CFG0_test_mode_END (3)
#define SOC_CORECRG_L_L3_APLL0_CFG0_unlock_clear_START (4)
#define SOC_CORECRG_L_L3_APLL0_CFG0_unlock_clear_END (4)
#define SOC_CORECRG_L_L3_APLL0_CFG0_dll_en_START (5)
#define SOC_CORECRG_L_L3_APLL0_CFG0_dll_en_END (5)
#define SOC_CORECRG_L_L3_APLL0_CFG0_pll_lock_ate_sel_START (6)
#define SOC_CORECRG_L_L3_APLL0_CFG0_pll_lock_ate_sel_END (7)
#define SOC_CORECRG_L_L3_APLL0_CFG0_test_data_sel_START (8)
#define SOC_CORECRG_L_L3_APLL0_CFG0_test_data_sel_END (11)
#define SOC_CORECRG_L_L3_APLL0_CFG0_bias_ctrl_START (12)
#define SOC_CORECRG_L_L3_APLL0_CFG0_bias_ctrl_END (13)
#define SOC_CORECRG_L_L3_APLL0_CFG0_icp_ctrl_START (14)
#define SOC_CORECRG_L_L3_APLL0_CFG0_icp_ctrl_END (15)
#define SOC_CORECRG_L_L3_APLL0_CFG0_updn_sel_START (16)
#define SOC_CORECRG_L_L3_APLL0_CFG0_updn_sel_END (16)
#define SOC_CORECRG_L_L3_APLL0_CFG0_int_mask_START (19)
#define SOC_CORECRG_L_L3_APLL0_CFG0_int_mask_END (21)
#define SOC_CORECRG_L_L3_APLL0_CFG0_pfd_div_ratio_START (22)
#define SOC_CORECRG_L_L3_APLL0_CFG0_pfd_div_ratio_END (25)
#define SOC_CORECRG_L_L3_APLL0_CFG0_freq_threshold_START (26)
#define SOC_CORECRG_L_L3_APLL0_CFG0_freq_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctinue_lock_num : 6;
        unsigned int lock_thr : 2;
        unsigned int dc_ac_clk_en : 1;
        unsigned int dtc_ctrl_inv : 1;
        unsigned int reserved : 6;
        unsigned int ana_cfg_fnpll : 16;
    } reg;
} SOC_CORECRG_L_L3_APLL0_CFG1_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL0_CFG1_ctinue_lock_num_START (0)
#define SOC_CORECRG_L_L3_APLL0_CFG1_ctinue_lock_num_END (5)
#define SOC_CORECRG_L_L3_APLL0_CFG1_lock_thr_START (6)
#define SOC_CORECRG_L_L3_APLL0_CFG1_lock_thr_END (7)
#define SOC_CORECRG_L_L3_APLL0_CFG1_dc_ac_clk_en_START (8)
#define SOC_CORECRG_L_L3_APLL0_CFG1_dc_ac_clk_en_END (8)
#define SOC_CORECRG_L_L3_APLL0_CFG1_dtc_ctrl_inv_START (9)
#define SOC_CORECRG_L_L3_APLL0_CFG1_dtc_ctrl_inv_END (9)
#define SOC_CORECRG_L_L3_APLL0_CFG1_ana_cfg_fnpll_START (16)
#define SOC_CORECRG_L_L3_APLL0_CFG1_ana_cfg_fnpll_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div2_pd : 1;
        unsigned int fbdiv_rst_n : 1;
        unsigned int refdiv_rst_n : 1;
        unsigned int dll_force_en : 1;
        unsigned int phe_code_a : 2;
        unsigned int phe_code_b : 2;
        unsigned int bbpd_calib_byp : 1;
        unsigned int k_gain_cfg_en : 1;
        unsigned int k_gain_cfg : 6;
        unsigned int k_gain_av_thr : 3;
        unsigned int dtc_test : 1;
        unsigned int dtc_m_cfg : 6;
        unsigned int dtc_o_cfg : 6;
    } reg;
} SOC_CORECRG_L_L3_APLL0_CFG2_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL0_CFG2_div2_pd_START (0)
#define SOC_CORECRG_L_L3_APLL0_CFG2_div2_pd_END (0)
#define SOC_CORECRG_L_L3_APLL0_CFG2_fbdiv_rst_n_START (1)
#define SOC_CORECRG_L_L3_APLL0_CFG2_fbdiv_rst_n_END (1)
#define SOC_CORECRG_L_L3_APLL0_CFG2_refdiv_rst_n_START (2)
#define SOC_CORECRG_L_L3_APLL0_CFG2_refdiv_rst_n_END (2)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dll_force_en_START (3)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dll_force_en_END (3)
#define SOC_CORECRG_L_L3_APLL0_CFG2_phe_code_a_START (4)
#define SOC_CORECRG_L_L3_APLL0_CFG2_phe_code_a_END (5)
#define SOC_CORECRG_L_L3_APLL0_CFG2_phe_code_b_START (6)
#define SOC_CORECRG_L_L3_APLL0_CFG2_phe_code_b_END (7)
#define SOC_CORECRG_L_L3_APLL0_CFG2_bbpd_calib_byp_START (8)
#define SOC_CORECRG_L_L3_APLL0_CFG2_bbpd_calib_byp_END (8)
#define SOC_CORECRG_L_L3_APLL0_CFG2_k_gain_cfg_en_START (9)
#define SOC_CORECRG_L_L3_APLL0_CFG2_k_gain_cfg_en_END (9)
#define SOC_CORECRG_L_L3_APLL0_CFG2_k_gain_cfg_START (10)
#define SOC_CORECRG_L_L3_APLL0_CFG2_k_gain_cfg_END (15)
#define SOC_CORECRG_L_L3_APLL0_CFG2_k_gain_av_thr_START (16)
#define SOC_CORECRG_L_L3_APLL0_CFG2_k_gain_av_thr_END (18)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dtc_test_START (19)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dtc_test_END (19)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dtc_m_cfg_START (20)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dtc_m_cfg_END (25)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dtc_o_cfg_START (26)
#define SOC_CORECRG_L_L3_APLL0_CFG2_dtc_o_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_reg_sel : 1;
        unsigned int read_en : 1;
        unsigned int input_cfg_en : 1;
        unsigned int test_mode : 1;
        unsigned int unlock_clear : 1;
        unsigned int dll_en : 1;
        unsigned int pll_lock_ate_sel : 2;
        unsigned int test_data_sel : 4;
        unsigned int bias_ctrl : 2;
        unsigned int icp_ctrl : 2;
        unsigned int updn_sel : 1;
        unsigned int reserved : 2;
        unsigned int int_mask : 3;
        unsigned int pfd_div_ratio : 4;
        unsigned int freq_threshold : 6;
    } reg;
} SOC_CORECRG_L_L3_APLL1_CFG0_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL1_CFG0_sta_reg_sel_START (0)
#define SOC_CORECRG_L_L3_APLL1_CFG0_sta_reg_sel_END (0)
#define SOC_CORECRG_L_L3_APLL1_CFG0_read_en_START (1)
#define SOC_CORECRG_L_L3_APLL1_CFG0_read_en_END (1)
#define SOC_CORECRG_L_L3_APLL1_CFG0_input_cfg_en_START (2)
#define SOC_CORECRG_L_L3_APLL1_CFG0_input_cfg_en_END (2)
#define SOC_CORECRG_L_L3_APLL1_CFG0_test_mode_START (3)
#define SOC_CORECRG_L_L3_APLL1_CFG0_test_mode_END (3)
#define SOC_CORECRG_L_L3_APLL1_CFG0_unlock_clear_START (4)
#define SOC_CORECRG_L_L3_APLL1_CFG0_unlock_clear_END (4)
#define SOC_CORECRG_L_L3_APLL1_CFG0_dll_en_START (5)
#define SOC_CORECRG_L_L3_APLL1_CFG0_dll_en_END (5)
#define SOC_CORECRG_L_L3_APLL1_CFG0_pll_lock_ate_sel_START (6)
#define SOC_CORECRG_L_L3_APLL1_CFG0_pll_lock_ate_sel_END (7)
#define SOC_CORECRG_L_L3_APLL1_CFG0_test_data_sel_START (8)
#define SOC_CORECRG_L_L3_APLL1_CFG0_test_data_sel_END (11)
#define SOC_CORECRG_L_L3_APLL1_CFG0_bias_ctrl_START (12)
#define SOC_CORECRG_L_L3_APLL1_CFG0_bias_ctrl_END (13)
#define SOC_CORECRG_L_L3_APLL1_CFG0_icp_ctrl_START (14)
#define SOC_CORECRG_L_L3_APLL1_CFG0_icp_ctrl_END (15)
#define SOC_CORECRG_L_L3_APLL1_CFG0_updn_sel_START (16)
#define SOC_CORECRG_L_L3_APLL1_CFG0_updn_sel_END (16)
#define SOC_CORECRG_L_L3_APLL1_CFG0_int_mask_START (19)
#define SOC_CORECRG_L_L3_APLL1_CFG0_int_mask_END (21)
#define SOC_CORECRG_L_L3_APLL1_CFG0_pfd_div_ratio_START (22)
#define SOC_CORECRG_L_L3_APLL1_CFG0_pfd_div_ratio_END (25)
#define SOC_CORECRG_L_L3_APLL1_CFG0_freq_threshold_START (26)
#define SOC_CORECRG_L_L3_APLL1_CFG0_freq_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctinue_lock_num : 6;
        unsigned int lock_thr : 2;
        unsigned int dc_ac_clk_en : 1;
        unsigned int dtc_ctrl_inv : 1;
        unsigned int reserved : 6;
        unsigned int ana_cfg_fnpll : 16;
    } reg;
} SOC_CORECRG_L_L3_APLL1_CFG1_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL1_CFG1_ctinue_lock_num_START (0)
#define SOC_CORECRG_L_L3_APLL1_CFG1_ctinue_lock_num_END (5)
#define SOC_CORECRG_L_L3_APLL1_CFG1_lock_thr_START (6)
#define SOC_CORECRG_L_L3_APLL1_CFG1_lock_thr_END (7)
#define SOC_CORECRG_L_L3_APLL1_CFG1_dc_ac_clk_en_START (8)
#define SOC_CORECRG_L_L3_APLL1_CFG1_dc_ac_clk_en_END (8)
#define SOC_CORECRG_L_L3_APLL1_CFG1_dtc_ctrl_inv_START (9)
#define SOC_CORECRG_L_L3_APLL1_CFG1_dtc_ctrl_inv_END (9)
#define SOC_CORECRG_L_L3_APLL1_CFG1_ana_cfg_fnpll_START (16)
#define SOC_CORECRG_L_L3_APLL1_CFG1_ana_cfg_fnpll_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div2_pd : 1;
        unsigned int fbdiv_rst_n : 1;
        unsigned int refdiv_rst_n : 1;
        unsigned int dll_force_en : 1;
        unsigned int phe_code_a : 2;
        unsigned int phe_code_b : 2;
        unsigned int bbpd_calib_byp : 1;
        unsigned int k_gain_cfg_en : 1;
        unsigned int k_gain_cfg : 6;
        unsigned int k_gain_av_thr : 3;
        unsigned int dtc_test : 1;
        unsigned int dtc_m_cfg : 6;
        unsigned int dtc_o_cfg : 6;
    } reg;
} SOC_CORECRG_L_L3_APLL1_CFG2_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL1_CFG2_div2_pd_START (0)
#define SOC_CORECRG_L_L3_APLL1_CFG2_div2_pd_END (0)
#define SOC_CORECRG_L_L3_APLL1_CFG2_fbdiv_rst_n_START (1)
#define SOC_CORECRG_L_L3_APLL1_CFG2_fbdiv_rst_n_END (1)
#define SOC_CORECRG_L_L3_APLL1_CFG2_refdiv_rst_n_START (2)
#define SOC_CORECRG_L_L3_APLL1_CFG2_refdiv_rst_n_END (2)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dll_force_en_START (3)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dll_force_en_END (3)
#define SOC_CORECRG_L_L3_APLL1_CFG2_phe_code_a_START (4)
#define SOC_CORECRG_L_L3_APLL1_CFG2_phe_code_a_END (5)
#define SOC_CORECRG_L_L3_APLL1_CFG2_phe_code_b_START (6)
#define SOC_CORECRG_L_L3_APLL1_CFG2_phe_code_b_END (7)
#define SOC_CORECRG_L_L3_APLL1_CFG2_bbpd_calib_byp_START (8)
#define SOC_CORECRG_L_L3_APLL1_CFG2_bbpd_calib_byp_END (8)
#define SOC_CORECRG_L_L3_APLL1_CFG2_k_gain_cfg_en_START (9)
#define SOC_CORECRG_L_L3_APLL1_CFG2_k_gain_cfg_en_END (9)
#define SOC_CORECRG_L_L3_APLL1_CFG2_k_gain_cfg_START (10)
#define SOC_CORECRG_L_L3_APLL1_CFG2_k_gain_cfg_END (15)
#define SOC_CORECRG_L_L3_APLL1_CFG2_k_gain_av_thr_START (16)
#define SOC_CORECRG_L_L3_APLL1_CFG2_k_gain_av_thr_END (18)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dtc_test_START (19)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dtc_test_END (19)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dtc_m_cfg_START (20)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dtc_m_cfg_END (25)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dtc_o_cfg_START (26)
#define SOC_CORECRG_L_L3_APLL1_CFG2_dtc_o_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_cpu_l3 : 1;
        unsigned int gt_clk_cpu_little : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CORECRG_L_L3_FCM_CLKEN_UNION;
#endif
#define SOC_CORECRG_L_L3_FCM_CLKEN_gt_clk_cpu_l3_START (0)
#define SOC_CORECRG_L_L3_FCM_CLKEN_gt_clk_cpu_l3_END (0)
#define SOC_CORECRG_L_L3_FCM_CLKEN_gt_clk_cpu_little_START (1)
#define SOC_CORECRG_L_L3_FCM_CLKEN_gt_clk_cpu_little_END (1)
#define SOC_CORECRG_L_L3_FCM_CLKEN_bitmasken_START (16)
#define SOC_CORECRG_L_L3_FCM_CLKEN_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CORECRG_L_L3_APLL0_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CORECRG_L_L3_APLL1_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll0_cfg3 : 32;
    } reg;
} SOC_CORECRG_L_L3_APLL0_CFG3_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL0_CFG3_apll0_cfg3_START (0)
#define SOC_CORECRG_L_L3_APLL0_CFG3_apll0_cfg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll1_cfg3 : 32;
    } reg;
} SOC_CORECRG_L_L3_APLL1_CFG3_UNION;
#endif
#define SOC_CORECRG_L_L3_APLL1_CFG3_apll1_cfg3_START (0)
#define SOC_CORECRG_L_L3_APLL1_CFG3_apll1_cfg3_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
