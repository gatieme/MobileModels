/*
 * record the data to rdr. (RDR: kernel run data recorder.)
 * This file wraps the ring buffer.
 *
 * Copyright (c) 2013 Hisilicon Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/printk.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/hisi/rdr_pub.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/delay.h>
#include <linux/miscdevice.h>
#include <linux/rproc_share.h>
#include <linux/version.h>
#include <linux/of_irq.h>

#include "rdr_hisi_isp.h"
#include "../rdr_print.h"
#include "../rdr_inner.h"
#include "../rdr_field.h"

#include <soc_acpu_baseaddr_interface.h>
#include <soc_isp_watchdog_interface.h>
#include <soc_sctrl_interface.h>
#include <soc_pctrl_interface.h>

enum RDR_ISP_SYSTEM_ERROR_TYPE {
	ISP_MODID_START = HISI_BB_MOD_ISP_START,
	ISP_WDT_TIMEOUT = 0x81fffdfe,
	ISP_SYSTEM_STATES,
	ISP_MODID_END = HISI_BB_MOD_ISP_END,
	ISP_SYSTEM_INVALID,
} rdr_isp_sys_err_t;

struct rdr_err_type {
	struct list_head node;
	enum RDR_ISP_SYSTEM_ERROR_TYPE type;
};

struct rdr_sys_err_dump_info {
	struct list_head node;
	u32 modid;
	u64 coreid;
	pfn_cb_dump_done cb;
};

struct rdr_isp_device {
    void __iomem *sctrl_addr;
    void __iomem *wdt_addr;
    void __iomem *pctrl_addr;
    void __iomem *rdr_addr;
    struct workqueue_struct *wq;
    struct work_struct err_work;
    struct work_struct dump_work;
    struct list_head err_list;
    struct list_head dump_list;
    spinlock_t err_list_lock;
    spinlock_t dump_list_lock;
    int wdt_irq;
    bool wdt_enable_flag;
    unsigned int offline_loglevel;
    unsigned int offline_rdrlevel;
    unsigned char irq[IRQ_NUM];
    int isprdr_initialized;
    u64 isprdr_addr;
    u64 core_id;
    struct rdr_register_module_result current_info;
} rdr_isp_dev;
typedef struct  _level_switch_s {
        unsigned int level;
        char enable_cmd[8];
        char disable_cmd[8];
        char info[32];
} level_switch_s;

static struct rdr_exception_info_s exc_info[] = {
	[0] = {
	       .e_modid = ISP_WDT_TIMEOUT,
	       .e_modid_end = ISP_WDT_TIMEOUT,
	       .e_process_priority = RDR_ERR,
	       .e_reboot_priority = RDR_REBOOT_WAIT,
	       .e_notify_core_mask = RDR_AP | RDR_ISP,
	       .e_reset_core_mask = RDR_AP,
	       .e_reentrant = RDR_REENTRANT_DISALLOW,
	       .e_exce_type = ISP_S_ISPWD,
	       .e_from_core = RDR_ISP,
	       .e_from_module = MODULE_NAME,
	       .e_desc = "RDR ISP WDT TIMEOUT",
	       },
};

extern char *hisp_get_comp_name(void);
int hisp_get_wdt_irq(void)
{
    struct device_node *np = NULL;
    char *name = NULL;
    int irq = 0;

    name = hisp_get_comp_name();

    np = of_find_compatible_node(NULL, NULL, name);
    if (!np) {
        pr_err("%s: of_find_compatible_node failed, %s\n", __func__, name);
        return -ENXIO;
    }

    irq = irq_of_parse_and_map(np, 0);
    if (!irq) {
        pr_err("%s: irq_of_parse_and_map failed, irq.%d\n", __func__, irq);
        return -ENXIO;
    }

    pr_info("%s: comp.%s, wdt irq.%d.\n", __func__, name, irq);
    return irq;
}

u64 get_isprdr_addr(void)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
    pr_info("%s: isprdr_addr.0x%llx, isprdr_addr.0x%x",
            __func__, dev->isprdr_addr, (unsigned int)dev->isprdr_addr);

	return dev->isprdr_addr;
}

static void rdr_system_err_dump_work(struct work_struct *work)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
	struct rdr_sys_err_dump_info *entry, *tmp;
	unsigned int sync_word;
	int timeout = 20;

	list_for_each_entry_safe(entry, tmp, &dev->dump_list, node) {
		if (ISP_WDT_TIMEOUT == entry->modid) {
			/* check sync word */
			do {
				sync_word =
				    readl(dev->rdr_addr + RDR_SYNC_WORD_OFF);
				msleep(100);
			} while (RDR_ISP_SYNC != sync_word && timeout-- > 0);
			pr_info("%s: sync_word = 0x%x, timeout = %d.\n",
				__func__, sync_word, timeout);
		}
		entry->cb(entry->modid, entry->coreid);

		spin_lock(&dev->dump_list_lock);
		list_del(&entry->node);
		spin_unlock(&dev->dump_list_lock);

		kfree(entry);
	}
}

