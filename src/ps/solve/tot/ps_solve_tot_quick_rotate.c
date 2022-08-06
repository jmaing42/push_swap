/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tot_quick_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:50:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 22:27:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitive_size_t.h"
#include "ps_solve_internal.h"

#include <stdlib.h>

t_err	ps_solve_tot_quick_rotate_solve(
	const t_ps_solve_context *context,
	int *arr,
	t_ps_solve_count_size size,
	bool right
)
{
	t_ps_solve_util_parts *const	p
		= ps_solve_util_allocate_divide_sbt(arr, size);
	const t_err						result
		= (
			!p
			|| ps_solve_util_divide_from_top_sbt(context, p, !right)
			|| ps_solve_util_solve_tst(context, &p->z, !right, false)
			|| ps_solve_util_rotate_down(context, &p->x, &p->y, false)
			|| ps_solve_util_solve_tst(context, &p->y, !right, false)
			|| ps_solve_util_solve_tot(context, &p->x, right, false)
			);

	free(p);
	return (result);
}

size_t	ps_solve_tot_quick_rotate_count(
	const t_ps_solve_context *context,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ps_solve_util_move_count_top_sbt(x, y, z)
		+ ps_solve_util_count_tst(context, z)
		+ ft_primitive_size_t_max(x, y)
		+ ps_solve_util_count_tst(context, y)
		+ ps_solve_util_count_tot(context, x)
	);
}
