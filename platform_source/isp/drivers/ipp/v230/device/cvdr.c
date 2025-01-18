
#include <linux/printk.h>
#include "cvdr_drv.h"
#include "axi_jpeg_drv_priv.h"
#include "axi_jpeg_reg_offset.h"
#include "axi_jpeg_reg_offset_field.h"

#define LOG_TAG LOG_MODULE_CVDR_DRV

#define VP_WR_REG_OFFSET (0x10)
#define VP_RD_REG_OFFSET (0x20)
#define NR_RD_REG_OFFSET (0x10)
#define NR_WR_REG_OFFSET (0x10)
#define ONE_REG_OFFSET   (0x4)
#define CVDR_SPARE_NUM   (4)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeclaration-after-statement"

unsigned int g_cvdr_wr_id[WR_MAX] = {
	8, // WR0_UV
	9, // WR1_Y
	10, // WR2_C
	30, // WR_CMDLST
	4, // WR0_SLAM
	5, // WR1_SLAM
	6, // WR2_SLAM
};


unsigned int g_cvdr_rd_id[RD_MAX] = {
	4, // RD_CMDLST
	13, // RD0_L0
	14, // RD1_L1
	15, // RD2_L2
	16, // RD3_MONO_DS4
	17, // RD4_MONO
	18, // RD5_COL_Y_DS4
	8, // RD0_SLAM
};

/**********************************************************
 * function name: cvdr_set_debug_enable
 *
 * description:
 *     set cvdr debug enable
 *
 * input:
 *     dev        : cvdr device
 *     wr_peak_en : enable the FIFO peak functionality over the write port
 *     rd_peak_en : enable the FIFO peak functionality over the read port
 *
 * output:
 *     0  : success
 *     -1 : failed
 ***********************************************************/
static int cvdr_set_debug_enable(cvdr_dev_t *dev, unsigned char wr_peak_en, unsigned char rd_peak_en)
{
	union u_axi_jpeg_cvdr_debug_en tmp;
	tmp.u32 = 0;
	tmp.bits.wr_peak_en = wr_peak_en;
	tmp.bits.rd_peak_en = rd_peak_en;
	hispcpe_reg_set(CVDR_REG, AXI_JPEG_AXI_JPEG_CVDR_DEBUG_EN_REG, tmp.u32);
	return CPE_FW_OK;
}

/**********************************************************
 * function name: cvdr_get_debug_info
 *
 * description:
 *     get cvdr debug info
 *
 * input:
 *     dev     : cvdr device
 *     wr_peak : peak number of Data Units used for the write functionality
 *     rd_peak : peak number of Data Units used for the read functionality
 *
 * output:
 *     0  : success
 *     -1 : failed
 ***********************************************************/
static int cvdr_get_debug_info(cvdr_dev_t *dev, unsigned char *wr_peak, unsigned char *rd_peak)
{
	union u_axi_jpeg_cvdr_debug tmp;
	tmp.u32 = hispcpe_reg_get(CVDR_REG, AXI_JPEG_AXI_JPEG_CVDR_DEBUG_REG);
	*wr_peak = tmp.bits.wr_peak;
	*rd_peak = tmp.bits.rd_peak;
	return CPE_FW_OK;
}

/**********************************************************
 * function name: cvdr_set_vp_wr_ready
 *
 * description:
 *     config cvdr video port write(vp_wr) configurations
 *
 * input:
 *     dev  : cvdr device
 *     port : write port number
 *     desc : vp wr configurations info
 *     addr : start address
 *
 * output:
 *     0  : success
 *     -1 : failed
 ***********************************************************/
