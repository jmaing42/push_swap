/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tob_quick_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:03:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types_primitive_size_t.h"
#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_tob_quick_rotate_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_tsb(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_top_tsb(context, p, !right)
			|| ps_solve_util_rotate_down(context, &p->y, &p->x, false)
			|| ps_solve_util_solve_tsb(context, &p->z, !right, false)
			|| ps_solve_util_solve_tob(context, &p->y, right, false)
			|| ps_solve_util_solve_tsb(context, &p->x, !right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tob_quick_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_top_tsb(x, y, z)
		+ ft_types_primitive_size_t_max(y, x)
		+ ps_solve_util_count_tsb(context, z)
		+ ps_solve_util_count_tob(context, y)
		+ ps_solve_util_count_tsb(context, x)
	);
}
