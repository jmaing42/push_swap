Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

SRC_DIR := ../../../src
SRCS := main.c $(SRC_DIR)/push_swap_solve_internal_sort.c

all: test
clean:
	$Qrm -f test.exe
fclean: clean
test: test.exe
	$Q./$< false < input.txt | cmp output_asc.txt
	$Q./$< true < input.txt | cmp output_desc.txt
test.exe: $(SRCS)
	$Q$(CC) -o $@ $^
