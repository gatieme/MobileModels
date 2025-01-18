#ifndef __SOC_FDUL_INTERFACE_H__
#define __SOC_FDUL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FDUL_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_FDUL_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_FDUL_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_FDUL_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_FDUL_PERRSTEN0_ADDR(base) ((base) + (0x020UL))
#define SOC_FDUL_PERRSTDIS0_ADDR(base) ((base) + (0x024UL))
#define SOC_FDUL_PERRSTSTAT0_ADDR(base) ((base) + (0x028UL))
#define SOC_FDUL_CLKDIV0_ADDR(base) ((base) + (0x040UL))
#define SOC_FDUL_CLKDIV1_ADDR(base) ((base) + (0x048UL))
#define SOC_FDUL_CLKDIV2_ADDR(base) ((base) + (0x04CUL))
#define SOC_FDUL_EDMA_CLK_FORCE_ENABLE_ADDR(base) ((base) + (0x0050UL))
#define SOC_FDUL_TINY_CLK_GAP_ADDR(base) ((base) + (0x0054UL))
#define SOC_FDUL_PERI_STAT0_ADDR(base) ((base) + (0x060UL))
#define SOC_FDUL_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x080UL))
#define SOC_FDUL_LB_MEM_CTRL_SP_ADDR(base) ((base) + (0x208UL))
#define SOC_FDUL_AIC_IFU_MEM_CTRL_SP_ADDR(base) ((base) + (0x20CUL))
#define SOC_FDUL_AIC_MTE_MEM_CTRL_SP_ADDR(base) ((base) + (0x210UL))
#define SOC_FDUL_AIC_VEC_MEM_CTRL_SP_ADDR(base) ((base) + (0x214UL))
#define SOC_FDUL_AIC_CCU_MEM_CTRL_SP_ADDR(base) ((base) + (0x218UL))
#define SOC_FDUL_EDMA_MEM_CTRL_TP_ADDR(base) ((base) + (0x244UL))
#define SOC_FDUL_AIC_CUBE_MEM_CTRL_TP_ADDR(base) ((base) + (0x248UL))
#define SOC_FDUL_AIC_MTE_MEM_CTRL_TP_ADDR(base) ((base) + (0x24CUL))
#define SOC_FDUL_CLK_AOBUS_EN_ADDR(base) ((base) + (0x400UL))
#define SOC_FDUL_FLL_CTRL_ADDR(base) ((base) + (0x408UL))
#define SOC_FDUL_AR_BANDWID_CTRL_ADDR(base) ((base) + (0x500UL))
#define SOC_FDUL_AW_BANDWID_CTRL_ADDR(base) ((base) + (0x504UL))
#define SOC_FDUL_AR_BANDWID_CTRL2_ADDR(base) ((base) + (0x508UL))
#define SOC_FDUL_AW_BANDWID_CTRL2_ADDR(base) ((base) + (0x50CUL))
#define SOC_FDUL_NOC_MAINPRESS_ADDR(base) ((base) + (0x580UL))
#define SOC_FDUL_NOC_AR_PTL_FULL_ADDR(base) ((base) + (0x58CUL))
#define SOC_FDUL_NOC_AW_PTL_FULL_ADDR(base) ((base) + (0x590UL))
#define SOC_FDUL_AXI_BUS_ERR_STAT_ADDR(base) ((base) + (0x600UL))
#define SOC_FDUL_AIC_TESTPORT_SEL_ADDR(base) ((base) + (0x800UL))
#define SOC_FDUL_AIC_TESTPORT_ADDR(base) ((base) + (0x804UL))
#define SOC_FDUL_AIC_CLK_SEL_ADDR(base) ((base) + (0x808UL))
#define SOC_FDUL_ERR_INT_STAT_ADDR(base) ((base) + (0xEC0UL))
#define SOC_FDUL_ERR_INT_MASK_ADDR(base) ((base) + (0xf00UL))
#define SOC_FDUL_DW_AXI_CG_EN_ADDR(base) ((base) + (0xf04UL))
#define SOC_FDUL_DW_AXI_STAT_ADDR(base) ((base) + (0xf08UL))
#define SOC_FDUL_AXI_SOFTRST_CTRL_ADDR(base) ((base) + (0xfB0UL))
#define SOC_FDUL_AXI_SOFTRST_ACK_ADDR(base) ((base) + (0xfB4UL))
#define SOC_FDUL_AXI_SOFTRST_ST0_ADDR(base) ((base) + (0xfB8UL))
#define SOC_FDUL_AXI_SOFTRST_ST1_ADDR(base) ((base) + (0xfBCUL))
#define SOC_FDUL_M5_AXI_SOFTRST_CTRL_ADDR(base) ((base) + (0xf90UL))
#define SOC_FDUL_M5_AXI_SOFTRST_ACK_ADDR(base) ((base) + (0xf94UL))
#define SOC_FDUL_M5_AXI_SOFTRST_ST0_ADDR(base) ((base) + (0xf98UL))
#define SOC_FDUL_M5_AXI_SOFTRST_ST1_ADDR(base) ((base) + (0xf9CUL))
#define SOC_FDUL_M3_AXI_SOFTRST_CTRL_ADDR(base) ((base) + (0xfA0UL))
#define SOC_FDUL_M3_AXI_SOFTRST_ACK_ADDR(base) ((base) + (0xfA4UL))
#define SOC_FDUL_M3_AXI_SOFTRST_ST0_ADDR(base) ((base) + (0xfA8UL))
#define SOC_FDUL_M3_AXI_SOFTRST_ST1_ADDR(base) ((base) + (0xfACUL))
#define SOC_FDUL_MINIISP_PACK_DISABLE_ADDR(base) ((base) + (0xfC0UL))
#define SOC_FDUL_AICORE_PACK_DISABLE_ADDR(base) ((base) + (0xfC4UL))
#define SOC_FDUL_HWTS_PACK_DISABLE_ADDR(base) ((base) + (0xfC8UL))
#define SOC_FDUL_RESERVED_ADDR(base) ((base) + (0xffcUL))
#else
#define SOC_FDUL_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_FDUL_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_FDUL_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_FDUL_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_FDUL_PERRSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_FDUL_PERRSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_FDUL_PERRSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_FDUL_CLKDIV0_ADDR(base) ((base) + (0x040))
#define SOC_FDUL_CLKDIV1_ADDR(base) ((base) + (0x048))
#define SOC_FDUL_CLKDIV2_ADDR(base) ((base) + (0x04C))
#define SOC_FDUL_EDMA_CLK_FORCE_ENABLE_ADDR(base) ((base) + (0x0050))
#define SOC_FDUL_TINY_CLK_GAP_ADDR(base) ((base) + (0x0054))
#define SOC_FDUL_PERI_STAT0_ADDR(base) ((base) + (0x060))
#define SOC_FDUL_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x080))
#define SOC_FDUL_LB_MEM_CTRL_SP_ADDR(base) ((base) + (0x208))
#define SOC_FDUL_AIC_IFU_MEM_CTRL_SP_ADDR(base) ((base) + (0x20C))
#define SOC_FDUL_AIC_MTE_MEM_CTRL_SP_ADDR(base) ((base) + (0x210))
#define SOC_FDUL_AIC_VEC_MEM_CTRL_SP_ADDR(base) ((base) + (0x214))
#define SOC_FDUL_AIC_CCU_MEM_CTRL_SP_ADDR(base) ((base) + (0x218))
#define SOC_FDUL_EDMA_MEM_CTRL_TP_ADDR(base) ((base) + (0x244))
#define SOC_FDUL_AIC_CUBE_MEM_CTRL_TP_ADDR(base) ((base) + (0x248))
#define SOC_FDUL_AIC_MTE_MEM_CTRL_TP_ADDR(base) ((base) + (0x24C))
#define SOC_FDUL_CLK_AOBUS_EN_ADDR(base) ((base) + (0x400))
#define SOC_FDUL_FLL_CTRL_ADDR(base) ((base) + (0x408))
#define SOC_FDUL_AR_BANDWID_CTRL_ADDR(base) ((base) + (0x500))
#define SOC_FDUL_AW_BANDWID_CTRL_ADDR(base) ((base) + (0x504))
#define SOC_FDUL_AR_BANDWID_CTRL2_ADDR(base) ((base) + (0x508))
#define SOC_FDUL_AW_BANDWID_CTRL2_ADDR(base) ((base) + (0x50C))
#define SOC_FDUL_NOC_MAINPRESS_ADDR(base) ((base) + (0x580))
#define SOC_FDUL_NOC_AR_PTL_FULL_ADDR(base) ((base) + (0x58C))
#define SOC_FDUL_NOC_AW_PTL_FULL_ADDR(base) ((base) + (0x590))
#define SOC_FDUL_AXI_BUS_ERR_STAT_ADDR(base) ((base) + (0x600))
#define SOC_FDUL_AIC_TESTPORT_SEL_ADDR(base) ((base) + (0x800))
#define SOC_FDUL_AIC_TESTPORT_ADDR(base) ((base) + (0x804))
#define SOC_FDUL_AIC_CLK_SEL_ADDR(base) ((base) + (0x808))
#define SOC_FDUL_ERR_INT_STAT_ADDR(base) ((base) + (0xEC0))
#define SOC_FDUL_ERR_INT_MASK_ADDR(base) ((base) + (0xf00))
#define SOC_FDUL_DW_AXI_CG_EN_ADDR(base) ((base) + (0xf04))
#define SOC_FDUL_DW_AXI_STAT_ADDR(base) ((base) + (0xf08))
#define SOC_FDUL_AXI_SOFTRST_CTRL_ADDR(base) ((base) + (0xfB0))
#define SOC_FDUL_AXI_SOFTRST_ACK_ADDR(base) ((base) + (0xfB4))
#define SOC_FDUL_AXI_SOFTRST_ST0_ADDR(base) ((base) + (0xfB8))
#define SOC_FDUL_AXI_SOFTRST_ST1_ADDR(base) ((base) + (0xfBC))
#define SOC_FDUL_M5_AXI_SOFTRST_CTRL_ADDR(base) ((base) + (0xf90))
#define SOC_FDUL_M5_AXI_SOFTRST_ACK_ADDR(base) ((base) + (0xf94))
#define SOC_FDUL_M5_AXI_SOFTRST_ST0_ADDR(base) ((base) + (0xf98))
#define SOC_FDUL_M5_AXI_SOFTRST_ST1_ADDR(base) ((base) + (0xf9C))
#define SOC_FDUL_M3_AXI_SOFTRST_CTRL_ADDR(base) ((base) + (0xfA0))
#define SOC_FDUL_M3_AXI_SOFTRST_ACK_ADDR(base) ((base) + (0xfA4))
#define SOC_FDUL_M3_AXI_SOFTRST_ST0_ADDR(base) ((base) + (0xfA8))
#define SOC_FDUL_M3_AXI_SOFTRST_ST1_ADDR(base) ((base) + (0xfAC))
#define SOC_FDUL_MINIISP_PACK_DISABLE_ADDR(base) ((base) + (0xfC0))
#define SOC_FDUL_AICORE_PACK_DISABLE_ADDR(base) ((base) + (0xfC4))
#define SOC_FDUL_HWTS_PACK_DISABLE_ADDR(base) ((base) + (0xfC8))
#define SOC_FDUL_RESERVED_ADDR(base) ((base) + (0xffc))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_tzpc : 1;
        unsigned int gt_pclk_dmmu0 : 1;
        unsigned int gt_pclk_dmmu1 : 1;
        unsigned int gt_pclk_dmmu2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_aclk_edma : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_imgcap : 1;
        unsigned int gt_clk_imgcap : 1;
        unsigned int gt_pclk_hifd_core : 1;
        unsigned int gt_clk_hifd_core : 1;
        unsigned int gt_pclk_lb : 1;
        unsigned int gt_clk_lb : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_csi_out : 1;
        unsigned int gt_pclk_s3asc : 1;
        unsigned int gt_pclk_csi_out : 1;
        unsigned int reserved_11 : 7;
    } reg;
} SOC_FDUL_PEREN0_UNION;
#endif
#define SOC_FDUL_PEREN0_gt_pclk_tzpc_START (0)
#define SOC_FDUL_PEREN0_gt_pclk_tzpc_END (0)
#define SOC_FDUL_PEREN0_gt_pclk_dmmu0_START (1)
#define SOC_FDUL_PEREN0_gt_pclk_dmmu0_END (1)
#define SOC_FDUL_PEREN0_gt_pclk_dmmu1_START (2)
#define SOC_FDUL_PEREN0_gt_pclk_dmmu1_END (2)
#define SOC_FDUL_PEREN0_gt_pclk_dmmu2_START (3)
#define SOC_FDUL_PEREN0_gt_pclk_dmmu2_END (3)
#define SOC_FDUL_PEREN0_gt_aclk_edma_START (5)
#define SOC_FDUL_PEREN0_gt_aclk_edma_END (5)
#define SOC_FDUL_PEREN0_gt_pclk_imgcap_START (7)
#define SOC_FDUL_PEREN0_gt_pclk_imgcap_END (7)
#define SOC_FDUL_PEREN0_gt_clk_imgcap_START (8)
#define SOC_FDUL_PEREN0_gt_clk_imgcap_END (8)
#define SOC_FDUL_PEREN0_gt_pclk_hifd_core_START (9)
#define SOC_FDUL_PEREN0_gt_pclk_hifd_core_END (9)
#define SOC_FDUL_PEREN0_gt_clk_hifd_core_START (10)
#define SOC_FDUL_PEREN0_gt_clk_hifd_core_END (10)
#define SOC_FDUL_PEREN0_gt_pclk_lb_START (11)
#define SOC_FDUL_PEREN0_gt_pclk_lb_END (11)
#define SOC_FDUL_PEREN0_gt_clk_lb_START (12)
#define SOC_FDUL_PEREN0_gt_clk_lb_END (12)
#define SOC_FDUL_PEREN0_gt_clk_csi_out_START (22)
#define SOC_FDUL_PEREN0_gt_clk_csi_out_END (22)
#define SOC_FDUL_PEREN0_gt_pclk_s3asc_START (23)
#define SOC_FDUL_PEREN0_gt_pclk_s3asc_END (23)
#define SOC_FDUL_PEREN0_gt_pclk_csi_out_START (24)
#define SOC_FDUL_PEREN0_gt_pclk_csi_out_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_tzpc : 1;
        unsigned int gt_pclk_dmmu0 : 1;
        unsigned int gt_pclk_dmmu1 : 1;
        unsigned int gt_pclk_dmmu2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_aclk_edma : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_imgcap : 1;
        unsigned int gt_clk_imgcap : 1;
        unsigned int gt_pclk_hifd_core : 1;
        unsigned int gt_clk_hifd_core : 1;
        unsigned int gt_pclk_lb : 1;
        unsigned int gt_clk_lb : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_csi_out : 1;
        unsigned int gt_pclk_s3asc : 1;
        unsigned int gt_pclk_csi_out : 1;
        unsigned int reserved_11 : 7;
    } reg;
} SOC_FDUL_PERDIS0_UNION;
#endif
#define SOC_FDUL_PERDIS0_gt_pclk_tzpc_START (0)
#define SOC_FDUL_PERDIS0_gt_pclk_tzpc_END (0)
#define SOC_FDUL_PERDIS0_gt_pclk_dmmu0_START (1)
#define SOC_FDUL_PERDIS0_gt_pclk_dmmu0_END (1)
#define SOC_FDUL_PERDIS0_gt_pclk_dmmu1_START (2)
#define SOC_FDUL_PERDIS0_gt_pclk_dmmu1_END (2)
#define SOC_FDUL_PERDIS0_gt_pclk_dmmu2_START (3)
#define SOC_FDUL_PERDIS0_gt_pclk_dmmu2_END (3)
#define SOC_FDUL_PERDIS0_gt_aclk_edma_START (5)
#define SOC_FDUL_PERDIS0_gt_aclk_edma_END (5)
#define SOC_FDUL_PERDIS0_gt_pclk_imgcap_START (7)
#define SOC_FDUL_PERDIS0_gt_pclk_imgcap_END (7)
#define SOC_FDUL_PERDIS0_gt_clk_imgcap_START (8)
#define SOC_FDUL_PERDIS0_gt_clk_imgcap_END (8)
#define SOC_FDUL_PERDIS0_gt_pclk_hifd_core_START (9)
#define SOC_FDUL_PERDIS0_gt_pclk_hifd_core_END (9)
#define SOC_FDUL_PERDIS0_gt_clk_hifd_core_START (10)
#define SOC_FDUL_PERDIS0_gt_clk_hifd_core_END (10)
#define SOC_FDUL_PERDIS0_gt_pclk_lb_START (11)
#define SOC_FDUL_PERDIS0_gt_pclk_lb_END (11)
#define SOC_FDUL_PERDIS0_gt_clk_lb_START (12)
#define SOC_FDUL_PERDIS0_gt_clk_lb_END (12)
#define SOC_FDUL_PERDIS0_gt_clk_csi_out_START (22)
#define SOC_FDUL_PERDIS0_gt_clk_csi_out_END (22)
#define SOC_FDUL_PERDIS0_gt_pclk_s3asc_START (23)
#define SOC_FDUL_PERDIS0_gt_pclk_s3asc_END (23)
#define SOC_FDUL_PERDIS0_gt_pclk_csi_out_START (24)
#define SOC_FDUL_PERDIS0_gt_pclk_csi_out_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_tzpc : 1;
        unsigned int gt_pclk_dmmu0 : 1;
        unsigned int gt_pclk_dmmu1 : 1;
        unsigned int gt_pclk_dmmu2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_aclk_edma : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_imgcap : 1;
        unsigned int gt_clk_imgcap : 1;
        unsigned int gt_pclk_hifd_core : 1;
        unsigned int gt_clk_hifd_core : 1;
        unsigned int gt_pclk_lb : 1;
        unsigned int gt_clk_lb : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_csi_out : 1;
        unsigned int gt_pclk_s3asc : 1;
        unsigned int gt_pclk_csi_out : 1;
        unsigned int reserved_11 : 7;
    } reg;
} SOC_FDUL_PERCLKEN0_UNION;
#endif
#define SOC_FDUL_PERCLKEN0_gt_pclk_tzpc_START (0)
#define SOC_FDUL_PERCLKEN0_gt_pclk_tzpc_END (0)
#define SOC_FDUL_PERCLKEN0_gt_pclk_dmmu0_START (1)
#define SOC_FDUL_PERCLKEN0_gt_pclk_dmmu0_END (1)
#define SOC_FDUL_PERCLKEN0_gt_pclk_dmmu1_START (2)
#define SOC_FDUL_PERCLKEN0_gt_pclk_dmmu1_END (2)
#define SOC_FDUL_PERCLKEN0_gt_pclk_dmmu2_START (3)
#define SOC_FDUL_PERCLKEN0_gt_pclk_dmmu2_END (3)
#define SOC_FDUL_PERCLKEN0_gt_aclk_edma_START (5)
#define SOC_FDUL_PERCLKEN0_gt_aclk_edma_END (5)
#define SOC_FDUL_PERCLKEN0_gt_pclk_imgcap_START (7)
#define SOC_FDUL_PERCLKEN0_gt_pclk_imgcap_END (7)
#define SOC_FDUL_PERCLKEN0_gt_clk_imgcap_START (8)
#define SOC_FDUL_PERCLKEN0_gt_clk_imgcap_END (8)
#define SOC_FDUL_PERCLKEN0_gt_pclk_hifd_core_START (9)
#define SOC_FDUL_PERCLKEN0_gt_pclk_hifd_core_END (9)
#define SOC_FDUL_PERCLKEN0_gt_clk_hifd_core_START (10)
#define SOC_FDUL_PERCLKEN0_gt_clk_hifd_core_END (10)
#define SOC_FDUL_PERCLKEN0_gt_pclk_lb_START (11)
#define SOC_FDUL_PERCLKEN0_gt_pclk_lb_END (11)
#define SOC_FDUL_PERCLKEN0_gt_clk_lb_START (12)
#define SOC_FDUL_PERCLKEN0_gt_clk_lb_END (12)
#define SOC_FDUL_PERCLKEN0_gt_clk_csi_out_START (22)
#define SOC_FDUL_PERCLKEN0_gt_clk_csi_out_END (22)
#define SOC_FDUL_PERCLKEN0_gt_pclk_s3asc_START (23)
#define SOC_FDUL_PERCLKEN0_gt_pclk_s3asc_END (23)
#define SOC_FDUL_PERCLKEN0_gt_pclk_csi_out_START (24)
#define SOC_FDUL_PERCLKEN0_gt_pclk_csi_out_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_pclk_tzpc : 1;
        unsigned int st_pclk_dmmu0 : 1;
        unsigned int st_pclk_dmmu1 : 1;
        unsigned int st_pclk_dmmu2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_aclk_edma : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_pclk_imgcap : 1;
        unsigned int st_clk_imgcap : 1;
        unsigned int st_pclk_hifd_core : 1;
        unsigned int st_clk_hifd_core : 1;
        unsigned int st_pclk_lb : 1;
        unsigned int st_clk_lb : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int st_clk_csi_out : 1;
        unsigned int st_pclk_s3asc_out : 1;
        unsigned int st_pclk_csi_out : 1;
        unsigned int reserved_11 : 7;
    } reg;
} SOC_FDUL_PERSTAT0_UNION;
#endif
#define SOC_FDUL_PERSTAT0_st_pclk_tzpc_START (0)
#define SOC_FDUL_PERSTAT0_st_pclk_tzpc_END (0)
#define SOC_FDUL_PERSTAT0_st_pclk_dmmu0_START (1)
#define SOC_FDUL_PERSTAT0_st_pclk_dmmu0_END (1)
#define SOC_FDUL_PERSTAT0_st_pclk_dmmu1_START (2)
#define SOC_FDUL_PERSTAT0_st_pclk_dmmu1_END (2)
#define SOC_FDUL_PERSTAT0_st_pclk_dmmu2_START (3)
#define SOC_FDUL_PERSTAT0_st_pclk_dmmu2_END (3)
#define SOC_FDUL_PERSTAT0_st_aclk_edma_START (5)
#define SOC_FDUL_PERSTAT0_st_aclk_edma_END (5)
#define SOC_FDUL_PERSTAT0_st_pclk_imgcap_START (7)
#define SOC_FDUL_PERSTAT0_st_pclk_imgcap_END (7)
#define SOC_FDUL_PERSTAT0_st_clk_imgcap_START (8)
#define SOC_FDUL_PERSTAT0_st_clk_imgcap_END (8)
#define SOC_FDUL_PERSTAT0_st_pclk_hifd_core_START (9)
#define SOC_FDUL_PERSTAT0_st_pclk_hifd_core_END (9)
#define SOC_FDUL_PERSTAT0_st_clk_hifd_core_START (10)
#define SOC_FDUL_PERSTAT0_st_clk_hifd_core_END (10)
#define SOC_FDUL_PERSTAT0_st_pclk_lb_START (11)
#define SOC_FDUL_PERSTAT0_st_pclk_lb_END (11)
#define SOC_FDUL_PERSTAT0_st_clk_lb_START (12)
#define SOC_FDUL_PERSTAT0_st_clk_lb_END (12)
#define SOC_FDUL_PERSTAT0_st_clk_csi_out_START (22)
#define SOC_FDUL_PERSTAT0_st_clk_csi_out_END (22)
#define SOC_FDUL_PERSTAT0_st_pclk_s3asc_out_START (23)
#define SOC_FDUL_PERSTAT0_st_pclk_s3asc_out_END (23)
#define SOC_FDUL_PERSTAT0_st_pclk_csi_out_START (24)
#define SOC_FDUL_PERSTAT0_st_pclk_csi_out_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_tzpc : 1;
        unsigned int ip_prst_dmmu0 : 1;
        unsigned int ip_prst_dmmu1 : 1;
        unsigned int ip_prst_dmmu2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_arst_edma : 1;
        unsigned int ip_prst_imagecap : 1;
        unsigned int ip_rst_imagecap : 1;
        unsigned int ip_prst_hifd_core : 1;
        unsigned int ip_rst_hifd_core_por : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_prst_lb : 1;
        unsigned int ip_rst_lb : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_csi : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_prst_s3asc : 1;
        unsigned int ip_prst_csi : 1;
        unsigned int reserved_9 : 9;
    } reg;
} SOC_FDUL_PERRSTEN0_UNION;
#endif
#define SOC_FDUL_PERRSTEN0_ip_prst_tzpc_START (1)
#define SOC_FDUL_PERRSTEN0_ip_prst_tzpc_END (1)
#define SOC_FDUL_PERRSTEN0_ip_prst_dmmu0_START (2)
#define SOC_FDUL_PERRSTEN0_ip_prst_dmmu0_END (2)
#define SOC_FDUL_PERRSTEN0_ip_prst_dmmu1_START (3)
#define SOC_FDUL_PERRSTEN0_ip_prst_dmmu1_END (3)
#define SOC_FDUL_PERRSTEN0_ip_prst_dmmu2_START (4)
#define SOC_FDUL_PERRSTEN0_ip_prst_dmmu2_END (4)
#define SOC_FDUL_PERRSTEN0_ip_arst_edma_START (6)
#define SOC_FDUL_PERRSTEN0_ip_arst_edma_END (6)
#define SOC_FDUL_PERRSTEN0_ip_prst_imagecap_START (7)
#define SOC_FDUL_PERRSTEN0_ip_prst_imagecap_END (7)
#define SOC_FDUL_PERRSTEN0_ip_rst_imagecap_START (8)
#define SOC_FDUL_PERRSTEN0_ip_rst_imagecap_END (8)
#define SOC_FDUL_PERRSTEN0_ip_prst_hifd_core_START (9)
#define SOC_FDUL_PERRSTEN0_ip_prst_hifd_core_END (9)
#define SOC_FDUL_PERRSTEN0_ip_rst_hifd_core_por_START (10)
#define SOC_FDUL_PERRSTEN0_ip_rst_hifd_core_por_END (10)
#define SOC_FDUL_PERRSTEN0_ip_prst_lb_START (12)
#define SOC_FDUL_PERRSTEN0_ip_prst_lb_END (12)
#define SOC_FDUL_PERRSTEN0_ip_rst_lb_START (13)
#define SOC_FDUL_PERRSTEN0_ip_rst_lb_END (13)
#define SOC_FDUL_PERRSTEN0_ip_rst_csi_START (19)
#define SOC_FDUL_PERRSTEN0_ip_rst_csi_END (19)
#define SOC_FDUL_PERRSTEN0_ip_prst_s3asc_START (21)
#define SOC_FDUL_PERRSTEN0_ip_prst_s3asc_END (21)
#define SOC_FDUL_PERRSTEN0_ip_prst_csi_START (22)
#define SOC_FDUL_PERRSTEN0_ip_prst_csi_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_tzpc : 1;
        unsigned int ip_prst_dmmu0 : 1;
        unsigned int ip_prst_dmmu1 : 1;
        unsigned int ip_prst_dmmu2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_arst_edma : 1;
        unsigned int ip_prst_imagecap : 1;
        unsigned int ip_rst_imagecap : 1;
        unsigned int ip_prst_hifd_core : 1;
        unsigned int ip_rst_hifd_core_por : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_prst_lb : 1;
        unsigned int ip_rst_lb : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_csi : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_prst_s3asc : 1;
        unsigned int ip_prst_csi : 1;
        unsigned int reserved_9 : 9;
    } reg;
} SOC_FDUL_PERRSTDIS0_UNION;
#endif
#define SOC_FDUL_PERRSTDIS0_ip_prst_tzpc_START (1)
#define SOC_FDUL_PERRSTDIS0_ip_prst_tzpc_END (1)
#define SOC_FDUL_PERRSTDIS0_ip_prst_dmmu0_START (2)
#define SOC_FDUL_PERRSTDIS0_ip_prst_dmmu0_END (2)
#define SOC_FDUL_PERRSTDIS0_ip_prst_dmmu1_START (3)
#define SOC_FDUL_PERRSTDIS0_ip_prst_dmmu1_END (3)
#define SOC_FDUL_PERRSTDIS0_ip_prst_dmmu2_START (4)
#define SOC_FDUL_PERRSTDIS0_ip_prst_dmmu2_END (4)
#define SOC_FDUL_PERRSTDIS0_ip_arst_edma_START (6)
#define SOC_FDUL_PERRSTDIS0_ip_arst_edma_END (6)
#define SOC_FDUL_PERRSTDIS0_ip_prst_imagecap_START (7)
#define SOC_FDUL_PERRSTDIS0_ip_prst_imagecap_END (7)
#define SOC_FDUL_PERRSTDIS0_ip_rst_imagecap_START (8)
#define SOC_FDUL_PERRSTDIS0_ip_rst_imagecap_END (8)
#define SOC_FDUL_PERRSTDIS0_ip_prst_hifd_core_START (9)
#define SOC_FDUL_PERRSTDIS0_ip_prst_hifd_core_END (9)
#define SOC_FDUL_PERRSTDIS0_ip_rst_hifd_core_por_START (10)
#define SOC_FDUL_PERRSTDIS0_ip_rst_hifd_core_por_END (10)
#define SOC_FDUL_PERRSTDIS0_ip_prst_lb_START (12)
#define SOC_FDUL_PERRSTDIS0_ip_prst_lb_END (12)
#define SOC_FDUL_PERRSTDIS0_ip_rst_lb_START (13)
#define SOC_FDUL_PERRSTDIS0_ip_rst_lb_END (13)
#define SOC_FDUL_PERRSTDIS0_ip_rst_csi_START (19)
#define SOC_FDUL_PERRSTDIS0_ip_rst_csi_END (19)
#define SOC_FDUL_PERRSTDIS0_ip_prst_s3asc_START (21)
#define SOC_FDUL_PERRSTDIS0_ip_prst_s3asc_END (21)
#define SOC_FDUL_PERRSTDIS0_ip_prst_csi_START (22)
#define SOC_FDUL_PERRSTDIS0_ip_prst_csi_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_tzpc : 1;
        unsigned int ip_prst_dmmu0 : 1;
        unsigned int ip_prst_dmmu1 : 1;
        unsigned int ip_prst_dmmu2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_arst_edma : 1;
        unsigned int ip_prst_imagecap : 1;
        unsigned int ip_rst_imagecap : 1;
        unsigned int ip_prst_hifd_core : 1;
        unsigned int ip_rst_hifd_core_por : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_prst_lb : 1;
        unsigned int ip_rst_lb : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_csi : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_prst_s3asc : 1;
        unsigned int ip_prst_csi : 1;
        unsigned int reserved_9 : 9;
    } reg;
} SOC_FDUL_PERRSTSTAT0_UNION;
#endif
#define SOC_FDUL_PERRSTSTAT0_ip_prst_tzpc_START (1)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_tzpc_END (1)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_dmmu0_START (2)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_dmmu0_END (2)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_dmmu1_START (3)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_dmmu1_END (3)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_dmmu2_START (4)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_dmmu2_END (4)
#define SOC_FDUL_PERRSTSTAT0_ip_arst_edma_START (6)
#define SOC_FDUL_PERRSTSTAT0_ip_arst_edma_END (6)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_imagecap_START (7)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_imagecap_END (7)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_imagecap_START (8)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_imagecap_END (8)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_hifd_core_START (9)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_hifd_core_END (9)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_hifd_core_por_START (10)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_hifd_core_por_END (10)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_lb_START (12)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_lb_END (12)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_lb_START (13)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_lb_END (13)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_csi_START (19)
#define SOC_FDUL_PERRSTSTAT0_ip_rst_csi_END (19)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_s3asc_START (21)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_s3asc_END (21)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_csi_START (22)
#define SOC_FDUL_PERRSTSTAT0_ip_prst_csi_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_clk_imgcap : 4;
        unsigned int div_clk_hifd_core : 2;
        unsigned int reserved_0 : 2;
        unsigned int div_pclk_sys_bus : 2;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_FDUL_CLKDIV0_UNION;
