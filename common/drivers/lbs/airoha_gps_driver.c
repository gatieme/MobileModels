#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/mod_devicetable.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <asm/atomic.h>
#include <linux/semaphore.h>
#include <linux/regulator/consumer.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/irq.h>
#include <linux/sysfs.h>
#include <linux/of_gpio.h>
// #include <securec.h>
#include "airoha_gps_driver.h"

#define LBS_PWR_DBG(fmt, arg...)     pr_debug("%s: " fmt "\n", __func__, ## arg)
#define LBS_PWR_INFO(fmt, arg...)    pr_info("%s: " fmt "\n", __func__, ## arg)
#define LBS_PWR_ERR(fmt, arg...)     pr_err("%s: " fmt "\n", __func__, ## arg)
#define LBS_CMD_PWR_CTRL              0xc0ad
#define LBS_CMD_HOST_WAKEUP_GPS_CTRL  0xc0ae
#define LBS_CMD_GET_DCXO_TYPE  0xc0af
#define MAX_NAME_LEN                  50
#define LBS_FUN_RET_FAIL              -1
#define GPS_WAKEUP_HOST    "lbs,gps_wakeup_host_gpio"
#define HOST_WAKEUP_GPS    "lbs,host_wakeup_gps_gpio"

static struct lbs_power_platform_data *lbs_power_pdata;
static struct platform_device *lbspdev;
static int pwr_state;
struct class *lbs_class;
static int lbs_major;
typedef struct gpio_data {
	char name[MAX_NAME_LEN];
	int gpio;
	int irq;
} gpio_data_t;
static gpio_data_t lbs_gpio[2];

static int airoha_gps_vreg_init(struct lbs_power_vreg_data *vreg)
{
	int rc = 0;
	struct device *dev = &lbspdev->dev;

	LBS_PWR_DBG("vreg_get for : %s", vreg->name);

	/* Get the regulator handle */
	vreg->reg = regulator_get(dev, vreg->name);
	if (IS_ERR(vreg->reg)) {
		rc = PTR_ERR(vreg->reg);
		vreg->reg = NULL;
		pr_err("%s: regulator_get(%s) failed. rc=%d", __func__, vreg->name, rc);
		goto out;
	}

	if ((regulator_count_voltages(vreg->reg) > 0) && (vreg->low_vol_level) && (vreg->high_vol_level)) {
		vreg->set_voltage_sup = 1;
	}

out:
	return rc;
}

static int airoha_gps_vreg_enable(struct lbs_power_vreg_data *vreg)
{
	int rc = 0;

	if (!vreg->is_enabled) {
		if (vreg->set_voltage_sup) {
			rc = regulator_set_voltage(vreg->reg, vreg->low_vol_level, vreg->high_vol_level);
			if (rc < 0) {
				LBS_PWR_ERR("vreg_set_vol(%s) failed rc=%d", vreg->name, rc);
				goto out;
			}
		}

		if (vreg->load_uA >= 0) {
			rc = regulator_set_load(vreg->reg, vreg->load_uA);
			if (rc < 0) {
				LBS_PWR_ERR("vreg_set_mode(%s) failed rc=%d", vreg->name, rc);
				goto out;
			}
		}

		rc = regulator_enable(vreg->reg);
		if (rc < 0) {
			LBS_PWR_ERR("regulator_enable(%s) failed. rc=%d\n",
					vreg->name, rc);
			goto out;
		}
		vreg->is_enabled = true;
	}

	LBS_PWR_INFO("vreg_en successful for : %s", vreg->name);
out:
	return rc;
}

static int airoha_gps_configure_vreg(struct lbs_power_vreg_data *vreg)
{
	int rc = 0;

	LBS_PWR_DBG("config %s", vreg->name);

	/* Get the regulator handle for vreg */
	if (!(vreg->reg)) {
		rc = airoha_gps_vreg_init(vreg);
		if (rc < 0)
			return rc;
	}
	rc = airoha_gps_vreg_enable(vreg);

	return rc;
}

