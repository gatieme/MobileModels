/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*lint --e{528,537,715} */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/platform_device.h>
#include <linux/proc_fs.h>
#include <linux/version.h>
#include <osl_spinlock.h>
#include <osl_sem.h>
#include "mdrv_errno.h"
#include <bsp_om_enum.h>
#include <bsp_reset.h>
#include <bsp_dump.h>
#include <bsp_onoff.h>
#include <bsp_slice.h>
#include <linux/ctype.h>
#include "bsp_llt.h"
#include <securec.h>
#include <bsp_print.h>
#include "bsp_modem_boot.h"
#define THIS_MODU mod_onoff
struct modem_power_plat_data {
    u32 modem_state;
};

#define MODEM_STATE_FILE_NAME "modemstatus"
#define MODEM_STATE_FILE_PERMISSION 0440

static struct modem_power_plat_data *g_modem_power_data = NULL;
static const char *g_modem_state_str[] = {
    "MODEM_STATE_OFF\n",
    "MODEM_STATE_READY\n",
    "MODEM_STATE_INIT_OK\n",
    "MODEM_STATE_INVALID\n",
};

LIST_HEAD(g_modem_boot_notifier_list);

/*
the following files need to be modified at the same time when modify MODEM_ID_MAX
*             : /ccore/drivers/onoff/bsp_onoff.c
*/
#define MODEM_ID_MAX 32
static struct modem_power_plat_data g_modem_power_state[MODEM_ID_MAX];

osl_sem_id g_modem_status_sem;

void bsp_drv_set_modem_state(unsigned int modem_id, unsigned int state)
{
    if (modem_id >= MODEM_ID_MAX || state >= MODEM_INVALID) {
        bsp_err("Modem power %s:args error,modem_id = %d, state = %d\n", __FUNCTION__, modem_id, state);
        return;
    }

    if (g_modem_power_data == NULL) {
        bsp_err("Modem power %s:%d not init.\n", __FUNCTION__, __LINE__);
        return;
    }

    osl_sem_down(&g_modem_status_sem);
    g_modem_power_data->modem_state = state;
    g_modem_power_state[modem_id].modem_state = state;
    osl_sem_up(&g_modem_status_sem);

    if (g_modem_power_state[modem_id].modem_state == MODEM_READY) {
        bsp_err("Modem power set modem%d state %d ,time slice %d\n", modem_id, state, bsp_get_elapse_ms());
    } else {
        bsp_err("Modem power set modem%d state %d\n", modem_id, state);
    }
    return;
}

/*
 * 功能描述: 提供ttf设置modem状态的API
 */
int mdrv_set_modem_state(unsigned int state)
{
    if (g_modem_power_data == NULL) {
        bsp_err("Modem power %s:%d not init.\n", __FUNCTION__, __LINE__);
        return -EINVAL;
    }
    if (state >= MODEM_INVALID) {
        bsp_err("Modem power %s:%d invalid state 0x%x.\n", __FUNCTION__, __LINE__, state);
        return -EINVAL;
    }

    osl_sem_down(&g_modem_status_sem);
    g_modem_power_data->modem_state = state;
    osl_sem_up(&g_modem_status_sem);

    if (g_modem_power_data->modem_state == MODEM_READY) {
        bsp_err("Modem power set state %d ,time slice %d\n", state, bsp_get_elapse_ms());
    } else {
        bsp_err("Modem power set state %d\n", state);
    }

    return 0;
}

ssize_t modem_power_get(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned int state;

    if (g_modem_power_data == NULL) {
        bsp_err("Modem power %s:%d not init.\n", __FUNCTION__, __LINE__);
        return 0;
    }
    if (g_modem_power_data->modem_state >= MODEM_INVALID) {
        bsp_err("Modem power : %s:%d Invalid state 0x%x now is set.\n", __FUNCTION__, __LINE__,
            g_modem_power_data->modem_state);
        return 0;
    }

    osl_sem_down(&g_modem_status_sem);
    state = g_modem_power_data->modem_state;
    osl_sem_up(&g_modem_status_sem);

    ret = strncpy_s(buf, PAGE_SIZE, g_modem_state_str[state], strlen(g_modem_state_str[state]));
    if (ret != EOK) {
        bsp_err("Modem power %s:strncpy_s fail.\n", __FUNCTION__);
        return -1;
    }

    return strlen(g_modem_state_str[state]);
}
EXPORT_SYMBOL_GPL(modem_power_get);

