#ifndef __SOC_NPU_TZPC_INTERFACE_H__
#define __SOC_NPU_TZPC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TZPC_R0SIZE_ADDR(base) ((base) + (0x000UL))
#define SOC_NPU_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800UL))
#define SOC_NPU_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804UL))
#define SOC_NPU_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808UL))
#define SOC_NPU_TZPC_DECPROT1STAT_ADDR(base) ((base) + (0x80CUL))
#define SOC_NPU_TZPC_DECPROT1SET_ADDR(base) ((base) + (0x810UL))
#define SOC_NPU_TZPC_DECPROT1CLR_ADDR(base) ((base) + (0x814UL))
#define SOC_NPU_TZPC_DECPROT2STAT_ADDR(base) ((base) + (0x818UL))
#define SOC_NPU_TZPC_DECPROT2SET_ADDR(base) ((base) + (0x81CUL))
#define SOC_NPU_TZPC_DECPROT2CLR_ADDR(base) ((base) + (0x820UL))
#define SOC_NPU_TZPC_DECPROT3STAT_ADDR(base) ((base) + (0x824UL))
#define SOC_NPU_TZPC_DECPROT3SET_ADDR(base) ((base) + (0x828UL))
#define SOC_NPU_TZPC_DECPROT3CLR_ADDR(base) ((base) + (0x82CUL))
#else
#define SOC_NPU_TZPC_R0SIZE_ADDR(base) ((base) + (0x000))
#define SOC_NPU_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800))
#define SOC_NPU_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804))
#define SOC_NPU_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808))
#define SOC_NPU_TZPC_DECPROT1STAT_ADDR(base) ((base) + (0x80C))
#define SOC_NPU_TZPC_DECPROT1SET_ADDR(base) ((base) + (0x810))
#define SOC_NPU_TZPC_DECPROT1CLR_ADDR(base) ((base) + (0x814))
#define SOC_NPU_TZPC_DECPROT2STAT_ADDR(base) ((base) + (0x818))
#define SOC_NPU_TZPC_DECPROT2SET_ADDR(base) ((base) + (0x81C))
#define SOC_NPU_TZPC_DECPROT2CLR_ADDR(base) ((base) + (0x820))
#define SOC_NPU_TZPC_DECPROT3STAT_ADDR(base) ((base) + (0x824))
#define SOC_NPU_TZPC_DECPROT3SET_ADDR(base) ((base) + (0x828))
#define SOC_NPU_TZPC_DECPROT3CLR_ADDR(base) ((base) + (0x82C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpcr0size : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_TZPC_R0SIZE_UNION;
#endif
#define SOC_NPU_TZPC_R0SIZE_tzpcr0size_START (0)
#define SOC_NPU_TZPC_R0SIZE_tzpcr0size_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int firewall_en_l2buf : 1;
        unsigned int err_resp_l2buf : 1;
        unsigned int el_sel : 1;
        unsigned int secure_ctrl_l2buf : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_TZPC_DECPROT0STAT_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT0STAT_firewall_en_l2buf_START (0)
#define SOC_NPU_TZPC_DECPROT0STAT_firewall_en_l2buf_END (0)
#define SOC_NPU_TZPC_DECPROT0STAT_err_resp_l2buf_START (1)
#define SOC_NPU_TZPC_DECPROT0STAT_err_resp_l2buf_END (1)
#define SOC_NPU_TZPC_DECPROT0STAT_el_sel_START (2)
#define SOC_NPU_TZPC_DECPROT0STAT_el_sel_END (2)
#define SOC_NPU_TZPC_DECPROT0STAT_secure_ctrl_l2buf_START (3)
#define SOC_NPU_TZPC_DECPROT0STAT_secure_ctrl_l2buf_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int firewall_en_l2buf : 1;
        unsigned int err_resp_l2buf : 1;
        unsigned int el_sel : 1;
        unsigned int secure_ctrl_l2buf : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_TZPC_DECPROT0SET_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT0SET_firewall_en_l2buf_START (0)
