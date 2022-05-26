/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/27 01:06:31 by Juyeong Maing    ###   ########.fr       */
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
	push_swap_solve_internal_collect((t_push_swap_solve_internal_collect){
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
