/*
 * lcd_kit_adapt.c
 *
 * lcdkit adapt function for lcd driver
 *
 * Copyright (c) 2022-2024 Huawei Technologies Co., Ltd.
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

#include "lcd_kit_adapt.h"
#include "lcd_kit_common.h"
#include "lcd_kit_disp.h"
#include "lcd_kit_power.h"
#include "lcd_kit_ext_power.h"
#include "lcd_kit_disp.h"
#include <securec.h>

static void lcd_kit_dump_cmd(struct dsi_cmd_desc *cmd)
{
	unsigned int i;

	LCD_KIT_DEBUG("cmd->dtype = 0x%x\n", cmd->dtype);
	LCD_KIT_DEBUG("cmd->vc = 0x%x\n", cmd->vc);
	LCD_KIT_DEBUG("cmd->wait = 0x%x\n", cmd->wait);
	LCD_KIT_DEBUG("cmd->waittype = 0x%x\n", cmd->waittype);
	LCD_KIT_DEBUG("cmd->dlen = 0x%x\n", cmd->dlen);
	LCD_KIT_DEBUG("cmd->payload:\n");
	for (i = 0; i < cmd->dlen; i++)
		LCD_KIT_DEBUG("0x%x\n", cmd->payload[i]);
}

static int lcd_kit_cmds_to_dsi_cmds(struct lcd_kit_dsi_cmd_desc *lcd_kit_cmds,
	struct dsi_cmd_desc *cmd, int link_state)
{
	if (lcd_kit_cmds == NULL) {
		LCD_KIT_ERR("lcd_kit_cmds is null point!\n");
		return LCD_KIT_FAIL;
	}
	if (cmd == NULL) {
		LCD_KIT_ERR("cmd is null!\n");
		return LCD_KIT_FAIL;
	}
	cmd->dtype = lcd_kit_cmds->dtype;
	cmd->vc =  lcd_kit_cmds->vc;
	cmd->waittype =  lcd_kit_cmds->waittype;
	cmd->dlen =  lcd_kit_cmds->dlen;
	cmd->payload = lcd_kit_cmds->payload;
	lcd_kit_dump_cmd(cmd);
	return LCD_KIT_OK;
}

static bool lcd_kit_cmd_is_write(struct dsi_cmd_desc *cmd)
{
	bool is_write = true;

	switch (cmd->dtype) {
	case DTYPE_GEN_WRITE:
	case DTYPE_GEN_WRITE1:
	case DTYPE_GEN_WRITE2:
	case DTYPE_GEN_LWRITE:
	case DTYPE_DCS_WRITE:
	case DTYPE_DCS_WRITE1:
	case DTYPE_DCS_LWRITE:
	case DTYPE_DSC_LWRITE:
		is_write = true;
		break;
	case DTYPE_GEN_READ:
	case DTYPE_GEN_READ1:
	case DTYPE_GEN_READ2:
	case DTYPE_DCS_READ:
		is_write = false;
		break;
	default:
		is_write = false;
		break;
	}
	return is_write;
}

static int lcd_kit_dsi_cmd_rx(int panel_id, unsigned char *out,
	int out_len, struct dsi_cmd_desc *cmd)
{
	int ret;
	unsigned int dsi_index;
	unsigned int connector_id;

	if (!cmd) {
		LCD_KIT_ERR("cmd is null\n");
		return LCD_KIT_FAIL;
	}

	connector_id = DPU_PINFO->connector_id;
	ret = lcd_kit_get_dsi_index(&dsi_index, connector_id);
	if (ret) {
		LCD_KIT_ERR("get dsi index error\n");
		return LCD_KIT_FAIL;
	}

	LCD_KIT_DEBUG("rx %d send cmd\n", dsi_index);
	mipi_dsi_cmds_rx_for_usr(dsi_index, out, out_len, cmd, false, DPU_PINFO->type);

	return LCD_KIT_OK;
}

static int lcd_kit_dual_dsi_cmd_rx(int panel_id, unsigned char *out0, unsigned char *out1,
	int out_len, struct dsi_cmd_desc *cmd)
{
	int ret;
	unsigned int connector_id;
	unsigned int cmd_type;
	unsigned int dsi0_index;
	unsigned int dsi1_index;

	if (!cmd) {
		LCD_KIT_ERR("cmd is null\n");
		return LCD_KIT_FAIL;
	}

	connector_id = DPU_PINFO->connector_id;
	cmd_type = DPU_PINFO->type;
	if (is_dual_mipi_panel(cmd_type)) {
		ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi0 index error\n");
			return LCD_KIT_FAIL;
		}
		connector_id &= (~(1 << dsi0_index));
		ret = lcd_kit_get_dsi_index(&dsi1_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi1 index error\n");
			return LCD_KIT_FAIL;
		}
		LCD_KIT_INFO("dual %d %d send cmd\n", dsi0_index, dsi1_index);
		mipi_dual_dsi_cmds_rx_for_usr(dsi0_index, out0, dsi1_index,
			out1, out_len, cmd, false, DPU_PINFO->type);
	} else {
		LCD_KIT_ERR("dual panel error\n");
		return LCD_KIT_FAIL;
	}

	return LCD_KIT_OK;
}

static int lcd_kit_dsi_cmd_tx(int panel_id, struct dsi_cmd_desc *cmd, int lock)
{
	int ret;
	unsigned int connector_id;
	unsigned int cmd_type;
	unsigned int dsi0_index;
	unsigned int dsi1_index;

	if (!cmd) {
		LCD_KIT_ERR("cmd is null\n");
		return LCD_KIT_FAIL;
	}

	connector_id = DPU_PINFO->connector_id;
	cmd_type = DPU_PINFO->type;
	if (is_dual_mipi_panel(cmd_type)) {
		ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi0 index error\n");
			return LCD_KIT_FAIL;
		}
		connector_id &= (~(1 << dsi0_index));
		ret = lcd_kit_get_dsi_index(&dsi1_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi1 index error\n");
			return LCD_KIT_FAIL;
		}
		LCD_KIT_DEBUG("dual %d %d send cmd\n", dsi0_index, dsi1_index);
		if (lock == NO_LOCK) {
			LCD_KIT_DEBUG("enter no lock\n");
			mipi_dual_dsi_cmds_tx_for_usr_isr_safe(dsi0_index, cmd, 1, dsi1_index, cmd, 1, 0, DPU_PINFO->type);
		} else {
			LCD_KIT_DEBUG("enter lock\n");
			mipi_dual_dsi_cmds_tx_for_usr(dsi0_index, cmd, 1, dsi1_index, cmd, 1, 0, DPU_PINFO->type);
		}
	} else {
		ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
		if (ret) {
			LCD_KIT_ERR("get dsi0 index error\n");
			return LCD_KIT_FAIL;
		}
		LCD_KIT_DEBUG("single %d send cmd\n", dsi0_index);
		if (lock == NO_LOCK) {
			LCD_KIT_DEBUG("enter no lock\n");
			mipi_dsi_cmds_tx_for_usr_isr_safe(dsi0_index, cmd, 1, DPU_PINFO->type);
		} else {
			LCD_KIT_DEBUG("enter lock\n");
			mipi_dsi_cmds_tx_for_usr(dsi0_index, cmd, 1, DPU_PINFO->type);
		}
	}

	return ret;
}

#define MAX_WAIT_TIME 20
static void wait_no_lock_completion(int panel_id)
{
	if (panel_id != PRIMARY_PANEL)
		return;
	reinit_completion(&disp_info->lcd_completion.tx_no_lock_done);
	LCD_KIT_INFO("wait no_lock_done!\n");
	if (!wait_for_completion_timeout(&disp_info->lcd_completion.tx_no_lock_done,
		msecs_to_jiffies(MAX_WAIT_TIME)))
		LCD_KIT_ERR("wait tx no lock time out!\n");
}

int lcd_kit_cmds_tx(int panel_id, void *hld, struct lcd_kit_dsi_panel_cmds *cmds)
{
	int i;
	int link_state;
	struct dsi_cmd_desc dsi_cmd;
	unsigned int dsi0_index;
	unsigned int connector_id;
	int ret;

	if (cmds == NULL || cmds->cmds == NULL || cmds->cmd_cnt <= 0) {
		LCD_KIT_ERR("cmds is null, or cmd_cnt <= 0!\n");
		return LCD_KIT_FAIL;
	}

	memset(&dsi_cmd, 0, sizeof(dsi_cmd));
	link_state = cmds->link_state;
	connector_id = DPU_PINFO->connector_id;
	ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
	if (ret) {
		LCD_KIT_ERR("get dsi0 index error\n");
		return LCD_KIT_FAIL;
	}

	if (disp_info->lcd_completion.is_in_tx_no_lock == true)
		wait_no_lock_completion(panel_id);
	down(&DISP_LOCK->lcd_kit_sem);
	/* switch to LP mode */
	if (cmds->link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, LCD_KIT_DSI_LP_MODE);
	for (i = 0; i < cmds->cmd_cnt; i++) {
		lcd_kit_cmds_to_dsi_cmds(&cmds->cmds[i], &dsi_cmd, link_state);
		lcd_kit_dsi_cmd_tx(panel_id, &dsi_cmd, LOCK);
		if (cmds->cmds[i].waittype & SELF_REFRESH_FLAG)
			dkmd_dfr_send_refresh(dsi0_index, DPU_PINFO->type);
		lcd_kit_delay(cmds->cmds[i].wait, cmds->cmds[i].waittype, true);
	}

	LCD_KIT_DEBUG("send cmd len = %d\n", cmds->cmd_cnt);
	/* switch to HS mode */
	if (cmds->link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, LCD_KIT_DSI_HS_MODE);
	up(&DISP_LOCK->lcd_kit_sem);

	return LCD_KIT_OK;
}

