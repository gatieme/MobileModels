/*
 * Generic driver for the cambricon ipu device.
 *
 * Copyright (C) 2016 Cambricon Limited
 *
 * Licensed under the GPL v2 or later.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/semaphore.h>
#include <linux/version.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#include <linux/compiler.h>
#include <linux/regulator/consumer.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>
#include <linux/pm_runtime.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/input.h>
#include <linux/wakelock.h>
#include <linux/clk.h>
#include <linux/hwspinlock.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include "ipu_smmu_drv.h"
#include "cambricon_ipu.h"
#include <linux/mfd/hisi_pmic.h>

/* define fasync queue */
static struct fasync_struct *ipu_async_queue;

#define UNUSED_PARAMETER(x) ((void)(x))

/* cambricon ipu private data */

struct cambricon_ipu_private
{
	const char *name;
	unsigned int	irq;

	unsigned int	config_reg_length;
	phys_addr_t	config_reg_phys_addr;
	void __iomem	*config_reg_virt_addr;

	unsigned int	inst_ram_size;
	phys_addr_t	inst_ram_phys_addr;
	void __iomem	*inst_ram_virt_addr;

	struct semaphore	config_reg_sem;
	struct semaphore	inst_ram_sem;
	struct semaphore	llseek_sem;
	/* char device */
	dev_t	chrdev;	/* ipu char device number */
	struct cdev	cdev;/* ipu char device */

	/* platform device resource */
	struct resource *inst_mem, *cfg_mem;

	struct regulator *vipu_ip;
};



/* global variables */
static unsigned int ipu_major = 0;
static unsigned int ipu_minor = 0;
static unsigned int ipu_open_count = 0;
static struct cambricon_ipu_private *adapter = NULL;
static struct class *dev_class = NULL;
static unsigned int smmu_ttbr0 = 0; /* base address of TTBR */


/* ipu char device ops declaration */
static int ipu_open(struct inode *inode, struct file *filp);
static int ipu_release(struct inode *inode, struct file *filp);
static ssize_t ipu_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
static ssize_t ipu_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,36))
static int ipu_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg);
#else
static long ipu_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);
#endif
static long ipu_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);
static loff_t ipu_llseek(struct file *filp, loff_t off, int whence);
static int ipu_fasync(int fd, struct file *filp, int on);
static void regulator_ip_vipu_enable(void);
static void regulator_ip_vipu_disable(void);

/* global variable declaration */
static const struct file_operations ipu_fops = {
	.owner			= THIS_MODULE,/*lint !e64*/
	.open			= ipu_open,
	.release		= ipu_release,
	.read			= ipu_read,
	.write			= ipu_write,
#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,36))
	.ioctl			= ipu_ioctl,
#else
	.unlocked_ioctl = ipu_ioctl,
#endif
	.llseek 		= ipu_llseek,
	.fasync			= ipu_fasync,
};/*lint !e785*/
/* ipu platform device */
static struct platform_device cambricon_ipu_device = {
	.name	= "cambricon-ipu",
	.id	= -1,
};/*lint !e785*/

static void regulator_ip_vipu_enable(void)
{
	int ret;

	ret = regulator_enable(adapter->vipu_ip);
	if (ret != 0) {
		printk(KERN_ERR"[regulator_ip_vipu_enable]:Failed to enable %s: %d\n", __func__, ret);
		return ;
	}
	printk(KERN_DEBUG"[regulator_ip_vipu_enable]:success to enable %s: %d\n", __func__, ret);
}

static void regulator_ip_vipu_disable(void)
{
	int ret;

	ret = regulator_disable(adapter->vipu_ip);
	if (ret != 0) {
		printk(KERN_ERR"[regulator_ip_vipu_disable]:Failed to disable %s: %d\n", __func__, ret);
		return ;
	}
	printk(KERN_DEBUG"[regulator_ip_vipu_disable]:success to disable %s: %d\n", __func__, ret);
}

