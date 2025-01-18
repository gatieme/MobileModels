/*
* Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
* Description: backlight driver of syh62758vgs
* Create: 2023-06-13
*/

#include <linux/module.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/leds.h>
#include <linux/backlight.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/regmap.h>
#include <linux/semaphore.h>
#include <securec.h>
#include "syh62758vgs.h"
#include "dpu_fb.h"
#include "../dpu_fb_panel.h"
#include "dpu_fb_defconfig.h"
#ifdef CONFIG_LCD_KIT_DRIVER
#include "lcd_kit_common.h"
#endif

#define TEST_ERROR_CHIP_INIT syh62758vgs_bit_offset(16)

static struct syh62758vgs_backlight_information syh62758vgs_bl_info;

static struct gpio_desc syh62758vgs_hw_en_on_cmds[] = {
	{ DTYPE_GPIO_REQUEST, WAIT_TYPE_US, 0, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_hw_en_gpio, 0 },
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_hw_en_gpio, 1 },
};

static struct gpio_desc syh62758vgs_2_hw_en_on_cmds[] = {
	{ DTYPE_GPIO_REQUEST, WAIT_TYPE_US, 0, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_2_hw_en_gpio, 0 },
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_2_hw_en_gpio, 1 },
};

#ifdef CONFIG_LCD_KIT_DRIVER
static struct gpio_desc syh62758vgs_hw_en_disable_cmds[] = {
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_US, 0, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_hw_en_gpio, 0 },
	{ DTYPE_GPIO_INPUT, WAIT_TYPE_US, 10, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_hw_en_gpio, 0 },
};

static struct gpio_desc syh62758vgs_2_hw_en_disable_cmds[] = {
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_US, 0, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_2_hw_en_gpio, 0 },
	{ DTYPE_GPIO_INPUT, WAIT_TYPE_US, 10, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_2_hw_en_gpio, 0 },
};

static struct gpio_desc syh62758vgs_hw_en_free_cmds[] = {
	{ DTYPE_GPIO_FREE, WAIT_TYPE_US, 50, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_hw_en_gpio, 0 },
};

static struct gpio_desc syh62758vgs_2_hw_en_free_cmds[] = {
	{ DTYPE_GPIO_FREE, WAIT_TYPE_US, 50, GPIO_SYH62758VGS_EN_NAME,
	  &syh62758vgs_bl_info.syh62758vgs_2_hw_en_gpio, 0 },
};
#endif

static char *syh62758vgs_dts_string[SYH62758VGS_RW_REG_MAX] = {
	"syh62758vgs_device_control", "syh62758vgs_eprom_cfg2","syh62758vgs_eprom_cfg0",
	"syh62758vgs_eprom_cfg1",     "syh62758vgs_eprom_cfg3", "syh62758vgs_eprom_cfg4",
	"syh62758vgs_eprom_cfg5",     "syh62758vgs_eprom_cfg6", "syh62758vgs_eprom_cfg7",
	"syh62758vgs_eprom_cfg9",     "syh62758vgs_eprom_cfgA", "syh62758vgs_eprom_cfgE",
	"syh62758vgs_eprom_cfg9E_2",   "syh62758vgs_led_enable",   "syh62758vgs_eprom_cfg98",
	"syh62758vgs_device_control_2",   "syh62758vgs_eprom_cfg9E_1","syh62758vgs_eprom_cfg9E_2",
};

static unsigned int syh62758vgs_reg_addr[SYH62758VGS_RW_REG_MAX] = {
	SYH62758VGS_DEVICE_CONTROL, SYH62758VGS_EPROM_CFG2, SYH62758VGS_EPROM_CFG0,
	SYH62758VGS_EPROM_CFG1,     SYH62758VGS_EPROM_CFG3, SYH62758VGS_EPROM_CFG4,
	SYH62758VGS_EPROM_CFG5,     SYH62758VGS_EPROM_CFG6, SYH62758VGS_EPROM_CFG7,
	SYH62758VGS_EPROM_CFG9,     SYH62758VGS_EPROM_CFGA, SYH62758VGS_EPROM_CFGE,
	SYH62758VGS_EPROM_CFG9E,   SYH62758VGS_LED_ENABLE, SYH62758VGS_EPROM_CFG98,
	SYH62758VGS_DEVICE_CONTROL,  SYH62758VGS_EPROM_CFG9E,SYH62758VGS_EPROM_CFG9E,
};

struct class *syh62758vgs_class = NULL;
struct syh62758vgs_chip_data *syh62758vgs_g_chip = NULL;
static bool syh62758vgs_init_status = false;
unsigned int syh62758vgs_msg_level = 7;
module_param_named(debug_syh62758vgs_msg_level, syh62758vgs_msg_level, int, 0640);
MODULE_PARM_DESC(debug_syh62758vgs_msg_level, "backlight syh62758vgs msg level");

