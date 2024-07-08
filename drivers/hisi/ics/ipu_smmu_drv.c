#include <linux/errno.h>
#include <linux/hisi/hisi-iommu.h> //for struct iommu_domain_data
#include <linux/iommu.h> //for struct iommu_domain

#include "ipu_smmu_drv.h"

#define IPU_SMMU_MSTR_BASE_ES (IPU_BASE_ADDRESS + 0x84000)
#define IPU_SMMU_COMM_BASE_ES (IPU_BASE_ADDRESS + 0x80000)
#define IPU_SMMU_MSTR_BASE (IPU_BASE_ADDRESS + 0xA0000)
#define IPU_SMMU_COMM_BASE (IPU_BASE_ADDRESS + 0x80000)


static struct iommu_domain *ipu_smmu_domain = 0;

void ipu_reg_bit_write_dword(
				unsigned long reg_addr,
                unsigned int start_bit,
                unsigned int end_bit,
                unsigned int content)
{
    unsigned int set_value;
    unsigned int reg_content;
    unsigned int tmp_mask;
    unsigned int tmp_bit;

    if ((end_bit < start_bit)
        || (start_bit > 31)
        || (end_bit > 31)) {
		printk(KERN_DEBUG"error input: reg_addr=%lx,start_bit=%x,end_bit=%x,content=%x\n",
			(unsigned long)reg_addr, start_bit, end_bit, content);
		return;
    }
	set_value      = content;
	set_value      = set_value << start_bit;

	tmp_bit        = 31 - end_bit;
	tmp_mask       = 0xffffffff << tmp_bit;
	tmp_mask       = tmp_mask >> ( start_bit + tmp_bit);
	tmp_mask       = tmp_mask << start_bit;

	reg_content    = (unsigned int) ioread32((void *)reg_addr);
	reg_content   &= (~tmp_mask);
	set_value     &= tmp_mask;
	iowrite32((reg_content | set_value), (void *)reg_addr);
	printk(KERN_DEBUG"reg_content=%d, set_value= %d\n", reg_content, set_value);
	return;
}

/* get ptr of iommu domain when probe */
static int ipu_enable_iommu(struct device *dev)
{
	int ret;
	if (!dev) {
		printk(KERN_DEBUG"[ipu_enable_iommu] dev is NULL\n");
		return -EIO;
	}
	if (ipu_smmu_domain) {
		printk(KERN_DEBUG"[ipu_enable_iommu] ipu_smmu_domain is not NULL\n");
		return 0;
	}

	printk(KERN_DEBUG"[ipu_enable_iommu] dev->bus is %lx\n", (unsigned long)dev->bus);

	if (!iommu_present(dev->bus)) {
		printk(KERN_DEBUG"[ipu_enable_iommu] iommu not found\n");
		return 0;
	}

	ipu_smmu_domain = iommu_domain_alloc(dev->bus);

	if (0 == ipu_smmu_domain) {
		printk(KERN_DEBUG"[ipu_enable_iommu] iommu_domain_alloc fail\n");
		return -EIO;
	}

	printk(KERN_DEBUG"[ipu_enable_iommu] iommu_domain_alloc success,ipu_smmu_domain=%lx\n",
		(unsigned long)ipu_smmu_domain);

	ret = iommu_attach_device(ipu_smmu_domain, dev);

	if (ret) {
		printk(KERN_DEBUG"[ipu_enable_iommu] iommu_attach_device fail, ret=%d\n", ret);
		iommu_domain_free(ipu_smmu_domain);
		return -EIO;
	}

	printk(KERN_DEBUG"[ipu_enable_iommu] successfully\n");
	return 0;
}

unsigned int ipu_get_smmu_base_phy(struct device *dev)
{
	struct iommu_domain_data *domain_data = 0;
	unsigned int low;
	unsigned int high;

	if (ipu_enable_iommu(dev)) {
		printk(KERN_DEBUG"[ipu_get_smmu_base_phy] ipu_enable_iommu fail and cannot get TTBR\n");
		return 0;
	}

	domain_data = (struct iommu_domain_data *)(ipu_smmu_domain->priv); /*lint !e838*/

	low = (unsigned int)(((unsigned long long)domain_data->phy_pgd_base) & (0xffffffff));

	printk("[ipu_get_smmu_base_phy]domain_data->phy_pgd_base low=%x\n", low);

	high = (unsigned int)(((unsigned long long)domain_data->phy_pgd_base) >> 32);

	printk("[ipu_get_smmu_base_phy]domain_data->phy_pgd_base high=%x\n", high);

	return low;
}

