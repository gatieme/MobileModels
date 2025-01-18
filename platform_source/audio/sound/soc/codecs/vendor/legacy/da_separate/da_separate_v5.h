/*
 * da_separate_v5_driver codec driver.
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

#ifndef __DA_SEPARATE_V5_H__
#define __DA_SEPARATE_V5_H__

#include <sound/soc.h>


#define PAGE_PMU_CODEC      0xC000
#define PAGE_PMU_CTRL       0x0
#define PAGE_PMU_HKADC      0x2000
#define PAGE_PMU_CTRL_REGB  0x400

#define SoCCODEC_START      0x0

#ifdef CONFIG_SND_SOC_CODEC_DA_SEPARATE_V6B
#define SoCCODEC_END        0x29c
#else
#define SoCCODEC_END        0x28c
#endif

#define PMUCODEC_START      0x0
#define PMUCODEC_END        0x4c
#define PMUHKADC_START      0x0
#define PMUHKADC_END        0x10

#ifdef CONFIG_BURB_IP_PLATFORM
#define PMUCLASSD_START     0x180
#define PMUCLASSD_END       0x183
#else
#define PMUCLASSD_START     0x17A
#define PMUCLASSD_END       0x17D
#endif

#define PMUCTRL_START       0x0
#define PMUCTRL_END         0x583

#define ASPCFG_START        0x0
#define ASPCFG_END          0x2A8
#define AOIOC_START         0x0
#define AOIOC_END           0xFC0

struct snd_soc_component *da_separate_get_codec(void);

#endif /* __DA_SEPARATE_V5_H__ */

