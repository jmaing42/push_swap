/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tst_m1_count.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:42:58 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 09:29:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tst_merge_early_rotate.h"

#include <stddef.h>

#include "ft_size_t.h"

size_t	ps_strategy_tst_merge_early_rotate_count(
	const t_ps_strategy_count *table,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t	sort_x = table[x].tot.item.moves;
	const size_t	sort_y = table[y].tst.item.moves;
	const size_t	rotate = ft_size_t_max(y, x);
	const size_t	sort_z = table[z].tot.item.moves;
	const size_t	collect = 2 * x + y + z;

	return (sort_x + sort_y + rotate + sort_z + collect);
}
