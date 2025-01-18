/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2014-2022. All rights reserved.
 * Description: This file describe GPU core hotplug feature
 * Create: 2022-04-02
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * A copy of the licence is included with the program, and can also be obtained
 * from Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 *
 */
#include "mali_kbase.h"
#include "mali_kbase_platform.h"

#ifdef CONFIG_GPU_CORE_HOTPLUG
/* For Odin, default core mask is 0x50005 */
#ifdef CONFIG_MALI_ODIN
#define CORE_MASK_LEVEL_1       1
#define CORE_MASK_LEVEL_2       2
#define CORE_MASK_LEVEL_3       3
#define CORE_MASK_LEVEL_4       4

#define CORE_MASK_LEVEL_1_VALUE       0x1
#define CORE_MASK_LEVEL_4_VALUE       0x50005

#ifdef CONFIG_GPU_SHADER_PRESENT_CFG
static u64 kbase_gpu_thermal_select_coremask(struct kbase_device *kbdev,
	u64 updated_core_mask, u32 *allowed_cores, u32 set)
{
	u32 available_cores = kbdev->gpu_dev_data.shader_present_lo_cfg;
	u32 i = 0;
	u64 core_mask = updated_core_mask;

	while (i < set) {
		if ((allowed_cores[i] & available_cores) == allowed_cores[i]) {
			core_mask = (u64)allowed_cores[i];
			break;
		}
		i++;
	}
	if (i == set) {
		core_mask &= (u64)available_cores;
		if (core_mask == 0)
			core_mask = (u64)available_cores;
		dev_err(kbdev->dev, "lite chip core_mask 0x%llx\n", core_mask);
	}
	return core_mask;
}

/* Get valid coremask for lite chips */
static u64 kbase_gpu_thermal_lite_coremask(struct kbase_device *kbdev,
	u64 updated_core_mask, u64 cores)
{
	u64 core_mask = updated_core_mask &
		(u64)kbdev->gpu_dev_data.shader_present_lo_cfg;

	switch (cores) {
	case CORE_MASK_LEVEL_1: {
		u32 allowed_cores[3] = { 0x1111, 0x2222, 0x4444 };
		u32 set = sizeof(allowed_cores) / sizeof(allowed_cores[0]);
		core_mask = kbase_gpu_thermal_select_coremask(kbdev,
			updated_core_mask, allowed_cores, set);
		break;
	}
	case CORE_MASK_LEVEL_2: {
		u32 allowed_cores[3] = { 0x11111111, 0x22222222, 0x44444444 };
		u32 set = sizeof(allowed_cores) / sizeof(allowed_cores[0]);
		core_mask = kbase_gpu_thermal_select_coremask(kbdev,
			updated_core_mask, allowed_cores, set);
		break;
	}
	case CORE_MASK_LEVEL_3: /* fall-through */
	case CORE_MASK_LEVEL_4:
		dev_err(kbdev->dev, "lite chip cores %llu core_mask 0x%llx\n",
			cores, core_mask);
		break;
	default:
		break;
	}

	return core_mask;
}
#endif
#endif

static u64 kbase_gpu_thermal_update_coremask(struct kbase_device *kbdev, u64 cores)
{
	u64 updated_core_mask = CORE_MASK_LEVEL_4_VALUE;

	switch (cores) {
	case CORE_MASK_LEVEL_1:  /* fall-through */
	case CORE_MASK_LEVEL_2:
		updated_core_mask = CORE_MASK_LEVEL_1_VALUE;
		break;
	case CORE_MASK_LEVEL_3:  /* fall-through */
	case CORE_MASK_LEVEL_4:
		updated_core_mask = CORE_MASK_LEVEL_4_VALUE;
		break;
	default:
		dev_err(kbdev->dev,
			"Invalid cores set 0x%llx\n", cores);
		break;
	}

#if defined(CONFIG_MALI_ODIN) && defined(CONFIG_GPU_SHADER_PRESENT_CFG)
	updated_core_mask = kbase_gpu_thermal_lite_coremask(kbdev,
		updated_core_mask, cores);
#endif
	return updated_core_mask;
}

void gpu_thermal_cores_control(u64 cores)
{
	u64 updated_core_mask;
	unsigned long flags;
	struct kbase_device *kbdev = kbase_platform_get_device();

	if (kbdev == NULL) {
		pr_err("[Mali]kbase_dev is null,seems platform uninitialized");
		return;
	}

	updated_core_mask = kbase_gpu_thermal_update_coremask(kbdev, cores);

	dev_err(kbdev->dev, " Enter GPU core hotplug. cores = %d, core_mask(0x%x -> 0x%x)",
		cores, kbdev->pm.debug_core_mask, updated_core_mask);
	mutex_lock(&kbdev->pm.lock);
	spin_lock_irqsave(&kbdev->hwaccess_lock, flags);
	if (kbdev->pm.debug_core_mask != updated_core_mask)
		kbase_pm_set_debug_core_mask(kbdev, updated_core_mask);
	spin_unlock_irqrestore(&kbdev->hwaccess_lock, flags);
	mutex_unlock(&kbdev->pm.lock);
}
EXPORT_SYMBOL(gpu_thermal_cores_control);
#endif
