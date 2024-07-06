/*---------------------------------------------------------------------------
 * This file is autogenerated file using huawei LCD parser. Please do not edit it.
 * Update input XML file to add a new entry or update variable in this file
 * Parser location: vendor/huawei/chipset_common/devkit/lcdkit/tools 
 *---------------------------------------------------------------------------*/

#ifndef _LCDKIT_EFFECT__H_
#define _LCDKIT_EFFECT__H_


#include "plat_effect_para.h"

/*---------------------------------------------------------------------------*/
/* static panel selection variable                                           */
/*---------------------------------------------------------------------------*/
enum {
DEFAULT_AUO_OTM1901A_5P2_1080P_VIDEO_DEFAULT_PANEL,
UDP_190_C07_7P847_UDP_PANEL,
UDP_190_C07_6P39_UDP_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_310_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_H01_7P847_PANEL,
ALTB_190_C07_1_7P847_PANEL,
ALTB_310_C07_1_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_H01_1_7P847_PANEL,
ALTB_190_H01_1_7P847_PANEL,
ALTB_190_H01_1_7P847_PANEL,
ALTB_190_H01_1_7P847_PANEL,
ALTB_310_C07_7P847_PANEL,
ALTB_190_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_190_H02_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_AUO_6P39_DEFAULT_PANEL,
ALTB_190_C07_1_7P847_PANEL,
ALTB_190_H01_7P847_PANEL,
ALTB_310_C07_1_7P847_PANEL,
ALTB_190_C07_1_7P847_PANEL,
ALTB_310_C07_1_7P847_PANEL,
ALTB_190_C07_1_7P847_PANEL,
ALTB_310_C07_1_7P847_PANEL,
ALTB_190_H01_7P847_PANEL,
ALTB_190_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_190_H02_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_310_C07_6P39_PANEL,
ALTB_AUO_6P39_DEFAULT_PANEL,
ALTB_190_C09_7P847_PANEL,
ALTB_190_C09_1_7P847_PANEL,
ALTB_190_C09_7P847_PANEL,
ALTB_190_C09_1_7P847_PANEL,
ALTB_AUO_7P847_DEFAULT_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_310_C07_7P847_PANEL,
ALTB_190_C09_7P847_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_1_7P847_PANEL,
ALTB_310_C07_1_7P847_PANEL,
ALTB_190_C09_1_7P847_PANEL,
ALTB_190_C07_1_7P847_PANEL,
ALTB_190_C07_1_6P39_PANEL,
ALTB_310_C07_1_6P39_PANEL,
ALTB_190_H02_1_6P39_PANEL,
ALTB_AUO_6P39_DEFAULT_PANEL,
ALTB_AUO_7P847_DEFAULT_PANEL,
ALTB_190_C07_7P847_PANEL,
ALTB_190_C07_1_7P847_PANEL,
ALTB_310_C07_7P847_PANEL,
ALTB_310_C07_1_7P847_PANEL,
ALTB_310_C07_VN4_7P847_PANEL,
ALTB_310_C07_VN4_1_7P847_PANEL,
ALTB_190_C09_VN1_7P847_PANEL,
ALTB_190_C09_VN1_1_7P847_PANEL,
ALTB_190_C07_1_6P39_PANEL,
ALTB_310_C07_1_6P39_PANEL,
ALTB_190_H02_1_6P39_PANEL,
ALTB_AUO_6P39_DEFAULT_PANEL,
ALTB_AUO_7P847_DEFAULT_PANEL,
ALTB_AUO_7P847_DEFAULT_PANEL,
ALTB_AUO_7P847_DEFAULT_PANEL,
BRA_190_C08_6P69_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_310_C08_6P69_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_310_H01_6P69_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_190_H01_6P69_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_AUO_6P69_DEFAULT_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_190_H00_6P74_PANEL,
BRA_190_C08_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_310_C08_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_310_H01_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_AUO_6P69_DEFAULT_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_190_H01_1_6P69_PANEL,
BRA_190_C08_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_310_C08_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_310_H01_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_AUO_6P69_DEFAULT_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
BRA_190_H01_2_6P69_PANEL,
ALN_190_C08_6P82_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_310_C08_6P82_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_310_H01_6P82_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_190_H01_6P82_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_AUO_6P82_DEFAULT_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_190_H00_1_6P74_PANEL,
ALN_190_C08_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_310_C08_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_310_H01_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_AUO_6P82_DEFAULT_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_190_H01_1_6P82_PANEL,
ALN_190_C08_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_310_C08_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_310_H01_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_AUO_6P82_DEFAULT_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
ALN_190_H01_2_6P82_PANEL,
PCE_190_H01_13P2_PANEL,
PCE_310_H01_13P2_PANEL,
PCE_AUO_13P2_DEFAULT_PANEL,
PCE_190_H01_1_13P2_PANEL,
PCE_310_H01_1_13P2_PANEL,
PCE_AUO_13P2_DEFAULT_PANEL,
LEM_190_C08_6P94_PANEL,
LEM_190_H02_6P94_PANEL,
LEM_310_H02_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_192_C08_6P94_PANEL,
LEM_192_H02_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_310_C08_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_190_C10_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_310_C10_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_190_C08_1_6P94_PANEL,
LEM_190_H02_1_6P94_PANEL,
LEM_310_H02_1_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_192_C08_1_6P94_PANEL,
LEM_192_H02_1_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_310_C08_1_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_AUO_DEF_6P94_PANEL,
LEM_190_C10_1_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_310_C10_1_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
LEM_AUO_DEF_1P15_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_AUO_10P2_DEFAULT_PANEL,
GRL_190_C08_10P2_PANEL,
XYAO_350_H01_11P0_PANEL,
XYAO_350_C00_11P0_PANEL,
XYAO_AUO_11P0_DEFAULT_PANEL,
ADL_290_C08_1_6P76_PANEL,
ADL_190_C08_1_6P76_PANEL,
ADL_AUO_6P82_DEFAULT_PANEL,
INVALID_PANEL_ID,
};


