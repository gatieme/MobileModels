/*
* Simple driver
* Copyright (C)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#include "sy7758.h"
#include "lcd_kit_common.h"
#include "lcd_kit_utils.h"
#if IS_ENABLED(CONFIG_DRM_MEDIATEK)
#include "lcd_kit_drm_panel.h"
#else
#include "lcm_drv.h"
#endif
#include "lcd_kit_disp.h"
#include "lcd_kit_power.h"
#include "lcd_kit_bl.h"
#include "lcd_kit_bias.h"

#define I2C_READ_FLAG 1
#define I2C_WRITE_FLAG 0

static struct sy7758_backlight_information sy7758_bl_info;

static char *sy7758_dts_string[SY7758_RW_REG_MAX] = {
	"sy7758_close_ctrl",
	"sy7758_eprom_cfg0",
	"sy7758_eprom_cfg1",
	"sy7758_eprom_cfg2",
	"sy7758_eprom_cfg3",
	"sy7758_eprom_cfg4",
	"sy7758_eprom_cfg5",
	"sy7758_eprom_cfg6",
	"sy7758_eprom_cfg7",
	"sy7758_eprom_cfg9",
	"sy7758_eprom_cfgA",
	"sy7758_eprom_cfgE",
	"sy7758_eprom_cfg9E",
	"sy7758_led_enable",
	"sy7758_eprom_cfg98",
	"sy7758_fualt_flag",
	"sy7758_eprom_cfg00",
	"sy7758_eprom_cfg03",
	"sy7758_eprom_cfg04",
	"sy7758_eprom_cfg05",
	"sy7758_eprom_cfg10",
	"sy7758_eprom_cfg11",
	"sy7758_device_control",
};

static unsigned int sy7758_reg_addr[SY7758_RW_REG_MAX] = {
	SY7758_DEVICE_CONTROL,
	SY7758_EPROM_CFG0,
	SY7758_EPROM_CFG1,
	SY7758_EPROM_CFG2,
	SY7758_EPROM_CFG3,
	SY7758_EPROM_CFG4,
	SY7758_EPROM_CFG5,
	SY7758_EPROM_CFG6,
	SY7758_EPROM_CFG7,
	SY7758_EPROM_CFG9,
	SY7758_EPROM_CFGA,
	SY7758_EPROM_CFGE,
	SY7758_EPROM_CFG9E,
	SY7758_LED_ENABLE,
	SY7758_EPROM_CFG98,
	SY7758_FUALT_FLAG,
	SY7758_EPROM_CFG00,
	SY7758_EPROM_CFG03,
	SY7758_EPROM_CFG04,
	SY7758_EPROM_CFG05,
	SY7758_EPROM_CFG10,
	SY7758_EPROM_CFG11,
	SY7758_DEVICE_CONTROL,
};

struct class *sy7758_class = NULL;
struct sy7758_chip_data *sy7758_g_chip = NULL;
static bool sy7758_init_status = true;
static bool backlight_enable_status = true;
#if !(IS_ENABLED(CONFIG_DRM_MEDIATEK))
extern struct LCM_DRIVER lcdkit_mtk_common_panel;
#endif

/*
** for debug, S_IRUGO
** /sys/module/honorfb/parameters
*/
unsigned sy7758_msg_level = 7;
module_param_named(debug_sy7758_msg_level, sy7758_msg_level, int, 0640);
MODULE_PARM_DESC(debug_sy7758_msg_level, "backlight sy7758 msg level");

