Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

SRC_DIR := ../../../src
SRCS := main.c $(SRC_DIR)/push_swap_solve_internal_operation.c $(SRC_DIR)/ft_io_basic.c $(SRC_DIR)/ft_size_t.c $(SRC_DIR)/ft_exit.c $(SRC_DIR)/ft_cstring_strlen.c $(SRC_DIR)/ft_byte_map.c

all: test
clean:
	$Qrm -f test.exe
fclean: clean
test: test.exe
	$Q./$< < input.txt | cmp output.txt
test.exe: $(SRCS)
	$Q$(CC) -o $@ $^