static int cvdr_set_vp_wr_ready(cvdr_dev_t *dev, unsigned char port, cvdr_wr_fmt_desc_t *desc, cvdr_bw_cfg_t *bw)
{
	i("set wr port %d addr = 0x%x, dev->base_addr = 0x%x", port, desc->fs_addr, dev->base_addr);
	loge_if_ret(desc->fs_addr & 0xF);
	union u_axi_jpeg_vp_wr_cfg tmp_cfg;
	union u_axi_jpeg_vp_wr_axi_fs tmp_fs;
	union u_axi_jpeg_vp_wr_axi_line tmp_line;
	union u_axi_jpeg_vp_wr_if_cfg tmp_if_cfg;
	union u_axi_jpeg_limiter_vp_wr tmp_limiter;
	tmp_cfg.u32  = 0;
	tmp_fs.u32   = 0;
	tmp_line.u32 = 0;
	tmp_limiter.u32 = 0;
	tmp_if_cfg.u32 = 0;

	if (NULL == bw) {
		pr_err("vdr_bw_cfg_t* bw NULL!");
		return CPE_FW_ERR;
	}

	tmp_cfg.bits.vpwr_pixel_format       = desc->pix_fmt;
	tmp_cfg.bits.vpwr_pixel_expansion    = desc->pix_expan;
	tmp_cfg.bits.vpwr_last_page          = desc->last_page;
	tmp_fs.bits.vpwr_address_frame_start = (desc->fs_addr >> 2) >> 2;
	tmp_line.bits.vpwr_line_stride       = desc->line_stride;
	tmp_line.bits.vpwr_line_start_wstrb  = 0xF;
	tmp_line.bits.vpwr_line_wrap         = desc->line_wrap;
	tmp_limiter.bits.vpwr_access_limiter_0 = 0xF;
	tmp_limiter.bits.vpwr_access_limiter_1 = 0xF;
	tmp_limiter.bits.vpwr_access_limiter_2 = 0xF;
	tmp_limiter.bits.vpwr_access_limiter_3 = 0xF;
	tmp_limiter.bits.vpwr_access_limiter_reload = 0xF;
	tmp_if_cfg.bits.vpwr_prefetch_bypass = 0;

	switch (port) {
	case 4: {
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_LIMITER_VP_WR_4_REG, tmp_limiter.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_CFG_4_REG, tmp_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_LINE_4_REG, tmp_line.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_IF_CFG_4_REG, tmp_if_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_FS_4_REG, tmp_fs.u32);
		break;
	}

	case 5: {
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_LIMITER_VP_WR_5_REG, tmp_limiter.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_CFG_5_REG, tmp_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_LINE_5_REG, tmp_line.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_IF_CFG_5_REG, tmp_if_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_FS_5_REG, tmp_fs.u32);
		break;
	}

	case 6: {
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_LIMITER_VP_WR_6_REG, tmp_limiter.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_CFG_6_REG, tmp_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_LINE_6_REG, tmp_line.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_IF_CFG_6_REG, tmp_if_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_FS_6_REG, tmp_fs.u32);
		break;
	}

	case 30: {
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_LIMITER_VP_WR_30_REG, tmp_limiter.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_CFG_30_REG, tmp_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_LINE_30_REG, tmp_line.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_IF_CFG_30_REG, tmp_if_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_WR_AXI_FS_30_REG, tmp_fs.u32);
		break;
	}

	default:
		break;
	}

	i("VP_WR_CFG: 0x%x, pix_fmt = %d, pix_expan = %d", tmp_cfg.u32, desc->pix_fmt, desc->pix_expan);
	i("VP_WR_AXI_LINE: 0x%x, line_stride = %d, line_wrap = %d", tmp_line.u32, desc->line_stride, desc->line_wrap);
	return CPE_FW_OK;
}

/**********************************************************
 * function name: cvdr_set_vp_rd_ready
 *
 * description:
 *     config cvdr video port read(vp_rd) configurations
 *
 * input:
 *     dev  : cvdr device
 *     port : read port number
 *     desc : vp rd configurations info
 *     addr : start address
 *
 * output:
 *     0  : success
 *     -1 : failed
 ***********************************************************/
