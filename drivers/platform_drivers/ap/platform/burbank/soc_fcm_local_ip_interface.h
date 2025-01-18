#ifndef __SOC_FCM_LOCAL_IP_INTERFACE_H__
#define __SOC_FCM_LOCAL_IP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_IP_CTRL0_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_LOCAL_IP_CLKEN1_ADDR(base) ((base) + (0x804UL))
#define SOC_FCM_LOCAL_IP_CLKEN2_ADDR(base) ((base) + (0x808UL))
#define SOC_FCM_LOCAL_IP_RST_EN_ADDR(base) ((base) + (0x80CUL))
#define SOC_FCM_LOCAL_IP_RST_DIS_ADDR(base) ((base) + (0x810UL))
#define SOC_FCM_LOCAL_IP_RST_STAT_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_LOCAL_IP_CTRL4_ADDR(base) ((base) + (0x818UL))
#define SOC_FCM_LOCAL_IP_CTRL5_ADDR(base) ((base) + (0x81CUL))
#define SOC_FCM_LOCAL_IP_CTRL6_ADDR(base) ((base) + (0x820UL))
#define SOC_FCM_LOCAL_IP_CTRL7_ADDR(base) ((base) + (0x824UL))
#define SOC_FCM_LOCAL_IP_CTRL8_ADDR(base) ((base) + (0x828UL))
#define SOC_FCM_LOCAL_IP_CTRL9_ADDR(base) ((base) + (0x82CUL))
#define SOC_FCM_LOCAL_IP_CTRL10_ADDR(base) ((base) + (0x830UL))
#define SOC_FCM_LOCAL_IP_CTRL11_ADDR(base) ((base) + (0x834UL))
#define SOC_FCM_LOCAL_IP_CTRL12_ADDR(base) ((base) + (0x838UL))
#define SOC_FCM_LOCAL_IP_CTRL13_ADDR(base) ((base) + (0x83CUL))
#define SOC_FCM_LOCAL_IP_CTRL14_ADDR(base) ((base) + (0x840UL))
#define SOC_FCM_LOCAL_IP_STAT0_ADDR(base) ((base) + (0xC00UL))
#define SOC_FCM_LOCAL_IP_STAT1_ADDR(base) ((base) + (0xC04UL))
#define SOC_FCM_LOCAL_IP_STAT2_ADDR(base) ((base) + (0xC08UL))
#define SOC_FCM_LOCAL_IP_STAT3_ADDR(base) ((base) + (0xC0CUL))
#define SOC_FCM_LOCAL_IP_STAT4_ADDR(base) ((base) + (0xC10UL))
#define SOC_FCM_LOCAL_IP_STAT5_ADDR(base) ((base) + (0xC14UL))
#define SOC_FCM_LOCAL_IP_STAT6_ADDR(base) ((base) + (0xC18UL))
#define SOC_FCM_LOCAL_IP_STAT7_ADDR(base) ((base) + (0xC1CUL))
#define SOC_FCM_LOCAL_IP_STAT8_ADDR(base) ((base) + (0xC20UL))
#define SOC_FCM_LOCAL_IP_STAT9_ADDR(base) ((base) + (0xC24UL))
#else
#define SOC_FCM_LOCAL_IP_CTRL0_ADDR(base) ((base) + (0x800))
#define SOC_FCM_LOCAL_IP_CLKEN1_ADDR(base) ((base) + (0x804))
#define SOC_FCM_LOCAL_IP_CLKEN2_ADDR(base) ((base) + (0x808))
#define SOC_FCM_LOCAL_IP_RST_EN_ADDR(base) ((base) + (0x80C))
#define SOC_FCM_LOCAL_IP_RST_DIS_ADDR(base) ((base) + (0x810))
#define SOC_FCM_LOCAL_IP_RST_STAT_ADDR(base) ((base) + (0x814))
#define SOC_FCM_LOCAL_IP_CTRL4_ADDR(base) ((base) + (0x818))
#define SOC_FCM_LOCAL_IP_CTRL5_ADDR(base) ((base) + (0x81C))
#define SOC_FCM_LOCAL_IP_CTRL6_ADDR(base) ((base) + (0x820))
#define SOC_FCM_LOCAL_IP_CTRL7_ADDR(base) ((base) + (0x824))
#define SOC_FCM_LOCAL_IP_CTRL8_ADDR(base) ((base) + (0x828))
#define SOC_FCM_LOCAL_IP_CTRL9_ADDR(base) ((base) + (0x82C))
#define SOC_FCM_LOCAL_IP_CTRL10_ADDR(base) ((base) + (0x830))
#define SOC_FCM_LOCAL_IP_CTRL11_ADDR(base) ((base) + (0x834))
#define SOC_FCM_LOCAL_IP_CTRL12_ADDR(base) ((base) + (0x838))
#define SOC_FCM_LOCAL_IP_CTRL13_ADDR(base) ((base) + (0x83C))
#define SOC_FCM_LOCAL_IP_CTRL14_ADDR(base) ((base) + (0x840))
#define SOC_FCM_LOCAL_IP_STAT0_ADDR(base) ((base) + (0xC00))
#define SOC_FCM_LOCAL_IP_STAT1_ADDR(base) ((base) + (0xC04))
#define SOC_FCM_LOCAL_IP_STAT2_ADDR(base) ((base) + (0xC08))
#define SOC_FCM_LOCAL_IP_STAT3_ADDR(base) ((base) + (0xC0C))
#define SOC_FCM_LOCAL_IP_STAT4_ADDR(base) ((base) + (0xC10))
#define SOC_FCM_LOCAL_IP_STAT5_ADDR(base) ((base) + (0xC14))
#define SOC_FCM_LOCAL_IP_STAT6_ADDR(base) ((base) + (0xC18))
#define SOC_FCM_LOCAL_IP_STAT7_ADDR(base) ((base) + (0xC1C))
#define SOC_FCM_LOCAL_IP_STAT8_ADDR(base) ((base) + (0xC20))
#define SOC_FCM_LOCAL_IP_STAT9_ADDR(base) ((base) + (0xC24))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clkdiv_aps_cpu_little : 6;
        unsigned int reserved_0 : 2;
        unsigned int clkdiv_aps_cpu_middle : 6;
        unsigned int reserved_1 : 2;
        unsigned int clkdiv_aps_cpu_big : 6;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL0_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL0_clkdiv_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_CTRL0_clkdiv_aps_cpu_little_END (5)
