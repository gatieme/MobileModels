#ifndef __SOC_TRNG_INTERFACE_H__
#define __SOC_TRNG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_TRNG_REG_TRNG_SEL_ADDR(base) ((base) + (0x0300))
#define SOC_TRNG_OTP_TRNG_SEL_ADDR(base) ((base) + (0x0304))
#define SOC_TRNG_OTP_SW_FLAG_ADDR(base) ((base) + (0x0308))
#define SOC_TRNG_FRO_EN_0_ADDR(base) ((base) + (0x030c))
#define SOC_TRNG_FRO_EN_1_ADDR(base) ((base) + (0x0310))
#define SOC_TRNG_GARO_EN_ADDR(base) ((base) + (0x0314))
#define SOC_TRNG_MT_FRO_EN_ADDR(base) ((base) + (0x0318))
#define SOC_TRNG_MT_GARO_EN_ADDR(base) ((base) + (0x031c))
#define SOC_TRNG_ENTROPY_SOURCE_ST_ADDR(base) ((base) + (0x320))
#define SOC_TRNG_SAMPLE_CLK_CFG_ADDR(base) ((base) + (0x324))
#define SOC_TRNG_INT_CHI_ONLINE_CLR_ADDR(base) ((base) + (0x328))
#define SOC_TRNG_RAW_BYPASS_EN_ADDR(base) ((base) + (0x32c))
#define SOC_TRNG_THRE_CHI_PRE1_ADDR(base) ((base) + (0x0330))
#define SOC_TRNG_THRE_CHI_PRE2_ADDR(base) ((base) + (0x334))
#define SOC_TRNG_THRE_CHI_PRE3_ADDR(base) ((base) + (0x338))
#define SOC_TRNG_THRE_CHI_ENTROPY_ADDR(base) ((base) + (0x33c))
#define SOC_TRNG_THRE_LONG_RUN_ADDR(base) ((base) + (0x340))
#define SOC_TRNG_THRE_POKER_ADDR(base) ((base) + (0x344))
#define SOC_TRNG_TEST_WIN_RAW_TEST_ADDR(base) ((base) + (0x348))
#define SOC_TRNG_THRE_FAIL_NUM_ADDR(base) ((base) + (0x34c))
#define SOC_TRNG_RAW_TEST_CLEAR_ADDR(base) ((base) + (0x350))
#define SOC_TRNG_RAW_FAIL_CNT_ADDR(base) ((base) + (0x354))
#define SOC_TRNG_RAW_STATE_ADDR(base) ((base) + (0x358))
#define SOC_TRNG_XOR_COMP_CFG_ADDR(base) ((base) + (0x35c))
#define SOC_TRNG_XOR_CHAIN_CFG_ADDR(base) ((base) + (0x360))
#define SOC_TRNG_POST_PROCESS_ADDR(base) ((base) + (0x364))
#define SOC_TRNG_RESEED_CNT_LIMIT_ADDR(base) ((base) + (0x368))
#define SOC_TRNG_POST_TEST_BYP_ADDR(base) ((base) + (0x36c))
#define SOC_TRNG_POST_TEST_ALARM_MSK_ADDR(base) ((base) + (0x370))
#define SOC_TRNG_DISTRIBUTION_ADDR(base) ((base) + (0x378))
#define SOC_TRNG_ALARM_STATE_ADDR(base) ((base) + (0x37c))
#define SOC_TRNG_THRE_POST_POKER_ADDR(base) ((base) + (0x384))
#define SOC_TRNG_POST_TEST_WIN_RAW_TEST_ADDR(base) ((base) + (0x388))
#define SOC_TRNG_THRE_POST_FAIL_NUM_ADDR(base) ((base) + (0x38c))
#define SOC_TRNG_POST_TEST_CLEAR_ADDR(base) ((base) + (0x390))
#define SOC_TRNG_POST_FAIL_CNT_ADDR(base) ((base) + (0x394))
#define SOC_TRNG_WAIT_FOR_USE_ADDR(base) ((base) + (0x39c))
#define SOC_TRNG_RNG_TIME_OUT_ADDR(base) ((base) + (0x3a0))
#define SOC_TRNG_CHI_TEST_STATE_ADDR(base) ((base) + (0x3a4))
#define SOC_TRNG_CLK_EN_ADDR(base) ((base) + (0x3a8))
#define SOC_TRNG_DONE_ADDR(base) ((base) + (0x3ac))
#define SOC_TRNG_READY_ADDR(base) ((base) + (0x3b0))
#define SOC_TRNG_READY_THRE_ADDR(base) ((base) + (0x3b4))
#define SOC_TRNG_FIFO_DATA_ADDR(base) ((base) + (0x3b8))
#define SOC_TRNG_PRT_LOCK_ADDR(base) ((base) + (0x3bc))
#define SOC_TRNG_ENTROPY_MERGE_ADDR(base) ((base) + (0x3c0))
#define SOC_TRNG_KNOWN_ANSWER_TEST_ADDR(base) ((base) + (0x3c4))
#define SOC_TRNG_SIGNAL_ALARM_ADDR(base) ((base) + (0x3c8))
#define SOC_TRNG_OTP_HEALTH_TEST_EN_ADDR(base) ((base) + (0x3cc))
#define SOC_TRNG_HEALTH_TEST_BYPASS_ADDR(base) ((base) + (0x3d0))
#define SOC_TRNG_THRE_REPETITION_COUNT_ADDR(base) ((base) + (0x3d4))
#define SOC_TRNG_THRE_ADAPTIVE_PROPORTION_ADDR(base) ((base) + (0x3d8))
#define SOC_TRNG_TEST_WIN_HEALTH_ADDR(base) ((base) + (0x3dc))
#define SOC_TRNG_THRE_FAIL_NUM_HEALTH_ADDR(base) ((base) + (0x3e0))
#define SOC_TRNG_FAIL_NUM_HEALTH_TEST_ADDR(base) ((base) + (0x3e4))
#define SOC_TRNG_HEALTH_TEST_CLEAR_ADDR(base) ((base) + (0x3e8))
#define SOC_TRNG_MSK_ALARM_HEALTH_ADDR(base) ((base) + (0x3ec))
#define SOC_TRNG_HEALTH_ALARM_STATE_ADDR(base) ((base) + (0x3f0))
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_ADDR(base) ((base) + (0x3f4))
#define SOC_TRNG_KAT_ENTROPY_INPUT_ADDR(base,n) ((base) + (0x3f8+(n)*4))
#define SOC_TRNG_KAT_ENTROPY_INPUT_PR1_ADDR(base,n) ((base) + (0x430+(n)*4))
#define SOC_TRNG_KAT_ENTROPY_INPUT_PR2_ADDR(base,n) ((base) + (0x468+(n)*4))
#define SOC_TRNG_KAT_NONCE_ADDR(base,m) ((base) + (0x4a0+(m)*4))
#define SOC_TRNG_KAT_PERSONALIZATION_STRING_ADDR(base) ((base) + (0x4b0))
#define SOC_TRNG_KAT_ADDITIONAL_INPUT1_ADDR(base) ((base) + (0x4b4))
#define SOC_TRNG_KAT_ADDITIONAL_INPUT2_ADDR(base) ((base) + (0x4b8))
#define SOC_TRNG_KNOWN_ANSWER_TEST_RESULT_ADDR(base,k) ((base) + (0x4bc+(k)*4))
#define SOC_TRNG_RO_SAMPLE_EN_ADDR(base) ((base) + (0x53c))
#define SOC_TRNG_RO_DIV_CFG1_ADDR(base) ((base) + (0x540))
#define SOC_TRNG_RO_DIV_CFG2_ADDR(base) ((base) + (0x544))
#define SOC_TRNG_RO_SAMPLE_SEL_ADDR(base) ((base) + (0x548))
#define SOC_TRNG_OTPC_TRNG_TRIM_0_ADDR(base) ((base) + (0x54c))
#define SOC_TRNG_OTPC_TRNG_TRIM_1_ADDR(base) ((base) + (0x550))
#define SOC_TRNG_OTPC_TRNG_TRIM_2_ADDR(base) ((base) + (0x554))
#define SOC_TRNG_OTPC_TRNG_TRIM_3_ADDR(base) ((base) + (0x558))
#define SOC_TRNG_OTPC_TRNG_TRIM_CRC_ADDR(base) ((base) + (0x55c))
#define SOC_TRNG_OTPC_STATUS_1_ADDR(base) ((base) + (0x560))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_trng_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_REG_TRNG_SEL_UNION;
#endif
#define SOC_TRNG_REG_TRNG_SEL_reg_trng_sel_START (0)
#define SOC_TRNG_REG_TRNG_SEL_reg_trng_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int otp_trng_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_OTP_TRNG_SEL_UNION;
#endif
#define SOC_TRNG_OTP_TRNG_SEL_otp_trng_sel_START (0)
#define SOC_TRNG_OTP_TRNG_SEL_otp_trng_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int otp_sw_flag : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_OTP_SW_FLAG_UNION;
#endif
#define SOC_TRNG_OTP_SW_FLAG_otp_sw_flag_START (0)
#define SOC_TRNG_OTP_SW_FLAG_otp_sw_flag_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fro_en_0 : 32;
    } reg;
} SOC_TRNG_FRO_EN_0_UNION;
#endif
#define SOC_TRNG_FRO_EN_0_fro_en_0_START (0)
#define SOC_TRNG_FRO_EN_0_fro_en_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fro_en_1 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_TRNG_FRO_EN_1_UNION;
#endif
#define SOC_TRNG_FRO_EN_1_fro_en_1_START (0)
#define SOC_TRNG_FRO_EN_1_fro_en_1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int garo_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TRNG_GARO_EN_UNION;
#endif
#define SOC_TRNG_GARO_EN_garo_en_START (0)
#define SOC_TRNG_GARO_EN_garo_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mt_fro_en : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_TRNG_MT_FRO_EN_UNION;
#endif
#define SOC_TRNG_MT_FRO_EN_mt_fro_en_START (0)
#define SOC_TRNG_MT_FRO_EN_mt_fro_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mt_garo_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_MT_GARO_EN_UNION;
#endif
#define SOC_TRNG_MT_GARO_EN_mt_garo_en_START (0)
#define SOC_TRNG_MT_GARO_EN_mt_garo_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int src_afifo_empty : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_ENTROPY_SOURCE_ST_UNION;
#endif
#define SOC_TRNG_ENTROPY_SOURCE_ST_src_afifo_empty_START (0)
#define SOC_TRNG_ENTROPY_SOURCE_ST_src_afifo_empty_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_clk_cfg : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_TRNG_SAMPLE_CLK_CFG_UNION;
#endif
#define SOC_TRNG_SAMPLE_CLK_CFG_sample_clk_cfg_START (0)
#define SOC_TRNG_SAMPLE_CLK_CFG_sample_clk_cfg_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_chi_online_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TRNG_INT_CHI_ONLINE_CLR_UNION;
#endif
#define SOC_TRNG_INT_CHI_ONLINE_CLR_int_chi_online_clr_START (0)
#define SOC_TRNG_INT_CHI_ONLINE_CLR_int_chi_online_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass_en_poker : 4;
        unsigned int bypass_en_chi : 4;
        unsigned int bypass_en_lrun : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_TRNG_RAW_BYPASS_EN_UNION;
