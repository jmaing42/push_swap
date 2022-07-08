/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tst_quick_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:04:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 21:06:34 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tst_quick.h"

#include <stddef.h>

#include "ps_strategy_util.h"

size_t	ps_strategy_tst_quick_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	divide = x + y + 2 * z;
	const size_t	sort_z = table[z].bot.item.moves;
	const size_t	sort_y = table[y].bst.item.moves;
	const size_t	sort_x = table[x].tot.item.moves;

	return (divide + sort_z + sort_y + sort_x);
}

void	ps_strategy_tst_quick_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_tst_quick_count);

	if (table[index].tst.item.moves > current.moves)
	{
		table[index].tst.item = current;
		table[index].tst.func = ps_strategy_tst_quick_execute;
		table[index].tst.name = "tst_quick";
	}
}