static int airoha_gps_vreg_disable(struct lbs_power_vreg_data *vreg)
{
	int rc = 0;

	if (!vreg)
		return rc;

	if (vreg->is_enabled) {
		rc = regulator_disable(vreg->reg);
		if (rc < 0) {
			LBS_PWR_ERR("regulator_disable(%s) failed. rc=%d", vreg->name, rc);
			goto out;
		}
		vreg->is_enabled = false;

		if (vreg->set_voltage_sup) {
			/* Set the min voltage to 0 */
			rc = regulator_set_voltage(vreg->reg, 0, vreg->high_vol_level);
			if (rc < 0) {
				LBS_PWR_ERR("vreg_set_vol(%s) failed rc=%d", vreg->name, rc);
				goto out;
			}
		}
		if (vreg->load_uA >= 0) {
			rc = regulator_set_load(vreg->reg, 0);
			if (rc < 0) {
				LBS_PWR_ERR("vreg_set_mode(%s) failed rc=%d", vreg->name, rc);
				goto out;
			}
		}
	}

	LBS_PWR_INFO("vreg_disable successful for : %s", vreg->name);
out:
	return rc;
}

static int airoha_gps_power(int on)
{
	int rc = 0;
	LBS_PWR_INFO("on: %d", on);

	if (on == 1) {
		// Power On, just L4C 1.8V
		if (lbs_power_pdata->lbs_vdd_spmu) {
			rc = airoha_gps_configure_vreg(lbs_power_pdata->lbs_vdd_spmu);
			if (rc < 0) {
				LBS_PWR_ERR("lbs_power lbs_vdd_spmu config failed");
				goto out;
			}
		}
	} else if (on == 0) {
		if (lbs_power_pdata->lbs_vdd_spmu) {
			rc = airoha_gps_vreg_disable(lbs_power_pdata->lbs_vdd_spmu);
			if (rc < 0) {
				LBS_PWR_ERR("lbs_power lbs_vdd_spmu config failed");
				goto out;
			}
		}
	} else {
		LBS_PWR_ERR("Invalid power mode: %d", on);
		rc = -1;
	}
out:
	return rc;
}

#define MAX_PROP_SIZE 32
static int airoha_gps_dt_parse_vreg_info(struct device *dev,
		struct lbs_power_vreg_data **vreg_data, const char *vreg_name)
{
	int len, ret = 0;
	const __be32 *prop = NULL;
	char prop_name[MAX_PROP_SIZE];
	struct lbs_power_vreg_data *vreg = NULL;
	struct device_node *np = dev->of_node;

	LBS_PWR_DBG("vreg dev tree parse for %s", vreg_name);

	*vreg_data = NULL;
	ret = snprintf(prop_name, MAX_PROP_SIZE, "%s-supply", vreg_name);
	if (ret < 0) {
		LBS_PWR_ERR("%s property is not valid", vreg_name);
	}
	if (of_parse_phandle(np, prop_name, 0)) {
		vreg = devm_kzalloc(dev, sizeof(*vreg), GFP_KERNEL);
		if (!vreg) {
			LBS_PWR_ERR("No memory for vreg: %s", vreg_name);
			ret = -ENOMEM;
			goto err;
		}

		vreg->name = vreg_name;

		/* Parse voltage-level from each node */
		ret = snprintf(prop_name, MAX_PROP_SIZE, "%s-voltage-level", vreg_name);
		if (ret < 0) {
			LBS_PWR_ERR("%s property is not valid", vreg_name);
		}
		prop = of_get_property(np, prop_name, &len);
		if (!prop || (len != (2 * sizeof(__be32)))) {
			dev_warn(dev, "%s %s property\n", prop ? "invalid format" : "no", prop_name);
		} else {
			vreg->low_vol_level = be32_to_cpup(&prop[0]);
			vreg->high_vol_level = be32_to_cpup(&prop[1]);
		}

		/* Parse current-level from each node */
		ret = snprintf(prop_name, MAX_PROP_SIZE, "%s-current-level", vreg_name);
		if (ret < 0) {
			LBS_PWR_ERR("%s property is not valid", vreg_name);
		}
		ret = of_property_read_u32(np, prop_name, &vreg->load_uA);
		if (ret < 0) {
			LBS_PWR_ERR("%s property is not valid", prop_name);
			vreg->load_uA = -1;
			ret = 0;
		}

		*vreg_data = vreg;
		LBS_PWR_DBG("%s: vol=[%d %d]uV, current=[%d]uA",
			vreg->name, vreg->low_vol_level,
			vreg->high_vol_level,
			vreg->load_uA);
	} else
		LBS_PWR_INFO("%s: is not provided in device tree", vreg_name);

err:
	return ret;
}

