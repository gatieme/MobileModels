#ifndef __SOC_HSDT_SYSCTRL_INTERFACE_H__
#define __SOC_HSDT_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_ADDR(base) ((base) + (0x200UL))
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_ADDR(base) ((base) + (0x204UL))
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_ADDR(base) ((base) + (0x214UL))
#define SOC_HSDT_Sysctrl_sdio_hresp_ctrl_ADDR(base) ((base) + (0x300UL))
#define SOC_HSDT_Sysctrl_HSDT_PLL_LOCK_ADDR(base) ((base) + (0x308UL))
#define SOC_HSDT_Sysctrl_HSDT_TEST_POINT_SEL_ADDR(base) ((base) + (0x30CUL))
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_ADDR(base) ((base) + (0x310UL))
#define SOC_HSDT_Sysctrl_PCIE_MCU_P2H_BRG_CLKEN_ADDR(base) ((base) + (0x314UL))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_ADDR(base) ((base) + (0x320UL))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_ADDR(base) ((base) + (0x324UL))
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_ADDR(base) ((base) + (0x328UL))
#define SOC_HSDT_Sysctrl_cc_path_sel_ADDR(base) ((base) + (0xD00UL))
#define SOC_HSDT_Sysctrl_cc_secfg_ADDR(base) ((base) + (0xD04UL))
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_ADDR(base) ((base) + (0xD08UL))
#define SOC_HSDT_Sysctrl_cc_trng_data_ADDR(base) ((base) + (0xD0CUL))
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_ADDR(base) ((base) + (0xD10UL))
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_ADDR(base) ((base) + (0xD14UL))
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_ADDR(base) ((base) + (0xD18UL))
#define SOC_HSDT_Sysctrl_cc_powerdown_en_ADDR(base) ((base) + (0xD50UL))
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_ADDR(base) ((base) + (0xD54UL))
#define SOC_HSDT_Sysctrl_HSDT_MID0_ADDR(base) ((base) + (0xE00UL))
#define SOC_HSDT_Sysctrl_HSDT_MID1_ADDR(base) ((base) + (0xE04UL))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_ADDR(base) ((base) + (0xE08UL))
#else
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_ADDR(base) ((base) + (0x200))
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_ADDR(base) ((base) + (0x204))
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_ADDR(base) ((base) + (0x214))
#define SOC_HSDT_Sysctrl_sdio_hresp_ctrl_ADDR(base) ((base) + (0x300))
#define SOC_HSDT_Sysctrl_HSDT_PLL_LOCK_ADDR(base) ((base) + (0x308))
#define SOC_HSDT_Sysctrl_HSDT_TEST_POINT_SEL_ADDR(base) ((base) + (0x30C))
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_ADDR(base) ((base) + (0x310))
#define SOC_HSDT_Sysctrl_PCIE_MCU_P2H_BRG_CLKEN_ADDR(base) ((base) + (0x314))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_ADDR(base) ((base) + (0x320))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_ADDR(base) ((base) + (0x324))
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_ADDR(base) ((base) + (0x328))
#define SOC_HSDT_Sysctrl_cc_path_sel_ADDR(base) ((base) + (0xD00))
#define SOC_HSDT_Sysctrl_cc_secfg_ADDR(base) ((base) + (0xD04))
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_ADDR(base) ((base) + (0xD08))
#define SOC_HSDT_Sysctrl_cc_trng_data_ADDR(base) ((base) + (0xD0C))
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_ADDR(base) ((base) + (0xD10))
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_ADDR(base) ((base) + (0xD14))
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_ADDR(base) ((base) + (0xD18))
#define SOC_HSDT_Sysctrl_cc_powerdown_en_ADDR(base) ((base) + (0xD50))
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_ADDR(base) ((base) + (0xD54))
#define SOC_HSDT_Sysctrl_HSDT_MID0_ADDR(base) ((base) + (0xE00))
#define SOC_HSDT_Sysctrl_HSDT_MID1_ADDR(base) ((base) + (0xE04))
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_ADDR(base) ((base) + (0xE08))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie0_aw_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie0_aw_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie0_aw_lmtr_en : 1;
    } reg;
} SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_UNION;
#endif
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_saturation_START (0)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_saturation_END (13)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_bandwidth_START (16)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_bandwidth_END (28)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_en_START (31)
#define SOC_HSDT_Sysctrl_PCIE0_W_QOS_LMTR_pcie0_aw_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie0_ar_lmtr_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int pcie0_ar_lmtr_bandwidth : 13;
        unsigned int reserved_1 : 2;
        unsigned int pcie0_ar_lmtr_en : 1;
    } reg;
} SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_UNION;
#endif
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_saturation_START (0)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_saturation_END (13)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_bandwidth_START (16)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_bandwidth_END (28)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_en_START (31)
#define SOC_HSDT_Sysctrl_PCIE0_R_QOS_LMTR_pcie0_ar_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_noc_pcie0_cfg_timeout_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_sc_noc_pcie0_cfg_timeout_en_START (0)
#define SOC_HSDT_Sysctrl_pcie_axi_slv_noc_timeout_en_sc_noc_pcie0_cfg_timeout_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_sdio_hresp_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_sdio_hresp_ctrl_UNION;
#endif
#define SOC_HSDT_Sysctrl_sdio_hresp_ctrl_sc_sdio_hresp_ctrl_START (0)
#define SOC_HSDT_Sysctrl_sdio_hresp_ctrl_sc_sdio_hresp_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pll_lock_req_en : 1;
        unsigned int pll_lock_req_value : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_Sysctrl_HSDT_PLL_LOCK_UNION;