static void rdr_isp_dump(u32 modid, u32 etype, u64 coreid,
			 char *pathname, pfn_cb_dump_done pfn_cb)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
	struct rdr_sys_err_dump_info *dump_info;
	pr_info("%s: enter.\n", __func__);

	dump_info = kzalloc(sizeof(struct rdr_sys_err_dump_info), GFP_KERNEL);
	if (!dump_info) {
		pr_err("%s: kzalloc failed.\n", __func__);
		return;
	}

	dump_info->modid = modid;
	dump_info->coreid = dev->core_id;
	dump_info->cb = pfn_cb;

	spin_lock(&dev->dump_list_lock);
	list_add_tail(&dump_info->node, &dev->dump_list);
	spin_unlock(&dev->dump_list_lock);

	queue_work(dev->wq, &dev->dump_work);
	pr_info("%s: exit.\n", __func__);
	return;
}

static void rdr_isp_reset(u32 modid, u32 etype, u64 coreid)
{
	pr_info("%s: enter.\n", __func__);
	return;
}

static irqreturn_t isp_wdt_irq_handler(int irq, void *data)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
	struct rdr_err_type *err_info;
	pr_info("%s:enter.\n", __func__);

	/* disable wdt */
	writel(WDT_UNLOCK, SOC_ISP_WatchDog_WDG_LOCK_ADDR(dev->wdt_addr));
	writel(0, SOC_ISP_WatchDog_WDG_CONTROL_ADDR(dev->wdt_addr));
	writel(WDT_LOCK, SOC_ISP_WatchDog_WDG_LOCK_ADDR(dev->wdt_addr));

	/* init sync work */
	writel(0, dev->rdr_addr + RDR_SYNC_WORD_OFF);

	/* send fiq to isp_a7 */
	writel(0, SOC_PCTRL_PERI_CTRL27_ADDR(dev->pctrl_addr));
	writel(1, SOC_PCTRL_PERI_CTRL27_ADDR(dev->pctrl_addr));
	writel(0, SOC_PCTRL_PERI_CTRL27_ADDR(dev->pctrl_addr));

	err_info = kzalloc(sizeof(struct rdr_err_type), GFP_ATOMIC);
	if (!err_info) {
		pr_info("%s: kzalloc failed.\n", __func__);
		return IRQ_NONE;
	}

	err_info->type = ISP_WDT_TIMEOUT;

	spin_lock(&dev->err_list_lock);
	list_add_tail(&err_info->node, &dev->err_list);
	spin_unlock(&dev->err_list_lock);

	queue_work(dev->wq, &dev->err_work);
	pr_info("%s:exit.\n", __func__);
	return IRQ_HANDLED;
}

static void rdr_system_err_work(struct work_struct *work)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
	struct rdr_err_type *entry, *tmp;

	list_for_each_entry_safe(entry, tmp, &dev->err_list, node) {
		if (ISP_WDT_TIMEOUT == entry->type)
			rdr_system_error(entry->type, dev->wdt_irq, 0);
		else
			rdr_system_error(entry->type, 0, 0);

		spin_lock_irq(&dev->err_list_lock);
		list_del(&entry->node);
		spin_unlock_irq(&dev->err_list_lock);

		kfree(entry);
	}
}

