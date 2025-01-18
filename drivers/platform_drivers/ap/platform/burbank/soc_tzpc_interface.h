#ifndef __SOC_TZPC_INTERFACE_H__
#define __SOC_TZPC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TZPC_AO_R0SIZE_ADDR(base) ((base) + (0x000UL))
#define SOC_TZPC_AO_DECPROT0STAT_ADDR(base) ((base) + (0x800UL))
#define SOC_TZPC_AO_DECPROT0SET_ADDR(base) ((base) + (0x804UL))
#define SOC_TZPC_AO_DECPROT0CLR_ADDR(base) ((base) + (0x808UL))
#define SOC_TZPC_AO_DECPROT1STAT_ADDR(base) ((base) + (0x80CUL))
#define SOC_TZPC_AO_DECPROT1SET_ADDR(base) ((base) + (0x810UL))
#define SOC_TZPC_AO_DECPROT1CLR_ADDR(base) ((base) + (0x814UL))
#define SOC_TZPC_AO_DECPROT2STAT_ADDR(base) ((base) + (0x818UL))
#define SOC_TZPC_AO_DECPROT2SET_ADDR(base) ((base) + (0x81CUL))
#define SOC_TZPC_AO_DECPROT2CLR_ADDR(base) ((base) + (0x820UL))
#define SOC_TZPC_AO_DECPROT3STAT_ADDR(base) ((base) + (0x824UL))
#define SOC_TZPC_AO_DECPROT3SET_ADDR(base) ((base) + (0x828UL))
#define SOC_TZPC_AO_DECPROT3CLR_ADDR(base) ((base) + (0x82CUL))
#define SOC_TZPC_AO_DECPROT4STAT_ADDR(base) ((base) + (0x830UL))
#define SOC_TZPC_AO_DECPROT4SET_ADDR(base) ((base) + (0x834UL))
#define SOC_TZPC_AO_DECPROT4CLR_ADDR(base) ((base) + (0x838UL))
#define SOC_TZPC_AO_DECPROT5STAT_ADDR(base) ((base) + (0x83CUL))
#define SOC_TZPC_AO_DECPROT5SET_ADDR(base) ((base) + (0x840UL))
#define SOC_TZPC_AO_DECPROT5CLR_ADDR(base) ((base) + (0x844UL))
#define SOC_TZPC_AO_DECPROT6STAT_ADDR(base) ((base) + (0x848UL))
#define SOC_TZPC_AO_DECPROT6SET_ADDR(base) ((base) + (0x84CUL))
#define SOC_TZPC_AO_DECPROT6CLR_ADDR(base) ((base) + (0x850UL))
#define SOC_TZPC_AO_DECPROT7STAT_ADDR(base) ((base) + (0x854UL))
#define SOC_TZPC_AO_DECPROT7SET_ADDR(base) ((base) + (0x858UL))
#define SOC_TZPC_AO_DECPROT7CLR_ADDR(base) ((base) + (0x85CUL))
#define SOC_TZPC_AO_DECPROT8STAT_ADDR(base) ((base) + (0x860UL))
#define SOC_TZPC_AO_DECPROT8SET_ADDR(base) ((base) + (0x864UL))
#define SOC_TZPC_AO_DECPROT8CLR_ADDR(base) ((base) + (0x868UL))
#define SOC_TZPC_AO_REG0_STAT_ADDR(base) ((base) + (0xA00UL))
#define SOC_TZPC_AO_REG1_STAT_ADDR(base) ((base) + (0xA04UL))
#define SOC_TZPC_AO_LOCK_ADDR(base) ((base) + (0xF00UL))
#else
#define SOC_TZPC_AO_R0SIZE_ADDR(base) ((base) + (0x000))
#define SOC_TZPC_AO_DECPROT0STAT_ADDR(base) ((base) + (0x800))
#define SOC_TZPC_AO_DECPROT0SET_ADDR(base) ((base) + (0x804))
#define SOC_TZPC_AO_DECPROT0CLR_ADDR(base) ((base) + (0x808))
#define SOC_TZPC_AO_DECPROT1STAT_ADDR(base) ((base) + (0x80C))
#define SOC_TZPC_AO_DECPROT1SET_ADDR(base) ((base) + (0x810))
#define SOC_TZPC_AO_DECPROT1CLR_ADDR(base) ((base) + (0x814))
#define SOC_TZPC_AO_DECPROT2STAT_ADDR(base) ((base) + (0x818))
#define SOC_TZPC_AO_DECPROT2SET_ADDR(base) ((base) + (0x81C))
#define SOC_TZPC_AO_DECPROT2CLR_ADDR(base) ((base) + (0x820))
#define SOC_TZPC_AO_DECPROT3STAT_ADDR(base) ((base) + (0x824))
#define SOC_TZPC_AO_DECPROT3SET_ADDR(base) ((base) + (0x828))
#define SOC_TZPC_AO_DECPROT3CLR_ADDR(base) ((base) + (0x82C))
#define SOC_TZPC_AO_DECPROT4STAT_ADDR(base) ((base) + (0x830))
#define SOC_TZPC_AO_DECPROT4SET_ADDR(base) ((base) + (0x834))
#define SOC_TZPC_AO_DECPROT4CLR_ADDR(base) ((base) + (0x838))
#define SOC_TZPC_AO_DECPROT5STAT_ADDR(base) ((base) + (0x83C))
#define SOC_TZPC_AO_DECPROT5SET_ADDR(base) ((base) + (0x840))
#define SOC_TZPC_AO_DECPROT5CLR_ADDR(base) ((base) + (0x844))
#define SOC_TZPC_AO_DECPROT6STAT_ADDR(base) ((base) + (0x848))
#define SOC_TZPC_AO_DECPROT6SET_ADDR(base) ((base) + (0x84C))
#define SOC_TZPC_AO_DECPROT6CLR_ADDR(base) ((base) + (0x850))
#define SOC_TZPC_AO_DECPROT7STAT_ADDR(base) ((base) + (0x854))
#define SOC_TZPC_AO_DECPROT7SET_ADDR(base) ((base) + (0x858))
#define SOC_TZPC_AO_DECPROT7CLR_ADDR(base) ((base) + (0x85C))
#define SOC_TZPC_AO_DECPROT8STAT_ADDR(base) ((base) + (0x860))
#define SOC_TZPC_AO_DECPROT8SET_ADDR(base) ((base) + (0x864))
#define SOC_TZPC_AO_DECPROT8CLR_ADDR(base) ((base) + (0x868))
#define SOC_TZPC_AO_REG0_STAT_ADDR(base) ((base) + (0xA00))
#define SOC_TZPC_AO_REG1_STAT_ADDR(base) ((base) + (0xA04))
#define SOC_TZPC_AO_LOCK_ADDR(base) ((base) + (0xF00))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TZPC_R0SIZE_ADDR(base) ((base) + (0x000UL))
#define SOC_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800UL))
#define SOC_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804UL))
#define SOC_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808UL))
#define SOC_TZPC_DECPROT1STAT_ADDR(base) ((base) + (0x80CUL))
#define SOC_TZPC_DECPROT1SET_ADDR(base) ((base) + (0x810UL))
#define SOC_TZPC_DECPROT1CLR_ADDR(base) ((base) + (0x814UL))
#define SOC_TZPC_DECPROT2STAT_ADDR(base) ((base) + (0x818UL))
#define SOC_TZPC_DECPROT2SET_ADDR(base) ((base) + (0x81CUL))
#define SOC_TZPC_DECPROT2CLR_ADDR(base) ((base) + (0x820UL))
#define SOC_TZPC_DECPROT3STAT_ADDR(base) ((base) + (0x824UL))
#define SOC_TZPC_DECPROT3SET_ADDR(base) ((base) + (0x828UL))
#define SOC_TZPC_DECPROT3CLR_ADDR(base) ((base) + (0x82CUL))
#define SOC_TZPC_DECPROT4STAT_ADDR(base) ((base) + (0x830UL))
#define SOC_TZPC_DECPROT4SET_ADDR(base) ((base) + (0x834UL))
#define SOC_TZPC_DECPROT4CLR_ADDR(base) ((base) + (0x838UL))
#define SOC_TZPC_DECPROT5STAT_ADDR(base) ((base) + (0x83CUL))
#define SOC_TZPC_DECPROT5SET_ADDR(base) ((base) + (0x840UL))
#define SOC_TZPC_DECPROT5CLR_ADDR(base) ((base) + (0x844UL))
#define SOC_TZPC_DECPROT6STAT_ADDR(base) ((base) + (0x848UL))
#define SOC_TZPC_DECPROT6SET_ADDR(base) ((base) + (0x84CUL))
#define SOC_TZPC_DECPROT6CLR_ADDR(base) ((base) + (0x850UL))
#define SOC_TZPC_DECPROT7STAT_ADDR(base) ((base) + (0x854UL))
#define SOC_TZPC_DECPROT7SET_ADDR(base) ((base) + (0x858UL))
#define SOC_TZPC_DECPROT7CLR_ADDR(base) ((base) + (0x85CUL))
#define SOC_TZPC_DECPROT8STAT_ADDR(base) ((base) + (0x860UL))
#define SOC_TZPC_DECPROT8SET_ADDR(base) ((base) + (0x864UL))
#define SOC_TZPC_DECPROT8CLR_ADDR(base) ((base) + (0x868UL))
#define SOC_TZPC_REG0_STAT_ADDR(base) ((base) + (0xA00UL))
#define SOC_TZPC_REG1_STAT_ADDR(base) ((base) + (0xA04UL))
#define SOC_TZPC_PERI_LOCK_ADDR(base) ((base) + (0xF00UL))
#else
#define SOC_TZPC_R0SIZE_ADDR(base) ((base) + (0x000))
#define SOC_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800))
#define SOC_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804))
#define SOC_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808))
#define SOC_TZPC_DECPROT1STAT_ADDR(base) ((base) + (0x80C))
#define SOC_TZPC_DECPROT1SET_ADDR(base) ((base) + (0x810))
#define SOC_TZPC_DECPROT1CLR_ADDR(base) ((base) + (0x814))
#define SOC_TZPC_DECPROT2STAT_ADDR(base) ((base) + (0x818))
#define SOC_TZPC_DECPROT2SET_ADDR(base) ((base) + (0x81C))
#define SOC_TZPC_DECPROT2CLR_ADDR(base) ((base) + (0x820))
#define SOC_TZPC_DECPROT3STAT_ADDR(base) ((base) + (0x824))
#define SOC_TZPC_DECPROT3SET_ADDR(base) ((base) + (0x828))
#define SOC_TZPC_DECPROT3CLR_ADDR(base) ((base) + (0x82C))
#define SOC_TZPC_DECPROT4STAT_ADDR(base) ((base) + (0x830))
#define SOC_TZPC_DECPROT4SET_ADDR(base) ((base) + (0x834))
#define SOC_TZPC_DECPROT4CLR_ADDR(base) ((base) + (0x838))
#define SOC_TZPC_DECPROT5STAT_ADDR(base) ((base) + (0x83C))
#define SOC_TZPC_DECPROT5SET_ADDR(base) ((base) + (0x840))
#define SOC_TZPC_DECPROT5CLR_ADDR(base) ((base) + (0x844))
#define SOC_TZPC_DECPROT6STAT_ADDR(base) ((base) + (0x848))
#define SOC_TZPC_DECPROT6SET_ADDR(base) ((base) + (0x84C))
#define SOC_TZPC_DECPROT6CLR_ADDR(base) ((base) + (0x850))
#define SOC_TZPC_DECPROT7STAT_ADDR(base) ((base) + (0x854))
#define SOC_TZPC_DECPROT7SET_ADDR(base) ((base) + (0x858))
#define SOC_TZPC_DECPROT7CLR_ADDR(base) ((base) + (0x85C))
#define SOC_TZPC_DECPROT8STAT_ADDR(base) ((base) + (0x860))
#define SOC_TZPC_DECPROT8SET_ADDR(base) ((base) + (0x864))
#define SOC_TZPC_DECPROT8CLR_ADDR(base) ((base) + (0x868))
#define SOC_TZPC_REG0_STAT_ADDR(base) ((base) + (0xA00))
#define SOC_TZPC_REG1_STAT_ADDR(base) ((base) + (0xA04))
#define SOC_TZPC_PERI_LOCK_ADDR(base) ((base) + (0xF00))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_TZPC_AO_R0SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec : 1;
        unsigned int rtc0 : 1;
        unsigned int rtc1 : 1;
        unsigned int sci0 : 1;
        unsigned int sci1 : 1;
        unsigned int syscnt : 1;
        unsigned int sctrl_region0 : 1;
        unsigned int sctrl_region1 : 1;
        unsigned int sctrl_region2 : 1;
        unsigned int sctrl_region3 : 1;
        unsigned int sctrl_region4 : 1;
        unsigned int sctrl_region5 : 1;
        unsigned int gpio22 : 1;
        unsigned int gpio23 : 1;
        unsigned int gpio24 : 1;
        unsigned int gpio25 : 1;
        unsigned int gpio26 : 1;
        unsigned int gpio27 : 1;
        unsigned int reserved_0 : 1;
        unsigned int AO_WDG : 1;
        unsigned int bb_drx : 1;
        unsigned int time0 : 1;
        unsigned int time1 : 1;
        unsigned int time2 : 1;
        unsigned int time3 : 1;
        unsigned int time4 : 1;
        unsigned int time5 : 1;
        unsigned int time6 : 1;
        unsigned int time7 : 1;
        unsigned int time8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT0STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT0STAT_efusec_START (0)
#define SOC_TZPC_AO_DECPROT0STAT_efusec_END (0)
#define SOC_TZPC_AO_DECPROT0STAT_rtc0_START (1)
#define SOC_TZPC_AO_DECPROT0STAT_rtc0_END (1)
#define SOC_TZPC_AO_DECPROT0STAT_rtc1_START (2)
#define SOC_TZPC_AO_DECPROT0STAT_rtc1_END (2)
#define SOC_TZPC_AO_DECPROT0STAT_sci0_START (3)
#define SOC_TZPC_AO_DECPROT0STAT_sci0_END (3)
#define SOC_TZPC_AO_DECPROT0STAT_sci1_START (4)
#define SOC_TZPC_AO_DECPROT0STAT_sci1_END (4)
#define SOC_TZPC_AO_DECPROT0STAT_syscnt_START (5)
#define SOC_TZPC_AO_DECPROT0STAT_syscnt_END (5)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region0_START (6)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region0_END (6)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region1_START (7)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region1_END (7)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region2_START (8)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region2_END (8)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region3_START (9)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region3_END (9)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region4_START (10)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region4_END (10)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region5_START (11)
#define SOC_TZPC_AO_DECPROT0STAT_sctrl_region5_END (11)
#define SOC_TZPC_AO_DECPROT0STAT_gpio22_START (12)
#define SOC_TZPC_AO_DECPROT0STAT_gpio22_END (12)
#define SOC_TZPC_AO_DECPROT0STAT_gpio23_START (13)
#define SOC_TZPC_AO_DECPROT0STAT_gpio23_END (13)
#define SOC_TZPC_AO_DECPROT0STAT_gpio24_START (14)
#define SOC_TZPC_AO_DECPROT0STAT_gpio24_END (14)
#define SOC_TZPC_AO_DECPROT0STAT_gpio25_START (15)
#define SOC_TZPC_AO_DECPROT0STAT_gpio25_END (15)
#define SOC_TZPC_AO_DECPROT0STAT_gpio26_START (16)
#define SOC_TZPC_AO_DECPROT0STAT_gpio26_END (16)
#define SOC_TZPC_AO_DECPROT0STAT_gpio27_START (17)
#define SOC_TZPC_AO_DECPROT0STAT_gpio27_END (17)
#define SOC_TZPC_AO_DECPROT0STAT_AO_WDG_START (19)
#define SOC_TZPC_AO_DECPROT0STAT_AO_WDG_END (19)
#define SOC_TZPC_AO_DECPROT0STAT_bb_drx_START (20)
#define SOC_TZPC_AO_DECPROT0STAT_bb_drx_END (20)
#define SOC_TZPC_AO_DECPROT0STAT_time0_START (21)
#define SOC_TZPC_AO_DECPROT0STAT_time0_END (21)
#define SOC_TZPC_AO_DECPROT0STAT_time1_START (22)
#define SOC_TZPC_AO_DECPROT0STAT_time1_END (22)
#define SOC_TZPC_AO_DECPROT0STAT_time2_START (23)
#define SOC_TZPC_AO_DECPROT0STAT_time2_END (23)
#define SOC_TZPC_AO_DECPROT0STAT_time3_START (24)
#define SOC_TZPC_AO_DECPROT0STAT_time3_END (24)
#define SOC_TZPC_AO_DECPROT0STAT_time4_START (25)
#define SOC_TZPC_AO_DECPROT0STAT_time4_END (25)
#define SOC_TZPC_AO_DECPROT0STAT_time5_START (26)
#define SOC_TZPC_AO_DECPROT0STAT_time5_END (26)
#define SOC_TZPC_AO_DECPROT0STAT_time6_START (27)
#define SOC_TZPC_AO_DECPROT0STAT_time6_END (27)
#define SOC_TZPC_AO_DECPROT0STAT_time7_START (28)
#define SOC_TZPC_AO_DECPROT0STAT_time7_END (28)
#define SOC_TZPC_AO_DECPROT0STAT_time8_START (29)
#define SOC_TZPC_AO_DECPROT0STAT_time8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec : 1;
        unsigned int rtc0 : 1;
        unsigned int rtc1 : 1;
        unsigned int sci0 : 1;
        unsigned int sci1 : 1;
        unsigned int syscnt : 1;
        unsigned int sctrl_region0 : 1;
        unsigned int sctrl_region1 : 1;
        unsigned int sctrl_region2 : 1;
        unsigned int sctrl_region3 : 1;
        unsigned int sctrl_region4 : 1;
        unsigned int sctrl_region5 : 1;
        unsigned int gpio22 : 1;
        unsigned int gpio23 : 1;
        unsigned int gpio24 : 1;
        unsigned int gpio25 : 1;
        unsigned int gpio26 : 1;
        unsigned int gpio27 : 1;
        unsigned int reserved_0 : 1;
        unsigned int AO_WDG : 1;
        unsigned int bb_drx : 1;
        unsigned int time0 : 1;
        unsigned int time1 : 1;
        unsigned int time2 : 1;
        unsigned int time3 : 1;
        unsigned int time4 : 1;
        unsigned int time5 : 1;
        unsigned int time6 : 1;
        unsigned int time7 : 1;
        unsigned int time8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT0SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT0SET_efusec_START (0)
