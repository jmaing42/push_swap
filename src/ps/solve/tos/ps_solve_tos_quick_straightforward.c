/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tos_quick_straightforward.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 16:36:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_tos_quick_straightforward_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_stb(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_top_stb(context, p, right)
			|| ps_solve_util_solve_bsb(context, &p->z, !right, false)
			|| ps_solve_util_solve_tst(context, &p->y, !right, false)
			|| ps_solve_util_solve_bot(context, &p->x, right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tos_quick_straightforward_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_top_stb(x, y, z)
		+ context->table[z].bsb.item.count
		+ context->table[y].tst.item.count
		+ context->table[x].bot.item.count
	);
}
