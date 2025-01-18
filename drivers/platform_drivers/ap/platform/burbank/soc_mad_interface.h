#ifndef __SOC_MAD_INTERFACE_H__
#define __SOC_MAD_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MAD_VERSION_ADDR(base) ((base) + (0x0000UL))
#define SOC_MAD_AW_DLOCK_ADDR(base) ((base) + (0x0004UL))
#define SOC_MAD_FIFO_EMPTY_ADDR(base) ((base) + (0x0008UL))
#define SOC_MAD_DSPIF_DEBUG_ADDR(base) ((base) + (0x000CUL))
#define SOC_MAD_CLK_EN_ADDR(base) ((base) + (0x001CUL))
#define SOC_MAD_SRC_CTRL_ADDR(base) ((base) + (0x0020UL))
#define SOC_MAD_CTRL_ADDR(base) ((base) + (0x0024UL))
#define SOC_MAD_AUTO_ACT_TIME_ADDR(base) ((base) + (0x0028UL))
#define SOC_MAD_ANA_TIME_ADDR(base) ((base) + (0x002CUL))
#define SOC_MAD_PLL_TIME_ADDR(base) ((base) + (0x0030UL))
#define SOC_MAD_ADC_TIME_ADDR(base) ((base) + (0x0034UL))
#define SOC_MAD_OMIT_SAMP_ADDR(base) ((base) + (0x0038UL))
#define SOC_MAD_VAD_NUM_ADDR(base) ((base) + (0x003CUL))
#define SOC_MAD_VAD_TIME_ADDR(base) ((base) + (0x0040UL))
#define SOC_MAD_SLEEP_TIME_ADDR(base) ((base) + (0x0044UL))
#define SOC_MAD_ANA_EN_BPCLTRL_ADDR(base) ((base) + (0x0048UL))
#define SOC_MAD_ALPHA_PREP_ADDR(base) ((base) + (0x004CUL))
#define SOC_MAD_ALPHA1_ADDR(base) ((base) + (0x0050UL))
#define SOC_MAD_ALPHA2_ADDR(base) ((base) + (0x0054UL))
#define SOC_MAD_ALPHA3_ADDR(base) ((base) + (0x0058UL))
#define SOC_MAD_MIN_CHAN_ENG_ADDR(base) ((base) + (0x005CUL))
#define SOC_MAD_IFRAME_ADDR(base) ((base) + (0x0060UL))
#define SOC_MAD_INE_ADDR(base) ((base) + (0x0064UL))
#define SOC_MAD_SNR_THRE_ADDR(base) ((base) + (0x0068UL))
#define SOC_MAD_BAND_THRE_ADDR(base) ((base) + (0x006CUL))
#define SOC_MAD_SNR_THRE_SUM_ADDR(base) ((base) + (0x0070UL))
#define SOC_MAD_SNR_MIN_ADDR(base) ((base) + (0x0074UL))
#define SOC_MAD_SCALE_ADDR(base) ((base) + (0x0078UL))
#define SOC_MAD_CNT_THRE_ADDR(base) ((base) + (0x007CUL))
#define SOC_MAD_SI_CTRL_ADDR(base) ((base) + (0x0080UL))
#define SOC_MAD_TH_SIFRAME_ADDR(base) ((base) + (0x0084UL))
#define SOC_MAD_BUFFER_CTRL_ADDR(base) ((base) + (0x0088UL))
#define SOC_MAD_MUX_SEL_ADDR(base) ((base) + (0x008CUL))
#define SOC_MAD_ADC_CTRL_ADDR(base) ((base) + (0x0090UL))
#define SOC_MAD_SIF_6144K_CTRL_ADDR(base) ((base) + (0x0094UL))
#define SOC_MAD_MEMORY_CTRL_ADDR(base) ((base) + (0x0098UL))
#define SOC_MAD_DMIC_CTRL_ADDR(base) ((base) + (0x009CUL))
#define SOC_MAD_DMIC_DIV_ADDR(base) ((base) + (0x00A0UL))
#define SOC_MAD_CLK_DIV_ADDR(base) ((base) + (0x00A4UL))
#define SOC_MAD_DEBUG_ADDR(base) ((base) + (0x00A8UL))
#define SOC_MAD_BUS_PRIORITY_ADDR(base) ((base) + (0x00ACUL))
#define SOC_MAD_MEM_CTRL_S_ADDR(base) ((base) + (0x00B0UL))
#define SOC_MAD_BUF_FIFO_CNT_ADDR(base) ((base) + (0x00B4UL))
#define SOC_MAD_DSP_IF_THRE_ADDR(base) ((base) + (0x00B8UL))
#define SOC_MAD_HPF_DC_GAIN_ADDR(base) ((base) + (0x00BCUL))
#define SOC_MAD_DMA_REQ_MASK_ADDR(base) ((base) + (0x00C0UL))
#define SOC_MAD_DSP_IF_THRE2_ADDR(base) ((base) + (0x00C4UL))
#define SOC_MAD_INT_CHECK_ADDR(base) ((base) + (0x00C8UL))
#define SOC_MAD_TZPC_ADDR(base) ((base) + (0x00CCUL))
#define SOC_MAD_CIC_CLK_SEL_ADDR(base) ((base) + (0x00D0UL))
#define SOC_MAD_CIC_DIV_NUM_ADDR(base) ((base) + (0x00D4UL))
#define SOC_MAD_DATA_DIN_SEL_ADDR(base) ((base) + (0x00D8UL))
#define SOC_MAD_SRCDN_12288K__CTRL_ADDR(base) ((base) + (0x00DCUL))
#define SOC_MAD_BM_SRCDN_12288K_WIND_SEL_ADDR(base) ((base) + (0x00E0UL))
#define SOC_MAD_HPF_768K_CTRL_ADDR(base) ((base) + (0x00E4UL))
#define SOC_MAD_PGA_CTRL_ADDR(base) ((base) + (0x00E8UL))
#define SOC_MAD_PGA_GAIN_OFFSET_ADDR(base) ((base) + (0x00ECUL))
#define SOC_MAD_PGA_THRE_CTRL0_ADDR(base) ((base) + (0x00F0UL))
#define SOC_MAD_PGA_THRE_CTRL1_ADDR(base) ((base) + (0x00F4UL))
#define SOC_MAD_PGA_THRE_CTRL2_ADDR(base) ((base) + (0x00F8UL))
#define SOC_MAD_PGA_DIN_DEL_ADDR(base) ((base) + (0x00FCUL))
#define SOC_MAD_AUTO_CLK_GATE_ADDR(base) ((base) + (0x0100UL))
#define SOC_MAD_HUB_SEL_ADDR(base) ((base) + (0x0104UL))
#define SOC_MAD_DLOCK_AVOID_ADDR(base) ((base) + (0x0108UL))
#define SOC_MAD_TC_SECURE_N_ADDR(base) ((base) + (0x010CUL))
#define SOC_MAD_CLKEN_SEC_ADDR(base) ((base) + (0x0110UL))
#else
#define SOC_MAD_VERSION_ADDR(base) ((base) + (0x0000))
#define SOC_MAD_AW_DLOCK_ADDR(base) ((base) + (0x0004))
#define SOC_MAD_FIFO_EMPTY_ADDR(base) ((base) + (0x0008))
#define SOC_MAD_DSPIF_DEBUG_ADDR(base) ((base) + (0x000C))
#define SOC_MAD_CLK_EN_ADDR(base) ((base) + (0x001C))
#define SOC_MAD_SRC_CTRL_ADDR(base) ((base) + (0x0020))
#define SOC_MAD_CTRL_ADDR(base) ((base) + (0x0024))
#define SOC_MAD_AUTO_ACT_TIME_ADDR(base) ((base) + (0x0028))
#define SOC_MAD_ANA_TIME_ADDR(base) ((base) + (0x002C))
#define SOC_MAD_PLL_TIME_ADDR(base) ((base) + (0x0030))
#define SOC_MAD_ADC_TIME_ADDR(base) ((base) + (0x0034))
#define SOC_MAD_OMIT_SAMP_ADDR(base) ((base) + (0x0038))
#define SOC_MAD_VAD_NUM_ADDR(base) ((base) + (0x003C))
#define SOC_MAD_VAD_TIME_ADDR(base) ((base) + (0x0040))
#define SOC_MAD_SLEEP_TIME_ADDR(base) ((base) + (0x0044))
#define SOC_MAD_ANA_EN_BPCLTRL_ADDR(base) ((base) + (0x0048))
#define SOC_MAD_ALPHA_PREP_ADDR(base) ((base) + (0x004C))
#define SOC_MAD_ALPHA1_ADDR(base) ((base) + (0x0050))
#define SOC_MAD_ALPHA2_ADDR(base) ((base) + (0x0054))
#define SOC_MAD_ALPHA3_ADDR(base) ((base) + (0x0058))
#define SOC_MAD_MIN_CHAN_ENG_ADDR(base) ((base) + (0x005C))
#define SOC_MAD_IFRAME_ADDR(base) ((base) + (0x0060))
#define SOC_MAD_INE_ADDR(base) ((base) + (0x0064))
#define SOC_MAD_SNR_THRE_ADDR(base) ((base) + (0x0068))
#define SOC_MAD_BAND_THRE_ADDR(base) ((base) + (0x006C))
#define SOC_MAD_SNR_THRE_SUM_ADDR(base) ((base) + (0x0070))
#define SOC_MAD_SNR_MIN_ADDR(base) ((base) + (0x0074))
#define SOC_MAD_SCALE_ADDR(base) ((base) + (0x0078))
#define SOC_MAD_CNT_THRE_ADDR(base) ((base) + (0x007C))
#define SOC_MAD_SI_CTRL_ADDR(base) ((base) + (0x0080))
#define SOC_MAD_TH_SIFRAME_ADDR(base) ((base) + (0x0084))
#define SOC_MAD_BUFFER_CTRL_ADDR(base) ((base) + (0x0088))
#define SOC_MAD_MUX_SEL_ADDR(base) ((base) + (0x008C))
#define SOC_MAD_ADC_CTRL_ADDR(base) ((base) + (0x0090))
#define SOC_MAD_SIF_6144K_CTRL_ADDR(base) ((base) + (0x0094))
#define SOC_MAD_MEMORY_CTRL_ADDR(base) ((base) + (0x0098))
#define SOC_MAD_DMIC_CTRL_ADDR(base) ((base) + (0x009C))
#define SOC_MAD_DMIC_DIV_ADDR(base) ((base) + (0x00A0))
#define SOC_MAD_CLK_DIV_ADDR(base) ((base) + (0x00A4))
#define SOC_MAD_DEBUG_ADDR(base) ((base) + (0x00A8))
#define SOC_MAD_BUS_PRIORITY_ADDR(base) ((base) + (0x00AC))
#define SOC_MAD_MEM_CTRL_S_ADDR(base) ((base) + (0x00B0))
#define SOC_MAD_BUF_FIFO_CNT_ADDR(base) ((base) + (0x00B4))
#define SOC_MAD_DSP_IF_THRE_ADDR(base) ((base) + (0x00B8))
#define SOC_MAD_HPF_DC_GAIN_ADDR(base) ((base) + (0x00BC))
#define SOC_MAD_DMA_REQ_MASK_ADDR(base) ((base) + (0x00C0))
#define SOC_MAD_DSP_IF_THRE2_ADDR(base) ((base) + (0x00C4))
#define SOC_MAD_INT_CHECK_ADDR(base) ((base) + (0x00C8))
#define SOC_MAD_TZPC_ADDR(base) ((base) + (0x00CC))
#define SOC_MAD_CIC_CLK_SEL_ADDR(base) ((base) + (0x00D0))
#define SOC_MAD_CIC_DIV_NUM_ADDR(base) ((base) + (0x00D4))
#define SOC_MAD_DATA_DIN_SEL_ADDR(base) ((base) + (0x00D8))
#define SOC_MAD_SRCDN_12288K__CTRL_ADDR(base) ((base) + (0x00DC))
#define SOC_MAD_BM_SRCDN_12288K_WIND_SEL_ADDR(base) ((base) + (0x00E0))
#define SOC_MAD_HPF_768K_CTRL_ADDR(base) ((base) + (0x00E4))
#define SOC_MAD_PGA_CTRL_ADDR(base) ((base) + (0x00E8))
#define SOC_MAD_PGA_GAIN_OFFSET_ADDR(base) ((base) + (0x00EC))
#define SOC_MAD_PGA_THRE_CTRL0_ADDR(base) ((base) + (0x00F0))
#define SOC_MAD_PGA_THRE_CTRL1_ADDR(base) ((base) + (0x00F4))
#define SOC_MAD_PGA_THRE_CTRL2_ADDR(base) ((base) + (0x00F8))
#define SOC_MAD_PGA_DIN_DEL_ADDR(base) ((base) + (0x00FC))
#define SOC_MAD_AUTO_CLK_GATE_ADDR(base) ((base) + (0x0100))
#define SOC_MAD_HUB_SEL_ADDR(base) ((base) + (0x0104))
#define SOC_MAD_DLOCK_AVOID_ADDR(base) ((base) + (0x0108))
#define SOC_MAD_TC_SECURE_N_ADDR(base) ((base) + (0x010C))
#define SOC_MAD_CLKEN_SEC_ADDR(base) ((base) + (0x0110))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int version : 32;
    } reg;
} SOC_MAD_VERSION_UNION;
#endif
#define SOC_MAD_VERSION_version_START (0)
#define SOC_MAD_VERSION_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dlock_mst : 1;
        unsigned int dlock_slv : 2;
        unsigned int dlock_id : 4;
        unsigned int dlock_wr : 1;
        unsigned int dlock_irq : 1;
        unsigned int dw_axi_m1_st : 1;
        unsigned int dw_axi_s1_st : 1;
        unsigned int dw_axi_s2_st : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_MAD_AW_DLOCK_UNION;
