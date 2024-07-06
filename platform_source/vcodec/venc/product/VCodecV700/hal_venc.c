/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
 * Description: venc register config
 * Create: 2019-9-30
 */
#include <linux/of.h>
#include "hal_venc.h"
#ifdef VENC_MCORE_ENABLE
#include "drv_venc_ipc.h"

void venc_mcore_start_encode(struct encode_info *info, S_HEVC_AVC_REGS_TYPE *vedu_reg)
{
	struct ipc_message msg = {0};
	msg.id = IPC_MSG_START_ENCODE;
	msg.data[0] = info->channel.id;
	venc_ipc_send_msg(MBX1, &msg);
}

static void vedu_hal_set_int_mcu(uint32_t *reg_base)
{
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_INTMASK.u32),
				 VENC_MASK_WITH_MCU); /* slice_end/soft int1 */
}
#endif

#ifndef VENC_MCORE_ENABLE
static void vedu_hal_set_int_without_mcu(uint32_t *reg_base)
{
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_INTMASK.u32),
		CMDLIST_MASK); /* slice_end/soft int0 */
}
#endif

void vedu_hal_set_int(uint32_t *reg_base)
{
#ifdef VENC_MCORE_ENABLE
	vedu_hal_set_int_mcu(reg_base);
#else
	vedu_hal_set_int_without_mcu(reg_base);
#endif
}

#ifndef VENC_MCORE_ENABLE
static void vedu_hal_cfg_without_mcu(volatile uint32_t *base, uint32_t offset, uint32_t value)
{
	hal_cmdlist_wr_cmd_in_len0(offset, value);
}
#endif

void vedu_hal_cfg(volatile uint32_t *base, uint32_t offset, uint32_t value)
{
#ifdef VENC_MCORE_ENABLE
	base[offset / 4] = value;
#else
	vedu_hal_cfg_without_mcu(base, offset, value);
#endif
}

void venc_hal_get_reg_stream_len(struct stream_info *stream_info, uint32_t *reg_base)
{
	int i;
	S_HEVC_AVC_REGS_TYPE *all_reg = (S_HEVC_AVC_REGS_TYPE *)reg_base; /*lint !e826 */
	volatile U_FUNC_VLCST_DSRPTR00 *base0 = all_reg->FUNC_VLCST_DSRPTR00;
	volatile U_FUNC_VLCST_DSRPTR01 *base1 = all_reg->FUNC_VLCST_DSRPTR01;

	for (i = 0; i < MAX_SLICE_NUM; i++) {
		stream_info->slice_len[i] = base0[i].bits.slc_len0 - base1[i].bits.invalidnum0;
		stream_info->aligned_slice_len[i] = base0[i].bits.slc_len0;
		stream_info->slice_num++;
		if (base1[i].bits.islastslc0)
			break;
	}
}

void venc_hal_cfg_curld_osd01(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	U_VEDU_CURLD_OSD01_ALPHA D32;

	D32.bits.rgb_clip_min = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.rgb_clip_min;
	D32.bits.rgb_clip_max = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.rgb_clip_max;
	D32.bits.curld_hfbcd_clk_gt_en = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.curld_hfbcd_clk_gt_en;
	D32.bits.vcpi_curld_hebcd_tag_en = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.vcpi_curld_hebcd_tag_en;
	D32.bits.curld_hfbcd_raw_en = channel_cfg->all_reg.VEDU_CURLD_OSD01_ALPHA.bits.curld_hfbcd_raw_en;

	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_CURLD_OSD01_ALPHA.u32), D32.u32);
}

