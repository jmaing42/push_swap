/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:10:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 17:43:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../../../src/push_swap_solve_internal.h"

#define MAX_LENGTH 1024

static void	init_s(
	int **a,
	t_push_swap_solve_internal *t,
	size_t *out_length
)
{
	int *const	arr = a[0];
	int *const	arr_sorted = a[1];
	int *const	arr_result = a[2];
	size_t		i;

	i = 0;
	while (scanf("%d", &arr_result[i]) == 1)
		i++;
	t->all = arr;
	t->all_sorted = arr_sorted;
	t->count_a = i / 3;
	t->count_b = (i - t->count_a) / 2;
	t->count_c = i - t->count_a - t->count_b;
	t->part_a = arr_result;
	t->part_b = &arr_result[t->count_a];
	t->part_c = &arr_result[t->count_a + t->count_b];
	push_swap_solve_internal_sort(t->part_a, t->count_a, false);
	push_swap_solve_internal_sort(t->part_b, t->count_b, false);
	push_swap_solve_internal_sort(t->part_c, t->count_c, true);
	*out_length = i;
}

static void	init_t(t_push_swap_solve_internal_print_collect *t)
{
	t->from_a = "rra\n";
	t->from_a_length = 4;
	t->from_b = "pa\n";
	t->from_b_length = 3;
	t->from_c = "rrb\npa\n";
	t->from_c_length = 7;
	t->reverse_a = false;
	t->reverse_b = false;
	t->reverse_c = true;
}

int	main(int argc, char **argv)
{
	int											arr[MAX_LENGTH];
	int											arr_sorted[MAX_LENGTH];
	int											arr_result[MAX_LENGTH];
	size_t										i;
	t_push_swap_solve_internal_print_collect	t;

	if (argc == 2)
		freopen(argv[2], "r", stdin);
	init_s((int *[3]){arr, arr_sorted, arr_result}, &t.s, &i);
	init_t(&t);
	push_swap_solve_internal_collect_print(&t);
	i = -1;
	while (++i < t.s.count_a + t.s.count_b + t.s.count_c)
		printf("%d\n", arr[i]);
}
