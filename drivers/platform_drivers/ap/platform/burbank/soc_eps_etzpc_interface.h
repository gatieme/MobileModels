#ifndef __SOC_ETZPC_INTERFACE_H__
#define __SOC_ETZPC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ETZPC_R0SIZE_ADDR(base) ((base) + (0x000))
#define SOC_ETZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800))
#define SOC_ETZPC_DECPROT0SET_ADDR(base) ((base) + (0x804))
#define SOC_ETZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808))
#define SOC_ETZPC_DECPROT1STAT_ADDR(base) ((base) + (0x80C))
#define SOC_ETZPC_DECPROT1SET_ADDR(base) ((base) + (0x810))
#define SOC_ETZPC_DECPROT1CLR_ADDR(base) ((base) + (0x814))
#define SOC_ETZPC_DECPROT2STAT_ADDR(base) ((base) + (0x818))
#define SOC_ETZPC_DECPROT2SET_ADDR(base) ((base) + (0x81C))
#define SOC_ETZPC_DECPROT2CLR_ADDR(base) ((base) + (0x820))
#define SOC_ETZPC_DECPROT3STAT_ADDR(base) ((base) + (0x824))
#define SOC_ETZPC_DECPROT3SET_ADDR(base) ((base) + (0x828))
#define SOC_ETZPC_DECPROT3CLR_ADDR(base) ((base) + (0x82C))
#define SOC_ETZPC_DECPROT4STAT_ADDR(base) ((base) + (0x830))
#define SOC_ETZPC_DECPROT4SET_ADDR(base) ((base) + (0x834))
#define SOC_ETZPC_DECPROT4CLR_ADDR(base) ((base) + (0x838))
#define SOC_ETZPC_DECPROT5STAT_ADDR(base) ((base) + (0x83C))
#define SOC_ETZPC_DECPROT5SET_ADDR(base) ((base) + (0x840))
#define SOC_ETZPC_DECPROT5CLR_ADDR(base) ((base) + (0x844))
#define SOC_ETZPC_DECPROT6STAT_ADDR(base) ((base) + (0x848))
#define SOC_ETZPC_DECPROT6SET_ADDR(base) ((base) + (0x84C))
#define SOC_ETZPC_DECPROT6CLR_ADDR(base) ((base) + (0x850))
#define SOC_ETZPC_DECPROT7STAT_ADDR(base) ((base) + (0x854))
#define SOC_ETZPC_DECPROT7SET_ADDR(base) ((base) + (0x858))
#define SOC_ETZPC_DECPROT7CLR_ADDR(base) ((base) + (0x85C))
#define SOC_ETZPC_DECPROT8STAT_ADDR(base) ((base) + (0x860))
#define SOC_ETZPC_DECPROT8SET_ADDR(base) ((base) + (0x864))
#define SOC_ETZPC_DECPROT8CLR_ADDR(base) ((base) + (0x868))
#define SOC_ETZPC_REG0_STAT_ADDR(base) ((base) + (0x86C))
#define SOC_ETZPC_REG1_STAT_ADDR(base) ((base) + (0x870))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH0_SEC_ADDR(base) ((base) + (0x874))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH1_SEC_ADDR(base) ((base) + (0x878))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH2_SEC_ADDR(base) ((base) + (0x87C))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH3_SEC_ADDR(base) ((base) + (0x880))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH4_SEC_ADDR(base) ((base) + (0x884))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH5_SEC_ADDR(base) ((base) + (0x888))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH6_SEC_ADDR(base) ((base) + (0x88C))
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH7_SEC_ADDR(base) ((base) + (0x890))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_ETZPC_R0SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tz_secure_km_0 : 1;
        unsigned int tz_secure_km_1 : 1;
        unsigned int tz_secure_km_2 : 1;
        unsigned int tz_secure_km_3 : 1;
        unsigned int tz_secure_sce_0 : 1;
        unsigned int tz_secure_sce_1 : 1;
        unsigned int tz_secure_sce_2 : 1;
        unsigned int tz_secure_sce_3 : 1;
        unsigned int tz_secure_pke_0 : 1;
        unsigned int tz_secure_pke_1 : 1;
        unsigned int tz_secure_pke_2 : 1;
        unsigned int tz_secure_pke_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int tz_secure_sce2_0 : 1;
        unsigned int tz_secure_sce2_1 : 1;
        unsigned int tz_secure_sce2_2 : 1;
        unsigned int tz_secure_sce2_3 : 1;
        unsigned int tz_secure_pke2_0 : 1;
        unsigned int tz_secure_pke2_1 : 1;
        unsigned int tz_secure_pke2_2 : 1;
        unsigned int tz_secure_pke2_3 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
    } reg;
} SOC_ETZPC_DECPROT0STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_0_START (4)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_0_END (4)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_1_START (5)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_1_END (5)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_2_START (6)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_2_END (6)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_3_START (7)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_km_3_END (7)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_0_START (8)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_0_END (8)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_1_START (9)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_1_END (9)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_2_START (10)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_2_END (10)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_3_START (11)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce_3_END (11)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_0_START (12)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_0_END (12)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_1_START (13)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_1_END (13)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_2_START (14)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_2_END (14)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_3_START (15)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke_3_END (15)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_0_START (20)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_0_END (20)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_1_START (21)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_1_END (21)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_2_START (22)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_2_END (22)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_3_START (23)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_sce2_3_END (23)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_0_START (24)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_0_END (24)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_1_START (25)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_1_END (25)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_2_START (26)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_2_END (26)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_3_START (27)
#define SOC_ETZPC_DECPROT0STAT_tz_secure_pke2_3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int km_set_0 : 1;
        unsigned int km_set_1 : 1;
        unsigned int km_set_2 : 1;
        unsigned int km_set_3 : 1;
        unsigned int sce_set_0 : 1;
        unsigned int sce_set_1 : 1;
        unsigned int sce_set_2 : 1;
        unsigned int sce_set_3 : 1;
        unsigned int pke_set_0 : 1;
        unsigned int pke_set_1 : 1;
        unsigned int pke_set_2 : 1;
        unsigned int pke_set_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int sce2_set_0 : 1;
        unsigned int sce2_set_1 : 1;
        unsigned int sce2_set_2 : 1;
        unsigned int sce2_set_3 : 1;
        unsigned int pke2_set_0 : 1;
        unsigned int pke2_set_1 : 1;
        unsigned int pke2_set_2 : 1;
        unsigned int pke2_set_3 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
    } reg;
} SOC_ETZPC_DECPROT0SET_UNION;
#endif
#define SOC_ETZPC_DECPROT0SET_km_set_0_START (4)
#define SOC_ETZPC_DECPROT0SET_km_set_0_END (4)
#define SOC_ETZPC_DECPROT0SET_km_set_1_START (5)
#define SOC_ETZPC_DECPROT0SET_km_set_1_END (5)
#define SOC_ETZPC_DECPROT0SET_km_set_2_START (6)
#define SOC_ETZPC_DECPROT0SET_km_set_2_END (6)
#define SOC_ETZPC_DECPROT0SET_km_set_3_START (7)
#define SOC_ETZPC_DECPROT0SET_km_set_3_END (7)
#define SOC_ETZPC_DECPROT0SET_sce_set_0_START (8)
#define SOC_ETZPC_DECPROT0SET_sce_set_0_END (8)
#define SOC_ETZPC_DECPROT0SET_sce_set_1_START (9)
#define SOC_ETZPC_DECPROT0SET_sce_set_1_END (9)
#define SOC_ETZPC_DECPROT0SET_sce_set_2_START (10)
#define SOC_ETZPC_DECPROT0SET_sce_set_2_END (10)
#define SOC_ETZPC_DECPROT0SET_sce_set_3_START (11)
#define SOC_ETZPC_DECPROT0SET_sce_set_3_END (11)
#define SOC_ETZPC_DECPROT0SET_pke_set_0_START (12)
#define SOC_ETZPC_DECPROT0SET_pke_set_0_END (12)
#define SOC_ETZPC_DECPROT0SET_pke_set_1_START (13)
#define SOC_ETZPC_DECPROT0SET_pke_set_1_END (13)
#define SOC_ETZPC_DECPROT0SET_pke_set_2_START (14)
#define SOC_ETZPC_DECPROT0SET_pke_set_2_END (14)
#define SOC_ETZPC_DECPROT0SET_pke_set_3_START (15)
#define SOC_ETZPC_DECPROT0SET_pke_set_3_END (15)
#define SOC_ETZPC_DECPROT0SET_sce2_set_0_START (20)
#define SOC_ETZPC_DECPROT0SET_sce2_set_0_END (20)
#define SOC_ETZPC_DECPROT0SET_sce2_set_1_START (21)
#define SOC_ETZPC_DECPROT0SET_sce2_set_1_END (21)
#define SOC_ETZPC_DECPROT0SET_sce2_set_2_START (22)
#define SOC_ETZPC_DECPROT0SET_sce2_set_2_END (22)
#define SOC_ETZPC_DECPROT0SET_sce2_set_3_START (23)
#define SOC_ETZPC_DECPROT0SET_sce2_set_3_END (23)
#define SOC_ETZPC_DECPROT0SET_pke2_set_0_START (24)
#define SOC_ETZPC_DECPROT0SET_pke2_set_0_END (24)
#define SOC_ETZPC_DECPROT0SET_pke2_set_1_START (25)
#define SOC_ETZPC_DECPROT0SET_pke2_set_1_END (25)
#define SOC_ETZPC_DECPROT0SET_pke2_set_2_START (26)
#define SOC_ETZPC_DECPROT0SET_pke2_set_2_END (26)
#define SOC_ETZPC_DECPROT0SET_pke2_set_3_START (27)
#define SOC_ETZPC_DECPROT0SET_pke2_set_3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int km_clr_0 : 1;
        unsigned int km_clr_1 : 1;
        unsigned int km_clr_2 : 1;
        unsigned int km_clr_3 : 1;
        unsigned int sce_clr_0 : 1;
        unsigned int sce_clr_1 : 1;
        unsigned int sce_clr_2 : 1;
        unsigned int sce_clr_3 : 1;
        unsigned int pke_clr_0 : 1;
        unsigned int pke_clr_1 : 1;
        unsigned int pke_clr_2 : 1;
        unsigned int pke_clr_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int sce2_clr_0 : 1;
        unsigned int sce2_clr_1 : 1;
        unsigned int sce2_clr_2 : 1;
        unsigned int sce2_clr_3 : 1;
        unsigned int pke2_clr_0 : 1;
        unsigned int pke2_clr_1 : 1;
        unsigned int pke2_clr_2 : 1;
        unsigned int pke2_clr_3 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
    } reg;
} SOC_ETZPC_DECPROT0CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT0CLR_km_clr_0_START (4)
#define SOC_ETZPC_DECPROT0CLR_km_clr_0_END (4)
#define SOC_ETZPC_DECPROT0CLR_km_clr_1_START (5)
#define SOC_ETZPC_DECPROT0CLR_km_clr_1_END (5)
#define SOC_ETZPC_DECPROT0CLR_km_clr_2_START (6)
#define SOC_ETZPC_DECPROT0CLR_km_clr_2_END (6)
#define SOC_ETZPC_DECPROT0CLR_km_clr_3_START (7)
#define SOC_ETZPC_DECPROT0CLR_km_clr_3_END (7)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_0_START (8)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_0_END (8)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_1_START (9)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_1_END (9)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_2_START (10)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_2_END (10)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_3_START (11)
#define SOC_ETZPC_DECPROT0CLR_sce_clr_3_END (11)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_0_START (12)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_0_END (12)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_1_START (13)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_1_END (13)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_2_START (14)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_2_END (14)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_3_START (15)
#define SOC_ETZPC_DECPROT0CLR_pke_clr_3_END (15)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_0_START (20)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_0_END (20)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_1_START (21)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_1_END (21)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_2_START (22)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_2_END (22)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_3_START (23)
#define SOC_ETZPC_DECPROT0CLR_sce2_clr_3_END (23)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_0_START (24)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_0_END (24)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_1_START (25)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_1_END (25)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_2_START (26)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_2_END (26)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_3_START (27)
#define SOC_ETZPC_DECPROT0CLR_pke2_clr_3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int config_state_0 : 1;
        unsigned int config_state_1 : 1;
        unsigned int config_state_2 : 1;
        unsigned int config_state_3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int trng_state_0 : 1;
        unsigned int trng_state_1 : 1;
        unsigned int trng_state_2 : 1;
        unsigned int trng_state_3 : 1;
        unsigned int timer_state_0 : 1;
        unsigned int timer_state_1 : 1;
        unsigned int timer_state_2 : 1;
        unsigned int timer_state_3 : 1;
        unsigned int tz_secure_mmu_0 : 1;
        unsigned int tz_secure_mmu_1 : 1;
        unsigned int tz_secure_mmu_2 : 1;
        unsigned int tz_secure_mmu_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_ETZPC_DECPROT1STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT1STAT_config_state_0_START (0)
