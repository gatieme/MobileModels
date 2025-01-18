#ifndef __SOC_MMC0_SYSCTRL_INTERFACE_H__
#define __SOC_MMC0_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + (0x0000UL))
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_ADDR(base) ((base) + (0x0004UL))
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_en_ADDR(base) ((base) + (0x0008UL))
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + (0x000CUL))
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_ADDR(base) ((base) + (0x0010UL))
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_en_ADDR(base) ((base) + (0x0014UL))
#define SOC_MMC0_sysctrl_HSDT1_MID_ADDR(base) ((base) + (0x0800UL))
#define SOC_MMC0_sysctrl_HSDT1_secure_sysctrl_ADDR(base) ((base) + (0x0e00UL))
#else
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + (0x0000))
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_ADDR(base) ((base) + (0x0004))
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_en_ADDR(base) ((base) + (0x0008))
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_ADDR(base) ((base) + (0x000C))
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_ADDR(base) ((base) + (0x0010))
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_en_ADDR(base) ((base) + (0x0014))
#define SOC_MMC0_sysctrl_HSDT1_MID_ADDR(base) ((base) + (0x0800))
#define SOC_MMC0_sysctrl_HSDT1_secure_sysctrl_ADDR(base) ((base) + (0x0e00))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb_axi_wr_bc_icfg_bwc_bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_UNION;
#endif
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_SET_usb_axi_wr_bc_icfg_bwc_bandwidth_START (0)
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_bandwidth_SET_usb_axi_wr_bc_icfg_bwc_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb_axi_wr_bc_icfg_bwc_saturation : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_UNION;
#endif
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_SET_usb_axi_wr_bc_icfg_bwc_saturation_START (0)
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_saturation_SET_usb_axi_wr_bc_icfg_bwc_saturation_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb_axi_wr_bc_icfg_bwc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_en_UNION;
#endif
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_en_SET_usb_axi_wr_bc_icfg_bwc_en_START (0)
#define SOC_MMC0_sysctrl_usb_axi_wr_bc_icfg_bwc_en_SET_usb_axi_wr_bc_icfg_bwc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb_axi_rd_bc_icfg_bwc_bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_UNION;
#endif
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_SET_usb_axi_rd_bc_icfg_bwc_bandwidth_START (0)
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_bandwidth_SET_usb_axi_rd_bc_icfg_bwc_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb_axi_rd_bc_icfg_bwc_saturation : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_UNION;
#endif
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_SET_usb_axi_rd_bc_icfg_bwc_saturation_START (0)
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_saturation_SET_usb_axi_rd_bc_icfg_bwc_saturation_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb_axi_rd_bc_icfg_bwc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_en_UNION;
#endif
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_en_SET_usb_axi_rd_bc_icfg_bwc_en_START (0)
#define SOC_MMC0_sysctrl_usb_axi_rd_bc_icfg_bwc_en_SET_usb_axi_rd_bc_icfg_bwc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SET_usb3otg_mid : 6;
        unsigned int SET_sd3_mid : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_MMC0_sysctrl_HSDT1_MID_UNION;
#endif
#define SOC_MMC0_sysctrl_HSDT1_MID_SET_usb3otg_mid_START (0)
#define SOC_MMC0_sysctrl_HSDT1_MID_SET_usb3otg_mid_END (5)
#define SOC_MMC0_sysctrl_HSDT1_MID_SET_sd3_mid_START (6)
#define SOC_MMC0_sysctrl_HSDT1_MID_SET_sd3_mid_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_secure_n_hsdt1_sysctrl_mid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MMC0_sysctrl_HSDT1_secure_sysctrl_UNION;
#endif
#define SOC_MMC0_sysctrl_HSDT1_secure_sysctrl_tz_secure_n_hsdt1_sysctrl_mid_START (0)
#define SOC_MMC0_sysctrl_HSDT1_secure_sysctrl_tz_secure_n_hsdt1_sysctrl_mid_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