#define SOC_NPU_TZPC_DECPROT0SET_firewall_en_l2buf_END (0)
#define SOC_NPU_TZPC_DECPROT0SET_err_resp_l2buf_START (1)
#define SOC_NPU_TZPC_DECPROT0SET_err_resp_l2buf_END (1)
#define SOC_NPU_TZPC_DECPROT0SET_el_sel_START (2)
#define SOC_NPU_TZPC_DECPROT0SET_el_sel_END (2)
#define SOC_NPU_TZPC_DECPROT0SET_secure_ctrl_l2buf_START (3)
#define SOC_NPU_TZPC_DECPROT0SET_secure_ctrl_l2buf_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int firewall_en_l2buf : 1;
        unsigned int err_resp_l2buf : 1;
        unsigned int el_sel : 1;
        unsigned int secure_ctrl_l2buf : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_TZPC_DECPROT0CLR_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT0CLR_firewall_en_l2buf_START (0)
#define SOC_NPU_TZPC_DECPROT0CLR_firewall_en_l2buf_END (0)
#define SOC_NPU_TZPC_DECPROT0CLR_err_resp_l2buf_START (1)
#define SOC_NPU_TZPC_DECPROT0CLR_err_resp_l2buf_END (1)
#define SOC_NPU_TZPC_DECPROT0CLR_el_sel_START (2)
#define SOC_NPU_TZPC_DECPROT0CLR_el_sel_END (2)
#define SOC_NPU_TZPC_DECPROT0CLR_secure_ctrl_l2buf_START (3)
#define SOC_NPU_TZPC_DECPROT0CLR_secure_ctrl_l2buf_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int firewall_en_npucfg : 1;
        unsigned int err_resp_npucfg : 1;
        unsigned int el_sel : 1;
        unsigned int secure_ctrl_npucfg : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_TZPC_DECPROT1STAT_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT1STAT_firewall_en_npucfg_START (0)
#define SOC_NPU_TZPC_DECPROT1STAT_firewall_en_npucfg_END (0)
#define SOC_NPU_TZPC_DECPROT1STAT_err_resp_npucfg_START (1)
#define SOC_NPU_TZPC_DECPROT1STAT_err_resp_npucfg_END (1)
#define SOC_NPU_TZPC_DECPROT1STAT_el_sel_START (2)
#define SOC_NPU_TZPC_DECPROT1STAT_el_sel_END (2)
#define SOC_NPU_TZPC_DECPROT1STAT_secure_ctrl_npucfg_START (3)
#define SOC_NPU_TZPC_DECPROT1STAT_secure_ctrl_npucfg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int firewall_en_npucfg : 1;
        unsigned int err_resp_npucfg : 1;
        unsigned int el_sel : 1;
        unsigned int secure_ctrl_npucfg : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_TZPC_DECPROT1SET_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT1SET_firewall_en_npucfg_START (0)
#define SOC_NPU_TZPC_DECPROT1SET_firewall_en_npucfg_END (0)
#define SOC_NPU_TZPC_DECPROT1SET_err_resp_npucfg_START (1)
#define SOC_NPU_TZPC_DECPROT1SET_err_resp_npucfg_END (1)
#define SOC_NPU_TZPC_DECPROT1SET_el_sel_START (2)
#define SOC_NPU_TZPC_DECPROT1SET_el_sel_END (2)
#define SOC_NPU_TZPC_DECPROT1SET_secure_ctrl_npucfg_START (3)
#define SOC_NPU_TZPC_DECPROT1SET_secure_ctrl_npucfg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int firewall_en_npucfg : 1;
        unsigned int err_resp_npucfg : 1;
        unsigned int el_sel : 1;
        unsigned int secure_ctrl_npucfg : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_TZPC_DECPROT1CLR_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT1CLR_firewall_en_npucfg_START (0)
