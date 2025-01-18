#ifndef __SOC_FCM_LOCAL_GIC_INTERFACE_H__
#define __SOC_FCM_LOCAL_GIC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_GIC_CTRL0_ADDR(base) ((base) + (0x000UL))
#define SOC_FCM_LOCAL_GIC_CTRL1_ADDR(base) ((base) + (0x004UL))
#define SOC_FCM_LOCAL_GIC_CTRL2_ADDR(base) ((base) + (0x008UL))
#define SOC_FCM_LOCAL_GIC_CTRL3_ADDR(base) ((base) + (0x00CUL))
#define SOC_FCM_LOCAL_GIC_CTRL4_ADDR(base) ((base) + (0x010UL))
#define SOC_FCM_LOCAL_GIC_CTRL5_ADDR(base) ((base) + (0x014UL))
#define SOC_FCM_LOCAL_GIC_CTRL6_ADDR(base) ((base) + (0x018UL))
#define SOC_FCM_LOCAL_GIC_CTRL7_ADDR(base) ((base) + (0x01CUL))
#define SOC_FCM_LOCAL_GIC_CTRL8_ADDR(base) ((base) + (0x020UL))
#define SOC_FCM_LOCAL_GIC_CTRL9_ADDR(base) ((base) + (0x024UL))
#define SOC_FCM_LOCAL_GIC_CTRL10_ADDR(base) ((base) + (0x028UL))
#define SOC_FCM_LOCAL_GIC_CTRL11_ADDR(base) ((base) + (0x02CUL))
#define SOC_FCM_LOCAL_GIC_CTRL12_ADDR(base) ((base) + (0x030UL))
#define SOC_FCM_LOCAL_GIC_CTRL13_ADDR(base) ((base) + (0x034UL))
#define SOC_FCM_LOCAL_GIC_CTRL14_ADDR(base) ((base) + (0x038UL))
#define SOC_FCM_LOCAL_GIC_CTRL15_ADDR(base) ((base) + (0x03CUL))
#define SOC_FCM_LOCAL_GIC_CTRL16_ADDR(base) ((base) + (0x040UL))
#define SOC_FCM_LOCAL_GIC_CTRL17_ADDR(base) ((base) + (0x044UL))
#define SOC_FCM_LOCAL_GIC_CTRL18_ADDR(base) ((base) + (0x048UL))
#define SOC_FCM_LOCAL_GIC_CTRL19_ADDR(base) ((base) + (0x04CUL))
#define SOC_FCM_LOCAL_GIC_STAT0_ADDR(base) ((base) + (0x200UL))
#define SOC_FCM_LOCAL_GIC_STAT1_ADDR(base) ((base) + (0x204UL))
#define SOC_FCM_LOCAL_GIC_STAT2_ADDR(base) ((base) + (0x208UL))
#define SOC_FCM_LOCAL_GIC_STAT3_ADDR(base) ((base) + (0x20CUL))
#define SOC_FCM_LOCAL_GIC_STAT4_ADDR(base) ((base) + (0x210UL))
#define SOC_FCM_LOCAL_GIC_STAT5_ADDR(base) ((base) + (0x214UL))
#define SOC_FCM_LOCAL_GIC_STAT6_ADDR(base) ((base) + (0x218UL))
#define SOC_FCM_LOCAL_GIC_STAT7_ADDR(base) ((base) + (0x21CUL))
#define SOC_FCM_LOCAL_GIC_STAT8_ADDR(base) ((base) + (0x220UL))
#define SOC_FCM_LOCAL_GIC_STAT9_ADDR(base) ((base) + (0x224UL))
#define SOC_FCM_LOCAL_GIC_STAT10_ADDR(base) ((base) + (0x228UL))
#define SOC_FCM_LOCAL_GIC_STAT11_ADDR(base) ((base) + (0x22CUL))
#define SOC_FCM_LOCAL_GIC_STAT12_ADDR(base) ((base) + (0x230UL))
#define SOC_FCM_LOCAL_GIC_STAT13_ADDR(base) ((base) + (0x234UL))
#define SOC_FCM_LOCAL_GIC_STAT14_ADDR(base) ((base) + (0x238UL))
#define SOC_FCM_LOCAL_GIC_STAT15_ADDR(base) ((base) + (0x23CUL))
#define SOC_FCM_LOCAL_GIC_STAT16_ADDR(base) ((base) + (0x240UL))
#define SOC_FCM_LOCAL_GIC_STAT17_ADDR(base) ((base) + (0x244UL))
#define SOC_FCM_LOCAL_GIC_STAT18_ADDR(base) ((base) + (0x248UL))
#define SOC_FCM_LOCAL_GIC_STAT19_ADDR(base) ((base) + (0x24CUL))
#else
#define SOC_FCM_LOCAL_GIC_CTRL0_ADDR(base) ((base) + (0x000))
#define SOC_FCM_LOCAL_GIC_CTRL1_ADDR(base) ((base) + (0x004))
#define SOC_FCM_LOCAL_GIC_CTRL2_ADDR(base) ((base) + (0x008))
#define SOC_FCM_LOCAL_GIC_CTRL3_ADDR(base) ((base) + (0x00C))
#define SOC_FCM_LOCAL_GIC_CTRL4_ADDR(base) ((base) + (0x010))
#define SOC_FCM_LOCAL_GIC_CTRL5_ADDR(base) ((base) + (0x014))
#define SOC_FCM_LOCAL_GIC_CTRL6_ADDR(base) ((base) + (0x018))
#define SOC_FCM_LOCAL_GIC_CTRL7_ADDR(base) ((base) + (0x01C))
#define SOC_FCM_LOCAL_GIC_CTRL8_ADDR(base) ((base) + (0x020))
#define SOC_FCM_LOCAL_GIC_CTRL9_ADDR(base) ((base) + (0x024))
#define SOC_FCM_LOCAL_GIC_CTRL10_ADDR(base) ((base) + (0x028))
#define SOC_FCM_LOCAL_GIC_CTRL11_ADDR(base) ((base) + (0x02C))
#define SOC_FCM_LOCAL_GIC_CTRL12_ADDR(base) ((base) + (0x030))
#define SOC_FCM_LOCAL_GIC_CTRL13_ADDR(base) ((base) + (0x034))
#define SOC_FCM_LOCAL_GIC_CTRL14_ADDR(base) ((base) + (0x038))
#define SOC_FCM_LOCAL_GIC_CTRL15_ADDR(base) ((base) + (0x03C))
#define SOC_FCM_LOCAL_GIC_CTRL16_ADDR(base) ((base) + (0x040))
#define SOC_FCM_LOCAL_GIC_CTRL17_ADDR(base) ((base) + (0x044))
#define SOC_FCM_LOCAL_GIC_CTRL18_ADDR(base) ((base) + (0x048))
#define SOC_FCM_LOCAL_GIC_CTRL19_ADDR(base) ((base) + (0x04C))
#define SOC_FCM_LOCAL_GIC_STAT0_ADDR(base) ((base) + (0x200))
#define SOC_FCM_LOCAL_GIC_STAT1_ADDR(base) ((base) + (0x204))
#define SOC_FCM_LOCAL_GIC_STAT2_ADDR(base) ((base) + (0x208))
#define SOC_FCM_LOCAL_GIC_STAT3_ADDR(base) ((base) + (0x20C))
#define SOC_FCM_LOCAL_GIC_STAT4_ADDR(base) ((base) + (0x210))
#define SOC_FCM_LOCAL_GIC_STAT5_ADDR(base) ((base) + (0x214))
#define SOC_FCM_LOCAL_GIC_STAT6_ADDR(base) ((base) + (0x218))
#define SOC_FCM_LOCAL_GIC_STAT7_ADDR(base) ((base) + (0x21C))
#define SOC_FCM_LOCAL_GIC_STAT8_ADDR(base) ((base) + (0x220))
#define SOC_FCM_LOCAL_GIC_STAT9_ADDR(base) ((base) + (0x224))
#define SOC_FCM_LOCAL_GIC_STAT10_ADDR(base) ((base) + (0x228))
#define SOC_FCM_LOCAL_GIC_STAT11_ADDR(base) ((base) + (0x22C))
#define SOC_FCM_LOCAL_GIC_STAT12_ADDR(base) ((base) + (0x230))
#define SOC_FCM_LOCAL_GIC_STAT13_ADDR(base) ((base) + (0x234))
#define SOC_FCM_LOCAL_GIC_STAT14_ADDR(base) ((base) + (0x238))
#define SOC_FCM_LOCAL_GIC_STAT15_ADDR(base) ((base) + (0x23C))
#define SOC_FCM_LOCAL_GIC_STAT16_ADDR(base) ((base) + (0x240))
#define SOC_FCM_LOCAL_GIC_STAT17_ADDR(base) ((base) + (0x244))
#define SOC_FCM_LOCAL_GIC_STAT18_ADDR(base) ((base) + (0x248))
#define SOC_FCM_LOCAL_GIC_STAT19_ADDR(base) ((base) + (0x24C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int ctiirq_pulse_sel : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL0_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL0_ctiirq_pulse_sel_START (5)
#define SOC_FCM_LOCAL_GIC_CTRL0_ctiirq_pulse_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gicclk_q_enable : 1;
        unsigned int reserved_0 : 3;
        unsigned int gicclk_qactive_cfgcnt : 7;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL1_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL1_gicclk_q_enable_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL1_gicclk_q_enable_END (0)
