/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_sort_only.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:38:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/25 21:32:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"
#include "ft_malloc.h"
#include "ft_exit.h"

static void	quick(
	t_push_swap *self,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_item *const	item
		= &self->map[count].sort_only_quick;
	const t_push_swap_solve_context		context = {
		self,
		arr,
		count,
		item,
		(int *)ft_malloc(sizeof(int) * item->x),
		(int *)ft_malloc(sizeof(int) * item->y),
		(int *)ft_malloc(sizeof(int) * item->z),
		from_right
	};

	push_swap_solve_sort_only_quick_internal_divide(&context);
	push_swap_solve_sort_only_quick_internal_sort_and_move_z(&context);
	push_swap_solve_sort_only_quick_internal_rotate(&context);
	push_swap_solve_sort_only_quick_internal_sort_only_y(&context);
	push_swap_solve_sort_only_quick_internal_sort_and_move_x(&context);
	free(context.x);
	free(context.y);
	free(context.z);
}

static void	merge(
	t_push_swap *self,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_item *const	item
		= &self->map[count].sort_only_merge;
	const t_push_swap_solve_context		context = {
		self,
		arr,
		count,
		item,
		(int *)ft_malloc(sizeof(int) * item->x),
		(int *)ft_malloc(sizeof(int) * item->y),
		(int *)ft_malloc(sizeof(int) * item->z),
		from_right
	};

	push_swap_solve_sort_only_merge_internal_sort_and_move_x(&context);
	push_swap_solve_sort_only_merge_internal_sort_and_move_y(&context);
	push_swap_solve_sort_only_merge_internal_sort_only_z(&context);
	push_swap_solve_sort_only_merge_internal_rotate(&context);
	push_swap_solve_sort_only_merge_internal_collect(&context);
	free(context.x);
	free(context.y);
	free(context.z);
}

void	push_swap_solve_sort_only(
	t_push_swap *self,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_part *const	part = &self->map[count];

	if (count <= 2)
	{
		if (count == 2 && arr[0] > arr[1])
			push_swap_solve_internal_operation_sx(from_right);
		return ;
	}
	if (part->sort_only_quick.total_moves
		> part->sort_only_merge.total_moves)
		quick(self, arr, count, from_right);
	else
		merge(self, arr, count, from_right);
}
