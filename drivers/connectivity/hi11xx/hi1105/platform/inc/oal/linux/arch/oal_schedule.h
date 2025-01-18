/**
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 *
 * Description: oal_types.c header file
 * Author: @CompanyNameTag
 */

#ifndef OAL_LINUX_SCHEDULE_H
#define OAL_LINUX_SCHEDULE_H

/* 其他头文件包含 */
#include <asm/atomic.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/jiffies.h>
#include <linux/time.h>
#include <asm/param.h>
#include <linux/timer.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/ktime.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 0, 0))
#include <linux/stacktrace.h>
#endif
#if ((LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)) && (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION))
#include <linux/pm_wakeup.h>
#endif
#include "linux/time.h"
#include "linux/timex.h"
#include "linux/rtc.h"
#include "securec.h"

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
#include <uapi/linux/sched/types.h>
#endif

typedef atomic_t oal_atomic;

#define OAL_SPIN_LOCK_MAGIC_TAG 0xdead4ead
typedef struct _oal_spin_lock_stru_ {
#ifdef CONFIG_SPIN_LOCK_MAGIC_DEBUG
    uint32_t magic;
    uint32_t reserved;
#endif
    spinlock_t lock;
} oal_spin_lock_stru;

#ifdef CONFIG_SPIN_LOCK_MAGIC_DEBUG
#define oal_define_spinlock(x) oal_spin_lock_stru x = { \
    .magic = OAL_SPIN_LOCK_MAGIC_TAG,                   \
    .lock = __SPIN_LOCK_UNLOCKED(x)                     \
}
#else
#define oal_define_spinlock(x) oal_spin_lock_stru x = { \
    .lock = __SPIN_LOCK_UNLOCKED(x)                     \
}
#endif

/* 函数指针，用来指向需要自旋锁保护的的函数 */
typedef uint32_t (*oal_irqlocked_func)(void *);

typedef rwlock_t oal_rwlock_stru;
typedef struct timer_list oal_timer_list_stru;

typedef struct tasklet_struct oal_tasklet_stru;
typedef void (*oal_defer_func)(oal_uint);

/* tasklet声明 */
#define OAL_DECLARE_TASK DECLARE_TASKLET

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0))
typedef wait_queue_entry_t oal_wait_queue_stru;
#else
typedef wait_queue_t oal_wait_queue_stru;
#endif
typedef wait_queue_head_t oal_wait_queue_head_stru;

/*
 * wait_event_interruptible_timeout - sleep until a condition gets true or a timeout elapses
 * @_wq: the waitqueue to wait on
 * @_condition: a C expression for the event to wait for
 * @_timeout: timeout, in jiffies
 * The process is put to sleep (TASK_INTERRUPTIBLE) until the
 * @condition evaluates to true or a signal is received.
 * The @condition is checked each time the waitqueue @wq is woken up.
 * wake_up() has to be called after changing any variable that could
 * change the result of the wait condition.
 * The function returns 0 if the @timeout elapsed, -ERESTARTSYS if it
 * was interrupted by a signal, and the remaining jiffies otherwise
 * if the condition evaluated to true before the timeout elapsed.
 */
#define oal_wait_event_interruptible_timeout_m(_st_wq, _condition, _timeout) \
    wait_event_interruptible_timeout(_st_wq, _condition, _timeout)

#define oal_wait_event_timeout_m(_st_wq, _condition, _timeout) \
    wait_event_timeout(_st_wq, _condition, _timeout)

#define oal_wait_event_interruptible_m(_st_wq, _condition) \
    wait_event_interruptible(_st_wq, _condition)

#define oal_wait_event_killable_timeout(_st_wq, _condition, _timeout) \
    wait_event_killable_timeout(_st_wq, _condition, _timeout)

#define oal_wait_queue_wake_up_interrupt(_pst_wq) wake_up_interruptible(_pst_wq)

#define oal_wait_queue_wake_up(_pst_wq) wake_up(_pst_wq)

#define oal_interruptible_sleep_on(_pst_wq) interruptible_sleep_on(_pst_wq)

#define oal_wait_queue_init_head(_pst_wq) init_waitqueue_head(_pst_wq)

/* 获取毫秒级时间戳 */
#define oal_time_get_stamp_ms() jiffies_to_msecs(jiffies)

/* 获取高精度毫秒时间戳,精度1ms */
#define oal_time_get_high_precision_ms() oal_get_time_stamp_from_timeval()

