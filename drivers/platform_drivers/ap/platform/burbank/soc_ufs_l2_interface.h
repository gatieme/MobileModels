#ifndef __SOC_UFS_L2_INTERFACE_H__
#define __SOC_UFS_L2_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_L2_DL_TxPreemptionCap_ADDR(base) ((base) + (0x2000UL))
#define SOC_UFS_L2_DL_TC0TxMaxSDUSize_ADDR(base) ((base) + (0x2001UL))
#define SOC_UFS_L2_DL_TC0RxInitCreditVal_ADDR(base) ((base) + (0x2002UL))
#define SOC_UFS_L2_DL_TC1TxMaxSDUSize_ADDR(base) ((base) + (0x2003UL))
#define SOC_UFS_L2_DL_TC1RxInitCreditVal_ADDR(base) ((base) + (0x2004UL))
#define SOC_UFS_L2_DL_TC0TxBufferSize_ADDR(base) ((base) + (0x2005UL))
#define SOC_UFS_L2_DL_TC1TxBufferSize_ADDR(base) ((base) + (0x2006UL))
#define SOC_UFS_L2_DL_TC0TXFCThreshold_ADDR(base) ((base) + (0x2040UL))
#define SOC_UFS_L2_DL_FC0ProtectionTimeOutVal_ADDR(base) ((base) + (0x2041UL))
#define SOC_UFS_L2_DL_TC0ReplayTimeOutVal_ADDR(base) ((base) + (0x2042UL))
#define SOC_UFS_L2_DL_AFC0ReqTimeOutVal_ADDR(base) ((base) + (0x2043UL))
#define SOC_UFS_L2_DL_AFC0CreditThreshold_ADDR(base) ((base) + (0x2044UL))
#define SOC_UFS_L2_DL_TC0OutAckThreshold_ADDR(base) ((base) + (0x2045UL))
#define SOC_UFS_L2_DL_PeerTC0Present_ADDR(base) ((base) + (0x2046UL))
#define SOC_UFS_L2_DL_PeerTC0RxInitCreditVal_ADDR(base) ((base) + (0x2047UL))
#define SOC_UFS_L2_DL_TC1TXFCThreshold_ADDR(base) ((base) + (0x2060UL))
#define SOC_UFS_L2_DL_FC1ProtectionTimeOutVal_ADDR(base) ((base) + (0x2061UL))
#define SOC_UFS_L2_DL_TC1ReplayTimeOutVal_ADDR(base) ((base) + (0x2062UL))
#define SOC_UFS_L2_DL_AFC1ReqTimeOutVal_ADDR(base) ((base) + (0x2063UL))
#define SOC_UFS_L2_DL_AFC1CreditThreshold_ADDR(base) ((base) + (0x2064UL))
#define SOC_UFS_L2_DL_TC1OutAckThreshold_ADDR(base) ((base) + (0x2065UL))
#define SOC_UFS_L2_DL_PeerTC1Present_ADDR(base) ((base) + (0x2066UL))
#define SOC_UFS_L2_DL_PeerTC1RxInitCreditVal_ADDR(base) ((base) + (0x2067UL))
#define SOC_UFS_L2_DL_IMPL_DEFINED0_ADDR(base) ((base) + (0xa000UL))
#define SOC_UFS_L2_DL_IMPL_DEFINED1_ADDR(base) ((base) + (0xa001UL))
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_ADDR(base) ((base) + (0xa008UL))
#define SOC_UFS_L2_DL_IMPL_PROTECTIO_TIMER_ADDR(base) ((base) + (0xa00bUL))
#define SOC_UFS_L2_DL_IMPL_REPLAY_TIMER_ADDR(base) ((base) + (0xa00cUL))
#define SOC_UFS_L2_DL_IMPL_REQUEST_TIMER_ADDR(base) ((base) + (0xa00dUL))
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_ADDR(base) ((base) + (0xa00eUL))
#define SOC_UFS_L2_DL_IMPL_ERROR_STATUS_ADDR(base) ((base) + (0xa00fUL))
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_ADDR(base) ((base) + (0xa010UL))
#define SOC_UFS_L2_DL_IMPL_STATE_ADDR(base) ((base) + (0xa011UL))
#define SOC_UFS_L2_DL_DBG_DL_TOP0_ADDR(base) ((base) + (0xa012UL))
#define SOC_UFS_L2_DL_DBG_DL_TOP1_ADDR(base) ((base) + (0xa013UL))
#define SOC_UFS_L2_DL_DBG_DL_TOP2_ADDR(base) ((base) + (0xa014UL))
#define SOC_UFS_L2_DL_DBG_TX_TOP0_ADDR(base) ((base) + (0xa015UL))
#define SOC_UFS_L2_DL_DBG_TX_TOP1_ADDR(base) ((base) + (0xa016UL))
#define SOC_UFS_L2_DL_DBG_TX_TOP2_ADDR(base) ((base) + (0xa017UL))
#define SOC_UFS_L2_DL_DBG_TX_TOP3_ADDR(base) ((base) + (0xa018UL))
#define SOC_UFS_L2_DL_DBG_TX_TOP4_ADDR(base) ((base) + (0xa019UL))
#define SOC_UFS_L2_DL_DBG_TX_TOP5_ADDR(base) ((base) + (0xa01aUL))
#define SOC_UFS_L2_DL_IMPL_ERROR_PA_INIT_COUNT_ADDR(base) ((base) + (0xa01bUL))
#else
#define SOC_UFS_L2_DL_TxPreemptionCap_ADDR(base) ((base) + (0x2000))
#define SOC_UFS_L2_DL_TC0TxMaxSDUSize_ADDR(base) ((base) + (0x2001))
#define SOC_UFS_L2_DL_TC0RxInitCreditVal_ADDR(base) ((base) + (0x2002))
#define SOC_UFS_L2_DL_TC1TxMaxSDUSize_ADDR(base) ((base) + (0x2003))
#define SOC_UFS_L2_DL_TC1RxInitCreditVal_ADDR(base) ((base) + (0x2004))
#define SOC_UFS_L2_DL_TC0TxBufferSize_ADDR(base) ((base) + (0x2005))
#define SOC_UFS_L2_DL_TC1TxBufferSize_ADDR(base) ((base) + (0x2006))
#define SOC_UFS_L2_DL_TC0TXFCThreshold_ADDR(base) ((base) + (0x2040))
#define SOC_UFS_L2_DL_FC0ProtectionTimeOutVal_ADDR(base) ((base) + (0x2041))
#define SOC_UFS_L2_DL_TC0ReplayTimeOutVal_ADDR(base) ((base) + (0x2042))
#define SOC_UFS_L2_DL_AFC0ReqTimeOutVal_ADDR(base) ((base) + (0x2043))
#define SOC_UFS_L2_DL_AFC0CreditThreshold_ADDR(base) ((base) + (0x2044))
#define SOC_UFS_L2_DL_TC0OutAckThreshold_ADDR(base) ((base) + (0x2045))
#define SOC_UFS_L2_DL_PeerTC0Present_ADDR(base) ((base) + (0x2046))
#define SOC_UFS_L2_DL_PeerTC0RxInitCreditVal_ADDR(base) ((base) + (0x2047))
#define SOC_UFS_L2_DL_TC1TXFCThreshold_ADDR(base) ((base) + (0x2060))
#define SOC_UFS_L2_DL_FC1ProtectionTimeOutVal_ADDR(base) ((base) + (0x2061))
#define SOC_UFS_L2_DL_TC1ReplayTimeOutVal_ADDR(base) ((base) + (0x2062))
#define SOC_UFS_L2_DL_AFC1ReqTimeOutVal_ADDR(base) ((base) + (0x2063))
#define SOC_UFS_L2_DL_AFC1CreditThreshold_ADDR(base) ((base) + (0x2064))
#define SOC_UFS_L2_DL_TC1OutAckThreshold_ADDR(base) ((base) + (0x2065))
#define SOC_UFS_L2_DL_PeerTC1Present_ADDR(base) ((base) + (0x2066))
#define SOC_UFS_L2_DL_PeerTC1RxInitCreditVal_ADDR(base) ((base) + (0x2067))
#define SOC_UFS_L2_DL_IMPL_DEFINED0_ADDR(base) ((base) + (0xa000))
#define SOC_UFS_L2_DL_IMPL_DEFINED1_ADDR(base) ((base) + (0xa001))
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_ADDR(base) ((base) + (0xa008))
#define SOC_UFS_L2_DL_IMPL_PROTECTIO_TIMER_ADDR(base) ((base) + (0xa00b))
#define SOC_UFS_L2_DL_IMPL_REPLAY_TIMER_ADDR(base) ((base) + (0xa00c))
#define SOC_UFS_L2_DL_IMPL_REQUEST_TIMER_ADDR(base) ((base) + (0xa00d))
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_ADDR(base) ((base) + (0xa00e))
#define SOC_UFS_L2_DL_IMPL_ERROR_STATUS_ADDR(base) ((base) + (0xa00f))
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_ADDR(base) ((base) + (0xa010))
#define SOC_UFS_L2_DL_IMPL_STATE_ADDR(base) ((base) + (0xa011))
#define SOC_UFS_L2_DL_DBG_DL_TOP0_ADDR(base) ((base) + (0xa012))
#define SOC_UFS_L2_DL_DBG_DL_TOP1_ADDR(base) ((base) + (0xa013))
#define SOC_UFS_L2_DL_DBG_DL_TOP2_ADDR(base) ((base) + (0xa014))
#define SOC_UFS_L2_DL_DBG_TX_TOP0_ADDR(base) ((base) + (0xa015))
#define SOC_UFS_L2_DL_DBG_TX_TOP1_ADDR(base) ((base) + (0xa016))
#define SOC_UFS_L2_DL_DBG_TX_TOP2_ADDR(base) ((base) + (0xa017))
#define SOC_UFS_L2_DL_DBG_TX_TOP3_ADDR(base) ((base) + (0xa018))
#define SOC_UFS_L2_DL_DBG_TX_TOP4_ADDR(base) ((base) + (0xa019))
#define SOC_UFS_L2_DL_DBG_TX_TOP5_ADDR(base) ((base) + (0xa01a))
#define SOC_UFS_L2_DL_IMPL_ERROR_PA_INIT_COUNT_ADDR(base) ((base) + (0xa01b))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TxPreemptionCap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L2_DL_TxPreemptionCap_UNION;
#endif
#define SOC_UFS_L2_DL_TxPreemptionCap_TxPreemptionCap_START (0)
#define SOC_UFS_L2_DL_TxPreemptionCap_TxPreemptionCap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0TxMaxSDUSize : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC0TxMaxSDUSize_UNION;
#endif
#define SOC_UFS_L2_DL_TC0TxMaxSDUSize_TC0TxMaxSDUSize_START (0)
#define SOC_UFS_L2_DL_TC0TxMaxSDUSize_TC0TxMaxSDUSize_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0RxInitCreditVal : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC0RxInitCreditVal_UNION;
#endif
#define SOC_UFS_L2_DL_TC0RxInitCreditVal_TC0RxInitCreditVal_START (0)
#define SOC_UFS_L2_DL_TC0RxInitCreditVal_TC0RxInitCreditVal_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC1TxMaxSDUSize : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC1TxMaxSDUSize_UNION;
#endif
#define SOC_UFS_L2_DL_TC1TxMaxSDUSize_TC1TxMaxSDUSize_START (0)
#define SOC_UFS_L2_DL_TC1TxMaxSDUSize_TC1TxMaxSDUSize_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC1RxInitCreditVal : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC1RxInitCreditVal_UNION;
#endif
#define SOC_UFS_L2_DL_TC1RxInitCreditVal_TC1RxInitCreditVal_START (0)
#define SOC_UFS_L2_DL_TC1RxInitCreditVal_TC1RxInitCreditVal_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0TxBufferSize : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC0TxBufferSize_UNION;
#endif
#define SOC_UFS_L2_DL_TC0TxBufferSize_TC0TxBufferSize_START (0)
#define SOC_UFS_L2_DL_TC0TxBufferSize_TC0TxBufferSize_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC1TxBufferSize : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC1TxBufferSize_UNION;
#endif
#define SOC_UFS_L2_DL_TC1TxBufferSize_TC1TxBufferSize_START (0)
#define SOC_UFS_L2_DL_TC1TxBufferSize_TC1TxBufferSize_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0TXFCThreshold : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC0TXFCThreshold_UNION;
#endif
#define SOC_UFS_L2_DL_TC0TXFCThreshold_TC0TXFCThreshold_START (0)
#define SOC_UFS_L2_DL_TC0TXFCThreshold_TC0TXFCThreshold_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FC0ProtectionTimeOutVal : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L2_DL_FC0ProtectionTimeOutVal_UNION;
#endif
#define SOC_UFS_L2_DL_FC0ProtectionTimeOutVal_FC0ProtectionTimeOutVal_START (0)
#define SOC_UFS_L2_DL_FC0ProtectionTimeOutVal_FC0ProtectionTimeOutVal_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0ReplayTimeOutVal : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L2_DL_TC0ReplayTimeOutVal_UNION;
#endif
#define SOC_UFS_L2_DL_TC0ReplayTimeOutVal_TC0ReplayTimeOutVal_START (0)
#define SOC_UFS_L2_DL_TC0ReplayTimeOutVal_TC0ReplayTimeOutVal_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AFC0ReqTimeOutVal : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L2_DL_AFC0ReqTimeOutVal_UNION;
#endif
#define SOC_UFS_L2_DL_AFC0ReqTimeOutVal_AFC0ReqTimeOutVal_START (0)
#define SOC_UFS_L2_DL_AFC0ReqTimeOutVal_AFC0ReqTimeOutVal_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AFC0CreditThreshold : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_UFS_L2_DL_AFC0CreditThreshold_UNION;
#endif
#define SOC_UFS_L2_DL_AFC0CreditThreshold_AFC0CreditThreshold_START (0)
#define SOC_UFS_L2_DL_AFC0CreditThreshold_AFC0CreditThreshold_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0OutAckThreshold : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_L2_DL_TC0OutAckThreshold_UNION;
#endif
#define SOC_UFS_L2_DL_TC0OutAckThreshold_TC0OutAckThreshold_START (0)
#define SOC_UFS_L2_DL_TC0OutAckThreshold_TC0OutAckThreshold_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerTC0Present : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L2_DL_PeerTC0Present_UNION;
#endif
#define SOC_UFS_L2_DL_PeerTC0Present_PeerTC0Present_START (0)
#define SOC_UFS_L2_DL_PeerTC0Present_PeerTC0Present_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerTC0RxInitCreditVal : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_PeerTC0RxInitCreditVal_UNION;
#endif
#define SOC_UFS_L2_DL_PeerTC0RxInitCreditVal_PeerTC0RxInitCreditVal_START (0)
#define SOC_UFS_L2_DL_PeerTC0RxInitCreditVal_PeerTC0RxInitCreditVal_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC1TXFCThreshold : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_TC1TXFCThreshold_UNION;
#endif
#define SOC_UFS_L2_DL_TC1TXFCThreshold_TC1TXFCThreshold_START (0)
#define SOC_UFS_L2_DL_TC1TXFCThreshold_TC1TXFCThreshold_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FC1ProtectionTimeOutVal : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L2_DL_FC1ProtectionTimeOutVal_UNION;
#endif
#define SOC_UFS_L2_DL_FC1ProtectionTimeOutVal_FC1ProtectionTimeOutVal_START (0)
#define SOC_UFS_L2_DL_FC1ProtectionTimeOutVal_FC1ProtectionTimeOutVal_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC1ReplayTimeOutVal : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L2_DL_TC1ReplayTimeOutVal_UNION;
#endif
#define SOC_UFS_L2_DL_TC1ReplayTimeOutVal_TC1ReplayTimeOutVal_START (0)
#define SOC_UFS_L2_DL_TC1ReplayTimeOutVal_TC1ReplayTimeOutVal_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AFC1ReqTimeOutVal : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_L2_DL_AFC1ReqTimeOutVal_UNION;
#endif
#define SOC_UFS_L2_DL_AFC1ReqTimeOutVal_AFC1ReqTimeOutVal_START (0)
#define SOC_UFS_L2_DL_AFC1ReqTimeOutVal_AFC1ReqTimeOutVal_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AFC1CreditThreshold : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_UFS_L2_DL_AFC1CreditThreshold_UNION;
#endif
#define SOC_UFS_L2_DL_AFC1CreditThreshold_AFC1CreditThreshold_START (0)
#define SOC_UFS_L2_DL_AFC1CreditThreshold_AFC1CreditThreshold_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC1OutAckThreshold : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_UFS_L2_DL_TC1OutAckThreshold_UNION;
#endif
#define SOC_UFS_L2_DL_TC1OutAckThreshold_TC1OutAckThreshold_START (0)
#define SOC_UFS_L2_DL_TC1OutAckThreshold_TC1OutAckThreshold_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerTC1Present : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L2_DL_PeerTC1Present_UNION;
#endif
#define SOC_UFS_L2_DL_PeerTC1Present_PeerTC1Present_START (0)
#define SOC_UFS_L2_DL_PeerTC1Present_PeerTC1Present_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PeerTC1RxInitCreditVal : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_PeerTC1RxInitCreditVal_UNION;
#endif
#define SOC_UFS_L2_DL_PeerTC1RxInitCreditVal_PeerTC1RxInitCreditVal_START (0)
#define SOC_UFS_L2_DL_PeerTC1RxInitCreditVal_PeerTC1RxInitCreditVal_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L2ALIGN_EN : 1;
        unsigned int NACRREQ_EN : 1;
        unsigned int NACAFC_EN : 1;
        unsigned int RE_INIT_EN_NAC : 1;
        unsigned int ERR_HANDLE_ORDER : 1;
        unsigned int sw_eh_stop_resume : 1;
        unsigned int sw_eh_pause_resume : 1;
        unsigned int rx_seq_ack_sel : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_L2_DL_IMPL_DEFINED0_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_DEFINED0_L2ALIGN_EN_START (0)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_L2ALIGN_EN_END (0)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_NACRREQ_EN_START (1)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_NACRREQ_EN_END (1)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_NACAFC_EN_START (2)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_NACAFC_EN_END (2)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_RE_INIT_EN_NAC_START (3)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_RE_INIT_EN_NAC_END (3)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_ERR_HANDLE_ORDER_START (4)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_ERR_HANDLE_ORDER_END (4)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_sw_eh_stop_resume_START (5)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_sw_eh_stop_resume_END (5)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_sw_eh_pause_resume_START (6)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_sw_eh_pause_resume_END (6)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_rx_seq_ack_sel_START (7)
