#!/bin/sh

set -e

./test.exe 0 | cmp data/0.txt
./test.exe 1 | cmp data/1.txt
./test.exe 2 | cmp data/2.txt
./test.exe 3 | cmp data/3.txt
./test.exe 4 | cmp data/4.txt
./test.exe 5 | cmp data/5.txt
