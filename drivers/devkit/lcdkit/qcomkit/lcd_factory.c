/*
 * lcd_factory.c
 *
 * lcd factory test function for lcd driver
 *
 * Copyright (c) 2021-2022 Honor Technologies Co., Ltd.
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
#include <linux/kernel.h>
#include <linux/device.h>
#include "lcd_defs.h"
#include "lcd_panel.h"
#include "lcd_factory.h"
#include "sde/sde_connector.h"

/* pcd add detect number */
static uint32_t error_num_pcd;
#if IS_ENABLED(CONFIG_DSM)
extern struct dsm_client *lcd_dclient;
#endif

static char *g_sence_array[] = {
	"LCD_INCOME0",   "MMI0",   "RUNNINGTEST0", "PROJECT_MENU0",
	"LCD_INCOME1",   "MMI1",   "RUNNINGTEST1",  "PROJECT_MENU1",
	"LCD_INCOME2",   "MMI2",   "RUNNINGTEST2",  "PROJECT_MENU2",
	"LCD_INCOME3",   "MMI3",   "RUNNINGTEST3",  "PROJECT_MENU3",
	"LCD_INCOME4",   "MMI4",   "RUNNINGTEST4",  "PROJECT_MENU4",
	"LCD_INCOME5",   "MMI5",   "RUNNINGTEST5",  "PROJECT_MENU5",
	"LCD_INCOME6",   "MMI6",   "RUNNINGTEST6",  "PROJECT_MENU6",
	"LCD_INCOME7",   "MMI7",   "RUNNINGTEST7",  "PROJECT_MENU7",
	"LCD_INCOME8",   "MMI8",   "RUNNINGTEST8",  "PROJECT_MENU8",
	"LCD_INCOME9",   "MMI9",   "RUNNINGTEST9",  "PROJECT_MENU9",
	"LCD_INCOME10",  "MMI10",  "RUNNINGTEST10",  "PROJECT_MENU10",
	"LCD_INCOME11",  "MMI11",  "RUNNINGTEST11",  "PROJECT_MENU11",
	"LCD_INCOME12",  "MMI12",  "RUNNINGTEST12",  "PROJECT_MENU12",
	"LCD_INCOME13",  "MMI13",  "RUNNINGTEST13",  "PROJECT_MENU13",
	"LCD_INCOME14",  "MMI14",  "RUNNINGTEST14",  "PROJECT_MENU14",
	"LCD_INCOME15",  "MMI15",  "RUNNINGTEST15",  "PROJECT_MENU15",
	"LCD_INCOME16",  "MMI16",  "RUNNINGTEST16",  "PROJECT_MENU16",
	"LCD_INCOME17",  "MMI17",  "RUNNINGTEST17",  "PROJECT_MENU17",
	"LCD_INCOME18",  "MMI18",  "RUNNINGTEST18",  "PROJECT_MENU18",
	"LCD_INCOME19",  "MMI19",  "RUNNINGTEST19",  "PROJECT_MENU19",
	"LCD_INCOME20",  "MMI20",  "RUNNINGTEST20",  "PROJECT_MENU20",
	"LCD_INCOME21",  "MMI21",  "RUNNINGTEST21",  "PROJECT_MENU21",
	"LCD_INCOME22",  "MMI22",  "RUNNINGTEST22",  "PROJECT_MENU22",
	"LCD_INCOME23",  "MMI23",  "RUNNINGTEST23",  "PROJECT_MENU23",
	"LCD_INCOME24",  "MMI24",  "RUNNINGTEST24",  "PROJECT_MENU24",
	"LCD_INCOME25",  "MMI25",  "RUNNINGTEST25",  "PROJECT_MENU25",
	"LCD_INCOME26",  "MMI26",  "RUNNINGTEST26",  "PROJECT_MENU26",
	"LCD_INCOME27",  "MMI27",  "RUNNINGTEST27",  "PROJECT_MENU27",
	"LCD_INCOME28",  "MMI28",  "RUNNINGTEST28",  "PROJECT_MENU28",
	"LCD_INCOME29",  "MMI29",  "RUNNINGTEST29",  "PROJECT_MENU29",
	"LCD_INCOME30",  "MMI30",  "RUNNINGTEST30",  "PROJECT_MENU30",
	"LCD_INCOME31",  "MMI31",  "RUNNINGTEST31",  "PROJECT_MENU31",
	"LCD_INCOME32",  "MMI32",  "RUNNINGTEST32",  "PROJECT_MENU32",
	"CURRENT1_0",    "CURRENT1_1", "CURRENT1_2",  "CURRENT1_3",
	"CURRENT1_4",    "CURRENT1_5", "CHECKSUM1",  "CHECKSUM2",
	"CHECKSUM3",     "CHECKSUM4", "BL_OPEN_SHORT",  "PCD_ERRORFLAG",
	"DOTINVERSION",  "CHECKREG", "COLUMNINVERSION",   "POWERONOFF",
	"BLSWITCH", "CURRENT_TEST_MODE", "OVER_CURRENT_DETECTION",
	"OVER_VOLTAGE_DETECTION", "GENERAL_TEST", "VERTICAL_LINE",
	"DDIC_LV_DETECT", "AVDD_DETECT",
};

