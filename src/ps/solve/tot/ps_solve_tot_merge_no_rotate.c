/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tot_merge_no_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:51:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 22:26:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_tot_merge_no_rotate_solve(
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
			|| ps_solve_util_solve_tob(context, &p->x, right, false)
			|| ps_solve_util_solve_tsb(context, &p->y, right, false)
			|| ps_solve_util_solve_tst(context, &p->z, right, true)
			|| ps_solve_util_collect_to_top_sbt(context, p, !right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tot_merge_no_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_tob(context, x)
		+ ps_solve_util_count_tsb(context, y)
		+ ps_solve_util_count_tst(context, z)
		+ ps_solve_util_move_count_top_sbt(x, y, z)
	);
}