#define SOC_TZPC_AO_DECPROT0SET_efusec_END (0)
#define SOC_TZPC_AO_DECPROT0SET_rtc0_START (1)
#define SOC_TZPC_AO_DECPROT0SET_rtc0_END (1)
#define SOC_TZPC_AO_DECPROT0SET_rtc1_START (2)
#define SOC_TZPC_AO_DECPROT0SET_rtc1_END (2)
#define SOC_TZPC_AO_DECPROT0SET_sci0_START (3)
#define SOC_TZPC_AO_DECPROT0SET_sci0_END (3)
#define SOC_TZPC_AO_DECPROT0SET_sci1_START (4)
#define SOC_TZPC_AO_DECPROT0SET_sci1_END (4)
#define SOC_TZPC_AO_DECPROT0SET_syscnt_START (5)
#define SOC_TZPC_AO_DECPROT0SET_syscnt_END (5)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region0_START (6)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region0_END (6)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region1_START (7)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region1_END (7)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region2_START (8)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region2_END (8)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region3_START (9)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region3_END (9)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region4_START (10)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region4_END (10)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region5_START (11)
#define SOC_TZPC_AO_DECPROT0SET_sctrl_region5_END (11)
#define SOC_TZPC_AO_DECPROT0SET_gpio22_START (12)
#define SOC_TZPC_AO_DECPROT0SET_gpio22_END (12)
#define SOC_TZPC_AO_DECPROT0SET_gpio23_START (13)
#define SOC_TZPC_AO_DECPROT0SET_gpio23_END (13)
#define SOC_TZPC_AO_DECPROT0SET_gpio24_START (14)
#define SOC_TZPC_AO_DECPROT0SET_gpio24_END (14)
#define SOC_TZPC_AO_DECPROT0SET_gpio25_START (15)
#define SOC_TZPC_AO_DECPROT0SET_gpio25_END (15)
#define SOC_TZPC_AO_DECPROT0SET_gpio26_START (16)
#define SOC_TZPC_AO_DECPROT0SET_gpio26_END (16)
#define SOC_TZPC_AO_DECPROT0SET_gpio27_START (17)
#define SOC_TZPC_AO_DECPROT0SET_gpio27_END (17)
#define SOC_TZPC_AO_DECPROT0SET_AO_WDG_START (19)
#define SOC_TZPC_AO_DECPROT0SET_AO_WDG_END (19)
#define SOC_TZPC_AO_DECPROT0SET_bb_drx_START (20)
#define SOC_TZPC_AO_DECPROT0SET_bb_drx_END (20)
#define SOC_TZPC_AO_DECPROT0SET_time0_START (21)
#define SOC_TZPC_AO_DECPROT0SET_time0_END (21)
#define SOC_TZPC_AO_DECPROT0SET_time1_START (22)
#define SOC_TZPC_AO_DECPROT0SET_time1_END (22)
#define SOC_TZPC_AO_DECPROT0SET_time2_START (23)
#define SOC_TZPC_AO_DECPROT0SET_time2_END (23)
#define SOC_TZPC_AO_DECPROT0SET_time3_START (24)
#define SOC_TZPC_AO_DECPROT0SET_time3_END (24)
#define SOC_TZPC_AO_DECPROT0SET_time4_START (25)
#define SOC_TZPC_AO_DECPROT0SET_time4_END (25)
#define SOC_TZPC_AO_DECPROT0SET_time5_START (26)
#define SOC_TZPC_AO_DECPROT0SET_time5_END (26)
#define SOC_TZPC_AO_DECPROT0SET_time6_START (27)
#define SOC_TZPC_AO_DECPROT0SET_time6_END (27)
#define SOC_TZPC_AO_DECPROT0SET_time7_START (28)
#define SOC_TZPC_AO_DECPROT0SET_time7_END (28)
#define SOC_TZPC_AO_DECPROT0SET_time8_START (29)
#define SOC_TZPC_AO_DECPROT0SET_time8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec : 1;
        unsigned int rtc0 : 1;
        unsigned int rtc1 : 1;
        unsigned int sci0 : 1;
        unsigned int sci1 : 1;
        unsigned int syscnt : 1;
        unsigned int sctrl_region0 : 1;
        unsigned int sctrl_region1 : 1;
        unsigned int sctrl_region2 : 1;
        unsigned int sctrl_region3 : 1;
        unsigned int sctrl_region4 : 1;
        unsigned int sctrl_region5 : 1;
        unsigned int gpio22 : 1;
        unsigned int gpio23 : 1;
        unsigned int gpio24 : 1;
        unsigned int gpio25 : 1;
        unsigned int gpio26 : 1;
        unsigned int gpio27 : 1;
        unsigned int reserved_0 : 1;
        unsigned int AO_WDG : 1;
        unsigned int bb_drx : 1;
        unsigned int time0 : 1;
        unsigned int time1 : 1;
        unsigned int time2 : 1;
        unsigned int time3 : 1;
        unsigned int time4 : 1;
        unsigned int time5 : 1;
        unsigned int time6 : 1;
        unsigned int time7 : 1;
        unsigned int time8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT0CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT0CLR_efusec_START (0)
#define SOC_TZPC_AO_DECPROT0CLR_efusec_END (0)
#define SOC_TZPC_AO_DECPROT0CLR_rtc0_START (1)
#define SOC_TZPC_AO_DECPROT0CLR_rtc0_END (1)
#define SOC_TZPC_AO_DECPROT0CLR_rtc1_START (2)
#define SOC_TZPC_AO_DECPROT0CLR_rtc1_END (2)
#define SOC_TZPC_AO_DECPROT0CLR_sci0_START (3)
#define SOC_TZPC_AO_DECPROT0CLR_sci0_END (3)
#define SOC_TZPC_AO_DECPROT0CLR_sci1_START (4)
#define SOC_TZPC_AO_DECPROT0CLR_sci1_END (4)
#define SOC_TZPC_AO_DECPROT0CLR_syscnt_START (5)
#define SOC_TZPC_AO_DECPROT0CLR_syscnt_END (5)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region0_START (6)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region0_END (6)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region1_START (7)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region1_END (7)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region2_START (8)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region2_END (8)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region3_START (9)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region3_END (9)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region4_START (10)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region4_END (10)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region5_START (11)
#define SOC_TZPC_AO_DECPROT0CLR_sctrl_region5_END (11)
#define SOC_TZPC_AO_DECPROT0CLR_gpio22_START (12)
#define SOC_TZPC_AO_DECPROT0CLR_gpio22_END (12)
#define SOC_TZPC_AO_DECPROT0CLR_gpio23_START (13)
#define SOC_TZPC_AO_DECPROT0CLR_gpio23_END (13)
#define SOC_TZPC_AO_DECPROT0CLR_gpio24_START (14)
#define SOC_TZPC_AO_DECPROT0CLR_gpio24_END (14)
#define SOC_TZPC_AO_DECPROT0CLR_gpio25_START (15)
#define SOC_TZPC_AO_DECPROT0CLR_gpio25_END (15)
#define SOC_TZPC_AO_DECPROT0CLR_gpio26_START (16)
#define SOC_TZPC_AO_DECPROT0CLR_gpio26_END (16)
#define SOC_TZPC_AO_DECPROT0CLR_gpio27_START (17)
#define SOC_TZPC_AO_DECPROT0CLR_gpio27_END (17)
#define SOC_TZPC_AO_DECPROT0CLR_AO_WDG_START (19)
#define SOC_TZPC_AO_DECPROT0CLR_AO_WDG_END (19)
#define SOC_TZPC_AO_DECPROT0CLR_bb_drx_START (20)
#define SOC_TZPC_AO_DECPROT0CLR_bb_drx_END (20)
#define SOC_TZPC_AO_DECPROT0CLR_time0_START (21)
#define SOC_TZPC_AO_DECPROT0CLR_time0_END (21)
#define SOC_TZPC_AO_DECPROT0CLR_time1_START (22)
#define SOC_TZPC_AO_DECPROT0CLR_time1_END (22)
#define SOC_TZPC_AO_DECPROT0CLR_time2_START (23)
#define SOC_TZPC_AO_DECPROT0CLR_time2_END (23)
#define SOC_TZPC_AO_DECPROT0CLR_time3_START (24)
#define SOC_TZPC_AO_DECPROT0CLR_time3_END (24)
#define SOC_TZPC_AO_DECPROT0CLR_time4_START (25)
#define SOC_TZPC_AO_DECPROT0CLR_time4_END (25)
#define SOC_TZPC_AO_DECPROT0CLR_time5_START (26)
#define SOC_TZPC_AO_DECPROT0CLR_time5_END (26)
#define SOC_TZPC_AO_DECPROT0CLR_time6_START (27)
#define SOC_TZPC_AO_DECPROT0CLR_time6_END (27)
#define SOC_TZPC_AO_DECPROT0CLR_time7_START (28)
#define SOC_TZPC_AO_DECPROT0CLR_time7_END (28)
#define SOC_TZPC_AO_DECPROT0CLR_time8_START (29)
#define SOC_TZPC_AO_DECPROT0CLR_time8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpio28 : 1;
        unsigned int gpio1_se : 1;
        unsigned int spmi : 1;
        unsigned int ao_ipc_s : 1;
        unsigned int ao_ipc_ns : 1;
        unsigned int ao_loadmonitor : 1;
        unsigned int gpio20 : 1;
        unsigned int gpio21 : 1;
        unsigned int spi3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int SPMI_RTC : 1;
        unsigned int GPIO29 : 1;
        unsigned int GPIO30 : 1;
        unsigned int GPIO31 : 1;
        unsigned int GPIO32 : 1;
        unsigned int GPIO33 : 1;
        unsigned int GPIO34 : 1;
        unsigned int GPIO35 : 1;
        unsigned int GPIO36 : 1;
        unsigned int TIMER13 : 1;
        unsigned int TIMER14 : 1;
        unsigned int TIMER15 : 1;
        unsigned int TIMER16 : 1;
        unsigned int TIMER17 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int AO_IOC_SUB_REGION32 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT1STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT1STAT_gpio28_START (0)
#define SOC_TZPC_AO_DECPROT1STAT_gpio28_END (0)
#define SOC_TZPC_AO_DECPROT1STAT_gpio1_se_START (1)
#define SOC_TZPC_AO_DECPROT1STAT_gpio1_se_END (1)
#define SOC_TZPC_AO_DECPROT1STAT_spmi_START (2)
#define SOC_TZPC_AO_DECPROT1STAT_spmi_END (2)
#define SOC_TZPC_AO_DECPROT1STAT_ao_ipc_s_START (3)
#define SOC_TZPC_AO_DECPROT1STAT_ao_ipc_s_END (3)
#define SOC_TZPC_AO_DECPROT1STAT_ao_ipc_ns_START (4)
#define SOC_TZPC_AO_DECPROT1STAT_ao_ipc_ns_END (4)
#define SOC_TZPC_AO_DECPROT1STAT_ao_loadmonitor_START (5)
#define SOC_TZPC_AO_DECPROT1STAT_ao_loadmonitor_END (5)
#define SOC_TZPC_AO_DECPROT1STAT_gpio20_START (6)
#define SOC_TZPC_AO_DECPROT1STAT_gpio20_END (6)
#define SOC_TZPC_AO_DECPROT1STAT_gpio21_START (7)
#define SOC_TZPC_AO_DECPROT1STAT_gpio21_END (7)
#define SOC_TZPC_AO_DECPROT1STAT_spi3_START (8)
#define SOC_TZPC_AO_DECPROT1STAT_spi3_END (8)
#define SOC_TZPC_AO_DECPROT1STAT_SPMI_RTC_START (10)
#define SOC_TZPC_AO_DECPROT1STAT_SPMI_RTC_END (10)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO29_START (11)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO29_END (11)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO30_START (12)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO30_END (12)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO31_START (13)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO31_END (13)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO32_START (14)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO32_END (14)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO33_START (15)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO33_END (15)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO34_START (16)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO34_END (16)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO35_START (17)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO35_END (17)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO36_START (18)
#define SOC_TZPC_AO_DECPROT1STAT_GPIO36_END (18)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER13_START (19)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER13_END (19)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER14_START (20)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER14_END (20)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER15_START (21)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER15_END (21)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER16_START (22)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER16_END (22)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER17_START (23)
#define SOC_TZPC_AO_DECPROT1STAT_TIMER17_END (23)
#define SOC_TZPC_AO_DECPROT1STAT_AO_IOC_SUB_REGION32_START (31)
#define SOC_TZPC_AO_DECPROT1STAT_AO_IOC_SUB_REGION32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpio28 : 1;
        unsigned int gpio1_se : 1;
        unsigned int spmi : 1;
        unsigned int ao_ipc_s : 1;
        unsigned int ao_ipc_ns : 1;
        unsigned int ao_loadmonitor : 1;
        unsigned int gpio20 : 1;
        unsigned int gpio21 : 1;
        unsigned int spi3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int SPMI_RTC : 1;
        unsigned int GPIO29 : 1;
        unsigned int GPIO30 : 1;
        unsigned int GPIO31 : 1;
        unsigned int GPIO32 : 1;
        unsigned int GPIO33 : 1;
        unsigned int GPIO34 : 1;
        unsigned int GPIO35 : 1;
        unsigned int GPIO36 : 1;
        unsigned int TIMER13 : 1;
        unsigned int TIMER14 : 1;
        unsigned int TIMER15 : 1;
        unsigned int TIMER16 : 1;
        unsigned int TIMER17 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int AO_IOC_SUB_REGION32 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT1SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT1SET_gpio28_START (0)
#define SOC_TZPC_AO_DECPROT1SET_gpio28_END (0)
#define SOC_TZPC_AO_DECPROT1SET_gpio1_se_START (1)
#define SOC_TZPC_AO_DECPROT1SET_gpio1_se_END (1)
#define SOC_TZPC_AO_DECPROT1SET_spmi_START (2)
#define SOC_TZPC_AO_DECPROT1SET_spmi_END (2)
#define SOC_TZPC_AO_DECPROT1SET_ao_ipc_s_START (3)
#define SOC_TZPC_AO_DECPROT1SET_ao_ipc_s_END (3)
#define SOC_TZPC_AO_DECPROT1SET_ao_ipc_ns_START (4)
#define SOC_TZPC_AO_DECPROT1SET_ao_ipc_ns_END (4)
#define SOC_TZPC_AO_DECPROT1SET_ao_loadmonitor_START (5)
#define SOC_TZPC_AO_DECPROT1SET_ao_loadmonitor_END (5)
#define SOC_TZPC_AO_DECPROT1SET_gpio20_START (6)
#define SOC_TZPC_AO_DECPROT1SET_gpio20_END (6)
#define SOC_TZPC_AO_DECPROT1SET_gpio21_START (7)
#define SOC_TZPC_AO_DECPROT1SET_gpio21_END (7)
#define SOC_TZPC_AO_DECPROT1SET_spi3_START (8)
#define SOC_TZPC_AO_DECPROT1SET_spi3_END (8)
#define SOC_TZPC_AO_DECPROT1SET_SPMI_RTC_START (10)
#define SOC_TZPC_AO_DECPROT1SET_SPMI_RTC_END (10)
#define SOC_TZPC_AO_DECPROT1SET_GPIO29_START (11)
#define SOC_TZPC_AO_DECPROT1SET_GPIO29_END (11)
#define SOC_TZPC_AO_DECPROT1SET_GPIO30_START (12)
#define SOC_TZPC_AO_DECPROT1SET_GPIO30_END (12)
#define SOC_TZPC_AO_DECPROT1SET_GPIO31_START (13)
#define SOC_TZPC_AO_DECPROT1SET_GPIO31_END (13)
#define SOC_TZPC_AO_DECPROT1SET_GPIO32_START (14)
#define SOC_TZPC_AO_DECPROT1SET_GPIO32_END (14)
#define SOC_TZPC_AO_DECPROT1SET_GPIO33_START (15)
#define SOC_TZPC_AO_DECPROT1SET_GPIO33_END (15)
#define SOC_TZPC_AO_DECPROT1SET_GPIO34_START (16)
#define SOC_TZPC_AO_DECPROT1SET_GPIO34_END (16)
#define SOC_TZPC_AO_DECPROT1SET_GPIO35_START (17)
#define SOC_TZPC_AO_DECPROT1SET_GPIO35_END (17)
#define SOC_TZPC_AO_DECPROT1SET_GPIO36_START (18)
#define SOC_TZPC_AO_DECPROT1SET_GPIO36_END (18)
#define SOC_TZPC_AO_DECPROT1SET_TIMER13_START (19)
#define SOC_TZPC_AO_DECPROT1SET_TIMER13_END (19)
#define SOC_TZPC_AO_DECPROT1SET_TIMER14_START (20)
#define SOC_TZPC_AO_DECPROT1SET_TIMER14_END (20)
#define SOC_TZPC_AO_DECPROT1SET_TIMER15_START (21)
#define SOC_TZPC_AO_DECPROT1SET_TIMER15_END (21)
#define SOC_TZPC_AO_DECPROT1SET_TIMER16_START (22)
#define SOC_TZPC_AO_DECPROT1SET_TIMER16_END (22)
#define SOC_TZPC_AO_DECPROT1SET_TIMER17_START (23)
#define SOC_TZPC_AO_DECPROT1SET_TIMER17_END (23)
#define SOC_TZPC_AO_DECPROT1SET_AO_IOC_SUB_REGION32_START (31)
#define SOC_TZPC_AO_DECPROT1SET_AO_IOC_SUB_REGION32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpio28 : 1;
        unsigned int gpio1_se : 1;
        unsigned int spmi : 1;
        unsigned int ao_ipc_s : 1;
        unsigned int ao_ipc_ns : 1;
        unsigned int ao_loadmonitor : 1;
        unsigned int gpio20 : 1;
        unsigned int gpio21 : 1;
        unsigned int spi3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int SPMI_RTC : 1;
        unsigned int GPIO29 : 1;
        unsigned int GPIO30 : 1;
        unsigned int GPIO31 : 1;
        unsigned int GPIO32 : 1;
        unsigned int GPIO33 : 1;
        unsigned int GPIO34 : 1;
        unsigned int GPIO35 : 1;
        unsigned int GPIO36 : 1;
        unsigned int TIMER13 : 1;
        unsigned int TIMER14 : 1;
        unsigned int TIMER15 : 1;
        unsigned int TIMER16 : 1;
        unsigned int TIMER17 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int AO_IOC_SUB_REGION32 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT1CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT1CLR_gpio28_START (0)
