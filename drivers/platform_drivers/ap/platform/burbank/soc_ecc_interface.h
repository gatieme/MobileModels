#ifndef __SOC_ECC_INTERFACE_H__
#define __SOC_ECC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ECC_BUSY_ADDR(base) ((base) + (0x0000))
#define SOC_ECC_MODE_ADDR(base) ((base) + (0x0004))
#define SOC_ECC_START_ADDR(base) ((base) + (0x0008))
#define SOC_ECC_RAM_CLR_EN_ADDR(base) ((base) + (0x000C))
#define SOC_ECC_RAM_CLR_DONE_ADDR(base) ((base) + (0x0010))
#define SOC_ECC_ORI_INT_ADDR(base) ((base) + (0x0014))
#define SOC_ECC_INT_MSK_ADDR(base) ((base) + (0x0018))
#define SOC_ECC_INT_ECC_ADDR(base) ((base) + (0x001C))
#define SOC_ECC_INT_CLR_ADDR(base) ((base) + (0x0020))
#define SOC_ECC_ALARM_DFA_ORI_ADDR(base) ((base) + (0x0024))
#define SOC_ECC_ALARM_DFA_MSK_ADDR(base) ((base) + (0x0028))
#define SOC_ECC_ALARM_DFA_ADDR(base) ((base) + (0x002C))
#define SOC_ECC_ALARM_DFA_CLR_ADDR(base) ((base) + (0x0030))
#define SOC_ECC_ALARM_PRT_ORI_ADDR(base) ((base) + (0x0034))
#define SOC_ECC_ALARM_PRT_MSK_ADDR(base) ((base) + (0x0038))
#define SOC_ECC_ALARM_PRT_ADDR(base) ((base) + (0x003C))
#define SOC_ECC_ALARM_PRT_CLR_ADDR(base) ((base) + (0x0040))
#define SOC_ECC_POINT_RESULT_INFI_ADDR(base) ((base) + (0x0044))
#define SOC_ECC_KEY_MSK_ADDR(base) ((base) + (0x0048))
#define SOC_ECC_KEY_BACKUP_ADDR(base) ((base) + (0x004C))
#define SOC_ECC_SCRAMB_EN_ADDR(base) ((base) + (0x0050))
#define SOC_ECC_LOCK_ADDR(base) ((base) + (0x0054))
#define SOC_ECC_KEY_LOCK_ADDR(base) ((base) + (0x0058))
#define SOC_ECC_DEBUG_UNMASK_ADDR(base) ((base) + (0x005C))
#define SOC_ECC_EC_PX1_ADDR(base,n) ((base) + (0x0100+4*(n)))
#define SOC_ECC_EC_PY1_ADDR(base,n) ((base) + (0x0148+4*(n)))
#define SOC_ECC_EC_PX2_ADDR(base,n) ((base) + (0x0190+4*(n)))
#define SOC_ECC_EC_PY2_ADDR(base,n) ((base) + (0x01D8+4*(n)))
#define SOC_ECC_OPRAND_N_ADDR(base,n) ((base) + (0x0220+4*(n)))
#define SOC_ECC_OPRAND_C_ADDR(base,n) ((base) + (0x0268+4*(n)))
#define SOC_ECC_RESULT_X_ADDR(base,n) ((base) + (0x02B0+4*(n)))
#define SOC_ECC_RESULT_Y_ADDR(base,n) ((base) + (0x02F8+4*(n)))
#define SOC_ECC_MUL_K_ADDR(base,n) ((base) + (0x0340+4*(n)))
#define SOC_ECC_EC_PARA_P_ADDR(base,n) ((base) + (0x0388+4*(n)))
#define SOC_ECC_EC_PARA_A_ADDR(base,n) ((base) + (0x03D0+4*(n)))
#define SOC_ECC_EC_PARA_B_ADDR(base,n) ((base) + (0x0418+4*(n)))
#define SOC_ECC_EC_PARA_N_ADDR(base,n) ((base) + (0x0460+4*(n)))
#define SOC_ECC_EC_PARA_GX_ADDR(base,n) ((base) + (0x04A8+4*(n)))
#define SOC_ECC_EC_PARA_GY_ADDR(base,n) ((base) + (0x04F0+4*(n)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_busy : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_BUSY_UNION;
#endif
#define SOC_ECC_BUSY_ecc_busy_START (0)
#define SOC_ECC_BUSY_ecc_busy_END (3)
#define SOC_ECC_BUSY_reverved_START (4)
#define SOC_ECC_BUSY_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 4;
        unsigned int length : 4;
        unsigned int reverved : 24;
    } reg;
} SOC_ECC_MODE_UNION;
#endif
#define SOC_ECC_MODE_mode_START (0)
#define SOC_ECC_MODE_mode_END (3)
#define SOC_ECC_MODE_length_START (4)
#define SOC_ECC_MODE_length_END (7)
#define SOC_ECC_MODE_reverved_START (8)
#define SOC_ECC_MODE_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_start : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_START_UNION;
#endif
#define SOC_ECC_START_ecc_start_START (0)
#define SOC_ECC_START_ecc_start_END (3)
#define SOC_ECC_START_reverved_START (4)
#define SOC_ECC_START_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_ram_clr_en : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_RAM_CLR_EN_UNION;
#endif
#define SOC_ECC_RAM_CLR_EN_ecc_ram_clr_en_START (0)
#define SOC_ECC_RAM_CLR_EN_ecc_ram_clr_en_END (3)
#define SOC_ECC_RAM_CLR_EN_reverved_START (4)
#define SOC_ECC_RAM_CLR_EN_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_ram_clr_done : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_RAM_CLR_DONE_UNION;
#endif
#define SOC_ECC_RAM_CLR_DONE_ecc_ram_clr_done_START (0)
#define SOC_ECC_RAM_CLR_DONE_ecc_ram_clr_done_END (3)
#define SOC_ECC_RAM_CLR_DONE_reverved_START (4)
#define SOC_ECC_RAM_CLR_DONE_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_ori_int : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ORI_INT_UNION;
#endif
#define SOC_ECC_ORI_INT_ecc_ori_int_START (0)
#define SOC_ECC_ORI_INT_ecc_ori_int_END (3)
#define SOC_ECC_ORI_INT_reverved_START (4)
#define SOC_ECC_ORI_INT_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_int_msk : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_INT_MSK_UNION;
#endif
#define SOC_ECC_INT_MSK_ecc_int_msk_START (0)
#define SOC_ECC_INT_MSK_ecc_int_msk_END (3)
#define SOC_ECC_INT_MSK_reverved_START (4)
#define SOC_ECC_INT_MSK_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_ecc : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_INT_ECC_UNION;
#endif
#define SOC_ECC_INT_ECC_int_ecc_START (0)
#define SOC_ECC_INT_ECC_int_ecc_END (3)
#define SOC_ECC_INT_ECC_reverved_START (4)
#define SOC_ECC_INT_ECC_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_int_clr : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_INT_CLR_UNION;
#endif
#define SOC_ECC_INT_CLR_ecc_int_clr_START (0)
#define SOC_ECC_INT_CLR_ecc_int_clr_END (3)
#define SOC_ECC_INT_CLR_reverved_START (4)
#define SOC_ECC_INT_CLR_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_dfa_ori : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_DFA_ORI_UNION;
#endif
#define SOC_ECC_ALARM_DFA_ORI_alarm_dfa_ori_START (0)
#define SOC_ECC_ALARM_DFA_ORI_alarm_dfa_ori_END (3)
#define SOC_ECC_ALARM_DFA_ORI_reverved_START (4)
#define SOC_ECC_ALARM_DFA_ORI_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_dfa_msk : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_DFA_MSK_UNION;
#endif
#define SOC_ECC_ALARM_DFA_MSK_alarm_dfa_msk_START (0)
#define SOC_ECC_ALARM_DFA_MSK_alarm_dfa_msk_END (3)
#define SOC_ECC_ALARM_DFA_MSK_reverved_START (4)
#define SOC_ECC_ALARM_DFA_MSK_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_dfa : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_DFA_UNION;
#endif
#define SOC_ECC_ALARM_DFA_alarm_dfa_START (0)
#define SOC_ECC_ALARM_DFA_alarm_dfa_END (3)
#define SOC_ECC_ALARM_DFA_reverved_START (4)
#define SOC_ECC_ALARM_DFA_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_dfa_clr : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_DFA_CLR_UNION;
#endif
#define SOC_ECC_ALARM_DFA_CLR_alarm_dfa_clr_START (0)
#define SOC_ECC_ALARM_DFA_CLR_alarm_dfa_clr_END (3)
#define SOC_ECC_ALARM_DFA_CLR_reverved_START (4)
#define SOC_ECC_ALARM_DFA_CLR_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_prt_ori : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_PRT_ORI_UNION;
#endif
#define SOC_ECC_ALARM_PRT_ORI_alarm_prt_ori_START (0)
#define SOC_ECC_ALARM_PRT_ORI_alarm_prt_ori_END (3)
#define SOC_ECC_ALARM_PRT_ORI_reverved_START (4)
#define SOC_ECC_ALARM_PRT_ORI_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_prt_msk : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_PRT_MSK_UNION;
#endif
#define SOC_ECC_ALARM_PRT_MSK_alarm_prt_msk_START (0)
#define SOC_ECC_ALARM_PRT_MSK_alarm_prt_msk_END (3)
#define SOC_ECC_ALARM_PRT_MSK_reverved_START (4)
#define SOC_ECC_ALARM_PRT_MSK_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_prt : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_PRT_UNION;
#endif
#define SOC_ECC_ALARM_PRT_alarm_prt_START (0)
#define SOC_ECC_ALARM_PRT_alarm_prt_END (3)
#define SOC_ECC_ALARM_PRT_reverved_START (4)
#define SOC_ECC_ALARM_PRT_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int alarm_prt_clr : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_ALARM_PRT_CLR_UNION;
#endif
#define SOC_ECC_ALARM_PRT_CLR_alarm_prt_clr_START (0)
#define SOC_ECC_ALARM_PRT_CLR_alarm_prt_clr_END (3)
#define SOC_ECC_ALARM_PRT_CLR_reverved_START (4)
#define SOC_ECC_ALARM_PRT_CLR_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int point_result_infi : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_POINT_RESULT_INFI_UNION;
#endif
#define SOC_ECC_POINT_RESULT_INFI_point_result_infi_START (0)
#define SOC_ECC_POINT_RESULT_INFI_point_result_infi_END (3)
#define SOC_ECC_POINT_RESULT_INFI_reverved_START (4)
#define SOC_ECC_POINT_RESULT_INFI_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_key_msk : 32;
    } reg;
} SOC_ECC_KEY_MSK_UNION;
#endif
#define SOC_ECC_KEY_MSK_ecc_key_msk_START (0)
#define SOC_ECC_KEY_MSK_ecc_key_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_key_backup : 32;
    } reg;
} SOC_ECC_KEY_BACKUP_UNION;
#endif
#define SOC_ECC_KEY_BACKUP_ecc_key_backup_START (0)
#define SOC_ECC_KEY_BACKUP_ecc_key_backup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_scramb_en : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_SCRAMB_EN_UNION;
#endif
#define SOC_ECC_SCRAMB_EN_ecc_scramb_en_START (0)
#define SOC_ECC_SCRAMB_EN_ecc_scramb_en_END (3)
#define SOC_ECC_SCRAMB_EN_reverved_START (4)
#define SOC_ECC_SCRAMB_EN_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_lock : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_LOCK_UNION;
#endif
#define SOC_ECC_LOCK_ecc_lock_START (0)
#define SOC_ECC_LOCK_ecc_lock_END (3)
#define SOC_ECC_LOCK_reverved_START (4)
#define SOC_ECC_LOCK_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_key_lock : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_KEY_LOCK_UNION;
#endif
#define SOC_ECC_KEY_LOCK_ecc_key_lock_START (0)
#define SOC_ECC_KEY_LOCK_ecc_key_lock_END (3)
#define SOC_ECC_KEY_LOCK_reverved_START (4)
#define SOC_ECC_KEY_LOCK_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ecc_debug_unmask : 4;
        unsigned int reverved : 28;
    } reg;
} SOC_ECC_DEBUG_UNMASK_UNION;
#endif
#define SOC_ECC_DEBUG_UNMASK_ecc_debug_unmask_START (0)
#define SOC_ECC_DEBUG_UNMASK_ecc_debug_unmask_END (3)
#define SOC_ECC_DEBUG_UNMASK_reverved_START (4)
#define SOC_ECC_DEBUG_UNMASK_reverved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_px1 : 32;
    } reg;
} SOC_ECC_EC_PX1_UNION;
#endif
#define SOC_ECC_EC_PX1_ec_px1_START (0)
#define SOC_ECC_EC_PX1_ec_px1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_py1 : 32;
    } reg;
} SOC_ECC_EC_PY1_UNION;
#endif
#define SOC_ECC_EC_PY1_ec_py1_START (0)
#define SOC_ECC_EC_PY1_ec_py1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_px2 : 32;
    } reg;
} SOC_ECC_EC_PX2_UNION;
#endif
#define SOC_ECC_EC_PX2_ec_px2_START (0)
#define SOC_ECC_EC_PX2_ec_px2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_py2 : 32;
    } reg;
} SOC_ECC_EC_PY2_UNION;
#endif
#define SOC_ECC_EC_PY2_ec_py2_START (0)
#define SOC_ECC_EC_PY2_ec_py2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int oprand_n : 32;
    } reg;
} SOC_ECC_OPRAND_N_UNION;
#endif
#define SOC_ECC_OPRAND_N_oprand_n_START (0)
#define SOC_ECC_OPRAND_N_oprand_n_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int oprand_c : 32;
    } reg;
} SOC_ECC_OPRAND_C_UNION;
#endif
#define SOC_ECC_OPRAND_C_oprand_c_START (0)
#define SOC_ECC_OPRAND_C_oprand_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int result_x : 32;
    } reg;
} SOC_ECC_RESULT_X_UNION;
#endif
#define SOC_ECC_RESULT_X_result_x_START (0)
#define SOC_ECC_RESULT_X_result_x_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int result_y : 32;
    } reg;
} SOC_ECC_RESULT_Y_UNION;
#endif
#define SOC_ECC_RESULT_Y_result_y_START (0)
#define SOC_ECC_RESULT_Y_result_y_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mul_k : 32;
    } reg;
} SOC_ECC_MUL_K_UNION;
#endif
#define SOC_ECC_MUL_K_mul_k_START (0)
#define SOC_ECC_MUL_K_mul_k_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_para_p : 32;
    } reg;
} SOC_ECC_EC_PARA_P_UNION;
#endif
#define SOC_ECC_EC_PARA_P_ec_para_p_START (0)
#define SOC_ECC_EC_PARA_P_ec_para_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_para_a : 32;
    } reg;
} SOC_ECC_EC_PARA_A_UNION;
#endif
#define SOC_ECC_EC_PARA_A_ec_para_a_START (0)
#define SOC_ECC_EC_PARA_A_ec_para_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_para_b : 32;
    } reg;
} SOC_ECC_EC_PARA_B_UNION;
#endif
#define SOC_ECC_EC_PARA_B_ec_para_b_START (0)
#define SOC_ECC_EC_PARA_B_ec_para_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_para_n : 32;
    } reg;
} SOC_ECC_EC_PARA_N_UNION;
#endif
#define SOC_ECC_EC_PARA_N_ec_para_n_START (0)
#define SOC_ECC_EC_PARA_N_ec_para_n_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_para_gx : 32;
    } reg;
} SOC_ECC_EC_PARA_GX_UNION;
#endif
#define SOC_ECC_EC_PARA_GX_ec_para_gx_START (0)
#define SOC_ECC_EC_PARA_GX_ec_para_gx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_para_gy : 32;
    } reg;
} SOC_ECC_EC_PARA_GY_UNION;
#endif
#define SOC_ECC_EC_PARA_GY_ec_para_gy_START (0)
#define SOC_ECC_EC_PARA_GY_ec_para_gy_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
