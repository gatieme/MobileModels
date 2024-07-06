
#ifndef __PERF_LPM_LIMIT_FREQ_H__
#define __PERF_LPM_LIMIT_FREQ_H__

#ifdef CONFIG_IPA_MNTN_INFO
ssize_t read_limit_freq(char *buf);
#endif
long perf_ioctl_lpm_limit_freq(unsigned int cmd, void __user *argp);

#endif /* __PERF_LPM_LIMIT_FREQ_H__ */
