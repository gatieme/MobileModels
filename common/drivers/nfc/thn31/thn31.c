/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 */
/*
 * Copyright (c) 2013 NXP Semiconductors N.V.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/irq.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/interrupt.h>

#include <linux/gpio.h>
#include <linux/spinlock.h>
#include <linux/of_gpio.h>
#include <linux/clk.h>
#include <linux/platform_device.h>
#include <linux/of_platform.h>
#include <linux/of_device.h>

#include <linux/regulator/consumer.h>
#include <linux/miscdevice.h>

#include <linux/io.h>
#include <linux/err.h>
#include <linux/time.h>
#include <linux/timekeeping.h>
#include <linux/spinlock_types.h>
#include <linux/kthread.h>
#include <linux/reboot.h>
#include <linux/pwm.h>
#include <linux/arm-smccc.h>
#include "securec.h"
#include "thn31.h"
#include "../nfc_kernel_common/nfc_kernel_common.h"

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <hwmanufac/dev_detect/dev_detect.h>
#endif

#ifdef CONFIG_HUAWEI_DSM
#include <dsm/dsm_pub.h>
#include <linux/errno.h>
#endif
#define NFC_TRY_NUM 3
#define UICC_SUPPORT_CARD_EMULATION (1 << 0)
#define eSE_SUPPORT_CARD_EMULATION (1 << 1)
#define UICC_2_SUPPORT_CARD_EMULATION (1 << 2)
#define CARD_UNKNOWN 0
#define CARD1_SELECT 1
#define CARD2_SELECT 2
#define UICC_CARD2_SELECT 3
#define MAX_ATTRIBUTE_BUFFER_SIZE 128
#define ENABLE_START 0
#define ENABLE_END 1
#define MAX_CONFIG_NAME_SIZE 64
#define MAX_NFC_CHIP_TYPE_SIZE 32
#define MAX_BUFFER_SIZE 512
#define SIGNAL_INTERRUPT_WAIT (-512)
#define NFC_MAX_IRQ_COUNT 10
#define NFC_PINCTRL_STATE_ACTIVE "nfc_active"
#define NFC_PINCTRL_STATE_SUSPEND "nfc_suspend"
#define NCI_HEADER 3
#define HCI_HEADER 1
#define HEADER_LEN (NCI_HEADER + HCI_HEADER)
#define DATA_LENGTH 4
#define INDEX_0_ID 0
#define INDEX_1_CR 1
#define INDEX_2_LEN 2
#define INDEX_3_HCI 3
#define CMD_LEN 6
#define WAKEUP_SRC_TIMEOUT 2000
#define T1_HEAD 0x5A
#define I2C_ELAPSE_TIMEOUT (1500 * 1000 * 1000L)
#define MAX_I2C_WAKEUP_TIME 6
#define I2C_WAKEUP_SLEEP_TIME1 5000
#define I2C_WAKEUP_SLEEP_TIME2 5100

/* #ifdef TMS_NFC */
static size_t last_count = 0;
/* #endif */

struct thn31_dev {
    wait_queue_head_t read_wq;
    struct mutex read_mutex;
    struct mutex irq_wake_mutex;
    struct device *dev;
    struct i2c_client *client;
    struct miscdevice thn31_device;
    struct clk *nfc_clk;
    struct pinctrl *thn31_pinctrl;
    struct pinctrl_state *pinctrl_state_srclkenai;
    struct pinctrl_state *pinctrl_state_esespics;
    struct pinctrl_state *pinctrl_state_esespiclk;
    struct pinctrl_state *pinctrl_state_esespimo;
    struct pinctrl_state *pinctrl_state_esespimi;
    struct pinctrl_state *pinctrl_state_esepwrreq;
    unsigned int sim_status;
    unsigned int sim_switch;
    unsigned int enable_status;
    int ven_gpio;
    int firm_gpio;
    int irq_gpio;
    int clk_req_gpio;
    int rf_gpio;
    bool irq_enabled;
    bool irq_wake_enabled;
    spinlock_t irq_enabled_lock;
    struct wakeup_source *wl;
    bool cancel_read;
    bool release_read;
};
static struct thn31_dev *nfcdev = NULL;
static ktime_t g_pre_write_time;

#ifdef CONFIG_HUAWEI_DSM
static struct dsm_dev dsm_nfc = {
    .name = "dsm_nfc",
    .device_name = NULL,
    .ic_name = NULL,
    .module_name = NULL,
    .fops = NULL,
    .buff_size = 1024,    // 1k buffer
};
#endif

/*
 * FUNCTION: thn31_disable_irq_wake
 * DESCRIPTION: disable irq wakeup function
 * Parameters
 * struct  thn31_dev *: device structure
 * RETURN VALUE
 * none
 */
static void thn31_disable_irq_wake(struct thn31_dev *thn31_dev)
{
    int ret;

    mutex_lock(&thn31_dev->irq_wake_mutex);
    if (thn31_dev->irq_wake_enabled) {
        thn31_dev->irq_wake_enabled = false;
        ret = irq_set_irq_wake(thn31_dev->client->irq, 0);
        if (ret) {
            pr_err("%s failed: ret=%d\n", __func__, ret);
        }
    }
    mutex_unlock(&thn31_dev->irq_wake_mutex);
}


/*
 * FUNCTION: thn31_enable_irq_wake
 * DESCRIPTION: enable irq wakeup function
 * Parameters
 * struct  thn31_dev *: device structure
 * RETURN VALUE
 * none
 */
static void thn31_enable_irq_wake(struct thn31_dev *thn31_dev)
{
    int ret;

    mutex_lock(&thn31_dev->irq_wake_mutex);
    if (!thn31_dev->irq_wake_enabled) {
        thn31_dev->irq_wake_enabled = true;
        ret = irq_set_irq_wake(thn31_dev->client->irq, 1);
        if (ret) {
            pr_err("%s failed: ret=%d\n", __func__, ret);
        }
    }
    mutex_unlock(&thn31_dev->irq_wake_mutex);
}

/* FUNCTION: thn31_enable_nfc
 * DESCRIPTION: reset cmd sequence to enable thn31
 * Parameters
 * struct  thn31_dev *pdev: device structure
 * RETURN VALUE
 * none
 */
static void thn31_enable_nfc(struct thn31_dev *pdev)
{
    /* hardware reset, power on */
    mdelay(20);    // sleep 20ms
    gpio_set_value(pdev->ven_gpio, 1);
    mdelay(20);    // sleep 20ms

    /* power off */
    gpio_set_value(pdev->ven_gpio, 0);
    mdelay(20);    // sleep 20ms

    /* power on */
    gpio_set_value(pdev->ven_gpio, 1);
    mdelay(20);    // sleep 20ms

    return;
}

/* FUNCTION: thn31_disable_irq
 * DESCRIPTION: disable irq function
 * Parameters
 * struct  thn31_dev *: device structure
 * RETURN VALUE
 * none
 */
static void thn31_disable_irq(struct thn31_dev *thn31_dev)
{
    unsigned long flags;

    spin_lock_irqsave(&thn31_dev->irq_enabled_lock, flags);
    if (thn31_dev->irq_enabled) {
        disable_irq_nosync(thn31_dev->client->irq);
        thn31_dev->irq_enabled = false;
    }
    spin_unlock_irqrestore(&thn31_dev->irq_enabled_lock, flags);
}

/* FUNCTION: thn31_enable_irq
 * DESCRIPTION: enable irq function
 * Parameters
 * struct  thn31_dev *: device structure
 * RETURN VALUE
 * none
 */
static void thn31_enable_irq(struct thn31_dev *thn31_dev)
{
    unsigned long flags;

    spin_lock_irqsave(&thn31_dev->irq_enabled_lock, flags);
    if (!thn31_dev->irq_enabled) {
        thn31_dev->irq_enabled = true;
        enable_irq(thn31_dev->client->irq);
    }
    spin_unlock_irqrestore(&thn31_dev->irq_enabled_lock, flags);
}

/* FUNCTION: thn31_dev_irq_handler
 * DESCRIPTION: irq handler, jump here when receive an irq request from NFC chip
 * Parameters
 * int irq: irq number
 * void *dev_id:device structure
 * RETURN VALUE
 * irqreturn_t: irq handle result
 */
static irqreturn_t thn31_dev_irq_handler(int irq, void *dev_id)
{
    struct thn31_dev *thn31_dev = dev_id;

    pr_err("%s: enter\n", __func__);
    if (gpio_get_value(thn31_dev->irq_gpio) != 1) {
        pr_err("%s: exit, irq_gpio is not high\n", __func__);
        return IRQ_HANDLED;
    }

    if (device_may_wakeup(&thn31_dev->client->dev))
        pm_wakeup_event(&thn31_dev->client->dev, WAKEUP_SRC_TIMEOUT);

    thn31_disable_irq(thn31_dev);
    wake_up(&thn31_dev->read_wq);
    pr_err("%s: exit\n", __func__);

    return IRQ_HANDLED;
}

static uint16_t thn31_nfc_check_number(const char *string, uint16_t len)
{
    uint16_t i;
    if (string == NULL)
        return 0;
    for (i = 0; i < len; i++) {
        if (string[i] > '9' || string[i] < '0')     // '9' & '0' means char must between 1-9
            return 0;
    }
    return 1;  // 1 means success
}

/* FUNCTION: thn31_dev_read
 * DESCRIPTION: read i2c data
 * Parameters
 * struct file *filp:device structure
 * char __user *buf:return to user buffer
 * size_t count:read data count
 * loff_t *offset:offset
 * RETURN VALUE
 * ssize_t: result
 */