static int syh62758vgs_parse_dts(struct device_node *np)
{
	int ret = 0;
	int i = 0;

	if (np == NULL) {
		syh62758vgs_err("np is null pointer\n");
		return -1;
	}

	for (i = 0; i < SYH62758VGS_RW_REG_MAX; i++) {
		ret = of_property_read_u32(np, syh62758vgs_dts_string[i],
			&syh62758vgs_bl_info.syh62758vgs_reg[i]);
		if (ret < 0) {
			/* init to invalid data */
			syh62758vgs_bl_info.syh62758vgs_reg[i] = 0xffff;
			syh62758vgs_info("can not find config:%s\n",
				syh62758vgs_dts_string[i]);
		}
	}
	ret = of_property_read_u32(np, "dual_ic", &syh62758vgs_bl_info.dual_ic);
	if (ret < 0)
		syh62758vgs_info("can not get dual_ic dts node\n");

	if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I3C) {
		ret = of_property_read_u32(np, "syh62758vgs_i2c_bus_id",
			&syh62758vgs_bl_info.syh62758vgs_i2c_bus_id);
		if (ret < 0)
			syh62758vgs_info("can not get syh_i2c_bus_id dts node\n");
	} else if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I2C) {
		ret = of_property_read_u32(np, "syh62758vgs_2_i2c_bus_id",
			&syh62758vgs_bl_info.syh62758vgs_2_i2c_bus_id);
		if (ret < 0)
			syh62758vgs_info("can not get syh_2_i2c_bus_id dts node\n");
	}
	ret = of_property_read_u32(np, "syh62758vgs_hw_en_gpio",
		&syh62758vgs_bl_info.syh62758vgs_hw_en_gpio);
	if (ret < 0) {
		syh62758vgs_err("get syh_hw_en_gpio dts config failed\n");
		return ret;
	}
	if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I2C) {
		ret = of_property_read_u32(np, "syh62758vgs_2_hw_en_gpio",
			&syh62758vgs_bl_info.syh62758vgs_2_hw_en_gpio);
		if (ret < 0)
			syh62758vgs_err("get syh_2_hw_en_gpio dts config failed\n");
	}
	ret = of_property_read_u32(np, "bl_on_kernel_mdelay",
		&syh62758vgs_bl_info.bl_on_kernel_mdelay);
	if (ret < 0) {
		syh62758vgs_err("get bl_on_kernel_mdelay dts config failed\n");
		return ret;
	}
	ret = of_property_read_u32(np, "bl_led_num",
		&syh62758vgs_bl_info.bl_led_num);
	if (ret < 0) {
		syh62758vgs_err("get bl_led_num dts config failed\n");
		return ret;
	}
	ret = of_property_read_u32(np, "bl_write_reg_mdelay_1",
		&syh62758vgs_bl_info.bl_write_reg_mdelay_1);
	if (ret < 0) {
		syh62758vgs_err("get bl_write_reg_mdelay_1 dts config failed\n");
		return ret;
	}
	ret = of_property_read_u32(np, "bl_write_reg_mdelay_2",
		&syh62758vgs_bl_info.bl_write_reg_mdelay_2);
	if (ret < 0) {
		syh62758vgs_err("get bl_write_reg_mdelay_2 dts config failed\n");
		return ret;
	}

	return ret;
}

static int syh62758vgs_2_config_write(struct syh62758vgs_chip_data *pchip,
	unsigned int reg[], unsigned int val[], unsigned int size)
{
	struct i2c_adapter *adap = NULL;
	struct i2c_msg msg = {0};
	char buf[2];
	int i2c_bus_id = 0;
	int ret;
	int i;

	if ((pchip == NULL) || (reg == NULL) || (val == NULL) ||
		(pchip->client == NULL)) {
		syh62758vgs_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	syh62758vgs_info("syh_2_config_write\n");
	/* get i2c adapter */
	if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I3C)
		i2c_bus_id = syh62758vgs_bl_info.syh62758vgs_i2c_bus_id;
	else if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I2C)
		i2c_bus_id = syh62758vgs_bl_info.syh62758vgs_2_i2c_bus_id;
	adap = i2c_get_adapter(i2c_bus_id);
	if (!adap) {
		syh62758vgs_err("i2c device %d not found\n", i2c_bus_id);
		ret = -ENODEV;
		goto out;
	}
	msg.addr = pchip->client->addr;
	msg.flags = pchip->client->flags;
	msg.len = 2;
	msg.buf = buf;
	for (i = 0; i < size; i++) {
		buf[0] = reg[i];
		buf[1] = val[i];
		if (val[i] != 0xffff) {
			ret = i2c_transfer(adap, &msg, 1);
			syh62758vgs_info("syh_2_config_write reg=0x%x,val=0x%x\n",
				buf[0], buf[1]);
		}
	}