#endif
#define SOC_FDUL_CLKDIV0_div_clk_imgcap_START (0)
#define SOC_FDUL_CLKDIV0_div_clk_imgcap_END (3)
#define SOC_FDUL_CLKDIV0_div_clk_hifd_core_START (4)
#define SOC_FDUL_CLKDIV0_div_clk_hifd_core_END (5)
#define SOC_FDUL_CLKDIV0_div_pclk_sys_bus_START (8)
#define SOC_FDUL_CLKDIV0_div_pclk_sys_bus_END (9)
#define SOC_FDUL_CLKDIV0_bitmasken_START (16)
#define SOC_FDUL_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int sel_clk_hifd_core : 1;
        unsigned int reserved_1 : 1;
        unsigned int sel_clk_noc_hifdul : 4;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_FDUL_CLKDIV1_UNION;
#endif
#define SOC_FDUL_CLKDIV1_sel_clk_hifd_core_START (1)
#define SOC_FDUL_CLKDIV1_sel_clk_hifd_core_END (1)
#define SOC_FDUL_CLKDIV1_sel_clk_noc_hifdul_START (3)
#define SOC_FDUL_CLKDIV1_sel_clk_noc_hifdul_END (6)
#define SOC_FDUL_CLKDIV1_bitmasken_START (16)
#define SOC_FDUL_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int sc_gt_clk_hifd_core : 1;
        unsigned int reserved_1 : 1;
        unsigned int sc_gt_clk_imgcap : 1;
        unsigned int reserved_2 : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_FDUL_CLKDIV2_UNION;
