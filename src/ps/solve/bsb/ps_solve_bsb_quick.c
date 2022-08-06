/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bsb_quick.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:30:47 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 22:26:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_bsb_quick_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_bts(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_bottom_stb(context, p, right)
			|| ps_solve_util_solve_tsb(context, &p->x, right, false)
			|| ps_solve_util_solve_tob(context, &p->y, !right, false)
			|| ps_solve_util_solve_bob(context, &p->z, !right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bsb_quick_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_bottom_stb(x, y, z)
		+ ps_solve_util_count_tsb(context, x)
		+ ps_solve_util_count_tob(context, y)
		+ ps_solve_util_count_bob(context, z)
	);
}
