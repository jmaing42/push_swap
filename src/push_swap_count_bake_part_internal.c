/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c_bake_part_internal.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:52:28 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/23 22:09:11 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_count.h"

#include <stdint.h>

#include "ft_size_t.h"

size_t	push_swap_c_bake_part_only_first_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ft_size_t_min(
			map[x].sort_and_move_collect_last.total_moves,
			map[x].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_min(
			map[y].sort_and_move_collect_last.total_moves,
			map[y].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_min(
			map[z].sort_only_collect_last.total_moves,
			map[z].sort_only_divide_first.total_moves
		)
		+ ft_size_t_max(y, z)
		+ x
		+ 2 * y
		+ z
	);
}

size_t	push_swap_c_bake_part_only_last_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x
		+ y
		+ 2 * z
		+ ft_size_t_min(
			map[x].sort_and_move_collect_last.total_moves,
			map[x].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_max(y, z)
		+ ft_size_t_min(
			map[y].sort_only_collect_last.total_moves,
			map[y].sort_only_divide_first.total_moves
		)
		+ ft_size_t_min(
			map[z].sort_and_move_collect_last.total_moves,
			map[z].sort_and_move_divide_first.total_moves
		)
	);
}

size_t	push_swap_c_bake_part_move_first_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ ft_size_t_min(
			map[x].sort_and_move_collect_last.total_moves,
			map[x].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_min(
			map[y].sort_only_collect_last.total_moves,
			map[y].sort_only_divide_first.total_moves
		)
		+ ft_size_t_max(y, z)
		+ ft_size_t_min(
			map[z].sort_only_collect_last.total_moves,
			map[z].sort_only_divide_first.total_moves
		)
		+ x
		+ 2 * y
		+ z
	);
}

size_t	push_swap_c_bake_part_move_last_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	return (
		+ x
		+ 2 * y
		+ z
		+ ft_size_t_min(
			map[x].sort_only_collect_last.total_moves,
			map[x].sort_only_divide_first.total_moves
		)
		+ ft_size_t_max(y, z)
		+ ft_size_t_min(
			map[y].sort_only_collect_last.total_moves,
			map[y].sort_only_divide_first.total_moves
		)
		+ ft_size_t_min(
			map[z].sort_and_move_collect_last.total_moves,
			map[z].sort_and_move_divide_first.total_moves
		)
	);
}