/* interrupts handle function */
irqreturn_t airoha_gps_wakeup_host_event_isr(int irq, void *dev)
{
	LBS_PWR_INFO("enter");
	return IRQ_HANDLED;
}

static int airoha_gps_gpio_irq_setup(struct device *dev, gpio_data_t *gpio_ptr)
{
	int ret;
	int irq;
	unsigned long irq_flags;

	if (dev == NULL || gpio_ptr == NULL) {
		LBS_PWR_ERR("dev is NULL\n");
		return LBS_FUN_RET_FAIL;
	}

	irq = gpio_to_irq(gpio_ptr->gpio);
	irq_flags = IRQF_TRIGGER_RISING | 0x4000;
	ret = devm_request_irq(dev, irq, airoha_gps_wakeup_host_event_isr, irq_flags, gpio_ptr->name, NULL);
	if (ret) {
		LBS_PWR_ERR("request_irq fail %s %d\n", gpio_ptr->name, ret);
		return ret;
	}
	gpio_ptr->irq = irq;
	LBS_PWR_INFO("gpio=%d, irq = %d, irq_flags = 0x%x\n", gpio_ptr->gpio, irq, irq_flags);

	return 0;
}

static int airoha_gps_get_gpio_config(struct device *dev, gpio_data_t *gpio_ptr, char *gpio_name)
{
	int ret = 0;
	int err = 0;
	int gpio;
	struct device_node *node = dev->of_node;

	if ((node == NULL) || (gpio_ptr == NULL)) {
		LBS_PWR_ERR("node or gpio_ptr is NULL\n");
		return LBS_FUN_RET_FAIL;
	}
	gpio = of_get_named_gpio(node, gpio_name, 0);
	LBS_PWR_ERR("debug nodeName %s fullName %s node gpio = %d gpio_name = %s\n",node->name,  node->full_name, 
	                                                                                  gpio, gpio_name);
	if (!gpio_is_valid(gpio)) {
		LBS_PWR_ERR("get gpio error %s\n", gpio_name);
		return LBS_FUN_RET_FAIL;
	}
	ret = gpio_request(gpio, gpio_name);
	if (ret) {
		LBS_PWR_ERR("requset gpio %d err %d\n", gpio, ret);
		return ret;
	}
	if (strncmp(gpio_name, GPS_WAKEUP_HOST, sizeof(GPS_WAKEUP_HOST)) == 0) {
	    ret = gpio_direction_input(gpio);
		LBS_PWR_INFO("[debug] Now enter gpio 1 logic!");
		if (ret) {
			LBS_PWR_ERR("requset gpio %d err %d\n", gpio, ret);
			return LBS_FUN_RET_FAIL;
		}
		err = snprintf(gpio_ptr->name, MAX_NAME_LEN, "gps_wakeup_host");
		if (err < 0) {
			LBS_PWR_ERR("snprintf %d err %d\n", gpio, err);
		}
	} else if (strncmp(gpio_name, HOST_WAKEUP_GPS, sizeof(HOST_WAKEUP_GPS)) == 0) {
		LBS_PWR_INFO("[debug] Now enter gpio 2 logic, output 0!");
		ret = gpio_direction_output(gpio, 0);
		if (ret) {
			LBS_PWR_ERR("requset gpio %d err %d\n", gpio, ret);
			return LBS_FUN_RET_FAIL;
		}
		err = snprintf(gpio_ptr->name, MAX_NAME_LEN, "host_wakeup_gps");
		if (err < 0) {
			LBS_PWR_ERR("snprintf %d err %d\n", gpio, err);
		}
	} else {
		LBS_PWR_ERR("get gpio failed");
		return LBS_FUN_RET_FAIL;
	}
	if (ret < 0) {
		LBS_PWR_ERR("gpio %d direction err %d\n", gpio, ret);
		return ret;
	}
	gpio_ptr->gpio = gpio;
	LBS_PWR_INFO("get gpio = %d %s\n", gpio_ptr->gpio, gpio_name);

	return ret;
}

