/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_sort_and_move.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:34:18 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/20 02:29:08 by Juyeong Maing    ###   ########.fr       */
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
	p->reverse_a = true;
	p->reverse_b = true;
	p->reverse_c = false;
	if (!to_right)
	{
		p->from_a = "rrb\n";
		p->from_b = "rra\npb\n";
		p->from_c = "pb\n";
	}
	else
	{
		p->from_a = "rra\n";
		p->from_b = "rrb\npa\n";
		p->from_c = "pa\n";
	}
	p->from_a_length = 4;
	p->from_b_length = 7;
	p->from_c_length = 3;
}

#include <stdio.h>

void	push_swap_solve_internal_sort_and_move_collect_last(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_item				c
		= context->map[count].sort_and_move_collect_last;
	int *const									sorted
		= (int *)ft_memdup(arr, sizeof(int) * count);
	const size_t								xy = c.x + c.y;
	t_push_swap_solve_internal_print_collect	collect_params;

	printf("%*.0d sort+move %zu (collect last): start\n", (int)count, 0, count);
	if (!sorted)
		ft_exit(EXIT_FAILURE);
	push_swap_solve_internal_sort(sorted, count);
	push_swap_solve_internal_sort_and_move(context, arr, c.x, from_right);
	push_swap_solve_internal_sort_only(context, arr + c.x, c.y, from_right);
	push_swap_solve_internal_operation_rx(c.y, c.x, from_right);
	push_swap_solve_internal_inverse(arr + xy, c.z);
	push_swap_solve_internal_sort_only(context, arr + xy, c.z, from_right);
	push_swap_solve_internal_inverse(arr + xy, c.z);
	collect_params.s = (t_push_swap_solve_internal){
		arr, sorted, arr, arr + c.x, arr + xy, c.x, c.y, c.z};
	collect_last_internal_init_params(&collect_params, from_right);
	push_swap_solve_internal_reverse(sorted, count);
	push_swap_solve_internal_collect_print(&collect_params);
	push_swap_solve_internal_reverse(sorted, count);
	ft_memcpy(arr, sorted, sizeof(int) * count);
	free(sorted);
	printf("%*.0d sort+move %zu (collect last): end\n", (int)count, 0, count);
}

static void	divide_first_internal_init_params(
	t_push_swap_solve_internal_print_divide *p,
	bool from_right
)
{
	p->reverse = false;
	if (!from_right)
	{
		p->to_a = "ra\n";
		p->to_b = "pb\nrb\n";
		p->to_c = "pb\n";
	}
	else
	{
		p->to_a = "rb\n";
		p->to_b = "pa\nra\n";
		p->to_c = "pa\n";
	}
	p->to_a_length = 3;
	p->to_b_length = 6;
	p->to_c_length = 3;
}

void	push_swap_solve_internal_sort_and_move_divide_first(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_item				c
		= context->map[count].sort_and_move_divide_first;
	int *const									sorted
		= (int *)ft_memdup(arr, sizeof(int) * count);
	int *const									original
		= (int *)ft_memdup(arr, sizeof(int) * count);
	const size_t								xy = c.x + c.y;
	t_push_swap_solve_internal_print_divide		divide_params;

	printf("%*.0d sort+move %zu (divide first): start\n", (int)count, 0, count);
	if (!sorted || !original)
		ft_exit(EXIT_FAILURE);
	push_swap_solve_internal_sort(sorted, count);
	divide_params.s = (t_push_swap_solve_internal){
		original, sorted, arr, arr + c.x, arr + xy, c.x, c.y, c.z};
	divide_first_internal_init_params(&divide_params, from_right);
	push_swap_solve_internal_divide_print(&divide_params);
	push_swap_solve_internal_reverse(arr, c.z);
	push_swap_solve_internal_sort_only(context, arr + xy, c.z, !from_right);
	push_swap_solve_internal_operation_rrx(c.x, c.z, from_right);
	push_swap_solve_internal_sort_only(context, arr + c.x, c.y, !from_right);
	push_swap_solve_internal_sort_and_move(context, arr, c.x, from_right);
	ft_memcpy(arr, sorted, sizeof(int) * count);
	free(original);
	free(sorted);
	printf("%*.0d sort+move %zu (divide first): end\n", (int)count, 0, count);
}

void	push_swap_solve_internal_sort_and_move(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool from_right
)
{
	t_push_swap_count_part *const	part = &context->map[count];

	if (!count)
		return ;
	if (count <= 2)
	{
		push_swap_solve_internal_operation_px(0, count, from_right);
		if (arr[0] < arr[1])
			push_swap_solve_internal_operation_sx(!from_right);
		return ;
	}
	if (part->sort_and_move_collect_last.total_moves
		< part->sort_and_move_divide_first.total_moves)
		push_swap_solve_internal_sort_and_move_collect_last(
			context,
			arr,
			count,
			from_right);
	else
		push_swap_solve_internal_sort_and_move_divide_first(
			context,
			arr,
			count,
			from_right);
}
