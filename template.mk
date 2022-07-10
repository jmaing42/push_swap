NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker
NAME_LIBFT = libft.a
NAME_LIBPS = libps.a

EXECUTABLE_TARGETS = $(NAME_PUSH_SWAP) $(NAME_CHECKER)
LIBS = $(NAME_LIBFT) $(NAME_LIBPS)
OBJS = $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_LIBFT) $(OBJS_LIBPS)

OTHER_USEFUL_FILES = .editorconfig .gitignore

CFLAGS = -Wall -Wextra -Werror

all: $(EXECUTABLE_TARGETS) $(OTHER_USEFUL_FILES)
bonus: all
clean:
	rm -f $(OBJS) $(LIBS) $(OTHER_USEFUL_FILES)
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
$(NAME_LIBPS): $(OBJS_LIBPS)
$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP) $(NAME_LIBFT) $(NAME_LIBPS)
$(NAME_CHECKER): $(OBJS_CHECKER) $(NAME_LIBFT) $(NAME_LIBPS)

$(LIBS):
	$(AR) $(ARFLAGS) $@ $^
$(EXECUTABLE_TARGETS):
	$(CC) $(LDFLAGS) -o $@ $^