static int airoha_gps_power_populate_dt_pinfo(struct platform_device *pdev)
{
	int rc;

	LBS_PWR_DBG("enter");
	if (!lbs_power_pdata) {
		return -ENOMEM;
	}

	if (pdev->dev.of_node) {
		LBS_PWR_INFO("Now enter parse vreg!\n");
		rc = airoha_gps_dt_parse_vreg_info(&pdev->dev, &lbs_power_pdata->lbs_vdd_spmu, "lbs,lbs-vdd-spmu");
		if (rc) {
			LBS_PWR_ERR("parse err %d\n", rc);
			return rc;
		}
		rc = airoha_gps_get_gpio_config(&pdev->dev, &lbs_gpio[0], GPS_WAKEUP_HOST);
		if (rc != 0) {
			LBS_PWR_ERR("GPS_WAKEUP_HOST get gpio config err %d\n", rc);
			return rc;
		}
		rc = airoha_gps_get_gpio_config(&pdev->dev, &lbs_gpio[1], HOST_WAKEUP_GPS);
		if (rc != 0) {
			LBS_PWR_ERR("HOST_WAKEUP_GPS get_gpio_config err %d\n", rc);
			return rc;
		}
	}

	lbs_power_pdata->lbs_power_setup = airoha_gps_power;
		LBS_PWR_INFO("airoha init ok!!\n");
	return 0;
}

static ssize_t airoha_gps_show_gps_gpio_debug(
	struct device *dev, struct device_attribute *attr, char *buf)
{
	if (buf == NULL) {
		LBS_PWR_ERR("buf is NULL\n");
		return LBS_FUN_RET_FAIL;
	}

	return snprintf(buf, PAGE_SIZE,  "gpio_%d level=%d\n", lbs_gpio[1].gpio,
		gpio_get_value(lbs_gpio[1].gpio));
}

static ssize_t airoha_gps_store_gps_gpio_debug(
	struct device *dev, struct device_attribute *attr, const char *buf, size_t count) {
	int val;

	if (buf == NULL) {
		LBS_PWR_ERR("buf is NULL\n");
		return LBS_FUN_RET_FAIL;
	}
	val = simple_strtoul(buf, NULL, MAX_NAME_LEN);
	LBS_PWR_INFO("val:%d", val);
	gpio_set_value(lbs_gpio[1].gpio, val);
	return count;
}

static int airoha_gps_power_probe(struct platform_device *pdev)
{
	int ret = 0;

	dev_err(&pdev->dev, "%s", __func__);

	lbs_power_pdata = kzalloc(sizeof(struct lbs_power_platform_data), GFP_KERNEL);

	if (!lbs_power_pdata) {
		LBS_PWR_ERR("Failed to allocate memory");
		return -ENOMEM;
	}

	if (pdev->dev.of_node) {
		ret = airoha_gps_power_populate_dt_pinfo(pdev);
		if (ret < 0) {
			ret = -EPROBE_DEFER;
			LBS_PWR_ERR("Failed to populate device tree info");
			goto free_pdata;
		}
	/*	ret = airoha_gps_gpio_irq_setup(&pdev->dev, &lbs_gpio[0]);
		if (ret < 0) {
			LBS_PWR_ERR("Failed to setup gpio irq");
			goto free_pdata;
		} */
		pdev->dev.platform_data = lbs_power_pdata;
	} else if (pdev->dev.platform_data) {
		/* Optional data set to default if not provided */
		if (!((struct lbs_power_platform_data *) (pdev->dev.platform_data))->lbs_power_setup)
			((struct lbs_power_platform_data *) (pdev->dev.platform_data))->lbs_power_setup = airoha_gps_power;
		memcpy(lbs_power_pdata, pdev->dev.platform_data,
			sizeof(struct lbs_power_platform_data));
		pwr_state = 0;
	} else {
		LBS_PWR_ERR("Failed to get platform data");
		goto free_pdata;
	}

	lbspdev = pdev;

	return 0;

free_pdata:
	kfree(lbs_power_pdata);
	lbs_power_pdata = NULL;
	return ret;
}

static int airoha_gps_power_remove(struct platform_device *pdev)
{
	dev_err(&pdev->dev, "%s", __func__);
	if (lbs_power_pdata->lbs_vdd_spmu->reg) {
		regulator_put(lbs_power_pdata->lbs_vdd_spmu->reg);
	}

	platform_set_drvdata(pdev, NULL);

	kfree(lbs_power_pdata);
	lbs_power_pdata = NULL;

	return 0;
}

