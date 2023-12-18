################################################################################

1. How to Build
	- Set Environment
		 - export LTO=thin
		 - export TARGET_BOARD_PLATFORM="taro"

	- build
		$ OUT_DIR=./kernel-out BUILD_CONFIG=./common/build.config.msm.waipio ./build/all-variants.sh ./build/build.sh

2. Output files
	- Kernel : arch/arm64/boot/Image.gz-dtb
	- module : drivers/*/*.o

3. How to Clean
		$ rm -rf kernel-out
################################################################################
