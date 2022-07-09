/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sob_merge_twist_up_count.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:36:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 17:13:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_sxs_merge_twist_up.h"

#include <stddef.h>

#include "ps_strategy_util.h"

size_t	ps_strategy_sxs_merge_twist_up_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	sort_x = table[x].tot.item.moves;
	const size_t	sort_y = table[y].tst.item.moves;
	const size_t	sort_z = table[z].bst.item.moves;
	const size_t	collect = x + 3 * y + 2 * z;

	return (sort_x + sort_y + sort_z + collect);
}

void	ps_strategy_sxs_merge_twist_up_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_sxs_merge_twist_up_count);

	if (table[index].sxs.item.moves > current.moves)
	{
		table[index].sxs.item = current;
		table[index].sxs.func = ps_strategy_sxs_merge_twist_up_execute;
		table[index].sxs.name = "sxs_merge_twist_up";
	}
}
