#ifndef __SOC_EFUSEC1_INTERFACE_H__
#define __SOC_EFUSEC1_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_EFUSEC1_EFUSEC_CFG_ADDR(base) ((base) + (0x000UL))
#define SOC_EFUSEC1_EFUSEC_STATUS_ADDR(base) ((base) + (0x004UL))
#define SOC_EFUSEC1_EFUSE_GROUP_ADDR(base) ((base) + (0x008UL))
#define SOC_EFUSEC1_PG_VALUE_ADDR(base) ((base) + (0x00CUL))
#define SOC_EFUSEC1_EFUSEC_COUNT_ADDR(base) ((base) + (0x010UL))
#define SOC_EFUSEC1_PGM_COUNT_ADDR(base) ((base) + (0x014UL))
#define SOC_EFUSEC1_EFUSEC_DATA_ADDR(base) ((base) + (0x018UL))
#define SOC_EFUSEC1_HW_CFG_ADDR(base) ((base) + (0x01CUL))
#define SOC_EFUSEC1_UDS_LOCK_ADDR(base) ((base) + (0x04CUL))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_ADDR(base) ((base) + (0x054UL))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_LOW_ADDR(base) ((base) + (0x058UL))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_HIGH_ADDR(base) ((base) + (0x05CUL))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_BYAPSS_ADDR(base) ((base) + (0x060UL))
#define SOC_EFUSEC1_APB_AIB_SEL_ADDR(base) ((base) + (0x064UL))
#define SOC_EFUSEC1_efuse_18v_en_debug_ADDR(base) ((base) + (0x068UL))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_LOW_DEBUG_ADDR(base) ((base) + (0x06CUL))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_HIGH_DEBUG_ADDR(base) ((base) + (0x070UL))
#define SOC_EFUSEC1_REMAP_EN_ADDR(base) ((base) + (0x074UL))
#define SOC_EFUSEC1_PAD_SEL_N_ADDR(base) ((base) + (0x078UL))
#define SOC_EFUSEC1_EFUSE_HWCFG_RDATA_ADDR(base) ((base) + (0x07CUL))
#define SOC_EFUSEC1_EFUSE_OR_LCS_LOW_ADDR(base) ((base) + (0x080UL))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED1_ADDR(base) ((base) + (0x084UL))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED2_ADDR(base) ((base) + (0x088UL))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED3_ADDR(base) ((base) + (0x08CUL))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED4_ADDR(base) ((base) + (0x090UL))
#define SOC_EFUSEC1_EFUSE_WR_NXT_WR_ADDR(base) ((base) + (0x094UL))
#else
#define SOC_EFUSEC1_EFUSEC_CFG_ADDR(base) ((base) + (0x000))
#define SOC_EFUSEC1_EFUSEC_STATUS_ADDR(base) ((base) + (0x004))
#define SOC_EFUSEC1_EFUSE_GROUP_ADDR(base) ((base) + (0x008))
#define SOC_EFUSEC1_PG_VALUE_ADDR(base) ((base) + (0x00C))
#define SOC_EFUSEC1_EFUSEC_COUNT_ADDR(base) ((base) + (0x010))
#define SOC_EFUSEC1_PGM_COUNT_ADDR(base) ((base) + (0x014))
#define SOC_EFUSEC1_EFUSEC_DATA_ADDR(base) ((base) + (0x018))
#define SOC_EFUSEC1_HW_CFG_ADDR(base) ((base) + (0x01C))
#define SOC_EFUSEC1_UDS_LOCK_ADDR(base) ((base) + (0x04C))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_ADDR(base) ((base) + (0x054))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_LOW_ADDR(base) ((base) + (0x058))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_HIGH_ADDR(base) ((base) + (0x05C))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_BYAPSS_ADDR(base) ((base) + (0x060))
#define SOC_EFUSEC1_APB_AIB_SEL_ADDR(base) ((base) + (0x064))
#define SOC_EFUSEC1_efuse_18v_en_debug_ADDR(base) ((base) + (0x068))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_LOW_DEBUG_ADDR(base) ((base) + (0x06C))
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_HIGH_DEBUG_ADDR(base) ((base) + (0x070))
#define SOC_EFUSEC1_REMAP_EN_ADDR(base) ((base) + (0x074))
#define SOC_EFUSEC1_PAD_SEL_N_ADDR(base) ((base) + (0x078))
#define SOC_EFUSEC1_EFUSE_HWCFG_RDATA_ADDR(base) ((base) + (0x07C))
#define SOC_EFUSEC1_EFUSE_OR_LCS_LOW_ADDR(base) ((base) + (0x080))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED1_ADDR(base) ((base) + (0x084))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED2_ADDR(base) ((base) + (0x088))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED3_ADDR(base) ((base) + (0x08C))
#define SOC_EFUSEC1_EFUSE_OR_RESERVED4_ADDR(base) ((base) + (0x090))
#define SOC_EFUSEC1_EFUSE_WR_NXT_WR_ADDR(base) ((base) + (0x094))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pgen : 1;
        unsigned int pre_pg : 1;
        unsigned int rden : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int pd_en : 1;
        unsigned int mr_en : 1;
        unsigned int reserved_2: 25;
    } reg;
} SOC_EFUSEC1_EFUSEC_CFG_UNION;
#endif
#define SOC_EFUSEC1_EFUSEC_CFG_pgen_START (0)
#define SOC_EFUSEC1_EFUSEC_CFG_pgen_END (0)
#define SOC_EFUSEC1_EFUSEC_CFG_pre_pg_START (1)
#define SOC_EFUSEC1_EFUSEC_CFG_pre_pg_END (1)
#define SOC_EFUSEC1_EFUSEC_CFG_rden_START (2)
#define SOC_EFUSEC1_EFUSEC_CFG_rden_END (2)
#define SOC_EFUSEC1_EFUSEC_CFG_pd_en_START (5)
#define SOC_EFUSEC1_EFUSEC_CFG_pd_en_END (5)
#define SOC_EFUSEC1_EFUSEC_CFG_mr_en_START (6)
#define SOC_EFUSEC1_EFUSEC_CFG_mr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pg_status : 1;
        unsigned int rd_status : 1;
        unsigned int pgenb_status : 1;
        unsigned int rd_error : 1;
        unsigned int pd_status : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_EFUSEC1_EFUSEC_STATUS_UNION;
