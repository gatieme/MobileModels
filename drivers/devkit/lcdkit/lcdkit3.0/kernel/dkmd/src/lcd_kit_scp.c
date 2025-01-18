

#include "lcd_kit_scp.h"
#include "lcd_kit_disp.h"
#include "lcd_kit_parse.h"
#include "lcd_kit_adapt.h"
#include <securec.h>
#ifdef CONFIG_POWER_DUBAI
#include <huawei_platform/log/hwlog_kernel.h>
#endif

#if defined CONFIG_HUAWEI_DSM
extern struct dsm_client *lcd_dclient;
#endif


#ifdef CONFIG_HUAWEI_DSM
static void lcd_kit_scp_dmd_report(int panel_id, char read_value)
{
	int ret;
	char dmd_info[DMD_DET_ERR_LEN] = {0};

	ret = snprintf_s(dmd_info, DMD_DET_ERR_LEN, DMD_DET_ERR_LEN -1,
		"lcd short circuit error: panel_id=%d, read_value=0x%x\n",
		panel_id, read_value);
	if (ret < 0) {
		LCD_KIT_ERR("snprintf error\n");
		return;
	}

	if (!lcd_dclient) {
		LCD_KIT_ERR("null pointer!\n");
		return;
	}

	if (!dsm_client_ocuppy(lcd_dclient)) {
		dsm_client_record(lcd_dclient, dmd_info);
		dsm_client_notify(lcd_dclient, DSM_LCD_ESD_OCP_RECOVERY_NO);
		LCD_KIT_INFO("%s", dmd_info);
		return;
	}

	LCD_KIT_ERR("dsm_client_ocuppy failed!\n");
}
#endif

static void lcd_kit_set_short_circuit_state(int panel_id, uint32_t status, char read_value)
{
	disp_info->short_circuit_protection.skip_power_on = true;
	disp_info->short_circuit_protection.short_circuit_cnt = 0;

#if defined(CONFIG_DKMD_DPU_AOD)
	if (panel_id == PRIMARY_PANEL)
		dkmd_set_lcd_status(PRIMARY_PANEL_SHORT_CIRCUIT_BIT, status);
	else if (panel_id == SECONDARY_PANEL)
		dkmd_set_lcd_status(SECONDARY_PANEL_SHORT_CIRCUIT_BIT, status);
	else
		return;
#else
	return;
#endif

#ifdef CONFIG_HUAWEI_DSM
	lcd_kit_scp_dmd_report(panel_id, read_value);
#endif

	LCD_KIT_ERR("short circuit protection, panel_id=%d\n", panel_id);
	return;
}

static int lcd_kit_get_short_circuit_state(int panel_id)
{
	if (!disp_info->short_circuit_protection.support)
		return false;

	return disp_info->short_circuit_protection.skip_power_on;
}

static int lcd_kit_scp_strategy(int panel_id, u32 *short_circuit_value, char *read_value)
{
	int ret = LCD_KIT_OK;
	char expect_value;
	int i;
	struct timespec64 *record_tv = NULL;
	struct timespec64 cur_tv;
	long delta_time;

	for (i = 0; i < disp_info->short_circuit_protection.value.cnt; i++) {
		expect_value = short_circuit_value[i] & 0xFF;
		LCD_KIT_INFO("short_circuit_value[%d] = 0x%x, read_value[%d] = 0x%x, expect_value = 0x%x, short_circuit_cnt = %d\n",
			i, short_circuit_value[i], i, read_value[i], expect_value,
			disp_info->short_circuit_protection.short_circuit_cnt);

		record_tv = &(disp_info->short_circuit_protection.short_circuit_record_tv);
		ktime_get_real_ts64(&cur_tv);
		/* change s to ns */
		delta_time = (cur_tv.tv_sec - record_tv->tv_sec) * 1000000000 + cur_tv.tv_nsec - record_tv->tv_nsec;
		/* change ns to ms */
		delta_time /= 1000000;

		/* more than 10 minutes clear residual historical short circuit information */
		if (cur_tv.tv_sec - record_tv->tv_sec > disp_info->short_circuit_protection.max_residue_time)
			disp_info->short_circuit_protection.short_circuit_cnt = 0;

		if (lcd_kit_judge_esd(ESD_EQUAL, read_value[i], expect_value)) {
			/* exit ESD, decrease by 1 points, maintain a residual effect */
			disp_info->short_circuit_protection.short_circuit_cnt--;
			if (disp_info->short_circuit_protection.short_circuit_cnt <= 0)
				disp_info->short_circuit_protection.short_circuit_cnt = 0;
			LCD_KIT_INFO("short_circuit_cnt=%d\n", disp_info->short_circuit_protection.short_circuit_cnt);
			continue;
		}

		/* enter LVD */
		disp_info->short_circuit_protection.short_circuit_cnt++;
		LCD_KIT_INFO("cur_tv.tv_sec=%ds, record_tv->tv_sec=%ds delta_time=%dms short_circuit_cnt=%d\n",
			cur_tv.tv_sec, record_tv->tv_sec, delta_time, disp_info->short_circuit_protection.short_circuit_cnt);
		/* LVD occurs again after the restart, DDIC's LVD self protection ability, avoid reset repeatedly. accumulate 1 points */
		if (delta_time < disp_info->short_circuit_protection.self_protection_time && delta_time >
			disp_info->short_circuit_protection.max_continuous_read_time &&
			disp_info->short_circuit_protection.short_circuit_cnt <
			disp_info->short_circuit_protection.short_circuit_cnt_thd)
			continue;

		/* case1.read ESD three times consecutively, if read three times accumulate 3 points. case2.next LVD */
		if (disp_info->short_circuit_protection.short_circuit_cnt >=
			disp_info->short_circuit_protection.short_circuit_cnt_thd)
			lcd_kit_set_short_circuit_state(panel_id, true, read_value[i]);

		/* update timestamp */
		record_tv->tv_sec = cur_tv.tv_sec;
		record_tv->tv_nsec = cur_tv.tv_nsec;

		return LCD_KIT_ESD;
	}

	return LCD_KIT_OK;
}

