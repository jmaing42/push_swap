include $(BASE_PATH)/build/common.mk

all: test
.PHONY: all test clean fclean re build dev

CPPFLAGS := $(patsubst %, -I%, $(INCS))
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS) $(COMMON_FLAGS) -g3
LDFLAGS := $(COMMON_FLAGS)

%.a:
	$Q$(AR) crs $@ $^
%.o:
	$Q$(CC) -MMD -MJ $@.part.json $(CFLAGS) -o $@ -c $<
%.exe:
	$Q$(CC) $(LDFLAGS) -o $@ $^

include $(BASE_PATH)/build/compile_commands.mk

.PHONY: clean_test
clean_test:
	$Qfind . -name "*.o" -o -name "*.d" | xargs rm

.PHONY: fclean_test
fclean_test: clean_test
	$Qrm -rf test.exe

clean: clean_test
fclean: fclean_test