static int sy7758_parse_dts(struct device_node *np)
{
	int ret;
	int i;
	struct mtk_panel_info *plcd_kit_info = NULL;

	if(np == NULL){
		sy7758_err("np is null pointer\n");
		return -1;
	}

	for (i = 0;i < SY7758_RW_REG_MAX;i++ ) {
		ret = of_property_read_u32(np, sy7758_dts_string[i],
			&sy7758_bl_info.sy7758_reg[i]);
		if (ret < 0) {
			//init to invalid data
			sy7758_bl_info.sy7758_reg[i] = 0xffff;
			sy7758_info("can not find config:%s\n", sy7758_dts_string[i]);
		}
	}

	ret = of_property_read_u32(np, "bl_ctrl_enable", &sy7758_bl_info.ctrl_enable);
	if (ret < 0) {
		sy7758_info("can not get bl_ctrl_enable dts node\n");
	}

	ret = of_property_read_u32(np, "dual_ic", &sy7758_bl_info.dual_ic);
	if (ret < 0) {
		sy7758_info("can not get dual_ic dts node\n");
	}
	else {
		ret = of_property_read_u32(np, "sy7758_2_i2c_bus_id",
			&sy7758_bl_info.sy7758_2_i2c_bus_id);
		if (ret < 0)
			sy7758_info("can not get sy7758_2_i2c_bus_id dts node\n");
	}
	ret = of_property_read_u32(np, "sy7758_hw_enable",
		&sy7758_bl_info.sy7758_hw_en);
	if (ret < 0) {
		sy7758_err("get sy7758_hw_en dts config failed\n");
		sy7758_bl_info.sy7758_hw_en = 0;
	}
	if (sy7758_bl_info.sy7758_hw_en != 0) {
		ret = of_property_read_u32(np, "sy7758_hw_en_gpio",
			&sy7758_bl_info.sy7758_hw_en_gpio);
		if (ret < 0) {
			sy7758_err("get sy7758_hw_en_gpio dts config failed\n");
			return ret;
		}
		if (sy7758_bl_info.dual_ic) {
			ret = of_property_read_u32(np, "sy7758_2_hw_en_gpio",
				&sy7758_bl_info.sy7758_2_hw_en_gpio);
			if (ret < 0) {
				sy7758_err("get sy7758_2_hw_en_gpio dts config failed\n");
				return ret;
			}
		}
	}
	/* gpio number offset */
#if IS_ENABLED(CONFIG_DRM_MEDIATEK)
	plcd_kit_info = lcm_get_panel_info();
	if (plcd_kit_info != NULL) {
		sy7758_bl_info.sy7758_hw_en_gpio += plcd_kit_info->gpio_offset;
		if (sy7758_bl_info.dual_ic)
			sy7758_bl_info.sy7758_2_hw_en_gpio += plcd_kit_info->gpio_offset;
	}
#else
	sy7758_bl_info.sy7758_hw_en_gpio += ((struct mtk_panel_info *)(lcdkit_mtk_common_panel.panel_info))->gpio_offset;
	if (sy7758_bl_info.dual_ic)
		sy7758_bl_info.sy7758_2_hw_en_gpio += ((struct mtk_panel_info *)(lcdkit_mtk_common_panel.panel_info))->gpio_offset;
#endif
	ret = of_property_read_u32(np, "bl_on_kernel_mdelay",
		&sy7758_bl_info.bl_on_kernel_mdelay);
	if (ret < 0) {
		sy7758_err("get bl_on_kernel_mdelay dts config failed\n");
		return ret;
	}
	ret = of_property_read_u32(np, "bl_led_num",
		&sy7758_bl_info.bl_led_num);
	if (ret < 0) {
		sy7758_err("get bl_led_num dts config failed\n");
		return ret;
	}

	return ret;
}

