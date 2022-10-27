/*
 * laser_cfg.h
 *
 * Copyright (c) 2021-2021 Honor Technologies Co., Ltd.
 *
 * laser driver and hal header file
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef __HW_ALAN_KERNEL_HWCAM_LASER_CFG_H__
#define __HW_ALAN_KERNEL_HWCAM_LASER_CFG_H__

#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/videodev2.h>

#define HWLASER_NAME_SIZE 32

enum {
	LASER_ST_L0_VERSION = 0,
	LASER_ST_L1_VERSION,
	LASER_AMS_TMF882X_VERSION,
	LASER_MAX_VERSION,
};

typedef struct _tag_hwlaser_info {
	char name[HWLASER_NAME_SIZE];
	int version;
	uint32_t sn;
} hwlaser_info_t;

typedef struct _tag_hwlaser_customer_nvm_managed {
	uint8_t global_config__spad_enables_ref_0;
	uint8_t global_config__spad_enables_ref_1;
	uint8_t global_config__spad_enables_ref_2;
	uint8_t global_config__spad_enables_ref_3;
	uint8_t global_config__spad_enables_ref_4;
	uint8_t global_config__spad_enables_ref_5;
	uint8_t global_config__ref_en_start_select;
	uint8_t ref_spad_man__num_requested_ref_spads;
	uint8_t ref_spad_man__ref_location;
	uint32_t algo__crosstalk_compensation_plane_offset_kcps;
	int16_t algo__crosstalk_compensation_x_plane_gradient_kcps;
	int16_t algo__crosstalk_compensation_y_plane_gradient_kcps;
	uint16_t ref_spad_char__total_rate_target_mcps;
	int16_t algo__part_to_part_range_offset_mm;
	int16_t mm_config__inner_offset_mm;
	int16_t mm_config__outer_offset_mm;
} hwlaser_customer_nvm_managed_t;

typedef struct _tag_hwlaser_dmax_calibration_data {
	uint16_t ref__actual_effective_spads;
	uint16_t ref__peak_signal_count_rate_mcps;
	uint16_t ref__distance_mm;
	uint16_t ref_reflectance;
	uint16_t coverglass_transmission;
} hwlaser_dmax_calibration_data_t;


/****************************************************************/
/**************** hwlaser_xtalk_histogram_data_t ****************/
/****************************************************************/
#define HWLASER_MAX_BIN_SEQUENCE_LENGTH 6
#define HWLASER_HISTOGRAM_BUFFER_SIZE 24
#define HWLASER_XTALK_HISTO_BINS 12
typedef struct _tag_hwlaser_xtalk_histogram_shape {
	uint8_t zone_id;
	uint32_t time_stamp;
	uint8_t PRM_00019;
	uint8_t PRM_00020;
	uint8_t PRM_00021;
	uint32_t bin_data[HWLASER_XTALK_HISTO_BINS];
	uint16_t phasecal_result__reference_phase;
	uint8_t phasecal_result__vcsel_start;
	uint8_t cal_config__vcsel_start;
	uint16_t vcsel_width;
	uint16_t PRM_00022;
	uint16_t zero_distance_phase;
} hwlaser_xtalk_histogram_shape_t;

typedef struct _tag_hwlaser_histogram_bin_data {
	uint8_t cfg_device_state;
	uint8_t rd_device_state;
	uint8_t zone_id;
	uint32_t time_stamp;
	uint8_t PRM_00019;
	uint8_t PRM_00020;
	uint8_t PRM_00021;
	uint8_t number_of_ambient_bins;
	uint8_t bin_seq[HWLASER_MAX_BIN_SEQUENCE_LENGTH];
	uint8_t bin_rep[HWLASER_MAX_BIN_SEQUENCE_LENGTH];
	int32_t bin_data[HWLASER_HISTOGRAM_BUFFER_SIZE];
	uint8_t result__interrupt_status;
	uint8_t result__range_status;
	uint8_t result__report_status;
	uint8_t result__stream_count;
	uint16_t result__dss_actual_effective_spads;
	uint16_t phasecal_result__reference_phase;
	uint8_t phasecal_result__vcsel_start;
	uint8_t cal_config__vcsel_start;
	uint16_t vcsel_width;
	uint8_t PRM_00008;
	uint16_t PRM_00022;
	uint32_t total_periods_elapsed;
	uint32_t peak_duration_us;
	uint32_t woi_duration_us;
	int32_t min_bin_value;
	int32_t max_bin_value;
	uint16_t zero_distance_phase;
	uint8_t number_of_ambient_samples;
	int32_t ambient_events_sum;
	int32_t PRM_00028;
	uint8_t roi_config__user_roi_centre_spad;
	uint8_t roi_config__user_roi_requested_global_xy_size;
} hwlaser_histogram_bin_data_t;