#define SOC_FCM_LOCAL_GIC_CTRL1_gicclk_qactive_cfgcnt_START (4)
#define SOC_FCM_LOCAL_GIC_CTRL1_gicclk_qactive_cfgcnt_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_mem_ls : 1;
        unsigned int gic_mem_ds : 1;
        unsigned int gic_mem_sd : 1;
        unsigned int gic_mem_tselr : 3;
        unsigned int gic_mem_tselw : 2;
        unsigned int gic_mem_test : 3;
        unsigned int reserved_0 : 5;
        unsigned int gic_mem_tra : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL2_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_ls_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_ls_END (0)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_ds_START (1)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_ds_END (1)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_sd_START (2)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_sd_END (2)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_tselr_START (3)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_tselr_END (5)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_tselw_START (6)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_tselw_END (7)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_test_START (8)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_test_END (10)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_tra_START (16)
#define SOC_FCM_LOCAL_GIC_CTRL2_gic_mem_tra_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gicp_allow_ns : 1;
        unsigned int gict_allow_ns : 1;
        unsigned int gic_bus_wakeup_bypass : 1;
        unsigned int cpu_core_active_bypass : 1;
        unsigned int cpu_core_active_hard_sel : 1;
        unsigned int cpu_core_active_soft_ctl : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL3_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL3_gicp_allow_ns_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL3_gicp_allow_ns_END (0)
