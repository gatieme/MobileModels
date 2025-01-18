#ifndef __SOC_DP_MISC_CTRL_INTERFACE_H__
#define __SOC_DP_MISC_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DP_MISC_CTRL_DPC_SEC_EN_ADDR(base) ((base) + (0x0000UL))
#define SOC_DP_MISC_CTRL_DPC_TP_SEL_ADDR(base) ((base) + (0x0100UL))
#define SOC_DP_MISC_CTRL_DPC_TP_OUT_ADDR(base) ((base) + (0x0104UL))
#define SOC_DP_MISC_CTRL_DPC_INTS_ADDR(base) ((base) + (0x010CUL))
#define SOC_DP_MISC_CTRL_DPC_INT_MSK_ADDR(base) ((base) + (0x0110UL))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W0_ADDR(base) ((base) + (0x0114UL))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W1_ADDR(base) ((base) + (0x0118UL))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R0_ADDR(base) ((base) + (0x011CUL))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R1_ADDR(base) ((base) + (0x0120UL))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R2_ADDR(base) ((base) + (0x0124UL))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R3_ADDR(base) ((base) + (0x0128UL))
#define SOC_DP_MISC_CTRL_DPC_Audio_CTRL_ADDR(base) ((base) + (0x012CUL))
#define SOC_DP_MISC_CTRL_DPC_MEM_CTRL_ADDR(base) ((base) + (0x0200UL))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL0_ADDR(base) ((base) + (0x0204UL))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL1_ADDR(base) ((base) + (0x0208UL))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL2_ADDR(base) ((base) + (0x020CUL))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL3_ADDR(base) ((base) + (0x0210UL))
#define SOC_DP_MISC_CTRL_HDCP22_KPF0_ADDR(base) ((base) + (0x0300UL))
#define SOC_DP_MISC_CTRL_HDCP22_KPF1_ADDR(base) ((base) + (0x0304UL))
#define SOC_DP_MISC_CTRL_HDCP22_KPF2_ADDR(base) ((base) + (0x0308UL))
#define SOC_DP_MISC_CTRL_HDCP22_KPF3_ADDR(base) ((base) + (0x030CUL))
#define SOC_DP_MISC_CTRL_HDCP22_DUK0_ADDR(base) ((base) + (0x0310UL))
#define SOC_DP_MISC_CTRL_HDCP22_DUK1_ADDR(base) ((base) + (0x0314UL))
#define SOC_DP_MISC_CTRL_HDCP22_DUK2_ADDR(base) ((base) + (0x0318UL))
#define SOC_DP_MISC_CTRL_HDCP22_DUK3_ADDR(base) ((base) + (0x031CUL))
#define SOC_DP_MISC_CTRL_HDCP22_DEVNUM_ADDR(base) ((base) + (0x0320UL))
#define SOC_DP_MISC_CTRL_HDCP22_ID_VLD_ADDR(base) ((base) + (0x0324UL))
#define SOC_DP_MISC_CTRL_HDCP22_FAMA_CTRL_ADDR(base) ((base) + (0x0328UL))
#define SOC_DP_MISC_CTRL_TRNG_TEST_SEL_ADDR(base) ((base) + (0x0400UL))
#define SOC_DP_MISC_CTRL_TRNG_TEST_MODE_ADDR(base) ((base) + (0x0404UL))
#define SOC_DP_MISC_CTRL_TRNG_TEST_TWEAK_MUX_ADDR(base) ((base) + (0x0408UL))
#define SOC_DP_MISC_CTRL_TRNG_TEST_TP_ADDR(base) ((base) + (0x040CUL))
#define SOC_DP_MISC_CTRL_HDCP22_CG_ADDR(base) ((base) + (0x0580UL))
#define SOC_DP_MISC_CTRL_TRNG_AXI_CG_ADDR(base) ((base) + (0x0584UL))
#else
#define SOC_DP_MISC_CTRL_DPC_SEC_EN_ADDR(base) ((base) + (0x0000))
#define SOC_DP_MISC_CTRL_DPC_TP_SEL_ADDR(base) ((base) + (0x0100))
#define SOC_DP_MISC_CTRL_DPC_TP_OUT_ADDR(base) ((base) + (0x0104))
#define SOC_DP_MISC_CTRL_DPC_INTS_ADDR(base) ((base) + (0x010C))
#define SOC_DP_MISC_CTRL_DPC_INT_MSK_ADDR(base) ((base) + (0x0110))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W0_ADDR(base) ((base) + (0x0114))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W1_ADDR(base) ((base) + (0x0118))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R0_ADDR(base) ((base) + (0x011C))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R1_ADDR(base) ((base) + (0x0120))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R2_ADDR(base) ((base) + (0x0124))
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R3_ADDR(base) ((base) + (0x0128))
#define SOC_DP_MISC_CTRL_DPC_Audio_CTRL_ADDR(base) ((base) + (0x012C))
#define SOC_DP_MISC_CTRL_DPC_MEM_CTRL_ADDR(base) ((base) + (0x0200))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL0_ADDR(base) ((base) + (0x0204))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL1_ADDR(base) ((base) + (0x0208))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL2_ADDR(base) ((base) + (0x020C))
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL3_ADDR(base) ((base) + (0x0210))
#define SOC_DP_MISC_CTRL_HDCP22_KPF0_ADDR(base) ((base) + (0x0300))
#define SOC_DP_MISC_CTRL_HDCP22_KPF1_ADDR(base) ((base) + (0x0304))
#define SOC_DP_MISC_CTRL_HDCP22_KPF2_ADDR(base) ((base) + (0x0308))
#define SOC_DP_MISC_CTRL_HDCP22_KPF3_ADDR(base) ((base) + (0x030C))
#define SOC_DP_MISC_CTRL_HDCP22_DUK0_ADDR(base) ((base) + (0x0310))
#define SOC_DP_MISC_CTRL_HDCP22_DUK1_ADDR(base) ((base) + (0x0314))
#define SOC_DP_MISC_CTRL_HDCP22_DUK2_ADDR(base) ((base) + (0x0318))
#define SOC_DP_MISC_CTRL_HDCP22_DUK3_ADDR(base) ((base) + (0x031C))
#define SOC_DP_MISC_CTRL_HDCP22_DEVNUM_ADDR(base) ((base) + (0x0320))
#define SOC_DP_MISC_CTRL_HDCP22_ID_VLD_ADDR(base) ((base) + (0x0324))
#define SOC_DP_MISC_CTRL_HDCP22_FAMA_CTRL_ADDR(base) ((base) + (0x0328))
#define SOC_DP_MISC_CTRL_TRNG_TEST_SEL_ADDR(base) ((base) + (0x0400))
#define SOC_DP_MISC_CTRL_TRNG_TEST_MODE_ADDR(base) ((base) + (0x0404))
#define SOC_DP_MISC_CTRL_TRNG_TEST_TWEAK_MUX_ADDR(base) ((base) + (0x0408))
#define SOC_DP_MISC_CTRL_TRNG_TEST_TP_ADDR(base) ((base) + (0x040C))
#define SOC_DP_MISC_CTRL_HDCP22_CG_ADDR(base) ((base) + (0x0580))
#define SOC_DP_MISC_CTRL_TRNG_AXI_CG_ADDR(base) ((base) + (0x0584))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_sec_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DP_MISC_CTRL_DPC_SEC_EN_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_SEC_EN_dpc_sec_en_START (0)
#define SOC_DP_MISC_CTRL_DPC_SEC_EN_dpc_sec_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_tp_sel : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DP_MISC_CTRL_DPC_TP_SEL_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_TP_SEL_dpc_tp_sel_START (0)
#define SOC_DP_MISC_CTRL_DPC_TP_SEL_dpc_tp_sel_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_tp_out : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DP_MISC_CTRL_DPC_TP_OUT_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_TP_OUT_dpc_tp_out_START (0)
#define SOC_DP_MISC_CTRL_DPC_TP_OUT_dpc_tp_out_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_ints : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DP_MISC_CTRL_DPC_INTS_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_INTS_dpc_ints_START (0)
#define SOC_DP_MISC_CTRL_DPC_INTS_dpc_ints_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_int_msk : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DP_MISC_CTRL_DPC_INT_MSK_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_INT_MSK_dpc_int_msk_START (0)
#define SOC_DP_MISC_CTRL_DPC_INT_MSK_dpc_int_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_debug_w0 : 32;
    } reg;
} SOC_DP_MISC_CTRL_DPC_DEBUG_W0_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W0_dpc_debug_w0_START (0)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W0_dpc_debug_w0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_debug_w1 : 32;
    } reg;
} SOC_DP_MISC_CTRL_DPC_DEBUG_W1_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W1_dpc_debug_w1_START (0)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_W1_dpc_debug_w1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int o_test_tp : 19;
        unsigned int dpc_debug_r0 : 13;
    } reg;
} SOC_DP_MISC_CTRL_DPC_DEBUG_R0_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R0_o_test_tp_START (0)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R0_o_test_tp_END (18)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R0_dpc_debug_r0_START (19)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R0_dpc_debug_r0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_debug_r1 : 32;
    } reg;
} SOC_DP_MISC_CTRL_DPC_DEBUG_R1_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R1_dpc_debug_r1_START (0)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R1_dpc_debug_r1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_debug_r2 : 32;
    } reg;
} SOC_DP_MISC_CTRL_DPC_DEBUG_R2_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R2_dpc_debug_r2_START (0)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R2_dpc_debug_r2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dpc_debug_r3 : 32;
    } reg;
} SOC_DP_MISC_CTRL_DPC_DEBUG_R3_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R3_dpc_debug_r3_START (0)
#define SOC_DP_MISC_CTRL_DPC_DEBUG_R3_dpc_debug_r3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_audio_mux : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DP_MISC_CTRL_DPC_Audio_CTRL_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_Audio_CTRL_sc_audio_mux_START (0)
#define SOC_DP_MISC_CTRL_DPC_Audio_CTRL_sc_audio_mux_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_dptx_mem_ctrl_pwr : 32;
    } reg;
} SOC_DP_MISC_CTRL_DPC_MEM_CTRL_UNION;
#endif
#define SOC_DP_MISC_CTRL_DPC_MEM_CTRL_sc_dptx_mem_ctrl_pwr_START (0)
#define SOC_DP_MISC_CTRL_DPC_MEM_CTRL_sc_dptx_mem_ctrl_pwr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_balance_l_mem_ctrl_pwr : 16;
        unsigned int sc_balance_h_mem_ctrl_pwr : 16;
    } reg;
} SOC_DP_MISC_CTRL_DSC_MEM_CTRL0_UNION;
#endif
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL0_sc_balance_l_mem_ctrl_pwr_START (0)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL0_sc_balance_l_mem_ctrl_pwr_END (15)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL0_sc_balance_h_mem_ctrl_pwr_START (16)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL0_sc_balance_h_mem_ctrl_pwr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_lb_ram_mem_ctrl_pwr : 16;
        unsigned int sc_se_size_ram_mem_ctrl_pwr : 16;
    } reg;
} SOC_DP_MISC_CTRL_DSC_MEM_CTRL1_UNION;
#endif
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL1_sc_lb_ram_mem_ctrl_pwr_START (0)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL1_sc_lb_ram_mem_ctrl_pwr_END (15)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL1_sc_se_size_ram_mem_ctrl_pwr_START (16)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL1_sc_se_size_ram_mem_ctrl_pwr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_rb_ram_mem_ctrl_pwr : 16;
        unsigned int sc_sd_ram_mem_ctrl_pwr : 16;
    } reg;
} SOC_DP_MISC_CTRL_DSC_MEM_CTRL2_UNION;
#endif
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL2_sc_rb_ram_mem_ctrl_pwr_START (0)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL2_sc_rb_ram_mem_ctrl_pwr_END (15)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL2_sc_sd_ram_mem_ctrl_pwr_START (16)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL2_sc_sd_ram_mem_ctrl_pwr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_lsteer_ram_mem_ctrl_pwr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DP_MISC_CTRL_DSC_MEM_CTRL3_UNION;
#endif
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL3_sc_lsteer_ram_mem_ctrl_pwr_START (0)
#define SOC_DP_MISC_CTRL_DSC_MEM_CTRL3_sc_lsteer_ram_mem_ctrl_pwr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_kpf0 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_KPF0_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_KPF0_hdcp22_kpf0_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_KPF0_hdcp22_kpf0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_kpf1 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_KPF1_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_KPF1_hdcp22_kpf1_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_KPF1_hdcp22_kpf1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_kpf2 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_KPF2_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_KPF2_hdcp22_kpf2_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_KPF2_hdcp22_kpf2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_kpf3 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_KPF3_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_KPF3_hdcp22_kpf3_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_KPF3_hdcp22_kpf3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_duk0 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_DUK0_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_DUK0_hdcp22_duk0_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_DUK0_hdcp22_duk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_duk1 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_DUK1_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_DUK1_hdcp22_duk1_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_DUK1_hdcp22_duk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_duk2 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_DUK2_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_DUK2_hdcp22_duk2_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_DUK2_hdcp22_duk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_duk3 : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_DUK3_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_DUK3_hdcp22_duk3_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_DUK3_hdcp22_duk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_devnum : 32;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_DEVNUM_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_DEVNUM_hdcp22_devnum_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_DEVNUM_hdcp22_devnum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_id_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_ID_VLD_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_ID_VLD_hdcp22_id_vld_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_ID_VLD_hdcp22_id_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp22_fama_araddr : 8;
        unsigned int reserved_0 : 8;
        unsigned int hdcp22_fama_awaddr : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_FAMA_CTRL_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_FAMA_CTRL_hdcp22_fama_araddr_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_FAMA_CTRL_hdcp22_fama_araddr_END (7)
