#ifndef __SOC_CONFIG_INTERFACE_H__
#define __SOC_CONFIG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_CONFIG_DDRENC_CTRL_ADDR(base) ((base) + (0x00))
#define SOC_CONFIG_EFUSEC2HIEPS_CTRL_ADDR(base) ((base) + (0x04))
#define SOC_CONFIG_REG_RESERVED1_ADDR(base) ((base) + (0x08))
#define SOC_CONFIG_REG_RESERVED2_ADDR(base) ((base) + (0x0C))
#define SOC_CONFIG_REG_RESERVED3_ADDR(base) ((base) + (0x10))
#define SOC_CONFIG_QIC_CTRL_ADDR(base) ((base) + (0x14))
#define SOC_CONFIG_REG_RESERVED4_ADDR(base) ((base) + (0x18))
#define SOC_CONFIG_REG_RESERVED5_ADDR(base) ((base) + (0x1C))
#define SOC_CONFIG_REG_RESERVED6_ADDR(base) ((base) + (0x20))
#define SOC_CONFIG_ALARM_CLR_ADDR(base) ((base) + (0x24))
#define SOC_CONFIG_REG_RESERVED7_ADDR(base) ((base) + (0x28))
#define SOC_CONFIG_REG_RESERVED8_ADDR(base) ((base) + (0x2C))
#define SOC_CONFIG_REG_RESERVED9_ADDR(base) ((base) + (0x30))
#define SOC_CONFIG_HIEPS_PEREN0_ADDR(base) ((base) + (0x100))
#define SOC_CONFIG_HIEPS_PERDIS0_ADDR(base) ((base) + (0x104))
#define SOC_CONFIG_HIEPS_PERCLKEN0_ADDR(base) ((base) + (0x108))
#define SOC_CONFIG_HIEPS_PERSTAT0_ADDR(base) ((base) + (0x10C))
#define SOC_CONFIG_PERRSTEN0_ADDR(base) ((base) + (0x110))
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ADDR(base) ((base) + (0x114))
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ADDR(base) ((base) + (0x118))
#define SOC_CONFIG_HIEPS_DIV0_ADDR(base) ((base) + (0x11C))
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_ADDR(base) ((base) + (0x120))
#define SOC_CONFIG_HIEPS_COMMON_CTRL1_ADDR(base) ((base) + (0x124))
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x128))
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_ADDR(base) ((base) + (0x200))
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_ADDR(base) ((base) + (0x204))
#define SOC_CONFIG_HIEPS_MEM_CTRL_HD_ADDR(base) ((base) + (0x208))
#define SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_ADDR(base) ((base) + (0x20C))
#define SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_ADDR(base) ((base) + (0x210))
#define SOC_CONFIG_HIEPS_INTR_MASK_ADDR(base) ((base) + (0x214))
#define SOC_CONFIG_HIEPS_SEC_CTRL_ADDR(base) ((base) + (0x218))
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_ADDR(base) ((base) + (0x21C))
#define SOC_CONFIG_HIEPS_ALARM_STAT_ADDR(base) ((base) + (0x220))
#define SOC_CONFIG_HIEPS_STAT_ADDR(base) ((base) + (0x224))
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_ADDR(base) ((base) + (0x228))
#define SOC_CONFIG_HIEPS_MMU_WID_ADDR(base) ((base) + (0x300))
#define SOC_CONFIG_HIEPS_MMU_RID_ADDR(base) ((base) + (0x304))
#define SOC_CONFIG_HIEPS_MMU_PREID_ADDR(base) ((base) + (0x308))
#define SOC_CONFIG_HIEPS_MMU2_WID_ADDR(base) ((base) + (0x30C))
#define SOC_CONFIG_HIEPS_MMU2_RID_ADDR(base) ((base) + (0x310))
#define SOC_CONFIG_HIEPS_MMU2_PREID_ADDR(base) ((base) + (0x314))
#define SOC_CONFIG_SCE_MST_PRIORITY_ADDR(base) ((base) + (0x400))
#define SOC_CONFIG_HIEPS_HINT_ADDR(base) ((base) + (0x404))
#define SOC_CONFIG_REG_RESERVED10_ADDR(base) ((base) + (0x420))
#define SOC_CONFIG_REG_RESERVED11_ADDR(base) ((base) + (0x424))
#define SOC_CONFIG_HIEPS_RCV_STATE_ADDR(base) ((base) + (0x500))
#define SOC_CONFIG_HIEPS_SMMU_STAT_ADDR(base) ((base) + (0x600))
#define SOC_CONFIG_HIEPS_SMMU_CTRL_ADDR(base) ((base) + (0x604))
#define SOC_CONFIG_HIEPS_SCE1_SID_ADDR(base) ((base) + (0x608))
#define SOC_CONFIG_HIEPS_SCE2_SID_ADDR(base) ((base) + (0x60C))
#define SOC_CONFIG_REG_RW_RES1_ADDR(base) ((base) + (0x800))
#define SOC_CONFIG_REG_RW_RES2_ADDR(base) ((base) + (0x804))
#define SOC_CONFIG_REG_RO_RES1_ADDR(base) ((base) + (0x808))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass_ddrenc : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_CONFIG_DDRENC_CTRL_UNION;
#endif
#define SOC_CONFIG_DDRENC_CTRL_bypass_ddrenc_START (0)
#define SOC_CONFIG_DDRENC_CTRL_bypass_ddrenc_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_ctrl : 32;
    } reg;
} SOC_CONFIG_EFUSEC2HIEPS_CTRL_UNION;
#endif
#define SOC_CONFIG_EFUSEC2HIEPS_CTRL_efusec2hieps_ctrl_START (0)
#define SOC_CONFIG_EFUSEC2HIEPS_CTRL_efusec2hieps_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps2qic_unenc_awMainPress : 2;
        unsigned int axi_unenc_awqos : 4;
        unsigned int axi_unenc_region : 4;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 1;
        unsigned int system_cache_hint_mux : 1;
        unsigned int reserved_3 : 1;
        unsigned int hieps2qic_unenc_arMainPress : 2;
        unsigned int axi_unenc_arqos : 4;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CONFIG_QIC_CTRL_UNION;
