/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_sort_only.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:53:35 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/04 22:28:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_io.h"
#include "ft_memory.h"
#include "ft_malloc.h"

static void	collect_last(
	t_push_swap *ctx,
	int *a,
	size_t c,
	int type
)
{
	const t_push_swap_count_item	i = ctx->map[c].sort_and_move_collect_last;
	const int *const				sorted = ft_memdup(a, sizeof(int) * )

	push_swap_solve_internal_sort_and_move(ctx, a, i.x,
		push_swap_solve_internal_type_inverse_order(type));
	push_swap_solve_internal_sort_and_move(ctx, &a[i.x], i.y, type);
	push_swap_solve_internal_sort_only(ctx, &a[i.x + i.y], i.z, type);
	push_swap_solve_internal_operation_rx(i.z, i.y,
		push_swap_solve_internal_type_is_reverse_direction(type));
	push_swap_solve_internal_collect((t_push_swap_solve_internal){
		self->numbers,
		i.z,
		z_offset,
		i.x,
		0,
		i.y,
		y_offset,
		false,
		reverse_order
	});
}

void	push_swap_solve_internal_sort_only(
	t_push_swap *context,
	int *a,
	size_t count,
	int type
)
{
	const t_push_swap_count_part	*c = &context->map[count];

	if (!count)
		return ;
	else if (count == 1)
		return ;
	else if (count == 2)
	{
		if (a[0] < a[1] == push_swap_solve_internal_type_is_reverse_order(type))
			push_swap_solve_internal_operation_sx(
				push_swap_solve_internal_type_is_reverse_direction(type));
		return ;
	}
	else if (c->sort_only_collect_last.total_moves
		< c->sort_only_divide_first.total_moves)
		collect_last(context, a, count, type);
	else
		divide_first(context, a, count, type);
}
