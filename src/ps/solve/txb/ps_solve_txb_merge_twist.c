/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_txb_merge_twist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:51:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:00:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_txb_merge_twist_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_collect(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_solve_tos(context, &p->x, right, false)
			|| ps_solve_util_solve_tob(context, &p->y, right, true)
			|| ps_solve_util_solve_tst(context, &p->z, right, false)
			|| ps_solve_util_collect_to_top_tbs(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_txb_merge_twist_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].tos.item.count
		+ context->table[y].tob.item.count
		+ context->table[z].tst.item.count
		+ ps_solve_util_move_count_bottom_tbs(x, y, z)
	);
}
