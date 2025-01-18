#ifndef __UCE_TCM_STRUCT_H__
#define __UCE_TCM_STRUCT_H__ 
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
typedef struct{
    u32 begin;
    u32 write;
    u32 read;
    u32 end;
} UCE_DDR_TRAIN_TRACK_HEAD_STRU;
typedef struct
{
    u32 uce_id;
    u32 wdt_en;
    u32 info_pack_en;
    u32 retrain_en;
    u32 soft_retrain_en;
    u32 ddr_manu_info;
    u32 print_level;
    u32 uce_uart_dis;
    u32 ddr_train_track_dis;
    UCE_DDR_TRAIN_TRACK_HEAD_STRU ddr_train_track_head;
}UCE_FLAG_STRU;
typedef struct {
 unsigned int init_zcal_err_cnt;
 unsigned int dfs_zcal_err_cnt;
 unsigned int sr_zcal_err_cnt;
 unsigned int zcal_err_cnt;
 unsigned int phyupdate_cnt;
 unsigned int uc_rtactive_cnt;
 unsigned int zcal_finish_wait_cnt;
 unsigned int zcal_finish_wait_max_cnt;
 unsigned int zcal_finish_wait_timeout_cnt;
} UCE_RUNTIME_VAR_STRU;
typedef struct {
 unsigned int first_retrain;
} UCE_DATA_MEM_STRU;
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
