#ifndef __SOC_UFS_INTERFACE_H__
#define __SOC_UFS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UFS_CAP_ADDR(base) ((base) + (0x000UL))
#define SOC_UFS_UMACAP_ADDR(base) ((base) + (0x4UL))
#define SOC_UFS_VER_ADDR(base) ((base) + (0x8UL))
#define SOC_UFS_HCPID_ADDR(base) ((base) + (0x10UL))
#define SOC_UFS_HCMID_ADDR(base) ((base) + (0x14UL))
#define SOC_UFS_AHIT_ADDR(base) ((base) + (0x18UL))
#define SOC_UFS_IS_ADDR(base) ((base) + (0x20UL))
#define SOC_UFS_IE_ADDR(base) ((base) + (0x24UL))
#define SOC_UFS_HCS_ADDR(base) ((base) + (0x30UL))
#define SOC_UFS_HCE_ADDR(base) ((base) + (0x34UL))
#define SOC_UFS_UECPA_ADDR(base) ((base) + (0x38UL))
#define SOC_UFS_UECDL_ADDR(base) ((base) + (0x3cUL))
#define SOC_UFS_UECN_ADDR(base) ((base) + (0x40UL))
#define SOC_UFS_UECT_ADDR(base) ((base) + (0x44UL))
#define SOC_UFS_UECDME_ADDR(base) ((base) + (0x48UL))
#define SOC_UFS_UTRIACR_ADDR(base) ((base) + (0x4cUL))
#define SOC_UFS_UTRLBA_ADDR(base) ((base) + (0x50UL))
#define SOC_UFS_UTRLBAU_ADDR(base) ((base) + (0x54UL))
#define SOC_UFS_UTRLDBR_ADDR(base) ((base) + (0x58UL))
#define SOC_UFS_UTRLCLR_ADDR(base) ((base) + (0x5cUL))
#define SOC_UFS_UTRLRSR_ADDR(base) ((base) + (0x60UL))
#define SOC_UFS_UTRLCNR_ADDR(base) ((base) + (0x64UL))
#define SOC_UFS_UTMRLBA_ADDR(base) ((base) + (0x70UL))
#define SOC_UFS_UTMRLBAU_ADDR(base) ((base) + (0x74UL))
#define SOC_UFS_UTMRLDBR_ADDR(base) ((base) + (0x78UL))
#define SOC_UFS_UTMRLCLR_ADDR(base) ((base) + (0x7cUL))
#define SOC_UFS_UTMRLRSR_ADDR(base) ((base) + (0x80UL))
#define SOC_UFS_UICCMD_ADDR(base) ((base) + (0x90UL))
#define SOC_UFS_UICCMDARG1_ADDR(base) ((base) + (0x94UL))
#define SOC_UFS_UICCMDARG2_ADDR(base) ((base) + (0x98UL))
#define SOC_UFS_UICCMDARG3_ADDR(base) ((base) + (0x9cUL))
#define SOC_UFS_UMABA_ADDR(base) ((base) + (0xb0UL))
#define SOC_UFS_UMABAU_ADDR(base) ((base) + (0xb4UL))
#define SOC_UFS_UMAOMAX_ADDR(base) ((base) + (0xb8UL))
#define SOC_UFS_UMACONF_ADDR(base) ((base) + (0xbcUL))
#define SOC_UFS_BUSTHRTL_ADDR(base) ((base) + (0xc0UL))
#define SOC_UFS_OOCPR_ADDR(base) ((base) + (0xc4UL))
#define SOC_UFS_FEIE_ADDR(base) ((base) + (0xc8UL))
#define SOC_UFS_SECURITY_ADDR(base) ((base) + (0xccUL))
#define SOC_UFS_CDACFG_ADDR(base) ((base) + (0xd0UL))
#define SOC_UFS_CDATX1_ADDR(base) ((base) + (0xd4UL))
#define SOC_UFS_CDATX2_ADDR(base) ((base) + (0xd8UL))
#define SOC_UFS_CDARX1_ADDR(base) ((base) + (0xdcUL))
#define SOC_UFS_CDARX2_ADDR(base) ((base) + (0xe0UL))
#define SOC_UFS_CDASTA_ADDR(base) ((base) + (0xe4UL))
#define SOC_UFS_LBMCFG_ADDR(base) ((base) + (0xf0UL))
#define SOC_UFS_LBMSTA_ADDR(base) ((base) + (0xf4UL))
#define SOC_UFS_DBG_ADDR(base) ((base) + (0xf8UL))
#define SOC_UFS_HCLKDIV_ADDR(base) ((base) + (0xfcUL))
#define SOC_UFS_CCAP_ADDR(base) ((base) + (0x100UL))
#define SOC_UFS_CRYPTOCAP_0_ADDR(base) ((base) + (0x104UL))
#define SOC_UFS_CRYPTOCAP_1_ADDR(base) ((base) + (0x108UL))
#define SOC_UFS_CRYPTOCFG_i_0_ADDR(base) ((base) + (0x500+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_1_ADDR(base) ((base) + (0x504+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_2_ADDR(base) ((base) + (0x508+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_3_ADDR(base) ((base) + (0x50c+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_4_ADDR(base) ((base) + (0x510+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_5_ADDR(base) ((base) + (0x514+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_6_ADDR(base) ((base) + (0x518+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_7_ADDR(base) ((base) + (0x51c+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_8_ADDR(base) ((base) + (0x520+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_9_ADDR(base) ((base) + (0x524+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_10_ADDR(base) ((base) + (0x528+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_11_ADDR(base) ((base) + (0x52c+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_12_ADDR(base) ((base) + (0x530+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_13_ADDR(base) ((base) + (0x534+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_14_ADDR(base) ((base) + (0x538+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_15_ADDR(base) ((base) + (0x53c+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_16_ADDR(base) ((base) + (0x540+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_17_ADDR(base) ((base) + (0x544+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_18_ADDR(base) ((base) + (0x548+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_19_ADDR(base) ((base) + (0x54c+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_20_ADDR(base) ((base) + (0x550+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_21_ADDR(base) ((base) + (0x554+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_22_ADDR(base) ((base) + (0x558+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_23_ADDR(base) ((base) + (0x55c+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_24_ADDR(base) ((base) + (0x560+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_25_ADDR(base) ((base) + (0x564+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_26_ADDR(base) ((base) + (0x568+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_27_ADDR(base) ((base) + (0x56c+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_28_ADDR(base) ((base) + (0x570+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_29_ADDR(base) ((base) + (0x574+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_30_ADDR(base) ((base) + (0x578+ i*0x80UL))
#define SOC_UFS_CRYPTOCFG_i_31_ADDR(base) ((base) + (0x57c+ i*0x80UL))
#else
#define SOC_UFS_CAP_ADDR(base) ((base) + (0x000))
#define SOC_UFS_UMACAP_ADDR(base) ((base) + (0x4))
#define SOC_UFS_VER_ADDR(base) ((base) + (0x8))
#define SOC_UFS_HCPID_ADDR(base) ((base) + (0x10))
#define SOC_UFS_HCMID_ADDR(base) ((base) + (0x14))
#define SOC_UFS_AHIT_ADDR(base) ((base) + (0x18))
#define SOC_UFS_IS_ADDR(base) ((base) + (0x20))
#define SOC_UFS_IE_ADDR(base) ((base) + (0x24))
#define SOC_UFS_HCS_ADDR(base) ((base) + (0x30))
#define SOC_UFS_HCE_ADDR(base) ((base) + (0x34))
#define SOC_UFS_UECPA_ADDR(base) ((base) + (0x38))
#define SOC_UFS_UECDL_ADDR(base) ((base) + (0x3c))
#define SOC_UFS_UECN_ADDR(base) ((base) + (0x40))
#define SOC_UFS_UECT_ADDR(base) ((base) + (0x44))
#define SOC_UFS_UECDME_ADDR(base) ((base) + (0x48))
#define SOC_UFS_UTRIACR_ADDR(base) ((base) + (0x4c))
#define SOC_UFS_UTRLBA_ADDR(base) ((base) + (0x50))
#define SOC_UFS_UTRLBAU_ADDR(base) ((base) + (0x54))
#define SOC_UFS_UTRLDBR_ADDR(base) ((base) + (0x58))
#define SOC_UFS_UTRLCLR_ADDR(base) ((base) + (0x5c))
#define SOC_UFS_UTRLRSR_ADDR(base) ((base) + (0x60))
#define SOC_UFS_UTRLCNR_ADDR(base) ((base) + (0x64))
#define SOC_UFS_UTMRLBA_ADDR(base) ((base) + (0x70))
#define SOC_UFS_UTMRLBAU_ADDR(base) ((base) + (0x74))
#define SOC_UFS_UTMRLDBR_ADDR(base) ((base) + (0x78))
#define SOC_UFS_UTMRLCLR_ADDR(base) ((base) + (0x7c))
#define SOC_UFS_UTMRLRSR_ADDR(base) ((base) + (0x80))
#define SOC_UFS_UICCMD_ADDR(base) ((base) + (0x90))
#define SOC_UFS_UICCMDARG1_ADDR(base) ((base) + (0x94))
#define SOC_UFS_UICCMDARG2_ADDR(base) ((base) + (0x98))
#define SOC_UFS_UICCMDARG3_ADDR(base) ((base) + (0x9c))
#define SOC_UFS_UMABA_ADDR(base) ((base) + (0xb0))
#define SOC_UFS_UMABAU_ADDR(base) ((base) + (0xb4))
#define SOC_UFS_UMAOMAX_ADDR(base) ((base) + (0xb8))
#define SOC_UFS_UMACONF_ADDR(base) ((base) + (0xbc))
#define SOC_UFS_BUSTHRTL_ADDR(base) ((base) + (0xc0))
#define SOC_UFS_OOCPR_ADDR(base) ((base) + (0xc4))
#define SOC_UFS_FEIE_ADDR(base) ((base) + (0xc8))
#define SOC_UFS_SECURITY_ADDR(base) ((base) + (0xcc))
#define SOC_UFS_CDACFG_ADDR(base) ((base) + (0xd0))
#define SOC_UFS_CDATX1_ADDR(base) ((base) + (0xd4))
#define SOC_UFS_CDATX2_ADDR(base) ((base) + (0xd8))
#define SOC_UFS_CDARX1_ADDR(base) ((base) + (0xdc))
#define SOC_UFS_CDARX2_ADDR(base) ((base) + (0xe0))
#define SOC_UFS_CDASTA_ADDR(base) ((base) + (0xe4))
#define SOC_UFS_LBMCFG_ADDR(base) ((base) + (0xf0))
#define SOC_UFS_LBMSTA_ADDR(base) ((base) + (0xf4))
#define SOC_UFS_DBG_ADDR(base) ((base) + (0xf8))
#define SOC_UFS_HCLKDIV_ADDR(base) ((base) + (0xfc))
#define SOC_UFS_CCAP_ADDR(base) ((base) + (0x100))
#define SOC_UFS_CRYPTOCAP_0_ADDR(base) ((base) + (0x104))
#define SOC_UFS_CRYPTOCAP_1_ADDR(base) ((base) + (0x108))
#define SOC_UFS_CRYPTOCFG_i_0_ADDR(base) ((base) + (0x500+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_1_ADDR(base) ((base) + (0x504+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_2_ADDR(base) ((base) + (0x508+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_3_ADDR(base) ((base) + (0x50c+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_4_ADDR(base) ((base) + (0x510+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_5_ADDR(base) ((base) + (0x514+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_6_ADDR(base) ((base) + (0x518+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_7_ADDR(base) ((base) + (0x51c+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_8_ADDR(base) ((base) + (0x520+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_9_ADDR(base) ((base) + (0x524+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_10_ADDR(base) ((base) + (0x528+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_11_ADDR(base) ((base) + (0x52c+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_12_ADDR(base) ((base) + (0x530+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_13_ADDR(base) ((base) + (0x534+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_14_ADDR(base) ((base) + (0x538+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_15_ADDR(base) ((base) + (0x53c+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_16_ADDR(base) ((base) + (0x540+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_17_ADDR(base) ((base) + (0x544+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_18_ADDR(base) ((base) + (0x548+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_19_ADDR(base) ((base) + (0x54c+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_20_ADDR(base) ((base) + (0x550+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_21_ADDR(base) ((base) + (0x554+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_22_ADDR(base) ((base) + (0x558+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_23_ADDR(base) ((base) + (0x55c+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_24_ADDR(base) ((base) + (0x560+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_25_ADDR(base) ((base) + (0x564+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_26_ADDR(base) ((base) + (0x568+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_27_ADDR(base) ((base) + (0x56c+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_28_ADDR(base) ((base) + (0x570+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_29_ADDR(base) ((base) + (0x574+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_30_ADDR(base) ((base) + (0x578+ i*0x80))
#define SOC_UFS_CRYPTOCFG_i_31_ADDR(base) ((base) + (0x57c+ i*0x80))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NUTRS : 5;
        unsigned int CAP_RSVD_7_5 : 3;
        unsigned int NORTTS : 8;
        unsigned int NUTMRS : 3;
        unsigned int CAP_RSVD_22_19 : 4;
        unsigned int AUTOH8 : 1;
        unsigned int AS64 : 1;
        unsigned int OODDS : 1;
        unsigned int UICDMETMS : 1;
        unsigned int DBMMS : 1;
        unsigned int CS : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_UFS_CAP_UNION;