#ifdef CAMBRICON_IPU_IRQ
/*
 * A very tiny interrupt handler. It runs with interrupts disabled,
 * but there is possibility of conflicting with operating register
 * at the same time in two different CPUs. So we need to serialize
 * accesses to the chip with the ipu_lock spinlock.
 */
static irqreturn_t ipu_interrupt_handler(int irq, void *dev)
{
	unsigned long reg_virt_addr = (unsigned long)adapter->config_reg_virt_addr;
	unsigned int reg_smmu_status;

	(void)adapter->chrdev;

	if (dev == NULL) {
		printk(KERN_ERR"[ipu_interrupt_handler]: no dev\n");
	}

	printk(KERN_DEBUG"[ipu_interrupt_handler]: %d\n", irq);

	reg_smmu_status = ioread32((void *)(reg_virt_addr + 0x80018));

	if (0 != reg_smmu_status) {
		printk(KERN_ERR"[ipu_interrupt_handler]: error, smmu interrupt received: %x\n", reg_smmu_status);
		/* clear smmu interrupt */
		iowrite32(0x3f, (void *)(reg_virt_addr + 0x8001C));
	} else {
		/* clear ipu finished status */
		iowrite32(0, (void *)(reg_virt_addr + IPU_STATUS_REG));
		printk(KERN_DEBUG"[ipu_interrupt_handler]: status_reg=%x\n",ioread32((void *)(reg_virt_addr + IPU_STATUS_REG)));

		if (ipu_async_queue)
			kill_fasync(&ipu_async_queue, SIGIO, POLL_IN);

		printk(KERN_DEBUG"[ipu_interrupt_handler]: IRQ_HANDLED ok\n");
	}

	return IRQ_HANDLED;
}
#endif

/* ipu char device ops function implementation */
static int ipu_open(struct inode *inode, struct file *filp)
{
	struct cambricon_ipu_private *dev;
	void __iomem *CNN = ioremap((unsigned long)0xff486000, (unsigned long)0xfff);

	if (!inode || !filp){
		printk(KERN_ERR"[ipu_open]: invalid input parameter !\n");
		return -EINVAL;
	}

	if (ipu_open_count >= 1) {
		printk(KERN_ERR"[ipu_open]: IPU device has already been opened !\n");
		return -EBUSY;
	}else {
		printk(KERN_ERR"[ipu_open]: IPU device open success!\n");
		ipu_open_count++;
	}

	/*ICS power on*/
	regulator_ip_vipu_enable();

	/*ES irq*/
	iowrite32(0x0, (void *)((unsigned long)CNN + 0x4));
	printk(KERN_DEBUG"[ipu_open]: CNN-irq = %d \n",ioread32((void *)((unsigned long)CNN + 0x4)));

#ifdef IPU_SMMU_ENABLE
	ipu_smmu_init_es(smmu_ttbr0);
#endif

	dev = container_of(inode->i_cdev, struct cambricon_ipu_private, cdev);/*lint !e826*/

	filp->private_data = dev;
	printk(KERN_DEBUG"[ipu_open]: %p\n", filp);

	return SUCCESS;
}

static int ipu_release(struct inode *inode, struct file *filp)
{
	struct cambricon_ipu_private *dev;

	UNUSED_PARAMETER(inode);

	if (!inode || !filp){
		printk(KERN_ERR"[ipu_release]: input parameter inode or filp is invalid !\n");
		return -EINVAL;
	}

	dev = filp->private_data;

	if (dev) {
		ipu_fasync(-1, filp, 0);
		ipu_open_count = 0;
		printk(KERN_DEBUG"[ipu_release]: %p\n", filp);
	} else {
		printk(KERN_ERR"[ipu_release]: No IPU device!\n");
		return -EINVAL;
	}
	/*ICS power down*/
	regulator_ip_vipu_disable();

	return SUCCESS;
}

