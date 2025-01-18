/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_CQ_DEFS_H
#define HVGR_CQ_DEFS_H

#include "linux/types.h"
#include "apicmd/hvgr_ioctl_mem.h"

#define CQ_QUEUE_ID_INVALID                          0
#define CQ_CHANNEL_NUM                               4
#define CQ_CHANNEL0                                  0
#define CQ_CHANNEL1                                  1
#define CQ_CHANNEL2                                  2
#define CQ_CHANNEL3                                  3
#define CQ_CHANNEL_ID_INVALID                        ((uint32_t)-1)
#define CQ_QUEUE_NUM_PER_CTX                         8

#define CQ_HW_WRITEABLE_CONTEXT_SIZE                 (48 * 1024)

#define CQ_ERR_FLOW_TOKEN_VALUE              0xFFFFFFFFU

#define TOKEN_NUMS    4096u
#define CQ_SYNC_TOKEN_NUMS    TOKEN_NUMS

#define CQ_ERROR              1
#define CQ_ERROR_NONE         0

enum cq_irq_counter_idx {
	CQ_IRQ_COUNTER_DONE = 0,
	CQ_IRQ_COUNTER_NOTIFY,
	CQ_IRQ_COUNTER_STOP,
	CQ_IRQ_COUNTER_EMPTY_TIMEOUT,
	CQ_IRQ_COUNTER_WAIT_TIMEOUT,
	CQ_IRQ_COUNTER_SUBQUEUE,
	CQ_IRQ_COUNTER_SYNC_BUFF_FULL,
	CQ_IRQ_COUNTER_ORDER_BUFF_FULL,
	CQ_IRQ_COUNTER_ENTRY_BOUNDARY,
	CQ_IRQ_COUNTER_MAX,
};

/* The cq_status share between KMD and UMD */
struct hvgr_cq_status {
	uint32_t err_flags;
};

struct cq_ring_buf {
	uint64_t reserve1;
	uint64_t ring_buf_w_ptr;
	uint64_t ring_buf_r_ptr;
	uint8_t reserve2[40]; /* reserve 320bits */

	uint8_t jcd_array[4][64]; /* Jcd buffer size is 512bits * 4 */

	/* Follow memory is ptr_buf array */
};

/* Hardware need start address align to 64Bytes */
#define CQ_RINGBUF_ALIGN_BYTES 64u
#define cq_ringbuf_align(size) \
	(((size) + (CQ_RINGBUF_ALIGN_BYTES - 1)) & (~(CQ_RINGBUF_ALIGN_BYTES - 1)))

/* Job ptr_buffer size is 64 bits, unit is byte */
#define CQ_RINGBUF_ENTRY_SIZE 8u

#define CQ_REND_RING_ENTRY_NUMS     8u
#define CQ_REND_RING_BUF_SIZE \
	cq_ringbuf_align(sizeof(struct cq_ring_buf) + \
		CQ_RINGBUF_ENTRY_SIZE * CQ_REND_RING_ENTRY_NUMS)

#define CQ_BIN_RING_ENTRY_NUMS      16u
#define CQ_BIN_RING_BUF_SIZE \
	cq_ringbuf_align(sizeof(struct cq_ring_buf) + \
		CQ_RINGBUF_ENTRY_SIZE * CQ_BIN_RING_ENTRY_NUMS)

#define CQ_COMPUTER_RING_ENTRY_NUMS 8u
#define CQ_COMPUTER_RING_BUF_SIZE \
	cq_ringbuf_align(sizeof(struct cq_ring_buf) + \
		CQ_RINGBUF_ENTRY_SIZE * CQ_COMPUTER_RING_ENTRY_NUMS)

#define CQ_BVHG_RING_ENTRY_NUMS     8u
#define CQ_BVHG_RING_BUF_SIZE \
	cq_ringbuf_align(sizeof(struct cq_ring_buf) + \
		CQ_RINGBUF_ENTRY_SIZE * CQ_BVHG_RING_ENTRY_NUMS)

#define CQ_RT_RING_ENTRY_NUMS       8u
#define CQ_RT_RING_BUF_SIZE \
	cq_ringbuf_align(sizeof(struct cq_ring_buf) + CQ_RINGBUF_ENTRY_SIZE * CQ_RT_RING_ENTRY_NUMS)

#define CQ_CMD_ENTRY_BUFFER_MEM_PROP HVGR_MEM_PROPERTY_4G_VA

struct cq_sw_writeable_context {
	uint64_t hw_context_address;
	uint64_t queue_base_address;
	uint32_t queue_max_num_entries;
	uint32_t queue_put_index;
	uint32_t queue_get_index;
	uint32_t priority;
	uint32_t defer_cs_issue_en;
	uint32_t warp_priority;

	uint32_t reserve1[6]; /* reserve 192 bit */

	struct {
		uint64_t rend_ring_buf_struct_ptr;
		uint32_t rend_ring_buf_struct_size;
		uint32_t reserve0;

		uint64_t bin_ring_buf_struct_ptr;
		uint32_t bin_ring_buf_struct_size;
		uint32_t reserve1;

		uint64_t comp_ring_buf_struct_ptr;
		uint32_t comp_ring_buf_struct_size;
		uint32_t reserve2;

		uint64_t bvhg_ring_buf_struct_ptr;
		uint32_t bvhg_ring_buf_struct_size;
		uint32_t reserve3;

		uint64_t rt_ring_buf_struct_ptr;
		uint32_t rt_ring_buf_struct_size;
		uint32_t reserve4;

		uint64_t ring_buf_struct_ptr_1;
		uint32_t ring_buf_struct_size_1;
		uint32_t reserve5;

		uint64_t ring_buf_struct_ptr_2;
		uint32_t ring_buf_struct_size_2;
		uint32_t reserve6;

		uint64_t ring_buf_struct_ptr_3;
		uint32_t ring_buf_struct_size_3;
		uint32_t reserve7;
	} ring_buffer;

	struct {
		uint64_t order_buf_ptr;
		uint32_t order_buf_size;
		uint32_t reserve0;

		uint64_t sync_buf_ptr;
		uint32_t sync_buf_size;
		uint32_t reserve1;

		uint32_t reserve3[8];
	} dfx_buf_info;

	uint8_t sw_reserve[64]; /* reserve: 512 bit */
	uint32_t wait_entry_info[208];
	uint32_t entry_done[512];
};

enum cq_priority {
	CQ_GLOBAL_PRIORITY_LOW_COMPUTE_L = 0,
	CQ_GLOBAL_PRIORITY_LOW_COMPUTE_H,
	CQ_GLOBAL_PRIORITY_MEDIUM_COMPUTE_L,
	CQ_GLOBAL_PRIORITY_MEDIUM_COMPUTE_H,
	CQ_GLOBAL_PRIORITY_HIGH_COMPUTE_L,
	CQ_GLOBAL_PRIORITY_HIGH_COMPUTE_H,
	CQ_GLOBAL_PRIORITY_REALTIME_COMPUTE_L,
	CQ_GLOBAL_PRIORITY_REALTIME_COMPUTE_H,
	CQ_PRIORITY_MAX,
};

#define CQ_PRIORITY_LOW CQ_GLOBAL_PRIORITY_LOW_COMPUTE_L
#define CQ_PRIORITY_HIGH CQ_GLOBAL_PRIORITY_REALTIME_COMPUTE_H

#endif