#endif
#define SOC_UFS_CAP_NUTRS_START (0)
#define SOC_UFS_CAP_NUTRS_END (4)
#define SOC_UFS_CAP_CAP_RSVD_7_5_START (5)
#define SOC_UFS_CAP_CAP_RSVD_7_5_END (7)
#define SOC_UFS_CAP_NORTTS_START (8)
#define SOC_UFS_CAP_NORTTS_END (15)
#define SOC_UFS_CAP_NUTMRS_START (16)
#define SOC_UFS_CAP_NUTMRS_END (18)
#define SOC_UFS_CAP_CAP_RSVD_22_19_START (19)
#define SOC_UFS_CAP_CAP_RSVD_22_19_END (22)
#define SOC_UFS_CAP_AUTOH8_START (23)
#define SOC_UFS_CAP_AUTOH8_END (23)
#define SOC_UFS_CAP_AS64_START (24)
#define SOC_UFS_CAP_AS64_END (24)
#define SOC_UFS_CAP_OODDS_START (25)
#define SOC_UFS_CAP_OODDS_END (25)
#define SOC_UFS_CAP_UICDMETMS_START (26)
#define SOC_UFS_CAP_UICDMETMS_END (26)
#define SOC_UFS_CAP_DBMMS_START (27)
#define SOC_UFS_CAP_DBMMS_END (27)
#define SOC_UFS_CAP_CS_START (28)
#define SOC_UFS_CAP_CS_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MNOOUR : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_UFS_UMACAP_UNION;
#endif
#define SOC_UFS_UMACAP_MNOOUR_START (0)
#define SOC_UFS_UMACAP_MNOOUR_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int VS : 4;
        unsigned int MNR : 4;
        unsigned int MJR : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_VER_UNION;