#endif
#define SOC_MAD_AW_DLOCK_dlock_mst_START (0)
#define SOC_MAD_AW_DLOCK_dlock_mst_END (0)
#define SOC_MAD_AW_DLOCK_dlock_slv_START (1)
#define SOC_MAD_AW_DLOCK_dlock_slv_END (2)
#define SOC_MAD_AW_DLOCK_dlock_id_START (3)
#define SOC_MAD_AW_DLOCK_dlock_id_END (6)
#define SOC_MAD_AW_DLOCK_dlock_wr_START (7)
#define SOC_MAD_AW_DLOCK_dlock_wr_END (7)
#define SOC_MAD_AW_DLOCK_dlock_irq_START (8)
#define SOC_MAD_AW_DLOCK_dlock_irq_END (8)
#define SOC_MAD_AW_DLOCK_dw_axi_m1_st_START (9)
#define SOC_MAD_AW_DLOCK_dw_axi_m1_st_END (9)
#define SOC_MAD_AW_DLOCK_dw_axi_s1_st_START (10)
#define SOC_MAD_AW_DLOCK_dw_axi_s1_st_END (10)
#define SOC_MAD_AW_DLOCK_dw_axi_s2_st_START (11)
#define SOC_MAD_AW_DLOCK_dw_axi_s2_st_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_fifo_empty : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MAD_FIFO_EMPTY_UNION;
#endif
#define SOC_MAD_FIFO_EMPTY_mad_fifo_empty_START (0)
#define SOC_MAD_FIFO_EMPTY_mad_fifo_empty_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dspif_debug : 32;
    } reg;
} SOC_MAD_DSPIF_DEBUG_UNION;
#endif
#define SOC_MAD_DSPIF_DEBUG_dspif_debug_START (0)
#define SOC_MAD_DSPIF_DEBUG_dspif_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_buffer_clken : 1;
        unsigned int mad_src_dn_clken : 1;
        unsigned int mad_adc_filer_clken : 1;
        unsigned int mad_cic_clken : 1;
        unsigned int mad_dmic_clken : 1;
        unsigned int mad_sif_6144k_clken : 1;
        unsigned int mad_dspif_clken : 1;
        unsigned int mad_clken : 1;
        unsigned int mad_dspif_clken1 : 1;
        unsigned int mad_dspif_clken2 : 1;
        unsigned int srcdn_12288k_clken : 1;
        unsigned int hpf_768k_clken : 1;
        unsigned int pga_clken : 1;
        unsigned int timer_clken : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MAD_CLK_EN_UNION;
