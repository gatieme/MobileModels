/*
 * cpufreq_util_freq_hw.h
 *
 * Copyright (c) 2021-2022 Huawei Technologies Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifdef CONFIG_ARCH_QCOM

unsigned int hw_freq_to_util(unsigned int cpu, unsigned int freq);

/*
 * Note that hw_util_to_freq(i, hw_freq_to_util(i, *freq*)) is lower than *freq*.
 * That's ok since we use CPUFREQ_RELATION_L in __cpufreq_driver_target().
 */
unsigned int hw_util_to_freq(unsigned int cpu, unsigned int util);

#endif
