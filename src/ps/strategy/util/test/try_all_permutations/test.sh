#!/bin/sh

set -e

./test.exe 0 | cmp data/0.txt
./test.exe 1 | cmp data/1.txt
./test.exe 2 | cmp data/2.txt
./test.exe 3 | cmp data/3.txt
./test.exe 4 | cmp data/4.txt
./test.exe 5 | cmp data/5.txt

find data -name "*.txt" | sed s/\\.txt\$// | sort | cut -c 6- | while IFS= read -r line
do
  if ./test.exe $line | cmp "data/$line.txt" ; then
    if [ "$V" = "1" ]; then
      if [ -t 1 ]; then
        printf "\033[0;32m[PASS]\033[0m "
      else
        printf "[PASS] "
      fi
      printf "ps_strategy_util/try_all_permutations - %s\n" "$line"
    fi
  else
    if [ "$V" = "1" ]; then
      if [ -t 1 ]; then
        printf "\033[0;31m[FAIL]\033[0m "
      else
        printf "[FAIL] "
      fi
      printf "ps_strategy_util/try_all_permutations - %s\n" "$line"
    fi
    exit 1
  fi
done
