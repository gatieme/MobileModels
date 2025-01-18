#ifndef __SOC_FCM_LOCAL_CPU_INTERFACE_H__
#define __SOC_FCM_LOCAL_CPU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_CPU_CTRL0_ADDR(base) ((base) + (0x000UL))
#define SOC_FCM_LOCAL_CPU_CTRL1_ADDR(base) ((base) + (0x004UL))
#define SOC_FCM_LOCAL_CPU_CTRL2_ADDR(base) ((base) + (0x008UL))
#define SOC_FCM_LOCAL_CPU_CTRL3_ADDR(base) ((base) + (0x00CUL))
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_ADDR(base) ((base) + (0x010UL))
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_ADDR(base) ((base) + (0x014UL))
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_ADDR(base) ((base) + (0x018UL))
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_ADDR(base) ((base) + (0x01CUL))
#define SOC_FCM_LOCAL_CPU_CTRL6_ADDR(base) ((base) + (0x020UL))
#define SOC_FCM_LOCAL_CPU_CTRL7_ADDR(base) ((base) + (0x024UL))
#define SOC_FCM_LOCAL_CPU_CTRL8_ADDR(base) ((base) + (0x028UL))
#define SOC_FCM_LOCAL_CPU_CTRL9_ADDR(base) ((base) + (0x02CUL))
#define SOC_FCM_LOCAL_CPU_CTRL10_ADDR(base) ((base) + (0x030UL))
#define SOC_FCM_LOCAL_CPU_CTRL11_ADDR(base) ((base) + (0x034UL))
#define SOC_FCM_LOCAL_CPU_CTRL12_ADDR(base) ((base) + (0x038UL))
#define SOC_FCM_LOCAL_CPU_CTRL13_ADDR(base) ((base) + (0x03CUL))
#define SOC_FCM_LOCAL_CPU_CTRL14_ADDR(base) ((base) + (0x040UL))
#define SOC_FCM_LOCAL_CPU_CTRL15_ADDR(base) ((base) + (0x044UL))
#define SOC_FCM_LOCAL_CPU_CTRL16_ADDR(base) ((base) + (0x048UL))
#define SOC_FCM_LOCAL_CPU_CTRL17_ADDR(base) ((base) + (0x04CUL))
#define SOC_FCM_LOCAL_CPU_CTRL18_ADDR(base) ((base) + (0x050UL))
#define SOC_FCM_LOCAL_CPU_CTRL19_ADDR(base) ((base) + (0x054UL))
#define SOC_FCM_LOCAL_CPU_STAT0_ADDR(base) ((base) + (0x200UL))
#define SOC_FCM_LOCAL_CPU_STAT1_ADDR(base) ((base) + (0x204UL))
#define SOC_FCM_LOCAL_CPU_STAT2_ADDR(base) ((base) + (0x208UL))
#define SOC_FCM_LOCAL_CPU_STAT3_ADDR(base) ((base) + (0x20CUL))
#define SOC_FCM_LOCAL_CPU_STAT4_ADDR(base) ((base) + (0x210UL))
#define SOC_FCM_LOCAL_CPU_STAT5_ADDR(base) ((base) + (0x214UL))
#define SOC_FCM_LOCAL_CPU_STAT6_ADDR(base) ((base) + (0x218UL))
#define SOC_FCM_LOCAL_CPU_STAT7_ADDR(base) ((base) + (0x21CUL))
#define SOC_FCM_LOCAL_CPU_STAT8_ADDR(base) ((base) + (0x220UL))
#define SOC_FCM_LOCAL_CPU_STAT9_ADDR(base) ((base) + (0x224UL))
#define SOC_FCM_LOCAL_CPU_STAT10_ADDR(base) ((base) + (0x228UL))
#define SOC_FCM_LOCAL_CPU_STAT11_ADDR(base) ((base) + (0x22CUL))
#define SOC_FCM_LOCAL_CPU_STAT12_ADDR(base) ((base) + (0x230UL))
#define SOC_FCM_LOCAL_CPU_STAT13_ADDR(base) ((base) + (0x234UL))
#define SOC_FCM_LOCAL_CPU_STAT14_ADDR(base) ((base) + (0x238UL))
#define SOC_FCM_LOCAL_CPU_STAT15_ADDR(base) ((base) + (0x23CUL))
#define SOC_FCM_LOCAL_CPU_STAT16_ADDR(base) ((base) + (0x240UL))
#define SOC_FCM_LOCAL_CPU_STAT17_ADDR(base) ((base) + (0x244UL))
#define SOC_FCM_LOCAL_CPU_STAT18_ADDR(base) ((base) + (0x248UL))
#define SOC_FCM_LOCAL_CPU_STAT19_ADDR(base) ((base) + (0x24CUL))
#else
#define SOC_FCM_LOCAL_CPU_CTRL0_ADDR(base) ((base) + (0x000))
#define SOC_FCM_LOCAL_CPU_CTRL1_ADDR(base) ((base) + (0x004))
#define SOC_FCM_LOCAL_CPU_CTRL2_ADDR(base) ((base) + (0x008))
#define SOC_FCM_LOCAL_CPU_CTRL3_ADDR(base) ((base) + (0x00C))
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_ADDR(base) ((base) + (0x010))
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_ADDR(base) ((base) + (0x014))
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_ADDR(base) ((base) + (0x018))
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_ADDR(base) ((base) + (0x01C))
#define SOC_FCM_LOCAL_CPU_CTRL6_ADDR(base) ((base) + (0x020))
#define SOC_FCM_LOCAL_CPU_CTRL7_ADDR(base) ((base) + (0x024))
#define SOC_FCM_LOCAL_CPU_CTRL8_ADDR(base) ((base) + (0x028))
#define SOC_FCM_LOCAL_CPU_CTRL9_ADDR(base) ((base) + (0x02C))
#define SOC_FCM_LOCAL_CPU_CTRL10_ADDR(base) ((base) + (0x030))
#define SOC_FCM_LOCAL_CPU_CTRL11_ADDR(base) ((base) + (0x034))
#define SOC_FCM_LOCAL_CPU_CTRL12_ADDR(base) ((base) + (0x038))
#define SOC_FCM_LOCAL_CPU_CTRL13_ADDR(base) ((base) + (0x03C))
#define SOC_FCM_LOCAL_CPU_CTRL14_ADDR(base) ((base) + (0x040))
#define SOC_FCM_LOCAL_CPU_CTRL15_ADDR(base) ((base) + (0x044))
#define SOC_FCM_LOCAL_CPU_CTRL16_ADDR(base) ((base) + (0x048))
#define SOC_FCM_LOCAL_CPU_CTRL17_ADDR(base) ((base) + (0x04C))
#define SOC_FCM_LOCAL_CPU_CTRL18_ADDR(base) ((base) + (0x050))
#define SOC_FCM_LOCAL_CPU_CTRL19_ADDR(base) ((base) + (0x054))
#define SOC_FCM_LOCAL_CPU_STAT0_ADDR(base) ((base) + (0x200))
#define SOC_FCM_LOCAL_CPU_STAT1_ADDR(base) ((base) + (0x204))
#define SOC_FCM_LOCAL_CPU_STAT2_ADDR(base) ((base) + (0x208))
#define SOC_FCM_LOCAL_CPU_STAT3_ADDR(base) ((base) + (0x20C))
#define SOC_FCM_LOCAL_CPU_STAT4_ADDR(base) ((base) + (0x210))
#define SOC_FCM_LOCAL_CPU_STAT5_ADDR(base) ((base) + (0x214))
#define SOC_FCM_LOCAL_CPU_STAT6_ADDR(base) ((base) + (0x218))
#define SOC_FCM_LOCAL_CPU_STAT7_ADDR(base) ((base) + (0x21C))
#define SOC_FCM_LOCAL_CPU_STAT8_ADDR(base) ((base) + (0x220))
#define SOC_FCM_LOCAL_CPU_STAT9_ADDR(base) ((base) + (0x224))
#define SOC_FCM_LOCAL_CPU_STAT10_ADDR(base) ((base) + (0x228))
#define SOC_FCM_LOCAL_CPU_STAT11_ADDR(base) ((base) + (0x22C))
#define SOC_FCM_LOCAL_CPU_STAT12_ADDR(base) ((base) + (0x230))
#define SOC_FCM_LOCAL_CPU_STAT13_ADDR(base) ((base) + (0x234))
#define SOC_FCM_LOCAL_CPU_STAT14_ADDR(base) ((base) + (0x238))
#define SOC_FCM_LOCAL_CPU_STAT15_ADDR(base) ((base) + (0x23C))
#define SOC_FCM_LOCAL_CPU_STAT16_ADDR(base) ((base) + (0x240))
#define SOC_FCM_LOCAL_CPU_STAT17_ADDR(base) ((base) + (0x244))
#define SOC_FCM_LOCAL_CPU_STAT18_ADDR(base) ((base) + (0x248))
#define SOC_FCM_LOCAL_CPU_STAT19_ADDR(base) ((base) + (0x24C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_sclk_q_channel_en : 1;
        unsigned int fcm_atclk_q_channel_en : 1;
        unsigned int fcm_pclk_q_channel_en : 1;
        unsigned int fcm_gicclk_q_channel_en : 1;
        unsigned int fcm_debug_clk_q_channel_en : 1;
        unsigned int fcm_debug_pwr_q_channel_qreqn : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL0_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_sclk_q_channel_en_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_sclk_q_channel_en_END (0)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_atclk_q_channel_en_START (1)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_atclk_q_channel_en_END (1)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_pclk_q_channel_en_START (2)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_pclk_q_channel_en_END (2)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_gicclk_q_channel_en_START (3)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_gicclk_q_channel_en_END (3)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_debug_clk_q_channel_en_START (4)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_debug_clk_q_channel_en_END (4)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_debug_pwr_q_channel_qreqn_START (5)
