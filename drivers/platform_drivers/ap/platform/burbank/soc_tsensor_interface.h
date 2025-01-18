#ifndef __SOC_TSENSOR_INTERFACE_H__
#define __SOC_TSENSOR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TSENSOR_CALIBRATION_ADDR(base,m) ((base) + (0x0000+0x100*(m)))
#define SOC_TSENSOR_TEMP_DET_EN_ADDR(base,m) ((base) + (0x0004+0x100*(m)))
#define SOC_TSENSOR_TEMP_CONFIG_ADDR(base,m) ((base) + (0x0008+0x100*(m)))
#define SOC_TSENSOR_TEMP_ADDR(base,m) ((base) + (0x000C+0x100*(m)))
#define SOC_TSENSOR_TSC_MODE_ADDR(base,m) ((base) + (0x0010+0x100*(m)))
#define SOC_TSENSOR_TEMP_ORIG_ADDR(base,m) ((base) + (0x0014+0x100*(m)))
#define SOC_TSENSOR_RST_TEMP_STAT_ADDR(base,m) ((base) + (0x0018+0x100*(m)))
#define SOC_TSENSOR_TEMP_HIGH_TH_ADDR(base,m) ((base) + (0x001C+0x100*(m)))
#define SOC_TSENSOR_TEMP_LOW_TH_ADDR(base,m) ((base) + (0x0020+0x100*(m)))
#define SOC_TSENSOR_TEMP_RST_TH_ADDR(base,m) ((base) + (0x0024+0x100*(m)))
#define SOC_TSENSOR_TEMP_LAG_ADDR(base,m) ((base) + (0x0028+0x100*(m)))
#define SOC_TSENSOR_TEMP_INT_MSK_ADDR(base,m) ((base) + (0x002C+0x100*(m)))
#define SOC_TSENSOR_TEMP_INT_CLR_ADDR(base,m) ((base) + (0x0030+0x100*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_H_ADDR(base,m) ((base) + (0x0034+0x100*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_H_ADDR(base,m) ((base) + (0x0038+0x100*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_L_ADDR(base,m) ((base) + (0x003C+0x100*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_L_ADDR(base,m) ((base) + (0x0040+0x100*(m)))
#define SOC_TSENSOR_TEMP_RST_MSK_ADDR(base,m) ((base) + (0x0044+0x100*(m)))
#define SOC_TSENSOR_TS_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0048+0x100*(m)))
#define SOC_TSENSOR_TS_EN2DIS_CLR_ADDR(base,m) ((base) + (0x004C+0x100*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0050+0x100*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ADDR(base,m) ((base) + (0x0054+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION1_ADDR(base,m) ((base) + (0x0058+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION2_ADDR(base,m) ((base) + (0x005C+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION3_ADDR(base,m) ((base) + (0x0060+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION4_ADDR(base,m) ((base) + (0x0064+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION5_ADDR(base,m) ((base) + (0x0068+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION6_ADDR(base,m) ((base) + (0x006C+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION7_ADDR(base,m) ((base) + (0x0070+0x100*(m)))
#define SOC_TSENSOR_TEMP01_ADDR(base,m) ((base) + (0x0080+0x100*(m)))
#define SOC_TSENSOR_TEMP23_ADDR(base,m) ((base) + (0x0084+0x100*(m)))
#define SOC_TSENSOR_TEMP45_ADDR(base,m) ((base) + (0x0088+0x100*(m)))
#define SOC_TSENSOR_TEMP67_ADDR(base,m) ((base) + (0x008C+0x100*(m)))
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_ADDR(base,m) ((base) + (0x0090+0x100*(m)))
#else
#define SOC_TSENSOR_CALIBRATION_ADDR(base,m) ((base) + (0x0000+0x100*(m)))
#define SOC_TSENSOR_TEMP_DET_EN_ADDR(base,m) ((base) + (0x0004+0x100*(m)))
#define SOC_TSENSOR_TEMP_CONFIG_ADDR(base,m) ((base) + (0x0008+0x100*(m)))
#define SOC_TSENSOR_TEMP_ADDR(base,m) ((base) + (0x000C+0x100*(m)))
#define SOC_TSENSOR_TSC_MODE_ADDR(base,m) ((base) + (0x0010+0x100*(m)))
#define SOC_TSENSOR_TEMP_ORIG_ADDR(base,m) ((base) + (0x0014+0x100*(m)))
#define SOC_TSENSOR_RST_TEMP_STAT_ADDR(base,m) ((base) + (0x0018+0x100*(m)))
#define SOC_TSENSOR_TEMP_HIGH_TH_ADDR(base,m) ((base) + (0x001C+0x100*(m)))
#define SOC_TSENSOR_TEMP_LOW_TH_ADDR(base,m) ((base) + (0x0020+0x100*(m)))
#define SOC_TSENSOR_TEMP_RST_TH_ADDR(base,m) ((base) + (0x0024+0x100*(m)))
#define SOC_TSENSOR_TEMP_LAG_ADDR(base,m) ((base) + (0x0028+0x100*(m)))
#define SOC_TSENSOR_TEMP_INT_MSK_ADDR(base,m) ((base) + (0x002C+0x100*(m)))
#define SOC_TSENSOR_TEMP_INT_CLR_ADDR(base,m) ((base) + (0x0030+0x100*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_H_ADDR(base,m) ((base) + (0x0034+0x100*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_H_ADDR(base,m) ((base) + (0x0038+0x100*(m)))
#define SOC_TSENSOR_TEMP_RAWINT_L_ADDR(base,m) ((base) + (0x003C+0x100*(m)))
#define SOC_TSENSOR_TEMP_MSKINT_L_ADDR(base,m) ((base) + (0x0040+0x100*(m)))
#define SOC_TSENSOR_TEMP_RST_MSK_ADDR(base,m) ((base) + (0x0044+0x100*(m)))
#define SOC_TSENSOR_TS_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0048+0x100*(m)))
#define SOC_TSENSOR_TS_EN2DIS_CLR_ADDR(base,m) ((base) + (0x004C+0x100*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ADDR(base,m) ((base) + (0x0050+0x100*(m)))
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ADDR(base,m) ((base) + (0x0054+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION1_ADDR(base,m) ((base) + (0x0058+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION2_ADDR(base,m) ((base) + (0x005C+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION3_ADDR(base,m) ((base) + (0x0060+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION4_ADDR(base,m) ((base) + (0x0064+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION5_ADDR(base,m) ((base) + (0x0068+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION6_ADDR(base,m) ((base) + (0x006C+0x100*(m)))
#define SOC_TSENSOR_CALIBRATION7_ADDR(base,m) ((base) + (0x0070+0x100*(m)))
#define SOC_TSENSOR_TEMP01_ADDR(base,m) ((base) + (0x0080+0x100*(m)))
#define SOC_TSENSOR_TEMP23_ADDR(base,m) ((base) + (0x0084+0x100*(m)))
#define SOC_TSENSOR_TEMP45_ADDR(base,m) ((base) + (0x0088+0x100*(m)))
#define SOC_TSENSOR_TEMP67_ADDR(base,m) ((base) + (0x008C+0x100*(m)))
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_ADDR(base,m) ((base) + (0x0090+0x100*(m)))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int local_sensorerror : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION_local_sensorerror_START (0)
#define SOC_TSENSOR_CALIBRATION_local_sensorerror_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_det_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_DET_EN_UNION;
#endif
#define SOC_TSENSOR_TEMP_DET_EN_temp_det_en_START (0)
#define SOC_TSENSOR_TEMP_DET_EN_temp_det_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_num : 8;
        unsigned int temp_clk_sel : 1;
        unsigned int temp_cfg : 16;
        unsigned int temp_ct_sel : 2;
        unsigned int temp_calib : 1;
        unsigned int temp_calib_vmode_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_TSENSOR_TEMP_CONFIG_UNION;
#endif
#define SOC_TSENSOR_TEMP_CONFIG_sample_num_START (0)
#define SOC_TSENSOR_TEMP_CONFIG_sample_num_END (7)
#define SOC_TSENSOR_TEMP_CONFIG_temp_clk_sel_START (8)
#define SOC_TSENSOR_TEMP_CONFIG_temp_clk_sel_END (8)
#define SOC_TSENSOR_TEMP_CONFIG_temp_cfg_START (9)
#define SOC_TSENSOR_TEMP_CONFIG_temp_cfg_END (24)
#define SOC_TSENSOR_TEMP_CONFIG_temp_ct_sel_START (25)
#define SOC_TSENSOR_TEMP_CONFIG_temp_ct_sel_END (26)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_START (27)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_END (27)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_vmode_en_START (28)
#define SOC_TSENSOR_TEMP_CONFIG_temp_calib_vmode_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp : 16;
        unsigned int temp_num : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_TSENSOR_TEMP_UNION;
#endif
#define SOC_TSENSOR_TEMP_temp_START (0)
#define SOC_TSENSOR_TEMP_temp_END (15)
#define SOC_TSENSOR_TEMP_temp_num_START (16)
#define SOC_TSENSOR_TEMP_temp_num_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_det_mode : 1;
        unsigned int temp_remote_softsel : 3;
        unsigned int tsensor_num : 4;
        unsigned int disable_delay : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TSC_MODE_UNION;
#endif
#define SOC_TSENSOR_TSC_MODE_temp_det_mode_START (0)
#define SOC_TSENSOR_TSC_MODE_temp_det_mode_END (0)
#define SOC_TSENSOR_TSC_MODE_temp_remote_softsel_START (1)
#define SOC_TSENSOR_TSC_MODE_temp_remote_softsel_END (3)
#define SOC_TSENSOR_TSC_MODE_tsensor_num_START (4)
#define SOC_TSENSOR_TSC_MODE_tsensor_num_END (7)
#define SOC_TSENSOR_TSC_MODE_disable_delay_START (8)
#define SOC_TSENSOR_TSC_MODE_disable_delay_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_orig : 16;
        unsigned int temp_num_orig : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_TSENSOR_TEMP_ORIG_UNION;
#endif
#define SOC_TSENSOR_TEMP_ORIG_temp_orig_START (0)
#define SOC_TSENSOR_TEMP_ORIG_temp_orig_END (15)
#define SOC_TSENSOR_TEMP_ORIG_temp_num_orig_START (16)
#define SOC_TSENSOR_TEMP_ORIG_temp_num_orig_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_tempstat : 16;
        unsigned int rst_remote_sel_stat : 3;
        unsigned int reserved : 13;
    } reg;
} SOC_TSENSOR_RST_TEMP_STAT_UNION;
#endif
#define SOC_TSENSOR_RST_TEMP_STAT_rst_tempstat_START (0)
#define SOC_TSENSOR_RST_TEMP_STAT_rst_tempstat_END (15)
#define SOC_TSENSOR_RST_TEMP_STAT_rst_remote_sel_stat_START (16)
#define SOC_TSENSOR_RST_TEMP_STAT_rst_remote_sel_stat_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TEMP_HIGH_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_HIGH_TH_temp_th_START (0)
#define SOC_TSENSOR_TEMP_HIGH_TH_temp_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_low_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TEMP_LOW_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_LOW_TH_temp_low_th_START (0)
#define SOC_TSENSOR_TEMP_LOW_TH_temp_low_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rst_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_TSENSOR_TEMP_RST_TH_UNION;
#endif
#define SOC_TSENSOR_TEMP_RST_TH_temp_rst_th_START (0)
#define SOC_TSENSOR_TEMP_RST_TH_temp_rst_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_lag : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_TSENSOR_TEMP_LAG_UNION;
#endif
#define SOC_TSENSOR_TEMP_LAG_temp_lag_START (0)
#define SOC_TSENSOR_TEMP_LAG_temp_lag_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_int_msk0 : 1;
        unsigned int temp_int_msk1 : 1;
        unsigned int temp_int_msk2 : 1;
        unsigned int temp_int_msk3 : 1;
        unsigned int temp_int_msk4 : 1;
        unsigned int temp_int_msk5 : 1;
        unsigned int temp_int_msk6 : 1;
        unsigned int temp_int_msk7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_INT_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk0_START (0)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk0_END (0)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk1_START (1)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk1_END (1)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk2_START (2)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk2_END (2)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk3_START (3)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk3_END (3)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk4_START (4)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk4_END (4)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk5_START (5)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk5_END (5)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk6_START (6)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk6_END (6)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk7_START (7)
#define SOC_TSENSOR_TEMP_INT_MSK_temp_int_msk7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_int_clr0 : 1;
        unsigned int temp_int_clr1 : 1;
        unsigned int temp_int_clr2 : 1;
        unsigned int temp_int_clr3 : 1;
        unsigned int temp_int_clr4 : 1;
        unsigned int temp_int_clr5 : 1;
        unsigned int temp_int_clr6 : 1;
        unsigned int temp_int_clr7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_INT_CLR_UNION;
#endif
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr0_START (0)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr0_END (0)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr1_START (1)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr1_END (1)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr2_START (2)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr2_END (2)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr3_START (3)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr3_END (3)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr4_START (4)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr4_END (4)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr5_START (5)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr5_END (5)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr6_START (6)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr6_END (6)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr7_START (7)
#define SOC_TSENSOR_TEMP_INT_CLR_temp_int_clr7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rawint_h0 : 1;
        unsigned int temp_rawint_h1 : 1;
        unsigned int temp_rawint_h2 : 1;
        unsigned int temp_rawint_h3 : 1;
        unsigned int temp_rawint_h4 : 1;
        unsigned int temp_rawint_h5 : 1;
        unsigned int temp_rawint_h6 : 1;
        unsigned int temp_rawint_h7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_RAWINT_H_UNION;
#endif
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h0_START (0)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h0_END (0)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h1_START (1)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h1_END (1)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h2_START (2)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h2_END (2)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h3_START (3)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h3_END (3)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h4_START (4)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h4_END (4)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h5_START (5)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h5_END (5)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h6_START (6)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h6_END (6)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h7_START (7)
#define SOC_TSENSOR_TEMP_RAWINT_H_temp_rawint_h7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_mskint_h0 : 1;
        unsigned int temp_mskint_h1 : 1;
        unsigned int temp_mskint_h2 : 1;
        unsigned int temp_mskint_h3 : 1;
        unsigned int temp_mskint_h4 : 1;
        unsigned int temp_mskint_h5 : 1;
        unsigned int temp_mskint_h6 : 1;
        unsigned int temp_mskint_h7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_MSKINT_H_UNION;
#endif
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h0_START (0)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h0_END (0)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h1_START (1)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h1_END (1)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h2_START (2)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h2_END (2)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h3_START (3)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h3_END (3)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h4_START (4)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h4_END (4)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h5_START (5)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h5_END (5)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h6_START (6)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h6_END (6)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h7_START (7)
#define SOC_TSENSOR_TEMP_MSKINT_H_temp_mskint_h7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rawint_l0 : 1;
        unsigned int temp_rawint_l1 : 1;
        unsigned int temp_rawint_l2 : 1;
        unsigned int temp_rawint_l3 : 1;
        unsigned int temp_rawint_l4 : 1;
        unsigned int temp_rawint_l5 : 1;
        unsigned int temp_rawint_l6 : 1;
        unsigned int temp_rawint_l7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_RAWINT_L_UNION;
#endif
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l0_START (0)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l0_END (0)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l1_START (1)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l1_END (1)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l2_START (2)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l2_END (2)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l3_START (3)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l3_END (3)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l4_START (4)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l4_END (4)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l5_START (5)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l5_END (5)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l6_START (6)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l6_END (6)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l7_START (7)
#define SOC_TSENSOR_TEMP_RAWINT_L_temp_rawint_l7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_mskint_l0 : 1;
        unsigned int temp_mskint_l1 : 1;
        unsigned int temp_mskint_l2 : 1;
        unsigned int temp_mskint_l3 : 1;
        unsigned int temp_mskint_l4 : 1;
        unsigned int temp_mskint_l5 : 1;
        unsigned int temp_mskint_l6 : 1;
        unsigned int temp_mskint_l7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_TEMP_MSKINT_L_UNION;
#endif
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l0_START (0)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l0_END (0)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l1_START (1)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l1_END (1)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l2_START (2)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l2_END (2)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l3_START (3)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l3_END (3)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l4_START (4)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l4_END (4)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l5_START (5)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l5_END (5)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l6_START (6)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l6_END (6)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l7_START (7)
#define SOC_TSENSOR_TEMP_MSKINT_L_temp_mskint_l7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_rst_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TEMP_RST_MSK_UNION;
#endif
#define SOC_TSENSOR_TEMP_RST_MSK_temp_rst_msk_START (0)
#define SOC_TSENSOR_TEMP_RST_MSK_temp_rst_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_sensor_en2dis_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TS_EN2DIS_MSK_UNION;
#endif
#define SOC_TSENSOR_TS_EN2DIS_MSK_t_sensor_en2dis_msk_START (0)
#define SOC_TSENSOR_TS_EN2DIS_MSK_t_sensor_en2dis_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int t_sensor_en2dis_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TS_EN2DIS_CLR_UNION;
#endif
#define SOC_TSENSOR_TS_EN2DIS_CLR_t_sensor_en2dis_clr_START (0)
#define SOC_TSENSOR_TS_EN2DIS_CLR_t_sensor_en2dis_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_ctrl_en2dis_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TSC_EN2DIS_MSK_UNION;
#endif
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ts_ctrl_en2dis_msk_START (0)
#define SOC_TSENSOR_TSC_EN2DIS_MSK_ts_ctrl_en2dis_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_ctrl_en2dis_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_TSENSOR_TSC_EN2DIS_CLR_UNION;
#endif
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ts_ctrl_en2dis_clr_START (0)
#define SOC_TSENSOR_TSC_EN2DIS_CLR_ts_ctrl_en2dis_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensorerror1 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION1_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION1_remote_sensorerror1_START (0)
#define SOC_TSENSOR_CALIBRATION1_remote_sensorerror1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensorerror2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION2_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION2_remote_sensorerror2_START (0)
#define SOC_TSENSOR_CALIBRATION2_remote_sensorerror2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensorerror3 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION3_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION3_remote_sensorerror3_START (0)
#define SOC_TSENSOR_CALIBRATION3_remote_sensorerror3_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensorerror4 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION4_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION4_remote_sensorerror4_START (0)
#define SOC_TSENSOR_CALIBRATION4_remote_sensorerror4_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensorerror5 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION5_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION5_remote_sensorerror5_START (0)
#define SOC_TSENSOR_CALIBRATION5_remote_sensorerror5_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensorerror6 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION6_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION6_remote_sensorerror6_START (0)
#define SOC_TSENSOR_CALIBRATION6_remote_sensorerror6_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_sensorerror7 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_TSENSOR_CALIBRATION7_UNION;
#endif
#define SOC_TSENSOR_CALIBRATION7_remote_sensorerror7_START (0)
#define SOC_TSENSOR_CALIBRATION7_remote_sensorerror7_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp0 : 16;
        unsigned int temp1 : 16;
    } reg;
} SOC_TSENSOR_TEMP01_UNION;
#endif
#define SOC_TSENSOR_TEMP01_temp0_START (0)
#define SOC_TSENSOR_TEMP01_temp0_END (15)
#define SOC_TSENSOR_TEMP01_temp1_START (16)
#define SOC_TSENSOR_TEMP01_temp1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp2 : 16;
        unsigned int temp3 : 16;
    } reg;
} SOC_TSENSOR_TEMP23_UNION;
#endif
#define SOC_TSENSOR_TEMP23_temp2_START (0)
#define SOC_TSENSOR_TEMP23_temp2_END (15)
#define SOC_TSENSOR_TEMP23_temp3_START (16)
#define SOC_TSENSOR_TEMP23_temp3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp4 : 16;
        unsigned int temp5 : 16;
    } reg;
} SOC_TSENSOR_TEMP45_UNION;
#endif
#define SOC_TSENSOR_TEMP45_temp4_START (0)
#define SOC_TSENSOR_TEMP45_temp4_END (15)
#define SOC_TSENSOR_TEMP45_temp5_START (16)
#define SOC_TSENSOR_TEMP45_temp5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp6 : 16;
        unsigned int temp7 : 16;
    } reg;
} SOC_TSENSOR_TEMP67_UNION;
#endif
#define SOC_TSENSOR_TEMP67_temp6_START (0)
#define SOC_TSENSOR_TEMP67_temp6_END (15)
#define SOC_TSENSOR_TEMP67_temp7_START (16)
#define SOC_TSENSOR_TEMP67_temp7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int remote_bypass0 : 1;
        unsigned int remote_bypass1 : 1;
        unsigned int remote_bypass2 : 1;
        unsigned int remote_bypass3 : 1;
        unsigned int remote_bypass4 : 1;
        unsigned int remote_bypass5 : 1;
        unsigned int remote_bypass6 : 1;
        unsigned int remote_bypass7 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_TSENSOR_REMOTE_FAIL_FLAG_UNION;
#endif
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass0_START (0)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass0_END (0)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass1_START (1)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass1_END (1)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass2_START (2)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass2_END (2)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass3_START (3)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass3_END (3)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass4_START (4)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass4_END (4)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass5_START (5)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass5_END (5)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass6_START (6)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass6_END (6)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass7_START (7)
#define SOC_TSENSOR_REMOTE_FAIL_FLAG_remote_bypass7_END (7)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
