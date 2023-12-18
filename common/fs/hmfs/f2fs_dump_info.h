/*
 * =====================================================================================
 *
 *       Filename:  f2fs_dump_info.h
 *
 *    Description:  dump f2fs infomation
 *
 *        Version:  1.0
 *        Created:  11/23/2015 19:31:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  malihou (m00279553), lihou.ma@huawei.com
 *   Organization:  Huawei
 *
 * =====================================================================================
 */

#ifndef F2FS_DUMP_INFO_H
#define F2FS_DUMP_INFO_H

void hmfs_print_raw_sb_info(struct f2fs_sb_info *sbi);
void hmfs_print_ckpt_info(struct f2fs_sb_info *sbi);
/* ckpt and sb info is far from the panic point,
   add the Real-time disk info, sbi messages */
void hmfs_print_sbi_info(struct f2fs_sb_info *sbi);

void hmfs_print_inode(struct f2fs_inode *ri);

#ifdef CONFIG_MAS_BLK
void hmfs_print_frag_info(void);
#endif

#endif
