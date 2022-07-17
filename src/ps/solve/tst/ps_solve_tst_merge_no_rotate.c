/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_merge_no_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:44:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 07:48:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "stdlib.h"

t_err	ps_solve_tst_merge_no_rotate_solve(
	t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool from_right
)
{
	t_ps_solve_util_parts *const	parts = ps_solve_util_collect(
			arr,
			size.x,
			size.y,
			size.z);
	t_ps_solve_util_divide			div;
	t_err							result;

	if (!parts)
		return (true);
	div.stream = context->stream;
	div.p = &parts->a;
	div.q = &parts->b;
	div.r = &parts->c;
	div.from_right = from_right;
	ps_solve_util_inverse(&parts->b);
	result = (ps_solve_tsb(context, arr, size.x, from_right)
			|| ps_solve_tot(context, arr, size.y, from_right)
			|| ps_solve_tob(context, arr, size.z, from_right)
			|| ps_solve_util_collect_to_top(div));
	free(parts);
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
