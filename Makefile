Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

all: test
clean:
	$Qrm -rf ./tmp
	$Q$(MAKE) -C src fclean
	$Q$(MAKE) -C test clean
	@printf "\033[0m"
fclean: clean deinit
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
init:
	$Q$(MAKE) -C test init
deinit:
	$Q$(MAKE) -C test deinit
reinit:
	$Q$(MAKE) -C test reinit
refresh:
	$Q$(MAKE) -C test refresh
test:
	$Q$(MAKE) -C test test
	@echo "Some test might need manual review"
publish_without_test:
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qcp src/*.c src/*.h tmp
	$Q(printf ".POSIX:\n# this file is generated, do not modify directly\n\nOBJS_PUSH_SWAP = %s\nOBJS_CHECKER = %s\nOBJS_LIBFT = %s\n\n" "$$(cd src && find . -maxdepth 1 -name "push_swap_*.c" | cut -c 3- | sed s/\\.c\$$/.o/ | xargs)" "$$(cd src && find . -maxdepth 1 -name "checker_*.c" | cut -c 3- | sed s/\\.c\$$/.o/ | xargs)" "$$(cd src && find . -maxdepth 1 -name "ft_*.c" | cut -c 3- | sed s/\\.c\$$/.o/ | xargs)" && cat template.mk && (cd src && find . -maxdepth 1 -name "*.c" | cut -c 3- | xargs gcc -MM -MG)) > tmp/Makefile
	$Q(cd tmp && git init && git add . && git commit -m "Initial commit" && git push "$(GIT_REMOTE_URL)" HEAD:master) || (echo "Failed to publish" && false)
	$Qrm -rf tmp
	$Qgit push "$(GIT_REMOTE_URL)" HEAD:source || echo "Failed to push HEAD to source"
publish:
	$Q$(MAKE) test
	$Q$(MAKE) publish_without_test
.PHONY: all clean fclean re init deinit reinit refresh test publish publish_without_test
