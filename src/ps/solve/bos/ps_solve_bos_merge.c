/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bos_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:05:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 15:10:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_bos_merge_solve(
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
			|| ps_solve_util_solve_bxt(context, &p->z, right, true)
			|| ps_solve_util_solve_bos(context, &p->y, right, false)
			|| ps_solve_util_solve_bsb(context, &p->x, right, false)
			|| ps_solve_util_collect_to_top_bst(context, p, !right)
			);

	free(p);
	return (result);
}

size_t	ps_solve_bos_merge_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_count_bxt(context, z)
		+ ps_solve_util_count_bos(context, y)
		+ ps_solve_util_count_bsb(context, x)
		+ ps_solve_util_move_count_top_bst(x, y, z)
	);
}
