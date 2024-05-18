/*
* Simple driver
* Copyright (C)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
*/

#include "mp3314.h"
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

static struct mp3314_backlight_information mp3314_bl_info;

static char *mp3314_dts_string[MP3314_RW_REG_MAX] = {
	"mp3314_eprom_cfg05",
	"mp3314_eprom_cfg06",
	"mp3314_eprom_cfg07",
	"mp3314_eprom_cfg08",
	"mp3314_eprom_cfg09",
	"mp3314_eprom_cfg0A",
	"mp3314_eprom_cfg0C",
	"mp3314_eprom_cfg0D",
	"mp3314_eprom_cfg0F",
	"mp3314_eprom_cfg10",
	"mp3314_eprom_cfg03",
	"mp3314_eprom_cfg04",
	"mp3314_eprom_cfg00",
	"mp3314_eprom_cfg01",
	"mp3314_bl_en_ctl",
	"mp3314_eprom_cfg1F",

};

static unsigned int mp3314_reg_addr[MP3314_RW_REG_MAX] = {
	MP3314_EPROM_CFG05,
	MP3314_EPROM_CFG06,
	MP3314_EPROM_CFG07,
	MP3314_EPROM_CFG08,
	MP3314_EPROM_CFG09,
	MP3314_EPROM_CFG0A,
	MP3314_EPROM_CFG0C,
	MP3314_EPROM_CFG0D,
	MP3314_EPROM_CFG0F,
	MP3314_EPROM_CFG10,
	MP3314_EPROM_CFG03,
	MP3314_EPROM_CFG04,
	MP3314_EPROM_CFG00,
	MP3314_EPROM_CFG01,
	MP3314_BL_EN_CTL,
	MP3314_EPROM_CFG1F,
};

struct class *mp3314_class = NULL;
struct mp3314_chip_data *mp3314_g_chip = NULL;
static bool mp3314_init_status = true;
static bool is_dual_hw_en_gpio_same = false;
#if !(IS_ENABLED(CONFIG_DRM_MEDIATEK))
extern struct LCM_DRIVER lcdkit_mtk_common_panel;
#endif

/*
** for debug, S_IRUGO
** /sys/module/honorfb/parameters
*/
unsigned mp3314_msg_level = 7;
module_param_named(debug_mp3314_msg_level, mp3314_msg_level, int, 0640);
MODULE_PARM_DESC(debug_mp3314_msg_level, "backlight mp3314 msg level");

static int mp3314_parse_dts(struct device_node *np)
{
	int ret;
	int i;
	struct mtk_panel_info *plcd_kit_info = NULL;

	if(np == NULL){
		mp3314_err("np is null pointer\n");
		return -1;
	}

	for (i = 0;i < MP3314_RW_REG_MAX;i++ ) {
		ret = of_property_read_u32(np, mp3314_dts_string[i],
			&mp3314_bl_info.mp3314_reg[i]);
		if (ret < 0) {
			//init to invalid data
			mp3314_bl_info.mp3314_reg[i] = 0xffff;
			mp3314_info("can not find config:%s\n", mp3314_dts_string[i]);
		}
	}

	ret = of_property_read_u32(np, "dual_ic", &mp3314_bl_info.dual_ic);
	if (ret < 0) {
		mp3314_info("can not get dual_ic dts node\n");
	}
	else {
		ret = of_property_read_u32(np, "mp3314_2_i2c_bus_id",
			&mp3314_bl_info.mp3314_2_i2c_bus_id);
		if (ret < 0)
			mp3314_info("can not get mp3314_2_i2c_bus_id dts node\n");
	}
	ret = of_property_read_u32(np, "mp3314_hw_enable",
		&mp3314_bl_info.mp3314_hw_en);
	if (ret < 0) {
		mp3314_err("get mp3314_hw_en dts config failed\n");
		mp3314_bl_info.mp3314_hw_en = 0;
	}
	if (mp3314_bl_info.mp3314_hw_en != 0) {
		ret = of_property_read_u32(np, "mp3314_hw_en_gpio",
			&mp3314_bl_info.mp3314_hw_en_gpio);
		if (ret < 0) {
			mp3314_err("get mp3314_hw_en_gpio dts config failed\n");
			return ret;
		}
		if (mp3314_bl_info.dual_ic) {
			ret = of_property_read_u32(np, "mp3314_2_hw_en_gpio",
				&mp3314_bl_info.mp3314_2_hw_en_gpio);
			if (ret < 0) {
				mp3314_err("get mp3314_2_hw_en_gpio dts config failed\n");
				return ret;
			}
			if (mp3314_bl_info.mp3314_hw_en_gpio == mp3314_bl_info.mp3314_2_hw_en_gpio) {
				is_dual_hw_en_gpio_same = true;
			}
		}
	}
	/* gpio number offset */
#if IS_ENABLED(CONFIG_DRM_MEDIATEK)
	plcd_kit_info = lcm_get_panel_info();
	if (plcd_kit_info != NULL) {
		mp3314_bl_info.mp3314_hw_en_gpio += plcd_kit_info->gpio_offset;
		if (mp3314_bl_info.dual_ic)
			mp3314_bl_info.mp3314_2_hw_en_gpio += plcd_kit_info->gpio_offset;
	}
#else
	mp3314_bl_info.mp3314_hw_en_gpio += ((struct mtk_panel_info *)(lcdkit_mtk_common_panel.panel_info))->gpio_offset;
	if (mp3314_bl_info.dual_ic)
		mp3314_bl_info.mp3314_2_hw_en_gpio += ((struct mtk_panel_info *)(lcdkit_mtk_common_panel.panel_info))->gpio_offset;
#endif
	ret = of_property_read_u32(np, "bl_on_kernel_mdelay",
		&mp3314_bl_info.bl_on_kernel_mdelay);
	if (ret < 0) {
		mp3314_err("get bl_on_kernel_mdelay dts config failed\n");
		return ret;
	}
	ret = of_property_read_u32(np, "bl_led_num",
		&mp3314_bl_info.bl_led_num);
	if (ret < 0) {
		mp3314_err("get bl_led_num dts config failed\n");
		return ret;
	}

	return ret;
}

