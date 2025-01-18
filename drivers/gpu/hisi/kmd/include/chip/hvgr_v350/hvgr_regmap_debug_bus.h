/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_REGMAP_DEBUG_BUS_H
#define HVGR_REGMAP_DEBUG_BUS_H

#define HVGR_DEBUG_BUS_MAX_CORE_ID              15
#define HVGR_DEBUG_BUS_MAX_GPC_CORE_ID          7
#define HVGR_DEBUG_BUS_MAX_BVH_CORE_ID          11
#define HVGR_DEBUG_BUS_MAX_COM_CTRL_CORE_ID     12
#define HVGR_DEBUG_BUS_FCM_CORE_ID              13
#define HVGR_DEBUG_BUS_L2MMU_CORE_ID            14
#define HVGR_DEBUG_BUS_BIN_COER_ID              15

#define HVGR_DEBUG_BUS_DUMP_FIR                 0
#define HVGR_DEBUG_BUS_DUMP_SEC                 1
#define HVGR_DEBUG_BUS_CNT_FIR                  1
#define HVGR_DEBUG_BUS_CNT_SEC                  2

#define HVGR_DEBUG_BUS_BUFFER_SIZE_MISC         0x1000000
#define HVGR_DEBUG_BUS_BUFFER_SIZE_PRE_GPC      0x200000

#define FCP_REG_SIZE                           4
#define HVGR_DEBUG_BUS_MAX_NUMBER              99
#define HVGR_DEBUG_BUS_FILE_PREFIX             "gpu_debugbus_"
#define HVGR_DEBUG_BUS_DATA_DIR                "/data/hisi_logs/debugbus/"
#define HVGR_DEBUG_BUS_DATA_FILE               "/data/hisi_logs/debugbus/gpu_debugbus_%s_%s.dbb"
#define HVGR_DEBUG_BUS_DATA_FILE_DUPLICATED    "/data/hisi_logs/debugbus/gpu_debugbus_%s_%s_duplicated.dbb"
#define HVGR_DEBUG_BUS_TIME                    "%4d-%02d-%02d_%02d-%02d-%02d"
#define HVGR_DEBUG_BUS_DATA_DIR_MODE           0777
#define DATA_DIR                               "/data"
#define HVGR_BTC_CONFIG_OFFSET                 ((u32)1 << 25)
#define HVGR_XBI_CONFIG_OFFSET                 ((u32)1 << 3)
#define HVGR_GPC_2_CONFIG_OFFSET               ((u32)1 << 2)
#define HVGR_GPC_3_CONFIG_OFFSET               ((u32)1 << 4)
#define HVGR_GPC_4_CONFIG_OFFSET               ((u32)1 << 1)

#define HVGR_DEBUG_BUS_STATE_TYPE_OFFSET       11
#define HVGR_DEBUG_BUS_DEST_ID_OFFSET          15
#define HVGR_DEBUG_BUS_CORE_ID_OFFSET          23

#define FAULT_NUMBER                           5
#define MIN_FREE_SPACE                         1024
#define DUMP_DATA_MAX_SIZE                     64
#define MAX_TIME_SIZE                          20
#define MAX_READ_TIMES                         50
#define VERSION_350                            "Version3.50\n"
#define RECORD_FORMAT                          "0x%08x:0x%08x\n"
#define GPU_CONTROL_TITLE                      "gpu control register:\n"
#define MISC_CONTROL_TITLE                     "misc control register:\n"
#define JOB_CONTROL_TITLE                      "job control register:\n"
#define MMU_CONTROL_TITLE                      "mmu control register:\n"
#define FCP_CONTROL_TITLE                      "fcp control register:\n"
#define CQ_CONTROL_TITLE                       "cq control register:\n"

#define JOB_CHAIN_NUM                          4
#define MAX_ADDR_SPACE_NUM                     8
#define MAX_REQ_NUM                            4
#define MAX_WINDOW_NUM                         4
#define MAX_MB_CMD_MSG_NUM                     4
#define MAX_MB_STATUE_MSG_NUM                  2
#define MAX_DMA_CHANNEL_NUMBER                 32
#define MAX_TIMER_NUMBER                       2

#define STATE_TYEP_0                           0
#define STATE_TYEP_1                           1
#define STATE_TYEP_2                           2
#define STATE_TYEP_3                           3
#define STATE_TYEP_4                           4
#define STATE_TYEP_5                           5
#define STATE_TYEP_6                           6
#define STATE_TYEP_7                           7
#define STATE_TYEP_8                           8
#define STATE_TYEP_9                           9
#define STATE_TYEP_10                          10
#define STATE_TYEP_11                          11
#define STATE_TYEP_12                          12
#define STATE_TYEP_13                          13
#define STATE_TYEP_14                          14
#define STATE_TYEP_15                          15

