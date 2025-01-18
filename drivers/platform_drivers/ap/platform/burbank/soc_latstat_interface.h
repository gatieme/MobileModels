#ifndef __SOC_LATSTAT_INTERFACE_H__
#define __SOC_LATSTAT_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_LATSTAT_CLK_GATE_ADDR(base) ((base) + (0x00UL))
#define SOC_LATSTAT_CMD_START_ADDR(base) ((base) + (0x04UL))
#define SOC_LATSTAT_SAMPLE_CNT_REG_ADDR(base) ((base) + (0x08UL))
#define SOC_LATSTAT_SAMPLE_NUM_REG_ADDR(base) ((base) + (0x0CUL))
#define SOC_LATSTAT_SAMPLE_STOP_ADDR(base) ((base) + (0x10UL))
#define SOC_LATSTAT_REAL_PORT_NUM_ADDR(base) ((base) + (0x14UL))
#define SOC_LATSTAT_AXI_ADDR_MODE_ADDR(base) ((base) + (0x18UL))
#define SOC_LATSTAT_SEQ_ADDR_LEN_ADDR(base) ((base) + (0x20UL))
#define SOC_LATSTAT_STAT_RST_CNT_ADDR(base) ((base) + (0x2CUL))
#define SOC_LATSTAT_INT_EN_ADDR(base) ((base) + (0x30UL))
#define SOC_LATSTAT_INT_CLR_ADDR(base) ((base) + (0x34UL))
#define SOC_LATSTAT_RAW_INT_STAT_ADDR(base) ((base) + (0x38UL))
#define SOC_LATSTAT_MASK_INT_STAT_ADDR(base) ((base) + (0x3CUL))
#define SOC_LATSTAT_ALL_SAMPLE_NUM_ADDR(base) ((base) + (0x40UL))
#define SOC_LATSTAT_OVERTIME_CFG_CNT_ADDR(base) ((base) + (0x48UL))
#define SOC_LATSTAT_DEBUG_FIFO_FULL_ADDR(base) ((base) + (0x4CUL))
#define SOC_LATSTAT_DEBUG_MONITOR_ADDR(base) ((base) + (0x50UL))
#define SOC_LATSTAT_MONITOR_RESET_ADDR(base) ((base) + (0x54UL))
#define SOC_LATSTAT_SEQ_ADDR_LOW_ADDR(base) ((base) + (0x58UL))
#define SOC_LATSTAT_SEQ_ADDR_HIGH_ADDR(base) ((base) + (0x5CUL))
#define SOC_LATSTAT_DESCRIPTOR_ADDR_LOW_ADDR(base) ((base) + (0x60UL))
#define SOC_LATSTAT_DESCRIPTOR_ADDR_HIGH_ADDR(base) ((base) + (0x64UL))
#define SOC_LATSTAT_LAST_DESC_ADDR_LOW_ADDR(base) ((base) + (0x68UL))
#define SOC_LATSTAT_LAST_DESC_ADDR_HIGH_ADDR(base) ((base) + (0x6CUL))
#define SOC_LATSTAT_LAST_SAMPLE_AXI_ADDR_LOW_ADDR(base) ((base) + (0x70UL))
#define SOC_LATSTAT_LAST_SAMPLE_AXI_ADDR_HIGH_ADDR(base) ((base) + (0x74UL))
#define SOC_LATSTAT_PDRST_TMO_CNT_CFG_ADDR(base) ((base) + (0x78UL))
#define SOC_LATSTAT_RS_ENABLE1_ADDR(base) ((base) + (0x7CUL))
#define SOC_LATSTAT_RS_ENABLE2_ADDR(base) ((base) + (0x80UL))
#define SOC_LATSTAT_RS_ENABLE3_ADDR(base) ((base) + (0x84UL))
#define SOC_LATSTAT_RS_ENABLE4_ADDR(base) ((base) + (0x88UL))
#define SOC_LATSTAT_RS_ENABLE5_ADDR(base) ((base) + (0x8CUL))
#define SOC_LATSTAT_RS_ENABLE6_ADDR(base) ((base) + (0x90UL))
#define SOC_LATSTAT_TRANS_SYNC_TIME_ADDR(base) ((base) + (0x94UL))
#define SOC_LATSTAT_BUS_STAT_ADDR(base) ((base) + (0x98UL))
#define SOC_LATSTAT_PORT_NUM_CNT_ADDR(base) ((base) + (0x9CUL))
#else
#define SOC_LATSTAT_CLK_GATE_ADDR(base) ((base) + (0x00))
#define SOC_LATSTAT_CMD_START_ADDR(base) ((base) + (0x04))
#define SOC_LATSTAT_SAMPLE_CNT_REG_ADDR(base) ((base) + (0x08))
#define SOC_LATSTAT_SAMPLE_NUM_REG_ADDR(base) ((base) + (0x0C))
#define SOC_LATSTAT_SAMPLE_STOP_ADDR(base) ((base) + (0x10))
#define SOC_LATSTAT_REAL_PORT_NUM_ADDR(base) ((base) + (0x14))
#define SOC_LATSTAT_AXI_ADDR_MODE_ADDR(base) ((base) + (0x18))
#define SOC_LATSTAT_SEQ_ADDR_LEN_ADDR(base) ((base) + (0x20))
#define SOC_LATSTAT_STAT_RST_CNT_ADDR(base) ((base) + (0x2C))
#define SOC_LATSTAT_INT_EN_ADDR(base) ((base) + (0x30))
#define SOC_LATSTAT_INT_CLR_ADDR(base) ((base) + (0x34))
#define SOC_LATSTAT_RAW_INT_STAT_ADDR(base) ((base) + (0x38))
#define SOC_LATSTAT_MASK_INT_STAT_ADDR(base) ((base) + (0x3C))
#define SOC_LATSTAT_ALL_SAMPLE_NUM_ADDR(base) ((base) + (0x40))
#define SOC_LATSTAT_OVERTIME_CFG_CNT_ADDR(base) ((base) + (0x48))
#define SOC_LATSTAT_DEBUG_FIFO_FULL_ADDR(base) ((base) + (0x4C))
#define SOC_LATSTAT_DEBUG_MONITOR_ADDR(base) ((base) + (0x50))
#define SOC_LATSTAT_MONITOR_RESET_ADDR(base) ((base) + (0x54))
#define SOC_LATSTAT_SEQ_ADDR_LOW_ADDR(base) ((base) + (0x58))
#define SOC_LATSTAT_SEQ_ADDR_HIGH_ADDR(base) ((base) + (0x5C))
#define SOC_LATSTAT_DESCRIPTOR_ADDR_LOW_ADDR(base) ((base) + (0x60))
#define SOC_LATSTAT_DESCRIPTOR_ADDR_HIGH_ADDR(base) ((base) + (0x64))
#define SOC_LATSTAT_LAST_DESC_ADDR_LOW_ADDR(base) ((base) + (0x68))
#define SOC_LATSTAT_LAST_DESC_ADDR_HIGH_ADDR(base) ((base) + (0x6C))
#define SOC_LATSTAT_LAST_SAMPLE_AXI_ADDR_LOW_ADDR(base) ((base) + (0x70))
#define SOC_LATSTAT_LAST_SAMPLE_AXI_ADDR_HIGH_ADDR(base) ((base) + (0x74))
#define SOC_LATSTAT_PDRST_TMO_CNT_CFG_ADDR(base) ((base) + (0x78))
#define SOC_LATSTAT_RS_ENABLE1_ADDR(base) ((base) + (0x7C))
#define SOC_LATSTAT_RS_ENABLE2_ADDR(base) ((base) + (0x80))
#define SOC_LATSTAT_RS_ENABLE3_ADDR(base) ((base) + (0x84))
#define SOC_LATSTAT_RS_ENABLE4_ADDR(base) ((base) + (0x88))
#define SOC_LATSTAT_RS_ENABLE5_ADDR(base) ((base) + (0x8C))
#define SOC_LATSTAT_RS_ENABLE6_ADDR(base) ((base) + (0x90))
#define SOC_LATSTAT_TRANS_SYNC_TIME_ADDR(base) ((base) + (0x94))
#define SOC_LATSTAT_BUS_STAT_ADDR(base) ((base) + (0x98))
#define SOC_LATSTAT_PORT_NUM_CNT_ADDR(base) ((base) + (0x9C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_clk_gate : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LATSTAT_CLK_GATE_UNION;
#endif
#define SOC_LATSTAT_CLK_GATE_apb_clk_gate_START (0)
#define SOC_LATSTAT_CLK_GATE_apb_clk_gate_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LATSTAT_CMD_START_UNION;
#endif
#define SOC_LATSTAT_CMD_START_cmd_start_START (0)
#define SOC_LATSTAT_CMD_START_cmd_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_SAMPLE_CNT_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_SAMPLE_NUM_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LATSTAT_SAMPLE_STOP_UNION;
#endif
#define SOC_LATSTAT_SAMPLE_STOP_sample_stop_START (0)
#define SOC_LATSTAT_SAMPLE_STOP_sample_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_REAL_PORT_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_addr_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LATSTAT_AXI_ADDR_MODE_UNION;
#endif
#define SOC_LATSTAT_AXI_ADDR_MODE_axi_addr_mode_START (0)
#define SOC_LATSTAT_AXI_ADDR_MODE_axi_addr_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_SEQ_ADDR_LEN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_rst_cnt : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_LATSTAT_STAT_RST_CNT_UNION;
#endif
#define SOC_LATSTAT_STAT_RST_CNT_stat_rst_cnt_START (0)
#define SOC_LATSTAT_STAT_RST_CNT_stat_rst_cnt_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_int_en : 1;
        unsigned int overtime_int_en : 1;
        unsigned int desc_int_en : 1;
        unsigned int desc_error_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_LATSTAT_INT_EN_UNION;
