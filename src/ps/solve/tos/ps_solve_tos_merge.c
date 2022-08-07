/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tos_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:51:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:35:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_tos.h"

#include <stdlib.h>

t_err	ps_solve_tos_merge_solve(
	const t_ps_solve_context *context,
	const int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_collect(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_solve_txb(context, &p->x, right, false)
			|| ps_solve_util_solve_tos(context, &p->y, right, false)
			|| ps_solve_util_solve_tst(context, &p->z, right, true)
			|| ps_solve_util_collect_to_top_bst(context, p, !right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tos_merge_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_txb(table, x)
		+ ps_solve_util_count_tos(table, y)
		+ ps_solve_util_count_tst(table, z)
		+ ps_solve_util_move_count_top_bst(x, y, z)
	);
}