#endif
#define SOC_FDUL_CLKDIV2_sc_gt_clk_hifd_core_START (1)
#define SOC_FDUL_CLKDIV2_sc_gt_clk_hifd_core_END (1)
#define SOC_FDUL_CLKDIV2_sc_gt_clk_imgcap_START (3)
#define SOC_FDUL_CLKDIV2_sc_gt_clk_imgcap_END (3)
#define SOC_FDUL_CLKDIV2_bitmasken_START (16)
#define SOC_FDUL_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edma_clk_force_en0 : 1;
        unsigned int edma_clk_force_en1 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_EDMA_CLK_FORCE_ENABLE_UNION;
#endif
#define SOC_FDUL_EDMA_CLK_FORCE_ENABLE_edma_clk_force_en0_START (0)
#define SOC_FDUL_EDMA_CLK_FORCE_ENABLE_edma_clk_force_en0_END (0)
#define SOC_FDUL_EDMA_CLK_FORCE_ENABLE_edma_clk_force_en1_START (1)
#define SOC_FDUL_EDMA_CLK_FORCE_ENABLE_edma_clk_force_en1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiny_clk_gap : 32;
    } reg;
} SOC_FDUL_TINY_CLK_GAP_UNION;
#endif
#define SOC_FDUL_TINY_CLK_GAP_tiny_clk_gap_START (0)
#define SOC_FDUL_TINY_CLK_GAP_tiny_clk_gap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_ack_clk_noc_hifdul_sw : 4;
        unsigned int reserved_0 : 2;
        unsigned int sw_ack_clk_hifd_core_sw : 2;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 20;
    } reg;
} SOC_FDUL_PERI_STAT0_UNION;
#endif
#define SOC_FDUL_PERI_STAT0_sw_ack_clk_noc_hifdul_sw_START (0)
#define SOC_FDUL_PERI_STAT0_sw_ack_clk_noc_hifdul_sw_END (3)
#define SOC_FDUL_PERI_STAT0_sw_ack_clk_hifd_core_sw_START (6)
#define SOC_FDUL_PERI_STAT0_sw_ack_clk_hifd_core_sw_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int tzpc_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int lb_clkrst_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int imgcap_clkrst_bypass : 1;
        unsigned int edma_clkrst_bypass : 1;
        unsigned int dmmu0_clkrst_bypass : 1;
        unsigned int dmmu1_clkrst_bypass : 1;
        unsigned int dmmu2_clkrst_bypass : 1;
        unsigned int reserved_3 : 1;
        unsigned int hifd_core_clkrst_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int csi_clkrst_bypass : 1;
        unsigned int s3asc_clkrst_bypass : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
    } reg;
} SOC_FDUL_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_FDUL_IPCLKRST_BYPASS0_tzpc_clkrst_bypass_START (1)
#define SOC_FDUL_IPCLKRST_BYPASS0_tzpc_clkrst_bypass_END (1)
#define SOC_FDUL_IPCLKRST_BYPASS0_lb_clkrst_bypass_START (3)
#define SOC_FDUL_IPCLKRST_BYPASS0_lb_clkrst_bypass_END (3)
#define SOC_FDUL_IPCLKRST_BYPASS0_imgcap_clkrst_bypass_START (5)
#define SOC_FDUL_IPCLKRST_BYPASS0_imgcap_clkrst_bypass_END (5)
#define SOC_FDUL_IPCLKRST_BYPASS0_edma_clkrst_bypass_START (6)
#define SOC_FDUL_IPCLKRST_BYPASS0_edma_clkrst_bypass_END (6)
#define SOC_FDUL_IPCLKRST_BYPASS0_dmmu0_clkrst_bypass_START (7)
#define SOC_FDUL_IPCLKRST_BYPASS0_dmmu0_clkrst_bypass_END (7)
#define SOC_FDUL_IPCLKRST_BYPASS0_dmmu1_clkrst_bypass_START (8)
#define SOC_FDUL_IPCLKRST_BYPASS0_dmmu1_clkrst_bypass_END (8)
#define SOC_FDUL_IPCLKRST_BYPASS0_dmmu2_clkrst_bypass_START (9)
#define SOC_FDUL_IPCLKRST_BYPASS0_dmmu2_clkrst_bypass_END (9)
#define SOC_FDUL_IPCLKRST_BYPASS0_hifd_core_clkrst_bypass_START (11)
#define SOC_FDUL_IPCLKRST_BYPASS0_hifd_core_clkrst_bypass_END (11)
#define SOC_FDUL_IPCLKRST_BYPASS0_csi_clkrst_bypass_START (14)
#define SOC_FDUL_IPCLKRST_BYPASS0_csi_clkrst_bypass_END (14)
#define SOC_FDUL_IPCLKRST_BYPASS0_s3asc_clkrst_bypass_START (15)
#define SOC_FDUL_IPCLKRST_BYPASS0_s3asc_clkrst_bypass_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_mem_ctrl_sp : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_FDUL_LB_MEM_CTRL_SP_UNION;
#endif
#define SOC_FDUL_LB_MEM_CTRL_SP_lb_mem_ctrl_sp_START (0)
#define SOC_FDUL_LB_MEM_CTRL_SP_lb_mem_ctrl_sp_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aicifu_mem_ctrl_sp : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_FDUL_AIC_IFU_MEM_CTRL_SP_UNION;
#endif
#define SOC_FDUL_AIC_IFU_MEM_CTRL_SP_aicifu_mem_ctrl_sp_START (0)
#define SOC_FDUL_AIC_IFU_MEM_CTRL_SP_aicifu_mem_ctrl_sp_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aicmte_mem_ctrl_sp : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_FDUL_AIC_MTE_MEM_CTRL_SP_UNION;
#endif
#define SOC_FDUL_AIC_MTE_MEM_CTRL_SP_aicmte_mem_ctrl_sp_START (0)
#define SOC_FDUL_AIC_MTE_MEM_CTRL_SP_aicmte_mem_ctrl_sp_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aicvec_mem_ctrl_sp : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_FDUL_AIC_VEC_MEM_CTRL_SP_UNION;
#endif
#define SOC_FDUL_AIC_VEC_MEM_CTRL_SP_aicvec_mem_ctrl_sp_START (0)
#define SOC_FDUL_AIC_VEC_MEM_CTRL_SP_aicvec_mem_ctrl_sp_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aicccu_mem_ctrl_sp : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_FDUL_AIC_CCU_MEM_CTRL_SP_UNION;
#endif
#define SOC_FDUL_AIC_CCU_MEM_CTRL_SP_aicccu_mem_ctrl_sp_START (0)
#define SOC_FDUL_AIC_CCU_MEM_CTRL_SP_aicccu_mem_ctrl_sp_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int edma_mem_ctrl_tp : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_EDMA_MEM_CTRL_TP_UNION;
#endif
#define SOC_FDUL_EDMA_MEM_CTRL_TP_edma_mem_ctrl_tp_START (0)
#define SOC_FDUL_EDMA_MEM_CTRL_TP_edma_mem_ctrl_tp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aiccube_mem_ctrl_tp : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_AIC_CUBE_MEM_CTRL_TP_UNION;
#endif
#define SOC_FDUL_AIC_CUBE_MEM_CTRL_TP_aiccube_mem_ctrl_tp_START (0)
#define SOC_FDUL_AIC_CUBE_MEM_CTRL_TP_aiccube_mem_ctrl_tp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aicmte_mem_ctrl_tp : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FDUL_AIC_MTE_MEM_CTRL_TP_UNION;
#endif
#define SOC_FDUL_AIC_MTE_MEM_CTRL_TP_aicmte_mem_ctrl_tp_START (0)
#define SOC_FDUL_AIC_MTE_MEM_CTRL_TP_aicmte_mem_ctrl_tp_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_aobus_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_CLK_AOBUS_EN_UNION;
#endif
#define SOC_FDUL_CLK_AOBUS_EN_clk_aobus_en_START (0)
#define SOC_FDUL_CLK_AOBUS_EN_clk_aobus_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hifd_ul_fll_ctrl : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_FDUL_FLL_CTRL_UNION;
#endif
#define SOC_FDUL_FLL_CTRL_hifd_ul_fll_ctrl_START (0)
#define SOC_FDUL_FLL_CTRL_hifd_ul_fll_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ar_icfg_bwc_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int ar_icfg_bwc_bandwidth : 13;
        unsigned int reserved_1 : 1;
        unsigned int ar_icfg_bwc_en : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_FDUL_AR_BANDWID_CTRL_UNION;