#endif
#define SOC_LATSTAT_INT_EN_sample_int_en_START (0)
#define SOC_LATSTAT_INT_EN_sample_int_en_END (0)
#define SOC_LATSTAT_INT_EN_overtime_int_en_START (1)
#define SOC_LATSTAT_INT_EN_overtime_int_en_END (1)
#define SOC_LATSTAT_INT_EN_desc_int_en_START (2)
#define SOC_LATSTAT_INT_EN_desc_int_en_END (2)
#define SOC_LATSTAT_INT_EN_desc_error_en_START (3)
#define SOC_LATSTAT_INT_EN_desc_error_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_int_clr : 1;
        unsigned int overtime_int_clr : 1;
        unsigned int desc_int_clr : 1;
        unsigned int desc_error_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_LATSTAT_INT_CLR_UNION;
#endif
#define SOC_LATSTAT_INT_CLR_sample_int_clr_START (0)
#define SOC_LATSTAT_INT_CLR_sample_int_clr_END (0)
#define SOC_LATSTAT_INT_CLR_overtime_int_clr_START (1)
#define SOC_LATSTAT_INT_CLR_overtime_int_clr_END (1)
#define SOC_LATSTAT_INT_CLR_desc_int_clr_START (2)
#define SOC_LATSTAT_INT_CLR_desc_int_clr_END (2)
#define SOC_LATSTAT_INT_CLR_desc_error_clr_START (3)
#define SOC_LATSTAT_INT_CLR_desc_error_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_raw_int_stat : 1;
        unsigned int overtime_int_stat : 1;
        unsigned int desc_raw_int_stat : 1;
        unsigned int desc_raw_error_stat : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_LATSTAT_RAW_INT_STAT_UNION;
