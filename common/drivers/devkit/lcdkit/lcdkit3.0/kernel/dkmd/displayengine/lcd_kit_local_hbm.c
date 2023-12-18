/*
 * lcd_kit_local_hbm.c
 *
 * display engine dkmd LHBM function in lcd
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
 *
 */

#include "lcd_kit_local_hbm.h"

#include "lcd_kit_adapt.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_utils.h"
#include "lcd_kit_disp.h"

#include "huawei_platform/fingerprint_interface/fingerprint_interface.h"

static uint32_t display_engine_brightness_get_mipi_level(void);
static int display_engine_local_hbm_get_circle_cmd_index(int panel_id);
static bool display_engine_local_hbm_set_circle_cmds_valid(int panel_id);
static int display_engine_local_hbm_set_circle_by_index(int panel_id, void *hld,
	bool is_on, int index);
static int display_engine_local_hbm_set_circle_color_vendor1(int panel_id, int grayscale);
static int display_engine_local_hbm_set_circle_color_vendor2(int panel_id, int grayscale);
static int display_engine_local_hbm_set_circle_color_by_grayscale(int panel_id, void *hld,
	int grayscale);
static void display_engine_local_hbm_cmds_print(int panel_id);
static int display_engine_local_hbm_set_mcu(int panel_id, void *hld, bool is_on);
static int display_engine_local_hbm_change_gamma(int panel_id, void *hld);

#define BACKLIGHT_HIGH_LEVEL 1
#define BACKLIGHT_LOW_LEVEL  2
#define LHBM_ON_WAIT_VSYNC_COUNT 2
#define LHBM_SAFE_FRAMERATE_DELAY_US 9000

/* local hbm circle cmds index for different brightness level */
enum circle_cmd {
	CIRCLE_FIRST_CMD = 0,
	CIRCLE_SECOND_CMD = 1,
	CIRCLE_THIRD_CMD = 2,
	CIRCLE_CMD_NUM = 3,
};

enum local_hbm_ddic {
	DDIC_VENDOR1 = 0,
	DDIC_VENDOR2 = 1,
	DDIC_NUM = 2,
};

/* Displayengine local hbm related parameters */
struct de_context_local_hbm {
	unsigned int last_level_in;
	int fingerprint_backlight_type;
};

static struct de_context_local_hbm g_de_context = {
	.last_level_in = 0,
	.fingerprint_backlight_type = BACKLIGHT_LOW_LEVEL,
};

static bool display_engine_local_hbm_set_circle_cmds_valid(int panel_id)
{
	if (!common_info->hbm.circle_exit_first_cmds.cmds) {
		LCD_KIT_ERR("circle_exit_first_cmds.cmds is NULL\n");
		return false;
	}
	if (!common_info->hbm.circle_exit_second_cmds.cmds) {
		LCD_KIT_ERR("circle_exit_second_cmds.cmds is NULL\n");
		return false;
	}
	if (!common_info->hbm.circle_enter_first_cmds.cmds) {
		LCD_KIT_ERR("circle_enter_first_cmds.cmds is NULL\n");
		return false;
	}
	if (!common_info->hbm.circle_enter_second_cmds.cmds) {
		LCD_KIT_ERR("circle_enter_second_cmds.cmds is NULL\n");
		return false;
	}
	switch (common_info->hbm.local_hbm_ddic) {
	case DDIC_VENDOR1:
		return true;
	case DDIC_VENDOR2:
		if (!common_info->hbm.circle_exit_third_cmds.cmds) {
			LCD_KIT_ERR("circle_exit_third_cmds.cmds is NULL\n");
			return false;
		}
		if (!common_info->hbm.circle_enter_third_cmds.cmds) {
			LCD_KIT_ERR("circle_enter_third_cmds.cmds is NULL\n");
			return false;
		}
		return true;
	default:
		break;
	}
	return false;
}

