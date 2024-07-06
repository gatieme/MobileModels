/*
 *  Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 *  Description: the partition table.
 */

#ifndef _ANTLIA_CDC_PLAT_PARTITION_H_
#define _ANTLIA_CDC_PLAT_PARTITION_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static struct partition partition_table_ufs[] = {
    {PART_XLOADER_A,                        0,      2 * 1024,      UFS_PART_0},
    {PART_XLOADER_B,                        0,      2 * 1024,      UFS_PART_1},
    {PART_PTABLE,                           0,           512,      UFS_PART_2}, /* ptable             512K    p0 */
    {PART_VRL_A,                          512,           512,      UFS_PART_2}, /* vrl_a              512K    p1 */
    {PART_VRL_BACKUP_A,               2 * 512,           512,      UFS_PART_2}, /* vrl backup_a       512K    p2 */
    {PART_RESERVED1,                  3 * 512,           512,      UFS_PART_2}, /* reserved1          512K    p3 */
    {PART_NPU_A,                     2 * 1024,      8 * 1024,      UFS_PART_2}, /* npu_a                8M    p4 */
    {PART_HIEPS_A,                  10 * 1024,      2 * 1024,      UFS_PART_2}, /* hieps_a              2M    p5 */
    {PART_IVP_A,                    12 * 1024,      2 * 1024,      UFS_PART_2}, /* ivp_a                2M    p6 */
    {PART_HDCP_A,                   14 * 1024,      1 * 1024,      UFS_PART_2}, /* PART_HDCP_a          1M    p7 */
    {PART_HISEE_IMG_A,              15 * 1024,      4 * 1024,      UFS_PART_2}, /* part_hisee_img_a     4M    p8 */
    {PART_HHEE_A,                   19 * 1024,      4 * 1024,      UFS_PART_2}, /* hhee_a               4M    p9 */
    {PART_FASTBOOT_A,               23 * 1024,     12 * 1024,      UFS_PART_2}, /* fastboot_a          12M    p10 */
    {PART_LOWPOWER_PARA_A,          35 * 1024,      1 * 1024,      UFS_PART_2}, /* lowpower_para_a      1M    p11 */
    {PART_BL2_A,                    36 * 1024,      4 * 1024,      UFS_PART_2}, /* bl2_a                4M    p12 */
    {PART_TEEOS_A,                  40 * 1024,      8 * 1024,      UFS_PART_2}, /* teeos_a              8M    p13 */
    {PART_FW_LPM3_A,                48 * 1024,           512,      UFS_PART_2}, /* fw_lpm3_a          512K    p14 */
    {PART_FW_CPU_LPCTRL_A,  (48 * 1024 + 512),           256,      UFS_PART_2}, /* fw_cpu_lpctrl      256K    p15 */
    {PART_FW_GPU_LPCTRL_A,  (48 * 1024 + 768),           128,      UFS_PART_2}, /* fw_gpu_lpctrl      128K    p16 */
    {PART_FW_DDR_LPCTRL_A,  (48 * 1024 + 896),           128,      UFS_PART_2}, /* fw_ddr_lpctrl      128K    p17 */
    {PART_HISEE_FS_A,               49 * 1024,      8 * 1024,      UFS_PART_2}, /* hisee_fs_a           8M    p18 */
    {PART_VECTOR_A,                 57 * 1024,      4 * 1024,      UFS_PART_2}, /* vector_a             4M    p19 */
    {PART_ISP_BOOT_A,               61 * 1024,      2 * 1024,      UFS_PART_2}, /* isp_boot_a           2M    p20 */
    {PART_ISP_FIRMWARE_A,           63 * 1024,     14 * 1024,      UFS_PART_2}, /* isp_firmware_a      14M    p21 */
    {PART_FW_HIFI_A,                77 * 1024,     12 * 1024,      UFS_PART_2}, /* hifi_a              12M    p22 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK_A,      89 * 1024,     12 * 1024,      UFS_PART_2}, /* erecovery_ramdisk_a 12M    p23 */
    {PART_ERECOVERY_VENDOR_A,      101 * 1024,      8 * 1024,      UFS_PART_2}, /* erecovery_vendor_a   8M    p24 */
    {PART_BOOT_A,                  109 * 1024,     65 * 1024,      UFS_PART_2}, /* boot_a              65M    p25 */
    {PART_RECOVERY_A,              174 * 1024,     85 * 1024,      UFS_PART_2}, /* recovery_a          85M    p26 */
    {PART_ERECOVERY_A,             259 * 1024,     12 * 1024,      UFS_PART_2}, /* erecovery_a         12M    p27 */
    {PART_KPATCH_A,                271 * 1024,     29 * 1024,      UFS_PART_2}, /* kpatch_a            29M    p28 */