static char *g_cmd_array[] = {
	"CURRENT1_0",   "CURRENT1_0",  "CURRENT1_0",  "CURRENT1_0",
	"CURRENT1_1",   "CURRENT1_1",  "CURRENT1_1",  "CURRENT1_1",
	"CURRENT1_2",   "CURRENT1_2",  "CURRENT1_2",  "CURRENT1_2",
	"CURRENT1_3",   "CURRENT1_3",  "CURRENT1_3",  "CURRENT1_3",
	"CURRENT1_4",   "CURRENT1_4",  "CURRENT1_4",  "CURRENT1_4",
	"CURRENT1_5",   "CURRENT1_5",  "CURRENT1_5",  "CURRENT1_5",
	"CHECKSUM1",   "CHECKSUM1",   "CHECKSUM1", "CHECKSUM1",
	"CHECKSUM2",   "CHECKSUM2",   "CHECKSUM2", "CHECKSUM2",
	"CHECKSUM3",    "CHECKSUM3",   "CHECKSUM3", "CHECKSUM3",
	"CHECKSUM4",   "CHECKSUM4",   "CHECKSUM4", "CHECKSUM4",
	"BL_OPEN_SHORT",   "BL_OPEN_SHORT",   "BL_OPEN_SHORT", "BL_OPEN_SHORT",
	"PCD_ERRORFLAG",   "PCD_ERRORFLAG",  "PCD_ERRORFLAG", "PCD_ERRORFLAG",
	"DOTINVERSION",    "DOTINVERSION",  "DOTINVERSION", "DOTINVERSION",
	"CHECKREG",    "CHECKREG",  "CHECKREG", "CHECKREG",
	"COLUMNINVERSION", "COLUMNINVERSION", "COLUMNINVERSION", "COLUMNINVERSION",
	"POWERONOFF",   "POWERONOFF",  "POWERONOFF",  "POWERONOFF",
	"BLSWITCH",    "BLSWITCH",  "BLSWITCH", "BLSWITCH",
	"GPU_TEST",   "GPU_TEST",  "GPU_TEST", "GPU_TEST",
	"GENERAL_TEST", "GENERAL_TEST", "GENERAL_TEST", "GENERAL_TEST",
	"VERTICAL_LINE_1", "VERTICAL_LINE_1", "VERTICAL_LINE_1",
	"VERTICAL_LINE_1", "VERTICAL_LINE_2", "VERTICAL_LINE_2",
	"VERTICAL_LINE_2", "VERTICAL_LINE_2", "VERTICAL_LINE_3",
	"VERTICAL_LINE_3", "VERTICAL_LINE_3", "VERTICAL_LINE_3",
	"VERTICAL_LINE_4", "VERTICAL_LINE_4", "VERTICAL_LINE_4",
	"VERTICAL_LINE_4", "VERTICAL_LINE_5", "VERTICAL_LINE_5",
	"VERTICAL_LINE_5", "VERTICAL_LINE_5", "DDIC_LV_DET_CMD_1",
	"DDIC_LV_DET_CMD_1",    "DDIC_LV_DET_CMD_1",    "DDIC_LV_DET_CMD_1",
	"DDIC_LV_DET_RESULT_1", "DDIC_LV_DET_RESULT_1", "DDIC_LV_DET_RESULT_1",
	"DDIC_LV_DET_RESULT_1", "DDIC_LV_DET_CMD_2",    "DDIC_LV_DET_CMD_2",
	"DDIC_LV_DET_CMD_2",    "DDIC_LV_DET_CMD_2",    "DDIC_LV_DET_RESULT_2",
	"DDIC_LV_DET_RESULT_2", "DDIC_LV_DET_RESULT_2", "DDIC_LV_DET_RESULT_2",
	"DDIC_LV_DET_CMD_3",    "DDIC_LV_DET_CMD_3",    "DDIC_LV_DET_CMD_3",
	"DDIC_LV_DET_CMD_3",    "DDIC_LV_DET_RESULT_3", "DDIC_LV_DET_RESULT_3",
	"DDIC_LV_DET_RESULT_3", "DDIC_LV_DET_RESULT_3", "DDIC_LV_DET_CMD_4",
	"DDIC_LV_DET_CMD_4",    "DDIC_LV_DET_CMD_4",    "DDIC_LV_DET_CMD_4",
	"DDIC_LV_DET_RESULT_4", "DDIC_LV_DET_RESULT_4", "DDIC_LV_DET_RESULT_4",
	"DDIC_LV_DET_RESULT_4", "AVDD_DET_GET_RESULT", "AVDD_DET_GET_RESULT",
	"AVDD_DET_GET_RESULT", "AVDD_DET_GET_RESULT",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/graphics/fb0/lcd_checksum",
	"/sys/class/graphics/fb0/lcd_checksum",
	"/sys/class/graphics/fb0/lcd_checksum",
	"/sys/class/graphics/fb0/lcd_checksum",
	"/sys/class/graphics/fb0/bl_self_test",
	"/sys/class/graphics/fb0/amoled_pcd_errflag_check",
	"/sys/class/graphics/fb0/lcd_inversion_mode",
	"/sys/class/graphics/fb0/lcd_check_reg",
	"/sys/class/graphics/fb0/lcd_inversion_mode",
	"/sys/class/graphics/fb0/lcd_check_reg",
	"/sys/class/graphics/fb0/lcd_check_reg",
	"LCD_CUR_DET_MODE",
	"OVER_CURRENT_DETECTION",
	"OVER_VOLTAGE_DETECTION",
	"/sys/class/graphics/fb0/lcd_general_test",
	"/sys/class/graphics/fb0/vertical_line_test",
	"/sys/class/graphics/fb0/ddic_lv_detect",
	"/sys/class/graphics/fb0/avdd_detect",
};

static char *g_cmd_array_fb1[] = {
	"CURRENT1_0",   "CURRENT1_0",  "CURRENT1_0",  "CURRENT1_0",
	"CURRENT1_1",   "CURRENT1_1",  "CURRENT1_1",  "CURRENT1_1",
	"CURRENT1_2",   "CURRENT1_2",  "CURRENT1_2",  "CURRENT1_2",
	"CURRENT1_3",   "CURRENT1_3",  "CURRENT1_3",  "CURRENT1_3",
	"CURRENT1_4",   "CURRENT1_4",  "CURRENT1_4",  "CURRENT1_4",
	"CURRENT1_5",   "CURRENT1_5",  "CURRENT1_5",  "CURRENT1_5",
	"CHECKSUM1",   "CHECKSUM1",   "CHECKSUM1", "CHECKSUM1",
	"CHECKSUM2",   "CHECKSUM2",   "CHECKSUM2", "CHECKSUM2",
	"CHECKSUM3",    "CHECKSUM3",   "CHECKSUM3", "CHECKSUM3",
	"CHECKSUM4",   "CHECKSUM4",   "CHECKSUM4", "CHECKSUM4",
	"BL_OPEN_SHORT",   "BL_OPEN_SHORT",   "BL_OPEN_SHORT", "BL_OPEN_SHORT",
	"PCD_ERRORFLAG",   "PCD_ERRORFLAG",  "PCD_ERRORFLAG", "PCD_ERRORFLAG",
	"DOTINVERSION",    "DOTINVERSION",  "DOTINVERSION", "DOTINVERSION",
	"CHECKREG",    "CHECKREG",  "CHECKREG", "CHECKREG",
	"COLUMNINVERSION", "COLUMNINVERSION", "COLUMNINVERSION", "COLUMNINVERSION",
	"POWERONOFF",   "POWERONOFF",  "POWERONOFF",  "POWERONOFF",
	"BLSWITCH",    "BLSWITCH",  "BLSWITCH", "BLSWITCH",
	"GPU_TEST",   "GPU_TEST",  "GPU_TEST", "GPU_TEST",
	"GENERAL_TEST", "GENERAL_TEST", "GENERAL_TEST", "GENERAL_TEST",
	"VERTICAL_LINE_1", "VERTICAL_LINE_1", "VERTICAL_LINE_1",
	"VERTICAL_LINE_1", "VERTICAL_LINE_2", "VERTICAL_LINE_2",
	"VERTICAL_LINE_2", "VERTICAL_LINE_2", "VERTICAL_LINE_3",
	"VERTICAL_LINE_3", "VERTICAL_LINE_3", "VERTICAL_LINE_3",
	"VERTICAL_LINE_4", "VERTICAL_LINE_4", "VERTICAL_LINE_4",
	"VERTICAL_LINE_4", "VERTICAL_LINE_5", "VERTICAL_LINE_5",
	"VERTICAL_LINE_5", "VERTICAL_LINE_5", "DDIC_LV_DET_CMD_1",
	"DDIC_LV_DET_CMD_1",    "DDIC_LV_DET_CMD_1",    "DDIC_LV_DET_CMD_1",
	"DDIC_LV_DET_RESULT_1", "DDIC_LV_DET_RESULT_1", "DDIC_LV_DET_RESULT_1",
	"DDIC_LV_DET_RESULT_1", "DDIC_LV_DET_CMD_2",    "DDIC_LV_DET_CMD_2",
	"DDIC_LV_DET_CMD_2",    "DDIC_LV_DET_CMD_2",    "DDIC_LV_DET_RESULT_2",
	"DDIC_LV_DET_RESULT_2", "DDIC_LV_DET_RESULT_2", "DDIC_LV_DET_RESULT_2",
	"DDIC_LV_DET_CMD_3",    "DDIC_LV_DET_CMD_3",    "DDIC_LV_DET_CMD_3",
	"DDIC_LV_DET_CMD_3",    "DDIC_LV_DET_RESULT_3", "DDIC_LV_DET_RESULT_3",
	"DDIC_LV_DET_RESULT_3", "DDIC_LV_DET_RESULT_3", "DDIC_LV_DET_CMD_4",
	"DDIC_LV_DET_CMD_4",    "DDIC_LV_DET_CMD_4",    "DDIC_LV_DET_CMD_4",
	"DDIC_LV_DET_RESULT_4", "DDIC_LV_DET_RESULT_4", "DDIC_LV_DET_RESULT_4",
	"DDIC_LV_DET_RESULT_4", "AVDD_DET_GET_RESULT", "AVDD_DET_GET_RESULT",
	"AVDD_DET_GET_RESULT", "AVDD_DET_GET_RESULT",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/ina231/ina231_0/ina231_set," \
	"/sys/class/ina231/ina231_0/ina231_value," \
	"1,9999999,1,9999999,1,99999",
	"/sys/class/graphics/fb1/lcd_checksum",
	"/sys/class/graphics/fb1/lcd_checksum",
	"/sys/class/graphics/fb1/lcd_checksum",
	"/sys/class/graphics/fb1/lcd_checksum",
	"/sys/class/graphics/fb1/bl_self_test",
	"/sys/class/graphics/fb1/amoled_pcd_errflag_check",
	"/sys/class/graphics/fb1/lcd_inversion_mode",
	"/sys/class/graphics/fb1/lcd_check_reg",
	"/sys/class/graphics/fb1/lcd_inversion_mode",
	"/sys/class/graphics/fb1/lcd_check_reg",
	"/sys/class/graphics/fb1/lcd_check_reg",
	"LCD_CUR_DET_MODE",
	"OVER_CURRENT_DETECTION",
	"OVER_VOLTAGE_DETECTION",
	"/sys/class/graphics/fb1/lcd_general_test",
	"/sys/class/graphics/fb1/vertical_line_test",
	"/sys/class/graphics/fb1/ddic_lv_detect",
	"/sys/class/graphics/fb1/avdd_detect",
};


