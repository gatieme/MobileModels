#ifndef __SOC_FCM_LOCAL_PERIPH_NS_INTERFACE_H__
#define __SOC_FCM_LOCAL_PERIPH_NS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_ADDR(base) ((base) + (0x804UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_ADDR(base) ((base) + (0x808UL))
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ADDR(base) ((base) + (0x80CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_ADDR(base) ((base) + (0x810UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_ADDR(base) ((base) + (0x818UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_ADDR(base) ((base) + (0x81CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_ADDR(base) ((base) + (0x820UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + (0x824UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + (0x828UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + (0x82CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + (0x830UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + (0x834UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + (0x838UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + (0x83CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + (0x840UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_ADDR(base) ((base) + (0x844UL))
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_ADDR(base) ((base) + (0x848UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_ADDR(base) ((base) + (0x84CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ADDR(base) ((base) + (0x850UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_ADDR(base) ((base) + (0x854UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_ADDR(base) ((base) + (0x858UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_ASP_POWERDN_REG_ADDR(base) ((base) + (0x85CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_ADDR(base) ((base) + (0x860UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_ADDR(base) ((base) + (0x864UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG1_ADDR(base) ((base) + (0x868UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_ADDR(base) ((base) + (0x86CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x870UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x874UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x878UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x87CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x880UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_DLYCNT_CFG_REG_ADDR(base) ((base) + (0x884UL))
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_FLUSH_CACHE_CFG_REG_ADDR(base) ((base) + (0x888UL))
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_OFF_TO_ON_CFG_REG_ADDR(base) ((base) + (0x88CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_ADDR(base) ((base) + (0x890UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x894UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x898UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x89CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8A0UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8A4UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8A8UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8ACUL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8B0UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8B4UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8B8UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8BCUL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C0UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C4UL))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C8UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_ADDR(base) ((base) + (0x8E4UL))
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_ADDR(base) ((base) + (0x8E8UL))
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_ADDR(base) ((base) + (0x8ECUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0xC00UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_ADDR(base) ((base) + (0xC04UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_ADDR(base) ((base) + (0xC08UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_ADDR(base) ((base) + (0xC0CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_ADDR(base) ((base) + (0xC10UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_ADDR(base) ((base) + (0xC14UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0xC18UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0xC1CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_ADDR(base) ((base) + (0xC20UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_ADDR(base) ((base) + (0xC24UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_ADDR(base) ((base) + (0xC28UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_ADDR(base) ((base) + (0xC2CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_ADDR(base) ((base) + (0xC30UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + (0xC34UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + (0xC38UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + (0xC3CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + (0xC40UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + (0xC44UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + (0xC48UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + (0xC4CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + (0xC50UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_ADDR(base) ((base) + (0xC54UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT22_ADDR(base) ((base) + (0xC58UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT23_ADDR(base) ((base) + (0xC5CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_ADDR(base) ((base) + (0xC60UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_ADDR(base) ((base) + (0xC64UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_ADDR(base) ((base) + (0xC68UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC6CUL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC70UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC74UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC78UL))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC7CUL))
#else
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_ADDR(base) ((base) + (0x800))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_ADDR(base) ((base) + (0x804))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_ADDR(base) ((base) + (0x808))
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ADDR(base) ((base) + (0x80C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_ADDR(base) ((base) + (0x810))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_ADDR(base) ((base) + (0x814))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_ADDR(base) ((base) + (0x818))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_ADDR(base) ((base) + (0x81C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_ADDR(base) ((base) + (0x820))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_ADDR(base) ((base) + (0x824))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_ADDR(base) ((base) + (0x828))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_ADDR(base) ((base) + (0x82C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_ADDR(base) ((base) + (0x830))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_ADDR(base) ((base) + (0x834))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_ADDR(base) ((base) + (0x838))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_ADDR(base) ((base) + (0x83C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_ADDR(base) ((base) + (0x840))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_ADDR(base) ((base) + (0x844))
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_ADDR(base) ((base) + (0x848))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_ADDR(base) ((base) + (0x84C))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ADDR(base) ((base) + (0x850))
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_ADDR(base) ((base) + (0x854))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_ADDR(base) ((base) + (0x858))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_ASP_POWERDN_REG_ADDR(base) ((base) + (0x85C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_ADDR(base) ((base) + (0x860))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_ADDR(base) ((base) + (0x864))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG1_ADDR(base) ((base) + (0x868))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_ADDR(base) ((base) + (0x86C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x870))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x874))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x878))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x87C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_CFG_REG_ADDR(base) ((base) + (0x880))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_DLYCNT_CFG_REG_ADDR(base) ((base) + (0x884))
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_FLUSH_CACHE_CFG_REG_ADDR(base) ((base) + (0x888))
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_OFF_TO_ON_CFG_REG_ADDR(base) ((base) + (0x88C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_ADDR(base) ((base) + (0x890))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x894))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x898))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x89C))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8A0))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8A4))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8A8))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8AC))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8B0))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8B4))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8B8))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8BC))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C0))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C4))
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_ADDR(base) ((base) + (0x8C8))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_ADDR(base) ((base) + (0x8E4))
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_ADDR(base) ((base) + (0x8E8))
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_ADDR(base) ((base) + (0x8EC))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0xC00))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_ADDR(base) ((base) + (0xC04))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_ADDR(base) ((base) + (0xC08))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_ADDR(base) ((base) + (0xC0C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_ADDR(base) ((base) + (0xC10))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_ADDR(base) ((base) + (0xC14))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0xC18))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0xC1C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_ADDR(base) ((base) + (0xC20))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_ADDR(base) ((base) + (0xC24))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_ADDR(base) ((base) + (0xC28))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_ADDR(base) ((base) + (0xC2C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_ADDR(base) ((base) + (0xC30))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_ADDR(base) ((base) + (0xC34))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_ADDR(base) ((base) + (0xC38))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_ADDR(base) ((base) + (0xC3C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_ADDR(base) ((base) + (0xC40))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_ADDR(base) ((base) + (0xC44))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_ADDR(base) ((base) + (0xC48))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_ADDR(base) ((base) + (0xC4C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_ADDR(base) ((base) + (0xC50))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_ADDR(base) ((base) + (0xC54))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT22_ADDR(base) ((base) + (0xC58))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT23_ADDR(base) ((base) + (0xC5C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_ADDR(base) ((base) + (0xC60))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_ADDR(base) ((base) + (0xC64))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_ADDR(base) ((base) + (0xC68))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC6C))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC70))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC74))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC78))
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_ADDR(base) ((base) + (0xC7C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aa64naa32 : 8;
        unsigned int broadcastpresist : 1;
        unsigned int broadcastcachemaint : 1;
        unsigned int broadcastcachemaintpou : 1;
        unsigned int core_idle_isolate_bypass : 1;
        unsigned int vinithi : 4;
        unsigned int sys_cnt_en_dly : 6;
        unsigned int wfi_source_sel : 1;
        unsigned int fcm_bus_dbg_en : 1;
        unsigned int l3_dataram_sd_dly_bypass : 1;
        unsigned int acp_wakeup_bypass : 1;
        unsigned int dbgconnected : 1;
        unsigned int pmusnapshotreq : 1;
        unsigned int debug_block_wakeup_bypass : 1;
        unsigned int little_core_clkgate_sel : 1;
        unsigned int middle_core_clkgate_sel : 1;
        unsigned int big_core_clkgate_sel : 1;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_aa64naa32_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_aa64naa32_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_broadcastpresist_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_broadcastpresist_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_broadcastcachemaint_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_broadcastcachemaint_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_broadcastcachemaintpou_START (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_broadcastcachemaintpou_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_core_idle_isolate_bypass_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_core_idle_isolate_bypass_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_vinithi_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_vinithi_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_sys_cnt_en_dly_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_sys_cnt_en_dly_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_wfi_source_sel_START (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_wfi_source_sel_END (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_fcm_bus_dbg_en_START (23)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_fcm_bus_dbg_en_END (23)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_l3_dataram_sd_dly_bypass_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_l3_dataram_sd_dly_bypass_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_acp_wakeup_bypass_START (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_acp_wakeup_bypass_END (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_dbgconnected_START (26)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_dbgconnected_END (26)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_pmusnapshotreq_START (27)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_pmusnapshotreq_END (27)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_debug_block_wakeup_bypass_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_debug_block_wakeup_bypass_END (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_little_core_clkgate_sel_START (29)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_little_core_clkgate_sel_END (29)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_middle_core_clkgate_sel_START (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_middle_core_clkgate_sel_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_big_core_clkgate_sel_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_BASE_CFG_big_core_clkgate_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coresight_memory_ls : 1;
        unsigned int coresight_memory_ds : 1;
        unsigned int coresight_memory_sd : 1;
        unsigned int reserved_0 : 5;
        unsigned int coresight_mem_test : 3;
        unsigned int coresight_mem_tsel_r : 3;
        unsigned int coresight_mem_tsel_w : 2;
        unsigned int coresight_mem_tra : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_memory_ls_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_memory_ls_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_memory_ds_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_memory_ds_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_memory_sd_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_memory_sd_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_test_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_test_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_r_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_r_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_w_START (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_tsel_w_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_tra_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CSSYS_MEM_CTL_coresight_mem_tra_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_coreclk_little : 4;
        unsigned int gt_clk_coreclk_middle : 2;
        unsigned int gt_clk_coreclk_big : 2;
        unsigned int gt_clk_adb_brg_m0 : 1;
        unsigned int gt_clk_adb_brg_m1 : 1;
        unsigned int gt_clk_adb_brg_acp : 1;
        unsigned int gt_clk_atclk : 1;
        unsigned int gt_clk_atclk_top : 1;
        unsigned int gt_clk_periphclk : 1;
        unsigned int gt_clk_adb_brg_pp : 1;
        unsigned int reserved : 1;
        unsigned int clken_masken : 16;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_coreclk_little_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_coreclk_little_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_coreclk_middle_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_coreclk_middle_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_coreclk_big_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_coreclk_big_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_m0_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_m0_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_m1_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_m1_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_acp_START (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_acp_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_atclk_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_atclk_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_atclk_top_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_atclk_top_END (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_periphclk_START (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_periphclk_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_pp_START (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_gt_clk_adb_brg_pp_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_clken_masken_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLK_EN_clken_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wakeup_rank_en : 1;
        unsigned int wakeup_ch_en : 1;
        unsigned int ddr_intlv_gran : 2;
        unsigned int ddr_ch4_order : 1;
        unsigned int ddr_addr_shift_mode : 1;
        unsigned int reserved_0 : 2;
        unsigned int ddr_rank_map : 16;
        unsigned int ddr_rank_intlv_en : 1;
        unsigned int ddr_rank_intlv_gran : 2;
        unsigned int ddr_wakeup_prd : 2;
        unsigned int ddr_wakeup_sc_enable : 1;
        unsigned int gid_zero_sc : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_wakeup_rank_en_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_wakeup_rank_en_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_wakeup_ch_en_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_wakeup_ch_en_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_intlv_gran_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_intlv_gran_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_ch4_order_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_ch4_order_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_addr_shift_mode_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_addr_shift_mode_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_rank_map_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_rank_map_END (23)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_en_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_en_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_gran_START (25)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_gran_END (26)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_wakeup_prd_START (27)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_wakeup_prd_END (28)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_wakeup_sc_enable_START (29)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_ddr_wakeup_sc_enable_END (29)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_gid_zero_sc_START (30)
#define SOC_FCM_LOCAL_PERIPH_NS_PD_FAST_WAKEUP_CFG_gid_zero_sc_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_en : 4;
        unsigned int middle_core_soft_rst_en : 2;
        unsigned int big_core_soft_rst_en : 2;
        unsigned int adb_brg_m0_rst_en : 1;
        unsigned int adb_brg_m1_rst_en : 1;
        unsigned int adb_acp_rst_en : 1;
        unsigned int adb_pp_rst_en : 1;
        unsigned int big_cluster_rst_en : 1;
        unsigned int middle_cluster_rst_en : 1;
        unsigned int little_cluster_rst_en : 1;
        unsigned int atb_top_rst_en : 1;
        unsigned int atb_fcm_rst_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_little_core_soft_rst_en_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_little_core_soft_rst_en_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_middle_core_soft_rst_en_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_middle_core_soft_rst_en_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_big_core_soft_rst_en_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_big_core_soft_rst_en_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_brg_m0_rst_en_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_brg_m0_rst_en_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_brg_m1_rst_en_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_brg_m1_rst_en_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_acp_rst_en_START (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_acp_rst_en_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_pp_rst_en_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_adb_pp_rst_en_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_big_cluster_rst_en_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_big_cluster_rst_en_END (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_middle_cluster_rst_en_START (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_middle_cluster_rst_en_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_little_cluster_rst_en_START (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_little_cluster_rst_en_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_atb_top_rst_en_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_atb_top_rst_en_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_atb_fcm_rst_en_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_EN_atb_fcm_rst_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_dis : 4;
        unsigned int middle_core_soft_rst_dis : 2;
        unsigned int big_core_soft_rst_dis : 2;
        unsigned int adb_brg_m0_rst_dis : 1;
        unsigned int adb_brg_m1_rst_dis : 1;
        unsigned int adb_acp_rst_dis : 1;
        unsigned int adb_pp_rst_dis : 1;
        unsigned int big_cluster_rst_dis : 1;
        unsigned int middle_cluster_rst_dis : 1;
        unsigned int little_cluster_rst_dis : 1;
        unsigned int atb_top_rst_dis : 1;
        unsigned int atb_fcm_rst_dis : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_little_core_soft_rst_dis_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_little_core_soft_rst_dis_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_middle_core_soft_rst_dis_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_middle_core_soft_rst_dis_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_big_core_soft_rst_dis_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_big_core_soft_rst_dis_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_brg_m0_rst_dis_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_brg_m0_rst_dis_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_brg_m1_rst_dis_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_brg_m1_rst_dis_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_acp_rst_dis_START (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_acp_rst_dis_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_pp_rst_dis_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_adb_pp_rst_dis_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_big_cluster_rst_dis_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_big_cluster_rst_dis_END (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_middle_cluster_rst_dis_START (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_middle_cluster_rst_dis_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_little_cluster_rst_dis_START (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_little_cluster_rst_dis_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_atb_top_rst_dis_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_atb_top_rst_dis_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_atb_fcm_rst_dis_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_DIS_atb_fcm_rst_dis_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_stat : 4;
        unsigned int middle_core_soft_rst_stat : 2;
        unsigned int big_core_soft_rst_stat : 2;
        unsigned int adb_brg_m0_rst_stat : 1;
        unsigned int adb_brg_m1_rst_stat : 1;
        unsigned int adb_acp_rst_stat : 1;
        unsigned int adb_pp_rst_stat : 1;
        unsigned int big_cluster_rst_stat : 1;
        unsigned int middle_cluster_rst_stat : 1;
        unsigned int little_cluster_rst_stat : 1;
        unsigned int atb_top_rst_stat : 1;
        unsigned int atb_fcm_rst_stat : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_little_core_soft_rst_stat_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_little_core_soft_rst_stat_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_middle_core_soft_rst_stat_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_middle_core_soft_rst_stat_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_big_core_soft_rst_stat_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_big_core_soft_rst_stat_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_brg_m0_rst_stat_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_brg_m0_rst_stat_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_brg_m1_rst_stat_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_brg_m1_rst_stat_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_acp_rst_stat_START (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_acp_rst_stat_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_pp_rst_stat_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_adb_pp_rst_stat_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_big_cluster_rst_stat_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_big_cluster_rst_stat_END (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_middle_cluster_rst_stat_START (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_middle_cluster_rst_stat_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_little_cluster_rst_stat_START (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_little_cluster_rst_stat_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_atb_top_rst_stat_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_atb_top_rst_stat_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_atb_fcm_rst_stat_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_RST_STAT_atb_fcm_rst_stat_END (16)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_init_pstate_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_enable_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_enable_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_force_on_to_sfonly_on_END (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_cluster_preq_from_sys_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_cluster_preq_from_sys_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_cluster_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_cluster_pstate_from_sys_END (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_cluster_pactive_sel_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_cluster_pactive_sel_END (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_PCHANNEL_CFG_fcm_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way15_way12_mem_ctrl_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way15_way12_mem_ctrl_sys_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way11_way8_mem_ctrl_sys_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way11_way8_mem_ctrl_sys_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way7_way4_mem_ctrl_sys_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way7_way4_mem_ctrl_sys_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way3_way0_mem_ctrl_sys_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_data_way3_way0_mem_ctrl_sys_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_sf_mem_ctrl_sys_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_sf_mem_ctrl_sys_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_other_mem_ctrl_sys_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_other_mem_ctrl_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way15_way12_mem_ctrl_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way15_way12_mem_ctrl_sys_END (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way11_way8_mem_ctrl_sys_START (23)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way11_way8_mem_ctrl_sys_END (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way7_way4_mem_ctrl_sys_START (26)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way7_way4_mem_ctrl_sys_END (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way3_way0_mem_ctrl_sys_START (29)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_MEM_CTRL_LP_l3_tag_way3_way0_mem_ctrl_sys_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_CFG_core0_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_CFG_core1_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_CFG_core2_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_CFG_core3_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_CFG_core4_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_CFG_core5_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_CFG_core6_p_channel_enable_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_init_pstate_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_pstate_from_sys_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_preq_from_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_preq_from_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_mem_ctrl_from_sys_END (30)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_enable_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_CFG_core7_p_channel_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_data_way15_0_hisi_mem_test : 3;
        unsigned int reserved_0 : 2;
        unsigned int l3_data_way15_0_hisi_mem_tselw : 2;
        unsigned int l3_data_way15_0_hisi_mem_tra : 2;
        unsigned int l3_data_way15_0_hisi_mem_tselr : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselr_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_DATARAM_WAY_0_15_MEM_TEST_l3_data_way15_0_hisi_mem_tselr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enyo_mpmm_en : 4;
        unsigned int reserved : 12;
        unsigned int aw_cmd_ost_cfg : 8;
        unsigned int ar_cmd_ost_cfg : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_enyo_mpmm_en_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_enyo_mpmm_en_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_aw_cmd_ost_cfg_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_aw_cmd_ost_cfg_END (23)
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_ar_cmd_ost_cfg_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_ENYO_MITIGATION_CFG_ar_cmd_ost_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_tag_victim_scu_hisi_mem_test : 3;
        unsigned int reserved_0 : 2;
        unsigned int l3_tag_victim_scu_hisi_mem_tselw : 2;
        unsigned int l3_tag_victim_scu_hisi_mem_tra : 2;
        unsigned int l3_tag_victim_scu_hisi_mem_tselr : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_tselr_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_TAGRAM_VICTIM_SCU_MEM_TEST_l3_tag_victim_scu_hisi_mem_tselr_END (11)
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
} SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_normal_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_normal_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_sd_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_sd_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_dslp_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_dslp_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_slp_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_ananke_core_mem_ctl_slp_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_normal_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_normal_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_sd_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_sd_END (22)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_dslp_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_dslp_END (26)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_slp_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE_MEM_LP_CTL_enyo_big_core_mem_ctl_slp_END (30)
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
} SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_normal_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_normal_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_sd_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_sd_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_dslp_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_mem_ctl_dslp_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_core_mem_ctl_slp_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_fcm_cluster_core_mem_ctl_slp_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_normal_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_normal_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_sd_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_sd_END (22)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_dslp_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_dslp_END (26)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_slp_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_CLUSTER_MEM_LP_CTL_enyo_mid_core_mem_ctl_slp_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_ltdb_hisi_mem_test : 3;
        unsigned int l3_ltdb_hisi_mem_tselr_tp : 2;
        unsigned int l3_ltdb_hisi_mem_tselw : 2;
        unsigned int l3_ltdb_hisi_mem_tra : 2;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CLUSTER_L3_LTDB_RAM_MEM_TEST_l3_ltdb_hisi_mem_tra_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int asp_power_reg_cpu : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_ASP_POWERDN_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_ASP_POWERDN_REG_asp_power_reg_cpu_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_ASP_POWERDN_REG_asp_power_reg_cpu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_sclk_q_channel_en : 1;
        unsigned int fcm_atclk_q_channel_en : 1;
        unsigned int fcm_pclk_q_channel_en : 1;
        unsigned int fcm_gicclk_q_channel_en : 1;
        unsigned int fcm_debug_clk_q_channel_en : 1;
        unsigned int fcm_debug_pwr_q_channel_qreqn : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_sclk_q_channel_en_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_sclk_q_channel_en_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_atclk_q_channel_en_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_atclk_q_channel_en_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_pclk_q_channel_en_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_pclk_q_channel_en_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_gicclk_q_channel_en_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_gicclk_q_channel_en_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_debug_clk_q_channel_en_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_debug_clk_q_channel_en_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_debug_pwr_q_channel_qreqn_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CTL_REG_fcm_debug_pwr_q_channel_qreqn_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_sclk_q_channel_cfgcnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int fcm_atclk_q_channel_cfgcnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int fcm_pclk_q_channel_cfgcnt : 7;
        unsigned int reserved_2 : 1;
        unsigned int fcm_gicclk_q_channel_cfgcnt : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_sclk_q_channel_cfgcnt_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_sclk_q_channel_cfgcnt_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_atclk_q_channel_cfgcnt_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_atclk_q_channel_cfgcnt_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_pclk_q_channel_cfgcnt_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_pclk_q_channel_cfgcnt_END (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_gicclk_q_channel_cfgcnt_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG0_fcm_gicclk_q_channel_cfgcnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_debug_clk_q_channel_cfgcnt : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG1_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG1_fcm_debug_clk_q_channel_cfgcnt_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_QCHANNEL_CFGCNT_REG1_fcm_debug_clk_q_channel_cfgcnt_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nirq_test : 8;
        unsigned int nfiq_test : 8;
        unsigned int reserved_0 : 12;
        unsigned int giccdisable : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_nirq_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_nirq_test_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_nfiq_test_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_nfiq_test_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_giccdisable_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_GIC_TEST_CFG_REG_giccdisable_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_pchannel_wait_cycle_sd : 16;
        unsigned int fcm_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_sd_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_sd_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_CFG_REG_fcm_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core0_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core1_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core0_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core0_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core1_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_CFG_REG_fcm_core1_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core2_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core3_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core2_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core2_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core3_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_CFG_REG_fcm_core3_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core4_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core5_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core4_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core4_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core5_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_CFG_REG_fcm_core5_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_core6_pchannel_wait_cycle_dslp : 16;
        unsigned int fcm_core7_pchannel_wait_cycle_dslp : 16;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core6_pchannel_wait_cycle_dslp_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core6_pchannel_wait_cycle_dslp_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core7_pchannel_wait_cycle_dslp_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_CFG_REG_fcm_core7_pchannel_wait_cycle_dslp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_dly_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_DLYCNT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_DLYCNT_CFG_REG_fcm_dly_cnt_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_DLYCNT_CFG_REG_fcm_dly_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_flush_cache : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_FLUSH_CACHE_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_FLUSH_CACHE_CFG_REG_force_flush_cache_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_FLUSH_CACHE_CFG_REG_force_flush_cache_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_off_to_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_OFF_TO_ON_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_OFF_TO_ON_CFG_REG_force_off_to_on_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_LPM3_FORCE_OFF_TO_ON_CFG_REG_force_off_to_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_disable_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_force_disable_off_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_P_CHANNEL_DISABLE_OFF_CFG_REG_force_disable_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_hc_test : 3;
        unsigned int core0_hc_tselr_tp : 2;
        unsigned int core0_hc_tselw : 2;
        unsigned int core0_hc_tra : 2;
        unsigned int core0_hc_tselr_hchd : 3;
        unsigned int core0_hd_test : 3;
        unsigned int core0_hd_tselr_tp : 2;
        unsigned int core0_hd_tselw : 2;
        unsigned int core0_hd_tra : 2;
        unsigned int core0_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE0_HCHD_MEM_ADJUST_REG_core0_hd_tselr_hchd_END (23)
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
        unsigned int core1_hc_test : 3;
        unsigned int core1_hc_tselr_tp : 2;
        unsigned int core1_hc_tselw : 2;
        unsigned int core1_hc_tra : 2;
        unsigned int core1_hc_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core0_tp_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE01_HCTP_MEM_ADJUST_REG_core1_hc_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_hd_test : 3;
        unsigned int core1_hd_tselr_tp : 2;
        unsigned int core1_hd_tselw : 2;
        unsigned int core1_hd_tra : 2;
        unsigned int core1_hd_tselr_hchd : 3;
        unsigned int core1_tp_test : 3;
        unsigned int core1_tp_tselr_tp : 2;
        unsigned int core1_tp_tselw : 2;
        unsigned int core1_tp_tra : 2;
        unsigned int core1_tp_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_hd_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE1_HDTP_MEM_ADJUST_REG_core1_tp_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_hc_test : 3;
        unsigned int core2_hc_tselr_tp : 2;
        unsigned int core2_hc_tselw : 2;
        unsigned int core2_hc_tra : 2;
        unsigned int core2_hc_tselr_hchd : 3;
        unsigned int core2_hd_test : 3;
        unsigned int core2_hd_tselr_tp : 2;
        unsigned int core2_hd_tselw : 2;
        unsigned int core2_hd_tra : 2;
        unsigned int core2_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE2_HCHD_MEM_ADJUST_REG_core2_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_tp_test : 3;
        unsigned int core2_tp_tselr_tp : 2;
        unsigned int core2_tp_tselw : 2;
        unsigned int core2_tp_tra : 2;
        unsigned int core2_tp_tselr_hchd : 3;
        unsigned int core3_hc_test : 3;
        unsigned int core3_hc_tselr_tp : 2;
        unsigned int core3_hc_tselw : 2;
        unsigned int core3_hc_tra : 2;
        unsigned int core3_hc_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core2_tp_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE23_HCTP_MEM_ADJUST_REG_core3_hc_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core3_hd_test : 3;
        unsigned int core3_hd_tselr_tp : 2;
        unsigned int core3_hd_tselw : 2;
        unsigned int core3_hd_tra : 2;
        unsigned int core3_hd_tselr_hchd : 3;
        unsigned int core3_tp_test : 3;
        unsigned int core3_tp_tselr_tp : 2;
        unsigned int core3_tp_tselw : 2;
        unsigned int core3_tp_tra : 2;
        unsigned int core3_tp_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_hd_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE3_HDTP_MEM_ADJUST_REG_core3_tp_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_hc_test : 3;
        unsigned int core4_hc_tselr_tp : 2;
        unsigned int core4_hc_tselw : 2;
        unsigned int core4_hc_tra : 2;
        unsigned int core4_hc_tselr_hchd : 3;
        unsigned int core4_hd_test : 3;
        unsigned int core4_hd_tselr_tp : 2;
        unsigned int core4_hd_tselw : 2;
        unsigned int core4_hd_tra : 2;
        unsigned int core4_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_HCHD_MEM_ADJUST_REG_core4_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_tp_test_24x144 : 3;
        unsigned int core4_tp_tselr_tp_24x144 : 2;
        unsigned int core4_tp_tselw_24x144 : 2;
        unsigned int core4_tp_tra_24x144 : 2;
        unsigned int core4_tp_tselr_hchd_24x144 : 3;
        unsigned int core4_tp_test_64x96 : 3;
        unsigned int core4_tp_tselr_tp_64x96 : 2;
        unsigned int core4_tp_tselw_64x96 : 2;
        unsigned int core4_tp_tra_64x96 : 2;
        unsigned int core4_tp_tselr_hchd_64x96 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_test_24x144_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_test_24x144_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_tp_24x144_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_tp_24x144_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselw_24x144_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselw_24x144_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tra_24x144_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tra_24x144_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_hchd_24x144_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_hchd_24x144_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_test_64x96_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_test_64x96_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_tp_64x96_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_tp_64x96_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselw_64x96_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselw_64x96_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tra_64x96_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tra_64x96_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_hchd_64x96_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE4_TP_MEM_ADJUST_REG_core4_tp_tselr_hchd_64x96_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_hc_test : 3;
        unsigned int core5_hc_tselr_tp : 2;
        unsigned int core5_hc_tselw : 2;
        unsigned int core5_hc_tra : 2;
        unsigned int core5_hc_tselr_hchd : 3;
        unsigned int core5_hd_test : 3;
        unsigned int core5_hd_tselr_tp : 2;
        unsigned int core5_hd_tselw : 2;
        unsigned int core5_hd_tra : 2;
        unsigned int core5_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_HCHD_MEM_ADJUST_REG_core5_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_tp_test_24x144 : 3;
        unsigned int core5_tp_tselr_tp_24x144 : 2;
        unsigned int core5_tp_tselw_24x144 : 2;
        unsigned int core5_tp_tra_24x144 : 2;
        unsigned int core5_tp_tselr_hchd_24x144 : 3;
        unsigned int core5_tp_test_64x96 : 3;
        unsigned int core5_tp_tselr_tp_64x96 : 2;
        unsigned int core5_tp_tselw_64x96 : 2;
        unsigned int core5_tp_tra_64x96 : 2;
        unsigned int core5_tp_tselr_hchd_64x96 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_test_24x144_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_test_24x144_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_tp_24x144_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_tp_24x144_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselw_24x144_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselw_24x144_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tra_24x144_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tra_24x144_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_hchd_24x144_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_hchd_24x144_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_test_64x96_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_test_64x96_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_tp_64x96_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_tp_64x96_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselw_64x96_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselw_64x96_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tra_64x96_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tra_64x96_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_hchd_64x96_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE5_TP_MEM_ADJUST_REG_core5_tp_tselr_hchd_64x96_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_hc_test : 3;
        unsigned int core6_hc_tselr_tp : 2;
        unsigned int core6_hc_tselw : 2;
        unsigned int core6_hc_tra : 2;
        unsigned int core6_hc_tselr_hchd : 3;
        unsigned int core6_hd_test : 3;
        unsigned int core6_hd_tselr_tp : 2;
        unsigned int core6_hd_tselw : 2;
        unsigned int core6_hd_tra : 2;
        unsigned int core6_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_HCHD_MEM_ADJUST_REG_core6_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_tp_test_24x144 : 3;
        unsigned int core6_tp_tselr_tp_24x144 : 2;
        unsigned int core6_tp_tselw_24x144 : 2;
        unsigned int core6_tp_tra_24x144 : 2;
        unsigned int core6_tp_tselr_hchd_24x144 : 3;
        unsigned int core6_tp_test_64x96 : 3;
        unsigned int core6_tp_tselr_tp_64x96 : 2;
        unsigned int core6_tp_tselw_64x96 : 2;
        unsigned int core6_tp_tra_64x96 : 2;
        unsigned int core6_tp_tselr_hchd_64x96 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_test_24x144_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_test_24x144_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_tp_24x144_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_tp_24x144_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselw_24x144_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselw_24x144_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tra_24x144_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tra_24x144_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_hchd_24x144_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_hchd_24x144_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_test_64x96_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_test_64x96_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_tp_64x96_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_tp_64x96_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselw_64x96_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselw_64x96_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tra_64x96_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tra_64x96_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_hchd_64x96_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE6_TP_MEM_ADJUST_REG_core6_tp_tselr_hchd_64x96_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_hc_test : 3;
        unsigned int core7_hc_tselr_tp : 2;
        unsigned int core7_hc_tselw : 2;
        unsigned int core7_hc_tra : 2;
        unsigned int core7_hc_tselr_hchd : 3;
        unsigned int core7_hd_test : 3;
        unsigned int core7_hd_tselr_tp : 2;
        unsigned int core7_hd_tselw : 2;
        unsigned int core7_hd_tra : 2;
        unsigned int core7_hd_tselr_hchd : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_test_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_test_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tselr_tp_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tselr_tp_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tselw_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tselw_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tra_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tra_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tselr_hchd_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hc_tselr_hchd_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_test_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_test_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tselr_tp_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tselr_tp_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tselw_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tselw_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tra_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tra_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tselr_hchd_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_HCHD_MEM_ADJUST_REG_core7_hd_tselr_hchd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_tp_test_24x144 : 3;
        unsigned int core7_tp_tselr_tp_24x144 : 2;
        unsigned int core7_tp_tselw_24x144 : 2;
        unsigned int core7_tp_tra_24x144 : 2;
        unsigned int core7_tp_tselr_hchd_24x144 : 3;
        unsigned int core7_tp_test_64x96 : 3;
        unsigned int core7_tp_tselr_tp_64x96 : 2;
        unsigned int core7_tp_tselw_64x96 : 2;
        unsigned int core7_tp_tra_64x96 : 2;
        unsigned int core7_tp_tselr_hchd_64x96 : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_test_24x144_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_test_24x144_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_tp_24x144_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_tp_24x144_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselw_24x144_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselw_24x144_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tra_24x144_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tra_24x144_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_hchd_24x144_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_hchd_24x144_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_test_64x96_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_test_64x96_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_tp_64x96_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_tp_64x96_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselw_64x96_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselw_64x96_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tra_64x96_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tra_64x96_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_hchd_64x96_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_CORE7_TP_MEM_ADJUST_REG_core7_tp_tselr_hchd_64x96_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_ar_nsaid_mid : 8;
        unsigned int m0_aw_nsaid_mid : 8;
        unsigned int m1_ar_nsaid_mid : 8;
        unsigned int m1_aw_nsaid_mid : 8;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m0_ar_nsaid_mid_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m0_ar_nsaid_mid_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m0_aw_nsaid_mid_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m0_aw_nsaid_mid_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m1_ar_nsaid_mid_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m1_ar_nsaid_mid_END (23)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m1_aw_nsaid_mid_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_NSAID_MID_m1_aw_nsaid_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int karma_mem_ctrl_ls : 1;
        unsigned int karma_mem_ctrl_ds : 1;
        unsigned int karma_mem_ctrl_sd : 1;
        unsigned int reserved_0 : 1;
        unsigned int karma_mem_ctrl_tselr : 2;
        unsigned int karma_mem_ctrl_tselw : 2;
        unsigned int karma_mem_ctrl_test : 3;
        unsigned int karma_mem_ctrl_tra : 2;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_ls_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_ls_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_ds_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_ds_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_sd_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_sd_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_tselr_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_tselr_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_tselw_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_tselw_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_test_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_test_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_tra_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_KARMA_MEM_CTRL_karma_mem_ctrl_tra_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcr_mem_ctrl_ls : 1;
        unsigned int pcr_mem_ctrl_ds : 1;
        unsigned int pcr_mem_ctrl_sd : 1;
        unsigned int reserved_0 : 1;
        unsigned int pcr_mem_ctrl_tselr : 2;
        unsigned int pcr_mem_ctrl_tselw : 2;
        unsigned int pcr_mem_ctrl_test : 3;
        unsigned int pcr_mem_ctrl_tra : 2;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_ls_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_ls_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_ds_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_ds_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_sd_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_sd_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_tselr_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_tselr_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_tselw_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_tselw_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_test_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_test_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_tra_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_PCR_MEM_CTRL_pcr_mem_ctrl_tra_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int atclk_qacceptn : 1;
        unsigned int atclk_qactive : 1;
        unsigned int atclk_qdeny : 1;
        unsigned int atclk_qreqn : 1;
        unsigned int gicclk_qacceptn : 1;
        unsigned int gicclk_qactive : 1;
        unsigned int gicclk_qdeny : 1;
        unsigned int gicclk_qreqn : 1;
        unsigned int pclk_qacceptn : 1;
        unsigned int pclk_qactive : 1;
        unsigned int pclk_qdeny : 1;
        unsigned int pclk_qreqn : 1;
        unsigned int sclk_qacceptn : 1;
        unsigned int sclk_qactive : 1;
        unsigned int sclk_qdeny : 1;
        unsigned int sclk_qreqn : 1;
        unsigned int pdbgclk_qacceptn : 1;
        unsigned int pdbgclk_qactive : 1;
        unsigned int pdbgtclk_qdeny : 1;
        unsigned int pdbgtclk_qreqn : 1;
        unsigned int pwr_qacceptn : 1;
        unsigned int pwr_qactive : 1;
        unsigned int pwr_qdeny : 1;
        unsigned int pwr_qreqn : 1;
        unsigned int awakeupm0 : 1;
        unsigned int awakeupm1 : 1;
        unsigned int awakeupmp : 1;
        unsigned int acp_valid_comb : 1;
        unsigned int clusterdbgpwrupreq : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qacceptn_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qacceptn_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qactive_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qactive_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qdeny_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qdeny_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qreqn_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_atclk_qreqn_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qacceptn_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qacceptn_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qactive_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qactive_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qdeny_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qdeny_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qreqn_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_gicclk_qreqn_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qacceptn_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qacceptn_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qactive_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qactive_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qdeny_START (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qdeny_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qreqn_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pclk_qreqn_END (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qacceptn_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qacceptn_END (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qactive_START (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qactive_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qdeny_START (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qdeny_END (14)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qreqn_START (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_sclk_qreqn_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgclk_qacceptn_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgclk_qacceptn_END (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgclk_qactive_START (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgclk_qactive_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgtclk_qdeny_START (18)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgtclk_qdeny_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgtclk_qreqn_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pdbgtclk_qreqn_END (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qacceptn_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qacceptn_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qactive_START (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qactive_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qdeny_START (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qdeny_END (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qreqn_START (23)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_pwr_qreqn_END (23)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_awakeupm0_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_awakeupm0_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_awakeupm1_START (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_awakeupm1_END (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_awakeupmp_START (26)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_awakeupmp_END (26)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_acp_valid_comb_START (27)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_acp_valid_comb_END (27)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_clusterdbgpwrupreq_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT0_clusterdbgpwrupreq_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int standbywfi_pdc_core : 8;
        unsigned int standbywfi_vdm_core : 8;
        unsigned int standbywfe_core : 8;
        unsigned int standbywfi_pdc_fcm : 1;
        unsigned int standbywfi_vdm_fcm : 1;
        unsigned int standbywfe_fcm : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_pdc_core_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_pdc_core_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_vdm_core_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_vdm_core_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfe_core_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfe_core_END (23)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_pdc_fcm_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_pdc_fcm_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_vdm_fcm_START (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfi_vdm_fcm_END (25)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfe_fcm_START (26)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT1_standbywfe_fcm_END (26)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_pactive_to_sys_END (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_cluster_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_cluster_can_pd_END (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_forced_on_sfonly_complete_START (31)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT2_forced_on_sfonly_complete_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT3_core_can_pd_END (28)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT4_core_can_pd_END (28)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT5_core_can_pd_END (28)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT6_core_can_pd_END (28)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT7_core_can_pd_END (28)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT8_core_can_pd_END (28)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT9_core_can_pd_END (28)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_pactive_to_sys_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_pactive_to_sys_END (17)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_paccept_to_sys_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_paccept_to_sys_END (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_pdeny_to_sys_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_pdeny_to_sys_END (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_core_can_pd_START (28)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT10_core_can_pd_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coreinstrrun : 8;
        unsigned int coreinstrret : 8;
        unsigned int pmusnapshotack : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_coreinstrrun_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_coreinstrrun_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_coreinstrret_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_coreinstrret_END (15)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_pmusnapshotack_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT11_pmusnapshotack_END (16)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_PCHANNEL_STAT_cluster_pactive_END (31)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE0_PCHANNEL_STAT_core_pactive_END (29)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE1_PCHANNEL_STAT_core_pactive_END (29)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE2_PCHANNEL_STAT_core_pactive_END (29)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE3_PCHANNEL_STAT_core_pactive_END (29)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE4_PCHANNEL_STAT_core_pactive_END (29)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE5_PCHANNEL_STAT_core_pactive_END (29)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE6_PCHANNEL_STAT_core_pactive_END (29)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_paccept_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_paccept_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_pdeny_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_pdeny_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_preq_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_preq_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_pstate_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_pstate_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_pactive_START (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE7_PCHANNEL_STAT_core_pactive_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_cluster_iso_en : 1;
        unsigned int dft_mrb_signals : 21;
        unsigned int hard_mtcmos_sel : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_fcm_cluster_iso_en_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_fcm_cluster_iso_en_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_dft_mrb_signals_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_dft_mrb_signals_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_hard_mtcmos_sel_START (22)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT21_hard_mtcmos_sel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbgack : 8;
        unsigned int dbgpwrupreq : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT22_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT22_dbgack_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT22_dbgack_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT22_dbgpwrupreq_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT22_dbgpwrupreq_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_aps_dpm : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT23_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT23_intr_aps_dpm_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT23_intr_aps_dpm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_cnt_m0 : 6;
        unsigned int reserved_0 : 2;
        unsigned int snoop_cnt_m1 : 6;
        unsigned int reserved_1 : 2;
        unsigned int ar_cnt_acp : 6;
        unsigned int reserved_2 : 2;
        unsigned int aw_cnt_acp : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_snoop_cnt_m0_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_snoop_cnt_m0_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_snoop_cnt_m1_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_snoop_cnt_m1_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_ar_cnt_acp_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_ar_cnt_acp_END (21)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_aw_cnt_acp_START (24)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT24_aw_cnt_acp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_cnt_acp : 6;
        unsigned int reserved_0: 2;
        unsigned int b_cnt_acp : 6;
        unsigned int reserved_1: 2;
        unsigned int r_cnt_acp : 6;
        unsigned int reserved_2: 10;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_w_cnt_acp_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_w_cnt_acp_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_b_cnt_acp_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_b_cnt_acp_END (13)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_r_cnt_acp_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT25_r_cnt_acp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acp_arvalid : 1;
        unsigned int acp_arready : 1;
        unsigned int acp_rvalid : 1;
        unsigned int acp_rready : 1;
        unsigned int acp_awvalid : 1;
        unsigned int acp_awready : 1;
        unsigned int acp_wvalid : 1;
        unsigned int acp_wready : 1;
        unsigned int acp_wlast : 1;
        unsigned int acp_bvalid : 1;
        unsigned int acp_bready : 1;
        unsigned int acp_rlast : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_arvalid_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_arvalid_END (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_arready_START (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_arready_END (1)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_rvalid_START (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_rvalid_END (2)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_rready_START (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_rready_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_awvalid_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_awvalid_END (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_awready_START (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_awready_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_wvalid_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_wvalid_END (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_wready_START (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_wready_END (7)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_wlast_START (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_wlast_END (8)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_bvalid_START (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_bvalid_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_bready_START (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_bready_END (10)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_rlast_START (11)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_LOCAL_STAT26_acp_rlast_END (11)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state0_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state0_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate0_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state1_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_current_state1_END (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE01_PCHANNEL_DEBUG_STAT_core_pstate1_END (25)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state2_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state2_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate2_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state3_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_current_state3_END (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE23_PCHANNEL_DEBUG_STAT_core_pstate3_END (25)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state4_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state4_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate4_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state5_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_current_state5_END (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE45_PCHANNEL_DEBUG_STAT_core_pstate5_END (25)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state6_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state6_END (3)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_START (4)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate6_END (9)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state7_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_current_state7_END (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_START (20)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_CORE67_PCHANNEL_DEBUG_STAT_core_pstate7_END (25)
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
} SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_UNION;
#endif
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_START (0)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_END (5)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_pstate_START (6)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_pstate_END (12)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_flush_cache_START (16)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_current_state_flush_cache_END (18)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_off_flush_cache_valid_START (19)
#define SOC_FCM_LOCAL_PERIPH_NS_FCM_FCM_PCHANNEL_DEBUG_STAT_cluster_off_flush_cache_valid_END (19)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
