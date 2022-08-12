/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:03:17 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/08 00:37:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_bob.h"
#include "ps_hardcoded.h"

static const t_ps_solve_count_tuple	g_strategies[] = {
{
	ps_solve_bob_merge_solve,
	ps_solve_bob_merge_count,
},
{
	ps_solve_bob_quick_solve,
	ps_solve_bob_quick_count,
},
};

// TODO: implement

t_ps_solve_strategy	ps_solve_bob_strategy(
	const t_ps_solve_context *context,
	size_t count
)
{
	t_ps_solve_strategy	result;

	if (count < context->table_size)
	{
		result.size = context->table[count].bob.item.size;
		result.solve = context->table[count].bob.solve;
		return (result);
	}
	result.size.x = count / 3;
	result.size.y = (count - result.size.x) / 2;
	result.size.z = count - result.size.x - result.size.y;
	result.solve = ps_solve_bob_merge_solve;
	return (result);
}

t_ps_solve_count_part	ps_solve_bob_count_part(
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

t_err	ps_solve_bob(
	const t_ps_solve_context *context,
	const int *arr,
	size_t length,
	bool from_right
)
{
	const t_ps_solve_strategy	strategy
		= ps_solve_bob_strategy(
			context,
			length);

	if (!length)
		return (false);
	if (length <= PS_HARDCODED_COUNT_BOB)
		return (
			ps_hardcoded_execute(
				context->stream,
				ps_hardcoded_find_index(arr, length),
				from_right,
				ps_hardcoded_bob_table(length)
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
