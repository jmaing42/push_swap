#!/bin/sh

set -e


[ "$V" != "1" ] && [ "$V" != "2" ] && [ "$V" != "3" ] && [ "$VERBOSE" != "1" ] && [ "$VERBOSE" != "2" ] && [ "$VERBOSE" != "3" ] || echo "Testing Makefile"

# initial
make -C push_swap -q all && exit 1 || :
make -C push_swap -q bonus && exit 1 || :
make -C push_swap -q push_swap && exit 1 || :
make -C push_swap -q checker && exit 1 || :
make -C push_swap -q && exit 1 || :
find push_swap | sort > tmp_initial.txt


[ "$V" != "1" ] && [ "$V" != "2" ] && [ "$V" != "3" ] && [ "$VERBOSE" != "1" ] && [ "$VERBOSE" != "2" ] && [ "$VERBOSE" != "3" ] || echo "1. testing all"

# make all
find push_swap | sort | cmp -s tmp_initial.txt
make -C push_swap all > /dev/null 2> /dev/null
make -C push_swap -q
make -C push_swap -q all
make -C push_swap -q push_swap
find push_swap | sort > tmp_all.txt
# make all clean
make -C push_swap clean > /dev/null 2> /dev/null
find push_swap | sort > tmp_all_clean.txt
cat tmp_all.txt tmp_all_clean.txt | sort | uniq | cmp -s tmp_all.txt
cat tmp_initial.txt template_all.txt | sort | uniq | cmp -s tmp_all_clean.txt
# make fclean
make -C push_swap fclean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_initial.txt


[ "$V" != "1" ] && [ "$V" != "2" ] && [ "$V" != "3" ] && [ "$VERBOSE" != "1" ] && [ "$VERBOSE" != "2" ] && [ "$VERBOSE" != "3" ] || echo "2. testing bonus"

# make bonus
make -C push_swap bonus > /dev/null 2> /dev/null
make -C push_swap -q bonus
make -C push_swap -q checker
find push_swap | sort > tmp_bonus.txt
# make bonus clean
make -C push_swap clean > /dev/null 2> /dev/null
find push_swap | sort > tmp_bonus_clean.txt
cat tmp_bonus.txt tmp_bonus_clean.txt | sort | uniq | cmp -s tmp_bonus.txt
cat tmp_initial.txt template_bonus.txt | sort | uniq | cmp -s tmp_bonus_clean.txt
# make fclean
make -C push_swap fclean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_initial.txt


[ "$V" != "1" ] && [ "$V" != "2" ] && [ "$V" != "3" ] && [ "$VERBOSE" != "1" ] && [ "$VERBOSE" != "2" ] && [ "$VERBOSE" != "3" ] || echo "3. testing default"

# make default
make -C push_swap > /dev/null 2> /dev/null
make -C push_swap -q
make -C push_swap -q all
make -C push_swap -q push_swap
find push_swap | sort | cmp -s tmp_all.txt
# make default clean
make -C push_swap clean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_all_clean.txt
cat tmp_all.txt tmp_all_clean.txt | sort | uniq | cmp -s tmp_all.txt
cat tmp_initial.txt template_all.txt | sort | uniq | cmp -s tmp_all_clean.txt
# make fclean
make -C push_swap fclean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_initial.txt


[ "$V" != "1" ] && [ "$V" != "2" ] && [ "$V" != "3" ] && [ "$VERBOSE" != "1" ] && [ "$VERBOSE" != "2" ] && [ "$VERBOSE" != "3" ] || echo "4. testing push_swap"

# make push_swap
find push_swap | sort | cmp -s tmp_initial.txt
make -C push_swap push_swap > /dev/null 2> /dev/null
make -C push_swap -q push_swap
find push_swap | sort > tmp_all.txt
# make push_swap clean
make -C push_swap clean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_all_clean.txt
cat tmp_all.txt tmp_all_clean.txt | sort | uniq | cmp -s tmp_all.txt
cat tmp_initial.txt template_all.txt | sort | uniq | cmp -s tmp_all_clean.txt
# make fclean
make -C push_swap fclean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_initial.txt


[ "$V" != "1" ] && [ "$V" != "2" ] && [ "$V" != "3" ] && [ "$VERBOSE" != "1" ] && [ "$VERBOSE" != "2" ] && [ "$VERBOSE" != "3" ] || echo "5. testing checker"

# make checker
make -C push_swap checker > /dev/null 2> /dev/null
make -C push_swap -q checker
find push_swap | sort > tmp_bonus.txt
# make bonus clean
make -C push_swap clean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_bonus_clean.txt
cat tmp_bonus.txt tmp_bonus_clean.txt | sort | uniq | cmp -s tmp_bonus.txt
cat tmp_initial.txt template_bonus.txt | sort | uniq | cmp -s tmp_bonus_clean.txt
# make fclean
make -C push_swap fclean > /dev/null 2> /dev/null
find push_swap | sort | cmp -s tmp_initial.txt
