BASE_PATH := ../../../..
include $(BASE_PATH)/build/common.mk

all: test
.PHONY: all test clean fclean re
test: test.exe
	$Qsh test.sh

INCS := \
	$(BASE_PATH)/ft \
	$(BASE_PATH)/ft/types \
	$(BASE_PATH)/ft/per_type \
	$(BASE_PATH)/ft/io \
	$(BASE_PATH)/ft/cstring \
	$(BASE_PATH)/ft/byte_map \

SRCS := \
	main.c \
	../../ps_stream_new.c \
	../../ps_stream_free.c \
	../../ps_stream_append.c \
	../../ps_stream_print.c \
	../../ps_stream_internal_append.c \
	../../ps_stream_internal_reduce.c \
	../../ps_stream_internal_node.c \
	$(BASE_PATH)/ft/per_type/ft_size_t.c \
	$(BASE_PATH)/ft/io/ft_io_basic.c \
	$(BASE_PATH)/ft/cstring/ft_cstring_strlen.c \
	$(BASE_PATH)/ft/byte_map/ft_byte_map.c \

COMMON_FLAGS := -fsanitize=address

CPPFLAGS := $(patsubst %, -I%, $(INCS))
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS) $(COMMON_FLAGS) -g3
LDFLAGS := $(COMMON_FLAGS)

test.exe: $(SRCS)
	$Q$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