#endif
#define SOC_EFUSEC1_EFUSEC_STATUS_pg_status_START (0)
#define SOC_EFUSEC1_EFUSEC_STATUS_pg_status_END (0)
#define SOC_EFUSEC1_EFUSEC_STATUS_rd_status_START (1)
#define SOC_EFUSEC1_EFUSEC_STATUS_rd_status_END (1)
#define SOC_EFUSEC1_EFUSEC_STATUS_pgenb_status_START (2)
#define SOC_EFUSEC1_EFUSEC_STATUS_pgenb_status_END (2)
#define SOC_EFUSEC1_EFUSEC_STATUS_rd_error_START (3)
#define SOC_EFUSEC1_EFUSEC_STATUS_rd_error_END (3)
#define SOC_EFUSEC1_EFUSEC_STATUS_pd_status_START (4)
#define SOC_EFUSEC1_EFUSEC_STATUS_pd_status_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_group : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_EFUSEC1_EFUSE_GROUP_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_GROUP_efuse_group_START (0)
#define SOC_EFUSEC1_EFUSE_GROUP_efuse_group_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pg_value : 32;
    } reg;
} SOC_EFUSEC1_PG_VALUE_UNION;
#endif
#define SOC_EFUSEC1_PG_VALUE_pg_value_START (0)
#define SOC_EFUSEC1_PG_VALUE_pg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec_count : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_EFUSEC1_EFUSEC_COUNT_UNION;
#endif
#define SOC_EFUSEC1_EFUSEC_COUNT_efusec_count_START (0)
#define SOC_EFUSEC1_EFUSEC_COUNT_efusec_count_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pgm_count : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_EFUSEC1_PGM_COUNT_UNION;
#endif
#define SOC_EFUSEC1_PGM_COUNT_pgm_count_START (0)
#define SOC_EFUSEC1_PGM_COUNT_pgm_count_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec_data : 32;
    } reg;
} SOC_EFUSEC1_EFUSEC_DATA_UNION;
#endif
#define SOC_EFUSEC1_EFUSEC_DATA_efusec_data_START (0)
#define SOC_EFUSEC1_EFUSEC_DATA_efusec_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_cfg : 32;
    } reg;
} SOC_EFUSEC1_HW_CFG_UNION;
#endif
#define SOC_EFUSEC1_HW_CFG_hw_cfg_START (0)
#define SOC_EFUSEC1_HW_CFG_hw_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uds_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_EFUSEC1_UDS_LOCK_UNION;
#endif
#define SOC_EFUSEC1_UDS_LOCK_uds_lock_START (0)
#define SOC_EFUSEC1_UDS_LOCK_uds_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_1P8v_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_EFUSEC1_EFUSE_1P8V_EN_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_1P8V_EN_efuse_1P8v_en_START (0)
#define SOC_EFUSEC1_EFUSE_1P8V_EN_efuse_1P8v_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_1P8v_en_timeout_low : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_LOW_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_LOW_efuse_1P8v_en_timeout_low_START (0)
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_LOW_efuse_1P8v_en_timeout_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_1P8v_en_timeout_high : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_HIGH_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_HIGH_efuse_1P8v_en_timeout_high_START (0)
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_HIGH_efuse_1P8v_en_timeout_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_1P8v_en_timeout_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_BYAPSS_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_BYAPSS_efuse_1P8v_en_timeout_bypass_START (0)
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMEOUT_BYAPSS_efuse_1P8v_en_timeout_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_aib_sel : 1;
        unsigned int state_idle : 1;
        unsigned int hw_rd_finish : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_EFUSEC1_APB_AIB_SEL_UNION;
