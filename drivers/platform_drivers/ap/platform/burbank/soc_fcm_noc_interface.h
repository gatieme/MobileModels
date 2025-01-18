#ifndef __SOC_FCM_NOC_INTERFACE_H__
#define __SOC_FCM_NOC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_NOC_FCMBUS_ERR_ID_COREID_ADDR(base) ((base) + (0x1C00UL))
#define SOC_FCM_NOC_FCMBUS_ERR_ID_REVISIONID_ADDR(base) ((base) + (0x1C04UL))
#define SOC_FCM_NOC_FCMBUS_ERR_FAULTEN_ADDR(base) ((base) + (0x1C08UL))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRVLD_ADDR(base) ((base) + (0x1C0CUL))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRCLR_ADDR(base) ((base) + (0x1C10UL))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_ADDR(base) ((base) + (0x1C14UL))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG1_ADDR(base) ((base) + (0x1C18UL))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG3_ADDR(base) ((base) + (0x1C20UL))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG5_ADDR(base) ((base) + (0x1C28UL))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG7_ADDR(base) ((base) + (0x1C30UL))
#define SOC_FCM_NOC_FCMBUS_ERR_STALLEN_ADDR(base) ((base) + (0x1C38UL))
#else
#define SOC_FCM_NOC_FCMBUS_ERR_ID_COREID_ADDR(base) ((base) + (0x1C00))
#define SOC_FCM_NOC_FCMBUS_ERR_ID_REVISIONID_ADDR(base) ((base) + (0x1C04))
#define SOC_FCM_NOC_FCMBUS_ERR_FAULTEN_ADDR(base) ((base) + (0x1C08))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRVLD_ADDR(base) ((base) + (0x1C0C))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRCLR_ADDR(base) ((base) + (0x1C10))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_ADDR(base) ((base) + (0x1C14))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG1_ADDR(base) ((base) + (0x1C18))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG3_ADDR(base) ((base) + (0x1C20))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG5_ADDR(base) ((base) + (0x1C28))
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG7_ADDR(base) ((base) + (0x1C30))
#define SOC_FCM_NOC_FCMBUS_ERR_STALLEN_ADDR(base) ((base) + (0x1C38))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ID_COREID_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ID_COREID_coretypeid_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ID_COREID_coretypeid_END (7)
#define SOC_FCM_NOC_FCMBUS_ERR_ID_COREID_corechecksum_START (8)
#define SOC_FCM_NOC_FCMBUS_ERR_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ID_REVISIONID_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ID_REVISIONID_userid_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ID_REVISIONID_userid_END (7)
#define SOC_FCM_NOC_FCMBUS_ERR_ID_REVISIONID_flexnocid_START (8)
#define SOC_FCM_NOC_FCMBUS_ERR_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int faulten : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_FAULTEN_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_FAULTEN_faulten_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_FAULTEN_faulten_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errvld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ERRVLD_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ERRVLD_errvld_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRVLD_errvld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errclr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ERRCLR_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ERRCLR_errclr_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRCLR_errclr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lock : 1;
        unsigned int opc : 4;
        unsigned int reserved_0: 3;
        unsigned int errcode : 3;
        unsigned int reserved_1: 5;
        unsigned int len1 : 7;
        unsigned int reserved_2: 8;
        unsigned int format : 1;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_lock_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_lock_END (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_opc_START (1)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_opc_END (4)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_errcode_START (8)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_errcode_END (10)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_len1_START (16)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_len1_END (22)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_format_START (31)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG0_format_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ERRLOG1_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG1_errlog1_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG1_errlog1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog3 : 32;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ERRLOG3_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG3_errlog3_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG3_errlog3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog5 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ERRLOG5_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG5_errlog5_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG5_errlog5_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog7 : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_ERRLOG7_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG7_errlog7_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_ERRLOG7_errlog7_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stallen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_NOC_FCMBUS_ERR_STALLEN_UNION;
#endif
#define SOC_FCM_NOC_FCMBUS_ERR_STALLEN_stallen_START (0)
#define SOC_FCM_NOC_FCMBUS_ERR_STALLEN_stallen_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