#endif
#define SOC_FDUL_AR_BANDWID_CTRL_ar_icfg_bwc_saturation_START (0)
#define SOC_FDUL_AR_BANDWID_CTRL_ar_icfg_bwc_saturation_END (13)
#define SOC_FDUL_AR_BANDWID_CTRL_ar_icfg_bwc_bandwidth_START (16)
#define SOC_FDUL_AR_BANDWID_CTRL_ar_icfg_bwc_bandwidth_END (28)
#define SOC_FDUL_AR_BANDWID_CTRL_ar_icfg_bwc_en_START (30)
#define SOC_FDUL_AR_BANDWID_CTRL_ar_icfg_bwc_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aw_icfg_bwc_saturation : 14;
        unsigned int reserved_0 : 2;
        unsigned int aw_icfg_bwc_bandwidth : 13;
        unsigned int reserved_1 : 1;
        unsigned int aw_icfg_bwc_en : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_FDUL_AW_BANDWID_CTRL_UNION;
#endif
#define SOC_FDUL_AW_BANDWID_CTRL_aw_icfg_bwc_saturation_START (0)
#define SOC_FDUL_AW_BANDWID_CTRL_aw_icfg_bwc_saturation_END (13)
#define SOC_FDUL_AW_BANDWID_CTRL_aw_icfg_bwc_bandwidth_START (16)
#define SOC_FDUL_AW_BANDWID_CTRL_aw_icfg_bwc_bandwidth_END (28)
#define SOC_FDUL_AW_BANDWID_CTRL_aw_icfg_bwc_en_START (30)
#define SOC_FDUL_AW_BANDWID_CTRL_aw_icfg_bwc_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ar_icfg_bwc_saturation2 : 14;
        unsigned int reserved_0 : 2;
        unsigned int ar_icfg_bwc_bandwidth2 : 13;
        unsigned int reserved_1 : 1;
        unsigned int ar_icfg_bwc_en2 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_FDUL_AR_BANDWID_CTRL2_UNION;
