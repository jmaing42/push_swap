/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:01:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/08 00:25:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_tob.h"
#include "ps_hardcoded.h"

static const t_ps_solve_count_tuple	g_strategies[] = {
{
	ps_solve_tob_merge_solve,
	ps_solve_tob_merge_count,
},
{
	ps_solve_tob_quick_no_rotate_solve,
	ps_solve_tob_quick_no_rotate_count,
},
{
	ps_solve_tob_quick_rotate_solve,
	ps_solve_tob_quick_rotate_count,
},
};

// TODO: implement

t_ps_solve_strategy	ps_solve_tob_strategy(
	const t_ps_solve_context *context,
	size_t count
)
{
	t_ps_solve_strategy	result;

	if (count < context->table_size)
	{
		result.size = context->table[count].tob.item.size;
		result.solve = context->table[count].tob.solve;
		return (result);
	}
	result.size.x = count / 3;
	result.size.y = (count - result.size.x) / 2;
	result.size.z = count - result.size.x - result.size.y;
	result.solve = ps_solve_tob_merge_solve;
	return (result);
}

t_ps_solve_count_part	ps_solve_tob_count_part(
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

t_err	ps_solve_tob(
	const t_ps_solve_context *context,
	const int *arr,
	size_t length,
	bool from_right
)
{
	const t_ps_solve_strategy	strategy
		= ps_solve_tob_strategy(
			context,
			length);

	if (!length)
		return (false);
	if (length <= PS_HARDCODED_COUNT_TOB)
		return (
			ps_hardcoded_execute(
				context->stream,
				ps_hardcoded_find_index(arr, length),
				from_right,
				ps_hardcoded_tob_table(length)
			)
		);
	return (
		strategy.solve(
			context,
			arr,
			strategy.size,
			from_right
		)
	);
}