#define SOC_FCM_LOCAL_CPU_CTRL0_fcm_debug_pwr_q_channel_qreqn_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_sclk_q_channel_cfgcnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int fcm_atclk_q_channel_cfgcnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int fcm_pclk_q_channel_cfgcnt : 7;
        unsigned int reserved_2 : 1;
        unsigned int fcm_gicclk_q_channel_cfgcnt : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL1_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_sclk_q_channel_cfgcnt_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_sclk_q_channel_cfgcnt_END (6)
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_atclk_q_channel_cfgcnt_START (8)
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_atclk_q_channel_cfgcnt_END (14)
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_pclk_q_channel_cfgcnt_START (16)
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_pclk_q_channel_cfgcnt_END (22)
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_gicclk_q_channel_cfgcnt_START (24)
#define SOC_FCM_LOCAL_CPU_CTRL1_fcm_gicclk_q_channel_cfgcnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_debug_clk_q_channel_cfgcnt : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL2_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL2_fcm_debug_clk_q_channel_cfgcnt_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL2_fcm_debug_clk_q_channel_cfgcnt_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwakeup_bypass : 1;
        unsigned int acp_wakeup_bypass : 1;
        unsigned int dbgconnected : 1;
        unsigned int pmusnapshotreq : 1;
        unsigned int fcm_bus_dbg_en : 1;
        unsigned int core_secure_debug_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ananke_stretch_l2ramclk_en : 1;
        unsigned int enyo_stretch_l2ramclk_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int fcm_stretch_l3ramclk_en : 1;
        unsigned int reserved_3 : 20;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL3_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL3_pwakeup_bypass_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL3_pwakeup_bypass_END (0)
