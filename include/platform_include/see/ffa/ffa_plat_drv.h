/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: header file for platform drivers ffa interface
 * Create: 2023/03/24
 */

#ifndef _PLAT_DRV_INIT_H
#define _PLAT_DRV_INIT_H

#ifdef CONFIG_ARM_FFA_TRANSPORT

#include <linux/arm_ffa.h>

#define FFA_LOCAL_BUFFER_MAX 4096

/*
 * send message to platdrv sp
 * success: return 0
 */
int ffa_platdrv_send_msg(struct ffa_send_direct_data *args);

/*
 * send message to platdrv sp with share memory
 * only arg0-arg2 can be used
 * local buffer size: u8 local_buf[FFA_LOCAL_BUFFER_MAX]
 * success: return 0
 */
int ffa_platdrv_send_msg_with_shmem(struct ffa_send_direct_data *args,
				    u8 *local_buf, u64 dir);

#else
#include <linux/types.h>

#define FFA_LOCAL_BUFFER_MAX 4096

struct ffa_send_direct_data {
	unsigned long data0; /* w3/x3 */
	unsigned long data1; /* w4/x4 */
	unsigned long data2; /* w5/x5 */
	unsigned long data3; /* w6/x6 */
	unsigned long data4; /* w7/x7 */
};

int ffa_platdrv_send_msg(struct ffa_send_direct_data *args)
{
	return 0;
}

/*
 * send message to platdrv sp with share memory
 * only arg0-arg2 can be used
 * local buffer size: u8 local_buf[FFA_LOCAL_BUFFER_MAX]
 * success: return 0
 */
int ffa_platdrv_send_msg_with_shmem(struct ffa_send_direct_data *args,
				    u8 *local_buf, u64 dir)
{
	return 0;
}

#endif   /* CONFIG_ARM_FFA_TRANSPORT */

#endif  /* _PLAT_DRV_INIT_H */