#define oal_enable_cycle_count()
#define oal_disable_cycle_count()
#define oal_get_cycle_count() 0

/* 寄存器反转模块运行时间计算 */
#define oal_time_calc_runtime(_ul_start, _ul_end)                              \
    (uint32_t)((oal_div_u64((uint64_t)(OAL_TIME_US_MAX_LEN), HZ) * 1000) + \
                 (((OAL_TIME_US_MAX_LEN) % HZ) * (1000 / HZ)) - (_ul_start) + (_ul_end))

#define oal_time_calc_runtime_us(_ul_start, _ul_end)                              \
    (uint32_t)((oal_div_u64((uint64_t)(OAL_TIME_US_MAX_LEN), HZ) * 1000000) + \
                 (((OAL_TIME_US_MAX_LEN) % HZ) * (1000000 / HZ)) - (_ul_start) + (_ul_end))

#define OAL_TIME_JIFFY jiffies

#define OAL_TIME_HZ HZ

#define oal_msecs_to_jiffies(_msecs) msecs_to_jiffies(_msecs)

#define oal_jiffies_to_msecs(_jiffies) jiffies_to_msecs(_jiffies)

#define oal_jiffies_to_usecs(_jiffies) jiffies_to_usecs(_jiffies)

#define oal_get_real_time_m(_pst_tm) oal_get_real_time(_pst_tm)

#define oal_init_completion(_my_completion) init_completion(_my_completion)

#define oal_complete(_my_completion) complete(_my_completion)

#define oal_in_interrupt() in_interrupt()

#define oal_in_atomic() in_atomic()
#define oal_read_once(_p) READ_ONCE(_p)
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 18, 0))
typedef uintptr_t oal_timeout_func_para_t;
#define oal_get_timer_container(container, data, member) ((typeof(container))data)
#else
typedef struct timer_list* oal_timeout_func_para_t;
#define oal_get_timer_container(container, data, member) (from_timer(container, data, member))
#endif

typedef void (*oal_timer_func)(oal_timeout_func_para_t);

typedef uint32_t (*oal_module_func_t)(void);

#define oal_module_license(_license_name) MODULE_LICENSE(_license_name)

#define OAL_MODULE_PARAM        module_param
#define OAL_MODULE_PARAM_STRING module_param_string

#define OAL_S_IRUGO S_IRUGO

#ifdef _PRE_WLAN_AIO
#define oal_module_init(_module_name)
#define oal_module_exit(_module_name)
#define oal_module_symbol(_symbol)
#else
#define oal_module_init(_module_name) module_init(_module_name)
#define oal_module_exit(_module_name) module_exit(_module_name)
#define oal_module_symbol(_symbol)    EXPORT_SYMBOL(_symbol)
#endif
#define oal_module_device_table(_type, _name) MODULE_DEVICE_TABLE(_type, _name)

#define oal_smp_call_function_single(core, task, info, wait) smp_call_function_single(core, task, info, wait)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 44))
#define oal_is_err_or_null(ptr) (!(ptr) || IS_ERR(ptr))
#else
static inline bool __must_check oal_is_err_or_null(__force const void *ptr)
{
    return !ptr || IS_ERR(ptr);
}
#endif
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
typedef struct timespec64 oal_timespec_stru;
#define oal_waitqueue_active(wait) swait_active(wait)
#else
typedef struct timeval oal_timespec_stru;
#define oal_waitqueue_active(wait) waitqueue_active(wait)
#endif

#define OAL_MUTEX_INIT(mutex) mutex_init(mutex)

/* STRUCT定义 */
typedef struct proc_dir_entry oal_proc_dir_entry_stru;

typedef struct mutex oal_mutex_stru;

typedef struct completion oal_completion;

typedef struct {
    signed long i_sec;
    signed long i_usec;
} oal_time_us_stru;

typedef ktime_t oal_time_t_stru;

typedef struct _oal_task_lock_stru_ {
    oal_wait_queue_head_stru wq;
    struct task_struct *claimer; /* task that has host claimed */
    oal_spin_lock_stru lock;     /* lock for claim and bus ops */
    uintptr_t claim_addr;
    uint32_t claimed;
    int32_t claim_cnt;
} oal_task_lock_stru;

// 与内核struct rtc_time 保持一致
typedef struct _oal_time_stru {
    int32_t tm_sec;   /* seconds */
    int32_t tm_min;   /* minutes */
    int32_t tm_hour;  /* hours */
    int32_t tm_mday;  /* day of the month */
    int32_t tm_mon;   /* month */
    int32_t tm_year;  /* year */
    int32_t tm_wday;  /* day of the week */
    int32_t tm_yday;  /* day in the year */
    int32_t tm_isdst; /* daylight saving time */
} oal_time_stru;

