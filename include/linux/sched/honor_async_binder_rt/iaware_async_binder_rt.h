/*
 * iaware_async_binder_rt.h
 *
 * Async binder rt priority declaration
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

#ifndef IAWARE_ASYNC_BINDER_RT_H
#define IAWARE_ASYNC_BINDER_RT_H

#define BINDER_CODE_FIRST 1
#define BINDER_DESCRIPTOR_OFFSET 16
#define BINDER_DESCRIPTOR_BYTE_SIZE 128
#define ASYNC_BINDER_RT_FROM_THREAD "surfaceflinger"

extern unsigned int g_sysctl_async_binder_rt_switch;

struct async_binder_rt_config_node {
	char *service_name;
	unsigned int name_length;
};

const char* get_descriptor_with_index(unsigned int index);
unsigned int get_descriptor_size_with_index(unsigned int index);
unsigned int get_descriptor_count(void);

#endif