#endif
#define SOC_MAD_CLK_EN_mad_buffer_clken_START (0)
#define SOC_MAD_CLK_EN_mad_buffer_clken_END (0)
#define SOC_MAD_CLK_EN_mad_src_dn_clken_START (1)
#define SOC_MAD_CLK_EN_mad_src_dn_clken_END (1)
#define SOC_MAD_CLK_EN_mad_adc_filer_clken_START (2)
#define SOC_MAD_CLK_EN_mad_adc_filer_clken_END (2)
#define SOC_MAD_CLK_EN_mad_cic_clken_START (3)
#define SOC_MAD_CLK_EN_mad_cic_clken_END (3)
#define SOC_MAD_CLK_EN_mad_dmic_clken_START (4)
#define SOC_MAD_CLK_EN_mad_dmic_clken_END (4)
#define SOC_MAD_CLK_EN_mad_sif_6144k_clken_START (5)
#define SOC_MAD_CLK_EN_mad_sif_6144k_clken_END (5)
#define SOC_MAD_CLK_EN_mad_dspif_clken_START (6)
#define SOC_MAD_CLK_EN_mad_dspif_clken_END (6)
#define SOC_MAD_CLK_EN_mad_clken_START (7)
#define SOC_MAD_CLK_EN_mad_clken_END (7)
#define SOC_MAD_CLK_EN_mad_dspif_clken1_START (8)
#define SOC_MAD_CLK_EN_mad_dspif_clken1_END (8)
#define SOC_MAD_CLK_EN_mad_dspif_clken2_START (9)
#define SOC_MAD_CLK_EN_mad_dspif_clken2_END (9)
#define SOC_MAD_CLK_EN_srcdn_12288k_clken_START (10)
#define SOC_MAD_CLK_EN_srcdn_12288k_clken_END (10)
#define SOC_MAD_CLK_EN_hpf_768k_clken_START (11)
#define SOC_MAD_CLK_EN_hpf_768k_clken_END (11)
#define SOC_MAD_CLK_EN_pga_clken_START (12)
#define SOC_MAD_CLK_EN_pga_clken_END (12)
#define SOC_MAD_CLK_EN_timer_clken_START (13)
#define SOC_MAD_CLK_EN_timer_clken_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_srcdn_sft_cfg : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MAD_SRC_CTRL_UNION;
#endif
#define SOC_MAD_SRC_CTRL_mad_srcdn_sft_cfg_START (0)
#define SOC_MAD_SRC_CTRL_mad_srcdn_sft_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_en : 1;
        unsigned int mad_wind_sel : 3;
        unsigned int mad_int_en : 1;
        unsigned int mad_vad_ao : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MAD_CTRL_UNION;
