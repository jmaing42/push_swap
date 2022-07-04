/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_sos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/05 00:15:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

size_t	ps_strategy_count_sos_m1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].txb.moves
		+ table[y].tot.moves
		+ table[z].tst.moves
		+ 2 * x + y + z
	);
}

size_t	ps_strategy_count_sos_m2(
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
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_count_sos_q1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].tsb.moves
		+ table[y].tst.moves
		+ table[x].sot.moves
	);
}

size_t	ps_strategy_count_sos_q2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].tot.moves
		+ table[y].bxt.moves
		+ table[x].bxt.moves
	);
}
