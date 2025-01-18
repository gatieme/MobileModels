#ifndef __SOC_MMC0_CRG_INTERFACE_H__
#define __SOC_MMC0_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MMC0_CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_MMC0_CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_MMC0_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_MMC0_CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_MMC0_CRG_CLKDIV0_ADDR(base) ((base) + (0x010UL))
#define SOC_MMC0_CRG_PERRSTEN0_ADDR(base) ((base) + (0x020UL))
#define SOC_MMC0_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x024UL))
#define SOC_MMC0_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028UL))
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x100UL))
#define SOC_MMC0_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500UL))
#define SOC_MMC0_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504UL))
#define SOC_MMC0_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508UL))
#else
#define SOC_MMC0_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_MMC0_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_MMC0_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_MMC0_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_MMC0_CRG_CLKDIV0_ADDR(base) ((base) + (0x010))
#define SOC_MMC0_CRG_PERRSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_MMC0_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_MMC0_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x100))
#define SOC_MMC0_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500))
#define SOC_MMC0_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504))
#define SOC_MMC0_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_mmc0_sysctrl : 1;
        unsigned int gt_clk_usbref : 1;
        unsigned int gt_pclk_io : 1;
        unsigned int gt_pclk_mmc0_ioc : 1;
        unsigned int gt_hclk_usb2drd : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_aclk_noc_usb2drd_asyncbrg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_ulpi_ref : 1;
        unsigned int gt_his_usb20phy_pclk : 1;
        unsigned int gt_usb20_sysctrl_pclk : 1;
        unsigned int reserved_6 : 16;
    } reg;
} SOC_MMC0_CRG_PEREN0_UNION;
#endif
#define SOC_MMC0_CRG_PEREN0_gt_hclk_sd_START (0)
#define SOC_MMC0_CRG_PEREN0_gt_hclk_sd_END (0)
#define SOC_MMC0_CRG_PEREN0_gt_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0_CRG_PEREN0_gt_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0_CRG_PEREN0_gt_clk_usbref_START (2)
#define SOC_MMC0_CRG_PEREN0_gt_clk_usbref_END (2)
#define SOC_MMC0_CRG_PEREN0_gt_pclk_io_START (3)
#define SOC_MMC0_CRG_PEREN0_gt_pclk_io_END (3)
#define SOC_MMC0_CRG_PEREN0_gt_pclk_mmc0_ioc_START (4)
#define SOC_MMC0_CRG_PEREN0_gt_pclk_mmc0_ioc_END (4)
#define SOC_MMC0_CRG_PEREN0_gt_hclk_usb2drd_START (5)
#define SOC_MMC0_CRG_PEREN0_gt_hclk_usb2drd_END (5)
#define SOC_MMC0_CRG_PEREN0_gt_aclk_noc_usb2drd_asyncbrg_START (8)
#define SOC_MMC0_CRG_PEREN0_gt_aclk_noc_usb2drd_asyncbrg_END (8)
#define SOC_MMC0_CRG_PEREN0_gt_clk_ulpi_ref_START (13)
#define SOC_MMC0_CRG_PEREN0_gt_clk_ulpi_ref_END (13)
#define SOC_MMC0_CRG_PEREN0_gt_his_usb20phy_pclk_START (14)
#define SOC_MMC0_CRG_PEREN0_gt_his_usb20phy_pclk_END (14)
#define SOC_MMC0_CRG_PEREN0_gt_usb20_sysctrl_pclk_START (15)
#define SOC_MMC0_CRG_PEREN0_gt_usb20_sysctrl_pclk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_mmc0_sysctrl : 1;
        unsigned int gt_clk_usbref : 1;
        unsigned int gt_pclk_io : 1;
        unsigned int gt_pclk_mmc0_ioc : 1;
        unsigned int gt_hclk_usb2drd : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_aclk_noc_usb2drd_asyncbrg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_ulpi_ref : 1;
        unsigned int gt_his_usb20phy_pclk : 1;
        unsigned int gt_usb20_sysctrl_pclk : 1;
        unsigned int reserved_6 : 16;
    } reg;
} SOC_MMC0_CRG_PERDIS0_UNION;
#endif
#define SOC_MMC0_CRG_PERDIS0_gt_hclk_sd_START (0)
#define SOC_MMC0_CRG_PERDIS0_gt_hclk_sd_END (0)
#define SOC_MMC0_CRG_PERDIS0_gt_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0_CRG_PERDIS0_gt_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0_CRG_PERDIS0_gt_clk_usbref_START (2)
#define SOC_MMC0_CRG_PERDIS0_gt_clk_usbref_END (2)
#define SOC_MMC0_CRG_PERDIS0_gt_pclk_io_START (3)
#define SOC_MMC0_CRG_PERDIS0_gt_pclk_io_END (3)
#define SOC_MMC0_CRG_PERDIS0_gt_pclk_mmc0_ioc_START (4)
#define SOC_MMC0_CRG_PERDIS0_gt_pclk_mmc0_ioc_END (4)
#define SOC_MMC0_CRG_PERDIS0_gt_hclk_usb2drd_START (5)
#define SOC_MMC0_CRG_PERDIS0_gt_hclk_usb2drd_END (5)
#define SOC_MMC0_CRG_PERDIS0_gt_aclk_noc_usb2drd_asyncbrg_START (8)
#define SOC_MMC0_CRG_PERDIS0_gt_aclk_noc_usb2drd_asyncbrg_END (8)
#define SOC_MMC0_CRG_PERDIS0_gt_clk_ulpi_ref_START (13)
#define SOC_MMC0_CRG_PERDIS0_gt_clk_ulpi_ref_END (13)
#define SOC_MMC0_CRG_PERDIS0_gt_his_usb20phy_pclk_START (14)
#define SOC_MMC0_CRG_PERDIS0_gt_his_usb20phy_pclk_END (14)
#define SOC_MMC0_CRG_PERDIS0_gt_usb20_sysctrl_pclk_START (15)
#define SOC_MMC0_CRG_PERDIS0_gt_usb20_sysctrl_pclk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_mmc0_sysctrl : 1;
        unsigned int gt_clk_usbref : 1;
        unsigned int gt_pclk_io : 1;
        unsigned int gt_pclk_mmc0_ioc : 1;
        unsigned int gt_hclk_usb2drd : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_aclk_noc_usb2drd_asyncbrg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_ulpi_ref : 1;
        unsigned int gt_his_usb20phy_pclk : 1;
        unsigned int gt_usb20_sysctrl_pclk : 1;
        unsigned int reserved_6 : 16;
    } reg;
} SOC_MMC0_CRG_PERCLKEN0_UNION;
#endif
#define SOC_MMC0_CRG_PERCLKEN0_gt_hclk_sd_START (0)
#define SOC_MMC0_CRG_PERCLKEN0_gt_hclk_sd_END (0)
#define SOC_MMC0_CRG_PERCLKEN0_gt_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0_CRG_PERCLKEN0_gt_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0_CRG_PERCLKEN0_gt_clk_usbref_START (2)
#define SOC_MMC0_CRG_PERCLKEN0_gt_clk_usbref_END (2)
#define SOC_MMC0_CRG_PERCLKEN0_gt_pclk_io_START (3)
#define SOC_MMC0_CRG_PERCLKEN0_gt_pclk_io_END (3)
#define SOC_MMC0_CRG_PERCLKEN0_gt_pclk_mmc0_ioc_START (4)
#define SOC_MMC0_CRG_PERCLKEN0_gt_pclk_mmc0_ioc_END (4)
#define SOC_MMC0_CRG_PERCLKEN0_gt_hclk_usb2drd_START (5)
#define SOC_MMC0_CRG_PERCLKEN0_gt_hclk_usb2drd_END (5)
#define SOC_MMC0_CRG_PERCLKEN0_gt_aclk_noc_usb2drd_asyncbrg_START (8)
#define SOC_MMC0_CRG_PERCLKEN0_gt_aclk_noc_usb2drd_asyncbrg_END (8)
#define SOC_MMC0_CRG_PERCLKEN0_gt_clk_ulpi_ref_START (13)
#define SOC_MMC0_CRG_PERCLKEN0_gt_clk_ulpi_ref_END (13)
#define SOC_MMC0_CRG_PERCLKEN0_gt_his_usb20phy_pclk_START (14)
#define SOC_MMC0_CRG_PERCLKEN0_gt_his_usb20phy_pclk_END (14)
#define SOC_MMC0_CRG_PERCLKEN0_gt_usb20_sysctrl_pclk_START (15)
#define SOC_MMC0_CRG_PERCLKEN0_gt_usb20_sysctrl_pclk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_hclk_sd : 1;
        unsigned int st_pclk_mmc0_sysctrl : 1;
        unsigned int st_clk_usbref : 1;
        unsigned int st_pclk_io : 1;
        unsigned int st_pclk_mmc0_ioc : 1;
        unsigned int st_hclk_usb2drd : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_aclk_noc_usb2drd_asyncbrg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_clk_ulpi_ref : 1;
        unsigned int st_his_usb20phy_pclk : 1;
        unsigned int st_usb20_sysctrl_pclk : 1;
        unsigned int reserved_6 : 16;
    } reg;
} SOC_MMC0_CRG_PERSTAT0_UNION;
#endif
#define SOC_MMC0_CRG_PERSTAT0_st_hclk_sd_START (0)
#define SOC_MMC0_CRG_PERSTAT0_st_hclk_sd_END (0)
#define SOC_MMC0_CRG_PERSTAT0_st_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0_CRG_PERSTAT0_st_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0_CRG_PERSTAT0_st_clk_usbref_START (2)
#define SOC_MMC0_CRG_PERSTAT0_st_clk_usbref_END (2)
#define SOC_MMC0_CRG_PERSTAT0_st_pclk_io_START (3)
#define SOC_MMC0_CRG_PERSTAT0_st_pclk_io_END (3)
#define SOC_MMC0_CRG_PERSTAT0_st_pclk_mmc0_ioc_START (4)
#define SOC_MMC0_CRG_PERSTAT0_st_pclk_mmc0_ioc_END (4)
#define SOC_MMC0_CRG_PERSTAT0_st_hclk_usb2drd_START (5)
#define SOC_MMC0_CRG_PERSTAT0_st_hclk_usb2drd_END (5)
#define SOC_MMC0_CRG_PERSTAT0_st_aclk_noc_usb2drd_asyncbrg_START (8)
#define SOC_MMC0_CRG_PERSTAT0_st_aclk_noc_usb2drd_asyncbrg_END (8)
#define SOC_MMC0_CRG_PERSTAT0_st_clk_ulpi_ref_START (13)
#define SOC_MMC0_CRG_PERSTAT0_st_clk_ulpi_ref_END (13)
#define SOC_MMC0_CRG_PERSTAT0_st_his_usb20phy_pclk_START (14)
#define SOC_MMC0_CRG_PERSTAT0_st_his_usb20phy_pclk_END (14)
#define SOC_MMC0_CRG_PERSTAT0_st_usb20_sysctrl_pclk_START (15)
#define SOC_MMC0_CRG_PERSTAT0_st_usb20_sysctrl_pclk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_io : 1;
        unsigned int sc_gt_usbphy_38d4m_ref_clk : 1;
        unsigned int sel_usb19d2m_ref_o : 1;
        unsigned int reserved : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MMC0_CRG_CLKDIV0_UNION;
