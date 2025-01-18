#ifndef __SOC_NPU_SRAM_INTERFACE_H__
#define __SOC_NPU_SRAM_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_SRAM_SRAM_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_SRAM_SRAM_STATE_ADDR(base) ((base) + (0x0004UL))
#define SOC_NPU_SRAM_SRAM_SEC_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_SRAM_SRAM_SEC_ADDR_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_SRAM_SRAM_SEC_SIZE_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_SRAM_SRAM_BASE_ADDR_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_SRAM_SRAM_INTMASK_ADDR(base) ((base) + (0x0040UL))
#define SOC_NPU_SRAM_SRAM_RAWINT_ADDR(base) ((base) + (0x0044UL))
#define SOC_NPU_SRAM_SRAM_INTSTS_ADDR(base) ((base) + (0x0048UL))
#define SOC_NPU_SRAM_SRAM_INTCLR_ADDR(base) ((base) + (0x004CUL))
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_ADDR(base) ((base) + (0x0060UL))
#define SOC_NPU_SRAM_SRAM_ERR_INFO_ADDR(base) ((base) + (0x0064UL))
#define SOC_NPU_SRAM_SRAM_ERR_ADDR_ADDR(base) ((base) + (0x0068UL))
#define SOC_NPU_SRAM_SRAM_ECC_INFO_ADDR(base) ((base) + (0x006CUL))
#define SOC_NPU_SRAM_SRAM_CLR_STAT_ADDR(base) ((base) + (0x0070UL))
#define SOC_NPU_SRAM_SRAM_ECC_CNT_ADDR(base) ((base) + (0x0080UL))
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_ADDR(base) ((base) + (0x0084UL))
#define SOC_NPU_SRAM_SRAM_CNT0_ADDR(base) ((base) + (0x0088UL))
#define SOC_NPU_SRAM_SRAM_CNT1_ADDR(base) ((base) + (0x008CUL))
#define SOC_NPU_SRAM_SRAM_CNT2_ADDR(base) ((base) + (0x0090UL))
#define SOC_NPU_SRAM_SRAM_CNT3_ADDR(base) ((base) + (0x0094UL))
#define SOC_NPU_SRAM_SRAM_MAGIC_WORD_ADDR(base) ((base) + (0x07F0UL))
#define SOC_NPU_SRAM_SRAM_VERSION_ADDR(base) ((base) + (0x0C10UL))
#else
#define SOC_NPU_SRAM_SRAM_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_SRAM_SRAM_STATE_ADDR(base) ((base) + (0x0004))
#define SOC_NPU_SRAM_SRAM_SEC_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_SRAM_SRAM_SEC_ADDR_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_SRAM_SRAM_SEC_SIZE_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_SRAM_SRAM_BASE_ADDR_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_SRAM_SRAM_INTMASK_ADDR(base) ((base) + (0x0040))
#define SOC_NPU_SRAM_SRAM_RAWINT_ADDR(base) ((base) + (0x0044))
#define SOC_NPU_SRAM_SRAM_INTSTS_ADDR(base) ((base) + (0x0048))
#define SOC_NPU_SRAM_SRAM_INTCLR_ADDR(base) ((base) + (0x004C))
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_ADDR(base) ((base) + (0x0060))
#define SOC_NPU_SRAM_SRAM_ERR_INFO_ADDR(base) ((base) + (0x0064))
#define SOC_NPU_SRAM_SRAM_ERR_ADDR_ADDR(base) ((base) + (0x0068))
#define SOC_NPU_SRAM_SRAM_ECC_INFO_ADDR(base) ((base) + (0x006C))
#define SOC_NPU_SRAM_SRAM_CLR_STAT_ADDR(base) ((base) + (0x0070))
#define SOC_NPU_SRAM_SRAM_ECC_CNT_ADDR(base) ((base) + (0x0080))
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_ADDR(base) ((base) + (0x0084))
#define SOC_NPU_SRAM_SRAM_CNT0_ADDR(base) ((base) + (0x0088))
#define SOC_NPU_SRAM_SRAM_CNT1_ADDR(base) ((base) + (0x008C))
#define SOC_NPU_SRAM_SRAM_CNT2_ADDR(base) ((base) + (0x0090))
#define SOC_NPU_SRAM_SRAM_CNT3_ADDR(base) ((base) + (0x0094))
#define SOC_NPU_SRAM_SRAM_MAGIC_WORD_ADDR(base) ((base) + (0x07F0))
#define SOC_NPU_SRAM_SRAM_VERSION_ADDR(base) ((base) + (0x0C10))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int init : 1;
        unsigned int reserved_0 : 1;
        unsigned int ecc_en : 1;
        unsigned int multi_ecc_report : 1;
        unsigned int excl_endian : 1;
        unsigned int cnt_en : 1;
        unsigned int decerr_report : 1;
        unsigned int reserved_1 : 1;
        unsigned int base_addr_en : 1;
        unsigned int exinc_en : 1;
        unsigned int exdec_en : 1;
        unsigned int mbist_en : 1;
        unsigned int rdwrap_dis : 1;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_NPU_SRAM_SRAM_CTRL_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_CTRL_init_START (0)
