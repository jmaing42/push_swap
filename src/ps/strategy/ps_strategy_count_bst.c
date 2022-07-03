/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_bst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 19:59:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

#include "ft_size_t.h"

size_t	ps_strategy_count_bst_m1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].bst.moves
		+ table[y].bot.moves
		+ table[z].bot.moves
		+ ft_size_t_max(x, z)
		+ x + y + 2 * z
	);
}

size_t	ps_strategy_count_bst_m2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].bot.moves
		+ table[y].bob.moves
		+ table[z].bsb.moves
		+ 2 * x + y + z
	);
}

size_t	ps_strategy_count_bst_q(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ 3 * x + 2 * y + z
		+ table[z].tst.moves
		+ table[y].tot.moves
		+ table[x].bot.moves
	);
}
