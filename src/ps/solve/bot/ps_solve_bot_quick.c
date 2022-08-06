/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bot_quick.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:53:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 22:16:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_bst_quick_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_bst(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_bottom_bst(context, p, !right)
			|| ps_solve_util_solve_tst(context, &p->z, !right, false)
			|| ps_solve_util_solve_tot(context, &p->y, right, false)
			|| ps_solve_util_solve_bst(context, &p->x, !right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bst_quick_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_bottom_bst(x, y, z)
		+ context->table[z].tst.item.count
		+ context->table[y].tot.item.count
		+ context->table[x].bst.item.count
	);
}
