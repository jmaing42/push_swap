/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bxt_quick_straightforward.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:16:53 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 21:50:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_bxt_quick_straightforward_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_tbs(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_bottom_tbs(context, p, right)
			|| ps_solve_util_solve_tst(context, &p->z, right, false)
			|| ps_solve_util_solve_tot(context, &p->y, !right, false)
			|| ps_solve_util_solve_sot(context, &p->x, !right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_sxs_quick_straightforward_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_bottom_tbs(x, y, z)
		+ context->table[z].tst.item.count
		+ context->table[y].tot.item.count
		+ context->table[x].sot.item.count
	);
}
