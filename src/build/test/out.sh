#!/bin/sh

set -e

find data -name "*.txt" | sed s/\\.txt\$// | sort | cut -c 6- | while IFS= read -r line
do
  if .cache/test.exe "$line" | cmp -s "data/$line.txt" ; then
    if [ "$V" = "1" ]; then
      if [ -t 1 ]; then
        printf "\033[0;32m[PASS]\033[0m "
      else
        printf "[PASS] "
      fi
      printf "$1 - %s\n" "$line"
    fi
  else
    if [ "$V" = "1" ]; then
      if [ -t 1 ]; then
        printf "\033[0;31m[FAIL]\033[0m "
      else
        printf "[FAIL] "
      fi
      printf "$1 - %s\n" "$line"
    fi
    exit 1
  fi
done