int lcd_kit_cmds_tx_no_lock(int panel_id, void *hld, struct lcd_kit_dsi_panel_cmds *cmds)
{
	int i;
	int link_state;
	struct dsi_cmd_desc dsi_cmd;
	unsigned int dsi0_index;
	unsigned int connector_id;
	int ret;

	if (cmds == NULL || cmds->cmds == NULL || cmds->cmd_cnt <= 0) {
		LCD_KIT_ERR("cmds is null, or cmd_cnt <= 0!\n");
		return LCD_KIT_FAIL;
	}

	memset(&dsi_cmd, 0, sizeof(dsi_cmd));
	link_state = cmds->link_state;
	connector_id = DPU_PINFO->connector_id;
	ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
	if (ret) {
		LCD_KIT_ERR("get dsi0 index error\n");
		return LCD_KIT_FAIL;
	}
	disp_info->lcd_completion.is_in_tx_no_lock = true;
	/* switch to LP mode */
	if (cmds->link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, LCD_KIT_DSI_LP_MODE);
	for (i = 0; i < cmds->cmd_cnt; i++) {
		lcd_kit_cmds_to_dsi_cmds(&cmds->cmds[i], &dsi_cmd, link_state);
		lcd_kit_dsi_cmd_tx(panel_id, &dsi_cmd, NO_LOCK);
		if (cmds->cmds[i].waittype & SELF_REFRESH_FLAG)
			dkmd_dfr_send_refresh(dsi0_index, DPU_PINFO->type);
		lcd_kit_delay(cmds->cmds[i].wait, cmds->cmds[i].waittype, true);
	}

	LCD_KIT_INFO("send cmd len = %d\n", cmds->cmd_cnt);
	/* switch to HS mode */
	if (cmds->link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, LCD_KIT_DSI_HS_MODE);
	complete_all(&disp_info->lcd_completion.tx_no_lock_done);
	disp_info->lcd_completion.is_in_tx_no_lock = false;
	return LCD_KIT_OK;
}

