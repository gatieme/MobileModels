/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: lcdkit parse spr function for lcd driver
 * Author: weiyuantian
 * Create: 2023-05-17
 */

#include "lcd_kit_utils.h"
#include "lcd_kit_parse.h"

#define LCD_MAX_SIZE 1548

uint32_t spr_lut_table_temp[LCD_MAX_SIZE] = {
	0,   72,  144,  216,  288,  360,  426,  486,  541,  592,  641,  686,  730,  772,  812,  850,  887,  923,  957,  991,
		1024, 1055, 1086, 1116, 1146, 1174, 1203, 1230, 1257, 1284, 1310, 1335, 1360, 1385, 1409, 1433, 1456, 1479, 1502, 1524,
		1547, 1568, 1590, 1611, 1632, 1653, 1673, 1693, 1713, 1733, 1753, 1772, 1791, 1810, 1829, 1847, 1866, 1884, 1902, 1920,
		1937, 1955, 1972, 1989, 2006, 2023, 2040, 2057, 2073, 2089, 2106, 2122, 2138, 2153, 2169, 2185, 2200, 2216, 2231, 2246,
		2261, 2276, 2291, 2306, 2320, 2335, 2349, 2364, 2378, 2392, 2406, 2420, 2434, 2448, 2462, 2475, 2489, 2503, 2516, 2529,
		2543, 2556, 2569, 2582, 2595, 2608, 2621, 2634, 2647, 2659, 2672, 2684, 2697, 2709, 2722, 2734, 2746, 2759, 2771, 2783,
		2795, 2807, 2819, 2831, 2842, 2854, 2866, 2877, 2889, 2901, 2912, 2924, 2935, 2946, 2958, 2969, 2980, 2991, 3003, 3014,
		3025, 3036, 3047, 3058, 3068, 3079, 3090, 3101, 3112, 3122, 3133, 3143, 3154, 3164, 3175, 3185, 3196, 3206, 3217, 3227,
		3237, 3247, 3257, 3268, 3278, 3288, 3298, 3308, 3318, 3328, 3338, 3348, 3358, 3367, 3377, 3387, 3397, 3406, 3416, 3426,
		3435, 3445, 3454, 3464, 3474, 3483, 3492, 3502, 3511, 3521, 3530, 3539, 3549, 3558, 3567, 3576, 3585, 3595, 3604, 3613,
		3622, 3631, 3640, 3649, 3658, 3667, 3676, 3685, 3694, 3702, 3711, 3720, 3729, 3738, 3746, 3755, 3764, 3772, 3781, 3790,
		3798, 3807, 3815, 3824, 3833, 3841, 3850, 3858, 3866, 3875, 3883, 3892, 3900, 3908, 3917, 3925, 3933, 3942, 3950, 3958,
		3966, 3974, 3983, 3991, 3999, 4007, 4015, 4023, 4031, 4039, 4047, 4055, 4063, 4071, 4079, 4087, 4096, 0,

		0,   72,  144,  216,  288,  360,  426,  486,  541,  592,  641,  686,  730,  772,  812,  850,  887,  923,  957,  991,
		1024, 1055, 1086, 1116, 1146, 1174, 1203, 1230, 1257, 1284, 1310, 1335, 1360, 1385, 1409, 1433, 1456, 1479, 1502, 1524,
		1547, 1568, 1590, 1611, 1632, 1653, 1673, 1693, 1713, 1733, 1753, 1772, 1791, 1810, 1829, 1847, 1866, 1884, 1902, 1920,
		1937, 1955, 1972, 1989, 2006, 2023, 2040, 2057, 2073, 2089, 2106, 2122, 2138, 2153, 2169, 2185, 2200, 2216, 2231, 2246,
		2261, 2276, 2291, 2306, 2320, 2335, 2349, 2364, 2378, 2392, 2406, 2420, 2434, 2448, 2462, 2475, 2489, 2503, 2516, 2529,
		2543, 2556, 2569, 2582, 2595, 2608, 2621, 2634, 2647, 2659, 2672, 2684, 2697, 2709, 2722, 2734, 2746, 2759, 2771, 2783,
		2795, 2807, 2819, 2831, 2842, 2854, 2866, 2877, 2889, 2901, 2912, 2924, 2935, 2946, 2958, 2969, 2980, 2991, 3003, 3014,
		3025, 3036, 3047, 3058, 3068, 3079, 3090, 3101, 3112, 3122, 3133, 3143, 3154, 3164, 3175, 3185, 3196, 3206, 3217, 3227,
		3237, 3247, 3257, 3268, 3278, 3288, 3298, 3308, 3318, 3328, 3338, 3348, 3358, 3367, 3377, 3387, 3397, 3406, 3416, 3426,
		3435, 3445, 3454, 3464, 3474, 3483, 3492, 3502, 3511, 3521, 3530, 3539, 3549, 3558, 3567, 3576, 3585, 3595, 3604, 3613,
		3622, 3631, 3640, 3649, 3658, 3667, 3676, 3685, 3694, 3702, 3711, 3720, 3729, 3738, 3746, 3755, 3764, 3772, 3781, 3790,
		3798, 3807, 3815, 3824, 3833, 3841, 3850, 3858, 3866, 3875, 3883, 3892, 3900, 3908, 3917, 3925, 3933, 3942, 3950, 3958,
		3966, 3974, 3983, 3991, 3999, 4007, 4015, 4023, 4031, 4039, 4047, 4055, 4063, 4071, 4079, 4087, 4096, 0,

		0,   72,  144,  216,  288,  360,  426,  486,  541,  592,  641,  686,  730,  772,  812,  850,  887,  923,  957,  991,
		1024, 1055, 1086, 1116, 1146, 1174, 1203, 1230, 1257, 1284, 1310, 1335, 1360, 1385, 1409, 1433, 1456, 1479, 1502, 1524,
		1547, 1568, 1590, 1611, 1632, 1653, 1673, 1693, 1713, 1733, 1753, 1772, 1791, 1810, 1829, 1847, 1866, 1884, 1902, 1920,
		1937, 1955, 1972, 1989, 2006, 2023, 2040, 2057, 2073, 2089, 2106, 2122, 2138, 2153, 2169, 2185, 2200, 2216, 2231, 2246,
		2261, 2276, 2291, 2306, 2320, 2335, 2349, 2364, 2378, 2392, 2406, 2420, 2434, 2448, 2462, 2475, 2489, 2503, 2516, 2529,
		2543, 2556, 2569, 2582, 2595, 2608, 2621, 2634, 2647, 2659, 2672, 2684, 2697, 2709, 2722, 2734, 2746, 2759, 2771, 2783,
		2795, 2807, 2819, 2831, 2842, 2854, 2866, 2877, 2889, 2901, 2912, 2924, 2935, 2946, 2958, 2969, 2980, 2991, 3003, 3014,
		3025, 3036, 3047, 3058, 3068, 3079, 3090, 3101, 3112, 3122, 3133, 3143, 3154, 3164, 3175, 3185, 3196, 3206, 3217, 3227,
		3237, 3247, 3257, 3268, 3278, 3288, 3298, 3308, 3318, 3328, 3338, 3348, 3358, 3367, 3377, 3387, 3397, 3406, 3416, 3426,
		3435, 3445, 3454, 3464, 3474, 3483, 3492, 3502, 3511, 3521, 3530, 3539, 3549, 3558, 3567, 3576, 3585, 3595, 3604, 3613,
		3622, 3631, 3640, 3649, 3658, 3667, 3676, 3685, 3694, 3702, 3711, 3720, 3729, 3738, 3746, 3755, 3764, 3772, 3781, 3790,
		3798, 3807, 3815, 3824, 3833, 3841, 3850, 3858, 3866, 3875, 3883, 3892, 3900, 3908, 3917, 3925, 3933, 3942, 3950, 3958,
		3966, 3974, 3983, 3991, 3999, 4007, 4015, 4023, 4031, 4039, 4047, 4055, 4063, 4071, 4079, 4087, 4096, 0,

		0,    4,    7,   11,   14,   18,   21,   25,   28,   32,   36,   39,   43,   46,   50,   53,   57,   60,   64,   68,
		71,   74,   78,   82,   86,   89,   93,   98,  102,  106,  110,  115,  119,  124,  129,  134,  139,  144,  149,  154,
		160,  165,  171,  176,  182,  188,  194,  200,  206,  213,  219,  226,  232,  239,  246,  253,  260,  267,  274,  282,
		289,  297,  304,  312,  320,  328,  336,  344,  353,  361,  370,  378,  387,  396,  405,  414,  423,  433,  442,  452,
		462,  471,  481,  491,  501,  512,  522,  532,  543,  554,  565,  576,  587,  598,  609,  620,  632,  644,  655,  667,
		679,  691,  703,  716,  728,  741,  753,  766,  779,  792,  805,  819,  832,  846,  859,  873,  887,  901,  915,  929,
		944,  958,  973,  988, 1002, 1017, 1032, 1048, 1063, 1078, 1094, 1110, 1126, 1142, 1158, 1174, 1190, 1207, 1223, 1240,
		1257, 1274, 1291, 1308, 1325, 1343, 1360, 1378, 1396, 1414, 1432, 1450, 1468, 1487, 1506, 1524, 1543, 1562, 1581, 1600,
		1620, 1639, 1659, 1679, 1698, 1718, 1739, 1759, 1779, 1800, 1820, 1841, 1862, 1883, 1904, 1926, 1947, 1969, 1990, 2012,
		2034, 2056, 2078, 2101, 2123, 2146, 2168, 2191, 2214, 2237, 2261, 2284, 2308, 2331, 2355, 2379, 2403, 2427, 2452, 2476,
		2501, 2525, 2550, 2575, 2600, 2626, 2651, 2677, 2702, 2728, 2754, 2780, 2806, 2833, 2859, 2886, 2912, 2939, 2966, 2993,
		3021, 3048, 3076, 3103, 3131, 3159, 3187, 3216, 3244, 3273, 3301, 3330, 3359, 3388, 3417, 3447, 3476, 3506, 3535, 3565,
		3595, 3626, 3656, 3686, 3717, 3748, 3779, 3810, 3841, 3872, 3903, 3935, 3967, 3999, 4031, 4063, 4096, 0,

		0,    4,    7,   11,   14,   18,   21,   25,   28,   32,   36,   39,   43,   46,   50,   53,   57,   60,   64,   68,
		71,   74,   78,   82,   86,   89,   93,   98,  102,  106,  110,  115,  119,  124,  129,  134,  139,  144,  149,  154,
		160,  165,  171,  176,  182,  188,  194,  200,  206,  213,  219,  226,  232,  239,  246,  253,  260,  267,  274,  282,
		289,  297,  304,  312,  320,  328,  336,  344,  353,  361,  370,  378,  387,  396,  405,  414,  423,  433,  442,  452,
		462,  471,  481,  491,  501,  512,  522,  532,  543,  554,  565,  576,  587,  598,  609,  620,  632,  644,  655,  667,
		679,  691,  703,  716,  728,  741,  753,  766,  779,  792,  805,  819,  832,  846,  859,  873,  887,  901,  915,  929,
		944,  958,  973,  988, 1002, 1017, 1032, 1048, 1063, 1078, 1094, 1110, 1126, 1142, 1158, 1174, 1190, 1207, 1223, 1240,
		1257, 1274, 1291, 1308, 1325, 1343, 1360, 1378, 1396, 1414, 1432, 1450, 1468, 1487, 1506, 1524, 1543, 1562, 1581, 1600,
		1620, 1639, 1659, 1679, 1698, 1718, 1739, 1759, 1779, 1800, 1820, 1841, 1862, 1883, 1904, 1926, 1947, 1969, 1990, 2012,
		2034, 2056, 2078, 2101, 2123, 2146, 2168, 2191, 2214, 2237, 2261, 2284, 2308, 2331, 2355, 2379, 2403, 2427, 2452, 2476,
		2501, 2525, 2550, 2575, 2600, 2626, 2651, 2677, 2702, 2728, 2754, 2780, 2806, 2833, 2859, 2886, 2912, 2939, 2966, 2993,
		3021, 3048, 3076, 3103, 3131, 3159, 3187, 3216, 3244, 3273, 3301, 3330, 3359, 3388, 3417, 3447, 3476, 3506, 3535, 3565,
		3595, 3626, 3656, 3686, 3717, 3748, 3779, 3810, 3841, 3872, 3903, 3935, 3967, 3999, 4031, 4063, 4096, 0,

		0,    4,    7,   11,   14,   18,   21,   25,   28,   32,   36,   39,   43,   46,   50,   53,   57,   60,   64,   68,
		71,   74,   78,   82,   86,   89,   93,   98,  102,  106,  110,  115,  119,  124,  129,  134,  139,  144,  149,  154,
		160,  165,  171,  176,  182,  188,  194,  200,  206,  213,  219,  226,  232,  239,  246,  253,  260,  267,  274,  282,
		289,  297,  304,  312,  320,  328,  336,  344,  353,  361,  370,  378,  387,  396,  405,  414,  423,  433,  442,  452,
		462,  471,  481,  491,  501,  512,  522,  532,  543,  554,  565,  576,  587,  598,  609,  620,  632,  644,  655,  667,
		679,  691,  703,  716,  728,  741,  753,  766,  779,  792,  805,  819,  832,  846,  859,  873,  887,  901,  915,  929,
		944,  958,  973,  988, 1002, 1017, 1032, 1048, 1063, 1078, 1094, 1110, 1126, 1142, 1158, 1174, 1190, 1207, 1223, 1240,
		1257, 1274, 1291, 1308, 1325, 1343, 1360, 1378, 1396, 1414, 1432, 1450, 1468, 1487, 1506, 1524, 1543, 1562, 1581, 1600,
		1620, 1639, 1659, 1679, 1698, 1718, 1739, 1759, 1779, 1800, 1820, 1841, 1862, 1883, 1904, 1926, 1947, 1969, 1990, 2012,
		2034, 2056, 2078, 2101, 2123, 2146, 2168, 2191, 2214, 2237, 2261, 2284, 2308, 2331, 2355, 2379, 2403, 2427, 2452, 2476,
		2501, 2525, 2550, 2575, 2600, 2626, 2651, 2677, 2702, 2728, 2754, 2780, 2806, 2833, 2859, 2886, 2912, 2939, 2966, 2993,
		3021, 3048, 3076, 3103, 3131, 3159, 3187, 3216, 3244, 3273, 3301, 3330, 3359, 3388, 3417, 3447, 3476, 3506, 3535, 3565,
		3595, 3626, 3656, 3686, 3717, 3748, 3779, 3810, 3841, 3872, 3903, 3935, 3967, 3999, 4031, 4063, 4096, 0,
};

