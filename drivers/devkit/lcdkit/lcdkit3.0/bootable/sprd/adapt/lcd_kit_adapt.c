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

#include "lcd_kit_adapt.h"
#include "lcd_kit_disp.h"
#include "lcd_kit_power.h"
#include "lcd_kit_common.h"
#include <libfdt.h>
#include <sprd_pin.h>
#include "dsi/mipi_dsi_api.h"

DECLARE_GLOBAL_DATA_PTR;
#define MAX_BUF_SIZE 20000
#define POWER_BUF_SIZE 3
#define LCD_ID_GPIO_HIGH 1
#define LCD_ID_GPIO_LOW 0
#define MTK_READ_MAX_LEN 10

struct dsi_cmd_common_desc {
        unsigned int dtype;
        unsigned int vc;
        unsigned int dlen;
        unsigned int link_state;
        char *payload;
};

static uint32_t lcd_id_cur_status[LCD_TYPE_NAME_MAX] = {0};
char lcd_type_buf[LCD_TYPE_NAME_MAX];

static struct lcd_type_info lcm_info_list[] = {
	{ LCDKIT, "LCDKIT" },
	{ LCD_KIT, "LCD_KIT" },
};

extern int  gpio_pin_set(unsigned int gpio_id, unsigned int ie_oe, unsigned int pull_down);

static int lcd_kit_get_data_by_property(const char *compatible,
	const char *propertyname, int **data, int *len)
{
	int offset;
	struct fdt_property *property = NULL;
	void *pfdt = NULL;

	if ((!compatible) || (!propertyname) || (!data) || (!len)) {
		LCD_KIT_ERR("domain_name, item_name or value is NULL!\n");
		return LCD_KIT_FAIL;
	}

	pfdt = gd->fdt_blob;
	if (!pfdt) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return LCD_KIT_FAIL;
	}

	offset = fdt_node_offset_by_compatible(pfdt, -1, compatible);
	if (offset < 0) {
		LCD_KIT_INFO("can not find %s node by compatible\n",
			compatible);
		return LCD_KIT_FAIL;
	}

	property = fdt_get_property(pfdt, offset, propertyname, len);
	if (!property) {
		LCD_KIT_INFO("can not find %s\n", propertyname);
		return LCD_KIT_FAIL;
	}

	if (!property->data)
		return LCD_KIT_FAIL;
	*data = (int *)property->data;
	return LCD_KIT_OK;
}

static int lcd_kit_get_dts_data_by_property(const void *pfdt, int offset,
		const char *propertyname, int **data, unsigned int *len)
{
	const struct fdt_property *property = NULL;

	if ((pfdt == NULL) || (propertyname == NULL) ||
		(data == NULL) || (len == NULL)) {
		LCD_KIT_ERR("input parameter is NULL!\n");
		return LCD_KIT_FAIL;
	}

	if (offset < 0) {
		LCD_KIT_INFO("can not find %s node\n", propertyname);
		return LCD_KIT_FAIL;
	}

	property = fdt_get_property(pfdt, offset, propertyname, (int *)len);
	if (property == NULL) {
		LCD_KIT_INFO("can not find %s\n", propertyname);
		return LCD_KIT_FAIL;
	}

	if (property->data == NULL)
		return LCD_KIT_FAIL;
	*data = property->data;
	return LCD_KIT_OK;
}

static int lcd_kit_get_dts_string_by_property(const void *pfdt, int offset,
	const char *propertyname, char *out_str, unsigned int length)
{
	struct fdt_property *property = NULL;
	int len = 0;

	if ((pfdt == NULL) || (propertyname == NULL) ||
		(out_str == NULL)) {
		LCD_KIT_ERR("input parameter is NULL!\n");
		return LCD_KIT_FAIL;
	}

	if (offset < 0) {
		LCD_KIT_INFO("can not find %s node\n", propertyname);
		return LCD_KIT_FAIL;
	}

	property = fdt_get_property(pfdt, offset, propertyname, &len);
	if (property == NULL) {
		LCD_KIT_INFO("can not find %s\n", propertyname);
		return LCD_KIT_FAIL;
	}
	if (property->data == NULL)
		return LCD_KIT_FAIL;
	length = (length >= (strlen((char *)property->data) + 1)) ?
		((strlen((char *)property->data)) + 1) : (length - 1);
	memcpy(out_str, (char *)property->data, length);
	return LCD_KIT_OK;
}

