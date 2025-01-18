#ifndef __SOC_MMC0CRG_INTERFACE_H__
#define __SOC_MMC0CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MMC0CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_MMC0CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_MMC0CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_MMC0CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_MMC0CRG_PERRSTEN0_ADDR(base) ((base) + (0x020UL))
#define SOC_MMC0CRG_PERRSTDIS0_ADDR(base) ((base) + (0x024UL))
#define SOC_MMC0CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028UL))
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x100UL))
#define SOC_MMC0CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500UL))
#define SOC_MMC0CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504UL))
#define SOC_MMC0CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508UL))
#else
#define SOC_MMC0CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_MMC0CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_MMC0CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_MMC0CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_MMC0CRG_PERRSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_MMC0CRG_PERRSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_MMC0CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0x100))
#define SOC_MMC0CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x500))
#define SOC_MMC0CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x504))
#define SOC_MMC0CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x508))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_mmc0_sysctrl : 1;
        unsigned int gt_aclk_dpctrl : 1;
        unsigned int gt_pclk_dpctrl : 1;
        unsigned int gt_pclk_mmc0_ioc : 1;
        unsigned int gt_hclk_usb3otg_misc : 1;
        unsigned int gt_aclk_usb3otg : 1;
        unsigned int gt_aclk_noc_dpctrl_asyncbrg : 1;
        unsigned int gt_aclk_noc_usb3otg_asyncbrg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 18;
    } reg;
} SOC_MMC0CRG_PEREN0_UNION;
#endif
#define SOC_MMC0CRG_PEREN0_gt_hclk_sd_START (0)
#define SOC_MMC0CRG_PEREN0_gt_hclk_sd_END (0)
#define SOC_MMC0CRG_PEREN0_gt_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0CRG_PEREN0_gt_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0CRG_PEREN0_gt_aclk_dpctrl_START (2)
#define SOC_MMC0CRG_PEREN0_gt_aclk_dpctrl_END (2)
#define SOC_MMC0CRG_PEREN0_gt_pclk_dpctrl_START (3)
#define SOC_MMC0CRG_PEREN0_gt_pclk_dpctrl_END (3)
#define SOC_MMC0CRG_PEREN0_gt_pclk_mmc0_ioc_START (4)
#define SOC_MMC0CRG_PEREN0_gt_pclk_mmc0_ioc_END (4)
#define SOC_MMC0CRG_PEREN0_gt_hclk_usb3otg_misc_START (5)
#define SOC_MMC0CRG_PEREN0_gt_hclk_usb3otg_misc_END (5)
#define SOC_MMC0CRG_PEREN0_gt_aclk_usb3otg_START (6)
#define SOC_MMC0CRG_PEREN0_gt_aclk_usb3otg_END (6)
#define SOC_MMC0CRG_PEREN0_gt_aclk_noc_dpctrl_asyncbrg_START (7)
#define SOC_MMC0CRG_PEREN0_gt_aclk_noc_dpctrl_asyncbrg_END (7)
#define SOC_MMC0CRG_PEREN0_gt_aclk_noc_usb3otg_asyncbrg_START (8)
#define SOC_MMC0CRG_PEREN0_gt_aclk_noc_usb3otg_asyncbrg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_mmc0_sysctrl : 1;
        unsigned int gt_aclk_dpctrl : 1;
        unsigned int gt_pclk_dpctrl : 1;
        unsigned int gt_pclk_mmc0_ioc : 1;
        unsigned int gt_hclk_usb3otg_misc : 1;
        unsigned int gt_aclk_usb3otg : 1;
        unsigned int gt_aclk_noc_dpctrl_asyncbrg : 1;
        unsigned int gt_aclk_noc_usb3otg_asyncbrg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 18;
    } reg;
} SOC_MMC0CRG_PERDIS0_UNION;
#endif
#define SOC_MMC0CRG_PERDIS0_gt_hclk_sd_START (0)
#define SOC_MMC0CRG_PERDIS0_gt_hclk_sd_END (0)
#define SOC_MMC0CRG_PERDIS0_gt_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0CRG_PERDIS0_gt_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_dpctrl_START (2)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_dpctrl_END (2)
#define SOC_MMC0CRG_PERDIS0_gt_pclk_dpctrl_START (3)
#define SOC_MMC0CRG_PERDIS0_gt_pclk_dpctrl_END (3)
#define SOC_MMC0CRG_PERDIS0_gt_pclk_mmc0_ioc_START (4)
#define SOC_MMC0CRG_PERDIS0_gt_pclk_mmc0_ioc_END (4)
#define SOC_MMC0CRG_PERDIS0_gt_hclk_usb3otg_misc_START (5)
#define SOC_MMC0CRG_PERDIS0_gt_hclk_usb3otg_misc_END (5)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_usb3otg_START (6)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_usb3otg_END (6)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_noc_dpctrl_asyncbrg_START (7)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_noc_dpctrl_asyncbrg_END (7)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_noc_usb3otg_asyncbrg_START (8)
#define SOC_MMC0CRG_PERDIS0_gt_aclk_noc_usb3otg_asyncbrg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hclk_sd : 1;
        unsigned int gt_pclk_mmc0_sysctrl : 1;
        unsigned int gt_aclk_dpctrl : 1;
        unsigned int gt_pclk_dpctrl : 1;
        unsigned int gt_pclk_mmc0_ioc : 1;
        unsigned int gt_hclk_usb3otg_misc : 1;
        unsigned int gt_aclk_usb3otg : 1;
        unsigned int gt_aclk_noc_dpctrl_asyncbrg : 1;
        unsigned int gt_aclk_noc_usb3otg_asyncbrg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 18;
    } reg;
} SOC_MMC0CRG_PERCLKEN0_UNION;
#endif
#define SOC_MMC0CRG_PERCLKEN0_gt_hclk_sd_START (0)
#define SOC_MMC0CRG_PERCLKEN0_gt_hclk_sd_END (0)
#define SOC_MMC0CRG_PERCLKEN0_gt_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0CRG_PERCLKEN0_gt_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_dpctrl_START (2)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_dpctrl_END (2)
#define SOC_MMC0CRG_PERCLKEN0_gt_pclk_dpctrl_START (3)
#define SOC_MMC0CRG_PERCLKEN0_gt_pclk_dpctrl_END (3)
#define SOC_MMC0CRG_PERCLKEN0_gt_pclk_mmc0_ioc_START (4)
#define SOC_MMC0CRG_PERCLKEN0_gt_pclk_mmc0_ioc_END (4)
#define SOC_MMC0CRG_PERCLKEN0_gt_hclk_usb3otg_misc_START (5)
#define SOC_MMC0CRG_PERCLKEN0_gt_hclk_usb3otg_misc_END (5)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_usb3otg_START (6)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_usb3otg_END (6)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_noc_dpctrl_asyncbrg_START (7)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_noc_dpctrl_asyncbrg_END (7)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_noc_usb3otg_asyncbrg_START (8)
#define SOC_MMC0CRG_PERCLKEN0_gt_aclk_noc_usb3otg_asyncbrg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_hclk_sd : 1;
        unsigned int st_pclk_mmc0_sysctrl : 1;
        unsigned int st_aclk_dpctrl : 1;
        unsigned int st_pclk_dpctrl : 1;
        unsigned int st_pclk_mmc0_ioc : 1;
        unsigned int st_hclk_usb3otg_misc : 1;
        unsigned int st_aclk_usb3otg : 1;
        unsigned int st_aclk_noc_dpctrl_asyncbrg : 1;
        unsigned int st_aclk_noc_usb3otg_asyncbrg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 18;
    } reg;
} SOC_MMC0CRG_PERSTAT0_UNION;
#endif
#define SOC_MMC0CRG_PERSTAT0_st_hclk_sd_START (0)
#define SOC_MMC0CRG_PERSTAT0_st_hclk_sd_END (0)
#define SOC_MMC0CRG_PERSTAT0_st_pclk_mmc0_sysctrl_START (1)
#define SOC_MMC0CRG_PERSTAT0_st_pclk_mmc0_sysctrl_END (1)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_dpctrl_START (2)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_dpctrl_END (2)
#define SOC_MMC0CRG_PERSTAT0_st_pclk_dpctrl_START (3)
#define SOC_MMC0CRG_PERSTAT0_st_pclk_dpctrl_END (3)
#define SOC_MMC0CRG_PERSTAT0_st_pclk_mmc0_ioc_START (4)
#define SOC_MMC0CRG_PERSTAT0_st_pclk_mmc0_ioc_END (4)
#define SOC_MMC0CRG_PERSTAT0_st_hclk_usb3otg_misc_START (5)
#define SOC_MMC0CRG_PERSTAT0_st_hclk_usb3otg_misc_END (5)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_usb3otg_START (6)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_usb3otg_END (6)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_noc_dpctrl_asyncbrg_START (7)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_noc_dpctrl_asyncbrg_END (7)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_noc_usb3otg_asyncbrg_START (8)
#define SOC_MMC0CRG_PERSTAT0_st_aclk_noc_usb3otg_asyncbrg_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_mmc0_sysctrl : 1;
        unsigned int ip_rst_dpctrl : 1;
        unsigned int ip_prst_mmc0_ioc : 1;
        unsigned int ip_hrst_usb3otg_misc : 1;
        unsigned int ip_rst_usb3otg_32k : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 21;
    } reg;
} SOC_MMC0CRG_PERRSTEN0_UNION;
#endif
#define SOC_MMC0CRG_PERRSTEN0_ip_hrst_sd_START (0)
#define SOC_MMC0CRG_PERRSTEN0_ip_hrst_sd_END (0)
#define SOC_MMC0CRG_PERRSTEN0_ip_rst_sd_START (1)
#define SOC_MMC0CRG_PERRSTEN0_ip_rst_sd_END (1)
#define SOC_MMC0CRG_PERRSTEN0_ip_prst_mmc0_sysctrl_START (2)
#define SOC_MMC0CRG_PERRSTEN0_ip_prst_mmc0_sysctrl_END (2)
#define SOC_MMC0CRG_PERRSTEN0_ip_rst_dpctrl_START (3)
#define SOC_MMC0CRG_PERRSTEN0_ip_rst_dpctrl_END (3)
#define SOC_MMC0CRG_PERRSTEN0_ip_prst_mmc0_ioc_START (4)
#define SOC_MMC0CRG_PERRSTEN0_ip_prst_mmc0_ioc_END (4)
#define SOC_MMC0CRG_PERRSTEN0_ip_hrst_usb3otg_misc_START (5)
#define SOC_MMC0CRG_PERRSTEN0_ip_hrst_usb3otg_misc_END (5)
#define SOC_MMC0CRG_PERRSTEN0_ip_rst_usb3otg_32k_START (6)
#define SOC_MMC0CRG_PERRSTEN0_ip_rst_usb3otg_32k_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_mmc0_sysctrl : 1;
        unsigned int ip_rst_dpctrl : 1;
        unsigned int ip_prst_mmc0_ioc : 1;
        unsigned int ip_hrst_usb3otg_misc : 1;
        unsigned int ip_rst_usb3otg_32k : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 21;
    } reg;
} SOC_MMC0CRG_PERRSTDIS0_UNION;
#endif
#define SOC_MMC0CRG_PERRSTDIS0_ip_hrst_sd_START (0)
#define SOC_MMC0CRG_PERRSTDIS0_ip_hrst_sd_END (0)
#define SOC_MMC0CRG_PERRSTDIS0_ip_rst_sd_START (1)
#define SOC_MMC0CRG_PERRSTDIS0_ip_rst_sd_END (1)
#define SOC_MMC0CRG_PERRSTDIS0_ip_prst_mmc0_sysctrl_START (2)
#define SOC_MMC0CRG_PERRSTDIS0_ip_prst_mmc0_sysctrl_END (2)
#define SOC_MMC0CRG_PERRSTDIS0_ip_rst_dpctrl_START (3)
#define SOC_MMC0CRG_PERRSTDIS0_ip_rst_dpctrl_END (3)
#define SOC_MMC0CRG_PERRSTDIS0_ip_prst_mmc0_ioc_START (4)
#define SOC_MMC0CRG_PERRSTDIS0_ip_prst_mmc0_ioc_END (4)
#define SOC_MMC0CRG_PERRSTDIS0_ip_hrst_usb3otg_misc_START (5)
#define SOC_MMC0CRG_PERRSTDIS0_ip_hrst_usb3otg_misc_END (5)
#define SOC_MMC0CRG_PERRSTDIS0_ip_rst_usb3otg_32k_START (6)
#define SOC_MMC0CRG_PERRSTDIS0_ip_rst_usb3otg_32k_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_hrst_sd : 1;
        unsigned int ip_rst_sd : 1;
        unsigned int ip_prst_mmc0_sysctrl : 1;
        unsigned int ip_rst_dpctrl : 1;
        unsigned int ip_prst_mmc0_ioc : 1;
        unsigned int ip_hrst_usb3otg_misc : 1;
        unsigned int ip_rst_usb3otg_32k : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 21;
    } reg;
} SOC_MMC0CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MMC0CRG_PERRSTSTAT0_ip_hrst_sd_START (0)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_hrst_sd_END (0)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_rst_sd_START (1)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_rst_sd_END (1)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_prst_mmc0_sysctrl_START (2)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_prst_mmc0_sysctrl_END (2)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_rst_dpctrl_START (3)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_rst_dpctrl_END (3)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_prst_mmc0_ioc_START (4)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_prst_mmc0_ioc_END (4)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_hrst_usb3otg_misc_START (5)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_hrst_usb3otg_misc_END (5)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_rst_usb3otg_32k_START (6)
#define SOC_MMC0CRG_PERRSTSTAT0_ip_rst_usb3otg_32k_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sd_clkrst_bypass : 1;
        unsigned int dpctrl_clkrst_bypass : 1;
        unsigned int mmc0_sysctrl_clkrst_bypass : 1;
        unsigned int mmc0_ioc_clkrst_bypass : 1;
        unsigned int usb3otg_misc_clkrst_bypass : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MMC0CRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_sd_clkrst_bypass_START (0)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_sd_clkrst_bypass_END (0)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_dpctrl_clkrst_bypass_START (1)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_dpctrl_clkrst_bypass_END (1)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_mmc0_sysctrl_clkrst_bypass_START (2)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_mmc0_sysctrl_clkrst_bypass_END (2)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_mmc0_ioc_clkrst_bypass_START (3)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_mmc0_ioc_clkrst_bypass_END (3)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_usb3otg_misc_clkrst_bypass_START (4)
#define SOC_MMC0CRG_IPCLKRST_BYPASS0_usb3otg_misc_clkrst_bypass_END (4)
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
} SOC_MMC0CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MMC0CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_usb_nonidle_pend_START (0)
#define SOC_MMC0CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_usb_nonidle_pend_END (0)
#define SOC_MMC0CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MMC0CRG_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
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
} SOC_MMC0CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MMC0CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_usb_nonidle_pend_START (0)
#define SOC_MMC0CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_usb_nonidle_pend_END (0)
#define SOC_MMC0CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MMC0CRG_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_usb_nonidle_pend : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MMC0CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_usb_nonidle_pend_START (0)
#define SOC_MMC0CRG_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_usb_nonidle_pend_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
