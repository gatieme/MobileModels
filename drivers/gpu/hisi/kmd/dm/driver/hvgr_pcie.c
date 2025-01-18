/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_pcie.h"

#include <linux/module.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/pci.h>
#include <linux/platform_drivers/pcie-kport-api.h>
#include <linux/of.h>

#include "hvgr_dm_defs.h"
#include "hvgr_defs.h"
#include "hvgr_dm_api.h"
#include "hvgr_pm_api.h"
#include "hvgr_regmap.h"
#include "hvgr_mem_api.h"
#include "hvgr_assert.h"
#include "hvgr_platform_api.h"

static void hvgr_pcie_mem_outbound(struct pci_dev *pdev)
{
	pcie_kport_outbound_atu(HVGR_PCIE_RC_ID, 0, 0x0,
		pci_resource_start(pdev, 0), 0x0, 0x01000000);

	/* link speed:0x0(gen1) 0x1(gen2) 0x2(gen3) */
	(void)pcie_kport_set_host_speed(HVGR_PCIE_RC_ID, 0x1);
}

int hvgr_crg_reset(struct hvgr_device * const gdev)
{
	u32 val = 0;
	void __iomem *pcie_addr = gdev->dm_dev.dev_reg.reg_base - HVGR_PCIE_REG_JM_TOP;

	writel(val, pcie_addr + HVGR_PCIE_REG_GLOBAL_RESET);
	udelay(1000); /* delay 1000 us is essential or GPU may die! */

	dev_info(gdev->dev, "send global reset command, val = 0x%x\n", val);
	return 0;
}

static int hvgr_pcie_irqs_init(struct pci_dev *pdev)
{
	struct hvgr_device *gdev = dev_get_drvdata(&pdev->dev);
	int nvec;
	const int irq_req = PCIE_GPU_IRQ_CNT;
	int irq_flag = PCI_IRQ_MSI | PCI_IRQ_AFFINITY;
	struct hvgr_irq *p = NULL;
	int i;

	/*
	 * SOC  hvgr irq order: JOB, MMU, GPU, EVENT;
	 * PCIe hvgr irq order: GPU, MMU, JOB, EVENT;
	 */
	int irq_n[] = {
		PCIE_JOB_IRQ,
		PCIE_MMU_IRQ,
		PCIE_GPU_IRQ,
		PCIE_FCP_IRQ,
		PCIE_CQ_IRQ,
		PCIE_CC_IRQ
	};

	hvgr_assert(sizeof(irq_n) >= sizeof(int) * GPU_IRQ_CNT);

	/* set up MSI capability for pcie FPGA and alloc MSI irqs */
	nvec = pci_alloc_irq_vectors(pdev, 1, irq_req, irq_flag);
	if (nvec != irq_req) {
		dev_err(gdev->dev, "pci_alloc_irq_vectors failed, nvec = %d\n", nvec);
		return -EINVAL;
	}
	dev_info(gdev->dev, "msi is enabled, irq = %u, nvec = %d\n", pdev->irq, nvec);

	for (i = 0; i < GPU_IRQ_CNT; i++) {
		p = &gdev->dm_dev.irqs[i];
		p->irq = pdev->irq + irq_n[i];
		p->flags = IRQF_TRIGGER_HIGH;
	}
	return 0;
}

static void hvgr_pcie_free_irqs(struct pci_dev *pdev)
{
	pci_free_irq_vectors(pdev);
}

