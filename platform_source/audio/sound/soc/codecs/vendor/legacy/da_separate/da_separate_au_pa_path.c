/*
 * da_separate_au_pa_path.c codec driver.
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
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

#include "da_separate_au_pa_path.h"

#include <sound/au_pa.h>

#include "audio_log.h"
#include "da_separate_type.h"
#include "da_separate_utils.h"
#include "asoc_adapter.h"

#define LOG_TAG "DA_separate_au_pa"

#define LUT_REG_INIT 269488144

static void au_pa2_asp_soc_reg_init(struct snd_soc_component *codec)
{
	da_separate_update_bits_for_runtime_resume(codec, CLASSH2_CTRL1_REG,
		BIT(CLASSH2_BYPASS_OFFSET), BIT(CLASSH2_BYPASS_OFFSET));
	da_separate_update_bits_for_runtime_resume(codec, CLASSH2_CTRL1_REG,
		MASK_ON_BIT(CLASSH2_DN_CFG_LEN, CLASSH2_DN_CFG_OFFSET), 0x1);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG0_3_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG4_7_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG8_11_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG12_15_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG16_19_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG20_23_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG24_27_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG28_31_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG32_35_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG36_39_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG40_43_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG44_47_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG48_51_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG52_55_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG56_59_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG60_63_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASS2_LUT_REG64_67_REG, LUT_REG_INIT);
}

static void au_pa3_asp_soc_reg_init(struct snd_soc_component *codec)
{
	da_separate_update_bits_for_runtime_resume(codec, CLASSH3_CTRL1_REG,
		BIT(CLASSH3_BYPASS_OFFSET), BIT(CLASSH3_BYPASS_OFFSET));
	da_separate_update_bits_for_runtime_resume(codec, CLASSH3_CTRL1_REG,
		MASK_ON_BIT(CLASSH3_DN_CFG_LEN, CLASSH3_DN_CFG_OFFSET), 0x1);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG0_3_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG4_7_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG8_11_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG12_15_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG16_19_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG20_23_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG24_27_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG28_31_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG32_35_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG36_39_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG40_43_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG44_47_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG48_51_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG52_55_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG56_59_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG60_63_REG, LUT_REG_INIT);
	da_separate_reg_write_for_runtime_resume(codec, CLASSH3_LUT_REG64_67_REG, LUT_REG_INIT);
}

void au_pa_reg_init(struct snd_soc_component *codec)
{
	au_pa2_asp_soc_reg_init(codec);
	au_pa3_asp_soc_reg_init(codec);
}

#ifdef CONFIG_SND_SOC_CODEC_DA_SEPARATE_V6B
#define MIXER4_PGA_KCONTROLS \
	SOC_SINGLE("IN1_VOICE_DL_PGA",       SPA2_MIXER4_CTRL0_REG,     SPA2_MIXER4_GAIN1_OFFSET,         0x3,  0), \
	SOC_SINGLE("IN1_VOICE_DR_PGA",       SPA3_MIXER4_CTRL0_REG,     SPA3_MIXER4_GAIN1_OFFSET,         0x3,  0), \
	SOC_SINGLE("IN2_FM_L_PGA",           SPA2_MIXER4_CTRL0_REG,     SPA2_MIXER4_GAIN2_OFFSET,         0x3,  0), \
	SOC_SINGLE("IN2_FM_R_PGA",           SPA3_MIXER4_CTRL0_REG,     SPA3_MIXER4_GAIN2_OFFSET,         0x3,  0), \
	SOC_SINGLE("IN3_ULTR_DN_SPA2_PGA",   SPA2_MIXER4_CTRL0_REG,     SPA2_MIXER4_GAIN3_OFFSET,         0x3,  0), \
	SOC_SINGLE("IN3_ULTR_DN_SPA3_PGA",   SPA3_MIXER4_CTRL0_REG,     SPA3_MIXER4_GAIN3_OFFSET,         0x3,  0), \
	SOC_SINGLE("IN4_FM_R_PGA",           SPA2_MIXER4_CTRL0_REG,     SPA2_MIXER4_GAIN4_OFFSET,         0x3,  0), \
	SOC_SINGLE("IN4_FM_L_PGA",           SPA3_MIXER4_CTRL0_REG,     SPA3_MIXER4_GAIN4_OFFSET,         0x3,  0), \

#endif
#define PGA_KCONTROLS \
	SOC_SINGLE("ADC2_SPAI_CIC_GAIN",        SPA2_ADC_FILTER_REG,    ADC2_SPAI_CIC_GAIN_OFFSET,         0x3f, 0), \
	SOC_SINGLE("ADC2_SPAV_CIC_GAIN",        SPA2_ADC_FILTER_REG,    ADC2_SPAV_CIC_GAIN_OFFSET,         0x3f, 0), \
	SOC_SINGLE("ADC3_SPAI_CIC_GAIN",        SPA3_ADC_FILTER_REG,    ADC3_SPAI_CIC_GAIN_OFFSET,         0x3f, 0), \
	SOC_SINGLE("ADC3_SPAV_CIC_GAIN",        SPA3_ADC_FILTER_REG,    ADC3_SPAV_CIC_GAIN_OFFSET,         0x3f, 0), \

#define CLASSH2_KCONTROLS \
	SOC_SINGLE("CLASSH2_BYPASS",        CLASSH2_CTRL1_REG,   CLASSH2_BYPASS_OFFSET,                    0x1,    0), \
	SOC_SINGLE("CLASSH2_FALL_DELAY",    CLASSH2_CTRL1_REG,   CLASSH2_FALL_DELAY_DF_CFG_OFFSET,         0x7fff, 0), \
	SOC_SINGLE("CLASSH2_DO_CFG",        CLASSH2_CTRL1_REG,   CLASSH2_DO_CFG_OFFSET,                    0xf,    0), \
	SOC_SINGLE("CLASSH2_FALL_DELAY_EN", CLASSH2_CTRL1_REG,   CLASSH2_FALL_DELAY_EN_OFFSET,             0x1,    0), \
	SOC_SINGLE("CLASSH2_DN_CFG",        CLASSH2_CTRL1_REG,   CLASSH2_DN_CFG_OFFSET,                    0xf,    0), \
	SOC_SINGLE("CLASSH2_FALL_STEP",     CLASSH2_CTRL2_REG,   CLASSH2_FALL_STEP_OFFSET,                 0x3f,   0), \
	SOC_SINGLE("CLASSH2_REG_VCTRL1",    CLASSH2_CTRL2_REG,   CLASSH2_REG_VCTRL1_OFFSET,                0xff,   0), \
	SOC_SINGLE("CLASSH2_EN",            CLASSH2_CTRL2_REG,   CLASSH2_EN_OFFSET,                        0x1,    0), \
	SOC_SINGLE("CLASSH2_DYM_EN",        CLASSH2_CTRL2_REG,   CLASSH2_DYM_EN_OFFSET,                    0x1,    0), \
	SOC_SINGLE("CLASSH2_PGA_GAIN",      CLASSH2_CTRL2_REG,   CLASSH2_PGA_GAIN_OFFSET,                  0x1ff,  0), \

#define CLASSH3_KCONTROLS \
	SOC_SINGLE("CLASSH3_BYPASS",        CLASSH3_CTRL1_REG,   CLASSH3_BYPASS_OFFSET,            0x1,    0), \
	SOC_SINGLE("CLASSH3_FALL_DELAY",    CLASSH3_CTRL1_REG,   CLASSH3_FALL_DELAY_DF_CFG_OFFSET, 0x7fff, 0), \
	SOC_SINGLE("CLASSH3_DO_CFG",        CLASSH3_CTRL1_REG,   CLASSH3_DO_CFG_OFFSET,            0xf,    0), \
	SOC_SINGLE("CLASSH3_FALL_DELAY_EN", CLASSH3_CTRL1_REG,   CLASSH3_FALL_DELAY_EN_OFFSET,     0x1,    0), \
	SOC_SINGLE("CLASSH3_DN_CFG",        CLASSH3_CTRL1_REG,   CLASSH3_DN_CFG_OFFSET,            0xf,    0), \
	SOC_SINGLE("CLASSH3_FALL_STEP",     CLASSH3_CTRL2_REG,   CLASSH3_FALL_STEP_OFFSET,         0x3f,   0), \
	SOC_SINGLE("CLASSH3_REG_VCTRL1",    CLASSH3_CTRL2_REG,   CLASSH3_REG_VCTRL1_OFFSET,        0xff,   0), \
	SOC_SINGLE("CLASSH3_EN",            CLASSH3_CTRL2_REG,   CLASSH3_EN_OFFSET,                0x1,    0), \
	SOC_SINGLE("CLASSH3_DYM_EN",        CLASSH3_CTRL2_REG,   CLASSH3_DYM_EN_OFFSET,            0x1,    0), \
	SOC_SINGLE("CLASSH3_PGA_GAIN",      CLASSH3_CTRL2_REG,   CLASSH3_PGA_GAIN_OFFSET,          0x1ff,  0), \


#define LUT2_KCONTROLS \
	SOC_SINGLE("CLASSH2_LUT_REG0_3",    CLASS2_LUT_REG0_3_REG,     CLASSH2_LUT_REG0_OFFSET,   0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG4_7",    CLASS2_LUT_REG4_7_REG,     CLASSH2_LUT_REG4_OFFSET,   0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG8_11",   CLASS2_LUT_REG8_11_REG,    CLASSH2_LUT_REG8_OFFSET,   0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG12_15",  CLASS2_LUT_REG12_15_REG,   CLASSH2_LUT_REG12_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG16_19",  CLASS2_LUT_REG16_19_REG,   CLASSH2_LUT_REG16_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG20_23",  CLASS2_LUT_REG20_23_REG,   CLASSH2_LUT_REG20_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG24_27",  CLASS2_LUT_REG24_27_REG,   CLASSH2_LUT_REG24_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG28_31",  CLASS2_LUT_REG28_31_REG,   CLASSH2_LUT_REG28_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG32_35",  CLASS2_LUT_REG32_35_REG,   CLASSH2_LUT_REG32_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG36_39",  CLASS2_LUT_REG36_39_REG,   CLASSH2_LUT_REG36_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG40_43",  CLASS2_LUT_REG40_43_REG,   CLASSH2_LUT_REG40_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG44_47",  CLASS2_LUT_REG44_47_REG,   CLASSH2_LUT_REG44_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG48_51",  CLASS2_LUT_REG48_51_REG,   CLASSH2_LUT_REG48_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG52_55",  CLASS2_LUT_REG52_55_REG,   CLASSH2_LUT_REG52_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG56_59",  CLASS2_LUT_REG56_59_REG,   CLASSH2_LUT_REG56_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG60_63",  CLASS2_LUT_REG60_63_REG,   CLASSH2_LUT_REG60_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH2_LUT_REG64_67",  CLASS2_LUT_REG64_67_REG,   CLASSH2_LUT_REG64_OFFSET,  0x7fffffff,  0), \

#define LUT3_KCONTROLS \
	SOC_SINGLE("CLASSH3_LUT_REG0_3",    CLASSH3_LUT_REG0_3_REG,     CLASSH3_LUT_REG0_OFFSET,   0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG4_7",    CLASSH3_LUT_REG4_7_REG,     CLASSH3_LUT_REG4_OFFSET,   0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG8_11",   CLASSH3_LUT_REG8_11_REG,    CLASSH3_LUT_REG8_OFFSET,   0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG12_15",  CLASSH3_LUT_REG12_15_REG,   CLASSH3_LUT_REG12_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG16_19",  CLASSH3_LUT_REG16_19_REG,   CLASSH3_LUT_REG16_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG20_23",  CLASSH3_LUT_REG20_23_REG,   CLASSH3_LUT_REG20_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG24_27",  CLASSH3_LUT_REG24_27_REG,   CLASSH3_LUT_REG24_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG28_31",  CLASSH3_LUT_REG28_31_REG,   CLASSH3_LUT_REG28_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG32_35",  CLASSH3_LUT_REG32_35_REG,   CLASSH3_LUT_REG32_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG36_39",  CLASSH3_LUT_REG36_39_REG,   CLASSH3_LUT_REG36_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG40_43",  CLASSH3_LUT_REG40_43_REG,   CLASSH3_LUT_REG40_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG44_47",  CLASSH3_LUT_REG44_47_REG,   CLASSH3_LUT_REG44_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG48_51",  CLASSH3_LUT_REG48_51_REG,   CLASSH3_LUT_REG48_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG52_55",  CLASSH3_LUT_REG52_55_REG,   CLASSH3_LUT_REG52_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG56_59",  CLASSH3_LUT_REG56_59_REG,   CLASSH3_LUT_REG56_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG60_63",  CLASSH3_LUT_REG60_63_REG,   CLASSH3_LUT_REG60_OFFSET,  0x7fffffff,  0), \
	SOC_SINGLE("CLASSH3_LUT_REG64_67",  CLASSH3_LUT_REG64_67_REG,   CLASSH3_LUT_REG64_OFFSET,  0x7fffffff,  0), \

static const struct snd_kcontrol_new au_pa_controls[] = {
#ifdef CONFIG_SND_SOC_CODEC_DA_SEPARATE_V6B
	MIXER4_PGA_KCONTROLS
#endif
	PGA_KCONTROLS
	CLASSH2_KCONTROLS
	CLASSH3_KCONTROLS
	LUT2_KCONTROLS
	LUT3_KCONTROLS
};

#define AU_PA_INPUT_OUTPUT_WIDGET \
	SND_SOC_DAPM_INPUT("AU_PA2_DLINK INPUT"), \
	SND_SOC_DAPM_INPUT("AU_PA3_DLINK INPUT"), \
	SND_SOC_DAPM_INPUT("ADC_SPA2 INPUT"), \
	SND_SOC_DAPM_INPUT("ADC_SPA3 INPUT"), \
	SND_SOC_DAPM_OUTPUT("DACL_SPA2 OUTPUT"), \
	SND_SOC_DAPM_OUTPUT("DACR_SPA3 OUTPUT"), \
	SND_SOC_DAPM_OUTPUT("ADC2_SPAI OUTPUT"), \
	SND_SOC_DAPM_OUTPUT("ADC2_SPAV OUTPUT"), \
	SND_SOC_DAPM_OUTPUT("ADC3_SPAI OUTPUT"), \
	SND_SOC_DAPM_OUTPUT("ADC3_SPAV OUTPUT"), \
	SND_SOC_DAPM_OUTPUT("AU_PA2 OUTPUT"), \
	SND_SOC_DAPM_OUTPUT("AU_PA3 OUTPUT"), \

static int audio_dl_pga_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* clear fifo */
		da_separate_update_bits(codec, CODEC_CLK_EN0_REG,
			BIT(AUDIO_L_DN_AFIFO_CLKEN_OFFSET), 0);

		udelay(CLEAR_FIFO_DELAY_LEN_MS);

		/* pga/fifo clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN0_REG,
			BIT(AUDIO_L_DN_PGA_CLKEN_OFFSET) |
			BIT(AUDIO_L_DN_AFIFO_CLKEN_OFFSET),
			BIT(AUDIO_L_DN_PGA_CLKEN_OFFSET) |
			BIT(AUDIO_L_DN_AFIFO_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* fifo clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN0_REG,
			BIT(AUDIO_L_DN_PGA_CLKEN_OFFSET) |
			BIT(AUDIO_L_DN_AFIFO_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

static int audio_dr_pga_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* clear fifo */
		da_separate_update_bits(codec, CODEC_CLK_EN0_REG,
			BIT(AUDIO_R_DN_AFIFO_CLKEN_OFFSET), 0);

		udelay(CLEAR_FIFO_DELAY_LEN_MS);

		/* pga/fifo clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN0_REG,
			BIT(AUDIO_R_DN_PGA_CLKEN_OFFSET) |
			BIT(AUDIO_R_DN_AFIFO_CLKEN_OFFSET),
			BIT(AUDIO_R_DN_PGA_CLKEN_OFFSET) |
			BIT(AUDIO_R_DN_AFIFO_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* fifo/pga clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN0_REG,
			BIT(AUDIO_R_DN_PGA_CLKEN_OFFSET) |
			BIT(AUDIO_R_DN_AFIFO_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

#define AU_PA_PGA_WIDGET \
	SND_SOC_DAPM_PGA_E("AUDIO_DL PGA", SND_SOC_NOPM, 0, 0, NULL, 0, \
		audio_dl_pga_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \
	SND_SOC_DAPM_PGA_E("AUDIO_DR PGA", SND_SOC_NOPM, 0, 0, NULL, 0, \
		audio_dr_pga_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \

static const struct snd_kcontrol_new au_pa2_en_mixer[] = {
	SOC_DAPM_SINGLE("AU_PA2_DAC_EN", VIR1_ADDR, REG_BIT3, 1, 0),
	SOC_DAPM_SINGLE("AU_PA2_ADC_EN", VIR1_ADDR, REG_BIT12, 1, 0),
};

static const struct snd_kcontrol_new au_pa3_en_mixer[] = {
	SOC_DAPM_SINGLE("AU_PA3_DAC_EN", VIR1_ADDR, REG_BIT4, 1, 0),
	SOC_DAPM_SINGLE("AU_PA3_ADC_EN", VIR1_ADDR, REG_BIT13, 1, 0),
};

#ifdef CONFIG_SND_SOC_CODEC_DA_SEPARATE_V6B
static const struct snd_kcontrol_new au_pa_dl_mixer[] = {
	SOC_DAPM_SINGLE("IN1_VOICE_DL", SPA2_MIXER4_CTRL0_REG,
		SPA2_MIXER4_IN1_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN2_FM_L", SPA2_MIXER4_CTRL0_REG,
		SPA2_MIXER4_IN2_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN3_ULTR_DN", SPA2_MIXER4_CTRL0_REG,
		SPA2_MIXER4_IN3_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN4_FM_R", SPA2_MIXER4_CTRL0_REG,
		SPA2_MIXER4_IN4_MUTE_OFFSET, 1, 1),
};

static const struct snd_kcontrol_new au_pa_dr_mixer[] = {
	SOC_DAPM_SINGLE("IN1_VOICE_DR", SPA3_MIXER4_CTRL0_REG,
		SPA3_MIXER4_IN1_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN2_FM_R", SPA3_MIXER4_CTRL0_REG,
		SPA3_MIXER4_IN2_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN3_ULTR_DN", SPA3_MIXER4_CTRL0_REG,
		SPA3_MIXER4_IN3_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN4_FM_L", SPA3_MIXER4_CTRL0_REG,
		SPA3_MIXER4_IN4_MUTE_OFFSET, 1, 1),
};

#define AU_PA_MIXER_WIDGET \
	SND_SOC_DAPM_MIXER("AU_PA_DL MIXER", 0, 0, 0, \
		au_pa_dl_mixer, ARRAY_SIZE(au_pa_dl_mixer)), \
	SND_SOC_DAPM_MIXER("AU_PA_DR MIXER", 0, 0, 0, \
		au_pa_dr_mixer, ARRAY_SIZE(au_pa_dr_mixer)), \
	SND_SOC_DAPM_MIXER("AU_PA2_EN MIXER", CODEC_CLK_EN2_REG, AU2_MST_CLKEN_OFFSET, 0, \
		au_pa2_en_mixer, ARRAY_SIZE(au_pa2_en_mixer)), \
	SND_SOC_DAPM_MIXER("AU_PA3_EN MIXER", CODEC_CLK_EN2_REG, AU3_MST_CLKEN_OFFSET, 0, \
		au_pa3_en_mixer, ARRAY_SIZE(au_pa3_en_mixer)), \

#else
static const struct snd_kcontrol_new au_pa_dl_mixer[] = {
	SOC_DAPM_SINGLE("IN1_FM_L", DACL_MIXER4_CTRL0_REG,
		DACL_MIXER4_IN1_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN2_VOICE_DL", DACL_MIXER4_CTRL0_REG,
		DACL_MIXER4_IN2_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN3_AUDIO_DL", DACL_MIXER4_CTRL0_REG,
		DACL_MIXER4_IN3_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN4_SIDETONE", DACL_MIXER4_CTRL0_REG,
		DACL_MIXER4_IN4_MUTE_OFFSET, 1, 1),
};

static const struct snd_kcontrol_new au_pa_dr_mixer[] = {
	SOC_DAPM_SINGLE("IN1_FM_R", DACR_MIXER4_CTRL0_REG,
		DACR_MIXER4_IN1_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN2_VOICE_DR", DACR_MIXER4_CTRL0_REG,
		DACR_MIXER4_IN2_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN3_AUDIO_DR", DACR_MIXER4_CTRL0_REG,
		DACR_MIXER4_IN3_MUTE_OFFSET, 1, 1),
	SOC_DAPM_SINGLE("IN4_SIDETONE", DACR_MIXER4_CTRL0_REG,
		DACR_MIXER4_IN4_MUTE_OFFSET, 1, 1),
};

#define AU_PA_MIXER_WIDGET \
	SND_SOC_DAPM_MIXER("AU_PA_DL MIXER", CODEC_CLK_EN0_REG, DACL_MIXER4_CLKEN_OFFSET, 0, \
		au_pa_dl_mixer, ARRAY_SIZE(au_pa_dl_mixer)), \
	SND_SOC_DAPM_MIXER("AU_PA_DR MIXER", CODEC_CLK_EN0_REG, DACR_MIXER4_CLKEN_OFFSET, 0, \
		au_pa_dr_mixer, ARRAY_SIZE(au_pa_dr_mixer)), \
	SND_SOC_DAPM_MIXER("AU_PA2_EN MIXER", CODEC_CLK_EN2_REG, AU2_MST_CLKEN_OFFSET, 0, \
		au_pa2_en_mixer, ARRAY_SIZE(au_pa2_en_mixer)), \
	SND_SOC_DAPM_MIXER("AU_PA3_EN MIXER", CODEC_CLK_EN2_REG, AU3_MST_CLKEN_OFFSET, 0, \
		au_pa3_en_mixer, ARRAY_SIZE(au_pa3_en_mixer)), \

#endif

static int adc2_spai_filter_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* filter clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPAI_CLKEN_OFFSET), BIT(ADC2_SPAI_CLKEN_OFFSET));
		/* AU ADC_SPA enable */
		da_separate_update_bits(codec, AU2_3_CTRL_REG,
			BIT(AU2_SPA_ADC_EN_OFFSET), BIT(AU2_SPA_ADC_EN_OFFSET));
		/* ADC2_SPI clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPI_UP_AFIFO_CLKEN_OFFSET), BIT(ADC2_SPI_UP_AFIFO_CLKEN_OFFSET));
		/* ADC2_SPI/SPV dma enable */
		da_separate_update_bits(codec, R_CODEC_DMA_SEL,
			BIT(SPA_DMA_SEL_OFFSET), BIT(SPA_DMA_SEL_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* ADC2_SPI/SPV dma disable */
		da_separate_update_bits(codec, R_CODEC_DMA_SEL,
			BIT(SPA_DMA_SEL_OFFSET), 0x0);
		/* filter clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPAI_CLKEN_OFFSET), 0);
		/* AU ADC_SPA disable */
		da_separate_update_bits(codec, AU2_3_CTRL_REG,
			BIT(AU2_SPA_ADC_EN_OFFSET), 0);
		/* ADC2_SPI clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPI_UP_AFIFO_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

static int adc2_spav_filter_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* filter clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPAV_CLKEN_OFFSET), BIT(ADC2_SPAV_CLKEN_OFFSET));
		/* ADC2_SPV clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPV_UP_AFIFO_CLKEN_OFFSET), BIT(ADC2_SPV_UP_AFIFO_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* filter clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPAV_CLKEN_OFFSET), 0);
		/* ADC2_SPV clk dsiable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC2_SPV_UP_AFIFO_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

static int adc3_spai_filter_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* filter clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPAI_CLKEN_OFFSET), BIT(ADC3_SPAI_CLKEN_OFFSET));
		/* AU ADC_SPA enable */
		da_separate_update_bits(codec, AU2_3_CTRL_REG,
			BIT(AU3_SPA_ADC_EN_OFFSET), BIT(AU3_SPA_ADC_EN_OFFSET));
		/* ADC3_SPI clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPI_UP_AFIFO_CLKEN_OFFSET), BIT(ADC3_SPI_UP_AFIFO_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* filter clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPAI_CLKEN_OFFSET), 0);
		/* AU ADC_SPA disable */
		da_separate_update_bits(codec, AU2_3_CTRL_REG,
			BIT(AU3_SPA_ADC_EN_OFFSET), 0);
		/* ADC3_SPI clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPI_UP_AFIFO_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

static int adc3_spav_filter_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* filter clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPAV_CLKEN_OFFSET), BIT(ADC3_SPAV_CLKEN_OFFSET));
		/* ADC3_SPV clk enable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPV_UP_AFIFO_CLKEN_OFFSET), BIT(ADC3_SPV_UP_AFIFO_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		/* filter clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPAV_CLKEN_OFFSET), 0);
		/* ADC3_SPV clk disable */
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(ADC3_SPV_UP_AFIFO_CLKEN_OFFSET), 0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

static int au_pa2_dacl_filter_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		da_separate_update_bits(codec, SPA_SDM_CTRL_REG,
			BIT(SPA2_SDM_CALM_VLD_OFFSET), BIT(SPA2_SDM_CALM_VLD_OFFSET));
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(SPA2_DAC_FILTER_CLKEN_OFFSET) | BIT(SPA2_UP16_CLKEN_OFFSET) | BIT(SPA2_SDM_CLKEN_OFFSET),
			BIT(SPA2_DAC_FILTER_CLKEN_OFFSET) | BIT(SPA2_UP16_CLKEN_OFFSET) | BIT(SPA2_SDM_CLKEN_OFFSET));
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(CLASSH2_CLKEN_OFFSET), BIT(CLASSH2_CLKEN_OFFSET));
		if (au_pa_cfg_iomux(NORMAL_MODE) != 0)
			AUDIO_LOGE("cfg au pa iomux failed\n");
		break;
	case SND_SOC_DAPM_PRE_PMD:
		if (au_pa_cfg_iomux(LOWPOWER_MODE) != 0)
			AUDIO_LOGE("cfg au pa iomux failed\n");
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(CLASSH2_CLKEN_OFFSET), 0);
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(SPA2_DAC_FILTER_CLKEN_OFFSET) | BIT(SPA2_UP16_CLKEN_OFFSET) | BIT(SPA2_SDM_CLKEN_OFFSET),
			0x0);
		da_separate_update_bits(codec, SPA_SDM_CTRL_REG,
			BIT(SPA2_SDM_CALM_VLD_OFFSET), 0x0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

static int au_pa3_dacr_filter_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *codec = snd_soc_dapm_to_component(w->dapm);

	IN_FUNCTION;

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		da_separate_update_bits(codec, SPA_SDM_CTRL_REG,
			BIT(SPA3_SDM_CALM_VLD_OFFSET), BIT(SPA3_SDM_CALM_VLD_OFFSET));
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(SPA3_DAC_FILTER_CLKEN_OFFSET) | BIT(SPA3_UP16_CLKEN_OFFSET) | BIT(SPA3_SDM_CLKEN_OFFSET),
			BIT(SPA3_DAC_FILTER_CLKEN_OFFSET) | BIT(SPA3_UP16_CLKEN_OFFSET) | BIT(SPA3_SDM_CLKEN_OFFSET));
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(CLASSH3_CLKEN_OFFSET), BIT(CLASSH3_CLKEN_OFFSET));
		break;
	case SND_SOC_DAPM_PRE_PMD:
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(CLASSH3_CLKEN_OFFSET), 0);
		da_separate_update_bits(codec, CODEC_CLK_EN2_REG,
			BIT(SPA3_DAC_FILTER_CLKEN_OFFSET) | BIT(SPA3_UP16_CLKEN_OFFSET) | BIT(SPA3_SDM_CLKEN_OFFSET),
			0x0);
		da_separate_update_bits(codec, SPA_SDM_CTRL_REG,
			BIT(SPA3_SDM_CALM_VLD_OFFSET), 0x0);
		break;
	default:
		AUDIO_LOGE("power mode event err: %d", event);
		break;
	}

	OUT_FUNCTION;

	return 0;
}

