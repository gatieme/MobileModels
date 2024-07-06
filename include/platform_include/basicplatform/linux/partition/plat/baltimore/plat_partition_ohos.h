#ifndef _PISCES_PLAT_PARTITION_OHOS_H_
#define _PISCES_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {PART_XLOADER,                0,               2 * 1024,    EMMC_BOOT_MAJOR_PART},
    {PART_RESERVED0,              0,               2 * 1024,    EMMC_BOOT_BACKUP_PART},
    {PART_PTABLE,                 0,                    512,    EMMC_USER_PART}, /* ptable           512K     */
    {PART_FRP,                        512,          512, EMMC_USER_PART}, /* frp                512KB p1 */
    {PART_PERSIST,                   1024,     6 * 1024, EMMC_USER_PART}, /* persist              6MB p2 */
    {PART_RESERVED1,             7 * 1024,         1024, EMMC_USER_PART}, /* reserved1         1024KB p3 */
    {PART_RESERVED6,             8 * 1024,          512, EMMC_USER_PART}, /* reserved6          512KB p4 */
    {PART_VRL,                       8704,          512, EMMC_USER_PART}, /* vrl                512KB p5 */
    {PART_VRL_BACKUP,            9 * 1024,          512, EMMC_USER_PART}, /* vrl_backup         512KB p6 */
    {PART_MODEM_SECURE,              9728,         8704, EMMC_USER_PART}, /* modem_secure      8704KB p7 */
    {PART_NVME,                 18 * 1024,     5 * 1024, EMMC_USER_PART}, /* nvme                 5MB p8 */
    {PART_CTF,                  23 * 1024,     1 * 1024, EMMC_USER_PART}, /* ctf               1024KB p9 */
    {PART_OEMINFO,              24 * 1024,    96 * 1024, EMMC_USER_PART}, /* oeminfo             96MB p10 */
    {PART_SECURE_STORAGE,      120 * 1024,    32 * 1024, EMMC_USER_PART}, /* secure_storage      32MB p11 */
    {PART_MODEMNVM_FACTORY,    152 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_factory    16MB p12 */
    {PART_MODEMNVM_BACKUP,     168 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_backup     16MB p13 */
    {PART_MODEMNVM_IMG,        184 * 1024,    46 * 1024, EMMC_USER_PART}, /* modemnvm_img        46MB p14 */
    {PART_HISEE_ENCOS,         230 * 1024,     4 * 1024, EMMC_USER_PART}, /* hisee_encos          4MB p15 */
    {PART_VERITYKEY,           234 * 1024,     1 * 1024, EMMC_USER_PART}, /* veritykey         1024KB p16 */
    {PART_DDR_PARA,            235 * 1024,     1 * 1024, EMMC_USER_PART}, /* ddr_para          1024KB p17 */
    {PART_LOWPOWER_PARA,       236 * 1024,     1 * 1024, EMMC_USER_PART}, /* lowpower_para     1024KB p18 */
    {PART_RESERVED2,           237 * 1024,   126 * 1024, EMMC_USER_PART}, /* reserved2          126MB p19 */
    {PART_LOG,                 363 * 1024,    80 * 1024, EMMC_USER_PART}, /* log                 80MB p20 */
    {PART_BOOTFAIL_INFO,       443 * 1024,     2 * 1024, EMMC_USER_PART}, /* bootfail_info        2MB p21 */
    {PART_MISC,                445 * 1024,     2 * 1024, EMMC_USER_PART}, /* misc                 2MB p22 */
    {PART_DFX,                 447 * 1024,    16 * 1024, EMMC_USER_PART}, /* dfx                 16MB p23 */
    {PART_RRECORD,             463 * 1024,    16 * 1024, EMMC_USER_PART}, /* rrecord             16MB p24 */
    {PART_METADATA,            479 * 1024,    16 * 1024, EMMC_USER_PART}, /* metadata            16MB p25 */
    {PART_FW_UFSDEV,           495 * 1024,     4 * 1024, EMMC_USER_PART}, /* fw_ufsdev            4MB p26 */
    {PART_TOC,                 499 * 1024,     1 * 1024, EMMC_USER_PART}, /* toc               1024KB p27 */
    {PART_BL2,                 500 * 1024,     4 * 1024, EMMC_USER_PART}, /* bl2                  4MB p28 */
    {PART_FW_LPM3,             504 * 1024,     1 * 1024, EMMC_USER_PART}, /* fw_lpm3           1024KB p29 */
    {PART_NPU,                 505 * 1024,     8 * 1024, EMMC_USER_PART}, /* npu                  8MB p30 */
    {PART_HIEPS,               513 * 1024,     2 * 1024, EMMC_USER_PART}, /* hieps                2MB p31 */
    {PART_IVP,                 515 * 1024,     2 * 1024, EMMC_USER_PART}, /* ivp                  2MB p32 */
    {PART_HDCP,                517 * 1024,     1 * 1024, EMMC_USER_PART}, /* hdcp              1024KB p33 */
    {PART_HISEE_IMG,           518 * 1024,     4 * 1024, EMMC_USER_PART}, /* hisee_img            4MB p34 */
    {PART_HHEE,                522 * 1024,     4 * 1024, EMMC_USER_PART}, /* hhee                 4MB p35 */
    {PART_HISEE_FS,            526 * 1024,     8 * 1024, EMMC_USER_PART}, /* hisee_fs             8MB p36 */
    {PART_FASTBOOT,            534 * 1024,    12 * 1024, EMMC_USER_PART}, /* fastboot            12MB p37 */
    {PART_VECTOR,              546 * 1024,     4 * 1024, EMMC_USER_PART}, /* vector               4MB p38 */
    {PART_ISP_BOOT,            550 * 1024,     2 * 1024, EMMC_USER_PART}, /* isp_boot             2MB p39 */
    {PART_ISP_FIRMWARE,        552 * 1024,    14 * 1024, EMMC_USER_PART}, /* isp_firmware        14MB p40 */
    {PART_FW_HIFI,             566 * 1024,    12 * 1024, EMMC_USER_PART}, /* fw_hifi             12MB p41 */
    {PART_TEEOS,               578 * 1024,     8 * 1024, EMMC_USER_PART}, /* teeos                8MB p42 */
    {PART_SENSORHUB,           586 * 1024,    16 * 1024, EMMC_USER_PART}, /* sensorhub           16MB p43 */
    {PART_FW_DTB,              602 * 1024,     8 * 1024, EMMC_USER_PART}, /* fw_dtb               8MB p44 */
    {PART_DTBO,                610 * 1024,    14 * 1024, EMMC_USER_PART}, /* dtbo                14MB p45 */
    {PART_TRUSTFIRMWARE,       624 * 1024,     2 * 1024, EMMC_USER_PART}, /* trustfirmware        2MB p46 */
    {PART_MODEM_FW,            626 * 1024,   134 * 1024, EMMC_USER_PART}, /* modem_fw           134MB p47 */
    {PART_MODEM_PATCH_NV,      760 * 1024,     4 * 1024, EMMC_USER_PART}, /* modem_patch_nv       4MB p48 */
    {PART_MODEM_DRIVER,        764 * 1024,    20 * 1024, EMMC_USER_PART}, /* modem_driver        20MB p49 */
    {PART_MODEMNVM_UPDATE,     784 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_update     16MB p50 */
    {PART_MODEMNVM_CUST,       800 * 1024,    16 * 1024, EMMC_USER_PART}, /* modemnvm_cust       16MB p51 */
    {PART_UPDATER_RVT,         816 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_rvt          2MB p52 */
    {PART_UPDATER_BAK_RVT,     818 * 1024,     2 * 1024, EMMC_USER_PART}, /* updater_bak_rvt      2MB p53 */
    {PART_RVT,                 820 * 1024,     4 * 1024, EMMC_USER_PART}, /* rvt                  4MB p54 */
    {PART_HKRR,                824 * 1024,    16 * 1024, EMMC_USER_PART}, /* hkrr                16MB p55 */
    {PART_RESERVED4,           840 * 1024,    24 * 1024, EMMC_USER_PART}, /* reserved4           24MB p56 */
    {PART_UPDATER_RAMDISK,     864 * 1024,      32*1024, EMMC_USER_PART}, /* updater_ramdisk     32MB p57 */
    {PART_UPDATER_VENDOR,      896 * 1024,      24*1024, EMMC_USER_PART}, /* updater_vendor      24MB p58 */
    {PART_BOOT,                920 * 1024,    46 * 1024, EMMC_USER_PART}, /* boot                46MB p59 */
    {PART_UPDATER_BOOT,        966 * 1024,      45*1024, EMMC_USER_PART}, /* updater_boot        45MB p60 */
    {PART_UPDATER_BOOT_BAK,   1011 * 1024,      45*1024, EMMC_USER_PART}, /* updater_boot_bak    45MB p61 */
    {PART_RESERVED,           1056 * 1024,    72 * 1024, EMMC_USER_PART}, /* reserved            72MB p62 */
    {PART_UPDATER_RAMDISK_BAK,  1128 * 1024,      32*1024, EMMC_USER_PART}, /* updater_ramdisk_bak  32MB p63 */
    {PART_UPDATER_VENDOR_BAK,  1160 * 1024,      24*1024, EMMC_USER_PART}, /* updater_vendor_bak  24MB p64 */
    {PART_ENG_SYSTEM,         1184 * 1024,    12 * 1024, EMMC_USER_PART}, /* eng_system          12MB p65 */
    {PART_ENG_VENDOR,         1196 * 1024,    20 * 1024, EMMC_USER_PART}, /* eng_vendor          20MB p66 */
    {PART_RAMDISK,            1216 * 1024,     3 * 1024, EMMC_USER_PART}, /* ramdisk              3MB p67 */
    {PART_RVT_SYSTEM,         1219 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_system        1024KB p68 */
    {PART_RVT_VENDOR,         1220 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_vendor        1024KB p69 */
    {PART_RVT_CHIP_PROD,      1221 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_chip_prod     1024KB p70 */
    {PART_RVT_CUST,           1222 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_cust          1024KB p71 */
    {PART_RVT_SYS_PROD,       1223 * 1024,     1 * 1024, EMMC_USER_PART}, /* rvt_sys_prod      1024KB p72 */
    {PART_PATCH,              1224 * 1024,    32 * 1024, EMMC_USER_PART}, /* patch               32MB p73 */
    {PART_CUST,               1256 * 1024,    88 * 1024, EMMC_USER_PART}, /* cust                88MB p74 */
    {PART_CHIP_PROD,          1344 * 1024,   616 * 1024, EMMC_USER_PART}, /* chip_prod          616MB p75 */
    {PART_VENDOR,             1960 * 1024,   920 * 1024, EMMC_USER_PART}, /* vendor             920MB p76 */
    {PART_SYS_PROD,           2880 * 1024,  1936 * 1024, EMMC_USER_PART}, /* sys_prod          1936MB p77 */
    {PART_SYSTEM,             4816 * 1024,  3416 * 1024, EMMC_USER_PART}, /* system            3416MB p78 */
    {PART_VERSION,            8232 * 1024,   576 * 1024, EMMC_USER_PART}, /* version            576MB p79 */
    {PART_PRELOAD,            8808 * 1024,  1400 * 1024, EMMC_USER_PART}, /* preload           1400MB p80 */
    {PART_HYPERHOLD,         10208 * 1024,  2048 * 1024, EMMC_USER_PART}, /* hyperhold         2048MB p81 */
#ifdef CONFIG_FACTORY_MODE
    {PART_HIBENCH_IMG,       12256 * 1024,   128 * 1024, EMMC_USER_PART}, /* hibench_img        128MB p82 */
    {PART_HIBENCH_DATA,      12384 * 1024,   512 * 1024, EMMC_USER_PART}, /* hibench_data       512MB p83 */
    {PART_FLASH_AGEING,      12896 * 1024,   512 * 1024, EMMC_USER_PART}, /* flash_ageing       512MB p84 */
    {PART_HIBENCH_LOG,       13408 * 1024,    32 * 1024, EMMC_USER_PART}, /* hibench_log         32MB p85 */
    {PART_SECFLASH_AGEING,   13440 * 1024,    32 * 1024, EMMC_USER_PART}, /* secflash_ageing     32MB p86 */
    {PART_USERDATA,          13472 * 1024,(4UL) * 1024 * 1024, EMMC_USER_PART}, /* userdata        4G p87 */
#else
    {PART_USERDATA,          12256 * 1024,(4UL) * 1024 * 1024, EMMC_USER_PART}, /* userdata        4G p82 */
#endif

    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                   0,                 2 * 1024,    UFS_PART_0},
    {PART_RESERVED0,                 0,                 2 * 1024,    UFS_PART_1},
    {PART_PTABLE,                    0,                      512,    UFS_PART_2}, /* ptable           512K     */
    {PART_FRP,                        512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                   1024,     6 * 1024, UFS_PART_2}, /* persist              6MB p2 */
    {PART_RESERVED1,             7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,                0,             512, UFS_PART_3}, /* ptable_lu3          512K p0 */
    {PART_VRL,                        512,          512, UFS_PART_3}, /* vrl                512KB p1 */
    {PART_VRL_BACKUP,                1024,          512, UFS_PART_3}, /* vrl_backup         512KB p2 */
    {PART_MODEM_SECURE,              1536,         8704, UFS_PART_3}, /* modem_secure      8704KB p3 */
    {PART_NVME,                 10 * 1024,     5 * 1024, UFS_PART_3}, /* nvme                 5MB p4 */
    {PART_CTF,                  15 * 1024,     1 * 1024, UFS_PART_3}, /* ctf               1024KB p5 */
    {PART_OEMINFO,              16 * 1024,    96 * 1024, UFS_PART_3}, /* oeminfo             96MB p6 */
    {PART_SECURE_STORAGE,      112 * 1024,    32 * 1024, UFS_PART_3}, /* secure_storage      32MB p7 */
    {PART_MODEMNVM_FACTORY,    144 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_factory    16MB p8 */
    {PART_MODEMNVM_BACKUP,     160 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_backup     16MB p9 */
    {PART_MODEMNVM_IMG,        176 * 1024,    46 * 1024, UFS_PART_3}, /* modemnvm_img        46MB p10 */
    {PART_HISEE_ENCOS,         222 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_encos          4MB p11 */
    {PART_VERITYKEY,           226 * 1024,     1 * 1024, UFS_PART_3}, /* veritykey         1024KB p12 */
    {PART_DDR_PARA,            227 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p13 */
    {PART_LOWPOWER_PARA,       228 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p14 */
    {PART_RESERVED2,           229 * 1024,   126 * 1024, UFS_PART_3}, /* reserved2          126MB p15 */
    {PART_LOG,                 355 * 1024,    80 * 1024, UFS_PART_3}, /* log                 80MB p16 */
    {PART_BOOTFAIL_INFO,       435 * 1024,     2 * 1024, UFS_PART_3}, /* bootfail_info        2MB p17 */
    {PART_MISC,                437 * 1024,     2 * 1024, UFS_PART_3}, /* misc                 2MB p18 */
    {PART_DFX,                 439 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p19 */
    {PART_RRECORD,             455 * 1024,    16 * 1024, UFS_PART_3}, /* rrecord             16MB p20 */
    {PART_METADATA,            471 * 1024,    16 * 1024, UFS_PART_3}, /* metadata            16MB p21 */
    {PART_FW_UFSDEV,           487 * 1024,     4 * 1024, UFS_PART_3}, /* fw_ufsdev            4MB p22 */
    {PART_TOC,                 491 * 1024,     1 * 1024, UFS_PART_3}, /* toc               1024KB p23 */
    {PART_BL2,                 492 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p24 */
    {PART_FW_LPM3,             496 * 1024,     1 * 1024, UFS_PART_3}, /* fw_lpm3           1024KB p25 */
    {PART_NPU,                 497 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p26 */
    {PART_HIEPS,               505 * 1024,     2 * 1024, UFS_PART_3}, /* hieps                2MB p27 */
    {PART_IVP,                 507 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p28 */
    {PART_HDCP,                509 * 1024,     1 * 1024, UFS_PART_3}, /* hdcp              1024KB p29 */
    {PART_HISEE_IMG,           510 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p30 */
    {PART_HHEE,                514 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p31 */
    {PART_HISEE_FS,            518 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p32 */
    {PART_FASTBOOT,            526 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p33 */
    {PART_VECTOR,              538 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p34 */
    {PART_ISP_BOOT,            542 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p35 */
    {PART_ISP_FIRMWARE,        544 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p36 */
    {PART_FW_HIFI,             558 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p37 */
    {PART_TEEOS,               570 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p38 */
    {PART_SENSORHUB,           578 * 1024,    16 * 1024, UFS_PART_3}, /* sensorhub           16MB p39 */
    {PART_FW_DTB,              594 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p40 */
    {PART_DTBO,                602 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p41 */
    {PART_TRUSTFIRMWARE,       616 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p42 */
    {PART_MODEM_FW,            618 * 1024,   134 * 1024, UFS_PART_3}, /* modem_fw           134MB p43 */
    {PART_MODEM_PATCH_NV,      752 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p44 */
    {PART_MODEM_DRIVER,        756 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p45 */
    {PART_MODEMNVM_UPDATE,     776 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p46 */
    {PART_MODEMNVM_CUST,       792 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p47 */
    {PART_UPDATER_RVT,         808 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p48 */
    {PART_UPDATER_BAK_RVT,     810 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p49 */
    {PART_RVT,                 812 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p50 */
    {PART_HKRR,                816 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr                16MB p51 */
    {PART_RESERVED4,           832 * 1024,    24 * 1024, UFS_PART_3}, /* reserved4           24MB p52 */
    {PART_UPDATER_RAMDISK,     856 * 1024,      32*1024, UFS_PART_3}, /* updater_ramdisk     32MB p53 */
    {PART_UPDATER_VENDOR,      888 * 1024,      24*1024, UFS_PART_3}, /* updater_vendor      24MB p54 */
    {PART_BOOT,                912 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p55 */
    {PART_UPDATER_BOOT,        958 * 1024,      45*1024, UFS_PART_3}, /* updater_boot        45MB p56 */
    {PART_UPDATER_BOOT_BAK,   1003 * 1024,      45*1024, UFS_PART_3}, /* updater_boot_bak    45MB p57 */
    {PART_RESERVED,           1048 * 1024,    72 * 1024, UFS_PART_3}, /* reserved            72MB p58 */
    {PART_UPDATER_RAMDISK_BAK,  1120 * 1024,      32*1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p59 */
    {PART_UPDATER_VENDOR_BAK,  1152 * 1024,      24*1024, UFS_PART_3}, /* updater_vendor_bak  24MB p60 */
    {PART_ENG_SYSTEM,         1176 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p61 */
    {PART_ENG_VENDOR,         1188 * 1024,    20 * 1024, UFS_PART_3}, /* eng_vendor          20MB p62 */
    {PART_RAMDISK,            1208 * 1024,     3 * 1024, UFS_PART_3}, /* ramdisk              3MB p63 */
    {PART_RVT_SYSTEM,         1211 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p64 */
    {PART_RVT_VENDOR,         1212 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p65 */
    {PART_RVT_CHIP_PROD,      1213 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p66 */
    {PART_RVT_CUST,           1214 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p67 */
    {PART_RVT_SYS_PROD,       1215 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p68 */
    {PART_PATCH,              1216 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p69 */
    {PART_CUST,               1248 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p70 */
    {PART_CHIP_PROD,          1336 * 1024,   616 * 1024, UFS_PART_3}, /* chip_prod          616MB p71 */
    {PART_VENDOR,             1952 * 1024,   920 * 1024, UFS_PART_3}, /* vendor             920MB p72 */
    {PART_SYS_PROD,           2872 * 1024,  1936 * 1024, UFS_PART_3}, /* sys_prod          1936MB p73 */
    {PART_SYSTEM,             4808 * 1024,  3416 * 1024, UFS_PART_3}, /* system            3416MB p74 */
    {PART_VERSION,            8224 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p75 */
    {PART_PRELOAD,            8800 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p76 */
    {PART_HYPERHOLD,         10200 * 1024,  2048 * 1024, UFS_PART_3}, /* hyperhold         2048MB p77 */
#ifdef CONFIG_FACTORY_MODE
    {PART_HIBENCH_IMG,       12248 * 1024,   128 * 1024, UFS_PART_3}, /* hibench_img        128MB p78 */
    {PART_HIBENCH_DATA,      12376 * 1024,   512 * 1024, UFS_PART_3}, /* hibench_data       512MB p79 */
    {PART_FLASH_AGEING,      12888 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p80 */
    {PART_HIBENCH_LOG,       13400 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p81 */
    {PART_SECFLASH_AGEING,   13432 * 1024,    32 * 1024, UFS_PART_3}, /* secflash_ageing     32MB p82 */
    {PART_USERDATA,          13464 * 1024,(4UL) * 1024 * 1024, UFS_PART_3}, /* userdata        4G p83 */
#else
    {PART_USERDATA,          12248 * 1024,(4UL) * 1024 * 1024, UFS_PART_3}, /* userdata        4G p78 */
#endif
    {PART_PTABLE_LU4,             0,             512,    UFS_PART_4}, /* ptable_lu4       512K    p0 */
    {PART_RESERVED12,                 512,         1536, UFS_PART_4}, /* reserved12        1536KB p1 */
    {PART_USERDATA2,             2 * 1024,(4UL) * 1024 * 1024, UFS_PART_4}, /* userdata2       4G p2 */
    {"0", 0, 0, 0},
};

#endif