static int sy7758_2_read_u8(struct sy7758_chip_data *pchip, unsigned int reg, unsigned int val[], unsigned int lenght)
{
	struct i2c_adapter *adap = NULL;
	struct i2c_msg msg[2] = {0};
	int ret= -ENODEV;

	if((pchip == NULL) || (val == NULL) || (pchip->client == NULL)) {
		sy7758_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	adap = i2c_get_adapter(sy7758_bl_info.sy7758_2_i2c_bus_id);
	if (adap == NULL) {
		sy7758_err("i2c device %d not found\n", sy7758_bl_info.sy7758_2_i2c_bus_id);
		goto out;
	}
	msg[0].addr = pchip->client->addr;
	msg[0].flags = I2C_WRITE_FLAG;
	msg[0].len = 1;
	msg[0].buf = (unsigned char *)&reg;

	msg[1].addr = pchip->client->addr;
	msg[1].flags = I2C_READ_FLAG;
	msg[1].len = lenght;
	msg[1].buf = (unsigned char *)val;

	ret = i2c_transfer(adap, msg, 2);
	if (ret < 0) {
		sy7758_err("i2c_transfer failed! ret:%d\n", ret);
		goto out;
	}

out:
	i2c_put_adapter(adap);

	return ret;
}

static int sy7758_2_config_write(struct sy7758_chip_data *pchip,
			unsigned int reg[], unsigned int val[], unsigned int size)
{
	struct i2c_adapter *adap = NULL;
	struct i2c_msg msg = {0};
	char buf[2];
	int ret;
	int i;

	if((pchip == NULL) || (reg == NULL) || (val == NULL) || (pchip->client == NULL)) {
		sy7758_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	/* get i2c adapter */
	adap = i2c_get_adapter(sy7758_bl_info.sy7758_2_i2c_bus_id);
	if (!adap) {
		sy7758_err("i2c device %d not found\n", sy7758_bl_info.sy7758_2_i2c_bus_id);
		ret = -ENODEV;
		goto out;
	}
	msg.addr = pchip->client->addr;
	msg.flags = pchip->client->flags;
	msg.len = 2;
	msg.buf = buf;
	for(i = 0; i < size; i++) {
		buf[0] = reg[i];
		buf[1] = val[i];
		if (val[i] != 0xffff) {
			ret = i2c_transfer(adap, &msg, 1);
			sy7758_info("sy7758_2_config_write reg=0x%x,val=0x%x\n", buf[0], buf[1]);
		}
	}
out:
	i2c_put_adapter(adap);
	return ret;
}

static int sy7758_config_write(struct sy7758_chip_data *pchip,
			unsigned int reg[],unsigned int val[],unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if((pchip == NULL) || (reg == NULL) || (val == NULL)){
		sy7758_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	for(i = 0;i < size;i++) {
		/*judge reg is invalid*/
		if (val[i] != 0xffff) {
			ret = regmap_write(pchip->regmap, reg[i], val[i]);
			if (ret < 0) {
				sy7758_err("write sy7758 backlight config register 0x%x failed\n",reg[i]);
				goto exit;
			}
		}
	}

exit:
	return ret;
}

static void lcd_kit_backlight_ctrl_enable(struct sy7758_chip_data *pchip)
{
	int ret;

	if (pchip == NULL) {
		sy7758_err("np is null pointer\n");
		return;
	}

	ret = sy7758_config_write(pchip, &sy7758_reg_addr[SY7758_RW_REG_MAX - 1], &sy7758_bl_info.sy7758_reg[SY7758_RW_REG_MAX - 1], 1);
	if (ret < 0) {
		sy7758_err("sy7758 config register failed");
		return;
	}

	if (sy7758_bl_info.dual_ic) {
		ret = sy7758_2_config_write(pchip, &sy7758_reg_addr[SY7758_RW_REG_MAX - 1], &sy7758_bl_info.sy7758_reg[SY7758_RW_REG_MAX - 1], 1);
		if (ret < 0) {
			sy7758_err("sy7758 slave config register failed\n");
			return;
		}
	}
	sy7758_info("backlight ctrl enable.\n");
}

static int sy7758_config_read(struct sy7758_chip_data *pchip,
			unsigned int reg[],unsigned int val[],unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if((pchip == NULL) || (reg == NULL) || (val == NULL)){
		sy7758_err("pchip or reg or val is null pointer\n");
		return -1;
	}

	for(i = 0;i < size;i++) {
		ret = regmap_read(pchip->regmap, reg[i],&val[i]);
		if (ret < 0) {
			sy7758_err("read sy7758 backlight config register 0x%x failed",reg[i]);
			goto exit;
		} else {
			sy7758_info("read 0x%x value = 0x%x\n", reg[i], val[i]);
		}
	}

exit:
	return ret;
}

/* initialize chip */
static int sy7758_chip_init(struct sy7758_chip_data *pchip)
{
	int ret = -1;

	sy7758_info("in!\n");

	if(pchip == NULL){
		sy7758_err("pchip is null pointer\n");
		return -1;
	}
	if (sy7758_bl_info.dual_ic) {
		ret = sy7758_2_config_write(pchip, sy7758_reg_addr, sy7758_bl_info.sy7758_reg, SY7758_INIT_CMD_NUM);
		if (ret < 0) {
			sy7758_err("sy7758 slave config register failed\n");
		goto out;
		}
	}
	ret = sy7758_config_write(pchip, sy7758_reg_addr, sy7758_bl_info.sy7758_reg, SY7758_INIT_CMD_NUM);
	if (ret < 0) {
		sy7758_err("sy7758 config register failed");
		goto out;
	}
	sy7758_info("ok!\n");
	return ret;

out:
	dev_err(pchip->dev, "i2c failed to access register\n");
	return ret;
}

/*
 * sy7758_set_reg(): Set sy7758 reg
 *
 * @bl_reg: which reg want to write
 * @bl_mask: which bits of reg want to change
 * @bl_val: what value want to write to the reg
 *
 * A value of zero will be returned on success, a negative errno will
 * be returned in error cases.
 */
ssize_t sy7758_set_reg(u8 bl_reg, u8 bl_mask, u8 bl_val)
{
	ssize_t ret = -1;
	u8 reg = bl_reg;
	u8 mask = bl_mask;
	u8 val = bl_val;

	if (!sy7758_init_status) {
		sy7758_err("init fail, return.\n");
		return ret;
	}

	if (reg < REG_MAX) {
		sy7758_err("Invalid argument!!!\n");
		return ret;
	}

	sy7758_info("%s:reg=0x%x,mask=0x%x,val=0x%x\n", __func__, reg, mask,
		val);

	ret = regmap_update_bits(sy7758_g_chip->regmap, reg, mask, val);
	if (ret < 0) {
		sy7758_err("i2c access fail to register\n");
		return ret;
	}

	return ret;
}
EXPORT_SYMBOL(sy7758_set_reg);

static ssize_t sy7758_reg_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct sy7758_chip_data *pchip = NULL;
	struct i2c_client *client = NULL;
	ssize_t ret = -1;

	if (!buf) {
		sy7758_err("buf is null\n");
		return ret;
	}

	if (!dev) {
		ret =  snprintf(buf, PAGE_SIZE, "dev is null\n");
		return ret;
	}

	pchip = dev_get_drvdata(dev);
	if (!pchip) {
		ret = snprintf(buf, PAGE_SIZE, "data is null\n");
		return ret;
	}

	client = pchip->client;
	if (!client) {
		ret = snprintf(buf, PAGE_SIZE, "client is null\n");
		return ret;
	}

	ret = sy7758_config_read(pchip, sy7758_reg_addr, sy7758_bl_info.sy7758_reg, SY7758_RW_REG_MAX);
	if (ret < 0) {
		sy7758_err("sy7758 config read failed");
		goto i2c_error;
	}

	ret = snprintf(buf, PAGE_SIZE, "Eprom Configuration0(0x01) = 0x%x\nEprom Configuration0(0xA0) = 0x%x\n\
			\rEprom Configuration1(0xA1) = 0x%x\nEprom Configuration2(0xA2) = 0x%x\n \
			\rEprom Configuration3(0xA3) = 0x%x\nEprom Configuration4(0xA4) = 0x%x\n \
			\rEprom Configuration5(0xA5) = 0x%x\nEprom Configuration6(0xA6) = 0x%x\n \
			\rEprom Configuration7(0xA7)  = 0x%x\nEprom Configuration9(0xA9)  = 0x%x\n \
			\rEprom ConfigurationA(0xAA) = 0x%x\nEprom ConfigurationE(0xAE) = 0x%x\n \
			\rEprom Configuration9E(0x9E) = 0x%x\nLed enable(0x16) = 0x%x\nEprom Configuration98(0x98) = 0x%x\nFUALT_FLAG(0x02) = 0x%x\nEprom Configuration0(0x00) = 0x%x\n \
			\rEprom Configuration03(0x03) = 0x%x\nEprom Configuration03(0x04)= 0x%x\nEprom Configuration05(0x05) = 0x%x\n \
			\rEprom Configuration10(0x10) = 0x%x\nEprom Configuration11(0x11) = 0x%x\nDevice control(0x01)= 0x%x\n",
			sy7758_bl_info.sy7758_reg[0], sy7758_bl_info.sy7758_reg[1], sy7758_bl_info.sy7758_reg[2], sy7758_bl_info.sy7758_reg[3], sy7758_bl_info.sy7758_reg[4], sy7758_bl_info.sy7758_reg[5],sy7758_bl_info.sy7758_reg[6], sy7758_bl_info.sy7758_reg[7],
			sy7758_bl_info.sy7758_reg[8], sy7758_bl_info.sy7758_reg[9], sy7758_bl_info.sy7758_reg[10], sy7758_bl_info.sy7758_reg[11], sy7758_bl_info.sy7758_reg[12], sy7758_bl_info.sy7758_reg[13],sy7758_bl_info.sy7758_reg[14],sy7758_bl_info.sy7758_reg[15],
			sy7758_bl_info.sy7758_reg[16],sy7758_bl_info.sy7758_reg[17],sy7758_bl_info.sy7758_reg[18],sy7758_bl_info.sy7758_reg[19],sy7758_bl_info.sy7758_reg[20],sy7758_bl_info.sy7758_reg[21], sy7758_bl_info.sy7758_reg[22]);
	return ret;

i2c_error:
	ret = snprintf(buf, PAGE_SIZE,"%s: i2c access fail to register\n", __func__);
	return ret;
}

static ssize_t sy7758_reg_store(struct device *dev,
					struct device_attribute *dev_attr,
					const char *buf, size_t size)
{
	ssize_t ret;
	struct sy7758_chip_data *pchip = NULL;
	unsigned int reg = 0;
	unsigned int mask = 0;
	unsigned int val = 0;

	if (!buf) {
		sy7758_err("buf is null\n");
		return -1;
	}

	if (!dev) {
		sy7758_err("dev is null\n");
		return -1;
	}

	pchip = dev_get_drvdata(dev);
	if(!pchip){
		sy7758_err("pchip is null\n");
		return -1;
	}

	ret = sscanf(buf, "reg=0x%x, mask=0x%x, val=0x%x", &reg, &mask, &val);
	if (ret < 0) {
		sy7758_info("check your input!!!\n");
		goto out_input;
	}

	sy7758_info("%s:reg=0x%x,mask=0x%x,val=0x%x\n", __func__, reg, mask, val);

	ret = regmap_update_bits(pchip->regmap, reg, mask, val);
	if (ret < 0)
		goto i2c_error;

	return size;

i2c_error:
	dev_err(pchip->dev, "%s:i2c access fail to register\n", __func__);
	return -1;

out_input:
	dev_err(pchip->dev, "%s:input conversion fail\n", __func__);
	return -1;
}

static DEVICE_ATTR(reg, (S_IRUGO|S_IWUSR), sy7758_reg_show, sy7758_reg_store);

/* pointers to created device attributes */
static struct attribute *sy7758_attributes[] = {
	&dev_attr_reg.attr,
	NULL,
};

static const struct attribute_group sy7758_group = {
	.attrs = sy7758_attributes,
};

static const struct regmap_config sy7758_regmap = {
	.reg_bits = 8,
	.val_bits = 8,
	.reg_stride = 1,
};

static void sy7758_enable(void)
{
	int ret;

	if (sy7758_bl_info.sy7758_hw_en) {
		ret = gpio_request(sy7758_bl_info.sy7758_hw_en_gpio, NULL);
		if (ret)
			sy7758_err("sy7758 Could not request  hw_en_gpio\n");
		ret = gpio_direction_output(sy7758_bl_info.sy7758_hw_en_gpio, GPIO_DIR_OUT);
		if (ret)
			sy7758_err("sy7758 set gpio output not success\n");
		gpio_set_value(sy7758_bl_info.sy7758_hw_en_gpio, GPIO_OUT_ONE);
		if (sy7758_bl_info.dual_ic) {
			ret = gpio_request(sy7758_bl_info.sy7758_2_hw_en_gpio, NULL);
			if (ret)
				sy7758_err("sy7758 Could not request  hw_en2_gpio\n");
			ret = gpio_direction_output(sy7758_bl_info.sy7758_2_hw_en_gpio, GPIO_DIR_OUT);
			if (ret)
				sy7758_err("sy7758 set gpio output not success\n");
			gpio_set_value(sy7758_bl_info.sy7758_2_hw_en_gpio, GPIO_OUT_ONE);
		}
		if (sy7758_bl_info.bl_on_kernel_mdelay)
			mdelay(sy7758_bl_info.bl_on_kernel_mdelay);
	}
	/* chip initialize */
	ret = sy7758_chip_init(sy7758_g_chip);
	if (ret < 0) {
		sy7758_err("sy7758_chip_init fail!\n");
		return;
	}
	sy7758_init_status = true;
}

static void sy7758_disable(void)
{
	if (sy7758_bl_info.sy7758_hw_en) {
		gpio_set_value(sy7758_bl_info.sy7758_hw_en_gpio, GPIO_OUT_ZERO);
		gpio_free(sy7758_bl_info.sy7758_hw_en_gpio);
		if (sy7758_bl_info.dual_ic) {
			gpio_set_value(sy7758_bl_info.sy7758_2_hw_en_gpio, GPIO_OUT_ZERO);
			gpio_free(sy7758_bl_info.sy7758_2_hw_en_gpio);
		}
	}
	sy7758_init_status = false;
	backlight_enable_status = false;
}

static int sy7758_set_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int bl_msb = 0;
	int bl_lsb = 0;
	int ret = 0;

	if (!sy7758_g_chip) {
		sy7758_err("sy7758_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(sy7758_g_chip->test_sem))) {
		sy7758_info("Now in test mode\n");
		return 0;
	}
	/*first set backlight, enable sy7758*/
	if (false == sy7758_init_status && bl_level > 0)
		sy7758_enable();

	if (false == sy7758_init_status) {
		sy7758_info("sy7758 is disabled, can not set backlight\n");
		up(&(sy7758_g_chip->test_sem));
		return 0;
	}
	/*set backlight level*/
	bl_msb = (bl_level >> 8) & 0x0F;
	bl_lsb = bl_level & 0xFF;

	ret = regmap_write(sy7758_g_chip->regmap, sy7758_bl_info.sy7758_level_lsb, bl_lsb);
	if (ret < 0)
		sy7758_err("write sy7758 backlight level lsb:0x%x failed\n", bl_lsb);
	ret = regmap_write(sy7758_g_chip->regmap, sy7758_bl_info.sy7758_level_msb, bl_msb);
	if (ret < 0)
		sy7758_err("write sy7758 backlight level msb:0x%x failed\n", bl_msb);
	sy7758_info("sy7758 write backlight level:%d bl_msb:0x%x bl_lsb:0x%x\n", bl_level, bl_msb, bl_lsb);

	if (backlight_enable_status == false) {
		if (sy7758_bl_info.ctrl_enable) {
			lcd_kit_backlight_ctrl_enable(sy7758_g_chip);
		}
		backlight_enable_status = true;
	}
	/*if set backlight level 0, disable sy7758*/
	if (true == sy7758_init_status && 0 == bl_level)
	{
		sy7758_disable();
	}
	up(&(sy7758_g_chip->test_sem));
	last_bl_level = bl_level;

	return ret;
}

static int sy7758_en_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int ret = 0;

	if (!sy7758_g_chip) {
		sy7758_err("sy7758_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(sy7758_g_chip->test_sem))) {
		sy7758_info("Now in test mode\n");
		return 0;
	}
	sy7758_info("sy7758_en_backlight bl_level=%d\n", bl_level);
	/*first set backlight, enable sy7758*/
	if (false == sy7758_init_status && bl_level > 0)
		sy7758_enable();

	/*if set backlight level 0, disable sy7758*/
	if (true == sy7758_init_status && 0 == bl_level)
		sy7758_disable();
	up(&(sy7758_g_chip->test_sem));
	last_bl_level = bl_level;
	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = sy7758_set_backlight,
	.en_backlight = sy7758_en_backlight,
	.name = "7758",
};

static int sy7758_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = NULL;
	struct sy7758_chip_data *pchip = NULL;
	int ret = -1;
	struct device_node *np = NULL;
	int temp = 0;

	sy7758_info("in!\n");

	if(!client){
		sy7758_err("client is null pointer\n");
		return -1;
	}
	adapter = client->adapter;

	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "i2c functionality check fail.\n");
		return -EOPNOTSUPP;
	}

	pchip = devm_kzalloc(&client->dev,
				sizeof(struct sy7758_chip_data), GFP_KERNEL);
	if (!pchip)
		return -ENOMEM;

