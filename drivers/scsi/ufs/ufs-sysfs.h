/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2018 Western Digital Corporation
 */

#ifndef __UFS_SYSFS_H__
#define __UFS_SYSFS_H__

#include <linux/sysfs.h>

#include "ufshcd.h"

void ufs_sysfs_add_nodes(struct ufs_hba *hba);
void ufs_sysfs_remove_nodes(struct device *dev);

const char *ufschd_uic_link_state_to_string(enum uic_link_state statea);
const char *ufschd_ufs_dev_pwr_mode_to_string(enum ufs_dev_pwr_mode state);

extern const struct attribute_group ufs_sysfs_unit_descriptor_group;
extern const struct attribute_group ufs_sysfs_lun_attributes_group;
#ifdef CONFIG_CGROUP_IOLIMIT_HIBERN8
/* IOLIMIT Hibern8 Timer, opt: 50ms */
#define UFS_ACGROUP_IOLIMIT_HIBERN8_OPT_TIMER 0x0C32

u32 get_dynamic_hibern8_timer(void);
#endif
#endif