static int input_check(unsigned int cmd, unsigned long arg)
{
	unsigned int *offset;

	if (cmd == RDCONFIG_BYTE || cmd == RDCONFIG_WORD || cmd == RDCONFIG_DWORD) {
		if (arg > 0xfffff) {
			printk(KERN_ERR"[input_check]: input parameter arg for read offset is invalid !\n");
			return -1;
		}
		return 0;
	}
	if (cmd == WRCONFIG_BYTE || cmd == WRCONFIG_WORD || cmd == WRCONFIG_DWORD) {
		if (!arg) {
			printk(KERN_ERR"[input_check]: input parameter arg for write is invalid !\n");
			return -1;
		}
		offset = (unsigned int *)arg;
		if (*offset > 0xfffff) {
			printk(KERN_ERR"[input_check]: input parameter arg for write offset is invalid !\n");
			return -1;
		}
		return 0;
	}

	printk(KERN_DEBUG"[input_check]: WRONG CMD!\n");
	return -1;
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,36))
static int ipu_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
#else
static long ipu_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
#endif
{
	unsigned int ret_value = SUCCESS;
	unsigned long reg_virt_addr;
	unsigned int read_value;
	struct cambricon_ipu_private *dev;

	if (input_check(cmd, arg)){
		printk(KERN_ERR"[ipu_ioctl]: input parameter arg is invalid !\n");
		return -EINVAL;
	}

	if (!filp){
		printk(KERN_ERR"[ipu_ioctl]: input parameter filp is invalid !\n");
		return -EINVAL;
	}

	dev = filp->private_data;

	if (!dev) {
		printk(KERN_ERR"[ipu_ioctl]: No IPU device!\n");
		return -EINVAL;
	}

	if (!dev->config_reg_virt_addr) {
		printk(KERN_ERR"[ipu_ioctl]: reg_virt_addr is invalid!\n");
		return -EINVAL;
	}

	reg_virt_addr = (unsigned long)dev->config_reg_virt_addr;

	if(down_interruptible(&dev->config_reg_sem))
		return -ERESTARTSYS;

	if(cmd == RDCONFIG_BYTE) {
		read_value = (unsigned int)ioread8((void *)(reg_virt_addr + arg));
		printk(KERN_DEBUG"[ipu_ioctl]: Read CONFIG REG byte offset 0x%x, value is 0x%x\n", (unsigned int)arg, (unsigned int)read_value);
		ret_value = (unsigned char) read_value;
	}

	if(cmd == RDCONFIG_WORD) {
		//unsigned short read_value;
		read_value = (unsigned int)ioread16((void *)(reg_virt_addr + arg));
		printk(KERN_DEBUG"[ipu_ioctl]: Read CONFIG REG word offset 0x%x, value is 0x%x\n", (unsigned int)arg, (unsigned int)read_value);
		ret_value =  (unsigned short)read_value;
	}

	if(cmd == RDCONFIG_DWORD) {
		//unsigned int read_value;
		read_value = ioread32((void *)(reg_virt_addr + arg));
		printk(KERN_DEBUG"[ipu_ioctl]: Read CONFIG REG dword offset 0x%x, value is 0x%x\n", (unsigned int)arg, (unsigned int)read_value);
		ret_value = (unsigned int)read_value;
	}

	if(cmd == WRCONFIG_BYTE) {
		unsigned int *offset = (unsigned int *)arg;
		unsigned char *data = (unsigned char *)((unsigned long *)arg + 1);
		printk(KERN_DEBUG"[ipu_ioctl]: Write CONFIG REG byte offset 0x%x, value is 0x%x\n", (unsigned int) *offset, (unsigned int)*data);
		iowrite8(*data, (void *)(reg_virt_addr + *offset));
	}

	if(cmd == WRCONFIG_WORD) {
		unsigned int *offset = (unsigned int *)arg;
		unsigned short *data = (unsigned short *)((unsigned long *)arg + 1);
		printk(KERN_DEBUG"[ipu_ioctl]: Write CONFIG REG word offset 0x%x, value is 0x%x\n", (unsigned int) *offset, (unsigned int)*data);
		iowrite16(*data, (void *)(reg_virt_addr + *offset));
	}

	if(cmd == WRCONFIG_DWORD) {
		unsigned int *offset = (unsigned int *)arg;
		unsigned int *data = (unsigned int *)((unsigned long *)arg + 1);
		printk(KERN_DEBUG"[ipu_ioctl]: Write CONFIG REG dword offset 0x%x, value is 0x%x\n", (unsigned int) *offset, (unsigned int)*data);
		iowrite32(*data, (void *)(reg_virt_addr + *offset));
	}

	up(&(dev->config_reg_sem));

	return ret_value;
}