typedef struct _tag_hwlaser_xtalk_histogram_data {
	hwlaser_xtalk_histogram_shape_t xtalk_shape;
	hwlaser_histogram_bin_data_t xtalk_hist_removed;
} hwlaser_xtalk_histogram_data_t;


/****************************************************************/
/************* hwlaser_additional_offset_cal_data_t *************/
/****************************************************************/
typedef struct _tag_hwlaser_additional_offset_cal_data {
	uint16_t result__mm_inner_actual_effective_spads;
	uint16_t result__mm_outer_actual_effective_spads;
	uint16_t result__mm_inner_peak_signal_count_rtn_mcps;
	uint16_t result__mm_outer_peak_signal_count_rtn_mcps;
} hwlaser_additional_offset_cal_data_t;

/*****************************************************************/
/****************** hwlaser_optical_centre_t *********************/
/*****************************************************************/
/*L3 does not have lens, need to delete or comment out*/
typedef struct _tag_hwlaser_optical_centre {
	uint8_t x_centre;
	uint8_t y_centre;
} hwlaser_optical_centre_t;

/*****************************************************************/
/***************** hwlaser_gain_calibration_data_t ***************/
/*****************************************************************/
typedef struct _tag_hwlaser_gain_calibration_data {
	uint16_t standard_ranging_gain_factor;
	uint16_t histogram_ranging_gain_factor;
} hwlaser_gain_calibration_data_t;

/*****************************************************************/
/****************** hwlaser_cal_peak_rate_map_t ******************/
/*****************************************************************/
/*maybe need to delete or comment out*/
#define HWLASER_NVM_PEAK_RATE_MAP_SAMPLES 25
typedef struct _tag_hwlaser_cal_peak_rate_map {
	int16_t cal_distance_mm;
	uint16_t cal_reflectance_pc;
	uint16_t max_samples;
	uint16_t width;
	uint16_t height;
	uint16_t peak_rate_mcps[HWLASER_NVM_PEAK_RATE_MAP_SAMPLES];
} hwlaser_cal_peak_rate_map_t;

typedef struct {
	int16_t short_a_offset_mm;
	int16_t short_b_offset_mm;
	int16_t medium_a_offset_mm;
	int16_t medium_b_offset_mm;
	int16_t long_a_offset_mm;
	int16_t long_b_offset_mm;
} hwlaser_per_vcsel_period_offset_cal_data_t;

/****************************************************************/
/************** NEW CALIBRATION datastruct:: ********************/
/***************** hwlaser_calibration_data *********************/
/****************************************************************/
#define VL53L1_BIN_REC_SIZE 6
typedef struct _tag_hwlaser_calibration_data {
	uint32_t struct_version; /* maybe need to delete or comment out */
	hwlaser_customer_nvm_managed_t customer;
	hwlaser_dmax_calibration_data_t fmt_dmax_cal; /* maybe need to delete or comment out */
	hwlaser_dmax_calibration_data_t cust_dmax_cal;
	hwlaser_additional_offset_cal_data_t add_off_cal_data;
	hwlaser_optical_centre_t optical_centre; /* maybe need to delete or comment out */
	hwlaser_xtalk_histogram_data_t xtalkhisto;
	hwlaser_gain_calibration_data_t gain_cal;
	hwlaser_cal_peak_rate_map_t cal_peak_rate_map; /* maybe need to delete or comment out */
	hwlaser_per_vcsel_period_offset_cal_data_t per_vcsel_cal_data;
	uint32_t algo__xtalk_cpo_HistoMerge_kcps[VL53L1_BIN_REC_SIZE];
} hwlaser_calibration_data;

