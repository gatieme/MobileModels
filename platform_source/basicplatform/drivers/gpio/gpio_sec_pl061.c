/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: provide secure gpio access function interfaces.
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
#include <linux/module.h>
#include <linux/bitops.h>
#include <linux/gpio/driver.h>
#include <linux/device.h>
#include <linux/amba/bus.h>
#include <linux/slab.h>
#include <linux/pinctrl/consumer.h>
#include <linux/pm.h>
#include <linux/hwspinlock.h>
#include <linux/arm-smccc.h>
#include "gpio_enhance_internal.h"

#define GPIODIR 0x400
#define GPIOIS  0x404
#define GPIOIBE 0x408
#define GPIOIEV 0x40C
#define GPIOIE  0x410
#define GPIORIS 0x414
#define GPIOMIS 0x418
#define GPIOIC  0x41C

#define HISI_SECURE_GPIO_REG_READ   0xc3001106
#define HISI_SECURE_GPIO_REG_WRITE  0xc3001107
static unsigned char pl061_readb(struct pl061 *chip, unsigned offset)
{
	unsigned char v;
	struct arm_smccc_res res;

	arm_smccc_1_1_smc(HISI_SECURE_GPIO_REG_READ,
			offset, chip->base, &res);
	v = (u8)res.a1;

	return v;
}

void gpio_sec_writeb(void __iomem *base, \
	unsigned char v, unsigned offset)
{
	struct arm_smccc_res res;

	arm_smccc_1_1_smc(HISI_SECURE_GPIO_REG_WRITE, v,
			offset, base, &res);
}


static void pl061_writeb(struct pl061 *chip, \
	unsigned char v, unsigned offset)
{
	struct arm_smccc_res res;

	arm_smccc_1_1_smc(HISI_SECURE_GPIO_REG_WRITE, v,
			offset, chip->base, &res);
}

static int sec_pl061_get_direction(struct gpio_chip *gc, unsigned offset)
{
	struct pl061 *pl061 = gpiochip_get_data(gc);

	if (pl061_readb(pl061, GPIODIR) & BIT(offset))
		return 0; /* GPIO_LINE_DIRECTION_OUT */

	return 1; /* GPIO_LINE_DIRECTION_IN */
}

static int sec_pl061_direction_input(struct gpio_chip *gc, unsigned offset)
{
	struct pl061 *pl061 = gpiochip_get_data(gc);
	unsigned long flags;
	unsigned char gpiodir;

	raw_spin_lock_irqsave(&pl061->lock, flags);
	gpiodir = pl061_readb(pl061, GPIODIR);
	gpiodir &= ~(BIT(offset));
	pl061_writeb(pl061, gpiodir, GPIODIR);
	raw_spin_unlock_irqrestore(&pl061->lock, flags);

	return 0;
}

static int sec_pl061_direction_output(struct gpio_chip *gc, unsigned offset,
		int value)
{
	struct pl061 *pl061 = gpiochip_get_data(gc);
	unsigned long flags;
	unsigned char gpiodir;

	raw_spin_lock_irqsave(&pl061->lock, flags);
	pl061_writeb(pl061, !!value << offset, (BIT(offset + 2)));
	gpiodir = pl061_readb(pl061, GPIODIR);
	gpiodir |= BIT(offset);
	pl061_writeb(pl061, gpiodir, GPIODIR);

	/*
	 * gpio value is set again, because pl061 doesn't allow to set value of
	 * a gpio pin before configuring it in OUT mode.
	 */
	pl061_writeb(pl061, !!value << offset, (BIT(offset + 2)));
	raw_spin_unlock_irqrestore(&pl061->lock, flags);

	return 0;
}

static int sec_pl061_get_value(struct gpio_chip *gc, unsigned offset)
{
	struct pl061 *pl061 = gpiochip_get_data(gc);

	return !!pl061_readb(pl061, (BIT(offset + 2)));
}

static void sec_pl061_set_value(struct gpio_chip *gc, unsigned offset, int value)
{
	struct pl061 *pl061 = gpiochip_get_data(gc);

	pl061_writeb(pl061, !!value << offset, (BIT(offset + 2)));
}