const int airoha_gps_get_dcxo_type(void)
{
	struct device_node *dp = of_find_node_by_path("/huawei_gps_info");
	if(!dp) {
		LBS_PWR_ERR("device is not available!\n");
		return -1;
	} else {
		LBS_PWR_DBG("dp->name:%s,dp->full_name:%s;\n", dp->name, dp->full_name);
	}

	return of_property_read_bool(dp, "qcom,gps_dcxo");
}

static long airoha_gps_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int ret = 0;
	int pwr_cntrl = 0;
	int gpio_cntrl = 0;

	switch (cmd) {
		case LBS_CMD_PWR_CTRL:
			pwr_cntrl = (int) arg;
			LBS_PWR_INFO("LBS_CMD_PWR_CTRL pwr_cntrl:%d", pwr_cntrl);
			if (pwr_state != pwr_cntrl) {
				ret = airoha_gps_power(pwr_cntrl);
				if (!ret) {
					pwr_state = pwr_cntrl;
				}
			} else {
				LBS_PWR_ERR("LBS state already:%d no change done", pwr_state);
				ret = 0;
			}
		case LBS_CMD_HOST_WAKEUP_GPS_CTRL:
			gpio_cntrl = (int) arg;
			LBS_PWR_INFO("LBS_CMD_HOST_WAKEUP_GPS_CTRL gpio_cntrl:%d", gpio_cntrl);
			gpio_set_value(lbs_gpio[1].gpio, gpio_cntrl);
			break;
		case LBS_CMD_GET_DCXO_TYPE:
			return airoha_gps_get_dcxo_type();
		default:
			return -EINVAL;
	}
	return ret;
}

static int airoha_gps_open(struct inode *inode, struct file *file_p)
{
	LBS_PWR_INFO("enter");
	return 0;
}

static ssize_t airoha_gps_read(struct file *file_p, char __user *user, size_t len, loff_t *offset)
{
	LBS_PWR_INFO("enter");
	return 0;
}

static ssize_t  airoha_gps_write(struct file *file_p, const char __user *user, size_t len, loff_t *offset)
{
	LBS_PWR_INFO("enter");
	return 0;
}

static int airoha_gps_release(struct inode *inode, struct file *file_p)
{
	LBS_PWR_INFO("enter");
	return 0;
}

static const struct of_device_id lbs_power_match_table[] = {
	{	.compatible = "lbs,airoha" },
	{}
};

static struct platform_driver lbs_power_driver = {
	.probe = airoha_gps_power_probe,
	.remove = airoha_gps_power_remove,
	.driver = {
		.name = "lbs_power",
		.of_match_table = lbs_power_match_table,
	},
};

static const struct file_operations lbs_dev_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = airoha_gps_ioctl,
	.compat_ioctl = airoha_gps_ioctl,
	.write = airoha_gps_write,
	.read = airoha_gps_read,
	.open = airoha_gps_open,
	.release = airoha_gps_release,
};

static int __init airoha_gps_power_init(void)
{
	int ret;
	LBS_PWR_INFO("enter");

	ret = platform_driver_register(&lbs_power_driver);

	lbs_major = register_chrdev(0, "lbs", &lbs_dev_fops);
	if (lbs_major < 0) {
		LBS_PWR_ERR("failed to allocate char dev");
		goto chrdev_unreg;
	}

	lbs_class = class_create(THIS_MODULE, "lbs-dev");
	if (IS_ERR(lbs_class)) {
		LBS_PWR_ERR("coudn't create class");
		goto chrdev_unreg;
	}

	// /sys/devices/virtual/lbs-dev/airoha_gps /dev/airoha_gps
	if (device_create(lbs_class, NULL, MKDEV((unsigned int)lbs_major, 0), NULL, "airoha_gps") == NULL) {
		LBS_PWR_ERR("failed to allocate char dev");
		goto chrdev_unreg;
	}
	return 0;

chrdev_unreg:
	unregister_chrdev(lbs_major, "lbs");
	class_destroy(lbs_class);
	return ret;
}

static void __exit airoha_gps_power_exit(void)
{
	LBS_PWR_INFO("enter");
	gpio_free(lbs_gpio[0].gpio);
	gpio_free(lbs_gpio[1].gpio);
	free_irq(lbs_gpio[0].irq, NULL);
	platform_driver_unregister(&lbs_power_driver);
}

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("MSM LBS power control driver");

module_init(airoha_gps_power_init);
module_exit(airoha_gps_power_exit);