static ssize_t ipu_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	unsigned int ret_value = SUCCESS;
	struct cambricon_ipu_private *dev;
	if (!filp || !buf) {
		printk(KERN_ERR"[ipu_read]: input parameter filp or buf is invalid!\n");
		return -EINVAL;
	}
	dev = filp->private_data;

	if (!dev) {
		printk(KERN_ERR"[ipu_read]: No IPU device!\n");
		return -EINVAL;
	}

	if (down_interruptible(&dev->inst_ram_sem))
		return -ERESTARTSYS;

	if (count == 0 || count == 0xFFFFFFFF) {
		printk(KERN_ERR"[ipu_read]: input parameter count is invalid!\n");
		goto out;
	}

	if (*f_pos > dev->inst_ram_size || *f_pos < 0) {
		printk(KERN_ERR"[ipu_read]: Read file position out of range!\n");
		goto out;
	}
	if ((unsigned long)*f_pos + count > dev->inst_ram_size)
		count = dev->inst_ram_size - (unsigned long)*f_pos;

	if (dev->inst_ram_virt_addr) {
		if (copy_to_user(buf, (void*)((unsigned long)dev->inst_ram_virt_addr + (unsigned long)(*f_pos)), count)) {
			printk(KERN_ERR"[ipu_read]: Copy data to user failed!\n");
			ret_value = EFAULT;
			goto out;
		}
	}

	ret_value = (unsigned int)count;
	printk(KERN_DEBUG"[ipu_read]: read %d bytes\n", ret_value);

out:
	up(&(dev->inst_ram_sem));
	return ret_value;
}

static ssize_t ipu_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	unsigned int ret_value = SUCCESS;
	struct cambricon_ipu_private *dev;
	if (!filp || !buf) {
		printk(KERN_ERR"[ipu_write]: input parameter filp or buf is invalid !\n");
		return -EINVAL;
	}
	dev = filp->private_data;

	if (!dev) {
		printk(KERN_ERR"[ipu_write]: No IPU device!\n");
		return -EINVAL;
	}

	if(down_interruptible(&dev->inst_ram_sem))
		return -ERESTARTSYS;

	if (count == 0 || count == 0xFFFFFFFF) {
		printk(KERN_ERR"[ipu_write]:input parameter count is invalid!\n");
		goto out;
	}
	if (*f_pos > dev->inst_ram_size || *f_pos < 0) {
		printk(KERN_ERR"[ipu_write]: Write file position out of range!\n");
		goto out;
	}
	if((unsigned long)*f_pos + count > dev->inst_ram_size)
		count = dev->inst_ram_size - (unsigned long)*f_pos;

	if (dev->inst_ram_virt_addr) {
		if(copy_from_user((void *)((unsigned long)dev->inst_ram_virt_addr + (unsigned long)(*f_pos)), buf, count)) {
			printk(KERN_ERR"[ipu_write]: Copy data from user failed!\n");
			ret_value = EFAULT;
			goto out;
		}
	}

	ret_value = (unsigned int)count;
	printk(KERN_DEBUG"[ipu_write]: write %d bytes\n", ret_value);
out:
	up(&dev->inst_ram_sem);
	return ret_value;
}