#endif
#define SOC_TRNG_RAW_BYPASS_EN_bypass_en_poker_START (0)
#define SOC_TRNG_RAW_BYPASS_EN_bypass_en_poker_END (3)
#define SOC_TRNG_RAW_BYPASS_EN_bypass_en_chi_START (4)
#define SOC_TRNG_RAW_BYPASS_EN_bypass_en_chi_END (7)
#define SOC_TRNG_RAW_BYPASS_EN_bypass_en_lrun_START (8)
#define SOC_TRNG_RAW_BYPASS_EN_bypass_en_lrun_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_pre1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TRNG_THRE_CHI_PRE1_UNION;
#endif
#define SOC_TRNG_THRE_CHI_PRE1_thre_pre1_START (0)
#define SOC_TRNG_THRE_CHI_PRE1_thre_pre1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_pre2 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TRNG_THRE_CHI_PRE2_UNION;
#endif
#define SOC_TRNG_THRE_CHI_PRE2_thre_pre2_START (0)
#define SOC_TRNG_THRE_CHI_PRE2_thre_pre2_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_pre3 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TRNG_THRE_CHI_PRE3_UNION;
#endif
#define SOC_TRNG_THRE_CHI_PRE3_thre_pre3_START (0)
#define SOC_TRNG_THRE_CHI_PRE3_thre_pre3_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_entropy : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TRNG_THRE_CHI_ENTROPY_UNION;
#endif
#define SOC_TRNG_THRE_CHI_ENTROPY_thre_entropy_START (0)
#define SOC_TRNG_THRE_CHI_ENTROPY_thre_entropy_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_long_run : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_TRNG_THRE_LONG_RUN_UNION;
#endif
#define SOC_TRNG_THRE_LONG_RUN_thre_long_run_START (0)
#define SOC_TRNG_THRE_LONG_RUN_thre_long_run_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int poker_ck_hig : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TRNG_THRE_POKER_UNION;
#endif
#define SOC_TRNG_THRE_POKER_poker_ck_hig_START (0)
#define SOC_TRNG_THRE_POKER_poker_ck_hig_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_win_poker : 8;
        unsigned int test_win_chi : 8;
        unsigned int test_win_longrun : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_TEST_WIN_RAW_TEST_UNION;