static int mp3314_2_config_write(struct mp3314_chip_data *pchip,
			unsigned int reg[], unsigned int val[], unsigned int size)
{
	struct i2c_adapter *adap = NULL;
	struct i2c_msg msg = {0};
	char buf[2];
	int ret;
	int i;

	if((pchip == NULL) || (reg == NULL) || (val == NULL) || (pchip->client == NULL)) {
		mp3314_err("pchip or reg or val is null pointer\n");
		return -1;
	}
	mp3314_info("mp3314_2_config_write\n");
	/* get i2c adapter */
	adap = i2c_get_adapter(mp3314_bl_info.mp3314_2_i2c_bus_id);
	if (!adap) {
		mp3314_err("i2c device %d not found\n", mp3314_bl_info.mp3314_2_i2c_bus_id);
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
			mp3314_info("mp3314_2_config_write reg=0x%x,val=0x%x\n", buf[0], buf[1]);
		}
	}
out:
	i2c_put_adapter(adap);
	return ret;
}

static int mp3314_config_write(struct mp3314_chip_data *pchip,
			unsigned int reg[],unsigned int val[],unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if((pchip == NULL) || (reg == NULL) || (val == NULL)){
		mp3314_err("pchip or reg or val is null pointer\n");
		return -1;
	}

	/*Disable bl before writing the register*/
	ret = regmap_write(pchip->regmap, MP3314_BL_EN_CTL, BL_DISABLE_CTL);
	if (ret < 0) {
		mp3314_err("write mp3314 backlight config register bl_disable = 0x%x failed\n",BL_DISABLE_CTL);
		goto exit;
	}

	for(i = 0;i < size;i++) {
		/*judge reg is invalid*/
		if (val[i] != 0xffff) {
			ret = regmap_write(pchip->regmap, reg[i], val[i]);
			if (ret < 0) {
				mp3314_err("write mp3314 backlight config register 0x%x failed\n",reg[i]);
				goto exit;
			}
		}
	}

exit:
	return ret;
}

static int mp3314_config_read(struct mp3314_chip_data *pchip,
			unsigned int reg[],unsigned int val[],unsigned int size)
{
	int ret = 0;
	unsigned int i = 0;

	if((pchip == NULL) || (reg == NULL) || (val == NULL)){
		mp3314_err("pchip or reg or val is null pointer\n");
		return -1;
	}

	for(i = 0;i < size;i++) {
		ret = regmap_read(pchip->regmap, reg[i],&val[i]);
		if (ret < 0) {
			mp3314_err("read mp3314 backlight config register 0x%x failed",reg[i]);
			goto exit;
		} else {
			mp3314_info("read 0x%x value = 0x%x\n", reg[i], val[i]);
		}
	}

exit:
	return ret;
}

