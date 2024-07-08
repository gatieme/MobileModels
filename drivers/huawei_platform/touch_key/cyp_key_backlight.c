#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/leds.h>
#include <linux/of_platform.h>
#include <linux/clk.h>
#include <linux/mfd/hisi_pmic.h>
#include <huawei_platform/log/hw_log.h>
#include <linux/of_device.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include "huawei_platform/sensor/huawei_key.h"
#ifdef CONFIG_FB
#include <linux/notifier.h>
#include <linux/fb.h>
#endif

#define KEY_BACKLIGHT_AP_COMPATIBLE_ID	"huawei,key_backlight_ap_reg"
#define HWLOG_TAG key_backlight_ap

#define DR_ENABLE_KEYPAD1	0x01	/* dr1 enable */
#define DR_ENABLE_KEYPAD2	0x10	/* dr2 enable */
#define DR_DISABLE_KEYPAD	0x00	/* dr1,2 disable */
#define KEYPAD_ALWAYS_ON	0x70

#define KEYPAD_DAFAULT_DELAY_OFF	(500)	/* default delay 5 sec */

#define KEYPAD_BRIGHTNESS_FULL	0x01
#define KEYPAD_BRIGHTNESS_HALF	0x00

#define ENABLE_NUM	1
#define DISABLE_NUM	0
#define MAX_BYTE	0xff

#define BRIGHTNESS_FULL		255
#define BRIGHTNESS_HALF		127
#define BRIGHTNESS_OFF		0

HWLOG_REGIST();

struct huawei_led {
	const char *name;
	unsigned int dr_iset0;
    unsigned int dr_iset1;
    unsigned long dr_led_ctrl;
	unsigned long dr_time_config0;
	unsigned long delay_off;
	char *default_trigger;
	struct mutex data_lock;
	struct mutex dr_lock;
#ifdef CONFIG_FB
	struct notifier_block fb_notif;
#endif
};

static struct key_param_t last_brightness_on = {
		.brightness1 = BRIGHTNESS_HALF,
		.brightness2 = BRIGHTNESS_HALF,
};

static struct huawei_led keypad_leds = {0};
static struct timer_list keypad_backlight_timer = {0};
static int backlight_on = DISABLE_NUM;
static int debug_mode = DISABLE_NUM;

int huawei_set_dr_key_backlight(void *param_t);

/* write register  */
static void hisi_led_reg_write(u8 led_set, u32 led_address)
{
    hisi_pmic_reg_write(led_address, led_set);
}

static void hisi_led_keypad_set_brightness(u8 brightness_set1,
		u8 brightness_set2, u8 dr_enable)
{
	mutex_lock(&keypad_leds.dr_lock);
	hwlog_info("set to %d, %d\n", brightness_set1, brightness_set2);
	/* config current */
	hisi_led_reg_write(brightness_set1, keypad_leds.dr_iset0);
	hisi_led_reg_write(brightness_set2, keypad_leds.dr_iset1);
	/* set_on  */
	hisi_led_reg_write(KEYPAD_ALWAYS_ON, keypad_leds.dr_time_config0);
	/* enable dr1 dr2*/
	hisi_led_reg_write(dr_enable, keypad_leds.dr_led_ctrl);
	mutex_unlock(&keypad_leds.dr_lock);
}

static void hisi_led_keypad_set_dr_disable(void)
{
	if (debug_mode == ENABLE_NUM) {
		hwlog_info("debug mode, keypad led always on.\n");
		return;
	}
	hwlog_info("set to 0, 0\n");
	mutex_lock(&keypad_leds.dr_lock);
	hisi_led_reg_write(DR_DISABLE_KEYPAD, keypad_leds.dr_led_ctrl);
	mutex_unlock(&keypad_leds.dr_lock);
}

void keypad_backlight_off(unsigned long arg)
{
	if (arg <= jiffies) {
		hisi_led_keypad_set_dr_disable();
		mutex_lock(&keypad_leds.data_lock);
		backlight_on = DISABLE_NUM;
		mutex_unlock(&keypad_leds.data_lock);
	} else {
		mutex_lock(&keypad_leds.data_lock);
		keypad_backlight_timer.expires = arg;
		add_timer(&keypad_backlight_timer);
		backlight_on = ENABLE_NUM;
		mutex_unlock(&keypad_leds.data_lock);
	}
}

