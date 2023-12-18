/*
 * z haptic_nv.c
 *
 * code for vibrator
 *
 * Copyright (c) 2021 Huawei Technologies Co., Ltd.
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

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/firmware.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/interrupt.h>
#include <linux/debugfs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/power_supply.h>
#include <linux/pm_qos.h>
#include <linux/vmalloc.h>
#include <linux/jiffies.h>
#include "haptic_nv.h"
#include "aw8622x.h"

#define HAPTIC_NV_DRIVER_VERSION	("v1.5.1")

struct awinic *aw_haptic_file;

/******************************************************
 *
 * i2c read/write
 *
 ******************************************************/
static int haptic_nv_i2c_read(struct awinic *awinic,
		unsigned char reg_addr, unsigned char *reg_data)
{
	unsigned char cnt = 0;
	int ret = -1;

	while (cnt < HAPTIC_NV_I2C_RETRIES) {
		ret = i2c_smbus_read_byte_data(awinic->i2c, reg_addr);
		if (ret < 0) {
			aw_dev_err("%s: i2c_read cnt=%d error=%d\n",
					__func__, cnt, ret);
		} else {
			*reg_data = ret;
			break;
		}
		cnt++;
		usleep_range(2000, 3000);
	}

	return ret;
}

static int haptic_nv_i2c_write(struct awinic *awinic,
		unsigned char reg_addr, unsigned char reg_data)
{
	unsigned char cnt = 0;
	int ret = -1;

	while (cnt < HAPTIC_NV_I2C_RETRIES) {
		ret =
		i2c_smbus_write_byte_data(awinic->i2c, reg_addr, reg_data);
		if (ret < 0) {
			aw_dev_err("%s: i2c_write cnt=%d error=%d\n",
					__func__, cnt, ret);
		} else {
			break;
		}
		cnt++;
		usleep_range(2000, 3000);
	}

	return ret;
}

static int haptic_nv_hw_reset(struct awinic *awinic)
{
	aw_dev_info("%s enter\n", __func__);

	if (awinic && gpio_is_valid(awinic->reset_gpio)) {
		gpio_set_value_cansleep(awinic->reset_gpio, 0);
		usleep_range(1000, 2000);
		gpio_set_value_cansleep(awinic->reset_gpio, 1);
		usleep_range(3500, 4000);
	} else {
		aw_dev_err("%s: failed\n", __func__);
	}
	return 0;
}

static int haptic_nv_haptic_softreset(struct awinic *awinic)
{
	aw_dev_info("%s enter\n", __func__);
	haptic_nv_i2c_write(awinic, HAPTIC_NV_REG_ID, 0xAA);
	usleep_range(2000, 2500);
	return 0;
}

static int haptic_nv_read_chipid(struct awinic *awinic,
				unsigned char *reg, unsigned char type)
{
	unsigned char cnt = 0;
	int ret = -1;

	while (cnt < HAPTIC_NV_I2C_RETRIES) {
		ret = i2c_smbus_read_byte_data(awinic->i2c, HAPTIC_NV_REG_ID);
		if (ret < 0) {
			if (type == HAPTIC_NV_FIRST_TRY) {
				aw_dev_info("%s: reading chip id\n", __func__);
			} else if (type == HAPTIC_NV_LAST_TRY) {
				aw_dev_err("%s: i2c_read cnt=%d error=%d\n",
						__func__, cnt, ret);
			} else {
				aw_dev_err("%s: type is error\n", __func__);
			}
		} else {
			*reg = ret;
			break;
		}
		cnt++;
		usleep_range(2000, 3000);
	}

	return ret;
}