#define SOC_FCM_LOCAL_IP_CTRL0_clkdiv_aps_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_CTRL0_clkdiv_aps_cpu_middle_END (13)
#define SOC_FCM_LOCAL_IP_CTRL0_clkdiv_aps_cpu_big_START (16)
#define SOC_FCM_LOCAL_IP_CTRL0_clkdiv_aps_cpu_big_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clkoff_aps_cpu_little : 1;
        unsigned int clkoff_aps_cpu_middle : 1;
        unsigned int clkoff_aps_cpu_big : 1;
        unsigned int reserved_0 : 1;
        unsigned int clkoff_hpm_cpu_little : 4;
        unsigned int clkoff_hpm_cpu_middle : 3;
        unsigned int clkoff_hpm_cpu_big : 1;
        unsigned int clkoff_hpm_scu : 1;
        unsigned int reserved_1 : 3;
        unsigned int clken_masken1 : 16;
    } reg;
} SOC_FCM_LOCAL_IP_CLKEN1_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_middle_END (10)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_big_START (11)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_CLKEN1_clken_masken1_START (16)
#define SOC_FCM_LOCAL_IP_CLKEN1_clken_masken1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clkoff_pa_cpu_little : 1;
        unsigned int clkoff_pa_cpu_big : 1;
        unsigned int reserved_0 : 6;
        unsigned int clkoff_pcr_m : 1;
        unsigned int reserved_1 : 7;
        unsigned int clken_masken2 : 16;
    } reg;
} SOC_FCM_LOCAL_IP_CLKEN2_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CLKEN2_clkoff_pa_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_CLKEN2_clkoff_pa_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_CLKEN2_clkoff_pa_cpu_big_START (1)
#define SOC_FCM_LOCAL_IP_CLKEN2_clkoff_pa_cpu_big_END (1)
#define SOC_FCM_LOCAL_IP_CLKEN2_clkoff_pcr_m_START (8)
#define SOC_FCM_LOCAL_IP_CLKEN2_clkoff_pcr_m_END (8)
#define SOC_FCM_LOCAL_IP_CLKEN2_clken_masken2_START (16)
#define SOC_FCM_LOCAL_IP_CLKEN2_clken_masken2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_en_aps_cpu_little : 1;
        unsigned int rst_en_aps_cpu_middle : 1;
        unsigned int rst_en_aps_cpu_big : 1;
        unsigned int reserved_0 : 1;
        unsigned int rst_en_hpm_cpu_little : 4;
        unsigned int rst_en_hpm_cpu_middle : 3;
        unsigned int rst_en_hpm_cpu_big : 1;
        unsigned int rst_en_hpm_scu : 1;
        unsigned int reserved_1 : 1;
        unsigned int rst_en_pcr_m : 1;
        unsigned int reserved_2 : 1;
        unsigned int rst_en_pa_cpu_little : 1;
        unsigned int reserved_3 : 1;
        unsigned int rst_en_pa_cpu_big : 1;
        unsigned int reserved_4 : 13;
    } reg;
} SOC_FCM_LOCAL_IP_RST_EN_UNION;
#endif
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_middle_END (10)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_big_START (11)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_pcr_m_START (14)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_pcr_m_END (14)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_pa_cpu_little_START (16)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_pa_cpu_little_END (16)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_pa_cpu_big_START (18)
#define SOC_FCM_LOCAL_IP_RST_EN_rst_en_pa_cpu_big_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_dis_aps_cpu_little : 1;
        unsigned int rst_dis_aps_cpu_middle : 1;
        unsigned int rst_dis_aps_cpu_big : 1;
        unsigned int reserved_0 : 1;
        unsigned int rst_dis_hpm_cpu_little : 4;
        unsigned int rst_dis_hpm_cpu_middle : 3;
        unsigned int rst_dis_hpm_cpu_big : 1;
        unsigned int rst_dis_hpm_scu : 1;
        unsigned int reserved_1 : 1;
        unsigned int rst_dis_pcr_m : 1;
        unsigned int reserved_2 : 1;
        unsigned int rst_dis_pa_cpu_little : 1;
        unsigned int reserved_3 : 1;
        unsigned int rst_dis_pa_cpu_big : 1;
        unsigned int reserved_4 : 13;
    } reg;
} SOC_FCM_LOCAL_IP_RST_DIS_UNION;
#endif
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_cpu_middle_END (10)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_cpu_big_START (11)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_pcr_m_START (14)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_pcr_m_END (14)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_pa_cpu_little_START (16)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_pa_cpu_little_END (16)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_pa_cpu_big_START (18)
#define SOC_FCM_LOCAL_IP_RST_DIS_rst_dis_pa_cpu_big_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_stat_aps_cpu_little : 1;
        unsigned int rst_stat_aps_cpu_middle : 1;
        unsigned int rst_stat_aps_cpu_big : 1;
        unsigned int reserved_0 : 1;
        unsigned int rst_stat_hpm_cpu_little : 4;
        unsigned int rst_stat_hpm_cpu_middle : 3;
        unsigned int rst_stat_hpm_cpu_big : 1;
        unsigned int rst_stat_hpm_scu : 1;
        unsigned int reserved_1 : 1;
        unsigned int rst_stat_pcr_m : 1;
        unsigned int reserved_2 : 1;
        unsigned int rst_stat_pa_cpu_little : 1;
        unsigned int reserved_3 : 1;
        unsigned int rst_en_pa_cpu_big : 1;
        unsigned int reserved_4 : 13;
    } reg;
} SOC_FCM_LOCAL_IP_RST_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_cpu_middle_END (10)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_cpu_big_START (11)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_pcr_m_START (14)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_pcr_m_END (14)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_pa_cpu_little_START (16)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_stat_pa_cpu_little_END (16)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_en_pa_cpu_big_START (18)
#define SOC_FCM_LOCAL_IP_RST_STAT_rst_en_pa_cpu_big_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int asp_power_reg_cpu : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL4_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL4_asp_power_reg_cpu_START (0)
#define SOC_FCM_LOCAL_IP_CTRL4_asp_power_reg_cpu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int hpmx_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpm_clk_div : 6;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL5_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL5_hpm_en_START (0)
#define SOC_FCM_LOCAL_IP_CTRL5_hpm_en_END (0)
#define SOC_FCM_LOCAL_IP_CTRL5_hpmx_en_START (4)
#define SOC_FCM_LOCAL_IP_CTRL5_hpmx_en_END (4)
#define SOC_FCM_LOCAL_IP_CTRL5_hpm_clk_div_START (8)
#define SOC_FCM_LOCAL_IP_CTRL5_hpm_clk_div_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pa_cfg_valid : 1;
        unsigned int pa_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int pa_cmd : 2;
        unsigned int reserved_1 : 2;
        unsigned int pa_ctrl : 6;
        unsigned int reserved_2 : 2;
        unsigned int pa_msg : 16;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL6_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL6_pa_cfg_valid_START (0)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_cfg_valid_END (0)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_en_START (1)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_en_END (1)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_cmd_START (4)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_cmd_END (5)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_ctrl_START (8)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_ctrl_END (13)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_msg_START (16)
