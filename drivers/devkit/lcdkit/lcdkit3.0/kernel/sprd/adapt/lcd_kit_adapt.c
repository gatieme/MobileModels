/*
 * lcd_kit_adapt.c
 *
 * lcdkit adapt function for lcd driver
 *
 * Copyright (c) 2018-2019 Honor Device Co., Ltd.
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

#include "lcd_kit_drm_panel.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_power.h"
#include <drm/drm_mipi_dsi.h>

#define MAX_TX_LEN_FOR_MIPI 16
/* dcs read/write */
#define DTYPE_DCS_WRITE     0x05 /* short write, 0 parameter */
#define DTYPE_DCS_WRITE1    0x15 /* short write, 1 parameter */
#define DTYPE_DCS_READ      0x06 /* read */
#define DTYPE_DCS_LWRITE    0x39 /* long write */

/* generic read/write */
#define DTYPE_GEN_WRITE     0x03 /* short write, 0 parameter */
#define DTYPE_GEN_WRITE1    0x13 /* short write, 1 parameter */
#define DTYPE_GEN_WRITE2    0x23 /* short write, 2 parameter */
#define DTYPE_GEN_LWRITE    0x29 /* long write */
#define DTYPE_GEN_READ      0x04 /* long read, 0 parameter */
#define DTYPE_GEN_READ1     0x14 /* long read, 1 parameter */
#define DTYPE_GEN_READ2     0x24 /* long read, 2 parameter */

struct dsi_cmd_common_desc {
	unsigned int dtype;
	unsigned int vc;
	unsigned int link_state;
	unsigned int tx_len[MAX_TX_LEN_FOR_MIPI];
	const void *tx_buf[MAX_TX_LEN_FOR_MIPI];
	unsigned int rx_len;
	char *rx_buf;
};

static int lcd_kit_cmd_is_write(struct lcd_kit_dsi_cmd_desc *cmd)
{
	int ret;

	if (cmd == NULL) {
		LCD_KIT_ERR("cmd is NULL!\n");
		return LCD_KIT_FAIL;
	}

	switch (cmd->dtype) {
	case DTYPE_GEN_WRITE:
	case DTYPE_GEN_WRITE1:
	case DTYPE_GEN_WRITE2:
	case DTYPE_GEN_LWRITE:
	case DTYPE_DCS_WRITE:
	case DTYPE_DCS_WRITE1:
	case DTYPE_DCS_LWRITE:
	case DTYPE_DSC_LWRITE:
		ret = LCD_KIT_FAIL;
		break;
	case DTYPE_GEN_READ:
	case DTYPE_GEN_READ1:
	case DTYPE_GEN_READ2:
	case DTYPE_DCS_READ:
		ret = LCD_KIT_OK;
		break;
	default:
		ret = LCD_KIT_FAIL;
		break;
	}
	return ret;
}

void mipi_dsi_cmds_tx(struct mipi_dsi_device *dsi,
	struct dsi_cmd_common_desc *cmds)
{
	ssize_t ret;

	if (cmds == NULL || dsi == NULL) {
		LCD_KIT_ERR("cmds or dsi is null");
		return;
	}
	switch (cmds->dtype) {
	case DTYPE_DCS_WRITE:
	case DTYPE_DCS_WRITE1:
	case DTYPE_DCS_LWRITE:
	case DTYPE_DSC_LWRITE:
		ret = mipi_dsi_dcs_write_buffer(dsi, cmds->tx_buf[0], cmds->tx_len[0]);
		break;
	case DTYPE_GEN_WRITE:
	case DTYPE_GEN_WRITE1:
	case DTYPE_GEN_WRITE2:
	case DTYPE_GEN_LWRITE:
		ret = mipi_dsi_generic_write(dsi, cmds->tx_buf[0], cmds->tx_len[0]);
		break;
	default:
		ret = mipi_dsi_dcs_write_buffer(dsi, cmds->tx_buf[0], cmds->tx_len[0]);
		break;
	}
	LCD_KIT_ERR("len is %d\n", cmds->tx_len[0]);
	if (ret < 0)
		LCD_KIT_ERR("write error is %d cmd is 0x%x\n", ret, *((unsigned char *)cmds->tx_buf[0]));
}

void mipi_dsi_cmds_rx(struct mipi_dsi_device *dsi,
	struct dsi_cmd_common_desc *cmds)
{
	ssize_t ret;