static void lcd_kit_spr_border_rlr_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-r-borderlr-value",
		&pinfo->spr.spr_r_borderlr.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-g-borderlr-value",
		&pinfo->spr.spr_g_borderlr.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-b-borderlr-value",
		&pinfo->spr.spr_b_borderlr.value, 0);
}

static void lcd_kit_spr_border_rlb_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-r-bordertb-value",
		&pinfo->spr.spr_r_bordertb.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-g-bordertb-value",
		&pinfo->spr.spr_g_bordertb.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-b-bordertb-value",
		&pinfo->spr.spr_b_bordertb.value, 0);
}

static void lcd_kit_spr_core_border_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_spr_border_rlr_set(panel_id, np, pinfo);
	lcd_kit_spr_border_rlb_set(panel_id, np, pinfo);

	lcd_kit_parse_u32(np, "lcd-kit,spr-pixgain-reg-value",
		&pinfo->spr.spr_pixgain_reg.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-pixgain-reg1-value",
		&pinfo->spr.spr_pixgain_reg1.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-P0-border-value",
		&pinfo->spr.spr_border_p0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-P1-border-value",
		&pinfo->spr.spr_border_p1.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-P2-border-value",
		&pinfo->spr.spr_border_p2.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-P3-border-value",
		&pinfo->spr.spr_border_p3.value, 0);
}

