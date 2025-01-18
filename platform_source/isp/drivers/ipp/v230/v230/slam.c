
#include <linux/printk.h>
#include <linux/string.h>
#include "ipp.h"
#include "slam_drv.h"
#include "slam_drv_priv.h"
#include "slam_reg_offset.h"
#include "slam_reg_offset_field.h"

#define LOG_TAG LOG_MODULE_MFNR_DRV

static int slam_config_basic(slam_dev_t *dev, slam_basic_cfg_t *slam_basic_cfg)
{
	union u_slam_cfg       temp_slam_cfg;
	union u_image_size     temp_slam_size;
	temp_slam_cfg.u32     = 0;
	temp_slam_size.u32    = 0;
	temp_slam_cfg.bits.pyramid_en = slam_basic_cfg->slam_cfg.pyramid_en;
	temp_slam_cfg.bits.gsblur_en = slam_basic_cfg->slam_cfg.gsblur_en;
	temp_slam_cfg.bits.fast_en = slam_basic_cfg->slam_cfg.fast_en;
	temp_slam_cfg.bits.nms_en = slam_basic_cfg->slam_cfg.nms_en;
	temp_slam_cfg.bits.orient_en = slam_basic_cfg->slam_cfg.orient_en;
	temp_slam_cfg.bits.brief_en = slam_basic_cfg->slam_cfg.brief_en;
	temp_slam_cfg.bits.freak_en = slam_basic_cfg->slam_cfg.freak_en;
	temp_slam_cfg.bits.scoremap_en = slam_basic_cfg->slam_cfg.scoremap_en;
	temp_slam_size.bits.width  = slam_basic_cfg->slam_size.width - 1;
	temp_slam_size.bits.height = slam_basic_cfg->slam_size.height - 1;
	cmdlst_set_reg_m(dev->base_addr + SLAM_SLAM_CFG_REG, temp_slam_cfg.u32);
	cmdlst_set_reg_m(dev->base_addr + SLAM_IMAGE_SIZE_REG, temp_slam_size.u32);
	return CPE_FW_OK;
}

static int slam_config_pyramid_param(slam_dev_t *dev, slam_pyramid_param_cfg_t *pyramid_param)
{
	union u_pyramid_inc_cfg     temp_scl_inc_cfg;
	union u_pyramid_vcrop_cfgb  temp_scl_vbottom_cfg;
	union u_pyramid_vcrop_cfgt  temp_scl_vtop_cfg;
	union u_pyramid_hcrop_cfgr  temp_scl_hright_cfg;
	union u_pyramid_hcrop_cfgl  temp_scl_hleft_cfg;
	temp_scl_inc_cfg.u32 = 0;
	temp_scl_vbottom_cfg.u32 = 0;
	temp_scl_vtop_cfg.u32 = 0;
	temp_scl_hright_cfg.u32 = 0;
	temp_scl_hleft_cfg.u32 = 0;
	temp_scl_inc_cfg.bits.scl_inc    = pyramid_param->scl_inc;
	temp_scl_vbottom_cfg.bits.scl_vbottom = pyramid_param->scl_vbottom;
	temp_scl_vtop_cfg.bits.scl_vtop     = pyramid_param->scl_vtop;
	temp_scl_hright_cfg.bits.scl_hright = pyramid_param->scl_hright;
	temp_scl_hleft_cfg.bits.scl_hleft   = pyramid_param->scl_hleft;
	cmdlst_set_reg_m(dev->base_addr + SLAM_PYRAMID_INC_CFG_REG, temp_scl_inc_cfg.u32);
	cmdlst_set_reg_m(dev->base_addr + SLAM_PYRAMID_VCROP_CFGB_REG, temp_scl_vbottom_cfg.u32);
	cmdlst_set_reg_m(dev->base_addr + SLAM_PYRAMID_VCROP_CFGT_REG, temp_scl_vtop_cfg.u32);
	cmdlst_set_reg_m(dev->base_addr + SLAM_PYRAMID_HCROP_CFGR_REG, temp_scl_hright_cfg.u32);
	cmdlst_set_reg_m(dev->base_addr + SLAM_PYRAMID_HCROP_CFGL_REG, temp_scl_hleft_cfg.u32);
	return CPE_FW_OK;
}