#endif
#define SOC_CONFIG_QIC_CTRL_hieps2qic_unenc_awMainPress_START (0)
#define SOC_CONFIG_QIC_CTRL_hieps2qic_unenc_awMainPress_END (1)
#define SOC_CONFIG_QIC_CTRL_axi_unenc_awqos_START (2)
#define SOC_CONFIG_QIC_CTRL_axi_unenc_awqos_END (5)
#define SOC_CONFIG_QIC_CTRL_axi_unenc_region_START (6)
#define SOC_CONFIG_QIC_CTRL_axi_unenc_region_END (9)
#define SOC_CONFIG_QIC_CTRL_system_cache_hint_mux_START (23)
#define SOC_CONFIG_QIC_CTRL_system_cache_hint_mux_END (23)
#define SOC_CONFIG_QIC_CTRL_hieps2qic_unenc_arMainPress_START (25)
#define SOC_CONFIG_QIC_CTRL_hieps2qic_unenc_arMainPress_END (26)
#define SOC_CONFIG_QIC_CTRL_axi_unenc_arqos_START (27)
#define SOC_CONFIG_QIC_CTRL_axi_unenc_arqos_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clr_ddrenc_alarm_pulse : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CONFIG_ALARM_CLR_UNION;
#endif
#define SOC_CONFIG_ALARM_CLR_clr_ddrenc_alarm_pulse_START (0)
#define SOC_CONFIG_ALARM_CLR_clr_ddrenc_alarm_pulse_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_hieps_timer : 1;
        unsigned int gt_pclk_hieps_trng : 1;
        unsigned int gt_clk_hieps_sce_km : 1;
        unsigned int gt_clk_hieps_pke : 1;
        unsigned int gt_clk_hieps_mmu : 1;
        unsigned int gt_clk_ddr_crpt : 1;
        unsigned int gt_clk_hieps_cmp : 1;
        unsigned int gt_clk_hieps_pke2 : 1;
        unsigned int gt_clk_hieps_sce2 : 1;
        unsigned int gt_aclk_hieps_qic : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_CONFIG_HIEPS_PEREN0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PEREN0_gt_pclk_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_mmu_START (4)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_mmu_END (4)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_ddr_crpt_START (5)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_ddr_crpt_END (5)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pke2_START (7)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_pke2_END (7)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce2_START (8)