static int ipu_smmu_mstr_init_es(void)
{
	unsigned int tmp;
	int cnt = 0;
	void __iomem *SMMU = ioremap((unsigned long long)IPU_SMMU_MSTR_BASE_ES, (unsigned long)0xffff);

	printk(KERN_DEBUG"[ipu_smmu_mstr_init] check mstr end ack start\n");

	/* polling by loop read SMMU_MSTR_END_ACK */
	do {
		cnt++;
		tmp = ioread32((void *)((unsigned long)SMMU + 0x0014));

		if (cnt > 0x100) {
			printk(KERN_DEBUG"[ipu_smmu_mstr_init] check SMMU MSTR END ACK loop overflow\n");
			break;
		}

	} while((tmp & 0xf) != 0xf);

	printk(KERN_DEBUG"[ipu_smmu_mstr_init] check mstr end ack end\n");

	/* set SMMU-normal mode */
	iowrite32(0x00000000, (void *)((unsigned long)SMMU + 0x0000));

	/* here can config clk:
	   for core_clk_en, hardware open, for low-power ctrl
	   for apb_clk_en,  software open, for debug (if want to read cache/ram status in RTL)
	   default value is OK, so NO need to config again */

	/* clean interrupt, and NOT mask all interrupts by config SMMU_MSTR_INTCLR and SMMU_MSTR_INTMASK */
	iowrite32(0x0000001f, (void *)((unsigned long)SMMU + 0x003c));
	iowrite32(0x00000000, (void *)((unsigned long)SMMU + 0x0030));

	/********************************************************
	config stream by SMMU_MSTR_SMRX_0
	for a sid, includes:
	VA max and VA min for this stream-id r/w region;
	len and upwin (in 32k, if VA continue increase, will not decrease in 32k, upwin is 0)
	len should be iid/2, iid(index id) is 8, for iid, for example, if pingpong buffer, iid is 2

	00.b:weight
	01.b:input read
	10.b:output read
	11.b:output write

	.len = iid/2=4
	.upwin = 0(do not search in upwin)
	.bypass = 0(no bypass)

	for malloc and free, VA is not in a designated area, so can not set VA max and VA min
	*********************************************************/
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x0100));
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x0110));
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x0120));
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x0130));

	/* stream startup by config SMMU_MSTR_SMRX_START */
	iowrite32(0x0000000f, (void *)((unsigned long)SMMU + 0x0020));
	printk(KERN_DEBUG"smmu=%lx\n", (unsigned long)SMMU);
	return 0;

}

static int ipu_smmu_comm_init_es(unsigned int ttbr0)
{
	void __iomem *SMMU_addr = ioremap((unsigned long long)IPU_SMMU_COMM_BASE_ES, (unsigned long)0xffff);
	unsigned long SMMU = (unsigned long)SMMU_addr;

	/* set SMMU mode as normal */
	ipu_reg_bit_write_dword(SMMU + 0x0000, 0, 0, 0);

	/* clear SMMU interrupt(SMMU_INTCLR_NS) */
	iowrite32(0x0000003f, (void *)((unsigned long)SMMU + 0x001c));

	/* clear MASK of interrupt(SMMU_INTMASK_NS) */
	ipu_reg_bit_write_dword(SMMU + 0x0010, 0, 5, 0);

	/* set stream status: SMMU normal(SMMU_SMRX_NS).
	default value is OK, NO need to config again */

	/* set master id(mid), (SMMU_SCR.ptw_mid) */
	ipu_reg_bit_write_dword(SMMU + 0x0000, 20, 27, 0x28);

	/* set SMMU Translation Table Base Register for Non-Secure Context Bank0(SMMU_CB_TTBR0) */
	iowrite32(ttbr0, (void *)((unsigned long)SMMU + 0x0204));

	/* set Descriptor select of the SMMU_CB_TTBR0 addressed region of Non-Secure Context Bank
	for 64bit system, select Long Descriptor -> 1(SMMU_CB_TTBCR.cb_ttbcr_des) */
	ipu_reg_bit_write_dword(SMMU + 0x020c, 0, 0, 0x1);

	printk(KERN_DEBUG"smmu = %lx,ttbr0 = %d\n", (unsigned long)SMMU, ttbr0);
	/* config FAMA (reserved) */
	return 0;
}

int ipu_smmu_init_es(unsigned int ttbr0)
{
	printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_mstr_init start\n");
	if (ipu_smmu_mstr_init_es()) {
		printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_mstr_init fail\n");
		return -EINVAL;
	}

	printk("[ipu_smmu_init]ttbr0=%x\n", ttbr0);

	if (0 == ttbr0) {
		return -EINVAL;
	}

	printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_comm_init start\n");
	if (ipu_smmu_comm_init_es(ttbr0)) {
		printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_comm_init fail\n");
		return -EINVAL;
	}

	printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_init successfully\n");

	return 0;
}