#define SOC_FCM_LOCAL_IP_CTRL6_pa_msg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tidm_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tihpm_mode : 3;
        unsigned int reserved_1 : 1;
        unsigned int tidm_div : 6;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL7_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL7_tidm_en_START (0)
#define SOC_FCM_LOCAL_IP_CTRL7_tidm_en_END (0)
#define SOC_FCM_LOCAL_IP_CTRL7_tihpm_mode_START (4)
#define SOC_FCM_LOCAL_IP_CTRL7_tihpm_mode_END (6)
#define SOC_FCM_LOCAL_IP_CTRL7_tidm_div_START (8)
#define SOC_FCM_LOCAL_IP_CTRL7_tidm_div_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_parameter_a : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL8_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL8_pcrtr_mid_parameter_a_START (0)
#define SOC_FCM_LOCAL_IP_CTRL8_pcrtr_mid_parameter_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_parameter_b : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL9_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL9_pcrtr_mid_parameter_b_START (0)
#define SOC_FCM_LOCAL_IP_CTRL9_pcrtr_mid_parameter_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_parameter_c : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL10_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL10_pcrtr_mid_parameter_c_START (0)
#define SOC_FCM_LOCAL_IP_CTRL10_pcrtr_mid_parameter_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_big_parameter_a : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL11_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL11_pcrtr_big_parameter_a_START (0)
#define SOC_FCM_LOCAL_IP_CTRL11_pcrtr_big_parameter_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_big_parameter_b : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL12_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL12_pcrtr_big_parameter_b_START (0)
#define SOC_FCM_LOCAL_IP_CTRL12_pcrtr_big_parameter_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_big_parameter_c : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL13_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL13_pcrtr_big_parameter_c_START (0)
#define SOC_FCM_LOCAL_IP_CTRL13_pcrtr_big_parameter_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_parameter_vld : 1;
        unsigned int pcrtr_big_parameter_vld : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL14_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL14_pcrtr_mid_parameter_vld_START (0)
