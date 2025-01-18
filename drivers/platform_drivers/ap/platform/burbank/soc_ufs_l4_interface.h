#ifndef __SOC_UFS_L4_INTERFACE_H__
#define __SOC_UFS_L4_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_L4_T_NumCPorts_ADDR(base) ((base) + (0x4000UL))
#define SOC_UFS_L4_T_NumTestFeatures_ADDR(base) ((base) + (0x4001UL))
#define SOC_UFS_L4_T_ConnectionState_ADDR(base) ((base) + (0x4020UL))
#define SOC_UFS_L4_T_PeerDeviceID_ADDR(base) ((base) + (0x4021UL))
#define SOC_UFS_L4_T_PeerCPortID_ADDR(base) ((base) + (0x4022UL))
#define SOC_UFS_L4_T_TrafficClass_ADDR(base) ((base) + (0x4023UL))
#define SOC_UFS_L4_T_ProtocolID_ADDR(base) ((base) + (0x4024UL))
#define SOC_UFS_L4_T_CPortFlags_ADDR(base) ((base) + (0x4025UL))
#define SOC_UFS_L4_T_TxTokenValue_ADDR(base) ((base) + (0x4026UL))
#define SOC_UFS_L4_T_RxTokenValue_ADDR(base) ((base) + (0x4027UL))
#define SOC_UFS_L4_T_LocalBufferSpace_ADDR(base) ((base) + (0x4028UL))
#define SOC_UFS_L4_T_PeerBufferSpace_ADDR(base) ((base) + (0x4029UL))
#define SOC_UFS_L4_T_CreditsToSend_ADDR(base) ((base) + (0x402AUL))
#define SOC_UFS_L4_T_CPortMode_ADDR(base) ((base) + (0x402BUL))
#define SOC_UFS_L4_T_TC0TxMaxSDUSize_ADDR(base) ((base) + (0x4060UL))
#define SOC_UFS_L4_T_TC1TxMaxSDUSize_ADDR(base) ((base) + (0x4061UL))
#define SOC_UFS_L4_T_TstCPortID_ADDR(base) ((base) + (0x4080UL))
#define SOC_UFS_L4_T_TstSrcOn_ADDR(base) ((base) + (0x4081UL))
#define SOC_UFS_L4_T_TstSrcPattern_ADDR(base) ((base) + (0x4082UL))
#define SOC_UFS_L4_T_TstSrcIncrement_ADDR(base) ((base) + (0x4083UL))
#define SOC_UFS_L4_T_TstSrcMessageSize_ADDR(base) ((base) + (0x4084UL))
#define SOC_UFS_L4_T_TstSrcMessageCount_ADDR(base) ((base) + (0x4085UL))
#define SOC_UFS_L4_T_TstSrcInterMessageGap_ADDR(base) ((base) + (0x4086UL))
#define SOC_UFS_L4_T_TstDstOn_ADDR(base) ((base) + (0x40A1UL))
#define SOC_UFS_L4_T_TstDstErrorDetectionEnable_ADDR(base) ((base) + (0x40A2UL))
#define SOC_UFS_L4_T_TstDstPattern_ADDR(base) ((base) + (0x40A3UL))
#define SOC_UFS_L4_T_TstDstIncrement_ADDR(base) ((base) + (0x40A4UL))
#define SOC_UFS_L4_T_TstDstMessageCount_ADDR(base) ((base) + (0x40A5UL))
#define SOC_UFS_L4_T_TstDstMessageOffset_ADDR(base) ((base) + (0x40A6UL))
#define SOC_UFS_L4_T_TstDstMessageSize_ADDR(base) ((base) + (0x40A7UL))
#define SOC_UFS_L4_T_TstDstFCCredits_ADDR(base) ((base) + (0x40A8UL))
#define SOC_UFS_L4_T_TstDstInterFCTokenGap_ADDR(base) ((base) + (0x40A9UL))
#define SOC_UFS_L4_T_TstDstInitialFCCredits_ADDR(base) ((base) + (0x40AAUL))
#define SOC_UFS_L4_T_TstDstErrorCode_ADDR(base) ((base) + (0x40ABUL))
#else
#define SOC_UFS_L4_T_NumCPorts_ADDR(base) ((base) + (0x4000))
#define SOC_UFS_L4_T_NumTestFeatures_ADDR(base) ((base) + (0x4001))
#define SOC_UFS_L4_T_ConnectionState_ADDR(base) ((base) + (0x4020))
#define SOC_UFS_L4_T_PeerDeviceID_ADDR(base) ((base) + (0x4021))
#define SOC_UFS_L4_T_PeerCPortID_ADDR(base) ((base) + (0x4022))
#define SOC_UFS_L4_T_TrafficClass_ADDR(base) ((base) + (0x4023))
#define SOC_UFS_L4_T_ProtocolID_ADDR(base) ((base) + (0x4024))
#define SOC_UFS_L4_T_CPortFlags_ADDR(base) ((base) + (0x4025))
#define SOC_UFS_L4_T_TxTokenValue_ADDR(base) ((base) + (0x4026))
#define SOC_UFS_L4_T_RxTokenValue_ADDR(base) ((base) + (0x4027))
#define SOC_UFS_L4_T_LocalBufferSpace_ADDR(base) ((base) + (0x4028))
#define SOC_UFS_L4_T_PeerBufferSpace_ADDR(base) ((base) + (0x4029))
#define SOC_UFS_L4_T_CreditsToSend_ADDR(base) ((base) + (0x402A))
#define SOC_UFS_L4_T_CPortMode_ADDR(base) ((base) + (0x402B))
#define SOC_UFS_L4_T_TC0TxMaxSDUSize_ADDR(base) ((base) + (0x4060))
#define SOC_UFS_L4_T_TC1TxMaxSDUSize_ADDR(base) ((base) + (0x4061))
#define SOC_UFS_L4_T_TstCPortID_ADDR(base) ((base) + (0x4080))
#define SOC_UFS_L4_T_TstSrcOn_ADDR(base) ((base) + (0x4081))
#define SOC_UFS_L4_T_TstSrcPattern_ADDR(base) ((base) + (0x4082))
#define SOC_UFS_L4_T_TstSrcIncrement_ADDR(base) ((base) + (0x4083))
#define SOC_UFS_L4_T_TstSrcMessageSize_ADDR(base) ((base) + (0x4084))
#define SOC_UFS_L4_T_TstSrcMessageCount_ADDR(base) ((base) + (0x4085))
#define SOC_UFS_L4_T_TstSrcInterMessageGap_ADDR(base) ((base) + (0x4086))
#define SOC_UFS_L4_T_TstDstOn_ADDR(base) ((base) + (0x40A1))
#define SOC_UFS_L4_T_TstDstErrorDetectionEnable_ADDR(base) ((base) + (0x40A2))
#define SOC_UFS_L4_T_TstDstPattern_ADDR(base) ((base) + (0x40A3))
#define SOC_UFS_L4_T_TstDstIncrement_ADDR(base) ((base) + (0x40A4))
#define SOC_UFS_L4_T_TstDstMessageCount_ADDR(base) ((base) + (0x40A5))
#define SOC_UFS_L4_T_TstDstMessageOffset_ADDR(base) ((base) + (0x40A6))
#define SOC_UFS_L4_T_TstDstMessageSize_ADDR(base) ((base) + (0x40A7))
#define SOC_UFS_L4_T_TstDstFCCredits_ADDR(base) ((base) + (0x40A8))
#define SOC_UFS_L4_T_TstDstInterFCTokenGap_ADDR(base) ((base) + (0x40A9))
#define SOC_UFS_L4_T_TstDstInitialFCCredits_ADDR(base) ((base) + (0x40AA))
#define SOC_UFS_L4_T_TstDstErrorCode_ADDR(base) ((base) + (0x40AB))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int num_cports : 32;
    } reg;
} SOC_UFS_L4_T_NumCPorts_UNION;
#endif
#define SOC_UFS_L4_T_NumCPorts_num_cports_START (0)
#define SOC_UFS_L4_T_NumCPorts_num_cports_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int num_testfeatures : 32;
    } reg;
} SOC_UFS_L4_T_NumTestFeatures_UNION;
#endif
#define SOC_UFS_L4_T_NumTestFeatures_num_testfeatures_START (0)
#define SOC_UFS_L4_T_NumTestFeatures_num_testfeatures_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ConnectionState_s : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_L4_T_ConnectionState_UNION;
#endif
#define SOC_UFS_L4_T_ConnectionState_ConnectionState_s_START (0)
#define SOC_UFS_L4_T_ConnectionState_ConnectionState_s_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerDeviceID_s : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_UFS_L4_T_PeerDeviceID_UNION;
#endif
#define SOC_UFS_L4_T_PeerDeviceID_PeerDeviceID_s_START (0)
#define SOC_UFS_L4_T_PeerDeviceID_PeerDeviceID_s_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerCPortID_s : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_UFS_L4_T_PeerCPortID_UNION;
#endif
#define SOC_UFS_L4_T_PeerCPortID_PeerCPortID_s_START (0)
#define SOC_UFS_L4_T_PeerCPortID_PeerCPortID_s_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TrafficClass_s : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L4_T_TrafficClass_UNION;
#endif
#define SOC_UFS_L4_T_TrafficClass_TrafficClass_s_START (0)
#define SOC_UFS_L4_T_TrafficClass_TrafficClass_s_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ProtocolID_s : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_ProtocolID_UNION;
#endif
#define SOC_UFS_L4_T_ProtocolID_ProtocolID_s_START (0)
#define SOC_UFS_L4_T_ProtocolID_ProtocolID_s_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int E2EFcEnabled_s : 1;
        unsigned int CSDDisabled_s : 1;
        unsigned int CSVDisabled_s : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_L4_T_CPortFlags_UNION;