/*
 * 函 数 名  : oal_spin_lock_init
 * 功能描述  : 自旋锁初始化，把自旋锁设置为1（未锁状态）。
 * 输入参数  : pst_lock: 锁的地址
 */
OAL_STATIC OAL_INLINE void oal_spin_lock_init(oal_spin_lock_stru *pst_lock)
{
    spin_lock_init(&pst_lock->lock);
#ifdef CONFIG_SPIN_LOCK_MAGIC_DEBUG
    pst_lock->magic = OAL_SPIN_LOCK_MAGIC_TAG;
#endif
}

OAL_STATIC OAL_INLINE void oal_spin_lock_magic_bug(oal_spin_lock_stru *pst_lock)
{
#ifdef CONFIG_SPIN_LOCK_MAGIC_DEBUG
    if (oal_unlikely(pst_lock->magic != (uint32_t)OAL_SPIN_LOCK_MAGIC_TAG)) {
#ifdef CONFIG_PRINTK
        const int l_dump_len = 32;
        /* spinlock never init or memory overwrite? */
        printk(KERN_EMERG "[E]SPIN_LOCK_BUG: spinlock:%p on CPU#%d, %s,magic:%08x should be %08x\n", pst_lock,
               raw_smp_processor_id(), current->comm, pst_lock->magic, OAL_SPIN_LOCK_MAGIC_TAG);
        /* 内核函数固定传参, rowsize = 16,groupsize = 1 */
        print_hex_dump(KERN_EMERG, "spinlock_magic: ", DUMP_PREFIX_ADDRESS, 16, 1,
                       (uint8_t *)((uintptr_t)pst_lock - l_dump_len),
                       l_dump_len + sizeof(oal_spin_lock_stru) + l_dump_len, true); /* 意为把前后32字节内容都dump出来 */
        printk(KERN_EMERG "\n");
        BUG_ON(1);
#endif
        oal_warn_on(1);
    }
#endif
}

/*
 * 函 数 名  : oal_spin_lock
 * 功能描述  : 自旋锁在软中断以及内核线程等核心态上下文环境下的加锁操作。如果
 *             能够立即获得锁，它就马上返回，否则，它将自旋在那里，直到该自旋
 *             锁的保持者释放，这时，它获得锁并返回。
 * 输入参数  : pst_lock:自旋锁地址
 */
OAL_STATIC OAL_INLINE void oal_spin_lock(oal_spin_lock_stru *pst_lock)
{
    oal_spin_lock_magic_bug(pst_lock);
    spin_lock(&pst_lock->lock);
}

/*
 * 函 数 名  : oal_spin_unlock
 * 功能描述  : Spinlock在内核线程等核心态上下文环境下的解锁操作。
 * 输入参数  : pst_lock:自旋锁地址
 */
OAL_STATIC OAL_INLINE void oal_spin_unlock(oal_spin_lock_stru *pst_lock)
{
    oal_spin_lock_magic_bug(pst_lock);
    spin_unlock(&pst_lock->lock);
}

/*
 * 函 数 名  : oal_spin_lock_bh
 * 功能描述  : 自旋锁在软中断以及内核线程等核心态上下文环境下的加锁操作。如果
 *             能够立即获得锁，它就马上返回，否则，它将自旋在那里，直到该自旋
 *             锁的保持者释放，这时，它获得锁并返回。
 * 输入参数  : pst_lock:自旋锁地址
 */
OAL_STATIC OAL_INLINE void oal_spin_lock_bh(oal_spin_lock_stru *pst_lock)
{
    oal_spin_lock_magic_bug(pst_lock);
    spin_lock_bh(&pst_lock->lock);
}

/*
 * 函 数 名  : oal_spin_unlock_bh
 * 功能描述  : Spinlock在软中断以及内核线程等核心态上下文环境下的解锁操作。
 */
OAL_STATIC OAL_INLINE void oal_spin_unlock_bh(oal_spin_lock_stru *pst_lock)
{
    oal_spin_lock_magic_bug(pst_lock);
    spin_unlock_bh(&pst_lock->lock);
}

/*
 * 函 数 名  : oal_spin_lock_irq_save
 * 功能描述  : 获得自旋锁的同时获得保存标志寄存器的值，并且失效本地中断。
 * 输入参数  : pst_lock:自旋锁地址
 *             pui_flags:标志寄存器
 */