out:
	i2c_put_adapter(adap);
	return ret;
}

static int syh62758vgs_config_write(struct syh62758vgs_chip_data *pchip,
	unsigned int reg[], unsigned int val[], unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if ((pchip == NULL) || (reg == NULL) || (val == NULL)) {
		syh62758vgs_err("pchip or reg or val is null pointer\n");
		return -1;
	}

	for (i = 0; i < size; i++) {
		/* judge reg is invalid */
		if (val[i] != 0xffff) {
			ret = regmap_write(pchip->regmap, reg[i], val[i]);
			if (ret < 0) {
				syh62758vgs_err("write syh backlight config register 0x%x failed\n",
					reg[i]);
				goto exit;
			}
			if (reg[i] == SYH62758VGS_DEVICE_CONTROL && val[i] == SYH62758VGS_DEVICE_CONTROL_VAL)
				mdelay(syh62758vgs_bl_info.bl_write_reg_mdelay_2);
			if (reg[i] == SYH62758VGS_EPROM_CFG9E && val[i] == SYH62758VGS_EPROM_CFG9E_VAL)
				mdelay(syh62758vgs_bl_info.bl_write_reg_mdelay_1);
		}
	}

exit:
	return ret;
}

static int syh62758vgs_config_read(struct syh62758vgs_chip_data *pchip,
		unsigned int reg[], unsigned int val[], unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if ((pchip == NULL) || (reg == NULL) || (val == NULL)) {
		syh62758vgs_err("pchip or reg or val is null pointer\n");
		return -1;
	}

	for (i = 0; i < size; i++) {
		ret = regmap_read(pchip->regmap, reg[i], &val[i]);
		if (ret < 0) {
			syh62758vgs_err("read syh62758vgs backlight config register 0x%x failed",
				reg[i]);
			goto exit;
		} else {
			syh62758vgs_info("read 0x%x value = 0x%x\n", reg[i], val[i]);
		}
	}

exit:
	return ret;
}

/* initialize chip */
static int syh62758vgs_chip_init(struct syh62758vgs_chip_data *pchip)
{
	int ret = -1;

	syh62758vgs_info("in!\n");

	if (pchip == NULL) {
		syh62758vgs_err("pchip is null pointer\n");
		return -1;
	}
	if (syh62758vgs_bl_info.dual_ic) {
		ret = syh62758vgs_2_config_write(pchip, syh62758vgs_reg_addr,
			syh62758vgs_bl_info.syh62758vgs_reg, SYH62758VGS_RW_REG_MAX);
		if (ret < 0) {
			syh62758vgs_err("syh slave config register failed\n");
			goto out;
		}
	}
	ret = syh62758vgs_config_write(pchip, syh62758vgs_reg_addr,
		syh62758vgs_bl_info.syh62758vgs_reg, SYH62758VGS_RW_REG_MAX);
	if (ret < 0) {
		syh62758vgs_err("syh62758vgs config register failed");
		goto out;
	}
	syh62758vgs_info("ok!\n");
	return ret;

out:
	dev_err(pchip->dev, "i2c failed to access register\n");
	return ret;
}

static ssize_t syh62758vgs_reg_show(struct device *dev,
			struct device_attribute *attr, char *buf)
{
	struct syh62758vgs_chip_data *pchip = NULL;
	struct i2c_client *client = NULL;
	ssize_t ret = -1;

	if (!buf) {
		syh62758vgs_err("buf is null\n");
		return ret;
	}

