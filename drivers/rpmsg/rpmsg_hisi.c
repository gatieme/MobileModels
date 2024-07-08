/*
 * Histarisp rpmsg client driver
 *
 * Copyright (c) 2013- Hisilicon Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
/*lint -e666  -e529 -e438 -e713 -e715 -e559 -e626 -e719 -e846 -e514 -e778 -e866 -e84 -e437 -esym(666,*) -esym(529,*) -esym(438,*) -esym(713,*) -esym(715,*) -esym(559,*) -esym(626,*) -esym(719,*) -esym(846,*) -esym(514,*) -esym(778,*) -esym(866,*) -esym(84,*) -esym(437,*)*/
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/scatterlist.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/cdev.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/skbuff.h>
#include <linux/sched.h>
#include <linux/rpmsg.h>
#include <linux/completion.h>
#include <uapi/linux/histarisp.h>
#include <linux/platform_data/remoteproc-hisi.h>
#include <linux/ion.h>
#include <linux/hisi/hisi_ion.h>

static int debug_mask = 0x3;
module_param_named(debug_mask, debug_mask, int, S_IRUGO | S_IWUSR);
static int fast_boot_rtos = 0x1;
module_param_named(fast_boot_rtos, fast_boot_rtos, int, S_IRUGO | S_IWUSR);
#define rpmsg_err(fmt, args...) \
    do {                         \
        if (debug_mask & 0x01)   \
            printk(KERN_INFO "Rpmsg HISI Err: [%s] " fmt, __func__, ##args); \
    } while (0)
#define rpmsg_info(fmt, args...)  \
    do {                         \
        if (debug_mask & 0x02)   \
            printk(KERN_INFO "Rpmsg HISI Info: [%s] " fmt, __func__, ##args);  \
    } while (0)
#define rpmsg_dbg(fmt, args...)  \
    do {                         \
        if (debug_mask & 0x04) \
            printk(KERN_INFO "Rpmsg HISI Debug: [%s] " fmt, __func__, ##args); \
    } while (0)

//#define RPMSG_MSG_SIZE          (496)

enum isp_rpmsg_state {
    RPMSG_UNCONNECTED,
    RPMSG_CONNECTED,
};

struct rpmsg_hisi_service {
    struct cdev *cdev;
    struct device *dev;
    struct rpmsg_channel *rpdev;
    struct list_head list;
    struct mutex lock;
};

struct rpmsg_hisi_instance {
    struct list_head node;
    struct rpmsg_hisi_service *hisi_serv;
    struct rpmsg_endpoint *ept;
    struct sk_buff_head queue;
    struct mutex lock;
    wait_queue_head_t readq;
	struct ion_client *client;
    void *rpmsg_msg;
    u32 dst;
    int state;
};

struct cdev_info {
    struct class *rpmsg_hisi_class;
    dev_t rpmsg_hisi_dev;
    struct cdev isp_cdev;
    struct device *isp_dev;
    int minor;
    int enable_rpmsg;
};
struct hisp_rpmsgrefs_s{
    atomic_t sendin_refs;
    atomic_t sendx_refs;
    unsigned long long sendx_last;
    atomic_t recvin_refs;
    atomic_t recvx_refs;
    atomic_t recvtask_refs;
    unsigned long long recvx_last;
}hisp_rpmsgrefs;

static struct cdev_info  cdev_local;
static struct rpmsg_hisi_service *hisi_isp_serv;
static atomic_t instances;

int rpmsg_client_debug = INVALID_CLIENT;
EXPORT_SYMBOL(rpmsg_client_debug);

static unsigned long long get_hisitime(void)
{
    return hisi_getcurtime();
}

static unsigned int reg_to_s(unsigned long long ts)
{
    return do_div(ts , 1000000000);
}

static unsigned int reg_to_us(unsigned long long ts)
{
    return do_div(ts ,1000);
}

void hisp_sendin(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->sendin_refs);
}

void hisp_sendx(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->sendx_refs);
    dev->sendx_last = get_hisitime();
}

void hisp_recvin(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->recvin_refs);
}
void hisp_recvx(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->recvx_refs);
    dev->recvx_last = get_hisitime();
}

void hisp_recvtask(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->recvtask_refs);
}