static void lcd_kit_spr_larea_border_rgb_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-larea-border-r-value",
		&pinfo->spr.spr_larea_border_r.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-larea-border-g-value",
		&pinfo->spr.spr_larea_border_g.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-larea-border-b-value",
		&pinfo->spr.spr_larea_border_b.value, 0);
}

static void lcd_kit_spr_core_larea_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-larea-start-value",
		&pinfo->spr.spr_larea_start.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-larea-end-value",
		&pinfo->spr.spr_larea_end.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-larea-offset-value",
		&pinfo->spr.spr_larea_offset.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-larea-gain-value",
		&pinfo->spr.spr_larea_gain.value, 0);

	lcd_kit_spr_larea_border_rgb_set(panel_id, np, pinfo);
}

static void lcd_kit_spr_coeffs_b_v0h0_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h0-b0-value",
		&pinfo->spr.spr_coeff_v0h0_b0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h0-b1-value",
		&pinfo->spr.spr_coeff_v0h0_b1.value, 0);
}

static void lcd_kit_spr_coeffs_b_v0h1_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h1-b0-value",
		&pinfo->spr.spr_coeff_v0h1_b0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h1-b1-value",
		&pinfo->spr.spr_coeff_v0h1_b1.value, 0);
}

static void lcd_kit_spr_coeffs_b_v1h0_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h0-b0-value",
		&pinfo->spr.spr_coeff_v1h0_b0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h0-b1-value",
		&pinfo->spr.spr_coeff_v1h0_b1.value, 0);
}

