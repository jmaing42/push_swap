include $(BASE_PATH)/build/common.mk

CPPFLAGS := $(addprefix -I$(BASE_PATH),$(shell xargs < $(INCS_FILE)))
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS) $(COMMON_FLAGS) -g3
LDFLAGS := $(COMMON_FLAGS)

%.o:
	$(Q2)$(CC) -MMD -MJ $@.compile_commands.part.json $(CFLAGS) -o $@ -c $<
%.a:
	$(Q2)$(AR) $(ARFLAGS) $@ $^
%.exe:
	$(Q2)$(CC) $(LDFLAGS) -o $@ $^

Makefile: deps.mk
	$(Q3)touch $@
deps.mk: $(DEPS_FILE)
	$(Q2)cat $^ | sh $(BASE_PATH)/build/srcs_to_deps.sh test.exe > $@

-include deps.mk $(shell find . -type f -name "*.d")
