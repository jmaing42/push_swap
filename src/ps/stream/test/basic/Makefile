BASE_PATH := ../../../..

INCS := \
	$(BASE_PATH)/ft \
	$(BASE_PATH)/ft/types \
	$(BASE_PATH)/ft/per_type \
	$(BASE_PATH)/ft/io \
	$(BASE_PATH)/ft/cstring \
	$(BASE_PATH)/ft/byte_map \

OBJS := main.o ps_stream_new.o ps_stream_free.o ps_stream_append.o ps_stream_print.o ps_stream_internal_append.o ps_stream_internal_node.o ps_stream_internal_reduce.o ft_size_t.o ft_pointer.o ft_io_basic.o ft_cstring_strlen.o ft_byte_map.o

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/test.mk

test: test.exe
	$Qsh test.sh

main.o: main.c
ps_stream_new.o: ../../ps_stream_new.c
ps_stream_free.o: ../../ps_stream_free.c
ps_stream_append.o: ../../ps_stream_append.c
ps_stream_print.o: ../../ps_stream_print.c
ps_stream_internal_append.o: ../../ps_stream_internal_append.c
ps_stream_internal_node.o: ../../ps_stream_internal_node.c
ps_stream_internal_reduce.o: ../../ps_stream_internal_reduce.c
ft_size_t.o: $(BASE_PATH)/ft/per_type/ft_size_t.c
ft_pointer.o: $(BASE_PATH)/ft/per_type/ft_pointer.c
ft_io_basic.o: $(BASE_PATH)/ft/io/ft_io_basic.c
ft_cstring_strlen.o: $(BASE_PATH)/ft/cstring/ft_cstring_strlen.c
ft_byte_map.o: $(BASE_PATH)/ft/byte_map/ft_byte_map.c
test.exe: $(OBJS)
