/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tsb_quick_rotate_count.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:13:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 20:35:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tsb_quick_rotate.h"

#include <stddef.h>

#include "ft_primitive_size_t.h"
#include "ps_strategy_util.h"

size_t	ps_strategy_tsb_quick_rotate_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	divide = x + 2 * y + z;
	const size_t	rotate = ft_primitive_size_t_max(x, y);
	const size_t	sort_x = table[x].tsb.item.moves;
	const size_t	sort_y = table[y].tob.item.moves;
	const size_t	sort_z = table[z].tob.item.moves;

	return (divide + sort_x + sort_y + sort_z);
}

void	ps_strategy_tsb_quick_rotate_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_tsb_quick_rotate_count);

	if (table[index].tsb.item.moves > current.moves)
	{
		table[index].tsb.item = current;
		table[index].tsb.func = ps_strategy_tsb_quick_rotate_execute;
		table[index].tsb.name = "tsb_quick_rotate";
	}
}