#endif
#define SOC_MMC0_CRG_CLKDIV0_div_io_START (0)
#define SOC_MMC0_CRG_CLKDIV0_div_io_END (0)
#define SOC_MMC0_CRG_CLKDIV0_sc_gt_usbphy_38d4m_ref_clk_START (1)
#define SOC_MMC0_CRG_CLKDIV0_sc_gt_usbphy_38d4m_ref_clk_END (1)
#define SOC_MMC0_CRG_CLKDIV0_sel_usb19d2m_ref_o_START (2)
#define SOC_MMC0_CRG_CLKDIV0_sel_usb19d2m_ref_o_END (2)
#define SOC_MMC0_CRG_CLKDIV0_bitmasken_START (16)
#define SOC_MMC0_CRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_mmc0_sysctrl : 1;
        unsigned int ip_rst_usb2drd_phy : 1;
        unsigned int ip_prst_mmc0_ioc : 1;
        unsigned int ip_hrst_usb2drd : 1;
        unsigned int ip_rst_usb3otg_32k : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_usb2drd_ahbif : 1;
        unsigned int ip_prst_io : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_usb20phy : 1;
        unsigned int ip_rst_usb20phy_por : 1;
        unsigned int ip_prst_usb20_sysctrl : 1;
        unsigned int ip_rst_ulpi : 1;
        unsigned int ip_rst_utmi : 1;
        unsigned int ip_rst_snp_usb20_vcc : 1;
        unsigned int ip_rst_snp_usb20_bus : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_MMC0_CRG_PERRSTEN0_UNION;
