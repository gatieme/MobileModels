// ******************************************************************************
// Copyright     :  Copyright (C) 2018, Hisilicon Technologies Co., Ltd.
// File name     :  slam_drv_priv.h
// Author        :  HerveDANIEL
// Version       :  1.0
// Date          :  2018-01-03
// Description   :  Define all registers/tables for HiStarISP
// Others        :  Generated automatically by nManager V4.0
// History       :  HerveDANIEL 2018-01-03 Create file
// ******************************************************************************

#ifndef __SLAM_DRV_PRIV_H__
#define __SLAM_DRV_PRIV_H__

/* Define the union U_SLAM_CFG */
union u_slam_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    pyramid_en            : 1   ; /* [0]  */
		unsigned int    gsblur_en             : 1   ; /* [1]  */
		unsigned int    fast_en               : 1   ; /* [2]  */
		unsigned int    nms_en                : 1   ; /* [3]  */
		unsigned int    orient_en             : 1   ; /* [4]  */
		unsigned int    brief_en              : 1   ; /* [5]  */
		unsigned int    freak_en              : 1   ; /* [6]  */
		unsigned int    scoremap_en           : 1   ; /* [7]  */
		unsigned int    reserved_0            : 24  ; /* [31..8]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_IMAGE_SIZE */
union u_image_size {
	/* Define the struct bits */
	struct {
		unsigned int    width                 : 10  ; /* [9..0]  */
		unsigned int    reserved_0            : 6   ; /* [15..10]  */
		unsigned int    height                : 10  ; /* [25..16]  */
		unsigned int    reserved_1            : 6   ; /* [31..26]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_PYRAMID_INC_CFG */
union u_pyramid_inc_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    scl_inc               : 20  ; /* [19..0]  */
		unsigned int    reserved_0            : 12  ; /* [31..20]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_PYRAMID_VCROP_CFGB */
union u_pyramid_vcrop_cfgb {
	/* Define the struct bits */
	struct {
		unsigned int    scl_vbottom           : 28  ; /* [27..0]  */
		unsigned int    reserved_0            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_PYRAMID_VCROP_CFGT */
union u_pyramid_vcrop_cfgt {
	/* Define the struct bits */
	struct {
		unsigned int    scl_vtop              : 28  ; /* [27..0]  */
		unsigned int    reserved_0            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_PYRAMID_HCROP_CFGR */
union u_pyramid_hcrop_cfgr {
	/* Define the struct bits */
	struct {
		unsigned int    scl_hright            : 28  ; /* [27..0]  */
		unsigned int    reserved_0            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_PYRAMID_HCROP_CFGL */
union u_pyramid_hcrop_cfgl {
	/* Define the struct bits */
	struct {
		unsigned int    scl_hleft             : 28  ; /* [27..0]  */
		unsigned int    reserved_0            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_GSBLUR_COEF_01 */
union u_gsblur_coef_01 {
	/* Define the struct bits */
	struct {
		unsigned int    coeff_gauss_1         : 10  ; /* [9..0]  */
		unsigned int    reserved_0            : 6   ; /* [15..10]  */
		unsigned int    coeff_gauss_0         : 10  ; /* [25..16]  */
		unsigned int    reserved_1            : 6   ; /* [31..26]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_GSBLUR_COEF_23 */
union u_gsblur_coef_23 {
	/* Define the struct bits */
	struct {
		unsigned int    coeff_gauss_3         : 10  ; /* [9..0]  */
		unsigned int    reserved_0            : 6   ; /* [15..10]  */
		unsigned int    coeff_gauss_2         : 10  ; /* [25..16]  */
		unsigned int    reserved_1            : 6   ; /* [31..26]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_THRESHOLD_CFG */
union u_threshold_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    min_th                : 8   ; /* [7..0]  */
		unsigned int    ini_th                : 8   ; /* [15..8]  */
		unsigned int    reserved_0            : 16  ; /* [31..16]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_NMS_WIN_CFG */
union u_nms_win_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    nmscell_v             : 4   ; /* [3..0]  */
		unsigned int    nmscell_h             : 5   ; /* [8..4]  */
		unsigned int    reserved_0            : 23  ; /* [31..9]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_SCORE_HIST */
union u_score_hist {
	/* Define the struct bits */
	struct {
		unsigned int    score_histbin         : 12  ; /* [11..0]  */
		unsigned int    reserved_0            : 20  ; /* [31..12]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_BRIEF_PATTERN */
union u_brief_pattern {
	/* Define the struct bits */
	struct {
		unsigned int    pattern_x0            : 6   ; /* [5..0]  */
		unsigned int    reserved_0            : 2   ; /* [7..6]  */
		unsigned int    pattern_y0            : 6   ; /* [13..8]  */
		unsigned int    reserved_1            : 2   ; /* [15..14]  */
		unsigned int    pattern_x1            : 6   ; /* [21..16]  */
		unsigned int    reserved_2            : 2   ; /* [23..22]  */
		unsigned int    pattern_y1            : 6   ; /* [29..24]  */
		unsigned int    reserved_3            : 2   ; /* [31..30]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_DEBUG_INFO */
union u_debug_info {
	/* Define the struct bits  */
	struct {
		unsigned int debug_info             : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
// ==============================================================================
/* Define the global struct */
struct s_slam_regs_type {
	union u_slam_cfg                      	slam_cfg                         ; /* 0x0 */
	unsigned int                    		reserved_0[3]                    ; /* 0x1~0x3 */
	union u_image_size                    	image_size                       ; /* 0x4 */
	unsigned int                    		reserved_1[3]                    ; /* 0x5~0x7 */
	union u_pyramid_inc_cfg               	pyramid_inc_cfg                  ; /* 0x8 */
	unsigned int                    		reserved_2[3]                    ; /* 0x9~0xb */
	union u_pyramid_vcrop_cfgb            	pyramid_vcrop_cfgb               ; /* 0xc */
	unsigned int                    		reserved_3[3]                    ; /* 0xd~0xf */
	union u_pyramid_vcrop_cfgt            	pyramid_vcrop_cfgt               ; /* 0x10 */
	unsigned int                    		reserved_4[3]                    ; /* 0x11~0x13 */
	union u_pyramid_hcrop_cfgr            	pyramid_hcrop_cfgr               ; /* 0x14 */
	unsigned int                    		reserved_5[3]                    ; /* 0x15~0x17 */
	union u_pyramid_hcrop_cfgl            	pyramid_hcrop_cfgl               ; /* 0x18 */
	unsigned int                    		reserved_6[3]                    ; /* 0x19~0x1b */
	union u_gsblur_coef_01                	gsblur_coef_01                   ; /* 0x1c */
	unsigned int                    		reserved_7[3]                    ; /* 0x1d~0x1f */
	union u_gsblur_coef_23                	gsblur_coef_23                   ; /* 0x20 */
	unsigned int                    		reserved_8[3]                    ; /* 0x21~0x23 */
	union u_threshold_cfg                 	threshold_cfg                    ; /* 0x24 */
	unsigned int                    		reserved_9[3]                    ; /* 0x25~0x27 */
	union u_nms_win_cfg                   	nms_win_cfg                      ; /* 0x28 */
	unsigned int                    		reserved_10[215]                 ; /* 0x29~0xff */
	union u_score_hist                    	score_hist[63]                   ; /* 0x100~0x1f8 */
	unsigned int                    		reserved_11[519]                 ; /* 0x1f9~0x3ff */
	union u_brief_pattern                 	brief_pattern[256]               ; /* 0x400~0x7fc */
	unsigned int                    		reserved_12[259]                 ; /* 0x7fd~0x8ff */
	union u_debug_info                    	debug_info                       ; /* 0x900 */
};

/* Declare the struct pointor of the module SLAM */
extern struct s_slam_regs_type *gopslamallreg;

#endif /* __SLAM_DRV_PRIV_H__ */
