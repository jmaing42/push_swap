.PHONY: compile_commands.json
compile_commands.json:
	$Q$(MAKE) -k build ; (printf "[" && find . -name "*.part.json" | xargs cat && printf "]") > $@

.PHONY: clean_compile_commands.json
clean_compile_commands.json:
	$Qfind . -name "*.part.json" | xargs rm

.PHONY: fclean_compile_commands.json
fclean_compile_commands.json: clean_compile_commands.json
	$Qrm -rf compile_commands.json

dev: compile_commands.json
clean: clean_compile_commands.json
fclean: fclean_compile_commands.json