#define SOC_FCM_LOCAL_CPU_CTRL3_acp_wakeup_bypass_START (1)
#define SOC_FCM_LOCAL_CPU_CTRL3_acp_wakeup_bypass_END (1)
#define SOC_FCM_LOCAL_CPU_CTRL3_dbgconnected_START (2)
#define SOC_FCM_LOCAL_CPU_CTRL3_dbgconnected_END (2)
#define SOC_FCM_LOCAL_CPU_CTRL3_pmusnapshotreq_START (3)
#define SOC_FCM_LOCAL_CPU_CTRL3_pmusnapshotreq_END (3)
#define SOC_FCM_LOCAL_CPU_CTRL3_fcm_bus_dbg_en_START (4)
#define SOC_FCM_LOCAL_CPU_CTRL3_fcm_bus_dbg_en_END (4)
#define SOC_FCM_LOCAL_CPU_CTRL3_core_secure_debug_en_START (5)
#define SOC_FCM_LOCAL_CPU_CTRL3_core_secure_debug_en_END (5)
#define SOC_FCM_LOCAL_CPU_CTRL3_ananke_stretch_l2ramclk_en_START (8)
#define SOC_FCM_LOCAL_CPU_CTRL3_ananke_stretch_l2ramclk_en_END (8)
#define SOC_FCM_LOCAL_CPU_CTRL3_enyo_stretch_l2ramclk_en_START (9)
#define SOC_FCM_LOCAL_CPU_CTRL3_enyo_stretch_l2ramclk_en_END (9)
#define SOC_FCM_LOCAL_CPU_CTRL3_fcm_stretch_l3ramclk_en_START (11)
#define SOC_FCM_LOCAL_CPU_CTRL3_fcm_stretch_l3ramclk_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int gt_clk_adb_brg_m0 : 1;
        unsigned int gt_clk_adb_brg_m1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_atclk : 1;
        unsigned int gt_clk_atclk_top : 1;
        unsigned int gt_clk_periphclk : 1;
        unsigned int gt_clk_adb_brg_pp : 1;
        unsigned int reserved_2 : 1;
        unsigned int clken_masken : 16;
    } reg;
} SOC_FCM_LOCAL_CPU_FCM_CLK_EN_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_adb_brg_m0_START (8)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_adb_brg_m0_END (8)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_adb_brg_m1_START (9)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_adb_brg_m1_END (9)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_atclk_START (11)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_atclk_END (11)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_atclk_top_START (12)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_atclk_top_END (12)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_periphclk_START (13)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_periphclk_END (13)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_adb_brg_pp_START (14)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_gt_clk_adb_brg_pp_END (14)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_clken_masken_START (16)
#define SOC_FCM_LOCAL_CPU_FCM_CLK_EN_clken_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_en : 6;
        unsigned int big_core_soft_rst_en : 2;
        unsigned int adb_brg_m0_rst_en : 1;
        unsigned int adb_brg_m1_rst_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int adb_pp_rst_en : 1;
        unsigned int big_cluster_rst_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int little_cluster_rst_en : 1;
        unsigned int atb_top_rst_en : 1;
        unsigned int atb_fcm_rst_en : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_FCM_LOCAL_CPU_FCM_RST_EN_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_little_core_soft_rst_en_START (0)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_little_core_soft_rst_en_END (5)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_big_core_soft_rst_en_START (6)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_big_core_soft_rst_en_END (7)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_adb_brg_m0_rst_en_START (8)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_adb_brg_m0_rst_en_END (8)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_adb_brg_m1_rst_en_START (9)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_adb_brg_m1_rst_en_END (9)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_adb_pp_rst_en_START (11)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_adb_pp_rst_en_END (11)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_big_cluster_rst_en_START (12)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_big_cluster_rst_en_END (12)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_little_cluster_rst_en_START (14)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_little_cluster_rst_en_END (14)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_atb_top_rst_en_START (15)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_atb_top_rst_en_END (15)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_atb_fcm_rst_en_START (16)