#ifdef CONFIG_REGMAP_I2C
	pchip->regmap = devm_regmap_init_i2c(client, &sy7758_regmap);
	if (IS_ERR(pchip->regmap)) {
		ret = PTR_ERR(pchip->regmap);
		dev_err(&client->dev, "fail : allocate register map: %d\n", ret);
		goto err_out;
	}
#endif

	sy7758_g_chip = pchip;
	pchip->client = client;
	i2c_set_clientdata(client, pchip);

	sema_init(&(pchip->test_sem), 1);

	pchip->dev = device_create(sy7758_class, NULL, 0, "%s", client->name);
	if (IS_ERR(pchip->dev)) {
		/* Not fatal */
		sy7758_err("Unable to create device; errno = %ld\n", PTR_ERR(pchip->dev));
		pchip->dev = NULL;
	} else {
		dev_set_drvdata(pchip->dev, pchip);
		ret = sysfs_create_group(&pchip->dev->kobj, &sy7758_group);
		if (ret)
			goto err_sysfs;
	}

	memset(&sy7758_bl_info, 0, sizeof(struct sy7758_backlight_information));

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_SY7758);
	if (!np) {
		sy7758_err("NOT FOUND device node %s!\n", DTS_COMP_SY7758);
		goto err_sysfs;
	}

	ret = sy7758_parse_dts(np);
	if (ret < 0) {
		sy7758_err("parse sy7758 dts failed");
		goto err_sysfs;
	}

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_SY7758);
	if (!np) {
		sy7758_err("NOT FOUND device node %s!\n", DTS_COMP_SY7758);
		goto err_sysfs;
	}
	/* Only testing sy7758 used */
	ret = regmap_read(pchip->regmap, sy7758_reg_addr[0], &temp);
	if (ret < 0) {
		sy7758_err("sy7758 not used\n");
		goto err_sysfs;
	} else {
		sy7758_err("sy7758 read 0x%x success, val:%d", sy7758_reg_addr[0], temp);
	}
	/* Testing sy7758-2 used */
	if (sy7758_bl_info.dual_ic) {
		ret = sy7758_2_read_u8(pchip, sy7758_reg_addr[0], &temp, 1);
		if (ret < 0) {
			sy7758_err("sy7758 slave not used\n");
			goto err_sysfs;
		} else {
			sy7758_info("sy7758 read 0x%x : 0x%x\n", sy7758_reg_addr[0], temp);
		}
	}
	ret = of_property_read_u32(np, "sy7758_level_lsb", &sy7758_bl_info.sy7758_level_lsb);
	if (ret < 0) {
		sy7758_err("get sy7758_level_lsb failed\n");
		goto err_sysfs;
	}

	ret = of_property_read_u32(np, "sy7758_level_msb", &sy7758_bl_info.sy7758_level_msb);
	if (ret < 0) {
		sy7758_err("get sy7758_level_msb failed\n");
		goto err_sysfs;
	}
	lcd_kit_bl_register(&bl_ops);

	return ret;