static int cvdr_set_vp_rd_ready(cvdr_dev_t *dev, unsigned char port, cvdr_rd_fmt_desc_t *desc, cvdr_bw_cfg_t *bw)
{
	pr_err("set rd port %d addr = 0x%x, dev->base_addr = 0x%x", port, desc->fs_addr, dev->base_addr);
	loge_if_ret(desc->fs_addr & 0xF);
	union u_axi_jpeg_vp_rd_cfg tmp_cfg;
	union u_axi_jpeg_vp_rd_lwg tmp_lwg;
	union u_axi_jpeg_vp_rd_fhg tmp_fhg;
	union u_axi_jpeg_vp_rd_axi_fs tmp_fs;
	union u_axi_jpeg_vp_rd_axi_line tmp_line;
	union u_axi_jpeg_vp_rd_if_cfg tmp_if_cfg;
	union u_axi_jpeg_limiter_vp_rd tmp_limiter;
	tmp_cfg.u32  = 0;
	tmp_lwg.u32  = 0;
	tmp_fhg.u32  = 0;
	tmp_fs.u32   = 0;
	tmp_line.u32 = 0;
	tmp_limiter.u32 = 0;
	tmp_if_cfg.u32 = 0;
	tmp_cfg.bits.vprd_pixel_format    = desc->pix_fmt;
	tmp_cfg.bits.vprd_pixel_expansion = desc->pix_expan;
	tmp_cfg.bits.vprd_allocated_du    = desc->allocated_du;
	tmp_cfg.bits.vprd_last_page       = desc->last_page;
	tmp_lwg.bits.vprd_line_size       = desc->line_size;
	tmp_lwg.bits.vprd_horizontal_blanking = desc->hblank;
	tmp_fhg.bits.vprd_frame_size      = desc->frame_size;
	tmp_fhg.bits.vprd_vertical_blanking   = desc->vblank;
	tmp_fs.bits.vprd_axi_frame_start  = (desc->fs_addr >> 2) >> 2;
	tmp_line.bits.vprd_line_stride    = desc->line_stride;
	tmp_line.bits.vprd_line_wrap      = desc->line_wrap;
	tmp_limiter.bits.vprd_access_limiter_0 = 0xF;
	tmp_limiter.bits.vprd_access_limiter_1 = 0xF;
	tmp_limiter.bits.vprd_access_limiter_2 = 0xF;
	tmp_limiter.bits.vprd_access_limiter_3 = 0xF;
	tmp_limiter.bits.vprd_access_limiter_reload = 0xF;
	tmp_if_cfg.bits.vprd_prefetch_bypass = 0;

	switch (port) {
	case 4: {
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_LIMITER_VP_RD_4_REG, tmp_limiter.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_CFG_4_REG, tmp_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_LWG_4_REG, tmp_lwg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_FHG_4_REG, tmp_fhg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_AXI_LINE_4_REG, tmp_line.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_IF_CFG_4_REG, tmp_if_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_AXI_FS_4_REG, tmp_fs.u32);
		break;
	}

	case 8: {
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_LIMITER_VP_RD_8_REG, tmp_limiter.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_CFG_8_REG, tmp_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_LWG_8_REG, tmp_lwg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_FHG_8_REG, tmp_fhg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_AXI_LINE_8_REG, tmp_line.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_IF_CFG_8_REG, tmp_if_cfg.u32);
		cmdlst_set_reg_m(dev->base_addr + AXI_JPEG_AXI_JPEG_VP_RD_AXI_FS_8_REG, tmp_fs.u32);
		break;
	}

	default:
		break;
	}

	i("VP_RD_CFG:      0x%x, pix_fmt = %d, pix_expan = %d, allocated_du = %d, last_page = %d",
	  tmp_cfg.u32, desc->pix_fmt, desc->pix_expan, desc->allocated_du, desc->last_page);
	i("VP_RD_LWG:      0x%x, line_size = %d, hblank = %d",
	  tmp_lwg.u32, desc->line_size, desc->hblank);
	i("VP_RD_FHG:      0x%x, frame_size = %d, vblank = %d",
	  tmp_fhg.u32, desc->frame_size, desc->vblank);
	i("VP_RD_AXI_LINE: 0x%x, line_stride = %d, line_wrap = %d",
	  tmp_line.u32, desc->line_stride, desc->line_wrap);
	i("VP_RD_AXI_FS:   0x%x, desc.addr = 0x%x,tmp_fs.bits.vprd_axi_frame_start = 0x%x ",
	  tmp_fs.u32, desc->fs_addr >> 2, tmp_fs.bits.vprd_axi_frame_start);
	return CPE_FW_OK;
}