static void lcd_kit_spr_coeffs_b_v1h1_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h1-b0-value",
		&pinfo->spr.spr_coeff_v1h1_b0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h1-b1-value",
		&pinfo->spr.spr_coeff_v1h1_b1.value, 0);
}

static void lcd_kit_spr_core_coeffs_b_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_spr_coeffs_b_v0h0_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_b_v0h1_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_b_v1h0_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_b_v1h1_set(panel_id, np, pinfo);
}

static void lcd_kit_spr_coeffs_r_v0h0_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h0-r0.value",
		&pinfo->spr.spr_coeff_v0h0_r0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h0-r1-value",
		&pinfo->spr.spr_coeff_v0h0_r1.value, 0);
}

static void lcd_kit_spr_coeffs_r_v0h1_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h1-r0-value",
		&pinfo->spr.spr_coeff_v0h1_r0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h1-r1-value",
		&pinfo->spr.spr_coeff_v0h1_r1.value, 0);
}

static void lcd_kit_spr_coeffs_r_v1h0_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h0-r0-value",
		&pinfo->spr.spr_coeff_v1h0_r0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h0-r1-value",
		&pinfo->spr.spr_coeff_v1h0_r1.value, 0);
}

static void lcd_kit_spr_coeffs_r_v1h1_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h1-r0-value",
		&pinfo->spr.spr_coeff_v1h1_r0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h1-r1-value",
		&pinfo->spr.spr_coeff_v1h1_r1.value, 0);
}