#define SOC_CONFIG_HIEPS_PEREN0_gt_clk_hieps_sce2_END (8)
#define SOC_CONFIG_HIEPS_PEREN0_gt_aclk_hieps_qic_START (9)
#define SOC_CONFIG_HIEPS_PEREN0_gt_aclk_hieps_qic_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_hieps_timer : 1;
        unsigned int gt_pclk_hieps_trng : 1;
        unsigned int gt_clk_hieps_sce_km : 1;
        unsigned int gt_clk_hieps_pke : 1;
        unsigned int gt_clk_hieps_mmu : 1;
        unsigned int gt_clk_ddr_crpt : 1;
        unsigned int gt_clk_hieps_cmp : 1;
        unsigned int gt_clk_hieps_pke2 : 1;
        unsigned int gt_clk_hieps_sce2 : 1;
        unsigned int gt_aclk_hieps_qic : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_CONFIG_HIEPS_PERDIS0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_pclk_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_mmu_START (4)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_mmu_END (4)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_ddr_crpt_START (5)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_ddr_crpt_END (5)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pke2_START (7)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_pke2_END (7)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce2_START (8)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_clk_hieps_sce2_END (8)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_aclk_hieps_qic_START (9)
#define SOC_CONFIG_HIEPS_PERDIS0_gt_aclk_hieps_qic_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_pclk_hieps_timer : 1;
        unsigned int gt_pclk_hieps_trng : 1;
        unsigned int gt_clk_hieps_sce_km : 1;
        unsigned int gt_clk_hieps_pke : 1;
        unsigned int gt_clk_hieps_mmu : 1;
        unsigned int gt_clk_ddr_crpt : 1;
        unsigned int gt_clk_hieps_cmp : 1;
        unsigned int gt_clk_hieps_pke2 : 1;
        unsigned int gt_clk_hieps_sce2 : 1;
        unsigned int gt_aclk_hieps_qic : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_CONFIG_HIEPS_PERCLKEN0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_pclk_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_mmu_START (4)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_mmu_END (4)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_ddr_crpt_START (5)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_ddr_crpt_END (5)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pke2_START (7)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_pke2_END (7)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce2_START (8)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_clk_hieps_sce2_END (8)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_aclk_hieps_qic_START (9)
#define SOC_CONFIG_HIEPS_PERCLKEN0_gt_aclk_hieps_qic_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_pclk_hieps_timer : 1;
        unsigned int st_pclk_hieps_trng : 1;
        unsigned int st_clk_hieps_sce_km : 1;
        unsigned int st_clk_hieps_pke : 1;
        unsigned int st_clk_hieps_mmu_bclk : 1;
        unsigned int st_clk_ddr_crpt : 1;
        unsigned int st_clk_hieps_cmp : 1;
        unsigned int st_clk_hieps_pke2 : 1;
        unsigned int st_clk_hieps_sce2 : 1;
        unsigned int st_aclk_hieps_qic : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_CONFIG_HIEPS_PERSTAT0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERSTAT0_st_pclk_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_pclk_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_pclk_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_pclk_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_mmu_bclk_START (4)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_mmu_bclk_END (4)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_ddr_crpt_START (5)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_ddr_crpt_END (5)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_pke2_START (7)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_pke2_END (7)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_sce2_START (8)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_clk_hieps_sce2_END (8)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_aclk_hieps_qic_START (9)
#define SOC_CONFIG_HIEPS_PERSTAT0_st_aclk_hieps_qic_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_hieps_timer : 1;
        unsigned int ip_prst_hieps_trng : 1;
        unsigned int ip_rst_hieps_sce_km : 1;
        unsigned int ip_rst_hieps_pke : 1;
        unsigned int ip_rst_hieps_mmu : 1;
        unsigned int ip_rst_ddr_crpt : 1;
        unsigned int ip_rst_hieps_cmp : 1;
        unsigned int ip_rst_hieps_sce2 : 1;
        unsigned int ip_rst_hieps_pke2 : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CONFIG_PERRSTEN0_UNION;
