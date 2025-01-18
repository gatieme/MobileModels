/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * dpu_frame_rate_adaptive.c
 *
 * The driver of adaptive frame rate
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

#include "dpu_frame_rate_adaptive.h"
#include "dpu_frame_rate_dimming.h"
#include <securec.h>
#include "dpu_trace.h"
#ifdef CONFIG_LCD_KIT_DRIVER
#include "lcd_kit_utils.h"
#endif

#ifdef CONFIG_DPU_FRAME_SKIP_LTPO1
uint32_t g_last_target_frm_rate = 0;
#endif

static struct dpu_fb_data_type *get_dpufb_from_fb_device(struct device *dev)
{
	struct fb_info *fbi = (struct fb_info *)dev_get_drvdata(dev);

	dpu_check_and_return(!fbi, NULL, ERR, "fbi is null pointer");

	return (struct dpu_fb_data_type *)fbi->par;
}

static struct dpu_fb_data_type *get_dpufb_from_device(struct device *dev)
{
	if (!dev) {
		DPU_FB_ERR("input dev is null!");
		return NULL;
	}

	if (strncmp(dev->kobj.name, DEV_NAME_FB0, 2) == 0)
		return get_dpufb_from_fb_device(dev);

	return NULL;
}

static uint32_t dpu_get_hw_frm_rate(struct dpu_fb_data_type *dpufd, uint32_t cur_frm_rate)
{
	int i;

	if (cur_frm_rate == 0)
		return dpufd->panel_info.dfr_info.oled_info.ltpo_info.te_freqs[0];

	for (i = 0; i < TE_FREQ_NUM_MAX; i++) {
		if (dpufd->panel_info.dfr_info.oled_info.ltpo_info.te_freqs[i]
			% cur_frm_rate == 0)
			return dpufd->panel_info.dfr_info.oled_info.ltpo_info.te_freqs[i];
	}

	DPU_FB_ERR("[afr] frm rate is %uhz, no valid te freq to devide", cur_frm_rate);
	return dpufd->panel_info.adaptive_frm_rate.cur_te_rate;
}

static ssize_t dimming_frame_rate_switch_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	ssize_t ret;
	int32_t dimming_switch;
	struct dpu_fb_data_type *dpufd = NULL;

	void_unused(attr);
	dpu_check_and_return((!dev || !buf), -1, ERR, "[afr] input is null pointer");
	ret = sscanf_s(buf, "%d", &dimming_switch);
	if (!ret) {
		DPU_FB_ERR("[afr] get frame rate (%s) fail\n", buf);
		return -1;
	}

	dpufd = get_dpufb_from_device(dev);
	if (!dpufd) {
		DPU_FB_ERR("[afr] get dpufd err");
		return count;
	}
	dpufd->panel_info.dfr_info.oled_info.ltpo_info.dimming_enable = dimming_switch;
	DPU_FB_INFO("[dimming] dimming_switch [%d],", dimming_switch);

	return count;
}


static ssize_t dimming_frame_rate_list_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	int dimming_list[100] = {0};
	int i = 0;
	char *cur = NULL;
	char *token = NULL;
	struct dpu_fb_data_type *dpufd = NULL;
	struct dpu_frm_dimming *frm_rate_dimming = NULL;

	void_unused(attr);
	dpu_check_and_return((!dev || !buf), -1, ERR, "[afr] input is null pointer");

	dpufd = get_dpufb_from_device(dev);
	if (!dpufd) {
		DPU_FB_ERR("[afr] get dpufd err");
		return count;
	}
	frm_rate_dimming = &dpufd->panel_info.frm_rate_dimming;

	cur = (char *)buf;
	token = strsep(&cur, ",");
	while (token != NULL) {
		dimming_list[i++] = simple_strtol(token, NULL, 0);
		token = strsep(&cur, ",");
		if (i >= 100)
			return count;
	}
	frm_rate_dimming->debug_list_len = i;
	for (int j = 0; j < i; j++)
		*(frm_rate_dimming->debug_dimming_list + j) = dimming_list[j];

	frm_rate_dimming->te_idle_count = 0;
	frm_rate_dimming->setup_dimming_list = true;
	frm_rate_dimming->idle_cur_index = 0;
	frm_rate_dimming->idle_index = 0;
	frm_rate_dimming->rd_idle_state = false;

	DPU_FB_INFO("[dimming] dimming_frame_rate_list_store reset dimming list");
	return count;
}