	if (!dev) {
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "dev is null\n");
		return ret;
	}

	pchip = dev_get_drvdata(dev);
	if (!pchip) {
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "data is null\n");
		return ret;
	}

	client = pchip->client;
	if (!client) {
		ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "client is null\n");
		return ret;
	}

	ret = syh62758vgs_config_read(pchip, syh62758vgs_reg_addr,
		syh62758vgs_bl_info.syh62758vgs_reg, SYH62758VGS_RW_REG_MAX);
	if (ret < 0) {
		syh62758vgs_err("syh62758vgs config read failed");
		goto i2c_error;
	}

	ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1,
		"Device control(0x01)= 0x%x\nEprom Configuration0(0xA2) = 0x%x\n \
		\rEprom Configuration0(0xA0) = 0x%x\nEprom Configuration1(0xA1) = 0x%x\n \
		\rEprom Configuration3(0xA3) = 0x%x\nEprom Configuration4(0xA4) = 0x%x\n \
		\rEprom Configuration5(0xA5) = 0x%x\nEprom Configuration6(0xA6) = 0x%x\n \
		\rEprom Configuration7(0xA7)  = 0x%x\nEprom Configuration9(0xA9)  = 0x%x\n \
		\rEprom ConfigurationA(0xAA) = 0x%x\nEprom ConfigurationE(0xAE) = 0x%x\n \
		\rEprom Configuration9E(0x9E) = 0x%x\nLed enable(0x16) = 0x%x\n \
		\rEprom Configuration98(0x98) = 0x%x\nDevice control(0x01)= 0x%x\n \
		\rEprom Configuration9E(0x9E) = 0x%x\nEprom Configuration9E(0x9E) = 0x%x\n",
		syh62758vgs_bl_info.syh62758vgs_reg[0], syh62758vgs_bl_info.syh62758vgs_reg[1],
		syh62758vgs_bl_info.syh62758vgs_reg[2], syh62758vgs_bl_info.syh62758vgs_reg[3],
		syh62758vgs_bl_info.syh62758vgs_reg[4], syh62758vgs_bl_info.syh62758vgs_reg[5],
		syh62758vgs_bl_info.syh62758vgs_reg[6], syh62758vgs_bl_info.syh62758vgs_reg[7],
		syh62758vgs_bl_info.syh62758vgs_reg[8], syh62758vgs_bl_info.syh62758vgs_reg[9],
		syh62758vgs_bl_info.syh62758vgs_reg[10], syh62758vgs_bl_info.syh62758vgs_reg[11],
		syh62758vgs_bl_info.syh62758vgs_reg[12], syh62758vgs_bl_info.syh62758vgs_reg[13],
		syh62758vgs_bl_info.syh62758vgs_reg[14], syh62758vgs_bl_info.syh62758vgs_reg[15],
		syh62758vgs_bl_info.syh62758vgs_reg[16], syh62758vgs_bl_info.syh62758vgs_reg[17]
		);
	return ret;

i2c_error:
	ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1,
		"%s: i2c access fail to register\n", __func__);
	return ret;
}

static ssize_t syh62758vgs_reg_store(struct device *dev,
		struct device_attribute *dev_attr, const char *buf, size_t size)
{
	ssize_t ret;
	struct syh62758vgs_chip_data *pchip = NULL;
	unsigned int reg = 0;
	unsigned int mask = 0;
	unsigned int val = 0;

	if (!buf) {
		syh62758vgs_err("buf is null\n");
		return -1;
	}

	if (!dev) {
		syh62758vgs_err("dev is null\n");
		return -1;
	}

	pchip = dev_get_drvdata(dev);
	if (!pchip) {
		syh62758vgs_err("pchip is null\n");
		return -1;
	}

	ret = sscanf_s(buf, "reg=0x%x, mask=0x%x, val=0x%x", &reg, &mask, &val);
	if (ret < 0) {
		syh62758vgs_info("check your input!!!\n");
		goto out_input;
	}

	syh62758vgs_err("%s:reg=0x%x, mask=0x%x, val=0x%x\n",
		__func__, reg, mask, val);

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

static DEVICE_ATTR(reg, 0644, syh62758vgs_reg_show, syh62758vgs_reg_store);

/* pointers to created device attributes */
static struct attribute *syh62758vgs_attributes[] = {
	&dev_attr_reg.attr,
	NULL,
};

static const struct attribute_group syh62758vgs_group = {
	.attrs = syh62758vgs_attributes,
};

static const struct regmap_config syh62758vgs_regmap = {
	.reg_bits = 8,
	.val_bits = 8,
	.reg_stride = 1,
};

#ifdef CONFIG_LCD_KIT_DRIVER
#include "lcd_kit_common.h"

static void syh62758vgs_enable(void)
{
	int ret = 0;

	mdelay(syh62758vgs_bl_info.bl_on_kernel_mdelay);
	gpio_cmds_tx(syh62758vgs_hw_en_on_cmds, ARRAY_SIZE(syh62758vgs_hw_en_on_cmds));
	if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I2C)
		gpio_cmds_tx(syh62758vgs_2_hw_en_on_cmds,
			ARRAY_SIZE(syh62758vgs_2_hw_en_on_cmds));
	/* chip initialize */
	ret = syh62758vgs_chip_init(syh62758vgs_g_chip);
	if (ret < 0) {
		syh62758vgs_err("syh62758vgs_chip_init fail!\n");
		return;
	}
	syh62758vgs_init_status = true;
}

static void syh62758vgs_disable(void)
{
	gpio_cmds_tx(syh62758vgs_hw_en_disable_cmds,
		ARRAY_SIZE(syh62758vgs_hw_en_disable_cmds));
	gpio_cmds_tx(syh62758vgs_hw_en_free_cmds,
		ARRAY_SIZE(syh62758vgs_hw_en_free_cmds));
	if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I2C) {
		gpio_cmds_tx(syh62758vgs_2_hw_en_disable_cmds,
			ARRAY_SIZE(syh62758vgs_2_hw_en_disable_cmds));
		gpio_cmds_tx(syh62758vgs_2_hw_en_free_cmds,
			ARRAY_SIZE(syh62758vgs_2_hw_en_free_cmds));
	}
	syh62758vgs_init_status = false;
}

