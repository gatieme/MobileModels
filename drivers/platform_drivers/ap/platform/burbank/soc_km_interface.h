#ifndef __SOC_KM_INTERFACE_H__
#define __SOC_KM_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_KM_STR_ADDR(base) ((base) + (0x0000))
#define SOC_KM_MODE_ADDR(base) ((base) + (0x0004))
#define SOC_KM_DERIVE_KEY_CLR_ADDR(base) ((base) + (0x0008))
#define SOC_KM_KEY_DECRY_DONE_ADDR(base) ((base) + (0x000C))
#define SOC_KM_KEY_DERIVE_DONE_ADDR(base) ((base) + (0x0010))
#define SOC_KM_KEY_DERIVE_DONE_CLR_ADDR(base) ((base) + (0x0014))
#define SOC_KM_DFX_ADDR(base) ((base) + (0x0018))
#define SOC_KM_REG_LOCK_ADDR(base) ((base) + (0x001C))
#define SOC_KM_AES_KEY_ADDR(base,n) ((base) + (0x0020+(n)*4))
#define SOC_KM_DES_KEY_ADDR(base,n) ((base) + (0x0040+(n)*4))
#define SOC_KM_SM4_KEY_ADDR(base,n) ((base) + (0x0060+(n)*4))
#define SOC_KM_KDR_IN_ADDR(base,n) ((base) + (0x0080+(n)*4))
#define SOC_KM_KDR_OUT_ADDR(base,n) ((base) + (0x00A0+(n)*4))
#define SOC_KM_CEK_IN_ADDR(base,n) ((base) + (0x00C0+(n)*4))
#define SOC_KM_DERIVE_KEY_ADDR(base,n) ((base) + (0x0120+(n)*4))
#define SOC_KM_GID_IN_ADDR(base,n) ((base) + (0x0140+(n)*4))
#define SOC_KM_GID_OUT_ADDR(base,n) ((base) + (0x0160+(n)*4))
#define SOC_KM_POS_IN_ADDR(base,n) ((base) + (0x0180+(n)*4))
#define SOC_KM_POS_OUT_ADDR(base,n) ((base) + (0x01A0+(n)*4))
#define SOC_KM_ROTPK_GJ_ADDR(base,n) ((base) + (0x01C0+(n)*4))
#define SOC_KM_ROTPK_GM_ADDR(base,n) ((base) + (0x01E0+(n)*4))
#define SOC_KM_ALARM_CLR_ADDR(base) ((base) + (0x0200))
#define SOC_KM_ALARM_MASK_EN_ADDR(base) ((base) + (0x0204))
#define SOC_KM_ALARM_ADDR(base) ((base) + (0x0208))
#define SOC_KM_ALARM_MASK_ADDR(base) ((base) + (0x020C))
#define SOC_KM_KEY_REG_LOCK_ADDR(base) ((base) + (0x0210))
#define SOC_KM_AESKEY_MASK_VALUE_ADDR(base) ((base) + (0x0214))
#define SOC_KM_DESKEY_MASK_VALUE_ADDR(base) ((base) + (0x0218))
#define SOC_KM_SM4KEY_MASK_VALUE_ADDR(base) ((base) + (0x021C))
#define SOC_KM_AES_KEY_PARITY_ADDR(base) ((base) + (0x0220))
#define SOC_KM_DES_KEY_PARITY_ADDR(base) ((base) + (0x0224))
#define SOC_KM_SM4_KEY_PARITY_ADDR(base) ((base) + (0x0228))
#define SOC_KM_KDR_IN_PARITY_ADDR(base) ((base) + (0x022C))
#define SOC_KM_KDR_OUT_PARITY_ADDR(base) ((base) + (0x0230))
#define SOC_KM_CEK_IN_PARITY_ADDR(base) ((base) + (0x0234))
#define SOC_KM_DERIVE_KEY_PARITY_ADDR(base) ((base) + (0x0238))
#define SOC_KM_CEK_MASK_VALUE_ADDR(base) ((base) + (0x0248))
#define SOC_KM_KEY_MASK_VALUE_ADDR(base) ((base) + (0x024C))
#define SOC_KM_GID_IN_PARITY_ADDR(base) ((base) + (0x0254))
#define SOC_KM_GID_OUT_PARITY_ADDR(base) ((base) + (0x0258))
#define SOC_KM_POS_IN_PARITY_ADDR(base) ((base) + (0x025C))
#define SOC_KM_POS_OUT_PARITY_ADDR(base) ((base) + (0x0260))
#define SOC_KM_ROTPK_GJ_PARITY_ADDR(base) ((base) + (0x0264))
#define SOC_KM_ROTPK_GM_PARITY_ADDR(base) ((base) + (0x0268))
#define SOC_KM_DDRENC_KEY_ADDR(base,n) ((base) + (0x026C+(n)*4))
#define SOC_KM_AES_KEY2_ADDR(base,n) ((base) + (0x0280+(n)*4))
#define SOC_KM_AESKEY2_MASK_VALUE_ADDR(base) ((base) + (0x02A0))
#define SOC_KM_AES_KEY2_PARITY_ADDR(base) ((base) + (0x02A4))
#define SOC_KM_DEBUG_SD_ADDR(base) ((base) + (0x02A8))
#define SOC_KM_DERIVE_KEY_SEC_ADDR(base,n) ((base) + (0x02C0+(n)*4))
#define SOC_KM_DERIVE_KEY_SEC_M_ADDR(base,n) ((base) + (0x0300+(n)*4))
#define SOC_KM_MODE_IND_ADDR(base) ((base) + (0x0400))
#define SOC_KM_MODE1_ADDR(base) ((base) + (0x0404))
#define SOC_KM_AES_KEY_SEL_IND_ADDR(base) ((base) + (0x0408))
#define SOC_KM_AES_KEY_SEL1_ADDR(base) ((base) + (0x040c))
#define SOC_KM_TA_KEY_PLA_CLR_ADDR(base) ((base) + (0x0410))
#define SOC_KM_CEK_CLR_ADDR(base) ((base) + (0x0414))
#define SOC_KM_TA_KEY_PLA_ADDR(base,n) ((base) + (0x0420+(n)*4))
#define SOC_KM_TA_KEY_PLA_M_ADDR(base,n) ((base) + (0x0440+(n)*4))
#define SOC_KM_CEK_PLA_ADDR(base,n) ((base) + (0x0460+(n)*4))
#define SOC_KM_CEK_PLA_M_ADDR(base,n) ((base) + (0x0480+(n)*4))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int km_str : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_KM_STR_UNION;
#endif
#define SOC_KM_STR_km_str_START (0)
#define SOC_KM_STR_km_str_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int des_key_sel : 1;
        unsigned int reserved_0 : 3;
        unsigned int aes_key_sel : 3;
        unsigned int reserved_1 : 1;
        unsigned int sm4_key_sel : 3;
        unsigned int reserved_2 : 1;
        unsigned int km_mode : 2;
        unsigned int ddrenc_key_derive : 1;
        unsigned int kdr_inv : 1;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_KM_MODE_UNION;
