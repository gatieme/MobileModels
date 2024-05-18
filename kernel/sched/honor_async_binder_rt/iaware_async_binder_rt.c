/*
 * iaware_async_binder_rt.c
 *
 * Async binder rt priority implementation
 *
 * Copyright (c) 2022-2022 Honor Device Co., Ltd.
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

#include <linux/sched/honor_async_binder_rt/iaware_async_binder_rt.h>

unsigned int g_sysctl_async_binder_rt_switch = 0;

const char async_binder_rt_descriptor_releaseBuf[] = {'a', '\0', 'n', '\0', 'd', '\0', 'r', '\0', 'o', '\0',
					   'i', '\0', 'd', '\0', '.', '\0', 'g', '\0', 'u', '\0',
					   'i', '\0', '.', '\0', 'I', '\0', 'T', '\0', 'r', '\0',
					   'a', '\0', 'n', '\0', 's', '\0', 'a', '\0', 'c', '\0',
					   't', '\0', 'i', '\0', 'o', '\0', 'n', '\0', 'C', '\0',
					   'o', '\0', 'm', '\0', 'p', '\0', 'o', '\0', 's', '\0',
					   'e', '\0', 'r', '\0', 'L', '\0', 'i', '\0', 's', '\0',
					   't', '\0', 'e', '\0', 'n', '\0', 'e', '\0', 'r', '\0',
					   '\0'};

const char async_binder_rt_descriptor_surfaceflinger[] = {'a', '\0', 'n', '\0', 'd', '\0', 'r', '\0', 'o', '\0',
					   'i', '\0', 'd', '\0', '.', '\0', 'g', '\0', 'u', '\0',
					   'i', '\0', '.', '\0', 'I', '\0', 'W', '\0', 'i', '\0',
					   'n', '\0', 'd', '\0', 'o', '\0', 'w', '\0', 'I', '\0',
					   'n', '\0', 'f', '\0', 'o', '\0', 's', '\0', 'L', '\0',
					   'i', '\0', 's', '\0', 't', '\0', 'e', '\0', 'n', '\0',
					   'e', '\0', 'r', '\0'};

const struct async_binder_rt_config_node async_binder_rt_config_list[] = {
	{(char*)async_binder_rt_descriptor_releaseBuf,		sizeof(async_binder_rt_descriptor_releaseBuf)},
	{(char*)async_binder_rt_descriptor_surfaceflinger, sizeof(async_binder_rt_descriptor_surfaceflinger)}};

const char* get_descriptor_with_index(unsigned int index)
{
	return async_binder_rt_config_list[index].service_name;
}

unsigned int get_descriptor_size_with_index(unsigned int index)
{
	return async_binder_rt_config_list[index].name_length;
}

unsigned int get_descriptor_count(void)
{
	return sizeof(async_binder_rt_config_list) / sizeof(struct async_binder_rt_config_node);
}

