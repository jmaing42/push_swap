Q := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
CASES := $(shell find . -mindepth 1 -maxdepth 1 -type d)
MAKE := make $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory)
RULES := all clean fclean re init deinit reinit refresh test

NPROC := $(shell sh nproc.sh)

.PHONY: $(RULES)
define build_common_rule
$1:
	$Q$(foreach t,$(CASES),$(MAKE) -C $t -j $(NPROC) $1 && )true
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)