#define SOC_FCM_LOCAL_IP_CTRL14_pcrtr_mid_parameter_vld_END (0)
#define SOC_FCM_LOCAL_IP_CTRL14_pcrtr_big_parameter_vld_START (1)
#define SOC_FCM_LOCAL_IP_CTRL14_pcrtr_big_parameter_vld_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_hpm_opc : 10;
        unsigned int reserved_0 : 2;
        unsigned int fcm_hpm_opc_vld : 1;
        unsigned int reserved_1 : 3;
        unsigned int fcm_hpmx_opc : 10;
        unsigned int reserved_2 : 2;
        unsigned int fcm_hpmx_opc_vld : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_IP_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpm_opc_START (0)
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpm_opc_END (9)
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpm_opc_vld_START (12)
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpm_opc_vld_END (12)
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpmx_opc_START (16)
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpmx_opc_END (25)
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpmx_opc_vld_START (28)
#define SOC_FCM_LOCAL_IP_STAT0_fcm_hpmx_opc_vld_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_hci_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_IP_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_hci_a_out_START (0)
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_hci_a_out_END (8)
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_hci_o_out_START (12)
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_hci_o_out_END (20)
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_valid_START (24)
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_valid_END (24)
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_cfg_ready_START (28)
#define SOC_FCM_LOCAL_IP_STAT1_pasensor_cfg_ready_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_nbti_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_FCM_LOCAL_IP_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT2_pasensor_nbti_a_out_START (0)
#define SOC_FCM_LOCAL_IP_STAT2_pasensor_nbti_a_out_END (8)
#define SOC_FCM_LOCAL_IP_STAT2_pasensor_nbti_o_out_START (12)
#define SOC_FCM_LOCAL_IP_STAT2_pasensor_nbti_o_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_hci_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_IP_STAT3_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_hci_a_out_START (0)
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_hci_a_out_END (8)
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_hci_o_out_START (12)
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_hci_o_out_END (20)
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_valid_START (24)
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_valid_END (24)
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_cfg_ready_START (28)
#define SOC_FCM_LOCAL_IP_STAT3_pasensor_cfg_ready_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_nbti_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_FCM_LOCAL_IP_STAT4_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT4_pasensor_nbti_a_out_START (0)
#define SOC_FCM_LOCAL_IP_STAT4_pasensor_nbti_a_out_END (8)
#define SOC_FCM_LOCAL_IP_STAT4_pasensor_nbti_o_out_START (12)
#define SOC_FCM_LOCAL_IP_STAT4_pasensor_nbti_o_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_hci_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_hci_o_out : 9;
        unsigned int reserved_1 : 3;
        unsigned int pasensor_valid : 1;
        unsigned int reserved_2 : 3;
        unsigned int pasensor_cfg_ready : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_IP_STAT5_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_hci_a_out_START (0)
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_hci_a_out_END (8)
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_hci_o_out_START (12)
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_hci_o_out_END (20)
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_valid_START (24)
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_valid_END (24)
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_cfg_ready_START (28)
#define SOC_FCM_LOCAL_IP_STAT5_pasensor_cfg_ready_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_nbti_a_out : 9;
        unsigned int reserved_0 : 3;
        unsigned int pasensor_nbti_o_out : 9;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_FCM_LOCAL_IP_STAT6_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT6_pasensor_nbti_a_out_START (0)
