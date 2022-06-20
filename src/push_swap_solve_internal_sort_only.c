/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_sort_only.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:06:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/21 01:49:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"
#include "ft_malloc.h"
#include "ft_exit.h"

static void	collect_last_internal_init_params(
	t_push_swap_solve_internal_print_collect *p,
	bool to_right
)
{
	p->reverse_a = false;
	p->reverse_b = true;
	p->reverse_c = true;
	if (!to_right)
	{
		p->from_a = "pa\n";
		p->from_b = "rrb\npa\n";
		p->from_c = "rra\n";
	}
	else
	{
		p->from_a = "pb\n";
		p->from_b = "rra\npb\n";
		p->from_c = "rrb\n";
	}
	p->from_a_length = 3;
	p->from_b_length = 7;
	p->from_c_length = 4;
}

#include <stdio.h>

void	push_swap_solve_internal_sort_only_collect_last(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_item				c
		= context->map[count].sort_only_collect_last;
	int *const									sorted
		= (int *)ft_memdup(arr, sizeof(int) * count);
	const size_t								xy = c.x + c.y;
	t_push_swap_solve_internal_print_collect	collect_params;

	printf("%*.0d sort only %zu (collect last): start\n", (int)count, 0, count);
	if (!sorted)
		ft_exit(EXIT_FAILURE);
	push_swap_solve_internal_sort(sorted, count);
	push_swap_solve_internal_inverse(arr, c.x);
	printf("%*.0d sort only %zu (collect last): sort x start (%zu (%d ~ %d))\n", (int)count, 0, count, c.x, sorted[0], sorted[c.x - 1]);
	push_swap_solve_internal_sort_and_move(context, arr, c.x, from_right);
	printf("%*.0d sort only %zu (collect last): sort x end (%zu (%d ~ %d))\n", (int)count, 0, count, c.x, sorted[0], sorted[c.x - 1]);
	push_swap_solve_internal_inverse(arr, c.x);
	printf("%*.0d sort only %zu (collect last): sort y start (%zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.x], sorted[xy - 1]);
	push_swap_solve_internal_sort_and_move(context, arr + c.x, c.y, from_right);
	printf("%*.0d sort only %zu (collect last): sort y end (%zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.x], sorted[xy - 1]);
	printf("%*.0d sort only %zu (collect last): sort z start (%zu (%d ~ %d))\n", (int)count, 0, count, xy, sorted[xy], sorted[count - 1]);
	push_swap_solve_internal_sort_only(context, arr + xy, c.z, from_right);
	printf("%*.0d sort only %zu (collect last): sort z end (%zu (%d ~ %d))\n", (int)count, 0, count, xy, sorted[xy], sorted[count - 1]);
	printf("%*.0d sort only %zu (collect last): rotate start to make y, x top (y: %zu (%d ~ %d), x: %zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.x], sorted[xy - 1], c.x, sorted[0], sorted[c.x - 1]);
	push_swap_solve_internal_operation_rx(c.y, c.x, from_right);
	printf("%*.0d sort only %zu (collect last): rotate end to make y, x top (y: %zu (%d ~ %d), x: %zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.x], sorted[xy - 1], c.x, sorted[0], sorted[c.x - 1]);
	collect_params.s = (t_push_swap_solve_internal){
		arr, sorted, arr, arr + c.x, arr + xy, c.x, c.y, c.z};
	collect_last_internal_init_params(&collect_params, from_right);
	push_swap_solve_internal_reverse(sorted, count);
	printf("%*.0d sort only %zu (collect last): collect start (x: %zu (%d ~ %d), y: %zu (%d ~ %d), z: %zu (%d ~ %d))\n", (int)count, 0, count, c.x, sorted[0], sorted[c.x - 1], c.y, sorted[c.x], sorted[xy - 1], c.z, sorted[xy], sorted[count - 1]);
	push_swap_solve_internal_collect_print(&collect_params);
	printf("%*.0d sort only %zu (collect last): collect start (x: %zu (%d ~ %d), y: %zu (%d ~ %d), z: %zu (%d ~ %d))\n", (int)count, 0, count, c.x, sorted[0], sorted[c.x - 1], c.y, sorted[c.x], sorted[xy - 1], c.z, sorted[xy], sorted[count - 1]);
	push_swap_solve_internal_reverse(sorted, count);
	ft_memcpy(arr, sorted, sizeof(int) * count);
	free(sorted);
	printf("%*.0d sort only %zu (collect last): end\n", (int)count, 0, count);
}

static void	divide_first_internal_init_params(
	t_push_swap_solve_internal_print_divide *p,
	bool from_right
)
{
	p->reverse = false;
	if (!from_right)
	{
		p->to_a = "pb\nrb\n";
		p->to_b = "ra\n";
		p->to_c = "pb\n";
	}
	else
	{
		p->to_a = "pa\nra\n";
		p->to_b = "rb\n";
		p->to_c = "pa\n";
	}
	p->to_a_length = 6;
	p->to_b_length = 3;
	p->to_c_length = 3;
}

void	push_swap_solve_internal_sort_only_divide_first(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_item				c
		= context->map[count].sort_only_divide_first;
	int *const									sorted
		= (int *)ft_memdup(arr, sizeof(int) * count);
	int *const									original
		= (int *)ft_memdup(arr, sizeof(int) * count);
	const size_t								xy = c.z + c.y;
	t_push_swap_solve_internal_print_divide		divide_params;

	printf("%*.0d sort only %zu (divide first): start\n", (int)count, 0, count);
	if (!sorted || !original)
		ft_exit(EXIT_FAILURE);
	push_swap_solve_internal_sort(sorted, count);
	divide_params.s = (t_push_swap_solve_internal){
		original, sorted, arr, arr + c.z, arr + xy, c.z, c.y, c.x};
	divide_first_internal_init_params(&divide_params, from_right);
	printf("%*.0d sort only %zu (divide first): divide start (x: %zu (%d ~ %d), y: %zu (%d ~ %d), z: %zu (%d ~ %d))\n", (int)count, 0, count, c.z, sorted[0], sorted[c.z - 1], c.y, sorted[c.z], sorted[xy - 1], c.z, sorted[xy], sorted[count - 1]);
	push_swap_solve_internal_divide_print(&divide_params);
	printf("%*.0d sort only %zu (divide first): divide end (x: %zu (%d ~ %d), y: %zu (%d ~ %d), z: %zu (%d ~ %d))\n", (int)count, 0, count, c.z, sorted[0], sorted[c.z - 1], c.y, sorted[c.z], sorted[xy - 1], c.z, sorted[xy], sorted[count - 1]);
	push_swap_solve_internal_reverse(arr, c.z);
	printf("%*.0d sort only %zu (divide first): sort z start (%zu (%d ~ %d))\n", (int)count, 0, count, c.x, sorted[xy], sorted[count - 1]);
	push_swap_solve_internal_sort_and_move(context, arr, c.z, !from_right);
	printf("%*.0d sort only %zu (divide first): sort z end (%zu (%d ~ %d))\n", (int)count, 0, count, c.x, sorted[xy], sorted[count - 1]);
	printf("%*.0d sort only %zu (divide first): rotate start to make y, x top (y: %zu (%d ~ %d), x: %zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.z], sorted[xy - 1], c.x, sorted[0], sorted[c.z - 1]);
	push_swap_solve_internal_operation_rrx(c.y, c.x, from_right);
	printf("%*.0d sort only %zu (divide first): rotate end to make y, x top (y: %zu (%d ~ %d), x: %zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.z], sorted[xy - 1], c.x, sorted[0], sorted[c.z - 1]);
	printf("%*.0d sort only %zu (divide first): sort y start (%zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.z], sorted[xy - 1]);
	push_swap_solve_internal_sort_only(context, arr + c.z, c.y, from_right);
	printf("%*.0d sort only %zu (divide first): sort y end (%zu (%d ~ %d))\n", (int)count, 0, count, c.y, sorted[c.z], sorted[xy - 1]);
	printf("%*.0d sort only %zu (divide first): sort x start (%zu (%d ~ %d))\n", (int)count, 0, count, c.z, sorted[0], sorted[c.z - 1]);
	push_swap_solve_internal_sort_and_move(context, arr + xy, c.x, !from_right);
	printf("%*.0d sort only %zu (divide first): sort x end (%zu (%d ~ %d))\n", (int)count, 0, count, c.z, sorted[0], sorted[c.z - 1]);
	ft_memcpy(arr, sorted, sizeof(int) * count);
	free(original);
	free(sorted);
	printf("%*.0d sort only %zu (divide first): end\n", (int)count, 0, count);
}

void	push_swap_solve_internal_sort_only(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool from_right
)
{
	t_push_swap_count_part *const	part = &context->map[count];

	if (count < 2)
		return ;
	if (count == 2)
	{
		if (arr[0] > arr[1])
			push_swap_solve_internal_operation_sx(from_right);
		return ;
	}
	if (part->sort_only_collect_last.total_moves
		< part->sort_only_divide_first.total_moves)
		push_swap_solve_internal_sort_only_collect_last(
			context,
			arr,
			count,
			from_right);
	else
		push_swap_solve_internal_sort_only_divide_first(
			context,
			arr,
			count,
			from_right);
}
