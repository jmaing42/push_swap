all: test
.PHONY: all clean fclean re test

all test: prelude
.PHONY: prelude
prelude:
	sh $(FT_BASE_PATH)/script/resolve.sh
	sh $(FT_BASE_PATH)/script/build_home.sh $(SRCS)
	(cd .ft/home && $(MAKE) executable.exe)

fclean:
	rm -rf .ft
