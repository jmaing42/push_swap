/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_tos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 00:12:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

size_t	ps_strategy_count_tos_m(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tsbx.moves
		+ table[y].tos.moves
		+ table[z].tst.moves
		+ 2 * x + y + z
	);
}

size_t	ps_strategy_count_tos_q1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].tst.moves
		+ table[y].bot.moves
		+ table[x].bot.moves
	);
}

size_t	ps_strategy_count_tos_q2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + y + 2 * z
		+ table[z].bsb.moves
		+ table[y].tst.moves
		+ table[x].bot.moves
	);
}