#endif
#define SOC_FDUL_AR_BANDWID_CTRL2_ar_icfg_bwc_saturation2_START (0)
#define SOC_FDUL_AR_BANDWID_CTRL2_ar_icfg_bwc_saturation2_END (13)
#define SOC_FDUL_AR_BANDWID_CTRL2_ar_icfg_bwc_bandwidth2_START (16)
#define SOC_FDUL_AR_BANDWID_CTRL2_ar_icfg_bwc_bandwidth2_END (28)
#define SOC_FDUL_AR_BANDWID_CTRL2_ar_icfg_bwc_en2_START (30)
#define SOC_FDUL_AR_BANDWID_CTRL2_ar_icfg_bwc_en2_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aw_icfg_bwc_saturation2 : 14;
        unsigned int reserved_0 : 2;
        unsigned int aw_icfg_bwc_bandwidth2 : 13;
        unsigned int reserved_1 : 1;
        unsigned int aw_icfg_bwc_en2 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_FDUL_AW_BANDWID_CTRL2_UNION;
#endif
#define SOC_FDUL_AW_BANDWID_CTRL2_aw_icfg_bwc_saturation2_START (0)
#define SOC_FDUL_AW_BANDWID_CTRL2_aw_icfg_bwc_saturation2_END (13)
#define SOC_FDUL_AW_BANDWID_CTRL2_aw_icfg_bwc_bandwidth2_START (16)
#define SOC_FDUL_AW_BANDWID_CTRL2_aw_icfg_bwc_bandwidth2_END (28)
#define SOC_FDUL_AW_BANDWID_CTRL2_aw_icfg_bwc_en2_START (30)
#define SOC_FDUL_AW_BANDWID_CTRL2_aw_icfg_bwc_en2_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_fd_mst_mainpress : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_NOC_MAINPRESS_UNION;
#endif
#define SOC_FDUL_NOC_MAINPRESS_noc_fd_mst_mainpress_START (0)
#define SOC_FDUL_NOC_MAINPRESS_noc_fd_mst_mainpress_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_ar_ptl_as_ful : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_NOC_AR_PTL_FULL_UNION;
#endif
#define SOC_FDUL_NOC_AR_PTL_FULL_noc_ar_ptl_as_ful_START (0)
#define SOC_FDUL_NOC_AR_PTL_FULL_noc_ar_ptl_as_ful_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_aw_ptl_as_ful : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_NOC_AW_PTL_FULL_UNION;
#endif
#define SOC_FDUL_NOC_AW_PTL_FULL_noc_aw_ptl_as_ful_START (0)
#define SOC_FDUL_NOC_AW_PTL_FULL_noc_aw_ptl_as_ful_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m1_rd_err : 1;
        unsigned int m2_rd_err : 1;
        unsigned int m3_rd_err : 1;
        unsigned int m4_rd_err : 1;
        unsigned int m5_rd_err : 1;
        unsigned int reserved_0: 3;
        unsigned int m1_wr_err : 1;
        unsigned int m2_wr_err : 1;
        unsigned int m3_wr_err : 1;
        unsigned int m4_wr_err : 1;
        unsigned int m5_wr_err : 1;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 16;
    } reg;
} SOC_FDUL_AXI_BUS_ERR_STAT_UNION;
#endif
#define SOC_FDUL_AXI_BUS_ERR_STAT_m1_rd_err_START (0)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m1_rd_err_END (0)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m2_rd_err_START (1)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m2_rd_err_END (1)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m3_rd_err_START (2)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m3_rd_err_END (2)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m4_rd_err_START (3)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m4_rd_err_END (3)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m5_rd_err_START (4)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m5_rd_err_END (4)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m1_wr_err_START (8)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m1_wr_err_END (8)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m2_wr_err_START (9)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m2_wr_err_END (9)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m3_wr_err_START (10)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m3_wr_err_END (10)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m4_wr_err_START (11)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m4_wr_err_END (11)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m5_wr_err_START (12)
#define SOC_FDUL_AXI_BUS_ERR_STAT_m5_wr_err_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_testport_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FDUL_AIC_TESTPORT_SEL_UNION;
#endif
#define SOC_FDUL_AIC_TESTPORT_SEL_aic_testport_sel_START (0)
#define SOC_FDUL_AIC_TESTPORT_SEL_aic_testport_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_testport : 32;
    } reg;
} SOC_FDUL_AIC_TESTPORT_UNION;
#endif
#define SOC_FDUL_AIC_TESTPORT_aic_testport_START (0)
#define SOC_FDUL_AIC_TESTPORT_aic_testport_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aic_reg_clk_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_AIC_CLK_SEL_UNION;
#endif
#define SOC_FDUL_AIC_CLK_SEL_aic_reg_clk_sel_START (0)
#define SOC_FDUL_AIC_CLK_SEL_aic_reg_clk_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdul_err_int_stat : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_ERR_INT_STAT_UNION;
#endif
#define SOC_FDUL_ERR_INT_STAT_fdul_err_int_stat_START (0)
#define SOC_FDUL_ERR_INT_STAT_fdul_err_int_stat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdul_err_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_ERR_INT_MASK_UNION;
#endif
#define SOC_FDUL_ERR_INT_MASK_fdul_err_int_mask_START (0)
#define SOC_FDUL_ERR_INT_MASK_fdul_err_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_axi_s0_cg_en : 1;
        unsigned int dw_axi_s1_cg_en : 1;
        unsigned int dw_axi_s2_cg_en : 1;
        unsigned int dw_axi_s3_cg_en : 1;
        unsigned int dw_axi_m1_cg_en : 1;
        unsigned int dw_axi_m2_cg_en : 1;
        unsigned int dw_axi_m3_cg_en : 1;
        unsigned int dw_axi_m4_cg_en : 1;
        unsigned int dw_axi_m5_cg_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_FDUL_DW_AXI_CG_EN_UNION;
