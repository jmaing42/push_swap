BASE_PATH := ../../../../..
include $(BASE_PATH)/build/common.mk
include $(BASE_PATH)/build/compile_commands.mk

all: test
.PHONY: all test clean fclean re
test: test.exe
	$Qsh test.sh

CPPFLAGS := -I../../.. -I../../../../stream -I../../../../../ft/types
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS)

test.exe: main.c ../../ps_strategy_util_try_all_permutations.c
	$Q$(CC) -MJ $@.part.json $(CFLAGS) $(LDFLAGS) -o $@ $^

build: test.exe
clean:
	$Qrm test.exe
fclean: clean
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
