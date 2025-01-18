#ifndef __SOC_NPU_SCTRL_INTERFACE_H__
#define __SOC_NPU_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_SCTRL_npu_ctrl0_ADDR(base) ((base) + (0x000UL))
#define SOC_NPU_SCTRL_npu_ctrl1_ADDR(base) ((base) + (0x004UL))
#define SOC_NPU_SCTRL_npu_ctrl2_ADDR(base) ((base) + (0x008UL))
#define SOC_NPU_SCTRL_npu_ctrl3_ADDR(base) ((base) + (0x00CUL))
#define SOC_NPU_SCTRL_npu_ctrl4_ADDR(base) ((base) + (0x010UL))
#define SOC_NPU_SCTRL_npu_ctrl5_ADDR(base) ((base) + (0x014UL))
#define SOC_NPU_SCTRL_npu_ctrl6_ADDR(base) ((base) + (0x018UL))
#define SOC_NPU_SCTRL_npu_ctrl7_ADDR(base) ((base) + (0x01CUL))
#define SOC_NPU_SCTRL_npu_ctrl8_ADDR(base) ((base) + (0x020UL))
#define SOC_NPU_SCTRL_npu_ctrl9_ADDR(base) ((base) + (0x024UL))
#define SOC_NPU_SCTRL_npu_ctrl10_ADDR(base) ((base) + (0x028UL))
#define SOC_NPU_SCTRL_NPU_CTRL11_ADDR(base) ((base) + (0x02CUL))
#define SOC_NPU_SCTRL_NPU_CTRL12_ADDR(base) ((base) + (0x030UL))
#define SOC_NPU_SCTRL_NPU_CTRL13_ADDR(base) ((base) + (0x034UL))
#define SOC_NPU_SCTRL_NPU_CTRL14_ADDR(base) ((base) + (0x038UL))
#define SOC_NPU_SCTRL_NPU_CTRL15_ADDR(base) ((base) + (0x03CUL))
#define SOC_NPU_SCTRL_NPU_CTRL16_ADDR(base) ((base) + (0x040UL))
#define SOC_NPU_SCTRL_NPU_CTRL17_ADDR(base) ((base) + (0x044UL))
#define SOC_NPU_SCTRL_NPU_CTRL18_ADDR(base) ((base) + (0x048UL))
#define SOC_NPU_SCTRL_NPU_CTRL19_ADDR(base) ((base) + (0x04CUL))
#define SOC_NPU_SCTRL_NPU_STAT0_ADDR(base) ((base) + (0x800UL))
#define SOC_NPU_SCTRL_npu_stat1_ADDR(base) ((base) + (0x804UL))
#define SOC_NPU_SCTRL_npu_stat2_ADDR(base) ((base) + (0x808UL))
#define SOC_NPU_SCTRL_npu_stat3_ADDR(base) ((base) + (0x80CUL))
#define SOC_NPU_SCTRL_npu_stat4_ADDR(base) ((base) + (0x810UL))
#define SOC_NPU_SCTRL_npu_stat5_ADDR(base) ((base) + (0x814UL))
#define SOC_NPU_SCTRL_npu_stat6_ADDR(base) ((base) + (0x818UL))
#define SOC_NPU_SCTRL_npu_stat7_ADDR(base) ((base) + (0x81CUL))
#define SOC_NPU_SCTRL_npu_stat8_ADDR(base) ((base) + (0x820UL))
#define SOC_NPU_SCTRL_npu_stat9_ADDR(base) ((base) + (0x824UL))
#else
#define SOC_NPU_SCTRL_npu_ctrl0_ADDR(base) ((base) + (0x000))
#define SOC_NPU_SCTRL_npu_ctrl1_ADDR(base) ((base) + (0x004))
#define SOC_NPU_SCTRL_npu_ctrl2_ADDR(base) ((base) + (0x008))
#define SOC_NPU_SCTRL_npu_ctrl3_ADDR(base) ((base) + (0x00C))
#define SOC_NPU_SCTRL_npu_ctrl4_ADDR(base) ((base) + (0x010))
#define SOC_NPU_SCTRL_npu_ctrl5_ADDR(base) ((base) + (0x014))
#define SOC_NPU_SCTRL_npu_ctrl6_ADDR(base) ((base) + (0x018))
#define SOC_NPU_SCTRL_npu_ctrl7_ADDR(base) ((base) + (0x01C))
#define SOC_NPU_SCTRL_npu_ctrl8_ADDR(base) ((base) + (0x020))
#define SOC_NPU_SCTRL_npu_ctrl9_ADDR(base) ((base) + (0x024))
#define SOC_NPU_SCTRL_npu_ctrl10_ADDR(base) ((base) + (0x028))
#define SOC_NPU_SCTRL_NPU_CTRL11_ADDR(base) ((base) + (0x02C))
#define SOC_NPU_SCTRL_NPU_CTRL12_ADDR(base) ((base) + (0x030))
#define SOC_NPU_SCTRL_NPU_CTRL13_ADDR(base) ((base) + (0x034))
#define SOC_NPU_SCTRL_NPU_CTRL14_ADDR(base) ((base) + (0x038))
#define SOC_NPU_SCTRL_NPU_CTRL15_ADDR(base) ((base) + (0x03C))
#define SOC_NPU_SCTRL_NPU_CTRL16_ADDR(base) ((base) + (0x040))
#define SOC_NPU_SCTRL_NPU_CTRL17_ADDR(base) ((base) + (0x044))
#define SOC_NPU_SCTRL_NPU_CTRL18_ADDR(base) ((base) + (0x048))
#define SOC_NPU_SCTRL_NPU_CTRL19_ADDR(base) ((base) + (0x04C))
#define SOC_NPU_SCTRL_NPU_STAT0_ADDR(base) ((base) + (0x800))
#define SOC_NPU_SCTRL_npu_stat1_ADDR(base) ((base) + (0x804))
#define SOC_NPU_SCTRL_npu_stat2_ADDR(base) ((base) + (0x808))
#define SOC_NPU_SCTRL_npu_stat3_ADDR(base) ((base) + (0x80C))
#define SOC_NPU_SCTRL_npu_stat4_ADDR(base) ((base) + (0x810))
#define SOC_NPU_SCTRL_npu_stat5_ADDR(base) ((base) + (0x814))
#define SOC_NPU_SCTRL_npu_stat6_ADDR(base) ((base) + (0x818))
#define SOC_NPU_SCTRL_npu_stat7_ADDR(base) ((base) + (0x81C))
#define SOC_NPU_SCTRL_npu_stat8_ADDR(base) ((base) + (0x820))
#define SOC_NPU_SCTRL_npu_stat9_ADDR(base) ((base) + (0x824))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hard_volt_high_dpm_aicore : 1;
        unsigned int hard_volt_low_dpm_aicore : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int l2buf_intlv_gran : 2;
        unsigned int reserved_2 : 1;
        unsigned int sc_monitor_rst_req : 1;
        unsigned int reserved_3 : 24;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl0_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl0_hard_volt_high_dpm_aicore_START (0)
