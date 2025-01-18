#ifndef __SOC_SECENG_P_INTERFACE_H__
#define __SOC_SECENG_P_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SECENG_P_HOST_IRR_ADDR(base) ((base) + (0x00A00UL))
#define SOC_SECENG_P_HOST_IMR_ADDR(base) ((base) + (0x00A04UL))
#define SOC_SECENG_P_HOST_ICR_ADDR(base) ((base) + (0x00A08UL))
#define SOC_SECENG_P_HOST_RGF_SIGNATURE_ADDR(base) ((base) + (0x00A24UL))
#define SOC_SECENG_P_HOST_BOOT_ADDR(base) ((base) + (0x00A28UL))
#define SOC_SECENG_P_HOST_KFDE0_VALID_ADDR(base) ((base) + (0x00A60UL))
#define SOC_SECENG_P_HOST_KFDE1_VALID_ADDR(base) ((base) + (0x00A64UL))
#define SOC_SECENG_P_HOST_KFDE2_VALID_ADDR(base) ((base) + (0x00A68UL))
#define SOC_SECENG_P_HOST_KFDE3_VALID_ADDR(base) ((base) + (0x00A6CUL))
#define SOC_SECENG_P_HOST_VERSION_ADDR(base) ((base) + (0x0A40UL))
#define SOC_SECENG_P_HOST_GPR0_ADDR(base) ((base) + (0x00A70UL))
#define SOC_SECENG_P_GPR_HOST_ADDR(base) ((base) + (0x00A74UL))
#define SOC_SECENG_P_HOST_POWER_DOWN_EN_ADDR(base) ((base) + (0x00A78UL))
#define SOC_SECENG_P_AXIM_MON_INFLIGHT_ADDR(base) ((base) + (0x00B00UL))
#define SOC_SECENG_P_AXIM_MON_INFLIGHTLAST_ADDR(base) ((base) + (0x00B40UL))
#define SOC_SECENG_P_AXIM_MON_COMP_ADDR(base) ((base) + (0x00B80UL))
#define SOC_SECENG_P_AXIM_MON_ERR_ADDR(base) ((base) + (0x00BC4UL))
#define SOC_SECENG_P_AXIM_CFG_ADDR(base) ((base) + (0x00BE8UL))
#define SOC_SECENG_P_AXIM_ACE_CONST_ADDR(base) ((base) + (0x0BECUL))
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_ADDR(base) ((base) + (0x0BF0UL))
#define SOC_SECENG_P_DSCRPTR_COMPLETION_COUNTER_ADDR(base) ((base) + (0x00E00UL))
#define SOC_SECENG_P_DSCRPTR_SW_RESET_ADDR(base) ((base) + (0x00E40UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_ADDR(base) ((base) + (0x00E60UL))
#define SOC_SECENG_P_DSCRPTR_SINGLE_ADDR_EN_ADDR(base) ((base) + (0x0E64UL))
#define SOC_SECENG_P_DSCRPTR_MEASURE_CNTR_ADDR(base) ((base) + (0x0E68UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD0_ADDR(base) ((base) + (0x00E80UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_ADDR(base) ((base) + (0x00E84UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD2_ADDR(base) ((base) + (0x00E88UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_ADDR(base) ((base) + (0x00E8CUL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_ADDR(base) ((base) + (0x00E90UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD5_ADDR(base) ((base) + (0x00E94UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WATERMARK_ADDR(base) ((base) + (0x00E98UL))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_CONTENT_ADDR(base) ((base) + (0x00E9CUL))
#define SOC_SECENG_P_SRAM_DATA_ADDR(base) ((base) + (0x00F00UL))
#define SOC_SECENG_P_SRAM_ADDR_ADDR(base) ((base) + (0x00F04UL))
#define SOC_SECENG_P_SRAM_DATA_READY_ADDR(base) ((base) + (0x00F08UL))
#else
#define SOC_SECENG_P_HOST_IRR_ADDR(base) ((base) + (0x00A00))
#define SOC_SECENG_P_HOST_IMR_ADDR(base) ((base) + (0x00A04))
#define SOC_SECENG_P_HOST_ICR_ADDR(base) ((base) + (0x00A08))
#define SOC_SECENG_P_HOST_RGF_SIGNATURE_ADDR(base) ((base) + (0x00A24))
#define SOC_SECENG_P_HOST_BOOT_ADDR(base) ((base) + (0x00A28))
#define SOC_SECENG_P_HOST_KFDE0_VALID_ADDR(base) ((base) + (0x00A60))
#define SOC_SECENG_P_HOST_KFDE1_VALID_ADDR(base) ((base) + (0x00A64))
#define SOC_SECENG_P_HOST_KFDE2_VALID_ADDR(base) ((base) + (0x00A68))
#define SOC_SECENG_P_HOST_KFDE3_VALID_ADDR(base) ((base) + (0x00A6C))
#define SOC_SECENG_P_HOST_VERSION_ADDR(base) ((base) + (0x0A40))
#define SOC_SECENG_P_HOST_GPR0_ADDR(base) ((base) + (0x00A70))
#define SOC_SECENG_P_GPR_HOST_ADDR(base) ((base) + (0x00A74))
#define SOC_SECENG_P_HOST_POWER_DOWN_EN_ADDR(base) ((base) + (0x00A78))
#define SOC_SECENG_P_AXIM_MON_INFLIGHT_ADDR(base) ((base) + (0x00B00))
#define SOC_SECENG_P_AXIM_MON_INFLIGHTLAST_ADDR(base) ((base) + (0x00B40))
#define SOC_SECENG_P_AXIM_MON_COMP_ADDR(base) ((base) + (0x00B80))
#define SOC_SECENG_P_AXIM_MON_ERR_ADDR(base) ((base) + (0x00BC4))
#define SOC_SECENG_P_AXIM_CFG_ADDR(base) ((base) + (0x00BE8))
#define SOC_SECENG_P_AXIM_ACE_CONST_ADDR(base) ((base) + (0x0BEC))
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_ADDR(base) ((base) + (0x0BF0))
#define SOC_SECENG_P_DSCRPTR_COMPLETION_COUNTER_ADDR(base) ((base) + (0x00E00))
#define SOC_SECENG_P_DSCRPTR_SW_RESET_ADDR(base) ((base) + (0x00E40))
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_ADDR(base) ((base) + (0x00E60))
#define SOC_SECENG_P_DSCRPTR_SINGLE_ADDR_EN_ADDR(base) ((base) + (0x0E64))
#define SOC_SECENG_P_DSCRPTR_MEASURE_CNTR_ADDR(base) ((base) + (0x0E68))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD0_ADDR(base) ((base) + (0x00E80))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_ADDR(base) ((base) + (0x00E84))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD2_ADDR(base) ((base) + (0x00E88))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_ADDR(base) ((base) + (0x00E8C))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_ADDR(base) ((base) + (0x00E90))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD5_ADDR(base) ((base) + (0x00E94))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WATERMARK_ADDR(base) ((base) + (0x00E98))
#define SOC_SECENG_P_DSCRPTR_QUEUE0_CONTENT_ADDR(base) ((base) + (0x00E9C))
#define SOC_SECENG_P_SRAM_DATA_ADDR(base) ((base) + (0x00F00))
#define SOC_SECENG_P_SRAM_ADDR_ADDR(base) ((base) + (0x00F04))
#define SOC_SECENG_P_SRAM_DATA_READY_ADDR(base) ((base) + (0x00F08))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int dscrptr_completion_low_int : 1;
        unsigned int reserved_1 : 5;
        unsigned int axi_err_int : 1;
        unsigned int reserved_2 : 2;
        unsigned int gpr0 : 1;
        unsigned int reserved_3 : 7;
        unsigned int dscrptr_watermark_int : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int axim_cmp_int : 1;
        unsigned int reserved_7 : 8;
    } reg;
} SOC_SECENG_P_HOST_IRR_UNION;
#endif
#define SOC_SECENG_P_HOST_IRR_dscrptr_completion_low_int_START (2)
#define SOC_SECENG_P_HOST_IRR_dscrptr_completion_low_int_END (2)
#define SOC_SECENG_P_HOST_IRR_axi_err_int_START (8)
#define SOC_SECENG_P_HOST_IRR_axi_err_int_END (8)
#define SOC_SECENG_P_HOST_IRR_gpr0_START (11)
#define SOC_SECENG_P_HOST_IRR_gpr0_END (11)
#define SOC_SECENG_P_HOST_IRR_dscrptr_watermark_int_START (19)
#define SOC_SECENG_P_HOST_IRR_dscrptr_watermark_int_END (19)
#define SOC_SECENG_P_HOST_IRR_axim_cmp_int_START (23)
#define SOC_SECENG_P_HOST_IRR_axim_cmp_int_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int dscrptr_completion_mask : 1;
        unsigned int reserved_1 : 5;
        unsigned int axi_err_mask : 1;
        unsigned int reserved_2 : 2;
        unsigned int gpr0 : 1;
        unsigned int reserved_3 : 7;
        unsigned int dscrptr_watermark_mask0 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int axim_comp_mask : 1;
        unsigned int reserved_7 : 8;
    } reg;
} SOC_SECENG_P_HOST_IMR_UNION;
#endif
#define SOC_SECENG_P_HOST_IMR_dscrptr_completion_mask_START (2)
#define SOC_SECENG_P_HOST_IMR_dscrptr_completion_mask_END (2)
#define SOC_SECENG_P_HOST_IMR_axi_err_mask_START (8)
#define SOC_SECENG_P_HOST_IMR_axi_err_mask_END (8)
#define SOC_SECENG_P_HOST_IMR_gpr0_START (11)
#define SOC_SECENG_P_HOST_IMR_gpr0_END (11)
#define SOC_SECENG_P_HOST_IMR_dscrptr_watermark_mask0_START (19)
#define SOC_SECENG_P_HOST_IMR_dscrptr_watermark_mask0_END (19)
#define SOC_SECENG_P_HOST_IMR_axim_comp_mask_START (23)
#define SOC_SECENG_P_HOST_IMR_axim_comp_mask_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int dscrptr_completion_clear : 1;
        unsigned int reserved_1 : 5;
        unsigned int axi_err_clear : 1;
        unsigned int reserved_2 : 2;
        unsigned int gpr_int_clear : 1;
        unsigned int reserved_3 : 7;
        unsigned int dscrptr_watermark_queue0_clear : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int axim_comp_clear : 1;
        unsigned int reserved_7 : 8;
    } reg;
} SOC_SECENG_P_HOST_ICR_UNION;
#endif
#define SOC_SECENG_P_HOST_ICR_dscrptr_completion_clear_START (2)
#define SOC_SECENG_P_HOST_ICR_dscrptr_completion_clear_END (2)
#define SOC_SECENG_P_HOST_ICR_axi_err_clear_START (8)
#define SOC_SECENG_P_HOST_ICR_axi_err_clear_END (8)
#define SOC_SECENG_P_HOST_ICR_gpr_int_clear_START (11)
#define SOC_SECENG_P_HOST_ICR_gpr_int_clear_END (11)
#define SOC_SECENG_P_HOST_ICR_dscrptr_watermark_queue0_clear_START (19)
#define SOC_SECENG_P_HOST_ICR_dscrptr_watermark_queue0_clear_END (19)
#define SOC_SECENG_P_HOST_ICR_axim_comp_clear_START (23)
#define SOC_SECENG_P_HOST_ICR_axim_comp_clear_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_signature : 32;
    } reg;
} SOC_SECENG_P_HOST_RGF_SIGNATURE_UNION;
#endif
#define SOC_SECENG_P_HOST_RGF_SIGNATURE_host_signature_START (0)
#define SOC_SECENG_P_HOST_RGF_SIGNATURE_host_signature_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int synthesis_config : 1;
        unsigned int large_rkek_local : 1;
        unsigned int hask_in_fuses_local : 1;
        unsigned int ext_mem_secured_local : 1;
        unsigned int reserved_0 : 1;
        unsigned int rkek_ecc_exists_n : 1;
        unsigned int sram_size_local : 3;
        unsigned int dscrptr_exists_local : 1;
        unsigned int pau_exists_local : 1;
        unsigned int rng_exists_local : 1;
        unsigned int pka_exists_local : 1;
        unsigned int rc4_exists_local : 1;
        unsigned int sha_512_prsnt_local : 1;
        unsigned int sha_256_prsnt_local : 1;
        unsigned int md5_prsnt_lcoal : 1;
        unsigned int hash_exists_local : 1;
        unsigned int c2_exists_local : 1;
        unsigned int des_exists_local : 1;
        unsigned int aes_xcbc_mac_exists_local : 1;
        unsigned int aes_cmac_exists_local : 1;
        unsigned int aes_ccm_exists_local : 1;
        unsigned int aes_xex_hw_t_calc_local : 1;
        unsigned int aes_xex_exists_local : 1;
        unsigned int ctr_exists : 1;
        unsigned int aes_din_byte_resolution_local : 1;
        unsigned int tunneling_enb_local : 1;
        unsigned int support_256_192_key_local : 1;
        unsigned int only_encrypt_local : 1;
        unsigned int aes_exists_local : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SECENG_P_HOST_BOOT_UNION;
