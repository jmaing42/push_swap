/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_tsbx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 00:15:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

size_t	ps_strategy_count_tsbx_m(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tos.moves
		+ table[y].tot.moves
		+ table[z].tst.moves
		+ 3 * x + 2 * y + z
	);
}

size_t	ps_strategy_count_tsbx_q(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + y + 2 * z
		+ table[x].bsb.moves
		+ table[y].tob.moves
		+ table[z].sob.moves
	);
}
