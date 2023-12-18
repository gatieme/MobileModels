#ifndef __HALL_REPORT_H
#define __HALL_REPORT_H

#include <../apsensor_channel/ap_sensor.h>
#include <../apsensor_channel/ap_sensor_route.h>

#ifdef CONFIG_HUAWEI_DSM
#include <dsm/dsm_pub.h>
#endif

int hall_report_register(struct device *dev);
void hall_report_unregister(void);
int hall_report_value(int value);
void ext_hall_report_value(int ext_hall_type, int value);
void get_hall_fature_config(struct device_node *node);
void ext_hall_notify_event(int ext_hall_type, int value);
uint32_t get_hall_lightstrap_value(void);
int get_ext_hall_status(unsigned int ext_hall_type);
#ifdef CONFIG_HUAWEI_DSM
void hall_set_irq_info(struct dsm_client *dclient, unsigned int pdata);
void hall_report_dsm_info(struct dsm_client *dclient, bool istrigger);
#endif
#endif