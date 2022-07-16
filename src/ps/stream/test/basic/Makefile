BASE_PATH := ../../../..

include $(BASE_PATH)/build/common.mk

test:
	$Qsh "$(BASE_PATH)/build/test/inout.sh" "ps/stream (basic)"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/test.mk