int huawei_set_dr_key_backlight(void *param_t)
{
    u8 bl_level1 = 0, bl_level2 = 0;
	u8 brightness1, brightness2, test_mode;
	u8 dr_enable = DR_DISABLE_KEYPAD;
	int ret = 0;
	struct key_param_t *param = (struct key_param_t *)param_t;

	mutex_lock(&keypad_leds.data_lock);
	brightness1 = param->brightness1;
	brightness2 = param->brightness2;
	test_mode = param->test_mode;
	mutex_unlock(&keypad_leds.data_lock);

	if (debug_mode == ENABLE_NUM && test_mode != ENABLE_NUM) {
		hwlog_info("debug mode.\n");
		return ret;
	}

	switch (brightness1) {
	case BRIGHTNESS_OFF:
		break;
	case BRIGHTNESS_FULL:
		bl_level1 = KEYPAD_BRIGHTNESS_FULL;
		dr_enable |= DR_ENABLE_KEYPAD1;
		break;
	case BRIGHTNESS_HALF:
		bl_level1 = KEYPAD_BRIGHTNESS_FULL;
		dr_enable |= DR_ENABLE_KEYPAD1;
		break;
	default:
		hwlog_info("keypad1 set not support brightness\n");
		return ret;
	}
	switch (brightness2) {
	case BRIGHTNESS_OFF:
		break;
	case BRIGHTNESS_FULL:
		bl_level2 = KEYPAD_BRIGHTNESS_FULL;
		dr_enable |= DR_ENABLE_KEYPAD2;
		break;
	case BRIGHTNESS_HALF:
		bl_level2 = KEYPAD_BRIGHTNESS_FULL;
		dr_enable |= DR_ENABLE_KEYPAD2;
		break;
	default:
		hwlog_info("keypad2 set not support brightness\n");
		return ret;
	}

	hisi_led_keypad_set_brightness(bl_level1, bl_level2, dr_enable);

	if (dr_enable == DR_DISABLE_KEYPAD) {
		hwlog_info("set keypad disable.\n");
		hisi_led_keypad_set_dr_disable();
		return ret;
	}
#ifdef CONFIG_FB
	else {
		last_brightness_on.brightness1 = brightness1;
		last_brightness_on.brightness2 = brightness2;
	}
#endif

	hwlog_info("[%s]  id is keypad, bl_level:%d, %d\n",
					__FUNCTION__, bl_level1, bl_level2);

	mutex_lock(&keypad_leds.data_lock);
	keypad_backlight_timer.data = jiffies + keypad_leds.delay_off;
	if (backlight_on == DISABLE_NUM && dr_enable) {
		keypad_backlight_timer.expires = keypad_backlight_timer.data;
		add_timer(&keypad_backlight_timer);
		backlight_on = ENABLE_NUM;
	}
	mutex_unlock(&keypad_leds.data_lock);

	return ret;
}

int key_backlight_power_on(void) {
	huawei_set_dr_key_backlight(&last_brightness_on);
	return 0;
}

#ifdef CONFIG_FB
static int fb_notifier_callback(struct notifier_block *self,
		unsigned long event, void *data)
{
	int *blank;
	int ret = 0;
	struct fb_event *evdata = data;

	struct huawei_led *led_data =
		container_of(self, struct huawei_led, fb_notif);
	if (evdata && evdata->data &&
			(FB_EVENT_BLANK == event) && led_data) {
		blank = evdata->data;
		if (FB_BLANK_UNBLANK == *blank) {
			hwlog_info("%s: unblank +.\n", __func__);
			huawei_set_dr_key_backlight(&last_brightness_on);
		} else if (FB_BLANK_POWERDOWN == *blank) {
			hwlog_info("%s: blank -.\n", __func__);
			hisi_led_keypad_set_dr_disable();
		}
	}
	return 0;
}
#endif