#endif
#define SOC_MAD_CTRL_mad_en_START (0)
#define SOC_MAD_CTRL_mad_en_END (0)
#define SOC_MAD_CTRL_mad_wind_sel_START (1)
#define SOC_MAD_CTRL_mad_wind_sel_END (3)
#define SOC_MAD_CTRL_mad_int_en_START (4)
#define SOC_MAD_CTRL_mad_int_en_END (4)
#define SOC_MAD_CTRL_mad_vad_ao_START (5)
#define SOC_MAD_CTRL_mad_vad_ao_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_auto_act_time : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MAD_AUTO_ACT_TIME_UNION;
#endif
#define SOC_MAD_AUTO_ACT_TIME_mad_auto_act_time_START (0)
#define SOC_MAD_AUTO_ACT_TIME_mad_auto_act_time_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_ana_time : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MAD_ANA_TIME_UNION;
#endif
#define SOC_MAD_ANA_TIME_mad_ana_time_START (0)
#define SOC_MAD_ANA_TIME_mad_ana_time_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_pll_time : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MAD_PLL_TIME_UNION;
#endif
#define SOC_MAD_PLL_TIME_mad_pll_time_START (0)
#define SOC_MAD_PLL_TIME_mad_pll_time_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_adc_time : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MAD_ADC_TIME_UNION;
#endif
#define SOC_MAD_ADC_TIME_mad_adc_time_START (0)
#define SOC_MAD_ADC_TIME_mad_adc_time_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_omit_samp : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_OMIT_SAMP_UNION;
#endif
#define SOC_MAD_OMIT_SAMP_mad_omit_samp_START (0)
#define SOC_MAD_OMIT_SAMP_mad_omit_samp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_vad_num : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_VAD_NUM_UNION;
#endif
#define SOC_MAD_VAD_NUM_mad_vad_num_START (0)
#define SOC_MAD_VAD_NUM_mad_vad_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_vad_time : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MAD_VAD_TIME_UNION;
#endif
#define SOC_MAD_VAD_TIME_mad_vad_time_START (0)
#define SOC_MAD_VAD_TIME_mad_vad_time_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_sleep_time : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MAD_SLEEP_TIME_UNION;
#endif
#define SOC_MAD_SLEEP_TIME_mad_sleep_time_START (0)
#define SOC_MAD_SLEEP_TIME_mad_sleep_time_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_ana_en_bpctrl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_ANA_EN_BPCLTRL_UNION;
#endif
#define SOC_MAD_ANA_EN_BPCLTRL_mad_ana_en_bpctrl_START (0)
#define SOC_MAD_ANA_EN_BPCLTRL_mad_ana_en_bpctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_alpha_prep : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MAD_ALPHA_PREP_UNION;
#endif
#define SOC_MAD_ALPHA_PREP_mad_alpha_prep_START (0)
#define SOC_MAD_ALPHA_PREP_mad_alpha_prep_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_alpha1 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MAD_ALPHA1_UNION;
#endif
#define SOC_MAD_ALPHA1_mad_alpha1_START (0)
#define SOC_MAD_ALPHA1_mad_alpha1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_alpha2 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MAD_ALPHA2_UNION;
#endif
#define SOC_MAD_ALPHA2_mad_alpha2_START (0)
#define SOC_MAD_ALPHA2_mad_alpha2_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_alpha3 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_MAD_ALPHA3_UNION;
#endif
#define SOC_MAD_ALPHA3_mad_alpha3_START (0)
#define SOC_MAD_ALPHA3_mad_alpha3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_min_chan_eng : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_MIN_CHAN_ENG_UNION;
#endif
#define SOC_MAD_MIN_CHAN_ENG_mad_min_chan_eng_START (0)
#define SOC_MAD_MIN_CHAN_ENG_mad_min_chan_eng_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_lframe : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MAD_IFRAME_UNION;
#endif
#define SOC_MAD_IFRAME_mad_lframe_START (0)
#define SOC_MAD_IFRAME_mad_lframe_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_ine : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_INE_UNION;
#endif
#define SOC_MAD_INE_mad_ine_START (0)
#define SOC_MAD_INE_mad_ine_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_snr_thre : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_MAD_SNR_THRE_UNION;
#endif
#define SOC_MAD_SNR_THRE_mad_snr_thre_START (0)
#define SOC_MAD_SNR_THRE_mad_snr_thre_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_band_thre : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MAD_BAND_THRE_UNION;
#endif
#define SOC_MAD_BAND_THRE_mad_band_thre_START (0)
#define SOC_MAD_BAND_THRE_mad_band_thre_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_snr_thre_sum : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_SNR_THRE_SUM_UNION;
#endif
#define SOC_MAD_SNR_THRE_SUM_mad_snr_thre_sum_START (0)
#define SOC_MAD_SNR_THRE_SUM_mad_snr_thre_sum_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_snr_min : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_MAD_SNR_MIN_UNION;
#endif
#define SOC_MAD_SNR_MIN_mad_snr_min_START (0)
#define SOC_MAD_SNR_MIN_mad_snr_min_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_scale : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MAD_SCALE_UNION;
#endif
#define SOC_MAD_SCALE_mad_scale_START (0)
#define SOC_MAD_SCALE_mad_scale_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_cnt_thre : 6;
        unsigned int reserved_0 : 2;
        unsigned int mad_alpha_en1 : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_MAD_CNT_THRE_UNION;