#define SOC_FCM_LOCAL_GIC_CTRL3_gict_allow_ns_START (1)
#define SOC_FCM_LOCAL_GIC_CTRL3_gict_allow_ns_END (1)
#define SOC_FCM_LOCAL_GIC_CTRL3_gic_bus_wakeup_bypass_START (2)
#define SOC_FCM_LOCAL_GIC_CTRL3_gic_bus_wakeup_bypass_END (2)
#define SOC_FCM_LOCAL_GIC_CTRL3_cpu_core_active_bypass_START (3)
#define SOC_FCM_LOCAL_GIC_CTRL3_cpu_core_active_bypass_END (3)
#define SOC_FCM_LOCAL_GIC_CTRL3_cpu_core_active_hard_sel_START (4)
#define SOC_FCM_LOCAL_GIC_CTRL3_cpu_core_active_hard_sel_END (4)
#define SOC_FCM_LOCAL_GIC_CTRL3_cpu_core_active_soft_ctl_START (5)
#define SOC_FCM_LOCAL_GIC_CTRL3_cpu_core_active_soft_ctl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_sample_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL4_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL4_gic_sample_req_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL4_gic_sample_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qreqn_col : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL5_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL5_qreqn_col_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL5_qreqn_col_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_preq : 1;
        unsigned int reserved_0 : 3;
        unsigned int gic_pstate : 5;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL6_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL6_gic_preq_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL6_gic_preq_END (0)