static int display_engine_local_hbm_set_circle_by_index(int panel_id, void *hld,
	bool is_on, int index)
{
	int ret;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	LCD_KIT_INFO("index: %d\n", index);
	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("cannot get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	if (!is_on) {
		switch (index) {
		case CIRCLE_FIRST_CMD:
			ret = adapt_ops->mipi_tx(panel_id, hld,
				&common_info->hbm.circle_exit_first_cmds);
			break;
		case CIRCLE_SECOND_CMD:
			ret = adapt_ops->mipi_tx(panel_id, hld,
				&common_info->hbm.circle_exit_second_cmds);
			break;
		case CIRCLE_THIRD_CMD:
			ret = adapt_ops->mipi_tx(panel_id, hld,
				&common_info->hbm.circle_exit_third_cmds);
			break;
		default:
			ret = LCD_KIT_FAIL;
			break;
		}
	} else {
		switch (index) {
		case CIRCLE_FIRST_CMD:
			ret = adapt_ops->mipi_tx(panel_id, hld,
				&common_info->hbm.circle_enter_first_cmds);
			break;
		case CIRCLE_SECOND_CMD:
			ret = adapt_ops->mipi_tx(panel_id, hld,
				&common_info->hbm.circle_enter_second_cmds);
			break;
		case CIRCLE_THIRD_CMD:
			ret = adapt_ops->mipi_tx(panel_id, hld,
				&common_info->hbm.circle_enter_third_cmds);
			break;
		default:
			ret = LCD_KIT_FAIL;
			break;
		}
	}
	return ret;
}

static int display_engine_local_hbm_set_circle_color_vendor1(int panel_id, int grayscale)
{
	/* circle_color_cmds.cmd_cnt's maximum value is 5 */
	if (common_info->hbm.circle_color_cmds.cmd_cnt != 5) {
		LCD_KIT_ERR("circle_color_cmds.cmd_cnt does not match\n");
		return LCD_KIT_FAIL;
	}

	/* circle_color_cmds.cmds[r|g|b] index is [1|2|3] */
	/* circle_color_cmds.cmds[r|g|b].dlen maximum value is 2 */
	if ((int)common_info->hbm.circle_color_cmds.cmds[1].dlen < 2 ||
		(int)common_info->hbm.circle_color_cmds.cmds[2].dlen < 2 ||
		(int)common_info->hbm.circle_color_cmds.cmds[3].dlen < 2) {
		LCD_KIT_ERR("array index out of range, cmds.dlen\n");
		return LCD_KIT_FAIL;
	}

	/* circle_color_cmds.cmds[r|g|b].payload value index is 1 */
	common_info->hbm.circle_color_cmds.cmds[1].payload[1] = grayscale;
	common_info->hbm.circle_color_cmds.cmds[2].payload[1] = grayscale;
	common_info->hbm.circle_color_cmds.cmds[3].payload[1] = grayscale;
	return LCD_KIT_OK;
}

static int display_engine_local_hbm_set_circle_color_vendor2(int panel_id, int grayscale)
{
	/* circle_color_cmds.cmd_cnt's maximum value is 7 */
	if (common_info->hbm.circle_color_cmds.cmd_cnt != 7) {
		LCD_KIT_ERR("circle_color_cmds.cmd_cnt does not match, cnt: \n",
			common_info->hbm.circle_color_cmds.cmd_cnt);
		return LCD_KIT_FAIL;
	}

	/* circle_color_cmds.cmds[r|g|b] index is [1|3|5] */
	/* circle_color_cmds.cmds[r|g|b].dlen maximum value is 5 */
	if ((int)common_info->hbm.circle_color_cmds.cmds[1].dlen < 5 ||
		(int)common_info->hbm.circle_color_cmds.cmds[3].dlen < 5 ||
		(int)common_info->hbm.circle_color_cmds.cmds[5].dlen < 5) {
		LCD_KIT_ERR("array index out of range, cmds.dlen\n");
		return LCD_KIT_FAIL;
	}

	/* circle_color_cmds.cmds[r|g|b].payload value index is 1 & 2 */
	common_info->hbm.circle_color_cmds.cmds[1].payload[1] =
		(((grayscale + 1) << 4) - 1) & 0xff;
	common_info->hbm.circle_color_cmds.cmds[1].payload[2] =
		((((grayscale + 1) << 4) - 1) >> 8) & 0x0f;
	common_info->hbm.circle_color_cmds.cmds[3].payload[1] =
		(((grayscale + 1) << 4) - 1) & 0xff;
	common_info->hbm.circle_color_cmds.cmds[3].payload[2] =
		((((grayscale + 1) << 4) - 1) >> 8) & 0x0f;
	common_info->hbm.circle_color_cmds.cmds[5].payload[1] =
		(((grayscale + 1) << 4) - 1) & 0xff;
	common_info->hbm.circle_color_cmds.cmds[5].payload[2] =
		((((grayscale + 1) << 4) - 1) >> 8) & 0x0f;
	return LCD_KIT_OK;
}

