/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_bos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 19:47:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

size_t	ps_strategy_count_bos_m(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].bst.moves
		+ table[y].bos.moves
		+ table[z].bsb.moves
		+ x + y + 2 * z
	);
}

size_t	ps_strategy_count_bos_q1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + 3 * z
		+ table[z].bsb.moves
		+ table[y].tst.moves
		+ table[x].tot.moves
	);
}

size_t	ps_strategy_count_bos_q2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 3 * y + 2 * z
		+ table[z].tst.moves
		+ table[y].bst.moves
		+ table[x].tot.moves
	);
}

size_t	ps_strategy_count_bos_q3(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 3 * y + 2 * z
		+ table[z].tsb.moves
		+ table[y].tst.moves
		+ table[x].tot.moves
	);
}
