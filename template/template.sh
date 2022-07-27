#!/bin/sh

set -e

printf ".POSIX:\n# this file is generated, do not modify directly\n\n"

printf "OBJS_PUSH_SWAP = %s\n" "$(find . -name "push_swap_*.c" | grep -v /test/ | cut -c 3- | sed s/\\.c\$/.o/ | xargs)"
printf "OBJS_CHECKER = %s\n" "$(find . -name "checker_*.c" | grep -v /test/ | cut -c 3- | sed s/\\.c\$/.o/ | xargs)"
printf "OBJS_LIBFT = %s\n" "$(find . -name "ft_*.c" | grep -v /test/ | cut -c 3- | sed s/\\.c\$/.o/ | xargs)"
printf "OBJS_LIBFTO = %s\n" "$(find . -name "fto_*.c" | grep -v /test/ | cut -c 3- | sed s/\\.c\$/.o/ | xargs)"
printf "OBJS_LIBPS = %s\n" "$(find . -name "ps_*.c" | grep -v /test/ | cut -c 3- | sed s/\\.c\$/.o/ | xargs)"

printf "\n"

cat ../template/template.mk

printf "\n# dependencies\n"

find . -name "*.c" | cut -c 3- | sort | xargs clang -MM -MG
