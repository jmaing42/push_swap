/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bst_merge_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:51:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 17:38:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_bst.h"

#include <stdlib.h>

#include "ft_types_primitive_size_t.h"

t_err	ps_solve_bst_merge_rotate_solve(
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
			|| ps_solve_util_solve_bot(context, &p->y, right, false)
			|| ps_solve_util_solve_bst(context, &p->x, right, false)
			|| ps_solve_util_rotate_up(context, &p->x, &p->y, right)
			|| ps_solve_util_collect_to_top_sbt(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bst_merge_rotate_count(
	const t_ps_solve_table *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_bst(table, z)
		+ ps_solve_util_count_bot(table, y)
		+ ps_solve_util_count_bst(table, x)
		+ ft_types_primitive_size_t_max(x, y)
		+ ps_solve_util_move_count_top_sbt(x, y, z)
	);
}
