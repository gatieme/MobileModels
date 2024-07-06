#ifndef _PISCES_PLAT_PARTITION_OHOS_H_
#define _PISCES_PLAT_PARTITION_OHOS_H_

#include "partition_macro.h"
#include "partition_macro_plus.h"
#include "partition_def.h"

static const struct partition partition_table_emmc[] = {
    {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] = {
    {PART_XLOADER,                0,              2 * 1024,    UFS_PART_0},
    {PART_RESERVED0,              0,              2 * 1024,    UFS_PART_1},
    {PART_PTABLE,                 0,                   512,    UFS_PART_2}, /* ptable           512K    p0 */
    {PART_FRP,                        512,          512, UFS_PART_2}, /* frp                512KB p1 */
    {PART_PERSIST,                   1024,     6 * 1024, UFS_PART_2}, /* persist              6MB p2 */
    {PART_RESERVED1,             7 * 1024,         1024, UFS_PART_2}, /* reserved1         1024KB p3 */
    {PART_PTABLE_LU3,             0,                   512,    UFS_PART_3}, /* ptable_lu3       512K    p0 */
    {PART_VRL,                        512,          512, UFS_PART_3}, /* vrl                512KB p1 */
    {PART_VRL_BACKUP,                1024,          512, UFS_PART_3}, /* vrl_backup         512KB p2 */
    {PART_MODEM_SECURE,              1536,         8704, UFS_PART_3}, /* modem_secure      8704KB p3 */
    {PART_NVME,                 10 * 1024,     4 * 1024, UFS_PART_3}, /* nvme                 4MB p4 */
    {PART_CONN_CALIDATA,        14 * 1024,         1024, UFS_PART_3}, /* conn_calidata     1024KB p5 */
    {PART_CTF,                  15 * 1024,     1 * 1024, UFS_PART_3}, /* ctf               1024KB p6 */
    {PART_OEMINFO,              16 * 1024,    96 * 1024, UFS_PART_3}, /* oeminfo             96MB p7 */
    {PART_SECURE_STORAGE,      112 * 1024,    32 * 1024, UFS_PART_3}, /* secure_storage      32MB p8 */
    {PART_MODEMNVM_FACTORY,    144 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_factory    16MB p9 */
    {PART_MODEMNVM_BACKUP,     160 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_backup     16MB p10 */
    {PART_MODEMNVM_IMG,        176 * 1024,    46 * 1024, UFS_PART_3}, /* modemnvm_img        46MB p11 */
    {PART_HISEE_ENCOS,         222 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_encos          4MB p12 */
    {PART_VERITYKEY,           226 * 1024,     1 * 1024, UFS_PART_3}, /* veritykey         1024KB p13 */
    {PART_DDR_PARA,            227 * 1024,     1 * 1024, UFS_PART_3}, /* ddr_para          1024KB p14 */
    {PART_LOWPOWER_PARA,       228 * 1024,     1 * 1024, UFS_PART_3}, /* lowpower_para     1024KB p15 */
    {PART_RESERVED2,           229 * 1024,   126 * 1024, UFS_PART_3}, /* reserved2          126MB p16 */
    {PART_LOG,                 355 * 1024,    80 * 1024, UFS_PART_3}, /* log                 80MB p17 */
    {PART_BOOTFAIL_INFO,       435 * 1024,     2 * 1024, UFS_PART_3}, /* bootfail_info        2MB p18 */
    {PART_MISC,                437 * 1024,     2 * 1024, UFS_PART_3}, /* misc                 2MB p19 */
    {PART_DFX,                 439 * 1024,    16 * 1024, UFS_PART_3}, /* dfx                 16MB p20 */
    {PART_RRECORD,             455 * 1024,    16 * 1024, UFS_PART_3}, /* rrecord             16MB p21 */
    {PART_METADATA,            471 * 1024,    16 * 1024, UFS_PART_3}, /* metadata            16MB p22 */
    {PART_RESERVED3,           487 * 1024,     4 * 1024, UFS_PART_3}, /* reserved3            4MB p23 */
    {PART_TOC,                 491 * 1024,     1 * 1024, UFS_PART_3}, /* toc               1024KB p24 */
    {PART_BL2,                 492 * 1024,     4 * 1024, UFS_PART_3}, /* bl2                  4MB p25 */
    {PART_FW_LPM3,             496 * 1024,          512, UFS_PART_3}, /* fw_lpm3            512KB p26 */
    {PART_FW_CPU_LPCTRL,       (496 * 1024 + 512),          256, UFS_PART_3}, /* fw_cpu_lpctrl            256K    p27 */
    {PART_FW_GPU_LPCTRL,       (496 * 1024 + 768),          128, UFS_PART_3}, /* fw_gpu_lpctrl            128K    p28 */
    {PART_FW_DDR_LPCTRL,       (496 * 1024 + 896),          128, UFS_PART_3}, /* fw_ddr_lpctrl            128K    p29 */
    {PART_NPU,                 497 * 1024,     8 * 1024, UFS_PART_3}, /* npu                  8MB p30 */
    {PART_HIEPS,               505 * 1024,     2 * 1024, UFS_PART_3}, /* hieps                2MB p31 */
    {PART_IVP,                 507 * 1024,     2 * 1024, UFS_PART_3}, /* ivp                  2MB p32 */
    {PART_DACC,                509 * 1024,          512, UFS_PART_3}, /* dacc               512KB p33 */
    {PART_VENC,                (509 * 1024 + 512),  512, UFS_PART_3}, /* venc                      512KB p35 */
    {PART_HISEE_IMG,           510 * 1024,     4 * 1024, UFS_PART_3}, /* hisee_img            4MB p35 */
    {PART_HHEE,                514 * 1024,     4 * 1024, UFS_PART_3}, /* hhee                 4MB p36 */
    {PART_THEE,                518 * 1024,     4 * 1024, UFS_PART_3}, /* thee                 4MB p37 */
    {PART_TZSP,                522 * 1024,    12 * 1024, UFS_PART_3}, /* tzsp                12MB p38 */
    {PART_HKRR,                534 * 1024,    16 * 1024, UFS_PART_3}, /* hkrr                16MB p39 */
    {PART_HISEE_FS,            550 * 1024,     8 * 1024, UFS_PART_3}, /* hisee_fs             8MB p40 */
    {PART_FASTBOOT,            558 * 1024,    12 * 1024, UFS_PART_3}, /* fastboot            12MB p41 */
    {PART_VECTOR,              570 * 1024,     4 * 1024, UFS_PART_3}, /* vector               4MB p42 */
    {PART_ISP_BOOT,            574 * 1024,     2 * 1024, UFS_PART_3}, /* isp_boot             2MB p43 */
    {PART_ISP_FIRMWARE,        576 * 1024,    14 * 1024, UFS_PART_3}, /* isp_firmware        14MB p44 */
    {PART_FW_HIFI,             590 * 1024,    12 * 1024, UFS_PART_3}, /* fw_hifi             12MB p45 */
    {PART_TEEOS,               602 * 1024,     8 * 1024, UFS_PART_3}, /* teeos                8MB p46 */
    {PART_SENSORHUB,           610 * 1024,    13 * 1024, UFS_PART_3}, /* sensorhub           13MB p47 */ 
    {PART_SENSORHUB_LOG_DIC,   623 * 1024,     3 * 1024, UFS_PART_3}, /* sensorhub_log_dic    3MB p48 */
    {PART_FW_DTB,              626 * 1024,     8 * 1024, UFS_PART_3}, /* fw_dtb               8MB p49 */
    {PART_TRUSTFIRMWARE,       634 * 1024,     2 * 1024, UFS_PART_3}, /* trustfirmware        2MB p50 */
    {PART_MODEM_FW,            636 * 1024,   124 * 1024, UFS_PART_3}, /* modem_fw           124MB p51 */
    {PART_MODEM_VENDOR,        760 * 1024,    10 * 1024, UFS_PART_3}, /* modem_vendor        10MB p52 */
    {PART_MODEM_PATCH_NV,      770 * 1024,     4 * 1024, UFS_PART_3}, /* modem_patch_nv       4MB p53 */
    {PART_MODEM_DRIVER,        774 * 1024,    20 * 1024, UFS_PART_3}, /* modem_driver        20MB p54 */
    {PART_MODEMNVM_UPDATE,     794 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_update     16MB p55 */
    {PART_MODEMNVM_CUST,       810 * 1024,    16 * 1024, UFS_PART_3}, /* modemnvm_cust       16MB p56 */
    {PART_RVT,                 826 * 1024,     4 * 1024, UFS_PART_3}, /* rvt                  4MB p57 */
    {PART_UPDATER_RVT,         830 * 1024,     2 * 1024, UFS_PART_3}, /* updater_rvt          2MB p58 */
    {PART_UPDATER_BAK_RVT,     832 * 1024,     2 * 1024, UFS_PART_3}, /* updater_bak_rvt      2MB p59 */
    {PART_RESERVED4,           834 * 1024,    24 * 1024, UFS_PART_3}, /* reserved4           24MB p60 */
    {PART_UPDATER_RAMDISK,     858 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk     32MB p61 */
    {PART_UPDATER_VENDOR,      890 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor      24MB p62 */
    {PART_BOOT,                914 * 1024,    46 * 1024, UFS_PART_3}, /* boot                46MB p63 */
    {PART_DTBO,                960 * 1024,    14 * 1024, UFS_PART_3}, /* dtbo                14MB p64 */
    {PART_UPDATER_BOOT,        974 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot        45MB p65 */
    {PART_UPDATER_BOOT_BAK,   1019 * 1024,    45 * 1024, UFS_PART_3}, /* updater_boot_bak    45MB p66 */
    {PART_RESERVED,           1064 * 1024,    72 * 1024, UFS_PART_3}, /* reserved            72MB p67 */
    {PART_UPDATER_RAMDISK_BAK,  1136 * 1024,    32 * 1024, UFS_PART_3}, /* updater_ramdisk_bak  32MB p68 */
    {PART_UPDATER_VENDOR_BAK,  1168 * 1024,    24 * 1024, UFS_PART_3}, /* updater_vendor_bak  24MB p69 */
    {PART_ENG_SYSTEM,         1192 * 1024,    12 * 1024, UFS_PART_3}, /* eng_system          12MB p70 */
    {PART_ENG_VENDOR,         1204 * 1024,    20 * 1024, UFS_PART_3}, /* eng_vendor          20MB p71 */
    {PART_RAMDISK,            1224 * 1024,     3 * 1024, UFS_PART_3}, /* ramdisk              3MB p72 */
    {PART_RVT_SYSTEM,         1227 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_system        1024KB p73 */
    {PART_RVT_VENDOR,         1228 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_vendor        1024KB p74 */
    {PART_RVT_CHIP_PROD,      1229 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_chip_prod     1024KB p75 */
    {PART_RVT_CUST,           1230 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_cust          1024KB p76 */
    {PART_RVT_SYS_PROD,       1231 * 1024,     1 * 1024, UFS_PART_3}, /* rvt_sys_prod      1024KB p77 */
    {PART_PATCH,              1232 * 1024,    32 * 1024, UFS_PART_3}, /* patch               32MB p78 */
    {PART_CUST,               1264 * 1024,    88 * 1024, UFS_PART_3}, /* cust                88MB p79 */
    {PART_CHIP_PROD,          1352 * 1024,   616 * 1024, UFS_PART_3}, /* chip_prod          616MB p80 */
    {PART_VENDOR,             1968 * 1024,   920 * 1024, UFS_PART_3}, /* vendor             920MB p81 */
    {PART_SYS_PROD,           2888 * 1024,  1936 * 1024, UFS_PART_3}, /* sys_prod          1936MB p82 */
    {PART_SYSTEM,             4824 * 1024,  3416 * 1024, UFS_PART_3}, /* system            3416MB p83 */
    {PART_VERSION,            8240 * 1024,   576 * 1024, UFS_PART_3}, /* version            576MB p84 */
    {PART_PRELOAD,            8816 * 1024,  1400 * 1024, UFS_PART_3}, /* preload           1400MB p85 */
    {PART_HYPERHOLD,         10216 * 1024,  2048 * 1024, UFS_PART_3}, /* hyperhold         2048MB p86 */
#ifdef CONFIG_FACTORY_MODE
    {PART_HIBENCH_IMG,       12264 * 1024,   128 * 1024, UFS_PART_3}, /* hibench_img        128MB p87 */
    {PART_HIBENCH_DATA,      12392 * 1024,   512 * 1024, UFS_PART_3}, /* hibench_data       512MB p88 */
    {PART_FLASH_AGEING,      12904 * 1024,   512 * 1024, UFS_PART_3}, /* flash_ageing       512MB p89 */
    {PART_HIBENCH_LOG,       13416 * 1024,    32 * 1024, UFS_PART_3}, /* hibench_log         32MB p90 */
    {PART_SECFLASH_AGEING,   13448 * 1024,    32 * 1024, UFS_PART_3}, /* secflash_ageing     32MB p91 */
    {PART_USERDATA,          13480 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata        6G p92 */
#else
#if defined(CONFIG_BOOT_UEFI) && defined(CONFIG_PARTITION_ENG)
    {PART_FTTEST,            12264 * 1024,   192 * 1024, UFS_PART_3}, /* fttest             192MB p87 */
    {PART_DDRTEST,           12456 * 1024,    48 * 1024, UFS_PART_3}, /* ddrtest             48MB p88 */
    {PART_HITEST_GPU,        12504 * 1024,   512 * 1024, UFS_PART_3}, /* hitest_gpu         512MB p89 */
    {PART_HITEST_ASP_DHRYSTONE, 13016 * 1024,    20 * 1024, UFS_PART_3}, /* hitest_asp_dhrystone  20MB p90 */
    {PART_HITEST_ASP_TEST,   13036 * 1024,   300 * 1024, UFS_PART_3}, /* hitest_asp_test    300MB p91 */
    {PART_HITEST_SENSORHUB,  13336 * 1024,     6 * 1024, UFS_PART_3}, /* hitest_sensorhub     6MB p92 */
    {PART_HITEST_ISP,        13342 * 1024,    25 * 1024, UFS_PART_3}, /* hitest_isp          25MB p93 */
    {PART_HITEST_ISP_AVS,    13367 * 1024,    25 * 1024, UFS_PART_3}, /* hitest_isp_avs      25MB p94 */
    {PART_HITEST_NPU,        13392 * 1024,    80 * 1024, UFS_PART_3}, /* hitest_npu          80MB p95 */
    {PART_HITEST_DSS,        13472 * 1024,    18 * 1024, UFS_PART_3}, /* hitest_dss          18MB p96 */
    {PART_DSS_DISP_BUF,      13490 * 1024,    64 * 1024, UFS_PART_3}, /* dss_disp_buf        64MB p97 */
    {PART_HITEST_JPEGENC,    13554 * 1024,   200 * 1024, UFS_PART_3}, /* hitest_jpegenc     200MB p98 */
    {PART_HITEST_HIPP,       13754 * 1024,   100 * 1024, UFS_PART_3}, /* hitest_hipp        100MB p99 */
    {PART_HITEST_LPM3,       13854 * 1024,     2 * 1024, UFS_PART_3}, /* hitest_lpm3          2MB p100 */
    {PART_JPEG_DEC_TEST_SRC, 13856 * 1024,    20 * 1024, UFS_PART_3}, /* jpeg_dec_test_src   20MB p101 */
    {PART_JPEG_DEC_TEST_DEST, 13876 * 1024,    80 * 1024, UFS_PART_3}, /* jpeg_dec_test_dest  80MB p102 */
    {PART_VCODE_DATA,        13956 * 1024,   130 * 1024, UFS_PART_3}, /* vcode_data         130MB p103 */
    {PART_VCODE_MAX_DATA,    14086 * 1024,   140 * 1024, UFS_PART_3}, /* vcode_max_data     140MB p104 */
    {PART_MODEM_TSP_TEST,    14226 * 1024,    79 * 1024, UFS_PART_3}, /* modem_tsp_test      79MB p105 */
    {PART_MODEM_TSP_DT,      14305 * 1024,     1 * 1024, UFS_PART_3}, /* modem_tsp_dt      1024KB p106 */
    {PART_MODEM_TSP_AVS,     14306 * 1024,    80 * 1024, UFS_PART_3}, /* modem_tsp_avs       80MB p107 */
    {PART_MODEM_PDE_TEST,    14386 * 1024,     4 * 1024, UFS_PART_3}, /* modem_pde_test       4MB p108 */
    {PART_USERDATA,          14390 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata        6G p109 */
#else
    {PART_USERDATA,          12264 * 1024,(16UL) * 1024 * 1024, UFS_PART_3}, /* userdata        6G p87 */
#endif
#endif
    {"0", 0, 0, 0},
};

#endif