static void venc_hal_cfg_ime(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	uint32_t i;

	/* according to <VcodecV700 IT Environment Constrain> 2.1.1 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_INTER_MODE.u32),
		channel_cfg->all_reg.VEDU_IME_INTER_MODE.u32);

	/* according to <VcodecV700 IT Environment Constrain> 2.2 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO2_THR.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO2_THR.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO2_THR1.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO2_THR1.u32);

	/* according to <VcodecV700 IT Environment Constrain> 2.3 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO1_THR.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO1_THR.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_LAYER3TO1_THR1.u32),
		channel_cfg->all_reg.VEDU_IME_LAYER3TO1_THR1.u32);

	/* according to <VcodecV700 IT Environment Constrain> 2.4 ~ 2.8 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_ET_THR.u32),
		channel_cfg->all_reg.VEDU_ME_ET_THR.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_ET_THR_ME_STAT.u32),
		channel_cfg->all_reg.VEDU_ME_ET_THR_ME_STAT.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_REF_BUF_WORD_NUM.u32),
		channel_cfg->all_reg.VEDU_IME_REF_BUF_WORD_NUM.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_IME_INTERPOLATION_FLAG.u32),
		channel_cfg->all_reg.VEDU_IME_INTERPOLATION_FLAG.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_MAX_REGION.u32),
		channel_cfg->all_reg.VEDU_ME_MAX_REGION.u32);

	/* according to <VcodecV700 IT Environment Constrain> 2.4 ~ 2.8 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_TMV_SCALE),
		channel_cfg->all_reg.VEDU_ME_TMV_SCALE);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_TMV_EN.u32),
		channel_cfg->all_reg.VEDU_ME_TMV_EN.u32);

	/* according to <VcodecV700 IT Environment Constrain> 2.9 */
	for (i = 0; i < 20; i++)
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ME_ADD1_RANDOM_POINT_LIST.u32) + i * sizeof(uint32_t),
			*(&channel_cfg->all_reg.VEDU_ME_ADD1_RANDOM_POINT_LIST.u32 + i));
}

static void venc_hal_cfg_buffer(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	uint32_t i;

	/* according to <VcodecV700 IT Environment Constrain> 1.16 and 1.17 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_REC_HEADER_STRIDE.u32),
		channel_cfg->all_reg.VEDU_VCPI_REC_HEADER_STRIDE.u32);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_REF_L0_HEADER_STRIDE.u32),
		channel_cfg->all_reg.VEDU_VCPI_REF_L0_HEADER_STRIDE.u32);

	/* according to <VcodecV700 IT Environment Constrain> 4.1 */
	for (i = 0; i < 16; i++) {
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMADDR_L_NEW[i]),
			channel_cfg->all_reg.VEDU_VCPI_STRMADDR_L_NEW[i]);

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMADDR_H_NEW[i]),
			channel_cfg->all_reg.VEDU_VCPI_STRMADDR_H_NEW[i]);

		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_STRMBUFLEN_NEW[i]),
			channel_cfg->all_reg.VEDU_VCPI_STRMBUFLEN_NEW[i]);
	}
	/* according to <VcodecV700 IT Environment Constrain> 4.1 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SLCINFOADDR_L_NEW),
		 channel_cfg->all_reg.VEDU_VCPI_SLCINFOADDR_L_NEW);
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SLCINFOADDR_H_NEW),
		channel_cfg->all_reg.VEDU_VCPI_SLCINFOADDR_H_NEW);
}

static void venc_hal_cfg_low_power_mode(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	/* The config is effective only in h265 4k60fps scene. decided by user code */
	if (channel_cfg->all_reg.VEDU_VCPI_FORCE_INTRAPU32_NUM.bits.vcpi_force_intrapu_num_en == 1) {
		vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_FORCE_INTRAPU32_NUM.u32),
			channel_cfg->all_reg.VEDU_VCPI_FORCE_INTRAPU32_NUM.u32);
		vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_FORCE_ZEROMV.u32),
			channel_cfg->all_reg.VEDU_VCPI_FORCE_ZEROMV.u32);
	}
}

static void venc_hal_cfg_rc(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	/* according to <VcodecV700 IT Environment Constrain> 3.1 */
	uint32_t i;
	for (i = 0; i < 80; i++)
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_QP_LAMBDA_CTRL_REG00.u32) + i * sizeof(uint32_t),
			*(&channel_cfg->all_reg.VEDU_QPG_QP_LAMBDA_CTRL_REG00.u32 + i));

	for (i = 0; i < 48; i++)
		vedu_hal_cfg(reg_base,
			offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_QPG_QP_LAMBDA_CTRL_REG80.u32) + i * sizeof(uint32_t),
			*(&channel_cfg->all_reg.VEDU_QPG_QP_LAMBDA_CTRL_REG80.u32 + i));

	// we use these registers to share rate control information with mcu
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_BGL_ADDR_L),
		(channel_cfg->channel.is_reset_rc << 16 | channel_cfg->channel.rcmode << 8) | channel_cfg->channel.id);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_BGL_ADDR_H),
		(channel_cfg->channel.gop << 16) | channel_cfg->channel.framerate);
	vedu_hal_cfg(reg_base, offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_BGC_ADDR_L),
		channel_cfg->channel.bitrate);
}