#endif
#define SOC_UFS_VER_VS_START (0)
#define SOC_UFS_VER_VS_END (3)
#define SOC_UFS_VER_MNR_START (4)
#define SOC_UFS_VER_MNR_END (7)
#define SOC_UFS_VER_MJR_START (8)
#define SOC_UFS_VER_MJR_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PID : 32;
    } reg;
} SOC_UFS_HCPID_UNION;
#endif
#define SOC_UFS_HCPID_PID_START (0)
#define SOC_UFS_HCPID_PID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MIC : 8;
        unsigned int BI : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCMID_UNION;
#endif
#define SOC_UFS_HCMID_MIC_START (0)
#define SOC_UFS_HCMID_MIC_END (7)
#define SOC_UFS_HCMID_BI_START (8)
#define SOC_UFS_HCMID_BI_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int AH8ITV : 10;
        unsigned int TS : 3;
        unsigned int reserved : 19;
    } reg;
} SOC_UFS_AHIT_UNION;
#endif
#define SOC_UFS_AHIT_AH8ITV_START (0)
#define SOC_UFS_AHIT_AH8ITV_END (9)
#define SOC_UFS_AHIT_TS_START (10)
#define SOC_UFS_AHIT_TS_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTRCS : 1;
        unsigned int UDEPRI : 1;
        unsigned int UE : 1;
        unsigned int UTMS : 1;
        unsigned int UPMS : 1;
        unsigned int UHXS : 1;
        unsigned int UHES : 1;
        unsigned int ULLS : 1;
        unsigned int ULSS : 1;
        unsigned int UTMRCS : 1;
        unsigned int UCCS : 1;
        unsigned int DFES : 1;
        unsigned int UTPES : 1;
        unsigned int reserved_0: 3;
        unsigned int HCFES : 1;
        unsigned int SBFES : 1;
        unsigned int CEFES : 1;
        unsigned int reserved_1: 13;
    } reg;
} SOC_UFS_IS_UNION;
#endif
#define SOC_UFS_IS_UTRCS_START (0)
#define SOC_UFS_IS_UTRCS_END (0)
#define SOC_UFS_IS_UDEPRI_START (1)
#define SOC_UFS_IS_UDEPRI_END (1)
#define SOC_UFS_IS_UE_START (2)
#define SOC_UFS_IS_UE_END (2)
#define SOC_UFS_IS_UTMS_START (3)
#define SOC_UFS_IS_UTMS_END (3)
#define SOC_UFS_IS_UPMS_START (4)
#define SOC_UFS_IS_UPMS_END (4)
#define SOC_UFS_IS_UHXS_START (5)
#define SOC_UFS_IS_UHXS_END (5)
#define SOC_UFS_IS_UHES_START (6)
#define SOC_UFS_IS_UHES_END (6)
#define SOC_UFS_IS_ULLS_START (7)
#define SOC_UFS_IS_ULLS_END (7)
#define SOC_UFS_IS_ULSS_START (8)
#define SOC_UFS_IS_ULSS_END (8)
#define SOC_UFS_IS_UTMRCS_START (9)
#define SOC_UFS_IS_UTMRCS_END (9)
#define SOC_UFS_IS_UCCS_START (10)
#define SOC_UFS_IS_UCCS_END (10)
#define SOC_UFS_IS_DFES_START (11)
#define SOC_UFS_IS_DFES_END (11)
#define SOC_UFS_IS_UTPES_START (12)
#define SOC_UFS_IS_UTPES_END (12)
#define SOC_UFS_IS_HCFES_START (16)
#define SOC_UFS_IS_HCFES_END (16)
#define SOC_UFS_IS_SBFES_START (17)
#define SOC_UFS_IS_SBFES_END (17)
#define SOC_UFS_IS_CEFES_START (18)
#define SOC_UFS_IS_CEFES_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTRCE : 1;
        unsigned int UDEPRIE : 1;
        unsigned int UEE : 1;
        unsigned int UTMSE : 1;
        unsigned int UPMSE : 1;
        unsigned int UHXSE : 1;
        unsigned int UHESE : 1;
        unsigned int ULLSE : 1;
        unsigned int ULSSE : 1;
        unsigned int UTMRCE : 1;
        unsigned int UCCE : 1;
        unsigned int DFEE : 1;
        unsigned int UTPEE : 1;
        unsigned int reserved_0: 3;
        unsigned int HCFEE : 1;
        unsigned int SBFEE : 1;
        unsigned int CEFEE : 1;
        unsigned int reserved_1: 13;
    } reg;
} SOC_UFS_IE_UNION;
#endif
#define SOC_UFS_IE_UTRCE_START (0)
#define SOC_UFS_IE_UTRCE_END (0)
#define SOC_UFS_IE_UDEPRIE_START (1)
#define SOC_UFS_IE_UDEPRIE_END (1)
#define SOC_UFS_IE_UEE_START (2)
#define SOC_UFS_IE_UEE_END (2)
#define SOC_UFS_IE_UTMSE_START (3)
#define SOC_UFS_IE_UTMSE_END (3)
#define SOC_UFS_IE_UPMSE_START (4)
#define SOC_UFS_IE_UPMSE_END (4)
#define SOC_UFS_IE_UHXSE_START (5)
#define SOC_UFS_IE_UHXSE_END (5)
#define SOC_UFS_IE_UHESE_START (6)
#define SOC_UFS_IE_UHESE_END (6)
#define SOC_UFS_IE_ULLSE_START (7)
#define SOC_UFS_IE_ULLSE_END (7)
#define SOC_UFS_IE_ULSSE_START (8)
#define SOC_UFS_IE_ULSSE_END (8)
#define SOC_UFS_IE_UTMRCE_START (9)
#define SOC_UFS_IE_UTMRCE_END (9)
#define SOC_UFS_IE_UCCE_START (10)
#define SOC_UFS_IE_UCCE_END (10)
#define SOC_UFS_IE_DFEE_START (11)
#define SOC_UFS_IE_DFEE_END (11)
#define SOC_UFS_IE_UTPEE_START (12)
#define SOC_UFS_IE_UTPEE_END (12)
#define SOC_UFS_IE_HCFEE_START (16)
#define SOC_UFS_IE_HCFEE_END (16)
#define SOC_UFS_IE_SBFEE_START (17)
#define SOC_UFS_IE_SBFEE_END (17)
#define SOC_UFS_IE_CEFEE_START (18)
#define SOC_UFS_IE_CEFEE_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DP : 1;
        unsigned int UTRLRDY : 1;
        unsigned int UTMRLRDY : 1;
        unsigned int UCRDY : 1;
        unsigned int reserved_0: 4;
        unsigned int UPMCRS : 3;
        unsigned int reserved_1: 1;
        unsigned int UTPEC : 4;
        unsigned int TTAGUTPE : 8;
        unsigned int TLUNUTPE : 8;
    } reg;
} SOC_UFS_HCS_UNION;
#endif
#define SOC_UFS_HCS_DP_START (0)
#define SOC_UFS_HCS_DP_END (0)
#define SOC_UFS_HCS_UTRLRDY_START (1)
#define SOC_UFS_HCS_UTRLRDY_END (1)
#define SOC_UFS_HCS_UTMRLRDY_START (2)
#define SOC_UFS_HCS_UTMRLRDY_END (2)
#define SOC_UFS_HCS_UCRDY_START (3)
#define SOC_UFS_HCS_UCRDY_END (3)
#define SOC_UFS_HCS_UPMCRS_START (8)
#define SOC_UFS_HCS_UPMCRS_END (10)
#define SOC_UFS_HCS_UTPEC_START (12)
#define SOC_UFS_HCS_UTPEC_END (15)
#define SOC_UFS_HCS_TTAGUTPE_START (16)
#define SOC_UFS_HCS_TTAGUTPE_END (23)
#define SOC_UFS_HCS_TLUNUTPE_START (24)
#define SOC_UFS_HCS_TLUNUTPE_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HCE : 1;
        unsigned int GCE : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_UFS_HCE_UNION;
