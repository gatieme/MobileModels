subdir-ccflags-y += -I$(srctree)/drivers/staging/android
subdir-ccflags-y += -I$(srctree)/drivers/staging/android/ion
subdir-ccflags-y += -I$(srctree)/mm
subdir-ccflags-y += -I$(srctree)/kernel
subdir-ccflags-y += -I$(srctree)/drivers/gpu/hisi/kmd

obj-$(CONFIG_DFX_MEMCHECK) += memcheck_mod.o memcheck_ioctl.o memcheck_account.o \
	memcheck_log_ion.o memcheck_log_ashmem.o memcheck_log_cma.o memcheck_log_vmalloc.o  memcheck_log_gpumem_hvgr.o\
	memcheck_fd_socket.o memcheck_fd_pipe.o memcheck_fd_fence.o
obj-$(CONFIG_DFX_MEMCHECK_STACK) += memcheck_stack.o memcheck_detail.o