static int rdr_isp_wdt_init(struct rdr_isp_device *dev)
{
	int ret = 0;
       int irq = 0;
	pr_info("%s: enter.\n", __func__);
	if (!dev->wdt_enable_flag) {
		pr_info("%s: isp wdt is disabled.\n", __func__);
		return 0;
	}

    irq = hisp_get_wdt_irq();
    if (irq <= 0) {
        pr_err("%s: hisp_get_wdt_irq failed, irq.0x%d\n", __func__, irq);
        return -EINVAL;
    }
    dev->wdt_irq = irq;

	ret =
	    request_irq(dev->wdt_irq, isp_wdt_irq_handler, 0, "isp wtd hanler",
			NULL);
	if (0 != ret)
		pr_err("%s: request_irq failed, irq.%d, ret.%d.\n", __func__, dev->wdt_irq, ret);

	pr_info("%s: exit.\n", __func__);
	return 0;
}

static int rdr_isp_module_register(void)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
	struct rdr_module_ops_pub module_ops;
	struct rdr_register_module_result ret_info;
	int ret = 0;

	pr_info("%s: enter.\n", __func__);
	module_ops.ops_dump = rdr_isp_dump;
	module_ops.ops_reset = rdr_isp_reset;

	dev->core_id = RDR_ISP;
	ret = rdr_register_module_ops(dev->core_id, &module_ops, &ret_info);
	if (ret != 0) {
		pr_err("%s: rdr_register_module_ops failed! return %d\n",
		       __func__, ret);
		return ret;
	}

	dev->current_info.log_addr = ret_info.log_addr;
	dev->current_info.log_len = ret_info.log_len;
	dev->current_info.nve = ret_info.nve;
	dev->isprdr_addr = ret_info.log_addr;

	pr_info("%s: log_addr = 0x%llx, log_len = 0x%x, nve = 0x%llx, isprdr_addr = 0x%llx\n",
	     __func__, ret_info.log_addr, ret_info.log_len, ret_info.nve,
	     dev->isprdr_addr);

	dev->rdr_addr = hisi_bbox_map((phys_addr_t)dev->isprdr_addr,
									dev->current_info.log_len);
	if (!dev->rdr_addr) {
		pr_err("%s: hisi_bbox_map rdr_addr failed.\n", __func__);
		return -ENOMEM;
	}

	dev->isprdr_initialized = 1;
	pr_info("%s: exit.\n", __func__);
	return 0;
}

static int rdr_isp_exception_register(struct rdr_isp_device *dev)
{
	int i, ret;

	pr_info("%s: enter.\n", __func__);
	for (i = 0; i < sizeof(exc_info) / sizeof(struct rdr_exception_info_s);
	     i++) {
		pr_info("%s: register rdr exception, i = %d, type:%d", __func__,
			i, exc_info[i].e_exce_type);

		if (exc_info[i].e_modid == ISP_WDT_TIMEOUT)
			if (!dev->wdt_enable_flag)
				continue;

		ret = rdr_register_exception(&exc_info[i]);
		if (ret != exc_info[i].e_modid_end) {
			pr_info("%s: rdr_register_exception failed, ret.%d.\n",
				__func__, ret);
			return -EINVAL;
		}
	}

	pr_info("%s: exit.\n", __func__);
	return 0;
}

