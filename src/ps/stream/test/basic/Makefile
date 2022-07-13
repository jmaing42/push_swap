BASE_PATH := ../../../..

INCS := \
	$(BASE_PATH)/ft \
	$(BASE_PATH)/ft/types \
	$(BASE_PATH)/ft/per_type \
	$(BASE_PATH)/ft/io \
	$(BASE_PATH)/ft/cstring \
	$(BASE_PATH)/ft/byte_map \

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/test.mk

test: test.exe
	$Qsh test.sh

Makefile: .cache/deps.mk
	$Qtouch $@
.cache/deps.mk: srcs.txt
	$Qmkdir -p .cache
	$Qsh $(BASE_PATH)/build/srcs_to_deps.sh test.exe < $< > $@

clean:
	$Qrm -rf .cache
fclean:
	$Qrm -f test.exe

-include .cache/deps.mk $(shell [ -d .cache ] && find .cache -name "*.d")