int lcd_kit_cmds_rx(int panel_id, void *hld, unsigned char *out, int out_len,
	struct lcd_kit_dsi_panel_cmds *cmds)
{
	int ret = LCD_KIT_OK;
	int i, j, link_state;
	int cnt = 0;
	struct dsi_cmd_desc dsi_cmd;
	unsigned char tmp[BUF_MAX] = {0};
	unsigned int dsi0_index;
	unsigned int connector_id;

	if (cmds == NULL || cmds->cmds == NULL || cmds->cmd_cnt <= 0) {
		LCD_KIT_ERR("cmds is null, or cmd_cnt <= 0!\n");
		return LCD_KIT_FAIL;
	}

	if (out == NULL) {
		LCD_KIT_ERR("out is null!\n");
		return LCD_KIT_FAIL;
	}

	connector_id = DPU_PINFO->connector_id;
	ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
	if (ret) {
		LCD_KIT_ERR("get dsi0 index error\n");
		return LCD_KIT_FAIL;
	}
	memset(&dsi_cmd, 0, sizeof(dsi_cmd));
	link_state = cmds->link_state;
	down(&DISP_LOCK->lcd_kit_sem);
	if (link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, link_state);
	for (i = 0; i < cmds->cmd_cnt; i++) {
		memset(tmp, 0, sizeof(tmp));
		lcd_kit_cmds_to_dsi_cmds(&cmds->cmds[i], &dsi_cmd, link_state);
		if (lcd_kit_cmd_is_write(&dsi_cmd)) {
			ret = lcd_kit_dsi_cmd_tx(panel_id, &dsi_cmd, LOCK);
			if (cmds->cmds[i].waittype & SELF_REFRESH_FLAG)
				dkmd_dfr_send_refresh(dsi0_index, DPU_PINFO->type);
		} else {
			ret = lcd_kit_dsi_cmd_rx(panel_id, tmp, BUF_MAX, &dsi_cmd);
			for (j = 0; (j < dsi_cmd.dlen) && (cnt <= out_len); j++)
				out[cnt++] = tmp[j];
		}
		lcd_kit_delay(cmds->cmds[i].wait, cmds->cmds[i].waittype, true);
	}

