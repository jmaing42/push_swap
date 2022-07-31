/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_txt_quick_straightforward.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 09:06:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_txt_quick_straightforward_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_sbt(arr, size.x, size.y, size.z);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_top_sbt(context, p, right)
			|| ps_solve_util_solve_tot(context, &p->z, !right, false)
			|| ps_solve_util_solve_sot(context, &p->y, !right, false)
			|| ps_solve_util_solve_bxt(context, &p->x, right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_txt_quick_straightforward_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ context->table[z].tot.item.count
		+ context->table[y].sot.item.count
		+ context->table[x].bxt.item.count
	);
}
