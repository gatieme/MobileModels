#ifndef __UAPP_DFX_RECORD_H__
#define __UAPP_DFX_RECORD_H__ 
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
#define UAPP_DFX_MAGIC_HEAD 0x75646D68
struct uapp_dfx_record {
 uint32_t head;
 struct {
  uint32_t cur_stage;
  uint32_t error_stage;
  uint32_t error_image;
  uint32_t error_code;
 } info;
};
#define CUR_STAGE_PRELOADER 0xAA000001
#define CUR_STAGE_XLOADER 0xAA000002
#define CUR_STAGE_INVALID 0xAA00FFFF
#define ERROR_STAGE_PRELOADER 0xBB000001
#define ERROR_STAGE_XLOADER 0xBB000002
#define ERROR_STAGE_BL2 0xBB000003
#define ERROR_STAGE_UEFI 0xBB000004
#define ERROR_STAGE_INVALID 0xBB00FFFF
#ifdef __cplusplus
}
#endif
#endif
