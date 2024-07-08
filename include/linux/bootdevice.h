#ifndef BOOTDEVICE_H
#define BOOTDEVICE_H
#include <linux/device.h>

enum bootdevice_type { BOOT_DEVICE_EMMC = 0, BOOT_DEVICE_UFS = 1 };
#define UFS_VENDOR_HYNIX       0x1AD
void set_bootdevice_type(enum bootdevice_type type);
enum bootdevice_type get_bootdevice_type(void);
unsigned int get_bootdevice_manfid(void);
void set_bootdevice_name(struct device *dev);
void set_bootdevice_size(sector_t size);
void set_bootdevice_cid(u32 *cid);
void set_bootdevice_product_name(char *product_name, u32 len);
void set_bootdevice_pre_eol_info(u8 pre_eol_info);
void set_bootdevice_life_time_est_typ_a(u8 life_time_est_typ_a);
void set_bootdevice_life_time_est_typ_b(u8 life_time_est_typ_b);
void set_bootdevice_manfid(unsigned int manfid);

#define MAX_RPMB_REGION_NUM 4
#define MAX_FRAME_BIT 64
/* we use 0x rpmb to indicate a valid value */
#define RPMB_DONE 0x72706D62 /* 'r', 'p', 'm', 'b' */
struct rpmb_config_info{
	u64 rpmb_total_blks;/*  rpmb total size is  (rpmb_total_blks * rpmb_blk_size)*/
	u64 rpmb_read_frame_support;/*bit 64 to mark the read frames support*/
	u64 rpmb_write_frame_support;/*bit 64 to mark the write frames support*/
	u64 rpmb_unit_size;/*default value is 128Kbyte*/
	u8 rpmb_region_size[MAX_RPMB_REGION_NUM];/*number of unit*/
	u8 rpmb_blk_size;/* one blk size is 2 << rpmb_blk_size*/
	u8 rpmb_read_align;/*0:no align 1:align*/
	u8 rpmb_write_align;/*0:no align 1:align*/
	u8 rpmb_region_enable;/*bit to enable region*/
};
void set_rpmb_blk_count(uint64_t blk_count);
void set_rpmb_write_frame_support(u64 write_frame_support);
void set_rpmb_config_ready_status(void);
int get_rpmb_blk_count(uint64_t *blk_count, int delay_ms);
unsigned int get_rpmb_config_ready_status(void);
struct rpmb_config_info get_rpmb_config(void);

#endif
