#ifndef __SOC_ASP_SOUNDWIRE_INTERFACE_H__
#define __SOC_ASP_SOUNDWIRE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ASP_SoundWire_DP0_INTSTAT_ADDR(base) ((base) + (0x00UL))
#define SOC_ASP_SoundWire_DP0_INTMASK_ADDR(base) ((base) + (0x01UL))
#define SOC_ASP_SoundWire_DP0_PORTCTRL_ADDR(base) ((base) + (0x02UL))
#define SOC_ASP_SoundWire_DP0_BLOCKCTRL1_ADDR(base) ((base) + (0x03UL))
#define SOC_ASP_SoundWire_DP0_PREPARESTATUS_ADDR(base) ((base) + (0x04UL))
#define SOC_ASP_SoundWire_DP0_PREPARECTRL_ADDR(base) ((base) + (0x05UL))
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK0_ADDR(base) ((base) + (0x20UL))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x22UL))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x23UL))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x24UL))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x25UL))
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK0_ADDR(base) ((base) + (0x26UL))
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK0_ADDR(base) ((base) + (0x28UL))
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK1_ADDR(base) ((base) + (0x30UL))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x32UL))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x33UL))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x34UL))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x35UL))
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK1_ADDR(base) ((base) + (0x36UL))
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK1_ADDR(base) ((base) + (0x38UL))
#define SOC_ASP_SoundWire_DP_IntStat1_ADDR(base) ((base) + (0x40UL))
#define SOC_ASP_SoundWire_DP_IntStat2_ADDR(base) ((base) + (0x42UL))
#define SOC_ASP_SoundWire_DP_IntStat3_ADDR(base) ((base) + (0x43UL))
#define SOC_ASP_SoundWire_SCP_DEVNUMBER_ADDR(base) ((base) + (0x46UL))
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK0_ADDR(base) ((base) + (0x60UL))
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK1_ADDR(base) ((base) + (0x70UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_ADDR(base) ((base) + (0x80UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_ADDR(base) ((base) + (0x81UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_ADDR(base) ((base) + (0x82UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN4_ADDR(base) ((base) + (0x83UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN5_ADDR(base) ((base) + (0x84UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_ADDR(base) ((base) + (0x85UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_ADDR(base) ((base) + (0x86UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN8_ADDR(base) ((base) + (0x87UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_ADDR(base) ((base) + (0x88UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_ADDR(base) ((base) + (0x89UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_ADDR(base) ((base) + (0x8AUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN4_ADDR(base) ((base) + (0x8BUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN5_ADDR(base) ((base) + (0x8CUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_ADDR(base) ((base) + (0x8DUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_ADDR(base) ((base) + (0x8EUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN8_ADDR(base) ((base) + (0x8FUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKDIVCTRL_ADDR(base) ((base) + (0x90UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLK_WAKEUP_EN_ADDR(base) ((base) + (0x91UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_TEST_MONITOR_ADDR(base) ((base) + (0x92UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_ADDR(base) ((base) + (0x93UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_REG_SEL_ADDR(base) ((base) + (0x9FUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_FIFO_LOOP_EN_ADDR(base) ((base) + (0xA0UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_ADDR(base) ((base) + (0xA1UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL2_ADDR(base) ((base) + (0xA2UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_SOURCESINK_CFG2_ADDR(base) ((base) + (0xA3UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_ADDR(base) ((base) + (0xA4UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_ADDR(base) ((base) + (0xA5UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_ADDR(base) ((base) + (0xA6UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG2_ADDR(base) ((base) + (0xA7UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_TEST_PROC_SEL_ADDR(base) ((base) + (0xA8UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_SYNC_TIMEOUT_ADDR(base) ((base) + (0xA9UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_ENUM_TIMEOUT_ADDR(base) ((base) + (0xAAUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_ADDR(base) ((base) + (0xC0UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_ADDR(base) ((base) + (0xC1UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_ADDR(base) ((base) + (0xC2UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_ADDR(base) ((base) + (0xC3UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_ADDR(base) ((base) + (0xC4UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_ADDR(base) ((base) + (0xC5UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT3_ADDR(base) ((base) + (0xC6UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK3_ADDR(base) ((base) + (0xC7UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT3_ADDR(base) ((base) + (0xC8UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_ADDR(base) ((base) + (0xC9UL))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_ADDR(base) ((base) + (0xCAUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_ADDR(base) ((base) + (0xCBUL))
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_ADDR(base) ((base) + (0xCCUL))
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_ADDR(base) ((base) + (0xCDUL))
#define SOC_ASP_SoundWire_DEBUG_OUT_0_ADDR(base) ((base) + (0xDFUL))
#define SOC_ASP_SoundWire_DEBUG_OUT_1_ADDR(base) ((base) + (0xE0UL))
#define SOC_ASP_SoundWire_DEBUG_OUT_2_ADDR(base) ((base) + (0xE1UL))
#define SOC_ASP_SoundWire_DEBUG_OUT_3_ADDR(base) ((base) + (0xE2UL))
#define SOC_ASP_SoundWire_DEBUG_OUT_4_ADDR(base) ((base) + (0xE3UL))
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL0_ADDR(base) ((base) + (0xE4UL))
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL1_ADDR(base) ((base) + (0xE5UL))
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL2_ADDR(base) ((base) + (0xE6UL))
#define SOC_ASP_SoundWire_DP1_FIFO_THRE_CTRL_ADDR(base) ((base) + (0xE7UL))
#define SOC_ASP_SoundWire_DP_FIFO_THRE_CTRL_ADDR(base) ((base) + (0xE8UL))
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_ADDR(base) ((base) + (0xF5UL))
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_ADDR(base) ((base) + (0xF6UL))
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_ADDR(base) ((base) + (0xF7UL))
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_ADDR(base) ((base) + (0xF8UL))
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_ADDR(base) ((base) + (0xF9UL))
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_ADDR(base) ((base) + (0xFAUL))
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_ADDR(base) ((base) + (0xFBUL))
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_ADDR(base) ((base) + (0xFCUL))
#define SOC_ASP_SoundWire_SOUNDWIRE_VERSION_ADDR(base) ((base) + (0x0FFUL))
#define SOC_ASP_SoundWire_DP1_INTSTAT_ADDR(base) ((base) + (0x100UL))
#define SOC_ASP_SoundWire_DP1_INTMASK_ADDR(base) ((base) + (0x101UL))
#define SOC_ASP_SoundWire_DP1_PORTCTRL_ADDR(base) ((base) + (0x102UL))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL1_ADDR(base) ((base) + (0x103UL))
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_ADDR(base) ((base) + (0x104UL))
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_ADDR(base) ((base) + (0x105UL))
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_ADDR(base) ((base) + (0x120UL))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x121UL))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x122UL))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x123UL))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x124UL))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x125UL))
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK0_ADDR(base) ((base) + (0x126UL))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x127UL))
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK0_ADDR(base) ((base) + (0x128UL))
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_ADDR(base) ((base) + (0x130UL))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x131UL))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x132UL))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x133UL))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x134UL))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x135UL))
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK1_ADDR(base) ((base) + (0x136UL))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x137UL))
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK1_ADDR(base) ((base) + (0x138UL))
#define SOC_ASP_SoundWire_DP2_INTSTAT_ADDR(base) ((base) + (0x200UL))
#define SOC_ASP_SoundWire_DP2_INTMASK_ADDR(base) ((base) + (0x201UL))
#define SOC_ASP_SoundWire_DP2_PORTCTRL_ADDR(base) ((base) + (0x202UL))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL1_ADDR(base) ((base) + (0x203UL))
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_ADDR(base) ((base) + (0x204UL))
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_ADDR(base) ((base) + (0x205UL))
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_ADDR(base) ((base) + (0x220UL))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x221UL))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x222UL))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x223UL))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x224UL))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x225UL))
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK0_ADDR(base) ((base) + (0x226UL))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x227UL))
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK0_ADDR(base) ((base) + (0x228UL))
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_ADDR(base) ((base) + (0x230UL))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x231UL))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x232UL))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x233UL))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x234UL))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x235UL))
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK1_ADDR(base) ((base) + (0x236UL))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x237UL))
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK1_ADDR(base) ((base) + (0x238UL))
#define SOC_ASP_SoundWire_DP3_INTSTAT_ADDR(base) ((base) + (0x300UL))
#define SOC_ASP_SoundWire_DP3_INTMASK_ADDR(base) ((base) + (0x301UL))
#define SOC_ASP_SoundWire_DP3_PORTCTRL_ADDR(base) ((base) + (0x302UL))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL1_ADDR(base) ((base) + (0x303UL))
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_ADDR(base) ((base) + (0x304UL))
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_ADDR(base) ((base) + (0x305UL))
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_ADDR(base) ((base) + (0x320UL))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x321UL))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x322UL))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x323UL))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x324UL))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x325UL))
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK0_ADDR(base) ((base) + (0x326UL))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x327UL))
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK0_ADDR(base) ((base) + (0x328UL))
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_ADDR(base) ((base) + (0x330UL))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x331UL))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x332UL))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x333UL))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x334UL))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x335UL))
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK1_ADDR(base) ((base) + (0x336UL))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x337UL))
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK1_ADDR(base) ((base) + (0x338UL))
#define SOC_ASP_SoundWire_DP4_INTSTAT_ADDR(base) ((base) + (0x400UL))
#define SOC_ASP_SoundWire_DP4_INTMASK_ADDR(base) ((base) + (0x401UL))
#define SOC_ASP_SoundWire_DP4_PORTCTRL_ADDR(base) ((base) + (0x402UL))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL1_ADDR(base) ((base) + (0x403UL))
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_ADDR(base) ((base) + (0x404UL))
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_ADDR(base) ((base) + (0x405UL))
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_ADDR(base) ((base) + (0x420UL))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x421UL))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x422UL))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x423UL))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x424UL))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x425UL))
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK0_ADDR(base) ((base) + (0x426UL))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x427UL))
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK0_ADDR(base) ((base) + (0x428UL))
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_ADDR(base) ((base) + (0x430UL))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x431UL))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x432UL))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x433UL))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x434UL))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x435UL))
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK1_ADDR(base) ((base) + (0x436UL))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x437UL))
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK1_ADDR(base) ((base) + (0x438UL))
#define SOC_ASP_SoundWire_DP5_INTSTAT_ADDR(base) ((base) + (0x500UL))
#define SOC_ASP_SoundWire_DP5_INTMASK_ADDR(base) ((base) + (0x501UL))
#define SOC_ASP_SoundWire_DP5_PORTCTRL_ADDR(base) ((base) + (0x502UL))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL1_ADDR(base) ((base) + (0x503UL))
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_ADDR(base) ((base) + (0x504UL))
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_ADDR(base) ((base) + (0x505UL))
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_ADDR(base) ((base) + (0x520UL))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x521UL))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x522UL))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x523UL))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x524UL))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x525UL))
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK0_ADDR(base) ((base) + (0x526UL))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x527UL))
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK0_ADDR(base) ((base) + (0x528UL))
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_ADDR(base) ((base) + (0x530UL))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x531UL))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x532UL))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x533UL))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x534UL))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x535UL))
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK1_ADDR(base) ((base) + (0x536UL))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x537UL))
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK1_ADDR(base) ((base) + (0x538UL))
#define SOC_ASP_SoundWire_DP6_INTSTAT_ADDR(base) ((base) + (0x600UL))
#define SOC_ASP_SoundWire_DP6_INTMASK_ADDR(base) ((base) + (0x601UL))
#define SOC_ASP_SoundWire_DP6_PORTCTRL_ADDR(base) ((base) + (0x602UL))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL1_ADDR(base) ((base) + (0x603UL))
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_ADDR(base) ((base) + (0x604UL))
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_ADDR(base) ((base) + (0x605UL))
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_ADDR(base) ((base) + (0x620UL))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x621UL))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x622UL))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x623UL))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x624UL))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x625UL))
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK0_ADDR(base) ((base) + (0x626UL))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x627UL))
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK0_ADDR(base) ((base) + (0x628UL))
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_ADDR(base) ((base) + (0x630UL))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x631UL))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x632UL))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x633UL))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x634UL))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x635UL))
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK1_ADDR(base) ((base) + (0x636UL))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x637UL))
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK1_ADDR(base) ((base) + (0x638UL))
#define SOC_ASP_SoundWire_DP7_INTSTAT_ADDR(base) ((base) + (0x700UL))
#define SOC_ASP_SoundWire_DP7_INTMASK_ADDR(base) ((base) + (0x701UL))
#define SOC_ASP_SoundWire_DP7_PORTCTRL_ADDR(base) ((base) + (0x702UL))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL1_ADDR(base) ((base) + (0x703UL))
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_ADDR(base) ((base) + (0x704UL))
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_ADDR(base) ((base) + (0x705UL))
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_ADDR(base) ((base) + (0x720UL))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x721UL))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x722UL))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x723UL))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x724UL))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x725UL))
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK0_ADDR(base) ((base) + (0x726UL))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x727UL))
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK0_ADDR(base) ((base) + (0x728UL))
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_ADDR(base) ((base) + (0x730UL))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x731UL))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x732UL))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x733UL))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x734UL))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x735UL))
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK1_ADDR(base) ((base) + (0x736UL))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x737UL))
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK1_ADDR(base) ((base) + (0x738UL))
#define SOC_ASP_SoundWire_DP8_INTSTAT_ADDR(base) ((base) + (0x800UL))
#define SOC_ASP_SoundWire_DP8_INTMASK_ADDR(base) ((base) + (0x801UL))
#define SOC_ASP_SoundWire_DP8_PORTCTRL_ADDR(base) ((base) + (0x802UL))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL1_ADDR(base) ((base) + (0x803UL))
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_ADDR(base) ((base) + (0x804UL))
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_ADDR(base) ((base) + (0x805UL))
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_ADDR(base) ((base) + (0x820UL))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x821UL))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x822UL))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x823UL))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x824UL))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x825UL))
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK0_ADDR(base) ((base) + (0x826UL))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x827UL))
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK0_ADDR(base) ((base) + (0x828UL))
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_ADDR(base) ((base) + (0x830UL))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x831UL))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x832UL))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x833UL))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x834UL))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x835UL))
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK1_ADDR(base) ((base) + (0x836UL))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x837UL))
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK1_ADDR(base) ((base) + (0x838UL))
#define SOC_ASP_SoundWire_DP9_INTSTAT_ADDR(base) ((base) + (0x900UL))
#define SOC_ASP_SoundWire_DP9_INTMASK_ADDR(base) ((base) + (0x901UL))
#define SOC_ASP_SoundWire_DP9_PORTCTRL_ADDR(base) ((base) + (0x902UL))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL1_ADDR(base) ((base) + (0x903UL))
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_ADDR(base) ((base) + (0x904UL))
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_ADDR(base) ((base) + (0x905UL))
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_ADDR(base) ((base) + (0x920UL))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x921UL))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x922UL))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x923UL))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x924UL))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x925UL))
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK0_ADDR(base) ((base) + (0x926UL))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x927UL))
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK0_ADDR(base) ((base) + (0x928UL))
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_ADDR(base) ((base) + (0x930UL))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x931UL))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x932UL))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x933UL))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x934UL))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x935UL))
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK1_ADDR(base) ((base) + (0x936UL))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x937UL))
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK1_ADDR(base) ((base) + (0x938UL))
#define SOC_ASP_SoundWire_DP10_INTSTAT_ADDR(base) ((base) + (0xA00UL))
#define SOC_ASP_SoundWire_DP10_INTMASK_ADDR(base) ((base) + (0xA01UL))
#define SOC_ASP_SoundWire_DP10_PORTCTRL_ADDR(base) ((base) + (0xA02UL))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL1_ADDR(base) ((base) + (0xA03UL))
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_ADDR(base) ((base) + (0xA04UL))
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_ADDR(base) ((base) + (0xA05UL))
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_ADDR(base) ((base) + (0xA20UL))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xA21UL))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xA22UL))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xA23UL))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xA24UL))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xA25UL))
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK0_ADDR(base) ((base) + (0xA26UL))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xA27UL))
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK0_ADDR(base) ((base) + (0xA28UL))
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_ADDR(base) ((base) + (0xA30UL))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xA31UL))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xA32UL))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xA33UL))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xA34UL))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xA35UL))
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK1_ADDR(base) ((base) + (0xA36UL))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xA37UL))
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK1_ADDR(base) ((base) + (0xA38UL))
#define SOC_ASP_SoundWire_DP11_INTSTAT_ADDR(base) ((base) + (0xB00UL))
#define SOC_ASP_SoundWire_DP11_INTMASK_ADDR(base) ((base) + (0xB01UL))
#define SOC_ASP_SoundWire_DP11_PORTCTRL_ADDR(base) ((base) + (0xB02UL))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL1_ADDR(base) ((base) + (0xB03UL))
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_ADDR(base) ((base) + (0xB04UL))
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_ADDR(base) ((base) + (0xB05UL))
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_ADDR(base) ((base) + (0xB20UL))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xB21UL))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xB22UL))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xB23UL))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xB24UL))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xB25UL))
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK0_ADDR(base) ((base) + (0xB26UL))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xB27UL))
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK0_ADDR(base) ((base) + (0xB28UL))
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_ADDR(base) ((base) + (0xB30UL))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xB31UL))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xB32UL))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xB33UL))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xB34UL))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xB35UL))
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK1_ADDR(base) ((base) + (0xB36UL))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xB37UL))
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK1_ADDR(base) ((base) + (0xB38UL))
#define SOC_ASP_SoundWire_DP12_INTSTAT_ADDR(base) ((base) + (0xC00UL))
#define SOC_ASP_SoundWire_DP12_INTMASK_ADDR(base) ((base) + (0xC01UL))
#define SOC_ASP_SoundWire_DP12_PORTCTRL_ADDR(base) ((base) + (0xC02UL))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL1_ADDR(base) ((base) + (0xC03UL))
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_ADDR(base) ((base) + (0xC04UL))
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_ADDR(base) ((base) + (0xC05UL))
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_ADDR(base) ((base) + (0xC20UL))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xC21UL))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xC22UL))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xC23UL))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xC24UL))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xC25UL))
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK0_ADDR(base) ((base) + (0xC26UL))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xC27UL))
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK0_ADDR(base) ((base) + (0xC28UL))
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_ADDR(base) ((base) + (0xC30UL))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xC31UL))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xC32UL))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xC33UL))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xC34UL))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xC35UL))
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK1_ADDR(base) ((base) + (0xC36UL))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xC37UL))
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK1_ADDR(base) ((base) + (0xC38UL))
#define SOC_ASP_SoundWire_DP13_INTSTAT_ADDR(base) ((base) + (0xD00UL))
#define SOC_ASP_SoundWire_DP13_INTMASK_ADDR(base) ((base) + (0xD01UL))
#define SOC_ASP_SoundWire_DP13_PORTCTRL_ADDR(base) ((base) + (0xD02UL))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL1_ADDR(base) ((base) + (0xD03UL))
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_ADDR(base) ((base) + (0xD04UL))
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_ADDR(base) ((base) + (0xD05UL))
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_ADDR(base) ((base) + (0xD20UL))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xD21UL))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xD22UL))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xD23UL))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xD24UL))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xD25UL))
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK0_ADDR(base) ((base) + (0xD26UL))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xD27UL))
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK0_ADDR(base) ((base) + (0xD28UL))
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_ADDR(base) ((base) + (0xD30UL))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xD31UL))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xD32UL))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xD33UL))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xD34UL))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xD35UL))
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK1_ADDR(base) ((base) + (0xD36UL))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xD37UL))
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK1_ADDR(base) ((base) + (0xD38UL))
#define SOC_ASP_SoundWire_DP14_INTSTAT_ADDR(base) ((base) + (0xE00UL))
#define SOC_ASP_SoundWire_DP14_INTMASK_ADDR(base) ((base) + (0xE01UL))
#define SOC_ASP_SoundWire_DP14_PORTCTRL_ADDR(base) ((base) + (0xE02UL))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL1_ADDR(base) ((base) + (0xE03UL))
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_ADDR(base) ((base) + (0xE04UL))
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_ADDR(base) ((base) + (0xE05UL))
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_ADDR(base) ((base) + (0xE20UL))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xE21UL))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xE22UL))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xE23UL))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xE24UL))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xE25UL))
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK0_ADDR(base) ((base) + (0xE26UL))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xE27UL))
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK0_ADDR(base) ((base) + (0xE28UL))
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_ADDR(base) ((base) + (0xE30UL))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xE31UL))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xE32UL))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xE33UL))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xE34UL))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xE35UL))
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK1_ADDR(base) ((base) + (0xE36UL))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xE37UL))
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK1_ADDR(base) ((base) + (0xE38UL))
#else
#define SOC_ASP_SoundWire_DP0_INTSTAT_ADDR(base) ((base) + (0x00))
#define SOC_ASP_SoundWire_DP0_INTMASK_ADDR(base) ((base) + (0x01))
#define SOC_ASP_SoundWire_DP0_PORTCTRL_ADDR(base) ((base) + (0x02))
#define SOC_ASP_SoundWire_DP0_BLOCKCTRL1_ADDR(base) ((base) + (0x03))
#define SOC_ASP_SoundWire_DP0_PREPARESTATUS_ADDR(base) ((base) + (0x04))
#define SOC_ASP_SoundWire_DP0_PREPARECTRL_ADDR(base) ((base) + (0x05))
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK0_ADDR(base) ((base) + (0x20))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x22))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x23))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x24))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x25))
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK0_ADDR(base) ((base) + (0x26))
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK0_ADDR(base) ((base) + (0x28))
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK1_ADDR(base) ((base) + (0x30))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x32))
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x33))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x34))
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x35))
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK1_ADDR(base) ((base) + (0x36))
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK1_ADDR(base) ((base) + (0x38))
#define SOC_ASP_SoundWire_DP_IntStat1_ADDR(base) ((base) + (0x40))
#define SOC_ASP_SoundWire_DP_IntStat2_ADDR(base) ((base) + (0x42))
#define SOC_ASP_SoundWire_DP_IntStat3_ADDR(base) ((base) + (0x43))
#define SOC_ASP_SoundWire_SCP_DEVNUMBER_ADDR(base) ((base) + (0x46))
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK0_ADDR(base) ((base) + (0x60))
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK1_ADDR(base) ((base) + (0x70))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_ADDR(base) ((base) + (0x80))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_ADDR(base) ((base) + (0x81))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_ADDR(base) ((base) + (0x82))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN4_ADDR(base) ((base) + (0x83))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN5_ADDR(base) ((base) + (0x84))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_ADDR(base) ((base) + (0x85))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_ADDR(base) ((base) + (0x86))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN8_ADDR(base) ((base) + (0x87))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_ADDR(base) ((base) + (0x88))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_ADDR(base) ((base) + (0x89))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_ADDR(base) ((base) + (0x8A))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN4_ADDR(base) ((base) + (0x8B))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN5_ADDR(base) ((base) + (0x8C))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_ADDR(base) ((base) + (0x8D))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_ADDR(base) ((base) + (0x8E))
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN8_ADDR(base) ((base) + (0x8F))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKDIVCTRL_ADDR(base) ((base) + (0x90))
#define SOC_ASP_SoundWire_SOUNDWIRE_CLK_WAKEUP_EN_ADDR(base) ((base) + (0x91))
#define SOC_ASP_SoundWire_SOUNDWIRE_TEST_MONITOR_ADDR(base) ((base) + (0x92))
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_ADDR(base) ((base) + (0x93))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_REG_SEL_ADDR(base) ((base) + (0x9F))
#define SOC_ASP_SoundWire_SOUNDWIRE_FIFO_LOOP_EN_ADDR(base) ((base) + (0xA0))
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_ADDR(base) ((base) + (0xA1))
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL2_ADDR(base) ((base) + (0xA2))
#define SOC_ASP_SoundWire_SOUNDWIRE_SOURCESINK_CFG2_ADDR(base) ((base) + (0xA3))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_ADDR(base) ((base) + (0xA4))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_ADDR(base) ((base) + (0xA5))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_ADDR(base) ((base) + (0xA6))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG2_ADDR(base) ((base) + (0xA7))
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_TEST_PROC_SEL_ADDR(base) ((base) + (0xA8))
#define SOC_ASP_SoundWire_SOUNDWIRE_SYNC_TIMEOUT_ADDR(base) ((base) + (0xA9))
#define SOC_ASP_SoundWire_SOUNDWIRE_ENUM_TIMEOUT_ADDR(base) ((base) + (0xAA))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_ADDR(base) ((base) + (0xC0))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_ADDR(base) ((base) + (0xC1))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_ADDR(base) ((base) + (0xC2))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_ADDR(base) ((base) + (0xC3))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_ADDR(base) ((base) + (0xC4))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_ADDR(base) ((base) + (0xC5))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT3_ADDR(base) ((base) + (0xC6))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK3_ADDR(base) ((base) + (0xC7))
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT3_ADDR(base) ((base) + (0xC8))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_ADDR(base) ((base) + (0xC9))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_ADDR(base) ((base) + (0xCA))
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_ADDR(base) ((base) + (0xCB))
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_ADDR(base) ((base) + (0xCC))
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_ADDR(base) ((base) + (0xCD))
#define SOC_ASP_SoundWire_DEBUG_OUT_0_ADDR(base) ((base) + (0xDF))
#define SOC_ASP_SoundWire_DEBUG_OUT_1_ADDR(base) ((base) + (0xE0))
#define SOC_ASP_SoundWire_DEBUG_OUT_2_ADDR(base) ((base) + (0xE1))
#define SOC_ASP_SoundWire_DEBUG_OUT_3_ADDR(base) ((base) + (0xE2))
#define SOC_ASP_SoundWire_DEBUG_OUT_4_ADDR(base) ((base) + (0xE3))
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL0_ADDR(base) ((base) + (0xE4))
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL1_ADDR(base) ((base) + (0xE5))
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL2_ADDR(base) ((base) + (0xE6))
#define SOC_ASP_SoundWire_DP1_FIFO_THRE_CTRL_ADDR(base) ((base) + (0xE7))
#define SOC_ASP_SoundWire_DP_FIFO_THRE_CTRL_ADDR(base) ((base) + (0xE8))
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_ADDR(base) ((base) + (0xF5))
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_ADDR(base) ((base) + (0xF6))
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_ADDR(base) ((base) + (0xF7))
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_ADDR(base) ((base) + (0xF8))
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_ADDR(base) ((base) + (0xF9))
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_ADDR(base) ((base) + (0xFA))
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_ADDR(base) ((base) + (0xFB))
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_ADDR(base) ((base) + (0xFC))
#define SOC_ASP_SoundWire_SOUNDWIRE_VERSION_ADDR(base) ((base) + (0x0FF))
#define SOC_ASP_SoundWire_DP1_INTSTAT_ADDR(base) ((base) + (0x100))
#define SOC_ASP_SoundWire_DP1_INTMASK_ADDR(base) ((base) + (0x101))
#define SOC_ASP_SoundWire_DP1_PORTCTRL_ADDR(base) ((base) + (0x102))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL1_ADDR(base) ((base) + (0x103))
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_ADDR(base) ((base) + (0x104))
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_ADDR(base) ((base) + (0x105))
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_ADDR(base) ((base) + (0x120))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x121))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x122))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x123))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x124))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x125))
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK0_ADDR(base) ((base) + (0x126))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x127))
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK0_ADDR(base) ((base) + (0x128))
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_ADDR(base) ((base) + (0x130))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x131))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x132))
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x133))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x134))
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x135))
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK1_ADDR(base) ((base) + (0x136))
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x137))
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK1_ADDR(base) ((base) + (0x138))
#define SOC_ASP_SoundWire_DP2_INTSTAT_ADDR(base) ((base) + (0x200))
#define SOC_ASP_SoundWire_DP2_INTMASK_ADDR(base) ((base) + (0x201))
#define SOC_ASP_SoundWire_DP2_PORTCTRL_ADDR(base) ((base) + (0x202))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL1_ADDR(base) ((base) + (0x203))
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_ADDR(base) ((base) + (0x204))
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_ADDR(base) ((base) + (0x205))
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_ADDR(base) ((base) + (0x220))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x221))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x222))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x223))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x224))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x225))
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK0_ADDR(base) ((base) + (0x226))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x227))
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK0_ADDR(base) ((base) + (0x228))
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_ADDR(base) ((base) + (0x230))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x231))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x232))
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x233))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x234))
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x235))
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK1_ADDR(base) ((base) + (0x236))
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x237))
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK1_ADDR(base) ((base) + (0x238))
#define SOC_ASP_SoundWire_DP3_INTSTAT_ADDR(base) ((base) + (0x300))
#define SOC_ASP_SoundWire_DP3_INTMASK_ADDR(base) ((base) + (0x301))
#define SOC_ASP_SoundWire_DP3_PORTCTRL_ADDR(base) ((base) + (0x302))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL1_ADDR(base) ((base) + (0x303))
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_ADDR(base) ((base) + (0x304))
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_ADDR(base) ((base) + (0x305))
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_ADDR(base) ((base) + (0x320))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x321))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x322))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x323))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x324))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x325))
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK0_ADDR(base) ((base) + (0x326))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x327))
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK0_ADDR(base) ((base) + (0x328))
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_ADDR(base) ((base) + (0x330))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x331))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x332))
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x333))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x334))
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x335))
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK1_ADDR(base) ((base) + (0x336))
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x337))
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK1_ADDR(base) ((base) + (0x338))
#define SOC_ASP_SoundWire_DP4_INTSTAT_ADDR(base) ((base) + (0x400))
#define SOC_ASP_SoundWire_DP4_INTMASK_ADDR(base) ((base) + (0x401))
#define SOC_ASP_SoundWire_DP4_PORTCTRL_ADDR(base) ((base) + (0x402))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL1_ADDR(base) ((base) + (0x403))
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_ADDR(base) ((base) + (0x404))
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_ADDR(base) ((base) + (0x405))
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_ADDR(base) ((base) + (0x420))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x421))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x422))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x423))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x424))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x425))
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK0_ADDR(base) ((base) + (0x426))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x427))
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK0_ADDR(base) ((base) + (0x428))
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_ADDR(base) ((base) + (0x430))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x431))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x432))
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x433))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x434))
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x435))
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK1_ADDR(base) ((base) + (0x436))
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x437))
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK1_ADDR(base) ((base) + (0x438))
#define SOC_ASP_SoundWire_DP5_INTSTAT_ADDR(base) ((base) + (0x500))
#define SOC_ASP_SoundWire_DP5_INTMASK_ADDR(base) ((base) + (0x501))
#define SOC_ASP_SoundWire_DP5_PORTCTRL_ADDR(base) ((base) + (0x502))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL1_ADDR(base) ((base) + (0x503))
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_ADDR(base) ((base) + (0x504))
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_ADDR(base) ((base) + (0x505))
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_ADDR(base) ((base) + (0x520))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x521))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x522))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x523))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x524))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x525))
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK0_ADDR(base) ((base) + (0x526))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x527))
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK0_ADDR(base) ((base) + (0x528))
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_ADDR(base) ((base) + (0x530))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x531))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x532))
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x533))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x534))
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x535))
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK1_ADDR(base) ((base) + (0x536))
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x537))
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK1_ADDR(base) ((base) + (0x538))
#define SOC_ASP_SoundWire_DP6_INTSTAT_ADDR(base) ((base) + (0x600))
#define SOC_ASP_SoundWire_DP6_INTMASK_ADDR(base) ((base) + (0x601))
#define SOC_ASP_SoundWire_DP6_PORTCTRL_ADDR(base) ((base) + (0x602))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL1_ADDR(base) ((base) + (0x603))
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_ADDR(base) ((base) + (0x604))
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_ADDR(base) ((base) + (0x605))
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_ADDR(base) ((base) + (0x620))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x621))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x622))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x623))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x624))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x625))
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK0_ADDR(base) ((base) + (0x626))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x627))
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK0_ADDR(base) ((base) + (0x628))
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_ADDR(base) ((base) + (0x630))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x631))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x632))
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x633))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x634))
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x635))
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK1_ADDR(base) ((base) + (0x636))
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x637))
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK1_ADDR(base) ((base) + (0x638))
#define SOC_ASP_SoundWire_DP7_INTSTAT_ADDR(base) ((base) + (0x700))
#define SOC_ASP_SoundWire_DP7_INTMASK_ADDR(base) ((base) + (0x701))
#define SOC_ASP_SoundWire_DP7_PORTCTRL_ADDR(base) ((base) + (0x702))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL1_ADDR(base) ((base) + (0x703))
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_ADDR(base) ((base) + (0x704))
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_ADDR(base) ((base) + (0x705))
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_ADDR(base) ((base) + (0x720))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x721))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x722))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x723))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x724))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x725))
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK0_ADDR(base) ((base) + (0x726))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x727))
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK0_ADDR(base) ((base) + (0x728))
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_ADDR(base) ((base) + (0x730))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x731))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x732))
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x733))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x734))
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x735))
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK1_ADDR(base) ((base) + (0x736))
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x737))
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK1_ADDR(base) ((base) + (0x738))
#define SOC_ASP_SoundWire_DP8_INTSTAT_ADDR(base) ((base) + (0x800))
#define SOC_ASP_SoundWire_DP8_INTMASK_ADDR(base) ((base) + (0x801))
#define SOC_ASP_SoundWire_DP8_PORTCTRL_ADDR(base) ((base) + (0x802))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL1_ADDR(base) ((base) + (0x803))
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_ADDR(base) ((base) + (0x804))
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_ADDR(base) ((base) + (0x805))
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_ADDR(base) ((base) + (0x820))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x821))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x822))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x823))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x824))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x825))
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK0_ADDR(base) ((base) + (0x826))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x827))
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK0_ADDR(base) ((base) + (0x828))
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_ADDR(base) ((base) + (0x830))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x831))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x832))
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x833))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x834))
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x835))
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK1_ADDR(base) ((base) + (0x836))
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x837))
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK1_ADDR(base) ((base) + (0x838))
#define SOC_ASP_SoundWire_DP9_INTSTAT_ADDR(base) ((base) + (0x900))
#define SOC_ASP_SoundWire_DP9_INTMASK_ADDR(base) ((base) + (0x901))
#define SOC_ASP_SoundWire_DP9_PORTCTRL_ADDR(base) ((base) + (0x902))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL1_ADDR(base) ((base) + (0x903))
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_ADDR(base) ((base) + (0x904))
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_ADDR(base) ((base) + (0x905))
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_ADDR(base) ((base) + (0x920))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0x921))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0x922))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0x923))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0x924))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0x925))
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK0_ADDR(base) ((base) + (0x926))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0x927))
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK0_ADDR(base) ((base) + (0x928))
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_ADDR(base) ((base) + (0x930))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0x931))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0x932))
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0x933))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0x934))
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0x935))
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK1_ADDR(base) ((base) + (0x936))
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0x937))
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK1_ADDR(base) ((base) + (0x938))
#define SOC_ASP_SoundWire_DP10_INTSTAT_ADDR(base) ((base) + (0xA00))
#define SOC_ASP_SoundWire_DP10_INTMASK_ADDR(base) ((base) + (0xA01))
#define SOC_ASP_SoundWire_DP10_PORTCTRL_ADDR(base) ((base) + (0xA02))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL1_ADDR(base) ((base) + (0xA03))
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_ADDR(base) ((base) + (0xA04))
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_ADDR(base) ((base) + (0xA05))
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_ADDR(base) ((base) + (0xA20))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xA21))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xA22))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xA23))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xA24))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xA25))
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK0_ADDR(base) ((base) + (0xA26))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xA27))
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK0_ADDR(base) ((base) + (0xA28))
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_ADDR(base) ((base) + (0xA30))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xA31))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xA32))
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xA33))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xA34))
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xA35))
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK1_ADDR(base) ((base) + (0xA36))
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xA37))
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK1_ADDR(base) ((base) + (0xA38))
#define SOC_ASP_SoundWire_DP11_INTSTAT_ADDR(base) ((base) + (0xB00))
#define SOC_ASP_SoundWire_DP11_INTMASK_ADDR(base) ((base) + (0xB01))
#define SOC_ASP_SoundWire_DP11_PORTCTRL_ADDR(base) ((base) + (0xB02))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL1_ADDR(base) ((base) + (0xB03))
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_ADDR(base) ((base) + (0xB04))
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_ADDR(base) ((base) + (0xB05))
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_ADDR(base) ((base) + (0xB20))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xB21))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xB22))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xB23))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xB24))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xB25))
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK0_ADDR(base) ((base) + (0xB26))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xB27))
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK0_ADDR(base) ((base) + (0xB28))
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_ADDR(base) ((base) + (0xB30))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xB31))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xB32))
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xB33))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xB34))
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xB35))
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK1_ADDR(base) ((base) + (0xB36))
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xB37))
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK1_ADDR(base) ((base) + (0xB38))
#define SOC_ASP_SoundWire_DP12_INTSTAT_ADDR(base) ((base) + (0xC00))
#define SOC_ASP_SoundWire_DP12_INTMASK_ADDR(base) ((base) + (0xC01))
#define SOC_ASP_SoundWire_DP12_PORTCTRL_ADDR(base) ((base) + (0xC02))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL1_ADDR(base) ((base) + (0xC03))
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_ADDR(base) ((base) + (0xC04))
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_ADDR(base) ((base) + (0xC05))
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_ADDR(base) ((base) + (0xC20))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xC21))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xC22))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xC23))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xC24))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xC25))
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK0_ADDR(base) ((base) + (0xC26))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xC27))
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK0_ADDR(base) ((base) + (0xC28))
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_ADDR(base) ((base) + (0xC30))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xC31))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xC32))
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xC33))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xC34))
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xC35))
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK1_ADDR(base) ((base) + (0xC36))
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xC37))
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK1_ADDR(base) ((base) + (0xC38))
#define SOC_ASP_SoundWire_DP13_INTSTAT_ADDR(base) ((base) + (0xD00))
#define SOC_ASP_SoundWire_DP13_INTMASK_ADDR(base) ((base) + (0xD01))
#define SOC_ASP_SoundWire_DP13_PORTCTRL_ADDR(base) ((base) + (0xD02))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL1_ADDR(base) ((base) + (0xD03))
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_ADDR(base) ((base) + (0xD04))
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_ADDR(base) ((base) + (0xD05))
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_ADDR(base) ((base) + (0xD20))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xD21))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xD22))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xD23))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xD24))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xD25))
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK0_ADDR(base) ((base) + (0xD26))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xD27))
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK0_ADDR(base) ((base) + (0xD28))
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_ADDR(base) ((base) + (0xD30))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xD31))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xD32))
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xD33))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xD34))
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xD35))
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK1_ADDR(base) ((base) + (0xD36))
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xD37))
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK1_ADDR(base) ((base) + (0xD38))
#define SOC_ASP_SoundWire_DP14_INTSTAT_ADDR(base) ((base) + (0xE00))
#define SOC_ASP_SoundWire_DP14_INTMASK_ADDR(base) ((base) + (0xE01))
#define SOC_ASP_SoundWire_DP14_PORTCTRL_ADDR(base) ((base) + (0xE02))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL1_ADDR(base) ((base) + (0xE03))
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_ADDR(base) ((base) + (0xE04))
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_ADDR(base) ((base) + (0xE05))
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_ADDR(base) ((base) + (0xE20))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK0_ADDR(base) ((base) + (0xE21))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK0_ADDR(base) ((base) + (0xE22))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK0_ADDR(base) ((base) + (0xE23))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK0_ADDR(base) ((base) + (0xE24))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK0_ADDR(base) ((base) + (0xE25))
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK0_ADDR(base) ((base) + (0xE26))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK0_ADDR(base) ((base) + (0xE27))
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK0_ADDR(base) ((base) + (0xE28))
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_ADDR(base) ((base) + (0xE30))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK1_ADDR(base) ((base) + (0xE31))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK1_ADDR(base) ((base) + (0xE32))
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK1_ADDR(base) ((base) + (0xE33))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK1_ADDR(base) ((base) + (0xE34))
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK1_ADDR(base) ((base) + (0xE35))
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK1_ADDR(base) ((base) + (0xE36))
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK1_ADDR(base) ((base) + (0xE37))
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK1_ADDR(base) ((base) + (0xE38))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_test_fail_int : 1;
        unsigned char dp0_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp0_cfg_error0_int : 1;
        unsigned char dp0_cfg_error1_int : 1;
        unsigned char dp0_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP0_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP0_INTSTAT_dp0_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_test_fail_int_mask : 1;
        unsigned char dp0_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp0_cfg_error0_int_mask : 1;
        unsigned char dp0_cfg_error1_int_mask : 1;
        unsigned char dp0_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP0_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP0_INTMASK_dp0_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 2;
        unsigned char dp0_portdatamode : 2;
        unsigned char dp0_nextinvertbank : 1;
        unsigned char reserved_1 : 1;
        unsigned char reserved_2 : 2;
    } reg;
} SOC_ASP_SoundWire_DP0_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_PORTCTRL_dp0_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP0_PORTCTRL_dp0_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP0_PORTCTRL_dp0_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP0_PORTCTRL_dp0_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP0_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_BLOCKCTRL1_dp0_wordlength_START (0)
#define SOC_ASP_SoundWire_DP0_BLOCKCTRL1_dp0_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_n_finished_channel1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP0_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_PREPARESTATUS_dp0_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP0_PREPARESTATUS_dp0_n_finished_channel1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_prepare_channel1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP0_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_PREPARECTRL_dp0_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP0_PREPARECTRL_dp0_prepare_channel1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_enable_channel1_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP0_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK0_dp0_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK0_dp0_enable_channel1_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK0_dp0_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK0_dp0_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK0_dp0_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK0_dp0_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK0_dp0_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK0_dp0_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK0_dp0_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK0_dp0_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_hstop_bank0 : 4;
        unsigned char dp0_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP0_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK0_dp0_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK0_dp0_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK0_dp0_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK0_dp0_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP0_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK0_dp0_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK0_dp0_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_enable_channel1_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP0_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK1_dp0_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP0_CHANNELEN_BANK1_dp0_enable_channel1_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK1_dp0_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL1_BANK1_dp0_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK1_dp0_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP0_SAMPLECTRL2_BANK1_dp0_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK1_dp0_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL1_BANK1_dp0_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK1_dp0_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP0_OFFSETCTRL2_BANK1_dp0_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_hstop_bank1 : 4;
        unsigned char dp0_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP0_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK1_dp0_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK1_dp0_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK1_dp0_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP0_HCTRL_BANK1_dp0_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP0_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK1_dp0_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP0_LANECTRL_BANK1_dp0_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 3;
        unsigned char dp0_int_mstat : 1;
        unsigned char dp1_int_mstat : 1;
        unsigned char dp2_int_mstat : 1;
        unsigned char dp3_int_mstat : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP_IntStat1_UNION;