#define SOC_ETZPC_DECPROT1STAT_config_state_0_END (0)
#define SOC_ETZPC_DECPROT1STAT_config_state_1_START (1)
#define SOC_ETZPC_DECPROT1STAT_config_state_1_END (1)
#define SOC_ETZPC_DECPROT1STAT_config_state_2_START (2)
#define SOC_ETZPC_DECPROT1STAT_config_state_2_END (2)
#define SOC_ETZPC_DECPROT1STAT_config_state_3_START (3)
#define SOC_ETZPC_DECPROT1STAT_config_state_3_END (3)
#define SOC_ETZPC_DECPROT1STAT_trng_state_0_START (8)
#define SOC_ETZPC_DECPROT1STAT_trng_state_0_END (8)
#define SOC_ETZPC_DECPROT1STAT_trng_state_1_START (9)
#define SOC_ETZPC_DECPROT1STAT_trng_state_1_END (9)
#define SOC_ETZPC_DECPROT1STAT_trng_state_2_START (10)
#define SOC_ETZPC_DECPROT1STAT_trng_state_2_END (10)
#define SOC_ETZPC_DECPROT1STAT_trng_state_3_START (11)
#define SOC_ETZPC_DECPROT1STAT_trng_state_3_END (11)
#define SOC_ETZPC_DECPROT1STAT_timer_state_0_START (12)
#define SOC_ETZPC_DECPROT1STAT_timer_state_0_END (12)
#define SOC_ETZPC_DECPROT1STAT_timer_state_1_START (13)
#define SOC_ETZPC_DECPROT1STAT_timer_state_1_END (13)
#define SOC_ETZPC_DECPROT1STAT_timer_state_2_START (14)
#define SOC_ETZPC_DECPROT1STAT_timer_state_2_END (14)
#define SOC_ETZPC_DECPROT1STAT_timer_state_3_START (15)
#define SOC_ETZPC_DECPROT1STAT_timer_state_3_END (15)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_0_START (16)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_0_END (16)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_1_START (17)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_1_END (17)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_2_START (18)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_2_END (18)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_3_START (19)
#define SOC_ETZPC_DECPROT1STAT_tz_secure_mmu_3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int config_set_0 : 1;
        unsigned int config_set_1 : 1;
        unsigned int config_set_2 : 1;
        unsigned int config_set_3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int trng_set_0 : 1;
        unsigned int trng_set_1 : 1;
        unsigned int trng_set_2 : 1;
        unsigned int trng_set_3 : 1;
        unsigned int timer_set_0 : 1;
        unsigned int timer_set_1 : 1;
        unsigned int timer_set_2 : 1;
        unsigned int timer_set_3 : 1;
        unsigned int mmu_set_0 : 1;
        unsigned int mmu_set_1 : 1;
        unsigned int mmu_set_2 : 1;
        unsigned int mmu_set_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_ETZPC_DECPROT1SET_UNION;