static loff_t ipu_llseek(struct file *filp, loff_t off, int whence)
{
	struct cambricon_ipu_private *dev;
	loff_t pos;
	if (!filp) {
		printk(KERN_ERR"[ipu_llseek]: input parameter filp is invalid !\n");
		return -EINVAL;
	}
	dev = filp->private_data;
	if (!dev) {
		printk(KERN_ERR"[ipu_llseek]: No IPU device!\n");
		return -EINVAL;
	}

	if(down_interruptible(&dev->llseek_sem))
		return -ERESTARTSYS;

	pos = filp->f_pos;
	switch (whence) {
		/* Set f_pos */
	case 0:
		pos = off;
		break;
		/* Move f_pos forward */
	case 1:
		pos += off;
		break;
		/* More */
	case 2:
		break;
		/* Default Operation */
	default:
		return -EINVAL;
	}

	if ((pos > dev->inst_ram_size) || (pos < 0)) {
		printk(KERN_ERR"[ipu_llseek]: Move file position out of range!");
		return -EINVAL;
	}

	printk(KERN_DEBUG"[ipu_llseek]: Move file position to %d", (unsigned int)pos);
	up(&dev->llseek_sem);
	return filp->f_pos = pos;
}

/* async notify user space application */
static int ipu_fasync(int fd, struct file *filp, int on)
{
	if (fasync_helper(fd, filp, on, &ipu_async_queue) >= 0)
		return 0;
	else
		return -EIO;
}

/* Allocate ipu chrdev region */
static int cambricon_ipu_chrdev_region(dev_t *chrdev)
{
	int err = -1;

	/* Allocate char device region */
	if (ipu_major) {
		*chrdev = MKDEV(ipu_major, ipu_minor);
		err = register_chrdev_region(*chrdev, 1, IPU_NAME);
	} else {
		err = alloc_chrdev_region(chrdev, 0, 1, IPU_NAME);
	}
	if (err < 0) {
		printk(KERN_ERR"[cambricon_ipu_chrdev_region]:alloc_chrdev_region fail!\n");
		return err;
	}

	ipu_major = MAJOR(*chrdev);
	ipu_minor = MINOR(*chrdev);

	return err;
}

