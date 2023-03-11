/*
 * soundwire_codec_dai.c -- soundwire codec dai driver
 *
 * Copyright (c) 2020 Huawei Technologies Co., Ltd.
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

#include <linux/of.h>

#include <linux/platform_drivers/da_combine/da_combine_v5.h>
#include <linux/platform_drivers/da_combine/da_combine_v5_regs.h>
#include <linux/platform_drivers/da_combine/da_combine_v5_type.h>
#include <linux/platform_drivers/da_combine/da_combine_resmgr.h>

#include "codec_bus.h"
#include "codec_dai.h"
#include "audio_log.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "soundwire_codec_dai"

#define FS_SDW_OFFSET 3
#define DAI_LINK_CODEC_DAI_NAME_AUDIO  "da_combine_v5-audio-dai"
#define DAI_LINK_CODEC_DAI_NAME_BT  "da_combine_v5-bt-dai"

struct snd_soc_dai_ops soundwire_audio_dai_ops = {
	.hw_params = codec_dai_hw_params,
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
	.mute_stream = codec_dai_mute_stream,
#else
	.digital_mute = codec_dai_digital_mute,
#endif
};

struct snd_soc_dai_ops soundwire_bt_dai_ops = {
	.hw_params = codec_dai_hw_params,
};

static void soundwire_codec_dai_init(struct snd_soc_component *codec)
{
	struct da_combine_v5_platform_data *priv = snd_soc_component_get_drvdata(codec);

	/* io share */
	snd_soc_component_write_adapter(codec, IOS_MF_CTRL3_REG, 0x4);
	snd_soc_component_write_adapter(codec, IOS_MF_CTRL4_REG, 0x4);
	snd_soc_component_write_adapter(codec, IOS_MF_CTRL5_REG, 0x4);
	snd_soc_component_write_adapter(codec, IOS_IOM_CTRL7_REG, 0x114);
	snd_soc_component_write_adapter(codec, IOS_IOM_CTRL8_REG, 0x114);
	snd_soc_component_write_adapter(codec, IOS_IOM_CTRL9_REG, 0x114);
	da_combine_update_bits(codec, IOS_IOM_CTRL7_REG, MASK_ON_BIT(DS_LEN, DS_OFFSET),
		priv->cdc_ctrl->data_cdc_drv << DS_OFFSET);
	da_combine_update_bits(codec, IOS_IOM_CTRL8_REG, MASK_ON_BIT(DS_LEN, DS_OFFSET),
		priv->cdc_ctrl->clk_cdc_drv << DS_OFFSET);
	da_combine_update_bits(codec, IOS_IOM_CTRL9_REG, MASK_ON_BIT(DS_LEN, DS_OFFSET),
		priv->cdc_ctrl->sdi_cdc_drv << DS_OFFSET);

	/* default 6M */
	snd_soc_component_write_adapter(codec, SLIM_CTRL0_REG, 0xd);
	da_combine_update_bits(codec, SLIM_CTRL1_REG, MASK_ON_BIT(SLIM_SWIRE_DIV_EN_LEN, SLIM_SWIRE_DIV_EN_OFFSET),
		BIT(SLIM_SWIRE_DIV_EN_OFFSET));
	da_combine_update_bits(codec, SLIM_CTRL1_REG, MASK_ON_BIT(SWIRE_CLK_EN_LEN, SWIRE_CLK_EN_OFFSET),
		BIT(SWIRE_CLK_EN_OFFSET));
	da_combine_update_bits(codec, CFG_CLK_CTRL_REG,
		MASK_ON_BIT(INTF_SOUNDWIRE_CLK_EN_LEN,
		INTF_SOUNDWIRE_CLK_EN_OFFSET) | MASK_ON_BIT(INTF_SLIM_CLK_EN_LEN, INTF_SLIM_CLK_EN_OFFSET),
		BIT(INTF_SOUNDWIRE_CLK_EN_OFFSET));
	da_combine_update_bits(codec, SC_CODEC_MUX_CTRL0_REG, MASK_ON_BIT(SLIM_SW_SEL_LEN, SLIM_SW_SEL_OFFSET),
		BIT(SLIM_SW_SEL_OFFSET));

	/* default fs == 48k */
	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL0_REG,
		MASK_ON_BIT(FS_SW_UP1_2_LEN, FS_SW_UP1_2_OFFSET) | MASK_ON_BIT(FS_SW_UP3_4_LEN, FS_SW_UP3_4_OFFSET),
		(0x4 << FS_SW_UP1_2_OFFSET) | (0x4 << FS_SW_UP3_4_OFFSET));
	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL1_REG,
		MASK_ON_BIT(FS_SW_UP5_6_LEN, FS_SW_UP5_6_OFFSET) | MASK_ON_BIT(FS_SW_UP7_8_LEN, FS_SW_UP7_8_OFFSET),
		(0x4 << FS_SW_UP5_6_OFFSET) | (0x4 << FS_SW_UP7_8_OFFSET));
	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL2_REG,
		MASK_ON_BIT(FS_SW_UP9_10_LEN, FS_SW_UP9_10_OFFSET) | MASK_ON_BIT(FS_SW_UP11_12_LEN, FS_SW_UP11_12_OFFSET),
		(0x4 << FS_SW_UP9_10_OFFSET) | (0x4 << FS_SW_UP11_12_OFFSET));
	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL3_REG,
		MASK_ON_BIT(FS_SW_UP13_14_LEN, FS_SW_UP13_14_OFFSET) | MASK_ON_BIT(FS_SW_UP15_16_LEN, FS_SW_UP15_16_OFFSET),
		(0x4 << FS_SW_UP13_14_OFFSET) | (0x4 << FS_SW_UP15_16_OFFSET));
	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL4_REG,
		MASK_ON_BIT(FS_SW_UP17_18_LEN, FS_SW_UP17_18_OFFSET), (0x4 << FS_SW_UP17_18_OFFSET));

	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL5_REG,
		MASK_ON_BIT(FS_SW_DN1_2_LEN, FS_SW_DN1_2_OFFSET) | MASK_ON_BIT(FS_SW_DN3_4_LEN, FS_SW_DN3_4_OFFSET),
		(0x4 << FS_SW_DN1_2_OFFSET) | (0x4 << FS_SW_DN3_4_OFFSET));
	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL6_REG,
		MASK_ON_BIT(FS_SW_DN5_6_LEN, FS_SW_DN5_6_OFFSET) | MASK_ON_BIT(FS_SW_DN7_8_LEN, FS_SW_DN7_8_OFFSET),
		(0x4 << FS_SW_DN5_6_OFFSET) | (0x4 << FS_SW_DN7_8_OFFSET));
	da_combine_update_bits(codec, SC_SOUNDWIRE_FS_CTRL7_REG,
		MASK_ON_BIT(FS_SW_DN9_10_LEN, FS_SW_DN9_10_OFFSET), (0x4 << FS_SW_DN9_10_OFFSET));

	AUDIO_LOGI("soundwire codec dai init");
}

