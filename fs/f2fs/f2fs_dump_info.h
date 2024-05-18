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
 *         Author:
 *   Organization:  Hornor
 *
 * =====================================================================================
 */

#ifndef F2FS_DUMP_INFO_H
#define F2FS_DUMP_INFO_H

void f2fs_print_raw_sb_info(struct f2fs_sb_info *sbi);
void f2fs_print_ckpt_info(struct f2fs_sb_info *sbi);
/* ckpt and sb info is far from the panic point,
   add the Real-time disk info, sbi messages */
void f2fs_print_sbi_info(struct f2fs_sb_info *sbi);

#endif