#endif
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s0_cg_en_START (0)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s0_cg_en_END (0)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s1_cg_en_START (1)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s1_cg_en_END (1)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s2_cg_en_START (2)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s2_cg_en_END (2)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s3_cg_en_START (3)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_s3_cg_en_END (3)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m1_cg_en_START (4)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m1_cg_en_END (4)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m2_cg_en_START (5)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m2_cg_en_END (5)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m3_cg_en_START (6)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m3_cg_en_END (6)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m4_cg_en_START (7)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m4_cg_en_END (7)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m5_cg_en_START (8)
#define SOC_FDUL_DW_AXI_CG_EN_dw_axi_m5_cg_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_axi_s1_st : 1;
        unsigned int dw_axi_s2_st : 1;
        unsigned int dw_axi_s3_st : 1;
        unsigned int dw_axi_m1_st : 1;
        unsigned int dw_axi_m2_st : 1;
        unsigned int dw_axi_m3_st : 1;
        unsigned int dw_axi_m4_st : 1;
        unsigned int dw_axi_m5_st : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_FDUL_DW_AXI_STAT_UNION;
#endif
#define SOC_FDUL_DW_AXI_STAT_dw_axi_s1_st_START (0)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_s1_st_END (0)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_s2_st_START (1)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_s2_st_END (1)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_s3_st_START (2)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_s3_st_END (2)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m1_st_START (3)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m1_st_END (3)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m2_st_START (4)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m2_st_END (4)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m3_st_START (5)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m3_st_END (5)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m4_st_START (6)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m4_st_END (6)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m5_st_START (7)
#define SOC_FDUL_DW_AXI_STAT_dw_axi_m5_st_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bus_axi_rst_req : 1;
        unsigned int cfg_force_req_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_AXI_SOFTRST_CTRL_UNION;