#endif
#define SOC_MAD_CNT_THRE_mad_cnt_thre_START (0)
#define SOC_MAD_CNT_THRE_mad_cnt_thre_END (5)
#define SOC_MAD_CNT_THRE_mad_alpha_en1_START (8)
#define SOC_MAD_CNT_THRE_mad_alpha_en1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_si_bypass : 1;
        unsigned int reserved_0 : 3;
        unsigned int mad_si_alpha : 4;
        unsigned int mad_si_frame : 4;
        unsigned int reserved_1 : 4;
        unsigned int mad_si_thre_h : 8;
        unsigned int mad_si_thre_l : 8;
    } reg;
} SOC_MAD_SI_CTRL_UNION;
#endif
#define SOC_MAD_SI_CTRL_mad_si_bypass_START (0)
#define SOC_MAD_SI_CTRL_mad_si_bypass_END (0)
#define SOC_MAD_SI_CTRL_mad_si_alpha_START (4)
#define SOC_MAD_SI_CTRL_mad_si_alpha_END (7)
#define SOC_MAD_SI_CTRL_mad_si_frame_START (8)
#define SOC_MAD_SI_CTRL_mad_si_frame_END (11)
#define SOC_MAD_SI_CTRL_mad_si_thre_h_START (16)
#define SOC_MAD_SI_CTRL_mad_si_thre_h_END (23)
#define SOC_MAD_SI_CTRL_mad_si_thre_l_START (24)
#define SOC_MAD_SI_CTRL_mad_si_thre_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_si_thre_sum : 8;
        unsigned int mad_lp_mode : 2;
        unsigned int reserved : 22;
    } reg;
} SOC_MAD_TH_SIFRAME_UNION;
#endif
#define SOC_MAD_TH_SIFRAME_mad_si_thre_sum_START (0)
#define SOC_MAD_TH_SIFRAME_mad_si_thre_sum_END (7)
#define SOC_MAD_TH_SIFRAME_mad_lp_mode_START (8)
#define SOC_MAD_TH_SIFRAME_mad_lp_mode_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_buf_fifo_thre : 13;
        unsigned int mad_buf_en : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MAD_BUFFER_CTRL_UNION;