#define SOC_UFS_L2_DL_IMPL_DEFINED0_rx_seq_ack_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DBG_MFE_RECOVER : 1;
        unsigned int DBG_EFE_RECOVER : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_L2_DL_IMPL_DEFINED1_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_DEFINED1_DBG_MFE_RECOVER_START (0)
#define SOC_UFS_L2_DL_IMPL_DEFINED1_DBG_MFE_RECOVER_END (0)
#define SOC_UFS_L2_DL_IMPL_DEFINED1_DBG_EFE_RECOVER_START (1)
#define SOC_UFS_L2_DL_IMPL_DEFINED1_DBG_EFE_RECOVER_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int AFC0RequestTimer_reg_dis : 1;
        unsigned int AFC1RequestTimer_reg_dis : 1;
        unsigned int TC0ReplayTimer_reg_dis : 1;
        unsigned int TC1ReplayTimer_reg_dis : 1;
        unsigned int FC0ProtectionTimer_reg_dis : 1;
        unsigned int FC1ProtectionTimer_reg_dis : 1;
        unsigned int reserved_1 : 2;
        unsigned int AFC0RequestTimer_reg_clr : 1;
        unsigned int AFC1RequestTimer_reg_clr : 1;
        unsigned int TC0ReplayTimer_reg_clr : 1;
        unsigned int TC1ReplayTimer_reg_clr : 1;
        unsigned int FC0ProtectionTimer_reg_clr : 1;
        unsigned int FC1ProtectionTimer_reg_clr : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_UFS_L2_DL_IMPL_TIMER_CTRL_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC0RequestTimer_reg_dis_START (16)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC0RequestTimer_reg_dis_END (16)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC1RequestTimer_reg_dis_START (17)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC1RequestTimer_reg_dis_END (17)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC0ReplayTimer_reg_dis_START (18)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC0ReplayTimer_reg_dis_END (18)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC1ReplayTimer_reg_dis_START (19)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC1ReplayTimer_reg_dis_END (19)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC0ProtectionTimer_reg_dis_START (20)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC0ProtectionTimer_reg_dis_END (20)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC1ProtectionTimer_reg_dis_START (21)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC1ProtectionTimer_reg_dis_END (21)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC0RequestTimer_reg_clr_START (24)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC0RequestTimer_reg_clr_END (24)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC1RequestTimer_reg_clr_START (25)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_AFC1RequestTimer_reg_clr_END (25)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC0ReplayTimer_reg_clr_START (26)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC0ReplayTimer_reg_clr_END (26)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC1ReplayTimer_reg_clr_START (27)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_TC1ReplayTimer_reg_clr_END (27)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC0ProtectionTimer_reg_clr_START (28)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC0ProtectionTimer_reg_clr_END (28)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC1ProtectionTimer_reg_clr_START (29)
