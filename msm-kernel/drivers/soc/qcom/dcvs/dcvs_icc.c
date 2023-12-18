// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 */

#define pr_fmt(fmt) "qcom-dcvs-icc: " fmt

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/interconnect.h>
#include <soc/qcom/dcvs.h>
#include "dcvs_private.h"

struct icc_sp_data {
	struct icc_path         *icc_path;
};

#if IS_ENABLED(CONFIG_CX_POWER_OPTIMIZE)

#include "../../../interconnect/internal.h"
#include "trace-dcvs.h"

#define DDR_VOTE_LOWSVS 	2188000
#define DDR_VOTE_SVS1 		3072000
#define DDR_VOTE_SVS2 		6220000
#define DDR_VOTE_SVS_L1 	6832000
#define DDR_VOTE_NOR 		8368000
#define LLCC_VOTE_LOWSVS 	4800000
#define LLCC_VOTE_SVS 		7456000
#define LLCC_VOTE_SVS_L1 	9600000
#define LLCC_VOTE_NOR 		12896000
#define MLEVEL_BW_UTILIZATION 1

extern u32 enable_cx_decrease;

static void cx_bw_optimize(struct icc_path *path, u32 *avg_bw, u32 *peak_bw)
{
	if (!strcmp(path->name, "chm_apps-qns_llcc")) {
		if (*peak_bw == LLCC_VOTE_SVS)
			*peak_bw = LLCC_VOTE_LOWSVS;
		else if (*peak_bw == LLCC_VOTE_SVS_L1)
			*peak_bw = LLCC_VOTE_SVS;
	}

	if (!strcmp(path->name, "llcc_mc-ebi")) {
		if (*peak_bw > DDR_VOTE_LOWSVS && *peak_bw <= DDR_VOTE_SVS1)
			*peak_bw = DDR_VOTE_LOWSVS;
		else if (*peak_bw > DDR_VOTE_SVS2 && *peak_bw <= DDR_VOTE_SVS_L1)
			*peak_bw = DDR_VOTE_SVS2;
	}
}
#endif

static int commit_icc_freq(struct dcvs_path *path, struct dcvs_freq *freqs,
							u32 update_mask)
{
	int ret;
	struct dcvs_hw *hw = path->hw;
	struct icc_sp_data *sp_data = path->data;
	struct icc_path *icc_path = sp_data->icc_path;
	u32 icc_ib = freqs->ib * hw->width;
	u32 icc_ab = freqs->ab * hw->width;

#if IS_ENABLED(CONFIG_CX_POWER_OPTIMIZE)
	/* trace icc_set_bw ori val of ab(avg) & ib(peak) for ddr and llcc */
	if (!strcmp(icc_path->name, "llcc_mc-ebi")
		|| !strcmp(icc_path->name, "chm_apps-qns_llcc"))
			trace_icc_set_bw_ori(icc_path, icc_ab, icc_ib);

	if (enable_cx_decrease == MLEVEL_BW_UTILIZATION)
		cx_bw_optimize(icc_path, &icc_ab, &icc_ib);

	/* trace icc_set_bw modify val of ab(avg) & ib(peak) for ddr and llcc */
	if (!strcmp(icc_path->name, "llcc_mc-ebi")
		|| !strcmp(icc_path->name, "chm_apps-qns_llcc"))
			trace_icc_set_bw_mod(icc_path, icc_ab, icc_ib);
#endif

	ret = icc_set_bw(icc_path, icc_ab, icc_ib);
	if (ret < 0) {
		dev_err(path->dev, "icc set bw request failed: %d\n", ret);
		return ret;
	}
	path->cur_freq.ib = freqs->ib;
	path->cur_freq.ab = freqs->ab;

	return ret;
}

#define ACTIVE_ONLY_TAG	0x3
#define PERF_MODE_TAG	0x8
int setup_icc_sp_device(struct device *dev, struct dcvs_hw *hw,
					struct dcvs_path *path)
{
	struct icc_sp_data *sp_data = NULL;
	int ret = 0;

	if (hw->type != DCVS_DDR && hw->type != DCVS_LLCC
					&& hw->type != DCVS_DDRQOS)
		return -EINVAL;

	sp_data = devm_kzalloc(dev, sizeof(*sp_data), GFP_KERNEL);
	if (!sp_data)
		return -ENOMEM;
	sp_data->icc_path = of_icc_get(dev, NULL);
	if (IS_ERR(sp_data->icc_path)) {
		ret = PTR_ERR(sp_data->icc_path);
		if (ret != -EPROBE_DEFER)
			dev_err(dev, "Unable to register icc path: %d\n", ret);
		return ret;
	}
	if (hw->type == DCVS_DDR || hw->type == DCVS_LLCC)
		icc_set_tag(sp_data->icc_path, ACTIVE_ONLY_TAG);
	else if (hw->type == DCVS_DDRQOS)
		icc_set_tag(sp_data->icc_path, ACTIVE_ONLY_TAG | PERF_MODE_TAG);
	path->data = sp_data;
	path->commit_dcvs_freqs = commit_icc_freq;

	return ret;
}