#define SOC_FCM_LOCAL_CPU_FCM_RST_EN_atb_fcm_rst_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_dis : 6;
        unsigned int big_core_soft_rst_dis : 2;
        unsigned int adb_brg_m0_rst_dis : 1;
        unsigned int adb_brg_m1_rst_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int adb_pp_rst_dis : 1;
        unsigned int big_cluster_rst_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int little_cluster_rst_dis : 1;
        unsigned int atb_top_rst_dis : 1;
        unsigned int atb_fcm_rst_dis : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_FCM_LOCAL_CPU_FCM_RST_DIS_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_little_core_soft_rst_dis_START (0)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_little_core_soft_rst_dis_END (5)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_big_core_soft_rst_dis_START (6)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_big_core_soft_rst_dis_END (7)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_adb_brg_m0_rst_dis_START (8)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_adb_brg_m0_rst_dis_END (8)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_adb_brg_m1_rst_dis_START (9)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_adb_brg_m1_rst_dis_END (9)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_adb_pp_rst_dis_START (11)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_adb_pp_rst_dis_END (11)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_big_cluster_rst_dis_START (12)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_big_cluster_rst_dis_END (12)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_little_cluster_rst_dis_START (14)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_little_cluster_rst_dis_END (14)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_atb_top_rst_dis_START (15)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_atb_top_rst_dis_END (15)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_atb_fcm_rst_dis_START (16)
#define SOC_FCM_LOCAL_CPU_FCM_RST_DIS_atb_fcm_rst_dis_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_stat : 6;
        unsigned int big_core_soft_rst_stat : 2;
        unsigned int adb_brg_m0_rst_stat : 1;
        unsigned int adb_brg_m1_rst_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int adb_pp_rst_stat : 1;
        unsigned int big_cluster_rst_stat : 1;
        unsigned int reserved_1 : 1;
        unsigned int little_cluster_rst_stat : 1;
        unsigned int atb_top_rst_stat : 1;
        unsigned int atb_fcm_rst_stat : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_FCM_LOCAL_CPU_FCM_RST_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_little_core_soft_rst_stat_START (0)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_little_core_soft_rst_stat_END (5)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_big_core_soft_rst_stat_START (6)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_big_core_soft_rst_stat_END (7)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_adb_brg_m0_rst_stat_START (8)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_adb_brg_m0_rst_stat_END (8)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_adb_brg_m1_rst_stat_START (9)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_adb_brg_m1_rst_stat_END (9)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_adb_pp_rst_stat_START (11)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_adb_pp_rst_stat_END (11)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_big_cluster_rst_stat_START (12)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_big_cluster_rst_stat_END (12)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_little_cluster_rst_stat_START (14)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_little_cluster_rst_stat_END (14)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_atb_top_rst_stat_START (15)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_atb_top_rst_stat_END (15)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_atb_fcm_rst_stat_START (16)
#define SOC_FCM_LOCAL_CPU_FCM_RST_STAT_atb_fcm_rst_stat_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wakeup_rank_en : 1;
        unsigned int wakeup_ch_en : 1;
        unsigned int ddr_intlv_gran : 2;
        unsigned int ddr_ch4_order : 1;
        unsigned int ddr_addr_shift_mode : 1;
        unsigned int reserved_0 : 2;
        unsigned int ddr_rank_intlv_gran : 5;
        unsigned int reserved_1 : 11;
        unsigned int ddr_rank_intlv_en : 1;
        unsigned int reserved_2 : 2;
        unsigned int ddr_wakeup_prd : 2;
        unsigned int ddr_wakeup_sc_enable : 1;
        unsigned int gid_zero_sc : 1;
        unsigned int wakeup_en : 1;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL6_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL6_wakeup_rank_en_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL6_wakeup_rank_en_END (0)
