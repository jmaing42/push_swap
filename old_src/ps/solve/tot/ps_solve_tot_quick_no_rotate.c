/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tot_quick_no_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:35:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_tot.h"

#include <stdlib.h>

t_err	ps_solve_tot_quick_no_rotate_solve(
	const t_ps_solve_context *context,
	const int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_sbt(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_top_sbt(context, p, !right)
			|| ps_solve_util_solve_tst(context, &p->z, !right, false)
			|| ps_solve_util_solve_bst(context, &p->y, !right, false)
			|| ps_solve_util_solve_bot(context, &p->x, right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tot_quick_no_rotate_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_top_sbt(x, y, z)
		+ ps_solve_util_count_tst(table, z)
		+ ps_solve_util_count_bst(table, y)
		+ ps_solve_util_count_bot(table, x)
	);
}