	if (cmds == NULL || dsi == NULL) {
		LCD_KIT_ERR("cmds or dsi is null");
		return;
	}
	mipi_dsi_set_maximum_return_packet_size(dsi, cmds->rx_len);
	switch (cmds->dtype) {
	case DTYPE_DCS_READ:
		ret = mipi_dsi_dcs_read(dsi, *(unsigned char *)cmds->tx_buf[0],
			cmds->rx_buf, cmds->rx_len);
		break;
	case DTYPE_GEN_READ:
	case DTYPE_GEN_READ1:
	case DTYPE_GEN_READ2:
		ret = mipi_dsi_generic_read(dsi, cmds->tx_buf[0],
			cmds->tx_len[0], cmds->rx_buf, cmds->rx_len);
		break;
	default:
		break;
	}

	if (ret < 0)
		LCD_KIT_ERR("read error is %d cmd is 0x%x\n", ret, *((unsigned char *)cmds->tx_buf[0]));
}

static int lcd_kit_cmds_to_dsi_cmds(struct lcd_kit_dsi_cmd_desc *lcd_kit_cmds,
	struct dsi_cmd_common_desc *cmd, int link_state)
{
	if (lcd_kit_cmds == NULL) {
		LCD_KIT_ERR("lcd_kit_cmds is null point!\n");
		return LCD_KIT_FAIL;
	}
	if (cmd == NULL) {
		LCD_KIT_ERR("cmd is null point!\n");
		return LCD_KIT_FAIL;
	}
	cmd->dtype = lcd_kit_cmds->dtype;
	cmd->vc = lcd_kit_cmds->vc;
	cmd->link_state = link_state;
	cmd->tx_len[0] = lcd_kit_cmds->dlen;
	cmd->tx_buf[0] = lcd_kit_cmds->payload;

	return LCD_KIT_OK;
}

static int lcd_kit_cmds_to_dsi_read_cmds(struct lcd_kit_dsi_cmd_desc *lcd_kit_cmds,
	unsigned char *out, int out_len,
	struct dsi_cmd_common_desc *cmd, int link_state)
{
	if (lcd_kit_cmds == NULL || cmd == NULL || out == NULL) {
		LCD_KIT_ERR("lcd_kit_cmds or cmd or out is null\n");
		return LCD_KIT_FAIL;
	}
	cmd->dtype = lcd_kit_cmds->dtype;
	cmd->vc = lcd_kit_cmds->vc;
	cmd->link_state = link_state;
	cmd->tx_len[0] = 1;
	cmd->tx_buf[0] = lcd_kit_cmds->payload;
	cmd->rx_len = lcd_kit_cmds->dlen;
	cmd->rx_buf = out;

	return LCD_KIT_OK;
}

int sprd_mipi_dsi_cmds_tx(void *dsi, struct lcd_kit_dsi_cmd_desc *cmds,
	int cnt, int link_state)
{
	struct lcd_kit_dsi_cmd_desc *cm = NULL;
	struct dsi_cmd_common_desc dsi_cmd = {0};
	int i;

	if (cmds == NULL || dsi == NULL) {
		LCD_KIT_ERR("cmds or dsi is null");
		return -EINVAL;
	}
	cm = cmds;
	for (i = 0; i < cnt; i++) {
		lcd_kit_cmds_to_dsi_cmds(cm, &dsi_cmd, link_state);
		mipi_dsi_cmds_tx(dsi, &dsi_cmd);
		if (!(cm->wait)) {
			cm++;
			continue;
		}
		if (cm->waittype == WAIT_TYPE_US) {
			udelay(cm->wait);
		} else if (cm->waittype == WAIT_TYPE_MS) {
			if (cm->wait <= 10)
				mdelay(cm->wait);
			else
				msleep(cm->wait);
		} else {
			msleep(cm->wait * 1000); // change s to ms
		}
		cm++;
	}

	return cnt;
}

int lcd_kit_dsi_cmds_tx(void *dsi, struct lcd_kit_dsi_panel_cmds *cmds)
{
	int i;

	if (!cmds || !dsi) {
		LCD_KIT_ERR("lcd_kit_cmds or dsi is null\n");
		return LCD_KIT_FAIL;
	}

	down(&disp_info->lcd_kit_sem);
	for (i = 0; i < cmds->cmd_cnt; i++)
		sprd_mipi_dsi_cmds_tx(dsi, &cmds->cmds[i], 1, cmds->link_state);
	up(&disp_info->lcd_kit_sem);
	return LCD_KIT_OK;
}

