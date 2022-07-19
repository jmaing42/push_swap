/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_count_part.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:05:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/19 09:09:54 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_ps_solve_count_part	ps_solve_util_count_part(
	const t_ps_solve_table *table,
	const t_ps_solve_count_tuple *strategies,
	size_t length,
	size_t count
)
{
	t_ps_solve_count_part	result;
	size_t					i;
	t_ps_solve_count_item	tmp;

	result.item
		= ps_solve_util_try_all_permutation(
			table,
			strategies[0].counter,
			count);
	result.solve = strategies[0].solver;
	i = 0;
	while (++i < length)
	{
		tmp
			= ps_solve_util_try_all_permutation(
				table,
				strategies[i].counter,
				count);
		if (tmp.count < result.item.count)
		{
			result.item = tmp;
			result.solve = strategies[i].solver;
		}
	}
	return (result);
}
