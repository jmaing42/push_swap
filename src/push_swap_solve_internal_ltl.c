/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_ltl.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/25 20:52:22 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"
#include "ft_malloc.h"

void	push_swap_solve_internal_ltl_collect_last(
	t_push_swap *self,
	size_t offset,
	size_t count,
	bool reverse_order
)
{
	const t_push_swap_count_item	c = self->map[count].sort_only_collect_last;
	const size_t					y_offset = c.x;
	const size_t					z_offset = y_offset + c.y;

	push_swap_solve_internal_ltr(self, 0, c.x, !reverse_order);
	push_swap_solve_internal_ltr(self, y_offset, c.y, reverse_order);
	push_swap_solve_internal_ltl(self, z_offset, c.z, reverse_order);
	rx(c.z, c.y);
	push_swap_internal_collect((t_push_swap_internal_collect){
		self->numbers,
		c.x,
		c.y,
		c.z,
		false,
		reverse_order
	});
	push_swap_internal_sort(&self->numbers[offset], count, reverse_order);
}

void	push_swap_solve_internal_ltl_divide_first(
	t_push_swap *self,
	size_t offset,
	size_t count,
	bool r
)
{
	const t_push_swap_count_item	c = self->map[count].sort_only_divide_first;
	const size_t					y_offset = c.x;
	const size_t					z_offset = y_offset + c.y;
	int *const						s
		= (int *)ft_malloc(sizeof(int) * count);

	ft_memcpy(s, &self->numbers[offset], sizeof(int) * count);
	push_swap_internal_sort(s, count, r);
	push_swap_internal_divide((t_push_swap_internal_divide){
		&self->numbers[offset],
		(t_push_swap_internal_part){c.y, s[c.z], s[c.z + c.y - 1]},
		(t_push_swap_internal_part){c.x, s[count - c.x], s[count - 1]},
		(t_push_swap_internal_part){c.z, s[0], s[c.z - 1]},
		false,
		r
	});
	push_swap_solve_internal_rtl(self, offset + 0, c.x, !r);
	rrx(c.y, c.z);
	push_swap_solve_internal_ltr(self, offset + y_offset, c.y, r);
	push_swap_solve_internal_ltl(self, offset + z_offset, c.z, r);
	ft_memcpy(&self->numbers[offset], s, sizeof(int) * count);
	free(s);
}

void	push_swap_solve_internal_ltl(
	t_push_swap *self,
	size_t offset,
	size_t count,
	bool reverse_order
)
{
	const t_push_swap_count_part	*c = &self->map[count];

	if (c->sort_and_move_collect_last.total_moves
		< c->sort_and_move_divide_first.total_moves)
		return (
			push_swap_solve_internal_ltl_collect_last(
				self,
				offset,
				count,
				reverse_order
			)
		);
	else
		return (
			push_swap_solve_internal_ltl_divide_first(
				self,
				offset,
				count,
				reverse_order
			)
		);
}
