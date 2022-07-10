include $(BASE_PATH)/build/common.mk

all: test
.PHONY: all test clean fclean re

test clean fclean re:
	$Qfind . -mindepth 1 -maxdepth 1 -type d | xargs -L1 -I {} make -C {} $@