static void lcd_kit_spr_core_coeffs_r_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_spr_coeffs_r_v0h0_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_r_v0h1_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_r_v1h0_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_r_v1h1_set(panel_id, np, pinfo);
}

static void lcd_kit_spr_coeffs_g_v0h0_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h0-g0-value",
		&pinfo->spr.spr_coeff_v0h0_g0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h0-g1-value",
		&pinfo->spr.spr_coeff_v0h0_g1.value, 0);
}

static void lcd_kit_spr_coeffs_g_v0h1_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h1-g0-value",
		&pinfo->spr.spr_coeff_v0h1_g0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v0h1-g1-value",
		&pinfo->spr.spr_coeff_v0h1_g1.value, 0);
}

static void lcd_kit_spr_coeffs_g_v1h0_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h0-g0-value",
		&pinfo->spr.spr_coeff_v1h0_g0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h0-g1-value",
		&pinfo->spr.spr_coeff_v1h0_g1.value, 0);
}

static void lcd_kit_spr_coeffs_g_v1h1_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h1-g0-value",
		&pinfo->spr.spr_coeff_v1h1_g0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-coeff-v1h1-g1-value",
		&pinfo->spr.spr_coeff_v1h1_g1.value, 0);
}

static void lcd_kit_spr_core_coeffs_g_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_spr_coeffs_g_v0h0_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_g_v0h1_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_g_v1h0_set(panel_id, np, pinfo);
	lcd_kit_spr_coeffs_g_v1h1_set(panel_id, np, pinfo);
}