#define SOC_NPU_SCTRL_npu_ctrl0_hard_volt_high_dpm_aicore_END (0)
#define SOC_NPU_SCTRL_npu_ctrl0_hard_volt_low_dpm_aicore_START (1)
#define SOC_NPU_SCTRL_npu_ctrl0_hard_volt_low_dpm_aicore_END (1)
#define SOC_NPU_SCTRL_npu_ctrl0_l2buf_intlv_gran_START (4)
#define SOC_NPU_SCTRL_npu_ctrl0_l2buf_intlv_gran_END (5)
#define SOC_NPU_SCTRL_npu_ctrl0_sc_monitor_rst_req_START (7)
#define SOC_NPU_SCTRL_npu_ctrl0_sc_monitor_rst_req_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LS : 1;
        unsigned int DS : 1;
        unsigned int reserved_0: 1;
        unsigned int TESTR : 3;
        unsigned int TESTW : 2;
        unsigned int TEST : 3;
        unsigned int reserved_1: 5;
        unsigned int TRA : 2;
        unsigned int reserved_2: 14;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl1_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl1_LS_START (0)
#define SOC_NPU_SCTRL_npu_ctrl1_LS_END (0)
#define SOC_NPU_SCTRL_npu_ctrl1_DS_START (1)
#define SOC_NPU_SCTRL_npu_ctrl1_DS_END (1)
#define SOC_NPU_SCTRL_npu_ctrl1_TESTR_START (3)
#define SOC_NPU_SCTRL_npu_ctrl1_TESTR_END (5)
#define SOC_NPU_SCTRL_npu_ctrl1_TESTW_START (6)
#define SOC_NPU_SCTRL_npu_ctrl1_TESTW_END (7)
#define SOC_NPU_SCTRL_npu_ctrl1_TEST_START (8)
#define SOC_NPU_SCTRL_npu_ctrl1_TEST_END (10)
#define SOC_NPU_SCTRL_npu_ctrl1_TRA_START (16)
#define SOC_NPU_SCTRL_npu_ctrl1_TRA_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LS : 1;
        unsigned int DS : 1;
        unsigned int reserved_0: 1;
        unsigned int TESTR : 3;
        unsigned int TESTW : 2;
        unsigned int TEST : 3;
        unsigned int reserved_1: 5;
        unsigned int TRA : 2;
        unsigned int reserved_2: 14;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl2_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl2_LS_START (0)
