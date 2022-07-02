/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_tstx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 00:01:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

size_t	ps_strategy_count_tstx_m(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].tsbx.moves
		+ table[y].tos.moves
		+ table[z].tot.moves
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_count_tstx_q(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x + 2 * y + z
		+ table[z].tot.moves
		+ table[y].sot.moves
		+ table[x].bstx.moves
	);
}