#endif
#define SOC_SECENG_P_HOST_BOOT_synthesis_config_START (0)
#define SOC_SECENG_P_HOST_BOOT_synthesis_config_END (0)
#define SOC_SECENG_P_HOST_BOOT_large_rkek_local_START (1)
#define SOC_SECENG_P_HOST_BOOT_large_rkek_local_END (1)
#define SOC_SECENG_P_HOST_BOOT_hask_in_fuses_local_START (2)
#define SOC_SECENG_P_HOST_BOOT_hask_in_fuses_local_END (2)
#define SOC_SECENG_P_HOST_BOOT_ext_mem_secured_local_START (3)
#define SOC_SECENG_P_HOST_BOOT_ext_mem_secured_local_END (3)
#define SOC_SECENG_P_HOST_BOOT_rkek_ecc_exists_n_START (5)
#define SOC_SECENG_P_HOST_BOOT_rkek_ecc_exists_n_END (5)
#define SOC_SECENG_P_HOST_BOOT_sram_size_local_START (6)
#define SOC_SECENG_P_HOST_BOOT_sram_size_local_END (8)
#define SOC_SECENG_P_HOST_BOOT_dscrptr_exists_local_START (9)
#define SOC_SECENG_P_HOST_BOOT_dscrptr_exists_local_END (9)
#define SOC_SECENG_P_HOST_BOOT_pau_exists_local_START (10)
#define SOC_SECENG_P_HOST_BOOT_pau_exists_local_END (10)
#define SOC_SECENG_P_HOST_BOOT_rng_exists_local_START (11)
#define SOC_SECENG_P_HOST_BOOT_rng_exists_local_END (11)
#define SOC_SECENG_P_HOST_BOOT_pka_exists_local_START (12)
#define SOC_SECENG_P_HOST_BOOT_pka_exists_local_END (12)
#define SOC_SECENG_P_HOST_BOOT_rc4_exists_local_START (13)
#define SOC_SECENG_P_HOST_BOOT_rc4_exists_local_END (13)
#define SOC_SECENG_P_HOST_BOOT_sha_512_prsnt_local_START (14)
#define SOC_SECENG_P_HOST_BOOT_sha_512_prsnt_local_END (14)
#define SOC_SECENG_P_HOST_BOOT_sha_256_prsnt_local_START (15)
#define SOC_SECENG_P_HOST_BOOT_sha_256_prsnt_local_END (15)
#define SOC_SECENG_P_HOST_BOOT_md5_prsnt_lcoal_START (16)
#define SOC_SECENG_P_HOST_BOOT_md5_prsnt_lcoal_END (16)
#define SOC_SECENG_P_HOST_BOOT_hash_exists_local_START (17)
#define SOC_SECENG_P_HOST_BOOT_hash_exists_local_END (17)
#define SOC_SECENG_P_HOST_BOOT_c2_exists_local_START (18)
#define SOC_SECENG_P_HOST_BOOT_c2_exists_local_END (18)
#define SOC_SECENG_P_HOST_BOOT_des_exists_local_START (19)
#define SOC_SECENG_P_HOST_BOOT_des_exists_local_END (19)
#define SOC_SECENG_P_HOST_BOOT_aes_xcbc_mac_exists_local_START (20)
#define SOC_SECENG_P_HOST_BOOT_aes_xcbc_mac_exists_local_END (20)
#define SOC_SECENG_P_HOST_BOOT_aes_cmac_exists_local_START (21)
#define SOC_SECENG_P_HOST_BOOT_aes_cmac_exists_local_END (21)
#define SOC_SECENG_P_HOST_BOOT_aes_ccm_exists_local_START (22)
#define SOC_SECENG_P_HOST_BOOT_aes_ccm_exists_local_END (22)
#define SOC_SECENG_P_HOST_BOOT_aes_xex_hw_t_calc_local_START (23)
#define SOC_SECENG_P_HOST_BOOT_aes_xex_hw_t_calc_local_END (23)
#define SOC_SECENG_P_HOST_BOOT_aes_xex_exists_local_START (24)
#define SOC_SECENG_P_HOST_BOOT_aes_xex_exists_local_END (24)
#define SOC_SECENG_P_HOST_BOOT_ctr_exists_START (25)
#define SOC_SECENG_P_HOST_BOOT_ctr_exists_END (25)
#define SOC_SECENG_P_HOST_BOOT_aes_din_byte_resolution_local_START (26)
#define SOC_SECENG_P_HOST_BOOT_aes_din_byte_resolution_local_END (26)
#define SOC_SECENG_P_HOST_BOOT_tunneling_enb_local_START (27)
#define SOC_SECENG_P_HOST_BOOT_tunneling_enb_local_END (27)
#define SOC_SECENG_P_HOST_BOOT_support_256_192_key_local_START (28)
#define SOC_SECENG_P_HOST_BOOT_support_256_192_key_local_END (28)
#define SOC_SECENG_P_HOST_BOOT_only_encrypt_local_START (29)
#define SOC_SECENG_P_HOST_BOOT_only_encrypt_local_END (29)
#define SOC_SECENG_P_HOST_BOOT_aes_exists_local_START (30)
#define SOC_SECENG_P_HOST_BOOT_aes_exists_local_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_kfde0_valid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_HOST_KFDE0_VALID_UNION;
#endif
#define SOC_SECENG_P_HOST_KFDE0_VALID_host_kfde0_valid_START (0)
#define SOC_SECENG_P_HOST_KFDE0_VALID_host_kfde0_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_kfde1_valid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_HOST_KFDE1_VALID_UNION;
#endif
#define SOC_SECENG_P_HOST_KFDE1_VALID_host_kfde1_valid_START (0)
#define SOC_SECENG_P_HOST_KFDE1_VALID_host_kfde1_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_kfde2_valid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_HOST_KFDE2_VALID_UNION;
#endif
#define SOC_SECENG_P_HOST_KFDE2_VALID_host_kfde2_valid_START (0)
#define SOC_SECENG_P_HOST_KFDE2_VALID_host_kfde2_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_kfde3_valid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_HOST_KFDE3_VALID_UNION;
#endif
#define SOC_SECENG_P_HOST_KFDE3_VALID_host_kfde3_valid_START (0)
#define SOC_SECENG_P_HOST_KFDE3_VALID_host_kfde3_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_version : 32;
    } reg;
} SOC_SECENG_P_HOST_VERSION_UNION;
#endif
#define SOC_SECENG_P_HOST_VERSION_host_version_START (0)
#define SOC_SECENG_P_HOST_VERSION_host_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_gpr0 : 32;
    } reg;
} SOC_SECENG_P_HOST_GPR0_UNION;
#endif
#define SOC_SECENG_P_HOST_GPR0_host_gpr0_START (0)
#define SOC_SECENG_P_HOST_GPR0_host_gpr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpr_host : 32;
    } reg;
} SOC_SECENG_P_GPR_HOST_UNION;
#endif
#define SOC_SECENG_P_GPR_HOST_gpr_host_START (0)
#define SOC_SECENG_P_GPR_HOST_gpr_host_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int host_power_down_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_HOST_POWER_DOWN_EN_UNION;
#endif
#define SOC_SECENG_P_HOST_POWER_DOWN_EN_host_power_down_en_START (0)
#define SOC_SECENG_P_HOST_POWER_DOWN_EN_host_power_down_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inflightcntr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SECENG_P_AXIM_MON_INFLIGHT_UNION;
#endif
#define SOC_SECENG_P_AXIM_MON_INFLIGHT_inflightcntr_START (0)
#define SOC_SECENG_P_AXIM_MON_INFLIGHT_inflightcntr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inflightcntr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SECENG_P_AXIM_MON_INFLIGHTLAST_UNION;
#endif
#define SOC_SECENG_P_AXIM_MON_INFLIGHTLAST_inflightcntr_START (0)
#define SOC_SECENG_P_AXIM_MON_INFLIGHTLAST_inflightcntr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int complastcntr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SECENG_P_AXIM_MON_COMP_UNION;
#endif
#define SOC_SECENG_P_AXIM_MON_COMP_complastcntr_START (0)
#define SOC_SECENG_P_AXIM_MON_COMP_complastcntr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bresp : 2;
        unsigned int bid : 4;
        unsigned int reserved_0: 10;
        unsigned int rresp : 2;
        unsigned int rid : 4;
        unsigned int reserved_1: 10;
    } reg;
} SOC_SECENG_P_AXIM_MON_ERR_UNION;
#endif
#define SOC_SECENG_P_AXIM_MON_ERR_bresp_START (0)
#define SOC_SECENG_P_AXIM_MON_ERR_bresp_END (1)
#define SOC_SECENG_P_AXIM_MON_ERR_bid_START (2)
#define SOC_SECENG_P_AXIM_MON_ERR_bid_END (5)
#define SOC_SECENG_P_AXIM_MON_ERR_rresp_START (16)
#define SOC_SECENG_P_AXIM_MON_ERR_rresp_END (17)
#define SOC_SECENG_P_AXIM_MON_ERR_rid_START (18)
#define SOC_SECENG_P_AXIM_MON_ERR_rid_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 4;
        unsigned int brespmask : 1;
        unsigned int rrespmask : 1;
        unsigned int infltmask : 1;
        unsigned int ompmask : 1;
        unsigned int reserved_1: 24;
    } reg;
} SOC_SECENG_P_AXIM_CFG_UNION;
#endif
#define SOC_SECENG_P_AXIM_CFG_brespmask_START (4)
#define SOC_SECENG_P_AXIM_CFG_brespmask_END (4)
#define SOC_SECENG_P_AXIM_CFG_rrespmask_START (5)
#define SOC_SECENG_P_AXIM_CFG_rrespmask_END (5)
#define SOC_SECENG_P_AXIM_CFG_infltmask_START (6)
#define SOC_SECENG_P_AXIM_CFG_infltmask_END (6)
#define SOC_SECENG_P_AXIM_CFG_ompmask_START (7)
#define SOC_SECENG_P_AXIM_CFG_ompmask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ardomain : 2;
        unsigned int awdomain : 2;
        unsigned int arbar : 2;
        unsigned int awbar : 2;
        unsigned int arsnoop : 4;
        unsigned int awsnoop_not_aligned : 3;
        unsigned int awsnoop_aligned : 3;
        unsigned int awaddr_not_masked : 7;
        unsigned int awlen_val : 4;
        unsigned int reserved : 3;
    } reg;
} SOC_SECENG_P_AXIM_ACE_CONST_UNION;
#endif
#define SOC_SECENG_P_AXIM_ACE_CONST_ardomain_START (0)
#define SOC_SECENG_P_AXIM_ACE_CONST_ardomain_END (1)
#define SOC_SECENG_P_AXIM_ACE_CONST_awdomain_START (2)
#define SOC_SECENG_P_AXIM_ACE_CONST_awdomain_END (3)
#define SOC_SECENG_P_AXIM_ACE_CONST_arbar_START (4)
#define SOC_SECENG_P_AXIM_ACE_CONST_arbar_END (5)
#define SOC_SECENG_P_AXIM_ACE_CONST_awbar_START (6)
#define SOC_SECENG_P_AXIM_ACE_CONST_awbar_END (7)
#define SOC_SECENG_P_AXIM_ACE_CONST_arsnoop_START (8)
#define SOC_SECENG_P_AXIM_ACE_CONST_arsnoop_END (11)
#define SOC_SECENG_P_AXIM_ACE_CONST_awsnoop_not_aligned_START (12)
#define SOC_SECENG_P_AXIM_ACE_CONST_awsnoop_not_aligned_END (14)
#define SOC_SECENG_P_AXIM_ACE_CONST_awsnoop_aligned_START (15)
#define SOC_SECENG_P_AXIM_ACE_CONST_awsnoop_aligned_END (17)
#define SOC_SECENG_P_AXIM_ACE_CONST_awaddr_not_masked_START (18)
#define SOC_SECENG_P_AXIM_ACE_CONST_awaddr_not_masked_END (24)
#define SOC_SECENG_P_AXIM_ACE_CONST_awlen_val_START (25)
#define SOC_SECENG_P_AXIM_ACE_CONST_awlen_val_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache_last : 4;
        unsigned int awcache : 4;
        unsigned int arcache : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_SECENG_P_AXIM_CACHE_PARAMS_UNION;
