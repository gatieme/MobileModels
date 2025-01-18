#ifndef __SOC_FDUL_DMMU_INTERFACE_H__
#define __SOC_FDUL_DMMU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC0_ADDR(base) ((base) + (0x800UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC1_ADDR(base) ((base) + (0x804UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC2_ADDR(base) ((base) + (0x808UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC3_ADDR(base) ((base) + (0x80CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC4_ADDR(base) ((base) + (0x810UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC5_ADDR(base) ((base) + (0x814UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC6_ADDR(base) ((base) + (0x818UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC7_ADDR(base) ((base) + (0x81CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN0_ADDR(base) ((base) + (0x820UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN1_ADDR(base) ((base) + (0x824UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN2_ADDR(base) ((base) + (0x828UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN3_ADDR(base) ((base) + (0x82CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN4_ADDR(base) ((base) + (0x830UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN5_ADDR(base) ((base) + (0x834UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN6_ADDR(base) ((base) + (0x838UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN7_ADDR(base) ((base) + (0x83CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST0_ADDR(base) ((base) + (0x840UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST1_ADDR(base) ((base) + (0x844UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST2_ADDR(base) ((base) + (0x848UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST3_ADDR(base) ((base) + (0x84CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST4_ADDR(base) ((base) + (0x850UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST5_ADDR(base) ((base) + (0x854UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST6_ADDR(base) ((base) + (0x858UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST7_ADDR(base) ((base) + (0x85CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_ADDR_DEFAULT_ADDR(base) ((base) + (0x860UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC8_ADDR(base) ((base) + (0x900UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC9_ADDR(base) ((base) + (0x904UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC10_ADDR(base) ((base) + (0x908UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC11_ADDR(base) ((base) + (0x90cUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC12_ADDR(base) ((base) + (0x910UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC13_ADDR(base) ((base) + (0x914UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC14_ADDR(base) ((base) + (0x918UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC15_ADDR(base) ((base) + (0x91cUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN8_ADDR(base) ((base) + (0x920UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN9_ADDR(base) ((base) + (0x924UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN10_ADDR(base) ((base) + (0x928UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN11_ADDR(base) ((base) + (0x92CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN12_ADDR(base) ((base) + (0x930UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN13_ADDR(base) ((base) + (0x934UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN14_ADDR(base) ((base) + (0x938UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN15_ADDR(base) ((base) + (0x93CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST8_ADDR(base) ((base) + (0x940UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST9_ADDR(base) ((base) + (0x944UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST10_ADDR(base) ((base) + (0x948UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST11_ADDR(base) ((base) + (0x94CUL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST12_ADDR(base) ((base) + (0x950UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST13_ADDR(base) ((base) + (0x954UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST14_ADDR(base) ((base) + (0x958UL))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST15_ADDR(base) ((base) + (0x95CUL))
#else
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC0_ADDR(base) ((base) + (0x800))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC1_ADDR(base) ((base) + (0x804))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC2_ADDR(base) ((base) + (0x808))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC3_ADDR(base) ((base) + (0x80C))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC4_ADDR(base) ((base) + (0x810))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC5_ADDR(base) ((base) + (0x814))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC6_ADDR(base) ((base) + (0x818))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC7_ADDR(base) ((base) + (0x81C))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN0_ADDR(base) ((base) + (0x820))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN1_ADDR(base) ((base) + (0x824))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN2_ADDR(base) ((base) + (0x828))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN3_ADDR(base) ((base) + (0x82C))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN4_ADDR(base) ((base) + (0x830))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN5_ADDR(base) ((base) + (0x834))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN6_ADDR(base) ((base) + (0x838))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN7_ADDR(base) ((base) + (0x83C))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST0_ADDR(base) ((base) + (0x840))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST1_ADDR(base) ((base) + (0x844))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST2_ADDR(base) ((base) + (0x848))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST3_ADDR(base) ((base) + (0x84C))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST4_ADDR(base) ((base) + (0x850))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST5_ADDR(base) ((base) + (0x854))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST6_ADDR(base) ((base) + (0x858))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST7_ADDR(base) ((base) + (0x85C))
#define SOC_FDUL_DMMU_FAMA_REMAP_ADDR_DEFAULT_ADDR(base) ((base) + (0x860))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC8_ADDR(base) ((base) + (0x900))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC9_ADDR(base) ((base) + (0x904))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC10_ADDR(base) ((base) + (0x908))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC11_ADDR(base) ((base) + (0x90c))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC12_ADDR(base) ((base) + (0x910))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC13_ADDR(base) ((base) + (0x914))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC14_ADDR(base) ((base) + (0x918))
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC15_ADDR(base) ((base) + (0x91c))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN8_ADDR(base) ((base) + (0x920))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN9_ADDR(base) ((base) + (0x924))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN10_ADDR(base) ((base) + (0x928))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN11_ADDR(base) ((base) + (0x92C))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN12_ADDR(base) ((base) + (0x930))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN13_ADDR(base) ((base) + (0x934))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN14_ADDR(base) ((base) + (0x938))
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN15_ADDR(base) ((base) + (0x93C))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST8_ADDR(base) ((base) + (0x940))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST9_ADDR(base) ((base) + (0x944))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST10_ADDR(base) ((base) + (0x948))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST11_ADDR(base) ((base) + (0x94C))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST12_ADDR(base) ((base) + (0x950))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST13_ADDR(base) ((base) + (0x954))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST14_ADDR(base) ((base) + (0x958))
#define SOC_FDUL_DMMU_FAMA_REMAP_DST15_ADDR(base) ((base) + (0x95C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC0_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC0_icfg_addr_src0_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC0_icfg_addr_src0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC1_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC1_icfg_addr_src1_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC1_icfg_addr_src1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC2_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC2_icfg_addr_src2_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC2_icfg_addr_src2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC3_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC3_icfg_addr_src3_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC3_icfg_addr_src3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC4_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC4_icfg_addr_src4_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC4_icfg_addr_src4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC5_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC5_icfg_addr_src5_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC5_icfg_addr_src5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC6_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC6_icfg_addr_src6_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC6_icfg_addr_src6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC7_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC7_icfg_addr_src7_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC7_icfg_addr_src7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN0_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN0_icfg_addr_len0_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN0_icfg_addr_len0_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN1_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN1_icfg_addr_len1_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN1_icfg_addr_len1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len2 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN2_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN2_icfg_addr_len2_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN2_icfg_addr_len2_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len3 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN3_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN3_icfg_addr_len3_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN3_icfg_addr_len3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len4 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN4_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN4_icfg_addr_len4_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN4_icfg_addr_len4_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len5 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN5_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN5_icfg_addr_len5_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN5_icfg_addr_len5_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len6 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN6_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN6_icfg_addr_len6_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN6_icfg_addr_len6_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len7 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN7_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN7_icfg_addr_len7_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN7_icfg_addr_len7_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst0 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST0_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST0_icfg_addr_dst0_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST0_icfg_addr_dst0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst1 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST1_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST1_icfg_addr_dst1_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST1_icfg_addr_dst1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst2 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST2_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST2_icfg_addr_dst2_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST2_icfg_addr_dst2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst3 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST3_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST3_icfg_addr_dst3_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST3_icfg_addr_dst3_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst4 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST4_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST4_icfg_addr_dst4_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST4_icfg_addr_dst4_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst5 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST5_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST5_icfg_addr_dst5_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST5_icfg_addr_dst5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst6 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST6_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST6_icfg_addr_dst6_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST6_icfg_addr_dst6_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst7 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST7_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST7_icfg_addr_dst7_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST7_icfg_addr_dst7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_default : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_ADDR_DEFAULT_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_ADDR_DEFAULT_icfg_addr_default_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_ADDR_DEFAULT_icfg_addr_default_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src8 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC8_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC8_icfg_addr_src8_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC8_icfg_addr_src8_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src9 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC9_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC9_icfg_addr_src9_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC9_icfg_addr_src9_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src10 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC10_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC10_icfg_addr_src10_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC10_icfg_addr_src10_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src11 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC11_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC11_icfg_addr_src11_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC11_icfg_addr_src11_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src12 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC12_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC12_icfg_addr_src12_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC12_icfg_addr_src12_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src13 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC13_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC13_icfg_addr_src13_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC13_icfg_addr_src13_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src14 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC14_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC14_icfg_addr_src14_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC14_icfg_addr_src14_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_src15 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_SRC15_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC15_icfg_addr_src15_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_SRC15_icfg_addr_src15_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len8 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN8_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN8_icfg_addr_len8_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN8_icfg_addr_len8_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len9 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN9_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN9_icfg_addr_len9_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN9_icfg_addr_len9_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len10 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN10_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN10_icfg_addr_len10_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN10_icfg_addr_len10_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len11 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN11_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN11_icfg_addr_len11_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN11_icfg_addr_len11_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len12 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN12_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN12_icfg_addr_len12_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN12_icfg_addr_len12_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len13 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN13_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN13_icfg_addr_len13_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN13_icfg_addr_len13_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len14 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN14_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN14_icfg_addr_len14_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN14_icfg_addr_len14_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_len15 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_LEN15_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN15_icfg_addr_len15_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_LEN15_icfg_addr_len15_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst8 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST8_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST8_icfg_addr_dst8_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST8_icfg_addr_dst8_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst9 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST9_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST9_icfg_addr_dst9_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST9_icfg_addr_dst9_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst10 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST10_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST10_icfg_addr_dst10_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST10_icfg_addr_dst10_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst11 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST11_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST11_icfg_addr_dst11_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST11_icfg_addr_dst11_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst12 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST12_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST12_icfg_addr_dst12_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST12_icfg_addr_dst12_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst13 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST13_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST13_icfg_addr_dst13_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST13_icfg_addr_dst13_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst14 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST14_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST14_icfg_addr_dst14_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST14_icfg_addr_dst14_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_addr_dst15 : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_FDUL_DMMU_FAMA_REMAP_DST15_UNION;
#endif
#define SOC_FDUL_DMMU_FAMA_REMAP_DST15_icfg_addr_dst15_START (0)
#define SOC_FDUL_DMMU_FAMA_REMAP_DST15_icfg_addr_dst15_END (27)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