void hisp_rpmsgrefs_dump(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    char time_log[80] = "";
    char *ptime_log;
    ptime_log = time_log;
    print_time(dev->sendx_last, ptime_log);
    pr_info("sendin_refs.0x%x, sendx_refs.0x%x, sendx_timer.%s\n", atomic_read(&dev->sendin_refs),atomic_read(&dev->sendx_refs),ptime_log);
    print_time(dev->recvx_last, ptime_log);
    pr_info("recvin_refs.0x%x, recvx_refs.0x%x, recvtask_refs.0x%x recvx_timer.%s\n", atomic_read(&dev->recvin_refs),atomic_read(&dev->recvx_refs),atomic_read(&dev->recvtask_refs),ptime_log);
}

void hisp_rpmsgrefs_reset(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    hisp_rpmsgrefs_dump();
    atomic_set(&dev->sendin_refs, 0);
    atomic_set(&dev->sendx_refs, 0);
    dev->sendx_last = 0;
    atomic_set(&dev->recvin_refs, 0);
    atomic_set(&dev->recvx_refs, 0);
    atomic_set(&dev->recvtask_refs, 0);
    dev->recvx_last = 0;
}

static const struct file_operations rpmsg_hisi_fops = {
    .owner          = THIS_MODULE,
};

static int rpmsg_hisi_probe(struct rpmsg_channel *rpdev)
{
    struct rpmsg_hisi_service *hisi_serv = NULL;

    hisi_serv = kzalloc(sizeof(*hisi_serv), GFP_KERNEL);
    if (!hisi_serv) {
        rpmsg_err("kzalloc failed\n");
        return -ENOMEM;
    }

    INIT_LIST_HEAD(&hisi_serv->list);
    mutex_init(&hisi_serv->lock);

    hisi_serv->cdev = &cdev_local.isp_cdev;
    hisi_serv->dev = cdev_local.isp_dev;
    hisi_isp_serv = hisi_serv;

    hisi_serv->rpdev = rpdev;

    dev_set_drvdata(&rpdev->dev, hisi_serv);

    rpmsg_info("new HISI connection srv channel: %u -> %u!\n",
                        rpdev->src, rpdev->dst);

    rpmsg_dbg("Exit ...\n");
    return 0;
}

static void rpmsg_hisi_remove(struct rpmsg_channel *rpdev)
{
    struct rpmsg_hisi_service *hisi_serv = dev_get_drvdata(&rpdev->dev);

    /* check list */

    mutex_lock(&hisi_serv->lock);
    if (list_empty(&hisi_serv->list)) {
        mutex_unlock(&hisi_serv->lock);
        kfree(hisi_serv);
        hisi_serv = NULL;

        rpmsg_info("hisi_serv->list is empty, instances = %d.\n", atomic_read(&instances));
    } else {
        mutex_unlock(&hisi_serv->lock);
        /* Maybe here need to debug, in case more exception case */
        rpmsg_err("rpmsg remove exception, instances = %d \n", atomic_read(&instances));
        WARN_ON(1);
    }

    rpmsg_info("Exit ...\n");
    return;
}

static void rpmsg_hisi_driver_cb(struct rpmsg_channel *rpdev, void *data,
                        int len, void *priv, u32 src)
{
    rpmsg_dbg("Enter ...\n");
    dev_warn(&rpdev->dev, "uhm, unexpected message\n");

    print_hex_dump(KERN_DEBUG, __func__, DUMP_PREFIX_NONE, 16, 1,
               data, len,  true);
    rpmsg_dbg("Exit ...\n");
}

static struct rpmsg_device_id rpmsg_hisi_id_table[] = {
    { .name    = "rpmsg-isp-debug" },
    { },
};
MODULE_DEVICE_TABLE(platform, rpmsg_hisi_id_table);

static struct rpmsg_driver rpmsg_hisi_driver = {
    .drv.name   = KBUILD_MODNAME,
    .drv.owner  = THIS_MODULE,
    .id_table   = rpmsg_hisi_id_table,
    .probe      = rpmsg_hisi_probe,
    .callback   = rpmsg_hisi_driver_cb,
    .remove     = rpmsg_hisi_remove,
};