static int get_dts_property(const char *compatible, const char *propertyname,
	const uint32_t **data, int *length)
{
	int offset;
	int len;
	struct fdt_property *property = NULL;
	void *pfdt = NULL;

	if (!compatible || !propertyname || !data || !length) {
		LCD_KIT_ERR("domain_name, item_name or value is NULL!\n");
		return LCD_KIT_FAIL;
	}

	pfdt = gd->fdt_blob;
	if (!pfdt) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return LCD_KIT_FAIL;
	}

	offset = fdt_node_offset_by_compatible(pfdt, -1, compatible);
	if (offset < 0) {
		LCD_KIT_ERR("-----can not find %s node by compatible\n",
			compatible);
		return LCD_KIT_FAIL;
	}

	property = fdt_get_property(pfdt, offset, propertyname, &len);
	if (!property) {
		LCD_KIT_ERR("-----can not find %s\n", propertyname);
		return LCD_KIT_FAIL;
	}

	*data = property->data;
	*length = len;

	return LCD_KIT_OK;
}

int lcd_kit_get_detect_type(void)
{
	int type = 0;
	int ret;

	ret = lcd_kit_parse_get_u32_default(DTS_COMP_LCD_PANEL_TYPE,
		"detect_type", &type, 0);
	if (ret < 0)
		return LCD_KIT_FAIL;

	LCD_KIT_INFO("LCD panel detect type = %d\n", type);
	return type;
}

void lcd_kit_get_lcdname(void)
{
	int type = 0;
	int offset;
	int len;
	struct fdt_property *property = NULL;
	void *pfdt = NULL;

	pfdt = gd->fdt_blob;
	if (!pfdt) {
		LCD_KIT_ERR("pfdt is NULL!\n");
		return;
	}

	offset = fdt_node_offset_by_compatible(pfdt, -1,
		DTS_COMP_LCD_PANEL_TYPE);
	if (offset < 0) {
		LCD_KIT_ERR("-----can not find %s node by compatible\n",
			DTS_COMP_LCD_PANEL_TYPE);
		return;
	}

	property = fdt_get_property(pfdt, offset, "support_lcd_type", &len);
	if (!property) {
		LCD_KIT_ERR("-----can not find support_lcd_type\n");
		return;
	}

	memset(lcd_type_buf, 0, LCD_TYPE_NAME_MAX);
	memcpy(lcd_type_buf, (char *)property->data,
		(unsigned int)strlen((char *)property->data) + 1);
}

int lcd_kit_get_lcd_type(void)
{
	int i;
	int length = sizeof(lcm_info_list) / sizeof(struct lcd_type_info);

	for (i = 0; i < length; i++) {
		if (strncmp(lcd_type_buf, (char *)lcm_info_list[i].lcd_name,
			strlen((char *)(lcm_info_list[i].lcd_name))) == 0)
			return lcm_info_list[i].lcd_type;
	}
	return UNKNOWN_LCD;
}
void lcd_kit_set_lcd_name_to_no_lcd(void)
{
	int size = strlen("NO_LCD") + 1;

	memcpy(lcd_type_buf, "NO_LCD", size);
}

static int get_dts_u32_index(const char *compatible, const char *propertyname,
	uint32_t index, uint32_t *out_val)
{
	int ret;
	int len;
	const uint32_t *data = NULL;
	uint32_t ret_tmp;
	struct fdt_operators *fdt_ops = NULL;

	if ((!compatible) || (!propertyname) || (!out_val)) {
		LCD_KIT_ERR("domain_name, item_name or value is NULL!\n");
		return LCD_KIT_FAIL;
	}

	ret = get_dts_property(compatible, propertyname, &data, &len);
	if ((ret < 0) || (len < 0))
		return ret;

	if ((index * sizeof(uint32_t)) >= (uint32_t)len) {
		LCD_KIT_ERR("out of range!\n");
		return LCD_KIT_FAIL;
	}

	ret_tmp = *(data + index);
	ret_tmp = fdt32_to_cpu(ret_tmp);
	*out_val = ret_tmp;

	return LCD_KIT_OK;
}

