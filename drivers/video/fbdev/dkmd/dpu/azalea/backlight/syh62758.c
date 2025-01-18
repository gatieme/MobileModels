/*
* Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
* Description: backlight driver of syh62758
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
#include "syh62758.h"
#include "dpu_fb.h"
#include "../dpu_fb_panel.h"
#include "dpu_fb_defconfig.h"
#ifdef CONFIG_LCD_KIT_DRIVER
#include "lcd_kit_common.h"
#endif

#define TEST_ERROR_CHIP_INIT bit(16)

static struct syh62758_backlight_information syh62758_bl_info;

static struct gpio_desc syh62758_hw_en_on_cmds[] = {
	{ DTYPE_GPIO_REQUEST, WAIT_TYPE_US, 0, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_hw_en_gpio, 0 },
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_hw_en_gpio, 1 },
};

static struct gpio_desc syh62758_2_hw_en_on_cmds[] = {
	{ DTYPE_GPIO_REQUEST, WAIT_TYPE_US, 0, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_2_hw_en_gpio, 0 },
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_2_hw_en_gpio, 1 },
};

#ifdef CONFIG_LCD_KIT_DRIVER
static struct gpio_desc syh62758_hw_en_disable_cmds[] = {
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_US, 0, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_hw_en_gpio, 0 },
	{ DTYPE_GPIO_INPUT, WAIT_TYPE_US, 10, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_hw_en_gpio, 0 },
};

static struct gpio_desc syh62758_2_hw_en_disable_cmds[] = {
	{ DTYPE_GPIO_OUTPUT, WAIT_TYPE_US, 0, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_2_hw_en_gpio, 0 },
	{ DTYPE_GPIO_INPUT, WAIT_TYPE_US, 10, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_2_hw_en_gpio, 0 },
};

static struct gpio_desc syh62758_hw_en_free_cmds[] = {
	{ DTYPE_GPIO_FREE, WAIT_TYPE_US, 50, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_hw_en_gpio, 0 },
};

static struct gpio_desc syh62758_2_hw_en_free_cmds[] = {
	{ DTYPE_GPIO_FREE, WAIT_TYPE_US, 50, GPIO_SYH62758_EN_NAME,
	  &syh62758_bl_info.syh62758_2_hw_en_gpio, 0 },
};
#endif

static char *syh62758_dts_string[SYH62758_RW_REG_MAX] = {
	"syh62758_device_control", "syh62758_led_enable",
};

static unsigned int syh62758_reg_addr[SYH62758_RW_REG_MAX] = {
	SYH62758_DEVICE_CONTROL, SYH62758_LED_ENABLE,
};

struct class *syh62758_class = NULL;
struct syh62758_chip_data *syh62758_g_chip = NULL;
static bool syh62758_init_status = false;
unsigned int syh62758_msg_level = 7;

static int syh62758_parse_dts(struct device_node *np)
{
	int ret = 0;
	int i = 0;

	if (np == NULL) {
		syh62758_err("np is null pointer\n");
		return -1;
	}

	for (i = 0; i < SYH62758_RW_REG_MAX; i++) {
		ret = of_property_read_u32(np, syh62758_dts_string[i],
			&syh62758_bl_info.syh62758_reg[i]);
		if (ret < 0) {
			/* init to invalid data */
			syh62758_bl_info.syh62758_reg[i] = 0xffff;
			syh62758_info("can not find config:%s\n",
				syh62758_dts_string[i]);
		}
	}
	ret = of_property_read_u32(np, "dual_ic", &syh62758_bl_info.dual_ic);
	if (ret < 0)
		syh62758_info("can not get dual_ic dts node\n");

	if (syh62758_bl_info.dual_ic == DUAL_SYH62758_I3C) {
		ret = of_property_read_u32(np, "syh62758_i2c_bus_id",
			&syh62758_bl_info.syh62758_i2c_bus_id);
		if (ret < 0)
			syh62758_info("can not get syh_i2c_bus_id dts node\n");
	} else if (syh62758_bl_info.dual_ic == DUAL_SYH62758_I2C) {
		ret = of_property_read_u32(np, "syh62758_2_i2c_bus_id",
			&syh62758_bl_info.syh62758_2_i2c_bus_id);
		if (ret < 0)
			syh62758_info("can not get syh_2_i2c_bus_id dts node\n");
	}
	ret = of_property_read_u32(np, "syh62758_hw_en_gpio",
		&syh62758_bl_info.syh62758_hw_en_gpio);
	if (ret < 0) {
		syh62758_err("get syh_hw_en_gpio dts config failed\n");
		return ret;
	}
	if (syh62758_bl_info.dual_ic == DUAL_SYH62758_I2C) {
		ret = of_property_read_u32(np, "syh62758_2_hw_en_gpio",
			&syh62758_bl_info.syh62758_2_hw_en_gpio);
		if (ret < 0)
			syh62758_err("get syh_2_hw_en_gpio dts config failed\n");
	}
	ret = of_property_read_u32(np, "bl_on_kernel_mdelay",
		&syh62758_bl_info.bl_on_kernel_mdelay);
	if (ret < 0) {
		syh62758_err("get bl_on_kernel_mdelay dts config failed\n");
		return ret;
	}
	ret = of_property_read_u32(np, "bl_led_num",
		&syh62758_bl_info.bl_led_num);
	if (ret < 0) {
		syh62758_err("get bl_led_num dts config failed\n");
		return ret;
	}

	return ret;
}

