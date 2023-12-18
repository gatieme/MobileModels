#ifndef __MAS_UFS_H__
#define __MAS_UFS_H__

#include <linux/version.h>

#define QUUEUE_CMD_TIMEOUT (2 * MSEC_PER_SEC)

void mas_ufshcd_prepare_req_desc_hdr(
	struct ufshcd_lrb *lrbp, u32 *upiu_flags);

void ufshcd_dump_status(
	struct Scsi_Host *host, enum blk_dump_scene dump_type);
int ufshcd_send_scsi_sync_cache_init(void);
void ufshcd_send_scsi_sync_cache_deinit(void);
int ufshcd_direct_flush(struct scsi_device *sdev);
void ufshcd_send_scsi_sync_cache_deinit(void);
void mas_ufshcd_slave_config(
	struct request_queue *q, struct scsi_device *sdev);
void ufshcd_mas_mq_init(struct ufs_hba *hba, struct Scsi_Host *host);
void ufshcd_lba_tag_release(struct ufs_hba *hba, int tag);
int ufshcd_lba_tag_alloc(struct ufs_hba *hba, struct scsi_cmnd *cmd);

#ifdef CONFIG_HYPERHOLD_CORE
int ufshcd_get_health_info(struct scsi_device *sdev,
	u8 *pre_eol_info, u8 *life_time_est_a, u8 *life_time_est_b);
#endif
#endif /* __MAS_UFS_H__ */