#define SOC_TZPC_AO_DECPROT1CLR_gpio28_END (0)
#define SOC_TZPC_AO_DECPROT1CLR_gpio1_se_START (1)
#define SOC_TZPC_AO_DECPROT1CLR_gpio1_se_END (1)
#define SOC_TZPC_AO_DECPROT1CLR_spmi_START (2)
#define SOC_TZPC_AO_DECPROT1CLR_spmi_END (2)
#define SOC_TZPC_AO_DECPROT1CLR_ao_ipc_s_START (3)
#define SOC_TZPC_AO_DECPROT1CLR_ao_ipc_s_END (3)
#define SOC_TZPC_AO_DECPROT1CLR_ao_ipc_ns_START (4)
#define SOC_TZPC_AO_DECPROT1CLR_ao_ipc_ns_END (4)
#define SOC_TZPC_AO_DECPROT1CLR_ao_loadmonitor_START (5)
#define SOC_TZPC_AO_DECPROT1CLR_ao_loadmonitor_END (5)
#define SOC_TZPC_AO_DECPROT1CLR_gpio20_START (6)
#define SOC_TZPC_AO_DECPROT1CLR_gpio20_END (6)
#define SOC_TZPC_AO_DECPROT1CLR_gpio21_START (7)
#define SOC_TZPC_AO_DECPROT1CLR_gpio21_END (7)
#define SOC_TZPC_AO_DECPROT1CLR_spi3_START (8)
#define SOC_TZPC_AO_DECPROT1CLR_spi3_END (8)
#define SOC_TZPC_AO_DECPROT1CLR_SPMI_RTC_START (10)
#define SOC_TZPC_AO_DECPROT1CLR_SPMI_RTC_END (10)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO29_START (11)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO29_END (11)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO30_START (12)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO30_END (12)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO31_START (13)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO31_END (13)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO32_START (14)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO32_END (14)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO33_START (15)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO33_END (15)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO34_START (16)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO34_END (16)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO35_START (17)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO35_END (17)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO36_START (18)
#define SOC_TZPC_AO_DECPROT1CLR_GPIO36_END (18)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER13_START (19)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER13_END (19)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER14_START (20)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER14_END (20)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER15_START (21)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER15_END (21)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER16_START (22)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER16_END (22)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER17_START (23)
#define SOC_TZPC_AO_DECPROT1CLR_TIMER17_END (23)
#define SOC_TZPC_AO_DECPROT1CLR_AO_IOC_SUB_REGION32_START (31)
#define SOC_TZPC_AO_DECPROT1CLR_AO_IOC_SUB_REGION32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AO_IOC_SUB_REGION0 : 1;
        unsigned int AO_IOC_SUB_REGION1 : 1;
        unsigned int AO_IOC_SUB_REGION2 : 1;
        unsigned int AO_IOC_SUB_REGION3 : 1;
        unsigned int AO_IOC_SUB_REGION4 : 1;
        unsigned int AO_IOC_SUB_REGION5 : 1;
        unsigned int AO_IOC_SUB_REGION6 : 1;
        unsigned int AO_IOC_SUB_REGION7 : 1;
        unsigned int AO_IOC_SUB_REGION8 : 1;
        unsigned int AO_IOC_SUB_REGION9 : 1;
        unsigned int AO_IOC_SUB_REGION10 : 1;
        unsigned int AO_IOC_SUB_REGION11 : 1;
        unsigned int AO_IOC_SUB_REGION12 : 1;
        unsigned int AO_IOC_SUB_REGION13 : 1;
        unsigned int AO_IOC_SUB_REGION14 : 1;
        unsigned int AO_IOC_SUB_REGION15 : 1;
        unsigned int AO_IOC_SUB_REGION16 : 1;
        unsigned int AO_IOC_SUB_REGION17 : 1;
        unsigned int AO_IOC_SUB_REGION18 : 1;
        unsigned int AO_IOC_SUB_REGION19 : 1;
        unsigned int AO_IOC_SUB_REGION20 : 1;
        unsigned int AO_IOC_SUB_REGION21 : 1;
        unsigned int AO_IOC_SUB_REGION22 : 1;
        unsigned int AO_IOC_SUB_REGION23 : 1;
        unsigned int AO_IOC_SUB_REGION24 : 1;
        unsigned int AO_IOC_SUB_REGION25 : 1;
        unsigned int AO_IOC_SUB_REGION26 : 1;
        unsigned int AO_IOC_SUB_REGION27 : 1;
        unsigned int AO_IOC_SUB_REGION28 : 1;
        unsigned int AO_IOC_SUB_REGION29 : 1;
        unsigned int AO_IOC_SUB_REGION30 : 1;
        unsigned int AO_IOC_SUB_REGION31 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT2STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION0_START (0)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION0_END (0)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION1_START (1)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION1_END (1)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION2_START (2)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION2_END (2)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION3_START (3)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION3_END (3)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION4_START (4)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION4_END (4)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION5_START (5)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION5_END (5)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION6_START (6)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION6_END (6)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION7_START (7)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION7_END (7)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION8_START (8)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION8_END (8)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION9_START (9)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION9_END (9)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION10_START (10)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION10_END (10)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION11_START (11)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION11_END (11)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION12_START (12)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION12_END (12)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION13_START (13)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION13_END (13)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION14_START (14)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION14_END (14)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION15_START (15)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION15_END (15)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION16_START (16)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION16_END (16)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION17_START (17)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION17_END (17)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION18_START (18)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION18_END (18)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION19_START (19)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION19_END (19)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION20_START (20)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION20_END (20)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION21_START (21)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION21_END (21)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION22_START (22)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION22_END (22)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION23_START (23)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION23_END (23)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION24_START (24)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION24_END (24)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION25_START (25)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION25_END (25)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION26_START (26)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION26_END (26)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION27_START (27)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION27_END (27)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION28_START (28)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION28_END (28)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION29_START (29)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION29_END (29)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION30_START (30)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION30_END (30)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION31_START (31)
#define SOC_TZPC_AO_DECPROT2STAT_AO_IOC_SUB_REGION31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AO_IOC_SUB_REGION0 : 1;
        unsigned int AO_IOC_SUB_REGION1 : 1;
        unsigned int AO_IOC_SUB_REGION2 : 1;
        unsigned int AO_IOC_SUB_REGION3 : 1;
        unsigned int AO_IOC_SUB_REGION4 : 1;
        unsigned int AO_IOC_SUB_REGION5 : 1;
        unsigned int AO_IOC_SUB_REGION6 : 1;
        unsigned int AO_IOC_SUB_REGION7 : 1;
        unsigned int AO_IOC_SUB_REGION8 : 1;
        unsigned int AO_IOC_SUB_REGION9 : 1;
        unsigned int AO_IOC_SUB_REGION10 : 1;
        unsigned int AO_IOC_SUB_REGION11 : 1;
        unsigned int AO_IOC_SUB_REGION12 : 1;
        unsigned int AO_IOC_SUB_REGION13 : 1;
        unsigned int AO_IOC_SUB_REGION14 : 1;
        unsigned int AO_IOC_SUB_REGION15 : 1;
        unsigned int AO_IOC_SUB_REGION16 : 1;
        unsigned int AO_IOC_SUB_REGION17 : 1;
        unsigned int AO_IOC_SUB_REGION18 : 1;
        unsigned int AO_IOC_SUB_REGION19 : 1;
        unsigned int AO_IOC_SUB_REGION20 : 1;
        unsigned int AO_IOC_SUB_REGION21 : 1;
        unsigned int AO_IOC_SUB_REGION22 : 1;
        unsigned int AO_IOC_SUB_REGION23 : 1;
        unsigned int AO_IOC_SUB_REGION24 : 1;
        unsigned int AO_IOC_SUB_REGION25 : 1;
        unsigned int AO_IOC_SUB_REGION26 : 1;
        unsigned int AO_IOC_SUB_REGION27 : 1;
        unsigned int AO_IOC_SUB_REGION28 : 1;
        unsigned int AO_IOC_SUB_REGION29 : 1;
        unsigned int AO_IOC_SUB_REGION30 : 1;
        unsigned int AO_IOC_SUB_REGION31 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT2SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION0_START (0)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION0_END (0)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION1_START (1)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION1_END (1)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION2_START (2)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION2_END (2)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION3_START (3)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION3_END (3)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION4_START (4)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION4_END (4)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION5_START (5)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION5_END (5)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION6_START (6)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION6_END (6)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION7_START (7)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION7_END (7)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION8_START (8)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION8_END (8)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION9_START (9)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION9_END (9)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION10_START (10)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION10_END (10)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION11_START (11)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION11_END (11)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION12_START (12)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION12_END (12)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION13_START (13)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION13_END (13)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION14_START (14)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION14_END (14)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION15_START (15)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION15_END (15)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION16_START (16)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION16_END (16)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION17_START (17)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION17_END (17)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION18_START (18)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION18_END (18)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION19_START (19)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION19_END (19)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION20_START (20)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION20_END (20)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION21_START (21)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION21_END (21)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION22_START (22)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION22_END (22)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION23_START (23)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION23_END (23)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION24_START (24)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION24_END (24)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION25_START (25)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION25_END (25)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION26_START (26)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION26_END (26)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION27_START (27)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION27_END (27)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION28_START (28)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION28_END (28)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION29_START (29)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION29_END (29)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION30_START (30)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION30_END (30)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION31_START (31)
#define SOC_TZPC_AO_DECPROT2SET_AO_IOC_SUB_REGION31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AO_IOC_SUB_REGION0 : 1;
        unsigned int AO_IOC_SUB_REGION1 : 1;
        unsigned int AO_IOC_SUB_REGION2 : 1;
        unsigned int AO_IOC_SUB_REGION3 : 1;
        unsigned int AO_IOC_SUB_REGION4 : 1;
        unsigned int AO_IOC_SUB_REGION5 : 1;
        unsigned int AO_IOC_SUB_REGION6 : 1;
        unsigned int AO_IOC_SUB_REGION7 : 1;
        unsigned int AO_IOC_SUB_REGION8 : 1;
        unsigned int AO_IOC_SUB_REGION9 : 1;
        unsigned int AO_IOC_SUB_REGION10 : 1;
        unsigned int AO_IOC_SUB_REGION11 : 1;
        unsigned int AO_IOC_SUB_REGION12 : 1;
        unsigned int AO_IOC_SUB_REGION13 : 1;
        unsigned int AO_IOC_SUB_REGION14 : 1;
        unsigned int AO_IOC_SUB_REGION15 : 1;
        unsigned int AO_IOC_SUB_REGION16 : 1;
        unsigned int AO_IOC_SUB_REGION17 : 1;
        unsigned int AO_IOC_SUB_REGION18 : 1;
        unsigned int AO_IOC_SUB_REGION19 : 1;
        unsigned int AO_IOC_SUB_REGION20 : 1;
        unsigned int AO_IOC_SUB_REGION21 : 1;
        unsigned int AO_IOC_SUB_REGION22 : 1;
        unsigned int AO_IOC_SUB_REGION23 : 1;
        unsigned int AO_IOC_SUB_REGION24 : 1;
        unsigned int AO_IOC_SUB_REGION25 : 1;
        unsigned int AO_IOC_SUB_REGION26 : 1;
        unsigned int AO_IOC_SUB_REGION27 : 1;
        unsigned int AO_IOC_SUB_REGION28 : 1;
        unsigned int AO_IOC_SUB_REGION29 : 1;
        unsigned int AO_IOC_SUB_REGION30 : 1;
        unsigned int AO_IOC_SUB_REGION31 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT2CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION0_START (0)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION0_END (0)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION1_START (1)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION1_END (1)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION2_START (2)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION2_END (2)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION3_START (3)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION3_END (3)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION4_START (4)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION4_END (4)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION5_START (5)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION5_END (5)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION6_START (6)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION6_END (6)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION7_START (7)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION7_END (7)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION8_START (8)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION8_END (8)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION9_START (9)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION9_END (9)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION10_START (10)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION10_END (10)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION11_START (11)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION11_END (11)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION12_START (12)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION12_END (12)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION13_START (13)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION13_END (13)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION14_START (14)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION14_END (14)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION15_START (15)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION15_END (15)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION16_START (16)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION16_END (16)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION17_START (17)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION17_END (17)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION18_START (18)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION18_END (18)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION19_START (19)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION19_END (19)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION20_START (20)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION20_END (20)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION21_START (21)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION21_END (21)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION22_START (22)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION22_END (22)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION23_START (23)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION23_END (23)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION24_START (24)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION24_END (24)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION25_START (25)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION25_END (25)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION26_START (26)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION26_END (26)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION27_START (27)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION27_END (27)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION28_START (28)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION28_END (28)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION29_START (29)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION29_END (29)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION30_START (30)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION30_END (30)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION31_START (31)
#define SOC_TZPC_AO_DECPROT2CLR_AO_IOC_SUB_REGION31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_trace_spiden : 1;
        unsigned int noc_trace_dbgen : 1;
        unsigned int TCP_SLAVE : 1;
        unsigned int UFS_SYS_CTRL : 1;
        unsigned int UFS_CFG : 1;
        unsigned int reserved_0 : 1;
        unsigned int AO_IOC_SUB_REGION32 : 1;
        unsigned int AO_IOC_SUB_REGION33 : 1;
        unsigned int AO_IOC_SUB_REGION34 : 1;
        unsigned int AO_IOC_SUB_REGION35 : 1;
        unsigned int AO_IOC_SUB_REGION36 : 1;
        unsigned int AO_IOC_SUB_REGION37 : 1;
        unsigned int AO_IOC_SUB_REGION38 : 1;
        unsigned int AO_IOC_SUB_REGION39 : 1;
        unsigned int AO_IOC_SUB_REGION40 : 1;
        unsigned int AO_IOC_SUB_REGION41 : 1;
        unsigned int AO_IOC_SUB_REGION42 : 1;
        unsigned int AO_IOC_SUB_REGION43 : 1;
        unsigned int AO_IOC_SUB_REGION44 : 1;
        unsigned int AO_IOC_SUB_REGION45 : 1;
        unsigned int AO_IOC_SUB_REGION46 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int AO_IOC_SUB_REGION47 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT3STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT3STAT_noc_trace_spiden_START (0)
#define SOC_TZPC_AO_DECPROT3STAT_noc_trace_spiden_END (0)
#define SOC_TZPC_AO_DECPROT3STAT_noc_trace_dbgen_START (1)
#define SOC_TZPC_AO_DECPROT3STAT_noc_trace_dbgen_END (1)
#define SOC_TZPC_AO_DECPROT3STAT_TCP_SLAVE_START (2)
#define SOC_TZPC_AO_DECPROT3STAT_TCP_SLAVE_END (2)
#define SOC_TZPC_AO_DECPROT3STAT_UFS_SYS_CTRL_START (3)
#define SOC_TZPC_AO_DECPROT3STAT_UFS_SYS_CTRL_END (3)
#define SOC_TZPC_AO_DECPROT3STAT_UFS_CFG_START (4)
#define SOC_TZPC_AO_DECPROT3STAT_UFS_CFG_END (4)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION32_START (6)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION32_END (6)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION33_START (7)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION33_END (7)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION34_START (8)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION34_END (8)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION35_START (9)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION35_END (9)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION36_START (10)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION36_END (10)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION37_START (11)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION37_END (11)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION38_START (12)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION38_END (12)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION39_START (13)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION39_END (13)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION40_START (14)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION40_END (14)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION41_START (15)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION41_END (15)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION42_START (16)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION42_END (16)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION43_START (17)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION43_END (17)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION44_START (18)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION44_END (18)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION45_START (19)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION45_END (19)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION46_START (20)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION46_END (20)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION47_START (23)
#define SOC_TZPC_AO_DECPROT3STAT_AO_IOC_SUB_REGION47_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_trace_spiden : 1;
        unsigned int noc_trace_dbgen : 1;
        unsigned int TCP_SLAVE : 1;
        unsigned int UFS_SYS_CTRL : 1;
        unsigned int UFS_CFG : 1;
        unsigned int reserved_0 : 1;
        unsigned int AO_IOC_SUB_REGION32 : 1;
        unsigned int AO_IOC_SUB_REGION33 : 1;
        unsigned int AO_IOC_SUB_REGION34 : 1;
        unsigned int AO_IOC_SUB_REGION35 : 1;
        unsigned int AO_IOC_SUB_REGION36 : 1;
        unsigned int AO_IOC_SUB_REGION37 : 1;
        unsigned int AO_IOC_SUB_REGION38 : 1;
        unsigned int AO_IOC_SUB_REGION39 : 1;
        unsigned int AO_IOC_SUB_REGION40 : 1;
        unsigned int AO_IOC_SUB_REGION41 : 1;
        unsigned int AO_IOC_SUB_REGION42 : 1;
        unsigned int AO_IOC_SUB_REGION43 : 1;
        unsigned int AO_IOC_SUB_REGION44 : 1;
        unsigned int AO_IOC_SUB_REGION45 : 1;
        unsigned int AO_IOC_SUB_REGION46 : 1;
        unsigned int AO_IOC_SUB_REGION47 : 1;
        unsigned int AO_IOC_SUB_REGION48 : 1;
        unsigned int AO_IOC_SUB_REGION49 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT3SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT3SET_noc_trace_spiden_START (0)
