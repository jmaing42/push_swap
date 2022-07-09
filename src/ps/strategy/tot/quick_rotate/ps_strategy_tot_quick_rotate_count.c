/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tot_quick_rotate_count.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:09:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 10:11:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tot_quick_rotate.h"

#include <stddef.h>

#include "ft_size_t.h"
#include "ps_strategy_util.h"

size_t	ps_strategy_tot_quick_rotate_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	divide = x + 2 * y + z;
	const size_t	sort_z = table[z].tst.item.moves;
	const size_t	rotate = ft_size_t_max(z, y);
	const size_t	sort_y = table[y].tst.item.moves;
	const size_t	sort_x = table[x].tot.item.moves;

	return (divide + sort_z + rotate + sort_y + sort_x);
}

void	ps_strategy_tot_quick_rotate_count_init_if_better(
	t_ps_strategy_count *table,
	size_t index
)
{
	const t_ps_strategy_count_item	current
		= ps_strategy_util_try_all_permutations(
			table,
			index,
			ps_strategy_tot_quick_rotate_count);

	if (table[index].tot.item.moves > current.moves)
	{
		table[index].tot.item = current;
		table[index].tot.func = ps_strategy_tot_quick_rotate_execute;
		table[index].tot.name = "tot_quick_rotate";
	}
}