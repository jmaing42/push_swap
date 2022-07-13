Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

CC := clang

default: all
.PHONY: default all test clean fclean re build dev

re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
fclean: clean
