BASE_PATH := ../../../../..

INCS := \
	../../.. \
	../../../../stream \
	../../../../../ft/types \

include $(BASE_PATH)/build/test.mk

test: test.exe
	$Qsh test.sh

Makefile: .cache/deps.mk
	$Qtouch $@
.cache/deps.mk: srcs.txt
	$Qmkdir -p .cache
	$Qsh $(BASE_PATH)/build/srcs_to_deps.sh test.exe < $< > $@

clean:
	$Qrm -rf .cache
fclean:
	$Qrm -f test.exe

-include .cache/deps.mk $(shell find .cache -name "*.d")