static void huawei_led_set_brightness(struct led_classdev *led_ldev,
				      u32 brightness)
{
	int ret = 0;
	struct key_param_t param;

	param.brightness1 = (brightness >> sizeof(char))
						& MAX_BYTE;
	param.brightness2 = brightness & MAX_BYTE;
	param.test_mode = ENABLE_NUM;
	if (brightness == 0) {
		debug_mode = DISABLE_NUM;
	} else {
		debug_mode = ENABLE_NUM;
	}
	ret = huawei_set_dr_key_backlight(&param);
	if (ret < 0) {
		hwlog_info("set key backlight err. ret:%d\n", ret);
	}
	return;
}

static struct led_classdev huawei_led_ap_ldev=
{
	.name = "keyboard-backlight-ap",
	.max_brightness = LED_FULL,
	.brightness_set = huawei_led_set_brightness,
};

static int key_backlight_probe(struct platform_device *pdev)
{
    int ret = 0;
	hwlog_info("key_backlight_ap device probe in\n");

    ret = led_classdev_register(&pdev->dev, &huawei_led_ap_ldev);
	if (ret < 0) {
		hwlog_info("couldn't register LED %s\n", huawei_led_ap_ldev.name);
		goto errout;
	}
	ret = of_property_read_u32(pdev->dev.of_node, "dr_led_ctrl", &keypad_leds.dr_led_ctrl);
	if (ret < 0) {
		hwlog_info("couldn't get dr_led_ctrl\n");
		goto error;
	}
	ret = of_property_read_u32(pdev->dev.of_node, "dr_iset0", &keypad_leds.dr_iset0);
	if (ret < 0) {
		hwlog_info("couldn't get dr_iset0\n");
		goto error;
	}
	ret = of_property_read_u32(pdev->dev.of_node, "dr_iset1", &keypad_leds.dr_iset1);
	if (ret < 0) {
		hwlog_info("couldn't get dr_iset1\n");
		goto error;
	}
	ret = of_property_read_u32(pdev->dev.of_node, "dr_time_config0", &keypad_leds.dr_time_config0);
	if (ret < 0) {
		hwlog_info("couldn't get dr_time_config0\n");
		goto error;
	}
	ret = of_property_read_u32(pdev->dev.of_node, "dr_delay_off", &keypad_leds.delay_off);
	if (ret < 0) {
		hwlog_info("couldn't get dr_time_config0\n");
		keypad_leds.delay_off = KEYPAD_DAFAULT_DELAY_OFF;
	}

#ifdef CONFIG_FB
	keypad_leds.fb_notif.notifier_call = fb_notifier_callback;
	ret = fb_register_client(&keypad_leds.fb_notif);
	if (ret) {
		hwlog_err("%s: Unable to register fb_notifier: %d", __func__, ret);
		goto err_register_fb;
	}
#endif

	init_timer(&keypad_backlight_timer);
	keypad_backlight_timer.function = keypad_backlight_off;
	mutex_init(&keypad_leds.data_lock);
	mutex_init(&keypad_leds.dr_lock);

	hwlog_info("key_backlight_ap device probe success\n");
	return 0;

#ifdef CONFIG_FB
err_register_fb:
	fb_unregister_client(&keypad_leds.fb_notif);
#endif
error:
	led_classdev_unregister(&huawei_led_ap_ldev);
errout:
	return ret;
}

static int key_backlight_remove(struct platform_device *pdev)
{
#ifdef CONFIG_FB
	fb_unregister_client(&keypad_leds.fb_notif);
#endif

	return 0;
}

static const struct of_device_id key_backlight_match_table[] = {
	{
	 .compatible = KEY_BACKLIGHT_AP_COMPATIBLE_ID,
	 .data = NULL,
	},
	{},
};

MODULE_DEVICE_TABLE(of, key_backlight_match_table);

static struct platform_driver key_backlight_driver = {
	.probe = key_backlight_probe,
	.remove = key_backlight_remove,
	.driver = {
		   .name = "key_backlight_ap",
		   .owner = THIS_MODULE,
		   .of_match_table = of_match_ptr(key_backlight_match_table),
		   },
};

static int key_backlight_init(void)
{
	hwlog_info("key_backlight_ap device init \n");
	return platform_driver_register(&key_backlight_driver);
}

static void key_backlight_exit(void)
{
	platform_driver_unregister(&key_backlight_driver);
}

module_init(key_backlight_init);
module_exit(key_backlight_exit);

MODULE_AUTHOR("Huawei");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("huawei touch key backlight ap driver");