static void lcd_set_esd_pending(struct panel_info *pinfo, int value)
{
	atomic_set(&pinfo->lcd_esd_pending, value);
}

static int lcd_checksum_compare(uint8_t *read_value, uint32_t *value, int len)
{
	int i;
	int err_no = 0;
	uint8_t tmp;

	for (i = 0; i < len; i++) {
		tmp = (uint8_t)value[i];
		LCD_ERR("gram checksum, read_value[%d]:0x%x\n", i, read_value[i]);
		if (read_value[i] != tmp) {
			LCD_ERR("gram check error, read_value[%d]:0x%x, expect_value[%d]:0x%x\n",
				i, read_value[i], i, tmp);
			err_no++;
		}
	}
	return err_no;
}

static int lcd_check_checksum(struct panel_info *pinfo)
{
	int ret;
	int err_cnt;
	int check_cnt;
	uint8_t read_value[LCD_KIT_CHECKSUM_SIZE + 1] = {0};
	uint32_t *src_value = NULL;
	struct lcd_checksum *checksum = &pinfo->fact_info->checksum;
	int offset;

	if (checksum->value.buf == NULL) {
		LCD_ERR("value buf is NULL\n");
		return -EINVAL;
	}

	offset = checksum->pic_index * LCD_KIT_CHECKSUM_SIZE;
	msleep(100);
	ret = dsi_panel_receive_data(pinfo->panel, DSI_CMD_SET_CHECKSUM,
		read_value, LCD_KIT_CHECKSUM_SIZE);
	if (ret) {
		LCD_ERR("checksum read dsi error\n");
		return -EINVAL;
	}

	check_cnt = checksum->value.cnt - offset >= LCD_KIT_CHECKSUM_SIZE ?
		LCD_KIT_CHECKSUM_SIZE : checksum->value.cnt - offset;

	src_value = checksum->value.buf + offset;
	err_cnt = lcd_checksum_compare(read_value, src_value, check_cnt);
	if (err_cnt) {
		LCD_ERR("err_cnt:%d\n", err_cnt);
		ret = -EINVAL;
	}
	return ret;
}

static int lcd_checksum_check(struct panel_info *pinfo)
{
	uint32_t pic_index;
	int ret;
	struct lcd_checksum *checksum = &pinfo->fact_info->checksum;
	struct dsi_panel *panel = pinfo->panel;
	pic_index = checksum->pic_index;
	LCD_INFO("checksum pic num:%d\n", pic_index);
	if (pic_index > TEST_PIC_2) {
		LCD_ERR("checksum pic num unknown:%d\n", pic_index);
		return -EINVAL;
	}

	ret = lcd_check_checksum(pinfo);
	if (ret)
		LCD_ERR("lcd checksum error\n");

	if (ret && pic_index == TEST_PIC_2)
		checksum->status = LCD_KIT_CHECKSUM_END;

	if (checksum->status == LCD_KIT_CHECKSUM_END) {
		LCD_INFO("gram checksum end, disable checksum\n");
		mutex_lock(&panel->panel_lock);
		if (dsi_panel_set_cmd(pinfo->panel, DSI_CMD_SET_CHECKSUM_DISABLE))
			LCD_ERR("send checksum disable fail!\n");
		else
			LCD_INFO("send checksum disable ok\n");
		lcd_set_esd_pending(pinfo, LCD_ESD_ENABLE);
		mutex_unlock(&panel->panel_lock);
	}

	return ret;
}

static int lcd_kit_checksum_set(struct panel_info *pinfo, int pic_index)
{
	int ret = 0;
	struct lcd_checksum *checksum = &pinfo->fact_info->checksum;
	struct dsi_panel *panel = pinfo->panel;
	if (checksum->status == LCD_KIT_CHECKSUM_END) {
		if (pic_index == TEST_PIC_0) {
			LCD_INFO("start gram checksum\n");
			lcd_set_esd_pending(pinfo, LCD_ESD_DISABLE);
			checksum->status = LCD_KIT_CHECKSUM_START;
			mutex_lock(&panel->panel_lock);
			ret = dsi_panel_set_cmd(pinfo->panel,
				DSI_CMD_SET_CHECKSUM_ENABLE);
			mutex_unlock(&panel->panel_lock);
			if (ret)
				LCD_ERR("send checksum enable fail!\n");
			else
				LCD_INFO("send checksum enable ok\n");
			checksum->pic_index = INVALID_INDEX;
			return ret;
		}
		LCD_ERR("set pic index error\n");
		return -EINVAL;
	}
	if (pic_index == TEST_PIC_2)
		checksum->check_count++;
	if (checksum->check_count == CHECKSUM_CHECKCOUNT) {
		LCD_INFO("check 5 times, set checksum end\n");
		checksum->status = LCD_KIT_CHECKSUM_END;
		checksum->check_count = 0;
	}
	switch (pic_index) {
	case TEST_PIC_0:
	case TEST_PIC_1:
	case TEST_PIC_2:
		LCD_INFO("set pic [%d]\n", pic_index);
		checksum->pic_index = pic_index;
		break;
	default:
		LCD_ERR("set pic [%d] unknown\n", pic_index);
		checksum->pic_index = INVALID_INDEX;
		break;
	}
	return ret;
}

struct lcd_fact_info *get_fact_info(int idx)
{
	struct lcd_fact_info *fact_info = NULL;
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(idx);
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return NULL;
	}
	fact_info = pinfo->fact_info;
	return fact_info;
}

