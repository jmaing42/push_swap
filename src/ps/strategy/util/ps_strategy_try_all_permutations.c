/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_try_all_permutations.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:09:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 20:59:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ps_strategy.h"

t_ps_strategy_count_item	ps_strategy_util_try_all_permutations(
	t_ps_strategy_count *table,
	size_t count,
	size_t (*calculate_with_exact_count)(
		const t_ps_strategy_count *table,
		size_t x,
		size_t y,
		size_t z
	)
)
{
	size_t						x;
	size_t						y;
	size_t						z;
	size_t						now;
	t_ps_strategy_count_item	result;

	result.moves = SIZE_MAX;
	x = -1;
	while (++x < count)
	{
		y = -1;
		while (x + ++y <= count)
		{
			z = count - (x + y);
			if (y == count || z == count)
				continue ;
			now = calculate_with_exact_count(table, x, y, z);
			if (now < result.moves)
				result = (t_ps_strategy_count_item){x, y, z, now};
		}
	}
	return (result);
}