#endif
#define SOC_HSDT_Sysctrl_HSDT_PLL_LOCK_pll_lock_req_en_START (0)
#define SOC_HSDT_Sysctrl_HSDT_PLL_LOCK_pll_lock_req_en_END (0)
#define SOC_HSDT_Sysctrl_HSDT_PLL_LOCK_pll_lock_req_value_START (1)
#define SOC_HSDT_Sysctrl_HSDT_PLL_LOCK_pll_lock_req_value_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_point_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_Sysctrl_HSDT_TEST_POINT_SEL_UNION;
#endif
#define SOC_HSDT_Sysctrl_HSDT_TEST_POINT_SEL_test_point_sel_START (0)
#define SOC_HSDT_Sysctrl_HSDT_TEST_POINT_SEL_test_point_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie0_mcu_uce_ipc_mbx_int : 2;
        unsigned int pcie0_mcu_uce_ipc_int : 2;
        unsigned int pcie0_mcu_uce_wdg_intr : 1;
        unsigned int pcie_pcs_intr : 1;
        unsigned int pcie_link_down_int : 1;
        unsigned int pcie0_mcu_uce_m3_idle : 1;
        unsigned int pcie0_mcu_uce_sys_idle : 1;
        unsigned int pcie0_mcu_uce_test_point : 8;
        unsigned int reserved : 15;
    } reg;
} SOC_HSDT_Sysctrl_pcie_mcu_stat_UNION;
#endif
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_ipc_mbx_int_START (0)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_ipc_mbx_int_END (1)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_ipc_int_START (2)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_ipc_int_END (3)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_wdg_intr_START (4)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_wdg_intr_END (4)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie_pcs_intr_START (5)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie_pcs_intr_END (5)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie_link_down_int_START (6)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie_link_down_int_END (6)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_m3_idle_START (7)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_m3_idle_END (7)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_sys_idle_START (8)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_sys_idle_END (8)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_test_point_START (9)
#define SOC_HSDT_Sysctrl_pcie_mcu_stat_pcie0_mcu_uce_test_point_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcie_mcu_p2h_brg_clken : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_PCIE_MCU_P2H_BRG_CLKEN_UNION;
#endif
#define SOC_HSDT_Sysctrl_PCIE_MCU_P2H_BRG_CLKEN_pcie_mcu_p2h_brg_clken_START (0)
#define SOC_HSDT_Sysctrl_PCIE_MCU_P2H_BRG_CLKEN_pcie_mcu_p2h_brg_clken_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awmmuswid_s0 : 8;
        unsigned int awmmusid_s0 : 8;
        unsigned int awmmussid_s0 : 8;
        unsigned int awmmussidv_s0 : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_UNION;
