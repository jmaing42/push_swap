/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_sort_only_quick.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:38:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/25 22:18:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_typedef_pointer.h"
#include "ft_const_pointer.h"
#include "ft_memory.h"
#include "ft_malloc.h"
#include "ft_exit.h"

void	push_swap_solve_sort_only_quick_internal_divide(
	const t_push_swap_solve_context *c
)
{
	int *const										sorted
		= (int *)ft_memdup(c->arr, sizeof(int) * c->count);
	const t_push_swap_solve_internal_print_divide	divide_params
		= {
	{
		c->arr, push_swap_solve_internal_sorted(sorted, c->count),
		c->x, c->y, c->z, c->part->x, c->part->y, c->part->z
	},
		(t_ccp)ft_const_pointer_if(c->from_right, "pa\n", "pb\n"),
		(t_ccp)ft_const_pointer_if(c->from_right, "rb\n", "ra\n"),
		(t_ccp)ft_const_pointer_if(c->from_right, "pa\nra\n", "pb\nrb\n"),
		3,
		3,
		6,
		false
	};

	push_swap_solve_internal_divide_print(&divide_params);
	push_swap_solve_internal_reverse(c->x, c->part->x);
	free(sorted);
}

void	push_swap_solve_sort_only_quick_internal_sort_and_move_z(
	const t_push_swap_solve_context *context
)
{
	push_swap_solve_sort_and_move(
		context->self,
		context->z,
		context->part->z,
		!context->from_right);
}

void	push_swap_solve_sort_only_quick_internal_rotate(
	const t_push_swap_solve_context *context
)
{
}

void	push_swap_solve_sort_only_quick_internal_sort_only_y(
	const t_push_swap_solve_context *context
)
{
	//
}

void	push_swap_solve_sort_only_quick_internal_sort_and_move_x(
	const t_push_swap_solve_context *context
)
{
	//
}

