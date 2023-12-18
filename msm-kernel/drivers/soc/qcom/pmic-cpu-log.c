/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: save panic cpu id driver.
 * Author: sunchongchong s00465875
 * Create: 2021-07-21
 */

#include <linux/err.h>
#include <linux/ipc_logging.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/nvmem-consumer.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/string.h>

/* SDAM NVMEM register offsets: */
#define REG_PUSH_PTR		0x46
#define REG_FIFO_DATA_START	0x4B
#define REG_FIFO_DATA_END	0xBF

static struct nvmem_device *g_nvmem = NULL;

static int pmic_cpu_log_parse(struct nvmem_device *nvmem)
{
	int ret;
	u8 cpuid;
	u8 cpunum = 0;

	ret = nvmem_device_read(nvmem, REG_PUSH_PTR, 1, &cpuid);
	if (ret < 0)
		return ret;
	if (cpuid)
		printk("last panic cpu id is 0x%x\n", cpuid);
	ret = nvmem_device_write(nvmem, REG_PUSH_PTR, 1, &cpunum);
	if (ret < 0)
		return ret;

	return 0;
}

int save_cpu_info(u8 cpu_id)
{
	int ret = -1;
	u8 cpunum = cpu_id + 1;
	if (g_nvmem == NULL) {
		printk("not register this nvmem!\n");
		return ret;
	}

	ret = nvmem_device_write(g_nvmem, REG_PUSH_PTR, 1, &cpunum);
	if (ret < 0)
		return ret;

	printk("panic cpu_id is 0x%x!\n", cpu_id);
	return ret;
}
EXPORT_SYMBOL(save_cpu_info);

static int pmic_cpu_log_probe(struct platform_device *pdev)
{
	struct nvmem_device *nvmem;
	int ret;

	nvmem = devm_nvmem_device_get(&pdev->dev, "fault_cpu");
	if (IS_ERR(nvmem)) {
		ret = PTR_ERR(nvmem);
		if (ret != -EPROBE_DEFER)
			dev_err(&pdev->dev, "failed to get nvmem device, ret=%d\n",
				ret);
		return ret;
	}
	g_nvmem = nvmem;

	ret = pmic_cpu_log_parse(nvmem);
	if (ret < 0)
		dev_err(&pdev->dev, "PMIC CPU log parsing failed, ret=%d\n",
			ret);

	return ret;
}

static int pmic_cpu_log_remove(struct platform_device *pdev)
{
	g_nvmem = NULL;

	return 0;
}

static const struct of_device_id pmic_cpu_log_of_match[] = {
	{ .compatible = "qcom,fault-cpu-log" },
	{}
};
MODULE_DEVICE_TABLE(of, pmic_cpu_log_of_match);

static struct platform_driver pmic_cpu_log_driver = {
	.driver = {
		.name = "qti-pmic-cpu-log",
		.of_match_table = of_match_ptr(pmic_cpu_log_of_match),
	},
	.probe = pmic_cpu_log_probe,
	.remove = pmic_cpu_log_remove,
};
module_platform_driver(pmic_cpu_log_driver);

MODULE_DESCRIPTION("PMIC fault cpu log driver");
MODULE_LICENSE("GPL v2");