/* initialize chip */
static int mp3314_chip_init(struct mp3314_chip_data *pchip)
{
	int ret = -1;
	int mp3314_bl_en_ctl = 0x02;
	int mp3314_bl_disable_ctl = 0x9C;

	mp3314_info("in!\n");

	if(pchip == NULL){
		mp3314_err("pchip is null pointer\n");
		return -1;
	}
	if (mp3314_bl_info.dual_ic) {
		/*Disable slave bl before writing the register*/
		ret = mp3314_2_config_write(pchip, &mp3314_bl_en_ctl, &mp3314_bl_disable_ctl, 1);
		if (ret < 0) {
			mp3314_err("mp3314 diable slave bl register failed\n");
			goto out;
		}
		ret = mp3314_2_config_write(pchip, mp3314_reg_addr, mp3314_bl_info.mp3314_reg, MP3314_RW_REG_MAX);
		if (ret < 0) {
			mp3314_err("mp3314 slave config register failed\n");
		goto out;
		}
	}
	ret = mp3314_config_write(pchip, mp3314_reg_addr, mp3314_bl_info.mp3314_reg, MP3314_RW_REG_MAX);
	if (ret < 0) {
		mp3314_err("mp3314 config register failed");
		goto out;
	}
	mp3314_info("ok!\n");
	return ret;

out:
	dev_err(pchip->dev, "i2c failed to access register\n");
	return ret;
}

/*
 * mp3314_set_reg(): Set mp3314 reg
 *
 * @bl_reg: which reg want to write
 * @bl_mask: which bits of reg want to change
 * @bl_val: what value want to write to the reg
 *
 * A value of zero will be returned on success, a negative errno will
 * be returned in error cases.
 */
ssize_t mp3314_set_reg(u8 bl_reg, u8 bl_mask, u8 bl_val)
{
	ssize_t ret = -1;
	u8 reg = bl_reg;
	u8 mask = bl_mask;
	u8 val = bl_val;

	if (!mp3314_init_status) {
		mp3314_err("init fail, return.\n");
		return ret;
	}

	if (reg < REG_MAX) {
		mp3314_err("Invalid argument!!!\n");
		return ret;
	}

	mp3314_info("%s:reg=0x%x,mask=0x%x,val=0x%x\n", __func__, reg, mask,
		val);

	ret = regmap_update_bits(mp3314_g_chip->regmap, reg, mask, val);
	if (ret < 0) {
		mp3314_err("i2c access fail to register\n");
		return ret;
	}

	return ret;
}
EXPORT_SYMBOL(mp3314_set_reg);

static ssize_t mp3314_reg_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct mp3314_chip_data *pchip = NULL;
	struct i2c_client *client = NULL;
	ssize_t ret = -1;

	if (!buf) {
		mp3314_err("buf is null\n");
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

	ret = mp3314_config_read(pchip, mp3314_reg_addr, mp3314_bl_info.mp3314_reg, MP3314_RW_REG_MAX);
	if (ret < 0) {
		mp3314_err("mp3314 config read failed");
		goto i2c_error;
	}

	ret = snprintf(buf, PAGE_SIZE, "Eprom Configuration05(0x05) = 0x%x\nEprom Configuration06(0x06) = 0x%x\n \
			\rEprom Configuration07(0x07) = 0x%x\nEprom Configuration08(0x08) = 0x%x\n \
			\rEprom Configuration09(0x09) = 0x%x\nEprom Configuration10(0x10) = 0x%x\n \
			\rEprom Configuration0A(0x0A)  = 0x%x\nEprom Configuration0C(0x0C)  = 0x%x\n \
			\rEprom Configuration0D(0x0D) = 0x%x\nEprom Configuration0F(0x0F) = 0x%x\nEprom Configuration03(0x03) = 0x%x\nEprom Configuration04(0x04) = 0x%x\n \
			\rEprom Configuration00(0x00)= 0x%x\nEprom Configuration01(0x01) = 0x%x\nEprom BL_EN_CTL(0x02) = 0x%xEprom Configuration1F(0x1F) = 0x%x\n",
			mp3314_bl_info.mp3314_reg[0], mp3314_bl_info.mp3314_reg[1], mp3314_bl_info.mp3314_reg[2], mp3314_bl_info.mp3314_reg[3], mp3314_bl_info.mp3314_reg[4], mp3314_bl_info.mp3314_reg[5],mp3314_bl_info.mp3314_reg[6], mp3314_bl_info.mp3314_reg[7],
			mp3314_bl_info.mp3314_reg[8], mp3314_bl_info.mp3314_reg[9], mp3314_bl_info.mp3314_reg[10], mp3314_bl_info.mp3314_reg[11], mp3314_bl_info.mp3314_reg[12],mp3314_bl_info.mp3314_reg[13],mp3314_bl_info.mp3314_reg[14],mp3314_bl_info.mp3314_reg[15]);
	return ret;

i2c_error:
	ret = snprintf(buf, PAGE_SIZE,"%s: i2c access fail to register\n", __func__);
	return ret;
}

