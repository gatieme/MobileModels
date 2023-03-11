#ifndef __QIC_INTERFACE_H__
#define __QIC_INTERFACE_H__ 
enum QIC_CORE_ID {
 QIC_ISP = 0x0,
 QIC_DSS,
 QIC_VENC,
 QIC_VDEC,
 QIC_IVP0,
 QIC_IVP1,
 QIC_IPP,
 QIC_ARPP,
 QIC_EPS,
 QIC_MDM,
 QIC_NPU_AICORE0,
 QIC_NPU_AICORE1,
 QIC_NPU_TS_0,
 QIC_NPU_TS_1,
 QIC_NPU_TCU,
 QIC_NPU_SYS2NPU,
 QIC_NPU_SYSDMA_0,
 QIC_NPU_SYSDMA_1,
 QIC_CORE_ID_MAX,
};
void dfx_qic_modid_register(unsigned int qic_coreid, unsigned int modid);
#endif
