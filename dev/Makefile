NAME := main.exe

all: $(NAME) dev

CPPFLAGS := $(shell find ../src -type d -mindepth 1 | grep -v /test/ | sed "s/^/-I /" | xargs)
CFLAGS := $(CPPFLAGS) -g3 -O3

../src/.cache/libft.production.release.a:
	$(MAKE) -C ../src .cache/libft.production.release.a

../src/.cache/libps.production.release.a:
	$(MAKE) -C ../src .cache/libps.production.release.a

$(NAME): main.o ../src/.cache/libft.production.release.a ../src/.cache/libps.production.release.a
	clang $(LDFLAGS) -o $@ $^

%.o: %.c
	clang $(CFLAGS) -o $@ -c $< -MJ $@.part.json -MMD

dev: compile_commands.json

compile_commands.json:
	-$(MAKE) $(NAME) -k
	(echo "[" && find . -name "*.part.json" | xargs cat && echo "]") > $@

.PHONY: all dev compile_commands.json ../src/.cache/libft.production.release.a ../src/.cache/libps.production.release.a

-include $(wildcard *.d)
