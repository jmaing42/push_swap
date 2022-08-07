Q := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory)
RULES := clean fclean re init deinit reinit refresh test

all: test
.PHONY: all $(RULES)

$(RULES):
	$Qfind . -mindepth 1 -maxdepth 1 -type d | xargs -L1 -I {} $(MAKE) -C {} $@
