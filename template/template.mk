
NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker
NAME_LIBFT = libft.a
NAME_LIBFTO = libfto.a
NAME_LIBPS = libps.a

EXECUTABLE_TARGETS = $(NAME_PUSH_SWAP) $(NAME_CHECKER)
LIBRARY_TARGETS = $(NAME_LIBFT) $(NAME_LIBFTO) $(NAME_LIBPS)
OBJS = $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_LIBFT) $(OBJS_LIBFTO) $(OBJS_LIBPS)

OTHER_USEFUL_FILES = .editorconfig .gitignore

CFLAGS = -Wall -Wextra -Werror


default: all
.PHONY: default


.PHONY: all
all: $(NAME_PUSH_SWAP) $(OTHER_USEFUL_FILES)

.PHONY: bonus
bonus: $(NAME_CHECKER) $(OTHER_USEFUL_FILES)

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIBRARY_TARGETS) $(OTHER_USEFUL_FILES)

.PHONY: fclean
fclean: clean
	rm -f $(EXECUTABLE_TARGETS)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.editorconfig:
	printf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig

.gitignore:
	(printf ".*\n*.o\n\n" && echo "$(EXECUTABLE_TARGETS) $(LIBRARY_TARGETS)" | xargs -n 1 echo) > $@


$(EXECUTABLE_TARGETS):
	$(CC) $(LDFLAGS) -o $@ $^
$(LIBRARY_TARGETS):
	$(AR) $(ARFLAGS) $@ $^

$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP) $(LIBRARY_TARGETS)
$(NAME_CHECKER): $(OBJS_CHECKER) $(LIBRARY_TARGETS)
$(NAME_LIBFT): $(OBJS_LIBFT)
$(NAME_LIBFTO): $(OBJS_LIBFTO)
$(NAME_LIBPS): $(OBJS_LIBPS)