#define SOC_TZPC_AO_DECPROT3SET_noc_trace_spiden_END (0)
#define SOC_TZPC_AO_DECPROT3SET_noc_trace_dbgen_START (1)
#define SOC_TZPC_AO_DECPROT3SET_noc_trace_dbgen_END (1)
#define SOC_TZPC_AO_DECPROT3SET_TCP_SLAVE_START (2)
#define SOC_TZPC_AO_DECPROT3SET_TCP_SLAVE_END (2)
#define SOC_TZPC_AO_DECPROT3SET_UFS_SYS_CTRL_START (3)
#define SOC_TZPC_AO_DECPROT3SET_UFS_SYS_CTRL_END (3)
#define SOC_TZPC_AO_DECPROT3SET_UFS_CFG_START (4)
#define SOC_TZPC_AO_DECPROT3SET_UFS_CFG_END (4)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION32_START (6)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION32_END (6)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION33_START (7)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION33_END (7)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION34_START (8)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION34_END (8)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION35_START (9)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION35_END (9)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION36_START (10)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION36_END (10)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION37_START (11)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION37_END (11)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION38_START (12)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION38_END (12)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION39_START (13)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION39_END (13)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION40_START (14)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION40_END (14)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION41_START (15)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION41_END (15)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION42_START (16)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION42_END (16)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION43_START (17)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION43_END (17)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION44_START (18)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION44_END (18)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION45_START (19)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION45_END (19)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION46_START (20)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION46_END (20)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION47_START (21)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION47_END (21)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION48_START (22)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION48_END (22)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION49_START (23)
#define SOC_TZPC_AO_DECPROT3SET_AO_IOC_SUB_REGION49_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noc_trace_spiden : 1;
        unsigned int noc_trace_dbgen : 1;
        unsigned int TCP_SLAVE : 1;
        unsigned int UFS_SYS_CTRL : 1;
        unsigned int UFS_CFG : 1;
        unsigned int reserved_0 : 1;
        unsigned int AO_IOC_SUB_REGION32 : 1;
        unsigned int AO_IOC_SUB_REGION33 : 1;
        unsigned int AO_IOC_SUB_REGION34 : 1;
        unsigned int AO_IOC_SUB_REGION35 : 1;
        unsigned int AO_IOC_SUB_REGION36 : 1;
        unsigned int AO_IOC_SUB_REGION37 : 1;
        unsigned int AO_IOC_SUB_REGION38 : 1;
        unsigned int AO_IOC_SUB_REGION39 : 1;
        unsigned int AO_IOC_SUB_REGION40 : 1;
        unsigned int AO_IOC_SUB_REGION41 : 1;
        unsigned int AO_IOC_SUB_REGION42 : 1;
        unsigned int AO_IOC_SUB_REGION43 : 1;
        unsigned int AO_IOC_SUB_REGION44 : 1;
        unsigned int AO_IOC_SUB_REGION45 : 1;
        unsigned int AO_IOC_SUB_REGION46 : 1;
        unsigned int AO_IOC_SUB_REGION47 : 1;
        unsigned int AO_IOC_SUB_REGION48 : 1;
        unsigned int AO_IOC_SUB_REGION49 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
    } reg;
} SOC_TZPC_AO_DECPROT3CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT3CLR_noc_trace_spiden_START (0)
#define SOC_TZPC_AO_DECPROT3CLR_noc_trace_spiden_END (0)
#define SOC_TZPC_AO_DECPROT3CLR_noc_trace_dbgen_START (1)
#define SOC_TZPC_AO_DECPROT3CLR_noc_trace_dbgen_END (1)
#define SOC_TZPC_AO_DECPROT3CLR_TCP_SLAVE_START (2)
#define SOC_TZPC_AO_DECPROT3CLR_TCP_SLAVE_END (2)
#define SOC_TZPC_AO_DECPROT3CLR_UFS_SYS_CTRL_START (3)
#define SOC_TZPC_AO_DECPROT3CLR_UFS_SYS_CTRL_END (3)
#define SOC_TZPC_AO_DECPROT3CLR_UFS_CFG_START (4)
#define SOC_TZPC_AO_DECPROT3CLR_UFS_CFG_END (4)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION32_START (6)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION32_END (6)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION33_START (7)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION33_END (7)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION34_START (8)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION34_END (8)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION35_START (9)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION35_END (9)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION36_START (10)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION36_END (10)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION37_START (11)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION37_END (11)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION38_START (12)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION38_END (12)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION39_START (13)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION39_END (13)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION40_START (14)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION40_END (14)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION41_START (15)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION41_END (15)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION42_START (16)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION42_END (16)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION43_START (17)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION43_END (17)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION44_START (18)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION44_END (18)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION45_START (19)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION45_END (19)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION46_START (20)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION46_END (20)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION47_START (21)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION47_END (21)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION48_START (22)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION48_END (22)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION49_START (23)
#define SOC_TZPC_AO_DECPROT3CLR_AO_IOC_SUB_REGION49_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT4STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT4SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT4CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT5STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT5SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT5CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TCP_MASTER : 1;
        unsigned int BB_DRX : 1;
        unsigned int UFS : 1;
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
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
    } reg;
} SOC_TZPC_AO_DECPROT6STAT_UNION;
#endif
#define SOC_TZPC_AO_DECPROT6STAT_TCP_MASTER_START (0)
#define SOC_TZPC_AO_DECPROT6STAT_TCP_MASTER_END (0)
#define SOC_TZPC_AO_DECPROT6STAT_BB_DRX_START (1)
#define SOC_TZPC_AO_DECPROT6STAT_BB_DRX_END (1)
#define SOC_TZPC_AO_DECPROT6STAT_UFS_START (2)
#define SOC_TZPC_AO_DECPROT6STAT_UFS_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TCP_MASTER : 1;
        unsigned int BB_DRX : 1;
        unsigned int UFS : 1;
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
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
    } reg;
} SOC_TZPC_AO_DECPROT6SET_UNION;
#endif
#define SOC_TZPC_AO_DECPROT6SET_TCP_MASTER_START (0)
#define SOC_TZPC_AO_DECPROT6SET_TCP_MASTER_END (0)
#define SOC_TZPC_AO_DECPROT6SET_BB_DRX_START (1)
#define SOC_TZPC_AO_DECPROT6SET_BB_DRX_END (1)
#define SOC_TZPC_AO_DECPROT6SET_UFS_START (2)
#define SOC_TZPC_AO_DECPROT6SET_UFS_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TCP_MASTER : 1;
        unsigned int BB_DRX : 1;
        unsigned int UFS : 1;
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
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
        unsigned int reserved_22: 1;
        unsigned int reserved_23: 1;
        unsigned int reserved_24: 1;
        unsigned int reserved_25: 1;
        unsigned int reserved_26: 1;
        unsigned int reserved_27: 1;
        unsigned int reserved_28: 1;
    } reg;
} SOC_TZPC_AO_DECPROT6CLR_UNION;
#endif
#define SOC_TZPC_AO_DECPROT6CLR_TCP_MASTER_START (0)
#define SOC_TZPC_AO_DECPROT6CLR_TCP_MASTER_END (0)
#define SOC_TZPC_AO_DECPROT6CLR_BB_DRX_START (1)
#define SOC_TZPC_AO_DECPROT6CLR_BB_DRX_END (1)
#define SOC_TZPC_AO_DECPROT6CLR_UFS_START (2)
#define SOC_TZPC_AO_DECPROT6CLR_UFS_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT7STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT7SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT7CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT8STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT8SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_DECPROT8CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_REG0_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_REG1_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_AO_LOCK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_TZPC_R0SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IOC_SUB_REGION0 : 1;
        unsigned int IOC_SUB_REGION1 : 1;
        unsigned int IOC_SUB_REGION2 : 1;
        unsigned int IOC_SUB_REGION3 : 1;
        unsigned int IOC_SUB_REGION4 : 1;
        unsigned int IOC_SUB_REGION5 : 1;
        unsigned int IOC_SUB_REGION6 : 1;
        unsigned int IOC_SUB_REGION7 : 1;
        unsigned int IOC_SUB_REGION8 : 1;
        unsigned int IOC_SUB_REGION9 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int IOC_SUB_REGION15 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT0 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT1 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT2 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT3 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT4 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT5 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT6 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT7 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT8 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT9 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT10 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT11 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT12 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT13 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT14 : 1;
    } reg;
} SOC_TZPC_DECPROT0STAT_UNION;
#endif
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION0_START (0)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION0_END (0)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION1_START (1)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION1_END (1)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION2_START (2)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION2_END (2)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION3_START (3)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION3_END (3)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION4_START (4)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION4_END (4)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION5_START (5)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION5_END (5)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION6_START (6)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION6_END (6)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION7_START (7)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION7_END (7)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION8_START (8)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION8_END (8)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION9_START (9)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION9_END (9)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION15_START (16)
#define SOC_TZPC_DECPROT0STAT_IOC_SUB_REGION15_END (16)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT0_START (17)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT0_END (17)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT1_START (18)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT1_END (18)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT2_START (19)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT2_END (19)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT3_START (20)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT3_END (20)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT4_START (21)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT4_END (21)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT5_START (22)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT5_END (22)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT6_START (23)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT6_END (23)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT7_START (24)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT7_END (24)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT8_START (25)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT8_END (25)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT9_START (26)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT9_END (26)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT10_START (27)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT10_END (27)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT11_START (28)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT11_END (28)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT12_START (29)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT12_END (29)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT13_START (30)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT13_END (30)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT14_START (31)
#define SOC_TZPC_DECPROT0STAT_AXI_MEM_DIV_ADDR_BIT14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IOC_SUB_REGION0 : 1;
        unsigned int IOC_SUB_REGION1 : 1;
        unsigned int IOC_SUB_REGION2 : 1;
        unsigned int IOC_SUB_REGION3 : 1;
        unsigned int IOC_SUB_REGION4 : 1;
        unsigned int IOC_SUB_REGION5 : 1;
        unsigned int IOC_SUB_REGION6 : 1;
        unsigned int IOC_SUB_REGION7 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int IOC_SUB_REGION15 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT0 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT1 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT2 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT3 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT4 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT5 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT6 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT7 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT8 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT9 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT10 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT11 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT12 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT13 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT14 : 1;
    } reg;
} SOC_TZPC_DECPROT0SET_UNION;
#endif
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION0_START (0)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION0_END (0)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION1_START (1)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION1_END (1)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION2_START (2)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION2_END (2)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION3_START (3)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION3_END (3)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION4_START (4)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION4_END (4)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION5_START (5)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION5_END (5)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION6_START (6)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION6_END (6)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION7_START (7)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION7_END (7)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION15_START (16)
#define SOC_TZPC_DECPROT0SET_IOC_SUB_REGION15_END (16)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT0_START (17)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT0_END (17)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT1_START (18)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT1_END (18)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT2_START (19)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT2_END (19)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT3_START (20)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT3_END (20)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT4_START (21)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT4_END (21)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT5_START (22)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT5_END (22)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT6_START (23)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT6_END (23)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT7_START (24)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT7_END (24)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT8_START (25)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT8_END (25)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT9_START (26)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT9_END (26)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT10_START (27)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT10_END (27)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT11_START (28)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT11_END (28)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT12_START (29)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT12_END (29)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT13_START (30)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT13_END (30)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT14_START (31)
#define SOC_TZPC_DECPROT0SET_AXI_MEM_DIV_ADDR_BIT14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IOC_SUB_REGION0 : 1;
        unsigned int IOC_SUB_REGION1 : 1;
        unsigned int IOC_SUB_REGION2 : 1;
        unsigned int IOC_SUB_REGION3 : 1;
        unsigned int IOC_SUB_REGION4 : 1;
        unsigned int IOC_SUB_REGION5 : 1;
        unsigned int IOC_SUB_REGION6 : 1;
        unsigned int IOC_SUB_REGION7 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int IOC_SUB_REGION15 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT0 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT1 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT2 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT3 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT4 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT5 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT6 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT7 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT8 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT9 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT10 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT11 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT12 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT13 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT14 : 1;
    } reg;
} SOC_TZPC_DECPROT0CLR_UNION;
#endif
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION0_START (0)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION0_END (0)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION1_START (1)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION1_END (1)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION2_START (2)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION2_END (2)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION3_START (3)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION3_END (3)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION4_START (4)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION4_END (4)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION5_START (5)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION5_END (5)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION6_START (6)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION6_END (6)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION7_START (7)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION7_END (7)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION15_START (16)
#define SOC_TZPC_DECPROT0CLR_IOC_SUB_REGION15_END (16)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT0_START (17)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT0_END (17)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT1_START (18)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT1_END (18)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT2_START (19)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT2_END (19)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT3_START (20)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT3_END (20)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT4_START (21)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT4_END (21)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT5_START (22)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT5_END (22)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT6_START (23)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT6_END (23)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT7_START (24)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT7_END (24)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT8_START (25)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT8_END (25)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT9_START (26)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT9_END (26)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT10_START (27)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT10_END (27)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT11_START (28)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT11_END (28)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT12_START (29)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT12_END (29)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT13_START (30)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT13_END (30)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT14_START (31)
#define SOC_TZPC_DECPROT0CLR_AXI_MEM_DIV_ADDR_BIT14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AXI_MEM_DIV_ADDR_BIT15 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT16 : 1;
        unsigned int timer9 : 1;
        unsigned int timer10 : 1;
        unsigned int timer11 : 1;
        unsigned int timer12 : 1;
        unsigned int PCTRL_SUB_REGION0 : 1;
        unsigned int PCTRL_SUB_REGION1 : 1;
        unsigned int PCTRL_SUB_REGION2 : 1;
        unsigned int PCTRL_SUB_REGION3 : 1;
        unsigned int PWM : 1;
        unsigned int reserved : 1;
        unsigned int WD0 : 1;
        unsigned int WD1 : 1;
        unsigned int gpio0 : 1;
        unsigned int gpio1 : 1;
        unsigned int gpio2 : 1;
        unsigned int gpio3 : 1;
        unsigned int gpio4 : 1;
        unsigned int gpio5 : 1;
        unsigned int gpio6 : 1;
        unsigned int gpio7 : 1;
        unsigned int gpio8 : 1;
        unsigned int gpio9 : 1;
        unsigned int gpio10 : 1;
        unsigned int gpio11 : 1;
        unsigned int gpio12 : 1;
        unsigned int gpio13 : 1;
        unsigned int gpio14 : 1;
        unsigned int gpio15 : 1;
        unsigned int gpio16 : 1;
        unsigned int gpio17 : 1;
    } reg;
} SOC_TZPC_DECPROT1STAT_UNION;
#endif
#define SOC_TZPC_DECPROT1STAT_AXI_MEM_DIV_ADDR_BIT15_START (0)
#define SOC_TZPC_DECPROT1STAT_AXI_MEM_DIV_ADDR_BIT15_END (0)
#define SOC_TZPC_DECPROT1STAT_AXI_MEM_DIV_ADDR_BIT16_START (1)
#define SOC_TZPC_DECPROT1STAT_AXI_MEM_DIV_ADDR_BIT16_END (1)
#define SOC_TZPC_DECPROT1STAT_timer9_START (2)
#define SOC_TZPC_DECPROT1STAT_timer9_END (2)
#define SOC_TZPC_DECPROT1STAT_timer10_START (3)
#define SOC_TZPC_DECPROT1STAT_timer10_END (3)
#define SOC_TZPC_DECPROT1STAT_timer11_START (4)
#define SOC_TZPC_DECPROT1STAT_timer11_END (4)
#define SOC_TZPC_DECPROT1STAT_timer12_START (5)
#define SOC_TZPC_DECPROT1STAT_timer12_END (5)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION0_START (6)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION0_END (6)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION1_START (7)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION1_END (7)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION2_START (8)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION2_END (8)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION3_START (9)
#define SOC_TZPC_DECPROT1STAT_PCTRL_SUB_REGION3_END (9)
#define SOC_TZPC_DECPROT1STAT_PWM_START (10)
#define SOC_TZPC_DECPROT1STAT_PWM_END (10)
#define SOC_TZPC_DECPROT1STAT_WD0_START (12)
#define SOC_TZPC_DECPROT1STAT_WD0_END (12)
#define SOC_TZPC_DECPROT1STAT_WD1_START (13)
#define SOC_TZPC_DECPROT1STAT_WD1_END (13)
#define SOC_TZPC_DECPROT1STAT_gpio0_START (14)
#define SOC_TZPC_DECPROT1STAT_gpio0_END (14)
#define SOC_TZPC_DECPROT1STAT_gpio1_START (15)
#define SOC_TZPC_DECPROT1STAT_gpio1_END (15)
#define SOC_TZPC_DECPROT1STAT_gpio2_START (16)
#define SOC_TZPC_DECPROT1STAT_gpio2_END (16)
#define SOC_TZPC_DECPROT1STAT_gpio3_START (17)
#define SOC_TZPC_DECPROT1STAT_gpio3_END (17)
#define SOC_TZPC_DECPROT1STAT_gpio4_START (18)
#define SOC_TZPC_DECPROT1STAT_gpio4_END (18)
#define SOC_TZPC_DECPROT1STAT_gpio5_START (19)
#define SOC_TZPC_DECPROT1STAT_gpio5_END (19)
#define SOC_TZPC_DECPROT1STAT_gpio6_START (20)
#define SOC_TZPC_DECPROT1STAT_gpio6_END (20)
#define SOC_TZPC_DECPROT1STAT_gpio7_START (21)
#define SOC_TZPC_DECPROT1STAT_gpio7_END (21)
#define SOC_TZPC_DECPROT1STAT_gpio8_START (22)
#define SOC_TZPC_DECPROT1STAT_gpio8_END (22)
#define SOC_TZPC_DECPROT1STAT_gpio9_START (23)
#define SOC_TZPC_DECPROT1STAT_gpio9_END (23)
#define SOC_TZPC_DECPROT1STAT_gpio10_START (24)
#define SOC_TZPC_DECPROT1STAT_gpio10_END (24)
#define SOC_TZPC_DECPROT1STAT_gpio11_START (25)
#define SOC_TZPC_DECPROT1STAT_gpio11_END (25)
#define SOC_TZPC_DECPROT1STAT_gpio12_START (26)
#define SOC_TZPC_DECPROT1STAT_gpio12_END (26)
#define SOC_TZPC_DECPROT1STAT_gpio13_START (27)
#define SOC_TZPC_DECPROT1STAT_gpio13_END (27)
#define SOC_TZPC_DECPROT1STAT_gpio14_START (28)
#define SOC_TZPC_DECPROT1STAT_gpio14_END (28)
#define SOC_TZPC_DECPROT1STAT_gpio15_START (29)
#define SOC_TZPC_DECPROT1STAT_gpio15_END (29)
#define SOC_TZPC_DECPROT1STAT_gpio16_START (30)
#define SOC_TZPC_DECPROT1STAT_gpio16_END (30)
#define SOC_TZPC_DECPROT1STAT_gpio17_START (31)
#define SOC_TZPC_DECPROT1STAT_gpio17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AXI_MEM_DIV_ADDR_BIT15 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT16 : 1;
        unsigned int timer9 : 1;
        unsigned int timer10 : 1;
        unsigned int timer11 : 1;
        unsigned int timer12 : 1;
        unsigned int PCTRL_SUB_REGION0 : 1;
        unsigned int PCTRL_SUB_REGION1 : 1;
        unsigned int PCTRL_SUB_REGION2 : 1;
        unsigned int PCTRL_SUB_REGION3 : 1;
        unsigned int PWM : 1;
        unsigned int reserved : 1;
        unsigned int WD0 : 1;
        unsigned int WD1 : 1;
        unsigned int gpio0 : 1;
        unsigned int gpio1 : 1;
        unsigned int gpio2 : 1;
        unsigned int gpio3 : 1;
        unsigned int gpio4 : 1;
        unsigned int gpio5 : 1;
        unsigned int gpio6 : 1;
        unsigned int gpio7 : 1;
        unsigned int gpio8 : 1;
        unsigned int gpio9 : 1;
        unsigned int gpio10 : 1;
        unsigned int gpio11 : 1;
        unsigned int gpio12 : 1;
        unsigned int gpio13 : 1;
        unsigned int gpio14 : 1;
        unsigned int gpio15 : 1;
        unsigned int gpio16 : 1;
        unsigned int gpio17 : 1;
    } reg;
} SOC_TZPC_DECPROT1SET_UNION;
#endif
#define SOC_TZPC_DECPROT1SET_AXI_MEM_DIV_ADDR_BIT15_START (0)
#define SOC_TZPC_DECPROT1SET_AXI_MEM_DIV_ADDR_BIT15_END (0)
#define SOC_TZPC_DECPROT1SET_AXI_MEM_DIV_ADDR_BIT16_START (1)
#define SOC_TZPC_DECPROT1SET_AXI_MEM_DIV_ADDR_BIT16_END (1)
#define SOC_TZPC_DECPROT1SET_timer9_START (2)
#define SOC_TZPC_DECPROT1SET_timer9_END (2)
#define SOC_TZPC_DECPROT1SET_timer10_START (3)
#define SOC_TZPC_DECPROT1SET_timer10_END (3)
#define SOC_TZPC_DECPROT1SET_timer11_START (4)
#define SOC_TZPC_DECPROT1SET_timer11_END (4)
#define SOC_TZPC_DECPROT1SET_timer12_START (5)
#define SOC_TZPC_DECPROT1SET_timer12_END (5)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION0_START (6)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION0_END (6)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION1_START (7)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION1_END (7)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION2_START (8)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION2_END (8)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION3_START (9)
#define SOC_TZPC_DECPROT1SET_PCTRL_SUB_REGION3_END (9)
#define SOC_TZPC_DECPROT1SET_PWM_START (10)
#define SOC_TZPC_DECPROT1SET_PWM_END (10)
#define SOC_TZPC_DECPROT1SET_WD0_START (12)
#define SOC_TZPC_DECPROT1SET_WD0_END (12)
#define SOC_TZPC_DECPROT1SET_WD1_START (13)
#define SOC_TZPC_DECPROT1SET_WD1_END (13)
#define SOC_TZPC_DECPROT1SET_gpio0_START (14)
#define SOC_TZPC_DECPROT1SET_gpio0_END (14)
#define SOC_TZPC_DECPROT1SET_gpio1_START (15)
#define SOC_TZPC_DECPROT1SET_gpio1_END (15)
#define SOC_TZPC_DECPROT1SET_gpio2_START (16)
#define SOC_TZPC_DECPROT1SET_gpio2_END (16)
#define SOC_TZPC_DECPROT1SET_gpio3_START (17)
#define SOC_TZPC_DECPROT1SET_gpio3_END (17)
#define SOC_TZPC_DECPROT1SET_gpio4_START (18)
#define SOC_TZPC_DECPROT1SET_gpio4_END (18)
#define SOC_TZPC_DECPROT1SET_gpio5_START (19)
#define SOC_TZPC_DECPROT1SET_gpio5_END (19)
#define SOC_TZPC_DECPROT1SET_gpio6_START (20)
#define SOC_TZPC_DECPROT1SET_gpio6_END (20)
#define SOC_TZPC_DECPROT1SET_gpio7_START (21)
#define SOC_TZPC_DECPROT1SET_gpio7_END (21)
#define SOC_TZPC_DECPROT1SET_gpio8_START (22)
#define SOC_TZPC_DECPROT1SET_gpio8_END (22)
#define SOC_TZPC_DECPROT1SET_gpio9_START (23)
#define SOC_TZPC_DECPROT1SET_gpio9_END (23)
#define SOC_TZPC_DECPROT1SET_gpio10_START (24)
#define SOC_TZPC_DECPROT1SET_gpio10_END (24)
#define SOC_TZPC_DECPROT1SET_gpio11_START (25)
#define SOC_TZPC_DECPROT1SET_gpio11_END (25)
#define SOC_TZPC_DECPROT1SET_gpio12_START (26)
#define SOC_TZPC_DECPROT1SET_gpio12_END (26)
#define SOC_TZPC_DECPROT1SET_gpio13_START (27)
#define SOC_TZPC_DECPROT1SET_gpio13_END (27)
#define SOC_TZPC_DECPROT1SET_gpio14_START (28)
#define SOC_TZPC_DECPROT1SET_gpio14_END (28)
#define SOC_TZPC_DECPROT1SET_gpio15_START (29)
#define SOC_TZPC_DECPROT1SET_gpio15_END (29)
#define SOC_TZPC_DECPROT1SET_gpio16_START (30)
#define SOC_TZPC_DECPROT1SET_gpio16_END (30)
#define SOC_TZPC_DECPROT1SET_gpio17_START (31)
#define SOC_TZPC_DECPROT1SET_gpio17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AXI_MEM_DIV_ADDR_BIT15 : 1;
        unsigned int AXI_MEM_DIV_ADDR_BIT16 : 1;
        unsigned int timer9 : 1;
        unsigned int timer10 : 1;
        unsigned int timer11 : 1;
        unsigned int timer12 : 1;
        unsigned int PCTRL_SUB_REGION0 : 1;
        unsigned int PCTRL_SUB_REGION1 : 1;
        unsigned int PCTRL_SUB_REGION2 : 1;
        unsigned int PCTRL_SUB_REGION3 : 1;
        unsigned int PWM : 1;
        unsigned int reserved : 1;
        unsigned int WD0 : 1;
        unsigned int WD1 : 1;
        unsigned int gpio0 : 1;
        unsigned int gpio1 : 1;
        unsigned int gpio2 : 1;
        unsigned int gpio3 : 1;
        unsigned int gpio4 : 1;
        unsigned int gpio5 : 1;
        unsigned int gpio6 : 1;
        unsigned int gpio7 : 1;
        unsigned int gpio8 : 1;
        unsigned int gpio9 : 1;
        unsigned int gpio10 : 1;
        unsigned int gpio11 : 1;
        unsigned int gpio12 : 1;
        unsigned int gpio13 : 1;
        unsigned int gpio14 : 1;
        unsigned int gpio15 : 1;
        unsigned int gpio16 : 1;
        unsigned int gpio17 : 1;
    } reg;
} SOC_TZPC_DECPROT1CLR_UNION;
#endif
#define SOC_TZPC_DECPROT1CLR_AXI_MEM_DIV_ADDR_BIT15_START (0)
#define SOC_TZPC_DECPROT1CLR_AXI_MEM_DIV_ADDR_BIT15_END (0)
#define SOC_TZPC_DECPROT1CLR_AXI_MEM_DIV_ADDR_BIT16_START (1)
#define SOC_TZPC_DECPROT1CLR_AXI_MEM_DIV_ADDR_BIT16_END (1)
#define SOC_TZPC_DECPROT1CLR_timer9_START (2)
#define SOC_TZPC_DECPROT1CLR_timer9_END (2)
#define SOC_TZPC_DECPROT1CLR_timer10_START (3)
#define SOC_TZPC_DECPROT1CLR_timer10_END (3)
#define SOC_TZPC_DECPROT1CLR_timer11_START (4)
#define SOC_TZPC_DECPROT1CLR_timer11_END (4)
#define SOC_TZPC_DECPROT1CLR_timer12_START (5)
#define SOC_TZPC_DECPROT1CLR_timer12_END (5)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION0_START (6)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION0_END (6)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION1_START (7)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION1_END (7)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION2_START (8)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION2_END (8)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION3_START (9)
#define SOC_TZPC_DECPROT1CLR_PCTRL_SUB_REGION3_END (9)
#define SOC_TZPC_DECPROT1CLR_PWM_START (10)
#define SOC_TZPC_DECPROT1CLR_PWM_END (10)
#define SOC_TZPC_DECPROT1CLR_WD0_START (12)
#define SOC_TZPC_DECPROT1CLR_WD0_END (12)
#define SOC_TZPC_DECPROT1CLR_WD1_START (13)
#define SOC_TZPC_DECPROT1CLR_WD1_END (13)
#define SOC_TZPC_DECPROT1CLR_gpio0_START (14)
#define SOC_TZPC_DECPROT1CLR_gpio0_END (14)
#define SOC_TZPC_DECPROT1CLR_gpio1_START (15)
#define SOC_TZPC_DECPROT1CLR_gpio1_END (15)
#define SOC_TZPC_DECPROT1CLR_gpio2_START (16)
#define SOC_TZPC_DECPROT1CLR_gpio2_END (16)
#define SOC_TZPC_DECPROT1CLR_gpio3_START (17)
#define SOC_TZPC_DECPROT1CLR_gpio3_END (17)
#define SOC_TZPC_DECPROT1CLR_gpio4_START (18)
#define SOC_TZPC_DECPROT1CLR_gpio4_END (18)
#define SOC_TZPC_DECPROT1CLR_gpio5_START (19)
#define SOC_TZPC_DECPROT1CLR_gpio5_END (19)
#define SOC_TZPC_DECPROT1CLR_gpio6_START (20)
#define SOC_TZPC_DECPROT1CLR_gpio6_END (20)
#define SOC_TZPC_DECPROT1CLR_gpio7_START (21)
#define SOC_TZPC_DECPROT1CLR_gpio7_END (21)
#define SOC_TZPC_DECPROT1CLR_gpio8_START (22)
#define SOC_TZPC_DECPROT1CLR_gpio8_END (22)
#define SOC_TZPC_DECPROT1CLR_gpio9_START (23)
#define SOC_TZPC_DECPROT1CLR_gpio9_END (23)
#define SOC_TZPC_DECPROT1CLR_gpio10_START (24)
#define SOC_TZPC_DECPROT1CLR_gpio10_END (24)
#define SOC_TZPC_DECPROT1CLR_gpio11_START (25)
#define SOC_TZPC_DECPROT1CLR_gpio11_END (25)
#define SOC_TZPC_DECPROT1CLR_gpio12_START (26)
#define SOC_TZPC_DECPROT1CLR_gpio12_END (26)
#define SOC_TZPC_DECPROT1CLR_gpio13_START (27)
#define SOC_TZPC_DECPROT1CLR_gpio13_END (27)
#define SOC_TZPC_DECPROT1CLR_gpio14_START (28)
#define SOC_TZPC_DECPROT1CLR_gpio14_END (28)
#define SOC_TZPC_DECPROT1CLR_gpio15_START (29)
#define SOC_TZPC_DECPROT1CLR_gpio15_END (29)
#define SOC_TZPC_DECPROT1CLR_gpio16_START (30)
#define SOC_TZPC_DECPROT1CLR_gpio16_END (30)
#define SOC_TZPC_DECPROT1CLR_gpio17_START (31)
#define SOC_TZPC_DECPROT1CLR_gpio17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CFG2GPUPCR : 1;
        unsigned int ATGC1 : 1;
        unsigned int GPIO18 : 1;
        unsigned int gpio19 : 1;
        unsigned int peri_loadmonitor0 : 1;
        unsigned int CFG2FCM : 1;
        unsigned int gpio0_se : 1;
        unsigned int atgc : 1;
        unsigned int peri_loadmonitor1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int IPC_NSCFG : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int g3d_firewall_slv : 8;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
    } reg;
} SOC_TZPC_DECPROT2STAT_UNION;
#endif
#define SOC_TZPC_DECPROT2STAT_CFG2GPUPCR_START (0)
#define SOC_TZPC_DECPROT2STAT_CFG2GPUPCR_END (0)
#define SOC_TZPC_DECPROT2STAT_ATGC1_START (1)
#define SOC_TZPC_DECPROT2STAT_ATGC1_END (1)
#define SOC_TZPC_DECPROT2STAT_GPIO18_START (2)
#define SOC_TZPC_DECPROT2STAT_GPIO18_END (2)
#define SOC_TZPC_DECPROT2STAT_gpio19_START (3)
#define SOC_TZPC_DECPROT2STAT_gpio19_END (3)
#define SOC_TZPC_DECPROT2STAT_peri_loadmonitor0_START (4)
#define SOC_TZPC_DECPROT2STAT_peri_loadmonitor0_END (4)
#define SOC_TZPC_DECPROT2STAT_CFG2FCM_START (5)
#define SOC_TZPC_DECPROT2STAT_CFG2FCM_END (5)
#define SOC_TZPC_DECPROT2STAT_gpio0_se_START (6)
#define SOC_TZPC_DECPROT2STAT_gpio0_se_END (6)
#define SOC_TZPC_DECPROT2STAT_atgc_START (7)
#define SOC_TZPC_DECPROT2STAT_atgc_END (7)
#define SOC_TZPC_DECPROT2STAT_peri_loadmonitor1_START (8)
#define SOC_TZPC_DECPROT2STAT_peri_loadmonitor1_END (8)
#define SOC_TZPC_DECPROT2STAT_IPC_NSCFG_START (11)
#define SOC_TZPC_DECPROT2STAT_IPC_NSCFG_END (11)
#define SOC_TZPC_DECPROT2STAT_g3d_firewall_slv_START (16)
#define SOC_TZPC_DECPROT2STAT_g3d_firewall_slv_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CFG2GPUPCR : 1;
        unsigned int ATGC1 : 1;
        unsigned int GPIO18 : 1;
        unsigned int gpio19 : 1;
        unsigned int peri_loadmonitor0 : 1;
        unsigned int CFG2FCM : 1;
        unsigned int gpio0_se : 1;
        unsigned int atgc : 1;
        unsigned int peri_loadmonitor1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int IPC_NSCFG : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int g3d_firewall_slv : 8;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
    } reg;
} SOC_TZPC_DECPROT2SET_UNION;
#endif
#define SOC_TZPC_DECPROT2SET_CFG2GPUPCR_START (0)
#define SOC_TZPC_DECPROT2SET_CFG2GPUPCR_END (0)
#define SOC_TZPC_DECPROT2SET_ATGC1_START (1)
#define SOC_TZPC_DECPROT2SET_ATGC1_END (1)
#define SOC_TZPC_DECPROT2SET_GPIO18_START (2)
#define SOC_TZPC_DECPROT2SET_GPIO18_END (2)
#define SOC_TZPC_DECPROT2SET_gpio19_START (3)
#define SOC_TZPC_DECPROT2SET_gpio19_END (3)
#define SOC_TZPC_DECPROT2SET_peri_loadmonitor0_START (4)
#define SOC_TZPC_DECPROT2SET_peri_loadmonitor0_END (4)
#define SOC_TZPC_DECPROT2SET_CFG2FCM_START (5)
#define SOC_TZPC_DECPROT2SET_CFG2FCM_END (5)
#define SOC_TZPC_DECPROT2SET_gpio0_se_START (6)
#define SOC_TZPC_DECPROT2SET_gpio0_se_END (6)
#define SOC_TZPC_DECPROT2SET_atgc_START (7)
#define SOC_TZPC_DECPROT2SET_atgc_END (7)
#define SOC_TZPC_DECPROT2SET_peri_loadmonitor1_START (8)
#define SOC_TZPC_DECPROT2SET_peri_loadmonitor1_END (8)
#define SOC_TZPC_DECPROT2SET_IPC_NSCFG_START (11)
#define SOC_TZPC_DECPROT2SET_IPC_NSCFG_END (11)
#define SOC_TZPC_DECPROT2SET_g3d_firewall_slv_START (16)
#define SOC_TZPC_DECPROT2SET_g3d_firewall_slv_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CFG2GPUPCR : 1;
        unsigned int ATGC1 : 1;
        unsigned int GPIO18 : 1;
        unsigned int gpio19 : 1;
        unsigned int peri_loadmonitor0 : 1;
        unsigned int CFG2FCM : 1;
        unsigned int gpio0_se : 1;
        unsigned int atgc : 1;
        unsigned int peri_loadmonitor1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int IPC_NSCFG : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int g3d_firewall_slv : 8;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
    } reg;
} SOC_TZPC_DECPROT2CLR_UNION;
#endif
#define SOC_TZPC_DECPROT2CLR_CFG2GPUPCR_START (0)
#define SOC_TZPC_DECPROT2CLR_CFG2GPUPCR_END (0)
#define SOC_TZPC_DECPROT2CLR_ATGC1_START (1)
#define SOC_TZPC_DECPROT2CLR_ATGC1_END (1)
#define SOC_TZPC_DECPROT2CLR_GPIO18_START (2)
#define SOC_TZPC_DECPROT2CLR_GPIO18_END (2)
#define SOC_TZPC_DECPROT2CLR_gpio19_START (3)
#define SOC_TZPC_DECPROT2CLR_gpio19_END (3)
#define SOC_TZPC_DECPROT2CLR_peri_loadmonitor0_START (4)
#define SOC_TZPC_DECPROT2CLR_peri_loadmonitor0_END (4)
#define SOC_TZPC_DECPROT2CLR_CFG2FCM_START (5)
#define SOC_TZPC_DECPROT2CLR_CFG2FCM_END (5)
#define SOC_TZPC_DECPROT2CLR_gpio0_se_START (6)
#define SOC_TZPC_DECPROT2CLR_gpio0_se_END (6)
#define SOC_TZPC_DECPROT2CLR_atgc_START (7)
#define SOC_TZPC_DECPROT2CLR_atgc_END (7)
#define SOC_TZPC_DECPROT2CLR_peri_loadmonitor1_START (8)
#define SOC_TZPC_DECPROT2CLR_peri_loadmonitor1_END (8)
#define SOC_TZPC_DECPROT2CLR_IPC_NSCFG_START (11)
#define SOC_TZPC_DECPROT2CLR_IPC_NSCFG_END (11)
#define SOC_TZPC_DECPROT2CLR_g3d_firewall_slv_START (16)
#define SOC_TZPC_DECPROT2CLR_g3d_firewall_slv_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int pcie0_firewall : 8;
        unsigned int reserved_1 : 8;
        unsigned int MMC0_CRG : 1;
        unsigned int MMC0_SYS_CTRL : 1;
        unsigned int HSDT_CRG_SUB_NSEC_REGION : 1;
        unsigned int HSDT_CRG_SUB_SEC_REGION : 1;
        unsigned int sd30 : 1;
        unsigned int sdio0 : 1;
        unsigned int HSDT_SYS_CTRL_SUB_NSEC_REGION : 1;
        unsigned int HSDT_SYS_CTRL_SUB_SEC_REGION : 1;
    } reg;
} SOC_TZPC_DECPROT3STAT_UNION;
#endif
#define SOC_TZPC_DECPROT3STAT_pcie0_firewall_START (8)
#define SOC_TZPC_DECPROT3STAT_pcie0_firewall_END (15)
#define SOC_TZPC_DECPROT3STAT_MMC0_CRG_START (24)
#define SOC_TZPC_DECPROT3STAT_MMC0_CRG_END (24)
#define SOC_TZPC_DECPROT3STAT_MMC0_SYS_CTRL_START (25)
#define SOC_TZPC_DECPROT3STAT_MMC0_SYS_CTRL_END (25)
#define SOC_TZPC_DECPROT3STAT_HSDT_CRG_SUB_NSEC_REGION_START (26)
#define SOC_TZPC_DECPROT3STAT_HSDT_CRG_SUB_NSEC_REGION_END (26)
#define SOC_TZPC_DECPROT3STAT_HSDT_CRG_SUB_SEC_REGION_START (27)
#define SOC_TZPC_DECPROT3STAT_HSDT_CRG_SUB_SEC_REGION_END (27)
#define SOC_TZPC_DECPROT3STAT_sd30_START (28)
#define SOC_TZPC_DECPROT3STAT_sd30_END (28)
#define SOC_TZPC_DECPROT3STAT_sdio0_START (29)
#define SOC_TZPC_DECPROT3STAT_sdio0_END (29)
#define SOC_TZPC_DECPROT3STAT_HSDT_SYS_CTRL_SUB_NSEC_REGION_START (30)
#define SOC_TZPC_DECPROT3STAT_HSDT_SYS_CTRL_SUB_NSEC_REGION_END (30)
#define SOC_TZPC_DECPROT3STAT_HSDT_SYS_CTRL_SUB_SEC_REGION_START (31)
#define SOC_TZPC_DECPROT3STAT_HSDT_SYS_CTRL_SUB_SEC_REGION_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int pcie0_firewall : 8;
        unsigned int reserved_1 : 8;
        unsigned int MMC0_CRG : 1;
        unsigned int MMC0_SYS_CTRL : 1;
        unsigned int HSDT_CRG_SUB_NSEC_REGION : 1;
        unsigned int HSDT_CRG_SUB_SEC_REGION : 1;
        unsigned int sd30 : 1;
        unsigned int sdio0 : 1;
        unsigned int HSDT_SYS_CTRL_SUB_NSEC_REGION : 1;
        unsigned int HSDT_SYS_CTRL_SUB_SEC_REGION : 1;
    } reg;
} SOC_TZPC_DECPROT3SET_UNION;
#endif
#define SOC_TZPC_DECPROT3SET_pcie0_firewall_START (8)
#define SOC_TZPC_DECPROT3SET_pcie0_firewall_END (15)
#define SOC_TZPC_DECPROT3SET_MMC0_CRG_START (24)
#define SOC_TZPC_DECPROT3SET_MMC0_CRG_END (24)
#define SOC_TZPC_DECPROT3SET_MMC0_SYS_CTRL_START (25)
#define SOC_TZPC_DECPROT3SET_MMC0_SYS_CTRL_END (25)
#define SOC_TZPC_DECPROT3SET_HSDT_CRG_SUB_NSEC_REGION_START (26)
#define SOC_TZPC_DECPROT3SET_HSDT_CRG_SUB_NSEC_REGION_END (26)
#define SOC_TZPC_DECPROT3SET_HSDT_CRG_SUB_SEC_REGION_START (27)
#define SOC_TZPC_DECPROT3SET_HSDT_CRG_SUB_SEC_REGION_END (27)
#define SOC_TZPC_DECPROT3SET_sd30_START (28)
#define SOC_TZPC_DECPROT3SET_sd30_END (28)
#define SOC_TZPC_DECPROT3SET_sdio0_START (29)
#define SOC_TZPC_DECPROT3SET_sdio0_END (29)
#define SOC_TZPC_DECPROT3SET_HSDT_SYS_CTRL_SUB_NSEC_REGION_START (30)
#define SOC_TZPC_DECPROT3SET_HSDT_SYS_CTRL_SUB_NSEC_REGION_END (30)
#define SOC_TZPC_DECPROT3SET_HSDT_SYS_CTRL_SUB_SEC_REGION_START (31)
#define SOC_TZPC_DECPROT3SET_HSDT_SYS_CTRL_SUB_SEC_REGION_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int pcie0_firewall : 8;
        unsigned int reserved_1 : 8;
        unsigned int MMC0_CRG : 1;
        unsigned int MMC0_SYS_CTRL : 1;
        unsigned int HSDT_CRG_SUB_NSEC_REGION : 1;
        unsigned int HSDT_CRG_SUB_SEC_REGION : 1;
        unsigned int sd30 : 1;
        unsigned int sdio0 : 1;
        unsigned int HSDT_SYS_CTRL_SUB_NSEC_REGION : 1;
        unsigned int HSDT_SYS_CTRL_SUB_SEC_REGION : 1;
    } reg;
} SOC_TZPC_DECPROT3CLR_UNION;
#endif
#define SOC_TZPC_DECPROT3CLR_pcie0_firewall_START (8)
#define SOC_TZPC_DECPROT3CLR_pcie0_firewall_END (15)
#define SOC_TZPC_DECPROT3CLR_MMC0_CRG_START (24)
#define SOC_TZPC_DECPROT3CLR_MMC0_CRG_END (24)
#define SOC_TZPC_DECPROT3CLR_MMC0_SYS_CTRL_START (25)
#define SOC_TZPC_DECPROT3CLR_MMC0_SYS_CTRL_END (25)
#define SOC_TZPC_DECPROT3CLR_HSDT_CRG_SUB_NSEC_REGION_START (26)
#define SOC_TZPC_DECPROT3CLR_HSDT_CRG_SUB_NSEC_REGION_END (26)
#define SOC_TZPC_DECPROT3CLR_HSDT_CRG_SUB_SEC_REGION_START (27)
#define SOC_TZPC_DECPROT3CLR_HSDT_CRG_SUB_SEC_REGION_END (27)
#define SOC_TZPC_DECPROT3CLR_sd30_START (28)
#define SOC_TZPC_DECPROT3CLR_sd30_END (28)
#define SOC_TZPC_DECPROT3CLR_sdio0_START (29)
#define SOC_TZPC_DECPROT3CLR_sdio0_END (29)
#define SOC_TZPC_DECPROT3CLR_HSDT_SYS_CTRL_SUB_NSEC_REGION_START (30)
#define SOC_TZPC_DECPROT3CLR_HSDT_SYS_CTRL_SUB_NSEC_REGION_END (30)
#define SOC_TZPC_DECPROT3CLR_HSDT_SYS_CTRL_SUB_SEC_REGION_START (31)
#define SOC_TZPC_DECPROT3CLR_HSDT_SYS_CTRL_SUB_SEC_REGION_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int usb3otg : 1;
        unsigned int usb3otg_bc : 1;
        unsigned int perf_stat : 1;
        unsigned int SPE_SLV : 1;
        unsigned int ipcns : 1;
        unsigned int ipc : 1;
        unsigned int EICC_slv_SEC : 1;
        unsigned int EICC_slv_NSEC : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int codec_ssi : 1;
        unsigned int ipc_mdm_s : 1;
        unsigned int ipc_mdm_ns : 1;
        unsigned int uart0 : 1;
        unsigned int uart1 : 1;
        unsigned int uart2 : 1;
        unsigned int uart4 : 1;
        unsigned int uart5 : 1;
        unsigned int spi1 : 1;
        unsigned int i2c3 : 1;
        unsigned int i2c4 : 1;
        unsigned int DDRC_SECURE_BOOT_LOCK : 1;
        unsigned int I2C6 : 1;
        unsigned int Latency_Monitor_CTRL : 1;
        unsigned int spi4 : 1;
        unsigned int i2c7 : 1;
        unsigned int I3C4 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ioc_mmc0 : 1;
        unsigned int IOC_HSDT : 1;
    } reg;
} SOC_TZPC_DECPROT4STAT_UNION;
#endif
#define SOC_TZPC_DECPROT4STAT_usb3otg_START (1)
#define SOC_TZPC_DECPROT4STAT_usb3otg_END (1)
#define SOC_TZPC_DECPROT4STAT_usb3otg_bc_START (2)
#define SOC_TZPC_DECPROT4STAT_usb3otg_bc_END (2)
#define SOC_TZPC_DECPROT4STAT_perf_stat_START (3)
#define SOC_TZPC_DECPROT4STAT_perf_stat_END (3)
#define SOC_TZPC_DECPROT4STAT_SPE_SLV_START (4)
#define SOC_TZPC_DECPROT4STAT_SPE_SLV_END (4)
#define SOC_TZPC_DECPROT4STAT_ipcns_START (5)
#define SOC_TZPC_DECPROT4STAT_ipcns_END (5)
#define SOC_TZPC_DECPROT4STAT_ipc_START (6)
#define SOC_TZPC_DECPROT4STAT_ipc_END (6)
#define SOC_TZPC_DECPROT4STAT_EICC_slv_SEC_START (7)
#define SOC_TZPC_DECPROT4STAT_EICC_slv_SEC_END (7)
#define SOC_TZPC_DECPROT4STAT_EICC_slv_NSEC_START (8)
#define SOC_TZPC_DECPROT4STAT_EICC_slv_NSEC_END (8)
#define SOC_TZPC_DECPROT4STAT_codec_ssi_START (11)
#define SOC_TZPC_DECPROT4STAT_codec_ssi_END (11)
#define SOC_TZPC_DECPROT4STAT_ipc_mdm_s_START (12)
#define SOC_TZPC_DECPROT4STAT_ipc_mdm_s_END (12)
#define SOC_TZPC_DECPROT4STAT_ipc_mdm_ns_START (13)
#define SOC_TZPC_DECPROT4STAT_ipc_mdm_ns_END (13)
#define SOC_TZPC_DECPROT4STAT_uart0_START (14)
#define SOC_TZPC_DECPROT4STAT_uart0_END (14)
#define SOC_TZPC_DECPROT4STAT_uart1_START (15)
#define SOC_TZPC_DECPROT4STAT_uart1_END (15)
#define SOC_TZPC_DECPROT4STAT_uart2_START (16)
#define SOC_TZPC_DECPROT4STAT_uart2_END (16)
#define SOC_TZPC_DECPROT4STAT_uart4_START (17)
#define SOC_TZPC_DECPROT4STAT_uart4_END (17)
#define SOC_TZPC_DECPROT4STAT_uart5_START (18)
#define SOC_TZPC_DECPROT4STAT_uart5_END (18)
#define SOC_TZPC_DECPROT4STAT_spi1_START (19)
#define SOC_TZPC_DECPROT4STAT_spi1_END (19)
#define SOC_TZPC_DECPROT4STAT_i2c3_START (20)
#define SOC_TZPC_DECPROT4STAT_i2c3_END (20)
#define SOC_TZPC_DECPROT4STAT_i2c4_START (21)
#define SOC_TZPC_DECPROT4STAT_i2c4_END (21)
#define SOC_TZPC_DECPROT4STAT_DDRC_SECURE_BOOT_LOCK_START (22)
#define SOC_TZPC_DECPROT4STAT_DDRC_SECURE_BOOT_LOCK_END (22)
#define SOC_TZPC_DECPROT4STAT_I2C6_START (23)
#define SOC_TZPC_DECPROT4STAT_I2C6_END (23)
#define SOC_TZPC_DECPROT4STAT_Latency_Monitor_CTRL_START (24)
#define SOC_TZPC_DECPROT4STAT_Latency_Monitor_CTRL_END (24)
#define SOC_TZPC_DECPROT4STAT_spi4_START (25)
#define SOC_TZPC_DECPROT4STAT_spi4_END (25)
#define SOC_TZPC_DECPROT4STAT_i2c7_START (26)
#define SOC_TZPC_DECPROT4STAT_i2c7_END (26)
#define SOC_TZPC_DECPROT4STAT_I3C4_START (27)
#define SOC_TZPC_DECPROT4STAT_I3C4_END (27)
#define SOC_TZPC_DECPROT4STAT_ioc_mmc0_START (30)
#define SOC_TZPC_DECPROT4STAT_ioc_mmc0_END (30)
#define SOC_TZPC_DECPROT4STAT_IOC_HSDT_START (31)
#define SOC_TZPC_DECPROT4STAT_IOC_HSDT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int usb3otg : 1;
        unsigned int usb3otg_bc : 1;
        unsigned int perf_stat : 1;
        unsigned int SPE_SLV : 1;
        unsigned int ipcns : 1;
        unsigned int ipc : 1;
        unsigned int EICC_slv_SEC : 1;
        unsigned int EICC_slv_NSEC : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int codec_ssi : 1;
        unsigned int ipc_mdm_s : 1;
        unsigned int ipc_mdm_ns : 1;
        unsigned int uart0 : 1;
        unsigned int uart1 : 1;
        unsigned int uart2 : 1;
        unsigned int uart4 : 1;
        unsigned int uart5 : 1;
        unsigned int spi1 : 1;
        unsigned int i2c3 : 1;
        unsigned int i2c4 : 1;
        unsigned int DDRC_SECURE_BOOT_LOCK : 1;
        unsigned int I2C6 : 1;
        unsigned int Latency_Monitor_CTRL : 1;
        unsigned int spi4 : 1;
        unsigned int i2c7 : 1;
        unsigned int I3C4 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ioc_mmc0 : 1;
        unsigned int IOC_HSDT : 1;
    } reg;
} SOC_TZPC_DECPROT4SET_UNION;
#endif
#define SOC_TZPC_DECPROT4SET_usb3otg_START (1)
#define SOC_TZPC_DECPROT4SET_usb3otg_END (1)
#define SOC_TZPC_DECPROT4SET_usb3otg_bc_START (2)
#define SOC_TZPC_DECPROT4SET_usb3otg_bc_END (2)
#define SOC_TZPC_DECPROT4SET_perf_stat_START (3)
#define SOC_TZPC_DECPROT4SET_perf_stat_END (3)
#define SOC_TZPC_DECPROT4SET_SPE_SLV_START (4)
#define SOC_TZPC_DECPROT4SET_SPE_SLV_END (4)
#define SOC_TZPC_DECPROT4SET_ipcns_START (5)
#define SOC_TZPC_DECPROT4SET_ipcns_END (5)
#define SOC_TZPC_DECPROT4SET_ipc_START (6)
#define SOC_TZPC_DECPROT4SET_ipc_END (6)
#define SOC_TZPC_DECPROT4SET_EICC_slv_SEC_START (7)
#define SOC_TZPC_DECPROT4SET_EICC_slv_SEC_END (7)
#define SOC_TZPC_DECPROT4SET_EICC_slv_NSEC_START (8)
#define SOC_TZPC_DECPROT4SET_EICC_slv_NSEC_END (8)
#define SOC_TZPC_DECPROT4SET_codec_ssi_START (11)
#define SOC_TZPC_DECPROT4SET_codec_ssi_END (11)
#define SOC_TZPC_DECPROT4SET_ipc_mdm_s_START (12)
#define SOC_TZPC_DECPROT4SET_ipc_mdm_s_END (12)
#define SOC_TZPC_DECPROT4SET_ipc_mdm_ns_START (13)
#define SOC_TZPC_DECPROT4SET_ipc_mdm_ns_END (13)
#define SOC_TZPC_DECPROT4SET_uart0_START (14)
#define SOC_TZPC_DECPROT4SET_uart0_END (14)
#define SOC_TZPC_DECPROT4SET_uart1_START (15)
#define SOC_TZPC_DECPROT4SET_uart1_END (15)
#define SOC_TZPC_DECPROT4SET_uart2_START (16)
#define SOC_TZPC_DECPROT4SET_uart2_END (16)
#define SOC_TZPC_DECPROT4SET_uart4_START (17)
#define SOC_TZPC_DECPROT4SET_uart4_END (17)
#define SOC_TZPC_DECPROT4SET_uart5_START (18)
#define SOC_TZPC_DECPROT4SET_uart5_END (18)
#define SOC_TZPC_DECPROT4SET_spi1_START (19)
#define SOC_TZPC_DECPROT4SET_spi1_END (19)
#define SOC_TZPC_DECPROT4SET_i2c3_START (20)
#define SOC_TZPC_DECPROT4SET_i2c3_END (20)
#define SOC_TZPC_DECPROT4SET_i2c4_START (21)
#define SOC_TZPC_DECPROT4SET_i2c4_END (21)
#define SOC_TZPC_DECPROT4SET_DDRC_SECURE_BOOT_LOCK_START (22)
#define SOC_TZPC_DECPROT4SET_DDRC_SECURE_BOOT_LOCK_END (22)
#define SOC_TZPC_DECPROT4SET_I2C6_START (23)
#define SOC_TZPC_DECPROT4SET_I2C6_END (23)
#define SOC_TZPC_DECPROT4SET_Latency_Monitor_CTRL_START (24)
#define SOC_TZPC_DECPROT4SET_Latency_Monitor_CTRL_END (24)
#define SOC_TZPC_DECPROT4SET_spi4_START (25)
#define SOC_TZPC_DECPROT4SET_spi4_END (25)
#define SOC_TZPC_DECPROT4SET_i2c7_START (26)
#define SOC_TZPC_DECPROT4SET_i2c7_END (26)
#define SOC_TZPC_DECPROT4SET_I3C4_START (27)
#define SOC_TZPC_DECPROT4SET_I3C4_END (27)
#define SOC_TZPC_DECPROT4SET_ioc_mmc0_START (30)
#define SOC_TZPC_DECPROT4SET_ioc_mmc0_END (30)
#define SOC_TZPC_DECPROT4SET_IOC_HSDT_START (31)
#define SOC_TZPC_DECPROT4SET_IOC_HSDT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int usb3otg : 1;
        unsigned int usb3otg_bc : 1;
        unsigned int perf_stat : 1;
        unsigned int SPE_SLV : 1;
        unsigned int ipcns : 1;
        unsigned int ipc : 1;
        unsigned int EICC_slv_SEC : 1;
        unsigned int EICC_slv_NSEC : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int codec_ssi : 1;
        unsigned int ipc_mdm_s : 1;
        unsigned int ipc_mdm_ns : 1;
        unsigned int uart0 : 1;
        unsigned int uart1 : 1;
        unsigned int uart2 : 1;
        unsigned int uart4 : 1;
        unsigned int uart5 : 1;
        unsigned int spi1 : 1;
        unsigned int i2c3 : 1;
        unsigned int i2c4 : 1;
        unsigned int DDRC_SECURE_BOOT_LOCK : 1;
        unsigned int I2C6 : 1;
        unsigned int Latency_Monitor_CTRL : 1;
        unsigned int spi4 : 1;
        unsigned int i2c7 : 1;
        unsigned int I3C4 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int ioc_mmc0 : 1;
        unsigned int IOC_HSDT : 1;
    } reg;
} SOC_TZPC_DECPROT4CLR_UNION;
#endif
#define SOC_TZPC_DECPROT4CLR_usb3otg_START (1)
#define SOC_TZPC_DECPROT4CLR_usb3otg_END (1)
#define SOC_TZPC_DECPROT4CLR_usb3otg_bc_START (2)
#define SOC_TZPC_DECPROT4CLR_usb3otg_bc_END (2)
#define SOC_TZPC_DECPROT4CLR_perf_stat_START (3)
#define SOC_TZPC_DECPROT4CLR_perf_stat_END (3)
#define SOC_TZPC_DECPROT4CLR_SPE_SLV_START (4)
#define SOC_TZPC_DECPROT4CLR_SPE_SLV_END (4)
#define SOC_TZPC_DECPROT4CLR_ipcns_START (5)
#define SOC_TZPC_DECPROT4CLR_ipcns_END (5)
#define SOC_TZPC_DECPROT4CLR_ipc_START (6)
#define SOC_TZPC_DECPROT4CLR_ipc_END (6)
#define SOC_TZPC_DECPROT4CLR_EICC_slv_SEC_START (7)
#define SOC_TZPC_DECPROT4CLR_EICC_slv_SEC_END (7)
#define SOC_TZPC_DECPROT4CLR_EICC_slv_NSEC_START (8)
#define SOC_TZPC_DECPROT4CLR_EICC_slv_NSEC_END (8)
#define SOC_TZPC_DECPROT4CLR_codec_ssi_START (11)
#define SOC_TZPC_DECPROT4CLR_codec_ssi_END (11)
#define SOC_TZPC_DECPROT4CLR_ipc_mdm_s_START (12)
#define SOC_TZPC_DECPROT4CLR_ipc_mdm_s_END (12)
#define SOC_TZPC_DECPROT4CLR_ipc_mdm_ns_START (13)
#define SOC_TZPC_DECPROT4CLR_ipc_mdm_ns_END (13)
#define SOC_TZPC_DECPROT4CLR_uart0_START (14)
#define SOC_TZPC_DECPROT4CLR_uart0_END (14)
#define SOC_TZPC_DECPROT4CLR_uart1_START (15)
#define SOC_TZPC_DECPROT4CLR_uart1_END (15)
#define SOC_TZPC_DECPROT4CLR_uart2_START (16)
#define SOC_TZPC_DECPROT4CLR_uart2_END (16)
#define SOC_TZPC_DECPROT4CLR_uart4_START (17)
#define SOC_TZPC_DECPROT4CLR_uart4_END (17)
#define SOC_TZPC_DECPROT4CLR_uart5_START (18)
#define SOC_TZPC_DECPROT4CLR_uart5_END (18)
#define SOC_TZPC_DECPROT4CLR_spi1_START (19)
#define SOC_TZPC_DECPROT4CLR_spi1_END (19)
#define SOC_TZPC_DECPROT4CLR_i2c3_START (20)
#define SOC_TZPC_DECPROT4CLR_i2c3_END (20)
#define SOC_TZPC_DECPROT4CLR_i2c4_START (21)
#define SOC_TZPC_DECPROT4CLR_i2c4_END (21)
#define SOC_TZPC_DECPROT4CLR_DDRC_SECURE_BOOT_LOCK_START (22)
#define SOC_TZPC_DECPROT4CLR_DDRC_SECURE_BOOT_LOCK_END (22)
#define SOC_TZPC_DECPROT4CLR_I2C6_START (23)
#define SOC_TZPC_DECPROT4CLR_I2C6_END (23)
#define SOC_TZPC_DECPROT4CLR_Latency_Monitor_CTRL_START (24)
#define SOC_TZPC_DECPROT4CLR_Latency_Monitor_CTRL_END (24)
#define SOC_TZPC_DECPROT4CLR_spi4_START (25)
#define SOC_TZPC_DECPROT4CLR_spi4_END (25)
#define SOC_TZPC_DECPROT4CLR_i2c7_START (26)
#define SOC_TZPC_DECPROT4CLR_i2c7_END (26)
#define SOC_TZPC_DECPROT4CLR_I3C4_START (27)
#define SOC_TZPC_DECPROT4CLR_I3C4_END (27)
#define SOC_TZPC_DECPROT4CLR_ioc_mmc0_START (30)
#define SOC_TZPC_DECPROT4CLR_ioc_mmc0_END (30)
#define SOC_TZPC_DECPROT4CLR_IOC_HSDT_START (31)
#define SOC_TZPC_DECPROT4CLR_IOC_HSDT_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int LP_SPI_DBG : 1;
        unsigned int lpm3_tsensorc : 1;
        unsigned int lpm3_pmc : 1;
        unsigned int lpm3_uart6 : 1;
        unsigned int reserved_1 : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION1 : 1;
        unsigned int PERI_CRG_SUB_REGION0 : 1;
        unsigned int PERI_CRG_SUB_REGION1 : 1;
        unsigned int PERI_CRG_SUB_REGION2 : 1;
        unsigned int PERI_CRG_SUB_REGION3 : 1;
        unsigned int PERI_CRG_SUB_REGION4 : 1;
        unsigned int lpm3_wdg : 1;
        unsigned int lpm3_timer : 1;
        unsigned int lpm3_config : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION0_REGION3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int lpm3_ram : 1;
        unsigned int reserved_3 : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION2 : 1;
        unsigned int CORE_CRG_SUB_REGION0 : 1;
        unsigned int CORE_CRG_SUB_REGION1 : 1;
        unsigned int CORE_CRG_SUB_REGION2 : 1;
        unsigned int CORE_CRG_SUB_REGION3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
    } reg;
} SOC_TZPC_DECPROT5STAT_UNION;
#endif
#define SOC_TZPC_DECPROT5STAT_LP_SPI_DBG_START (1)
#define SOC_TZPC_DECPROT5STAT_LP_SPI_DBG_END (1)
#define SOC_TZPC_DECPROT5STAT_lpm3_tsensorc_START (2)
#define SOC_TZPC_DECPROT5STAT_lpm3_tsensorc_END (2)
#define SOC_TZPC_DECPROT5STAT_lpm3_pmc_START (3)
#define SOC_TZPC_DECPROT5STAT_lpm3_pmc_END (3)
#define SOC_TZPC_DECPROT5STAT_lpm3_uart6_START (4)
#define SOC_TZPC_DECPROT5STAT_lpm3_uart6_END (4)
#define SOC_TZPC_DECPROT5STAT_CPU_PERI_CRG_SUB_REGION1_START (6)
#define SOC_TZPC_DECPROT5STAT_CPU_PERI_CRG_SUB_REGION1_END (6)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION0_START (7)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION0_END (7)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION1_START (8)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION1_END (8)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION2_START (9)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION2_END (9)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION3_START (10)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION3_END (10)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION4_START (11)
#define SOC_TZPC_DECPROT5STAT_PERI_CRG_SUB_REGION4_END (11)
#define SOC_TZPC_DECPROT5STAT_lpm3_wdg_START (12)
#define SOC_TZPC_DECPROT5STAT_lpm3_wdg_END (12)
#define SOC_TZPC_DECPROT5STAT_lpm3_timer_START (13)
#define SOC_TZPC_DECPROT5STAT_lpm3_timer_END (13)
#define SOC_TZPC_DECPROT5STAT_lpm3_config_START (14)
#define SOC_TZPC_DECPROT5STAT_lpm3_config_END (14)
#define SOC_TZPC_DECPROT5STAT_CPU_PERI_CRG_SUB_REGION0_REGION3_START (15)
#define SOC_TZPC_DECPROT5STAT_CPU_PERI_CRG_SUB_REGION0_REGION3_END (15)
#define SOC_TZPC_DECPROT5STAT_lpm3_ram_START (17)
#define SOC_TZPC_DECPROT5STAT_lpm3_ram_END (17)
#define SOC_TZPC_DECPROT5STAT_CPU_PERI_CRG_SUB_REGION2_START (19)
#define SOC_TZPC_DECPROT5STAT_CPU_PERI_CRG_SUB_REGION2_END (19)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION0_START (20)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION0_END (20)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION1_START (21)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION1_END (21)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION2_START (22)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION2_END (22)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION3_START (23)
#define SOC_TZPC_DECPROT5STAT_CORE_CRG_SUB_REGION3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int LP_SPI_DBG : 1;
        unsigned int lpm3_tsensorc : 1;
        unsigned int lpm3_pmc : 1;
        unsigned int lpm3_uart6 : 1;
        unsigned int reserved_1 : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION1 : 1;
        unsigned int PERI_CRG_SUB_REGION0 : 1;
        unsigned int PERI_CRG_SUB_REGION1 : 1;
        unsigned int PERI_CRG_SUB_REGION2 : 1;
        unsigned int PERI_CRG_SUB_REGION3 : 1;
        unsigned int PERI_CRG_SUB_REGION4 : 1;
        unsigned int lpm3_wdg : 1;
        unsigned int lpm3_timer : 1;
        unsigned int lpm3_config : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION0_REGION3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int lpm3_ram : 1;
        unsigned int reserved_3 : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION2 : 1;
        unsigned int CORE_CRG_SUB_REGION0 : 1;
        unsigned int CORE_CRG_SUB_REGION1 : 1;
        unsigned int CORE_CRG_SUB_REGION2 : 1;
        unsigned int CORE_CRG_SUB_REGION3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
    } reg;
} SOC_TZPC_DECPROT5SET_UNION;
#endif
#define SOC_TZPC_DECPROT5SET_LP_SPI_DBG_START (1)
#define SOC_TZPC_DECPROT5SET_LP_SPI_DBG_END (1)
#define SOC_TZPC_DECPROT5SET_lpm3_tsensorc_START (2)
#define SOC_TZPC_DECPROT5SET_lpm3_tsensorc_END (2)
#define SOC_TZPC_DECPROT5SET_lpm3_pmc_START (3)
#define SOC_TZPC_DECPROT5SET_lpm3_pmc_END (3)
#define SOC_TZPC_DECPROT5SET_lpm3_uart6_START (4)
#define SOC_TZPC_DECPROT5SET_lpm3_uart6_END (4)
#define SOC_TZPC_DECPROT5SET_CPU_PERI_CRG_SUB_REGION1_START (6)
#define SOC_TZPC_DECPROT5SET_CPU_PERI_CRG_SUB_REGION1_END (6)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION0_START (7)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION0_END (7)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION1_START (8)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION1_END (8)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION2_START (9)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION2_END (9)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION3_START (10)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION3_END (10)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION4_START (11)
#define SOC_TZPC_DECPROT5SET_PERI_CRG_SUB_REGION4_END (11)
#define SOC_TZPC_DECPROT5SET_lpm3_wdg_START (12)
#define SOC_TZPC_DECPROT5SET_lpm3_wdg_END (12)
#define SOC_TZPC_DECPROT5SET_lpm3_timer_START (13)
#define SOC_TZPC_DECPROT5SET_lpm3_timer_END (13)
#define SOC_TZPC_DECPROT5SET_lpm3_config_START (14)
#define SOC_TZPC_DECPROT5SET_lpm3_config_END (14)
#define SOC_TZPC_DECPROT5SET_CPU_PERI_CRG_SUB_REGION0_REGION3_START (15)
#define SOC_TZPC_DECPROT5SET_CPU_PERI_CRG_SUB_REGION0_REGION3_END (15)
#define SOC_TZPC_DECPROT5SET_lpm3_ram_START (17)
#define SOC_TZPC_DECPROT5SET_lpm3_ram_END (17)
#define SOC_TZPC_DECPROT5SET_CPU_PERI_CRG_SUB_REGION2_START (19)
#define SOC_TZPC_DECPROT5SET_CPU_PERI_CRG_SUB_REGION2_END (19)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION0_START (20)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION0_END (20)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION1_START (21)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION1_END (21)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION2_START (22)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION2_END (22)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION3_START (23)
#define SOC_TZPC_DECPROT5SET_CORE_CRG_SUB_REGION3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int LP_SPI_DBG : 1;
        unsigned int lpm3_tsensorc : 1;
        unsigned int lpm3_pmc : 1;
        unsigned int lpm3_uart6 : 1;
        unsigned int reserved_1 : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION1 : 1;
        unsigned int PERI_CRG_SUB_REGION0 : 1;
        unsigned int PERI_CRG_SUB_REGION1 : 1;
        unsigned int PERI_CRG_SUB_REGION2 : 1;
        unsigned int PERI_CRG_SUB_REGION3 : 1;
        unsigned int PERI_CRG_SUB_REGION4 : 1;
        unsigned int lpm3_wdg : 1;
        unsigned int lpm3_timer : 1;
        unsigned int lpm3_config : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION0_REGION3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int lpm3_ram : 1;
        unsigned int reserved_3 : 1;
        unsigned int CPU_PERI_CRG_SUB_REGION2 : 1;
        unsigned int CORE_CRG_SUB_REGION0 : 1;
        unsigned int CORE_CRG_SUB_REGION1 : 1;
        unsigned int CORE_CRG_SUB_REGION2 : 1;
        unsigned int CORE_CRG_SUB_REGION3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
    } reg;
} SOC_TZPC_DECPROT5CLR_UNION;
#endif
#define SOC_TZPC_DECPROT5CLR_LP_SPI_DBG_START (1)
#define SOC_TZPC_DECPROT5CLR_LP_SPI_DBG_END (1)
#define SOC_TZPC_DECPROT5CLR_lpm3_tsensorc_START (2)
#define SOC_TZPC_DECPROT5CLR_lpm3_tsensorc_END (2)
#define SOC_TZPC_DECPROT5CLR_lpm3_pmc_START (3)
#define SOC_TZPC_DECPROT5CLR_lpm3_pmc_END (3)
#define SOC_TZPC_DECPROT5CLR_lpm3_uart6_START (4)
#define SOC_TZPC_DECPROT5CLR_lpm3_uart6_END (4)
#define SOC_TZPC_DECPROT5CLR_CPU_PERI_CRG_SUB_REGION1_START (6)
#define SOC_TZPC_DECPROT5CLR_CPU_PERI_CRG_SUB_REGION1_END (6)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION0_START (7)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION0_END (7)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION1_START (8)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION1_END (8)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION2_START (9)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION2_END (9)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION3_START (10)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION3_END (10)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION4_START (11)
#define SOC_TZPC_DECPROT5CLR_PERI_CRG_SUB_REGION4_END (11)
#define SOC_TZPC_DECPROT5CLR_lpm3_wdg_START (12)
#define SOC_TZPC_DECPROT5CLR_lpm3_wdg_END (12)
#define SOC_TZPC_DECPROT5CLR_lpm3_timer_START (13)
#define SOC_TZPC_DECPROT5CLR_lpm3_timer_END (13)
#define SOC_TZPC_DECPROT5CLR_lpm3_config_START (14)
#define SOC_TZPC_DECPROT5CLR_lpm3_config_END (14)
#define SOC_TZPC_DECPROT5CLR_CPU_PERI_CRG_SUB_REGION0_REGION3_START (15)
#define SOC_TZPC_DECPROT5CLR_CPU_PERI_CRG_SUB_REGION0_REGION3_END (15)
#define SOC_TZPC_DECPROT5CLR_lpm3_ram_START (17)
#define SOC_TZPC_DECPROT5CLR_lpm3_ram_END (17)
#define SOC_TZPC_DECPROT5CLR_CPU_PERI_CRG_SUB_REGION2_START (19)
#define SOC_TZPC_DECPROT5CLR_CPU_PERI_CRG_SUB_REGION2_END (19)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION0_START (20)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION0_END (20)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION1_START (21)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION1_END (21)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION2_START (22)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION2_END (22)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION3_START (23)
#define SOC_TZPC_DECPROT5CLR_CORE_CRG_SUB_REGION3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpm3 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int sd3 : 1;
        unsigned int sdio0 : 1;
        unsigned int reserved_4: 1;
        unsigned int usb3otg : 1;
        unsigned int g3d : 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int perf_stat : 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int pcie0 : 1;
        unsigned int PCIE1 : 1;
        unsigned int LAT_STAT : 1;
        unsigned int SPE_MST : 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
    } reg;
} SOC_TZPC_DECPROT6STAT_UNION;
#endif
#define SOC_TZPC_DECPROT6STAT_lpm3_START (0)
#define SOC_TZPC_DECPROT6STAT_lpm3_END (0)
#define SOC_TZPC_DECPROT6STAT_sd3_START (5)
#define SOC_TZPC_DECPROT6STAT_sd3_END (5)
#define SOC_TZPC_DECPROT6STAT_sdio0_START (6)
#define SOC_TZPC_DECPROT6STAT_sdio0_END (6)
#define SOC_TZPC_DECPROT6STAT_usb3otg_START (8)
#define SOC_TZPC_DECPROT6STAT_usb3otg_END (8)
#define SOC_TZPC_DECPROT6STAT_g3d_START (9)
#define SOC_TZPC_DECPROT6STAT_g3d_END (9)
#define SOC_TZPC_DECPROT6STAT_perf_stat_START (18)
#define SOC_TZPC_DECPROT6STAT_perf_stat_END (18)
#define SOC_TZPC_DECPROT6STAT_pcie0_START (22)
#define SOC_TZPC_DECPROT6STAT_pcie0_END (22)
#define SOC_TZPC_DECPROT6STAT_PCIE1_START (23)
#define SOC_TZPC_DECPROT6STAT_PCIE1_END (23)
#define SOC_TZPC_DECPROT6STAT_LAT_STAT_START (24)
#define SOC_TZPC_DECPROT6STAT_LAT_STAT_END (24)
#define SOC_TZPC_DECPROT6STAT_SPE_MST_START (25)
#define SOC_TZPC_DECPROT6STAT_SPE_MST_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpm3 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int sd3 : 1;
        unsigned int sdio0 : 1;
        unsigned int reserved_4: 1;
        unsigned int usb3otg : 1;
        unsigned int g3d : 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int perf_stat : 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int pcie0 : 1;
        unsigned int PCIE1 : 1;
        unsigned int LAT_STAT : 1;
        unsigned int SPE_MST : 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
    } reg;
} SOC_TZPC_DECPROT6SET_UNION;
#endif
#define SOC_TZPC_DECPROT6SET_lpm3_START (0)
#define SOC_TZPC_DECPROT6SET_lpm3_END (0)
#define SOC_TZPC_DECPROT6SET_sd3_START (5)
#define SOC_TZPC_DECPROT6SET_sd3_END (5)
#define SOC_TZPC_DECPROT6SET_sdio0_START (6)
#define SOC_TZPC_DECPROT6SET_sdio0_END (6)
#define SOC_TZPC_DECPROT6SET_usb3otg_START (8)
#define SOC_TZPC_DECPROT6SET_usb3otg_END (8)
#define SOC_TZPC_DECPROT6SET_g3d_START (9)
#define SOC_TZPC_DECPROT6SET_g3d_END (9)
#define SOC_TZPC_DECPROT6SET_perf_stat_START (18)
#define SOC_TZPC_DECPROT6SET_perf_stat_END (18)
#define SOC_TZPC_DECPROT6SET_pcie0_START (22)
#define SOC_TZPC_DECPROT6SET_pcie0_END (22)
#define SOC_TZPC_DECPROT6SET_PCIE1_START (23)
#define SOC_TZPC_DECPROT6SET_PCIE1_END (23)
#define SOC_TZPC_DECPROT6SET_LAT_STAT_START (24)
#define SOC_TZPC_DECPROT6SET_LAT_STAT_END (24)
#define SOC_TZPC_DECPROT6SET_SPE_MST_START (25)
#define SOC_TZPC_DECPROT6SET_SPE_MST_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpm3 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int sd3 : 1;
        unsigned int sdio0 : 1;
        unsigned int reserved_4: 1;
        unsigned int usb3otg : 1;
        unsigned int g3d : 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int perf_stat : 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int pcie0 : 1;
        unsigned int PCIE1 : 1;
        unsigned int LAT_STAT : 1;
        unsigned int SPE_MST : 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 1;
        unsigned int reserved_18: 1;
        unsigned int reserved_19: 1;
        unsigned int reserved_20: 1;
        unsigned int reserved_21: 1;
    } reg;
} SOC_TZPC_DECPROT6CLR_UNION;
#endif
#define SOC_TZPC_DECPROT6CLR_lpm3_START (0)
#define SOC_TZPC_DECPROT6CLR_lpm3_END (0)
#define SOC_TZPC_DECPROT6CLR_sd3_START (5)
#define SOC_TZPC_DECPROT6CLR_sd3_END (5)
#define SOC_TZPC_DECPROT6CLR_sdio0_START (6)
#define SOC_TZPC_DECPROT6CLR_sdio0_END (6)
#define SOC_TZPC_DECPROT6CLR_usb3otg_START (8)
#define SOC_TZPC_DECPROT6CLR_usb3otg_END (8)
#define SOC_TZPC_DECPROT6CLR_g3d_START (9)
#define SOC_TZPC_DECPROT6CLR_g3d_END (9)
#define SOC_TZPC_DECPROT6CLR_perf_stat_START (18)
#define SOC_TZPC_DECPROT6CLR_perf_stat_END (18)
#define SOC_TZPC_DECPROT6CLR_pcie0_START (22)
#define SOC_TZPC_DECPROT6CLR_pcie0_END (22)
#define SOC_TZPC_DECPROT6CLR_PCIE1_START (23)
#define SOC_TZPC_DECPROT6CLR_PCIE1_END (23)
#define SOC_TZPC_DECPROT6CLR_LAT_STAT_START (24)
#define SOC_TZPC_DECPROT6CLR_LAT_STAT_END (24)
#define SOC_TZPC_DECPROT6CLR_SPE_MST_START (25)
#define SOC_TZPC_DECPROT6CLR_SPE_MST_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IPF_PSAM_NSEC_SUB_REGION0 : 1;
        unsigned int IPF_NSEC_SUB_REGION0 : 1;
        unsigned int IPF_PSAM_SUB_REGION1 : 1;
        unsigned int IPF_SUB_REGION1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ENABLE_FIREWALL_MAA : 1;
        unsigned int ERR_RESP_FIREWALL_MAA : 1;
        unsigned int MAA_slave_secure_region : 1;
        unsigned int MAA_slave_nsecure_region : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION0 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION1 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION2 : 1;
        unsigned int MEDIA2_CRG_SUB_REGION0 : 1;
        unsigned int MEDIA2_CRG_SUB_REGION1 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ENABLE_FIREWALL_AXI_MEM : 1;
        unsigned int ERR_RESP_FIREWALL_AXI_MEM : 1;
        unsigned int AXI_MEM_slave_secure_region : 1;
        unsigned int AXI_MEM_slave_nsecure_region : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_TZPC_DECPROT7STAT_UNION;