#ifndef BSP_CONFIG_PHONE_TYPE
struct modem_boot_mode {
    enum boot_mode_e boot_mode;
    char *string;
};

static struct modem_boot_mode g_modem_boot_mode[] = {
    {BOOT_MODE_ERROR, "error"},
    {BOOT_MODE_FMC, "fmc"},
    {BOOT_MODE_EMMC0, "emmc"},
    {BOOT_MODE_FMC_DOUBLEBOOT, "fmc_doubleboot"},
    {BOOT_MODE_AP_PCIE, "pcie"},
    {BOOT_MODE_AP_UART, "uart"},
    {BOOT_MODE_AP_PCIE1, "pcie1"},
    {BOOT_MODE_FMC_PAD, "fmc_pad"}
};

ssize_t modem_boot_mode_get(struct device *dev, struct device_attribute *attr, char *buf)
{
    unsigned int i;
    int ret;
    enum boot_mode_e boot_mode = bsp_boot_mode_get();

    for (i = 0; i < sizeof(g_modem_boot_mode) / sizeof(struct modem_boot_mode); i++) {
        if (g_modem_boot_mode[i].boot_mode != boot_mode) {
            continue;
        }
        ret = strcpy_s(buf, PAGE_SIZE, g_modem_boot_mode[i].string);
        if (ret != EOK) {
            bsp_err("Modem power %s:strcpy_s fail.\n", __FUNCTION__);
            return -1;
        }
        return strlen(g_modem_boot_mode[i].string);
    }

    bsp_err("Modem power %s:bsp_boot_mode_get error, boot_mode = %d.\n", __FUNCTION__, boot_mode);
    return -1;
}

#else
ssize_t modem_boot_mode_get(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    char *stub_string = "not support";
    ret = strcpy_s(buf, PAGE_SIZE, stub_string);
    if (ret != EOK) {
        bsp_err("Modem power %s:strcpy_s fail.\n", __FUNCTION__);
        return -1;
    }
    return strlen(stub_string);
}
#endif
EXPORT_SYMBOL_GPL(modem_boot_mode_get);

ssize_t modem_state_write(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    return (ssize_t)count;
}
EXPORT_SYMBOL_GPL(modem_state_write);

ssize_t modem_reset_set(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    return bsp_reset_set_dev(buf, count);
}

EXPORT_SYMBOL_GPL(modem_reset_set);
/*lint -save -e* */
static DEVICE_ATTR(modem_boot_mode, 0440, modem_boot_mode_get, NULL);
static DEVICE_ATTR(state, 0660, modem_power_get, modem_reset_set);
static DEVICE_ATTR(modem_state, 0660, modem_power_get, modem_state_write); /*lint -restore */


/*
 * Read function of virtual file.
 * @filp: file handle
 * @user_buf : the user space buffer to write to
 * @count: the size of the user space buffer
 * @ppos: the current position in the buffer
 *
 * On success, the number of bytes read is returned, or negative value is
 * returned on error.
 */
ssize_t modem_status_read(struct file *file, char __user *user_buf, size_t count, loff_t *ppos)
{
    unsigned int modem_id;
    unsigned char modem_state[MODEM_ID_MAX] = {0};
    ssize_t ret;

    if (*ppos > 0) {
        return 0;
    }

    if (count >= MODEM_ID_MAX) {
        bsp_err("count %d is larger than %d", (int)count, MODEM_ID_MAX);
        count = MODEM_ID_MAX;
    }

    osl_sem_down(&g_modem_status_sem);
    for (modem_id = 0; modem_id < MODEM_ID_MAX; modem_id++) {
        if (g_modem_power_state[modem_id].modem_state != MODEM_READY) {
            modem_state[modem_id] = (unsigned char)MODEM_NOT_READY;
        } else {
            modem_state[modem_id] = (unsigned char)MODEM_READY;
        }
    }
    osl_sem_up(&g_modem_status_sem);

    ret = simple_read_from_buffer(user_buf, count, ppos, modem_state, count);
    if (ret < 0) {
        bsp_err("read state error, return:%d\n", (int)ret);
    }

    return ret;
}
EXPORT_SYMBOL(modem_status_read);