#define SOC_NPU_TZPC_DECPROT1CLR_firewall_en_npucfg_END (0)
#define SOC_NPU_TZPC_DECPROT1CLR_err_resp_npucfg_START (1)
#define SOC_NPU_TZPC_DECPROT1CLR_err_resp_npucfg_END (1)
#define SOC_NPU_TZPC_DECPROT1CLR_el_sel_START (2)
#define SOC_NPU_TZPC_DECPROT1CLR_el_sel_END (2)
#define SOC_NPU_TZPC_DECPROT1CLR_secure_ctrl_npucfg_START (3)
#define SOC_NPU_TZPC_DECPROT1CLR_secure_ctrl_npucfg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipc_s : 1;
        unsigned int ipc_ns : 1;
        unsigned int crg : 1;
        unsigned int sctrl : 1;
        unsigned int uart : 1;
        unsigned int hw_exp_irq : 1;
        unsigned int l2buf_cfg : 1;
        unsigned int npu_dpm : 1;
        unsigned int sysdma_cfg : 1;
        unsigned int aic_smmu_cfg : 1;
        unsigned int sysdma_smmu_cfg : 1;
        unsigned int tcu_cfg : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_TZPC_DECPROT2STAT_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT2STAT_ipc_s_START (0)
#define SOC_NPU_TZPC_DECPROT2STAT_ipc_s_END (0)
#define SOC_NPU_TZPC_DECPROT2STAT_ipc_ns_START (1)
#define SOC_NPU_TZPC_DECPROT2STAT_ipc_ns_END (1)
#define SOC_NPU_TZPC_DECPROT2STAT_crg_START (2)
#define SOC_NPU_TZPC_DECPROT2STAT_crg_END (2)
#define SOC_NPU_TZPC_DECPROT2STAT_sctrl_START (3)
#define SOC_NPU_TZPC_DECPROT2STAT_sctrl_END (3)
#define SOC_NPU_TZPC_DECPROT2STAT_uart_START (4)
#define SOC_NPU_TZPC_DECPROT2STAT_uart_END (4)
#define SOC_NPU_TZPC_DECPROT2STAT_hw_exp_irq_START (5)
#define SOC_NPU_TZPC_DECPROT2STAT_hw_exp_irq_END (5)
#define SOC_NPU_TZPC_DECPROT2STAT_l2buf_cfg_START (6)
#define SOC_NPU_TZPC_DECPROT2STAT_l2buf_cfg_END (6)
#define SOC_NPU_TZPC_DECPROT2STAT_npu_dpm_START (7)
#define SOC_NPU_TZPC_DECPROT2STAT_npu_dpm_END (7)
#define SOC_NPU_TZPC_DECPROT2STAT_sysdma_cfg_START (8)
#define SOC_NPU_TZPC_DECPROT2STAT_sysdma_cfg_END (8)
#define SOC_NPU_TZPC_DECPROT2STAT_aic_smmu_cfg_START (9)
#define SOC_NPU_TZPC_DECPROT2STAT_aic_smmu_cfg_END (9)
#define SOC_NPU_TZPC_DECPROT2STAT_sysdma_smmu_cfg_START (10)
#define SOC_NPU_TZPC_DECPROT2STAT_sysdma_smmu_cfg_END (10)
#define SOC_NPU_TZPC_DECPROT2STAT_tcu_cfg_START (11)
#define SOC_NPU_TZPC_DECPROT2STAT_tcu_cfg_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipc_s : 1;
        unsigned int ipc_ns : 1;
        unsigned int crg : 1;
        unsigned int sctrl : 1;
        unsigned int uart : 1;
        unsigned int hw_exp_irq : 1;
        unsigned int l2buf_cfg : 1;
        unsigned int npu_dpm : 1;
        unsigned int sysdma_cfg : 1;
        unsigned int aic_smmu_cfg : 1;
        unsigned int sysdma_smmu_cfg : 1;
        unsigned int tcu_cfg : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_TZPC_DECPROT2SET_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT2SET_ipc_s_START (0)