#endif
#define SOC_KM_MODE_des_key_sel_START (0)
#define SOC_KM_MODE_des_key_sel_END (0)
#define SOC_KM_MODE_aes_key_sel_START (4)
#define SOC_KM_MODE_aes_key_sel_END (6)
#define SOC_KM_MODE_sm4_key_sel_START (8)
#define SOC_KM_MODE_sm4_key_sel_END (10)
#define SOC_KM_MODE_km_mode_START (12)
#define SOC_KM_MODE_km_mode_END (13)
#define SOC_KM_MODE_ddrenc_key_derive_START (14)
#define SOC_KM_MODE_ddrenc_key_derive_END (14)
#define SOC_KM_MODE_kdr_inv_START (15)
#define SOC_KM_MODE_kdr_inv_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int derive_key_clr : 1;
        unsigned int derive_key_sec_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_KM_DERIVE_KEY_CLR_UNION;
#endif
#define SOC_KM_DERIVE_KEY_CLR_derive_key_clr_START (0)
#define SOC_KM_DERIVE_KEY_CLR_derive_key_clr_END (0)
#define SOC_KM_DERIVE_KEY_CLR_derive_key_sec_clr_START (1)
#define SOC_KM_DERIVE_KEY_CLR_derive_key_sec_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key_decry_done : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_KM_KEY_DECRY_DONE_UNION;
#endif
#define SOC_KM_KEY_DECRY_DONE_key_decry_done_START (0)
#define SOC_KM_KEY_DECRY_DONE_key_decry_done_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key_derive_done : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_KM_KEY_DERIVE_DONE_UNION;
#endif
#define SOC_KM_KEY_DERIVE_DONE_key_derive_done_START (0)
#define SOC_KM_KEY_DERIVE_DONE_key_derive_done_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key_derive_done_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_KM_KEY_DERIVE_DONE_CLR_UNION;
#endif
#define SOC_KM_KEY_DERIVE_DONE_CLR_key_derive_done_clr_START (0)
#define SOC_KM_KEY_DERIVE_DONE_CLR_key_derive_done_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key_decry_state : 16;
        unsigned int keyid_cnt : 1;
        unsigned int reserved_0 : 3;
        unsigned int key_lenth_cnt : 2;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_KM_DFX_UNION;
