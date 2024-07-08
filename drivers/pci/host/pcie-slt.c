#ifdef __SLT_FEATURE__
#include "pcie-kirin-common.h"
#include <linux/file.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/compat.h>
#include <linux/poll.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/wait.h>
#include <linux/pci-aspm.h>
#include <linux/pci.h>
#include <linux/fs.h>
#include <asm/memory.h>
#include <linux/pci_regs.h>


#define WIFI_FIRMWARE_START 0x180000
#define SLT_RANDOM_DATA 0x1234abcd
#define SLT_TEST_DATA_SIZE 0xc0000

#define SIZE_M	(0x100000)
#define L0S_MODE 0
#define L1_MODE 1
#define L1_1_MODE 2
#define L1_2_MODE 3

#define PCIETESTCMD	        _IOWR('p', 0xc1, unsigned long)


/* wait_for_power_status - wait for link Entry lowpower mode
 * @mode: lowpower mode index
*/
int wait_for_power_status(struct kirin_pcie *pcie, int mode)
{
	int status4;
	int status5;
	int wait_condition = 0;
	unsigned long prev_jffy;

	prev_jffy = jiffies;
	while (!(time_after(jiffies, prev_jffy + HZ / 10))) {
		status4 = kirin_elb_readl(pcie, SOC_PCIECTRL_STATE4_ADDR);
		status5 = kirin_elb_readl(pcie, SOC_PCIECTRL_STATE5_ADDR);
		switch (mode) {
		case 0:
			if ((status4 & 0x3f) == 0x12)
				wait_condition = 1;
			break;
		case 1:
			if ((status4 & 0x3f) == 0x14)
				wait_condition = 1;
			break;
		case 2:
			if (((status5 & BIT(15)) == 0) && ((status5 & BIT(14)) == BIT(14)))
				wait_condition = 1;
			break;
		case 3:
			if (((status5 & BIT(15)) == BIT(15)) && ((status5 & BIT(14)) == BIT(14)))
				wait_condition = 1;
			break;
		default:
			PCIE_PR_ERR("unknown lowpower mode\n");
			break;
		}
		if (wait_condition == 1)
			return 0;
		msleep(10);
	}
	return -1;
}

enum pcie_test_result set_loopback_test(struct kirin_pcie *pcie)
{
	u32 value_temp = 0;
	int index = 0;
	int ret = 0;
	int bar2 = 0;
	static int prev_ret = 0xaa;
	unsigned int val = 0;
	struct pci_dev *ep_dev;
	struct pcie_port *pp;
	void __iomem *loop_back_cmp;
	void __iomem *loop_back_src;

	loop_back_cmp = kmalloc(SLT_TEST_DATA_SIZE, GFP_KERNEL);
	if (!loop_back_cmp) {
		PCIE_PR_ERR("can not alloc loop_back_cmp memory");
		return ERR_OTHER;
	}

	pp = &(pcie->pp);
	if (prev_ret == 0xaa) {
		if (wlan_on(pcie->rc_id, 1)) {
			ret =  ERR_OTHER;
			goto TEST_FAIL;
		}
		mdelay(100);
		ret = kirin_pcie_power_on(&pcie->pp, RC_POWER_ON);
		if (ret) {
			PCIE_PR_ERR("Failed to Power On RC");
			ret = ERR_OTHER;
			goto TEST_FAIL;
		}
		/*Unreset wifi*/
		val = readl(pcie->apb_base+ SOC_PCIECTRL_CTRL12_ADDR);
		val |= 0x7;
		writel(val, pcie->apb_base + SOC_PCIECTRL_CTRL12_ADDR);
		kirin_pcie_enumerate(pcie->rc_id);
	}
	mdelay(10);
	set_bme(pcie->rc_id, 1);
	set_mse(pcie->rc_id, 1);
	ep_dev = pcie->ep_dev;
	if (!ep_dev) {
		PCIE_PR_ERR("Failed to get EP Device");
		ret = ERR_OTHER;
		goto TEST_FAIL;
	}
	if (prev_ret == 0xaa) {
		pci_enable_device(ep_dev);
		pci_set_master(ep_dev);
		prev_ret = 0x55;
	}