	LCD_KIT_DEBUG("send cmd len = %d\n", cmds->cmd_cnt);
	if (link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, LCD_KIT_DSI_HS_MODE);
	up(&DISP_LOCK->lcd_kit_sem);

	return ret;
}

int lcd_kit_dual_cmds_rx(int panel_id, void *hld, unsigned char *out0, unsigned char *out1,
	int out_len, struct lcd_kit_dsi_panel_cmds *cmds)
{
	int ret = LCD_KIT_OK;
	int i, j, link_state;
	int cnt0 = 0;
	int cnt1 = 0;
	struct dsi_cmd_desc dsi_cmd;
	unsigned char tmp0[BUF_MAX] = {0};
	unsigned char tmp1[BUF_MAX] = {0};

	if (cmds == NULL || cmds->cmds == NULL || cmds->cmd_cnt <= 0) {
		LCD_KIT_ERR("cmds is null, or cmd_cnt <= 0!\n");
		return LCD_KIT_FAIL;
	}

	if (out0 == NULL || out1 == NULL) {
		LCD_KIT_ERR("out is null!\n");
		return LCD_KIT_FAIL;
	}

	memset(&dsi_cmd, 0, sizeof(dsi_cmd));
	link_state = cmds->link_state;
	down(&DISP_LOCK->lcd_kit_sem);
	if (link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, link_state);
	for (i = 0; i < cmds->cmd_cnt; i++) {
		memset(tmp0, 0, sizeof(tmp0));
		memset(tmp1, 0, sizeof(tmp1));
		lcd_kit_cmds_to_dsi_cmds(&cmds->cmds[i], &dsi_cmd, link_state);
		if (lcd_kit_cmd_is_write(&dsi_cmd)) {
			ret = lcd_kit_dsi_cmd_tx(panel_id, &dsi_cmd, LOCK);
		} else {
			ret = lcd_kit_dual_dsi_cmd_rx(panel_id, tmp0, tmp1, BUF_MAX, &dsi_cmd);
			for (j = 0; (j < dsi_cmd.dlen) && (cnt0 <= out_len) && (cnt1 <= out_len); j++) {
				out0[cnt0++] = tmp0[j];
				out1[cnt1++] = tmp1[j];
			}
		}
		lcd_kit_delay(cmds->cmds[i].wait, cmds->cmds[i].waittype, true);
	}

	LCD_KIT_INFO("send cmd len = %d\n", cmds->cmd_cnt);
	if (link_state == LCD_KIT_DSI_LP_MODE)
		lcd_kit_set_mipi_link(panel_id, LCD_KIT_DSI_HS_MODE);
	up(&DISP_LOCK->lcd_kit_sem);

	return ret;
}

