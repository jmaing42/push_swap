test.exe: main.o
main.o: main.c
test.exe: ps_strategy_util_try_all_permutations.o
ps_strategy_util_try_all_permutations.o: ../../ps_strategy_util_try_all_permutations.c