#endif
#define SOC_MAD_BUFFER_CTRL_mad_buf_fifo_thre_START (0)
#define SOC_MAD_BUFFER_CTRL_mad_buf_fifo_thre_END (12)
#define SOC_MAD_BUFFER_CTRL_mad_buf_en_START (13)
#define SOC_MAD_BUFFER_CTRL_mad_buf_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_adc_din_sel : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_MAD_MUX_SEL_UNION;
#endif
#define SOC_MAD_MUX_SEL_mad_adc_din_sel_START (0)
#define SOC_MAD_MUX_SEL_mad_adc_din_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adc_hpf_bypass_en : 1;
        unsigned int adc_hbfvd_bypass_en : 1;
        unsigned int adc_hbf2d_bypass_en : 1;
        unsigned int adc_compd_bypass_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int adc_cic_gain : 6;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_MAD_ADC_CTRL_UNION;
#endif
#define SOC_MAD_ADC_CTRL_adc_hpf_bypass_en_START (0)
#define SOC_MAD_ADC_CTRL_adc_hpf_bypass_en_END (0)
#define SOC_MAD_ADC_CTRL_adc_hbfvd_bypass_en_START (1)
#define SOC_MAD_ADC_CTRL_adc_hbfvd_bypass_en_END (1)
#define SOC_MAD_ADC_CTRL_adc_hbf2d_bypass_en_START (2)
#define SOC_MAD_ADC_CTRL_adc_hbf2d_bypass_en_END (2)
#define SOC_MAD_ADC_CTRL_adc_compd_bypass_en_START (3)
#define SOC_MAD_ADC_CTRL_adc_compd_bypass_en_END (3)
#define SOC_MAD_ADC_CTRL_adc_cic_gain_START (6)
#define SOC_MAD_ADC_CTRL_adc_cic_gain_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sif_6144k_adc_edge_sel : 1;
        unsigned int sif_6144k_adc_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MAD_SIF_6144K_CTRL_UNION;
#endif
#define SOC_MAD_SIF_6144K_CTRL_sif_6144k_adc_edge_sel_START (0)
#define SOC_MAD_SIF_6144K_CTRL_sif_6144k_adc_edge_sel_END (0)
#define SOC_MAD_SIF_6144K_CTRL_sif_6144k_adc_en_START (1)
#define SOC_MAD_SIF_6144K_CTRL_sif_6144k_adc_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MAD_MEMORY_CTRL_UNION;
#endif
#define SOC_MAD_MEMORY_CTRL_mem_ctrl_d1w2r_START (0)
#define SOC_MAD_MEMORY_CTRL_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmic_sw_dmic_mode : 1;
        unsigned int dmic_reverse : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MAD_DMIC_CTRL_UNION;
#endif
#define SOC_MAD_DMIC_CTRL_dmic_sw_dmic_mode_START (0)
#define SOC_MAD_DMIC_CTRL_dmic_sw_dmic_mode_END (0)
#define SOC_MAD_DMIC_CTRL_dmic_reverse_START (1)
#define SOC_MAD_DMIC_CTRL_dmic_reverse_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fs_dmic : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MAD_DMIC_DIV_UNION;
#endif
#define SOC_MAD_DMIC_DIV_fs_dmic_START (0)
#define SOC_MAD_DMIC_DIV_fs_dmic_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_clk_div_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MAD_CLK_DIV_UNION;
#endif
#define SOC_MAD_CLK_DIV_mad_clk_div_num_START (0)
#define SOC_MAD_CLK_DIV_mad_clk_div_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_debug : 32;
    } reg;
} SOC_MAD_DEBUG_UNION;
#endif
#define SOC_MAD_DEBUG_mad_debug_START (0)
#define SOC_MAD_DEBUG_mad_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_priority_m1 : 1;
        unsigned int slv_priority_s1 : 2;
        unsigned int slv_priority_s2 : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_MAD_BUS_PRIORITY_UNION;
#endif
#define SOC_MAD_BUS_PRIORITY_mst_priority_m1_START (0)
#define SOC_MAD_BUS_PRIORITY_mst_priority_m1_END (0)
#define SOC_MAD_BUS_PRIORITY_slv_priority_s1_START (1)
#define SOC_MAD_BUS_PRIORITY_slv_priority_s1_END (2)
#define SOC_MAD_BUS_PRIORITY_slv_priority_s2_START (3)
#define SOC_MAD_BUS_PRIORITY_slv_priority_s2_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_MAD_MEM_CTRL_S_UNION;
#endif
#define SOC_MAD_MEM_CTRL_S_mem_ctrl_s_START (0)
#define SOC_MAD_MEM_CTRL_S_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_buf_fifo_cnt : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MAD_BUF_FIFO_CNT_UNION;
#endif
#define SOC_MAD_BUF_FIFO_CNT_mad_buf_fifo_cnt_START (0)
#define SOC_MAD_BUF_FIFO_CNT_mad_buf_fifo_cnt_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dspif_thre_up : 4;
        unsigned int dspif_thre_dn : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_DSP_IF_THRE_UNION;
