#ifndef __SECINFO_CTX_STRUCT_H__
#define __SECINFO_CTX_STRUCT_H__ 
#include <stdint.h>
#define SECINFO_CTX_MAGIC_NUM 0x5A5A0105
#define UAPP_NONCE_MAX_BYTES 32
#define SECINFO_CTX_RESERVE_BYTES 40
struct secinfo_ctx {
 uint32_t head_magic;
 uint8_t hbk_hash[32];
 uint32_t uapp_enable;
 uint32_t uapp_bindfile_verify;
 uint8_t uapp_nonce[UAPP_NONCE_MAX_BYTES];
 uint8_t uapp_magic_version[8];
 uint8_t uapp_nonce_bc[UAPP_NONCE_MAX_BYTES];
 uint8_t uapp_boot_nonce[UAPP_NONCE_MAX_BYTES];
 uint8_t uapp_upgrade_nonce[UAPP_NONCE_MAX_BYTES];
 uint8_t uapp_magic_version_bc[8];
 uint32_t uapp_ctx_auth_role;
 uint32_t uapp_ctx_match_nonce;
 uint32_t empower_nv;
 uint32_t empower_sevd;
 uint32_t empower_uapp;
 uint32_t empower_force_load;
 uint8_t reserve[SECINFO_CTX_RESERVE_BYTES];
 uint32_t tail_magic;
} __attribute__((__packed__));
#endif
