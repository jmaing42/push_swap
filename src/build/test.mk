include $(BASE_PATH)/build/common.mk

all: test

include $(BASE_PATH)/build/compile_commands.mk

build: .cache/Makefile

.cache/Makefile:
	$Qmkdir -p .cache
	$Qsh $(BASE_PATH)/build/test_build.sh $(BASE_PATH) $(SRCS_FILE) $(INCS_FILE)

clean:
	$Qrm -rf .cache

fclean: clean

test: build
	$Qsh test.sh

build:
	$Qmake -C .cache test.exe