/**********************************************************
 * function name: cvdr_do_config
 *
 * description:
 *     according to cvdr_config_table config cvdr
 *
 * input:
 *     dev    : cvdr device
 *     table  : cvdr configurations info table
 *
 * output:
 *     0  : success
 *     -1 : failed
 ***********************************************************/
static int cvdr_do_config(cvdr_dev_t *dev, cfg_tab_cvdr_t *table)
{
	d("[%s] +\n", __func__);

	if (NULL == dev || NULL == table) {
		pr_err("input param is invalid!!");
		return CPE_FW_ERR;
	}

	int i;

	for (i = 0; i < WR_MAX; ++i) {
		if (table->vp_wr_cfg[i].to_use) {
			loge_if_ret(cvdr_set_vp_wr_ready(dev, get_cvdr_wr_port_num(i), &(table->vp_wr_cfg[i].fmt),
				&(table->vp_wr_cfg[i].bw)));
			table->vp_wr_cfg[i].to_use = 0;
		}
	}

	for (i = RD_MAX - 1; i >= 0; --i) {
		if (table->vp_rd_cfg[i].to_use) {
			loge_if_ret(cvdr_set_vp_rd_ready(dev, get_cvdr_rd_port_num(i), &(table->vp_rd_cfg[i].fmt),
				&(table->vp_rd_cfg[i].bw)));
			table->vp_rd_cfg[i].to_use = 0;
		}
	}

	d("[%s] -\n", __func__);
	return CPE_FW_OK;
}

int cvdr_prepare_vprd_cmd(cvdr_dev_t *dev, cmd_buf_t *cmd_buf, cfg_tab_cvdr_t *table)
{
	dev->cmd_buf = cmd_buf;
	return CPE_FW_OK;
}

int cvdr_prepare_vpwr_cmd(cvdr_dev_t *dev, cmd_buf_t *cmd_buf, cfg_tab_cvdr_t *table)
{
	dev->cmd_buf = cmd_buf;
	return CPE_FW_OK;
}

int cvdr_prepare_cmd(cvdr_dev_t *dev, cmd_buf_t *cmd_buf, cfg_tab_cvdr_t *table)
{
	d("[%s] +\n", __func__);
	dev->cmd_buf = cmd_buf;
	loge_if_ret(cvdr_do_config(dev, table));
	d("[%s] -\n", __func__);
	return CPE_FW_OK;
}

static cvdr_ops_t cvdr_ops = {
	.set_debug_enable     = cvdr_set_debug_enable,
	.get_debug_info       = cvdr_get_debug_info,
	.set_vp_wr_ready      = cvdr_set_vp_wr_ready,
	.set_vp_rd_ready      = cvdr_set_vp_rd_ready,

	.do_config   = cvdr_do_config,
	.prepare_cmd = cvdr_prepare_cmd,
	.prepare_vprd_cmd = cvdr_prepare_vprd_cmd,
	.prepare_vpwr_cmd = cvdr_prepare_vpwr_cmd,
};

cvdr_dev_t g_cvdr_devs[] = {
	[0] =
	{
		.base_addr = JPG_CVDR_ADDR,
		.ops = &cvdr_ops,
	},
};

#pragma GCC diagnostic pop