static int rdr_isp_dev_map(struct rdr_isp_device *dev)
{
	unsigned int value;
	bool wdt_flag = false;

	pr_info("%s: enter.\n", __func__);
	dev->wdt_enable_flag = wdt_flag;

	dev->sctrl_addr = ioremap((phys_addr_t) SOC_ACPU_SCTRL_BASE_ADDR, SZ_4K);
	if (!dev->sctrl_addr) {
		pr_err("%s: ioremp sctrl failed.\n", __func__);
		return -ENOMEM;
	}

	value = readl(SOC_SCTRL_SCBAKDATA10_ADDR(dev->sctrl_addr));

	if (value & (1 << SC_ISP_WDT_BIT))
		wdt_flag = true;

	if (wdt_flag) {
		dev->wdt_addr = ioremap((phys_addr_t) SOC_ACPU_ISP_WDT_BASE_ADDR, SZ_4K);
		if (!dev->wdt_addr) {
			pr_err("%s: ioremp wdt failed.\n", __func__);
			goto wdt_err;
		}

		dev->pctrl_addr = ioremap((phys_addr_t) SOC_ACPU_PCTRL_BASE_ADDR, SZ_4K);
		if (!dev->pctrl_addr) {
			pr_err("%s: ioremp pctrl failed.\n", __func__);
			goto pctrl_err;
		}
	}

	dev->wdt_enable_flag = wdt_flag;
	pr_info("%s: exit.\n", __func__);
	return 0;

pctrl_err:
	iounmap(dev->wdt_addr);
wdt_err:
	iounmap(dev->sctrl_addr);

	pr_info("%s: error, exit.\n", __func__);
	return -ENOMEM;
}



int find_irq_num(char *cmp, const char *input)
{
	unsigned long data;
	int ret, len_cmp;

	len_cmp = strlen(cmp);
	ret = kstrtoul((input + len_cmp), 0, &data);
	if (ret < 0) {
		pr_err("%s: strict_strtoul failed, ret.%d\n", __func__, ret);
		return -EINVAL;
	}

	pr_info("%s: number is %d.\n", __func__, (int)data);
	return (int)data;
}

level_switch_s rdrlevel[] = {
        {
        A7ISP_RDR_USE_APCTRL, "yes", "no", "RDR Controlled by AP"}, {
        A7ISP_RDR_RESERVE_30, "enable", "disable","reserved 30"}, {
        A7ISP_RDR_RESERVE_29, "enable", "disable", "reserved 29"}, {
        A7ISP_RDR_RESERVE_28, "enable", "disable", "reserved 28"}, {
        A7ISP_RDR_RESERVE_27, "enable", "disable", "reserved 27"}, {
        A7ISP_RDR_RESERVE_26, "enable", "disable", "reserved 26"}, {
        A7ISP_RDR_RESERVE_25, "enable", "disable", "reserved 25"}, {
        A7ISP_RDR_RESERVE_24, "enable", "disable", "reserved 24"}, {
        A7ISP_RDR_RESERVE_23, "enable", "disable", "reserved 23"}, {
        A7ISP_RDR_RESERVE_22, "enable", "disable", "reserved 22"}, {
        A7ISP_RDR_RESERVE_21, "enable", "disable", "reserved 21"}, {
        A7ISP_RDR_RESERVE_20, "enable", "disable", "reserved 20"}, {
        A7ISP_RDR_RESERVE_19, "enable", "disable", "reserved 19"}, {
        A7ISP_RDR_RESERVE_18, "enable", "disable", "reserved 18"}, {
        A7ISP_RDR_RESERVE_17, "enable", "disable", "reserved 17"}, {
        A7ISP_RDR_RESERVE_16, "enable", "disable", "reserved 16"}, {
        A7ISP_RDR_RESERVE_15, "enable", "disable", "reserved 15"}, {
        A7ISP_RDR_RESERVE_14, "enable", "disable", "reserved 14"}, {
        A7ISP_RDR_RESERVE_13, "enable", "disable", "reserved 13"}, {
        A7ISP_RDR_RESERVE_12, "enable", "disable", "reserved 12"}, {
        A7ISP_RDR_RESERVE_11, "enable", "disable", "reserved 11"}, {
        A7ISP_RDR_RESERVE_10, "enable", "disable", "reserved 10"}, {
        A7ISP_RDR_RESERVE_9, "enable", "disable", "reserved 9"}, {
        A7ISP_RDR_RESERVE_8, "enable", "disable", "reserved 8"}, {
        A7ISP_RDR_RESERVE_7, "enable", "disable", "reserved 7"}, {
        A7ISP_RDR_RESERVE_6, "enable", "disable", "reserved 6"}, {
        A7ISP_RDR_LEVEL_TASK, "enable", "disable", "task switch"}, {
        A7ISP_RDR_LEVEL_IRQ, "enable", "disable", "irq"}, {
        A7ISP_RDR_LEVEL_CVDR, "enable", "disable", "cvdr"}, {
        A7ISP_RDR_LEVEL_ALGO, "enable", "disable", "algo"}, {
        A7ISP_RDR_LEVEL_LAST_WORD, "enable", "disable", "last word"}, {
        A7ISP_RDR_LEVEL_TRACE, "enable", "disable", "trace"},};