#endif
#define SOC_TRNG_TEST_WIN_RAW_TEST_test_win_poker_START (0)
#define SOC_TRNG_TEST_WIN_RAW_TEST_test_win_poker_END (7)
#define SOC_TRNG_TEST_WIN_RAW_TEST_test_win_chi_START (8)
#define SOC_TRNG_TEST_WIN_RAW_TEST_test_win_chi_END (15)
#define SOC_TRNG_TEST_WIN_RAW_TEST_test_win_longrun_START (16)
#define SOC_TRNG_TEST_WIN_RAW_TEST_test_win_longrun_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_fail_num_poker : 8;
        unsigned int thre_fail_num_chi : 8;
        unsigned int thre_fail_num_longrun : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_THRE_FAIL_NUM_UNION;
#endif
#define SOC_TRNG_THRE_FAIL_NUM_thre_fail_num_poker_START (0)
#define SOC_TRNG_THRE_FAIL_NUM_thre_fail_num_poker_END (7)
#define SOC_TRNG_THRE_FAIL_NUM_thre_fail_num_chi_START (8)
#define SOC_TRNG_THRE_FAIL_NUM_thre_fail_num_chi_END (15)
#define SOC_TRNG_THRE_FAIL_NUM_thre_fail_num_longrun_START (16)
#define SOC_TRNG_THRE_FAIL_NUM_thre_fail_num_longrun_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clear_poker : 1;
        unsigned int clear_chi : 1;
        unsigned int clear_longrun : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_TRNG_RAW_TEST_CLEAR_UNION;
#endif
#define SOC_TRNG_RAW_TEST_CLEAR_clear_poker_START (0)
#define SOC_TRNG_RAW_TEST_CLEAR_clear_poker_END (0)
#define SOC_TRNG_RAW_TEST_CLEAR_clear_chi_START (1)
#define SOC_TRNG_RAW_TEST_CLEAR_clear_chi_END (1)
#define SOC_TRNG_RAW_TEST_CLEAR_clear_longrun_START (2)
#define SOC_TRNG_RAW_TEST_CLEAR_clear_longrun_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fail_num_poker : 8;
        unsigned int fail_num_chi : 8;
        unsigned int fail_num_longrun : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_RAW_FAIL_CNT_UNION;