OAL_STATIC OAL_INLINE void oal_spin_lock_irq_save(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
    oal_spin_lock_magic_bug(pst_lock);
    spin_lock_irqsave(&pst_lock->lock, *pui_flags);
}

/*
 * 函 数 名  : oal_spin_unlock_irq_restore
 * 功能描述  : 释放自旋锁的同时，恢复标志寄存器的值，恢复本地中断。它与oal_sp-
 *             in_lock_irq配对使用
 * 输入参数  : pst_lock:自旋锁地址
 *             pui_flags:标志寄存器
 */
OAL_STATIC OAL_INLINE void oal_spin_unlock_irq_restore(oal_spin_lock_stru *pst_lock, oal_uint *pui_flags)
{
    oal_spin_lock_magic_bug(pst_lock);
    spin_unlock_irqrestore(&pst_lock->lock, *pui_flags);
}

/*
 * 函 数 名  : oal_spin_lock_irq_exec
 * 功能描述  : 获取自旋锁，关闭中断，执行某个函数，完了之后再打开中断，释放自旋锁。
 * 输入参数  : pst_lock:自旋锁地址
 *             func：函数指针地址
 *             p_arg：函数参数
 *             pui_flags: 中断标志寄存器
 */
OAL_STATIC OAL_INLINE uint32_t oal_spin_lock_irq_exec(oal_spin_lock_stru *pst_lock, oal_irqlocked_func func,
                                                      void *p_arg, oal_uint *pui_flags)
{
    uint32_t ul_rslt;

    spin_lock_irqsave(&pst_lock->lock, *pui_flags);

    ul_rslt = func(p_arg);

    spin_unlock_irqrestore(&pst_lock->lock, *pui_flags);

    return ul_rslt;
}

/*
 * 函 数 名  : oal_mutex_lock
 * 功能描述  : 获取互斥锁，在进程上下文使用, 如果获取不到会让出cpu
 * 输入参数  : lock 互斥锁结构体地址
 */
OAL_STATIC OAL_INLINE void oal_mutex_lock(oal_mutex_stru *lock)
{
    mutex_lock(lock);
}

/*
 * 函 数 名  : oal_mutex_lock
 * 功能描述  : 释放互斥锁，在进程上下文使用
 * 输入参数  : lock 互斥锁结构体地址
 */
OAL_STATIC OAL_INLINE void oal_mutex_unlock(oal_mutex_stru *lock)
{
    mutex_unlock(lock);
}

/*
 * 函 数 名  : oal_mutex_lock
 * 功能描述  : 获取互斥锁，如果获取不到立刻返回
 * 输入参数  : lock 互斥锁结构体地址
 */
OAL_STATIC OAL_INLINE int32_t oal_mutex_trylock(oal_mutex_stru *lock)
{
    return mutex_trylock(lock);
}

/*
 * 函 数 名  : oal_rw_lock_init
 * 功能描述  : 读写锁初始化，把读写锁设置为1（未锁状态）。
 * 输入参数  : pst_lock: 读写锁结构体地址
 */
OAL_STATIC OAL_INLINE void oal_rw_lock_init(oal_rwlock_stru *pst_lock)
{
    rwlock_init(pst_lock);
}

/*
 * 函 数 名  : oal_rw_lock_read_lock
 * 功能描述  : 获得指定的读锁
 * 输入参数  : pst_lock: 读写锁结构体地址
 */
OAL_STATIC OAL_INLINE void oal_rw_lock_read_lock(oal_rwlock_stru *pst_lock)
{
    read_lock(pst_lock);
}

/*
 * 函 数 名  : oal_rw_lock_read_unlock
 * 功能描述  : 释放指定的读锁
 * 输入参数  : pst_lock: 读写锁结构体地址
 */
OAL_STATIC OAL_INLINE void oal_rw_lock_read_unlock(oal_rwlock_stru *pst_lock)
{
    read_unlock(pst_lock);
}

/*
 * 函 数 名  : oal_rw_lock_write_lock
 * 功能描述  : 获得指定的写锁
 * 输入参数  : pst_lock: 读写锁结构体地址
 */
OAL_STATIC OAL_INLINE void oal_rw_lock_write_lock(oal_rwlock_stru *pst_lock)
{
    write_lock(pst_lock);
}

/*
 * 函 数 名  : oal_rw_lock_write_unlock
 * 功能描述  : 释放指定的写锁
 * 输入参数  : pst_lock: 读写锁结构体地址
 */