#endif
#define SOC_MMC0_CRG_PERRSTEN0_ip_hrst_sd_START (0)
#define SOC_MMC0_CRG_PERRSTEN0_ip_hrst_sd_END (0)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_sd_START (1)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_sd_END (1)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_mmc0_sysctrl_START (2)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_mmc0_sysctrl_END (2)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb2drd_phy_START (3)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb2drd_phy_END (3)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_mmc0_ioc_START (4)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_mmc0_ioc_END (4)
#define SOC_MMC0_CRG_PERRSTEN0_ip_hrst_usb2drd_START (5)
#define SOC_MMC0_CRG_PERRSTEN0_ip_hrst_usb2drd_END (5)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb3otg_32k_START (6)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb3otg_32k_END (6)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb2drd_ahbif_START (8)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb2drd_ahbif_END (8)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_io_START (9)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_io_END (9)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_usb20phy_START (11)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_usb20phy_END (11)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb20phy_por_START (12)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_usb20phy_por_END (12)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_usb20_sysctrl_START (13)
#define SOC_MMC0_CRG_PERRSTEN0_ip_prst_usb20_sysctrl_END (13)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_ulpi_START (14)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_ulpi_END (14)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_utmi_START (15)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_utmi_END (15)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_snp_usb20_vcc_START (16)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_snp_usb20_vcc_END (16)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_snp_usb20_bus_START (17)
#define SOC_MMC0_CRG_PERRSTEN0_ip_rst_snp_usb20_bus_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_mmc0_sysctrl : 1;
        unsigned int ip_rst_usb2drd_phy : 1;
        unsigned int ip_prst_mmc0_ioc : 1;
        unsigned int ip_hrst_usb2drd : 1;
        unsigned int ip_rst_usb3otg_32k : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_usb2drd_ahbif : 1;
        unsigned int ip_prst_io : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_usb20phy : 1;
        unsigned int ip_rst_usb20phy_por : 1;
        unsigned int ip_prst_usb20_sysctrl : 1;
        unsigned int ip_rst_ulpi : 1;
        unsigned int ip_rst_utmi : 1;
        unsigned int ip_rst_snp_usb20_vcc : 1;
        unsigned int ip_rst_snp_usb20_bus : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_MMC0_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_MMC0_CRG_PERRSTDIS0_ip_hrst_sd_START (0)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_hrst_sd_END (0)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_sd_START (1)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_sd_END (1)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_mmc0_sysctrl_START (2)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_mmc0_sysctrl_END (2)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb2drd_phy_START (3)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb2drd_phy_END (3)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_mmc0_ioc_START (4)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_mmc0_ioc_END (4)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_hrst_usb2drd_START (5)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_hrst_usb2drd_END (5)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb3otg_32k_START (6)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb3otg_32k_END (6)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb2drd_ahbif_START (8)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb2drd_ahbif_END (8)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_io_START (9)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_io_END (9)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_usb20phy_START (11)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_usb20phy_END (11)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb20phy_por_START (12)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_usb20phy_por_END (12)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_usb20_sysctrl_START (13)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_prst_usb20_sysctrl_END (13)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_ulpi_START (14)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_ulpi_END (14)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_utmi_START (15)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_utmi_END (15)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_snp_usb20_vcc_START (16)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_snp_usb20_vcc_END (16)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_snp_usb20_bus_START (17)