#endif
#define SOC_KM_DFX_key_decry_state_START (0)
#define SOC_KM_DFX_key_decry_state_END (15)
#define SOC_KM_DFX_keyid_cnt_START (16)
#define SOC_KM_DFX_keyid_cnt_END (16)
#define SOC_KM_DFX_key_lenth_cnt_START (20)
#define SOC_KM_DFX_key_lenth_cnt_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int km_reg_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_REG_LOCK_UNION;
#endif
#define SOC_KM_REG_LOCK_km_reg_lock_START (0)
#define SOC_KM_REG_LOCK_km_reg_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key : 32;
    } reg;
} SOC_KM_AES_KEY_UNION;
#endif
#define SOC_KM_AES_KEY_aes_key_START (0)
#define SOC_KM_AES_KEY_aes_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key : 32;
    } reg;
} SOC_KM_DES_KEY_UNION;
#endif
#define SOC_KM_DES_KEY_aes_key_START (0)
#define SOC_KM_DES_KEY_aes_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key : 32;
    } reg;
} SOC_KM_SM4_KEY_UNION;
#endif
#define SOC_KM_SM4_KEY_aes_key_START (0)
#define SOC_KM_SM4_KEY_aes_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int kdr_in : 32;
    } reg;
} SOC_KM_KDR_IN_UNION;
#endif
#define SOC_KM_KDR_IN_kdr_in_START (0)
#define SOC_KM_KDR_IN_kdr_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int kdr_out : 32;
    } reg;
} SOC_KM_KDR_OUT_UNION;
#endif
#define SOC_KM_KDR_OUT_kdr_out_START (0)
#define SOC_KM_KDR_OUT_kdr_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cek_in : 32;
    } reg;
} SOC_KM_CEK_IN_UNION;
#endif
#define SOC_KM_CEK_IN_cek_in_START (0)
#define SOC_KM_CEK_IN_cek_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int derive_key : 32;
    } reg;
} SOC_KM_DERIVE_KEY_UNION;
#endif
#define SOC_KM_DERIVE_KEY_derive_key_START (0)
#define SOC_KM_DERIVE_KEY_derive_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid_in : 32;
    } reg;
} SOC_KM_GID_IN_UNION;
#endif
#define SOC_KM_GID_IN_gid_in_START (0)
#define SOC_KM_GID_IN_gid_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid_out : 32;
    } reg;
} SOC_KM_GID_OUT_UNION;
#endif
#define SOC_KM_GID_OUT_gid_out_START (0)
#define SOC_KM_GID_OUT_gid_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pos_in : 32;
    } reg;
} SOC_KM_POS_IN_UNION;
#endif
#define SOC_KM_POS_IN_pos_in_START (0)
#define SOC_KM_POS_IN_pos_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pos_out : 32;
    } reg;
} SOC_KM_POS_OUT_UNION;
#endif
#define SOC_KM_POS_OUT_pos_out_START (0)
#define SOC_KM_POS_OUT_pos_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rotpk_gj_out : 32;
    } reg;
} SOC_KM_ROTPK_GJ_UNION;
#endif
#define SOC_KM_ROTPK_GJ_rotpk_gj_out_START (0)
#define SOC_KM_ROTPK_GJ_rotpk_gj_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rotpk_gm_out : 32;
    } reg;
} SOC_KM_ROTPK_GM_UNION;
#endif
#define SOC_KM_ROTPK_GM_rotpk_gm_out_START (0)
#define SOC_KM_ROTPK_GM_rotpk_gm_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_critical_clr : 4;
        unsigned int alarm_reg_check_clr : 4;
        unsigned int alarm_reg_access_clr : 4;
        unsigned int alarm_key_check_clr : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_KM_ALARM_CLR_UNION;
