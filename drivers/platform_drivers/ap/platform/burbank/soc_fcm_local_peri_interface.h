#ifndef __SOC_FCM_LOCAL_PERI_INTERFACE_H__
#define __SOC_FCM_LOCAL_PERI_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_PERI_CTRL0_ADDR(base) ((base) + (0x000UL))
#define SOC_FCM_LOCAL_PERI_CTRL1_ADDR(base) ((base) + (0x004UL))
#define SOC_FCM_LOCAL_PERI_CTRL2_ADDR(base) ((base) + (0x008UL))
#define SOC_FCM_LOCAL_PERI_CTRL3_ADDR(base) ((base) + (0x00CUL))
#define SOC_FCM_LOCAL_PERI_CTRL4_ADDR(base) ((base) + (0x010UL))
#define SOC_FCM_LOCAL_PERI_CTRL5_ADDR(base) ((base) + (0x014UL))
#define SOC_FCM_LOCAL_PERI_CTRL6_ADDR(base) ((base) + (0x018UL))
#define SOC_FCM_LOCAL_PERI_CTRL7_ADDR(base) ((base) + (0x01CUL))
#define SOC_FCM_LOCAL_PERI_CTRL8_ADDR(base) ((base) + (0x020UL))
#define SOC_FCM_LOCAL_PERI_CTRL9_ADDR(base) ((base) + (0x024UL))
#define SOC_FCM_LOCAL_PERI_CTRL10_ADDR(base) ((base) + (0x028UL))
#define SOC_FCM_LOCAL_PERI_CTRL11_ADDR(base) ((base) + (0x02CUL))
#define SOC_FCM_LOCAL_PERI_CTRL12_ADDR(base) ((base) + (0x030UL))
#define SOC_FCM_LOCAL_PERI_CTRL13_ADDR(base) ((base) + (0x034UL))
#define SOC_FCM_LOCAL_PERI_CTRL14_ADDR(base) ((base) + (0x038UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + (0x03CUL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + (0x040UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + (0x044UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + (0x048UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + (0x04CUL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + (0x050UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + (0x054UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + (0x058UL))
#define SOC_FCM_LOCAL_PERI_CTRL23_ADDR(base) ((base) + (0x05CUL))
#define SOC_FCM_LOCAL_PERI_CTRL24_ADDR(base) ((base) + (0x060UL))
#define SOC_FCM_LOCAL_PERI_CTRL25_ADDR(base) ((base) + (0x064UL))
#define SOC_FCM_LOCAL_PERI_CTRL26_ADDR(base) ((base) + (0x068UL))
#define SOC_FCM_LOCAL_PERI_CTRL27_ADDR(base) ((base) + (0x06CUL))
#define SOC_FCM_LOCAL_PERI_CTRL28_ADDR(base) ((base) + (0x070UL))
#define SOC_FCM_LOCAL_PERI_CTRL29_ADDR(base) ((base) + (0x074UL))
#define SOC_FCM_LOCAL_PERI_CTRL30_ADDR(base) ((base) + (0x078UL))
#define SOC_FCM_LOCAL_PERI_CTRL31_ADDR(base) ((base) + (0x07CUL))
#define SOC_FCM_LOCAL_PERI_CTRL32_ADDR(base) ((base) + (0x080UL))
#define SOC_FCM_LOCAL_PERI_CTRL33_ADDR(base) ((base) + (0x084UL))
#define SOC_FCM_LOCAL_PERI_CTRL34_ADDR(base) ((base) + (0x088UL))
#define SOC_FCM_LOCAL_PERI_CTRL35_ADDR(base) ((base) + (0x08CUL))
#define SOC_FCM_LOCAL_PERI_CTRL36_ADDR(base) ((base) + (0x090UL))
#define SOC_FCM_LOCAL_PERI_CTRL37_ADDR(base) ((base) + (0x094UL))
#define SOC_FCM_LOCAL_PERI_CTRL38_ADDR(base) ((base) + (0x098UL))
#define SOC_FCM_LOCAL_PERI_CTRL39_ADDR(base) ((base) + (0x09CUL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL0_ADDR(base) ((base) + (0x100UL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL1_ADDR(base) ((base) + (0x104UL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL2_ADDR(base) ((base) + (0x108UL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL3_ADDR(base) ((base) + (0x10CUL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL4_ADDR(base) ((base) + (0x110UL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL5_ADDR(base) ((base) + (0x114UL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL6_ADDR(base) ((base) + (0x118UL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL7_ADDR(base) ((base) + (0x11CUL))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_ADDR(base) ((base) + (0x120UL))
#define SOC_FCM_LOCAL_PERI_STAT0_ADDR(base) ((base) + (0x200UL))
#define SOC_FCM_LOCAL_PERI_STAT1_ADDR(base) ((base) + (0x204UL))
#define SOC_FCM_LOCAL_PERI_STAT2_ADDR(base) ((base) + (0x208UL))
#define SOC_FCM_LOCAL_PERI_STAT3_ADDR(base) ((base) + (0x20CUL))
#define SOC_FCM_LOCAL_PERI_STAT4_ADDR(base) ((base) + (0x210UL))
#define SOC_FCM_LOCAL_PERI_STAT5_ADDR(base) ((base) + (0x214UL))
#define SOC_FCM_LOCAL_PERI_STAT6_ADDR(base) ((base) + (0x218UL))
#define SOC_FCM_LOCAL_PERI_STAT7_ADDR(base) ((base) + (0x21CUL))
#define SOC_FCM_LOCAL_PERI_STAT8_ADDR(base) ((base) + (0x220UL))
#define SOC_FCM_LOCAL_PERI_STAT9_ADDR(base) ((base) + (0x224UL))
#define SOC_FCM_LOCAL_PERI_STAT10_ADDR(base) ((base) + (0x228UL))
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_ADDR(base) ((base) + (0x22CUL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + (0x230UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + (0x234UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + (0x238UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + (0x23CUL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + (0x240UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + (0x244UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + (0x248UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + (0x24CUL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x250UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x254UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x258UL))
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x25CUL))
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x260UL))
#define SOC_FCM_LOCAL_PERI_STAT25_ADDR(base) ((base) + (0x264UL))
#define SOC_FCM_LOCAL_PERI_STAT26_ADDR(base) ((base) + (0x268UL))
#define SOC_FCM_LOCAL_PERI_STAT27_ADDR(base) ((base) + (0x26CUL))
#define SOC_FCM_LOCAL_PERI_STAT28_ADDR(base) ((base) + (0x270UL))
#define SOC_FCM_LOCAL_PERI_STAT29_ADDR(base) ((base) + (0x274UL))
#else
#define SOC_FCM_LOCAL_PERI_CTRL0_ADDR(base) ((base) + (0x000))
#define SOC_FCM_LOCAL_PERI_CTRL1_ADDR(base) ((base) + (0x004))
#define SOC_FCM_LOCAL_PERI_CTRL2_ADDR(base) ((base) + (0x008))
#define SOC_FCM_LOCAL_PERI_CTRL3_ADDR(base) ((base) + (0x00C))
#define SOC_FCM_LOCAL_PERI_CTRL4_ADDR(base) ((base) + (0x010))
#define SOC_FCM_LOCAL_PERI_CTRL5_ADDR(base) ((base) + (0x014))
#define SOC_FCM_LOCAL_PERI_CTRL6_ADDR(base) ((base) + (0x018))
#define SOC_FCM_LOCAL_PERI_CTRL7_ADDR(base) ((base) + (0x01C))
#define SOC_FCM_LOCAL_PERI_CTRL8_ADDR(base) ((base) + (0x020))
#define SOC_FCM_LOCAL_PERI_CTRL9_ADDR(base) ((base) + (0x024))
#define SOC_FCM_LOCAL_PERI_CTRL10_ADDR(base) ((base) + (0x028))
#define SOC_FCM_LOCAL_PERI_CTRL11_ADDR(base) ((base) + (0x02C))
#define SOC_FCM_LOCAL_PERI_CTRL12_ADDR(base) ((base) + (0x030))
#define SOC_FCM_LOCAL_PERI_CTRL13_ADDR(base) ((base) + (0x034))
#define SOC_FCM_LOCAL_PERI_CTRL14_ADDR(base) ((base) + (0x038))
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + (0x03C))
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + (0x040))
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + (0x044))
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + (0x048))
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + (0x04C))
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + (0x050))
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + (0x054))
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + (0x058))
#define SOC_FCM_LOCAL_PERI_CTRL23_ADDR(base) ((base) + (0x05C))
#define SOC_FCM_LOCAL_PERI_CTRL24_ADDR(base) ((base) + (0x060))
#define SOC_FCM_LOCAL_PERI_CTRL25_ADDR(base) ((base) + (0x064))
#define SOC_FCM_LOCAL_PERI_CTRL26_ADDR(base) ((base) + (0x068))
#define SOC_FCM_LOCAL_PERI_CTRL27_ADDR(base) ((base) + (0x06C))
#define SOC_FCM_LOCAL_PERI_CTRL28_ADDR(base) ((base) + (0x070))
#define SOC_FCM_LOCAL_PERI_CTRL29_ADDR(base) ((base) + (0x074))
#define SOC_FCM_LOCAL_PERI_CTRL30_ADDR(base) ((base) + (0x078))
#define SOC_FCM_LOCAL_PERI_CTRL31_ADDR(base) ((base) + (0x07C))
#define SOC_FCM_LOCAL_PERI_CTRL32_ADDR(base) ((base) + (0x080))
#define SOC_FCM_LOCAL_PERI_CTRL33_ADDR(base) ((base) + (0x084))
#define SOC_FCM_LOCAL_PERI_CTRL34_ADDR(base) ((base) + (0x088))
#define SOC_FCM_LOCAL_PERI_CTRL35_ADDR(base) ((base) + (0x08C))
#define SOC_FCM_LOCAL_PERI_CTRL36_ADDR(base) ((base) + (0x090))
#define SOC_FCM_LOCAL_PERI_CTRL37_ADDR(base) ((base) + (0x094))
#define SOC_FCM_LOCAL_PERI_CTRL38_ADDR(base) ((base) + (0x098))
#define SOC_FCM_LOCAL_PERI_CTRL39_ADDR(base) ((base) + (0x09C))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL0_ADDR(base) ((base) + (0x100))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL1_ADDR(base) ((base) + (0x104))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL2_ADDR(base) ((base) + (0x108))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL3_ADDR(base) ((base) + (0x10C))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL4_ADDR(base) ((base) + (0x110))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL5_ADDR(base) ((base) + (0x114))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL6_ADDR(base) ((base) + (0x118))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL7_ADDR(base) ((base) + (0x11C))
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_ADDR(base) ((base) + (0x120))
#define SOC_FCM_LOCAL_PERI_STAT0_ADDR(base) ((base) + (0x200))
#define SOC_FCM_LOCAL_PERI_STAT1_ADDR(base) ((base) + (0x204))
#define SOC_FCM_LOCAL_PERI_STAT2_ADDR(base) ((base) + (0x208))
#define SOC_FCM_LOCAL_PERI_STAT3_ADDR(base) ((base) + (0x20C))
#define SOC_FCM_LOCAL_PERI_STAT4_ADDR(base) ((base) + (0x210))
#define SOC_FCM_LOCAL_PERI_STAT5_ADDR(base) ((base) + (0x214))
#define SOC_FCM_LOCAL_PERI_STAT6_ADDR(base) ((base) + (0x218))
#define SOC_FCM_LOCAL_PERI_STAT7_ADDR(base) ((base) + (0x21C))
#define SOC_FCM_LOCAL_PERI_STAT8_ADDR(base) ((base) + (0x220))
#define SOC_FCM_LOCAL_PERI_STAT9_ADDR(base) ((base) + (0x224))
#define SOC_FCM_LOCAL_PERI_STAT10_ADDR(base) ((base) + (0x228))
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_ADDR(base) ((base) + (0x22C))
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + (0x230))
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + (0x234))
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + (0x238))
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + (0x23C))
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + (0x240))
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + (0x244))
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + (0x248))
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + (0x24C))
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x250))
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x254))
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x258))
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x25C))
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0x260))
#define SOC_FCM_LOCAL_PERI_STAT25_ADDR(base) ((base) + (0x264))
#define SOC_FCM_LOCAL_PERI_STAT26_ADDR(base) ((base) + (0x268))
#define SOC_FCM_LOCAL_PERI_STAT27_ADDR(base) ((base) + (0x26C))
#define SOC_FCM_LOCAL_PERI_STAT28_ADDR(base) ((base) + (0x270))
#define SOC_FCM_LOCAL_PERI_STAT29_ADDR(base) ((base) + (0x274))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int broadcastcacheoutter : 1;
        unsigned int broadcastcachemaint : 1;
        unsigned int broadcastpersist : 1;
        unsigned int broadcastcachemaintpou : 1;
        unsigned int enyo_mpmm_en : 4;
        unsigned int iso_sd_bypass : 1;
        unsigned int iso_idle_bypass : 1;
        unsigned int bisr_sd_bypass : 1;
        unsigned int pdc_sd_bypass : 1;
        unsigned int reserved : 4;
        unsigned int arnsaid_m1 : 2;
        unsigned int armid_m1 : 6;
        unsigned int awnsaid_m1 : 2;
        unsigned int awmid_m1 : 6;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL0_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastcacheoutter_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastcacheoutter_END (0)
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastcachemaint_START (1)
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastcachemaint_END (1)
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastpersist_START (2)
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastpersist_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastcachemaintpou_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL0_broadcastcachemaintpou_END (3)
#define SOC_FCM_LOCAL_PERI_CTRL0_enyo_mpmm_en_START (4)
#define SOC_FCM_LOCAL_PERI_CTRL0_enyo_mpmm_en_END (7)
#define SOC_FCM_LOCAL_PERI_CTRL0_iso_sd_bypass_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL0_iso_sd_bypass_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL0_iso_idle_bypass_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL0_iso_idle_bypass_END (9)
#define SOC_FCM_LOCAL_PERI_CTRL0_bisr_sd_bypass_START (10)
#define SOC_FCM_LOCAL_PERI_CTRL0_bisr_sd_bypass_END (10)
#define SOC_FCM_LOCAL_PERI_CTRL0_pdc_sd_bypass_START (11)
#define SOC_FCM_LOCAL_PERI_CTRL0_pdc_sd_bypass_END (11)
#define SOC_FCM_LOCAL_PERI_CTRL0_arnsaid_m1_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL0_arnsaid_m1_END (17)
#define SOC_FCM_LOCAL_PERI_CTRL0_armid_m1_START (18)
#define SOC_FCM_LOCAL_PERI_CTRL0_armid_m1_END (23)
#define SOC_FCM_LOCAL_PERI_CTRL0_awnsaid_m1_START (24)
#define SOC_FCM_LOCAL_PERI_CTRL0_awnsaid_m1_END (25)
#define SOC_FCM_LOCAL_PERI_CTRL0_awmid_m1_START (26)
#define SOC_FCM_LOCAL_PERI_CTRL0_awmid_m1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int astartmp : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL1_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL1_astartmp_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL1_astartmp_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aendmp : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL2_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL2_aendmp_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL2_aendmp_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aa64naa32 : 8;
        unsigned int vinithi : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL3_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL3_aa64naa32_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL3_aa64naa32_END (7)