#define SOC_NPU_TZPC_DECPROT2SET_ipc_s_END (0)
#define SOC_NPU_TZPC_DECPROT2SET_ipc_ns_START (1)
#define SOC_NPU_TZPC_DECPROT2SET_ipc_ns_END (1)
#define SOC_NPU_TZPC_DECPROT2SET_crg_START (2)
#define SOC_NPU_TZPC_DECPROT2SET_crg_END (2)
#define SOC_NPU_TZPC_DECPROT2SET_sctrl_START (3)
#define SOC_NPU_TZPC_DECPROT2SET_sctrl_END (3)
#define SOC_NPU_TZPC_DECPROT2SET_uart_START (4)
#define SOC_NPU_TZPC_DECPROT2SET_uart_END (4)
#define SOC_NPU_TZPC_DECPROT2SET_hw_exp_irq_START (5)
#define SOC_NPU_TZPC_DECPROT2SET_hw_exp_irq_END (5)
#define SOC_NPU_TZPC_DECPROT2SET_l2buf_cfg_START (6)
#define SOC_NPU_TZPC_DECPROT2SET_l2buf_cfg_END (6)
#define SOC_NPU_TZPC_DECPROT2SET_npu_dpm_START (7)
#define SOC_NPU_TZPC_DECPROT2SET_npu_dpm_END (7)
#define SOC_NPU_TZPC_DECPROT2SET_sysdma_cfg_START (8)
#define SOC_NPU_TZPC_DECPROT2SET_sysdma_cfg_END (8)
#define SOC_NPU_TZPC_DECPROT2SET_aic_smmu_cfg_START (9)
#define SOC_NPU_TZPC_DECPROT2SET_aic_smmu_cfg_END (9)
#define SOC_NPU_TZPC_DECPROT2SET_sysdma_smmu_cfg_START (10)
#define SOC_NPU_TZPC_DECPROT2SET_sysdma_smmu_cfg_END (10)
#define SOC_NPU_TZPC_DECPROT2SET_tcu_cfg_START (11)
#define SOC_NPU_TZPC_DECPROT2SET_tcu_cfg_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ipc_s : 1;
        unsigned int ipc_ns : 1;
        unsigned int crg : 1;
        unsigned int sctrl : 1;
        unsigned int uart : 1;
        unsigned int hw_exp_irq : 1;
        unsigned int l2buf_cfg : 1;
        unsigned int npu_dpm : 1;
        unsigned int sysdma_cfg : 1;
        unsigned int aic_smmu_cfg : 1;
        unsigned int sysdma_smmu_cfg : 1;
        unsigned int tcu_cfg : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_TZPC_DECPROT2CLR_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT2CLR_ipc_s_START (0)
