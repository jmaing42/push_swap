/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count_bake_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:52:28 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/25 16:15:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_count.h"

#include <stdint.h>

static t_push_swap_count_item	get_item_minimum(
	t_push_swap_count_part *map,
	size_t count,
	size_t (*calculate_with_exact_count)(
		const t_push_swap_count_part *map,
		size_t x,
		size_t y,
		size_t z
	)
)
{
	size_t					x;
	size_t					y;
	size_t					z;
	size_t					now;
	t_push_swap_count_item	result;

	result.total_moves = SIZE_MAX;
	x = -1;
	while (++x < count)
	{
		y = -1;
		while (x + ++y <= count)
		{
			z = count - (x + y);
			if (y == count || z == count)
				continue ;
			now = calculate_with_exact_count(map, x, y, z);
			if (now < result.total_moves)
				result = (t_push_swap_count_item){now, x, y, z};
		}
	}
	return (result);
}

t_push_swap_count_part	push_swap_count_bake_part(
	t_push_swap_count_part *map,
	size_t count
)
{
	const t_push_swap_count_part	result = {
		get_item_minimum(
			map,
			count,
			push_swap_count_bake_part_sort_only_divide_first),
		get_item_minimum(
			map,
			count,
			push_swap_count_bake_part_sort_only_collect_last),
		get_item_minimum(
			map,
			count,
			push_swap_count_bake_part_sort_and_move_divide_first),
		get_item_minimum(
			map,
			count,
			push_swap_count_bake_part_sort_and_move_collect_last),
	};

	return (result);
}