#endif
#define SOC_TRNG_RAW_FAIL_CNT_fail_num_poker_START (0)
#define SOC_TRNG_RAW_FAIL_CNT_fail_num_poker_END (7)
#define SOC_TRNG_RAW_FAIL_CNT_fail_num_chi_START (8)
#define SOC_TRNG_RAW_FAIL_CNT_fail_num_chi_END (15)
#define SOC_TRNG_RAW_FAIL_CNT_fail_num_longrun_START (16)
#define SOC_TRNG_RAW_FAIL_CNT_fail_num_longrun_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int raw_state : 32;
    } reg;
} SOC_TRNG_RAW_STATE_UNION;
#endif
#define SOC_TRNG_RAW_STATE_raw_state_START (0)
#define SOC_TRNG_RAW_STATE_raw_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xor_comp_rate : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_TRNG_XOR_COMP_CFG_UNION;
#endif
#define SOC_TRNG_XOR_COMP_CFG_xor_comp_rate_START (0)
#define SOC_TRNG_XOR_COMP_CFG_xor_comp_rate_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xor_chain_byp : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_XOR_CHAIN_CFG_UNION;
#endif
#define SOC_TRNG_XOR_CHAIN_CFG_xor_chain_byp_START (0)
#define SOC_TRNG_XOR_CHAIN_CFG_xor_chain_byp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int byp_en_post_proc : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_POST_PROCESS_UNION;
#endif
#define SOC_TRNG_POST_PROCESS_byp_en_post_proc_START (0)
#define SOC_TRNG_POST_PROCESS_byp_en_post_proc_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reseed_cnt_limit : 32;
    } reg;
} SOC_TRNG_RESEED_CNT_LIMIT_UNION;
#endif
#define SOC_TRNG_RESEED_CNT_LIMIT_reseed_cnt_limit_START (0)
#define SOC_TRNG_RESEED_CNT_LIMIT_reseed_cnt_limit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int byp_en_poker : 4;
        unsigned int byp_en_256same : 4;
        unsigned int byp_en_32same : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_TRNG_POST_TEST_BYP_UNION;
#endif
#define SOC_TRNG_POST_TEST_BYP_byp_en_poker_START (0)
#define SOC_TRNG_POST_TEST_BYP_byp_en_poker_END (3)
#define SOC_TRNG_POST_TEST_BYP_byp_en_256same_START (4)
#define SOC_TRNG_POST_TEST_BYP_byp_en_256same_END (7)
#define SOC_TRNG_POST_TEST_BYP_byp_en_32same_START (8)
#define SOC_TRNG_POST_TEST_BYP_byp_en_32same_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int msk_alarm_poker : 4;
        unsigned int msk_alarm_256same : 4;
        unsigned int msk_alarm_32same : 4;
        unsigned int msk_alarm_prepoker : 4;
        unsigned int msk_alarm_chi : 4;
        unsigned int msk_alarm_longrun : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_POST_TEST_ALARM_MSK_UNION;
#endif
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_poker_START (0)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_poker_END (3)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_256same_START (4)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_256same_END (7)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_32same_START (8)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_32same_END (11)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_prepoker_START (12)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_prepoker_END (15)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_chi_START (16)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_chi_END (19)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_longrun_START (20)
#define SOC_TRNG_POST_TEST_ALARM_MSK_msk_alarm_longrun_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int full_dist_mode : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_DISTRIBUTION_UNION;
#endif
#define SOC_TRNG_DISTRIBUTION_full_dist_mode_START (0)
#define SOC_TRNG_DISTRIBUTION_full_dist_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_pos_poker : 1;
        unsigned int alarm_same32 : 1;
        unsigned int alarm_same256 : 1;
        unsigned int alarm_pre_poker : 1;
        unsigned int alarm_chi_test : 1;
        unsigned int alarm_longrun : 1;
        unsigned int alarm_otpc_check : 1;
        unsigned int signal_alarm : 1;
        unsigned int alarm_adaptive_proportion : 1;
        unsigned int alarm_repetition_count : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_TRNG_ALARM_STATE_UNION;
#endif
#define SOC_TRNG_ALARM_STATE_alarm_pos_poker_START (0)
#define SOC_TRNG_ALARM_STATE_alarm_pos_poker_END (0)
#define SOC_TRNG_ALARM_STATE_alarm_same32_START (1)
#define SOC_TRNG_ALARM_STATE_alarm_same32_END (1)
#define SOC_TRNG_ALARM_STATE_alarm_same256_START (2)
#define SOC_TRNG_ALARM_STATE_alarm_same256_END (2)
#define SOC_TRNG_ALARM_STATE_alarm_pre_poker_START (3)
#define SOC_TRNG_ALARM_STATE_alarm_pre_poker_END (3)
#define SOC_TRNG_ALARM_STATE_alarm_chi_test_START (4)
#define SOC_TRNG_ALARM_STATE_alarm_chi_test_END (4)
#define SOC_TRNG_ALARM_STATE_alarm_longrun_START (5)
#define SOC_TRNG_ALARM_STATE_alarm_longrun_END (5)
#define SOC_TRNG_ALARM_STATE_alarm_otpc_check_START (6)
#define SOC_TRNG_ALARM_STATE_alarm_otpc_check_END (6)
#define SOC_TRNG_ALARM_STATE_signal_alarm_START (7)
#define SOC_TRNG_ALARM_STATE_signal_alarm_END (7)
#define SOC_TRNG_ALARM_STATE_alarm_adaptive_proportion_START (8)
#define SOC_TRNG_ALARM_STATE_alarm_adaptive_proportion_END (8)
#define SOC_TRNG_ALARM_STATE_alarm_repetition_count_START (9)
#define SOC_TRNG_ALARM_STATE_alarm_repetition_count_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_poker_ck_hig : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TRNG_THRE_POST_POKER_UNION;
#endif
#define SOC_TRNG_THRE_POST_POKER_post_poker_ck_hig_START (0)
#define SOC_TRNG_THRE_POST_POKER_post_poker_ck_hig_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_win_post_poker : 8;
        unsigned int test_win_same256 : 8;
        unsigned int test_win_same32 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_POST_TEST_WIN_RAW_TEST_UNION;
