/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bxb_merge_twist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:23:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:37:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_bxb.h"

#include <stdlib.h>

t_err	ps_solve_bxb_merge_twist_solve(
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
			|| ps_solve_util_solve_bos(context, &p->z, right, true)
			|| ps_solve_util_solve_bob(context, &p->y, right, false)
			|| ps_solve_util_solve_bst(context, &p->x, right, true)
			|| ps_solve_util_collect_to_bottom_sbt(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bxb_merge_twist_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_bos(table, z)
		+ ps_solve_util_count_bob(table, y)
		+ ps_solve_util_count_bst(table, x)
		+ ps_solve_util_move_count_bottom_sbt(x, y, z)
	);
}
