/*
 * Hisi ISP CPE
 *
 * Copyright (c) 2017 Hisilicon Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/of.h>
#include <linux/regulator/consumer.h>
#include <linux/clk.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <linux/of_irq.h>
#include <linux/iommu.h>
#include <linux/pm_wakeup.h>
#include <linux/types.h>
#ifdef CONFIG_ION
#include <linux/ion.h>
#include <linux/ion/mm_ion.h>
#elif defined CONFIG_DMABUF_HEAPS
#include <linux/dma-heap.h>
#include <linux/dmabuf/mm_dma_heap.h>
#endif
#include <linux/genalloc.h>
#include <linux/iommu/mm_iommu.h>
#include <linux/version.h>
#include <platform_include/isp/linux/hipp.h>
#include "slam.h"
#include "ipp.h"
#include "slamtest.h"
#include "sub_ctrl_drv_priv.h"
#include "sub_ctrl_reg_offset.h"
#include "memory.h"
#include <platform_include/camera/jpeg/jpeg_base.h>

#define SLAM_BI_SID     (30)
#define SLAM_STAT_SID   (32)
#define SLAM_RATE_INDEX_MAX (3)

struct ipp_adapter_t {
	uint32_t cmd;
	int (*handler)(unsigned long args);
};

int kmsgcat_mask = (INFO_BIT | ERROR_BIT);
/*lint -e21 -e846 -e514 -e778 -e866 -e84 -e429 -e613 -e668*/
module_param_named(kmsgcat_mask, kmsgcat_mask, int, S_IRUGO | S_IWUSR | S_IWGRP);

enum HISP_CPE_CLK_TYPE {
	CLK_HIGH_RATE    = 541000000,
	CLK_NOMAL_RATE    = 406000000,
	CLK_LOW_RATE    = 325000000,
	CLK_ULTRA_LOW_RATE    = 271000000,
	MAX_CPE_CLK
};

enum HISP_CPE_IRQ_TYPE {
	CPE_IRQ_0        = 0,
	MAX_HISP_CPE_IRQ
};

enum hipp_fd_type_e {
	BI_SHARE_FD    = 0,
	STAT_SHARE_FD  = 1,
	MAX_HIPP_TYPE_ORB
};


unsigned int  clk_rate_map[4] = {
	[0] = CLK_HIGH_RATE,
	[1] = CLK_NOMAL_RATE,
	[2] = CLK_LOW_RATE,
	[3] = CLK_ULTRA_LOW_RATE,
};

struct hispcpe_s {
	struct miscdevice miscdev;
	struct platform_device *pdev;
	wait_queue_head_t cpe_wait;
	wait_queue_head_t slam_wait;
	int cpe_ready;
	int slam_ready;
	int initialized;
	unsigned int  sec_path;
	unsigned int  sec_req;
	atomic_t open_refs;
	struct regulator *cpe_supply;
	atomic_t cpe_supply_refs;
	atomic_t sec_slam_supply_refs;
	atomic_t cpe_slam_refs;
	atomic_t sec_slam_refs;
	struct mutex lock;
	unsigned int irq_num;
	unsigned int reg_num;
	unsigned int curr_slam_rate_value;
	unsigned int curr_cpe_rate_value;
	unsigned int ipp_set_rate_value;
	int irq[MAX_HISP_CPE_IRQ];
	struct resource *r[MAX_HISP_CPE_REG];
	void __iomem *reg[MAX_HISP_CPE_REG];
	struct iommu_domain *domain;
	struct hipp_common_s *ippdrv;
	struct hipp_common_s *sec_slamdrv;
	struct dma_buf *devbuf;
	struct dma_buf *modulebuf;
	unsigned int daddr;
	void *virt_addr;
	unsigned int jpg_clk_rate;
	unsigned int jpgclk_low_frequency;
	unsigned int jpgclk_off_frequency;
	struct clk *jpg_clk;
	struct wakeup_source *ipp_wakelock;
	struct mutex ipp_wakelock_mutex;
};

struct hispcpe_s *hispcpe_dev = NULL;

#define MEM_HISPCPE_SIZE                (0x00300000) /*  the cpe iova size */

#define ISP_TEXT_MEM_ATTR               (IOMMU_READ | IOMMU_CACHE | IOMMU_EXEC)
#define ISP_DATA_MEM_ATTR               (IOMMU_READ | IOMMU_WRITE | IOMMU_CACHE)
#define ISP_DATA_MEM_NO_CACHE_ATTR      (IOMMU_READ | IOMMU_WRITE)
#define ISP_DEV_MEM_ATTR                (IOMMU_DEVICE)

struct pw_memory_s {
	int shared_fd;
	int size;
	unsigned long prot;
};
struct memory_block_s {
	int shared_fd;
	int size;
	unsigned long prot;
	unsigned int da;
	int usage;
	void *viraddr;
};

struct power_para_s {
	unsigned int pw_flag;
	struct pw_memory_s mem;
};

#define HISP_CPE_PWRUP          _IOWR('C', 0x1001, int)
#define HISP_CPE_PWRDN          _IOWR('C', 0x1002, int)
#define HISP_CPE_MAP_BUF        _IOWR('C', 0x2003, int)
#define HISP_CPE_UNMAP_BUF      _IOWR('C', 0x2004, int)
#define HISP_CPE_SLAM_REQ       _IOWR('C', 0x2005, int)
#define HISP_CPE_SLAMTEST_REQ   _IOWR('C', 0x2006, int)
#define HISP_CPE_MAP_IOMMU      _IOWR('C', 0x2007, int)
#define HISP_CPE_UNMAP_IOMMU    _IOWR('C', 0x2008, int)

#define DTS_NAME_HISI_IPP "hisilicon,ipp"
#ifdef CONFIG_IPP_DEBUG
#define HISP_CPE_TIMEOUT_MS (300000)
#else
#define HISP_CPE_TIMEOUT_MS (3000)
#endif
#define min_func(a, b) (((a) < (b)) ? (a) : (b))

unsigned int g_share_fd_size[MAX_HIPP_TYPE_ORB] = { 0 };

static struct hispcpe_s *get_cpedev_bymisc(struct miscdevice *mdev)
{
	struct hispcpe_s *dev = NULL;

	if (!mdev) {
		pr_err("[%s] Failed : mdev.%pK\n", __func__, mdev);
		return NULL;
	}

	dev = container_of(mdev, struct hispcpe_s, miscdev);
	return dev;
}

void hispcpe_reg_set(unsigned int mode, unsigned int offset, unsigned int value)
{
	struct hispcpe_s *dev = hispcpe_dev;
	void __iomem *reg_base = dev->reg[mode];
	d("[%s] +\n", __func__);
	i("mode = %d, value = %d, reg = 0x%pK \n", mode, value, reg_base + offset);
	writel(value, reg_base + offset);
	d("[%s] -\n", __func__);
}

unsigned int hispcpe_reg_get(unsigned int mode, unsigned int offset)
{
	struct hispcpe_s *dev = hispcpe_dev;
	unsigned int value = 0;
	void __iomem *reg_base = dev->reg[mode];
	d("[%s] +\n", __func__);

	if (mode == SMMU_REG) {
		e("Failed : mode.(0x%x = 0x%x)\n", mode, SMMU_REG);
		return 0;
	}

	value = readl(reg_base + offset);
	d("[%s] -\n", __func__);
	return value;
}

static irqreturn_t hispcpe_irq_handler(int irq, void *devid)
{
	struct hispcpe_s *dev = NULL;
	unsigned int value = 0;
	union u_cmdlst_acpu_irq_reg2 reg2;
	union u_cmdlst_acpu_irq_reg2 regp;
	d("+\n");

	if ((dev = (struct hispcpe_s *)devid) == NULL) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return IRQ_NONE;
	}

	if (!dev->initialized) {
		pr_err("[%s] Failed : CPE Device Not Exist.%d\n", __func__, dev->initialized);
		return IRQ_NONE;
	}

	value = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_SLAM_IRQ_REG1_REG));
	pr_info("[%s] SLAM_IRQ. irq mask value = 0x%x.\n", __func__, value);
	regp.u32 = readl((volatile void __iomem *)(dev->reg[CPE_TOP] +
					 SUB_CTRL_CMDLST_ACPU_IRQ_REG2_REG));
	pr_info("[%s] SLAM_IRQ. ACPU irq state value = 0x%x.\n", __func__, regp.u32);
	reg2.bits.cmdlst_acpu_irq_state_mask    = regp.bits.cmdlst_acpu_irq_state_mask;
	reg2.bits.cmdlst_acpu_irq_state_raw    = regp.bits.cmdlst_acpu_irq_state_raw;

	if (reg2.bits.cmdlst_acpu_irq_state_raw != 0) {
		pr_info("SLAM_CMDLST_ACPU_IRQ COME!");
		dev->slam_ready = 1;
		writel(0x2, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_CMDLST_ACPU_IRQ_REG0_REG));
		wake_up_interruptible(&dev->slam_wait);
	}

	d("-\n");
	return IRQ_HANDLED;
}

static int hispcpe_cmdlst_clock_enable(struct hispcpe_s *dev)
{
	union u_top_axi_cfg0 cfg;

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	i("+\n");
	cfg.u32 = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_TOP_AXI_CFG0_REG));
	cfg.bits.cmdlst_clken = 1;
	writel(cfg.u32, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_TOP_AXI_CFG0_REG));
	i("-\n");
	return 0;
}

