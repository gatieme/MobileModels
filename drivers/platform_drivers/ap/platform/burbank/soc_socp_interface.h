#ifndef __SOC_SOCP_INTERFACE_H__
#define __SOC_SOCP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SOCP_GLOBAL_CTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_SOCP_ENC_SRST_CTRL_L_ADDR(base) ((base) + (0x004UL))
#define SOC_SOCP_ENC_SRST_CTRL_H_ADDR(base) ((base) + (0x008UL))
#define SOC_SOCP_DEC_SRST_CTRL_ADDR(base) ((base) + (0x00CUL))
#define SOC_SOCP_ENC_CH_STATUS_L_ADDR(base) ((base) + (0x010UL))
#define SOC_SOCP_ENC_CH_STATUS_H_ADDR(base) ((base) + (0x014UL))
#define SOC_SOCP_DEC_CH_STATUS_ADDR(base) ((base) + (0x018UL))
#define SOC_SOCP_CLK_CTRL_ADDR(base) ((base) + (0x01CUL))
#define SOC_SOCP_PRIOR_CFG_ADDR(base) ((base) + (0x020UL))
#define SOC_SOCP_DEC_INT_TIMEOUT_ADDR(base) ((base) + (0x024UL))
#define SOC_SOCP_INT_TIMEOUT_ADDR(base) ((base) + (0x028UL))
#define SOC_SOCP_BUFFER_TIMEOUT_ADDR(base) ((base) + (0x02CUL))
#define SOC_SOCP_DEC_PKT_LEN_CFG_ADDR(base) ((base) + (0x030UL))
#define SOC_SOCP_ENC_SRCCH_SECCTRL_L_ADDR(base) ((base) + (0x034UL))
#define SOC_SOCP_ENC_SRCCH_SECCTRL_H_ADDR(base) ((base) + (0x038UL))
#define SOC_SOCP_ENC_DSTCH_SECCTRL_ADDR(base) ((base) + (0x03CUL))
#define SOC_SOCP_DEC_SRCCH_SECCTRL_ADDR(base) ((base) + (0x040UL))
#define SOC_SOCP_DEC_DSTCH_SECCTRL_ADDR(base) ((base) + (0x044UL))
#define SOC_SOCP_GLB_REG_SECCTRL_ADDR(base) ((base) + (0x048UL))
#define SOC_SOCP_GLOBAL_INT_STATUS_ADDR(base) ((base) + (0x050UL))
#define SOC_SOCP_ENC_CORE0_MASK0_ADDR(base) ((base) + (0x054UL))
#define SOC_SOCP_ENC_CORE1_MASK0_ADDR(base) ((base) + (0x058UL))
#define SOC_SOCP_ENC_CORE2_MASK0_ADDR(base) ((base) + (0x05CUL))
#define SOC_SOCP_ENC_RAWINT0_ADDR(base) ((base) + (0x060UL))
#define SOC_SOCP_ENC_CORE0_INT0_ADDR(base) ((base) + (0x064UL))
#define SOC_SOCP_ENC_CORE1_INT0_ADDR(base) ((base) + (0x068UL))
#define SOC_SOCP_ENC_CORE2_INT0_ADDR(base) ((base) + (0x06CUL))
#define SOC_SOCP_ENC_CORE0_MASK1_L_ADDR(base) ((base) + (0x070UL))
#define SOC_SOCP_ENC_CORE0_MASK1_H_ADDR(base) ((base) + (0x074UL))
#define SOC_SOCP_ENC_CORE1_MASK1_L_ADDR(base) ((base) + (0x078UL))
#define SOC_SOCP_ENC_CORE1_MASK1_H_ADDR(base) ((base) + (0x07CUL))
#define SOC_SOCP_ENC_CORE2_MASK1_L_ADDR(base) ((base) + (0x080UL))
#define SOC_SOCP_ENC_CORE2_MASK1_H_ADDR(base) ((base) + (0x084UL))
#define SOC_SOCP_ENC_RAWINT1_L_ADDR(base) ((base) + (0x088UL))
#define SOC_SOCP_ENC_RAWINT1_H_ADDR(base) ((base) + (0x08CUL))
#define SOC_SOCP_ENC_CORE0_INT1_L_ADDR(base) ((base) + (0x090UL))
#define SOC_SOCP_ENC_CORE0_INT1_H_ADDR(base) ((base) + (0x094UL))
#define SOC_SOCP_ENC_CORE1_INT1_L_ADDR(base) ((base) + (0x098UL))
#define SOC_SOCP_ENC_CORE1_INT1_H_ADDR(base) ((base) + (0x09CUL))
#define SOC_SOCP_ENC_CORE2_INT1_L_ADDR(base) ((base) + (0x0A0UL))
#define SOC_SOCP_ENC_CORE2_INT1_H_ADDR(base) ((base) + (0x0A4UL))
#define SOC_SOCP_ENC_CORE0_MASK2_ADDR(base) ((base) + (0x0A8UL))
#define SOC_SOCP_ENC_CORE1_MASK2_ADDR(base) ((base) + (0x0ACUL))
#define SOC_SOCP_ENC_CORE2_MASK2_ADDR(base) ((base) + (0x0B0UL))
#define SOC_SOCP_ENC_RAWINT2_ADDR(base) ((base) + (0x0B4UL))
#define SOC_SOCP_ENC_CORE0_INT2_ADDR(base) ((base) + (0x0B8UL))
#define SOC_SOCP_ENC_CORE1_INT2_ADDR(base) ((base) + (0x0BCUL))
#define SOC_SOCP_ENC_CORE2_INT2_ADDR(base) ((base) + (0x0C0UL))
#define SOC_SOCP_ENC_CORE0_MASK3_L_ADDR(base) ((base) + (0x0C4UL))
#define SOC_SOCP_ENC_CORE0_MASK3_H_ADDR(base) ((base) + (0x0C8UL))
#define SOC_SOCP_ENC_CORE1_MASK3_L_ADDR(base) ((base) + (0x0CCUL))
#define SOC_SOCP_ENC_CORE1_MASK3_H_ADDR(base) ((base) + (0x0D0UL))
#define SOC_SOCP_ENC_CORE2_MASK3_L_ADDR(base) ((base) + (0x0D4UL))
#define SOC_SOCP_ENC_CORE2_MASK3_H_ADDR(base) ((base) + (0x0D8UL))
#define SOC_SOCP_ENC_RAWINT3_L_ADDR(base) ((base) + (0x0DCUL))
#define SOC_SOCP_ENC_RAWINT3_H_ADDR(base) ((base) + (0x0E0UL))
#define SOC_SOCP_ENC_CORE0_INT3_L_ADDR(base) ((base) + (0x0E4UL))
#define SOC_SOCP_ENC_CORE0_INT3_H_ADDR(base) ((base) + (0x0E8UL))
#define SOC_SOCP_ENC_CORE1_INT3_L_ADDR(base) ((base) + (0x0ECUL))
#define SOC_SOCP_ENC_CORE1_INT3_H_ADDR(base) ((base) + (0x0F0UL))
#define SOC_SOCP_ENC_CORE2_INT3_L_ADDR(base) ((base) + (0x0F4UL))
#define SOC_SOCP_ENC_CORE2_INT3_H_ADDR(base) ((base) + (0x0F8UL))
#define SOC_SOCP_DEC_CORE0_MASK0_ADDR(base) ((base) + (0x0FCUL))
#define SOC_SOCP_DEC_CORE1_MASK0_ADDR(base) ((base) + (0x100UL))
#define SOC_SOCP_DEC_CORE2_MASK0_ADDR(base) ((base) + (0x104UL))
#define SOC_SOCP_DEC_RAWINT0_ADDR(base) ((base) + (0x108UL))
#define SOC_SOCP_DEC_CORE0_INT0_ADDR(base) ((base) + (0x10CUL))
#define SOC_SOCP_DEC_CORE1_INT0_ADDR(base) ((base) + (0x110UL))
#define SOC_SOCP_DEC_CORE2_INT0_ADDR(base) ((base) + (0x114UL))
#define SOC_SOCP_DEC_CORE0_MASK1_ADDR(base) ((base) + (0x118UL))
#define SOC_SOCP_DEC_CORE1_MASK1_ADDR(base) ((base) + (0x11CUL))
#define SOC_SOCP_DEC_CORE2_MASK1_ADDR(base) ((base) + (0x120UL))
#define SOC_SOCP_DEC_RAWINT1_ADDR(base) ((base) + (0x124UL))
#define SOC_SOCP_DEC_CORE0_INT1_ADDR(base) ((base) + (0x128UL))
#define SOC_SOCP_DEC_CORE1_INT1_ADDR(base) ((base) + (0x12CUL))
#define SOC_SOCP_DEC_CORE2_INT1_ADDR(base) ((base) + (0x130UL))
#define SOC_SOCP_DEC_CORE0_MASK2_ADDR(base) ((base) + (0x134UL))
#define SOC_SOCP_DEC_CORE1_MASK2_ADDR(base) ((base) + (0x138UL))
#define SOC_SOCP_DEC_CORE2_MASK2_ADDR(base) ((base) + (0x13CUL))
#define SOC_SOCP_DEC_RAWINT2_ADDR(base) ((base) + (0x140UL))
#define SOC_SOCP_DEC_CORE0_INT2_ADDR(base) ((base) + (0x144UL))
#define SOC_SOCP_DEC_CORE1_INT2_ADDR(base) ((base) + (0x148UL))
#define SOC_SOCP_DEC_CORE2_INT2_ADDR(base) ((base) + (0x14CUL))
#define SOC_SOCP_BUS_ERROR_MASK_ADDR(base) ((base) + (0x150UL))
#define SOC_SOCP_BUS_ERROR_RAWINT_ADDR(base) ((base) + (0x154UL))
#define SOC_SOCP_BUS_ERROR_INT_ADDR(base) ((base) + (0x158UL))
#define SOC_SOCP_ENC_SRC_RATE_PERIOD_ADDR(base) ((base) + (0x180UL))
#define SOC_SOCP_ENC_SRC_RATE_EN_L_ADDR(base) ((base) + (0x184UL))
#define SOC_SOCP_ENC_SRC_RATE_EN_H_ADDR(base) ((base) + (0x188UL))
#define SOC_SOCP_ENC_SRC_PTR_IMG_CFG_ADDR(base) ((base) + (0x18CUL))
#define SOC_SOCP_ENC_SRC_RATE_THR_ADDR(base,m) ((base) + (0x190+0x4*(m)))
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_L_ADDR(base) ((base) + (0x290UL))
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_H_ADDR(base) ((base) + (0x294UL))
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_L_ADDR(base) ((base) + (0x298UL))
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_H_ADDR(base) ((base) + (0x29CUL))
#define SOC_SOCP_ENC_SRC_PTR_CORE0_MASK_ADDR(base) ((base) + (0x2A0UL))
#define SOC_SOCP_ENC_SRC_PTR_CORE1_MASK_ADDR(base) ((base) + (0x2A4UL))
#define SOC_SOCP_ENC_SRC_PTR_CORE2_MASK_ADDR(base) ((base) + (0x2A8UL))
#define SOC_SOCP_ENC_SRC_PTR_RAWINT_ADDR(base) ((base) + (0x2ACUL))
#define SOC_SOCP_ENC_SRC_PTR_CORE0_INT_ADDR(base) ((base) + (0x2B0UL))
#define SOC_SOCP_ENC_SRC_PTR_CORE1_INT_ADDR(base) ((base) + (0x2B4UL))
#define SOC_SOCP_ENC_SRC_PTR_CORE2_INT_ADDR(base) ((base) + (0x2B8UL))
#define SOC_SOCP_ENC_SRC_BUFM_WPTR_ADDR(base,m) ((base) + (0x300+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_ADDR(base,m) ((base) + (0x304+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_L_ADDR(base,m) ((base) + (0x308+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_H_ADDR(base,m) ((base) + (0x30C+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_DEPTH_ADDR(base,m) ((base) + (0x310+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_CFG_ADDR(base,m) ((base) + (0x314+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_ADDR(base,m) ((base) + (0x318+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_RPTR_ADDR(base,m) ((base) + (0x31C+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_L_ADDR(base,m) ((base) + (0x320+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_H_ADDR(base,m) ((base) + (0x324+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_CFG_ADDR(base,m) ((base) + (0x328+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_L_ADDR(base,m) ((base) + (0x32C+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_H_ADDR(base,m) ((base) + (0x330+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_L_ADDR(base,m) ((base) + (0x334+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_H_ADDR(base,m) ((base) + (0x338+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RATE_CNT_CTRL_ADDR(base,m) ((base) + (0x33C+0x40*(m)))
#define SOC_SOCP_ENC_DEST_BUFN_WPTR_ADDR(base,n) ((base) + (0x1300+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_RPTR_ADDR(base,n) ((base) + (0x1304+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_L_ADDR(base,n) ((base) + (0x1308+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_H_ADDR(base,n) ((base) + (0x130C+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_DEPTH_ADDR(base,n) ((base) + (0x1310+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_THRH_ADDR(base,n) ((base) + (0x1314+0x40*(n)))
#define SOC_SOCP_ENC_INT_THRESHOLD_ADDR(base,n) ((base) + (0x1318+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUF_MODE_ADDR(base,n) ((base) + (0x131C+0x40*(n)))
#define SOC_SOCP_ENC_DEST_TRANSID_ADDR(base,n) ((base) + (0x1320+0x40*(n)))
#define SOC_SOCP_DEC_SRC_BUFX_WPTR_ADDR(base,j) ((base) + (0x1400+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_RPTR_ADDR(base,j) ((base) + (0x1404+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_L_ADDR(base,j) ((base) + (0x1408+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_H_ADDR(base,j) ((base) + (0x140C+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_ADDR(base,j) ((base) + (0x1410+0x40*(j)))
#define SOC_SOCP_DEC_BUFX_STATUS0_ADDR(base,j) ((base) + (0x1414+0x40*(j)))
#define SOC_SOCP_DEC_BUFX_STATUS1_ADDR(base,j) ((base) + (0x1418+0x40*(j)))
#define SOC_SOCP_DEC_DEST_BUFY_WPTR_ADDR(base,y) ((base) + (0x1500+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_RPTR_ADDR(base,y) ((base) + (0x1504+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_L_ADDR(base,y) ((base) + (0x1508+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_H_ADDR(base,y) ((base) + (0x150C+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_ADDR(base,y) ((base) + (0x1510+0x40*(y)))
#define SOC_SOCP_ENC_CD_DBG0_ADDR(base) ((base) + (0x1600UL))
#define SOC_SOCP_ENC_CD_DBG1_ADDR(base) ((base) + (0x1604UL))
#define SOC_SOCP_ENC_IBUF_DBG0_ADDR(base) ((base) + (0x1608UL))
#define SOC_SOCP_ENC_IBUF_DBG1_ADDR(base) ((base) + (0x160CUL))
#define SOC_SOCP_ENC_IBUF_DBG2_ADDR(base) ((base) + (0x1610UL))
#define SOC_SOCP_ENC_IBUF_DBG3_ADDR(base) ((base) + (0x1614UL))
#define SOC_SOCP_ENC_OBUF_DBG0_ADDR(base) ((base) + (0x1618UL))
#define SOC_SOCP_ENC_OBUF_DBG1_ADDR(base) ((base) + (0x161CUL))
#define SOC_SOCP_ENC_OBUF_DBG2_ADDR(base) ((base) + (0x1620UL))
#define SOC_SOCP_ENC_OBUF_DBG3_ADDR(base) ((base) + (0x1624UL))
#define SOC_SOCP_DEC_IBUF_DBG0_ADDR(base) ((base) + (0x1628UL))
#define SOC_SOCP_DEC_IBUF_DBG1_ADDR(base) ((base) + (0x162CUL))
#define SOC_SOCP_DEC_IBUF_DBG2_ADDR(base) ((base) + (0x1630UL))
#define SOC_SOCP_DEC_IBUF_DBG3_ADDR(base) ((base) + (0x1634UL))
#define SOC_SOCP_DEC_OBUF_DBG0_ADDR(base) ((base) + (0x1638UL))
#define SOC_SOCP_DEC_OBUF_DBG1_ADDR(base) ((base) + (0x163CUL))
#define SOC_SOCP_DEC_OBUF_DBG2_ADDR(base) ((base) + (0x1640UL))
#define SOC_SOCP_DEC_OBUF_DBG3_ADDR(base) ((base) + (0x1644UL))
#define SOC_SOCP_ENC_PTR_DBG0_ADDR(base) ((base) + (0x1648UL))
#define SOC_SOCP_ENC_PTR_DBG1_ADDR(base) ((base) + (0x164CUL))
#define SOC_SOCP_ENC_PTR_DBG2_ADDR(base) ((base) + (0x1650UL))
#define SOC_SOCP_ENC_PTR_DBG3_ADDR(base) ((base) + (0x1654UL))
#define SOC_SOCP_ENC_CH_TRH_DBG0_ADDR(base) ((base) + (0x1658UL))
#define SOC_SOCP_ENC_CH_TRH_DBG1_ADDR(base) ((base) + (0x165CUL))
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ADDR(base) ((base) + (0x1660UL))
#define SOC_SOCP_ENC_PTR_IMG_DBG1_ADDR(base) ((base) + (0x1664UL))
#define SOC_SOCP_ENC_PTR_IMG_DBG2_ADDR(base) ((base) + (0x1668UL))
#define SOC_SOCP_ENC_PTR_IMG_DBG3_ADDR(base) ((base) + (0x166CUL))
#define SOC_SOCP_ENC_PTR_IMG_DBG4_ADDR(base) ((base) + (0x1670UL))
#define SOC_SOCP_ENC_RD_IMG_DBG0_ADDR(base) ((base) + (0x1674UL))
#define SOC_SOCP_ENC_RD_IMG_DBG1_ADDR(base) ((base) + (0x1678UL))
#define SOC_SOCP_ENC_RD_IMG_DBG2_ADDR(base) ((base) + (0x167CUL))
#define SOC_SOCP_ENC_RD_IMG_DBG3_ADDR(base) ((base) + (0x1680UL))
#define SOC_SOCP_ENC_RD_IMG_DBG4_ADDR(base) ((base) + (0x1684UL))
#define SOC_SOCP_ENC_IBUF_STATE_DBG0_ADDR(base) ((base) + (0x1688UL))
#define SOC_SOCP_ENC_IBUF_STATE_DBG1_ADDR(base) ((base) + (0x168CUL))
#define SOC_SOCP_ENC_IBUF_STATE_DBG2_ADDR(base) ((base) + (0x1690UL))
#define SOC_SOCP_HAC_GIF_DBG_ADDR(base) ((base) + (0x1694UL))
#define SOC_SOCP_ENC_IBUF_STATE_CLEAR_ADDR(base) ((base) + (0x17F0UL))
#define SOC_SOCP_VERSION_ADDR(base) ((base) + (0x17FCUL))
#else
#define SOC_SOCP_GLOBAL_CTRL_ADDR(base) ((base) + (0x000))
#define SOC_SOCP_ENC_SRST_CTRL_L_ADDR(base) ((base) + (0x004))
#define SOC_SOCP_ENC_SRST_CTRL_H_ADDR(base) ((base) + (0x008))
#define SOC_SOCP_DEC_SRST_CTRL_ADDR(base) ((base) + (0x00C))
#define SOC_SOCP_ENC_CH_STATUS_L_ADDR(base) ((base) + (0x010))
#define SOC_SOCP_ENC_CH_STATUS_H_ADDR(base) ((base) + (0x014))
#define SOC_SOCP_DEC_CH_STATUS_ADDR(base) ((base) + (0x018))
#define SOC_SOCP_CLK_CTRL_ADDR(base) ((base) + (0x01C))
#define SOC_SOCP_PRIOR_CFG_ADDR(base) ((base) + (0x020))
#define SOC_SOCP_DEC_INT_TIMEOUT_ADDR(base) ((base) + (0x024))
#define SOC_SOCP_INT_TIMEOUT_ADDR(base) ((base) + (0x028))
#define SOC_SOCP_BUFFER_TIMEOUT_ADDR(base) ((base) + (0x02C))
#define SOC_SOCP_DEC_PKT_LEN_CFG_ADDR(base) ((base) + (0x030))
#define SOC_SOCP_ENC_SRCCH_SECCTRL_L_ADDR(base) ((base) + (0x034))
#define SOC_SOCP_ENC_SRCCH_SECCTRL_H_ADDR(base) ((base) + (0x038))
#define SOC_SOCP_ENC_DSTCH_SECCTRL_ADDR(base) ((base) + (0x03C))
#define SOC_SOCP_DEC_SRCCH_SECCTRL_ADDR(base) ((base) + (0x040))
#define SOC_SOCP_DEC_DSTCH_SECCTRL_ADDR(base) ((base) + (0x044))
#define SOC_SOCP_GLB_REG_SECCTRL_ADDR(base) ((base) + (0x048))
#define SOC_SOCP_GLOBAL_INT_STATUS_ADDR(base) ((base) + (0x050))
#define SOC_SOCP_ENC_CORE0_MASK0_ADDR(base) ((base) + (0x054))
#define SOC_SOCP_ENC_CORE1_MASK0_ADDR(base) ((base) + (0x058))
#define SOC_SOCP_ENC_CORE2_MASK0_ADDR(base) ((base) + (0x05C))
#define SOC_SOCP_ENC_RAWINT0_ADDR(base) ((base) + (0x060))
#define SOC_SOCP_ENC_CORE0_INT0_ADDR(base) ((base) + (0x064))
#define SOC_SOCP_ENC_CORE1_INT0_ADDR(base) ((base) + (0x068))
#define SOC_SOCP_ENC_CORE2_INT0_ADDR(base) ((base) + (0x06C))
#define SOC_SOCP_ENC_CORE0_MASK1_L_ADDR(base) ((base) + (0x070))
#define SOC_SOCP_ENC_CORE0_MASK1_H_ADDR(base) ((base) + (0x074))
#define SOC_SOCP_ENC_CORE1_MASK1_L_ADDR(base) ((base) + (0x078))
#define SOC_SOCP_ENC_CORE1_MASK1_H_ADDR(base) ((base) + (0x07C))
#define SOC_SOCP_ENC_CORE2_MASK1_L_ADDR(base) ((base) + (0x080))
#define SOC_SOCP_ENC_CORE2_MASK1_H_ADDR(base) ((base) + (0x084))
#define SOC_SOCP_ENC_RAWINT1_L_ADDR(base) ((base) + (0x088))
#define SOC_SOCP_ENC_RAWINT1_H_ADDR(base) ((base) + (0x08C))
#define SOC_SOCP_ENC_CORE0_INT1_L_ADDR(base) ((base) + (0x090))
#define SOC_SOCP_ENC_CORE0_INT1_H_ADDR(base) ((base) + (0x094))
#define SOC_SOCP_ENC_CORE1_INT1_L_ADDR(base) ((base) + (0x098))
#define SOC_SOCP_ENC_CORE1_INT1_H_ADDR(base) ((base) + (0x09C))
#define SOC_SOCP_ENC_CORE2_INT1_L_ADDR(base) ((base) + (0x0A0))
#define SOC_SOCP_ENC_CORE2_INT1_H_ADDR(base) ((base) + (0x0A4))
#define SOC_SOCP_ENC_CORE0_MASK2_ADDR(base) ((base) + (0x0A8))
#define SOC_SOCP_ENC_CORE1_MASK2_ADDR(base) ((base) + (0x0AC))
#define SOC_SOCP_ENC_CORE2_MASK2_ADDR(base) ((base) + (0x0B0))
#define SOC_SOCP_ENC_RAWINT2_ADDR(base) ((base) + (0x0B4))
#define SOC_SOCP_ENC_CORE0_INT2_ADDR(base) ((base) + (0x0B8))
#define SOC_SOCP_ENC_CORE1_INT2_ADDR(base) ((base) + (0x0BC))
#define SOC_SOCP_ENC_CORE2_INT2_ADDR(base) ((base) + (0x0C0))
#define SOC_SOCP_ENC_CORE0_MASK3_L_ADDR(base) ((base) + (0x0C4))
#define SOC_SOCP_ENC_CORE0_MASK3_H_ADDR(base) ((base) + (0x0C8))
#define SOC_SOCP_ENC_CORE1_MASK3_L_ADDR(base) ((base) + (0x0CC))
#define SOC_SOCP_ENC_CORE1_MASK3_H_ADDR(base) ((base) + (0x0D0))
#define SOC_SOCP_ENC_CORE2_MASK3_L_ADDR(base) ((base) + (0x0D4))
#define SOC_SOCP_ENC_CORE2_MASK3_H_ADDR(base) ((base) + (0x0D8))
#define SOC_SOCP_ENC_RAWINT3_L_ADDR(base) ((base) + (0x0DC))
#define SOC_SOCP_ENC_RAWINT3_H_ADDR(base) ((base) + (0x0E0))
#define SOC_SOCP_ENC_CORE0_INT3_L_ADDR(base) ((base) + (0x0E4))
#define SOC_SOCP_ENC_CORE0_INT3_H_ADDR(base) ((base) + (0x0E8))
#define SOC_SOCP_ENC_CORE1_INT3_L_ADDR(base) ((base) + (0x0EC))
#define SOC_SOCP_ENC_CORE1_INT3_H_ADDR(base) ((base) + (0x0F0))
#define SOC_SOCP_ENC_CORE2_INT3_L_ADDR(base) ((base) + (0x0F4))
#define SOC_SOCP_ENC_CORE2_INT3_H_ADDR(base) ((base) + (0x0F8))
#define SOC_SOCP_DEC_CORE0_MASK0_ADDR(base) ((base) + (0x0FC))
#define SOC_SOCP_DEC_CORE1_MASK0_ADDR(base) ((base) + (0x100))
#define SOC_SOCP_DEC_CORE2_MASK0_ADDR(base) ((base) + (0x104))
#define SOC_SOCP_DEC_RAWINT0_ADDR(base) ((base) + (0x108))
#define SOC_SOCP_DEC_CORE0_INT0_ADDR(base) ((base) + (0x10C))
#define SOC_SOCP_DEC_CORE1_INT0_ADDR(base) ((base) + (0x110))
#define SOC_SOCP_DEC_CORE2_INT0_ADDR(base) ((base) + (0x114))
#define SOC_SOCP_DEC_CORE0_MASK1_ADDR(base) ((base) + (0x118))
#define SOC_SOCP_DEC_CORE1_MASK1_ADDR(base) ((base) + (0x11C))
#define SOC_SOCP_DEC_CORE2_MASK1_ADDR(base) ((base) + (0x120))
#define SOC_SOCP_DEC_RAWINT1_ADDR(base) ((base) + (0x124))
#define SOC_SOCP_DEC_CORE0_INT1_ADDR(base) ((base) + (0x128))
#define SOC_SOCP_DEC_CORE1_INT1_ADDR(base) ((base) + (0x12C))
#define SOC_SOCP_DEC_CORE2_INT1_ADDR(base) ((base) + (0x130))
#define SOC_SOCP_DEC_CORE0_MASK2_ADDR(base) ((base) + (0x134))
#define SOC_SOCP_DEC_CORE1_MASK2_ADDR(base) ((base) + (0x138))
#define SOC_SOCP_DEC_CORE2_MASK2_ADDR(base) ((base) + (0x13C))
#define SOC_SOCP_DEC_RAWINT2_ADDR(base) ((base) + (0x140))
#define SOC_SOCP_DEC_CORE0_INT2_ADDR(base) ((base) + (0x144))
#define SOC_SOCP_DEC_CORE1_INT2_ADDR(base) ((base) + (0x148))
#define SOC_SOCP_DEC_CORE2_INT2_ADDR(base) ((base) + (0x14C))
#define SOC_SOCP_BUS_ERROR_MASK_ADDR(base) ((base) + (0x150))
#define SOC_SOCP_BUS_ERROR_RAWINT_ADDR(base) ((base) + (0x154))
#define SOC_SOCP_BUS_ERROR_INT_ADDR(base) ((base) + (0x158))
#define SOC_SOCP_ENC_SRC_RATE_PERIOD_ADDR(base) ((base) + (0x180))
#define SOC_SOCP_ENC_SRC_RATE_EN_L_ADDR(base) ((base) + (0x184))
#define SOC_SOCP_ENC_SRC_RATE_EN_H_ADDR(base) ((base) + (0x188))
#define SOC_SOCP_ENC_SRC_PTR_IMG_CFG_ADDR(base) ((base) + (0x18C))
#define SOC_SOCP_ENC_SRC_RATE_THR_ADDR(base,m) ((base) + (0x190+0x4*(m)))
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_L_ADDR(base) ((base) + (0x290))
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_H_ADDR(base) ((base) + (0x294))
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_L_ADDR(base) ((base) + (0x298))
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_H_ADDR(base) ((base) + (0x29C))
#define SOC_SOCP_ENC_SRC_PTR_CORE0_MASK_ADDR(base) ((base) + (0x2A0))
#define SOC_SOCP_ENC_SRC_PTR_CORE1_MASK_ADDR(base) ((base) + (0x2A4))
#define SOC_SOCP_ENC_SRC_PTR_CORE2_MASK_ADDR(base) ((base) + (0x2A8))
#define SOC_SOCP_ENC_SRC_PTR_RAWINT_ADDR(base) ((base) + (0x2AC))
#define SOC_SOCP_ENC_SRC_PTR_CORE0_INT_ADDR(base) ((base) + (0x2B0))
#define SOC_SOCP_ENC_SRC_PTR_CORE1_INT_ADDR(base) ((base) + (0x2B4))
#define SOC_SOCP_ENC_SRC_PTR_CORE2_INT_ADDR(base) ((base) + (0x2B8))
#define SOC_SOCP_ENC_SRC_BUFM_WPTR_ADDR(base,m) ((base) + (0x300+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_ADDR(base,m) ((base) + (0x304+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_L_ADDR(base,m) ((base) + (0x308+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_H_ADDR(base,m) ((base) + (0x30C+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_DEPTH_ADDR(base,m) ((base) + (0x310+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_CFG_ADDR(base,m) ((base) + (0x314+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_ADDR(base,m) ((base) + (0x318+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_RPTR_ADDR(base,m) ((base) + (0x31C+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_L_ADDR(base,m) ((base) + (0x320+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_H_ADDR(base,m) ((base) + (0x324+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_CFG_ADDR(base,m) ((base) + (0x328+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_L_ADDR(base,m) ((base) + (0x32C+0x40*(m)))
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_H_ADDR(base,m) ((base) + (0x330+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_L_ADDR(base,m) ((base) + (0x334+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_H_ADDR(base,m) ((base) + (0x338+0x40*(m)))
#define SOC_SOCP_ENC_SRC_RATE_CNT_CTRL_ADDR(base,m) ((base) + (0x33C+0x40*(m)))
#define SOC_SOCP_ENC_DEST_BUFN_WPTR_ADDR(base,n) ((base) + (0x1300+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_RPTR_ADDR(base,n) ((base) + (0x1304+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_L_ADDR(base,n) ((base) + (0x1308+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_H_ADDR(base,n) ((base) + (0x130C+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_DEPTH_ADDR(base,n) ((base) + (0x1310+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUFN_THRH_ADDR(base,n) ((base) + (0x1314+0x40*(n)))
#define SOC_SOCP_ENC_INT_THRESHOLD_ADDR(base,n) ((base) + (0x1318+0x40*(n)))
#define SOC_SOCP_ENC_DEST_BUF_MODE_ADDR(base,n) ((base) + (0x131C+0x40*(n)))
#define SOC_SOCP_ENC_DEST_TRANSID_ADDR(base,n) ((base) + (0x1320+0x40*(n)))
#define SOC_SOCP_DEC_SRC_BUFX_WPTR_ADDR(base,j) ((base) + (0x1400+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_RPTR_ADDR(base,j) ((base) + (0x1404+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_L_ADDR(base,j) ((base) + (0x1408+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_H_ADDR(base,j) ((base) + (0x140C+0x40*(j)))
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_ADDR(base,j) ((base) + (0x1410+0x40*(j)))
#define SOC_SOCP_DEC_BUFX_STATUS0_ADDR(base,j) ((base) + (0x1414+0x40*(j)))
#define SOC_SOCP_DEC_BUFX_STATUS1_ADDR(base,j) ((base) + (0x1418+0x40*(j)))
#define SOC_SOCP_DEC_DEST_BUFY_WPTR_ADDR(base,y) ((base) + (0x1500+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_RPTR_ADDR(base,y) ((base) + (0x1504+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_L_ADDR(base,y) ((base) + (0x1508+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_H_ADDR(base,y) ((base) + (0x150C+0x40*(y)))
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_ADDR(base,y) ((base) + (0x1510+0x40*(y)))
#define SOC_SOCP_ENC_CD_DBG0_ADDR(base) ((base) + (0x1600))
#define SOC_SOCP_ENC_CD_DBG1_ADDR(base) ((base) + (0x1604))
#define SOC_SOCP_ENC_IBUF_DBG0_ADDR(base) ((base) + (0x1608))
#define SOC_SOCP_ENC_IBUF_DBG1_ADDR(base) ((base) + (0x160C))
#define SOC_SOCP_ENC_IBUF_DBG2_ADDR(base) ((base) + (0x1610))
#define SOC_SOCP_ENC_IBUF_DBG3_ADDR(base) ((base) + (0x1614))
#define SOC_SOCP_ENC_OBUF_DBG0_ADDR(base) ((base) + (0x1618))
#define SOC_SOCP_ENC_OBUF_DBG1_ADDR(base) ((base) + (0x161C))
#define SOC_SOCP_ENC_OBUF_DBG2_ADDR(base) ((base) + (0x1620))
#define SOC_SOCP_ENC_OBUF_DBG3_ADDR(base) ((base) + (0x1624))
#define SOC_SOCP_DEC_IBUF_DBG0_ADDR(base) ((base) + (0x1628))
#define SOC_SOCP_DEC_IBUF_DBG1_ADDR(base) ((base) + (0x162C))
#define SOC_SOCP_DEC_IBUF_DBG2_ADDR(base) ((base) + (0x1630))
#define SOC_SOCP_DEC_IBUF_DBG3_ADDR(base) ((base) + (0x1634))
#define SOC_SOCP_DEC_OBUF_DBG0_ADDR(base) ((base) + (0x1638))
#define SOC_SOCP_DEC_OBUF_DBG1_ADDR(base) ((base) + (0x163C))
#define SOC_SOCP_DEC_OBUF_DBG2_ADDR(base) ((base) + (0x1640))
#define SOC_SOCP_DEC_OBUF_DBG3_ADDR(base) ((base) + (0x1644))
#define SOC_SOCP_ENC_PTR_DBG0_ADDR(base) ((base) + (0x1648))
#define SOC_SOCP_ENC_PTR_DBG1_ADDR(base) ((base) + (0x164C))
#define SOC_SOCP_ENC_PTR_DBG2_ADDR(base) ((base) + (0x1650))
#define SOC_SOCP_ENC_PTR_DBG3_ADDR(base) ((base) + (0x1654))
#define SOC_SOCP_ENC_CH_TRH_DBG0_ADDR(base) ((base) + (0x1658))
#define SOC_SOCP_ENC_CH_TRH_DBG1_ADDR(base) ((base) + (0x165C))
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ADDR(base) ((base) + (0x1660))
#define SOC_SOCP_ENC_PTR_IMG_DBG1_ADDR(base) ((base) + (0x1664))
#define SOC_SOCP_ENC_PTR_IMG_DBG2_ADDR(base) ((base) + (0x1668))
#define SOC_SOCP_ENC_PTR_IMG_DBG3_ADDR(base) ((base) + (0x166C))
#define SOC_SOCP_ENC_PTR_IMG_DBG4_ADDR(base) ((base) + (0x1670))
#define SOC_SOCP_ENC_RD_IMG_DBG0_ADDR(base) ((base) + (0x1674))
#define SOC_SOCP_ENC_RD_IMG_DBG1_ADDR(base) ((base) + (0x1678))
#define SOC_SOCP_ENC_RD_IMG_DBG2_ADDR(base) ((base) + (0x167C))
#define SOC_SOCP_ENC_RD_IMG_DBG3_ADDR(base) ((base) + (0x1680))
#define SOC_SOCP_ENC_RD_IMG_DBG4_ADDR(base) ((base) + (0x1684))
#define SOC_SOCP_ENC_IBUF_STATE_DBG0_ADDR(base) ((base) + (0x1688))
#define SOC_SOCP_ENC_IBUF_STATE_DBG1_ADDR(base) ((base) + (0x168C))
#define SOC_SOCP_ENC_IBUF_STATE_DBG2_ADDR(base) ((base) + (0x1690))
#define SOC_SOCP_HAC_GIF_DBG_ADDR(base) ((base) + (0x1694))
#define SOC_SOCP_ENC_IBUF_STATE_CLEAR_ADDR(base) ((base) + (0x17F0))
#define SOC_SOCP_VERSION_ADDR(base) ((base) + (0x17FC))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int global_srst : 1;
        unsigned int int_timeout_cfg_sel : 1;
        unsigned int reserved_0 : 2;
        unsigned int timeout_test_sel_enc : 1;
        unsigned int reserved_1 : 11;
        unsigned int ch_halt : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_SOCP_GLOBAL_CTRL_UNION;
#endif
#define SOC_SOCP_GLOBAL_CTRL_global_srst_START (0)
#define SOC_SOCP_GLOBAL_CTRL_global_srst_END (0)
#define SOC_SOCP_GLOBAL_CTRL_int_timeout_cfg_sel_START (1)
#define SOC_SOCP_GLOBAL_CTRL_int_timeout_cfg_sel_END (1)
#define SOC_SOCP_GLOBAL_CTRL_timeout_test_sel_enc_START (4)
#define SOC_SOCP_GLOBAL_CTRL_timeout_test_sel_enc_END (4)
#define SOC_SOCP_GLOBAL_CTRL_ch_halt_START (16)
#define SOC_SOCP_GLOBAL_CTRL_ch_halt_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_chm_srst_l : 32;
    } reg;
} SOC_SOCP_ENC_SRST_CTRL_L_UNION;
#endif
#define SOC_SOCP_ENC_SRST_CTRL_L_enc_chm_srst_l_START (0)
#define SOC_SOCP_ENC_SRST_CTRL_L_enc_chm_srst_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_chm_srst_h : 32;
    } reg;
} SOC_SOCP_ENC_SRST_CTRL_H_UNION;
#endif
#define SOC_SOCP_ENC_SRST_CTRL_H_enc_chm_srst_h_START (0)
#define SOC_SOCP_ENC_SRST_CTRL_H_enc_chm_srst_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_chx_srst : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SOCP_DEC_SRST_CTRL_UNION;
#endif
#define SOC_SOCP_DEC_SRST_CTRL_dec_chx_srst_START (0)
#define SOC_SOCP_DEC_SRST_CTRL_dec_chx_srst_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_chm_busy_l : 32;
    } reg;
} SOC_SOCP_ENC_CH_STATUS_L_UNION;
#endif
#define SOC_SOCP_ENC_CH_STATUS_L_enc_chm_busy_l_START (0)
#define SOC_SOCP_ENC_CH_STATUS_L_enc_chm_busy_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_chm_busy_h : 32;
    } reg;
} SOC_SOCP_ENC_CH_STATUS_H_UNION;
#endif
#define SOC_SOCP_ENC_CH_STATUS_H_enc_chm_busy_h_START (0)
#define SOC_SOCP_ENC_CH_STATUS_H_enc_chm_busy_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_chx_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SOCP_DEC_CH_STATUS_UNION;
#endif
#define SOC_SOCP_DEC_CH_STATUS_dec_chx_busy_START (0)
#define SOC_SOCP_DEC_CH_STATUS_dec_chx_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_gclk_en : 1;
        unsigned int dec_gclk_en : 1;
        unsigned int reg_clk_en : 1;
        unsigned int gm_gclk_en : 1;
        unsigned int ram_gclk_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SOCP_CLK_CTRL_UNION;
