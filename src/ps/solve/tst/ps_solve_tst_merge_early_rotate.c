/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_merge_early_rotate.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 08:57:00 by Juyeong Maing    ###   ########.fr       */
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
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_collect(arr, size.x, size.y, size.z);
	const t_err						result
		= (
			!p
			|| ps_solve_util_solve_tot(context, &p->x, right, false)
			|| ps_solve_util_solve_tst(context, &p->y, right, false)
			|| ps_solve_util_rotate_up(context, &p->y, &p->x, right)
			|| ps_solve_util_solve_tot(context, &p->z, right, true)
			|| ps_solve_util_collect_to_top_bst(context, p, right)
			);

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