#endif
#define SOC_FDUL_AXI_SOFTRST_CTRL_bus_axi_rst_req_START (0)
#define SOC_FDUL_AXI_SOFTRST_CTRL_bus_axi_rst_req_END (0)
#define SOC_FDUL_AXI_SOFTRST_CTRL_cfg_force_req_ack_START (1)
#define SOC_FDUL_AXI_SOFTRST_CTRL_cfg_force_req_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bus_axi_rst_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_AXI_SOFTRST_ACK_UNION;
#endif
#define SOC_FDUL_AXI_SOFTRST_ACK_bus_axi_rst_ack_START (0)
#define SOC_FDUL_AXI_SOFTRST_ACK_bus_axi_rst_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int softrst_state0 : 32;
    } reg;
} SOC_FDUL_AXI_SOFTRST_ST0_UNION;
#endif
#define SOC_FDUL_AXI_SOFTRST_ST0_softrst_state0_START (0)
#define SOC_FDUL_AXI_SOFTRST_ST0_softrst_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int softrst_state1 : 32;
    } reg;
} SOC_FDUL_AXI_SOFTRST_ST1_UNION;
#endif
#define SOC_FDUL_AXI_SOFTRST_ST1_softrst_state1_START (0)
#define SOC_FDUL_AXI_SOFTRST_ST1_softrst_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m5_bus_axi_rst_req : 1;
        unsigned int m5_cfg_force_req_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_M5_AXI_SOFTRST_CTRL_UNION;
