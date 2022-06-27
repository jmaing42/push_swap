Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
CASES := $(sort $(wildcard case*))
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)
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
