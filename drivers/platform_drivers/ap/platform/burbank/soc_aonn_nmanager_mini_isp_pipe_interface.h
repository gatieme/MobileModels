#ifndef __SOC_AONN_NMANAGER_MINI_ISP_PIPE_INTERFACE_H__
#define __SOC_AONN_NMANAGER_MINI_ISP_PIPE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_ADDR(base) ((base) + (0x0000UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_H_ADDR(base) ((base) + (0x0004UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_V_ADDR(base) ((base) + (0x0008UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_RB_ADDR(base) ((base) + (0x0014UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_G_ADDR(base) ((base) + (0x0018UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_ADDR(base) ((base) + (0x020UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_ADDR(base) ((base) + (0x024UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_ADDR(base) ((base) + (0x028UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_ADDR(base) ((base) + (0x02CUL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_01_ADDR(base) ((base) + (0x0030UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_23_ADDR(base) ((base) + (0x0034UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_45_ADDR(base) ((base) + (0x0038UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_67_ADDR(base) ((base) + (0x003CUL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_8_ADDR(base) ((base) + (0x0040UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_ADDR(base) ((base) + (0x0044UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_ADDR(base,Range21) ((base) + (0x0050+0x4*(Range21)))
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_ADDR(base) ((base) + (0x00D0UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_RB_ADDR(base) ((base) + (0x00E0UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_G_ADDR(base) ((base) + (0x00E4UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ADDR(base) ((base) + (0x00F0UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCH_ADDR(base) ((base) + (0x0100UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCV_ADDR(base) ((base) + (0x0104UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_LEFT_ADDR(base) ((base) + (0x0110UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_RIGHT_ADDR(base) ((base) + (0x0114UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_TOP_ADDR(base) ((base) + (0x0118UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_BOTTOM_ADDR(base) ((base) + (0x011CUL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_ADDR(base) ((base) + (0x0120UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_ADDR(base) ((base) + (0x0124UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 0_ADDR(base) ((base) + (0x0130UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 1_ADDR(base) ((base) + (0x0134UL))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_YSUM_ADDR(base,Range48) ((base) + (0x0140+0x4*(Range48)))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_SUM_COUNTER_ADDR(base,Range768) ((base) + (0x0200+0x4*(Range768)))
#else
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_ADDR(base) ((base) + (0x0000))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_H_ADDR(base) ((base) + (0x0004))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_V_ADDR(base) ((base) + (0x0008))
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_RB_ADDR(base) ((base) + (0x0014))
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_G_ADDR(base) ((base) + (0x0018))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_ADDR(base) ((base) + (0x020))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_ADDR(base) ((base) + (0x024))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_ADDR(base) ((base) + (0x028))
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_ADDR(base) ((base) + (0x02C))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_01_ADDR(base) ((base) + (0x0030))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_23_ADDR(base) ((base) + (0x0034))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_45_ADDR(base) ((base) + (0x0038))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_67_ADDR(base) ((base) + (0x003C))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_8_ADDR(base) ((base) + (0x0040))
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_ADDR(base) ((base) + (0x0044))
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_ADDR(base,Range21) ((base) + (0x0050+0x4*(Range21)))
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_ADDR(base) ((base) + (0x00D0))
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_RB_ADDR(base) ((base) + (0x00E0))
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_G_ADDR(base) ((base) + (0x00E4))
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ADDR(base) ((base) + (0x00F0))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCH_ADDR(base) ((base) + (0x0100))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCV_ADDR(base) ((base) + (0x0104))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_LEFT_ADDR(base) ((base) + (0x0110))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_RIGHT_ADDR(base) ((base) + (0x0114))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_TOP_ADDR(base) ((base) + (0x0118))
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_BOTTOM_ADDR(base) ((base) + (0x011C))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_ADDR(base) ((base) + (0x0120))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_ADDR(base) ((base) + (0x0124))
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 0_ADDR(base) ((base) + (0x0130))
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 1_ADDR(base) ((base) + (0x0134))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_YSUM_ADDR(base,Range48) ((base) + (0x0140+0x4*(Range48)))
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_SUM_COUNTER_ADDR(base,Range768) ((base) + (0x0200+0x4*(Range768)))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_en : 1;
        unsigned int ir_en : 1;
        unsigned int lsc_en : 1;
        unsigned int stat_awb_en : 1;
        unsigned int stat_en : 1;
        unsigned int awbgain_en : 1;
        unsigned int demosaic_en : 1;
        unsigned int cc_en : 1;
        unsigned int gamma_en : 1;
        unsigned int scl_en : 1;
        unsigned int ir_mode : 1;
        unsigned int mono_mode : 1;
        unsigned int bayer_pat : 2;
        unsigned int reserved : 18;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_blc_en_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_blc_en_END (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_ir_en_START (1)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_ir_en_END (1)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_lsc_en_START (2)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_lsc_en_END (2)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_stat_awb_en_START (3)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_stat_awb_en_END (3)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_stat_en_START (4)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_stat_en_END (4)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_awbgain_en_START (5)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_awbgain_en_END (5)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_demosaic_en_START (6)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_demosaic_en_END (6)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_cc_en_START (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_cc_en_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_gamma_en_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_gamma_en_END (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_scl_en_START (9)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_scl_en_END (9)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_ir_mode_START (10)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_ir_mode_END (10)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_mono_mode_START (11)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_mono_mode_END (11)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_bayer_pat_START (12)
#define SOC_AONN_nManager_MINI_ISP_PIPE_PIPE_CONFIG_bayer_pat_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_h : 11;
        unsigned int reserved_0: 5;
        unsigned int start_h : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CROP_H_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_H_end_h_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_H_end_h_END (10)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_H_start_h_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_H_start_h_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_v : 11;
        unsigned int reserved_0: 5;
        unsigned int start_v : 11;
        unsigned int reserved_1: 5;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CROP_V_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_V_end_v_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_V_end_v_END (10)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_V_start_v_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CROP_V_start_v_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_b_fixed : 9;
        unsigned int reserved_0 : 7;
        unsigned int blc_r_fixed : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_RB_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_RB_blc_b_fixed_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_RB_blc_b_fixed_END (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_RB_blc_r_fixed_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_RB_blc_r_fixed_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blc_gb_fixed : 9;
        unsigned int reserved_0 : 7;
        unsigned int blc_gr_fixed : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_G_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_G_blc_gb_fixed_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_G_blc_gb_fixed_END (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_G_blc_gr_fixed_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_BLC_FIX_G_blc_gr_fixed_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_curve_3 : 8;
        unsigned int gamma_curve_2 : 8;
        unsigned int gamma_curve_1 : 8;
        unsigned int gamma_curve_0 : 8;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_3_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_3_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_2_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_2_END (15)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_1_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_1_END (23)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_0_START (24)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G0_gamma_curve_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_curve_7 : 8;
        unsigned int gamma_curve_6 : 8;
        unsigned int gamma_curve_5 : 8;
        unsigned int gamma_curve_4 : 8;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_7_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_7_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_6_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_6_END (15)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_5_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_5_END (23)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_4_START (24)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G1_gamma_curve_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_curve_11 : 8;
        unsigned int gamma_curve_10 : 8;
        unsigned int gamma_curve_9 : 8;
        unsigned int gamma_curve_8 : 8;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_11_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_11_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_10_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_10_END (15)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_9_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_9_END (23)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_8_START (24)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G2_gamma_curve_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_curve_15 : 8;
        unsigned int gamma_curve_14 : 8;
        unsigned int gamma_curve_13 : 8;
        unsigned int gamma_curve_12 : 8;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_15_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_15_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_14_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_14_END (15)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_13_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_13_END (23)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_12_START (24)
#define SOC_AONN_nManager_MINI_ISP_PIPE_GAMMA_CURVE_G3_gamma_curve_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_mat_1 : 12;
        unsigned int reserved_0: 4;
        unsigned int cc_mat_0 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_01_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_01_cc_mat_1_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_01_cc_mat_1_END (11)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_01_cc_mat_0_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_01_cc_mat_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_mat_3 : 12;
        unsigned int reserved_0: 4;
        unsigned int cc_mat_2 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_23_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_23_cc_mat_3_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_23_cc_mat_3_END (11)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_23_cc_mat_2_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_23_cc_mat_2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_mat_5 : 12;
        unsigned int reserved_0: 4;
        unsigned int cc_mat_4 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_45_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_45_cc_mat_5_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_45_cc_mat_5_END (11)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_45_cc_mat_4_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_45_cc_mat_4_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_mat_7 : 12;
        unsigned int reserved_0: 4;
        unsigned int cc_mat_6 : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_67_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_67_cc_mat_7_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_67_cc_mat_7_END (11)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_67_cc_mat_6_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_67_cc_mat_6_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_mat_8 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_8_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_8_cc_mat_8_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_MAT_8_cc_mat_8_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cc_ofst_2 : 8;
        unsigned int cc_ofst_1 : 8;
        unsigned int cc_ofst_0 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_cc_ofst_2_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_cc_ofst_2_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_cc_ofst_1_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_cc_ofst_1_END (15)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_cc_ofst_0_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_CC_OFFSET_cc_ofst_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lscgain_b : 10;
        unsigned int lscgain_g : 10;
        unsigned int lscgain_r : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_lscgain_b_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_lscgain_b_END (9)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_lscgain_g_START (10)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_lscgain_g_END (19)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_lscgain_r_START (20)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_GAIN_lscgain_r_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cenx : 10;
        unsigned int reserved_0: 2;
        unsigned int ceny : 10;
        unsigned int reserved_1: 2;
        unsigned int shiftn : 4;
        unsigned int reserved_2: 4;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_cenx_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_cenx_END (9)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_ceny_START (12)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_ceny_END (21)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_shiftn_START (24)
#define SOC_AONN_nManager_MINI_ISP_PIPE_LSC_CEN_SHIFT_shiftn_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awbgain_b : 10;
        unsigned int reserved_0: 6;
        unsigned int awbgain_r : 10;
        unsigned int reserved_1: 6;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_RB_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_RB_awbgain_b_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_RB_awbgain_b_END (9)
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_RB_awbgain_r_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_RB_awbgain_r_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awbgain_gb : 10;
        unsigned int reserved_0 : 6;
        unsigned int awbgain_gr : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_G_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_G_awbgain_gb_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_G_awbgain_gb_END (9)
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_G_awbgain_gr_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_AWBGAIN_COEF_G_awbgain_gr_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ir_pos : 2;
        unsigned int ir_dir : 2;
        unsigned int ir_color_sel : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ir_pos_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ir_pos_END (1)
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ir_dir_START (2)
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ir_dir_END (3)
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ir_color_sel_START (4)
#define SOC_AONN_nManager_MINI_ISP_PIPE_IR_CFG_ir_color_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl_hinc : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCH_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCH_scl_hinc_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCH_scl_hinc_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl_vinc : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCV_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCV_scl_vinc_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_INCV_scl_vinc_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl_hleft : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_LEFT_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_LEFT_scl_hleft_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_LEFT_scl_hleft_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl_hright : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_RIGHT_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_RIGHT_scl_hright_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_RIGHT_scl_hright_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl_vtop : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_TOP_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_TOP_scl_vtop_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_TOP_scl_vtop_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl_vbottom : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_BOTTOM_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_BOTTOM_scl_vbottom_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_SCL_HCROP_BOTTOM_scl_vbottom_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_min_th : 8;
        unsigned int stat_max_th : 8;
        unsigned int stat_win_v : 7;
        unsigned int reserved_0 : 1;
        unsigned int stat_win_h : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_min_th_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_min_th_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_max_th_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_max_th_END (15)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_win_v_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_win_v_END (22)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_win_h_START (24)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_stat_win_h_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_mcoef : 8;
        unsigned int stat_bcoef : 8;
        unsigned int stat_gcoef : 8;
        unsigned int stat_rcoef : 8;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_mcoef_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_mcoef_END (7)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_bcoef_START (8)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_bcoef_END (15)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_gcoef_START (16)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_gcoef_END (23)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_rcoef_START (24)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_stat_rcoef_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug0 : 32;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 0_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 0_debug0_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 0_debug0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug1 : 32;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 1_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 1_debug1_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_DEBUG 1_debug1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_y_sum : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_YSUM_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_YSUM_stat_y_sum_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AE_YSUM_stat_y_sum_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_awb : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_SUM_COUNTER_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_SUM_COUNTER_stat_awb_START (0)
#define SOC_AONN_nManager_MINI_ISP_PIPE_STAT_AWB_SUM_COUNTER_stat_awb_END (19)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