int lcd_kit_dsi_cmds_rx(void *dsi, unsigned char *out, int out_len,
	struct lcd_kit_dsi_panel_cmds *cmds)
{
	int i;
	int ret = 0;
	struct dsi_cmd_common_desc dsi_cmd = {0};

	if ((cmds == NULL) || (out == NULL) || (dsi == NULL)) {
		LCD_KIT_ERR("out or cmds or dsi is null\n");
		return LCD_KIT_FAIL;
	}

	down(&disp_info->lcd_kit_sem);
	for (i = 0; i < cmds->cmd_cnt; i++) {
		if (lcd_kit_cmd_is_write(&cmds->cmds[i])) {
			lcd_kit_cmds_to_dsi_cmds(&cmds->cmds[i], &dsi_cmd,
				cmds->link_state);
			ret = sprd_mipi_dsi_cmds_tx(dsi, &cmds->cmds[i],
				1, cmds->link_state);
			if (ret < 0)
				LCD_KIT_ERR("mipi write error\n");
		} else {
			lcd_kit_cmds_to_dsi_read_cmds(&cmds->cmds[i], &out[0], out_len,
				&dsi_cmd, cmds->link_state);
			mipi_dsi_cmds_rx(dsi, &dsi_cmd);
		}
	}
	up(&disp_info->lcd_kit_sem);
	return ret;
}

int lcd_kit_dsi_cmds_extern_rx(unsigned char *out,
	struct lcd_kit_dsi_panel_cmds *cmds, unsigned int len)
{
	unsigned int i;
	unsigned int j;
	unsigned int k = 0;
	int ret;
	unsigned char buffer[MTK_READ_MAX_LEN] = {0};
	struct sprd_panel_info *panel_info = NULL;
	struct mutex *panel_lock = NULL;
	struct dsi_cmd_common_desc dsi_cmd = {0};

	if ((cmds == NULL)  || (out == NULL) || (len == 0)) {
		LCD_KIT_ERR("out or cmds is NULL\n");
		return LCD_KIT_FAIL;
	}
	panel_info = lcm_get_panel_info();
	if (panel_info == NULL) {
 		LCD_KIT_ERR("panel_info is NULL\n");
 		return LCD_KIT_FAIL;
	}
	panel_lock = lcm_get_panel_lock();
	if (panel_lock == NULL) {
 		LCD_KIT_ERR("panel_lock is NULL\n");
 		return LCD_KIT_FAIL;
	}
	mutex_lock(panel_lock);
	for (i = 0; i < cmds->cmd_cnt; i++) {
		if (lcd_kit_cmd_is_write(&cmds->cmds[i])) {
			ret = sprd_mipi_dsi_cmds_tx(panel_info->slave, &cmds->cmds[i],
				1, cmds->link_state);
			if (ret < 0)
				LCD_KIT_ERR("mipi write error\n");
		} else {
			ret = lcd_kit_cmds_to_dsi_read_cmds(&cmds->cmds[i], &buffer[0], len,
				&dsi_cmd, cmds->link_state);
			if (ret != LCD_KIT_OK) {
				LCD_KIT_ERR("exchange dsi mipi fail\n");
				return LCD_KIT_FAIL;
			}
			if (dsi_cmd.rx_len == 0) {
				LCD_KIT_ERR("cmd len is 0\n");
				return LCD_KIT_FAIL;
			}
			LCD_KIT_INFO("cmd len is %d!\n", dsi_cmd.rx_len);
			mipi_dsi_cmds_rx(panel_info->slave, &dsi_cmd);
			for (j = 0; j < dsi_cmd.rx_len; j++) {
				out[k] = buffer[j];
				LCD_KIT_INFO("read the %d value is 0x%x\n", k, out[k]);
				k++;
				if (k == len) {
					LCD_KIT_INFO("buffer is full, len is %d\n", len);
					break;
				}
			}
		}
	}
	mutex_unlock(panel_lock);
	return LCD_KIT_OK;
}

