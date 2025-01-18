#ifndef __SOC_ITS_INTERFACE_H__
#define __SOC_ITS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ITS_CLK_RST_CTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_ITS_DIV_CTRL0_ADDR(base) ((base) + (0x0004UL))
#define SOC_ITS_MODE_CTRL_ADDR(base) ((base) + (0x0008UL))
#define SOC_ITS_TIMER_PERIOD_ADDR(base) ((base) + (0x000CUL))
#define SOC_ITS_INTR_MSK_ADDR(base) ((base) + (0x0010UL))
#define SOC_ITS_INTR_CTRL_ADDR(base) ((base) + (0x0014UL))
#define SOC_ITS_INTR_ADDR(base) ((base) + (0x0018UL))
#define SOC_ITS_DEBUG_STATUS_ADDR(base) ((base) + (0x001CUL))
#define SOC_ITS_DPM_DATA_T0_ADDR(base) ((base) + (0x0020UL))
#define SOC_ITS_DPM_DATA_T1_ADDR(base) ((base) + (0x0024UL))
#define SOC_ITS_target_window_num_ADDR(base) ((base) + (0x002CUL))
#define SOC_ITS_dpm_out_result0_ADDR(base) ((base) + (0x0034UL))
#define SOC_ITS_dpm_out_result1_ADDR(base) ((base) + (0x0038UL))
#define SOC_ITS_dpm_out_result_lsb_ADDR(base) ((base) + (0x003CUL))
#define SOC_ITS_COEFFICIENT_ADDR(base,n) ((base) + (0x0040+0x4*(n)))
#define SOC_ITS_cnt_data_sel_ADDR(base) ((base) + (0x0100UL))
#define SOC_ITS_cnt_data_result_ADDR(base) ((base) + (0x0104UL))
#define SOC_ITS_hold_previous_cnt_mode_ADDR(base) ((base) + (0x0108UL))
#define SOC_ITS_cnt_inter_val_ADDR(base) ((base) + (0x010cUL))
#define SOC_ITS_dpm_sum_tmp_data_ADDR(base) ((base) + (0x0110UL))
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_ADDR(base) ((base) + (0x0114UL))
#else
#define SOC_ITS_CLK_RST_CTRL_ADDR(base) ((base) + (0x000))
#define SOC_ITS_DIV_CTRL0_ADDR(base) ((base) + (0x0004))
#define SOC_ITS_MODE_CTRL_ADDR(base) ((base) + (0x0008))
#define SOC_ITS_TIMER_PERIOD_ADDR(base) ((base) + (0x000C))
#define SOC_ITS_INTR_MSK_ADDR(base) ((base) + (0x0010))
#define SOC_ITS_INTR_CTRL_ADDR(base) ((base) + (0x0014))
#define SOC_ITS_INTR_ADDR(base) ((base) + (0x0018))
#define SOC_ITS_DEBUG_STATUS_ADDR(base) ((base) + (0x001C))
#define SOC_ITS_DPM_DATA_T0_ADDR(base) ((base) + (0x0020))
#define SOC_ITS_DPM_DATA_T1_ADDR(base) ((base) + (0x0024))
#define SOC_ITS_target_window_num_ADDR(base) ((base) + (0x002C))
#define SOC_ITS_dpm_out_result0_ADDR(base) ((base) + (0x0034))
#define SOC_ITS_dpm_out_result1_ADDR(base) ((base) + (0x0038))
#define SOC_ITS_dpm_out_result_lsb_ADDR(base) ((base) + (0x003C))
#define SOC_ITS_COEFFICIENT_ADDR(base,n) ((base) + (0x0040+0x4*(n)))
#define SOC_ITS_cnt_data_sel_ADDR(base) ((base) + (0x0100))
#define SOC_ITS_cnt_data_result_ADDR(base) ((base) + (0x0104))
#define SOC_ITS_hold_previous_cnt_mode_ADDR(base) ((base) + (0x0108))
#define SOC_ITS_cnt_inter_val_ADDR(base) ((base) + (0x010c))
#define SOC_ITS_dpm_sum_tmp_data_ADDR(base) ((base) + (0x0110))
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_ADDR(base) ((base) + (0x0114))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timer_clk_en : 1;
        unsigned int dpm_clk_en : 1;
        unsigned int its_crg_clk_en : 1;
        unsigned int timer_rst_en_n : 1;
        unsigned int dpm_rst_en_n : 1;
        unsigned int its_crg_rst_n : 1;
        unsigned int reserved_0 : 2;
        unsigned int sens_clk_en : 1;
        unsigned int its_div_clk_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int sens_rst_n : 1;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_ITS_CLK_RST_CTRL_UNION;