static int syh62758vgs_set_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int bl_msb = 0;
	int bl_lsb = 0;
	int ret = 0;

	if (!syh62758vgs_g_chip) {
		syh62758vgs_err("syh62758vgs_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(syh62758vgs_g_chip->test_sem))) {
		syh62758vgs_info("Now in test mode\n");
		return 0;
	}
	/* first set backlight, enable syh62758vgs */
	if (false == syh62758vgs_init_status && bl_level > 0)
		syh62758vgs_enable();

	/* set backlight level */
	bl_msb = (bl_level >> 8) & 0x0F;
	bl_lsb = bl_level & 0xFF;
	ret = regmap_write(syh62758vgs_g_chip->regmap,
		syh62758vgs_bl_info.syh62758vgs_level_lsb, bl_lsb);
	if (ret < 0)
		syh62758vgs_debug("write syh62758vgs backlight level lsb:0x%x failed\n",bl_lsb);
	ret = regmap_write(syh62758vgs_g_chip->regmap,syh62758vgs_bl_info.syh62758vgs_level_msb, bl_msb);
	if (ret < 0)
		syh62758vgs_debug("write syh62758vgs backlight level msb:0x%x failed\n",bl_msb);
	/* if set backlight level 0, disable syh62758vgs */
	if (true == syh62758vgs_init_status && 0 == bl_level)
		syh62758vgs_disable();
	up(&(syh62758vgs_g_chip->test_sem));

	last_bl_level = bl_level;
	return ret;
}

static int syh62758vgs_en_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int ret = 0;

	if (!syh62758vgs_g_chip) {
		syh62758vgs_err("syh62758vgs_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(syh62758vgs_g_chip->test_sem))) {
		syh62758vgs_info("Now in test mode\n");
		return 0;
	}
	syh62758vgs_info("%s bl_level=%d\n", __func__, bl_level);
	/* first set backlight, enable syh62758vgs */
	if (false == syh62758vgs_init_status && bl_level > 0)
		syh62758vgs_enable();

	/* if set backlight level 0, disable syh62758vgs */
	if (true == syh62758vgs_init_status && 0 == bl_level)
		syh62758vgs_disable();
	up(&(syh62758vgs_g_chip->test_sem));

	last_bl_level = bl_level;
	return ret;
}

static int syh62758vgs_backlight_save_restore(int save_enable)
{
	static int bl_msb = 0;
	static int bl_lsb = 0;
	int ret = 0;
	unsigned int val = 0;

	if (save_enable) {
		ret = regmap_read(syh62758vgs_g_chip->regmap,syh62758vgs_bl_info.syh62758vgs_level_lsb, &val);
		if (ret < 0) {
			syh62758vgs_err("write syh backlight level msb:0x%x failed\n",
				bl_msb);
			return -1;
		}
		bl_lsb = val & 0xFF;
		ret = regmap_read(syh62758vgs_g_chip->regmap,
			syh62758vgs_bl_info.syh62758vgs_level_msb, &val);
		if (ret < 0) {
			syh62758vgs_err("write syh backlight level msb:0x%x failed\n",
				bl_msb);
			return -1;
		}
		bl_msb = val & 0x0F;
	} else {
		ret = regmap_write(syh62758vgs_g_chip->regmap,
			syh62758vgs_bl_info.syh62758vgs_level_lsb, bl_lsb);
		if (ret < 0) {
			syh62758vgs_err("write syh backlight level lsb:0x%x failed\n",bl_lsb);
			return -1;
		}
		ret = regmap_write(syh62758vgs_g_chip->regmap,
			syh62758vgs_bl_info.syh62758vgs_level_msb, bl_msb);
		if (ret < 0) {
			syh62758vgs_err("write syh backlight level msb:0x%x failed\n",bl_msb);
			return -1;
		}
	}
	return ret;
}

