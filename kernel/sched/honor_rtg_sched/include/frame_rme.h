/*
 * Copyright (c) Honor Device Co., Ltd. 2019-2020. All rights reserved.
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
 * trans rtg thread header
 *
 */

#ifndef HONOR_FRAME_RME_H
#define HONOR_FRAME_RME_H

#ifdef CONFIG_HONOR_RTG_FRAME_RME
int ctrl_rme_state(int freq_type);

long ctrl_set_min_util(unsigned long arg);
long ctrl_set_margin(unsigned long arg);
long ctrl_set_min_util_and_margin(unsigned long arg);
long ctrl_set_rme_margin(unsigned long arg);
long ctrl_get_rme_margin(unsigned long arg);
#else
static inline long ctrl_set_min_util(unsigned long arg)
{
	return 0;
}
static inline long ctrl_set_margin(unsigned long arg)
{
	return 0;
}
static inline long ctrl_set_min_util_and_margin(unsigned long arg)
{
	return 0;
}
static inline long ctrl_set_rme_margin(unsigned long arg)
{
	return 0;
}
static inline long ctrl_get_rme_margin(unsigned long arg)
{
	return 0;
}
#endif /* CONFIG_HONOR_RTG_FRAME_RME */

#endif /* HONOR_FRAME_RME_H */
