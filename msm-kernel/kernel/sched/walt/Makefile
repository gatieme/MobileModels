# SPDX-License-Identifier: GPL-2.0-only

KCOV_INSTRUMENT := n
KCSAN_SANITIZE := n

obj-$(CONFIG_SCHED_WALT) += sched-walt.o
sched-walt-$(CONFIG_SCHED_WALT) := walt.o boost.o sched_avg.o walt_pause.o core_ctl.o trace.o input-boost.o sysctl.o cpufreq_walt.o fixup.o walt_lb.o walt_rt.o walt_cfs.o walt_tp.o

ifneq ($(CONFIG_SCHED_PERF_CTRL),)
sched-walt-$(CONFIG_SCHED_WALT) += ../sched_perf_ctrl.o
endif

ifneq ($(CONFIG_HUAWEI_DDR_PERF_CTRL),)
sched-walt-$(CONFIG_SCHED_WALT) += ../../../drivers/perf_ctrl/ddr_perf_ctrl.o
endif

ifneq ($(CONFIG_HUAWEI_THERMAL_PERF_CTRL),)
sched-walt-$(CONFIG_SCHED_WALT) += ../../../drivers/perf_ctrl/thermal_perf_ctrl.o
endif

ifneq ($(CONFIG_HUAWEI_DEV_PERF_CTRL),)
sched-walt-$(CONFIG_SCHED_WALT) += ../../../drivers/perf_ctrl/dev_perf_ctrl.o
endif

ifneq ($(CONFIG_RENDER_RT),)
sched-walt-$(CONFIG_SCHED_WALT) += ../../../drivers/perf_ctrl/render_rt.o
endif

ifneq ($(CONFIG_HUAWEI_PERF_CTRL),)
sched-walt-$(CONFIG_SCHED_WALT) += ../../../drivers/perf_ctrl/perf_ctrl.o
endif

ifneq ($(CONFIG_DRG),)
sched-walt-$(CONFIG_SCHED_WALT) += ../../../drivers/hw_drg/drg.o
endif

ifneq ($(CONFIG_HW_RTG),)
sched-walt-$(CONFIG_SCHED_WALT) += ../hw_rtg/rtg_sched.o
endif

ifneq ($(CONFIG_HW_RTG_FRAME),)
sched-walt-$(CONFIG_SCHED_WALT) += ../hw_rtg/trans_rtg.o ../hw_rtg/iaware_rtg.o ../hw_rtg/proc_state.o ../hw_rtg/set_rtg.o ../hw_rtg/frame_timer.o ../hw_rtg/frame_info.o ../hw_rtg/frame_perf_ctrl.o
endif

ifneq ($(CONFIG_HW_RTG_AUX),)
sched-walt-$(CONFIG_SCHED_WALT)	+= ../hw_rtg/aux_info.o
endif

ifneq ($(CONFIG_HW_RTG_FRAME_RME),)
sched-walt-$(CONFIG_SCHED_WALT) += ../hw_rtg/frame_rme.o
endif

ifneq ($(CONFIG_HW_RTG_DEBUG),)
sched-walt-$(CONFIG_SCHED_WALT) += ../hw_rtg/rtg_debug.o ../hw_rtg/aux_debug.o ../hw_rtg/frame_debug.o
endif

ifneq ($(CONFIG_HW_RTG_PERF_CTRL),)
sched-walt-$(CONFIG_SCHED_WALT) += ../hw_rtg/rtg_perf_ctrl.o
endif

ifneq ($(CONFIG_HW_RTG_PSEUDO_TICK),)
sched-walt-$(CONFIG_SCHED_WALT) += ../hw_rtg/rtg_pseudo.o
endif

ifneq ($(CONFIG_HW_RTG_MULTI_FRAME),)
sched-walt-$(CONFIG_SCHED_WALT) += ../hw_rtg/multi_frame_info.o
endif

obj-$(CONFIG_SCHED_WALT_DEBUG) += sched-walt-debug.o
sched-walt-debug-$(CONFIG_SCHED_WALT_DEBUG) := walt_debug.o preemptirq_long.o