typedef struct _tag_hwlaser_calibration_FOV {
	float x;
	float y;
	float width;
	float height;
	float angle;
} hwlaser_calibration_FOV;

typedef struct _tag_hwlaser_calibration_data_L1 {
	hwlaser_calibration_FOV HW_FOV;
	hwlaser_calibration_data RAW_CalibData;
} hwlaser_calibration_data_L1;

#define QUADRANT_CALIB_SIZE 188
#define CROSSTALK_SIZE 9

typedef struct _tag_ams_calibration_data {
    uint32_t calib_cross_data_3x3[CROSSTALK_SIZE];
    uint8_t calib_data_4x4[QUADRANT_CALIB_SIZE];
} ams_calibration_data;

typedef struct __tag_hwlaser_calibration_data {
	/* 0: Set
	   1: Get
	*/
	int32_t is_read;
	union {
		hwlaser_calibration_data rawCalibData;
		ams_calibration_data amsCalibData;
	};
} hwlaser_calibration_data_t;

/** @defgroup VL53L1_define_PresetModes_group Defines Preset modes
 * Defines all possible preset modes for the device
 * @{
 */
typedef uint8_t HWLASER_PresetModes;

#define HWLASER_PRESETMODE_RANGING ((HWLASER_PresetModes) 1)
#define HWLASER_PRESETMODE_MULTIZONES_SCANNING ((HWLASER_PresetModes) 2)
#define HWLASER_PRESETMODE_AUTONOMOUS ((HWLASER_PresetModes) 3)
#define HWLASER_PRESETMODE_LITE_RANGING ((HWLASER_PresetModes) 4)
#define HWLASER_PRESETMODE_OLT ((HWLASER_PresetModes) 7)
#define HWLASER_PRESETMODE_LOWPOWER_AUTONOMOUS ((HWLASER_PresetModes) 8)
#define HWLASER_PRESETMODE_PROXY_RANGING_MODE ((HWLASER_PresetModes) 9)

typedef enum _hwlaser_parameter_name_e {
	OFFSET_PAR = 0,
	XTALKRATE_PAR = 1,
	XTALKENABLE_PAR = 2,
	GPIOFUNC_PAR = 3,
	LOWTHRESH_PAR = 4,
	HIGHTHRESH_PAR = 5,
	DEVICEMODE_PAR = 6,
	INTERMEASUREMENT_PAR = 7,
	REFERENCESPADS_PAR = 8,
	REFCALIBRATION_PAR = 9,
	POLLDELAY_PAR = 10,
	/*!< TIMINGBUDGET_PAR
	 ** @ref parameter.value field is timing budget in micro second
	 ** type : int32_t
	 ** @note the value cannot be set while ranging will set
	 ** ebusy errno,
	 ** value set is absorbed at next range start @ref
	 *IOCTL_INIT
	 **/
	TIMINGBUDGET_PAR = 11,
	/*!< DISTANCEMODE_PAR
	 * * valid distance mode value :
	 * * @li 1 @a DISTANCEMODE_SHORT
	 * * @li 2 @a DISTANCEMODE_MEDIUM
	 * * @li 3 @a DISTANCEMODE_LONG
	 * * @li 4 @a DISTANCEMODE_AUTO_LITE
	 * * @li 5 @a DISTANCEMODE_AUTO
	 * * type : int32_t
	 * * @warning distance mode can only
	 * * be set while not ranging
	 * */
	DISTANCEMODE_PAR = 12,
	/* HW Custom param */
	/*!< NVM_PAR
	 * * @ref value : principal x
	 * * type : float
	 * * @ref valu2 : principal y
	 * * type : float
	 * * @note get para from NVM
	 * */
	 SIGMALIMIT_PAR = 13,
	 SIGNALLIMIT_PAR = 14,
	 RIT_PAR = 15,
	NVM_PAR = 0x100,

} hwlaser_parameter_name_e;

