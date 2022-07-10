/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_sort_and_move.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:38:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 16:49:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_pointer.h"
#include "ft_memory.h"
#include "ft_malloc.h"
#include "ft_exit.h"

#include "ps_hardcoded.h"

static void	quick(
	t_push_swap *self,
	int *arr,
	size_t count,
	bool from_right
)
{
	const t_push_swap_count_item *const	item
		= &self->map[count].sort_and_move_quick;
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

	push_swap_solve_sort_and_move_quick_internal_divide(&context);
	push_swap_solve_sort_and_move_quick_internal_sort_only_z(&context);
	push_swap_solve_sort_and_move_quick_internal_rotate(&context);
	push_swap_solve_sort_and_move_quick_internal_sort_only_y(&context);
	push_swap_solve_sort_and_move_quick_internal_sort_and_move_x(&context);
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
		= &self->map[count].sort_and_move_merge;
	const size_t						offset_z = item->x + item->y;
	const t_push_swap_solve_context		context = {
		self,
		arr,
		count,
		item,
		(int *)ft_nonnull(ft_memdup(arr, sizeof(int) * item->x)),
		(int *)ft_nonnull(ft_memdup(arr + item->x, sizeof(int) * item->y)),
		(int *)ft_nonnull(ft_memdup(arr + offset_z, sizeof(int) * item->z)),
		from_right
	};

	push_swap_solve_sort_and_move_merge_internal_sort_and_move_x(&context);
	push_swap_solve_sort_and_move_merge_internal_sort_only_y(&context);
	push_swap_solve_sort_and_move_merge_internal_rotate(&context);
	push_swap_solve_sort_and_move_merge_internal_sort_only_z(&context);
	push_swap_solve_sort_and_move_merge_internal_collect(&context);
	free(context.x);
	free(context.y);
	free(context.z);
}

void	push_swap_solve_sort_and_move(
	t_push_swap *self,
	int *arr,
	size_t count,
	bool from_right
)
{
	const size_t	already_sorted_count
		= push_swap_solve_internal_reverse_sorted_count_front(arr, count);
	const size_t	count_to_sort = count - already_sorted_count;

	push_swap_solve_internal_operation_px(0, already_sorted_count, from_right);
	if (count_to_sort <= 8)
	{
		if (!count)
			return ;
		ps_hardcoded_execute(
			ps_hardcoded_find_index(arr, count),
			from_right,
			ps_hardcoded_tot(count));
		return ;
	}
	if (self->map[count_to_sort].sort_and_move_quick.total_moves
		< self->map[count_to_sort].sort_and_move_merge.total_moves)
		quick(self, &arr[already_sorted_count], count_to_sort, from_right);
	else
		merge(self, &arr[already_sorted_count], count_to_sort, from_right);
}