uint32_t lcdkit_get_lcd_id(void)
{
	uint32_t lcdid_count;
	int ret;
	uint32_t i;
	uint32_t gpio_id = 0;
	uint32_t lcd_id_status = 0;
	uint32_t lcd_id_up;
	uint32_t lcd_id_down;
	const int lcd_nc_value = 2;
	uint32_t *dts_data_p = NULL;
	int dts_data_len = 0;
	uint32_t iovcc_ctrl_mode = 0;
	uint32_t ldo_gpio = 0;

	ret = get_dts_property(DTS_COMP_LCD_PANEL_TYPE, "gpio_id",
		(const uint32_t **)&dts_data_p, &dts_data_len);
	if (ret < 0) {
		LCD_KIT_ERR("get id failed or excess max supported id pins!\n");
		return LCD_KIT_FAIL;
	}

	/* 4 means u32 has 4 bits */
	lcdid_count = dts_data_len / 4;

	for (i = 0; i < lcdid_count; i++) {
		ret = get_dts_u32_index(DTS_COMP_LCD_PANEL_TYPE,
			"gpio_id", i, &gpio_id);
		sprd_gpio_request(NULL, gpio_id);
		gpio_pin_set(gpio_id, PIN_IE, PIN_UP_20K);
		mdelay(10);
		lcd_id_up = sprd_gpio_get(NULL, gpio_id);

		gpio_pin_set(gpio_id, PIN_IE, PIN_DOWN);
		mdelay(10);
		lcd_id_down = sprd_gpio_get(NULL, gpio_id);

		if (lcd_id_up == lcd_id_down) {
			if (lcd_id_up == LCD_ID_GPIO_LOW)
				lcd_id_cur_status[i] = LCD_ID_GPIO_LOW;
			else
				lcd_id_cur_status[i] = LCD_ID_GPIO_HIGH;
		} else {
			lcd_id_cur_status[i] = lcd_nc_value;
		}
		/* 2 means 2 mul i bits */
		lcd_id_status |= (lcd_id_cur_status[i] << (2 * i));
	}

	LCD_KIT_INFO("[uboot]:%s ,lcd_id_status=%d.\n",
		__func__, lcd_id_status);
	return lcd_id_status;
}

int lcd_kit_get_product_id(void)
{
	int ret;
	int product_id = 0;

	ret = lcd_kit_parse_get_u32_default(DTS_COMP_LCD_PANEL_TYPE,
		"product_id", &product_id, 0);
	if (ret < 0)
		/* 1000 is default product_id value */
		product_id = 1000;

	return product_id;
}

void lcdkit_set_lcd_panel_type(void *fdt, char *type)
{
	int ret;
	int offset;
	void *kernel_fdt = NULL;

	if (!type) {
		LCD_KIT_ERR("type is NULL!\n");
		return;
	}

	kernel_fdt = fdt;
	if (!kernel_fdt) {
		LCD_KIT_ERR("kernel_fdt is NULL!\n");
		return;
	}

	offset = fdt_path_offset(kernel_fdt, DTS_LCD_PANEL_TYPE);
	if (offset < 0) {
		LCD_KIT_ERR("Could not find panel node, change dts failed\n");
		return;
	}

	ret = fdt_setprop_string(kernel_fdt, offset, (const char *)"lcd_panel_type",
		(const void *)type);
	if (ret)
		LCD_KIT_ERR("Cannot update lcd panel type(errno=%d)!\n", ret);
}

void lcdkit_set_lcd_ddic_max_brightness(void *fdt, unsigned int bl_val)
{
	int ret;
	int offset;
	void *kernel_fdt = NULL;

	kernel_fdt = fdt;
	if (!kernel_fdt) {
		LCD_KIT_ERR("kernel_fdt is NULL!\n");
		return;
	}

	offset = fdt_path_offset(kernel_fdt, DTS_LCD_PANEL_TYPE);
	if (offset < 0) {
		LCD_KIT_ERR("Could not find honor,lcd_panel node\n");
		return;
	}

	ret = fdt_setprop_cell(kernel_fdt, offset,
		(const char *)"panel_ddic_max_brightness", bl_val);
	if (ret)
		LCD_KIT_ERR("Cannot update lcd max brightness(errno=%d)!\n",
			ret);
}

static int lcd_kit_cmds_to_sprd_dsi_cmds(
	struct lcd_kit_dsi_cmd_desc *lcd_kit_cmds,
	struct dsi_cmd_common_desc *cmd)
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
	cmd->dlen = lcd_kit_cmds->dlen;
	cmd->payload = lcd_kit_cmds->payload;
	cmd->link_state = MIPI_MODE_LP;

	return LCD_KIT_OK;
}

static int lcd_kit_cmds_to_sprd_dsi_read_cmds(
	struct lcd_kit_dsi_cmd_desc *lcd_kit_cmds,
	struct dsi_cmd_common_desc *cmd)
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
	cmd->dlen = lcd_kit_cmds->dlen;
	cmd->link_state = MIPI_MODE_LP;
	cmd->payload = lcd_kit_cmds->payload;

	return LCD_KIT_OK;
}