static unsigned int syh62758vgs_test_led_open(struct syh62758vgs_chip_data *pchip, int led_num)
{
	int ret;
	unsigned int i;
	unsigned int result = TEST_OK;
	unsigned int val = 0;
	unsigned int enable_leds = SYH62758VGS_ENABLE_ALL_LEDS;
	int bl_led_num = syh62758vgs_bl_info.bl_led_num;

	for (i = bl_led_num; i < SYH62758VGS_LED_NUM; i++)
		enable_leds &= ~(unsigned int)(1 << i);
	/* Enable all LED strings */
	ret = regmap_write(pchip->regmap, SYH62758VGS_LED_ENABLE, enable_leds);
	if (ret < 0) {
		syh62758vgs_err("TEST_ERROR_I2C\n");
		return TEST_ERROR_I2C;
	}

	/* Set maximum brightness */
	syh62758vgs_set_backlight(SYH62758VGS_BL_MAX);

	/* Open LEDx string. */

	ret = regmap_write(pchip->regmap, SYH62758VGS_LED_ENABLE,
		(~(unsigned int)(1 << (unsigned int)led_num)) & enable_leds);
	if (ret < 0) {
		syh62758vgs_err("TEST_ERROR_I2C\n");
		return TEST_ERROR_I2C;
	}

	/* Wait 4 msec. */
	usleep_range(4000, 4001);

	/* Read LED open fault */
	ret = regmap_read(pchip->regmap, SYH62758VGS_FUALT_FLAG, &val);
	if (ret < 0) {
		syh62758vgs_err("TEST_ERROR_I2C\n");
		return TEST_ERROR_I2C;
	}

	/* If then a LED open fault condition has been detected. */
	if (val & (1 << SYH62758VGS_FAULT_OPEN_BIT))
		result |= (1 << (SYH62758VGS_LED1_OPEN_ERR_BIT + led_num));

	/* Connect LEDx string. */
	ret = regmap_write(pchip->regmap, SYH62758VGS_LED_ENABLE, enable_leds);
	if (ret < 0) {
		syh62758vgs_err("TEST_ERROR_I2C\n");
		return result | TEST_ERROR_I2C;
	}

	/* Repeat the procedure for the other LED strings. */
	msleep(1000);
	return result;
}

static unsigned int syh62758vgs_test_led_short(struct syh62758vgs_chip_data *pchip, int led_num)
{
	unsigned int val = 0;
	int ret;
	unsigned int result = TEST_OK;

	/* Enable only LEDx string. */
	ret = regmap_write(pchip->regmap, SYH62758VGS_LED_ENABLE,
		(1 << (unsigned int)led_num));
	if (ret < 0) {
		syh62758vgs_err("TEST_ERROR_I2C\n");
		return TEST_ERROR_I2C;
	}

	/* Set maximum brightness. */
	syh62758vgs_set_backlight(SYH62758VGS_BL_MAX);

	/* Wait 4 msec. */
	usleep_range(4000, 4001);

	/* Read LED short fault */
	ret = regmap_read(pchip->regmap, SYH62758VGS_FUALT_FLAG, &val);
	if (ret < 0) {
		syh62758vgs_err("TEST_ERROR_I2C\n");
		return TEST_ERROR_I2C;
	}

	/* A LED short fault condition has been detected. */
	if (val & (1 << SYH62758VGS_FAULT_SHORT_BIT))
		result |= (1 << (SYH62758VGS_LED1_SHORT_ERR_BIT + led_num));

	/* Set chip enable and LED string enable low. */
	ret = regmap_write(pchip->regmap, SYH62758VGS_LED_ENABLE,
		SYH62758VGS_DISABLE_ALL_LEDS);
	if (ret < 0) {
		syh62758vgs_err("TEST_ERROR_I2C\n");
		return result | TEST_ERROR_I2C;
	}

	/* Repeat the procedure for the other LED Strings */
	msleep(1000);
	return result;
}

static ssize_t syh62758vgs_self_test(void)
{
	struct syh62758vgs_chip_data *pchip = NULL;
	struct i2c_client *client = NULL;
	ssize_t ret = -1;
	unsigned int result = 0;
	int syh62758vgs_regs[SYH62758VGS_RW_REG_MAX] = {0};
	int led_num = syh62758vgs_bl_info.bl_led_num;
	int i;

	pchip = syh62758vgs_g_chip;
	if (!pchip) {
		syh62758vgs_err("pchip is null\n");
		return -1;
	}

	client = pchip->client;
	if (!client)
		syh62758vgs_err("client is null\n");

	down(&(pchip->test_sem));
	ret = syh62758vgs_config_read(pchip, syh62758vgs_reg_addr,syh62758vgs_regs, SYH62758VGS_RW_REG_MAX);
	if (ret) {
		result |= TEST_ERROR_I2C;
		goto syh62758vgs_test_failed;
	}
	ret = syh62758vgs_backlight_save_restore(1);
	if (ret) {
		result |= TEST_ERROR_I2C;
		goto syh62758vgs_test_failed;
	}

	for (i = 0; i < led_num; i++)
		result |= syh62758vgs_test_led_open(pchip, i);

	for (i = 0; i < led_num; i++)
		result |= syh62758vgs_test_led_short(pchip, i);

	ret = syh62758vgs_chip_init(pchip);
	if (ret < 0) {
		result |= TEST_ERROR_CHIP_INIT;
		goto syh62758vgs_test_failed;
	}

	ret = syh62758vgs_config_write(pchip, syh62758vgs_reg_addr,syh62758vgs_regs, SYH62758VGS_RW_REG_MAX);
	if (ret) {
		result |= TEST_ERROR_I2C;
		goto syh62758vgs_test_failed;
	}
	ret = syh62758vgs_backlight_save_restore(0);
	if (ret) {
		result |= TEST_ERROR_I2C;
		goto syh62758vgs_test_failed;
	}

	up(&(pchip->test_sem));
	syh62758vgs_info("self test out:%d\n", result);
	return result;
syh62758vgs_test_failed:
	up(&(pchip->test_sem));
	syh62758vgs_info("self test out:%d\n", result);
	return result;
}