#endif
#define SOC_TZPC_DECPROT7STAT_IPF_PSAM_NSEC_SUB_REGION0_START (0)
#define SOC_TZPC_DECPROT7STAT_IPF_PSAM_NSEC_SUB_REGION0_END (0)
#define SOC_TZPC_DECPROT7STAT_IPF_NSEC_SUB_REGION0_START (1)
#define SOC_TZPC_DECPROT7STAT_IPF_NSEC_SUB_REGION0_END (1)
#define SOC_TZPC_DECPROT7STAT_IPF_PSAM_SUB_REGION1_START (2)
#define SOC_TZPC_DECPROT7STAT_IPF_PSAM_SUB_REGION1_END (2)
#define SOC_TZPC_DECPROT7STAT_IPF_SUB_REGION1_START (3)
#define SOC_TZPC_DECPROT7STAT_IPF_SUB_REGION1_END (3)
#define SOC_TZPC_DECPROT7STAT_ENABLE_FIREWALL_MAA_START (8)
#define SOC_TZPC_DECPROT7STAT_ENABLE_FIREWALL_MAA_END (8)
#define SOC_TZPC_DECPROT7STAT_ERR_RESP_FIREWALL_MAA_START (9)
#define SOC_TZPC_DECPROT7STAT_ERR_RESP_FIREWALL_MAA_END (9)
#define SOC_TZPC_DECPROT7STAT_MAA_slave_secure_region_START (10)
#define SOC_TZPC_DECPROT7STAT_MAA_slave_secure_region_END (10)
#define SOC_TZPC_DECPROT7STAT_MAA_slave_nsecure_region_START (11)
#define SOC_TZPC_DECPROT7STAT_MAA_slave_nsecure_region_END (11)
#define SOC_TZPC_DECPROT7STAT_MEDIA1_CRG_SUB_REGION0_START (16)
#define SOC_TZPC_DECPROT7STAT_MEDIA1_CRG_SUB_REGION0_END (16)
#define SOC_TZPC_DECPROT7STAT_MEDIA1_CRG_SUB_REGION1_START (17)
#define SOC_TZPC_DECPROT7STAT_MEDIA1_CRG_SUB_REGION1_END (17)
#define SOC_TZPC_DECPROT7STAT_MEDIA1_CRG_SUB_REGION2_START (18)
#define SOC_TZPC_DECPROT7STAT_MEDIA1_CRG_SUB_REGION2_END (18)
#define SOC_TZPC_DECPROT7STAT_MEDIA2_CRG_SUB_REGION0_START (19)
#define SOC_TZPC_DECPROT7STAT_MEDIA2_CRG_SUB_REGION0_END (19)
#define SOC_TZPC_DECPROT7STAT_MEDIA2_CRG_SUB_REGION1_START (20)
#define SOC_TZPC_DECPROT7STAT_MEDIA2_CRG_SUB_REGION1_END (20)
#define SOC_TZPC_DECPROT7STAT_ENABLE_FIREWALL_AXI_MEM_START (24)
#define SOC_TZPC_DECPROT7STAT_ENABLE_FIREWALL_AXI_MEM_END (24)
#define SOC_TZPC_DECPROT7STAT_ERR_RESP_FIREWALL_AXI_MEM_START (25)
#define SOC_TZPC_DECPROT7STAT_ERR_RESP_FIREWALL_AXI_MEM_END (25)
#define SOC_TZPC_DECPROT7STAT_AXI_MEM_slave_secure_region_START (26)
#define SOC_TZPC_DECPROT7STAT_AXI_MEM_slave_secure_region_END (26)
#define SOC_TZPC_DECPROT7STAT_AXI_MEM_slave_nsecure_region_START (27)
#define SOC_TZPC_DECPROT7STAT_AXI_MEM_slave_nsecure_region_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IPF_PSAM_NSEC_SUB_REGION0 : 1;
        unsigned int IPF_NSEC_SUB_REGION0 : 1;
        unsigned int IPF_PSAM_SUB_REGION1 : 1;
        unsigned int IPF_SUB_REGION1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ENABLE_FIREWALL_MAA : 1;
        unsigned int ERR_RESP_FIREWALL_MAA : 1;
        unsigned int MAA_slave_secure_region : 1;
        unsigned int MAA_slave_nsecure_region : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION0 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION1 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION2 : 1;
        unsigned int MEDIA2_CRG_SUB_REGION0 : 1;
        unsigned int MEDIA2_CRG_SUB_REGION1 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ENABLE_FIREWALL_AXI_MEM : 1;
        unsigned int ERR_RESP_FIREWALL_AXI_MEM : 1;
        unsigned int AXI_MEM_slave_secure_region : 1;
        unsigned int AXI_MEM_slave_nsecure_region : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_TZPC_DECPROT7SET_UNION;
