/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: This file contains the function required for init_user and
 *              package management.
 * Create: 2021-05-21
 */

#include "inc/ioctl/hwdps_ioctl_impl.h"
#include <securec.h>
#include <huawei_platform/hwdps/hwdps_ioctl.h>
#include <huawei_platform/hwdps/hwdps_defines.h>
#include "inc/base/hwdps_utils.h"
#include "inc/data/hwdps_data.h"
#include "inc/data/hwdps_packages.h"
#include "inc/policy/hwdps_policy.h"

#define PKG_NUMS_MAX 1024

static hwdps_result_t get_result(s32 ret)
{
	switch (ret) {
	case 0:
		return HWDPS_SUCCESS;
	case -EINVAL:
		return HWDPS_ERR_INVALID_ARGS;
	case -ENOMEM:
		return HWDPS_ERR_NO_MEMORY;
	default:
		return HWDPS_ERR_INTERNAL;
	}
}

void hwdps_sync_installed_packages(
	struct hwdps_sync_packages_t *sync_installed_packages)
{
	s32 ret;
	u32 i;
	s32 count;
	s32 effect;

	if (!sync_installed_packages)
		return;

	hwdps_data_write_lock();
	count = get_package_hashtable_len();
	effect = 0;
	if (count > PKG_NUMS_MAX) {
		hwdps_data_write_unlock();
		ret = -EINVAL;
		sync_installed_packages->ret = get_result(ret);
		return;
	}
	effect = PKG_NUMS_MAX - count;
	if (effect > sync_installed_packages->package_count)
		effect = sync_installed_packages->package_count;
	for (i = 0; i < effect; i++) {
		ret = hwdps_packages_insert(
			&sync_installed_packages->packages[i]);
		if (ret != 0)
			break;
	}

	hwdps_data_write_unlock();
	sync_installed_packages->ret = get_result(ret);
}

void hwdps_install_package(struct hwdps_install_package_t *install_package)
{
	s32 ret;
	s32 count;

	if (!install_package)
		return;

	hwdps_data_write_lock();
	count = get_package_hashtable_len();
	if (count > PKG_NUMS_MAX) {
		ret = -EINVAL;
		goto ERR;
	}
	ret = hwdps_packages_insert(&install_package->pinfo);
ERR:
	hwdps_data_write_unlock();
	install_package->ret = get_result(ret);
}

void hwdps_uninstall_package(
	struct hwdps_uninstall_package_t *uninstall_package)
{
	if (!uninstall_package)
		return;

	hwdps_data_write_lock();
	hwdps_packages_delete(&uninstall_package->pinfo);
	hwdps_data_write_unlock();
	uninstall_package->ret = HWDPS_SUCCESS;
}