#endif
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_timer_START (0)
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_timer_END (0)
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_trng_START (1)
#define SOC_CONFIG_PERRSTEN0_ip_prst_hieps_trng_END (1)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce_km_START (2)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce_km_END (2)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pke_START (3)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pke_END (3)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_mmu_START (4)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_mmu_END (4)
#define SOC_CONFIG_PERRSTEN0_ip_rst_ddr_crpt_START (5)
#define SOC_CONFIG_PERRSTEN0_ip_rst_ddr_crpt_END (5)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_cmp_START (6)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_cmp_END (6)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce2_START (7)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_sce2_END (7)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pke2_START (8)
#define SOC_CONFIG_PERRSTEN0_ip_rst_hieps_pke2_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_hieps_timer : 1;
        unsigned int ip_prst_hieps_trng : 1;
        unsigned int ip_rst_hieps_sce_km : 1;
        unsigned int ip_rst_hieps_pke : 1;
        unsigned int ip_rst_hieps_mmu : 1;
        unsigned int ip_rst_ddr_crpt : 1;
        unsigned int ip_rst_hieps_cmp : 1;
        unsigned int ip_rst_hieps_sce2 : 1;
        unsigned int ip_rst_hieps_pke2 : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CONFIG_HIEPS_PERRSTDIS0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_prst_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_mmu_START (4)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_mmu_END (4)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_ddr_crpt_START (5)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_ddr_crpt_END (5)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce2_START (7)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_sce2_END (7)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pke2_START (8)
#define SOC_CONFIG_HIEPS_PERRSTDIS0_ip_rst_hieps_pke2_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_hieps_timer : 1;
        unsigned int ip_prst_hieps_trng : 1;
        unsigned int ip_rst_hieps_sce_km : 1;
        unsigned int ip_rst_hieps_pke : 1;
        unsigned int ip_rst_hieps_mmu : 1;
        unsigned int ip_rst_ddr_crpt : 1;
        unsigned int ip_rst_hieps_cmp : 1;
        unsigned int ip_rst_hieps_sce2 : 1;
        unsigned int ip_rst_hieps_pke2 : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CONFIG_HIEPS_PERRSTSTAT0_UNION;
#endif
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_timer_START (0)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_timer_END (0)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_trng_START (1)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_prst_hieps_trng_END (1)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce_km_START (2)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce_km_END (2)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke_START (3)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke_END (3)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_mmu_START (4)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_mmu_END (4)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_ddr_crpt_START (5)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_ddr_crpt_END (5)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_cmp_START (6)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_cmp_END (6)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce2_START (7)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_sce2_END (7)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke2_START (8)
#define SOC_CONFIG_HIEPS_PERRSTSTAT0_ip_rst_hieps_pke2_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_hieps_ahb_bus_tp : 2;
        unsigned int div_hieps_timer : 2;
        unsigned int sc_gt_clk_hieps_ahb_bus : 1;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CONFIG_HIEPS_DIV0_UNION;
#endif
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_ahb_bus_tp_START (0)
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_ahb_bus_tp_END (1)
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_timer_START (2)
#define SOC_CONFIG_HIEPS_DIV0_div_hieps_timer_END (3)
#define SOC_CONFIG_HIEPS_DIV0_sc_gt_clk_hieps_ahb_bus_START (4)
#define SOC_CONFIG_HIEPS_DIV0_sc_gt_clk_hieps_ahb_bus_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timer0_soft_en : 1;
        unsigned int timer1_soft_en : 1;
        unsigned int hieps_timer0_en_sel : 1;
        unsigned int hieps_timer1_en_sel : 1;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CONFIG_HIEPS_COMMON_CTRL0_UNION;
#endif
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer0_soft_en_START (0)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer0_soft_en_END (0)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer1_soft_en_START (1)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_timer1_soft_en_END (1)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer0_en_sel_START (2)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer0_en_sel_END (2)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer1_en_sel_START (3)
#define SOC_CONFIG_HIEPS_COMMON_CTRL0_hieps_timer1_en_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_CONFIG_HIEPS_COMMON_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_timer_clkrst_bypass : 1;
        unsigned int hieps_trng_clkrst_bypass : 1;
        unsigned int hieps_sce_km_clkrst_bypass : 1;
        unsigned int hieps_pke_clkrst_bypass : 1;
        unsigned int hieps_mmu_clkrst_bypass : 1;
        unsigned int hieps_sce2_clkrst_bypass : 1;
        unsigned int hieps_pke2_clkrst_bypass : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_timer_clkrst_bypass_START (0)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_timer_clkrst_bypass_END (0)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_trng_clkrst_bypass_START (1)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_trng_clkrst_bypass_END (1)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce_km_clkrst_bypass_START (2)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce_km_clkrst_bypass_END (2)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pke_clkrst_bypass_START (3)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pke_clkrst_bypass_END (3)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_mmu_clkrst_bypass_START (4)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_mmu_clkrst_bypass_END (4)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce2_clkrst_bypass_START (5)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_sce2_clkrst_bypass_END (5)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pke2_clkrst_bypass_START (6)