#define SOC_NPU_SRAM_SRAM_CTRL_init_END (0)
#define SOC_NPU_SRAM_SRAM_CTRL_ecc_en_START (2)
#define SOC_NPU_SRAM_SRAM_CTRL_ecc_en_END (2)
#define SOC_NPU_SRAM_SRAM_CTRL_multi_ecc_report_START (3)
#define SOC_NPU_SRAM_SRAM_CTRL_multi_ecc_report_END (3)
#define SOC_NPU_SRAM_SRAM_CTRL_excl_endian_START (4)
#define SOC_NPU_SRAM_SRAM_CTRL_excl_endian_END (4)
#define SOC_NPU_SRAM_SRAM_CTRL_cnt_en_START (5)
#define SOC_NPU_SRAM_SRAM_CTRL_cnt_en_END (5)
#define SOC_NPU_SRAM_SRAM_CTRL_decerr_report_START (6)
#define SOC_NPU_SRAM_SRAM_CTRL_decerr_report_END (6)
#define SOC_NPU_SRAM_SRAM_CTRL_base_addr_en_START (8)
#define SOC_NPU_SRAM_SRAM_CTRL_base_addr_en_END (8)
#define SOC_NPU_SRAM_SRAM_CTRL_exinc_en_START (9)
#define SOC_NPU_SRAM_SRAM_CTRL_exinc_en_END (9)
#define SOC_NPU_SRAM_SRAM_CTRL_exdec_en_START (10)
#define SOC_NPU_SRAM_SRAM_CTRL_exdec_en_END (10)
#define SOC_NPU_SRAM_SRAM_CTRL_mbist_en_START (11)
#define SOC_NPU_SRAM_SRAM_CTRL_mbist_en_END (11)
#define SOC_NPU_SRAM_SRAM_CTRL_rdwrap_dis_START (12)
#define SOC_NPU_SRAM_SRAM_CTRL_rdwrap_dis_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int init_over : 1;
        unsigned int wrfifo_empty : 1;
        unsigned int rdfifo_empty : 1;
        unsigned int wdatfifo_empty : 1;
        unsigned int pipe_empty : 1;
        unsigned int resp_empty : 1;
        unsigned int reserved_0 : 2;
        unsigned int decode_error : 1;
        unsigned int slave_error : 1;
        unsigned int ns_error : 1;
        unsigned int single_ecc : 1;
        unsigned int multi_ecc : 1;
        unsigned int buscfg_rderr : 1;
        unsigned int buscfg_wrerr : 1;
        unsigned int buscfg_wrcft : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_NPU_SRAM_SRAM_STATE_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_STATE_init_over_START (0)
