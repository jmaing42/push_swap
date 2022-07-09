/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bst_merge_no_rotate_count.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:01:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 18:02:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_bst_merge_no_rotate.h"

#include <stddef.h>

#include "ps_strategy_util.h"

size_t	ps_strategy_bst_merge_no_rotate_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	sort_z = table[z].bot.item.moves;
	const size_t	sort_y = table[y].bob.item.moves;
	const size_t	sort_x = table[x].bsb.item.moves;
	const size_t	collect = x + 2 * y + z;

	return (sort_x + sort_y + sort_z + collect);
}

void	ps_strategy_bst_merge_no_rotate_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_bst_merge_no_rotate_count);

	if (table[index].sxs.item.moves > current.moves)
	{
		table[index].sxs.item = current;
		table[index].sxs.func = ps_strategy_bst_merge_no_rotate_execute;
		table[index].sxs.name = "bst_merge_no_rotate";
	}
}