OAL_STATIC OAL_INLINE void oal_rw_lock_write_unlock(oal_rwlock_stru *pst_lock)
{
    write_unlock(pst_lock);
}

/*
 * 函 数 名  : oal_task_init
 * 功能描述  : 任务初始化。初始化完成后，任务处于挂起状态。
 * 输入参数  : pst_task: 任务结构体指针
 *             p_func: 任务处理函数入口地址
 *             ui_args: 需进行处理的函数的入参地址
 */
OAL_STATIC OAL_INLINE void oal_task_init(oal_tasklet_stru *pst_task, oal_defer_func p_func, oal_uint ui_args)
{
    tasklet_init(pst_task, p_func, ui_args);
}

OAL_STATIC OAL_INLINE void oal_task_kill(oal_tasklet_stru *pst_task)
{
    return tasklet_kill(pst_task);
}

/*
 * 函 数 名  : oal_task_sched
 * 功能描述  : 任务调度，令任务处于准备就绪状态；当任务执行完后，又回到挂起状态。
 */
OAL_STATIC OAL_INLINE void oal_task_sched(oal_tasklet_stru *pst_task)
{
    tasklet_schedule(pst_task);
}

/*
 * 函 数 名  : oal_task_is_scheduled
 * 功能描述  : 检测tasklet是否等待执行
 */
OAL_STATIC OAL_INLINE oal_uint oal_task_is_scheduled(oal_tasklet_stru *pst_task)
{
    return test_bit(TASKLET_STATE_SCHED, (unsigned long const volatile *)&pst_task->state);
}

/*
 * 函 数 名  : oal_atomic_read
 * 功能描述  : 读取原子变量的值
 * 输入参数  : *p_vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE int32_t oal_atomic_read(oal_atomic *p_vector)
{
    return atomic_read(p_vector);
}

/*
 * 函 数 名  : oal_atomic_set
 * 功能描述  : 原子地设置原子变量p_vector值为ul_val
 * 输入参数  : p_vector: 需要进行原子操作的原子变量地址
 *             l_val  : 需要被设置成的值
 */
OAL_STATIC OAL_INLINE void oal_atomic_set(oal_atomic *p_vector, int32_t l_val)
{
    atomic_set(p_vector, l_val);
}

/*
 * 函 数 名  : oal_atomic_dec
 * 功能描述  : 原子的给入参减1，
 * 输入参数  : *p_vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE void oal_atomic_dec(oal_atomic *p_vector)
{
    atomic_dec(p_vector);
}

/*
 * 函 数 名  : oal_atomic_inc
 * 功能描述  : 原子的给如参加一
 * 输入参数  : *p_vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE void oal_atomic_inc(oal_atomic *p_vector)
{
    atomic_inc(p_vector);
}

/*
 * 函 数 名  : oal_atomic_add
 * 功能描述  : 原子地设置原子变量p_vector值加上ul_val
 * 输入参数  : p_vector: 需要进行原子操作的原子变量地址
 *             l_val  : 需要加上的值
 */
OAL_STATIC OAL_INLINE void oal_atomic_add(oal_atomic *p_vector, int32_t l_val)
{
    atomic_add(l_val, p_vector);
}


/*
 * 函 数 名  : oal_atomic_inc_and_test
 * 功能描述  : 原子递增后检查结果是否为0
 * 输入参数  : *p_vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE int32_t oal_atomic_inc_and_test(oal_atomic *p_vector)
{
    return atomic_inc_and_test(p_vector);
}

/*
 * 函 数 名  : oal_atomic_dec_and_test
 * 功能描述  : 原子递减后检查结果是否为0
 * 输入参数  : *p_vector: 需要进行原子操作的原子变量地址
 */
OAL_STATIC OAL_INLINE int32_t oal_atomic_dec_and_test(oal_atomic *p_vector)
{
    return atomic_dec_and_test(p_vector);
}

/*
 * 函 数 名  : oal_time_get_stamp_us
 * 功能描述  : 获取微妙精度级的时间戳
 * 输入参数  : pst_usec: 时间结构体指针
 */
OAL_STATIC OAL_INLINE void oal_time_get_stamp_us(oal_time_us_stru *pst_usec)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
    struct timespec64 ts = {0};

    ktime_get_real_ts64(&ts);
#else
    struct timespec ts = {0};

    getnstimeofday(&ts);