static int hispcpe_set_qos(struct hispcpe_s *dev)
{
	unsigned int qos_val = 0;

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	i("+\n");
	writel(0x0, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL0_0_REG));
	qos_val = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL0_0_REG));
	pr_err("[%s] IPP_RD QOS JPG_FLUX_CTRL0_0 = 0x%x (0x0 wanted)\n", __func__, qos_val);
	writel(0x8000105, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL0_1_REG));
	qos_val = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL0_1_REG));
	pr_err("[%s] IPP_RD QOS JPG_FLUX_CTRL0_1 = 0x%x (0x8000105 wanted)\n", __func__, qos_val);
	writel(0x0, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL1_0_REG));
	qos_val = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL1_0_REG));
	pr_err("[%s] IPP_RD QOS JPG_FLUX_CTRL1_0 = 0x%x (0x0 wanted)\n", __func__, qos_val);
	writel(0x8000085, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL1_1_REG));
	qos_val = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_JPG_FLUX_CTRL1_1_REG));
	pr_err("[%s] IPP_RD QOS JPG_FLUX_CTRL1_1 = 0x%x (0x8000085 wanted)\n", __func__, qos_val);
	i("-\n");
	return 0;
}


static int hispcpe_cmdlst_clock_disable(struct hispcpe_s *dev)
{
	union u_top_axi_cfg0 cfg;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	cfg.u32 = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_TOP_AXI_CFG0_REG));
	cfg.bits.cmdlst_clken = 0;
	writel(cfg.u32, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_TOP_AXI_CFG0_REG));
	d("-\n");
	return 0;
}

static int hispcpe_irq_config(struct hispcpe_s *dev)
{
	union u_cmdlst_chn1 cfg_cmdlst_ch1_irq;
	union u_cmdlst_acpu_irq_reg1 cfg_acpu;
	i("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	// cmdlst channel 1 mask, channel 0 default unmask.
	cfg_cmdlst_ch1_irq.u32 = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_CMDLST_CHN1_REG));
	cfg_cmdlst_ch1_irq.bits.cmdlst_eof_mask_chn1 = 3;
	writel(cfg_cmdlst_ch1_irq.u32, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_CMDLST_CHN1_REG));
	// ACPU mask.
	cfg_acpu.u32 = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_CMDLST_ACPU_IRQ_REG1_REG));
	cfg_acpu.bits.cmdlst_acpu_irq_mask = 0x1;
	writel(cfg_acpu.u32, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_CMDLST_ACPU_IRQ_REG1_REG));
	i("-\n");
	return 0;
}

static int dataflow_cvdr_global_config(struct hispcpe_s *dev)
{
	unsigned int reg_val;
	reg_val = (0 << 0)        // axiwrite_du_threshold = 0
			  | (34 << 8)     // du_threshold_reached = 34
			  | (19 << 16)     // max_axiread_id = 19
			  | (11 << 24);     // max_axiwrite_id = 11
	writel(reg_val, (volatile void __iomem *)(dev->reg[CVDR_REG] + 0x0));
	return CPE_FW_OK;
}

static int ipp_setclk_enable(struct hispcpe_s *dev)
{
	int ret;

	if ((ret = jpeg_ipp_set_rate(dev->jpg_clk, dev->jpgclk_low_frequency)) != 0)
		pr_err("[%s] Failed: jpeg_ipp_set_rate  %d  %d\n", __func__, dev->jpgclk_low_frequency, ret);

	if ((ret = jpeg_ipp_clk_prepare_enable(dev->jpg_clk)) != 0) {
		pr_err("[%s] Failed: jpeg_ipp_clk_prepare_enable.%d\n", __func__, ret);
		return ret;
	}

	return ret;
}

static int ipp_setclk_disable(struct hispcpe_s *dev)
{
	int ret = 0;
	jpeg_ipp_clk_disable_unprepare(dev->jpg_clk);

	if ((ret = jpeg_ipp_set_rate(dev->jpg_clk, dev->jpgclk_off_frequency)) != 0) {
		pr_err("[%s] Failed: jpeg_ipp_set_rate.%d\n", __func__, ret);
		return ret;
	}

	return 0;
}

