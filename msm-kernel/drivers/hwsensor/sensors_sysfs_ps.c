/* Copyright (c) 2013-2014, 2017 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/ctype.h>
#include <linux/rwsem.h>
#include <linux/string.h>
//#include <securec.h>
#include "sensors_sysfs_ps.h"
#include <apsensor_channel/ap_sensor_route.h>
#include <apsensor_channel/ap_sensor.h>

#define MAX_STR_SIZE        1024
#define TAG_PS_FOR_NODE     5
static int receiver_status;
static int lcdfreq_status;

/***************** tp event to ultrasonic start ******************/
#define ULTRASONIC_SENSOR_TYPE 6
#define TP_EVENT_CMD 5

typedef struct tp_buf_to_hal {
    uint8_t sensor_type;
    uint8_t cmd;
    uint8_t subcmd;
    uint8_t reserved;
} tp_buf_to_hal_t;

static tp_buf_to_hal_t tp_data = {0xFF, 0, 0, 0};

int tp_event_to_ultrasonic(uint8_t event)
{
    hwlog_info("[%s] tp send event to slpi", __func__);

    tp_data.sensor_type = ULTRASONIC_SENSOR_TYPE;
    tp_data.cmd = TP_EVENT_CMD;
    tp_data.subcmd = event;
    tp_data.reserved = 0;

    ap_sensor_route_write((char *)&tp_data, (4));
    return 0;
}
EXPORT_SYMBOL(tp_event_to_ultrasonic);
/***************** tp event to ultrasonic end ******************/

void ps_lcdfreq_status_change(unsigned long value)
{
    struct ps_node_buf_to_hal_t lcdfreq_buf;

    lcdfreq_buf.sensor_type = SENSOR_TYPE_SENSOR_NODE;
    lcdfreq_buf.cmd = TAG_PS_FOR_NODE;
    lcdfreq_buf.data[NODE_INFO_TYPE] = SUNCOM_LCDFREQ;
    lcdfreq_buf.data[NODE_INFO_VALUE] = value;

    pr_info("SENSOR_TYPE_SENSOR_NODE lcdfreq status %d\n", value);
    ap_sensor_route_write((char *)&lcdfreq_buf,
        (PS_NODE_INFO_CNT * sizeof(uint32_t) + PS_IOCTL_PKG_HEADER));
}

void ps_recv_status_change(unsigned long value)
{
    struct ps_node_buf_to_hal_t recv_buf;

    recv_buf.sensor_type = SENSOR_TYPE_SENSOR_NODE;
    recv_buf.cmd = TAG_PS_FOR_NODE;
    recv_buf.data[NODE_INFO_TYPE] = SUBCOM_RECV;
    recv_buf.data[NODE_INFO_VALUE] = value;

    pr_info("SENSOR_TYPE_SENSOR_NODE receiver status(1:ON,0:OFF) %d\n", value);
    ap_sensor_route_write((char *)&recv_buf,
        (PS_NODE_INFO_CNT * sizeof(uint32_t) + PS_IOCTL_PKG_HEADER));
}

ssize_t store_send_lcdfreq_req(struct device *dev,
    struct device_attribute *attr, const char *buf, size_t size)
{
    unsigned long value = 0;

    if (kstrtoul(buf, 10, &value)) {
        pr_err("%s: lcdfreq val %lu invalid", __func__, value);
    }
    pr_info("%s: send_lcdfreq_req val %lu\n", __func__, value);
    lcdfreq_status = (int)value;
    if (value == ST_LCDFREQ_60HZ || value == ST_LCDFREQ_90HZ ||
        value == ST_LCDFREQ_120HZ || value == ST_LCDFREQ_30HZ) {
        ps_lcdfreq_status_change(value);
    }
    return size;
}
EXPORT_SYMBOL(store_send_lcdfreq_req);

ssize_t show_send_lcdfreq_req(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    return snprintf(buf, MAX_STR_SIZE, "%d\n", lcdfreq_status);
}
EXPORT_SYMBOL(show_send_lcdfreq_req);

ssize_t store_send_receiver_req(struct device *dev,
    struct device_attribute *attr, const char *buf, size_t size)
{
    unsigned long value = 0;

    if (kstrtoul(buf, 10, &value)) {
        pr_err("%s: receiver val %lu invalid", __func__, value);
    }
    pr_info("%s: send_receiver_req val %lu\n", __func__, value);
    receiver_status = (int)value;
    if (value == ST_RECEIVER_OFF || value == ST_RECEIVER_ON) {
        ps_recv_status_change(value);
    }
    return size;
}
EXPORT_SYMBOL(store_send_receiver_req);

ssize_t show_send_receiver_req(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    return snprintf(buf, MAX_STR_SIZE, "%d\n", receiver_status);
}
EXPORT_SYMBOL(show_send_receiver_req);

MODULE_LICENSE("GPL");