#endif
    pst_usec->i_sec = ts.tv_sec;

    pst_usec->i_usec = ts.tv_nsec / 1000; /* 单位转换，1us=1000ns */
}

/*
 * 函 数 名  : oal_ktime_get
 * 功能描述  : 调用内核函数获取当前时间戳
 */
OAL_STATIC OAL_INLINE oal_time_t_stru oal_ktime_get(void)
{
    return ktime_get();
}

/*
 * 函 数 名  : oal_ktime_sub
 * 功能描述  : 调用内核函数获取时间差值
 */
OAL_STATIC OAL_INLINE oal_time_t_stru oal_ktime_sub(const oal_time_t_stru lhs, const oal_time_t_stru rhs)
{
    return ktime_sub(lhs, rhs);
}

OAL_STATIC OAL_INLINE void oal_timer_init(oal_timer_list_stru *pst_timer, uint32_t ul_delay,
                                          oal_timer_func p_func, uintptr_t arg)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 18, 0))
    init_timer(pst_timer);
    pst_timer->function = p_func;
    pst_timer->data = arg;
#else
    timer_setup(pst_timer, (void*)p_func, 0);
#endif
    pst_timer->expires = jiffies + msecs_to_jiffies(ul_delay);
}

OAL_STATIC OAL_INLINE int32_t oal_timer_delete(oal_timer_list_stru *pst_timer)
{
    return del_timer(pst_timer);
}

/*
 * 函 数 名  : oal_timer_delete_sync
 * 功能描述  : 同步删除定时器，用于多核
 * 输入参数  : pst_timer: 定时器结构体指针
 */
OAL_STATIC OAL_INLINE int32_t oal_timer_delete_sync(oal_timer_list_stru *pst_timer)
{
    return del_timer_sync(pst_timer);
}

/*
 * 函 数 名  : oal_timer_add
 * 功能描述  : 激活定时器
 * 输入参数  : pst_timer: 定时器结构体指针
 */
OAL_STATIC OAL_INLINE void oal_timer_add(oal_timer_list_stru *pst_timer)
{
    add_timer(pst_timer);
}

/*
 * 函 数 名  : oal_timer_start
 * 功能描述  : 重启定时器
 */
OAL_STATIC OAL_INLINE int32_t oal_timer_start(oal_timer_list_stru *pst_timer, oal_uint ui_delay)
{
    return mod_timer(pst_timer, (jiffies + msecs_to_jiffies(ui_delay)));
}

/*
 * 函 数 名  : oal_timer_start_on
 * 功能描述  : 指定cpu,重启定时器,调用时timer要处于非激活状态否者会死机
 */
OAL_STATIC OAL_INLINE void oal_timer_start_on(oal_timer_list_stru *pst_timer, oal_uint ui_delay, int32_t cpu)
{
    pst_timer->expires = jiffies + msecs_to_jiffies(ui_delay);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 34))
    add_timer_on(pst_timer, cpu);
#else
    /* 低版本内核add_timer_on符号未导出 */
    add_timer(pst_timer);
#endif
}

/*
 * 函 数 名  : oal_copy_from_user
 * 功能描述  : 将用户态数据拷贝到内核态
 * 输入参数  : p_to: 目的地址
 *             p_from : 源地址
 *             ul_size : 需要拷贝的长度
 */
OAL_STATIC OAL_INLINE uint32_t oal_copy_from_user(void *p_to, const void *p_from, uint32_t ul_size)
{
    return (uint32_t)copy_from_user(p_to, p_from, (oal_uint)ul_size);
}

/*
 * 函 数 名  : oal_copy_to_user
 * 功能描述  : 将内核态数据拷贝到用户态
 * 输入参数  : p_to: 目的地址
 *             p_from : 源地址
 *             ul_size : 需要拷贝的长度
 */
OAL_STATIC OAL_INLINE uint32_t oal_copy_to_user(void *p_to, const void *p_from, uint32_t ul_size)
{
    return (uint32_t)copy_to_user(p_to, p_from, (oal_uint)ul_size);
}

/*
 * 函 数 名  : oal_create_proc_entry
 * 功能描述  : 创建g_proc_entry结构体
 * 输入参数  : pc_name: 创建的proc_entry的名字
 *             us_mode: 创建模式
 *             pst_parent: 母proc_entry结构体，继承属性
 */
OAL_STATIC OAL_INLINE oal_proc_dir_entry_stru *oal_create_proc_entry(const char *pc_name, uint16_t us_mode,
                                                                     oal_proc_dir_entry_stru *pst_parent)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 10, 44))
    return NULL;