#endif
#define SOC_ASP_SoundWire_DP_IntStat1_dp0_int_mstat_START (3)
#define SOC_ASP_SoundWire_DP_IntStat1_dp0_int_mstat_END (3)
#define SOC_ASP_SoundWire_DP_IntStat1_dp1_int_mstat_START (4)
#define SOC_ASP_SoundWire_DP_IntStat1_dp1_int_mstat_END (4)
#define SOC_ASP_SoundWire_DP_IntStat1_dp2_int_mstat_START (5)
#define SOC_ASP_SoundWire_DP_IntStat1_dp2_int_mstat_END (5)
#define SOC_ASP_SoundWire_DP_IntStat1_dp3_int_mstat_START (6)
#define SOC_ASP_SoundWire_DP_IntStat1_dp3_int_mstat_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_int_mstat : 1;
        unsigned char dp5_int_mstat : 1;
        unsigned char dp6_int_mstat : 1;
        unsigned char dp7_int_mstat : 1;
        unsigned char dp8_int_mstat : 1;
        unsigned char dp9_int_mstat : 1;
        unsigned char dp10_int_mstat : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_DP_IntStat2_UNION;
#endif
#define SOC_ASP_SoundWire_DP_IntStat2_dp4_int_mstat_START (0)
#define SOC_ASP_SoundWire_DP_IntStat2_dp4_int_mstat_END (0)
#define SOC_ASP_SoundWire_DP_IntStat2_dp5_int_mstat_START (1)
#define SOC_ASP_SoundWire_DP_IntStat2_dp5_int_mstat_END (1)
#define SOC_ASP_SoundWire_DP_IntStat2_dp6_int_mstat_START (2)
#define SOC_ASP_SoundWire_DP_IntStat2_dp6_int_mstat_END (2)
#define SOC_ASP_SoundWire_DP_IntStat2_dp7_int_mstat_START (3)
#define SOC_ASP_SoundWire_DP_IntStat2_dp7_int_mstat_END (3)
#define SOC_ASP_SoundWire_DP_IntStat2_dp8_int_mstat_START (4)
#define SOC_ASP_SoundWire_DP_IntStat2_dp8_int_mstat_END (4)
#define SOC_ASP_SoundWire_DP_IntStat2_dp9_int_mstat_START (5)
#define SOC_ASP_SoundWire_DP_IntStat2_dp9_int_mstat_END (5)
#define SOC_ASP_SoundWire_DP_IntStat2_dp10_int_mstat_START (6)
#define SOC_ASP_SoundWire_DP_IntStat2_dp10_int_mstat_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_int_mstat : 1;
        unsigned char dp12_int_mstat : 1;
        unsigned char dp13_int_mstat : 1;
        unsigned char dp14_int_mstat : 1;
        unsigned char reserved : 4;
    } reg;
} SOC_ASP_SoundWire_DP_IntStat3_UNION;
#endif
#define SOC_ASP_SoundWire_DP_IntStat3_dp11_int_mstat_START (0)
#define SOC_ASP_SoundWire_DP_IntStat3_dp11_int_mstat_END (0)
#define SOC_ASP_SoundWire_DP_IntStat3_dp12_int_mstat_START (1)
#define SOC_ASP_SoundWire_DP_IntStat3_dp12_int_mstat_END (1)
#define SOC_ASP_SoundWire_DP_IntStat3_dp13_int_mstat_START (2)
#define SOC_ASP_SoundWire_DP_IntStat3_dp13_int_mstat_END (2)
#define SOC_ASP_SoundWire_DP_IntStat3_dp14_int_mstat_START (3)
#define SOC_ASP_SoundWire_DP_IntStat3_dp14_int_mstat_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} SOC_ASP_SoundWire_SCP_DEVNUMBER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char columncontrol_bank0 : 3;
        unsigned char rowcontrol_bank0 : 5;
    } reg;
} SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK0_columncontrol_bank0_START (0)
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK0_columncontrol_bank0_END (2)
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK0_rowcontrol_bank0_START (3)
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK0_rowcontrol_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char columncontrol_bank1 : 3;
        unsigned char rowcontrol_bank1 : 5;
    } reg;
} SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK1_columncontrol_bank1_START (0)
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK1_columncontrol_bank1_END (2)
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK1_rowcontrol_bank1_START (3)
#define SOC_ASP_SoundWire_SCP_FRAMECTRL_BANK1_rowcontrol_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char frame_ctrl_clken : 1;
        unsigned char data_port_clken : 1;
        unsigned char sw_clk_o_div_en : 1;
        unsigned char rx0_clken : 1;
        unsigned char tx0_clken : 1;
        unsigned char rx1_clken : 1;
        unsigned char tx1_clken : 1;
        unsigned char sysctrl_clken : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_frame_ctrl_clken_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_frame_ctrl_clken_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_data_port_clken_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_data_port_clken_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_sw_clk_o_div_en_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_sw_clk_o_div_en_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_rx0_clken_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_rx0_clken_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_tx0_clken_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_tx0_clken_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_rx1_clken_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_rx1_clken_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_tx1_clken_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_tx1_clken_END (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_sysctrl_clken_START (7)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN1_sysctrl_clken_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_port1_clken : 1;
        unsigned char data_port2_clken : 1;
        unsigned char data_port3_clken : 1;
        unsigned char data_port4_clken : 1;
        unsigned char data_port5_clken : 1;
        unsigned char data_port6_clken : 1;
        unsigned char data_port7_clken : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port1_clken_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port1_clken_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port2_clken_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port2_clken_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port3_clken_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port3_clken_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port4_clken_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port4_clken_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port5_clken_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port5_clken_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port6_clken_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port6_clken_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port7_clken_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN2_data_port7_clken_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_port8_clken : 1;
        unsigned char data_port9_clken : 1;
        unsigned char data_port10_clken : 1;
        unsigned char data_port11_clken : 1;
        unsigned char data_port12_clken : 1;
        unsigned char data_port13_clken : 1;
        unsigned char data_port14_clken : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port8_clken_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port8_clken_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port9_clken_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port9_clken_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port10_clken_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port10_clken_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port11_clken_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port11_clken_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port12_clken_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port12_clken_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port13_clken_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port13_clken_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port14_clken_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN3_data_port14_clken_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 6;
        unsigned char bus_rst_en : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN4_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN4_bus_rst_en_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN4_bus_rst_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp_fifo1_up_clken : 1;
        unsigned char dp_fifo2_up_clken : 1;
        unsigned char dp_fifo3_up_clken : 1;
        unsigned char dp_fifo4_up_clken : 1;
        unsigned char dp_fifo5_up_clken : 1;
        unsigned char dp_fifo6_up_clken : 1;
        unsigned char dp_fifo7_up_clken : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo1_up_clken_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo1_up_clken_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo2_up_clken_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo2_up_clken_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo3_up_clken_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo3_up_clken_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo4_up_clken_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo4_up_clken_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo5_up_clken_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo5_up_clken_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo6_up_clken_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo6_up_clken_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo7_up_clken_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN6_dp_fifo7_up_clken_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 2;
        unsigned char dp_fifo10_dn_clken : 1;
        unsigned char dp_fifo11_dn_clken : 1;
        unsigned char dp_fifo12_dn_clken : 1;
        unsigned char dp_fifo13_dn_clken : 1;
        unsigned char dp_fifo14_dn_clken : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo10_dn_clken_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo10_dn_clken_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo11_dn_clken_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo11_dn_clken_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo12_dn_clken_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo12_dn_clken_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo13_dn_clken_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo13_dn_clken_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo14_dn_clken_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN7_dp_fifo14_dn_clken_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp_fifo8_up_clken : 1;
        unsigned char dp_fifo9_up_clken : 1;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKEN8_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN8_dp_fifo8_up_clken_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN8_dp_fifo8_up_clken_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN8_dp_fifo9_up_clken_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKEN8_dp_fifo9_up_clken_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char frame_ctrl_rsten : 1;
        unsigned char data_port_rsten : 1;
        unsigned char reserved : 1;
        unsigned char rx0_rsten : 1;
        unsigned char tx0_rsten : 1;
        unsigned char rx1_rsten : 1;
        unsigned char tx1_rsten : 1;
        unsigned char sysctrl_rsten : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_frame_ctrl_rsten_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_frame_ctrl_rsten_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_data_port_rsten_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_data_port_rsten_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_rx0_rsten_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_rx0_rsten_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_tx0_rsten_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_tx0_rsten_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_rx1_rsten_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_rx1_rsten_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_tx1_rsten_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_tx1_rsten_END (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_sysctrl_rsten_START (7)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN1_sysctrl_rsten_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_port1_rsten : 1;
        unsigned char data_port2_rsten : 1;
        unsigned char data_port3_rsten : 1;
        unsigned char data_port4_rsten : 1;
        unsigned char data_port5_rsten : 1;
        unsigned char data_port6_rsten : 1;
        unsigned char data_port7_rsten : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port1_rsten_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port1_rsten_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port2_rsten_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port2_rsten_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port3_rsten_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port3_rsten_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port4_rsten_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port4_rsten_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port5_rsten_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port5_rsten_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port6_rsten_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port6_rsten_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port7_rsten_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN2_data_port7_rsten_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_port8_rsten : 1;
        unsigned char data_port9_rsten : 1;
        unsigned char data_port10_rsten : 1;
        unsigned char data_port11_rsten : 1;
        unsigned char data_port12_rsten : 1;
        unsigned char data_port13_rsten : 1;
        unsigned char data_port14_rsten : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port8_rsten_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port8_rsten_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port9_rsten_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port9_rsten_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port10_rsten_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port10_rsten_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port11_rsten_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port11_rsten_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port12_rsten_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port12_rsten_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port13_rsten_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port13_rsten_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port14_rsten_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN3_data_port14_rsten_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp_fifo1_up_rsten : 1;
        unsigned char dp_fifo2_up_rsten : 1;
        unsigned char dp_fifo3_up_rsten : 1;
        unsigned char dp_fifo4_up_rsten : 1;
        unsigned char dp_fifo5_up_rsten : 1;
        unsigned char dp_fifo6_up_rsten : 1;
        unsigned char dp_fifo7_up_rsten : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo1_up_rsten_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo1_up_rsten_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo2_up_rsten_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo2_up_rsten_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo3_up_rsten_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo3_up_rsten_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo4_up_rsten_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo4_up_rsten_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo5_up_rsten_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo5_up_rsten_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo6_up_rsten_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo6_up_rsten_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo7_up_rsten_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN6_dp_fifo7_up_rsten_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 2;
        unsigned char dp_fifo10_dn_rsten : 1;
        unsigned char dp_fifo11_dn_rsten : 1;
        unsigned char dp_fifo12_dn_rsten : 1;
        unsigned char dp_fifo13_dn_rsten : 1;
        unsigned char dp_fifo14_dn_rsten : 1;
        unsigned char reserved_1 : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo10_dn_rsten_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo10_dn_rsten_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo11_dn_rsten_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo11_dn_rsten_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo12_dn_rsten_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo12_dn_rsten_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo13_dn_rsten_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo13_dn_rsten_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo14_dn_rsten_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN7_dp_fifo14_dn_rsten_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp_fifo8_up_rsten : 1;
        unsigned char dp_fifo9_up_rsten : 1;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_RSTEN8_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN8_dp_fifo8_up_rsten_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN8_dp_fifo8_up_rsten_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN8_dp_fifo9_up_rsten_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_RSTEN8_dp_fifo9_up_rsten_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sw_clk_div_ratio : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLKDIVCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKDIVCTRL_sw_clk_div_ratio_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLKDIVCTRL_sw_clk_div_ratio_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char mst_clk_wakeup_en : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CLK_WAKEUP_EN_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CLK_WAKEUP_EN_mst_clk_wakeup_en_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CLK_WAKEUP_EN_mst_clk_wakeup_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char clkswitch_cs : 4;
        unsigned char reserved : 4;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_TEST_MONITOR_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_TEST_MONITOR_clkswitch_cs_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_TEST_MONITOR_clkswitch_cs_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char frame_bank0_sel : 1;
        unsigned char frame_bank1_sel : 1;
        unsigned char frame_ctrl_state : 3;
        unsigned char rx0_sync_state_curr : 3;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_frame_bank0_sel_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_frame_bank0_sel_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_frame_bank1_sel_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_frame_bank1_sel_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_frame_ctrl_state_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_frame_ctrl_state_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_rx0_sync_state_curr_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_BANK_SW_MONITOR_rx0_sync_state_curr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char page_reg_sel : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_SLV_REG_SEL_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_REG_SEL_page_reg_sel_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_REG_SEL_page_reg_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char fifo_loopback_sel : 4;
        unsigned char reserved : 4;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_FIFO_LOOP_EN_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_FIFO_LOOP_EN_fifo_loopback_sel_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_FIFO_LOOP_EN_fifo_loopback_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sync_timeout_en : 1;
        unsigned char dploopback0_en : 1;
        unsigned char dploopback1_en : 1;
        unsigned char frame_ctrl_en : 1;
        unsigned char dev_addr_ctrl : 4;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_sync_timeout_en_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_sync_timeout_en_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_dploopback0_en_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_dploopback0_en_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_dploopback1_en_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_dploopback1_en_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_frame_ctrl_en_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_frame_ctrl_en_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_dev_addr_ctrl_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL1_dev_addr_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char enum_timeout_en : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_CTRL2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL2_enum_timeout_en_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_CTRL2_enum_timeout_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_SOURCESINK_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_big_ending : 1;
        unsigned char dp1_big_ending : 1;
        unsigned char dp2_big_ending : 1;
        unsigned char dp3_big_ending : 1;
        unsigned char dp4_big_ending : 1;
        unsigned char dp5_big_ending : 1;
        unsigned char dp6_big_ending : 1;
        unsigned char dp7_big_ending : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp0_big_ending_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp0_big_ending_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp1_big_ending_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp1_big_ending_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp2_big_ending_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp2_big_ending_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp3_big_ending_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp3_big_ending_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp4_big_ending_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp4_big_ending_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp5_big_ending_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp5_big_ending_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp6_big_ending_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp6_big_ending_END (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp7_big_ending_START (7)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG1_dp7_big_ending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_big_ending : 1;
        unsigned char dp9_big_ending : 1;
        unsigned char dp10_big_ending : 1;
        unsigned char dp11_big_ending : 1;
        unsigned char dp12_big_ending : 1;
        unsigned char dp13_big_ending : 1;
        unsigned char dp14_big_ending : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp8_big_ending_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp8_big_ending_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp9_big_ending_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp9_big_ending_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp10_big_ending_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp10_big_ending_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp11_big_ending_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp11_big_ending_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp12_big_ending_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp12_big_ending_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp13_big_ending_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp13_big_ending_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp14_big_ending_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_CFG2_dp14_big_ending_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_fifo_loopback_en : 1;
        unsigned char dp1_fifo_loopback_en : 1;
        unsigned char dp2_fifo_loopback_en : 1;
        unsigned char dp3_fifo_loopback_en : 1;
        unsigned char dp4_fifo_loopback_en : 1;
        unsigned char dp5_fifo_loopback_en : 1;
        unsigned char dp6_fifo_loopback_en : 1;
        unsigned char dp7_fifo_loopback_en : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp0_fifo_loopback_en_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp0_fifo_loopback_en_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp1_fifo_loopback_en_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp1_fifo_loopback_en_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp2_fifo_loopback_en_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp2_fifo_loopback_en_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp3_fifo_loopback_en_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp3_fifo_loopback_en_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp4_fifo_loopback_en_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp4_fifo_loopback_en_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp5_fifo_loopback_en_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp5_fifo_loopback_en_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp6_fifo_loopback_en_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp6_fifo_loopback_en_END (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp7_fifo_loopback_en_START (7)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG1_dp7_fifo_loopback_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_fifo_loopback_en : 1;
        unsigned char dp9_fifo_loopback_en : 1;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG2_dp8_fifo_loopback_en_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG2_dp8_fifo_loopback_en_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG2_dp9_fifo_loopback_en_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_FIFO_CFG2_dp9_fifo_loopback_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_port_test_proc_sel : 4;
        unsigned char reserved : 4;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_TEST_PROC_SEL_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_TEST_PROC_SEL_data_port_test_proc_sel_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_DATAPORT_TEST_PROC_SEL_data_port_test_proc_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sync_timeout_frm_num : 8;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_SYNC_TIMEOUT_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_SYNC_TIMEOUT_sync_timeout_frm_num_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_SYNC_TIMEOUT_sync_timeout_frm_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char enum_timeout_frm_num : 8;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_ENUM_TIMEOUT_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_ENUM_TIMEOUT_enum_timeout_frm_num_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_ENUM_TIMEOUT_enum_timeout_frm_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char enum_finished_int : 1;
        unsigned char slv_unattached_int : 1;
        unsigned char slv_com_int : 1;
        unsigned char command_ignore_int : 1;
        unsigned char command_abort_int : 1;
        unsigned char msync_lost_int : 1;
        unsigned char mbus_clash_int_0 : 1;
        unsigned char mbus_clash_int_1 : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_enum_finished_int_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_enum_finished_int_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_slv_unattached_int_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_slv_unattached_int_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_slv_com_int_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_slv_com_int_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_command_ignore_int_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_command_ignore_int_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_command_abort_int_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_command_abort_int_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_msync_lost_int_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_msync_lost_int_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_mbus_clash_int_0_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_mbus_clash_int_0_END (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_mbus_clash_int_1_START (7)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT1_mbus_clash_int_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char enum_finished_int_mask : 1;
        unsigned char slv_unattached_int_mask : 1;
        unsigned char slv_com_int_mask : 1;
        unsigned char command_ignore_int_mask : 1;
        unsigned char command_abort_int_mask : 1;
        unsigned char msync_lost_int_mask : 1;
        unsigned char mbus_clash_int_0_mask : 1;
        unsigned char mbus_clash_int_1_mask : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_enum_finished_int_mask_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_enum_finished_int_mask_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_slv_unattached_int_mask_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_slv_unattached_int_mask_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_slv_com_int_mask_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_slv_com_int_mask_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_command_ignore_int_mask_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_command_ignore_int_mask_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_command_abort_int_mask_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_command_abort_int_mask_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_msync_lost_int_mask_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_msync_lost_int_mask_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_mbus_clash_int_0_mask_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_mbus_clash_int_0_mask_END (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_mbus_clash_int_1_mask_START (7)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK1_mbus_clash_int_1_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char enum_finished_int_mstat : 1;
        unsigned char slv_unattached_int_mstat : 1;
        unsigned char slv_com_int_mstat : 1;
        unsigned char command_ignore_int_mstat : 1;
        unsigned char command_abort_int_mstat : 1;
        unsigned char msync_lost_int_mstat : 1;
        unsigned char mbus_clash_int_0_mstat : 1;
        unsigned char mbus_clash_int_1_mstat : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_enum_finished_int_mstat_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_enum_finished_int_mstat_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_slv_unattached_int_mstat_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_slv_unattached_int_mstat_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_slv_com_int_mstat_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_slv_com_int_mstat_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_command_ignore_int_mstat_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_command_ignore_int_mstat_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_command_abort_int_mstat_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_command_abort_int_mstat_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_msync_lost_int_mstat_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_msync_lost_int_mstat_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_mbus_clash_int_0_mstat_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_mbus_clash_int_0_mstat_END (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_mbus_clash_int_1_mstat_START (7)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT1_mbus_clash_int_1_mstat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char mpar_err_int : 1;
        unsigned char msync_timeout_int : 1;
        unsigned char reg_req_int : 1;
        unsigned char scp_frmend_finished_int : 1;
        unsigned char slv_attached_int : 1;
        unsigned char clock_option_finished_int : 1;
        unsigned char enum_timeout_int : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_mpar_err_int_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_mpar_err_int_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_msync_timeout_int_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_msync_timeout_int_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_reg_req_int_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_reg_req_int_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_scp_frmend_finished_int_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_scp_frmend_finished_int_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_slv_attached_int_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_slv_attached_int_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_clock_option_finished_int_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_clock_option_finished_int_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_enum_timeout_int_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT2_enum_timeout_int_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char mpar_err_int_mask : 1;
        unsigned char msync_timeout_int_mask : 1;
        unsigned char reg_req_int_mask : 1;
        unsigned char scp_frmend_finished_int_mask : 1;
        unsigned char slv_attached_int_mask : 1;
        unsigned char clock_option_finished_int_mask : 1;
        unsigned char enum_timeout_int_mask : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_mpar_err_int_mask_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_mpar_err_int_mask_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_msync_timeout_int_mask_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_msync_timeout_int_mask_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_reg_req_int_mask_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_reg_req_int_mask_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_scp_frmend_finished_int_mask_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_scp_frmend_finished_int_mask_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_slv_attached_int_mask_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_slv_attached_int_mask_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_clock_option_finished_int_mask_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_clock_option_finished_int_mask_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_enum_timeout_int_mask_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK2_enum_timeout_int_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char mpar_err_int_mstat : 1;
        unsigned char msync_timeout_int_mstat : 1;
        unsigned char reg_req_int_mstat : 1;
        unsigned char scp_frmend_finished_int_mstat : 1;
        unsigned char slv_attached_int_mstat : 1;
        unsigned char clock_option_finished_int_mstat : 1;
        unsigned char enum_timeout_int_mstat : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_mpar_err_int_mstat_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_mpar_err_int_mstat_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_msync_timeout_int_mstat_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_msync_timeout_int_mstat_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_reg_req_int_mstat_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_reg_req_int_mstat_END (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_scp_frmend_finished_int_mstat_START (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_scp_frmend_finished_int_mstat_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_slv_attached_int_mstat_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_slv_attached_int_mstat_END (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_clock_option_finished_int_mstat_START (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_clock_option_finished_int_mstat_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_enum_timeout_int_mstat_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT2_enum_timeout_int_mstat_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char clockoptionnow_cfg_int : 1;
        unsigned char clockoptiondone_cfg_int : 1;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT3_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT3_clockoptionnow_cfg_int_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT3_clockoptionnow_cfg_int_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT3_clockoptiondone_cfg_int_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTSTAT3_clockoptiondone_cfg_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char clockoptionnow_cfg_int_mask : 1;
        unsigned char clockoptiondone_cfg_int_mask : 1;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTMASK3_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK3_clockoptionnow_cfg_int_mask_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK3_clockoptionnow_cfg_int_mask_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK3_clockoptiondone_cfg_int_mask_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMASK3_clockoptiondone_cfg_int_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char clockoptionnow_cfg_int_mstat : 1;
        unsigned char clockoptiondone_cfg_int_mstat : 1;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT3_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT3_clockoptionnow_cfg_int_mstat_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT3_clockoptionnow_cfg_int_mstat_END (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT3_clockoptiondone_cfg_int_mstat_START (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_INTMSTAT3_clockoptiondone_cfg_int_mstat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slv_stat_00 : 2;
        unsigned char slv_stat_01 : 2;
        unsigned char slv_stat_02 : 2;
        unsigned char slv_stat_03 : 2;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_00_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_00_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_01_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_01_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_02_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_02_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_03_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT0_slv_stat_03_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slv_stat_04 : 2;
        unsigned char slv_stat_05 : 2;
        unsigned char slv_stat_06 : 2;
        unsigned char slv_stat_07 : 2;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_04_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_04_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_05_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_05_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_06_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_06_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_07_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT1_slv_stat_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char slv_stat_08 : 2;
        unsigned char slv_stat_09 : 2;
        unsigned char slv_stat_10 : 2;
        unsigned char slv_stat_11 : 2;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_08_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_08_END (1)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_09_START (2)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_09_END (3)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_10_START (4)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_10_END (5)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_11_START (6)
#define SOC_ASP_SoundWire_SOUNDWIRE_SLV_STAT2_slv_stat_11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_fifo_clr : 1;
        unsigned char dp2_fifo_clr : 1;
        unsigned char dp3_fifo_clr : 1;
        unsigned char dp4_fifo_clr : 1;
        unsigned char dp5_fifo_clr : 1;
        unsigned char dp6_fifo_clr : 1;
        unsigned char dp7_fifo_clr : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_DP_FIFO_CLR1_UNION;
#endif
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp1_fifo_clr_START (0)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp1_fifo_clr_END (0)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp2_fifo_clr_START (1)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp2_fifo_clr_END (1)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp3_fifo_clr_START (2)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp3_fifo_clr_END (2)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp4_fifo_clr_START (3)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp4_fifo_clr_END (3)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp5_fifo_clr_START (4)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp5_fifo_clr_END (4)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp6_fifo_clr_START (5)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp6_fifo_clr_END (5)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp7_fifo_clr_START (6)
#define SOC_ASP_SoundWire_DP_FIFO_CLR1_dp7_fifo_clr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_fifo_clr : 1;
        unsigned char dp9_fifo_clr : 1;
        unsigned char dp10_fifo_clr : 1;
        unsigned char dp11_fifo_clr : 1;
        unsigned char dp12_fifo_clr : 1;
        unsigned char dp13_fifo_clr : 1;
        unsigned char dp14_fifo_clr : 1;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_DP_FIFO_CLR2_UNION;
#endif
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp8_fifo_clr_START (0)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp8_fifo_clr_END (0)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp9_fifo_clr_START (1)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp9_fifo_clr_END (1)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp10_fifo_clr_START (2)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp10_fifo_clr_END (2)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp11_fifo_clr_START (3)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp11_fifo_clr_END (3)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp12_fifo_clr_START (4)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp12_fifo_clr_END (4)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp13_fifo_clr_START (5)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp13_fifo_clr_END (5)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp14_fifo_clr_START (6)
#define SOC_ASP_SoundWire_DP_FIFO_CLR2_dp14_fifo_clr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_io_proc_out : 7;
        unsigned char reserved : 1;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_0_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_0_test_io_proc_out_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_0_test_io_proc_out_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_reg_proc_out_1 : 8;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_1_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_1_test_reg_proc_out_1_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_1_test_reg_proc_out_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_reg_proc_out_2 : 8;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_2_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_2_test_reg_proc_out_2_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_2_test_reg_proc_out_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_reg_proc_out_3 : 8;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_3_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_3_test_reg_proc_out_3_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_3_test_reg_proc_out_3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_reg_proc_out_4 : 8;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_4_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_4_test_reg_proc_out_4_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_4_test_reg_proc_out_4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_proc_vld_sel : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_SEL0_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL0_test_proc_vld_sel_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL0_test_proc_vld_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_io_proc_sel : 8;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_SEL1_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL1_test_io_proc_sel_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL1_test_io_proc_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char test_reg_proc_sel : 8;
    } reg;
} SOC_ASP_SoundWire_DEBUG_OUT_SEL2_UNION;
#endif
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL2_test_reg_proc_sel_START (0)
#define SOC_ASP_SoundWire_DEBUG_OUT_SEL2_test_reg_proc_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp_fifo_thre_up : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP1_FIFO_THRE_CTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_FIFO_THRE_CTRL_dp_fifo_thre_up_START (0)
#define SOC_ASP_SoundWire_DP1_FIFO_THRE_CTRL_dp_fifo_thre_up_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp_fifo_thre_dn : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP_FIFO_THRE_CTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP_FIFO_THRE_CTRL_dp_fifo_thre_dn_START (0)
#define SOC_ASP_SoundWire_DP_FIFO_THRE_CTRL_dp_fifo_thre_dn_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp0_fifo_up_full : 1;
        unsigned char dp0_fifo_up_empty : 1;
        unsigned char dp0_fifo_dn_full : 1;
        unsigned char dp0_fifo_dn_empty : 1;
        unsigned char reserved : 4;
    } reg;
} SOC_ASP_SoundWire_DP0_FIFO_STAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_up_full_START (0)
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_up_full_END (0)
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_up_empty_START (1)
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_up_empty_END (1)
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_dn_full_START (2)
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_dn_full_END (2)
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_dn_empty_START (3)
#define SOC_ASP_SoundWire_DP0_FIFO_STAT_dp0_fifo_dn_empty_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_fifo_up_full : 1;
        unsigned char dp1_fifo_up_empty : 1;
        unsigned char reserved_0 : 2;
        unsigned char dp2_fifo_up_full : 1;
        unsigned char dp2_fifo_up_empty : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp1_fifo_up_full_START (0)
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp1_fifo_up_full_END (0)
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp1_fifo_up_empty_START (1)
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp1_fifo_up_empty_END (1)
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp2_fifo_up_full_START (4)
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp2_fifo_up_full_END (4)
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp2_fifo_up_empty_START (5)
#define SOC_ASP_SoundWire_DP12_FIFO_INTSTAT_dp2_fifo_up_empty_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_fifo_up_full : 1;
        unsigned char dp3_fifo_up_empty : 1;
        unsigned char reserved_0 : 2;
        unsigned char dp4_fifo_up_full : 1;
        unsigned char dp4_fifo_up_empty : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp3_fifo_up_full_START (0)
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp3_fifo_up_full_END (0)
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp3_fifo_up_empty_START (1)
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp3_fifo_up_empty_END (1)
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp4_fifo_up_full_START (4)
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp4_fifo_up_full_END (4)
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp4_fifo_up_empty_START (5)
#define SOC_ASP_SoundWire_DP34_FIFO_INTSTAT_dp4_fifo_up_empty_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_fifo_up_full : 1;
        unsigned char dp5_fifo_up_empty : 1;
        unsigned char reserved_0 : 2;
        unsigned char dp6_fifo_up_full : 1;
        unsigned char dp6_fifo_up_empty : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp5_fifo_up_full_START (0)
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp5_fifo_up_full_END (0)
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp5_fifo_up_empty_START (1)
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp5_fifo_up_empty_END (1)
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp6_fifo_up_full_START (4)
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp6_fifo_up_full_END (4)
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp6_fifo_up_empty_START (5)
#define SOC_ASP_SoundWire_DP56_FIFO_INTSTAT_dp6_fifo_up_empty_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_fifo_up_full : 1;
        unsigned char dp7_fifo_up_empty : 1;
        unsigned char reserved_0 : 2;
        unsigned char dp8_fifo_up_full : 1;
        unsigned char dp8_fifo_up_empty : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp7_fifo_up_full_START (0)
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp7_fifo_up_full_END (0)
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp7_fifo_up_empty_START (1)
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp7_fifo_up_empty_END (1)
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp8_fifo_up_full_START (4)
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp8_fifo_up_full_END (4)
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp8_fifo_up_empty_START (5)
#define SOC_ASP_SoundWire_DP78_FIFO_INTSTAT_dp8_fifo_up_empty_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_fifo_up_full : 1;
        unsigned char dp9_fifo_up_empty : 1;
        unsigned char reserved : 4;
        unsigned char dp10_fifo_dn_full : 1;
        unsigned char dp10_fifo_dn_empty : 1;
    } reg;
} SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp9_fifo_up_full_START (0)
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp9_fifo_up_full_END (0)
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp9_fifo_up_empty_START (1)
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp9_fifo_up_empty_END (1)
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp10_fifo_dn_full_START (6)
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp10_fifo_dn_full_END (6)
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp10_fifo_dn_empty_START (7)
#define SOC_ASP_SoundWire_DP910_FIFO_INTSTAT_dp10_fifo_dn_empty_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 2;
        unsigned char dp11_fifo_dn_full : 1;
        unsigned char dp11_fifo_dn_empty : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp12_fifo_dn_full : 1;
        unsigned char dp12_fifo_dn_empty : 1;
    } reg;
} SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp11_fifo_dn_full_START (2)
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp11_fifo_dn_full_END (2)
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp11_fifo_dn_empty_START (3)
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp11_fifo_dn_empty_END (3)
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp12_fifo_dn_full_START (6)
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp12_fifo_dn_full_END (6)
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp12_fifo_dn_empty_START (7)
#define SOC_ASP_SoundWire_DP1112_FIFO_INTSTAT_dp12_fifo_dn_empty_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved_0 : 2;
        unsigned char dp13_fifo_dn_full : 1;
        unsigned char dp13_fifo_dn_empty : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp14_fifo_dn_full : 1;
        unsigned char dp14_fifo_dn_empty : 1;
    } reg;
} SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp13_fifo_dn_full_START (2)
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp13_fifo_dn_full_END (2)
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp13_fifo_dn_empty_START (3)
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp13_fifo_dn_empty_END (3)
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp14_fifo_dn_full_START (6)
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp14_fifo_dn_full_END (6)
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp14_fifo_dn_empty_START (7)
#define SOC_ASP_SoundWire_DP1314_FIFO_INTSTAT_dp14_fifo_dn_empty_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char version : 8;
    } reg;
} SOC_ASP_SoundWire_SOUNDWIRE_VERSION_UNION;
#endif
#define SOC_ASP_SoundWire_SOUNDWIRE_VERSION_version_START (0)
#define SOC_ASP_SoundWire_SOUNDWIRE_VERSION_version_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_test_fail_int : 1;
        unsigned char dp1_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp1_cfg_error0_int : 1;
        unsigned char dp1_cfg_error1_int : 1;
        unsigned char dp1_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP1_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP1_INTSTAT_dp1_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_test_fail_int_mask : 1;
        unsigned char dp1_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp1_cfg_error0_int_mask : 1;
        unsigned char dp1_cfg_error1_int_mask : 1;
        unsigned char dp1_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP1_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP1_INTMASK_dp1_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_portflowmode : 2;
        unsigned char dp1_portdatamode : 2;
        unsigned char dp1_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP1_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_PORTCTRL_dp1_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP1_PORTCTRL_dp1_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP1_PORTCTRL_dp1_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP1_PORTCTRL_dp1_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP1_PORTCTRL_dp1_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP1_PORTCTRL_dp1_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP1_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL1_dp1_wordlength_START (0)
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL1_dp1_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_n_finished_channel1 : 1;
        unsigned char dp1_n_finished_channel2 : 1;
        unsigned char dp1_n_finished_channel3 : 1;
        unsigned char dp1_n_finished_channel4 : 1;
        unsigned char dp1_n_finished_channel5 : 1;
        unsigned char dp1_n_finished_channel6 : 1;
        unsigned char dp1_n_finished_channel7 : 1;
        unsigned char dp1_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP1_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP1_PREPARESTATUS_dp1_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_prepare_channel1 : 1;
        unsigned char dp1_prepare_channel2 : 1;
        unsigned char dp1_prepare_channel3 : 1;
        unsigned char dp1_prepare_channel4 : 1;
        unsigned char dp1_prepare_channel5 : 1;
        unsigned char dp1_prepare_channel6 : 1;
        unsigned char dp1_prepare_channel7 : 1;
        unsigned char dp1_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP1_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP1_PREPARECTRL_dp1_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_enable_channel1_bank0 : 1;
        unsigned char dp1_enable_channel2_bank0 : 1;
        unsigned char dp1_enable_channel3_bank0 : 1;
        unsigned char dp1_enable_channel4_bank0 : 1;
        unsigned char dp1_enable_channel5_bank0 : 1;
        unsigned char dp1_enable_channel6_bank0 : 1;
        unsigned char dp1_enable_channel7_bank0 : 1;
        unsigned char dp1_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK0_dp1_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK0_dp1_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK0_dp1_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK0_dp1_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK0_dp1_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK0_dp1_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK0_dp1_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK0_dp1_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK0_dp1_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK0_dp1_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK0_dp1_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_hstop_bank0 : 4;
        unsigned char dp1_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP1_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK0_dp1_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK0_dp1_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK0_dp1_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK0_dp1_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK0_dp1_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK0_dp1_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP1_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK0_dp1_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK0_dp1_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_enable_channel1_bank1 : 1;
        unsigned char dp1_enable_channel2_bank1 : 1;
        unsigned char dp1_enable_channel3_bank1 : 1;
        unsigned char dp1_enable_channel4_bank1 : 1;
        unsigned char dp1_enable_channel5_bank1 : 1;
        unsigned char dp1_enable_channel6_bank1 : 1;
        unsigned char dp1_enable_channel7_bank1 : 1;
        unsigned char dp1_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP1_CHANNELEN_BANK1_dp1_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK1_dp1_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL2_BANK1_dp1_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK1_dp1_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL1_BANK1_dp1_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK1_dp1_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_SAMPLECTRL2_BANK1_dp1_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK1_dp1_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL1_BANK1_dp1_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK1_dp1_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_OFFSETCTRL2_BANK1_dp1_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_hstop_bank1 : 4;
        unsigned char dp1_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP1_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK1_dp1_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK1_dp1_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK1_dp1_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP1_HCTRL_BANK1_dp1_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK1_dp1_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_BLOCKCTRL3_BANK1_dp1_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp1_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP1_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK1_dp1_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP1_LANECTRL_BANK1_dp1_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_test_fail_int : 1;
        unsigned char dp2_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp2_cfg_error0_int : 1;
        unsigned char dp2_cfg_error1_int : 1;
        unsigned char dp2_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP2_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP2_INTSTAT_dp2_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_test_fail_int_mask : 1;
        unsigned char dp2_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp2_cfg_error0_int_mask : 1;
        unsigned char dp2_cfg_error1_int_mask : 1;
        unsigned char dp2_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP2_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP2_INTMASK_dp2_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_portflowmode : 2;
        unsigned char dp2_portdatamode : 2;
        unsigned char dp2_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP2_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_PORTCTRL_dp2_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP2_PORTCTRL_dp2_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP2_PORTCTRL_dp2_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP2_PORTCTRL_dp2_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP2_PORTCTRL_dp2_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP2_PORTCTRL_dp2_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP2_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL1_dp2_wordlength_START (0)
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL1_dp2_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_n_finished_channel1 : 1;
        unsigned char dp2_n_finished_channel2 : 1;
        unsigned char dp2_n_finished_channel3 : 1;
        unsigned char dp2_n_finished_channel4 : 1;
        unsigned char dp2_n_finished_channel5 : 1;
        unsigned char dp2_n_finished_channel6 : 1;
        unsigned char dp2_n_finished_channel7 : 1;
        unsigned char dp2_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP2_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP2_PREPARESTATUS_dp2_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_prepare_channel1 : 1;
        unsigned char dp2_prepare_channel2 : 1;
        unsigned char dp2_prepare_channel3 : 1;
        unsigned char dp2_prepare_channel4 : 1;
        unsigned char dp2_prepare_channel5 : 1;
        unsigned char dp2_prepare_channel6 : 1;
        unsigned char dp2_prepare_channel7 : 1;
        unsigned char dp2_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP2_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP2_PREPARECTRL_dp2_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_enable_channel1_bank0 : 1;
        unsigned char dp2_enable_channel2_bank0 : 1;
        unsigned char dp2_enable_channel3_bank0 : 1;
        unsigned char dp2_enable_channel4_bank0 : 1;
        unsigned char dp2_enable_channel5_bank0 : 1;
        unsigned char dp2_enable_channel6_bank0 : 1;
        unsigned char dp2_enable_channel7_bank0 : 1;
        unsigned char dp2_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK0_dp2_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK0_dp2_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK0_dp2_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK0_dp2_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK0_dp2_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK0_dp2_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK0_dp2_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK0_dp2_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK0_dp2_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK0_dp2_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK0_dp2_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_hstop_bank0 : 4;
        unsigned char dp2_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP2_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK0_dp2_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK0_dp2_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK0_dp2_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK0_dp2_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK0_dp2_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK0_dp2_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP2_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK0_dp2_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK0_dp2_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_enable_channel1_bank1 : 1;
        unsigned char dp2_enable_channel2_bank1 : 1;
        unsigned char dp2_enable_channel3_bank1 : 1;
        unsigned char dp2_enable_channel4_bank1 : 1;
        unsigned char dp2_enable_channel5_bank1 : 1;
        unsigned char dp2_enable_channel6_bank1 : 1;
        unsigned char dp2_enable_channel7_bank1 : 1;
        unsigned char dp2_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP2_CHANNELEN_BANK1_dp2_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK1_dp2_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL2_BANK1_dp2_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK1_dp2_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL1_BANK1_dp2_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK1_dp2_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_SAMPLECTRL2_BANK1_dp2_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK1_dp2_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL1_BANK1_dp2_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK1_dp2_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_OFFSETCTRL2_BANK1_dp2_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_hstop_bank1 : 4;
        unsigned char dp2_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP2_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK1_dp2_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK1_dp2_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK1_dp2_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP2_HCTRL_BANK1_dp2_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK1_dp2_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_BLOCKCTRL3_BANK1_dp2_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp2_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP2_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK1_dp2_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP2_LANECTRL_BANK1_dp2_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_test_fail_int : 1;
        unsigned char dp3_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp3_cfg_error0_int : 1;
        unsigned char dp3_cfg_error1_int : 1;
        unsigned char dp3_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP3_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP3_INTSTAT_dp3_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_test_fail_int_mask : 1;
        unsigned char dp3_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp3_cfg_error0_int_mask : 1;
        unsigned char dp3_cfg_error1_int_mask : 1;
        unsigned char dp3_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP3_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP3_INTMASK_dp3_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_portflowmode : 2;
        unsigned char dp3_portdatamode : 2;
        unsigned char dp3_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP3_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_PORTCTRL_dp3_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP3_PORTCTRL_dp3_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP3_PORTCTRL_dp3_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP3_PORTCTRL_dp3_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP3_PORTCTRL_dp3_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP3_PORTCTRL_dp3_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP3_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL1_dp3_wordlength_START (0)
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL1_dp3_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_n_finished_channel1 : 1;
        unsigned char dp3_n_finished_channel2 : 1;
        unsigned char dp3_n_finished_channel3 : 1;
        unsigned char dp3_n_finished_channel4 : 1;
        unsigned char dp3_n_finished_channel5 : 1;
        unsigned char dp3_n_finished_channel6 : 1;
        unsigned char dp3_n_finished_channel7 : 1;
        unsigned char dp3_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP3_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP3_PREPARESTATUS_dp3_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_prepare_channel1 : 1;
        unsigned char dp3_prepare_channel2 : 1;
        unsigned char dp3_prepare_channel3 : 1;
        unsigned char dp3_prepare_channel4 : 1;
        unsigned char dp3_prepare_channel5 : 1;
        unsigned char dp3_prepare_channel6 : 1;
        unsigned char dp3_prepare_channel7 : 1;
        unsigned char dp3_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP3_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP3_PREPARECTRL_dp3_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_enable_channel1_bank0 : 1;
        unsigned char dp3_enable_channel2_bank0 : 1;
        unsigned char dp3_enable_channel3_bank0 : 1;
        unsigned char dp3_enable_channel4_bank0 : 1;
        unsigned char dp3_enable_channel5_bank0 : 1;
        unsigned char dp3_enable_channel6_bank0 : 1;
        unsigned char dp3_enable_channel7_bank0 : 1;
        unsigned char dp3_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK0_dp3_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK0_dp3_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK0_dp3_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK0_dp3_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK0_dp3_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK0_dp3_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK0_dp3_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK0_dp3_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK0_dp3_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK0_dp3_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK0_dp3_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_hstop_bank0 : 4;
        unsigned char dp3_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP3_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK0_dp3_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK0_dp3_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK0_dp3_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK0_dp3_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK0_dp3_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK0_dp3_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP3_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK0_dp3_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK0_dp3_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_enable_channel1_bank1 : 1;
        unsigned char dp3_enable_channel2_bank1 : 1;
        unsigned char dp3_enable_channel3_bank1 : 1;
        unsigned char dp3_enable_channel4_bank1 : 1;
        unsigned char dp3_enable_channel5_bank1 : 1;
        unsigned char dp3_enable_channel6_bank1 : 1;
        unsigned char dp3_enable_channel7_bank1 : 1;
        unsigned char dp3_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP3_CHANNELEN_BANK1_dp3_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK1_dp3_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL2_BANK1_dp3_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK1_dp3_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL1_BANK1_dp3_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK1_dp3_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_SAMPLECTRL2_BANK1_dp3_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK1_dp3_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL1_BANK1_dp3_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK1_dp3_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_OFFSETCTRL2_BANK1_dp3_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_hstop_bank1 : 4;
        unsigned char dp3_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP3_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK1_dp3_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK1_dp3_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK1_dp3_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP3_HCTRL_BANK1_dp3_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK1_dp3_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_BLOCKCTRL3_BANK1_dp3_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp3_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP3_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK1_dp3_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP3_LANECTRL_BANK1_dp3_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_test_fail_int : 1;
        unsigned char dp4_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp4_cfg_error0_int : 1;
        unsigned char dp4_cfg_error1_int : 1;
        unsigned char dp4_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP4_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP4_INTSTAT_dp4_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_test_fail_int_mask : 1;
        unsigned char dp4_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp4_cfg_error0_int_mask : 1;
        unsigned char dp4_cfg_error1_int_mask : 1;
        unsigned char dp4_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP4_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP4_INTMASK_dp4_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_portflowmode : 2;
        unsigned char dp4_portdatamode : 2;
        unsigned char dp4_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP4_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_PORTCTRL_dp4_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP4_PORTCTRL_dp4_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP4_PORTCTRL_dp4_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP4_PORTCTRL_dp4_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP4_PORTCTRL_dp4_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP4_PORTCTRL_dp4_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP4_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL1_dp4_wordlength_START (0)
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL1_dp4_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_n_finished_channel1 : 1;
        unsigned char dp4_n_finished_channel2 : 1;
        unsigned char dp4_n_finished_channel3 : 1;
        unsigned char dp4_n_finished_channel4 : 1;
        unsigned char dp4_n_finished_channel5 : 1;
        unsigned char dp4_n_finished_channel6 : 1;
        unsigned char dp4_n_finished_channel7 : 1;
        unsigned char dp4_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP4_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP4_PREPARESTATUS_dp4_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_prepare_channel1 : 1;
        unsigned char dp4_prepare_channel2 : 1;
        unsigned char dp4_prepare_channel3 : 1;
        unsigned char dp4_prepare_channel4 : 1;
        unsigned char dp4_prepare_channel5 : 1;
        unsigned char dp4_prepare_channel6 : 1;
        unsigned char dp4_prepare_channel7 : 1;
        unsigned char dp4_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP4_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP4_PREPARECTRL_dp4_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_enable_channel1_bank0 : 1;
        unsigned char dp4_enable_channel2_bank0 : 1;
        unsigned char dp4_enable_channel3_bank0 : 1;
        unsigned char dp4_enable_channel4_bank0 : 1;
        unsigned char dp4_enable_channel5_bank0 : 1;
        unsigned char dp4_enable_channel6_bank0 : 1;
        unsigned char dp4_enable_channel7_bank0 : 1;
        unsigned char dp4_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK0_dp4_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK0_dp4_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK0_dp4_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK0_dp4_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK0_dp4_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK0_dp4_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK0_dp4_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK0_dp4_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK0_dp4_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK0_dp4_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK0_dp4_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_hstop_bank0 : 4;
        unsigned char dp4_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP4_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK0_dp4_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK0_dp4_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK0_dp4_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK0_dp4_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK0_dp4_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK0_dp4_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP4_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK0_dp4_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK0_dp4_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_enable_channel1_bank1 : 1;
        unsigned char dp4_enable_channel2_bank1 : 1;
        unsigned char dp4_enable_channel3_bank1 : 1;
        unsigned char dp4_enable_channel4_bank1 : 1;
        unsigned char dp4_enable_channel5_bank1 : 1;
        unsigned char dp4_enable_channel6_bank1 : 1;
        unsigned char dp4_enable_channel7_bank1 : 1;
        unsigned char dp4_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP4_CHANNELEN_BANK1_dp4_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK1_dp4_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL2_BANK1_dp4_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK1_dp4_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL1_BANK1_dp4_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK1_dp4_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_SAMPLECTRL2_BANK1_dp4_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK1_dp4_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL1_BANK1_dp4_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK1_dp4_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_OFFSETCTRL2_BANK1_dp4_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_hstop_bank1 : 4;
        unsigned char dp4_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP4_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK1_dp4_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK1_dp4_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK1_dp4_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP4_HCTRL_BANK1_dp4_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK1_dp4_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_BLOCKCTRL3_BANK1_dp4_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp4_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP4_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK1_dp4_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP4_LANECTRL_BANK1_dp4_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_test_fail_int : 1;
        unsigned char dp5_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp5_cfg_error0_int : 1;
        unsigned char dp5_cfg_error1_int : 1;
        unsigned char dp5_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP5_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP5_INTSTAT_dp5_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_test_fail_int_mask : 1;
        unsigned char dp5_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp5_cfg_error0_int_mask : 1;
        unsigned char dp5_cfg_error1_int_mask : 1;
        unsigned char dp5_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP5_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP5_INTMASK_dp5_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_portflowmode : 2;
        unsigned char dp5_portdatamode : 2;
        unsigned char dp5_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP5_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_PORTCTRL_dp5_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP5_PORTCTRL_dp5_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP5_PORTCTRL_dp5_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP5_PORTCTRL_dp5_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP5_PORTCTRL_dp5_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP5_PORTCTRL_dp5_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP5_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL1_dp5_wordlength_START (0)
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL1_dp5_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_n_finished_channel1 : 1;
        unsigned char dp5_n_finished_channel2 : 1;
        unsigned char dp5_n_finished_channel3 : 1;
        unsigned char dp5_n_finished_channel4 : 1;
        unsigned char dp5_n_finished_channel5 : 1;
        unsigned char dp5_n_finished_channel6 : 1;
        unsigned char dp5_n_finished_channel7 : 1;
        unsigned char dp5_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP5_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP5_PREPARESTATUS_dp5_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_prepare_channel1 : 1;
        unsigned char dp5_prepare_channel2 : 1;
        unsigned char dp5_prepare_channel3 : 1;
        unsigned char dp5_prepare_channel4 : 1;
        unsigned char dp5_prepare_channel5 : 1;
        unsigned char dp5_prepare_channel6 : 1;
        unsigned char dp5_prepare_channel7 : 1;
        unsigned char dp5_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP5_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP5_PREPARECTRL_dp5_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_enable_channel1_bank0 : 1;
        unsigned char dp5_enable_channel2_bank0 : 1;
        unsigned char dp5_enable_channel3_bank0 : 1;
        unsigned char dp5_enable_channel4_bank0 : 1;
        unsigned char dp5_enable_channel5_bank0 : 1;
        unsigned char dp5_enable_channel6_bank0 : 1;
        unsigned char dp5_enable_channel7_bank0 : 1;
        unsigned char dp5_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK0_dp5_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK0_dp5_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK0_dp5_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK0_dp5_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK0_dp5_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK0_dp5_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK0_dp5_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK0_dp5_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK0_dp5_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK0_dp5_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK0_dp5_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_hstop_bank0 : 4;
        unsigned char dp5_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP5_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK0_dp5_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK0_dp5_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK0_dp5_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK0_dp5_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK0_dp5_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK0_dp5_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP5_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK0_dp5_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK0_dp5_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_enable_channel1_bank1 : 1;
        unsigned char dp5_enable_channel2_bank1 : 1;
        unsigned char dp5_enable_channel3_bank1 : 1;
        unsigned char dp5_enable_channel4_bank1 : 1;
        unsigned char dp5_enable_channel5_bank1 : 1;
        unsigned char dp5_enable_channel6_bank1 : 1;
        unsigned char dp5_enable_channel7_bank1 : 1;
        unsigned char dp5_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP5_CHANNELEN_BANK1_dp5_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK1_dp5_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL2_BANK1_dp5_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK1_dp5_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL1_BANK1_dp5_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK1_dp5_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_SAMPLECTRL2_BANK1_dp5_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK1_dp5_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL1_BANK1_dp5_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK1_dp5_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_OFFSETCTRL2_BANK1_dp5_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_hstop_bank1 : 4;
        unsigned char dp5_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP5_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK1_dp5_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK1_dp5_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK1_dp5_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP5_HCTRL_BANK1_dp5_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK1_dp5_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_BLOCKCTRL3_BANK1_dp5_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp5_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP5_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK1_dp5_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP5_LANECTRL_BANK1_dp5_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_test_fail_int : 1;
        unsigned char dp6_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp6_cfg_error0_int : 1;
        unsigned char dp6_cfg_error1_int : 1;
        unsigned char dp6_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP6_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP6_INTSTAT_dp6_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_test_fail_int_mask : 1;
        unsigned char dp6_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp6_cfg_error0_int_mask : 1;
        unsigned char dp6_cfg_error1_int_mask : 1;
        unsigned char dp6_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP6_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP6_INTMASK_dp6_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_portflowmode : 2;
        unsigned char dp6_portdatamode : 2;
        unsigned char dp6_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP6_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_PORTCTRL_dp6_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP6_PORTCTRL_dp6_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP6_PORTCTRL_dp6_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP6_PORTCTRL_dp6_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP6_PORTCTRL_dp6_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP6_PORTCTRL_dp6_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP6_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL1_dp6_wordlength_START (0)
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL1_dp6_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_n_finished_channel1 : 1;
        unsigned char dp6_n_finished_channel2 : 1;
        unsigned char dp6_n_finished_channel3 : 1;
        unsigned char dp6_n_finished_channel4 : 1;
        unsigned char dp6_n_finished_channel5 : 1;
        unsigned char dp6_n_finished_channel6 : 1;
        unsigned char dp6_n_finished_channel7 : 1;
        unsigned char dp6_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP6_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP6_PREPARESTATUS_dp6_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_prepare_channel1 : 1;
        unsigned char dp6_prepare_channel2 : 1;
        unsigned char dp6_prepare_channel3 : 1;
        unsigned char dp6_prepare_channel4 : 1;
        unsigned char dp6_prepare_channel5 : 1;
        unsigned char dp6_prepare_channel6 : 1;
        unsigned char dp6_prepare_channel7 : 1;
        unsigned char dp6_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP6_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP6_PREPARECTRL_dp6_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_enable_channel1_bank0 : 1;
        unsigned char dp6_enable_channel2_bank0 : 1;
        unsigned char dp6_enable_channel3_bank0 : 1;
        unsigned char dp6_enable_channel4_bank0 : 1;
        unsigned char dp6_enable_channel5_bank0 : 1;
        unsigned char dp6_enable_channel6_bank0 : 1;
        unsigned char dp6_enable_channel7_bank0 : 1;
        unsigned char dp6_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK0_dp6_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK0_dp6_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK0_dp6_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK0_dp6_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK0_dp6_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK0_dp6_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK0_dp6_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK0_dp6_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK0_dp6_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK0_dp6_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK0_dp6_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_hstop_bank0 : 4;
        unsigned char dp6_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP6_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK0_dp6_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK0_dp6_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK0_dp6_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK0_dp6_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK0_dp6_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK0_dp6_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP6_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK0_dp6_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK0_dp6_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_enable_channel1_bank1 : 1;
        unsigned char dp6_enable_channel2_bank1 : 1;
        unsigned char dp6_enable_channel3_bank1 : 1;
        unsigned char dp6_enable_channel4_bank1 : 1;
        unsigned char dp6_enable_channel5_bank1 : 1;
        unsigned char dp6_enable_channel6_bank1 : 1;
        unsigned char dp6_enable_channel7_bank1 : 1;
        unsigned char dp6_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP6_CHANNELEN_BANK1_dp6_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK1_dp6_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL2_BANK1_dp6_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK1_dp6_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL1_BANK1_dp6_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK1_dp6_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_SAMPLECTRL2_BANK1_dp6_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK1_dp6_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL1_BANK1_dp6_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK1_dp6_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_OFFSETCTRL2_BANK1_dp6_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_hstop_bank1 : 4;
        unsigned char dp6_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP6_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK1_dp6_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK1_dp6_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK1_dp6_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP6_HCTRL_BANK1_dp6_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK1_dp6_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_BLOCKCTRL3_BANK1_dp6_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp6_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP6_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK1_dp6_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP6_LANECTRL_BANK1_dp6_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_test_fail_int : 1;
        unsigned char dp7_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp7_cfg_error0_int : 1;
        unsigned char dp7_cfg_error1_int : 1;
        unsigned char dp7_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP7_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP7_INTSTAT_dp7_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_test_fail_int_mask : 1;
        unsigned char dp7_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp7_cfg_error0_int_mask : 1;
        unsigned char dp7_cfg_error1_int_mask : 1;
        unsigned char dp7_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP7_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP7_INTMASK_dp7_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_portflowmode : 2;
        unsigned char dp7_portdatamode : 2;
        unsigned char dp7_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP7_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_PORTCTRL_dp7_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP7_PORTCTRL_dp7_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP7_PORTCTRL_dp7_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP7_PORTCTRL_dp7_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP7_PORTCTRL_dp7_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP7_PORTCTRL_dp7_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP7_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL1_dp7_wordlength_START (0)
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL1_dp7_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_n_finished_channel1 : 1;
        unsigned char dp7_n_finished_channel2 : 1;
        unsigned char dp7_n_finished_channel3 : 1;
        unsigned char dp7_n_finished_channel4 : 1;
        unsigned char dp7_n_finished_channel5 : 1;
        unsigned char dp7_n_finished_channel6 : 1;
        unsigned char dp7_n_finished_channel7 : 1;
        unsigned char dp7_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP7_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP7_PREPARESTATUS_dp7_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_prepare_channel1 : 1;
        unsigned char dp7_prepare_channel2 : 1;
        unsigned char dp7_prepare_channel3 : 1;
        unsigned char dp7_prepare_channel4 : 1;
        unsigned char dp7_prepare_channel5 : 1;
        unsigned char dp7_prepare_channel6 : 1;
        unsigned char dp7_prepare_channel7 : 1;
        unsigned char dp7_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP7_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP7_PREPARECTRL_dp7_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_enable_channel1_bank0 : 1;
        unsigned char dp7_enable_channel2_bank0 : 1;
        unsigned char dp7_enable_channel3_bank0 : 1;
        unsigned char dp7_enable_channel4_bank0 : 1;
        unsigned char dp7_enable_channel5_bank0 : 1;
        unsigned char dp7_enable_channel6_bank0 : 1;
        unsigned char dp7_enable_channel7_bank0 : 1;
        unsigned char dp7_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK0_dp7_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK0_dp7_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK0_dp7_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK0_dp7_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK0_dp7_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK0_dp7_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK0_dp7_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK0_dp7_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK0_dp7_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK0_dp7_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK0_dp7_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_hstop_bank0 : 4;
        unsigned char dp7_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP7_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK0_dp7_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK0_dp7_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK0_dp7_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK0_dp7_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK0_dp7_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK0_dp7_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP7_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK0_dp7_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK0_dp7_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_enable_channel1_bank1 : 1;
        unsigned char dp7_enable_channel2_bank1 : 1;
        unsigned char dp7_enable_channel3_bank1 : 1;
        unsigned char dp7_enable_channel4_bank1 : 1;
        unsigned char dp7_enable_channel5_bank1 : 1;
        unsigned char dp7_enable_channel6_bank1 : 1;
        unsigned char dp7_enable_channel7_bank1 : 1;
        unsigned char dp7_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP7_CHANNELEN_BANK1_dp7_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK1_dp7_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL2_BANK1_dp7_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK1_dp7_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL1_BANK1_dp7_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK1_dp7_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_SAMPLECTRL2_BANK1_dp7_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK1_dp7_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL1_BANK1_dp7_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK1_dp7_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_OFFSETCTRL2_BANK1_dp7_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_hstop_bank1 : 4;
        unsigned char dp7_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP7_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK1_dp7_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK1_dp7_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK1_dp7_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP7_HCTRL_BANK1_dp7_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK1_dp7_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_BLOCKCTRL3_BANK1_dp7_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp7_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP7_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK1_dp7_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP7_LANECTRL_BANK1_dp7_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_test_fail_int : 1;
        unsigned char dp8_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp8_cfg_error0_int : 1;
        unsigned char dp8_cfg_error1_int : 1;
        unsigned char dp8_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP8_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP8_INTSTAT_dp8_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_test_fail_int_mask : 1;
        unsigned char dp8_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp8_cfg_error0_int_mask : 1;
        unsigned char dp8_cfg_error1_int_mask : 1;
        unsigned char dp8_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP8_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP8_INTMASK_dp8_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_portflowmode : 2;
        unsigned char dp8_portdatamode : 2;
        unsigned char dp8_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP8_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_PORTCTRL_dp8_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP8_PORTCTRL_dp8_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP8_PORTCTRL_dp8_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP8_PORTCTRL_dp8_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP8_PORTCTRL_dp8_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP8_PORTCTRL_dp8_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP8_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL1_dp8_wordlength_START (0)
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL1_dp8_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_n_finished_channel1 : 1;
        unsigned char dp8_n_finished_channel2 : 1;
        unsigned char dp8_n_finished_channel3 : 1;
        unsigned char dp8_n_finished_channel4 : 1;
        unsigned char dp8_n_finished_channel5 : 1;
        unsigned char dp8_n_finished_channel6 : 1;
        unsigned char dp8_n_finished_channel7 : 1;
        unsigned char dp8_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP8_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP8_PREPARESTATUS_dp8_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_prepare_channel1 : 1;
        unsigned char dp8_prepare_channel2 : 1;
        unsigned char dp8_prepare_channel3 : 1;
        unsigned char dp8_prepare_channel4 : 1;
        unsigned char dp8_prepare_channel5 : 1;
        unsigned char dp8_prepare_channel6 : 1;
        unsigned char dp8_prepare_channel7 : 1;
        unsigned char dp8_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP8_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP8_PREPARECTRL_dp8_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_enable_channel1_bank0 : 1;
        unsigned char dp8_enable_channel2_bank0 : 1;
        unsigned char dp8_enable_channel3_bank0 : 1;
        unsigned char dp8_enable_channel4_bank0 : 1;
        unsigned char dp8_enable_channel5_bank0 : 1;
        unsigned char dp8_enable_channel6_bank0 : 1;
        unsigned char dp8_enable_channel7_bank0 : 1;
        unsigned char dp8_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK0_dp8_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK0_dp8_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK0_dp8_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK0_dp8_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK0_dp8_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK0_dp8_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK0_dp8_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK0_dp8_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK0_dp8_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK0_dp8_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK0_dp8_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_hstop_bank0 : 4;
        unsigned char dp8_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP8_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK0_dp8_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK0_dp8_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK0_dp8_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK0_dp8_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK0_dp8_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK0_dp8_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP8_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK0_dp8_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK0_dp8_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_enable_channel1_bank1 : 1;
        unsigned char dp8_enable_channel2_bank1 : 1;
        unsigned char dp8_enable_channel3_bank1 : 1;
        unsigned char dp8_enable_channel4_bank1 : 1;
        unsigned char dp8_enable_channel5_bank1 : 1;
        unsigned char dp8_enable_channel6_bank1 : 1;
        unsigned char dp8_enable_channel7_bank1 : 1;
        unsigned char dp8_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP8_CHANNELEN_BANK1_dp8_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK1_dp8_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL2_BANK1_dp8_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK1_dp8_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL1_BANK1_dp8_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK1_dp8_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_SAMPLECTRL2_BANK1_dp8_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK1_dp8_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL1_BANK1_dp8_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK1_dp8_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_OFFSETCTRL2_BANK1_dp8_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_hstop_bank1 : 4;
        unsigned char dp8_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP8_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK1_dp8_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK1_dp8_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK1_dp8_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP8_HCTRL_BANK1_dp8_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK1_dp8_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_BLOCKCTRL3_BANK1_dp8_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp8_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP8_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK1_dp8_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP8_LANECTRL_BANK1_dp8_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_test_fail_int : 1;
        unsigned char dp9_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp9_cfg_error0_int : 1;
        unsigned char dp9_cfg_error1_int : 1;
        unsigned char dp9_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP9_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP9_INTSTAT_dp9_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_test_fail_int_mask : 1;
        unsigned char dp9_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp9_cfg_error0_int_mask : 1;
        unsigned char dp9_cfg_error1_int_mask : 1;
        unsigned char dp9_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP9_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP9_INTMASK_dp9_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_portflowmode : 2;
        unsigned char dp9_portdatamode : 2;
        unsigned char dp9_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP9_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_PORTCTRL_dp9_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP9_PORTCTRL_dp9_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP9_PORTCTRL_dp9_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP9_PORTCTRL_dp9_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP9_PORTCTRL_dp9_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP9_PORTCTRL_dp9_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP9_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL1_dp9_wordlength_START (0)
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL1_dp9_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_n_finished_channel1 : 1;
        unsigned char dp9_n_finished_channel2 : 1;
        unsigned char dp9_n_finished_channel3 : 1;
        unsigned char dp9_n_finished_channel4 : 1;
        unsigned char dp9_n_finished_channel5 : 1;
        unsigned char dp9_n_finished_channel6 : 1;
        unsigned char dp9_n_finished_channel7 : 1;
        unsigned char dp9_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP9_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP9_PREPARESTATUS_dp9_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_prepare_channel1 : 1;
        unsigned char dp9_prepare_channel2 : 1;
        unsigned char dp9_prepare_channel3 : 1;
        unsigned char dp9_prepare_channel4 : 1;
        unsigned char dp9_prepare_channel5 : 1;
        unsigned char dp9_prepare_channel6 : 1;
        unsigned char dp9_prepare_channel7 : 1;
        unsigned char dp9_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP9_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP9_PREPARECTRL_dp9_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_enable_channel1_bank0 : 1;
        unsigned char dp9_enable_channel2_bank0 : 1;
        unsigned char dp9_enable_channel3_bank0 : 1;
        unsigned char dp9_enable_channel4_bank0 : 1;
        unsigned char dp9_enable_channel5_bank0 : 1;
        unsigned char dp9_enable_channel6_bank0 : 1;
        unsigned char dp9_enable_channel7_bank0 : 1;
        unsigned char dp9_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK0_dp9_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK0_dp9_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK0_dp9_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK0_dp9_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK0_dp9_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK0_dp9_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK0_dp9_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK0_dp9_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK0_dp9_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK0_dp9_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK0_dp9_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_hstop_bank0 : 4;
        unsigned char dp9_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP9_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK0_dp9_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK0_dp9_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK0_dp9_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK0_dp9_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK0_dp9_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK0_dp9_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP9_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK0_dp9_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK0_dp9_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_enable_channel1_bank1 : 1;
        unsigned char dp9_enable_channel2_bank1 : 1;
        unsigned char dp9_enable_channel3_bank1 : 1;
        unsigned char dp9_enable_channel4_bank1 : 1;
        unsigned char dp9_enable_channel5_bank1 : 1;
        unsigned char dp9_enable_channel6_bank1 : 1;
        unsigned char dp9_enable_channel7_bank1 : 1;
        unsigned char dp9_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP9_CHANNELEN_BANK1_dp9_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK1_dp9_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL2_BANK1_dp9_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK1_dp9_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL1_BANK1_dp9_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK1_dp9_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_SAMPLECTRL2_BANK1_dp9_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK1_dp9_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL1_BANK1_dp9_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK1_dp9_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_OFFSETCTRL2_BANK1_dp9_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_hstop_bank1 : 4;
        unsigned char dp9_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP9_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK1_dp9_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK1_dp9_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK1_dp9_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP9_HCTRL_BANK1_dp9_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK1_dp9_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_BLOCKCTRL3_BANK1_dp9_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp9_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP9_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK1_dp9_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP9_LANECTRL_BANK1_dp9_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_test_fail_int : 1;
        unsigned char dp10_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp10_cfg_error0_int : 1;
        unsigned char dp10_cfg_error1_int : 1;
        unsigned char dp10_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP10_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP10_INTSTAT_dp10_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_test_fail_int_mask : 1;
        unsigned char dp10_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp10_cfg_error0_int_mask : 1;
        unsigned char dp10_cfg_error1_int_mask : 1;
        unsigned char dp10_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP10_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP10_INTMASK_dp10_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_portflowmode : 2;
        unsigned char dp10_portdatamode : 2;
        unsigned char dp10_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP10_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_PORTCTRL_dp10_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP10_PORTCTRL_dp10_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP10_PORTCTRL_dp10_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP10_PORTCTRL_dp10_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP10_PORTCTRL_dp10_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP10_PORTCTRL_dp10_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP10_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL1_dp10_wordlength_START (0)
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL1_dp10_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_n_finished_channel1 : 1;
        unsigned char dp10_n_finished_channel2 : 1;
        unsigned char dp10_n_finished_channel3 : 1;
        unsigned char dp10_n_finished_channel4 : 1;
        unsigned char dp10_n_finished_channel5 : 1;
        unsigned char dp10_n_finished_channel6 : 1;
        unsigned char dp10_n_finished_channel7 : 1;
        unsigned char dp10_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP10_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP10_PREPARESTATUS_dp10_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_prepare_channel1 : 1;
        unsigned char dp10_prepare_channel2 : 1;
        unsigned char dp10_prepare_channel3 : 1;
        unsigned char dp10_prepare_channel4 : 1;
        unsigned char dp10_prepare_channel5 : 1;
        unsigned char dp10_prepare_channel6 : 1;
        unsigned char dp10_prepare_channel7 : 1;
        unsigned char dp10_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP10_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP10_PREPARECTRL_dp10_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_enable_channel1_bank0 : 1;
        unsigned char dp10_enable_channel2_bank0 : 1;
        unsigned char dp10_enable_channel3_bank0 : 1;
        unsigned char dp10_enable_channel4_bank0 : 1;
        unsigned char dp10_enable_channel5_bank0 : 1;
        unsigned char dp10_enable_channel6_bank0 : 1;
        unsigned char dp10_enable_channel7_bank0 : 1;
        unsigned char dp10_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK0_dp10_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK0_dp10_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK0_dp10_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK0_dp10_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK0_dp10_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK0_dp10_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK0_dp10_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK0_dp10_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK0_dp10_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK0_dp10_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK0_dp10_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_hstop_bank0 : 4;
        unsigned char dp10_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP10_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK0_dp10_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK0_dp10_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK0_dp10_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK0_dp10_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK0_dp10_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK0_dp10_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP10_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK0_dp10_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK0_dp10_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_enable_channel1_bank1 : 1;
        unsigned char dp10_enable_channel2_bank1 : 1;
        unsigned char dp10_enable_channel3_bank1 : 1;
        unsigned char dp10_enable_channel4_bank1 : 1;
        unsigned char dp10_enable_channel5_bank1 : 1;
        unsigned char dp10_enable_channel6_bank1 : 1;
        unsigned char dp10_enable_channel7_bank1 : 1;
        unsigned char dp10_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP10_CHANNELEN_BANK1_dp10_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK1_dp10_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL2_BANK1_dp10_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK1_dp10_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL1_BANK1_dp10_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK1_dp10_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_SAMPLECTRL2_BANK1_dp10_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK1_dp10_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL1_BANK1_dp10_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK1_dp10_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_OFFSETCTRL2_BANK1_dp10_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_hstop_bank1 : 4;
        unsigned char dp10_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP10_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK1_dp10_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK1_dp10_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK1_dp10_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP10_HCTRL_BANK1_dp10_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK1_dp10_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_BLOCKCTRL3_BANK1_dp10_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp10_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP10_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK1_dp10_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP10_LANECTRL_BANK1_dp10_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_test_fail_int : 1;
        unsigned char dp11_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp11_cfg_error0_int : 1;
        unsigned char dp11_cfg_error1_int : 1;
        unsigned char dp11_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP11_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP11_INTSTAT_dp11_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_test_fail_int_mask : 1;
        unsigned char dp11_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp11_cfg_error0_int_mask : 1;
        unsigned char dp11_cfg_error1_int_mask : 1;
        unsigned char dp11_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP11_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP11_INTMASK_dp11_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_portflowmode : 2;
        unsigned char dp11_portdatamode : 2;
        unsigned char dp11_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP11_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_PORTCTRL_dp11_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP11_PORTCTRL_dp11_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP11_PORTCTRL_dp11_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP11_PORTCTRL_dp11_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP11_PORTCTRL_dp11_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP11_PORTCTRL_dp11_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP11_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL1_dp11_wordlength_START (0)
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL1_dp11_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_n_finished_channel1 : 1;
        unsigned char dp11_n_finished_channel2 : 1;
        unsigned char dp11_n_finished_channel3 : 1;
        unsigned char dp11_n_finished_channel4 : 1;
        unsigned char dp11_n_finished_channel5 : 1;
        unsigned char dp11_n_finished_channel6 : 1;
        unsigned char dp11_n_finished_channel7 : 1;
        unsigned char dp11_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP11_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP11_PREPARESTATUS_dp11_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_prepare_channel1 : 1;
        unsigned char dp11_prepare_channel2 : 1;
        unsigned char dp11_prepare_channel3 : 1;
        unsigned char dp11_prepare_channel4 : 1;
        unsigned char dp11_prepare_channel5 : 1;
        unsigned char dp11_prepare_channel6 : 1;
        unsigned char dp11_prepare_channel7 : 1;
        unsigned char dp11_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP11_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP11_PREPARECTRL_dp11_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_enable_channel1_bank0 : 1;
        unsigned char dp11_enable_channel2_bank0 : 1;
        unsigned char dp11_enable_channel3_bank0 : 1;
        unsigned char dp11_enable_channel4_bank0 : 1;
        unsigned char dp11_enable_channel5_bank0 : 1;
        unsigned char dp11_enable_channel6_bank0 : 1;
        unsigned char dp11_enable_channel7_bank0 : 1;
        unsigned char dp11_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK0_dp11_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK0_dp11_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK0_dp11_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK0_dp11_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK0_dp11_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK0_dp11_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK0_dp11_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK0_dp11_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK0_dp11_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK0_dp11_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK0_dp11_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_hstop_bank0 : 4;
        unsigned char dp11_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP11_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK0_dp11_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK0_dp11_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK0_dp11_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK0_dp11_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK0_dp11_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK0_dp11_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP11_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK0_dp11_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK0_dp11_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_enable_channel1_bank1 : 1;
        unsigned char dp11_enable_channel2_bank1 : 1;
        unsigned char dp11_enable_channel3_bank1 : 1;
        unsigned char dp11_enable_channel4_bank1 : 1;
        unsigned char dp11_enable_channel5_bank1 : 1;
        unsigned char dp11_enable_channel6_bank1 : 1;
        unsigned char dp11_enable_channel7_bank1 : 1;
        unsigned char dp11_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP11_CHANNELEN_BANK1_dp11_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK1_dp11_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL2_BANK1_dp11_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK1_dp11_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL1_BANK1_dp11_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK1_dp11_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_SAMPLECTRL2_BANK1_dp11_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK1_dp11_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL1_BANK1_dp11_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK1_dp11_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_OFFSETCTRL2_BANK1_dp11_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_hstop_bank1 : 4;
        unsigned char dp11_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP11_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK1_dp11_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK1_dp11_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK1_dp11_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP11_HCTRL_BANK1_dp11_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK1_dp11_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_BLOCKCTRL3_BANK1_dp11_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp11_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP11_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK1_dp11_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP11_LANECTRL_BANK1_dp11_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_test_fail_int : 1;
        unsigned char dp12_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp12_cfg_error0_int : 1;
        unsigned char dp12_cfg_error1_int : 1;
        unsigned char dp12_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP12_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP12_INTSTAT_dp12_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_test_fail_int_mask : 1;
        unsigned char dp12_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp12_cfg_error0_int_mask : 1;
        unsigned char dp12_cfg_error1_int_mask : 1;
        unsigned char dp12_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP12_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP12_INTMASK_dp12_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_portflowmode : 2;
        unsigned char dp12_portdatamode : 2;
        unsigned char dp12_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP12_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_PORTCTRL_dp12_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP12_PORTCTRL_dp12_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP12_PORTCTRL_dp12_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP12_PORTCTRL_dp12_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP12_PORTCTRL_dp12_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP12_PORTCTRL_dp12_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP12_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL1_dp12_wordlength_START (0)
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL1_dp12_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_n_finished_channel1 : 1;
        unsigned char dp12_n_finished_channel2 : 1;
        unsigned char dp12_n_finished_channel3 : 1;
        unsigned char dp12_n_finished_channel4 : 1;
        unsigned char dp12_n_finished_channel5 : 1;
        unsigned char dp12_n_finished_channel6 : 1;
        unsigned char dp12_n_finished_channel7 : 1;
        unsigned char dp12_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP12_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP12_PREPARESTATUS_dp12_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_prepare_channel1 : 1;
        unsigned char dp12_prepare_channel2 : 1;
        unsigned char dp12_prepare_channel3 : 1;
        unsigned char dp12_prepare_channel4 : 1;
        unsigned char dp12_prepare_channel5 : 1;
        unsigned char dp12_prepare_channel6 : 1;
        unsigned char dp12_prepare_channel7 : 1;
        unsigned char dp12_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP12_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP12_PREPARECTRL_dp12_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_enable_channel1_bank0 : 1;
        unsigned char dp12_enable_channel2_bank0 : 1;
        unsigned char dp12_enable_channel3_bank0 : 1;
        unsigned char dp12_enable_channel4_bank0 : 1;
        unsigned char dp12_enable_channel5_bank0 : 1;
        unsigned char dp12_enable_channel6_bank0 : 1;
        unsigned char dp12_enable_channel7_bank0 : 1;
        unsigned char dp12_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK0_dp12_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK0_dp12_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK0_dp12_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK0_dp12_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK0_dp12_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK0_dp12_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK0_dp12_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK0_dp12_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK0_dp12_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK0_dp12_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK0_dp12_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_hstop_bank0 : 4;
        unsigned char dp12_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP12_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK0_dp12_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK0_dp12_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK0_dp12_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK0_dp12_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK0_dp12_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK0_dp12_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP12_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK0_dp12_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK0_dp12_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_enable_channel1_bank1 : 1;
        unsigned char dp12_enable_channel2_bank1 : 1;
        unsigned char dp12_enable_channel3_bank1 : 1;
        unsigned char dp12_enable_channel4_bank1 : 1;
        unsigned char dp12_enable_channel5_bank1 : 1;
        unsigned char dp12_enable_channel6_bank1 : 1;
        unsigned char dp12_enable_channel7_bank1 : 1;
        unsigned char dp12_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP12_CHANNELEN_BANK1_dp12_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK1_dp12_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL2_BANK1_dp12_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK1_dp12_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL1_BANK1_dp12_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK1_dp12_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_SAMPLECTRL2_BANK1_dp12_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK1_dp12_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL1_BANK1_dp12_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK1_dp12_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_OFFSETCTRL2_BANK1_dp12_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_hstop_bank1 : 4;
        unsigned char dp12_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP12_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK1_dp12_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK1_dp12_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK1_dp12_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP12_HCTRL_BANK1_dp12_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK1_dp12_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_BLOCKCTRL3_BANK1_dp12_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp12_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP12_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK1_dp12_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP12_LANECTRL_BANK1_dp12_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_test_fail_int : 1;
        unsigned char dp13_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp13_cfg_error0_int : 1;
        unsigned char dp13_cfg_error1_int : 1;
        unsigned char dp13_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP13_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP13_INTSTAT_dp13_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_test_fail_int_mask : 1;
        unsigned char dp13_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp13_cfg_error0_int_mask : 1;
        unsigned char dp13_cfg_error1_int_mask : 1;
        unsigned char dp13_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP13_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP13_INTMASK_dp13_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_portflowmode : 2;
        unsigned char dp13_portdatamode : 2;
        unsigned char dp13_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP13_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_PORTCTRL_dp13_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP13_PORTCTRL_dp13_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP13_PORTCTRL_dp13_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP13_PORTCTRL_dp13_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP13_PORTCTRL_dp13_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP13_PORTCTRL_dp13_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP13_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL1_dp13_wordlength_START (0)
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL1_dp13_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_n_finished_channel1 : 1;
        unsigned char dp13_n_finished_channel2 : 1;
        unsigned char dp13_n_finished_channel3 : 1;
        unsigned char dp13_n_finished_channel4 : 1;
        unsigned char dp13_n_finished_channel5 : 1;
        unsigned char dp13_n_finished_channel6 : 1;
        unsigned char dp13_n_finished_channel7 : 1;
        unsigned char dp13_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP13_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP13_PREPARESTATUS_dp13_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_prepare_channel1 : 1;
        unsigned char dp13_prepare_channel2 : 1;
        unsigned char dp13_prepare_channel3 : 1;
        unsigned char dp13_prepare_channel4 : 1;
        unsigned char dp13_prepare_channel5 : 1;
        unsigned char dp13_prepare_channel6 : 1;
        unsigned char dp13_prepare_channel7 : 1;
        unsigned char dp13_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP13_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP13_PREPARECTRL_dp13_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_enable_channel1_bank0 : 1;
        unsigned char dp13_enable_channel2_bank0 : 1;
        unsigned char dp13_enable_channel3_bank0 : 1;
        unsigned char dp13_enable_channel4_bank0 : 1;
        unsigned char dp13_enable_channel5_bank0 : 1;
        unsigned char dp13_enable_channel6_bank0 : 1;
        unsigned char dp13_enable_channel7_bank0 : 1;
        unsigned char dp13_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK0_dp13_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK0_dp13_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK0_dp13_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK0_dp13_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK0_dp13_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK0_dp13_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK0_dp13_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK0_dp13_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK0_dp13_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK0_dp13_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK0_dp13_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_hstop_bank0 : 4;
        unsigned char dp13_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP13_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK0_dp13_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK0_dp13_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK0_dp13_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK0_dp13_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK0_dp13_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK0_dp13_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP13_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK0_dp13_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK0_dp13_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_enable_channel1_bank1 : 1;
        unsigned char dp13_enable_channel2_bank1 : 1;
        unsigned char dp13_enable_channel3_bank1 : 1;
        unsigned char dp13_enable_channel4_bank1 : 1;
        unsigned char dp13_enable_channel5_bank1 : 1;
        unsigned char dp13_enable_channel6_bank1 : 1;
        unsigned char dp13_enable_channel7_bank1 : 1;
        unsigned char dp13_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP13_CHANNELEN_BANK1_dp13_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK1_dp13_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL2_BANK1_dp13_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK1_dp13_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL1_BANK1_dp13_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK1_dp13_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_SAMPLECTRL2_BANK1_dp13_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK1_dp13_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL1_BANK1_dp13_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK1_dp13_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_OFFSETCTRL2_BANK1_dp13_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_hstop_bank1 : 4;
        unsigned char dp13_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP13_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK1_dp13_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK1_dp13_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK1_dp13_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP13_HCTRL_BANK1_dp13_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK1_dp13_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_BLOCKCTRL3_BANK1_dp13_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp13_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP13_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK1_dp13_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP13_LANECTRL_BANK1_dp13_lanecontrol_bank1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_test_fail_int : 1;
        unsigned char dp14_port_ready_int : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp14_cfg_error0_int : 1;
        unsigned char dp14_cfg_error1_int : 1;
        unsigned char dp14_cfg_error2_int : 1;
    } reg;
} SOC_ASP_SoundWire_DP14_INTSTAT_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_test_fail_int_START (0)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_test_fail_int_END (0)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_port_ready_int_START (1)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_port_ready_int_END (1)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_cfg_error0_int_START (5)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_cfg_error0_int_END (5)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_cfg_error1_int_START (6)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_cfg_error1_int_END (6)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_cfg_error2_int_START (7)
#define SOC_ASP_SoundWire_DP14_INTSTAT_dp14_cfg_error2_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_test_fail_int_mask : 1;
        unsigned char dp14_port_ready_int_mask : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
        unsigned char dp14_cfg_error0_int_mask : 1;
        unsigned char dp14_cfg_error1_int_mask : 1;
        unsigned char dp14_cfg_error2_int_mask : 1;
    } reg;
} SOC_ASP_SoundWire_DP14_INTMASK_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_test_fail_int_mask_START (0)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_test_fail_int_mask_END (0)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_port_ready_int_mask_START (1)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_port_ready_int_mask_END (1)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_cfg_error0_int_mask_START (5)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_cfg_error0_int_mask_END (5)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_cfg_error1_int_mask_START (6)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_cfg_error1_int_mask_END (6)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_cfg_error2_int_mask_START (7)
#define SOC_ASP_SoundWire_DP14_INTMASK_dp14_cfg_error2_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_portflowmode : 2;
        unsigned char dp14_portdatamode : 2;
        unsigned char dp14_nextinvertbank : 1;
        unsigned char reserved_0 : 1;
        unsigned char reserved_1 : 2;
    } reg;
} SOC_ASP_SoundWire_DP14_PORTCTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_PORTCTRL_dp14_portflowmode_START (0)
#define SOC_ASP_SoundWire_DP14_PORTCTRL_dp14_portflowmode_END (1)
#define SOC_ASP_SoundWire_DP14_PORTCTRL_dp14_portdatamode_START (2)
#define SOC_ASP_SoundWire_DP14_PORTCTRL_dp14_portdatamode_END (3)
#define SOC_ASP_SoundWire_DP14_PORTCTRL_dp14_nextinvertbank_START (4)
#define SOC_ASP_SoundWire_DP14_PORTCTRL_dp14_nextinvertbank_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_wordlength : 6;
        unsigned char reserved : 2;
    } reg;
} SOC_ASP_SoundWire_DP14_BLOCKCTRL1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL1_dp14_wordlength_START (0)
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL1_dp14_wordlength_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_n_finished_channel1 : 1;
        unsigned char dp14_n_finished_channel2 : 1;
        unsigned char dp14_n_finished_channel3 : 1;
        unsigned char dp14_n_finished_channel4 : 1;
        unsigned char dp14_n_finished_channel5 : 1;
        unsigned char dp14_n_finished_channel6 : 1;
        unsigned char dp14_n_finished_channel7 : 1;
        unsigned char dp14_n_finished_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP14_PREPARESTATUS_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel1_START (0)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel1_END (0)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel2_START (1)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel2_END (1)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel3_START (2)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel3_END (2)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel4_START (3)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel4_END (3)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel5_START (4)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel5_END (4)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel6_START (5)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel6_END (5)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel7_START (6)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel7_END (6)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel8_START (7)
