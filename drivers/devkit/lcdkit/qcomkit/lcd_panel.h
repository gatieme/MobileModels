/*
 * lcd_panel.h
 *
 * lcd panel function for lcd driver
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
#ifndef LCD_PANEL_H
#define LCD_PANEL_H
#if IS_ENABLED(CONFIG_DSM)
#include <dsm/dsm_pub.h>
#endif
#ifdef CONFIG_LCD_FACTORY
#include "lcd_factory.h"
#endif

#include "lcd_sysfs.h"

#define HBM_EXIT	0
#define HBM_ENTER	1
#define AOD_LK_BL	100
#define AOD_ULK_BL	101

#define LCD_ESD_OK 1
#define LCD_ESD_ERROR (-1)

//#if IS_ENABLED(CONFIG_DSM)
#define DMD_RECORD_BUF_LEN 100
//#endif

#define MAX_REG_READ_COUNT 4
#define MAX_REG_READ_ESD_COUNT 7

#define WORK_DELAY_TIME_READ_BATCH 20000
#define READ_PANEL_BATCH_NUM 1
#define READ_PANEL_BATCH_MAX_COUNT 3
#define MIPI_ERROR_CHECK_LENGTH 10
#define BACKLIGHT_LENGTH 3
#define MAX_READ_LHBM_LIGHT_LENGTH 6

/* LCD init step */
enum panel_init_step {
    PANEL_INIT_NONE = 0,
    PANEL_INIT_POWER_ON,
    PANEL_INIT_SEND_SEQUENCE,
    PANEL_INIT_MIPI_LP_SEND_SEQUENCE,
    PANEL_INIT_MIPI_HS_SEND_SEQUENCE,
};

/* LCD uninit step */
enum panel_uninit_step {
    PANEL_UNINIT_NONE = 0,
    PANEL_UNINIT_POWER_OFF,
    PANEL_UNINIT_SEND_SEQUENCE,
    PANEL_UNINIT_MIPI_LP_SEND_SEQUENCE,
    PANEL_UNINIT_MIPI_HS_SEND_SEQUENCE,
};

enum esd_judge_type {
	ESD_UNEQUAL,
	ESD_EQUAL,
	ESD_BIT_VALID,
};

enum panel_bias_type {
	PANEL_SET_BISA_VOL,
	PANEL_SET_BISA_POWER_DOWN,
	PANEL_SET_BISA_DISABLE,
};

enum adjust_backlight_level {
	INIT_MODE,
	LOW_LEVEL,
	HIGH_LEVEL,
};

enum cust_dsc_pps_type {
	DSC_PPS_DEF,
	DSC_PPS_NT37290,
};

typedef enum {
	MMI_COLOR_BAR,
	MMI_L0_P,
	MMI_OTHER,
	RT_IMAGE,
	RT_VIDEO,
} fps_order_factory;

struct hbm_desc {
	bool enabled;
	int mode;
};

struct lcd_kit_2d_barcode {
	u32 support;
	u32 offset;
	u8 barcode_data[OEM_INFO_SIZE_MAX];
	bool is_sn_read;
};

struct lcd_kit_sn_data {
	u32 support;
	unsigned char sn_code[LCD_SN_CODE_LENGTH];
};

struct lcd_kit_mipi_error_data {
	u32 support;
	u32 *expect_val;
	int expect_count;
};

struct lcd_kit_oem_info {
	u32 support;
	struct lcd_kit_2d_barcode barcode_2d;
	struct lcd_kit_sn_data sn_data;
};

struct panel_gamma_info {
	bool support;
	bool enable;
	u8 gamma_data1[LCD_GAMMA_CODE_LENGTH];
	u8 gamma_data3[LCD_GAMMA_CODE_LENGTH];
	u8 gamma_data5[LCD_GAMMA_CODE_LENGTH];
};

struct panel_batch_info {
	bool support;
	bool batch_match_hbm;
	u32 cnt;
	u32 *expect_val;
	struct dsi_panel_cmd_set *cmd_set;
};

struct lcd_bias_info {
	bool support;
	bool enabled;
	int enable_gpio;
};

struct lcd_kit_power_key_info {
	unsigned int support;
	unsigned int long_press_flag;
	unsigned int timer_val;
	struct notifier_block nb;
	struct delayed_work pf_work;
};

struct panel_info {
	const char *lcd_model;
	const char *lcd_ic_name;
	const char *lcd_module_name;
	u32 panel_id;
	int panel_state;
#ifdef CONFIG_LCD_FACTORY
	struct lcd_fact_info *fact_info;
	void *sde_connector;
	atomic_t lcd_esd_pending;
	atomic_t lcd_noti_comp;
	struct completion lcd_test_comp;
	fps_order_factory fps_order;
#endif
	struct hbm_desc hbm;
	struct lcd_kit_oem_info oeminfo;
	struct lcd_kit_mipi_error_data mipi_error;
	struct dsi_panel *panel;
	struct lcd_bias_info bias;
	bool local_hbm_enabled;
	bool lhbm_fpr_light_enable;
	bool lhbm_adjust_light_enable;
	bool lhbm_light_changed;
	u8 *lhbm_light_origin;
	u8 *lhbm_light_adjust;
	u32 *fps_list;
	u32 *fps_list_mmi_colorbar;
	u32 *fps_list_mmi_other;
	u32 *fps_list_rt_image;
	u32 *fps_list_rt_video;
	u32 fps_list_len;
	u32 fps_mmi_colorbar_len;
	u32 fps_mmi_other_len;
	u32 fps_rt_image_len;
	u32 fps_rt_video_len;
	bool power_on;
	bool four_byte_bl;
	struct panel_batch_info lcd_panel_batch_info;
	bool inited;
	u32 cust_dsc_pps_type;
	bool adjust_backlight_enabled;
	u32 low_backlight_high_bound;
	u32 low_backlight_low_bound;
	u32 high_backlight_high_bound;
	u32 backlight_level;
	u32 brightness;
	unsigned long dual_panel_display;
	struct lcd_kit_power_key_info pwrkey_press;
	u32 aod_mod;
	bool super_wallpaper;
	struct panel_gamma_info lcd_panel_gamma_info;
	u32 pre_reset_time;
};

struct panel_data {
	struct panel_info *pinfo;
	int (*create_sysfs)(struct kobject *obj);
	int (*panel_init)(struct dsi_panel *panel);
	int (*panel_hbm_set)(struct dsi_panel *panel,
		struct display_engine_ddic_hbm_param *hbm_cfg);
	int (*panel_hbm_fp_set)(struct dsi_panel *panel, int mode);
	int (*on)(struct dsi_panel *panel, int step);
	int (*off)(struct dsi_panel *panel, int step);
	int (*print_bkl)(struct dsi_panel *panel, u32 bl_lvl);
	int (*boot_set)(struct dsi_panel *panel);
	int (*set_backlight)(u32 bl_lvl);
};

extern struct panel_data g_panel_data;
extern struct usb_kit_ops *usb_kit_get_ops(void);
extern struct bat_heating_ops *bat_heating_get_ops(void);
extern struct bat_leakage_kit_ops *bat_leakage_kit_get_ops(void);

/* oem info cmd */
struct oem_info_cmd {
	unsigned char type;
	int (*func)(struct panel_info *pinfo, char *oem_data, int len);
};

extern int gamma_code(struct dsi_panel *panel);
int panel_mipi_error_check(struct dsi_panel *panel);

#if IS_ENABLED(CONFIG_DSM)
int lcd_dsm_client_record(struct dsm_client *lcd_dclient,const char *record_buf,
	int lcd_dsm_error_no);
#endif
#endif