static int display_engine_local_hbm_set_circle_color_by_grayscale(int panel_id, void *hld,
	int grayscale)
{
	int ret;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("cannot get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	if (!common_info->hbm.circle_color_cmds.cmds) {
		LCD_KIT_ERR("circle_color_cmds.cmds is NULL\n");
		return LCD_KIT_FAIL;
	}
	switch (common_info->hbm.local_hbm_ddic) {
	case DDIC_VENDOR1:
		ret = display_engine_local_hbm_set_circle_color_vendor1(panel_id, grayscale);
		break;
	case DDIC_VENDOR2:
		ret = display_engine_local_hbm_set_circle_color_vendor2(panel_id, grayscale);
		break;
	default:
		ret = LCD_KIT_FAIL;
		break;
	}
	if (ret != LCD_KIT_OK) {
		LCD_KIT_ERR("set circle color error\n");
		return LCD_KIT_FAIL;
	}
	ret = adapt_ops->mipi_tx(panel_id, hld, &common_info->hbm.circle_color_cmds);
	if (ret != LCD_KIT_OK)
		LCD_KIT_ERR("mipi_tx failed! ret = %d\n", ret);
	return ret;
}

static int display_engine_local_hbm_set_circle(int panel_id, void *hld, bool is_on)
{
	int ret;
	uint32_t dbv;
	int circle_cmd_index;

	if (!display_engine_local_hbm_set_circle_cmds_valid(panel_id)) {
		LCD_KIT_INFO("set circle cmds invalid\n");
		return LCD_KIT_FAIL;
	}
	dbv = display_engine_brightness_get_mipi_level();
	circle_cmd_index = display_engine_local_hbm_get_circle_cmd_index(panel_id);
	LCD_KIT_INFO("dbv:%d, circle_cmd_index:%d\n", dbv, circle_cmd_index);
	ret = display_engine_local_hbm_set_circle_by_index(panel_id, hld, is_on, circle_cmd_index);
	return ret;
}

static int display_engine_local_hbm_set_mcu(int panel_id, void *hld, bool is_on)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	if (!common_info->hbm.circle_mcu_open_cmds.cmds) {
		LCD_KIT_DEBUG("circle_mcu_open_cmds.cmds is NULL\n");
		return LCD_KIT_FAIL;
	}
	if (!common_info->hbm.circle_mcu_close_cmds.cmds) {
		LCD_KIT_DEBUG("circle_mcu_close_cmds.cmds is NULL\n");
		return LCD_KIT_FAIL;
	}
	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("cannot get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	/* close mcu to set circle color by grayscale */
	if (!is_on)
		ret = adapt_ops->mipi_tx(panel_id, hld, &common_info->hbm.circle_mcu_close_cmds);
	else
		ret = adapt_ops->mipi_tx(panel_id, hld, &common_info->hbm.circle_mcu_open_cmds);
	if (ret != LCD_KIT_OK)
		LCD_KIT_ERR("mipi_tx failed! ret = %d\n", ret);
	return ret;
}

int display_engine_local_hbm_change_gamma(int panel_id, void *hld)
{
	int ret = LCD_KIT_OK;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	if (!common_info->hbm.circle_gamma_change_cmds.cmds) {
		LCD_KIT_DEBUG("circle_gamma_change_cmds.cmds is NULL\n");
		return LCD_KIT_FAIL;
	}
	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_tx) {
		LCD_KIT_ERR("cannot get adapt_ops!\n");
		return LCD_KIT_FAIL;
	}
	/* change gamma to set circle color by grayscale */
	ret = adapt_ops->mipi_tx(panel_id, hld, &common_info->hbm.circle_gamma_change_cmds);
	if (ret != LCD_KIT_OK)
		LCD_KIT_ERR("mipi_tx failed! ret = %d\n", ret);
	return ret;
}

