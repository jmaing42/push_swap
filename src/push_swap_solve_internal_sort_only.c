/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_sort_only.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:06:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/19 21:17:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"
#include "ft_malloc.h"

static void	collect_last_internal_init_params(
	t_push_swap_solve_internal_print_collect *p,
	bool from_right
)
{
	p->reverse_a = false;
	p->reverse_b = false;
	p->reverse_c = false;
	if (!from_right)
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

static void	collect_last(
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

	push_swap_solve_internal_sort(sorted, count);
	push_swap_solve_internal_inverse(arr, c.x);
	push_swap_solve_internal_sort_and_move(context, arr, c.x, from_right);
	push_swap_solve_internal_inverse(arr, c.x);
	push_swap_solve_internal_sort_and_move(context, arr + c.x, c.y, from_right);
	push_swap_solve_internal_sort_only(context, arr + xy, c.z, from_right);
	push_swap_solve_internal_operation_rx(c.z, c.y, from_right);
	collect_params.s = (t_push_swap_solve_internal){
		arr, sorted, arr, arr + c.x, arr + xy, c.x, c.y, c.z};
	collect_last_internal_init_params(&collect_params, from_right);
	push_swap_solve_internal_reverse(sorted, count);
	push_swap_solve_internal_collect_print(&collect_params);
	push_swap_solve_internal_reverse(sorted, count);
	ft_memcpy(arr, sorted, sizeof(int) * count);
	free(sorted);
}

static void	divide_first_internal_init_params(
	t_push_swap_solve_internal_print_divide *p,
	bool from_right
)
{
	p->reverse = false;
	if (!from_right)
	{
		p->to_a = "pb\n";
		p->to_b = "ra\n";
		p->to_c = "pb\nrb\n";
	}
	else
	{
		p->to_a = "pa\n";
		p->to_b = "rb\n";
		p->to_c = "pa\nra\n";
	}
	p->to_a_length = 3;
	p->to_b_length = 3;
	p->to_c_length = 6;
}

static void	divide_first(
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
	int *const									original
		= (int *)ft_memdup(arr, sizeof(int) * count);
	const size_t								xy = c.x + c.y;
	t_push_swap_solve_internal_print_divide		divide_params;

	push_swap_solve_internal_sort(sorted, count);
	divide_params.s = (t_push_swap_solve_internal){
		original, sorted, arr, arr + c.x, arr + xy, c.x, c.y, c.z};
	divide_first_internal_init_params(&divide_params, from_right);
	push_swap_solve_internal_sort_and_move(context, arr, c.x, !from_right);
	push_swap_solve_internal_operation_rrx(c.y, c.z, from_right);
	push_swap_solve_internal_sort_only(context, arr + c.x, c.y, from_right);
	push_swap_solve_internal_sort_and_move(context, arr + xy, c.z, !from_right);
	ft_memcpy(arr, sorted, sizeof(int) * count);
	free(original);
	free(sorted);
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
		push_swap_solve_internal_operation_sx(from_right);
		return ;
	}
	if (part->sort_only_collect_last.total_moves
		< part->sort_only_divide_first.total_moves)
		collect_last(context, arr, count, from_right);
	else
		divide_first(context, arr, count, from_right);
}
