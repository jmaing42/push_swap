/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tos_merge_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:26:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 10:27:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tos_merge.h"

#include <stddef.h>

#include "ft_size_t.h"
#include "ps_strategy_util.h"

size_t	ps_strategy_tos_merge_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	sort_x = table[x].txb.item.moves;
	const size_t	sort_y = table[y].tos.item.moves;
	const size_t	sort_z = table[z].tst.item.moves;
	const size_t	collect = 2 * x + y + z;

	return (sort_x + sort_y + sort_z + collect);
}

void	ps_strategy_tos_merge_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_tos_merge_count);

	if (table[index].tos.item.moves > current.moves)
	{
		table[index].tos.item = current;
		table[index].tos.func = ps_strategy_tos_merge_execute;
		table[index].tos.name = "tos_merge";
	}
}