int sec_slam_powerup(struct hispcpe_s *dev, int share_fd)
{
	int ret = 0, err = 0;
	i("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (share_fd < 0) {
		pr_err("[%s] Failed : share_fd.%d\n", __func__, share_fd);
		return -EINVAL;
	}

	if (atomic_read(&dev->sec_slam_supply_refs) > 0) {
		pr_err("[%s] Failed: sec_slam_supply Opened.0x%x\n", __func__, atomic_read(&dev->sec_slam_supply_refs));
		return -EBUSY;
	}

	if (!dev->sec_slamdrv) {
		pr_err("[%s] Failed : sec_slamdrv.%pK\n", __func__, dev->sec_slamdrv);
		return -ENOMEM;
	}

	if (!dev->sec_slamdrv->enable_jpgclk) {
		pr_err("[%s] Failed : sec_slamdrv->enable_jpgclk.%pK\n", __func__, dev->sec_slamdrv->enable_jpgclk);
		return -ENOMEM;
	}

	if ((ret = regulator_enable(dev->cpe_supply)) != 0) {
		pr_err("[%s] Failed: sec_slam regulator_enable.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = ipp_setclk_enable(dev)) != 0) {
		pr_err("[%s] Failed: ipp_setclk_enable.%d\n", __func__, ret);
		goto fail_enjgpclk;
	}

	if ((ret = atfhipp_orb_init()) != 0) {
		pr_err("[%s] Failed : orb_init.%d\n", __func__, ret);
		goto fail_enjgpclk;
	}

	if ((ret = hispcpe_cmdlst_clock_enable(dev)) != 0) {
		pr_err("[%s] Failed: hispcpe_cmdlst_clock_enable.%d\n", __func__, ret);
		goto fail_cmdlist;
	}

	if ((ret = hispcpe_irq_config(dev)) != 0) {
		pr_err("[%s] Failed: hispcpe_cmdlst_clock_enable.%d\n", __func__, ret);
		goto fail_irq;
	}

	if ((ret = dataflow_cvdr_global_config(dev)) != 0) {
		pr_err("[%s] Failed: dataflow_cvdr_global_config.%d\n", __func__, ret);
		goto  fail_irq;
	}

	if ((ret = hipp_ptable_secmem_init(share_fd)) < 0) {
		e("[%s] Failed : hisp_secmem_init.%d\n", __func__, ret);
		goto fail_irq;
	}

	atomic_set(&dev->sec_slam_supply_refs, 1);
	dev->sec_path = 1;
	i("-\n");
	return 0;
fail_irq:

	if ((err = hispcpe_cmdlst_clock_disable(dev)) != 0)
		pr_err("[%s] Failed: sec_slam_cmdlst_clock_disable.%d\n", __func__, err);

fail_cmdlist:

	if ((err = ipp_setclk_disable(dev)) != 0)
		pr_err("[%s] Failed : ipp_setclk_disable.%d\n", __func__, err);

fail_enjgpclk:

	if ((err = regulator_disable(dev->cpe_supply)) != 0)
		pr_err("[%s] Failed: sec_slam regulator_disable.%d\n", __func__, err);

	return ret;
}
EXPORT_SYMBOL(sec_slam_powerup);

int hispcpe_powerup(struct hispcpe_s *dev)
{
	int ret = 0, err = 0;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (atomic_read(&dev->cpe_supply_refs) > 0) {
		pr_err("[%s] Failed: cpe_supply Opened.0x%x\n", __func__, atomic_read(&dev->cpe_supply_refs));
		return -EBUSY;
	}

	if ((ret = regulator_enable(dev->cpe_supply)) != 0) {
		pr_err("[%s] Failed: cpe regulator_enable.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = ipp_setclk_enable(dev)) != 0) {
		pr_err("[%s] Failed: ipp_setclk_enable.%d\n", __func__, ret);
		goto fail_enjgpclk;
	}

	dev->curr_slam_rate_value = dev->jpgclk_low_frequency;
	dev->curr_cpe_rate_value = dev->jpgclk_low_frequency;
	dev->ipp_set_rate_value = dev->jpgclk_low_frequency;

	if ((ret = hispcpe_cmdlst_clock_enable(dev)) != 0) {
		pr_err("[%s] Failed: hispcpe_cmdlst_clock_enable.%d\n", __func__, ret);
		goto fail_cmdlist;
	}

	if ((ret = hispcpe_irq_config(dev)) != 0) {
		pr_err("[%s] Failed: hispcpe_cmdlst_clock_enable.%d\n", __func__, ret);
		goto fail_irq;
	}

	if ((ret = hispcpe_set_qos(dev)) != 0) {
		pr_err("[%s] Failed: hispcpe_set_QOS.%d\n", __func__, ret);
		goto fail_irq;
	}

	if ((ret = dataflow_cvdr_global_config(dev)) != 0) {
		pr_err("[%s] Failed: dataflow_cvdr_global_config.%d\n", __func__, ret);
		return ret;
	}

	if (!dev->ippdrv->enable_smmu) {
		pr_err("[%s] Failed : ippdrv->enable_smmu.%pK\n", __func__, dev->ippdrv->enable_smmu);
		return -ENOMEM;
	}

	if ((ret = dev->ippdrv->enable_smmu(dev->ippdrv)) != 0) {
		pr_err("[%s] Failed : dev->ippdrv->enable_smmu.%d\n", __func__, ret);
		return ret;
	}

	atomic_set(&dev->cpe_supply_refs, 1);
	d("-\n");
	return 0;
fail_irq:

	if ((err = hispcpe_cmdlst_clock_disable(dev)) != 0)
		pr_err("[%s] Failed: hispcpe_cmdlst_clock_disable.%d\n", __func__, err);

fail_cmdlist:

	if ((err = ipp_setclk_disable(dev)) != 0)
		pr_err("[%s] Failed : ipp_setclk_disable.%d\n", __func__, err);

fail_enjgpclk:

	if ((err = regulator_disable(dev->cpe_supply)) != 0)
		pr_err("[%s] Failed: cpe regulator_disable.%d\n", __func__, err);

	return ret;
}
EXPORT_SYMBOL(hispcpe_powerup);

int hispcpe_powerdn(struct hispcpe_s *dev)
{
	int ret = 0;
	d("+\n");

	if (atomic_read(&dev->cpe_supply_refs) <= 0) {
		pr_err("[%s] Failed: cpe_supply not Opened.0x%x\n", __func__, atomic_read(&dev->cpe_supply_refs));
		return -EINVAL;
	}

	atomic_set(&dev->cpe_supply_refs, 0);
	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (!dev->ippdrv) {
		pr_err("[%s] Failed : ippdrv.%pK\n", __func__, dev->ippdrv);
		return -ENOMEM;
	}

	if (!dev->ippdrv->disable_smmu) {
		pr_err("[%s] Failed : ippdrv->disable_smmu.%pK\n", __func__, dev->ippdrv->disable_smmu);
		return -ENOMEM;
	}

	if ((ret = dev->ippdrv->disable_smmu(dev->ippdrv)) != 0) {
		pr_err("[%s] Failed : dev->ippdrv->disable_smmu.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = hispcpe_cmdlst_clock_disable(dev)) != 0)
		pr_err("[%s] Failed: hispcpe_cmdlst_clock_disable.%d\n", __func__, ret);

	if ((ret = ipp_setclk_disable(dev)) != 0) {
		pr_err("[%s] Failed: ipp_setclk_disable.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = regulator_disable(dev->cpe_supply)) != 0)
		pr_err("[%s] Failed: cpe regulator_disable.%d\n", __func__, ret);

	d("-\n");
	return 0;
}
EXPORT_SYMBOL(hispcpe_powerdn);

int sec_slam_powerdn(struct hispcpe_s *dev)
{
	int ret = 0;
	dev->sec_path = 0;
	d("+\n");

	if (atomic_read(&dev->sec_slam_supply_refs) <= 0) {
		pr_err("[%s] Failed: sec_slam_supply not Opened.0x%x\n", __func__, atomic_read(&dev->sec_slam_supply_refs));
		return -EINVAL;
	}

	atomic_set(&dev->sec_slam_supply_refs, 0);
	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if ((ret = hipp_ptable_secmem_deinit()) != 0)
		pr_err("[%s] Failed: hipp_ptable_secmem_deinit.%d\n", __func__, ret);

	if ((ret = atfhipp_orb_deinit()) != 0) {
		pr_err("[%s] Failed : orb_deinit.%d\n", __func__, ret);
		return ret;
	}

	if (!dev->sec_slamdrv) {
		pr_err("[%s] Failed : sec_slamdrv.%pK\n", __func__, dev->sec_slamdrv);
		return -ENOMEM;
	}

	if (!dev->sec_slamdrv->disable_jpgclk) {
		pr_err("[%s] Failed : sec_slamdrv->disable_jpgclk.%pK\n", __func__, dev->sec_slamdrv->disable_jpgclk);
		return -ENOMEM;
	}

	if ((ret = ipp_setclk_disable(dev)) != 0) {
		pr_err("[%s] Failed: ipp_setclk_disable.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = regulator_disable(dev->cpe_supply)) != 0)
		pr_err("[%s] Failed: slam regulator_disable.%d\n", __func__, ret);

	d("-\n");
	return 0;
}
EXPORT_SYMBOL(sec_slam_powerdn);

static int hispcpe_slam_clk_enable(struct hispcpe_s *dev)
{
	union u_slam_crg_cfg0 cfg;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (0 == dev->sec_path) {
		if (atomic_read(&dev->cpe_supply_refs) <= 0) {
			pr_err("[%s] Failed: cpe_supply not Opened.0x%x\n", __func__, atomic_read(&dev->cpe_supply_refs));
			return -EINVAL;
		}
	} else if (1 == dev->sec_path) {
		if (atomic_read(&dev->sec_slam_supply_refs) <= 0) {
			pr_err("[%s] Failed: sec_slam_supply not Opened.0x%x\n", __func__, atomic_read(&dev->sec_slam_supply_refs));
			return -EINVAL;
		}
	} else {
		pr_err("[%s] Failed: check sec_path\n", __func__);
	}

	if (0 == dev->sec_path) {
		if (atomic_read(&dev->cpe_slam_refs) > 0) {
			pr_err("[%s] Failed: cpe slam Opened.0x%x\n", __func__, atomic_read(&dev->cpe_slam_refs));
			return -EINVAL;
		}
	} else if (1 == dev->sec_path) {
		if (atomic_read(&dev->sec_slam_refs) > 0) {
			pr_err("[%s] Failed: cpe slam Opened.0x%x\n", __func__, atomic_read(&dev->sec_slam_refs));
			return -EINVAL;
		}
	} else {
		pr_err("[%s] Failed: check sec_path\n", __func__);
	}

	cfg.u32 = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_SLAM_CRG_CFG0_REG));
	cfg.bits.slam_clken = 1;
	writel(cfg.u32, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_SLAM_CRG_CFG0_REG));

	if (0 == dev->sec_path) {
		atomic_set(&dev->cpe_slam_refs, 1);
	} else if (1 == dev->sec_path) {
		atomic_set(&dev->sec_slam_refs, 1);
	}

	d("-\n");
	return 0;
}

static int hispcpe_slam_clk_disable(struct hispcpe_s *dev)
{
	union u_slam_crg_cfg0 cfg;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (0 == dev->sec_path) {
		if (atomic_read(&dev->cpe_supply_refs) <= 0) {
			pr_err("[%s] Failed: cpe_supply not Opened.0x%x\n", __func__, atomic_read(&dev->cpe_supply_refs));
			return -EINVAL;
		}
	} else if (1 == dev->sec_path) {
		if (atomic_read(&dev->sec_slam_supply_refs) <= 0) {
			pr_err("[%s] Failed: sec_slam_supply not Opened.0x%x\n", __func__, atomic_read(&dev->sec_slam_supply_refs));
			return -EINVAL;
		}
	} else {
		pr_err("[%s] Failed: check sec_path\n", __func__);
	}

	if (0 == dev->sec_path) {
		if (atomic_read(&dev->cpe_slam_refs) <= 0) {
			pr_err("[%s] Failed: cpe slam Opened.0x%x\n", __func__, atomic_read(&dev->cpe_slam_refs));
			return -EINVAL;
		}
	} else if (1 == dev->sec_path) {
		if (atomic_read(&dev->sec_slam_refs) <= 0) {
			pr_err("[%s] Failed: cpe slam Opened.0x%x\n", __func__, atomic_read(&dev->sec_slam_refs));
			return -EINVAL;
		}
	} else {
		pr_err("[%s] Failed: check sec_path\n", __func__);
	}

	cfg.u32 = readl((volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_SLAM_CRG_CFG0_REG));
	cfg.bits.slam_clken = 0;
	writel(cfg.u32, (volatile void __iomem *)(dev->reg[CPE_TOP] + SUB_CTRL_SLAM_CRG_CFG0_REG));

	if (0 == dev->sec_path) {
		atomic_set(&dev->cpe_slam_refs, 0);
	} else if (1 == dev->sec_path) {
		atomic_set(&dev->sec_slam_refs, 0);
	}

	d("-\n");
	return 0;
}

static int hispcpe_clean_wait_flag(struct hispcpe_s *dev, unsigned int wait_mode)
{
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (wait_mode == 0) {
		dev->cpe_ready = 0;
	} else if (wait_mode == 1) {
		dev->slam_ready = 0;
	}

	d("-\n");
	return 0;
}

static int hispcpe_wait(struct hispcpe_s *dev, unsigned int wait_mode)
{
	int ret = 0;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (wait_mode == 0) {
		if ((ret = wait_event_interruptible_timeout(dev->cpe_wait, dev->cpe_ready, HISP_CPE_TIMEOUT_MS)) < 0) {
			pr_err("[%s] Failed : wait_event_interruptible_timeout.%d\n", __func__, ret);
			return ret;
		}
	} else {
		if ((ret = wait_event_interruptible_timeout(dev->slam_wait, dev->slam_ready, HISP_CPE_TIMEOUT_MS)) < 0) {
			pr_err("[%s] Failed : wait_event_interruptible_timeout.%d\n", __func__, ret);
			return ret;
		}
	}

	d("-\n");
	return 0;
}

int hispcpe_slam_request(struct hispcpe_s *dev, msg_req_slam_request_t *ctrl)
{
	int ret = 0;
	d("+\n");

	if (!dev || !ctrl) {
		pr_err("[%s] Failed : dev.%pK, ctrl.%pK\n", __func__, dev, ctrl);
		return -EINVAL;
	}

	if ((ret = hispcpe_clean_wait_flag(dev, 1)) < 0) {
		pr_err("[%s] Failed : hispcpe_clean_wait_flag.%d\n", __func__, ret);
		return ret;
	}

	slam_request_handler(ctrl);
	if ((ret = hispcpe_wait(dev, 1)) < 0) {
		pr_err("[%s] Failed : hispcpe_wait.%d\n", __func__, ret);
		return ret;
	}

	slam_eof_handler(ctrl);
	d("-\n");
	return 0;
}
EXPORT_SYMBOL(hispcpe_slam_request);

int hispcpe_slamtest_request(struct hispcpe_s *dev, msg_req_slamtest_request_t *ctrl)
{
	int ret = 0;
	d("+\n");

	if (!dev || !ctrl) {
		pr_err("[%s] Failed : dev.%pK, ctrl.%pK\n", __func__, dev, ctrl);
		return -EINVAL;
	}

	if ((ret = hispcpe_clean_wait_flag(dev, 1)) < 0) {
		pr_err("[%s] Failed : hispcpe_clean_wait_flag.%d\n", __func__, ret);
		return ret;
	}

	slamtest_request_handler(ctrl);
	if ((ret = hispcpe_wait(dev, 1)) < 0) {
		pr_err("[%s] Failed : hispcpe_wait.%d\n", __func__, ret);
		return ret;
	}

	slamtest_eof_handler();
	d("-\n");
	return 0;
}
EXPORT_SYMBOL(hispcpe_slamtest_request);

static int hispcpe_map_kernel(struct hispcpe_s *dev, unsigned long args)
{
	void *virt_addr = NULL;
	struct memory_block_s  pst_frame_buf = { 0 };
	unsigned int iova = 0;
	unsigned long iova_size = 0;
	int ret = 0;

	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	i("+\n");

	if ((ret = copy_from_user(&pst_frame_buf, (void __user *)args, sizeof(struct memory_block_s))) != 0) {
		pr_err("[%s] copy_from_user.%d\n", __func__, ret);
		return -EFAULT;
	}

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (pst_frame_buf.shared_fd < 0) {
		pr_err("[%s] Failed : hare_fd.%d\n", __func__, pst_frame_buf.shared_fd);
		return -EINVAL;
	}

	dev->devbuf = dma_buf_get(pst_frame_buf.shared_fd);
	if (IS_ERR_OR_NULL(dev->devbuf)) {
		pr_err("[%s] Failed : dma_buf_get, buf.%pK\n", __func__, dev->devbuf);
		return -EINVAL;
	}

	iova = kernel_iommu_map_dmabuf(&dev->pdev->dev, dev->devbuf, pst_frame_buf.prot, &iova_size);
	if (iova == 0) {
		pr_err("[%s] Failed : mm_iommu_map_sg\n", __func__);
		goto err_dma_buf_get;
	}

	if (pst_frame_buf.size != iova_size) {
		pr_err("[%s] hisi_iommu_map_range failed:  %d len 0x%lx\n", __func__, pst_frame_buf.size, iova_size);
		goto err_hisi_iommu_check;
	}

	if ((ret = dma_buf_begin_cpu_access(dev->devbuf, DMA_FROM_DEVICE)) < 0) {
		pr_err("[%s] hisi_iommu_map_range failed: ret.%d\n", __func__, ret);
		goto err_hisi_iommu_check;
	}

	virt_addr = dma_buf_kmap(dev->devbuf, 0);
	if (NULL == virt_addr) {
		pr_err("[%s] Failed : dma_buf_kmap.%pK\n", __func__, virt_addr);
		goto err_cpu_access;
	}

	dev->virt_addr = virt_addr;
	dev->daddr = iova;
	pr_info("[after map kernel]virt_addr = 0x%lx, da.(0x%x, 0x%x)", (unsigned long)(uintptr_t)dev->virt_addr, iova,
			dev->daddr); /*lint !e626 */
	i("-\n");
	return ret;
err_cpu_access:
	ret = dma_buf_end_cpu_access(dev->devbuf, DMA_FROM_DEVICE);
err_hisi_iommu_check:
	ret = kernel_iommu_unmap_dmabuf(&dev->pdev->dev, dev->devbuf, iova);
err_dma_buf_get:
	dma_buf_put(dev->devbuf);
	return -ENOMEM;
}

static int hispcpe_unmap_kernel(struct hispcpe_s *dev)
{
	int ret = 0;
	i("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	dma_buf_kunmap(dev->devbuf, 0, dev->virt_addr);
	ret = dma_buf_end_cpu_access(dev->devbuf, DMA_FROM_DEVICE);
	if (ret < 0)
		pr_err("[%s] dma_buf_end_cpu_access failed: ret.%d\n", __func__, ret);

	ret = kernel_iommu_unmap_dmabuf(&dev->pdev->dev, dev->devbuf, dev->daddr);
	if (ret < 0)
		pr_err("[%s] kernel_iommu_unmap_dmabuf failed: ret.%d\n", __func__, ret);

	dma_buf_put(dev->devbuf);
	dev->devbuf = NULL;
	i("-\n");
	return 0;
}

static int hispcpe_map_iommu(struct hispcpe_s *dev, struct memory_block_s *buf)
{
	unsigned int iova;
	unsigned long size;
	int ret = 0;
	i("+\n");

	if (buf->shared_fd < 0) {
		pr_err("[%s] Failed : hare_fd.%d\n", __func__, buf->shared_fd);
		return -EINVAL;
	}

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	dev->modulebuf = dma_buf_get(buf->shared_fd);
	if (IS_ERR_OR_NULL(dev->modulebuf)) {
		pr_err("[%s] Failed : dma_buf_get, buf.%pK\n", __func__, dev->modulebuf);
		return -EINVAL;
	}

	iova = kernel_iommu_map_dmabuf(&dev->pdev->dev, dev->modulebuf, buf->prot, &size);
	if (iova == 0) {
		pr_err("[%s] Failed : kernel_iommu_map_dmabuf\n", __func__);
		goto err_dma_buf_get;
	}
	if (buf->size != size) {
		pr_err("[%s] hisi_iommu_map_range failed:  %d len 0x%lx\n", __func__, buf->size, size);
		goto err_dma_buf_get;
	}

	buf->da = iova;
	pr_info("[after map iommu]da.(0x%x)", buf->da);/*lint !e626 */
err_dma_buf_get:
	dma_buf_put(dev->modulebuf);
	i("-\n");
	return ret;
}

void hispcpe_unmap_iommu(struct hispcpe_s *dev, struct memory_block_s *buf)
{
	int ret = 0;
	i("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return;
	}

	ret = kernel_iommu_unmap_dmabuf(&dev->pdev->dev, dev->modulebuf, buf->da);
	if (ret < 0)
		pr_err("[%s] Failed : kernel_iommu_unmap_dmabuf\n", __func__);

	dma_buf_put(dev->modulebuf);
	dev->modulebuf = NULL;
	i("-\n");
}

int ipp_set_rate(struct hispcpe_s *dev)
{
	unsigned int ret = 0;
	unsigned int curr_max_rate = dev->curr_cpe_rate_value;

	if (dev->curr_slam_rate_value > dev->curr_cpe_rate_value)
		curr_max_rate = dev->curr_slam_rate_value;

	if (curr_max_rate !=  dev->ipp_set_rate_value) {
		pr_info("curr_max_rate  = %d\n", curr_max_rate);

		if ((ret = jpeg_ipp_set_rate(dev->jpg_clk, curr_max_rate)) != 0) {
			pr_err("[%s] Failed to set ipp  rate mode: %d\n", __func__, curr_max_rate);

			if ((ret = jpeg_ipp_set_rate(dev->jpg_clk, dev->jpgclk_low_frequency)) != 0) {
				pr_err("[%s] Failed to set ipp  rate mode: %d\n", __func__, dev->jpgclk_low_frequency);
				return -EINVAL;
			}
		}

		dev->ipp_set_rate_value = curr_max_rate;
	}

	return 0;
}
static int slam_test_process(struct hispcpe_s *dev, unsigned long args)
{
	unsigned int ret = 0;
	msg_req_slamtest_request_t *ctrl_slamtest = NULL;

	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	ctrl_slamtest = (msg_req_slamtest_request_t *)kmalloc(sizeof(msg_req_slamtest_request_t), GFP_KERNEL);
	if (NULL == ctrl_slamtest) {
		pr_err(" fail to kmalloc ctrl_slamtest\n");
		goto free_slamtest_kmalloc_memory;
	}

	if ((ret = copy_from_user(ctrl_slamtest, (void __user *)args, sizeof(msg_req_slamtest_request_t))) != 0) {
		pr_err("[%s] copy_from_user.%d\n", __func__, ret);
		goto free_slamtest_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_clk_enable(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_clk_enable.%d\n", __func__, ret);
		goto free_slamtest_kmalloc_memory;
	}

	if ((ret = hispcpe_slamtest_request(dev, ctrl_slamtest)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_request.%d\n", __func__, ret);
		goto free_slamtest_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_clk_disable(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_clk_disable.%d\n", __func__, ret);
		goto free_slamtest_kmalloc_memory;
	}

free_slamtest_kmalloc_memory:

	if (ctrl_slamtest) {
		kfree(ctrl_slamtest);
		ctrl_slamtest = NULL;
	}

	return ret ;
}

static int slam_process(struct hispcpe_s *dev, unsigned long args)
{
	unsigned int ret = 0;
	unsigned int slam_rate_index = 0;
	msg_req_slam_request_t *ctrl_slam = NULL;

	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	if (!dev->ippdrv) {
		pr_err("[%s] Failed : ippdrv.%pK\n", __func__, dev->ippdrv);
		return -EINVAL;
	}

	if (!dev->ippdrv->lock_usecase) {
		pr_err("[%s] Failed : ippdrv->lock_usecase.%pK\n", __func__, dev->ippdrv->lock_usecase);
		return -EINVAL;
	}

	if ((ret = dev->ippdrv->lock_usecase(dev->ippdrv)) != 0) {
		pr_err("[%s] Failed : dev->ippdrv->lock_usecase.%d\n", __func__, ret);
		return ret;
	}

	ctrl_slam = (msg_req_slam_request_t *)kmalloc(sizeof(msg_req_slam_request_t), GFP_KERNEL);
	if (NULL == ctrl_slam) {
		pr_err(" fail to kmalloc ctrl_slam\n");
		goto free_slam_kmalloc_memory;
	}

	if ((ret = copy_from_user(ctrl_slam, (void __user *)args, sizeof(msg_req_slam_request_t))) != 0) {
		pr_err("[%s] copy_from_user.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	slam_rate_index = ctrl_slam->slam_rate_value;

	if (slam_rate_index > SLAM_RATE_INDEX_MAX) {
		pr_err("[%s] check slam rate index.%d\n", __func__, slam_rate_index);
		goto free_slam_kmalloc_memory;
	} else {
		dev->curr_slam_rate_value = clk_rate_map[slam_rate_index];
	}

	if ((ret = ipp_set_rate(dev)) != 0) {
		pr_err("[%s] Failed : slam_set_rate.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if (ctrl_slam->pyramid_layer_num > MAX_PYRAMID_LAYER) {
		pr_err("[%s] Failed : Invalid pyramid_layer_num = %d\n", __func__, ctrl_slam->pyramid_layer_num);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_clk_enable(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_clk_enable.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_request(dev, ctrl_slam)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_request.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_clk_disable(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_clk_disable.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

free_slam_kmalloc_memory:

	if (ctrl_slam) {
		kfree(ctrl_slam);
		ctrl_slam = NULL;
	}

	if ((ret = dev->ippdrv->unlock_usecase(dev->ippdrv)) != 0) {
		pr_err("[%s] Failed : dev->ippdrv->unlock_usecase.%d\n", __func__, ret);
		return ret;
	}

	return ret ;
}

static int sec_slam_smmu_int(struct hispcpe_s *dev)
{
	unsigned int ret = 0;

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv) {
		pr_err("[%s] Failed : sec_slamdrv.%pK\n", __func__, dev->sec_slamdrv);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv->enable_smmu) {
		pr_err("[%s] Failed : sec_slamdrv->enable_smmu.%pK\n", __func__, dev->sec_slamdrv->enable_smmu);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv->setsid_smmu) {
		pr_err("[%s] Failed : sec_slamdrv->setsid_smmu.%pK\n", __func__, dev->sec_slamdrv->setsid_smmu);
		return -EINVAL;
	}

	if ((ret = dev->sec_slamdrv->enable_smmu(dev->sec_slamdrv)) != 0) {
		pr_err("[%s] Failed : dev->sec_slamdrv->enable_smmu.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = dev->sec_slamdrv->setsid_smmu(dev->sec_slamdrv, SLAM_BI_SID, TRUSTED)) != 0) {
		pr_err("[%s] Failed : sec_slamdrv->setsid_smmu.%pK, sid.%d\n", __func__, dev->sec_slamdrv->setsid_smmu,
			SLAM_BI_SID);
		return ret;
	}

	if ((ret = dev->sec_slamdrv->setsid_smmu(dev->sec_slamdrv, SLAM_STAT_SID, TRUSTED)) != 0) {
		pr_err("[%s] Failed : sec_slamdrv->setsid_smmu.%pK, sid.%d\n", __func__, dev->sec_slamdrv->setsid_smmu,
			SLAM_STAT_SID);
		return ret;
	}

	return ret;
}

static int sec_slam_int(struct hispcpe_s *dev, msg_req_slam_request_t *ctrl_slam)
{
	unsigned int ret = 0;

	if (TRUSTED ==  ctrl_slam->secure_flag) {
		if ((ret = sec_slam_smmu_int(dev)) != 0) {
			pr_err("[%s] Failed : sec_slam_smmu_int.%d\n", __func__, ret);
			return ret;
		}

		if (!dev->sec_slamdrv->shrf2da) {
			pr_err("[%s] Failed : sec_slamdrv->shrf2da.%pK\n", __func__, dev->sec_slamdrv->shrf2da);
			return -EINVAL;
		}

		ctrl_slam->streams[0][0].buf = dev->sec_slamdrv->shrf2da(dev->sec_slamdrv, ctrl_slam->streams[0][0].buf,
									   &g_share_fd_size[BI_SHARE_FD]);
		if (ctrl_slam->streams[0][0].buf == 0) {
			e("[%s] Failed : hipp_shrf2da.BI_SHARE_FD\n", __func__);
			return -ENOMEM;
		}

		ctrl_slam->streams[0][2].buf = dev->sec_slamdrv->shrf2da(dev->sec_slamdrv, ctrl_slam->streams[0][2].buf,
									   &g_share_fd_size[STAT_SHARE_FD]);
		if (ctrl_slam->streams[0][2].buf == 0) {
			e("[%s] Failed : hipp_shrf2da.STAT_SHARE_FD\n", __func__);
			return -ENOMEM;
		}
	} else if (NONTRUS ==  ctrl_slam->secure_flag) {
		if (!dev->ippdrv) {
			pr_err("Failed : ippdrv.%pK\n", dev->ippdrv);
			return -EINVAL;
		}

		if (!dev->ippdrv->enable_smmu) {
			pr_err("Failed : ippdrv->enable_smmu.%pK \n", dev->ippdrv->enable_smmu);
			return -EINVAL;
		}

		if ((ret = dev->ippdrv->enable_smmu(dev->ippdrv)) != 0) {
			pr_err("[%s] Failed : dev->ippdrv->enable_smmu.%d\n", __func__, ret);
			return ret;
		}
	}

	return ret;
}

static int sec_slam_smmu_deint(struct hispcpe_s *dev)
{
	unsigned int ret = 0;

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv) {
		pr_err("[%s] Failed : sec_slamdrv.%pK\n", __func__, dev->sec_slamdrv);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv->enable_smmu) {
		pr_err("[%s] Failed : sec_slamdrv->enable_smmu.%pK\n", __func__, dev->sec_slamdrv->enable_smmu);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv->setsid_smmu) {
		pr_err("[%s] Failed : sec_slamdrv->setsid_smmu.%pK\n", __func__, dev->sec_slamdrv->setsid_smmu);
		return -EINVAL;
	}

	if ((ret = dev->sec_slamdrv->disable_smmu(dev->sec_slamdrv)) != 0) {
		pr_err("[%s] Failed : dev->sec_slamdrv->enable_smmu.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = dev->sec_slamdrv->setsid_smmu(dev->sec_slamdrv, SLAM_BI_SID, NONTRUS)) != 0) {
		pr_err("[%s] Failed : sec_slamdrv->setsid_smmu.%pK\n", __func__, dev->sec_slamdrv->setsid_smmu);
		return ret;
	}

	if ((ret = dev->sec_slamdrv->setsid_smmu(dev->sec_slamdrv, SLAM_STAT_SID, NONTRUS)) != 0) {
		pr_err("[%s] Failed : sec_slamdrv->setsid_smmu.%pK\n", __func__, dev->sec_slamdrv->setsid_smmu);
		return ret;
	}

	return ret;
}

static int sec_slam_deint(struct hispcpe_s *dev, msg_req_slam_request_t *ctrl_slam)
{
	unsigned int ret = 0;

	if (TRUSTED ==  ctrl_slam->secure_flag) {
		if ((ret = sec_slam_smmu_deint(dev)) != 0) {
			pr_err("[%s] Failed : sec_slam_smmu_int.%d\n", __func__, ret);
			return ret;
		}

		hipp_trusted_unmap(dev->sec_slamdrv, ctrl_slam->streams[0][0].buf, g_share_fd_size[BI_SHARE_FD]);
		hipp_trusted_unmap(dev->sec_slamdrv, ctrl_slam->streams[0][2].buf, g_share_fd_size[STAT_SHARE_FD]);
	} else if (NONTRUS ==  ctrl_slam->secure_flag) {
		if (!dev->ippdrv) {
			pr_err("Failed : ippdrv.%pK\n", dev->ippdrv);
			return -EINVAL;
		}

		if (!dev->ippdrv->enable_smmu) {
			pr_err("Failed : ippdrv->enable_smmu.%pK \n", dev->ippdrv->enable_smmu);
			return -EINVAL;
		}

		if ((ret = dev->ippdrv->disable_smmu(dev->ippdrv)) != 0) {
			pr_err("[%s] Failed : dev->ippdrv->enable_smmu.%d\n", __func__, ret);
			return ret;
		}
	}

	return ret;
}

static int sec_slam_process(struct hispcpe_s *dev, unsigned long args)
{
	unsigned int ret = 0;
	msg_req_slam_request_t *ctrl_slam = NULL;

	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv) {
		pr_err("[%s] Failed : sec_slamdrv.%pK\n", __func__, dev->sec_slamdrv);
		return -EINVAL;
	}

	if (!dev->sec_slamdrv->lock_usecase) {
		pr_err("[%s] Failed : sec_slamdrv->lock_usecase.%pK\n", __func__, dev->sec_slamdrv->lock_usecase);
		return -EINVAL;
	}

	if ((ret = dev->sec_slamdrv->lock_usecase(dev->sec_slamdrv)) != 0) {
		pr_err("[%s] Failed : dev->sec_slamdrv->lock_usecase.%d\n", __func__, ret);
		return ret;
	}

	ctrl_slam = (msg_req_slam_request_t *)kmalloc(sizeof(msg_req_slam_request_t), GFP_KERNEL);
	if (NULL == ctrl_slam) {
		pr_err(" fail to kmalloc ctrl_slam\n");
		goto free_slam_kmalloc_memory;
	}

	if ((ret = copy_from_user(ctrl_slam, (void __user *)args, sizeof(msg_req_slam_request_t))) != 0) {
		pr_err("[%s] copy_from_user.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if (ctrl_slam->pyramid_layer_num > MAX_PYRAMID_LAYER) {
		pr_err("[%s] Failed : Invalid pyramid_layer_num = %d\n", __func__, ctrl_slam->pyramid_layer_num);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = sec_slam_int(dev, ctrl_slam)) != 0) {
		pr_err("[%s] Failed : sec_slam_int.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_clk_enable(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_clk_enable.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_request(dev, ctrl_slam)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_request.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = hispcpe_slam_clk_disable(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_slam_clk_disable.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

	if ((ret = sec_slam_deint(dev, ctrl_slam)) != 0) {
		pr_err("[%s] Failed : sec_slam_int.%d\n", __func__, ret);
		goto free_slam_kmalloc_memory;
	}

free_slam_kmalloc_memory:

	if (ctrl_slam) {
		kfree(ctrl_slam);
		ctrl_slam = NULL;
	}

	if ((ret = dev->sec_slamdrv->unlock_usecase(dev->sec_slamdrv)) != 0) {
		pr_err("[%s] Failed : dev->sec_slamdrv->unlock_usecase.%d\n", __func__, ret);
		return ret;
	}

	return ret;
}

static int hipp_cmd_pwrup(unsigned long args)
{
	struct hispcpe_s *dev = hispcpe_dev;
	int ret = 0;
	struct power_para_s para = { 0 };

	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	if ((ret = copy_from_user(&para, (void __user *)args, sizeof(struct power_para_s))) != 0) {
		pr_err("[%s] copy_from_user.%d\n", __func__, ret);
		return -EFAULT;
	}
	i(" info : HISP_CPE_PWRUP.pw_flag.%d\n", para.pw_flag);

	mutex_lock(&dev->lock);
	mutex_lock(&dev->ipp_wakelock_mutex);
	if (dev->ipp_wakelock->active) {
		__pm_relax(dev->ipp_wakelock);
		pr_info("ipp power up wake unlock.\n");
	}
	mutex_unlock(&dev->ipp_wakelock_mutex);

	if (0 == para.pw_flag) {
		if ((ret = hispcpe_powerup(dev)) != 0) {
			pr_err("[%s] Failed : hispcpe_powerup.%d\n", __func__, ret);
			goto relax_ipp_wakelock;
		}
	} else if (1 == para.pw_flag) {
		if ((para.mem.shared_fd < 0) || (para.mem.size != MEM_HISPCPE_SIZE)) {
			pr_err("[%s] Failed : share_fd.%d, size.0x%x\n", __func__, para.mem.shared_fd, para.mem.size);
			goto relax_ipp_wakelock;
		}
		if ((ret = sec_slam_powerup(dev, para.mem.shared_fd)) != 0) {
			pr_err("[%s] Failed : sec_slam_powerup.%d\n", __func__, ret);
			goto relax_ipp_wakelock;
		}
	} else {
		pr_err(" Failed : check up layer pw_flag.%d\n", para.pw_flag);
		goto relax_ipp_wakelock;
	}
	mutex_unlock(&dev->lock);
	return ret;

relax_ipp_wakelock:
	mutex_lock(&dev->ipp_wakelock_mutex);
	if (dev->ipp_wakelock->active) {
		__pm_relax(dev->ipp_wakelock);
		pr_info("ipp power up wake unlock.\n");
	}
	mutex_unlock(&dev->ipp_wakelock_mutex);
	mutex_unlock(&dev->lock);
	return -EINVAL;
}

static int hipp_cmd_pwrdn(unsigned long args)
{
	int ret = 0;
	struct hispcpe_s *dev = hispcpe_dev;

	mutex_lock(&dev->lock);
	if (0 == dev->sec_path) {
		if ((ret = hispcpe_powerdn(dev)) != 0) {
			pr_err("[%s] Failed : hispcpe_powerdn.%d\n", __func__, ret);
			goto relax_ipp_wakelock;
		}
	} else if (1 == dev->sec_path) {
		if ((ret = sec_slam_powerdn(dev)) != 0) {
			pr_err("[%s] Failed : sec_slam_powerdn.%d\n", __func__, ret);
			goto relax_ipp_wakelock;
		}
	} else {
		pr_err(" Failed :check sec_path.%d\n", dev->sec_path);
		goto relax_ipp_wakelock;
	}

	mutex_lock(&dev->ipp_wakelock_mutex);
	if (dev->ipp_wakelock->active) {
		__pm_relax(dev->ipp_wakelock);
		pr_info("ipp power up wake unlock.\n");
	}
	mutex_unlock(&dev->ipp_wakelock_mutex);
	mutex_unlock(&dev->lock);
	return ret;

relax_ipp_wakelock:
	mutex_lock(&dev->ipp_wakelock_mutex);
	if (dev->ipp_wakelock->active) {
		__pm_relax(dev->ipp_wakelock);
		pr_info("ipp power up wake unlock.\n");
	}
	mutex_unlock(&dev->ipp_wakelock_mutex);
	mutex_unlock(&dev->lock);
	return -EINVAL;
}

static int hipp_cmd_map_buf(unsigned long args)
{
	int ret = 0;
	struct hispcpe_s *dev = hispcpe_dev;

	pr_info("[%s] cmd.HISP_CPE_MAP_BUF\n", __func__);
	mutex_lock(&dev->lock);
	if ((ret = hispcpe_map_kernel(dev, args)) != 0) {
		pr_err("[%s] Failed : hispcpe_map_kernel.%d\n", __func__, ret);
		mutex_unlock(&dev->lock);
		return ret;
	}
	if ((ret = cpe_init_memory()) != 0) {
		pr_err("[%s] Failed : cpe_init_memory.%d\n", __func__, ret);
		mutex_unlock(&dev->lock);
		return ret;
	}
	mutex_unlock(&dev->lock);
	return ret;
}

static int hipp_cmd_unmap_buf(unsigned long args)
{
	int ret = 0;
	struct hispcpe_s *dev = hispcpe_dev;

	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	mutex_lock(&dev->lock);
	if ((ret = hispcpe_unmap_kernel(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_umap_kernel.%d\n", __func__, ret);
		mutex_unlock(&dev->lock);
		return -EINVAL;
	}
	mutex_unlock(&dev->lock);
	return ret;
}

static int hipp_cmd_map_iommu(unsigned long args)
{
	int ret = 0;
	struct hispcpe_s *dev = hispcpe_dev;
	struct memory_block_s buf = { 0 };

	pr_info("[%s] cmd.HISP_CPE_MAP_IOMMU\n", __func__);
	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	if ((ret = copy_from_user(&buf, (void __user *)args, sizeof(struct memory_block_s))) != 0) {
		pr_err("[%s] copy_from_user.%d\n", __func__, ret);
		return -EFAULT;
	}

	mutex_lock(&dev->lock);
	if ((ret = hispcpe_map_iommu(dev, &buf)) != 0) {
		pr_err("[%s] Failed : hispcpe_map_iommu.%d\n", __func__, ret);
		mutex_unlock(&dev->lock);
		return ret;
	}
	mutex_unlock(&dev->lock);

	if ((ret = copy_to_user((void __user *)args, &buf, sizeof(struct memory_block_s))) != 0) {
		pr_err("[%s] copy_to_user.%d\n", __func__, ret);
		return -EFAULT;
	}

	return ret;
}

static int hipp_cmd_unmap_iommu(unsigned long args)
{
	int ret = 0;
	struct hispcpe_s *dev = hispcpe_dev;
	struct memory_block_s buf = { 0 };

	if (args == 0) {
		pr_err("[%s] args.0x%lx\n", __func__, args);
		return -EINVAL;
	}

	if ((ret = copy_from_user(&buf, (void __user *)args, sizeof(struct memory_block_s))) != 0) {
		pr_err("[%s] copy_from_user.%d\n", __func__, ret);
		return -EFAULT;
	}

	mutex_lock(&dev->lock);
	hispcpe_unmap_iommu(dev, &buf);
	mutex_unlock(&dev->lock);
	return ret;
}

static int hipp_cmd_slam_req(unsigned long args)
{
	int ret = 0;
	struct hispcpe_s *dev = hispcpe_dev;

	pr_info("[%s] HISP_CPE_SLAM_REQ\n", __func__);
	mutex_lock(&dev->lock);
	if (0 == dev->sec_path) {
		if ((ret = slam_process(dev, args)) != 0) {
			pr_err("[%s] Failed : slam_process.%d\n", __func__, ret);
			mutex_unlock(&dev->lock);
			return ret;
		}
	} else if (1 == dev->sec_path) {
		if ((ret = sec_slam_process(dev, args)) != 0) {
			pr_err("[%s] Failed : sec_slam_process.%d\n", __func__, ret);
			mutex_unlock(&dev->lock);
			return ret;
		}
	} else {
		pr_err(" Failed : check sec_path \n");
		mutex_unlock(&dev->lock);
		return -EINVAL;
	}
	mutex_unlock(&dev->lock);
	return ret;
}

static int hipp_cmd_slamtest_req(unsigned long args)
{
	int ret = 0;
	struct hispcpe_s *dev = hispcpe_dev;

	mutex_lock(&dev->lock);
	if ((ret = slam_test_process(dev, args)) != 0)
		pr_err("[%s] Failed : hispcpe_slam_request.%d\n", __func__, ret);

	mutex_unlock(&dev->lock);
	return ret;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wframe-larger-than="

static const struct ipp_adapter_t g_ipp_adapt[] = {
	{HISP_CPE_PWRUP,         hipp_cmd_pwrup     },
	{HISP_CPE_SLAM_REQ,      hipp_cmd_slam_req},
	{HISP_CPE_MAP_BUF,       hipp_cmd_map_buf   },
	{HISP_CPE_SLAMTEST_REQ,  hipp_cmd_slamtest_req },
	{HISP_CPE_UNMAP_BUF,     hipp_cmd_unmap_buf },
	{HISP_CPE_PWRDN,         hipp_cmd_pwrdn     },
	{HISP_CPE_MAP_IOMMU,     hipp_cmd_map_iommu   },
	{HISP_CPE_UNMAP_IOMMU,   hipp_cmd_unmap_iommu },
};

static long hispcpe_ioctl(struct file *filp, unsigned int cmd, unsigned long args)
{
	struct hispcpe_s *dev = NULL;
	int ret = 0;
	int (*filter)(unsigned long args) = NULL;
	size_t nums;
	unsigned int index;

	dev = get_cpedev_bymisc((struct miscdevice *)filp->private_data);
	if ((dev == NULL) || (dev != hispcpe_dev)) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (dev->initialized == 0) {
		pr_err("[%s] Failed : IPP Device Not Exist.0\n", __func__);
		return -ENXIO;
	}

	nums = ARRAY_SIZE(g_ipp_adapt);
	for (index = 0; index < nums; index++) {
		if (g_ipp_adapt[index].cmd == cmd) {
			filter = g_ipp_adapt[index].handler;
			break;
		}
	}

	if (filter == NULL) {
		pr_err("[%s] Failed : not supported.0x%x\n", __func__, cmd);
		return -EINVAL;
	}

	ret = filter(args);
	return ret;
}
#pragma GCC diagnostic pop

static int hispcpe_open(struct inode *inode, struct file *filp)
{
	struct hispcpe_s *dev = NULL;
	d("+\n");

	if ((dev = get_cpedev_bymisc((struct miscdevice *)filp->private_data)) == NULL) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (!dev->initialized) {
		pr_err("[%s] Failed : CPE Device Not Exist.%d\n", __func__, dev->initialized);
		return -ENXIO;
	}

	if (atomic_read(&dev->open_refs) != 0) {
		pr_err("[%s] Failed: Opened, open_refs.0x%x\n", __func__, atomic_read(&dev->open_refs));
		return -EBUSY;
	}

	atomic_inc(&dev->open_refs);
	d("-\n");
	return 0;
}

static int hispcpe_release(struct inode *inode, struct file *filp)
{
	struct hispcpe_s *dev = NULL;
	unsigned int ret = 0;
	d("+\n");

	if ((dev = get_cpedev_bymisc((struct miscdevice *)filp->private_data)) == NULL) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -EINVAL;
	}

	if (!dev->initialized) {
		pr_err("[%s] Failed : CPE Device Not Exist.%d\n", __func__, dev->initialized);
		return -ENXIO;
	}

	if (atomic_read(&dev->open_refs) <= 0) {
		pr_err("[%s] Failed: Closed, open_refs.0x%x\n", __func__, atomic_read(&dev->open_refs));
		return -EBUSY;
	}

	atomic_set(&dev->open_refs, 0);
	if (atomic_read(&dev->cpe_supply_refs) > 0) {
		pr_err("[%s] Failed: cpe_supply Opened.0x%x\n", __func__, atomic_read(&dev->cpe_supply_refs));

		if ((ret = hispcpe_powerdn(dev)) != 0) {
			pr_err("[%s] Failed : hispcpe_powerdn.%d\n", __func__, ret);
			return -EINVAL;
		}
	}

	if (atomic_read(&dev->sec_slam_supply_refs) > 0) {
		pr_err("[%s] Failed: sec_slam_supply Opened.0x%x\n", __func__, atomic_read(&dev->sec_slam_supply_refs));

		if ((ret = sec_slam_powerdn(dev)) != 0) {
			pr_err("[%s] Failed : sec_slam_powerdn.%d\n", __func__, ret);
			return -EINVAL;
		}
	}

	mutex_lock(&dev->ipp_wakelock_mutex);
	if (dev->ipp_wakelock->active) {
		__pm_relax(dev->ipp_wakelock);
		pr_info("ipp power up wake unlock.\n");
	}
	mutex_unlock(&dev->ipp_wakelock_mutex);

	d("-\n");
	return 0;
}

static ssize_t hispcpe_show(struct device *pdev, struct device_attribute *attr, char *buf)
{
	char *s = buf;
	d("+\n");
	d("-\n");
	return (ssize_t)(s - buf);
}

static ssize_t hispcpe_store(struct device *pdev, struct device_attribute *attr, const char *buf, size_t count)
{
	d("+\n");
	d("-\n");
	return (ssize_t)count;
}

static DEVICE_ATTR(hispcpe, (S_IRUGO | S_IWUSR | S_IWGRP), hispcpe_show, hispcpe_store);

static struct file_operations hispcpe_fops = {
	.owner          = THIS_MODULE,
	.open           = hispcpe_open,
	.release        = hispcpe_release,
	.unlocked_ioctl = hispcpe_ioctl,
};

static struct miscdevice hispcpe_miscdev = {
	.minor  = MISC_DYNAMIC_MINOR,
	.name   = KBUILD_MODNAME,
	.fops   = &hispcpe_fops,
};

static int hispcpe_register_irq(struct hispcpe_s *dev)
{
	int i = 0, ret = 0;
	d("+\n");

	for (i = 0; i < min_func(MAX_HISP_CPE_IRQ, dev->irq_num); i ++) {/*lint !e574 */
		if ((ret = request_irq(dev->irq[i], hispcpe_irq_handler, 0, "HISP_CPE_IRQ", (void *)dev)) != 0) {
			pr_err("[%s] Failed : %d.request_irq.%d\n", __func__, i, ret);
			return ret;
		}

		pr_info("[%s] Hisp CPE %d.IRQ.%d, handler.%pK\n", __func__, i, dev->irq[i], hispcpe_irq_handler);
	}

	d("-\n");
	return 0;
}

static int hispcpe_ioremap_reg(struct hispcpe_s *dev)
{
	struct device *device = NULL;
	int i = 0;
	d("+\n");
	device = &dev->pdev->dev;

	for (i = 0; i < min_func(MAX_HISP_CPE_REG, dev->reg_num); i ++) {/*lint !e574 */
		dev->reg[i] = devm_ioremap_resource(device, dev->r[i]);

		if (!dev->reg[i]) {
			pr_err("[%s] Failed : %d.devm_ioremap_resource.%pK\n", __func__, i, dev->reg[i]);
			return -ENOMEM;
		}

		pr_info("[%s] Hisp CPE %d.Resource.%pK.(n.%s, s.0x%llx, e.0x%llx, f.0x%lx) > %pK\n", __func__, i, dev->r[i],
				dev->r[i]->name, (unsigned long long)dev->r[i]->start, (unsigned long long)dev->r[i]->end, dev->r[i]->flags,
				dev->reg[i]);
	}

	d("-\n");
	return 0;
}

static int hispcpe_resource_init(struct hispcpe_s *dev)
{
	int ret = 0;

	if ((ret = hispcpe_register_irq(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_register_irq.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = hispcpe_ioremap_reg(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_ioremap_reg.%d\n", __func__, ret);
		return ret;
	}

	return 0;
}

static int hipp_enable_iommu(struct hispcpe_s *dev)
{
	struct iommu_domain *domain = NULL;
	struct device *device = NULL;
	i("+\n");

	if (!dev) {
		e("Failed : hipp smmu dev.%pK\n", dev);
		return -ENODEV;
	}

	if (!dev->pdev) {
		e("Failed : pdev.%pK\n", dev->pdev);
		return -ENODEV;
	}

	device = &dev->pdev->dev;
	dma_set_mask_and_coherent(device, DMA_BIT_MASK(64));/*lint !e598 !e648*/
	domain = iommu_get_domain_for_dev(device);
	if (!domain) {
		e("Failed : iommu_get_domain_for_dev fail\n");
		return -EINVAL;
	}

	dev->domain = domain;
	return 0; /*lint !e715 !e438*/
}

static void hipp_disable_iommu(struct hispcpe_s *dev)
{
	if (dev->domain != NULL)
		dev->domain = NULL;
}

static int hispcpe_getdts_pwrclk(struct hispcpe_s *dev)
{
	struct device *device = NULL;
	struct device_node *np;
	unsigned int ret = 0;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -ENXIO;
	}

	if (!dev->pdev) {
		pr_err("[%s] Failed : pdev.%pK\n", __func__, dev->pdev);
		return -ENXIO;
	}

	device = &dev->pdev->dev;
	dev->cpe_supply = devm_regulator_get(device, "ipp-cpe");

	if (IS_ERR(dev->cpe_supply)) {
		pr_err("[%s] Failed : CPE devm_regulator_get.%pK\n", __func__, dev->cpe_supply);
		return -EINVAL;
	}

	pr_info("[%s] Hisp CPE cpe_supply.%pK\n", __func__, dev->cpe_supply);
	dev->jpg_clk = devm_clk_get(device, "clk_jpg_func");

	if (IS_ERR(dev->jpg_clk)) {
		pr_err("get jpg_clk failed");
		return -EINVAL;
	}

	np = device->of_node;
	if (NULL == np) {
		pr_err("%s: of node NULL", __func__);
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "clock-value", &dev->jpg_clk_rate);
	if (ret) {
		pr_err("ipp get rate failed, ret:%d", ret);
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "clock-low-frequency", &dev->jpgclk_low_frequency);
	if (ret) {
		pr_err("ipp get jpgclk_low_frequency failed, ret:%d", ret);
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "power-off-frequency", &dev->jpgclk_off_frequency);
	if (ret) {
		pr_err("ipp get jpgclk_off_frequency failed, ret:%d", ret);
		return -EINVAL;
	}

	pr_err("ipp get jpgclk frequency 1:%d 2:%d 3:%d", dev->jpg_clk_rate, dev->jpgclk_low_frequency,
		   dev->jpgclk_off_frequency);
	i("-\n");
	return 0;
}

int hispcpe_get_irq(int index)
{
	struct device_node *np = NULL;
	char *name = DTS_NAME_HISI_IPP;
	int irq = 0;
	np = of_find_compatible_node(NULL, NULL, name);
	if (!np) {
		pr_err("[%s] Failed : %s.of_find_compatible_node.%pK\n", __func__, name, np);
		return -ENXIO;
	}

	irq = irq_of_parse_and_map(np, index);
	if (!irq) {
		pr_err("[%s] Failed : irq_of_parse_and_map.%d\n", __func__, irq);
		return -ENXIO;
	}

	pr_info("%s: comp.%s, cpe irq.%d.\n", __func__, name, irq);
	return irq;
}

static int hispcpe_getdts_irq(struct hispcpe_s *dev)
{
	struct device *device = NULL;
	int i = 0, irq = 0, ret = 0;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -ENXIO;
	}

	if (!dev->pdev) {
		pr_err("[%s] Failed : pdev.%pK\n", __func__, dev->pdev);
		return -ENXIO;
	}
	device = &dev->pdev->dev;

	if ((ret = of_property_read_u32(device->of_node, "irq-num", (unsigned int *)(&dev->irq_num))) < 0) {
		pr_err("[%s] Failed: irq-num of_property_read_u32.%d\n", __func__, ret);
		return -EINVAL;
	}

	pr_info("[%s] Hisp CPE irq_num.%d\n", __func__, dev->irq_num);
	for (i = 0; i < min_func(MAX_HISP_CPE_IRQ, dev->irq_num); i ++) {/*lint !e574 */
		if ((irq = hispcpe_get_irq(i)) <= 0) {
			pr_err("[%s] Failed : platform_get_irq.%d\n", __func__, irq);
			return -EINVAL;
		}

		dev->irq[i] = irq;
		pr_info("[%s] Hisp CPE %d.IRQ.%d\n", __func__, i, dev->irq[i]);
	}

	i("-\n");
	return 0;
}

static int hispcpe_getdts_reg(struct hispcpe_s *dev)
{
	struct device *device = NULL;
	int i = 0, ret = 0;
	d("+\n");

	if (!dev) {
		pr_err("[%s] Failed : dev.%pK\n", __func__, dev);
		return -ENXIO;
	}

	if (!dev->pdev) {
		pr_err("[%s] Failed : pdev.%pK\n", __func__, dev->pdev);
		return -ENXIO;
	}

	device = &dev->pdev->dev;
	if ((ret = of_property_read_u32(device->of_node, "reg-num", (unsigned int *)(&dev->reg_num))) < 0) {
		pr_err("[%s] Failed: reg-num of_property_read_u32.%d\n", __func__, ret);
		return -EINVAL;
	}

	pr_info("[%s] Hisp CPE reg_num.%d\n", __func__, dev->reg_num);
	for (i = 0; i < min_func(MAX_HISP_CPE_REG, dev->reg_num); i ++) {/*lint !e574 */
		if ((dev->r[i] = platform_get_resource(dev->pdev, IORESOURCE_MEM, i)) == NULL) {
			pr_err("[%s] Failed : platform_get_resource.%pK\n", __func__, dev->r[i]);
			return -ENXIO;
		}

		pr_info("[%s] Hisp CPE %d.Resource.%pK.(n.%s, s.0x%llx, e.0x%llx, f.0x%lx)\n", __func__, i, dev->r[i],
				dev->r[i]->name, (unsigned long long)dev->r[i]->start, (unsigned long long)dev->r[i]->end, dev->r[i]->flags);
	}

	i("-\n");
	return 0;
}

static int hispcpe_getdts(struct hispcpe_s *dev)
{
	int ret = 0;

	if ((ret = hispcpe_getdts_pwrclk(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_getdts_pwrclk.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = hispcpe_getdts_irq(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_getdts_irq.%d\n", __func__, ret);
		return ret;
	}

	if ((ret = hispcpe_getdts_reg(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_getdts_reg.%d\n", __func__, ret);
		return ret;
	}

	return 0;
}

static int hispcpe_attach_misc(struct hispcpe_s *dev, struct miscdevice *mdev)
{
	i("+\n");

	if (!dev || !mdev) {
		pr_err("[%s] Failed : dev.%pK, mdev.%pK\n", __func__, dev, mdev);
		return -EINVAL;
	}

	dev->miscdev = hispcpe_miscdev;
	i("-\n");
	return 0;
}

unsigned int get_cpe_addr_da(void)
{
	if (hispcpe_dev == NULL) {
		pr_err("[%s], NONE cpe_mem_info!\n", __func__);
		return 0;
	}

	return hispcpe_dev->daddr;
}

void *get_cpe_addr_va(void)
{
	if (hispcpe_dev == NULL) {
		pr_err("[%s], NONE cpe_mem_info!\n", __func__);
		return 0;
	}

	return hispcpe_dev->virt_addr;
}
// lint -save -e454 -e455
int ippdev_lock(void)
{
	i("+\n");

	if (hispcpe_dev == NULL) {
		pr_err("[%s], NONE cpe_mem_info!\n", __func__);
		return -1;
	}

	mutex_lock(&hispcpe_dev->lock);
	i("-\n");
	return 0;
}

int ippdev_unlock(void)
{
	i("+\n");

	if (hispcpe_dev == NULL) {
		pr_err("[%s], NONE cpe_mem_info!\n", __func__);
		return -1;
	}

	mutex_unlock(&hispcpe_dev->lock);
	i("-\n");
	return 0;
}

static int hispcpe_probe(struct platform_device *pdev)
{
	struct hispcpe_s *dev = NULL;
	int ret = 0;
	i("+\n");

	if ((dev = (struct hispcpe_s *)kzalloc(sizeof(struct hispcpe_s), GFP_KERNEL)) == NULL) {
		pr_err("[%s] Failed : kzalloc\n", __func__);
		return -ENOMEM;
	}

	dev->pdev = pdev;
	platform_set_drvdata(pdev, dev);

	if ((ret = hispcpe_getdts(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_getdts.%d\n", __func__, ret);
		goto free_dev;
	}

	if ((ret = hispcpe_resource_init(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_resource_init.%d\n", __func__, ret);
		goto free_dev;
	}

	if ((ret = hipp_enable_iommu(dev)) != 0) {
		pr_err("[%s] Failed : hispcpe_resource_init.%d\n", __func__, ret);
		goto free_dev;
	}

	dev->initialized = 0;
	init_waitqueue_head(&dev->cpe_wait);
	init_waitqueue_head(&dev->slam_wait);
	hispcpe_attach_misc(dev, &hispcpe_miscdev);

	if (!(dev->ippdrv = hipp_register(CPE_UNIT, NONTRUS))) {
		pr_err("[%s] Failed : hipp_register.%pK\n", __func__, dev->ippdrv);
		goto free_iommu;
	}

	if (!(dev->sec_slamdrv = hipp_register(ORB_UNIT, TRUSTED))) {
		pr_err("[%s] Failed : sec_slam_register.%pK\n", __func__, dev->sec_slamdrv);
		goto free_iommu;
	}

	if ((ret = misc_register((struct miscdevice *)&dev->miscdev)) != 0) {
		pr_err("[%s] Failed : misc_register.%d\n", __func__, ret);
		goto free_iommu;
	}

	if ((ret = device_create_file(dev->miscdev.this_device, &dev_attr_hispcpe)) != 0) {
		pr_err("[%s] Faield : hispcpe device_create_file.%d\n", __func__, ret);
		goto clean_misc;
	}

	atomic_set(&dev->open_refs, 0);
	atomic_set(&dev->cpe_supply_refs, 0);
	atomic_set(&dev->sec_slam_supply_refs, 0);
	atomic_set(&dev->sec_slam_refs, 0);
	atomic_set(&dev->cpe_slam_refs, 0);
	mutex_init(&dev->lock);
	dev->ipp_wakelock = wakeup_source_register(&pdev->dev, "ipp_wakelock");
	if (!dev->ipp_wakelock)
		pr_err("ipp_wakelock register fail\n");
	mutex_init(&dev->ipp_wakelock_mutex);
	dev->initialized = 1;
	hispcpe_dev = dev;
	dev->sec_path = 0;
	dev->sec_req = 0;
	i("-\n");
	return 0;
clean_misc:
	misc_deregister(&dev->miscdev);
free_iommu:
	hipp_disable_iommu(dev);
free_dev:
	kfree(dev);
	return ret;
}

static int hispcpe_remove(struct platform_device *pdev)
{
	struct hispcpe_s *dev = NULL;
	i("+\n");

	if ((dev = (struct hispcpe_s *)platform_get_drvdata(pdev)) == NULL) {
		pr_err("[%s] Failed : platform_get_drvdata, dev.%pK.pdev.%pK\n", __func__, dev, pdev);
		return -ENODEV;
	}

	misc_deregister(&dev->miscdev);
	atomic_set(&dev->open_refs, 0);
	atomic_set(&dev->cpe_supply_refs, 0);
	atomic_set(&dev->cpe_slam_refs, 0);
	wakeup_source_unregister(dev->ipp_wakelock);
	mutex_destroy(&dev->ipp_wakelock_mutex);

	if (hipp_unregister(CPE_UNIT))
		pr_err("[%s] Failed : hipp_unregister\n", __func__);

	if (hipp_unregister(ORB_UNIT))
		pr_err("[%s] Failed : sec_slam_unregister\n", __func__);

	if (dev->ippdrv)
		dev->ippdrv = NULL;

	if (dev->sec_slamdrv)
		dev->sec_slamdrv = NULL;

	dev->initialized = 0;
	kfree(dev);
	dev = NULL;
	i("-\n");
	return 0;
}

#ifdef CONFIG_OF
static struct of_device_id hisiipp_of_id[] = {
	{.compatible = DTS_NAME_HISI_IPP},
	{}
};
#endif

static struct platform_driver hispcpe_pdrvr = {
	.probe          = hispcpe_probe,
	.remove         = hispcpe_remove,
	.driver         = {
		.name           = "hisiipp",
		.owner          = THIS_MODULE,
#ifdef CONFIG_OF
		.of_match_table = of_match_ptr(hisiipp_of_id),
#endif
	},
};

module_platform_driver(hispcpe_pdrvr);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hisilicon ISP CPE Driver");
MODULE_AUTHOR("isp");

/*lint +e21 +e846 +e514 +e778 +e866 +e84 +e429 +e613 +e668*/
