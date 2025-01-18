#ifndef __SOC_VCODEC_BUS_INTERFACE_H__
#define __SOC_VCODEC_BUS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_COREID_ADDR(base) ((base) + (0x0000UL))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004UL))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_PRIORITY_ADDR(base) ((base) + (0x0008UL))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_MODE_ADDR(base) ((base) + (0x000CUL))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0010UL))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_SATURATION_ADDR(base) ((base) + (0x0014UL))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018UL))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_COREID_ADDR(base) ((base) + (0x0080UL))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0084UL))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_PRIORITY_ADDR(base) ((base) + (0x0088UL))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_MODE_ADDR(base) ((base) + (0x008CUL))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0090UL))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_SATURATION_ADDR(base) ((base) + (0x0094UL))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0098UL))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_COREID_ADDR(base) ((base) + (0x0100UL))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0104UL))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_PRIORITY_ADDR(base) ((base) + (0x0108UL))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_MODE_ADDR(base) ((base) + (0x010CUL))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0110UL))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_SATURATION_ADDR(base) ((base) + (0x0114UL))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0118UL))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_COREID_ADDR(base) ((base) + (0x0180UL))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0184UL))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_PRIORITY_ADDR(base) ((base) + (0x0188UL))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_MODE_ADDR(base) ((base) + (0x018CUL))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0190UL))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_SATURATION_ADDR(base) ((base) + (0x0194UL))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0198UL))
#define SOC_VCODEC_BUS_IVP32_QOS_ID_COREID_ADDR(base) ((base) + (0x0200UL))
#define SOC_VCODEC_BUS_IVP32_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0204UL))
#define SOC_VCODEC_BUS_IVP32_QOS_PRIORITY_ADDR(base) ((base) + (0x0208UL))
#define SOC_VCODEC_BUS_IVP32_QOS_MODE_ADDR(base) ((base) + (0x020CUL))
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0218UL))
#else
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_COREID_ADDR(base) ((base) + (0x0000))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_PRIORITY_ADDR(base) ((base) + (0x0008))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_MODE_ADDR(base) ((base) + (0x000C))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0010))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_SATURATION_ADDR(base) ((base) + (0x0014))
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_COREID_ADDR(base) ((base) + (0x0080))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0084))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_PRIORITY_ADDR(base) ((base) + (0x0088))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_MODE_ADDR(base) ((base) + (0x008C))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0090))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_SATURATION_ADDR(base) ((base) + (0x0094))
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0098))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_COREID_ADDR(base) ((base) + (0x0100))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0104))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_PRIORITY_ADDR(base) ((base) + (0x0108))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_MODE_ADDR(base) ((base) + (0x010C))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0110))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_SATURATION_ADDR(base) ((base) + (0x0114))
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0118))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_COREID_ADDR(base) ((base) + (0x0180))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0184))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_PRIORITY_ADDR(base) ((base) + (0x0188))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_MODE_ADDR(base) ((base) + (0x018C))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0190))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_SATURATION_ADDR(base) ((base) + (0x0194))
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0198))
#define SOC_VCODEC_BUS_IVP32_QOS_ID_COREID_ADDR(base) ((base) + (0x0200))
#define SOC_VCODEC_BUS_IVP32_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0204))
#define SOC_VCODEC_BUS_IVP32_QOS_PRIORITY_ADDR(base) ((base) + (0x0208))
#define SOC_VCODEC_BUS_IVP32_QOS_MODE_ADDR(base) ((base) + (0x020C))
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0218))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_COREID_ADDR(base) ((base) + (0x0000UL))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004UL))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_PRIORITY_ADDR(base) ((base) + (0x0008UL))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_MODE_ADDR(base) ((base) + (0x000CUL))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018UL))
#define SOC_VCODEC_BUS_ERR_ID_COREID_ADDR(base) ((base) + (0x1C00UL))
#define SOC_VCODEC_BUS_ERR_ID_REVISIONID_ADDR(base) ((base) + (0x1C04UL))
#define SOC_VCODEC_BUS_ERR_FAULTEN_ADDR(base) ((base) + (0x1C08UL))
#define SOC_VCODEC_BUS_ERR_ERRVLD_ADDR(base) ((base) + (0x1C0CUL))
#define SOC_VCODEC_BUS_ERR_ERRCLR_ADDR(base) ((base) + (0x1C10UL))
#define SOC_VCODEC_BUS_ERR_ERRLOG0_ADDR(base) ((base) + (0x1C14UL))
#define SOC_VCODEC_BUS_ERR_ERRLOG1_ADDR(base) ((base) + (0x1C18UL))
#define SOC_VCODEC_BUS_ERR_ERRLOG3_ADDR(base) ((base) + (0x1C20UL))
#define SOC_VCODEC_BUS_ERR_ERRLOG4_ADDR(base) ((base) + (0x1C24UL))
#define SOC_VCODEC_BUS_ERR_ERRLOG5_ADDR(base) ((base) + (0x1C28UL))
#define SOC_VCODEC_BUS_ERR_ERRLOG7_ADDR(base) ((base) + (0x1C30UL))
#define SOC_VCODEC_BUS_ERR_STALLEN_ADDR(base) ((base) + (0x1C38UL))
#else
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_COREID_ADDR(base) ((base) + (0x0000))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_PRIORITY_ADDR(base) ((base) + (0x0008))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_MODE_ADDR(base) ((base) + (0x000C))
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018))
#define SOC_VCODEC_BUS_ERR_ID_COREID_ADDR(base) ((base) + (0x1C00))
#define SOC_VCODEC_BUS_ERR_ID_REVISIONID_ADDR(base) ((base) + (0x1C04))
#define SOC_VCODEC_BUS_ERR_FAULTEN_ADDR(base) ((base) + (0x1C08))
#define SOC_VCODEC_BUS_ERR_ERRVLD_ADDR(base) ((base) + (0x1C0C))
#define SOC_VCODEC_BUS_ERR_ERRCLR_ADDR(base) ((base) + (0x1C10))
#define SOC_VCODEC_BUS_ERR_ERRLOG0_ADDR(base) ((base) + (0x1C14))
#define SOC_VCODEC_BUS_ERR_ERRLOG1_ADDR(base) ((base) + (0x1C18))
#define SOC_VCODEC_BUS_ERR_ERRLOG3_ADDR(base) ((base) + (0x1C20))
#define SOC_VCODEC_BUS_ERR_ERRLOG4_ADDR(base) ((base) + (0x1C24))
#define SOC_VCODEC_BUS_ERR_ERRLOG5_ADDR(base) ((base) + (0x1C28))
#define SOC_VCODEC_BUS_ERR_ERRLOG7_ADDR(base) ((base) + (0x1C30))
#define SOC_VCODEC_BUS_ERR_STALLEN_ADDR(base) ((base) + (0x1C38))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VCODEC_BUS_VDEC_QOS_ID_COREID_ADDR(base) ((base) + (0x0000UL))
#define SOC_VCODEC_BUS_VDEC_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004UL))
#define SOC_VCODEC_BUS_VDEC_QOS_PRIORITY_ADDR(base) ((base) + (0x0008UL))
#define SOC_VCODEC_BUS_VDEC_QOS_MODE_ADDR(base) ((base) + (0x000CUL))
#define SOC_VCODEC_BUS_VDEC_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0010UL))
#define SOC_VCODEC_BUS_VDEC_QOS_SATURATION_ADDR(base) ((base) + (0x0014UL))
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018UL))
#else
#define SOC_VCODEC_BUS_VDEC_QOS_ID_COREID_ADDR(base) ((base) + (0x0000))
#define SOC_VCODEC_BUS_VDEC_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004))
#define SOC_VCODEC_BUS_VDEC_QOS_PRIORITY_ADDR(base) ((base) + (0x0008))
#define SOC_VCODEC_BUS_VDEC_QOS_MODE_ADDR(base) ((base) + (0x000C))
#define SOC_VCODEC_BUS_VDEC_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0010))
#define SOC_VCODEC_BUS_VDEC_QOS_SATURATION_ADDR(base) ((base) + (0x0014))
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VCODEC_BUS_VENC_QOS_ID_COREID_ADDR(base) ((base) + (0x0000UL))
#define SOC_VCODEC_BUS_VENC_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004UL))
#define SOC_VCODEC_BUS_VENC_QOS_PRIORITY_ADDR(base) ((base) + (0x0008UL))
#define SOC_VCODEC_BUS_VENC_QOS_MODE_ADDR(base) ((base) + (0x000CUL))
#define SOC_VCODEC_BUS_VENC_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0010UL))
#define SOC_VCODEC_BUS_VENC_QOS_SATURATION_ADDR(base) ((base) + (0x0014UL))
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018UL))
#else
#define SOC_VCODEC_BUS_VENC_QOS_ID_COREID_ADDR(base) ((base) + (0x0000))
#define SOC_VCODEC_BUS_VENC_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0004))
#define SOC_VCODEC_BUS_VENC_QOS_PRIORITY_ADDR(base) ((base) + (0x0008))
#define SOC_VCODEC_BUS_VENC_QOS_MODE_ADDR(base) ((base) + (0x000C))
#define SOC_VCODEC_BUS_VENC_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0010))
#define SOC_VCODEC_BUS_VENC_QOS_SATURATION_ADDR(base) ((base) + (0x0014))
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0018))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_VCODEC_BUS_EPS_QOS_ID_COREID_ADDR(base) ((base) + (0x0280UL))
#define SOC_VCODEC_BUS_EPS_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0284UL))
#define SOC_VCODEC_BUS_EPS_QOS_PRIORITY_ADDR(base) ((base) + (0x0288UL))
#define SOC_VCODEC_BUS_EPS_QOS_MODE_ADDR(base) ((base) + (0x028CUL))
#define SOC_VCODEC_BUS_EPS_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0290UL))
#define SOC_VCODEC_BUS_EPS_QOS_SATURATION_ADDR(base) ((base) + (0x0294UL))
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0298UL))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_COREID_ADDR(base) ((base) + (0x0300UL))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0304UL))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_PRIORITY_ADDR(base) ((base) + (0x0308UL))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_MODE_ADDR(base) ((base) + (0x030CUL))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0318UL))
#else
#define SOC_VCODEC_BUS_EPS_QOS_ID_COREID_ADDR(base) ((base) + (0x0280))
#define SOC_VCODEC_BUS_EPS_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0284))
#define SOC_VCODEC_BUS_EPS_QOS_PRIORITY_ADDR(base) ((base) + (0x0288))
#define SOC_VCODEC_BUS_EPS_QOS_MODE_ADDR(base) ((base) + (0x028C))
#define SOC_VCODEC_BUS_EPS_QOS_BANDWIDTH_ADDR(base) ((base) + (0x0290))
#define SOC_VCODEC_BUS_EPS_QOS_SATURATION_ADDR(base) ((base) + (0x0294))
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0298))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_COREID_ADDR(base) ((base) + (0x0300))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_REVISIONID_ADDR(base) ((base) + (0x0304))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_PRIORITY_ADDR(base) ((base) + (0x0308))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_MODE_ADDR(base) ((base) + (0x030C))
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_ADDR(base) ((base) + (0x0318))
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
} SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_RD_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_RD_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_RD_QOS_BANDWIDTH_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_BANDWIDTH_bandwidth_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_BANDWIDTH_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int saturation : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_RD_QOS_SATURATION_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_SATURATION_saturation_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_SATURATION_saturation_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_IVP_CORE_RD_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_WR_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_WR_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_WR_QOS_BANDWIDTH_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_BANDWIDTH_bandwidth_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_BANDWIDTH_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int saturation : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_WR_QOS_SATURATION_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_SATURATION_saturation_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_SATURATION_saturation_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_IVP_CORE_WR_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_BANDWIDTH_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_BANDWIDTH_bandwidth_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_BANDWIDTH_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int saturation : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_SATURATION_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_SATURATION_saturation_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_SATURATION_saturation_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_IVP_IDMA_RD_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_BANDWIDTH_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_BANDWIDTH_bandwidth_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_BANDWIDTH_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int saturation : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_SATURATION_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_SATURATION_saturation_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_SATURATION_saturation_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_IVP_IDMA_WR_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_IVP32_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP32_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_IVP32_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_IVP32_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_IVP32_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_IVP32_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_IVP32_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_IVP32_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_IVP32_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_IVP32_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_IVP32_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_IVP32_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_IVP32_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_IVP32_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_IVP32_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_IVP32_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_IVP32_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_IVP32_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_IVP32_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_CFG2VCODEC_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_CFG2VCODEC_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_CFG2VCODEC_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_ERR_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_ERR_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_ERR_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_ERR_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_ERR_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_ERR_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_ERR_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_ERR_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int faulten : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VCODEC_BUS_ERR_FAULTEN_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_FAULTEN_faulten_START (0)
#define SOC_VCODEC_BUS_ERR_FAULTEN_faulten_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errvld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRVLD_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRVLD_errvld_START (0)
#define SOC_VCODEC_BUS_ERR_ERRVLD_errvld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errclr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRCLR_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRCLR_errclr_START (0)
#define SOC_VCODEC_BUS_ERR_ERRCLR_errclr_END (0)
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
        unsigned int len1 : 8;
        unsigned int reserved_2: 7;
        unsigned int format : 1;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRLOG0_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRLOG0_lock_START (0)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_lock_END (0)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_opc_START (1)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_opc_END (4)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_errcode_START (8)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_errcode_END (10)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_len1_START (16)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_len1_END (23)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_format_START (31)