#endif
#define SOC_SOCP_CLK_CTRL_enc_gclk_en_START (0)
#define SOC_SOCP_CLK_CTRL_enc_gclk_en_END (0)
#define SOC_SOCP_CLK_CTRL_dec_gclk_en_START (1)
#define SOC_SOCP_CLK_CTRL_dec_gclk_en_END (1)
#define SOC_SOCP_CLK_CTRL_reg_clk_en_START (2)
#define SOC_SOCP_CLK_CTRL_reg_clk_en_END (2)
#define SOC_SOCP_CLK_CTRL_gm_gclk_en_START (3)
#define SOC_SOCP_CLK_CTRL_gm_gclk_en_END (3)
#define SOC_SOCP_CLK_CTRL_ram_gclk_en_START (4)
#define SOC_SOCP_CLK_CTRL_ram_gclk_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_prior_cfg : 1;
        unsigned int dec_prior_cfg : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_PRIOR_CFG_UNION;
#endif
#define SOC_SOCP_PRIOR_CFG_enc_prior_cfg_START (0)
#define SOC_SOCP_PRIOR_CFG_enc_prior_cfg_END (0)
#define SOC_SOCP_PRIOR_CFG_dec_prior_cfg_START (1)
#define SOC_SOCP_PRIOR_CFG_dec_prior_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_int_timeout_cfg : 32;
    } reg;
} SOC_SOCP_DEC_INT_TIMEOUT_UNION;
#endif
#define SOC_SOCP_DEC_INT_TIMEOUT_dec_int_timeout_cfg_START (0)
#define SOC_SOCP_DEC_INT_TIMEOUT_dec_int_timeout_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_timeout0_cfg : 32;
    } reg;
} SOC_SOCP_INT_TIMEOUT_UNION;
#endif
#define SOC_SOCP_INT_TIMEOUT_int_timeout0_cfg_START (0)
#define SOC_SOCP_INT_TIMEOUT_int_timeout0_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buffer_timeout_cfg : 16;
        unsigned int reserved : 15;
        unsigned int buffer_timeout_en : 1;
    } reg;
} SOC_SOCP_BUFFER_TIMEOUT_UNION;
#endif
#define SOC_SOCP_BUFFER_TIMEOUT_buffer_timeout_cfg_START (0)
#define SOC_SOCP_BUFFER_TIMEOUT_buffer_timeout_cfg_END (15)
#define SOC_SOCP_BUFFER_TIMEOUT_buffer_timeout_en_START (31)
#define SOC_SOCP_BUFFER_TIMEOUT_buffer_timeout_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_max_pkt_len : 12;
        unsigned int dec_min_pkt_len : 5;
        unsigned int reserved : 15;
    } reg;
} SOC_SOCP_DEC_PKT_LEN_CFG_UNION;
#endif
#define SOC_SOCP_DEC_PKT_LEN_CFG_dec_max_pkt_len_START (0)
#define SOC_SOCP_DEC_PKT_LEN_CFG_dec_max_pkt_len_END (11)
#define SOC_SOCP_DEC_PKT_LEN_CFG_dec_min_pkt_len_START (12)
#define SOC_SOCP_DEC_PKT_LEN_CFG_dec_min_pkt_len_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_srcch_secctrl_l : 32;
    } reg;
} SOC_SOCP_ENC_SRCCH_SECCTRL_L_UNION;
#endif
#define SOC_SOCP_ENC_SRCCH_SECCTRL_L_enc_srcch_secctrl_l_START (0)
#define SOC_SOCP_ENC_SRCCH_SECCTRL_L_enc_srcch_secctrl_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_srcch_secctrl_h : 32;
    } reg;
} SOC_SOCP_ENC_SRCCH_SECCTRL_H_UNION;
#endif
#define SOC_SOCP_ENC_SRCCH_SECCTRL_H_enc_srcch_secctrl_h_START (0)
#define SOC_SOCP_ENC_SRCCH_SECCTRL_H_enc_srcch_secctrl_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dstch_secctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_ENC_DSTCH_SECCTRL_UNION;
#endif
#define SOC_SOCP_ENC_DSTCH_SECCTRL_enc_dstch_secctrl_START (0)
#define SOC_SOCP_ENC_DSTCH_SECCTRL_enc_dstch_secctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_srcch_secctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SOCP_DEC_SRCCH_SECCTRL_UNION;
#endif
#define SOC_SOCP_DEC_SRCCH_SECCTRL_dec_srcch_secctrl_START (0)
#define SOC_SOCP_DEC_SRCCH_SECCTRL_dec_srcch_secctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_dstch_secctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_DSTCH_SECCTRL_UNION;
#endif
#define SOC_SOCP_DEC_DSTCH_SECCTRL_dec_dstch_secctrl_START (0)
#define SOC_SOCP_DEC_DSTCH_SECCTRL_dec_dstch_secctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int glb_reg_secctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SOCP_GLB_REG_SECCTRL_UNION;
#endif
#define SOC_SOCP_GLB_REG_SECCTRL_glb_reg_secctrl_START (0)
#define SOC_SOCP_GLB_REG_SECCTRL_glb_reg_secctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_dec_tfr_int : 1;
        unsigned int core1_dec_tfr_int : 1;
        unsigned int core2_dec_tfr_int : 1;
        unsigned int core0_dec_err_int : 1;
        unsigned int core1_dec_err_int : 1;
        unsigned int core2_dec_err_int : 1;
        unsigned int core0_dec_obuf_ovf_int : 1;
        unsigned int core1_dec_obuf_ovf_int : 1;
        unsigned int core2_dec_obuf_ovf_int : 1;
        unsigned int core0_enc_tfr_int : 1;
        unsigned int core1_enc_tfr_int : 1;
        unsigned int core2_enc_tfr_int : 1;
        unsigned int core0_enc_mode_switch_int : 1;
        unsigned int core1_enc_mode_switch_int : 1;
        unsigned int core2_enc_mode_switch_int : 1;
        unsigned int core0_enc_flag_err_int : 1;
        unsigned int core1_enc_flag_err_int : 1;
        unsigned int core2_enc_flag_err_int : 1;
        unsigned int core0_enc_obuf_ovf_int : 1;
        unsigned int core1_enc_obuf_ovf_int : 1;
        unsigned int core2_enc_obuf_ovf_int : 1;
        unsigned int core0_enc_rdq_int : 1;
        unsigned int core1_enc_rdq_int : 1;
        unsigned int core2_enc_rdq_int : 1;
        unsigned int core0_enc_rptr_tout_int : 1;
        unsigned int core1_enc_rptr_tout_int : 1;
        unsigned int core2_enc_rptr_tout_int : 1;
        unsigned int core0_enc_rd_tout_int : 1;
        unsigned int core1_enc_rd_tout_int : 1;
        unsigned int core2_enc_rd_tout_int : 1;
        unsigned int bus_err_int : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_SOCP_GLOBAL_INT_STATUS_UNION;
