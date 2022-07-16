BASE_PATH := ../../../..

include $(BASE_PATH)/build/common.mk

test:
	$Qsh "$(BASE_PATH)/build/test/inout_line.sh" "ps/hardcoded/find_index"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

include $(BASE_PATH)/build/test.mk