/* probe() function for platform driver */
static int cambricon_ipu_probe(struct platform_device *pdev)
{
	int err;
	dev_t chrdev = 0;
	struct device *temp = NULL;
	struct resource *res, *res_cfg;
	unsigned long  size;

	printk(KERN_DEBUG"[ipu_probe]: Initializing IPU device!\n");

	/* Allocate char device region */
	err = cambricon_ipu_chrdev_region(&chrdev);
	if (err < 0) {
		printk(KERN_ERR"[ipu_probe]: Failed to allocate device ID for IPU!\n");
		goto fail;
	}

	/* Allocate cambricon_ipu_private struct and asigned to global variable adapter */
	adapter = kmalloc(sizeof(struct cambricon_ipu_private), GFP_KERNEL);
	if (!adapter) {
		err = -ENOMEM;
		printk(KERN_ERR"[ipu_probe]: Failed to allocate memory for struct ipu!\n");
		goto unregister;
	}

	/* Initialize cambricon_ipu_private struct */
	memset(adapter, 0, sizeof(struct cambricon_ipu_private));
	adapter->name = IPU_NAME;
	adapter->irq = (unsigned int)platform_get_irq_byname(pdev, "ipu_dma_irq");
	printk(KERN_DEBUG"[ipu_probe]: platform_get_irq_byname:%d\n",adapter->irq);

	/* get regulator */
	adapter->vipu_ip = devm_regulator_get(&pdev->dev, "vipu");
	if (IS_ERR(adapter->vipu_ip)) {
		printk(KERN_ERR"[ipu_probe]:Couldn't get regulator ip [%s]! \n", __func__);
		return err;
	}
	printk(KERN_DEBUG"[ipu_probe]:Get regulator ip [%s] succuse!\n", __func__);

	printk(KERN_DEBUG"[ipu_probe]: dev-num-resouce:%d\n",pdev->num_resources);

	sema_init(&(adapter->config_reg_sem), 1);
	sema_init(&(adapter->inst_ram_sem), 1);
	sema_init(&(adapter->llseek_sem), 1);

	/* ipu instruction ram resource */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);

	if (res == NULL) {
		dev_err(&pdev->dev, "[ipu_probe]: failed to get instruction resource\n");
		err = -ENXIO;
		goto cleanup;
	}

	size = resource_size(res);
	adapter->inst_ram_phys_addr = res->start;
	adapter->inst_ram_size = (unsigned int)size;
	adapter->inst_mem = request_mem_region(res->start, size, pdev->name);
	if (adapter->inst_mem == NULL) {
		dev_err(&pdev->dev, "[ipu_probe]: failed to get instruction memory region\n");
		err = -ENOENT;
		goto cleanup;
	}

	adapter->inst_ram_virt_addr = ioremap(res->start, size);
	if (adapter->inst_ram_virt_addr == NULL) {
		dev_err(&pdev->dev, "[ipu_probe]: ioremap() of instruction resource failed\n");
		err = -ENXIO;
		goto release_res_inst;
	}

	/* ipu configure registers resource */
	res_cfg = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (res_cfg == NULL) {
		dev_err(&pdev->dev, "[ipu_probe]: failed to get configure registers resource\n");
		err = -ENXIO;
		goto unmap_ram;
	}

	size = resource_size(res_cfg);
	adapter->config_reg_phys_addr = res_cfg->start;
	adapter->config_reg_length = (unsigned int)size;
	adapter->cfg_mem = request_mem_region(res_cfg->start, size, pdev->name);
	if (adapter->cfg_mem == NULL) {
		dev_err(&pdev->dev, "[ipu_probe]: failed to get configure registers memory region\n");
		err = -ENOENT;
		goto unmap_ram;
	}

	adapter->config_reg_virt_addr = ioremap(res_cfg->start, size);
	if (adapter->config_reg_virt_addr == NULL) {
		dev_err(&pdev->dev, "[ipu_probe]: ioremap() of configure registers resource failed\n");
		err = -ENXIO;
		goto release_res_cfg;
	}

#ifdef CAMBRICON_IPU_IRQ
	/* request ipu irq */
	if (request_irq(adapter->irq, ipu_interrupt_handler, (unsigned long)IRQF_TRIGGER_HIGH, IPU_NAME, &(adapter->cdev))) {
		printk(KERN_ERR"[ipu_probe]: IPU Require IRQ failed!\n");
		err = -EIO;
		goto free_irq;
	}
	printk(KERN_DEBUG"[ipu_probe]: IPU Require IRQ Succeeded\n");
#endif

	/* Add ipu char device to system, udev can auto detect */
	cdev_init(&(adapter->cdev), &ipu_fops);
	adapter->cdev.owner = THIS_MODULE;/*lint !e64*/
	adapter->cdev.ops = &ipu_fops;
	err = cdev_add(&(adapter->cdev), chrdev, 1);
	if (err) {
		printk(KERN_ERR"[ipu_probe]: Failed to Add IPU to system!\n");
		goto unmap_reg;
	}

	/* Create ipu class under /sys/class */
	dev_class = class_create(THIS_MODULE, IPU_NAME);/*lint !e64*/
	if (IS_ERR(dev_class)) {
		err = (int)PTR_ERR(dev_class);
		printk(KERN_ERR"[ipu_probe]: Failed to create ipu class!\n");
		goto destroy_cdev;
	}
	/* Register ipu device in sysfs, and this will cause udev to create corresponding device node */
	temp = device_create(dev_class, NULL, chrdev, NULL, "%s", IPU_NAME);
	if (IS_ERR(temp)) {
		err = (int)PTR_ERR(temp);
		printk(KERN_ERR"[ipu_probe]: Failed to mount IPU to /dev/ipu!\n");
		goto destroy_class;
	}

