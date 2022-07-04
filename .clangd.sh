#!/bin/sh

cd "$(dirname "$0")"

printf "CompileFlags:\n  Add:\n"

find src \
  | xargs dirname \
  | grep -v .cache \
  | cut -c 5- \
  | sort \
  | uniq \
  | xargs printf '    - "-I%s"\n' \