#endif
#define SOC_ETZPC_DECPROT1SET_config_set_0_START (0)
#define SOC_ETZPC_DECPROT1SET_config_set_0_END (0)
#define SOC_ETZPC_DECPROT1SET_config_set_1_START (1)
#define SOC_ETZPC_DECPROT1SET_config_set_1_END (1)
#define SOC_ETZPC_DECPROT1SET_config_set_2_START (2)
#define SOC_ETZPC_DECPROT1SET_config_set_2_END (2)
#define SOC_ETZPC_DECPROT1SET_config_set_3_START (3)
#define SOC_ETZPC_DECPROT1SET_config_set_3_END (3)
#define SOC_ETZPC_DECPROT1SET_trng_set_0_START (8)
#define SOC_ETZPC_DECPROT1SET_trng_set_0_END (8)
#define SOC_ETZPC_DECPROT1SET_trng_set_1_START (9)
#define SOC_ETZPC_DECPROT1SET_trng_set_1_END (9)
#define SOC_ETZPC_DECPROT1SET_trng_set_2_START (10)
#define SOC_ETZPC_DECPROT1SET_trng_set_2_END (10)
#define SOC_ETZPC_DECPROT1SET_trng_set_3_START (11)
#define SOC_ETZPC_DECPROT1SET_trng_set_3_END (11)
#define SOC_ETZPC_DECPROT1SET_timer_set_0_START (12)
#define SOC_ETZPC_DECPROT1SET_timer_set_0_END (12)
#define SOC_ETZPC_DECPROT1SET_timer_set_1_START (13)
#define SOC_ETZPC_DECPROT1SET_timer_set_1_END (13)
#define SOC_ETZPC_DECPROT1SET_timer_set_2_START (14)
#define SOC_ETZPC_DECPROT1SET_timer_set_2_END (14)
#define SOC_ETZPC_DECPROT1SET_timer_set_3_START (15)
#define SOC_ETZPC_DECPROT1SET_timer_set_3_END (15)
#define SOC_ETZPC_DECPROT1SET_mmu_set_0_START (16)
#define SOC_ETZPC_DECPROT1SET_mmu_set_0_END (16)
#define SOC_ETZPC_DECPROT1SET_mmu_set_1_START (17)
#define SOC_ETZPC_DECPROT1SET_mmu_set_1_END (17)
#define SOC_ETZPC_DECPROT1SET_mmu_set_2_START (18)
#define SOC_ETZPC_DECPROT1SET_mmu_set_2_END (18)
#define SOC_ETZPC_DECPROT1SET_mmu_set_3_START (19)
#define SOC_ETZPC_DECPROT1SET_mmu_set_3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int config_clr_0 : 1;
        unsigned int config_clr_1 : 1;
        unsigned int config_clr_2 : 1;
        unsigned int config_clr_3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int trng_clr_0 : 1;
        unsigned int trng_clr_1 : 1;
        unsigned int trng_clr_2 : 1;
        unsigned int trng_clr_3 : 1;
        unsigned int timer_clr_0 : 1;
        unsigned int timer_clr_1 : 1;
        unsigned int timer_clr_2 : 1;
        unsigned int timer_clr_3 : 1;
        unsigned int mmu_clr_0 : 1;
        unsigned int mmu_clr_1 : 1;
        unsigned int mmu_clr_2 : 1;
        unsigned int mmu_clr_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
    } reg;
} SOC_ETZPC_DECPROT1CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT1CLR_config_clr_0_START (0)
#define SOC_ETZPC_DECPROT1CLR_config_clr_0_END (0)
#define SOC_ETZPC_DECPROT1CLR_config_clr_1_START (1)
#define SOC_ETZPC_DECPROT1CLR_config_clr_1_END (1)
#define SOC_ETZPC_DECPROT1CLR_config_clr_2_START (2)
#define SOC_ETZPC_DECPROT1CLR_config_clr_2_END (2)
#define SOC_ETZPC_DECPROT1CLR_config_clr_3_START (3)
#define SOC_ETZPC_DECPROT1CLR_config_clr_3_END (3)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_0_START (8)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_0_END (8)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_1_START (9)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_1_END (9)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_2_START (10)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_2_END (10)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_3_START (11)
#define SOC_ETZPC_DECPROT1CLR_trng_clr_3_END (11)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_0_START (12)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_0_END (12)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_1_START (13)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_1_END (13)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_2_START (14)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_2_END (14)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_3_START (15)
#define SOC_ETZPC_DECPROT1CLR_timer_clr_3_END (15)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_0_START (16)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_0_END (16)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_1_START (17)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_1_END (17)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_2_START (18)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_2_END (18)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_3_START (19)
#define SOC_ETZPC_DECPROT1CLR_mmu_clr_3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT2STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT2SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT2CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT3STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT3SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT3CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_sce_axi_mst_wr_stat_0 : 1;
        unsigned int tz_sce_axi_mst_wr_stat_1 : 1;
        unsigned int tz_sce_axi_mst_wr_stat_2 : 1;
        unsigned int tz_sce_axi_mst_rd_stat_0 : 1;
        unsigned int tz_sce_axi_mst_rd_stat_1 : 1;
        unsigned int tz_sce_axi_mst_rd_stat_2 : 1;
        unsigned int tz_sce2_axi_mst_wr_stat_0 : 1;
        unsigned int tz_sce2_axi_mst_wr_stat_1 : 1;
        unsigned int tz_sce2_axi_mst_wr_stat_2 : 1;
        unsigned int tz_sce2_axi_mst_rd_stat_0 : 1;
        unsigned int tz_sce2_axi_mst_rd_stat_1 : 1;
        unsigned int tz_sce2_axi_mst_rd_stat_2 : 1;
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
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_ETZPC_DECPROT4STAT_UNION;
#endif
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_0_START (0)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_0_END (0)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_1_START (1)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_1_END (1)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_2_START (2)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_wr_stat_2_END (2)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_0_START (3)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_0_END (3)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_1_START (4)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_1_END (4)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_2_START (5)
#define SOC_ETZPC_DECPROT4STAT_tz_sce_axi_mst_rd_stat_2_END (5)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_wr_stat_0_START (6)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_wr_stat_0_END (6)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_wr_stat_1_START (7)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_wr_stat_1_END (7)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_wr_stat_2_START (8)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_wr_stat_2_END (8)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_rd_stat_0_START (9)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_rd_stat_0_END (9)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_rd_stat_1_START (10)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_rd_stat_1_END (10)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_rd_stat_2_START (11)
#define SOC_ETZPC_DECPROT4STAT_tz_sce2_axi_mst_rd_stat_2_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_sce_axi_mst_wr_set_0 : 1;
        unsigned int tz_sce_axi_mst_wr_set_1 : 1;
        unsigned int tz_sce_axi_mst_wr_set_2 : 1;
        unsigned int tz_sce_axi_mst_rd_set_0 : 1;
        unsigned int tz_sce_axi_mst_rd_set_1 : 1;
        unsigned int tz_sce_axi_mst_rd_set_2 : 1;
        unsigned int tz_sce2_axi_mst_wr_set_0 : 1;
        unsigned int tz_sce2_axi_mst_wr_set_1 : 1;
        unsigned int tz_sce2_axi_mst_wr_set_2 : 1;
        unsigned int tz_sce2_axi_mst_rd_set_0 : 1;
        unsigned int tz_sce2_axi_mst_rd_set_1 : 1;
        unsigned int tz_sce2_axi_mst_rd_set_2 : 1;
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
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_ETZPC_DECPROT4SET_UNION;
#endif
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_0_START (0)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_0_END (0)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_1_START (1)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_1_END (1)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_2_START (2)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_wr_set_2_END (2)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_0_START (3)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_0_END (3)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_1_START (4)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_1_END (4)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_2_START (5)
#define SOC_ETZPC_DECPROT4SET_tz_sce_axi_mst_rd_set_2_END (5)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_wr_set_0_START (6)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_wr_set_0_END (6)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_wr_set_1_START (7)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_wr_set_1_END (7)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_wr_set_2_START (8)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_wr_set_2_END (8)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_rd_set_0_START (9)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_rd_set_0_END (9)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_rd_set_1_START (10)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_rd_set_1_END (10)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_rd_set_2_START (11)
#define SOC_ETZPC_DECPROT4SET_tz_sce2_axi_mst_rd_set_2_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tz_sce_axi_mst_wr_clr_0 : 1;
        unsigned int tz_sce_axi_mst_wr_clr_1 : 1;
        unsigned int tz_sce_axi_mst_wr_clr_2 : 1;
        unsigned int tz_sce_axi_mst_rd_clr_0 : 1;
        unsigned int tz_sce_axi_mst_rd_clr_1 : 1;
        unsigned int tz_sce_axi_mst_rd_clr_2 : 1;
        unsigned int tz_sce2_axi_mst_wr_clr_0 : 1;
        unsigned int tz_sce2_axi_mst_wr_clr_1 : 1;
        unsigned int tz_sce2_axi_mst_wr_clr_2 : 1;
        unsigned int tz_sce2_axi_mst_rd_clr_0 : 1;
        unsigned int tz_sce2_axi_mst_rd_clr_1 : 1;
        unsigned int tz_sce2_axi_mst_rd_clr_2 : 1;
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
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
    } reg;
} SOC_ETZPC_DECPROT4CLR_UNION;
#endif
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_0_START (0)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_0_END (0)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_1_START (1)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_1_END (1)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_2_START (2)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_wr_clr_2_END (2)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_0_START (3)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_0_END (3)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_1_START (4)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_1_END (4)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_2_START (5)
#define SOC_ETZPC_DECPROT4CLR_tz_sce_axi_mst_rd_clr_2_END (5)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_wr_clr_0_START (6)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_wr_clr_0_END (6)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_wr_clr_1_START (7)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_wr_clr_1_END (7)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_wr_clr_2_START (8)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_wr_clr_2_END (8)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_rd_clr_0_START (9)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_rd_clr_0_END (9)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_rd_clr_1_START (10)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_rd_clr_1_END (10)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_rd_clr_2_START (11)
#define SOC_ETZPC_DECPROT4CLR_tz_sce2_axi_mst_rd_clr_2_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT5STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT5SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT5CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT6STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT6SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
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
        unsigned int reserved_29: 1;
        unsigned int reserved_30: 1;
        unsigned int reserved_31: 1;
    } reg;
} SOC_ETZPC_DECPROT6CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 28;
    } reg;
} SOC_ETZPC_DECPROT7STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 28;
    } reg;
} SOC_ETZPC_DECPROT7SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 28;
    } reg;
} SOC_ETZPC_DECPROT7CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 23;
        unsigned int reserved_2: 1;
    } reg;
} SOC_ETZPC_DECPROT8STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 23;
        unsigned int reserved_2: 1;
    } reg;
} SOC_ETZPC_DECPROT8SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 23;
        unsigned int reserved_2: 1;
    } reg;
} SOC_ETZPC_DECPROT8CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_ETZPC_REG0_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_ETZPC_REG1_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch0_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH0_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH0_SEC_efusec2hieps_patch0_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH0_SEC_efusec2hieps_patch0_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch1_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH1_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH1_SEC_efusec2hieps_patch1_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH1_SEC_efusec2hieps_patch1_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch2_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH2_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH2_SEC_efusec2hieps_patch2_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH2_SEC_efusec2hieps_patch2_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch3_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH3_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH3_SEC_efusec2hieps_patch3_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH3_SEC_efusec2hieps_patch3_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch4_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH4_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH4_SEC_efusec2hieps_patch4_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH4_SEC_efusec2hieps_patch4_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch5_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH5_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH5_SEC_efusec2hieps_patch5_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH5_SEC_efusec2hieps_patch5_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch6_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH6_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH6_SEC_efusec2hieps_patch6_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH6_SEC_efusec2hieps_patch6_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec2hieps_patch7_sec : 32;
    } reg;
} SOC_ETZPC_EFUSEC2HIEPS_PATCH7_SEC_UNION;
#endif
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH7_SEC_efusec2hieps_patch7_sec_START (0)
#define SOC_ETZPC_EFUSEC2HIEPS_PATCH7_SEC_efusec2hieps_patch7_sec_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