static int lcd_current_det(struct lcd_fact_info *fact_info)
{
	int current_check_result = 0;

	return current_check_result;
}

static int lcd_lv_det(struct lcd_fact_info *fact_info)
{
	int lv_check_result = 0;

	return lv_check_result;
}

static ssize_t lcd_inversion_mode_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	lcd_inversion_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t lcd_scan_mode_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	return ret;
}

static ssize_t	lcd_scan_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t lcd_check_reg_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int i;
	ssize_t ret = LCD_OK;
	uint8_t *exp_val = NULL;
	uint8_t read_value[MAX_REG_READ_COUNT] = {0};
	struct panel_info *pinfo = get_panel_info(get_fb_index(dev));

	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	msleep(500);
	if (pinfo->panel_state != LCD_HS_ON) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	if (!pinfo->fact_info->checkreg.enabled) {
		LCD_INFO("not support check reg\n");
		return ret;
	}

	exp_val = pinfo->fact_info->checkreg.expect_val;
	dsi_panel_receive_data(pinfo->panel,
			DSI_CMD_GET_CHECK_REG, read_value, MAX_REG_READ_COUNT - 1);
	for (i = 0; i < pinfo->fact_info->checkreg.expect_count; i++) {
		if (read_value[i] != exp_val[i]) {
			ret = LCD_FAIL;
			LCD_ERR("read_value[%u] = 0x%x, but expect_ptr[%u] = 0x%x!\n",
					i, read_value[i], i, exp_val[i]);
			break;
		}
		LCD_INFO("read_value[%u] = 0x%x same with expect value!\n",
				i, read_value[i]);
	}

	if (!ret)
		ret = snprintf(buf, PAGE_SIZE, "OK");
	else
		ret = snprintf(buf, PAGE_SIZE, "FAIL");
	LCD_INFO("checkreg result:%s\n", buf);
	return ret;
}

static ssize_t lcd_gram_check_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	int checksum_result = 0;
	struct panel_info *pinfo = NULL;

	ret = snprintf(buf, PAGE_SIZE, "%d\n", checksum_result);
	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	if (!pinfo->panel_state) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	if(pinfo->fact_info->checksum.support) {
		checksum_result = lcd_checksum_check(pinfo);
		ret = snprintf(buf, PAGE_SIZE, "%d\n", checksum_result);
	}

	return ret;
}

static ssize_t	lcd_gram_check_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	ssize_t ret = 0;
	ssize_t index;
	unsigned long val = 0;
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	if (!pinfo->panel_state) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	ret = kstrtoul(buf, 10, &val);
	if (ret) {
		LCD_ERR("kstrtoul error!\n");
		return ret;
	}
	LCD_INFO("val = %ld\n", val);

	if (pinfo->fact_info->checksum.support) {
		index = val - INDEX_START;
		ret = lcd_kit_checksum_set(pinfo, index);
	}
	return count;
}

static ssize_t lcd_sleep_ctrl_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}
	ret = snprintf(buf, PAGE_SIZE, "PT test mod = %d\n", pinfo->fact_info->pt_flag);
	return ret;
}

static ssize_t	lcd_sleep_ctrl_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned long val = 0;
	struct panel_info *pinfo = NULL;

	if (buf == NULL) {
		LCD_ERR("buf is null\n");
		return -EINVAL;
	}
	val = simple_strtoul(buf, NULL, 0);
	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}
	pinfo->fact_info->pt_flag = val;
	return count;
}

static int lcd_panel_reset(struct dsi_panel *panel)
{
	int rc = LCD_OK;
	struct dsi_panel_reset_config *r_config = &panel->reset_config;

	if (!r_config->count) {
		LCD_INFO("count = 0\n");
		return rc;
	}

	rc = gpio_direction_output(r_config->reset_gpio, 1);
	if (rc) {
		DSI_ERR("unable to set dir for rst gpio rc=%d\n", rc);
		return rc;
	}

	gpio_set_value(r_config->reset_gpio, 0);
	usleep_range(LCD_RST_DOWN_TIME * 1000, LCD_RST_DOWN_TIME * 1000 + 100);
	gpio_set_value(r_config->reset_gpio, 1);

	return rc;
}

static void lcd_panel_recovery(struct panel_info *pinfo)
{
	atomic_set(&pinfo->lcd_noti_comp, 1);
	lcd_sde_panel_recovery(pinfo->sde_connector, false);
	wait_for_completion(&pinfo->lcd_test_comp);
	atomic_set(&pinfo->lcd_noti_comp, 0);
}

static int lcd_hor_line_test(struct panel_info *pinfo)
{
	int ret = LCD_OK;
	int count = HOR_LINE_TEST_TIMES;
	struct dsi_panel *panel = pinfo->panel;

	if (!pinfo->sde_connector) {
		LCD_ERR("sde_connector is NULL\n");
		return ret;
	}

	LCD_INFO("horizontal line test start\n");
	LCD_INFO("g_fact_info.hor_line.duration = %d\n",
		pinfo->fact_info->hor_line_test.hor_duration);

	while (count--) {
		mdelay(10000);
		ret = lcd_panel_reset(pinfo->panel);
		if (ret) {
			LCD_ERR("lcd_panel_reset fail\n");
			return ret;
		}

		mdelay(3);
		mutex_lock(&panel->panel_lock);
		ret = dsi_panel_set_cmd(pinfo->panel, DSI_CMD_HOR_LINE_REG);
		if (ret){
			mutex_unlock(&panel->panel_lock);
			LCD_ERR("[%s] failed to send  DSI_CMD_HOR_LINE_REG cmds, rc=%d\n",
				pinfo->panel->name, ret);
			return ret;
		}
		mutex_unlock(&panel->panel_lock);

		msleep(pinfo->fact_info->hor_line_test.hor_duration * MILLISEC_TIME);
		lcd_panel_recovery(pinfo);
	}

	LCD_INFO("horizontal line test end\n");
	return ret;
}

static int lcd_vtc_line_test(unsigned long pic_index, struct panel_info *pinfo)
{
	int ret = LCD_OK;
	struct dsi_panel *panel = pinfo->panel;

	if (!pinfo->sde_connector) {
		LCD_ERR("sde_connector is NULL\n");
		return ret;
	}

	switch (pic_index) {
	case PIC1_INDEX:
		if (!pinfo->fact_info->vtc_line_test.vtc_no_reset) {
			ret = lcd_panel_reset(pinfo->panel);
			if (ret) {
				LCD_ERR("[%s] failed to reset panel, rc=%d\n",
						pinfo->panel->name, ret);
				return ret;
			}
		}

		mdelay(3);
		mutex_unlock(&panel->panel_lock);
		ret = dsi_panel_set_cmd(pinfo->panel, DSI_CMD_VTC_LINE_REG);
		if (ret){
			mutex_unlock(&panel->panel_lock);
			LCD_ERR("[%s] failed to send  DSI_CMD_VTC_LINE_REG cmds, rc=%d\n",
					pinfo->panel->name, ret);
			return ret;
		}
		mutex_unlock(&panel->panel_lock);

		break;
	case PIC2_INDEX:
	case PIC3_INDEX:
	case PIC4_INDEX:
		LCD_INFO("picture:%lu display\n", pic_index);
		break;
	case PIC5_INDEX:
		lcd_sde_panel_recovery(pinfo->sde_connector, false);
		break;
	default:
		LCD_ERR("pic number not support\n");
		break;
	}

	return ret;
}