#else
    {PART_ERECOVERY_RAMDISK_A,      89 * 1024,     32 * 1024,      UFS_PART_2}, /* erecovery_ramdisk_a 32M    p23 */
    {PART_ERECOVERY_VENDOR_A,      121 * 1024,     24 * 1024,      UFS_PART_2}, /* erecovery_vendor_a  16M    p24 */
    {PART_BOOT_A,                  145 * 1024,     30 * 1024,      UFS_PART_2}, /* boot_a              25M    p25 */
    {PART_RECOVERY_A,              175 * 1024,     45 * 1024,      UFS_PART_2}, /* recovery_a          45M    p26 */
    {PART_ERECOVERY_A,             220 * 1024,     45 * 1024,      UFS_PART_2}, /* erecovery_a         45M    p27 */
    {PART_KPATCH_A,                265 * 1024,     35 * 1024,      UFS_PART_2}, /* kpatch_a            48M    p28 */
#endif
    {PART_ENG_SYSTEM_A,            300 * 1024,     12 * 1024,      UFS_PART_2}, /* eng_system_a        12M    p29 */
    {PART_RAMDISK_A,               312 * 1024,      2 * 1024,      UFS_PART_2}, /* ramdisk_a            2M    p30 */
    {PART_VBMETA_SYSTEM_A,         314 * 1024,      1 * 1024,      UFS_PART_2}, /* vbmeta_system_a      1M    p31 */
    {PART_VBMETA_VENDOR_A,         315 * 1024,      1 * 1024,      UFS_PART_2}, /* vbmeta_vendor_a      1M    p32 */
    {PART_VBMETA_ODM_A,            316 * 1024,      1 * 1024,      UFS_PART_2}, /* vbmeta_odm_a         1M    p33 */
    {PART_VBMETA_CUST_A,           317 * 1024,      1 * 1024,      UFS_PART_2}, /* vbmeta_cus_a         1M    p34 */
    {PART_VBMETA_HW_PRODUCT_A,     318 * 1024,      1 * 1024,      UFS_PART_2}, /* vbmeta_hw_product_a  1M    p35 */
    {PART_RECOVERY_RAMDISK_A,      319 * 1024,     32 * 1024,      UFS_PART_2}, /* recovery_ramdisk_a  32M    p36 */
    {PART_RECOVERY_VENDOR_A,       351 * 1024,     24 * 1024,      UFS_PART_2}, /* recovery_vendor_a   24M    p37 */
    {PART_DTBO_A,                  375 * 1024,     20 * 1024,      UFS_PART_2}, /* dtoimage_a          20M    p38 */
    {PART_ENG_VENDOR_A,            395 * 1024,     20 * 1024,      UFS_PART_2}, /* eng_vendor_a        20M    p39 */
    {PART_SECURITY_DTB_A,          415 * 1024,      2 * 1024,      UFS_PART_2}, /* security_dtb_a       2M    p40 */
    {PART_FW_DTB_A,                417 * 1024,      8 * 1024,      UFS_PART_2}, /* fw_dtb_a             8M    p41 */
    {PART_TRUSTFIRMWARE_A,         425 * 1024,      2 * 1024,      UFS_PART_2}, /* trustfirmware_a      2M    p42 */
    {PART_RECOVERY_VBMETA_A,       427 * 1024,      2 * 1024,      UFS_PART_2}, /* recovery_vbmeta_a    2M    p43 */
    {PART_ERECOVERY_VBMETA_A,      429 * 1024,      2 * 1024,      UFS_PART_2}, /* erecovery_vbmeta_a   2M    p44 */
    {PART_VBMETA_A,                431 * 1024,      4 * 1024,      UFS_PART_2}, /* PART_VBMETA_a        4M    p45 */
    {PART_PATCH_A,                 435 * 1024,     32 * 1024,      UFS_PART_2}, /* patch_a             32M    p46 */
    {PART_PREAS_A,                 467 * 1024,   1280 * 1024,      UFS_PART_2}, /* preas_a           1280M    p47 */
    {PART_PREAVS_A,               1747 * 1024,     32 * 1024,      UFS_PART_2}, /* preavs_a            32M    p48 */
    {PART_VERSION_A,              1779 * 1024,    576 * 1024,      UFS_PART_2}, /* version_a          576M    p49 */
    {PART_PRELOAD_A,              2355 * 1024,   1144 * 1024,      UFS_PART_2}, /* preload_a         1144M    p50 */
    {PART_SAFETY_ISLAND_A,        3499 * 1024,      4 * 1024,      UFS_PART_2}, /* safety_island_a      4M    p51 */
    {PART_THEE_A,                 3503 * 1024,      4 * 1024,      UFS_PART_2}, /* thee                 4M    p52 */
    {PART_TZSP_A,                 3507 * 1024,     12 * 1024,      UFS_PART_2}, /* tzsp                12M    p53 */
    {PART_SENSORHUB_A,            3519 * 1024,     16 * 1024,      UFS_PART_2}, /* sensorhub           16M    p54 */
    {PART_DICE_A,                 3535 * 1024,      1 * 1024,      UFS_PART_2}, /* die_a                1M    p55 */
    {PART_DACC_A,                 3536 * 1024,           256,      UFS_PART_2}, /* dacc_a             256K    p56 */
    {PART_DACC_LITE_A,    (3536 * 1024 + 256),           256,      UFS_PART_2}, /* dacc_lite_a        256K    p56 */
    {PART_VENC_A,         (3536 * 1024 + 512),           512,      UFS_PART_2}, /* venc_a             512K    p57 */
    {PART_DDR_XPU_BOOT0_A,        3537 * 1024,           136,      UFS_PART_2}, /* ddr_xpu_boot0_a    136K    p13 */
    {PART_DDR_XPU_BOOT1_A,(3537 * 1024 + 136),           136,      UFS_PART_2}, /* ddr_xpu_boot1_a    136K    p13 */
    {PART_PTABLE_LU3,                       0,           512,      UFS_PART_3}, /* ptable             512K    p0 */
    {PART_VRL_B,                          512,           512,      UFS_PART_3}, /* vrl_b              512K    p1 */
    {PART_VRL_BACKUP_B,               2 * 512,           512,      UFS_PART_3}, /* vrl backup_b       512K    p2 */
    {PART_RESERVED2,                  3 * 512,           512,      UFS_PART_3}, /* reserved2          512K    p3 */
    {PART_NPU_B,                     2 * 1024,      8 * 1024,      UFS_PART_3}, /* npu_b                8M    p4 */
    {PART_HIEPS_B,                  10 * 1024,      2 * 1024,      UFS_PART_3}, /* hieps_b              2M    p5 */
    {PART_IVP_B,                    12 * 1024,      2 * 1024,      UFS_PART_3}, /* ivp_b                2M    p6 */
    {PART_HDCP_B,                   14 * 1024,      1 * 1024,      UFS_PART_3}, /* PART_HDCP_b          1M    p7 */
    {PART_HISEE_IMG_B,              15 * 1024,      4 * 1024,      UFS_PART_3}, /* part_hisee_img_b     4M    p8 */
    {PART_HHEE_B,                   19 * 1024,      4 * 1024,      UFS_PART_3}, /* hhee_b               4M    p9 */
    {PART_FASTBOOT_B,               23 * 1024,     12 * 1024,      UFS_PART_3}, /* fastboot_b          12M    p10 */
    {PART_LOWPOWER_PARA_B,          35 * 1024,      1 * 1024,      UFS_PART_3}, /* lowpower_para_b      1M    p11 */
    {PART_BL2_B,                    36 * 1024,      4 * 1024,      UFS_PART_3}, /* bl2_b                4M    p12 */
    {PART_TEEOS_B,                  40 * 1024,      8 * 1024,      UFS_PART_3}, /* teeos_b              8M    p13 */
    {PART_FW_LPM3_B,                48 * 1024,           512,      UFS_PART_3}, /* fw_lpm3_b          512K    p14 */
    {PART_FW_CPU_LPCTRL_B,  (48 * 1024 + 512),           256,      UFS_PART_3}, /* fw_cpu_lpctrl      256K    p15 */
    {PART_FW_GPU_LPCTRL_B,  (48 * 1024 + 768),           128,      UFS_PART_3}, /* fw_gpu_lpctrl      128K    p16 */
    {PART_FW_DDR_LPCTRL_B,  (48 * 1024 + 896),           128,      UFS_PART_3}, /* fw_ddr_lpctrl      128K    p17 */
    {PART_HISEE_FS_B,               49 * 1024,      8 * 1024,      UFS_PART_3}, /* hisee_fs_b           8M    p18 */
    {PART_VECTOR_B,                 57 * 1024,      4 * 1024,      UFS_PART_3}, /* vector_b             4M    p19 */
    {PART_ISP_BOOT_B,               61 * 1024,      2 * 1024,      UFS_PART_3}, /* isp_boot_b           2M    p20 */
    {PART_ISP_FIRMWARE_B,           63 * 1024,     14 * 1024,      UFS_PART_3}, /* isp_firmware_b      14M    p21 */
    {PART_FW_HIFI_B,                77 * 1024,     12 * 1024,      UFS_PART_3}, /* hifi_b              12M    p22 */