#define SOC_UFS_L2_DL_IMPL_TIMER_CTRL_FC1ProtectionTimer_reg_clr_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FC0ProtectionTimer : 16;
        unsigned int FC1ProtectionTimer : 16;
    } reg;
} SOC_UFS_L2_DL_IMPL_PROTECTIO_TIMER_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_PROTECTIO_TIMER_FC0ProtectionTimer_START (0)
#define SOC_UFS_L2_DL_IMPL_PROTECTIO_TIMER_FC0ProtectionTimer_END (15)
#define SOC_UFS_L2_DL_IMPL_PROTECTIO_TIMER_FC1ProtectionTimer_START (16)
#define SOC_UFS_L2_DL_IMPL_PROTECTIO_TIMER_FC1ProtectionTimer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TC0ReplayTimer : 16;
        unsigned int TC1ReplayTimer : 16;
    } reg;
} SOC_UFS_L2_DL_IMPL_REPLAY_TIMER_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_REPLAY_TIMER_TC0ReplayTimer_START (0)
#define SOC_UFS_L2_DL_IMPL_REPLAY_TIMER_TC0ReplayTimer_END (15)
#define SOC_UFS_L2_DL_IMPL_REPLAY_TIMER_TC1ReplayTimer_START (16)
#define SOC_UFS_L2_DL_IMPL_REPLAY_TIMER_TC1ReplayTimer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AFC0RequestTimer : 16;
        unsigned int AFC1RequestTimer : 16;
    } reg;
} SOC_UFS_L2_DL_IMPL_REQUEST_TIMER_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_REQUEST_TIMER_AFC0RequestTimer_START (0)
#define SOC_UFS_L2_DL_IMPL_REQUEST_TIMER_AFC0RequestTimer_END (15)
#define SOC_UFS_L2_DL_IMPL_REQUEST_TIMER_AFC1RequestTimer_START (16)
#define SOC_UFS_L2_DL_IMPL_REQUEST_TIMER_AFC1RequestTimer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pause_st_wait_time : 4;
        unsigned int reserved_0 : 4;
        unsigned int txbuf_size_margin : 4;
        unsigned int txbuf_outs_margin : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_UFS_L2_DL_IMPL_TX_CTRL0_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_pause_st_wait_time_START (0)
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_pause_st_wait_time_END (3)
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_txbuf_size_margin_START (8)
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_txbuf_size_margin_END (11)
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_txbuf_outs_margin_START (12)
#define SOC_UFS_L2_DL_IMPL_TX_CTRL0_txbuf_outs_margin_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_dat_NonPeerTC1_r : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_L2_DL_IMPL_ERROR_STATUS_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_ERROR_STATUS_rx_dat_NonPeerTC1_r_START (0)
#define SOC_UFS_L2_DL_IMPL_ERROR_STATUS_rx_dat_NonPeerTC1_r_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_err_inject_en : 1;
        unsigned int rx_err_inject_interval : 11;
        unsigned int rx_err_inject_cont : 4;
        unsigned int tx_err_inject_en : 1;
        unsigned int tx_err_inject_interval : 11;
        unsigned int tx_err_inject_cont : 4;
    } reg;
} SOC_UFS_L2_DL_IMPL_ERROR_INJECT_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_rx_err_inject_en_START (0)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_rx_err_inject_en_END (0)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_rx_err_inject_interval_START (1)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_rx_err_inject_interval_END (11)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_rx_err_inject_cont_START (12)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_rx_err_inject_cont_END (15)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_tx_err_inject_en_START (16)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_tx_err_inject_en_END (16)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_tx_err_inject_interval_START (17)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_tx_err_inject_interval_END (27)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_tx_err_inject_cont_START (28)
#define SOC_UFS_L2_DL_IMPL_ERROR_INJECT_tx_err_inject_cont_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int state_main : 4;
        unsigned int state_afc0 : 2;
        unsigned int state_afc1 : 2;
        unsigned int state_main_es : 3;
        unsigned int reserved_0 : 1;
        unsigned int state_nac_rcv : 4;
        unsigned int state_prot : 4;
        unsigned int state_replay : 4;
        unsigned int state_rs : 3;
        unsigned int reserved_1 : 1;
        unsigned int state_rx_err : 4;
    } reg;
} SOC_UFS_L2_DL_IMPL_STATE_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_STATE_state_main_START (0)
#define SOC_UFS_L2_DL_IMPL_STATE_state_main_END (3)
#define SOC_UFS_L2_DL_IMPL_STATE_state_afc0_START (4)
#define SOC_UFS_L2_DL_IMPL_STATE_state_afc0_END (5)
#define SOC_UFS_L2_DL_IMPL_STATE_state_afc1_START (6)
#define SOC_UFS_L2_DL_IMPL_STATE_state_afc1_END (7)
#define SOC_UFS_L2_DL_IMPL_STATE_state_main_es_START (8)
#define SOC_UFS_L2_DL_IMPL_STATE_state_main_es_END (10)
#define SOC_UFS_L2_DL_IMPL_STATE_state_nac_rcv_START (12)
#define SOC_UFS_L2_DL_IMPL_STATE_state_nac_rcv_END (15)
#define SOC_UFS_L2_DL_IMPL_STATE_state_prot_START (16)
#define SOC_UFS_L2_DL_IMPL_STATE_state_prot_END (19)
#define SOC_UFS_L2_DL_IMPL_STATE_state_replay_START (20)
#define SOC_UFS_L2_DL_IMPL_STATE_state_replay_END (23)
#define SOC_UFS_L2_DL_IMPL_STATE_state_rs_START (24)
#define SOC_UFS_L2_DL_IMPL_STATE_state_rs_END (26)
#define SOC_UFS_L2_DL_IMPL_STATE_state_rx_err_START (28)
#define SOC_UFS_L2_DL_IMPL_STATE_state_rx_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_eh_stop_st : 2;
        unsigned int dbg_eh_pause_prot_st : 2;
        unsigned int dbg_eh_pause_st : 2;
        unsigned int reserved_0 : 5;
        unsigned int stopFrozenReq_DAT1 : 1;
        unsigned int stopFrozenReq_DAT0 : 1;
        unsigned int stopFrozenReq_AFC1 : 1;
        unsigned int stopFrozenReq_AFC0 : 1;
        unsigned int stopFrozenReq_NAC : 1;
        unsigned int reserved_1 : 3;
        unsigned int protFrozenReq_DAT1 : 1;
        unsigned int protFrozenReq_DAT0 : 1;
        unsigned int protFrozenReq_AFC1 : 1;
        unsigned int protFrozenReq_AFC0 : 1;
        unsigned int protFrozenReq_NAC : 1;
        unsigned int pause_st_FrozenReq : 1;
        unsigned int tx_blocking : 1;
        unsigned int tx_pause_req : 1;
        unsigned int TcdFrozenReq_DAT1 : 1;
        unsigned int TcdFrozenReq_DAT0 : 1;
        unsigned int TcdFrozenReq_AFC1 : 1;
        unsigned int TcdFrozenReq_AFC0 : 1;
        unsigned int TcdFrozenReq_NAC : 1;
    } reg;
} SOC_UFS_L2_DL_DBG_DL_TOP0_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_DL_TOP0_dbg_eh_stop_st_START (0)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_dbg_eh_stop_st_END (1)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_dbg_eh_pause_prot_st_START (2)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_dbg_eh_pause_prot_st_END (3)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_dbg_eh_pause_st_START (4)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_dbg_eh_pause_st_END (5)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_DAT1_START (11)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_DAT1_END (11)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_DAT0_START (12)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_DAT0_END (12)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_AFC1_START (13)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_AFC1_END (13)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_AFC0_START (14)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_AFC0_END (14)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_NAC_START (15)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_stopFrozenReq_NAC_END (15)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_DAT1_START (19)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_DAT1_END (19)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_DAT0_START (20)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_DAT0_END (20)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_AFC1_START (21)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_AFC1_END (21)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_AFC0_START (22)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_AFC0_END (22)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_NAC_START (23)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_protFrozenReq_NAC_END (23)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_pause_st_FrozenReq_START (24)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_pause_st_FrozenReq_END (24)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_tx_blocking_START (25)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_tx_blocking_END (25)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_tx_pause_req_START (26)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_tx_pause_req_END (26)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_DAT1_START (27)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_DAT1_END (27)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_DAT0_START (28)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_DAT0_END (28)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_AFC1_START (29)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_AFC1_END (29)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_AFC0_START (30)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_AFC0_END (30)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_NAC_START (31)
#define SOC_UFS_L2_DL_DBG_DL_TOP0_TcdFrozenReq_NAC_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_tc0_CurrSeq : 5;
        unsigned int rx_tc0_CurrSeq_L2 : 5;
        unsigned int ev_TxAfc0_LastSeqnum : 5;
        unsigned int reserved_0 : 1;
        unsigned int rx_tc1_CurrSeq : 5;
        unsigned int rx_tc1_CurrSeq_L2 : 5;
        unsigned int ev_TxAfc1_LastSeqnum : 5;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_UFS_L2_DL_DBG_DL_TOP1_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc0_CurrSeq_START (0)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc0_CurrSeq_END (4)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc0_CurrSeq_L2_START (5)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc0_CurrSeq_L2_END (9)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_ev_TxAfc0_LastSeqnum_START (10)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_ev_TxAfc0_LastSeqnum_END (14)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc1_CurrSeq_START (16)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc1_CurrSeq_END (20)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc1_CurrSeq_L2_START (21)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_rx_tc1_CurrSeq_L2_END (25)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_ev_TxAfc1_LastSeqnum_START (26)