static int lcd_kit_open_pcd_check(struct panel_info *pinfo)
{
	int ret = LCD_OK;
	if (!pinfo->panel) {
		LCD_ERR("pinfo_panel is null\n");
		return -EINVAL;
	}

	ret = dsi_panel_set_cmd(pinfo->panel, DSI_CMD_PCD_CHECK_OPEN);

	if (ret)
		LCD_ERR("send PCD open cmds error\n");
	else
		LCD_INFO("pcd open cmd tx successfully\n");
	return ret;
}

static int lcd_kit_close_pcd_check(struct panel_info *pinfo)
{
	int ret = LCD_OK;
	if (!pinfo->panel) {
		LCD_ERR("pinfo_panel is null\n");
		return -EINVAL;
	}

	ret = dsi_panel_set_cmd(pinfo->panel, DSI_CMD_PCD_CHECK_CLOSE);

	if (ret)
		LCD_ERR("send PCD close cmds error\n");
	else
		LCD_INFO("pcd close cmd tx successfully\n");
	return ret;
}

static int lcd_kit_judge_pcd_dmd(struct panel_info *pinfo, uint8_t read_val,
	uint32_t expect_val, uint32_t compare_mode)
{
	uint32_t exp_pcd_value_mask = pinfo->fact_info->pcd_errflag_check.exp_pcd_mask;;

	LCD_INFO("Pcd cmp mode = %d\n", compare_mode);
	LCD_INFO("PCD exp_pcd_value_mask = %d\n", exp_pcd_value_mask);
	LCD_INFO("PCD read_val= %d, expect_val=%d \n",read_val,expect_val);

	if (compare_mode == PCD_COMPARE_MODE_EQUAL) {
		if ((uint32_t)read_val != expect_val)
			return LCD_FAIL;
	} else if (compare_mode == PCD_COMPARE_MODE_BIGGER) {
		if ((uint32_t)read_val < expect_val)
			return LCD_FAIL;
	} else if (compare_mode == PCD_COMPARE_MODE_MASK) {
		if (((uint32_t)read_val & exp_pcd_value_mask) == expect_val)
			return LCD_FAIL;
	}
	return LCD_OK;
}

#define PCD_READ_LEN 3
static void lcd_kit_pcd_dmd_report(struct panel_info *pinfo, uint8_t *pcd_read_val, uint32_t val_len)
{
	int ret = 0;
	int8_t record_buf[DMD_RECORD_BUF_LEN * MAX_REG_READ_COUNT] = {'\0'};

	if (val_len < PCD_READ_LEN) {
		LCD_ERR("val len err\n");
		return;
	}
	if (!pcd_read_val) {
		LCD_ERR("pcd_read_val is NULL\n");
		return;
	}
	ret = snprintf(record_buf, DMD_ERR_INFO_LEN,
		"Panel%d PCD REG Value is 0x%x 0x%x 0x%x\n",
		pinfo->panel_id, pcd_read_val[0], pcd_read_val[1], pcd_read_val[2]);
	if (ret < 0) {
		LCD_ERR("snprintf error\n");
		return;
	}
#if IS_ENABLED(CONFIG_DSM)
	(void)lcd_dsm_client_record(lcd_dclient, record_buf,
		DSM_LCD_PANEL_CRACK_ERROR_NO);
#endif
}

static void pcd_err_record(struct panel_info *pinfo, uint8_t *result, uint8_t *pcd_read_val)
{
	error_num_pcd++;
	LCD_INFO("enter pcd_err_record, pcd_error_num = %d\n", error_num_pcd);
	if (error_num_pcd >= pinfo->fact_info->pcd_errflag_check.pcd_det_num) {
		LCD_INFO("pcd_error_num = %d\n", error_num_pcd);
		lcd_kit_pcd_dmd_report(pinfo, pcd_read_val, LCD_KIT_PCD_SIZE);
		*result |= PCD_FAIL;
		error_num_pcd = 0;
	}
}

static int lcd_kit_check_pcd_check(struct panel_info *pinfo)
{
	uint8_t result = PCD_ERRFLAG_SUCCESS;
	int ret = 0;
	uint8_t read_pcd[4] = {0};
	uint32_t expect_value = 0;

	if (!pinfo->panel) {
		LCD_ERR("pinfo_panel is null\n");
		return -EINVAL;
	}

	ret = dsi_panel_receive_data_nolock(pinfo->panel, DSI_CMD_PCD_CHECK_REG,
			read_pcd, 3);
	if (ret) {
		LCD_ERR("mipi_rx fail\n");
		return ret;
	}

	expect_value = pinfo->fact_info->pcd_errflag_check.pcd_value;
	if (ret == LCD_OK) {
		if (lcd_kit_judge_pcd_dmd(pinfo, read_pcd[0], expect_value,
			pinfo->fact_info->pcd_errflag_check.pcd_value_compare_mode) == LCD_OK) {
			pcd_err_record(pinfo, &result, read_pcd);
		} else {
			LCD_INFO("pcd_error_num = %d\n", error_num_pcd);
			error_num_pcd = 0;
		}
	} else {
		LCD_ERR("read pcd err\n");
	}

	LCD_INFO("pcd REG read result is 0x%x 0x%x 0x%x\n",
			read_pcd[0], read_pcd[1], read_pcd[2]);
	LCD_INFO("pcd check result is %d\n", result);

	return (int)result;
}

static ssize_t lcd_amoled_pcd_errflag_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = LCD_OK;
	int check_result = 0;
	struct panel_info *pinfo = get_panel_info(get_fb_index(dev));
	struct dsi_panel *panel = pinfo->panel;


	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	if (!pinfo->panel_state) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	if (!pinfo->fact_info->pcd_errflag_check.pcd_support) {
		LCD_INFO("not support PCD detect\n");
		return ret;
	}

	mutex_lock(&panel->panel_lock);
	if(!panel->pdata->pinfo->power_on) {
		mutex_unlock(&panel->panel_lock);
		LCD_WARN("not power on!\n");
		return ret;
	}

	lcd_set_esd_pending(pinfo,LCD_ESD_DISABLE);
	LCD_INFO("Pcd open\n");
	lcd_kit_open_pcd_check(pinfo);
	LCD_INFO("Pcd check\n");
	check_result = lcd_kit_check_pcd_check(pinfo);
	LCD_INFO("Pcd close\n");
	lcd_kit_close_pcd_check(pinfo);
	lcd_set_esd_pending(pinfo,LCD_ESD_ENABLE);

	ret = snprintf(buf, PAGE_SIZE, "%d\n", check_result);
	LCD_INFO("pcd_errflag, the check_result = %d\n", check_result);

	 mutex_unlock(&panel->panel_lock);
	return ret;
}

static ssize_t	lcd_amoled_pcd_errflag_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret = LCD_OK;
	struct panel_info *pinfo = get_panel_info(get_fb_index(dev));

	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	if (!pinfo->panel_state) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	if (!pinfo->fact_info->pcd_errflag_check.pcd_support) {
		LCD_INFO("not support PCD detect\n");
		return ret;
	}

	return count;
}

