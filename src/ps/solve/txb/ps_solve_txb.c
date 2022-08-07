/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_txb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:01:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/08 00:20:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_txb.h"

static const t_ps_solve_count_tuple	g_strategies[] = {
{
	ps_solve_txb_merge_straightforward_solve,
	ps_solve_txb_merge_straightforward_count,
},
{
	ps_solve_txb_merge_twist_solve,
	ps_solve_txb_merge_twist_count,
},
{
	ps_solve_txb_quick_straightforward_solve,
	ps_solve_txb_quick_straightforward_count,
},
{
	ps_solve_txb_quick_twist_solve,
	ps_solve_txb_quick_twist_count,
},
};

// TODO: implement

t_ps_solve_strategy	ps_solve_txb_strategy(
	const t_ps_solve_context *context,
	size_t count
)
{
	t_ps_solve_strategy	result;

	if (count < context->table_size)
	{
		result.size = context->table[count].tst.item.size;
		result.solve = context->table[count].tst.solve;
		return (result);
	}
	result.size.x = count / 3;
	result.size.y = (count - result.size.x) / 2;
	result.size.x = count - result.size.x - result.size.y;
	result.solve = ps_solve_txb_merge_straightforward_solve;
	return (result);
}

t_ps_solve_count_part	ps_solve_txb_count_part(
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

t_err	ps_solve_txb(
	const t_ps_solve_context *context,
	const int *arr,
	size_t length,
	bool from_right
)
{
	const t_ps_solve_strategy	strategy
		= ps_solve_txb_strategy(
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