#define SOC_UFS_L2_DL_DBG_DL_TOP1_ev_TxAfc1_LastSeqnum_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tc1_RxBufaddr0 : 7;
        unsigned int tc0_RxBufaddr0 : 7;
        unsigned int tx_tc1_FrmIsretrans : 1;
        unsigned int tx_tc0_FrmIsretrans : 1;
        unsigned int rx_correct : 1;
        unsigned int rx_crc_err : 1;
        unsigned int FrameError_sys : 1;
        unsigned int EofSyntaxError_sys : 1;
        unsigned int AfcSyntaxError_sys : 1;
        unsigned int NacSyntaxError_sys : 1;
        unsigned int BadCtrlSymType_sys : 1;
        unsigned int L2Enable : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_UFS_L2_DL_DBG_DL_TOP2_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tc1_RxBufaddr0_START (0)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tc1_RxBufaddr0_END (6)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tc0_RxBufaddr0_START (7)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tc0_RxBufaddr0_END (13)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tx_tc1_FrmIsretrans_START (14)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tx_tc1_FrmIsretrans_END (14)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tx_tc0_FrmIsretrans_START (15)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_tx_tc0_FrmIsretrans_END (15)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_rx_correct_START (16)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_rx_correct_END (16)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_rx_crc_err_START (17)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_rx_crc_err_END (17)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_FrameError_sys_START (18)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_FrameError_sys_END (18)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_EofSyntaxError_sys_START (19)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_EofSyntaxError_sys_END (19)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_AfcSyntaxError_sys_START (20)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_AfcSyntaxError_sys_END (20)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_NacSyntaxError_sys_START (21)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_NacSyntaxError_sys_END (21)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_BadCtrlSymType_sys_START (22)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_BadCtrlSymType_sys_END (22)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_L2Enable_START (23)