static ssize_t lcd_test_config_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int i;
	int ret;
	struct lcd_fact_info *fact_info = NULL;

	fact_info = get_fact_info(PRIMARY_PANEL);
	if (!fact_info) {
		LCD_ERR("fact_info is null\n");
		return -EINVAL;
	}
	for (i = 0; i < (int)ARRAY_SIZE(g_sence_array); i++) {
		if (g_sence_array[i] == NULL) {
			ret = -EINVAL;
			LCD_INFO("Sence cmd is end, total num is:%d\n", i);
			break;
		}
		if (!strncmp(fact_info->lcd_cmd_now, g_sence_array[i],
			strlen(fact_info->lcd_cmd_now))) {
			if (get_active_panel() == PRIMARY_PANEL) {
				LCD_INFO("panel0: current test cmd:%s,return cmd:%s\n",
					fact_info->lcd_cmd_now, g_cmd_array[i]);
				ret = snprintf(buf, PAGE_SIZE, g_cmd_array[i]);
			} else if (get_active_panel() == SECONDARY_PANEL) {
				LCD_INFO("panel1: current test cmd:%s,return cmd:%s\n",
					fact_info->lcd_cmd_now, g_cmd_array_fb1[i]);
				ret = snprintf(buf, PAGE_SIZE, g_cmd_array_fb1[i]);
			} else {
				LCD_ERR("panel status error:%d\n", get_active_panel());
				return -EINVAL;
			}
		}
	}
	/* current and voltage test */
	if (buf) {
		if (!strncmp(buf, "OVER_CURRENT_DETECTION",
			strlen("OVER_CURRENT_DETECTION"))) {
			ret = lcd_current_det(fact_info);
			return snprintf(buf, PAGE_SIZE, "%d", ret);
		}
		if (!strncmp(buf, "OVER_VOLTAGE_DETECTION",
			strlen("OVER_VOLTAGE_DETECTION"))) {
			ret = lcd_lv_det(fact_info);
			return snprintf(buf, PAGE_SIZE, "%d", ret);
		}
	}
	return ret;
}

static ssize_t	lcd_test_config_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct lcd_fact_info *fact_info = NULL;

	fact_info = get_fact_info(PRIMARY_PANEL);
	if (!fact_info) {
		LCD_ERR("fact_info is null\n");
		return -EINVAL;
	}

	memset(fact_info->lcd_cmd_now, 0, LCD_CMD_NAME_MAX);
	if (strlen(buf) < LCD_CMD_NAME_MAX) {
		memcpy(fact_info->lcd_cmd_now, buf, strlen(buf) + 1);
		LCD_INFO("current test cmd:%s\n", fact_info->lcd_cmd_now);
	} else {
		memcpy(fact_info->lcd_cmd_now, "INVALID", strlen("INVALID") + 1);
		LCD_ERR("invalid test cmd:%s\n", fact_info->lcd_cmd_now);
	}
	return count;
}

static ssize_t lcd_lv_detect_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	ret = snprintf(buf, PAGE_SIZE, "%d", ret);
	return ret;
}

static ssize_t lcd_current_detect_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	ret = snprintf(buf, PAGE_SIZE, "%d", ret);
	return ret;
}

static ssize_t lcd_general_test_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = LCD_OK;
	struct panel_info *pinfo = get_panel_info(get_fb_index(dev));

	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	if (!pinfo->panel_state) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	if (!pinfo->fact_info->hor_line_test.hor_support) {
		LCD_INFO("not support hor line test\n");
		return ret;
	}

	lcd_set_esd_pending(pinfo, LCD_ESD_DISABLE);
	ret = lcd_hor_line_test(pinfo);
	if (!ret)
		ret = snprintf(buf, PAGE_SIZE, "OK\n");
	else
		ret = snprintf(buf, PAGE_SIZE, "FAIL\n");
	lcd_set_esd_pending(pinfo, LCD_ESD_ENABLE);

	return ret;
}

static ssize_t lcd_vertical_line_test_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int ret = LCD_OK;
	struct panel_info *pinfo = get_panel_info(get_fb_index(dev));

	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	if (!pinfo->panel_state) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	if (!pinfo->fact_info->vtc_line_test.vtc_support) {
		LCD_INFO("not support vtc line check\n");
		return ret;
	}

	return snprintf(buf, PAGE_SIZE, "OK\n");;
}

static ssize_t lcd_vertical_line_test_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret = LCD_OK;
	unsigned long index = 0;
	struct panel_info *pinfo = get_panel_info(get_fb_index(dev));

	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	if (!pinfo->panel_state) {
		LCD_ERR("panel is power off!\n");
		return ret;
	}

	if (!pinfo->fact_info->vtc_line_test.vtc_support) {
		LCD_INFO("not support vtc line check\n");
		return ret;
	}

	ret = kstrtoul(buf, 10, &index);
	if (ret) {
		LCD_ERR("strict_strtoul fail!\n");
		return ret;
	}

	lcd_set_esd_pending(pinfo, LCD_ESD_DISABLE);
	ret = lcd_vtc_line_test(index, pinfo);
	if (ret)
		LCD_INFO("lcd vtc line test fail\n");
	lcd_set_esd_pending(pinfo, LCD_ESD_ENABLE);

	return count;
}

static ssize_t lcd_oneside_mode_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	if (!ret)
		ret = snprintf(buf, PAGE_SIZE, "OK\n");
	return ret;
}

static ssize_t	lcd_oneside_mode_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static ssize_t lcd_avdd_detect_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	ssize_t ret = 0;

	if (!ret)
		ret = snprintf(buf, PAGE_SIZE, "%d\n", 0);
	return ret;
}

void lcd_kit_ddic_lv_detect_dmd_report(
	u8 reg_val[DETECT_LOOPS][DETECT_NUM][VAL_NUM])
{
	int i;
	int ret;
	unsigned int len;
	char err_info[DMD_DET_ERR_LEN] = {0};

	if (!reg_val) {
		LCD_ERR("reg_val is null\n");
		return;
	}
	for (i = 0; i < DETECT_LOOPS; i++) {
		len = strlen(err_info);
		if (len >= DMD_DET_ERR_LEN) {
			LCD_ERR("strlen error\n");
			return;
		}
		ret = snprintf(err_info + len, DMD_DET_ERR_LEN - len,
			"%d: %x, %x, %x, %x ",
			i + DET_START,
			reg_val[i][DET1_INDEX][VAL_0],
			reg_val[i][DET2_INDEX][VAL_0],
			reg_val[i][DET3_INDEX][VAL_0],
			reg_val[i][DET4_INDEX][VAL_0]);
		if (ret < 0) {
			LCD_ERR("snprintf error\n");
			return;
		}
	}
	LCD_INFO("err_info = %s\n", err_info);
#if IS_ENABLED(CONFIG_DSM)
	(void)lcd_dsm_client_record(lcd_dclient, err_info, DSM_LCD_DDIC_LV_DETECT_ERROR_NO);
#endif
}