/*---------------------------------------------------------------------------*/
/* static panel board mapping variable                                           */
/*---------------------------------------------------------------------------*/
struct lcd_kit_board_map {
    uint32_t lcd_id;
    char *panel_compatible;
    uint32_t product_id;
};

static struct lcd_kit_board_map lcd_kit_map[] = {
    {DEFAULT_AUO_OTM1901A_5P2_1080P_VIDEO_DEFAULT_PANEL, "auo_otm1901a_5p2_1080p_video_default", 0},
    {UDP_190_C07_7P847_UDP_PANEL, "190_c07_7p847", 1000},
    {UDP_190_C07_6P39_UDP_PANEL, "190_c07_6p39", 1000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_310_C07_7P847_PANEL, "310_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_H01_7P847_PANEL, "190_h01_7p847", 2000},
    {ALTB_190_C07_1_7P847_PANEL, "190_c07_1_7p847", 2000},
    {ALTB_310_C07_1_7P847_PANEL, "310_c07_1_7p847", 2000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 2000},
    {ALTB_190_H01_1_7P847_PANEL, "190_h01_1_7p847", 2000},
    {ALTB_190_H01_1_7P847_PANEL, "190_h01_1_7p847", 2000},
    {ALTB_190_H01_1_7P847_PANEL, "190_h01_1_7p847", 3000},
    {ALTB_190_H01_1_7P847_PANEL, "190_h01_1_7p847", 3000},
    {ALTB_310_C07_7P847_PANEL, "310_c07_7p847", 2000},
    {ALTB_190_C07_6P39_PANEL, "190_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_190_H02_6P39_PANEL, "190_h02_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 2000},
    {ALTB_AUO_6P39_DEFAULT_PANEL, "auo_6p39_default", 2000},
    {ALTB_190_C07_1_7P847_PANEL, "190_c07_1_7p847", 3000},
    {ALTB_190_H01_7P847_PANEL, "190_h01_7p847", 3000},
    {ALTB_310_C07_1_7P847_PANEL, "310_c07_1_7p847", 3000},
    {ALTB_190_C07_1_7P847_PANEL, "190_c07_1_7p847", 3000},
    {ALTB_310_C07_1_7P847_PANEL, "310_c07_1_7p847", 3000},
    {ALTB_190_C07_1_7P847_PANEL, "190_c07_1_7p847", 3000},
    {ALTB_310_C07_1_7P847_PANEL, "310_c07_1_7p847", 3000},
    {ALTB_190_H01_7P847_PANEL, "190_h01_7p847", 3000},
    {ALTB_190_C07_6P39_PANEL, "190_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_190_H02_6P39_PANEL, "190_h02_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_310_C07_6P39_PANEL, "310_c07_6p39", 3000},
    {ALTB_AUO_6P39_DEFAULT_PANEL, "auo_6p39_default", 3000},
    {ALTB_190_C09_7P847_PANEL, "190_c09_7p847", 2000},
    {ALTB_190_C09_1_7P847_PANEL, "190_c09_1_7p847", 2000},
    {ALTB_190_C09_7P847_PANEL, "190_c09_7p847", 3000},
    {ALTB_190_C09_1_7P847_PANEL, "190_c09_1_7p847", 3000},
    {ALTB_AUO_7P847_DEFAULT_PANEL, "auo_7p847_default", 3000},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 3001},
    {ALTB_310_C07_7P847_PANEL, "310_c07_7p847", 3001},
    {ALTB_190_C09_7P847_PANEL, "190_c09_7p847", 3001},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 3001},
    {ALTB_190_C07_1_7P847_PANEL, "190_c07_1_7p847", 3001},
    {ALTB_310_C07_1_7P847_PANEL, "310_c07_1_7p847", 3001},
    {ALTB_190_C09_1_7P847_PANEL, "190_c09_1_7p847", 3001},
    {ALTB_190_C07_1_7P847_PANEL, "190_c07_1_7p847", 3001},
    {ALTB_190_C07_1_6P39_PANEL, "190_c07_1_6p39", 3001},
    {ALTB_310_C07_1_6P39_PANEL, "310_c07_1_6p39", 3001},
    {ALTB_190_H02_1_6P39_PANEL, "190_h02_1_6p39", 3001},
    {ALTB_AUO_6P39_DEFAULT_PANEL, "auo_6p39_default", 3001},
    {ALTB_AUO_7P847_DEFAULT_PANEL, "auo_7p847_default", 3001},
    {ALTB_190_C07_7P847_PANEL, "190_c07_7p847", 3002},
    {ALTB_190_C07_1_7P847_PANEL, "190_c07_1_7p847", 3002},
    {ALTB_310_C07_7P847_PANEL, "310_c07_7p847", 3002},
    {ALTB_310_C07_1_7P847_PANEL, "310_c07_1_7p847", 3002},
    {ALTB_310_C07_VN4_7P847_PANEL, "310_c07_vn4_7p847", 3002},
    {ALTB_310_C07_VN4_1_7P847_PANEL, "310_c07_vn4_1_7p847", 3002},
    {ALTB_190_C09_VN1_7P847_PANEL, "190_c09_vn1_7p847", 3002},
    {ALTB_190_C09_VN1_1_7P847_PANEL, "190_c09_vn1_1_7p847", 3002},
    {ALTB_190_C07_1_6P39_PANEL, "190_c07_1_6p39", 3002},
    {ALTB_310_C07_1_6P39_PANEL, "310_c07_1_6p39", 3002},
    {ALTB_190_H02_1_6P39_PANEL, "190_h02_1_6p39", 3002},
    {ALTB_AUO_6P39_DEFAULT_PANEL, "auo_6p39_default", 3002},
    {ALTB_AUO_7P847_DEFAULT_PANEL, "auo_7p847_default", 3002},
    {ALTB_AUO_7P847_DEFAULT_PANEL, "auo_7p847_default", 3002},
    {ALTB_AUO_7P847_DEFAULT_PANEL, "auo_7p847_default", 3002},
    {BRA_190_C08_6P69_PANEL, "190_c08_6p69", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_310_C08_6P69_PANEL, "310_c08_6p69", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_310_H01_6P69_PANEL, "310_h01_6p69", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_190_H01_6P69_PANEL, "190_h01_6p69", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_AUO_6P69_DEFAULT_PANEL, "auo_6p69_default", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_190_H00_6P74_PANEL, "190_h00_6p74", 4000},
    {BRA_190_C08_1_6P69_PANEL, "190_c08_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_310_C08_1_6P69_PANEL, "310_c08_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_310_H01_1_6P69_PANEL, "310_h01_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_AUO_6P69_DEFAULT_PANEL, "auo_6p69_default", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_190_H01_1_6P69_PANEL, "190_h01_1_6p69", 4100},
    {BRA_190_C08_2_6P69_PANEL, "190_c08_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_310_C08_2_6P69_PANEL, "310_c08_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_310_H01_2_6P69_PANEL, "310_h01_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_AUO_6P69_DEFAULT_PANEL, "auo_6p69_default", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {BRA_190_H01_2_6P69_PANEL, "190_h01_2_6p69", 4200},
    {ALN_190_C08_6P82_PANEL, "190_c08_6p82", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_310_C08_6P82_PANEL, "310_c08_6p82", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_310_H01_6P82_PANEL, "310_h01_6p82", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_190_H01_6P82_PANEL, "190_h01_6p82", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_AUO_6P82_DEFAULT_PANEL, "auo_6p82_default", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_190_H00_1_6P74_PANEL, "190_h00_1_6p74", 5000},
    {ALN_190_C08_1_6P82_PANEL, "190_c08_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_310_C08_1_6P82_PANEL, "310_c08_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_310_H01_1_6P82_PANEL, "310_h01_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_AUO_6P82_DEFAULT_PANEL, "auo_6p82_default", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_190_H01_1_6P82_PANEL, "190_h01_1_6p82", 5100},
    {ALN_190_C08_2_6P82_PANEL, "190_c08_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_310_C08_2_6P82_PANEL, "310_c08_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_310_H01_2_6P82_PANEL, "310_h01_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_AUO_6P82_DEFAULT_PANEL, "auo_6p82_default", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {ALN_190_H01_2_6P82_PANEL, "190_h01_2_6p82", 5200},
    {PCE_190_H01_13P2_PANEL, "190_h01_13p2", 6000},
    {PCE_310_H01_13P2_PANEL, "310_h01_13p2", 6000},
    {PCE_AUO_13P2_DEFAULT_PANEL, "auo_13p2_default", 6000},
    {PCE_190_H01_1_13P2_PANEL, "190_h01_1_13p2", 6100},
    {PCE_310_H01_1_13P2_PANEL, "310_h01_1_13p2", 6100},
    {PCE_AUO_13P2_DEFAULT_PANEL, "auo_13p2_default", 6100},
    {LEM_190_C08_6P94_PANEL, "190_c08_6p94", 7000},
    {LEM_190_H02_6P94_PANEL, "190_h02_6p94", 7000},
    {LEM_310_H02_6P94_PANEL, "310_h02_6p94", 7000},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7000},
    {LEM_192_C08_6P94_PANEL, "192_c08_6p94", 7000},
    {LEM_192_H02_6P94_PANEL, "192_h02_6p94", 7000},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7000},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7000},
    {LEM_310_C08_6P94_PANEL, "310_c08_6p94", 7000},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7000},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7000},
    {LEM_190_C10_1P15_PANEL, "190_c10_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_310_C10_1P15_PANEL, "310_c10_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7000},
    {LEM_190_C08_1_6P94_PANEL, "190_c08_1_6p94", 7100},
    {LEM_190_H02_1_6P94_PANEL, "190_h02_1_6p94", 7100},
    {LEM_310_H02_1_6P94_PANEL, "310_h02_1_6p94", 7100},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7100},
    {LEM_192_C08_1_6P94_PANEL, "192_c08_1_6p94", 7100},
    {LEM_192_H02_1_6P94_PANEL, "192_h02_1_6p94", 7100},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7100},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7100},
    {LEM_310_C08_1_6P94_PANEL, "310_c08_1_6p94", 7100},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7100},
    {LEM_AUO_DEF_6P94_PANEL, "auo_def_6p94", 7100},
    {LEM_190_C10_1_1P15_PANEL, "190_c10_1_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_310_C10_1_1P15_PANEL, "310_c10_1_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {LEM_AUO_DEF_1P15_PANEL, "auo_def_1p15", 7100},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_AUO_10P2_DEFAULT_PANEL, "auo_10p2_default", 8000},
    {GRL_190_C08_10P2_PANEL, "190_c08_10p2", 8000},
    {XYAO_350_H01_11P0_PANEL, "350_h01_11p0", 9000},
    {XYAO_350_C00_11P0_PANEL, "350_c00_11p0", 9000},
    {XYAO_AUO_11P0_DEFAULT_PANEL, "auo_11p0_default", 9000},
    {ADL_290_C08_1_6P76_PANEL, "290_c08_1_6p76", 10000},
    {ADL_190_C08_1_6P76_PANEL, "190_c08_1_6p76", 10000},
    {ADL_AUO_6P82_DEFAULT_PANEL, "auo_6p82_default", 10000},
};