#endif
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_dec_tfr_int_START (0)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_dec_tfr_int_END (0)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_dec_tfr_int_START (1)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_dec_tfr_int_END (1)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_dec_tfr_int_START (2)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_dec_tfr_int_END (2)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_dec_err_int_START (3)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_dec_err_int_END (3)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_dec_err_int_START (4)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_dec_err_int_END (4)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_dec_err_int_START (5)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_dec_err_int_END (5)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_dec_obuf_ovf_int_START (6)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_dec_obuf_ovf_int_END (6)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_dec_obuf_ovf_int_START (7)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_dec_obuf_ovf_int_END (7)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_dec_obuf_ovf_int_START (8)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_dec_obuf_ovf_int_END (8)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_tfr_int_START (9)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_tfr_int_END (9)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_tfr_int_START (10)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_tfr_int_END (10)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_tfr_int_START (11)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_tfr_int_END (11)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_mode_switch_int_START (12)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_mode_switch_int_END (12)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_mode_switch_int_START (13)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_mode_switch_int_END (13)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_mode_switch_int_START (14)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_mode_switch_int_END (14)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_flag_err_int_START (15)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_flag_err_int_END (15)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_flag_err_int_START (16)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_flag_err_int_END (16)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_flag_err_int_START (17)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_flag_err_int_END (17)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_obuf_ovf_int_START (18)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_obuf_ovf_int_END (18)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_obuf_ovf_int_START (19)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_obuf_ovf_int_END (19)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_obuf_ovf_int_START (20)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_obuf_ovf_int_END (20)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_rdq_int_START (21)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_rdq_int_END (21)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_rdq_int_START (22)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_rdq_int_END (22)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_rdq_int_START (23)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_rdq_int_END (23)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_rptr_tout_int_START (24)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_rptr_tout_int_END (24)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_rptr_tout_int_START (25)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_rptr_tout_int_END (25)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_rptr_tout_int_START (26)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_rptr_tout_int_END (26)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_rd_tout_int_START (27)
#define SOC_SOCP_GLOBAL_INT_STATUS_core0_enc_rd_tout_int_END (27)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_rd_tout_int_START (28)
#define SOC_SOCP_GLOBAL_INT_STATUS_core1_enc_rd_tout_int_END (28)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_rd_tout_int_START (29)
#define SOC_SOCP_GLOBAL_INT_STATUS_core2_enc_rd_tout_int_END (29)
#define SOC_SOCP_GLOBAL_INT_STATUS_bus_err_int_START (30)
#define SOC_SOCP_GLOBAL_INT_STATUS_bus_err_int_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_tfr_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int core0_mode_switch_mask : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE0_MASK0_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_MASK0_core0_enc_tfr_mask_START (0)
#define SOC_SOCP_ENC_CORE0_MASK0_core0_enc_tfr_mask_END (3)
#define SOC_SOCP_ENC_CORE0_MASK0_core0_mode_switch_mask_START (16)
#define SOC_SOCP_ENC_CORE0_MASK0_core0_mode_switch_mask_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_tfr_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int core1_mode_switch_mask : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE1_MASK0_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_MASK0_core1_enc_tfr_mask_START (0)
#define SOC_SOCP_ENC_CORE1_MASK0_core1_enc_tfr_mask_END (3)
#define SOC_SOCP_ENC_CORE1_MASK0_core1_mode_switch_mask_START (16)
#define SOC_SOCP_ENC_CORE1_MASK0_core1_mode_switch_mask_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_tfr_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int core2_mode_switch_mask : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE2_MASK0_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_MASK0_core2_enc_tfr_mask_START (0)
#define SOC_SOCP_ENC_CORE2_MASK0_core2_enc_tfr_mask_END (3)
#define SOC_SOCP_ENC_CORE2_MASK0_core2_mode_switch_mask_START (16)
#define SOC_SOCP_ENC_CORE2_MASK0_core2_mode_switch_mask_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_tfr_rawint : 4;
        unsigned int reserved_0 : 12;
        unsigned int mode_switch_rawint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_RAWINT0_UNION;
