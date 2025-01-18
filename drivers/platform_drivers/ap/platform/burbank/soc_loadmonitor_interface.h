#ifndef __SOC_LOADMONITOR_INTERFACE_H__
#define __SOC_LOADMONITOR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_ADDR(base) ((base) + (0x000UL))
#define SOC_LOADMONITOR_MONITOR_CFG_TIME_ADDR(base) ((base) + (0x004UL))
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_ADDR(base) ((base) + (0x008UL))
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_ADDR(base) ((base) + (0x00CUL))
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_ADDR(base) ((base) + (0x010UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD0_ADDR(base) ((base) + (0x014UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD1_ADDR(base) ((base) + (0x018UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD2_ADDR(base) ((base) + (0x01CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD3_ADDR(base) ((base) + (0x020UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD4_ADDR(base) ((base) + (0x024UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD5_ADDR(base) ((base) + (0x028UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD6_ADDR(base) ((base) + (0x02CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD7_ADDR(base) ((base) + (0x030UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD8_ADDR(base) ((base) + (0x034UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD9_ADDR(base) ((base) + (0x038UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD10_ADDR(base) ((base) + (0x03CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD11_ADDR(base) ((base) + (0x040UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD12_ADDR(base) ((base) + (0x044UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD13_ADDR(base) ((base) + (0x048UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD14_ADDR(base) ((base) + (0x04CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD15_ADDR(base) ((base) + (0x050UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD16_ADDR(base) ((base) + (0x054UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD17_ADDR(base) ((base) + (0x058UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD18_ADDR(base) ((base) + (0x05CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD19_ADDR(base) ((base) + (0x060UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD20_ADDR(base) ((base) + (0x064UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD21_ADDR(base) ((base) + (0x068UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD22_ADDR(base) ((base) + (0x06CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD23_ADDR(base) ((base) + (0x070UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD24_ADDR(base) ((base) + (0x074UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD25_ADDR(base) ((base) + (0x078UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD26_ADDR(base) ((base) + (0x07CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD27_ADDR(base) ((base) + (0x080UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD28_ADDR(base) ((base) + (0x084UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD29_ADDR(base) ((base) + (0x088UL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD30_ADDR(base) ((base) + (0x08CUL))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD31_ADDR(base) ((base) + (0x090UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD0_ADDR(base) ((base) + (0x094UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD1_ADDR(base) ((base) + (0x098UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD2_ADDR(base) ((base) + (0x09CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD3_ADDR(base) ((base) + (0x0A0UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD4_ADDR(base) ((base) + (0x0A4UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD5_ADDR(base) ((base) + (0x0A8UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD6_ADDR(base) ((base) + (0x0ACUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD7_ADDR(base) ((base) + (0x0B0UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD8_ADDR(base) ((base) + (0x0B4UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD9_ADDR(base) ((base) + (0x0B8UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD10_ADDR(base) ((base) + (0x0BCUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD11_ADDR(base) ((base) + (0x0C0UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD12_ADDR(base) ((base) + (0x0C4UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD13_ADDR(base) ((base) + (0x0C8UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD14_ADDR(base) ((base) + (0x0CCUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD15_ADDR(base) ((base) + (0x0D0UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD16_ADDR(base) ((base) + (0x0D4UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD17_ADDR(base) ((base) + (0x0D8UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD18_ADDR(base) ((base) + (0x0DCUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD19_ADDR(base) ((base) + (0x0E0UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD20_ADDR(base) ((base) + (0x0E4UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD21_ADDR(base) ((base) + (0x0E8UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD22_ADDR(base) ((base) + (0x0ECUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD23_ADDR(base) ((base) + (0x0F0UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD24_ADDR(base) ((base) + (0x0F4UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD25_ADDR(base) ((base) + (0x0F8UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD26_ADDR(base) ((base) + (0x0FCUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD27_ADDR(base) ((base) + (0x100UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD28_ADDR(base) ((base) + (0x104UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD29_ADDR(base) ((base) + (0x108UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD30_ADDR(base) ((base) + (0x10CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD31_ADDR(base) ((base) + (0x110UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD0_ADDR(base) ((base) + (0x114UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD1_ADDR(base) ((base) + (0x118UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD2_ADDR(base) ((base) + (0x11CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD3_ADDR(base) ((base) + (0x120UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD4_ADDR(base) ((base) + (0x124UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD5_ADDR(base) ((base) + (0x128UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD6_ADDR(base) ((base) + (0x12CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD7_ADDR(base) ((base) + (0x130UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD8_ADDR(base) ((base) + (0x134UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD9_ADDR(base) ((base) + (0x138UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD10_ADDR(base) ((base) + (0x13CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD11_ADDR(base) ((base) + (0x140UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD12_ADDR(base) ((base) + (0x144UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD13_ADDR(base) ((base) + (0x148UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD14_ADDR(base) ((base) + (0x14CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD15_ADDR(base) ((base) + (0x150UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD16_ADDR(base) ((base) + (0x154UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD17_ADDR(base) ((base) + (0x158UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD18_ADDR(base) ((base) + (0x15CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD19_ADDR(base) ((base) + (0x160UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD20_ADDR(base) ((base) + (0x164UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD21_ADDR(base) ((base) + (0x168UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD22_ADDR(base) ((base) + (0x16CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD23_ADDR(base) ((base) + (0x170UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD24_ADDR(base) ((base) + (0x174UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD25_ADDR(base) ((base) + (0x178UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD26_ADDR(base) ((base) + (0x17CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD27_ADDR(base) ((base) + (0x180UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD28_ADDR(base) ((base) + (0x184UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD29_ADDR(base) ((base) + (0x188UL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD30_ADDR(base) ((base) + (0x18CUL))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD31_ADDR(base) ((base) + (0x190UL))
#define SOC_LOADMONITOR_MONITOR_SIGNAL_INV_ADDR(base) ((base) + (0x194UL))
#define SOC_LOADMONITOR_SOFT_SAMPLE_PULSE_ADDR(base) ((base) + (0x198UL))
#else
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_ADDR(base) ((base) + (0x000))
#define SOC_LOADMONITOR_MONITOR_CFG_TIME_ADDR(base) ((base) + (0x004))
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_ADDR(base) ((base) + (0x008))
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_ADDR(base) ((base) + (0x00C))
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_ADDR(base) ((base) + (0x010))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD0_ADDR(base) ((base) + (0x014))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD1_ADDR(base) ((base) + (0x018))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD2_ADDR(base) ((base) + (0x01C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD3_ADDR(base) ((base) + (0x020))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD4_ADDR(base) ((base) + (0x024))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD5_ADDR(base) ((base) + (0x028))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD6_ADDR(base) ((base) + (0x02C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD7_ADDR(base) ((base) + (0x030))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD8_ADDR(base) ((base) + (0x034))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD9_ADDR(base) ((base) + (0x038))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD10_ADDR(base) ((base) + (0x03C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD11_ADDR(base) ((base) + (0x040))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD12_ADDR(base) ((base) + (0x044))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD13_ADDR(base) ((base) + (0x048))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD14_ADDR(base) ((base) + (0x04C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD15_ADDR(base) ((base) + (0x050))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD16_ADDR(base) ((base) + (0x054))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD17_ADDR(base) ((base) + (0x058))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD18_ADDR(base) ((base) + (0x05C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD19_ADDR(base) ((base) + (0x060))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD20_ADDR(base) ((base) + (0x064))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD21_ADDR(base) ((base) + (0x068))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD22_ADDR(base) ((base) + (0x06C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD23_ADDR(base) ((base) + (0x070))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD24_ADDR(base) ((base) + (0x074))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD25_ADDR(base) ((base) + (0x078))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD26_ADDR(base) ((base) + (0x07C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD27_ADDR(base) ((base) + (0x080))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD28_ADDR(base) ((base) + (0x084))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD29_ADDR(base) ((base) + (0x088))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD30_ADDR(base) ((base) + (0x08C))
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD31_ADDR(base) ((base) + (0x090))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD0_ADDR(base) ((base) + (0x094))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD1_ADDR(base) ((base) + (0x098))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD2_ADDR(base) ((base) + (0x09C))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD3_ADDR(base) ((base) + (0x0A0))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD4_ADDR(base) ((base) + (0x0A4))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD5_ADDR(base) ((base) + (0x0A8))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD6_ADDR(base) ((base) + (0x0AC))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD7_ADDR(base) ((base) + (0x0B0))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD8_ADDR(base) ((base) + (0x0B4))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD9_ADDR(base) ((base) + (0x0B8))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD10_ADDR(base) ((base) + (0x0BC))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD11_ADDR(base) ((base) + (0x0C0))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD12_ADDR(base) ((base) + (0x0C4))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD13_ADDR(base) ((base) + (0x0C8))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD14_ADDR(base) ((base) + (0x0CC))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD15_ADDR(base) ((base) + (0x0D0))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD16_ADDR(base) ((base) + (0x0D4))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD17_ADDR(base) ((base) + (0x0D8))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD18_ADDR(base) ((base) + (0x0DC))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD19_ADDR(base) ((base) + (0x0E0))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD20_ADDR(base) ((base) + (0x0E4))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD21_ADDR(base) ((base) + (0x0E8))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD22_ADDR(base) ((base) + (0x0EC))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD23_ADDR(base) ((base) + (0x0F0))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD24_ADDR(base) ((base) + (0x0F4))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD25_ADDR(base) ((base) + (0x0F8))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD26_ADDR(base) ((base) + (0x0FC))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD27_ADDR(base) ((base) + (0x100))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD28_ADDR(base) ((base) + (0x104))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD29_ADDR(base) ((base) + (0x108))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD30_ADDR(base) ((base) + (0x10C))
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD31_ADDR(base) ((base) + (0x110))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD0_ADDR(base) ((base) + (0x114))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD1_ADDR(base) ((base) + (0x118))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD2_ADDR(base) ((base) + (0x11C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD3_ADDR(base) ((base) + (0x120))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD4_ADDR(base) ((base) + (0x124))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD5_ADDR(base) ((base) + (0x128))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD6_ADDR(base) ((base) + (0x12C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD7_ADDR(base) ((base) + (0x130))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD8_ADDR(base) ((base) + (0x134))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD9_ADDR(base) ((base) + (0x138))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD10_ADDR(base) ((base) + (0x13C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD11_ADDR(base) ((base) + (0x140))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD12_ADDR(base) ((base) + (0x144))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD13_ADDR(base) ((base) + (0x148))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD14_ADDR(base) ((base) + (0x14C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD15_ADDR(base) ((base) + (0x150))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD16_ADDR(base) ((base) + (0x154))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD17_ADDR(base) ((base) + (0x158))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD18_ADDR(base) ((base) + (0x15C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD19_ADDR(base) ((base) + (0x160))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD20_ADDR(base) ((base) + (0x164))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD21_ADDR(base) ((base) + (0x168))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD22_ADDR(base) ((base) + (0x16C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD23_ADDR(base) ((base) + (0x170))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD24_ADDR(base) ((base) + (0x174))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD25_ADDR(base) ((base) + (0x178))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD26_ADDR(base) ((base) + (0x17C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD27_ADDR(base) ((base) + (0x180))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD28_ADDR(base) ((base) + (0x184))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD29_ADDR(base) ((base) + (0x188))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD30_ADDR(base) ((base) + (0x18C))
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD31_ADDR(base) ((base) + (0x190))
#define SOC_LOADMONITOR_MONITOR_SIGNAL_INV_ADDR(base) ((base) + (0x194))
#define SOC_LOADMONITOR_SOFT_SAMPLE_PULSE_ADDR(base) ((base) + (0x198))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_ctrl_en : 1;
        unsigned int volt_monitor : 4;
        unsigned int sync_cg_off : 1;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_LOADMONITOR_MONITOR_CTRL_EN_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_monitor_ctrl_en_START (0)
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_monitor_ctrl_en_END (0)
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_volt_monitor_START (1)
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_volt_monitor_END (4)
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_sync_cg_off_START (5)
#define SOC_LOADMONITOR_MONITOR_CTRL_EN_sync_cg_off_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cfg_time : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_CFG_TIME_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_CFG_TIME_monitor_cfg_time_START (0)
#define SOC_LOADMONITOR_MONITOR_CFG_TIME_monitor_cfg_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_sensor0_en : 1;
        unsigned int monitor_sensor1_en : 1;
        unsigned int monitor_sensor2_en : 1;
        unsigned int monitor_sensor3_en : 1;
        unsigned int monitor_sensor4_en : 1;
        unsigned int monitor_sensor5_en : 1;
        unsigned int monitor_sensor6_en : 1;
        unsigned int monitor_sensor7_en : 1;
        unsigned int monitor_sensor8_en : 1;
        unsigned int monitor_sensor9_en : 1;
        unsigned int monitor_sensor10_en : 1;
        unsigned int monitor_sensor11_en : 1;
        unsigned int monitor_sensor12_en : 1;
        unsigned int monitor_sensor13_en : 1;
        unsigned int monitor_sensor14_en : 1;
        unsigned int monitor_sensor15_en : 1;
        unsigned int monitor_sensor16_en : 1;
        unsigned int monitor_sensor17_en : 1;
        unsigned int monitor_sensor18_en : 1;
        unsigned int monitor_sensor19_en : 1;
        unsigned int monitor_sensor20_en : 1;
        unsigned int monitor_sensor21_en : 1;
        unsigned int monitor_sensor22_en : 1;
        unsigned int monitor_sensor23_en : 1;
        unsigned int monitor_sensor24_en : 1;
        unsigned int monitor_sensor25_en : 1;
        unsigned int monitor_sensor26_en : 1;
        unsigned int monitor_sensor27_en : 1;
        unsigned int monitor_sensor28_en : 1;
        unsigned int monitor_sensor29_en : 1;
        unsigned int monitor_sensor30_en : 1;
        unsigned int monitor_sensor31_en : 1;
    } reg;
} SOC_LOADMONITOR_MONITOR_SENSOR_EN_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor0_en_START (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor0_en_END (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor1_en_START (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor1_en_END (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor2_en_START (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor2_en_END (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor3_en_START (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor3_en_END (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor4_en_START (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor4_en_END (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor5_en_START (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor5_en_END (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor6_en_START (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor6_en_END (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor7_en_START (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor7_en_END (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor8_en_START (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor8_en_END (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor9_en_START (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor9_en_END (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor10_en_START (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor10_en_END (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor11_en_START (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor11_en_END (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor12_en_START (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor12_en_END (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor13_en_START (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor13_en_END (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor14_en_START (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor14_en_END (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor15_en_START (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor15_en_END (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor16_en_START (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor16_en_END (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor17_en_START (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor17_en_END (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor18_en_START (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor18_en_END (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor19_en_START (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor19_en_END (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor20_en_START (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor20_en_END (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor21_en_START (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor21_en_END (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor22_en_START (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor22_en_END (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor23_en_START (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor23_en_END (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor24_en_START (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor24_en_END (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor25_en_START (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor25_en_END (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor26_en_START (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor26_en_END (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor27_en_START (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor27_en_END (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor28_en_START (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor28_en_END (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor29_en_START (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor29_en_END (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor30_en_START (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor30_en_END (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor31_en_START (31)
#define SOC_LOADMONITOR_MONITOR_SENSOR_EN_monitor_sensor31_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_sensor0_dis : 1;
        unsigned int monitor_sensor1_dis : 1;
        unsigned int monitor_sensor2_dis : 1;
        unsigned int monitor_sensor3_dis : 1;
        unsigned int monitor_sensor4_dis : 1;
        unsigned int monitor_sensor5_dis : 1;
        unsigned int monitor_sensor6_dis : 1;
        unsigned int monitor_sensor7_dis : 1;
        unsigned int monitor_sensor8_dis : 1;
        unsigned int monitor_sensor9_dis : 1;
        unsigned int monitor_sensor10_dis : 1;
        unsigned int monitor_sensor11_dis : 1;
        unsigned int monitor_sensor12_dis : 1;
        unsigned int monitor_sensor13_dis : 1;
        unsigned int monitor_sensor14_dis : 1;
        unsigned int monitor_sensor15_dis : 1;
        unsigned int monitor_sensor16_dis : 1;
        unsigned int monitor_sensor17_dis : 1;
        unsigned int monitor_sensor18_dis : 1;
        unsigned int monitor_sensor19_dis : 1;
        unsigned int monitor_sensor20_dis : 1;
        unsigned int monitor_sensor21_dis : 1;
        unsigned int monitor_sensor22_dis : 1;
        unsigned int monitor_sensor23_dis : 1;
        unsigned int monitor_sensor24_dis : 1;
        unsigned int monitor_sensor25_dis : 1;
        unsigned int monitor_sensor26_dis : 1;
        unsigned int monitor_sensor27_dis : 1;
        unsigned int monitor_sensor28_dis : 1;
        unsigned int monitor_sensor29_dis : 1;
        unsigned int monitor_sensor30_dis : 1;
        unsigned int monitor_sensor31_dis : 1;
    } reg;
} SOC_LOADMONITOR_MONITOR_SENSOR_DIS_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor0_dis_START (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor0_dis_END (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor1_dis_START (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor1_dis_END (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor2_dis_START (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor2_dis_END (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor3_dis_START (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor3_dis_END (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor4_dis_START (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor4_dis_END (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor5_dis_START (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor5_dis_END (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor6_dis_START (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor6_dis_END (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor7_dis_START (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor7_dis_END (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor8_dis_START (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor8_dis_END (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor9_dis_START (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor9_dis_END (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor10_dis_START (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor10_dis_END (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor11_dis_START (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor11_dis_END (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor12_dis_START (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor12_dis_END (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor13_dis_START (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor13_dis_END (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor14_dis_START (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor14_dis_END (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor15_dis_START (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor15_dis_END (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor16_dis_START (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor16_dis_END (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor17_dis_START (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor17_dis_END (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor18_dis_START (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor18_dis_END (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor19_dis_START (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor19_dis_END (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor20_dis_START (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor20_dis_END (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor21_dis_START (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor21_dis_END (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor22_dis_START (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor22_dis_END (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor23_dis_START (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor23_dis_END (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor24_dis_START (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor24_dis_END (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor25_dis_START (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor25_dis_END (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor26_dis_START (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor26_dis_END (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor27_dis_START (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor27_dis_END (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor28_dis_START (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor28_dis_END (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor29_dis_START (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor29_dis_END (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor30_dis_START (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor30_dis_END (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor31_dis_START (31)
#define SOC_LOADMONITOR_MONITOR_SENSOR_DIS_monitor_sensor31_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_sensor0_stat : 1;
        unsigned int monitor_sensor1_stat : 1;
        unsigned int monitor_sensor2_stat : 1;
        unsigned int monitor_sensor3_stat : 1;
        unsigned int monitor_sensor4_stat : 1;
        unsigned int monitor_sensor5_stat : 1;
        unsigned int monitor_sensor6_stat : 1;
        unsigned int monitor_sensor7_stat : 1;
        unsigned int monitor_sensor8_stat : 1;
        unsigned int monitor_sensor9_stat : 1;
        unsigned int monitor_sensor10_stat : 1;
        unsigned int monitor_sensor11_stat : 1;
        unsigned int monitor_sensor12_stat : 1;
        unsigned int monitor_sensor13_stat : 1;
        unsigned int monitor_sensor14_stat : 1;
        unsigned int monitor_sensor15_stat : 1;
        unsigned int monitor_sensor16_stat : 1;
        unsigned int monitor_sensor17_stat : 1;
        unsigned int monitor_sensor18_stat : 1;
        unsigned int monitor_sensor19_stat : 1;
        unsigned int monitor_sensor20_stat : 1;
        unsigned int monitor_sensor21_stat : 1;
        unsigned int monitor_sensor22_stat : 1;
        unsigned int monitor_sensor23_stat : 1;
        unsigned int monitor_sensor24_stat : 1;
        unsigned int monitor_sensor25_stat : 1;
        unsigned int monitor_sensor26_stat : 1;
        unsigned int monitor_sensor27_stat : 1;
        unsigned int monitor_sensor28_stat : 1;
        unsigned int monitor_sensor29_stat : 1;
        unsigned int monitor_sensor30_stat : 1;
        unsigned int monitor_sensor31_stat : 1;
    } reg;
} SOC_LOADMONITOR_MONITOR_SENSOR_STAT_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor0_stat_START (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor0_stat_END (0)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor1_stat_START (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor1_stat_END (1)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor2_stat_START (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor2_stat_END (2)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor3_stat_START (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor3_stat_END (3)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor4_stat_START (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor4_stat_END (4)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor5_stat_START (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor5_stat_END (5)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor6_stat_START (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor6_stat_END (6)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor7_stat_START (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor7_stat_END (7)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor8_stat_START (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor8_stat_END (8)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor9_stat_START (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor9_stat_END (9)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor10_stat_START (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor10_stat_END (10)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor11_stat_START (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor11_stat_END (11)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor12_stat_START (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor12_stat_END (12)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor13_stat_START (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor13_stat_END (13)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor14_stat_START (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor14_stat_END (14)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor15_stat_START (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor15_stat_END (15)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor16_stat_START (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor16_stat_END (16)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor17_stat_START (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor17_stat_END (17)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor18_stat_START (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor18_stat_END (18)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor19_stat_START (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor19_stat_END (19)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor20_stat_START (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor20_stat_END (20)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor21_stat_START (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor21_stat_END (21)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor22_stat_START (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor22_stat_END (22)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor23_stat_START (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor23_stat_END (23)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor24_stat_START (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor24_stat_END (24)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor25_stat_START (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor25_stat_END (25)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor26_stat_START (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor26_stat_END (26)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor27_stat_START (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor27_stat_END (27)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor28_stat_START (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor28_stat_END (28)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor29_stat_START (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor29_stat_END (29)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor30_stat_START (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor30_stat_END (30)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor31_stat_START (31)
#define SOC_LOADMONITOR_MONITOR_SENSOR_STAT_monitor_sensor31_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load0 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD0_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD0_monitor_cnt_idle_nor_load0_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD0_monitor_cnt_idle_nor_load0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load1 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD1_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD1_monitor_cnt_idle_nor_load1_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD1_monitor_cnt_idle_nor_load1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load2 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD2_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD2_monitor_cnt_idle_nor_load2_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD2_monitor_cnt_idle_nor_load2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load3 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD3_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD3_monitor_cnt_idle_nor_load3_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD3_monitor_cnt_idle_nor_load3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load4 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD4_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD4_monitor_cnt_idle_nor_load4_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD4_monitor_cnt_idle_nor_load4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load5 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD5_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD5_monitor_cnt_idle_nor_load5_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD5_monitor_cnt_idle_nor_load5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load6 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD6_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD6_monitor_cnt_idle_nor_load6_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD6_monitor_cnt_idle_nor_load6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load7 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD7_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD7_monitor_cnt_idle_nor_load7_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD7_monitor_cnt_idle_nor_load7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load8 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD8_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD8_monitor_cnt_idle_nor_load8_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD8_monitor_cnt_idle_nor_load8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load9 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD9_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD9_monitor_cnt_idle_nor_load9_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD9_monitor_cnt_idle_nor_load9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load10 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD10_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD10_monitor_cnt_idle_nor_load10_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD10_monitor_cnt_idle_nor_load10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load11 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD11_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD11_monitor_cnt_idle_nor_load11_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD11_monitor_cnt_idle_nor_load11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load12 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD12_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD12_monitor_cnt_idle_nor_load12_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD12_monitor_cnt_idle_nor_load12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load13 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD13_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD13_monitor_cnt_idle_nor_load13_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD13_monitor_cnt_idle_nor_load13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load14 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD14_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD14_monitor_cnt_idle_nor_load14_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD14_monitor_cnt_idle_nor_load14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load15 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD15_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD15_monitor_cnt_idle_nor_load15_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD15_monitor_cnt_idle_nor_load15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load16 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD16_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD16_monitor_cnt_idle_nor_load16_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD16_monitor_cnt_idle_nor_load16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load17 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD17_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD17_monitor_cnt_idle_nor_load17_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD17_monitor_cnt_idle_nor_load17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load18 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD18_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD18_monitor_cnt_idle_nor_load18_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD18_monitor_cnt_idle_nor_load18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load19 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD19_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD19_monitor_cnt_idle_nor_load19_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD19_monitor_cnt_idle_nor_load19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load20 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD20_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD20_monitor_cnt_idle_nor_load20_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD20_monitor_cnt_idle_nor_load20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load21 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD21_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD21_monitor_cnt_idle_nor_load21_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD21_monitor_cnt_idle_nor_load21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load22 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD22_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD22_monitor_cnt_idle_nor_load22_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD22_monitor_cnt_idle_nor_load22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load23 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD23_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD23_monitor_cnt_idle_nor_load23_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD23_monitor_cnt_idle_nor_load23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load24 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD24_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD24_monitor_cnt_idle_nor_load24_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD24_monitor_cnt_idle_nor_load24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load25 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD25_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD25_monitor_cnt_idle_nor_load25_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD25_monitor_cnt_idle_nor_load25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load26 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD26_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD26_monitor_cnt_idle_nor_load26_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD26_monitor_cnt_idle_nor_load26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load27 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD27_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD27_monitor_cnt_idle_nor_load27_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD27_monitor_cnt_idle_nor_load27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load28 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD28_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD28_monitor_cnt_idle_nor_load28_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD28_monitor_cnt_idle_nor_load28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load29 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD29_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD29_monitor_cnt_idle_nor_load29_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD29_monitor_cnt_idle_nor_load29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load30 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD30_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD30_monitor_cnt_idle_nor_load30_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD30_monitor_cnt_idle_nor_load30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_idle_nor_load31 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD31_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD31_monitor_cnt_idle_nor_load31_START (0)
#define SOC_LOADMONITOR_MONITOR_IDLE_NOR_LOAD31_monitor_cnt_idle_nor_load31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load0 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD0_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD0_monitor_cnt_busy_nor_load0_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD0_monitor_cnt_busy_nor_load0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load1 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD1_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD1_monitor_cnt_busy_nor_load1_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD1_monitor_cnt_busy_nor_load1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load2 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD2_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD2_monitor_cnt_busy_nor_load2_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD2_monitor_cnt_busy_nor_load2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load3 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD3_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD3_monitor_cnt_busy_nor_load3_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD3_monitor_cnt_busy_nor_load3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load4 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD4_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD4_monitor_cnt_busy_nor_load4_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD4_monitor_cnt_busy_nor_load4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load5 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD5_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD5_monitor_cnt_busy_nor_load5_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD5_monitor_cnt_busy_nor_load5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load6 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD6_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD6_monitor_cnt_busy_nor_load6_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD6_monitor_cnt_busy_nor_load6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load7 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD7_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD7_monitor_cnt_busy_nor_load7_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD7_monitor_cnt_busy_nor_load7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load8 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD8_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD8_monitor_cnt_busy_nor_load8_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD8_monitor_cnt_busy_nor_load8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load9 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD9_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD9_monitor_cnt_busy_nor_load9_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD9_monitor_cnt_busy_nor_load9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load10 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD10_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD10_monitor_cnt_busy_nor_load10_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD10_monitor_cnt_busy_nor_load10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load11 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD11_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD11_monitor_cnt_busy_nor_load11_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD11_monitor_cnt_busy_nor_load11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load12 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD12_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD12_monitor_cnt_busy_nor_load12_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD12_monitor_cnt_busy_nor_load12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load13 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD13_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD13_monitor_cnt_busy_nor_load13_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD13_monitor_cnt_busy_nor_load13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load14 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD14_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD14_monitor_cnt_busy_nor_load14_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD14_monitor_cnt_busy_nor_load14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load15 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD15_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD15_monitor_cnt_busy_nor_load15_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD15_monitor_cnt_busy_nor_load15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load16 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD16_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD16_monitor_cnt_busy_nor_load16_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD16_monitor_cnt_busy_nor_load16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load17 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD17_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD17_monitor_cnt_busy_nor_load17_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD17_monitor_cnt_busy_nor_load17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load18 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD18_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD18_monitor_cnt_busy_nor_load18_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD18_monitor_cnt_busy_nor_load18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load19 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD19_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD19_monitor_cnt_busy_nor_load19_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD19_monitor_cnt_busy_nor_load19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load20 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD20_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD20_monitor_cnt_busy_nor_load20_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD20_monitor_cnt_busy_nor_load20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load21 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD21_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD21_monitor_cnt_busy_nor_load21_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD21_monitor_cnt_busy_nor_load21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load22 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD22_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD22_monitor_cnt_busy_nor_load22_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD22_monitor_cnt_busy_nor_load22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load23 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD23_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD23_monitor_cnt_busy_nor_load23_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD23_monitor_cnt_busy_nor_load23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load24 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD24_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD24_monitor_cnt_busy_nor_load24_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD24_monitor_cnt_busy_nor_load24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load25 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD25_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD25_monitor_cnt_busy_nor_load25_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD25_monitor_cnt_busy_nor_load25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load26 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD26_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD26_monitor_cnt_busy_nor_load26_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD26_monitor_cnt_busy_nor_load26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load27 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD27_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD27_monitor_cnt_busy_nor_load27_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD27_monitor_cnt_busy_nor_load27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load28 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD28_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD28_monitor_cnt_busy_nor_load28_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD28_monitor_cnt_busy_nor_load28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load29 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD29_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD29_monitor_cnt_busy_nor_load29_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD29_monitor_cnt_busy_nor_load29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load30 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD30_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD30_monitor_cnt_busy_nor_load30_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD30_monitor_cnt_busy_nor_load30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_nor_load31 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD31_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD31_monitor_cnt_busy_nor_load31_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_NOR_LOAD31_monitor_cnt_busy_nor_load31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load0 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD0_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD0_monitor_cnt_busy_low_load0_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD0_monitor_cnt_busy_low_load0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load1 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD1_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD1_monitor_cnt_busy_low_load1_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD1_monitor_cnt_busy_low_load1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load2 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD2_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD2_monitor_cnt_busy_low_load2_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD2_monitor_cnt_busy_low_load2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load3 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD3_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD3_monitor_cnt_busy_low_load3_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD3_monitor_cnt_busy_low_load3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load4 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD4_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD4_monitor_cnt_busy_low_load4_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD4_monitor_cnt_busy_low_load4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load5 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD5_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD5_monitor_cnt_busy_low_load5_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD5_monitor_cnt_busy_low_load5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load6 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD6_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD6_monitor_cnt_busy_low_load6_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD6_monitor_cnt_busy_low_load6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load7 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD7_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD7_monitor_cnt_busy_low_load7_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD7_monitor_cnt_busy_low_load7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load8 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD8_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD8_monitor_cnt_busy_low_load8_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD8_monitor_cnt_busy_low_load8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load9 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD9_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD9_monitor_cnt_busy_low_load9_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD9_monitor_cnt_busy_low_load9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load10 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD10_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD10_monitor_cnt_busy_low_load10_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD10_monitor_cnt_busy_low_load10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load11 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD11_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD11_monitor_cnt_busy_low_load11_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD11_monitor_cnt_busy_low_load11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load12 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD12_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD12_monitor_cnt_busy_low_load12_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD12_monitor_cnt_busy_low_load12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load13 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD13_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD13_monitor_cnt_busy_low_load13_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD13_monitor_cnt_busy_low_load13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load14 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD14_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD14_monitor_cnt_busy_low_load14_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD14_monitor_cnt_busy_low_load14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load15 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD15_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD15_monitor_cnt_busy_low_load15_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD15_monitor_cnt_busy_low_load15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load16 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD16_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD16_monitor_cnt_busy_low_load16_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD16_monitor_cnt_busy_low_load16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load17 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD17_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD17_monitor_cnt_busy_low_load17_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD17_monitor_cnt_busy_low_load17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load18 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD18_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD18_monitor_cnt_busy_low_load18_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD18_monitor_cnt_busy_low_load18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load19 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD19_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD19_monitor_cnt_busy_low_load19_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD19_monitor_cnt_busy_low_load19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load20 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD20_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD20_monitor_cnt_busy_low_load20_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD20_monitor_cnt_busy_low_load20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load21 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD21_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD21_monitor_cnt_busy_low_load21_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD21_monitor_cnt_busy_low_load21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load22 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD22_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD22_monitor_cnt_busy_low_load22_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD22_monitor_cnt_busy_low_load22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load23 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD23_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD23_monitor_cnt_busy_low_load23_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD23_monitor_cnt_busy_low_load23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load24 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD24_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD24_monitor_cnt_busy_low_load24_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD24_monitor_cnt_busy_low_load24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load25 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD25_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD25_monitor_cnt_busy_low_load25_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD25_monitor_cnt_busy_low_load25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load26 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD26_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD26_monitor_cnt_busy_low_load26_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD26_monitor_cnt_busy_low_load26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load27 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD27_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD27_monitor_cnt_busy_low_load27_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD27_monitor_cnt_busy_low_load27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load28 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD28_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD28_monitor_cnt_busy_low_load28_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD28_monitor_cnt_busy_low_load28_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load29 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD29_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD29_monitor_cnt_busy_low_load29_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD29_monitor_cnt_busy_low_load29_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load30 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD30_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD30_monitor_cnt_busy_low_load30_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD30_monitor_cnt_busy_low_load30_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_cnt_busy_low_load31 : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD31_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD31_monitor_cnt_busy_low_load31_START (0)
#define SOC_LOADMONITOR_MONITOR_BUSY_LOW_LOAD31_monitor_cnt_busy_low_load31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int signal_inv : 32;
    } reg;
} SOC_LOADMONITOR_MONITOR_SIGNAL_INV_UNION;
#endif
#define SOC_LOADMONITOR_MONITOR_SIGNAL_INV_signal_inv_START (0)
#define SOC_LOADMONITOR_MONITOR_SIGNAL_INV_signal_inv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_sample_pulse : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_LOADMONITOR_SOFT_SAMPLE_PULSE_UNION;
#endif
#define SOC_LOADMONITOR_SOFT_SAMPLE_PULSE_soft_sample_pulse_START (0)
#define SOC_LOADMONITOR_SOFT_SAMPLE_PULSE_soft_sample_pulse_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
