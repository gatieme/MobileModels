// ******************************************************************************
// Copyright     :  Copyright (C) 2018, Hisilicon Technologies Co., Ltd.
// File name     :  axi_jpeg_drv_priv.h
// Author        :  AnthonySixta
// Version       :  1.0
// Date          :  2018-01-03
// Description   :  Define all registers/tables for HiStarISP
// Others        :  Generated automatically by nManager V4.0
// History       :  AnthonySixta 2018-01-03 Create file
// ******************************************************************************

#ifndef __AXI_JPEG_DRV_PRIV_H__
#define __AXI_JPEG_DRV_PRIV_H__

/* Define the union U_AXI_JPEG_CVDR_CFG */
union u_axi_jpeg_cvdr_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    axiwrite_du_threshold : 6   ; /* [5..0]  */
		unsigned int    reserved_0            : 2   ; /* [7..6]  */
		unsigned int    du_threshold_reached  : 8   ; /* [15..8]  */
		unsigned int    max_axiread_id        : 5   ; /* [20..16]  */
		unsigned int    reserved_1            : 3   ; /* [23..21]  */
		unsigned int    max_axiwrite_id       : 5   ; /* [28..24]  */
		unsigned int    reserved_2            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_CVDR_DEBUG_EN */
union u_axi_jpeg_cvdr_debug_en {
	/* Define the struct bits */
	struct {
		unsigned int    wr_peak_en            : 1   ; /* [0]  */
		unsigned int    reserved_0            : 7   ; /* [7..1]  */
		unsigned int    rd_peak_en            : 1   ; /* [8]  */
		unsigned int    reserved_1            : 23  ; /* [31..9]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_CVDR_DEBUG */
union u_axi_jpeg_cvdr_debug {
	/* Define the struct bits */
	struct {
		unsigned int    wr_peak               : 8   ; /* [7..0]  */
		unsigned int    rd_peak               : 8   ; /* [15..8]  */
		unsigned int    reserved_0            : 16  ; /* [31..16]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_CVDR_WR_QOS_CFG */
union u_axi_jpeg_cvdr_wr_qos_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    wr_qos_threshold_01_stop : 4   ; /* [3..0]  */
		unsigned int    wr_qos_threshold_01_start : 4   ; /* [7..4]  */
		unsigned int    wr_qos_threshold_10_stop : 4   ; /* [11..8]  */
		unsigned int    wr_qos_threshold_10_start : 4   ; /* [15..12]  */
		unsigned int    wr_qos_threshold_11_stop : 4   ; /* [19..16]  */
		unsigned int    wr_qos_threshold_11_start : 4   ; /* [23..20]  */
		unsigned int    reserved_0            : 2   ; /* [25..24]  */
		unsigned int    wr_qos_min            : 2   ; /* [27..26]  */
		unsigned int    wr_qos_max            : 2   ; /* [29..28]  */
		unsigned int    wr_qos_sr             : 2   ; /* [31..30]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_CVDR_RD_QOS_CFG */
union u_axi_jpeg_cvdr_rd_qos_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    rd_qos_threshold_01_stop : 4   ; /* [3..0]  */
		unsigned int    rd_qos_threshold_01_start : 4   ; /* [7..4]  */
		unsigned int    rd_qos_threshold_10_stop : 4   ; /* [11..8]  */
		unsigned int    rd_qos_threshold_10_start : 4   ; /* [15..12]  */
		unsigned int    rd_qos_threshold_11_stop : 4   ; /* [19..16]  */
		unsigned int    rd_qos_threshold_11_start : 4   ; /* [23..20]  */
		unsigned int    reserved_0            : 2   ; /* [25..24]  */
		unsigned int    rd_qos_min            : 2   ; /* [27..26]  */
		unsigned int    rd_qos_max            : 2   ; /* [29..28]  */
		unsigned int    rd_qos_sr             : 2   ; /* [31..30]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_FORCE_CLK */
union u_axi_jpeg_force_clk {
	/* Define the struct bits */
	struct {
		unsigned int    force_vprd_clk_on     : 1   ; /* [0]  */
		unsigned int    force_vpwr_clk_on     : 1   ; /* [1]  */
		unsigned int    force_nrrd_clk_on     : 1   ; /* [2]  */
		unsigned int    force_nrwr_clk_on     : 1   ; /* [3]  */
		unsigned int    force_axi_rd_clk_on   : 1   ; /* [4]  */
		unsigned int    force_axi_wr_clk_on   : 1   ; /* [5]  */
		unsigned int    force_du_rd_clk_on    : 1   ; /* [6]  */
		unsigned int    force_du_wr_clk_on    : 1   ; /* [7]  */
		unsigned int    force_cfg_clk_on      : 1   ; /* [8]  */
		unsigned int    reserved_0            : 23  ; /* [31..9]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_OTHER_RO */
union u_axi_jpeg_other_ro {
	/* Define the struct bits  */
	struct {
		unsigned int other_ro               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_OTHER_RW */
union u_axi_jpeg_other_rw {
	/* Define the struct bits  */
	struct {
		unsigned int other_rw               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_vp_wr_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_pixel_format   : 4   ; /* [3..0]  */
		unsigned int    vpwr_pixel_expansion : 1   ; /* [4]  */
		unsigned int    reserved_0            : 8   ; /* [12..5]  */
		unsigned int    vpwr_last_page      : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_FS_8 */
union u_axi_jpeg_vp_wr_axi_fs {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vpwr_address_frame_start : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_LINE_8 */
union u_axi_jpeg_vp_wr_axi_line {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_line_stride    : 11  ; /* [10..0]  */
		unsigned int    vpwr_line_start_wstrb : 4   ; /* [14..11]  */
		unsigned int    vpwr_line_wrap      : 14  ; /* [28..15]  */
		unsigned int    reserved_0            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_IF_CFG_8 */
union u_axi_jpeg_vp_wr_if_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_wr_stop_enable_du_threshold_reached : 1   ; /* [16]  */
		unsigned int    vp_wr_stop_enable_flux_ctrl : 1   ; /* [17]  */
		unsigned int    vp_wr_stop_enable_pressure : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_wr_stop_ok       : 1   ; /* [24]  */
		unsigned int    vp_wr_stop          : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vpwr_prefetch_bypass : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_limiter_vp_wr {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_access_limiter_0 : 4   ; /* [3..0]  */
		unsigned int    vpwr_access_limiter_1 : 4   ; /* [7..4]  */
		unsigned int    vpwr_access_limiter_2 : 4   ; /* [11..8]  */
		unsigned int    vpwr_access_limiter_3 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vpwr_access_limiter_reload : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_vp_rd_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_pixel_format  : 4   ; /* [3..0]  */
		unsigned int    vprd_pixel_expansion : 1   ; /* [4]  */
		unsigned int    vprd_allocated_du  : 5   ; /* [9..5]  */
		unsigned int    reserved_0            : 3   ; /* [12..10]  */
		unsigned int    vprd_last_page     : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_vp_rd_lwg {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_line_size     : 13  ; /* [12..0]  */
		unsigned int    reserved_0            : 3   ; /* [15..13]  */
		unsigned int    vprd_horizontal_blanking : 8   ; /* [23..16]  */
		unsigned int    reserved_1            : 8   ; /* [31..24]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_vp_rd_fhg {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_frame_size    : 13  ; /* [12..0]  */
		unsigned int    reserved_0            : 3   ; /* [15..13]  */
		unsigned int    vprd_vertical_blanking : 8   ; /* [23..16]  */
		unsigned int    reserved_1            : 8   ; /* [31..24]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_vp_rd_axi_fs {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vprd_axi_frame_start : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_vp_rd_axi_line {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_line_stride   : 11  ; /* [10..0]  */
		unsigned int    reserved_0            : 5   ; /* [15..11]  */
		unsigned int    vprd_line_wrap     : 13  ; /* [28..16]  */
		unsigned int    reserved_1            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_vp_rd_if_cfg {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_rd_stop_enable_du_threshold_reached : 1   ; /* [16]  */
		unsigned int    vp_rd_stop_enable_flux_ctrl : 1   ; /* [17]  */
		unsigned int    vp_rd_stop_enable_pressure : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_rd_stop_ok      : 1   ; /* [24]  */
		unsigned int    vp_rd_stop         : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vprd_prefetch_bypass : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

union u_axi_jpeg_limiter_vp_rd {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_access_limiter_0 : 4   ; /* [3..0]  */
		unsigned int    vprd_access_limiter_1 : 4   ; /* [7..4]  */
		unsigned int    vprd_access_limiter_2 : 4   ; /* [11..8]  */
		unsigned int    vprd_access_limiter_3 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vprd_access_limiter_reload : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_CFG_4 */
union u_axi_jpeg_vp_wr_cfg_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_pixel_format_4   : 4   ; /* [3..0]  */
		unsigned int    vpwr_pixel_expansion_4 : 1   ; /* [4]  */
		unsigned int    reserved_0            : 8   ; /* [12..5]  */
		unsigned int    vpwr_last_page_4      : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_FS_4 */
union u_axi_jpeg_vp_wr_axi_fs_4 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vpwr_address_frame_start_4 : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_LINE_4 */
union u_axi_jpeg_vp_wr_axi_line_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_line_stride_4    : 11  ; /* [10..0]  */
		unsigned int    vpwr_line_start_wstrb_4 : 4   ; /* [14..11]  */
		unsigned int    vpwr_line_wrap_4      : 14  ; /* [28..15]  */
		unsigned int    reserved_0            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_IF_CFG_4 */
union u_axi_jpeg_vp_wr_if_cfg_4 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_wr_stop_enable_du_threshold_reached_4 : 1   ; /* [16]  */
		unsigned int    vp_wr_stop_enable_flux_ctrl_4 : 1   ; /* [17]  */
		unsigned int    vp_wr_stop_enable_pressure_4 : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_wr_stop_ok_4       : 1   ; /* [24]  */
		unsigned int    vp_wr_stop_4          : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vpwr_prefetch_bypass_4 : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_CFG_5 */
union u_axi_jpeg_vp_wr_cfg_5 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_pixel_format_5   : 4   ; /* [3..0]  */
		unsigned int    vpwr_pixel_expansion_5 : 1   ; /* [4]  */
		unsigned int    reserved_0            : 8   ; /* [12..5]  */
		unsigned int    vpwr_last_page_5      : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_FS_5 */
union u_axi_jpeg_vp_wr_axi_fs_5 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vpwr_address_frame_start_5 : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
} ;

/* Define the union U_AXI_JPEG_VP_WR_AXI_LINE_5 */
union u_axi_jpeg_vp_wr_axi_line_5 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_line_stride_5    : 11  ; /* [10..0]  */
		unsigned int    vpwr_line_start_wstrb_5 : 4   ; /* [14..11]  */
		unsigned int    vpwr_line_wrap_5      : 14  ; /* [28..15]  */
		unsigned int    reserved_0            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_IF_CFG_5 */
union u_axi_jpeg_vp_wr_if_cfg_5 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_wr_stop_enable_du_threshold_reached_5 : 1   ; /* [16]  */
		unsigned int    vp_wr_stop_enable_flux_ctrl_5 : 1   ; /* [17]  */
		unsigned int    vp_wr_stop_enable_pressure_5 : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_wr_stop_ok_5       : 1   ; /* [24]  */
		unsigned int    vp_wr_stop_5          : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vpwr_prefetch_bypass_5 : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_CFG_6 */
union u_axi_jpeg_vp_wr_cfg_6 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_pixel_format_6   : 4   ; /* [3..0]  */
		unsigned int    vpwr_pixel_expansion_6 : 1   ; /* [4]  */
		unsigned int    reserved_0            : 8   ; /* [12..5]  */
		unsigned int    vpwr_last_page_6      : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_FS_6 */
union u_axi_jpeg_vp_wr_axi_fs_6 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vpwr_address_frame_start_6 : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_LINE_6 */
union u_axi_jpeg_vp_wr_axi_line_6 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_line_stride_6    : 11  ; /* [10..0]  */
		unsigned int    vpwr_line_start_wstrb_6 : 4   ; /* [14..11]  */
		unsigned int    vpwr_line_wrap_6      : 14  ; /* [28..15]  */
		unsigned int    reserved_0            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_IF_CFG_6 */
union u_axi_jpeg_vp_wr_if_cfg_6 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_wr_stop_enable_du_threshold_reached_6 : 1   ; /* [16]  */
		unsigned int    vp_wr_stop_enable_flux_ctrl_6 : 1   ; /* [17]  */
		unsigned int    vp_wr_stop_enable_pressure_6 : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_wr_stop_ok_6       : 1   ; /* [24]  */
		unsigned int    vp_wr_stop_6          : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vpwr_prefetch_bypass_6 : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_CFG_25 */
union u_axi_jpeg_vp_wr_cfg_25 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_pixel_format_25  : 4   ; /* [3..0]  */
		unsigned int    vpwr_pixel_expansion_25 : 1   ; /* [4]  */
		unsigned int    reserved_0            : 8   ; /* [12..5]  */
		unsigned int    vpwr_last_page_25     : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_FS_25 */
union u_axi_jpeg_vp_wr_axi_fs_25 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vpwr_address_frame_start_25 : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_LINE_25 */
union u_axi_jpeg_vp_wr_axi_line_25 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_line_stride_25   : 11  ; /* [10..0]  */
		unsigned int    vpwr_line_start_wstrb_25 : 4   ; /* [14..11]  */
		unsigned int    vpwr_line_wrap_25     : 14  ; /* [28..15]  */
		unsigned int    reserved_0            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_IF_CFG_25 */
union u_axi_jpeg_vp_wr_if_cfg_25 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_wr_stop_enable_du_threshold_reached_25 : 1   ; /* [16]  */
		unsigned int    vp_wr_stop_enable_flux_ctrl_25 : 1   ; /* [17]  */
		unsigned int    vp_wr_stop_enable_pressure_25 : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_wr_stop_ok_25      : 1   ; /* [24]  */
		unsigned int    vp_wr_stop_25         : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vpwr_prefetch_bypass_25 : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_CFG_30 */
union u_axi_jpeg_vp_wr_cfg_30 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_pixel_format_30  : 4   ; /* [3..0]  */
		unsigned int    vpwr_pixel_expansion_30 : 1   ; /* [4]  */
		unsigned int    reserved_0            : 8   ; /* [12..5]  */
		unsigned int    vpwr_last_page_30     : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_FS_30 */
union u_axi_jpeg_vp_wr_axi_fs_30 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vpwr_address_frame_start_30 : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_AXI_LINE_30 */
union u_axi_jpeg_vp_wr_axi_line_30 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_line_stride_30   : 11  ; /* [10..0]  */
		unsigned int    vpwr_line_start_wstrb_30 : 4   ; /* [14..11]  */
		unsigned int    vpwr_line_wrap_30     : 14  ; /* [28..15]  */
		unsigned int    reserved_0            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_WR_IF_CFG_30 */
union u_axi_jpeg_vp_wr_if_cfg_30 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_wr_stop_enable_du_threshold_reached_30 : 1   ; /* [16]  */
		unsigned int    vp_wr_stop_enable_flux_ctrl_30 : 1   ; /* [17]  */
		unsigned int    vp_wr_stop_enable_pressure_30 : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_wr_stop_ok_30      : 1   ; /* [24]  */
		unsigned int    vp_wr_stop_30         : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vpwr_prefetch_bypass_30 : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_LIMITER_VP_WR_4 */
union u_axi_jpeg_limiter_vp_wr_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_access_limiter_0_4 : 4   ; /* [3..0]  */
		unsigned int    vpwr_access_limiter_1_4 : 4   ; /* [7..4]  */
		unsigned int    vpwr_access_limiter_2_4 : 4   ; /* [11..8]  */
		unsigned int    vpwr_access_limiter_3_4 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vpwr_access_limiter_reload_4 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_LIMITER_VP_WR_5 */
union u_axi_jpeg_limiter_vp_wr_5 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_access_limiter_0_5 : 4   ; /* [3..0]  */
		unsigned int    vpwr_access_limiter_1_5 : 4   ; /* [7..4]  */
		unsigned int    vpwr_access_limiter_2_5 : 4   ; /* [11..8]  */
		unsigned int    vpwr_access_limiter_3_5 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vpwr_access_limiter_reload_5 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_LIMITER_VP_WR_6 */
union u_axi_jpeg_limiter_vp_wr_6 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_access_limiter_0_6 : 4   ; /* [3..0]  */
		unsigned int    vpwr_access_limiter_1_6 : 4   ; /* [7..4]  */
		unsigned int    vpwr_access_limiter_2_6 : 4   ; /* [11..8]  */
		unsigned int    vpwr_access_limiter_3_6 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vpwr_access_limiter_reload_6 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_LIMITER_VP_WR_25 */
union u_axi_jpeg_limiter_vp_wr_25 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_access_limiter_0_25 : 4   ; /* [3..0]  */
		unsigned int    vpwr_access_limiter_1_25 : 4   ; /* [7..4]  */
		unsigned int    vpwr_access_limiter_2_25 : 4   ; /* [11..8]  */
		unsigned int    vpwr_access_limiter_3_25 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vpwr_access_limiter_reload_25 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_LIMITER_VP_WR_30 */
union u_axi_jpeg_limiter_vp_wr_30 {
	/* Define the struct bits */
	struct {
		unsigned int    vpwr_access_limiter_0_30 : 4   ; /* [3..0]  */
		unsigned int    vpwr_access_limiter_1_30 : 4   ; /* [7..4]  */
		unsigned int    vpwr_access_limiter_2_30 : 4   ; /* [11..8]  */
		unsigned int    vpwr_access_limiter_3_30 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vpwr_access_limiter_reload_30 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_CFG_4 */
union u_axi_jpeg_vp_rd_cfg_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_pixel_format_4   : 4   ; /* [3..0]  */
		unsigned int    vprd_pixel_expansion_4 : 1   ; /* [4]  */
		unsigned int    vprd_allocated_du_4   : 5   ; /* [9..5]  */
		unsigned int    reserved_0            : 3   ; /* [12..10]  */
		unsigned int    vprd_last_page_4      : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_LWG_4 */
union u_axi_jpeg_vp_rd_lwg_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_line_size_4      : 13  ; /* [12..0]  */
		unsigned int    reserved_0            : 3   ; /* [15..13]  */
		unsigned int    vprd_horizontal_blanking_4 : 8   ; /* [23..16]  */
		unsigned int    reserved_1            : 8   ; /* [31..24]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_FHG_4 */
union u_axi_jpeg_vp_rd_fhg_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_frame_size_4     : 13  ; /* [12..0]  */
		unsigned int    reserved_0            : 3   ; /* [15..13]  */
		unsigned int    vprd_vertical_blanking_4 : 8   ; /* [23..16]  */
		unsigned int    reserved_1            : 8   ; /* [31..24]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_AXI_FS_4 */
union u_axi_jpeg_vp_rd_axi_fs_4 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vprd_axi_frame_start_4 : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_AXI_LINE_4 */
union u_axi_jpeg_vp_rd_axi_line_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_line_stride_4    : 11  ; /* [10..0]  */
		unsigned int    reserved_0            : 5   ; /* [15..11]  */
		unsigned int    vprd_line_wrap_4      : 13  ; /* [28..16]  */
		unsigned int    reserved_1            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_IF_CFG_4 */
union u_axi_jpeg_vp_rd_if_cfg_4 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_rd_stop_enable_du_threshold_reached_4 : 1   ; /* [16]  */
		unsigned int    vp_rd_stop_enable_flux_ctrl_4 : 1   ; /* [17]  */
		unsigned int    vp_rd_stop_enable_pressure_4 : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_rd_stop_ok_4       : 1   ; /* [24]  */
		unsigned int    vp_rd_stop_4          : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vprd_prefetch_bypass_4 : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_DEBUG_4 */
union u_axi_jpeg_vp_rd_debug_4 {
	/* Define the struct bits  */
	struct {
		unsigned int vp_rd_debug_4          : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_VP_RD_CFG_8 */
union u_axi_jpeg_vp_rd_cfg_8 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_pixel_format_8   : 4   ; /* [3..0]  */
		unsigned int    vprd_pixel_expansion_8 : 1   ; /* [4]  */
		unsigned int    vprd_allocated_du_8   : 5   ; /* [9..5]  */
		unsigned int    reserved_0            : 3   ; /* [12..10]  */
		unsigned int    vprd_last_page_8      : 19  ; /* [31..13]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_LWG_8 */
union u_axi_jpeg_vp_rd_lwg_8 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_line_size_8      : 13  ; /* [12..0]  */
		unsigned int    reserved_0            : 3   ; /* [15..13]  */
		unsigned int    vprd_horizontal_blanking_8 : 8   ; /* [23..16]  */
		unsigned int    reserved_1            : 8   ; /* [31..24]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_FHG_8 */
union u_axi_jpeg_vp_rd_fhg_8 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_frame_size_8     : 13  ; /* [12..0]  */
		unsigned int    reserved_0            : 3   ; /* [15..13]  */
		unsigned int    vprd_vertical_blanking_8 : 8   ; /* [23..16]  */
		unsigned int    reserved_1            : 8   ; /* [31..24]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_AXI_FS_8 */
union u_axi_jpeg_vp_rd_axi_fs_8 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 2   ; /* [1..0]  */
		unsigned int    vprd_axi_frame_start_8 : 30  ; /* [31..2]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_AXI_LINE_8 */
union u_axi_jpeg_vp_rd_axi_line_8 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_line_stride_8    : 11  ; /* [10..0]  */
		unsigned int    reserved_0            : 5   ; /* [15..11]  */
		unsigned int    vprd_line_wrap_8      : 13  ; /* [28..16]  */
		unsigned int    reserved_1            : 3   ; /* [31..29]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_IF_CFG_8 */
union u_axi_jpeg_vp_rd_if_cfg_8 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 16  ; /* [15..0]  */
		unsigned int    vp_rd_stop_enable_du_threshold_reached_8 : 1   ; /* [16]  */
		unsigned int    vp_rd_stop_enable_flux_ctrl_8 : 1   ; /* [17]  */
		unsigned int    vp_rd_stop_enable_pressure_8 : 1   ; /* [18]  */
		unsigned int    reserved_1            : 5   ; /* [23..19]  */
		unsigned int    vp_rd_stop_ok_8       : 1   ; /* [24]  */
		unsigned int    vp_rd_stop_8          : 1   ; /* [25]  */
		unsigned int    reserved_2            : 5   ; /* [30..26]  */
		unsigned int    vprd_prefetch_bypass_8 : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_VP_RD_DEBUG_8 */
union u_axi_jpeg_vp_rd_debug_8 {
	/* Define the struct bits  */
	struct {
		unsigned int vp_rd_debug_8          : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_LIMITER_VP_RD_4 */
union u_axi_jpeg_limiter_vp_rd_4 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_access_limiter_0_4 : 4   ; /* [3..0]  */
		unsigned int    vprd_access_limiter_1_4 : 4   ; /* [7..4]  */
		unsigned int    vprd_access_limiter_2_4 : 4   ; /* [11..8]  */
		unsigned int    vprd_access_limiter_3_4 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vprd_access_limiter_reload_4 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_LIMITER_VP_RD_8 */
union u_axi_jpeg_limiter_vp_rd_8 {
	/* Define the struct bits */
	struct {
		unsigned int    vprd_access_limiter_0_8 : 4   ; /* [3..0]  */
		unsigned int    vprd_access_limiter_1_8 : 4   ; /* [7..4]  */
		unsigned int    vprd_access_limiter_2_8 : 4   ; /* [11..8]  */
		unsigned int    vprd_access_limiter_3_8 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    vprd_access_limiter_reload_8 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_NR_RD_CFG_4 */
union u_axi_jpeg_nr_rd_cfg_4 {
	/* Define the struct bits */
	struct {
		unsigned int    reserved_0            : 5   ; /* [4..0]  */
		unsigned int    nrrd_allocated_du_4   : 5   ; /* [9..5]  */
		unsigned int    reserved_1            : 6   ; /* [15..10]  */
		unsigned int    nr_rd_stop_enable_du_threshold_reached_4 : 1   ; /* [16]  */
		unsigned int    nr_rd_stop_enable_flux_ctrl_4 : 1   ; /* [17]  */
		unsigned int    nr_rd_stop_enable_pressure_4 : 1   ; /* [18]  */
		unsigned int    reserved_2            : 5   ; /* [23..19]  */
		unsigned int    nr_rd_stop_ok_4       : 1   ; /* [24]  */
		unsigned int    nr_rd_stop_4          : 1   ; /* [25]  */
		unsigned int    reserved_3            : 5   ; /* [30..26]  */
		unsigned int    nrrd_enable_4         : 1   ; /* [31]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_NR_RD_DEBUG_4 */
union u_axi_jpeg_nr_rd_debug_4 {
	/* Define the struct bits  */
	struct {
		unsigned int nr_rd_debug_4          : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_LIMITER_NR_RD_4 */
union u_axi_jpeg_limiter_nr_rd_4 {
	/* Define the struct bits */
	struct {
		unsigned int    nrrd_access_limiter_0_4 : 4   ; /* [3..0]  */
		unsigned int    nrrd_access_limiter_1_4 : 4   ; /* [7..4]  */
		unsigned int    nrrd_access_limiter_2_4 : 4   ; /* [11..8]  */
		unsigned int    nrrd_access_limiter_3_4 : 4   ; /* [15..12]  */
		unsigned int    reserved_0            : 8   ; /* [23..16]  */
		unsigned int    nrrd_access_limiter_reload_4 : 4   ; /* [27..24]  */
		unsigned int    reserved_1            : 4   ; /* [31..28]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};

/* Define the union U_AXI_JPEG_SPARE_0 */
union u_axi_jpeg_spare_0 {
	/* Define the struct bits  */
	struct {
		unsigned int spare_0                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_SPARE_1 */
union u_axi_jpeg_spare_1 {
	/* Define the struct bits  */
	struct {
		unsigned int spare_1                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_SPARE_2 */
union u_axi_jpeg_spare_2 {
	/* Define the struct bits  */
	struct {
		unsigned int spare_2                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_SPARE_3 */
union u_axi_jpeg_spare_3 {
	/* Define the struct bits  */
	struct {
		unsigned int spare_3                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_VP_WR_DEBUG_4 */
union u_axi_jpeg_vp_wr_debug_4 {
	/* Define the struct bits  */
	struct {
		unsigned int vp_wr_debug_4          : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_VP_WR_DEBUG_5 */
union u_axi_jpeg_vp_wr_debug_5 {
	/* Define the struct bits  */
	struct {
		unsigned int vp_wr_debug_5          : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_VP_WR_DEBUG_6 */
union u_axi_jpeg_vp_wr_debug_6 {
	/* Define the struct bits  */
	struct {
		unsigned int vp_wr_debug_6          : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_VP_WR_DEBUG_25 */
union u_axi_jpeg_vp_wr_debug_25 {
	/* Define the struct bits  */
	struct {
		unsigned int vp_wr_debug_25         : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_VP_WR_DEBUG_30 */
union u_axi_jpeg_vp_wr_debug_30 {
	/* Define the struct bits  */
	struct {
		unsigned int vp_wr_debug_30         : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_0 */
union u_axi_jpeg_debug_0 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_0                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_1 */
union u_axi_jpeg_debug_1 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_1                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_2 */
union u_axi_jpeg_debug_2 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_2                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_3 */
union u_axi_jpeg_debug_3 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_3                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_4 */
union u_axi_jpeg_debug_4 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_4                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_5 */
union u_axi_jpeg_debug_5 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_5                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_6 */
union u_axi_jpeg_debug_6 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_6                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_7 */
union u_axi_jpeg_debug_7 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_7                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_8 */
union u_axi_jpeg_debug_8 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_8                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_9 */
union u_axi_jpeg_debug_9 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_9                : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_10 */
union u_axi_jpeg_debug_10 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_10               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_11 */
union u_axi_jpeg_debug_11 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_11               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_12 */
union u_axi_jpeg_debug_12 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_12               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_13 */
union u_axi_jpeg_debug_13 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_13               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_14 */
union u_axi_jpeg_debug_14 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_14               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
/* Define the union U_AXI_JPEG_DEBUG_15 */
union u_axi_jpeg_debug_15 {
	/* Define the struct bits  */
	struct {
		unsigned int debug_15               : 32  ; /* [31..0]  */
	} bits;

	/* Define an unsigned member */
	unsigned int    u32;
};
// ==============================================================================
/* Define the global struct */
struct s_axi_jpeg_regs_type {
	union u_axi_jpeg_cvdr_cfg             axi_jpeg_cvdr_cfg                ; /* 0x0 */
	union u_axi_jpeg_cvdr_debug_en        axi_jpeg_cvdr_debug_en           ; /* 0x4 */
	union u_axi_jpeg_cvdr_debug           axi_jpeg_cvdr_debug              ; /* 0x8 */
	union u_axi_jpeg_cvdr_wr_qos_cfg      axi_jpeg_cvdr_wr_qos_cfg         ; /* 0xc */
	union u_axi_jpeg_cvdr_rd_qos_cfg      axi_jpeg_cvdr_rd_qos_cfg         ; /* 0x10 */
	union u_axi_jpeg_force_clk            axi_jpeg_force_clk               ; /* 0x14 */
	unsigned int                          reserved_0[2]                    ; /* 0x18~0x1c */
	union u_axi_jpeg_other_ro             axi_jpeg_other_ro                ; /* 0x20 */
	union u_axi_jpeg_other_rw             axi_jpeg_other_rw                ; /* 0x24 */
	unsigned int                          reserved_1[18]                   ; /* 0x28~0x6c */
	union u_axi_jpeg_vp_wr_cfg_4          axi_jpeg_vp_wr_cfg_4             ; /* 0x70 */
	union u_axi_jpeg_vp_wr_axi_fs_4       axi_jpeg_vp_wr_axi_fs_4          ; /* 0x74 */
	union u_axi_jpeg_vp_wr_axi_line_4     axi_jpeg_vp_wr_axi_line_4        ; /* 0x78 */
	union u_axi_jpeg_vp_wr_if_cfg_4       axi_jpeg_vp_wr_if_cfg_4          ; /* 0x7c */
	union u_axi_jpeg_vp_wr_cfg_5          axi_jpeg_vp_wr_cfg_5             ; /* 0x80 */
	union u_axi_jpeg_vp_wr_axi_fs_5       axi_jpeg_vp_wr_axi_fs_5          ; /* 0x84 */
	union u_axi_jpeg_vp_wr_axi_line_5     axi_jpeg_vp_wr_axi_line_5        ; /* 0x88 */
	union u_axi_jpeg_vp_wr_if_cfg_5       axi_jpeg_vp_wr_if_cfg_5          ; /* 0x8c */
	union u_axi_jpeg_vp_wr_cfg_6          axi_jpeg_vp_wr_cfg_6             ; /* 0x90 */
	union u_axi_jpeg_vp_wr_axi_fs_6       axi_jpeg_vp_wr_axi_fs_6          ; /* 0x94 */
	union u_axi_jpeg_vp_wr_axi_line_6     axi_jpeg_vp_wr_axi_line_6        ; /* 0x98 */
	union u_axi_jpeg_vp_wr_if_cfg_6       axi_jpeg_vp_wr_if_cfg_6          ; /* 0x9c */
	unsigned int                          reserved_2[72]                   ; /* 0xa0~0x1bc */
	union u_axi_jpeg_vp_wr_cfg_25         axi_jpeg_vp_wr_cfg_25            ; /* 0x1c0 */
	union u_axi_jpeg_vp_wr_axi_fs_25      axi_jpeg_vp_wr_axi_fs_25         ; /* 0x1c4 */
	union u_axi_jpeg_vp_wr_axi_line_25    axi_jpeg_vp_wr_axi_line_25       ; /* 0x1c8 */
	union u_axi_jpeg_vp_wr_if_cfg_25      axi_jpeg_vp_wr_if_cfg_25         ; /* 0x1cc */
	unsigned int                          reserved_3[16]                   ; /* 0x1d0~0x20c */
	union u_axi_jpeg_vp_wr_cfg_30         axi_jpeg_vp_wr_cfg_30            ; /* 0x210 */
	union u_axi_jpeg_vp_wr_axi_fs_30      axi_jpeg_vp_wr_axi_fs_30         ; /* 0x214 */
	union u_axi_jpeg_vp_wr_axi_line_30    axi_jpeg_vp_wr_axi_line_30       ; /* 0x218 */
	union u_axi_jpeg_vp_wr_if_cfg_30      axi_jpeg_vp_wr_if_cfg_30         ; /* 0x21c */
	unsigned int                          reserved_4[392]                  ; /* 0x220~0x83c */
	union u_axi_jpeg_limiter_vp_wr_4      axi_jpeg_limiter_vp_wr_4         ; /* 0x840 */
	union u_axi_jpeg_limiter_vp_wr_5      axi_jpeg_limiter_vp_wr_5         ; /* 0x844 */
	union u_axi_jpeg_limiter_vp_wr_6      axi_jpeg_limiter_vp_wr_6         ; /* 0x848 */
	unsigned int                          reserved_5[18]                   ; /* 0x84c~0x890 */
	union u_axi_jpeg_limiter_vp_wr_25     axi_jpeg_limiter_vp_wr_25        ; /* 0x894 */
	unsigned int                          reserved_6[4]                    ; /* 0x898~0x8a4 */
	union u_axi_jpeg_limiter_vp_wr_30     axi_jpeg_limiter_vp_wr_30        ; /* 0x8a8 */
	unsigned int                          reserved_7[129]                  ; /* 0x8ac~0xaac */
	union u_axi_jpeg_vp_rd_cfg_4          axi_jpeg_vp_rd_cfg_4             ; /* 0xab0 */
	union u_axi_jpeg_vp_rd_lwg_4          axi_jpeg_vp_rd_lwg_4             ; /* 0xab4 */
	union u_axi_jpeg_vp_rd_fhg_4          axi_jpeg_vp_rd_fhg_4             ; /* 0xab8 */
	union u_axi_jpeg_vp_rd_axi_fs_4       axi_jpeg_vp_rd_axi_fs_4          ; /* 0xabc */
	union u_axi_jpeg_vp_rd_axi_line_4     axi_jpeg_vp_rd_axi_line_4        ; /* 0xac0 */
	union u_axi_jpeg_vp_rd_if_cfg_4       axi_jpeg_vp_rd_if_cfg_4          ; /* 0xac4 */
	unsigned int                          reserved_8                       ; /* 0xac8 */
	union u_axi_jpeg_vp_rd_debug_4        axi_jpeg_vp_rd_debug_4           ; /* 0xacc */
	unsigned int                          reserved_9[24]                   ; /* 0xad0~0xb2c */
	union u_axi_jpeg_vp_rd_cfg_8          axi_jpeg_vp_rd_cfg_8             ; /* 0xb30 */
	union u_axi_jpeg_vp_rd_lwg_8          axi_jpeg_vp_rd_lwg_8             ; /* 0xb34 */
	union u_axi_jpeg_vp_rd_fhg_8          axi_jpeg_vp_rd_fhg_8             ; /* 0xb38 */
	union u_axi_jpeg_vp_rd_axi_fs_8       axi_jpeg_vp_rd_axi_fs_8          ; /* 0xb3c */
	union u_axi_jpeg_vp_rd_axi_line_8     axi_jpeg_vp_rd_axi_line_8        ; /* 0xb40 */
	union u_axi_jpeg_vp_rd_if_cfg_8       axi_jpeg_vp_rd_if_cfg_8          ; /* 0xb44 */
	unsigned int                          reserved_10                      ; /* 0xb48 */
	union u_axi_jpeg_vp_rd_debug_8        axi_jpeg_vp_rd_debug_8           ; /* 0xb4c */
	unsigned int                          reserved_11[444]                 ; /* 0xb50~0x123c */
	union u_axi_jpeg_limiter_vp_rd_4      axi_jpeg_limiter_vp_rd_4         ; /* 0x1240 */
	unsigned int                          reserved_12[3]                   ; /* 0x1244~0x124c */
	union u_axi_jpeg_limiter_vp_rd_8      axi_jpeg_limiter_vp_rd_8         ; /* 0x1250 */
	unsigned int                          reserved_13[199]                 ; /* 0x1254~0x156c */
	union u_axi_jpeg_nr_rd_cfg_4          axi_jpeg_nr_rd_cfg_4             ; /* 0x1570 */
	union u_axi_jpeg_nr_rd_debug_4        axi_jpeg_nr_rd_debug_4           ; /* 0x1574 */
	union u_axi_jpeg_limiter_nr_rd_4      axi_jpeg_limiter_nr_rd_4         ; /* 0x1578 */
	unsigned int                          reserved_14[493]                 ; /* 0x157c~0x1d2c */
	union u_axi_jpeg_spare_0              axi_jpeg_spare_0                 ; /* 0x1d30 */
	union u_axi_jpeg_spare_1              axi_jpeg_spare_1                 ; /* 0x1d34 */
	union u_axi_jpeg_spare_2              axi_jpeg_spare_2                 ; /* 0x1d38 */
	union u_axi_jpeg_spare_3              axi_jpeg_spare_3                 ; /* 0x1d3c */
	unsigned int                          reserved_15[4]                   ; /* 0x1d40~0x1d4c */
	union u_axi_jpeg_vp_wr_debug_4        axi_jpeg_vp_wr_debug_4           ; /* 0x1d50 */
	union u_axi_jpeg_vp_wr_debug_5        axi_jpeg_vp_wr_debug_5           ; /* 0x1d54 */
	union u_axi_jpeg_vp_wr_debug_6        axi_jpeg_vp_wr_debug_6           ; /* 0x1d58 */
	unsigned int                          reserved_16[18]                  ; /* 0x1d5c~0x1da0 */
	union u_axi_jpeg_vp_wr_debug_25       axi_jpeg_vp_wr_debug_25          ; /* 0x1da4 */
	unsigned int                          reserved_17[4]                   ; /* 0x1da8~0x1db4 */
	union u_axi_jpeg_vp_wr_debug_30       axi_jpeg_vp_wr_debug_30          ; /* 0x1db8 */
	unsigned int                          reserved_18[97]                  ; /* 0x1dbc~0x1f3c */
	union u_axi_jpeg_debug_0              axi_jpeg_debug_0                 ; /* 0x1f40 */
	union u_axi_jpeg_debug_1              axi_jpeg_debug_1                 ; /* 0x1f44 */
	union u_axi_jpeg_debug_2              axi_jpeg_debug_2                 ; /* 0x1f48 */
	union u_axi_jpeg_debug_3              axi_jpeg_debug_3                 ; /* 0x1f4c */
	union u_axi_jpeg_debug_4              axi_jpeg_debug_4                 ; /* 0x1f50 */
	union u_axi_jpeg_debug_5              axi_jpeg_debug_5                 ; /* 0x1f54 */
	union u_axi_jpeg_debug_6              axi_jpeg_debug_6                 ; /* 0x1f58 */
	union u_axi_jpeg_debug_7              axi_jpeg_debug_7                 ; /* 0x1f5c */
	union u_axi_jpeg_debug_8              axi_jpeg_debug_8                 ; /* 0x1f60 */
	union u_axi_jpeg_debug_9              axi_jpeg_debug_9                 ; /* 0x1f64 */
	union u_axi_jpeg_debug_10             axi_jpeg_debug_10                ; /* 0x1f68 */
	union u_axi_jpeg_debug_11             axi_jpeg_debug_11                ; /* 0x1f6c */
	union u_axi_jpeg_debug_12             axi_jpeg_debug_12                ; /* 0x1f70 */
	union u_axi_jpeg_debug_13             axi_jpeg_debug_13                ; /* 0x1f74 */
	union u_axi_jpeg_debug_14             axi_jpeg_debug_14                ; /* 0x1f78 */
	union u_axi_jpeg_debug_15             axi_jpeg_debug_15                ; /* 0x1f7c */
};

/* Declare the struct pointor of the module AXI_JPEG */
extern struct s_axi_jpeg_regs_type *gopaxi_jpegallreg;

#endif /* __AXI_JPEG_DRV_PRIV_H__ */