#endif
#define SOC_FDUL_M5_AXI_SOFTRST_CTRL_m5_bus_axi_rst_req_START (0)
#define SOC_FDUL_M5_AXI_SOFTRST_CTRL_m5_bus_axi_rst_req_END (0)
#define SOC_FDUL_M5_AXI_SOFTRST_CTRL_m5_cfg_force_req_ack_START (1)
#define SOC_FDUL_M5_AXI_SOFTRST_CTRL_m5_cfg_force_req_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m5_bus_axi_rst_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_M5_AXI_SOFTRST_ACK_UNION;
#endif
#define SOC_FDUL_M5_AXI_SOFTRST_ACK_m5_bus_axi_rst_ack_START (0)
#define SOC_FDUL_M5_AXI_SOFTRST_ACK_m5_bus_axi_rst_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m5_softrst_state0 : 32;
    } reg;
} SOC_FDUL_M5_AXI_SOFTRST_ST0_UNION;
#endif
#define SOC_FDUL_M5_AXI_SOFTRST_ST0_m5_softrst_state0_START (0)
#define SOC_FDUL_M5_AXI_SOFTRST_ST0_m5_softrst_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m5_softrst_state1 : 32;
    } reg;
} SOC_FDUL_M5_AXI_SOFTRST_ST1_UNION;
#endif
#define SOC_FDUL_M5_AXI_SOFTRST_ST1_m5_softrst_state1_START (0)
#define SOC_FDUL_M5_AXI_SOFTRST_ST1_m5_softrst_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m3_bus_axi_rst_req : 1;
        unsigned int m3_cfg_force_req_ack : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_M3_AXI_SOFTRST_CTRL_UNION;
#endif
#define SOC_FDUL_M3_AXI_SOFTRST_CTRL_m3_bus_axi_rst_req_START (0)
#define SOC_FDUL_M3_AXI_SOFTRST_CTRL_m3_bus_axi_rst_req_END (0)
#define SOC_FDUL_M3_AXI_SOFTRST_CTRL_m3_cfg_force_req_ack_START (1)
#define SOC_FDUL_M3_AXI_SOFTRST_CTRL_m3_cfg_force_req_ack_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m3_bus_axi_rst_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_M3_AXI_SOFTRST_ACK_UNION;
#endif
#define SOC_FDUL_M3_AXI_SOFTRST_ACK_m3_bus_axi_rst_ack_START (0)
#define SOC_FDUL_M3_AXI_SOFTRST_ACK_m3_bus_axi_rst_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m3_softrst_state0 : 32;
    } reg;
} SOC_FDUL_M3_AXI_SOFTRST_ST0_UNION;
#endif
#define SOC_FDUL_M3_AXI_SOFTRST_ST0_m3_softrst_state0_START (0)
#define SOC_FDUL_M3_AXI_SOFTRST_ST0_m3_softrst_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m3_softrst_state1 : 32;
    } reg;
} SOC_FDUL_M3_AXI_SOFTRST_ST1_UNION;
#endif
#define SOC_FDUL_M3_AXI_SOFTRST_ST1_m3_softrst_state1_START (0)
#define SOC_FDUL_M3_AXI_SOFTRST_ST1_m3_softrst_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int miniisp_x2x_pack_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_MINIISP_PACK_DISABLE_UNION;
#endif
#define SOC_FDUL_MINIISP_PACK_DISABLE_miniisp_x2x_pack_disable_START (0)
#define SOC_FDUL_MINIISP_PACK_DISABLE_miniisp_x2x_pack_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aicore_x2x_pack_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_AICORE_PACK_DISABLE_UNION;
#endif
#define SOC_FDUL_AICORE_PACK_DISABLE_aicore_x2x_pack_disable_START (0)
#define SOC_FDUL_AICORE_PACK_DISABLE_aicore_x2x_pack_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hwts_x2x_pack_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_HWTS_PACK_DISABLE_UNION;
#endif
#define SOC_FDUL_HWTS_PACK_DISABLE_hwts_x2x_pack_disable_START (0)
#define SOC_FDUL_HWTS_PACK_DISABLE_hwts_x2x_pack_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdul_resv : 32;
    } reg;
} SOC_FDUL_RESERVED_UNION;
#endif
#define SOC_FDUL_RESERVED_fdul_resv_START (0)
#define SOC_FDUL_RESERVED_fdul_resv_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
