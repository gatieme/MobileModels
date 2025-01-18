#ifndef __SOC_FDUL_SECURE_INTERFACE_H__
#define __SOC_FDUL_SECURE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FDUL_Secure_ASC_INT_ADDR(base) ((base) + (0x0100UL))
#define SOC_FDUL_Secure_S3_ASC_INT_ADDR(base) ((base) + (0x0104UL))
#define SOC_FDUL_Secure_NOC_AR_MID_ADDR(base) ((base) + (0x584UL))
#define SOC_FDUL_Secure_NOC_AW_MID_ADDR(base) ((base) + (0x588UL))
#define SOC_FDUL_Secure_DW_AXI_SLV_S_ADDR(base) ((base) + (0xf00UL))
#define SOC_FDUL_Secure_MST_AWPROT_ADDR(base) ((base) + (0xFB0UL))
#define SOC_FDUL_Secure_MST_ARPROT_ADDR(base) ((base) + (0xFB4UL))
#else
#define SOC_FDUL_Secure_ASC_INT_ADDR(base) ((base) + (0x0100))
#define SOC_FDUL_Secure_S3_ASC_INT_ADDR(base) ((base) + (0x0104))
#define SOC_FDUL_Secure_NOC_AR_MID_ADDR(base) ((base) + (0x584))
#define SOC_FDUL_Secure_NOC_AW_MID_ADDR(base) ((base) + (0x588))
#define SOC_FDUL_Secure_DW_AXI_SLV_S_ADDR(base) ((base) + (0xf00))
#define SOC_FDUL_Secure_MST_AWPROT_ADDR(base) ((base) + (0xFB0))
#define SOC_FDUL_Secure_MST_ARPROT_ADDR(base) ((base) + (0xFB4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int asc_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_Secure_ASC_INT_UNION;
#endif
#define SOC_FDUL_Secure_ASC_INT_asc_int_START (0)
#define SOC_FDUL_Secure_ASC_INT_asc_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3_asc_int : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FDUL_Secure_S3_ASC_INT_UNION;
#endif
#define SOC_FDUL_Secure_S3_ASC_INT_s3_asc_int_START (0)
#define SOC_FDUL_Secure_S3_ASC_INT_s3_asc_int_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_fd_mst_aruser : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_FDUL_Secure_NOC_AR_MID_UNION;
#endif
#define SOC_FDUL_Secure_NOC_AR_MID_noc_fd_mst_aruser_START (0)
#define SOC_FDUL_Secure_NOC_AR_MID_noc_fd_mst_aruser_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_fd_mst_awuser : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_FDUL_Secure_NOC_AW_MID_UNION;
#endif
#define SOC_FDUL_Secure_NOC_AW_MID_noc_fd_mst_awuser_START (0)
#define SOC_FDUL_Secure_NOC_AW_MID_noc_fd_mst_awuser_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dw_axi_slv_s : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FDUL_Secure_DW_AXI_SLV_S_UNION;
#endif
#define SOC_FDUL_Secure_DW_AXI_SLV_S_dw_axi_slv_s_START (0)
#define SOC_FDUL_Secure_DW_AXI_SLV_S_dw_axi_slv_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int davinci_tiny_awprot_b1 : 1;
        unsigned int dma_awprot_b1 : 1;
        unsigned int miniisp_awprot_b1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hwts_awprot_b1 : 1;
        unsigned int reserved_2 : 26;
    } reg;
} SOC_FDUL_Secure_MST_AWPROT_UNION;
#endif
#define SOC_FDUL_Secure_MST_AWPROT_davinci_tiny_awprot_b1_START (0)
#define SOC_FDUL_Secure_MST_AWPROT_davinci_tiny_awprot_b1_END (0)
#define SOC_FDUL_Secure_MST_AWPROT_dma_awprot_b1_START (1)
#define SOC_FDUL_Secure_MST_AWPROT_dma_awprot_b1_END (1)
#define SOC_FDUL_Secure_MST_AWPROT_miniisp_awprot_b1_START (2)
#define SOC_FDUL_Secure_MST_AWPROT_miniisp_awprot_b1_END (2)
#define SOC_FDUL_Secure_MST_AWPROT_hwts_awprot_b1_START (5)
#define SOC_FDUL_Secure_MST_AWPROT_hwts_awprot_b1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int davinci_tiny_arprot_b1 : 1;
        unsigned int dma_arprot_b1 : 1;
        unsigned int miniisp_arprot_b1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hwts_arprot_b1 : 1;
        unsigned int reserved_2 : 26;
    } reg;
} SOC_FDUL_Secure_MST_ARPROT_UNION;
#endif
#define SOC_FDUL_Secure_MST_ARPROT_davinci_tiny_arprot_b1_START (0)
#define SOC_FDUL_Secure_MST_ARPROT_davinci_tiny_arprot_b1_END (0)
#define SOC_FDUL_Secure_MST_ARPROT_dma_arprot_b1_START (1)
#define SOC_FDUL_Secure_MST_ARPROT_dma_arprot_b1_END (1)
#define SOC_FDUL_Secure_MST_ARPROT_miniisp_arprot_b1_START (2)
#define SOC_FDUL_Secure_MST_ARPROT_miniisp_arprot_b1_END (2)
#define SOC_FDUL_Secure_MST_ARPROT_hwts_arprot_b1_START (5)
#define SOC_FDUL_Secure_MST_ARPROT_hwts_arprot_b1_END (5)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