static void dfr_switch_cur_frm_rate(struct dpu_fb_data_type *dpufd, uint32_t frame_rate)
{
	DPU_FB_INFO("[afr] cur_frm_rate change [%d] -> [%d]\n",
		dpufd->panel_info.adaptive_frm_rate.cur_frm_rate, frame_rate);

	dpufd->panel_info.adaptive_frm_rate.cur_frm_rate = frame_rate;
	DPU_ATRACE_INT_WITH_GID_VALUE("frame_rate", dpufd->panel_info.dpu_task, frame_rate);
}

void dfr_switch_cur_te_rate(struct dpu_fb_data_type *dpufd, uint32_t cur_te_rate)
{
	DPU_FB_INFO("[afr] cur_te_rate change [%d] -> [%d]\n",
		dpufd->panel_info.adaptive_frm_rate.cur_te_rate, cur_te_rate);

	dfr_switch_cur_frm_rate(dpufd, dpufd->panel_info.adaptive_frm_rate.target_frm_rate);
	dpufd->panel_info.adaptive_frm_rate.cur_te_rate = cur_te_rate;
	dpufd->panel_info.frm_rate_static.cur_te_rate = cur_te_rate;
	dpu_reset_dimming_idle_list(dpufd, cur_te_rate);
}

static int32_t dfr_set_target_frm_rate_ltpo(
	struct dpu_fb_data_type *dpufd, struct dpu_fb_panel_data *pdata, uint32_t frame_rate)
{
	int32_t ret = 0;
	uint32_t cur_te_rate;
	int32_t scence = 0;

	cur_te_rate = dpu_get_hw_frm_rate(dpufd, frame_rate);
	if (pdata->fps_scence_get == NULL || pdata->lcd_fps_scence_handle == NULL)
		return ret;

	if (((ret = pdata->fps_scence_get(cur_te_rate, &scence)) == 0) &&
		((ret = pdata->lcd_fps_scence_handle(dpufd->pdev, scence)) == 0)) {
		dpufd->panel_info.adaptive_frm_rate.target_frm_rate = frame_rate;
		if (cur_te_rate == dpufd->panel_info.fps)
			dfr_switch_cur_frm_rate(dpufd, frame_rate);
	}
	return ret;
}

#ifdef CONFIG_DPU_FRAME_SKIP_LTPO1
int32_t dfr_init_set_last_frm_rate(struct dpu_fb_data_type *dpufd, uint32_t frame_rate)
{
	struct dpu_fb_panel_data *pdata = NULL;

	if (!dpufd) {
		DPU_FB_ERR("[afr] get dpufd err");
		return -1;
	}

	// set the last target frame rate, only for ltpo
	DPU_FB_INFO("[afr] cur_frm_rate want to change [%d] -> [%d]\n",
		dpufd->panel_info.adaptive_frm_rate.cur_frm_rate, frame_rate);

	if (!dpufd->panel_power_on || !dpufd->panel_info.adaptive_frm_rate.is_support_ltpo) {
		DPU_FB_INFO("fb%d is power off or is not an LPTO screen\n", dpufd->index);
		return -1;
	}

	pdata = dev_get_platdata(&dpufd->pdev->dev);
	if (pdata == NULL) {
		DPU_FB_ERR("[afr] lcd fps scence store pdata NULL Pointer!\n");
		return -1;
	}

	return dfr_set_target_frm_rate_ltpo(dpufd, pdata, frame_rate);
}
#endif

static int32_t dfr_target_frame_rate_store_ltpo(
	struct dpu_fb_data_type *dpufd, struct dpu_fb_panel_data *pdata, uint32_t frame_rate)
{
	DPU_FB_INFO("[afr] cur_frm_rate want to change [%d] -> [%d]\n",
		dpufd->panel_info.adaptive_frm_rate.cur_frm_rate, frame_rate);

