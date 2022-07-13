include $(BASE_PATH)/build/common.mk

CPPFLAGS := $(addprefix -I$(BASE_PATH),$(shell xargs < $(INCS_FILE)))
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS) $(COMMON_FLAGS) -g3
LDFLAGS := $(COMMON_FLAGS)

%.o:
	$Q$(CC) -MMD -MJ $@.part.json $(CFLAGS) -o $@ -c $<
%.a:
	$Q$(AR) $(ARFLAGS) $@ $^
%.exe:
	$Q$(CC) $(LDFLAGS) -o $@ $^

Makefile: deps.mk
	$Qtouch $@
deps.mk: $(DEPS_FILE)
	$Qcat $^ | sh $(BASE_PATH)/build/srcs_to_deps.sh test.exe > $@

-include deps.mk $(shell find . -type f -name "*.d")
