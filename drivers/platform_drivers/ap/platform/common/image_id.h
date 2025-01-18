#ifndef __IMAGE_ID_H__
#define __IMAGE_ID_H__ 
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
#define IMAGE_NAME_MAX_LEN 36u
#define PARTITION_NAME_MAX_LEN 36u
struct image_id_t {
 char partition_name[PARTITION_NAME_MAX_LEN];
 char image_name[IMAGE_NAME_MAX_LEN];
};
#ifdef __cplusplus
}
#endif
#endif