#define SOC_ASP_SoundWire_DP14_PREPARESTATUS_dp14_n_finished_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_prepare_channel1 : 1;
        unsigned char dp14_prepare_channel2 : 1;
        unsigned char dp14_prepare_channel3 : 1;
        unsigned char dp14_prepare_channel4 : 1;
        unsigned char dp14_prepare_channel5 : 1;
        unsigned char dp14_prepare_channel6 : 1;
        unsigned char dp14_prepare_channel7 : 1;
        unsigned char dp14_prepare_channel8 : 1;
    } reg;
} SOC_ASP_SoundWire_DP14_PREPARECTRL_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel1_START (0)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel1_END (0)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel2_START (1)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel2_END (1)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel3_START (2)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel3_END (2)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel4_START (3)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel4_END (3)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel5_START (4)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel5_END (4)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel6_START (5)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel6_END (5)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel7_START (6)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel7_END (6)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel8_START (7)
#define SOC_ASP_SoundWire_DP14_PREPARECTRL_dp14_prepare_channel8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_enable_channel1_bank0 : 1;
        unsigned char dp14_enable_channel2_bank0 : 1;
        unsigned char dp14_enable_channel3_bank0 : 1;
        unsigned char dp14_enable_channel4_bank0 : 1;
        unsigned char dp14_enable_channel5_bank0 : 1;
        unsigned char dp14_enable_channel6_bank0 : 1;
        unsigned char dp14_enable_channel7_bank0 : 1;
        unsigned char dp14_enable_channel8_bank0 : 1;
    } reg;
} SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel1_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel1_bank0_END (0)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel2_bank0_START (1)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel2_bank0_END (1)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel3_bank0_START (2)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel3_bank0_END (2)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel4_bank0_START (3)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel4_bank0_END (3)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel5_bank0_START (4)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel5_bank0_END (4)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel6_bank0_START (5)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel6_bank0_END (5)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel7_bank0_START (6)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel7_bank0_END (6)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel8_bank0_START (7)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK0_dp14_enable_channel8_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_blockgroupcontrol_bank0 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK0_dp14_blockgroupcontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK0_dp14_blockgroupcontrol_bank0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_sampleintervallow_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK0_dp14_sampleintervallow_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK0_dp14_sampleintervallow_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_sampleintervalhigh_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK0_dp14_sampleintervalhigh_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK0_dp14_sampleintervalhigh_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_offset1_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK0_dp14_offset1_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK0_dp14_offset1_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_offset2_bank0 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK0_dp14_offset2_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK0_dp14_offset2_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_hstop_bank0 : 4;
        unsigned char dp14_hstart_bank0 : 4;
    } reg;
} SOC_ASP_SoundWire_DP14_HCTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK0_dp14_hstop_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK0_dp14_hstop_bank0_END (3)
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK0_dp14_hstart_bank0_START (4)
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK0_dp14_hstart_bank0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_blockpackingmode_bank0 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK0_dp14_blockpackingmode_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK0_dp14_blockpackingmode_bank0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_lanecontrol_bank0 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP14_LANECTRL_BANK0_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK0_dp14_lanecontrol_bank0_START (0)
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK0_dp14_lanecontrol_bank0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_enable_channel1_bank1 : 1;
        unsigned char dp14_enable_channel2_bank1 : 1;
        unsigned char dp14_enable_channel3_bank1 : 1;
        unsigned char dp14_enable_channel4_bank1 : 1;
        unsigned char dp14_enable_channel5_bank1 : 1;
        unsigned char dp14_enable_channel6_bank1 : 1;
        unsigned char dp14_enable_channel7_bank1 : 1;
        unsigned char dp14_enable_channel8_bank1 : 1;
    } reg;
} SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel1_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel1_bank1_END (0)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel2_bank1_START (1)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel2_bank1_END (1)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel3_bank1_START (2)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel3_bank1_END (2)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel4_bank1_START (3)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel4_bank1_END (3)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel5_bank1_START (4)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel5_bank1_END (4)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel6_bank1_START (5)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel6_bank1_END (5)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel7_bank1_START (6)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel7_bank1_END (6)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel8_bank1_START (7)
#define SOC_ASP_SoundWire_DP14_CHANNELEN_BANK1_dp14_enable_channel8_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_blockgroupcontrol_bank1 : 2;
        unsigned char reserved : 6;
    } reg;
} SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK1_dp14_blockgroupcontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL2_BANK1_dp14_blockgroupcontrol_bank1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_sampleintervallow_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK1_dp14_sampleintervallow_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL1_BANK1_dp14_sampleintervallow_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_sampleintervalhigh_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK1_dp14_sampleintervalhigh_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_SAMPLECTRL2_BANK1_dp14_sampleintervalhigh_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_offset1_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK1_dp14_offset1_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL1_BANK1_dp14_offset1_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_offset2_bank1 : 8;
    } reg;
} SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK1_dp14_offset2_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_OFFSETCTRL2_BANK1_dp14_offset2_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_hstop_bank1 : 4;
        unsigned char dp14_hstart_bank1 : 4;
    } reg;
} SOC_ASP_SoundWire_DP14_HCTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK1_dp14_hstop_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK1_dp14_hstop_bank1_END (3)
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK1_dp14_hstart_bank1_START (4)
#define SOC_ASP_SoundWire_DP14_HCTRL_BANK1_dp14_hstart_bank1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_blockpackingmode_bank1 : 1;
        unsigned char reserved : 7;
    } reg;
} SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK1_dp14_blockpackingmode_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_BLOCKCTRL3_BANK1_dp14_blockpackingmode_bank1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dp14_lanecontrol_bank1 : 3;
        unsigned char reserved : 5;
    } reg;
} SOC_ASP_SoundWire_DP14_LANECTRL_BANK1_UNION;
#endif
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK1_dp14_lanecontrol_bank1_START (0)
#define SOC_ASP_SoundWire_DP14_LANECTRL_BANK1_dp14_lanecontrol_bank1_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
