/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bos_quick_rotate_down.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:53:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:39:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_bos.h"

#include <stdlib.h>

t_err	ps_solve_bos_quick_rotate_down_solve(
	const t_ps_solve_context *context,
	const int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_stb(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_bottom_stb(context, p, !right)
			|| ps_solve_util_solve_bst(context, &p->z, !right, false)
			|| ps_solve_util_solve_bst(context, &p->y, !right, false)
			|| ps_solve_util_solve_tot(context, &p->x, right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bos_quick_rotate_down_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_bottom_stb(x, y, z)
		+ ps_solve_util_count_bst(table, z)
		+ ps_solve_util_count_bst(table, y)
		+ ps_solve_util_count_tot(table, x)
	);
}
