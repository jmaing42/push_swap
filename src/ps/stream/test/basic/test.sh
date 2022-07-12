#!/bin/sh

set -e

find data -name "*.out.txt" | sed s/\\.out\\.txt\$// | cut -c 6- | while IFS= read -r line
do
  ./test.exe < "data/$line.in.txt" | cmp "data/$line.out.txt"
  if [ "$V" = "1" ]; then
    if [ -t 1 ]; then
      printf "\033[0;32m[PASS]\033[0m "
    else
      printf "[PASS] "
    fi
    printf "ps_stream/basic - %s\n" "$line"
  fi
done
