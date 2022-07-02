/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_tst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/02 16:14:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

#include "ft_size_t.h"

size_t	ps_strategy_count_tst_m1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tot.moves
		+ table[y].tot.moves
		+ table[z].tst.moves
		+ ft_size_t_max(z, y)
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_count_tst_m2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tot.moves
		+ table[y].tob.moves
		+ table[z].tsb.moves
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_count_tst_q1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ ft_size_t_max(z, y)
		+ table[z].tst.moves
		+ table[y].tot.moves
		+ table[x].tot.moves
	);
}

size_t	ps_strategy_count_tst_q2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].bst.moves
		+ table[y].bot.moves
		+ table[x].tot.moves
	);
}