#define SOC_NPU_SCTRL_npu_ctrl2_LS_END (0)
#define SOC_NPU_SCTRL_npu_ctrl2_DS_START (1)
#define SOC_NPU_SCTRL_npu_ctrl2_DS_END (1)
#define SOC_NPU_SCTRL_npu_ctrl2_TESTR_START (3)
#define SOC_NPU_SCTRL_npu_ctrl2_TESTR_END (5)
#define SOC_NPU_SCTRL_npu_ctrl2_TESTW_START (6)
#define SOC_NPU_SCTRL_npu_ctrl2_TESTW_END (7)
#define SOC_NPU_SCTRL_npu_ctrl2_TEST_START (8)
#define SOC_NPU_SCTRL_npu_ctrl2_TEST_END (10)
#define SOC_NPU_SCTRL_npu_ctrl2_TRA_START (16)
#define SOC_NPU_SCTRL_npu_ctrl2_TRA_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LS : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
        unsigned int TESTR : 2;
        unsigned int TESTW : 2;
        unsigned int TEST : 3;
        unsigned int TRA : 2;
        unsigned int reserved_2: 19;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl3_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl3_LS_START (0)
#define SOC_NPU_SCTRL_npu_ctrl3_LS_END (0)
#define SOC_NPU_SCTRL_npu_ctrl3_TESTR_START (4)
#define SOC_NPU_SCTRL_npu_ctrl3_TESTR_END (5)
#define SOC_NPU_SCTRL_npu_ctrl3_TESTW_START (6)
#define SOC_NPU_SCTRL_npu_ctrl3_TESTW_END (7)
#define SOC_NPU_SCTRL_npu_ctrl3_TEST_START (8)
#define SOC_NPU_SCTRL_npu_ctrl3_TEST_END (10)
#define SOC_NPU_SCTRL_npu_ctrl3_TRA_START (11)
#define SOC_NPU_SCTRL_npu_ctrl3_TRA_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm_clk_div : 6;
        unsigned int hpm_en : 1;
        unsigned int hpmx_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl4_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl4_hpm_clk_div_START (0)
#define SOC_NPU_SCTRL_npu_ctrl4_hpm_clk_div_END (5)
#define SOC_NPU_SCTRL_npu_ctrl4_hpm_en_START (6)
#define SOC_NPU_SCTRL_npu_ctrl4_hpm_en_END (6)
#define SOC_NPU_SCTRL_npu_ctrl4_hpmx_en_START (7)
#define SOC_NPU_SCTRL_npu_ctrl4_hpmx_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_ostd_lvl : 8;
        unsigned int ostd_monitor_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl5_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl5_icfg_ostd_lvl_START (0)