static void usage_isprdrctrl(void)
{
    int i = 0;

    pr_info("<Usage: >\n");
    for (i = 0; i < sizeof(rdrlevel) / sizeof(level_switch_s); i++) {
        if (rdrlevel[i].level == A7ISP_RDR_USE_APCTRL)
            continue;
        pr_info("echo <%s>:<%s/%s> > rdr_isp\n", rdrlevel[i].info,
        rdrlevel[i].enable_cmd, rdrlevel[i].disable_cmd);
    }
    //sirq handle
    pr_info("echo <%s>:<%s/%s> > rdr_isp\n", "sirqX",
        "enable", "disable");
    pr_info("sirqX,X[0-%d]\n",IRQ_NUM);
}
static ssize_t rdr_isp_store(struct device *pdev, struct device_attribute *attr,
                                                                        const char *buf, size_t count)
{
        int i = 0, len = 0, flag = 0;
        int irq_num;

        char *p = NULL;
        char *q = NULL;
        struct rdr_isp_device *dev = &rdr_isp_dev;
        struct rproc_shared_para *param =  rproc_get_share_para();;

        p = memchr(buf, ':', count);
        if(!p)
            return -EINVAL;
        len = p - buf;
        for (i = 0; i < sizeof(rdrlevel) / sizeof(level_switch_s);i++) {
            if (rdrlevel[i].level == A7ISP_RDR_USE_APCTRL)
                continue;

            if (!strncmp(buf, rdrlevel[i].info, len)) {
                flag = 1;
                p += 1;
                if (!strncmp(p, rdrlevel[i].enable_cmd,
                    strlen(rdrlevel[i].enable_cmd)))
                    dev->offline_rdrlevel |= rdrlevel[i].level;
                else if (!strncmp(p, rdrlevel[i].disable_cmd,
                    strlen(rdrlevel[i].disable_cmd)))
                    dev->offline_rdrlevel &= ~(rdrlevel[i].level);
                else
                    flag = 0;
                break;
            }
       }
       /*sirq should special handle  example:sirq32:disable or sirq32:enable*/
       if(!strncmp(buf,"sirq",strlen("sirq")))
       {
            flag = 0;
            p += 1;

            q = kzalloc(strlen(buf)+1, GFP_KERNEL);
            if (!q) {
                pr_err("%s: kzalloc failed.\n", __func__);
                return -EINVAL;
            }
            memcpy(q,buf,len);
            q[len] ='\0';

            irq_num=find_irq_num("sirq", q);
            kzfree(q);


            if (irq_num < 0 || irq_num > IRQ_NUM) {
                pr_err("%s: SIRQ irq number overflow.\n", __func__);
                goto EXIT;
            }

            pr_info("%s: SIRQ .%d\n", __func__, irq_num);
            if (!param) {
                pr_err("%s:rproc_get_share_para failed.\n", __func__);
                goto EXIT;
            }

            if(!strncmp(p,"enable",strlen("enable")))
            {
                flag =1 ;
                param->irq[irq_num] = 1;
                dev->irq[irq_num] = 1;
            }
            else if(!strncmp(p,"disable",strlen("disable")))
            {
                flag=1;
                param->irq[irq_num] = 0;
                dev->irq[irq_num] = 0;
            }
            else
                flag = 0;
       }
EXIT:
    if (!flag)
        usage_isprdrctrl();

    if (param != NULL) {
        param->rdr_enable_type =
            (param->rdr_enable_type & ~A7ISP_RDR_LEVEL_MASK) |
        (dev->offline_rdrlevel & A7ISP_RDR_LEVEL_MASK);
        pr_info("[%s] rdrlevel.0x%x >> online.0x%x\n", __func__,
                            dev->offline_rdrlevel, param->rdr_enable_type);
    }

    return count;

}
static ssize_t rdr_isp_show(struct device *pdev,
                                                                            struct device_attribute *attr, char *buf)
{
    struct rdr_isp_device *dev = &rdr_isp_dev;
    struct rproc_shared_para *param;
    unsigned int rdr_enable_type = 0;
    char *s = buf;
    ssize_t size;
    int i;

