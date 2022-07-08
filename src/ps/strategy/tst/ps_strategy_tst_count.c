/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tst_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 09:29:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tst.h"

#include <stddef.h>

#include "ft_size_t.h"

size_t	ps_strategy_tst_count_m1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tot.item.moves
		+ table[y].tot.item.moves
		+ table[z].tst.item.moves
		+ ft_size_t_max(z, y)
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_tst_count_m2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tot.item.moves
		+ table[y].tob.item.moves
		+ table[z].tsb.item.moves
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_tst_count_q1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ ft_size_t_max(z, y)
		+ table[z].tst.item.moves
		+ table[y].tot.item.moves
		+ table[x].tot.item.moves
	);
}

size_t	ps_strategy_tst_count_q2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].bst.item.moves
		+ table[y].bot.item.moves
		+ table[x].tot.item.moves
	);
}