#define AU_PA_FILTER_WIDGET \
	SND_SOC_DAPM_PGA_E("ADC2_SPAI_FILTER", SND_SOC_NOPM, 0, 0, NULL, 0, \
		adc2_spai_filter_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \
	SND_SOC_DAPM_PGA_E("ADC2_SPAV_FILTER", SND_SOC_NOPM, 0, 0, NULL, 0, \
		adc2_spav_filter_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \
	SND_SOC_DAPM_PGA_E("ADC3_SPAI_FILTER", SND_SOC_NOPM, 0, 0, NULL, 0, \
		adc3_spai_filter_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \
	SND_SOC_DAPM_PGA_E("ADC3_SPAV_FILTER", SND_SOC_NOPM, 0, 0, NULL, 0, \
		adc3_spav_filter_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \
	SND_SOC_DAPM_PGA_E("AU_PA2_DACL_FILTER", SND_SOC_NOPM, 0, 0, NULL, 0, \
		au_pa2_dacl_filter_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \
	SND_SOC_DAPM_PGA_E("AU_PA3_DACR_FILTER", SND_SOC_NOPM, 0, 0, NULL, 0, \
		au_pa3_dacr_filter_event, (SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD)), \

static const struct snd_kcontrol_new dac_spa2_switch[] = {
	SOC_DAPM_SINGLE("DAC_SPA2_EN",
		AU2_3_CTRL_REG, AU2_SPA_DAC_EN_OFFSET, 1, 0),
};

static const struct snd_kcontrol_new dac_spa3_switch[] = {
	SOC_DAPM_SINGLE("DAC_SPA3_EN",
		AU2_3_CTRL_REG, AU3_SPA_DAC_EN_OFFSET, 1, 0),
};

static const struct snd_kcontrol_new au_pa2_virtual_switch[] = {
	SOC_DAPM_SINGLE("AU_PA2_EN",
		VIR1_ADDR, REG_BIT30, 1, 0),
};

static const struct snd_kcontrol_new au_pa3_virtual_switch[] = {
	SOC_DAPM_SINGLE("AU_PA3_EN",
		VIR1_ADDR, REG_BIT31, 1, 0),
};

#define AU_PA_SWITCH_WIDGET \
	SND_SOC_DAPM_SWITCH("DAC_SPA2 SWITCH", SND_SOC_NOPM, 0, 0, dac_spa2_switch), \
	SND_SOC_DAPM_SWITCH("DAC_SPA3 SWITCH", SND_SOC_NOPM, 0, 0, dac_spa3_switch), \
	SND_SOC_DAPM_SWITCH("AU_PA2 SWITCH", SND_SOC_NOPM, 0, 0, au_pa2_virtual_switch), \
	SND_SOC_DAPM_SWITCH("AU_PA3 SWITCH", SND_SOC_NOPM, 0, 0, au_pa3_virtual_switch), \

static const struct snd_soc_dapm_widget au_pa_dapm_widgets[] = {
	AU_PA_INPUT_OUTPUT_WIDGET
	AU_PA_PGA_WIDGET
	AU_PA_MIXER_WIDGET
	AU_PA_FILTER_WIDGET
	AU_PA_SWITCH_WIDGET
};
#ifdef CONFIG_SND_SOC_CODEC_DA_SEPARATE_V6B
#define AU_PA_DOWNLINK \
	{ "VOICE_DL PGA",             NULL,                "AU_PA2_DLINK INPUT" }, \
	{ "VOICE_DR PGA",             NULL,                "AU_PA3_DLINK INPUT" }, \
	{ "VOICE_DL PGA",             NULL,                "PLL" }, \
	{ "VOICE_DR PGA",             NULL,                "PLL" }, \
	{ "AU_PA2 SWITCH",            "AU_PA2_EN",         "VOICE_DL PGA" }, \
	{ "AU_PA3 SWITCH",            "AU_PA3_EN",         "VOICE_DR PGA" }, \
	{ "AU_PA2 OUTPUT",            NULL,                "AU_PA2 SWITCH" }, \
	{ "AU_PA3 OUTPUT",            NULL,                "AU_PA3 SWITCH" }, \
	{ "AU_PA_DL MIXER",           "IN1_VOICE_DL",      "VOICE_DL PGA" }, \
	{ "AU_PA_DR MIXER",           "IN1_VOICE_DR",      "VOICE_DR PGA" }, \
	{ "AU_PA_DL MIXER",           "IN2_FM_L",          "S2_SRC_RX SWITCH" }, \
	{ "AU_PA_DR MIXER",           "IN2_FM_R",          "S2_SRC_RX SWITCH" }, \
	{ "AU_PA_DL MIXER",           "IN3_ULTR_DN",       "ULTR_DLINK_EN MIXER" }, \
	{ "AU_PA_DR MIXER",           "IN3_ULTR_DN",       "ULTR_DLINK_EN MIXER" }, \
	{ "AU_PA_DL MIXER",           "IN4_FM_R",          "S2_SRC_RX SWITCH" }, \
	{ "AU_PA_DR MIXER",           "IN4_FM_L",          "S2_SRC_RX SWITCH" }, \
	{ "AU_PA2_DACL_FILTER",       NULL,                "AU_PA_DL MIXER" }, \
	{ "AU_PA3_DACR_FILTER",       NULL,                "AU_PA_DR MIXER" }, \
	{ "DAC_SPA2 SWITCH",          "DAC_SPA2_EN",       "AU_PA2_DACL_FILTER" }, \
	{ "DAC_SPA3 SWITCH",          "DAC_SPA3_EN",       "AU_PA3_DACR_FILTER" }, \
	{ "AU_PA2_EN MIXER",          "AU_PA2_DAC_EN",     "DAC_SPA2 SWITCH" }, \
	{ "AU_PA3_EN MIXER",          "AU_PA3_DAC_EN",     "DAC_SPA3 SWITCH" }, \
	{ "DACL_SPA2 OUTPUT",          NULL,               "AU_PA2_EN MIXER" }, \
	{ "DACR_SPA3 OUTPUT",          NULL,               "AU_PA3_EN MIXER" }, \

#else
#define AU_PA_DOWNLINK \
	{ "AUDIO_DL PGA",             NULL,                "AU_PA2_DLINK INPUT" }, \
	{ "AUDIO_DR PGA",             NULL,                "AU_PA3_DLINK INPUT" }, \
	{ "VOICE_DL PGA",             NULL,                "PLL" }, \
	{ "VOICE_DR PGA",             NULL,                "PLL" }, \
	{ "AU_PA2 SWITCH",            "AU_PA2_EN",         "AUDIO_DL PGA" }, \
	{ "AU_PA3 SWITCH",            "AU_PA3_EN",         "AUDIO_DR PGA" }, \
	{ "AU_PA2 OUTPUT",            NULL,                "AU_PA2 SWITCH" }, \
	{ "AU_PA3 OUTPUT",            NULL,                "AU_PA3 SWITCH" }, \
	{ "AU_PA_DL MIXER",           "IN3_AUDIO_DL",      "AUDIO_DL PGA" }, \
	{ "AU_PA_DR MIXER",           "IN3_AUDIO_DR",      "AUDIO_DR PGA" }, \
	{ "AU_PA_DL MIXER",           "IN1_FM_L",          "S2_SRC_RX SWITCH" }, \
	{ "AU_PA_DR MIXER",           "IN1_FM_R",          "S2_SRC_RX SWITCH" }, \
	{ "AU_PA2_DACL_FILTER",       NULL,                "AU_PA_DL MIXER" }, \
	{ "AU_PA3_DACR_FILTER",       NULL,                "AU_PA_DR MIXER" }, \
	{ "DAC_SPA2 SWITCH",          "DAC_SPA2_EN",       "AU_PA2_DACL_FILTER" }, \
	{ "DAC_SPA3 SWITCH",          "DAC_SPA3_EN",       "AU_PA3_DACR_FILTER" }, \
	{ "AU_PA2_EN MIXER",          "AU_PA2_DAC_EN",     "DAC_SPA2 SWITCH" }, \
	{ "AU_PA3_EN MIXER",          "AU_PA3_DAC_EN",     "DAC_SPA3 SWITCH" }, \
	{ "DACL_SPA2 OUTPUT",         NULL,                "AU_PA2_EN MIXER" }, \
	{ "DACR_SPA3 OUTPUT",         NULL,                "AU_PA3_EN MIXER" }, \

#endif
#define AU_PA_UPLINK \
	{ "AU_PA2_EN MIXER",           "AU_PA2_ADC_EN",     "ADC_SPA2 INPUT" }, \
	{ "AU_PA3_EN MIXER",           "AU_PA3_ADC_EN",     "ADC_SPA3 INPUT" }, \
	{ "ADC2_SPAI_FILTER",          NULL,                "AU_PA2_EN MIXER" }, \
	{ "ADC2_SPAV_FILTER",          NULL,                "AU_PA2_EN MIXER" }, \
	{ "ADC3_SPAI_FILTER",          NULL,                "AU_PA3_EN MIXER" }, \
	{ "ADC3_SPAV_FILTER",          NULL,                "AU_PA3_EN MIXER" }, \
	{ "ADC2_SPAI OUTPUT",          NULL,                "ADC2_SPAI_FILTER" }, \
	{ "ADC2_SPAV OUTPUT",          NULL,                "ADC2_SPAV_FILTER" }, \
	{ "ADC3_SPAI OUTPUT",          NULL,                "ADC3_SPAI_FILTER" }, \
	{ "ADC3_SPAV OUTPUT",          NULL,                "ADC3_SPAV_FILTER" }, \

static const struct snd_soc_dapm_route au_pa_route_map[] = {
	AU_PA_DOWNLINK
	AU_PA_UPLINK
};

static struct snd_codec_resource au_pa_resource = {
	au_pa_controls,
	ARRAY_SIZE(au_pa_controls),
	au_pa_dapm_widgets,
	ARRAY_SIZE(au_pa_dapm_widgets),
	au_pa_route_map,
	ARRAY_SIZE(au_pa_route_map),
};

int add_au_pa(struct snd_soc_component *codec)
{
	if (codec == NULL) {
		AUDIO_LOGE("parameter is null");
		return -EINVAL;
	}

	return da_separate_add_codec_resource(codec, &au_pa_resource);
}
