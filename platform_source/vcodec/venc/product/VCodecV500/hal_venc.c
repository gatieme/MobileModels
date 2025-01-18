/*
 * hal_venc.c
 *
 * This is venc register config.
 *
 * Copyright (c) 2010-2020 Huawei Technologies CO., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "hal_venc.h"
#include "drv_common.h"

#ifdef CONFIG_VCODEC_BYPASS_VENC
#include "soc_spec_info.h"
#endif

void venc_hal_get_reg_stream_len(struct stream_info *stream_info, uint32_t *reg_base)
{
	return;
}

void venc_hal_cfg_curld_osd01(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	S_HEVC_AVC_REGS_TYPE *all_reg = (S_HEVC_AVC_REGS_TYPE *)reg_base;/*lint !e826 */
	U_VEDU_CURLD_OSD01_ALPHA D32;

	D32.bits.rgb_clip_min = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.rgb_clip_min;
	D32.bits.rgb_clip_max = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.rgb_clip_max;
	D32.bits.curld_hfbcd_clk_gt_en = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.curld_hfbcd_clk_gt_en;
	D32.bits.curld_hfbcd_bypass_en = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.curld_hfbcd_raw_en;
	D32.bits.curld_hfbcd_raw_en = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.curld_hfbcd_raw_en;
	all_reg->VEDU_CURLD_OSD01_ALPHA.u32 = D32.u32;
}

void vedu_hal_set_int(uint32_t *reg_base)
{
	S_HEVC_AVC_REGS_TYPE *all_reg = (S_HEVC_AVC_REGS_TYPE *)reg_base; /*lint !e826 */
	all_reg->VEDU_VCPI_INTMASK.u32 = VENC_MASK;
}

void vedu_hal_cfg_smmu(struct encode_info *channel_cfg, uint32_t core_id)
{
	bool is_protected = (channel_cfg->is_protected == 1 ? true : false);
	venc_entry_t *venc = platform_get_drvdata(venc_get_device());
	struct venc_context *ctx = &venc->ctx[core_id];

	if (ctx->first_cfg_flag == true) {
		venc_smmu_init(is_protected, core_id);
		ctx->first_cfg_flag = false;
	}

	venc_smmu_cfg(channel_cfg, ctx->reg_base);
}

void vedu_hal_cfg(volatile uint32_t *base, uint32_t offset, uint32_t value)
{
	base[offset / 4] = value;
}

static void venc_hal_cfg_buffer(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMADDR_L),
		channel_cfg->all_reg.VEDU_VCPI_STRMADDR_L);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMADDR_H),
		channel_cfg->all_reg.VEDU_VCPI_STRMADDR_H);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SWPTRADDR_L),
		channel_cfg->all_reg.VEDU_VCPI_SWPTRADDR_L);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SWPTRADDR_H),
		channel_cfg->all_reg.VEDU_VCPI_SWPTRADDR_H);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SRPTRADDR_L),
		channel_cfg->all_reg.VEDU_VCPI_SRPTRADDR_L);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SRPTRADDR_H),
		channel_cfg->all_reg.VEDU_VCPI_SRPTRADDR_H);
}

static void venc_hal_cfg_curld_clip(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	{
		U_VEDU_RGB2YUV_CLIP_THR_Y clip_thr;

		clip_thr.bits.rgb2yuv_clip_min_y =
			channel_cfg->all_reg.VEDU_RGB2YUV_CLIP_THR_Y.bits.rgb2yuv_clip_min_y;
		clip_thr.bits.rgb2yuv_clip_max_y =
			channel_cfg->all_reg.VEDU_RGB2YUV_CLIP_THR_Y.bits.rgb2yuv_clip_max_y;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_RGB2YUV_CLIP_THR_Y.u32),
			clip_thr.u32);
	}

	{
		U_VEDU_RGB2YUV_CLIP_THR_C clip_thr;

		clip_thr.bits.rgb2yuv_clip_min_c =
			channel_cfg->all_reg.VEDU_RGB2YUV_CLIP_THR_C.bits.rgb2yuv_clip_min_c;
		clip_thr.bits.rgb2yuv_clip_max_c =
			channel_cfg->all_reg.VEDU_RGB2YUV_CLIP_THR_C.bits.rgb2yuv_clip_max_c;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_RGB2YUV_CLIP_THR_C.u32),
			clip_thr.u32);
	}
}