#endif
#define SOC_SOCP_ENC_RAWINT0_enc_tfr_rawint_START (0)
#define SOC_SOCP_ENC_RAWINT0_enc_tfr_rawint_END (3)
#define SOC_SOCP_ENC_RAWINT0_mode_switch_rawint_START (16)
#define SOC_SOCP_ENC_RAWINT0_mode_switch_rawint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_tfr_maskint : 4;
        unsigned int reserved_0 : 12;
        unsigned int core0_mode_switch_maskint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE0_INT0_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_INT0_core0_enc_tfr_maskint_START (0)
#define SOC_SOCP_ENC_CORE0_INT0_core0_enc_tfr_maskint_END (3)
#define SOC_SOCP_ENC_CORE0_INT0_core0_mode_switch_maskint_START (16)
#define SOC_SOCP_ENC_CORE0_INT0_core0_mode_switch_maskint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_tfr_maskint : 4;
        unsigned int reserved_0 : 12;
        unsigned int core1_mode_switch_maskint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE1_INT0_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_INT0_core1_enc_tfr_maskint_START (0)
#define SOC_SOCP_ENC_CORE1_INT0_core1_enc_tfr_maskint_END (3)
#define SOC_SOCP_ENC_CORE1_INT0_core1_mode_switch_maskint_START (16)
#define SOC_SOCP_ENC_CORE1_INT0_core1_mode_switch_maskint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_tfr_maskint : 4;
        unsigned int reserved_0 : 12;
        unsigned int core2_mode_switch_maskint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE2_INT0_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_INT0_core2_enc_tfr_maskint_START (0)
#define SOC_SOCP_ENC_CORE2_INT0_core2_enc_tfr_maskint_END (3)
#define SOC_SOCP_ENC_CORE2_INT0_core2_mode_switch_maskint_START (16)
#define SOC_SOCP_ENC_CORE2_INT0_core2_mode_switch_maskint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_flag_err_maskint_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_MASK1_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_MASK1_L_core0_enc_flag_err_maskint_l_START (0)
#define SOC_SOCP_ENC_CORE0_MASK1_L_core0_enc_flag_err_maskint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_flag_err_maskint_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_MASK1_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_MASK1_H_core0_enc_flag_err_maskint_h_START (0)
#define SOC_SOCP_ENC_CORE0_MASK1_H_core0_enc_flag_err_maskint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_flag_err_maskint_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_MASK1_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_MASK1_L_core1_enc_flag_err_maskint_l_START (0)
#define SOC_SOCP_ENC_CORE1_MASK1_L_core1_enc_flag_err_maskint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_flag_err_maskint_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_MASK1_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_MASK1_H_core1_enc_flag_err_maskint_h_START (0)
#define SOC_SOCP_ENC_CORE1_MASK1_H_core1_enc_flag_err_maskint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_flag_err_maskint_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_MASK1_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_MASK1_L_core2_enc_flag_err_maskint_l_START (0)
#define SOC_SOCP_ENC_CORE2_MASK1_L_core2_enc_flag_err_maskint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_flag_err_maskint_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_MASK1_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_MASK1_H_core2_enc_flag_err_maskint_h_START (0)
#define SOC_SOCP_ENC_CORE2_MASK1_H_core2_enc_flag_err_maskint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_flag_err_rawint_l : 32;
    } reg;
} SOC_SOCP_ENC_RAWINT1_L_UNION;
#endif
#define SOC_SOCP_ENC_RAWINT1_L_enc_flag_err_rawint_l_START (0)
#define SOC_SOCP_ENC_RAWINT1_L_enc_flag_err_rawint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_flag_err_rawint_h : 32;
    } reg;
} SOC_SOCP_ENC_RAWINT1_H_UNION;
#endif
#define SOC_SOCP_ENC_RAWINT1_H_enc_flag_err_rawint_h_START (0)
#define SOC_SOCP_ENC_RAWINT1_H_enc_flag_err_rawint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_flag_err_maskint_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_INT1_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_INT1_L_core0_enc_flag_err_maskint_l_START (0)
#define SOC_SOCP_ENC_CORE0_INT1_L_core0_enc_flag_err_maskint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_flag_err_maskint_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_INT1_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_INT1_H_core0_enc_flag_err_maskint_h_START (0)
#define SOC_SOCP_ENC_CORE0_INT1_H_core0_enc_flag_err_maskint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_flag_err_maskint_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_INT1_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_INT1_L_core1_enc_flag_err_maskint_l_START (0)
#define SOC_SOCP_ENC_CORE1_INT1_L_core1_enc_flag_err_maskint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_flag_err_maskint_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_INT1_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_INT1_H_core1_enc_flag_err_maskint_h_START (0)
#define SOC_SOCP_ENC_CORE1_INT1_H_core1_enc_flag_err_maskint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_flag_err_maskint_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_INT1_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_INT1_L_core2_enc_flag_err_maskint_l_START (0)
#define SOC_SOCP_ENC_CORE2_INT1_L_core2_enc_flag_err_maskint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_flag_err_maskint_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_INT1_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_INT1_H_core2_enc_flag_err_maskint_h_START (0)
#define SOC_SOCP_ENC_CORE2_INT1_H_core2_enc_flag_err_maskint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_obuf_ovf_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int core0_enc_obuf_thrh_ovf_mask : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE0_MASK2_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_MASK2_core0_enc_obuf_ovf_mask_START (0)
#define SOC_SOCP_ENC_CORE0_MASK2_core0_enc_obuf_ovf_mask_END (3)
#define SOC_SOCP_ENC_CORE0_MASK2_core0_enc_obuf_thrh_ovf_mask_START (16)
#define SOC_SOCP_ENC_CORE0_MASK2_core0_enc_obuf_thrh_ovf_mask_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_obuf_ovf_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int core1_enc_obuf_thrh_ovf_mask : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE1_MASK2_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_MASK2_core1_enc_obuf_ovf_mask_START (0)
#define SOC_SOCP_ENC_CORE1_MASK2_core1_enc_obuf_ovf_mask_END (3)
#define SOC_SOCP_ENC_CORE1_MASK2_core1_enc_obuf_thrh_ovf_mask_START (16)
#define SOC_SOCP_ENC_CORE1_MASK2_core1_enc_obuf_thrh_ovf_mask_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_obuf_ovf_mask : 4;
        unsigned int reserved_0 : 12;
        unsigned int core2_enc_obuf_thrh_ovf_mask : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE2_MASK2_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_MASK2_core2_enc_obuf_ovf_mask_START (0)
#define SOC_SOCP_ENC_CORE2_MASK2_core2_enc_obuf_ovf_mask_END (3)
#define SOC_SOCP_ENC_CORE2_MASK2_core2_enc_obuf_thrh_ovf_mask_START (16)
#define SOC_SOCP_ENC_CORE2_MASK2_core2_enc_obuf_thrh_ovf_mask_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_obuf_ovf_rawint : 4;
        unsigned int reserved_0 : 12;
        unsigned int enc_obuf_thrh_ovf_rawint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_RAWINT2_UNION;
#endif
#define SOC_SOCP_ENC_RAWINT2_enc_obuf_ovf_rawint_START (0)
#define SOC_SOCP_ENC_RAWINT2_enc_obuf_ovf_rawint_END (3)
#define SOC_SOCP_ENC_RAWINT2_enc_obuf_thrh_ovf_rawint_START (16)
#define SOC_SOCP_ENC_RAWINT2_enc_obuf_thrh_ovf_rawint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_obuf_ovf_maskint : 4;
        unsigned int reserved_0 : 12;
        unsigned int core0_enc_obuf_thrh_ovf_maskint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE0_INT2_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_INT2_core0_enc_obuf_ovf_maskint_START (0)
#define SOC_SOCP_ENC_CORE0_INT2_core0_enc_obuf_ovf_maskint_END (3)
#define SOC_SOCP_ENC_CORE0_INT2_core0_enc_obuf_thrh_ovf_maskint_START (16)
#define SOC_SOCP_ENC_CORE0_INT2_core0_enc_obuf_thrh_ovf_maskint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_obuf_ovf_maskint : 4;
        unsigned int reserved_0 : 12;
        unsigned int core1_enc_obuf_thrh_ovf_maskint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE1_INT2_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_INT2_core1_enc_obuf_ovf_maskint_START (0)
#define SOC_SOCP_ENC_CORE1_INT2_core1_enc_obuf_ovf_maskint_END (3)
#define SOC_SOCP_ENC_CORE1_INT2_core1_enc_obuf_thrh_ovf_maskint_START (16)
#define SOC_SOCP_ENC_CORE1_INT2_core1_enc_obuf_thrh_ovf_maskint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_obuf_ovf_maskint : 4;
        unsigned int reserved_0 : 12;
        unsigned int core2_enc_obuf_thrh_ovf_maskint : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_ENC_CORE2_INT2_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_INT2_core2_enc_obuf_ovf_maskint_START (0)
#define SOC_SOCP_ENC_CORE2_INT2_core2_enc_obuf_ovf_maskint_END (3)
#define SOC_SOCP_ENC_CORE2_INT2_core2_enc_obuf_thrh_ovf_maskint_START (16)
#define SOC_SOCP_ENC_CORE2_INT2_core2_enc_obuf_thrh_ovf_maskint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_rdq_done_mask_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_MASK3_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_MASK3_L_core0_enc_rdq_done_mask_l_START (0)
#define SOC_SOCP_ENC_CORE0_MASK3_L_core0_enc_rdq_done_mask_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_rdq_done_mask_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_MASK3_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_MASK3_H_core0_enc_rdq_done_mask_h_START (0)
#define SOC_SOCP_ENC_CORE0_MASK3_H_core0_enc_rdq_done_mask_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_rdq_done_mask_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_MASK3_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_MASK3_L_core1_enc_rdq_done_mask_l_START (0)
#define SOC_SOCP_ENC_CORE1_MASK3_L_core1_enc_rdq_done_mask_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_rdq_done_mask_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_MASK3_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_MASK3_H_core1_enc_rdq_done_mask_h_START (0)
#define SOC_SOCP_ENC_CORE1_MASK3_H_core1_enc_rdq_done_mask_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_rdq_done_mask_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_MASK3_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_MASK3_L_core2_enc_rdq_done_mask_l_START (0)
#define SOC_SOCP_ENC_CORE2_MASK3_L_core2_enc_rdq_done_mask_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_rdq_done_mask_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_MASK3_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_MASK3_H_core2_enc_rdq_done_mask_h_START (0)
#define SOC_SOCP_ENC_CORE2_MASK3_H_core2_enc_rdq_done_mask_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_rdq_done_rawint_l : 32;
    } reg;
} SOC_SOCP_ENC_RAWINT3_L_UNION;
#endif
#define SOC_SOCP_ENC_RAWINT3_L_enc_rdq_done_rawint_l_START (0)
#define SOC_SOCP_ENC_RAWINT3_L_enc_rdq_done_rawint_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_rdq_done_rawint_h : 32;
    } reg;
} SOC_SOCP_ENC_RAWINT3_H_UNION;
#endif
#define SOC_SOCP_ENC_RAWINT3_H_enc_rdq_done_rawint_h_START (0)
#define SOC_SOCP_ENC_RAWINT3_H_enc_rdq_done_rawint_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_rdq_done_int_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_INT3_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_INT3_L_core0_enc_rdq_done_int_l_START (0)
#define SOC_SOCP_ENC_CORE0_INT3_L_core0_enc_rdq_done_int_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_enc_rdq_done_int_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE0_INT3_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE0_INT3_H_core0_enc_rdq_done_int_h_START (0)
#define SOC_SOCP_ENC_CORE0_INT3_H_core0_enc_rdq_done_int_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_rdq_done_int_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_INT3_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_INT3_L_core1_enc_rdq_done_int_l_START (0)
#define SOC_SOCP_ENC_CORE1_INT3_L_core1_enc_rdq_done_int_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_enc_rdq_done_int_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE1_INT3_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE1_INT3_H_core1_enc_rdq_done_int_h_START (0)
#define SOC_SOCP_ENC_CORE1_INT3_H_core1_enc_rdq_done_int_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_rdq_done_int_l : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_INT3_L_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_INT3_L_core2_enc_rdq_done_int_l_START (0)
#define SOC_SOCP_ENC_CORE2_INT3_L_core2_enc_rdq_done_int_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_enc_rdq_done_int_h : 32;
    } reg;
} SOC_SOCP_ENC_CORE2_INT3_H_UNION;
#endif
#define SOC_SOCP_ENC_CORE2_INT3_H_core2_enc_rdq_done_int_h_START (0)
#define SOC_SOCP_ENC_CORE2_INT3_H_core2_enc_rdq_done_int_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_dtype0_tfr_int_mask0 : 1;
        unsigned int core0_dtype1_tfr_int_mask1 : 1;
        unsigned int core0_dtype2_tfr_int_mask2 : 1;
        unsigned int core0_dtype3_tfr_int_mask3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE0_MASK0_UNION;
