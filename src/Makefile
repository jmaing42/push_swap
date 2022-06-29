Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

CC := clang
CCLD := clang
AR := ar
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic
CPPFLAGS := $(shell find . -type d | sed "s/^/-I /" | xargs)

SRC_DIR := .
OBJ_DIR := .cache

SRCS_PUSH_SWAP := $(shell find . -name "push_swap_*.c" | xargs)
SRCS_CHECKER := $(shell find . -name "checker_*.c" | xargs)
SRCS_LIBFT := $(shell find . -name "ft_*.c" | xargs)
SRCS_LIBPS := $(shell find . -name "ps_*.c" | xargs)

NAME := push_swap
NAME_CHECKER := checker
EXECUTABLE_TARGETS := $(NAME) $(NAME_CHECKER)

all: $(NAME) $(NAME_CHECKER)
bonus: all
clean:
	$Qrm -rf $(OBJ_DIR)
fclean:
	$Q$(MAKE) clean
	$Qrm -f $(EXECUTABLE_TARGETS:=.exe)
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
.PHONY: all bonus clean fclean re

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

$(OBJ_DIR)/%.a:
	$Qmkdir -p $(@D)
	$Q$(AR) rcs $@ $^
$(OBJ_DIR)/%.exe:
	$Qmkdir -p $(@D)
	$Q$(CCLD) $(LDFLAGS) -o $@ $^
$(OBJ_DIR)/%$(SUFFIX).o: %.c
	$Qmkdir -p $(@D)
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -o $@ -c $<

$(OBJ_DIR)/libft$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBFT))
$(OBJ_DIR)/libps$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBPS))
$(OBJ_DIR)/$(NAME)$(SUFFIX).exe: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_PUSH_SWAP)) $(OBJ_DIR)/libft$(SUFFIX).a
$(OBJ_DIR)/$(NAME_CHECKER)$(SUFFIX).exe: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_CHECKER)) $(OBJ_DIR)/libft$(SUFFIX).a
$(EXECUTABLE_TARGETS): %: $(OBJ_DIR)/%$(SUFFIX).exe
	$Qcp $< $@.exe
.PHONY: $(EXECUTABLE_TARGETS)

# dependencies
-include $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).d,$(SRCS))
