/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tsb_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/28 08:28:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_tsb_merge_solve(
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
			|| ps_solve_util_solve_tot(context, &p->a, right, true)
			|| ps_solve_util_solve_tob(context, &p->b, right, false)
			|| ps_solve_util_solve_tst(context, &p->c, right, true)
			|| ps_solve_util_collect_to_bottom_tbs(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tsb_merge_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].tot.item.count
		+ context->table[y].tob.item.count
		+ context->table[z].tst.item.count
		+ 2 * x + 3 * y + z
	);
}