#define SOC_FCM_LOCAL_CPU_CTRL6_wakeup_ch_en_START (1)
#define SOC_FCM_LOCAL_CPU_CTRL6_wakeup_ch_en_END (1)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_intlv_gran_START (2)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_intlv_gran_END (3)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_ch4_order_START (4)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_ch4_order_END (4)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_addr_shift_mode_START (5)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_addr_shift_mode_END (5)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_rank_intlv_gran_START (8)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_rank_intlv_gran_END (12)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_rank_intlv_en_START (24)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_rank_intlv_en_END (24)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_wakeup_prd_START (27)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_wakeup_prd_END (28)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_wakeup_sc_enable_START (29)
#define SOC_FCM_LOCAL_CPU_CTRL6_ddr_wakeup_sc_enable_END (29)
#define SOC_FCM_LOCAL_CPU_CTRL6_gid_zero_sc_START (30)
#define SOC_FCM_LOCAL_CPU_CTRL6_gid_zero_sc_END (30)
#define SOC_FCM_LOCAL_CPU_CTRL6_wakeup_en_START (31)
#define SOC_FCM_LOCAL_CPU_CTRL6_wakeup_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_eventi_npu_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL7_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL7_tcu_eventi_npu_enable_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL7_tcu_eventi_npu_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 28;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arnsaid_m0 : 2;
        unsigned int armid_m0 : 6;
        unsigned int awnsaid_m0 : 2;
        unsigned int awmid_m0 : 6;
        unsigned int arnsaid_m1 : 2;
        unsigned int armid_m1 : 6;
        unsigned int awnsaid_m1 : 2;
        unsigned int awmid_m1 : 6;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL9_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL9_arnsaid_m0_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL9_arnsaid_m0_END (1)
#define SOC_FCM_LOCAL_CPU_CTRL9_armid_m0_START (2)
#define SOC_FCM_LOCAL_CPU_CTRL9_armid_m0_END (7)
#define SOC_FCM_LOCAL_CPU_CTRL9_awnsaid_m0_START (8)
#define SOC_FCM_LOCAL_CPU_CTRL9_awnsaid_m0_END (9)
#define SOC_FCM_LOCAL_CPU_CTRL9_awmid_m0_START (10)
#define SOC_FCM_LOCAL_CPU_CTRL9_awmid_m0_END (15)
#define SOC_FCM_LOCAL_CPU_CTRL9_arnsaid_m1_START (16)
#define SOC_FCM_LOCAL_CPU_CTRL9_arnsaid_m1_END (17)
#define SOC_FCM_LOCAL_CPU_CTRL9_armid_m1_START (18)
#define SOC_FCM_LOCAL_CPU_CTRL9_armid_m1_END (23)
#define SOC_FCM_LOCAL_CPU_CTRL9_awnsaid_m1_START (24)
#define SOC_FCM_LOCAL_CPU_CTRL9_awnsaid_m1_END (25)
#define SOC_FCM_LOCAL_CPU_CTRL9_awmid_m1_START (26)
#define SOC_FCM_LOCAL_CPU_CTRL9_awmid_m1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aw_cmd_ost_cfg : 8;
        unsigned int ar_cmd_ost_cfg : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL10_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL10_aw_cmd_ost_cfg_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL10_aw_cmd_ost_cfg_END (7)
#define SOC_FCM_LOCAL_CPU_CTRL10_ar_cmd_ost_cfg_START (8)
#define SOC_FCM_LOCAL_CPU_CTRL10_ar_cmd_ost_cfg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nirq_test : 8;
        unsigned int nfiq_test : 8;
        unsigned int reserved_0 : 12;
        unsigned int giccdisable : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL11_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL11_nirq_test_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL11_nirq_test_END (7)
#define SOC_FCM_LOCAL_CPU_CTRL11_nfiq_test_START (8)
#define SOC_FCM_LOCAL_CPU_CTRL11_nfiq_test_END (15)
#define SOC_FCM_LOCAL_CPU_CTRL11_giccdisable_START (28)
#define SOC_FCM_LOCAL_CPU_CTRL11_giccdisable_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddr_rank_map : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL13_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL13_ddr_rank_map_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL13_ddr_rank_map_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 9;
        unsigned int pcr_m_sel : 2;
        unsigned int pcr_b_sel : 2;
        unsigned int cpu_m_pi_sel : 4;
        unsigned int cpu_b_pi_sel : 3;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL14_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL14_pcr_m_sel_START (9)
