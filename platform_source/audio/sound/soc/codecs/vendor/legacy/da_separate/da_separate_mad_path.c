/*
 * da_separate_mad_path.c codec driver.
 *
 * Copyright (c) 2019 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "da_separate_mad_path.h"
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/regulator/consumer.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/initval.h>
#include <sound/soc.h>
#include <sound/soc-dapm.h>
#include <sound/tlv.h>

#include "audio_log.h"
#include "da_separate_utils.h"
#include "da_separate_type.h"
#include "soc_mad.h"
#include "asoc_adapter.h"
#include "audio/audio_base_addr.h"

#define LOG_TAG "DA_separate_mad"

static const struct snd_kcontrol_new mad_controls[] = {
	SOC_SINGLE("MAD_MIC_PGA_GAIN",    CODEC_ANA_RW59_REG,  PGA_OFFSET,   0x1ff, 0),
	SOC_SINGLE("MAD_CIC_GAIN",    AU_MAD_CIC_GAIN_REG,  MAD_CIC_GAIN_OFFSET,   0x3f, 0),
};

static const char * const mad_mic_mux_texts[] = {
	"NULL",
	"MAIN_MIC",
	"AUX_MIC",
	"NULL",
	"MIC3",
};

static const struct soc_enum mad_mic_mux_enum =
	SOC_ENUM_SINGLE(CODEC_ANA_RW58_REG, MAD_PGA_SEL_OFFSET,
		ARRAY_SIZE(mad_mic_mux_texts), mad_mic_mux_texts);

static const struct snd_kcontrol_new mad_mic_mux_controls =
	SOC_DAPM_ENUM("Mux", mad_mic_mux_enum);

static const struct snd_kcontrol_new au_mad_switch =
	SOC_DAPM_SINGLE("ENABLE", VIR1_ADDR, REG_BIT5, 1, 0);

static bool is_mad_init(void)
{
#ifdef SOC_SCTRL_SCPEREN0_gt_clk_mad_acpu_START
	unsigned int sctrl_scperclken0_data = da_separate_get_sctrl_scperclken0_data() &
		BIT(SOC_SCTRL_SCPEREN0_gt_clk_mad_acpu_START);
	if (sctrl_scperclken0_data != BIT(SOC_SCTRL_SCPEREN0_gt_clk_mad_acpu_START)) {
		AUDIO_LOGE("asp mad is not ready");
		return false;
	} else {
		return true;
	}
#else
	AUDIO_LOGI("asp do not support mad");
	return false;
#endif
}

static int au_mad_mic_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);
	struct platform_data *priv = snd_soc_component_get_drvdata(codec);

	if (!is_mad_init())
		return 0;

	AUDIO_LOGI("power mode event: %d", event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		soc_mad_select_din(LOW_FREQ_MODE);
		if (priv->board_type == UDP_BOARD) {
			soc_mad_request_pinctrl_state(LOW_FREQ_MODE);
		} else {
			snd_soc_component_write_adapter(codec, 0xFA89C788, 0x3);
			snd_soc_component_write_adapter(codec, 0xFA89C78C, 0x3);
			snd_soc_component_write_adapter(codec, 0xFA89C794, 0x3);
		}
		snd_soc_component_write_adapter(codec, CTRL_REG_DIG_IO_DS_SEL1_CODEC_CFG_REG, 0x1);
		break;
	case SND_SOC_DAPM_POST_PMD:
		soc_mad_select_din(HIGH_FREQ_MODE);
		if (priv->board_type == UDP_BOARD) {
			soc_mad_release_pinctrl_state(LOW_FREQ_MODE);
		} else {
			snd_soc_component_write_adapter(codec, 0xFA89C788, 0x1);
			snd_soc_component_write_adapter(codec, 0xFA89C78C, 0x1);
			snd_soc_component_write_adapter(codec, 0xFA89C794, 0x1);
		}
		snd_soc_component_write_adapter(codec, CTRL_REG_DIG_IO_DS_SEL1_CODEC_CFG_REG, 0x0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	return 0;
}

static int mad_mic_mux_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	AUDIO_LOGI("power mode event: %d", event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		snd_soc_component_write_adapter(codec, CODEC_ANA_RW60_REG, 0x3F);
		da_separate_update_bits(codec, CODEC_ANA_RW1_REG, 0x3 << AVREF_SEL_OFFSET, 0x2);
		da_separate_update_bits(codec, CODEC_ANA_RW62_REG, BIT(DIN_MAD_MIC_OFFSET),
			BIT(DIN_MAD_MIC_OFFSET));
		da_separate_update_bits(codec, CODEC_ANA_RW58_REG, BIT(VCM_MAD_LP_EN_OFFSET),
			BIT(VCM_MAD_LP_EN_OFFSET));

		break;
	case SND_SOC_DAPM_POST_PMD:
		da_separate_update_bits(codec, CODEC_ANA_RW62_REG, BIT(DIN_MAD_MIC_OFFSET), 0x0);
		da_separate_update_bits(codec, CODEC_ANA_RW58_REG, BIT(VCM_MAD_LP_EN_OFFSET), 0x0);

		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	return 0;
}

static int au_mad_switch_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	AUDIO_LOGI("power mode event: %d", event);
	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		snd_soc_component_write_adapter(codec, CODEC_ANA_RW60_REG, 0x02);
		usleep_range(10, 11);
		da_separate_update_bits(codec, CODEC_ANA_RW60_REG, BIT(PD_MUTE_MAD_OFFSET), 0);
		usleep_range(200, 220);
		da_separate_update_bits(codec, AU_MAD_REG,
			BIT(MAD_CIC_CLKEN_OFFSET) | BIT(AU_MAD_ADC_EN_OFFSET) | BIT(AU_MAD_EN_OFFSET),
			BIT(MAD_CIC_CLKEN_OFFSET) | BIT(AU_MAD_ADC_EN_OFFSET) | BIT(AU_MAD_EN_OFFSET));
		break;
	case SND_SOC_DAPM_POST_PMD:
		da_separate_update_bits(codec, CODEC_ANA_RW60_REG, BIT(PD_MUTE_MAD_OFFSET), BIT(PD_MUTE_MAD_OFFSET));
		da_separate_update_bits(codec, AU_MAD_REG,
			BIT(MAD_CIC_CLKEN_OFFSET) | BIT(AU_MAD_ADC_EN_OFFSET) | BIT(AU_MAD_EN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	return 0;
}

static int mad_drv_power_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	AUDIO_LOGI("power mode event: %d", event);
	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		da_separate_update_bits(codec, CODEC_ANA_RW1_REG, 0x3 << AVREF_SEL_OFFSET, 0x1);
		usleep_range(200, 220);
		break;
	case SND_SOC_DAPM_PRE_PMD:
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	return 0;
}

static const struct snd_soc_dapm_widget mad_dapm_widgets[] = {
	SND_SOC_DAPM_INPUT("MAD INPUT"),
	SND_SOC_DAPM_INPUT("MAD_AUX INPUT"),
	SND_SOC_DAPM_MIC("AU_MAD_MIC", au_mad_mic_event),
	SND_SOC_DAPM_MUX_E("MAD_MIC_MUX", SND_SOC_NOPM, 0, 0, &mad_mic_mux_controls, \
		mad_mic_mux_event, (SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_SWITCH_E("AU_MAD_SWITCH", SND_SOC_NOPM, 0, 0, &au_mad_switch, \
		au_mad_switch_event, (SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD)),
	SND_SOC_DAPM_OUT_DRV_E("MAD_ADC1 DRV", CODEC_ANA_RW3_REG, ADCL_MUTE_OFFSET, 1, NULL, 0, \
		mad_drv_power_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)),
	SND_SOC_DAPM_OUTPUT("MAD OUTPUT"),
	SND_SOC_DAPM_OUTPUT("MAD_AUX OUTPUT"),
};

#define AU_MAD_HIGH_FREQ \
	{ "MAD INPUT", 			NULL, 				"MICBIAS1 MIC"}, \
	{ "ANA_MUX3 MUX", 		"ADC1", 			"MAD INPUT"}, \
	{ "ANA_AU_EN MIXER", 	"ANA_AU_MAD_EN", 	"ANA_MUX3 MUX" }, \
	{ "MAD OUTPUT", 		NULL, 				"ANA_AU_EN MIXER" }, \

#define AU_MAD_HIGH_FREQ_SOC \
	{ "ADCL_FILTER",			NULL,				"ADC1 INPUT" }, \
	{ "AU_EN MIXER",			"AU_ADCL_EN",		"ADCL_FILTER" }, \
	{ "DA_AD_LOOP MUX",			"NORMAL",			"AU_EN MIXER" }, \
	{ "ADC1 MUX",				"ADC1",				"DA_AD_LOOP MUX" }, \
	{ "MAD OUTPUT",				NULL,				"ADC1 MUX" }, \
	{ "ADCL_FILTER",			NULL,				"PLL" }, \
	{ "ADCL_FILTER",			NULL,				"SIF_CLK" }, \

#define AU_MAD_LOW_FREQ \
	{ "AU_MAD_MIC",				    NULL, 				"MAD INPUT" }, \
	{ "MAD_MIC_MUX",				"MAIN_MIC",			"AU_MAD_MIC" }, \
	{ "MAD_MIC_MUX",				"AUX_MIC",			"AU_MAD_MIC" }, \
	{ "MAD_MIC_MUX",				"MIC3",				"AU_MAD_MIC" }, \
	{ "AU_MAD_SWITCH",				"ENABLE",			"MAD_MIC_MUX" }, \
	{ "MAD OUTPUT", 				NULL, 				"AU_MAD_SWITCH"}, \

#define AU_MAD_LOW_FREQ_AUX \
	{ "MAD_AUX INPUT",				NULL,				"MICBIAS1 MIC" }, \
	{ "ANA_AU_EN MIXER",			"ANA_AU_MAD_EN",	"MAD_AUX INPUT"}, \
	{ "MAD_AUX OUTPUT",				NULL,				"ANA_AU_EN MIXER" }, \

static const struct snd_soc_dapm_route mad_route_map[] = {
	AU_MAD_HIGH_FREQ
	AU_MAD_HIGH_FREQ_SOC
	AU_MAD_LOW_FREQ
	AU_MAD_LOW_FREQ_AUX
};

static struct snd_codec_resource mad_resource = {
	mad_controls,
	ARRAY_SIZE(mad_controls),
	mad_dapm_widgets,
	ARRAY_SIZE(mad_dapm_widgets),
	mad_route_map,
	ARRAY_SIZE(mad_route_map),
};

int add_mad(struct snd_soc_component *codec)
{
	if (codec == NULL) {
		AUDIO_LOGE("parameter is null");
		return -EINVAL;
	}

	return da_separate_add_codec_resource(codec, &mad_resource);
}

