Q3 := $(if $(filter 3,$(V) $(VERBOSE)),,@)
Q2 := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
Q1 := $(if $(filter 1 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh build/script/nproc.sh) NO_ADDITIONAL_J=1)

CC := clang
AR := ar
ARFLAGS := cr$(if $(filter 3,$(V) $(VERBOSE)),v,)
CPPFLAGS := $(shell find . -type d -mindepth 1 | grep -v /test/ | sed "s/^/-I /" | xargs)
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS)

SRC_DIR := .
OBJ_DIR := .cache

SRCS_PUSH_SWAP := $(shell find . -name "push_swap_*.c" | grep -v /test/ | xargs)
SRCS_CHECKER := $(shell find . -name "checker_*.c" | grep -v /test/ | xargs)
SRCS_LIBFT := $(shell find . -name "ft_*.c" | grep -v /test/ | xargs)
SRCS_LIBFTO := $(shell find . -name "fto_*.c" | grep -v /test/ | xargs)
SRCS_LIBPS := $(shell find . -name "ps_*.c" | grep -v /test/ | xargs)

NAME_PUSH_SWAP := push_swap
NAME_CHECKER := checker
EXECUTABLE_TARGETS := $(NAME_PUSH_SWAP) $(NAME_CHECKER)

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)
bonus: all
clean:
	$(Q1)rm -rf $(OBJ_DIR)
fclean:
	$(Q3)$(MAKE) clean
	$(Q1)rm -f $(EXECUTABLE_TARGETS:=.exe)
re:
	$(Q3)$(MAKE) NO_ADDITIONAL_J=1 fclean
	$(Q3)$(MAKE) NO_ADDITIONAL_J=1 all
test:
	$(Q1)find . -type d -mindepth 1 -name "test" | xargs -L1 -I {} $(MAKE) -C {} test
.PHONY: all bonus clean fclean re test

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
	$(Q3)mkdir -p $(@D)
	$(Q2)$(AR) $(ARFLAGS) $@ $^
$(OBJ_DIR)/%.exe:
	$(Q3)mkdir -p $(@D)
	$(Q2)$(CC) $(LDFLAGS) -o $@ $^
$(OBJ_DIR)/%$(SUFFIX).o: %.c
	$(Q3)mkdir -p $(@D)
	$(Q2)$(CC) $(CFLAGS) -MJ $@.compile_commands.part.json -MMD -o $@ -c $<

$(OBJ_DIR)/libft$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBFT))
$(OBJ_DIR)/libfto$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBFTO))
$(OBJ_DIR)/libps$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBPS))
$(OBJ_DIR)/$(NAME_PUSH_SWAP)$(SUFFIX).exe: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_PUSH_SWAP)) $(OBJ_DIR)/libft$(SUFFIX).a $(OBJ_DIR)/libfto$(SUFFIX).a $(OBJ_DIR)/libps$(SUFFIX).a
$(OBJ_DIR)/$(NAME_CHECKER)$(SUFFIX).exe: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_CHECKER)) $(OBJ_DIR)/libft$(SUFFIX).a $(OBJ_DIR)/libfto$(SUFFIX).a $(OBJ_DIR)/libps$(SUFFIX).a
$(EXECUTABLE_TARGETS): %: $(OBJ_DIR)/%$(SUFFIX).exe
	$(Q1)cp $< $@.exe
.PHONY: $(EXECUTABLE_TARGETS)

# dependencies
-include $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).d,$(SRCS))
