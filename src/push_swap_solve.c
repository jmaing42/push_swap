/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/25 21:43:18 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

void	push_swap_solve(
	t_push_swap *self
)
{
	const size_t	y_offset = self->solution.x;
	const size_t	z_offset = y_offset + self->solution.y;

	push_swap_solve_internal_ltr(self, 0, self->solution.x, false);
	push_swap_solve_internal_ltr(self, y_offset, self->solution.y, true);
	push_swap_solve_internal_ltl(self, z_offset, self->solution.z, false);
	push_swap_internal_collect((t_push_swap_internal_collect){
		self->numbers,
		self->solution.z,
		z_offset,
		self->solution.y,
		y_offset,
		self->solution.x,
		0,
		false,
		false,
	});
}
