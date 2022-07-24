/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_quick_late_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/24 21:19:31 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitive_size_t.h"

#include <stdlib.h>

#include "ps_solve_internal.h"

t_err	ps_solve_tst_quick_late_rotate_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_bst(arr, size.x, size.y, size.z);
	const t_err						result
		= (
			!p
			|| ps_solve_util_collect_to_top_bst(context, p, right)
			|| ps_solve_util_solve_tot(context, &p->c, !right, false)
			|| ps_solve_util_rotate_down(context, &p->b, &p->a, right)
			|| ps_solve_util_solve_tst(context, &p->b, right, false)
			|| ps_solve_util_solve_tot(context, &p->a, !right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tst_quick_late_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ context->table[z].tot.item.count
		+ ft_primitive_size_t_max(y, x)
		+ context->table[y].tst.item.count
		+ context->table[x].tot.item.count
		+ x + 2 * y + z
	);
}