static int sec_pl061_irq_type(struct irq_data *d, unsigned trigger)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct pl061 *pl061 = gpiochip_get_data(gc);
	int offset = irqd_to_hwirq(d);
	unsigned long flags;
	u8 gpiois, gpioibe, gpioiev;
	u8 bit = BIT(offset);

	if (offset < 0 || offset >= PL061_GPIO_NR)
		return -EINVAL;

	if ((trigger & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) &&
	    (trigger & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING)))
	{
		dev_err(gc->parent,
			"trying to configure line %d for both level and edge "
			"detection, choose one!\n",
			offset);
		return -EINVAL;
	}

	raw_spin_lock_irqsave(&pl061->lock, flags);
	gpioiev = pl061_readb(pl061, GPIOIEV);
	gpiois = pl061_readb(pl061, GPIOIS);
	gpioibe = pl061_readb(pl061, GPIOIBE);

	if (trigger & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) {
		bool polarity = trigger & IRQ_TYPE_LEVEL_HIGH;

		/* Disable edge detection */
		gpioibe &= ~bit;
		/* Enable level detection */
		gpiois |= bit;
		/* Select polarity */
		if (polarity)
			gpioiev |= bit;
		else
			gpioiev &= ~bit;
		irq_set_handler_locked(d, handle_level_irq);
		dev_dbg(gc->parent, "line %d: IRQ on %s level\n",
			offset,
			polarity ? "HIGH" : "LOW");
	} else if ((trigger & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
		/* Disable level detection */
		gpiois &= ~bit;
		/* Select both edges, setting this makes GPIOEV be ignored */
		gpioibe |= bit;
		irq_set_handler_locked(d, handle_edge_irq);
		dev_dbg(gc->parent, "line %d: IRQ on both edges\n", offset);
	} else if ((trigger & IRQ_TYPE_EDGE_RISING) ||
		   (trigger & IRQ_TYPE_EDGE_FALLING)) {
		bool rising = trigger & IRQ_TYPE_EDGE_RISING;

		/* Disable level detection */
		gpiois &= ~bit;
		/* Clear detection on both edges */
		gpioibe &= ~bit;
		/* Select edge */
		if (rising)
			gpioiev |= bit;
		else
			gpioiev &= ~bit;
		irq_set_handler_locked(d, handle_edge_irq);
		dev_dbg(gc->parent, "line %d: IRQ on %s edge\n",
			offset,
			rising ? "RISING" : "FALLING");
	} else {
		/* No trigger: disable everything */
		gpiois &= ~bit;
		gpioibe &= ~bit;
		gpioiev &= ~bit;
		irq_set_handler_locked(d, handle_bad_irq);
		dev_warn(gc->parent, "no trigger selected for line %d\n",
			 offset);
	}

	pl061_writeb(pl061, gpiois, GPIOIS);
	pl061_writeb(pl061, gpioibe, GPIOIBE);
	pl061_writeb(pl061, gpioiev, GPIOIEV);

	raw_spin_unlock_irqrestore(&pl061->lock, flags);

	return 0;
}

static void sec_pl061_irq_handler(struct irq_desc *desc)
{
	unsigned long pending;
	int offset;
	struct gpio_chip *gc = irq_desc_get_handler_data(desc);
	struct pl061 *pl061 = gpiochip_get_data(gc);
	struct irq_chip *irqchip = irq_desc_get_chip(desc);

	chained_irq_enter(irqchip, desc);

	pending = pl061_readb(pl061, GPIOMIS);
	if (pending) {
		for_each_set_bit(offset, &pending, PL061_GPIO_NR)
			generic_handle_irq(irq_find_mapping(gc->irq.domain,
							    offset));
	}

	chained_irq_exit(irqchip, desc);
}

static void sec_pl061_irq_mask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct pl061 *pl061 = gpiochip_get_data(gc);
	u8 mask = BIT(irqd_to_hwirq(d) % PL061_GPIO_NR);
	u8 gpioie;

	raw_spin_lock(&pl061->lock);
	gpioie = pl061_readb(pl061, GPIOIE) & ~mask;
	pl061_writeb(pl061, gpioie, GPIOIE);
	raw_spin_unlock(&pl061->lock);
}

static void sec_pl061_irq_unmask(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct pl061 *pl061 = gpiochip_get_data(gc);
	u8 mask = BIT(irqd_to_hwirq(d) % PL061_GPIO_NR);
	u8 gpioie;

	raw_spin_lock(&pl061->lock);
	gpioie = pl061_readb(pl061, GPIOIE) | mask;
	pl061_writeb(pl061, gpioie, GPIOIE);
	raw_spin_unlock(&pl061->lock);
}