static int hvgr_pcie_reg_map(struct pci_dev *pdev)
{
	struct hvgr_device *gdev = dev_get_drvdata(&pdev->dev);
	phys_addr_t bar0_addr;
	unsigned long bar0_size;
	int err;
	int reg_val = 0;

	/* rearrange pcie mem map to zone [0~2M] */
	hvgr_pcie_mem_outbound(pdev);
	pci_read_config_dword(pdev, 0x10, &reg_val);
	reg_val &= ((u32)0xFFFFFF);
	pci_write_config_dword(pdev, 0x10, reg_val);

	bar0_addr = pci_resource_start(pdev, 0);
	bar0_size = pci_resource_len(pdev, 0);

	/* request regions and ioremap resource */
	if (!request_mem_region(bar0_addr, bar0_size, dev_name(gdev->dev))) {
		dev_err(gdev->dev, "Register window unavailable\n");
		err = -EIO;
		goto out_region;
	}

	gdev->dm_dev.dev_reg.reg_base = ioremap(bar0_addr, bar0_size);
	if (gdev->dm_dev.dev_reg.reg_base == NULL) {
		dev_err(gdev->dev, "Can't remap register window\n");
		err = -EINVAL;
		goto out_ioremap;
	}

#ifdef HVGR_FEATURE_SYSTEM_CACHE
	if (of_property_read_u32_array(gdev->dev->of_node, "ctrl_reg",
		&gdev->dm_dev.ctrl_reg.reg_start, HVGR_CTRL_REG_PARA_NUM) == 0) {
		gdev->dm_dev.ctrl_reg.reg_base = ioremap(gdev->dm_dev.ctrl_reg.reg_start,
			gdev->dm_dev.ctrl_reg.reg_size);
		if (gdev->dm_dev.ctrl_reg.reg_base == NULL)
			dev_err(gdev->dev, "Map CTRL register failed");
		else
			hvgr_sc_config_remap_register(gdev);
	} else {
		dev_err(gdev->dev, "Can't find gpu ctrl register config");
	}
#endif

	/*
	 * PCIe reg space is 2M, first half for dbi regs,
	 * last half for GPU regs
	 */
	gdev->dm_dev.dev_reg.reg_base += HVGR_PCIE_REG_JM_TOP;

	gdev->dm_dev.uio_reg_start = bar0_addr + HVGR_PCIE_REG_JM_TOP + CQ_SUBMIT_FOR_UMD;

	/*
	 * At this time, pcie FPGA need reset before booting,
	 * or u must press reboot button on FPGA!
	 */
	err = hvgr_crg_reset(gdev);
	if (err) {
		dev_err(gdev->dev, "Failed to send global reset command\n");
		goto out_reset_fail;
	}

	return 0;

out_reset_fail:
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	if (gdev->dm_dev.ctrl_reg.reg_base != NULL)
		iounmap(gdev->dm_dev.ctrl_reg.reg_base);
#endif
	iounmap(gdev->dm_dev.dev_reg.reg_base);
out_ioremap:
	release_mem_region(bar0_addr, bar0_size);
out_region:
	return err;
}

static void hvgr_pcie_reg_ummap(struct pci_dev *pdev)
{
	struct hvgr_device *gdev = NULL;
	phys_addr_t bar0_addr;
	unsigned long bar0_size;

	gdev = dev_get_drvdata(&pdev->dev);
	bar0_addr = pci_resource_start(pdev, 0);
	bar0_size = pci_resource_len(pdev, 0);

	gdev->dm_dev.dev_reg.reg_base -= HVGR_PCIE_REG_JM_TOP;
#ifdef HVGR_FEATURE_SYSTEM_CACHE
	if (gdev->dm_dev.ctrl_reg.reg_base != NULL)
		iounmap(gdev->dm_dev.ctrl_reg.reg_base);
#endif
	iounmap(gdev->dm_dev.dev_reg.reg_base);
	release_mem_region(bar0_addr, bar0_size);
}

static int hvgr_pcie_get_of_node(struct pci_dev *pdev)
{
#ifdef CONFIG_OF
	struct device_node *np = of_find_compatible_node(NULL, NULL,
		"hisi,hvgr");

	if (np == NULL) {
		dev_err(&pdev->dev, "cannot find of_node with name \"hisi,hvgr\"");
		return -EINVAL;
	}

	pdev->dev.of_node = of_node_get(np);
	dev_info(&pdev->dev, "change pdev of_node to %pK\n", pdev->dev.of_node);
	return 0;
#else
	dev_err(&pdev->dev, "pcie_hvgr without of_node is not supported");
	return -EINVAL;
#endif
}

