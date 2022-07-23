/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_merge_no_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/24 08:48:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "stdlib.h"

t_err	ps_solve_tst_merge_no_rotate_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_collect(arr, size.x, size.y, size.z);
	const t_err						result
		= (
			!p
			|| ps_solve_util_solve_tsb(context, &p->a, right, false)
			|| ps_solve_util_solve_tot(context, &p->b, right, true)
			|| ps_solve_util_solve_tob(context, &p->c, right, false)
			|| ps_solve_util_collect_to_top_stb(context, p, right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tst_merge_no_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].tsb.item.count
		+ context->table[y].tot.item.count
		+ context->table[z].tob.item.count
		+ x + y + 2 * z
	);
}
