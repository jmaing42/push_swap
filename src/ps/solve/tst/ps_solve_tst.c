/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:01:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 09:21:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_tst.h"
#include "ps_solve_internal.h"

// TODO: implement

static const t_ps_solve_count_tuple	g_strategies[] = {
{
	ps_solve_tst_merge_no_rotate_solve,
	ps_solve_tst_merge_no_rotate_count,
},
{
	ps_solve_tst_merge_early_rotate_solve,
	ps_solve_tst_merge_early_rotate_count,
},
{
	ps_solve_tst_merge_late_rotate_solve,
	ps_solve_tst_merge_late_rotate_count,
},
{
	ps_solve_tst_merge_no_rotate_solve,
	ps_solve_tst_merge_no_rotate_count,
},
{
	ps_solve_tst_merge_early_rotate_solve,
	ps_solve_tst_merge_early_rotate_count,
},
{
	ps_solve_tst_merge_late_rotate_solve,
	ps_solve_tst_merge_late_rotate_count,
},
};

t_ps_solve_strategy	ps_solve_tst_strategy(
	t_ps_solve_context *context,
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
	result.solve = NULL;
	return (result);
}

t_ps_solve_count_part	ps_solve_tst_count_part(
	size_t count
)
{
	return (
		ps_solve_count_part(
			g_strategies,
			sizeof(g_strategies) / sizeof(g_strategies[0]),
			count
		)
	);
}

t_err	ps_solve_tst(
	t_ps_solve_context *context,
	int *arr,
	size_t length,
	bool from_right
)
{
	const t_ps_solve_strategy	strategy = ps_solve_tst_strategy(
			context,
			length);

	return (strategy.solve(context, arr, strategy.size, from_right));
}