#endif
#define SOC_KM_ALARM_CLR_alarm_critical_clr_START (0)
#define SOC_KM_ALARM_CLR_alarm_critical_clr_END (3)
#define SOC_KM_ALARM_CLR_alarm_reg_check_clr_START (4)
#define SOC_KM_ALARM_CLR_alarm_reg_check_clr_END (7)
#define SOC_KM_ALARM_CLR_alarm_reg_access_clr_START (8)
#define SOC_KM_ALARM_CLR_alarm_reg_access_clr_END (11)
#define SOC_KM_ALARM_CLR_alarm_key_check_clr_START (12)
#define SOC_KM_ALARM_CLR_alarm_key_check_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_critical_mask_en : 4;
        unsigned int alarm_reg_check_mask_en : 4;
        unsigned int alarm_reg_access_mask_en : 4;
        unsigned int alarm_key_check_mask_en : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_KM_ALARM_MASK_EN_UNION;
#endif
#define SOC_KM_ALARM_MASK_EN_alarm_critical_mask_en_START (0)
#define SOC_KM_ALARM_MASK_EN_alarm_critical_mask_en_END (3)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_check_mask_en_START (4)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_check_mask_en_END (7)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_access_mask_en_START (8)
#define SOC_KM_ALARM_MASK_EN_alarm_reg_access_mask_en_END (11)
#define SOC_KM_ALARM_MASK_EN_alarm_key_check_mask_en_START (12)
#define SOC_KM_ALARM_MASK_EN_alarm_key_check_mask_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_critical : 1;
        unsigned int alarm_reg_check : 1;
        unsigned int alarm_reg_access : 1;
        unsigned int alarm_key_check : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_ALARM_UNION;
#endif
#define SOC_KM_ALARM_alarm_critical_START (0)
#define SOC_KM_ALARM_alarm_critical_END (0)
#define SOC_KM_ALARM_alarm_reg_check_START (1)
#define SOC_KM_ALARM_alarm_reg_check_END (1)
#define SOC_KM_ALARM_alarm_reg_access_START (2)
#define SOC_KM_ALARM_alarm_reg_access_END (2)
#define SOC_KM_ALARM_alarm_key_check_START (3)
#define SOC_KM_ALARM_alarm_key_check_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_critical_mask : 1;
        unsigned int alarm_reg_check_mask : 1;
        unsigned int alarm_reg_access_mask : 1;
        unsigned int alarm_key_check : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_ALARM_MASK_UNION;