#define SOC_NPU_SRAM_SRAM_STATE_init_over_END (0)
#define SOC_NPU_SRAM_SRAM_STATE_wrfifo_empty_START (1)
#define SOC_NPU_SRAM_SRAM_STATE_wrfifo_empty_END (1)
#define SOC_NPU_SRAM_SRAM_STATE_rdfifo_empty_START (2)
#define SOC_NPU_SRAM_SRAM_STATE_rdfifo_empty_END (2)
#define SOC_NPU_SRAM_SRAM_STATE_wdatfifo_empty_START (3)
#define SOC_NPU_SRAM_SRAM_STATE_wdatfifo_empty_END (3)
#define SOC_NPU_SRAM_SRAM_STATE_pipe_empty_START (4)
#define SOC_NPU_SRAM_SRAM_STATE_pipe_empty_END (4)
#define SOC_NPU_SRAM_SRAM_STATE_resp_empty_START (5)
#define SOC_NPU_SRAM_SRAM_STATE_resp_empty_END (5)
#define SOC_NPU_SRAM_SRAM_STATE_decode_error_START (8)
#define SOC_NPU_SRAM_SRAM_STATE_decode_error_END (8)
#define SOC_NPU_SRAM_SRAM_STATE_slave_error_START (9)
#define SOC_NPU_SRAM_SRAM_STATE_slave_error_END (9)
#define SOC_NPU_SRAM_SRAM_STATE_ns_error_START (10)
#define SOC_NPU_SRAM_SRAM_STATE_ns_error_END (10)
#define SOC_NPU_SRAM_SRAM_STATE_single_ecc_START (11)
#define SOC_NPU_SRAM_SRAM_STATE_single_ecc_END (11)
#define SOC_NPU_SRAM_SRAM_STATE_multi_ecc_START (12)
#define SOC_NPU_SRAM_SRAM_STATE_multi_ecc_END (12)
#define SOC_NPU_SRAM_SRAM_STATE_buscfg_rderr_START (13)
#define SOC_NPU_SRAM_SRAM_STATE_buscfg_rderr_END (13)
#define SOC_NPU_SRAM_SRAM_STATE_buscfg_wrerr_START (14)
#define SOC_NPU_SRAM_SRAM_STATE_buscfg_wrerr_END (14)
#define SOC_NPU_SRAM_SRAM_STATE_buscfg_wrcft_START (15)
#define SOC_NPU_SRAM_SRAM_STATE_buscfg_wrcft_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_sec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_SRAM_SRAM_SEC_CTRL_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_SEC_CTRL_reg_sec_en_START (0)
#define SOC_NPU_SRAM_SRAM_SEC_CTRL_reg_sec_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_sec_addr : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_SRAM_SRAM_SEC_ADDR_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_SEC_ADDR_reg_sec_addr_START (0)
#define SOC_NPU_SRAM_SRAM_SEC_ADDR_reg_sec_addr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_sec_size : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_SRAM_SRAM_SEC_SIZE_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_SEC_SIZE_reg_sec_size_START (0)
#define SOC_NPU_SRAM_SRAM_SEC_SIZE_reg_sec_size_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_base_addr : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_NPU_SRAM_SRAM_BASE_ADDR_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_BASE_ADDR_reg_base_addr_START (0)
#define SOC_NPU_SRAM_SRAM_BASE_ADDR_reg_base_addr_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int decerr_intmsk : 1;
        unsigned int slverr_intmsk : 1;
        unsigned int nserr_intmsk : 1;
        unsigned int ecc_intmsk : 1;
        unsigned int cnt0_intmsk : 1;
        unsigned int cnt1_intmsk : 1;
        unsigned int cnt2_intmsk : 1;
        unsigned int cnt3_intmsk : 1;
        unsigned int buserr_intmsk : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_NPU_SRAM_SRAM_INTMASK_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_INTMASK_decerr_intmsk_START (0)