#endif
#define SOC_UFS_HCE_HCE_START (0)
#define SOC_UFS_HCE_HCE_END (0)
#define SOC_UFS_HCE_GCE_START (1)
#define SOC_UFS_HCE_GCE_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EC : 5;
        unsigned int UECPA_RSVD_30_5 : 26;
        unsigned int ERR : 1;
    } reg;
} SOC_UFS_UECPA_UNION;
#endif
#define SOC_UFS_UECPA_EC_START (0)
#define SOC_UFS_UECPA_EC_END (4)
#define SOC_UFS_UECPA_UECPA_RSVD_30_5_START (5)
#define SOC_UFS_UECPA_UECPA_RSVD_30_5_END (30)
#define SOC_UFS_UECPA_ERR_START (31)
#define SOC_UFS_UECPA_ERR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EC : 15;
        unsigned int reserved : 16;
        unsigned int ERR : 1;
    } reg;
} SOC_UFS_UECDL_UNION;
#endif
#define SOC_UFS_UECDL_EC_START (0)
#define SOC_UFS_UECDL_EC_END (14)
#define SOC_UFS_UECDL_ERR_START (31)
#define SOC_UFS_UECDL_ERR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EC : 3;
        unsigned int reserved : 28;
        unsigned int ERR : 1;
    } reg;
} SOC_UFS_UECN_UNION;
#endif
#define SOC_UFS_UECN_EC_START (0)
#define SOC_UFS_UECN_EC_END (2)
#define SOC_UFS_UECN_ERR_START (31)
#define SOC_UFS_UECN_ERR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EC : 7;
        unsigned int reserved : 24;
        unsigned int ERR : 1;
    } reg;
} SOC_UFS_UECT_UNION;
#endif
#define SOC_UFS_UECT_EC_START (0)
#define SOC_UFS_UECT_EC_END (6)
#define SOC_UFS_UECT_ERR_START (31)
#define SOC_UFS_UECT_ERR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EC : 1;
        unsigned int reserved : 30;
        unsigned int ERR : 1;
    } reg;
} SOC_UFS_UECDME_UNION;
#endif
#define SOC_UFS_UECDME_EC_START (0)
#define SOC_UFS_UECDME_EC_END (0)
#define SOC_UFS_UECDME_ERR_START (31)
#define SOC_UFS_UECDME_ERR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int IATOVAL : 8;
        unsigned int IACTH : 5;
        unsigned int reserved_0: 3;
        unsigned int CTR : 1;
        unsigned int reserved_1: 3;
        unsigned int IASB : 1;
        unsigned int reserved_2: 3;
        unsigned int IAPWEN : 1;
        unsigned int reserved_3: 6;
        unsigned int IAEN : 1;
    } reg;
} SOC_UFS_UTRIACR_UNION;
#endif
#define SOC_UFS_UTRIACR_IATOVAL_START (0)
#define SOC_UFS_UTRIACR_IATOVAL_END (7)
#define SOC_UFS_UTRIACR_IACTH_START (8)
#define SOC_UFS_UTRIACR_IACTH_END (12)
#define SOC_UFS_UTRIACR_CTR_START (16)
#define SOC_UFS_UTRIACR_CTR_END (16)
#define SOC_UFS_UTRIACR_IASB_START (20)
#define SOC_UFS_UTRIACR_IASB_END (20)
#define SOC_UFS_UTRIACR_IAPWEN_START (24)
#define SOC_UFS_UTRIACR_IAPWEN_END (24)
#define SOC_UFS_UTRIACR_IAEN_START (31)
#define SOC_UFS_UTRIACR_IAEN_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int UTRLBA : 22;
    } reg;
} SOC_UFS_UTRLBA_UNION;
#endif
#define SOC_UFS_UTRLBA_UTRLBA_START (10)
#define SOC_UFS_UTRLBA_UTRLBA_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTRLBAU : 32;
    } reg;
} SOC_UFS_UTRLBAU_UNION;
#endif
#define SOC_UFS_UTRLBAU_UTRLBAU_START (0)
#define SOC_UFS_UTRLBAU_UTRLBAU_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTRLDBR : 32;
    } reg;
} SOC_UFS_UTRLDBR_UNION;
#endif
#define SOC_UFS_UTRLDBR_UTRLDBR_START (0)
#define SOC_UFS_UTRLDBR_UTRLDBR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTRLCLR : 32;
    } reg;
} SOC_UFS_UTRLCLR_UNION;
#endif
#define SOC_UFS_UTRLCLR_UTRLCLR_START (0)
#define SOC_UFS_UTRLCLR_UTRLCLR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTRLRSR : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_UTRLRSR_UNION;
#endif
#define SOC_UFS_UTRLRSR_UTRLRSR_START (0)
#define SOC_UFS_UTRLRSR_UTRLRSR_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTRLCNR : 32;
    } reg;
} SOC_UFS_UTRLCNR_UNION;
#endif
#define SOC_UFS_UTRLCNR_UTRLCNR_START (0)
#define SOC_UFS_UTRLCNR_UTRLCNR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int UTMRLBA : 22;
    } reg;
} SOC_UFS_UTMRLBA_UNION;
#endif
#define SOC_UFS_UTMRLBA_UTMRLBA_START (10)
#define SOC_UFS_UTMRLBA_UTMRLBA_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTMRLBAU : 32;
    } reg;
} SOC_UFS_UTMRLBAU_UNION;
#endif
#define SOC_UFS_UTMRLBAU_UTMRLBAU_START (0)
#define SOC_UFS_UTMRLBAU_UTMRLBAU_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTMRLDBR : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_UTMRLDBR_UNION;
#endif
#define SOC_UFS_UTMRLDBR_UTMRLDBR_START (0)
#define SOC_UFS_UTMRLDBR_UTMRLDBR_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTMRLCLR : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_UTMRLCLR_UNION;
#endif
#define SOC_UFS_UTMRLCLR_UTMRLCLR_START (0)
#define SOC_UFS_UTMRLCLR_UTMRLCLR_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UTMRLRSR : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_UTMRLRSR_UNION;
#endif
#define SOC_UFS_UTMRLRSR_UTMRLRSR_START (0)
#define SOC_UFS_UTMRLRSR_UTMRLRSR_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CMDOP : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_UFS_UICCMD_UNION;
#endif
#define SOC_UFS_UICCMD_CMDOP_START (0)
#define SOC_UFS_UICCMD_CMDOP_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ARG1 : 32;
    } reg;
} SOC_UFS_UICCMDARG1_UNION;
#endif
#define SOC_UFS_UICCMDARG1_ARG1_START (0)
#define SOC_UFS_UICCMDARG1_ARG1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ARG2 : 32;
    } reg;
} SOC_UFS_UICCMDARG2_UNION;
#endif
#define SOC_UFS_UICCMDARG2_ARG2_START (0)
#define SOC_UFS_UICCMDARG2_ARG2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ARG3 : 32;
    } reg;
} SOC_UFS_UICCMDARG3_UNION;
#endif
#define SOC_UFS_UICCMDARG3_ARG3_START (0)
#define SOC_UFS_UICCMDARG3_ARG3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int UMABA : 22;
    } reg;
} SOC_UFS_UMABA_UNION;
#endif
#define SOC_UFS_UMABA_UMABA_START (10)
#define SOC_UFS_UMABA_UMABA_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UMABAU : 32;
    } reg;
} SOC_UFS_UMABAU_UNION;
#endif
#define SOC_UFS_UMABAU_UMABAU_START (0)
#define SOC_UFS_UMABAU_UMABAU_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 10;
        unsigned int UMAOMAX : 22;
    } reg;
} SOC_UFS_UMAOMAX_UNION;
#endif
#define SOC_UFS_UMAOMAX_UMAOMAX_START (10)
#define SOC_UFS_UMAOMAX_UMAOMAX_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UMEn : 1;
        unsigned int reserved_0 : 7;
        unsigned int CportConfEn : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_UFS_UMACONF_UNION;