static int syh62758_2_config_write(struct syh62758_chip_data *pchip,
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
		syh62758_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	syh62758_info("syh_2_config_write\n");
	/* get i2c adapter */
	if (syh62758_bl_info.dual_ic == DUAL_SYH62758_I3C)
		i2c_bus_id = syh62758_bl_info.syh62758_i2c_bus_id;
	else if (syh62758_bl_info.dual_ic == DUAL_SYH62758_I2C)
		i2c_bus_id = syh62758_bl_info.syh62758_2_i2c_bus_id;
	adap = i2c_get_adapter(i2c_bus_id);
	if (!adap) {
		syh62758_err("i2c device %d not found\n", i2c_bus_id);
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
			syh62758_info("syh_2_config_write reg=0x%x,val=0x%x\n",
				buf[0], buf[1]);
		}
	}
out:
	i2c_put_adapter(adap);
	return ret;
}

static int syh62758_config_write(struct syh62758_chip_data *pchip,
	unsigned int reg[], unsigned int val[], unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if ((pchip == NULL) || (reg == NULL) || (val == NULL)) {
		syh62758_err("pchip or reg or val is null pointer\n");
		return -1;
	}

	for (i = 0; i < size; i++) {
		/* judge reg is invalid */
		if (val[i] != 0xffff) {
			ret = regmap_write(pchip->regmap, reg[i], val[i]);
			if (ret < 0) {
				syh62758_err("write syh backlight config register 0x%x failed\n",
					reg[i]);
				goto exit;
			}
		}
	}

exit:
	return ret;
}

/* initialize chip */
static int syh62758_chip_init(struct syh62758_chip_data *pchip)
{
	int ret = -1;

	syh62758_info("in!\n");

	if (pchip == NULL) {
		syh62758_err("pchip is null pointer\n");
		return -1;
	}
	if (syh62758_bl_info.dual_ic) {
		ret = syh62758_2_config_write(pchip, syh62758_reg_addr,
			syh62758_bl_info.syh62758_reg, SYH62758_RW_REG_MAX);
		if (ret < 0) {
			syh62758_err("syh slave config register failed\n");
			goto out;
		}
	}
	ret = syh62758_config_write(pchip, syh62758_reg_addr,
		syh62758_bl_info.syh62758_reg, SYH62758_RW_REG_MAX);
	if (ret < 0) {
		syh62758_err("syh config register failed");
		goto out;
	}
	syh62758_info("ok!\n");
	return ret;

out:
	dev_err(pchip->dev, "i2c failed to access register\n");
	return ret;
}

