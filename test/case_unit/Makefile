Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
CASES := $(sort $(wildcard test_*))
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)
RULES := all clean fclean refresh test
RULES_NOP := init deinit reinit refresh

.PHONY: $(RULES) $(RULES_NOP) re
define build_common_rule
$1:
	$Q$(foreach t,$(CASES),$(MAKE) -C $t $1 && )true
endef
$(foreach r, \
	$(RULES), \
	$(eval $(call \
		build_common_rule, \
		$r \
	)) \
)

$(RULES_NOP):

re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