	if (!dpufd->panel_power_on) {
#ifdef CONFIG_DPU_FRAME_SKIP_LTPO1
		if (dpu_get_panel_product_type() == PANEL_DUAL_PANEL_TYPE)
			g_last_target_frm_rate = frame_rate;
#endif
		DPU_FB_INFO("[afr] panel_power_on %d\n", dpufd->panel_power_on);
		return -1;
	}

	return dfr_set_target_frm_rate_ltpo(dpufd, pdata, frame_rate);
}

static ssize_t dfr_target_frame_rate_store(struct device *dev, struct device_attribute *attr,
	const char *buf, size_t count)
{
	uint32_t frame_rate;
	int32_t scence;
	ssize_t ret;
	struct dpu_fb_data_type *dpufd = NULL;
	struct dpu_fb_panel_data *pdata = NULL;

	void_unused(attr);
	dpu_check_and_return((!dev || !buf), -1, ERR, "[afr] input is null pointer");

	if (!sscanf_s(buf, "%u", &frame_rate)) {
		DPU_FB_ERR("[afr] get frame rate (%s) fail\n", buf);
		return -1;
	}
	DPU_FB_DEBUG("[afr] frame_rate = %u, cur_time = %llu,", frame_rate, ktime_to_ns(ktime_get()));

#ifdef CONFIG_LCD_KIT_DRIVER
	dpufd = lcd_kit_get_hisifd(dev);
#else
	dpufd = get_dpufb_from_device(dev);
#endif
	if (!dpufd) {
		DPU_FB_ERR("[afr] get dpufd err");
		return count;
	}
	pdata = dev_get_platdata(&dpufd->pdev->dev);
	if (pdata == NULL) {
		DPU_FB_ERR("[afr] lcd fps scence store pdata NULL Pointer!\n");
		return count;
	}

	if (dpufd->panel_info.dfr_info.oled_info.oled_type == PANEL_OLED_LTPS) {
		if (pdata->fps_scence_get) {
			if (pdata->fps_scence_get(frame_rate, &scence) == 0) {
				if (pdata->lcd_fps_scence_handle)
					pdata->lcd_fps_scence_handle(dpufd->pdev, scence);
			}
		}
		return count;
	}

	ret = dfr_target_frame_rate_store_ltpo(dpufd, pdata, frame_rate);

	return ret == 0 ? count : ret;
}

static ssize_t dfr_real_frame_rate_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	ssize_t ret;
	uint32_t real_frame_rate;
	struct dpu_fb_data_type *dpufd = NULL;

	void_unused(attr);
	dpu_check_and_return((!dev || !buf), -1, ERR, "input is null pointer");

	dpufd = get_dpufb_from_device(dev);
	if (!dpufd) {
		DPU_FB_ERR("[afr] get dpufb err");
		return -1;
	}

	if (!dpufd->panel_power_on || !dpufd->panel_info.adaptive_frm_rate.is_support_ltpo) {
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n",
			"current screen is powered off or is not an LPTO screen");
	} else {
		real_frame_rate = dpufd->panel_info.frm_rate_static.real_frame_rate;
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", real_frame_rate);
	}

	buf[strlen(buf) + 1] = '\0';
	return ret;
}

static ssize_t dfr_average_frame_rate_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	ssize_t ret;
	struct dpu_fb_data_type *dpufd = NULL;
	struct dpu_frm_rate_static *frame_rate_static = NULL;

	void_unused(attr);
	dpu_check_and_return((!dev || !buf), -1, ERR, "input is null pointer");

	dpufd = get_dpufb_from_device(dev);
	if (!dpufd) {
		DPU_FB_ERR("[afr] get dpufb err");
		return -1;
	}

	if (!dpufd->panel_info.adaptive_frm_rate.is_support_ltpo) {
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n",
			"current screen is not an LPTO screen");
		return -1;
	}

	frame_rate_static = &dpufd->panel_info.frm_rate_static;

	ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1,
		"1hz[%u], 10hz[%u], 15hz[%u], 24hz[%u], 30hz[%u], 45hz[%u], 60hz[%u], 90hz[%u], 120hz[%u], 180hz[%u]\n",
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_1HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_10HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_15HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_24HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_30HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_45HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_60HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_90HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_120HZ],
		frame_rate_static->refresh_stat_info.stat_info.refresh_cnt[FRM_RATE_180HZ]);

	buf[strlen(buf) + 1] = '\0';

	return ret;
}

