// ******************************************************************************
// Copyright     :  Copyright (C) 2018, Hisilicon Technologies Co., Ltd.
// File name     :  sub_ctrl_drv_priv.h
// Version       :  1.0
// Date          :  2018-01-03
// Description   :  Define all registers/tables for HiStarISP
// Others        :  Generated automatically by nManager V4.0
// ******************************************************************************

#ifndef __SUB_CTRL_DRV_PRIV_H__
#define __SUB_CTRL_DRV_PRIV_H__

/* Define the union U_TOP_AXI_CFG0 */
union u_top_axi_cfg0 {
	/* Define the struct bits */
	struct {
		unsigned int    jpg_dw_axi_gatedclock_en : 1   ; /* [0]  */
		unsigned int    jpg_smmu_force_clk_on : 1   ; /* [1]  */
		unsigned int    jpg_dma_force_clk_on  : 1   ; /* [2]  */
		unsigned int    jpg_top_apb_force_clk_on : 1   ; /* [3]  */
		unsigned int    jpg_smmu_master_clken : 1   ; /* [4]  */
		unsigned int    cmdlst_clken          : 1   ; /* [5]  */
		unsigned int    reserved_0            : 10  ; /* [15..6]  */
		unsigned int    control_disable_axi_data_packing : 1   ; /* [16]  */
		unsigned int    mst_priority_fd       : 1   ; /* [17]  */
		unsigned int    mst_priority_cvdr     : 1   ; /* [18]  */
		unsigned int    reserved_1            : 13  ; /* [31..19]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_DMA_CRG_CFG1 */
union u_dma_crg_cfg1 {
	/* Define the struct bits */
	struct {
		unsigned int    cvdr_soft_rst         : 1   ; /* [0]  */
		unsigned int    smmu_soft_rst         : 1   ; /* [1]  */
		unsigned int    smmu_master_soft_rst  : 1   ; /* [2]  */
		unsigned int    cmdlst_soft_rst       : 1   ; /* [3]  */
		unsigned int    reserved_0            : 28  ; /* [31..4]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CVDR_MEM_CFG */
union u_cvdr_mem_cfg   {
	/* Define the struct bits  */
	struct {
		unsigned int cvdr_mem_ctrl          : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_CVDR_IRQ_REG0 */
union u_cvdr_irq_reg0 {
	/* Define the struct bits */
	struct {
		unsigned int    cvdr_irq_clr          : 8   ; /* [7..0]  */
		unsigned int    reserved_0            : 24  ; /* [31..8]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CVDR_IRQ_REG1 */
union u_cvdr_irq_reg1 {
	/* Define the struct bits */
	struct {
		unsigned int    cvdr_irq_mask         : 8   ; /* [7..0]  */
		unsigned int    reserved_0            : 24  ; /* [31..8]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CVDR_IRQ_REG2 */
union u_cvdr_irq_reg2 {
	/* Define the struct bits */
	struct {
		unsigned int    cvdr_irq_state_mask   : 8   ; /* [7..0]  */
		unsigned int    reserved_0            : 8   ; /* [15..8]  */
		unsigned int    cvdr_irq_state_raw    : 8   ; /* [23..16]  */
		unsigned int    reserved_1            : 8   ; /* [31..24]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_CTRL */
union u_cmdlst_ctrl {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_ctrl_chn0      : 2   ; /* [1..0]  */
		unsigned int    cmdlst_ctrl_chn1      : 2   ; /* [3..2]  */
		unsigned int    reserved_0            : 28  ; /* [31..4]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_CHN0 */
union u_cmdlst_chn0 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_eof_mask_chn0  : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_CHN1 */
union u_cmdlst_chn1 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_eof_mask_chn1  : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_R8_IRQ_REG0 */
union u_cmdlst_r8_irq_reg0 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_r8_irq_clr     : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_R8_IRQ_REG1 */
union u_cmdlst_r8_irq_reg1 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_r8_irq_mask    : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_R8_IRQ_REG2 */
union u_cmdlst_r8_irq_reg2 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_r8_irq_state_mask : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 14  ; /* [15..2]  */
		unsigned int    cmdlst_r8_irq_state_raw : 2   ; /* [17..16]  */
		unsigned int    reserved_1            : 14  ; /* [31..18]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_ACPU_IRQ_REG0 */
union u_cmdlst_acpu_irq_reg0 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_acpu_irq_clr   : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_ACPU_IRQ_REG1 */
union u_cmdlst_acpu_irq_reg1 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_acpu_irq_mask  : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_ACPU_IRQ_REG2 */
union u_cmdlst_acpu_irq_reg2 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_acpu_irq_state_mask : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 14  ; /* [15..2]  */
		unsigned int    cmdlst_acpu_irq_state_raw : 2   ; /* [17..16]  */
		unsigned int    reserved_1            : 14  ; /* [31..18]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_IVP_IRQ_REG0 */
union u_cmdlst_ivp_irq_reg0 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_ivp_irq_clr    : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_IVP_IRQ_REG1 */
union u_cmdlst_ivp_irq_reg1 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_ivp_irq_mask   : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_CMDLST_IVP_IRQ_REG2 */
union u_cmdlst_ivp_irq_reg2 {
	/* Define the struct bits */
	struct {
		unsigned int    cmdlst_ivp_irq_state_mask : 2   ; /* [1..0]  */
		unsigned int    reserved_0            : 14  ; /* [15..2]  */
		unsigned int    cmdlst_ivp_irq_state_raw : 2   ; /* [17..16]  */
		unsigned int    reserved_1            : 14  ; /* [31..18]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPG_FLUX_CTRL0_0 */
union u_jpg_flux_ctrl0_0 {
	/* Define the struct bits  */
	struct {
		unsigned int flux_ctrl0_cvdr_r      : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_FLUX_CTRL0_1 */
union u_jpg_flux_ctrl0_1 {
	/* Define the struct bits  */
	struct {
		unsigned int flux_ctrl1_cvdr_r      : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_FLUX_CTRL1_0 */
union u_jpg_flux_ctrl1_0 {
	/* Define the struct bits  */
	struct {
		unsigned int flux_ctrl0_cvdr_w      : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_FLUX_CTRL1_1 */
union u_jpg_flux_ctrl1_1 {
	/* Define the struct bits  */
	struct {
		unsigned int flux_ctrl1_cvdr_w      : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_RO_STATE */
union u_jpg_ro_state {
	/* Define the struct bits */
	struct {
		unsigned int    prefetch_stop_ok_jpgenc : 1   ; /* [0]  */
		unsigned int    prefetch_stop_ok_jpgdec : 1   ; /* [1]  */
		unsigned int    reserved_0            : 6   ; /* [7..2]  */
		unsigned int    jpg_smmu_idle         : 1   ; /* [8]  */
		unsigned int    jpg_cvdr_busy         : 1   ; /* [9]  */
		unsigned int    reserved_1            : 6   ; /* [15..10]  */
		unsigned int    jpg_axi_dlock_irq     : 1   ; /* [16]  */
		unsigned int    jpg_axi_dlock_wr      : 1   ; /* [17]  */
		unsigned int    jpg_axi_dlock_slv     : 1   ; /* [18]  */
		unsigned int    jpg_axi_dlock_mst     : 1   ; /* [19]  */
		unsigned int    jpg_axi_dlock_id      : 8   ; /* [27..20]  */
		unsigned int    reserved_2            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPGENC_CRG_CFG0 */
union u_jpgenc_crg_cfg0 {
	/* Define the struct bits */
	struct {
		unsigned int    jpgenc_clken          : 1   ; /* [0]  */
		unsigned int    reserved_0            : 31  ; /* [31..1]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPGENC_CRG_CFG1 */
union u_jpgenc_crg_cfg1 {
	/* Define the struct bits */
	struct {
		unsigned int    jpgenc_soft_rst       : 1   ; /* [0]  */
		unsigned int    reserved_0            : 15  ; /* [15..1]  */
		unsigned int    prefetch_stop_jpgenc  : 1   ; /* [16]  */
		unsigned int    reserved_1            : 15  ; /* [31..17]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPGENC_MEM_CFG */
union u_jpgenc_mem_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    jpgenc_mem_ctrl       : 3   ; /* [2..0]  */
		unsigned int    reserved_0            : 29  ; /* [31..3]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPGENC_IRQ_REG0 */
union u_jpgenc_irq_reg0 {
	/* Define the struct bits */
	struct {
		unsigned int    jpgenc_irq_clr        : 5   ; /* [4..0]  */
		unsigned int    reserved_0            : 11  ; /* [15..5]  */
		unsigned int    jpgenc_irq_force      : 5   ; /* [20..16]  */
		unsigned int    reserved_1            : 11  ; /* [31..21]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPGENC_IRQ_REG1 */
union u_jpgenc_irq_reg1 {
	/* Define the struct bits */
	struct {
		unsigned int    jpgenc_irq_mask       : 5   ; /* [4..0]  */
		unsigned int    reserved_0            : 27  ; /* [31..5]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPGENC_IRQ_REG2 */
union u_jpgenc_irq_reg2 {
	/* Define the struct bits */
	struct {
		unsigned int    jpgenc_irq_state_mask : 5   ; /* [4..0]  */
		unsigned int    reserved_0            : 11  ; /* [15..5]  */
		unsigned int    jpgenc_irq_state_raw  : 5   ; /* [20..16]  */
		unsigned int    reserved_1            : 11  ; /* [31..21]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SLAM_CRG_CFG0 */
union u_slam_crg_cfg0 {
	/* Define the struct bits */
	struct {
		unsigned int    slam_clken            : 1   ; /* [0]  */
		unsigned int    reserved_0            : 31  ; /* [31..1]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SLAM_CRG_CFG1 */
union u_slam_crg_cfg1 {
	/* Define the struct bits */
	struct {
		unsigned int    slam_soft_rst         : 1   ; /* [0]  */
		unsigned int    reserved_0            : 31  ; /* [31..1]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SLAM_CRG_CFG2 */
union u_slam_crg_cfg2 {
	/* Define the struct bits */
	struct {
		unsigned int    slam_force_clk_on     : 1   ; /* [0]  */
		unsigned int    reserved_0            : 31  ; /* [31..1]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SLAM_MEM_CFG1 */
union u_slam_mem_cfg1 {
	/* Define the struct bits */
	struct {
		unsigned int    slam_pwr_mem_ctrl_sp  : 3   ; /* [2..0]  */
		unsigned int    reserved_0            : 29  ; /* [31..3]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SLAM_IRQ_REG0 */
union u_slam_irq_reg0 {
	/* Define the struct bits */
	struct {
		unsigned int    slam_irq_clr          : 14  ; /* [13..0]  */
		unsigned int    reserved_0            : 2   ; /* [15..14]  */
		unsigned int    slam_irq_force        : 14  ; /* [29..16]  */
		unsigned int    reserved_1            : 2   ; /* [31..30]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SLAM_IRQ_REG1 */
union u_slam_irq_reg1 {
	/* Define the struct bits */
	struct {
		unsigned int    slam_irq_mask         : 14  ; /* [13..0]  */
		unsigned int    reserved_0            : 2   ; /* [15..14]  */
		unsigned int    slam_irq_outen        : 2   ; /* [17..16]  */
		unsigned int    reserved_1            : 14  ; /* [31..18]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SLAM_IRQ_REG2 */
union u_slam_irq_reg2 {
	/* Define the struct bits */
	struct {
		unsigned int    slam_irq_state_mask   : 14  ; /* [13..0]  */
		unsigned int    reserved_0            : 2   ; /* [15..14]  */
		unsigned int    slam_irq_state_raw    : 14  ; /* [29..16]  */
		unsigned int    reserved_1            : 2   ; /* [31..30]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_JPG_DEBUG_0 */
union u_jpg_debug_0 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_info_0           : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_DEBUG_1 */
union u_jpg_debug_1 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_info_1           : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_DEBUG_2 */
union u_jpg_debug_2 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_info_2           : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_DEBUG_3 */
union u_jpg_debug_3 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_info_3           : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_JPG_SEC_CTRL_S */
union u_jpg_sec_ctrl_s {
	/* Define the struct bits */
	struct {
		unsigned int    top_tz_secure_n       : 1   ; /* [0]  */
		unsigned int    jpgenc_tz_secure_n    : 1   ; /* [1]  */
		unsigned int    jpgdec_tz_secure_n    : 1   ; /* [2]  */
		unsigned int    fd_tz_secure_n        : 1   ; /* [3]  */
		unsigned int    cpe_tz_secure_n       : 1   ; /* [4]  */
		unsigned int    slam_tz_secure_n      : 1   ; /* [5]  */
		unsigned int    reserved_0            : 26  ; /* [31..6]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

// ==============================================================================
/* Define the global struct */
struct s_sub_ctrl_regs_type {
	union u_top_axi_cfg0                  	top_axi_cfg0                     ; /* 0x0 */
	union u_dma_crg_cfg1                  	dma_crg_cfg1                     ; /* 0x4 */
	union u_cvdr_mem_cfg                  	cvdr_mem_cfg                     ; /* 0x8 */
	unsigned int                    		reserved_0                       ; /* 0xc */
	union u_cvdr_irq_reg0                 	cvdr_irq_reg0                    ; /* 0x10 */
	union u_cvdr_irq_reg1                 	cvdr_irq_reg1                    ; /* 0x14 */
	union u_cvdr_irq_reg2                 	cvdr_irq_reg2                    ; /* 0x18 */
	unsigned int                    		reserved_1[9]                    ; /* 0x1c~0x3c */
	union u_cmdlst_ctrl                   	cmdlst_ctrl                      ; /* 0x40 */
	union u_cmdlst_chn0                   	cmdlst_chn0                      ; /* 0x44 */
	union u_cmdlst_chn1                   	cmdlst_chn1                      ; /* 0x48 */
	unsigned int                    		reserved_2[4]                    ; /* 0x4c~0x58 */
	union u_cmdlst_r8_irq_reg0            	cmdlst_r8_irq_reg0               ; /* 0x5c */
	union u_cmdlst_r8_irq_reg1            	cmdlst_r8_irq_reg1               ; /* 0x60 */
	union u_cmdlst_r8_irq_reg2            	cmdlst_r8_irq_reg2               ; /* 0x64 */
	union u_cmdlst_acpu_irq_reg0          	cmdlst_acpu_irq_reg0             ; /* 0x68 */
	union u_cmdlst_acpu_irq_reg1          	cmdlst_acpu_irq_reg1             ; /* 0x6c */
	union u_cmdlst_acpu_irq_reg2          	cmdlst_acpu_irq_reg2             ; /* 0x70 */
	union u_cmdlst_ivp_irq_reg0           	cmdlst_ivp_irq_reg0              ; /* 0x74 */
	union u_cmdlst_ivp_irq_reg1           	cmdlst_ivp_irq_reg1              ; /* 0x78 */
	union u_cmdlst_ivp_irq_reg2           	cmdlst_ivp_irq_reg2              ; /* 0x7c */
	union u_jpg_flux_ctrl0_0              	jpg_flux_ctrl0_0                 ; /* 0x80 */
	union u_jpg_flux_ctrl0_1              	jpg_flux_ctrl0_1                 ; /* 0x84 */
	union u_jpg_flux_ctrl1_0              	jpg_flux_ctrl1_0                 ; /* 0x88 */
	union u_jpg_flux_ctrl1_1              	jpg_flux_ctrl1_1                 ; /* 0x8c */
	unsigned int                  	  		reserved_3[12]                   ; /* 0x90~0xbc */
	union u_jpg_ro_state                  	jpg_ro_state                     ; /* 0xc0 */
	unsigned int                    		reserved_4[15]                   ; /* 0xc4~0xfc */
	union u_jpgenc_crg_cfg0               	jpgenc_crg_cfg0                  ; /* 0x100 */
	union u_jpgenc_crg_cfg1               	jpgenc_crg_cfg1                  ; /* 0x104 */
	union u_jpgenc_mem_cfg                	jpgenc_mem_cfg                   ; /* 0x108 */
	unsigned int                    		reserved_5                       ; /* 0x10c */
	union u_jpgenc_irq_reg0               	jpgenc_irq_reg0                  ; /* 0x110 */
	union u_jpgenc_irq_reg1               	jpgenc_irq_reg1                  ; /* 0x114 */
	union u_jpgenc_irq_reg2               	jpgenc_irq_reg2                  ; /* 0x118 */
	unsigned int                    		reserved_6[89]                   ; /* 0x11c~0x27c */
	union u_slam_crg_cfg0                 	slam_crg_cfg0                    ; /* 0x280 */
	union u_slam_crg_cfg1                 	slam_crg_cfg1                    ; /* 0x284 */
	union u_slam_crg_cfg2                 	slam_crg_cfg2                    ; /* 0x288 */
	union u_slam_mem_cfg1                 	slam_mem_cfg1                    ; /* 0x28c */
	union u_slam_irq_reg0                 	slam_irq_reg0                    ; /* 0x290 */
	union u_slam_irq_reg1                 	slam_irq_reg1                    ; /* 0x294 */
	union u_slam_irq_reg2                 	slam_irq_reg2                    ; /* 0x298 */
	unsigned int                    		reserved_7[89]                   ; /* 0x29c~0x3fc */
	union u_jpg_debug_0                   	jpg_debug_0                      ; /* 0x400 */
	union u_jpg_debug_1                   	jpg_debug_1                      ; /* 0x404 */
	union u_jpg_debug_2                   	jpg_debug_2                      ; /* 0x408 */
	union u_jpg_debug_3                   	jpg_debug_3                      ; /* 0x40c */
	unsigned int                    		reserved_8[252]                  ; /* 0x410~0x7fc */
	union u_jpg_sec_ctrl_s                	jpg_sec_ctrl_s                   ; /* 0x800 */
};

/* Declare the struct pointor of the module SUB_CTRL */
extern struct s_sub_ctrl_regs_type *gopsub_ctrlallreg;

#endif /* __SUB_CTRL_DRV_PRIV_H__ */