static int haptic_nv_parse_chipid(struct awinic *awinic)
{
	unsigned char cnt = 0;
	unsigned char reg = 0;
	unsigned char ef_id = 0xff;
	int ret = -1;

	while (cnt < HAPTIC_NV_CHIPID_RETRIES) {
		/* hardware reset */
		haptic_nv_hw_reset(awinic);

		ret = haptic_nv_read_chipid(awinic, &reg, HAPTIC_NV_FIRST_TRY);
		if (ret < 0) {
			awinic->i2c->addr = (u16)awinic->aw862xx_i2c_addr;
			aw_dev_info("%s: try to replace i2c addr [(0x%02X)] to read chip id again\n",
					__func__, awinic->i2c->addr);
			ret = haptic_nv_read_chipid(awinic, &reg,
							HAPTIC_NV_LAST_TRY);
			if (ret < 0)
				break;
		}
		switch (reg) {
		case AW8622X_CHIP_ID:
			/* Distinguish products by AW862XX_REG_EFRD9. */
			haptic_nv_i2c_read(awinic, AW862XX_REG_EFRD9, &ef_id);
			if ((ef_id & 0x41) == AW86224_5_EF_ID) {
				awinic->name = AW86224_5;
				aw_dev_info("%s aw86224_5 detected\n",
						__func__);
				haptic_nv_haptic_softreset(awinic);
				return 0;
			}
			if ((ef_id & 0x41) == AW86223_EF_ID) {
				awinic->name = AW86223;
				aw_dev_info("%s aw86223 detected\n",
						__func__);
				haptic_nv_haptic_softreset(awinic);
				return 0;
			}
			aw_dev_info("%s unsupported ef_id = (0x%02X)\n",
					__func__, ef_id);
			break;
		default:
			aw_dev_info("%s unsupported device revision (0x%x)\n",
					__func__, reg);
			break;
		}
		cnt++;
		usleep_range(2000, 3000);
	}

	return -EINVAL;
}

static int haptic_nv_parse_dt(struct awinic *awinic, struct device *dev,
			struct device_node *np)
{
	unsigned int val = 0;

	val = of_property_read_u32(np, "boost_fw", &awinic->boost_fw);
	if (val != 0){
		aw_dev_info("boost_fw not found");
	}

	if(awinic->boost_fw){
		aw_dev_info("boost_en gpio software control %d", awinic->boost_en);
		awinic->boost_en = of_get_named_gpio(np, "boost_en", 0);
		if (awinic->boost_en >= 0) {
			aw_dev_info("boost en-%d ok\n", awinic->boost_en);
		} else {
			aw_dev_err("get boost en gpio fail\n");
		}
		aw_dev_info("boost_en gpio provide ok %d", awinic->boost_en);
	} else {
		aw_dev_info("boost_en gpio hardware control %d", awinic->boost_en);
	}

	awinic->reset_gpio = of_get_named_gpio(np, "reset-gpio", 0);
	if (awinic->reset_gpio >= 0) {
		aw_dev_info("%s: reset gpio provided ok\n", __func__);
	} else {
		awinic->reset_gpio = -1;
		aw_dev_err("%s: no reset gpio provided, will not HW reset device\n",
				__func__);
		return -ERANGE;
	}

	awinic->irq_gpio = of_get_named_gpio(np, "irq-gpio", 0);
	if (awinic->irq_gpio < 0) {
		aw_dev_err("%s: no irq gpio provided.\n", __func__);
		awinic->IsUsedIRQ = false;
	} else {
		aw_dev_info("%s: irq gpio provided ok.\n", __func__);
		awinic->IsUsedIRQ = true;
	}

	val = of_property_read_u32(np,
			"reg", &awinic->aw862xx_i2c_addr);
	if (val)
		aw_dev_err("%s:configure aw862xx_i2c_addr error\n", __func__);
	else
		aw_dev_info("%s: configure aw862xx_i2c_addr ok\n", __func__);
	return 0;
}

static int aw_file_open(struct inode *inode, struct file *file)
{
	aw_dev_info("%s: enter\n", __func__);
	if (!file)
		return 0;

	if (!try_module_get(THIS_MODULE))
		return -ENODEV;

	file->private_data = (void *)aw_haptic_file;
	aw_dev_info("%s: exit\n", __func__);
	return 0;
}

static int aw_file_release(struct inode *inode, struct file *file)
{
	if (!file)
		return 0;
	file->private_data = (void *)NULL;

	module_put(THIS_MODULE);
	return 0;
}

