/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_tob.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 00:15:18 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

size_t	ps_strategy_count_tob_m(
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

size_t	ps_strategy_count_tob_q(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ 2 * x + y + z
		+ table[x].bsb.moves
		+ table[y].tsb.moves
		+ table[z].bob.moves
	);
}