static void lcd_kit_spr_core_edgestr_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-edgestr-r-value",
		&pinfo->spr.spr_edgestr_r.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-edgestr-g-value",
		&pinfo->spr.spr_edgestr_g.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-edgestr-b-value",
		&pinfo->spr.spr_edgestr_b.value, 0);
}

static void lcd_kit_spr_core_dir_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-dir-min-value",
		&pinfo->spr.spr_dir_min.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-dir-max-value",
		&pinfo->spr.spr_dir_max.value, 0);
}

static void lcd_kit_spr_core_blend_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-blend-value",
		&pinfo->spr.spr_blend.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-weight-value",
		&pinfo->spr.spr_weight.value, 0);
}

static void lcd_kit_spr_diffdirgain_r_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-diff-r0-value",
		&pinfo->spr.spr_diff_r0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-diff-r1-value",
		&pinfo->spr.spr_diff_r1.value, 0);
}

static void lcd_kit_spr_diffdirgain_g_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-diff-g0-value",
		&pinfo->spr.spr_diff_g0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-diff-g1-value",
		&pinfo->spr.spr_diff_g1.value, 0);
}

static void lcd_kit_spr_diffdirgain_b_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-diff-b0-value",
		&pinfo->spr.spr_diff_b0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-diff-b1-value",
		&pinfo->spr.spr_diff_b1.value, 0);
}

static void lcd_kit_spr_core_diffdirgain_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_spr_diffdirgain_r_set(panel_id, np, pinfo);
	lcd_kit_spr_diffdirgain_g_set(panel_id, np, pinfo);
	lcd_kit_spr_diffdirgain_b_set(panel_id, np, pinfo);
}

static void lcd_kit_spr_core_horz_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-horzgradblend-value",
		&pinfo->spr.spr_horzgradblend.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-horzbdbld-value",
		&pinfo->spr.spr_horzbdbld.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-horzbdweight-value",
		&pinfo->spr.spr_horzbdweight.value, 0);
}

static void lcd_kit_spr_vert_gain_rgb_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-vertbd-gain-r-value",
		&pinfo->spr.spr_vertbd_gain_r.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-vertbd-gain-g-value",
		&pinfo->spr.spr_vertbd_gain_g.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-vertbd-gain-b-value",
		&pinfo->spr.spr_vertbd_gain_b.value, 0);
}

static void lcd_kit_spr_core_vert_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-vertbdbld-value",
		&pinfo->spr.spr_vertbdbld.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-vertbdweight-value",
		&pinfo->spr.spr_vertbdweight.value, 0);

	lcd_kit_spr_vert_gain_rgb_set(panel_id, np, pinfo);
}

static void lcd_kit_spr_txip_coef_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-coef0-value",
		&pinfo->spr.txip_coef0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-coef1-value",
		&pinfo->spr.txip_coef1.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-coef2-value",
		&pinfo->spr.txip_coef2.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-coef3-value",
		&pinfo->spr.txip_coef3.value, 0);
}

static void lcd_kit_spr_txip_offset_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-offset0-value",
		&pinfo->spr.txip_offset0.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-offset1-value",
		&pinfo->spr.txip_offset1.value, 0);
}

