KBUILD_EXTRA_SYMBOLS+=$(OUT)/obj/kernel_platform/msm-kernel/sound/usb/Module.symvers
KBUILD_EXTRA_SYMBOLS+=$(OUT)/obj/DLKM_OBJ/kernel_platform/msm-kernel/Module.symvers
export KBUILD_EXTRA_SYMBOLS
modules:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) modules $(KBUILD_OPTIONS) VERBOSE=1
modules_install:
	$(MAKE) M=$(M) -C $(KERNEL_SRC) modules_install
clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) clean