err_sysfs:
	sy7758_debug("sysfs error!\n");
	device_destroy(sy7758_class, 0);
err_out:
	devm_kfree(&client->dev, pchip);
	return ret;
}

static int sy7758_remove(struct i2c_client *client)
{
	if(!client){
		sy7758_err("client is null pointer\n");
		return -1;
	}

	sysfs_remove_group(&client->dev.kobj, &sy7758_group);

	return 0;
}

static const struct i2c_device_id sy7758_id[] = {
	{SY7758_NAME, 0},
	{},
};

static const struct of_device_id sy7758_of_id_table[] = {
	{.compatible = "sy,sy7758"},
	{},
};

MODULE_DEVICE_TABLE(i2c, sy7758_id);
static struct i2c_driver sy7758_i2c_driver = {
		.driver = {
			.name = "sy7758",
			.owner = THIS_MODULE,
			.of_match_table = sy7758_of_id_table,
		},
		.probe = sy7758_probe,
		.remove = sy7758_remove,
		.id_table = sy7758_id,
};

static int __init sy7758_module_init(void)
{
	int ret = -1;

	sy7758_info("in!\n");

	sy7758_class = class_create(THIS_MODULE, "sy7758");
	if (IS_ERR(sy7758_class)) {
		sy7758_err("Unable to create sy7758 class; errno = %ld\n", PTR_ERR(sy7758_class));
		sy7758_class = NULL;
	}

	ret = i2c_add_driver(&sy7758_i2c_driver);
	if (ret)
		sy7758_err("Unable to register sy7758 driver\n");

	sy7758_info("ok!\n");

	return ret;
}
static void __exit sy7758_module_exit(void)
{
	i2c_del_driver(&sy7758_i2c_driver);
}

late_initcall(sy7758_module_init);
module_exit(sy7758_module_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Backlight driver for sy7758");
MODULE_AUTHOR("Honor Device Co., Ltd.");
