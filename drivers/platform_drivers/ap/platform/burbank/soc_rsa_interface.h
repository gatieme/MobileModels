#ifndef __SOC_RSA_INTERFACE_H__
#define __SOC_RSA_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_RSA_BUSY_ADDR(base) ((base) + (0x0000))
#define SOC_RSA_WORK_MODE_ADDR(base) ((base) + (0x0004))
#define SOC_RSA_START_ADDR(base) ((base) + (0x0008))
#define SOC_RSA_DEBUG_EN_ADDR(base) ((base) + (0x0010))
#define SOC_RSA_RNG_OPTION_ADDR(base) ((base) + (0x0014))
#define SOC_RSA_NEW_ALARM_MASK_ADDR(base) ((base) + (0x0018))
#define SOC_RSA_INT_MASK_ADDR(base) ((base) + (0x0020))
#define SOC_RSA_INT_STATUS_ADDR(base) ((base) + (0x0024))
#define SOC_RSA_INT_NOMASK_STATUS_ADDR(base) ((base) + (0x0028))
#define SOC_RSA_INT_CLR_ADDR(base) ((base) + (0x002C))
#define SOC_RSA_ALARM_MASK_ADDR(base) ((base) + (0x0030))
#define SOC_RSA_ALARM_STATUS_ADDR(base) ((base) + (0x0034))
#define SOC_RSA_ALARM_NOMASK_STATUS_ADDR(base) ((base) + (0x0038))
#define SOC_RSA_ALARM_CLR_ADDR(base) ((base) + (0x003C))
#define SOC_RSA_RESULT_FLAG_ADDR(base) ((base) + (0x0040))
#define SOC_RSA_FAILURE_FLAG_ADDR(base) ((base) + (0x0044))
#define SOC_RSA_STAT_CLR_ADDR(base) ((base) + (0x0050))
#define SOC_RSA_KEY_MSK_ADDR(base) ((base) + (0x0054))
#define SOC_RSA_KEY_BACKUP_ADDR(base) ((base) + (0x0058))
#define SOC_RSA_LOCK_ADDR(base) ((base) + (0x005C))
#define SOC_RSA_KEY_LOCK_ADDR(base) ((base) + (0x0060))
#define SOC_RSA_VERSION_ID_ADDR(base) ((base) + (0x007C))
#define SOC_RSA_LSB_N_EQUAL_ONE_ADDR(base) ((base) + (0x0080))
#define SOC_RSA_MRAM_ADDR(base,n) ((base) + (0x0200+(n)*4))
#define SOC_RSA_NRAM_ADDR(base,n) ((base) + (0x0600+(n)*4))
#define SOC_RSA_KRAM_ADDR(base,n) ((base) + (0x0A00+(n)*4))
#define SOC_RSA_RRAM_ADDR(base,n) ((base) + (0x0E00+(n)*4))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_RSA_BUSY_UNION;
#endif
#define SOC_RSA_BUSY_rsa_busy_START (0)
#define SOC_RSA_BUSY_rsa_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int opcode : 4;
        unsigned int reserved_0: 4;
        unsigned int mode : 8;
        unsigned int reserved_1: 16;
    } reg;
} SOC_RSA_WORK_MODE_UNION;
#endif
#define SOC_RSA_WORK_MODE_opcode_START (0)
#define SOC_RSA_WORK_MODE_opcode_END (3)
#define SOC_RSA_WORK_MODE_mode_START (8)
#define SOC_RSA_WORK_MODE_mode_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_start : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_RSA_START_UNION;
#endif
#define SOC_RSA_START_rsa_start_START (0)
#define SOC_RSA_START_rsa_start_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_debug_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_RSA_DEBUG_EN_UNION;
#endif
#define SOC_RSA_DEBUG_EN_rsa_debug_en_START (0)
#define SOC_RSA_DEBUG_EN_rsa_debug_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_rng_option : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_RSA_RNG_OPTION_UNION;
#endif
#define SOC_RSA_RNG_OPTION_rsa_rng_option_START (0)
#define SOC_RSA_RNG_OPTION_rsa_rng_option_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_new_alarm_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_RSA_NEW_ALARM_MASK_UNION;
#endif
#define SOC_RSA_NEW_ALARM_MASK_rsa_new_alarm_mask_START (0)
#define SOC_RSA_NEW_ALARM_MASK_rsa_new_alarm_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int finish_int_mask : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_RSA_INT_MASK_UNION;
#endif
#define SOC_RSA_INT_MASK_finish_int_mask_START (0)
#define SOC_RSA_INT_MASK_finish_int_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int finish_int_status : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_RSA_INT_STATUS_UNION;
#endif
#define SOC_RSA_INT_STATUS_finish_int_status_START (0)
#define SOC_RSA_INT_STATUS_finish_int_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int finish_int_nomsk_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_RSA_INT_NOMASK_STATUS_UNION;
#endif
#define SOC_RSA_INT_NOMASK_STATUS_finish_int_nomsk_status_START (0)
#define SOC_RSA_INT_NOMASK_STATUS_finish_int_nomsk_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int finish_int_clr : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_RSA_INT_CLR_UNION;
#endif
#define SOC_RSA_INT_CLR_finish_int_clr_START (0)
#define SOC_RSA_INT_CLR_finish_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_dfa_alarm_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_RSA_ALARM_MASK_UNION;
#endif
#define SOC_RSA_ALARM_MASK_rsa_dfa_alarm_mask_START (0)
#define SOC_RSA_ALARM_MASK_rsa_dfa_alarm_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_dfa_alarm_status : 1;
        unsigned int rsa_attack_alarm_status : 1;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_RSA_ALARM_STATUS_UNION;