#endif
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_awcache_last_START (0)
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_awcache_last_END (3)
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_awcache_START (4)
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_awcache_END (7)
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_arcache_START (8)
#define SOC_SECENG_P_AXIM_CACHE_PARAMS_arcache_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int completion_counter : 6;
        unsigned int overflow_counter : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_SECENG_P_DSCRPTR_COMPLETION_COUNTER_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_COMPLETION_COUNTER_completion_counter_START (0)
#define SOC_SECENG_P_DSCRPTR_COMPLETION_COUNTER_completion_counter_END (5)
#define SOC_SECENG_P_DSCRPTR_COMPLETION_COUNTER_overflow_counter_START (6)
#define SOC_SECENG_P_DSCRPTR_COMPLETION_COUNTER_overflow_counter_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dscrptr_sw_reset : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_DSCRPTR_SW_RESET_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_SW_RESET_dscrptr_sw_reset_START (0)
#define SOC_SECENG_P_DSCRPTR_SW_RESET_dscrptr_sw_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int num_of_dscrptr : 10;
        unsigned int dscrptr_sram_size : 12;
        unsigned int sram_size : 3;
        unsigned int reserved : 7;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_num_of_dscrptr_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_num_of_dscrptr_END (9)
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_dscrptr_sram_size_START (10)
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_dscrptr_sram_size_END (21)
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_sram_size_START (22)
#define SOC_SECENG_P_DSCRPTR_QUEUE_SRAM_SIZE_sram_size_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dscrptr_single_addr_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_DSCRPTR_SINGLE_ADDR_EN_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_SINGLE_ADDR_EN_dscrptr_single_addr_en_START (0)
#define SOC_SECENG_P_DSCRPTR_SINGLE_ADDR_EN_dscrptr_single_addr_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int measure_cntr : 32;
    } reg;
} SOC_SECENG_P_DSCRPTR_MEASURE_CNTR_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_MEASURE_CNTR_measure_cntr_START (0)
#define SOC_SECENG_P_DSCRPTR_MEASURE_CNTR_measure_cntr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int din_dma_address : 32;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_WORD0_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD0_din_dma_address_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD0_din_dma_address_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int din_dma_mode : 2;
        unsigned int din_size : 24;
        unsigned int ns_bit : 1;
        unsigned int din_const_value : 1;
        unsigned int not_last : 1;
        unsigned int lock_queue : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_din_dma_mode_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_din_dma_mode_END (1)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_din_size_START (2)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_din_size_END (25)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_ns_bit_START (26)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_ns_bit_END (26)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_din_const_value_START (27)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_din_const_value_END (27)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_not_last_START (28)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_not_last_END (28)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_lock_queue_START (29)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD1_lock_queue_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dout_dma_address : 32;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_WORD2_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD2_dout_dma_address_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD2_dout_dma_address_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dout_dma_mode : 2;
        unsigned int dout_size : 24;
        unsigned int ns_bit : 1;
        unsigned int dout_last_ind : 1;
        unsigned int reserved_0 : 1;
        unsigned int hash_xor_bit : 1;
        unsigned int reserved_1 : 1;
        unsigned int queue_last_ind : 1;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_dout_dma_mode_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_dout_dma_mode_END (1)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_dout_size_START (2)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_dout_size_END (25)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_ns_bit_START (26)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_ns_bit_END (26)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_dout_last_ind_START (27)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_dout_last_ind_END (27)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_hash_xor_bit_START (29)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_hash_xor_bit_END (29)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_queue_last_ind_START (31)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD3_queue_last_ind_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int data_flow_mode : 6;
        unsigned int aes_sel_n_hash : 1;
        unsigned int aes_xor_crypto_key : 1;
        unsigned int ack_needed : 2;
        unsigned int cipher_mode : 4;
        unsigned int cmac_size0 : 1;
        unsigned int cipher_do : 2;
        unsigned int cipher_conf0 : 2;
        unsigned int cipher_conf1 : 1;
        unsigned int cipher_conf2 : 2;
        unsigned int key_size : 2;
        unsigned int setup_operation : 4;
        unsigned int din_sram_endianness : 1;
        unsigned int dout_sram_endianness : 1;
        unsigned int word_swap : 1;
        unsigned int bytes_swap : 1;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_data_flow_mode_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_data_flow_mode_END (5)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_aes_sel_n_hash_START (6)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_aes_sel_n_hash_END (6)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_aes_xor_crypto_key_START (7)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_aes_xor_crypto_key_END (7)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_ack_needed_START (8)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_ack_needed_END (9)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_mode_START (10)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_mode_END (13)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cmac_size0_START (14)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cmac_size0_END (14)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_do_START (15)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_do_END (16)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_conf0_START (17)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_conf0_END (18)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_conf1_START (19)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_conf1_END (19)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_conf2_START (20)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_cipher_conf2_END (21)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_key_size_START (22)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_key_size_END (23)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_setup_operation_START (24)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_setup_operation_END (27)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_din_sram_endianness_START (28)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_din_sram_endianness_END (28)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_dout_sram_endianness_START (29)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_dout_sram_endianness_END (29)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_word_swap_START (30)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_word_swap_END (30)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_bytes_swap_START (31)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD4_bytes_swap_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int din_addr_high : 16;
        unsigned int dout_addr_high : 16;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_WORD5_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD5_din_addr_high_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD5_din_addr_high_END (15)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD5_dout_addr_high_START (16)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WORD5_dout_addr_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int watermark : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_WATERMARK_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WATERMARK_watermark_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_WATERMARK_watermark_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int queue_content : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SECENG_P_DSCRPTR_QUEUE0_CONTENT_UNION;
#endif
#define SOC_SECENG_P_DSCRPTR_QUEUE0_CONTENT_queue_content_START (0)
#define SOC_SECENG_P_DSCRPTR_QUEUE0_CONTENT_queue_content_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sram_data : 32;
    } reg;
} SOC_SECENG_P_SRAM_DATA_UNION;
#endif
#define SOC_SECENG_P_SRAM_DATA_sram_data_START (0)
#define SOC_SECENG_P_SRAM_DATA_sram_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sram_addr : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SECENG_P_SRAM_ADDR_UNION;
#endif
#define SOC_SECENG_P_SRAM_ADDR_sram_addr_START (0)
#define SOC_SECENG_P_SRAM_ADDR_sram_addr_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sram_ready : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SECENG_P_SRAM_DATA_READY_UNION;
#endif
#define SOC_SECENG_P_SRAM_DATA_READY_sram_ready_START (0)
#define SOC_SECENG_P_SRAM_DATA_READY_sram_ready_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