#define DEST_ID_GPC_VTC                        0
#define DEST_ID_GPC_SDC                        1
#define DEST_ID_GPC_LSC                        2
#define DEST_ID_GPC_GTC                        3
#define DEST_ID_GPC_WM                         4
#define DEST_ID_GPC_RTTC                       6
#define DEST_ID_GPC_DM                         8
#define DEST_ID_GPC_SQ                         9
#define DEST_ID_GPC_DG                         10
#define DEST_ID_GPC_EU                         11
#define DEST_ID_GPC_EU1                        12
#define DEST_ID_GPC_EU2                        13
#define DEST_ID_GPC_EU3                        14
#define DEST_ID_GPC_RCP                        16
#define DEST_ID_GPC_TS                         17
#define DEST_ID_GPC_RAST                       18
#define DEST_ID_GPC_ZS                         19
#define DEST_ID_GPC_BLND                       20
#define DEST_ID_GPC_VARY                       21
#define DEST_ID_GPC_CBI                        24
#define DEST_ID_GPC_PEC                        25
#define DEST_ID_GPC_CPB                        26
#define DEST_ID_GPC_TSM                        32
#define DEST_ID_GPC_TRD                        33
#define DEST_ID_GPC_TAG                        34
#define DEST_ID_GPC_TSG                        35
#define DEST_ID_GPC_TRS                        36
#define DEST_ID_GPC_TCC                        37
#define DEST_ID_GPC_TFU                        38

#define DEST_ID_BVH_BVHM                       0
#define DEST_ID_BVH_BSETUP                     1
#define DEST_ID_BVH_BRANK                      2
#define DEST_ID_BVH_BEMIT                      3
#define DEST_ID_BVH_BSAH                       4
#define DEST_ID_BVH_PEC                        8

#define DEST_ID_COM_CTRL                       0

#define DEST_ID_FCM_JOB                        0
#define DEST_ID_FCM_CQ_QM                      2
#define DEST_ID_FCM_CQ_SM                      3
#define DEST_ID_FCM_FCP                        4
#define DEST_ID_FCM_FCP_CTRL                   5
#define DEST_ID_FCM_MISC_CTRL                  6
#define DEST_ID_FCM_PEC                        7
#define DEST_ID_FCM_TOP_FCM                    8
#define DEST_ID_FCM_TOP_GPU                    9

#define DEST_ID_L2MMU_L2RO                     0
#define DEST_ID_L2MMU_L2RW                     1
#define DEST_ID_L2MMU_L2MIF                    2
#define DEST_ID_L2MMU_MMU                      3
#define DEST_ID_L2MMU_GBI                      4
#define DEST_ID_L2MMU_MCB                      5
#define DEST_ID_L2MMU_CPB                      6
#define DEST_ID_L2MMU_PEU                      7
#define DEST_ID_L2MMU_L2VPM                    8
#define DEST_ID_L2MMU_RTU                      9
#define DEST_ID_L2MMU_RTU1                     10
#define DEST_ID_L2MMU_UTLB                     16
#define DEST_ID_L2MMU_UTLB1                    17
#define DEST_ID_L2MMU_UTLB2                    18

#define DEST_ID_BIN_JCU                        0
#define DEST_ID_BIN_VF                         1
#define DEST_ID_BIN_PA                         2
#define DEST_ID_BIN_TESS                       3
#define DEST_ID_BIN_UTC                        4
#define DEST_ID_BIN_OA                         5
#define DEST_ID_BIN_GPC_ARB                    6
#define DEST_ID_BIN_BTC_TOP                    7
#define DEST_ID_BIN_BTS                        8
#define DEST_ID_BIN_BRAST                      9
#define DEST_ID_BIN_BCZ                        10
#define DEST_ID_BIN_REJ_SYNC                   11
#define DEST_ID_BIN_SPU                        12
#define DEST_ID_BIN_SC                         13
#define DEST_ID_BIN_PEC                        15

/*
 * We need to balance the code size and the dbb file size.
 * The previous code was designed to divide valid offset addresses into groups,
 * and to traverse each group from 0 to 2047. This solution results in a huge dbb file
 * size. At some platform, we have not enough space to save this file.
 * So, we need to reduce the dbb file size. Now, we record the max valid address for each
 * group as follow, so traverse each group from 0 to the max value.
 */