    param = rproc_get_share_para();
    if (param != NULL)
        rdr_enable_type = param->rdr_enable_type;

    for (i = 0; i < sizeof(rdrlevel) / sizeof(level_switch_s);
        i++) {
                s += sprintf(s, "[%s.%s] : %s\n",
                                        (param ? ((rdr_enable_type & rdrlevel[i].level)
                                        ? rdrlevel[i].enable_cmd : rdrlevel[i].disable_cmd) : "ispoffline"),
                                        ((dev->offline_rdrlevel & rdrlevel[i].
                                        level) ? rdrlevel[i].enable_cmd : rdrlevel[i].disable_cmd),
                                        rdrlevel[i].info);
    }
    /*handle  sirq */
   for(i=1;i<IRQ_NUM;i++)
   {
        s += sprintf(s, "[%s.%s] : sirq%d\n",
            (param ?((param->irq[i])
             ?"enable":"disable"):"ispoffline"),
             ((dev->irq[i])?"enable":"disable"),
             i);
   }

    size = s - buf;
    return size;
}

level_switch_s  loglevel[] = {
	{
	A7ISP_LOG_USE_APCTRL, "yes", "no", "LOG Controlled by AP"}, {
	A7ISP_LOG_TIMESTAMP_FPGAMOD, "yes", "no",
		    "LOG Timestamp syscounter Mode"}, {
	A7ISP_LOG_FORCE_UART, "enable", "disable", "uart"}, {
	A7ISP_LOG_LEVEL_WATCHDOG, "enable", "disable", "watchdog"}, {
	A7ISP_LOG_RESERVE_27, "enable", "disable", "reserved 27"}, {
	A7ISP_LOG_RESERVE_26, "enable", "disable", "reserved 26"}, {
	A7ISP_LOG_RESERVE_25, "enable", "disable", "reserved 25"}, {
	A7ISP_LOG_RESERVE_24, "enable", "disable", "reserved 24"}, {
	A7ISP_LOG_RESERVE_23, "enable", "disable", "reserved 23"}, {
	A7ISP_LOG_RESERVE_22, "enable", "disable", "reserved 22"}, {
	A7ISP_LOG_RESERVE_21, "enable", "disable", "reserved 21"}, {
	A7ISP_LOG_RESERVE_20, "enable", "disable", "reserved 20"}, {
	A7ISP_LOG_RESERVE_19, "enable", "disable", "reserved 19"}, {
	A7ISP_LOG_RESERVE_18, "enable", "disable", "reserved 18"}, {
	A7ISP_LOG_RESERVE_17, "enable", "disable", "reserved 17"}, {
	A7ISP_LOG_RESERVE_16, "enable", "disable", "reserved 16"}, {
	A7ISP_LOG_RESERVE_15, "enable", "disable", "reserved 15"}, {
	A7ISP_LOG_RESERVE_14, "enable", "disable", "reserved 14"}, {
	A7ISP_LOG_RESERVE_13, "enable", "disable", "reserved 13"}, {
	A7ISP_LOG_RESERVE_12, "enable", "disable", "reserved 12"}, {
	A7ISP_LOG_RESERVE_11, "enable", "disable", "reserved 11"}, {
	A7ISP_LOG_RESERVE_10, "enable", "disable", "reserved 10"}, {
	A7ISP_LOG_RESERVE_09, "enable", "disable", "reserved 9"}, {
	A7ISP_LOG_RESERVE_08, "enable", "disable", "reserved 8"}, {
	A7ISP_LOG_LEVEL_DEBUG_ALGO, "enable", "disable", "algodebug"}, {
	A7ISP_LOG_LEVEL_ERR_ALGO, "enable", "disable", "algoerr"}, {
	A7ISP_LOG_LEVEL_TRACE, "enable", "disable", "trace"}, {
	A7ISP_LOG_LEVEL_DUMP, "enable", "disable", "dump"}, {
	A7ISP_LOG_LEVEL_DBG, "enable", "disable", "dbg"}, {
	A7ISP_LOG_LEVEL_INFO, "enable", "disable", "info"}, {
	A7ISP_LOG_LEVEL_WARN, "enable", "disable", "warn"}, {
	A7ISP_LOG_LEVEL_ERR, "enable", "disable", "err"},};