#endif
#define SOC_TRNG_POST_TEST_WIN_RAW_TEST_test_win_post_poker_START (0)
#define SOC_TRNG_POST_TEST_WIN_RAW_TEST_test_win_post_poker_END (7)
#define SOC_TRNG_POST_TEST_WIN_RAW_TEST_test_win_same256_START (8)
#define SOC_TRNG_POST_TEST_WIN_RAW_TEST_test_win_same256_END (15)
#define SOC_TRNG_POST_TEST_WIN_RAW_TEST_test_win_same32_START (16)
#define SOC_TRNG_POST_TEST_WIN_RAW_TEST_test_win_same32_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_fail_num_post_poker : 8;
        unsigned int thre_fail_num_same256 : 8;
        unsigned int thre_fail_num_same32 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_THRE_POST_FAIL_NUM_UNION;
#endif
#define SOC_TRNG_THRE_POST_FAIL_NUM_thre_fail_num_post_poker_START (0)
#define SOC_TRNG_THRE_POST_FAIL_NUM_thre_fail_num_post_poker_END (7)
#define SOC_TRNG_THRE_POST_FAIL_NUM_thre_fail_num_same256_START (8)
#define SOC_TRNG_THRE_POST_FAIL_NUM_thre_fail_num_same256_END (15)
#define SOC_TRNG_THRE_POST_FAIL_NUM_thre_fail_num_same32_START (16)
#define SOC_TRNG_THRE_POST_FAIL_NUM_thre_fail_num_same32_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clear_post_poker : 1;
        unsigned int clear_same256 : 1;
        unsigned int clear_same32 : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_TRNG_POST_TEST_CLEAR_UNION;
#endif
#define SOC_TRNG_POST_TEST_CLEAR_clear_post_poker_START (0)
#define SOC_TRNG_POST_TEST_CLEAR_clear_post_poker_END (0)
#define SOC_TRNG_POST_TEST_CLEAR_clear_same256_START (1)
#define SOC_TRNG_POST_TEST_CLEAR_clear_same256_END (1)
#define SOC_TRNG_POST_TEST_CLEAR_clear_same32_START (2)
#define SOC_TRNG_POST_TEST_CLEAR_clear_same32_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fail_num_post_poker : 8;
        unsigned int fail_num_same256 : 8;
        unsigned int fail_num_same32 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_POST_FAIL_CNT_UNION;
#endif
#define SOC_TRNG_POST_FAIL_CNT_fail_num_post_poker_START (0)
#define SOC_TRNG_POST_FAIL_CNT_fail_num_post_poker_END (7)
#define SOC_TRNG_POST_FAIL_CNT_fail_num_same256_START (8)
#define SOC_TRNG_POST_FAIL_CNT_fail_num_same256_END (15)
#define SOC_TRNG_POST_FAIL_CNT_fail_num_same32_START (16)
#define SOC_TRNG_POST_FAIL_CNT_fail_num_same32_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wait_for_use : 32;
    } reg;
} SOC_TRNG_WAIT_FOR_USE_UNION;
#endif
#define SOC_TRNG_WAIT_FOR_USE_wait_for_use_START (0)
#define SOC_TRNG_WAIT_FOR_USE_wait_for_use_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int time_out_alarm : 1;
        unsigned int time_out_alarm_msk : 1;
        unsigned int time_out_clear : 1;
        unsigned int reserved : 5;
        unsigned int time_out_limit : 24;
    } reg;
} SOC_TRNG_RNG_TIME_OUT_UNION;
#endif
#define SOC_TRNG_RNG_TIME_OUT_time_out_alarm_START (0)
#define SOC_TRNG_RNG_TIME_OUT_time_out_alarm_END (0)
#define SOC_TRNG_RNG_TIME_OUT_time_out_alarm_msk_START (1)
#define SOC_TRNG_RNG_TIME_OUT_time_out_alarm_msk_END (1)
#define SOC_TRNG_RNG_TIME_OUT_time_out_clear_START (2)
#define SOC_TRNG_RNG_TIME_OUT_time_out_clear_END (2)
#define SOC_TRNG_RNG_TIME_OUT_time_out_limit_START (8)
#define SOC_TRNG_RNG_TIME_OUT_time_out_limit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int chi_fai : 1;
        unsigned int int_chi_online : 4;
        unsigned int alarm_chi_tot : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_TRNG_CHI_TEST_STATE_UNION;
#endif
#define SOC_TRNG_CHI_TEST_STATE_chi_fai_START (0)
#define SOC_TRNG_CHI_TEST_STATE_chi_fai_END (0)
#define SOC_TRNG_CHI_TEST_STATE_int_chi_online_START (1)
#define SOC_TRNG_CHI_TEST_STATE_int_chi_online_END (4)
#define SOC_TRNG_CHI_TEST_STATE_alarm_chi_tot_START (5)
#define SOC_TRNG_CHI_TEST_STATE_alarm_chi_tot_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_clk_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_CLK_EN_UNION;
#endif
#define SOC_TRNG_CLK_EN_trng_clk_en_START (0)
#define SOC_TRNG_CLK_EN_trng_clk_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_done : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_DONE_UNION;
#endif
#define SOC_TRNG_DONE_trng_done_START (0)
#define SOC_TRNG_DONE_trng_done_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_ready : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_READY_UNION;
#endif
#define SOC_TRNG_READY_trng_ready_START (0)
#define SOC_TRNG_READY_trng_ready_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_ready_thre : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_TRNG_READY_THRE_UNION;
#endif
#define SOC_TRNG_READY_THRE_trng_ready_thre_START (0)
#define SOC_TRNG_READY_THRE_trng_ready_thre_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_fifo_data : 32;
    } reg;
} SOC_TRNG_FIFO_DATA_UNION;
#endif
#define SOC_TRNG_FIFO_DATA_trng_fifo_data_START (0)
#define SOC_TRNG_FIFO_DATA_trng_fifo_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lock_reg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_PRT_LOCK_UNION;
#endif
#define SOC_TRNG_PRT_LOCK_lock_reg_START (0)
#define SOC_TRNG_PRT_LOCK_lock_reg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int src_merge_cfg : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_ENTROPY_MERGE_UNION;
#endif
#define SOC_TRNG_ENTROPY_MERGE_src_merge_cfg_START (0)
#define SOC_TRNG_ENTROPY_MERGE_src_merge_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int answer_test_fail : 1;
        unsigned int answer_test_done : 1;
        unsigned int answer_test_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_TRNG_KNOWN_ANSWER_TEST_UNION;