#endif
#define SOC_TZPC_DECPROT7SET_IPF_PSAM_NSEC_SUB_REGION0_START (0)
#define SOC_TZPC_DECPROT7SET_IPF_PSAM_NSEC_SUB_REGION0_END (0)
#define SOC_TZPC_DECPROT7SET_IPF_NSEC_SUB_REGION0_START (1)
#define SOC_TZPC_DECPROT7SET_IPF_NSEC_SUB_REGION0_END (1)
#define SOC_TZPC_DECPROT7SET_IPF_PSAM_SUB_REGION1_START (2)
#define SOC_TZPC_DECPROT7SET_IPF_PSAM_SUB_REGION1_END (2)
#define SOC_TZPC_DECPROT7SET_IPF_SUB_REGION1_START (3)
#define SOC_TZPC_DECPROT7SET_IPF_SUB_REGION1_END (3)
#define SOC_TZPC_DECPROT7SET_ENABLE_FIREWALL_MAA_START (8)
#define SOC_TZPC_DECPROT7SET_ENABLE_FIREWALL_MAA_END (8)
#define SOC_TZPC_DECPROT7SET_ERR_RESP_FIREWALL_MAA_START (9)
#define SOC_TZPC_DECPROT7SET_ERR_RESP_FIREWALL_MAA_END (9)
#define SOC_TZPC_DECPROT7SET_MAA_slave_secure_region_START (10)
#define SOC_TZPC_DECPROT7SET_MAA_slave_secure_region_END (10)
#define SOC_TZPC_DECPROT7SET_MAA_slave_nsecure_region_START (11)
#define SOC_TZPC_DECPROT7SET_MAA_slave_nsecure_region_END (11)
#define SOC_TZPC_DECPROT7SET_MEDIA1_CRG_SUB_REGION0_START (16)
#define SOC_TZPC_DECPROT7SET_MEDIA1_CRG_SUB_REGION0_END (16)
#define SOC_TZPC_DECPROT7SET_MEDIA1_CRG_SUB_REGION1_START (17)
#define SOC_TZPC_DECPROT7SET_MEDIA1_CRG_SUB_REGION1_END (17)
#define SOC_TZPC_DECPROT7SET_MEDIA1_CRG_SUB_REGION2_START (18)
#define SOC_TZPC_DECPROT7SET_MEDIA1_CRG_SUB_REGION2_END (18)
#define SOC_TZPC_DECPROT7SET_MEDIA2_CRG_SUB_REGION0_START (19)
#define SOC_TZPC_DECPROT7SET_MEDIA2_CRG_SUB_REGION0_END (19)
#define SOC_TZPC_DECPROT7SET_MEDIA2_CRG_SUB_REGION1_START (20)
#define SOC_TZPC_DECPROT7SET_MEDIA2_CRG_SUB_REGION1_END (20)
#define SOC_TZPC_DECPROT7SET_ENABLE_FIREWALL_AXI_MEM_START (24)
#define SOC_TZPC_DECPROT7SET_ENABLE_FIREWALL_AXI_MEM_END (24)
#define SOC_TZPC_DECPROT7SET_ERR_RESP_FIREWALL_AXI_MEM_START (25)
#define SOC_TZPC_DECPROT7SET_ERR_RESP_FIREWALL_AXI_MEM_END (25)
#define SOC_TZPC_DECPROT7SET_AXI_MEM_slave_secure_region_START (26)
#define SOC_TZPC_DECPROT7SET_AXI_MEM_slave_secure_region_END (26)
#define SOC_TZPC_DECPROT7SET_AXI_MEM_slave_nsecure_region_START (27)
#define SOC_TZPC_DECPROT7SET_AXI_MEM_slave_nsecure_region_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IPF_PSAM_NSEC_SUB_REGION0 : 1;
        unsigned int IPF_NSEC_SUB_REGION0 : 1;
        unsigned int IPF_PSAM_SUB_REGION1 : 1;
        unsigned int IPF_SUB_REGION1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ENABLE_FIREWALL_MAA : 1;
        unsigned int ERR_RESP_FIREWALL_MAA : 1;
        unsigned int MAA_slave_secure_region : 1;
        unsigned int MAA_slave_nsecure_region : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION0 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION1 : 1;
        unsigned int MEDIA1_CRG_SUB_REGION2 : 1;
        unsigned int MEDIA2_CRG_SUB_REGION0 : 1;
        unsigned int MEDIA2_CRG_SUB_REGION1 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ENABLE_FIREWALL_AXI_MEM : 1;
        unsigned int ERR_RESP_FIREWALL_AXI_MEM : 1;
        unsigned int AXI_MEM_slave_secure_region : 1;
        unsigned int AXI_MEM_slave_nsecure_region : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
    } reg;
} SOC_TZPC_DECPROT7CLR_UNION;
#endif
#define SOC_TZPC_DECPROT7CLR_IPF_PSAM_NSEC_SUB_REGION0_START (0)
#define SOC_TZPC_DECPROT7CLR_IPF_PSAM_NSEC_SUB_REGION0_END (0)
#define SOC_TZPC_DECPROT7CLR_IPF_NSEC_SUB_REGION0_START (1)
#define SOC_TZPC_DECPROT7CLR_IPF_NSEC_SUB_REGION0_END (1)
#define SOC_TZPC_DECPROT7CLR_IPF_PSAM_SUB_REGION1_START (2)
#define SOC_TZPC_DECPROT7CLR_IPF_PSAM_SUB_REGION1_END (2)
#define SOC_TZPC_DECPROT7CLR_IPF_SUB_REGION1_START (3)
#define SOC_TZPC_DECPROT7CLR_IPF_SUB_REGION1_END (3)
#define SOC_TZPC_DECPROT7CLR_ENABLE_FIREWALL_MAA_START (8)
#define SOC_TZPC_DECPROT7CLR_ENABLE_FIREWALL_MAA_END (8)
#define SOC_TZPC_DECPROT7CLR_ERR_RESP_FIREWALL_MAA_START (9)
#define SOC_TZPC_DECPROT7CLR_ERR_RESP_FIREWALL_MAA_END (9)
#define SOC_TZPC_DECPROT7CLR_MAA_slave_secure_region_START (10)
#define SOC_TZPC_DECPROT7CLR_MAA_slave_secure_region_END (10)
#define SOC_TZPC_DECPROT7CLR_MAA_slave_nsecure_region_START (11)
#define SOC_TZPC_DECPROT7CLR_MAA_slave_nsecure_region_END (11)
#define SOC_TZPC_DECPROT7CLR_MEDIA1_CRG_SUB_REGION0_START (16)
#define SOC_TZPC_DECPROT7CLR_MEDIA1_CRG_SUB_REGION0_END (16)
#define SOC_TZPC_DECPROT7CLR_MEDIA1_CRG_SUB_REGION1_START (17)
#define SOC_TZPC_DECPROT7CLR_MEDIA1_CRG_SUB_REGION1_END (17)
#define SOC_TZPC_DECPROT7CLR_MEDIA1_CRG_SUB_REGION2_START (18)
#define SOC_TZPC_DECPROT7CLR_MEDIA1_CRG_SUB_REGION2_END (18)
#define SOC_TZPC_DECPROT7CLR_MEDIA2_CRG_SUB_REGION0_START (19)
#define SOC_TZPC_DECPROT7CLR_MEDIA2_CRG_SUB_REGION0_END (19)
#define SOC_TZPC_DECPROT7CLR_MEDIA2_CRG_SUB_REGION1_START (20)
#define SOC_TZPC_DECPROT7CLR_MEDIA2_CRG_SUB_REGION1_END (20)
#define SOC_TZPC_DECPROT7CLR_ENABLE_FIREWALL_AXI_MEM_START (24)
#define SOC_TZPC_DECPROT7CLR_ENABLE_FIREWALL_AXI_MEM_END (24)
#define SOC_TZPC_DECPROT7CLR_ERR_RESP_FIREWALL_AXI_MEM_START (25)
#define SOC_TZPC_DECPROT7CLR_ERR_RESP_FIREWALL_AXI_MEM_END (25)
#define SOC_TZPC_DECPROT7CLR_AXI_MEM_slave_secure_region_START (26)
#define SOC_TZPC_DECPROT7CLR_AXI_MEM_slave_secure_region_END (26)
#define SOC_TZPC_DECPROT7CLR_AXI_MEM_slave_nsecure_region_START (27)
#define SOC_TZPC_DECPROT7CLR_AXI_MEM_slave_nsecure_region_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vivobus_firewall : 12;
        unsigned int vcodecbus_firewall : 8;
        unsigned int ddrc_firewall : 8;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_TZPC_DECPROT8STAT_UNION;