#endif
#define SOC_ITS_CLK_RST_CTRL_timer_clk_en_START (0)
#define SOC_ITS_CLK_RST_CTRL_timer_clk_en_END (0)
#define SOC_ITS_CLK_RST_CTRL_dpm_clk_en_START (1)
#define SOC_ITS_CLK_RST_CTRL_dpm_clk_en_END (1)
#define SOC_ITS_CLK_RST_CTRL_its_crg_clk_en_START (2)
#define SOC_ITS_CLK_RST_CTRL_its_crg_clk_en_END (2)
#define SOC_ITS_CLK_RST_CTRL_timer_rst_en_n_START (3)
#define SOC_ITS_CLK_RST_CTRL_timer_rst_en_n_END (3)
#define SOC_ITS_CLK_RST_CTRL_dpm_rst_en_n_START (4)
#define SOC_ITS_CLK_RST_CTRL_dpm_rst_en_n_END (4)
#define SOC_ITS_CLK_RST_CTRL_its_crg_rst_n_START (5)
#define SOC_ITS_CLK_RST_CTRL_its_crg_rst_n_END (5)
#define SOC_ITS_CLK_RST_CTRL_sens_clk_en_START (8)
#define SOC_ITS_CLK_RST_CTRL_sens_clk_en_END (8)
#define SOC_ITS_CLK_RST_CTRL_its_div_clk_en_START (9)
#define SOC_ITS_CLK_RST_CTRL_its_div_clk_en_END (9)
#define SOC_ITS_CLK_RST_CTRL_sens_rst_n_START (12)
#define SOC_ITS_CLK_RST_CTRL_sens_rst_n_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int dpm_mac_div : 4;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_ITS_DIV_CTRL0_UNION;
#endif
#define SOC_ITS_DIV_CTRL0_dpm_mac_div_START (8)
#define SOC_ITS_DIV_CTRL0_dpm_mac_div_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ist_en : 1;
        unsigned int its_mode : 1;
        unsigned int data_clear : 1;
        unsigned int dpm_mac_clk_sel : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ITS_MODE_CTRL_UNION;
#endif
#define SOC_ITS_MODE_CTRL_ist_en_START (0)
#define SOC_ITS_MODE_CTRL_ist_en_END (0)
#define SOC_ITS_MODE_CTRL_its_mode_START (1)
#define SOC_ITS_MODE_CTRL_its_mode_END (1)
#define SOC_ITS_MODE_CTRL_data_clear_START (2)
#define SOC_ITS_MODE_CTRL_data_clear_END (2)
#define SOC_ITS_MODE_CTRL_dpm_mac_clk_sel_START (3)
#define SOC_ITS_MODE_CTRL_dpm_mac_clk_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timer_period : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ITS_TIMER_PERIOD_UNION;
#endif
#define SOC_ITS_TIMER_PERIOD_timer_period_START (0)
#define SOC_ITS_TIMER_PERIOD_timer_period_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask : 1;
        unsigned int single_window_intr_mode : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ITS_INTR_MSK_UNION;
#endif
#define SOC_ITS_INTR_MSK_intr_mask_START (0)
#define SOC_ITS_INTR_MSK_intr_mask_END (0)
#define SOC_ITS_INTR_MSK_single_window_intr_mode_START (1)
#define SOC_ITS_INTR_MSK_single_window_intr_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ITS_INTR_CTRL_UNION;
#endif
#define SOC_ITS_INTR_CTRL_intr_clr_START (0)
#define SOC_ITS_INTR_CTRL_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ITS_INTR_UNION;
#endif
#define SOC_ITS_INTR_intr_status_START (0)
#define SOC_ITS_INTR_intr_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int dpm_done : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int dpm_data_lsb : 2;
        unsigned int reserved_3 : 1;
        unsigned int rtl_version : 8;
        unsigned int version_num : 16;
    } reg;
} SOC_ITS_DEBUG_STATUS_UNION;
#endif
#define SOC_ITS_DEBUG_STATUS_dpm_done_START (2)
#define SOC_ITS_DEBUG_STATUS_dpm_done_END (2)
#define SOC_ITS_DEBUG_STATUS_dpm_data_lsb_START (5)
#define SOC_ITS_DEBUG_STATUS_dpm_data_lsb_END (6)
#define SOC_ITS_DEBUG_STATUS_rtl version_START (8)
#define SOC_ITS_DEBUG_STATUS_rtl version_END (15)
#define SOC_ITS_DEBUG_STATUS_version num_START (16)
#define SOC_ITS_DEBUG_STATUS_version num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpm_data_t0 : 32;
    } reg;
} SOC_ITS_DPM_DATA_T0_UNION;
#endif
#define SOC_ITS_DPM_DATA_T0_dpm_data_t0_START (0)
#define SOC_ITS_DPM_DATA_T0_dpm_data_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpm_data_t1 : 32;
    } reg;
} SOC_ITS_DPM_DATA_T1_UNION;
#endif
#define SOC_ITS_DPM_DATA_T1_dpm_data_t1_START (0)
#define SOC_ITS_DPM_DATA_T1_dpm_data_t1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int target_window_num : 16;
        unsigned int window_num : 16;
    } reg;
} SOC_ITS_target_window_num_UNION;
#endif
#define SOC_ITS_target_window_num_target_window_num_START (0)
#define SOC_ITS_target_window_num_target_window_num_END (15)
#define SOC_ITS_target_window_num_window_num_START (16)
#define SOC_ITS_target_window_num_window_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpm_out_result0 : 32;
    } reg;
} SOC_ITS_dpm_out_result0_UNION;
#endif
#define SOC_ITS_dpm_out_result0_dpm_out_result0_START (0)
#define SOC_ITS_dpm_out_result0_dpm_out_result0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpm_out_result1 : 32;
    } reg;
} SOC_ITS_dpm_out_result1_UNION;
#endif
#define SOC_ITS_dpm_out_result1_dpm_out_result1_START (0)
#define SOC_ITS_dpm_out_result1_dpm_out_result1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpm_out_result1_lsb : 9;
        unsigned int reserved_0 : 7;
        unsigned int dpm_out_result0_lsb : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_ITS_dpm_out_result_lsb_UNION;