static ssize_t dimming_frame_rate_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	ssize_t ret;
	int32_t dimming_switch;
	struct dpu_fb_data_type *dpufd = NULL;

	void_unused(attr);
	dpu_check_and_return((!dev || !buf), -1, ERR, "input is null pointer");

	dpufd = get_dpufb_from_device(dev);
	if (!dpufd) {
		DPU_FB_ERR("[afr] get dpufb err");
		return -1;
	}

	if (!dpufd->panel_power_on || !dpufd->panel_info.adaptive_frm_rate.is_support_ltpo) {
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n",
			"current screen is powered off or is not an LPTO screen");
	} else {
		dimming_switch = dpufd->panel_info.dfr_info.oled_info.ltpo_info.dimming_enable;
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%d\n", dimming_switch);
	}

	buf[strlen(buf) + 1] = '\0';
	return ret;
}

static DEVICE_ATTR(dfr_target_frame_rate, 0200, NULL, dfr_target_frame_rate_store);
static DEVICE_ATTR(dfr_real_frame_rate, 0400, dfr_real_frame_rate_show, NULL);
static DEVICE_ATTR(dfr_average_frame_rate, 0400, dfr_average_frame_rate_show, NULL);
static DEVICE_ATTR(dimming_frame_rate_list, 0200, NULL, dimming_frame_rate_list_store);
static DEVICE_ATTR(dimming_frame_rate_switch, 0600, dimming_frame_rate_switch_show, dimming_frame_rate_switch_store);

void dpufb_frame_rate_deinit(struct dpu_fb_data_type *dpufd)
{
	dpufb_frame_rate_static_deinit(dpufd);
	dpufb_frame_rate_dimming_deinit(dpufd);
}

void dpu_adaptive_frame_rate_init(struct dpu_fb_data_type *dpufd)
{
	dpu_check_and_no_retval(!dpufd, ERR, "[afr] dpufd is NULL!\n");

	if (dpufd->sysfs_attrs_append_fnc)
		dpufd->sysfs_attrs_append_fnc(dpufd, &dev_attr_dfr_target_frame_rate.attr);

	if (dpufd->panel_info.dfr_info.oled_info.oled_type == PANEL_OLED_LTPO) {
		dpufd->panel_info.adaptive_frm_rate.is_support_ltpo = true;
		atomic_set(&(dpufd->panel_info.adaptive_frm_rate.skip_te_count), 0);
		spin_lock_init(&dpufd->panel_info.adaptive_frm_rate.skip_te_lock);
		dpufd->panel_info.adaptive_frm_rate.vsync_update_single_frm = false;
		dpufd->panel_info.adaptive_frm_rate.cur_frm_rate = FPS_120HZ;
		dpufd->panel_info.adaptive_frm_rate.cur_te_rate = FPS_120HZ;
		dpufd->panel_info.adaptive_frm_rate.target_frm_rate = FPS_120HZ;
		dpufd->panel_info.adaptive_frm_rate.vsync_realtimestamp = 0;
		dpu_refresh_stat_init(dpufd);
		dpu_frm_rate_dimming_init(dpufd);
		if (dpufd->sysfs_attrs_append_fnc) {
			dpufd->sysfs_attrs_append_fnc(dpufd, &dev_attr_dfr_real_frame_rate.attr);
			dpufd->sysfs_attrs_append_fnc(dpufd, &dev_attr_dfr_average_frame_rate.attr);
			dpufd->sysfs_attrs_append_fnc(dpufd, &dev_attr_dimming_frame_rate_list.attr);
			dpufd->sysfs_attrs_append_fnc(dpufd, &dev_attr_dimming_frame_rate_switch.attr);
		}
	}

	return;
}