#endif
#define SOC_UFS_UMACONF_UMEn_START (0)
#define SOC_UFS_UMACONF_UMEn_END (0)
#define SOC_UFS_UMACONF_CportConfEn_START (8)
#define SOC_UFS_UMACONF_CportConfEn_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BUSDLY : 8;
        unsigned int reserved_0 : 4;
        unsigned int CGE : 1;
        unsigned int MBL : 3;
        unsigned int LP_PGE : 1;
        unsigned int LP_AH8_PGE : 1;
        unsigned int MAXOBUSR : 6;
        unsigned int reserved_1 : 4;
        unsigned int DME_CTRL_LOGIC_EN : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_UFS_BUSTHRTL_UNION;
#endif
#define SOC_UFS_BUSTHRTL_BUSDLY_START (0)
#define SOC_UFS_BUSTHRTL_BUSDLY_END (7)
#define SOC_UFS_BUSTHRTL_CGE_START (12)
#define SOC_UFS_BUSTHRTL_CGE_END (12)
#define SOC_UFS_BUSTHRTL_MBL_START (13)
#define SOC_UFS_BUSTHRTL_MBL_END (15)
#define SOC_UFS_BUSTHRTL_LP_PGE_START (16)
#define SOC_UFS_BUSTHRTL_LP_PGE_END (16)
#define SOC_UFS_BUSTHRTL_LP_AH8_PGE_START (17)
#define SOC_UFS_BUSTHRTL_LP_AH8_PGE_END (17)
#define SOC_UFS_BUSTHRTL_MAXOBUSR_START (18)
#define SOC_UFS_BUSTHRTL_MAXOBUSR_END (23)
#define SOC_UFS_BUSTHRTL_DME_CTRL_LOGIC_EN_START (28)
#define SOC_UFS_BUSTHRTL_DME_CTRL_LOGIC_EN_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OORR : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_UFS_OOCPR_UNION;
#endif
#define SOC_UFS_OOCPR_OORR_START (0)
#define SOC_UFS_OOCPR_OORR_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int VSUTRCE : 1;
        unsigned int VSUDEPRIE : 1;
        unsigned int VSUEE : 1;
        unsigned int VSUTMSE : 1;
        unsigned int VSUPMSE : 1;
        unsigned int VSUHXSE : 1;
        unsigned int VSUHESE : 1;
        unsigned int VSULLSE : 1;
        unsigned int VSULSSE : 1;
        unsigned int VSUTMRCE : 1;
        unsigned int VSUCCE : 1;
        unsigned int VSDFEE : 1;
        unsigned int VSUTPEE : 1;
        unsigned int reserved_0: 3;
        unsigned int VSHCFEE : 1;
        unsigned int VSSBFEE : 1;
        unsigned int reserved_1: 14;
    } reg;
} SOC_UFS_FEIE_UNION;
#endif
#define SOC_UFS_FEIE_VSUTRCE_START (0)
#define SOC_UFS_FEIE_VSUTRCE_END (0)
#define SOC_UFS_FEIE_VSUDEPRIE_START (1)
#define SOC_UFS_FEIE_VSUDEPRIE_END (1)
#define SOC_UFS_FEIE_VSUEE_START (2)
#define SOC_UFS_FEIE_VSUEE_END (2)
#define SOC_UFS_FEIE_VSUTMSE_START (3)
#define SOC_UFS_FEIE_VSUTMSE_END (3)
#define SOC_UFS_FEIE_VSUPMSE_START (4)
#define SOC_UFS_FEIE_VSUPMSE_END (4)
#define SOC_UFS_FEIE_VSUHXSE_START (5)
#define SOC_UFS_FEIE_VSUHXSE_END (5)
#define SOC_UFS_FEIE_VSUHESE_START (6)
#define SOC_UFS_FEIE_VSUHESE_END (6)
#define SOC_UFS_FEIE_VSULLSE_START (7)
#define SOC_UFS_FEIE_VSULLSE_END (7)
#define SOC_UFS_FEIE_VSULSSE_START (8)
#define SOC_UFS_FEIE_VSULSSE_END (8)
#define SOC_UFS_FEIE_VSUTMRCE_START (9)
#define SOC_UFS_FEIE_VSUTMRCE_END (9)
#define SOC_UFS_FEIE_VSUCCE_START (10)
#define SOC_UFS_FEIE_VSUCCE_END (10)
#define SOC_UFS_FEIE_VSDFEE_START (11)
#define SOC_UFS_FEIE_VSDFEE_END (11)
#define SOC_UFS_FEIE_VSUTPEE_START (12)
#define SOC_UFS_FEIE_VSUTPEE_END (12)
#define SOC_UFS_FEIE_VSHCFEE_START (16)
#define SOC_UFS_FEIE_VSHCFEE_END (16)
#define SOC_UFS_FEIE_VSSBFEE_START (17)
#define SOC_UFS_FEIE_VSSBFEE_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int KEY_ACC_SEL : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_SECURITY_UNION;
#endif
#define SOC_UFS_SECURITY_KEY_ACC_SEL_START (0)
#define SOC_UFS_SECURITY_KEY_ACC_SEL_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int CDABE : 8;
        unsigned int CDAEOM : 1;
        unsigned int CDACFG_RSVD_27_17 : 11;
        unsigned int CDAEN : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_UFS_CDACFG_UNION;