#define SOC_FCM_LOCAL_PERI_CTRL3_vinithi_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL3_vinithi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_coreclk_little_soft : 4;
        unsigned int gt_clk_coreclk_middle_soft : 3;
        unsigned int gt_clk_coreclk_big_soft : 1;
        unsigned int gt_gicclk_harden_soft : 1;
        unsigned int reserved : 4;
        unsigned int little_core_clkgate_sel : 1;
        unsigned int middle_core_clkgate_sel : 1;
        unsigned int big_core_clkgate_sel : 1;
        unsigned int clken_masken : 16;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL4_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_clk_coreclk_little_soft_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_clk_coreclk_little_soft_END (3)
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_clk_coreclk_middle_soft_START (4)
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_clk_coreclk_middle_soft_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_clk_coreclk_big_soft_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_clk_coreclk_big_soft_END (7)
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_gicclk_harden_soft_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL4_gt_gicclk_harden_soft_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL4_little_core_clkgate_sel_START (13)
#define SOC_FCM_LOCAL_PERI_CTRL4_little_core_clkgate_sel_END (13)
#define SOC_FCM_LOCAL_PERI_CTRL4_middle_core_clkgate_sel_START (14)
#define SOC_FCM_LOCAL_PERI_CTRL4_middle_core_clkgate_sel_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL4_big_core_clkgate_sel_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL4_big_core_clkgate_sel_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL4_clken_masken_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL4_clken_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sys_cnt_en_dly : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL5_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL5_sys_cnt_en_dly_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL5_sys_cnt_en_dly_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ananke_core_mem_ctl_normal : 3;
        unsigned int reserved_0 : 1;
        unsigned int ananke_core_mem_ctl_sd : 3;
        unsigned int reserved_1 : 1;
        unsigned int ananke_core_mem_ctl_dslp : 3;
        unsigned int reserved_2 : 1;
        unsigned int ananke_core_mem_ctl_slp : 3;
        unsigned int reserved_3 : 1;
        unsigned int enyo_big_core_mem_ctl_normal : 3;
        unsigned int reserved_4 : 1;
        unsigned int enyo_big_core_mem_ctl_sd : 3;
        unsigned int reserved_5 : 1;
        unsigned int enyo_big_core_mem_ctl_dslp : 3;
        unsigned int reserved_6 : 1;
        unsigned int enyo_big_core_mem_ctl_slp : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL7_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_normal_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_normal_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_sd_START (4)
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_sd_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_dslp_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_dslp_END (10)
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_slp_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL7_ananke_core_mem_ctl_slp_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_normal_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_normal_END (18)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_sd_START (20)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_sd_END (22)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_dslp_START (24)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_dslp_END (26)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_slp_START (28)
#define SOC_FCM_LOCAL_PERI_CTRL7_enyo_big_core_mem_ctl_slp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_cluster_mem_ctl_normal : 3;
        unsigned int reserved_0 : 1;
        unsigned int fcm_cluster_mem_ctl_sd : 3;
        unsigned int reserved_1 : 1;
        unsigned int fcm_cluster_mem_ctl_dslp : 3;
        unsigned int reserved_2 : 1;
        unsigned int fcm_cluster_core_mem_ctl_slp : 3;
        unsigned int reserved_3 : 1;
        unsigned int enyo_mid_core_mem_ctl_normal : 3;
        unsigned int reserved_4 : 1;
        unsigned int enyo_mid_core_mem_ctl_sd : 3;
        unsigned int reserved_5 : 1;
        unsigned int enyo_mid_core_mem_ctl_dslp : 3;
        unsigned int reserved_6 : 1;
        unsigned int enyo_mid_core_mem_ctl_slp : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL8_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_mem_ctl_normal_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_mem_ctl_normal_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_mem_ctl_sd_START (4)
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_mem_ctl_sd_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_mem_ctl_dslp_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_mem_ctl_dslp_END (10)
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_core_mem_ctl_slp_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL8_fcm_cluster_core_mem_ctl_slp_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_normal_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_normal_END (18)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_sd_START (20)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_sd_END (22)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_dslp_START (24)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_dslp_END (26)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_slp_START (28)
#define SOC_FCM_LOCAL_PERI_CTRL8_enyo_mid_core_mem_ctl_slp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_data_way15_way12_mem_ctrl_sys : 3;
        unsigned int l3_data_way11_way8_mem_ctrl_sys : 3;
        unsigned int l3_data_way7_way4_mem_ctrl_sys : 3;
        unsigned int l3_data_way3_way0_mem_ctrl_sys : 3;
        unsigned int l3_sf_mem_ctrl_sys : 3;
        unsigned int l3_other_mem_ctrl_sys : 3;
        unsigned int reserved : 2;
        unsigned int l3_tag_way15_way12_mem_ctrl_sys : 3;
        unsigned int l3_tag_way11_way8_mem_ctrl_sys : 3;
        unsigned int l3_tag_way7_way4_mem_ctrl_sys : 3;
        unsigned int l3_tag_way3_way0_mem_ctrl_sys : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL9_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way15_way12_mem_ctrl_sys_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way15_way12_mem_ctrl_sys_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way11_way8_mem_ctrl_sys_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way11_way8_mem_ctrl_sys_END (5)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way7_way4_mem_ctrl_sys_START (6)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way7_way4_mem_ctrl_sys_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way3_way0_mem_ctrl_sys_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_data_way3_way0_mem_ctrl_sys_END (11)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_sf_mem_ctrl_sys_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_sf_mem_ctrl_sys_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_other_mem_ctrl_sys_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_other_mem_ctrl_sys_END (17)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way15_way12_mem_ctrl_sys_START (20)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way15_way12_mem_ctrl_sys_END (22)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way11_way8_mem_ctrl_sys_START (23)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way11_way8_mem_ctrl_sys_END (25)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way7_way4_mem_ctrl_sys_START (26)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way7_way4_mem_ctrl_sys_END (28)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way3_way0_mem_ctrl_sys_START (29)
