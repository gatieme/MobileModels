#include <linux/platform_device.h>

#include <linux/interrupt.h>
#include <linux/i2c.h>
#include <linux/regmap.h>
#include <linux/kernel.h>
#include <linux/clk.h>

#include "hisi_fb.h"
#include "bridge_pinctrl.h"


#define  DEFAULT_MAX_BRIGHTNESS 120000
#define  EDID_LEN  128
struct mipi2edp;

enum mipi2edp_type {
	LT9711A = 0,
	SN65DSIX6 = 1,
};

enum mipi2edp_output {
	OUTPUT_LCD = 0,
	OUTPUT_VGA = 1,
};

#define DEFAULT_BRIDGE SN65DSIX6

struct gpio_config {
	int hw_enable_gpio;
	int hw_suspend_gpio;
	int lcd_vdd_enable_gpio;
	int bl_config_enable_gpio;
};

struct bridge_chip_ops {
	int (*is_chip_onboard)(struct mipi2edp  *pdata);
	void (*pre_enable)(struct mipi2edp  *pdata);
	int (*enable)(struct mipi2edp  *pdata);
	void (*disable)(struct mipi2edp  *pdata);
	void (*post_disable)(struct mipi2edp  *pdata);
};

struct mipi2edp {
	struct pinctrl_data *pinctrl;
	struct gpio_config *gpio_set;
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	const struct regmap_config *regmap_config;
    struct platform_device *pdev;

	struct clk *mipi2edp_clk;
	/* DSI RX related params */
	struct device_node *host_node;
	struct mipi_dsi_device *dsi;
	u8 num_dsi_lanes;
	unsigned int hw_hpd_gpio;
	unsigned int hw_hpd_irq;
	unsigned int patch;
	struct hisi_panel_info panel_info;
	struct backlight_device *bl;
	enum mipi2edp_output output;
	enum mipi2edp_type type;

	struct bridge_chip_ops chip;
	struct regulator *ec_1v2_en;
	struct regulator *ec_dsi_vccio_on;
	struct regulator *ec_1v8_en;
	int output_hdisplay;
	int output_vdisplay;
	int output_vrefresh;
	char edid_array[EDID_LEN];
};

struct mipi_info {
	uint32_t dsi_bit_clk;
	uint32_t hsa;
	uint32_t hbp;
	uint32_t hline_time;
	uint32_t vsa;
	uint32_t vbp;
	uint32_t vfp;
	uint32_t dpi_hsize;
	uint32_t vactive_line;
};

struct config_table {
	int64_t key;
	struct mipi_info *mipi_config_info;
};

int mipi2edp_panel_info_config(struct mipi2edp *pdata);
int mipi2edp_panel_diff_info_init(struct mipi2edp *pdata, struct mipi_info mipi2edp_panel_info_init_data);
int mipi2edp_panel_comon_info_init(struct mipi2edp *pdata);

void mipi2edp_bridge_pre_enable(struct mipi2edp *pdata);
void mipi2edp_bridge_enable(struct mipi2edp *pdata);
void mipi2edp_bridge_disable(struct mipi2edp *pdata);
void mipi2edp_bridge_post_disable(struct mipi2edp *pdata);
void bridge_power_off(void);
void  mipi2edp_bridge_resume(struct device *dev);