#endif
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype0_tfr_int_mask0_START (0)
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype0_tfr_int_mask0_END (0)
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype1_tfr_int_mask1_START (1)
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype1_tfr_int_mask1_END (1)
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype2_tfr_int_mask2_START (2)
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype2_tfr_int_mask2_END (2)
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype3_tfr_int_mask3_START (3)
#define SOC_SOCP_DEC_CORE0_MASK0_core0_dtype3_tfr_int_mask3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_dtype0_tfr_int_mask0 : 1;
        unsigned int core1_dtype1_tfr_int_mask1 : 1;
        unsigned int core1_dtype2_tfr_int_mask2 : 1;
        unsigned int core1_dtype3_tfr_int_mask3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE1_MASK0_UNION;
#endif
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype0_tfr_int_mask0_START (0)
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype0_tfr_int_mask0_END (0)
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype1_tfr_int_mask1_START (1)
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype1_tfr_int_mask1_END (1)
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype2_tfr_int_mask2_START (2)
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype2_tfr_int_mask2_END (2)
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype3_tfr_int_mask3_START (3)
#define SOC_SOCP_DEC_CORE1_MASK0_core1_dtype3_tfr_int_mask3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_dtype0_tfr_int_mask0 : 1;
        unsigned int core2_dtype1_tfr_int_mask1 : 1;
        unsigned int core2_dtype2_tfr_int_mask2 : 1;
        unsigned int core2_dtype3_tfr_int_mask3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE2_MASK0_UNION;
#endif
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype0_tfr_int_mask0_START (0)
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype0_tfr_int_mask0_END (0)
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype1_tfr_int_mask1_START (1)
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype1_tfr_int_mask1_END (1)
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype2_tfr_int_mask2_START (2)
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype2_tfr_int_mask2_END (2)
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype3_tfr_int_mask3_START (3)
#define SOC_SOCP_DEC_CORE2_MASK0_core2_dtype3_tfr_int_mask3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dtype0_tfr_rawint0 : 1;
        unsigned int dtype1_tfr_rawint1 : 1;
        unsigned int dtype2_tfr_rawint2 : 1;
        unsigned int dtype3_tfr_rawint3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_RAWINT0_UNION;
#endif
#define SOC_SOCP_DEC_RAWINT0_dtype0_tfr_rawint0_START (0)
#define SOC_SOCP_DEC_RAWINT0_dtype0_tfr_rawint0_END (0)
#define SOC_SOCP_DEC_RAWINT0_dtype1_tfr_rawint1_START (1)
#define SOC_SOCP_DEC_RAWINT0_dtype1_tfr_rawint1_END (1)
#define SOC_SOCP_DEC_RAWINT0_dtype2_tfr_rawint2_START (2)
#define SOC_SOCP_DEC_RAWINT0_dtype2_tfr_rawint2_END (2)
#define SOC_SOCP_DEC_RAWINT0_dtype3_tfr_rawint3_START (3)
#define SOC_SOCP_DEC_RAWINT0_dtype3_tfr_rawint3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_dtype0_tfr_maskint0 : 1;
        unsigned int core0_dtype1_tfr_maskint1 : 1;
        unsigned int core0_dtype2_tfr_maskint2 : 1;
        unsigned int core0_dtype3_tfr_maskint3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE0_INT0_UNION;
#endif
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype0_tfr_maskint0_START (0)
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype0_tfr_maskint0_END (0)
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype1_tfr_maskint1_START (1)
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype1_tfr_maskint1_END (1)
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype2_tfr_maskint2_START (2)
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype2_tfr_maskint2_END (2)
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype3_tfr_maskint3_START (3)
#define SOC_SOCP_DEC_CORE0_INT0_core0_dtype3_tfr_maskint3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_dtype0_tfr_maskint0 : 1;
        unsigned int core1_dtype1_tfr_maskint1 : 1;
        unsigned int core1_dtype2_tfr_maskint2 : 1;
        unsigned int core1_dtype3_tfr_maskint3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE1_INT0_UNION;
#endif
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype0_tfr_maskint0_START (0)
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype0_tfr_maskint0_END (0)
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype1_tfr_maskint1_START (1)
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype1_tfr_maskint1_END (1)
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype2_tfr_maskint2_START (2)
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype2_tfr_maskint2_END (2)
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype3_tfr_maskint3_START (3)
#define SOC_SOCP_DEC_CORE1_INT0_core1_dtype3_tfr_maskint3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_dtype0_tfr_maskint0 : 1;
        unsigned int core2_dtype1_tfr_maskint1 : 1;
        unsigned int core2_dtype2_tfr_maskint2 : 1;
        unsigned int core2_dtype3_tfr_maskint3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE2_INT0_UNION;
#endif
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype0_tfr_maskint0_START (0)
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype0_tfr_maskint0_END (0)
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype1_tfr_maskint1_START (1)
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype1_tfr_maskint1_END (1)
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype2_tfr_maskint2_START (2)
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype2_tfr_maskint2_END (2)
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype3_tfr_maskint3_START (3)
#define SOC_SOCP_DEC_CORE2_INT0_core2_dtype3_tfr_maskint3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_dec_ibuf_underflow_mask : 1;
        unsigned int core0_dec_flag_unmatch_mask : 1;
        unsigned int core0_dec_dtype_unmatch_mask : 1;
        unsigned int core0_dec_crc_err_mask : 1;
        unsigned int core0_dec_len_err_mask : 1;
        unsigned int core0_dec_7d_err_mask : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_DEC_CORE0_MASK1_UNION;
#endif
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_ibuf_underflow_mask_START (0)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_ibuf_underflow_mask_END (0)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_flag_unmatch_mask_START (1)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_flag_unmatch_mask_END (1)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_dtype_unmatch_mask_START (2)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_dtype_unmatch_mask_END (2)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_crc_err_mask_START (3)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_crc_err_mask_END (3)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_len_err_mask_START (4)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_len_err_mask_END (4)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_7d_err_mask_START (5)
#define SOC_SOCP_DEC_CORE0_MASK1_core0_dec_7d_err_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_dec_ibuf_underflow_mask : 1;
        unsigned int core1_dec_flag_unmatch_mask : 1;
        unsigned int core1_dec_dtype_unmatch_mask : 1;
        unsigned int core1_dec_crc_err_mask : 1;
        unsigned int core1_dec_len_err_mask : 1;
        unsigned int core1_dec_7d_err_mask : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_DEC_CORE1_MASK1_UNION;
#endif
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_ibuf_underflow_mask_START (0)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_ibuf_underflow_mask_END (0)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_flag_unmatch_mask_START (1)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_flag_unmatch_mask_END (1)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_dtype_unmatch_mask_START (2)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_dtype_unmatch_mask_END (2)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_crc_err_mask_START (3)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_crc_err_mask_END (3)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_len_err_mask_START (4)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_len_err_mask_END (4)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_7d_err_mask_START (5)
#define SOC_SOCP_DEC_CORE1_MASK1_core1_dec_7d_err_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_dec_ibuf_underflow_mask : 1;
        unsigned int core2_dec_flag_unmatch_mask : 1;
        unsigned int core2_dec_dtype_unmatch_mask : 1;
        unsigned int core2_dec_crc_err_mask : 1;
        unsigned int core2_dec_len_err_mask : 1;
        unsigned int core2_dec_7d_err_mask : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_DEC_CORE2_MASK1_UNION;
#endif
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_ibuf_underflow_mask_START (0)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_ibuf_underflow_mask_END (0)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_flag_unmatch_mask_START (1)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_flag_unmatch_mask_END (1)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_dtype_unmatch_mask_START (2)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_dtype_unmatch_mask_END (2)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_crc_err_mask_START (3)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_crc_err_mask_END (3)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_len_err_mask_START (4)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_len_err_mask_END (4)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_7d_err_mask_START (5)
#define SOC_SOCP_DEC_CORE2_MASK1_core2_dec_7d_err_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_ibuf_underflow_rawint : 1;
        unsigned int dec_flag_unmatch_rawint : 1;
        unsigned int dec_obuf_id_unmatch_rawint : 1;
        unsigned int dec_crc_err_rawint : 1;
        unsigned int dec_len_err_rawint : 1;
        unsigned int dec_7d_err_rawint : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_DEC_RAWINT1_UNION;
#endif
#define SOC_SOCP_DEC_RAWINT1_dec_ibuf_underflow_rawint_START (0)
#define SOC_SOCP_DEC_RAWINT1_dec_ibuf_underflow_rawint_END (0)
#define SOC_SOCP_DEC_RAWINT1_dec_flag_unmatch_rawint_START (1)
#define SOC_SOCP_DEC_RAWINT1_dec_flag_unmatch_rawint_END (1)
#define SOC_SOCP_DEC_RAWINT1_dec_obuf_id_unmatch_rawint_START (2)
#define SOC_SOCP_DEC_RAWINT1_dec_obuf_id_unmatch_rawint_END (2)
#define SOC_SOCP_DEC_RAWINT1_dec_crc_err_rawint_START (3)
#define SOC_SOCP_DEC_RAWINT1_dec_crc_err_rawint_END (3)
#define SOC_SOCP_DEC_RAWINT1_dec_len_err_rawint_START (4)
#define SOC_SOCP_DEC_RAWINT1_dec_len_err_rawint_END (4)
#define SOC_SOCP_DEC_RAWINT1_dec_7d_err_rawint_START (5)
#define SOC_SOCP_DEC_RAWINT1_dec_7d_err_rawint_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_dec_ibuf_underflow_maskint : 1;
        unsigned int core0_dec_flag_unmatch_maskint : 1;
        unsigned int core0_dec_obuf_id_unmatch_maskint : 1;
        unsigned int core0_dec_crc_err_maskint : 1;
        unsigned int core0_dec_len_err_maskint : 1;
        unsigned int core0_dec_7d_err_maskint : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_DEC_CORE0_INT1_UNION;
#endif
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_ibuf_underflow_maskint_START (0)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_ibuf_underflow_maskint_END (0)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_flag_unmatch_maskint_START (1)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_flag_unmatch_maskint_END (1)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_obuf_id_unmatch_maskint_START (2)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_obuf_id_unmatch_maskint_END (2)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_crc_err_maskint_START (3)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_crc_err_maskint_END (3)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_len_err_maskint_START (4)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_len_err_maskint_END (4)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_7d_err_maskint_START (5)
#define SOC_SOCP_DEC_CORE0_INT1_core0_dec_7d_err_maskint_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_dec_ibuf_underflow_maskint : 1;
        unsigned int core1_dec_flag_unmatch_maskint : 1;
        unsigned int core1_dec_obuf_id_unmatch_maskint : 1;
        unsigned int core1_dec_crc_err_maskint : 1;
        unsigned int core1_dec_len_err_maskint : 1;
        unsigned int core1_dec_7d_err_maskint : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_DEC_CORE1_INT1_UNION;
#endif
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_ibuf_underflow_maskint_START (0)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_ibuf_underflow_maskint_END (0)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_flag_unmatch_maskint_START (1)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_flag_unmatch_maskint_END (1)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_obuf_id_unmatch_maskint_START (2)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_obuf_id_unmatch_maskint_END (2)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_crc_err_maskint_START (3)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_crc_err_maskint_END (3)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_len_err_maskint_START (4)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_len_err_maskint_END (4)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_7d_err_maskint_START (5)
#define SOC_SOCP_DEC_CORE1_INT1_core1_dec_7d_err_maskint_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_dec_ibuf_underflow_maskint : 1;
        unsigned int core2_dec_flag_unmatch_maskint : 1;
        unsigned int core2_dec_obuf_id_unmatch_maskint : 1;
        unsigned int core2_dec_crc_err_maskint : 1;
        unsigned int core2_dec_len_err_maskint : 1;
        unsigned int core2_dec_7d_err_maskint : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_DEC_CORE2_INT1_UNION;
#endif
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_ibuf_underflow_maskint_START (0)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_ibuf_underflow_maskint_END (0)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_flag_unmatch_maskint_START (1)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_flag_unmatch_maskint_END (1)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_obuf_id_unmatch_maskint_START (2)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_obuf_id_unmatch_maskint_END (2)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_crc_err_maskint_START (3)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_crc_err_maskint_END (3)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_len_err_maskint_START (4)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_len_err_maskint_END (4)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_7d_err_maskint_START (5)
#define SOC_SOCP_DEC_CORE2_INT1_core2_dec_7d_err_maskint_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_dtype0_obuf_ovf_mask0 : 1;
        unsigned int core0_dtype1_obuf_ovf_mask1 : 1;
        unsigned int core0_dtype2_obuf_ovf_mask2 : 1;
        unsigned int core0_dtype3_obuf_ovf_mask3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE0_MASK2_UNION;
#endif
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype0_obuf_ovf_mask0_START (0)
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype0_obuf_ovf_mask0_END (0)
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype1_obuf_ovf_mask1_START (1)
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype1_obuf_ovf_mask1_END (1)
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype2_obuf_ovf_mask2_START (2)
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype2_obuf_ovf_mask2_END (2)
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype3_obuf_ovf_mask3_START (3)
#define SOC_SOCP_DEC_CORE0_MASK2_core0_dtype3_obuf_ovf_mask3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_dtype0_obuf_ovf_mask0 : 1;
        unsigned int core1_dtype1_obuf_ovf_mask1 : 1;
        unsigned int core1_dtype2_obuf_ovf_mask2 : 1;
        unsigned int core1_dtype3_obuf_ovf_mask3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE1_MASK2_UNION;
