# SPDX-License-Identifier: GPL-2.0
#
# Makefile for the kernel security code
#

obj-$(CONFIG_KEYS)			+= keys/

# always enable default capabilities
obj-y					+= commoncap.o
obj-$(CONFIG_MMU)			+= min_addr.o

# Object file lists
obj-$(CONFIG_SECURITY)			+= security.o
obj-$(CONFIG_SECURITYFS)		+= inode.o
obj-$(CONFIG_SECURITY_SELINUX)		+= selinux/
obj-$(CONFIG_SECURITY_SMACK)		+= smack/
obj-$(CONFIG_SECURITY)			+= lsm_audit.o
obj-$(CONFIG_SECURITY_TOMOYO)		+= tomoyo/
obj-$(CONFIG_SECURITY_APPARMOR)		+= apparmor/
obj-$(CONFIG_SECURITY_YAMA)		+= yama/
obj-$(CONFIG_SECURITY_LOADPIN)		+= loadpin/
obj-$(CONFIG_SECURITY_SAFESETID)       += safesetid/
obj-$(CONFIG_SECURITY_LOCKDOWN_LSM)	+= lockdown/
obj-$(CONFIG_CGROUPS)			+= device_cgroup.o
obj-$(CONFIG_BPF_LSM)			+= bpf/
obj-$(CONFIG_SECURITY_LANDLOCK)		+= landlock/

# Object integrity file lists
obj-$(CONFIG_INTEGRITY)			+= integrity/

include security/kernel_harden/Makefile

# Object kernel_harden_test file
obj-$(CONFIG_KERNEL_HARDEN_DEBUG)       += kernel_harden_test/

# Object kernel_stp file
obj-$(CONFIG_HN_KERNEL_STP)			+= kernel_stp/

# Object check_root file
obj-$(CONFIG_HONOR_PROC_CHECK_ROOT)     +=check_root/

# Object root_scan
obj-$(CONFIG_HN_ROOT_SCAN)     +=hw_root_scan/

# Object root_scan
obj-$(CONFIG_HONOR_EIMA)     +=eima/