static ssize_t thn31_dev_read(struct file *filp, char __user *buf,
                              size_t count, loff_t *offset)
{
    struct thn31_dev *thn31_dev = filp->private_data;
    char tmp[MAX_BUFFER_SIZE] = {0};
    char *tmpStr = NULL;
    int err = -1;
    int ret = -1;
    int i;
    int retry = 0;
    /* #ifdef TMS_NFC */
    bool need2byte = false;
    /* #endif */

    /* max size is 512 */
    bool isSuccess = false;
    uint16_t buffer_count;
    uint16_t tmp_length;
    /* 2 means ascii length of char, 1 means '\0' */

    if (count > MAX_BUFFER_SIZE) {
        count = MAX_BUFFER_SIZE;
    }

    mutex_lock(&thn31_dev->read_mutex);

    /* read data when interrupt occur */
    if (!gpio_get_value(thn31_dev->irq_gpio)) {
        if (filp->f_flags & O_NONBLOCK) {
            ret = -EAGAIN;
            pr_err("%s : EAGAIN,%d\n", __func__, ret);
            goto fail;
        }

        for (i = 0; i < NFC_MAX_IRQ_COUNT; i++) {
            thn31_enable_irq(thn31_dev);
            pr_info("%s: common wait ireq\n", __func__);
            ret = wait_event_interruptible(
                thn31_dev->read_wq,
                !thn31_dev->irq_enabled);
            pr_info("%s: common ireq received\n", __func__);

            if (ret) {
                pr_err("%s : ret %d goto fail\n", __func__, ret);
                goto fail;
            }
            thn31_disable_irq(thn31_dev);

            if (gpio_get_value(thn31_dev->irq_gpio)) {
                break;
            }
            /*
             * NFC service wanted to close the driver so,
             * release the calling reader thread asap.
             *
             * This can happen in case of nfc node close call from
             * eSE HAL in that case the NFC HAL reader thread
             * will again call read system call
             */
            if (thn31_dev->release_read) {
                pr_info("%s: releasing read\n", __func__);
                mutex_unlock(&thn31_dev->read_mutex);
                return 0;
            }
        }
    }

    tmpStr = (char *)kzalloc(sizeof(tmp) * 2 + 1, GFP_KERNEL);
    if (!tmpStr) {
        pr_err("%s:Cannot allocate memory for read tmpStr.\n", __func__);
        ret = -ENOMEM;
        goto fail;
    }

    /* Read data, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        /* #ifdef TMS_NFC */
        if (last_count == 3 && count == 1) {
            pr_info("%s: need2byte \n", __func__);
            need2byte = true;
            count = 2;
        }
        /* #endif */
        ret = i2c_master_recv(thn31_dev->client, tmp, (int)count);
        /* #ifdef TMS_NFC */
        if (need2byte) {
            count = 1;
            --ret;
        }
        /* #endif */
        for (i = 0; i < count; i++) {
            snprintf_s(&tmpStr[i * 2], sizeof(tmp[i]) * 2 + 1, sizeof(tmp[i]) * 2 + 1, "%02X", tmp[i]);
        }

        // hide bank card number,'6'&'2' means card number head
        buffer_count = count * 2 + 1;       // 2 means ascii length of char, 1 means '\0'
        tmp_length = sizeof(tmp) * 2 + 1;  // 2 means ascii length of char, 1 means '\0'
        if (buffer_count > MIN_NCI_CMD_LEN_WITH_BANKCARD_NUM) {
            for (i = NCI_CMD_HEAD_OFFSET; i < buffer_count - BANKCARD_NUM_LEN; i += BANKCARD_NUM_HEAD_LEN) {
                if ((*(tmpStr + i) == '6') && (*(tmpStr + i + 1) == '2') &&
                    ((i + BANKCARD_NUM_OVERRIDE_OFFSET) < tmp_length) &&
                    thn31_nfc_check_number(tmpStr + i + BANKCARD_NUM_HEAD_LEN, BANKCARD_NUM_VALUE_LEN)) {
                    err = memcpy_s(tmpStr + i + BANKCARD_NUM_OVERRIDE_OFFSET, BANKCARD_NUM_OVERRIDE_LEN,
                                   "XXXXXXXX", BANKCARD_NUM_OVERRIDE_LEN);
                    if (err != EOK) {
                        pr_err("%s:memcpy_s fail, err=%d.\n", __func__, err);
                    }
                }
            }
        }
        // end
        /* hide cplc
         * 4 is start pos of 9F7F and length of 9F7F
         * 18 is length of cplc and 2 is trans byte "9F" into two char
         * 13 is length of print info and \0
         */
        if ((2 * count > 18) && (strncmp(tmpStr + 4, "9F7F", 4) == 0))
            snprintf_s(tmpStr, sizeof("xxxx9F7Fxxxx") + 1, sizeof("xxxx9F7Fxxxx") + 1, "%s", "xxxx9F7Fxxxx");
        pr_info("%s : retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);

        if (ret == (int)count) {
            isSuccess = true;
            break;
        } else {
            pr_info("%s : read data try =%d returned %d\n", __func__, retry, ret);
            msleep(1);
            continue;
        }
    }
    // 0&1 means '6105' or '000012' mifare, 2 means nci length
    if (((count >= FIRST_LINE_NCI_LEN) && (tmp[0] == 0x61) &&
        (tmp[1] == 0x05) && (tmp[2] >= 0x0A)) ||
        ((tmp[0] == 0x00) && (tmp[1] == 0x00) && (tmp[2] == 0x12)) ||
        ((tmp[0] == 0x01) && (tmp[1] == 0x02) && (tmp[2] == 0x04))) {
        set_is_uid(true);
    } else {
        set_is_uid(false);
    }
    kfree(tmpStr);
    mutex_unlock(&thn31_dev->read_mutex);

    if (ret != (int)count) {
        pr_err("%s : i2c_master_recv returned %d\n", __func__, ret);
        ret = -EIO;
    }
    if (ret < 0) {
        pr_err("%s: THN31 i2c_master_recv returned %d\n", __func__, ret);
        return ret;
    }
    if (ret > (int)count) {
        pr_err("%s: received too many bytes from i2c (%d)\n", __func__, ret);
        return -EIO;
    }
    g_pre_write_time = ktime_get_boottime();
    /* copy data to user */
    if (copy_to_user(buf, tmp, ret)) {
        pr_err("%s : failed to copy to user space\n", __func__);
        return -EFAULT;
    }
    /* #ifdef TMS_NFC */
    last_count = count;
    /* #endif */
    return ret;

fail:
    mutex_unlock(&thn31_dev->read_mutex);

    return ret;
}

static int32_t compare_active_cmd(const char *send_buf, size_t len, size_t count)
{
    int32_t active_ret = -1;
    const uint8_t active_cmd[CMD_LEN] = {
        0x80, 0xf0, 0x01, 0x01, 0x00, 0x4f
    };
    if (count <= HEADER_LEN + CMD_LEN || len < count)
        return active_ret;

    // compare 0x80F00101xx4F
    active_ret = memcmp(&send_buf[HEADER_LEN + 1], active_cmd, HEADER_LEN) ||
                 memcmp(&send_buf[HEADER_LEN + CMD_LEN],
                        &active_cmd[CMD_LEN - 1], 1);

    return active_ret;
}

/* FUNCTION: thn31_dev_write
 * DESCRIPTION: write i2c data
 * Parameters
 * struct file *filp:device structure
 * char __user *buf:user buffer to write
 * size_t count:write data count
 * loff_t *offset:offset
 * RETURN VALUE
 * ssize_t: result
 */
