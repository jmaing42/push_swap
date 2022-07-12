include $(BASE_PATH)/build/common.mk

all: test
.PHONY: all test clean fclean re build

test clean fclean re dev:
	$Qfind . -mindepth 1 -maxdepth 1 -type d | xargs -L1 -I {} make -C {} $@
