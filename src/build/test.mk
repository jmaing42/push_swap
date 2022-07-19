all: test

include $(BASE_PATH)/build/compile_commands.mk

build: .cache/Makefile

.cache/Makefile:
	$Qmkdir -p .cache
	$Qsh $(BASE_PATH)/build/test_build.sh $(BASE_PATH) $(SRCS_FILE) $(INCS_FILE)

clean:
	$Qrm -rf .cache

fclean: clean
	$Qrm -f launch.part.json tasks.part.json

test: build

build:
	$Qmake COMMON_FLAGS=$(COMMON_FLAGS) -C .cache

launch.part.json:
	$Qprintf '    {\n      "type": "lldb",\n      "request": "launch",\n      "name": "Debug unit test %s",\n      "program": "%s/.cache/test.exe",\n      "cwd": "%s",\n      "preLaunchTask": "build unit test %s",\n    },\n' "$$(basename "$$(pwd)")" "$$(pwd)" "$$(pwd)" "$$(basename "$$(pwd)")" > $@

tasks.part.json:
	$Qprintf '    {\n      "label": "build unit test %s",\n      "type": "shell",\n      "command": "make build",\n      "options": {\n        "cwd": "%s",\n      },\n      "problemMatcher": ["$gcc"]\n    },\n' "$$(basename "$$(pwd)")" "$$(pwd)" > $@

dev: launch.part.json tasks.part.json