#endif
#define SOC_TRNG_KNOWN_ANSWER_TEST_answer_test_fail_START (0)
#define SOC_TRNG_KNOWN_ANSWER_TEST_answer_test_fail_END (0)
#define SOC_TRNG_KNOWN_ANSWER_TEST_answer_test_done_START (1)
#define SOC_TRNG_KNOWN_ANSWER_TEST_answer_test_done_END (1)
#define SOC_TRNG_KNOWN_ANSWER_TEST_answer_test_en_START (2)
#define SOC_TRNG_KNOWN_ANSWER_TEST_answer_test_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int all_signal_alarm : 4;
        unsigned int all_signal_alarm_clr : 1;
        unsigned int reserved_0 : 3;
        unsigned int msk_all_signal_alarm : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_TRNG_SIGNAL_ALARM_UNION;
#endif
#define SOC_TRNG_SIGNAL_ALARM_all_signal_alarm_START (0)
#define SOC_TRNG_SIGNAL_ALARM_all_signal_alarm_END (3)
#define SOC_TRNG_SIGNAL_ALARM_all_signal_alarm_clr_START (4)
#define SOC_TRNG_SIGNAL_ALARM_all_signal_alarm_clr_END (4)
#define SOC_TRNG_SIGNAL_ALARM_msk_all_signal_alarm_START (8)
#define SOC_TRNG_SIGNAL_ALARM_msk_all_signal_alarm_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int otp_health_test_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TRNG_OTP_HEALTH_TEST_EN_UNION;
#endif
#define SOC_TRNG_OTP_HEALTH_TEST_EN_otp_health_test_en_START (0)
#define SOC_TRNG_OTP_HEALTH_TEST_EN_otp_health_test_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass_en_adaptive_proportion : 4;
        unsigned int bypass_en_repetition_count : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_TRNG_HEALTH_TEST_BYPASS_UNION;
#endif
#define SOC_TRNG_HEALTH_TEST_BYPASS_bypass_en_adaptive_proportion_START (0)
#define SOC_TRNG_HEALTH_TEST_BYPASS_bypass_en_adaptive_proportion_END (3)
#define SOC_TRNG_HEALTH_TEST_BYPASS_bypass_en_repetition_count_START (4)
#define SOC_TRNG_HEALTH_TEST_BYPASS_bypass_en_repetition_count_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_repetition_count : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TRNG_THRE_REPETITION_COUNT_UNION;
#endif
#define SOC_TRNG_THRE_REPETITION_COUNT_thre_repetition_count_START (0)
#define SOC_TRNG_THRE_REPETITION_COUNT_thre_repetition_count_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_adaptive_proportion : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TRNG_THRE_ADAPTIVE_PROPORTION_UNION;
#endif
#define SOC_TRNG_THRE_ADAPTIVE_PROPORTION_thre_adaptive_proportion_START (0)
#define SOC_TRNG_THRE_ADAPTIVE_PROPORTION_thre_adaptive_proportion_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_win_adaptive_proportion : 8;
        unsigned int test_win_repetition_count : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_TRNG_TEST_WIN_HEALTH_UNION;
#endif
#define SOC_TRNG_TEST_WIN_HEALTH_test_win_adaptive_proportion_START (0)
#define SOC_TRNG_TEST_WIN_HEALTH_test_win_adaptive_proportion_END (7)
#define SOC_TRNG_TEST_WIN_HEALTH_test_win_repetition_count_START (8)
#define SOC_TRNG_TEST_WIN_HEALTH_test_win_repetition_count_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thre_fail_num_adaptive_proportion : 8;
        unsigned int thre_fail_num_repetition_count : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_TRNG_THRE_FAIL_NUM_HEALTH_UNION;
#endif
#define SOC_TRNG_THRE_FAIL_NUM_HEALTH_thre_fail_num_adaptive_proportion_START (0)
#define SOC_TRNG_THRE_FAIL_NUM_HEALTH_thre_fail_num_adaptive_proportion_END (7)
#define SOC_TRNG_THRE_FAIL_NUM_HEALTH_thre_fail_num_repetition_count_START (8)
#define SOC_TRNG_THRE_FAIL_NUM_HEALTH_thre_fail_num_repetition_count_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fail_num_adaptive_proportion : 8;
        unsigned int fail_num_repetition_count : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_TRNG_FAIL_NUM_HEALTH_TEST_UNION;
