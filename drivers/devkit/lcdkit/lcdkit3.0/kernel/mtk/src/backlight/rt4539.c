/*
* Simple driver
* Copyright (C)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#include "rt4539.h"
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

static struct rt4539_backlight_information rt4539_bl_info;

static char *rt4539_dts_string[RT4539_RW_REG_MAX] = {
	"rt4539_eprom_cfg00",
	"rt4539_eprom_cfg01",
	"rt4539_eprom_cfg02",
	"rt4539_eprom_cfg03",
	"rt4539_eprom_cfg06",
	"rt4539_eprom_cfg07",
	"rt4539_eprom_cfg08",
	"rt4539_eprom_cfg09",
	"rt4539_eprom_cfg0A",
	"rt4539_eprom_cfg05",
	"rt4539_eprom_cfg04",
	"rt4539_bl_control",
};

static unsigned int rt4539_reg_addr[RT4539_RW_REG_MAX] = {
	RT4539_EPROM_CFG00,
	RT4539_EPROM_CFG01,
	RT4539_EPROM_CFG02,
	RT4539_EPROM_CFG03,
	RT4539_EPROM_CFG06,
	RT4539_EPROM_CFG07,
	RT4539_EPROM_CFG08,
	RT4539_EPROM_CFG09,
	RT4539_EPROM_CFG0A,
	RT4539_EPROM_CFG05,
	RT4539_EPROM_CFG04,
	RT4539_BL_CONTROL,
};

struct class *rt4539_class = NULL;
struct rt4539_chip_data *rt4539_g_chip = NULL;
static bool rt4539_init_status = true;
static bool is_dual_hw_en_gpio_same = false;
#if !(IS_ENABLED(CONFIG_DRM_MEDIATEK))
extern struct LCM_DRIVER lcdkit_mtk_common_panel;
#endif

/*
** for debug, S_IRUGO
** /sys/module/honorfb/parameters
*/
unsigned rt4539_msg_level = 7;
module_param_named(debug_rt4539_msg_level, rt4539_msg_level, int, 0640);
MODULE_PARM_DESC(debug_rt4539_msg_level, "backlight rt4539 msg level");

static int rt4539_parse_dts(struct device_node *np)
{
	int ret;
	int i;
	struct mtk_panel_info *plcd_kit_info = NULL;

	if(np == NULL){
		rt4539_err("np is null pointer\n");
		return -1;
	}

	for (i = 0;i < RT4539_RW_REG_MAX;i++ ) {
		ret = of_property_read_u32(np, rt4539_dts_string[i],
			&rt4539_bl_info.rt4539_reg[i]);
		if (ret < 0) {
			//init to invalid data
			rt4539_bl_info.rt4539_reg[i] = 0xffff;
			rt4539_info("can not find config:%s\n", rt4539_dts_string[i]);
		}
	}

	ret = of_property_read_u32(np, "dual_ic", &rt4539_bl_info.dual_ic);
	if (ret < 0) {
		rt4539_info("can not get dual_ic dts node\n");
	}
	else {
		ret = of_property_read_u32(np, "rt4539_2_i2c_bus_id",
			&rt4539_bl_info.rt4539_2_i2c_bus_id);
		if (ret < 0)
			rt4539_info("can not get rt4539_2_i2c_bus_id dts node\n");
	}
	ret = of_property_read_u32(np, "rt4539_hw_enable",
		&rt4539_bl_info.rt4539_hw_en);
	if (ret < 0) {
		rt4539_err("get rt4539_hw_en dts config failed\n");
		rt4539_bl_info.rt4539_hw_en = 0;
	}
	if (rt4539_bl_info.rt4539_hw_en != 0) {
		ret = of_property_read_u32(np, "rt4539_hw_en_gpio",
			&rt4539_bl_info.rt4539_hw_en_gpio);
		if (ret < 0) {
			rt4539_err("get rt4539_hw_en_gpio dts config failed\n");
			return ret;
		}
		if (rt4539_bl_info.dual_ic) {
			ret = of_property_read_u32(np, "rt4539_2_hw_en_gpio",
				&rt4539_bl_info.rt4539_2_hw_en_gpio);
			if (ret < 0) {
				rt4539_err("get rt4539_2_hw_en_gpio dts config failed\n");
				return ret;
			}
			if (rt4539_bl_info.rt4539_hw_en_gpio == rt4539_bl_info.rt4539_2_hw_en_gpio) {
				is_dual_hw_en_gpio_same = true;
			}
		}
	}
	/* gpio number offset */
#if IS_ENABLED(CONFIG_DRM_MEDIATEK)
	plcd_kit_info = lcm_get_panel_info();
	if (plcd_kit_info != NULL) {
		rt4539_bl_info.rt4539_hw_en_gpio += plcd_kit_info->gpio_offset;
		if (rt4539_bl_info.dual_ic)
			rt4539_bl_info.rt4539_2_hw_en_gpio += plcd_kit_info->gpio_offset;
	}
#else
	rt4539_bl_info.rt4539_hw_en_gpio += ((struct mtk_panel_info *)(lcdkit_mtk_common_panel.panel_info))->gpio_offset;
	if (rt4539_bl_info.dual_ic)
		rt4539_bl_info.rt4539_2_hw_en_gpio += ((struct mtk_panel_info *)(lcdkit_mtk_common_panel.panel_info))->gpio_offset;
#endif
	ret = of_property_read_u32(np, "bl_on_kernel_mdelay",
		&rt4539_bl_info.bl_on_kernel_mdelay);
	if (ret < 0) {
		rt4539_err("get bl_on_kernel_mdelay dts config failed\n");
		return ret;
	}
	ret = of_property_read_u32(np, "bl_led_num",
		&rt4539_bl_info.bl_led_num);
	if (ret < 0) {
		rt4539_err("get bl_led_num dts config failed\n");
		return ret;
	}

	return ret;
}

