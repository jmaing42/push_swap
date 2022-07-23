/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_merge_late_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/24 07:28:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

#include "ft_primitive_size_t.h"

t_err	ps_solve_tst_merge_early_rotate_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p = ps_solve_util_allocate_collect(
			arr,
			size.x,
			size.y,
			size.z);
	t_err							result;

	if (!p)
		return (true);
	result = (ps_solve_util_solve_tot(context, &p->a, right, true)
			|| ps_solve_util_solve_tot(context, &p->b, right, false)
			|| ps_solve_util_solve_tst(context, &p->c, right, false)
			|| ps_solve_util_rotate_up(context, &p->b, &p->a, right)
			|| ps_solve_util_collect_to_top_bts(context, p, right));
	free(p);
	return (result);
}

size_t	ps_solve_tst_merge_early_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].tot.item.count
		+ context->table[y].tot.item.count
		+ context->table[z].tst.item.count
		+ ft_primitive_size_t_max(z, y)
		+ 2 * x + y + z
	);
}