#endif
#define SOC_MAD_DSP_IF_THRE_dspif_thre_up_START (0)
#define SOC_MAD_DSP_IF_THRE_dspif_thre_up_END (3)
#define SOC_MAD_DSP_IF_THRE_dspif_thre_dn_START (4)
#define SOC_MAD_DSP_IF_THRE_dspif_thre_dn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpf_dc_gain : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_MAD_HPF_DC_GAIN_UNION;
#endif
#define SOC_MAD_HPF_DC_GAIN_hpf_dc_gain_START (0)
#define SOC_MAD_HPF_DC_GAIN_hpf_dc_gain_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_req_up_audio_mask : 1;
        unsigned int dma_req_up_dnn_mask : 1;
        unsigned int time_int_mask : 1;
        unsigned int mad_int_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MAD_DMA_REQ_MASK_UNION;
#endif
#define SOC_MAD_DMA_REQ_MASK_dma_req_up_audio_mask_START (0)
#define SOC_MAD_DMA_REQ_MASK_dma_req_up_audio_mask_END (0)
#define SOC_MAD_DMA_REQ_MASK_dma_req_up_dnn_mask_START (1)
#define SOC_MAD_DMA_REQ_MASK_dma_req_up_dnn_mask_END (1)
#define SOC_MAD_DMA_REQ_MASK_time_int_mask_START (2)
#define SOC_MAD_DMA_REQ_MASK_time_int_mask_END (2)
#define SOC_MAD_DMA_REQ_MASK_mad_int_mask_START (3)
#define SOC_MAD_DMA_REQ_MASK_mad_int_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dspif2_thre_up : 4;
        unsigned int dspif2_thre_dn : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_DSP_IF_THRE2_UNION;
#endif
#define SOC_MAD_DSP_IF_THRE2_dspif2_thre_up_START (0)
#define SOC_MAD_DSP_IF_THRE2_dspif2_thre_up_END (3)
#define SOC_MAD_DSP_IF_THRE2_dspif2_thre_dn_START (4)
#define SOC_MAD_DSP_IF_THRE2_dspif2_thre_dn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_int : 1;
        unsigned int timer_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MAD_INT_CHECK_UNION;