static int sprd_mipi_dsi_cmds_tx(void *dsi,
	struct lcd_kit_dsi_cmd_desc *cmds, int cnt)
{
	struct lcd_kit_dsi_cmd_desc *cm = cmds;
	struct dsi_cmd_common_desc dsi_cmd;
	struct sprd_dsi *pdsi = (struct sprd_dsi *)dsi;
	int i;
	int (*mipi_write)(struct sprd_dsi *dsi, u8 *param, u16 len) = NULL;

	if (cmds == NULL) {
		LCD_KIT_ERR("cmds is NULL");
		return LCD_KIT_FAIL;
	}
	if (pdsi == NULL) {
		LCD_KIT_ERR("dsi is NULL");
		return LCD_KIT_FAIL;
	}
	if (pdsi->panel != NULL) {
		if (pdsi->panel->dcs_write_en)
			mipi_write = mipi_dsi_dcs_write;
		else
			mipi_write = mipi_dsi_gen_write;
	}
	for (i = 0; i < cnt; i++) {
		lcd_kit_cmds_to_sprd_dsi_cmds(cm, &dsi_cmd);
		(void)mipi_write(dsi, dsi_cmd.payload, dsi_cmd.dlen);

		if (cm->wait) {
			if (cm->waittype == WAIT_TYPE_US)
				udelay(cm->wait);
			else if (cm->waittype == WAIT_TYPE_MS)
				mdelay(cm->wait);
			else
				/* 1000 means second */
				mdelay(cm->wait * 1000);
		}
		cm++;
	}
	return cnt;
}

static int sprd_mipi_dsi_cmds_rx(unsigned char *out, void *dsi,
	struct dsi_cmd_common_desc *cmd, unsigned char len)
{
	struct sprd_dsi *pdsi = (struct sprd_dsi *)dsi;
	int i;
	int (*mipi_write)(struct sprd_dsi *dsi, u8 *param, u16 len) = NULL;

	if (cmd == NULL || pdsi == NULL ||
		out == NULL || len == 0) {
		LCD_KIT_ERR("input is NULL");
		return 0;
	}

	mipi_dsi_set_max_return_size(pdsi, len);
	mipi_dsi_dcs_read(pdsi, cmd->payload[0], out, len);
	return len;
}


static int lcd_kit_cmd_is_write(struct lcd_kit_dsi_cmd_desc *cmd)
{
	int ret = LCD_KIT_FAIL;

	if (!cmd) {
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
		ret = LCD_KIT_OK;
		break;
	case DTYPE_GEN_READ:
	case DTYPE_GEN_READ1:
	case DTYPE_GEN_READ2:
	case DTYPE_DCS_READ:
		ret = LCD_KIT_FAIL;
		break;
	default:
		ret = LCD_KIT_FAIL;
		break;
	}
	return ret;
}

/*
 *  dsi send cmds
 */
int lcd_kit_dsi_cmds_tx(void *hld, struct lcd_kit_dsi_panel_cmds *cmds)
{
	int i;

	if (!hld) {
		LCD_KIT_ERR("hld is NULL!\n");
		return LCD_KIT_FAIL;
	}

	if (!cmds) {
		LCD_KIT_ERR("cmd is NULL!\n");
		return LCD_KIT_FAIL;
	}

	for (i = 0; i < cmds->cmd_cnt; i++)
		sprd_mipi_dsi_cmds_tx(hld, &cmds->cmds[i], 1);

	return LCD_KIT_OK;
}

/*
 *  dsi receive cmds
 */
int lcd_kit_dsi_cmds_rx(void *hld, uint8_t *out, int out_len,
	struct lcd_kit_dsi_panel_cmds *cmds)
{
	int i;
	int j;
	int k = 0;
	int ret;
	struct dsi_cmd_common_desc dsi_cmd = {0};
	unsigned char buffer[MTK_READ_MAX_LEN] = {0};

	if (!hld) {
		LCD_KIT_ERR("hld is NULL!\n");
		return LCD_KIT_FAIL;
	}

	if (!cmds || !out || out_len == 0) {
		LCD_KIT_ERR("cmds or out is NULL!\n");
		return LCD_KIT_FAIL;
	}

