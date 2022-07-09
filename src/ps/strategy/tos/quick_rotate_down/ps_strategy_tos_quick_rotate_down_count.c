/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tos_quick_rotate_down_count.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:37:04 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 12:37:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tos_quick_rotate_down.h"

#include <stddef.h>

#include "ps_strategy_util.h"

size_t	ps_strategy_tos_quick_rotate_down_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	divide = x + y + 2 * z;
	const size_t	sort_y = table[y].tsb.item.moves;
	const size_t	sort_z = table[z].tsb.item.moves;
	const size_t	sort_x = table[x].bot.item.moves;

	return (divide + sort_z + sort_y + sort_x);
}

void	ps_strategy_tos_quick_rotate_down_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_tos_quick_rotate_down_count);

	if (table[index].tos.item.moves > current.moves)
	{
		table[index].tos.item = current;
		table[index].tos.func = ps_strategy_tos_quick_rotate_down_execute;
		table[index].tos.name = "tos_quick_rotate_down";
	}
}