#define SOC_FCM_LOCAL_GIC_CTRL6_gic_pstate_START (4)
#define SOC_FCM_LOCAL_GIC_CTRL6_gic_pstate_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_adb_mst_clk_en : 1;
        unsigned int gic_adb_mst_rst_req : 1;
        unsigned int gic_dbg_rst_req : 1;
        unsigned int gic_func_rst_req : 1;
        unsigned int reserved : 12;
        unsigned int clk_rst_en_masken : 16;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL7_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_adb_mst_clk_en_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_adb_mst_clk_en_END (0)
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_adb_mst_rst_req_START (1)
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_adb_mst_rst_req_END (1)
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_dbg_rst_req_START (2)
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_dbg_rst_req_END (2)
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_func_rst_req_START (3)
#define SOC_FCM_LOCAL_GIC_CTRL7_gic_func_rst_req_END (3)
#define SOC_FCM_LOCAL_GIC_CTRL7_clk_rst_en_masken_START (16)
#define SOC_FCM_LOCAL_GIC_CTRL7_clk_rst_en_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_cpu_active_soft_cfg : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL8_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL8_gic_cpu_active_soft_cfg_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL8_gic_cpu_active_soft_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_soft_spi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL11_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_CTRL11_gic_soft_spi_START (0)
#define SOC_FCM_LOCAL_GIC_CTRL11_gic_soft_spi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_CTRL19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_sample_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT0_gic_sample_ack_START (0)
#define SOC_FCM_LOCAL_GIC_STAT0_gic_sample_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qacceptn_col : 1;
        unsigned int qactive_col : 1;
        unsigned int qdeny_col : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT1_qacceptn_col_START (0)
#define SOC_FCM_LOCAL_GIC_STAT1_qacceptn_col_END (0)
#define SOC_FCM_LOCAL_GIC_STAT1_qactive_col_START (1)
#define SOC_FCM_LOCAL_GIC_STAT1_qactive_col_END (1)
#define SOC_FCM_LOCAL_GIC_STAT1_qdeny_col_START (2)
#define SOC_FCM_LOCAL_GIC_STAT1_qdeny_col_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_paccept : 1;
        unsigned int gic_pactive : 1;
        unsigned int gic_pdeny : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT2_gic_paccept_START (0)
#define SOC_FCM_LOCAL_GIC_STAT2_gic_paccept_END (0)
#define SOC_FCM_LOCAL_GIC_STAT2_gic_pactive_START (1)
#define SOC_FCM_LOCAL_GIC_STAT2_gic_pactive_END (1)
#define SOC_FCM_LOCAL_GIC_STAT2_gic_pdeny_START (2)
#define SOC_FCM_LOCAL_GIC_STAT2_gic_pdeny_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_cfg2fcm_i_mainnordpendingtrans : 1;
        unsigned int noc_cfg2fcm_i_mainnowrpendingtrans : 1;
        unsigned int noc_fcm2sys_t_mainnopendingtrans : 1;
        unsigned int noc_fcm2sys_t_maintimeout : 1;
        unsigned int noc_fcm_cfg_t_mainnopendingtrans : 1;
        unsigned int noc_fcm_cfg_t_maintimeout : 1;
        unsigned int noc_gic_cfg_t_mainnopendingtrans : 1;
        unsigned int noc_gic_cfg_t_maintimeout : 1;
        unsigned int noc_peri_port_i_mainnordpendingtrans : 1;
        unsigned int noc_peri_port_i_mainnowrpendingtrans : 1;
        unsigned int fcmbus_error_probe_observer_mainfault : 1;
        unsigned int fcm_service_target_t_mainnopendingtrans : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT4_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT4_noc_cfg2fcm_i_mainnordpendingtrans_START (0)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_cfg2fcm_i_mainnordpendingtrans_END (0)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_cfg2fcm_i_mainnowrpendingtrans_START (1)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_cfg2fcm_i_mainnowrpendingtrans_END (1)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm2sys_t_mainnopendingtrans_START (2)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm2sys_t_mainnopendingtrans_END (2)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm2sys_t_maintimeout_START (3)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm2sys_t_maintimeout_END (3)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm_cfg_t_mainnopendingtrans_START (4)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm_cfg_t_mainnopendingtrans_END (4)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm_cfg_t_maintimeout_START (5)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_fcm_cfg_t_maintimeout_END (5)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_gic_cfg_t_mainnopendingtrans_START (6)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_gic_cfg_t_mainnopendingtrans_END (6)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_gic_cfg_t_maintimeout_START (7)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_gic_cfg_t_maintimeout_END (7)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_peri_port_i_mainnordpendingtrans_START (8)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_peri_port_i_mainnordpendingtrans_END (8)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_peri_port_i_mainnowrpendingtrans_START (9)
