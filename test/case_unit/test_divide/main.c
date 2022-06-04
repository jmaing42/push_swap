/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:08:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 16:58:33 by Juyeong Maing    ###   ########.fr       */
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
	while (scanf("%d", &arr[i]) == 1)
		i++;
	t->all = arr;
	t->all_sorted = arr_sorted;
	t->count_a = i / 3;
	t->count_b = (i - t->count_a) / 2;
	t->count_c = i - t->count_a - t->count_b;
	t->part_a = arr_result;
	t->part_b = &arr_result[t->count_a];
	t->part_c = &arr_result[t->count_a + t->count_b];
	memcpy(arr_sorted, arr, sizeof(int) * i);
	push_swap_solve_internal_sort(arr_sorted, i, false);
	*out_length = i;
}

static void	init_t(t_push_swap_solve_internal_print_divide *t)
{
	t->to_a = "ra\n";
	t->to_a_length = 3;
	t->to_b = "pb\n";
	t->to_b_length = 3;
	t->to_c = "pb\nrb\n";
	t->to_c_length = 6;
}

int	main(void)
{
	int										arr[MAX_LENGTH];
	int										arr_sorted[MAX_LENGTH];
	int										arr_result[MAX_LENGTH];
	size_t									i;
	t_push_swap_solve_internal_print_divide	t;

	init_s((int *[3]){arr, arr_sorted, arr_result}, &t.s, &i);
	init_t(&t);
	push_swap_solve_internal_divide_print(&t);
	puts("=====\n  a\n=====");
	i = -1;
	while (++i < t.s.count_a)
		printf("%d\n", arr_result[i]);
	puts("=====\n  b\n=====");
	i = -1;
	while (++i < t.s.count_b)
		printf("%d\n", arr_result[t.s.count_a + i]);
	puts("=====\n  c\n=====");
	i = -1;
	while (++i < t.s.count_c)
		printf("%d\n", arr_result[t.s.count_a + t.s.count_b + i]);
}