#endif
#define SOC_KM_ALARM_MASK_alarm_critical_mask_START (0)
#define SOC_KM_ALARM_MASK_alarm_critical_mask_END (0)
#define SOC_KM_ALARM_MASK_alarm_reg_check_mask_START (1)
#define SOC_KM_ALARM_MASK_alarm_reg_check_mask_END (1)
#define SOC_KM_ALARM_MASK_alarm_reg_access_mask_START (2)
#define SOC_KM_ALARM_MASK_alarm_reg_access_mask_END (2)
#define SOC_KM_ALARM_MASK_alarm_key_check_START (3)
#define SOC_KM_ALARM_MASK_alarm_key_check_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_KEY_REG_LOCK_UNION;
#endif
#define SOC_KM_KEY_REG_LOCK_key_lock_START (0)
#define SOC_KM_KEY_REG_LOCK_key_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aeskey_mask_value : 32;
    } reg;
} SOC_KM_AESKEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_AESKEY_MASK_VALUE_aeskey_mask_value_START (0)
#define SOC_KM_AESKEY_MASK_VALUE_aeskey_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int deskey_mask_value : 32;
    } reg;
} SOC_KM_DESKEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_DESKEY_MASK_VALUE_deskey_mask_value_START (0)
#define SOC_KM_DESKEY_MASK_VALUE_deskey_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sm4key_mask_value : 32;
    } reg;
} SOC_KM_SM4KEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_SM4KEY_MASK_VALUE_sm4key_mask_value_START (0)
#define SOC_KM_SM4KEY_MASK_VALUE_sm4key_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key_parity : 32;
    } reg;
} SOC_KM_AES_KEY_PARITY_UNION;
#endif
#define SOC_KM_AES_KEY_PARITY_aes_key_parity_START (0)
#define SOC_KM_AES_KEY_PARITY_aes_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int des_key_parity : 32;
    } reg;
} SOC_KM_DES_KEY_PARITY_UNION;
#endif
#define SOC_KM_DES_KEY_PARITY_des_key_parity_START (0)
#define SOC_KM_DES_KEY_PARITY_des_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sm4_key_parity : 32;
    } reg;
} SOC_KM_SM4_KEY_PARITY_UNION;
#endif
#define SOC_KM_SM4_KEY_PARITY_sm4_key_parity_START (0)
#define SOC_KM_SM4_KEY_PARITY_sm4_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int kdr_in_parity : 32;
    } reg;
} SOC_KM_KDR_IN_PARITY_UNION;
#endif
#define SOC_KM_KDR_IN_PARITY_kdr_in_parity_START (0)
#define SOC_KM_KDR_IN_PARITY_kdr_in_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int kdr_out_parity : 32;
    } reg;
} SOC_KM_KDR_OUT_PARITY_UNION;
#endif
#define SOC_KM_KDR_OUT_PARITY_kdr_out_parity_START (0)
#define SOC_KM_KDR_OUT_PARITY_kdr_out_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cek_in_parity : 32;
    } reg;
} SOC_KM_CEK_IN_PARITY_UNION;
#endif
#define SOC_KM_CEK_IN_PARITY_cek_in_parity_START (0)
#define SOC_KM_CEK_IN_PARITY_cek_in_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int derive_key_parity : 32;
    } reg;
} SOC_KM_DERIVE_KEY_PARITY_UNION;
#endif
#define SOC_KM_DERIVE_KEY_PARITY_derive_key_parity_START (0)
#define SOC_KM_DERIVE_KEY_PARITY_derive_key_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cek_mask_value : 32;
    } reg;
} SOC_KM_CEK_MASK_VALUE_UNION;
#endif
#define SOC_KM_CEK_MASK_VALUE_cek_mask_value_START (0)
#define SOC_KM_CEK_MASK_VALUE_cek_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int key_mask_value : 32;
    } reg;
} SOC_KM_KEY_MASK_VALUE_UNION;
#endif
#define SOC_KM_KEY_MASK_VALUE_key_mask_value_START (0)
#define SOC_KM_KEY_MASK_VALUE_key_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid_in_parity : 32;
    } reg;
} SOC_KM_GID_IN_PARITY_UNION;
#endif
#define SOC_KM_GID_IN_PARITY_gid_in_parity_START (0)
#define SOC_KM_GID_IN_PARITY_gid_in_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gid_out_parity : 32;
    } reg;
} SOC_KM_GID_OUT_PARITY_UNION;
#endif
#define SOC_KM_GID_OUT_PARITY_gid_out_parity_START (0)
#define SOC_KM_GID_OUT_PARITY_gid_out_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pos_in_parity : 32;
    } reg;
} SOC_KM_POS_IN_PARITY_UNION;
#endif
#define SOC_KM_POS_IN_PARITY_pos_in_parity_START (0)
#define SOC_KM_POS_IN_PARITY_pos_in_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pos_out_parity : 32;
    } reg;
} SOC_KM_POS_OUT_PARITY_UNION;
#endif
#define SOC_KM_POS_OUT_PARITY_pos_out_parity_START (0)
#define SOC_KM_POS_OUT_PARITY_pos_out_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rotpk_gj_parity : 32;
    } reg;
} SOC_KM_ROTPK_GJ_PARITY_UNION;
#endif
#define SOC_KM_ROTPK_GJ_PARITY_rotpk_gj_parity_START (0)
#define SOC_KM_ROTPK_GJ_PARITY_rotpk_gj_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rotpk_gm_parity : 32;
    } reg;
} SOC_KM_ROTPK_GM_PARITY_UNION;
#endif
#define SOC_KM_ROTPK_GM_PARITY_rotpk_gm_parity_START (0)
#define SOC_KM_ROTPK_GM_PARITY_rotpk_gm_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ddrenc_key : 32;
    } reg;
} SOC_KM_DDRENC_KEY_UNION;
#endif
#define SOC_KM_DDRENC_KEY_ddrenc_key_START (0)
#define SOC_KM_DDRENC_KEY_ddrenc_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key2 : 32;
    } reg;
} SOC_KM_AES_KEY2_UNION;
#endif
#define SOC_KM_AES_KEY2_aes_key2_START (0)
#define SOC_KM_AES_KEY2_aes_key2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key2_mask_value : 32;
    } reg;
} SOC_KM_AESKEY2_MASK_VALUE_UNION;
#endif
#define SOC_KM_AESKEY2_MASK_VALUE_aes_key2_mask_value_START (0)
#define SOC_KM_AESKEY2_MASK_VALUE_aes_key2_mask_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key2_parity : 32;
    } reg;
} SOC_KM_AES_KEY2_PARITY_UNION;
#endif
#define SOC_KM_AES_KEY2_PARITY_aes_key2_parity_START (0)
#define SOC_KM_AES_KEY2_PARITY_aes_key2_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DEBUG_SD : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_KM_DEBUG_SD_UNION;
#endif
#define SOC_KM_DEBUG_SD_DEBUG_SD_START (0)
#define SOC_KM_DEBUG_SD_DEBUG_SD_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int derive_key_sec : 32;
    } reg;
} SOC_KM_DERIVE_KEY_SEC_UNION;
#endif
#define SOC_KM_DERIVE_KEY_SEC_derive_key_sec_START (0)
#define SOC_KM_DERIVE_KEY_SEC_derive_key_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int derive_key_sec_m : 32;
    } reg;
} SOC_KM_DERIVE_KEY_SEC_M_UNION;
#endif
#define SOC_KM_DERIVE_KEY_SEC_M_derive_key_sec_m_START (0)
#define SOC_KM_DERIVE_KEY_SEC_M_derive_key_sec_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int km_mode_ind : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_MODE_IND_UNION;
#endif
#define SOC_KM_MODE_IND_km_mode_ind_START (0)
#define SOC_KM_MODE_IND_km_mode_ind_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int km_mode1 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_KM_MODE1_UNION;
#endif
#define SOC_KM_MODE1_km_mode1_START (0)
#define SOC_KM_MODE1_km_mode1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key_sel_ind : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_AES_KEY_SEL_IND_UNION;
#endif
#define SOC_KM_AES_KEY_SEL_IND_aes_key_sel_ind_START (0)
#define SOC_KM_AES_KEY_SEL_IND_aes_key_sel_ind_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aes_key_sel1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_KM_AES_KEY_SEL1_UNION;
#endif
#define SOC_KM_AES_KEY_SEL1_aes_key_sel1_START (0)
#define SOC_KM_AES_KEY_SEL1_aes_key_sel1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ta_key_pla_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_KM_TA_KEY_PLA_CLR_UNION;
#endif
#define SOC_KM_TA_KEY_PLA_CLR_ta_key_pla_clr_START (0)
#define SOC_KM_TA_KEY_PLA_CLR_ta_key_pla_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cek_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_KM_CEK_CLR_UNION;
#endif
#define SOC_KM_CEK_CLR_cek_clr_START (0)
#define SOC_KM_CEK_CLR_cek_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ta_key_pla_sec : 32;
    } reg;
} SOC_KM_TA_KEY_PLA_UNION;
#endif
#define SOC_KM_TA_KEY_PLA_ta_key_pla_sec_START (0)
#define SOC_KM_TA_KEY_PLA_ta_key_pla_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ta_key_pla_m : 32;
    } reg;
} SOC_KM_TA_KEY_PLA_M_UNION;
#endif
#define SOC_KM_TA_KEY_PLA_M_ta_key_pla_m_START (0)
#define SOC_KM_TA_KEY_PLA_M_ta_key_pla_m_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cek_pla_sec : 32;
    } reg;
} SOC_KM_CEK_PLA_UNION;
#endif
#define SOC_KM_CEK_PLA_cek_pla_sec_START (0)
#define SOC_KM_CEK_PLA_cek_pla_sec_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cek_pla_m : 32;
    } reg;
} SOC_KM_CEK_PLA_M_UNION;
#endif
#define SOC_KM_CEK_PLA_M_cek_pla_m_START (0)
#define SOC_KM_CEK_PLA_M_cek_pla_m_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
