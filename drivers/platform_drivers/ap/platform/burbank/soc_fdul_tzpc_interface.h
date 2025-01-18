#ifndef __SOC_FDUL_TZPC_INTERFACE_H__
#define __SOC_FDUL_TZPC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FDUL_TZPC_R0SIZE_ADDR(base) ((base) + (0x000UL))
#define SOC_FDUL_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800UL))
#define SOC_FDUL_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804UL))
#define SOC_FDUL_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808UL))
#define SOC_FDUL_TZPC_DECPROT1STAT_ADDR(base) ((base) + (0x80CUL))
#define SOC_FDUL_TZPC_DECPROT1SET_ADDR(base) ((base) + (0x810UL))
#define SOC_FDUL_TZPC_DECPROT1CLR_ADDR(base) ((base) + (0x814UL))
#define SOC_FDUL_TZPC_DECPROT2STAT_ADDR(base) ((base) + (0x818UL))
#define SOC_FDUL_TZPC_DECPROT2SET_ADDR(base) ((base) + (0x81CUL))
#define SOC_FDUL_TZPC_DECPROT2CLR_ADDR(base) ((base) + (0x820UL))
#define SOC_FDUL_TZPC_DECPROT3STAT_ADDR(base) ((base) + (0x824UL))
#define SOC_FDUL_TZPC_DECPROT3SET_ADDR(base) ((base) + (0x828UL))
#define SOC_FDUL_TZPC_DECPROT3CLR_ADDR(base) ((base) + (0x82CUL))
#define SOC_FDUL_TZPC_DECPROT4STAT_ADDR(base) ((base) + (0x830UL))
#define SOC_FDUL_TZPC_DECPROT4SET_ADDR(base) ((base) + (0x834UL))
#define SOC_FDUL_TZPC_DECPROT4CLR_ADDR(base) ((base) + (0x838UL))
#define SOC_FDUL_TZPC_DECPROT5STAT_ADDR(base) ((base) + (0x83CUL))
#define SOC_FDUL_TZPC_DECPROT5SET_ADDR(base) ((base) + (0x840UL))
#define SOC_FDUL_TZPC_DECPROT5CLR_ADDR(base) ((base) + (0x844UL))
#define SOC_FDUL_TZPC_DECPROT6STAT_ADDR(base) ((base) + (0x848UL))
#define SOC_FDUL_TZPC_DECPROT6SET_ADDR(base) ((base) + (0x84CUL))
#define SOC_FDUL_TZPC_DECPROT6CLR_ADDR(base) ((base) + (0x850UL))
#define SOC_FDUL_TZPC_DECPROT7STAT_ADDR(base) ((base) + (0x854UL))
#define SOC_FDUL_TZPC_DECPROT7SET_ADDR(base) ((base) + (0x858UL))
#define SOC_FDUL_TZPC_DECPROT7CLR_ADDR(base) ((base) + (0x85CUL))
#define SOC_FDUL_TZPC_DECPROT8STAT_ADDR(base) ((base) + (0x860UL))
#define SOC_FDUL_TZPC_DECPROT8SET_ADDR(base) ((base) + (0x864UL))
#define SOC_FDUL_TZPC_DECPROT8CLR_ADDR(base) ((base) + (0x868UL))
#define SOC_FDUL_TZPC_REG0_STAT_ADDR(base) ((base) + (0x86CUL))
#define SOC_FDUL_TZPC_REG1_STAT_ADDR(base) ((base) + (0x870UL))
#else
#define SOC_FDUL_TZPC_R0SIZE_ADDR(base) ((base) + (0x000))
#define SOC_FDUL_TZPC_DECPROT0STAT_ADDR(base) ((base) + (0x800))
#define SOC_FDUL_TZPC_DECPROT0SET_ADDR(base) ((base) + (0x804))
#define SOC_FDUL_TZPC_DECPROT0CLR_ADDR(base) ((base) + (0x808))
#define SOC_FDUL_TZPC_DECPROT1STAT_ADDR(base) ((base) + (0x80C))
#define SOC_FDUL_TZPC_DECPROT1SET_ADDR(base) ((base) + (0x810))
#define SOC_FDUL_TZPC_DECPROT1CLR_ADDR(base) ((base) + (0x814))
#define SOC_FDUL_TZPC_DECPROT2STAT_ADDR(base) ((base) + (0x818))
#define SOC_FDUL_TZPC_DECPROT2SET_ADDR(base) ((base) + (0x81C))
#define SOC_FDUL_TZPC_DECPROT2CLR_ADDR(base) ((base) + (0x820))
#define SOC_FDUL_TZPC_DECPROT3STAT_ADDR(base) ((base) + (0x824))
#define SOC_FDUL_TZPC_DECPROT3SET_ADDR(base) ((base) + (0x828))
#define SOC_FDUL_TZPC_DECPROT3CLR_ADDR(base) ((base) + (0x82C))
#define SOC_FDUL_TZPC_DECPROT4STAT_ADDR(base) ((base) + (0x830))
#define SOC_FDUL_TZPC_DECPROT4SET_ADDR(base) ((base) + (0x834))
#define SOC_FDUL_TZPC_DECPROT4CLR_ADDR(base) ((base) + (0x838))
#define SOC_FDUL_TZPC_DECPROT5STAT_ADDR(base) ((base) + (0x83C))
#define SOC_FDUL_TZPC_DECPROT5SET_ADDR(base) ((base) + (0x840))
#define SOC_FDUL_TZPC_DECPROT5CLR_ADDR(base) ((base) + (0x844))
#define SOC_FDUL_TZPC_DECPROT6STAT_ADDR(base) ((base) + (0x848))
#define SOC_FDUL_TZPC_DECPROT6SET_ADDR(base) ((base) + (0x84C))
#define SOC_FDUL_TZPC_DECPROT6CLR_ADDR(base) ((base) + (0x850))
#define SOC_FDUL_TZPC_DECPROT7STAT_ADDR(base) ((base) + (0x854))
#define SOC_FDUL_TZPC_DECPROT7SET_ADDR(base) ((base) + (0x858))
#define SOC_FDUL_TZPC_DECPROT7CLR_ADDR(base) ((base) + (0x85C))
#define SOC_FDUL_TZPC_DECPROT8STAT_ADDR(base) ((base) + (0x860))
#define SOC_FDUL_TZPC_DECPROT8SET_ADDR(base) ((base) + (0x864))
#define SOC_FDUL_TZPC_DECPROT8CLR_ADDR(base) ((base) + (0x868))
#define SOC_FDUL_TZPC_REG0_STAT_ADDR(base) ((base) + (0x86C))
#define SOC_FDUL_TZPC_REG1_STAT_ADDR(base) ((base) + (0x870))
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
} SOC_FDUL_TZPC_R0SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ao_tzpcdecprot0 : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT0STAT_UNION;
#endif
#define SOC_FDUL_TZPC_DECPROT0STAT_ao_tzpcdecprot0_START (0)
#define SOC_FDUL_TZPC_DECPROT0STAT_ao_tzpcdecprot0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ao_tzpcdecprot0 : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT0SET_UNION;
#endif
#define SOC_FDUL_TZPC_DECPROT0SET_ao_tzpcdecprot0_START (0)
#define SOC_FDUL_TZPC_DECPROT0SET_ao_tzpcdecprot0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ao_tzpcdecprot0 : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT0CLR_UNION;
#endif
#define SOC_FDUL_TZPC_DECPROT0CLR_ao_tzpcdecprot0_START (0)
#define SOC_FDUL_TZPC_DECPROT0CLR_ao_tzpcdecprot0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT1STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT1SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT1CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT2STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT2SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT2CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT3STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT3SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT3CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT4STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT4SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT4CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT5STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT5SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT5CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT6STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT6SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT6CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT7STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT7SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT7CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT8STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT8SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_DECPROT8CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_REG0_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FDUL_TZPC_REG1_STAT_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
