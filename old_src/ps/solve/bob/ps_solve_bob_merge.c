/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bob_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:03:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:39:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_bob.h"

#include <stdlib.h>

t_err	ps_solve_bob_merge_solve(
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
			|| ps_solve_util_solve_bot(context, &p->z, right, true)
			|| ps_solve_util_solve_bst(context, &p->y, right, true)
			|| ps_solve_util_solve_bsb(context, &p->x, right, false)
			|| ps_solve_util_collect_to_bottom_bts(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bob_merge_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_bot(table, z)
		+ ps_solve_util_count_bst(table, y)
		+ ps_solve_util_count_bsb(table, x)
		+ ps_solve_util_move_count_bottom_bts(x, y, z)
	);
}