static const struct port_config soundwire_port_cfg[] = {
	{ PORT_D1_D2, SC_SOUNDWIRE_FS_CTRL5_REG },
	{ PORT_D3_D4, SC_SOUNDWIRE_FS_CTRL5_REG },
	{ PORT_D5_D6, SC_SOUNDWIRE_FS_CTRL6_REG },
	{ PORT_D7_D8, SC_SOUNDWIRE_FS_CTRL6_REG },
	{ PORT_D9_D10, SC_SOUNDWIRE_FS_CTRL7_REG },
	{ PORT_U1_U2, SC_SOUNDWIRE_FS_CTRL0_REG },
	{ PORT_U3_U4, SC_SOUNDWIRE_FS_CTRL0_REG },
	{ PORT_U5_U6, SC_SOUNDWIRE_FS_CTRL1_REG },
	{ PORT_U7_U8, SC_SOUNDWIRE_FS_CTRL1_REG },
	{ PORT_U9_U10, SC_SOUNDWIRE_FS_CTRL2_REG },
	{ PORT_U11_U12, SC_SOUNDWIRE_FS_CTRL2_REG },
	{ PORT_U13_U14, SC_SOUNDWIRE_FS_CTRL3_REG },
	{ PORT_U15_U16, SC_SOUNDWIRE_FS_CTRL3_REG },
	{ PORT_U17_U18, SC_SOUNDWIRE_FS_CTRL4_REG }
};

