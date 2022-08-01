/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bsb_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:37:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/01 22:56:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_bsb_merge_solve(
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
			|| ps_solve_util_solve_bob(context, &p->z, right, true)
			|| ps_solve_util_solve_bot(context, &p->y, right, true)
			|| ps_solve_util_solve_bst(context, &p->x, right, false)
			|| ps_solve_util_collect_to_bottom_stb(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bsb_merge_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[z].bsb.item.count
		+ context->table[y].bob.item.count
		+ context->table[x].bst.item.count
		+ ps_solve_util_move_count_bottom_stb(x, y, z)
	);
}
