main.exe: main.c ../src/ps/strategy/ps_strategy_bake.c $(wildcard ../src/ps/strategy/ps_strategy_count_*.c) ../src/ft/primitive/ft_primitive_size_t.c
	clang -g3 -fsanitize=address -I ../src/ft/primitive -o $@ $^