#endif
#define SOC_TRNG_FAIL_NUM_HEALTH_TEST_fail_num_adaptive_proportion_START (0)
#define SOC_TRNG_FAIL_NUM_HEALTH_TEST_fail_num_adaptive_proportion_END (7)
#define SOC_TRNG_FAIL_NUM_HEALTH_TEST_fail_num_repetition_count_START (8)
#define SOC_TRNG_FAIL_NUM_HEALTH_TEST_fail_num_repetition_count_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clear_adaptive_proportion : 4;
        unsigned int clear_repetition_count : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_TRNG_HEALTH_TEST_CLEAR_UNION;
#endif
#define SOC_TRNG_HEALTH_TEST_CLEAR_clear_adaptive_proportion_START (0)
#define SOC_TRNG_HEALTH_TEST_CLEAR_clear_adaptive_proportion_END (3)
#define SOC_TRNG_HEALTH_TEST_CLEAR_clear_repetition_count_START (4)
#define SOC_TRNG_HEALTH_TEST_CLEAR_clear_repetition_count_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int msk_alarm_adaptive_proportion : 4;
        unsigned int msk_alarm_repetition_count : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_TRNG_MSK_ALARM_HEALTH_UNION;
#endif
#define SOC_TRNG_MSK_ALARM_HEALTH_msk_alarm_adaptive_proportion_START (0)
#define SOC_TRNG_MSK_ALARM_HEALTH_msk_alarm_adaptive_proportion_END (3)
#define SOC_TRNG_MSK_ALARM_HEALTH_msk_alarm_repetition_count_START (4)
#define SOC_TRNG_MSK_ALARM_HEALTH_msk_alarm_repetition_count_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_adaptive_proportion : 4;
        unsigned int alarm_repetition_count : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_TRNG_HEALTH_ALARM_STATE_UNION;
#endif
#define SOC_TRNG_HEALTH_ALARM_STATE_alarm_adaptive_proportion_START (0)
#define SOC_TRNG_HEALTH_ALARM_STATE_alarm_adaptive_proportion_END (3)
#define SOC_TRNG_HEALTH_ALARM_STATE_alarm_repetition_count_START (4)
#define SOC_TRNG_HEALTH_ALARM_STATE_alarm_repetition_count_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Known_answer_test_done : 4;
        unsigned int Known_answer_test_busy : 4;
        unsigned int Known_answer_test_start : 4;
        unsigned int Known_answer_test_out_cfg : 5;
        unsigned int Known_answer_test_genrnd_cfg : 4;
        unsigned int reserved : 11;
    } reg;
} SOC_TRNG_KNOWN_ANSWER_TEST_CPU_UNION;
#endif
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_done_START (0)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_done_END (3)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_busy_START (4)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_busy_END (7)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_start_START (8)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_start_END (11)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_out_cfg_START (12)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_out_cfg_END (16)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_genrnd_cfg_START (17)
#define SOC_TRNG_KNOWN_ANSWER_TEST_CPU_Known_answer_test_genrnd_cfg_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KAT_Entropy_input : 32;
    } reg;
} SOC_TRNG_KAT_ENTROPY_INPUT_UNION;
#endif
#define SOC_TRNG_KAT_ENTROPY_INPUT_KAT_Entropy_input_START (0)
#define SOC_TRNG_KAT_ENTROPY_INPUT_KAT_Entropy_input_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KAT_Entropy_input_pr1 : 32;
    } reg;
} SOC_TRNG_KAT_ENTROPY_INPUT_PR1_UNION;
#endif
#define SOC_TRNG_KAT_ENTROPY_INPUT_PR1_KAT_Entropy_input_pr1_START (0)
#define SOC_TRNG_KAT_ENTROPY_INPUT_PR1_KAT_Entropy_input_pr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KAT_Entropy_input_pr2 : 32;
    } reg;
} SOC_TRNG_KAT_ENTROPY_INPUT_PR2_UNION;
#endif
#define SOC_TRNG_KAT_ENTROPY_INPUT_PR2_KAT_Entropy_input_pr2_START (0)
#define SOC_TRNG_KAT_ENTROPY_INPUT_PR2_KAT_Entropy_input_pr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KAT_Nonce : 32;
    } reg;
} SOC_TRNG_KAT_NONCE_UNION;
#endif
#define SOC_TRNG_KAT_NONCE_KAT_Nonce_START (0)
#define SOC_TRNG_KAT_NONCE_KAT_Nonce_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KAT_Personalization_String : 32;
    } reg;
} SOC_TRNG_KAT_PERSONALIZATION_STRING_UNION;
#endif
#define SOC_TRNG_KAT_PERSONALIZATION_STRING_KAT_Personalization_String_START (0)
#define SOC_TRNG_KAT_PERSONALIZATION_STRING_KAT_Personalization_String_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KAT_Additional_Input1 : 32;
    } reg;
} SOC_TRNG_KAT_ADDITIONAL_INPUT1_UNION;
#endif
#define SOC_TRNG_KAT_ADDITIONAL_INPUT1_KAT_Additional_Input1_START (0)
#define SOC_TRNG_KAT_ADDITIONAL_INPUT1_KAT_Additional_Input1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KAT_Additional_Input2 : 32;
    } reg;
} SOC_TRNG_KAT_ADDITIONAL_INPUT2_UNION;
#endif
#define SOC_TRNG_KAT_ADDITIONAL_INPUT2_KAT_Additional_Input2_START (0)
#define SOC_TRNG_KAT_ADDITIONAL_INPUT2_KAT_Additional_Input2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Known_answer_test_result : 32;
    } reg;
} SOC_TRNG_KNOWN_ANSWER_TEST_RESULT_UNION;
#endif
#define SOC_TRNG_KNOWN_ANSWER_TEST_RESULT_Known_answer_test_result_START (0)
#define SOC_TRNG_KNOWN_ANSWER_TEST_RESULT_Known_answer_test_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ro_sample_en : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_TRNG_RO_SAMPLE_EN_UNION;
#endif
#define SOC_TRNG_RO_SAMPLE_EN_ro_sample_en_START (0)
#define SOC_TRNG_RO_SAMPLE_EN_ro_sample_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ro4_div_cfg : 6;
        unsigned int ro5_div_cfg : 6;
        unsigned int ro6_div_cfg : 6;
        unsigned int ro7_div_cfg : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_TRNG_RO_DIV_CFG1_UNION;