#define SOC_NPU_SCTRL_npu_ctrl5_icfg_ostd_lvl_END (7)
#define SOC_NPU_SCTRL_npu_ctrl5_ostd_monitor_en_START (8)
#define SOC_NPU_SCTRL_npu_ctrl5_ostd_monitor_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_sample_reg : 1;
        unsigned int gic_clk_gt_enable : 1;
        unsigned int qreqn_col : 1;
        unsigned int reserved_0 : 1;
        unsigned int gic_clk_qactive_cfgcnt : 7;
        unsigned int reserved_1 : 5;
        unsigned int gic_pstate : 5;
        unsigned int gic_preq : 1;
        unsigned int gic_bus_wakeup_bypass : 1;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl6_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl6_gic_sample_reg_START (0)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_sample_reg_END (0)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_clk_gt_enable_START (1)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_clk_gt_enable_END (1)
#define SOC_NPU_SCTRL_npu_ctrl6_qreqn_col_START (2)
#define SOC_NPU_SCTRL_npu_ctrl6_qreqn_col_END (2)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_clk_qactive_cfgcnt_START (4)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_clk_qactive_cfgcnt_END (10)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_pstate_START (16)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_pstate_END (20)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_preq_START (21)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_preq_END (21)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_bus_wakeup_bypass_START (22)
#define SOC_NPU_SCTRL_npu_ctrl6_gic_bus_wakeup_bypass_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_rd_bwc_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int ts_rd_bwc_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int ts_rd_bwc_en : 1;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl7_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl7_ts_rd_bwc_saturation_START (0)
#define SOC_NPU_SCTRL_npu_ctrl7_ts_rd_bwc_saturation_END (13)
#define SOC_NPU_SCTRL_npu_ctrl7_ts_rd_bwc_bandwidth_START (16)
#define SOC_NPU_SCTRL_npu_ctrl7_ts_rd_bwc_bandwidth_END (28)
#define SOC_NPU_SCTRL_npu_ctrl7_ts_rd_bwc_en_START (31)
#define SOC_NPU_SCTRL_npu_ctrl7_ts_rd_bwc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_wr_bwc_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int ts_wr_bwc_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int ts_wr_bwc_en : 1;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl8_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl8_ts_wr_bwc_saturation_START (0)
#define SOC_NPU_SCTRL_npu_ctrl8_ts_wr_bwc_saturation_END (13)
#define SOC_NPU_SCTRL_npu_ctrl8_ts_wr_bwc_bandwidth_START (16)
#define SOC_NPU_SCTRL_npu_ctrl8_ts_wr_bwc_bandwidth_END (28)
#define SOC_NPU_SCTRL_npu_ctrl8_ts_wr_bwc_en_START (31)
#define SOC_NPU_SCTRL_npu_ctrl8_ts_wr_bwc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_icfg_ostd0_lvl : 8;
        unsigned int ts_icfg_ostd1_lvl : 8;
        unsigned int flux_en_aicore : 1;
        unsigned int ostd_en_aicore : 1;
        unsigned int flux_en_ts : 1;
        unsigned int ostd_en_ts : 1;
        unsigned int flux_en_aicpu : 1;
        unsigned int ostd_en_aicpu : 1;
        unsigned int flux_en_sdma : 1;
        unsigned int ostd_en_sdma : 1;
        unsigned int reserved_0 : 6;
        unsigned int ts_icfg_ostd0_type : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl9_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl9_ts_icfg_ostd0_lvl_START (0)