#define SOC_UFS_L2_DL_DBG_DL_TOP2_L2Enable_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_txbuf_txic_st : 4;
        unsigned int dbg_TxBufWrSeqnumTC0 : 5;
        unsigned int dbg_TxBufWrSeqnumTC1 : 5;
        unsigned int dbg_NumFramesInTxBufTC0 : 5;
        unsigned int dbg_NumFramesInTxBufTC1 : 5;
        unsigned int reserved : 8;
    } reg;
} SOC_UFS_L2_DL_DBG_TX_TOP0_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_txbuf_txic_st_START (0)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_txbuf_txic_st_END (3)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_TxBufWrSeqnumTC0_START (4)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_TxBufWrSeqnumTC0_END (8)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_TxBufWrSeqnumTC1_START (9)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_TxBufWrSeqnumTC1_END (13)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_NumFramesInTxBufTC0_START (14)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_NumFramesInTxBufTC0_END (18)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_NumFramesInTxBufTC1_START (19)
#define SOC_UFS_L2_DL_DBG_TX_TOP0_dbg_NumFramesInTxBufTC1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_freebufTC0 : 9;
        unsigned int reserved_0 : 7;
        unsigned int dbg_freebufTC1 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_UFS_L2_DL_DBG_TX_TOP1_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_TX_TOP1_dbg_freebufTC0_START (0)