#define SOC_MMC0_CRG_PERRSTDIS0_ip_rst_snp_usb20_bus_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_mmc0_sysctrl : 1;
        unsigned int ip_rst_usb2drd_phy : 1;
        unsigned int ip_prst_mmc0_ioc : 1;
        unsigned int ip_hrst_usb2drd : 1;
        unsigned int ip_rst_usb3otg_32k : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_usb2drd_ahbif : 1;
        unsigned int ip_prst_io : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_prst_usb20phy : 1;
        unsigned int ip_rst_usb20phy_por : 1;
        unsigned int ip_prst_usb20_sysctrl : 1;
        unsigned int ip_rst_ulpi : 1;
        unsigned int ip_rst_utmi : 1;
        unsigned int ip_rst_snp_usb20_vcc : 1;
        unsigned int ip_rst_snp_usb20_bus : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_MMC0_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_hrst_sd_START (0)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_hrst_sd_END (0)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_sd_START (1)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_sd_END (1)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_mmc0_sysctrl_START (2)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_mmc0_sysctrl_END (2)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb2drd_phy_START (3)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb2drd_phy_END (3)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_mmc0_ioc_START (4)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_mmc0_ioc_END (4)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_hrst_usb2drd_START (5)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_hrst_usb2drd_END (5)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb3otg_32k_START (6)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb3otg_32k_END (6)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb2drd_ahbif_START (8)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb2drd_ahbif_END (8)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_io_START (9)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_io_END (9)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_usb20phy_START (11)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_usb20phy_END (11)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb20phy_por_START (12)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_usb20phy_por_END (12)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_usb20_sysctrl_START (13)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_prst_usb20_sysctrl_END (13)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_ulpi_START (14)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_ulpi_END (14)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_utmi_START (15)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_utmi_END (15)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_snp_usb20_vcc_START (16)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_snp_usb20_vcc_END (16)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_snp_usb20_bus_START (17)