#define SOC_FCM_LOCAL_GIC_STAT4_noc_peri_port_i_mainnowrpendingtrans_END (9)
#define SOC_FCM_LOCAL_GIC_STAT4_fcmbus_error_probe_observer_mainfault_START (10)
#define SOC_FCM_LOCAL_GIC_STAT4_fcmbus_error_probe_observer_mainfault_END (10)
#define SOC_FCM_LOCAL_GIC_STAT4_fcm_service_target_t_mainnopendingtrans_START (11)
#define SOC_FCM_LOCAL_GIC_STAT4_fcm_service_target_t_mainnopendingtrans_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_l3_sdo_dbg : 12;
        unsigned int fcm_other_sdo_dbg : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT12_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT12_fcm_l3_sdo_dbg_START (0)
#define SOC_FCM_LOCAL_GIC_STAT12_fcm_l3_sdo_dbg_END (11)
#define SOC_FCM_LOCAL_GIC_STAT12_fcm_other_sdo_dbg_START (12)
#define SOC_FCM_LOCAL_GIC_STAT12_fcm_other_sdo_dbg_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_l3_dso_dbg : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT13_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT13_fcm_l3_dso_dbg_START (0)
#define SOC_FCM_LOCAL_GIC_STAT13_fcm_l3_dso_dbg_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ananke0_sdo_dbg : 1;
        unsigned int ananke1_sdo_dbg : 1;
        unsigned int ananke2_sdo_dbg : 1;
        unsigned int ananke3_sdo_dbg : 1;
        unsigned int ananke4_sdo_dbg : 1;
        unsigned int ananke5_sdo_dbg : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT14_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT14_ananke0_sdo_dbg_START (0)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke0_sdo_dbg_END (0)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke1_sdo_dbg_START (1)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke1_sdo_dbg_END (1)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke2_sdo_dbg_START (2)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke2_sdo_dbg_END (2)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke3_sdo_dbg_START (3)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke3_sdo_dbg_END (3)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke4_sdo_dbg_START (4)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke4_sdo_dbg_END (4)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke5_sdo_dbg_START (5)
#define SOC_FCM_LOCAL_GIC_STAT14_ananke5_sdo_dbg_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ananke0_dso_dbg : 4;
        unsigned int ananke1_dso_dbg : 4;
        unsigned int ananke2_dso_dbg : 4;
        unsigned int ananke3_dso_dbg : 4;
        unsigned int ananke4_dso_dbg : 4;
        unsigned int ananke5_dso_dbg : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT15_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT15_ananke0_dso_dbg_START (0)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke0_dso_dbg_END (3)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke1_dso_dbg_START (4)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke1_dso_dbg_END (7)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke2_dso_dbg_START (8)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke2_dso_dbg_END (11)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke3_dso_dbg_START (12)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke3_dso_dbg_END (15)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke4_dso_dbg_START (16)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke4_dso_dbg_END (19)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke5_dso_dbg_START (20)
#define SOC_FCM_LOCAL_GIC_STAT15_ananke5_dso_dbg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int big_enyo0_sdo_dbg : 1;
        unsigned int big_enyo1_sdo_dbg : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT16_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT16_big_enyo0_sdo_dbg_START (0)
#define SOC_FCM_LOCAL_GIC_STAT16_big_enyo0_sdo_dbg_END (0)
#define SOC_FCM_LOCAL_GIC_STAT16_big_enyo1_sdo_dbg_START (1)
#define SOC_FCM_LOCAL_GIC_STAT16_big_enyo1_sdo_dbg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int big_enyo0_dso_dbg : 10;
        unsigned int big_enyo1_dso_dbg : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT17_UNION;
#endif
#define SOC_FCM_LOCAL_GIC_STAT17_big_enyo0_dso_dbg_START (0)
#define SOC_FCM_LOCAL_GIC_STAT17_big_enyo0_dso_dbg_END (9)
#define SOC_FCM_LOCAL_GIC_STAT17_big_enyo1_dso_dbg_START (10)
#define SOC_FCM_LOCAL_GIC_STAT17_big_enyo1_dso_dbg_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_GIC_STAT19_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
