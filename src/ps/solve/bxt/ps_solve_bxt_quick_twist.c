/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bxt_quick_twist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:16:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/01 23:19:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_sxs_quick_twist_solve(
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
			|| ps_solve_util_divide_from_bottom_bts(context, p, right)
			|| ps_solve_util_solve_bob(context, &p->x, !right, false)
			|| ps_solve_util_solve_sob(context, &p->y, !right, false)
			|| ps_solve_util_solve_txb(context, &p->z, right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_sxs_quick_twist_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_bottom_bts(x, y, z)
		+ context->table[x].bob.item.count
		+ context->table[y].sob.item.count
		+ context->table[z].txb.item.count
	);
}
