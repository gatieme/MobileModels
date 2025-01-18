/*
 * da_separate_fpga.c is used to work by da_separate_fpga.
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

#include "da_separate_fpga.h"
#include "audio_log.h"
#include "asoc_adapter.h"
#include "da_separate_v5_asp_reg_def.h"

#define LOG_TAG "da_separate_fpga"
#define PMU_CODEC_VERSION           0x36
#define DA_SEPARATE_PMU_CODEC_BASE       0x0

void au0_io_init(struct snd_soc_component *codec)
{
	unsigned int i;
	struct dev_node_au0 {
		char *node;
		unsigned int offset;
	};

	struct dev_node_au0 au0_io[] = {
		{"au0_clk_offset", 0},
		{"au0_flag_offset", 0},
		{"au0_dout0_offset", 0},
		{"au0_din0_offset", 0},
		{"au0_dout1_offset", 0},
		{"au0_din1_offset", 0}
	};

	for (i = 0; i < ARRAY_SIZE(au0_io); i++) {
		if (of_property_read_u32(codec->dev->of_node, au0_io[i].node, &au0_io[i].offset)) {
			AUDIO_LOGW("au0 io offset %d is not configed", i);
			return;
		}
		snd_soc_component_write_adapter(codec, ASP_AO_IOC_BASE + au0_io[i].offset, 0x1);
	}
}

bool is_pmu_version_valid(struct snd_soc_component *codec)
{
	unsigned int pmu_version = snd_soc_component_read32(codec, DA_SEPARATE_PMU_CODEC_BASE);
	/* pmu codec version must equal to 0x36 */
	if (pmu_version != PMU_CODEC_VERSION) {
		AUDIO_LOGI("pmu version = %d is invalid", pmu_version);
		return false;
	}
	return true;
}