#endif
#define SOC_LATSTAT_RAW_INT_STAT_sample_raw_int_stat_START (0)
#define SOC_LATSTAT_RAW_INT_STAT_sample_raw_int_stat_END (0)
#define SOC_LATSTAT_RAW_INT_STAT_overtime_int_stat_START (1)
#define SOC_LATSTAT_RAW_INT_STAT_overtime_int_stat_END (1)
#define SOC_LATSTAT_RAW_INT_STAT_desc_raw_int_stat_START (2)
#define SOC_LATSTAT_RAW_INT_STAT_desc_raw_int_stat_END (2)
#define SOC_LATSTAT_RAW_INT_STAT_desc_raw_error_stat_START (3)
#define SOC_LATSTAT_RAW_INT_STAT_desc_raw_error_stat_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_mask_int_stat : 1;
        unsigned int overtime_int_stat : 1;
        unsigned int desc_mask_int_stat : 1;
        unsigned int desc_mask_error_stat : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_LATSTAT_MASK_INT_STAT_UNION;
#endif
#define SOC_LATSTAT_MASK_INT_STAT_sample_mask_int_stat_START (0)
#define SOC_LATSTAT_MASK_INT_STAT_sample_mask_int_stat_END (0)
#define SOC_LATSTAT_MASK_INT_STAT_overtime_int_stat_START (1)
#define SOC_LATSTAT_MASK_INT_STAT_overtime_int_stat_END (1)
#define SOC_LATSTAT_MASK_INT_STAT_desc_mask_int_stat_START (2)
#define SOC_LATSTAT_MASK_INT_STAT_desc_mask_int_stat_END (2)
#define SOC_LATSTAT_MASK_INT_STAT_desc_mask_error_stat_START (3)
#define SOC_LATSTAT_MASK_INT_STAT_desc_mask_error_stat_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_ALL_SAMPLE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_OVERTIME_CFG_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_fifo_full : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LATSTAT_DEBUG_FIFO_FULL_UNION;
#endif
#define SOC_LATSTAT_DEBUG_FIFO_FULL_debug_fifo_full_START (0)
#define SOC_LATSTAT_DEBUG_FIFO_FULL_debug_fifo_full_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_DEBUG_MONITOR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_reset : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LATSTAT_MONITOR_RESET_UNION;
#endif
#define SOC_LATSTAT_MONITOR_RESET_monitor_reset_START (0)
#define SOC_LATSTAT_MONITOR_RESET_monitor_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_SEQ_ADDR_LOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_SEQ_ADDR_HIGH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_DESCRIPTOR_ADDR_LOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_DESCRIPTOR_ADDR_HIGH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_LAST_DESC_ADDR_LOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_LAST_DESC_ADDR_HIGH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_LAST_SAMPLE_AXI_ADDR_LOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_LAST_SAMPLE_AXI_ADDR_HIGH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pdrst_tmo_cnt_cfg : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_LATSTAT_PDRST_TMO_CNT_CFG_UNION;
#endif
#define SOC_LATSTAT_PDRST_TMO_CNT_CFG_pdrst_tmo_cnt_cfg_START (0)
#define SOC_LATSTAT_PDRST_TMO_CNT_CFG_pdrst_tmo_cnt_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_RS_ENABLE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_RS_ENABLE2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_RS_ENABLE3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_RS_ENABLE4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_RS_ENABLE5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_RS_ENABLE6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_TRANS_SYNC_TIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_BUS_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_LATSTAT_PORT_NUM_CNT_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
