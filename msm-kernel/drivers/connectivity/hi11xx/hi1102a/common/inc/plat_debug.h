/*
 * 版权所有 (c) 华为技术有限公司 2012-2018
 * 功能说明   : 日志打印宏定义
 * 作者       : zwx144390
 * 创建日期   : 2012年10月11日
 */

#ifndef __PLAT_DEBUG_H__
#define __PLAT_DEBUG_H__

/* Include other Head file */
#include "bfgx_user_ctrl.h"
#include "chr_user.h"

/* Define macro */
#define PS_PRINT_FUNCTION_NAME                                    \
    do {                                                          \
        if (g_plat_loglevel >= PLAT_LOG_DEBUG) {                  \
            printk(KERN_INFO KBUILD_MODNAME ":D]%s]", __func__); \
        }                                                         \
    } while (0)

#define ps_print_dbg(s, args...)                                            \
    do {                                                                    \
        if (g_plat_loglevel >= PLAT_LOG_DEBUG) {                            \
            printk(KERN_INFO KBUILD_MODNAME ":D]%s]" s, __func__, ##args); \
        }                                                                   \
    } while (0)

#define ps_print_info(s, args...)                                           \
    do {                                                                    \
        if (g_plat_loglevel >= PLAT_LOG_INFO) {                             \
            printk(KERN_INFO KBUILD_MODNAME ":I]%s]" s, __func__, ##args); \
            chr_log(CHR_LOG_INFO, CHR_LOG_TAG_PLAT, s, ##args);             \
        }                                                                   \
    } while (0)

#define ps_print_suc(s, args...)                                            \
    do {                                                                    \
        if (g_plat_loglevel >= PLAT_LOG_INFO) {                             \
            printk(KERN_INFO KBUILD_MODNAME ":S]%s]" s, __func__, ##args); \
            chr_log(CHR_LOG_INFO, CHR_LOG_TAG_PLAT, s, ##args);             \
        }                                                                   \
    } while (0)

#define ps_print_warning(s, args...)                                          \
    do {                                                                      \
        if (g_plat_loglevel >= PLAT_LOG_WARNING) {                            \
            printk(KERN_WARNING KBUILD_MODNAME ":W]%s]" s, __func__, ##args); \
            chr_log(CHR_LOG_WARN, CHR_LOG_TAG_PLAT, s, ##args);               \
        }                                                                     \
    } while (0)

#define ps_print_err(s, args...)                                          \
    do {                                                                  \
        if (g_plat_loglevel >= PLAT_LOG_ERR) {                            \
            printk(KERN_ERR KBUILD_MODNAME ":E]%s]" s, __func__, ##args); \
            chr_log(CHR_LOG_ERROR, CHR_LOG_TAG_PLAT, s, ##args);          \
        }                                                                 \
    } while (0)

#define ps_print_alert(s, args...)                                              \
    do {                                                                        \
        if (g_plat_loglevel >= PLAT_LOG_ALERT) {                                \
            printk(KERN_ALERT KBUILD_MODNAME ":ALERT]%s]" s, __func__, ##args); \
            chr_log(CHR_LOG_ERROR, CHR_LOG_TAG_PLAT, s, ##args);                \
        }                                                                       \
    } while (0)

#define ps_bug_on(s)                              \
    do {                                          \
        if ((g_bug_on_enable == BUG_ON_ENABLE)) { \
            BUG_ON(s);                            \
        }                                         \
    } while (0)

#endif /* PLAT_DEBUG_H */