static void venc_hal_cfg_curld_pre_mod_para(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	{
		U_VEDU_VCPI_OSD_POS_0 osd_pos0;

		osd_pos0.bits.rgb2yuv_v_0coef =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_0.bits.rgb2yuv_v_0coef;
		osd_pos0.bits.rgb2yuv_v_1coef =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_0.bits.rgb2yuv_v_1coef;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_OSD_POS_0.u32),
			osd_pos0.u32);
	}

	{
		U_VEDU_VCPI_OSD_POS_1 osd_pos1;

		osd_pos1.bits.rgb2yuv_v_2coef =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_1.bits.rgb2yuv_v_2coef;
		osd_pos1.bits.rgb_v_rnd =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_1.bits.rgb_v_rnd;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_OSD_POS_1.u32),
			osd_pos1.u32);
	}

	{
		U_VEDU_VCPI_OSD_POS_4 osd_pos4;

		osd_pos4.bits.curld_narrow_chrm_max =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_4.bits.curld_narrow_chrm_max;
		osd_pos4.bits.curld_narrow_chrm_min =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_4.bits.curld_narrow_chrm_min;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_OSD_POS_4.u32),
			osd_pos4.u32);
	}

	{
		U_VEDU_VCPI_OSD_POS_5 osd_pos5;

		osd_pos5.bits.curld_narrow_luma_max =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_5.bits.curld_narrow_luma_max;
		osd_pos5.bits.curld_narrow_luma_min =
			channel_cfg->all_reg.VEDU_VCPI_OSD_POS_5.bits.curld_narrow_luma_min;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_OSD_POS_5.u32),
			osd_pos5.u32);
	}

	{
		U_VEDU_CURLD_OSD23_ALPHA osd32_alpha;

		osd32_alpha.bits.vcpi_filter_hor_0coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD23_ALPHA.bits.vcpi_filter_hor_0coef;
		osd32_alpha.bits.vcpi_filter_hor_1coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD23_ALPHA.bits.vcpi_filter_hor_1coef;
		osd32_alpha.bits.vcpi_filter_hor_2coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD23_ALPHA.bits.vcpi_filter_hor_2coef;
		osd32_alpha.bits.vcpi_filter_hor_3coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD23_ALPHA.bits.vcpi_filter_hor_3coef;
		osd32_alpha.bits.vcpi_filter_hor_rnd =
			channel_cfg->all_reg.VEDU_CURLD_OSD23_ALPHA.bits.vcpi_filter_hor_rnd;
		osd32_alpha.bits.vcpi_filter_hor_shift =
			channel_cfg->all_reg.VEDU_CURLD_OSD23_ALPHA.bits.vcpi_filter_hor_shift;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_OSD23_ALPHA.u32),
			osd32_alpha.u32);
	}

	{
		U_VEDU_CURLD_OSD45_ALPHA osd45_alpha;

		osd45_alpha.bits.vcpi_filter_ver_0coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD45_ALPHA.bits.vcpi_filter_ver_0coef;
		osd45_alpha.bits.vcpi_filter_ver_1coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD45_ALPHA.bits.vcpi_filter_ver_1coef;
		osd45_alpha.bits.vcpi_filter_ver_2coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD45_ALPHA.bits.vcpi_filter_ver_2coef;
		osd45_alpha.bits.vcpi_filter_ver_3coef =
			channel_cfg->all_reg.VEDU_CURLD_OSD45_ALPHA.bits.vcpi_filter_ver_3coef;
		osd45_alpha.bits.vcpi_filter_ver_rnd =
			channel_cfg->all_reg.VEDU_CURLD_OSD45_ALPHA.bits.vcpi_filter_ver_rnd;
		osd45_alpha.bits.vcpi_filter_ver_shift =
			channel_cfg->all_reg.VEDU_CURLD_OSD45_ALPHA.bits.vcpi_filter_ver_shift;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_OSD45_ALPHA.u32),
			osd45_alpha.u32);
	}

	{
		U_VEDU_CURLD_OSD67_ALPHA osd67_alpha;

		osd67_alpha.bits.srcyh_stride =
			channel_cfg->all_reg.VEDU_CURLD_OSD67_ALPHA.bits.srcyh_stride;
		osd67_alpha.bits.srcch_stride =
			channel_cfg->all_reg.VEDU_CURLD_OSD67_ALPHA.bits.srcch_stride;

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_OSD67_ALPHA.u32),
			osd67_alpha.u32);
	}
	venc_hal_cfg_curld_clip(channel_cfg, reg_base);
}