#ifdef CONFIG_SANITIZER_ENABLE
    {PART_ERECOVERY_RAMDISK_B,      89 * 1024,     12 * 1024,      UFS_PART_3}, /* erecovery_ramdisk_b 12M    p23 */
    {PART_ERECOVERY_VENDOR_B,      101 * 1024,      8 * 1024,      UFS_PART_3}, /* erecovery_vendor_b   8M    p24 */
    {PART_BOOT_B,                  109 * 1024,     65 * 1024,      UFS_PART_3}, /* boot_b              65M    p25 */
    {PART_RECOVERY_B,              174 * 1024,     85 * 1024,      UFS_PART_3}, /* recovery_b          85M    p26 */
    {PART_ERECOVERY_B,             259 * 1024,     12 * 1024,      UFS_PART_3}, /* erecovery_b         12M    p27 */
    {PART_KPATCH_B,                271 * 1024,     29 * 1024,      UFS_PART_3}, /* kpatch_b            29M    p28 */
#else
    {PART_ERECOVERY_RAMDISK_B,      89 * 1024,     32 * 1024,      UFS_PART_3}, /* erecovery_ramdisk_b 32M    p23 */
    {PART_ERECOVERY_VENDOR_B,      121 * 1024,     24 * 1024,      UFS_PART_3}, /* erecovery_vendor_b  16M    p24 */
    {PART_BOOT_B,                  145 * 1024,     30 * 1024,      UFS_PART_3}, /* boot_b              25M    p25 */
    {PART_RECOVERY_B,              175 * 1024,     45 * 1024,      UFS_PART_3}, /* recovery_b          45M    p26 */
    {PART_ERECOVERY_B,             220 * 1024,     45 * 1024,      UFS_PART_3}, /* erecovery_b         45M    p27 */
    {PART_KPATCH_B,                265 * 1024,     35 * 1024,      UFS_PART_3}, /* kpatch_b            48M    p28 */