#define SOC_NPU_SCTRL_npu_ctrl9_ts_icfg_ostd0_lvl_END (7)
#define SOC_NPU_SCTRL_npu_ctrl9_ts_icfg_ostd1_lvl_START (8)
#define SOC_NPU_SCTRL_npu_ctrl9_ts_icfg_ostd1_lvl_END (15)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_aicore_START (16)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_aicore_END (16)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_aicore_START (17)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_aicore_END (17)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_ts_START (18)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_ts_END (18)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_ts_START (19)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_ts_END (19)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_aicpu_START (20)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_aicpu_END (20)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_aicpu_START (21)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_aicpu_END (21)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_sdma_START (22)
#define SOC_NPU_SCTRL_npu_ctrl9_flux_en_sdma_END (22)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_sdma_START (23)
#define SOC_NPU_SCTRL_npu_ctrl9_ostd_en_sdma_END (23)
#define SOC_NPU_SCTRL_npu_ctrl9_ts_icfg_ostd0_type_START (30)
#define SOC_NPU_SCTRL_npu_ctrl9_ts_icfg_ostd0_type_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LS : 1;
        unsigned int DS : 1;
        unsigned int reserved_0: 6;
        unsigned int TEST : 3;
        unsigned int TESTR : 3;
        unsigned int TESTW : 2;
        unsigned int TRA : 2;
        unsigned int reserved_1: 14;
    } reg;
} SOC_NPU_SCTRL_npu_ctrl10_UNION;
#endif
#define SOC_NPU_SCTRL_npu_ctrl10_LS_START (0)
#define SOC_NPU_SCTRL_npu_ctrl10_LS_END (0)
#define SOC_NPU_SCTRL_npu_ctrl10_DS_START (1)
#define SOC_NPU_SCTRL_npu_ctrl10_DS_END (1)
#define SOC_NPU_SCTRL_npu_ctrl10_TEST_START (8)
#define SOC_NPU_SCTRL_npu_ctrl10_TEST_END (10)
#define SOC_NPU_SCTRL_npu_ctrl10_TESTR_START (11)
#define SOC_NPU_SCTRL_npu_ctrl10_TESTR_END (13)
#define SOC_NPU_SCTRL_npu_ctrl10_TESTW_START (14)
#define SOC_NPU_SCTRL_npu_ctrl10_TESTW_END (15)
#define SOC_NPU_SCTRL_npu_ctrl10_TRA_START (16)
#define SOC_NPU_SCTRL_npu_ctrl10_TRA_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ls : 1;
        unsigned int ds : 1;
        unsigned int reserved_0: 1;
        unsigned int testr : 3;
        unsigned int testw : 2;
        unsigned int test : 3;
        unsigned int reserved_1: 5;
        unsigned int tra : 2;
        unsigned int reserved_2: 14;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL11_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL11_ls_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL11_ls_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL11_ds_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL11_ds_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL11_testr_START (3)
#define SOC_NPU_SCTRL_NPU_CTRL11_testr_END (5)
#define SOC_NPU_SCTRL_NPU_CTRL11_testw_START (6)
#define SOC_NPU_SCTRL_NPU_CTRL11_testw_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL11_test_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL11_test_END (10)
#define SOC_NPU_SCTRL_NPU_CTRL11_tra_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL11_tra_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ls : 1;
        unsigned int ds : 1;
        unsigned int reserved_0: 2;
        unsigned int testr : 2;
        unsigned int testw : 2;
        unsigned int test : 3;
        unsigned int tra : 2;
        unsigned int reserved_1: 19;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL12_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL12_ls_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL12_ls_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL12_ds_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL12_ds_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL12_testr_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL12_testr_END (5)
#define SOC_NPU_SCTRL_NPU_CTRL12_testw_START (6)
#define SOC_NPU_SCTRL_NPU_CTRL12_testw_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL12_test_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL12_test_END (10)
#define SOC_NPU_SCTRL_NPU_CTRL12_tra_START (11)
#define SOC_NPU_SCTRL_NPU_CTRL12_tra_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ls : 1;
        unsigned int ds : 1;
        unsigned int reserved_0: 1;
        unsigned int testr : 3;
        unsigned int testw : 2;
        unsigned int test : 3;
        unsigned int reserved_1: 5;
        unsigned int tra : 2;
        unsigned int reserved_2: 14;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL13_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL13_ls_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL13_ls_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL13_ds_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL13_ds_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL13_testr_START (3)
