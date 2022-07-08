/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tsb_merge_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:28:23 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 21:31:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tsb_merge.h"

#include <stddef.h>

#include "ft_size_t.h"
#include "ps_strategy_util.h"

size_t	ps_strategy_tsb_merge_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	sort_x = table[x].tob.item.moves;
	const size_t	sort_y = table[y].tot.item.moves;
	const size_t	sort_z = table[z].tst.item.moves;
	const size_t	collect = 3 * x + 2 * y + z;

	return (sort_x + sort_y + sort_z + collect);
}

void	ps_strategy_tsb_merge_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_tsb_merge_count);

	if (table[index].tst.item.moves > current.moves)
	{
		table[index].tst.item = current;
		table[index].tst.func = ps_strategy_tsb_merge_execute;
		table[index].tst.name = "tsb_merge";
	}
}