static void venc_hal_cfg_misc(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	/* according to <VcodecV700 IT Environment Constrain> 1.12.1 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_ICE_CMC_MODE_CFG0.u32),
		channel_cfg->all_reg.VEDU_ICE_CMC_MODE_CFG0.u32);
}

static void venc_hal_cfg_memctrl(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	/* v120 chip constraint : VEDU_VCPI_SPMEM_CTRL_1 reg must keep default value
	 * v110 chip constraint : VEDU_VCPI_SPMEM_CTRL_1 reg not used so ignore it
	 */
	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_VCPI_SPMEM_CTRL_1.u32), 0x00155858);
}

static void venc_hal_cfg_ref_syscache(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	uint32_t i;
	uint32_t offset;
	U_VEDU_REFLD_ESP_HINT ref_esp_cache_hint = {0};
	U_VEDU_CACHE_AS_FUL cache_as_ful = {0};

	ref_esp_cache_hint.bits.sc_esp_hint_en = 1;
	ref_esp_cache_hint.bits.sc_esp_hint_l0 = 0x8;
	ref_esp_cache_hint.bits.sc_esp_hint_l1 = 0x9;
	ref_esp_cache_hint.bits.sc_esp_hint_l2 = 0xB;

	vedu_hal_cfg(reg_base,
		offsetof(S_HEVC_AVC_REGS_TYPE, VEDU_REFLD_ESP_HINT.u32), ref_esp_cache_hint.u32);

	for (i = VENC_REFLD_DATA_START_SID; i < VENC_REFLD_DATA_END_SID; i++) {
		offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE_RESERVE_1[0]) + i * 0x4 + 0x300;
		cache_as_ful.bits.domain = 0x3;
		cache_as_ful.bits.cache = 0x3;
		cache_as_ful.bits.sc_gid_hint = 1;
		cache_as_ful.bits.sc_new_hint = 0x8;
		vedu_hal_cfg(reg_base, offset, cache_as_ful.u32);
	}

	for (i = VENC_REC_DATA_START_SID; i < VENC_REC_DATA_END_SID; i++) {
		offset = offsetof(S_HEVC_AVC_REGS_TYPE, SMMU_PRE_RESERVE_1[0]) + i * 0x4 + 0x300;
		cache_as_ful.bits.domain = 0x3;
		cache_as_ful.bits.cache = 0x3;
		cache_as_ful.bits.sc_gid_hint = 1;
		cache_as_ful.bits.sc_new_hint = 0x8;
		vedu_hal_cfg(reg_base, offset, cache_as_ful.u32);
	}
}

void venc_hal_cfg_platform_diff(struct encode_info *channel_cfg, uint32_t *reg_base)
{
	venc_hal_cfg_ime(channel_cfg, reg_base);
	venc_hal_cfg_buffer(channel_cfg, reg_base);
	venc_hal_cfg_low_power_mode(channel_cfg, reg_base);
	venc_hal_cfg_rc(channel_cfg, reg_base);
	venc_hal_cfg_misc(channel_cfg, reg_base);
	venc_hal_cfg_memctrl(channel_cfg, reg_base);
	venc_hal_cfg_ref_syscache(channel_cfg, reg_base);
}

const char *pg_chip_bypass_venc[] = {
	"level2_partial_good_modem",
	"level2_partial_good_drv",
	"pc",
	"pc_lite",
	"unknown",
};

bool venc_device_need_bypass(void)
{
	uint32_t i;
	int32_t ret;
	const char *soc_spec = NULL;
	struct device_node *np = of_find_compatible_node(NULL, NULL, "hisilicon, soc_spec");
	if (!np) {
		VCODEC_ERR_VENC("of_find_compatible_node fail or normal type chip\n");
		return false;
	}

	ret = of_property_read_string(np, "soc_spec_set", &soc_spec);
	if (ret) {
		VCODEC_ERR_VENC("of_property_read_string soc_spec_set fail");
		return false;
	}

	for (i = 0; i < sizeof(pg_chip_bypass_venc) / sizeof(pg_chip_bypass_venc[0]); i++) {
		ret = strncmp(soc_spec, pg_chip_bypass_venc[i], strlen(pg_chip_bypass_venc[i]));
		if (!ret) {
			VCODEC_INFO_VENC("is pg chip : %s, need bypass venc\n", pg_chip_bypass_venc[i]);
			return true;
		}
	}

	VCODEC_INFO_VENC("no need to bypass venc\n");
	return false;
}
