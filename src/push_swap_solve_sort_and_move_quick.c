/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_sort_and_move_quick.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:38:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/26 03:27:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_typedef_pointer.h"
#include "ft_const_pointer.h"
#include "ft_memory.h"
#include "ft_malloc.h"
#include "ft_exit.h"

#include <stdio.h>

void	push_swap_solve_sort_and_move_quick_internal_divide(
	const t_push_swap_solve_context *c
)
{
	int *const										sorted
		= push_swap_solve_internal_sorted(c->arr, c->count);
	const t_push_swap_solve_internal_print_divide	divide_params
		= {
	{
		c->arr, sorted,
		c->x, c->y, c->z,
		c->part->x, c->part->y, c->part->z
	},
		(t_ccp)ft_const_pointer_if(c->from_right, "pa\n", "pb\n"),
		(t_ccp)ft_const_pointer_if(c->from_right, "pa\nra\n", "pb\nrb\n"),
		(t_ccp)ft_const_pointer_if(c->from_right, "rb\n", "ra\n"),
		3,
		6,
		3
	};

	printf("%*.0d sort&move %zu items - phase 1: divide - start\n",
		(int)c->count, 0, c->count);
	push_swap_solve_internal_divide_print(&divide_params);
	printf("%*.0d sort&move %zu items - phase 1: divide - end\n",
		(int)c->count, 0, c->count);
	push_swap_solve_internal_reverse(c->x, c->part->x);
	free(sorted);
}

void	push_swap_solve_sort_and_move_quick_internal_sort_only_x(
	const t_push_swap_solve_context *context
)
{
	printf("%*.0d sort&move %zu items - phase 2: sort %zu items - start\n",
		(int)context->count, 0, context->count, context->part->x);
	push_swap_solve_sort_only(
		context->self,
		context->x,
		context->part->x,
		!context->from_right);
	printf("%*.0d sort&move %zu items - phase 2: sort %zu items - end\n",
		(int)context->count, 0, context->count, context->part->x);
}

void	push_swap_solve_sort_and_move_quick_internal_rotate(
	const t_push_swap_solve_context *context
)
{
	printf("%*.0d sort&move %zu items - phase 3: rotate - start\n",
		(int)context->count, 0, context->count);
	push_swap_solve_internal_operation_rrx(
		context->part->z,
		context->part->y,
		context->from_right);
	printf("%*.0d sort&move %zu items - phase 3: rotate - end\n",
		(int)context->count, 0, context->count);
}

void	push_swap_solve_sort_and_move_quick_internal_sort_and_move_y(
	const t_push_swap_solve_context *context
)
{
	printf("%*.0d sort&move %zu items - phase 4: sort&move %zu items - start\n",
		(int)context->count, 0, context->count, context->part->y);
	push_swap_solve_sort_and_move(
		context->self,
		context->y,
		context->part->y,
		!context->from_right);
	printf("%*.0d sort&move %zu items - phase 4: sort&move %zu items - end\n",
		(int)context->count, 0, context->count, context->part->y);
}

void	push_swap_solve_sort_and_move_quick_internal_sort_and_move_z(
	const t_push_swap_solve_context *context
)
{
	printf("%*.0d sort&move %zu items - phase 5: sort&move %zu items - start\n",
		(int)context->count, 0, context->count, context->part->z);
	push_swap_solve_sort_and_move(
		context->self,
		context->z,
		context->part->z,
		context->from_right);
	printf("%*.0d sort&move %zu items - phase 5: sort&move %zu items - end\n",
		(int)context->count, 0, context->count, context->part->z);
}
