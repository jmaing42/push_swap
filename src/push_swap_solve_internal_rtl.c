/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_rtl.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 16:30:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"
#include "ft_malloc.h"

void	push_swap_solve_internal_rtl_collect_last(
	t_push_swap *self,
	size_t offset,
	size_t count,
	bool reverse_order
)
{
	const t_push_swap_count_item	c
		= self->map[count].sort_and_move_collect_last;
	const size_t					y_offset = c.x;
	const size_t					z_offset = y_offset + c.y;

	push_swap_solve_internal_rtl(self, offset, c.x, reverse_order);
	push_swap_solve_internal_rtr(self, offset + y_offset, c.y, reverse_order);
	rx(c.y, c.x);
	push_swap_solve_internal_rtr(self, offset + z_offset, c.z, !reverse_order);
	push_swap_solve_internal_collect((t_push_swap_solve_internal_collect){
		self->numbers,
		c.x,
		0,
		c.z,
		z_offset,
		c.y,
		y_offset,
		true,
		reverse_order
	});
}

void	push_swap_solve_internal_rtl_divide_first(
	t_push_swap *self,
	size_t offset,
	size_t count,
	bool reverse_order
)
{
	const t_push_swap_count_item	c
		= self->map[count].sort_and_move_collect_last;
	const size_t					y_offset = c.x;
	const size_t					z_offset = y_offset + c.y;
	int *const						s
		= (int *)ft_malloc(sizeof(int) * count);

	ft_memcpy(s, &self->numbers[offset], sizeof(int) * count);
	push_swap_solve_internal_sort(s, count, reverse_order);
	push_swap_sort_internal_divide((t_push_swap_sort_internal_divide){
		&self->numbers[offset],
		(t_push_swap_internal_part){c.z, s[0], s[c.z - 1]},
		(t_push_swap_internal_part){c.x, s[count - c.x], s[count - 1]},
		(t_push_swap_internal_part){c.y, s[c.z], s[c.z + c.y - 1]},
		false,
		reverse_order
	});
	push_swap_solve_internal_ltl(self, offset, c.x, reverse_order);
	rrx(c.z, c.y);
	push_swap_solve_internal_ltl(self, offset + y_offset, c.y, reverse_order);
	push_swap_solve_internal_rtl(self, offset + z_offset, c.z, reverse_order);
	free(s);
}

void	push_swap_solve_internal_rtl(
	t_push_swap *self,
	size_t offset,
	size_t count,
	bool reverse_order
)
{
	const t_push_swap_count_part	*c = &self->map[count];

	if (!count)
		return ;
	else if (count == 1)
		px(1, 0);
	else if (count == 2)
	{
		if (self->numbers[offset] < self->numbers[offset + 1] == reverse_order)
			sb();
		px(2, 0);
		return ;
	}
	else if (c->sort_and_move_collect_last.total_moves
		< c->sort_and_move_divide_first.total_moves)
		push_swap_solve_internal_rtl_collect_last(
			self, offset, count, reverse_order);
	else
		push_swap_solve_internal_rtl_divide_first(
			self, offset, count, reverse_order);
}
