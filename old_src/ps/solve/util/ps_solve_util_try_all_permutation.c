/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_try_all_permutation.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:09:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 00:30:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ps_solve_internal.h"

t_ps_solve_count_item	ps_solve_util_try_all_permutation(
	const t_ps_solve_table *table,
	t_ps_solve_count strategy,
	size_t count
)
{
	size_t					x;
	size_t					y;
	size_t					z;
	size_t					now;
	t_ps_solve_count_item	result;

	result.count = SIZE_MAX;
	x = -1;
	while (++x < count)
	{
		y = -1;
		while (x + ++y <= count)
		{
			z = count - (x + y);
			if (y == count || z == count)
				continue ;
			now = strategy(table, x, y, z);
			if (now < result.count)
				result = (t_ps_solve_count_item){{x, y, z}, now};
		}
	}
	return (result);
}
