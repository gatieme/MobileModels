/*
  * boot time implementation
  *
  * Copyright (c) 2019-2019 Honor Technologies Co., Ltd.
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

#ifndef _HW_BOOTTIME_H_
#define _HW_BOOTTIME_H_
#ifdef CONFIG_BOOT_TIME
#include <linux/init.h>
int __init_or_module do_boottime_initcall(initcall_t fn);
void log_boot(char *str);
#endif
#endif