#define SOC_FCM_LOCAL_PERI_CTRL9_l3_tag_way3_way0_mem_ctrl_sys_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_pchannel_wait_cycle_sd : 16;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL10_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_sd_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL10_fcm_pchannel_wait_cycle_sd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_p_channel_init_pstate : 7;
        unsigned int reserved_0 : 1;
        unsigned int force_on_to_sfonly_on_enable : 1;
        unsigned int reserved_1 : 3;
        unsigned int force_on_to_sfonly_on : 1;
        unsigned int reserved_2 : 2;
        unsigned int cluster_preq_from_sys : 1;
        unsigned int cluster_pstate_from_sys : 7;
        unsigned int reserved_3 : 1;
        unsigned int cluster_pactive_sel : 2;
        unsigned int reserved_4 : 5;
        unsigned int fcm_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL11_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL11_fcm_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL11_fcm_p_channel_init_pstate_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL11_force_on_to_sfonly_on_enable_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL11_force_on_to_sfonly_on_enable_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL11_force_on_to_sfonly_on_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL11_force_on_to_sfonly_on_END (12)
#define SOC_FCM_LOCAL_PERI_CTRL11_cluster_preq_from_sys_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL11_cluster_preq_from_sys_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL11_cluster_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL11_cluster_pstate_from_sys_END (22)
#define SOC_FCM_LOCAL_PERI_CTRL11_cluster_pactive_sel_START (24)
#define SOC_FCM_LOCAL_PERI_CTRL11_cluster_pactive_sel_END (25)
#define SOC_FCM_LOCAL_PERI_CTRL11_fcm_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_CTRL11_fcm_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_flush_cache : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL12_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL12_force_flush_cache_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL12_force_flush_cache_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_off_to_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL13_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL13_force_off_to_on_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL13_force_off_to_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_disable_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL14_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL14_force_disable_off_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL14_force_disable_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core0_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core0_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core0_mem_ctrl_from_sys : 3;
        unsigned int core0_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core1_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core1_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core1_mem_ctrl_from_sys : 3;
        unsigned int core1_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core2_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core2_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core2_mem_ctrl_from_sys : 3;
        unsigned int core2_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core3_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core3_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core3_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core3_mem_ctrl_from_sys : 3;
        unsigned int core3_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core4_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core4_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core4_mem_ctrl_from_sys : 3;
        unsigned int core4_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core5_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core5_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core5_mem_ctrl_from_sys : 3;
        unsigned int core5_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core6_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core6_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core6_mem_ctrl_from_sys : 3;
        unsigned int core6_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_p_channel_init_pstate : 6;
        unsigned int reserved_0 : 10;
        unsigned int core7_pstate_from_sys : 6;
        unsigned int reserved_1 : 2;
        unsigned int core7_preq_from_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core7_mem_ctrl_from_sys : 3;
        unsigned int core7_p_channel_enable : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core0_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core1_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL23_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL23_fcm_core0_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL23_fcm_core0_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL23_fcm_core1_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL23_fcm_core1_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core2_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core3_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL24_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL24_fcm_core2_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL24_fcm_core2_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL24_fcm_core3_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL24_fcm_core3_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core4_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core5_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL25_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL25_fcm_core4_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL25_fcm_core4_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL25_fcm_core5_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL25_fcm_core5_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core6_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core7_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL26_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL26_fcm_core6_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL26_fcm_core6_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL26_fcm_core7_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL26_fcm_core7_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_hc_test : 3;
        unsigned int little_hc_tselr_tp : 2;
        unsigned int little_hc_tselw : 2;
        unsigned int little_hc_tra : 2;
        unsigned int little_hc_tselr_hchd : 3;
        unsigned int little_hd_test : 3;
        unsigned int little_hd_tselr_tp : 2;
        unsigned int little_hd_tselw : 2;
        unsigned int little_hd_tra : 2;
        unsigned int little_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL27_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_test_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_test_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_test_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_test_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERI_CTRL27_little_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_tp_test : 3;
        unsigned int core0_tp_tselr_tp : 2;
        unsigned int core0_tp_tselw : 2;
        unsigned int core0_tp_tra : 2;
        unsigned int core0_tp_tselr_hchd : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL28_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_test_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_test_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tselw_START (5)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tselw_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tra_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tra_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL28_core0_tp_tselr_hchd_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int middle_hc_test : 3;
        unsigned int middle_hc_tselr_tp : 2;
        unsigned int middle_hc_tselw : 2;
        unsigned int middle_hc_tra : 2;
        unsigned int middle_hc_tselr_hchd : 3;
        unsigned int middle_hd_test : 3;
        unsigned int middle_hd_tselr_tp : 2;
        unsigned int middle_hd_tselw : 2;
        unsigned int middle_hd_tra : 2;
        unsigned int middle_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL29_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_test_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_test_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_test_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_test_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERI_CTRL29_middle_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int middle_tp_test_24x144 : 3;
        unsigned int middle_tp_tselr_tp_24x144 : 2;
        unsigned int middle_tp_tselw_24x144 : 2;
        unsigned int middle_tp_tra_24x144 : 2;
        unsigned int middle_tp_tselr_hchd_24x144 : 3;
        unsigned int middle_tp_test_64x96 : 3;
        unsigned int middle_tp_tselr_tp_64x96 : 2;
        unsigned int middle_tp_tselw_64x96 : 2;
        unsigned int middle_tp_tra_64x96 : 2;
        unsigned int middle_tp_tselr_hchd_64x96 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL30_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_test_24x144_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_test_24x144_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_tp_24x144_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_tp_24x144_END (4)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselw_24x144_START (5)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselw_24x144_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tra_24x144_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tra_24x144_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_hchd_24x144_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_hchd_24x144_END (11)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_test_64x96_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_test_64x96_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_tp_64x96_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_tp_64x96_END (16)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselw_64x96_START (17)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselw_64x96_END (18)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tra_64x96_START (19)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tra_64x96_END (20)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_hchd_64x96_START (21)