#endif
#define SOC_TZPC_DECPROT8STAT_vivobus_firewall_START (0)
#define SOC_TZPC_DECPROT8STAT_vivobus_firewall_END (11)
#define SOC_TZPC_DECPROT8STAT_vcodecbus_firewall_START (12)
#define SOC_TZPC_DECPROT8STAT_vcodecbus_firewall_END (19)
#define SOC_TZPC_DECPROT8STAT_ddrc_firewall_START (20)
#define SOC_TZPC_DECPROT8STAT_ddrc_firewall_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vivobus_firewall : 12;
        unsigned int vcodecbus_firewall : 8;
        unsigned int ddrc_firewall : 8;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_TZPC_DECPROT8SET_UNION;
#endif
#define SOC_TZPC_DECPROT8SET_vivobus_firewall_START (0)
#define SOC_TZPC_DECPROT8SET_vivobus_firewall_END (11)
#define SOC_TZPC_DECPROT8SET_vcodecbus_firewall_START (12)
#define SOC_TZPC_DECPROT8SET_vcodecbus_firewall_END (19)
#define SOC_TZPC_DECPROT8SET_ddrc_firewall_START (20)
#define SOC_TZPC_DECPROT8SET_ddrc_firewall_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vivobus_firewall : 12;
        unsigned int vcodecbus_firewall : 8;
        unsigned int ddrc_firewall : 8;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_TZPC_DECPROT8CLR_UNION;
#endif
#define SOC_TZPC_DECPROT8CLR_vivobus_firewall_START (0)
#define SOC_TZPC_DECPROT8CLR_vivobus_firewall_END (11)
#define SOC_TZPC_DECPROT8CLR_vcodecbus_firewall_START (12)
#define SOC_TZPC_DECPROT8CLR_vcodecbus_firewall_END (19)
#define SOC_TZPC_DECPROT8CLR_ddrc_firewall_START (20)
#define SOC_TZPC_DECPROT8CLR_ddrc_firewall_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_REG0_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_REG1_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_TZPC_PERI_LOCK_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
