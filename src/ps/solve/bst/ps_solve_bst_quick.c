/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bst_quick.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:09:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:38:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_bst.h"

#include <stdlib.h>

t_err	ps_solve_bst_quick_solve(
	const t_ps_solve_context *context,
	const int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_bts(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_bottom_bts(context, p, right)
			|| ps_solve_util_solve_tst(context, &p->z, right, false)
			|| ps_solve_util_solve_tot(context, &p->y, !right, false)
			|| ps_solve_util_solve_bot(context, &p->x, !right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bst_quick_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_bottom_bts(x, y, z)
		+ ps_solve_util_count_tst(table, z)
		+ ps_solve_util_count_tot(table, y)
		+ ps_solve_util_count_bot(table, x)
	);
}
