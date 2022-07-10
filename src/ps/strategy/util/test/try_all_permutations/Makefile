BASE_PATH := ../../../../..
include $(BASE_PATH)/build/common.mk

all: test
.PHONY: all test clean fclean re
test: test.exe
	$Qsh test.sh

CPPFLAGS := -I../../.. -I../../../../stream -I../../../../../ft/types
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS)

test.exe: main.c ../../ps_strategy_util_try_all_permutations.c
	$Q$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