static ssize_t thn31_dev_write(struct file *filp, const char __user *buf,
                               size_t count, loff_t *offset)
{
    struct thn31_dev *thn31_dev = filp->private_data;
    char short_buf[HEADER_LEN + DATA_LENGTH] = {0};
    char data[MAX_BUFFER_SIZE] = {0};
    char *data_buf = NULL;
    char *send_buf = NULL;
    char *tmpStr = NULL;
    int ret = -1;
    int err = -1;
    int send_times = 1;
    int send_length = 0;
    int hci_date_length = 0;
    int retry, j;
    int data_len, remainder;
    bool is_active_cmd = false;
    bool isSuccess = false;
    char *pDataAlloc = NULL;

    char wakeup_cmd[1] = {0};
    int wakeup_len = 1;
    int retry_count = 0;
    ktime_t elapse_time = 0;
    ktime_t write_time;

    /* max size is 512 */
    if (count > MAX_BUFFER_SIZE) {
        pDataAlloc = (char *)kzalloc(count, GFP_KERNEL);
        if (NULL == pDataAlloc) {
            pr_err("%s: memory kzalloc failed\n", __func__);
            return -ENOMEM;
        }
        data_buf = pDataAlloc;
    } else {
        data_buf = data;
    }

    /* copy data from user */
    if (copy_from_user(data_buf, buf, count)) {
        if (NULL != pDataAlloc) {
            kfree(pDataAlloc);
            pDataAlloc = NULL;
        }
        pr_err("%s : failed to copy from user space\n", __func__);
        return -EFAULT;
    }
    if (data_buf[0] != T1_HEAD) {
        write_time = ktime_get_boottime();
        elapse_time = write_time - g_pre_write_time;
        // make sure elapse_time is not overflow
        if (elapse_time < 0) {
            elapse_time = I2C_ELAPSE_TIMEOUT;
        }
        g_pre_write_time = write_time;
        if (elapse_time >= I2C_ELAPSE_TIMEOUT) {
            pr_info("%s : need to send 0x00\n", __func__);
            while (++retry_count < MAX_I2C_WAKEUP_TIME) {
                ret = i2c_master_send(thn31_dev->client, wakeup_cmd, wakeup_len);
                usleep_range(I2C_WAKEUP_SLEEP_TIME1, I2C_WAKEUP_SLEEP_TIME2);
                if (ret == wakeup_len) {
                    break;
                }
            }
            if (ret < 0) {
                pr_err("%s: failed to write wakeup_cmd : %d, retry for : %d times\n", __func__, ret, retry_count);
            }
        }
    }
    if (compare_active_cmd(data_buf, MAX_BUFFER_SIZE, count) == 0) {
        pr_err("%s: active cmd count:%d\n", __func__, count);
        is_active_cmd = true;
        hci_date_length = (int)count - HEADER_LEN;
        send_times = hci_date_length / DATA_LENGTH;
        remainder = hci_date_length % DATA_LENGTH;
        if (remainder != 0) {
            send_times += 1;
        }
        // fill the first two bytes
        short_buf[INDEX_0_ID] = data_buf[INDEX_0_ID];
        short_buf[INDEX_1_CR] = data_buf[INDEX_1_CR];
    }
    for (j = 0; j < send_times; j++) {
        // need to send multi-times for specail apdu commands
        if (is_active_cmd) {
            short_buf[INDEX_3_HCI] = data_buf[INDEX_3_HCI];
            if (j != send_times - 1) {    // not last packet
                data_len = DATA_LENGTH;
                short_buf[INDEX_3_HCI] &= ~(1 << 7);  // clear bit 7
            } else {
                data_len = (remainder == 0) ?
                    DATA_LENGTH : remainder;
            }
            short_buf[INDEX_2_LEN] = HCI_HEADER + (char)data_len;
            err = memcpy_s(&short_buf[HEADER_LEN], data_len,
                           &data_buf[HEADER_LEN + DATA_LENGTH * j],
                           data_len);
            if (err != EOK) {
                pr_err("%s:memcpy_s fail, err=%d.\n", __func__, err);
            }

            send_buf = short_buf;
            send_length = HEADER_LEN + data_len;
        } else {
            send_buf = data_buf;
            send_length = count;
        }
        isSuccess = false;
        /* Send data */
        tmpStr = (char *)kzalloc(send_length * 2 + 1, GFP_KERNEL);    // strlen = hexlen * 2
        if (tmpStr == NULL) {
            if (NULL != pDataAlloc) {
                pDataAlloc = NULL;
                kfree(pDataAlloc);
            }
            pr_err("%s:Cannot allocate memory for write tmpStr.\n",
                __func__);
            return -ENOMEM;
        }
        for (retry = 0; retry < NFC_TRY_NUM; retry++) {
            ret = i2c_master_send(thn31_dev->client,
                send_buf, send_length);
            for (j = 0; j < count; j++) {
                snprintf_s(&tmpStr[j * 2], sizeof(send_buf[j]) * 2 + 1,
                           sizeof(send_buf[j]) * 2 + 1, "%02X", send_buf[j]);
            }
            pr_err("%s : retry = %d, ret = %d, expect count = %3d > %s\n",
                __func__, retry, ret, (int)send_length, tmpStr);
            if (ret == (int)send_length) {
                isSuccess = true;
                break;
            } else {
                if (retry > 0) {
                    pr_err("%s : send data retry =%d return %d\n",
                        __func__, retry, ret);
                }
                msleep(1);
                continue;
            }
        }
        kfree(tmpStr);
        tmpStr = NULL;
        if (isSuccess == false) {
            pr_err("%s : send returned %d\n", __func__, ret);
            ret = -EIO;
        }
    }

    if (NULL != pDataAlloc) {
        kfree(pDataAlloc);
        pDataAlloc = NULL;
    }
    return ret;
}

/* FUNCTION: thn31_i2c_write
 * DESCRIPTION: write i2c data, only use in check_sim_status
 * Parameters
 * struct  thn31_dev *pdev:device structure
 * const char *buf:user buffer to write
 * int count:write data count
 * RETURN VALUE
 * ssize_t: result
 */
static ssize_t thn31_i2c_write(struct thn31_dev *pdev, const char *buf, int count)
{
    int ret = -1;
    int err = -1;
    int retry = 0;
    char *tmpStr = NULL;
    int i;

    tmpStr = (char *)kzalloc(255 * 2, GFP_KERNEL);    // allco tmp 255 * 2 buffer
    if (!tmpStr) {
        pr_info("%s:Cannot allocate memory for write tmpStr.\n", __func__);
        return -ENOMEM;
    }
    /* Write data, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        ret = i2c_master_send(pdev->client, buf, (int)count);
        for (i = 0; i < count; i++) {
            // store write cmd tmpStr[i * 2], sizeof(buf[i]) * 2 + 1,
            err = snprintf_s(&tmpStr[i * 2], sizeof(buf[i]) * 2 + 1,
                             // sizeof(buf[i]) * 2 + 1
                             sizeof(buf[i]) * 2 + 1, "%02X", buf[i]);
            if (err < 0) {
                pr_err("%s:snprintf_s fail, err=%d.\n", __func__, err);
            }
        }
        pr_info("%s : retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);
        if (ret == (int)count) {
            break;
        } else {
            if (retry > 0) {
                pr_info("%s : send data try =%d returned %d\n", __func__, retry, ret);
            }
            msleep(10);    // sleep 10ms
            continue;
        }
    }
    kfree(tmpStr);
    if (ret != (int)count) {
        pr_err("%s : i2c_master_send returned %d\n", __func__, ret);
        ret = -EIO;
    }

    return (size_t)ret;
}

/* FUNCTION: thn31_i2c_read
 * DESCRIPTION: read i2c data, only use in check_sim_status
 * Parameters
 * struct  thn31_dev *pdev:device structure
 * const char *buf:read to user buffer
 * int count:read data count
 * RETURN VALUE
 * ssize_t: result
 */
static ssize_t thn31_i2c_read(struct thn31_dev *pdev, char *buf, int count)
{
    int ret = -1;
    int err = -1;
    int retry = 0;
    char *tmpStr = NULL;
    int i;
    /* #ifdef TMS_NFC */
    bool need2byte = false;
    /* #endif */

    mutex_lock(&pdev->read_mutex);
    if (!gpio_get_value(pdev->irq_gpio)) {
        /* for -ERESTARTSYS, we have 3 chances */
        for (retry = 0; retry < NFC_TRY_NUM; retry++) {
            thn31_disable_irq(pdev);
            thn31_enable_irq(pdev);

            /* wait_event_interruptible_timeout Returns:
             * 0: if the @timeout elapsed
             * -ERESTARTSYS: if it was interrupted by a signal
             * >0:the remaining jiffies (at least 1) if the @condition = true before the @timeout elapsed.*/
            ret = wait_event_interruptible_timeout(pdev->read_wq,
                  !pdev->irq_enabled, (unsigned long)msecs_to_jiffies(1000)); // 1000ms timeout
            thn31_disable_irq(pdev);
            set_wait_event_interruptible_ret(ret);
            if (ret <= 0) {
                pr_err("%s : wait retry count %d!,ret = %d\n", __func__, retry, ret);
                continue;
            }
            /*
             * NFC service wanted to close the driver so,
             * release the calling reader thread asap.
             *
             * This can happen in case of nfc node close call from
             * eSE HAL in that case the NFC HAL reader thread
             * will again call read system call
             */
            if (pdev->release_read) {
                pr_info("%s: releasing read\n", __func__);
                mutex_unlock(&pdev->read_mutex);
                return 0;
            }
            break;
        }

        if (ret <= 0) {
            pr_err("%s : wait_event_interruptible_timeout error!,ret = %d\n", __func__, ret);
            ret = -1;
            goto fail;
        }
    }

    tmpStr = (char *)kzalloc(count * 2 + 1, GFP_KERNEL);    // count of read cmd: count * 2 + 1,
    if (!tmpStr) {
        pr_err("%s:Cannot allocate memory for read tmpStr.\n", __func__);
        ret = -ENOMEM;
        goto fail;
    }

    /* Read data, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        /* #ifdef TMS_NFC */
        if (count == 1) {
            pr_info("%s: need2byte \n", __func__);
            need2byte = true;
            count = 2;    // read 2 bytes
        }
        /* #endif */
        ret = i2c_master_recv(pdev->client, buf, (int)count);
        /* #ifdef TMS_NFC */
        if (need2byte) {
            count = 1;
            --ret;
        }
        /* #endif */
        for (i = 0; i < count; i++) {
            // &tmpStr[i * 2], sizeof(buf[i]) * 2 + 1
            err = snprintf_s(&tmpStr[i * 2], sizeof(buf[i]) * 2 + 1,
                             // sizeof(buf[i]) * 2 + 1
                             sizeof(buf[i]) * 2 + 1, "%02X", buf[i]);
            if (err < 0) {
                pr_err("%s:snprintf_s fail, err=%d.\n", __func__, err);
            }
        }
        pr_info("%s : retry = %d, ret = %d, count = %3d > %s\n", __func__, retry, ret, (int)count, tmpStr);
        if (ret == (int)count) {
            break;
        } else {
            pr_err("%s : read data try =%d returned %d\n", __func__, retry, ret);
            msleep(10);    // sleep 10ms
            continue;
        }
    }
    kfree(tmpStr);
    mutex_unlock(&pdev->read_mutex);

    if (ret != (int)count) {
        pr_err("%s : i2c_master_recv returned %d\n", __func__, ret);
        ret = -EIO;
    }
    return (ssize_t)ret;

fail:
    mutex_unlock(&pdev->read_mutex);
    return (ssize_t)ret;
}