#define SOC_FCM_LOCAL_CPU_CTRL14_pcr_m_sel_END (10)
#define SOC_FCM_LOCAL_CPU_CTRL14_pcr_b_sel_START (11)
#define SOC_FCM_LOCAL_CPU_CTRL14_pcr_b_sel_END (12)
#define SOC_FCM_LOCAL_CPU_CTRL14_cpu_m_pi_sel_START (13)
#define SOC_FCM_LOCAL_CPU_CTRL14_cpu_m_pi_sel_END (16)
#define SOC_FCM_LOCAL_CPU_CTRL14_cpu_b_pi_sel_START (17)
#define SOC_FCM_LOCAL_CPU_CTRL14_cpu_b_pi_sel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_cnt_threthod : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL15_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL15_cpu_load_cnt_threthod_START (0)
#define SOC_FCM_LOCAL_CPU_CTRL15_cpu_load_cnt_threthod_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int enable_mid_core_mitigation : 1;
        unsigned int enable_mid_corewfe_include_maxpower : 1;
        unsigned int enable_big_core_mitigation : 1;
        unsigned int enable_big_corewfe_include_maxpower : 1;
        unsigned int enable_mid_core_renamefix : 1;
        unsigned int enable_big_core_renamefix : 1;
        unsigned int enable_mid_core_didt : 1;
        unsigned int enable_big_core_didt : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL16_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_core_mitigation_START (1)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_core_mitigation_END (1)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_corewfe_include_maxpower_START (2)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_corewfe_include_maxpower_END (2)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_core_mitigation_START (3)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_core_mitigation_END (3)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_corewfe_include_maxpower_START (4)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_corewfe_include_maxpower_END (4)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_core_renamefix_START (5)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_core_renamefix_END (5)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_core_renamefix_START (6)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_core_renamefix_END (6)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_core_didt_START (7)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_mid_core_didt_END (7)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_core_didt_START (8)
#define SOC_FCM_LOCAL_CPU_CTRL16_enable_big_core_didt_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_CTRL19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int atclk_qacceptn : 1;
        unsigned int atclk_qactive : 1;
        unsigned int atclk_qdeny : 1;
        unsigned int atclk_qreqn : 1;
        unsigned int gicclk_qacceptn : 1;
        unsigned int gicclk_qactive : 1;
        unsigned int gicclk_qdeny : 1;
        unsigned int gicclk_qreqn : 1;
        unsigned int pclk_qacceptn : 1;
        unsigned int pclk_qactive : 1;
        unsigned int pclk_qdeny : 1;
        unsigned int pclk_qreqn : 1;
        unsigned int sclk_qacceptn : 1;
        unsigned int sclk_qactive : 1;
        unsigned int sclk_qdeny : 1;
        unsigned int sclk_qreqn : 1;
        unsigned int pdbgclk_qacceptn : 1;
        unsigned int pdbgclk_qactive : 1;
        unsigned int pdbgtclk_qdeny : 1;
        unsigned int pdbgtclk_qreqn : 1;
        unsigned int pwr_qacceptn : 1;
        unsigned int pwr_qactive : 1;
        unsigned int pwr_qdeny : 1;
        unsigned int pwr_qreqn : 1;
        unsigned int awakeupm0 : 1;
        unsigned int awakeupm1 : 1;
        unsigned int awakeupmp : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qacceptn_START (0)
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qacceptn_END (0)
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qactive_START (1)
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qactive_END (1)
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qdeny_START (2)
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qdeny_END (2)
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qreqn_START (3)
#define SOC_FCM_LOCAL_CPU_STAT0_atclk_qreqn_END (3)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qacceptn_START (4)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qacceptn_END (4)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qactive_START (5)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qactive_END (5)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qdeny_START (6)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qdeny_END (6)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qreqn_START (7)
#define SOC_FCM_LOCAL_CPU_STAT0_gicclk_qreqn_END (7)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qacceptn_START (8)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qacceptn_END (8)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qactive_START (9)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qactive_END (9)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qdeny_START (10)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qdeny_END (10)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qreqn_START (11)
#define SOC_FCM_LOCAL_CPU_STAT0_pclk_qreqn_END (11)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qacceptn_START (12)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qacceptn_END (12)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qactive_START (13)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qactive_END (13)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qdeny_START (14)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qdeny_END (14)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qreqn_START (15)
#define SOC_FCM_LOCAL_CPU_STAT0_sclk_qreqn_END (15)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgclk_qacceptn_START (16)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgclk_qacceptn_END (16)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgclk_qactive_START (17)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgclk_qactive_END (17)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgtclk_qdeny_START (18)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgtclk_qdeny_END (18)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgtclk_qreqn_START (19)
#define SOC_FCM_LOCAL_CPU_STAT0_pdbgtclk_qreqn_END (19)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qacceptn_START (20)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qacceptn_END (20)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qactive_START (21)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qactive_END (21)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qdeny_START (22)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qdeny_END (22)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qreqn_START (23)
#define SOC_FCM_LOCAL_CPU_STAT0_pwr_qreqn_END (23)
#define SOC_FCM_LOCAL_CPU_STAT0_awakeupm0_START (24)
#define SOC_FCM_LOCAL_CPU_STAT0_awakeupm0_END (24)
#define SOC_FCM_LOCAL_CPU_STAT0_awakeupm1_START (25)
#define SOC_FCM_LOCAL_CPU_STAT0_awakeupm1_END (25)
#define SOC_FCM_LOCAL_CPU_STAT0_awakeupmp_START (26)
#define SOC_FCM_LOCAL_CPU_STAT0_awakeupmp_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbgack : 8;
        unsigned int dbgpwrupreq : 8;
        unsigned int clusterdbgpwrupreq : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT1_dbgack_START (0)