static long aw_file_unlocked_ioctl(struct file *file,
	unsigned int cmd, unsigned long arg)
{
	struct awinic *awinic = NULL;

	if (!file)
		return 0;

	awinic = (struct awinic *)file->private_data;

	if (!awinic)
		return 0;
	aw_dev_info("cmd=0x%x, arg=0x%lx\n", cmd, arg);

	mutex_lock(&awinic->lock);
	if (_IOC_TYPE(cmd) != AW_HAPTIC_IOCTL_MAGIC) {
		aw_dev_err("%s: cmd magic err\n", __func__);
		mutex_unlock(&awinic->lock);
		return -EINVAL;
	}

	switch (cmd) {
	default:
		aw_dev_err("%s, unknown cmd\n", __func__);
		break;
	}

	mutex_unlock(&awinic->lock);

	return 0;
}

static ssize_t aw_file_read(struct file *filp,
	char *buff, size_t len, loff_t *offset)
{
	struct awinic *awinic = (struct awinic *)filp->private_data;
	int ret = 0;
	int i = 0;
	unsigned char reg_val = 0;
	unsigned char *pbuff = NULL;

	mutex_lock(&awinic->lock);

	aw_dev_info("len=%d\n", len);

	switch (awinic->fileops.cmd) {
	case AW_HAPTIC_CMD_READ_REG:
		pbuff = kzalloc(len, GFP_KERNEL);
		if (pbuff != NULL) {
			for (i = 0; i < len; i++) {
				haptic_nv_i2c_read(awinic,
						awinic->fileops.reg+i,
						&reg_val);
				pbuff[i] = reg_val;
			}
			ret = copy_to_user(buff, pbuff, len);
			if (ret) {
				aw_dev_err("copy to user fail\n");
			}
			kfree(pbuff);
		} else {
			aw_dev_err("alloc memory fail\n");
		}
		break;
	default:
		aw_dev_err("unknown cmd %d\n", awinic->fileops.cmd);
		break;
	}

	mutex_unlock(&awinic->lock);

	for (i = 0; i < len; i++) {
		aw_dev_info("buff[%d]=0x%02x\n", i, buff[i]);
	}

	return len;
}

static ssize_t aw_file_write(struct file *filp,
	const char *buff, size_t len, loff_t *off)
{
	struct awinic *awinic = NULL;
	char write_buf[MAX_WRITE_BUF_LEN] = {0};
	uint64_t type = 0;

	if (!buff || !filp || (len > (MAX_WRITE_BUF_LEN - 1)))
		return len;

	awinic = (struct awinic *)filp->private_data;
	if (!awinic)
		return len;

	if (copy_from_user(write_buf, buff, len)) {
		aw_dev_err("[haptics_write] copy_from_user failed\n");
		return len;
	}
	if (kstrtoull(write_buf, 10, &type)) {
		aw_dev_err("[haptics_write] read value error\n");
		return len;
	}
	aw_dev_info("get haptic id = %llu\n", type);

	switch(awinic->name){
	case AW86223:
	case AW86224_5:
		mutex_lock(&awinic->aw8622x->lock);
		aw8622x_haptic_file_config(awinic->aw8622x, type);
		mutex_unlock(&awinic->aw8622x->lock);
		break;
	default:
		break;
	}

	return len;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = aw_file_read,
	.write = aw_file_write,
	.unlocked_ioctl = aw_file_unlocked_ioctl,
	.open = aw_file_open,
	.release = aw_file_release,
};

static struct miscdevice aw_haptic_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = AW_HAPTIC_NAME,
	.fops = &fops,
};