static const struct regmap_config syh62758_regmap = {
	.reg_bits = 8,
	.val_bits = 8,
	.reg_stride = 1,
};

#ifdef CONFIG_LCD_KIT_DRIVER
static void syh62758_enable(void)
{
	int ret = 0;

	mdelay(syh62758_bl_info.bl_on_kernel_mdelay);
	gpio_cmds_tx(syh62758_hw_en_on_cmds, ARRAY_SIZE(syh62758_hw_en_on_cmds));
	if (syh62758_bl_info.dual_ic == DUAL_SYH62758_I2C)
		gpio_cmds_tx(syh62758_2_hw_en_on_cmds,
			ARRAY_SIZE(syh62758_2_hw_en_on_cmds));
	/* chip initialize */
	ret = syh62758_chip_init(syh62758_g_chip);
	if (ret < 0) {
		syh62758_err("syh_chip_init fail!\n");
		return;
	}
	syh62758_init_status = true;
}

static void syh62758_disable(void)
{
	gpio_cmds_tx(syh62758_hw_en_disable_cmds,
		ARRAY_SIZE(syh62758_hw_en_disable_cmds));
	gpio_cmds_tx(syh62758_hw_en_free_cmds,
		ARRAY_SIZE(syh62758_hw_en_free_cmds));
	if (syh62758_bl_info.dual_ic == DUAL_SYH62758_I2C) {
		gpio_cmds_tx(syh62758_2_hw_en_disable_cmds,
			ARRAY_SIZE(syh62758_2_hw_en_disable_cmds));
		gpio_cmds_tx(syh62758_2_hw_en_free_cmds,
			ARRAY_SIZE(syh62758_2_hw_en_free_cmds));
	}
	syh62758_init_status = false;
}

static int syh62758_en_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int ret = 0;
	int panel_id = get_panel_id();

	if (!syh62758_g_chip) {
		syh62758_err("syh_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(syh62758_g_chip->test_sem))) {
		syh62758_info("Now in test mode\n");
		return 0;
	}
	syh62758_info("%s bl_level=%d\n", __func__, bl_level);
	/* first set backlight, enable syh62758 */
	if (false == syh62758_init_status && bl_level > 0)
		syh62758_enable();

	/* if set backlight level 0, disable syh62758 */
	if (true == syh62758_init_status && 0 == bl_level)
		syh62758_disable();
	up(&(syh62758_g_chip->test_sem));

	/* when power on backlight, schedule backlight check work */
	if (last_bl_level == 0 && bl_level > 0) {
		if (common_info->check_thread.check_bl_support)
			/* delay 500ms schedule work */
			schedule_delayed_work(&common_info->check_thread.check_work,
				(HZ / 5));
	}
	last_bl_level = bl_level;
	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = NULL,
	.en_backlight = syh62758_en_backlight,
	.name = "62758",
};
#endif

static int syh62758_probe(struct i2c_client *client,
	const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = NULL;
	struct syh62758_chip_data *pchip = NULL;
	int ret = -1;
	struct device_node *np = NULL;

	syh62758_info("in!\n");

	if (!client) {
		syh62758_err("client is null pointer\n");
		return -1;
	}
	adapter = client->adapter;

	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "i2c functionality check fail.\n");
		return -EOPNOTSUPP;
	}

	pchip = devm_kzalloc(&client->dev,
		sizeof(struct syh62758_chip_data), GFP_KERNEL);
	if (!pchip)
		return -ENOMEM;

#ifdef CONFIG_REGMAP_I2C
	pchip->regmap = devm_regmap_init_i2c(client, &syh62758_regmap);
	if (IS_ERR(pchip->regmap)) {
		ret = PTR_ERR(pchip->regmap);
		dev_err(&client->dev, "fail : allocate register map: %d\n",
			ret);
		goto err_out;
	}
