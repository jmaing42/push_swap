NAME := main.exe

all: $(NAME) dev

COMMON_FLAGS := -fsanitize=address
CPPFLAGS := $(shell find ../src -type d -mindepth 1 | grep -v /test/ | sed "s/^/-I /" | xargs)
CFLAGS := $(CPPFLAGS) -g3 $(COMMON_FLAGS)
LDFLAGS := $(COMMON_FLAGS)

../src/.cache/libft.development.debug.address.a:
	$(MAKE) -C ../src PROFILE=debug TARGET=development SANITIZER=address .cache/libft.development.debug.address.a

../src/.cache/libps.development.debug.address.a:
	$(MAKE) -C ../src PROFILE=debug TARGET=development SANITIZER=address .cache/libps.development.debug.address.a

$(NAME): main.o ../src/.cache/libft.development.debug.address.a ../src/.cache/libps.development.debug.address.a
	clang $(LDFLAGS) -o $@ $^

%.o: %.c
	clang $(CFLAGS) -o $@ -c $< -MJ $@.part.json -MMD

dev: compile_commands.json

compile_commands.json:
	-$(MAKE) $(NAME) -k
	(echo "[" && find . -name "*.part.json" | xargs cat && echo "]") > $@

.PHONY: all dev compile_commands.json ../src/.cache/libft.development.debug.address.a ../src/.cache/libps.development.debug.address.a

-include $(wildcard *.d)
