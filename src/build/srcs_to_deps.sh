#!/bin/sh

while IFS= read -r line
do
  line=$(printf "$line" | sed s/\\.c\$//)
  printf "%s: .cache/%s\n" "$1" "$(basename "$line.o")"
  printf ".cache/%s: %s | .cache\n" "$(basename "$line.o")" "$line.c"
done