#endif
    {PART_ENG_SYSTEM_B,            300 * 1024,     12 * 1024,      UFS_PART_3}, /* eng_system_b        12M    p29 */
    {PART_RAMDISK_B,               312 * 1024,      2 * 1024,      UFS_PART_3}, /* ramdisk_b            2M    p30 */
    {PART_VBMETA_SYSTEM_B,         314 * 1024,      1 * 1024,      UFS_PART_3}, /* vbmeta_system_b      1M    p31 */
    {PART_VBMETA_VENDOR_B,         315 * 1024,      1 * 1024,      UFS_PART_3}, /* vbmeta_vendor_b      1M    p32 */
    {PART_VBMETA_ODM_B,            316 * 1024,      1 * 1024,      UFS_PART_3}, /* vbmeta_odm_b         1M    p33 */
    {PART_VBMETA_CUST_B,           317 * 1024,      1 * 1024,      UFS_PART_3}, /* vbmeta_cus_b         1M    p34 */
    {PART_VBMETA_HW_PRODUCT_B,     318 * 1024,      1 * 1024,      UFS_PART_3}, /* vbmeta_hw_product_b  1M    p35 */
    {PART_RECOVERY_RAMDISK_B,      319 * 1024,     32 * 1024,      UFS_PART_3}, /* recovery_ramdisk_b  32M    p36 */
    {PART_RECOVERY_VENDOR_B,       351 * 1024,     24 * 1024,      UFS_PART_3}, /* recovery_vendor_b   24M    p37 */
    {PART_DTBO_B,                  375 * 1024,     20 * 1024,      UFS_PART_3}, /* dtoimage_b          20M    p38 */
    {PART_ENG_VENDOR_B,            395 * 1024,     20 * 1024,      UFS_PART_3}, /* eng_vendor_b        20M    p39 */
    {PART_SECURITY_DTB_B,          415 * 1024,      2 * 1024,      UFS_PART_3}, /* security_dtb_b       2M    p40 */
    {PART_FW_DTB_B,                417 * 1024,      8 * 1024,      UFS_PART_3}, /* fw_dtb_b             8M    p41 */
    {PART_TRUSTFIRMWARE_B,         425 * 1024,      2 * 1024,      UFS_PART_3}, /* trustfirmware_b      2M    p42 */
    {PART_RECOVERY_VBMETA_B,       427 * 1024,      2 * 1024,      UFS_PART_3}, /* recovery_vbmeta_b    2M    p43 */
    {PART_ERECOVERY_VBMETA_B,      429 * 1024,      2 * 1024,      UFS_PART_3}, /* erecovery_vbmeta_b   2M    p44 */
    {PART_VBMETA_B,                431 * 1024,      4 * 1024,      UFS_PART_3}, /* PART_VBMETA_b        4M    p45 */
    {PART_PATCH_B,                 435 * 1024,     32 * 1024,      UFS_PART_3}, /* patch_b             32M    p46 */
    {PART_PREAS_B,                 467 * 1024,   1280 * 1024,      UFS_PART_3}, /* preas_b           1280M    p47 */
    {PART_PREAVS_B,               1747 * 1024,     32 * 1024,      UFS_PART_3}, /* preavs_b            32M    p48 */
    {PART_VERSION_B,              1779 * 1024,    576 * 1024,      UFS_PART_3}, /* version_b          576M    p49 */
    {PART_PRELOAD_B,              2355 * 1024,   1144 * 1024,      UFS_PART_3}, /* preload_b         1144M    p50 */
    {PART_SAFETY_ISLAND_B,        3499 * 1024,      4 * 1024,      UFS_PART_3}, /* safety_island_b      4M    p51 */
    {PART_THEE_B,                 3503 * 1024,      4 * 1024,      UFS_PART_3}, /* thee                 4M    p52 */
    {PART_TZSP_B,                 3507 * 1024,     12 * 1024,      UFS_PART_3}, /* tzsp                12M    p53 */
    {PART_SENSORHUB_B,            3519 * 1024,     16 * 1024,      UFS_PART_3}, /* sensorhub           16M    p54 */
    {PART_DICE_B,                 3535 * 1024,      1 * 1024,      UFS_PART_3}, /* die_a                1M    p55 */
    {PART_DACC_B,                 3536 * 1024,           256,      UFS_PART_3}, /* dacc_b             256K    p56 */
    {PART_DACC_LITE_B,    (3536 * 1024 + 256),           256,      UFS_PART_3}, /* dacc_lite_b        256K    p56 */
    {PART_VENC_B,         (3536 * 1024 + 512),           512,      UFS_PART_3}, /* venc_b             512K    p57 */
    {PART_DDR_XPU_BOOT0_B,        3537 * 1024,           136,      UFS_PART_3}, /* ddr_xpu_boot0_b    136K    p13 */
    {PART_DDR_XPU_BOOT1_B, (3537 * 1024 + 136),          136,      UFS_PART_3}, /* ddr_xpu_boot1_b    136K    p13 */
    {PART_PTABLE_LU4,                       0,           512,      UFS_PART_4}, /* ptable_lu4         512K    p0 */
    {PART_FRP,                            512,           512,      UFS_PART_4}, /* frp                512K    p1 */
    {PART_PERSIST,                   1 * 1024,      6 * 1024,      UFS_PART_4}, /* persist           6144K    p2 */
    {PART_BOOT_CTRL,                 7 * 1024,      1 * 1024,      UFS_PART_4}, /* boot ctrl          512K    p3 */
    {PART_NVME,                      8 * 1024,      5 * 1024,      UFS_PART_4}, /* nvme                 5M    p4 */
    {PART_CTF,                      13 * 1024,      1 * 1024,      UFS_PART_4}, /* PART_CTF             1M    p5 */
    {PART_OEMINFO,                  14 * 1024,     96 * 1024,      UFS_PART_4}, /* oeminfo             96M    p6 */
    {PART_BOARD_ID,                110 * 1024,            64,      UFS_PART_4}, /* board_id             64K   p7 */
    {PART_RESERVED3,        (110 * 1024 + 64),  (960 + 1024),      UFS_PART_4}, /* reserved3           960K   p8 */
    {PART_SECURE_STORAGE,          112 * 1024,     32 * 1024,      UFS_PART_4}, /* secure storage      32M    p9 */
    {PART_HISEE_ENCOS,             144 * 1024,      4 * 1024,      UFS_PART_4}, /* hisee_encos          4M    p10 */
    {PART_VERITYKEY,               148 * 1024,      1 * 1024,      UFS_PART_4}, /* veritykey            1M    p11 */
    {PART_DDR_PARA,                149 * 1024,      1 * 1024,      UFS_PART_4}, /* DDR_PARA             1M    p12 */
    {PART_BATT_TP_PARA,            150 * 1024,      1 * 1024,      UFS_PART_4}, /* batt_tp_para         1M    p13 */
    {PART_TOC,                     151 * 1024,      1 * 1024,      UFS_PART_4}, /* toc                  1M    p14 */
    {PART_SPLASH2,                 152 * 1024,     80 * 1024,      UFS_PART_4}, /* splash2             80M    p15 */
    {PART_BOOTFAIL_INFO,           232 * 1024,      2 * 1024,      UFS_PART_4}, /* bootfail info        2M    p16 */
    {PART_MISC,                    234 * 1024,      2 * 1024,      UFS_PART_4}, /* misc                 2M    p17 */
    {PART_DFX,                     236 * 1024,     16 * 1024,      UFS_PART_4}, /* dfx                 16M    p18 */
    {PART_RRECORD,                 252 * 1024,     16 * 1024,      UFS_PART_4}, /* rrecord             16M    p19 */
    {PART_CACHE,                   268 * 1024,    104 * 1024,      UFS_PART_4}, /* cache              104M    p20 */
    {PART_METADATA,                372 * 1024,     16 * 1024,      UFS_PART_4}, /* metadata            16M    p21 */
    {PART_HKRR,                    388 * 1024,     16 * 1024,      UFS_PART_4}, /* hkrr               16MB    p22 */
    {PART_SUPER,                   404 * 1024,  19742 * 1024,      UFS_PART_4}, /* super     2M+9382+9382M    p23 */
