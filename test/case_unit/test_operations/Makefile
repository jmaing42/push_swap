Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

LIBFT := ../../../src/.cache/libft.production.release.a
SRC_DIR := ../../../src
SRCS := main.c $(LIBFT) $(SRC_DIR)/push_swap_solve_internal_operation.c

.PHONY: all clean fclean test $(LIBFT)
all: test
clean:
	$Qrm -f test.exe
fclean: clean
test: test.exe
	$Q./$< < input.txt | cmp output.txt
test.exe: $(SRCS)
	$Q$(CC) -o $@ $^

$(LIBFT):
	$Qmake -C ../../../src .cache/libft.production.release.a