static ssize_t mp3314_reg_store(struct device *dev,
					struct device_attribute *dev_attr,
					const char *buf, size_t size)
{
	ssize_t ret;
	struct mp3314_chip_data *pchip = NULL;
	unsigned int reg = 0;
	unsigned int mask = 0;
	unsigned int val = 0;

	if (!buf) {
		mp3314_err("buf is null\n");
		return -1;
	}

	if (!dev) {
		mp3314_err("dev is null\n");
		return -1;
	}

	pchip = dev_get_drvdata(dev);
	if(!pchip){
		mp3314_err("pchip is null\n");
		return -1;
	}

	ret = sscanf(buf, "reg=0x%x, mask=0x%x, val=0x%x", &reg, &mask, &val);
	if (ret < 0) {
		mp3314_info("check your input!!!\n");
		goto out_input;
	}

	mp3314_info("%s:reg=0x%x,mask=0x%x,val=0x%x\n", __func__, reg, mask, val);

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

static DEVICE_ATTR(reg, (S_IRUGO|S_IWUSR), mp3314_reg_show, mp3314_reg_store);

/* pointers to created device attributes */
static struct attribute *mp3314_attributes[] = {
	&dev_attr_reg.attr,
	NULL,
};

static const struct attribute_group mp3314_group = {
	.attrs = mp3314_attributes,
};

static const struct regmap_config mp3314_regmap = {
	.reg_bits = 8,
	.val_bits = 8,
	.reg_stride = 1,
};

static void mp3314_enable(void)
{
	int ret;

	if (mp3314_bl_info.mp3314_hw_en) {
		ret = gpio_request(mp3314_bl_info.mp3314_hw_en_gpio, NULL);
		if (ret)
			mp3314_err("mp3314 Could not request  hw_en_gpio\n");
		ret = gpio_direction_output(mp3314_bl_info.mp3314_hw_en_gpio, GPIO_DIR_OUT);
		if (ret)
			mp3314_err("mp3314 set gpio output not success\n");
		gpio_set_value(mp3314_bl_info.mp3314_hw_en_gpio, GPIO_OUT_ONE);
		if (mp3314_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			ret = gpio_request(mp3314_bl_info.mp3314_2_hw_en_gpio, NULL);
			if (ret)
				mp3314_err("mp3314 Could not request  hw_en2_gpio\n");
			ret = gpio_direction_output(mp3314_bl_info.mp3314_2_hw_en_gpio, GPIO_DIR_OUT);
			if (ret)
				mp3314_err("mp3314 set gpio output not success\n");
			gpio_set_value(mp3314_bl_info.mp3314_2_hw_en_gpio, GPIO_OUT_ONE);
		}
		if (mp3314_bl_info.bl_on_kernel_mdelay)
			mdelay(mp3314_bl_info.bl_on_kernel_mdelay);
	}
	/* chip initialize */
	ret = mp3314_chip_init(mp3314_g_chip);
	if (ret < 0) {
		mp3314_err("mp3314_chip_init fail!\n");
		return;
	}
	mp3314_init_status = true;
}

static void mp3314_disable(void)
{
	if (mp3314_bl_info.mp3314_hw_en) {
		gpio_set_value(mp3314_bl_info.mp3314_hw_en_gpio, GPIO_OUT_ZERO);
		gpio_free(mp3314_bl_info.mp3314_hw_en_gpio);
		if (mp3314_bl_info.dual_ic && is_dual_hw_en_gpio_same == false) {
			gpio_set_value(mp3314_bl_info.mp3314_2_hw_en_gpio, GPIO_OUT_ZERO);
			gpio_free(mp3314_bl_info.mp3314_2_hw_en_gpio);
		}
	}
	mp3314_init_status = false;
}

static int mp3314_set_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int bl_msb = 0;
	int bl_lsb = 0;
	int ret = 0;

	if (!mp3314_g_chip) {
		mp3314_err("mp3314_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(mp3314_g_chip->test_sem))) {
		mp3314_info("Now in test mode\n");
		return 0;
	}
	/*first set backlight, enable mp3314*/
	if (false == mp3314_init_status && bl_level > 0)
		mp3314_enable();

	if (false == mp3314_init_status) {
		mp3314_info("mp3314 is disabled, can not set backlight\n");
		up(&(mp3314_g_chip->test_sem));
		return 0;
	}

	bl_level = bl_level * mp3314_bl_info.bl_level / MP3314_BL_DEFAULT_LEVEL;
	if(bl_level > BL_MAX) {
		bl_level = BL_MAX;
	}

	/*set backlight level*/
	bl_msb = (bl_level >> 8) & 0xFF;
	bl_lsb = bl_level & 0xFF;

	ret = regmap_write(mp3314_g_chip->regmap, mp3314_bl_info.mp3314_level_msb, bl_msb);
	if (ret < 0)
		mp3314_debug("write mp3314 backlight level msb:0x%x failed\n", bl_msb);
	ret = regmap_write(mp3314_g_chip->regmap, mp3314_bl_info.mp3314_level_lsb, bl_lsb);
	if (ret < 0)
		mp3314_debug("write mp3314 backlight level lsb:0x%x failed\n", bl_lsb);

	if (mp3314_bl_info.dual_ic) {
		ret = mp3314_2_config_write(mp3314_g_chip, &mp3314_bl_info.mp3314_level_msb, &bl_msb, 1);
		if (ret < 0)
			mp3314_debug("write slave mp3314 backlight level msb:0x%x failed\n", bl_msb);
		ret = mp3314_2_config_write(mp3314_g_chip, &mp3314_bl_info.mp3314_level_lsb, &bl_lsb, 1);
	    	if (ret < 0)
			mp3314_debug("write slave mp3314 backlight level lsb:0x%x failed\n", bl_lsb);

	}

	mp3314_info("mp3314 write backlight level:%d bl_msb:0x%x bl_lsb:0x%x\n", bl_level, bl_msb, bl_lsb);
	/*if set backlight level 0, disable mp3314*/
	if (true == mp3314_init_status && 0 == bl_level)
	{
		mp3314_disable();
	}
	up(&(mp3314_g_chip->test_sem));
	last_bl_level = bl_level;

	return ret;
}

static int mp3314_en_backlight(uint32_t bl_level)
{
	static int last_bl_level = 0;
	int ret = 0;

	if (!mp3314_g_chip) {
		mp3314_err("mp3314_g_chip is null\n");
		return -1;
	}
	if (down_trylock(&(mp3314_g_chip->test_sem))) {
		mp3314_info("Now in test mode\n");
		return 0;
	}
	mp3314_info("mp3314_en_backlight bl_level=%d\n", bl_level);
	/*first set backlight, enable mp3314*/
	if (false == mp3314_init_status && bl_level > 0)
		mp3314_enable();

	/*if set backlight level 0, disable mp3314*/
	if (true == mp3314_init_status && 0 == bl_level)
		mp3314_disable();
	up(&(mp3314_g_chip->test_sem));
	last_bl_level = bl_level;
	return ret;
}

static struct lcd_kit_bl_ops bl_ops = {
	.set_backlight = mp3314_set_backlight,
	.en_backlight = mp3314_en_backlight,
	.name = "3314",
};

static int mp3314_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = NULL;
	struct mp3314_chip_data *pchip = NULL;
	int ret = -1;
	struct device_node *np = NULL;

	mp3314_info("in!\n");

	if(!client){
		mp3314_err("client is null pointer\n");
		return -1;
	}
	adapter = client->adapter;

	if (!i2c_check_functionality(adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "i2c functionality check fail.\n");
		return -EOPNOTSUPP;
	}

	pchip = devm_kzalloc(&client->dev,
				sizeof(struct mp3314_chip_data), GFP_KERNEL);
	if (!pchip)
		return -ENOMEM;

#ifdef CONFIG_REGMAP_I2C
	pchip->regmap = devm_regmap_init_i2c(client, &mp3314_regmap);
	if (IS_ERR(pchip->regmap)) {
		ret = PTR_ERR(pchip->regmap);
		dev_err(&client->dev, "fail : allocate register map: %d\n", ret);
		goto err_out;
	}
#endif

	mp3314_g_chip = pchip;
	pchip->client = client;
	i2c_set_clientdata(client, pchip);

	sema_init(&(pchip->test_sem), 1);

	pchip->dev = device_create(mp3314_class, NULL, 0, "%s", client->name);
	if (IS_ERR(pchip->dev)) {
		/* Not fatal */
		mp3314_err("Unable to create device; errno = %ld\n", PTR_ERR(pchip->dev));
		pchip->dev = NULL;
	} else {
		dev_set_drvdata(pchip->dev, pchip);
		ret = sysfs_create_group(&pchip->dev->kobj, &mp3314_group);
		if (ret)
			goto err_sysfs;
	}

	memset(&mp3314_bl_info, 0, sizeof(struct mp3314_backlight_information));

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_MP3314);
	if (!np) {
		mp3314_err("NOT FOUND device node %s!\n", DTS_COMP_MP3314);
		goto err_sysfs;
	}

	ret = mp3314_parse_dts(np);
	if (ret < 0) {
		mp3314_err("parse mp3314 dts failed");
		goto err_sysfs;
	}

	np = of_find_compatible_node(NULL, NULL, DTS_COMP_MP3314);
	if (!np) {
		mp3314_err("NOT FOUND device node %s!\n", DTS_COMP_MP3314);
		goto err_sysfs;
	}
	/* Only testing mp3314 used */
	ret = regmap_read(pchip->regmap,
		mp3314_reg_addr[0], &mp3314_bl_info.mp3314_reg[0]);
	if (ret < 0) {
		mp3314_err("mp3314 not used\n");
		goto err_sysfs;
	}
	/* Testing mp3314-2 used */
	if (mp3314_bl_info.dual_ic) {
		ret = mp3314_2_config_write(pchip, mp3314_reg_addr, mp3314_bl_info.mp3314_reg, 1);
		if (ret < 0) {
			mp3314_err("mp3314 slave not used\n");
			goto err_sysfs;
		}
	}

        ret = of_property_read_u32(np, "bl_level", &mp3314_bl_info.bl_level);
	if (ret < 0) {
		mp3314_err("get bl_level failed\n");
		goto err_sysfs;
	}


	ret = of_property_read_u32(np, "mp3314_level_lsb", &mp3314_bl_info.mp3314_level_lsb);
	if (ret < 0) {
		mp3314_err("get mp3314_level_lsb failed\n");
		goto err_sysfs;
	}

	ret = of_property_read_u32(np, "mp3314_level_msb", &mp3314_bl_info.mp3314_level_msb);
	if (ret < 0) {
		mp3314_err("get mp3314_level_msb failed\n");
		goto err_sysfs;
	}
	lcd_kit_bl_register(&bl_ops);

	return ret;

