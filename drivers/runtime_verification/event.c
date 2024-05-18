#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/uio.h>
#include <linux/version.h>

#include <log/hw_log.h>
#include <log/hw_logger.h>
#include <log/log_exception.h>

#define HWLOG_TAG rv
HILOG_REGIST();

#define LOGGER_RV "rv"
#define LOGGER_RV_BUF_SIZE 128 * 1024
#define CHECK_CODE 0x7BCDABCD

extern int create_log(char *log_name, int size);
extern void destroy_logger(const char *name);


ssize_t send_rv_event(const char *msg, ssize_t msg_len)
{
	struct iovec vec[3]; // 3:hievent data vector size
	struct idapheader idaphdr;
	const int magic = CHECK_CODE;

	idaphdr.level    = 0;
	idaphdr.category = 0;
	idaphdr.log_type = IDAP_LOGTYPE_CMD;
	idaphdr.sn       = 0;

	vec[0].iov_base = (void *)&magic;
	vec[0].iov_len = sizeof(int);
	vec[1].iov_base = (void *)&idaphdr;
	vec[1].iov_len = sizeof(idaphdr);
	vec[2].iov_base = (void *)msg;
	vec[2].iov_len = msg_len;

	return send_hievent_vector(LOGGER_RV, vec, ARRAY_SIZE(vec));
}
EXPORT_SYMBOL(send_rv_event);

static int __init rv_init(void)
{
	return create_log(LOGGER_RV, LOGGER_RV_BUF_SIZE);
}

static void __exit rv_exit(void)
{
	destroy_logger(LOGGER_RV);
}

module_init(rv_init);
module_exit(rv_exit);

MODULE_LICENSE("GPL");
