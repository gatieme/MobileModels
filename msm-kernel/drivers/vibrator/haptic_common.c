#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/of_gpio.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/debugfs.h>

extern struct i2c_driver aw869xx_i2c_driver;
extern struct i2c_driver aw_i2c_driver;

static int __init aw_haptic_i2c_init(void)
{
	int ret = 0;

	pr_info("%s enter\n", __func__);
	ret = i2c_add_driver(&aw869xx_i2c_driver);
	if (ret) {
		pr_err("fail to add aw869xx device into i2c\n");
		return ret;
	}

	ret = i2c_add_driver(&aw_i2c_driver);
	if (ret) {
		pr_err("fail to add aw_haptic device into i2c");
		return ret;
	}
	return 0;
}

module_init(aw_haptic_i2c_init);

static void __exit aw_haptic_i2c_exit(void)
{
	i2c_del_driver(&aw869xx_i2c_driver);

	i2c_del_driver(&aw_i2c_driver);
}

module_exit(aw_haptic_i2c_exit);

MODULE_LICENSE("GPL v2");
