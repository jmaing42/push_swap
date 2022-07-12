Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)

all: test
clean:
	$Qrm -rf ./tmp compile_commands.json
	$Q$(MAKE) -C src fclean
	@printf "\033[0m"
fclean: clean deinit
re:
	$Q$(MAKE) fclean
	$Q$(MAKE) all
test:
	$Qfind src -type d -name "test" | xargs $(MAKE) -C
	@echo "Some test might need manual review"
publish_without_test:
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$Qrm -rf tmp
	$Qmkdir tmp
	$Qsh copy_src_to_tmp_flatten.sh
	$Qcd tmp && sh ../template.sh > Makefile
	$Q(cd tmp && git init && git add . && git commit -m "Initial commit" && git push "$(GIT_REMOTE_URL)" HEAD:master) || (echo "Failed to publish" && false)
	$Qrm -rf tmp
	$Qgit push "$(GIT_REMOTE_URL)" HEAD:source || echo "Failed to push HEAD to source"
publish:
	$Q$(MAKE) test
	$Q$(MAKE) publish_without_test
.PHONY: all clean fclean re init deinit reinit refresh test publish publish_without_test

.PHONY: compile_commands.json
compile_commands.json:
	$Q$(MAKE) -C src -k PROFILE=debug TARGET=development SANITIZER=address all ; (printf "[" && find src/.cache -name "*.json" | xargs cat && printf "]") > $@
.PHONY: dev
dev: compile_commands.json
