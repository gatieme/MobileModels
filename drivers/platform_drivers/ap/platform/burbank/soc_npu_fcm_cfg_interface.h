#ifndef __SOC_NPU_FCM_CFG_INTERFACE_H__
#define __SOC_NPU_FCM_CFG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_ADDR(base) ((base) + (0x100UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_ADDR(base) ((base) + (0x104UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_ADDR(base) ((base) + (0x108UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_ADDR(base) ((base) + (0x10CUL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_ADDR(base) ((base) + (0x110UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_ADDR(base) ((base) + (0x114UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL6_ADDR(base) ((base) + (0x118UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_ADDR(base) ((base) + (0x11CUL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL8_ADDR(base) ((base) + (0x120UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL9_ADDR(base) ((base) + (0x124UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_ADDR(base) ((base) + (0x200UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_ADDR(base) ((base) + (0x204UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_ADDR(base) ((base) + (0x208UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_ADDR(base) ((base) + (0x20CUL))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_ADDR(base) ((base) + (0x210UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_ADDR(base) ((base) + (0x214UL))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT6_ADDR(base) ((base) + (0x218UL))
#else
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_ADDR(base) ((base) + (0x100))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_ADDR(base) ((base) + (0x104))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_ADDR(base) ((base) + (0x108))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_ADDR(base) ((base) + (0x10C))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_ADDR(base) ((base) + (0x110))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_ADDR(base) ((base) + (0x114))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL6_ADDR(base) ((base) + (0x118))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_ADDR(base) ((base) + (0x11C))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL8_ADDR(base) ((base) + (0x120))
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL9_ADDR(base) ((base) + (0x124))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_ADDR(base) ((base) + (0x200))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_ADDR(base) ((base) + (0x204))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_ADDR(base) ((base) + (0x208))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_ADDR(base) ((base) + (0x20C))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_ADDR(base) ((base) + (0x210))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_ADDR(base) ((base) + (0x214))
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT6_ADDR(base) ((base) + (0x218))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 7;
        unsigned int debug_pwr_q_channel_qreqn : 1;
        unsigned int fcm_stretch_l2ramclk_en : 1;
        unsigned int dbgconnected : 1;
        unsigned int pmusnapshotreq : 1;
        unsigned int dbgnopwrdwn_patch : 1;
        unsigned int giccdisable : 1;
        unsigned int reserved_1 : 15;
        unsigned int nirq_test : 2;
        unsigned int nfiq_test : 2;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_debug_pwr_q_channel_qreqn_START (7)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_debug_pwr_q_channel_qreqn_END (7)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_fcm_stretch_l2ramclk_en_START (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_fcm_stretch_l2ramclk_en_END (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_dbgconnected_START (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_dbgconnected_END (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_pmusnapshotreq_START (10)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_pmusnapshotreq_END (10)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_dbgnopwrdwn_patch_START (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_dbgnopwrdwn_patch_END (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_giccdisable_START (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_giccdisable_END (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_nirq_test_START (28)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_nirq_test_END (29)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_nfiq_test_START (30)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL0_nfiq_test_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sclk_q_channel_en : 1;
        unsigned int atclk_q_channel_en : 1;
        unsigned int pclk_q_channel_en : 1;
        unsigned int gicclk_q_channel_en : 1;
        unsigned int pclk_dbg_q_channel_en : 1;
        unsigned int reserved_0 : 19;
        unsigned int pclk_dbg_q_channel_cfgcnt : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_sclk_q_channel_en_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_sclk_q_channel_en_END (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_atclk_q_channel_en_START (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_atclk_q_channel_en_END (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_pclk_q_channel_en_START (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_pclk_q_channel_en_END (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_gicclk_q_channel_en_START (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_gicclk_q_channel_en_END (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_pclk_dbg_q_channel_en_START (4)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_pclk_dbg_q_channel_en_END (4)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_pclk_dbg_q_channel_cfgcnt_START (24)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL1_pclk_dbg_q_channel_cfgcnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sclk_q_channel_cfgcnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int atclk_q_channel_cfgcnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int pclk_q_channel_cfgcnt : 7;
        unsigned int reserved_2 : 1;
        unsigned int gicclk_q_channel_cfgcnt : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_sclk_q_channel_cfgcnt_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_sclk_q_channel_cfgcnt_END (6)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_atclk_q_channel_cfgcnt_START (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_atclk_q_channel_cfgcnt_END (14)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_pclk_q_channel_cfgcnt_START (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_pclk_q_channel_cfgcnt_END (22)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_gicclk_q_channel_cfgcnt_START (24)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL2_gicclk_q_channel_cfgcnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int cluster_mem_ctl_normal : 3;
        unsigned int reserved_1 : 1;
        unsigned int cluster_mem_ctl_sd : 3;
        unsigned int reserved_2 : 1;
        unsigned int cluster_mem_ctl_dslp : 3;
        unsigned int reserved_3 : 1;
        unsigned int cluster_mem_ctl_slp : 3;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_normal_START (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_normal_END (18)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_sd_START (20)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_sd_END (22)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_dslp_START (24)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_dslp_END (26)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_slp_START (28)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL3_cluster_mem_ctl_slp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int force_on_to_sfonly_on_enable : 1;
        unsigned int force_disable_off : 1;
        unsigned int force_flush_cache : 1;
        unsigned int force_off_to_on : 1;
        unsigned int force_on_to_sfonly_on : 1;
        unsigned int reserved_1 : 2;
        unsigned int cluster_preq_from_sys : 1;
        unsigned int cluster_pstate_from_sys : 7;
        unsigned int reserved_2 : 1;
        unsigned int cluster_pactive_sel : 2;
        unsigned int reserved_3 : 5;
        unsigned int fcm_p_channel_enable : 1;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_fcm_p_channel_init_pstate_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_fcm_p_channel_init_pstate_END (6)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_on_to_sfonly_on_enable_START (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_on_to_sfonly_on_enable_END (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_disable_off_START (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_disable_off_END (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_flush_cache_START (10)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_flush_cache_END (10)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_off_to_on_START (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_off_to_on_END (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_on_to_sfonly_on_START (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_force_on_to_sfonly_on_END (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_cluster_preq_from_sys_START (15)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_cluster_preq_from_sys_END (15)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_cluster_pstate_from_sys_START (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_cluster_pstate_from_sys_END (22)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_cluster_pactive_sel_START (24)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_cluster_pactive_sel_END (25)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_fcm_p_channel_enable_START (31)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL4_fcm_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_data_way15_way12_mem_ctrl_sys : 3;
        unsigned int l3_data_way11_way8_mem_ctrl_sys : 3;
        unsigned int l3_data_way7_way4_mem_ctrl_sys : 3;
        unsigned int l3_data_way3_way0_mem_ctrl_sys : 3;
        unsigned int l3_sf_mem_ctrl_sys : 3;
        unsigned int l3_other_mem_ctrl_sys : 3;
        unsigned int reserved : 2;
        unsigned int l3_tag_way15_way12_mem_ctrl_sys : 3;
        unsigned int l3_tag_way11_way8_mem_ctrl_sys : 3;
        unsigned int l3_tag_way7_way4_mem_ctrl_sys : 3;
        unsigned int l3_tag_way3_way0_mem_ctrl_sys : 3;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way15_way12_mem_ctrl_sys_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way15_way12_mem_ctrl_sys_END (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way11_way8_mem_ctrl_sys_START (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way11_way8_mem_ctrl_sys_END (5)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way7_way4_mem_ctrl_sys_START (6)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way7_way4_mem_ctrl_sys_END (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way3_way0_mem_ctrl_sys_START (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_data_way3_way0_mem_ctrl_sys_END (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_sf_mem_ctrl_sys_START (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_sf_mem_ctrl_sys_END (14)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_other_mem_ctrl_sys_START (15)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_other_mem_ctrl_sys_END (17)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way15_way12_mem_ctrl_sys_START (20)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way15_way12_mem_ctrl_sys_END (22)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way11_way8_mem_ctrl_sys_START (23)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way11_way8_mem_ctrl_sys_END (25)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way7_way4_mem_ctrl_sys_START (26)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way7_way4_mem_ctrl_sys_END (28)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way3_way0_mem_ctrl_sys_START (29)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL5_l3_tag_way3_way0_mem_ctrl_sys_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_pchannel_wait_cycle_SD : 16;
        unsigned int fcm_pchannel_wait_cycle_DSLP : 16;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL6_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL6_fcm_pchannel_wait_cycle_SD_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL6_fcm_pchannel_wait_cycle_SD_END (15)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL6_fcm_pchannel_wait_cycle_DSLP_START (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL6_fcm_pchannel_wait_cycle_DSLP_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_hc_sfram_hisi_mem_test : 3;
        unsigned int reserved_0 : 2;
        unsigned int fcm_hc_sfram_hisi_mem_tselw : 2;
        unsigned int fcm_hc_sfram_hisi_mem_tra : 2;
        unsigned int fcm_hc_sfram_hisi_mem_tselr : 3;
        unsigned int fcm_tp_ltdb_hisi_mem_test : 3;
        unsigned int fcm_tp_ltdb_hisi_mem_tselr_tp : 2;
        unsigned int fcm_tp_ltdb_hisi_mem_tselw : 2;
        unsigned int fcm_tp_ltdb_hisi_mem_tra : 2;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_test_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_test_END (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_tselw_START (5)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_tselw_END (6)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_tra_START (7)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_tra_END (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_tselr_START (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_hc_sfram_hisi_mem_tselr_END (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_test_START (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_test_END (14)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_tselr_tp_START (15)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_tselr_tp_END (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_tselw_START (17)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_tselw_END (18)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_tra_START (19)
#define SOC_NPU_FCM_CFG_FCM_CPU_CTRL7_fcm_tp_ltdb_hisi_mem_tra_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_CTRL9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_idle : 1;
        unsigned int pmusnapshotack : 1;
        unsigned int dbgpwrupreq : 1;
        unsigned int clusterdbgpwrupreq : 1;
        unsigned int clusterpwrstat_active_portion : 4;
        unsigned int awakeupm0 : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_STAT0_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_fcm_idle_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_fcm_idle_END (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_pmusnapshotack_START (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_pmusnapshotack_END (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_dbgpwrupreq_START (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_dbgpwrupreq_END (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_clusterdbgpwrupreq_START (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_clusterdbgpwrupreq_END (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_clusterpwrstat_active_portion_START (4)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_clusterpwrstat_active_portion_END (7)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_awakeupm0_START (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT0_awakeupm0_END (8)
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
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_STAT1_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qacceptn_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qacceptn_END (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qactive_START (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qactive_END (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qdeny_START (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qdeny_END (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qreqn_START (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_atclk_qreqn_END (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qacceptn_START (4)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qacceptn_END (4)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qactive_START (5)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qactive_END (5)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qdeny_START (6)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qdeny_END (6)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qreqn_START (7)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_gicclk_qreqn_END (7)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qacceptn_START (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qacceptn_END (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qactive_START (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qactive_END (9)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qdeny_START (10)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qdeny_END (10)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qreqn_START (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pclk_qreqn_END (11)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qacceptn_START (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qacceptn_END (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qactive_START (13)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qactive_END (13)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qdeny_START (14)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qdeny_END (14)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qreqn_START (15)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_sclk_qreqn_END (15)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgclk_qacceptn_START (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgclk_qacceptn_END (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgclk_qactive_START (17)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgclk_qactive_END (17)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgtclk_qdeny_START (18)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgtclk_qdeny_END (18)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgtclk_qreqn_START (19)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pdbgtclk_qreqn_END (19)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qacceptn_START (20)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qacceptn_END (20)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qactive_START (21)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qactive_END (21)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qdeny_START (22)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qdeny_END (22)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qreqn_START (23)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT1_pwr_qreqn_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cluster_paccept : 1;
        unsigned int cluster_pdeny : 1;
        unsigned int cluster_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int cluster_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int cluster_pactive : 20;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_STAT2_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_paccept_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_paccept_END (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_pdeny_START (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_pdeny_END (1)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_preq_START (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_preq_END (2)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_pstate_START (4)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_pstate_END (10)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_pactive_START (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT2_cluster_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cluster_current_state : 6;
        unsigned int cluster_current_pstate : 7;
        unsigned int reserved_0 : 3;
        unsigned int cluster_current_state_flush_cache : 3;
        unsigned int cluster_off_flush_cache_valid : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_STAT3_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_current_state_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_current_state_END (5)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_current_pstate_START (6)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_current_pstate_END (12)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_current_state_flush_cache_START (16)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_current_state_flush_cache_END (18)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_off_flush_cache_valid_START (19)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT3_cluster_off_flush_cache_valid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 20;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int cluster_can_pd : 1;
        unsigned int reserved_2 : 2;
        unsigned int forced_on_sfonly_complete : 1;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_STAT4_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_pactive_to_sys_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_pactive_to_sys_END (19)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_paccept_to_sys_START (20)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_paccept_to_sys_END (20)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_pdeny_to_sys_START (24)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_pdeny_to_sys_END (24)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_cluster_can_pd_START (28)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_cluster_can_pd_END (28)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_forced_on_sfonly_complete_START (31)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT4_forced_on_sfonly_complete_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core0_dso_dbg : 4;
        unsigned int fcm_core1_dso_dbg : 4;
        unsigned int fcm_l3_dso_dbg : 12;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_STAT5_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_fcm_core0_dso_dbg_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_fcm_core0_dso_dbg_END (3)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_fcm_core1_dso_dbg_START (4)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_fcm_core1_dso_dbg_END (7)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_fcm_l3_dso_dbg_START (8)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT5_fcm_l3_dso_dbg_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NPU_FCM_id_version : 32;
    } reg;
} SOC_NPU_FCM_CFG_FCM_CPU_STAT6_UNION;
#endif
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT6_NPU_FCM_id_version_START (0)
#define SOC_NPU_FCM_CFG_FCM_CPU_STAT6_NPU_FCM_id_version_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
