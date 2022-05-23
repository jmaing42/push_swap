/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count_bake_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:52:28 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/23 22:40:28 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_count.h"

#include <stdint.h>

t_push_swap_count_part	push_swap_count_bake_part(
	t_push_swap_count_part *map,
	size_t count
)
{
	const t_push_swap_count_part	result = {
		push_swap_count_bake_part_only_first(map, count),
		push_swap_count_bake_part_only_last(map, count),
		push_swap_count_bake_part_move_first(map, count),
		push_swap_count_bake_part_move_last(map, count)
	};

	return (result);
}

t_push_swap_count_item	push_swap_count_bake_part_only_first(
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
			now = push_swap_count_bake_part_only_first_internal(map, x, y, z);
			if (now < result.total_moves)
				result = (t_push_swap_count_item){now, x, y, z};
		}
	}
	return (result);
}

t_push_swap_count_item	push_swap_count_bake_part_only_last(
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
			now = push_swap_count_bake_part_only_last_internal(map, x, y, z);
			if (now < result.total_moves)
				result = (t_push_swap_count_item){now, x, y, z};
		}
	}
	return (result);
}

t_push_swap_count_item	push_swap_count_bake_part_move_first(
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
			now = push_swap_count_bake_part_move_first_internal(map, x, y, z);
			if (now < result.total_moves)
				result = (t_push_swap_count_item){now, x, y, z};
		}
	}
	return (result);
}

t_push_swap_count_item	push_swap_count_bake_part_move_last(
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
			now = push_swap_count_bake_part_move_last_internal(map, x, y, z);
			if (now < result.total_moves)
				result = (t_push_swap_count_item){now, x, y, z};
		}
	}
	return (result);
}