#endif
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype0_obuf_ovf_mask0_START (0)
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype0_obuf_ovf_mask0_END (0)
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype1_obuf_ovf_mask1_START (1)
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype1_obuf_ovf_mask1_END (1)
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype2_obuf_ovf_mask2_START (2)
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype2_obuf_ovf_mask2_END (2)
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype3_obuf_ovf_mask3_START (3)
#define SOC_SOCP_DEC_CORE1_MASK2_core1_dtype3_obuf_ovf_mask3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_dtype0_obuf_ovf_mask0 : 1;
        unsigned int core2_dtype1_obuf_ovf_mask1 : 1;
        unsigned int core2_dtype2_obuf_ovf_mask2 : 1;
        unsigned int core2_dtype3_obuf_ovf_mask3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE2_MASK2_UNION;
#endif
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype0_obuf_ovf_mask0_START (0)
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype0_obuf_ovf_mask0_END (0)
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype1_obuf_ovf_mask1_START (1)
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype1_obuf_ovf_mask1_END (1)
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype2_obuf_ovf_mask2_START (2)
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype2_obuf_ovf_mask2_END (2)
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype3_obuf_ovf_mask3_START (3)
#define SOC_SOCP_DEC_CORE2_MASK2_core2_dtype3_obuf_ovf_mask3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dtype0_obuf_ovf_rawint0 : 1;
        unsigned int dtype1_obuf_ovf_rawint1 : 1;
        unsigned int dtype2_obuf_ovf_rawint2 : 1;
        unsigned int dtype3_obuf_ovf_rawint3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_RAWINT2_UNION;
#endif
#define SOC_SOCP_DEC_RAWINT2_dtype0_obuf_ovf_rawint0_START (0)
#define SOC_SOCP_DEC_RAWINT2_dtype0_obuf_ovf_rawint0_END (0)
#define SOC_SOCP_DEC_RAWINT2_dtype1_obuf_ovf_rawint1_START (1)
#define SOC_SOCP_DEC_RAWINT2_dtype1_obuf_ovf_rawint1_END (1)
#define SOC_SOCP_DEC_RAWINT2_dtype2_obuf_ovf_rawint2_START (2)
#define SOC_SOCP_DEC_RAWINT2_dtype2_obuf_ovf_rawint2_END (2)
#define SOC_SOCP_DEC_RAWINT2_dtype3_obuf_ovf_rawint3_START (3)
#define SOC_SOCP_DEC_RAWINT2_dtype3_obuf_ovf_rawint3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_dtype0_obuf_ovf_int : 1;
        unsigned int core0_dtype1_obuf_ovf_int : 1;
        unsigned int core0_dtype2_obuf_ovf_int : 1;
        unsigned int core0_dtype3_obuf_ovf_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE0_INT2_UNION;
#endif
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype0_obuf_ovf_int_START (0)
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype0_obuf_ovf_int_END (0)
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype1_obuf_ovf_int_START (1)
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype1_obuf_ovf_int_END (1)
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype2_obuf_ovf_int_START (2)
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype2_obuf_ovf_int_END (2)
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype3_obuf_ovf_int_START (3)
#define SOC_SOCP_DEC_CORE0_INT2_core0_dtype3_obuf_ovf_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_dtype0_obuf_ovf_int : 1;
        unsigned int core1_dtype1_obuf_ovf_int : 1;
        unsigned int core1_dtype2_obuf_ovf_int : 1;
        unsigned int core1_dtype3_obuf_ovf_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE1_INT2_UNION;
#endif
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype0_obuf_ovf_int_START (0)
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype0_obuf_ovf_int_END (0)
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype1_obuf_ovf_int_START (1)
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype1_obuf_ovf_int_END (1)
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype2_obuf_ovf_int_START (2)
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype2_obuf_ovf_int_END (2)
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype3_obuf_ovf_int_START (3)
#define SOC_SOCP_DEC_CORE1_INT2_core1_dtype3_obuf_ovf_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_dtype0_obuf_ovf_int : 1;
        unsigned int core2_dtype1_obuf_ovf_int : 1;
        unsigned int core2_dtype2_obuf_ovf_int : 1;
        unsigned int core2_dtype3_obuf_ovf_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SOCP_DEC_CORE2_INT2_UNION;
#endif
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype0_obuf_ovf_int_START (0)
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype0_obuf_ovf_int_END (0)
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype1_obuf_ovf_int_START (1)
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype1_obuf_ovf_int_END (1)
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype2_obuf_ovf_int_START (2)
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype2_obuf_ovf_int_END (2)
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype3_obuf_ovf_int_START (3)
#define SOC_SOCP_DEC_CORE2_INT2_core2_dtype3_obuf_ovf_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_srcch_err_mask : 1;
        unsigned int enc_dstch_err_mask : 1;
        unsigned int dec_srcch_err_mask : 1;
        unsigned int dec_dstch_err_mask : 1;
        unsigned int glb_reg_err_mask : 1;
        unsigned int reserved_0 : 11;
        unsigned int enc_mst_wr_err_mask : 1;
        unsigned int enc_mst_rd_err_mask : 1;
        unsigned int dec_mst_wr_err_mask : 1;
        unsigned int dec_mst_rd_err_mask : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_BUS_ERROR_MASK_UNION;
#endif
#define SOC_SOCP_BUS_ERROR_MASK_enc_srcch_err_mask_START (0)
#define SOC_SOCP_BUS_ERROR_MASK_enc_srcch_err_mask_END (0)
#define SOC_SOCP_BUS_ERROR_MASK_enc_dstch_err_mask_START (1)
#define SOC_SOCP_BUS_ERROR_MASK_enc_dstch_err_mask_END (1)
#define SOC_SOCP_BUS_ERROR_MASK_dec_srcch_err_mask_START (2)
#define SOC_SOCP_BUS_ERROR_MASK_dec_srcch_err_mask_END (2)
#define SOC_SOCP_BUS_ERROR_MASK_dec_dstch_err_mask_START (3)
#define SOC_SOCP_BUS_ERROR_MASK_dec_dstch_err_mask_END (3)
#define SOC_SOCP_BUS_ERROR_MASK_glb_reg_err_mask_START (4)
#define SOC_SOCP_BUS_ERROR_MASK_glb_reg_err_mask_END (4)
#define SOC_SOCP_BUS_ERROR_MASK_enc_mst_wr_err_mask_START (16)
#define SOC_SOCP_BUS_ERROR_MASK_enc_mst_wr_err_mask_END (16)
#define SOC_SOCP_BUS_ERROR_MASK_enc_mst_rd_err_mask_START (17)
#define SOC_SOCP_BUS_ERROR_MASK_enc_mst_rd_err_mask_END (17)
#define SOC_SOCP_BUS_ERROR_MASK_dec_mst_wr_err_mask_START (18)
#define SOC_SOCP_BUS_ERROR_MASK_dec_mst_wr_err_mask_END (18)
#define SOC_SOCP_BUS_ERROR_MASK_dec_mst_rd_err_mask_START (19)
#define SOC_SOCP_BUS_ERROR_MASK_dec_mst_rd_err_mask_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_srcch_err_rawint : 1;
        unsigned int enc_dstch_err_rawint : 1;
        unsigned int dec_srcch_err_rawint : 1;
        unsigned int dec_dstch_err_rawint : 1;
        unsigned int glb_reg_err_rawint : 1;
        unsigned int reserved_0 : 11;
        unsigned int enc_mst_wr_err_rawint : 1;
        unsigned int enc_mst_rd_err_rawint : 1;
        unsigned int dec_mst_wr_err_rawint : 1;
        unsigned int dec_mst_rd_err_rawint : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_BUS_ERROR_RAWINT_UNION;
#endif
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_srcch_err_rawint_START (0)
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_srcch_err_rawint_END (0)
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_dstch_err_rawint_START (1)
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_dstch_err_rawint_END (1)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_srcch_err_rawint_START (2)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_srcch_err_rawint_END (2)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_dstch_err_rawint_START (3)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_dstch_err_rawint_END (3)
#define SOC_SOCP_BUS_ERROR_RAWINT_glb_reg_err_rawint_START (4)
#define SOC_SOCP_BUS_ERROR_RAWINT_glb_reg_err_rawint_END (4)
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_mst_wr_err_rawint_START (16)
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_mst_wr_err_rawint_END (16)
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_mst_rd_err_rawint_START (17)
#define SOC_SOCP_BUS_ERROR_RAWINT_enc_mst_rd_err_rawint_END (17)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_mst_wr_err_rawint_START (18)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_mst_wr_err_rawint_END (18)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_mst_rd_err_rawint_START (19)
#define SOC_SOCP_BUS_ERROR_RAWINT_dec_mst_rd_err_rawint_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_srcch_err_int : 1;
        unsigned int enc_dstch_err_int : 1;
        unsigned int dec_srcch_err_int : 1;
        unsigned int dec_dstch_err_int : 1;
        unsigned int glb_reg_err_int : 1;
        unsigned int reserved_0 : 11;
        unsigned int enc_mst_wr_err_int : 1;
        unsigned int enc_mst_rd_err_int : 1;
        unsigned int dec_mst_wr_err_int : 1;
        unsigned int dec_mst_rd_err_int : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_SOCP_BUS_ERROR_INT_UNION;