int lcd_kit_dsi_cmds_extern_tx(struct lcd_kit_dsi_panel_cmds *cmds)
{
 	int ret = LCD_KIT_OK;
 	int i;
	struct sprd_panel_info *panel_info = NULL;
	struct mutex *panel_lock = NULL;

 	if (cmds == NULL) {
 		LCD_KIT_ERR("lcd_kit_cmds is NULL\n");
 		return LCD_KIT_FAIL;
 	}
	panel_info = lcm_get_panel_info();
	if (panel_info == NULL) {
 		LCD_KIT_ERR("panel_info is NULL\n");
 		return LCD_KIT_FAIL;
	}
	panel_lock = lcm_get_panel_lock();
	if (panel_lock == NULL) {
 		LCD_KIT_ERR("panel_lock is NULL\n");
 		return LCD_KIT_FAIL;
	}
	mutex_lock(panel_lock);
	for (i = 0; i < cmds->cmd_cnt; i++)
		sprd_mipi_dsi_cmds_tx(panel_info->slave, &cmds->cmds[i], 1, cmds->link_state);
	mutex_unlock(panel_lock);
 	return ret;
}


static int lcd_kit_buf_trans(const char *inbuf, int inlen, char **outbuf,
	int *outlen)
{
	char *buf = NULL;
	int i;
	int bufsize = inlen;

	if (!inbuf || !outbuf || !outlen) {
		LCD_KIT_ERR("inbuf is null point!\n");
		return LCD_KIT_FAIL;
	}
	/* The property is 4 bytes long per element in cells: <> */
	bufsize = bufsize / 4;
	if (bufsize <= 0) {
		LCD_KIT_ERR("bufsize is less 0!\n");
		return LCD_KIT_FAIL;
	}
	/* If use bype property: [], this division should be removed */
	buf = kzalloc(sizeof(char) * bufsize, GFP_KERNEL);
	if (!buf) {
		LCD_KIT_ERR("buf is null point!\n");
		return LCD_KIT_FAIL;
	}
	/* For use cells property: <> */
	for (i = 0; i < bufsize; i++)
		buf[i] = inbuf[i * 4 + 3];
	*outbuf = buf;
	*outlen = bufsize;
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_enable(u32 type)
{
	lcd_kit_gpio_tx(type, GPIO_HIGH);
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_disable(u32 type)
{
	lcd_kit_gpio_tx(type, GPIO_LOW);
	return LCD_KIT_OK;
}
#if 0
static int lcd_kit_regulator_enable(u32 type)
{
	int ret;

	switch (type) {
	case LCD_KIT_VSP:
	case LCD_KIT_VSN:
	case LCD_KIT_BL:
		ret = lcd_kit_charger_ctrl(type, LDO_ENABLE);
		break;
	case LCD_KIT_VCI:
	case LCD_KIT_IOVCC:
		ret = lcd_kit_pmu_ctrl(type, LDO_ENABLE);
		break;
	default:
		ret = LCD_KIT_FAIL;
		LCD_KIT_ERR("regulator type:%d not support\n", type);
		break;
	}
	return ret;
}

static int lcd_kit_regulator_disable(u32 type)
{
	int ret = LCD_KIT_OK;

	switch (type) {
	case LCD_KIT_VSP:
	case LCD_KIT_VSN:
	case LCD_KIT_BL:
		ret = lcd_kit_charger_ctrl(type, LDO_DISABLE);
		break;
	case LCD_KIT_VCI:
	case LCD_KIT_IOVCC:
		ret = lcd_kit_pmu_ctrl(type, LDO_DISABLE);
		break;
	default:
		LCD_KIT_ERR("regulator type:%d not support\n", type);
		break;
	}
	return ret;
}
#endif
static int lcd_kit_lock(void *hld)
{
	return LCD_KIT_FAIL;
}

static void lcd_kit_release(void *hld)
{
}

void *lcd_kit_get_pdata_hld(void)
{
	return 0;
}

struct lcd_kit_adapt_ops adapt_ops = {
	.mipi_tx = lcd_kit_dsi_cmds_tx,
	.mipi_rx = lcd_kit_dsi_cmds_rx,
	.gpio_enable = lcd_kit_gpio_enable,
	.gpio_disable = lcd_kit_gpio_disable,
	.regulator_enable = NULL,
	.regulator_disable = NULL,
	.buf_trans = lcd_kit_buf_trans,
	.lock = lcd_kit_lock,
	.release = lcd_kit_release,
	.get_pdata_hld = lcd_kit_get_pdata_hld,
};
int lcd_kit_adapt_init(void)
{
	int ret;

	ret = lcd_kit_adapt_register(&adapt_ops);
	return ret;
}