#define SOC_CONFIG_HIEPS_IPCLKRST_BYPASS0_hieps_pke2_clkrst_bypass_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_rom_ctrl_ckhe : 1;
        unsigned int hieps_rom_ctrl_ckle : 1;
        unsigned int hieps_rom_ctrl_skp : 2;
        unsigned int hieps_rom_ctrl_dt : 2;
        unsigned int reserved : 26;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_ROM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_ckhe_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_ckhe_END (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_ckle_START (1)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_ckle_END (1)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_skp_START (2)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_skp_END (3)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_dt_START (4)
#define SOC_CONFIG_HIEPS_MEM_CTRL_ROM_hieps_rom_ctrl_dt_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_spram_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_hieps_spram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_SPRAM_hieps_spram_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_hd_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_HD_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_HD_hieps_hd_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_HD_hieps_hd_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_dpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_hieps_dpram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_DPRAM_hieps_dpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_bpram_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_UNION;
#endif
#define SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_hieps_bpram_mem_ctrl_START (0)
#define SOC_CONFIG_HIEPS_MEM_CTRL_BPRAM_hieps_bpram_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int cfg_alarm_km_mask : 1;
        unsigned int cfg_alarm_sce_mask : 1;
        unsigned int cfg_alarm_rsa_mask : 1;
        unsigned int cfg_alarm_ecc_mask : 1;
        unsigned int cfg_alarm_trng_mask : 1;
        unsigned int cfg_int_trng_mask : 1;
        unsigned int reserved_1 : 1;
        unsigned int cfg_alarm_sm9_mask : 1;
        unsigned int cfg_alarm_ddrenc_mask : 1;
        unsigned int cfg_alarm_sce2_mask : 1;
        unsigned int cfg_alarm_rsa3_mask : 1;
        unsigned int cfg_alarm_rsa2_mask : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 15;
    } reg;
} SOC_CONFIG_HIEPS_INTR_MASK_UNION;
#endif
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_km_mask_START (1)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_km_mask_END (1)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce_mask_START (2)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce_mask_END (2)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa_mask_START (3)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa_mask_END (3)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_ecc_mask_START (4)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_ecc_mask_END (4)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_trng_mask_START (5)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_trng_mask_END (5)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_int_trng_mask_START (6)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_int_trng_mask_END (6)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sm9_mask_START (8)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sm9_mask_END (8)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_ddrenc_mask_START (9)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_ddrenc_mask_END (9)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce2_mask_START (10)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_sce2_mask_END (10)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa3_mask_START (11)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa3_mask_END (11)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa2_mask_START (12)
#define SOC_CONFIG_HIEPS_INTR_MASK_cfg_alarm_rsa2_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps2lm_busy : 3;
        unsigned int hieps_perf_stat_en : 1;
        unsigned int hieps2qic_disable : 1;
        unsigned int hieps_perf_stat_en_1 : 1;
        unsigned int cfg_trust2prot_en : 1;
        unsigned int eps_debug_rma_en : 1;
        unsigned int hieps2dmss_sec_lock : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CONFIG_HIEPS_SEC_CTRL_UNION;
#endif
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2lm_busy_START (0)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2lm_busy_END (2)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps_perf_stat_en_START (3)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps_perf_stat_en_END (3)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2qic_disable_START (4)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2qic_disable_END (4)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps_perf_stat_en_1_START (5)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps_perf_stat_en_1_END (5)
#define SOC_CONFIG_HIEPS_SEC_CTRL_cfg_trust2prot_en_START (6)
#define SOC_CONFIG_HIEPS_SEC_CTRL_cfg_trust2prot_en_END (6)
#define SOC_CONFIG_HIEPS_SEC_CTRL_eps_debug_rma_en_START (7)
#define SOC_CONFIG_HIEPS_SEC_CTRL_eps_debug_rma_en_END (7)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2dmss_sec_lock_START (8)
#define SOC_CONFIG_HIEPS_SEC_CTRL_hieps2dmss_sec_lock_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps2qic_enc_awMainPress : 2;
        unsigned int axi_enc_awqos : 4;
        unsigned int axi_enc_region : 4;
        unsigned int hieps2qic_enc_arMainPress : 2;
        unsigned int axi_enc_arqos : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_QIC_ENC_CTRL_UNION;