inline int dpu_afr_get_skip_stride(struct dpu_fb_data_type *dpufd)
{
	if (dpufd->panel_info.adaptive_frm_rate.cur_frm_rate)
		return max(dpufd->panel_info.adaptive_frm_rate.cur_te_rate / dpufd->panel_info.adaptive_frm_rate.cur_frm_rate, 1);

	return 1;
}

bool dpu_afr_vsync_handle(struct dpu_fb_data_type *dpufd)
{
	int skip_te = 1;
	ktime_t pre_timestamp = 0;
	ktime_t diff_time = 0;
	int step = 1;

	DPU_ATRACE_BEGIN("dpu_afr_vsync_handle");
	if (!dpufd->panel_info.adaptive_frm_rate.is_support_ltpo) {
		DPU_ATRACE_END("dpu_afr_vsync_handle");
		return true;
	}

	dpu_vsync_dimming_handle(dpufd);

	pre_timestamp = dpufd->panel_info.adaptive_frm_rate.pre_vsync_timestamp;
	dpufd->panel_info.adaptive_frm_rate.pre_vsync_timestamp = ktime_get();

	diff_time = dpufd->panel_info.adaptive_frm_rate.pre_vsync_timestamp - pre_timestamp;
	step = (diff_time * (int32_t)dpufd->panel_info.adaptive_frm_rate.cur_te_rate + 500000000) / 1000000000;
	skip_te = atomic_add_return(step, &(dpufd->panel_info.adaptive_frm_rate.skip_te_count));

	DPU_ATRACE_INT_WITH_GID_VALUE("skip_te_count",
		dpufd->panel_info.dpu_task, atomic_read(&dpufd->panel_info.adaptive_frm_rate.skip_te_count));
	DPU_FB_DEBUG("[afr] diffTime is %llu step is %d TE %u cur_frm_rate %u\n", diff_time, step,
		dpufd->panel_info.adaptive_frm_rate.cur_te_rate, dpufd->panel_info.adaptive_frm_rate.cur_frm_rate);

	dpu_afr_vsync_single_frame_update(dpufd);

	if (skip_te % dpu_afr_get_skip_stride(dpufd)) {
		DPU_ATRACE_END("dpu_afr_vsync_handle");
		return false;
	}
#if defined(CONFIG_DPU_FRAME_SKIP_LTPO1)
	if (dpufd->panel_info.adaptive_frm_rate.is_support_ltpo &&
		dpu_get_panel_product_type() == PANEL_DUAL_PANEL_TYPE &&
		dpufd->panel_info.frm_rate_dimming.need_reset_dimming) {
		dpu_reset_idle_para(dpufd, FRM_UPDATE);
		dpufd->panel_info.frm_rate_dimming.need_reset_dimming = false;
	}
#endif

	atomic_set(&(dpufd->panel_info.adaptive_frm_rate.skip_te_count), 0);
	DPU_ATRACE_INT_WITH_GID_VALUE("skip_te_count", dpufd->panel_info.dpu_task,
		atomic_read(&dpufd->panel_info.adaptive_frm_rate.skip_te_count));
	DPU_FB_DEBUG("[afr] fb%d, vsync_realtimestamp time_diff=%llu.\n", dpufd->index,
		(ktime_get() - dpufd->panel_info.adaptive_frm_rate.vsync_realtimestamp));
	dpufd->panel_info.adaptive_frm_rate.vsync_realtimestamp =  ktime_get();
	DPU_ATRACE_END("dpu_afr_vsync_handle");
	return true;
}

