#ifndef __SOC_MEDIA2_CRG_INTERFACE_H__
#define __SOC_MEDIA2_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MEDIA2_CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_MEDIA2_CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_MEDIA2_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_MEDIA2_CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_MEDIA2_CRG_PERRSTEN0_ADDR(base) ((base) + (0x030UL))
#define SOC_MEDIA2_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x034UL))
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x160UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x164UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x168UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x16cUL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ADDR(base) ((base) + (0x170UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_ADDR(base) ((base) + (0x174UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_ADDR(base) ((base) + (0x178UL))
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D0UL))
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D4UL))
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x1D8UL))
#define SOC_MEDIA2_CRG_DMSS_ASYNC_BRG_ADDR(base) ((base) + (0x1DCUL))
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_ADDR(base) ((base) + (0xD00UL))
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_ADDR(base) ((base) + (0xD04UL))
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_ADDR(base) ((base) + (0xD08UL))
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_ADDR(base) ((base) + (0xD0CUL))
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ADDR(base) ((base) + (0xD30UL))
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ADDR(base) ((base) + (0xD34UL))
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ADDR(base) ((base) + (0xD38UL))
#define SOC_MEDIA2_CRG_PERRSTEN_SEC_IVP_ADDR(base) ((base) + (0xE00UL))
#define SOC_MEDIA2_CRG_PERRSTDIS_SEC_IVP_ADDR(base) ((base) + (0xE04UL))
#define SOC_MEDIA2_CRG_PERRSTSTAT_SEC_IVP_ADDR(base) ((base) + (0xE08UL))
#define SOC_MEDIA2_CRG_DECPROT0SET_ADDR(base) ((base) + (0xF00UL))
#else
#define SOC_MEDIA2_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_MEDIA2_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_MEDIA2_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_MEDIA2_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_MEDIA2_CRG_PERRSTEN0_ADDR(base) ((base) + (0x030))
#define SOC_MEDIA2_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x034))
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038))
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x160))
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x164))
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_ADDR(base) ((base) + (0x168))
#define SOC_MEDIA2_CRG_PERI_AUTODIV3_ADDR(base) ((base) + (0x16c))
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ADDR(base) ((base) + (0x170))
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_ADDR(base) ((base) + (0x174))
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_ADDR(base) ((base) + (0x178))
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D0))
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D4))
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x1D8))
#define SOC_MEDIA2_CRG_DMSS_ASYNC_BRG_ADDR(base) ((base) + (0x1DC))
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_ADDR(base) ((base) + (0xD00))
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_ADDR(base) ((base) + (0xD04))
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_ADDR(base) ((base) + (0xD08))
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_ADDR(base) ((base) + (0xD0C))
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ADDR(base) ((base) + (0xD30))
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ADDR(base) ((base) + (0xD34))
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ADDR(base) ((base) + (0xD38))
#define SOC_MEDIA2_CRG_PERRSTEN_SEC_IVP_ADDR(base) ((base) + (0xE00))
#define SOC_MEDIA2_CRG_PERRSTDIS_SEC_IVP_ADDR(base) ((base) + (0xE04))
#define SOC_MEDIA2_CRG_PERRSTSTAT_SEC_IVP_ADDR(base) ((base) + (0xE08))
#define SOC_MEDIA2_CRG_DECPROT0SET_ADDR(base) ((base) + (0xF00))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vcodecbus : 1;
        unsigned int gt_pclk_atgs_vcodec : 1;
        unsigned int gt_pclk_autodiv_vcodecbus : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_clk_vcodecbus_ini : 1;
        unsigned int gt_clk_dmss_vcodec : 1;
        unsigned int gt_clk_loadmonitor : 1;
        unsigned int gt_pclk_media2_lm : 1;
        unsigned int gt_pclk_media2_lm_lpm3 : 1;
        unsigned int gt_clk_ivp32dsp_tcxo : 1;
        unsigned int gt_pclk_autodiv_ivp : 1;
        unsigned int gt_pclk_atgm_ivp : 1;
        unsigned int gt_clk_noc_ivp32_cfg : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_atclk_trace : 1;
        unsigned int gt_pclk_dbg_trace : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_ivp_noc_crg_ini : 1;
        unsigned int gt_clk_ivp_noc_peri_ini : 1;
    } reg;
} SOC_MEDIA2_CRG_PEREN0_UNION;
#endif
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_venc_START (3)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_venc_END (3)
#define SOC_MEDIA2_CRG_PEREN0_gt_aclk_venc_START (4)
#define SOC_MEDIA2_CRG_PEREN0_gt_aclk_venc_END (4)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_venc_START (5)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_venc_END (5)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_vdec_START (6)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_vdec_END (6)
#define SOC_MEDIA2_CRG_PEREN0_gt_aclk_vdec_START (7)
#define SOC_MEDIA2_CRG_PEREN0_gt_aclk_vdec_END (7)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_vdec_START (8)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_vdec_END (8)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_vcodecbus_START (9)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_vcodecbus_END (9)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_atgs_vcodec_START (10)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_atgs_vcodec_END (10)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_vcodecbus_START (11)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_vcodecbus_END (11)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_vdec_START (12)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_vdec_END (12)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_venc_START (13)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_venc_END (13)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_vcodecbus_ini_START (14)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_vcodecbus_ini_END (14)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_dmss_vcodec_START (15)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_dmss_vcodec_END (15)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_loadmonitor_START (16)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_loadmonitor_END (16)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_media2_lm_START (17)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_media2_lm_END (17)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_media2_lm_lpm3_START (18)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_media2_lm_lpm3_END (18)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ivp32dsp_tcxo_START (19)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ivp32dsp_tcxo_END (19)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_ivp_START (20)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_ivp_END (20)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_atgm_ivp_START (21)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_atgm_ivp_END (21)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_noc_ivp32_cfg_START (22)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_noc_ivp32_cfg_END (22)
#define SOC_MEDIA2_CRG_PEREN0_gt_atclk_trace_START (26)
#define SOC_MEDIA2_CRG_PEREN0_gt_atclk_trace_END (26)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_dbg_trace_START (27)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_dbg_trace_END (27)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ivp_noc_crg_ini_START (30)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ivp_noc_crg_ini_END (30)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ivp_noc_peri_ini_START (31)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ivp_noc_peri_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vcodecbus : 1;
        unsigned int gt_pclk_atgs_vcodec : 1;
        unsigned int gt_pclk_autodiv_vcodecbus : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_clk_vcodecbus_ini : 1;
        unsigned int gt_clk_dmss_vcodec : 1;
        unsigned int gt_clk_loadmonitor : 1;
        unsigned int gt_pclk_media2_lm : 1;
        unsigned int gt_pclk_media2_lm_lpm3 : 1;
        unsigned int gt_clk_ivp32dsp_tcxo : 1;
        unsigned int gt_pclk_autodiv_ivp : 1;
        unsigned int gt_pclk_atgm_ivp : 1;
        unsigned int gt_clk_noc_ivp32_cfg : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_atclk_trace : 1;
        unsigned int gt_pclk_dbg_trace : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_ivp_noc_crg_ini : 1;
        unsigned int gt_clk_ivp_noc_peri_ini : 1;
    } reg;
} SOC_MEDIA2_CRG_PERDIS0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_venc_START (3)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_venc_END (3)
#define SOC_MEDIA2_CRG_PERDIS0_gt_aclk_venc_START (4)
#define SOC_MEDIA2_CRG_PERDIS0_gt_aclk_venc_END (4)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_venc_START (5)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_venc_END (5)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_vdec_START (6)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_vdec_END (6)
#define SOC_MEDIA2_CRG_PERDIS0_gt_aclk_vdec_START (7)
#define SOC_MEDIA2_CRG_PERDIS0_gt_aclk_vdec_END (7)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_vdec_START (8)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_vdec_END (8)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_vcodecbus_START (9)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_vcodecbus_END (9)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_atgs_vcodec_START (10)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_atgs_vcodec_END (10)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_vcodecbus_START (11)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_vcodecbus_END (11)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_vdec_START (12)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_vdec_END (12)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_venc_START (13)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_venc_END (13)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_vcodecbus_ini_START (14)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_vcodecbus_ini_END (14)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_dmss_vcodec_START (15)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_dmss_vcodec_END (15)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_loadmonitor_START (16)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_loadmonitor_END (16)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_media2_lm_START (17)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_media2_lm_END (17)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_media2_lm_lpm3_START (18)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_media2_lm_lpm3_END (18)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ivp32dsp_tcxo_START (19)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ivp32dsp_tcxo_END (19)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_ivp_START (20)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_ivp_END (20)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_atgm_ivp_START (21)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_atgm_ivp_END (21)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_noc_ivp32_cfg_START (22)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_noc_ivp32_cfg_END (22)
#define SOC_MEDIA2_CRG_PERDIS0_gt_atclk_trace_START (26)
#define SOC_MEDIA2_CRG_PERDIS0_gt_atclk_trace_END (26)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_dbg_trace_START (27)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_dbg_trace_END (27)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ivp_noc_crg_ini_START (30)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ivp_noc_crg_ini_END (30)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ivp_noc_peri_ini_START (31)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ivp_noc_peri_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_pclk_venc : 1;
        unsigned int gt_aclk_venc : 1;
        unsigned int gt_clk_venc : 1;
        unsigned int gt_pclk_vdec : 1;
        unsigned int gt_aclk_vdec : 1;
        unsigned int gt_clk_vdec : 1;
        unsigned int gt_clk_vcodecbus : 1;
        unsigned int gt_pclk_atgs_vcodec : 1;
        unsigned int gt_pclk_autodiv_vcodecbus : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_clk_vcodecbus_ini : 1;
        unsigned int gt_clk_dmss_vcodec : 1;
        unsigned int gt_clk_loadmonitor : 1;
        unsigned int gt_pclk_media2_lm : 1;
        unsigned int gt_pclk_media2_lm_lpm3 : 1;
        unsigned int gt_clk_ivp32dsp_tcxo : 1;
        unsigned int gt_pclk_autodiv_ivp : 1;
        unsigned int gt_pclk_atgm_ivp : 1;
        unsigned int gt_clk_noc_ivp32_cfg : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_atclk_trace : 1;
        unsigned int gt_pclk_dbg_trace : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_ivp_noc_crg_ini : 1;
        unsigned int gt_clk_ivp_noc_peri_ini : 1;
    } reg;
} SOC_MEDIA2_CRG_PERCLKEN0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_venc_START (3)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_venc_END (3)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_aclk_venc_START (4)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_aclk_venc_END (4)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_venc_START (5)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_venc_END (5)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_vdec_START (6)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_vdec_END (6)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_aclk_vdec_START (7)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_aclk_vdec_END (7)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_vdec_START (8)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_vdec_END (8)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_vcodecbus_START (9)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_vcodecbus_END (9)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_atgs_vcodec_START (10)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_atgs_vcodec_END (10)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_vcodecbus_START (11)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_vcodecbus_END (11)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_vdec_START (12)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_vdec_END (12)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_venc_START (13)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_venc_END (13)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_vcodecbus_ini_START (14)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_vcodecbus_ini_END (14)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_dmss_vcodec_START (15)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_dmss_vcodec_END (15)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_loadmonitor_START (16)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_loadmonitor_END (16)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_media2_lm_START (17)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_media2_lm_END (17)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_media2_lm_lpm3_START (18)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_media2_lm_lpm3_END (18)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ivp32dsp_tcxo_START (19)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ivp32dsp_tcxo_END (19)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_ivp_START (20)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_ivp_END (20)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_atgm_ivp_START (21)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_atgm_ivp_END (21)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_noc_ivp32_cfg_START (22)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_noc_ivp32_cfg_END (22)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_atclk_trace_START (26)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_atclk_trace_END (26)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_dbg_trace_START (27)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_dbg_trace_END (27)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ivp_noc_crg_ini_START (30)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ivp_noc_crg_ini_END (30)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ivp_noc_peri_ini_START (31)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ivp_noc_peri_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_pclk_venc : 1;
        unsigned int st_aclk_venc : 1;
        unsigned int st_clk_venc : 1;
        unsigned int st_pclk_vdec : 1;
        unsigned int st_aclk_vdec : 1;
        unsigned int st_clk_vdec : 1;
        unsigned int st_clk_vcodecbus : 1;
        unsigned int st_pclk_atgs_vcodec : 1;
        unsigned int st_pclk_autodiv_vcodecbus : 1;
        unsigned int st_pclk_autodiv_vdec : 1;
        unsigned int st_pclk_autodiv_venc : 1;
        unsigned int st_clk_vcodecbus_ini : 1;
        unsigned int st_clk_dmss_vcodec : 1;
        unsigned int st_clk_loadmonitor : 1;
        unsigned int st_pclk_media2_lm : 1;
        unsigned int st_pclk_media2_lm_lpm3 : 1;
        unsigned int st_clk_ivp32dsp_tcxo : 1;
        unsigned int st_pclk_autodiv_ivp : 1;
        unsigned int st_pclk_atgm_ivp : 1;
        unsigned int st_clk_noc_ivp32_cfg : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_atclk_trace : 1;
        unsigned int st_pclk_dbg_trace : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int st_clk_ivp_noc_crg_ini : 1;
        unsigned int st_clk_ivp_noc_peri_ini : 1;
    } reg;
} SOC_MEDIA2_CRG_PERSTAT0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_venc_START (3)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_venc_END (3)
#define SOC_MEDIA2_CRG_PERSTAT0_st_aclk_venc_START (4)
#define SOC_MEDIA2_CRG_PERSTAT0_st_aclk_venc_END (4)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_venc_START (5)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_venc_END (5)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_vdec_START (6)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_vdec_END (6)
#define SOC_MEDIA2_CRG_PERSTAT0_st_aclk_vdec_START (7)
#define SOC_MEDIA2_CRG_PERSTAT0_st_aclk_vdec_END (7)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_vdec_START (8)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_vdec_END (8)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_vcodecbus_START (9)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_vcodecbus_END (9)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_atgs_vcodec_START (10)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_atgs_vcodec_END (10)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_vcodecbus_START (11)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_vcodecbus_END (11)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_vdec_START (12)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_vdec_END (12)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_venc_START (13)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_venc_END (13)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_vcodecbus_ini_START (14)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_vcodecbus_ini_END (14)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_dmss_vcodec_START (15)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_dmss_vcodec_END (15)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_loadmonitor_START (16)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_loadmonitor_END (16)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_media2_lm_START (17)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_media2_lm_END (17)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_media2_lm_lpm3_START (18)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_media2_lm_lpm3_END (18)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ivp32dsp_tcxo_START (19)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ivp32dsp_tcxo_END (19)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_ivp_START (20)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_ivp_END (20)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_atgm_ivp_START (21)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_atgm_ivp_END (21)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_noc_ivp32_cfg_START (22)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_noc_ivp32_cfg_END (22)
#define SOC_MEDIA2_CRG_PERSTAT0_st_atclk_trace_START (26)
#define SOC_MEDIA2_CRG_PERSTAT0_st_atclk_trace_END (26)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_dbg_trace_START (27)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_dbg_trace_END (27)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ivp_noc_crg_ini_START (30)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ivp_noc_crg_ini_END (30)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ivp_noc_peri_ini_START (31)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ivp_noc_peri_ini_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_venc : 1;
        unsigned int ip_arst_venc : 1;
        unsigned int ip_prst_venc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_prst_media2_lm : 1;
        unsigned int ip_prst_atgs_vcodec : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_atgm_ivp : 1;
        unsigned int ip_rst_trace : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 16;
    } reg;
} SOC_MEDIA2_CRG_PERRSTEN0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_venc_START (0)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_venc_END (0)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_arst_venc_START (1)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_arst_venc_END (1)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_venc_START (2)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_venc_END (2)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_vdec_START (6)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_vdec_END (6)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_media2_lm_START (7)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_media2_lm_END (7)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_atgs_vcodec_START (8)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_atgs_vcodec_END (8)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_atgm_ivp_START (10)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_atgm_ivp_END (10)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_trace_START (11)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_trace_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_venc : 1;
        unsigned int ip_arst_venc : 1;
        unsigned int ip_prst_venc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_prst_media2_lm : 1;
        unsigned int ip_prst_atgs_vcodec : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_atgm_ivp : 1;
        unsigned int ip_rst_trace : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 16;
    } reg;
} SOC_MEDIA2_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_venc_START (0)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_venc_END (0)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_arst_venc_START (1)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_arst_venc_END (1)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_venc_START (2)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_venc_END (2)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_vdec_START (6)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_vdec_END (6)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_media2_lm_START (7)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_media2_lm_END (7)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_atgs_vcodec_START (8)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_atgs_vcodec_END (8)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_atgm_ivp_START (10)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_atgm_ivp_END (10)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_trace_START (11)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_trace_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_venc : 1;
        unsigned int ip_arst_venc : 1;
        unsigned int ip_prst_venc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_prst_media2_lm : 1;
        unsigned int ip_prst_atgs_vcodec : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_atgm_ivp : 1;
        unsigned int ip_rst_trace : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 16;
    } reg;
} SOC_MEDIA2_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_venc_START (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_venc_END (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_arst_venc_START (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_arst_venc_END (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_venc_START (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_venc_END (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_vdec_START (6)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_vdec_END (6)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_media2_lm_START (7)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_media2_lm_END (7)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_atgs_vcodec_START (8)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_atgs_vcodec_END (8)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_atgm_ivp_START (10)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_atgm_ivp_END (10)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_trace_START (11)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_trace_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int venc_auto_waitcfg_in : 10;
        unsigned int venc_auto_waitcfg_out : 10;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_venc_auto_waitcfg_in_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_venc_auto_waitcfg_in_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_venc_auto_waitcfg_out_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_venc_auto_waitcfg_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int vdec_auto_waitcfg_in : 10;
        unsigned int vdec_auto_waitcfg_out : 10;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_vdec_auto_waitcfg_in_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_vdec_auto_waitcfg_in_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_vdec_auto_waitcfg_out_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_vdec_auto_waitcfg_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int vcodecbus_auto_waitcfg_in : 10;
        unsigned int vcodecbus_auto_waitcfg_out : 8;
        unsigned int vcodecbus_ivp32_idle_bypass : 1;
        unsigned int vcodecbus_venc2_idle_bypass : 1;
        unsigned int vcodecbus_venc_idle_bypass : 1;
        unsigned int vcodecbus_vdec_idle_bypass : 1;
        unsigned int vcodecbus_hiface_core_idle_bypass : 1;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV2_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_auto_waitcfg_in_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_auto_waitcfg_in_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_auto_waitcfg_out_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_auto_waitcfg_out_END (18)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_ivp32_idle_bypass_START (19)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_ivp32_idle_bypass_END (19)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_venc2_idle_bypass_START (20)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_venc2_idle_bypass_END (20)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_venc_idle_bypass_START (21)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_venc_idle_bypass_END (21)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_vdec_idle_bypass_START (22)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_vdec_idle_bypass_END (22)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_hiface_core_idle_bypass_START (23)
#define SOC_MEDIA2_CRG_PERI_AUTODIV2_vcodecbus_hiface_core_idle_bypass_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int venc2_auto_waitcfg_in : 10;
        unsigned int venc2_auto_waitcfg_out : 10;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV3_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV3_venc2_auto_waitcfg_in_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV3_venc2_auto_waitcfg_in_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV3_venc2_auto_waitcfg_out_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV3_venc2_auto_waitcfg_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int ivp_auto_waitcfg_in : 10;
        unsigned int ivp_auto_waitcfg_out : 9;
        unsigned int reserved_1 : 7;
        unsigned int ivp_pwaitmode_bypass : 1;
        unsigned int ivp_dw_axi_m1_st_bypass : 1;
        unsigned int ivp_dw_axi_m2_st_bypass : 1;
        unsigned int ivp_dw_axi_m3_st_bypass : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV4_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_auto_waitcfg_in_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_auto_waitcfg_in_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_auto_waitcfg_out_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_auto_waitcfg_out_END (19)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_pwaitmode_bypass_START (27)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_pwaitmode_bypass_END (27)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_dw_axi_m1_st_bypass_START (28)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_dw_axi_m1_st_bypass_END (28)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_dw_axi_m2_st_bypass_START (29)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_dw_axi_m2_st_bypass_END (29)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_dw_axi_m3_st_bypass_START (30)
#define SOC_MEDIA2_CRG_PERI_AUTODIV4_ivp_dw_axi_m3_st_bypass_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcodecbus_ddrc0_bypass : 1;
        unsigned int vcodecbus_ddrc1_bypass : 1;
        unsigned int vcodecbus_vdec_bypass : 1;
        unsigned int vcodecbus_venc_bypass : 1;
        unsigned int vcodecbus_venc2_bypass : 1;
        unsigned int vcodecbus_ivp32_mst_bypass : 1;
        unsigned int vcodecbus_ivp_core_bypass : 1;
        unsigned int vcodecbus_ivp_idma_bypass : 1;
        unsigned int vcodecbus_hiface_core_bypass : 1;
        unsigned int vcodecbus_eps_axi_bypass : 1;
        unsigned int reserved : 12;
        unsigned int vcodecbus_hiface_core_cfg_bypass : 1;
        unsigned int vcodecbus_eps_cfg_bypass : 1;
        unsigned int vcodecbus_eps_ahb_bypass : 1;
        unsigned int vcodecbus_ipv32_cfg_bypass : 1;
        unsigned int vcodecbus_venc2_cfg_bypass : 1;
        unsigned int vcodecbus_venc_cfg_bypass : 1;
        unsigned int vcodecbus_vdec_cfg_bypass : 1;
        unsigned int vcodecbus_vcodec_crg_bypass : 1;
        unsigned int vcodecbus_vcodec2cfg_bypass : 1;
        unsigned int vcodecbus_cfg2vcodec_bypass : 1;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV5_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ddrc0_bypass_START (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ddrc0_bypass_END (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ddrc1_bypass_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ddrc1_bypass_END (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vdec_bypass_START (2)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vdec_bypass_END (2)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc_bypass_START (3)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc_bypass_END (3)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc2_bypass_START (4)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc2_bypass_END (4)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ivp32_mst_bypass_START (5)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ivp32_mst_bypass_END (5)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ivp_core_bypass_START (6)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ivp_core_bypass_END (6)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ivp_idma_bypass_START (7)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ivp_idma_bypass_END (7)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_hiface_core_bypass_START (8)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_hiface_core_bypass_END (8)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_eps_axi_bypass_START (9)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_eps_axi_bypass_END (9)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_hiface_core_cfg_bypass_START (22)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_hiface_core_cfg_bypass_END (22)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_eps_cfg_bypass_START (23)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_eps_cfg_bypass_END (23)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_eps_ahb_bypass_START (24)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_eps_ahb_bypass_END (24)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ipv32_cfg_bypass_START (25)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_ipv32_cfg_bypass_END (25)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc2_cfg_bypass_START (26)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc2_cfg_bypass_END (26)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc_cfg_bypass_START (27)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_venc_cfg_bypass_END (27)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vdec_cfg_bypass_START (28)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vdec_cfg_bypass_END (28)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vcodec_crg_bypass_START (29)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vcodec_crg_bypass_END (29)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vcodec2cfg_bypass_START (30)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_vcodec2cfg_bypass_END (30)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_cfg2vcodec_bypass_START (31)
#define SOC_MEDIA2_CRG_PERI_AUTODIV5_vcodecbus_cfg2vcodec_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vcodecbus_bbk_eps_cfg_bypass : 1;
        unsigned int vcodecbus_bbk_eps_service_target_bypass : 1;
        unsigned int vcodecbus_bbk_eps_bypass : 1;
        unsigned int vcodecbus_bbk_eps_mst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hiface_core_auto_waitcfg_in : 5;
        unsigned int hiface_core_auto_waitcfg_out : 10;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV6_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_cfg_bypass_START (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_cfg_bypass_END (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_service_target_bypass_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_service_target_bypass_END (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_bypass_START (2)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_bypass_END (2)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_mst_bypass_START (3)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_vcodecbus_bbk_eps_mst_bypass_END (3)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_hiface_core_auto_waitcfg_in_START (6)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_hiface_core_auto_waitcfg_in_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_hiface_core_auto_waitcfg_out_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV6_hiface_core_auto_waitcfg_out_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr_media2bus_nonidle_pend : 1;
        unsigned int intr_mask_vcodecbus_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_mask_vdecbus_nonidle_pend : 1;
        unsigned int intr_mask_vencbus_nonidle_pend : 1;
        unsigned int intr_mask_ivpbus_nonidle_pend : 1;
        unsigned int intr_mask_hiface_bus_nonidle_pend : 1;
        unsigned int reserved_1 : 9;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_clr_media2bus_nonidle_pend_START (0)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_clr_media2bus_nonidle_pend_END (0)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_vcodecbus_nonidle_pend_START (1)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_vcodecbus_nonidle_pend_END (1)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_vdecbus_nonidle_pend_START (3)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_vdecbus_nonidle_pend_END (3)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_vencbus_nonidle_pend_START (4)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_vencbus_nonidle_pend_END (4)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_ivpbus_nonidle_pend_START (5)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_ivpbus_nonidle_pend_END (5)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_hiface_bus_nonidle_pend_START (6)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_intr_mask_hiface_bus_nonidle_pend_END (6)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MEDIA2_CRG_INTR_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_vcodecbus_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_stat_vdecbus_nonidle_pend : 1;
        unsigned int intr_stat_vencbus_nonidle_pend : 1;
        unsigned int intr_stat_ivpbus_nonidle_pend : 1;
        unsigned int intr_stat_hiface_bus_nonidle_pend : 1;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_vcodecbus_nonidle_pend_START (0)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_vcodecbus_nonidle_pend_END (0)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_vdecbus_nonidle_pend_START (2)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_vdecbus_nonidle_pend_END (2)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_vencbus_nonidle_pend_START (3)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_vencbus_nonidle_pend_END (3)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ivpbus_nonidle_pend_START (4)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ivpbus_nonidle_pend_END (4)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hiface_bus_nonidle_pend_START (5)
#define SOC_MEDIA2_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hiface_bus_nonidle_pend_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int media2_lm_clkrst_bypass : 1;
        unsigned int media2_trace_clkrst_bypass : 1;
        unsigned int hiface_core_clkrst_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MEDIA2_CRG_IPCLKRST_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_media2_lm_clkrst_bypass_START (0)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_media2_lm_clkrst_bypass_END (0)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_media2_trace_clkrst_bypass_START (1)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_media2_trace_clkrst_bypass_END (1)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_hiface_core_clkrst_bypass_START (2)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_hiface_core_clkrst_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmss_ckg_byp : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_MEDIA2_CRG_DMSS_ASYNC_BRG_UNION;
#endif
#define SOC_MEDIA2_CRG_DMSS_ASYNC_BRG_dmss_ckg_byp_START (0)
#define SOC_MEDIA2_CRG_DMSS_ASYNC_BRG_dmss_ckg_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_aclk_hiface_noc : 1;
        unsigned int gt_pclk_hiface_noc : 1;
        unsigned int gt_clk_hieps_tcxo : 1;
        unsigned int gt_atclk_hieps : 1;
        unsigned int gt_pclk_dbg_hieps : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 23;
    } reg;
} SOC_MEDIA2_CRG_PEREN1_HIFACE_UNION;
#endif
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_aclk_hiface_noc_START (3)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_aclk_hiface_noc_END (3)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_pclk_hiface_noc_START (4)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_pclk_hiface_noc_END (4)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_clk_hieps_tcxo_START (5)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_clk_hieps_tcxo_END (5)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_atclk_hieps_START (6)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_atclk_hieps_END (6)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_pclk_dbg_hieps_START (7)
#define SOC_MEDIA2_CRG_PEREN1_HIFACE_gt_pclk_dbg_hieps_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_aclk_hiface_noc : 1;
        unsigned int gt_pclk_hiface_noc : 1;
        unsigned int gt_clk_hieps_tcxo : 1;
        unsigned int gt_atclk_hieps : 1;
        unsigned int gt_pclk_dbg_hieps : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 23;
    } reg;
} SOC_MEDIA2_CRG_PERDIS1_HIFACE_UNION;
#endif
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_aclk_hiface_noc_START (3)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_aclk_hiface_noc_END (3)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_pclk_hiface_noc_START (4)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_pclk_hiface_noc_END (4)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_clk_hieps_tcxo_START (5)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_clk_hieps_tcxo_END (5)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_atclk_hieps_START (6)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_atclk_hieps_END (6)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_pclk_dbg_hieps_START (7)
#define SOC_MEDIA2_CRG_PERDIS1_HIFACE_gt_pclk_dbg_hieps_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_aclk_hiface_noc : 1;
        unsigned int gt_pclk_hiface_noc : 1;
        unsigned int gt_clk_hieps_tcxo : 1;
        unsigned int gt_atclk_hieps : 1;
        unsigned int gt_pclk_dbg_hieps : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 23;
    } reg;
} SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_UNION;
#endif
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_aclk_hiface_noc_START (3)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_aclk_hiface_noc_END (3)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_pclk_hiface_noc_START (4)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_pclk_hiface_noc_END (4)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_clk_hieps_tcxo_START (5)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_clk_hieps_tcxo_END (5)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_atclk_hieps_START (6)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_atclk_hieps_END (6)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_pclk_dbg_hieps_START (7)
#define SOC_MEDIA2_CRG_PERCLKEN1_HIFACE_gt_pclk_dbg_hieps_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_aclk_hiface_noc : 1;
        unsigned int st_pclk_hiface_noc : 1;
        unsigned int st_clk_hieps_tcxo : 1;
        unsigned int st_atclk_hieps : 1;
        unsigned int st_pclk_dbg_hieps : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 23;
    } reg;
} SOC_MEDIA2_CRG_PERSTAT1_HIFACE_UNION;
#endif
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_aclk_hiface_noc_START (3)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_aclk_hiface_noc_END (3)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_pclk_hiface_noc_START (4)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_pclk_hiface_noc_END (4)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_clk_hieps_tcxo_START (5)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_clk_hieps_tcxo_END (5)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_atclk_hieps_START (6)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_atclk_hieps_END (6)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_pclk_dbg_hieps_START (7)
#define SOC_MEDIA2_CRG_PERSTAT1_HIFACE_st_pclk_dbg_hieps_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hiface : 1;
        unsigned int ip_rst_hiface_crg : 1;
        unsigned int ip_rst_hieps : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ip_rst_hiface_START (13)
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ip_rst_hiface_END (13)
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ip_rst_hiface_crg_START (14)
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ip_rst_hiface_crg_END (14)
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ip_rst_hieps_START (15)
#define SOC_MEDIA2_CRG_PERRSTEN0_HIFACE_ip_rst_hieps_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hiface : 1;
        unsigned int ip_rst_hiface_crg : 1;
        unsigned int ip_rst_hieps : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ip_rst_hiface_START (13)
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ip_rst_hiface_END (13)
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ip_rst_hiface_crg_START (14)
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ip_rst_hiface_crg_END (14)
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ip_rst_hieps_START (15)
#define SOC_MEDIA2_CRG_PERRSTDIS0_HIFACE_ip_rst_hieps_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_hiface : 1;
        unsigned int ip_rst_hiface_crg : 1;
        unsigned int ip_rst_hieps : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ip_rst_hiface_START (13)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ip_rst_hiface_END (13)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ip_rst_hiface_crg_START (14)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ip_rst_hiface_crg_END (14)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ip_rst_hieps_START (15)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_HIFACE_ip_rst_hieps_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32dsp_subsys_crg : 1;
        unsigned int ip_rst_ivp32dsp_subsys : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_MEDIA2_CRG_PERRSTEN_SEC_IVP_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_START (0)
#define SOC_MEDIA2_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_END (0)
#define SOC_MEDIA2_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_START (1)
#define SOC_MEDIA2_CRG_PERRSTEN_SEC_IVP_ip_rst_ivp32dsp_subsys_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32dsp_subsys_crg : 1;
        unsigned int ip_rst_ivp32dsp_subsys : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_MEDIA2_CRG_PERRSTDIS_SEC_IVP_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_START (0)
#define SOC_MEDIA2_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_END (0)
#define SOC_MEDIA2_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_START (1)
#define SOC_MEDIA2_CRG_PERRSTDIS_SEC_IVP_ip_rst_ivp32dsp_subsys_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_ivp32dsp_subsys_crg : 1;
        unsigned int ip_rst_ivp32dsp_subsys : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_MEDIA2_CRG_PERRSTSTAT_SEC_IVP_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_START (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_crg_END (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_START (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT_SEC_IVP_ip_rst_ivp32dsp_subsys_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_secure_n_med2_lm : 1;
        unsigned int tz_secure_n_hiface : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MEDIA2_CRG_DECPROT0SET_UNION;
#endif
#define SOC_MEDIA2_CRG_DECPROT0SET_tz_secure_n_med2_lm_START (0)
#define SOC_MEDIA2_CRG_DECPROT0SET_tz_secure_n_med2_lm_END (0)
#define SOC_MEDIA2_CRG_DECPROT0SET_tz_secure_n_hiface_START (1)
#define SOC_MEDIA2_CRG_DECPROT0SET_tz_secure_n_hiface_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
