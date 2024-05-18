# Makefile for the Honor Kernel Harden.
#

ccflags-y += -I$(srctree)/

obj-$(CONFIG_HONOR_KERNEL_STACK_NX) += kernel_harden/hn_stack_nx.o
obj-$(CONFIG_HONOR_KERNEL_MODULE_RANDOMIZE) += kernel_harden/hn_kaslr_module.o
obj-$(CONFIG_HONOR_HIDESYMS) += kernel_harden/hn_litehide_symbols.o
obj-$(CONFIG_HONOR_KASLR_DEBUGFS) += kernel_harden/hn_kaslr_debugfs.o
obj-$(CONFIG_GCC_PLUGIN_RANDSTRUCT_DEBUGFS) += kernel_harden/hn_struct_rand_debugfs.o
obj-$(CONFIG_HONOR_FREELIST_RANDOM_DEBUGFS) += kernel_harden/hn_freelist_random_debugfs.o
obj-$(CONFIG_HONOR_DOUBLE_FREE_CHECK_DEBUGFS) += kernel_harden/hn_double_free_debugfs.o
obj-$(CONFIG_HONOR_HARDEN_DOUBLE_FREE_CHECK_DEBUGFS) += kernel_harden/hn_harden_double_free_debugfs.o
obj-y += kernel_harden/hn_ptrace_log.o