#endif
#define SOC_SOCP_BUS_ERROR_INT_enc_srcch_err_int_START (0)
#define SOC_SOCP_BUS_ERROR_INT_enc_srcch_err_int_END (0)
#define SOC_SOCP_BUS_ERROR_INT_enc_dstch_err_int_START (1)
#define SOC_SOCP_BUS_ERROR_INT_enc_dstch_err_int_END (1)
#define SOC_SOCP_BUS_ERROR_INT_dec_srcch_err_int_START (2)
#define SOC_SOCP_BUS_ERROR_INT_dec_srcch_err_int_END (2)
#define SOC_SOCP_BUS_ERROR_INT_dec_dstch_err_int_START (3)
#define SOC_SOCP_BUS_ERROR_INT_dec_dstch_err_int_END (3)
#define SOC_SOCP_BUS_ERROR_INT_glb_reg_err_int_START (4)
#define SOC_SOCP_BUS_ERROR_INT_glb_reg_err_int_END (4)
#define SOC_SOCP_BUS_ERROR_INT_enc_mst_wr_err_int_START (16)
#define SOC_SOCP_BUS_ERROR_INT_enc_mst_wr_err_int_END (16)
#define SOC_SOCP_BUS_ERROR_INT_enc_mst_rd_err_int_START (17)
#define SOC_SOCP_BUS_ERROR_INT_enc_mst_rd_err_int_END (17)
#define SOC_SOCP_BUS_ERROR_INT_dec_mst_wr_err_int_START (18)
#define SOC_SOCP_BUS_ERROR_INT_dec_mst_wr_err_int_END (18)
#define SOC_SOCP_BUS_ERROR_INT_dec_mst_rd_err_int_START (19)
#define SOC_SOCP_BUS_ERROR_INT_dec_mst_rd_err_int_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rate_period : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RATE_PERIOD_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RATE_PERIOD_enc_src_rate_period_START (0)
#define SOC_SOCP_ENC_SRC_RATE_PERIOD_enc_src_rate_period_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rate_en_l : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RATE_EN_L_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RATE_EN_L_enc_src_rate_en_l_START (0)
#define SOC_SOCP_ENC_SRC_RATE_EN_L_enc_src_rate_en_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rate_en_h : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RATE_EN_H_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RATE_EN_H_enc_src_rate_en_h_START (0)
#define SOC_SOCP_ENC_SRC_RATE_EN_H_enc_src_rate_en_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_wptr_img_cfg : 32;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_IMG_CFG_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_IMG_CFG_enc_src_wptr_img_cfg_START (0)
#define SOC_SOCP_ENC_SRC_PTR_IMG_CFG_enc_src_wptr_img_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rate_thr : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RATE_THR_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RATE_THR_enc_src_rate_thr_START (0)
#define SOC_SOCP_ENC_SRC_RATE_THR_enc_src_rate_thr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_state_l : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_L_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_L_enc_src_rptr_img_state_l_START (0)
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_L_enc_src_rptr_img_state_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_state_h : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_H_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_H_enc_src_rptr_img_state_h_START (0)
#define SOC_SOCP_ENC_SRC_RPTR_IMG_STATE_H_enc_src_rptr_img_state_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rd_img_state_l : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RD_IMG_STATE_L_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_L_enc_src_rd_img_state_l_START (0)
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_L_enc_src_rd_img_state_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rd_img_state_h : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RD_IMG_STATE_H_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_H_enc_src_rd_img_state_h_START (0)
#define SOC_SOCP_ENC_SRC_RD_IMG_STATE_H_enc_src_rd_img_state_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_core0_mask : 1;
        unsigned int enc_src_rd_img_core0_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_CORE0_MASK_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_CORE0_MASK_enc_src_rptr_img_core0_mask_START (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE0_MASK_enc_src_rptr_img_core0_mask_END (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE0_MASK_enc_src_rd_img_core0_mask_START (1)
#define SOC_SOCP_ENC_SRC_PTR_CORE0_MASK_enc_src_rd_img_core0_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_core1_mask : 1;
        unsigned int enc_src_rd_img_core1_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_CORE1_MASK_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_CORE1_MASK_enc_src_rptr_img_core1_mask_START (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE1_MASK_enc_src_rptr_img_core1_mask_END (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE1_MASK_enc_src_rd_img_core1_mask_START (1)
#define SOC_SOCP_ENC_SRC_PTR_CORE1_MASK_enc_src_rd_img_core1_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_core2_mask : 1;
        unsigned int enc_src_rd_img_core2_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_CORE2_MASK_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_CORE2_MASK_enc_src_rptr_img_core2_mask_START (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE2_MASK_enc_src_rptr_img_core2_mask_END (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE2_MASK_enc_src_rd_img_core2_mask_START (1)
#define SOC_SOCP_ENC_SRC_PTR_CORE2_MASK_enc_src_rd_img_core2_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_rawint : 1;
        unsigned int enc_src_rd_img_rawint : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_RAWINT_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_RAWINT_enc_src_rptr_img_rawint_START (0)
#define SOC_SOCP_ENC_SRC_PTR_RAWINT_enc_src_rptr_img_rawint_END (0)
#define SOC_SOCP_ENC_SRC_PTR_RAWINT_enc_src_rd_img_rawint_START (1)
#define SOC_SOCP_ENC_SRC_PTR_RAWINT_enc_src_rd_img_rawint_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_core0_int : 1;
        unsigned int enc_src_rd_img_core0_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_CORE0_INT_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_CORE0_INT_enc_src_rptr_img_core0_int_START (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE0_INT_enc_src_rptr_img_core0_int_END (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE0_INT_enc_src_rd_img_core0_int_START (1)
#define SOC_SOCP_ENC_SRC_PTR_CORE0_INT_enc_src_rd_img_core0_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_core1_int : 1;
        unsigned int enc_src_rd_img_core1_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_CORE1_INT_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_CORE1_INT_enc_src_rptr_img_core1_int_START (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE1_INT_enc_src_rptr_img_core1_int_END (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE1_INT_enc_src_rd_img_core1_int_START (1)
#define SOC_SOCP_ENC_SRC_PTR_CORE1_INT_enc_src_rd_img_core1_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_rptr_img_core2_int : 1;
        unsigned int enc_src_rd_img_core2_int : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SOCP_ENC_SRC_PTR_CORE2_INT_UNION;
#endif
#define SOC_SOCP_ENC_SRC_PTR_CORE2_INT_enc_src_rptr_img_core2_int_START (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE2_INT_enc_src_rptr_img_core2_int_END (0)
#define SOC_SOCP_ENC_SRC_PTR_CORE2_INT_enc_src_rd_img_core2_int_START (1)
#define SOC_SOCP_ENC_SRC_PTR_CORE2_INT_enc_src_rd_img_core2_int_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_wptr : 32;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_WPTR_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_WPTR_enc_src_bufm_wptr_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_WPTR_enc_src_bufm_wptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_rptr : 32;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_RPTR_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_enc_src_bufm_rptr_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_enc_src_bufm_rptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_addr_l : 32;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_ADDR_L_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_L_enc_src_bufm_addr_l_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_L_enc_src_bufm_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_addr_h : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_ADDR_H_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_H_enc_src_bufm_addr_h_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_ADDR_H_enc_src_bufm_addr_h_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_size : 32;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_DEPTH_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_DEPTH_enc_src_bufm_size_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_DEPTH_enc_src_bufm_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_chm_en : 1;
        unsigned int enc_chm_mode : 2;
        unsigned int trans_id_en : 1;
        unsigned int enc_chm_dest_buf_id : 2;
        unsigned int reserved_0 : 2;
        unsigned int enc_chm_prior_id : 2;
        unsigned int bypass_en : 1;
        unsigned int no_data_type : 1;
        unsigned int ptr_image_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int data_type : 8;
        unsigned int reserved_2 : 7;
        unsigned int enc_debug : 1;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_CFG_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_en_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_en_END (0)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_mode_START (1)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_mode_END (2)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_trans_id_en_START (3)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_trans_id_en_END (3)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_dest_buf_id_START (4)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_dest_buf_id_END (5)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_prior_id_START (8)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_chm_prior_id_END (9)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_bypass_en_START (10)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_bypass_en_END (10)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_no_data_type_START (11)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_no_data_type_END (11)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_ptr_image_en_START (12)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_ptr_image_en_END (12)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_data_type_START (16)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_data_type_END (23)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_debug_START (31)
#define SOC_SOCP_ENC_SRC_BUFM_CFG_enc_debug_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_bufm_rdq_wptr : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RDQ_WPTR_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_enc_bufm_rdq_wptr_START (0)
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_enc_bufm_rdq_wptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_bufm_rdq_rptr : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RDQ_RPTR_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RDQ_RPTR_enc_bufm_rdq_rptr_START (0)
#define SOC_SOCP_ENC_SRC_RDQ_RPTR_enc_bufm_rdq_rptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_bufm_rdq_baddr_l : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RDQ_BADDR_L_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_L_enc_bufm_rdq_baddr_l_START (0)
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_L_enc_bufm_rdq_baddr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_bufm_rdq_baddr_h : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SOCP_ENC_SRC_RDQ_BADDR_H_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_H_enc_bufm_rdq_baddr_h_START (0)
#define SOC_SOCP_ENC_SRC_RDQ_BADDR_H_enc_bufm_rdq_baddr_h_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_bufm_rdq_size : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SOCP_ENC_SRC_RDQ_CFG_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RDQ_CFG_enc_bufm_rdq_size_START (0)
#define SOC_SOCP_ENC_SRC_RDQ_CFG_enc_bufm_rdq_size_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_rptr_img_l : 32;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_L_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_L_enc_src_bufm_rptr_img_l_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_L_enc_src_bufm_rptr_img_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_rptr_img_h : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_H_UNION;
#endif
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_H_enc_src_bufm_rptr_img_h_START (0)
#define SOC_SOCP_ENC_SRC_BUFM_RPTR_IMG_H_enc_src_bufm_rptr_img_h_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_rptr_img_l : 32;
    } reg;
} SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_L_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_L_enc_src_bufm_rptr_img_l_START (0)
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_L_enc_src_bufm_rptr_img_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_rptr_img_h : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_H_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_H_enc_src_bufm_rptr_img_h_START (0)
#define SOC_SOCP_ENC_SRC_RDQ_WPTR_IMG_H_enc_src_bufm_rptr_img_h_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_src_bufm_rate_cnt : 24;
        unsigned int reserved : 7;
        unsigned int enc_src_bufm_rate_cnt_clr : 1;
    } reg;
} SOC_SOCP_ENC_SRC_RATE_CNT_CTRL_UNION;
#endif
#define SOC_SOCP_ENC_SRC_RATE_CNT_CTRL_enc_src_bufm_rate_cnt_START (0)
#define SOC_SOCP_ENC_SRC_RATE_CNT_CTRL_enc_src_bufm_rate_cnt_END (23)
#define SOC_SOCP_ENC_SRC_RATE_CNT_CTRL_enc_src_bufm_rate_cnt_clr_START (31)
#define SOC_SOCP_ENC_SRC_RATE_CNT_CTRL_enc_src_bufm_rate_cnt_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dest_bufn_wptr : 32;
    } reg;
} SOC_SOCP_ENC_DEST_BUFN_WPTR_UNION;
#endif
#define SOC_SOCP_ENC_DEST_BUFN_WPTR_enc_dest_bufn_wptr_START (0)
#define SOC_SOCP_ENC_DEST_BUFN_WPTR_enc_dest_bufn_wptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dest_bufn_rptr : 32;
    } reg;
} SOC_SOCP_ENC_DEST_BUFN_RPTR_UNION;
#endif
#define SOC_SOCP_ENC_DEST_BUFN_RPTR_enc_dest_bufn_rptr_START (0)
#define SOC_SOCP_ENC_DEST_BUFN_RPTR_enc_dest_bufn_rptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dest_bufn_addr_l : 32;
    } reg;
} SOC_SOCP_ENC_DEST_BUFN_ADDR_L_UNION;
#endif
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_L_enc_dest_bufn_addr_l_START (0)
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_L_enc_dest_bufn_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dest_bufn_addr_h : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SOCP_ENC_DEST_BUFN_ADDR_H_UNION;
#endif
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_H_enc_dest_bufn_addr_h_START (0)
#define SOC_SOCP_ENC_DEST_BUFN_ADDR_H_enc_dest_bufn_addr_h_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dest_bufn_size : 32;
    } reg;
} SOC_SOCP_ENC_DEST_BUFN_DEPTH_UNION;
#endif
#define SOC_SOCP_ENC_DEST_BUFN_DEPTH_enc_dest_bufn_size_START (0)
#define SOC_SOCP_ENC_DEST_BUFN_DEPTH_enc_dest_bufn_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dest_bufn_thrh : 32;
    } reg;
} SOC_SOCP_ENC_DEST_BUFN_THRH_UNION;
#endif
#define SOC_SOCP_ENC_DEST_BUFN_THRH_enc_dest_bufn_thrh_START (0)
#define SOC_SOCP_ENC_DEST_BUFN_THRH_enc_dest_bufn_thrh_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_int_threshold : 32;
    } reg;
} SOC_SOCP_ENC_INT_THRESHOLD_UNION;
#endif
#define SOC_SOCP_ENC_INT_THRESHOLD_enc_int_threshold_START (0)
#define SOC_SOCP_ENC_INT_THRESHOLD_enc_int_threshold_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dstch_en : 1;
        unsigned int enc_dest_buf_mode_set : 1;
        unsigned int enc_dest_buf_mode_state : 1;
        unsigned int enc_timeout_ctrl : 1;
        unsigned int enc_dest_buf_rptr_sel : 1;
        unsigned int enc_dest_trans_id_en : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SOCP_ENC_DEST_BUF_MODE_UNION;
