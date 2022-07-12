BASE_PATH := ../../../..

INCS := \
	../.. \
	$(BASE_PATH)/ps/stream \
	$(BASE_PATH)/ft/types \

OBJS := main.o ps_hardcoded_find_index.o

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/test.mk

test: test.exe
	$Qsh test.sh

main.o: main.c
ps_hardcoded_find_index.o: ../../ps_hardcoded_find_index.c
test.exe: $(OBJS)
