/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sss_merge_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:52:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 14:52:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_sss_merge.h"

#include <stddef.h>

#include "ps_strategy_util.h"

size_t	ps_strategy_sss_merge_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	sort_x = table[x].tot.item.moves;
	const size_t	sort_y = table[y].tob.item.moves;
	const size_t	sort_z = table[z].sss.item.moves;
	const size_t	collect = x + 2 * y + z;

	return (sort_x + sort_y + sort_z + collect);
}

void	ps_strategy_sss_merge_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_sss_merge_count);

	if (table[index].sss.item.moves > current.moves)
	{
		table[index].sss.item = current;
		table[index].sss.func = ps_strategy_sss_merge_execute;
		table[index].sss.name = "sss_merge";
	}
}