static void syh62758vgs_dsm_notify(int val)
{
#if defined(CONFIG_HUAWEI_DSM)
	if (lcd_dclient && !dsm_client_ocuppy(lcd_dclient)) {
		dsm_client_record(lcd_dclient,
			"syh62758vgs happen short, reg:0x02 value is:0x%x\n", val);
		dsm_client_notify(lcd_dclient, DSM_LCD_OVP_ERROR_NO);
	} else {
		syh62758vgs_err("dsm_client_ocuppy fail!\n");
	}
#endif
}

static int syh62758vgs_check_backlight(void)
{
#define CHECK_COUNT 3
#define CHECK_REG 0x02
#define CHECK_VAL 0x04
#define CHECK_VAL_FACTORY 0xC4
	int count = 0;
	int val = 0;
	int ret = 0;
	int err_cnt = 0;

	if (!syh62758vgs_g_chip) {
		syh62758vgs_err("syh62758vgs_g_chip is null\n");
		return -1;
	}
	/* judge syh62758vgs is enable, if not return */
	if (syh62758vgs_init_status == false) {
		syh62758vgs_err("syh62758vgs not enable\n");
		ret = -1;
		goto error;
	}

	while (count < CHECK_COUNT) {
		ret = regmap_read(syh62758vgs_g_chip->regmap, CHECK_REG, &val);
		if (ret < 0) {
			syh62758vgs_err("read syh62758vgs fail!\n");
			goto error;
		}
		if (runmode_is_factory()) {
			if (val & CHECK_VAL_FACTORY) {
				err_cnt++;
				syh62758vgs_err("check val:0x%x, backlight maybe short!\n",val);
			}
		} else {
			if (val & CHECK_VAL) {
				err_cnt++;
				syh62758vgs_err("check val:0x%x, backlight maybe short!\n",val);
			}
		}
		count++;
		mdelay(3);
	}
	if (err_cnt == CHECK_COUNT) {
		/* backlight short, shutdown backlight */
		syh62758vgs_err("backlight short, shutdown backlight!\n");
		gpio_cmds_tx(syh62758vgs_hw_en_disable_cmds,ARRAY_SIZE(syh62758vgs_hw_en_disable_cmds));
		gpio_cmds_tx(syh62758vgs_hw_en_free_cmds,ARRAY_SIZE(syh62758vgs_hw_en_free_cmds));
		if (syh62758vgs_bl_info.dual_ic == DUAL_SYH62758VGS_I2C) {
			gpio_cmds_tx(syh62758vgs_2_hw_en_disable_cmds,
				ARRAY_SIZE(syh62758vgs_2_hw_en_disable_cmds));
			gpio_cmds_tx(syh62758vgs_2_hw_en_free_cmds,
				ARRAY_SIZE(syh62758vgs_2_hw_en_free_cmds));
		}
		syh62758vgs_dsm_notify(val);
		ret = -1;
		goto error;
	}
error:
	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = syh62758vgs_set_backlight,
	.en_backlight = syh62758vgs_en_backlight,
	.bl_self_test = syh62758vgs_self_test,
	.check_backlight = syh62758vgs_check_backlight,
	.name = "62758",
};
#endif

static int syh62758vgs_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = NULL;
	struct syh62758vgs_chip_data *pchip = NULL;
	int ret = -1;
	struct device_node *np = NULL;

	syh62758vgs_info("in!\n");

	if (!client) {
		syh62758vgs_err("client is null pointer\n");
		return -1;
	}
	adapter = client->adapter;

	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "i2c functionality check fail.\n");
		return -EOPNOTSUPP;
	}

	pchip = devm_kzalloc(&client->dev,
		sizeof(struct syh62758vgs_chip_data), GFP_KERNEL);
	if (!pchip)
		return -ENOMEM;

#ifdef CONFIG_REGMAP_I2C
	pchip->regmap = devm_regmap_init_i2c(client, &syh62758vgs_regmap);
	if (IS_ERR(pchip->regmap)) {
		ret = PTR_ERR(pchip->regmap);
		dev_err(&client->dev, "fail : allocate register map: %d\n", ret);
		goto err_out;
	} else {
		syh62758vgs_info("sucess : allocate register map");
	}
