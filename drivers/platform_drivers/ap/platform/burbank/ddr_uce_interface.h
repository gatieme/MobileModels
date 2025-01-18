#ifndef __DDR_UCE_INTERFACE__H__
#define __DDR_UCE_INTERFACE__H__ 
typedef struct {
 unsigned int rdet_en : 1;
 unsigned int wdet_en : 1;
 unsigned int ct_dqs_en : 1;
 unsigned int av_en : 1;
 unsigned int cat_en : 1;
 unsigned int byte_swap : 1;
 unsigned int cat_eyet_rb_opt : 1;
 unsigned int dm_dis : 1;
 unsigned int target_freq_idx : 4;
 unsigned int wl_en : 1;
 unsigned int wl2_en : 1;
 unsigned int cst_en : 1;
 unsigned int rdet_bdl_normalize :1 ;
 unsigned int rdet_type:1 ;
 unsigned int rdqdcc_en: 1;
 unsigned int rdqsdit_en: 1;
 unsigned int rdq_duty_en: 1;
 unsigned int dca_duty_en: 1;
 unsigned int rd_test_mode: 1;
 unsigned int rdqsdcc : 4;
 unsigned int rdet_mode: 1;
 unsigned int rdqdcc_evenodd: 1;
 unsigned int cat_byte_idx: 1;
 unsigned int reserved2: 3;
} init_train_ctrl_str;
typedef struct {
 unsigned int reserved : 8;
 unsigned int target_freq_idx : 4;
 unsigned int reserved0 : 4;
 unsigned int reserved1 : 15;
 unsigned int trfc_stop : 1;
} retrain_ctrl_str;
typedef struct {
 unsigned int step1 : 1;
 unsigned int step2 : 1;
 unsigned int is_core_vol_rise : 1;
 unsigned int is_vdd2h_dvs : 1;
 unsigned int current_train_para_idx : 4;
 unsigned int target_freq_idx : 4;
 unsigned int current_freq_idx : 4;
 unsigned int is_vdd2h_dvs_first:1;
 unsigned int reserved0 : 1;
 unsigned int is_fasttrain_conversion : 1;
 unsigned int wr_sel : 2;
 unsigned int target_train_para_idx : 4;
 unsigned int op_sel : 2;
 unsigned int is_simple_dfs : 1;
 unsigned int is_section_dfs_first : 1;
 unsigned int is_dvfs_slowly : 1;
 unsigned int reserved1 : 1;
 unsigned int trfc_stop : 1;
} dfs_ctrl_str;
typedef union {
 unsigned int value;
 init_train_ctrl_str init_train_ctrl;
 retrain_ctrl_str retrain_ctrl;
 dfs_ctrl_str dfs_ctrl;
} lpm3_uce_proc_ctrl_union;
typedef struct {
 unsigned char det_finished : 1;
 unsigned char det_result : 5;
 unsigned char reserved : 2;
} init_train_stat_str;
typedef struct {
 unsigned char reserved : 5;
 unsigned char trfc_process : 1;
 unsigned char sfrt_stat : 1;
 unsigned char reserved1 : 1;
} retrain_stat_str;
typedef struct {
 unsigned char step1_finished : 1;
 unsigned char step2_finished : 1;
 unsigned char reserved : 6;
} dfs_stat_str;
typedef union {
 unsigned int value;
 init_train_stat_str init_train_stat;
 retrain_stat_str retrain_stat;
 dfs_stat_str dfs_stat;
} uce_proc_stat_union;
typedef union {
 unsigned int value;
 init_train_stat_str init_train_stat[PACK_MAX_NUM];
 retrain_stat_str retrain_stat[PACK_MAX_NUM];
 dfs_stat_str dfs_stat[PACK_MAX_NUM];
} lpm3_proc_stat_union;
typedef struct {
 unsigned short wdqphase;
 unsigned short wdqbdl;
} wdet_boundary_str;
typedef struct {
 unsigned short rdqsbdl[2];
} rdet_boundary_str;
typedef struct {
 unsigned short ca_cs_phase;
 unsigned short ca_cs_bdl;
} cat_boundary_str;
typedef union {
 unsigned int value;
 wdet_boundary_str wdet_boundary;
 rdet_boundary_str rdet_boundary;
 cat_boundary_str cat_boundary;
 cat_boundary_str cst_boundary;
} uce_train_result_union;
#define RDERT_RESULT_MB_CH 0
#define WDERT_RESULT_MB_CH 1
#define RDET_BOUNDARY_MB_CH 0
#define WDET_LEFT_BOUNDARY_MB_CH 1
#define WDET_RIGHT_BOUNDARY_MB_CH 3
#define WDET_BDL_MB_CH 2
#define CAT_BOUNDARY_MB_CH 0
#define RDQDCC_MB_CH0 0
#define RDQDCC_MB_CH1 1
#define RDQDCC_MB_CH2 2
#define RDERT_RESULT_DATA_IDX 0
#define WDERT_RESULT_DATA_IDX 0
#define WDET_LB_DATA_IDX 0
#define WDET_RB_DATA_IDX 1
#define RDET_LB_DATA_IDX 0
#define RDET_RB_DATA_IDX 1
#define CAT_LB_DATA_IDX 0
#define CAT_RB_DATA_IDX 1
#endif
