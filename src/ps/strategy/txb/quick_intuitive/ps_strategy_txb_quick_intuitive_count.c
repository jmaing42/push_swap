/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txb_quick_intuitive_count.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:36:36 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 09:42:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_txb_quick_intuitive.h"

#include <stddef.h>

#include "ft_size_t.h"
#include "ps_strategy_util.h"

size_t	ps_strategy_txb_quick_intuitive_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	divide = x + y + 2 * z;
	const size_t	sort_x = table[x].bsb.item.moves;
	const size_t	sort_y = table[y].tob.item.moves;
	const size_t	sort_z = table[z].sob.item.moves;

	return (divide + sort_x + sort_y + sort_z);
}

void	ps_strategy_txb_quick_intuitive_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_txb_quick_intuitive_count);

	if (table[index].txb.item.moves > current.moves)
	{
		table[index].txb.item = current;
		table[index].txb.func = ps_strategy_txb_quick_intuitive_execute;
		table[index].txb.name = "txb_quick_intuitive";
	}
}