static int lcd_kit_scp_check_start(int panel_id, void *hld)
{
	int ret = LCD_KIT_OK;
	char read_value[MAX_REG_READ_COUNT] = {0};
	u32 *short_circuit_value = NULL;
	struct lcd_kit_scp_ops * scp_ops = NULL;
	struct lcd_kit_adapt_ops *adapt_ops = NULL;

	if (!disp_info->short_circuit_protection.support) {
		LCD_KIT_DEBUG("not support short circuit protection, panel_id = %d\n", panel_id);
		return LCD_KIT_OK;
	}

	short_circuit_value = disp_info->short_circuit_protection.value.buf;
	if (!short_circuit_value) {
		LCD_KIT_ERR("not register short_circuit_protection !!!panel_id = %d\n", panel_id);
		return LCD_KIT_OK;
	}

	adapt_ops = lcd_kit_get_adapt_ops();
	if (!adapt_ops || !adapt_ops->mipi_rx) {
		LCD_KIT_ERR("can not register adapt_ops or mipi_rx! panel_id = %d\n", panel_id);
		return LCD_KIT_FAIL;
	}

	ret = adapt_ops->mipi_rx(panel_id, hld, read_value, MAX_REG_READ_COUNT - 1,
		&disp_info->short_circuit_protection.cmds);
	if (ret) {
		LCD_KIT_INFO("mipi_rx fail, panel_id = %d\n", panel_id);
		return LCD_KIT_FAIL;
	}

	return lcd_kit_scp_strategy(panel_id, short_circuit_value, read_value);
}

static void lcd_kit_panel_parse_scp_cmds(int panel_id, const struct device_node *np)
{
	lcd_kit_parse_u32(np, "lcd-kit,short-circuit-protection-support",
		&disp_info->short_circuit_protection.support, 0);
	if (!disp_info->short_circuit_protection.support)
		return;

	/* short circuit cnt greater than this threshold trigger protection, default thd is 12 */
	lcd_kit_parse_u32(np, "lcd-kit,short-circuit-cnt-thd",
		&disp_info->short_circuit_protection.short_circuit_cnt_thd, 12);
	/* short circuit self protection time, default 2000ms */
	lcd_kit_parse_u32(np, "lcd-kit,short-circuit-self-protection-time",
		&disp_info->short_circuit_protection.self_protection_time, 2000);
	/* short circuit max residue time, default 600s */
	lcd_kit_parse_u32(np, "lcd-kit,short-circuit-max-residue-time",
		&disp_info->short_circuit_protection.max_residue_time, 600);
	/* short circuit max continuous read time, default 100ms */
	lcd_kit_parse_u32(np, "lcd-kit,short-circuit-max-continuous-read-time",
		&disp_info->short_circuit_protection.max_continuous_read_time, 100);
	lcd_kit_parse_dcs_cmds(np, "lcd-kit,short-circuit-protection-cmds",
		"lcd-kit,short-circuit-protection-cmds-state", &disp_info->short_circuit_protection.cmds);
	lcd_kit_parse_array_data(np, "lcd-kit,short-circuit-protection-value",
		&disp_info->short_circuit_protection.value);

	memset_s(&disp_info->short_circuit_protection.short_circuit_record_tv,
		sizeof(struct timespec64), 0, sizeof(struct timespec64));
}

struct lcd_kit_scp_ops g_lcd_scp_ops = {
	.scp_check_start = lcd_kit_scp_check_start,
	.get_short_circuit_state = lcd_kit_get_short_circuit_state,
};

struct lcd_kit_scp_ops *lcd_kit_get_scp_ops(void)
{
	return &g_lcd_scp_ops;
}

int lcd_kit_scp_init(int panel_id, struct device_node *np)
{
	lcd_kit_panel_parse_scp_cmds(panel_id, np);
	return LCD_KIT_OK;
}