#endif
#define SOC_UFS_CDACFG_CDABE_START (8)
#define SOC_UFS_CDACFG_CDABE_END (15)
#define SOC_UFS_CDACFG_CDAEOM_START (16)
#define SOC_UFS_CDACFG_CDAEOM_END (16)
#define SOC_UFS_CDACFG_CDACFG_RSVD_27_17_START (17)
#define SOC_UFS_CDACFG_CDACFG_RSVD_27_17_END (27)
#define SOC_UFS_CDACFG_CDAEN_START (28)
#define SOC_UFS_CDACFG_CDAEN_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CDATXB7 : 8;
        unsigned int CDATXB6 : 8;
        unsigned int CDATXB5 : 8;
        unsigned int CDATXB4 : 8;
    } reg;
} SOC_UFS_CDATX1_UNION;
#endif
#define SOC_UFS_CDATX1_CDATXB7_START (0)
#define SOC_UFS_CDATX1_CDATXB7_END (7)
#define SOC_UFS_CDATX1_CDATXB6_START (8)
#define SOC_UFS_CDATX1_CDATXB6_END (15)
#define SOC_UFS_CDATX1_CDATXB5_START (16)
#define SOC_UFS_CDATX1_CDATXB5_END (23)
#define SOC_UFS_CDATX1_CDATXB4_START (24)
#define SOC_UFS_CDATX1_CDATXB4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CDATXB3 : 8;
        unsigned int CDATXB2 : 8;
        unsigned int CDATXB1 : 8;
        unsigned int CDATXB0 : 8;
    } reg;
} SOC_UFS_CDATX2_UNION;
#endif
#define SOC_UFS_CDATX2_CDATXB3_START (0)
#define SOC_UFS_CDATX2_CDATXB3_END (7)
#define SOC_UFS_CDATX2_CDATXB2_START (8)
#define SOC_UFS_CDATX2_CDATXB2_END (15)
#define SOC_UFS_CDATX2_CDATXB1_START (16)
#define SOC_UFS_CDATX2_CDATXB1_END (23)
#define SOC_UFS_CDATX2_CDATXB0_START (24)
#define SOC_UFS_CDATX2_CDATXB0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CDARXB7 : 8;
        unsigned int CDARXB6 : 8;
        unsigned int CDARXB5 : 8;
        unsigned int CDARXB4 : 8;
    } reg;
} SOC_UFS_CDARX1_UNION;
#endif
#define SOC_UFS_CDARX1_CDARXB7_START (0)
#define SOC_UFS_CDARX1_CDARXB7_END (7)
#define SOC_UFS_CDARX1_CDARXB6_START (8)
#define SOC_UFS_CDARX1_CDARXB6_END (15)
#define SOC_UFS_CDARX1_CDARXB5_START (16)
#define SOC_UFS_CDARX1_CDARXB5_END (23)
#define SOC_UFS_CDARX1_CDARXB4_START (24)
#define SOC_UFS_CDARX1_CDARXB4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CDARXB3 : 8;
        unsigned int CDARXB2 : 8;
        unsigned int CDARXB1 : 8;
        unsigned int CDARXB0 : 8;
    } reg;
} SOC_UFS_CDARX2_UNION;
#endif
#define SOC_UFS_CDARX2_CDARXB3_START (0)
#define SOC_UFS_CDARX2_CDARXB3_END (7)
#define SOC_UFS_CDARX2_CDARXB2_START (8)
#define SOC_UFS_CDARX2_CDARXB2_END (15)
#define SOC_UFS_CDARX2_CDARXB1_START (16)
#define SOC_UFS_CDARX2_CDARXB1_END (23)
#define SOC_UFS_CDARX2_CDARXB0_START (24)
#define SOC_UFS_CDARX2_CDARXB0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int CDABE : 8;
        unsigned int CDASOM : 1;
        unsigned int CDAEOM : 1;
        unsigned int CDASTA : 1;
        unsigned int CDABUSY : 1;
        unsigned int CDARES : 3;
        unsigned int reserved_1: 9;
    } reg;
} SOC_UFS_CDASTA_UNION;
#endif
#define SOC_UFS_CDASTA_CDABE_START (8)
#define SOC_UFS_CDASTA_CDABE_END (15)
#define SOC_UFS_CDASTA_CDASOM_START (16)
#define SOC_UFS_CDASTA_CDASOM_END (16)
#define SOC_UFS_CDASTA_CDAEOM_START (17)
#define SOC_UFS_CDASTA_CDAEOM_END (17)
#define SOC_UFS_CDASTA_CDASTA_START (18)
#define SOC_UFS_CDASTA_CDASTA_END (18)
#define SOC_UFS_CDASTA_CDABUSY_START (19)
#define SOC_UFS_CDASTA_CDABUSY_END (19)
#define SOC_UFS_CDASTA_CDARES_START (20)
#define SOC_UFS_CDASTA_CDARES_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UDLY : 4;
        unsigned int USDLY : 1;
        unsigned int PDSIZE : 4;
        unsigned int LBME : 1;
        unsigned int MRTTE : 1;
        unsigned int TRTLDV : 4;
        unsigned int BEPS : 1;
        unsigned int BEP : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_UFS_LBMCFG_UNION;
