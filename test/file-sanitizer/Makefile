Q := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory)

default: all
.PHONY: default


.PHONY: all
all: test

.PHONY: clean
clean:
	rm -rf push_swap

.PHONY: fclean
fclean: clean

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: init
init:

.PHONY: deinit
deinit: fclean

.PHONY: reinit
	$(MAKE) deinit
	$(MAKE) init

.PHONY: refresh
refresh:
	$Qrm -rf push_swap
	$Qcp -r ../../tmp push_swap
	$Qrm -rf push_swap/.git

.PHONY: test
test: refresh
	$Qsh test.sh
