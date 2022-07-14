include $(BASE_PATH)/build/common.mk

all: test
.PHONY: all test clean fclean re build dev

test clean fclean build dev:
	$Qfind . -mindepth 1 -maxdepth 1 -type d | xargs -L1 -I {} make -C {} $@
