#!/bin/sh

set -e

find data -name "*.out.txt" | sed s/\\.out\\.txt\$// | while IFS= read -r line
do
  ./test.exe < "$line.in.txt" | cmp "$line.out.txt"
done