static int slam_config_gsblur_coeff(slam_dev_t *dev, slam_gsblur_coeff_cfg_t *gsblur_coeff)
{
	union u_gsblur_coef_01 temp_gsblur_coeff_01;
	union u_gsblur_coef_23 temp_gsblur_coeff_23;
	temp_gsblur_coeff_01.u32 = 0;
	temp_gsblur_coeff_23.u32 = 0;
	temp_gsblur_coeff_01.bits.coeff_gauss_0 = gsblur_coeff->coeff_gauss_0;
	temp_gsblur_coeff_01.bits.coeff_gauss_1 = gsblur_coeff->coeff_gauss_1;
	temp_gsblur_coeff_23.bits.coeff_gauss_2 = gsblur_coeff->coeff_gauss_2;
	temp_gsblur_coeff_23.bits.coeff_gauss_3 = gsblur_coeff->coeff_gauss_3;
	cmdlst_set_reg_m(dev->base_addr + SLAM_GSBLUR_COEF_01_REG, temp_gsblur_coeff_01.u32);
	cmdlst_set_reg_m(dev->base_addr + SLAM_GSBLUR_COEF_23_REG, temp_gsblur_coeff_23.u32);
	return CPE_FW_OK;
}

static int slam_config_threshold_param(slam_dev_t *dev, slam_threshold_param_cfg_t *threshold_param)
{
	union u_threshold_cfg  temp_threshold_param;
	temp_threshold_param.u32 = 0;
	temp_threshold_param.bits.min_th = threshold_param->min_th;
	temp_threshold_param.bits.ini_th = threshold_param->ini_th;
	cmdlst_set_reg_m(dev->base_addr + SLAM_THRESHOLD_CFG_REG, temp_threshold_param.u32);
	return CPE_FW_OK;
}

static int slam_config_nms_win_param(slam_dev_t *dev, slam_nms_win_param_cfg_t *nms_win_param)
{
	union u_nms_win_cfg  temp_nms_win_param;
	temp_nms_win_param.u32 = 0;
	temp_nms_win_param.bits.nmscell_h = nms_win_param->nmscell_h;
	temp_nms_win_param.bits.nmscell_v = nms_win_param->nmscell_v;
	cmdlst_set_reg_m(dev->base_addr + SLAM_NMS_WIN_CFG_REG, temp_nms_win_param.u32);
	return CPE_FW_OK;
}

static int slam_config_pattern_param(slam_dev_t *dev, unsigned int *pattern_param)
{
	union u_brief_pattern    temp_pattern_param;
	temp_pattern_param.u32 = 0;
	cmdlst_set_reg_incr_m(dev->base_addr + SLAM_BRIEF_PATTERN_0_REG, SLAM_PATTERN_NUM, 0);
	memcpy_s((unsigned int *)(uintptr_t)dev->cmd_buf->data_addr, SLAM_PATTERN_NUM * sizeof(unsigned int), pattern_param,
			 SLAM_PATTERN_NUM * sizeof(unsigned int));
	dev->cmd_buf->data_addr += 4 * SLAM_PATTERN_NUM;
	dev->cmd_buf->data_size += 4 * SLAM_PATTERN_NUM;
	return CPE_FW_OK;
}

static int slam_do_config(slam_dev_t *dev, slam_config_table_t *cfg_tab)
{
	if ((dev == NULL) || (cfg_tab == NULL))
		return CPE_FW_ERR;

	if (cfg_tab->to_use == 1) {
		cfg_tab->to_use = 0;

		if (cfg_tab->basic_cfg.to_use == 1) {
			cfg_tab->basic_cfg.to_use = 0;
			slam_config_basic(dev, &cfg_tab->basic_cfg);
		}

		slam_config_pyramid_param(dev, &cfg_tab->pyramid_param);
		slam_config_gsblur_coeff(dev, &cfg_tab->gsblur_coeff);
		slam_config_threshold_param(dev, &cfg_tab->threshold_param);
		slam_config_nms_win_param(dev, &cfg_tab->nms_win_param);
		slam_config_pattern_param(dev, cfg_tab->pattern_param.pattern_param);
	}

	return CPE_FW_OK;
}

int slam_prepare_cmd(slam_dev_t *dev, cmd_buf_t *cmd_buf, slam_config_table_t *table)
{
	dev->cmd_buf = cmd_buf;
	loge_if_ret(slam_do_config(dev, table));
	return 0;
}

static slam_ops_t slam_ops = {
	.prepare_cmd   = slam_prepare_cmd,
};

slam_dev_t g_slam_devs[] = {
	[0] =
	{
		.base_addr = JPG_SLAM_ADDR,
		.ops = &slam_ops,
	},
};

/********************************** END **********************************/