void isp_loglevel_init(struct rproc_shared_para *param)
{
    struct rdr_isp_device *dev = &rdr_isp_dev;

    param->logx_switch = (param->logx_switch & ~A7ISP_LOG_LEVEL_MASK) |
                                    (dev->offline_loglevel & A7ISP_LOG_LEVEL_MASK);
    param->rdr_enable_type = (param->rdr_enable_type & ~A7ISP_RDR_LEVEL_MASK) |
                                    (dev->offline_rdrlevel & A7ISP_RDR_LEVEL_MASK);
    pr_info("[%s] 0x%x = 0x%x\n", __func__, param->logx_switch,
    dev->offline_loglevel);
}

static ssize_t isplogctrl_show(struct device *pdev,
			       struct device_attribute *attr, char *buf)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
	struct rproc_shared_para *param;
	unsigned int logx_switch = 0;
	char *s = buf;
	ssize_t size;
	int i;

	param = rproc_get_share_para();
	if (param != NULL)
		logx_switch = param->logx_switch;

	for (i = 0; i < sizeof(loglevel) / sizeof(level_switch_s);
	     i++) {
		s += sprintf(s, "[%s.%s] : %s\n",
			     (param ? ((logx_switch & loglevel[i].level)
			     ? loglevel[i].enable_cmd : loglevel[i].disable_cmd) : "ispoffline"),
			     ((dev->offline_loglevel & loglevel[i].
			      level) ? loglevel[i].enable_cmd : loglevel[i].disable_cmd),
			     loglevel[i].info);
	}

	size = s - buf;
	return size;
}

static void usage_isplogctrl(void)
{
	int i = 0;

	pr_info("<Usage: >\n");
	for (i = 0; i < sizeof(loglevel) / sizeof(level_switch_s); i++) {
		if (loglevel[i].level == A7ISP_LOG_USE_APCTRL
		    || loglevel[i].level == A7ISP_LOG_TIMESTAMP_FPGAMOD)
			continue;
		pr_info("echo <%s>:<%s/%s> > isplogctrl\n", loglevel[i].info,
		       loglevel[i].enable_cmd, loglevel[i].disable_cmd);
	}
}

static ssize_t isplogctrl_store(struct device *pdev,
				struct device_attribute *attr, const char *buf,
				size_t count)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;
	struct rproc_shared_para *param;
	int i = 0, len = 0, flag = 0;
	char *p = NULL;

	p = memchr(buf, ':', count);
    if(!p)
         return -EINVAL;
    len = p - buf;
	for (i = 0; i < sizeof(loglevel) / sizeof(level_switch_s);
	     i++) {
		if (loglevel[i].level == A7ISP_LOG_USE_APCTRL
		    || loglevel[i].level == A7ISP_LOG_TIMESTAMP_FPGAMOD)
			continue;
		if (!strncmp(buf, loglevel[i].info, len)) {
			flag = 1;
			p += 1;
			if (!strncmp(p, loglevel[i].enable_cmd,
				strlen(loglevel[i].enable_cmd)))
				dev->offline_loglevel |= loglevel[i].level;
			else if (!strncmp(p, loglevel[i].disable_cmd,
				  strlen(loglevel[i].disable_cmd)))
				dev->offline_loglevel &= ~(loglevel[i].level);
			else
				flag = 0;
			break;
		}
	}

	if (!flag)
		usage_isplogctrl();

	param = rproc_get_share_para();
	if (param != NULL) {
		param->logx_switch =
		    (param->logx_switch & ~A7ISP_LOG_LEVEL_MASK) |
		    (dev->offline_loglevel & A7ISP_LOG_LEVEL_MASK);
		pr_info("[%s] loglevel.0x%x >> online.0x%x\n", __func__,
			dev->offline_loglevel, param->logx_switch);
	}

	return count;
}