static void lcd_kit_spr_txip_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-ctrl-value",
		&pinfo->spr.txip_ctrl.value, 0);

	pinfo->spr.txip_size.value = 0;
	pinfo->spr.txip_size.reg.txip_height = pinfo->yres - 1;
	pinfo->spr.txip_size.reg.txip_width = pinfo->xres - 1;

	lcd_kit_spr_txip_coef_set(panel_id, np, pinfo);
	lcd_kit_spr_txip_offset_set(panel_id, np, pinfo);

	lcd_kit_parse_u32(np, "lcd-kit,spr-txip-clip-value",
		&pinfo->spr.txip_clip.value, 0);
}

static void lcd_kit_spr_datapack_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-datapack-ctrl-value",
		&pinfo->spr.datapack_ctrl.value, 0);
	pinfo->spr.datapack_size.value = 0;
	pinfo->spr.datapack_size.reg.datapack_width = pinfo->xres - 1;
	pinfo->spr.datapack_size.reg.datapack_height = pinfo->yres - 1;
}

static void lcd_kit_spr_degamma_gamma_set(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-gamma-en-value",
		&pinfo->spr.spr_gamma_en.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-gamma-shiften-value",
		&pinfo->spr.spr_gamma_shiften.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-degamma-en-value",
		&pinfo->spr.degamma_en.value, 0);
	pinfo->spr.spr_lut_table = spr_lut_table_temp;
	pinfo->spr.spr_lut_table_len = LCD_MAX_SIZE;
}

static void lcd_kit_parse_spr_config_ctrl(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-ctrl-value",
		&pinfo->spr.spr_ctrl.value, 0);
}

static void lcd_kit_parse_spr_config_pix(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	lcd_kit_parse_u32(np, "lcd-kit,spr-pix-even-value",
		&pinfo->spr.spr_pix_even.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-pix-odd-value",
		&pinfo->spr.spr_pix_odd.value, 0);

	lcd_kit_parse_u32(np, "lcd-kit,spr-pix-panel-value",
		&pinfo->spr.spr_pix_panel.value, 0);
}

static void lcd_kit_parse_spr_config_info(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	pinfo->spr.panel_xres = pinfo->xres;
	pinfo->spr.panel_yres = pinfo->yres;
	pinfo->spr.spr_size.value = 0;
	pinfo->spr.spr_size.reg.spr_width = pinfo->xres - 1;
	pinfo->spr.spr_size.reg.spr_height = pinfo->yres - 1;
	lcd_kit_parse_spr_config_ctrl(panel_id, np, pinfo);
	lcd_kit_parse_spr_config_pix(panel_id, np, pinfo);
}

void lcd_kit_parse_spr_info(int panel_id, struct device_node *np,
	struct dpu_panel_info *pinfo)
{
	unsigned int support = 0;
	lcd_kit_parse_u32(np, "lcd-kit,spr-support", &support, 0);
	if (!support)
		return;
	lcd_kit_parse_spr_config_info(panel_id, np, pinfo);
	lcd_kit_spr_core_border_set(panel_id, np, pinfo);
	lcd_kit_spr_core_larea_set(panel_id, np, pinfo);
	lcd_kit_spr_core_coeffs_b_set(panel_id, np, pinfo);
	lcd_kit_spr_core_coeffs_r_set(panel_id, np, pinfo);
	lcd_kit_spr_core_coeffs_g_set(panel_id, np, pinfo);
	lcd_kit_spr_core_blend_set(panel_id, np, pinfo);
	lcd_kit_spr_core_edgestr_set(panel_id, np, pinfo);
	lcd_kit_spr_core_dir_set(panel_id, np, pinfo);
	lcd_kit_spr_core_diffdirgain_set(panel_id, np, pinfo);
	lcd_kit_spr_core_horz_set(panel_id, np, pinfo);
	lcd_kit_spr_core_vert_set(panel_id, np, pinfo);
	lcd_kit_spr_txip_set(panel_id, np, pinfo);
	lcd_kit_spr_datapack_set(panel_id, np, pinfo);
	lcd_kit_spr_degamma_gamma_set(panel_id, np, pinfo);
}