#endif
#define SOC_UFS_LBMCFG_UDLY_START (0)
#define SOC_UFS_LBMCFG_UDLY_END (3)
#define SOC_UFS_LBMCFG_USDLY_START (4)
#define SOC_UFS_LBMCFG_USDLY_END (4)
#define SOC_UFS_LBMCFG_PDSIZE_START (5)
#define SOC_UFS_LBMCFG_PDSIZE_END (8)
#define SOC_UFS_LBMCFG_LBME_START (9)
#define SOC_UFS_LBMCFG_LBME_END (9)
#define SOC_UFS_LBMCFG_MRTTE_START (10)
#define SOC_UFS_LBMCFG_MRTTE_END (10)
#define SOC_UFS_LBMCFG_TRTLDV_START (11)
#define SOC_UFS_LBMCFG_TRTLDV_END (14)
#define SOC_UFS_LBMCFG_BEPS_START (15)
#define SOC_UFS_LBMCFG_BEPS_END (15)
#define SOC_UFS_LBMCFG_BEP_START (16)
#define SOC_UFS_LBMCFG_BEP_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ERR : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_UFS_LBMSTA_UNION;
#endif
#define SOC_UFS_LBMSTA_ERR_START (0)
#define SOC_UFS_LBMSTA_ERR_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DBG : 32;
    } reg;
} SOC_UFS_DBG_UNION;
#endif
#define SOC_UFS_DBG_DBG_START (0)
#define SOC_UFS_DBG_DBG_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HCLKDIV : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_UFS_HCLKDIV_UNION;
#endif
#define SOC_UFS_HCLKDIV_HCLKDIV_START (0)
#define SOC_UFS_HCLKDIV_HCLKDIV_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CC : 8;
        unsigned int CFGC : 8;
        unsigned int CCAP_RSVD_23_16 : 8;
        unsigned int CFGPTR : 8;
    } reg;
} SOC_UFS_CCAP_UNION;
#endif
#define SOC_UFS_CCAP_CC_START (0)
#define SOC_UFS_CCAP_CC_END (7)
#define SOC_UFS_CCAP_CFGC_START (8)
#define SOC_UFS_CCAP_CFGC_END (15)
#define SOC_UFS_CCAP_CCAP_RSVD_23_16_START (16)
#define SOC_UFS_CCAP_CCAP_RSVD_23_16_END (23)
#define SOC_UFS_CCAP_CFGPTR_START (24)
#define SOC_UFS_CCAP_CFGPTR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ALGID : 8;
        unsigned int SUDSB : 8;
        unsigned int KS : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_UFS_CRYPTOCAP_0_UNION;
