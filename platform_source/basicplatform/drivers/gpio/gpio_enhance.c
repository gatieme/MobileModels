/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: provide gpio extend function(eg:hwspinlock\secure read & write) interfaces.
 * Create: 2022-3-15
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <linux/spinlock.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/irqchip/chained_irq.h>
#include <linux/bitops.h>
#include <linux/gpio.h>
#include <linux/device.h>
#include <linux/amba/bus.h>
#include <linux/slab.h>
#include <linux/pinctrl/consumer.h>
#include <linux/pm.h>
#include <linux/arm-smccc.h>
#include <securec.h>
#include "gpio_enhance_internal.h"
#include "gpiolib.h"

#define GPIO_IRQ_CTL  0x41C
static struct hwspinlock  *gpio_hwlock;

raw_spinlock_t *get_gpio_lock_by_id(int id)
{
	struct gpio_desc *desc = NULL;
	struct gpio_chip *gc = NULL;
	struct gpio_enhance_chip *gec = NULL;

	desc = gpio_to_desc(id);
	if (!desc) {
		pr_err("Faile to get desc from gpio id\n");
		return NULL;
	}

	gc = gpiod_to_chip(desc);
	if (!gc) {
		pr_err("Faile to get gc from gpio desc\n");
		return NULL;
	}

	gec = container_of(gc, struct gpio_enhance_chip, gc);
	if (!gec) {
		pr_err("Faile to get gpio_enhance_chip from gc\n");
		return NULL;
	}

	return &gec->sub_chip->lock;
}

/* 6502 gpio ops begin */
int gpiochip_usbphy_request(struct gpio_chip *chip, unsigned int offset)
{
	return pinctrl_gpio_request(chip->gpiodev->base + offset);
}

void gpiochip_usbphy_free(struct gpio_chip *chip, unsigned int offset)
{
	pinctrl_gpio_free(chip->gpiodev->base + offset);
}
/* 6502 gpio ops end */


/* ops begin */
static int gec_direction_input(struct gpio_chip *gc, unsigned offset)
{
	struct gpio_enhance_chip *gec = container_of(gc, struct gpio_enhance_chip, gc);
	unsigned long flags;

	gpio_hwspin_lock_irqsave(gpio_hwlock, gc, &flags);
	(void)gec->sub_chip->gc.direction_input(gc, offset);
	hwspin_unlock_irqrestore(gpio_hwlock, &flags);

	return 0;
}

static int gec_direction_output(struct gpio_chip *gc, unsigned offset,
		int value)
{
	struct gpio_enhance_chip *gec = container_of(gc, struct gpio_enhance_chip, gc);
	unsigned long flags;

	gpio_hwspin_lock_irqsave(gpio_hwlock, gc, &flags);
	(void)gec->sub_chip->gc.direction_output(gc, offset, value);
	hwspin_unlock_irqrestore(gpio_hwlock, &flags);

	return 0;
}

static int gec_irq_type(struct irq_data *d, unsigned trigger)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct gpio_enhance_chip *gec = container_of(gc, struct gpio_enhance_chip, gc);
	unsigned long flags;
	int ret;

	gpio_hwspin_lock_irqsave(gpio_hwlock, gc, &flags);
	ret = gec->sub_chip->irq_chip.irq_set_type(d, trigger);
	if (ret)
		dev_err(gc->parent, "%s Fail to set irq type\n", __func__);
	hwspin_unlock_irqrestore(gpio_hwlock, &flags);

	return 0;
}

static void gec_irq_mask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct gpio_enhance_chip *gec = container_of(gc, struct gpio_enhance_chip, gc);

	gpio_hwspin_lock_void(gpio_hwlock, gc);
	gec->sub_chip->irq_chip.irq_mask(d);
	hwspin_unlock(gpio_hwlock);
}

static void gec_irq_unmask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct gpio_enhance_chip *gec = container_of(gc, struct gpio_enhance_chip, gc);

	gpio_hwspin_lock_void(gpio_hwlock, gc);
	gec->sub_chip->irq_chip.irq_unmask(d);
	hwspin_unlock(gpio_hwlock);
}


static void gec_irq_ack(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct gpio_enhance_chip *gec = container_of(gc, struct gpio_enhance_chip, gc);

	gpio_hwspin_lock_void(gpio_hwlock, gc);
	gec->sub_chip->irq_chip.irq_ack(d);
	hwspin_unlock(gpio_hwlock);
}
/* ops end */

static LIST_HEAD(amba_drv_list);
struct amba_drv_ext {
	struct amba_driver *drv;
	struct list_head list;
};

int gpio_enhance_register(struct amba_driver *drv)
{
	struct amba_drv_ext *drv_ext = kzalloc(sizeof(struct amba_drv_ext), GFP_KERNEL);
	if (!drv_ext) {
		pr_err("%s fail to register gpio drv\n", __func__);
		return -1;
	}

	drv_ext->drv = drv;
	list_add(&drv_ext->list, &amba_drv_list);

	return 0;
}

bool gpio_enhance_match(struct device_node *np, struct amba_driver *drv)
{
	u32 val;
	int ret;
	const struct amba_id *table = drv->id_table;

	ret = of_property_read_u32(np, "secure-mode", &val);
	if (ret || (!val)) {
		while (table->mask) {
			if (table->id == 0x00041061) /* pl061 pid */
				return TRUE;
			table++;
		}
	} else {
		while (table->mask) {
			if (table->id == 0x000CC567) /* id 0xCC567(SEC) */
				return TRUE;
			table++;
		}
	}

	return FALSE;
}