static int lcd_kit_gpio_enable(int panel_id, unsigned int type)
{
	lcd_kit_gpio_tx(panel_id, type, GPIO_REQ);
	lcd_kit_gpio_tx(panel_id, type, GPIO_HIGH);
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_disable(int panel_id, unsigned int type)
{
	lcd_kit_gpio_tx(panel_id, type, GPIO_LOW);
	lcd_kit_gpio_tx(panel_id, type, GPIO_FREE);
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_disable_plugin(unsigned int type)
{
	lcd_kit_gpio_tx_plugin(type, GPIO_LOW);
	lcd_kit_gpio_tx_plugin(type, GPIO_FREE);
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_enable_nolock(int panel_id, unsigned int type)
{
	lcd_kit_gpio_tx(panel_id, type, GPIO_REQ);
	lcd_kit_gpio_tx(panel_id, type, GPIO_HIGH);
	lcd_kit_gpio_tx(panel_id, type, GPIO_FREE);
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_disable_nolock(int panel_id, unsigned int type)
{
	lcd_kit_gpio_tx(panel_id, type, GPIO_REQ);
	lcd_kit_gpio_tx(panel_id, type, GPIO_LOW);
	lcd_kit_gpio_tx(panel_id, type, GPIO_FREE);
	return LCD_KIT_OK;
}

static int lcd_kit_regulator_enable(int panel_id, unsigned int type, int enable)
{
	int ret = LCD_KIT_OK;

	switch (type) {
	case LCD_KIT_VCI:
	case LCD_KIT_IOVCC:
	case LCD_KIT_VDD:
		ret = lcd_kit_pmu_ctrl(panel_id, type, enable);
		break;
	default:
		ret = LCD_KIT_FAIL;
		LCD_KIT_ERR("regulator type:%d not support\n", type);
		break;
	}
	return ret;
}

static int lcd_kit_buf_trans(const char *inbuf, int inlen,
	char **outbuf, int *outlen)
{
	char *buf = NULL;
	int i;
	int bufsize = inlen;

	if (!inbuf) {
		LCD_KIT_ERR("inbuf is null point!\n");
		return LCD_KIT_FAIL;
	}
	/* The property is 4bytes long per element in cells: <> */
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
	// For use cells property: <>
	for (i = 0; i < bufsize; i++)
		buf[i] = inbuf[i * 4 + 3];
	*outbuf = buf;
	*outlen = bufsize;
	return LCD_KIT_OK;
}

static int lcd_kit_read_nv_info(uint32_t panel_id, int nv_num,
	int valid_size, char *info, uint32_t info_len)
{
	int ret;

	if (!info || info_len == 0) {
		LCD_KIT_ERR("invalid info\n");
		return LCD_KIT_FAIL;
	}
	if (memset_s(&disp_info->nv_info, sizeof(disp_info->nv_info), 0,
		sizeof(disp_info->nv_info)) != EOK) {
		LCD_KIT_ERR("memset_s fail\n");
		return LCD_KIT_FAIL;
	}
	disp_info->nv_info.nv_operation = NV_READ;
	disp_info->nv_info.nv_number = nv_num;
	disp_info->nv_info.valid_size = valid_size;
	if (strncpy_s(disp_info->nv_info.nv_name, sizeof(disp_info->nv_info.nv_name),
		"LCD_STA", sizeof("LCD_STA")) != EOK) {
		LCD_KIT_ERR("strncpy_s fail\n");
		return LCD_KIT_FAIL;
	}
	disp_info->nv_info.nv_name[sizeof(disp_info->nv_info.nv_name) - 1] = '\0';
	ret = nve_direct_access_interface(&disp_info->nv_info);
	if (ret != 0) {
		LCD_KIT_ERR("read nv %d fail\n", nv_num);
		return LCD_KIT_FAIL;
	}
	if (memcpy_s(info, info_len, disp_info->nv_info.nv_data, valid_size) != EOK) {
		LCD_KIT_ERR("memcpy_s fail\n");
		return LCD_KIT_FAIL;
	}
	return LCD_KIT_OK;
}

static int lcd_kit_write_nv_info(uint32_t panel_id, int nv_num,
	int valid_size, char *info, uint32_t info_len)
{
	int ret;

	if (!info || info_len == 0) {
		LCD_KIT_ERR("invalid info\n");
		return LCD_KIT_FAIL;
	}
	if (memset_s(&disp_info->nv_info, sizeof(disp_info->nv_info), 0,
		sizeof(disp_info->nv_info)) != EOK) {
		LCD_KIT_ERR("memset_s fail\n");
		return LCD_KIT_FAIL;
	}
	disp_info->nv_info.nv_operation = NV_WRITE;
	disp_info->nv_info.nv_number = nv_num;
	disp_info->nv_info.valid_size = valid_size;
	if (strncpy_s(disp_info->nv_info.nv_name, sizeof(disp_info->nv_info.nv_name),
		"LCD_STA", sizeof("LCD_STA")) != EOK) {
		LCD_KIT_ERR("strncpy_s fail\n");
		return LCD_KIT_FAIL;
	}
	disp_info->nv_info.nv_name[sizeof(disp_info->nv_info.nv_name) - 1] = '\0';
	if (memcpy_s(disp_info->nv_info.nv_data, sizeof(disp_info->nv_info.nv_data),
		info, info_len) != EOK) {
		LCD_KIT_ERR("memcpy_s fail\n");
		return LCD_KIT_FAIL;
	}
	ret = nve_direct_access_interface(&disp_info->nv_info);
	if (ret != 0) {
		LCD_KIT_ERR("write nv %d fail\n", nv_num);
		return LCD_KIT_FAIL;
	}
	return LCD_KIT_OK;
}

struct lcd_kit_adapt_ops adapt_ops = {
	.mipi_tx = lcd_kit_cmds_tx,
	.mipi_tx_no_lock = lcd_kit_cmds_tx_no_lock,
	.mipi_rx = lcd_kit_cmds_rx,
	.gpio_enable = lcd_kit_gpio_enable,
	.gpio_disable = lcd_kit_gpio_disable,
	.gpio_disable_plugin = lcd_kit_gpio_disable_plugin,
	.gpio_enable_nolock = lcd_kit_gpio_enable_nolock,
	.gpio_disable_nolock = lcd_kit_gpio_disable_nolock,
	.regulator_enable = lcd_kit_regulator_enable,
	.buf_trans = lcd_kit_buf_trans,
	.read_nv_info = lcd_kit_read_nv_info,
	.write_nv_info= lcd_kit_write_nv_info,
};

int lcd_kit_adapt_init(void)
{
	int ret;

	ret = lcd_kit_adapt_register(&adapt_ops);
	return ret;
}