static ssize_t rpmsgrefs_show(struct device *pdev, struct device_attribute *attr,
                    char *buf)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    char *s = buf;

    s += sprintf(s, "%s send.(0x%x, 0x%x, [%05u.%06u]), recv.(0x%x, 0x%x, [%05u.%06u])\n", "hisp_rpmsgrefs", atomic_read(&dev->sendin_refs),
            atomic_read(&dev->sendx_refs), reg_to_s(dev->sendx_last), reg_to_us(dev->sendx_last), atomic_read(&dev->recvin_refs),
            atomic_read(&dev->recvx_refs), reg_to_s(dev->recvx_last), reg_to_us(dev->recvx_last));
    return (s - buf);
}

static ssize_t rpmsgrefs_store(struct device *pdev, struct device_attribute *attr,
                     const char *buf, size_t count)
{
    return count;
}

static DEVICE_ATTR(rpmsgrefs, (S_IRUGO | S_IWUSR | S_IWGRP), rpmsgrefs_show, rpmsgrefs_store);

static int __init rpmsg_hisi_init(void)
{
    int ret, major;

    rpmsg_dbg("Enter ...\n");

    cdev_local.minor = 0;
    atomic_set(&instances, 0);

    ret = alloc_chrdev_region(&cdev_local.rpmsg_hisi_dev, 0, 1,
                            KBUILD_MODNAME);
    if (ret) {
        pr_err("alloc_chrdev_region failed: %d\n", ret);
        goto out;
    }

    cdev_local.rpmsg_hisi_class = class_create(THIS_MODULE, KBUILD_MODNAME);
    if (IS_ERR(cdev_local.rpmsg_hisi_class)) {
        ret = PTR_ERR(cdev_local.rpmsg_hisi_class);
        pr_err("class_create failed: %d\n", ret);
        goto unreg_region;
    }

    major = MAJOR(cdev_local.rpmsg_hisi_dev);
    rpmsg_dbg("cdev_local.rpmsg_hisi_dev major.%u \n", (unsigned int)major);

    cdev_init(&cdev_local.isp_cdev, &rpmsg_hisi_fops);
    rpmsg_dbg("hisi_serv->cdev.%pK\n", &cdev_local.isp_cdev);

    cdev_local.isp_cdev.owner = THIS_MODULE;
    ret = cdev_add(&cdev_local.isp_cdev, MKDEV(major, cdev_local.minor), 1);
    if (ret) {
        rpmsg_err("cdev_add failed: %d\n", ret);
        goto destroy_class;
    }

    cdev_local.isp_dev = device_create(cdev_local.rpmsg_hisi_class, NULL,
                                    MKDEV(major, cdev_local.minor), NULL,
                                    "rpmsg-hisi%d", cdev_local.minor);
    if (IS_ERR(cdev_local.isp_dev)) {
        ret = PTR_ERR(cdev_local.isp_dev);
        rpmsg_dbg("device_create failed: %d\n", ret);
        goto clean_cdev;
    }

	cdev_local.enable_rpmsg = 0;

    if ( device_create_file(cdev_local.isp_dev, &dev_attr_rpmsgrefs) < 0 )
        rpmsg_err("Failed : device_create_file");

    return register_rpmsg_driver(&rpmsg_hisi_driver);

clean_cdev:
    cdev_del(&cdev_local.isp_cdev);
destroy_class:
    class_destroy(cdev_local.rpmsg_hisi_class);
unreg_region:
    unregister_chrdev_region(cdev_local.rpmsg_hisi_dev, 1);
out:
    rpmsg_dbg("Exit ...\n");
    return ret;
}
module_init(rpmsg_hisi_init);

static void __exit rpmsg_hisi_exit(void)
{
    int major = MAJOR(cdev_local.rpmsg_hisi_dev);

    rpmsg_dbg("Enter ...\n");
    unregister_rpmsg_driver(&rpmsg_hisi_driver);
    device_destroy(cdev_local.rpmsg_hisi_class, MKDEV(major, cdev_local.minor));
    cdev_del(&cdev_local.isp_cdev);
    class_destroy(cdev_local.rpmsg_hisi_class);
    unregister_chrdev_region(cdev_local.rpmsg_hisi_dev, 1);
    rpmsg_dbg("Exit ...\n");
}
module_exit(rpmsg_hisi_exit);

MODULE_DESCRIPTION("HISI offloading rpmsg driver");
MODULE_LICENSE("GPL v2");