#endif
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_hieps2qic_enc_awMainPress_START (0)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_hieps2qic_enc_awMainPress_END (1)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_axi_enc_awqos_START (2)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_axi_enc_awqos_END (5)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_axi_enc_region_START (6)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_axi_enc_region_END (9)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_hieps2qic_enc_arMainPress_START (10)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_hieps2qic_enc_arMainPress_END (11)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_axi_enc_arqos_START (12)
#define SOC_CONFIG_HIEPS_QIC_ENC_CTRL_axi_enc_arqos_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_km_stat : 1;
        unsigned int alarm_sce_stat : 1;
        unsigned int alarm_rsa_stat : 1;
        unsigned int alarm_ecc_stat : 1;
        unsigned int alarm_trng_stat : 1;
        unsigned int int_trng_stat : 1;
        unsigned int alarm_sm9_stat : 1;
        unsigned int alarm_ddrenc_stat : 1;
        unsigned int alarm_sce2_stat : 1;
        unsigned int alarm_rsa3_stat : 1;
        unsigned int alarm_rsa2_stat : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_CONFIG_HIEPS_ALARM_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_km_stat_START (0)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_km_stat_END (0)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce_stat_START (1)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce_stat_END (1)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa_stat_START (2)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa_stat_END (2)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_ecc_stat_START (3)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_ecc_stat_END (3)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_trng_stat_START (4)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_trng_stat_END (4)
#define SOC_CONFIG_HIEPS_ALARM_STAT_int_trng_stat_START (5)
#define SOC_CONFIG_HIEPS_ALARM_STAT_int_trng_stat_END (5)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sm9_stat_START (6)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sm9_stat_END (6)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_ddrenc_stat_START (7)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_ddrenc_stat_END (7)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce2_stat_START (8)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_sce2_stat_END (8)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa3_stat_START (9)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa3_stat_END (9)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa2_stat_START (10)
#define SOC_CONFIG_HIEPS_ALARM_STAT_alarm_rsa2_stat_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_lcs_4bit : 4;
        unsigned int hw_rd_finish : 1;
        unsigned int lcs_rma : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CONFIG_HIEPS_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_STAT_hieps_lcs_4bit_START (0)
#define SOC_CONFIG_HIEPS_STAT_hieps_lcs_4bit_END (3)
#define SOC_CONFIG_HIEPS_STAT_hw_rd_finish_START (4)
#define SOC_CONFIG_HIEPS_STAT_hw_rd_finish_END (4)
#define SOC_CONFIG_HIEPS_STAT_lcs_rma_START (5)
#define SOC_CONFIG_HIEPS_STAT_lcs_rma_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eps_debug_disable : 4;
        unsigned int km_debug_disable : 4;
        unsigned int misc2crypto_smx_disable : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_eps_debug_disable_START (0)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_eps_debug_disable_END (3)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_km_debug_disable_START (4)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_km_debug_disable_END (7)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_misc2crypto_smx_disable_START (8)
#define SOC_CONFIG_HIEPS_EFUSE_CTRL_STAT_misc2crypto_smx_disable_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awmmusid_s0 : 8;
        unsigned int awmmussid_s0 : 8;
        unsigned int awmmusecsid_s0 : 1;
        unsigned int awmmussidv_s0 : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_CONFIG_HIEPS_MMU_WID_UNION;
#endif
#define SOC_CONFIG_HIEPS_MMU_WID_awmmusid_s0_START (0)
#define SOC_CONFIG_HIEPS_MMU_WID_awmmusid_s0_END (7)
#define SOC_CONFIG_HIEPS_MMU_WID_awmmussid_s0_START (8)
#define SOC_CONFIG_HIEPS_MMU_WID_awmmussid_s0_END (15)
#define SOC_CONFIG_HIEPS_MMU_WID_awmmusecsid_s0_START (16)
#define SOC_CONFIG_HIEPS_MMU_WID_awmmusecsid_s0_END (16)
#define SOC_CONFIG_HIEPS_MMU_WID_awmmussidv_s0_START (17)
#define SOC_CONFIG_HIEPS_MMU_WID_awmmussidv_s0_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int armmusid_s0 : 8;
        unsigned int armmussid_s0 : 8;
        unsigned int armmusecsid_s0 : 1;
        unsigned int armmussidv_s0 : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_CONFIG_HIEPS_MMU_RID_UNION;