typedef hwlaser_parameter_name_e parameter_name_e;


typedef struct _hwlaser_parameter {
	uint32_t is_read; /*!< [in]1: Get 0: Set*/
	hwlaser_parameter_name_e name; /*!< [in]parameter to set/get */
	int32_t value; /*!< [in/out] value in int32_t to set /get */
	int32_t value2; /*!< [in/out] optional 2nd value int int32_t*/
	int32_t status; /*!< [out]status of the operation */
} hwlaser_parameter_t;

#define HWLASER_MAX_RANGE_RESULTS 4
typedef struct _tag_hwlaser_ranging_measurement_data {

	uint8_t RangeQualityLevel;
		/*!< indicate a quality level in percentage from 0 to 100
		 * @warning Not yet implemented
		 */

	int16_t RangeMaxMilliMeter;
		/*!< Tells what is the maximum detection distance of the object
		 * in current setup and environment conditions (Filled when
		 * applicable)
		 */

	int16_t RangeMinMilliMeter;
		/*!< Tells what is the minimum detection distance of the object
		 * in current setup and environment conditions (Filled when
		 * applicable)
		 */

	uint32_t SignalRateRtnMegaCps;
		/*!< Return signal rate (MCPS)\n these is a 16.16 fix point
		 * value, which is effectively a measure of target
		 * reflectance.
		 */

	uint32_t AmbientRateRtnMegaCps;
		/*!< Return ambient rate (MCPS)\n these is a 16.16 fix point
		 * value, which is effectively a measure of the ambien
		 * t light.
		 */

	uint32_t SigmaMilliMeter;
		/*!< Return the Sigma value in millimeter */

	int16_t RangeMilliMeter;
		/*!< range distance in millimeter. This should be between
		 * RangeMinMilliMeter and RangeMaxMilliMeter
		 */

	uint8_t RangeFractionalPart;
		/*!< Fractional part of range distance. Final value is a
		 ** RangeMilliMeter + RangeFractionalPart/256.
		 ** @warning Not yet implemented */

	uint8_t RangeStatus;
		/*!< Range Status for the current measurement. This is device
		 ** dependent. Value = 0 means value is valid.
		 **/
} hwlaser_RangingMeasurementData_t;

typedef uint8_t RoiStatus_t;
#define HWLASER_ROISTATUS_NOT_VALID ((RoiStatus_t) 0)
#define HWLASER_ROISTATUS_VALID_NOT_LAST ((RoiStatus_t) 1)
#define HWLASER_ROISTATUS_VALID_LAST ((RoiStatus_t) 2)
/** @defgroup hwlaser_define_DistanceModes_group Defines Distance modes
 * Defines all possible Distance modes for the device
 * @{
 */
typedef uint8_t hwlaser_DistanceModes;

typedef struct _tag_hwlaser_multi_ranging_data {

	uint32_t TimeStamp;
		/*!< 32-bit time stamp.
		 * @warning Not yet implemented
		 */

	uint8_t StreamCount;
		/*!< 8-bit Stream Count. */

	uint8_t RoiNumber;
		/*!< Denotes on which ROI the range data is related to. */
	uint8_t NumberOfObjectsFound;
		/*!< Indicate the number of objects found in the current ROI.
		 ** This is used to know how many ranging data should be get.
		 ** NumberOfObjectsFound is in the range 0 to
		 ** HWLASER_MAX_RANGE_RESULTS.
		 **/
	RoiStatus_t RoiStatus;
		/*!< Indicate if the data read is valid or not or if this is
		 ** the last valid data in the ROI.
		 **/
	hwlaser_RangingMeasurementData_t RangeData[HWLASER_MAX_RANGE_RESULTS];
		/*!< Range data each target distance */

	uint8_t HasXtalkValueChanged;
		/*!< set to 1 if a new Xtalk value has been computed whilst
		 * smudge correction mode enable by with
		 * hwlaser_SmudgeCorrectionEnable() function is either
		 * hwlaser_SMUDGE_CORRECTION_CONTINUOUS or
		 * hwlaser_SMUDGE_CORRECTION_SINGLE.
		 */

	uint16_t EffectiveSpadRtnCount;
		/*!< Return the effective SPAD count for the return signal.
		 * To obtain Real value it should be divided by 256
		 */

	int16_t DmaxMilliMeter;
		/*!< range Dmax distance in millimeter.
		 */

	hwlaser_DistanceModes RecommendedDistanceMode;
		/*!< suggestion for a better distance mode choice to improve
		 * range accuracy.
		 */
} hwlaser_multiRangingData_t;