	for (i = 0; i < cmds->cmd_cnt; i++) {
		if (!lcd_kit_cmd_is_write(&cmds->cmds[i])) {
			ret = sprd_mipi_dsi_cmds_tx(hld, &cmds->cmds[i], 1);
			if (ret < 0) {
				LCD_KIT_ERR("mipi cmd tx failed!\n");
				return LCD_KIT_FAIL;
			}
		} else {
			lcd_kit_cmds_to_sprd_dsi_read_cmds(&cmds->cmds[i],
				&dsi_cmd);
			ret = sprd_mipi_dsi_cmds_rx(&buffer[0], hld, &dsi_cmd, dsi_cmd.dlen);
			if (ret == 0) {
				LCD_KIT_ERR("mipi cmd rx failed\n");
				return LCD_KIT_FAIL;
			}
			for (j = 0; j < dsi_cmd.dlen; j++) {
				out[k] = buffer[j];
				LCD_KIT_INFO("read the %d value is 0x%x\n", k, out[k]);
				k++;
				if (k == out_len) {
					LCD_KIT_INFO("buffer is full, out_len is %d\n", out_len);
					break;
				}
			}
		}
	}
	return LCD_KIT_OK;
}

static int lcd_kit_buf_trans(const char *inbuf, int inlen, char **outbuf,
	int *outlen)
{
	char *buf = NULL;
	int i;
	int bufsize = inlen;

	if (!inbuf || !outbuf || !outlen) {
		LCD_KIT_ERR("inbuf is null!\n");
		return LCD_KIT_FAIL;
	}
	if ((bufsize <= 0) || (bufsize > MAX_BUF_SIZE)) {
		LCD_KIT_ERR("bufsize <= 0 or > MAX_BUF_SIZE!\n");
		return LCD_KIT_FAIL;
	}
	/* The property is 4bytes long per element in cells: <> */
	bufsize = bufsize / 4;
	/* If use bype property: [], this division should be removed */
	buf = malloc(sizeof(char) * bufsize);
	if (!buf) {
		LCD_KIT_ERR("buf is null\n");
		return LCD_KIT_FAIL;
	}
	/* 4 means 4bytes 3 means the third element */
	for (i = 0; i < bufsize; i++)
		buf[i] = inbuf[i * 4 + 3];

	*outbuf = buf;
	*outlen = bufsize;
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_disable(u32 type)
{
	lcd_kit_gpio_tx(type, GPIO_LOW);
	lcd_kit_gpio_tx(type, GPIO_RELEASE);
	return LCD_KIT_OK;
}

static int lcd_kit_gpio_enable(u32 type)
{
	lcd_kit_gpio_tx(type, GPIO_REQ);
	lcd_kit_gpio_tx(type, GPIO_HIGH);
	return LCD_KIT_OK;
}

static int lcd_kit_regulator_disable(u32 type)
{
	int ret;

	switch (type) {
	case LCD_KIT_VCI:
	case LCD_KIT_IOVCC:
		ret = lcd_kit_pmu_ctrl(type, DISABLE);
		break;
	case LCD_KIT_VSP:
	case LCD_KIT_VSN:
	case LCD_KIT_BL:
		ret = lcd_kit_charger_ctrl(type, DISABLE);
		break;
	default:
		ret = LCD_KIT_FAIL;
		LCD_KIT_ERR("regulator type:%d not support!\n", type);
		break;
	}
	return ret;
}

static int lcd_kit_regulator_enable(u32 type)
{
	int ret;

	switch (type) {
	case LCD_KIT_VCI:
	case LCD_KIT_IOVCC:
	case LCD_KIT_VDD:
		ret = lcd_kit_pmu_ctrl(type, ENABLE);
		break;
	case LCD_KIT_VSP:
	case LCD_KIT_VSN:
	case LCD_KIT_BL:
		ret = lcd_kit_charger_ctrl(type, ENABLE);
		break;
	default:
		ret = LCD_KIT_FAIL;
		LCD_KIT_ERR("regulator type:%d not support!\n", type);
		break;
	}
	return ret;
}

struct lcd_kit_adapt_ops adapt_ops = {
	.mipi_tx = lcd_kit_dsi_cmds_tx,
	.mipi_rx = lcd_kit_dsi_cmds_rx,
	.gpio_enable = lcd_kit_gpio_enable,
	.gpio_disable = lcd_kit_gpio_disable,
	.regulator_enable = lcd_kit_regulator_enable,
	.regulator_disable = lcd_kit_regulator_disable,
	.buf_trans = lcd_kit_buf_trans,
	.get_data_by_property = lcd_kit_get_data_by_property,
	.get_dts_data_by_property = lcd_kit_get_dts_data_by_property,
	.get_dts_string_by_property = lcd_kit_get_dts_string_by_property,
};

int lcd_kit_adapt_init(void)
{
	int ret;

	ret = lcd_kit_adapt_register(&adapt_ops);
	return ret;
}