#endif
#define SOC_CONFIG_HIEPS_MMU_RID_armmusid_s0_START (0)
#define SOC_CONFIG_HIEPS_MMU_RID_armmusid_s0_END (7)
#define SOC_CONFIG_HIEPS_MMU_RID_armmussid_s0_START (8)
#define SOC_CONFIG_HIEPS_MMU_RID_armmussid_s0_END (15)
#define SOC_CONFIG_HIEPS_MMU_RID_armmusecsid_s0_START (16)
#define SOC_CONFIG_HIEPS_MMU_RID_armmusecsid_s0_END (16)
#define SOC_CONFIG_HIEPS_MMU_RID_armmussidv_s0_START (17)
#define SOC_CONFIG_HIEPS_MMU_RID_armmussidv_s0_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int armmuswid_s0 : 8;
        unsigned int awmmuswid_s0 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_MMU_PREID_UNION;
#endif
#define SOC_CONFIG_HIEPS_MMU_PREID_armmuswid_s0_START (0)
#define SOC_CONFIG_HIEPS_MMU_PREID_armmuswid_s0_END (7)
#define SOC_CONFIG_HIEPS_MMU_PREID_awmmuswid_s0_START (8)
#define SOC_CONFIG_HIEPS_MMU_PREID_awmmuswid_s0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awmmusid_s1 : 8;
        unsigned int awmmussid_s1 : 8;
        unsigned int awmmusecsid_s1 : 1;
        unsigned int awmmussidv_s1 : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_CONFIG_HIEPS_MMU2_WID_UNION;
#endif
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmusid_s1_START (0)
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmusid_s1_END (7)
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmussid_s1_START (8)
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmussid_s1_END (15)
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmusecsid_s1_START (16)
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmusecsid_s1_END (16)
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmussidv_s1_START (17)
#define SOC_CONFIG_HIEPS_MMU2_WID_awmmussidv_s1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int armmusid_s1 : 8;
        unsigned int armmussid_s1 : 8;
        unsigned int armmusecsid_s1 : 1;
        unsigned int armmussidv_s1 : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_CONFIG_HIEPS_MMU2_RID_UNION;
#endif
#define SOC_CONFIG_HIEPS_MMU2_RID_armmusid_s1_START (0)
#define SOC_CONFIG_HIEPS_MMU2_RID_armmusid_s1_END (7)
#define SOC_CONFIG_HIEPS_MMU2_RID_armmussid_s1_START (8)
#define SOC_CONFIG_HIEPS_MMU2_RID_armmussid_s1_END (15)
#define SOC_CONFIG_HIEPS_MMU2_RID_armmusecsid_s1_START (16)
#define SOC_CONFIG_HIEPS_MMU2_RID_armmusecsid_s1_END (16)
#define SOC_CONFIG_HIEPS_MMU2_RID_armmussidv_s1_START (17)
#define SOC_CONFIG_HIEPS_MMU2_RID_armmussidv_s1_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int armmuswid_s1 : 8;
        unsigned int awmmuswid_s1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_MMU2_PREID_UNION;
#endif
#define SOC_CONFIG_HIEPS_MMU2_PREID_armmuswid_s1_START (0)
#define SOC_CONFIG_HIEPS_MMU2_PREID_armmuswid_s1_END (7)
#define SOC_CONFIG_HIEPS_MMU2_PREID_awmmuswid_s1_START (8)
#define SOC_CONFIG_HIEPS_MMU2_PREID_awmmuswid_s1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce_mst_priority_sce2to2 : 1;
        unsigned int sce2_mst_priority_sce2to2 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CONFIG_SCE_MST_PRIORITY_UNION;
