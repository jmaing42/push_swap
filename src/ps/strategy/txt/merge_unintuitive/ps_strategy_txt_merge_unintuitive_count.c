/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txt_merge_unintuitive_count.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:16:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 00:19:34 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_txt_merge_unintuitive.h"

#include <stddef.h>

#include "ft_size_t.h"
#include "ps_strategy_util.h"

size_t	ps_strategy_txt_merge_unintuitive_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	sort_x = table[x].txb.item.moves;
	const size_t	sort_y = table[y].tos.item.moves;
	const size_t	sort_z = table[z].tob.item.moves;
	const size_t	collect = x + y + 2 * z;

	return (sort_x + sort_y + sort_z + collect);
}

void	ps_strategy_txt_merge_unintuitive_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_txt_merge_unintuitive_count);

	if (table[index].tst.item.moves > current.moves)
	{
		table[index].tst.item = current;
		table[index].tst.func = ps_strategy_txt_merge_unintuitive_execute;
		table[index].tst.name = "txt_merge_unintuitive";
	}
}
