#ifndef __SOC_FDUL_ENHANCE_INTERFACE_H__
#define __SOC_FDUL_ENHANCE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FDUL_Enhance_ENHANCE_ENABLE_ADDR(base) ((base) + (0x0000UL))
#define SOC_FDUL_Enhance_MST_ENHANCE_ADDR(base) ((base) + (0x0004UL))
#define SOC_FDUL_Enhance_FDUL_EPS_INT_MASK_ADDR(base) ((base) + (0x000CUL))
#define SOC_FDUL_Enhance_TZPC_SP_SEC_N_ADDR(base) ((base) + (0x0010UL))
#define SOC_FDUL_Enhance_FDULN_SP_SEC_N_ADDR(base) ((base) + (0x0014UL))
#define SOC_FDUL_Enhance_FDULS_SP_SEC_N_ADDR(base) ((base) + (0x0018UL))
#define SOC_FDUL_Enhance_LBASC_SP_SEC_N_ADDR(base) ((base) + (0x001CUL))
#define SOC_FDUL_Enhance_LBSMC_SP_SEC_N_ADDR(base) ((base) + (0x0020UL))
#define SOC_FDUL_Enhance_MINIISP_SP_SEC_N_ADDR(base) ((base) + (0x0024UL))
#define SOC_FDUL_Enhance_DMA_SP_SEC_N_ADDR(base) ((base) + (0x0028UL))
#define SOC_FDUL_Enhance_DMMU0_SP_SEC_N_ADDR(base) ((base) + (0x002CUL))
#define SOC_FDUL_Enhance_DMMU1_SP_SEC_N_ADDR(base) ((base) + (0x0030UL))
#define SOC_FDUL_Enhance_DMMU2_SP_SEC_N_ADDR(base) ((base) + (0x0034UL))
#define SOC_FDUL_Enhance_S3ASC_SP_SEC_N_ADDR(base) ((base) + (0x0038UL))
#define SOC_FDUL_Enhance_TINY_SP_SEC_N_ADDR(base) ((base) + (0x003CUL))
#define SOC_FDUL_Enhance_CSI_SP_SEC_N_ADDR(base) ((base) + (0x0040UL))
#define SOC_FDUL_Enhance_FDUL_EPS_INT_STAT_ADDR(base) ((base) + (0x080UL))
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_ADDR(base) ((base) + (0x600UL))
#define SOC_FDUL_Enhance_PEREN0_ADDR(base) ((base) + (0x800UL))
#define SOC_FDUL_Enhance_PERDIS0_ADDR(base) ((base) + (0x804UL))
#define SOC_FDUL_Enhance_PERCLKEN0_ADDR(base) ((base) + (0x808UL))
#define SOC_FDUL_Enhance_PERSTAT0_ADDR(base) ((base) + (0x80CUL))
#define SOC_FDUL_Enhance_PERRSTEN0_ADDR(base) ((base) + (0x820UL))
#define SOC_FDUL_Enhance_PERRSTDIS0_ADDR(base) ((base) + (0x824UL))
#define SOC_FDUL_Enhance_PERRSTSTAT0_ADDR(base) ((base) + (0x828UL))
#define SOC_FDUL_Enhance_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x880UL))
#else
#define SOC_FDUL_Enhance_ENHANCE_ENABLE_ADDR(base) ((base) + (0x0000))
#define SOC_FDUL_Enhance_MST_ENHANCE_ADDR(base) ((base) + (0x0004))
#define SOC_FDUL_Enhance_FDUL_EPS_INT_MASK_ADDR(base) ((base) + (0x000C))
#define SOC_FDUL_Enhance_TZPC_SP_SEC_N_ADDR(base) ((base) + (0x0010))
#define SOC_FDUL_Enhance_FDULN_SP_SEC_N_ADDR(base) ((base) + (0x0014))
#define SOC_FDUL_Enhance_FDULS_SP_SEC_N_ADDR(base) ((base) + (0x0018))
#define SOC_FDUL_Enhance_LBASC_SP_SEC_N_ADDR(base) ((base) + (0x001C))
#define SOC_FDUL_Enhance_LBSMC_SP_SEC_N_ADDR(base) ((base) + (0x0020))
#define SOC_FDUL_Enhance_MINIISP_SP_SEC_N_ADDR(base) ((base) + (0x0024))
#define SOC_FDUL_Enhance_DMA_SP_SEC_N_ADDR(base) ((base) + (0x0028))
#define SOC_FDUL_Enhance_DMMU0_SP_SEC_N_ADDR(base) ((base) + (0x002C))
#define SOC_FDUL_Enhance_DMMU1_SP_SEC_N_ADDR(base) ((base) + (0x0030))
#define SOC_FDUL_Enhance_DMMU2_SP_SEC_N_ADDR(base) ((base) + (0x0034))
#define SOC_FDUL_Enhance_S3ASC_SP_SEC_N_ADDR(base) ((base) + (0x0038))
#define SOC_FDUL_Enhance_TINY_SP_SEC_N_ADDR(base) ((base) + (0x003C))
#define SOC_FDUL_Enhance_CSI_SP_SEC_N_ADDR(base) ((base) + (0x0040))
#define SOC_FDUL_Enhance_FDUL_EPS_INT_STAT_ADDR(base) ((base) + (0x080))
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_ADDR(base) ((base) + (0x600))
#define SOC_FDUL_Enhance_PEREN0_ADDR(base) ((base) + (0x800))
#define SOC_FDUL_Enhance_PERDIS0_ADDR(base) ((base) + (0x804))
#define SOC_FDUL_Enhance_PERCLKEN0_ADDR(base) ((base) + (0x808))
#define SOC_FDUL_Enhance_PERSTAT0_ADDR(base) ((base) + (0x80C))
#define SOC_FDUL_Enhance_PERRSTEN0_ADDR(base) ((base) + (0x820))
#define SOC_FDUL_Enhance_PERRSTDIS0_ADDR(base) ((base) + (0x824))
#define SOC_FDUL_Enhance_PERRSTSTAT0_ADDR(base) ((base) + (0x828))
#define SOC_FDUL_Enhance_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x880))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdul_enhance_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_Enhance_ENHANCE_ENABLE_UNION;
#endif
#define SOC_FDUL_Enhance_ENHANCE_ENABLE_fdul_enhance_en_START (0)
#define SOC_FDUL_Enhance_ENHANCE_ENABLE_fdul_enhance_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int davinci_tiny_enhance : 1;
        unsigned int dma_enhance : 1;
        unsigned int miniisp_enhance : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hwts_enhance : 1;
        unsigned int reserved_2 : 26;
    } reg;
} SOC_FDUL_Enhance_MST_ENHANCE_UNION;
#endif
#define SOC_FDUL_Enhance_MST_ENHANCE_davinci_tiny_enhance_START (0)
#define SOC_FDUL_Enhance_MST_ENHANCE_davinci_tiny_enhance_END (0)
#define SOC_FDUL_Enhance_MST_ENHANCE_dma_enhance_START (1)
#define SOC_FDUL_Enhance_MST_ENHANCE_dma_enhance_END (1)
#define SOC_FDUL_Enhance_MST_ENHANCE_miniisp_enhance_START (2)
#define SOC_FDUL_Enhance_MST_ENHANCE_miniisp_enhance_END (2)
#define SOC_FDUL_Enhance_MST_ENHANCE_hwts_enhance_START (5)
#define SOC_FDUL_Enhance_MST_ENHANCE_hwts_enhance_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdul_eps_int_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FDUL_Enhance_FDUL_EPS_INT_MASK_UNION;
#endif
#define SOC_FDUL_Enhance_FDUL_EPS_INT_MASK_fdul_eps_int_mask_START (0)
#define SOC_FDUL_Enhance_FDUL_EPS_INT_MASK_fdul_eps_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_TZPC_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_TZPC_SP_SEC_N_tzpc_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_TZPC_SP_SEC_N_tzpc_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fduln_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_FDULN_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_FDULN_SP_SEC_N_fduln_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_FDULN_SP_SEC_N_fduln_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fduls_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_FDULS_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_FDULS_SP_SEC_N_fduls_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_FDULS_SP_SEC_N_fduls_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbasc_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_LBASC_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_LBASC_SP_SEC_N_lbasc_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_LBASC_SP_SEC_N_lbasc_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbsmc_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_LBSMC_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_LBSMC_SP_SEC_N_lbsmc_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_LBSMC_SP_SEC_N_lbsmc_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int miniisp_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_MINIISP_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_MINIISP_SP_SEC_N_miniisp_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_MINIISP_SP_SEC_N_miniisp_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_DMA_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_DMA_SP_SEC_N_dma_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_DMA_SP_SEC_N_dma_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmmu0_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_DMMU0_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_DMMU0_SP_SEC_N_dmmu0_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_DMMU0_SP_SEC_N_dmmu0_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmmu1_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_DMMU1_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_DMMU1_SP_SEC_N_dmmu1_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_DMMU1_SP_SEC_N_dmmu1_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dmmu2_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_DMMU2_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_DMMU2_SP_SEC_N_dmmu2_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_DMMU2_SP_SEC_N_dmmu2_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3asc_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_S3ASC_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_S3ASC_SP_SEC_N_s3asc_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_S3ASC_SP_SEC_N_s3asc_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tiny_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_TINY_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_TINY_SP_SEC_N_tiny_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_TINY_SP_SEC_N_tiny_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csi_sp_sec_n : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FDUL_Enhance_CSI_SP_SEC_N_UNION;
#endif
#define SOC_FDUL_Enhance_CSI_SP_SEC_N_csi_sp_sec_n_START (0)
#define SOC_FDUL_Enhance_CSI_SP_SEC_N_csi_sp_sec_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fdul_eps_int_stat : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FDUL_Enhance_FDUL_EPS_INT_STAT_UNION;
#endif
#define SOC_FDUL_Enhance_FDUL_EPS_INT_STAT_fdul_eps_int_stat_START (0)
#define SOC_FDUL_Enhance_FDUL_EPS_INT_STAT_fdul_eps_int_stat_END (7)
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
} SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_UNION;
#endif
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m1_rd_err_START (0)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m1_rd_err_END (0)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m2_rd_err_START (1)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m2_rd_err_END (1)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m3_rd_err_START (2)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m3_rd_err_END (2)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m4_rd_err_START (3)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m4_rd_err_END (3)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m5_rd_err_START (4)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m5_rd_err_END (4)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m1_wr_err_START (8)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m1_wr_err_END (8)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m2_wr_err_START (9)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m2_wr_err_END (9)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m3_wr_err_START (10)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m3_wr_err_END (10)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m4_wr_err_START (11)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m4_wr_err_END (11)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m5_wr_err_START (12)
#define SOC_FDUL_Enhance_AXI_BUS_ERR_STAT_m5_wr_err_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_etzpc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 7;
    } reg;
} SOC_FDUL_Enhance_PEREN0_UNION;
#endif
#define SOC_FDUL_Enhance_PEREN0_gt_pclk_etzpc_START (0)
#define SOC_FDUL_Enhance_PEREN0_gt_pclk_etzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_etzpc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 7;
    } reg;
} SOC_FDUL_Enhance_PERDIS0_UNION;
#endif
#define SOC_FDUL_Enhance_PERDIS0_gt_pclk_etzpc_START (0)
#define SOC_FDUL_Enhance_PERDIS0_gt_pclk_etzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_etzpc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 7;
    } reg;
} SOC_FDUL_Enhance_PERCLKEN0_UNION;
#endif
#define SOC_FDUL_Enhance_PERCLKEN0_gt_pclk_etzpc_START (0)
#define SOC_FDUL_Enhance_PERCLKEN0_gt_pclk_etzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_pclk_etzpc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 7;
    } reg;
} SOC_FDUL_Enhance_PERSTAT0_UNION;
#endif
#define SOC_FDUL_Enhance_PERSTAT0_st_pclk_etzpc_START (0)
#define SOC_FDUL_Enhance_PERSTAT0_st_pclk_etzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_etzpc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 9;
    } reg;
} SOC_FDUL_Enhance_PERRSTEN0_UNION;
#endif
#define SOC_FDUL_Enhance_PERRSTEN0_ip_prst_etzpc_START (0)
#define SOC_FDUL_Enhance_PERRSTEN0_ip_prst_etzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_etzpc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 9;
    } reg;
} SOC_FDUL_Enhance_PERRSTDIS0_UNION;
#endif
#define SOC_FDUL_Enhance_PERRSTDIS0_ip_prst_etzpc_START (0)
#define SOC_FDUL_Enhance_PERRSTDIS0_ip_prst_etzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_etzpc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 9;
    } reg;
} SOC_FDUL_Enhance_PERRSTSTAT0_UNION;
#endif
#define SOC_FDUL_Enhance_PERRSTSTAT0_ip_prst_etzpc_START (0)
#define SOC_FDUL_Enhance_PERRSTSTAT0_ip_prst_etzpc_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int etzpc_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
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
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
        unsigned int reserved_29 : 1;
        unsigned int reserved_30 : 1;
    } reg;
} SOC_FDUL_Enhance_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_FDUL_Enhance_IPCLKRST_BYPASS0_etzpc_clkrst_bypass_START (0)
#define SOC_FDUL_Enhance_IPCLKRST_BYPASS0_etzpc_clkrst_bypass_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
