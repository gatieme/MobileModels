/*
 * get_fuse.c
 *
 * function of get_fuse module
 *
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd.
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

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/notifier.h>
#include <linux/topology.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/cpu.h>
#include <linux/cpumask.h>
#include <linux/cpufreq.h>
#include <linux/devfreq.h>
#include <linux/cpu_pm.h>
#include <linux/platform_device.h>
#include <linux/kthread.h>
#include <linux/of.h>
#include <linux/pm_qos.h>
#include <linux/device.h>
#include <linux/printk.h>
#include <linux/string.h>
#include <linux/kallsyms.h>
#include <linux/tty.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/kprobes.h>
#include <asm/traps.h>

#include "get_fuse.h"

#define REG_VIR_ADDR_MAP(phyAddr)        ioremap(phyAddr, sizeof(unsigned long))
#define REG_VIR_ADDR_UNMAP(virAddr)      iounmap(virAddr)
#define NUM_COL 7
#define SEND_DATA_COUNT 64

struct get_fuse_rule {
	struct kobject kobj;
	const char *name;
};

struct get_fuse_device {
	struct device_node *np;
	struct get_fuse_rule *ruler;
};

static fuse_domain_info *fuse_domain_info_t = NULL;
result_to_send send_data[SEND_DATA_COUNT];

struct get_fuse_attr {
	struct attribute attr;
	ssize_t (*show)(const struct get_fuse_rule *, char *);
	ssize_t (*store)(struct get_fuse_rule *, const char *, size_t count);
};

static int read_fuse_reg(unsigned int addr, int *return_value)
{
	unsigned int pAddr = addr;
	void __iomem *virAddr = NULL;

	virAddr = REG_VIR_ADDR_MAP(pAddr);
	if (!virAddr) {
		pr_err("virAddr is NULL\n");
		return -1;
	}
	*return_value = readl(virAddr);
	REG_VIR_ADDR_UNMAP(virAddr);

	return 0;
}

signed short decode_fuse_value(u32 addr, u32 offset, u32 mask,
                              u8 packingFactor, unsigned char isSigned)
{
	int bits_assigned = 0;
	u32 cpr_fuse_bits = 0;
	u32 raw_fuse_value = 0;
	u32 bits_we_care_about = 0;
	u32 number_of_bits_we_care_about = 0;
	u32 mask_for_counting = 0;
	u32 value_mask = 0;
	signed short value = 0;
	int ret = 0;

	ret = read_fuse_reg(addr, &raw_fuse_value);
	bits_we_care_about = (raw_fuse_value & mask) >> offset;
	mask_for_counting = mask >> offset;

	while (mask_for_counting) {
		number_of_bits_we_care_about++;
		mask_for_counting = mask_for_counting >> 1;
	}

	cpr_fuse_bits = cpr_fuse_bits << number_of_bits_we_care_about;
	cpr_fuse_bits |= bits_we_care_about;
	bits_assigned += number_of_bits_we_care_about;
	value_mask = (1 << (isSigned ? bits_assigned - 1 : bits_assigned)) - 1;
	value = (signed short) ((cpr_fuse_bits & value_mask) * packingFactor);

	if (isSigned && (cpr_fuse_bits & (1 << (bits_assigned - 1))))
		value = -value;

	return value;
}

int cpr_get_volt(fuse_rail_info*rail)
{
	u32 volt = 0;

	if (rail == NULL)
		return -1;

	if (rail->volt_addr != 0x0)
		volt = decode_fuse_value(rail->volt_addr, rail->volt_offset,
		                        rail->volt_mask, 1, true );
	return volt;
}

int cpr_get_volt_offset(fuse_rail_info *rail)
{
	u32 volt_offset = 0;

	if (rail == NULL)
		return -1;

	if (rail->volt_offset_addr != 0x0)
		volt_offset = decode_fuse_value(rail->volt_offset_addr, rail->volt_offset_offset,
		                               rail->volt_offset_mask, 1, true );

	return volt_offset;
}

int calc_fuse_data(void) {
	int i = 0;
	int j = 0;
	int k = 0;
	fuse_domain_info *t_domain_result = NULL;
	fuse_rail_info *t_rail_result = NULL;
	fuse_rail_result *t_rail_result_copy = NULL;
	fuse_domain_result *domain_result = NULL;

	domain_result = (fuse_domain_result*)kmalloc(sizeof(fuse_domain_result),
	                                    GFP_KERNEL);
	if (domain_result == NULL) {
		pr_err("domain_result init fail \n");
		return -1;
	}
	domain_result->rail_result = (fuse_rail_result*)kmalloc(sizeof(fuse_rail_result) *
	                             CPR_VOLTAGE_MODE_COUNT, GFP_KERNEL);
	if (domain_result->rail_result == NULL) {
		pr_err("rail_result init fail \n");
		kfree(domain_result);
		return -1;
	}
	for (i = 0; i < DOMAIN_COUNT; i++) {
		t_domain_result = &fuse_domain_info_t[i];
		pr_err("t_domain_result = %px\n", t_domain_result);

		if (t_domain_result == NULL) {
			pr_err("t_domain_result fail \n");
			break;
		}

		domain_result->id = t_domain_result->id;
		pr_err("domain id = %d\n", domain_result->id);

		domain_result->modecount = t_domain_result->mode_count;
		pr_err("modecount = %d\n", domain_result->modecount);
		for (j = 0; j < t_domain_result->mode_count; j++) {
			t_rail_result = &(t_domain_result->rail[j]);
			t_rail_result_copy = &(domain_result->rail_result[j]);

			if (t_rail_result == NULL) {
				pr_err("t_rail_result fail \n");
				break;
			}

			if (t_rail_result_copy == NULL) {
				pr_err("t_rail_result_copy fail \n");
				break;
			}
			t_rail_result_copy->targ_volt = cpr_get_volt(t_rail_result);
			t_rail_result_copy->targ_volt_offset = cpr_get_volt_offset(t_rail_result);
			pr_err("mode=%d\t targ_volt=%d\t targ_volt_offset=%d\n",
			      t_rail_result->mode, t_rail_result_copy->targ_volt,
			      t_rail_result_copy->targ_volt_offset);
			send_data[k].id = domain_result->id;
			send_data[k].mode = t_rail_result->mode;
			send_data[k].targ_volt = t_rail_result_copy->targ_volt;
			send_data[k].targ_voltoffset = t_rail_result_copy->targ_volt_offset;
			k++;
		}
	}
	kfree(domain_result->rail_result);
	kfree(domain_result);

	return 0;
}

static ssize_t show_fuse_data(const struct get_fuse_rule *ruler, char *buf)
{
	ssize_t i = 0;
	int index = 0;

	calc_fuse_data();

	for (index = 0; index < SEND_DATA_COUNT; index++) {
		i += sprintf(&buf[i], "%d %d %d %d,", send_data[index].id, send_data[index].mode,
		            send_data[index].targ_volt, send_data[index].targ_voltoffset);
	}
	i += sprintf(&buf[i], "\n");

	return i;
}

#define get_fuse_attr_ro(_name) \
static struct get_fuse_attr _name = __ATTR(_name, 0440, show_##_name, NULL)

#define get_fuse_attr_rw(_name) \
static struct get_fuse_attr _name = __ATTR(_name, 0640, show_##_name, store_##_name)

get_fuse_attr_ro(fuse_data);

static struct attribute *default_attrs[] = {
	&fuse_data.attr,
	NULL
};

#define to_get_fuse_rule(k) container_of(k, struct get_fuse_rule, kobj)
#define to_attr(a) container_of(a, struct get_fuse_attr, attr)

static ssize_t show(struct kobject *kobj, struct attribute *attr, char *buf)
{
	struct get_fuse_rule *data = to_get_fuse_rule(kobj);
	struct get_fuse_attr *cattr = to_attr(attr);
	ssize_t ret = -EIO;

	if (cattr->show != NULL)
		ret = cattr->show(data, buf);

	return ret;
}

static ssize_t store(struct kobject *kobj, struct attribute *attr,
		     const char *buf, size_t count)
{
	struct get_fuse_rule *data = to_get_fuse_rule(kobj);
	struct get_fuse_attr *cattr = to_attr(attr);
	ssize_t ret = -EIO;

	if (cattr->store != NULL)
		ret = cattr->store(data, buf, count);

	return ret;
}

static const struct sysfs_ops sysfs_ops = {
	.show = show,
	.store = store,
};

static struct kobj_type ktype_get_fuse = {
	.sysfs_ops = &sysfs_ops,
	.default_attrs = default_attrs,
};


static int get_fuse_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = pdev->dev.of_node;
	struct device_node *child = NULL;
	struct get_fuse_rule *ruler = NULL;
	int ret = 0;
	int index = 0;
	int id = 0;
	int modecount = 0;
	int info = 0;
	int i = 0;
	int railnum = 0;
	fuse_rail_info *rail = NULL;
	fuse_domain_info *t_domain= NULL;

	ret = of_property_read_u32(np, "fuse,railnum", &railnum);
	fuse_domain_info_t = (fuse_domain_info*)kmalloc(sizeof(fuse_domain_info) * railnum,
	                     GFP_KERNEL);
	pr_err("fuse_domain_info_t = %px\n", fuse_domain_info_t);

	if (fuse_domain_info_t == NULL)
		goto err_probe;

	for_each_child_of_node(np, child) {
		if (index >= NUM_COL)
			continue;

		pr_err("child_name%s\n", child->name);
		t_domain = &fuse_domain_info_t[index];
		pr_err("t_domain = %px\n", t_domain);

		if (t_domain == NULL) {
			pr_err("t_domain init err");
			goto err_probe;
		}

		ret = of_property_read_u32(child, "fuse,id", &id);
		pr_err("id = %d\n", id);

		if (ret < 0) {
			pr_err("id init err");
			goto err_probe;
		}

		t_domain->id = id;

		ret = of_property_read_u32(child, "fuse,modecount", &modecount);
		pr_err("modecount = %d\n", modecount);

		if (modecount < 0) {
			pr_err("modecount init err");
			goto err_probe;
		}

		t_domain->mode_count = modecount;

		t_domain->rail = (fuse_rail_info *)kmalloc(sizeof(fuse_rail_info) * modecount,
		                 GFP_KERNEL);
		pr_err("t_domain->rail = %px\n", t_domain->rail);

		if(t_domain->rail == NULL) {
			pr_err("t_domain->rail init err");
			goto err_probe;
		}

		for (i = 0; i < modecount; i++) {
			rail = &(t_domain->rail[i]);
			pr_err("lyn rail = %px\n", rail);

			ret = of_property_read_u32_index(child, "fuse,rail_info", (NUM_COL * i + 0),
			                                &info);
			rail->mode = info;

			ret = of_property_read_u32_index(child, "fuse,rail_info", (NUM_COL * i + 1),
			                                &info);
			rail->volt_addr = info;

			ret = of_property_read_u32_index(child, "fuse,rail_info", (NUM_COL * i + 2),
			                                &info);
			rail->volt_mask = info;

			ret = of_property_read_u32_index(child, "fuse,rail_info", (NUM_COL * i + 3),
			                                &info);
			rail->volt_offset = info;

			ret = of_property_read_u32_index(child, "fuse,rail_info", (NUM_COL * i + 4),
			                                &info);
			rail->volt_offset_addr = info;

			ret = of_property_read_u32_index(child, "fuse,rail_info", (NUM_COL * i + 5),
			                                &info);
			rail->volt_offset_mask = info;

			ret = of_property_read_u32_index(child, "fuse,rail_info", (NUM_COL * i + 6),
			                                &info);
			rail->volt_offset_offset = info;
		}
		index++;
	}

	ruler = (struct get_fuse_rule *)
	        devm_kzalloc(&pdev->dev, sizeof(*ruler), GFP_KERNEL);

	if (IS_ERR_OR_NULL(ruler)) {
		dev_err(dev, "alloc ruler fail\n");
		ret = -ENOMEM;
		goto err_probe;
	}

	ruler->name = "huawei-get_fuse";

	ret = kobject_init_and_add(&ruler->kobj, &ktype_get_fuse,
	                          &dev->kobj, "%s", ruler->name);

err_probe:
	return ret;
}

static const struct of_device_id get_fuse_of_match[] = {
	{
		.compatible = "huawei,get_fuse",
	},
};

static struct platform_driver get_fuse_driver = {
	.probe = get_fuse_probe,
	.driver = {
		.name = "hw-get_fuse",
		.owner = THIS_MODULE,
		.of_match_table = of_match_ptr(get_fuse_of_match),
	},
};

module_platform_driver(get_fuse_driver);

MODULE_LICENSE("GPL v2");
