BASE_PATH := ../../../..

include $(BASE_PATH)/build/common.mk

build: build_tester

.PHONY: build_tester
build_tester:
	$(Q2)$(MAKE) -C ../tester build

test:
	$(Q2)sh "test.sh" "ps/solve/tst"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/test.mk