#endif
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmuswid_s0_START (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmuswid_s0_END (7)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmusid_s0_START (8)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmusid_s0_END (15)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussid_s0_START (16)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussid_s0_END (23)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussidv_s0_START (24)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AW_NS_awmmussidv_s0_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int armmuswid_s0 : 8;
        unsigned int armmusid_s0 : 8;
        unsigned int armmussid_s0 : 8;
        unsigned int armmussidv_s0 : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_UNION;
#endif
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmuswid_s0_START (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmuswid_s0_END (7)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmusid_s0_START (8)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmusid_s0_END (15)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussid_s0_START (16)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussid_s0_END (23)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussidv_s0_START (24)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_AR_NS_armmussidv_s0_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smmu_mem_ctrl_sd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_UNION;
#endif
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_smmu_mem_ctrl_sd_START (0)
#define SOC_HSDT_Sysctrl_smmu_mem_ctrl_sd_smmu_mem_ctrl_sd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_path_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_Sysctrl_cc_path_sel_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_path_sel_cc_path_sel_START (0)
#define SOC_HSDT_Sysctrl_cc_path_sel_cc_path_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_secfg : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc_secfg_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_secfg_cc_secfg_START (0)
#define SOC_HSDT_Sysctrl_cc_secfg_cc_secfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_secfg_vld_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_cc_secfg_vld_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_cc_secfg_vld_en_START (0)
#define SOC_HSDT_Sysctrl_cc_secfg_vld_en_cc_secfg_vld_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_trng_data : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc_trng_data_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_trng_data_cc_trng_data_START (0)
#define SOC_HSDT_Sysctrl_cc_trng_data_cc_trng_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_trng_vld_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_cc_trng_vld_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_cc_trng_vld_en_START (0)
#define SOC_HSDT_Sysctrl_cc_trng_vld_en_cc_trng_vld_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc712_spmram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_cc712_spmram_mem_ctrl_START (0)
#define SOC_HSDT_Sysctrl_cc712_spmram_mem_ctrl_cc712_spmram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc712_reserved_ctrl : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc712_reserved_ctrl_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_cc712_reserved_ctrl_START (0)
#define SOC_HSDT_Sysctrl_cc712_reserved_ctrl_cc712_reserved_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_powerdown_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT_Sysctrl_cc_powerdown_en_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc_powerdown_en_cc_powerdown_en_START (0)
#define SOC_HSDT_Sysctrl_cc_powerdown_en_cc_powerdown_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc712_reserved_stat : 32;
    } reg;
} SOC_HSDT_Sysctrl_cc712_reserved_stat_UNION;
#endif
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_cc712_reserved_stat_START (0)
#define SOC_HSDT_Sysctrl_cc712_reserved_stat_cc712_reserved_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_sdio_mid : 6;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 6;
        unsigned int reserved_4 : 2;
        unsigned int sc_cc712_mid : 6;
        unsigned int reserved_5 : 2;
    } reg;
} SOC_HSDT_Sysctrl_HSDT_MID0_UNION;
#endif
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_sdio_mid_START (0)
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_sdio_mid_END (5)
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_cc712_mid_START (24)
#define SOC_HSDT_Sysctrl_HSDT_MID0_sc_cc712_mid_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_pcie0_mid : 6;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 6;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 6;
        unsigned int reserved_6 : 2;
    } reg;
} SOC_HSDT_Sysctrl_HSDT_MID1_UNION;
#endif
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_pcie0_mid_START (0)
#define SOC_HSDT_Sysctrl_HSDT_MID1_sc_pcie0_mid_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awmmusecsid_s0 : 1;
        unsigned int armmusecsid_s0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_UNION;
#endif
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_awmmusecsid_s0_START (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_awmmusecsid_s0_END (0)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_armmusecsid_s0_START (1)
#define SOC_HSDT_Sysctrl_SC_SMMU_CTRL_S_armmusecsid_s0_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