#endif
#define SOC_UFS_CRYPTOCAP_0_ALGID_START (0)
#define SOC_UFS_CRYPTOCAP_0_ALGID_END (7)
#define SOC_UFS_CRYPTOCAP_0_SUDSB_START (8)
#define SOC_UFS_CRYPTOCAP_0_SUDSB_END (15)
#define SOC_UFS_CRYPTOCAP_0_KS_START (16)
#define SOC_UFS_CRYPTOCAP_0_KS_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ALGID : 8;
        unsigned int SUDSB : 8;
        unsigned int KS : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_UFS_CRYPTOCAP_1_UNION;
#endif
#define SOC_UFS_CRYPTOCAP_1_ALGID_START (0)
#define SOC_UFS_CRYPTOCAP_1_ALGID_END (7)
#define SOC_UFS_CRYPTOCAP_1_SUDSB_START (8)
#define SOC_UFS_CRYPTOCAP_1_SUDSB_END (15)
#define SOC_UFS_CRYPTOCAP_1_KS_START (16)
#define SOC_UFS_CRYPTOCAP_1_KS_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_0 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_0_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_0_CRYPTOKEY_i_0_START (0)
#define SOC_UFS_CRYPTOCFG_i_0_CRYPTOKEY_i_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_1 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_1_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_1_CRYPTOKEY_i_1_START (0)
#define SOC_UFS_CRYPTOCFG_i_1_CRYPTOKEY_i_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_2 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_2_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_2_CRYPTOKEY_i_2_START (0)
#define SOC_UFS_CRYPTOCFG_i_2_CRYPTOKEY_i_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_3 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_3_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_3_CRYPTOKEY_i_3_START (0)
#define SOC_UFS_CRYPTOCFG_i_3_CRYPTOKEY_i_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_4 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_4_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_4_CRYPTOKEY_i_4_START (0)
#define SOC_UFS_CRYPTOCFG_i_4_CRYPTOKEY_i_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_5 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_5_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_5_CRYPTOKEY_i_5_START (0)
#define SOC_UFS_CRYPTOCFG_i_5_CRYPTOKEY_i_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_6 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_6_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_6_CRYPTOKEY_i_6_START (0)
#define SOC_UFS_CRYPTOCFG_i_6_CRYPTOKEY_i_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_7 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_7_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_7_CRYPTOKEY_i_7_START (0)
#define SOC_UFS_CRYPTOCFG_i_7_CRYPTOKEY_i_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_8 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_8_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_8_CRYPTOKEY_i_8_START (0)
#define SOC_UFS_CRYPTOCFG_i_8_CRYPTOKEY_i_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_9 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_9_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_9_CRYPTOKEY_i_9_START (0)
#define SOC_UFS_CRYPTOCFG_i_9_CRYPTOKEY_i_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_10 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_10_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_10_CRYPTOKEY_i_10_START (0)
#define SOC_UFS_CRYPTOCFG_i_10_CRYPTOKEY_i_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_11 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_11_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_11_CRYPTOKEY_i_11_START (0)
#define SOC_UFS_CRYPTOCFG_i_11_CRYPTOKEY_i_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_12 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_12_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_12_CRYPTOKEY_i_12_START (0)
#define SOC_UFS_CRYPTOCFG_i_12_CRYPTOKEY_i_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_13 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_13_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_13_CRYPTOKEY_i_13_START (0)
#define SOC_UFS_CRYPTOCFG_i_13_CRYPTOKEY_i_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_14 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_14_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_14_CRYPTOKEY_i_14_START (0)
#define SOC_UFS_CRYPTOCFG_i_14_CRYPTOKEY_i_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CRYPTOKEY_i_15 : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_15_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_15_CRYPTOKEY_i_15_START (0)
#define SOC_UFS_CRYPTOCFG_i_15_CRYPTOKEY_i_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DUSIZE_0 : 8;
        unsigned int CAPIDX_0 : 8;
        unsigned int reserved : 15;
        unsigned int CFGE_0 : 1;
    } reg;
} SOC_UFS_CRYPTOCFG_i_16_UNION;
#endif
#define SOC_UFS_CRYPTOCFG_i_16_DUSIZE_0_START (0)
#define SOC_UFS_CRYPTOCFG_i_16_DUSIZE_0_END (7)
#define SOC_UFS_CRYPTOCFG_i_16_CAPIDX_0_START (8)
#define SOC_UFS_CRYPTOCFG_i_16_CAPIDX_0_END (15)
#define SOC_UFS_CRYPTOCFG_i_16_CFGE_0_START (31)
#define SOC_UFS_CRYPTOCFG_i_16_CFGE_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_24_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_25_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_29_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_30_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_UFS_CRYPTOCFG_i_31_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
