/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_sort_only.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:06:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/14 01:35:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include "ft_memory.h"
#include "ft_malloc.h"

static void	internal_collect_last(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool rtl
)
{
	const t_push_swap_count_item	c
		= context->map[count].sort_only_collect_last;
	int *const						sorted
		= (int *)ft_malloc(sizeof(int) * count);

	push_swap_solve_internal_sort(sorted, count);
	if (rtl)
		push_swap_solve_internal_reverse(sorted, count);
		// WIP
}

void	push_swap_solve_internal_sort_only(
	t_push_swap *context,
	int *arr,
	size_t count,
	bool rtl
)
{
	t_push_swap_count_part *const	part = &context->map[count];

	if (count < 2)
		return ;
	if (count == 2)
	{
		push_swap_solve_internal_operation_sx(rtl);
		return ;
	}
	if (part->sort_only_collect_last.total_moves
		< part->sort_only_divide_first.total_moves)
		internal_collect_last(context, arr, count, rtl);
	else
		internal_divide_first(context, arr, count, rtl);
}
