#ifndef __HJPGENC160_CS_H_INCLUDED__
#define __HJPGENC160_CS_H_INCLUDED__

#define CS_JPEG_REG_BASE    0xE8300000

#define REG_BASE_TOP        (CS_JPEG_REG_BASE+0x4000)//0xE8304000
#define JPEG_TOP_MEM_SIZE   0x1000
#define JPGENC_CRG_CFG0     0x0

#define REG_BASE_SMMU       (CS_JPEG_REG_BASE+0x20000)//0xE8320000
#define SMMU_MEM_SIZE       0x20000
#define SMMU_INTMASK_NS             0x10
#define SMMU_INTCLR_NS              0x1C
#define SMMU_SMRX_NS_STREAM_ID_0    0x20
#define SMMU_SMRX_NS_STREAM_ID_4    0x30//(0x20+4*0x4)
#define SMMU_SMRX_NS_STREAM_ID_5    0x34//(0x20+5*0x4)
#define SMMU_RLD_EN0_NS             0x1F0
#define SMMU_RLD_EN1_NS             0x1F4
#define SMMU_RLD_EN2_NS             0x1F8
#define SMMU_CB_TTBR0               0x204
#define SMMU_CB_TTBCR               0x20C
#define SMMU_FAMA_CTRL0_NS          0x220
#define SMMU_FAMA_CTRL1_NS          0x224
#define SMMU_ADDR_MSB               0x300
#define SMMU_ERR_RDADDR             0x304
#define SMMU_ERR_WRADDR             0x308
#define SMMU_SMRX_S_STREAM_ID_0     0x500
#define SMMU_SMRX_S_STREAM_ID_4     0x510//(0x500+4*0x04)
#define SMMU_SMRX_S_STREAM_ID_5     0x514//(0x500+5*0x04)
#define SMMU_SMRX_P_STREAM_ID_0     0x10000
#define SMMU_SMRX_P_STREAM_ID_4     0x10010
#define SMMU_SMRX_P_STREAM_ID_5     0x10014

#define REG_BASE_CVDR       (CS_JPEG_REG_BASE+0x2000)//0xE8302000
#define CVDR_MEM_SIZE       0x1000

#define CVDR_AXI_JPEG_VP_WR_CFG_0_OFFSET            0x1C
#define CVDR_AXI_JPEG_VP_WR_AXI_FS_0_OFFSET         0x20
#define CVDR_AXI_JPEG_VP_WR_AXI_LINE_0_OFFSET       0x24
#define CVDR_AXI_JPEG_VP_WR_IF_CFG_0_OFFSET         0x28
#define CVDR_AXI_JPEG_LIMITER_VP_WR_0_OFFSET        0x400
#define CVDR_AXI_JPEG_NR_RD_CFG_0_OFFSET            0xA00
#define CVDR_AXI_JPEG_LIMITER_NR_RD_0_OFFSET        0xA08


enum JPEG_CLK_TYPE {
    JPEG_FUNC_CLK = 0,
    JPEG_CLK_MAX
};

#endif//__HJPGENC160_CS_H_INCLUDED__