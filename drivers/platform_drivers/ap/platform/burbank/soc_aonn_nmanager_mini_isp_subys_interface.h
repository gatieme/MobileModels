#ifndef __SOC_AONN_NMANAGER_MINI_ISP_SUBYS_INTERFACE_H__
#define __SOC_AONN_NMANAGER_MINI_ISP_SUBYS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_ADDR(base) ((base) + (0x0UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_ADDR(base) ((base) + (0x4UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_ADDR(base) ((base) + (0x8UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_ADDR(base) ((base) + (0xCUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FORCE_CLK_ON_ADDR(base) ((base) + (0x10UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_ADDR(base) ((base) + (0x14UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_ADDR(base) ((base) + (0x18UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ADDR(base) ((base) + (0x1CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ADDR(base) ((base) + (0x20UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_ADDR(base) ((base) + (0x24UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_ADDR(base) ((base) + (0x28UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_ADDR(base) ((base) + (0x2CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ADDR(base) ((base) + (0x30UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ADDR(base) ((base) + (0x34UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_ADDR(base) ((base) + (0x38UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_ADDR(base) ((base) + (0x3CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_ADDR(base) ((base) + (0x40UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ADDR(base) ((base) + (0x44UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ADDR(base) ((base) + (0x48UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_ADDR(base) ((base) + (0x4CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_ADDR(base) ((base) + (0x50UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_ADDR(base) ((base) + (0x54UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MEM_CTRL_SP_ADDR(base) ((base) + (0x58UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_TIME_OUT_ADDR(base) ((base) + (0x5CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_VSYNC_CTRL_ADDR(base) ((base) + (0x60UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_CTRL_ADDR(base) ((base) + (0x64UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_ADDR(base) ((base) + (0x68UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FRAMECOUNTER_ADDR(base) ((base) + (0x6CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_GO_BIT_ADDR(base) ((base) + (0x70UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECURITY_CFG_ADDR(base) ((base) + (0x400UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ADDR(base) ((base) + (0x41CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ADDR(base) ((base) + (0x420UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_ADDR(base) ((base) + (0x424UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_ADDR(base) ((base) + (0x428UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_ADDR(base) ((base) + (0x42CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ADDR(base) ((base) + (0x430UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ADDR(base) ((base) + (0x434UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_ADDR(base) ((base) + (0x438UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_ADDR(base) ((base) + (0x43CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_ADDR(base) ((base) + (0x440UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ADDR(base) ((base) + (0x444UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ADDR(base) ((base) + (0x448UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_ADDR(base) ((base) + (0x44CUL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_ADDR(base) ((base) + (0x450UL))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_ADDR(base) ((base) + (0x454UL))
#else
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_ADDR(base) ((base) + (0x0))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_ADDR(base) ((base) + (0x4))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_ADDR(base) ((base) + (0x8))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_ADDR(base) ((base) + (0xC))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FORCE_CLK_ON_ADDR(base) ((base) + (0x10))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_ADDR(base) ((base) + (0x14))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_ADDR(base) ((base) + (0x18))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ADDR(base) ((base) + (0x1C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ADDR(base) ((base) + (0x20))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_ADDR(base) ((base) + (0x24))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_ADDR(base) ((base) + (0x28))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_ADDR(base) ((base) + (0x2C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ADDR(base) ((base) + (0x30))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ADDR(base) ((base) + (0x34))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_ADDR(base) ((base) + (0x38))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_ADDR(base) ((base) + (0x3C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_ADDR(base) ((base) + (0x40))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ADDR(base) ((base) + (0x44))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ADDR(base) ((base) + (0x48))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_ADDR(base) ((base) + (0x4C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_ADDR(base) ((base) + (0x50))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_ADDR(base) ((base) + (0x54))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MEM_CTRL_SP_ADDR(base) ((base) + (0x58))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_TIME_OUT_ADDR(base) ((base) + (0x5C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_VSYNC_CTRL_ADDR(base) ((base) + (0x60))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_CTRL_ADDR(base) ((base) + (0x64))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_ADDR(base) ((base) + (0x68))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FRAMECOUNTER_ADDR(base) ((base) + (0x6C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_GO_BIT_ADDR(base) ((base) + (0x70))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECURITY_CFG_ADDR(base) ((base) + (0x400))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ADDR(base) ((base) + (0x41C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ADDR(base) ((base) + (0x420))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_ADDR(base) ((base) + (0x424))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_ADDR(base) ((base) + (0x428))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_ADDR(base) ((base) + (0x42C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ADDR(base) ((base) + (0x430))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ADDR(base) ((base) + (0x434))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_ADDR(base) ((base) + (0x438))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_ADDR(base) ((base) + (0x43C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_ADDR(base) ((base) + (0x440))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ADDR(base) ((base) + (0x444))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ADDR(base) ((base) + (0x448))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_ADDR(base) ((base) + (0x44C))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_ADDR(base) ((base) + (0x450))
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_ADDR(base) ((base) + (0x454))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_pipe : 1;
        unsigned int cg_cvdr : 1;
        unsigned int cg_csi2if : 1;
        unsigned int global_enable : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_cg_pipe_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_cg_pipe_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_cg_cvdr_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_cg_cvdr_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_cg_csi2if_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_cg_csi2if_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_global_enable_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_global_enable_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_pipe : 1;
        unsigned int cg_cvdr : 1;
        unsigned int cg_csi2if : 1;
        unsigned int global_enable : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_cg_pipe_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_cg_pipe_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_cg_cvdr_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_cg_cvdr_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_cg_csi2if_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_cg_csi2if_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_global_enable_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_SET_global_enable_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cg_pipe : 1;
        unsigned int cg_cvdr : 1;
        unsigned int cg_csi2if : 1;
        unsigned int global_enable : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_cg_pipe_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_cg_pipe_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_cg_cvdr_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_cg_cvdr_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_cg_csi2if_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_cg_csi2if_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_global_enable_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_CGR_0_CLEAR_global_enable_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_rst_pipe : 1;
        unsigned int soft_rst_cvdr : 1;
        unsigned int soft_rst_csi2if : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_soft_rst_pipe_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_soft_rst_pipe_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_soft_rst_cvdr_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_soft_rst_cvdr_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_soft_rst_csi2if_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MINI_ISP_RESET_0_soft_rst_csi2if_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_FORCE_CLK_ON_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FORCE_CLK_ON_pipe_force_clk_on_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FORCE_CLK_ON_pipe_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cam_mode : 2;
        unsigned int reserved_0 : 2;
        unsigned int cam_pol : 1;
        unsigned int hvalid_pol : 1;
        unsigned int vvalid_pol : 1;
        unsigned int worder : 1;
        unsigned int vsync_mode : 2;
        unsigned int dummy_dta_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int cam_trigger_cnt : 4;
        unsigned int cam_shutdown : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_mode_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_mode_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_pol_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_pol_END (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_hvalid_pol_START (5)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_hvalid_pol_END (5)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_vvalid_pol_START (6)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_vvalid_pol_END (6)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_worder_START (7)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_worder_END (7)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_vsync_mode_START (8)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_vsync_mode_END (9)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_dummy_dta_en_START (10)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_dummy_dta_en_END (10)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_trigger_cnt_START (12)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_trigger_cnt_END (15)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_shutdown_START (16)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_cam_shutdown_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int img_width : 11;
        unsigned int reserved_0 : 5;
        unsigned int img_height : 11;
        unsigned int reserved_1 : 4;
        unsigned int vp_mux : 1;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_img_width_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_img_width_END (10)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_img_height_START (16)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_img_height_END (26)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_vp_mux_START (31)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_IF_CTRL_2_vp_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ims_cam_eof : 1;
        unsigned int ims_pipe_irq : 1;
        unsigned int ims_cvdr_vp_wr_eof : 1;
        unsigned int ims_cvdr_vp_rd_eof : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_cam_eof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_cam_eof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_pipe_irq_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_pipe_irq_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_cvdr_vp_wr_eof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_cvdr_vp_wr_eof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_cvdr_vp_rd_eof_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_ims_cvdr_vp_rd_eof_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ris_cam_eof : 1;
        unsigned int ris_pipe_irq : 1;
        unsigned int ris_cvdr_vp_wr_eof : 1;
        unsigned int ris_cvdr_vp_rd_eof : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_cam_eof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_cam_eof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_pipe_irq_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_pipe_irq_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_cvdr_vp_wr_eof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_cvdr_vp_wr_eof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_cvdr_vp_rd_eof_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_ris_cvdr_vp_rd_eof_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mis_cam_eof : 1;
        unsigned int mis_pipe_irq : 1;
        unsigned int mis_cvdr_vp_wr_eof : 1;
        unsigned int mis_cvdr_vp_rd_eof : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_cam_eof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_cam_eof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_pipe_irq_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_pipe_irq_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_cvdr_vp_wr_eof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_cvdr_vp_wr_eof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_cvdr_vp_rd_eof_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_mis_cvdr_vp_rd_eof_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icr_cam_eof : 1;
        unsigned int icr_pipe_irq : 1;
        unsigned int icr_cvdr_vp_wr_eof : 1;
        unsigned int icr_cvdr_vp_rd_eof : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_cam_eof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_cam_eof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_pipe_irq_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_pipe_irq_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_cvdr_vp_wr_eof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_cvdr_vp_wr_eof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_cvdr_vp_rd_eof_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_icr_cvdr_vp_rd_eof_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isr_cam_eof : 1;
        unsigned int isr_pipe_irq : 1;
        unsigned int isr_cvdr_vp_wr_eof : 1;
        unsigned int isr_cvdr_vp_rd_eof : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_cam_eof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_cam_eof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_pipe_irq_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_pipe_irq_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_cvdr_vp_wr_eof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_cvdr_vp_wr_eof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_cvdr_vp_rd_eof_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_isr_cvdr_vp_rd_eof_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ims_cam_overflow : 1;
        unsigned int ims_image_size_err : 1;
        unsigned int ims_cvdr_axi_wr_resp_err : 1;
        unsigned int ims_cvdr_axi_rd_resp_err : 1;
        unsigned int ims_cvdr_axi_wr_full : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cam_overflow_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cam_overflow_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_image_size_err_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_image_size_err_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cvdr_axi_wr_resp_err_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cvdr_axi_wr_resp_err_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cvdr_axi_rd_resp_err_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cvdr_axi_rd_resp_err_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cvdr_axi_wr_full_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_ims_cvdr_axi_wr_full_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ris_cam_overflow : 1;
        unsigned int ris_image_size_err : 1;
        unsigned int ris_cvdr_axi_wr_resp_err : 1;
        unsigned int ris_cvdr_axi_rd_resp_err : 1;
        unsigned int ris_cvdr_axi_wr_full : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cam_overflow_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cam_overflow_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_image_size_err_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_image_size_err_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cvdr_axi_wr_resp_err_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cvdr_axi_wr_resp_err_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cvdr_axi_rd_resp_err_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cvdr_axi_rd_resp_err_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cvdr_axi_wr_full_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_ris_cvdr_axi_wr_full_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mis_cam_overflow : 1;
        unsigned int mis_image_size_err : 1;
        unsigned int mis_cvdr_axi_wr_resp_err : 1;
        unsigned int mis_cvdr_axi_rd_resp_err : 1;
        unsigned int mis_cvdr_axi_wr_full : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cam_overflow_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cam_overflow_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_image_size_err_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_image_size_err_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cvdr_axi_wr_resp_err_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cvdr_axi_wr_resp_err_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cvdr_axi_rd_resp_err_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cvdr_axi_rd_resp_err_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cvdr_axi_wr_full_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_mis_cvdr_axi_wr_full_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icr_cam_overflow : 1;
        unsigned int icr_image_size_err : 1;
        unsigned int icr_cvdr_axi_wr_resp_err : 1;
        unsigned int icr_cvdr_axi_rd_resp_err : 1;
        unsigned int icr_cvdr_axi_wr_full : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cam_overflow_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cam_overflow_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_image_size_err_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_image_size_err_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cvdr_axi_wr_resp_err_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cvdr_axi_wr_resp_err_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cvdr_axi_rd_resp_err_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cvdr_axi_rd_resp_err_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cvdr_axi_wr_full_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_icr_cvdr_axi_wr_full_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isr_cam_overflow : 1;
        unsigned int isr_image_size_err : 1;
        unsigned int isr_cvdr_axi_wr_resp_err : 1;
        unsigned int isr_cvdr_axi_rd_resp_err : 1;
        unsigned int isr_cvdr_axi_wr_full : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cam_overflow_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cam_overflow_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_image_size_err_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_image_size_err_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cvdr_axi_wr_resp_err_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cvdr_axi_wr_resp_err_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cvdr_axi_rd_resp_err_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cvdr_axi_rd_resp_err_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cvdr_axi_wr_full_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_isr_cvdr_axi_wr_full_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ims_cam_sof : 1;
        unsigned int ims_cvdr_vp_wr_sof : 1;
        unsigned int ims_cvdr_vp_rd_sof : 1;
        unsigned int ims_cvdr_vp_wr_dropped : 1;
        unsigned int ims_cam_dropped : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cam_sof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cam_sof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cvdr_vp_wr_sof_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cvdr_vp_wr_sof_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cvdr_vp_rd_sof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cvdr_vp_rd_sof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cvdr_vp_wr_dropped_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cvdr_vp_wr_dropped_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cam_dropped_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_ims_cam_dropped_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ris_cam_sof : 1;
        unsigned int ris_cvdr_vp_wr_sof : 1;
        unsigned int ris_cvdr_vp_rd_sof : 1;
        unsigned int ris_cvdr_vp_wr_dropped : 1;
        unsigned int ris_cam_dropped : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cam_sof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cam_sof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cvdr_vp_wr_sof_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cvdr_vp_wr_sof_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cvdr_vp_rd_sof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cvdr_vp_rd_sof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cvdr_vp_wr_dropped_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cvdr_vp_wr_dropped_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cam_dropped_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_ris_cam_dropped_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mis_cam_sof : 1;
        unsigned int mis_cvdr_vp_wr_sof : 1;
        unsigned int mis_cvdr_vp_rd_sof : 1;
        unsigned int mis_cvdr_vp_wr_dropped : 1;
        unsigned int mis_cam_dropped : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cam_sof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cam_sof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cvdr_vp_wr_sof_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cvdr_vp_wr_sof_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cvdr_vp_rd_sof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cvdr_vp_rd_sof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cvdr_vp_wr_dropped_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cvdr_vp_wr_dropped_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cam_dropped_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_mis_cam_dropped_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icr_cam_sof : 1;
        unsigned int icr_cvdr_vp_wr_sof : 1;
        unsigned int icr_cvdr_vp_rd_sof : 1;
        unsigned int icr_cvdr_vp_wr_dropped : 1;
        unsigned int icr_cam_dropped : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cam_sof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cam_sof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cvdr_vp_wr_sof_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cvdr_vp_wr_sof_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cvdr_vp_rd_sof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cvdr_vp_rd_sof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cvdr_vp_wr_dropped_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cvdr_vp_wr_dropped_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cam_dropped_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_icr_cam_dropped_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isr_cam_sof : 1;
        unsigned int isr_cvdr_vp_wr_sof : 1;
        unsigned int isr_cvdr_vp_rd_sof : 1;
        unsigned int isr_cvdr_vp_wr_dropped : 1;
        unsigned int isr_cam_dropped : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cam_sof_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cam_sof_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cvdr_vp_wr_sof_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cvdr_vp_wr_sof_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cvdr_vp_rd_sof_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cvdr_vp_rd_sof_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cvdr_vp_wr_dropped_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cvdr_vp_wr_dropped_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cam_dropped_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_isr_cam_dropped_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_s : 32;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_MEM_CTRL_SP_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MEM_CTRL_SP_mem_ctrl_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_MEM_CTRL_SP_mem_ctrl_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timeout : 32;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_TIME_OUT_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_TIME_OUT_timeout_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_TIME_OUT_timeout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int soft_vsync : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_VSYNC_CTRL_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_VSYNC_CTRL_soft_vsync_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_VSYNC_CTRL_soft_vsync_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cam_trigger : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_CTRL_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_CTRL_cam_trigger_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_CAM_CTRL_cam_trigger_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awnsaid : 3;
        unsigned int reserved_0: 1;
        unsigned int arnsaid : 3;
        unsigned int reserved_1: 4;
        unsigned int prot : 1;
        unsigned int reserved_2: 20;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_awnsaid_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_awnsaid_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_arnsaid_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_arnsaid_END (6)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_prot_START (11)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECU_CTRL_prot_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_cnt : 32;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_FRAMECOUNTER_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FRAMECOUNTER_frame_cnt_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_FRAMECOUNTER_frame_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int go : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_GO_BIT_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_GO_BIT_go_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_GO_BIT_go_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cvdr_security : 1;
        unsigned int top_security : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_SECURITY_CFG_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECURITY_CFG_cvdr_security_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECURITY_CFG_cvdr_security_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECURITY_CFG_top_security_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_SECURITY_CFG_top_security_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ims_cam_eof_s : 1;
        unsigned int ims_pipe_irq_s : 1;
        unsigned int ims_cvdr_vp_wr_eof_s : 1;
        unsigned int ims_cvdr_vp_rd_eof_s : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_cam_eof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_cam_eof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_pipe_irq_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_pipe_irq_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_cvdr_vp_wr_eof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_cvdr_vp_wr_eof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_cvdr_vp_rd_eof_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_IMS_S_ims_cvdr_vp_rd_eof_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ris_cam_eof_s : 1;
        unsigned int ris_pipe_irq_s : 1;
        unsigned int ris_cvdr_vp_wr_eof_s : 1;
        unsigned int ris_cvdr_vp_rd_eof_s : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_cam_eof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_cam_eof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_pipe_irq_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_pipe_irq_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_cvdr_vp_wr_eof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_cvdr_vp_wr_eof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_cvdr_vp_rd_eof_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_RIS_S_ris_cvdr_vp_rd_eof_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mis_cam_eof_s : 1;
        unsigned int mis_pipe_irq_s : 1;
        unsigned int mis_cvdr_vp_wr_eof_s : 1;
        unsigned int mis_cvdr_vp_rd_eof_s : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_cam_eof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_cam_eof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_pipe_irq_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_pipe_irq_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_cvdr_vp_wr_eof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_cvdr_vp_wr_eof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_cvdr_vp_rd_eof_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_MIS_S_mis_cvdr_vp_rd_eof_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icr_cam_eof_s : 1;
        unsigned int icr_pipe_irq_s : 1;
        unsigned int icr_cvdr_vp_wr_eof_s : 1;
        unsigned int icr_cvdr_vp_rd_eof_s : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_cam_eof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_cam_eof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_pipe_irq_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_pipe_irq_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_cvdr_vp_wr_eof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_cvdr_vp_wr_eof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_cvdr_vp_rd_eof_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ICR_S_icr_cvdr_vp_rd_eof_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isr_cam_eof_s : 1;
        unsigned int isr_pipe_irq_s : 1;
        unsigned int isr_cvdr_vp_wr_eof_s : 1;
        unsigned int isr_cvdr_vp_rd_eof_s : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_cam_eof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_cam_eof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_pipe_irq_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_pipe_irq_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_cvdr_vp_wr_eof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_cvdr_vp_wr_eof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_cvdr_vp_rd_eof_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_EOP_IRQ_ISR_S_isr_cvdr_vp_rd_eof_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ims_cam_overflow_s : 1;
        unsigned int ims_image_size_err_s : 1;
        unsigned int ims_cvdr_axi_wr_resp_err_s : 1;
        unsigned int ims_cvdr_axi_rd_resp_err_s : 1;
        unsigned int ims_cvdr_axi_wr_full_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cam_overflow_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cam_overflow_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_image_size_err_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_image_size_err_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cvdr_axi_wr_resp_err_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cvdr_axi_wr_resp_err_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cvdr_axi_rd_resp_err_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cvdr_axi_rd_resp_err_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cvdr_axi_wr_full_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_IMS_S_ims_cvdr_axi_wr_full_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ris_cam_overflow_s : 1;
        unsigned int ris_image_size_err_s : 1;
        unsigned int ris_cvdr_axi_wr_resp_err_s : 1;
        unsigned int ris_cvdr_axi_rd_resp_err_s : 1;
        unsigned int ris_cvdr_axi_wr_full_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cam_overflow_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cam_overflow_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_image_size_err_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_image_size_err_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cvdr_axi_wr_resp_err_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cvdr_axi_wr_resp_err_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cvdr_axi_rd_resp_err_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cvdr_axi_rd_resp_err_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cvdr_axi_wr_full_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_RIS_S_ris_cvdr_axi_wr_full_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mis_cam_overflow_s : 1;
        unsigned int mis_image_size_err_s : 1;
        unsigned int mis_cvdr_axi_wr_resp_err_s : 1;
        unsigned int mis_cvdr_axi_rd_resp_err_s : 1;
        unsigned int mis_cvdr_axi_wr_full_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cam_overflow_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cam_overflow_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_image_size_err_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_image_size_err_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cvdr_axi_wr_resp_err_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cvdr_axi_wr_resp_err_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cvdr_axi_rd_resp_err_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cvdr_axi_rd_resp_err_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cvdr_axi_wr_full_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_MIS_S_mis_cvdr_axi_wr_full_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icr_cam_overflow_s : 1;
        unsigned int icr_image_size_err_s : 1;
        unsigned int icr_cvdr_axi_wr_resp_err_s : 1;
        unsigned int icr_cvdr_axi_rd_resp_err_s : 1;
        unsigned int icr_cvdr_axi_wr_full_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cam_overflow_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cam_overflow_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_image_size_err_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_image_size_err_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cvdr_axi_wr_resp_err_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cvdr_axi_wr_resp_err_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cvdr_axi_rd_resp_err_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cvdr_axi_rd_resp_err_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cvdr_axi_wr_full_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ICR_S_icr_cvdr_axi_wr_full_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isr_cam_overflow_s : 1;
        unsigned int isr_image_size_err_s : 1;
        unsigned int isr_cvdr_axi_wr_resp_err_s : 1;
        unsigned int isr_cvdr_axi_rd_resp_err_s : 1;
        unsigned int isr_cvdr_axi_wr_full_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cam_overflow_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cam_overflow_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_image_size_err_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_image_size_err_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cvdr_axi_wr_resp_err_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cvdr_axi_wr_resp_err_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cvdr_axi_rd_resp_err_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cvdr_axi_rd_resp_err_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cvdr_axi_wr_full_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_ERR_IRQ_ISR_S_isr_cvdr_axi_wr_full_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ims_cam_sof_s : 1;
        unsigned int ims_cvdr_vp_wr_sof_s : 1;
        unsigned int ims_cvdr_vp_rd_sof_s : 1;
        unsigned int ims_cvdr_vp_wr_dropped_s : 1;
        unsigned int ims_cam_dropped_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cam_sof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cam_sof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cvdr_vp_wr_sof_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cvdr_vp_wr_sof_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cvdr_vp_rd_sof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cvdr_vp_rd_sof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cvdr_vp_wr_dropped_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cvdr_vp_wr_dropped_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cam_dropped_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_IMS_S_ims_cam_dropped_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ris_cam_sof_s : 1;
        unsigned int ris_cvdr_vp_wr_sof_s : 1;
        unsigned int ris_cvdr_vp_rd_sof_s : 1;
        unsigned int ris_cvdr_vp_wr_dropped_s : 1;
        unsigned int ris_cam_dropped_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cam_sof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cam_sof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cvdr_vp_wr_sof_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cvdr_vp_wr_sof_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cvdr_vp_rd_sof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cvdr_vp_rd_sof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cvdr_vp_wr_dropped_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cvdr_vp_wr_dropped_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cam_dropped_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_RIS_S_ris_cam_dropped_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mis_cam_sof_s : 1;
        unsigned int mis_cvdr_vp_wr_sof_s : 1;
        unsigned int mis_cvdr_vp_rd_sof_s : 1;
        unsigned int mis_cvdr_vp_wr_dropped_s : 1;
        unsigned int mis_cam_dropped_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cam_sof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cam_sof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cvdr_vp_wr_sof_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cvdr_vp_wr_sof_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cvdr_vp_rd_sof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cvdr_vp_rd_sof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cvdr_vp_wr_dropped_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cvdr_vp_wr_dropped_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cam_dropped_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_MIS_S_mis_cam_dropped_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icr_cam_sof_s : 1;
        unsigned int icr_cvdr_vp_wr_sof_s : 1;
        unsigned int icr_cvdr_vp_rd_sof_s : 1;
        unsigned int icr_cvdr_vp_wr_dropped_s : 1;
        unsigned int icr_cam_dropped_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cam_sof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cam_sof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cvdr_vp_wr_sof_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cvdr_vp_wr_sof_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cvdr_vp_rd_sof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cvdr_vp_rd_sof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cvdr_vp_wr_dropped_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cvdr_vp_wr_dropped_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cam_dropped_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ICR_S_icr_cam_dropped_s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isr_cam_sof_s : 1;
        unsigned int isr_cvdr_vp_wr_sof_s : 1;
        unsigned int isr_cvdr_vp_rd_sof_s : 1;
        unsigned int isr_cvdr_vp_wr_dropped_s : 1;
        unsigned int isr_cam_dropped_s : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_UNION;
#endif
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cam_sof_s_START (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cam_sof_s_END (0)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cvdr_vp_wr_sof_s_START (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cvdr_vp_wr_sof_s_END (1)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cvdr_vp_rd_sof_s_START (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cvdr_vp_rd_sof_s_END (2)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cvdr_vp_wr_dropped_s_START (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cvdr_vp_wr_dropped_s_END (3)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cam_dropped_s_START (4)
#define SOC_AONN_nManager_MINI_ISP_SUBYS_DBG_IRQ_ISR_S_isr_cam_dropped_s_END (4)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
