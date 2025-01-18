#ifndef __SOC_DDRC_DMC_TOP_INTERFACE_H__
#define __SOC_DDRC_DMC_TOP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_ADDR(base) ((base) + (0x0000UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_RNKVOL_ADDR(base) ((base) + (0x0010UL))
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_ADDR(base) ((base) + (0x001CUL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CMD_ADDR(base) ((base) + (0x0020UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_DAT_ADDR(base) ((base) + (0x0024UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_ADDR(base) ((base) + (0x0028UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_ADDR(base) ((base) + (0x002CUL))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_ADDR(base) ((base) + (0x0030UL))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_ADDR(base) ((base) + (0x0034UL))
#define SOC_DDRC_DMC_TOP_DDRC_TEST_RAM_TMOD_ADDR(base) ((base) + (0x0040UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_ADDR(base,chs) ((base) + (0x0050+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS0_ADDR(base,chs) ((base) + (0x0054+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS1_ADDR(base,chs) ((base) + (0x0058+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_REALTIME_ADDR(base,chs) ((base) + (0x005C+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_ADDR(base) ((base) + (0x0080UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_ADDR(base) ((base) + (0x0088UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_o_ADDR(base) ((base) + (0x0090UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_ADDR(base) ((base) + (0x0094UL))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ADDR(base) ((base) + (0x0098UL))
#else
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_ADDR(base) ((base) + (0x0000))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_RNKVOL_ADDR(base) ((base) + (0x0010))
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_ADDR(base) ((base) + (0x001C))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CMD_ADDR(base) ((base) + (0x0020))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_DAT_ADDR(base) ((base) + (0x0024))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_ADDR(base) ((base) + (0x0028))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_ADDR(base) ((base) + (0x002C))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_ADDR(base) ((base) + (0x0030))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_ADDR(base) ((base) + (0x0034))
#define SOC_DDRC_DMC_TOP_DDRC_TEST_RAM_TMOD_ADDR(base) ((base) + (0x0040))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_ADDR(base,chs) ((base) + (0x0050+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS0_ADDR(base,chs) ((base) + (0x0054+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS1_ADDR(base,chs) ((base) + (0x0058+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_REALTIME_ADDR(base,chs) ((base) + (0x005C+0x10*(chs)))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_ADDR(base) ((base) + (0x0080))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_ADDR(base) ((base) + (0x0088))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_o_ADDR(base) ((base) + (0x0090))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_ADDR(base) ((base) + (0x0094))
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TREG_CLK_ON_ADDR(base) ((base) + (0x0098))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int mem_width : 2;
        unsigned int tdm_dual_ch : 1;
        unsigned int clk_ratio : 2;
        unsigned int seer_en : 1;
        unsigned int rdata_ch_intlv_mode : 1;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_mem_width_START (4)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_mem_width_END (5)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_tdm_dual_ch_START (6)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_tdm_dual_ch_END (6)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_clk_ratio_START (7)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_clk_ratio_END (8)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_seer_en_START (9)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_seer_en_END (9)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_rdata_ch_intlv_mode_START (10)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TOPMODE_rdata_ch_intlv_mode_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_bankgroup : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_RNKVOL_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_RNKVOL_mem_bankgroup_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_RNKVOL_mem_bankgroup_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mtest_start : 1;
        unsigned int dual_ch : 1;
        unsigned int broadcast_mode : 2;
        unsigned int mbist_mode : 1;
        unsigned int col_shift : 2;
        unsigned int reserved : 25;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_mtest_start_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_mtest_start_END (0)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_dual_ch_START (1)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_dual_ch_END (1)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_broadcast_mode_START (2)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_broadcast_mode_END (3)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_mbist_mode_START (4)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_mbist_mode_END (4)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_col_shift_START (5)
#define SOC_DDRC_DMC_TOP_DDRC_CTRL_MTEST_col_shift_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exmbist_cmd : 32;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CMD_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CMD_exmbist_cmd_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CMD_exmbist_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exmbist_din : 32;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_DAT_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_DAT_exmbist_din_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_DAT_exmbist_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mbist_rank : 3;
        unsigned int reserved_0 : 5;
        unsigned int mbist_lr : 3;
        unsigned int reserved_1 : 3;
        unsigned int mbist_lg_rnk_swp : 2;
        unsigned int mbist_rank_swp : 3;
        unsigned int reserved_2 : 13;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_END (2)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_lr_START (8)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_lr_END (10)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_lg_rnk_swp_START (14)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_lg_rnk_swp_END (15)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_swp_START (16)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MBIST_mbist_rank_swp_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int two_clk_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_two_clk_mode_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_EXMBIST_CLK_MODE_two_clk_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int exmbist_dout : 32;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_exmbist_dout_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_DOUT_exmbist_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bist_done : 1;
        unsigned int bist_pass : 1;
        unsigned int reserved_0 : 2;
        unsigned int parity_error : 1;
        unsigned int watchdog_error : 1;
        unsigned int diag_fifo_last : 1;
        unsigned int bist_mode : 1;
        unsigned int diag_ip : 3;
        unsigned int reserved_1 : 1;
        unsigned int fingerprint : 4;
        unsigned int iter_cnt : 16;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_done_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_done_END (0)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_pass_START (1)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_pass_END (1)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_parity_error_START (4)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_parity_error_END (4)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_watchdog_error_START (5)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_watchdog_error_END (5)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_fifo_last_START (6)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_fifo_last_END (6)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_mode_START (7)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_bist_mode_END (7)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_ip_START (8)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_diag_ip_END (10)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_fingerprint_START (12)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_fingerprint_END (15)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_iter_cnt_START (16)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_EXMBIST_STATUS_iter_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_tmod : 16;
        unsigned int ram_tmod_st : 16;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_TEST_RAM_TMOD_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_TEST_RAM_TMOD_ram_tmod_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_TEST_RAM_TMOD_ram_tmod_END (15)
#define SOC_DDRC_DMC_TOP_DDRC_TEST_RAM_TMOD_ram_tmod_st_START (16)
#define SOC_DDRC_DMC_TOP_DDRC_TEST_RAM_TMOD_ram_tmod_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brsp_valid_window : 20;
        unsigned int brsp_infinate_mode : 1;
        unsigned int brsp_status_clr : 1;
        unsigned int brsp_done : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_valid_window_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_valid_window_END (19)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_infinate_mode_START (20)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_infinate_mode_END (20)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_status_clr_START (21)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_status_clr_END (21)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_done_START (22)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_BRSP_brsp_done_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brsp_status0_dq : 20;
        unsigned int brsp_status0_alert : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS0_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS0_brsp_status0_dq_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS0_brsp_status0_dq_END (19)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS0_brsp_status0_alert_START (20)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS0_brsp_status0_alert_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brsp_status1_dq : 20;
        unsigned int brsp_status1_alert : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS1_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS1_brsp_status1_dq_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS1_brsp_status1_dq_END (19)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS1_brsp_status1_alert_START (20)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_STATUS1_brsp_status1_alert_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brsp_realtime_dq : 20;
        unsigned int brsp_realtime_alert : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_REALTIME_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_REALTIME_brsp_realtime_dq_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_REALTIME_brsp_realtime_dq_END (19)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_REALTIME_brsp_realtime_alert_START (20)
#define SOC_DDRC_DMC_TOP_DDRC_HIS_BRSP_REAL_REALTIME_brsp_realtime_alert_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int matrix_rptr : 7;
        unsigned int matrix_wptr_rst : 1;
        unsigned int matrix_ohot : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_matrix_rptr_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_matrix_rptr_END (6)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_matrix_wptr_rst_START (7)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_matrix_wptr_rst_END (7)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_matrix_ohot_START (8)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_matrix_ohot_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int matrix : 32;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_matrix_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_matrix_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int matrix_o : 32;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_o_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_o_matrix_o_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_MATRIX_bit_o_matrix_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int disp_grt_fifo_full : 1;
        unsigned int disp_grt_fifo_empty : 1;
        unsigned int disp_seer_fifo_full : 1;
        unsigned int disp_seer_fifo_empty : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_full_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_full_END (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_empty_START (1)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_grt_fifo_empty_END (1)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_seer_fifo_full_START (2)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_seer_fifo_full_END (2)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_seer_fifo_empty_START (3)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_FIFO_STATUS_disp_seer_fifo_empty_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int treg_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DDRC_DMC_TOP_DDRC_CFG_TREG_CLK_ON_UNION;
#endif
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TREG_CLK_ON_treg_clk_on_START (0)
#define SOC_DDRC_DMC_TOP_DDRC_CFG_TREG_CLK_ON_treg_clk_on_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