static int
haptic_nv_i2c_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
	int ret = -1;
	int irq_flags = 0;
	struct awinic *awinic;
	struct device_node *np = i2c->dev.of_node;

	aw_dev_info("%s enter\n", __func__);
	if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_I2C)) {
		aw_dev_err("check_functionality failed\n");
		return -EIO;
	}

	awinic = devm_kzalloc(&i2c->dev, sizeof(struct awinic), GFP_KERNEL);
	if (awinic == NULL)
		return -ENOMEM;

	awinic->dev = &i2c->dev;
	awinic->i2c = i2c;

	i2c_set_clientdata(i2c, awinic);
	/* aw862xx rst & int */
	if (np) {
		ret = haptic_nv_parse_dt(awinic, &i2c->dev, np);
		if (ret) {
			aw_dev_err("%s: failed to parse device tree node\n",
					__func__);
			goto err_parse_dt;
		}
	}

	if(awinic->boost_fw){
		if (gpio_is_valid(awinic->boost_en)) {
			ret = devm_gpio_request_one(&i2c->dev, awinic->boost_en,
									GPIOF_OUT_INIT_HIGH, "boost_en");
			if (ret) {
				aw_dev_err("%s:boost en gpio request failed",__func__);
				goto err_boost_en_request;
			}
			gpio_set_value_cansleep(awinic->boost_en, 1);
			usleep_range(3500, 4000);
		}
	}

	if (gpio_is_valid(awinic->reset_gpio)) {
		ret = devm_gpio_request_one(&i2c->dev, awinic->reset_gpio,
			GPIOF_OUT_INIT_LOW, "haptic_nv_rst");
		if (ret) {
			aw_dev_err("%s: rst request failed\n", __func__);
			goto err_reset_gpio_request;
		}
	}

	if (gpio_is_valid(awinic->irq_gpio)) {
		ret = devm_gpio_request_one(&i2c->dev, awinic->irq_gpio,
			GPIOF_DIR_IN, "haptic_nv_int");
		if (ret) {
			aw_dev_err("%s: int request failed\n", __func__);
			goto err_irq_gpio_request;
		}
	}

	/* parse chip id */
	ret = haptic_nv_parse_chipid(awinic);
	if (ret < 0) {
		aw_dev_err("%s: haptic_nv_read_chipid failed\n", __func__);
		goto err_id;
	}

	/* aw8622x */
	if (awinic->name == AW86223 || awinic->name == AW86224_5) {
		awinic->aw8622x = devm_kzalloc(&i2c->dev,
					sizeof(struct aw8622x), GFP_KERNEL);
		if (awinic->aw8622x == NULL) {
			if (gpio_is_valid(awinic->irq_gpio))
				devm_gpio_free(&i2c->dev, awinic->irq_gpio);
			if (gpio_is_valid(awinic->reset_gpio))
				devm_gpio_free(&i2c->dev, awinic->reset_gpio);
			devm_kfree(&i2c->dev, awinic);
			awinic = NULL;
			return -ENOMEM;
		}
		awinic->aw8622x->dev = awinic->dev;
		awinic->aw8622x->i2c = awinic->i2c;
		awinic->aw8622x->reset_gpio = awinic->reset_gpio;
		awinic->aw8622x->irq_gpio = awinic->irq_gpio;
		awinic->aw8622x->isUsedIntn = awinic->IsUsedIRQ;
		awinic->aw8622x->name = awinic->name;
		/* chip qualify */
		if (!aw8622x_check_qualify(awinic->aw8622x)) {
			aw_dev_err("%s:unqualified chip!\n", __func__);
			goto err_aw8622x_check_qualify;
		}
		if (np) {
			ret = aw8622x_parse_dt(awinic->aw8622x, &i2c->dev, np);
			if (ret) {
				aw_dev_err("%s: failed to parse device tree node\n",
						__func__);
				goto err_aw8622x_parse_dt;
			}
		}
		/* aw8622x irq */
		if (gpio_is_valid(awinic->aw8622x->irq_gpio) &&
			!(awinic->aw8622x->flags & AW8622X_FLAG_SKIP_INTERRUPTS)) {
			/* register irq handler */
			aw8622x_interrupt_setup(awinic->aw8622x);
			irq_flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
			ret = devm_request_threaded_irq(&i2c->dev,
					gpio_to_irq(awinic->aw8622x->irq_gpio),
					NULL, aw8622x_irq, irq_flags,
					"aw8622x", awinic->aw8622x);
			if (ret != 0) {
				aw_dev_err("%s: failed to request IRQ %d: %d\n",
					__func__,
					gpio_to_irq(awinic->aw8622x->irq_gpio),
					ret);
				goto err_aw8622x_irq;
			}
		} else {
			aw_dev_info("%s skipping IRQ registration\n", __func__);
			/* disable feature support if gpio was invalid */
			awinic->aw8622x->flags |= AW8622X_FLAG_SKIP_INTERRUPTS;
		}

		aw8622x_vibrator_init(awinic->aw8622x);
		aw8622x_haptic_init(awinic->aw8622x);
		aw8622x_ram_work_init(awinic->aw8622x);
	}

	dev_set_drvdata(&i2c->dev, awinic);

	aw_haptic_file = awinic;
	ret = misc_register(&aw_haptic_misc);
	if (ret) {
		aw_dev_err("misc fail\n");
		return -ENOMEM;
	}
	aw_dev_info("%s probe completed successfully!\n", __func__);

	return 0;