#define SOC_VCODEC_BUS_ERR_ERRLOG0_format_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRLOG1_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRLOG1_errlog1_START (0)
#define SOC_VCODEC_BUS_ERR_ERRLOG1_errlog1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog3 : 32;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRLOG3_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRLOG3_errlog3_START (0)
#define SOC_VCODEC_BUS_ERR_ERRLOG3_errlog3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog4 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRLOG4_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRLOG4_errlog4_START (0)
#define SOC_VCODEC_BUS_ERR_ERRLOG4_errlog4_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog5 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRLOG5_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRLOG5_errlog5_START (0)
#define SOC_VCODEC_BUS_ERR_ERRLOG5_errlog5_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int errlog7 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_ERR_ERRLOG7_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_ERRLOG7_errlog7_START (0)
#define SOC_VCODEC_BUS_ERR_ERRLOG7_errlog7_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stallen : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_VCODEC_BUS_ERR_STALLEN_UNION;
#endif
#define SOC_VCODEC_BUS_ERR_STALLEN_stallen_START (0)
#define SOC_VCODEC_BUS_ERR_STALLEN_stallen_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_VDEC_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_VDEC_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_VDEC_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_VDEC_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_VDEC_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_VDEC_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_VDEC_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_VDEC_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_VDEC_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_VDEC_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_VDEC_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_VDEC_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_VDEC_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_VDEC_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_VDEC_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_VDEC_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_VDEC_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_VDEC_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_VCODEC_BUS_VDEC_QOS_BANDWIDTH_UNION;
#endif
#define SOC_VCODEC_BUS_VDEC_QOS_BANDWIDTH_bandwidth_START (0)
#define SOC_VCODEC_BUS_VDEC_QOS_BANDWIDTH_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int saturation : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VCODEC_BUS_VDEC_QOS_SATURATION_UNION;
#endif
#define SOC_VCODEC_BUS_VDEC_QOS_SATURATION_saturation_START (0)
#define SOC_VCODEC_BUS_VDEC_QOS_SATURATION_saturation_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_VDEC_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_VENC_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_VENC_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_VENC_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_VENC_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_VENC_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_VENC_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_VENC_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_VENC_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_VENC_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_VENC_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_VENC_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_VENC_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_VENC_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_VENC_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_VENC_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_VENC_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_VENC_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_VENC_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_VCODEC_BUS_VENC_QOS_BANDWIDTH_UNION;
#endif
#define SOC_VCODEC_BUS_VENC_QOS_BANDWIDTH_bandwidth_START (0)
#define SOC_VCODEC_BUS_VENC_QOS_BANDWIDTH_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int saturation : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VCODEC_BUS_VENC_QOS_SATURATION_UNION;
#endif
#define SOC_VCODEC_BUS_VENC_QOS_SATURATION_saturation_START (0)
#define SOC_VCODEC_BUS_VENC_QOS_SATURATION_saturation_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_VENC_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_EPS_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_EPS_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_EPS_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_EPS_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_EPS_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_EPS_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_EPS_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_EPS_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_EPS_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_EPS_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_EPS_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_EPS_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_EPS_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_EPS_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bandwidth : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_VCODEC_BUS_EPS_QOS_BANDWIDTH_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_QOS_BANDWIDTH_bandwidth_START (0)
#define SOC_VCODEC_BUS_EPS_QOS_BANDWIDTH_bandwidth_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int saturation : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_VCODEC_BUS_EPS_QOS_SATURATION_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_QOS_SATURATION_saturation_START (0)
#define SOC_VCODEC_BUS_EPS_QOS_SATURATION_saturation_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_EPS_QOS_EXTCONTROL_extlimiten_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coretypeid : 8;
        unsigned int corechecksum : 24;
    } reg;
} SOC_VCODEC_BUS_EPS_CFG_QOS_ID_COREID_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_COREID_coretypeid_START (0)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_COREID_coretypeid_END (7)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_COREID_corechecksum_START (8)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_COREID_corechecksum_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int userid : 8;
        unsigned int flexnocid : 24;
    } reg;
} SOC_VCODEC_BUS_EPS_CFG_QOS_ID_REVISIONID_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_REVISIONID_userid_START (0)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_REVISIONID_userid_END (7)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_REVISIONID_flexnocid_START (8)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_ID_REVISIONID_flexnocid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p0 : 2;
        unsigned int reserved_0: 6;
        unsigned int p1 : 2;
        unsigned int reserved_1: 22;
    } reg;
} SOC_VCODEC_BUS_EPS_CFG_QOS_PRIORITY_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_CFG_QOS_PRIORITY_p0_START (0)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_PRIORITY_p0_END (1)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_PRIORITY_p1_START (8)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_PRIORITY_p1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_VCODEC_BUS_EPS_CFG_QOS_MODE_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_CFG_QOS_MODE_mode_START (0)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_MODE_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socketqosen : 1;
        unsigned int extthren : 1;
        unsigned int intclken : 1;
        unsigned int extlimiten : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_UNION;
#endif
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_socketqosen_START (0)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_socketqosen_END (0)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_extthren_START (1)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_extthren_END (1)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_intclken_START (2)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_intclken_END (2)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_extlimiten_START (3)
#define SOC_VCODEC_BUS_EPS_CFG_QOS_EXTCONTROL_extlimiten_END (3)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
