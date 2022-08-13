Q := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory)

default: all
.PHONY: default


.PHONY: all
all: test

.PHONY: clean
clean:
	rm -rf tmp_git

.PHONY: fclean
fclean: clean

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: init
init: tester

.PHONY: deinit
deinit: fclean
	rm -rf tester

.PHONY: reinit
	$(MAKE) deinit
	$(MAKE) init

.PHONY: refresh
refresh:
	@

.PHONY: test
test: tester
	$Q$(MAKE) -C ../../tmp
	$Qbash tester/tester.sh ../../tmp 1-100 20

tester:
	$Qrm -rf tmp_git
	$Qgit clone https://github.com/lmalki-h/push_swap_tester.git tmp_git --depth 1
	$Qmv tmp_git tester
