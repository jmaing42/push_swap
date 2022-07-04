/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_sob.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/05 00:14:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

size_t	ps_strategy_count_sob_m1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tot.moves
		+ table[y].tst.moves
		+ table[z].bst.moves
		+ x + 3 * y + 2 * z
	);
}

size_t	ps_strategy_count_sob_m2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tot.moves
		+ table[y].tsb.moves
		+ table[z].tst.moves
		+ x + 3 * y + 2 * z
	);
}

size_t	ps_strategy_count_sob_m3(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tsb.moves
		+ table[y].tot.moves
		+ table[z].tst.moves
		+ 3 * x + y + 2 * z
	);
}

size_t	ps_strategy_count_sob_q(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ 2 * x + y + z
		+ table[x].bsb.moves
		+ table[y].sob.moves
		+ table[z].txb.moves
	);
}