#define SOC_FCM_LOCAL_PERI_CTRL30_middle_tp_tselr_hchd_64x96_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int big_hc_test : 3;
        unsigned int big_hc_tselr_tp : 2;
        unsigned int big_hc_tselw : 2;
        unsigned int big_hc_tra : 2;
        unsigned int big_hc_tselr_hchd : 3;
        unsigned int big_hd_test : 3;
        unsigned int big_hd_tselr_tp : 2;
        unsigned int big_hd_tselw : 2;
        unsigned int big_hd_tra : 2;
        unsigned int big_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL31_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_test_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_test_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_test_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_test_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERI_CTRL31_big_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int big_tp_test_24x144 : 3;
        unsigned int big_tp_tselr_tp_24x144 : 2;
        unsigned int big_tp_tselw_24x144 : 2;
        unsigned int big_tp_tra_24x144 : 2;
        unsigned int big_tp_tselr_hchd_24x144 : 3;
        unsigned int big_tp_test_64x96 : 3;
        unsigned int big_tp_tselr_tp_64x96 : 2;
        unsigned int big_tp_tselw_64x96 : 2;
        unsigned int big_tp_tra_64x96 : 2;
        unsigned int big_tp_tselr_hchd_64x96 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL32_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_test_24x144_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_test_24x144_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_tp_24x144_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_tp_24x144_END (4)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselw_24x144_START (5)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselw_24x144_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tra_24x144_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tra_24x144_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_hchd_24x144_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_hchd_24x144_END (11)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_test_64x96_START (12)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_test_64x96_END (14)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_tp_64x96_START (15)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_tp_64x96_END (16)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselw_64x96_START (17)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselw_64x96_END (18)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tra_64x96_START (19)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tra_64x96_END (20)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_hchd_64x96_START (21)