/* FUNCTION: check_sim_status
 * DESCRIPTION: To test if the SWP interfaces are operational between the NFCC and the connected NFCEEs.
 *    Test sequence:
 *    1) hardware reset chip
 *    2) send CORE_RESET_CMD
 *    3) send CORE_INIT_CMD
 *    4) send NCI_PROPRIETARY_ACT_CMD
 *    5) send SYSTEM_TEST_SWP_INTERFACE_CMD(SWP1/2)
 * Parameters
 * struct i2c_client *client:i2c device structure
 * struct  thn31_dev *pdev:device structure
 * RETURN VALUE
 * int: check result
 */

static int check_sim_status(struct i2c_client *client, struct thn31_dev *pdev)
{
    int ret;
    unsigned char recvBuf[40] = {0};                           // read buffer max len 40
    const char send_reset[] = {0x20, 0x00, 0x01, 0x01};           // CORE_RESET_CMD
    const char init_cmd[] = {0x20, 0x01, 0x02, 0x00, 0x00};       // CORE_INIT_CMD
    const char read_config[] = {0x2F, 0x02, 0x00};               // SYSTEM_PROPRIETARY_ACT_CMD
    const char read_config_UICC[] = {0x2F, 0x3E, 0x01, 0x00};  // SYSTEM_TEST_SWP_INTERFACE_CMD(swp1)
    pr_info("thn31 - %s : enter\n", __func__);

    pdev->sim_status = 0;
    /* hardware reset */
    gpio_set_value(pdev->firm_gpio, 0);
    thn31_enable_nfc(pdev);

    /* write CORE_RESET_CMD */
    ret = thn31_i2c_write(pdev, send_reset, sizeof(send_reset));
    if (ret < 0) {
        pr_err("%s: CORE_RESET_CMD thn31_i2c_write failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    pr_err("%s: sleep 10ms:\n", __func__);
    /* read response */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: CORE_RESET_RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read rsp payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: CORE_RESET_RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    /* read NTF */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: CORE_RESET_NTF thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read ntf payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: CORE_RESET_NTF thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }

    udelay(500);    // delay 500us
    /* write CORE_INIT_CMD */
    ret = thn31_i2c_write(pdev, init_cmd, sizeof(init_cmd));
    if (ret < 0) {
        pr_err("%s: CORE_INIT_CMD thn31_i2c_write failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    /* read response */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: CORE_INIT_RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read rsp payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: CORE_INIT_RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }

    udelay(500);    // delay 500us
    /* write NCI_PROPRIETARY_ACT_CMD */
    ret = thn31_i2c_write(pdev, read_config, sizeof(read_config));
    if (ret < 0) {
        pr_err("%s: PRO_ACT_CMD thn31_i2c_write failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    /* read response */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: read_config RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read rsp payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: PRO_ACT_RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }

    udelay(500);    // delay 500us
    /* write TEST_SWP_CMD UICC */
    ret = thn31_i2c_write(pdev, read_config_UICC, sizeof(read_config_UICC));
    if (ret < 0) {
        pr_err("%s: TEST_UICC_CMD thn31_i2c_write failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    /* read response */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: TEST_UICC_RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read rsp payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: CORE_RESET_RSP thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }

    mdelay(10);    // sleep 10ms
    /* read notification */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: TEST_UICC_NTF thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read ntf payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: CORE_RESET_NTF thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }

    /* NTF's format: 6F 3E 02 XX1 XX2 -> "XX1 == 0" means SWP link OK "XX1 == 3" means SWP link Failed */
    if (recvBuf[0] == 0x6F && recvBuf[1] == 0x3E && recvBuf[3] == 0x00) {
        pdev->sim_status |= UICC_SUPPORT_CARD_EMULATION;
    }

    return pdev->sim_status;
failed:
    pdev->sim_status = (unsigned int)ret;
    return ret;
}

/* FUNCTION: thn31_nfc_sim_status_show
 * DESCRIPTION: get nfc-sim card support result.
 * Parameters
 *    struct device *dev:device structure
 *    struct device_attribute *attr:device attribute
 *    const char *buf:user buffer
 * RETURN VALUE
 *        eSE        UICC    value
 *        0        0        0    (not support)
 *        0        1        1    (swp1 support)
 *        1        0        2    (swp2 support)
 *        1        1        3    (all support)
 *        <0    :error
 */
static ssize_t thn31_nfc_sim_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret = -1;
    int status = -1;
    int retry = 0;
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;

    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        pr_err("%s:     thn31_dev == NULL!\n", __func__);
        return status;
    }

    pr_info("%s: enter!\n", __func__);
    /* if failed, we have 3 chances */
    for (retry = 0; retry < NFC_TRY_NUM; retry++) {
        status = check_sim_status(i2c_client_dev, thn31_dev);
        if (status < 0) {
            pr_err("%s: check_sim_status error!retry count=%d\n", __func__, retry);
            msleep(10);    // sleep 10ms
            continue;
        }
        break;
    }
    ret = snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
                     MAX_ATTRIBUTE_BUFFER_SIZE - 1, "%d\n", status);
    pr_info("%s: status=%d\n", __func__, status);
    return ret;
}

/* FUNCTION: thn31_nfc_sim_switch_store
 * DESCRIPTION: save user sim card select result.
 * Parameters
 *    struct device *dev:device structure
 *    struct device_attribute *attr:device attribute
 *    const char *buf:user buffer
 *    size_t count:data count
 * RETURN VALUE
 *    ssize_t:result
 */
static ssize_t thn31_nfc_sim_switch_store(struct device *dev, struct device_attribute *attr,
                                          const char *buf, size_t count)
{
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    int val = 0;

    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        pr_err("%s:     thn31_dev == NULL!\n", __func__);
        return 0;
    }

    /* save card select result */
    if (sscanf_s(buf, "%1d", &val) == 1) {
        pr_err("%s: input val = %d!\n", __func__, val);
        if (val == CARD1_SELECT) {
            thn31_dev->sim_switch = CARD1_SELECT;
        } else if (val == CARD2_SELECT) {
            thn31_dev->sim_switch = CARD2_SELECT;
        } else if (val == UICC_CARD2_SELECT) {
            thn31_dev->sim_switch = UICC_CARD2_SELECT;
        } else {
            return -EINVAL;
        }
    } else {
        return -EINVAL;
    }

    return (ssize_t)count;
}

/* FUNCTION: thn31_nfc_sim_switch_show
 * DESCRIPTION: get user sim card select result.
 * Parameters
 *    struct device *dev:device structure
 *    struct device_attribute *attr:device attribute
 *    const char *buf:user buffer
 * RETURN VALUE
 *    ssize_t:  result
 */
static ssize_t thn31_nfc_sim_switch_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret = -1;
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;

    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        pr_err("%s:     thn31_dev == NULL!\n", __func__);
        return 0;
    }
    ret = snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE - 1, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
                     "%u\n", thn31_dev->sim_switch);
    return ret;
}

/* FUNCTION: thn31_rd_nfc_sim_status_show
 * DESCRIPTION: get nfc-sim card support result from variate, no need to send check commands again.
 * Parameters
 *    struct device *dev:device structure
 *    struct device_attribute *attr:device attribute
 *    const char *buf:user buffer
 * RETURN VALUE
 *        eSE        UICC    value
 *        0        0        0    (not support)
 *        0        1        1    (swp1 support)
 *        1        0        2    (swp2 support)
 *        1        1        3    (all support)
 *        <0    :error
 */
static ssize_t thn31_rd_nfc_sim_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret = -1;
    int status = -1;
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        pr_err("%s:     thn31_dev == NULL!\n", __func__);
        return status;
    }
    ret = snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE - 1, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
                     "%u\n", thn31_dev->sim_status);
    return ret;
}

/* FUNCTION: thn31_nfc_enable_status_store
 * DESCRIPTION: store nfc_enable_status for RD test.
 * Parameters
 *    struct device *dev:device structure
 *    struct device_attribute *attr:device attribute
 *    const char *buf:user buffer
 *    size_t count:data count
 * RETURN VALUE
 *    ssize_t:  result
 */
static ssize_t thn31_nfc_enable_status_store(struct device *dev, struct device_attribute *attr,
                                             const char *buf, size_t count)
{
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    int val = 0;

    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        pr_err("%s:     thn31_dev == NULL!\n", __func__);
        return 0;
    }

    /* save nfc enable status */
    if (sscanf_s(buf, "%1d", &val) == 1) {
        if (val == ENABLE_START) {
            thn31_dev->enable_status = ENABLE_START;
        } else if (val == ENABLE_END) {
            thn31_dev->enable_status = ENABLE_END;
        } else {
            return -EINVAL;
        }
    } else {
        return -EINVAL;
    }

    return (ssize_t)count;
}

/* FUNCTION: thn31_nfc_enable_status_show
 * DESCRIPTION: show nfc_enable_status for RD test.
 * Parameters
 *    struct device *dev:device structure
 *    struct device_attribute *attr:device attribute
 *    const char *buf:user buffer
 * RETURN VALUE
 *    ssize_t:  result
 */