#endif
#define SOC_CONFIG_SCE_MST_PRIORITY_sce_mst_priority_sce2to2_START (0)
#define SOC_CONFIG_SCE_MST_PRIORITY_sce_mst_priority_sce2to2_END (0)
#define SOC_CONFIG_SCE_MST_PRIORITY_sce2_mst_priority_sce2to2_START (1)
#define SOC_CONFIG_SCE_MST_PRIORITY_sce2_mst_priority_sce2to2_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int sce_arhint : 4;
        unsigned int sce_awhint : 4;
        unsigned int sce2_arhint : 4;
        unsigned int sce2_awhint : 4;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_CONFIG_HIEPS_HINT_UNION;
#endif
#define SOC_CONFIG_HIEPS_HINT_sce_arhint_START (8)
#define SOC_CONFIG_HIEPS_HINT_sce_arhint_END (11)
#define SOC_CONFIG_HIEPS_HINT_sce_awhint_START (12)
#define SOC_CONFIG_HIEPS_HINT_sce_awhint_END (15)
#define SOC_CONFIG_HIEPS_HINT_sce2_arhint_START (16)
#define SOC_CONFIG_HIEPS_HINT_sce2_arhint_END (19)
#define SOC_CONFIG_HIEPS_HINT_sce2_awhint_START (20)
#define SOC_CONFIG_HIEPS_HINT_sce2_awhint_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CONFIG_REG_RESERVED11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hieps_rcv_state : 32;
    } reg;
} SOC_CONFIG_HIEPS_RCV_STATE_UNION;
#endif
#define SOC_CONFIG_HIEPS_RCV_STATE_hieps_rcv_state_START (0)
#define SOC_CONFIG_HIEPS_RCV_STATE_hieps_rcv_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_ack : 8;
        unsigned int smmu_idle : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CONFIG_HIEPS_SMMU_STAT_UNION;
#endif
#define SOC_CONFIG_HIEPS_SMMU_STAT_end_ack_START (0)
#define SOC_CONFIG_HIEPS_SMMU_STAT_end_ack_END (7)
#define SOC_CONFIG_HIEPS_SMMU_STAT_smmu_idle_START (8)
#define SOC_CONFIG_HIEPS_SMMU_STAT_smmu_idle_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int end_req : 8;
        unsigned int stream_start : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_CONFIG_HIEPS_SMMU_CTRL_UNION;
#endif
#define SOC_CONFIG_HIEPS_SMMU_CTRL_end_req_START (0)
#define SOC_CONFIG_HIEPS_SMMU_CTRL_end_req_END (7)
#define SOC_CONFIG_HIEPS_SMMU_CTRL_stream_start_START (8)
#define SOC_CONFIG_HIEPS_SMMU_CTRL_stream_start_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsid_sce1 : 5;
        unsigned int awsid_sce1 : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_CONFIG_HIEPS_SCE1_SID_UNION;
#endif
#define SOC_CONFIG_HIEPS_SCE1_SID_arsid_sce1_START (0)
#define SOC_CONFIG_HIEPS_SCE1_SID_arsid_sce1_END (4)
#define SOC_CONFIG_HIEPS_SCE1_SID_awsid_sce1_START (5)
#define SOC_CONFIG_HIEPS_SCE1_SID_awsid_sce1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsid_sce2 : 5;
        unsigned int awsid_sce2 : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_CONFIG_HIEPS_SCE2_SID_UNION;
#endif
#define SOC_CONFIG_HIEPS_SCE2_SID_arsid_sce2_START (0)
#define SOC_CONFIG_HIEPS_SCE2_SID_arsid_sce2_END (4)
#define SOC_CONFIG_HIEPS_SCE2_SID_awsid_sce2_START (5)
#define SOC_CONFIG_HIEPS_SCE2_SID_awsid_sce2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_rw_res1 : 32;
    } reg;
} SOC_CONFIG_REG_RW_RES1_UNION;
#endif
#define SOC_CONFIG_REG_RW_RES1_reg_rw_res1_START (0)
#define SOC_CONFIG_REG_RW_RES1_reg_rw_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_rw_res2 : 32;
    } reg;
} SOC_CONFIG_REG_RW_RES2_UNION;
#endif
#define SOC_CONFIG_REG_RW_RES2_reg_rw_res2_START (0)
#define SOC_CONFIG_REG_RW_RES2_reg_rw_res2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ro_res1 : 32;
    } reg;
} SOC_CONFIG_REG_RO_RES1_UNION;
#endif
#define SOC_CONFIG_REG_RO_RES1_reg_ro_res1_START (0)
#define SOC_CONFIG_REG_RO_RES1_reg_ro_res1_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