static int gpio_sub_driver_probe(struct device_node *np, \
	struct amba_device *adev, const struct amba_id *id)
{
	struct amba_drv_ext *drv_iter = NULL;
	int ret;

	list_for_each_entry(drv_iter, &amba_drv_list, list) {
		if (gpio_enhance_match(np, drv_iter->drv)) {
			ret = drv_iter->drv->probe(adev, id);
			if (ret) {
				pr_err("[%s] fail to probe driver of-node : %s\n", \
					np->name, __func__);
				return ret;
			}

			return 0;
		}
	}

	pr_err("[%s] fail to match driver of-node : %s\n", \
		np->name, __func__);

	return -1;
}

static void clear_gpio_irq(struct device_node *np, \
	struct gpio_enhance_chip *gec)
{
	int ret;
	u32 val;

	ret = of_property_read_u32(np, "secure-mode", &val);
	if (ret || (!val))
		writeb(0xff, gec->base + GPIO_IRQ_CTL);
	else
		gpio_sec_writeb(gec->base, 0xff, GPIO_IRQ_CTL);
}

int gpio_get_base_value(struct device_node *of_node)
{
	struct device_node *np = of_node;
	int base = 0;

	if(!of_property_read_s32(np, "base,offset", &base))
		return base;

	if(of_node->name)
		pr_err("%s:get value failed from node name:%s\n", \
			__func__, of_node->name);

	return -1;
}

static int gpio_enhance_probe(struct amba_device *adev, const struct amba_id *id)
{
	struct device *dev = &adev->dev;
	struct gpio_enhance_chip *gec = NULL;
	int ret;

	gec = devm_kzalloc(dev, sizeof(*gec), GFP_KERNEL);
	if (gec == NULL)
		return -ENOMEM;

	if (of_get_property(dev->of_node, "gpio,hwspinlock", NULL)) {
		gpio_hwlock = hwspin_lock_request_specific(GPIO_HWLOCK_ID);
		if (!gpio_hwlock)
			return -EBUSY;
	}

	if (gpio_sub_driver_probe(dev->of_node, adev, id))
		return -1;

	gec->sub_chip = amba_get_drvdata(adev);
	gec->base = gec->sub_chip->base;
	gec->gc.request = gpiochip_generic_request;
	gec->gc.free = gpiochip_generic_free;
#ifdef CONFIG_GPIO_PL061_VM
	gec->gc.base = gpio_get_base_value(dev->of_node);
#else
	gec->gc.base = -1;
#endif
	gec->gc.get_direction = gec->sub_chip->gc.get_direction;
	gec->gc.direction_input = gec_direction_input;
	gec->gc.direction_output = gec_direction_output;
	gec->gc.get = gec->sub_chip->gc.get;
	gec->gc.set = gec->sub_chip->gc.set;
	gec->gc.ngpio = PL061_GPIO_NR;
	gec->gc.label = dev_name(dev);
	gec->gc.parent = dev;
	gec->gc.owner = THIS_MODULE;

	/*
	 * irq_chip support
	 */
	gec->irq_chip.name = dev_name(dev);
	gec->irq_chip.irq_ack	= gec_irq_ack;
	gec->irq_chip.irq_mask = gec_irq_mask;
	gec->irq_chip.irq_unmask = gec_irq_unmask;
	gec->irq_chip.irq_set_type = gec_irq_type;
	gec->irq_chip.irq_set_wake = gec->sub_chip->irq_chip.irq_set_wake;
#ifdef CONFIG_ARCH_HISI
	gec->irq_chip.irq_disable = gec_irq_mask;
	gec->irq_chip.irq_enable = gec_irq_unmask;
#endif
	/* ensure no gpio irq */
	clear_gpio_irq(dev->of_node, gec);

	gec->parent_irq = gec->sub_chip->parent_irq;
	ret = memcpy_s(&gec->gc.irq, sizeof(struct gpio_irq_chip), \
			&gec->sub_chip->gc.irq, sizeof(struct gpio_irq_chip));
	if (ret) {
		dev_err(dev, "memcpy gc irq failed\n");
		return -EBUSY;
	}

	/* gc irq chip use gec ops, irq handle use sub chip irq handle */
	gec->gc.irq.chip = &gec->irq_chip;

	ret = devm_gpiochip_add_data(dev, &gec->gc, gec->sub_chip);
	if (ret)
		return ret;

	amba_set_drvdata(adev, gec);
	dev_info(dev, "PL061 GPIO chip registered\n");

	return 0;
}

static const struct amba_id enhance_ids[] = {
	{
		.id = 0x00041061,
		.mask = 0x000fffff,
	},
	{ 0, 0 },
};
MODULE_DEVICE_TABLE(amba, pl061_ids);

static struct amba_driver gpio_enhance_driver = {
	.drv = {
		.name = "gpio_enhance",
	},
	.id_table = enhance_ids,
	.probe = gpio_enhance_probe,
};

static int __init gpio_enhance_init(void)
{
	return amba_driver_register(&gpio_enhance_driver);
}

subsys_initcall(gpio_enhance_init);
MODULE_LICENSE("GPL v2");