static ssize_t thn31_nfc_enable_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret = -1;
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev;
    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        pr_err("%s:thn31_dev == NULL!\n", __func__);
        return 0;
    }
    ret = snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE - 1, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
                     "%u\n", thn31_dev->enable_status);
    return ret;
}

static void thn31_set_nfc_qcom_activated(void)
{
    int ret = -1;

    ret = nfc_get_dts_config_u32("tms_nfc_qcom_activated", "tms_nfc_qcom_activated", get_g_nfc_qcom_activated());
    if (ret != 0) {
        *get_g_nfc_qcom_activated() = 1;
        pr_err("%s: can't get nfc qcom activated config!\n", __func__);
    }
    return;
}

static void thn31_nfc_write_conf_to_tee(void)
{
    struct arm_smccc_res res;
    uint32_t x1;
    uint32_t x2;
    uint32_t gpio_svdd_pwr_req = (uint32_t)get_ese_svdd_pwr_req();
    uint8_t spi_bus = (uint32_t)get_ese_spi_bus();
    uint8_t ese_type = 3;  // ese type 3:thn31

    x1 = ese_type;
    x1 = x1 | (spi_bus << OFFSET_8);
    x1 = x1 | (ESE_MAGIC_NUM << OFFSET_16);

    x2 = gpio_svdd_pwr_req;
    x2 = x2 | (ESE_MAGIC_NUM << OFFSET_16);
    arm_smccc_1_1_smc(MTK_SIP_KERNEL_ESE_CONF_TO_TEE_ADDR_AARCH64, x1, x2, 0, &res);
    pr_err("%s: thn31_nfc_write_conf_to_tee, x1:0x%X x2:0x%X\n", __func__, x1, x2);
    return;
}

