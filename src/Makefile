Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

SRC_DIR := .
OBJ_DIR := .cache

# This variable is used only if the list of source file is not hardcoded.
SRCS ?= $(shell cd $(SRC_DIR) && find . -maxdepth 1 -name "*.c" | xargs)
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

all: $(NAME) $(OTHER_USEFUL_FILES)
bonus: $(NAME_CHECKER) $(OTHER_USEFUL_FILES)
clean:
	$Qrm -rf $(OBJ_DIR)
	$Qrm -f $(OTHER_USEFUL_FILES)
fclean:
	$Q$(MAKE) clean
	$Qrm -f $(EXECUTABLE_TARGETS)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all bonus clean fclean re

.editorconfig:
	$Qprintf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig
.gitignore:
	$Qprintf ".*\n$(OBJ_DIR)\n\n$$(echo "$(EXECUTABLE_TARGETS)" | xargs -n 1 echo)\n" > $@

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

$(OBJ_DIR)/%.a:
	$Qmkdir -p $(@D)
	$Q$(AR) rcs $@ $^
$(OBJ_DIR)/%.exe:
	$Qmkdir -p $(@D)
	$Q$(CCLD) $(LDFLAGS) -o $@ $^
$(OBJ_DIR)/%$(SUFFIX).o: %.c
	$Qmkdir -p $(@D)
	$Q$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)/libft$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBFT))
$(OBJ_DIR)/$(NAME)$(SUFFIX).exe: $(SRCS_PUSH_SWAP) $(OBJ_DIR)/libft$(SUFFIX).a
$(OBJ_DIR)/$(NAME_CHECKER)$(SUFFIX).exe: $(SRCS_CHECKER) $(OBJ_DIR)/libft$(SUFFIX).a
$(EXECUTABLE_TARGETS): %: $(OBJ_DIR)/%$(SUFFIX).exe
	$Qcp $< $@
.PHONY: $(EXECUTABLE_TARGETS)

# dependencies
ifneq ($(MOULINETTE_MODE),1)
-include $(OBJ_DIR)/$(SRCS:.c=$(SUFFIX).d)
endif