#define SOC_FCM_LOCAL_PERI_CTRL32_big_tp_tselr_hchd_64x96_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_mem_test : 3;
        unsigned int reserved_0 : 2;
        unsigned int l3_mem_tselw : 2;
        unsigned int l3_mem_tra : 2;
        unsigned int l3_mem_tselr : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL33_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_test_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_test_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_tselw_START (5)
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_tselw_END (6)
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_tra_START (7)
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_tra_END (8)
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_tselr_START (9)
#define SOC_FCM_LOCAL_PERI_CTRL33_l3_mem_tselr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sp_memory_ls : 1;
        unsigned int sp_memory_ds : 1;
        unsigned int sp_memory_sd : 1;
        unsigned int sp_mem_hc_tselr : 3;
        unsigned int sp_mem_hc_tselw : 2;
        unsigned int sp_mem_test : 3;
        unsigned int sp_mem_hd_tselr : 3;
        unsigned int sp_mem_hd_tselw : 2;
        unsigned int sp_mem_tra : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL34_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_memory_ls_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_memory_ls_END (0)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_memory_ds_START (1)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_memory_ds_END (1)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_memory_sd_START (2)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_memory_sd_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hc_tselr_START (3)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hc_tselr_END (5)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hc_tselw_START (6)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hc_tselw_END (7)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_test_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_test_END (10)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hd_tselr_START (11)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hd_tselr_END (13)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hd_tselw_START (14)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_hd_tselw_END (15)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_tra_START (16)