static int display_engine_local_hbm_set_inner(int panel_id, int grayscale)
{
	int ret = LCD_KIT_OK;
	unsigned int dsi0_index;
	unsigned int connector_id;

	connector_id = DPU_PINFO->connector_id;
	ret = lcd_kit_get_dsi_index(&dsi0_index, connector_id);
	if (ret) {
		LCD_KIT_ERR("get dsi0 index error\n");
		return LCD_KIT_FAIL;
	}

	LCD_KIT_INFO("grayscale: %d\n", grayscale);
	if (grayscale > 0) {
		/* enter LHBM close safe frame */
		dkmd_dfr_disable_safe_frm_rate(dsi0_index, DPU_PINFO->type, LHBM_DISABLE);
		/* max grayscale no need close mcu */
		if (grayscale != 255)
			display_engine_local_hbm_set_mcu(panel_id, NULL, false);
		display_engine_local_hbm_set_circle_color_by_grayscale(panel_id, NULL, grayscale);
		ret = display_engine_local_hbm_set_circle(panel_id, NULL, true);
		/* max grayscale no need change gamma */
		if (grayscale != 255)
			display_engine_local_hbm_change_gamma(panel_id, NULL);
		g_de_context.fingerprint_backlight_type = BACKLIGHT_HIGH_LEVEL;
		/* close dimming, start refresh */
		dkmd_dfr_send_refresh(dsi0_index, DPU_PINFO->type);
	} else {
		ret = display_engine_local_hbm_set_circle(panel_id, NULL, false);
		g_de_context.fingerprint_backlight_type = BACKLIGHT_LOW_LEVEL;
		if (common_info->hbm.local_hbm_ddic == DDIC_VENDOR1) {
			LCD_KIT_INFO("safe framerate delay +");
			usleep_range(LHBM_SAFE_FRAMERATE_DELAY_US, LHBM_SAFE_FRAMERATE_DELAY_US);
			LCD_KIT_INFO("safe framerate delay -");
		}
		/* exit LHBM open safe frame */
		dkmd_dfr_enable_safe_frm_rate(dsi0_index, DPU_PINFO->type);
		/* close dimming, start refresh */
		dkmd_dfr_send_refresh(dsi0_index, DPU_PINFO->type);
	}
	return ret;
}

int display_engine_brightness_update(unsigned int bl_level)
{
	g_de_context.last_level_in = bl_level;
	return LCD_KIT_OK;
}

static uint32_t display_engine_brightness_get_mipi_level(void)
{
	return g_de_context.last_level_in;
}

static int display_engine_local_hbm_get_circle_cmd_index(int panel_id)
{
	int i = 0;
	uint32_t dbv;

	if (!common_info->hbm.local_hbm_dbv_threshold.buf)
		return i;
	dbv = display_engine_brightness_get_mipi_level();
	for (i = 0; i < common_info->hbm.local_hbm_dbv_threshold.cnt; i++) {
		if (dbv < common_info->hbm.local_hbm_dbv_threshold.buf[i])
			return i;
	}
	return i - 1;
}

static void display_engine_local_hbm_cmds_print(int panel_id)
{
	LCD_KIT_INFO("LocalHBMSupport: %d, LocalHBMThreshold: <%d, %d, %d>, LocalHBMDdic: %d.\n",
		common_info->hbm.local_hbm_support, common_info->hbm.local_hbm_dbv_threshold.buf[0],
		common_info->hbm.local_hbm_dbv_threshold.buf[1],
		common_info->hbm.local_hbm_dbv_threshold.buf[2],
		common_info->hbm.local_hbm_ddic);
	LCD_KIT_INFO("FirstCommand cnt: %d, SecondCommand cnt: %d, ThirdCommand cnt: %d.\n",
		common_info->hbm.circle_enter_first_cmds.cmd_cnt,
		common_info->hbm.circle_enter_second_cmds.cmd_cnt,
		common_info->hbm.circle_enter_third_cmds.cmd_cnt);
}

void display_engine_local_hbm_workqueue_handler(struct kthread_work *work)
{
	static uint32_t vsync_count = 0;

	if (!work) {
		LCD_KIT_ERR("work is NULL.\n");
		return;
	}

	if (!display_engine_local_hbm_get_support()) {
		LCD_KIT_DEBUG("local hbm not support.\n");
		return;
	}

	if (g_de_context.fingerprint_backlight_type == BACKLIGHT_HIGH_LEVEL) {
		vsync_count += 1;
		if (vsync_count == LHBM_ON_WAIT_VSYNC_COUNT) {
			LCD_KIT_INFO("Fingerprint LHBM notify...\n");
			vsync_count = 0;
			ud_fp_on_hbm_completed();
		}
	} else {
		vsync_count = 0;
	}
}

