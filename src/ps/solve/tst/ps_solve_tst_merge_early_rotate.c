/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_merge_early_rotate.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/24 07:28:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

#include "ft_primitive_size_t.h"

t_err	ps_solve_tst_merge_late_rotate_solve(
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
	result = (ps_solve_util_solve_tot(context, &p->a, right, false)
			|| ps_solve_util_solve_tst(context, &p->b, right, false)
			|| ps_solve_util_rotate_up(context, &p->b, &p->a, right)
			|| ps_solve_util_solve_tot(context, &p->c, right, true)
			|| ps_solve_util_collect_to_top_bst(context, p, right));
	free(p);
	return (result);
}

size_t	ps_solve_tst_merge_late_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].tot.item.count
		+ context->table[y].tst.item.count
		+ ft_primitive_size_t_max(y, x)
		+ context->table[z].tot.item.count
		+ 2 * x + y + z
	);
}