static int recovery_close_nfc(struct i2c_client *client, struct thn31_dev *pdev)
{
    int ret;
    unsigned char recvBuf[40] = {0};
    const char send_reset[] = {0x20, 0x00, 0x01, 0x01};

    /* hardware reset */
    /* power on */
    gpio_set_value(pdev->firm_gpio, 0);
    thn31_enable_nfc(pdev);

    /* write CORE_RESET_CMD */
    ret = thn31_i2c_write(pdev, send_reset, sizeof(send_reset));
    if (ret < 0) {
        pr_err("%s: thn31_i2c_write failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    /* read response */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read rsp payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    /* read NTF */
    ret = thn31_i2c_read(pdev, recvBuf, NCI_HEADER);
    if (ret < 0) {
        pr_err("%s: thn31_i2c_read2 failed, ret:%d\n", __func__, ret);
        goto failed;
    }
    ret = thn31_i2c_read(pdev, recvBuf, recvBuf[2]);    // read ntf payload recvBuf[2]
    if (ret < 0) {
        pr_err("%s: thn31_i2c_read failed, ret:%d\n", __func__, ret);
        goto failed;
    }

    return 0;
failed:
    return -1;
}

static ssize_t thn31_nfc_recovery_close_nfc_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret = -1;
    int status = -1;
    struct i2c_client *i2c_client_dev = container_of(dev, struct i2c_client, dev);
    struct thn31_dev *thn31_dev = NULL;

    thn31_dev = i2c_get_clientdata(i2c_client_dev);
    if (thn31_dev == NULL) {
        pr_err("%s: thn31_dev == NULL!\n", __func__);
        return status;
    }
    pr_info("%s: enter!\n", __func__);
    status = recovery_close_nfc(i2c_client_dev, thn31_dev);
    if (status < 0) {
        pr_err("%s: check_sim_status error!\n", __func__);
    }
    ret = snprintf_s(buf, MAX_ATTRIBUTE_BUFFER_SIZE - 1, MAX_ATTRIBUTE_BUFFER_SIZE - 1,
                     "%d\n", status);
    pr_info("%s: status=%d\n", __func__, status);
    return ret;
}

static ssize_t thn31_nfc_recovery_close_nfc_store(struct device *dev, struct device_attribute *attr,
                                                  const char *buf, size_t count)
{
    return (ssize_t)count;
}

static int thn31_get_common_pointer()
{
    set_nfc_sim_status_show_pointer(thn31_nfc_sim_status_show);
    set_nfc_sim_switch_show_pointer(thn31_nfc_sim_switch_show);
    set_nfc_sim_switch_store_pointer(thn31_nfc_sim_switch_store);
    set_rd_nfc_sim_status_show_pointer(thn31_rd_nfc_sim_status_show);
    set_nfc_enable_status_show_pointer(thn31_nfc_enable_status_show);
    set_nfc_enable_status_store_pointer(thn31_nfc_enable_status_store);
    set_nfc_recovery_close_nfc_show_pointer(thn31_nfc_recovery_close_nfc_show);
    set_nfc_recovery_close_nfc_store_pointer(thn31_nfc_recovery_close_nfc_store);
    if ((get_nfc_sim_status_show_pointer() == NULL) || (get_nfc_sim_switch_show_pointer() == NULL) ||
        (get_nfc_sim_switch_store_pointer() == NULL) || (get_rd_nfc_sim_status_show_pointer() == NULL) ||
        (get_nfc_enable_status_show_pointer() == NULL) || (get_nfc_enable_status_store_pointer() == NULL) ||
        (get_nfc_recovery_close_nfc_show_pointer() == NULL) || (get_nfc_recovery_close_nfc_store_pointer() == NULL))
        return -1;

    return 0;
}

static int thn31_remove_common_pointer(void)
{
    set_nfc_sim_status_show_pointer(NULL);
    set_nfc_sim_switch_show_pointer(NULL);
    set_nfc_sim_switch_store_pointer(NULL);
    set_rd_nfc_sim_status_show_pointer(NULL);
    set_nfc_enable_status_show_pointer(NULL);
    set_nfc_enable_status_store_pointer(NULL);
    set_nfc_recovery_close_nfc_show_pointer(NULL);
    set_nfc_recovery_close_nfc_store_pointer(NULL);
    if ((get_nfc_sim_status_show_pointer() != NULL) || (get_nfc_sim_switch_show_pointer() != NULL) ||
        (get_nfc_sim_switch_store_pointer() != NULL) || (get_rd_nfc_sim_status_show_pointer() != NULL) ||
        (get_nfc_enable_status_show_pointer() != NULL) || (get_nfc_enable_status_store_pointer() != NULL) ||
        (get_nfc_recovery_close_nfc_show_pointer() != NULL) || (get_nfc_recovery_close_nfc_store_pointer() != NULL))
        return -1;

    return 0;
}

/* FUNCTION: create_sysfs_interfaces
 * DESCRIPTION: create_sysfs_interfaces.
 * Parameters
 * struct device *dev:device structure
 * RETURN VALUE
 * int:     result
 */
static int create_sysfs_interfaces(struct device *dev)
{
    if (thn31_get_common_pointer() != 0) {
        pr_err("%s:thn31_get_common_pointer fail\n", __func__);
        return -1;
    }
    if (create_common_sysfs_interfaces(dev) != 0) {
        pr_err("%s:thn31_create_common_sysfs_interfaces fail\n", __func__);
        return -1;
    }
    return 0;
}
/* FUNCTION: remove_sysfs_interfaces
 * DESCRIPTION: remove_sysfs_interfaces.
 * Parameters
 * struct device *dev:device structure
 * RETURN VALUE
 * int:     result
 */
static int remove_sysfs_interfaces(struct device *dev)
{
    remove_common_sysfs_interfaces(dev);
    if (thn31_remove_common_pointer() != 0) {
        pr_err("%s:thn31_remove_common_pointer fail\n", __func__);
        return -1;
    }
    return 0;
}

static int nfc_ven_low_beforepwd(struct notifier_block *this, unsigned long code,
                                 void *unused)
{
    pr_info("[%s]: enter!\n", __func__);
    if (nfcdev == NULL) {
        pr_err("[%s]: nfcdev NULL.don't need close nfc!\n", __func__);
        return 0;
    }
    gpio_set_value(nfcdev->ven_gpio, 0);
    msleep(10);    // sleep 10ms
    return 0;
}

static struct notifier_block nfc_ven_low_notifier = {
    .notifier_call = nfc_ven_low_beforepwd,
};

/* FUNCTION: check_thn31
 * DESCRIPTION: To test if nfc chip is ok
 * Parameters
 * struct i2c_client *client:i2c device structure
 * struct  thn31_dev *pdev:device structure
 * RETURN VALUE
 * int: check result
 */
static int check_thn31(struct i2c_client *client, struct thn31_dev *pdev)
{
    int ret = -1;
    int count = 0;
    const char host_to_thn31[1] = {0x20};
    const char firm_dload_cmd[8] = {0x00, 0x04, 0xD0, 0x09, 0x00, 0x00, 0xB1, 0x84};

    /* power on */
    gpio_set_value(pdev->firm_gpio, 0);
    thn31_enable_nfc(pdev);

    do {
        ret = i2c_master_send(client, host_to_thn31, sizeof(host_to_thn31));
        if (ret < 0) {
            pr_err("%s:thn31_i2c_write failed and ret = %d,at %d times\n", __func__, ret, count);
        } else {
            pr_info("%s:thn31_i2c_write success and ret = %d,at %d times\n", __func__, ret, count);
            mdelay(10);    // sleep 10ms
            thn31_enable_nfc(pdev);

            return ret;
        }
        count++;
        mdelay(10);    // sleep 10ms
    } while (count < NFC_TRY_NUM);

    /* In case firmware dload failed, will cause host_to_thn31 cmd send failed */
    for (count = 0; count < NFC_TRY_NUM; count++) {
        gpio_set_value(pdev->firm_gpio, 1);
        thn31_enable_nfc(pdev);

        ret = i2c_master_send(client, firm_dload_cmd, sizeof(firm_dload_cmd));
        if (ret < 0) {
            pr_err("%s:thn31_i2c_write download cmd failed:%d, ret = %d\n", __func__, count, ret);
            continue;
        }
        gpio_set_value(pdev->firm_gpio, 0);
        thn31_enable_nfc(pdev);

        break;
    }

    gpio_set_value(pdev->firm_gpio, 0);

    return ret;
}

/* FUNCTION: thn31_dev_open
 * DESCRIPTION: thn31_dev_open, used by user space to enable thn31
 * Parameters
 * struct inode *inode:device inode
 * struct file *filp:device file
 * RETURN VALUE
 * int: result
 */
static int thn31_dev_open(struct inode *inode, struct file *filp)
{
    struct thn31_dev *thn31_dev = container_of(filp->private_data,
                        struct thn31_dev,
                        thn31_device);
    filp->private_data = thn31_dev;
    pr_err("%s : %d,%d\n", __func__, imajor(inode), iminor(inode));

    return 0;
}
static int thn31_ese_pwr(struct thn31_dev *thn31_dev, unsigned long arg)
{
    int r = -1;

    if (arg == ESE_POWER_ON) {
        /**
         * Let's store the NFC VEN pin state
         * will check stored value in case of eSE power off request,
         * to find out if NFC MW also sent request to set VEN HIGH
         * VEN state will remain HIGH if NFC is enabled otherwise
         * it will be set as LOW
         */
        if (!gpio_get_value(thn31_dev->ven_gpio)) {
            pr_err("eSE HAL service setting ven_gpio HIGH\n");
            gpio_set_value(thn31_dev->ven_gpio, 1);
            /* hardware dependent delay */
            usleep_range(1000, 1100);    // sleep 1000, 1100 us
        } else {
            pr_err("ven_gpio already HIGH\n");
        }
        r = 0;
    } else if (arg == ESE_POWER_OFF) {
        if (!gpio_get_value(thn31_dev->ven_gpio)) {
            pr_err("NFC not enabled, disabling ven_gpio\n");
            gpio_set_value(thn31_dev->ven_gpio, 0);
            /* hardware dependent delay */
            usleep_range(1000, 1100);    // sleep 1000, 1100 ums
        } else {
            pr_err("keep ven_gpio high as NFC is enabled\n");
        }
        r = 0;
    } else if (arg == ESE_POWER_STATE) {
        // eSE power state
        r = gpio_get_value(thn31_dev->ven_gpio);
    }
    return r;
}

static void thn31_dealwith_setpwr_case(struct thn31_dev *thn31_dev, unsigned long arg)
{
    switch (arg) {
        case MODE_POWER_OFF:
            /* power off */
            pr_err("%s power off\n", __func__);
            gpio_set_value(thn31_dev->firm_gpio, 0);
            thn31_disable_irq_wake(thn31_dev);
            msleep(60);    // sleep 60ms
            break;
        case MODE_POWER_ON:
            /* power on */
            pr_err("%s firm_gpio %d, ven_gpio %d, power on\n", __func__,
                   thn31_dev->firm_gpio, thn31_dev->ven_gpio);
            gpio_set_value(thn31_dev->firm_gpio, 0);
            gpio_set_value(thn31_dev->ven_gpio, 1);
            thn31_enable_irq_wake(thn31_dev);
            msleep(20);    // sleep 20ms
            break;
        case MODE_FW_DWNLD_WITH_VEN:
            /* power on with firmware download (requires hw reset) */
            gpio_set_value(thn31_dev->ven_gpio, 0);
            gpio_set_value(thn31_dev->firm_gpio, 1);
            msleep(60);    // sleep 60ms
            gpio_set_value(thn31_dev->ven_gpio, 0);
            msleep(60);    // sleep 60ms
            gpio_set_value(thn31_dev->ven_gpio, 1);
            msleep(60);    // sleep 60ms
            break;
        case MODE_ISO_RST:
            pr_info("%s Read Cancel\n", __func__);
            thn31_dev->cancel_read = true;
            wake_up(&thn31_dev->read_wq);
            break;
        case MODE_FW_DWND_HIGH:     // 4 means thn31 download start
            pr_err("%s FW dwld gpio %d ioctl called from NFC \n", __func__, thn31_dev->firm_gpio);
            gpio_set_value(thn31_dev->firm_gpio, 1);
            msleep(10);    // sleep 10ms
            break;
        case MODE_POWER_RESET:
            pr_err("%s noting arg %lu\n", __func__, arg);
            break;
        case MODE_FW_GPIO_LOW:    // 6 means thn31 download complete
            pr_err("%s FW GPIO %d set to 0x00 >>>>>>>\n", __func__, thn31_dev->firm_gpio);
            gpio_set_value(thn31_dev->firm_gpio, 0);
            msleep(5);    // sleep 5ms
            break;
        case MODE_RF_GPIO_HIGH:
            pr_err("%s RF GPIO set rf_gpio %d to 01 >>>>>>>\n", __func__, thn31_dev->rf_gpio);
            if (thn31_dev->rf_gpio > 0) {
                gpio_set_value(thn31_dev->rf_gpio, 1);
            }
            msleep(5);    // sleep 5ms
            break;
        case MODE_RF_GPIO_LOW:
            pr_err("%s RF GPIO set rf_gpio %d to 00 >>>>>>>\n", __func__, thn31_dev->rf_gpio);
            if (thn31_dev->rf_gpio > 0) {
                gpio_set_value(thn31_dev->rf_gpio, 0);
            }
            msleep(5);    // sleep 5ms
            break;
        case MODE_THN31_VEN_HIGH:
            pr_err("%s THN31 VEN GPIO %d to 01 >>>>>>>\n", __func__, thn31_dev->ven_gpio);
            if (thn31_dev->ven_gpio > 0) {
                gpio_set_value(thn31_dev->ven_gpio, 1);
            }
            break;
        case MODE_THN31_VEN_LOW:
            pr_err("%s THN31 VEN GPIO %d to 00 >>>>>>>\n", __func__, thn31_dev->ven_gpio);
            if (thn31_dev->ven_gpio > 0) {
                gpio_set_value(thn31_dev->ven_gpio, 0);
            }
            break;
        case MODE_THN31_FW_DWND_HIGH:
            pr_err("%s THN31 FW DWND GPIO %d to 01 >>>>>>>\n", __func__, thn31_dev->firm_gpio);
            if (thn31_dev->firm_gpio > 0) {
                gpio_set_value(thn31_dev->firm_gpio, 1);
            }
            break;
        case MODE_THN31_FW_DWND_LOW:
            pr_err("%s THN31 FW DWND GPIO %d to 00 >>>>>>>\n", __func__, thn31_dev->firm_gpio);
            if (thn31_dev->firm_gpio > 0) {
                gpio_set_value(thn31_dev->firm_gpio, 0);
            }
            break;
        case MODE_THN31_NFC_DLD_FLUSH:
            /*
             * release blocked user thread waiting for pending read
             */
            if (!mutex_trylock(&thn31_dev->read_mutex)) {
                thn31_dev->release_read = true;
                thn31_disable_irq(thn31_dev);
                wake_up(&thn31_dev->read_wq);
                pr_info("%s: waiting for release of blocked read\n", __func__);
                mutex_lock(&thn31_dev->read_mutex);
                thn31_dev->release_read = false;
            } else {
                pr_info("%s: read thread already released\n", __func__);
            }
            mutex_unlock(&thn31_dev->read_mutex);
            break;
        default:
            pr_err("%s bad arg %lu\n", __func__, arg);
            break;
    }
    return;
}
/* FUNCTION: thn31_dev_ioctl
 * DESCRIPTION: thn31_dev_ioctl, used by user space
 * Parameters
 * struct file *filp:device file
 * unsigned int cmd:command
 * unsigned long arg:parameters
 * RETURN VALUE:<0(error code), 0(success), >0(chip type)
 * long: result
 */
static long thn31_dev_ioctl(struct file *filp,
                            unsigned int cmd, unsigned long arg)
{
    struct thn31_dev *thn31_dev = filp->private_data;
    int r = 0;

    pr_info("%s ++      cmd = 0x%x \n", __func__, cmd);

    switch (cmd) {
        case THN31_SET_PWR:
            thn31_dealwith_setpwr_case(thn31_dev, arg);
            break;
        case ESE_SET_PWR:
            r = thn31_ese_pwr(thn31_dev, arg);
            break;
        case ESE_GET_PWR:
            r = thn31_ese_pwr(thn31_dev, ESE_POWER_STATE);    // 3 ese power off
            break;
        case THN31_GET_CHIP_TYPE:
            r = get_chip_value();
            break;
        default:
            pr_err("%s bad ioctl 0x%x\n", __func__, cmd);
            return -EINVAL;
    }

    return r;
}

static const struct file_operations thn31_dev_fops = {
    .owner = THIS_MODULE,
    .llseek = no_llseek,
    .read = thn31_dev_read,
    .write = thn31_dev_write,
    .open = thn31_dev_open,
    .unlocked_ioctl = thn31_dev_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl = thn31_dev_ioctl,
#endif
};

/* FUNCTION: thn31_parse_dt
 * DESCRIPTION: thn31_parse_dt, get gpio configuration from device tree system
 * Parameters
 * struct device *dev:device data
 * struct thn31_i2c_platform_data *pdata:i2c data
 * RETURN VALUE
 * int: result
 */
static int thn31_parse_dt(struct device *dev,
                          struct thn31_i2c_platform_data *pdata)
{
    struct device_node *np = dev->of_node;
    int ret = 0;

    /* int gpio */
    pdata->irq_gpio = of_get_named_gpio_flags(np, "tms,nfc_int", 0, NULL);
    pr_err("pdata->irq_gpio = %d \n", pdata->irq_gpio);
    if (pdata->irq_gpio < 0) {
        pr_err("failed to get \"huawei,nfc_int\"\n");
        goto err;
    }

    /* nfc_fm_dload gpio */
    pdata->fwdl_en_gpio = of_get_named_gpio_flags(np, "tms,nfc_firm", 0, NULL);
    pr_err("pdata->fwdl_en_gpio = %d \n", pdata->fwdl_en_gpio);
    if (pdata->fwdl_en_gpio < 0) {
        pr_err("failed to get \"huawei,nfc_firm\"\n");
        goto err;
    }

    /* nfc_ven gpio */
    pdata->ven_gpio = of_get_named_gpio_flags(np, "tms,nfc_ven", 0, NULL);
    pr_err("pdata->ven_gpio = %d \n", pdata->ven_gpio);
    if (pdata->ven_gpio < 0) {
        pr_err("failed to get \"huawei,nfc_ven\"\n");
        goto err;
    }
    /* nfc_rf gpio */
    pdata->rf_gpio = of_get_named_gpio_flags(np, "tms,nfc_palau_rf", 0, NULL);
    pr_err("pdata->rf_gpio = %d \n", pdata->rf_gpio);

    pr_info("%s :clk-req-gpio=%d, irq_gpio=%d, fwdl_en_gpio=%d, ven_gpio=%d \n", __func__, pdata->clk_req_gpio,
            pdata->irq_gpio, pdata->fwdl_en_gpio, pdata->ven_gpio);

err:
    return ret;
}

/* FUNCTION: thn31_gpio_request
 * DESCRIPTION: thn31_gpio_request, nfc gpio configuration
 * Parameters
 * struct device *dev:device data
 * struct thn31_i2c_platform_data *pdata:i2c data
 * RETURN VALUE
 * int: result
 */
static int thn31_gpio_request(struct device *dev,
                              struct thn31_i2c_platform_data *pdata)
{
    int ret = -1;

    pr_info("%s : thn31_gpio_request enter\n", __func__);

    // NFC_INT
    ret = gpio_request(pdata->irq_gpio, "nfc_int");
    if (ret) {
        goto err_irq;
    }
    ret = gpio_direction_input(pdata->irq_gpio);
    if (ret) {
        goto err_fwdl_en;
    }

    // NFC_FWDL
    ret = gpio_request(pdata->fwdl_en_gpio, "nfc_wake");
    if (ret) {
        goto err_fwdl_en;
    }
    ret = gpio_direction_output(pdata->fwdl_en_gpio, 0);
    if (ret) {
        goto err_ven;
    }

    // NFC_VEN
    ret = gpio_request(pdata->ven_gpio, "nfc_ven");
    if (ret) {
        goto err_ven;
    }
    ret = gpio_direction_output(pdata->ven_gpio, 0);
    if (ret) {
        goto err_clk_req;
    }
    if (pdata->rf_gpio > 0) {
        ret = gpio_request(pdata->rf_gpio, "nfc_palau_rf");
        pr_info("[%s,%d]:thn31 probe rf_gpio %d request ret %d\n", __func__, __LINE__, pdata->rf_gpio, ret);
        if (ret == 0) {
            ret = gpio_direction_output(pdata->rf_gpio, 1);
            pr_info("[%s,%d]:thn31 probe rf_gpio gpio_direction_output ret %d\n", __func__, __LINE__, ret);
        }
    }
    return 0;

err_clk_req:
    gpio_free(pdata->ven_gpio);
err_ven:
    gpio_free(pdata->fwdl_en_gpio);
err_fwdl_en:
    gpio_free(pdata->irq_gpio);
err_irq:

    pr_err("%s: gpio request err %d\n", __func__, ret);
    return ret;
}
/* FUNCTION: thn31_gpio_release
 * DESCRIPTION: thn31_gpio_release, release nfc gpio
 * Parameters
 * struct thn31_i2c_platform_data *pdata:i2c data
 * RETURN VALUE
 * none
 */
static void thn31_gpio_release(struct thn31_i2c_platform_data *pdata)
{
    gpio_free(pdata->ven_gpio);
    gpio_free(pdata->irq_gpio);
    gpio_free(pdata->fwdl_en_gpio);
}

static int thn31_pinctrl_lookup_select(struct pinctrl *thn31_pinctrl,
                                       struct pinctrl_state **pin_state, const char *pinctrl_name)
{
    int ret = 0;
    struct pinctrl_state *state;
    state = pinctrl_lookup_state(thn31_pinctrl, pinctrl_name);
    if (IS_ERR_OR_NULL(state)) {
        ret = PTR_ERR(state);
        pr_err("%s: get %s error: %d\n", __func__, pinctrl_name, ret);
        return -1;
    }

    ret = pinctrl_select_state(thn31_pinctrl, state);
    if (ret < 0) {
        pr_err("%s: select %s error: %d\n", __func__, pinctrl_name, ret);
    } else {
        *pin_state = state;
        pr_info("%s: thn31 select %s success\n", __func__, pinctrl_name);
    }
    return 0;
}

static int thn31_pinctrl_init(struct thn31_dev *nfc_dev)
{
    int ret = 0;

    nfc_dev->thn31_pinctrl = devm_pinctrl_get(nfc_dev->dev);
    if (IS_ERR_OR_NULL(nfc_dev->thn31_pinctrl)) {
        ret = PTR_ERR(nfc_dev->thn31_pinctrl);
        pr_err("%s: get thn31_pinctrl error: %d\n", __func__, ret);
        goto err_pinctrl_get;
    }

    thn31_pinctrl_lookup_select(nfc_dev->thn31_pinctrl,
                                &nfc_dev->pinctrl_state_srclkenai, "srclkenai");
    thn31_pinctrl_lookup_select(nfc_dev->thn31_pinctrl,
                                &nfc_dev->pinctrl_state_esespics, "esespics");
    thn31_pinctrl_lookup_select(nfc_dev->thn31_pinctrl,
                                &nfc_dev->pinctrl_state_esespiclk, "esespiclk");
    thn31_pinctrl_lookup_select(nfc_dev->thn31_pinctrl,
                                &nfc_dev->pinctrl_state_esespimo, "esespimo");
    thn31_pinctrl_lookup_select(nfc_dev->thn31_pinctrl,
                                &nfc_dev->pinctrl_state_esespimi, "esespimi");
    thn31_pinctrl_lookup_select(nfc_dev->thn31_pinctrl,
                                &nfc_dev->pinctrl_state_esepwrreq, "esepwrreq");

    devm_pinctrl_put(nfc_dev->thn31_pinctrl);
err_pinctrl_get:
    nfc_dev->thn31_pinctrl = NULL;
    return ret;
}

static int thn31_get_resource(struct thn31_dev *pdev, struct i2c_client *client)
{
    int ret = 0;
    char *nfc_clk_status = NULL;

    ret = of_property_read_string(client->dev.of_node, "clk_status", (const char **)&nfc_clk_status);
    if (ret) {
        pr_err("[%s,%d]:read clk status fail\n", __func__, __LINE__);
        return -ENODEV;
    } else if (!strcmp(nfc_clk_status, "pmu")) {
        pr_err("[%s,%d]:clock source is pmu\n", __func__, __LINE__);
        set_nfc_clk_src(NFC_CLK_SRC_PMU);
    } else if (!strcmp(nfc_clk_status, "xtal")) {
        pr_err("[%s,%d]:clock source is XTAL\n", __func__, __LINE__);
        set_nfc_clk_src(NFC_CLK_SRC_XTAL);
    } else {
        pr_err("[%s,%d]:clock source is cpu by default\n", __func__, __LINE__);
        set_nfc_clk_src(NFC_CLK_SRC_CPU);
    }

    return 0;
}

static int thn31_nfc_i2c_dev_suspend(struct device *device)
{
    struct i2c_client *client = to_i2c_client(device);
    struct thn31_dev *thn31_dev = i2c_get_clientdata(client);

    if (device_may_wakeup(&client->dev) && thn31_dev->irq_enabled) {
        if (!enable_irq_wake(thn31_dev->client->irq))
            thn31_dev->irq_wake_enabled = true;
    }
    return 0;
}

static int thn31_nfc_i2c_dev_resume(struct device *device)
{
    struct i2c_client *client = to_i2c_client(device);
    struct thn31_dev *thn31_dev = i2c_get_clientdata(client);

    if (device_may_wakeup(&client->dev) && thn31_dev->irq_wake_enabled) {
        if (!disable_irq_wake(client->irq))
            thn31_dev->irq_wake_enabled = false;
    }
    return 0;
}
/* FUNCTION: thn31_probe
 * DESCRIPTION: thn31_probe
 * Parameters
 * struct i2c_client *client:i2c client data
 * const struct i2c_device_id *id:i2c device id
 * RETURN VALUE
 * int: result
 */
static int thn31_probe(struct i2c_client *client,
                       const struct i2c_device_id *id)
{
    int ret = 0;
    struct clk *nfc_clk = NULL;
    struct thn31_i2c_platform_data *platform_data = NULL;
    struct thn31_dev *thn31_dev = NULL;

    pr_info("%s begin\n", __func__);
#ifdef CONFIG_HUAWEI_DSM
    if (!get_nfc_dclient()) {
        set_nfc_dclient(dsm_register_client (&dsm_nfc));
    }
#endif

    if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
        pr_err("%s : need I2C_FUNC_I2C\n", __func__);
        return -ENODEV;
    }

    get_nfc_wired_ese_type();

    /* create interface node */
    ret = create_sysfs_interfaces(&client->dev);
    if (ret < 0) {
        pr_err("Failed to create_sysfs_interfaces\n");
        return -ENODEV;
    }
    ret = sysfs_create_link(NULL, &client->dev.kobj, "nfc");
    if (ret < 0) {
        pr_err("Failed to sysfs_create_link\n");
        return -ENODEV;
    }
    platform_data = kzalloc(sizeof(struct thn31_i2c_platform_data),
                            GFP_KERNEL);
    if (platform_data == NULL) {
        dev_err(&client->dev, "failed to allocate memory\n");
        ret = -ENOMEM;
        goto err_platform_data;
    }

    /* get gpio config */
    ret = thn31_parse_dt(&client->dev, platform_data);
    if (ret < 0) {
        dev_err(&client->dev, "failed to parse device tree: %d\n", ret);
        goto err_parse_dt;
    }
    /* config nfc gpio */
    ret = thn31_gpio_request(&client->dev, platform_data);
    if (ret) {
        dev_err(&client->dev, "failed to request gpio\n");
        goto err_gpio_request;
    }

    thn31_dev = kzalloc(sizeof(*thn31_dev), GFP_KERNEL);
    if (thn31_dev == NULL) {
        dev_err(&client->dev,
                "failed to allocate memory for module data\n");
        ret = -ENOMEM;
        goto err_exit;
    }

    ret = thn31_get_resource(thn31_dev, client);
    if (ret < 0) {
        pr_err("[%s,%d]:thn31 probe get resource failed\n", __func__, __LINE__);
    }

    client->irq = gpio_to_irq(platform_data->irq_gpio);

    thn31_dev->irq_gpio = platform_data->irq_gpio;
    thn31_dev->ven_gpio = platform_data->ven_gpio;
    thn31_dev->firm_gpio = platform_data->fwdl_en_gpio;
    thn31_dev->rf_gpio = platform_data->rf_gpio;
    thn31_dev->client = client;
    thn31_dev->dev = &client->dev;
    thn31_dev->sim_switch = CARD1_SELECT; /* sim_select = 1,UICC select */
    thn31_dev->sim_status = CARD_UNKNOWN;
    thn31_dev->enable_status = ENABLE_START;
    thn31_dev->nfc_clk = nfc_clk;
    thn31_dev->irq_wake_enabled = false;
    thn31_dev->release_read = false;

    nfcdev = thn31_dev;
    /* notifier for supply shutdown */
    pr_err("%s:register_reboot_notifier\n", __func__);
    register_reboot_notifier(&nfc_ven_low_notifier);
    get_nfc_chip_type();
    thn31_pinctrl_init(thn31_dev);

    /* Initialise mutex and work queue */
    init_waitqueue_head(&thn31_dev->read_wq);
    mutex_init(&thn31_dev->read_mutex);
    mutex_init(&thn31_dev->irq_wake_mutex);
    spin_lock_init(&thn31_dev->irq_enabled_lock);
    thn31_dev->wl = wakeup_source_register(thn31_dev->dev, "nfc_locker");
    pr_err("%s:wakeup_source_register start\n", __func__);
    thn31_dev->thn31_device.minor = MISC_DYNAMIC_MINOR;
    thn31_dev->thn31_device.name = "nfc_dg";
    thn31_dev->thn31_device.fops = &thn31_dev_fops;
    ret = misc_register(&thn31_dev->thn31_device);
    if (ret) {
        dev_err(&client->dev, "%s: misc_register err %d\n",
                __func__, ret);
        goto err_misc_register;
    }
    pr_err("%s:check thn31\n", __func__);
    /* check if nfc chip is ok */
    ret = check_thn31(client, thn31_dev);
    if (ret < 0) {
        pr_err("%s: thn31 check failed \n", __func__);
        goto err_i2c;
    }
    gpio_set_value(thn31_dev->firm_gpio, 0);
    /* request irq.     the irq is set whenever the chip has data available
     * for reading.     it is cleared when all data has been read.
     */
    dev_info(&client->dev, "%s : requesting IRQ %d\n",
        __func__, client->irq);
    thn31_dev->irq_enabled = true;
    ret = request_irq(client->irq, thn31_dev_irq_handler,
                      IRQF_TRIGGER_HIGH,
                      client->name, thn31_dev);
    if (ret) {
        dev_err(&client->dev, "request_irq failed\n");
        goto err_request_irq_failed;
    }
    device_init_wakeup(&client->dev, true);
    device_set_wakeup_capable(&client->dev, true);
    enable_irq_wake(thn31_dev->client->irq);
    thn31_disable_irq(thn31_dev);
    i2c_set_clientdata(client, thn31_dev);

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
    /* detect current device successful, set the flag as present */
    set_hw_dev_flag(DEV_I2C_NFC);
    pr_info("%s set_hw_dev_flag success.\n", __func__);
#endif

    /* get and save configure name */
    get_nfc_config_name(&client->dev);
    set_nfc_single_channel(&client->dev);
    if ((nfc_get_ese_spi_bus() == 0) && (nfc_get_ese_pwr_req_gpio() == 0)) {
        thn31_nfc_write_conf_to_tee();
    }

    /* #ifdef TMS_NFC */
    thn31_set_nfc_qcom_activated();
    /* #endif */
    pr_info("%s success.\n", __func__);
    return 0;
err_i2c:
    nfc_record_dmd_info(NFC_DMD_I2C_READ_ERROR_NO, "THN31-Error-in-Probe-Error:nfc_sz");
err_request_irq_failed:
    misc_deregister(&thn31_dev->thn31_device);

err_misc_register:
    mutex_destroy(&thn31_dev->read_mutex);
    mutex_destroy(&thn31_dev->irq_wake_mutex);
    kfree(thn31_dev);
err_exit:
    thn31_gpio_release(platform_data);
err_gpio_request:
    if (nfc_clk) {
        clk_put(nfc_clk);
        nfc_clk = NULL;
    }
err_parse_dt:
    kfree(platform_data);
err_platform_data:
    remove_sysfs_interfaces(&client->dev);

    dev_err(&client->dev, "%s: err %d\n", __func__, ret);
    return ret;
}