static int lcd_judge_ddic_lv_detect(struct panel_info *pinfo,
	uint32_t pic_index, int loop)
{
	int i;
	uint8_t expect_value;
	int ret;
	uint32_t * detect_value = NULL;
	uint8_t read_value[MAX_REG_READ_COUNT] = {0};
	struct lcd_fact_info *fact_info = NULL;

	fact_info =pinfo->fact_info;
	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	detect_value = fact_info->ddic_lv_detect.lv_expect;
	if (detect_value == NULL) {
		LCD_INFO("lvd expect value is null\n");
		return LCD_FAIL;
	}

	/* delay 2s, or ddic reg value invalid */
	ssleep(2);

	ret = dsi_panel_receive_data(pinfo->panel,
			DSI_CMD_LVD_READ_ENABLE, read_value, MAX_REG_READ_COUNT - 1);

	if (ret) {
		LCD_INFO("lvd read reg error\n");
		return ret;
	}

	for (i = 0; i <fact_info->ddic_lv_detect.cnt; i++) {
		/* obtains the value of the first byte */
		expect_value = detect_value[i] & 0xFF;
		LCD_INFO("pic: %u, read_val[%d] = 0x%x, expect_val = 0x%x\n",
			pic_index, i, read_value[i], expect_value);
		if ((i < VAL_NUM) && (loop < DETECT_LOOPS))
			fact_info->ddic_lv_detect.reg_val[loop][pic_index][i] =
				read_value[i];
		if (read_value[i] != expect_value) {
			fact_info->ddic_lv_detect.err_flag[pic_index]++;
			LCD_ERR("pic: %u, read_val:%d = 0x%x, but expect_val = 0x%x\n",
				pic_index, i, read_value[i], expect_value);
			return LCD_FAIL;
		}
	}

	return ret;
}

static int lcd_ddic_lv_detect_test(struct panel_info *pinfo)
{
	int i;
	int ret;
	static int count;
	static int loop_num;
	int err_record = 0;
	uint32_t pic_index;
	uint32_t *error_flag = NULL;
	struct lcd_fact_info *fact_info = NULL;

	fact_info = pinfo->fact_info;
	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	pic_index = fact_info->ddic_lv_detect.pic_index;
	error_flag = fact_info->ddic_lv_detect.err_flag;
	if (pic_index >= DETECT_NUM) {
		LCD_ERR("pic number not support\n");
		return LCD_FAIL;
	}
	ret = lcd_judge_ddic_lv_detect(pinfo, pic_index, loop_num);
	if (ret)
		LCD_ERR("ddic lvd judge fail\n");

	if (count >= DETECT_NUM) {
		loop_num++;
		/* set initial value */
		count = 0;
	}
	LCD_INFO("count = %d, loop_num = %d\n", count, loop_num);
	count++;
	if ((count == DETECT_NUM) && (loop_num >= DETECT_LOOPS-1)) {
		for (i = 0; i < DETECT_NUM; i++) {
			LCD_INFO("pic : %d, err_num = %d\n",
				i, error_flag[i]);
			if (error_flag[i] > ERR_THRESHOLD)
				err_record++;
			/* set initial value */
			fact_info->ddic_lv_detect.err_flag[i] = 0;
		}
		if (err_record > 0)
			lcd_kit_ddic_lv_detect_dmd_report(
			fact_info->ddic_lv_detect.reg_val);
		/* set initial value */
		loop_num = 0;
	}
	return ret;
}

static int lcd_ddic_lv_detect_set(struct panel_info *pinfo,
	uint32_t pic_index)
{
	int ret = LCD_OK;
	struct lcd_fact_info *fact_info = NULL;
	struct dsi_panel *panel = pinfo->panel;
	fact_info = pinfo->fact_info;
	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pointer is null\n");
		return -EINVAL;
	}

	pic_index = pic_index - DET_START;
	if ((pic_index >= DET1_INDEX) && (pic_index < DETECT_NUM)) {
		lcd_set_esd_pending(pinfo, LCD_ESD_DISABLE);
		mutex_lock(&panel->panel_lock);
		ret = dsi_panel_set_cmd(pinfo->panel,DSI_CMD_LVD_ENTER_ENABLE);
		mutex_unlock(&panel->panel_lock);
		if (ret) {
			LCD_ERR("send lvd cmd error\n");
			return ret;
		}

		LCD_INFO("set picture : %u\n", pic_index);
		fact_info->ddic_lv_detect.pic_index = pic_index;
	} else {
		LCD_INFO("set picture : %u unknown\n", pic_index);
		fact_info->ddic_lv_detect.pic_index = INVALID_INDEX;
	}

	return ret;
}

static ssize_t lcd_ddic_lv_detect_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int result;
	ssize_t ret = LCD_OK;
	struct panel_info *pinfo = NULL;
	pinfo = get_panel_info(get_fb_index(dev));

	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	if (pinfo->fact_info->ddic_lv_detect.support) {
		if (pinfo->power_on) {
			result = lcd_ddic_lv_detect_test(pinfo);
			ret = snprintf(buf, PAGE_SIZE, "%d\n", result);
		}
		lcd_panel_recovery(pinfo);
		lcd_set_esd_pending(pinfo, LCD_ESD_ENABLE);
	}

	return ret;
}

static ssize_t	lcd_ddic_lv_detect_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	ssize_t ret;
	uint32_t index = 0;
	struct panel_info *pinfo = NULL;

	pinfo = get_panel_info(get_fb_index(dev));
	if (!pinfo || !pinfo->fact_info) {
		LCD_ERR("pinfo is null\n");
		return -EINVAL;
	}

	if (!pinfo->fact_info->ddic_lv_detect.support) {
		LCD_INFO("ddic lv detect is not support\n");
		return LCD_FAIL;
	}
	if (dev == NULL) {
		LCD_ERR("dev is null\n");
		return LCD_FAIL;
	}
	if (buf == NULL) {
		LCD_ERR("buf is null\n");
		return LCD_FAIL;
	}

	/* decimal parsing */
	ret = kstrtouint(buf, 10, &index);
	if (ret) {
		LCD_ERR("strict_strtoul fail\n");
		return ret;
	}

	LCD_INFO("picture index=%u\n", index);
	if (pinfo->power_on) {
		ret = lcd_ddic_lv_detect_set(pinfo, index);
	}

	return ret;
}

static DEVICE_ATTR(lcd_inversion_mode, 0644, lcd_inversion_mode_show,
	lcd_inversion_mode_store);
static DEVICE_ATTR(lcd_scan_mode, 0644, lcd_scan_mode_show,
	lcd_scan_mode_store);
static DEVICE_ATTR(lcd_check_reg, 0444, lcd_check_reg_show, NULL);
static DEVICE_ATTR(lcd_checksum, 0644, lcd_gram_check_show,
	lcd_gram_check_store);
static DEVICE_ATTR(lcd_sleep_ctrl, 0644, lcd_sleep_ctrl_show,
	lcd_sleep_ctrl_store);
static DEVICE_ATTR(amoled_pcd_errflag_check, 0644,
	lcd_amoled_pcd_errflag_show,
	lcd_amoled_pcd_errflag_store);
static DEVICE_ATTR(lcd_test_config, 0640, lcd_test_config_show,
	lcd_test_config_store);
static DEVICE_ATTR(lv_detect, 0640, lcd_lv_detect_show, NULL);
static DEVICE_ATTR(current_detect, 0640, lcd_current_detect_show, NULL);
static DEVICE_ATTR(lcd_general_test, 0444, lcd_general_test_show, NULL);
static DEVICE_ATTR(vertical_line_test, 0644,
	lcd_vertical_line_test_show, lcd_vertical_line_test_store);
static DEVICE_ATTR(lcd_oneside_mode, 0644, lcd_oneside_mode_show,
	lcd_oneside_mode_store);
static DEVICE_ATTR(avdd_detect, 0644, lcd_avdd_detect_show, NULL);
static DEVICE_ATTR(ddic_lv_detect, 0644, lcd_ddic_lv_detect_show,
	lcd_ddic_lv_detect_store);

