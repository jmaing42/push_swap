/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bst_merge_no_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:51:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/01 09:21:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_bst_merge_no_rotate_solve(
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
			|| ps_solve_util_solve_bst(context, &p->x, right, true)
			|| ps_solve_util_solve_bob(context, &p->y, right, false)
			|| ps_solve_util_solve_bsb(context, &p->z, right, false)
			|| ps_solve_util_collect_to_top_tsb(context, p, !right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bst_merge_no_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].bst.item.count
		+ context->table[y].bob.item.count
		+ context->table[z].bsb.item.count
		+ ps_solve_util_move_count_top_tsb(x, y, z)
	);
}
