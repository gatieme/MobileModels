/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef DATAN_JOBTRACE_TYPE_DESC_H
#define DATAN_JOBTRACE_TYPE_DESC_H
#include "jobtrace_type_defs.h"

enum jobtrace_packet_family {
	JOBTRACE_PACKET_FAMILY_CTRL = 0,
	JOBTRACE_PACKET_FAMILY_DATA = 1,

	JOBTRACE_PACKET_FAMILY_COUNT
};

enum jobtrace_packet_class {
	JOBTRACE_PACKET_CLASS_OBJ = 0,
	JOBTRACE_PACKET_CLASS_AUX = 1,
};

enum jobtrace_packet_type {
	JOBTRACE_PACKET_TYPE_HEADER  = 0,
	JOBTRACE_PACKET_TYPE_BODY    = 1,
	JOBTRACE_PACKET_TYPE_SUMMARY = 2,
};

#define JOBTRACE_STREAM_ID (1)

enum jobtrace_aux_msg_id {
	JOBTRACE_AUX_PM_STATE,
	JOBTRACE_AUX_PAGEFAULT,
	JOBTRACE_AUX_PAGESALLOC,
	JOBTRACE_AUX_DEVFREQ_TARGET,
	JOBTRACE_AUX_PROTECTED_ENTER_START,
	JOBTRACE_AUX_PROTECTED_ENTER_END,
	JOBTRACE_AUX_PROTECTED_LEAVE_START,
	JOBTRACE_AUX_PROTECTED_LEAVE_END,

	JOBTRACE_AUX_CNT
};

#define jobtrace_packet_header_word0(id, type, class, family)    \
	((((id) & PACKET_STREAMID_MASK) << PACKET_STREAMID_POS)   |  \
	(((type) & PACKET_TYPE_MASK) << PACKET_TYPE_POS)          |  \
	(((class) & PACKET_STREAMID_MASK) << PACKET_STREAMID_POS) |  \
	(((family) & PACKET_FAMILY_MASK) << PACKET_FAMILY_POS))

#define JOBTRACE_PACKET_OBJ_DECL_HEADER_WORD0                           \
	jobtrace_packet_header_word0(JOBTRACE_STREAM_ID, JOBTRACE_PACKET_TYPE_HEADER, \
		JOBTRACE_PACKET_CLASS_OBJ, JOBTRACE_PACKET_FAMILY_DATA)

#define JOBTRACE_PACKET_OBJ_SUM_HEADER_WORD0                            \
	jobtrace_packet_header_word0(JOBTRACE_STREAM_ID, JOBTRACE_PACKET_TYPE_SUMMARY, \
		JOBTRACE_PACKET_CLASS_OBJ, JOBTRACE_PACKET_FAMILY_DATA)

#define JOBTRACE_PACKET_OBJ_HEADER_WORD0                                \
	jobtrace_packet_header_word0(JOBTRACE_STREAM_ID, JOBTRACE_PACKET_TYPE_BODY, \
		JOBTRACE_PACKET_CLASS_OBJ, JOBTRACE_PACKET_FAMILY_DATA)

#define JOBTRACE_PACKET_AUX_DECL_HEADER_WORD0                           \
	jobtrace_packet_header_word0(JOBTRACE_STREAM_ID, JOBTRACE_PACKET_TYPE_HEADER, \
		JOBTRACE_PACKET_CLASS_AUX, JOBTRACE_PACKET_FAMILY_DATA)

#define JOBTRACE_PACKET_AUX_HEADER_WORD0                                \
	jobtrace_packet_header_word0(JOBTRACE_STREAM_ID, JOBTRACE_PACKET_TYPE_BODY, \
		JOBTRACE_PACKET_CLASS_AUX, JOBTRACE_PACKET_FAMILY_DATA)

struct jobtrace_desc {
	int id;
	const char *id_str;
	const char *name;
	const char *arg_types;
	const char *arg_names;
};

#define to_string(s) #s