static void lcd_kit_effect_get_data(uint8_t panel_id, struct hisi_panel_info* pinfo)
{
    if (pinfo->gamma_support == 1)
    {
        pinfo->gamma_lut_table_R = plat_gamma_lut_table_R;
        pinfo->gamma_lut_table_G = plat_gamma_lut_table_G;
        pinfo->gamma_lut_table_B = plat_gamma_lut_table_B;
        pinfo->gamma_lut_table_len = ARRAY_SIZE(plat_gamma_lut_table_R);
        pinfo->igm_lut_table_R = plat_igm_lut_table_R;
        pinfo->igm_lut_table_G = plat_igm_lut_table_G;
        pinfo->igm_lut_table_B = plat_igm_lut_table_B;
        pinfo->igm_lut_table_len = ARRAY_SIZE(plat_igm_lut_table_R);
        pinfo->gmp_lut_table_low32bit = &plat_gmp_lut_table_low32bit[0][0][0];
        pinfo->gmp_lut_table_high4bit = &plat_gmp_lut_table_high4bit[0][0][0];
        pinfo->gmp_lut_table_len = ARRAY_3_SIZE(plat_gmp_lut_table_low32bit);
        pinfo->xcc_table = plat_xcc_table;
        pinfo->xcc_table_len = ARRAY_SIZE(plat_xcc_table);
    }
    switch (panel_id) {
    default:
        LCD_KIT_INFO("Panel ID not detected %d\n", panel_id);
        break;
    }
}

static uint8_t lcd_kit_get_panel_id(uint32_t product_id, char* compatible)
{
    uint8_t lcd_panel_id = DEFAULT_AUO_OTM1901A_5P2_1080P_VIDEO_DEFAULT_PANEL;
    int i = 0;
    int len = strlen(compatible);
    int length = 0;
    for (i = 0; i < ARRAY_SIZE(lcd_kit_map); ++i) {
        length = strlen(lcd_kit_map[i].panel_compatible);
        if ((lcd_kit_map[i].product_id == product_id) && !strncmp(lcd_kit_map[i].panel_compatible, compatible, (length > len?length:len))){
            lcd_panel_id = lcd_kit_map[i].lcd_id;
            break;
        }
    }

    HISI_FB_INFO("lcd_panel_id = %d\n", lcd_panel_id);
    return lcd_panel_id;
}


#endif /*_LCDKIT_EFFECT__H_*/
