/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count_bake_part_internal.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:52:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/25 16:10:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_count.h"

#include <stdint.h>

#include "ft_size_t.h"

/**
 * @brief calculate maximum operation count to sort with method described below
 *
 * @param map array containing previous operation count   (bottom-up DP)
 * @param x count of small part
 * @param y count of middle part
 * @param z count of big part
 * @return size_t maximum operation count to sort given arguments
 *
 * ||                                                                         ||
 * ||    :                                                           X        ||
 * ||    : |           |           |         y |         Y |         Y |      ||
 * ||    : |           | z       Z |         Z | x       Z | x       Z |      ||
 * ||   -A-+-B- (1) -A-+-B- (2) -A-+-B- (3) -A-+-B- (4) -A-+-B- (5) -A-+-B-   ||
 * ||      |         y | x       y | x         |           |           |      ||
 * ||      |           |           |           |           |           |      ||
 * ||                                                                         ||
 * ||   (1) divide  (2) sort+move z  (3) rotate  (4) sort y  (5) sort+move x  ||
 *
 */
size_t	push_swap_count_bake_part_sort_only_divide_first(
	const t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t												divide
		= 2 * x + y + z;
	const size_t												sort_and_move_z
		= ft_size_t_min(
			map[z].sort_and_move_collect_last.total_moves,
			map[z].sort_and_move_divide_first.total_moves);
	const size_t												rotate
		= ft_size_t_max(y, x);
	const size_t												sort_only_y
		= ft_size_t_min(
			map[y].sort_only_collect_last.total_moves,
			map[y].sort_only_divide_first.total_moves);
	const size_t												sort_and_move_x
		= ft_size_t_min(
			+ map[x].sort_and_move_collect_last.total_moves,
			+ map[x].sort_and_move_divide_first.total_moves);

	return (
		+ divide
		+ sort_and_move_z
		+ rotate
		+ sort_only_y
		+ sort_and_move_x
	);
}

/**
 * @brief calculate maximum operation count to sort with method described below
 *
 * @param map array containing previous operation count   (bottom-up DP)
 * @param x count of top part
 * @param y count of middle part
 * @param z count of bottom part
 * @return size_t maximum operation count to sort given arguments
 *
 * ||                                                                         ||
 * ||    x                                                           :        ||
 * ||    y |         y |           | Y         | Y         |         : |      ||
 * ||    z |         z | X       z | X       Z | X         | X       : |      ||
 * ||   -A-+-B- (1) -A-+-B- (2) -A-+-B- (3) -A-+-B- (4) -A-+-B- (5) -A-+-B-   ||
 * ||      |           |           |           |         Z | Y         |      ||
 * ||      |           |           |           |           |           |      ||
 * ||                                                                         ||
 * ||  (1) sort+move x  (2) sort+move y  (3) sort z  (4) rotate  (5) collect  ||
 *
 */
size_t	push_swap_count_bake_part_sort_only_collect_last(
	const t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t												sort_and_move_x
		= ft_size_t_min(
			map[x].sort_and_move_collect_last.total_moves,
			map[x].sort_and_move_divide_first.total_moves);
	const size_t												sort_and_move_y
		= ft_size_t_min(
			map[y].sort_and_move_collect_last.total_moves,
			map[y].sort_and_move_divide_first.total_moves);
	const size_t												sort_only_z
		= ft_size_t_min(
			map[z].sort_only_collect_last.total_moves,
			map[z].sort_only_divide_first.total_moves);
	const size_t												rotate
		= ft_size_t_max(z, y);
	const size_t												collect
		= x + 2 * y + z;

	return (
		+ sort_and_move_x
		+ sort_and_move_y
		+ sort_only_z
		+ rotate
		+ collect
	);
}

/**
 * @brief calculate maximum operation count to sort with method described below
 *
 * @param map array containing previous operation count   (bottom-up DP)
 * @param x count of small part
 * @param y count of middle part
 * @param z count of big part
 * @return size_t maximum operation count to sort given arguments
 *
 * ||                                                                         ||
 * ||    :                                                               X    ||
 * ||    : |           |           |           | y         | Y         | Y    ||
 * ||    : |           | x         | X       z | X       z | X         | Z    ||
 * ||   -A-+-B- (1) -A-+-B- (2) -A-+-B- (3) -A-+-B- (4) -A-+-B- (5) -A-+-B-   ||
 * ||      |         z | y       z | y         |           |           |      ||
 * ||      |           |           |           |           |           |      ||
 * ||                                                                         ||
 * ||   (1) divide   (2) sort x   (3) rotate   (4) sort y   (5) sort+move x   ||
 *
 */
size_t	push_swap_count_bake_part_sort_and_move_divide_first(
	const t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t												divide
		= x + 2 * y + z;
	const size_t												sort_only_x
		= ft_size_t_min(
			map[x].sort_only_collect_last.total_moves,
			map[x].sort_only_divide_first.total_moves);
	const size_t												rotate
		= ft_size_t_max(x, y);
	const size_t												sort_and_move_y
		= ft_size_t_min(
			map[y].sort_and_move_collect_last.total_moves,
			map[y].sort_and_move_divide_first.total_moves);
	const size_t												sort_and_move_z
		= ft_size_t_min(
			map[z].sort_and_move_collect_last.total_moves,
			map[z].sort_and_move_divide_first.total_moves);

	return (
		+ divide
		+ sort_only_x
		+ rotate
		+ sort_and_move_y
		+ sort_and_move_z
	);
}

/**
 * @brief calculate maximum operation count to sort with method described below
 *
 * @param map array containing previous operation count   (bottom-up DP)
 * @param x count of top part
 * @param y count of middle part
 * @param z count of bottom part
 * @return size_t maximum operation count to sort given arguments
 *
 * ||                                                                         ||
 * ||    x                                                               :    ||
 * ||    y |         y |         Y |           |           |           | :    ||
 * ||    z |         z | X       z | X       z |         Z |           | :    ||
 * ||   -A-+-B- (1) -A-+-B- (2) -A-+-B- (3) -A-+-B- (4) -A-+-B- (5) -A-+-B-   ||
 * ||      |           |           |         Y | X       Y | X         |      ||
 * ||      |           |           |           |           |           |      ||
 * ||                                                                         ||
 * ||  (1) sort+move x  (2) sort+move y  (3) sort z  (4) rotate  (5) collect  ||
 *
 */
size_t	push_swap_count_bake_part_sort_and_move_collect_last(
	const t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	const size_t												sort_and_move_x
		= ft_size_t_min(
			map[x].sort_and_move_collect_last.total_moves,
			map[x].sort_and_move_divide_first.total_moves);
	const size_t												sort_only_y
		= ft_size_t_min(
			map[y].sort_only_collect_last.total_moves,
			map[y].sort_only_divide_first.total_moves);
	const size_t												rotate
		= ft_size_t_max(y, x);
	const size_t												sort_only_z
		= ft_size_t_min(
			map[z].sort_only_collect_last.total_moves,
			map[z].sort_only_divide_first.total_moves);
	const size_t												collect
		= x + 2 * y + z;

	return (
		+ sort_and_move_x
		+ sort_only_y
		+ rotate
		+ sort_only_z
		+ collect
	);
}
