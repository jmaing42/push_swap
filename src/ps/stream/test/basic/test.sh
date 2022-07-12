#!/bin/sh

set -e

find data -name "*.out.txt" | sed s/\\.out\\.txt\$// | cut -c 6- | while IFS= read -r line
do
  if ./test.exe < "data/$line.in.txt" | cmp -s "data/$line.out.txt" ; then
    if [ "$V" = "1" ]; then
      if [ -t 1 ]; then
        printf "\033[0;32m[PASS]\033[0m "
      else
        printf "[PASS] "
      fi
      printf "ps_stream/basic - %s\n" "$line"
    fi
  else
    if [ "$V" = "1" ]; then
      if [ -t 1 ]; then
        printf "\033[0;31m[FAIL]\033[0m "
      else
        printf "[FAIL] "
      fi
      printf "ps_stream/basic - %s\n" "$line"
    fi
    exit 1
  fi
done
