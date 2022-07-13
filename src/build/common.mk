Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

CC := clang
ARFLAGS := cr$(if $(filter 1,$(V) $(VERBOSE)),v,)

default: all
.PHONY: default all test clean fclean re build dev

re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