#ifdef IPU_SMMU_ENABLE
	smmu_ttbr0 = ipu_get_smmu_base_phy(&pdev->dev);
#endif

	printk(KERN_DEBUG"[ipu_probe]: Succeeded to initialize ipu device.\n");

	return SUCCESS;

#ifdef CAMBRICON_IPU_IRQ
free_irq:
	free_irq(adapter->irq, &(adapter->cdev));
#endif
destroy_class:
	class_destroy(dev_class);
destroy_cdev:
	cdev_del(&(adapter->cdev));
unmap_reg:
	iounmap(adapter->config_reg_virt_addr);
release_res_cfg:
	release_mem_region((unsigned long)res_cfg->start, size);
unmap_ram:
	iounmap(adapter->inst_ram_virt_addr);
release_res_inst:
	release_mem_region((unsigned long)res->start, size);
cleanup:
	kfree(adapter);
unregister:
	unregister_chrdev_region(chrdev, 1);
fail:
	return err;
}

/* remove() function for platform driver */
static int __exit cambricon_ipu_remove(struct platform_device *pdev)
{
	dev_t chrdev;

	UNUSED_PARAMETER(pdev);

	chrdev = MKDEV(ipu_major, ipu_minor);

	printk(KERN_DEBUG"[ipu_remove]: Destroying IPU device!\n");

	/* Destroy ipu class */
	if (dev_class) {
		device_destroy(dev_class, chrdev);
		class_destroy(dev_class);
	}

	/* Destroy ipu */
	if (adapter) {
		cdev_del(&(adapter->cdev));
		iounmap(adapter->config_reg_virt_addr);
		iounmap(adapter->inst_ram_virt_addr);
		release_mem_region(adapter->inst_mem->start, resource_size(adapter->inst_mem));
		release_mem_region(adapter->cfg_mem->start, resource_size(adapter->cfg_mem));

#ifdef CAMBRICON_IPU_IRQ
		free_irq(adapter->irq, &(adapter->cdev));
#endif
		kfree(adapter);
	}

	/* Unregister chrdev region */
	unregister_chrdev_region(chrdev, 1);

	printk(KERN_DEBUG"[ipu_remove]: Succeeded to destroying IPU device.\n");

	return 0;
}
/*lint -e785*/
static const struct of_device_id cambricon_ipu_match_table[] = {
	{ .compatible = COMP_CAMBRICON_IPU_DRV_NAME, },
	{},
};

MODULE_DEVICE_TABLE(of, cambricon_ipu_match_table);
/* ipu platform drive */
static struct platform_driver cambricon_ipu_driver = {
	.driver	= {
		.name = "cambricon-ipu",
		.owner = THIS_MODULE,/*lint !e64*/
		.of_match_table = of_match_ptr(cambricon_ipu_match_table),
	},
	.probe	= cambricon_ipu_probe,
	.remove	= cambricon_ipu_remove,
};
/*lint +e785*/
/* ipu platform device and driver register */
static int __init cambricon_ipu_init(void)
{
	int ret;

	printk(KERN_DEBUG"[ipu_init]: platform device and driver register!\n");
	ret = platform_driver_register(&cambricon_ipu_driver);/*lint !e64*/
	if (ret)
		return ret;

	ret = platform_device_register(&cambricon_ipu_device);
	if (ret)
		goto fail_platform_device;

	return 0;

fail_platform_device:
	platform_driver_unregister(&cambricon_ipu_driver);
	return ret;
}

/* ipu platform device and driver unregister */
static void __exit cambricon_ipu_exit(void)
{
	platform_device_unregister(&cambricon_ipu_device);
	platform_driver_unregister(&cambricon_ipu_driver);
}

/*lint -e753 -e528*/

module_init(cambricon_ipu_init);
module_exit(cambricon_ipu_exit);

MODULE_AUTHOR("Cambricon Limited");
MODULE_LICENSE("GPL");