#endif

	syh62758vgs_g_chip = pchip;
	pchip->client = client;
	i2c_set_clientdata(client, pchip);

	sema_init(&(pchip->test_sem), 1);

	pchip->dev = device_create(syh62758vgs_class, NULL, 0, "%s", client->name);
	if (IS_ERR(pchip->dev)) {
		/* Not fatal */
		syh62758vgs_err("Unable to create device; errno = %ld\n", PTR_ERR(pchip->dev));
		pchip->dev = NULL;
	} else {
		dev_set_drvdata(pchip->dev, pchip);
		ret = sysfs_create_group(&pchip->dev->kobj, &syh62758vgs_group);
		if (ret)
			goto err_sysfs;
	}

	memset_s(&syh62758vgs_bl_info, sizeof(struct syh62758vgs_backlight_information),
		0, sizeof(struct syh62758vgs_backlight_information));

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_SYH62758VGS);
	if (!np) {
		syh62758vgs_err("NOT FOUND device node %s!\n", DTS_COMP_SYH62758VGS);
		goto err_sysfs;
	}

	ret = syh62758vgs_parse_dts(np);
	if (ret < 0) {
		syh62758vgs_err("parse syh dts failed");
		goto err_sysfs;
	}

#ifdef CONFIG_LCD_KIT_DRIVER
	int val = 0;
	/* Only testing syh62758vgs used */
	ret = regmap_read(pchip->regmap, syh62758vgs_reg_addr[0],
		&syh62758vgs_bl_info.syh62758vgs_reg[0]);
	if (ret < 0) {
		syh62758vgs_err("syh not used\n");
		goto err_sysfs;
	}
	/* Testing syh62758vgs-2 used */
	if (syh62758vgs_bl_info.dual_ic) {
		ret = syh62758vgs_2_config_write(pchip, syh62758vgs_reg_addr,
			syh62758vgs_bl_info.syh62758vgs_reg, 1);
		if (ret < 0) {
			syh62758vgs_err("syh slave not used\n");
			goto err_sysfs;
		}
	}
	ret = of_property_read_u32(np, "syh62758vgs_level_lsb",
		&syh62758vgs_bl_info.syh62758vgs_level_lsb);
	if (ret < 0) {
		syh62758vgs_err("get syh62758vgs_level_lsb failed\n");
		goto err_sysfs;
	}

	ret = of_property_read_u32(np, "syh62758vgs_level_msb",
		&syh62758vgs_bl_info.syh62758vgs_level_msb);
	if (ret < 0) {
		syh62758vgs_err("get syh62758vgs_level_msb failed\n");
		goto err_sysfs;
	}
	ret = regmap_read(pchip->regmap, SYH62758VGS_FUALT_FLAG, &val);
	if (val & (1 << SYH62758VGS_LED1_OPEN_ERR_BIT))
		syh62758vgs_init_status = true;
	lcd_kit_bl_register(&bl_ops);
#endif

	return ret;

err_sysfs:
	syh62758vgs_debug("sysfs error!\n");
	device_destroy(syh62758vgs_class, 0);
err_out:
	devm_kfree(&client->dev, pchip);
	return ret;
}

static int syh62758vgs_remove(struct i2c_client *client)
{
	if (!client) {
		syh62758vgs_err("client is null pointer\n");
		return -1;
	}
	sysfs_remove_group(&client->dev.kobj, &syh62758vgs_group);
	return 0;
}

static const struct i2c_device_id syh62758vgs_id[] = {
	{SYH62758VGS_NAME, 0},
	{},
};

static const struct of_device_id syh62758vgs_of_id_table[] = {
	{.compatible = "syh,syh62758vgs"},
	{},
};

MODULE_DEVICE_TABLE(i2c, syh62758vgs_id);
static struct i2c_driver syh62758vgs_i2c_driver = {
	.driver = {
		.name = "syh62758vgs",
		.owner = THIS_MODULE,
		.of_match_table = syh62758vgs_of_id_table,
	},
	.probe = syh62758vgs_probe,
	.remove = syh62758vgs_remove,
	.id_table = syh62758vgs_id,
};

static int __init syh62758vgs_module_init(void)
{
	int ret = -1;

	syh62758vgs_info("in!\n");

	syh62758vgs_class = class_create(THIS_MODULE, "syh62758vgs");
	if (IS_ERR(syh62758vgs_class)) {
		syh62758vgs_err("Unable to create syh class; errno = %ld\n",
			PTR_ERR(syh62758vgs_class));
		syh62758vgs_class = NULL;
	}

	ret = i2c_add_driver(&syh62758vgs_i2c_driver);
	if (ret)
		syh62758vgs_err("Unable to register syh driver\n");

	syh62758vgs_info("ok!\n");

	return ret;
}
late_initcall(syh62758vgs_module_init);
