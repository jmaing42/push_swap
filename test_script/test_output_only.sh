#!/bin/sh

set -e

if .ft/home/executable.exe | cmp -s - "data.txt" ; then
  if [ "$V" = "1" ]; then
    if [ -t 1 ]; then
      printf "\033[0;32m[PASS]\033[0m "
    else
      printf "[PASS] "
    fi
    printf "%s\n" "$FT_TEST_NAME"
  fi
else
  if [ "$V" = "1" ]; then
    if [ -t 1 ]; then
      printf "\033[0;31m[FAIL]\033[0m "
    else
      printf "[FAIL] "
    fi
    printf "%s\n" "$FT_TEST_NAME"
  fi
  exit 1
fi
