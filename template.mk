NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker
NAME_LIBFT = libft.a
EXECUTABLE_TARGETS = $(NAME_PUSH_SWAP) $(NAME_CHECKER)

OTHER_USEFUL_FILES = .editorconfig .gitignore

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER) $(OTHER_USEFUL_FILES)
bonus: all
clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_LIBFT) $(LIBFT) $(OTHER_USEFUL_FILES)
fclean: clean
	rm -f $(EXECUTABLE_TARGETS)
re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: all bonus clean fclean re

.editorconfig:
	printf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	(printf ".*\n*.o\n\n" && echo "$(EXECUTABLE_TARGETS) $(NAME_LIBFT)" | xargs -n 1 echo) > $@

$(NAME_LIBFT): $(OBJS_LIBFT)
	$(AR) $(ARFLAGS) $@ $^
$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP) $(NAME_LIBFT)
	$(CC) $(LDFLAGS) -o $@ $^
$(NAME_CHECKER): $(OBJS_CHECKER) $(NAME_LIBFT)
	$(CC) $(LDFLAGS) -o $@ $^