static void lcd_kit_parse_local_hbm_support(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,local-hbm-support",
		&common_info->hbm.local_hbm_support, 0);
}

static void lcd_kit_parse_local_hbm_threshold(int panel_id, struct device_node *np)
{
	lcd_kit_parse_array_data(np, "lcd-kit,local-hbm-threshold",
		&common_info->hbm.local_hbm_dbv_threshold);
}

static void lcd_kit_parse_local_hbm_ddic(int panel_id, struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,local-hbm-ddic",
		&common_info->hbm.local_hbm_ddic, 0);
}

static void lcd_kit_parse_local_hbm_first_circle_cmds(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-circle-enter-first-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_enter_first_cmds);
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-circle-exit-first-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_exit_first_cmds);
}

static void lcd_kit_parse_local_hbm_second_circle_cmds(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-circle-enter-second-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_enter_second_cmds);
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-circle-exit-second-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_exit_second_cmds);
}

static void lcd_kit_parse_local_hbm_third_circle_cmds(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-circle-enter-third-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_enter_third_cmds);
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-circle-exit-third-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_exit_third_cmds);
}

static void lcd_kit_parse_local_hbm_circle_color_cmds(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-circle-color-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_color_cmds);
}

static void lcd_kit_parse_local_hbm_mcu_open_cmds(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-mcu-open-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_mcu_open_cmds);
}

static void lcd_kit_parse_local_hbm_mcu_close_cmds(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-mcu-close-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_mcu_close_cmds);
}

static void lcd_kit_parse_local_hbm_change_gamma_cmds(int panel_id, struct device_node *np)
{
	lcd_kit_parse_dcs_cmds(np,
		"lcd-kit,local-hbm-fp-panel-change-gamma-cmds-hisi",
		"lcd-kit,panel-circle-command-state",
		&common_info->hbm.circle_gamma_change_cmds);
}

void lcd_kit_local_hbm_cmds_parse(int panel_id, struct device_node *np)
{
	lcd_kit_parse_local_hbm_support(panel_id, np);
	if (!common_info->hbm.local_hbm_support) {
		LCD_KIT_INFO("platform not support local hbm\n");
		return;
	}
	lcd_kit_parse_local_hbm_threshold(panel_id, np);
	lcd_kit_parse_local_hbm_ddic(panel_id, np);
	lcd_kit_parse_local_hbm_first_circle_cmds(panel_id, np);
	lcd_kit_parse_local_hbm_second_circle_cmds(panel_id, np);
	lcd_kit_parse_local_hbm_third_circle_cmds(panel_id, np);
	lcd_kit_parse_local_hbm_circle_color_cmds(panel_id, np);
	lcd_kit_parse_local_hbm_mcu_open_cmds(panel_id, np);
	lcd_kit_parse_local_hbm_mcu_close_cmds(panel_id, np);
	lcd_kit_parse_local_hbm_change_gamma_cmds(panel_id, np);
}

void display_engine_local_hbm_init(void)
{
	struct ud_fp_display_ops finger_print_callback = {NULL, NULL, NULL};

	LCD_KIT_INFO("+\n");
	finger_print_callback.fp_get_local_hbm_mode = display_engine_local_hbm_get_support;
	finger_print_callback.fp_set_brightness_level = display_engine_local_hbm_set;
	ud_fp_display_register(&finger_print_callback);
	LCD_KIT_INFO("-\n");
}

uint32_t display_engine_local_hbm_get_support(void)
{
	int panel_id = PRIMARY_PANEL;

	LCD_KIT_DEBUG("local hbm support: %d.\n", common_info->hbm.local_hbm_support);
	return common_info->hbm.local_hbm_support;
}

int display_engine_local_hbm_set(int grayscale)
{
	int panel_id = PRIMARY_PANEL;

	LCD_KIT_INFO("+\n");
	if (!lcd_kit_get_panel_on_state(panel_id)) {
		g_de_context.fingerprint_backlight_type = BACKLIGHT_LOW_LEVEL;
		LCD_KIT_ERR("panel is power off\n");
		return LCD_KIT_FAIL;
	}

	if (!display_engine_local_hbm_get_support()) {
		LCD_KIT_ERR("Local HBM is not supported\n");
		return LCD_KIT_FAIL;
	}
	display_engine_local_hbm_set_inner(panel_id, grayscale);
	LCD_KIT_INFO("-\n");
	return LCD_KIT_OK;
}