#define SOC_NPU_SCTRL_NPU_CTRL13_testr_END (5)
#define SOC_NPU_SCTRL_NPU_CTRL13_testw_START (6)
#define SOC_NPU_SCTRL_NPU_CTRL13_testw_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL13_test_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL13_test_END (10)
#define SOC_NPU_SCTRL_NPU_CTRL13_tra_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL13_tra_END (17)
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
} SOC_NPU_SCTRL_NPU_CTRL14_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_cfg_valid_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_cfg_valid_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_en_START (1)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_en_END (1)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_cmd_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_cmd_END (5)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_ctrl_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_ctrl_END (13)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_msg_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL14_pa_msg_END (31)
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
} SOC_NPU_SCTRL_NPU_CTRL15_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL15_tidm_en_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL15_tidm_en_END (0)
#define SOC_NPU_SCTRL_NPU_CTRL15_tihpm_mode_START (4)
#define SOC_NPU_SCTRL_NPU_CTRL15_tihpm_mode_END (6)
#define SOC_NPU_SCTRL_NPU_CTRL15_tidm_div_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL15_tidm_div_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_mem_ds_in : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL16_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL16_aic_mem_ds_in_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL16_aic_mem_ds_in_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int npu_stat_bwc_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int npu_stat_bwc_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int npu_stat_bwc_en : 1;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL17_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL17_npu_stat_bwc_saturation_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL17_npu_stat_bwc_saturation_END (13)
#define SOC_NPU_SCTRL_NPU_CTRL17_npu_stat_bwc_bandwidth_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL17_npu_stat_bwc_bandwidth_END (28)
#define SOC_NPU_SCTRL_NPU_CTRL17_npu_stat_bwc_en_START (31)
#define SOC_NPU_SCTRL_NPU_CTRL17_npu_stat_bwc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_sid_bypass : 8;
        unsigned int aic_sid_nobypass : 8;
        unsigned int aic_sid_sel : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL18_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL18_aic_sid_bypass_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL18_aic_sid_bypass_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL18_aic_sid_nobypass_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL18_aic_sid_nobypass_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL18_aic_sid_sel_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL18_aic_sid_sel_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_sid_bypass : 8;
        unsigned int dma_sid_nobypass : 8;
        unsigned int dma_sid_sel : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_NPU_SCTRL_NPU_CTRL19_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_CTRL19_dma_sid_bypass_START (0)
#define SOC_NPU_SCTRL_NPU_CTRL19_dma_sid_bypass_END (7)
#define SOC_NPU_SCTRL_NPU_CTRL19_dma_sid_nobypass_START (8)
#define SOC_NPU_SCTRL_NPU_CTRL19_dma_sid_nobypass_END (15)
#define SOC_NPU_SCTRL_NPU_CTRL19_dma_sid_sel_START (16)
#define SOC_NPU_SCTRL_NPU_CTRL19_dma_sid_sel_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 10;
        unsigned int etf_full_npu_cssys : 1;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_NPU_SCTRL_NPU_STAT0_UNION;
#endif
#define SOC_NPU_SCTRL_NPU_STAT0_etf_full_npu_cssys_START (10)
#define SOC_NPU_SCTRL_NPU_STAT0_etf_full_npu_cssys_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm_opc : 10;
        unsigned int hpm_opc_vld : 1;
        unsigned int reserved_0 : 5;
        unsigned int hpmx_opc : 10;
        unsigned int hpmx_opc_vld : 1;
        unsigned int aicore_mem_ds_out : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_SCTRL_npu_stat1_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat1_hpm_opc_START (0)
#define SOC_NPU_SCTRL_npu_stat1_hpm_opc_END (9)
#define SOC_NPU_SCTRL_npu_stat1_hpm_opc_vld_START (10)
#define SOC_NPU_SCTRL_npu_stat1_hpm_opc_vld_END (10)
#define SOC_NPU_SCTRL_npu_stat1_hpmx_opc_START (16)
#define SOC_NPU_SCTRL_npu_stat1_hpmx_opc_END (25)
#define SOC_NPU_SCTRL_npu_stat1_hpmx_opc_vld_START (26)
#define SOC_NPU_SCTRL_npu_stat1_hpmx_opc_vld_END (26)
#define SOC_NPU_SCTRL_npu_stat1_aicore_mem_ds_out_START (27)
#define SOC_NPU_SCTRL_npu_stat1_aicore_mem_ds_out_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_sample_ack : 1;
        unsigned int qactive_col : 1;
        unsigned int qacceptn_col : 1;
        unsigned int qdeny_col : 1;
        unsigned int gic_pactive : 1;
        unsigned int gic_paccept : 1;
        unsigned int gic_pdeny : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_NPU_SCTRL_npu_stat2_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat2_gic_sample_ack_START (0)