#define SOC_NPU_SRAM_SRAM_INTMASK_decerr_intmsk_END (0)
#define SOC_NPU_SRAM_SRAM_INTMASK_slverr_intmsk_START (1)
#define SOC_NPU_SRAM_SRAM_INTMASK_slverr_intmsk_END (1)
#define SOC_NPU_SRAM_SRAM_INTMASK_nserr_intmsk_START (2)
#define SOC_NPU_SRAM_SRAM_INTMASK_nserr_intmsk_END (2)
#define SOC_NPU_SRAM_SRAM_INTMASK_ecc_intmsk_START (3)
#define SOC_NPU_SRAM_SRAM_INTMASK_ecc_intmsk_END (3)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt0_intmsk_START (4)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt0_intmsk_END (4)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt1_intmsk_START (5)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt1_intmsk_END (5)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt2_intmsk_START (6)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt2_intmsk_END (6)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt3_intmsk_START (7)
#define SOC_NPU_SRAM_SRAM_INTMASK_cnt3_intmsk_END (7)
#define SOC_NPU_SRAM_SRAM_INTMASK_buserr_intmsk_START (8)
#define SOC_NPU_SRAM_SRAM_INTMASK_buserr_intmsk_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int decerr_rawint : 1;
        unsigned int slverr_rawint : 1;
        unsigned int nserr_rawint : 1;
        unsigned int ecc_rawint : 1;
        unsigned int cnt0_rawint : 1;
        unsigned int cnt1_rawint : 1;
        unsigned int cnt2_rawint : 1;
        unsigned int cnt3_rawint : 1;
        unsigned int buserr_rawint : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_NPU_SRAM_SRAM_RAWINT_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_RAWINT_decerr_rawint_START (0)
#define SOC_NPU_SRAM_SRAM_RAWINT_decerr_rawint_END (0)
#define SOC_NPU_SRAM_SRAM_RAWINT_slverr_rawint_START (1)
#define SOC_NPU_SRAM_SRAM_RAWINT_slverr_rawint_END (1)
#define SOC_NPU_SRAM_SRAM_RAWINT_nserr_rawint_START (2)
#define SOC_NPU_SRAM_SRAM_RAWINT_nserr_rawint_END (2)
#define SOC_NPU_SRAM_SRAM_RAWINT_ecc_rawint_START (3)
#define SOC_NPU_SRAM_SRAM_RAWINT_ecc_rawint_END (3)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt0_rawint_START (4)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt0_rawint_END (4)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt1_rawint_START (5)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt1_rawint_END (5)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt2_rawint_START (6)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt2_rawint_END (6)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt3_rawint_START (7)
#define SOC_NPU_SRAM_SRAM_RAWINT_cnt3_rawint_END (7)
#define SOC_NPU_SRAM_SRAM_RAWINT_buserr_rawint_START (8)
#define SOC_NPU_SRAM_SRAM_RAWINT_buserr_rawint_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int decerr_intst : 1;
        unsigned int slverr_intst : 1;
        unsigned int nserr_intst : 1;
        unsigned int ecc_intst : 1;
        unsigned int cnt0_intst : 1;
        unsigned int cnt1_intst : 1;
        unsigned int cnt2_intst : 1;
        unsigned int cnt3_intst : 1;
        unsigned int buserr_intst : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_NPU_SRAM_SRAM_INTSTS_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_INTSTS_decerr_intst_START (0)