#endif
#define SOC_TRNG_RO_DIV_CFG1_ro4_div_cfg_START (0)
#define SOC_TRNG_RO_DIV_CFG1_ro4_div_cfg_END (5)
#define SOC_TRNG_RO_DIV_CFG1_ro5_div_cfg_START (6)
#define SOC_TRNG_RO_DIV_CFG1_ro5_div_cfg_END (11)
#define SOC_TRNG_RO_DIV_CFG1_ro6_div_cfg_START (12)
#define SOC_TRNG_RO_DIV_CFG1_ro6_div_cfg_END (17)
#define SOC_TRNG_RO_DIV_CFG1_ro7_div_cfg_START (18)
#define SOC_TRNG_RO_DIV_CFG1_ro7_div_cfg_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ro1_div_cfg : 6;
        unsigned int ro2_div_cfg : 6;
        unsigned int ro3_div_cfg : 6;
        unsigned int reserved : 14;
    } reg;
} SOC_TRNG_RO_DIV_CFG2_UNION;
#endif
#define SOC_TRNG_RO_DIV_CFG2_ro1_div_cfg_START (0)
#define SOC_TRNG_RO_DIV_CFG2_ro1_div_cfg_END (5)
#define SOC_TRNG_RO_DIV_CFG2_ro2_div_cfg_START (6)
#define SOC_TRNG_RO_DIV_CFG2_ro2_div_cfg_END (11)
#define SOC_TRNG_RO_DIV_CFG2_ro3_div_cfg_START (12)
#define SOC_TRNG_RO_DIV_CFG2_ro3_div_cfg_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ro_sample_sel : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_TRNG_RO_SAMPLE_SEL_UNION;
#endif
#define SOC_TRNG_RO_SAMPLE_SEL_ro_sample_sel_START (0)
#define SOC_TRNG_RO_SAMPLE_SEL_ro_sample_sel_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OTPC_TRNG_TRIM_0 : 32;
    } reg;
} SOC_TRNG_OTPC_TRNG_TRIM_0_UNION;
#endif
#define SOC_TRNG_OTPC_TRNG_TRIM_0_OTPC_TRNG_TRIM_0_START (0)
#define SOC_TRNG_OTPC_TRNG_TRIM_0_OTPC_TRNG_TRIM_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OTPC_TRNG_TRIM_1 : 32;
    } reg;
} SOC_TRNG_OTPC_TRNG_TRIM_1_UNION;
#endif
#define SOC_TRNG_OTPC_TRNG_TRIM_1_OTPC_TRNG_TRIM_1_START (0)
#define SOC_TRNG_OTPC_TRNG_TRIM_1_OTPC_TRNG_TRIM_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OTPC_TRNG_TRIM_2 : 32;
    } reg;
} SOC_TRNG_OTPC_TRNG_TRIM_2_UNION;
#endif
#define SOC_TRNG_OTPC_TRNG_TRIM_2_OTPC_TRNG_TRIM_2_START (0)
#define SOC_TRNG_OTPC_TRNG_TRIM_2_OTPC_TRNG_TRIM_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OTPC_TRNG_TRIM_3 : 32;
    } reg;
} SOC_TRNG_OTPC_TRNG_TRIM_3_UNION;
#endif
#define SOC_TRNG_OTPC_TRNG_TRIM_3_OTPC_TRNG_TRIM_3_START (0)
#define SOC_TRNG_OTPC_TRNG_TRIM_3_OTPC_TRNG_TRIM_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OTPC_TRNG_TRIM_CRC : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TRNG_OTPC_TRNG_TRIM_CRC_UNION;
#endif
#define SOC_TRNG_OTPC_TRNG_TRIM_CRC_OTPC_TRNG_TRIM_CRC_START (0)
#define SOC_TRNG_OTPC_TRNG_TRIM_CRC_OTPC_TRNG_TRIM_CRC_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int otpc_trng_tp_disable : 4;
        unsigned int otpc_trng_pre_test_en : 4;
        unsigned int otpc_hw_rd_finish : 4;
        unsigned int otpc_trng_entropy_sel : 4;
        unsigned int otpc_trng_sm3_sel : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_TRNG_OTPC_STATUS_1_UNION;
#endif
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_tp_disable_START (0)
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_tp_disable_END (3)
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_pre_test_en_START (4)
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_pre_test_en_END (7)
#define SOC_TRNG_OTPC_STATUS_1_otpc_hw_rd_finish_START (8)
#define SOC_TRNG_OTPC_STATUS_1_otpc_hw_rd_finish_END (11)
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_entropy_sel_START (12)
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_entropy_sel_END (15)
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_sm3_sel_START (16)
#define SOC_TRNG_OTPC_STATUS_1_otpc_trng_sm3_sel_END (19)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
