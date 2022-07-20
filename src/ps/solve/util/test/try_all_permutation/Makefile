BASE_PATH := ../../../../..

include $(BASE_PATH)/build/common.mk

test:
	$(Q2)sh "$(BASE_PATH)/build/script/out.sh" "ps/strategy/util/try_all_permutations"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

include $(BASE_PATH)/build/test.mk