#define SOC_NPU_TZPC_DECPROT2CLR_ipc_s_END (0)
#define SOC_NPU_TZPC_DECPROT2CLR_ipc_ns_START (1)
#define SOC_NPU_TZPC_DECPROT2CLR_ipc_ns_END (1)
#define SOC_NPU_TZPC_DECPROT2CLR_crg_START (2)
#define SOC_NPU_TZPC_DECPROT2CLR_crg_END (2)
#define SOC_NPU_TZPC_DECPROT2CLR_sctrl_START (3)
#define SOC_NPU_TZPC_DECPROT2CLR_sctrl_END (3)
#define SOC_NPU_TZPC_DECPROT2CLR_uart_START (4)
#define SOC_NPU_TZPC_DECPROT2CLR_uart_END (4)
#define SOC_NPU_TZPC_DECPROT2CLR_hw_exp_irq_START (5)
#define SOC_NPU_TZPC_DECPROT2CLR_hw_exp_irq_END (5)
#define SOC_NPU_TZPC_DECPROT2CLR_l2buf_cfg_START (6)
#define SOC_NPU_TZPC_DECPROT2CLR_l2buf_cfg_END (6)
#define SOC_NPU_TZPC_DECPROT2CLR_npu_dpm_START (7)
#define SOC_NPU_TZPC_DECPROT2CLR_npu_dpm_END (7)
#define SOC_NPU_TZPC_DECPROT2CLR_sysdma_cfg_START (8)
#define SOC_NPU_TZPC_DECPROT2CLR_sysdma_cfg_END (8)
#define SOC_NPU_TZPC_DECPROT2CLR_aic_smmu_cfg_START (9)
#define SOC_NPU_TZPC_DECPROT2CLR_aic_smmu_cfg_END (9)
#define SOC_NPU_TZPC_DECPROT2CLR_sysdma_smmu_cfg_START (10)
#define SOC_NPU_TZPC_DECPROT2CLR_sysdma_smmu_cfg_END (10)
#define SOC_NPU_TZPC_DECPROT2CLR_tcu_cfg_START (11)
#define SOC_NPU_TZPC_DECPROT2CLR_tcu_cfg_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_tcu : 6;
        unsigned int reserved_0 : 2;
        unsigned int mid_sysdma : 6;
        unsigned int reserved_1 : 2;
        unsigned int mid_aicore : 6;
        unsigned int reserved_2 : 2;
        unsigned int gict_allow_ns : 1;
        unsigned int gicd_allow_ns : 1;
        unsigned int protected_nsaid_en : 1;
        unsigned int npu_mst_secure : 1;
        unsigned int protected_nsaid_en_mem : 1;
        unsigned int protected_nsaid_en_dev : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_TZPC_DECPROT3STAT_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT3STAT_mid_tcu_START (0)
#define SOC_NPU_TZPC_DECPROT3STAT_mid_tcu_END (5)
#define SOC_NPU_TZPC_DECPROT3STAT_mid_sysdma_START (8)
#define SOC_NPU_TZPC_DECPROT3STAT_mid_sysdma_END (13)
#define SOC_NPU_TZPC_DECPROT3STAT_mid_aicore_START (16)
#define SOC_NPU_TZPC_DECPROT3STAT_mid_aicore_END (21)
#define SOC_NPU_TZPC_DECPROT3STAT_gict_allow_ns_START (24)
#define SOC_NPU_TZPC_DECPROT3STAT_gict_allow_ns_END (24)
#define SOC_NPU_TZPC_DECPROT3STAT_gicd_allow_ns_START (25)
#define SOC_NPU_TZPC_DECPROT3STAT_gicd_allow_ns_END (25)
#define SOC_NPU_TZPC_DECPROT3STAT_protected_nsaid_en_START (26)
#define SOC_NPU_TZPC_DECPROT3STAT_protected_nsaid_en_END (26)
#define SOC_NPU_TZPC_DECPROT3STAT_npu_mst_secure_START (27)
#define SOC_NPU_TZPC_DECPROT3STAT_npu_mst_secure_END (27)
#define SOC_NPU_TZPC_DECPROT3STAT_protected_nsaid_en_mem_START (28)
#define SOC_NPU_TZPC_DECPROT3STAT_protected_nsaid_en_mem_END (28)
#define SOC_NPU_TZPC_DECPROT3STAT_protected_nsaid_en_dev_START (29)
#define SOC_NPU_TZPC_DECPROT3STAT_protected_nsaid_en_dev_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_tcu : 6;
        unsigned int reserved_0 : 2;
        unsigned int mid_sysdma : 6;
        unsigned int reserved_1 : 2;
        unsigned int mid_aicore : 6;
        unsigned int reserved_2 : 2;
        unsigned int gict_allow_ns : 1;
        unsigned int gicd_allow_ns : 1;
        unsigned int protected_nsaid_en : 1;
        unsigned int npu_mst_secure : 1;
        unsigned int protected_nsaid_en_mem : 1;
        unsigned int protected_nsaid_en_dev : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_TZPC_DECPROT3SET_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT3SET_mid_tcu_START (0)