#endif
#define SOC_EFUSEC1_APB_AIB_SEL_apb_aib_sel_START (0)
#define SOC_EFUSEC1_APB_AIB_SEL_apb_aib_sel_END (0)
#define SOC_EFUSEC1_APB_AIB_SEL_state_idle_START (1)
#define SOC_EFUSEC1_APB_AIB_SEL_state_idle_END (1)
#define SOC_EFUSEC1_APB_AIB_SEL_hw_rd_finish_START (2)
#define SOC_EFUSEC1_APB_AIB_SEL_hw_rd_finish_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_18v_en_timeout_event : 1;
        unsigned int efuse_18v_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_EFUSEC1_efuse_18v_en_debug_UNION;
#endif
#define SOC_EFUSEC1_efuse_18v_en_debug_efuse_18v_en_timeout_event_START (0)
#define SOC_EFUSEC1_efuse_18v_en_debug_efuse_18v_en_timeout_event_END (0)
#define SOC_EFUSEC1_efuse_18v_en_debug_efuse_18v_en_START (1)
#define SOC_EFUSEC1_efuse_18v_en_debug_efuse_18v_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_1P8v_en_timer_low : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_LOW_DEBUG_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_LOW_DEBUG_efuse_1P8v_en_timer_low_START (0)
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_LOW_DEBUG_efuse_1P8v_en_timer_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_1P8v_en_timer_high : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_HIGH_DEBUG_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_HIGH_DEBUG_efuse_1P8v_en_timer_high_START (0)
#define SOC_EFUSEC1_EFUSE_1P8V_EN_TIMER_HIGH_DEBUG_efuse_1P8v_en_timer_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remap_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_EFUSEC1_REMAP_EN_UNION;
#endif
#define SOC_EFUSEC1_REMAP_EN_remap_en_START (0)
#define SOC_EFUSEC1_REMAP_EN_remap_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pad_sel_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_EFUSEC1_PAD_SEL_N_UNION;
#endif
#define SOC_EFUSEC1_PAD_SEL_N_pad_sel_n_START (0)
#define SOC_EFUSEC1_PAD_SEL_N_pad_sel_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_hwcfg_rdata : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_HWCFG_RDATA_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_HWCFG_RDATA_efuse_hwcfg_rdata_START (0)
#define SOC_EFUSEC1_EFUSE_HWCFG_RDATA_efuse_hwcfg_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_or_lcs_low : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_OR_LCS_LOW_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_OR_LCS_LOW_efuse_or_lcs_low_START (0)
#define SOC_EFUSEC1_EFUSE_OR_LCS_LOW_efuse_or_lcs_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_or_reserved1 : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_OR_RESERVED1_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_OR_RESERVED1_efuse_or_reserved1_START (0)
#define SOC_EFUSEC1_EFUSE_OR_RESERVED1_efuse_or_reserved1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_or_reserved2 : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_OR_RESERVED2_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_OR_RESERVED2_efuse_or_reserved2_START (0)
#define SOC_EFUSEC1_EFUSE_OR_RESERVED2_efuse_or_reserved2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_or_reserved3 : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_OR_RESERVED3_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_OR_RESERVED3_efuse_or_reserved3_START (0)
#define SOC_EFUSEC1_EFUSE_OR_RESERVED3_efuse_or_reserved3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_or_reserved4 : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_OR_RESERVED4_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_OR_RESERVED4_efuse_or_reserved4_START (0)
#define SOC_EFUSEC1_EFUSE_OR_RESERVED4_efuse_or_reserved4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EFUSE_WR_NXT_WR : 32;
    } reg;
} SOC_EFUSEC1_EFUSE_WR_NXT_WR_UNION;
#endif
#define SOC_EFUSEC1_EFUSE_WR_NXT_WR_EFUSE_WR_NXT_WR_START (0)
#define SOC_EFUSEC1_EFUSE_WR_NXT_WR_EFUSE_WR_NXT_WR_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