static const struct rate_reg_config soundwire_fs_cfg[] = {
	{ SAMPLE_RATE_8K,   FS_VALUE_8K   << FS_SDW_OFFSET, FS_VALUE_8K },
	{ SAMPLE_RATE_16K,  FS_VALUE_16K  << FS_SDW_OFFSET, FS_VALUE_16K },
	{ SAMPLE_RATE_32K,  FS_VALUE_32K  << FS_SDW_OFFSET, FS_VALUE_32K },
	{ SAMPLE_RATE_48K,  FS_VALUE_48K  << FS_SDW_OFFSET, FS_VALUE_48K },
	{ SAMPLE_RATE_96K,  FS_VALUE_96K  << FS_SDW_OFFSET, FS_VALUE_96K },
	{ SAMPLE_RATE_192K, FS_VALUE_192K << FS_SDW_OFFSET, FS_VALUE_192K },
	{ SAMPLE_RATE_44K1, FS_VALUE_44K1 << FS_SDW_OFFSET, FS_VALUE_44K1 },
	{ SAMPLE_RATE_88K2, FS_VALUE_88K2 << FS_SDW_OFFSET, FS_VALUE_88K2 },
	{ SAMPLE_RATE_176K4, FS_VALUE_176K4 << FS_SDW_OFFSET, FS_VALUE_176K4 }
};

static int soundwire_config_sample_rate(struct snd_soc_component *codec,
	struct codec_dai_sample_rate_params *hwparms)
{
	unsigned int i;
	unsigned int reg;

	for (i = 0; i < ARRAY_SIZE(soundwire_port_cfg); i++) {
		if (hwparms->port == soundwire_port_cfg[i].port) {
			reg = soundwire_port_cfg[i].reg;
			break;
		}
	}

	if (i >= ARRAY_SIZE(soundwire_port_cfg)) {
		AUDIO_LOGE("port invalid argument");
		return -EINVAL;
	}

	for (i = 0; i < ARRAY_SIZE(soundwire_fs_cfg); i++)
		if (hwparms->rate == soundwire_fs_cfg[i].rate)
			break;

	if (i >= ARRAY_SIZE(soundwire_fs_cfg)) {
		AUDIO_LOGE("config sample rate invalid argument");
		return -EINVAL;
	}

	if (hwparms->port == PORT_U9_U10)
		da_combine_update_bits(codec,
			reg,
			MASK_ON_BIT(FS_SW_UP9_10_LEN, FS_SW_UP9_10_OFFSET),
			soundwire_fs_cfg[i].up_bit_val);
	else if (hwparms->port == PORT_U11_U12)
		da_combine_update_bits(codec,
			reg,
			MASK_ON_BIT(FS_SW_UP11_12_LEN, FS_SW_UP11_12_OFFSET),
			soundwire_fs_cfg[i].dn_bit_val);
	else
		snd_soc_component_write_adapter(codec,
			reg,
			soundwire_fs_cfg[i].up_bit_val | soundwire_fs_cfg[i].dn_bit_val);

	return 0;
}

static struct snd_soc_dai_driver soundwire_codec_dai_driver[] = {
	{
		.name = DAI_LINK_CODEC_DAI_NAME_AUDIO,
		.playback = {
			.stream_name = "Playback",
			.channels_min = 2,
			.channels_max = 4,
			.rates = DA_COMBINE_V5_RATES,
			.formats = DA_COMBINE_V5_FORMATS },
		.capture = {
			.stream_name = "Capture",
			.channels_min = 1,
			.channels_max = 13,
			.rates = DA_COMBINE_V5_RATES,
			.formats = DA_COMBINE_V5_FORMATS },
		.ops = &soundwire_audio_dai_ops,
		.probe = codec_dai_probe,
	},
	{
		.name = DAI_LINK_CODEC_DAI_NAME_BT,
		.playback = {
			.stream_name = "Playback",
			.channels_min = 2,
			.channels_max = 2,
			.rates = DA_COMBINE_V5_RATES,
			.formats = DA_COMBINE_V5_FORMATS },
		.capture = {
			.stream_name = "Capture",
			.channels_min = 1,
			.channels_max = 2,
			.rates = DA_COMBINE_V5_RATES,
			.formats = DA_COMBINE_V5_FORMATS },
		.ops = &soundwire_bt_dai_ops,
	},
};

static struct da_combine_v5_codec_dai soundwire_codec_dai = {
	.dai_driver = soundwire_codec_dai_driver,
	.dai_nums = ARRAY_SIZE(soundwire_codec_dai_driver),
	.config_sample_rate = soundwire_config_sample_rate,
	.codec_dai_init = soundwire_codec_dai_init,
};

struct da_combine_v5_codec_dai *get_soundwire_codec_dai(void)
{
	return &soundwire_codec_dai;
}
