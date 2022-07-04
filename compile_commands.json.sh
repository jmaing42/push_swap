#!/bin/sh

cd "$(dirname "$0")"

INCS=$(find src | xargs dirname | grep -v .cache | cut -c 5- | sort | uniq | xargs printf '"-I%s", ')

printf '[\n'

find src -type f -name "*.c" | cut -c 4- | xargs -L1 -I {} printf '  { "directory": "src", "arguments": ["clang", %s"-c", "-o", "%s.o", "%s.c"], "file": "%s.c" },\n' "$INCS" "{}" "{}" "{}"

printf '  { "directory": "dev", "arguments": ["clang", %s"-c", "-o", "main.o", "main.c"], "file": "main.c" }\n' "$INCS"

printf ']\n'