/* FUNCTION: thn31_remove
 * DESCRIPTION: thn31_remove
 * Parameters
 * struct i2c_client *client:i2c client data
 * RETURN VALUE
 * int: result
 */
static int thn31_remove(struct i2c_client *client)
{
    struct thn31_dev *thn31_dev = NULL;
    dev_info(&client->dev, "%s ++\n", __func__);
    unregister_reboot_notifier(&nfc_ven_low_notifier);
    thn31_dev = i2c_get_clientdata(client);
    gpio_set_value(thn31_dev->ven_gpio, 0);
    free_irq(client->irq, thn31_dev);
    misc_deregister(&thn31_dev->thn31_device);
    mutex_destroy(&thn31_dev->read_mutex);
    mutex_destroy(&thn31_dev->irq_wake_mutex);
    wakeup_source_unregister(thn31_dev->wl);
    remove_sysfs_interfaces(&client->dev);
    if (thn31_dev->nfc_clk) {
        clk_put(thn31_dev->nfc_clk);
        thn31_dev->nfc_clk = NULL;
    }
    gpio_free(thn31_dev->irq_gpio);
    gpio_free(thn31_dev->ven_gpio);
    gpio_free(thn31_dev->firm_gpio);
    kfree(thn31_dev);

    return 0;
}

static const struct i2c_device_id thn31_id[] = {
    { "thn31", 0 },
    { }
};

static struct of_device_id thn31_match_table[] = {
    { .compatible = "qcom,nq-thn31", },
    { },
};

static const struct dev_pm_ops nfc_i2c_dev_pm_ops = {
    SET_SYSTEM_SLEEP_PM_OPS(thn31_nfc_i2c_dev_suspend, thn31_nfc_i2c_dev_resume)
};

static struct i2c_driver thn31_driver = {
    .id_table = thn31_id,
    .probe = thn31_probe,
    .remove = thn31_remove,
    .driver        = {
        .owner = THIS_MODULE,
        .name = "thn31",
        .pm = &nfc_i2c_dev_pm_ops,
        .of_match_table = thn31_match_table,
    },
};

static int __init thn31_dev_init(void)
{
    pr_info("### %s begin! \n", __func__);
    return i2c_add_driver(&thn31_driver);
}
module_init(thn31_dev_init);

static void __exit thn31_dev_exit(void)
{
    i2c_del_driver(&thn31_driver);
}
module_exit(thn31_dev_exit);

MODULE_AUTHOR("SERI");
MODULE_DESCRIPTION("NFC thn31 driver");
MODULE_LICENSE("GPL");