/** Select reference spad calibration in @ref HWLASER_IOCTL_PERFORM_CALIBRATION.
 *
 * param1, param2 and param3 not use
 */
#define HWLASER_CALIBRATION_REF_SPAD 0

/** Select crosstalk calibration in @ref HWLASER_IOCTL_PERFORM_CALIBRATION.
 **
 ** param1 is calibration method. param2 and param3 not use.
 **/
#define HWLASER_CALIBRATION_CROSSTALK 1

/** Select offset calibration @ref HWLASER_IOCTL_PERFORM_CALIBRATION.
 ** param1 is target distance in mm. param2 and
 ** param3 not use.
 **/
#define HWLASER_CALIBRATION_OFFSET 2

/** Select reference calibration in @ref HWLASER_IOCTL_PERFORM_CALIBRATION.
 *
 * param1, param2 and param3 not use
 */
#define HWLASER_CALIBRATION_REFERENCE 3

/** Select spad calibration in @ref HWLASER_IOCTL_PERFORM_CALIBRATION.
 *
 * param1, param2 and param3 not use
 */
#define HWLASER_CALIBRATION_SPAD 4

/** @defgroup HWLASER_define_OffsetCal_group Defines Offset Calibration modes
* Defines all possible Offset Calibration modes for the device
* @{
*/
typedef uint8_t HWLASER_OffsetCalibrationModes;

#define HWLASER_OFFSETCALIBRATIONMODE_STANDARD \
	((HWLASER_OffsetCalibrationModes) 1)
#define HWLASER_OFFSETCALIBRATIONMODE_PRERANGE_ONLY \
	((HWLASER_OffsetCalibrationModes) 2)
#define HWLASER_OFFSETCALIBRATIONMODE_MULTI_ZONE \
	((HWLASER_OffsetCalibrationModes) 3)

typedef struct _tag_hwlaser_ioctl_perform_calibration {
	uint32_t calibration_type;
	/*!< [in] select which calibration to do :
	 ** @li @ref HWLASER_CALIBRATION_REF_SPAD
	 ** @li @ref HWLASER_CALIBRATION_CROSSTALK
	 ** @li @ref HWLASER_CALIBRATION_OFFSET
	 **/
	uint32_t param1;
	/*!< [in] first param. Usage depends on calibration_type */
	uint32_t param2;
	/*!< [in] second param. Usage depends on calibration_type */
	uint32_t param3;
	/*!< [in] third param. Usage depends on calibration_type */
} hwlaser_ioctl_perform_calibration_t;

#define LASER_MAGIC 'A'
#define HWLASER_IOCTL_GET_INFO\
	_IOR(LASER_MAGIC, 0x01, hwlaser_info_t)
#define HWLASER_IOCTL_CALIBRATION_DATA\
	_IOWR(LASER_MAGIC, 0x02, hwlaser_calibration_data_t)
#define HWLASER_IOCTL_PARAMETER\
	_IOWR(LASER_MAGIC, 0x03, hwlaser_parameter_t)
#define HWLASER_IOCTL_MZ_DATA\
	_IOWR(LASER_MAGIC, 0x04, hwlaser_multiRangingData_t)
#define HWLASER_IOCTL_PERFORM_CALIBRATION\
	_IOWR(LASER_MAGIC, 0x05, hwlaser_ioctl_perform_calibration_t)

#endif /* __HW_ALAN_KERNEL_HWCAM_LASER_CFG_H__ */