#ifdef CONFIG_FACTORY_MODE
    {PART_HIBENCH_IMG,           20146 * 1024,    128 * 1024,      UFS_PART_4}, /* hibench_img        128M    p24 */
    {PART_HIBENCH_DATA,          20274 * 1024,    512 * 1024,      UFS_PART_4}, /* hibench_data       512M    p25 */
    {PART_FLASH_AGEING,          20786 * 1024,    512 * 1024,      UFS_PART_4}, /* FLASH_AGEING       512M    p26 */
    {PART_HIBENCH_LOG,           21298 * 1024,     32 * 1024,      UFS_PART_4}, /* HIBENCH_LOG         32M    p27 */
    {PART_HIBENCH_LPM3,          21330 * 1024,     32 * 1024,      UFS_PART_4}, /* HIBENCH_LPM3        32M    p28 */
    {PART_SECFLASH_AGEING,       21362 * 1024,     32 * 1024,      UFS_PART_4}, /* secflash_ageing     32M    p29 */
    {PART_USERDATA,              21394 * 1024,  (4UL) * 1024 * 1024,    UFS_PART_4}, /* userdata       4G     p30 */
#elif defined CONFIG_PARTITION_ENG
    {PART_FTTEST,                20146 * 1024,    192 * 1024,      UFS_PART_4}, /* fttest             192M    p24 */
    {PART_DDRTEST,               20338 * 1024,     48 * 1024,      UFS_PART_4}, /* ddrtest             48MB   p25 */
    {PART_HITEST_GPU,            20386 * 1024,    512 * 1024,      UFS_PART_4}, /* hitest_gpu         512MB   p26 */
    {PART_HITEST_ASP_DHRYSTONE,  20898 * 1024,     20 * 1024,      UFS_PART_4}, /* hitest_asp_dhrystone  20MB p27 */
    {PART_HITEST_ASP_TEST,       20918 * 1024,    300 * 1024,      UFS_PART_4}, /* hitest_asp_test    300MB   p28 */
    {PART_HITEST_SENSORHUB,      21218 * 1024,      6 * 1024,      UFS_PART_4}, /* hitest_sensorhub     6MB   p29 */
    {PART_HITEST_ISP,            21224 * 1024,     25 * 1024,      UFS_PART_4}, /* hitest_isp          25MB   p30 */
    {PART_HITEST_ISP_AVS,        21249 * 1024,     25 * 1024,      UFS_PART_4}, /* hitest_isp_avs      25MB   p31 */
    {PART_HITEST_NPU,            21274 * 1024,     80 * 1024,      UFS_PART_4}, /* hitest_npu          80MB   p32 */
    {PART_HITEST_DSS,            21354 * 1024,     18 * 1024,      UFS_PART_4}, /* hitest_dss          18MB   p33 */
    {PART_DSS_DISP_BUF,          21372 * 1024,     64 * 1024,      UFS_PART_4}, /* dss_disp_buf        64MB   p34 */
    {PART_HITEST_JPEGENC,        21436 * 1024,    200 * 1024,      UFS_PART_4}, /* hitest_jpegenc     200MB   p35 */
    {PART_HITEST_HIPP,           21636 * 1024,    100 * 1024,      UFS_PART_4}, /* hitest_hipp        100MB   p36 */
    {PART_HITEST_LPM3,           21736 * 1024,      2 * 1024,      UFS_PART_4}, /* hitest_lpm3          2MB   p37 */
    {PART_JPEG_DEC_TEST_SRC,     21738 * 1024,     20 * 1024,      UFS_PART_4}, /* jpeg_dec_test_src   20MB   p38 */
    {PART_JPEG_DEC_TEST_DEST,    21758 * 1024,     80 * 1024,      UFS_PART_4}, /* jpeg_dec_test_dest  80MB   p39 */
    {PART_VCODE_DATA,            21838 * 1024,    160 * 1024,      UFS_PART_4}, /* vcode_data         200MB   p40 */
    {PART_VCODE_MAX_DATA,        21998 * 1024,    180 * 1024,      UFS_PART_4}, /* vcode_max_data     140MB   p41 */
    {PART_HITEST_SAFETY_ISLAND,  22178 * 1024,      4 * 1024,      UFS_PART_4}, /* safety island        4MB   p42 */
    {PART_USERDATA,              22182 * 1024,  (4UL) * 1024 * 1024,    UFS_PART_4}, /* userdata       4G     p43 */
#else
    {PART_USERDATA,              20146 * 1024,  (4UL) * 1024 * 1024,    UFS_PART_4}, /* userdata       4G     p24 */
#endif
    {"0", 0, 0, 0},
};

#endif