int bsp_sysboot_notifier_register(modem_sysboot_notifier_s *modem_sysboot_notifier)
{
    modem_sysboot_notifier_s *sysboot_notifier = NULL;

    if (modem_sysboot_notifier == NULL || modem_sysboot_notifier->func == NULL) {
        bsp_err("error arg\n");
        return -1;
    }

    list_for_each_entry(sysboot_notifier, &g_modem_boot_notifier_list, list) {
        if (sysboot_notifier == modem_sysboot_notifier) {
            bsp_err("had registered\n");
            return -1;
        }
    }

    list_add(&modem_sysboot_notifier->list, &g_modem_boot_notifier_list);
    return 0;
}

void sysboot_notifier_process(sysboot_stage_e state)
{
    modem_sysboot_notifier_s *sysboot_notifier = NULL;
    list_for_each_entry(sysboot_notifier, &g_modem_boot_notifier_list, list) {
        if (sysboot_notifier->func) {
            sysboot_notifier->func(state);
        }
    }
}

static const struct proc_ops g_modem_status_file_ops = {
    .proc_read = modem_status_read,
};

static int bsp_modem_status_file_init(void)
{
    struct proc_dir_entry *proc_entry = NULL;

    proc_entry = proc_create(MODEM_STATE_FILE_NAME, MODEM_STATE_FILE_PERMISSION, NULL, &g_modem_status_file_ops);
    if (proc_entry == NULL) {
        return -ENOMEM;
    }
    return 0;
}

int onoff_modem_reset_cb(drv_reset_cb_moment_e param, int user_data)
{
    if (param == MDRV_RESET_CB_BEFORE) {
        unsigned int modem_id;

        if (g_modem_power_data == NULL) {
            bsp_err("Modem power %s:%d not init.\n", __FUNCTION__, __LINE__);
            return -EINVAL;
        }

        osl_sem_down(&g_modem_status_sem);
        g_modem_power_data->modem_state = MODEM_NOT_READY;
        for (modem_id = 0; modem_id < MODEM_ID_MAX; modem_id++) {
            g_modem_power_state[modem_id].modem_state = MODEM_NOT_READY;
        }
        osl_sem_up(&g_modem_status_sem);
    }

    return 0;
}

EXPORT_SYMBOL_GPL(onoff_modem_reset_cb);

static int bsp_power_probe(struct platform_device *pdev)
{
    u32 ret;

    g_modem_power_data = pdev->dev.platform_data;

    ret = (u32)device_create_file(&(pdev->dev), &dev_attr_state);
    ret |= (u32)device_create_file(&(pdev->dev), &dev_attr_modem_state);
    ret |= (u32)device_create_file(&(pdev->dev), &dev_attr_modem_boot_mode);
    if (ret) {
        bsp_err("fail to create modem boot sysfs\n");
        return ret;
    }

    ret = (u32)bsp_modem_status_file_init();
    if (ret) {
        bsp_err("fail to create modem boot proc file\n");
    }

    ret = (u32)bsp_reset_cb_func_register("ONOFF", onoff_modem_reset_cb, 0, DRV_RESET_CB_PIOR_ALL);
    if (ret) {
        bsp_err(" register cp reset cb failed, ret = 0x%x\n", ret);
    }

    return (int)ret;
}

static struct modem_power_plat_data g_modem_power_plat_data = {
    .modem_state = MODEM_NOT_READY,
};

static struct platform_device g_modem_power_device = {
    .name = "modem_power",
    .id = -1,
    .dev = {
        .platform_data = &g_modem_power_plat_data,
    }, /* lint !e785 */
}; /* lint !e785 */

static struct platform_driver g_modem_power_drv = {
    .probe      = bsp_power_probe,
    .driver     = {
        .name     = "modem_power",
        .owner    = THIS_MODULE, /* lint !e64 */
        .probe_type = PROBE_FORCE_SYNCHRONOUS,
    }, /* lint !e785 */
}; /* lint !e785 */

int bsp_modem_boot_init(void)
{
    int ret;

    ret = platform_device_register(&g_modem_power_device);
    if (ret) {
        bsp_err("register modem boot device failed.\n");
        return ret;
    }
    osl_sem_init(1, &g_modem_status_sem);

    ret = platform_driver_register(&g_modem_power_drv); /*lint !e64*/
    if (ret) {
        bsp_err("register modem boot driver failed.\n");
        platform_device_unregister(&g_modem_power_device);
    }

    return ret;
}

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(bsp_modem_boot_init);
#endif