static void venc_hal_cfg_pmeinfo_addr(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PMEINFO_ST_ADDR_L),
		channel_cfg->all_reg.VEDU_VCPI_PMEINFO_ST_ADDR_L);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PMEINFO_LD0_ADDR_L),
		channel_cfg->all_reg.VEDU_VCPI_PMEINFO_LD0_ADDR_L);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PMEINFO_LD1_ADDR_L),
		channel_cfg->all_reg.VEDU_VCPI_PMEINFO_LD1_ADDR_L);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PMEINFO_ST_ADDR_H),
		channel_cfg->all_reg.VEDU_VCPI_PMEINFO_ST_ADDR_H);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PMEINFO_LD0_ADDR_H),
		channel_cfg->all_reg.VEDU_VCPI_PMEINFO_LD0_ADDR_H);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_PMEINFO_LD1_ADDR_H),
		channel_cfg->all_reg.VEDU_VCPI_PMEINFO_LD1_ADDR_H);
}

// platform differences configured only in the vedu_hal_cfg_reg interface
void venc_hal_cfg_plat_diff_all_cfg(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	venc_hal_cfg_curld_pre_mod_para(channel_cfg, reg_base);
}

void venc_hal_cfg_platform_diff(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	venc_hal_cfg_buffer(channel_cfg, reg_base);
	venc_hal_cfg_pmeinfo_addr(channel_cfg, reg_base);
	return;
}

bool venc_device_need_bypass(void)
{
#ifdef CONFIG_VCODEC_BYPASS_VENC
	return (get_module_freq_level(kernel, video) == FREQ_LEVEL2);
#else
	return false;
#endif
}

static int32_t check_internal_buffer_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg, const mem_buffer_t *buffer)
{
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_YADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_CADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_YH_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REC_CH_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFY_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFC_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFYH_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFCH_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMELD_L0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFY_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFC_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFYH_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_REFCH_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMELD_L1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMEST_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_NBI_MVST_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_NBI_MVLD_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMEINFO_ST_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMEINFO_LD0_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_PMEINFO_LD1_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_QPGLD_INF_ADDR_L, buffer->size);

	return 0;
}

static int32_t check_image_buffer_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg, const mem_buffer_t *buffer)
{
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_TUNLCELL_ADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_SRC_YADDR_L, buffer->size);
	d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_SRC_CADDR_L, buffer->size);

	if (reg->VEDU_VCPI_STRFMT.bits.vcpi_str_fmt == YUV420_PLANAR ||
		reg->VEDU_VCPI_STRFMT.bits.vcpi_str_fmt == YUV422_PLANAR)
		d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_SRC_VADDR_L, buffer->size);

	if (reg->VEDU_VCPI_STRFMT.bits.vcpi_str_fmt == YUV420_SEMIPLANAR_CMP) {
		d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_YH_ADDR_L, buffer->size);
		d_venc_check_cfg_reg_addr_ret(buffer->start_phys_addr, reg->VEDU_VCPI_CH_ADDR_L, buffer->size);
	}

	return 0;
}

static int32_t check_image_stream_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg,
		const mem_buffer_t *stream_buffer, const mem_buffer_t *head_buffer)
{
	d_venc_check_cfg_reg_addr_ret(stream_buffer->start_phys_addr, reg->VEDU_VCPI_SWPTRADDR_L, stream_buffer->size);
	d_venc_check_cfg_reg_addr_ret(stream_buffer->start_phys_addr, reg->VEDU_VCPI_SRPTRADDR_L, stream_buffer->size);
	d_venc_check_cfg_reg_addr_ret(stream_buffer->start_phys_addr, reg->VEDU_VCPI_STRMADDR_L, stream_buffer->size);

	return 0;
}

int32_t vedu_hal_check_addr(const S_HEVC_AVC_REGS_TYPE_CFG *reg, venc_buffer_info_t *mem_info)
{
	int32_t ret;

	ret = check_internal_buffer_addr(reg, &mem_info->internal_buffer);
	if (ret) {
		VCODEC_FATAL_VENC("check internal buffer addr failed");
		return VCODEC_FAILURE;
	}

	ret = check_image_buffer_addr(reg, &mem_info->image_buffer);
	if (ret) {
		VCODEC_FATAL_VENC("check image buffer addr failed");
		return VCODEC_FAILURE;
	}

	ret = check_image_stream_addr(reg, &mem_info->stream_buffer[0], &mem_info->stream_head_buffer);
	if (ret) {
		VCODEC_FATAL_VENC("check stream buffer addr failed");
		return VCODEC_FAILURE;
	}
	return 0;
}