#define SOC_NPU_TZPC_DECPROT3SET_mid_tcu_END (5)
#define SOC_NPU_TZPC_DECPROT3SET_mid_sysdma_START (8)
#define SOC_NPU_TZPC_DECPROT3SET_mid_sysdma_END (13)
#define SOC_NPU_TZPC_DECPROT3SET_mid_aicore_START (16)
#define SOC_NPU_TZPC_DECPROT3SET_mid_aicore_END (21)
#define SOC_NPU_TZPC_DECPROT3SET_gict_allow_ns_START (24)
#define SOC_NPU_TZPC_DECPROT3SET_gict_allow_ns_END (24)
#define SOC_NPU_TZPC_DECPROT3SET_gicd_allow_ns_START (25)
#define SOC_NPU_TZPC_DECPROT3SET_gicd_allow_ns_END (25)
#define SOC_NPU_TZPC_DECPROT3SET_protected_nsaid_en_START (26)
#define SOC_NPU_TZPC_DECPROT3SET_protected_nsaid_en_END (26)
#define SOC_NPU_TZPC_DECPROT3SET_npu_mst_secure_START (27)
#define SOC_NPU_TZPC_DECPROT3SET_npu_mst_secure_END (27)
#define SOC_NPU_TZPC_DECPROT3SET_protected_nsaid_en_mem_START (28)
#define SOC_NPU_TZPC_DECPROT3SET_protected_nsaid_en_mem_END (28)
#define SOC_NPU_TZPC_DECPROT3SET_protected_nsaid_en_dev_START (29)
#define SOC_NPU_TZPC_DECPROT3SET_protected_nsaid_en_dev_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_tcu : 6;
        unsigned int reserved_0 : 2;
        unsigned int mid_sysdma : 6;
        unsigned int reserved_1 : 2;
        unsigned int mid_aicore : 6;
        unsigned int reserved_2 : 2;
        unsigned int gict_allow_ns : 1;
        unsigned int gicd_allow_ns : 1;
        unsigned int protected_nsaid_en : 1;
        unsigned int npu_mst_secure : 1;
        unsigned int protected_nsaid_en_mem : 1;
        unsigned int protected_nsaid_en_dev : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_TZPC_DECPROT3CLR_UNION;
#endif
#define SOC_NPU_TZPC_DECPROT3CLR_mid_tcu_START (0)
#define SOC_NPU_TZPC_DECPROT3CLR_mid_tcu_END (5)
#define SOC_NPU_TZPC_DECPROT3CLR_mid_sysdma_START (8)
#define SOC_NPU_TZPC_DECPROT3CLR_mid_sysdma_END (13)
#define SOC_NPU_TZPC_DECPROT3CLR_mid_aicore_START (16)
#define SOC_NPU_TZPC_DECPROT3CLR_mid_aicore_END (21)
#define SOC_NPU_TZPC_DECPROT3CLR_gict_allow_ns_START (24)
#define SOC_NPU_TZPC_DECPROT3CLR_gict_allow_ns_END (24)
#define SOC_NPU_TZPC_DECPROT3CLR_gicd_allow_ns_START (25)
#define SOC_NPU_TZPC_DECPROT3CLR_gicd_allow_ns_END (25)
#define SOC_NPU_TZPC_DECPROT3CLR_protected_nsaid_en_START (26)
#define SOC_NPU_TZPC_DECPROT3CLR_protected_nsaid_en_END (26)
#define SOC_NPU_TZPC_DECPROT3CLR_npu_mst_secure_START (27)
#define SOC_NPU_TZPC_DECPROT3CLR_npu_mst_secure_END (27)
#define SOC_NPU_TZPC_DECPROT3CLR_protected_nsaid_en_mem_START (28)
#define SOC_NPU_TZPC_DECPROT3CLR_protected_nsaid_en_mem_END (28)
#define SOC_NPU_TZPC_DECPROT3CLR_protected_nsaid_en_dev_START (29)
#define SOC_NPU_TZPC_DECPROT3CLR_protected_nsaid_en_dev_END (29)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
