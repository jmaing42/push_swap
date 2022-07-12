.PHONY: compile_commands.json
compile_commands.json:
	$Q$(MAKE) -k build ; (printf "[" && find . -name "*.part.json" | xargs cat && printf "]") > $@
.PHONY: dev
dev: compile_commands.json