#define DEST_ID_GPC_VTC_STATE_0_SIZE         0x32
#define DEST_ID_GPC_SDC_STATE_0_SIZE         0x7FF
#define DEST_ID_GPC_SDC_STATE_1_SIZE         0x200
#define DEST_ID_GPC_LSC_STATE_0_SIZE         0x705
#define DEST_ID_GPC_LSC_STATE_2_SIZE         0x7FF /* = 0x1000 - 0x800 * 0x2 + 0x800[256/32*256] */
#define DEST_ID_GPC_LSC_STATE_3_SIZE         0x0   /* = 0x1800 - 0x800 * 0x3 */
#define DEST_ID_GPC_GTC_STATE_0_SIZE         0x52
#define DEST_ID_GPC_WM_STATS_0_SIZE          0x4C
#define DEST_ID_GPC_RTTC_STATS_0_SIZE        0x19
#define DEST_ID_GPC_DM_STATS_0_SIZE          0x98
#define DEST_ID_GPC_SQ_STATS_0_SIZE          0x7FF
#define DEST_ID_GPC_SQ_STATS_1_SIZE          0x7FF
#define DEST_ID_GPC_SQ_STATS_2_SIZE          0x7FF
#define DEST_ID_GPC_SQ_STATS_3_SIZE          0x7FF
#define DEST_ID_GPC_SQ_STATS_4_SIZE          0x7F
#define DEST_ID_GPC_DG_STATS_0_SIZE          0x46
#define DEST_ID_GPC_EU_STATS_0_SIZE          0xF
#define DEST_ID_GPC_EU1_STATS_0_SIZE         0xF
#define DEST_ID_GPC_EU2_STATS_0_SIZE         0xF
#define DEST_ID_GPC_EU3_STATS_0_SIZE         0xF
#define DEST_ID_GPC_RCP_STATS_0_SIZE         0x422
#define DEST_ID_GPC_TS_STATS_0_SIZE          0x40
#define DEST_ID_GPC_RAST_STATS_0_SIZE        0x2A
#define DEST_ID_GPC_ZS_STATE_0_SIZE          0x40
#define DEST_ID_GPC_ZS_STATE_2_SIZE          0x51
#define DEST_ID_GPC_ZS_STATE_4_SIZE          0x14
#define DEST_ID_GPC_ZS_STATE_6_SIZE          0x30
#define DEST_ID_GPC_ZS_STATE_8_SIZE          0x86
#define DEST_ID_GPC_BLND_STATE_0_SIZE        0x22
#define DEST_ID_GPC_BLND_STATE_2_SIZE        0x9
#define DEST_ID_GPC_BLND_STATE_4_SIZE        0x7
#define DEST_ID_GPC_BLND_STATE_6_SIZE        0x13
#define DEST_ID_GPC_BLND_STATE_8_SIZE        0x31B
#define DEST_ID_GPC_BLND_STATE_10_SIZE       0x17
#define DEST_ID_GPC_BLND_STATE_12_SIZE       0x5
#define DEST_ID_GPC_VARY_STATE_0_SIZE        0x24
#define DEST_ID_GPC_CBI_STATE_0_SIZE         0x303
#define DEST_ID_GPC_PEC_STATE_0_SIZE         0x1
#define DEST_ID_GPC_CPB_STATE_0_SIZE         0x1
#define DEST_ID_GPC_TSM_STATE_0_SIZE         0x6
#define DEST_ID_GPC_TSM_STATE_1_SIZE         0x7FF
#define DEST_ID_GPC_TRD_STATE_0_SIZE         0x8
#define DEST_ID_GPC_TAG_STATE_0_SIZE         0x14
#define DEST_ID_GPC_TSG_STATE_0_SIZE         0x0
#define DEST_ID_GPC_TRS_STATE_0_SIZE         0x0
#define DEST_ID_GPC_TCC_STATE_0_SIZE         0x420
#define DEST_ID_GPC_TCC_STATE_2_SIZE         0x7FF
#define DEST_ID_GPC_TCC_STATE_3_SIZE         0x7FF
#define DEST_ID_GPC_TFU_STATE_0_SIZE         0x2
#define DEST_ID_COM_CTRL_STATE_0_SIZE        0x11
#define DEST_ID_BVH_BVHM_STATE_0_SIZE        0x706
#define DEST_ID_BVH_BSETUP_STATE_0_SIZE      0xE
#define DEST_ID_BVH_BRANK_STATE_0_SIZE       0x39
#define DEST_ID_BVH_BEMIT_STATE_0_SIZE       0x701
#define DEST_ID_BVH_BEMIT_STATE_1_SIZE       0x4
#define DEST_ID_BVH_BSAH_STATE_0_SIZE        0x601
#define DEST_ID_BVH_BCACHE_STATE_0_SIZE      0x718
#define DEST_ID_BVH_BCACHE_STATE_1_SIZE      0x0
#define DEST_ID_BVH_PEC_STATE_0_SIZE         0x1
#define DEST_ID_FCM_JOB_STATE_0_SIZE         0x501
#define DEST_ID_FCM_JOB_STATE_2_SIZE         0x7FF
#define DEST_ID_FCM_JOB_STATE_3_SIZE         0x108
#define DEST_ID_FCM_CQ_VCQ_STATE_0_SIZE      0x32
#define DEST_ID_FCM_CQ_QM_STATE_0_SIZE       0x31A
#define DEST_ID_FCM_CQ_SM_STATE_0_SIZE       0x1D6
#define DEST_ID_FCM_FCP_STATE_0_SIZE         0x128
#define DEST_ID_FCM_FCP_CTRL_STATE_0_SIZE    0x11
#define DEST_ID_FCM_MISC_CTRL_STATE_0_SIZE   0xD
#define DEST_ID_FCM_PEC_STATE_0_SIZE         0x1
#define DEST_ID_FCM_TOP_FCM_STATE_0_SIZE     0x6
#define DEST_ID_FCM_TOP_GPU_STATE_0_SIZE     0xA
#define DEST_ID_L2MMU_L2RO_STATE_0_SIZE      0x7FF
#define DEST_ID_L2MMU_L2RW_STATE_0_SIZE      0x7FF
#define DEST_ID_L2MMU_L2MIF_STATE_0_SIZE     0x100
#define DEST_ID_L2MMU_MMU_STATE_0_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_1_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_2_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_3_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_4_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_5_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_6_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_7_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_8_SIZE       0x7FF
#define DEST_ID_L2MMU_MMU_STATE_9_SIZE       0x7FF
#define DEST_ID_L2MMU_GBI_STATE_0_SIZE       0x2A2
#define DEST_ID_L2MMU_MCB_STATE_0_SIZE       0x6
#define DEST_ID_L2MMU_CPB_STATE_0_SIZE       0x7
#define DEST_ID_L2MMU_PEU_STATE_0_SIZE       0x1
#define DEST_ID_L2MMU_RTU_STATE_0_SIZE       0x3C
#define DEST_ID_L2MMU_RTU1_STATE_0_SIZE      0x3C
#define DEST_ID_L2MMU_L2VPM_STATE_0_SIZE     0x38
#define DEST_ID_L2MMU_UTLB_STATE_0_SIZE      0x7FF
#define DEST_ID_L2MMU_UTLB_STATE_1_SIZE      0x400
#define DEST_ID_L2MMU_UTLB1_STATE_0_SIZE     0x7FF
#define DEST_ID_L2MMU_UTLB1_STATE_1_SIZE     0x400
#define DEST_ID_L2MMU_UTLB2_STATE_0_SIZE     0x7FF
#define DEST_ID_L2MMU_UTLB2_STATE_1_SIZE     0x400
#define DEST_ID_L2MMU_UTLB3_STATE_0_SIZE     0x7FF
#define DEST_ID_L2MMU_UTLB3_STATE_1_SIZE     0x400
#define DEST_ID_L2MMU_UTLB4_STATE_0_SIZE     0x7FF
#define DEST_ID_L2MMU_UTLB4_STATE_1_SIZE     0x400
#define DEST_ID_BIN_JCU_STATE_0_SIZE         0x23
#define DEST_ID_BIN_VF_STATE_0_SIZE          0x7
#define DEST_ID_BIN_VF_STATE_1_SIZE          0x14
#define DEST_ID_BIN_PA_STATE_0_SIZE          0x7
#define DEST_ID_BIN_TESS_STATE_0_SIZE        0x6
#define DEST_ID_BIN_TESS_STATE_1_SIZE        0x0
#define DEST_ID_BIN_UTC_STATE_0_SIZE         0x13
#define DEST_ID_BIN_OA_STATE_0_SIZE          0x7
#define DEST_ID_BIN_OA_STATE_1_SIZE          0x3
#define DEST_ID_BIN_GPC_ARB_STATE_0_SIZE     0x44
#define DEST_ID_BIN_BTC_TOP_STATE_0_SIZE     0x6
#define DEST_ID_BIN_BTS_STATE_0_SIZE         0x29
#define DEST_ID_BIN_BRAST_STATE_0_SIZE       0x19
#define DEST_ID_BIN_BCZ_STATE_0_SIZE         0x3A
#define DEST_ID_BIN_REJ_SYNC_STATE_0_SIZE    0x8
#define DEST_ID_BIN_SPU_STATE_0_SIZE         0x18
#define DEST_ID_BIN_SC_STATE_0_SIZE          0x3
#define DEST_ID_BIN_PEC_STATE_0_SIZE         0x1

#endif  /* HVGR_REGMAP_DEBUG_BUS_H */