#endif
#define SOC_ITS_dpm_out_result_lsb_dpm_out_result1_lsb_START (0)
#define SOC_ITS_dpm_out_result_lsb_dpm_out_result1_lsb_END (8)
#define SOC_ITS_dpm_out_result_lsb_dpm_out_result0_lsb_START (16)
#define SOC_ITS_dpm_out_result_lsb_dpm_out_result0_lsb_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coefficient_2n : 14;
        unsigned int reserved_0 : 2;
        unsigned int coefficient_2n_plus_1 : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_ITS_COEFFICIENT_UNION;
#endif
#define SOC_ITS_COEFFICIENT_coefficient_2n_START (0)
#define SOC_ITS_COEFFICIENT_coefficient_2n_END (13)
#define SOC_ITS_COEFFICIENT_coefficient_2n_plus_1_START (16)
#define SOC_ITS_COEFFICIENT_coefficient_2n_plus_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sens_debug_data_index : 7;
        unsigned int sens_debug_clk_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ITS_cnt_data_sel_UNION;
#endif
#define SOC_ITS_cnt_data_sel_sens_debug_data_index_START (0)
#define SOC_ITS_cnt_data_sel_sens_debug_data_index_END (6)
#define SOC_ITS_cnt_data_sel_sens_debug_clk_en_START (7)
#define SOC_ITS_cnt_data_sel_sens_debug_clk_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int previous_window_cnt_bin_status : 13;
        unsigned int reserved_0 : 3;
        unsigned int current_window_cnt_gray_status : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ITS_cnt_data_result_UNION;
#endif
#define SOC_ITS_cnt_data_result_previous_window_cnt_bin_status_START (0)
#define SOC_ITS_cnt_data_result_previous_window_cnt_bin_status_END (12)
#define SOC_ITS_cnt_data_result_current_window_cnt_gray_status_START (16)
#define SOC_ITS_cnt_data_result_current_window_cnt_gray_status_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hold_previous_cnt_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ITS_hold_previous_cnt_mode_UNION;
#endif
#define SOC_ITS_hold_previous_cnt_mode_hold_previous_cnt_mode_START (0)
#define SOC_ITS_hold_previous_cnt_mode_hold_previous_cnt_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt_interval : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ITS_cnt_inter_val_UNION;
#endif
#define SOC_ITS_cnt_inter_val_cnt_interval_START (0)
#define SOC_ITS_cnt_inter_val_cnt_interval_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpm_sum_tmp_data : 32;
    } reg;
} SOC_ITS_dpm_sum_tmp_data_UNION;
#endif
#define SOC_ITS_dpm_sum_tmp_data_dpm_sum_tmp_data_START (0)
#define SOC_ITS_dpm_sum_tmp_data_dpm_sum_tmp_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_num_status : 16;
        unsigned int dpm_sum_tmp_data_lsb : 9;
        unsigned int reserved : 5;
        unsigned int intr_status : 1;
        unsigned int cnt_status_valid : 1;
    } reg;
} SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_UNION;
#endif
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_window_num_status_START (0)
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_window_num_status_END (15)
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_dpm_sum_tmp_data_lsb_START (16)
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_dpm_sum_tmp_data_lsb_END (24)
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_intr_status_START (30)
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_intr_status_END (30)
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_cnt_status_valid_START (31)
#define SOC_ITS_dpm_sum_tmp_data_lsb_and_cnt_status_cnt_status_valid_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
