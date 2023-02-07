/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_txt_merge_straightforward.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:49:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:35:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_txt.h"

#include <stdlib.h>

t_err	ps_solve_txt_merge_straightforward_solve(
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
			|| ps_solve_util_solve_tot(context, &p->z, right, true)
			|| ps_solve_util_collect_to_top_sbt(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_txt_merge_straightforward_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_txb(table, x)
		+ ps_solve_util_count_tos(table, y)
		+ ps_solve_util_count_tot(table, z)
		+ ps_solve_util_move_count_top_sbt(x, y, z)
	);
}
