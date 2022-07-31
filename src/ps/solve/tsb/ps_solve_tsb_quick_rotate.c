/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tsb_quick_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 09:14:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitive_size_t.h"

#include <stdlib.h>

#include "ps_solve_internal.h"

t_err	ps_solve_tsb_quick_rotate_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_bst(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_top_bst(context, p, right)
			|| ps_solve_util_rotate_down(context, &p->x, &p->y, right)
			|| ps_solve_util_solve_tsb(context, &p->x, right, false)
			|| ps_solve_util_solve_tob(context, &p->y, !right, false)
			|| ps_solve_util_solve_tob(context, &p->z, !right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tsb_quick_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ ft_primitive_size_t_max(x, y)
		+ context->table[x].tsb.item.count
		+ context->table[y].tob.item.count
		+ context->table[z].tob.item.count
	);
}
