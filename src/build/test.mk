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

build:
	$Qmake COMMON_FLAGS=$(COMMON_FLAGS) -C .cache test.exe
