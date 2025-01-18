#ifndef __SOC_FCM_KARMA_INTERFACE_H__
#define __SOC_FCM_KARMA_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_KARMA_ENABLE_ADDR(base) ((base) + (0x0000UL))
#define SOC_FCM_KARMA_GLBCTL_ADDR(base) ((base) + (0x0004UL))
#define SOC_FCM_KARMA_DCPTBL_ADDR(base) ((base) + (0x0008UL))
#define SOC_FCM_KARMA_DCPBSC_ADDR(base) ((base) + (0x000CUL))
#define SOC_FCM_KARMA_REPCTL_ADDR(base) ((base) + (0x0010UL))
#define SOC_FCM_KARMA_STGCTL_ADDR(base) ((base) + (0x0014UL))
#define SOC_FCM_KARMA_ADBREP_ADDR(base) ((base) + (0x00018UL))
#define SOC_FCM_KARMA_ADBDCP_ADDR(base) ((base) + (0x0001CUL))
#define SOC_FCM_KARMA_ADPPR_ADDR(base) ((base) + (0x00020UL))
#define SOC_FCM_KARMA_ADBSCCT_ADDR(base) ((base) + (0x00024UL))
#define SOC_FCM_KARMA_ADBBSC_ADDR(base) ((base) + (0x00028UL))
#define SOC_FCM_KARMA_ADBEFF_ADDR(base) ((base) + (0x0002CUL))
#define SOC_FCM_KARMA_ADBDMCC_ADDR(base) ((base) + (0x00030UL))
#define SOC_FCM_KARMA_CLRCTL_ADDR(base) ((base) + (0x00034UL))
#define SOC_FCM_KARMA_BEADPCTL1_ADDR(base) ((base) + (0x00038UL))
#define SOC_FCM_KARMA_BEADPCTL2_ADDR(base) ((base) + (0x0003CUL))
#define SOC_FCM_KARMA_BEADPCTL3_ADDR(base) ((base) + (0x00040UL))
#define SOC_FCM_KARMA_BEADPCTL4_ADDR(base) ((base) + (0x00044UL))
#define SOC_FCM_KARMA_BEADPCTL5_ADDR(base) ((base) + (0x00048UL))
#define SOC_FCM_KARMA_STATUS_ADDR(base) ((base) + (0x0004CUL))
#define SOC_FCM_KARMA_BEADP1_ADDR(base) ((base) + (0x00050UL))
#define SOC_FCM_KARMA_BEADP2_ADDR(base) ((base) + (0x00054UL))
#define SOC_FCM_KARMA_BEADP3_ADDR(base) ((base) + (0x00058UL))
#define SOC_FCM_KARMA_SYSCTL_ADDR(base) ((base) + (0x0005CUL))
#else
#define SOC_FCM_KARMA_ENABLE_ADDR(base) ((base) + (0x0000))
#define SOC_FCM_KARMA_GLBCTL_ADDR(base) ((base) + (0x0004))
#define SOC_FCM_KARMA_DCPTBL_ADDR(base) ((base) + (0x0008))
#define SOC_FCM_KARMA_DCPBSC_ADDR(base) ((base) + (0x000C))
#define SOC_FCM_KARMA_REPCTL_ADDR(base) ((base) + (0x0010))
#define SOC_FCM_KARMA_STGCTL_ADDR(base) ((base) + (0x0014))
#define SOC_FCM_KARMA_ADBREP_ADDR(base) ((base) + (0x00018))
#define SOC_FCM_KARMA_ADBDCP_ADDR(base) ((base) + (0x0001C))
#define SOC_FCM_KARMA_ADPPR_ADDR(base) ((base) + (0x00020))
#define SOC_FCM_KARMA_ADBSCCT_ADDR(base) ((base) + (0x00024))
#define SOC_FCM_KARMA_ADBBSC_ADDR(base) ((base) + (0x00028))
#define SOC_FCM_KARMA_ADBEFF_ADDR(base) ((base) + (0x0002C))
#define SOC_FCM_KARMA_ADBDMCC_ADDR(base) ((base) + (0x00030))
#define SOC_FCM_KARMA_CLRCTL_ADDR(base) ((base) + (0x00034))
#define SOC_FCM_KARMA_BEADPCTL1_ADDR(base) ((base) + (0x00038))
#define SOC_FCM_KARMA_BEADPCTL2_ADDR(base) ((base) + (0x0003C))
#define SOC_FCM_KARMA_BEADPCTL3_ADDR(base) ((base) + (0x00040))
#define SOC_FCM_KARMA_BEADPCTL4_ADDR(base) ((base) + (0x00044))
#define SOC_FCM_KARMA_BEADPCTL5_ADDR(base) ((base) + (0x00048))
#define SOC_FCM_KARMA_STATUS_ADDR(base) ((base) + (0x0004C))
#define SOC_FCM_KARMA_BEADP1_ADDR(base) ((base) + (0x00050))
#define SOC_FCM_KARMA_BEADP2_ADDR(base) ((base) + (0x00054))
#define SOC_FCM_KARMA_BEADP3_ADDR(base) ((base) + (0x00058))
#define SOC_FCM_KARMA_SYSCTL_ADDR(base) ((base) + (0x0005C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char main_enable : 1;
    } reg;
} SOC_FCM_KARMA_ENABLE_UNION;
#endif
#define SOC_FCM_KARMA_ENABLE_main_enable_START (0)
#define SOC_FCM_KARMA_ENABLE_main_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rep_disable : 1;
        unsigned int dcp_disable : 1;
        unsigned int ARBFIFOdepth : 3;
        unsigned int STGINFIFOdepth : 3;
        unsigned int ACPFIFOdepth : 7;
        unsigned int ACPoutstanding : 5;
        unsigned int L3requesttypemask : 4;
        unsigned int L3requestIDmask : 8;
    } reg;
} SOC_FCM_KARMA_GLBCTL_UNION;
#endif
#define SOC_FCM_KARMA_GLBCTL_rep_disable_START (0)
#define SOC_FCM_KARMA_GLBCTL_rep_disable_END (0)
#define SOC_FCM_KARMA_GLBCTL_dcp_disable_START (1)
#define SOC_FCM_KARMA_GLBCTL_dcp_disable_END (1)
#define SOC_FCM_KARMA_GLBCTL_ARBFIFOdepth_START (2)
#define SOC_FCM_KARMA_GLBCTL_ARBFIFOdepth_END (4)
#define SOC_FCM_KARMA_GLBCTL_STGINFIFOdepth_START (5)
#define SOC_FCM_KARMA_GLBCTL_STGINFIFOdepth_END (7)
#define SOC_FCM_KARMA_GLBCTL_ACPFIFOdepth_START (8)
#define SOC_FCM_KARMA_GLBCTL_ACPFIFOdepth_END (14)
#define SOC_FCM_KARMA_GLBCTL_ACPoutstanding_START (15)
#define SOC_FCM_KARMA_GLBCTL_ACPoutstanding_END (19)
#define SOC_FCM_KARMA_GLBCTL_L3requesttypemask_START (20)
#define SOC_FCM_KARMA_GLBCTL_L3requesttypemask_END (23)
#define SOC_FCM_KARMA_GLBCTL_L3requestIDmask_START (24)
#define SOC_FCM_KARMA_GLBCTL_L3requestIDmask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PT_only_stride : 1;
        unsigned int DCONFstart : 5;
        unsigned int DCONFINClow : 3;
        unsigned int DCONFINChigh : 3;
        unsigned int DCONFDEClow : 3;
        unsigned int DCONFDEChigh : 3;
        unsigned int Ptcounterallcleare : 1;
        unsigned int DCONFlevel : 5;
        unsigned int PTLRUdisable : 1;
        unsigned int SCONFthreshold : 5;
        unsigned int Canceldisable : 1;
        unsigned int DCPselfbypassdisable : 1;
    } reg;
} SOC_FCM_KARMA_DCPTBL_UNION;
#endif
#define SOC_FCM_KARMA_DCPTBL_PT_only_stride_START (0)
#define SOC_FCM_KARMA_DCPTBL_PT_only_stride_END (0)
#define SOC_FCM_KARMA_DCPTBL_DCONFstart_START (1)
#define SOC_FCM_KARMA_DCPTBL_DCONFstart_END (5)
#define SOC_FCM_KARMA_DCPTBL_DCONFINClow_START (6)
#define SOC_FCM_KARMA_DCPTBL_DCONFINClow_END (8)
#define SOC_FCM_KARMA_DCPTBL_DCONFINChigh_START (9)
#define SOC_FCM_KARMA_DCPTBL_DCONFINChigh_END (11)
#define SOC_FCM_KARMA_DCPTBL_DCONFDEClow_START (12)
#define SOC_FCM_KARMA_DCPTBL_DCONFDEClow_END (14)
#define SOC_FCM_KARMA_DCPTBL_DCONFDEChigh_START (15)
#define SOC_FCM_KARMA_DCPTBL_DCONFDEChigh_END (17)
#define SOC_FCM_KARMA_DCPTBL_Ptcounterallcleare_START (18)
#define SOC_FCM_KARMA_DCPTBL_Ptcounterallcleare_END (18)
#define SOC_FCM_KARMA_DCPTBL_DCONFlevel_START (19)
#define SOC_FCM_KARMA_DCPTBL_DCONFlevel_END (23)
#define SOC_FCM_KARMA_DCPTBL_PTLRUdisable_START (24)
#define SOC_FCM_KARMA_DCPTBL_PTLRUdisable_END (24)
#define SOC_FCM_KARMA_DCPTBL_SCONFthreshold_START (25)
#define SOC_FCM_KARMA_DCPTBL_SCONFthreshold_END (29)
#define SOC_FCM_KARMA_DCPTBL_Canceldisable_START (30)
#define SOC_FCM_KARMA_DCPTBL_Canceldisable_END (30)
#define SOC_FCM_KARMA_DCPTBL_DCPselfbypassdisable_START (31)
#define SOC_FCM_KARMA_DCPTBL_DCPselfbypassdisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PTenableevenhightL3hitrate : 1;
        unsigned int SCONFincrement : 5;
        unsigned int PTenableeventheDMDis : 1;
        unsigned int SCONFdecrement : 5;
        unsigned int PTbypassSTG : 1;
        unsigned int SCONFstart : 5;
        unsigned int NA : 2;
        unsigned int PFcost : 4;
        unsigned int DefaultDCPDEG : 6;
        unsigned int L3Ptraintarget : 2;
    } reg;
} SOC_FCM_KARMA_DCPBSC_UNION;
#endif
#define SOC_FCM_KARMA_DCPBSC_PTenableevenhightL3hitrate_START (0)
#define SOC_FCM_KARMA_DCPBSC_PTenableevenhightL3hitrate_END (0)
#define SOC_FCM_KARMA_DCPBSC_SCONFincrement_START (1)
#define SOC_FCM_KARMA_DCPBSC_SCONFincrement_END (5)
#define SOC_FCM_KARMA_DCPBSC_PTenableeventheDMDis_START (6)
#define SOC_FCM_KARMA_DCPBSC_PTenableeventheDMDis_END (6)
#define SOC_FCM_KARMA_DCPBSC_SCONFdecrement_START (7)
#define SOC_FCM_KARMA_DCPBSC_SCONFdecrement_END (11)
#define SOC_FCM_KARMA_DCPBSC_PTbypassSTG_START (12)
#define SOC_FCM_KARMA_DCPBSC_PTbypassSTG_END (12)
#define SOC_FCM_KARMA_DCPBSC_SCONFstart_START (13)
#define SOC_FCM_KARMA_DCPBSC_SCONFstart_END (17)
#define SOC_FCM_KARMA_DCPBSC_NA_START (18)
#define SOC_FCM_KARMA_DCPBSC_NA_END (19)
#define SOC_FCM_KARMA_DCPBSC_PFcost_START (20)
#define SOC_FCM_KARMA_DCPBSC_PFcost_END (23)
#define SOC_FCM_KARMA_DCPBSC_DefaultDCPDEG_START (24)
#define SOC_FCM_KARMA_DCPBSC_DefaultDCPDEG_END (29)
#define SOC_FCM_KARMA_DCPBSC_L3Ptraintarget_START (30)
#define SOC_FCM_KARMA_DCPBSC_L3Ptraintarget_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DefaultREPdegree : 6;
        unsigned int ACshift : 4;
        unsigned int REPdistance : 5;
        unsigned int REPdistanceopposite : 5;
        unsigned int MAXREPDEG : 6;
        unsigned int SameblockupdatePAenable : 1;
        unsigned int Carryoverdisable : 1;
        unsigned int DVMsynccleardisable : 1;
        unsigned int Inflightrequestclear : 1;
        unsigned int InitDMDindexforRTCsi : 1;
        unsigned int Pafilterdisable : 1;
    } reg;
} SOC_FCM_KARMA_REPCTL_UNION;
#endif
#define SOC_FCM_KARMA_REPCTL_DefaultREPdegree_START (0)
#define SOC_FCM_KARMA_REPCTL_DefaultREPdegree_END (5)
#define SOC_FCM_KARMA_REPCTL_ACshift_START (6)
#define SOC_FCM_KARMA_REPCTL_ACshift_END (9)
#define SOC_FCM_KARMA_REPCTL_REPdistance_START (10)
#define SOC_FCM_KARMA_REPCTL_REPdistance_END (14)
#define SOC_FCM_KARMA_REPCTL_REPdistanceopposite_START (15)
#define SOC_FCM_KARMA_REPCTL_REPdistanceopposite_END (19)
#define SOC_FCM_KARMA_REPCTL_MAXREPDEG_START (20)
#define SOC_FCM_KARMA_REPCTL_MAXREPDEG_END (25)
#define SOC_FCM_KARMA_REPCTL_SameblockupdatePAenable_START (26)
#define SOC_FCM_KARMA_REPCTL_SameblockupdatePAenable_END (26)
#define SOC_FCM_KARMA_REPCTL_Carryoverdisable_START (27)
#define SOC_FCM_KARMA_REPCTL_Carryoverdisable_END (27)
#define SOC_FCM_KARMA_REPCTL_DVMsynccleardisable_START (28)
#define SOC_FCM_KARMA_REPCTL_DVMsynccleardisable_END (28)
#define SOC_FCM_KARMA_REPCTL_Inflightrequestclear_START (29)
#define SOC_FCM_KARMA_REPCTL_Inflightrequestclear_END (29)
#define SOC_FCM_KARMA_REPCTL_InitDMDindexforRTCsi_START (30)
#define SOC_FCM_KARMA_REPCTL_InitDMDindexforRTCsi_END (30)
#define SOC_FCM_KARMA_REPCTL_Pafilterdisable_START (31)
#define SOC_FCM_KARMA_REPCTL_Pafilterdisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ForceSTGbypass : 1;
        unsigned int DisableSTGbypass : 1;
        unsigned int PTbuffernumber : 2;
        unsigned int forcefetchonly16requ : 1;
        unsigned int STGbypasscounterlowdelta : 5;
        unsigned int PTpatterncounterTH : 3;
        unsigned int STGbypasscounterhighdelta : 5;
        unsigned int Defaultactiveprefe : 1;
        unsigned int Adaptiveactiveprefet : 1;
        unsigned int ADPintervalthreshold : 2;
        unsigned int ForceDCPTAGhitforupdate : 1;
        unsigned int ForceDCPTAGhitforlookup : 1;
        unsigned int ADBdisable : 1;
        unsigned int ForceRCGenable : 1;
        unsigned int K3toK1blockenable : 1;
        unsigned int K4toK1blockenable : 1;
        unsigned int ReflowPASSalwaysneedDCPp : 1;
        unsigned int don_tupdRTCifdumyR5 : 1;
        unsigned int ACPfifodropfromheaddisable : 1;
        unsigned int CSREPgeneratepatter : 1;
    } reg;
} SOC_FCM_KARMA_STGCTL_UNION;
#endif
#define SOC_FCM_KARMA_STGCTL_ForceSTGbypass_START (0)
#define SOC_FCM_KARMA_STGCTL_ForceSTGbypass_END (0)
#define SOC_FCM_KARMA_STGCTL_DisableSTGbypass_START (1)
#define SOC_FCM_KARMA_STGCTL_DisableSTGbypass_END (1)
#define SOC_FCM_KARMA_STGCTL_PTbuffernumber_START (2)
#define SOC_FCM_KARMA_STGCTL_PTbuffernumber_END (3)
#define SOC_FCM_KARMA_STGCTL_forcefetchonly16requ_START (4)
#define SOC_FCM_KARMA_STGCTL_forcefetchonly16requ_END (4)
#define SOC_FCM_KARMA_STGCTL_STGbypasscounterlowdelta_START (5)
#define SOC_FCM_KARMA_STGCTL_STGbypasscounterlowdelta_END (9)
#define SOC_FCM_KARMA_STGCTL_PTpatterncounterTH_START (10)
#define SOC_FCM_KARMA_STGCTL_PTpatterncounterTH_END (12)
#define SOC_FCM_KARMA_STGCTL_STGbypasscounterhighdelta_START (13)
#define SOC_FCM_KARMA_STGCTL_STGbypasscounterhighdelta_END (17)
#define SOC_FCM_KARMA_STGCTL_Defaultactiveprefe_START (18)
#define SOC_FCM_KARMA_STGCTL_Defaultactiveprefe_END (18)
#define SOC_FCM_KARMA_STGCTL_Adaptiveactiveprefet_START (19)
#define SOC_FCM_KARMA_STGCTL_Adaptiveactiveprefet_END (19)
#define SOC_FCM_KARMA_STGCTL_ADPintervalthreshold_START (20)
#define SOC_FCM_KARMA_STGCTL_ADPintervalthreshold_END (21)
#define SOC_FCM_KARMA_STGCTL_ForceDCPTAGhitforupdate_START (22)
#define SOC_FCM_KARMA_STGCTL_ForceDCPTAGhitforupdate_END (22)
#define SOC_FCM_KARMA_STGCTL_ForceDCPTAGhitforlookup_START (23)
#define SOC_FCM_KARMA_STGCTL_ForceDCPTAGhitforlookup_END (23)
#define SOC_FCM_KARMA_STGCTL_ADBdisable_START (24)
#define SOC_FCM_KARMA_STGCTL_ADBdisable_END (24)
#define SOC_FCM_KARMA_STGCTL_ForceRCGenable_START (25)
#define SOC_FCM_KARMA_STGCTL_ForceRCGenable_END (25)
#define SOC_FCM_KARMA_STGCTL_K3toK1blockenable_START (26)
#define SOC_FCM_KARMA_STGCTL_K3toK1blockenable_END (26)
#define SOC_FCM_KARMA_STGCTL_K4toK1blockenable_START (27)
#define SOC_FCM_KARMA_STGCTL_K4toK1blockenable_END (27)
#define SOC_FCM_KARMA_STGCTL_ReflowPASSalwaysneedDCPp_START (28)
#define SOC_FCM_KARMA_STGCTL_ReflowPASSalwaysneedDCPp_END (28)
#define SOC_FCM_KARMA_STGCTL_don_tupdRTCifdumyR5_START (29)
#define SOC_FCM_KARMA_STGCTL_don_tupdRTCifdumyR5_END (29)
#define SOC_FCM_KARMA_STGCTL_ACPfifodropfromheaddisable_START (30)
#define SOC_FCM_KARMA_STGCTL_ACPfifodropfromheaddisable_END (30)
#define SOC_FCM_KARMA_STGCTL_CSREPgeneratepatter_START (31)
#define SOC_FCM_KARMA_STGCTL_CSREPgeneratepatter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_mulcore_th0 : 7;
        unsigned int BEADP_dcpe_th0 : 7;
        unsigned int ADBSREPDEG2 : 4;
        unsigned int ADBSREPDEG3 : 4;
        unsigned int REPtrackerupdatewh : 1;
        unsigned int REPtrackerupdateTH : 3;
        unsigned int ACupdateeveryDMD : 1;
        unsigned int ADBintervelTH : 5;
    } reg;
} SOC_FCM_KARMA_ADBREP_UNION;
#endif
#define SOC_FCM_KARMA_ADBREP_BEADP_mulcore_th0_START (0)
#define SOC_FCM_KARMA_ADBREP_BEADP_mulcore_th0_END (6)
#define SOC_FCM_KARMA_ADBREP_BEADP_dcpe_th0_START (7)
#define SOC_FCM_KARMA_ADBREP_BEADP_dcpe_th0_END (13)
#define SOC_FCM_KARMA_ADBREP_ADBSREPDEG2_START (14)
#define SOC_FCM_KARMA_ADBREP_ADBSREPDEG2_END (17)
#define SOC_FCM_KARMA_ADBREP_ADBSREPDEG3_START (18)
#define SOC_FCM_KARMA_ADBREP_ADBSREPDEG3_END (21)
#define SOC_FCM_KARMA_ADBREP_REPtrackerupdatewh_START (22)
#define SOC_FCM_KARMA_ADBREP_REPtrackerupdatewh_END (22)
#define SOC_FCM_KARMA_ADBREP_REPtrackerupdateTH_START (23)
#define SOC_FCM_KARMA_ADBREP_REPtrackerupdateTH_END (25)
#define SOC_FCM_KARMA_ADBREP_ACupdateeveryDMD_START (26)
#define SOC_FCM_KARMA_ADBREP_ACupdateeveryDMD_END (26)
#define SOC_FCM_KARMA_ADBREP_ADBintervelTH_START (27)
#define SOC_FCM_KARMA_ADBREP_ADBintervelTH_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_acphit_th0 : 7;
        unsigned int BEADP_l3hit_th0 : 7;
        unsigned int BEADP_ddrbw_th0 : 7;
        unsigned int BEADP_dcp_enable : 1;
        unsigned int BEADP_rep_enable : 1;
        unsigned int BEADP_acp_enable : 1;
        unsigned int MAXDCPDEG : 6;
        unsigned int DMDREQinjectdisable : 1;
        unsigned int AdaptiveMAXREPdeg : 1;
    } reg;
} SOC_FCM_KARMA_ADBDCP_UNION;
#endif
#define SOC_FCM_KARMA_ADBDCP_BEADP_acphit_th0_START (0)
#define SOC_FCM_KARMA_ADBDCP_BEADP_acphit_th0_END (6)
#define SOC_FCM_KARMA_ADBDCP_BEADP_l3hit_th0_START (7)
#define SOC_FCM_KARMA_ADBDCP_BEADP_l3hit_th0_END (13)
#define SOC_FCM_KARMA_ADBDCP_BEADP_ddrbw_th0_START (14)
#define SOC_FCM_KARMA_ADBDCP_BEADP_ddrbw_th0_END (20)
#define SOC_FCM_KARMA_ADBDCP_BEADP_dcp_enable_START (21)
#define SOC_FCM_KARMA_ADBDCP_BEADP_dcp_enable_END (21)
#define SOC_FCM_KARMA_ADBDCP_BEADP_rep_enable_START (22)
#define SOC_FCM_KARMA_ADBDCP_BEADP_rep_enable_END (22)
#define SOC_FCM_KARMA_ADBDCP_BEADP_acp_enable_START (23)
#define SOC_FCM_KARMA_ADBDCP_BEADP_acp_enable_END (23)
#define SOC_FCM_KARMA_ADBDCP_MAXDCPDEG_START (24)
#define SOC_FCM_KARMA_ADBDCP_MAXDCPDEG_END (29)
#define SOC_FCM_KARMA_ADBDCP_DMDREQinjectdisable_START (30)
#define SOC_FCM_KARMA_ADBDCP_DMDREQinjectdisable_END (30)
#define SOC_FCM_KARMA_ADBDCP_AdaptiveMAXREPdeg_START (31)
#define SOC_FCM_KARMA_ADBDCP_AdaptiveMAXREPdeg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Naappr : 31;
        unsigned int parameter : 1;
    } reg;
} SOC_FCM_KARMA_ADPPR_UNION;
#endif
#define SOC_FCM_KARMA_ADPPR_Naappr_START (0)
#define SOC_FCM_KARMA_ADPPR_Naappr_END (30)
#define SOC_FCM_KARMA_ADPPR_parameter_START (31)
#define SOC_FCM_KARMA_ADPPR_parameter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int Naadbscctr : 31;
        unsigned int ac_cost : 1;
    } reg;
} SOC_FCM_KARMA_ADBSCCT_UNION;
#endif
#define SOC_FCM_KARMA_ADBSCCT_Naadbscctr_START (0)
#define SOC_FCM_KARMA_ADBSCCT_Naadbscctr_END (30)
#define SOC_FCM_KARMA_ADBSCCT_ac_cost_START (31)
#define SOC_FCM_KARMA_ADBSCCT_ac_cost_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ADBPREPefficiencyhighthreshold : 6;
        unsigned int PLD_also_train_PT : 1;
        unsigned int ACPFIFOtimeoutTH : 3;
        unsigned int ADBPREPefficiencyl : 6;
        unsigned int filterL3hitforREPge : 1;
        unsigned int REP_DCPgoodonlyincre : 1;
        unsigned int ACPFIFOtimeoutdropenable : 1;
        unsigned int STGhashenable : 1;
        unsigned int ADBPcyclegap : 4;
        unsigned int ADBPdisable : 1;
        unsigned int tilizationwhendis : 2;
        unsigned int DCPacross4Kenable : 1;
        unsigned int TSoverflowACupdatedecr : 3;
        unsigned int don_tupdateTSisall : 1;
    } reg;
} SOC_FCM_KARMA_ADBBSC_UNION;
#endif
#define SOC_FCM_KARMA_ADBBSC_ADBPREPefficiencyhighthreshold_START (0)
#define SOC_FCM_KARMA_ADBBSC_ADBPREPefficiencyhighthreshold_END (5)
#define SOC_FCM_KARMA_ADBBSC_PLD_also_train_PT_START (6)
#define SOC_FCM_KARMA_ADBBSC_PLD_also_train_PT_END (6)
#define SOC_FCM_KARMA_ADBBSC_ACPFIFOtimeoutTH_START (7)
#define SOC_FCM_KARMA_ADBBSC_ACPFIFOtimeoutTH_END (9)
#define SOC_FCM_KARMA_ADBBSC_ADBPREPefficiencyl_START (10)
#define SOC_FCM_KARMA_ADBBSC_ADBPREPefficiencyl_END (15)
#define SOC_FCM_KARMA_ADBBSC_filterL3hitforREPge_START (16)
#define SOC_FCM_KARMA_ADBBSC_filterL3hitforREPge_END (16)
#define SOC_FCM_KARMA_ADBBSC_REP_DCPgoodonlyincre_START (17)
#define SOC_FCM_KARMA_ADBBSC_REP_DCPgoodonlyincre_END (17)
#define SOC_FCM_KARMA_ADBBSC_ACPFIFOtimeoutdropenable_START (18)
#define SOC_FCM_KARMA_ADBBSC_ACPFIFOtimeoutdropenable_END (18)
#define SOC_FCM_KARMA_ADBBSC_STGhashenable_START (19)
#define SOC_FCM_KARMA_ADBBSC_STGhashenable_END (19)
#define SOC_FCM_KARMA_ADBBSC_ADBPcyclegap_START (20)
#define SOC_FCM_KARMA_ADBBSC_ADBPcyclegap_END (23)
#define SOC_FCM_KARMA_ADBBSC_ADBPdisable_START (24)
#define SOC_FCM_KARMA_ADBBSC_ADBPdisable_END (24)
#define SOC_FCM_KARMA_ADBBSC_tilizationwhendis_START (25)
#define SOC_FCM_KARMA_ADBBSC_tilizationwhendis_END (26)
#define SOC_FCM_KARMA_ADBBSC_DCPacross4Kenable_START (27)
#define SOC_FCM_KARMA_ADBBSC_DCPacross4Kenable_END (27)
#define SOC_FCM_KARMA_ADBBSC_TSoverflowACupdatedecr_START (28)
#define SOC_FCM_KARMA_ADBBSC_TSoverflowACupdatedecr_END (30)
#define SOC_FCM_KARMA_ADBBSC_don_tupdateTSisall_START (31)
#define SOC_FCM_KARMA_ADBBSC_don_tupdateTSisall_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ADBPDCPefficiencyh : 6;
        unsigned int STGupdateevenCMDmasked : 1;
        unsigned int L3hitrateTH : 3;
        unsigned int ADBPDCPefficiencylow : 6;
        unsigned int STGupdateevenIDismasked : 1;
        unsigned int REP_DCPfiltermodeforL3hit : 2;
        unsigned int filterDCPforL3hitrequests : 1;
        unsigned int ADBPDCONFACCTH : 5;
        unsigned int ADBPEFFPFCNTshift : 2;
        unsigned int multicpu_CNT_disable_big_co : 1;
        unsigned int STGupdateallCMD : 1;
        unsigned int STGupdateallID : 1;
        unsigned int REPDEGadaptivechange : 1;
        unsigned int DCPDEGadaptivechange : 1;
    } reg;
} SOC_FCM_KARMA_ADBEFF_UNION;
#endif
#define SOC_FCM_KARMA_ADBEFF_ADBPDCPefficiencyh_START (0)
#define SOC_FCM_KARMA_ADBEFF_ADBPDCPefficiencyh_END (5)
#define SOC_FCM_KARMA_ADBEFF_STGupdateevenCMDmasked_START (6)
#define SOC_FCM_KARMA_ADBEFF_STGupdateevenCMDmasked_END (6)
#define SOC_FCM_KARMA_ADBEFF_L3hitrateTH_START (7)
#define SOC_FCM_KARMA_ADBEFF_L3hitrateTH_END (9)
#define SOC_FCM_KARMA_ADBEFF_ADBPDCPefficiencylow_START (10)
#define SOC_FCM_KARMA_ADBEFF_ADBPDCPefficiencylow_END (15)
#define SOC_FCM_KARMA_ADBEFF_STGupdateevenIDismasked_START (16)
#define SOC_FCM_KARMA_ADBEFF_STGupdateevenIDismasked_END (16)
#define SOC_FCM_KARMA_ADBEFF_REP_DCPfiltermodeforL3hit_START (17)
#define SOC_FCM_KARMA_ADBEFF_REP_DCPfiltermodeforL3hit_END (18)
#define SOC_FCM_KARMA_ADBEFF_filterDCPforL3hitrequests_START (19)
#define SOC_FCM_KARMA_ADBEFF_filterDCPforL3hitrequests_END (19)
#define SOC_FCM_KARMA_ADBEFF_ADBPDCONFACCTH_START (20)
#define SOC_FCM_KARMA_ADBEFF_ADBPDCONFACCTH_END (24)
#define SOC_FCM_KARMA_ADBEFF_ADBPEFFPFCNTshift_START (25)
#define SOC_FCM_KARMA_ADBEFF_ADBPEFFPFCNTshift_END (26)
#define SOC_FCM_KARMA_ADBEFF_multicpu_CNT_disable_big_co_START (27)
#define SOC_FCM_KARMA_ADBEFF_multicpu_CNT_disable_big_co_END (27)
#define SOC_FCM_KARMA_ADBEFF_STGupdateallCMD_START (28)
#define SOC_FCM_KARMA_ADBEFF_STGupdateallCMD_END (28)
#define SOC_FCM_KARMA_ADBEFF_STGupdateallID_START (29)
#define SOC_FCM_KARMA_ADBEFF_STGupdateallID_END (29)
#define SOC_FCM_KARMA_ADBEFF_REPDEGadaptivechange_START (30)
#define SOC_FCM_KARMA_ADBEFF_REPDEGadaptivechange_END (30)
#define SOC_FCM_KARMA_ADBEFF_DCPDEGadaptivechange_START (31)
#define SOC_FCM_KARMA_ADBEFF_DCPDEGadaptivechange_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_l3hit_th3 : 7;
        unsigned int BEADP_BW_select2 : 1;
        unsigned int BEADP_BW_th2 : 6;
        unsigned int PT_4K_buffer_number : 2;
        unsigned int DMC_averate_counter_T3 : 5;
        unsigned int PT_4K_time_out_threshold : 3;
        unsigned int DDRintervalnumber : 4;
        unsigned int DDRaverageincrease : 3;
        unsigned int CSADPalgorithmdisable : 1;
    } reg;
} SOC_FCM_KARMA_ADBDMCC_UNION;
#endif
#define SOC_FCM_KARMA_ADBDMCC_BEADP_l3hit_th3_START (0)
#define SOC_FCM_KARMA_ADBDMCC_BEADP_l3hit_th3_END (6)
#define SOC_FCM_KARMA_ADBDMCC_BEADP_BW_select2_START (7)
#define SOC_FCM_KARMA_ADBDMCC_BEADP_BW_select2_END (7)
#define SOC_FCM_KARMA_ADBDMCC_BEADP_BW_th2_START (8)
#define SOC_FCM_KARMA_ADBDMCC_BEADP_BW_th2_END (13)
#define SOC_FCM_KARMA_ADBDMCC_PT_4K_buffer_number_START (14)
#define SOC_FCM_KARMA_ADBDMCC_PT_4K_buffer_number_END (15)
#define SOC_FCM_KARMA_ADBDMCC_DMC_averate_counter_T3_START (16)
#define SOC_FCM_KARMA_ADBDMCC_DMC_averate_counter_T3_END (20)
#define SOC_FCM_KARMA_ADBDMCC_PT_4K_time_out_threshold_START (21)
#define SOC_FCM_KARMA_ADBDMCC_PT_4K_time_out_threshold_END (23)
#define SOC_FCM_KARMA_ADBDMCC_DDRintervalnumber_START (24)
#define SOC_FCM_KARMA_ADBDMCC_DDRintervalnumber_END (27)
#define SOC_FCM_KARMA_ADBDMCC_DDRaverageincrease_START (28)
#define SOC_FCM_KARMA_ADBDMCC_DDRaverageincrease_END (30)
#define SOC_FCM_KARMA_ADBDMCC_CSADPalgorithmdisable_START (31)
#define SOC_FCM_KARMA_ADBDMCC_CSADPalgorithmdisable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clearenable : 1;
        unsigned int CPUIDmaskforPT : 8;
        unsigned int ACP_send_read_request : 1;
        unsigned int BEADP_l3hit_th4 : 7;
        unsigned int BEADP_l3BW_th3 : 7;
        unsigned int BEADP_ACPhit_th3 : 7;
        unsigned int ADB_intervel_source : 1;
    } reg;
} SOC_FCM_KARMA_CLRCTL_UNION;
#endif
#define SOC_FCM_KARMA_CLRCTL_clearenable_START (0)
#define SOC_FCM_KARMA_CLRCTL_clearenable_END (0)
#define SOC_FCM_KARMA_CLRCTL_CPUIDmaskforPT_START (1)
#define SOC_FCM_KARMA_CLRCTL_CPUIDmaskforPT_END (8)
#define SOC_FCM_KARMA_CLRCTL_ACP_send_read_request_START (9)
#define SOC_FCM_KARMA_CLRCTL_ACP_send_read_request_END (9)
#define SOC_FCM_KARMA_CLRCTL_BEADP_l3hit_th4_START (10)
#define SOC_FCM_KARMA_CLRCTL_BEADP_l3hit_th4_END (16)
#define SOC_FCM_KARMA_CLRCTL_BEADP_l3BW_th3_START (17)
#define SOC_FCM_KARMA_CLRCTL_BEADP_l3BW_th3_END (23)
#define SOC_FCM_KARMA_CLRCTL_BEADP_ACPhit_th3_START (24)
#define SOC_FCM_KARMA_CLRCTL_BEADP_ACPhit_th3_END (30)
#define SOC_FCM_KARMA_CLRCTL_ADB_intervel_source_START (31)
#define SOC_FCM_KARMA_CLRCTL_ADB_intervel_source_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_hzd_th5 : 7;
        unsigned int BEADP_bw_th5 : 7;
        unsigned int BEADP_acphit_th5 : 7;
        unsigned int BEADP_l3hit_th5 : 7;
        unsigned int BE_ADP_total_levels : 2;
        unsigned int BE_ADP_ACP_levels : 2;
    } reg;
} SOC_FCM_KARMA_BEADPCTL1_UNION;
#endif
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_hzd_th5_START (0)
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_hzd_th5_END (6)
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_bw_th5_START (7)
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_bw_th5_END (13)
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_acphit_th5_START (14)
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_acphit_th5_END (20)
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_l3hit_th5_START (21)
#define SOC_FCM_KARMA_BEADPCTL1_BEADP_l3hit_th5_END (27)
#define SOC_FCM_KARMA_BEADPCTL1_BE_ADP_total_levels_START (28)
#define SOC_FCM_KARMA_BEADPCTL1_BE_ADP_total_levels_END (29)
#define SOC_FCM_KARMA_BEADPCTL1_BE_ADP_ACP_levels_START (30)
#define SOC_FCM_KARMA_BEADPCTL1_BE_ADP_ACP_levels_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_hzd_th6 : 7;
        unsigned int BEADP_bw_th6 : 7;
        unsigned int BEADP_acphit_th6 : 7;
        unsigned int BEADP_l3hit_th6 : 7;
        unsigned int BE_ADP_ACP_outstanding : 2;
        unsigned int BE_ADP_ACP_hack_levels : 2;
    } reg;
} SOC_FCM_KARMA_BEADPCTL2_UNION;
#endif
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_hzd_th6_START (0)
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_hzd_th6_END (6)
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_bw_th6_START (7)
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_bw_th6_END (13)
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_acphit_th6_START (14)
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_acphit_th6_END (20)
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_l3hit_th6_START (21)
#define SOC_FCM_KARMA_BEADPCTL2_BEADP_l3hit_th6_END (27)
#define SOC_FCM_KARMA_BEADPCTL2_BE_ADP_ACP_outstanding_START (28)
#define SOC_FCM_KARMA_BEADPCTL2_BE_ADP_ACP_outstanding_END (29)
#define SOC_FCM_KARMA_BEADPCTL2_BE_ADP_ACP_hack_levels_START (30)
#define SOC_FCM_KARMA_BEADPCTL2_BE_ADP_ACP_hack_levels_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int BEADP_repeff_th7 : 7;
        unsigned int BEADP_dcpeff_th7 : 7;
        unsigned int BEADP_l3bw_th4 : 7;
        unsigned int BEADP_acp_th4 : 7;
        unsigned int BE_ADP_DEG0_hack : 2;
        unsigned int BE_ADP_intervel_timer_en : 1;
        unsigned int BE_ADP_clr_timer_en : 1;
    } reg;
} SOC_FCM_KARMA_BEADPCTL3_UNION;
#endif
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_repeff_th7_START (0)
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_repeff_th7_END (6)
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_dcpeff_th7_START (7)
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_dcpeff_th7_END (13)
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_l3bw_th4_START (14)
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_l3bw_th4_END (20)
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_acp_th4_START (21)
#define SOC_FCM_KARMA_BEADPCTL3_BEADP_acp_th4_END (27)
#define SOC_FCM_KARMA_BEADPCTL3_BE_ADP_DEG0_hack_START (28)
#define SOC_FCM_KARMA_BEADPCTL3_BE_ADP_DEG0_hack_END (29)
#define SOC_FCM_KARMA_BEADPCTL3_BE_ADP_intervel_timer_en_START (30)
#define SOC_FCM_KARMA_BEADPCTL3_BE_ADP_intervel_timer_en_END (30)
#define SOC_FCM_KARMA_BEADPCTL3_BE_ADP_clr_timer_en_START (31)
#define SOC_FCM_KARMA_BEADPCTL3_BE_ADP_clr_timer_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NAadpctl4 : 31;
        unsigned int adp_th4 : 1;
    } reg;
} SOC_FCM_KARMA_BEADPCTL4_UNION;
#endif
#define SOC_FCM_KARMA_BEADPCTL4_NAadpctl4_START (0)
#define SOC_FCM_KARMA_BEADPCTL4_NAadpctl4_END (30)
#define SOC_FCM_KARMA_BEADPCTL4_adp_th4_START (31)
#define SOC_FCM_KARMA_BEADPCTL4_adp_th4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L3_average_T3 : 5;
        unsigned int BEADP_bw_th0 : 7;
        unsigned int PT_traffice_limit_TH : 3;
        unsigned int BEADP_hazard_sel2 : 1;
        unsigned int ADP_force_DCP_hit_total : 1;
        unsigned int ADP_force_DCP_hit_ACP : 1;
        unsigned int ADP_force_DCP_hit_EFF : 1;
        unsigned int DCP_enable : 1;
        unsigned int REP_enable : 1;
        unsigned int REP_select : 1;
        unsigned int EFF_select : 1;
        unsigned int BEADP_GPU_BW_TH0 : 5;
        unsigned int AC_shift_system_feedback : 4;
    } reg;
} SOC_FCM_KARMA_BEADPCTL5_UNION;
#endif
#define SOC_FCM_KARMA_BEADPCTL5_L3_average_T3_START (0)
#define SOC_FCM_KARMA_BEADPCTL5_L3_average_T3_END (4)
#define SOC_FCM_KARMA_BEADPCTL5_BEADP_bw_th0_START (5)
#define SOC_FCM_KARMA_BEADPCTL5_BEADP_bw_th0_END (11)
#define SOC_FCM_KARMA_BEADPCTL5_PT_traffice_limit_TH_START (12)
#define SOC_FCM_KARMA_BEADPCTL5_PT_traffice_limit_TH_END (14)
#define SOC_FCM_KARMA_BEADPCTL5_BEADP_hazard_sel2_START (15)
#define SOC_FCM_KARMA_BEADPCTL5_BEADP_hazard_sel2_END (15)
#define SOC_FCM_KARMA_BEADPCTL5_ADP_force_DCP_hit_total_START (16)
#define SOC_FCM_KARMA_BEADPCTL5_ADP_force_DCP_hit_total_END (16)
#define SOC_FCM_KARMA_BEADPCTL5_ADP_force_DCP_hit_ACP_START (17)
#define SOC_FCM_KARMA_BEADPCTL5_ADP_force_DCP_hit_ACP_END (17)
#define SOC_FCM_KARMA_BEADPCTL5_ADP_force_DCP_hit_EFF_START (18)
#define SOC_FCM_KARMA_BEADPCTL5_ADP_force_DCP_hit_EFF_END (18)
#define SOC_FCM_KARMA_BEADPCTL5_DCP_enable_START (19)
#define SOC_FCM_KARMA_BEADPCTL5_DCP_enable_END (19)
#define SOC_FCM_KARMA_BEADPCTL5_REP_enable_START (20)
#define SOC_FCM_KARMA_BEADPCTL5_REP_enable_END (20)
#define SOC_FCM_KARMA_BEADPCTL5_REP_select_START (21)
#define SOC_FCM_KARMA_BEADPCTL5_REP_select_END (21)
#define SOC_FCM_KARMA_BEADPCTL5_EFF_select_START (22)
#define SOC_FCM_KARMA_BEADPCTL5_EFF_select_END (22)
#define SOC_FCM_KARMA_BEADPCTL5_BEADP_GPU_BW_TH0_START (23)
#define SOC_FCM_KARMA_BEADPCTL5_BEADP_GPU_BW_TH0_END (27)
#define SOC_FCM_KARMA_BEADPCTL5_AC_shift_system_feedback_START (28)
#define SOC_FCM_KARMA_BEADPCTL5_AC_shift_system_feedback_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char karmaidle : 1;
        unsigned char Ptmemorylatenc : 1;
    } reg;
} SOC_FCM_KARMA_STATUS_UNION;
#endif
#define SOC_FCM_KARMA_STATUS_karmaidle_START (0)
#define SOC_FCM_KARMA_STATUS_karmaidle_END (0)
#define SOC_FCM_KARMA_STATUS_Ptmemorylatenc_START (1)
#define SOC_FCM_KARMA_STATUS_Ptmemorylatenc_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L3_bandwith : 8;
        unsigned int L3_utilization : 8;
        unsigned int multicore_bandwith : 8;
        unsigned int DDR_utilization : 7;
        unsigned int ADP_level_dec_vld : 1;
    } reg;
} SOC_FCM_KARMA_BEADP1_UNION;
#endif
#define SOC_FCM_KARMA_BEADP1_L3_bandwith_START (0)
#define SOC_FCM_KARMA_BEADP1_L3_bandwith_END (7)
#define SOC_FCM_KARMA_BEADP1_L3_utilization_START (8)
#define SOC_FCM_KARMA_BEADP1_L3_utilization_END (15)
#define SOC_FCM_KARMA_BEADP1_multicore_bandwith_START (16)
#define SOC_FCM_KARMA_BEADP1_multicore_bandwith_END (23)
#define SOC_FCM_KARMA_BEADP1_DDR_utilization_START (24)
#define SOC_FCM_KARMA_BEADP1_DDR_utilization_END (30)
#define SOC_FCM_KARMA_BEADP1_ADP_level_dec_vld_START (31)
#define SOC_FCM_KARMA_BEADP1_ADP_level_dec_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int REP_good_ratio : 6;
        unsigned int NABEADPP3 : 6;
        unsigned int DCP_good_ratio : 6;
        unsigned int NABEADPP2 : 4;
        unsigned int total_good_ratio : 6;
        unsigned int NABEADPP1 : 4;
    } reg;
} SOC_FCM_KARMA_BEADP2_UNION;
#endif
#define SOC_FCM_KARMA_BEADP2_REP_good_ratio_START (0)
#define SOC_FCM_KARMA_BEADP2_REP_good_ratio_END (5)
#define SOC_FCM_KARMA_BEADP2_NABEADPP3_START (6)
#define SOC_FCM_KARMA_BEADP2_NABEADPP3_END (11)
#define SOC_FCM_KARMA_BEADP2_DCP_good_ratio_START (12)
#define SOC_FCM_KARMA_BEADP2_DCP_good_ratio_END (17)
#define SOC_FCM_KARMA_BEADP2_NABEADPP2_START (18)
#define SOC_FCM_KARMA_BEADP2_NABEADPP2_END (21)
#define SOC_FCM_KARMA_BEADP2_total_good_ratio_START (22)
#define SOC_FCM_KARMA_BEADP2_total_good_ratio_END (27)
#define SOC_FCM_KARMA_BEADP2_NABEADPP1_START (28)
#define SOC_FCM_KARMA_BEADP2_NABEADPP1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int L3_hit_rate : 6;
        unsigned int NABE2 : 6;
        unsigned int acp_hit_rate : 6;
        unsigned int NABE1 : 4;
        unsigned int hazard_rate : 6;
        unsigned int NABE0 : 4;
    } reg;
} SOC_FCM_KARMA_BEADP3_UNION;
#endif
#define SOC_FCM_KARMA_BEADP3_L3_hit_rate_START (0)
#define SOC_FCM_KARMA_BEADP3_L3_hit_rate_END (5)
#define SOC_FCM_KARMA_BEADP3_NABE2_START (6)
#define SOC_FCM_KARMA_BEADP3_NABE2_END (11)
#define SOC_FCM_KARMA_BEADP3_acp_hit_rate_START (12)
#define SOC_FCM_KARMA_BEADP3_acp_hit_rate_END (17)
#define SOC_FCM_KARMA_BEADP3_NABE1_START (18)
#define SOC_FCM_KARMA_BEADP3_NABE1_END (21)
#define SOC_FCM_KARMA_BEADP3_hazard_rate_START (22)
#define SOC_FCM_KARMA_BEADP3_hazard_rate_END (27)
#define SOC_FCM_KARMA_BEADP3_NABE0_START (28)
#define SOC_FCM_KARMA_BEADP3_NABE0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GID_mask_vector : 16;
        unsigned int ADBS_EFF0 : 4;
        unsigned int ADBS_EFF1 : 4;
        unsigned int ADBS_EFF2 : 4;
        unsigned int ADBS_EFF3 : 4;
    } reg;
} SOC_FCM_KARMA_SYSCTL_UNION;
#endif
#define SOC_FCM_KARMA_SYSCTL_GID_mask_vector_START (0)
#define SOC_FCM_KARMA_SYSCTL_GID_mask_vector_END (15)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF0_START (16)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF0_END (19)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF1_START (20)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF1_END (23)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF2_START (24)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF2_END (27)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF3_START (28)
#define SOC_FCM_KARMA_SYSCTL_ADBS_EFF3_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