#endif

	syh62758_g_chip = pchip;
	pchip->client = client;
	i2c_set_clientdata(client, pchip);

	sema_init(&(pchip->test_sem), 1);

	pchip->dev = device_create(syh62758_class,
		NULL, 0, "%s", client->name);
	if (IS_ERR(pchip->dev)) {
		/* Not fatal */
		syh62758_err("Unable to create device; errno = %ld\n",
			PTR_ERR(pchip->dev));
		pchip->dev = NULL;
	}

	memset_s(&syh62758_bl_info, sizeof(struct syh62758_backlight_information),
		0, sizeof(struct syh62758_backlight_information));

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_SYH62758);
	if (!np) {
		syh62758_err("NOT FOUND device node %s!\n", DTS_COMP_SYH62758);
		goto err_sysfs;
	}

	ret = syh62758_parse_dts(np);
	if (ret < 0) {
		syh62758_err("parse syh dts failed");
		goto err_sysfs;
	}

#ifdef CONFIG_LCD_KIT_DRIVER
	np = of_find_compatible_node(NULL, NULL, DTS_COMP_SYH62758);
	if (!np) {
		syh62758_err("NOT FOUND device node %s!\n", DTS_COMP_SYH62758);
		goto err_sysfs;
	}
	/* Only testing syh62758 used */
	ret = regmap_read(pchip->regmap, syh62758_reg_addr[0],
		&syh62758_bl_info.syh62758_reg[0]);
	if (ret < 0) {
		syh62758_err("syh not used\n");
		goto err_sysfs;
	}
	/* Testing syh62758-2 used */
	if (syh62758_bl_info.dual_ic) {
		ret = syh62758_2_config_write(pchip, syh62758_reg_addr,
			syh62758_bl_info.syh62758_reg, 1);
		if (ret < 0) {
			syh62758_err("syh slave not used\n");
			goto err_sysfs;
		}
	}
	ret = of_property_read_u32(np, "syh62758_level_lsb",
		&syh62758_bl_info.syh62758_level_lsb);
	if (ret < 0) {
		syh62758_err("get syh_level_lsb failed\n");
		goto err_sysfs;
	}

	ret = of_property_read_u32(np, "syh62758_level_msb",
		&syh62758_bl_info.syh62758_level_msb);
	if (ret < 0) {
		syh62758_err("get syh_level_msb failed\n");
		goto err_sysfs;
	}
	lcd_kit_bl_register(&bl_ops);
#endif

	return ret;

err_sysfs:
	syh62758_debug("sysfs error!\n");
	device_destroy(syh62758_class, 0);
err_out:
	devm_kfree(&client->dev, pchip);
	return ret;
}

static int syh62758_remove(struct i2c_client *client)
{
	if (!client) {
		syh62758_err("client is null pointer\n");
		return -1;
	}

	return 0;
}

static const struct i2c_device_id syh62758_id[] = {
	{SYH62758_NAME, 0},
	{},
};

static const struct of_device_id syh62758_of_id_table[] = {
	{.compatible = "syh,syh62758"},
	{},
};

MODULE_DEVICE_TABLE(i2c, syh62758_id);
static struct i2c_driver syh62758_i2c_driver = {
	.driver = {
		.name = "syh62758",
		.owner = THIS_MODULE,
		.of_match_table = syh62758_of_id_table,
	},
	.probe = syh62758_probe,
	.remove = syh62758_remove,
	.id_table = syh62758_id,
};

static int __init syh62758_module_init(void)
{
	int ret = -1;

	syh62758_info("in!\n");

	syh62758_class = class_create(THIS_MODULE, "syh62758");
	if (IS_ERR(syh62758_class)) {
		syh62758_err("Unable to create syh class; errno = %ld\n",
			PTR_ERR(syh62758_class));
		syh62758_class = NULL;
	}

	ret = i2c_add_driver(&syh62758_i2c_driver);
	if (ret)
		syh62758_err("Unable to register syh driver\n");

	syh62758_info("ok!\n");

	return ret;
}
late_initcall(syh62758_module_init);
