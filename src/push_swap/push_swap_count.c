/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:11:42 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/20 20:35:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_count.h"

#include <stdint.h>

#include "ft_primitive_size_t.h"

t_push_swap_count_item	push_swap_count_solution(
	t_push_swap_count_part *map,
	size_t count
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
			now = push_swap_count_solution_internal(map, x, y, z);
			if (now < result.total_moves)
				result = (t_push_swap_count_item){now, x, y, z};
		}
	}
	return (result);
}

size_t	push_swap_count_solution_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ft_primitive_size_t_min(
			map[x].sort_and_move_merge.total_moves,
			map[x].sort_and_move_quick.total_moves
		)
		+ ft_primitive_size_t_min(
			map[y].sort_and_move_merge.total_moves,
			map[y].sort_and_move_quick.total_moves
		)
		+ ft_primitive_size_t_min(
			map[z].sort_only_merge.total_moves,
			map[z].sort_only_quick.total_moves
		)
		+ 2 * x
		+ y
		+ z
	);
}