err_sysfs:
	mp3314_debug("sysfs error!\n");
	device_destroy(mp3314_class, 0);
err_out:
	devm_kfree(&client->dev, pchip);
	return ret;
}

static int mp3314_remove(struct i2c_client *client)
{
	if(!client){
		mp3314_err("client is null pointer\n");
		return -1;
	}

	sysfs_remove_group(&client->dev.kobj, &mp3314_group);

	return 0;
}

static const struct i2c_device_id mp3314_id[] = {
	{MP3314_NAME, 0},
	{},
};

static const struct of_device_id mp3314_of_id_table[] = {
	{.compatible = "mp,mp3314"},
	{},
};

MODULE_DEVICE_TABLE(i2c, mp3314_id);
static struct i2c_driver mp3314_i2c_driver = {
		.driver = {
			.name = "mp3314",
			.owner = THIS_MODULE,
			.of_match_table = mp3314_of_id_table,
		},
		.probe = mp3314_probe,
		.remove = mp3314_remove,
		.id_table = mp3314_id,
};

static int __init mp3314_module_init(void)
{
	int ret = -1;

	mp3314_info("in!\n");

	mp3314_class = class_create(THIS_MODULE, "mp3314");
	if (IS_ERR(mp3314_class)) {
		mp3314_err("Unable to create mp3314 class; errno = %ld\n", PTR_ERR(mp3314_class));
		mp3314_class = NULL;
	}

	ret = i2c_add_driver(&mp3314_i2c_driver);
	if (ret)
		mp3314_err("Unable to register mp3314 driver\n");

	mp3314_info("ok!\n");

	return ret;
}
static void __exit mp3314_module_exit(void)
{
	i2c_del_driver(&mp3314_i2c_driver);
}

late_initcall(mp3314_module_init);
module_exit(mp3314_module_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Backlight driver for mp3314");
MODULE_AUTHOR("Honor Device Co., Ltd.");
