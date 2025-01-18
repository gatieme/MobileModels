#ifndef __SOC_UFS_L3_INTERFACE_H__
#define __SOC_UFS_L3_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_L3_N_Device_ID_ADDR(base) ((base) + (0x3000UL))
#define SOC_UFS_L3_N_DeviceID_valid_ADDR(base) ((base) + (0x3001UL))
#define SOC_UFS_L3_N_TC0TxMaxSDUSize_ADDR(base) ((base) + (0x3020UL))
#define SOC_UFS_L3_N_TC1TxMaxSDUSize_ADDR(base) ((base) + (0x3021UL))
#define SOC_UFS_L3_N_IMPLATION_DEF0_ADDR(base) ((base) + (0xb000UL))
#else
#define SOC_UFS_L3_N_Device_ID_ADDR(base) ((base) + (0x3000))
#define SOC_UFS_L3_N_DeviceID_valid_ADDR(base) ((base) + (0x3001))
#define SOC_UFS_L3_N_TC0TxMaxSDUSize_ADDR(base) ((base) + (0x3020))
#define SOC_UFS_L3_N_TC1TxMaxSDUSize_ADDR(base) ((base) + (0x3021))
#define SOC_UFS_L3_N_IMPLATION_DEF0_ADDR(base) ((base) + (0xb000))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Device_ID : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_UFS_L3_N_Device_ID_UNION;
#endif
#define SOC_UFS_L3_N_Device_ID_Device_ID_START (0)
#define SOC_UFS_L3_N_Device_ID_Device_ID_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DeviceID_valid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L3_N_DeviceID_valid_UNION;
#endif
#define SOC_UFS_L3_N_DeviceID_valid_DeviceID_valid_START (0)
#define SOC_UFS_L3_N_DeviceID_valid_DeviceID_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tc0txmaxsdusize : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_UFS_L3_N_TC0TxMaxSDUSize_UNION;
#endif
#define SOC_UFS_L3_N_TC0TxMaxSDUSize_tc0txmaxsdusize_START (0)
#define SOC_UFS_L3_N_TC0TxMaxSDUSize_tc0txmaxsdusize_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tc1txmaxsdusize : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_UFS_L3_N_TC1TxMaxSDUSize_UNION;
#endif
#define SOC_UFS_L3_N_TC1TxMaxSDUSize_tc1txmaxsdusize_START (0)
#define SOC_UFS_L3_N_TC1TxMaxSDUSize_tc1txmaxsdusize_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdu_size_check_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L3_N_IMPLATION_DEF0_UNION;
#endif
#define SOC_UFS_L3_N_IMPLATION_DEF0_sdu_size_check_dis_START (0)
#define SOC_UFS_L3_N_IMPLATION_DEF0_sdu_size_check_dis_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