static DEVICE_ATTR(rdr_isp, (S_IRUGO | S_IWUSR | S_IWGRP), rdr_isp_show,
		   rdr_isp_store);
static DEVICE_ATTR(isplogctrl, (S_IRUGO | S_IWUSR | S_IWGRP), isplogctrl_show,
		   isplogctrl_store);

static struct miscdevice isp_rdr_miscdev = {
	.minor = 255,
	.name = "isp_rdr_miscdev",
};

static void rdr_isp_dev_unmap(struct rdr_isp_device *dev)
{
	iounmap(dev->sctrl_addr);

	if (dev->wdt_enable_flag) {
		iounmap(dev->wdt_addr);
		iounmap(dev->pctrl_addr);
	}

	return;
}

int __init rdr_isp_init(void)
{
        struct rdr_isp_device *dev = &rdr_isp_dev;
        int ret = 0;
        int i;

        pr_info("[%s] +\n", __func__);
        ret = rdr_isp_dev_map(dev);
        if (0 != ret) {
            pr_err("%s: rdr_isp_dev_map failed.\n", __func__);
            return ret;
        }

        ret = rdr_isp_wdt_init(dev);
        if (0 != ret) {
            pr_err("%s: rdr_isp_wdt_init failed.\n", __func__);
            return ret;
        }

        ret = rdr_isp_module_register();
        if (0 != ret) {
            pr_err("%s: rdr_isp_module_register failed.\n", __func__);
            return ret;
        }

        ret = rdr_isp_exception_register(dev);
        if (0 != ret) {
            pr_err("%s: rdr_isp_exception_register failed.\n", __func__);
            return ret;
        }

        dev->wq = create_singlethread_workqueue(MODULE_NAME);
        if (!dev->wq) {
            pr_err("%s: create_singlethread_workqueue failed.\n", __func__);
            return -1;
        }

        INIT_WORK(&dev->dump_work, rdr_system_err_dump_work);
        INIT_WORK(&dev->err_work, rdr_system_err_work);
        INIT_LIST_HEAD(&dev->err_list);
        INIT_LIST_HEAD(&dev->dump_list);

        spin_lock_init(&dev->err_list_lock);
        spin_lock_init(&dev->dump_list_lock);

        ret = misc_register(&isp_rdr_miscdev);
        if (0 != ret) {
            pr_err("%s: misc_register failed, ret.%d.\n", __func__, ret);
            return ret;
        }

        ret = device_create_file(isp_rdr_miscdev.this_device, &dev_attr_rdr_isp);
        if (0 != ret) {
            pr_err("%s: Faield : isprdr device_create_file.%d\n",
                __func__, ret);
            return ret;
        }

        ret = device_create_file(isp_rdr_miscdev.this_device,
                                        &dev_attr_isplogctrl);
        if (0 != ret) {
            pr_err("%s: Faield : isplog device_create_file.%d\n", __func__,
                   ret);
            return ret;
        }
        dev->offline_loglevel = A7ISP_DEFAULT_LOG_LEVEL;
        dev->offline_rdrlevel = A7ISP_DEFAULT_RDR_LEVEL;
        for(i=0;i<IRQ_NUM;i++)
            dev->irq[i]=0;


        pr_info("[%s] -\n", __func__);

        return ret;
}

subsys_initcall(rdr_isp_init);

static void __exit rdr_isp_exit(void)
{
	struct rdr_isp_device *dev = &rdr_isp_dev;

	rdr_isp_dev_unmap(dev);
	destroy_workqueue(dev->wq);
	misc_deregister(&isp_rdr_miscdev);

	return;
}

module_exit(rdr_isp_exit);

MODULE_LICENSE("GPL v2");
