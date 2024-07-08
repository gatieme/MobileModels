#ifndef __HISI_HISEE_FS_H__
#define __HISI_HISEE_FS_H__

#define HISEE_IMAGE_PARTITION_NAME  "hisee_img"
#define HISEE_IMAGE_A_PARTION_NAME   "hisee_img_a"
#define HISEE_IMG_PARTITION_SIZE     (4 * SIZE_1M)
#define HISEE_SW_VERSION_MAGIC_VALUE (0xa5a55a5a)

#define HISEE_MIN_MISC_IMAGE_NUMBER  (1)
#define HISEE_MAX_MISC_IMAGE_NUMBER  (5)

#define HISEE_FS_PARTITION_NAME     "/hisee_fs/"
#define HISEE_FS_APDU_TEST_NAME     "test.apdu.bin"
#define HISEE_FS_APDU_APPLET_NAME   "applet.apdu.bin"

/* Hisee module specific error code*/
#define HISEE_COS_VERIFICATITON_ERROR  (-1002)
#define HISEE_IMG_PARTITION_MAGIC_ERROR  (-1003)
#define HISEE_IMG_PARTITION_FILES_ERROR  (-1004)
#define HISEE_IMG_SUB_FILE_NAME_ERROR    (-1005)
#define HISEE_SUB_FILE_SIZE_CHECK_ERROR   (-1006)
#define HISEE_SUB_FILE_OFFSET_CHECK_ERROR (-1007)
#define HISEE_IMG_SUB_FILE_ABSENT_ERROR  (-1008)
#define HISEE_FS_SUB_FILE_ABSENT_ERROR   (-1009)

#define HISEE_OPEN_FILE_ERROR    (-2000)
#define HISEE_READ_FILE_ERROR    (-2001)
#define HISEE_WRITE_FILE_ERROR   (-2002)
#define HISEE_CLOSE_FILE_ERROR   (-2003)
#define HISEE_LSEEK_FILE_ERROR   (-2004)
#define HISEE_OUTOF_RANGE_FILE_ERROR   (-2005)

#define HISEE_FS_MALLOC_ERROR          (-3000)
#define HISEE_FS_PATH_ABSENT_ERROR     (-3001)
#define HISEE_FS_OPEN_PATH_ERROR       (-3002)
#define HISEE_FS_COUNT_FILES_ERROR     (-3003)
#define HISEE_FS_PATH_LONG_ERROR       (-3004)
#define HISEE_FS_READ_FILE_ERROR       (-3005)

/* hisee image info */
#define HISEE_IMG_MAGIC_LEN		    (4)
#define HISEE_IMG_MAGIC_VALUE		"inse"
#define HISEE_IMG_TIME_STAMP_LEN	(20)
#define HISEE_IMG_DATA_LEN	        (4)
#define HISEE_IMG_SUB_FILE_LEN	    (4)
#define HISEE_IMG_HEADER_LEN        (HISEE_IMG_MAGIC_LEN + HISEE_IMG_TIME_STAMP_LEN + HISEE_IMG_DATA_LEN + HISEE_IMG_SUB_FILE_LEN)
#define HISEE_IMG_SUB_FILE_MAX		(8)
#define HISEE_IMG_SUB_FILE_NAME_LEN	(8)
#define HISEE_IMG_SUB_FILE_OFFSET_LEN (4)
#define HISEE_IMG_SUB_FILE_DATA_LEN (4)
#define HISEE_IMG_SUB_FILES_LEN     (HISEE_IMG_SUB_FILE_NAME_LEN + HISEE_IMG_SUB_FILE_OFFSET_LEN + HISEE_IMG_SUB_FILE_DATA_LEN)
#define HISEE_IMG_SLOADER_NAME		"SLOADER"
#define HISEE_IMG_COS_NAME			"COS"
#define HISEE_IMG_OTP_NAME			"OTP"
#define HISEE_IMG_OTP0_NAME			"OTP0"
#define HISEE_IMG_OTP1_NAME			"OTP1"
#define HISEE_IMG_MISC_NAME			"MISC"

#define MAX_PATH_NAME_LEN    (128)
#define HISEE_FILESYS_DIR_ENTRY_SIZE    (1024)
#define HISEE_FILESYS_DEFAULT_MODE       0770  /* default mode when creating a file or dir if user doesn't set mode*/

/* hisee_img partition struct */
typedef struct _IMG_FILE_INFO {
	char name[HISEE_IMG_SUB_FILE_NAME_LEN];
	unsigned int offset;
	unsigned int size;
} img_file_info;

typedef struct _HISEE_IMG_HEADER {
	char magic[HISEE_IMG_MAGIC_LEN];
	char time_stamp[HISEE_IMG_TIME_STAMP_LEN];
	unsigned int total_size;
	unsigned int file_cnt;
	img_file_info file[HISEE_IMG_SUB_FILE_MAX];
	unsigned int sw_version_cnt;
	unsigned int misc_image_cnt;
} hisee_img_header;

typedef enum _HISEE_IMAGE_A_ACCESS_TYPE_ {
	SW_VERSION_READ_TYPE = 0,
	SW_VERSION_WRITE_TYPE,
	COS_UPGRADE_RUN_READ_TYPE,
	COS_UPGRADE_RUN_WRITE_TYPE,
	MISC_VERSION_READ_TYPE,
	MISC_VERSION_WRITE_TYPE,
} hisee_image_a_access_type;

typedef enum  _HISEE_IMG_FILE_TYPE {
	SLOADER_IMG_TYPE = 0,
	COS_IMG_TYPE,
	OTP_IMG_TYPE,
	OTP1_IMG_TYPE,
	MISC0_IMG_TYPE,
	MISC1_IMG_TYPE,
	MISC2_IMG_TYPE,
	MISC3_IMG_TYPE,
	MISC4_IMG_TYPE,
	MAX_IMG_TYPE,
} hisee_img_file_type;

typedef union _TIMESTAMP_INFO {
	struct timestamp {
		unsigned char second;
		unsigned char minute;
		unsigned char hour;
		unsigned char day;
		unsigned char month;
		unsigned char padding;
		unsigned short year;
	} timestamp;
	unsigned long value;
} timestamp_info;

typedef struct _COSIMAGE_VERSION_INFO_ {
	unsigned int magic;
	unsigned int img_version_num;
	timestamp_info img_timestamp;
} cosimage_version_info;

int write_hisee_otp_value(hisee_img_file_type otp_img_index);
int hisee_parse_img_header(char *buffer);
int filesys_hisee_read_image(hisee_img_file_type type, char *buffer);
int hisee_read_file(const char *fullname, char *buffer, size_t offset, size_t size);
int access_hisee_image_partition(char *data_buf, hisee_image_a_access_type access_type);

#endif