#define SOC_DP_MISC_CTRL_HDCP22_FAMA_CTRL_hdcp22_fama_awaddr_START (16)
#define SOC_DP_MISC_CTRL_HDCP22_FAMA_CTRL_hdcp22_fama_awaddr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_test_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DP_MISC_CTRL_TRNG_TEST_SEL_UNION;
#endif
#define SOC_DP_MISC_CTRL_TRNG_TEST_SEL_trng_test_sel_START (0)
#define SOC_DP_MISC_CTRL_TRNG_TEST_SEL_trng_test_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_test_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DP_MISC_CTRL_TRNG_TEST_MODE_UNION;
#endif
#define SOC_DP_MISC_CTRL_TRNG_TEST_MODE_trng_test_mode_START (0)
#define SOC_DP_MISC_CTRL_TRNG_TEST_MODE_trng_test_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_test_tweak_mux : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_DP_MISC_CTRL_TRNG_TEST_TWEAK_MUX_UNION;
#endif
#define SOC_DP_MISC_CTRL_TRNG_TEST_TWEAK_MUX_trng_test_tweak_mux_START (0)
#define SOC_DP_MISC_CTRL_TRNG_TEST_TWEAK_MUX_trng_test_tweak_mux_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_test_tp : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_DP_MISC_CTRL_TRNG_TEST_TP_UNION;
#endif
#define SOC_DP_MISC_CTRL_TRNG_TEST_TP_trng_test_tp_START (0)
#define SOC_DP_MISC_CTRL_TRNG_TEST_TP_trng_test_tp_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdcp_clk_en : 1;
        unsigned int hdcp_clk_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DP_MISC_CTRL_HDCP22_CG_UNION;
#endif
#define SOC_DP_MISC_CTRL_HDCP22_CG_hdcp_clk_en_START (0)
#define SOC_DP_MISC_CTRL_HDCP22_CG_hdcp_clk_en_END (0)
#define SOC_DP_MISC_CTRL_HDCP22_CG_hdcp_clk_sel_START (1)
#define SOC_DP_MISC_CTRL_HDCP22_CG_hdcp_clk_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trng_axi_clk_en : 1;
        unsigned int trng_axi_clk_sel : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DP_MISC_CTRL_TRNG_AXI_CG_UNION;
#endif
#define SOC_DP_MISC_CTRL_TRNG_AXI_CG_trng_axi_clk_en_START (0)
#define SOC_DP_MISC_CTRL_TRNG_AXI_CG_trng_axi_clk_en_END (0)
#define SOC_DP_MISC_CTRL_TRNG_AXI_CG_trng_axi_clk_sel_START (1)
#define SOC_DP_MISC_CTRL_TRNG_AXI_CG_trng_axi_clk_sel_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
