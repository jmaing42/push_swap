#!/bin/sh

set -e

find push_swap | sort > tmp_initial.txt
make -C push_swap all
make -C push_swap -q all
find push_swap | sort > tmp_all.txt
make -C push_swap clean
! make -C push_swap -q all
find push_swap | sort > tmp_all_clean.txt
cat tmp_all.txt tmp_all_clean.txt | sort | uniq | cmp -s tmp_all.txt
cat tmp_initial.txt template_all.txt | sort | uniq | cmp -s tmp_all_clean.txt