#else
    return create_proc_entry(pc_name, us_mode, pst_parent);
#endif
}

/*
 * 函 数 名  : oal_remove_proc_entry
 * 功能描述  : 创建g_proc_entry结构体
 * 输入参数  : pc_name: 创建的proc_entry的名字
 *             pst_parent: 母proc_entry结构体，继承属性
 */
OAL_STATIC OAL_INLINE void oal_remove_proc_entry(const char *pc_name, oal_proc_dir_entry_stru *pst_parent)
{
    return remove_proc_entry(pc_name, pst_parent);
}

/*
 * 函 数 名  : oal_time_is_before
 * 功能描述  : 判断ul_time是否比当前时间早
 *             若早，表示超时时间已过；若不早，表明还未超时
 */
OAL_STATIC OAL_INLINE uint32_t oal_time_is_before(oal_uint ui_time)
{
    return (uint32_t)time_is_before_jiffies(ui_time);
}

/*
 * 函 数 名  : oal_time_after
 * 功能描述  : 判断时间戳ul_time_a是否在ul_time_b之后:
 * 返 回 值  : Return: 1 ul_time_a在ul_time_b之后; 否则 Return: 0
 */
OAL_STATIC OAL_INLINE uint32_t oal_time_after(unsigned long ul_time_a, unsigned long ul_time_b)
{
    return (uint32_t)time_after(ul_time_a, ul_time_b);
}

/*
 * 函 数 名  : oal_time_after
 * 功能描述  : 判断时间戳ul_time_a是否在ul_time_b之后:
 * 返 回 值  : Return: 1 ul_time_a在ul_time_b之后; 否则 Return: 0
 * 限制条件  : 两数逻辑差值不能大于ox7FFFFFFF
 */
OAL_STATIC OAL_INLINE uint32_t oal_time_after32(uint32_t ul_time_a, uint32_t ul_time_b)
{
    return (uint32_t)((int32_t)((ul_time_b) - (ul_time_a)) < 0);
}

OAL_INLINE static char *oal_get_current_task_name(void)
{
    return current->comm;
}
/*
 * 函 数 名  : oal_wait_for_completion_timeout
 * 功能描述  : 同步：等待超时检查
 * 返 回 值  : Return: 0 if timed out, and positive (at least 1, or number of jiffies left till timeout) if completed.
 */
OAL_STATIC OAL_INLINE uint32_t oal_wait_for_completion_timeout(oal_completion *pst_completion, uint32_t ul_timeout)
{
    return (uint32_t)wait_for_completion_timeout(pst_completion, ul_timeout);
}


OAL_STATIC OAL_INLINE long oal_wait_for_completion_interruptible_timeout(oal_completion *pst_completion,
                                                                         unsigned long ul_timeout)
{
    return (long)wait_for_completion_interruptible_timeout(pst_completion, ul_timeout);
}

OAL_STATIC OAL_INLINE long oal_wait_for_completion_killable_timeout(oal_completion *pst_completion,
                                                                    unsigned long ul_timeout)
{
    return (long)wait_for_completion_killable_timeout(pst_completion, ul_timeout);
}

#ifdef _PRE_OAL_FEATURE_TASK_NEST_LOCK
/*
 * 函 数 名  : oal_smp_task_lock
 * 功能描述  : lock the task, the lock can be double locked by the same process
 */
extern void _oal_smp_task_lock_(oal_task_lock_stru *pst_lock, uintptr_t claim_addr);
#define oal_smp_task_lock(lock) _oal_smp_task_lock_(lock, (uintptr_t)_THIS_IP_)

/*
 * 函 数 名  : oal_smp_task_unlock
 * 功能描述  : unlock the task
 */
OAL_STATIC OAL_INLINE void oal_smp_task_unlock(oal_task_lock_stru *pst_lock)
{
    unsigned long flags;

    if (oal_warn_on(in_interrupt() || in_atomic())) {
        return;
    }

    if (oal_unlikely(!pst_lock->claimed)) {
        oal_warn_on(1);
        return;
    }

    oal_spin_lock_irq_save(&pst_lock->lock, &flags);
    if (--pst_lock->claim_cnt) {
        oal_spin_unlock_irq_restore(&pst_lock->lock, &flags);
    } else {
        pst_lock->claimed = 0;
        pst_lock->claimer = NULL;
        oal_spin_unlock_irq_restore(&pst_lock->lock, &flags);
        wake_up(&pst_lock->wq);
    }
}