static void hvgr_pcie_put_of_node(struct pci_dev *pdev)
{
#ifdef CONFIG_OF
	of_node_put(pdev->dev.of_node);
	pdev->dev.of_node = NULL;
#else
	dev_err(&pdev->dev, "pcie_hvgr without of_node is not supported");
#endif
}


int hvgr_pcie_device_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
	int ret = 0;
	struct hvgr_device *gdev = NULL;

	if (pci_enable_device(pdev)) {
		dev_err(&pdev->dev, "%s: Cannot enable PCI device", __func__);
		return 1;
	}

	pci_set_master(pdev);

	gdev = kvzalloc(sizeof(*gdev), GFP_KERNEL);
	if (gdev == NULL) {
		dev_err(&pdev->dev, "Allocate hvgr device failed");
		ret = -ENOMEM;
		goto alloc_failed;
	}
	gdev->dev = &pdev->dev;
	gdev->device_type = HVGR_DEVICE_TYPE_PCIE;
	pci_set_drvdata(pdev, gdev);

	ret = hvgr_pcie_get_of_node(pdev);
	if (ret != 0)
		goto get_of_node_fail;

	ret = hvgr_pcie_irqs_init(pdev);
	if (ret) {
		dev_err(&pdev->dev, "Initialize hvgr irqs failed");
		ret = -ENOMEM;
		goto out_irqs;
	}

	ret = hvgr_pcie_reg_map(pdev);
	if (ret) {
		dev_err(&pdev->dev, "Map hvgr registers zone failed");
		goto out_map;
	}

	ret = hvgr_device_probe(gdev);
	if (ret) {
		dev_err(&pdev->dev, "hvgr init failed");
		goto init_failed;
	}
	return 0;

init_failed:
	hvgr_pcie_reg_ummap(pdev);
out_map:
	hvgr_pcie_free_irqs(pdev);
out_irqs:
	hvgr_pcie_put_of_node(pdev);
get_of_node_fail:
	kvfree(gdev);
alloc_failed:
	pci_disable_device(pdev);
	return ret;
}

void hvgr_pcie_device_remove(struct pci_dev *pdev)
{
	struct hvgr_device *gdev = dev_get_drvdata(&pdev->dev);

	if (unlikely(gdev == NULL))
		return;

	(void)hvgr_device_remove(gdev);
	hvgr_pcie_reg_ummap(pdev);
	hvgr_pcie_free_irqs(pdev);
	hvgr_pcie_put_of_node(pdev);
	kvfree(gdev);
	pci_disable_device(pdev);
	dev_set_drvdata(&pdev->dev, NULL);
}

void hvgr_pcie_device_shutdown(struct pci_dev *pdev)
{
	struct hvgr_device *gdev = dev_get_drvdata(&pdev->dev);

	if (unlikely(gdev == NULL))
		return;

	(void)hvgr_pm_suspend(gdev);
}

static struct pci_device_id hvgr_pcie_devid[] = {
	{ PCI_DEVICE(PCI_VENDOR_ID_HVGR, PCIE_DEVICE_ID_HVGR) },
	{ 0, }
};

static struct pci_driver hvgr_driver = {
	.name     = "pcie_hvgr",
	.id_table = hvgr_pcie_devid,
	.probe    = hvgr_pcie_device_probe,
	.remove   = hvgr_pcie_device_remove,
	.shutdown = hvgr_pcie_device_shutdown,
};

int __init hvgr_driver_init(void)
{
	return pci_register_driver(&hvgr_driver);
}

void __exit hvgr_driver_exit(void)
{
	pci_unregister_driver(&hvgr_driver);
}
module_init(hvgr_driver_init);
module_exit(hvgr_driver_exit);
MODULE_DESCRIPTION("driver for hvgr pcie fpga");
MODULE_DEVICE_TABLE(pci, hvgr_pcie_devid);
MODULE_LICENSE("GPL");