static int ipu_smmu_mstr_init(void)
{
	unsigned int tmp;
	int cnt = 0;
	void __iomem *SMMU = ioremap((unsigned long long)IPU_SMMU_MSTR_BASE, (unsigned long)0xFFFF);

	printk(KERN_DEBUG"[ipu_smmu_mstr_init] check mstr end ack start\n");

	/* polling by loop read SMMU_MSTR_END_ACK */
	do {
		cnt++;
		tmp = ioread32((void *)((unsigned long)SMMU + 0x0010));

		if (cnt > 0x100) {
			printk(KERN_DEBUG"[ipu_smmu_mstr_init] check SMMU MSTR END ACK loop overflow\n");
			break;
		}

	} while((tmp & 0xF) != 0xF);

	printk(KERN_DEBUG"[ipu_smmu_mstr_init] check mstr end ack end\n");

	/* set SMMU-normal mode */
	iowrite32(0x00000000, (void *)((unsigned long)SMMU + 0x0000));

	/* here can config clk:
	   for core_clk_en, hardware open, for low-power ctrl
	   for apb_clk_en,  software open, for debug (if want to read cache/ram status in RTL)
	   default value is OK, so NO need to config again */

	/* clean interrupt, and NOT mask all interrupts by config SMMU_MSTR_INTCLR and SMMU_MSTR_INTMASK */
	iowrite32(0x0000001f, (void *)((unsigned long)SMMU + 0x004c));
	iowrite32(0x00000000, (void *)((unsigned long)SMMU + 0x0040));

	/********************************************************
	config stream by SMMU_MSTR_SMRX_0
	for a sid, includes:
	VA max and VA min for this stream-id r/w region;
	len and upwin (in 32k, if VA continue increase, will not decrease in 32k, upwin is 0)
	len should be iid/2, iid(index id) is 8, for iid, for example, if pingpong buffer, iid is 2

	00.b:weight
	01.b:input read
	10.b:output read
	11.b:output write

	.len = iid/2=4
	.upwin = 0(do not search in upwin)
	.bypass = 0(no bypass)

	for malloc and free, VA is not in a designated area, so can not set VA max and VA min
	*********************************************************/
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x0100));
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x0104));
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x0108));
	iowrite32(0x00004000, (void *)((unsigned long)SMMU + 0x010C));

	/* set input signal as "register" by config SMMU_MSTR_INPT_SEL */
	iowrite32(0x00000003, (void *)((unsigned long)SMMU + 0x0034));

	/* stream startup by config SMMU_MSTR_SMRX_START */
	iowrite32(0x0000000F, (void *)((unsigned long)SMMU + 0x0028));
	printk(KERN_DEBUG"smmu=%lx\n", (unsigned long)SMMU);
	return 0;

}

static int ipu_smmu_comm_init(unsigned int ttbr0)
{
	void __iomem *SMMU_addr = ioremap((unsigned long long)IPU_SMMU_COMM_BASE, (unsigned long)0xffff);
	unsigned long SMMU = (unsigned long) SMMU_addr;
	/* set SMMU mode as normal */
	ipu_reg_bit_write_dword(SMMU + 0x0000, 0, 0, 0);

	/* clear SMMU interrupt(SMMU_INTCLR_NS) */
	iowrite32(0x0000003f, (void *)((unsigned long)SMMU + 0x001c));

	/* clear MASK of interrupt(SMMU_INTMASK_NS) */
	ipu_reg_bit_write_dword(SMMU + 0x0010, 0, 5, 0);

	/* set stream status: SMMU normal(SMMU_SMRX_NS).
	default value is OK, NO need to config again */

	/* set master id(mid), (SMMU_SCR.ptw_mid), NO need for CS */

	/* set SMMU Translation Table Base Register for Non-Secure Context Bank0(SMMU_CB_TTBR0) */
	iowrite32(ttbr0, (void *)((unsigned long)SMMU + 0x0204));

	/* set Descriptor select of the SMMU_CB_TTBR0 addressed region of Non-Secure Context Bank
	for 64bit system, select Long Descriptor -> 1(SMMU_CB_TTBCR.cb_ttbcr_des) */
	ipu_reg_bit_write_dword(SMMU + 0x020c, 0, 0, 0x1);

	printk(KERN_DEBUG"smmu=%lx,ttbr0=%d\n", (unsigned long)SMMU, ttbr0);
	/* config FAMA (reserved) */

	return 0;
}

int ipu_smmu_init(unsigned int ttbr0)
{
	printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_mstr_init start\n");
	if (ipu_smmu_mstr_init()) {
		printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_mstr_init fail\n");
		return -EINVAL;
	}

	printk("[ipu_smmu_init]ttbr0=%x\n", ttbr0);

	if (0 == ttbr0) {
		return -EINVAL;
	}

	printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_comm_init start\n");
	if (ipu_smmu_comm_init(ttbr0)) {
		printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_comm_init fail\n");
		return -EINVAL;
	}

	printk(KERN_DEBUG"[ipu_smmu_init]: ipu_smmu_init successfully\n");

	return 0;
}

