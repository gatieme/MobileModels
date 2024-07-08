#ifndef __HISI_HISEE_UPGRADE_H__
#define __HISI_HISEE_UPGRADE_H__

#define HISEE_OLD_COS_IMAGE_ERROR      (-8000)

#define HISEE_MISC_VERSION0            (0x20)

int cos_image_upgrade_func(void *buf, int para);
int hisee_misc_process(void);
int misc_image_upgrade_func(void *buf, int para);

ssize_t hisee_has_new_cos_show(struct device *dev, struct device_attribute *attr, char *buf);
ssize_t hisee_check_upgrade_show(struct device *dev, struct device_attribute *attr, char *buf);

#endif