/* factory attrs */
struct attribute *lcd_factory_attrs[] = {
	&dev_attr_lcd_inversion_mode.attr,
	&dev_attr_lcd_scan_mode.attr,
	&dev_attr_lcd_check_reg.attr,
	&dev_attr_lcd_checksum.attr,
	&dev_attr_lcd_sleep_ctrl.attr,
	&dev_attr_amoled_pcd_errflag_check.attr,
	&dev_attr_lcd_test_config.attr,
	&dev_attr_lv_detect.attr,
	&dev_attr_current_detect.attr,
	&dev_attr_lcd_general_test.attr,
	&dev_attr_vertical_line_test.attr,
	&dev_attr_lcd_oneside_mode.attr,
	&dev_attr_avdd_detect.attr,
	&dev_attr_ddic_lv_detect.attr,
	NULL,
};

struct attribute_group lcd_fac_sysfs_attr_group = {
	.attrs = lcd_factory_attrs,
};

int lcd_create_fact_sysfs(struct kobject *obj)
{
	int rc;

	rc = sysfs_create_group(obj, &lcd_fac_sysfs_attr_group);
	if (rc)
		LCD_ERR("sysfs group creation failed, rc=%d\n", rc);
	return rc;
}

static void parse_check_reg(struct lcd_fact_info *fact_info,
	struct dsi_parser_utils *utils)
{
	int i = 0;
	int val = 0;

	fact_info->checkreg.enabled = utils->read_bool(utils->data,
			"qcom,mdss-dsi-panel-lcd-check-reg-enabled");
	if (!fact_info->checkreg.enabled)
		return;

	fact_info->checkreg.expect_count = of_property_count_u32_elems(utils->data,
			"qcom,mdss-dsi-panel-lcd-check-reg-expect_vals");

	fact_info->checkreg.expect_val = kcalloc(fact_info->checkreg.expect_count,
			sizeof(int), GFP_KERNEL);
	for (i = 0; i < fact_info->checkreg.expect_count; i++) {
		of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-panel-lcd-check-reg-expect_vals", i, &val);
		fact_info->checkreg.expect_val[i] = val;
	}
}

static void parse_pcd(struct lcd_fact_info *fact_info,
	struct dsi_parser_utils *utils)
{
	int val = 0;

	/* pcd errflag */
	fact_info->pcd_errflag_check.pcd_support = utils->read_bool(utils->data,
		"qcom,mdss-dsi-panel-lcd-check-pcd-support");
	if (fact_info->pcd_errflag_check.pcd_support) {
		of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-panel-lcd-check-pcd-expect_vals", 0, &val);
		fact_info->pcd_errflag_check.pcd_value = val;

		of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-panel-lcd-pcd_value_compare_mode", 0, &val);
		fact_info->pcd_errflag_check.pcd_value_compare_mode = val;

		of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-panel-lcd-pcd_mask", 0, &val);
		fact_info->pcd_errflag_check.exp_pcd_mask = val;

		of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-panel-lcd-pcd_det_num", 0, &val);
		fact_info->pcd_errflag_check.pcd_det_num = val;
	}

}

static void parse_hor_line(struct lcd_fact_info *fact_info,
	struct dsi_parser_utils *utils)
{
	int val = 0;

	/* hor line check */
	fact_info->hor_line_test.hor_support = utils->read_bool(utils->data,
							"qcom,mdss-dsi-panel-lcd-hor-line-support");
	if (fact_info->hor_line_test.hor_support) {
		fact_info->hor_line_test.hor_no_reset = utils->read_bool(utils->data,
								"qcom,mdss-dsi-panel-lcd-hor-line-no-reset");

		of_property_read_u32_index(utils->data,
				"qcom,mdss-dsi-panel-lcd-hor-line-duration", 0, &val);
		fact_info->hor_line_test.hor_duration = val;
	}
}

static void parse_vtc_line(struct lcd_fact_info *fact_info,
	struct dsi_parser_utils *utils)
{
	/* vtc line check */
	fact_info->vtc_line_test.vtc_support = utils->read_bool(utils->data,
							"qcom,mdss-dsi-panel-lcd-vtc-line-support");
	if (fact_info->vtc_line_test.vtc_support) {
		fact_info->vtc_line_test.vtc_no_reset = utils->read_bool(utils->data,
								"qcom,mdss-dsi-panel-lcd-vtc-line-no-reset");
	}
}

static void parse_lvd(struct lcd_fact_info *fact_info,
	struct dsi_parser_utils *utils)
{
	int i = 0;
	int val = 0;

	fact_info->ddic_lv_detect.support = utils->read_bool(utils->data,
			"qcom,mdss-dsi-panel-lvd-support");

	if (fact_info->ddic_lv_detect.support)
	{
		fact_info->ddic_lv_detect.cnt = of_property_count_u32_elems(utils->data,
			"qcom,mdss-dsi-lvd-expect-value");

		fact_info->ddic_lv_detect.lv_expect = kcalloc(fact_info->ddic_lv_detect.cnt,
			sizeof(int), GFP_KERNEL);

		if (!fact_info->ddic_lv_detect.lv_expect) {
			LCD_ERR("kcalloc lv_expect info fail\n");
			return;
		}

		for (i = 0; i < fact_info->ddic_lv_detect.cnt; i++) {
			of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-lvd-expect-value", i, &val);
			fact_info->ddic_lv_detect.lv_expect[i] = val;
		}
	}
}

static void parse_checksum(struct lcd_fact_info *fact_info,
	struct dsi_parser_utils *utils)
{
	int i;
	int val = 0;
	struct lcd_checksum *checksum = &fact_info->checksum;

	checksum->support = utils->read_bool(utils->data,
		"qcom,mdss-dsi-panel-checksum-support");
	if (!checksum->support)
		return;

	checksum->value.cnt = of_property_count_u32_elems(utils->data,
			"qcom,mdss-dsi-panel-checksum-value");

	checksum->value.buf = kcalloc(checksum->value.cnt,
			sizeof(u32), GFP_KERNEL);
	if (!checksum->value.buf) {
		LCD_ERR("kcalloc value buf fail!\n");
		return;
	}
	for (i = 0; i < checksum->value.cnt; i++) {
		of_property_read_u32_index(utils->data,
			"qcom,mdss-dsi-panel-checksum-value", i, &val);
		checksum->value.buf[i] = val;
	}
}

int factory_init(struct dsi_panel *panel, struct panel_info *pinfo)
{
	struct dsi_parser_utils *utils = &panel->utils;

	if (!utils) {
		LCD_ERR("utils is null\n");
		return -1;
	}
	pinfo->fact_info = kzalloc(sizeof(struct lcd_fact_info), GFP_KERNEL);
	if (!pinfo->fact_info) {
		LCD_ERR("kzalloc factory info fail\n");
		return -1;
	}
	pinfo->fact_info->pt_reset_enable = utils->read_bool(utils->data,
		"qcom,mdss-dsi-panel-pt-reset-enabled");

	init_completion(&pinfo->lcd_test_comp);
	parse_check_reg(pinfo->fact_info, utils);
	parse_pcd(pinfo->fact_info, utils);
	parse_vtc_line(pinfo->fact_info, utils);
	parse_hor_line(pinfo->fact_info, utils);
	parse_lvd(pinfo->fact_info, utils);
	parse_checksum(pinfo->fact_info, utils);
	return 0;
}
