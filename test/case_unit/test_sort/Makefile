Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

LIBFT := ../../../src/.cache/libft.development.debug.address.a
SRC_DIR := ../../../src
SRCS := main.c $(LIBFT) $(SRC_DIR)/push_swap_solve_internal_sort.c $(SRC_DIR)/push_swap_solve_internal_reverse.c

.PHONY: all clean fclean test $(LIBFT)
all: test
clean:
	$Qrm -f test.exe
fclean: clean
test: test.exe
	$Q./$< false < input.txt | cmp output_asc.txt
	$Q./$< true < input.txt | cmp output_desc.txt
test.exe: $(SRCS)
	$Q$(CC) -o $@ $^ -g3 -fsanitize=address

$(LIBFT):
	$Qmake -C ../../../src TARGET=development PROFILE=debug SANITIZER=address .cache/libft.development.debug.address.a