#define SOC_FCM_LOCAL_CPU_STAT1_dbgack_END (7)
#define SOC_FCM_LOCAL_CPU_STAT1_dbgpwrupreq_START (8)
#define SOC_FCM_LOCAL_CPU_STAT1_dbgpwrupreq_END (15)
#define SOC_FCM_LOCAL_CPU_STAT1_clusterdbgpwrupreq_START (16)
#define SOC_FCM_LOCAL_CPU_STAT1_clusterdbgpwrupreq_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_aps_dpm : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT2_intr_aps_dpm_START (0)
#define SOC_FCM_LOCAL_CPU_STAT2_intr_aps_dpm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coreinstrrun : 8;
        unsigned int coreinstrret : 8;
        unsigned int pmusnapshotack : 1;
        unsigned int reserved : 11;
        unsigned int reg_clusterpwrstat_active_portions : 4;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT6_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT6_coreinstrrun_START (0)
#define SOC_FCM_LOCAL_CPU_STAT6_coreinstrrun_END (7)
#define SOC_FCM_LOCAL_CPU_STAT6_coreinstrret_START (8)
#define SOC_FCM_LOCAL_CPU_STAT6_coreinstrret_END (15)
#define SOC_FCM_LOCAL_CPU_STAT6_pmusnapshotack_START (16)
#define SOC_FCM_LOCAL_CPU_STAT6_pmusnapshotack_END (16)
#define SOC_FCM_LOCAL_CPU_STAT6_reg_clusterpwrstat_active_portions_START (28)
#define SOC_FCM_LOCAL_CPU_STAT6_reg_clusterpwrstat_active_portions_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ar_cnt_m0 : 6;
        unsigned int reserved_0: 2;
        unsigned int aw_cnt_m0 : 6;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 16;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT7_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT7_ar_cnt_m0_START (0)
#define SOC_FCM_LOCAL_CPU_STAT7_ar_cnt_m0_END (5)
#define SOC_FCM_LOCAL_CPU_STAT7_aw_cnt_m0_START (8)
#define SOC_FCM_LOCAL_CPU_STAT7_aw_cnt_m0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_cnt_m0 : 6;
        unsigned int reserved_0: 2;
        unsigned int b_cnt_m0 : 6;
        unsigned int reserved_1: 2;
        unsigned int r_cnt_m0 : 6;
        unsigned int reserved_2: 10;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT8_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT8_w_cnt_m0_START (0)
#define SOC_FCM_LOCAL_CPU_STAT8_w_cnt_m0_END (5)
#define SOC_FCM_LOCAL_CPU_STAT8_b_cnt_m0_START (8)
#define SOC_FCM_LOCAL_CPU_STAT8_b_cnt_m0_END (13)
#define SOC_FCM_LOCAL_CPU_STAT8_r_cnt_m0_START (16)
#define SOC_FCM_LOCAL_CPU_STAT8_r_cnt_m0_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_arvalid : 1;
        unsigned int m0_arready : 1;
        unsigned int m0_rvalid : 1;
        unsigned int m0_rready : 1;
        unsigned int m0_awvalid : 1;
        unsigned int m0_awready : 1;
        unsigned int m0_wvalid : 1;
        unsigned int m0_wready : 1;
        unsigned int m0_wlast : 1;
        unsigned int m0_bvalid : 1;
        unsigned int m0_bready : 1;
        unsigned int m0_rlast : 1;
        unsigned int reserved_0 : 4;
        unsigned int m0_araddr_35_32 : 4;
        unsigned int reserved_1 : 4;
        unsigned int m0_awaddr_35_32 : 4;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT9_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT9_m0_arvalid_START (0)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_arvalid_END (0)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_arready_START (1)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_arready_END (1)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_rvalid_START (2)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_rvalid_END (2)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_rready_START (3)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_rready_END (3)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_awvalid_START (4)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_awvalid_END (4)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_awready_START (5)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_awready_END (5)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_wvalid_START (6)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_wvalid_END (6)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_wready_START (7)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_wready_END (7)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_wlast_START (8)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_wlast_END (8)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_bvalid_START (9)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_bvalid_END (9)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_bready_START (10)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_bready_END (10)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_rlast_START (11)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_rlast_END (11)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_araddr_35_32_START (16)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_araddr_35_32_END (19)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_awaddr_35_32_START (24)