#define SOC_NPU_SCTRL_npu_stat2_gic_sample_ack_END (0)
#define SOC_NPU_SCTRL_npu_stat2_qactive_col_START (1)
#define SOC_NPU_SCTRL_npu_stat2_qactive_col_END (1)
#define SOC_NPU_SCTRL_npu_stat2_qacceptn_col_START (2)
#define SOC_NPU_SCTRL_npu_stat2_qacceptn_col_END (2)
#define SOC_NPU_SCTRL_npu_stat2_qdeny_col_START (3)
#define SOC_NPU_SCTRL_npu_stat2_qdeny_col_END (3)
#define SOC_NPU_SCTRL_npu_stat2_gic_pactive_START (4)
#define SOC_NPU_SCTRL_npu_stat2_gic_pactive_END (4)
#define SOC_NPU_SCTRL_npu_stat2_gic_paccept_START (5)
#define SOC_NPU_SCTRL_npu_stat2_gic_paccept_END (5)
#define SOC_NPU_SCTRL_npu_stat2_gic_pdeny_START (6)
#define SOC_NPU_SCTRL_npu_stat2_gic_pdeny_END (6)
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
} SOC_NPU_SCTRL_npu_stat3_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat3_pasensor_hci_a_out_START (0)
#define SOC_NPU_SCTRL_npu_stat3_pasensor_hci_a_out_END (8)
#define SOC_NPU_SCTRL_npu_stat3_pasensor_hci_o_out_START (12)
#define SOC_NPU_SCTRL_npu_stat3_pasensor_hci_o_out_END (20)
#define SOC_NPU_SCTRL_npu_stat3_pasensor_valid_START (24)
#define SOC_NPU_SCTRL_npu_stat3_pasensor_valid_END (24)
#define SOC_NPU_SCTRL_npu_stat3_pasensor_cfg_ready_START (28)
#define SOC_NPU_SCTRL_npu_stat3_pasensor_cfg_ready_END (28)
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
} SOC_NPU_SCTRL_npu_stat4_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat4_pasensor_nbti_a_out_START (0)
#define SOC_NPU_SCTRL_npu_stat4_pasensor_nbti_a_out_END (8)
#define SOC_NPU_SCTRL_npu_stat4_pasensor_nbti_o_out_START (12)
#define SOC_NPU_SCTRL_npu_stat4_pasensor_nbti_o_out_END (20)
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
} SOC_NPU_SCTRL_npu_stat5_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat5_pasensor_hci_a_out_START (0)
#define SOC_NPU_SCTRL_npu_stat5_pasensor_hci_a_out_END (8)
#define SOC_NPU_SCTRL_npu_stat5_pasensor_hci_o_out_START (12)
#define SOC_NPU_SCTRL_npu_stat5_pasensor_hci_o_out_END (20)
#define SOC_NPU_SCTRL_npu_stat5_pasensor_valid_START (24)
#define SOC_NPU_SCTRL_npu_stat5_pasensor_valid_END (24)
#define SOC_NPU_SCTRL_npu_stat5_pasensor_cfg_ready_START (28)
#define SOC_NPU_SCTRL_npu_stat5_pasensor_cfg_ready_END (28)
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
} SOC_NPU_SCTRL_npu_stat6_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat6_pasensor_nbti_a_out_START (0)
#define SOC_NPU_SCTRL_npu_stat6_pasensor_nbti_a_out_END (8)
#define SOC_NPU_SCTRL_npu_stat6_pasensor_nbti_o_out_START (12)
#define SOC_NPU_SCTRL_npu_stat6_pasensor_nbti_o_out_END (20)
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
} SOC_NPU_SCTRL_npu_stat7_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat7_tidm_hpm_code_START (0)
#define SOC_NPU_SCTRL_npu_stat7_tidm_hpm_code_END (8)
#define SOC_NPU_SCTRL_npu_stat7_tidm_hpmx_code_START (9)
#define SOC_NPU_SCTRL_npu_stat7_tidm_hpmx_code_END (17)
#define SOC_NPU_SCTRL_npu_stat7_tidm_tihpm_code_START (18)
#define SOC_NPU_SCTRL_npu_stat7_tidm_tihpm_code_END (26)
#define SOC_NPU_SCTRL_npu_stat7_tidm_finish_valid_START (31)
#define SOC_NPU_SCTRL_npu_stat7_tidm_finish_valid_END (31)
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
} SOC_NPU_SCTRL_npu_stat8_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat8_tidm_hpm_code_START (0)
#define SOC_NPU_SCTRL_npu_stat8_tidm_hpm_code_END (8)
#define SOC_NPU_SCTRL_npu_stat8_tidm_hpmx_code_START (9)
#define SOC_NPU_SCTRL_npu_stat8_tidm_hpmx_code_END (17)
#define SOC_NPU_SCTRL_npu_stat8_tidm_tihpm_code_START (18)
#define SOC_NPU_SCTRL_npu_stat8_tidm_tihpm_code_END (26)
#define SOC_NPU_SCTRL_npu_stat8_tidm_finish_valid_START (31)
#define SOC_NPU_SCTRL_npu_stat8_tidm_finish_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int irpt_s_smmu_aicore_stat : 1;
        unsigned int irpt_s_smmu_sysdma_stat : 1;
        unsigned int wdog_res_ai_stat : 1;
        unsigned int wdog_res_ts_stat : 1;
        unsigned int intr_uart_npu_stat : 1;
        unsigned int gic_ts_sram_int_stat : 1;
        unsigned int npu_trace_int_stat : 1;
        unsigned int gic_wake_request0_stat : 1;
        unsigned int gic_wake_request1_stat : 1;
        unsigned int tcu_irpt_s_stat : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_SCTRL_npu_stat9_UNION;
