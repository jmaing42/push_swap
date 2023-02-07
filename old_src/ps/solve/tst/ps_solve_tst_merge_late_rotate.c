/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_merge_late_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:35:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_tst.h"

#include <stdlib.h>

#include "ft_types_primitive_size_t.h"

t_err	ps_solve_tst_merge_early_rotate_solve(
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
			|| ps_solve_util_solve_tot(context, &p->x, right, true)
			|| ps_solve_util_solve_tot(context, &p->y, right, false)
			|| ps_solve_util_solve_tst(context, &p->z, right, false)
			|| ps_solve_util_rotate_up(context, &p->z, &p->y, right)
			|| ps_solve_util_collect_to_top_tbs(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tst_merge_early_rotate_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_tot(table, x)
		+ ps_solve_util_count_tot(table, y)
		+ ps_solve_util_count_tst(table, z)
		+ ft_types_primitive_size_t_max(z, y)
		+ ps_solve_util_move_count_top_tbs(x, y, z)
	);
}
