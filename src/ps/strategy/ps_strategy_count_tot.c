/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_tot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 00:09:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

#include "ft_size_t.h"

size_t	ps_strategy_count_tot_m1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tot.moves
		+ table[y].tst.moves
		+ ft_size_t_max(y, x)
		+ table[z].tst.moves
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_count_tot_m2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tob.moves
		+ table[y].tsb.moves
		+ table[z].tst.moves
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_count_tot_q1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].tst.moves
		+ ft_size_t_max(y, x)
		+ table[y].tst.moves
		+ table[x].tot.moves
	);
}

size_t	ps_strategy_count_tot_q2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].tst.moves
		+ table[y].bst.moves
		+ table[x].bot.moves
	);
}