#define SOC_MMC0_CRG_PERRSTSTAT0_ip_rst_snp_usb20_bus_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sd_clkrst_bypass : 1;
        unsigned int io_clkrst_bypass : 1;
        unsigned int mmc0_sysctrl_clkrst_bypass : 1;
        unsigned int mmc0_ioc_clkrst_bypass : 1;
        unsigned int usb2drd_clkrst_bypass : 1;
        unsigned int usb20phy_clkrst_bypass : 1;
        unsigned int usb20_sysctrl_clkrst_bypass : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_MMC0_CRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_sd_clkrst_bypass_START (0)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_sd_clkrst_bypass_END (0)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_io_clkrst_bypass_START (1)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_io_clkrst_bypass_END (1)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_mmc0_sysctrl_clkrst_bypass_START (2)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_mmc0_sysctrl_clkrst_bypass_END (2)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_mmc0_ioc_clkrst_bypass_START (3)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_mmc0_ioc_clkrst_bypass_END (3)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_usb2drd_clkrst_bypass_START (4)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_usb2drd_clkrst_bypass_END (4)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_usb20phy_clkrst_bypass_START (5)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_usb20phy_clkrst_bypass_END (5)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_usb20_sysctrl_clkrst_bypass_START (6)
#define SOC_MMC0_CRG_IPCLKRST_BYPASS0_usb20_sysctrl_clkrst_bypass_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_usb_nonidle_pend : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MMC0_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MMC0_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_usb_nonidle_pend_START (0)
#define SOC_MMC0_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_usb_nonidle_pend_END (0)
#define SOC_MMC0_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MMC0_CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr_usb_nonidle_pend : 1;
        unsigned int reserved : 15;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MMC0_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MMC0_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_usb_nonidle_pend_START (0)
#define SOC_MMC0_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_usb_nonidle_pend_END (0)
#define SOC_MMC0_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MMC0_CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_usb_nonidle_pend : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MMC0_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_usb_nonidle_pend_START (0)
#define SOC_MMC0_CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_usb_nonidle_pend_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