#define SOC_NPU_SRAM_SRAM_INTSTS_decerr_intst_END (0)
#define SOC_NPU_SRAM_SRAM_INTSTS_slverr_intst_START (1)
#define SOC_NPU_SRAM_SRAM_INTSTS_slverr_intst_END (1)
#define SOC_NPU_SRAM_SRAM_INTSTS_nserr_intst_START (2)
#define SOC_NPU_SRAM_SRAM_INTSTS_nserr_intst_END (2)
#define SOC_NPU_SRAM_SRAM_INTSTS_ecc_intst_START (3)
#define SOC_NPU_SRAM_SRAM_INTSTS_ecc_intst_END (3)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt0_intst_START (4)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt0_intst_END (4)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt1_intst_START (5)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt1_intst_END (5)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt2_intst_START (6)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt2_intst_END (6)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt3_intst_START (7)
#define SOC_NPU_SRAM_SRAM_INTSTS_cnt3_intst_END (7)
#define SOC_NPU_SRAM_SRAM_INTSTS_buserr_intst_START (8)
#define SOC_NPU_SRAM_SRAM_INTSTS_buserr_intst_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int decerr_intclr : 1;
        unsigned int slverr_intclr : 1;
        unsigned int nserr_intclr : 1;
        unsigned int ecc_intclr : 1;
        unsigned int cnt0_intclr : 1;
        unsigned int cnt1_intclr : 1;
        unsigned int cnt2_intclr : 1;
        unsigned int cnt3_intclr : 1;
        unsigned int buserr_intclr : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_NPU_SRAM_SRAM_INTCLR_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_INTCLR_decerr_intclr_START (0)
#define SOC_NPU_SRAM_SRAM_INTCLR_decerr_intclr_END (0)
#define SOC_NPU_SRAM_SRAM_INTCLR_slverr_intclr_START (1)
#define SOC_NPU_SRAM_SRAM_INTCLR_slverr_intclr_END (1)
#define SOC_NPU_SRAM_SRAM_INTCLR_nserr_intclr_START (2)
#define SOC_NPU_SRAM_SRAM_INTCLR_nserr_intclr_END (2)
#define SOC_NPU_SRAM_SRAM_INTCLR_ecc_intclr_START (3)
#define SOC_NPU_SRAM_SRAM_INTCLR_ecc_intclr_END (3)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt0_intclr_START (4)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt0_intclr_END (4)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt1_intclr_START (5)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt1_intclr_END (5)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt2_intclr_START (6)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt2_intclr_END (6)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt3_intclr_START (7)
#define SOC_NPU_SRAM_SRAM_INTCLR_cnt3_intclr_END (7)
#define SOC_NPU_SRAM_SRAM_INTCLR_buserr_intclr_START (8)
#define SOC_NPU_SRAM_SRAM_INTCLR_buserr_intclr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bit1_sel : 7;
        unsigned int bit1_en : 1;
        unsigned int bit2_sel : 7;
        unsigned int bit2_en : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SRAM_SRAM_ECC_INJECT_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit1_sel_START (0)
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit1_sel_END (6)
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit1_en_START (7)
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit1_en_END (7)
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit2_sel_START (8)
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit2_sel_END (14)
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit2_en_START (15)
#define SOC_NPU_SRAM_SRAM_ECC_INJECT_bit2_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errinfo_id : 16;
        unsigned int errinfo_len : 6;
        unsigned int errinfo_size : 3;
        unsigned int errinfo_burst : 2;
        unsigned int errinfo_lock : 1;
        unsigned int errinfo_prot : 3;
        unsigned int errinfo_en : 1;
    } reg;
} SOC_NPU_SRAM_SRAM_ERR_INFO_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_id_START (0)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_id_END (15)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_len_START (16)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_len_END (21)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_size_START (22)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_size_END (24)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_burst_START (25)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_burst_END (26)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_lock_START (27)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_lock_END (27)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_prot_START (28)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_prot_END (30)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_en_START (31)
#define SOC_NPU_SRAM_SRAM_ERR_INFO_errinfo_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_addr : 32;
    } reg;
} SOC_NPU_SRAM_SRAM_ERR_ADDR_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_ERR_ADDR_ecc_addr_START (0)
#define SOC_NPU_SRAM_SRAM_ERR_ADDR_ecc_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eccinfo_vec : 2;
        unsigned int reserved_0 : 2;
        unsigned int eccinfo_addr : 17;
        unsigned int reserved_1 : 3;
        unsigned int eccinfo_single : 1;
        unsigned int eccinfo_multi : 1;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_NPU_SRAM_SRAM_ECC_INFO_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_vec_START (0)
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_vec_END (1)
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_addr_START (4)
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_addr_END (20)
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_single_START (24)
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_single_END (24)
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_multi_START (25)
#define SOC_NPU_SRAM_SRAM_ECC_INFO_eccinfo_multi_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clr_state : 1;
        unsigned int clr_ecc1_cnt : 1;
        unsigned int clr_ecc2_cnt : 1;
        unsigned int clr_err_info : 1;
        unsigned int clr_ecc_info : 1;
        unsigned int clr_cnt0 : 1;
        unsigned int clr_cnt1 : 1;
        unsigned int clr_cnt2 : 1;
        unsigned int clr_cnt3 : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_SRAM_SRAM_CLR_STAT_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_state_START (0)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_state_END (0)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_ecc1_cnt_START (1)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_ecc1_cnt_END (1)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_ecc2_cnt_START (2)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_ecc2_cnt_END (2)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_err_info_START (3)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_err_info_END (3)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_ecc_info_START (4)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_ecc_info_END (4)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt0_START (5)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt0_END (5)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt1_START (6)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt1_END (6)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt2_START (7)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt2_END (7)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt3_START (8)