#define SOC_FCM_LOCAL_PERI_CTRL34_sp_mem_tra_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_mem_ctrl_ls : 1;
        unsigned int tp_mem_ctrl_ds : 1;
        unsigned int tp_mem_ctrl_sd : 1;
        unsigned int reserved_0 : 1;
        unsigned int tp_mem_ctrl_tselr : 2;
        unsigned int tp_mem_ctrl_tselw : 2;
        unsigned int tp_mem_ctrl_test : 3;
        unsigned int tp_mem_ctrl_tra : 2;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL35_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_ls_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_ls_END (0)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_ds_START (1)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_ds_END (1)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_sd_START (2)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_sd_END (2)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselr_START (4)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselr_END (5)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselw_START (6)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_tselw_END (7)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_test_START (8)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_test_END (10)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_tra_START (11)
#define SOC_FCM_LOCAL_PERI_CTRL35_tp_mem_ctrl_tra_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcr_sd_in_0 : 1;
        unsigned int pcr_sd_in_1 : 1;
        unsigned int pcr_sd_in_2 : 1;
        unsigned int pcr_sd_in_3 : 1;
        unsigned int pcr_sd_in_4 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL36_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_0_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_0_END (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_1_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_1_END (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_2_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_2_END (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_3_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_3_END (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_4_START (0)
#define SOC_FCM_LOCAL_PERI_CTRL36_pcr_sd_in_4_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL37_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL38_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_CTRL39_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr0 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL0_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL0_rvbaraddr0_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL0_rvbaraddr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr1 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL1_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL1_rvbaraddr1_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL1_rvbaraddr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr2 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL2_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL2_rvbaraddr2_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL2_rvbaraddr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr3 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL3_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL3_rvbaraddr3_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL3_rvbaraddr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr4 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL4_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL4_rvbaraddr4_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL4_rvbaraddr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr5 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL5_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL5_rvbaraddr5_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL5_rvbaraddr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr6 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL6_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL6_rvbaraddr6_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL6_rvbaraddr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr7 : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL7_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL7_rvbaraddr7_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL7_rvbaraddr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr0_high : 4;
        unsigned int rvbaraddr1_high : 4;
        unsigned int rvbaraddr2_high : 4;
        unsigned int rvbaraddr3_high : 4;
        unsigned int rvbaraddr4_high : 4;
        unsigned int rvbaraddr5_high : 4;
        unsigned int rvbaraddr6_high : 4;
        unsigned int rvbaraddr7_high : 4;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr0_high_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr0_high_END (3)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr1_high_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr1_high_END (7)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr2_high_START (8)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr2_high_END (11)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr3_high_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr3_high_END (15)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr4_high_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr4_high_END (19)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr5_high_START (20)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr5_high_END (23)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr6_high_START (24)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr6_high_END (27)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr7_high_START (28)
#define SOC_FCM_LOCAL_PERI_FCM_RVBAR_CTRL8_rvbaraddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT0_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT0_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT0_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT0_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT0_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT0_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT0_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT0_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT1_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT1_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT1_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT1_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT1_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT1_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT1_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT1_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT2_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT2_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT2_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT2_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT2_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT2_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT2_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT2_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT3_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT3_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT3_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT3_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT3_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT3_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT3_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT3_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT3_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT4_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT4_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT4_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT4_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT4_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT4_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT4_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT4_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT4_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT5_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT5_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT5_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT5_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT5_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT5_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT5_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT5_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT5_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT6_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT6_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT6_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT6_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT6_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT6_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT6_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT6_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT6_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 18;
        unsigned int reserved_0 : 2;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_2 : 3;
        unsigned int core_can_pd : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT7_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT7_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT7_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERI_STAT7_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT7_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT7_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT7_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT7_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT7_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pactive_to_sys : 20;
        unsigned int paccept_to_sys : 1;
        unsigned int reserved_0 : 3;
        unsigned int pdeny_to_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int cluster_can_pd : 1;
        unsigned int reserved_2 : 2;
        unsigned int forced_on_sfonly_complete : 1;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT8_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT8_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERI_STAT8_pactive_to_sys_END (19)
#define SOC_FCM_LOCAL_PERI_STAT8_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERI_STAT8_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERI_STAT8_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERI_STAT8_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERI_STAT8_cluster_can_pd_START (28)
#define SOC_FCM_LOCAL_PERI_STAT8_cluster_can_pd_END (28)
#define SOC_FCM_LOCAL_PERI_STAT8_forced_on_sfonly_complete_START (31)
#define SOC_FCM_LOCAL_PERI_STAT8_forced_on_sfonly_complete_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int custom_wfi : 8;
        unsigned int custom_wfe : 8;
        unsigned int standbywfi_pdc : 8;
        unsigned int standbywfi_pdc_l3 : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT9_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT9_custom_wfi_START (0)
#define SOC_FCM_LOCAL_PERI_STAT9_custom_wfi_END (7)
#define SOC_FCM_LOCAL_PERI_STAT9_custom_wfe_START (8)
#define SOC_FCM_LOCAL_PERI_STAT9_custom_wfe_END (15)
#define SOC_FCM_LOCAL_PERI_STAT9_standbywfi_pdc_START (16)
#define SOC_FCM_LOCAL_PERI_STAT9_standbywfi_pdc_END (23)
#define SOC_FCM_LOCAL_PERI_STAT9_standbywfi_pdc_l3_START (24)
#define SOC_FCM_LOCAL_PERI_STAT9_standbywfi_pdc_l3_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_bisr_req : 8;
        unsigned int core_pdc_sdo_ack : 8;
        unsigned int l3_bisr_req : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT10_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_STAT10_core_bisr_req_START (0)
#define SOC_FCM_LOCAL_PERI_STAT10_core_bisr_req_END (7)
#define SOC_FCM_LOCAL_PERI_STAT10_core_pdc_sdo_ack_START (8)
#define SOC_FCM_LOCAL_PERI_STAT10_core_pdc_sdo_ack_END (15)
#define SOC_FCM_LOCAL_PERI_STAT10_l3_bisr_req_START (16)
#define SOC_FCM_LOCAL_PERI_STAT10_l3_bisr_req_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cluster_paccept : 1;
        unsigned int cluster_pdeny : 1;
        unsigned int cluster_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int cluster_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int cluster_pactive : 20;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CLUSTER_PCHANNEL_STAT_cluster_pactive_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE0_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE1_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE2_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE3_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE4_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE5_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE6_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_paccept : 1;
        unsigned int core_pdeny : 1;
        unsigned int core_preq : 1;
        unsigned int reserved_0 : 1;
        unsigned int core_pstate : 7;
        unsigned int reserved_1 : 1;
        unsigned int core_pactive : 18;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERI_FCM_CORE7_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state0 : 4;
        unsigned int core_pstate0 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state1 : 4;
        unsigned int core_pstate1 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state0_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state0_END (3)
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_END (9)
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state1_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state1_END (19)
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_START (20)
#define SOC_FCM_LOCAL_PERI_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state2 : 4;
        unsigned int core_pstate2 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state3 : 4;
        unsigned int core_pstate3 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state2_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state2_END (3)
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_END (9)
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state3_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state3_END (19)
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_START (20)
#define SOC_FCM_LOCAL_PERI_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state4 : 4;
        unsigned int core_pstate4 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state5 : 4;
        unsigned int core_pstate5 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state4_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state4_END (3)
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_END (9)
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state5_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state5_END (19)
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_START (20)
#define SOC_FCM_LOCAL_PERI_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int current_state6 : 4;
        unsigned int core_pstate6 : 6;
        unsigned int reserved_0 : 6;
        unsigned int current_state7 : 4;
        unsigned int core_pstate7 : 6;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state6_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state6_END (3)
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_START (4)
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_END (9)
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state7_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state7_END (19)
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_START (20)
#define SOC_FCM_LOCAL_PERI_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cluster_current_state : 6;
        unsigned int cluster_pstate : 7;
        unsigned int reserved_0 : 3;
        unsigned int cluster_current_state_flush_cache : 3;
        unsigned int cluster_off_flush_cache_valid : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_START (0)
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_END (5)
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_pstate_START (6)
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_pstate_END (12)
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_flush_cache_START (16)
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_flush_cache_END (18)
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_off_flush_cache_valid_START (19)
#define SOC_FCM_LOCAL_PERI_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_off_flush_cache_valid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT25_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_PERI_STAT29_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
