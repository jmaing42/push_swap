BASE_PATH := ../../../../..

INCS := \
	../../.. \
	../../../../stream \
	../../../../../ft/types \

OBJS := main.o ps_strategy_util_try_all_permutations.o

include $(BASE_PATH)/build/test.mk

test: test.exe
	$Qsh test.sh

main.o: main.c
ps_strategy_util_try_all_permutations.o: ../../ps_strategy_util_try_all_permutations.c

test.exe: $(OBJS)
