/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2020. All rights reserved.
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

#ifndef _BSP_MLOADER_H_
#define _BSP_MLOADER_H_

#include <product_config.h>
#include <osl_common.h>

/* ****************************************************************************
 * Attention                           *
 * *****************************************************************************
 * Description : Driver for mloader
 * Header File : the following head files need to be modified at the same time
 * : /acore/kernel/platform_drivers/include/bsp_mloader.h
 * : /ccore/include/fusion/bsp_mloader.h
 * **************************************************************************** */
#define MLOADER_OP_GET_INIT_INFO (2)
#define MLOADER_OP_VERIFY_IMAGE (3)
#define MLOADER_OP_PATCH_MSG (4)
#define MLOADER_OP_LOAD_FINISHED (5)

typedef enum {
    MLOADER_NORMAL_LOAD = 0,
    MLOADER_FS_LOAD = 1,
    MLOADER_BACK_LOAD = 2,
    MLOADER_BUTT
} mloader_load_e;

/* 这个枚举的修改需要同步修改一下几个地方
mbb、phone:
phone secos
modem/drv/teeos
*/
enum MODEM_SECBOOT_IMG_TYPE {
    MODEM_CCPU = 0,
    MODEM_LPMCU,
    MODEM_CCPU_TEE,
    MODEM_CCPU_TEE_PATCH,
    MODEM_FW_DTB,
    MODEM_COMM_IMG = 5,
    MODEM_CCPU_DTB,
    RESERVED_IMG3,
    RESERVED_IMG4,
    RESERVED_IMG5,
    RESERVED_IMG6 = 10,
    MODEM_COLD_PATCH,
    RESERVED_IMG7,
    MODEM_CCPU_DTO = 13,
    MAX_SOC_MODEM,
};

/* ****************************************************************************
 * Attention   END                        *
 * *************************************************************************** */

typedef enum {
    IMAGE_VERIFY_IN,
    IMAGE_VERIFY_OUT,
    ALL_IMAGE_LOAD_DONE,
    LOAD_MAX,
} mloader_stage_e;

/* 回调通知接口形式
   stage：通知当前阶段
   result：通知当前阶段对应的操作结果，0 表示成功，< 0 表示失败
   img_id：通知当前阶段对应的镜像 id
 */
typedef void (*mloader_notifier_func)(mloader_stage_e stage, int result, enum MODEM_SECBOOT_IMG_TYPE img_id);

typedef struct {
    struct list_head list;
    mloader_notifier_func func;
} mloader_notifier_s;

#ifndef BSP_CONFIG_PHONE_TYPE
#define MODEM_START (0x100)
#endif

int bsp_load_modem_images(void);
int bsp_mloader_load_reset(void);

/*
注意!!!!!!!!!!!!!
使用约束
1、分配好 mloader_load_notifier_s 空间后，传入全局变量，否则功能会异常；
2、对于不需要处理的阶段，直接忽略即可，不能当错误处理；
3、不能有耗时较长的操作，避免影响系统启动时间；
*/
int bsp_mloader_notifier_register(mloader_notifier_s *notifier);

/* 获取 modem_fw 分区单板侧路径，不包含目录结尾的"/"
 */
const char *bsp_mloader_get_modem_fw_path(void);

/* 获取 modem_vendor 分区单板侧路径，不包含目录结尾的"/"
 */
const char *bsp_mloader_get_modem_vendor_path(void);

/* 获取镜像签名的大小，单位：Byte
 */
int bsp_mloader_get_vrl_size(void);

/* 获取文件大小，单位：Byte
 */
int bsp_mloader_get_file_size(const char *file_path);

/* 读取文件内容
 */
int bsp_mloader_read_file(const char *file_path, unsigned int offset, unsigned int length, char *buffer);

/* 校验镜像信息初始化
 * image： image 标识，每个镜像唯一
 */
int bsp_mloader_sec_prepare(enum MODEM_SECBOOT_IMG_TYPE image);

/* 加载镜像签名到 TEEOS
 * image： image 标识，每个镜像唯一
 * buf  ： 签名信息的虚拟地址，要求整个签名信息在物理上连续
 * len  ： 签名信息的长度
 */
int bsp_mloader_sec_copy_vrl(enum MODEM_SECBOOT_IMG_TYPE image, void *buf, const u32 len);

/* 加载镜像内容到 TEEOS
 * image： image 标识，每个镜像唯一
 * buf  ： 镜像内容的虚拟地址，要求整个镜像内容在物理上连续
 * ddr_offset：镜像加载到对应独立空间内部的偏移
 * len  ： 签名内容的长度
 */
int bsp_mloader_sec_copy_data(enum MODEM_SECBOOT_IMG_TYPE image, void *buf, const u32 ddr_offset, const u32 len);

/* 通过 TEEOS 校验镜像内容
 * image： image 标识，每个镜像唯一
 */
int bsp_mloader_sec_verify(enum MODEM_SECBOOT_IMG_TYPE image);

/* 加载镜像内容到 TEEOS
 * file_path: 单板侧文件路径
 * image： image 标识，每个镜像唯一
 * ddr_offset：镜像加载到对应独立空间内部的偏移
 */
int bsp_mloader_sec_load_image(const char *file_path, enum MODEM_SECBOOT_IMG_TYPE image, u32 ddr_offset);

/* 加载并校验镜像（包括VRL头+镜像内容）
 * file_name： 镜像的名称，只能在modem_fw目录
 * image：     image 标识，每个镜像唯一
 * ddr_offset：镜像加载到对应独立空间内部的偏移
 */
int bsp_mloader_load_modem_image(char *file_name, enum MODEM_SECBOOT_IMG_TYPE image, const u32 ddr_offset);

/* 获取 modem 镜像的内存地址和大小
 * file_name： 镜像的名称，只能在modem_fw目录
 * phys_addr： 镜像在内存中的物理地址
 * size：      镜像内存空间的大小
 */
int bsp_mloader_get_ddr_region(const char *file_name, unsigned long *phys_addr, u32 *size);

/* 获取 dtb 镜像的内存地址和大小
 * file_name： 镜像的名称，只能在modem_fw目录
 * phys_addr： 镜像在内存中的物理地址
 * size：      镜像内存空间的大小
 */
int bsp_mloader_get_dtb_ddr_region(const char *file_name, unsigned long *phys_addr, u32 *size);
#endif