#endif
#define SOC_RSA_ALARM_STATUS_rsa_dfa_alarm_status_START (0)
#define SOC_RSA_ALARM_STATUS_rsa_dfa_alarm_status_END (0)
#define SOC_RSA_ALARM_STATUS_rsa_attack_alarm_status_START (1)
#define SOC_RSA_ALARM_STATUS_rsa_attack_alarm_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_dfa_alarm_nomask_status : 1;
        unsigned int rsa_attack_alarm_nomask_status : 1;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_RSA_ALARM_NOMASK_STATUS_UNION;
#endif
#define SOC_RSA_ALARM_NOMASK_STATUS_rsa_dfa_alarm_nomask_status_START (0)
#define SOC_RSA_ALARM_NOMASK_STATUS_rsa_dfa_alarm_nomask_status_END (0)
#define SOC_RSA_ALARM_NOMASK_STATUS_rsa_attack_alarm_nomask_status_START (1)
#define SOC_RSA_ALARM_NOMASK_STATUS_rsa_attack_alarm_nomask_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_dfa_alarm_clr : 4;
        unsigned int rsa_attack_alarm_clr : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_RSA_ALARM_CLR_UNION;
#endif
#define SOC_RSA_ALARM_CLR_rsa_dfa_alarm_clr_START (0)
#define SOC_RSA_ALARM_CLR_rsa_dfa_alarm_clr_END (3)
#define SOC_RSA_ALARM_CLR_rsa_attack_alarm_clr_START (4)
#define SOC_RSA_ALARM_CLR_rsa_attack_alarm_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_result_flag : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_RSA_RESULT_FLAG_UNION;
#endif
#define SOC_RSA_RESULT_FLAG_rsa_result_flag_START (0)
#define SOC_RSA_RESULT_FLAG_rsa_result_flag_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_failure_flag : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_RSA_FAILURE_FLAG_UNION;
#endif
#define SOC_RSA_FAILURE_FLAG_rsa_failure_flag_START (0)
#define SOC_RSA_FAILURE_FLAG_rsa_failure_flag_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_stat_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_RSA_STAT_CLR_UNION;
#endif
#define SOC_RSA_STAT_CLR_rsa_stat_clr_START (0)
#define SOC_RSA_STAT_CLR_rsa_stat_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_key_msk : 32;
    } reg;
} SOC_RSA_KEY_MSK_UNION;
#endif
#define SOC_RSA_KEY_MSK_rsa_key_msk_START (0)
#define SOC_RSA_KEY_MSK_rsa_key_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_key_backup : 32;
    } reg;
} SOC_RSA_KEY_BACKUP_UNION;
#endif
#define SOC_RSA_KEY_BACKUP_rsa_key_backup_START (0)
#define SOC_RSA_KEY_BACKUP_rsa_key_backup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_RSA_LOCK_UNION;
#endif
#define SOC_RSA_LOCK_rsa_lock_START (0)
#define SOC_RSA_LOCK_rsa_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsa_key_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_RSA_KEY_LOCK_UNION;
#endif
#define SOC_RSA_KEY_LOCK_rsa_key_lock_START (0)
#define SOC_RSA_KEY_LOCK_rsa_key_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rs_version_id : 32;
    } reg;
} SOC_RSA_VERSION_ID_UNION;
#endif
#define SOC_RSA_VERSION_ID_rs_version_id_START (0)
#define SOC_RSA_VERSION_ID_rs_version_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_RSA_LSB_N_EQUAL_ONE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mram : 32;
    } reg;
} SOC_RSA_MRAM_UNION;
#endif
#define SOC_RSA_MRAM_mram_START (0)
#define SOC_RSA_MRAM_mram_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nram : 32;
    } reg;
} SOC_RSA_NRAM_UNION;
#endif
#define SOC_RSA_NRAM_nram_START (0)
#define SOC_RSA_NRAM_nram_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int kram : 32;
    } reg;
} SOC_RSA_KRAM_UNION;
#endif
#define SOC_RSA_KRAM_kram_START (0)
#define SOC_RSA_KRAM_kram_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rram : 32;
    } reg;
} SOC_RSA_RRAM_UNION;
#endif
#define SOC_RSA_RRAM_rram_START (0)
#define SOC_RSA_RRAM_rram_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