static int rt4539_2_config_write(struct rt4539_chip_data *pchip, unsigned int reg, unsigned int val)
{
	char buf[2];
	int ret = -ENODEV;
	struct i2c_msg msg = {0};
	struct i2c_adapter *adap = NULL;

	if((pchip == NULL) || (pchip->client == NULL)) {
		rt4539_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	if (val == 0xFFFF) {
		rt4539_err("invalid value 0x%x:0xFFFF\n", reg);
		return 0;
	}

	adap = i2c_get_adapter(rt4539_bl_info.rt4539_2_i2c_bus_id);
	if (adap == NULL) {
		rt4539_err("i2c device %d not found\n", rt4539_bl_info.rt4539_2_i2c_bus_id);
		goto out;
	}
	msg.addr = pchip->client->addr;
	msg.flags = pchip->client->flags;
	msg.len = 2;
	msg.buf = buf;
	buf[0] = reg;
	buf[1] = val;

	ret = i2c_transfer(adap, &msg, 1);
	if (ret < 0) {
		rt4539_err("rt4539_2_config_write reg=0x%x,val=0x%x failed!\n", reg, val);
		goto out;
	}

	rt4539_info("rt4539_2_config_write reg=0x%x,val=0x%x\n", reg, val);

out:
	i2c_put_adapter(adap);

	return ret;
}

static int rt4539_2_read_u8(struct rt4539_chip_data *pchip, unsigned int reg, unsigned int val[], unsigned int length)
{
	struct i2c_adapter *adap = NULL;
	struct i2c_msg msg[2] = {0};
	int ret= -ENODEV;

	if((pchip == NULL) || (val == NULL) || (pchip->client == NULL)) {
		rt4539_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	adap = i2c_get_adapter(rt4539_bl_info.rt4539_2_i2c_bus_id);
	if (adap == NULL) {
		rt4539_err("i2c device %d not found\n", rt4539_bl_info.rt4539_2_i2c_bus_id);
		goto out;
	}
	msg[0].addr = pchip->client->addr;
	msg[0].flags = I2C_WRITE_FLAG;
	msg[0].len = 1;
	msg[0].buf = (unsigned char *)&reg;

	msg[1].addr = pchip->client->addr;
	msg[1].flags = I2C_READ_FLAG;
	msg[1].len = length;
	msg[1].buf = (unsigned char *)val;

	ret = i2c_transfer(adap, msg, 2);
	if (ret < 0) {
		rt4539_err("i2c_transfer failed! ret:%d\n", ret);
		goto out;
	}

out:
	i2c_put_adapter(adap);

	return ret;
}

static int rt4539_config_write(struct rt4539_chip_data *pchip, unsigned int reg,unsigned int val)
{
	int ret = 0;

	if(pchip == NULL){
		rt4539_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	if (val == 0xFFFF) {
		rt4539_err("invalid value 0x%x:0xFFFF\n", reg);
		return 0;
	}

	ret = regmap_write(pchip->regmap, reg, val);
	if (ret < 0) {
		rt4539_err("write rt4539 backlight config register 0x%x:0x%x failed\n", reg, val);
		return ret;
	}

	rt4539_info("rt4539_config_write reg=0x%x,val=0x%x\n", reg, val);

	return ret;
}

static int rt4539_config_read(struct rt4539_chip_data *pchip,
			unsigned int reg[],unsigned int val[],unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if((pchip == NULL) || (reg == NULL) || (val == NULL)){
		rt4539_err("pchip or reg or val is null pointer\n");
		return -1;
	}

	for(i = 0;i < size;i++) {
		ret = regmap_read(pchip->regmap, reg[i],&val[i]);
		if (ret < 0) {
			rt4539_err("read rt4539 backlight config register 0x%x failed",reg[i]);
			goto exit;
		} else {
			rt4539_info("read 0x%x value = 0x%x\n", reg[i], val[i]);
		}
	}

exit:
	return ret;
}

/* initialize chip */
static int rt4539_chip_init(struct rt4539_chip_data *pchip)
{
	int i;
	int ret = -1;

	rt4539_info("in!\n");

	if(pchip == NULL){
		rt4539_err("pchip is null pointer\n");
		return -1;
	}

	/* Disable bl before writing the register */
	ret = regmap_write(pchip->regmap, RT4539_BL_CONTROL, BL_DISABLE_CTL);
	if (ret < 0) {
		goto out;
	}
	rt4539_info("regmap_write reg=0x%x,value=0x%x\n", RT4539_BL_CONTROL, BL_DISABLE_CTL);

	if (rt4539_bl_info.dual_ic) {
		ret = rt4539_2_config_write(pchip, RT4539_BL_CONTROL, BL_DISABLE_CTL);
		if (ret < 0) {
			goto out;
		}
	}

	for (i = 0; i < RT4539_RW_REG_MAX; i++) {
		ret = rt4539_config_write(pchip, rt4539_reg_addr[i], rt4539_bl_info.rt4539_reg[i]);
		if (ret < 0) {
			goto out;
		}
                if (rt4539_bl_info.dual_ic) {
			ret = rt4539_2_config_write(pchip, rt4539_reg_addr[i], rt4539_bl_info.rt4539_reg[i]);
			if (ret < 0) {
				goto out;
			}
		}
	}
	rt4539_info("ok!\n");

	return ret;

out:
	dev_err(pchip->dev, "i2c failed to access register\n");
	return ret;
}

/*
 * rt4539_set_reg(): Set rt4539 reg
 *
 * @bl_reg: which reg want to write
 * @bl_mask: which bits of reg want to change
 * @bl_val: what value want to write to the reg
 *
 * A value of zero will be returned on success, a negative errno will
 * be returned in error cases.
 */
ssize_t rt4539_set_reg(u8 bl_reg, u8 bl_mask, u8 bl_val)
{
	ssize_t ret = -1;
	u8 reg = bl_reg;
	u8 mask = bl_mask;
	u8 val = bl_val;

	if (!rt4539_init_status) {
		rt4539_err("init fail, return.\n");
		return ret;
	}

	if (reg < REG_MAX) {
		rt4539_err("Invalid argument!!!\n");
		return ret;
	}

	rt4539_info("%s:reg=0x%x,mask=0x%x,val=0x%x\n", __func__, reg, mask,
		val);

	ret = regmap_update_bits(rt4539_g_chip->regmap, reg, mask, val);
	if (ret < 0) {
		rt4539_err("i2c access fail to register\n");
		return ret;
	}

	return ret;
}
EXPORT_SYMBOL(rt4539_set_reg);

static ssize_t rt4539_reg_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct rt4539_chip_data *pchip = NULL;
	struct i2c_client *client = NULL;
	ssize_t ret = -1;

	if (!buf) {
		rt4539_err("buf is null\n");
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

	ret = rt4539_config_read(pchip, rt4539_reg_addr, rt4539_bl_info.rt4539_reg, RT4539_RW_REG_MAX);
	if (ret < 0) {
		rt4539_err("rt4539 config read failed");
		goto i2c_error;
	}

	ret = snprintf(buf, PAGE_SIZE, "Eprom Configuration0(0x00) = 0x%x\nEprom Configuration01(0x01) = 0x%x\n \
			\rEprom Configuration02(0x02) = 0x%x\nEprom Configuration03(0x03) = 0x%x\n \
			\rEprom Configuration06(0x06) = 0x%x\nEprom Configuration07(0x07) = 0x%x\n \
			\rEprom Configuration08(0x08)  = 0x%x\nEprom Configuration09(0x09)  = 0x%x\n \
			\rEprom Configuration0A(0x0A) = 0x%x\nlevel_lsb(0x05)= 0x%x\n \
			\rlevel_msb(0x04) = 0x%x\nbl_control(0x0B) = 0x%x\n",
			rt4539_bl_info.rt4539_reg[0], rt4539_bl_info.rt4539_reg[1], rt4539_bl_info.rt4539_reg[2], rt4539_bl_info.rt4539_reg[3], rt4539_bl_info.rt4539_reg[4], rt4539_bl_info.rt4539_reg[5],rt4539_bl_info.rt4539_reg[6], rt4539_bl_info.rt4539_reg[7],rt4539_bl_info.rt4539_reg[8], rt4539_bl_info.rt4539_reg[9], rt4539_bl_info.rt4539_reg[10], rt4539_bl_info.rt4539_reg[11]);
	return ret;

i2c_error:
	ret = snprintf(buf, PAGE_SIZE,"%s: i2c access fail to register\n", __func__);
	return ret;
}

static ssize_t rt4539_reg_store(struct device *dev,
					struct device_attribute *dev_attr,
					const char *buf, size_t size)
{
	ssize_t ret;
	struct rt4539_chip_data *pchip = NULL;
	unsigned int reg = 0;
	unsigned int mask = 0;
	unsigned int val = 0;

	if (!buf) {
		rt4539_err("buf is null\n");
		return -1;
	}

	if (!dev) {
		rt4539_err("dev is null\n");
		return -1;
	}

	pchip = dev_get_drvdata(dev);
	if(!pchip){
		rt4539_err("pchip is null\n");
		return -1;
	}

	ret = sscanf(buf, "reg=0x%x, mask=0x%x, val=0x%x", &reg, &mask, &val);
	if (ret < 0) {
		rt4539_info("check your input!!!\n");
		goto out_input;
	}

	rt4539_info("%s:reg=0x%x,mask=0x%x,val=0x%x\n", __func__, reg, mask, val);

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

static DEVICE_ATTR(reg, (S_IRUGO|S_IWUSR), rt4539_reg_show, rt4539_reg_store);

/* pointers to created device attributes */
static struct attribute *rt4539_attributes[] = {
	&dev_attr_reg.attr,
	NULL,
};

static const struct attribute_group rt4539_group = {
	.attrs = rt4539_attributes,
};

static const struct regmap_config rt4539_regmap = {
	.reg_bits = 8,
	.val_bits = 8,
	.reg_stride = 1,
};

static void rt4539_enable(void)
{
	int ret;

	if (rt4539_bl_info.rt4539_hw_en) {
		ret = gpio_request(rt4539_bl_info.rt4539_hw_en_gpio, NULL);
		if (ret)
			rt4539_err("rt4539 Could not request  hw_en_gpio\n");
		ret = gpio_direction_output(rt4539_bl_info.rt4539_hw_en_gpio, GPIO_DIR_OUT);
		if (ret)
			rt4539_err("rt4539 set gpio output not success\n");
		gpio_set_value(rt4539_bl_info.rt4539_hw_en_gpio, GPIO_OUT_ONE);
		if (rt4539_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			ret = gpio_request(rt4539_bl_info.rt4539_2_hw_en_gpio, NULL);
			if (ret)
				rt4539_err("rt4539 Could not request  hw_en2_gpio\n");
			ret = gpio_direction_output(rt4539_bl_info.rt4539_2_hw_en_gpio, GPIO_DIR_OUT);
			if (ret)
				rt4539_err("rt4539 set gpio output not success\n");
			gpio_set_value(rt4539_bl_info.rt4539_2_hw_en_gpio, GPIO_OUT_ONE);
		}
		if (rt4539_bl_info.bl_on_kernel_mdelay)
			mdelay(rt4539_bl_info.bl_on_kernel_mdelay);
	}
	/* chip initialize */
	ret = rt4539_chip_init(rt4539_g_chip);
	if (ret < 0) {
		rt4539_err("rt4539_chip_init fail!\n");
		return;
	}
	rt4539_init_status = true;
}

static void rt4539_disable(void)
{
	if (rt4539_bl_info.rt4539_hw_en) {
		gpio_set_value(rt4539_bl_info.rt4539_hw_en_gpio, GPIO_OUT_ZERO);
		gpio_free(rt4539_bl_info.rt4539_hw_en_gpio);
		if (rt4539_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			gpio_set_value(rt4539_bl_info.rt4539_2_hw_en_gpio, GPIO_OUT_ZERO);
			gpio_free(rt4539_bl_info.rt4539_2_hw_en_gpio);
		}
	}
	rt4539_init_status = false;
}

static int rt4539_set_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int bl_msb = 0;
	int bl_lsb = 0;
	int bl_addr = 0;
	int ret = 0;

	if (!rt4539_g_chip) {
		rt4539_err("rt4539_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(rt4539_g_chip->test_sem))) {
		rt4539_info("Now in test mode\n");
		return 0;
	}
	/* first set backlight, enable rt4539  */
	if (false == rt4539_init_status && bl_level > 0) {
		rt4539_enable();
	}

	if (false == rt4539_init_status) {
		rt4539_info("rt4539 is disabled, can not set backlight, bl_level = %d\n", bl_level);
		up(&(rt4539_g_chip->test_sem));
		return 0;
	}

	if(bl_level > BL_MAX) {
		bl_level = BL_MAX;
	}

	/*set backlight level*/
	bl_msb = (bl_level >> 8) & 0x0F;
	bl_lsb = bl_level & 0xFF;

	ret = regmap_write(rt4539_g_chip->regmap, rt4539_bl_info.rt4539_level_msb, bl_msb);
	if (ret < 0) {
		rt4539_err("write rt4539 backlight level msb:0x%x failed\n", bl_msb);
	}

	ret = regmap_write(rt4539_g_chip->regmap, rt4539_bl_info.rt4539_level_lsb, bl_lsb);
	if (ret < 0) {
		rt4539_err("write rt4539 backlight level lsb:0x%x failed\n", bl_lsb);
	}

	if (rt4539_bl_info.dual_ic) {
		bl_addr = rt4539_bl_info.rt4539_level_msb;
		ret = rt4539_2_config_write(rt4539_g_chip, bl_addr, bl_msb);
		if (ret < 0) {
			rt4539_err("rt4539_2_config_write msb fail\n");
			up(&(rt4539_g_chip->test_sem));
			return ret;
		}

		bl_addr = rt4539_bl_info.rt4539_level_lsb;
		ret = rt4539_2_config_write(rt4539_g_chip, bl_addr, bl_lsb);
		if (ret < 0) {
			rt4539_err("rt4539_2_config_write lsb fail\n");
			up(&(rt4539_g_chip->test_sem));
			return ret;
		}
	}

	rt4539_info("rt4539 write backlight level:%d bl_msb:0x%x bl_lsb:0x%x\n", bl_level, bl_msb, bl_lsb);

	/*if set backlight level 0, disable rt4539*/
	if (true == rt4539_init_status && 0 == bl_level) {
		rt4539_disable();
	}

	up(&(rt4539_g_chip->test_sem));
	last_bl_level = bl_level;

	return ret;
}

static int rt4539_en_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int ret = 0;

	if (!rt4539_g_chip) {
		rt4539_err("rt4539_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(rt4539_g_chip->test_sem))) {
		rt4539_info("Now in test mode\n");
		return 0;
	}
	rt4539_info("rt4539_en_backlight bl_level=%d\n", bl_level);
	/*first set backlight, enable rt4539*/
	if (false == rt4539_init_status && bl_level > 0)
		rt4539_enable();

	/*if set backlight level 0, disable rt4539*/
	if (true == rt4539_init_status && 0 == bl_level)
		rt4539_disable();
	up(&(rt4539_g_chip->test_sem));
	last_bl_level = bl_level;
	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = rt4539_set_backlight,
	.en_backlight = rt4539_en_backlight,
	.name = "4539",
};

static int rt4539_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = NULL;
	struct rt4539_chip_data *pchip = NULL;
	int ret = -1;
	struct device_node *np = NULL;
	int temp;

	rt4539_info("in!\n");

	if(!client){
		rt4539_err("client is null pointer\n");
		return -1;
	}
	adapter = client->adapter;

	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "i2c functionality check fail.\n");
		return -EOPNOTSUPP;
	}

	pchip = devm_kzalloc(&client->dev,
				sizeof(struct rt4539_chip_data), GFP_KERNEL);
	if (!pchip)
		return -ENOMEM;

#ifdef CONFIG_REGMAP_I2C
	pchip->regmap = devm_regmap_init_i2c(client, &rt4539_regmap);
	if (IS_ERR(pchip->regmap)) {
		ret = PTR_ERR(pchip->regmap);
		dev_err(&client->dev, "fail : allocate register map: %d\n", ret);
		goto err_out;
	}
#endif

	rt4539_g_chip = pchip;
	pchip->client = client;
	i2c_set_clientdata(client, pchip);

	sema_init(&(pchip->test_sem), 1);

	pchip->dev = device_create(rt4539_class, NULL, 0, "%s", client->name);
	if (IS_ERR(pchip->dev)) {
		/* Not fatal */
		rt4539_err("Unable to create device; errno = %ld\n", PTR_ERR(pchip->dev));
		pchip->dev = NULL;
	} else {
		dev_set_drvdata(pchip->dev, pchip);
		ret = sysfs_create_group(&pchip->dev->kobj, &rt4539_group);
		if (ret)
			goto err_sysfs;
	}

	memset(&rt4539_bl_info, 0, sizeof(struct rt4539_backlight_information));

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_RT4539);
	if (!np) {
		rt4539_err("NOT FOUND device node %s!\n", DTS_COMP_RT4539);
		goto err_sysfs;
	}

	ret = rt4539_parse_dts(np);
	if (ret < 0) {
		rt4539_err("parse rt4539 dts failed");
		goto err_sysfs;
	}

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_RT4539);
	if (!np) {
		rt4539_err("NOT FOUND device node %s!\n", DTS_COMP_RT4539);
		goto err_sysfs;
	}
	/* Only testing rt4539 used */
	ret = regmap_read(pchip->regmap, rt4539_reg_addr[0], &temp);
	if (ret < 0) {
		rt4539_err("rt4539 not used\n");
		goto err_sysfs;
	}
	/* Testing rt4539-2 used */
	if (rt4539_bl_info.dual_ic) {
		ret = rt4539_2_read_u8(pchip, rt4539_reg_addr[0], &temp, 1);
		if (ret < 0) {
			rt4539_err("rt4539 slave not used\n");
			goto err_sysfs;
		}
	}
	ret = of_property_read_u32(np, "rt4539_level_lsb", &rt4539_bl_info.rt4539_level_lsb);
	if (ret < 0) {
		rt4539_err("get rt4539_level_lsb failed\n");
		goto err_sysfs;
	}

	ret = of_property_read_u32(np, "rt4539_level_msb", &rt4539_bl_info.rt4539_level_msb);
	if (ret < 0) {
		rt4539_err("get rt4539_level_msb failed\n");
		goto err_sysfs;
	}
	lcd_kit_bl_register(&bl_ops);

	return ret;