static const struct jobtrace_desc g_jobtrace_desc_obj[JOBTRACE_OBJ_CNT] = {
	{
		KDATAN_TL_NEW_CTX,
		to_string(KDATAN_TL_NEW_CTX),
		"object ctx is created",
		"@pII",
		"kctx,kctx_nr,tgid"
	},
	{
		KDATAN_TL_RET_AS_CTX,
		to_string(KDATAN_TL_RET_AS_CTX),
		"address space is retained by context",
		"@pI",
		"kctx,asid"
	},
	{
		KDATAN_TL_WRITE_REG,
		to_string(KDATAN_TL_WRITE_REG),
		"write reg",
		"@pII",
		"kctx,offset,value"
	},
	{
		KDATAN_TL_ATTRIB_AS_CONFIG,
		to_string(KDATAN_TL_ATTRIB_AS_CONFIG),
		"address space attributes",
		"@pILLL",
		"kctx,asid,transtab,memattr,transcfg"
	},
	{
		KDATAN_TL_RET_QUEUE_CHANNEL,
		to_string(KDATAN_TL_RET_QUEUE_CHANNEL),
		"command queue 's queue id and channel id",
		"@pII",
		"kctx,queue_id,channel_id"
	},
	{
		KDATAN_TL_SUBMIT_QUEUE,
		to_string(KDATAN_TL_SUBMIT_QUEUE),
		"kmd submit command queue to GPU",
		"@pI",
		"kctx,queue_id"
	},
	{
		KDATAN_TL_NEW_WAIT_IRQ,
		to_string(KDATAN_TL_NEW_WAIT_IRQ),
		"wait cq irq",
		"@pIIII",
		"kctx,queue_id,channel_id,irq_type,cq_bind_register_value"
	},
	{
		KDATAN_JD_UPDATE_JIT_MEMORY,
		to_string(KDATAN_JD_UPDATE_JIT_MEMORY),
		"kmd alloc jit memory",
		"@pLLII",
		"kctx,heap_ptr,jit_mem,jit_size,queue_id"
	},
	{
		KDATAN_TL_DUMP_FW,
		to_string(KDATAN_TL_DUMP_FW),
		"dump firmware",
		"@psLI",
		"kctx,filepath,addr,size"
	},
	{
		KDATAN_TL_WAIT_CMD_DONE,
		to_string(KDATAN_TL_WAIT_CMD_DONE),
		"wait cmd done",
		"@psLI",
		"kctx,cmd,reg,value"
	},
	{
		KDATAN_JD_DUMP_FCP_PT,
		to_string(KDATAN_JD_DUMP_FCP_PT),
		"dump fcp pagetable",
		"@ps",
		"kctx,filepath"
	},
	{
		KDATAN_JD_DUMP_PT,
		to_string(KDATAN_JD_DUMP_PT),
		"dump pagetable",
		"@ps",
		"kctx,filepath"
	},
	{
		KDATAN_JD_DUMP_CD,
		to_string(KDATAN_JD_DUMP_CD),
		"dump cd",
		"@psLL",
		"kctx,filepath,start_addr,mem_size"
	},
	{
		KDATAN_JD_DUMP_CMDQ,
		to_string(KDATAN_JD_DUMP_CMDQ),
		"dump cmdq",
		"@psLL",
		"kctx,filepath,start_addr,mem_size"
	},
	{
		KDATAN_SET_PTR,
		to_string(KDATAN_SET_PTR),
		"set pointer",
		"@pLLsI",
		"kctx,addr,value,tag,queue_id"
	},
	{
		KDATAN_SET_GET_INDEX,
		to_string(KDATAN_SET_GET_INDEX),
		"set pointer",
		"@pIII",
		"kctx,queue_id,put_idx,get_idx"
	},
	{
		KDATAN_SET_PUT_IDX,
		to_string(KDATAN_SET_PUT_IDX),
		"submit entry, recorde put_idx",
		"@pII",
		"ctx,queue_id,put_idx"
	},
};

static const struct jobtrace_desc g_jobtrace_desc_aux[JOBTRACE_AUX_CNT] = {
	{
		JOBTRACE_AUX_PM_STATE,
		to_string(JOBTRACE_AUX_PM_STATE),
		"PM state",
		"@IL",
		"core_type,core_state_bitset"
	},
	{
		JOBTRACE_AUX_PAGEFAULT,
		to_string(JOBTRACE_AUX_PAGEFAULT),
		"Page fault",
		"@IL",
		"ctx_nr,page_cnt_change"
	},
	{
		JOBTRACE_AUX_PAGESALLOC,
		to_string(JOBTRACE_AUX_PAGESALLOC),
		"Total alloc pages change",
		"@IL",
		"ctx_nr,page_cnt"
	},
	{
		JOBTRACE_AUX_DEVFREQ_TARGET,
		to_string(JOBTRACE_AUX_DEVFREQ_TARGET),
		"New device frequency target",
		"@L",
		"target_freq"
	},
	{
		JOBTRACE_AUX_PROTECTED_ENTER_START,
		to_string(JOBTRACE_AUX_PROTECTED_ENTER_START),
		"enter protected mode start",
		"@p",
		"gpu"
	},
	{
		JOBTRACE_AUX_PROTECTED_ENTER_END,
		to_string(JOBTRACE_AUX_PROTECTED_ENTER_END),
		"enter protected mode end",
		"@p",
		"gpu"
	},
	{
		JOBTRACE_AUX_PROTECTED_LEAVE_START,
		to_string(JOBTRACE_AUX_PROTECTED_LEAVE_START),
		"leave protected mode start",
		"@p",
		"gpu"
	},
	{
		JOBTRACE_AUX_PROTECTED_LEAVE_END,
		to_string(JOBTRACE_AUX_PROTECTED_LEAVE_END),
		"leave protected mode end",
		"@p",
		"gpu"
	}
};

#undef to_string

#endif

