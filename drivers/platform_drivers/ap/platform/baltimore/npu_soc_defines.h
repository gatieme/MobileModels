#ifndef __NPU_SOC_DEFINES_H__
#define __NPU_SOC_DEFINES_H__ 
enum npu_hwts_sqe_type {
    NPU_HWTS_SQE_AICORE = 0,
    NPU_HWTS_SQE_AICPU = 1,
    NPU_HWTS_SQE_VECTOR_CORE = 2,
    NPU_HWTS_SQE_PLACE_HOLDER = 3,
    NPU_HWTS_SQE_EVENT_RECORD = 4,
    NPU_HWTS_SQE_EVENT_WAIT = 5,
    NPU_HWTS_SQE_NOTIFY_RECORD = 6,
    NPU_HWTS_SQE_NOTIFY_WAIT = 7,
    NPU_HWTS_SQE_WRITE_VALUE = 8,
    NPU_HWTS_SQE_MEMCPY = 9,
    NPU_HWTS_SQE_TYPE_RESV = 12,
};
enum npu_hwts_ph_task_type {
    NPU_HWTS_PH_SQE_NORMAL = 0,
    NPU_HWTS_PH_SQE_LABEL_SWITCH = 1,
    NPU_HWTS_PH_SQE_LABEL_GOTO = 2,
    NPU_HWTS_PH_SQE_TYPE_RESV,
};
struct hwts_sqe_head {
    unsigned int type : 8;
    unsigned int ie : 1;
    unsigned int pre_p : 1;
    unsigned int post_p : 1;
    unsigned int wr_cqe : 1;
    unsigned int rd_cond : 1;
    unsigned int res0 : 1;
    unsigned int l2_lock : 1;
    unsigned int l2_unlock : 1;
    unsigned int block_dim : 16;
    unsigned int stream_id : 16;
    unsigned int task_id : 16;
};
struct hwts_kernel_sqe {
    unsigned int type : 8;
    unsigned int ie : 1;
    unsigned int pre_p : 1;
    unsigned int post_p : 1;
    unsigned int wr_cqe : 1;
    unsigned int rd_cond : 1;
    unsigned int res0 : 1;
    unsigned int l2_lock : 1;
    unsigned int l2_unlock : 1;
    unsigned int block_dim : 16;
    unsigned int stream_id : 16;
    unsigned int task_id : 16;
    unsigned int pc_addr_low;
    unsigned int pc_addr_high : 16;
    unsigned int kernel_credit : 8;
    unsigned int res1 : 3;
    unsigned int icache_prefetch_cnt : 5;
    unsigned int param_addr_low;
    unsigned int param_addr_high : 16;
    unsigned int l2_in_main : 8;
    unsigned int res2 : 8;
    unsigned int literal_addr_low;
    unsigned int literal_addr_high : 16;
    unsigned int res3 : 16;
    unsigned int literal_base_ub;
    unsigned int res4;
    unsigned int literal_buff_len;
    unsigned int res5;
    unsigned int l2_ctrl_addr_low;
    unsigned int l2_ctrl_addr_high : 16;
    unsigned int res6 : 16;
    unsigned char res7[8];
};
struct hwts_label_switch_sqe {
    unsigned long long right;
    unsigned short true_label_idx;
    unsigned char condition;
    unsigned char res0[5];
};
struct hwts_label_goto_sqe {
    unsigned short label_idx;
    unsigned short res0[7];
};
struct hwts_ph_sqe {
    unsigned char type;
    unsigned char ie : 1;
    unsigned char pre_p : 1;
    unsigned char post_p : 1;
    unsigned char wr_cqe : 1;
    unsigned char res0 : 2;
    unsigned char l2_lock : 1;
    unsigned char l2_unlock : 1;
    unsigned short task_type;
    unsigned short stream_id;
    unsigned short task_id;
    union {
        struct hwts_label_switch_sqe label_switch;
        struct hwts_label_goto_sqe label_goto;
    } u;
    unsigned int res2[10];
};
struct hwts_event_sqe {
    unsigned char type;
    unsigned char ie : 1;
    unsigned char pre_p : 1;
    unsigned char post_p : 1;
    unsigned char wr_cqe : 1;
    unsigned char reserved : 2;
    unsigned char l2_lock : 1;
    unsigned char l2_unlock : 1;
    unsigned short res0;
    unsigned short stream_id;
    unsigned short task_id;
    unsigned int event_id : 10;
    unsigned int res1 : 22;
    unsigned int res2 : 16;
    unsigned int kernel_credit : 8;
    unsigned int res3 : 8;
    unsigned int res4[12];
} ;
struct hwts_notify_sqe {
    unsigned char type;
    unsigned char ie : 1;
    unsigned char pre_p : 1;
    unsigned char post_p : 1;
    unsigned char wr_cqe : 1;
    unsigned char reserved : 2;
    unsigned char l2_lock : 1;
    unsigned char l2_unlock : 1;
    unsigned short res0;
    unsigned short stream_id;
    unsigned short task_id;
    unsigned int notify_id : 10;
    unsigned int res1 : 22;
    unsigned int res2 : 16;
    unsigned int kernel_credit : 8;
    unsigned int res3 : 8;
    unsigned int res4[12];
};
struct hwts_write_val_sqe {
    unsigned char type;
    unsigned char ie : 1;
    unsigned char pre_p : 1;
    unsigned char post_p : 1;
    unsigned char wr_cqe : 1;
    unsigned char reserved : 2;
    unsigned char l2_lock : 1;
    unsigned char l2_unlock : 1;
    unsigned short res0;
    unsigned short stream_id;
    unsigned short task_id;
    unsigned int reg_addr_low;
    unsigned short reg_addr_high;
    unsigned short awsize : 3;
    unsigned short snoop : 1;
    unsigned short res1 : 4;
    unsigned short awcache : 4;
    unsigned short awprot : 3;
    unsigned short va : 1;
    unsigned int write_value_low;
    unsigned int write_value_high;
    unsigned int res2[10];
};
struct hwts_memcpy_sqe {
    unsigned char type;
    unsigned char ie : 1;
    unsigned char pre_p : 1;
    unsigned char post_p : 1;
    unsigned char wr_cqe : 1;
    unsigned char reserved : 2;
    unsigned char l2_lock : 1;
    unsigned char l2_unlock : 1;
    unsigned short res0;
    unsigned short stream_id;
    unsigned short task_id;
    unsigned int res1;
    unsigned int res2 : 16;
    unsigned int kernel_credit : 8;
    unsigned int res3 : 8;
    unsigned int ie_dma : 1;
    unsigned int mode : 3;
    unsigned int res4 : 4;
    unsigned int w_pattern : 8;
    unsigned int res5 : 4;
    unsigned int message0 : 12;
    unsigned int src_streamid : 8;
    unsigned int src_substreamid : 8;
    unsigned int dst_streamid : 8;
    unsigned int dst_substreamid : 8;
    unsigned int res6;
    unsigned int length;
    unsigned int src_addr_low;
    unsigned int src_addr_high : 16;
    unsigned int res7 : 15;
    unsigned int src_addr_high_p : 1;
    unsigned int dst_addr_low;
    unsigned int dst_addr_high : 16;
    unsigned int res8 : 15;
    unsigned int dst_addr_high_p : 1;
    unsigned int res10[4];
};
struct hwts_cqe {
    volatile unsigned short p : 1;
    volatile unsigned short w : 1;
    volatile unsigned short evt : 1;
    volatile unsigned short res0 : 1;
    volatile unsigned short sq_id : 10;
    volatile unsigned short res1 : 2;
    volatile unsigned short sq_head;
    volatile unsigned short stream_id;
    volatile unsigned short task_id;
    volatile unsigned int syscnt_low;
    volatile unsigned int syscnt_high;
};
#define AICORE_BASE_ADDR_SHIFT 0x14
#define AICORE_UNLOCK_MAGICNUM 0x19101920
#endif
