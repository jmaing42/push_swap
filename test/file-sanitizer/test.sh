#!/bin/sh

set -e

# initial make all
find push_swap | sort > tmp_initial.txt
make -C push_swap all
make -C push_swap -q all
find push_swap | sort > tmp_all.txt

# initial make all clean
make -C push_swap clean
! make -C push_swap -q all
find push_swap | sort > tmp_all_clean.txt
cat tmp_all.txt tmp_all_clean.txt | sort | uniq | cmp -s tmp_all.txt
cat tmp_initial.txt template_all.txt | sort | uniq | cmp -s tmp_all_clean.txt

# make fclean
make -C push_swap fclean
! make -C push_swap -q all
find push_swap | sort | cmp -s tmp_initial.txt