/**
 * pl061_irq_ack() - ACK an edge IRQ
 * @d: IRQ data for this IRQ
 *
 * This gets called from the edge IRQ handler to ACK the edge IRQ
 * in the GPIOIC (interrupt-clear) register. For level IRQs this is
 * not needed: these go away when the level signal goes away.
 */
static void sec_pl061_irq_ack(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct pl061 *pl061 = gpiochip_get_data(gc);
	u8 mask = BIT(irqd_to_hwirq(d) % PL061_GPIO_NR);

	raw_spin_lock(&pl061->lock);
	pl061_writeb(pl061, mask, GPIOIC);
	raw_spin_unlock(&pl061->lock);
}

static int sec_pl061_irq_set_wake(struct irq_data *d, unsigned int state)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct pl061 *pl061 = gpiochip_get_data(gc);

	return irq_set_irq_wake(pl061->parent_irq, state);
}

static int sec_pl061_probe(struct amba_device *adev, const struct amba_id *id)
{
	struct device *dev = &adev->dev;
	struct pl061 *pl061 = NULL;
	struct gpio_irq_chip *girq = NULL;
	int irq;

	pl061 = devm_kzalloc(dev, sizeof(*pl061), GFP_KERNEL);
	if (pl061 == NULL)
		return -ENOMEM;

	/* SEC GPIO W&R Physical Address */
	pl061->base = (void *)adev->res.start;
	if (IS_ERR(pl061->base))
		return PTR_ERR(pl061->base);

	raw_spin_lock_init(&pl061->lock);
	pl061->gc.request = gpiochip_generic_request;
	pl061->gc.free = gpiochip_generic_free;
	pl061->gc.base = -1;
	pl061->gc.get_direction = sec_pl061_get_direction;
	pl061->gc.direction_input = sec_pl061_direction_input;
	pl061->gc.direction_output = sec_pl061_direction_output;
	pl061->gc.get = sec_pl061_get_value;
	pl061->gc.set = sec_pl061_set_value;
	pl061->gc.ngpio = PL061_GPIO_NR;
	pl061->gc.label = dev_name(dev);
	pl061->gc.parent = dev;
	pl061->gc.owner = THIS_MODULE;

	/*
	 * irq_chip support
	 */
	pl061->irq_chip.name = dev_name(dev);
	pl061->irq_chip.irq_ack	= sec_pl061_irq_ack;
	pl061->irq_chip.irq_mask = sec_pl061_irq_mask;
	pl061->irq_chip.irq_unmask = sec_pl061_irq_unmask;
	pl061->irq_chip.irq_set_type = sec_pl061_irq_type;
	pl061->irq_chip.irq_set_wake = sec_pl061_irq_set_wake;

	pl061_writeb(pl061, 0, GPIOIE);
	irq = adev->irq[0];
	if (!irq)
		dev_warn(&adev->dev, "IRQ support disabled\n");
	pl061->parent_irq = irq;

	girq = &pl061->gc.irq;
	girq->chip = &pl061->irq_chip;
	girq->parent_handler = sec_pl061_irq_handler;
	girq->num_parents = 1;
	girq->parents = devm_kcalloc(dev, 1, sizeof(*girq->parents),
				     GFP_KERNEL);
	if (!girq->parents)
		return -ENOMEM;
	girq->parents[0] = irq;
	girq->default_type = IRQ_TYPE_NONE;
	girq->handler = handle_bad_irq;

	amba_set_drvdata(adev, pl061);
	dev_info(dev, "PL061 SEC GPIO chip registered\n");

	return 0;
}

static const struct amba_id sec_pl061_ids[] = {
	{
		.id = 0x000CC567,
		.mask = 0x000fffff,
	},
	{ 0, 0 },
};
MODULE_DEVICE_TABLE(amba, pl061_ids);

static struct amba_driver sec_pl061_gpio_driver = {
	.drv = {
		.name = "sec_pl061_gpio",
	},
	.id_table = sec_pl061_ids,
	.probe = sec_pl061_probe,
};

module_gpio_enhance_driver(sec_pl061_gpio_driver);

MODULE_LICENSE("GPL v2");
