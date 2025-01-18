#ifndef __SOC_FCM_LOCAL_IP_NS_INTERFACE_H__
#define __SOC_FCM_LOCAL_IP_NS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_ADDR(base) ((base) + (0x804UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_ADDR(base) ((base) + (0x808UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_ADDR(base) ((base) + (0x80CUL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_ADDR(base) ((base) + (0x810UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_ADDR(base) ((base) + (0x868UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_ADDR(base) ((base) + (0x86CUL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_ADDR(base) ((base) + (0x870UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0xC18UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0xC1CUL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT8_ADDR(base) ((base) + (0xC20UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_ADDR(base) ((base) + (0xC24UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT10_ADDR(base) ((base) + (0xC28UL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_ADDR(base) ((base) + (0xC2CUL))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_ADDR(base) ((base) + (0xC30UL))
#else
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_ADDR(base) ((base) + (0x804))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_ADDR(base) ((base) + (0x808))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_ADDR(base) ((base) + (0x80C))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_ADDR(base) ((base) + (0x810))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_ADDR(base) ((base) + (0x814))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_ADDR(base) ((base) + (0x868))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_ADDR(base) ((base) + (0x86C))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_ADDR(base) ((base) + (0x870))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0xC18))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0xC1C))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT8_ADDR(base) ((base) + (0xC20))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_ADDR(base) ((base) + (0xC24))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT10_ADDR(base) ((base) + (0xC28))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_ADDR(base) ((base) + (0xC2C))
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_ADDR(base) ((base) + (0xC30))
#endif
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
        unsigned int clkoff_hpm_cpu_middle : 2;
        unsigned int clkoff_hpm_cpu_big : 2;
        unsigned int clkoff_hpm_scu : 1;
        unsigned int reserved_1 : 3;
        unsigned int clken_masken1 : 16;
    } reg;
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_cpu_middle_END (9)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_cpu_big_START (10)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clkoff_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clken_masken1_START (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL1_clken_masken1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clkoff_pa_cpu_little : 1;
        unsigned int clkoff_pa_cpu_big : 1;
        unsigned int clkoff_pa_cpu_middle : 1;
        unsigned int reserved_0 : 1;
        unsigned int clkoff_tidm_cpu_little : 1;
        unsigned int clkoff_tidm_cpu_middle : 1;
        unsigned int clkoff_tidm_cpu_big : 1;
        unsigned int reserved_1 : 9;
        unsigned int clken_masken2 : 16;
    } reg;
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_pa_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_pa_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_pa_cpu_big_START (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_pa_cpu_big_END (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_pa_cpu_middle_START (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_pa_cpu_middle_END (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_tidm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_tidm_cpu_little_END (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_tidm_cpu_middle_START (5)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_tidm_cpu_middle_END (5)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_tidm_cpu_big_START (6)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clkoff_tidm_cpu_big_END (6)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clken_masken2_START (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL2_clken_masken2_END (31)
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
        unsigned int rst_en_hpm_cpu_middle : 2;
        unsigned int rst_en_hpm_cpu_big : 2;
        unsigned int rst_en_hpm_scu : 1;
        unsigned int reserved_1 : 3;
        unsigned int rst_en_pa_cpu_little : 1;
        unsigned int rst_en_pa_cpu_middle : 1;
        unsigned int rst_en_pa_cpu_big : 1;
        unsigned int reserved_2 : 1;
        unsigned int rst_en_tidm_cpu_little : 1;
        unsigned int rst_en_tidm_cpu_middle : 1;
        unsigned int rst_en_tidm_cpu_big : 1;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_cpu_middle_END (9)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_cpu_big_START (10)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_pa_cpu_little_START (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_pa_cpu_little_END (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_pa_cpu_middle_START (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_pa_cpu_middle_END (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_pa_cpu_big_START (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_pa_cpu_big_END (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_tidm_cpu_little_START (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_tidm_cpu_little_END (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_tidm_cpu_middle_START (21)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_tidm_cpu_middle_END (21)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_tidm_cpu_big_START (22)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL3_rst_en_tidm_cpu_big_END (22)
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
        unsigned int rst_dis_hpm_cpu_middle : 2;
        unsigned int rst_dis_hpm_cpu_big : 2;
        unsigned int rst_dis_hpm_scu : 1;
        unsigned int reserved_1 : 3;
        unsigned int rst_dis_pa_cpu_little : 1;
        unsigned int rst_dis_pa_cpu_middle : 1;
        unsigned int rst_dis_pa_cpu_big : 1;
        unsigned int reserved_2 : 1;
        unsigned int rst_dis_tidm_cpu_little : 1;
        unsigned int rst_dis_tidm_cpu_middle : 1;
        unsigned int rst_dis_tidm_cpu_big : 1;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_reserved_0_START (3)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_reserved_0_END (3)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_cpu_middle_END (9)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_cpu_big_START (10)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_pa_cpu_little_START (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_pa_cpu_little_END (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_pa_cpu_middle_START (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_pa_cpu_middle_END (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_pa_cpu_big_START (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_pa_cpu_big_END (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_tidm_cpu_little_START (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_tidm_cpu_little_END (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_tidm_cpu_middle_START (21)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_tidm_cpu_middle_END (21)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_tidm_cpu_big_START (22)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL4_rst_dis_tidm_cpu_big_END (22)
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
        unsigned int rst_stat_hpm_cpu_middle : 2;
        unsigned int rst_stat_hpm_cpu_big : 2;
        unsigned int rst_stat_hpm_scu : 1;
        unsigned int reserved_1 : 3;
        unsigned int rst_stat_pa_cpu_little : 1;
        unsigned int rst_stat_pa_cpu_middle : 1;
        unsigned int rst_stat_pa_cpu_big : 1;
        unsigned int reserved_2 : 1;
        unsigned int rst_stat_tidm_cpu_little : 1;
        unsigned int rst_stat_tidm_cpu_middle : 1;
        unsigned int rst_stat_tidm_cpu_big : 1;
        unsigned int reserved_3 : 9;
    } reg;
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_aps_cpu_little_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_aps_cpu_little_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_aps_cpu_middle_START (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_aps_cpu_middle_END (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_aps_cpu_big_START (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_aps_cpu_big_END (2)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_cpu_little_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_cpu_little_END (7)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_cpu_middle_START (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_cpu_middle_END (9)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_cpu_big_START (10)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_cpu_big_END (11)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_scu_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_hpm_scu_END (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_pa_cpu_little_START (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_pa_cpu_little_END (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_pa_cpu_middle_START (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_pa_cpu_middle_END (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_pa_cpu_big_START (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_pa_cpu_big_END (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_tidm_cpu_little_START (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_tidm_cpu_little_END (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_tidm_cpu_middle_START (21)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_tidm_cpu_middle_END (21)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_tidm_cpu_big_START (22)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL5_rst_stat_tidm_cpu_big_END (22)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_hpm_en_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_hpm_en_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_hpmx_en_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_hpmx_en_END (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_hpm_clk_div_START (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL26_hpm_clk_div_END (13)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_cfg_valid_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_cfg_valid_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_en_START (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_en_END (1)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_cmd_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_cmd_END (5)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_ctrl_START (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_ctrl_END (13)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_msg_START (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL27_pa_msg_END (31)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_tidm_en_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_tidm_en_END (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_tihpm_mode_START (4)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_tihpm_mode_END (6)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_tidm_div_START (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_CTRL28_tidm_div_END (13)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpm_opc_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpm_opc_END (9)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpm_opc_vld_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpm_opc_vld_END (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpmx_opc_START (16)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpmx_opc_END (25)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpmx_opc_vld_START (28)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT6_fcm_hpmx_opc_vld_END (28)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_hci_a_out_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_hci_a_out_END (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_hci_o_out_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_hci_o_out_END (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_valid_START (24)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_valid_END (24)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_cfg_ready_START (28)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT7_pasensor_cfg_ready_END (28)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT8_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT8_pasensor_nbti_a_out_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT8_pasensor_nbti_a_out_END (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT8_pasensor_nbti_o_out_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT8_pasensor_nbti_o_out_END (20)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_hci_a_out_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_hci_a_out_END (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_hci_o_out_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_hci_o_out_END (20)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_valid_START (24)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_valid_END (24)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_cfg_ready_START (28)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT9_pasensor_cfg_ready_END (28)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT10_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT10_pasensor_nbti_a_out_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT10_pasensor_nbti_a_out_END (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT10_pasensor_nbti_o_out_START (12)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT10_pasensor_nbti_o_out_END (20)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_hpm_code_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_hpm_code_END (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_hpmx_code_START (9)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_hpmx_code_END (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_tihpm_code_START (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_tihpm_code_END (26)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_finish_valid_START (31)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT11_tidm_finish_valid_END (31)
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
} SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_UNION;
#endif
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_hpm_code_START (0)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_hpm_code_END (8)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_hpmx_code_START (9)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_hpmx_code_END (17)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_tihpm_code_START (18)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_tihpm_code_END (26)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_finish_valid_START (31)
#define SOC_FCM_LOCAL_IP_NS_FCM_LOCAL_STAT12_tidm_finish_valid_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