err_sysfs:
	rt4539_debug("sysfs error!\n");
	device_destroy(rt4539_class, 0);
err_out:
	devm_kfree(&client->dev, pchip);
	return ret;
}

static int rt4539_remove(struct i2c_client *client)
{
	if(!client){
		rt4539_err("client is null pointer\n");
		return -1;
	}

	sysfs_remove_group(&client->dev.kobj, &rt4539_group);

	return 0;
}

static const struct i2c_device_id rt4539_id[] = {
	{RT4539_NAME, 0},
	{},
};

static const struct of_device_id rt4539_of_id_table[] = {
	{.compatible = "rt,rt4539"},
	{},
};

MODULE_DEVICE_TABLE(i2c, rt4539_id);
static struct i2c_driver rt4539_i2c_driver = {
		.driver = {
			.name = "rt4539",
			.owner = THIS_MODULE,
			.of_match_table = rt4539_of_id_table,
		},
		.probe = rt4539_probe,
		.remove = rt4539_remove,
		.id_table = rt4539_id,
};

static int __init rt4539_module_init(void)
{
	int ret = -1;

	rt4539_info("in!\n");

	rt4539_class = class_create(THIS_MODULE, "rt4539");
	if (IS_ERR(rt4539_class)) {
		rt4539_err("Unable to create rt4539 class; errno = %ld\n", PTR_ERR(rt4539_class));
		rt4539_class = NULL;
	}

	ret = i2c_add_driver(&rt4539_i2c_driver);
	if (ret)
		rt4539_err("Unable to register rt4539 driver\n");

	rt4539_info("ok!\n");

	return ret;
}
static void __exit rt4539_module_exit(void)
{
	i2c_del_driver(&rt4539_i2c_driver);
}

late_initcall(rt4539_module_init);
module_exit(rt4539_module_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Backlight driver for rt4539");
MODULE_AUTHOR("Honor Device Co., Ltd.");