err_aw8622x_irq:
err_aw8622x_parse_dt:
err_aw8622x_check_qualify:
	if (awinic->name == AW86223 || awinic->name == AW86224_5) {
		devm_kfree(&i2c->dev, awinic->aw8622x);
		awinic->aw8622x = NULL;
	}

err_id:
	if (gpio_is_valid(awinic->irq_gpio))
		devm_gpio_free(&i2c->dev, awinic->irq_gpio);
err_irq_gpio_request:
	if (gpio_is_valid(awinic->reset_gpio))
		devm_gpio_free(&i2c->dev, awinic->reset_gpio);
err_boost_en_request:
	if (gpio_is_valid(awinic->boost_en))
		devm_gpio_free(&i2c->dev, awinic->boost_en);
err_reset_gpio_request:
err_parse_dt:
	devm_kfree(&i2c->dev, awinic);
	awinic = NULL;
	return ret;
}

static int haptic_nv_i2c_remove(struct i2c_client *i2c)
{
	struct awinic *awinic = i2c_get_clientdata(i2c);

	aw_dev_info("%s enter\n", __func__);

	if (awinic->name == AW86223 || awinic->name == AW86224_5) {
		aw_dev_info("%s remove aw8622x\n", __func__);
		cancel_delayed_work_sync(&awinic->aw8622x->ram_work);
		cancel_work_sync(&awinic->aw8622x->haptic_audio.work);
		hrtimer_cancel(&awinic->aw8622x->haptic_audio.timer);
		if (awinic->aw8622x->isUsedIntn)
			cancel_work_sync(&awinic->aw8622x->rtp_work);
		cancel_work_sync(&awinic->aw8622x->vibrator_work);

		hrtimer_cancel(&awinic->aw8622x->timer);
		mutex_destroy(&awinic->aw8622x->lock);
		mutex_destroy(&awinic->aw8622x->rtp_lock);
		mutex_destroy(&awinic->aw8622x->haptic_audio.lock);
		sysfs_remove_group(&awinic->aw8622x->i2c->dev.kobj,
			&aw8622x_vibrator_attribute_group);
#ifdef TIMED_OUTPUT
		timed_output_dev_unregister(&awinic->aw8622x->vib_dev);
#endif
		devm_free_irq(&awinic->aw8622x->i2c->dev,
					gpio_to_irq(awinic->aw8622x->irq_gpio),
					awinic->aw8622x);

	} else {
		aw_dev_err("%s no chip\n", __func__);
		return -ERANGE;
	}

	misc_deregister(&aw_haptic_misc);

	aw_dev_info("%s exit\n", __func__);
	return 0;
}

static const struct i2c_device_id haptic_nv_i2c_id[] = {
	{ HAPTIC_NV_I2C_NAME, 0 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, haptic_nv_i2c_id);

static const struct of_device_id haptic_nv_dt_match[] = {
	{ .compatible = "awinic,haptic_nv" },
	{ },
};

static struct i2c_driver haptic_nv_i2c_driver = {
	.driver = {
		.name = HAPTIC_NV_I2C_NAME,
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(haptic_nv_dt_match),
	},
	.probe = haptic_nv_i2c_probe,
	.remove = haptic_nv_i2c_remove,
	.id_table = haptic_nv_i2c_id,
};

static int __init haptic_nv_i2c_init(void)
{
	int ret = 0;

	aw_dev_info("awinic driver version %s\n", HAPTIC_NV_DRIVER_VERSION);

	ret = i2c_add_driver(&haptic_nv_i2c_driver);
	if (ret) {
		aw_dev_err("fail to add awinic device into i2c\n");
		return ret;
	}

	return 0;
}

late_initcall(haptic_nv_i2c_init);

static void __exit haptic_nv_i2c_exit(void)
{
	i2c_del_driver(&haptic_nv_i2c_driver);
}
module_exit(haptic_nv_i2c_exit);

MODULE_DESCRIPTION("Awinic Haptic Driver");
MODULE_LICENSE("GPL v2");