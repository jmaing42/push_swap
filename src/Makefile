Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

# This variable will be used only if source files are not hardcoded
SRCS ?= $(shell find . -maxdepth 1 -name "*.c" | xargs)
SRCS_PUSH_SWAP := $(filter push_swap_%.c,$(SRCS))
SRCS_CHECKER := $(filter checker_%.c,$(SRCS))
SRCS_LIBFT := $(filter-out $(SRCS_PUSH_SWAP) $(SRCS_CHECKER), $(SRCS))

NAME := push_swap
NAME_CHECKER := checker
EXECUTABLE_TARGETS := $(NAME) $(NAME_CHECKER)

OTHER_USEFUL_FILES := .editorconfig .gitignore

CC := clang
CCLD := clang
AR := ar
CFLAGS := -Wall -Wextra -Werror
TMP_DIR := tmp
TMPS := $(OTHER_USEFUL_FILES) $(TMP_DIR)

all: $(NAME) $(OTHER_USEFUL_FILES)
bonus: $(NAME_CHECKER)
clean:
	$Qrm -rf $(TMPS)
fclean: clean
	$Qrm -f $(EXECUTABLE_TARGETS)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all bonus clean fclean re

.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\ntmp\n\npush_swap\nchecker\n" > .gitignore

ifeq ($(MOULINETTE_MODE),1)
CC := cc
CCLD := cc
else

CFLAGS += -std=c99 -pedantic -MMD

PROFILE ?= release
ifeq ($(PROFILE),release)
CFLAGS += -O3 -DNDEBUG
else ifeq ($(PROFILE),debug)
CFLAGS += -g3 -DDEBUG
else
$(error Bad profile)
endif

TARGET ?= production
ifeq ($(TARGET),production)
CFLAGS += -DNDEVELOPMENT
else ifeq ($(TARGET),development)
CFLAGS += -DDEVELOPMENT
else
$(error Bad target)
endif

SUFFIX := .$(TARGET).$(PROFILE)$(if $(SANITIZER),.$(SANITIZER))
CFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)
LDFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)

endif

$(TMP_DIR)/%.a:
	$Qmkdir -p $(@D)
	$Q$(AR) rcs $@ $^
$(TMP_DIR)/%.exe:
	$Qmkdir -p $(@D)
	$Q$(CCLD) $(LDFLAGS) -o $@ $^
$(TMP_DIR)/%$(SUFFIX).o: %.c
	$Qmkdir -p $(@D)
	$Q$(CC) $(CFLAGS) -o $@ -c $<

$(TMP_DIR)/libft$(SUFFIX).a: $(patsubst ./%.c,$(TMP_DIR)/%$(SUFFIX).o,$(SRCS_LIBFT))
$(TMP_DIR)/$(NAME)$(SUFFIX).exe: $(SRCS_PUSH_SWAP) $(TMP_DIR)/libft$(SUFFIX).a
$(TMP_DIR)/$(NAME_CHECKER)$(SUFFIX).exe: $(SRCS_CHECKER) $(TMP_DIR)/libft$(SUFFIX).a
$(EXECUTABLE_TARGETS): %: $(TMP_DIR)/%$(SUFFIX).exe
	$Qcp $< $@
.PHONY: $(EXECUTABLE_TARGETS)

# dependencies
ifneq ($(MOULINETTE_MODE),1)
-include $(TMP_DIR)/$(SRCS:.c=$(SUFFIX).d)
endif
