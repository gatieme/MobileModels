#ifndef __SOC_FCM_LOCAL_ANANKE_CORE_NS_INTERFACE_H__
#define __SOC_FCM_LOCAL_ANANKE_CORE_NS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_ADDR(base) ((base) + (0x82CUL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_ADDR(base) ((base) + (0x868UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_ADDR(base) ((base) + (0x86CUL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_ADDR(base) ((base) + (0x870UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_CLR_CFG_REG_ADDR(base) ((base) + (0x874UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_ADDR(base) ((base) + (0xC18UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_ADDR(base) ((base) + (0xC1CUL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT1_ADDR(base) ((base) + (0xC20UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_ADDR(base) ((base) + (0xC24UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT3_ADDR(base) ((base) + (0xC28UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_ADDR(base) ((base) + (0xC2CUL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_ADDR(base) ((base) + (0xC30UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_LO_ADDR(base) ((base) + (0xC80UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_HI_ADDR(base) ((base) + (0xC84UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_LO_ADDR(base) ((base) + (0xC88UL))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_HI_ADDR(base) ((base) + (0xC8CUL))
#else
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_ADDR(base) ((base) + (0x800))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_ADDR(base) ((base) + (0x814))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_ADDR(base) ((base) + (0x82C))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_ADDR(base) ((base) + (0x868))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_ADDR(base) ((base) + (0x86C))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_ADDR(base) ((base) + (0x870))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_CLR_CFG_REG_ADDR(base) ((base) + (0x874))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_ADDR(base) ((base) + (0xC18))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_ADDR(base) ((base) + (0xC1C))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT1_ADDR(base) ((base) + (0xC20))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_ADDR(base) ((base) + (0xC24))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT3_ADDR(base) ((base) + (0xC28))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_ADDR(base) ((base) + (0xC2C))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_ADDR(base) ((base) + (0xC30))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_LO_ADDR(base) ((base) + (0xC80))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_HI_ADDR(base) ((base) + (0xC84))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_LO_ADDR(base) ((base) + (0xC88))
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_HI_ADDR(base) ((base) + (0xC8C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_db_mem_test : 3;
        unsigned int reserved_0 : 1;
        unsigned int l2_db_mem_tselw : 2;
        unsigned int reserved_1 : 2;
        unsigned int l2_db_mem_tselr : 2;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_l2_db_mem_test_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_l2_db_mem_test_END (2)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_l2_db_mem_tselw_START (4)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_l2_db_mem_tselw_END (5)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_l2_db_mem_tselr_START (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_L2DB_MEM_CTL_CFG_REG_l2_db_mem_tselr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l2_data_mem_test : 3;
        unsigned int reserved_0 : 1;
        unsigned int l2_data_mem_tselw : 2;
        unsigned int reserved_1 : 2;
        unsigned int l2_data_mem_tselr : 2;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_l2_data_mem_test_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_l2_data_mem_test_END (2)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_l2_data_mem_tselw_START (4)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_l2_data_mem_tselw_END (5)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_l2_data_mem_tselr_START (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_L2_DATA_MEM_CTL_CFG_REG_l2_data_mem_tselr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int others_mem_test : 3;
        unsigned int reserved_0 : 1;
        unsigned int others_mem_tselw : 2;
        unsigned int reserved_1 : 2;
        unsigned int others_mem_tselr : 2;
        unsigned int reserved_2 : 22;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_others_mem_test_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_others_mem_test_END (2)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_others_mem_tselw_START (4)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_others_mem_tselw_END (5)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_others_mem_tselr_START (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_Other_MEM_CTL_CFG_REG_others_mem_tselr_END (9)
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
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_hpm_en_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_hpm_en_END (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_hpmx_en_START (4)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_hpmx_en_END (4)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_hpm_clk_div_START (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_CFG_REG_hpm_clk_div_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pasensor_cfg_valid : 1;
        unsigned int pasensor_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int pasensor_cmd : 2;
        unsigned int reserved_1 : 2;
        unsigned int pasensor_ctrl : 6;
        unsigned int reserved_2 : 2;
        unsigned int pasensor_msg : 16;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_cfg_valid_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_cfg_valid_END (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_en_START (1)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_en_END (1)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_cmd_START (4)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_cmd_END (5)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_ctrl_START (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_ctrl_END (13)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_msg_START (16)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PASENSOR_CFG_REG_pasensor_msg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tidm_en : 1;
        unsigned int reserved_0: 3;
        unsigned int tidm_mode : 3;
        unsigned int reserved_1: 1;
        unsigned int tidm_div : 6;
        unsigned int reserved_2: 18;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_tidm_en_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_tidm_en_END (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_tidm_mode_START (4)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_tidm_mode_END (6)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_tidm_div_START (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_CFG_REG_tidm_div_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latch_debug_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_CLR_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_CLR_CFG_REG_latch_debug_en_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_CLR_CFG_REG_latch_debug_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm_opc : 10;
        unsigned int reserved_0 : 2;
        unsigned int hpm_opc_valid : 1;
        unsigned int reserved_1 : 3;
        unsigned int hpmx_opc : 10;
        unsigned int reserved_2 : 2;
        unsigned int hpmx_opc_vld : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpm_opc_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpm_opc_END (9)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpm_opc_valid_START (12)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpm_opc_valid_END (12)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpmx_opc_START (16)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpmx_opc_END (25)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpmx_opc_vld_START (28)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_HPM_STAT_hpmx_opc_vld_END (28)
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
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_hci_a_out_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_hci_a_out_END (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_hci_o_out_START (12)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_hci_o_out_END (20)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_valid_START (24)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_valid_END (24)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_cfg_ready_START (28)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT0_pasensor_cfg_ready_END (28)
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
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT1_pasensor_nbti_a_out_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT1_pasensor_nbti_a_out_END (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT1_pasensor_nbti_o_out_START (12)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT1_pasensor_nbti_o_out_END (20)
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
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_hci_a_out_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_hci_a_out_END (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_hci_o_out_START (12)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_hci_o_out_END (20)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_valid_START (24)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_valid_END (24)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_cfg_ready_START (28)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT2_pasensor_cfg_ready_END (28)
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
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT3_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT3_pasensor_nbti_a_out_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT3_pasensor_nbti_a_out_END (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT3_pasensor_nbti_o_out_START (12)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_PA_STAT3_pasensor_nbti_o_out_END (20)
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
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_hpm_code_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_hpm_code_END (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_hpmx_code_START (9)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_hpmx_code_END (17)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_tihpm_code_START (18)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_tihpm_code_END (26)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_finish_valid_START (31)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT0_tidm_finish_valid_END (31)
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
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_hpm_code_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_hpm_code_END (8)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_hpmx_code_START (9)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_hpmx_code_END (17)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_tihpm_code_START (18)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_tihpm_code_END (26)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_finish_valid_START (31)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_TIDM_STAT1_tidm_finish_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_pc_low : 32;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_LO_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_LO_core_pc_low_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_LO_core_pc_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_pc_high : 32;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_HI_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_HI_core_pc_high_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_PC_HI_core_pc_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_sp_low : 32;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_LO_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_LO_core_sp_low_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_LO_core_sp_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_sp_high : 32;
    } reg;
} SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_HI_UNION;
#endif
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_HI_core_sp_high_START (0)
#define SOC_FCM_LOCAL_ANANKE_CORE_NS_ANANKE_DBG_SP_HI_core_sp_high_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
