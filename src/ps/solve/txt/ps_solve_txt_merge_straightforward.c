/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_txt_merge_straightforward.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:49:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/29 09:02:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_txt_merge_straightforward_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_collect(arr, size.x, size.y, size.z);
	const t_err						result
		= (
			!p
			|| ps_solve_util_solve_txb(context, &p->a, right, false)
			|| ps_solve_util_solve_tos(context, &p->b, right, false)
			|| ps_solve_util_solve_tot(context, &p->c, right, true)
			|| ps_solve_util_collect_to_top_sbt(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_txt_merge_straightforward_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].txb.item.count
		+ context->table[y].tos.item.count
		+ context->table[z].tot.item.count
		+ x + 2 * y + z
	);
}
