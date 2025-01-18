#ifndef __IMAGE_ENCODE_MAP_H__
#define __IMAGE_ENCODE_MAP_H__ 
#include <stdint.h>
#include "image_id.h"
#ifdef __cplusplus
extern "C" {
#endif
struct image_encode_map {
 struct image_id_t id;
 uint32_t encode;
};
#define ERROR_IMAGE_XLOADER_XLOADER 0xCC000001
#define ERROR_IMAGE_XLOADER_XLOADER1_1 0xCC000002
#define ERROR_IMAGE_INVALID 0xCC00FFFF
static const struct image_encode_map g_map[] = {
 {
  .id = { "xloader", "uce" },
  .encode = 0xCC000003,
 },
 {
  .id = { "lowpower_para", "xloader3" },
  .encode = 0xCC000004,
 },
 {
  .id = { "bl2", "bl2" },
  .encode = 0xCC000005,
 },
 {
  .id = { "fw_gpu_lpctrl", "gxpu" },
  .encode = 0xCC000006,
 },
 {
  .id = { "fw_cpu_lpctrl", "cxpu" },
  .encode = 0xCC000007,
 },
#ifndef CONFIG_UAPP_DFX_IN_XLOADER
 {
  .id = { "trustfirmware", "bl31" },
  .encode = 0xCC000010,
 },
 {
  .id = { "teeos", "trustedcore" },
  .encode = 0xCC000011,
 },
 {
  .id = { "thee", "thee" },
  .encode = 0xCC000012,
 },
 {
  .id = { "tzsp", "tzsp" },
  .encode = 0xCC000013,
 },
 {
  .id = { "hhee", "hhee" },
  .encode = 0xCC000014,
 },
 {
  .id = { "fw_lpm3", "lpm3" },
  .encode = 0xCC000015,
 },
 {
  .id = { "fastboot", "fastboot" },
  .encode = 0xCC000016,
 },
 {
  .id = { "fw_ddr_lpctrl", "ddr_xpu" },
  .encode = 0xCC000017,
 },
 {
  .id = { "dtbo", "dtbo" },
  .encode = 0xCC000018,
 },
 {
  .id = { "sensorhub", "sensorhub" },
  .encode = 0xCC000019,
 },
 {
  .id = { "fw_hifi", "fw_hifi" },
  .encode = 0xCC00001A,
 },
 {
  .id = { "fw_dtb", "fwdtb" },
  .encode = 0xCC00001B,
 },
 {
  .id = { "npu", "npu_fw" },
  .encode = 0xCC00001C,
 },
 {
  .id = { "dacc", "dacc" },
  .encode = 0xCC00001D,
 },
 {
  .id = { "isp_firmware", "secispimage" },
  .encode = 0xCC00001E,
 },
 {
  .id = { "vbmeta", "vbmeta" },
  .encode = 0xCC00001F,
 },
 {
  .id = { "recovery_vbmeta", "vbmeta" },
  .encode = 0xCC000020,
 },
 {
  .id = { "erecovery_vbmeta", "vbmeta" },
  .encode = 0xCC000021,
 },
 {
  .id = { "boot", "dt" },
  .encode = 0xCC000022,
 },
 {
  .id = { "kpatch", "kpatch" },
  .encode = 0xCC000023,
 },
 {
  .id = { "fw_ufsdev", "orig_ufs_emer_fw" },
  .encode = 0xCC000024,
 },
#endif
};
#ifdef __cplusplus
}
#endif
#endif