#endif
#define SOC_UFS_L4_T_CPortFlags_E2EFcEnabled_s_START (0)
#define SOC_UFS_L4_T_CPortFlags_E2EFcEnabled_s_END (0)
#define SOC_UFS_L4_T_CPortFlags_CSDDisabled_s_START (1)
#define SOC_UFS_L4_T_CPortFlags_CSDDisabled_s_END (1)
#define SOC_UFS_L4_T_CPortFlags_CSVDisabled_s_START (2)
#define SOC_UFS_L4_T_CPortFlags_CSVDisabled_s_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxTokenValue_ao_s : 32;
    } reg;
} SOC_UFS_L4_T_TxTokenValue_UNION;
#endif
#define SOC_UFS_L4_T_TxTokenValue_TxTokenValue_ao_s_START (0)
#define SOC_UFS_L4_T_TxTokenValue_TxTokenValue_ao_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RxTokenValue_ao_s : 32;
    } reg;
} SOC_UFS_L4_T_RxTokenValue_UNION;
#endif
#define SOC_UFS_L4_T_RxTokenValue_RxTokenValue_ao_s_START (0)
#define SOC_UFS_L4_T_RxTokenValue_RxTokenValue_ao_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FcLocalBuffer_s : 32;
    } reg;
} SOC_UFS_L4_T_LocalBufferSpace_UNION;
#endif
#define SOC_UFS_L4_T_LocalBufferSpace_FcLocalBuffer_s_START (0)
#define SOC_UFS_L4_T_LocalBufferSpace_FcLocalBuffer_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FcPeerBuffer_s : 32;
    } reg;
} SOC_UFS_L4_T_PeerBufferSpace_UNION;
#endif
#define SOC_UFS_L4_T_PeerBufferSpace_FcPeerBuffer_s_START (0)
#define SOC_UFS_L4_T_PeerBufferSpace_FcPeerBuffer_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FcToSend_s : 32;
    } reg;
} SOC_UFS_L4_T_CreditsToSend_UNION;
#endif
#define SOC_UFS_L4_T_CreditsToSend_FcToSend_s_START (0)
#define SOC_UFS_L4_T_CreditsToSend_FcToSend_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CPortMode_s : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_L4_T_CPortMode_UNION;
#endif
#define SOC_UFS_L4_T_CPortMode_CPortMode_s_START (0)
#define SOC_UFS_L4_T_CPortMode_CPortMode_s_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0_TxMaxSDUSize : 32;
    } reg;
} SOC_UFS_L4_T_TC0TxMaxSDUSize_UNION;
#endif
#define SOC_UFS_L4_T_TC0TxMaxSDUSize_TC0_TxMaxSDUSize_START (0)
#define SOC_UFS_L4_T_TC0TxMaxSDUSize_TC0_TxMaxSDUSize_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC1_TxMaxSDUSize : 32;
    } reg;
} SOC_UFS_L4_T_TC1TxMaxSDUSize_UNION;
#endif
#define SOC_UFS_L4_T_TC1TxMaxSDUSize_TC1_TxMaxSDUSize_START (0)
#define SOC_UFS_L4_T_TC1TxMaxSDUSize_TC1_TxMaxSDUSize_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstCPortID_o : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_UFS_L4_T_TstCPortID_UNION;
#endif
#define SOC_UFS_L4_T_TstCPortID_TstCPortID_o_START (0)
#define SOC_UFS_L4_T_TstCPortID_TstCPortID_o_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstSrcOn_o : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L4_T_TstSrcOn_UNION;
#endif
#define SOC_UFS_L4_T_TstSrcOn_TstSrcOn_o_START (0)
#define SOC_UFS_L4_T_TstSrcOn_TstSrcOn_o_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstSrcPattern_o : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L4_T_TstSrcPattern_UNION;
#endif
#define SOC_UFS_L4_T_TstSrcPattern_TstSrcPattern_o_START (0)
#define SOC_UFS_L4_T_TstSrcPattern_TstSrcPattern_o_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstSrcIncrement_o : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L4_T_TstSrcIncrement_UNION;
#endif
#define SOC_UFS_L4_T_TstSrcIncrement_TstSrcIncrement_o_START (0)
#define SOC_UFS_L4_T_TstSrcIncrement_TstSrcIncrement_o_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstSrcMessageSize_o : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_TstSrcMessageSize_UNION;
#endif
#define SOC_UFS_L4_T_TstSrcMessageSize_TstSrcMessageSize_o_START (0)
#define SOC_UFS_L4_T_TstSrcMessageSize_TstSrcMessageSize_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstSrcMessageCount_o : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_TstSrcMessageCount_UNION;
#endif
#define SOC_UFS_L4_T_TstSrcMessageCount_TstSrcMessageCount_o_START (0)
#define SOC_UFS_L4_T_TstSrcMessageCount_TstSrcMessageCount_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstSrcInterMessageGap_o : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_TstSrcInterMessageGap_UNION;
#endif
#define SOC_UFS_L4_T_TstSrcInterMessageGap_TstSrcInterMessageGap_o_START (0)
#define SOC_UFS_L4_T_TstSrcInterMessageGap_TstSrcInterMessageGap_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstOn_o : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L4_T_TstDstOn_UNION;
#endif
#define SOC_UFS_L4_T_TstDstOn_TstDstOn_o_START (0)
#define SOC_UFS_L4_T_TstDstOn_TstDstOn_o_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstErrorDetectionEnable_o : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L4_T_TstDstErrorDetectionEnable_UNION;
#endif
#define SOC_UFS_L4_T_TstDstErrorDetectionEnable_TstDstErrorDetectionEnable_o_START (0)
#define SOC_UFS_L4_T_TstDstErrorDetectionEnable_TstDstErrorDetectionEnable_o_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstPattern_o : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L4_T_TstDstPattern_UNION;
#endif
#define SOC_UFS_L4_T_TstDstPattern_TstDstPattern_o_START (0)
#define SOC_UFS_L4_T_TstDstPattern_TstDstPattern_o_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstIncrement_o : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L4_T_TstDstIncrement_UNION;
#endif
#define SOC_UFS_L4_T_TstDstIncrement_TstDstIncrement_o_START (0)
#define SOC_UFS_L4_T_TstDstIncrement_TstDstIncrement_o_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstMessageCount_o : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_TstDstMessageCount_UNION;
#endif
#define SOC_UFS_L4_T_TstDstMessageCount_TstDstMessageCount_o_START (0)
#define SOC_UFS_L4_T_TstDstMessageCount_TstDstMessageCount_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstMessageOffset_o : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_TstDstMessageOffset_UNION;
#endif
#define SOC_UFS_L4_T_TstDstMessageOffset_TstDstMessageOffset_o_START (0)
#define SOC_UFS_L4_T_TstDstMessageOffset_TstDstMessageOffset_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstMessageSize_o : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_TstDstMessageSize_UNION;
#endif
#define SOC_UFS_L4_T_TstDstMessageSize_TstDstMessageSize_o_START (0)
#define SOC_UFS_L4_T_TstDstMessageSize_TstDstMessageSize_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstFCCredits_o : 32;
    } reg;
} SOC_UFS_L4_T_TstDstFCCredits_UNION;
#endif
#define SOC_UFS_L4_T_TstDstFCCredits_TstDstFCCredits_o_START (0)
#define SOC_UFS_L4_T_TstDstFCCredits_TstDstFCCredits_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstInterFCTokenGap_o : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L4_T_TstDstInterFCTokenGap_UNION;
#endif
#define SOC_UFS_L4_T_TstDstInterFCTokenGap_TstDstInterFCTokenGap_o_START (0)
#define SOC_UFS_L4_T_TstDstInterFCTokenGap_TstDstInterFCTokenGap_o_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstInitialFCCredits_o : 32;
    } reg;
} SOC_UFS_L4_T_TstDstInitialFCCredits_UNION;
#endif
#define SOC_UFS_L4_T_TstDstInitialFCCredits_TstDstInitialFCCredits_o_START (0)
#define SOC_UFS_L4_T_TstDstInitialFCCredits_TstDstInitialFCCredits_o_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TstDstErrorCode_o : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_L4_T_TstDstErrorCode_UNION;
#endif
#define SOC_UFS_L4_T_TstDstErrorCode_TstDstErrorCode_o_START (0)
#define SOC_UFS_L4_T_TstDstErrorCode_TstDstErrorCode_o_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