void dpu_afr_power_on(struct dpu_fb_data_type *dpufd)
{
	struct dsi_cmd_desc *dsi_cmd;
	uint32_t cmd_type = PANEL_LTPO_DSI_CMD_REFRESH;

	dpu_check_and_no_retval(!dpufd, ERR, "dpufd is NULL!\n");

	if (!dpufd->panel_info.adaptive_frm_rate.is_support_ltpo) {
		DPU_FB_DEBUG("000 ltpo is_support_ltpo not support.\n");
		return;
	}
	atomic_set(&(dpufd->panel_info.adaptive_frm_rate.skip_te_count), 0);

	DPU_ATRACE_INT_WITH_GID_VALUE("skip_te_count", dpufd->panel_info.dpu_task,
		atomic_read(&dpufd->panel_info.adaptive_frm_rate.skip_te_count));

	dsi_cmd = dpufd->panel_info.dfr_info.oled_info.ltpo_info.dsi_cmds[cmd_type].cmds;
	if (dsi_cmd->payload[0] == 0x5E)
		dsi_cmd->payload[1] = 0;

	if (dpufd->panel_info.frm_rate_dimming.base_hw_fps == dpufd->panel_info.fps_updt) {
		dpu_send_idle_control_cmd_inner(dpufd, check_frm_rate_valid_and_send(dpufd));
	} else {
		DPU_FB_WARNING("[dimming] base_hw_fps %d != panel.fps_updt %d\n",
			dpufd->panel_info.frm_rate_dimming.base_hw_fps, dpufd->panel_info.fps_updt);
	}

	DPU_FB_INFO("[dimming] panel power on, set safe frm fps is %d te fps %d\n",
		dpufd->panel_info.frm_rate_dimming.safe_frame_rate, dpufd->panel_info.frm_rate_dimming.base_hw_fps);

	// for ltpo panel switch te need >1TE, for 90hz before 1st SFU .
	usleep_range(10000, 10000);
	return;
}

void dpu_afr_power_off(struct dpu_fb_data_type *dpufd)
{
	unsigned long flags = 0;

	dpu_check_and_no_retval(!dpufd, ERR, "dpufd is NULL!\n");

	if (!dpufd->panel_info.adaptive_frm_rate.is_support_ltpo) {
		DPU_FB_DEBUG("000 ltpo is_support_ltpo not support.\n");
		return;
	}

	spin_lock_irqsave(&dpufd->panel_info.adaptive_frm_rate.skip_te_lock, flags);
	dpufd->panel_info.adaptive_frm_rate.vsync_update_single_frm = false;
	spin_unlock_irqrestore(&dpufd->panel_info.adaptive_frm_rate.skip_te_lock, flags);
	DPU_FB_INFO("[afr] panel power off, set vsync_update_single_frm is %d\n", false);
	return;
}

void dpu_afr_vsync_single_frame_update(struct dpu_fb_data_type *dpufd)
{
	unsigned long flags = 0;

	dpu_check_and_no_retval(!dpufd, ERR, "dpufd is NULL!\n");

	spin_lock_irqsave(&dpufd->panel_info.adaptive_frm_rate.skip_te_lock, flags);

	if (dpufd->panel_info.adaptive_frm_rate.vsync_update_single_frm &&
	atomic_read(&dpufd->panel_info.adaptive_frm_rate.skip_te_count) % dpu_afr_get_skip_stride(dpufd) ==
		(dpu_afr_get_skip_stride(dpufd) - 1)) {
		single_frame_update(dpufd);
		dpufb_frame_updated(dpufd);
		dpufd->panel_info.adaptive_frm_rate.vsync_update_single_frm = FALSE;
	}

	spin_unlock_irqrestore(&dpufd->panel_info.adaptive_frm_rate.skip_te_lock, flags);
	return;
}

bool dpu_afr_need_update_single_frame(struct dpu_fb_data_type *dpufd)
{
	unsigned long flags = 0;
	int i = 0;

	dpu_check_and_return(!dpufd, -EINVAL, ERR, "dpufd is NULL!\n");

	if (!dpufd->panel_info.adaptive_frm_rate.is_support_ltpo)
		return true;

	i = atomic_read(&dpufd->panel_info.adaptive_frm_rate.skip_te_count) % dpu_afr_get_skip_stride(dpufd);
	if (i < (dpu_afr_get_skip_stride(dpufd) - 1)) {
		spin_lock_irqsave(&dpufd->panel_info.adaptive_frm_rate.skip_te_lock, flags);
		dpufd->panel_info.adaptive_frm_rate.vsync_update_single_frm = TRUE;
		spin_unlock_irqrestore(&dpufd->panel_info.adaptive_frm_rate.skip_te_lock, flags);
		return false;
	}

	return true;
}

