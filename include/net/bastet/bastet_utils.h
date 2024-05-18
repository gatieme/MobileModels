

#ifndef _BASTET_UTILS_H
#define _BASTET_UTILS_H

#define BASTET_LOG_TAG "Bastet"

/* adb shell:
   use echo "file drivers/net/bastet/bastet_fastgrab.c +p" > /proc/dynamic_debug/control to open debug print
   use echo "file drivers/net/bastet/bastet_fastgrab.c -p" > /proc/dynamic_debug/control to close debug print */
#define bastet_logd(fmt, ...) do { \
    pr_debug("["BASTET_LOG_TAG"] %s: "fmt"\n", __func__, ##__VA_ARGS__); \
} while (0)

#define bastet_logi(fmt, ...) do { \
    pr_info("["BASTET_LOG_TAG"] %s: "fmt"\n", __func__, ##__VA_ARGS__); \
} while (0)

#define bastet_loge(fmt, ...) do { \
    pr_err("["BASTET_LOG_TAG"] %s: "fmt"\n", __func__, ##__VA_ARGS__); \
} while (0)

struct socket *sockfd_lookup_by_fd_pid(int fd, pid_t pid, int *err);
struct sock *get_sock_by_fd_pid(int fd, pid_t pid);
#endif /* _BASTET_UTILS_H */