#endif
#define SOC_NPU_SCTRL_npu_stat9_irpt_s_smmu_aicore_stat_START (0)
#define SOC_NPU_SCTRL_npu_stat9_irpt_s_smmu_aicore_stat_END (0)
#define SOC_NPU_SCTRL_npu_stat9_irpt_s_smmu_sysdma_stat_START (1)
#define SOC_NPU_SCTRL_npu_stat9_irpt_s_smmu_sysdma_stat_END (1)
#define SOC_NPU_SCTRL_npu_stat9_wdog_res_ai_stat_START (2)
#define SOC_NPU_SCTRL_npu_stat9_wdog_res_ai_stat_END (2)
#define SOC_NPU_SCTRL_npu_stat9_wdog_res_ts_stat_START (3)
#define SOC_NPU_SCTRL_npu_stat9_wdog_res_ts_stat_END (3)
#define SOC_NPU_SCTRL_npu_stat9_intr_uart_npu_stat_START (4)
#define SOC_NPU_SCTRL_npu_stat9_intr_uart_npu_stat_END (4)
#define SOC_NPU_SCTRL_npu_stat9_gic_ts_sram_int_stat_START (5)
#define SOC_NPU_SCTRL_npu_stat9_gic_ts_sram_int_stat_END (5)
#define SOC_NPU_SCTRL_npu_stat9_npu_trace_int_stat_START (6)
#define SOC_NPU_SCTRL_npu_stat9_npu_trace_int_stat_END (6)
#define SOC_NPU_SCTRL_npu_stat9_gic_wake_request0_stat_START (7)
#define SOC_NPU_SCTRL_npu_stat9_gic_wake_request0_stat_END (7)
#define SOC_NPU_SCTRL_npu_stat9_gic_wake_request1_stat_START (8)
#define SOC_NPU_SCTRL_npu_stat9_gic_wake_request1_stat_END (8)
#define SOC_NPU_SCTRL_npu_stat9_tcu_irpt_s_stat_START (9)
#define SOC_NPU_SCTRL_npu_stat9_tcu_irpt_s_stat_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
