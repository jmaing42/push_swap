/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_sort_and_move_merge.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:38:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/26 21:37:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_typedef_pointer.h"
#include "ft_const_pointer.h"
#include "ft_memory.h"
#include "ft_malloc.h"
#include "ft_exit.h"

void	push_swap_solve_sort_and_move_merge_internal_sort_and_move_x(
	const t_push_swap_solve_context *context
)
{
	push_swap_solve_sort_and_move(
		context->self,
		context->x,
		context->part->x,
		context->from_right);
}

void	push_swap_solve_sort_and_move_merge_internal_sort_only_y(
	const t_push_swap_solve_context *context
)
{
	push_swap_solve_sort_only(
		context->self,
		context->y,
		context->part->y,
		context->from_right);
}

void	push_swap_solve_sort_and_move_merge_internal_rotate(
	const t_push_swap_solve_context *context
)
{
	push_swap_solve_internal_operation_rx(
		context->part->y,
		context->part->x,
		context->from_right);
}

void	push_swap_solve_sort_and_move_merge_internal_sort_only_z(
	const t_push_swap_solve_context *context
)
{
	push_swap_solve_internal_inverse(context->z, context->part->z);
	push_swap_solve_sort_only(
		context->self,
		context->z,
		context->part->z,
		context->from_right);
	push_swap_solve_internal_inverse(context->z, context->part->z);
}

void	push_swap_solve_sort_and_move_merge_internal_collect(
	const t_push_swap_solve_context *c
)
{
	int *const										sorted
		= push_swap_solve_internal_sorted(c->arr, c->count);
	const t_push_swap_solve_internal_print_collect	collect_params
		= {
	{
		c->arr, sorted,
		c->x, c->y, c->z,
		c->part->x, c->part->y, c->part->z
	},
		(t_ccp)ft_const_pointer_if(c->from_right, "rra\n", "rrb\n"),
		(t_ccp)ft_const_pointer_if(c->from_right, "rrb\npa\n", "rra\npb\n"),
		(t_ccp)ft_const_pointer_if(c->from_right, "pa\n", "pb\n"),
		4, 7, 3,
		true, false, false
	};

	push_swap_solve_internal_sort(c->x, c->part->x);
	push_swap_solve_internal_sort(c->y, c->part->y);
	push_swap_solve_internal_reverse(c->y, c->part->y);
	push_swap_solve_internal_sort(c->z, c->part->z);
	push_swap_solve_internal_reverse(c->z, c->part->z);
	push_swap_solve_internal_collect_print(&collect_params);
	free(sorted);
}