#define SOC_FCM_LOCAL_IP_STAT6_pasensor_nbti_a_out_END (8)
#define SOC_FCM_LOCAL_IP_STAT6_pasensor_nbti_o_out_START (12)
#define SOC_FCM_LOCAL_IP_STAT6_pasensor_nbti_o_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tidm_hpm_code : 9;
        unsigned int tidm_hpmx_code : 9;
        unsigned int tidm_tihpm_code : 9;
        unsigned int reserved : 4;
        unsigned int tidm_finish_valid : 1;
    } reg;
} SOC_FCM_LOCAL_IP_STAT7_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT7_tidm_hpm_code_START (0)
#define SOC_FCM_LOCAL_IP_STAT7_tidm_hpm_code_END (8)
#define SOC_FCM_LOCAL_IP_STAT7_tidm_hpmx_code_START (9)
#define SOC_FCM_LOCAL_IP_STAT7_tidm_hpmx_code_END (17)
#define SOC_FCM_LOCAL_IP_STAT7_tidm_tihpm_code_START (18)
#define SOC_FCM_LOCAL_IP_STAT7_tidm_tihpm_code_END (26)
#define SOC_FCM_LOCAL_IP_STAT7_tidm_finish_valid_START (31)
#define SOC_FCM_LOCAL_IP_STAT7_tidm_finish_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tidm_hpm_code : 9;
        unsigned int tidm_hpmx_code : 9;
        unsigned int tidm_tihpm_code : 9;
        unsigned int reserved : 4;
        unsigned int tidm_finish_valid : 1;
    } reg;
} SOC_FCM_LOCAL_IP_STAT8_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT8_tidm_hpm_code_START (0)
#define SOC_FCM_LOCAL_IP_STAT8_tidm_hpm_code_END (8)
#define SOC_FCM_LOCAL_IP_STAT8_tidm_hpmx_code_START (9)
#define SOC_FCM_LOCAL_IP_STAT8_tidm_hpmx_code_END (17)
#define SOC_FCM_LOCAL_IP_STAT8_tidm_tihpm_code_START (18)
#define SOC_FCM_LOCAL_IP_STAT8_tidm_tihpm_code_END (26)
#define SOC_FCM_LOCAL_IP_STAT8_tidm_finish_valid_START (31)
#define SOC_FCM_LOCAL_IP_STAT8_tidm_finish_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tidm_hpm_code : 9;
        unsigned int tidm_hpmx_code : 9;
        unsigned int tidm_tihpm_code : 9;
        unsigned int reserved : 4;
        unsigned int tidm_finish_valid : 1;
    } reg;
} SOC_FCM_LOCAL_IP_STAT9_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT9_tidm_hpm_code_START (0)
#define SOC_FCM_LOCAL_IP_STAT9_tidm_hpm_code_END (8)
#define SOC_FCM_LOCAL_IP_STAT9_tidm_hpmx_code_START (9)
#define SOC_FCM_LOCAL_IP_STAT9_tidm_hpmx_code_END (17)
#define SOC_FCM_LOCAL_IP_STAT9_tidm_tihpm_code_START (18)
#define SOC_FCM_LOCAL_IP_STAT9_tidm_tihpm_code_END (26)
#define SOC_FCM_LOCAL_IP_STAT9_tidm_finish_valid_START (31)
#define SOC_FCM_LOCAL_IP_STAT9_tidm_finish_valid_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