	pci_read_config_dword(ep_dev, 0x18, &bar2);
	PCIE_PR_INFO("bar2 is %x", bar2);
	loop_back_src = ioremap_nocache(pcie->pp.mem_base, 4*SIZE_M);
	if (!loop_back_src) {
		PCIE_PR_ERR("loop_back_src ioremap fail");
		return ERR_OTHER;
	}
	kirin_pcie_outbound_atu(pcie->rc_id, PCIE_ATU_REGION_INDEX0, PCIE_ATU_TYPE_MEM,
				pp->mem_base, (bar2 & (~0x3)), 8*SIZE_M);
	for (index = 0; index < SLT_TEST_DATA_SIZE; index = index + 4) {
		writel((SLT_RANDOM_DATA + index), (loop_back_cmp + index));
		writel((SLT_RANDOM_DATA + index), (loop_back_src + index + WIFI_FIRMWARE_START));
	}
	if (memcmp((loop_back_src + WIFI_FIRMWARE_START), loop_back_cmp, SLT_TEST_DATA_SIZE)) {
		PCIE_PR_ERR("loop back fail");
		ret = ERR_DATA_TRANS;
		goto TEST_FAIL;
	}
	PCIE_PR_INFO("loop back OK");
	kirin_pcie_config_l0sl1(pcie->rc_id, ASPM_L0S);
	if (wait_for_power_status(pcie, L0S_MODE)) {
		PCIE_PR_ERR("Enter L0s fail");
		ret = ERR_L0S;
		goto TEST_FAIL;
	}
	PCIE_PR_INFO("L0S test pass");
	kirin_pcie_config_l0sl1(pcie->rc_id, ASPM_L1);
	if (wait_for_power_status(pcie, L1_MODE)) {
		PCIE_PR_ERR("Enter L1 fail");
		ret = ERR_L1;
		goto TEST_FAIL;
	}
	PCIE_PR_INFO("L1 test pass");
	kirin_pcie_config_l0sl1(pcie->rc_id, ASPM_L0S_L1);
	if (wait_for_power_status(pcie, L1_MODE)) {
		PCIE_PR_ERR("Enter L0s_and_L1 fail");
		ret = ERR_L0_L1;
		goto TEST_FAIL;
	}
	PCIE_PR_INFO("L0s and L1 test pass");
	/*Return to L0*/
	kirin_pcie_config_l0sl1(pcie->rc_id, ASPM_CLOSE);
	writel(SLT_RANDOM_DATA, loop_back_src + WIFI_FIRMWARE_START);
	kirin_pcie_config_l1ss(pcie->rc_id, L1SS_ASPM_1_1);
	if (wait_for_power_status(pcie, L1_1_MODE)) {
		PCIE_PR_ERR("Enter L1_1 fail");
		ret = ERR_L1_1;
		goto TEST_FAIL;
	}
	PCIE_PR_INFO("L1SS test pass");
	kirin_pcie_config_l1ss(pcie->rc_id, L1SS_ASPM_1_2);
	if (wait_for_power_status(pcie, L1_2_MODE)) {
		PCIE_PR_ERR("Enter L1_2 fail");
		ret = ERR_L1_2;
		goto TEST_FAIL;
	}
	PCIE_PR_INFO("L1SS test pass");
	ret = RESULT_OK;
TEST_FAIL:
	iounmap(loop_back_src);
	kfree(loop_back_cmp);
	loop_back_cmp = NULL;
	return ret;
}
EXPORT_SYMBOL(set_loopback_test);

struct pcie_slt {
	atomic_t ioctl_excl;
	atomic_t open_excl;
	int pcie_slt_major_number;
};
struct pcie_slt g_pcie_slt;

static inline int pcie_slt_lock(atomic_t *excl)
{
	if (atomic_inc_return(excl) == 1) {
		return 0;
	} else {
		atomic_dec(excl);
		return -1;
	}
}

static inline void pcie_slt_unlock(atomic_t *excl)
{
	atomic_dec(excl);
}

static int pcie_slt_ioctl(struct file *file, u_int cmd, unsigned long result)
{
	int ret;
	int test_result;

	if (pcie_slt_lock(&(g_pcie_slt.ioctl_excl)))
		return -EBUSY;

	switch (cmd) {
	case PCIETESTCMD:
		test_result = set_loopback_test(&g_kirin_pcie[0]);
		copy_to_user((unsigned long *)result, &test_result, sizeof(int));

		ret = 0;
		break;
	default:
		ret = -1;
		break;
	}
	pcie_slt_unlock(&(g_pcie_slt.ioctl_excl));
	return ret;
}


static int pcie_slt_open(struct inode *ip, struct file *fp)
{
	PCIE_PR_INFO("pcie_slt_open\n");

	if (pcie_slt_lock(&(g_pcie_slt.open_excl)))

		return -EBUSY;
	PCIE_PR_INFO("pcie_slt_open success\n");
	return 0;
}

static int pcie_slt_release(struct inode *ip, struct file *fp)
{

	PCIE_PR_INFO("pcie_slt_release\n");

	pcie_slt_unlock(&(g_pcie_slt.open_excl));

	return 0;
}

static const struct file_operations pcie_slt_fops = {
	.owner             = THIS_MODULE,
	.unlocked_ioctl    = pcie_slt_ioctl,
	.open              = pcie_slt_open,
	.release           = pcie_slt_release,
};

static int __init pcie_slt_init(void)
{
	int error;
	struct device *pdevice;

	struct class *pcie_slt_class;

	/*semaphore initial*/
	g_pcie_slt.pcie_slt_major_number = register_chrdev(0, "pcie-slt", &pcie_slt_fops);

	if (g_pcie_slt.pcie_slt_major_number < 0) {
		PCIE_PR_ERR("Can't allocate major number for pcie slt device.\n");
		error = -EAGAIN;
		goto failed_register_pcie;
	}
	atomic_set(&g_pcie_slt.open_excl, 0);
	atomic_set(&g_pcie_slt.ioctl_excl, 0);

	pcie_slt_class = class_create(THIS_MODULE, "pcie-slt");

	if (IS_ERR(pcie_slt_class)) {
		PCIE_PR_ERR("Error creating pcie-slt class.\n");
		unregister_chrdev(g_pcie_slt.pcie_slt_major_number, "pcie-slt");
		error = PTR_ERR(pcie_slt_class);
		goto failed_register_pcie;
	}

	 pdevice = device_create(pcie_slt_class, NULL, MKDEV(g_pcie_slt.pcie_slt_major_number, 0), NULL, "pcie-slt");
	if (IS_ERR(pdevice)) {
		error = -EFAULT;
		PCIE_PR_ERR("slt pcie: device_create error.\n");
		goto failed_register_pcie;
	}

	PCIE_PR_INFO("pcie-slt init ok!\n");

	return 0;

failed_register_pcie:
	return error;
}
static void __exit pcie_slt_cleanup(void)
{
	unregister_chrdev(g_pcie_slt.pcie_slt_major_number, "pcie-slt");
}
module_init(pcie_slt_init);
module_exit(pcie_slt_cleanup);
MODULE_DESCRIPTION("Hisilicon Kirin pcie driver");
MODULE_LICENSE("GPL");
#endif