#define SOC_NPU_SRAM_SRAM_CLR_STAT_clr_cnt3_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int single_ecc_cnt : 16;
        unsigned int multi_ecc_cnt : 16;
    } reg;
} SOC_NPU_SRAM_SRAM_ECC_CNT_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_ECC_CNT_single_ecc_cnt_START (0)
#define SOC_NPU_SRAM_SRAM_ECC_CNT_single_ecc_cnt_END (15)
#define SOC_NPU_SRAM_SRAM_ECC_CNT_multi_ecc_cnt_START (16)
#define SOC_NPU_SRAM_SRAM_ECC_CNT_multi_ecc_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cnt0_type : 4;
        unsigned int cnt1_type : 4;
        unsigned int cnt2_type : 4;
        unsigned int cnt3_type : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_SRAM_SRAM_CNT_TYPE_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt0_type_START (0)
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt0_type_END (3)
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt1_type_START (4)
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt1_type_END (7)
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt2_type_START (8)
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt2_type_END (11)
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt3_type_START (12)
#define SOC_NPU_SRAM_SRAM_CNT_TYPE_cnt3_type_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cnt0 : 32;
    } reg;
} SOC_NPU_SRAM_SRAM_CNT0_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_CNT0_dfx_cnt0_START (0)
#define SOC_NPU_SRAM_SRAM_CNT0_dfx_cnt0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cnt1 : 32;
    } reg;
} SOC_NPU_SRAM_SRAM_CNT1_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_CNT1_dfx_cnt1_START (0)
#define SOC_NPU_SRAM_SRAM_CNT1_dfx_cnt1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cnt2 : 32;
    } reg;
} SOC_NPU_SRAM_SRAM_CNT2_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_CNT2_dfx_cnt2_START (0)
#define SOC_NPU_SRAM_SRAM_CNT2_dfx_cnt2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_cnt3 : 32;
    } reg;
} SOC_NPU_SRAM_SRAM_CNT3_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_CNT3_dfx_cnt3_START (0)
#define SOC_NPU_SRAM_SRAM_CNT3_dfx_cnt3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_SRAM_SRAM_MAGIC_WORD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hisilicon_version : 12;
        unsigned int sub_version : 4;
        unsigned int main_version : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_SRAM_SRAM_VERSION_UNION;
#endif
#define SOC_NPU_SRAM_SRAM_VERSION_hisilicon_version_START (0)
#define SOC_NPU_SRAM_SRAM_VERSION_hisilicon_version_END (11)
#define SOC_NPU_SRAM_SRAM_VERSION_sub_version_START (12)
#define SOC_NPU_SRAM_SRAM_VERSION_sub_version_END (15)
#define SOC_NPU_SRAM_SRAM_VERSION_main_version_START (16)
#define SOC_NPU_SRAM_SRAM_VERSION_main_version_END (19)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