#define SOC_FCM_LOCAL_CPU_STAT9_m0_awaddr_35_32_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_araddr_31_0 : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT10_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT10_m0_araddr_31_0_START (0)
#define SOC_FCM_LOCAL_CPU_STAT10_m0_araddr_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_awaddr_31_0 : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT11_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT11_m0_awaddr_31_0_START (0)
#define SOC_FCM_LOCAL_CPU_STAT11_m0_awaddr_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_rdsrcattr : 12;
        unsigned int reserved_0 : 4;
        unsigned int m0_wrsrcattr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT12_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT12_m0_rdsrcattr_START (0)
#define SOC_FCM_LOCAL_CPU_STAT12_m0_rdsrcattr_END (11)
#define SOC_FCM_LOCAL_CPU_STAT12_m0_wrsrcattr_START (16)
#define SOC_FCM_LOCAL_CPU_STAT12_m0_wrsrcattr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ar_cnt_m1 : 6;
        unsigned int reserved_0: 2;
        unsigned int aw_cnt_m1 : 6;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 16;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT13_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT13_ar_cnt_m1_START (0)
#define SOC_FCM_LOCAL_CPU_STAT13_ar_cnt_m1_END (5)
#define SOC_FCM_LOCAL_CPU_STAT13_aw_cnt_m1_START (8)
#define SOC_FCM_LOCAL_CPU_STAT13_aw_cnt_m1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_cnt_m1 : 6;
        unsigned int reserved_0: 2;
        unsigned int b_cnt_m1 : 6;
        unsigned int reserved_1: 2;
        unsigned int r_cnt_m1 : 6;
        unsigned int reserved_2: 10;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT14_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT14_w_cnt_m1_START (0)
#define SOC_FCM_LOCAL_CPU_STAT14_w_cnt_m1_END (5)
#define SOC_FCM_LOCAL_CPU_STAT14_b_cnt_m1_START (8)
#define SOC_FCM_LOCAL_CPU_STAT14_b_cnt_m1_END (13)
#define SOC_FCM_LOCAL_CPU_STAT14_r_cnt_m1_START (16)
#define SOC_FCM_LOCAL_CPU_STAT14_r_cnt_m1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m1_arvalid : 1;
        unsigned int m1_arready : 1;
        unsigned int m1_rvalid : 1;
        unsigned int m1_rready : 1;
        unsigned int m1_awvalid : 1;
        unsigned int m1_awready : 1;
        unsigned int m1_wvalid : 1;
        unsigned int m1_wready : 1;
        unsigned int m1_wlast : 1;
        unsigned int m1_bvalid : 1;
        unsigned int m1_bready : 1;
        unsigned int m1_rlast : 1;
        unsigned int reserved_0 : 4;
        unsigned int m1_araddr_35_32 : 4;
        unsigned int reserved_1 : 4;
        unsigned int m1_awaddr_35_32 : 4;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT15_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT15_m1_arvalid_START (0)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_arvalid_END (0)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_arready_START (1)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_arready_END (1)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_rvalid_START (2)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_rvalid_END (2)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_rready_START (3)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_rready_END (3)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_awvalid_START (4)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_awvalid_END (4)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_awready_START (5)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_awready_END (5)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_wvalid_START (6)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_wvalid_END (6)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_wready_START (7)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_wready_END (7)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_wlast_START (8)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_wlast_END (8)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_bvalid_START (9)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_bvalid_END (9)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_bready_START (10)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_bready_END (10)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_rlast_START (11)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_rlast_END (11)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_araddr_35_32_START (16)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_araddr_35_32_END (19)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_awaddr_35_32_START (24)
#define SOC_FCM_LOCAL_CPU_STAT15_m1_awaddr_35_32_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m1_araddr_31_0 : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT16_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT16_m1_araddr_31_0_START (0)
#define SOC_FCM_LOCAL_CPU_STAT16_m1_araddr_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m1_awaddr_31_0 : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT17_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT17_m1_awaddr_31_0_START (0)
#define SOC_FCM_LOCAL_CPU_STAT17_m1_awaddr_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m1_rdsrcattr : 12;
        unsigned int reserved_0 : 4;
        unsigned int m1_wrsrcattr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT18_UNION;
#endif
#define SOC_FCM_LOCAL_CPU_STAT18_m1_rdsrcattr_START (0)
#define SOC_FCM_LOCAL_CPU_STAT18_m1_rdsrcattr_END (11)
#define SOC_FCM_LOCAL_CPU_STAT18_m1_wrsrcattr_START (16)
#define SOC_FCM_LOCAL_CPU_STAT18_m1_wrsrcattr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_CPU_STAT19_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
