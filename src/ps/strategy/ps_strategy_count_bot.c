/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_count_bot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 19:44:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include <stddef.h>

#include "ft_size_t.h"

size_t	ps_strategy_count_bot_m1(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].bst.moves
		+ table[y].bst.moves
		+ table[z].bot.moves
		+ ft_size_t_max(y, z)
		+ x + 2 * y + z
	);
}

size_t	ps_strategy_count_bot_m2(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ table[x].bst.moves
		+ table[y].bob.moves
		+ table[z].bsb.moves
		+ x + y + 2 * z
	);
}

size_t	ps_strategy_count_bot_q(
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
