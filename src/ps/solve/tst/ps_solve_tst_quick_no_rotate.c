/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_quick_no_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/28 08:27:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_tst_quick_no_rotate_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_tbs(arr, size.x, size.y, size.z);
	const t_err						result
		= (
			!p
			|| ps_solve_util_collect_to_top_tbs(context, p, right)
			|| ps_solve_util_solve_tot(context, &p->a, !right, false)
			|| ps_solve_util_solve_bot(context, &p->b, !right, false)
			|| ps_solve_util_solve_bst(context, &p->c, right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tst_quick_no_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[x].tot.item.count
		+ context->table[y].bob.item.count
		+ context->table[z].bst.item.count
		+ x + 2 * y + z
	);
}