#endif
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dstch_en_START (0)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dstch_en_END (0)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_buf_mode_set_START (1)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_buf_mode_set_END (1)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_buf_mode_state_START (2)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_buf_mode_state_END (2)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_timeout_ctrl_START (3)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_timeout_ctrl_END (3)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_buf_rptr_sel_START (4)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_buf_rptr_sel_END (4)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_trans_id_en_START (5)
#define SOC_SOCP_ENC_DEST_BUF_MODE_enc_dest_trans_id_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_dest_trans_id : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SOCP_ENC_DEST_TRANSID_UNION;
#endif
#define SOC_SOCP_ENC_DEST_TRANSID_enc_dest_trans_id_START (0)
#define SOC_SOCP_ENC_DEST_TRANSID_enc_dest_trans_id_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_src_bufx_wptr : 32;
    } reg;
} SOC_SOCP_DEC_SRC_BUFX_WPTR_UNION;
#endif
#define SOC_SOCP_DEC_SRC_BUFX_WPTR_dec_src_bufx_wptr_START (0)
#define SOC_SOCP_DEC_SRC_BUFX_WPTR_dec_src_bufx_wptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_src_bufx_rptr : 32;
    } reg;
} SOC_SOCP_DEC_SRC_BUFX_RPTR_UNION;
#endif
#define SOC_SOCP_DEC_SRC_BUFX_RPTR_dec_src_bufx_rptr_START (0)
#define SOC_SOCP_DEC_SRC_BUFX_RPTR_dec_src_bufx_rptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_src_bufx_addr_l : 32;
    } reg;
} SOC_SOCP_DEC_SRC_BUFX_ADDR_L_UNION;
#endif
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_L_dec_src_bufx_addr_l_START (0)
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_L_dec_src_bufx_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_src_bufx_addr_h : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SOCP_DEC_SRC_BUFX_ADDR_H_UNION;
#endif
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_H_dec_src_bufx_addr_h_START (0)
#define SOC_SOCP_DEC_SRC_BUFX_ADDR_H_dec_src_bufx_addr_h_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_src_bufx_size : 16;
        unsigned int reserved_0 : 10;
        unsigned int no_data_type_sel : 2;
        unsigned int reserved_1 : 1;
        unsigned int dec_debug : 1;
        unsigned int dec_chx_en : 1;
        unsigned int no_data_type : 1;
    } reg;
} SOC_SOCP_DEC_SRC_BUFX_CFG0_UNION;
#endif
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_dec_src_bufx_size_START (0)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_dec_src_bufx_size_END (15)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_no_data_type_sel_START (26)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_no_data_type_sel_END (27)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_dec_debug_START (29)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_dec_debug_END (29)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_dec_chx_en_START (30)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_dec_chx_en_END (30)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_no_data_type_START (31)
#define SOC_SOCP_DEC_SRC_BUFX_CFG0_no_data_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_crc_err_cnt : 16;
        unsigned int dec_len_err_cnt : 16;
    } reg;
} SOC_SOCP_DEC_BUFX_STATUS0_UNION;
#endif
#define SOC_SOCP_DEC_BUFX_STATUS0_dec_crc_err_cnt_START (0)
#define SOC_SOCP_DEC_BUFX_STATUS0_dec_crc_err_cnt_END (15)
#define SOC_SOCP_DEC_BUFX_STATUS0_dec_len_err_cnt_START (16)
#define SOC_SOCP_DEC_BUFX_STATUS0_dec_len_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_start_err_cnt : 16;
        unsigned int data_type_err_cnt : 16;
    } reg;
} SOC_SOCP_DEC_BUFX_STATUS1_UNION;
#endif
#define SOC_SOCP_DEC_BUFX_STATUS1_dec_start_err_cnt_START (0)
#define SOC_SOCP_DEC_BUFX_STATUS1_dec_start_err_cnt_END (15)
#define SOC_SOCP_DEC_BUFX_STATUS1_data_type_err_cnt_START (16)
#define SOC_SOCP_DEC_BUFX_STATUS1_data_type_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_dest_bufy_wptr : 32;
    } reg;
} SOC_SOCP_DEC_DEST_BUFY_WPTR_UNION;
#endif
#define SOC_SOCP_DEC_DEST_BUFY_WPTR_dec_dest_bufy_wptr_START (0)
#define SOC_SOCP_DEC_DEST_BUFY_WPTR_dec_dest_bufy_wptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_dest_bufy_rptr : 32;
    } reg;
} SOC_SOCP_DEC_DEST_BUFY_RPTR_UNION;
#endif
#define SOC_SOCP_DEC_DEST_BUFY_RPTR_dec_dest_bufy_rptr_START (0)
#define SOC_SOCP_DEC_DEST_BUFY_RPTR_dec_dest_bufy_rptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_dest_bufy_addr_l : 32;
    } reg;
} SOC_SOCP_DEC_DEST_BUFY_ADDR_L_UNION;
#endif
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_L_dec_dest_bufy_addr_l_START (0)
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_L_dec_dest_bufy_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_dest_bufy_addr_h : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SOCP_DEC_DEST_BUFY_ADDR_H_UNION;
#endif
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_H_dec_dest_bufy_addr_h_START (0)
#define SOC_SOCP_DEC_DEST_BUFY_ADDR_H_dec_dest_bufy_addr_h_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dec_dest_bufy_size : 16;
        unsigned int dec_int_threshold : 8;
        unsigned int data_type : 8;
    } reg;
} SOC_SOCP_DEC_DEST_BUFY_CFG0_UNION;
#endif
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_dec_dest_bufy_size_START (0)
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_dec_dest_bufy_size_END (15)
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_dec_int_threshold_START (16)
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_dec_int_threshold_END (23)
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_data_type_START (24)
#define SOC_SOCP_DEC_DEST_BUFY_CFG0_data_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cd_buf_baddr_l : 32;
    } reg;
} SOC_SOCP_ENC_CD_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_CD_DBG0_cd_buf_baddr_l_START (0)
#define SOC_SOCP_ENC_CD_DBG0_cd_buf_baddr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cd_buf_baddr_h : 15;
        unsigned int cd_idle : 1;
        unsigned int cd_blk_len : 16;
    } reg;
} SOC_SOCP_ENC_CD_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_CD_DBG1_cd_buf_baddr_h_START (0)
#define SOC_SOCP_ENC_CD_DBG1_cd_buf_baddr_h_END (14)
#define SOC_SOCP_ENC_CD_DBG1_cd_idle_START (15)
#define SOC_SOCP_ENC_CD_DBG1_cd_idle_END (15)
#define SOC_SOCP_ENC_CD_DBG1_cd_blk_len_START (16)
#define SOC_SOCP_ENC_CD_DBG1_cd_blk_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_fsm_state : 3;
        unsigned int reserved_0 : 1;
        unsigned int eop : 1;
        unsigned int sop : 1;
        unsigned int fifo_full : 1;
        unsigned int fifo_empty : 1;
        unsigned int reserved_1 : 8;
        unsigned int remain_blk_cnt : 16;
    } reg;
} SOC_SOCP_ENC_IBUF_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_DBG0_ibuf_fsm_state_START (0)
#define SOC_SOCP_ENC_IBUF_DBG0_ibuf_fsm_state_END (2)
#define SOC_SOCP_ENC_IBUF_DBG0_eop_START (4)
#define SOC_SOCP_ENC_IBUF_DBG0_eop_END (4)
#define SOC_SOCP_ENC_IBUF_DBG0_sop_START (5)
#define SOC_SOCP_ENC_IBUF_DBG0_sop_END (5)
#define SOC_SOCP_ENC_IBUF_DBG0_fifo_full_START (6)
#define SOC_SOCP_ENC_IBUF_DBG0_fifo_full_END (6)
#define SOC_SOCP_ENC_IBUF_DBG0_fifo_empty_START (7)
#define SOC_SOCP_ENC_IBUF_DBG0_fifo_empty_END (7)
#define SOC_SOCP_ENC_IBUF_DBG0_remain_blk_cnt_START (16)
#define SOC_SOCP_ENC_IBUF_DBG0_remain_blk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr : 32;
    } reg;
} SOC_SOCP_ENC_IBUF_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_DBG1_dma_addr_START (0)
#define SOC_SOCP_ENC_IBUF_DBG1_dma_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_fifo_dout_lo : 32;
    } reg;
} SOC_SOCP_ENC_IBUF_DBG2_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_DBG2_ibuf_fifo_dout_lo_START (0)
#define SOC_SOCP_ENC_IBUF_DBG2_ibuf_fifo_dout_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_fifo_dout_hi : 32;
    } reg;
} SOC_SOCP_ENC_IBUF_DBG3_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_DBG3_ibuf_fifo_dout_hi_START (0)
#define SOC_SOCP_ENC_IBUF_DBG3_ibuf_fifo_dout_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int obuf_fsm_state : 3;
        unsigned int reserved_0 : 2;
        unsigned int fifo_afull : 1;
        unsigned int fifo_full : 1;
        unsigned int fifo_empty : 1;
        unsigned int eop : 1;
        unsigned int sop : 1;
        unsigned int reserved_1 : 6;
        unsigned int pkt_in_cnt : 16;
    } reg;
} SOC_SOCP_ENC_OBUF_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_OBUF_DBG0_obuf_fsm_state_START (0)
#define SOC_SOCP_ENC_OBUF_DBG0_obuf_fsm_state_END (2)
#define SOC_SOCP_ENC_OBUF_DBG0_fifo_afull_START (5)
#define SOC_SOCP_ENC_OBUF_DBG0_fifo_afull_END (5)
#define SOC_SOCP_ENC_OBUF_DBG0_fifo_full_START (6)
#define SOC_SOCP_ENC_OBUF_DBG0_fifo_full_END (6)
#define SOC_SOCP_ENC_OBUF_DBG0_fifo_empty_START (7)
#define SOC_SOCP_ENC_OBUF_DBG0_fifo_empty_END (7)
#define SOC_SOCP_ENC_OBUF_DBG0_eop_START (8)
#define SOC_SOCP_ENC_OBUF_DBG0_eop_END (8)
#define SOC_SOCP_ENC_OBUF_DBG0_sop_START (9)
#define SOC_SOCP_ENC_OBUF_DBG0_sop_END (9)
#define SOC_SOCP_ENC_OBUF_DBG0_pkt_in_cnt_START (16)
#define SOC_SOCP_ENC_OBUF_DBG0_pkt_in_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pkt_out_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SOCP_ENC_OBUF_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_OBUF_DBG1_pkt_out_cnt_START (0)
#define SOC_SOCP_ENC_OBUF_DBG1_pkt_out_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nxt_dma_addr : 32;
    } reg;
} SOC_SOCP_ENC_OBUF_DBG2_UNION;
#endif
#define SOC_SOCP_ENC_OBUF_DBG2_nxt_dma_addr_START (0)
#define SOC_SOCP_ENC_OBUF_DBG2_nxt_dma_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int obuf_fifo_dout_lo : 32;
    } reg;
} SOC_SOCP_ENC_OBUF_DBG3_UNION;
#endif
#define SOC_SOCP_ENC_OBUF_DBG3_obuf_fifo_dout_lo_START (0)
#define SOC_SOCP_ENC_OBUF_DBG3_obuf_fifo_dout_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_fsm_state : 4;
        unsigned int ibuf_rdy : 1;
        unsigned int dec_end : 1;
        unsigned int fifo_full : 1;
        unsigned int fifo_empty : 1;
        unsigned int reserved : 8;
        unsigned int remain_blk_cnt : 16;
    } reg;
} SOC_SOCP_DEC_IBUF_DBG0_UNION;
#endif
#define SOC_SOCP_DEC_IBUF_DBG0_ibuf_fsm_state_START (0)
#define SOC_SOCP_DEC_IBUF_DBG0_ibuf_fsm_state_END (3)
#define SOC_SOCP_DEC_IBUF_DBG0_ibuf_rdy_START (4)
#define SOC_SOCP_DEC_IBUF_DBG0_ibuf_rdy_END (4)
#define SOC_SOCP_DEC_IBUF_DBG0_dec_end_START (5)
#define SOC_SOCP_DEC_IBUF_DBG0_dec_end_END (5)
#define SOC_SOCP_DEC_IBUF_DBG0_fifo_full_START (6)
#define SOC_SOCP_DEC_IBUF_DBG0_fifo_full_END (6)
#define SOC_SOCP_DEC_IBUF_DBG0_fifo_empty_START (7)
#define SOC_SOCP_DEC_IBUF_DBG0_fifo_empty_END (7)
#define SOC_SOCP_DEC_IBUF_DBG0_remain_blk_cnt_START (16)
#define SOC_SOCP_DEC_IBUF_DBG0_remain_blk_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr : 32;
    } reg;
} SOC_SOCP_DEC_IBUF_DBG1_UNION;
#endif
#define SOC_SOCP_DEC_IBUF_DBG1_dma_addr_START (0)
#define SOC_SOCP_DEC_IBUF_DBG1_dma_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_fifo_dout_lo : 32;
    } reg;
} SOC_SOCP_DEC_IBUF_DBG2_UNION;
#endif
#define SOC_SOCP_DEC_IBUF_DBG2_ibuf_fifo_dout_lo_START (0)
#define SOC_SOCP_DEC_IBUF_DBG2_ibuf_fifo_dout_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_fifo_dout_hi : 32;
    } reg;
} SOC_SOCP_DEC_IBUF_DBG3_UNION;
#endif
#define SOC_SOCP_DEC_IBUF_DBG3_ibuf_fifo_dout_hi_START (0)
#define SOC_SOCP_DEC_IBUF_DBG3_ibuf_fifo_dout_hi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int obuf_fsm_state : 3;
        unsigned int reserved_0 : 2;
        unsigned int fifo_afull : 1;
        unsigned int fifo_full : 1;
        unsigned int fifo_empty : 1;
        unsigned int eop : 1;
        unsigned int sop : 1;
        unsigned int reserved_1 : 6;
        unsigned int pkt_in_cnt : 16;
    } reg;
} SOC_SOCP_DEC_OBUF_DBG0_UNION;
#endif
#define SOC_SOCP_DEC_OBUF_DBG0_obuf_fsm_state_START (0)
#define SOC_SOCP_DEC_OBUF_DBG0_obuf_fsm_state_END (2)
#define SOC_SOCP_DEC_OBUF_DBG0_fifo_afull_START (5)
#define SOC_SOCP_DEC_OBUF_DBG0_fifo_afull_END (5)
#define SOC_SOCP_DEC_OBUF_DBG0_fifo_full_START (6)
#define SOC_SOCP_DEC_OBUF_DBG0_fifo_full_END (6)
#define SOC_SOCP_DEC_OBUF_DBG0_fifo_empty_START (7)
#define SOC_SOCP_DEC_OBUF_DBG0_fifo_empty_END (7)
#define SOC_SOCP_DEC_OBUF_DBG0_eop_START (8)
#define SOC_SOCP_DEC_OBUF_DBG0_eop_END (8)
#define SOC_SOCP_DEC_OBUF_DBG0_sop_START (9)
#define SOC_SOCP_DEC_OBUF_DBG0_sop_END (9)
#define SOC_SOCP_DEC_OBUF_DBG0_pkt_in_cnt_START (16)
#define SOC_SOCP_DEC_OBUF_DBG0_pkt_in_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pkt_out_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SOCP_DEC_OBUF_DBG1_UNION;
#endif
#define SOC_SOCP_DEC_OBUF_DBG1_pkt_out_cnt_START (0)
#define SOC_SOCP_DEC_OBUF_DBG1_pkt_out_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nxt_dma_addr : 32;
    } reg;
} SOC_SOCP_DEC_OBUF_DBG2_UNION;
#endif
#define SOC_SOCP_DEC_OBUF_DBG2_nxt_dma_addr_START (0)
#define SOC_SOCP_DEC_OBUF_DBG2_nxt_dma_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int obuf_fifo_dout_lo : 32;
    } reg;
} SOC_SOCP_DEC_OBUF_DBG3_UNION;
#endif
#define SOC_SOCP_DEC_OBUF_DBG3_obuf_fifo_dout_lo_START (0)
#define SOC_SOCP_DEC_OBUF_DBG3_obuf_fifo_dout_lo_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ibuf_addr_l : 32;
    } reg;
} SOC_SOCP_ENC_PTR_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_PTR_DBG0_enc_ibuf_addr_l_START (0)
#define SOC_SOCP_ENC_PTR_DBG0_enc_ibuf_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ibuf_addr_h : 32;
    } reg;
} SOC_SOCP_ENC_PTR_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_PTR_DBG1_enc_ibuf_addr_h_START (0)
#define SOC_SOCP_ENC_PTR_DBG1_enc_ibuf_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_obuf_addr_l : 32;
    } reg;
} SOC_SOCP_ENC_PTR_DBG2_UNION;
#endif
#define SOC_SOCP_ENC_PTR_DBG2_enc_obuf_addr_l_START (0)
#define SOC_SOCP_ENC_PTR_DBG2_enc_obuf_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_obuf_addr_h : 32;
    } reg;
} SOC_SOCP_ENC_PTR_DBG3_UNION;
#endif
#define SOC_SOCP_ENC_PTR_DBG3_enc_obuf_addr_h_START (0)
#define SOC_SOCP_ENC_PTR_DBG3_enc_obuf_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ch_rate_ovf_l : 32;
    } reg;
} SOC_SOCP_ENC_CH_TRH_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_CH_TRH_DBG0_enc_ch_rate_ovf_l_START (0)
#define SOC_SOCP_ENC_CH_TRH_DBG0_enc_ch_rate_ovf_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ch_rate_ovf_h : 32;
    } reg;
} SOC_SOCP_ENC_CH_TRH_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_CH_TRH_DBG1_enc_ch_rate_ovf_h_START (0)
#define SOC_SOCP_ENC_CH_TRH_DBG1_enc_ch_rate_ovf_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_rptr_dma_addr_h : 8;
        unsigned int reserved_0 : 8;
        unsigned int ibuf_rptr_fsm_state : 3;
        unsigned int ibuf_rptr_ch_grant_index : 6;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_SOCP_ENC_PTR_IMG_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ibuf_rptr_dma_addr_h_START (0)
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ibuf_rptr_dma_addr_h_END (7)
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ibuf_rptr_fsm_state_START (16)
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ibuf_rptr_fsm_state_END (18)
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ibuf_rptr_ch_grant_index_START (19)
#define SOC_SOCP_ENC_PTR_IMG_DBG0_ibuf_rptr_ch_grant_index_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_rptr_dma_addr_l : 32;
    } reg;
} SOC_SOCP_ENC_PTR_IMG_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_PTR_IMG_DBG1_ibuf_rptr_dma_addr_l_START (0)
#define SOC_SOCP_ENC_PTR_IMG_DBG1_ibuf_rptr_dma_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_rptr_dma_data : 32;
    } reg;
} SOC_SOCP_ENC_PTR_IMG_DBG2_UNION;
#endif
#define SOC_SOCP_ENC_PTR_IMG_DBG2_ibuf_rptr_dma_data_START (0)
#define SOC_SOCP_ENC_PTR_IMG_DBG2_ibuf_rptr_dma_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_rptr_all_arb_req_l : 32;
    } reg;
} SOC_SOCP_ENC_PTR_IMG_DBG3_UNION;
#endif
#define SOC_SOCP_ENC_PTR_IMG_DBG3_ibuf_rptr_all_arb_req_l_START (0)
#define SOC_SOCP_ENC_PTR_IMG_DBG3_ibuf_rptr_all_arb_req_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ibuf_rptr_all_arb_req_h : 32;
    } reg;
} SOC_SOCP_ENC_PTR_IMG_DBG4_UNION;
#endif
#define SOC_SOCP_ENC_PTR_IMG_DBG4_ibuf_rptr_all_arb_req_h_START (0)
#define SOC_SOCP_ENC_PTR_IMG_DBG4_ibuf_rptr_all_arb_req_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_wptr_dma_addr_h : 8;
        unsigned int reserved_0 : 8;
        unsigned int rd_wptr_fsm_state : 3;
        unsigned int rd_wptr_ch_grant_index : 6;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_SOCP_ENC_RD_IMG_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_RD_IMG_DBG0_rd_wptr_dma_addr_h_START (0)
#define SOC_SOCP_ENC_RD_IMG_DBG0_rd_wptr_dma_addr_h_END (7)
#define SOC_SOCP_ENC_RD_IMG_DBG0_rd_wptr_fsm_state_START (16)
#define SOC_SOCP_ENC_RD_IMG_DBG0_rd_wptr_fsm_state_END (18)
#define SOC_SOCP_ENC_RD_IMG_DBG0_rd_wptr_ch_grant_index_START (19)
#define SOC_SOCP_ENC_RD_IMG_DBG0_rd_wptr_ch_grant_index_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_wptr_dma_addr_l : 32;
    } reg;
} SOC_SOCP_ENC_RD_IMG_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_RD_IMG_DBG1_rd_wptr_dma_addr_l_START (0)
#define SOC_SOCP_ENC_RD_IMG_DBG1_rd_wptr_dma_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_wptr_dma_data : 32;
    } reg;
} SOC_SOCP_ENC_RD_IMG_DBG2_UNION;
#endif
#define SOC_SOCP_ENC_RD_IMG_DBG2_rd_wptr_dma_data_START (0)
#define SOC_SOCP_ENC_RD_IMG_DBG2_rd_wptr_dma_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_wptr_all_arb_req_l : 32;
    } reg;
} SOC_SOCP_ENC_RD_IMG_DBG3_UNION;
#endif
#define SOC_SOCP_ENC_RD_IMG_DBG3_rd_wptr_all_arb_req_l_START (0)
#define SOC_SOCP_ENC_RD_IMG_DBG3_rd_wptr_all_arb_req_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_wptr_all_arb_req_h : 32;
    } reg;
} SOC_SOCP_ENC_RD_IMG_DBG4_UNION;
#endif
#define SOC_SOCP_ENC_RD_IMG_DBG4_rd_wptr_all_arb_req_h_START (0)
#define SOC_SOCP_ENC_RD_IMG_DBG4_rd_wptr_all_arb_req_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ch_state_l : 32;
    } reg;
} SOC_SOCP_ENC_IBUF_STATE_DBG0_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_STATE_DBG0_enc_ch_state_l_START (0)
#define SOC_SOCP_ENC_IBUF_STATE_DBG0_enc_ch_state_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ch_state_h : 32;
    } reg;
} SOC_SOCP_ENC_IBUF_STATE_DBG1_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_STATE_DBG1_enc_ch_state_h_START (0)
#define SOC_SOCP_ENC_IBUF_STATE_DBG1_enc_ch_state_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ch_id : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_SOCP_ENC_IBUF_STATE_DBG2_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_STATE_DBG2_enc_ch_id_START (0)
#define SOC_SOCP_ENC_IBUF_STATE_DBG2_enc_ch_id_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hac_gif_axi_st : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_SOCP_HAC_GIF_DBG_UNION;
#endif
#define SOC_SOCP_HAC_GIF_DBG_hac_gif_axi_st_START (0)
#define SOC_SOCP_HAC_GIF_DBG_hac_gif_axi_st_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enc_ibuf_state_clear : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SOCP_ENC_IBUF_STATE_CLEAR_UNION;
#endif
#define SOC_SOCP_ENC_IBUF_STATE_CLEAR_enc_ibuf_state_clear_START (0)
#define SOC_SOCP_ENC_IBUF_STATE_CLEAR_enc_ibuf_state_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int socp_version : 32;
    } reg;
} SOC_SOCP_VERSION_UNION;
#endif
#define SOC_SOCP_VERSION_socp_version_START (0)
#define SOC_SOCP_VERSION_socp_version_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