#define SOC_UFS_L2_DL_DBG_TX_TOP1_dbg_freebufTC0_END (8)
#define SOC_UFS_L2_DL_DBG_TX_TOP1_dbg_freebufTC1_START (16)
#define SOC_UFS_L2_DL_DBG_TX_TOP1_dbg_freebufTC1_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbgtxd0_toc_cst : 2;
        unsigned int dbgtxd0_txcb_NumFramesToSend : 5;
        unsigned int dbgtxd0_txcb_EnoughCredits : 1;
        unsigned int dbgtxd0_ev_NumTxUnackFramesTCx : 5;
        unsigned int dbgtxd0_crc_LastSentSeqnum : 5;
        unsigned int dbgtxd0_LastValidRxSeqnumAfc : 5;
        unsigned int reserved : 9;
    } reg;
} SOC_UFS_L2_DL_DBG_TX_TOP2_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_toc_cst_START (0)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_toc_cst_END (1)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_txcb_NumFramesToSend_START (2)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_txcb_NumFramesToSend_END (6)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_txcb_EnoughCredits_START (7)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_txcb_EnoughCredits_END (7)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_ev_NumTxUnackFramesTCx_START (8)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_ev_NumTxUnackFramesTCx_END (12)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_crc_LastSentSeqnum_START (13)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_crc_LastSentSeqnum_END (17)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_LastValidRxSeqnumAfc_START (18)
#define SOC_UFS_L2_DL_DBG_TX_TOP2_dbgtxd0_LastValidRxSeqnumAfc_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbgtxd1_toc_cst : 2;
        unsigned int dbgtxd1_txcb_NumFramesToSend : 5;
        unsigned int dbgtxd1_txcb_EnoughCredits : 1;
        unsigned int dbgtxd1_ev_NumTxUnackFramesTCx : 5;
        unsigned int dbgtxd1_crc_LastSentSeqnum : 5;
        unsigned int dbgtxd1_LastValidRxSeqnumAfc : 5;
        unsigned int reserved : 9;
    } reg;
} SOC_UFS_L2_DL_DBG_TX_TOP3_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_toc_cst_START (0)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_toc_cst_END (1)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_txcb_NumFramesToSend_START (2)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_txcb_NumFramesToSend_END (6)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_txcb_EnoughCredits_START (7)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_txcb_EnoughCredits_END (7)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_ev_NumTxUnackFramesTCx_START (8)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_ev_NumTxUnackFramesTCx_END (12)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_crc_LastSentSeqnum_START (13)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_crc_LastSentSeqnum_END (17)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_LastValidRxSeqnumAfc_START (18)
#define SOC_UFS_L2_DL_DBG_TX_TOP3_dbgtxd1_LastValidRxSeqnumAfc_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int afc0_state : 2;
        unsigned int afc1_state : 2;
        unsigned int nac_state : 2;
        unsigned int dl_out_req : 4;
        unsigned int reserved : 22;
    } reg;
} SOC_UFS_L2_DL_DBG_TX_TOP4_UNION;
#endif
#define SOC_UFS_L2_DL_DBG_TX_TOP4_afc0_state_START (0)
#define SOC_UFS_L2_DL_DBG_TX_TOP4_afc0_state_END (1)
#define SOC_UFS_L2_DL_DBG_TX_TOP4_afc1_state_START (2)
#define SOC_UFS_L2_DL_DBG_TX_TOP4_afc1_state_END (3)
#define SOC_UFS_L2_DL_DBG_TX_TOP4_nac_state_START (4)
#define SOC_UFS_L2_DL_DBG_TX_TOP4_nac_state_END (5)
#define SOC_UFS_L2_DL_DBG_TX_TOP4_dl_out_req_START (6)
#define SOC_UFS_L2_DL_DBG_TX_TOP4_dl_out_req_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_L2_DL_DBG_TX_TOP5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pa_init_cnt : 31;
        unsigned int pa_init_cnt_clr : 1;
    } reg;
} SOC_UFS_L2_DL_IMPL_ERROR_PA_INIT_COUNT_UNION;
#endif
#define SOC_UFS_L2_DL_IMPL_ERROR_PA_INIT_COUNT_pa_init_cnt_START (0)
#define SOC_UFS_L2_DL_IMPL_ERROR_PA_INIT_COUNT_pa_init_cnt_END (30)
#define SOC_UFS_L2_DL_IMPL_ERROR_PA_INIT_COUNT_pa_init_cnt_clr_START (31)
#define SOC_UFS_L2_DL_IMPL_ERROR_PA_INIT_COUNT_pa_init_cnt_clr_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
