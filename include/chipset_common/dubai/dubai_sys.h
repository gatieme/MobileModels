#ifndef __H_DUBAI_SYS_H__
#define __H_DUBAI_SYS_H__

#include <linux/types.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/sysfs.h>

extern struct class *dubai_class;

int dubai_sysfslink_register(struct device *dev);
int dubai_sysfslink_register_name(struct device *dev, char *name);
void dubai_sysfslink_unregister(struct device *dev);
int dubai_class_init(void);
void dubai_class_exit(void);

#endif /*__H_DUBAI_SYS_H__*/
