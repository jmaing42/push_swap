/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_merge_no_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:15:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "stdlib.h"

t_err	ps_solve_tst_merge_no_rotate_solve(
	t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p = ps_solve_util_allocate_collect(
			arr,
			size.x,
			size.y,
			size.z);
	t_ps_solve_util_collect			collect;
	t_err							result;

	if (!p)
		return (true);
	collect.stream = context->stream;
	collect.p = &p->a;
	collect.q = &p->b;
	collect.r = &p->c;
	collect.from_right = right;
	ps_solve_util_array_inverse(&p->b);
	result = (ps_solve_tsb(context, p->a.array, size.x, right)
			|| ps_solve_tot(context, p->b.array, size.y, right)
			|| ps_solve_tob(context, p->c.array, size.z, right)
			|| ps_solve_util_collect_to_top(&collect));
	free(p);
	return (result);
}

size_t	ps_solve_tst_merge_no_rotate_count(
	t_ps_solve_context *context,
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