OAL_STATIC OAL_INLINE void oal_smp_task_lock_init(oal_task_lock_stru *pst_lock)
{
    memset_s((void *)pst_lock, sizeof(oal_task_lock_stru), 0, sizeof(oal_task_lock_stru));

    oal_spin_lock_init(&pst_lock->lock);
    oal_wait_queue_init_head(&pst_lock->wq);
    pst_lock->claimed = 0;
    pst_lock->claim_cnt = 0;
}
#endif
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
OAL_STATIC OAL_INLINE void oal_do_gettimeofday(struct timespec64 *ts)
{
    ktime_get_real_ts64(ts);
}
#else
OAL_STATIC OAL_INLINE void oal_do_gettimeofday(struct timeval *tv)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
    struct timespec64 now;

    ktime_get_real_ts64(&now);
    tv->tv_sec = now.tv_sec;
    tv->tv_usec = now.tv_nsec / 1000; // 1us是1000ns
#else
    do_gettimeofday(tv);
#endif
}
#endif

OAL_STATIC OAL_INLINE uint64_t oal_get_usec(oal_timespec_stru *ts)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
    return (ts->tv_nsec / NSEC_PER_USEC);
#else
    return ts->tv_usec;
#endif
}

/*
 * 函 数 名  : oal_get_time_stamp_from_timeval
 * 功能描述  : 获取时间精度
 */
OAL_STATIC OAL_INLINE uint64_t oal_get_time_stamp_from_timeval(void)
{
    uint64_t curr_time;
    oal_timespec_stru ts;
    oal_do_gettimeofday(&ts);
    curr_time = oal_get_usec(&ts); // 1us是1000ns
    do_div(curr_time, USEC_PER_MSEC); // 1ms为1000us
    curr_time = curr_time + (uint64_t)ts.tv_sec * MSEC_PER_SEC; /* 1s是1000ms */

    return curr_time;
}

OAL_STATIC OAL_INLINE uint64_t oal_get_time_stamp_from_timeval_us(void)
{
    uint64_t curr_time;
    oal_timespec_stru ts;
    oal_do_gettimeofday(&ts);
    curr_time = oal_get_usec(&ts); // 1us是1000ns
    curr_time = curr_time + (uint64_t)ts.tv_sec * MSEC_PER_SEC * USEC_PER_MSEC; /* 1s是1000000us */

    return curr_time;
}

OAL_STATIC OAL_INLINE void oal_rtc_ktime_to_tm(oal_timespec_stru ts, struct rtc_time *tm)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 18, 0))
    rtc_time_to_tm(ts.tv_sec, tm);
#else
    *tm = rtc_ktime_to_tm((ktime_t)(ts.tv_sec * NSEC_PER_SEC));
#endif
}

OAL_STATIC OAL_INLINE void oal_get_real_time(oal_time_stru *pst_tm)
{
    struct rtc_time tm = {0};
    oal_timespec_stru ts;
    /* 获取当前UTC时间 */
    oal_do_gettimeofday(&ts);
    /* 把UTC时间调整本地时间 */
    ts.tv_sec -= sys_tz.tz_minuteswest * OAL_SEC_PER_MIN;
    /* 算出时间中的年月日等数值到tm中 */
    oal_rtc_ktime_to_tm(ts, &tm);

    memcpy_s(pst_tm, sizeof(oal_time_stru), &tm, sizeof(oal_time_stru));
}

OAL_STATIC OAL_INLINE unsigned long oal_access_write_ok(const void __user *addr, unsigned long size)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0))
    return access_ok(VERIFY_WRITE, (uintptr_t)addr, (int)size);
#elif (LINUX_VERSION_CODE < KERNEL_VERSION(5, 0, 0))
    return access_ok(VERIFY_WRITE, addr, size);
#else
    return access_ok(addr, size);
#endif
}

OAL_STATIC OAL_INLINE void oal_wakeup_source_init(struct wakeup_source *ws,
    const char *name)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
    if (ws) {
        memset_s((void *)ws, sizeof(*ws), 0, sizeof(*ws));
        ws->name = name;
    }
    wakeup_source_add(ws);
#else
    wakeup_source_init(ws, name);
#endif
}

OAL_STATIC OAL_INLINE void oal_wakeup_source_trash(struct wakeup_source *ws)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0))
    if (!ws) {
        return;
    }
    wakeup_source_remove(ws);
    __pm_relax(ws);
#else
    wakeup_source_trash(ws);
#endif
}

#endif /* end of oal_schedule.h */
