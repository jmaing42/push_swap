/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_sxs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:01:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/08 00:27:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_sxs.h"

static const t_ps_solve_count_tuple	g_strategies[] = {
{
	ps_solve_sxs_merge_straightforward_solve,
	ps_solve_sxs_merge_straightforward_count,
},
{
	ps_solve_sxs_merge_twist_solve,
	ps_solve_sxs_merge_twist_count,
},
{
	ps_solve_sxs_quick_straightforward_solve,
	ps_solve_sxs_quick_straightforward_count,
},
{
	ps_solve_sxs_quick_twist_solve,
	ps_solve_sxs_quick_twist_count,
},
};

// TODO: implement

t_ps_solve_strategy	ps_solve_sxs_strategy(
	const t_ps_solve_context *context,
	size_t count
)
{
	t_ps_solve_strategy	result;

	if (count < context->table_size)
	{
		result.size = context->table[count].sxs.item.size;
		result.solve = context->table[count].sxs.solve;
		return (result);
	}
	result.size.x = count / 3;
	result.size.y = (count - result.size.x) / 2;
	result.size.z = count - result.size.x - result.size.y;
	result.solve = ps_solve_sxs_merge_straightforward_solve;
	return (result);
}

t_ps_solve_count_part	ps_solve_sxs_count_part(
	const t_ps_solve_table *table,
	size_t count
)
{
	return (
		ps_solve_util_count_part(
			table,
			g_strategies,
			sizeof(g_strategies) / sizeof(g_strategies[0]),
			count
		)
	);
}

t_err	ps_solve_sxs(
	const t_ps_solve_context *context,
	const int *arr,
	size_t length,
	bool from_right
)
{
	const t_ps_solve_strategy	strategy
		= ps_solve_sxs_strategy(
			context,
			length);

	return (
		strategy.solve(
			context,
			arr,
			strategy.size,
			from_right
		)
	);
}