#endif
#define SOC_MAD_INT_CHECK_mad_int_START (0)
#define SOC_MAD_INT_CHECK_mad_int_END (0)
#define SOC_MAD_INT_CHECK_timer_int_START (1)
#define SOC_MAD_INT_CHECK_timer_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dspif_tzpc : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MAD_TZPC_UNION;
#endif
#define SOC_MAD_TZPC_dspif_tzpc_START (0)
#define SOC_MAD_TZPC_dspif_tzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cic_clk_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MAD_CIC_CLK_SEL_UNION;
#endif
#define SOC_MAD_CIC_CLK_SEL_cic_clk_sel_START (0)
#define SOC_MAD_CIC_CLK_SEL_cic_clk_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cic_div_num : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MAD_CIC_DIV_NUM_UNION;
#endif
#define SOC_MAD_CIC_DIV_NUM_cic_div_num_START (0)
#define SOC_MAD_CIC_DIV_NUM_cic_div_num_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mad_data_din_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MAD_DATA_DIN_SEL_UNION;
#endif
#define SOC_MAD_DATA_DIN_SEL_mad_data_din_sel_START (0)
#define SOC_MAD_DATA_DIN_SEL_mad_data_din_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srcdn_12288k_fifo_clr : 1;
        unsigned int srcdn_12288k_mode : 3;
        unsigned int reserved : 28;
    } reg;
} SOC_MAD_SRCDN_12288K__CTRL_UNION;
#endif
#define SOC_MAD_SRCDN_12288K__CTRL_srcdn_12288k_fifo_clr_START (0)
#define SOC_MAD_SRCDN_12288K__CTRL_srcdn_12288k_fifo_clr_END (0)
#define SOC_MAD_SRCDN_12288K__CTRL_srcdn_12288k_mode_START (1)
#define SOC_MAD_SRCDN_12288K__CTRL_srcdn_12288k_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bm_srcdn_12288k_wind_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MAD_BM_SRCDN_12288K_WIND_SEL_UNION;
#endif
#define SOC_MAD_BM_SRCDN_12288K_WIND_SEL_bm_srcdn_12288k_wind_sel_START (0)
#define SOC_MAD_BM_SRCDN_12288K_WIND_SEL_bm_srcdn_12288k_wind_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpf_768k_bypass_en : 1;
        unsigned int hpf_768k_dc : 24;
        unsigned int reserved : 7;
    } reg;
} SOC_MAD_HPF_768K_CTRL_UNION;
#endif
#define SOC_MAD_HPF_768K_CTRL_hpf_768k_bypass_en_START (0)
#define SOC_MAD_HPF_768K_CTRL_hpf_768k_bypass_en_END (0)
#define SOC_MAD_HPF_768K_CTRL_hpf_768k_dc_START (1)
#define SOC_MAD_HPF_768K_CTRL_hpf_768k_dc_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int adc_up_pga_linear_sel : 1;
        unsigned int adc_up_pga_zero_num : 5;
        unsigned int adc_up_pga_thre_id : 2;
        unsigned int adc_up_pga_noise_en : 1;
        unsigned int adc_up_pga_bypass : 1;
        unsigned int adc_up_pga_fade_out : 5;
        unsigned int adc_up_pga_fade_in : 5;
        unsigned int adc_up_pga_cfg : 3;
        unsigned int adc_up_pga_gain : 8;
    } reg;
} SOC_MAD_PGA_CTRL_UNION;
#endif
#define SOC_MAD_PGA_CTRL_adc_up_pga_linear_sel_START (1)
#define SOC_MAD_PGA_CTRL_adc_up_pga_linear_sel_END (1)
#define SOC_MAD_PGA_CTRL_adc_up_pga_zero_num_START (2)
#define SOC_MAD_PGA_CTRL_adc_up_pga_zero_num_END (6)
#define SOC_MAD_PGA_CTRL_adc_up_pga_thre_id_START (7)
#define SOC_MAD_PGA_CTRL_adc_up_pga_thre_id_END (8)
#define SOC_MAD_PGA_CTRL_adc_up_pga_noise_en_START (9)
#define SOC_MAD_PGA_CTRL_adc_up_pga_noise_en_END (9)
#define SOC_MAD_PGA_CTRL_adc_up_pga_bypass_START (10)
#define SOC_MAD_PGA_CTRL_adc_up_pga_bypass_END (10)
#define SOC_MAD_PGA_CTRL_adc_up_pga_fade_out_START (11)
#define SOC_MAD_PGA_CTRL_adc_up_pga_fade_out_END (15)
#define SOC_MAD_PGA_CTRL_adc_up_pga_fade_in_START (16)
#define SOC_MAD_PGA_CTRL_adc_up_pga_fade_in_END (20)
#define SOC_MAD_PGA_CTRL_adc_up_pga_cfg_START (21)
#define SOC_MAD_PGA_CTRL_adc_up_pga_cfg_END (23)
#define SOC_MAD_PGA_CTRL_adc_up_pga_gain_START (24)
#define SOC_MAD_PGA_CTRL_adc_up_pga_gain_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_gain_offset : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MAD_PGA_GAIN_OFFSET_UNION;
#endif
#define SOC_MAD_PGA_GAIN_OFFSET_pga_gain_offset_START (0)
#define SOC_MAD_PGA_GAIN_OFFSET_pga_gain_offset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_thre_ctrl0 : 32;
    } reg;
} SOC_MAD_PGA_THRE_CTRL0_UNION;
#endif
#define SOC_MAD_PGA_THRE_CTRL0_pga_thre_ctrl0_START (0)
#define SOC_MAD_PGA_THRE_CTRL0_pga_thre_ctrl0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_thre_ctrl1 : 32;
    } reg;
} SOC_MAD_PGA_THRE_CTRL1_UNION;
#endif
#define SOC_MAD_PGA_THRE_CTRL1_pga_thre_ctrl1_START (0)
#define SOC_MAD_PGA_THRE_CTRL1_pga_thre_ctrl1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_thre_ctrl2 : 32;
    } reg;
} SOC_MAD_PGA_THRE_CTRL2_UNION;
#endif
#define SOC_MAD_PGA_THRE_CTRL2_pga_thre_ctrl2_START (0)
#define SOC_MAD_PGA_THRE_CTRL2_pga_thre_ctrl2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pga_din__sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MAD_PGA_DIN_DEL_UNION;
#endif
#define SOC_MAD_PGA_DIN_DEL_pga_din__sel_START (0)
#define SOC_MAD_PGA_DIN_DEL_pga_din__sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_m1_cg_en : 1;
        unsigned int axi_s0_cg_en : 1;
        unsigned int axi_s1_cg_en : 1;
        unsigned int axi_s2_cg_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MAD_AUTO_CLK_GATE_UNION;
#endif
#define SOC_MAD_AUTO_CLK_GATE_axi_m1_cg_en_START (0)
#define SOC_MAD_AUTO_CLK_GATE_axi_m1_cg_en_END (0)
#define SOC_MAD_AUTO_CLK_GATE_axi_s0_cg_en_START (1)
#define SOC_MAD_AUTO_CLK_GATE_axi_s0_cg_en_END (1)
#define SOC_MAD_AUTO_CLK_GATE_axi_s1_cg_en_START (2)
#define SOC_MAD_AUTO_CLK_GATE_axi_s1_cg_en_END (2)
#define SOC_MAD_AUTO_CLK_GATE_axi_s2_cg_en_START (3)
#define SOC_MAD_AUTO_CLK_GATE_axi_s2_cg_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hub_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MAD_HUB_SEL_UNION;
#endif
#define SOC_MAD_HUB_SEL_hub_sel_START (0)
#define SOC_MAD_HUB_SEL_hub_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dlock_bp_timer : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MAD_DLOCK_AVOID_UNION;
#endif
#define SOC_MAD_DLOCK_AVOID_dlock_bp_timer_START (0)
#define SOC_MAD_DLOCK_AVOID_dlock_bp_timer_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tc_secure_n : 1;
        unsigned int tc_secure_reg : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MAD_TC_SECURE_N_UNION;
#endif
#define SOC_MAD_TC_SECURE_N_tc_secure_n_START (0)
#define SOC_MAD_TC_SECURE_N_tc_secure_n_END (0)
#define SOC_MAD_TC_SECURE_N_tc_secure_reg_START (1)
#define SOC_MAD_TC_SECURE_N_tc_secure_reg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clken_sec : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MAD_CLKEN_SEC_UNION;
#endif
#define SOC_MAD_CLKEN_SEC_clken_sec_START (0)
#define SOC_MAD_CLKEN_SEC_clken_sec_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
