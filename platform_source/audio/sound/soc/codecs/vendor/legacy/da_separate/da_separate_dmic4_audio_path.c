/*
 * da_separate_dmic4_audio_path.c codec driver.
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
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

#include "da_separate_dmic4_audio_path.h"

#include "audio_log.h"
#include "da_separate_utils.h"
#include "da_separate_type.h"

#define LOG_TAG "da_separate_dmic4_audio"

#define AUDIO_MIC4_SRC_KCONTROLS \
	SOC_SINGLE("MIC4_UP_SRC18_MODE",    MIC4_SRCDN_CTRL1_REG, MIC4_UP_SRCDN_SRC_MODE_OFFSET, 0x7, 0), \
	SOC_SINGLE("MIC4_UP_SRC18_FS",      FS_CTRL4_REG,     FS_MIC4_UP_SRCDN_DOUT_OFFSET,      0x3, 0), \

#define AUDIO_MIC4_PGA_KCONTROLS \
	SOC_SINGLE("ADC_MIC4_PGA_GAIN",      MIC4_UP_PGA_REG,          MIC4_UP_PGA_GAIN_OFFSET,      0xff, 0), \
	SOC_SINGLE("ADC_MIC4_PGA_BYPASS",    MIC4_UP_PGA_REG,          MIC4_UP_PGA_BYPASS_OFFSET,    0x1,  0), \

static const struct snd_kcontrol_new audio_dmic4_controls[] = {
	AUDIO_MIC4_SRC_KCONTROLS
	AUDIO_MIC4_PGA_KCONTROLS
};

static const char *const src18_mux_texts[] = {
	"BYPASS",
	"SRC18",
};

static const struct soc_enum src18_mux_enum =
	SOC_ENUM_SINGLE(CODEC_CLK_EN2_REG, MIC4_UP_SRCDN_CLKEN_OFFSET,
		ARRAY_SIZE(src18_mux_texts), src18_mux_texts);

static const struct snd_kcontrol_new src18_mux =
	SOC_DAPM_ENUM("Mux", src18_mux_enum);

static const struct snd_kcontrol_new mic4_up_fifo_switch[] = {
	SOC_DAPM_SINGLE("ENABLE", VIR0_ADDR, REG_BIT10, 1, 0),
};

static int adc_mic4_filter_pga_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* filter/pga clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(MIC4_ADC_FILTER_CLKEN_OFFSET),
			BIT(MIC4_ADC_FILTER_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* filter/pga clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(MIC4_ADC_FILTER_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

static int mic4_up_fifo_switch_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* clear fifo */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(MIC4_UP_AFIFO_CLKEN_OFFSET), 0);

		udelay(CLEAR_FIFO_DELAY_LEN_MS);

		/* fifo clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(MIC4_UP_AFIFO_CLKEN_OFFSET),
			BIT(MIC4_UP_AFIFO_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* fifo clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(MIC4_UP_AFIFO_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

#define AUDIO_MIC4_INPUT_OUTPUT_WIDGET \
	SND_SOC_DAPM_OUTPUT("MIC4_UP OUTPUT"), \

#define AUDIO_MIC4_PGA_WIDGET \
	SND_SOC_DAPM_PGA_E("ADC_MIC4_FILTER", SND_SOC_NOPM, 0, 0, NULL, 0, \
		adc_mic4_filter_pga_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \
	SND_SOC_DAPM_PGA("ADC_MIC4 PGA", CODEC_CLK_EN2_REG, MIC4_UP_PGA_CLKEN_OFFSET, 0, NULL, 0), \

#define AUDIO_MIC4_MUX_WIDGET \
	SND_SOC_DAPM_MUX("MIC4_SRC18 MUX", SND_SOC_NOPM, 0, 0, &src18_mux), \

#define AUDIO_MIC4_SWITCH_WIDGET \
	SND_SOC_DAPM_SWITCH_E("MIC4_UP_FIFO SWITCH", SND_SOC_NOPM, 0, 0, mic4_up_fifo_switch, \
		mic4_up_fifo_switch_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \


static const struct snd_soc_dapm_widget audio_dmic4_dapm_widgets[] = {
	AUDIO_MIC4_INPUT_OUTPUT_WIDGET
	AUDIO_MIC4_PGA_WIDGET
	AUDIO_MIC4_MUX_WIDGET
	AUDIO_MIC4_SWITCH_WIDGET
};

#define ASP_MIC4_AUDIO_CAP \
	{ "ADC_MIC4_FILTER",       NULL,           "ADC_MIC4 PGA" }, \
	{ "MIC4_SRC18 MUX",        "BYPASS",       "ADC_MIC4_FILTER" }, \
	{ "MIC4_SRC18 MUX",        "SRC18",        "ADC_MIC4_FILTER" }, \
	{ "MIC4_UP_FIFO SWITCH",   "ENABLE",       "MIC4_SRC18 MUX" }, \
	{ "MIC4_UP OUTPUT",        NULL,           "MIC4_UP_FIFO SWITCH" }, \

#define MIC4_PLL \
	{ "MIC4_UP_FIFO SWITCH",  NULL,   "PLL" }, \
	{ "MIC4_UP_FIFO SWITCH",  NULL,   "SIF_CLK" }, \

#define MIC4_CAP \
	{ "ADC_MIC4 PGA",   NULL,      "DMIC2" }, \

static const struct snd_soc_dapm_route audio_dmic4_route_map[] = {
	ASP_MIC4_AUDIO_CAP
	MIC4_PLL
	MIC4_CAP
};

static struct snd_codec_resource audio_resource = {
	audio_dmic4_controls,
	ARRAY_SIZE(audio_dmic4_controls),
	audio_dmic4_dapm_widgets,
	ARRAY_SIZE(audio_dmic4_dapm_widgets),
	audio_dmic4_route_map,
	ARRAY_SIZE(audio_dmic4_route_map),
};

int add_dmic4(struct snd_soc_component *codec)
{
	if (codec == NULL) {
		AUDIO_LOGE("parameter is null");
		return -EINVAL;
	}

	return da_separate_add_codec_resource(codec, &audio_resource);
}

